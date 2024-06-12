#pragma once
/******************************************************************************/
/* File   : infServiceDcm_ServiceNvM_Types.hpp                                */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "ReSim.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define ServiceDcm_SizeinfServiceDcmClients                                   59

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class NvM_BlocksRom_ServiceDcm_Type:
      public ConstModule_TypeAbstract
{
   public:
      uint8                u8SizeinfServiceDcmClients;
      infServiceDcmClient* aptrServiceDcmClients[ServiceDcm_SizeinfServiceDcmClients];
#if(STD_ON == _ReSIM)
      string               astrServiceDcmClientNames[ServiceDcm_SizeinfServiceDcmClients];
#else
#endif
};

class NvM_BlocksNv_ServiceDcm_Type:
      public CfgModule_TypeAbstract
{
};

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

