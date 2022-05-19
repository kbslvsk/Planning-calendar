/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 14/05/2022
*/

#include "CFindID.h"

CFind &CFindID::configure(const CInterface &interface)
{
    ID = interface.promptNumber( PROMPT_ID, []( size_t id ){
        return true;
    }, UNKNOWN_EVENT );

    return *this;
}

vector<CEvent> CFindID::find( const map<size_t, CEvent> &events ) const
{
    vector<CEvent> foundEvents;

    if ( events.find( ID ) != events.end() )
    {
        foundEvents.push_back( events.find( ID )->second );
    }

    return foundEvents;
}
