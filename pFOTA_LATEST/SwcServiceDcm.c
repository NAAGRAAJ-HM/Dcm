#ifdef __cplusplus
extern "C"
{
#endif

#include "SwcServiceDcm.hpp"

#define cSidDiagSessionCtrl   0x10
#define cSidEcuReset          0x11
#define cSidSecAccess         0x27
#define cSidCommControl       0x28
#define cSidTesterPresent     0x3E
#define cSidCtrlDtcSetting    0x85
#define cSidRoutineControl    0x31
#define cSidReadDataByIdent   0x22
#define cSidWriteDataByIdent  0x2E

#define cSubFuncHardReset     0x01
#define cSubFuncSoftReset     0x03
#define cSubFuncHRwoResp      0x40
#define cSubFuncSRwoResp      0x41
#define cSubFuncResUDSTimer   0x4C

#define cDidModuleToProgram   0x0102u
#define cDidBootSwId          0xF180u
#define cDidApplSwId          0xF181u
#define cDidCalSwId           0xF182u
#define cDidBootSwFingerprint 0xF183u
#define cDidApplSwFingerprint 0xF184u
#define cDidAppCalFingerprint 0xF185u
#define cDidActiveSession     0xF186u
#define cDidSerialNumber      0xF18Cu
#define cDidVin               0xF190u
#define cDidRAJAHwPN        0xF191u
#define cDidProgImgBM         0xF010u
#define cDidProgImgBL         0xF011u
#define cDidProgImgBLUP       0xF012u
#define cDidProgImgRAMUP      0xF013u
#define cDidProgImgAPP1       0xF014u
#define cDidProgImgAPP2       0xF015u
#define cDidProgImgCAL        0xF016u
#define cDidProgImgRAMAPP     0xF019u
#define cDidKeyGenCounters    0xF017u
#define cDidManufSuppMode     0xF018u
#define cDidCompAndSwType     0x0101u
#define cDidGenealVerNumber   0xF110u
#define cDidBoardPartNumber   0xF112u
#define cDidBoardSerNumber    0xF113u
#define cDidGenealCrc         0xF116u
#define cDidGenealFull        0xF117u
#define cDidCalVersionNumber  0xF118u
#define cDidCalCrc            0xF119u
#define cDidCalBlock          0xF11Au
#define cDidEepBlockStatus    0xF11Bu
#define cDidAuxId             0xF11Cu
#define cDidModeId            0xF11Du

#define cRidSelfTest                0xF200u
#define cRidKeyExchange             0x0207u
#define cRidEraseMemory             0xFF00u
#define cRidAppHwidCheck            0x0401u
#define cRidCheckValidModule        0x0402u
#define cRidInitGenealogyBlock      0x0404u
#define cRidCompAndStoreSignature   0x0406u

#define NO_OF_SID     4
#define NO_OF_DID_RID 13

#if(SEED_KEY_ALGORITHM == SEED_KEY_USE_HMAC_SHA256)
static boolean DcmAuthenticationNeeded(uint8 ucSid, uint16 ushDidRid, uint8 ucRequestResponse);
static boolean DcmKeyExist(uint8* aucKey, uint8 ucLength);
static boolean DcmGetSubFunctionFromMessageBuffer(uint8 ucSID, const uint8* aucMessage, uint16* ushSubFunc);
static boolean DcmHashExist(uint8 ucSid, uint16 ushDidRid, uint32 ulServiceLength);
#endif

#include "hmac_sha2.hpp"
#include "EcuabFee_FblBlockInterface.hpp"
#include "version.hpp"
#include "fbl_diag_core.hpp"

extern uint16 FblDiagGetLengthOfDataForWdbi(uint16 ushDid);
extern uint16 FblDiagGetLengthOfDataForRoutineControl(uint16 ushRid);

#define MA_REQUEST 0
#define MA_RESPONSE 1
#define ROW_WITH_RIDS 2
#define COL_WITH_RID_REQUEST_ONlY 3

#if(SEED_KEY_ALGORITHM == SEED_KEY_USE_HMAC_SHA256)
static const uint16 aushAuthList[NO_OF_SID][NO_OF_DID_RID] = {
   { cSidReadDataByIdent     , cDidBootSwFingerprint, cDidApplSwFingerprint, cDidProgImgBL      , cDidProgImgAPP1  , cDidManufSuppMode   , cDidBoardPartNumber   , cDidBoardSerNumber       , cDidSerialNumber, cDidRAJAHwPN, cDidAuxId , cDidModeId, cDidVin }
   ,  { cSidWriteDataByIdent    , cDidBootSwFingerprint, cDidApplSwFingerprint, cDidModuleToProgram, cDidManufSuppMode, cDidBoardPartNumber , cDidBoardSerNumber    , cDidSerialNumber         , cDidRAJAHwPN  , cDidAuxId     , cDidModeId, cDidVin   , 0 }
   ,  { cSidRoutineControl      , cRidSelfTest         , cRidEraseMemory      , cRidKeyExchange    , cRidAppHwidCheck , cRidCheckValidModule, cRidInitGenealogyBlock, cRidCompAndStoreSignature, 0, 0, 0, 0, 0 }
   ,  { cSidEcuReset            , cSubFuncHardReset    , cSubFuncSoftReset    , cSubFuncHRwoResp   , cSubFuncSRwoResp , cSubFuncResUDSTimer , 0, 0, 0, 0, 0, 0, 0 }
};
#endif

uint8 DcmCheckMessageAuthentication(uint8 ucSid, const uint8* aucMessage, uint16 ushLength){
	uint8  ucRetVal = MSG_NO_AUTH_NEEDED;
#if(SEED_KEY_ALGORITHM == SEED_KEY_USE_HMAC_SHA256)
	uint8  aucHash[cSIZE_OF_HASH];
	uint8  aucKey[kEepSizeSecKey_UDSMSGKEY];
	uint16 ushSubFunc;
	uint8  i;
#endif

#ifdef DEBUG_IGNORE_MESSAGE_AUTHENTICATION
	ucRetVal = MSG_NO_AUTH_NEEDED;
#else
#if(SEED_KEY_ALGORITHM == SEED_KEY_USE_HMAC_SHA256)
	DcmGetSubFunctionFromMessageBuffer(ucSid, aucMessage, &ushSubFunc);
	if(DcmAuthenticationNeeded(ucSid, ushSubFunc, MA_REQUEST) == TRUE){
		if(DcmHashExist(ucSid, ushSubFunc, (uint32)ushLength) == TRUE){
			FEEFBL_GetUdsMsgKey(aucKey);
			if(DcmKeyExist(aucKey, kEepSizeSecKey_UDSMSGKEY) == TRUE){
				ushLength -= cSIZE_OF_HASH;
				hmac_sha256(aucKey, kEepSizeSecKey_UDSMSGKEY, aucMessage, ushLength, aucHash, cSIZE_OF_HASH);
				ucRetVal = MSG_AUTH_SUCCESSFUL;
				for(i = 0; i < cSIZE_OF_HASH; i++){
					if(aucMessage[ushLength + i] != aucHash[i]){
						ucRetVal = MSG_REJECTED;
					}
				}
			}
			else{
				ucRetVal = MSG_AUTH_SUCCESSFUL;
			}
		}
	}
#endif
#endif
	return ucRetVal;
}

uint8 DcmAppendMessageAuthentication(uint8 ucSid, uint8* aucMessage, uint32 ushLength){
	uint8 ucRetVal = 0;
#ifdef DEBUG_IGNORE_MESSAGE_AUTHENTICATION
	uint16 ushSubFunc;
	uint8 aucKey[kEepSizeSecKey_UDSMSGKEY];
	uint8 aucHash[cSIZE_OF_HASH] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	uint8 i;
	uint8 ucLocalSid = ucSid - 0x40;

	if(DcmGetSubFunctionFromMessageBuffer(ucLocalSid, (const uint8*)aucMessage, &ushSubFunc) == TRUE){
		if(DcmAuthenticationNeeded(ucLocalSid, ushSubFunc, MA_RESPONSE) == TRUE){
			FEEFBL_GetUdsMsgKey(aucKey);
			if(DcmKeyExist(aucKey, kEepSizeSecKey_UDSMSGKEY) == TRUE){
				hmac_sha256(aucKey, kEepSizeSecKey_UDSMSGKEY, aucMessage, ushLength, aucHash, cSIZE_OF_HASH);
				for(i = 0; i < cSIZE_OF_HASH; i++){
					aucMessage[ushLength + i] = aucHash[i];
				}
				ucRetVal = cSIZE_OF_HASH;
			}
		}
	}
#endif
	return ucRetVal;
}

#if(SEED_KEY_ALGORITHM == SEED_KEY_USE_HMAC_SHA256)
static boolean DcmGetSubFunctionFromMessageBuffer(uint8 ucSID, const uint8* aucMessage, uint16* ushSubFunc){
  boolean bRetVal = TRUE;

  switch(ucSID){
    case cSidReadDataByIdent:
    case cSidWriteDataByIdent:
      *ushSubFunc = (aucMessage[0] << 8) + aucMessage[1];
    break;

    case cSidRoutineControl:
      *ushSubFunc = (aucMessage[1] << 8) + aucMessage[2];
    break;

    case cSidEcuReset:
      *ushSubFunc = (uint16)aucMessage[0];
    break;

    default:
      *ushSubFunc = 0x0;
      bRetVal = FALSE;
    break;
  }

  return bRetVal;
}

static boolean DcmHashExist(uint8 ucSid, uint16 ushDidRid, uint32 ulServiceLength){
  uint32 ulDidDataLength;
  boolean bRetVal = FALSE;

  switch(ucSid){
    case cSidReadDataByIdent:
    if(ulServiceLength == 18){
      bRetVal = TRUE;
    }
    break;

    case cSidEcuReset:
    if(ulServiceLength == 17){
      bRetVal = TRUE;
    }
    break;

    case cSidRoutineControl:
    ulDidDataLength = FblDiagGetLengthOfDataForRoutineControl(ushDidRid);
    if((ulServiceLength >= 19) && ((ulDidDataLength + 16) == ulServiceLength)){
      bRetVal = TRUE;
    }
    break;

    case cSidWriteDataByIdent:
    ulDidDataLength = FblDiagGetLengthOfDataForWdbi(ushDidRid);
    if((ulServiceLength > 18) && ((ulDidDataLength + 16) == ulServiceLength)){
      bRetVal = TRUE;
    }
    break;

    default:
    break;
  }

  return bRetVal;
}

static boolean DcmAuthenticationNeeded(uint8 ucSid, uint16 ushDidRid, uint8 ucRequestResponse){
  uint8 i;
  uint8 j;
  boolean ucRetVal = FALSE;

  for(i=0; i<NO_OF_SID; i++){
    if(ucSid == aushAuthList[i][0]){
      for(j=0; j<NO_OF_DID_RID; j++)
      {
        if(ushDidRid == aushAuthList[i][j])
        {
          if((ucRequestResponse == MA_RESPONSE) && (i == ROW_WITH_RIDS) && (j >= COL_WITH_RID_REQUEST_ONlY))
          {
            ucRetVal = FALSE;
          }
          else
          {
            ucRetVal = TRUE;
          }
        }
      }
    }
  }

  return ucRetVal;
}

static boolean DcmKeyExist(uint8* aucKey, uint8 ucLength){
  uint8 i;
  boolean ucRetVal = FALSE;

  for(i=0; i<ucLength; i++){
    if(aucKey[i] != 0xff){
      ucRetVal = TRUE;
    }
  }

  return ucRetVal;
}
#endif

#ifdef __cplusplus
}
#endif
