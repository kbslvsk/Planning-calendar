/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 27/02/2022
*/

#include "CCommand.h"
#include "CFindManager.h"

bool CCommand::execute ( const CInterface & interface , CCalendar & calendar ) const
{
    return m_execute ( interface, calendar );
}


const string &CCommand::getInfo() const { return info; }

CCommand CCommand::addEvent()
{
    return CCommand( INFO_ADD , [] ( const CInterface & interface , CCalendar & calendar )
                     {
                         CEvent event;
                         while ( true )
                         {
                             try
                             {
                                 event = interface.promptEvent();
                             }

                             catch ( logic_error & ex )
                             {
                                 interface.printMessage(DASHES);
                                 interface.printMessage(ex.what());
                                 interface.printMessage(DASHES);
                                 continue;
                             }

                             break;
                         }

                         calendar.insert ( event );

                         interface.printMessage( DASHES );
                         interface.printMessage("Event added!");
                         interface.printMessage( DASHES );
                         return true;
                     }
    );
}

CCommand CCommand::editEvent()
{
    return CCommand ( INFO_EDIT, [] ( const CInterface & interface, CCalendar & calendar ) {

        if ( calendar.isEmpty() )
        {
            interface.printMessage( DASHES );
            interface.printMessage(EMPTY);
            interface.printMessage( DASHES );
            return true;
        }

        size_t id = interface.promptNumber(PROMPT_ID, [&calendar](size_t wantedId) {
            return calendar.isIncluded(wantedId);
        }, UNKNOWN_EVENT );


        CEvent &toEdit = calendar[id];
        CEventEditor editor(toEdit);

        while (true)
        {
            string edit = interface.promptString( TO_EDIT, []( const string & toEdit ) {
                return ( CInterface::toLower( toEdit ) == "name"  ||
                         CInterface::toLower( toEdit ) == "place" ||
                         CInterface::toLower( toEdit ) == "time"  ||
                         CInterface::toLower( toEdit ) == "back");
            });

            if      ( CInterface::toLower( edit ) == "name" )       { editor.changeName( interface ); continue; }
            else if ( CInterface::toLower( edit ) == "place" )      { editor.changePlace( interface ); continue; }
            else if ( CInterface::toLower( edit ) == "time" )       { editor.changeTime( interface, calendar ); continue; }
            else { return true; }
        }
    });
}

CCommand CCommand::viewEvents()
{
    return CCommand(INFO_VIEW, [] ( const CInterface & interface , const CCalendar & calendar )
    {
        CViewManager viewManager;
        string wantedView = CInterface::toLower( interface.promptString( TO_PRINT, [ &viewManager ]( const string & mode ) {
            return ( viewManager.findView ( mode ) != nullptr );
        }));

        unique_ptr<CView> view = viewManager.findView(wantedView);
        view->Configure( interface );
        interface.printMessage( view->Print( calendar.provideEvents()));
        return true;

    } );
}

CCommand CCommand::setRepetition()
{
    return CCommand( INFO_REP, [] ( const CInterface & interface, CCalendar & calendar ) {

        if ( calendar.isEmpty() )
        {
            interface.printMessage( DASHES );
            interface.printMessage(EMPTY);
            interface.printMessage( DASHES );
            return true;
        }

        size_t id = interface.promptNumber( PROMPT_ID, [&calendar](size_t wantedId) {
            return calendar.isIncluded(wantedId);
        }, UNKNOWN_EVENT );


        size_t period = interface.promptNumber( PROMPT_PERIOD, []( size_t period ){ return ( period > 0 && period <= 48 ); }, INVALID_VALUE );
        CDate repetitionEnd = interface.promptDate( PROMPT_REPETITION_END );

        CEvent tmp ( calendar[id] );
        tmp.setID(0);
        CTime startTime = tmp.getFrom().getTime();
        CTime endTime   = tmp.getTo().getTime();

        time_t t = time(nullptr);
        tm timeStruct = *localtime(&t);
        tmp.getFrom().makeTimeStruct( &timeStruct );
        timeStruct.tm_mday += ( period * 7 );
        mktime( &timeStruct );

        tm timeStructEnd = *localtime(&t);
        tmp.getTo().makeTimeStruct( &timeStructEnd );
        timeStructEnd.tm_mday += ( period * 7 );
        mktime( &timeStructEnd );

        while ( CDate( timeStruct.tm_mday, timeStruct.tm_mon + 1, timeStruct.tm_year + 1900 ) < repetitionEnd )
        {
            tmp.setTime( CDateTime( startTime.getHour(), startTime.getMin(), timeStruct.tm_mday, timeStruct.tm_mon + 1, timeStruct.tm_year + 1900 ),
                         CDateTime( endTime.getHour(), endTime.getMin(), timeStructEnd.tm_mday, timeStructEnd.tm_mon + 1, timeStructEnd.tm_year + 1900 ));
            calendar.insert( tmp );
            tmp.setID(0);
            timeStruct.tm_mday += ( period * 7 );
            timeStructEnd.tm_mday += ( period * 7 );
            mktime( & timeStruct );
            mktime( & timeStructEnd );
        }

        return true;
    });

}

