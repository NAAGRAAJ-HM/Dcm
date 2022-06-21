#pragma once
/******************************************************************************/
/* File   : infDcm_PduR.hpp                                                   */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "CompilerCfg_Dcm.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class infDcm_PduR{
   public:
      virtual FUNC(void, DCM_CODE) StartOfReception (void) = 0;
      virtual FUNC(void, DCM_CODE) CopyRxData       (void) = 0;
      virtual FUNC(void, DCM_CODE) RxIndication     (void) = 0;
      virtual FUNC(void, DCM_CODE) CopyTxData       (void) = 0;
      virtual FUNC(void, DCM_CODE) TxConfirmation   (void) = 0;
};

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
extern CONSTP2VAR(infDcm_PduR, DCM_VAR, DCM_CONST) gptrinfDcm_PduR;

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

