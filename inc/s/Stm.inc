' ########################################################################################
' Microsoft Windows
' File: Stm.inc
' Contents: This module contains the definitions of the IPX Service Table Manger APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%STM_INC = 1

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// Supported functionality flags                                            //
'//                                                                          //
'// ROUTING                  Imports Routing Table Manager APIs              //
'// SERVICES                 Exports Service Table Manager APIs              //
'// DEMAND_UPDATE_ROUTES     IP and IPX RIP support for Autostatic           //
'// DEMAND_UPDATE_SERVICES   IPX SAP, NLSP support for Autostatic            //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

%SERVICES                = &H00000002???
%DEMAND_UPDATE_SERVICES  = &H00000008???

'//
'// Server Entry
'//

' // Size = 64 bytes
TYPE IPX_SERVER_ENTRY BYTE
   Type     AS WORD          ' USHORT
   Name     AS STRING * 48   ' UCHAR
   Network  AS STRING * 4    ' UCHAR
   Node     AS STRING * 6    ' UCHAR
   Socket   AS STRING * 2    ' UCHAR
   HopCount AS WORD          ' USHORT
END TYPE

' // Size = 72 bytes
TYPE IPX_SERVICE BYTE
   InterfaceIndex AS DWORD         ' ULONG
   Protocol       AS DWORD         ' ULONG // protocol from which knowledge of the service was obatined
   Server         AS IPX_SERVER_ENTRY
END TYPE

'// Function which returns TRUE if the service exists

'typedef
'BOOL
'(WINAPI * PIS_SERVICE)(
'      IN USHORT    Type,
'      IN PUCHAR    Name,
'      OUT PIPX_SERVICE   Service OPTIONAL
'      );

'FUNCTION PIS_SERVICE (BYVAL nType AS WORD, BYVAL wszName AS DWORD, BYREF tServide AS IPX_SERVICE) AS LONG

'// Exclusion flags.  Limit enumeration to only servers that
'// have same values of the specified by flags parameter(s) as those of
'// criterea service.

%STM_ONLY_THIS_INTERFACE      = &H00000001???
%STM_ONLY_THIS_PROTOCOL       = &H00000002???
%STM_ONLY_THIS_TYPE           = &H00000004???
%STM_ONLY_THIS_NAME           = &H00000008???

'// Ordering methods. Specify the order in which services should be
'// retreived (methods are mutually exclusive).

%STM_ORDER_BY_TYPE_AND_NAME         = 0
%STM_ORDER_BY_INTERFACE_TYPE_NAME   = 1


'// Create handle to start enumeration of the services in the STM table.
'// Returns handle to be used for enumerations or NULL if operation failed
'//   GetLastError () returns the follwing error codes in case of failure:
'//      ERROR_CAN_NOT_COMPLETE
'//      ERROR_NOT_ENOUGH_MEMORY

'typedef
'HANDLE
'(WINAPI * PCREATE_SERVICE_ENUMERATION_HANDLE)(
'    IN  DWORD           ExclusionFlags, // Flags to limit enumeration to certain
'                                        // types of servers
'    IN   PIPX_SERVICE  CriteriaService   // Criteria for exclusion flags
'    );

'FUNCTION CREATE_SERVICE_ENUMERATION_HANDLE ( _
'   BYVAL ExclusionFlags AS DWORD, BYREF CriteriaService AS IPX_SERVICE) AS DWORD

'// Get next service in the enumeration started by CreateServiceEnumerationHandle
'// Returns NO_ERROR if next service was placed in provided buffer or
'// ERROR_NO_MORE_ITEMS when there are no more services to be
'// returned in the enumeration; ERROR_CAN_NOT_COMPLETE will be
'// returned if operation failed.

'typedef
'DWORD
'(WINAPI * PENUMERATE_GET_NEXT_SERVICE)(
'    IN  HANDLE          EnumerationHandle, // Handle that identifies this
'                                           // enumeration
'    OUT PIPX_SERVICE  Service          // buffer to place parameters of next service entry
'                              // to be returned by enumeration
'    );

'FUNCTION ENUMERATE_GET_NEXT_SERVICE ( _
'   BYVAL EnumerationHandle AS DWORD, BYREF tService AS IPX_SERVICE) AS DWORD

'// Frees resources associated with enumeration.
'// Returns NO_ERROR if operation succeded, ERROR_CAN_NOT_COMPLETE
'// otherwise

'typedef
'DWORD
'(WINAPI * PCLOSE_SERVICE_ENUMERATION_HANDLE)(
'    IN   HANDLE          EnumerationHandle
'    );

