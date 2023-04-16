/******************************************************************************/
/* File   : SwcServiceDcm.cpp                                                 */
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
/* https://github.com/RaajnaagHuliyapuradaMata?tab=repositories               */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.hpp"

#include "SwcServiceDcm.hpp"

#include "infSwcServiceDcmSwcServiceEcuM.hpp"
#include "infSwcServiceDcmSwcServicePduR.hpp"

#include "CfgSwcServiceDcm.hpp"
#include "LibAutosarFifo.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define SwcServiceDcm_dIndexService                                            1

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
const CfgSwcServiceDcm_tst* SwcServiceDcm_pstConfig;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
LibAutosarFifo_t     SwcServiceDcm_stFifoRequestUds;
LibAutosarFifo_tItem SwcServiceDcm_atBuffer[CfgSwcServiceDcm_dNumMaxRequests];

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
static const uint32 cu32MaxTimerP2 = 5000;
static       uint32 u32TimerP2;
static void TimerP2_Init     (void){u32TimerP2 = 0;}
static void TimerP2_ReStart  (void){u32TimerP2 = cu32MaxTimerP2;/*Start current protocol*/}
static void TimerP2_Runnable (void){if(0 == --u32TimerP2){/*Stop current protocol*/}}

FUNC(void, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServiceEcuM_InitFunction(const CfgSwcServiceDcm_tst* pstConfig){
   SwcServiceDcm_pstConfig = pstConfig;
   (void)LibAutosarFifo_InitFunction( //TBD: Handle not OK cases
         &SwcServiceDcm_stFifoRequestUds
      ,  &SwcServiceDcm_atBuffer[0]
      ,  CfgSwcServiceDcm_dNumMaxRequests
   );
   TimerP2_Init();
}

FUNC(void, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServiceEcuM_DeInitFunction(void){}

FUNC(void, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServiceSchM_MainFunction(void){
   TimerP2_Runnable();
   uint8 lu8IndexBufferRx;
   while(
         LibAutosarFifo_eStatus_OK
      == LibAutosarFifo_Get(&SwcServiceDcm_stFifoRequestUds, &lu8IndexBufferRx)
   ){
      TimerP2_ReStart();
      switch( //TBD: Configurable SID table
         McalCan_astRxFifio[lu8IndexBufferRx].McalCan_stFrameExtended.data[SwcServiceDcm_dIndexService] //TBD: Reduce complexity using unions of higher layers and Fifo APIs
      ){
         case 0x3E: //TBF: Implement tester present service handle here
            break;
      }
   }
}

FUNC(void, SWCSERVICEDCM_CODE) infSwcServiceDcmSwcServicePduR_RxIndication(uint8 lu8IndexBufferRx){
   (void)LibAutosarFifo_Put(&SwcServiceDcm_stFifoRequestUds, lu8IndexBufferRx); //TBD: Handle not OK cases
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

