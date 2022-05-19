/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 11/05/2022
*/

#pragma once
#include <memory>
#include <functional>
#include <utility>
#include <map>
#include "CInterface.h"

/**
 * @brief Abstract class used to find events in different modes
 */
class CFind {

public:

    /**
     * @brief Default constructor
     */
    CFind() = default;

    /**
     * @brief Copy constructor
     * @param other Find object to be copied
     */
    CFind ( const CFind & other ) = default;

    CFind & operator = ( const CFind & ) = delete;

    /**
     * @brief Virtual destructor
     */
    virtual ~CFind() = default;

    /**
     * @brief Function, that makes identical copy of self
     * @return unique_ptr to identical copy
     */
    virtual unique_ptr<CFind> clone () const = 0;

    /**
     * @brief Configures find details
     * @param interface User interface
     * @return Reference to self
     */
    virtual CFind & configure ( const CInterface & interface ) = 0;

    /**
     * @brief Finds events with chosen parameters
     * @param events Map of events
     * @return Vector of found events
     */
    virtual vector<CEvent> find ( const map<size_t, CEvent> & events ) const = 0;
};
