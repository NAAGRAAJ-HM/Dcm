#pragma once
/******************************************************************************/
/* File   : ServiceDcm.hpp                                                    */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "infServiceDcm_ServiceNvM_Types.hpp"
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
      const ConstModule_TypeAbstract* lptrNvMBlocksRom = (ConstModule_TypeAbstract*)NULL_PTR;
      infServicePduRClient_Up infServicePduRClient_ServiceDcm;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
   private:
      FUNC(void, SERVICEDCM_CODE) print_versions (void);

   public:
      FUNC(void, SERVICEDCM_CODE) InitFunction(
            CONSTP2CONST(ConstModule_TypeAbstract, SERVICEDCM_CONST,       SERVICEDCM_APPL_CONST) lptrNvMBlocksRomModule
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

