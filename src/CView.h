/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 23/02/2022
*/

#pragma once
#include "CCalendar.h"
#include <sstream>
#include <iomanip>

/**
 * @brief Abstract base class for different Calendar views
 */

class CView {

public:

    /**
     * @brief Default constructor
     */
    CView () = default;

    /**
     * @brief Default copy constructor
     */
    CView ( const CView & ) = default;
    CView & operator = ( const CView & ) = delete;

    /**
     * @brief Virtual destructor
     */
    virtual ~CView () = default;

    /**
     * @brief Makes a unique_ptr clone of self
     * @return unique_ptr clone of self
     */
    virtual unique_ptr<CView> Clone ( ) const = 0;

    /**
     *
     * @param interface User interface
     * @return Reference to configured CView object
     */
    virtual CView & Configure ( const CInterface & interface ) = 0;

    /**
     *
     * @param Events Map with events from calendar
     * @return printed Events
     */

    virtual string Print ( const map< CDate, vector<CEvent> > & Events ) const = 0;
};



