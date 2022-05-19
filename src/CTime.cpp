/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 14/05/2022
*/

#include "CTime.h"

ostream &operator<<( ostream &os, const CTime &self)
{
    self.hour > 9 ? os << self.hour : os << "0" << self.hour;
    os << ":";
    self.min > 9 ? os << self.min : os << "0" << self.min;
    return os;
}

