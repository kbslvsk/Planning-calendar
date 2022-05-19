/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 14/05/2022
*/

#pragma once
#include "CFind.h"

/**
 * @brief Finds events by place
 */
class CFindPlace : public CFind {

    /**
     * @brief wanted event place
     */
    string place;

public:
    /**
     * @brief Function, that makes identical copy of self
     * @return unique_ptr to identical copy
     */
    virtual unique_ptr<CFind> clone () const override { return make_unique<CFindPlace>( *this );}

    /**
     * @brief Configures find details
     * @param interface User interface
     * @return Reference to self
     */
    virtual CFind & configure ( const CInterface & interface ) override;

    /**
     * @brief Finds events with chosen parameters
     * @param events Map of events
     * @return Vector of found events
     */
    virtual vector<CEvent> find ( const map<size_t, CEvent> & events ) const override;
};



