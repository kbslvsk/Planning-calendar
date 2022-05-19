/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 23/02/2022
*/

#pragma once
#include "CDateTime.h"
#include <string>
#include <map>


/**
 * @brief Event object
 */

class CEvent {
    /**
     * @brief Start date + time of the event
     */
    CDateTime from;

    /**
     * @brief End date + time of the event
     */
    CDateTime to;

    /**
     * @brief Place of the event
     */
    string place;

    /**
     * @brief Name of the event
     */
    string name;

    /**
     * @brief Event id
     */
    size_t id = 0;

    /**
     * @brief Map with load phases of event for Import
     */
    static map<size_t, string> loadPhases;

public:
    /**
     * @brief Constructor
     */
    CEvent () = default;

    /**
     * @brief Constructor
     * @param name Event name
     * @param place Event place
     * @param from Event start
     * @param to Event end
     */
    CEvent ( string name, string place, CDateTime from, CDateTime to );

    /**
     * @brief Copy constructor
     * @param other Event to be copied
     */
    CEvent ( const CEvent & other ) = default;

    /**
     * @brief Maximal length of the event name
     */
    static const size_t maxNameWidth = 24;

    /**
     * @brief Name setter
     * @param name new name
     */

    void setName ( string name ) { this->name = move ( name ); }

    /**
     * @brief Place setter
     * @param place new place
     */
    void setPlace ( string place ) { this->place = move ( place ); }

    /**
     * @brief Time setter
     * @param from New starttime
     * @param to New endtime
     */
    void setTime ( const CDateTime & from, const CDateTime & to );

    /**
     * @brief ID setter
     * @param id New event id
     */

    void setID ( size_t id ) { this->id = id; }

    /**
     * @brief Name gettetr
     * @return Name of the event
     */
    string getName () const { return name; }

    /**
     * @brief Place getter
     * @return Place of the event
     */
    string getPlace () const { return place; }

    /**
     * @brief ID getter
     * @return ID of the event
     */
    size_t getID () const { return id ; }

    /**
     * @brief Starttime getter
     * @return Starttime of the event
     */
    CDateTime getFrom () const { return from; }

    /**
     * @brief Endtime getter
     * @return Endtime of the event
     */

    CDateTime getTo () const { return to; }

    /**
     *
     * @param os Output stream
     * @param self Event to be printed
     * @return stream with the event printed
     */

    friend ostream & operator << ( ostream & os , const CEvent & self );

    /**
     *
     * @param in Input stream
     * @param self Event to be configured
     * @return Input stream
     */
    friend istream & operator >> ( istream & in , CEvent & self );




};



