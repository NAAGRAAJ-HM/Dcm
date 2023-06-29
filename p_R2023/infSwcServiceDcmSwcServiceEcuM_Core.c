/******************************************************************************/
/* File   : infSwcServiceDcmSwcServiceEcuM_Core.c                             */
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

#include "infSwcServiceDcmSwcServiceEcuM.h"
#include "PBcfgSwcServiceDcm.h"

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
const Type_SwcServiceDcmDsld_stConnection* SwcServiceDcmDsld_ptrcstTableConnection;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServiceEcuM_vInitFunction(
   const Dcm_ConfigType* ConfigPtr
){
#if(CfgSwcServiceDcm_PBcfg != CfgSwcServiceDcm_Disable)
   Dcm_ActiveConfigSet_Ptr = ConfigPtr;
#else
   (void)ConfigPtr;
#endif
   SwcServiceDcmDsld_ptrcstTableConnection     = CfgSwcServiceDcmDsld_cst.ptr_conntable_pcs;
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

