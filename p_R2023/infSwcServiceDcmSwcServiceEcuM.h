#ifndef _INFSWCSERVICEDCMSWCSERVICEECUM_H
#define _INFSWCSERVICEDCMSWCSERVICEECUM_H
/******************************************************************************/
/* File   : infSwcServiceDcmSwcServiceEcuM.h                                  */
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
#include "CompilerCfg_SwcServiceDcm.h"
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
typedef struct{
   uint8 ConfigSetId;
}Dcm_ConfigType;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
extern const Type_SwcServiceDcmDsld_stConnection* SwcServiceDcmDsld_ptrcstTableConnection;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
extern FUNC(void, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServiceEcuM_vInitFunction(
   const Dcm_ConfigType* ConfigPtr
);

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
#endif
