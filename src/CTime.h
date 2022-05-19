/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 14/05/2022
*/

#pragma once
#include <iostream>

using namespace std;

/**
 * @brief Time class holding time info with hours + minutes
 */

class CTime {

    /**
     * @brief Hours
     */
    size_t hour = 0;

    /**
     * Minutes
     */
    size_t min = 0;

public:

    /**
     * @brief Default constructor
     */
    CTime () = default;

    /**
     * @brief Constructor
     * @param hour Hours
     * @param min Minutes
     */
    CTime ( size_t hour, size_t min ): hour ( hour ), min ( min ){}

    /**
     *
     * @param other Second time
     * @return True if the first time is earlier
     */
    bool operator < ( const CTime other ) const { return hour == other.hour ? min < other.min : hour < other.hour; }

    /**
     *
     * @param other Second time
     * @return True if the first time and second time is equal
     */
    bool operator == ( const CTime other ) const { return ( hour == other.hour && min == other.min ) ; }

    /**
     *
     * @param other Second time
     * @return True if the first time is later or equal
     */
    bool operator >= ( const CTime other ) const { return !( *this < other );}

    /**
     *
     * @param other Second time
     * @return True if the first time is later
     */
    bool operator > ( const CTime other ) const { return ( !( *this < other ) && !( *this == other ) ); }

    /**
     *
     * @param other Second time
     * @return True if the first time is earlier or equal
     */
    bool operator <= ( const CTime other ) const { return ( !( *this > other )); }

    /**
     *
     * @param other Second time
     * @return True if the first and second time are not equal
     */
    bool operator != ( const CTime other ) const { return !( *this == other );}

    /**
     * @brief Hours getter
     * @return Hours
     */
    size_t getHour () const { return hour ;}

    /**
     * @brief Minutes getter
     * @return Minutes
     */
    size_t getMin () const { return min; }

    /**
     *
     * @param os Output stream
     * @param self CTime object
     * @return Stream with printed time object
     */

    friend ostream & operator << ( ostream & os, const CTime & self );


};



