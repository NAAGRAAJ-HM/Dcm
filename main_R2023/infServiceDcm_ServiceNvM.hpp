#pragma once
/******************************************************************************/
/* File   : infServiceDcm_ServiceNvM.hpp                                      */
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
#include "infServiceDcmClient.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define ServiceDcm_SizeinfServiceDcmClients                                   59

#define NvM_InitBlocksRom_ServiceDcm                                                                                 \
   ,  {                                                                                                              \
            {SERVICEDCM_AR_RELEASE_VERSION_MAJOR, SERVICEDCM_AR_RELEASE_VERSION_MINOR, 0x00,0xFF,0x01,'0','1','0'}   \
         ,  ServiceDcm_SizeinfServiceDcmClients                                                                      \
         ,  {                                                                                                        \
                  &ApplSwcFoc                                                                                        \
               ,  &ProjectARA                                                                                        \
               ,  &ServiceBswM                                                                                       \
               ,  &ServiceCanNm                                                                                      \
               ,  &ServiceCanSm                                                                                      \
               ,  &ServiceCom                                                                                        \
               ,  &ServiceComM                                                                                       \
               ,  &ServiceCsm                                                                                        \
               ,  &ServiceDcm                                                                                        \
               ,  &ServiceDem                                                                                        \
               ,  &ServiceDet                                                                                        \
               ,  &ServiceDlt                                                                                        \
               ,  &ServiceEcuM                                                                                       \
               ,  &ServiceFiM                                                                                        \
               ,  &ServiceFrNm                                                                                       \
               ,  &ServiceIpduM                                                                                      \
               ,  &ServiceNm                                                                                         \
               ,  &ServiceNvM                                                                                        \
               ,  &ServiceOs                                                                                         \
               ,  &ServicePduR                                                                                       \
               ,  &ServiceSchM                                                                                       \
               ,  &ServiceSecOC                                                                                      \
               ,  &ServiceSokFm                                                                                      \
               ,  &ServiceStartUp                                                                                    \
               ,  &ServiceStbM                                                                                       \
               ,  &ServiceSwcEcuM                                                                                    \
               ,  &ServiceSwcOs                                                                                      \
               ,  &ServiceVkms                                                                                       \
               ,  &ServiceWdgM                                                                                       \
               ,  &EcuabCanIf                                                                                        \
               ,  &EcuabCanTp                                                                                        \
               ,  &EcuabCryIf                                                                                        \
               ,  &EcuabEthIf                                                                                        \
               ,  &EcuabFee                                                                                          \
               ,  &EcuabFrIf                                                                                         \
               ,  &EcuabFrTp                                                                                         \
               ,  &EcuabJ1939Tp                                                                                      \
               ,  &EcuabLinIf                                                                                        \
               ,  &EcuabLinTp                                                                                        \
               ,  &EcuabMemIf                                                                                        \
               ,  &EcuabWdgIf                                                                                        \
               ,  &McalAdc                                                                                           \
               ,  &McalCan                                                                                           \
               ,  &McalCry                                                                                           \
               ,  &McalDio                                                                                           \
               ,  &EcuabEa                                                                                           \
               ,  &McalEep                                                                                           \
               ,  &McalEth                                                                                           \
               ,  &McalFls                                                                                           \
               ,  &McalFr                                                                                            \
               ,  &McalGpt                                                                                           \
               ,  &McalIcu                                                                                           \
               ,  &McalLin                                                                                           \
               ,  &McalMcu                                                                                           \
               ,  &McalOcu                                                                                           \
               ,  &McalPort                                                                                          \
               ,  &McalPwm                                                                                           \
               ,  &McalSpi                                                                                           \
               ,  &McalWdg                                                                                           \
            }                                                                                                        \
         ,  {                                                                                                        \
                  "ApplSwcFoc"                                                                                       \
               ,  "ProjectARA"                                                                                       \
               ,  "ServiceBswM"                                                                                      \
               ,  "ServiceCanNm"                                                                                     \
               ,  "ServiceCanSm"                                                                                     \
               ,  "ServiceCom"                                                                                       \
               ,  "ServiceComM"                                                                                      \
               ,  "ServiceCsm"                                                                                       \
               ,  "ServiceDcm"                                                                                       \
               ,  "ServiceDem"                                                                                       \
               ,  "ServiceDet"                                                                                       \
               ,  "ServiceDlt"                                                                                       \
               ,  "ServiceEcuM"                                                                                      \
               ,  "ServiceFiM"                                                                                       \
               ,  "ServiceFrNm"                                                                                      \
               ,  "ServiceIpduM"                                                                                     \
               ,  "ServiceNm"                                                                                        \
               ,  "ServiceNvM"                                                                                       \
               ,  "ServiceOs"                                                                                        \
               ,  "ServicePduR"                                                                                      \
               ,  "ServiceSchM"                                                                                      \
               ,  "ServiceSecOC"                                                                                     \
               ,  "ServiceSokFm"                                                                                     \
               ,  "ServiceStartUp"                                                                                   \
               ,  "ServiceStbM"                                                                                      \
               ,  "ServiceSwcEcuM"                                                                                   \
               ,  "ServiceSwcOs"                                                                                     \
               ,  "ServiceVkms"                                                                                      \
               ,  "ServiceWdgM"                                                                                      \
               ,  "EcuabCanIf"                                                                                       \
               ,  "EcuabCanTp"                                                                                       \
               ,  "EcuabCryIf"                                                                                       \
               ,  "EcuabEa"                                                                                          \
               ,  "EcuabEthIf"                                                                                       \
               ,  "EcuabFee"                                                                                         \
               ,  "EcuabFrIf"                                                                                        \
               ,  "EcuabFrTp"                                                                                        \
               ,  "EcuabJ1939Tp"                                                                                     \
               ,  "EcuabLinIf"                                                                                       \
               ,  "EcuabLinTp"                                                                                       \
               ,  "EcuabMemIf"                                                                                       \
               ,  "EcuabWdgIf"                                                                                       \
               ,  "McalAdc"                                                                                          \
               ,  "McalCan"                                                                                          \
               ,  "McalCry"                                                                                          \
               ,  "McalDio"                                                                                          \
               ,  "McalEep"                                                                                          \
               ,  "McalEth"                                                                                          \
               ,  "McalFls"                                                                                          \
               ,  "McalFr"                                                                                           \
               ,  "McalGpt"                                                                                          \
               ,  "McalIcu"                                                                                          \
               ,  "McalLin"                                                                                          \
               ,  "McalMcu"                                                                                          \
               ,  "McalOcu"                                                                                          \
               ,  "McalPwm"                                                                                          \
               ,  "McalPort"                                                                                         \
               ,  "McalSpi"                                                                                          \
               ,  "McalWdg"                                                                                          \
            }                                                                                                        \
      }                                                                                                              \

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

