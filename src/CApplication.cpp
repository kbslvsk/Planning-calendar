/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 11/02/2022
*/

#include "CApplication.h"

using namespace std;


int CApplication::run()
{
    printf("\n \n%s", "|  __ \\| |                 (_)              / ____|    | |              | |           \n"
                      "| |__) | | __ _ _ __  _ __  _ _ __   __ _  | |     __ _| | ___ _ __   __| | __ _ _ __ \n"
                      "|  ___/| |/ _` | '_ \\| '_ \\| | '_ \\ / _` | | |    / _` | |/ _ \\ '_ \\ / _` |/ _` | '__|\n"
                      "| |    | | (_| | | | | | | | | | | | (_| | | |___| (_| | |  __/ | | | (_| | (_| | |   \n"
                      "|_|    |_|\\__,_|_| |_|_| |_|_|_| |_|\\__, |  \\_____\\__,_|_|\\___|_| |_|\\__,_|\\__,_|_|   \n"
                      "                                     __/ |                                            \n"
                      "                                    |___/                                             \n");

    while ( true )
    {
        interface.printMessage("\n\n\n");

        for ( const auto & it : commands )
        {
            interface.printOption( it.first, it.second.getInfo() );
        }

        try
        {
            size_t nextAction = interface.promptNumber( PROMPT_ACTION, [this](size_t action) {
                return ( this->commands.find(action) != this->commands.end() );
            }, UNKNOWN_COMMAND);

            auto command = commands.find(nextAction);
            if ( ! command->second.execute( interface, calendar ))
            {
                return 0;
            }
        }

        catch ( const ios_base::failure& fail )
        {
            if ( interface.endApp() )
            {
                return 0;
            }

            return 1;
        }

    }
    return 0;
}

CApplication::CApplication( CInterface interface ) : interface( interface ), calendar ( CCalendar() )
{
    commands.emplace( 1, CCommand::addEvent() );
    commands.emplace( 2, CCommand::editEvent());
    commands.emplace( 3, CCommand::viewEvents());
    commands.emplace( 4, CCommand::setRepetition());
    commands.emplace( 5, CCommand::searchForEvents());
    commands.emplace( 6, CCommand::exportCommand());
    commands.emplace( 7, CCommand::importCommand());
    commands.emplace( 8, CCommand::freeTimeFinder());
    commands.emplace( 9, CCommand::endApp()   );
}
