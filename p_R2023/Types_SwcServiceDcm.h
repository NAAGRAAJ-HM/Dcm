#ifndef _TYPES_SWCSERVICEDCM_H
#define _TYPES_SWCSERVICEDCM_H
/******************************************************************************/
/* File   : Types_SwcServiceDcm.h                                             */
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
#include "Rte_Dcm_Type.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#ifndef DCM_E_PENDING
#define DCM_E_PENDING                                                        10u
#endif

#ifndef DCM_E_COMPARE_KEY_FAILED
#define DCM_E_COMPARE_KEY_FAILED                                              11
#endif

#ifndef DCM_E_SESSION_NOT_ALLOWED
#define DCM_E_SESSION_NOT_ALLOWED                                              4
#endif

#ifndef DCM_E_FORCE_RCRRP
#define DCM_E_FORCE_RCRRP           12
#endif

#ifndef DCM_E_PROTOCOL_NOT_ALLOWED
#define DCM_E_PROTOCOL_NOT_ALLOWED  5
#endif

#ifndef DCM_E_REQUEST_NOT_ACCEPTED
#define DCM_E_REQUEST_NOT_ACCEPTED  8
#endif

#ifndef DCM_E_REQUEST_ENV_NOK
#define DCM_E_REQUEST_ENV_NOK       9u
#endif

#ifndef DCM_E_RDBI_DATA_PENDING
#define DCM_E_RDBI_DATA_PENDING  14
#endif

#define DCM_PRV_AR_4_0_2                    0u              /* RTE Version AR 4.0.2 */
#define DCM_PRV_AR_4_0_2_HYBRID             1u              /* RTE Version AR 4.0.2 with some extensions from AR 4.0.3 */
#define DCM_PRV_AR_3_2_1                    2u              /* RTE version AR 3.2.1 */
#define DCM_PRV_AR_3_1_4                    3u              /* RTE version AR 3.1.4 */

#ifndef DCM_E_GENERALREJECT
#define DCM_E_GENERALREJECT 0x10
#endif

#ifndef DCM_E_SERVICENOTSUPPORTED
#define DCM_E_SERVICENOTSUPPORTED 0x11
#endif

#ifndef DCM_E_SUBFUNCTIONNOTSUPPORTED
#define DCM_E_SUBFUNCTIONNOTSUPPORTED 0x12u
#endif

#ifndef DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT
#define DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT 0x13
#endif

#ifndef DCM_E_RESPONSETOOLONG
#define DCM_E_RESPONSETOOLONG 0x14
#endif

#ifndef DCM_E_BUSYREPEATREQUEST
#define DCM_E_BUSYREPEATREQUEST 0x21
#endif

#ifndef DCM_E_CONDITIONSNOTCORRECT
#define DCM_E_CONDITIONSNOTCORRECT 0x22
#endif

#ifndef DCM_E_REQUESTSEQUENCEERROR
#define DCM_E_REQUESTSEQUENCEERROR 0x24
#endif

#ifndef DCM_E_NORESPONSEFROMSUBNETCOMPONENT
#define DCM_E_NORESPONSEFROMSUBNETCOMPONENT 0x25
#endif

#ifndef DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION
#define DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION 0x26
#endif

#ifndef DCM_E_REQUESTOUTOFRANGE
#define DCM_E_REQUESTOUTOFRANGE 0x31
#endif

#ifndef DCM_E_SECURITYACCESSDENIED
#define DCM_E_SECURITYACCESSDENIED 0x33
#endif

#ifndef DCM_E_INVALIDKEY
#define DCM_E_INVALIDKEY 0x35
#endif

#ifndef DCM_E_EXCEEDNUMBEROFATTEMPTS
#define DCM_E_EXCEEDNUMBEROFATTEMPTS 0x36
#endif

#ifndef DCM_E_REQUIREDTIMEDELAYNOTEXPIRED
#define DCM_E_REQUIREDTIMEDELAYNOTEXPIRED 0x37
#endif

#ifndef DCM_E_UPLOADDOWNLOADNOTACCEPTED
#define DCM_E_UPLOADDOWNLOADNOTACCEPTED 0x70
#endif

#ifndef DCM_E_TRANSFERDATASUSPENDED
#define DCM_E_TRANSFERDATASUSPENDED 0x71
#endif

#ifndef DCM_E_GENERALPROGRAMMINGFAILURE
#define DCM_E_GENERALPROGRAMMINGFAILURE 0x72
#endif

