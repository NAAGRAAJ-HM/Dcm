/*****************************************************/
/* File   : Dcm.cpp                                  */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "Dcm.h"

#include "Dcm_EcuM.h"
#include "Dcm_SchM.h"

/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
interface_Dcm_EcuM_Init Dcm_EcuM_Init;
interface_Dcm_SchM_Main Dcm_SchM_Main;
class_Dcm Dcm;

interface_EcuM_Init_Client *EcuM_Init_Client_ptr_Dcm = &Dcm_EcuM_Init;
interface_SchM_Main_Client *SchM_Main_Client_ptr_Dcm = &Dcm_SchM_Main;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
FUNC(void, DCM_CODE) interface_Dcm_EcuM_Init::InitFunction(void){
}

FUNC(void, DCM_CODE) interface_Dcm_SchM_Main::MainFunction(void){
}

FUNC(void, DCM_CODE) class_Dcm::GetVersionInfo(void){
}

FUNC(void, DCM_CODE) class_Dcm::DemTriggerOnDtcStatus(void){
}

FUNC(void, DCM_CODE) class_Dcm::GetVin(void){
}

FUNC(void, DCM_CODE) class_Dcm::GetSecurityLevel(void){
}

FUNC(void, DCM_CODE) class_Dcm::GetSesCtrlType(void){
}

FUNC(void, DCM_CODE) class_Dcm::GetActiveProtocol(void){
}

FUNC(void, DCM_CODE) class_Dcm::ResetToDefaultSession(void){
}

FUNC(void, DCM_CODE) class_Dcm::TriggerOnEvent(void){
}

FUNC(void, DCM_CODE) class_Dcm::SetActiveDiagnostic(void){
}

FUNC(void, DCM_CODE) class_Dcm::StartOfReception(void){
}

FUNC(void, DCM_CODE) class_Dcm::CopyRxData(void){
}

FUNC(void, DCM_CODE) class_Dcm::TpRxIndication(void){
}

FUNC(void, DCM_CODE) class_Dcm::CopyTxData(void){
}

FUNC(void, DCM_CODE) class_Dcm::TpTxConfirmation(void){
}

FUNC(void, DCM_CODE) class_Dcm::TxConfirmation(void){
}

FUNC(void, DCM_CODE) class_Dcm::ComM_NoComModeEntered(void){
}

FUNC(void, DCM_CODE) class_Dcm::ComM_SilentComModeEntered(void){
}

FUNC(void, DCM_CODE) class_Dcm::ComM_FullComModeEntered(void){
}

FUNC(void, DCM_CODE) class_Dcm::CallOut_ReadMemory(void){
}

FUNC(void, DCM_CODE) class_Dcm::CallOut_WriteMemory(void){
}

FUNC(void, DCM_CODE) class_Dcm::CallOut_SetProgConditions(void){
}

FUNC(void, DCM_CODE) class_Dcm::CallOut_GetProgConditions(void){
}

FUNC(void, DCM_CODE) class_Dcm::CallOut_ProcessRequestTransferExit(void){
}

FUNC(void, DCM_CODE) class_Dcm::CallOut_ProcessRequestUpload(void){
}

FUNC(void, DCM_CODE) class_Dcm::CallOut_ProcessRequestDownload(void){
}

FUNC(void, DCM_CODE) class_Dcm::CallOut_ProcessRequestFileTransfer(void){
}

/*****************************************************/
/* EOF                                               */
/*****************************************************/

