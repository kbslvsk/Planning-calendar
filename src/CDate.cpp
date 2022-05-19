/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 12/02/2022
*/


#include "CDate.h"
#include <sstream>


CDate::CDate ( int day, int month, int year ) {
    this->year = year;
    this->month = month;
    this->day = day;
}

bool CDate::operator == ( const CDate &other ) const {
    return ( year == other.year && other.month == month && day == other.day );
}

bool CDate::operator > ( const CDate &other ) const {
    return ( year > other.year ||
           ( year == other.year && month > other.month ) ||
           ( year == other.year && month == other.month && day > other.day )
           );
}

bool CDate::operator < ( const CDate &other ) const {
    return ( !( *this > other ) && !( *this == other ) );
}

bool CDate::operator <= ( const CDate &other ) const {
    return ( !( *this > other ) );
}

bool CDate::operator >= ( const CDate &other ) const {
    return ( !( *this < other ) );
}

bool CDate::operator != ( const CDate &other ) const {
    return ( !( *this == other ) );
}

ostream &operator << ( ostream &os, const CDate &self ) {
    ( self.day   <= 9 )? os << "0" << self.day : os << self.day;
    os << "/";
    ( self.month <= 9 )? os << "0" << self.month : os << self.month;
    os << "/";
    os << self.year;
    return os;
}

istream & operator >> ( istream &in, CDate &self ) {

    int year, month, day;
    char SEPARATOR, SEPARATOR2;
    string line;

    if ( ! getline( in, line )) { return in ; }

    istringstream iss ( line );

    if ( ! ( iss >> day >> SEPARATOR >> month >> SEPARATOR2 >> year ) || ! ( iss.eof() ) || !(SEPARATOR == '/' && SEPARATOR2 == '/'))
    {
        in.setstate(ios::failbit);
        return in;
    }


    CDate tmp ( day , month , year );

    if (! tmp.isValid())
    {
        in.setstate(ios::failbit);
        return in;
    }

    self = tmp;
    return in;
}

int CDate::daysInMonth () const {
    switch ( month ) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: return 31;
        case 4:
        case 6:
        case 9:
        case 11: return 30;
        case 2: if (isLeap()) { return 29; } else { return 28; }
        default: return 0;
    }
}

bool CDate::isLeap () const {
    if (year % 4 == 0) {
        if ( year % 100 == 0) {
            if (year % 400 == 0 ) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}


bool CDate::isValid () const {
    return ( month >= 1 && month <= 12 && day >= 1 && day <= daysInMonth() && year >= 2000 );
}

void CDate::makeTimeStruct( tm* timeStruct ) const
{
    timeStruct->tm_year = year - 1900;
    timeStruct->tm_mon = month - 1;
    timeStruct->tm_mday = day;
}

vector<CDate> CDate::getWeekFromDate() const
{
    vector<CDate> dates;
    time_t t = time( nullptr );
    tm timeStruct = *localtime( &t );
    makeTimeStruct( &timeStruct );
    mktime(&timeStruct);

    if ( timeStruct.tm_wday == 0 )
    {
        timeStruct.tm_mday -= 6;
    }

    else
    {
        timeStruct.tm_mday -= ( timeStruct.tm_wday - 1 );
    }

    for ( size_t i = 0 ; i < 7 ; ++i )
    {
        mktime ( &timeStruct );
        dates.emplace_back( timeStruct.tm_mday, timeStruct.tm_mon + 1, timeStruct.tm_year + 1900 );
        timeStruct.tm_mday += 1;
    }

    return dates;
}


