/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 14/05/2022
*/

#pragma once
#include "CFindPlace.h"
#include "CFindName.h"
#include "CFindID.h"

/**
 * @brief Class with possible find options to be used
 */
class CFindManager {

    /**
     * @brief Map with possible find options
     */
    map<string, unique_ptr<CFind>> findOptions;

public:

    /**
     * @brief Constructor
     */
    CFindManager();

    /**
     * @brief Finds options
     * @param wantedOption Option to be found
     * @return Unique_ptr to wanted option, nullptr if invalid
     */
    unique_ptr<CFind> getOption ( const string & wantedOption ) const;

};



