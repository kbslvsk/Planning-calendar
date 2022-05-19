/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 12/02/2022
*/

#pragma once

#include "CDate.h"
#include "CTime.h"

/**
 * CDateTime : Class to work with timestamp ( Date + time )
 */
class CDateTime : public CDate {

private:
    /**
     * @brief Hour info
     */
    int hour = 0;

    /**
     * @brief Minutes info
     */
    int min = 0;

    /**
     * @brief Checks whether the Date + time is valid
     * @return True if valid
     */
    bool isValid () const;

public:

    /**
     * @brief Default constructor
     */
     CDateTime () = default;

     /**
      * @brief Constructor
      * @param c_hour Hours
      * @param c_min Minutes
      * @param day Day
      * @param month Month
      * @param year Year
      */
     CDateTime( int c_hour, int c_min, int day, int month, int year );

     /**
      * @brief Destructor
      */
    ~CDateTime () = default;

    /**
     * @brief Makes tm time structure
     * @param timeStruct Pointer to tm structure to be configured
     */

    void makeTimeStruct ( tm* timeStruct ) const;

    /**
     * @brief Time getter
     * @return Timestamp
     */
    CTime getTime () const { return CTime ( hour, min ) ;}

    /**
     * @brief Assignment operator
     * @param other Datetime to be assigned
     * @return reference to modified Datetime
     */

    CDateTime & operator = ( const CDateTime & other ) = default;

    /**
      *
      * @param other second datetime
      * @return true if both datetimes are same
      */

    bool operator == ( const CDateTime & other ) const;

    /**
      *
      * @param other second datetime
      * @return true if the first datetime is later
      */

    bool operator > ( const CDateTime & other ) const;

    /**
    *
    * @param other second datetime
    * @return true if the first datetime is earlier
    */

    bool operator < ( const CDateTime & other ) const;

    /**
    *
    * @param other second datetime
    * @return true if the first datetime is earlier or equal
    */

    bool operator <= ( const CDateTime & other ) const;

    /**
    *
    * @param other second datetime
    * @return true if the first datetime is later or equal
    */

    bool operator >= ( const CDateTime & other ) const;

    /**
    *
    * @param other second datetime
    * @return true if the datetimes are not equal
    */

    bool operator != ( const CDateTime & other ) const;

    /**
      * @brief Left bitwise operator
      * @param os output stream
      * @param self Datetime to be printed
      * @return output stream reference
      */

    friend ostream & operator << ( ostream & os , const CDateTime& self );

    /**
      * @brief Right bitwise operator
      * @param in input stream
      * @param self Datetime to be modified
      * @return input stream reference
      */

    friend istream & operator >> ( istream & in , CDateTime & self );

};



