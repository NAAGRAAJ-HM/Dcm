#include "Std_Types.hpp"

#include "DcmCore_DslDsd_Inf.hpp"
#include "DcmCore_Main_Inf.hpp"

#define DCM_MAX_LIMIT_WAITPEND        (0xFFu)

#define Dcm_Lok_ProcessDslStateMachine(stDslState_en)  Dcm_ProcessDslState[stDslState_en]()
typedef void (*Dcm_DslStateType)(void);

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_Cfg_MemMap.hpp"
const Dcm_DslStateType  Dcm_ProcessDslState[DCM_NUMBER_OF_DSL_STATES];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_Cfg_MemMap.hpp"

#define DCM_START_SEC_VAR_CLEARED_8
#include "Dcm_Cfg_MemMap.hpp"
VAR(uint8,DCM_VAR) Dcm_DslWaitPendBuffer_au8[8];
VAR(uint8, AUTOMATIC) Dcm_DslState_u8;
VAR(uint8, AUTOMATIC) Dcm_DslSubState_u8;
VAR(uint8, AUTOMATIC) Dcm_DslNextState_u8;
VAR(uint8, AUTOMATIC) Dcm_DslNextSubState_u8;
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "Dcm_Cfg_MemMap.hpp"

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_Cfg_MemMap.hpp"
P2CONST(Dcm_Dsld_ServiceType, DCM_VAR, DCM_INTERN_CONST) Dcm_DsldSrvTable_pcst;
VAR(Dcm_DsldTimingsType_tst,DCM_VAR) Dcm_DsldTimer_st;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_Cfg_MemMap.hpp"

#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_Cfg_MemMap.hpp"
VAR(boolean,DCM_VAR) Dcm_isGeneralRejectSent_b;
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_Cfg_MemMap.hpp"

#define DCM_START_SEC_VAR_CLEARED_8
#include "Dcm_Cfg_MemMap.hpp"
VAR(StatusType,DCM_VAR) Dcm_P2OrS3TimerStatus_uchr;
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "Dcm_Cfg_MemMap.hpp"

#define DCM_START_SEC_CODE
#include "Dcm_Cfg_MemMap.hpp"

FUNC(P2VAR(Dcm_MsgItemType, AUTOMATIC, DCM_INTERN_DATA), DCM_CODE) Dcm_GetActiveBuffer(void){
    return Dcm_DsldProtocol_pcst[Dcm_DsldGlobal_st.idxCurrentProtocol_u8].rx_mainBuffer_pa;
}

static FUNC(void, DCM_CODE) Dcm_Lok_SetIntermediateResponse(VAR(uint8, AUTOMATIC) dataNegativeResponse_u8)
{

    Dcm_Lok_SetDslState(DSL_STATE_WAITING_FOR_TXCONFIRMATION);

    Dcm_DslWaitPendBuffer_au8[0] = DCM_NEGRESPONSE_INDICATOR;
    Dcm_DslWaitPendBuffer_au8[1] = Dcm_DsldGlobal_st.dataSid_u8;
    Dcm_DslWaitPendBuffer_au8[2] = dataNegativeResponse_u8 ;

    Dcm_DsldPduInfo_st.SduDataPtr = Dcm_DslWaitPendBuffer_au8;
    Dcm_DsldPduInfo_st.SduLength = DCM_NEGATIVE_RESPONSE_LENGTH;
}

static FUNC(Std_ReturnType, DCM_CODE) Dcm_Lok_StartProtocol(void){
   VAR(Std_ReturnType, AUTOMATIC) startProtocolStatus = E_NOT_OK;
   if((Dcm_CurProtocol_u8 != DCM_NO_ACTIVE_PROTOCOL) && (!Dcm_isStopProtocolInvoked_b)){
        Dcm_StopProtocol(Dcm_CurProtocol_u8);
   }
   startProtocolStatus = Dcm_StartProtocol(Dcm_DsldProtocol_pcst[Dcm_DsldGlobal_st.idxCurrentProtocol_u8].protocolid_u8);
   if(E_OK == startProtocolStatus){
        Dcm_DsldGlobal_st.flgCommActive_b = TRUE;
        Dcm_DsldGlobal_st.datActiveSrvtable_u8 = Dcm_DsldProtocol_pcst[Dcm_DsldGlobal_st.idxCurrentProtocol_u8].
                sid_tableid_u8;
        Dcm_DsldSrvTable_pcst = CfgSwcServiceDcm_stDsld.sid_table_pcs[Dcm_DsldGlobal_st.datActiveSrvtable_u8].ptr_service_table_pcs;
        Dcm_Dsd_ServiceIni(Dcm_DsldGlobal_st.datActiveSrvtable_u8);
        Dcm_Lok_SetSesCtrlType(Dcm_DsldSessionTable_pcu8[DCM_DEFAULT_SESSION_IDX]);
        Dcm_CurProtocol_u8 = Dcm_DsldProtocol_pcst[Dcm_DsldGlobal_st.idxCurrentProtocol_u8].protocolid_u8;
   }
   return startProtocolStatus;
}