'FUNCTION CLOSE_SERVICE_ENUMERATION_HANDLE (BYVAL EnumerationHandle AS DWORD) AS DWORD

'// Get total number of known services

'typedef
'ULONG
'(WINAPI * PGET_SERVICE_COUNT)(
'   VOID
'   );

'FUNCTION GET_SERVICE_COUNT () AS DWORD

'//   Add service of IPX_PROTOCOL_STATIC to the table

'typedef
'DWORD
'(WINAPI * PCREATE_STATIC_SERVICE)(IN ULONG      InterfaceIndex,
'             IN PIPX_SERVER_ENTRY      ServerEntry);

'FUNCTION CREATE_STATIC_SERVICE ( _
'   BYVAL InterfaceIndex AS DWORD, BYREF ServerEntry AS IPX_SERVER_ENTRY) AS DWORD

'//   Delete service of IPX_PROTOCOL_STATIC from the table

'typedef
'DWORD
'(WINAPI * PDELETE_STATIC_SERVICE)(IN ULONG      InterfaceIndex,
'             IN PIPX_SERVER_ENTRY      ServerEntry);

'FUNCTION DELETE_STATIC_SERVICE ( _
'   BYVAL InterfaceIndex AS DWORD, BYREF ServerEntry AS IPX_SERVER_ENTRY) AS DWORD

'//   Converts protocol of all services associated with given interface to
'//   IPX_PROTOCOL_STATIC

'typedef
'DWORD
'(WINAPI * PBLOCK_CONVERT_SERVICES_TO_STATIC) (
'   IN ULONG      InterfaceIndex
'   );

'FUNCTION BLOCK_CONVERT_SERVICES_TO_STATIC (BYVAL InterfaceIndex AS DWORD) AS DWORD

'//   Delete all services of IPX_PROTOCOL_STATIC
'//   associated with  given interface from the table

'typedef
'DWORD
'(WINAPI * PBLOCK_DELETE_STATIC_SERVICES)(
'   IN ULONG      InterfaceIndex
'   );

'FUNCTION BLOCK_DELETE_STATIC_SERVICES (BYVAL InterfaceIndex AS DWORD) AS DWORD

'// Find and return first service in the order specified by the ordering method.
'// Search is limited only to ceratin types of services as specified by the
'// exclusion flags end corresponding fields in Service parameter.
'// Returns ERROR_NO_MORE_ITEMS if there are no services in the
'// table that meet specified criteria.

'typedef
'DWORD
'(WINAPI * PGET_FIRST_ORDERED_SERVICE)(
'    IN  DWORD           OrderingMethod,     // What ordering to use
'    IN  DWORD           ExclusionFlags,     // Flags to limit search to ceratin
'                                            // types of servers
'    IN OUT PIPX_SERVICE Service        // On input: criteria for exclusion
'                                            //          flags
'                                            // On output: first service entry
'                                            //          in the specified order
'    );

'FUNCTION GET_FIRST_ORDERED_SERVICE ( _
'   BYVAL OrderingMethod AS DWORD, BYVAL ExclusionFlags AS DWORD, _
'   BYREF tService AS IPX_SERVICE) AS DWORD

'// Find and return next service in the order specified by the ordering method.
'// Search starts from specified service and is limited only to ceratin types
'// of services as specified by the exclusion flags and corresponding fields
'// in Service parameter.
'// Returns ERROR_NO_MORE_ITEMS if there are no services in table
'// table that meet specified criteria.

'typedef
'DWORD
'(WINAPI * PGET_NEXT_ORDERED_SERVICE)(
'    IN  DWORD           OrderingMethod,     // What ordering to use
'    IN  DWORD           ExclusionFlags,     // Flags to limit search to ceratin
'                                            // types of servers
'    IN OUT PIPX_SERVICE Service        // On input: service to start the
'                                            //          search from and
'                                            //          criteria for exclusion
'                                            //          flags
'                                            // On output: next service entry
'                                            //          in the specified order
'    );

'FUNCTION GET_NEXT_ORDERED_SERVICE ( _
'   BYVAL OrderingMethod AS DWORD, BYVAL ExclusionFlags AS DWORD, _
'   BYREF tService AS IPX_SERVICE) AS DWORD

'typedef
'DWORD
'(WINAPI * DO_UPDATE_SERVICES) (
'    IN ULONG    InterfaceIndex
'    );

'FUNCTION PDO_UPDATE_SERVICES (BYVAL InterfaceIndex AS DWORD) AS DWORD

