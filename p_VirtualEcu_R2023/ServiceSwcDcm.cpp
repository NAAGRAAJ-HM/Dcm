/******************************************************************************/
/* File   : ServiceSwcDcm.cpp                                                 */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.hpp"

#include "ServiceSwcDcm.hpp"

#include "infServiceSwcDcmServiceSwcEcuM.hpp"
#include "infServiceSwcDcmServiceSwcPduR.hpp"

#include "CfgServiceSwcDcm.hpp"
#include "LibAutosarFifo.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define ServiceSwcDcm_dIndexService                                            1

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
const CfgServiceSwcDcm_tst* ServiceSwcDcm_pstConfig;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
LibAutosarFifo_t     ServiceSwcDcm_stFifoRequestUds;
LibAutosarFifo_tItem ServiceSwcDcm_atBuffer[CfgServiceSwcDcm_dNumMaxRequests];

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, SERVICESWCDCM_CODE) infServiceSwcDcmServiceSwcEcuM_InitFunction(const CfgServiceSwcDcm_tst* pstConfig){
   ServiceSwcDcm_pstConfig = pstConfig;
   (void)LibAutosarFifo_InitFunction( //TBD: Handle not OK cases
         &ServiceSwcDcm_stFifoRequestUds
      ,  &ServiceSwcDcm_atBuffer[0]
      ,  CfgServiceSwcDcm_dNumMaxRequests
   );

}

FUNC(void, SERVICESWCDCM_CODE) infServiceSwcDcmServiceSwcEcuM_DeInitFunction(void){}

FUNC(void, SERVICESWCDCM_CODE) infServiceSwcDcmServiceSwcSchM_MainFunction(void){
   uint8 lu8IndexBufferRx;
   while(
         LibAutosarFifo_eStatus_OK
      == LibAutosarFifo_Get(&ServiceSwcDcm_stFifoRequestUds, &lu8IndexBufferRx)
   ){
      switch( //TBD: Configurable SID table
         McalCan_astRxFifio[lu8IndexBufferRx].McalCan_stFrameExtended.data[ServiceSwcDcm_dIndexService] //TBD: Reduce complexity using unions of higher layers and Fifo APIs
      ){
         case 0x3E: //TBF: Implement tester present service handle here
            break;
      }
   }
}

FUNC(void, SERVICESWCDCM_CODE) infServiceSwcDcmServiceSwcPduR_RxIndication(uint8 lu8IndexBufferRx){
   (void)LibAutosarFifo_Put(&ServiceSwcDcm_stFifoRequestUds, lu8IndexBufferRx); //TBD: Handle not OK cases
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

