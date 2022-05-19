/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 12/02/2022
*/

#include "CDateTime.h"
#include <sstream>

CDateTime::CDateTime ( int c_hour, int c_min, int day, int month, int year ) :
                      CDate( day, month, year ) ,
                      hour ( c_hour) ,
                      min  ( c_min)
                      {}

bool CDateTime::operator == ( const CDateTime &other ) const {
    return ( min == other.min &&
             hour == other.hour &&
             CDate( day, month, year ) == CDate (other.day, other.month, other.year));
}

bool CDateTime::operator > ( const CDateTime &other ) const {
    CDate thisTmp ( day, month, year );
    CDate otherTmp ( other.day, other.month, other.year );

    return ( thisTmp > otherTmp ||
            (thisTmp == otherTmp && hour > other.hour ) ||
            (thisTmp == otherTmp && hour == other.hour && min > other.min )
            );
}

bool CDateTime::operator<(const CDateTime &other) const {
    return ( !( *this == other ) && !( *this > other ) );
}

bool CDateTime::operator<=(const CDateTime &other) const {
    return ( !( *this > other ) );
}

bool CDateTime::operator>=(const CDateTime &other) const {
    return ( !( *this < other ) );
}

bool CDateTime::operator!=(const CDateTime &other) const {
    return ( !( *this == other ) );
}

ostream &operator<<(ostream &os, const CDateTime &self) {
    ( self.hour <= 9 ) ? os << "0" << self.hour : os << self.hour;
    os << ":";
    ( self.min  <= 9 ) ? os << "0" << self.min  : os << self.min;
    os << " ";
    CDate tmp ( self.day, self.month, self.year );
    os << tmp ;
    return os;
}

istream &operator >> (istream &in, CDateTime &self) {
    int hour, min, year, month, day;
    char SEPARATOR1, SEPARATOR2, SEPARATOR3;

    string line;
    getline ( in, line );
    istringstream iss ( line );

    if ( ! ( iss >> hour >> SEPARATOR1 >> min >> day >> SEPARATOR2 >> month >> SEPARATOR3 >> year ) || ! iss.eof() ||
         ! ( SEPARATOR1 == ':' && SEPARATOR2 == '/' && SEPARATOR3 == '/' ))
    {
        in.setstate( ios::failbit );
        return in ;
    }


    CDateTime tmp ( hour, min, day, month, year );

    if ( ! tmp.isValid() )
    {
        in.setstate(ios::failbit);
        return in;
    }

    self = tmp;
    return in;
}

bool CDateTime::isValid() const {
    return ( month >= 1 && month <= 12 && day >= 1 && day <= daysInMonth() && year >= 2000
          && hour >= 0 && hour <= 23 && min >= 0 && min <= 59 );
}

void CDateTime::makeTimeStruct( tm* timeStruct) const
{
    timeStruct->tm_year = year - 1900;
    timeStruct->tm_mon = month - 1;
    timeStruct->tm_mday = day;
    timeStruct->tm_hour = hour;
    timeStruct->tm_min = min;
}
