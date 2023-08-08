/**
 ********************************************************************************
 * @file     teampro_app.hpp
 * @author   gravers
 * @version  $Revision: 000 $
 * @date     $LastChangeDate: Feb 18, 2013 1:20:23 PM $
 *
 * @brief    This is an example of an instance of a working task for
 *           an application.
 *
 ********************************************************************************
 * COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2015
 *******************************************************************************/

/** Avoid problems with multiple inclusion */
#ifndef TEAMPRO_APP_HPP_
#define TEAMPRO_APP_HPP_


/** Includes */
#include <string>
#include "BETask.hpp"

/**
 * @addtogroup APP-TASK
 * @{
 */
class teampro_app: public BETask


{
public:
    teampro_app(BETaskConfiguration conf);
    ~teampro_app();

    /**
     ********************************************************************************
     * @brief     This method is called cyclic for this application task.
     *******************************************************************************/
    void cycleWork(void);


private:

    int counter;
};

/** @} */

#endif  /** TEAMPRO_APP_HPP_ */
