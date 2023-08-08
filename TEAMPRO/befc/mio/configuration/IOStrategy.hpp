/**
 ********************************************************************************
 * @file     IOStrategy.hpp
 * @author   madsen
 * @version  $Revision: 000 $
 * @date     $LastChangeDate: Jan 7, 2014 9:50:58 AM 11:00:00 $
 *
 * @brief    Implementation of IOStrategy
 *
 ********************************************************************************
 * COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2015
 *******************************************************************************/

#ifndef IOSTRATEGY_HPP_
#define IOSTRATEGY_HPP_

#include "mtypes.h"
#include "vector"

class BasicDigitalModule;
class BasicIoModule;

/**
 ********************************************************************************
 * @brief     The classes which inherits from this base class has the responsibility
 * 			  to implement the behaviour of how to handle IO at each cycle. This is
 * 			  done to separate the behaviour of when ProcessImage is enabled or not.
 * 			  (or maybe some third/fourth option)
 *******************************************************************************/
class IOStrategy
{

public:

    /**
     ********************************************************************************
     * @brief     This function marks the module as dirty, and when the writeOutput()
     * 			  function is called, the values of that module will be written to HW
     *
     * @param[in]  pIOModule  Pointer to the module to mark as dirty
     *******************************************************************************/
    void markModuleAsDirty(BasicIoModule *pIOModule);

    /**
     ********************************************************************************
     * @brief     This function unmmarks the module as dirty
     *
     * @param[in]  pIOModule  Pointer to the module to unmark as dirty
     *******************************************************************************/
    void unMarkAsDirty(BasicIoModule *pIOModule);

    /**
     ********************************************************************************
     * @brief     This function registers the card. This means, that it will get the
     * 			  driver id from the mio system functions, so that values can be read.
     *
     * @param[in]  pIOModule  Pointer to the module to register
     *******************************************************************************/
    virtual void registerCard(BasicIoModule *pIOModule) = 0;

    /**
     ********************************************************************************
     * @brief     This function should be called in the beginning of the task cycle.
     * 			  This will update values on all the modules in memory, which are
     * 			  registered.
     * @throws    MIOException if anything goes wrong during reading the output
     *******************************************************************************/
    virtual void readInput() = 0;

    /**
     ********************************************************************************
     * @brief     This function should be called in the end of the task cycle.
     * 			  This will write the values to the HW modules.
     *
     * @throws    MIOException if anything goes wrong during writing the output
     *******************************************************************************/
    virtual void writeOutput() = 0;

    /**
     ********************************************************************************
     * @brief     This will update values on all the modules in memory, which are
     *            registered. This is called by the readInput() function in the
     *            beginning of the task cycle
     * @throws    MIOException if anything goes wrong during reading the output
     *******************************************************************************/
    void readModuleInput(BasicIoModule *pModule);

    /**
     ********************************************************************************
     * @brief     This will write the values to the HW modules.This is called by the
     *            writeOutput() function in the end of the task cycle
     *
     * @throws    MIOException if anything goes wrong during writing the output
     *******************************************************************************/
    void writeModuleOutput(BasicIoModule *pModule);

    IOStrategy();

    virtual ~IOStrategy();

protected:

    std::vector<BasicIoModule*> *m_pRegistredCards;

    /**
     ********************************************************************************
     * @brief     Gets list of 'dirty' cards. Meaning, cards which have channels with
     *            values to be written to IO layer
     *******************************************************************************/
    std::vector<BasicIoModule*>* getDirtyList();

    /**
     ********************************************************************************
     * @brief     Clears the dirty list
     *******************************************************************************/
    void clearDirtyList();

    /**
     ********************************************************************************
     * @brief     Reads digital values in an optimized way
     *
     * @throws    MIOException if a specific channel cannot be read.
     *******************************************************************************/
    void readDigitalValues(BasicDigitalModule *pModule);

    /**
     ********************************************************************************
     * @brief     Writes digital values in an optimized way
     *
     * @throws    MIOException if a specific channel cannot be written to
     *******************************************************************************/
    void writeDigitalValues(BasicDigitalModule *pModule);

    /**
     ********************************************************************************
     * @brief     Refreshes the error state on all channels. If the module is already
     *            attached to an error listener, this function has no effect.
     *******************************************************************************/
    void refreshChannelErrorStates(BasicIoModule *pModule);

    /**
     ********************************************************************************
     * @brief     Writes all the values on the module to the IO layer, one by one
     *            using the mio_setValue function
     *******************************************************************************/
    void writeSingleValues(BasicIoModule *pModule);

    /**
     ********************************************************************************
     * @brief     Reads all the values from the IO layer one by one, using the
     *            mio_getValue function.
     *******************************************************************************/
    void readSingleValues(BasicIoModule *pModule);

private:

    std::vector<BasicIoModule*> *m_pDirtyCards;

    explicit IOStrategy(IOStrategy const& that); /** no copy */

    IOStrategy& operator=(IOStrategy const&); /** no assign */
};

#endif /* IOSTRATEGY_HPP_ */
