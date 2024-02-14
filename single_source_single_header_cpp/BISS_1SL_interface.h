/*
 * Software and its documentation is provided by iC-Haus GmbH or contributors "AS IS" and is
 * subject to the ZVEI General Conditions for the Supply of Products and Services with iC-Haus
 * amendments and the ZVEI Software clause with iC-Haus amendments (http://www.ichaus.de/EULA).
 */

#ifndef BISS_1SL_INTERFACE_H
#define BISS_1SL_INTERFACE_H


#if defined _WIN32 || defined __CYGWIN__
    #ifdef BISS_CALLING_STDCALL
        #define BISS_CALLING __stdcall
    #endif
    #ifndef BISS_CALLING
        #define BISS_CALLING
    #endif
    #if defined BUILDING_BISS_DLL
        #ifdef __GNUC__
            #define BISS_PUBLIC BISS_CALLING __attribute__ ((dllexport))
        #else
            #define BISS_PUBLIC BISS_CALLING __declspec(dllexport)
        #endif
    #elif defined BISS_STATIC_LIB
        #define BISS_PUBLIC BISS_CALLING
    #else
        #ifdef __GNUC__
            #define BISS_PUBLIC BISS_CALLING __attribute__ ((dllimport))
        #else
            #define BISS_PUBLIC BISS_CALLING __declspec(dllimport)
        #endif
    #endif
#else
    #if __GNUC__ >= 4
        #define BISS_PUBLIC __attribute__ ((visibility ("default")))
    #else
        #define BISS_PUBLIC
    #endif
#endif


#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "BISS_1SL_defs.h"


BISS_PUBLIC uint32_t BISS_Open(uint32_t* pulBISSHandle);

BISS_PUBLIC uint32_t BISS_Close(uint32_t ulBISSHandle);

BISS_PUBLIC uint32_t BISS_SetInterface(
        uint32_t ulBISSHandle,
        uint32_t ulInterface,
        const char* pcInterfaceOption);

BISS_PUBLIC uint32_t BISS_GetInterface(
        uint32_t ulBISSHandle,
        uint32_t* pulInterface);

BISS_PUBLIC uint32_t BISS_SetComParam(
        uint32_t ulBISSHandle,
        uint32_t ulParam,
        uint32_t ulValue);

BISS_PUBLIC uint32_t BISS_GetComParam(
        uint32_t ulBISSHandle,
        uint32_t ulParam,
        uint32_t* pulValue);

BISS_PUBLIC uint32_t BISS_SetFrameParam(
        uint32_t ulBISSHandle,
        uint32_t ulDataChannel,
        uint32_t ulParam,
        uint32_t ulValue);

BISS_PUBLIC uint32_t BISS_GetFrameParam(
        uint32_t ulBISSHandle,
        uint32_t ulDataChannel,
        uint32_t ulParam,
        uint32_t* pulValue);

BISS_PUBLIC uint32_t BISS_AutoDetection(
        uint32_t ulBISSHandle,
        char* pcFilename,
        uint32_t* pulSlaveCount,
        uint32_t ulWriteMasterParams);

BISS_PUBLIC uint32_t BISS_WriteMasterParams(uint32_t ulBISSHandle);

BISS_PUBLIC uint32_t BISS_InitBissComm(uint32_t ulBISSHandle);

BISS_PUBLIC uint32_t BISS_ReadSCD(
        uint32_t ulBISSHandle,
        uint32_t* pulDataScdH,
        uint32_t* pulDataScdL,
        uint32_t* pulScdValid,
        uint32_t ulStartControlFrame,
        uint32_t* pulControlFrameEnd);

BISS_PUBLIC uint32_t BISS_WriteSlaveRegister(
        uint32_t ulBISSHandle,
        uint32_t ulProtocol,
        uint32_t ulSlaveId,
        uint32_t ulRegisterAddress,
        uint32_t* pulNumberOfBytes,
        uint32_t* pulRegisterContent);

BISS_PUBLIC uint32_t BISS_ReadSlaveRegister(
        uint32_t ulBISSHandle,
        uint32_t ulProtocol,
        uint32_t ulSlaveId,
        uint32_t ulRegisterAddress,
        uint32_t* pulNumberOfBytes,
        uint32_t* pulRegisterContent);

