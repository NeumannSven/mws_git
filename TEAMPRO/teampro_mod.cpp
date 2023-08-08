/**
 ********************************************************************************
 * @file     teampro_mod.cpp
 * @author   gravers
 * @version  $Revision: 000 $
 * @date     $LastChangeDate: Feb 18, 2013 1:20:23 PM $
 *
 * @brief    This is the implementation of the entry point of the application.
 *           Working tasks are created and added in the @see doInit method.
 *
 ********************************************************************************
 * COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2015
 *******************************************************************************/

/** Includes */
#include "mcpp.hpp"

#include "teampro_mod.hpp"
#include "teampro_app.hpp"
#include <string>
#include "BETaskConfiguration.hpp"


using namespace std;


/** globals */
BEModule* MainModule;

/** SW-Module memory partition, needed for new operator */
UINT32 teampro_MemPart = 0;
UINT32 teampro_DebugMode = 0;
UINT32 befc_DebugMode = 0;

/** Function definitions */


/**
 ********************************************************************************
 * @brief         This function is the entry point to the module.
 *                After module loading this function will be called as part
 *                of the module handler.
 *                This function has to initialize the interfaces to the
 *                environment (SMI, SVI) so that they are ready to operate.
 *
 *
 * @param[in]  pConf   Parameter for configuration (data from MCONFIG.INI).
 * @param[in]  pLoad   Parameter from module loading.
 * @retval     >0      Task-Id, module initialized correctly.
 * @retval     <0      Error during initialization.
 *******************************************************************************/
extern "C" SINT32 teampro_Init(MOD_CONF *pConf, MOD_LOAD *pLoad)
{
    /** SW-Module memory partition, needed for new operator */
    teampro_MemPart = pConf->MemPart;
    teampro_DebugMode = pConf->DebugMode;
    befc_DebugMode = pConf->DebugMode;

    try
    {
        /** Create new application class. */
        MainModule = new teampro_mod();
        MainModule->init(pConf, pLoad);
        /** return the task int to the module handler */
        return MainModule->getSmiTaskId();
    }
    catch(int e)
    {
        /** Close application if an error is occurred. */
        SAFE_DELETE(MainModule)
        return(e);
    }

    return(0);
}

teampro_mod::teampro_mod()
{
}

teampro_mod::teampro_mod(VOIDFUNCPTR fpPanicHandler) : BEModule(fpPanicHandler)
{
}

teampro_mod::~teampro_mod()
{
}


BOOL8 teampro_mod::doInit(VOID)
{
        /** Create application task class */
        addTask(new teampro_app(BETaskConfiguration(this, "a" + getAppName())));
        return (true);

}

