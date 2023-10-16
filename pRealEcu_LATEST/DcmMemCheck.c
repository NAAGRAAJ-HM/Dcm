#include "Std_Types.hpp"

#include "DcmMemCheck.hpp"
#include "LibAutosar_Crc.hpp"
#include "version.hpp"

extern boolean DcmVerifyApplicationMemory(void){
  tDescriptorBlock* pApplMetaData;
  uint32 ulCrc32Calculated;
  uint32 ulCrcRom;
  boolean bRetVal = FALSE;

  ulCrc32Calculated = LibAutosarCrc_u32Calculate((const uint8*)0x20100U, 0x57ae0U, LibAutosarCrc_dValueInitial32, TRUE);

  pApplMetaData = VERSION_GetPointerToDescriptorBlock(cAPP);
  ulCrcRom = *((uint32*)&(pApplMetaData->ucHash));

  if(ulCrcRom == ulCrc32Calculated)
  {
   bRetVal = TRUE;
  }

  return bRetVal;
}