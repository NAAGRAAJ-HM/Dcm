#ifndef _TYPES_SWCSERVICEDCM_H
#define _TYPES_SWCSERVICEDCM_H
/******************************************************************************/
/* File   : Types_SwcServiceDcm.h                                             */
/*                                                                            */
/* Author : Nagaraja HULIYAPURADA MATA                                        */
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
/* All rights reserved. Copyright © 1982 Nagaraja HULIYAPURADA MATA           */
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
#include "Types_StackCom.h"

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
         Type_tIdPdu                                          tNumIdPduTx;
         Type_tIdPdu                                          tIdPduTxType2Roe;
         Type_tIdPdu                                          tIdPduTxType2Rdpi;
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
#if(CfgSwcServiceDcm_fQueueBuffer != CfgSwcServiceDcm_dbDisable)
         Type_SwcServiceDcmDsld_tMessage                      tMessageReserveRx;
#endif
#if(CfgSwcServiceDcm_fRoe != CfgSwcServiceDcm_dbDisable)
   const Type_SwcServiceDcmDsld_stInfoProtocolExtended*       ptrcstInfoProtocolExtendedRoe;
#endif
#if(CfgSwcServiceDcm_fRdpi != CfgSwcServiceDcm_dbDisable)
   const Type_SwcServiceDcmDsld_stInfoProtocolExtended*       ptrcstInfoProtocolExtendedRdpi;
#endif
         Type_SwcServiceDcmDsld_tMessageLength                tLengthMessageTx;
         Type_SwcServiceDcmDsld_tMessageLength                tLengthMessageRx;
#if(CfgSwcServiceDcm_fPagedBuffer != CfgSwcServiceDcm_dbDisable)
         Type_SwcServiceDcmDsld_tMessageLength                maxResponseLength_u32;
#endif
         uint32                                               u32DataTimerP2Adjust;
         uint32                                               u32DataTimerP2AdjustStart;
         uint8                                                u8IdProtocol;
         uint8                                                u8IdTableSid;
         uint8                                                u8LevelPreemption;
         uint8                                                u8IndexInfoPdu;
#if(CfgSwcServiceDcm_fKwp != CfgSwcServiceDcm_dbDisable)
         uint8                                                u8IndexTimingsLimit;
         uint8                                                u8IndexTimings;
#endif
#if(CfgSwcServiceDcm_fPBcfg != CfgSwcServiceDcm_dbDisable)
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
         Type_tIdPdu                                          tIdPduRxDcm;
}Type_SwcServiceDcmDsld_stContextMessage;

typedef uint8 Type_SwcServiceDcmDsld_tCodeResponseNegative;
typedef boolean (*Type_SwcServiceDcmDsld_fptrRuleMode)(uint8* ptru8CodeResponseNegative);

typedef struct{
         uint32                                               u32AllowedSession;
         uint32                                               u32AllowedSecurity;
#if((CfgSwcServiceDcmDsld_fModeRuleSubService!=CfgSwcServiceDcm_dbDisable))
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
            ,  Type_tIdPdu                                    tIdPduRx
            ,  uint16                                         u16AddressSource
            ,  Type_SwcServiceDcmDsld_tStatusConfirmation     tStatusConfirmation
);

typedef struct{
         uint32                                               u32AllowedSession;
         uint32                                               u32AllowedSecurity;
#if((CfgSwcServiceDcmDsld_fModeRuleService != CfgSwcServiceDcm_dbDisable))
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

typedef struct{
         Type_StackCom_stInfoPdu                              stInfoPdu;
#if(CfgSwcServiceDcm_fQueueBuffer != CfgSwcServiceDcm_dbDisable)
         Type_SwcServiceDcmDsld_tMessage                      tMessage;
#endif
         uint8                                                u8IdService;
         boolean                                              bPresentTester;
         boolean                                              bPduCopy;
}Type_SwcServiceDcmDsld_stPduRxElement;

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
