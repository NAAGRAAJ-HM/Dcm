#include "Std_Types.hpp"

#include "DcmCore_DslDsd_Inf.hpp"

#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_Cfg_MemMap.hpp"
static VAR(boolean,DCM_VAR) Dcm_isResetToDefaultRequested_b;
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_Cfg_MemMap.hpp"

#define DCM_START_SEC_CODE
#include "Dcm_Cfg_MemMap.hpp"

static FUNC(boolean, DCM_CODE) Dcm_Lok_SetNonDefaultSesCtrlType (VAR(Dcm_SesCtrlType, AUTOMATIC) CurrentSession_u8
   ,     VAR(Dcm_SesCtrlType, AUTOMATIC) SesCtrlType_u8)
{
   VAR(boolean, AUTOMATIC) isSessionAvailable = FALSE;
   VAR(uint8, AUTOMATIC) nrSessions_u8 = 0u;
   VAR(uint8, AUTOMATIC) idxIndex_u8   = 0u;

    nrSessions_u8 = DCM_CFG_NUM_UDS_SESSIONS;
   for(idxIndex_u8 = 0x1; idxIndex_u8 < nrSessions_u8 ; idxIndex_u8++)
   {
        if(Dcm_DsldSessionTable_pcu8[idxIndex_u8]== SesCtrlType_u8)
        {
            break;
        }
   }
   if(idxIndex_u8 != nrSessions_u8)
   {
        isSessionAvailable = TRUE;
        Dcm_DsldGlobal_st.idxActiveSession_u8 = idxIndex_u8;
        if(DCM_IS_KWPPROT_ACTIVE() == FALSE)
        {
            Dcm_DsldGlobal_st.idxActiveSecurity_u8 = 0x00u;
        }
        Dcm_RoutineSetSesCtrlType(SesCtrlType_u8);
   }
   else{
        DCM_DET_ERROR(DCM_SETSESSIONLEVEL , DCM_E_SESSION_NOT_CONFIGURED)
   }
    return isSessionAvailable;
}

static FUNC(void, DCM_CODE) Dcm_Lok_SetDefaultSesCtrlType (VAR(Dcm_SesCtrlType, AUTOMATIC) CurrentSession_u8
   ,     VAR(Dcm_SesCtrlType, AUTOMATIC) SesCtrlType_u8)
{
    SchM_Enter_Dcm_DsldTimer_NoNest();
    Dcm_DsldTimer_st.dataTimeoutP2max_u32    =  DCM_CFG_DEFAULT_P2MAX_TIME;
    Dcm_DsldTimer_st.dataTimeoutP2StrMax_u32 =  DCM_CFG_DEFAULT_P2STARMAX_TIME;
    SchM_Exit_Dcm_DsldTimer_NoNest();
    Dcm_DsldGlobal_st.idxActiveSecurity_u8 = 0x00u;
    Dcm_DsldGlobal_st.idxActiveSession_u8 = 0x00u;
    Dcm_RoutineSetSesCtrlType(SesCtrlType_u8);
   if(CurrentSession_u8 != Dcm_DsldSessionTable_pcu8[DCM_DEFAULT_SESSION_IDX])
   {
   }
}

FUNC(void, DCM_CODE) Dcm_Lok_SetSesCtrlType (VAR(Dcm_SesCtrlType, AUTOMATIC) SesCtrlType_u8)
{
   VAR(Dcm_SesCtrlType, AUTOMATIC) currentSession_u8 = 0u;
   if(FALSE != Dcm_isSessionStored_b)
   {
        currentSession_u8 = Dcm_DsldSessionTable_pcu8[Dcm_DsldGlobal_st.PreviousSessionIndex];
        Dcm_isSessionStored_b = FALSE;
   }
   else{
        currentSession_u8 = Dcm_DsldSessionTable_pcu8[Dcm_DsldGlobal_st.idxActiveSession_u8];
   }
   if(SesCtrlType_u8 == Dcm_DsldSessionTable_pcu8[DCM_DEFAULT_SESSION_IDX])
   {
        Dcm_Lok_SetDefaultSesCtrlType(currentSession_u8,SesCtrlType_u8);
   }
   else{
        if(FALSE == Dcm_Lok_SetNonDefaultSesCtrlType(currentSession_u8,SesCtrlType_u8))
        {
            SesCtrlType_u8 = currentSession_u8;
        }
   }
    Dcm_Dsp_SecaSessIni();
    Dcm_ControlDtcSettingExit();
    Dcm_DspDeactivateRequestUploadDownloadPermission();
    (void)Dcm_SesCtrlChangeIndication(currentSession_u8, SesCtrlType_u8);
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_GetSesCtrlType(P2VAR(Dcm_SesCtrlType, AUTOMATIC, DCM_APPL_DATA)  SesCtrlType){
   if(SesCtrlType != NULL_PTR){
        if(FALSE != Dcm_isSessionStored_b){
            *SesCtrlType = Dcm_DsldSessionTable_pcu8[Dcm_DsldGlobal_st.PreviousSessionIndex];
        }
        else{
            *SesCtrlType = Dcm_DsldSessionTable_pcu8[ Dcm_DsldGlobal_st.idxActiveSession_u8];
        }
   }
   else{

        DCM_DET_ERROR(DCM_SETSESSION_ID, DCM_E_PARAM_POINTER);
   }
    return(E_OK);
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_ResetToDefaultSession(void){
   Dcm_isResetToDefaultRequested_b = TRUE;
   return (E_OK);
}

FUNC(void, DCM_CODE) Dcm_Lok_ProcessResetToDefaultSession(void){
   if(FALSE != Dcm_isResetToDefaultRequested_b){
      Dcm_Lok_SetSesCtrlType(Dcm_DsldSessionTable_pcu8[DCM_DEFAULT_SESSION_IDX]);
      Dcm_isResetToDefaultRequested_b = FALSE;
   }
}

FUNC(void, DCM_CODE) Dcm_Lok_ResetDefaultSessionRequestFlag(void){
   Dcm_isResetToDefaultRequested_b = FALSE;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_Cfg_MemMap.hpp"
