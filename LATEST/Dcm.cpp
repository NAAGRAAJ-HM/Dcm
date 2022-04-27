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
   if(E_OK == IsInitDone){
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
#endif
      if(NULL_PTR == lptrCfgModule){
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
         if(STD_LOW){
// check lptrCfgModule for memory faults
            lptrCfg = lptrCfgModule;
         }
         else{
// use PBcfgCanIf as back-up configuration
            lptrCfg = &PBcfgDcm;
         }
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
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
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
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
      );
#endif
   }
   else{
#endif
#if(STD_ON == Dcm_InitCheck)
   }
#endif
}

FUNC(void, DCM_CODE) class_Dcm_Functionality::DemTriggerOnDtcStatus(void){
}

FUNC(void, DCM_CODE) class_Dcm_Functionality::GetVin(void){
}

FUNC(void, DCM_CODE) class_Dcm_Functionality::GetSecurityLevel(void){
}

FUNC(void, DCM_CODE) class_Dcm_Functionality::GetSesCtrlType(void){
}

FUNC(void, DCM_CODE) class_Dcm_Functionality::GetActiveProtocol(void){
}

FUNC(void, DCM_CODE) class_Dcm_Functionality::ResetToDefaultSession(void){
}

FUNC(void, DCM_CODE) class_Dcm_Functionality::TriggerOnEvent(void){
}

FUNC(void, DCM_CODE) class_Dcm_Functionality::SetActiveDiagnostic(void){
}

FUNC(void, DCM_CODE) class_Dcm_Functionality::StartOfReception(void){
}

FUNC(void, DCM_CODE) class_Dcm_Functionality::CopyRxData(void){
}

FUNC(void, DCM_CODE) class_Dcm_Functionality::TpRxIndication(void){
}

FUNC(void, DCM_CODE) class_Dcm_Functionality::CopyTxData(void){
}

FUNC(void, DCM_CODE) class_Dcm_Functionality::TpTxConfirmation(void){
}

FUNC(void, DCM_CODE) class_Dcm_Functionality::TxConfirmation(void){
}

FUNC(void, DCM_CODE) class_Dcm_Functionality::ComM_NoComModeEntered(void){
}

FUNC(void, DCM_CODE) class_Dcm_Functionality::ComM_SilentComModeEntered(void){
}

FUNC(void, DCM_CODE) class_Dcm_Functionality::ComM_FullComModeEntered(void){
}

FUNC(void, DCM_CODE) class_Dcm_Functionality::CallOut_ReadMemory(void){
}

FUNC(void, DCM_CODE) class_Dcm_Functionality::CallOut_WriteMemory(void){
}

FUNC(void, DCM_CODE) class_Dcm_Functionality::CallOut_SetProgConditions(void){
}

FUNC(void, DCM_CODE) class_Dcm_Functionality::CallOut_GetProgConditions(void){
}

FUNC(void, DCM_CODE) class_Dcm_Functionality::CallOut_ProcessRequestTransferExit(void){
}

FUNC(void, DCM_CODE) class_Dcm_Functionality::CallOut_ProcessRequestUpload(void){
}

FUNC(void, DCM_CODE) class_Dcm_Functionality::CallOut_ProcessRequestDownload(void){
}

FUNC(void, DCM_CODE) class_Dcm_Functionality::CallOut_ProcessRequestFileTransfer(void){
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

