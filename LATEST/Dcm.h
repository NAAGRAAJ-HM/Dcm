#pragma once
/*****************************************************/
/* File   : Dcm.h                                    */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "Std_Types.h"
#include "Compiler_Cfg_Dcm.h"

/*****************************************************/
/* TYPEDEFS                                          */
/*****************************************************/
class class_Dcm{
   public:
/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
      FUNC(void, DCM_CODE) InitFunction                       (void);
      FUNC(void, DCM_CODE) GetVersionInfo                     (void);
      FUNC(void, DCM_CODE) DemTriggerOnDtcStatus              (void);
      FUNC(void, DCM_CODE) GetVin                             (void);
      FUNC(void, DCM_CODE) GetSecurityLevel                   (void);
      FUNC(void, DCM_CODE) GetSesCtrlType                     (void);
      FUNC(void, DCM_CODE) GetActiveProtocol                  (void);
      FUNC(void, DCM_CODE) ResetToDefaultSession              (void);
      FUNC(void, DCM_CODE) TriggerOnEvent                     (void);
      FUNC(void, DCM_CODE) SetActiveDiagnostic                (void);
      FUNC(void, DCM_CODE) StartOfReception                   (void);
      FUNC(void, DCM_CODE) CopyRxData                         (void);
      FUNC(void, DCM_CODE) TpRxIndication                     (void);
      FUNC(void, DCM_CODE) CopyTxData                         (void);
      FUNC(void, DCM_CODE) TpTxConfirmation                   (void);
      FUNC(void, DCM_CODE) TxConfirmation                     (void);
      FUNC(void, DCM_CODE) ComM_NoComModeEntered              (void);
      FUNC(void, DCM_CODE) ComM_SilentComModeEntered          (void);
      FUNC(void, DCM_CODE) ComM_FullComModeEntered            (void);
      FUNC(void, DCM_CODE) CallOut_ReadMemory                 (void);
      FUNC(void, DCM_CODE) CallOut_WriteMemory                (void);
      FUNC(void, DCM_CODE) CallOut_SetProgConditions          (void);
      FUNC(void, DCM_CODE) CallOut_GetProgConditions          (void);
      FUNC(void, DCM_CODE) CallOut_ProcessRequestTransferExit (void);
      FUNC(void, DCM_CODE) CallOut_ProcessRequestUpload       (void);
      FUNC(void, DCM_CODE) CallOut_ProcessRequestDownload     (void);
      FUNC(void, DCM_CODE) CallOut_ProcessRequestFileTransfer (void);
      FUNC(void, DCM_CODE) MainFunction                       (void);
};

/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
extern class_Dcm Dcm;

/*****************************************************/
/* EOF                                               */
/*****************************************************/

