/******************************************************************************/
/* File   : infSwcServiceDcmSwcServicePduR_eCopyPduRx.c                       */
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

#include "infSwcApplDcmSwcServiceDcm.h"
#include "infSwcServiceDcmSwcServiceComM.h"
#include "infSwcServiceDetSwcServiceDcm.h"
#include "infSwcServiceDcmSwcServiceEcuM.h"
#if(CfgSwcServiceDcm_fProcessingParallel != CfgSwcServiceDcm_dbDisable)
#include "LibAutosar_FindElementInArray.h"
#endif
#include "LibAutosar_MemCopy.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define SwcServiceDcmDsld_dIdServiceValueDefault                         (0xFFu)
#define SwcServiceDcmDsld_vMemCopy(ptrvDestination,ptrcvSource,u32NumByte) (void)LibAutosar_ptrvMemCopy((ptrvDestination),(ptrcvSource),(uint32)(u32NumByte))

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/


/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
const uint8*                             SwcServiceDcmDsld_pcu8TableRx;
const Type_SwcServiceDcmDsld_stProtocol* SwcServiceDcmDsld_pcstProtocol;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
static boolean lbCheckEnvironment_CopyPduRx(
            Type_tIdPdu      ltIdPdu
   ,  const Type_stInfoPdu*  lptrcstInfoPdu
   ,  const Type_tLengthPdu* lptrtLengthPdu
){
   boolean lbValueReturnStatusEnvironment = FALSE;
   if(
         ltIdPdu
      >= CfgSwcServiceDcmDsld_NumIdPduRx
   ){
      (void)Det_ReportError(
            DCM_MODULE_ID
         ,  DCM_INSTANCE_ID
         ,  DCM_COPYRXDATA_ID
         ,  DCM_E_DCMRXPDUID_RANGE_EXCEED
      );
   }
   else if(
         (lptrcstInfoPdu == NULL_PTR)
      || (lptrtLengthPdu == NULL_PTR)
   ){
      (void)Det_ReportError(
            DCM_MODULE_ID
         ,  DCM_INSTANCE_ID
         ,  DCM_COPYRXDATA_ID
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
         ,  DCM_COPYRXDATA_ID
         ,  DCM_E_PARAM_POINTER
      );
   }
   else{
      lbValueReturnStatusEnvironment = TRUE;
   }
   return lbValueReturnStatusEnvironment;
}

static boolean lbIsReceivedRequestPriorityLow(Type_tIdPdu ltIdPdu){
   return(
         SwcServiceDcmDsld_pcstProtocol[
            SwcServiceDcmDsld_ptrcstTableConnection[
               SwcServiceDcmDsld_pcu8TableRx[ltIdPdu]
            ].u8NumProtocol
         ].bNrc21
      && SwcServiceDcmDsld_bIsModeComMChannelFull(
            SwcServiceDcmDsld_ptrcstTableConnection[
               SwcServiceDcmDsld_pcu8TableRx[ltIdPdu]
            ].u8IndexChannel
         )
   );
}

#if(CfgSwcServiceDcm_fSharingPduRx != CfgSwcServiceDcm_dbDisable)
extern boolean SwcServiceDcmDsl_bIsRequestReceivedObd;
static boolean lbIsPduRxShared(
      Type_tIdPdu ltIdPdu
   ,  uint8     lu8IdService
){
   return(
         (ltIdPdu      < (CfgSwcServiceDcmDsld_NumIdPduRx-1u))
      && (ltIdPdu      == CfgSwcServiceDcmDsld_IdPduRxShared)
      && (lu8IdService >= CfgSwcServiceDcmDsld_IdServiceObd_0x01)
      && (lu8IdService <= CfgSwcServiceDcmDsld_IdServiceObd_0x0A)
   );
}
#endif

#if(CfgSwcServiceDcm_fProcessingParallel != CfgSwcServiceDcm_dbDisable)
#include "LibAutosar_FindElementInArray.h"
static boolean lbIsIdPduRxObd(
   Type_tIdPdu ltIdPdu
){
   return(
      (
            0
         <  LibAutosar_u16FindElementInArray(
                  &CfgSwcServiceDcmDsld_aIdPduRxObd[0]
               ,  CfgSwcServiceDcmDsld_u8NumIdPduRxObd
               ,  ltIdPdu
            )
      )
      ?  TRUE
      :  FALSE
   );
}

