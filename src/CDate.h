/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 12/02/2022
*/

#pragma once

#include <iostream>
#include <vector>

using namespace std;

/**
 * Class to work with time
 */

class CDate {

protected:
    int year = 0;
    int month = 0;
    int day = 0;

    /**
     * @brief Checks whether the date is valid
     * @return true if valid, otherwise false
     */
    bool isValid () const;

    /**
     *
     * @return number of days in month
     */
    int daysInMonth () const;

    /**
     * @brief Checks whether the year is leap
     * @return True if leap, otherwise false
     */
    bool isLeap () const;

public:

    /**
     * @brief Default constructor
     */
     CDate () = default;

     /**
      * @brief Constructor
      * @param day Day
      * @param month Month
      * @param year Year
      */

     CDate ( int day, int month, int year );

     /**
      * @brief Destructor
      */

     ~CDate ( ) = default;

     /**
      * @param timeStruct tm pointer to configure time structure from date
      */
     void makeTimeStruct ( tm* timeStruct ) const;

     /**
      * @brief Assignment operator
      * @param other Date to be assigned
      * @return Reference to modified date
      */

     CDate & operator = ( const CDate & other ) = default;

     /**
      *
      * @return vector of days in week, which is the chosen date part of
      */
     vector<CDate> getWeekFromDate () const;

     /**
      *
      * @param other second date
      * @return true if both dates are same
      */

     bool operator == ( const CDate & other ) const;

     /**
      *
      * @param other second date
      * @return true if the first date is later
      */

     bool operator > ( const CDate & other ) const;

    /**
    *
    * @param other second date
    * @return true if the first date is earlier
    */

     bool operator < ( const CDate & other ) const;

    /**
    *
    * @param other second date
    * @return true if the first date is earlier or equal
    */

     bool operator <= ( const CDate & other ) const;

    /**
    *
    * @param other second date
    * @return true if the first date is later or equal
    */

     bool operator >= ( const CDate & other ) const;

    /**
    *
    * @param other second date
    * @return true if the dates are not equal
    */

     bool operator != ( const CDate & other ) const;

     /**
      * @brief Left bitwise operator
      * @param os output stream
      * @param self Date to be printed
      * @return output stream reference
      */

     friend ostream & operator << ( ostream & os , const CDate & self );

     /**
      * @brief Right bitwise operator
      * @param in input stream
      * @param self Date to be modified
      * @return input stream reference
      */

     friend istream & operator >> ( istream & in , CDate & self );



};



