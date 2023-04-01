#pragma once
/******************************************************************************/
/* File   : infServiceDcmClient.hpp                                                  */
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

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class infServiceDcmClient{
/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
   public:
      CONST(Std_TypeVersionInfo, SERVICEDCM_CONST) VersionInfo = { //TBD: remove const
            STD_AR_RELEASE_VERSION_MAJOR
         ,  STD_AR_RELEASE_VERSION_MINOR
         ,  0x00
         ,  0x00
         ,  0x01
         ,  '0'
         ,  '1'
         ,  '0'
      };

   public:
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
      FUNC(void, SERVICEDCM_CODE) GetVersionInfo(
         CONSTP2VAR(Std_TypeVersionInfo, SERVICEDCM_VAR, SERVICEDCM_CONST) lptrVersionInfo
      );
};

typedef FUNC(void, SERVICEDCM_CODE) (*fptrGetVersionInfo)(
   CONSTP2VAR(Std_TypeVersionInfo, SERVICEDCM_VAR, SERVICEDCM_CONST) lptrVersionInfo
);

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