Type_SwcServiceDcmDsld_stInfoPduRxObd SwcServiceDcmDsld_astPduRxObd[CfgSwcServiceDcmDsld_NumIdPduRx];
static void lvGetLengthPduRxObd(
      Type_tIdPdu      ltIdPdu
   ,  Type_tLengthPdu* lptrtLengthPdu
){
   uint8 lu8IndexProtocol;
   if(FALSE !=  SwcServiceDcmDsld_astPduRxObd[ltIdPdu].bPduCopy){
      *(lptrtLengthPdu) = SwcServiceDcmDsld_astPduRxObd[ltIdPdu].stInfoPdu.tLengthSdu;
   }
   else{
      lu8IndexProtocol  = SwcServiceDcmDsld_ptrcstTableConnection[SwcServiceDcmDsld_pcu8TableRx[ltIdPdu]].u8NumProtocol;
      *(lptrtLengthPdu) = (Type_tLengthPdu)(SwcServiceDcmDsld_pcstProtocol[lu8IndexProtocol].tLengthMessageRx);
   }
}

static void lvCopyPduRxObd(
            Type_tIdPdu      ltIdPdu
   ,  const Type_stInfoPdu*  lptrcstInfoPdu
   ,        Type_tLengthPdu* lptrtLengthPdu
){
   SwcServiceDcmDsld_vMemCopy(
         SwcServiceDcmDsld_astPduRxObd[ltIdPdu].stInfoPdu.ptru8DataSdu
      ,  lptrcstInfoPdu->ptru8DataSdu
      ,  lptrcstInfoPdu->tLengthSdu
   );
   SwcServiceDcmDsld_astPduRxObd[ltIdPdu].stInfoPdu.ptru8DataSdu += lptrcstInfoPdu->tLengthSdu;
   SwcServiceDcmDsld_astPduRxObd[ltIdPdu].stInfoPdu.tLengthSdu  -= lptrcstInfoPdu->tLengthSdu;
#if(CfgSwcServiceDcmDsld_fCallApplRxRequest != CfgSwcServiceDcm_dbDisable)
   (void)infSwcApplDcmSwcServiceDcm_vCopyPduRx(
         ltIdPdu
      ,  lptrcstInfoPdu->tLengthSdu
   );
#endif
   *(lptrtLengthPdu) = SwcServiceDcmDsld_astPduRxObd[ltIdPdu].stInfoPdu.tLengthSdu;
}

static BufReq_ReturnType leCheckPduRxObd(
            Type_tIdPdu      ltIdPdu
   ,  const Type_stInfoPdu*  lptrcstInfoPdu
   ,        Type_tLengthPdu* lptrtLengthPdu
){
   BufReq_ReturnType leValueReturnStatusRequestBuffer = BUFREQ_E_NOT_OK;
   if(
         FALSE
      != SwcServiceDcmDsld_astPduRxObd[ltIdPdu].bPduCopy
   ){
      lvCopyPduRxObd(
            ltIdPdu
         ,  lptrcstInfoPdu
         ,  lptrtLengthPdu
      );
      leValueReturnStatusRequestBuffer = BUFREQ_OK;
   }
   else{
      if(
            FALSE
         != lbIsReceivedRequestPriorityLow(ltIdPdu)
      ){
         if(
               SwcServiceDcmDsld_dIdServiceValueDefault
            == SwcServiceDcmDsld_astPduRxObd[ltIdPdu].u8IdService
         ){
            SwcServiceDcmDsld_astPduRxObd[ltIdPdu].u8IdService = (uint8)lptrcstInfoPdu->ptru8DataSdu[0];
         }
         leValueReturnStatusRequestBuffer = BUFREQ_OK;
      }
   }
   return leValueReturnStatusRequestBuffer;
}

