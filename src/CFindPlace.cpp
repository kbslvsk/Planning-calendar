/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 14/05/2022
*/

#include "CFindPlace.h"

CFind &CFindPlace::configure(const CInterface &interface)
{
    place = interface.promptString( PROMPT_PLACE, []( const string & place ){
        return true;
    });

    return *this;
}

vector<CEvent> CFindPlace::find(const map<size_t, CEvent> &events) const
{
    vector<CEvent> foundEvents;

    for ( const auto & eventsIterator : events )
    {
        if ( CInterface::toLower( eventsIterator.second.getPlace() ).find( CInterface::toLower( place ) ) != string::npos )
        {
            foundEvents.push_back( eventsIterator.second );
        }
    }

    return foundEvents;
}
