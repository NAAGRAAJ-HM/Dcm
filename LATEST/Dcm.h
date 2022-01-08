#pragma once

class class_Dcm{
   public:
      void InitFunction                       (void);
      void GetVersionInfo                     (void);
      void DemTriggerOnDtcStatus              (void);
      void GetVin                             (void);
      void GetSecurityLevel                   (void);
      void GetSesCtrlType                     (void);
      void GetActiveProtocol                  (void);
      void ResetToDefaultSession              (void);
      void TriggerOnEvent                     (void);
      void SetActiveDiagnostic                (void);
      void StartOfReception                   (void);
      void CopyRxData                         (void);
      void TpRxIndication                     (void);
      void CopyTxData                         (void);
      void TpTxConfirmation                   (void);
      void TxConfirmation                     (void);
      void ComM_NoComModeEntered              (void);
      void ComM_SilentComModeEntered          (void);
      void ComM_FullComModeEntered            (void);
      void CallOut_ReadMemory                 (void);
      void CallOut_WriteMemory                (void);
      void CallOut_SetProgConditions          (void);
      void CallOut_GetProgConditions          (void);
      void CallOut_ProcessRequestTransferExit (void);
      void CallOut_ProcessRequestUpload       (void);
      void CallOut_ProcessRequestDownload     (void);
      void CallOut_ProcessRequestFileTransfer (void);
      void MainFunction                       (void);
};

extern class_Dcm Dcm;