static BufReq_ReturnType leCopyPduRxObd(
            Type_tIdPdu      ltIdPdu
   ,  const Type_stInfoPdu*  lptrcstInfoPdu
   ,        Type_tLengthPdu* lptrtLengthPdu
){
   BufReq_ReturnType leValueReturnStatusRequestBuffer = BUFREQ_E_NOT_OK;
   if(
         0u
      == lptrcstInfoPdu->tLengthSdu
   ){
      lvGetLengthPduRxObd(
            ltIdPdu
         ,  lptrtLengthPdu
      );
      leValueReturnStatusRequestBuffer = BUFREQ_OK;
   }
   else{
      if(
            (
                  lptrcstInfoPdu->tLengthSdu
               <= SwcServiceDcmDsld_astPduRxObd[ltIdPdu].stInfoPdu.tLengthSdu
            )
         || (lbIsReceivedRequestPriorityLow(ltIdPdu))
      ){
         leValueReturnStatusRequestBuffer = leCheckPduRxObd(
               ltIdPdu
            ,  lptrcstInfoPdu
            ,  lptrtLengthPdu
         );
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
   return leValueReturnStatusRequestBuffer;
}
#endif

Type_SwcServiceDcmDsld_stPduRxElement SwcServiceDcmDsld_astTablePduRx[CfgSwcServiceDcmDsld_NumIdPduRx];

static void lvUpdateLengthPdu(
      Type_tIdPdu      ltIdPdu
   ,  Type_tLengthPdu* lptrtLengthPdu
){
   uint8 idxProtocol_u8 = SwcServiceDcmDsld_ptrcstTableConnection[SwcServiceDcmDsld_pcu8TableRx[ltIdPdu]].u8NumProtocol;
   if(
         FALSE
      != SwcServiceDcmDsld_astTablePduRx[ltIdPdu].bPduCopy
   ){   *(lptrtLengthPdu) = SwcServiceDcmDsld_astTablePduRx[ltIdPdu].stInfoPdu.tLengthSdu;}
   else{*(lptrtLengthPdu) = (Type_tLengthPdu)(SwcServiceDcmDsld_pcstProtocol[idxProtocol_u8].tLengthMessageRx);}
}

static boolean lIsReceivedRequestPresentTesterFunctional(
   Type_tIdPdu ltIdPdu
){
   return(
          (SwcServiceDcmDsld_astTablePduRx[ltIdPdu].bPresentTester)
      && !(SwcServiceDcmDsld_astTablePduRx[ltIdPdu].bPduCopy)
   );
}

static boolean lbIsReceivedRequestValid(
   Type_tIdPdu ltIdPdu
){
   return(
      SwcServiceDcmDsld_astTablePduRx[ltIdPdu].bPduCopy
   );
}

#if(CfgSwcServiceDcm_fQueueBuffer != CfgSwcServiceDcm_dbDisable)
typedef enum{
      SwcServiceDcmDsld_eStatusQueueIdle
   ,  SwcServiceDcmDsld_eStatusQueueRunning
   ,  SwcServiceDcmDsld_eStatusQueueCompleted
}Type_SwcServiceDcmDsld_eStatusQueue;

typedef struct{
   Type_SwcServiceDcmDsld_eStatusQueue eStatus;
   Type_SwcServiceDcmDsld_tMessage     tMessage;
   Type_tLengthPdu                     tLengthPdu;
   Type_tIdPdu                         tIdPdu;
   uint8                               u8IndexBuffer;
}Type_SwcServiceDcmDsld_stQueue;

Type_SwcServiceDcmDsld_stQueue SwcServiceDcmDsld_stQueue;
#endif
static void lvCopyPduRx(
            Type_tIdPdu      ltIdPdu
   ,  const Type_stInfoPdu*  lptrcstInfoPdu
   ,        Type_tLengthPdu* lptrtLengthPdu
){
   SwcServiceDcmDsld_vMemCopy(
         SwcServiceDcmDsld_astTablePduRx[ltIdPdu].stInfoPdu.ptru8DataSdu
      ,  lptrcstInfoPdu->ptru8DataSdu
      ,  lptrcstInfoPdu->tLengthSdu
   );
   SwcServiceDcmDsld_astTablePduRx[ltIdPdu].stInfoPdu.ptru8DataSdu += lptrcstInfoPdu->tLengthSdu;
   SwcServiceDcmDsld_astTablePduRx[ltIdPdu].stInfoPdu.tLengthSdu  -= lptrcstInfoPdu->tLengthSdu;
#if(CfgSwcServiceDcmDsld_fCallApplRxRequest != CfgSwcServiceDcm_dbDisable)
#if(CfgSwcServiceDcm_fQueueBuffer != CfgSwcServiceDcm_dbDisable)
   if(SwcServiceDcmDsld_stQueue.eStatus == SwcServiceDcmDsld_eStatusQueueIdle)
#endif
   {
      (void)infSwcApplDcmSwcServiceDcm_vCopyPduRx(
            ltIdPdu
         ,  lptrcstInfoPdu->tLengthSdu
      );
   }
#endif
   *(lptrtLengthPdu) = SwcServiceDcmDsld_astTablePduRx[ltIdPdu].stInfoPdu.tLengthSdu;
}

static BufReq_ReturnType leCopyPduRx(
            Type_tIdPdu      ltIdPdu
   ,  const Type_stInfoPdu*  lptrcstInfoPdu
   ,        Type_tLengthPdu* lptrtLengthPdu
){
   BufReq_ReturnType leValueReturnStatusRequestBuffer = BUFREQ_E_NOT_OK;
   if(
         FALSE
      != lbIsReceivedRequestValid(ltIdPdu)
   ){
      lvCopyPduRx(
            ltIdPdu
         ,  lptrcstInfoPdu
         ,  lptrtLengthPdu
      );
      leValueReturnStatusRequestBuffer = BUFREQ_OK;
   }
   else{
      if(
            FALSE
         != lbIsReceivedRequestPriorityLow(ltIdPdu)
      ){
         if(
               SwcServiceDcmDsld_astTablePduRx[ltIdPdu].u8IdService
            == SwcServiceDcmDsld_dIdServiceValueDefault
         ){
            SwcServiceDcmDsld_astTablePduRx[ltIdPdu].u8IdService = (uint8)lptrcstInfoPdu->ptru8DataSdu[0];
         }
         leValueReturnStatusRequestBuffer = BUFREQ_OK;
      }
   }
   return leValueReturnStatusRequestBuffer;
}

FUNC(BufReq_ReturnType, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServicePduR_eCopyPduRx(
            Type_tIdPdu      ltIdPdu
   ,  const Type_stInfoPdu*  lptrcstInfoPdu
   ,        Type_tLengthPdu* lptrtLengthPdu
){
   BufReq_ReturnType leValueReturnStatusRequestBuffer = BUFREQ_E_NOT_OK;
   if(
         FALSE
      != lbCheckEnvironment_CopyPduRx(
               ltIdPdu
            ,  lptrcstInfoPdu
            ,  lptrtLengthPdu
         )
   ){
#if(CfgSwcServiceDcm_fSharingPduRx != CfgSwcServiceDcm_dbDisable)
      if(
            (NULL_PTR != lptrcstInfoPdu->ptru8DataSdu)
         && (FALSE    != SwcServiceDcmDsl_bIsRequestReceivedObd)
      ){
         if(
               FALSE
            != lbIsPduRxShared(
                     ltIdPdu
                  ,  lptrcstInfoPdu->ptru8DataSdu[0]
               )
         ){
            ltIdPdu = (CfgSwcServiceDcmDsld_NumIdPduRx-1u);
         }
      }
#endif
#if(CfgSwcServiceDcm_fProcessingParallel != CfgSwcServiceDcm_dbDisable)
      if(lbIsIdPduRxObd(ltIdPdu)){
         leValueReturnStatusRequestBuffer = leCopyPduRxObd(
               ltIdPdu
            ,  lptrcstInfoPdu
            ,  lptrtLengthPdu
         );
      }
      else
#endif
      {
         if(lptrcstInfoPdu->tLengthSdu == 0u){
            lvUpdateLengthPdu(
                  ltIdPdu
               ,  lptrtLengthPdu
            );
            leValueReturnStatusRequestBuffer = BUFREQ_OK;
         }
         else if(
               FALSE
            != lIsReceivedRequestPresentTesterFunctional(ltIdPdu)
         ){
            leValueReturnStatusRequestBuffer = BUFREQ_OK;
         }
         else{
            if(
                  (
                        lptrcstInfoPdu->tLengthSdu
                     <= SwcServiceDcmDsld_astTablePduRx[ltIdPdu].stInfoPdu.tLengthSdu
                  )
               || (FALSE != lbIsReceivedRequestPriorityLow(ltIdPdu))
            ){
               leValueReturnStatusRequestBuffer = leCopyPduRx(
                     ltIdPdu
                  ,  lptrcstInfoPdu
                  ,  lptrtLengthPdu
               );
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
   }
   return leValueReturnStatusRequestBuffer;
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
