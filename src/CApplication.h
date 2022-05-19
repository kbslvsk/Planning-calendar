/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 11/02/2022
*/

#pragma once

#include "CCommand.h"

/**
 * @brief Application
 */

class CApplication {

private:

    /**
     * @brief User interface
     */
    CInterface interface;

    /**
     * @brief Calendar to be used
     */
    CCalendar calendar;

    /**
     * @brief Usable commands
     */
    map<size_t, CCommand> commands;

public:

    /**
     * @brief Constructs an Application instance
     * @param interface Interface that communicates with user
     */

    explicit CApplication ( CInterface interface );

    CApplication ( const CApplication & ) = delete;

    CApplication & operator = ( const CApplication & ) = delete;

    /**
     * @brief Destructor
     */
    ~CApplication() = default;

    /**
     * @brief Function that controls the run of application
     * @return 0 if properly ended, 1 if there was some problem
     */

    int run ();


};



