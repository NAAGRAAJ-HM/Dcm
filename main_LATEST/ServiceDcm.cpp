/******************************************************************************/
/* File   : ServiceDcm.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "ServiceDcm.hpp"
#include "infServiceDcm_Imp.hpp"

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
VAR(module_ServiceDcm, DCM_VAR) ServiceDcm;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#if(STD_ON == _ReSIM)
FUNC(void, DCM_CODE) module_ServiceDcm::print_versions(
   void
){
   for(
      uint8 lu8Index = 0;
            lu8Index < lptrConst->u8SizeinfServiceDcmClients;
            lu8Index ++
   ){
      cout<<endl<<lptrConst->astrServiceDcmClientNames[lu8Index]<<"\t\tR";
      cout<<lptrConst->aptrServiceDcmClients[lu8Index]->VersionInfo.u8SwVersionMajor<<".";
      cout<<lptrConst->aptrServiceDcmClients[lu8Index]->VersionInfo.u8SwVersionMinor<<".";
      cout<<lptrConst->aptrServiceDcmClients[lu8Index]->VersionInfo.u8SwVersionPatch;
   }
}
#else
#endif

FUNC(void, DCM_CODE) module_ServiceDcm::InitFunction(
      CONSTP2CONST(ConstModule_TypeAbstract, DCM_CONST,       DCM_APPL_CONST) lptrConstModule
   ,  CONSTP2CONST(CfgModule_TypeAbstract,   DCM_CONFIG_DATA, DCM_APPL_CONST) lptrCfgModule
){
#if(STD_ON == ServiceDcm_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(
            (NULL_PTR != lptrConstModule)
         && (NULL_PTR != lptrCfgModule)
      ){
         lptrConst = (const ConstServiceDcm_Type*)lptrConstModule;
         lptrCfg   = lptrCfgModule;
      }
      else{
#if(STD_ON == ServiceDcm_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }
#if(STD_ON == ServiceDcm_InitCheck)
#if(STD_ON == _ReSIM)
//    print_versions();
#else
#endif
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == ServiceDcm_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  DCM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, DCM_CODE) module_ServiceDcm::DeInitFunction(
   void
){
#if(STD_ON == ServiceDcm_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == ServiceDcm_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == ServiceDcm_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  DCM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, DCM_CODE) module_ServiceDcm::MainFunction(
   void
){
#if(STD_ON == ServiceDcm_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == ServiceDcm_InitCheck)
   }
   else{
#if(STD_ON == ServiceDcm_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  DCM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, DCM_CODE) module_ServiceDcm::ServiceDemTriggerOnDtcStatus(
   void
){
}

FUNC(void, DCM_CODE) module_ServiceDcm::GetVin(
   void
){
}

FUNC(void, DCM_CODE) module_ServiceDcm::GetSecurityLevel(
   void
){
}

FUNC(void, DCM_CODE) module_ServiceDcm::GetSesCtrlType(
   void
){
}

FUNC(void, DCM_CODE) module_ServiceDcm::GetActiveProtocol(
   void
){
}

FUNC(void, DCM_CODE) module_ServiceDcm::ResetToDefaultSession(
   void
){
}

FUNC(void, DCM_CODE) module_ServiceDcm::TriggerOnEvent(
   void
){
}

FUNC(void, DCM_CODE) module_ServiceDcm::SetActiveDiagnostic(
   void
){
}

FUNC(void, DCM_CODE) module_ServiceDcm::ServiceComM_NoServiceComModeEntered(
   void
){
}

FUNC(void, DCM_CODE) module_ServiceDcm::ServiceComM_SilentServiceComModeEntered(
   void
){
}

FUNC(void, DCM_CODE) module_ServiceDcm::ServiceComM_FullServiceComModeEntered(
   void
){
}

FUNC(void, DCM_CODE) module_ServiceDcm::CallOut_ReadMemory(
   void
){
}

FUNC(void, DCM_CODE) module_ServiceDcm::CallOut_WriteMemory(
   void
){
}

FUNC(void, DCM_CODE) module_ServiceDcm::CallOut_SetProgConditions(
   void
){
}

FUNC(void, DCM_CODE) module_ServiceDcm::CallOut_GetProgConditions(
   void
){
}

FUNC(void, DCM_CODE) module_ServiceDcm::CallOut_ProcessRequestTransferExit(
   void
){
}

FUNC(void, DCM_CODE) module_ServiceDcm::CallOut_ProcessRequestUpload(
   void
){
}

FUNC(void, DCM_CODE) module_ServiceDcm::CallOut_ProcessRequestDownload(
   void
){
}

FUNC(void, DCM_CODE) module_ServiceDcm::CallOut_ProcessRequestFileTransfer(
   void
){
}

FUNC(void, DCM_CODE) module_ServiceDcm::StartOfReception(
   void
){
}

FUNC(void, DCM_CODE) module_ServiceDcm::CopyRxData(
   void
){
}

FUNC(void, DCM_CODE) module_ServiceDcm::RxIndication(
   void
){
}

FUNC(void, DCM_CODE) module_ServiceDcm::CopyTxData(
   void
){
}

FUNC(void, DCM_CODE) module_ServiceDcm::TxConfirmation(
   void
){
}

#include <cstring>
FUNC(void, DCM_CODE) infServiceDcmClient::GetVersionInfo(
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
#if(STD_ON == ServiceDcm_DevErrorDetect)
      ServiceDet_ReportError(
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

