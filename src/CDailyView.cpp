/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 26/02/2022
*/


#include "CDailyView.h"


CView &CDailyView::Configure(const CInterface &interface) {
    date = interface.promptDate( PROMPT_DATE );
    return *this;
}

string CDailyView::Print( const map< CDate, vector<CEvent> > & Events ) const
{
    ostringstream buffer;
    buffer << DASHES << endl;
    buffer << date << endl;
    buffer << DASHES << endl;
    auto it = Events.find( date );

    if ( it == Events.end() )
    {
        buffer << "NO EVENTS";
        return buffer.str();
    }

    for ( const auto & eventIterator : it->second )
    {
        buffer << eventIterator << endl;
        buffer << DASHES << endl;
    }

    return buffer.str();

}


