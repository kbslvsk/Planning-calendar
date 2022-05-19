/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 23/02/2022
*/

#pragma once
#include <iostream>
#include <string>
#include <functional>
#include "CEvent.h"
#include "textMessages.h"


/**
 * @brief User interface
 */

class CInterface {

    /**
     * Input stream
     */
    std::istream & in;

    /**
     * Output stream
     */
    std::ostream & out;

public:

    /**
     * @brief Constructor
     * @param c_in Input stream
     * @param c_out Output stream
     */
    CInterface( std::istream & c_in, std::ostream & c_out);

    /**
     * @brief Empties buffer + resets flags
     */
    void clearLine () const;

    /**
     *
     * @return True if EOF
     */
    bool endApp () const;

    /**
     * @brief Prompts user for a date
     * @param message Message to be printed for user
     * @return Date, that user entered
     */
    CDate promptDate ( const string & message ) const;

    /**
     * @brief Prompts user for a Date + time
     * @param message Message to be printed for user
     * @return Date + time, that user entered
     */
    CDateTime promptDateTime ( const string & message ) const;

    /**
     * @brief Prompts user for a string
     * @param message Message to be printed for user
     * @param validString Function, that checks, whether the entered string is valid
     * @return Entered string
     */
    string promptString ( const string & message, const function<bool ( const string & )> & validString ) const;

    /**
     * @brief Prompts user for an event
     * @return Entered event
     */
    CEvent promptEvent () const;

    /**
     * @brief Prompts user for a number
     * @param message Message to be printed for user
     * @param validNumber Checks whether the entered number is valid
     * @param errorMessage Shows, if the input was incorrect
     * @return Entered number
     */
    size_t promptNumber ( const string & message, const function< bool ( size_t )> & validNumber, const string & errorMessage ) const;

    /**
     * @brief Prints usable commands to output stream
     * @param commandNumber Number of command
     * @param commandInfo Info about command function
     */
    void printOption ( size_t commandNumber, const string & commandInfo ) const;

    /**
     * @brief Prints text to output stream
     * @param message Text to be printed
     */
    void printMessage ( const string & message ) const;

    /**
     * @brief Prints timeframe to output stream
     * @param start Start time
     * @param end End time
     */
    void printTimeFrame ( CTime start, CTime end ) const;

    /**
     * @brief Converts a string to lowercase
     * @param text Text to be converted
     * @return Converted string
     */

    static string toLower ( string text );

};



