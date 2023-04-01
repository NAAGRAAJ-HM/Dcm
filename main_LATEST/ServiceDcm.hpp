#pragma once
/******************************************************************************/
/* File   : ServiceDcm.hpp                                                           */
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
#include "ConstServiceDcm.hpp"
#include "CfgServiceDcm.hpp"
#include "ServiceDcm_core.hpp"
#include "infServiceDcm_Exp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_ServiceDcm:
      INTERFACES_EXPORTED_SERVICEDCM
   ,  public abstract_module
   ,  public class_ServiceDcm_Functionality
{
   private:
/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
      const ConstServiceDcm_Type* lptrConst = (ConstServiceDcm_Type*)NULL_PTR;
      infServicePduRClient_Up infServicePduRClient_ServiceDcm;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
   private:
      FUNC(void, SERVICEDCM_CODE) print_versions (void);

   public:
      FUNC(void, SERVICEDCM_CODE) InitFunction(
            CONSTP2CONST(ConstModule_TypeAbstract, SERVICEDCM_CONST,       SERVICEDCM_APPL_CONST) lptrConstModule
         ,  CONSTP2CONST(CfgModule_TypeAbstract,   SERVICEDCM_CONFIG_DATA, SERVICEDCM_APPL_CONST) lptrCfgModule
      );
      FUNC(void, SERVICEDCM_CODE) DeInitFunction (void);
      FUNC(void, SERVICEDCM_CODE) MainFunction   (void);
      SERVICEDCM_CORE_FUNCTIONALITIES
};

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
extern VAR(module_ServiceDcm, SERVICEDCM_VAR) ServiceDcm;

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

