#ifndef _INFSWCSERVICEDCMSWCSERVICEPDUR_H
#define _INFSWCSERVICEDCMSWCSERVICEPDUR_H
/******************************************************************************/
/* File   : infSwcServiceDcmSwcServicePduR.h                                  */
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
/* All rights reserved. Copyright © 1982 Raajnaag HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* git@github.com:RaajnaagHuliyapuradaMata/<module_name>.git                  */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "CompilerCfg_SwcServiceDcm.h"

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
extern FUNC(BufReq_ReturnType, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServicePduR_CopyRxData(
            PduIdType      id
   ,  const PduInfoType*   PduInfoPtr
   ,        PduLengthType* bufferSizePtr
);

extern FUNC(BufReq_ReturnType, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServicePduR_CopyTxData(
            PduIdType      id
   ,  const PduInfoType*   info
   ,        RetryInfoType* retry
   ,        PduLengthType* availableDataPtr
);

extern FUNC(BufReq_ReturnType, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServicePduR_StartOfReception(
            PduIdType      id
   ,  const PduInfoType*   info
   ,        PduLengthType  TpSduLength
   ,        PduLengthType* bufferSizePtr
);

extern FUNC(void, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServicePduR_vTpRxIndication(
      PduIdType      id
   ,  Std_ReturnType result
);

extern FUNC(void, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServicePduR_vTpTxConfirmation(
      PduIdType      id
   ,  Std_ReturnType result
);

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
#endif
