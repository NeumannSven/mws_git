/*
 * SysConfiguration.hpp
 *
 *  Created on: May 16, 2018
 *      Author: sovve
 */

#ifndef RES_BEFC_MODULE_SYSCONFIGURATION_HPP_
#define RES_BEFC_MODULE_SYSCONFIGURATION_HPP_

#include <string>
#include <mtypes.h>

class SysConfiguration
{
public:
    SysConfiguration(const std::string Section, const std::string Group, const std::string FileName);
    SysConfiguration(const std::string Section, const std::string Group, const std::string ValueName, const std::string FileName);
    ~SysConfiguration();
    VOID init(const std::string Section, const std::string Group, const std::string FileName);

    VOID setValue(const std::string Value);
    VOID setValue(BOOL8 Value);
    VOID setValue(BOOL32 Value);
    VOID setValue(UINT32 Value);
    VOID setValue(REAL32 Value);
    VOID setValue(const std::string ValueName, const std::string Value);
    VOID setValue(const std::string ValueName, const std::string Value, BOOL8 create);
    VOID setValue(const std::string ValueName, BOOL8 Value);
    VOID setValue(const std::string ValueName, BOOL32 Value);
    VOID setValue(const std::string ValueName, UINT32 Value);
    VOID setValue(const std::string ValueName, REAL32 Value);
    VOID setPrecision(UINT32 Precision) {m_Precision = Precision;}
    VOID setValueHEX(UINT32 Value, const UINT32 Width);
    VOID setValueHEX(const std::string ValueName, UINT32 Value, UINT32 Width);

    /**
     ********************************************************************************
     * @brief      Gets a configuration key as integer.
     *
     * @param[in]  group            The name of group where key exists
     * @param[in]  keyword          The name of the key
     * @throws     ModuleException  If key does not exist in mconfig.ini
     * @retval     The value as integer
     *******************************************************************************/
    SINT32 getConfigAsInt(std::string group, std::string keyword);

    /**
     ********************************************************************************
     * @brief      Gets a configuration key as integer.
     *
     * @param[in]  group            The name of group where key exists
     * @param[in]  set              The name of set when key exist
     * @param[in]  unit             The name of unit when key exist
     * @param[in]  keyword          The name of the key
     * @throws     ModuleException  If key does not exist in mconfig.ini
     * @retval     The value as integer
     *******************************************************************************/
    SINT32 getConfigAsInt(std::string group, std::string set, std::string unit,
            std::string keyword);

    /**
     ********************************************************************************
     * @brief      Gets a configuration key as decimal number.
     *
     * @param[in]  group            The name of group where key exists
     * @param[in]  keyword          The name of the key
     * @throws     ModuleException  If key does not exist in mconfig.ini
     * @retval     The value as REAL32
     *******************************************************************************/
    REAL32 getConfigAsReal(std::string group, std::string keyword);

    /**
     ********************************************************************************
     * @brief      Gets a configuration key as decimal number.
     *
     * @param[in]  keyword          The name of the key
     * @throws     ModuleException  If key does not exist in mconfig.ini
     * @retval     The value as REAL32
     *******************************************************************************/
    REAL32 getConfigAsReal(std::string keyword);

    /**
     ********************************************************************************
     * @brief      Gets a configuration key as decimal number.
     *
     * @param[in]  group            The name of group where key exists
     * @param[in]  set              The name of set when key exist
     * @param[in]  unit             The name of unit when key exist
     * @param[in]  keyword          The name of the key
     * @throws     ModuleException  If key does not exist in mconfig.ini
     * @retval     The value as REAL32
     *******************************************************************************/
    REAL32 getConfigAsReal(std::string group, std::string set, std::string unit,
            std::string keyword);

    /**
     ********************************************************************************
     * @brief      Gets a configuration key as string.
     *
     * @param[in]  keyword          The name of the key
     * @throws     ModuleException  If key does not exist in mconfig.ini
     * @retval     The value as string
     *******************************************************************************/
    std::string getConfigAsString(std::string keyword);

    /**
     ********************************************************************************
     * @brief      Gets a configuration key as string.
     *
     * @param[in]  group            The name of group where key exists
     * @param[in]  keyword          The name of the key
     * @throws     ModuleException  If key does not exist in mconfig.ini
     * @retval     The value as string
     *******************************************************************************/
    std::string getConfigAsString(std::string group, std::string keyword);

    /**
     ********************************************************************************
     * @brief      Gets a configuration key as string.
     *
     * @param[in]  group            The name of group where key exists
     * @param[in]  set              The name of set when key exist
     * @param[in]  unit             The name of unit when key exist
     * @param[in]  keyword          The name of the key
     * @throws     ModuleException  If key does not exist in mconfig.ini
     * @retval     The value as string
     *******************************************************************************/
    std::string getConfigAsString(std::string group, std::string set, std::string unit,
            std::string keyword);

    /**
     ********************************************************************************
     * @brief      Gets a configuration key as boolean
     *
     * @param[in]  group            The name of group where key exists
     * @param[in]  keyword          The name of the key
     * @throws     ModuleException  If key does not exist in mconfig.ini
     * @retval     The value as boolean
     *******************************************************************************/
    bool getConfigAsBool(std::string group, std::string keyword);

    /**
     ********************************************************************************
     * @brief      Gets a configuration key as boolean
     *
     * @param[in]  group            The name of group where key exists
     * @param[in]  set              The name of set when key exist
     * @param[in]  unit             The name of unit when key exist
     * @param[in]  keyword          The name of the key
     * @throws     ModuleException  If key does not exist in mconfig.ini
     * @retval     The value as boolean
     *******************************************************************************/
    bool getConfigAsBool(std::string group, std::string set, std::string unit, std::string keyword);

private:
    VOID validateResult(const SINT32 lineNbr);
    SINT32 createMissingLine(UINT8 * Section, UINT8 * Group, UINT8 * Keyword, UINT8 * Value);

    std::string m_Section;
    std::string m_Group;
    std::string m_FileName;
    std::string m_ValueName;
    UINT32 m_Precision;
    UINT32 m_LineNumber;
};


#endif /* RES_BEFC_MODULE_SYSCONFIGURATION_HPP_ */