#ifndef DCM_E_WRONGBLOCKSEQUENCECOUNTER
#define DCM_E_WRONGBLOCKSEQUENCECOUNTER 0x73
#endif

#ifndef DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION
#define DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION 0x7E
#endif

#ifndef DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION
#define DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION 0x7F
#endif

#ifndef DCM_E_RPMTOOHIGH
#define DCM_E_RPMTOOHIGH 0x81
#endif

#ifndef DCM_E_RPMTOOLOW
#define DCM_E_RPMTOOLOW 0x82
#endif

#ifndef DCM_E_ENGINEISRUNNING
#define DCM_E_ENGINEISRUNNING 0x83
#endif

#ifndef DCM_E_ENGINEISNOTRUNNING
#define DCM_E_ENGINEISNOTRUNNING  0x84
#endif

#ifndef DCM_E_ENGINERUNTIMETOOLOW
#define DCM_E_ENGINERUNTIMETOOLOW 0x85
#endif

#ifndef DCM_E_TEMPERATURETOOHIGH
#define DCM_E_TEMPERATURETOOHIGH 0x86
#endif

#ifndef DCM_E_TEMPERATURETOOLOW
#define DCM_E_TEMPERATURETOOLOW 0x87
#endif

#ifndef DCM_E_VEHICLESPEEDTOOHIGH
#define DCM_E_VEHICLESPEEDTOOHIGH 0x88
#endif

#ifndef DCM_E_VEHICLESPEEDTOOLOW
#define DCM_E_VEHICLESPEEDTOOLOW 0x89
#endif

#ifndef DCM_E_THROTTLE_PEDALTOOHIGH
#define DCM_E_THROTTLE_PEDALTOOHIGH 0x8A
#endif

#ifndef DCM_E_THROTTLE_PEDALTOOLOW
#define DCM_E_THROTTLE_PEDALTOOLOW 0x8B
#endif

#ifndef DCM_E_TRANSMISSIONRANGENOTINNEUTRAL
#define DCM_E_TRANSMISSIONRANGENOTINNEUTRAL 0x8C
#endif

#ifndef DCM_E_TRANSMISSIONRANGENOTINGEAR
#define DCM_E_TRANSMISSIONRANGENOTINGEAR 0x8D
#endif

#ifndef DCM_E_BRAKESWITCH_NOTCLOSED
#define DCM_E_BRAKESWITCH_NOTCLOSED 0x8F
#endif

#ifndef DCM_E_SHIFTERLEVERNOTINPARK
#define DCM_E_SHIFTERLEVERNOTINPARK 0x90
#endif

#ifndef DCM_E_TORQUECONVERTERCLUTCHLOCKED
#define DCM_E_TORQUECONVERTERCLUTCHLOCKED 0x91
#endif

#ifndef DCM_E_VOLTAGETOOHIGH
#define DCM_E_VOLTAGETOOHIGH 0x92
#endif

#ifndef DCM_E_VOLTAGETOOLOW
#define DCM_E_VOLTAGETOOLOW 0x93
#endif

#ifndef DCM_INITIAL
#define DCM_INITIAL 0x00    /* Indicates the initial call to the operation */
#endif

#ifndef DCM_PENDING
#define DCM_PENDING 0x01    /* Indicates that a pending return has been done on the previous call of the operation */
#endif

#ifndef DCM_CANCEL
#define DCM_CANCEL  0x02    /* Indicates that the DCM requests to cancel the pending operation */
#endif

#ifndef DCM_FORCE_RCRRP_OK
#define DCM_FORCE_RCRRP_OK  0x03    /* Confirm a response pending transmission */
#endif


#ifndef DCM_CHECKDATA
#define DCM_CHECKDATA 0x04
#endif

#ifndef DCM_PROCESSSERVICE
#define DCM_PROCESSSERVICE  0x05
#endif


#ifndef     DCM_AR_4_0_2
#define     DCM_AR_4_0_2                DCM_PRV_AR_4_0_2
#endif
#ifndef     DCM_AR_4_0_2_HYBRID
#define     DCM_AR_4_0_2_HYBRID         DCM_PRV_AR_4_0_2_HYBRID
#endif
#ifndef     DCM_AR_3_2_1
#define     DCM_AR_3_2_1                DCM_PRV_AR_3_2_1
#endif

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

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
#endif