static FUNC(void, DCM_CODE) Dcm_Lok_SendNrcforStartProtocolFailure(void){
   VAR(Dcm_NegativeResponseCodeType, AUTOMATIC) dataNrc_u8 = 0x22;
   P2VAR(Dcm_MsgItemType, AUTOMATIC, DCM_INTERN_DATA) adrRxBuffer_pu8 = NULL_PTR;

    Dcm_DsldGlobal_st.adrActiveTxBuffer_tpu8 = (&(Dcm_DsldProtocol_pcst[Dcm_DsldGlobal_st.idxCurrentProtocol_u8]))->tx_buffer_pa;
    Dcm_DsldGlobal_st.dataResponseByDsd_b = TRUE;
    adrRxBuffer_pu8 = (&(Dcm_DsldProtocol_pcst[Dcm_DsldGlobal_st.idxCurrentProtocol_u8]))->rx_mainBuffer_pa;
    Dcm_DsldGlobal_st.dataSid_u8     = adrRxBuffer_pu8[0];
    Dcm_DsldMsgContext_st.idContext  = Dcm_DsldGlobal_st.dataSid_u8;
    Dcm_DsldMsgContext_st.dcmRxPduId = Dcm_DsldGlobal_st.dataActiveRxPduId_u8;
    Dcm_DsldMsgContext_st.msgAddInfo.sourceofRequest = DCM_UDS_TESTER_SOURCE;
    Dcm_DsldMsgContext_st.resDataLen = 0u;
   if(Dcm_DsldGlobal_st.dataActiveRxPduId_u8 >= DCM_INDEX_FUNC_RX_PDUID)
   {
        Dcm_DsldMsgContext_st.msgAddInfo.reqType = DCM_PRV_FUNCTIONAL_REQUEST;
   }
   else{
        Dcm_DsldMsgContext_st.msgAddInfo.reqType = DCM_PRV_PHYSICAL_REQUEST;
   }
    Dcm_DsldGlobal_st.stResponseType_en      = DCM_DSLD_POS_RESPONSE;
    Dcm_Lok_SetDslState(DSL_STATE_REQUEST_RECEIVED);
    Dcm_Lok_SetDslSubState(DSL_SUBSTATE_P2MAX_TIMEMONITORING);
    Dcm_DsldGlobal_st.dataActiveTxPduId_u8   = Dcm_DsldConnTable_pcst[Dcm_DsldGlobal_st.nrActiveConn_u8].txpduid_num_u8;
    Dcm_DsldGlobal_st.cntrWaitpendCounter_u8 = 0;
    Dcm_DslTransmit_st.isForceResponsePendRequested_b    = FALSE;
    Dcm_SetNegResponse(&Dcm_DsldMsgContext_st ,dataNrc_u8);
    Dcm_ProcessingDone(&Dcm_DsldMsgContext_st);
}

