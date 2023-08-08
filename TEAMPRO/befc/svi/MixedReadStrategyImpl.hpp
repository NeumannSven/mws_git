/*
 * MixedReadStrategy.hpp
 *
 *  Created on: Jan 5, 2021
 *      Author: madsen
 */

#ifndef RES_BEFC_SVI_MIXEDREADSTRATEGYIMPL_HPP_
#define RES_BEFC_SVI_MIXEDREADSTRATEGYIMPL_HPP_

#include <SviGroupItemStrategy.hpp>
#include "SingleItemReadStrategyImpl.hpp"
#include "ListReadStrategyImpl.hpp"

/**
 * Strategy, which makes use of both the list and single read option.
 *
 * It starts with reading the optimized way as reading a list of svi variables,
 * and if that fails somehow - all the SVI variables are read one by one.
 *
 */
class MixedReadStrategyImpl: public SviGroupItemStrategy
{
public:
    MixedReadStrategyImpl(SviSystem *pSystem);

    virtual TFailList readValues(AbstractSviGroup *pGroup);

    virtual TFailList writeValues(AbstractSviGroup *pGroup);

    virtual ~MixedReadStrategyImpl();

private:

    SingleItemStrategyImpl *pSingleStrategy;

    ListReadStrategyImpl *pListStrategy;

};

#endif /* RES_BEFC_SVI_MIXEDREADSTRATEGYIMPL_HPP_ */
