/******************************************************************************/
/* File   : infSwcServiceDcmSwcServicePduR_eStartReception.c                  */
/*                                                                            */
/* Author : Raajnaag HULIYAPURADA MATA                                        */
/*                                                                            */
/* License / Warranty / Terms and Conditions                                  */
/*                                                                            */
/* Everyone is permitted to copy and distribute verbatim copies of this lice- */
/* nse document, but changing it is not allowed. This is a free, copyright l- */
/* icense for software and other kinds of works. By contrast, this license is */
/* intended to guarantee your freedom to share and change all versions of a   */
/* program, to make sure it remains free software for all its users. You have */
/* certain responsibilities, if you distribute copies of the software, or if  */
/* you modify it: responsibilities to respect the freedom of others.          */
/*                                                                            */
/* All rights reserved. Copyright � 1982 Raajnaag HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* git@github.com:RaajnaagHuliyapuradaMata/<module_name>.git                  */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.h"
#include "CfgSwcServiceDcm.h"
#include "ComStack_Types.h"
#include "infSwcServiceDcmSwcServicePduR.h"

#include "infSwcServiceDcmSwcServiceComM.h"
#include "infSwcServiceDcmSwcServiceEcuM.h"
#include "infSwcServiceDetSwcServiceDcm.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/


/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(BufReq_ReturnType, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServicePduR_eStartReception(
            PduIdType      id
   ,  const PduInfoType*   info
   ,        PduLengthType  TpSduLength
   ,        PduLengthType* bufferSizePtr
){
   BufReq_ReturnType leValueReturnStatusRequestBuffer = BUFREQ_E_NOT_OK;
   UNUSED(id);
   UNUSED(info);
   UNUSED(TpSduLength);
   UNUSED(bufferSizePtr);
   return leValueReturnStatusRequestBuffer;
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

