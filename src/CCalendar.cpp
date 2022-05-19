/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 23/02/2022
*/

#include "CCalendar.h"

CCalendar & CCalendar::insert( CEvent & event )
{
    if ( event.getID() == 0 ) { event.setID(idCount++); }

    EventsById.emplace( event.getID(), event );
    Events[event.getFrom()].push_back(event);

    if ( CDate ( event.getFrom() ) <  CDate ( event.getTo() ))
    {
        time_t t = time(nullptr);
        tm startTimeStruct = *localtime(&t);
        tm endTimeStruct = *localtime(&t);
        event.getFrom().makeTimeStruct( &startTimeStruct );
        event.getTo().makeTimeStruct( &endTimeStruct );

        do
        {
            startTimeStruct.tm_mday += 1;
            mktime( &startTimeStruct );
            CDate tmpDate ( startTimeStruct.tm_mday, startTimeStruct.tm_mon + 1, startTimeStruct.tm_year + 1900 );
            Events[tmpDate].push_back( event );
        }

        while ( ! ( startTimeStruct.tm_mday == endTimeStruct.tm_mday &&
                    startTimeStruct.tm_mon  == endTimeStruct.tm_mon  &&
                    startTimeStruct.tm_year == endTimeStruct.tm_year ));

    }

    return *this;
}

bool CCalendar::deleteEvent( size_t id )
{
    if ( EventsById.find(id) == EventsById.end())
    {
        return false;
    }

    const auto & itEvent = EventsById.find(id);
    CEvent tmp ( itEvent->second );
    int index;

    EventsById.erase(itEvent);

    for ( auto & daysIterator : Events )
    {
        if ( daysIterator.first >= tmp.getFrom() && daysIterator.first <= tmp.getTo())
        {
            index = 0;

            for ( const auto & eventsIterator : daysIterator.second )
            {
                if ( eventsIterator.getID() == id )
                {
                    break;
                }

                ++index;

            }

            daysIterator.second.erase(daysIterator.second.begin() + index );
        }
    }

    return true;
}

bool CCalendar::isIncluded( size_t id ) const
{
    return ( EventsById.find(id) != EventsById.end() );
}

CEvent &CCalendar::operator[](size_t idx)
{
    if ( EventsById.find( idx ) == EventsById.end())
    {
        throw out_of_range("Unknown Event ID!");
    }

    return EventsById.at(idx);
}

const CEvent &CCalendar::operator[](size_t idx) const
{
    if ( EventsById.find( idx ) == EventsById.end())
    {
        throw out_of_range("Unknown Event ID!");
    }

    return EventsById.at(idx);
}


ostream & operator << (ostream & os, const CCalendar & self )
{
    for ( const auto & calIterator : self.EventsById )
    {
        os << "EVENT" << endl;
        os << calIterator.second << endl;
    }

    return os;

}

istream &operator >> ( istream &iss, CCalendar &self )
{
    string endCheck;
    while ( true )
    {
        if ( ! getline ( iss, endCheck ) )
        {
            if ( iss.eof() )
            {
                iss.clear();
            }

            break;
        }

        if ( endCheck != "EVENT" )
        {
            iss.setstate( ios::failbit );
            break;
        }

        CEvent tmp;

        if ( ! ( iss >> tmp ) )
        {
            return iss;
        }

        tmp.setID( 0 );
        self.insert( tmp );
    }

    return iss;

}

vector<pair<CTime, CTime>> CCalendar::findFreeTime( CDate date ) const
{
    vector<pair<CTime, CTime>> freeTimes;
    freeTimes.emplace_back( CTime ( 0, 0 ), CTime ( 23, 59 ) );

    auto pos = Events.find( date );

    if ( pos != Events.end() )
    {
       for ( const auto & eventsIterator : pos->second )
       {
           CTime startTime, endTime;
           startTime = ( CDate ) eventsIterator.getFrom() < date ? CTime( 0, 0 ) : eventsIterator.getFrom().getTime();
           endTime   = ( CDate ) eventsIterator.getTo() > date ? CTime( 23, 59 ) : eventsIterator.getTo().getTime();

            vector<pair<CTime, CTime>>  newFreeTimes;
            bool madeChanges = false;

            for ( const auto & timesIterator : freeTimes )
            {
                if ( startTime < timesIterator.second && endTime > timesIterator.first )
                {
                    madeChanges = true;

                    if ( startTime <= timesIterator.first )
                    {
                        if ( endTime >= timesIterator.second )
                        {
                            continue;
                        }

                        else
                        {
                            newFreeTimes.emplace_back( endTime, timesIterator.second );
                            continue;
                        }
                    }

                    else if ( endTime >= timesIterator.second )
                    {
                        newFreeTimes.emplace_back( timesIterator.first, startTime );
                        continue;
                    }

                    else
                    {
                        newFreeTimes.emplace_back( timesIterator.first, startTime );
                        newFreeTimes.emplace_back( endTime, timesIterator.second );
                    }
                }

                else
                {
                    newFreeTimes.push_back( timesIterator );
                }

            }

            if ( madeChanges ) { freeTimes = newFreeTimes ;}
       }
    }

    return freeTimes;
}

bool CCalendar::isEmpty() const
{
    return EventsById.empty();
}



