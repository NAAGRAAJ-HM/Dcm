#ifndef _INFSWCSERVICEDCMSWCSERVICECOMM_H
#define _INFSWCSERVICEDCMSWCSERVICECOMM_H
/******************************************************************************/
/* File   : infSwcServiceDcmSwcServiceComM.h                                  */
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
/* All rights reserved. Copyright © 1982 Raajnaag HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* git@github.com:RaajnaagHuliyapuradaMata/<module_name>.git                  */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "CompilerCfg_SwcServiceDcm.h" //TBD: Move to SwcApplDcm
#include "CfgSwcServiceDcm.h"

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
#if(CfgSwcServiceDcm_EnableDiagAdapt != DCM_CFG_OFF)
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

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
extern FUNC(void, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServiceComM_vFullComModeEntered   (uint8 NetworkId);
extern FUNC(void, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServiceComM_vNoComModeEntered     (uint8 NetworkId);
extern FUNC(void, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServiceComM_vSilentComModeEntered (uint8 NetworkId);

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
#endif
