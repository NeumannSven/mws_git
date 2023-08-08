/*
 * ManualMixedIOConfigurationFactory.hpp
 *
 *  Created on: Apr 8, 2022
 *      Author: madsen
 */

#ifndef RES_BEFC_MIO_CONFIGURATION_MANUALMIXEDIOCONFIGURATIONFACTORY_HPP_
#define RES_BEFC_MIO_CONFIGURATION_MANUALMIXEDIOCONFIGURATIONFACTORY_HPP_

#include <IOConfigurationFactory.hpp>

/**
 ********************************************************************************
 * @brief     This is a variant of the IOConfigurationFactory, which makes it
 *            possible to make use of both the Process Image and normal MIO
 *            handling. Card is added to the PI if possible, and if that fails,
 *            the normal approach is used.
 *            It does not autodetect any cards on the backplane - cards should be
 *            added manually.
 *******************************************************************************/
class ManualMixedIOConfigurationFactory: public IOConfigurationFactory
{
public:
    ManualMixedIOConfigurationFactory();

    MIOConfiguration* createConfiguration(IOStrategy *pIOStrategy);

    IOStrategy* createIOStrategy(BETask *pTask);

    virtual ~ManualMixedIOConfigurationFactory();
};

#endif /* RES_BEFC_MIO_CONFIGURATION_MANUALMIXEDIOCONFIGURATIONFACTORY_HPP_ */
