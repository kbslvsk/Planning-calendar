/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 01/05/2022
*/

#pragma once

#include "CCalendar.h"

/**
 * @brief Handles the editting of event
 */
class CEventEditor {

private:

    /**
     * @brief Event to be editted
     */
    CEvent & event;

public:

    CEventEditor() = delete;

    /**
     * @brief Constructor
     * @param event Event to be editted
     */
    explicit CEventEditor( CEvent & event ): event(event){}

    /**
     * @brief Changes the name of the event
     * @param interface User interface
     */
    void changeName ( const CInterface & interface );

    /**
     * @brief Changes the place of the events
     * @param interface User interface
     */
    void changePlace ( const CInterface & interface );

    /**
     * @brief Changes the time of the event
     * @param interface User interface
     * @param calendar Calendar, where the event is included
     */
    void changeTime ( const CInterface & interface, CCalendar & calendar );


};