BISS_PUBLIC uint32_t BISS_SendCommand(
        uint32_t ulBISSHandle,
        uint32_t ulIds,
        uint32_t ulCmd);

BISS_PUBLIC uint32_t BISS_GetDLLVersion(uint32_t* pulDllVersion);


//optional functions
BISS_PUBLIC uint32_t BISS_SetSlaveLabel(
        uint32_t ulBISSHandle,
        uint32_t ulSlave,
        char* pcManufacturerLabel,
        char* pcSlaveLabel,
        char* pcCompleteLabel);

BISS_PUBLIC uint32_t BISS_GetSlaveLabel(
        uint32_t ulBISSHandle,
        uint32_t ulSlave,
        char* pcManufacturerLabel,
        char* pcSlaveLabel,
        char* pcCompleteLabel);

BISS_PUBLIC uint32_t BISS_SetScdContentLabels(
        uint32_t ulBISSHandle,
        uint32_t ulDataChannel,
        uint32_t ulContentIndex,
        char* pcScdContentLabel,
        char* pcScdContentUnit);

BISS_PUBLIC uint32_t BISS_GetScdContentLabels(
        uint32_t ulBISSHandle,
        uint32_t ulDataChannel,
        uint32_t ulContentIndex,
        char* pcScdContentLabel,
        char* pcScdContentUnit);

BISS_PUBLIC uint32_t BISS_SetScdContentParams(
        uint32_t ulBISSHandle,
        uint32_t ulDataChannel,
        uint32_t ulContentIndex,
        BISS_ScdContentStruct* pScdContentItems);

BISS_PUBLIC uint32_t BISS_GetScdContentParams(
        uint32_t ulBISSHandle,
        uint32_t ulDataChannel,
        uint32_t ulContentIndex,
        BISS_ScdContentStruct* pScdContentItems);

BISS_PUBLIC uint32_t BISS_GetScdContent(
        uint32_t ulBISSHandle,
        uint32_t ulDataChannel,
        uint32_t* pulScdContentValues);

BISS_PUBLIC uint32_t BISS_GetScdContentEx(
        uint32_t ulBISSHandle,
        uint32_t ulDataChannel,
        uint32_t* pulScdContentValuesH,
        uint32_t* pulScdContentValuesL);

BISS_PUBLIC uint32_t BISS_WriteMasterRegister(
        uint32_t ulBISSHandle,
        uint32_t ulRegisterAddress,
        uint32_t ulRegisterContent);

BISS_PUBLIC uint32_t BISS_ReadMasterRegister(
        uint32_t ulBISSHandle,
        uint32_t ulRegisterAddress,
        uint32_t* pulRegisterContent);

BISS_PUBLIC uint32_t BISS_GetMasterRegister(
        uint32_t ulBISSHandle,
        uint32_t ulRegisterAddress,
        uint32_t* pulRegisterContent);

BISS_PUBLIC uint32_t BISS_ReadSCDFrames(
        uint32_t ulBISSHandle,
        uint32_t ulCycleCnt,
        uint32_t* pulDataScdH,
        uint32_t* pulDataScdL,
        uint32_t* pulTimestamp,
        uint32_t* pulStatus);

BISS_PUBLIC uint32_t BISS_GetSCDFrame(
        uint32_t ulBISSHandle,
        uint32_t ulFrameIndex,
        uint32_t* pulDataScdH,
        uint32_t* pulDataScdL,
        uint32_t* pulTimestamp,
        uint32_t* pulStatus);

BISS_PUBLIC uint32_t BISS_GetSCDFrameEx(
        uint32_t ulBISSHandle,
        uint32_t ulCycleCnt,
        uint32_t ulDataChannel,
        uint32_t* pulDataScdH,
        uint32_t* pulDataScdL,
        uint32_t* pulTimestamp,
        uint32_t* pulStatus);

BISS_PUBLIC uint32_t BISS_GetScdFrameContent(
        uint32_t ulBISSHandle,
        uint32_t ulCycleCnt,
        uint32_t ulDataChannel,
        uint32_t ulContentIndex,
        uint32_t* pulValues);

