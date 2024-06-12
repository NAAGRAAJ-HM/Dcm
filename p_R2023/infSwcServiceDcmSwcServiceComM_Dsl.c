/******************************************************************************/
/* File   : infSwcServiceDcmSwcServiceComM_Dsl.c                              */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
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

