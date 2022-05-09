/******************************************************************************/
/* File   : Dcm.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "CfgDcm.hpp"
#include "Dcm_core.hpp"
#include "infDcm.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define DCM_AR_RELEASE_VERSION_MAJOR                                           4
#define DCM_AR_RELEASE_VERSION_MINOR                                           3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(DCM_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible DCM_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(DCM_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible DCM_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_Dcm:
      public abstract_module
   ,  public class_Dcm_Functionality
{
   private:
/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
            Std_TypeReturn          IsInitDone{E_NOT_OK};
      const CfgModule_TypeAbstract* lptrCfg{(CfgModule_TypeAbstract*)NULL_PTR};

   public:
      module_Dcm(Std_TypeVersionInfo lVersionInfo) : abstract_module(lVersionInfo){
      }
      FUNC(void, DCM_CODE) InitFunction(
         CONSTP2CONST(CfgModule_TypeAbstract, DCM_CONFIG_DATA, DCM_APPL_CONST) lptrCfgModule
      );
      FUNC(void, DCM_CODE) DeInitFunction (void);
      FUNC(void, DCM_CODE) MainFunction   (void);
      DCM_CORE_FUNCTIONALITIES
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

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_Dcm, DCM_VAR) Dcm(
   {
         DCM_AR_RELEASE_VERSION_MAJOR
      ,  DCM_AR_RELEASE_VERSION_MINOR
      ,  0x00
      ,  0xFF
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
   if(E_OK != IsInitDone){
#endif
      if(NULL_PTR != lptrCfgModule){
         if(STD_HIGH){
            lptrCfg = lptrCfgModule;
         }
         else{
            lptrCfg = &PBcfgDcm;
         }
      }
      else{
#if(STD_ON == Dcm_DevErrorDetect)
         Det_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }
#if(STD_ON == Dcm_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == Dcm_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  DCM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, DCM_CODE) module_Dcm::DeInitFunction(void){
#if(STD_ON == Dcm_InitCheck)
   if(E_OK == IsInitDone){
#endif
#if(STD_ON == Dcm_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == Dcm_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  DCM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, DCM_CODE) module_Dcm::MainFunction(void){
#if(STD_ON == Dcm_InitCheck)
   if(E_OK == IsInitDone){
#endif
#if(STD_ON == Dcm_InitCheck)
   }
   else{
#if(STD_ON == Dcm_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  DCM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, DCM_CODE) module_Dcm::DemTriggerOnDtcStatus(void){
}

FUNC(void, DCM_CODE) module_Dcm::GetVin(void){
}

FUNC(void, DCM_CODE) module_Dcm::GetSecurityLevel(void){
}

FUNC(void, DCM_CODE) module_Dcm::GetSesCtrlType(void){
}

FUNC(void, DCM_CODE) module_Dcm::GetActiveProtocol(void){
}

FUNC(void, DCM_CODE) module_Dcm::ResetToDefaultSession(void){
}

FUNC(void, DCM_CODE) module_Dcm::TriggerOnEvent(void){
}

FUNC(void, DCM_CODE) module_Dcm::SetActiveDiagnostic(void){
}

FUNC(void, DCM_CODE) module_Dcm::StartOfReception(void){
}

FUNC(void, DCM_CODE) module_Dcm::CopyRxData(void){
}

FUNC(void, DCM_CODE) module_Dcm::TpRxIndication(void){
}

FUNC(void, DCM_CODE) module_Dcm::CopyTxData(void){
}

FUNC(void, DCM_CODE) module_Dcm::TpTxConfirmation(void){
}

FUNC(void, DCM_CODE) module_Dcm::TxConfirmation(void){
}

FUNC(void, DCM_CODE) module_Dcm::ComM_NoComModeEntered(void){
}

FUNC(void, DCM_CODE) module_Dcm::ComM_SilentComModeEntered(void){
}

FUNC(void, DCM_CODE) module_Dcm::ComM_FullComModeEntered(void){
}

FUNC(void, DCM_CODE) module_Dcm::CallOut_ReadMemory(void){
}

FUNC(void, DCM_CODE) module_Dcm::CallOut_WriteMemory(void){
}

FUNC(void, DCM_CODE) module_Dcm::CallOut_SetProgConditions(void){
}

FUNC(void, DCM_CODE) module_Dcm::CallOut_GetProgConditions(void){
}

FUNC(void, DCM_CODE) module_Dcm::CallOut_ProcessRequestTransferExit(void){
}

FUNC(void, DCM_CODE) module_Dcm::CallOut_ProcessRequestUpload(void){
}

FUNC(void, DCM_CODE) module_Dcm::CallOut_ProcessRequestDownload(void){
}

FUNC(void, DCM_CODE) module_Dcm::CallOut_ProcessRequestFileTransfer(void){
}

#if(STD_ON == DCM_VERSION_INFO_API)
#include <cstring>
FUNC(void, DCM_CODE) infDcmClient::GetVersionInfo(
   CONSTP2VAR(Std_TypeVersionInfo, DCM_VAR, DCM_CONST) lptrVersionInfo
){
   if(NULL_PTR == lptrVersionInfo){
#if(STD_ON == Dcm_DevErrorDetect)
      Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
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

