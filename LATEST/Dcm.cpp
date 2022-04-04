/******************************************************************************/
/* File   : Dcm.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "infDcm_EcuM.hpp"
#include "infDcm_Dcm.hpp"
#include "infDcm_SchM.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define DCM_AR_RELEASE_MAJOR_VERSION                                           4
#define DCM_AR_RELEASE_MINOR_VERSION                                           3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(DCM_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION)
   #error "Incompatible DCM_AR_RELEASE_MAJOR_VERSION!"
#endif

#if(DCM_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)
   #error "Incompatible DCM_AR_RELEASE_MINOR_VERSION!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_Dcm:
      public abstract_module
{
   public:
      module_Dcm(Std_TypeVersionInfo lVersionInfo) : abstract_module(lVersionInfo){
      }
      FUNC(void, DCM_CODE) InitFunction(
         CONSTP2CONST(CfgModule_TypeAbstract, DCM_CONFIG_DATA, DCM_APPL_CONST) lptrCfgModule
      );
      FUNC(void, DCM_CODE) DeInitFunction (void);
      FUNC(void, DCM_CODE) MainFunction   (void);
};

extern VAR(module_Dcm, DCM_VAR) Dcm;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
CONSTP2VAR(infEcuMClient, DCM_VAR, DCM_CONST) gptrinfEcuMClient_Dcm = &Dcm;
CONSTP2VAR(infDcmClient,  DCM_VAR, DCM_CONST) gptrinfDcmClient_Dcm  = &Dcm;
CONSTP2VAR(infSchMClient, DCM_VAR, DCM_CONST) gptrinfSchMClient_Dcm = &Dcm;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/
#include "CfgDcm.hpp"

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_Dcm, DCM_VAR) Dcm(
   {
         0x0000
      ,  0xFFFF
      ,  0x01
      ,  '0'
      ,  '1'
      ,  '0'
   }
);

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, DCM_CODE) module_Dcm::InitFunction(
   CONSTP2CONST(CfgModule_TypeAbstract, DCM_CONFIG_DATA, DCM_APPL_CONST) lptrCfgModule
){
#if(STD_ON == Dcm_InitCheck)
   if(E_OK == IsInitDone){
#if(STD_ON == Dcm_DevErrorDetect)
      Det_ReportError(
      );
#endif
   }
   else{
#endif
      if(NULL_PTR == lptrCfgModule){
#if(STD_ON == Dcm_DevErrorDetect)
         Det_ReportError(
         );
#endif
      }
      else{
// check lptrCfgModule for memory faults
// use PBcfg_Dcm as back-up configuration
      }
      IsInitDone = E_OK;
#if(STD_ON == Dcm_InitCheck)
   }
#endif
}

FUNC(void, DCM_CODE) module_Dcm::DeInitFunction(void){
#if(STD_ON == Dcm_InitCheck)
   if(E_OK != IsInitDone){
#if(STD_ON == Dcm_DevErrorDetect)
      Det_ReportError(
      );
#endif
   }
   else{
#endif
      IsInitDone = E_NOT_OK;
#if(STD_ON == Dcm_InitCheck)
   }
#endif
}

FUNC(void, DCM_CODE) module_Dcm::MainFunction(void){
#if(STD_ON == Dcm_InitCheck)
   if(E_OK != IsInitDone){
#if(STD_ON == Dcm_DevErrorDetect)
      Det_ReportError(
      );
#endif
   }
   else{
#endif
#if(STD_ON == Dcm_InitCheck)
   }
#endif
}

class class_Dcm_Unused{
   public:
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
};

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

#if(STD_ON == DCM_VERSION_INFO_API)
#include <cstring>
FUNC(void, DCM_CODE) infDcmClient::GetVersionInfo(
   CONSTP2VAR(Std_TypeVersionInfo, DCM_VAR, DCM_CONST) lptrVersionInfo
){
   if(NULL_PTR == lptrVersionInfo){
#if(STD_ON == Dcm_DevErrorDetect)
      Det_ReportError(
      );
#endif
   }
   else{
      memcpy(
            lptrVersionInfo
         ,  &VersionInfo
         ,  sizeof(VersionInfo)
      );
   }
}
#endif

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

