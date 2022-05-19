/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 26/02/2022
*/

#pragma once

#include "CView.h"

/**
 * @brief View of chosen day in Calendar
 */

class CDailyView : public CView {

    /**
     * @brief Date to be printed
     */
    CDate date;

public:

    /**
     *
     * @return unique pointer to CDailyView
     */

    unique_ptr<CView> Clone () const override { return make_unique<CDailyView>(*this); }

    /**
     * @brief Configures the view properties
     * @param interface User interface
     * @return CView reference
     */

    CView & Configure ( const CInterface & interface ) override;

    /**
     * @brief Prints the events
     * @param Events map of Events in calendar
     * @return printed Events
     */

    string Print ( const map< CDate, vector<CEvent> > & Events ) const override;

};



