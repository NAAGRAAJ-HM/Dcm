/******************************************************************************/
/* File   : infSwcServiceDcmSwcServicePduR_eCopyPduTx.c                       */
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

#if(CfgSwcServiceDcm_fProcessingParallel != CfgSwcServiceDcm_dbDisable)
#include "LibAutosar_FindElementInArray.h"
#endif

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
static boolean lbCheckEnvironment_CopyPduTx(
            Type_tIdPdu     ltIdPdu
   ,  const Type_stInfoPdu* lptrcstInfoPdu
){
   boolean lbValueReturnStatusEnvironment = FALSE;
   if(
         ltIdPdu
      >= CfgSwcServiceDcmDsld_NumIdPduTx
   ){
      (void)Det_ReportError(
            DCM_MODULE_ID
         ,  DCM_INSTANCE_ID
         ,  DCM_COPYTXDATA_ID
         ,  DCM_E_DCMTXPDUID_RANGE_EXCEED
      );
   }
   else if(lptrcstInfoPdu == NULL_PTR){
      (void)Det_ReportError(
            DCM_MODULE_ID
         ,  DCM_INSTANCE_ID
         ,  DCM_COPYTXDATA_ID
         ,  DCM_E_PARAM_POINTER
      );
   }
   else if(
         (lptrcstInfoPdu->tLengthSdu  != 0u)
      && (lptrcstInfoPdu->ptru8DataSdu == NULL_PTR)
   ){
      (void)Det_ReportError(
            DCM_MODULE_ID
         ,  DCM_INSTANCE_ID
         ,  DCM_COPYTXDATA_ID
         ,  DCM_E_PARAM_POINTER
      );
   }
   else{
      lbValueReturnStatusEnvironment = TRUE;
   }
   return lbValueReturnStatusEnvironment;
}

#if(CfgSwcServiceDcm_fProcessingParallel != CfgSwcServiceDcm_dbDisable)
static boolean lbIsIdPduTxObd(
   Type_tIdPdu ltIdPdu
){
   return(
      (
            0
         <  LibAutosar_u16FindElementInArray(
                 &CfgSwcServiceDcmDsld_aIdPduTxObd[0]
               ,  CfgSwcServiceDcmDsld_u8NumIdPduTxObd
               ,  ltIdPdu
            )
      )
      ?  TRUE
      :  FALSE
   );
}

#include "PBcfgSwcServiceDcm.h"
#define DCM_NEGRESPONSE_INDICATOR                                          0x7Fu
#define DCM_E_BUSYREPEATREQUEST                                            0x21u
#define DCM_NEGATIVE_RESPONSE_LENGTH                                       0x03u
typedef enum{
      DCM_DSLD_POS_RESPONSE
   ,  DCM_DSLD_NEG_RESPONSE
}Type_SwcServiceDcmDsld_eTypeResponse;

typedef struct{
   Type_tIdPdu                          tIdPduRxActive;
   uint8                                u8NumConnectionActive;
   uint8                                u8IndexProtocolCurrent;
   Type_tIdPdu                          tIdPduTxActive;
   uint8                                u8TableServiceActive;
   boolean                              bIsCommunicationActive;
   uint8                                u8CounterPendingWait;
   Type_SwcServiceDcmDsld_eTypeResponse eTypeResponse;
   Std_ReturnType                       u8Result;
   uint8                                u8IndexService;
   boolean                              bIsResponseByDsd;
   uint8                                u8IdService;
   Type_tLengthPdu                      tLengthPduRequest;
   Type_tIdPdu                          tIdPduTxOld;
   Type_SwcServiceDcmDsld_tMessage      tMessageTxActive;
   uint32                               u32TimeoutMonitor;
}Type_SwcServiceDcmDsld_stInternalObd;

Type_SwcServiceDcmDsld_stInternalObd SwcServiceDcmDsld_stInternalObd;
Type_stInfoPdu                       SwcServiceDcmDsld_stInfoPduObd;
static boolean bIsNrc21ResponseSetObd;
static BufReq_ReturnType    leCopyPduTxObd(
            Type_tIdPdu     ltIdPdu
   ,  const Type_stInfoPdu* lptrcstInfoPdu
){
   BufReq_ReturnType leValueReturnStatusRequestBuffer = BUFREQ_E_NOT_OK;
   Type_stInfoPdu    lstInfoPdu;
   uint8             lau8Nrc[3];
   uint8             u8IdService = 0u;

   bIsNrc21ResponseSetObd = FALSE;
   if(
         (
               CfgSwcServiceDcmDsld_cst.ptrctTableIdPduTx[ltIdPdu]
            == SwcServiceDcmDsld_stInternalObd.tIdPduTxActive
         )
   ){
      lptrcstInfoPdu                   = &SwcServiceDcmDsld_stInfoPduObd;
      leValueReturnStatusRequestBuffer = BUFREQ_OK;
   }
   else{
         bIsNrc21ResponseSetObd           = TRUE;
         leValueReturnStatusRequestBuffer = BUFREQ_OK;
         lau8Nrc[0]                       = DCM_NEGRESPONSE_INDICATOR;
         lau8Nrc[1]                       = u8IdService;
         lau8Nrc[2]                       = DCM_E_BUSYREPEATREQUEST;
         lstInfoPdu.tLengthSdu            = DCM_NEGATIVE_RESPONSE_LENGTH;
         lstInfoPdu.ptru8DataSdu          = &lau8Nrc[0];
         lptrcstInfoPdu                   = &lstInfoPdu;
   }
   return leValueReturnStatusRequestBuffer;
}
#endif

FUNC(BufReq_ReturnType, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServicePduR_eCopyPduTx(
            Type_tIdPdu      ltIdPdu
   ,  const Type_stInfoPdu*  lptrcstInfoPdu
   ,        RetryInfoType*   retry
   ,        Type_tLengthPdu* lptrtLengthPdu
){
   BufReq_ReturnType leValueReturnStatusRequestBuffer = BUFREQ_E_NOT_OK;
   UNUSED(retry);
   UNUSED(lptrtLengthPdu);
   if(
         FALSE
      != lbCheckEnvironment_CopyPduTx(
               ltIdPdu
            ,  lptrcstInfoPdu
         )
   ){
#if(CfgSwcServiceDcm_fProcessingParallel != CfgSwcServiceDcm_dbDisable)
      if(lbIsIdPduTxObd(ltIdPdu)){
         leValueReturnStatusRequestBuffer = leCopyPduTxObd(
               ltIdPdu
            ,  lptrcstInfoPduTemp
         );
         lbIsNrc21ResponseSet = bIsNrc21ResponseSetObd;
      }
      else
#endif
      {
      }
   }
   return leValueReturnStatusRequestBuffer;
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

