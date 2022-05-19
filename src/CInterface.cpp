/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 23/02/2022
*/

#include "CInterface.h"
#include <limits>
#include <sstream>

CInterface::CInterface(std::istream &c_in, std::ostream &c_out): in (c_in), out (c_out)
{
    in.exceptions( ios::eofbit | ios::badbit );
    out.exceptions( ios::failbit );

}

CDate CInterface::promptDate( const string & message ) const
{
    CDate tmp;
    while (true)
    {
        out << message << std::endl;
        if ( ! ( in >> tmp ) )
        {
            out << INVALID_INPUT << endl;
            in.clear();
            continue;
        }

        break;
    }

    return tmp;
}

// ________________________________________________________________________________________________

CEvent CInterface::promptEvent() const {
    CEvent tmp;
    string name;
    string place;
    CDateTime from;
    CDateTime to;

    while ( true )
    {
        while ( true )
        {
            name = promptString( PROMPT_NAME, []( const string & name ) { return true; } );

            break;
        }

        while ( true )
        {
            place = promptString( PROMPT_PLACE, []( const string & place ) { return true; } );

            break;
        }

        while ( true )
        {
            out << EVENT_START << endl;
            if ( ! ( in >> from ) )
            {
                if ( in.eof() )
                {
                    return tmp;
                }

                in.clear();
                out << INVALID_INPUT << endl;
                continue;
            }

            break;

        }

        while ( true )
        {
            out << EVENT_END << endl;

            if ( ! ( in >> to ) )
            {
                if ( in.eof() )
                {
                    return tmp;
                }

                in.clear();
                out << INVALID_INPUT << endl;
                continue;
            }

            break;
        }

        break;
    }

    return CEvent( name, place, from, to );

}


// ________________________________________________________________________________________________

string CInterface::promptString( const string & message, const function< bool ( const string & )> & validString ) const
{
    out << message << endl;
    string tmp;
    while ( true )
    {
        if ( ( ! getline ( in, tmp )) || ! validString( toLower( tmp ) ) )
        {
            if ( in.eof() )
            {
                return tmp;
            }

            out << INVALID_INPUT << endl;
            in.clear();
            continue;
        }

        break;

    }

    in.clear();
    return tmp;

}

bool CInterface::endApp() const
{
    return ( in.eof() );
}

void CInterface::clearLine() const
{
    in.clear();
    in.ignore( numeric_limits<streamsize>::max(), '\n' );
}


void CInterface::printOption( size_t commandNumber, const string & commandInfo )  const
{
    out << commandNumber << " - " << commandInfo << endl;

}

CDateTime CInterface::promptDateTime( const string & message ) const
{
    CDateTime tmp;
    while (true)
    {
        out << message << std::endl;
        if ( ! ( in >> tmp ) )
        {
            if( in.eof() )
            {
                return tmp;
            }
            out << INVALID_INPUT << endl;
            clearLine();
            continue;
        }

        break;
    }

    return tmp;
}

void CInterface::printMessage( const string & message) const
{
    out << message << endl;
}

size_t CInterface::promptNumber( const string & message, const function< bool (size_t) > & validNumber, const string & errorMessage ) const
{
    out << message << endl;

    string line;
    size_t number;

    while ( true )
    {
        getline(in, line);

        istringstream iss( line );
        if ((!(iss >> number)) || ! (iss.eof()))
        {
            out << INVALID_INPUT << endl;
            in.clear();
            continue;
        }

        if ( !validNumber( number ))
        {
            out << errorMessage << endl;
            in.clear();
            continue;
        }

        break;
    }

    return number;
}

void CInterface::printTimeFrame( CTime start, CTime end ) const
{
    out << start << " - " << end << endl;
}

string CInterface::toLower(string text)
{
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    return text;
}






