/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 23/02/2022
*/

#pragma once

#include "CFindID.h"
#include "CFindName.h"
#include "CFindPlace.h"
#include <map>
#include <vector>

/**
 * @brief Calendar class
 */

class CCalendar {

private:

    /**
     * @brief Map of events by Date
     */
    map< CDate, vector<CEvent> > Events;

    /**
     * @brief Map of events by ID
     */
    map< size_t, CEvent > EventsById;

    /**
     * @brief Events ID counter
     */
    size_t idCount = 1;


public:
    /**
     * @brief Default constructor
     */
    CCalendar () = default;

    /**
     * copy constructor
     * @param other Instance of calendar, that is supposed to be copied
     */
    CCalendar ( const CCalendar & other ) = default;

    /**
     * @brief Assignment operator
     * @param other Instance of calendar, that is supposed to be assigned
     * @return reference to the new Calendar
     */
    CCalendar & operator = ( const CCalendar & other ) = default;

    /**
     * @brief Destructor
     */

    ~CCalendar() = default;

    /**
     * @brief Provides the events by dates from Calendar
     * @return Map with provided Events
     */

    const map<CDate, vector<CEvent>> & provideEvents () const { return Events ; }

    /**
     * @brief Provides the events by id's from Calendar
     * @return Map with provided Events
     */
    const map<size_t, CEvent> & provideEventsById () const { return EventsById; }

    /**
     * @brief Index operator, to access an event with chosen ID.
     * @throw out_of_range when invalid ID provided
     * @param idx ID of event to be accessed
     * @return Reference to found event
     */
          CEvent & operator[]( size_t idx );
    const CEvent & operator[]( size_t idx ) const;

    /**
     * @brief Finds a free time in a chosen day
     * @param date Day, where free time will be found
     * @return vector of timeframes ( start, end ) of free time
     */

    vector<pair<CTime, CTime>> findFreeTime ( CDate date ) const;

    /**
     * @brief Checks, whether the calendar is empty
     * @return True, if the calendar has no events
     */
    bool isEmpty() const;

    /**
     * @brief Inserts an event to calendar
     * @param event Event to be inserted
     * @return Reference to the calendar
     */

    CCalendar & insert ( CEvent & event );

    /**
     * @brief Deletes an event from calendar
     * @param id ID of event to be deleted
     * @return True if successful, otherwise false
     */

    bool deleteEvent ( size_t id );

    /**
     * @brief Checks whether the event with chosen ID is in Calendar
     * @param id ID of event
     * @return True if included, otherwise false
     */
    bool isIncluded ( size_t id ) const;

    /**
     * @brief Searches events with given parameters in calendar
     * @param option Search option
     * @param interface User interface
     * @return vector of found events
     */


    /**
     * @brief left bitwise operator
     * @param os output stream
     * @param self Calendar to be printed
     * @return output stream reference
     */
    friend ostream & operator << ( ostream & os, const CCalendar & self );

    /**
     * @brief right bitwise operator
     * @param is input stream
     * @param self Calendar to be configured
     * @return input stream reference
     */
    friend istream & operator >> ( istream & is, CCalendar & self );






};



