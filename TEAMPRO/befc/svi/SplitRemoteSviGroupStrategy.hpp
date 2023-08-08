/*
 * SplitRemoteSviGroupStrategy.hpp
 *
 *  Created on: Apr 25, 2022
 *      Author: madsen
 */

#ifndef BEFC_SVI_SPLITREMOTESVIGROUPSTRATEGY_HPP_
#define BEFC_SVI_SPLITREMOTESVIGROUPSTRATEGY_HPP_

#include <SviGroupItemStrategy.hpp>
#include "RemoteMixedReadStrategy.hpp"
#include "RemoteSviReadStrategy.hpp"
#include "SvigroupContainer.hpp"

/**
 *  Strategy which splits failed items into a failed group, and optimizes
 *  the OK items by using the @see RemoteSviListReadStrategy strategy.
 *  For the failed items, it uses the @see RemoteSviReadStrategy strategy,
 *  which uses a single call for each item.
 */
class SplitRemoteSviGroupStrategy : public SviGroupItemStrategy
{
public:
    SplitRemoteSviGroupStrategy(SmiClient *pClient);

    virtual TFailList readValues(AbstractSviGroup *pGroup);

    virtual TFailList writeValues(AbstractSviGroup *pGroup);

    virtual ~SplitRemoteSviGroupStrategy();


private:

    SviGroupContainer *pContainerOK;

    SviGroupContainer *pContainerFault;

    SviGroupItemStrategy *pStrategy;

    SviGroupItemStrategy *pSingleItemStrategy;

};

#endif /* BEFC_SVI_SPLITREMOTESVIGROUPSTRATEGY_HPP_ */
