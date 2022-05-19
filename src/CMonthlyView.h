/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 02/05/2022
*/

#pragma once
#include "CView.h"


class CMonthlyView : public CView {
    /**
     * @brief Map of month names and their numbers
     */

    const map<string, int> months = { { "january", 1  }, { "february", 2  }, { "march",     3 },
                                    { "april",   4  }, { "may",      5  }, { "june",      6 },
                                    { "july",    7  }, { "august",   8  }, { "september", 9 },
                                    { "october", 10 }, { "november", 11 }, { "december", 12 } };


    /**
     * @brief Month to be displayed
     */
    int wantedMonth;

    /**
     * @brief Year to be displayed
     */
    int wantedYear;





public:

    /**
     *
     * @return unique_ptr to CMonthlyView object
     */
    unique_ptr<CView> Clone () const override { return make_unique<CMonthlyView>(*this); }

    /**
     *
     * @param interface User interface
     * @return Reference to configured CView object
     */
    CView & Configure ( const CInterface & interface ) override;

    /**
     *
     * @param Events map with Events in calendar
     * @return Printed events from chosen month
     */
    string Print ( const map< CDate, vector<CEvent> > & Events ) const override;


};