static FUNC(void, DCM_CODE) Dcm_Lok_UpdateStatesForStartProtocol(void){
   if((DCM_CHKFULLCOMM_MODE(Dcm_DsldConnTable_pcst[Dcm_DsldGlobal_st.nrActiveConn_u8].channel_idx_u8)) && \
            (FALSE == (DCM_TimerElapsed(Dcm_DsldGlobal_st.dataTimeoutMonitor_u32))))
   {
        Dcm_isGeneralRejectSent_b = FALSE;
        Dcm_Lok_SetDslState(DSL_STATE_REQUEST_RECEIVED);
        Dcm_Lok_SetDslSubState(DSL_SUBSTATE_P2MAX_TIMEMONITORING);
        Dcm_Lok_SetDslNextState(DSL_STATE_REQUEST_RECEIVED);
        Dcm_Lok_SetDslNextSubState(DSL_SUBSTATE_P2MAX_TIMEMONITORING);
        Dcm_Lok_SetDsdState(DSD_VERIFY_DIAGNOSTIC_DATA);
        Dcm_DsldGlobal_st.cntrWaitpendCounter_u8 = 0x0u;
        Dcm_DsldGlobal_st.dataActiveTxPduId_u8   = Dcm_DsldConnTable_pcst[Dcm_DsldGlobal_st.nrActiveConn_u8].txpduid_num_u8;
        Dcm_DsldGlobal_st.dataSid_u8 = Dcm_DsldProtocol_pcst[Dcm_DsldGlobal_st.idxCurrentProtocol_u8].rx_mainBuffer_pa[0];
   }
   else if((Dcm_DsldGlobal_st.idxActiveSession_u8 != DCM_DEFAULT_SESSION_IDX) \
            || (FALSE != DCM_TimerElapsed(Dcm_DsldGlobal_st.dataTimeoutMonitor_u32)))
   {
        DcmAppl_DcmComModeError(Dcm_active_commode_e[Dcm_DsldConnTable_pcst[Dcm_DsldGlobal_st.nrActiveConn_u8].channel_idx_u8].ComMChannelId);
        Dcm_Lok_SetDslState(DSL_STATE_IDLE);
        Dcm_Lok_SetDslSubState(DSL_SUBSTATE_S3_OR_P3_TIMEMONITORING);
        Dcm_Lok_SetDslNextState(DSL_STATE_IDLE);
        Dcm_Lok_SetDslNextSubState(DSL_SUBSTATE_S3_OR_P3_TIMEMONITORING);
        Dcm_Lok_SetDsdState(DSD_IDLE);
   }
   else{
        DCM_TimerProcess(Dcm_DsldGlobal_st.dataTimeoutMonitor_u32,Dcm_P2OrS3StartTick_u32,Dcm_P2OrS3TimerStatus_uchr)
   }
}

static FUNC(void, DCM_CODE) Dcm_Lok_DslSubState_SendFinalResponse(void){
     Dcm_DsldPduInfo_st.SduDataPtr = Dcm_DslTransmit_st.TxBuffer_tpu8;
     Dcm_DsldPduInfo_st.SduLength = (Type_SwcServiceCom_tLengthPdu)Dcm_DslTransmit_st.TxResponseLength_u32;
     Dcm_Lok_SetDslState(DSL_STATE_WAITING_FOR_TXCONFIRMATION);
     Dcm_DsldGlobal_st.cntrWaitpendCounter_u8 = 0x0u;
     Dcm_Lok_SetDslNextState(DSL_STATE_IDLE);
     Dcm_Lok_SetDslNextSubState(DSL_SUBSTATE_S3_OR_P3_TIMEMONITORING);
     Dcm_Lok_SendResponse(& Dcm_DsldPduInfo_st);
}

static FUNC(void, DCM_CODE) Dcm_Lok_DslSubState_SendGeneralReject(void){
   VAR(uint8,DCM_VAR) NrcValue_u8 = 0u;
   if(Dcm_DsldGlobal_st.cntrWaitpendCounter_u8 == DCM_CFG_MAX_WAITPEND)
   {
        if(Dcm_DsldSrvTable_pcst[Dcm_DsldGlobal_st.idxService_u8].service_handler_fp != NULL_PTR)
        {
            (void)(*Dcm_DsldSrvTable_pcst[Dcm_DsldGlobal_st.idxService_u8].service_handler_fp) \
                                (DCM_CANCEL,&Dcm_DsldMsgContext_st,&NrcValue_u8);
            Dcm_SrvOpstatus_u8 = DCM_INITIAL;
        }
        Dcm_DsldGlobal_st.idxService_u8       = 0x00u;
        Dcm_DsldGlobal_st.dataResponseByDsd_b = TRUE;
        Dcm_DslTransmit_st.isForceResponsePendRequested_b = FALSE;
        Dcm_Lok_ResetDsdSubStateMachine();
        Dcm_SetNegResponse( &Dcm_DsldMsgContext_st ,DCM_E_GENERALREJECT);
        Dcm_isGeneralRejectSent_b = TRUE;
        Dcm_ProcessingDone (&Dcm_DsldMsgContext_st);
   }
}

