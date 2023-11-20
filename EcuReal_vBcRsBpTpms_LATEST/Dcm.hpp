#pragma once

#include "ComStack_Types.hpp"
#include "Dcm_Cfg_DslDsd.hpp"
#include "Dcm_Types.hpp"
#include "DcmCore_DslDsd_Pub.hpp"
#include "Dcm_Cfg_DspUds.hpp"
#include "Dcm_Lcfg_DspUds.hpp"
#include "DcmDspUds_Uds_Pub.hpp"

#include "Dcm_Lcfg_DslDsd.hpp"

#define DCM_PRV_EXPORTAPI2LEGACY

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_GetVin (P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_SetActiveDiagnostic(VAR(boolean, AUTOMATIC) active);

extern Dcm_SrvOpStatusType Dcm_SrvOpstatus_u8;
