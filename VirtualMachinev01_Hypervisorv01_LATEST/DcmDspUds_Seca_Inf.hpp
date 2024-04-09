#pragma once

#include "Dcm.hpp"

#if(DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF)
#include "DcmCore_DslDsd_Prot.hpp"
#include "DcmDspUds_Uds_Prot.hpp"
#endif

#if( ( DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF ) && ( DCM_CFG_DSP_SECURITYACCESS_ENABLED != DCM_CFG_OFF ) )
#include "DcmAppl.hpp"

#if(DCM_CFG_IN_PARAM_MAXLEN > 0u)
#include "rba_BswSrv.hpp"
#endif

#endif
