#pragma once
/******************************************************************************/
/* File   : ServiceDcm_core.hpp                                                      */
/*                                                                            */
/* Author : Nagaraja HULIYAPURADA MATA                                        */
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
/* All rights reserved. Copyright © 1982 Nagaraja HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* https://github.com/NagarajaHuliyapuradaMata?tab=repositories               */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "CompilerCfg_ServiceDcm.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define SERVICEDCM_CORE_FUNCTIONALITIES                                                  \
              FUNC(void, SERVICEDCM_CODE) ServiceDemTriggerOnDtcStatus              (void);     \
              FUNC(void, SERVICEDCM_CODE) GetVin                             (void);     \
              FUNC(void, SERVICEDCM_CODE) GetSecurityLevel                   (void);     \
              FUNC(void, SERVICEDCM_CODE) GetSesCtrlType                     (void);     \
              FUNC(void, SERVICEDCM_CODE) GetActiveProtocol                  (void);     \
              FUNC(void, SERVICEDCM_CODE) ResetToDefaultSession              (void);     \
              FUNC(void, SERVICEDCM_CODE) TriggerOnEvent                     (void);     \
              FUNC(void, SERVICEDCM_CODE) SetActiveDiagnostic                (void);     \
              FUNC(void, SERVICEDCM_CODE) ServiceComM_NoServiceComModeEntered              (void);     \
              FUNC(void, SERVICEDCM_CODE) ServiceComM_SilentServiceComModeEntered          (void);     \
              FUNC(void, SERVICEDCM_CODE) ServiceComM_FullServiceComModeEntered            (void);     \
              FUNC(void, SERVICEDCM_CODE) CallOut_ReadMemory                 (void);     \
              FUNC(void, SERVICEDCM_CODE) CallOut_WriteMemory                (void);     \
              FUNC(void, SERVICEDCM_CODE) CallOut_SetProgConditions          (void);     \
              FUNC(void, SERVICEDCM_CODE) CallOut_GetProgConditions          (void);     \
              FUNC(void, SERVICEDCM_CODE) CallOut_ProcessRequestTransferExit (void);     \
              FUNC(void, SERVICEDCM_CODE) CallOut_ProcessRequestUpload       (void);     \
              FUNC(void, SERVICEDCM_CODE) CallOut_ProcessRequestDownload     (void);     \
              FUNC(void, SERVICEDCM_CODE) CallOut_ProcessRequestFileTransfer (void);     \
              FUNC(void, SERVICEDCM_CODE) StartOfReception                   (void);     \
              FUNC(void, SERVICEDCM_CODE) CopyRxData                         (void);     \
              FUNC(void, SERVICEDCM_CODE) RxIndication                       (void);     \
              FUNC(void, SERVICEDCM_CODE) CopyTxData                         (void);     \
              FUNC(void, SERVICEDCM_CODE) TxConfirmation                     (void);     \

#define SERVICEDCM_CORE_FUNCTIONALITIES_VIRTUAL                                          \
      virtual FUNC(void, SERVICEDCM_CODE) ServiceDemTriggerOnDtcStatus              (void) = 0; \
      virtual FUNC(void, SERVICEDCM_CODE) GetVin                             (void) = 0; \
      virtual FUNC(void, SERVICEDCM_CODE) GetSecurityLevel                   (void) = 0; \
      virtual FUNC(void, SERVICEDCM_CODE) GetSesCtrlType                     (void) = 0; \
      virtual FUNC(void, SERVICEDCM_CODE) GetActiveProtocol                  (void) = 0; \
      virtual FUNC(void, SERVICEDCM_CODE) ResetToDefaultSession              (void) = 0; \
      virtual FUNC(void, SERVICEDCM_CODE) TriggerOnEvent                     (void) = 0; \
      virtual FUNC(void, SERVICEDCM_CODE) SetActiveDiagnostic                (void) = 0; \
      virtual FUNC(void, SERVICEDCM_CODE) ServiceComM_NoServiceComModeEntered              (void) = 0; \
      virtual FUNC(void, SERVICEDCM_CODE) ServiceComM_SilentServiceComModeEntered          (void) = 0; \
      virtual FUNC(void, SERVICEDCM_CODE) ServiceComM_FullServiceComModeEntered            (void) = 0; \
      virtual FUNC(void, SERVICEDCM_CODE) CallOut_ReadMemory                 (void) = 0; \
      virtual FUNC(void, SERVICEDCM_CODE) CallOut_WriteMemory                (void) = 0; \
      virtual FUNC(void, SERVICEDCM_CODE) CallOut_SetProgConditions          (void) = 0; \
      virtual FUNC(void, SERVICEDCM_CODE) CallOut_GetProgConditions          (void) = 0; \
      virtual FUNC(void, SERVICEDCM_CODE) CallOut_ProcessRequestTransferExit (void) = 0; \
      virtual FUNC(void, SERVICEDCM_CODE) CallOut_ProcessRequestUpload       (void) = 0; \
      virtual FUNC(void, SERVICEDCM_CODE) CallOut_ProcessRequestDownload     (void) = 0; \
      virtual FUNC(void, SERVICEDCM_CODE) CallOut_ProcessRequestFileTransfer (void) = 0; \
      virtual FUNC(void, SERVICEDCM_CODE) StartOfReception                   (void) = 0; \
      virtual FUNC(void, SERVICEDCM_CODE) CopyRxData                         (void) = 0; \
      virtual FUNC(void, SERVICEDCM_CODE) RxIndication                       (void) = 0; \
      virtual FUNC(void, SERVICEDCM_CODE) CopyTxData                         (void) = 0; \
      virtual FUNC(void, SERVICEDCM_CODE) TxConfirmation                     (void) = 0; \

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class class_ServiceDcm_Functionality{
   public:
      SERVICEDCM_CORE_FUNCTIONALITIES_VIRTUAL
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

