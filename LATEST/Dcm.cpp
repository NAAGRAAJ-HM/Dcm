/******************************************************************************/
/* File   : Dcm.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "infDcm_Version.h"

#include "module.h"
#include "infDcm_EcuM.h"
#include "infDcm_Dcm.h"
#include "infDcm_SchM.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_Dcm:
      public abstract_module
{
   public:
      FUNC(void, DCM_CODE) InitFunction   (void);
      FUNC(void, DCM_CODE) DeInitFunction (void);
      FUNC(void, DCM_CODE) GetVersionInfo (void);
      FUNC(void, DCM_CODE) MainFunction   (void);
};

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

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/


/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
VAR(module_Dcm, DCM_VAR) Dcm;
CONSTP2VAR(infEcuMClient, DCM_VAR, DCM_CONST) gptrinfEcuMClient_Dcm = &Dcm;
CONSTP2VAR(infDcmClient,  DCM_VAR, DCM_CONST) gptrinfDcmClient_Dcm  = &Dcm;
CONSTP2VAR(infSchMClient, DCM_VAR, DCM_CONST) gptrinfSchMClient_Dcm = &Dcm;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
FUNC(void, DCM_CODE) module_Dcm::InitFunction(void){
}

FUNC(void, DCM_CODE) module_Dcm::DeInitFunction(void){
}

FUNC(void, DCM_CODE) module_Dcm::GetVersionInfo(void){
}

FUNC(void, DCM_CODE) module_Dcm::MainFunction(void){
}

#include "Dcm_Unused.h"

FUNC(void, DCM_CODE) class_Dcm_Unused::DemTriggerOnDtcStatus(void){
}

FUNC(void, DCM_CODE) class_Dcm_Unused::GetVin(void){
}

FUNC(void, DCM_CODE) class_Dcm_Unused::GetSecurityLevel(void){
}

FUNC(void, DCM_CODE) class_Dcm_Unused::GetSesCtrlType(void){
}

FUNC(void, DCM_CODE) class_Dcm_Unused::GetActiveProtocol(void){
}

FUNC(void, DCM_CODE) class_Dcm_Unused::ResetToDefaultSession(void){
}

FUNC(void, DCM_CODE) class_Dcm_Unused::TriggerOnEvent(void){
}

FUNC(void, DCM_CODE) class_Dcm_Unused::SetActiveDiagnostic(void){
}

FUNC(void, DCM_CODE) class_Dcm_Unused::StartOfReception(void){
}

FUNC(void, DCM_CODE) class_Dcm_Unused::CopyRxData(void){
}

FUNC(void, DCM_CODE) class_Dcm_Unused::TpRxIndication(void){
}

FUNC(void, DCM_CODE) class_Dcm_Unused::CopyTxData(void){
}

FUNC(void, DCM_CODE) class_Dcm_Unused::TpTxConfirmation(void){
}

FUNC(void, DCM_CODE) class_Dcm_Unused::TxConfirmation(void){
}

FUNC(void, DCM_CODE) class_Dcm_Unused::ComM_NoComModeEntered(void){
}

FUNC(void, DCM_CODE) class_Dcm_Unused::ComM_SilentComModeEntered(void){
}

FUNC(void, DCM_CODE) class_Dcm_Unused::ComM_FullComModeEntered(void){
}

FUNC(void, DCM_CODE) class_Dcm_Unused::CallOut_ReadMemory(void){
}

FUNC(void, DCM_CODE) class_Dcm_Unused::CallOut_WriteMemory(void){
}

FUNC(void, DCM_CODE) class_Dcm_Unused::CallOut_SetProgConditions(void){
}

FUNC(void, DCM_CODE) class_Dcm_Unused::CallOut_GetProgConditions(void){
}

FUNC(void, DCM_CODE) class_Dcm_Unused::CallOut_ProcessRequestTransferExit(void){
}

FUNC(void, DCM_CODE) class_Dcm_Unused::CallOut_ProcessRequestUpload(void){
}

FUNC(void, DCM_CODE) class_Dcm_Unused::CallOut_ProcessRequestDownload(void){
}

FUNC(void, DCM_CODE) class_Dcm_Unused::CallOut_ProcessRequestFileTransfer(void){
}

/*****************************************************/
/* EOF                                               */
/*****************************************************/