CCommand CCommand::searchForEvents()
{
    return ( CCommand ( EVENT_SEARCH, []( const CInterface & interface, const CCalendar & calendar ) {

        if ( calendar.isEmpty() )
        {
            interface.printMessage( DASHES );
            interface.printMessage(EMPTY);
            interface.printMessage( DASHES );
            return true;
        }

        CFindManager findManager;
        string option = CInterface::toLower( interface.promptString( PROMPT_OPTION, [&]( const string & option ){
            return ( findManager.getOption( CInterface::toLower( option )) != nullptr );
        }));

        vector<CEvent> foundEvents = findManager.getOption( option )->configure( interface ).find( calendar.provideEventsById() );

        if ( foundEvents.empty() )
        {
            interface.printMessage(DASHES);
            interface.printMessage(NO_EVENTS);
            interface.printMessage(DASHES);
        }

        else
        {
            interface.printMessage( to_string( foundEvents.size()) + " event/s with entered parameters found. ");
            interface.printMessage(DASHES);

            for ( const auto & eventsIterator : foundEvents )
            {
                ostringstream oss;
                oss << eventsIterator << endl;
                interface.printMessage( oss.str() );
            }

            interface.printMessage( DASHES );
        }
        return true;
    }));
}

CCommand CCommand::exportCommand()
{
    return CCommand( INFO_EXPORT, []( const CInterface & interface, const CCalendar & calendar )
    {
        string filePath = interface.promptString( PROMPT_PATH, []( const string & filePath ) {
            return ofstream(filePath).is_open();
        } );

        ofstream outFile ( filePath );

        if ( ! ( outFile << calendar ))
        {
            interface.printMessage("ERROR");
        }

        else
        {
            interface.printMessage("EVENTS EXPORTED");
        }

        outFile.close();

        return true;
    });
}

CCommand CCommand::importCommand()
{
    return CCommand( INFO_IMPORT, []( const CInterface & interface, CCalendar & calendar )
    {
        string filePath = interface.promptString( PROMPT_PATH, []( const string & filePath ) {
            return ifstream( filePath ).is_open();
        } );

        ifstream inFile ( filePath );

        CCalendar tmp;

        if ( ! ( inFile >> tmp ))
        {
            interface.printMessage("Import failed!");
            inFile.close();
            return true;
        }

        inFile.close();

        interface.printMessage("Events imported successfuly!");
        calendar = tmp;
        return true;
    });
}

CCommand CCommand::freeTimeFinder()
{
    return CCommand ( INFO_FINDER, []( const CInterface & interface, const CCalendar & calendar ) {
        CDate wantedDate = interface.promptDate( PROMPT_DATE );
        vector<pair<CTime, CTime>> freeTimes = calendar.findFreeTime( wantedDate );

        if ( freeTimes.empty() )
        {
            interface.printMessage(DASHES);
            interface.printMessage("Unfortunately, there is no free time in a chosen day. Try another day.");
            interface.printMessage(DASHES);
        }

        else
        {
            interface.printMessage("Here are is your free time in the day of your choice :-)");
            for ( const auto & it : freeTimes)
            {
                interface.printTimeFrame( it.first, it.second );
            }

            interface.printMessage( DASHES );
        }
        return true;

    });

}

CCommand CCommand::endApp() {
    return CCommand ( INFO_END, [] ( const CInterface & interface, const CCalendar & calendar ) {
        return false;
    });
}

