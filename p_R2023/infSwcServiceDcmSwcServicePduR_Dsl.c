/******************************************************************************/
/* File   : infSwcServiceDcmSwcServicePduR_Dsl.c                              */
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

#include "infSwcServiceDcmSwcServicePduR.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
//TBD: Remove typedefs and include headers
typedef enum{
      BUFREQ_OK
   ,  BUFREQ_E_NOT_OK
   ,  BUFREQ_E_BUSY
   ,  BUFREQ_E_OVFL
}BufReq_ReturnType;

typedef enum{
      TP_DATACONF
   ,  TP_DATARETRY
   ,  TP_CONFPENDING
}TpDataStateType;

typedef uint16 PduIdType;
typedef uint16 PduLengthType;

typedef struct{
   uint8*        SduDataPtr;
   uint8*        MetaDataPtr;
   PduLengthType SduLength;
}PduInfoType;

typedef struct{
   TpDataStateType TpDataState;
   PduLengthType   TxTpDataCnt;
}RetryInfoType;

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
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

BufReq_ReturnType infSwcServiceDcmSwcServicePduR_CopyRxData(
            PduIdType      id
   ,  const PduInfoType*   PduInfoPtr
   ,        PduLengthType* bufferSizePtr
){
   return 0;
}

BufReq_ReturnType infSwcServiceDcmSwcServicePduR_CopyTxData(
            PduIdType      id
   ,  const PduInfoType*   info
   ,        RetryInfoType* retry
   ,        PduLengthType* availableDataPtr
){
   return 0;
}

BufReq_ReturnType infSwcServiceDcmSwcServicePduR_StartOfReception(
            PduIdType      id
   ,  const PduInfoType*   info
   ,        PduLengthType  TpSduLength
   ,        PduLengthType* bufferSizePtr
){
   return 0;
}

void infSwcServiceDcmSwcServicePduR_vTpRxIndication(
      PduIdType      id
   ,  Std_ReturnType result
){
}

void infSwcServiceDcmSwcServicePduR_vTpTxConfirmation(
      PduIdType      id
   ,  Std_ReturnType result
){
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

