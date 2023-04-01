/******************************************************************************/
/* File   : ServiceDcm.cpp                                                    */
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
#include "Module.hpp"
#include "ServiceDcm.hpp"
#include "infServiceDcm_Imp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

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
VAR(module_ServiceDcm, SERVICEDCM_VAR) ServiceDcm;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#if(STD_ON == _ReSIM)
FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::print_versions(
   void
){
   for(
      uint8 lu8Index = 0;
            lu8Index < ((NvM_BlocksRom_ServiceDcm_Type*)lptrNvMBlocksRom)->u8SizeinfServiceDcmClients; // TBD: OOPS concept
            lu8Index ++
   ){
      cout<<endl<<((NvM_BlocksRom_ServiceDcm_Type*)lptrNvMBlocksRom)->astrServiceDcmClientNames[lu8Index]<<"\t\tR";
      cout<<((NvM_BlocksRom_ServiceDcm_Type*)lptrNvMBlocksRom)->aptrServiceDcmClients[lu8Index]->VersionInfo.u8SwVersionMajor<<".";
      cout<<((NvM_BlocksRom_ServiceDcm_Type*)lptrNvMBlocksRom)->aptrServiceDcmClients[lu8Index]->VersionInfo.u8SwVersionMinor<<".";
      cout<<((NvM_BlocksRom_ServiceDcm_Type*)lptrNvMBlocksRom)->aptrServiceDcmClients[lu8Index]->VersionInfo.u8SwVersionPatch;
   }
}
#else
#endif

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::InitFunction(
      CONSTP2CONST(ConstModule_TypeAbstract, SERVICEDCM_CONST,       SERVICEDCM_APPL_CONST) lptrNvMBlocksRomModule
   ,  CONSTP2CONST(CfgModule_TypeAbstract,   SERVICEDCM_CONFIG_DATA, SERVICEDCM_APPL_CONST) lptrCfgModule
){
#if(STD_ON == ServiceDcm_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(
            (NULL_PTR != lptrNvMBlocksRomModule)
         && (NULL_PTR != lptrCfgModule)
      ){
         lptrNvMBlocksRom = lptrNvMBlocksRomModule;
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
         ,  SERVICEDCM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::DeInitFunction(
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
         ,  SERVICEDCM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::MainFunction(
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
         ,  SERVICEDCM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::ServiceDemTriggerOnDtcStatus(
   void
){
}

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::GetVin(
   void
){
}

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::GetSecurityLevel(
   void
){
}

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::GetSesCtrlType(
   void
){
}

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::GetActiveProtocol(
   void
){
}

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::ResetToDefaultSession(
   void
){
}

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::TriggerOnEvent(
   void
){
}

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::SetActiveDiagnostic(
   void
){
}

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::ServiceComM_NoServiceComModeEntered(
   void
){
}

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::ServiceComM_SilentServiceComModeEntered(
   void
){
}

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::ServiceComM_FullServiceComModeEntered(
   void
){
}

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::CallOut_ReadMemory(
   void
){
}

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::CallOut_WriteMemory(
   void
){
}

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::CallOut_SetProgConditions(
   void
){
}

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::CallOut_GetProgConditions(
   void
){
}

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::CallOut_ProcessRequestTransferExit(
   void
){
}

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::CallOut_ProcessRequestUpload(
   void
){
}

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::CallOut_ProcessRequestDownload(
   void
){
}

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::CallOut_ProcessRequestFileTransfer(
   void
){
}

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::StartOfReception(
   void
){
}

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::CopyRxData(
   void
){
}

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::RxIndication(
   void
){
}

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::CopyTxData(
   void
){
}

FUNC(void, SERVICEDCM_CODE) module_ServiceDcm::TxConfirmation(
   void
){
}

#include <cstring>
FUNC(void, SERVICEDCM_CODE) infServiceDcmClient::GetVersionInfo(
   CONSTP2VAR(Std_TypeVersionInfo, SERVICEDCM_VAR, SERVICEDCM_CONST) lptrVersionInfo
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
         ,  SERVICEDCM_E_PARAM_POINTER
      );
#endif
   }
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

