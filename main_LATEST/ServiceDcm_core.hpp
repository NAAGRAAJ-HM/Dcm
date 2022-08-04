#pragma once
/******************************************************************************/
/* File   : ServiceDcm_core.hpp                                                      */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "CompilerCfg_ServiceDcm.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define DCM_CORE_FUNCTIONALITIES                                                  \
              FUNC(void, DCM_CODE) ServiceDemTriggerOnDtcStatus              (void);     \
              FUNC(void, DCM_CODE) GetVin                             (void);     \
              FUNC(void, DCM_CODE) GetSecurityLevel                   (void);     \
              FUNC(void, DCM_CODE) GetSesCtrlType                     (void);     \
              FUNC(void, DCM_CODE) GetActiveProtocol                  (void);     \
              FUNC(void, DCM_CODE) ResetToDefaultSession              (void);     \
              FUNC(void, DCM_CODE) TriggerOnEvent                     (void);     \
              FUNC(void, DCM_CODE) SetActiveDiagnostic                (void);     \
              FUNC(void, DCM_CODE) ServiceComM_NoServiceComModeEntered              (void);     \
              FUNC(void, DCM_CODE) ServiceComM_SilentServiceComModeEntered          (void);     \
              FUNC(void, DCM_CODE) ServiceComM_FullServiceComModeEntered            (void);     \
              FUNC(void, DCM_CODE) CallOut_ReadMemory                 (void);     \
              FUNC(void, DCM_CODE) CallOut_WriteMemory                (void);     \
              FUNC(void, DCM_CODE) CallOut_SetProgConditions          (void);     \
              FUNC(void, DCM_CODE) CallOut_GetProgConditions          (void);     \
              FUNC(void, DCM_CODE) CallOut_ProcessRequestTransferExit (void);     \
              FUNC(void, DCM_CODE) CallOut_ProcessRequestUpload       (void);     \
              FUNC(void, DCM_CODE) CallOut_ProcessRequestDownload     (void);     \
              FUNC(void, DCM_CODE) CallOut_ProcessRequestFileTransfer (void);     \
              FUNC(void, DCM_CODE) StartOfReception                   (void);     \
              FUNC(void, DCM_CODE) CopyRxData                         (void);     \
              FUNC(void, DCM_CODE) RxIndication                       (void);     \
              FUNC(void, DCM_CODE) CopyTxData                         (void);     \
              FUNC(void, DCM_CODE) TxConfirmation                     (void);     \

#define DCM_CORE_FUNCTIONALITIES_VIRTUAL                                          \
      virtual FUNC(void, DCM_CODE) ServiceDemTriggerOnDtcStatus              (void) = 0; \
      virtual FUNC(void, DCM_CODE) GetVin                             (void) = 0; \
      virtual FUNC(void, DCM_CODE) GetSecurityLevel                   (void) = 0; \
      virtual FUNC(void, DCM_CODE) GetSesCtrlType                     (void) = 0; \
      virtual FUNC(void, DCM_CODE) GetActiveProtocol                  (void) = 0; \
      virtual FUNC(void, DCM_CODE) ResetToDefaultSession              (void) = 0; \
      virtual FUNC(void, DCM_CODE) TriggerOnEvent                     (void) = 0; \
      virtual FUNC(void, DCM_CODE) SetActiveDiagnostic                (void) = 0; \
      virtual FUNC(void, DCM_CODE) ServiceComM_NoServiceComModeEntered              (void) = 0; \
      virtual FUNC(void, DCM_CODE) ServiceComM_SilentServiceComModeEntered          (void) = 0; \
      virtual FUNC(void, DCM_CODE) ServiceComM_FullServiceComModeEntered            (void) = 0; \
      virtual FUNC(void, DCM_CODE) CallOut_ReadMemory                 (void) = 0; \
      virtual FUNC(void, DCM_CODE) CallOut_WriteMemory                (void) = 0; \
      virtual FUNC(void, DCM_CODE) CallOut_SetProgConditions          (void) = 0; \
      virtual FUNC(void, DCM_CODE) CallOut_GetProgConditions          (void) = 0; \
      virtual FUNC(void, DCM_CODE) CallOut_ProcessRequestTransferExit (void) = 0; \
      virtual FUNC(void, DCM_CODE) CallOut_ProcessRequestUpload       (void) = 0; \
      virtual FUNC(void, DCM_CODE) CallOut_ProcessRequestDownload     (void) = 0; \
      virtual FUNC(void, DCM_CODE) CallOut_ProcessRequestFileTransfer (void) = 0; \
      virtual FUNC(void, DCM_CODE) StartOfReception                   (void) = 0; \
      virtual FUNC(void, DCM_CODE) CopyRxData                         (void) = 0; \
      virtual FUNC(void, DCM_CODE) RxIndication                       (void) = 0; \
      virtual FUNC(void, DCM_CODE) CopyTxData                         (void) = 0; \
      virtual FUNC(void, DCM_CODE) TxConfirmation                     (void) = 0; \

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class class_ServiceDcm_Functionality{
   public:
      DCM_CORE_FUNCTIONALITIES_VIRTUAL
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