static FUNC(void, DCM_CODE) Dcm_Lok_DslSubState_SendPendingResponse(void){
   if(FALSE == Dcm_Lok_Check_PendingResponseForKWP())
   {
        if(TRUE == Dcm_Lok_IsVerifyDataProcessing())
        {
            Dcm_Lok_SetDslNextState(DSL_STATE_IDLE);
            Dcm_Lok_SetDslSubState(DSL_SUBSTATE_S3_OR_P3_TIMEMONITORING);
            Dcm_Lok_SetDslNextSubState(DSL_SUBSTATE_S3_OR_P3_TIMEMONITORING);
            Dcm_Lok_SetDsdState(DSD_IDLE);
            Dcm_Lok_SetIntermediateResponse(DCM_E_BUSYREPEATREQUEST);
            Dcm_Lok_SendResponse(& Dcm_DsldPduInfo_st);
        }
        else{
            if((Dcm_DsldGlobal_st.cntrWaitpendCounter_u8 < DCM_CFG_MAX_WAITPEND) || \
                    (DCM_CFG_MAX_WAITPEND == DCM_MAX_LIMIT_WAITPEND))
            {
                Dcm_DsldMsgContext_st.msgAddInfo.suppressPosResponse = FALSE;
                Dcm_Lok_SetIntermediateResponse(DCM_E_REQUESTCORRECTLYRECEIVED_RESPONSEPENDING);
                if(Dcm_DsldGlobal_st.cntrWaitpendCounter_u8 < DCM_MAX_LIMIT_WAITPEND)
                {
                    Dcm_DsldGlobal_st.cntrWaitpendCounter_u8++;
                }
                Dcm_Lok_SendResponse(&Dcm_DsldPduInfo_st);
            }
            else{
                Dcm_Lok_DslSubState_SendGeneralReject();
            }
        }
   }
}

static FUNC(void, DCM_CODE) Dcm_Lok_DslSubState_MonitorP2Max(void){
    DCM_TimerProcess(Dcm_DsldGlobal_st.dataTimeoutMonitor_u32,Dcm_P2OrS3StartTick_u32,Dcm_P2OrS3TimerStatus_uchr)
   if(FALSE != DCM_TimerElapsed(Dcm_DsldGlobal_st.dataTimeoutMonitor_u32))
   {
        Dcm_Lok_DslSubState_SendPendingResponse();
   }
}

static FUNC(void, DCM_CODE) Dcm_Lok_DslSubState_StartProtocol(void){
   if(FALSE == Dcm_Lok_isProtocolStarted())
   {
        if(E_OK != Dcm_Lok_StartProtocol())
        {
            Dcm_Lok_SendNrcforStartProtocolFailure();
        }
        Dcm_isStopProtocolInvoked_b = FALSE;
   }
   if(FALSE != Dcm_Lok_isProtocolStarted())
   {
        Dcm_Lok_UpdateStatesForStartProtocol();
   }
}

static FUNC(void, DCM_CODE) Dcm_Lok_DslSubState_S3_OR_P3_Timeout(VAR(uint8, AUTOMATIC) idxActiveSession_u8){
   if(idxActiveSession_u8 != DCM_DEFAULT_SESSION_IDX){
        ComM_DCM_InactiveDiagnostic (Dcm_active_commode_e \
                [Dcm_DsldConnTable_pcst[Dcm_DsldGlobal_st.nrActiveConn_u8].channel_idx_u8].ComMChannelId);
   }
    Dcm_Lok_SetSesCtrlType(Dcm_DsldSessionTable_pcu8[DCM_DEFAULT_SESSION_IDX]);
    Dcm_DsldGlobal_st.flgMonitorP3timer_b = FALSE;
}

static FUNC(void, DCM_CODE) Dcm_Lok_DslSubState_S3_OR_P3_TimeMoniotor(void){
   if(FALSE == (DCM_TimerElapsed(Dcm_DsldGlobal_st.dataTimeoutMonitor_u32))){
        DCM_TimerProcess(Dcm_DsldGlobal_st.dataTimeoutMonitor_u32,Dcm_P2OrS3StartTick_u32,\
                Dcm_P2OrS3TimerStatus_uchr)
   }
   else{
        Dcm_Lok_SetDslSubState(DSL_SUBSTATE_S3_OR_P3_TIMEOUT);
   }
}

