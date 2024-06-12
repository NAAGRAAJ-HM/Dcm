#ifndef _INFSWCSERVICEDCMSWCSERVICEPDUR_H
#define _INFSWCSERVICEDCMSWCSERVICEPDUR_H
/******************************************************************************/
/* File   : infSwcServiceDcmSwcServicePduR.h                                  */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
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
#define SwcServiceDcmDsld_eContextObd                                      TRUE
#define SwcServiceDcmDsld_eContextUds                                      FALSE
#define SwcServiceDcmDsld_dIdServiceValueDefault                         (0xFFu)

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
typedef struct{
   Type_StackCom_stInfoPdu stInfoPdu;
   uint8                   u8IdService;
   boolean                 bPduCopy;
}Type_SwcServiceDcmDsld_stInfoPduRxObd;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
#if(CfgSwcServiceDcm_fProcessingParallel != CfgSwcServiceDcm_dbDisable)
extern Type_SwcServiceDcmDsld_stInfoPduRxObd SwcServiceDcmDsld_astPduRxObd[CfgSwcServiceDcmDsld_dNumIdPduRx];
#endif

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
extern FUNC(Type_StackCom_eResultBufferRequest, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServicePduR_eCopyPduRx(
            Type_tIdPdu              id
   ,  const Type_StackCom_stInfoPdu* PduInfoPtr
   ,        Type_tLengthPdu*         bufferSizePtr
);

extern FUNC(Type_StackCom_eResultBufferRequest, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServicePduR_eCopyPduTx(
            Type_tIdPdu                id
   ,  const Type_StackCom_stInfoPdu*   info
   ,        Type_StackCom_stInfoRetry* retry
   ,        Type_tLengthPdu*           availableDataPtr
);

extern FUNC(Type_StackCom_eResultBufferRequest, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServicePduR_eStartReception(
            Type_tIdPdu              id
   ,  const Type_StackCom_stInfoPdu* info
   ,        Type_tLengthPdu          TptLengthSdu
   ,        Type_tLengthPdu*         bufferSizePtr
);

extern FUNC(void, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServicePduR_vTpRxIndication(
      Type_tIdPdu    id
   ,  Std_ReturnType result
);

extern FUNC(void, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServicePduR_vTpTxConfirmation(
      Type_tIdPdu    id
   ,  Std_ReturnType result
);

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
#endif
