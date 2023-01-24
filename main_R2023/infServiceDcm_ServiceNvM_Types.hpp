#pragma once
/******************************************************************************/
/* File   : infServiceDcm_ServiceNvM_Types.hpp                                */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define ServiceDcm_SizeinfServiceDcmClients                                   59

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class ConstServiceDcm_Type:
      public ConstModule_TypeAbstract
{
/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
   public:
      uint8                u8SizeinfServiceDcmClients;
      infServiceDcmClient* aptrServiceDcmClients[ServiceDcm_SizeinfServiceDcmClients];
#if(STD_ON == _ReSIM)
      string               astrServiceDcmClientNames[ServiceDcm_SizeinfServiceDcmClients];
#else
#endif
};

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