static FUNC(void, DCM_CODE) Dcm_Lok_DslState_WaitingForTxConfirmation(void){
   VAR(uint8, AUTOMATIC) Dcm_DslStateTemp_u8 = 0u;
    (void)Dcm_DslStateTemp_u8;
}

static FUNC(void, DCM_CODE) Dcm_Lok_DslState_ResponseTransmission(void){
   if(Dcm_Lok_GetDslSubState() == DSL_SUBSTATE_SEND_PENDING_RESPONSE)
   {
        Dcm_Lok_DslSubState_SendPendingResponse();
   }
   if(Dcm_Lok_GetDslSubState() == DSL_SUBSTATE_SEND_GENERAL_REJECT)
   {
        Dcm_Lok_DslSubState_SendGeneralReject();
   }
   if(Dcm_Lok_GetDslSubState() == DSL_SUBSTATE_SEND_FINAL_RESPONSE)
   {
        Dcm_Lok_DslSubState_SendFinalResponse();
   }
}

static FUNC(void, DCM_CODE) Dcm_Lok_DslState_RequestReceived(void){
   if(Dcm_Lok_GetDslSubState() == DSL_SUBSTATE_START_PROTOCOL)
   {
        Dcm_Lok_DslSubState_StartProtocol();
   }

   if(Dcm_Lok_GetDslSubState() == DSL_SUBSTATE_P2MAX_TIMEMONITORING)
   {
        Dcm_Lok_DslSubState_MonitorP2Max();
   }
}

static FUNC(void, DCM_CODE) Dcm_Lok_DslState_WaitingForRxIndication(void){
   VAR(uint8, AUTOMATIC) Dcm_DslStateTemp_u8 = 0u;
    (void)Dcm_DslStateTemp_u8;
}

static FUNC(void, DCM_CODE) Dcm_Lok_DslState_Idle(void){
   VAR(uint8, AUTOMATIC) idxActiveSession_u8 = 0u;
    SchM_Enter_Dcm_Global_NoNest();
   idxActiveSession_u8 = Dcm_DsldGlobal_st.idxActiveSession_u8;
    SchM_Exit_Dcm_Global_NoNest();
   if((idxActiveSession_u8 != DCM_DEFAULT_SESSION_IDX) || (Dcm_DsldGlobal_st.flgMonitorP3timer_b != FALSE))
   {
        if(Dcm_Lok_GetDslSubState() == DSL_SUBSTATE_S3_OR_P3_TIMEMONITORING)
        {
            Dcm_Lok_DslSubState_S3_OR_P3_TimeMoniotor();
        }
        if(Dcm_Lok_GetDslSubState() == DSL_SUBSTATE_S3_OR_P3_TIMEOUT)
        {
            Dcm_Lok_DslSubState_S3_OR_P3_Timeout(idxActiveSession_u8);
            Dcm_Lok_SetDslSubState(DSL_SUBSTATE_S3_OR_P3_TIMEMONITORING);
        }
   }
}

FUNC(void, DCM_CODE) Dcm_Lok_DslStateMachine(void){
   VAR(uint8, AUTOMATIC) DslStateTemp_u8 = 0u;
    SchM_Enter_Dcm_Global_NoNest();
    DslStateTemp_u8 = Dcm_Lok_GetDslState();
    SchM_Exit_Dcm_Global_NoNest();
    Dcm_Lok_ProcessDslStateMachine(DslStateTemp_u8);
}
#define DCM_STOP_SEC_CODE
#include "Dcm_Cfg_MemMap.hpp"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_Cfg_MemMap.hpp"
const Dcm_DslStateType  Dcm_ProcessDslState[DCM_NUMBER_OF_DSL_STATES] =
{
    Dcm_Lok_DslState_Idle
   ,   Dcm_Lok_DslState_WaitingForRxIndication
   ,   Dcm_Lok_DslState_RequestReceived
   ,   Dcm_Lok_DslState_ResponseTransmission
   ,   Dcm_Lok_DslState_WaitingForTxConfirmation,
   Dcm_Lok_DslState_Idle
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_Cfg_MemMap.hpp"
