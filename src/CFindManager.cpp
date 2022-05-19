/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 14/05/2022
*/

#include "CFindManager.h"

CFindManager::CFindManager()
{
    findOptions.emplace("id"  , make_unique<CFindID>());
    findOptions.emplace("name" , make_unique<CFindName>());
    findOptions.emplace("place", make_unique<CFindPlace>());
}

unique_ptr<CFind> CFindManager::getOption( const string &wantedOption ) const
{
    auto search = findOptions.find( wantedOption );

    if ( search == findOptions.end() )
    {
        return nullptr;
    }

    return search->second->clone();
}
