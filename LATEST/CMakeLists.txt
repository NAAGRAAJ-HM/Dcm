add_library(
   BswAUTOSAR_Service_Dcm
   Dcm.cpp
)

include_directories(
   ../../BswAUTOSAR_Service_SchM/LATEST
   ../../common/LATEST
   ../../common/LATEST/Compiler_Abstraction_GNU/LATEST
   ../../SwcServiceEcuM/LATEST
   ../../SwcServiceOs/LATEST
)

