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
#include "CfgSwcServiceDcm.h"
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
typedef struct{
         uint8                                                u8NumProtocol;
         PduIdType                                            tNumIdPduTx;
         PduIdType                                            tIdPduTxType2Roe;
         PduIdType                                            tIdPduTxType2Rdpi;
         uint16                                               u16AddressTest;
         uint8                                                u8IndexChannel;
         uint8                                                u8IndexConnection;
         uint8                                                u8NumberPduTx;
}Type_SwcServiceDcmDsld_stConnection;

typedef uint8                                                 Type_SwcServiceDcmDsld_tMessageItem;
typedef Type_SwcServiceDcmDsld_tMessageItem*                  Type_SwcServiceDcmDsld_tMessage;
typedef uint32                                                Type_SwcServiceDcmDsld_tMessageLength;

typedef struct{
         Type_SwcServiceDcmDsld_tMessage                      tMessage;
         Type_SwcServiceDcmDsld_tMessage                      tMessageMainRx;
#if(CfgSwcServiceDcm_QueueBuffer != CfgSwcServiceDcm_Disable)
         Type_SwcServiceDcmDsld_tMessage                      tMessageReserveRx;
#endif
#if(CfgSwcServiceDcm_Roe != CfgSwcServiceDcm_Disable)
   const Type_SwcServiceDcmDsld_stInfoProtocolExtended*       ptrcstInfoProtocolExtendedRoe;
#endif
#if(CfgSwcServiceDcm_Rdpi != CfgSwcServiceDcm_Disable)
   const Type_SwcServiceDcmDsld_stInfoProtocolExtended*       ptrcstInfoProtocolExtendedRdpi;
#endif
         Type_SwcServiceDcmDsld_tMessageLength                tLengthMessageTx;
         Type_SwcServiceDcmDsld_tMessageLength                tLengthMessageRx;
#if(CfgSwcServiceDcm_BufferPaged != CfgSwcServiceDcm_Disable)
         Type_SwcServiceDcmDsld_tMessageLength                maxResponseLength_u32;
#endif
         uint32                                               u32DataTimerP2Adjust;
         uint32                                               u32DataTimerP2AdjustStart;
         uint8                                                u8IdProtocol;
         uint8                                                u8IdTableSid;
         uint8                                                u8LevelPreemption;
         uint8                                                u8IndexInfoPdu;
#if(CfgSwcServiceDcm_Kwp != CfgSwcServiceDcm_Disable)
         uint8                                                u8IndexTimingsLimit;
         uint8                                                u8IndexTimings;
#endif
#if(CfgSwcServiceDcm_PBcfg != CfgSwcServiceDcm_Disable)
         uint8                                                u8MaskConfig;
#endif
         uint8                                                u8IdClientDem;
         boolean                                              bNrc21;
         boolean                                              bBootResponsePending;
}Type_SwcServiceDcmDsld_stProtocol;

typedef uint8 Type_SwcServiceDcmDsld_tStatusOperationService;

typedef struct{
         uint8                                                u8TypeRequest;
         boolean                                              bResponsePositiveSuppress;
         uint8                                                u8RequestSource;
}Type_SwcServiceDcmDsld_stInfoAddMessage;

typedef uint8 Type_SwcServiceDcmDsld_tIdContext;

typedef struct{
         Type_SwcServiceDcmDsld_tMessage                      tMessageResponse;
         Type_SwcServiceDcmDsld_tMessage                      tMessageRequest;
         Type_SwcServiceDcmDsld_stInfoAddMessage              stInfoAddMessage;
         Type_SwcServiceDcmDsld_tMessageLength                tMessageLengthResponse;
         Type_SwcServiceDcmDsld_tMessageLength                tMessageLengthRequest;
         Type_SwcServiceDcmDsld_tMessageLength                tMaxMessageLengthResponse;
         Type_SwcServiceDcmDsld_tIdContext                    tIdContext;
         PduIdType                                            tIdPduRxDcm;
}Type_SwcServiceDcmDsld_stContextMessage;

typedef uint8 Type_SwcServiceDcmDsld_tCodeResponseNegative;
typedef boolean (*Type_SwcServiceDcmDsld_fptrRuleMode)(uint8* ptru8CodeResponseNegative);

typedef struct{
         uint32                                               u32AllowedSession;
         uint32                                               u32AllowedSecurity;
#if((CfgSwcServiceDcmDsld_ModeRuleSubService!=CfgSwcServiceDcm_Disable))
         Type_SwcServiceDcmDsld_fptrRuleMode                  fptrRuleMode;
#endif
         Std_ReturnType (*adrUserSubServiceModeRule_pfct)(
               Type_SwcServiceDcmDsld_tCodeResponseNegative*  ptrtCodeResponseNegative
            ,  uint8                                          u8IdService
            ,  uint8                                          u8IdSubService
         );
         Std_ReturnType (*SubFunc_fp)(
               Type_SwcServiceDcmDsld_tStatusOperationService tStatusOperationService
            ,  Type_SwcServiceDcmDsld_stContextMessage*       ptrstContextMessage
            ,  Type_SwcServiceDcmDsld_tCodeResponseNegative*  ptrtCodeResponseNegative
         );
         uint8                                                u8IdSubService;
         boolean                                              bIsSubServiceRdtcDsp;
}Type_SwcServiceDcmDsld_stSubService;

typedef uint8 Type_SwcServiceDcmDsld_tStatusConfirmation;

typedef void (*Type_SwcServiceDcmDsld_fptrApiConfirmation)(
               Type_SwcServiceDcmDsld_tIdContext              tIdContext
            ,  PduIdType                                      tIdPduRx
            ,  uint16                                         u16AddressSource
            ,  Type_SwcServiceDcmDsld_tStatusConfirmation     tStatusConfirmation
);

typedef struct{
         uint32                                               u32AllowedSession;
         uint32                                               u32AllowedSecurity;
#if((CfgSwcServiceDcmDsld_ModeRuleService != CfgSwcServiceDcm_Disable))
         Type_SwcServiceDcmDsld_fptrRuleMode                  fptrRuleMode;
#endif
         Std_ReturnType (*fptrHandlerService)(
               Type_SwcServiceDcmDsld_tStatusOperationService tStatusOperationService
            ,  Type_SwcServiceDcmDsld_stContextMessage*       ptrstContextMessage
            ,  Type_SwcServiceDcmDsld_tCodeResponseNegative*  ptrtCodeResponseNegative
         );
   void (*fptrServiceInit)(void);
         uint8                                                u8IdService;
         boolean                                              bIsExistSubService;
         boolean                                              bIsServiceLocator;
   const Type_SwcServiceDcmDsld_stSubService*                 ptrstTableSubService;
         uint8                                                u8NumberSubService;
         Std_ReturnType (*adrUserServiceModeRule_pfct)(
               Type_SwcServiceDcmDsld_tCodeResponseNegative*  ptrtCodeResponseNegative
            ,  uint8                                          u8IdService
         );
         Type_SwcServiceDcmDsld_fptrApiConfirmation           fptrServiceConfirmation;
}Type_SwcServiceDcmDsld_stService;

typedef struct{
   const Type_SwcServiceDcmDsld_stService*                    ptrcstTableService;
         uint8                                                u8NumberService;
         uint8                                                u8CodeResponseNegativeSessionNotSupported;
         uint8                                                u8IndexCDtc;
}Type_SwcServiceDcmDsld_stTableSid;

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
