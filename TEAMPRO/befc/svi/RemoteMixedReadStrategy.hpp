/*
 * RemoteMixedReadStrategy.hpp
 *
 *  Created on: Aug 31, 2021
 *      Author: madsen
 */

#ifndef RES_BEFC_SVI_REMOTEMIXEDREADSTRATEGY_HPP_
#define RES_BEFC_SVI_REMOTEMIXEDREADSTRATEGY_HPP_

#include <SviGroupItemStrategy.hpp>
#include "RemoteSviListReadStrategy.hpp"
#include "RemoteSviReadStrategy.hpp"

class RemoteMixedReadStrategy: public SviGroupItemStrategy
{
public:
    RemoteMixedReadStrategy(SmiClient *pClient);

    TFailList readValues(AbstractSviGroup *pGroup);

    TFailList writeValues(AbstractSviGroup *pGroup);

    virtual ~RemoteMixedReadStrategy();

private:

    RemoteSviListReadStrategy *pStrat1;

    RemoteSviReadStrategy *pStrat2;
};

#endif /* RES_BEFC_SVI_REMOTEMIXEDREADSTRATEGY_HPP_ */
