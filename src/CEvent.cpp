/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 23/02/2022
*/

#include "CEvent.h"

#include <utility>
#include <sstream>

CEvent::CEvent( string name, string place, CDateTime from, CDateTime to ) {

    if ( from >= to )
    {
        throw logic_error("Start of the event has to be earlier than its end!");
    }

    if ( name.length() > maxNameWidth )
    {
        throw logic_error("Event name is too long! Max. length is " + to_string( maxNameWidth ));
    }


    this->from = from ;
    this->to = to;
    this->place = move(place);
    this->name = move(name);

}

ostream &operator<< ( ostream &os, const CEvent & self )
{
    os << "ID: " << self.id << endl;
    os << "Name: " << self.name << endl;
    os << "Place: " << self.place << endl;
    os << "From: " << self.from << endl;
    os << "To: " << self.to;
    return os;
}

istream & operator >> ( istream & in, CEvent & self )
{
    string loadedLine;
    string editedData;
    string name, place;
    CDateTime tmpFrom, tmpTo;

    for ( size_t i = 1; i <= 5 ; ++i )
    {
        if ( ! getline ( in, loadedLine )) { return in; }

        if ( loadedLine.find( CEvent::loadPhases[i] ) != 0 )
        {
            in.setstate( ios::failbit );
            return in;
        }

        loadedLine.erase( 0, CEvent::loadPhases[i].length() );

        if ( i != 1 )
        editedData += ( loadedLine + '\n' );
    }

    istringstream iss ( editedData );

    if ( ! getline ( iss, name ) || ! getline ( iss, place ) || ! ( iss >> tmpFrom >> tmpTo ))
    {
        in.setstate( ios::failbit );
        return in;
    }

    self.from = tmpFrom;
    self.to = tmpTo;
    self.name = name;
    self.place = place;

    if ( self.from >= self.to || self.name.length() > CEvent::maxNameWidth )
    {
        in.setstate( ios::failbit );
        return in;
    }

    return in;

}

void CEvent::setTime(const CDateTime & from, const CDateTime & to)
{
    if ( from >= to )
    {
        cout << from << ", " << to << endl;
        throw logic_error("Start of the event has to be earlier than its end! Try again.");
    }

    this->from = from;
    this->to   = to;
}

map<size_t, string> CEvent::loadPhases =
        {
                { 1, "ID:" },
                { 2, "Name:" },
                { 3, "Place: " },
                { 4, "From: "},
                { 5, "To: "}
        };





