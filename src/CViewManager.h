/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 23/02/2022
*/

#pragma once
#include <string>
#include "CDailyView.h"
#include "CWeeklyView.h"
#include "CMonthlyView.h"

/**
 * Class that holds possible view options
 */

class CViewManager {

    /**
     * @brief Map with unique pointers to possible views
     */
    map<string, unique_ptr<CView>> views;

public:

    /**
     * @brief Constructor
     */
    CViewManager();

    /**
     *
     * @param wantedView View that should be found
     * @return Unique pointer to wanted view. nullptr if not found
     */
    unique_ptr<CView> findView ( string wantedView ) const;

};