'typedef
'BOOL
'(WINAPI * PGET_SERVICE_ID)(
'      IN USHORT    Type,
'      IN PUCHAR    Name,
'      OUT PULONG   ServiceID
'      );

'FUNCTION GET_SERVICE_ID (BYVAL mType AS WORD, BYVAL wszName AS DWORD, BYREF ServiceID AS DWORD) AS LONG

'typedef
'BOOL
'(WINAPI * PGET_SERVICE_FROM_ID)(
'      IN ULONG           ServiceID,
'      OUT PIPX_SERVICE  Service
'      );

'FUNCTION GET_SERVICE_FROM_ID (BYVAL ServiceID AS DWORD, BYREF tService AS IPX_SERVICE) AS LONG

'typedef
'DWORD
'(WINAPI * PGET_NEXT_SERVICE_FROM_ID)(
'      IN ULONG           ServiceID,
'      OUT PIPX_SERVICE  NextService,
'      OUT PULONG        NextServiceID
'      );

'FUNCTION GET_NEXT_SERVICE_FROM_ID (BYVAL ServiceID AS DWORD, _
'   BYREF NextService AS IPX_SERVICE, BYREF NextServiceID AS DWORD) AS DWORD

'typedef struct _MPR40_SERVICE_CHARACTERISTICS
'{
'    DWORD                               dwVersion;
'    DWORD                               dwProtocolId;
'    DWORD                               fSupportedFunctionality;
'    PIS_SERVICE                         pfnIsService;
'    PDO_UPDATE_SERVICES                 pfnUpdateServices;
'    PCREATE_SERVICE_ENUMERATION_HANDLE  pfnCreateServiceEnumerationHandle;
'    PENUMERATE_GET_NEXT_SERVICE         pfnEnumerateGetNextService;
'    PCLOSE_SERVICE_ENUMERATION_HANDLE   pfnCloseServiceEnumerationHandle;
'    PGET_SERVICE_COUNT                  pfnGetServiceCount;
'    PCREATE_STATIC_SERVICE              pfnCreateStaticService;
'    PDELETE_STATIC_SERVICE              pfnDeleteStaticService;
'    PBLOCK_CONVERT_SERVICES_TO_STATIC   pfnBlockConvertServicesToStatic;
'    PBLOCK_DELETE_STATIC_SERVICES       pfnBlockDeleteStaticServices;
'    PGET_FIRST_ORDERED_SERVICE          pfnGetFirstOrderedService;
'    PGET_NEXT_ORDERED_SERVICE           pfnGetNextOrderedService;
'}MPR40_SERVICE_CHARACTERISTICS;

' // Size = 60 bytes
TYPE MPR40_SERVICE_CHARACTERISTICS DWORD
   dwVersion                         AS DWORD
   dwProtocolId                      AS DWORD
   fSupportedFunctionality           AS DWORD
   pfnIsService                      AS DWORD
   pfnUpdateServices                 AS DWORD
   pfnCreateServiceEnumerationHandle AS DWORD
   pfnEnumerateGetNextService        AS DWORD
   pfnCloseServiceEnumerationHandle  AS DWORD
   pfnGetServiceCount                AS DWORD
   pfnCreateStaticService            AS DWORD
   pfnDeleteStaticService            AS DWORD
   pfnBlockConvertServicesToStatic   AS DWORD
   pfnBlockDeleteStaticServices      AS DWORD
   pfnGetFirstOrderedService         AS DWORD
   pfnGetNextOrderedService          AS DWORD
END TYPE


'typedef struct _MPR50_SERVICE_CHARACTERISTICS
'{

'#ifdef __cplusplus
'    MPR40_SERVICE_CHARACTERISTICS       mscMpr40ServiceChars;
'#else
'    MPR40_SERVICE_CHARACTERISTICS;
'#endif

'}MPR50_SERVICE_CHARACTERISTICS;

'#if MPR50
'    typedef MPR50_SERVICE_CHARACTERISTICS MPR_SERVICE_CHARACTERISTICS;
'#else
'    #if MPR40
'    typedef MPR40_SERVICE_CHARACTERISTICS MPR_SERVICE_CHARACTERISTICS;
'    #endif
'#endif

'typedef MPR_SERVICE_CHARACTERISTICS *PMPR_SERVICE_CHARACTERISTICS;

' // Size = 60 bytes
TYPE MPR50_SERVICE_CHARACTERISTICS DWORD
   MPR40_SERVICE_CHARACTERISTICS
END TYPE
