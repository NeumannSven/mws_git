/**
 ********************************************************************************
 * @file     SviItem.hpp
 * @author   madsen
 * @version  $Revision: 000 $
 * @date     $LastChangeDate: Feb 12, 2013 9:50:58 AM 11:00:00 $
 *
 * @brief    Implementation of SviItem
 *
 ********************************************************************************
 * COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2015
 *******************************************************************************/

/** Avoid problems with multiple inclusion */
#ifndef SVIITEM_HPP_
#define SVIITEM_HPP_

#include "AbstractSviItem.hpp"
#include "value/SviValue.hpp"

/**
 * @addtogroup SVI
 * @{
 */

class SviItem: public AbstractSviItem
{
public:

    /**
     ********************************************************************************
     * @brief      Gets the current value
     *
     * @retval     The current value as SviValue type
     *******************************************************************************/
    virtual SviValue* getValue() = 0;

    /**
     ********************************************************************************
     * @brief      Sets the current value
     *
     * @param[in]  pValue   The new value
     *******************************************************************************/
    virtual VOID setValue(SviValue *pValue) = 0;

    /**
     ********************************************************************************
     * @brief      Operator overload for comparing SviItems
     *
     * @retval     True if other has same moduleName and varName
     *******************************************************************************/
    bool operator==(const SviItem &other) const;

    /**
     ********************************************************************************
     * @brief      Conversion of svi data type to readable text
     *
     * @retval     SVI type in text
     *******************************************************************************/
    std::string getTypeAsText(UINT32 datatype)
    {
        switch (datatype & SVI_F_SUBTYPEMSK)
        {
            case SVI_F_UNKNOWN:
                return SVI_ITEM_TEXT_UNKNOWN;
            case SVI_F_UINT1:
                return SVI_ITEM_TEXT_UINT1;
            case SVI_F_UINT8:
                return SVI_ITEM_TEXT_UINT8;
            case SVI_F_SINT8:
                return SVI_ITEM_TEXT_SINT8;
            case SVI_F_UINT16:
                return SVI_ITEM_TEXT_UINT16;
            case SVI_F_SINT16:
                return SVI_ITEM_TEXT_SINT16;
            case SVI_F_UINT32:
                return SVI_ITEM_TEXT_UINT32;
            case SVI_F_SINT32:
                return SVI_ITEM_TEXT_SINT32;
            case SVI_F_UINT64:
                return SVI_ITEM_TEXT_UINT64;
            case SVI_F_SINT64:
                return SVI_ITEM_TEXT_SINT64;
            case SVI_F_REAL32:
                return SVI_ITEM_TEXT_REAL32;
            case SVI_F_REAL64:
                return SVI_ITEM_TEXT_REAL64;
            case SVI_F_BOOL8:
                return SVI_ITEM_TEXT_BOOL8;
            case SVI_F_CHAR8:
                return SVI_ITEM_TEXT_CHAR8;
            case SVI_F_MIXED:
                return SVI_ITEM_TEXT_MIXED;
            case SVI_F_CHAR16:
                return SVI_ITEM_TEXT_CHAR16;
            case SVI_F_STRINGLSTBASE:
                return SVI_ITEM_TEXT_STRINGLSTBASE;
            case SVI_F_USTRINGLSTBASE:
                return SVI_ITEM_TEXT_USTRINGLSTBASE;

            default:
                // else unknown
                std::stringstream ss;
                ss << datatype;
                return ss.str();
        }
    }

    static const std::string SVI_ITEM_TEXT_UNKNOWN;
    static const std::string SVI_ITEM_TEXT_UINT1;
    static const std::string SVI_ITEM_TEXT_UINT8;
    static const std::string SVI_ITEM_TEXT_UINT16;
    static const std::string SVI_ITEM_TEXT_UINT32;
    static const std::string SVI_ITEM_TEXT_UINT64;
    static const std::string SVI_ITEM_TEXT_SINT1;
    static const std::string SVI_ITEM_TEXT_SINT8;
    static const std::string SVI_ITEM_TEXT_SINT16;
    static const std::string SVI_ITEM_TEXT_SINT32;
    static const std::string SVI_ITEM_TEXT_SINT64;
    static const std::string SVI_ITEM_TEXT_BOOL8;
    static const std::string SVI_ITEM_TEXT_REAL32;
    static const std::string SVI_ITEM_TEXT_REAL64;
    static const std::string SVI_ITEM_TEXT_CHAR8;
    static const std::string SVI_ITEM_TEXT_CHAR16;
    static const std::string SVI_ITEM_TEXT_MIXED;
    static const std::string SVI_ITEM_TEXT_STRINGLSTBASE;
    static const std::string SVI_ITEM_TEXT_USTRINGLSTBASE;
};
/** @} */

#endif  /*SVIITEM_HPP_*/
