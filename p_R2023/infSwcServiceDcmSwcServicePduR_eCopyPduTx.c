/******************************************************************************/
/* File   : infSwcServiceDcmSwcServicePduR_eCopyPduTx.c                       */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
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
extern const Type_SwcServiceDcmDsld_stProtocol* SwcServiceDcmDsld_pcstProtocol;

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
            Type_tIdPdu              ltIdPdu
   ,  const Type_StackCom_stInfoPdu* lptrcstInfoPdu
){
   boolean lbValueReturnStatusEnvironment = FALSE;
   if(
         ltIdPdu
      >= CfgSwcServiceDcmDsld_dNumIdPduTx
   ){
      (void)SwcServiceDet_tReportError(
            SwcServiceDet_eIdModuleSwcServiceDcm
         ,  DCM_INSTANCE_ID
         ,  DCM_COPYTXDATA_ID
         ,  DCM_E_DCMTXPDUID_RANGE_EXCEED
      );
   }
   else if(lptrcstInfoPdu == NULL_PTR){
      (void)SwcServiceDet_tReportError(
            SwcServiceDet_eIdModuleSwcServiceDcm
         ,  DCM_INSTANCE_ID
         ,  DCM_COPYTXDATA_ID
         ,  DCM_E_PARAM_POINTER
      );
   }
   else if(
         (lptrcstInfoPdu->tLengthSdu  != 0u)
      && (lptrcstInfoPdu->ptru8DataSdu == NULL_PTR)
   ){
      (void)SwcServiceDet_tReportError(
            SwcServiceDet_eIdModuleSwcServiceDcm
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

#include "PBcfgSwcServiceDcm.h"
#define DCM_NEGRESPONSE_INDICATOR                                          0x7Fu
#define DCM_E_BUSYREPEATREQUEST                                            0x21u
#define DCM_NEGATIVE_RESPONSE_LENGTH                                       0x03u
typedef enum{
      DCM_DSLD_POS_RESPONSE
   ,  DCM_DSLD_NEG_RESPONSE
}Type_SwcServiceDcmDsld_eTypeResponse;
extern const uint8* SwcServiceDcmDsld_pcu8TableRx;

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

static boolean lbIsNrc21AvailableObd(
      uint8*      lptru8IdService
   ,  Type_tIdPdu ltIdPdu
){
   Type_tIdPdu ltIdPduIndex;
   uint8       lu8IdService;
   uint8       lu8IdConnection;
   uint8       lu8IndexProtocol;
   boolean     lbValueReturn = FALSE;

   for(
      ltIdPduIndex = 0;
      ltIdPduIndex < CfgSwcServiceDcmDsld_dNumIdPduRx;
      ltIdPduIndex ++
   ){
      lu8IdService = SwcServiceDcmDsld_astPduRxObd[ltIdPduIndex].u8IdService;
      if(
            SwcServiceDcmDsld_dIdServiceValueDefault
         != lu8IdService
      ){
        *lptru8IdService  = lu8IdService;
         lu8IdConnection  = SwcServiceDcmDsld_pcu8TableRx[ltIdPduIndex];
         lu8IndexProtocol = SwcServiceDcmDsld_ptrcstTableConnection[lu8IdConnection].u8NumProtocol;

         if(
               (
                     SwcServiceDcmDsld_ptrcstTableConnection[lu8IdConnection].tNumIdPduTx
                  == CfgSwcServiceDcmDsld_cst.ptrctTableIdPduTx[ltIdPdu]
               )
            && (
                     FALSE
                  != SwcServiceDcmDsld_pcstProtocol[lu8IndexProtocol].bNrc21
               )
         ){
            lbValueReturn = TRUE;
            break;
         }
      }
   }
   return lbValueReturn;
}

#define SwcServiceDcmDsld_eGetMachineStateObd() (SwcServiceDcmDsld_eMachineStateObd)
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

typedef enum{
      eMachineStateObd_Idle
   ,  eMachineStateObd_RequestReceiving
   ,  eMachineStateObd_RequestReceived
   ,  eMachineStateObd_DataVerification
   ,  eMachineStateObd_ServiceProcessing
   ,  eMachineStateObd_TxConfirmationWaiting
}Type_SwcServiceDcmDsld_eMachineStateObd;

       Type_SwcServiceDcmDsld_stInternalObd    SwcServiceDcmDsld_stInternalObd;
       Type_StackCom_stInfoPdu                 SwcServiceDcmDsld_stInfoPduObd;
       Type_SwcServiceDcmDsld_eMachineStateObd SwcServiceDcmDsld_eMachineStateObd;
static boolean                                 bIsNrc21ResponseSetObd;

static Type_StackCom_eResultBufferRequest leCopyPduTxObd(
            Type_tIdPdu              ltIdPdu
   ,  const Type_StackCom_stInfoPdu* lptrcstInfoPdu
){
   Type_StackCom_eResultBufferRequest leValueReturn = eResultBufferRequest_Nok;
   Type_StackCom_stInfoPdu            lstInfoPdu;
   uint8                              lau8Nrc[3];
   uint8                              lu8IdService = 0u;

   bIsNrc21ResponseSetObd = FALSE;
   if(
         (
               CfgSwcServiceDcmDsld_cst.ptrctTableIdPduTx[ltIdPdu]
            == SwcServiceDcmDsld_stInternalObd.tIdPduTxActive
         )
      && (
               eMachineStateObd_TxConfirmationWaiting
            == SwcServiceDcmDsld_eGetMachineStateObd()
         )
   ){
      lptrcstInfoPdu = &SwcServiceDcmDsld_stInfoPduObd;
      leValueReturn  = eResultBufferRequest_Ok;
   }
   else{
      if(
            FALSE
         != lbIsNrc21AvailableObd(
                 &lu8IdService
               ,  ltIdPdu
            )
      ){
         bIsNrc21ResponseSetObd  = TRUE;
         leValueReturn           = eResultBufferRequest_Ok;
         lau8Nrc[0]              = DCM_NEGRESPONSE_INDICATOR;
         lau8Nrc[1]              = lu8IdService;
         lau8Nrc[2]              = DCM_E_BUSYREPEATREQUEST;
         lstInfoPdu.tLengthSdu   = DCM_NEGATIVE_RESPONSE_LENGTH;
         lstInfoPdu.ptru8DataSdu = &lau8Nrc[0];
         lptrcstInfoPdu          = &lstInfoPdu;
      }
   }
   return leValueReturn;
}
#endif

typedef struct{
#if(CfgSwcServiceDcm_fQueueBuffer != CfgSwcServiceDcm_dbDisable)
   Type_SwcServiceDcmDsld_tMessage       tMessage;
#endif
   Type_tIdPdu                           tIdPduRxActive;
   uint8                                 u8NumConnectionActive;
   uint8                                 u8IndexSessionActive;
   boolean                               bMonitorTimerP3;
   uint8                                 u8IndexProtocolCurrent;
   Type_tIdPdu                           tIdPduTxActive;
   uint8                                 u8TableServiceActive;
   boolean                               bIsCommunicationActive;
   uint8                                 u8CounterPendingWait;
   Type_SwcServiceDcmDsld_eTypeResponse  eTypeResponse;
   uint8                                 u8IndexSecurityActive;
   Std_ReturnType                        u8Result;
   uint8                                 u8IndexService;
   boolean                               bIsResponseByDsd;
   uint8                                 u8IdService;
#if((CfgSwcServiceDcm_fRoe != CfgSwcServiceDcm_dbDisable)||(CfgSwcServiceDcm_fRdpi != CfgSwcServiceDcm_dbDisable))
   uint8                                 u8TableServiceDataOld;
#endif
#if(CfgSwcServiceDcm_fPagedBuffer != CfgSwcServiceDcm_dbDisable)
   boolean                               bBufferTxPaged;
#endif
#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != CfgSwcServiceDcm_dbDisable)
   Type_tIdPdu                           tIdPduRxNew;
#if((CfgSwcServiceDcm_fRoe != CfgSwcServiceDcm_dbDisable)||(CfgSwcServiceDcm_fRdpi != CfgSwcServiceDcm_dbDisable))
   Type_tIdPdu                           tIdPduRxPass;
#endif
#endif
   Type_tLengthPdu                       tLengthPduRequest;
   Type_tIdPdu                           tIdPduTxOld;
#if(CfgSwcServiceDcm_fPagedBuffer != CfgSwcServiceDcm_dbDisable)
   Type_SwcServiceDcmDsld_tMessageLength tMessageLengthResponsePageCurrent;
#endif
#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != CfgSwcServiceDcm_dbDisable)
   Type_tLengthPdu                       tLengthPduRequestNew;
#endif
#if((CfgSwcServiceDcm_fRoe != CfgSwcServiceDcm_dbDisable)||(CfgSwcServiceDcm_fRdpi != CfgSwcServiceDcm_dbDisable))
#if(DCM_CFG_PROTOCOL_PREMPTION_ENABLED != CfgSwcServiceDcm_dbDisable)
   Type_tLengthPdu                       tLengthPduRequestPass;
#endif
   uint32                                u32TimeoutTimerData;
#endif
   Type_SwcServiceDcmDsld_tMessage       tMessageTxActive;
   uint32                                u32TimeoutMonitor;
#if(DCM_CFG_ROETYPE2_ENABLED != CfgSwcServiceDcm_dbDisable)
   uint32                                u32TimeoutTimerDataRoeType2;
#endif
#if(CfgSwcServiceDcm_fPagedBuffer != CfgSwcServiceDcm_dbDisable)
   uint32                                u32TimeoutTimerDataBufferPaged;
#endif
   uint8                                 u8IndexSessionPrevious;
}Type_SwcServiceDcmDsld_stInternal;

Type_SwcServiceDcmDsld_stInternal SwcServiceDcmDsld_stInternal;
static boolean lbIsNormalResponseAvailable(
   Type_tIdPdu ltIdPdu
){
   return(
         (
               CfgSwcServiceDcmDsld_cst.ptrctTableIdPduTx[ltIdPdu]
            == SwcServiceDcmDsld_stInternal.tIdPduTxActive
         )
   );
}

extern Type_SwcServiceDcmDsld_stPduRxElement SwcServiceDcmDsld_astTablePduRx[CfgSwcServiceDcmDsld_dNumIdPduRx];
static boolean bIsNrc21ResponseAvailable(
      uint16*     lptru16IdService
   ,  Type_tIdPdu ltIdPdu
){
   Type_tIdPdu ltIdPduIndex;
   uint8       lu8IdConnection;
   uint8       lu8IndexProtocol;
   uint8       lu8IdService;
   boolean     lbValueReturn = FALSE;

   for(
      ltIdPduIndex = 0;
      ltIdPduIndex < CfgSwcServiceDcmDsld_dNumIdPduRx;
      ltIdPduIndex ++
   ){
      lu8IdService = SwcServiceDcmDsld_astTablePduRx[ltIdPduIndex].u8IdService;
      if(
            SwcServiceDcmDsld_dIdServiceValueDefault
         != lu8IdService
      ){
        *lptru16IdService = lu8IdService;
         lu8IdConnection  = SwcServiceDcmDsld_pcu8TableRx[ltIdPduIndex];
         lu8IndexProtocol = SwcServiceDcmDsld_ptrcstTableConnection[lu8IdConnection].u8NumProtocol;
         if(
               (
                     SwcServiceDcmDsld_ptrcstTableConnection[lu8IdConnection].tNumIdPduTx
                  == CfgSwcServiceDcmDsld_cst.ptrctTableIdPduTx[ltIdPdu]
               )
            && (
                     FALSE
                  != SwcServiceDcmDsld_pcstProtocol[lu8IndexProtocol].bNrc21
               )
         ){
            lbValueReturn = TRUE;
            break;
         }
      }
   }
   return lbValueReturn;
}

extern Type_StackCom_stInfoPdu SwcServiceDcmDsld_stInfoPdu;
       Type_StackCom_stInfoPdu SwcServiceDcmDsld_stInfoPdu;
static Type_StackCom_stInfoPdu* ptrstInfoPdu;
static boolean                  bIsNrc21ResponseSet;
static Type_StackCom_eResultBufferRequest leValidateCopyInfoPduTx(
            Type_tIdPdu                ltIdPdu
   ,  const Type_StackCom_stInfoPdu*   lptrcstInfoPdu
   ,  const Type_StackCom_stInfoRetry* lptrcstInfoRetry
){
   Type_StackCom_stInfoPdu            lstInfoPdu;
   Type_StackCom_eResultBufferRequest leValueReturn = eResultBufferRequest_Nok;
   uint16                             u16IdService  = 0u;
   uint8                              lau8Data[3];

   bIsNrc21ResponseSet = FALSE;
   if(
         FALSE
      != lbIsNormalResponseAvailable(ltIdPdu)
   ){
      ptrstInfoPdu  = &SwcServiceDcmDsld_stInfoPdu;
      leValueReturn = eResultBufferRequest_Ok;
   }
#if(CfgSwcServiceDcm_fPagedBuffer != CfgSwcServiceDcm_dbDisable)
   else if(
         FALSE
      != Dcm_Prv_isPagedBufferResponseAvailable(ltIdPdu)
   ){
      leValueReturn = Dcm_Prv_ProcessPagedBufferResponse(
            lptrcstInfoPdu
         ,  lptrcstInfoRetry
      );
   }
#endif
#if(DCM_CFG_ROETYPE2_ENABLED != CfgSwcServiceDcm_dbDisable)
   else if(
         FALSE
      != Dcm_Prv_isRoeType2ResponseAvailable(ltIdPdu)
   ){
      ptrstInfoPdu  = &Dcm_DsldRoe2PduInfo_st;
      leValueReturn = eResultBufferRequest_Ok;
   }
#endif
   else{
      if(
            FALSE
         != bIsNrc21ResponseAvailable(
                 &u16IdService
               ,  ltIdPdu
            )
      ){
         bIsNrc21ResponseSet     = TRUE;
         leValueReturn           = eResultBufferRequest_Ok;
         lau8Data[0]             = DCM_NEGRESPONSE_INDICATOR;
         lau8Data[1]             = (uint8)u16IdService;
         lau8Data[2]             = DCM_E_BUSYREPEATREQUEST;
         lstInfoPdu.tLengthSdu   = DCM_NEGATIVE_RESPONSE_LENGTH;
         lstInfoPdu.ptru8DataSdu = &lau8Data[0];
         ptrstInfoPdu            = &lstInfoPdu;
      }
   }
#if(CfgSwcServiceDcm_fPagedBuffer == CfgSwcServiceDcm_dbDisable)
   (void)lptrcstInfoPdu;
   (void)lptrcstInfoRetry;
#endif
   return leValueReturn;
}

FUNC(Type_StackCom_eResultBufferRequest, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServicePduR_eCopyPduTx(
            Type_tIdPdu                ltIdPdu
   ,  const Type_StackCom_stInfoPdu*   lptrcstInfoPdu
   ,        Type_StackCom_stInfoRetry* retry
   ,        Type_tLengthPdu*           lptrtLengthPdu
){
   Type_StackCom_eResultBufferRequest leValueReturn = eResultBufferRequest_Nok;
   Type_StackCom_stInfoPdu*           lptrcstInfoPduTemp;
   boolean                            lbIsNrc21ResponseSet;
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
         leValueReturn = leCopyPduTxObd(
               ltIdPdu
            ,  lptrcstInfoPduTemp
         );
         lbIsNrc21ResponseSet = bIsNrc21ResponseSetObd;
      }
      else
#endif
      {
         leValueReturn = leValidateCopyInfoPduTx(
               ltIdPdu
            ,  lptrcstInfoPdu
            ,  retry
         );
         lbIsNrc21ResponseSet = bIsNrc21ResponseSet;
         lptrcstInfoPduTemp   = ptrstInfoPdu;
      }
   }
   UNUSED(lbIsNrc21ResponseSet);
   UNUSED(lptrcstInfoPduTemp);
   return leValueReturn;
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

