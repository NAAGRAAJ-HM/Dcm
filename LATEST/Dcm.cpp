/******************************************************************************/
/* File   : Dcm.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "Dcm.hpp"
#include "infDcm_Imp.hpp"

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

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_Dcm, DCM_VAR) Dcm;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#if(STD_ON == _ReSIM)
FUNC(void, DCM_CODE) module_Dcm::print_versions(
   void
){
   for(
      uint8 lu8Index = 0;
            lu8Index < lptrConst->u8SizeinfDcmClients;
            lu8Index ++
   ){
      cout<<endl<<lptrConst->astrDcmClientNames[lu8Index]<<"\t\tR";
      cout<<lptrConst->aptrDcmClients[lu8Index]->VersionInfo.u8SwVersionMajor<<".";
      cout<<lptrConst->aptrDcmClients[lu8Index]->VersionInfo.u8SwVersionMinor<<".";
      cout<<lptrConst->aptrDcmClients[lu8Index]->VersionInfo.u8SwVersionPatch;
   }
}
#else
#endif

FUNC(void, DCM_CODE) module_Dcm::InitFunction(
      CONSTP2CONST(ConstModule_TypeAbstract, DCM_CONST,       DCM_APPL_CONST) lptrConstModule
   ,  CONSTP2CONST(CfgModule_TypeAbstract,   DCM_CONFIG_DATA, DCM_APPL_CONST) lptrCfgModule
){
#if(STD_ON == Dcm_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(
            (NULL_PTR != lptrConstModule)
         && (NULL_PTR != lptrCfgModule)
      ){
         lptrConst = lptrConstModule;
         lptrCfg   = lptrCfgModule;
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
#if(STD_ON == _ReSIM)
      print_versions();
#else
#endif
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

FUNC(void, DCM_CODE) module_Dcm::DeInitFunction(
   void
){
#if(STD_ON == Dcm_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
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

FUNC(void, DCM_CODE) module_Dcm::MainFunction(
   void
){
#if(STD_ON == Dcm_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
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

FUNC(void, DCM_CODE) module_Dcm::DemTriggerOnDtcStatus(
   void
){
}

FUNC(void, DCM_CODE) module_Dcm::GetVin(
   void
){
}

FUNC(void, DCM_CODE) module_Dcm::GetSecurityLevel(
   void
){
}

FUNC(void, DCM_CODE) module_Dcm::GetSesCtrlType(
   void
){
}

FUNC(void, DCM_CODE) module_Dcm::GetActiveProtocol(
   void
){
}

FUNC(void, DCM_CODE) module_Dcm::ResetToDefaultSession(
   void
){
}

FUNC(void, DCM_CODE) module_Dcm::TriggerOnEvent(
   void
){
}

FUNC(void, DCM_CODE) module_Dcm::SetActiveDiagnostic(
   void
){
}

FUNC(void, DCM_CODE) module_Dcm::ComM_NoComModeEntered(
   void
){
}

FUNC(void, DCM_CODE) module_Dcm::ComM_SilentComModeEntered(
   void
){
}

FUNC(void, DCM_CODE) module_Dcm::ComM_FullComModeEntered(
   void
){
}

FUNC(void, DCM_CODE) module_Dcm::CallOut_ReadMemory(
   void
){
}

FUNC(void, DCM_CODE) module_Dcm::CallOut_WriteMemory(
   void
){
}

FUNC(void, DCM_CODE) module_Dcm::CallOut_SetProgConditions(
   void
){
}

FUNC(void, DCM_CODE) module_Dcm::CallOut_GetProgConditions(
   void
){
}

FUNC(void, DCM_CODE) module_Dcm::CallOut_ProcessRequestTransferExit(
   void
){
}

FUNC(void, DCM_CODE) module_Dcm::CallOut_ProcessRequestUpload(
   void
){
}

FUNC(void, DCM_CODE) module_Dcm::CallOut_ProcessRequestDownload(
   void
){
}

FUNC(void, DCM_CODE) module_Dcm::CallOut_ProcessRequestFileTransfer(
   void
){
}

FUNC(void, DCM_CODE) module_Dcm::StartOfReception(
   void
){
}

FUNC(void, DCM_CODE) module_Dcm::CopyRxData(
   void
){
}

FUNC(void, DCM_CODE) module_Dcm::RxIndication(
   void
){
}

FUNC(void, DCM_CODE) module_Dcm::CopyTxData(
   void
){
}

FUNC(void, DCM_CODE) module_Dcm::TxConfirmation(
   void
){
}

#include <cstring>
FUNC(void, DCM_CODE) infDcmClient::GetVersionInfo(
   CONSTP2VAR(Std_TypeVersionInfo, DCM_VAR, DCM_CONST) lptrVersionInfo
){
   if(
         NULL_PTR
      != lptrVersionInfo
   ){
      memcpy(
            lptrVersionInfo
         ,  &VersionInfo
         ,  sizeof(VersionInfo)
      );
   }
   else{
#if(STD_ON == Dcm_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  DCM_E_PARAM_POINTER
      );
#endif
   }
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

