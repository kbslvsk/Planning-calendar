/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 02/05/2022
*/

#include "CMonthlyView.h"
#include <set>

CView &CMonthlyView::Configure(const CInterface &interface)
{
    wantedMonth = months.at(CInterface::toLower( interface.promptString( PROMPT_MONTH_NAME, [&]( const string & validMonth ){
        return ( months.find(CInterface::toLower( validMonth )) != months.end());
    } )));

    wantedYear = interface.promptNumber( PROMPT_YEAR, []( int year ){
        return true;
    }, INVALID_VALUE );

    return *this;
}

string CMonthlyView::Print( const map<CDate, vector<CEvent>> &Events ) const
{
    vector<const CEvent *> eventsInMonth;
    set<size_t> idCheck;
    ostringstream oss;
    oss << DASHES << endl;

    CDate start( 1, wantedMonth, wantedYear );

    time_t t = time( nullptr );
    tm timeStruct = *localtime( &t );
    start.makeTimeStruct( &timeStruct );
    mktime( &timeStruct );

    while ( timeStruct.tm_mon == wantedMonth - 1 )
    {
        CDate tmp ( timeStruct.tm_mday, timeStruct.tm_mon + 1, timeStruct.tm_year + 1900 );
        const auto & daysIterator = Events.find( tmp );

        if ( daysIterator != Events.end() )
        {
            for ( const auto &eventsIterator : daysIterator->second )
            {
                if ( idCheck.insert( eventsIterator.getID()).second )
                {
                    eventsInMonth.push_back(&eventsIterator);
                }
            }
        }
        timeStruct.tm_mday += 1;
        mktime( &timeStruct );
    }

    if ( eventsInMonth.size() < 10 )
    {
        for ( const auto & eventsIterator2 : eventsInMonth )
        {
            oss << *eventsIterator2 << endl;
            oss << DASHES << endl;
        }
    }

    else
    {
        oss << "In " << wantedMonth << "/" << wantedYear << " you have " << eventsInMonth.size()
            << " events with following ID's planned: " << endl;

        for ( const auto & eventsIterator2 : eventsInMonth )
        {
            oss << eventsIterator2->getID() << endl;
        }

        oss << "For more details, you can search each event by its ID individually" << endl;
    }

    return oss.str();

}
