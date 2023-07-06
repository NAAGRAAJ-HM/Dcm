/******************************************************************************/
/* File   : infSwcServiceDcmSwcServiceComM_Dsl.c                              */
/*                                                                            */
/* Author : Raajnaag HULIYAPURADA MATA                                        */
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
/* All rights reserved. Copyright � 1982 Raajnaag HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* git@github.com:RaajnaagHuliyapuradaMata/<module_name>.git                  */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.h"

#include "CfgSwcServiceDcm.h"
#include "infSwcServiceDcmSwcServiceComM.h"
#include "CfgSwcServiceComM.h"

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
TypeSwcApplDcmDsld_stChannelComM SwcApplDcmDsld_ChannelComM[CfgSwcServiceDcmDsld_dNumChannelComM] = {
   {ComMConf_ComMChannel_ComMChannel_Can_Network_0_Channel, SwcApplDcmDsld_eModeComM_None}
};

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
static void vSetComMState(
      uint8                        lu8IdNetwork
   ,  TypeSwcApplDcmDsld_eModeComM leModeComM
){
   uint8 u8IndexNetwork;
   for(
      u8IndexNetwork = 0;
      u8IndexNetwork < CfgSwcServiceDcmDsld_dNumChannelComM;
      u8IndexNetwork ++
   ){
      if(SwcApplDcmDsld_ChannelComM[u8IndexNetwork].u8IdChannelComM == lu8IdNetwork){
         break;
      }
   }
   if(u8IndexNetwork < CfgSwcServiceDcmDsld_dNumChannelComM){
      SwcApplDcmDsld_ChannelComM[u8IndexNetwork].eModeComM = leModeComM;
   }
}

FUNC(void, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServiceComM_vFullComModeEntered(
   uint8 lu8IdNetwork
){
   vSetComMState(
         lu8IdNetwork
      ,  SwcApplDcmDsld_eModeComM_Full
   );
}

FUNC(void, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServiceComM_vNoComModeEntered(
   uint8 lu8IdNetwork
){
   vSetComMState(
         lu8IdNetwork
      ,  SwcApplDcmDsld_eModeComM_None
   );
}


FUNC(void, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServiceComM_vSilentComModeEntered(
   uint8 lu8IdNetwork
){
   vSetComMState(
         lu8IdNetwork
      ,  SwcApplDcmDsld_eModeComM_Silent
   );
}

FUNC(boolean, SWCSERVICEDCM_CODE) SwcServiceDcmDsld_bIsModeComMChannelFull(uint8 lu8IndexChannel){
   return(
      (
            SwcApplDcmDsld_eModeComM_Full
         == SwcApplDcmDsld_ChannelComM[lu8IndexChannel].eModeComM
      )
      ?  TRUE
      :  FALSE
   );
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

