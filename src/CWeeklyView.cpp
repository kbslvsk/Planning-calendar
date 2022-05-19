/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 02/05/2022
*/

#include "CWeeklyView.h"

CView &CWeeklyView::Configure(const CInterface &interface)
{
    CDate date = interface.promptDate( PROMPT_DATE );
    days = date.getWeekFromDate();
    return *this;
}

string CWeeklyView::Print( const map<CDate, vector<CEvent>> &Events ) const
{
    size_t doneCounter = 0;
    size_t eventCounter = 0;
    vector<int> daysDone (7 );

    ostringstream oss;
    oss << days.front() << " - " << days.back() << endl;

    for ( size_t i = 0; i < 7 ; ++i )
    {
        oss << " " << setw(CEvent::maxNameWidth - 1 ) << setfill('-') << "" ;
    }

    oss << setfill(' ') << endl;
    oss << WEEK_DAYS << endl;

    for ( size_t i = 0; i < 7 ; ++i )
    {
        if ( Events.find( days[i] ) == Events.end() )
        {
            daysDone[i] = 1;
            ++ doneCounter;
        }
    }


    while ( doneCounter < 7 )
    {
        oss << "|" ;

        for ( size_t i = 0 ; i < 7 ; ++i )
        {

            if ( ! daysDone[i] )
            {

                try
                {
                    CEvent toPrint = Events.find( days[i] )->second.at( eventCounter );
                    oss << " " << setw( CEvent::maxNameWidth - 2 ) << left << toPrint.getName() << "|" << right;
                }

                catch ( const out_of_range & invalidIndex )
                {
                    daysDone[i] = 1;
                    ++ doneCounter;
                    oss << setw( CEvent::maxNameWidth ) << "|";
                }

                continue;
            }


            oss << setw( CEvent::maxNameWidth ) << "|";
        }

        oss << endl;
        ++ eventCounter;
    }

    for ( size_t i = 0; i < 7 ; ++i )
    {
        oss << " " << setw(CEvent::maxNameWidth - 1 ) << setfill('-' ) << "" ;

    }

    oss << endl;

    return oss.str();

}
