#ifndef _INFSWCSERVICEDCMSWCSERVICECOMM_H
#define _INFSWCSERVICEDCMSWCSERVICECOMM_H
/******************************************************************************/
/* File   : infSwcServiceDcmSwcServiceComM.h                                  */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "CompilerCfg_SwcServiceDcm.h" //TBD: Move to SwcApplDcm
#include "CfgSwcServiceDcm.h"
#include "Types_SwcServiceDcm.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
typedef enum{ //TBD: ComM and all it's clients seem to have their own definitions of None/Silent/Full communication
      SwcApplDcmDsld_eModeComM_None
   ,  SwcApplDcmDsld_eModeComM_Silent
   ,  SwcApplDcmDsld_eModeComM_Full
}TypeSwcApplDcmDsld_eModeComM;

typedef struct{
   uint8                        u8IdChannelComM;
   TypeSwcApplDcmDsld_eModeComM eModeComM;
#if(CfgSwcServiceDcm_fAdaptiveDiagnostics != CfgSwcServiceDcm_dbDisable)
   Dcm_DslDsd_MediumType_ten    IdMedium;
#endif
}TypeSwcApplDcmDsld_stChannelComM;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
extern TypeSwcApplDcmDsld_stChannelComM SwcApplDcmDsld_ChannelComM[CfgSwcServiceDcmDsld_dNumChannelComM];

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
extern FUNC(void,    SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServiceComM_vFullComModeEntered   (uint8 NetworkId);
extern FUNC(void,    SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServiceComM_vNoComModeEntered     (uint8 NetworkId);
extern FUNC(void,    SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServiceComM_vSilentComModeEntered (uint8 NetworkId);
extern FUNC(boolean, SWCSERVICEDCM_CODE) SwcServiceDcmDsld_bIsModeComMChannelFull             (uint8 lu8IndexChannel);

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
#endif
