/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 14/05/2022
*/

#include "CFindName.h"

CFind &CFindName::configure(const CInterface &interface)
{
    name = interface.promptString( PROMPT_NAME, []( const string & name ){
        return true;
    });

    return *this;
}

vector<CEvent> CFindName::find( const map<size_t, CEvent> &events) const
{
    vector<CEvent> foundEvents;

    for ( const auto & eventsIterator : events )
    {
        if ( CInterface::toLower( eventsIterator.second.getName() ).find( CInterface::toLower( name ) ) != string::npos )
        {
            foundEvents.push_back( eventsIterator.second );
        }
    }
    return foundEvents;
}
