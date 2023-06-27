/******************************************************************************/
/* File   : infSwcServiceDcmSwcServicePduR_Dsl.c                              */
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
#include "ComStack_Cfg.h"   //TBD: Move header
#include "ComStack_Types.h" //TBD: Move header
#include "infSwcServiceDcmSwcServicePduR.h"

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
extern boolean Dcm_isObdRequestReceived_b;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
static boolean bCheckEnvironment_CopyRxData(
            PduIdType      lIdPdu
   ,  const PduInfoType*   lptrInfoPdu
   ,  const PduLengthType* lptrLengthPdu
){
   boolean bStatusEnvironment = FALSE;
   if(
         lIdPdu
      >= CfgSwcServiceDcmDsld_NnmPduIdRx
   ){
      (void)Det_ReportError(
            DCM_MODULE_ID
         ,  DCM_INSTANCE_ID
         ,  DCM_COPYRXDATA_ID
         ,  DCM_E_DCMRXPDUID_RANGE_EXCEED
      );
   }
   else if(
         (lptrInfoPdu   == NULL_PTR)
      || (lptrLengthPdu == NULL_PTR)
   ){
      (void)Det_ReportError(
            DCM_MODULE_ID
         ,  DCM_INSTANCE_ID
         ,  DCM_COPYRXDATA_ID
         ,  DCM_E_PARAM_POINTER
      );
   }
   else if(
         (lptrInfoPdu->SduLength  != 0u)
      && (lptrInfoPdu->SduDataPtr == NULL_PTR)
   ){
      (void)Det_ReportError(
            DCM_MODULE_ID
         ,  DCM_INSTANCE_ID
         ,  DCM_COPYRXDATA_ID
         ,  DCM_E_PARAM_POINTER
      );
   }
   else{
      bStatusEnvironment = TRUE;
   }
   return bStatusEnvironment;
}

#if(CfgSwcServiceDcm_EnableSharingPduRx != DCM_CFG_OFF)
static boolean Dcm_Prv_isRxPduShared(
      PduIdType lIdPdu
   ,  uint8     lu8IdService
){
   return(
         (lIdPdu        < (CfgSwcServiceDcmDsld_NnmPduIdRx-1u))
   );
}
#endif

#if(CfgSwcServiceDcm_EnableProcessingParallel != DCM_CFG_OFF)
boolean Dcm_Prv_IsRxPduIdOBD(
   PduIdType DcmRxPduId
){
   boolean IsRxPduIdObd_b = FALSE;
   return IsRxPduIdObd_b;
}

boolean Dcm_Prv_IsTxPduIdOBD(
   PduIdType DcmTxPduId
){
   boolean IsTxPduIdObd_b = FALSE;
   return IsTxPduIdObd_b;
}
#endif

FUNC(BufReq_ReturnType, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServicePduR_CopyRxData(
            PduIdType      lIdPdu
   ,  const PduInfoType*   lptrInfoPdu
   ,        PduLengthType* lptrLengthPdu
){
   BufReq_ReturnType leRetValReqBuf = BUFREQ_E_NOT_OK;
   if(
         FALSE
      != bCheckEnvironment_CopyRxData(
               lIdPdu
            ,  lptrInfoPdu
            ,  lptrLengthPdu
         )
   ){
#if(CfgSwcServiceDcm_EnableSharingPduRx != DCM_CFG_OFF)
      if(
            (NULL_PTR != lptrInfoPdu->SduDataPtr)
         && (FALSE    != Dcm_isObdRequestReceived_b)
      ){
         if(
               FALSE
            != Dcm_Prv_isRxPduShared(
                     lIdPdu
                  ,  lptrInfoPdu->SduDataPtr[0]
               )
         ){
            lIdPdu = (CfgSwcServiceDcmDsld_NnmPduIdRx-1u);
         }
      }
#endif
      {
         if(lptrInfoPdu->SduLength == 0u){
            leRetValReqBuf = BUFREQ_OK;
         }
         else{
               (void)Det_ReportError(
                        DCM_MODULE_ID
                     ,  DCM_INSTANCE_ID
                     ,  DCM_COPYRXDATA_ID
                     ,  DCM_E_INTERFACE_BUFFER_OVERFLOW
               );
         }
      }
   }
   return leRetValReqBuf;
}

FUNC(BufReq_ReturnType, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServicePduR_CopyTxData(
            PduIdType      id
   ,  const PduInfoType*   info
   ,        RetryInfoType* retry
   ,        PduLengthType* availableDataPtr
){
   BufReq_ReturnType bufRequestStatus_en = BUFREQ_E_NOT_OK;
   return bufRequestStatus_en;
}

FUNC(BufReq_ReturnType, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServicePduR_StartOfReception(
            PduIdType      id
   ,  const PduInfoType*   info
   ,        PduLengthType  TpSduLength
   ,        PduLengthType* bufferSizePtr
){
   BufReq_ReturnType bufRequestStatus_en = BUFREQ_E_NOT_OK;
   return bufRequestStatus_en;
}

FUNC(void, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServicePduR_vTpRxIndication(
      PduIdType      id
   ,  Std_ReturnType result
){
}

FUNC(void, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServicePduR_vTpTxConfirmation(
      PduIdType      id
   ,  Std_ReturnType result
){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