BISS_PUBLIC uint32_t BISS_GetScdFrameContentEx(
        uint32_t ulBISSHandle,
        uint32_t ulCycleCnt,
        uint32_t ulDataChannel,
        uint32_t ulContentIndex,
        uint64_t *pulValues);

BISS_PUBLIC uint32_t BISS_SaveMasterConfig(
        uint32_t ulBISSHandle,
        char* pcCfgFilename);

BISS_PUBLIC uint32_t BISS_SaveRegister(
        uint32_t ulBISSHandle,
        char* pcFilename,
        uint32_t ulStartAdr,
        uint32_t ulNumberOfBytes,
        uint32_t* pulData);

BISS_PUBLIC uint32_t BISS_LoadRegister(
        uint32_t ulBISSHandle,
        char* pcFilename,
        uint32_t ulStartAdr,
        uint32_t ulNumberOfBytes,
        uint32_t* pulData);

BISS_PUBLIC uint32_t BISS_SaveDLLConfig(
        uint32_t ulBISSHandle,
        char* pcCfgFilename);

BISS_PUBLIC uint32_t BISS_LoadDLLConfig(
        uint32_t ulBISSHandle,
        char* pcCfgFilename);

BISS_PUBLIC uint32_t BISS_CalculateCRC(
        uint32_t ulBISSHandle,
        uint32_t ulCrcPoly,
        uint32_t* pulData,
        uint32_t ulByteCount,
        uint32_t* pulCheckSum);

BISS_PUBLIC uint32_t BISS_CalculateCRC_Ex(
        uint32_t ulBISSHandle,
        uint32_t ulCrcPoly,
        uint32_t ulCrcStartValue,
        uint32_t* pulData,
        uint32_t ulByteCount,
        uint32_t* pulCheckSum);

BISS_PUBLIC uint32_t BISS_GetInterfaceInfo(
        uint32_t ulBISSHandle,
        uint32_t ulIndex,
        char* pcInterfaceInfo);

BISS_PUBLIC uint32_t BISS_SetMb3uPins(
        uint32_t ulBISSHandle,
        uint32_t ulDir,
        uint32_t ulValue);

BISS_PUBLIC uint32_t BISS_GetMb3uPins(
        uint32_t ulBISSHandle,
        uint32_t* pulDir,
        uint32_t* pulValue);

BISS_PUBLIC uint32_t BISS_SetFtdiFreq(
        uint32_t ulBISSHandle,
        uint32_t ulFreqH,
        uint32_t ulFreqL);

BISS_PUBLIC uint32_t BISS_SetEdsParam(
        uint32_t ulBISSHandle,
        uint32_t ulParam,
        uint32_t ulValue);

BISS_PUBLIC uint32_t BISS_GetEdsParam(
        uint32_t ulBISSHandle,
        uint32_t ulParam,
        uint32_t* pulValue);

BISS_PUBLIC uint32_t BISS_SetEdsRegister(
        uint32_t ulBISSHandle,
        uint32_t ulAdr,
        uint32_t ulValue);

BISS_PUBLIC uint32_t BISS_GetEdsRegister(
        uint32_t ulBISSHandle,
        uint32_t ulAdr,
        uint32_t* pulValue);

BISS_PUBLIC uint32_t BISS_ReadEdsParams(
        uint32_t ulBISSHandle,
        uint32_t ulSlaveId);

BISS_PUBLIC uint32_t BISS_WriteEdsParams(
        uint32_t ulBISSHandle,
        uint32_t ulSlaveId);

BISS_PUBLIC uint32_t BISS_SaveEdsParams(
        uint32_t ulBISSHandle,
        char* pcFilename);

BISS_PUBLIC uint32_t BISS_LoadEdsParams(
        uint32_t ulBISSHandle,
        char* pcFilename);

BISS_PUBLIC uint32_t BISS_GetLastError(
        uint32_t ulBISSHandle,
        uint32_t* pulLastError,
        uint32_t* pulErrorType,
        char* pcErrorText);


#ifdef __cplusplus
}
#endif


#endif //BISS_1SL_INTERFACE_H

