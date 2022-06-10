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
#include "infDcm_Exp.hpp"
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
class module_Dcm:
      INTERFACES_EXPORTED_DCM
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
const infDcmClient* gaptrDcmClients[] = {
      gptrinfDcmClient_CanIf
   ,  gptrinfDcmClient_CanTp
   ,  gptrinfDcmClient_CryIf
   ,  gptrinfDcmClient_Ea
   ,  gptrinfDcmClient_EthIf
   ,  gptrinfDcmClient_Fee
   ,  gptrinfDcmClient_FrIf
   ,  gptrinfDcmClient_LinIf
   ,  gptrinfDcmClient_LinTp
   ,  gptrinfDcmClient_MemIf
   ,  gptrinfDcmClient_WdgIf
   ,  gptrinfDcmClient_Adc
   ,  gptrinfDcmClient_Can
   ,  gptrinfDcmClient_Cry
   ,  gptrinfDcmClient_Dio
   ,  gptrinfDcmClient_Eep
   ,  gptrinfDcmClient_Eth
   ,  gptrinfDcmClient_Fls
   ,  gptrinfDcmClient_Fr
   ,  gptrinfDcmClient_Gpt
   ,  gptrinfDcmClient_Icu
   ,  gptrinfDcmClient_Lin
   ,  gptrinfDcmClient_Mcu
   ,  gptrinfDcmClient_Ocu
   ,  gptrinfDcmClient_Port
   ,  gptrinfDcmClient_Pwm
   ,  gptrinfDcmClient_Spi
   ,  gptrinfDcmClient_Wdg
   ,  gptrinfDcmClient_BswM
   ,  gptrinfDcmClient_Com
   ,  gptrinfDcmClient_ComM
   ,  gptrinfDcmClient_Csm
   ,  gptrinfDcmClient_Dcm
   ,  gptrinfDcmClient_Dem
   ,  gptrinfDcmClient_Det
   ,  gptrinfDcmClient_EcuM
   ,  gptrinfDcmClient_FiM
   ,  gptrinfDcmClient_Nm
   ,  gptrinfDcmClient_NvM
   ,  gptrinfDcmClient_Os
   ,  gptrinfDcmClient_PduR
   ,  gptrinfDcmClient_SchM
   ,  gptrinfDcmClient_SecOC
   ,  gptrinfDcmClient_SokFm
   ,  gptrinfDcmClient_StartUp
   ,  gptrinfDcmClient_StbM
   ,  gptrinfDcmClient_Vkms
   ,  gptrinfDcmClient_WdgM
   ,  gptrinfDcmClient_Rte
   ,  gptrinfDcmClient_SwcApplFoc
   ,  gptrinfDcmClient_SwcServiceEcuM
   ,  gptrinfDcmClient_SwcServiceOs
};

#if(STD_ON == _ReSIM)
#include <iostream>
using namespace std;
static const string lstrDcmClientNames[] = {
      "CanIf"
   ,  "CanTp"
   ,  "CryIf"
   ,  "Ea"
   ,  "EthIf"
   ,  "Fee"
   ,  "FrIf"
   ,  "LinIf"
   ,  "LinTp"
   ,  "MemIf"
   ,  "WdgIf"
   ,  "Adc"
   ,  "Can"
   ,  "Cry"
   ,  "Dio"
   ,  "Eep"
   ,  "Eth"
   ,  "Fls"
   ,  "Fr"
   ,  "Gpt"
   ,  "Icu"
   ,  "Lin"
   ,  "Mcu"
   ,  "Ocu"
   ,  "Port"
   ,  "Pwm"
   ,  "Spi"
   ,  "Wdg"
   ,  "BswM"
   ,  "Com"
   ,  "ComM"
   ,  "Csm"
   ,  "Dcm"
   ,  "Dem"
   ,  "Det"
   ,  "EcuM"
   ,  "FiM"
   ,  "Nm"
   ,  "NvM"
   ,  "Os"
   ,  "PduR"
   ,  "SchM"
   ,  "SecOC"
   ,  "SokFm"
   ,  "StartUp"
   ,  "StbM"
   ,  "Vkms"
   ,  "WdgM"
   ,  "Rte"
   ,  "SwcApplFoc"
   ,  "SwcServiceEcuM"
   ,  "SwcServiceOs"
};

void print_modules_version(void){
   for(
      uint8 lu8Index = 0;
            lu8Index < sizeof(gaptrDcmClients)/sizeof(infDcmClient*);
            lu8Index ++
   ){
      cout<<endl<<lstrDcmClientNames[lu8Index]<<"\t\tR";
      cout<<gaptrDcmClients[lu8Index]->VersionInfo.SwVersionMajor<<".";
      cout<<gaptrDcmClients[lu8Index]->VersionInfo.SwVersionMinor<<".";
      cout<<gaptrDcmClients[lu8Index]->VersionInfo.SwVersionPatch;
   }
}
#else
#endif

FUNC(void, DCM_CODE) module_Dcm::InitFunction(
   CONSTP2CONST(CfgModule_TypeAbstract, DCM_CONFIG_DATA, DCM_APPL_CONST) lptrCfgModule
){
#if(STD_ON == Dcm_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
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
#if(STD_ON == _ReSIM)
      print_modules_version();
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

FUNC(void, DCM_CODE) module_Dcm::DeInitFunction(void){
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

FUNC(void, DCM_CODE) module_Dcm::MainFunction(void){
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
#endif

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

