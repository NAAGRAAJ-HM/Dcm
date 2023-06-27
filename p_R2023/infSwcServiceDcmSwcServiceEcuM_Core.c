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

#include "ComStack_Cfg.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
typedef struct{ //TBD: Remove typedef and include header
   uint8 ConfigSetId;
}Dcm_ConfigType;

#include "infSwcServiceDcmSwcServiceEcuM.h" //TBD: Move to include section

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
FUNC(void, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServiceEcuM_vInitFunction(
   const Dcm_ConfigType* ConfigPtr
){
   PduIdType idxPduIndex_u8;
   uint8     idxIndex_u8;
#if(DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
   Dcm_ActiveConfigSet_Ptr = ConfigPtr;
#else
   (void)ConfigPtr;
#endif
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

