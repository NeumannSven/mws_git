/**
 ********************************************************************************
 * @file     mcpp.hpp
 * @author   eckrodt
 * @version  $Revision: 000 $
 * @date     $LastChangeDate: Jan 25, 2013 05:40:00 AM 11:00:00 $
 *
 * @brief    This file implements helper function for BEFC.
 *
 ********************************************************************************
 * COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2015
 *******************************************************************************/

/** Avoid problems with multiple inclusion */
#ifndef MCPP_HPP_
#define MCPP_HPP_

#include <typeinfo>
#include <sstream>

#include <mtypes.h>
#include <log_e.h>

/**
 * @addtogroup COM
 * @{
 */

extern UINT32 befc_DebugMode;

#define CLASSNAME (typeid(this).name())

// MACRO for logging internal BEFC messages, with class and function name include in message
#define befc_int_info(s){std::stringstream log; log << CLASSNAME << "::" << __FUNCTION__ << ": " << s; log_Info("%s",log.str().c_str()); }
#define befc_int_warn(s){std::stringstream log; log << CLASSNAME << "::" << __FUNCTION__ << ": " << s; log_Wrn("%s",log.str().c_str()); }
#define befc_int_error(s){std::stringstream log; log << CLASSNAME << "::" << __FUNCTION__ << ": " << s; log_Err("%s",log.str().c_str()); }

// MACRO for logging BEFC messages
#define befc_info(level, s) {std::stringstream log; log << s; if((!level) || (level == (level & befc_DebugMode))) {log_Info("%s",log.str().c_str());}; }
#define befc_warn(level, s) {std::stringstream log; log << s; if((!level) || (level == (level & befc_DebugMode))) {log_Wrn("%s",log.str().c_str());}; }
#define befc_error(level, s){std::stringstream log; log << s; if((!level) || (level == (level & befc_DebugMode))) {log_Err("%s",log.str().c_str());}; }


#define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }

/** @} */

#endif  /** MCPP_HPP_*/
