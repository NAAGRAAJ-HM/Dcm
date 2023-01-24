#pragma once
/******************************************************************************/
/* File   : infServiceDcm_ServiceNvM.hpp                                      */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "infServiceDcmClient.hpp"

#if(STD_ON == _ReSIM)
#include <iostream>
using namespace std;
#else
#endif

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define CONSTSERVICEDCM_AR_RELEASE_VERSION_MAJOR                               4
#define CONSTSERVICEDCM_AR_RELEASE_VERSION_MINOR                               3
#define ServiceDcm_SizeinfServiceDcmClients                                   59

#define Const_DefaultInit_ConstServiceDcm                                                                                      \
   ,  {                                                                                                                        \
            {CONSTSERVICEDCM_AR_RELEASE_VERSION_MAJOR, CONSTSERVICEDCM_AR_RELEASE_VERSION_MINOR, 0x00,0xFF,0x01,'0','1','0'}   \
         ,  ServiceDcm_SizeinfServiceDcmClients                                                                                \
         ,  {                                                                                                                  \
                  &ApplSwcFoc                                                                                                  \
               ,  &ProjectARA                                                                                                  \
               ,  &ServiceBswM                                                                                                 \
               ,  &ServiceCanNm                                                                                                \
               ,  &ServiceCanSm                                                                                                \
               ,  &ServiceCom                                                                                                  \
               ,  &ServiceComM                                                                                                 \
               ,  &ServiceCsm                                                                                                  \
               ,  &ServiceDcm                                                                                                  \
               ,  &ServiceDem                                                                                                  \
               ,  &ServiceDet                                                                                                  \
               ,  &ServiceDlt                                                                                                  \
               ,  &ServiceEcuM                                                                                                 \
               ,  &ServiceFiM                                                                                                  \
               ,  &ServiceFrNm                                                                                                 \
               ,  &ServiceIpduM                                                                                                \
               ,  &ServiceNm                                                                                                   \
               ,  &ServiceNvM                                                                                                  \
               ,  &ServiceOs                                                                                                   \
               ,  &ServicePduR                                                                                                 \
               ,  &ServiceSchM                                                                                                 \
               ,  &ServiceSecOC                                                                                                \
               ,  &ServiceSokFm                                                                                                \
               ,  &ServiceStartUp                                                                                              \
               ,  &ServiceStbM                                                                                                 \
               ,  &ServiceSwcEcuM                                                                                              \
               ,  &ServiceSwcOs                                                                                                \
               ,  &ServiceVkms                                                                                                 \
               ,  &ServiceWdgM                                                                                                 \
               ,  &EcuabCanIf                                                                                                  \
               ,  &EcuabCanTp                                                                                                  \
               ,  &EcuabCryIf                                                                                                  \
               ,  &EcuabEthIf                                                                                                  \
               ,  &EcuabFee                                                                                                    \
               ,  &EcuabFrIf                                                                                                   \
               ,  &EcuabFrTp                                                                                                   \
               ,  &EcuabJ1939Tp                                                                                                \
               ,  &EcuabLinIf                                                                                                  \
               ,  &EcuabLinTp                                                                                                  \
               ,  &EcuabMemIf                                                                                                  \
               ,  &EcuabWdgIf                                                                                                  \
               ,  &McalAdc                                                                                                     \
               ,  &McalCan                                                                                                     \
               ,  &McalCry                                                                                                     \
               ,  &McalDio                                                                                                     \
               ,  &EcuabEa                                                                                                     \
               ,  &McalEep                                                                                                     \
               ,  &McalEth                                                                                                     \
               ,  &McalFls                                                                                                     \
               ,  &McalFr                                                                                                      \
               ,  &McalGpt                                                                                                     \
               ,  &McalIcu                                                                                                     \
               ,  &McalLin                                                                                                     \
               ,  &McalMcu                                                                                                     \
               ,  &McalOcu                                                                                                     \
               ,  &McalPort                                                                                                    \
               ,  &McalPwm                                                                                                     \
               ,  &McalSpi                                                                                                     \
               ,  &McalWdg                                                                                                     \
            }                                                                                                                  \
         ,  {                                                                                                                  \
                  "ApplSwcFoc"                                                                                                 \
               ,  "ProjectARA"                                                                                                 \
               ,  "ServiceBswM"                                                                                                \
               ,  "ServiceCanNm"                                                                                               \
               ,  "ServiceCanSm"                                                                                               \
               ,  "ServiceCom"                                                                                                 \
               ,  "ServiceComM"                                                                                                \
               ,  "ServiceCsm"                                                                                                 \
               ,  "ServiceDcm"                                                                                                 \
               ,  "ServiceDem"                                                                                                 \
               ,  "ServiceDet"                                                                                                 \
               ,  "ServiceDlt"                                                                                                 \
               ,  "ServiceEcuM"                                                                                                \
               ,  "ServiceFiM"                                                                                                 \
               ,  "ServiceFrNm"                                                                                                \
               ,  "ServiceIpduM"                                                                                               \
               ,  "ServiceNm"                                                                                                  \
               ,  "ServiceNvM"                                                                                                 \
               ,  "ServiceOs"                                                                                                  \
               ,  "ServicePduR"                                                                                                \
               ,  "ServiceSchM"                                                                                                \
               ,  "ServiceSecOC"                                                                                               \
               ,  "ServiceSokFm"                                                                                               \
               ,  "ServiceStartUp"                                                                                             \
               ,  "ServiceStbM"                                                                                                \
               ,  "ServiceSwcEcuM"                                                                                             \
               ,  "ServiceSwcOs"                                                                                               \
               ,  "ServiceVkms"                                                                                                \
               ,  "ServiceWdgM"                                                                                                \
               ,  "EcuabCanIf"                                                                                                 \
               ,  "EcuabCanTp"                                                                                                 \
               ,  "EcuabCryIf"                                                                                                 \
               ,  "EcuabEa"                                                                                                    \
               ,  "EcuabEthIf"                                                                                                 \
               ,  "EcuabFee"                                                                                                   \
               ,  "EcuabFrIf"                                                                                                  \
               ,  "EcuabFrTp"                                                                                                  \
               ,  "EcuabJ1939Tp"                                                                                               \
               ,  "EcuabLinIf"                                                                                                 \
               ,  "EcuabLinTp"                                                                                                 \
               ,  "EcuabMemIf"                                                                                                 \
               ,  "EcuabWdgIf"                                                                                                 \
               ,  "McalAdc"                                                                                                    \
               ,  "McalCan"                                                                                                    \
               ,  "McalCry"                                                                                                    \
               ,  "McalDio"                                                                                                    \
               ,  "McalEep"                                                                                                    \
               ,  "McalEth"                                                                                                    \
               ,  "McalFls"                                                                                                    \
               ,  "McalFr"                                                                                                     \
               ,  "McalGpt"                                                                                                    \
               ,  "McalIcu"                                                                                                    \
               ,  "McalLin"                                                                                                    \
               ,  "McalMcu"                                                                                                    \
               ,  "McalOcu"                                                                                                    \
               ,  "McalPwm"                                                                                                    \
               ,  "McalPort"                                                                                                   \
               ,  "McalSpi"                                                                                                    \
               ,  "McalWdg"                                                                                                    \
            }                                                                                                                  \
      }                                                                                                                        \

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(CONSTSERVICEDCM_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible CONSTSERVICEDCM_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(CONSTSERVICEDCM_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible CONSTSERVICEDCM_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

