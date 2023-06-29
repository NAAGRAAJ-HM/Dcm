#ifndef _INFSWCSERVICEDCMSWCSERVICESCHM_H
#define _INFSWCSERVICEDCMSWCSERVICESCHM_H
/******************************************************************************/
/* File   : infSwcServiceDcmSwcServiceSchM.h                                  */
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
extern FUNC(void, SWCSERVICEDCM_CODE) infSwcApplDcmSwcServiceSchM_vMainFunction            (void); //TBD: Move to infSwcApplDcmSwcServiceSchM.h
extern FUNC(void, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServiceSchM_vMainFunction         (void);
extern FUNC(void, SWCSERVICEDCM_CODE) infSwcApplDcmSwcServiceSchM_vRunnableIncNonceCounter (void);

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
#endif
