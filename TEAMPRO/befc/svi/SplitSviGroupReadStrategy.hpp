/*
 * SplitSviGroupReadStrategy.hpp
 *
 *  Created on: Apr 22, 2022
 *      Author: madsen
 */

#ifndef BEFC_SVI_SPLITSVIGROUPREADSTRATEGY_HPP_
#define BEFC_SVI_SPLITSVIGROUPREADSTRATEGY_HPP_

#include <SviGroupItemStrategy.hpp>
#include "MixedReadStrategyImpl.hpp"
#include "SvigroupContainer.hpp"

/**
 *  Strategy which splits failed items into a failed group, and optimizes
 *  the OK items by using the @see MixedReadStrategyImpl strategy.
 *  For the failed items, it uses the @see SingleItemStrategyImpl strategy,
 *  which uses a single call for each item.
 */
class SplitSviGroupReadStrategy: public SviGroupItemStrategy
{
public:
    SplitSviGroupReadStrategy(SviSystem *pSystem);

    virtual TFailList readValues(AbstractSviGroup *pGroup);

    virtual TFailList writeValues(AbstractSviGroup *pGroup);

private:

    SviGroupContainer *pContainerOK;

    SviGroupContainer *pContainerFault;

    MixedReadStrategyImpl *pStrategy;

    SingleItemStrategyImpl *pSingleItemStrategy;

    virtual ~SplitSviGroupReadStrategy();
};


#endif /* BEFC_SVI_SPLITSVIGROUPREADSTRATEGY_HPP_ */
