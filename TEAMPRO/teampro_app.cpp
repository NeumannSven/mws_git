/**
 ********************************************************************************
 * @file     teampro_app.cpp
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
#define CLASS_NAME "teampro_app"

/** Includes */
#include "mcpp.hpp"
#include "teampro_app.hpp"
#include "BEModule.hpp"
#include "log_e.h"
#include <iostream>
#include "BETaskConfiguration.hpp"

using namespace std;

teampro_app::teampro_app(BETaskConfiguration conf) :
        BETask(conf)
{
}

teampro_app::~teampro_app()
{

}

void teampro_app::cycleWork(void)
{
}

