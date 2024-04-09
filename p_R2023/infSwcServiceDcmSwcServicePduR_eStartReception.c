/******************************************************************************/
/* File   : infSwcServiceDcmSwcServicePduR_eStartReception.c                  */
/*                                                                            */
/* Author : Nagaraja HULIYAPURADA MATA                                        */
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
/* All rights reserved. Copyright � 1982 Nagaraja HULIYAPURADA MATA           */
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
#include "Types_StackCom.h"
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
FUNC(Type_StackCom_eResultBufferRequest, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServicePduR_eStartReception(
            Type_tIdPdu              id
   ,  const Type_StackCom_stInfoPdu* info
   ,        Type_tLengthPdu          TptLengthSdu
   ,        Type_tLengthPdu*         bufferSizePtr
){
   Type_StackCom_eResultBufferRequest leValueReturnStatusRequestBuffer = eResultBufferRequest_Nok;
   UNUSED(id);
   UNUSED(info);
   UNUSED(TptLengthSdu);
   UNUSED(bufferSizePtr);
   return leValueReturnStatusRequestBuffer;
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

