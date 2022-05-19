/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 01/05/2022
*/

#include "CEventEditor.h"

void CEventEditor::changeName(const CInterface &interface)
{
    string newName = interface.promptString(PROMPT_NEW_NAME, []( const string & name ) { return true; });
    event.setName( newName );
}

void CEventEditor::changePlace(const CInterface &interface)
{
    string newPlace = interface.promptString(PROMPT_NEW_PLACE, []( const string & place ) { return true; });
    event.setPlace( newPlace );
}

void CEventEditor::changeTime( const CInterface &interface, CCalendar & calendar )
{
    calendar.deleteEvent( event.getID() );
    while ( true )
    {
        try
        {
            CDateTime newFrom = interface.promptDateTime( EVENT_START );
            CDateTime newTo = interface.promptDateTime( EVENT_END );
            event.setTime( newFrom, newTo );
            calendar.insert( event );
            break;
        }
        catch ( const logic_error & error )
        {
            interface.printMessage( error.what());
            continue;
        }
    }
}
