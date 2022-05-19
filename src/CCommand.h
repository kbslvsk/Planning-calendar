/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 27/02/2022
*/

#pragma once
#include <string>
#include "CEventEditor.h"
#include "CViewManager.h"
#include <fstream>

/**
 * @brief Class with possible commands
 */
class CCommand {

    /**
     * @brief Info about what does the command do
     */
    std::string info;

    /**
     * @brief execute function of command
     */
    std::function<bool(const CInterface & , CCalendar & )> m_execute;


public:

    /**
     * @brief Constructor
     * @param c_info info about command
     * @param c_execute execute function of command
     */

    CCommand( string c_info, function<bool(const CInterface &, CCalendar & )> c_execute ):info(move(c_info)), m_execute(move(c_execute)){};

    /**
     * @brief Executes the command
     * @return True if the app should continue, False if it should end
     */
    bool execute ( const CInterface &, CCalendar & ) const ;

    /**
     * @brief Provides info about command
     * @return information about command
     */

    const string & getInfo() const;

    /**
     *
     * @return Command that adds Event to calendar
     */
    static CCommand addEvent ();

    /**
     *
     * @return Command that edits Events in calendar
     */
    static CCommand editEvent ();

    /**
     *
     * @return Command that displays calendar in different modes
     */
    static CCommand viewEvents ();

    /**
     *
     * @return Command that sets repetitions to events in calendar
     */
    static CCommand setRepetition();

    /**
     *
     * @param searchOptions Options, how to search events
     * @return Command that searches events in Calendar
     */
    static CCommand searchForEvents ();

    /**
     *
     * @return Command that exports events from calendar to file
     */
    static CCommand exportCommand();

    /**
     *
     * @return Command that imports events from file to calendar
     */
    static CCommand importCommand();

    /**
     *
     * @return Command that searches for a free time in a day
     */
    static CCommand freeTimeFinder();

    /**
     *
     * @return  Command that ends the app
     */
    static CCommand endApp ();

};



