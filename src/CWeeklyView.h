/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 02/05/2022
*/

#pragma once
#include "CView.h"

/**
 * @brief Weekly view
 *
 * Displays events from chosen calendar week
 */

class CWeeklyView : public CView {

    /**
     * Vector of days in chosen week
     */
    vector<CDate> days;



public:

    /**
     *
     * @return unique_ptr to CWeeklyView object
     */
    unique_ptr<CView> Clone () const override { return make_unique<CWeeklyView>( *this ); }

    /**
     *
     * @param interface User interface
     * @return Reference to configured CView object
     */
    CView & Configure ( const CInterface & interface ) override;


    /**
     *
     * @param Events map with Events in calendar
     * @return Printed events from chosen week
     */
    string Print ( const map< CDate, vector<CEvent> > & Events ) const override;


};



