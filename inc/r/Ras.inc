' ########################################################################################
' Microsoft Windows
' File: Ras.inc
' Contents: Remote Access external API
' Copyright (c) 2010 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%RAS_INC = 1

' NOTE: The members of the structures are not dword aligned, but the whole
' structure has to fit into a 4-byte bounded memory space, thus the extra
' bytes fillers at the end of the structure.
' This is not the same as using the DWORD specifier in the type declaration
' (that would dword align each member of the structure).


'/*++

'Copyright (c) Microsoft Corporation. All rights reserved.

'Module Name:

'    ras.h

'Abstract:

'    Remote Access external API

'    WINVER values in this file:
'        WINVER < 0x400 = Windows NT 3.5, Windows NT 3.51
'        WINVER = 0x400 = Windows 95, Windows98, Windows NT4 (default)
'        WINVER > 0x400 = Windows NT4 enhancements
'        WINVER = 0x500 = Windows 2000
'        WINVER = 0x501 = Windows XP

'--*/

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "raserror.inc"

#IF NOT %DEF(%WINVER)
%WINVER = &H0601  ' Assume Windows 7
#ENDIF

#IF NOT %DEF(%UNLEN)
    #INCLUDE ONCE "lmcons.inc"
#ENDIF

'// To use Quarantine APIs, applications should explicitly
'// define USES_RAS_QUARANTINE_APIS.
#IF %DEF(%USES_RAS_QUARANTINE_APIS)
#INCLUDE ONCE "naptypes.inc"

%RASNAP_ProbationTime = &H00000001

TYPE RASNAPSTATE DWORD
    dwSize         AS DWORD      ' DWORD
    dwFlags        AS DWORD      ' DWORD
    isolationState AS LONG       ' IsolationState enum
    probationTime  AS FILETIME   ' ProbationTime
END TYPE
#ENDIF   ' %USES_RAS_QUARANTINE_APIS

'#include <pshpack4.h>
#INCLUDE ONCE "inaddr.inc"
#INCLUDE ONCE "in6addr.inc"

'/* RAS API Version
'*/
' enum RASAPIVERSION
%RASAPIVERSION_500 = 1
%RASAPIVERSION_501 = 2
%RASAPIVERSION_600 = 3
%RASAPIVERSION_601 = 4

%RASAPIVERSION_CURRENT = %RASAPIVERSION_601

'/* A RAS IP address.
'*/
' // Size = 4 bytes
TYPE RASIPADDR BYTE
   a AS BYTE
   b AS BYTE
   c AS BYTE
   d AS BYTE
END TYPE

'#if (WINVER >= 0x600)

'/* A RAS IPv4 address.
'*/
'typedef struct in_addr RASIPV4ADDR;
MACRO RASIPV4ADDR = in_addr

'/* A RAS IPv6 address.
'*/
'typedef struct in6_addr RASIPV6ADDR;
MACRO RASIPV6ADDR = in6_addr
'#endif

#IF (%WINVER >= &H600)

%RASTUNNELENDPOINT_UNKNOWN = 0
%RASTUNNELENDPOINT_IPv4    = 1
%RASTUNNELENDPOINT_IPv6    = 2

'/* RAS Tunnel endpoint address
'*/
' // Size = 16 bytes
UNION RASTUNNELENDPOINT_UNION
   ipv4 AS RASIPV4ADDR
   ipv6 AS RASIPV6ADDR
END UNION

' // Size = 20 bytes
TYPE RASTUNNELENDPOINT ' Must be 4 byte aligned
   dwType AS DWORD   ' DWORD
   RASTUNNELENDPOINT_UNION
END TYPE

#ENDIF

%RAS_MaxDeviceType     = 16
%RAS_MaxPhoneNumber    = 128
%RAS_MaxIpAddress      = 15
%RAS_MaxIpxAddress     = 21

#IF (%WINVER >= &H400)
%RAS_MaxEntryName      = 256
%RAS_MaxDeviceName     = 128
%RAS_MaxCallbackNumber = %RAS_MaxPhoneNumber
#ELSE
%RAS_MaxEntryName      = 20
%RAS_MaxDeviceName     = 32
%RAS_MaxCallbackNumber = 48
#ENDIF

%RAS_MaxAreaCode       = 10
%RAS_MaxPadType        = 32
%RAS_MaxX25Address     = 200
%RAS_MaxFacilities     = 200
%RAS_MaxUserData       = 200
%RAS_MaxReplyMessage   = 1024
%RAS_MaxDnsSuffix      = 256

'DECLARE_HANDLE( HRASCONN );
'#define LPHRASCONN HRASCONN*

#IF (%WINVER >= &H501)
%RASCF_AllUsers        = &H00000001???
%RASCF_GlobalCreds     = &H00000002???
%RASCF_OwnerKnown      = &H00000004???
%RASCF_OwnerMatch      = &H00000008???

'#define RASCF_IsOwner(rascFlags)    (((rascFlags) & (RASCF_OwnerKnown | RASCF_OwnerMatch)) == (RASCF_OwnerKnown | RASCF_OwnerMatch))
'#define RASCF_IsNotOwner(rascFlags) (((rascFlags) & (RASCF_OwnerKnown | RASCF_OwnerMatch)) == (RASCF_OwnerKnown))
MACRO RASCF_IsOwner(rascFlags) = (((rascFlags) AND (%RASCF_OwnerKnown OR %RASCF_OwnerMatch)) = (%RASCF_OwnerKnown OR %RASCF_OwnerMatch))
MACRO RASCF_IsNotOwner(rascFlags) = (((rascFlags) AND (%RASCF_OwnerKnown OR %RASCF_OwnerMatch)) = (%RASCF_OwnerKnown))
#ENDIF

'/* Identifies an active RAS connection.  (See RasEnumConnections)
'*/

' // Size = 1384 bytes
TYPE RASCONNW   ' Must be 4 byte aligned
   dwSize       AS DWORD                               ' DWORD
   hRasConn     AS DWORD                               ' HRASCONN
   szEntryName  AS WSTRINGZ * %RAS_MaxEntryName + 1    ' WCHAR[RAS_MaxEntryName + 1]
#IF (%WINVER >= &H400)
   szDeviceTYPE AS WSTRINGZ * %RAS_MaxDeviceType + 1   ' WCHAR[RAS_MaxDeviceType + 1]
   szDeviceName AS WSTRINGZ * %RAS_MaxDeviceName + 1   ' WCHAR[RAS_MaxDeviceName + 1]
#ENDIF
#IF (%WINVER >= &H401)
   szPhonebook  AS WSTRINGZ * %MAX_PATH                ' WCHAR[MAX_PATH]
   dwSubEntry   AS DWORD                               ' DWORD
#ENDIF
#IF (%WINVER >= &H500)
   guidEntry    AS GUID                                ' GUID
#ENDIF
#IF (%WINVER >= &H501)
   dwFlags      AS DWORD                               ' DWORD
   luid         AS QUAD                                ' LUID
#ENDIF
#IF (%WINVER >= &H600)
   guidCorrelationId AS GUID                           ' GUID
#ENDIF
   alignment__(1) AS BYTE                              ' // To keep 4 byte alignment
END TYPE

'#define RASCONNA struct tagRASCONNA
'RASCONNA
'{
'    DWORD    dwSize;
'    HRASCONN hrasconn;
'    CHAR     szEntryName[ RAS_MaxEntryName + 1 ];

'#if (WINVER >= 0x400)
'    CHAR     szDeviceType[ RAS_MaxDeviceType + 1 ];
'    CHAR     szDeviceName[ RAS_MaxDeviceName + 1 ];
'#endif
'#if (WINVER >= 0x401)
'    CHAR     szPhonebook [ MAX_PATH ];
'    DWORD    dwSubEntry;
'#endif
'#if (WINVER >= 0x500)
'    GUID     guidEntry;
'#endif
'#if (WINVER >= 0x501)
'   DWORD   dwFlags;
'   LUID    luid;
'#endif
'#if (WINVER >= 0x600)
'    GUID     guidCorrelationId;
'#endif
'};

' // Size = 720 bytes
TYPE RASCONNA   ' Must be 4 byte aligned
   dwSize       AS DWORD                             ' DWORD
   hRasConn     AS DWORD                             ' HRASCONN
   szEntryName  AS ASCIIZ * %RAS_MaxEntryName + 1    ' CHAR[RAS_MaxEntryName + 1]
#IF (%WINVER >= &H400)
   szDeviceTYPE AS ASCIIZ * %RAS_MaxDeviceType + 1   ' CHAR[RAS_MaxDeviceType + 1]
   szDeviceName AS ASCIIZ * %RAS_MaxDeviceName + 1   ' CHAR[RAS_MaxDeviceName + 1]
#ENDIF
#IF (%WINVER >= &H401)
   szPhonebook  AS ASCIIZ * %MAX_PATH                ' CHAR[MAX_PATH]
   dwSubEntry   AS DWORD                             ' DWORD
#ENDIF
#IF (%WINVER >= &H500)
   guidEntry    AS GUID                              ' GUID
#ENDIF
#IF (%WINVER >= &H501)
   dwFlags      AS DWORD                             ' DWORD
   luid         AS QUAD                              ' LUID
#ENDIF
#IF (%WINVER >= &H600)
   guidCorrelationId AS GUID                         ' GUID
#ENDIF
   alignment__(0) AS BYTE                            ' // To keep 4 byte alignment
END TYPE

#IF %DEF(%UNICODE)
   MACRO RASCONN = RASCONNW
#ELSE
   MACRO RASCONN = RASCONNA
#ENDIF

'/* Enumerates intermediate states to a connection.  (See RasDial)
'*/
%RASCS_PAUSED = &H1000
%RASCS_DONE   = &H2000

'#define RASCONNSTATE enum tagRASCONNSTATE
%RASCS_OpenPort             = 0
%RASCS_PortOpened           = 1
%RASCS_ConnectDevice        = 2
%RASCS_DeviceConnected      = 3
%RASCS_AllDevicesConnected  = 4
%RASCS_Authenticate         = 5
%RASCS_AuthNotify           = 6
%RASCS_AuthRetry            = 7
%RASCS_AuthCallback         = 8
%RASCS_AuthChangePassword   = 9
%RASCS_AuthProject          = 10
%RASCS_AuthLinkSpeed        = 11
%RASCS_AuthAck              = 12
%RASCS_ReAuthenticate       = 13
%RASCS_Authenticated        = 14
%RASCS_PrepareForCallback   = 15
%RASCS_WaitForModemReset    = 16
%RASCS_WaitForCallback      = 17
%RASCS_Projected            = 18
#IF (%WINVER >= &H400)
%RASCS_StartAuthentication  = 19
%RASCS_CallbackComplete     = 20
%RASCS_LogonNetwork         = 21
#ENDIF
%RASCS_SubEntryConnected    = 22
%RASCS_SubEntryDisconnected = 23
#IF (%WINVER >= &H601)
%RASCS_ApplySettings        = 24
#ENDIF
%RASCS_Interactive          = %RASCS_PAUSED
%RASCS_RetryAuthentication  = %RASCS_PAUSED + 1
%RASCS_CallbackSetByCaller  = %RASCS_PAUSED + 2
%RASCS_PasswordExpired      = %RASCS_PAUSED + 3
#IF (%WINVER >= &H500)
%RASCS_InvokeEapUI          = %RASCS_PAUSED + 3
#ENDIF
%RASCS_Connected            = %RASCS_DONE
%RASCS_Disconnected         = %RASCS_DONE + 1

#IF (%WINVER >= &H600)
%RASCSS_DONE      = &H2000

' enum RASCONNSUBSTATE
%RASCSS_None = 0
%RASCSS_Dormant = 1
%RASCSS_Reconnecting = 2
%RASCSS_Reconnected = %RASCSS_DONE
#ENDIF

'/* Describes the status of a RAS connection.  (See RasConnectionStatus)
'*/
'#define RASCONNSTATUSW struct tagRASCONNSTATUSW
' // Size = 608 bytes
TYPE RASCONNSTATUSW   ' Must be 4 byte aligned
   dwSize          AS DWORD                                ' DWORD
   rasconnstate    AS LONG                                 ' RASCONNSTATE
   dwError         AS DWORD                                ' DWORD
   szDeviceTYPE    AS WSTRINGZ * %RAS_MaxDeviceType + 1    ' WCHAR[RAS_MaxDeviceType + 1]
   szDeviceName    AS WSTRINGZ * %RAS_MaxDeviceName + 1    ' WCHAR[RAS_MaxDeviceName + 1]
#IF (%WINVER >= &H401)
   szPhoneNumber   AS WSTRINGZ * %RAS_MaxPhoneNumber + 1   ' WCHAR[RAS_MaxPhoneNumber + 1]
#ENDIF
#IF (%WINVER >= &H401)
   alignment__(1)  AS BYTE   ' // To keep 4 byte alignment
#ENDIF
#IF (%WINVER >= &H601)
   localEndPoint   AS RASTUNNELENDPOINT                    ' RASTUNNELENDPOINT
   remoteEndPoint  AS RASTUNNELENDPOINT                    ' RASTUNNELENDPOINT
   rasconnsubstate AS LONG                                 ' RASCONNSUBSTATE
#ENDIF
END TYPE

'#define RASCONNSTATUSA struct tagRASCONNSTATUSA
' // Size = 332 bytes
TYPE RASCONNSTATUSA   ' Must be 4 byte aligned
   dwSize          AS DWORD
   rasconnstate    AS LONG
   dwError         AS DWORD
   szDeviceTYPE    AS ASCIIZ * %RAS_MaxDeviceType + 1    ' CHAR[RAS_MaxDeviceType + 1]
   szDeviceName    AS ASCIIZ * %RAS_MaxDeviceName + 1    ' CHAR[RAS_MaxDeviceName + 1]
#IF (%WINVER >= &H401)
   szPhoneNumber   AS ASCIIZ * %RAS_MaxPhoneNumber + 1   ' CHAR[RAS_MaxPhoneNumber + 1]
#ENDIF
#IF (%WINVER >= &H401)
   alignment__(0)  AS BYTE                               ' // To keep 4 byte alignment
#ELSE
   alignment__(1)  AS BYTE                               ' // To keep 4 byte alignment
#ENDIF
#IF (%WINVER >= &H601)
   localEndPoint   AS RASTUNNELENDPOINT                  ' RASTUNNELENDPOINT
   remoteEndPoint  AS RASTUNNELENDPOINT                  ' RASTUNNELENDPOINT
   rasconnsubstate AS LONG                               ' RASCONNSUBSTATE
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
   MACRO RASCONNSTATUS = RASCONNSTATUSW
#ELSE
   MACRO RASCONNSTATUS = RASCONNSTATUSA
#ENDIF

'/* Describes connection establishment parameters.  (See RasDial)
'*/
'#define RASDIALPARAMSW struct tagRASDIALPARAMSW
' // Size = 2108 bytes
TYPE RASDIALPARAMSW   ' Must be 4 byte aligned
   dwSize           AS DWORD                                   ' DWORD
   szEntryName      AS WSTRINGZ * %RAS_MaxEntryName + 1        ' WCHAR[RAS_MaxEntryName]
   szPhoneNumber    AS WSTRINGZ * %RAS_MaxPhoneNumber + 1      ' WCHAR[RAS_MaxPhoneNumber]
   szCallBackNumber AS WSTRINGZ * %RAS_MaxCallbackNumber + 1   ' WCHAR[RAS_MaxCallbackNumber]
   szUserName       AS WSTRINGZ * %UNLEN + 1                   ' WCHAR[UNLEN + 1]
   szPassword       AS WSTRINGZ * %PWLEN + 1                   ' WCHAR[PWLEN + 1]
   szDomain         AS WSTRINGZ * %DNLEN + 1                   ' WCHAR[DNLEN + 1]
#IF (%WINVER >= &H401)
   dwSubEntry       AS DWORD                                   ' DWORD
   dwCallbackId     AS DWORD                                   ' ULONG_PTR
#ENDIF
   alignment__(1)   AS BYTE                                    ' // To keep 4 byte alignment
#IF (%WINVER >= &H601)
   dwIfIndex        AS DWORD                                   ' DWORD
#ENDIF
END TYPE

'#define RASDIALPARAMSA struct tagRASDIALPARAMSA
' // Size = 1064 bytes
TYPE RASDIALPARAMSA   ' Must be 4 byte aligned
   dwSize           AS DWORD                                 ' DWORD
   szEntryName      AS ASCIIZ * %RAS_MaxEntryName + 1        ' CHAR[RAS_MaxEntryName + 1]
   szPhoneNumber    AS ASCIIZ * %RAS_MaxPhoneNumber + 1      ' CHAR[RAS_MaxPhoneNumber + 1]
   szCallBackNumber AS ASCIIZ * %RAS_MaxCallbackNumber + 1   ' CHAR[RAS_MaxCallbackNumber + 1]
   szUserName       AS ASCIIZ * %UNLEN + 1                   ' CHAR[UNLEN]
   szPassword       AS ASCIIZ * %PWLEN + 1                   ' CHAR[PWLEN]
   szDomain         AS ASCIIZ * %DNLEN + 1                   ' CHAR[DNLEN]
#IF (%WINVER >= &H401)
   dwSubEntry       AS DWORD                                 ' DWORD
   dwCallbackId     AS DWORD                                 ' ULONG_PTR
#ENDIF
   alignment__(2)   AS BYTE                                  ' // To keep 4 byte alignment
#IF (%WINVER >= &H601)
   dwIfIndex        AS DWORD                                 ' DWORD
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
   MACRO RASDIALPARAMS = RASDIALPARAMSW
#ELSE
   MACRO RASDIALPARAMS = RASDIALPARAMSA
#ENDIF

'#if (WINVER >= 0x500)

'#define RASEAPINFO struct tagRASEAPINFO
'RASEAPINFO
'{
'    DWORD dwSizeofEapInfo;
'    BYTE  *pbEapInfo;
'};

' // Size = 8 bytes
TYPE RASEAPINFO   ' Must be 4 byte aligned
   dwSizeofEapInfo AS DWORD
   pbEapInfo       AS BYTE PTR
END TYPE
MACRO RASEAPINFO_type = RASEAPINFO   ' // For compatibility with the PB declares

'#endif

'#IF (%WINVER >= &H601)
' // Size = 8 bytes
TYPE RASDEVSPECIFICINFO   ' Must be 4 byte aligned
   dwSize            AS DWORD      ' DWORD
   pbDevSpecificInfo AS BYTE PTR   ' BYTE*
END TYPE
MACRO RASDEVSPECIFICINFO_type = RASDEVSPECIFICINFO   ' // For compatibility with the PB declares
'#ENDIF

'/* Describes extended connection establishment options.  (See RasDial)
'*/
'#define RASDIALEXTENSIONS struct tagRASDIALEXTENSIONS
' // Size = 40 bytes
TYPE RASDIALEXTENSIONS   ' Must be 4 byte aligned
   dwSize             AS DWORD                ' DWORD
   dwfOptions         AS DWORD                ' DWORD
   hwndParent         AS DWORD                ' HWND
   reserved           AS DWORD                ' ULONG_PTR
#IF (%WINVER >= &H500)
   reserved1          AS DWORD                ' ULONG_PTR
   RasEapInfo         AS RASEAPINFO           ' RASEAPINFO
#ENDIF
#IF (%WINVER >= &H601)
   fSkipPppAuth       AS LONG                 ' BOOL
   RasDevSpecificInfo AS RASDEVSPECIFICINFO   ' RASDEVSPECIFICINFO
#ENDIF
END TYPE

'#define LPRASDIALEXTENSIONS RASDIALEXTENSIONS*

'/* 'dwfOptions' bit flags.
'*/
%RDEOPT_UsePrefixSuffix           = &H00000001???
%RDEOPT_PausedStates              = &H00000002???
%RDEOPT_IgnoreModemSpeaker        = &H00000004???
%RDEOPT_SetModemSpeaker           = &H00000008???
%RDEOPT_IgnoreSoftwareCompression = &H00000010???
%RDEOPT_SetSoftwareCompression    = &H00000020???
%RDEOPT_DisableConnectedUI        = &H00000040???
%RDEOPT_DisableReconnectUI        = &H00000080???
%RDEOPT_DisableReconnect          = &H00000100???
%RDEOPT_NoUser                    = &H00000200???
%RDEOPT_PauseOnScript             = &H00000400???
%RDEOPT_Router                    = &H00000800???

#IF (%WINVER >= &H500)
%RDEOPT_CustomDial                = &H00001000???
#ENDIF

#IF (%WINVER >= &H501)
%RDEOPT_UseCustomScripting        = &H00002000???
#ENDIF


'//
'// This flag when set in the RASENTRYNAME structure
'// indicates that the phonebook to which this entry
'// belongs is a system phonebook.
'//
%REN_User                         = &H00000000???
%REN_AllUsers                     = &H00000001???


'/* Describes an enumerated RAS phone book entry name.  (See RasEntryEnum)
'*/
'#define RASENTRYNAMEW struct tagRASENTRYNAMEW
' // Size = 1048 bytes
TYPE RASENTRYNAMEW   ' Must be 4 byte aligned
   dwSize          AS DWORD                              ' DWORD
   szEntryName     AS WSTRINGZ * %RAS_MaxEntryName + 1   ' WCHAR[RAS_MaxEntryName + 1]
#IF (%WINVER >= &H500)
   dwFlags         AS DWORD                              ' DWORD
   szPhonebookPath AS WSTRINGZ * %MAX_PATH + 1           ' WCHAR[MAX_PATH + 1]
#ENDIF
#IF (%WINVER >= &H500)
   alignment__(3)  AS BYTE
#ELSE
   alignment__(1)  AS BYTE
#ENDIF
END TYPE

'#define RASENTRYNAMEA struct tagRASENTRYNAMEA
' // Size = 532 bytes
TYPE RASENTRYNAMEA   ' Must be 4 byte aligned
   dwSize          AS DWORD                            ' DWORD
   szEntryName     AS ASCIIZ * %RAS_MaxEntryName + 1   ' CHAR[RAS_MaxEntryName + 1]
#IF (%WINVER >= &H500)
   dwFlags         AS DWORD                            ' DWORD
   szPhonebookPath AS ASCIIZ * %MAX_PATH + 1           ' CHAR[MAX_PATH + 1]
#ENDIF
#IF (%WINVER >= &H500)
   alignment__(5)  AS BYTE
#ELSE
   alignment__(2)  AS BYTE
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
   MACRO RASENTRYNAME = RASENTRYNAMEW
#ELSE
   MACRO RASENTRYNAME = RASENTRYNAMEA
#ENDIF

'/* Protocol code to projection data structure mapping.
'*/
'#define RASPROJECTION enum tagRASPROJECTION
%RASP_Amb    = &H10000
%RASP_PppNbf = &H803F??
%RASP_PppIpx = &H802B??
%RASP_PppIp  = &H8021??
#IF (%WINVER >= &H500)
%RASP_PppCcp = &H80FD??
#ENDIF
%RASP_PppLcp = &HC021??
%RASP_Slip   = &H20000


'/* Describes the result of a RAS AMB (Authentication Message Block)
'** projection.  This protocol is used with NT 3.1 and OS/2 1.3 downlevel
'** RAS servers.
'*/
'#define RASAMBW struct tagRASAMBW
' // Size = 44 bytes
TYPE RASAMBW   ' Must be 4 byte aligned
   dwSize         AS DWORD                              ' DWORD
   dwError        AS DWORD                              ' DWORD
   szNetBiosError AS WSTRINGZ * %NETBIOS_NAME_LEN + 1   ' WCHAR[NETBIOS_NAME_LEN + 1]
   bLana          AS BYTE                               ' BYTE
   alignment__(0) AS BYTE
END TYPE

'#define RASAMBA struct tagRASAMBA
' // Size = 28 bytes
TYPE RASAMBA   ' Must be 4 byte aligned
   dwSize         AS DWORD                            ' DWORD
   dwError        AS DWORD                            ' DWORD
   szNetBiosError AS ASCIIZ * %NETBIOS_NAME_LEN + 1   ' CHAR[NETBIOS_NAME_LEN + 1]
   bLana          AS BYTE                             ' BYTE
   alignment__(1) AS BYTE
END TYPE

#IF %DEF(%UNICODE)
   MACRO RASAMB = RASAMBW
#ELSE
   MACRO RASAMB = RASAMBA
#ENDIF

'/* Describes the result of a PPP NBF (NetBEUI) projection.
'*/
''#define RASPPPNBFW struct tagRASPPPNBFW
' // Size = 84 bytes
TYPE RASPPPNBFW   ' Must be 4 byte aligned
   dwSize            AS DWORD                              ' DWORD
   dwError           AS DWORD                              ' DWORD
   dwNetBiosError    AS DWORD                              ' DWORD
   szNetBiosError    AS WSTRINGZ * %NETBIOS_NAME_LEN + 1   ' WCHAR[NETBIOS_NAME_LEN + 1]
   szWorkstationName AS WSTRINGZ * %NETBIOS_NAME_LEN + 1   ' WCHAR[NETBIOS_NAME_LEN + 1]
   bLana             AS BYTE                               ' BYTE
   alignment__(2)    AS BYTE
END TYPE

'#define RASPPPNBFA struct tagRASPPPNBFA
' // Size = 48 bytes
TYPE RASPPPNBFA   ' Must be 4 byte aligned
   dwSize            AS DWORD                            ' DWORD
   dwError           AS DWORD                            ' DWORD
   dwNetBiosError    AS DWORD                            ' DWORD
   szNetBiosError    AS ASCIIZ * %NETBIOS_NAME_LEN + 1   ' CHAR[NETBIOS_NAME_LEN + 1]
   szWorkstationName AS ASCIIZ * %NETBIOS_NAME_LEN + 1   ' CHAR[NETBIOS_NAME_LEN + 1]
   bLana             AS BYTE                             ' BYTE
   alignment__(0)    AS BYTE
END TYPE

#IF %DEF(%UNICODE)
   MACRO RASPPPNBF = RASPPPNBFW
#ELSE
   MACRO RASPPPNBF = RASPPPNBFA
#ENDIF

'/* Describes the results of a PPP IPX (Internetwork Packet Exchange)
'** projection.
'*/
'#define RASPPPIPXW struct tagRASIPXW
' // Size = 52 bytes
TYPE RASPPPIPXW   ' Must be 4 byte aligned
   dwSize       AS DWORD                               ' DWORD
   dwError      AS DWORD                               ' DWORD
   szIpxAddress AS WSTRINGZ * %RAS_MaxIpxAddress + 1   ' WCHAR[RAS_MaxIpxAddress + 1]
END TYPE

'#define RASPPPIPXA struct tagRASPPPIPXA
' // Size = 32 bytes
TYPE RASPPPIPXA   ' Must be 4 byte aligned
   dwSize         AS DWORD                             ' DWORD
   dwError        AS DWORD                             ' DWORD
   szIpxAddress   AS ASCIIZ * %RAS_MaxIpxAddress + 1   ' CHAR[RAS_MaxIpxAddress + 1]
   alignment__(1) AS BYTE
END TYPE

#IF %DEF(%UNICODE)
   MACRO RASPPPIPX = RASPPPIPXW
#ELSE
   MACRO RASPPPIPX = RASPPPIPXA
#ENDIF

'/* Describes the results of a PPP IP (Internet) projection.
'*/

#IF (%WINVER >= &H500)

'/* RASPPPIP 'dwOptions' and 'dwServerOptions' flags.
'*/
%RASIPO_VJ       = &H00000001???

#ENDIF

''#define RASPPPIPW struct tagRASPPPIPW
' // Size = 80 bytes
TYPE RASPPPIPW   ' Must be 4 byte aligned
   dwSize            AS DWORD                              ' DWORD
   dwError           AS DWORD                              ' DWORD
   szIpAddress       AS WSTRINGZ * %RAS_MaxIpAddress + 1   ' WCHAR[RAS_MaxIpAddress]
#IF NOT %DEF(%WINNT35COMPATIBLE)
   szServerIpAddress AS WSTRINGZ * %RAS_MaxIpAddress + 1   ' WCHAR[RAS_MaxIpAddress]
#ENDIF
#IF (%WINVER >= &H500)
   dwOptions         AS DWORD                               ' DWORD
   dwServerOptions   AS DWORD                               ' DWORD
#ENDIF
END TYPE

'#define RASPPPIPA struct tagRASPPPIPA
' // Size = 48 bytes
TYPE RASPPPIPA   ' Must be 4 byte aligned
   dwSize            AS DWORD                            ' DWORD
   dwError           AS DWORD                            ' DWORD
   szIpAddress       AS ASCIIZ * %RAS_MaxIpAddress + 1   ' CHAR[RAS_MaxIpAddress + 1
#IF NOT %DEF(%WINNT35COMPATIBLE)
   szServerIpAddress AS ASCIIZ * %RAS_MaxIpAddress + 1   ' CHAR[RAS_MaxIpAddress + 1
#ENDIF
#IF (%WINVER >= &H500)
   dwOptions         AS DWORD                            ' DWORD
   dwServerOptions   AS DWORD                            ' DWORD
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
   MACRO RASPPPIP = RASPPPIPW
#ELSE
   MACRO RASPPPIP = RASPPPIPA
#ENDIF

'/* Describes the results of a Ipv6 projection info
'*/
#IF (%WINVER >= &H600)
'#define RASPPPIPV6 struct tagRASPPPIPV6
' // Size = 28 bytes   ' Must be 4 byte aligned
TYPE RASPPPIPV6
   dwSize                       AS DWORD   ' DWORD
   dwError                      AS DWORD   ' DWORD
   bLocalInterfaceIdentifier(7) AS BYTE    ' BYTE
   bPeerInterfaceIdentifier(7)  AS BYTE    ' BYTE
   bLocalCompressionProtocol(1) AS BYTE    ' BYTE
   bPeerCompressionProtocol(1)  AS BYTE    ' BYTE
END TYPE
#ENDIF

'/* Describes the results of a PPP LCP/multi-link negotiation.
'*/

#IF (%WINVER >= &H500)

'/* RASPPPLCP 'dwAuthenticatonProtocol' values.
'*/
%RASLCPAP_PAP          = &HC023???
%RASLCPAP_SPAP         = &HC027???
%RASLCPAP_CHAP         = &HC223???
%RASLCPAP_EAP          = &HC227???

'/* RASPPPLCP 'dwAuthenticatonData' values.
'*/
%RASLCPAD_CHAP_MD5     = &H05???
%RASLCPAD_CHAP_MS      = &H80???
%RASLCPAD_CHAP_MSV2    = &H81???

'/* RASPPPLCP 'dwOptions' and 'dwServerOptions' flags.
'*/
%RASLCPO_PFC           = &H00000001???
%RASLCPO_ACFC          = &H00000002???
%RASLCPO_SSHF          = &H00000004???
%RASLCPO_DES_56        = &H00000008???
%RASLCPO_3_DES         = &H00000010???

#IF (%WINVER >= &H600)
%RASLCPO_AES_128       = &H00000020???
%RASLCPO_AES_256       = &H00000040???
#ENDIF   ' /* WINVER >= 0x0600 */

#ENDIF


'#define RASPPPLCPW struct tagRASPPPLCPW
' // Size = 2104 bytes
TYPE RASPPPLCPW   ' Must be 4 byte aligned
   dwSize                         AS DWORD                             ' DWORD
   fBundled                       AS LONG                              ' BOOL
#IF (%WINVER >= &H500)
   dwError                        AS DWORD                             ' DWORD
   dwAuthenticationProtocol       AS DWORD                             ' DWORD
   dwAuthenticationData           AS DWORD                             ' DWORD
   dwEapTypeId                    AS DWORD                             ' DWORD
   dwServerAuthenticationProtocol AS DWORD                             ' DWORD
   dwServerAuthenticationData     AS DWORD                             ' DWORD
   dwServerEapTypeId              AS DWORD                             ' DWORD
   fMultilink                     AS LONG                              ' BOOL
   dwTerminateReason              AS DWORD                             ' DWORD
   dwServerTerminateReason        AS DWORD                             ' DWORD
   szReplyMessage                 AS WSTRINGZ * %RAS_MaxReplyMessage   ' WCHAR[RAS_MaxReplyMessage]
   dwOptions                      AS DWORD                             ' DWORD
   dwServerOptions                AS DWORD                             ' DWORD
#ENDIF
END TYPE

'#define RASPPPLCPA struct tagRASPPPLCPA
' // Size = 1080 bytes
TYPE RASPPPLCPA   ' Must be 4 byte aligned
   dwSize                         AS DWORD                           ' DWORD
   fBundled                       AS LONG                            ' BOOL
#IF (%WINVER >= &H500)
   dwError                        AS DWORD                           ' DWORD
   dwAuthenticationProtocol       AS DWORD                           ' DWORD
   dwAuthenticationData           AS DWORD                           ' DWORD
   dwEapTypeId                    AS DWORD                           ' DWORD
   dwServerAuthenticationProtocol AS DWORD                           ' DWORD
   dwServerAuthenticationData     AS DWORD                           ' DWORD
   dwServerEapTypeId              AS DWORD                           ' DWORD
   fMultilink                     AS LONG                            ' BOOL
   dwTerminateReason              AS DWORD                           ' DWORD
   dwServerTerminateReason        AS DWORD                           ' DWORD
   szReplyMessage                 AS ASCIIZ * %RAS_MaxReplyMessage   ' CHAR[RAS_MaxReplyMessage]
   dwOptions                      AS DWORD                           ' DWORD
   dwServerOptions                AS DWORD                           ' DWORD
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
   MACRO RASPPPLCP = RASPPPLCPW
#ELSE
   MACRO RASPPPLCP = RASPPPLCPA
#ENDIF

#IF (%WINVER < &H600)    ' // SLIP

'/* Describes the results of a SLIP (Serial Line IP) projection.
'*/
'#define RASSLIPW struct tagRASSLIPW
' // Size = 40 bytes
TYPE RASSLIPW   ' Must be 4 byte aligned
   dwSize      AS DWORD                              ' DWORD
   dwError     AS DWORD                              ' DWORD
   szIpAddress AS WSTRINGZ * %RAS_MaxIpAddress + 1   ' WCHAR[RAS_MaxIpAddress + 1]
END TYPE

'#define RASSLIPA struct tagRASSLIPA
' // Size = 24 bytes
TYPE RASSLIPA   ' Must be 4 byte aligned
   dwSize      AS DWORD                            ' DWORD
   dwError     AS DWORD                            ' DWORD
   szIpAddress AS ASCIIZ * %RAS_MaxIpAddress + 1   ' CHAR[RAS_MaxIpAddress + 1]
END TYPE

#IF %DEF(%UNICODE)
   MACRO RASSLIP = RASSLIPW
#ELSE
   MACRO RASSLIP = RASSLIPA
#ENDIF

#ENDIF   ' // SLIP

#IF (%WINVER >= &H500)

'/* Describes the results of a PPP CCP (Compression Control Protocol)
'projection.
'*/

'/* RASPPPCCP 'dwCompressionAlgorithm' values.
'*/
%RASCCPCA_MPPC             = &H00000006???
%RASCCPCA_STAC             = &H00000005???

'/* RASPPPCCP 'dwOptions' values.
'*/
%RASCCPO_Compression       = &H00000001???
%RASCCPO_HistoryLess       = &H00000002???
%RASCCPO_Encryption56bit   = &H00000010???
%RASCCPO_Encryption40bit   = &H00000020???
%RASCCPO_Encryption128bit  = &H00000040???

'#define RASPPPCCP struct tagRASPPPCCP
' // Size = 24 bytes
TYPE RASPPPCCP   ' Must be 4 byte aligned
   dwSize                       AS DWORD   ' DWORD
   dwError                      AS DWORD   ' DWORD
   dwCompressionAlgorithm       AS DWORD   ' DWORD
   dwOptions                    AS DWORD   ' DWORD
   dwServerCompressionAlgorithm AS DWORD   ' DWORD
   dwServerOptions              AS DWORD   ' DWORD
END TYPE

#ENDIF

'/*
'** New Projection Information structure for PPP and IKEv2
'**
'*/
'#if (WINVER >= 0x601)

' // Size = 100 bytes
TYPE RASPPP_PROJECTION_INFO   ' Must be 4 byte aligned
   ' // IPv4 Projection Parameters
   dwIPv4NegotiationError          AS DWORD         ' DWORD
   ipv4Address                     AS RASIPV4ADDR   ' RASIPV4ADDR
   ipv4ServerAddress               AS RASIPV4ADDR   ' RASIPV4ADDR
   dwIPv4Options                   AS DWORD         ' DWORD
   dwIPv4ServerOptions             AS DWORD         ' DWORD
   ' // IPv6 Projection Parameters
   dwIPv6NegotiationError          AS DWORD         ' DWORD
   bInterfaceIdentifier(7)         AS BYTE          ' BYTE[8]
   bServerInterfaceIdentifier(7)   AS BYTE          ' BYTE[8]
   ' // LCP Options
   fBundled                        AS LONG          ' BOOL
   fMultilink                      AS LONG          ' BOOL
   dwAuthenticationProtocol        AS DWORD         ' DWORD
   dwAuthenticationData            AS DWORD         ' DWORD
   dwServerAuthenticationProtocol  AS DWORD         ' DWORD
   dwServerAuthenticationData      AS DWORD         ' DWORD
   dwEapTypeId                     AS DWORD         ' DWORD
   dwServerEapTypeId               AS DWORD         ' DWORD
   dwLcpOptions                    AS DWORD         ' DWORD
   dwLcpServerOptions              AS DWORD         ' DWORD
   ' // CCP options
   dwCcpError                      AS DWORD         ' DWORD
   dwCcpCompressionAlgorithm       AS DWORD         ' DWORD
   dwCcpServerCompressionAlgorithm AS DWORD         ' DWORD
   dwCcpOptions                    AS DWORD         ' DWORD
   dwCcpServerOptions              AS DWORD         ' DWORD
END TYPE

'/* RASIKEV2_PROJECTION_INFO 'dwFlags' values.
'*/
%RASIKEv2_FLAGS_MOBIKESUPPORTED  = &H00000001???
%RASIKEv2_FLAGS_BEHIND_NAT       = &H00000002???
%RASIKEv2_FLAGS_SERVERBEHIND_NAT = &H00000004???

'/* RASIKEV2_PROJECTION_INFO 'dwAuthenticatonProtocol' values.
'*/
%RASIKEv2_AUTH_MACHINECERTIFICATES = 1
%RASIKEv2_AUTH_EAP                 = 2

' // Size = 84 bytes
TYPE RASIKEV2_PROJECTION_INFO   ' Must be 4 byte aligned
   ' // IPv4 Projection Parameters
   dwIPv4NegotiationError   AS DWORD             ' DWORD
   ipv4Address              AS RASIPV4ADDR       ' RASIPV4ADDR
   ipv4ServerAddress        AS RASIPV4ADDR       ' RASIPV4ADDR
   ' // IPv6 Projection Parameters
   dwIPv6NegotiationError   AS DWORD             ' DWORD
   ipv6Address              AS RASIPV6ADDR       ' RASIPV6ADDR
   ipv6ServerAddress        AS RASIPV6ADDR       ' RASIPV6ADDR
   dwPrefixLength           AS DWORD             ' DWORD
   ' // AUTH
   dwAuthenticationProtocol AS DWORD             ' DWORD
   dwEapTypeId              AS DWORD             ' DWORD
   dwFlags                  AS DWORD             ' DWORD
   dwEncryptionMethod       AS DWORD             ' DWORD
   numIPv4ServerAddresses   AS DWORD             ' DWORD
   ipv4ServerAddresses      AS RASIPV4ADDR PTR   ' RASIPV4ADDR*
   numIPv6ServerAddresses   AS DWORD             ' DWORD
   ipv6ServerAddresses      AS RASIPV6ADDR PTR   ' RASIPV6ADDR*
END TYPE

' enum RASPROJECTION_INFO_TYPE
%PROJECTION_INFO_TYPE_PPP   = 1
%PROJECTION_INFO_TYPE_IKEv2 = 2

' // Size = 100 bytes
UNION RAS_PROJECTION_INFO_UNION   ' Must be 4 byte aligned
   ppp AS RASPPP_PROJECTION_INFO
   ikev2 AS RASIKEV2_PROJECTION_INFO
END UNION

' // Size = 108 bytes
TYPE RAS_PROJECTION_INFO   ' Must be 4 byte aligned
   version AS LONG   ' RASAPIVERSION
   type    AS LONG   ' RASPROJECTION_INFO_TYPE
   ' // Based on the connectionFlags, it should use appropriate projection info
   RAS_PROJECTION_INFO_UNION
END TYPE

'#endif

'/* If using RasDial message notifications, get the notification message code
'** by passing this string to the RegisterWindowMessageA() API.
'** WM_RASDIALEVENT is used only if a unique message cannot be registered.
'*/
$RASDIALEVENT    = "RasDialEvent"
%WM_RASDIALEVENT = &HCCCD??

'/* Prototypes for caller's RasDial callback handler.  Arguments are the
'** message ID (currently always WM_RASDIALEVENT), the current RASCONNSTATE and
'** the error that has occurred (or 0 if none).  Extended arguments are the
'** handle of the RAS connection and an extended error code.
'**
'** For RASDIALFUNC2, subsequent callback notifications for all
'** subentries can be cancelled by returning FALSE.
'*/
'typedef VOID (WINAPI *RASDIALFUNC)( UINT, RASCONNSTATE, DWORD );
'SUB RASDIALFUNC (BYVAL DWORD, BYVAL LONG, BYVAL DWORD)
'typedef VOID (WINAPI *RASDIALFUNC1)( HRASCONN, UINT, RASCONNSTATE, DWORD, DWORD );
'SUB RASDIALFUNC1 (BYVAL DWORD, BYVAL DWORD, BYVAL LONG, BYVAL DWORD, BYVAL DWORD)
'typedef DWORD (WINAPI *RASDIALFUNC2)( ULONG_PTR, DWORD, HRASCONN, UINT, RASCONNSTATE, DWORD, DWORD );
'SUB RASDIALFUNC2 (BYVAL DWORD, BYVAL DWORD, BYVAL DWORD, BYVAL DWORD, BYVAL LONG, BYVAL DWORD, BYVAL DWIRD)


'/* Information describing a RAS-capable device.
'*/
'#define RASDEVINFOW struct tagRASDEVINFOW
' // Size = 296 bytes
TYPE RASDEVINFOW   ' Must be 4 byte aligned
   dwSize       AS DWORD                               ' DWORD
   szDeviceType AS WSTRINGZ * %RAS_MaxDeviceType + 1   ' WCHAR[RAS_MaxDeviceType + 1]
   szDeviceName AS WSTRINGZ * %RAS_MaxDeviceName + 1   ' WCHAR[RAS_MaxDeviceName + 1]
END TYPE

'#define RASDEVINFOA struct tagRASDEVINFOA
' // Size = 152 bytes
TYPE RASDEVINFOA   ' Must be 4 byte aligned
   dwSize         AS DWORD                             ' DWORD
   szDeviceType   AS ASCIIZ * %RAS_MaxDeviceType + 1   ' CHAR[RAS_MaxDeviceType + 1]
   szDeviceName   AS ASCIIZ * %RAS_MaxDeviceName + 1   ' CHAR[RAS_MaxDeviceName + 1]
   alignment__(1) AS BYTE
END TYPE

#IF %DEF(%UNICODE)
   MACRO RASDEVINFO = RASDEVINFOW
#ELSE
   MACRO RASDEVINFO = RASDEVINFOA
#ENDIF

'/* RAS country information (currently retrieved from TAPI).
'*/
'#define RASCTRYINFO struct RASCTRYINFO
' // Size = 20 bytes
TYPE RASCTRYINFOA   ' Must be 4 byte aligned
   dwSize              AS DWORD   ' DWORD
   dwCountryID         AS DWORD   ' DWORD
   dwNextCountryID     AS DWORD   ' DWORD
   dwCountryCode       AS DWORD   ' DWORD
   dwCountryNameOffset AS DWORD   ' DWORD
END TYPE

' // Size = 20 bytes
TYPE RASCTRYINFOW   ' Must be 4 byte aligned
   dwSize              AS DWORD   ' DWORD
   dwCountryID         AS DWORD   ' DWORD
   dwNextCountryID     AS DWORD   ' DWORD
   dwCountryCode       AS DWORD   ' DWORD
   dwCountryNameOffset AS DWORD   ' DWORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO RASCTRYINFO = RASCTRYINFOW
#ELSE
   MACRO RASCTRYINFO = RASCTRYINFOA
#ENDIF

'/* There is currently no difference between
'** RASCTRYINFOA and RASCTRYINFOW.  This may
'** change in the future.
'*/
'#define RASCTRYINFOW   RASCTRYINFO
'#define RASCTRYINFOA   RASCTRYINFO

'#define LPRASCTRYINFOW RASCTRYINFOW*
'#define LPRASCTRYINFOA RASCTRYINFOW*
'#define LPRASCTRYINFO  RASCTRYINFO*

#IF (%WINVER >= &H500)

%ET_None         = 0   ' // No encryption
%ET_Require      = 1   ' // Require Encryption
%ET_RequireMax   = 2   ' // Require max encryption
%ET_Optional     = 3   ' // Do encryption if possible. None Ok.

#ENDIF

%VS_Default      = 0   ' // default (PPTP for now)
%VS_PptpOnly     = 1   ' // Only PPTP is attempted.
%VS_PptpFirst    = 2   ' // PPTP is tried first.
%VS_L2tpOnly     = 3   ' // Only L2TP is attempted.
%VS_L2tpFirst    = 4   ' // L2TP is tried first.

#IF %WINVER >= &H600
%VS_SstpOnly     = 5   ' // Only SSTP is attempted
%VS_SstpFirst    = 6   ' // SSTP is attempted first
#ENDIF

#IF %WINVER >= &H601
%VS_SstpOnly     = 5   ' // Only SSTP is attempted
%VS_SstpFirst    = 6   ' // SSTP is attempted first
#ENDIF

#IF %WINVER >= &H601
%VS_Ikev2Only    = 7   ' // Only VPN Ikev2 is attempted
%VS_Ikev2First   = 8   ' // VPN Ikev2 is attempted first
#ENDIF

'/* A RAS phone book entry.
'*/
'#define RASENTRYA struct tagRASENTRYA
' // Size = 2948 bytes
TYPE RASENTRYA   ' Must be 4 byte aligned
   dwSize                     AS DWORD                              ' DWORD
   dwfOptions                 AS DWORD                              ' DWORD
   dwCountryID                AS DWORD                              ' DWORD
   dwCountryCode              AS DWORD                              ' DWORD
   szAreaCode                 AS ASCIIZ * %RAS_MaxAreaCode + 1      ' CHAR[RAS_MaxAreaCode + 1]
   szLocalPhoneNumber         AS ASCIIZ * %RAS_MaxPhoneNumber + 1   ' CHAR[RAS_MaxPhoneNumber + 1]
   dwAlternateOffset          AS DWORD                              ' DWORD
   ipaddr                     AS RASIPADDR                          ' RASIPADDR
   ipaddrDns                  AS RASIPADDR                          ' RASIPADDR
   ipaddrDnsAlt               AS RASIPADDR                          ' RASIPADDR
   ipaddrWins                 AS RASIPADDR                          ' RASIPADDR
   ipaddrWinsAlt              AS RASIPADDR                          ' RASIPADDR
   dwFrameSize                AS DWORD                              ' DWORD
   dwfNetProtocols            AS DWORD                              ' DWORD
   dwFramingProtocol          AS DWORD                              ' DWORD
   szScript                   AS ASCIIZ * %MAX_PATH                 ' CHAR[MAX_PATH]
   szAutodialDll              AS ASCIIZ * %MAX_PATH                 ' CHAR[MAX_PATH]
   szAutodialFunc             AS ASCIIZ * %MAX_PATH                 ' CHAR[MAX_PATH]
   szDeviceType               AS ASCIIZ * %RAS_MaxDeviceType + 1    ' CHAR[RAS_MaxDeviceType + 1]
   szDeviceName               AS ASCIIZ * %RAS_MaxDeviceName + 1    ' CHAR[RAS_MaxDeviceName + 1]
   szX25PadType               AS ASCIIZ * %RAS_MaxPadType + 1       ' CHAR[RAS_MaxPadType + 1]
   szX25Address               AS ASCIIZ * %RAS_MaxX25Address + 1    ' CHAR[RAS_MaxX25Address + 1]
   szX25Facilities            AS ASCIIZ * %RAS_MaxFacilities + 1    ' CHAR[RAS_MaxFacilities + 1]
   szX25UserData              AS ASCIIZ * %RAS_MaxUserData + 1      ' CHAR[RAS_MaxUserData + 1]
   dwChannels                 AS DWORD                              ' DWORD
   dwReserved1                AS DWORD                              ' DWORD
   dwReserved2                AS DWORD                              ' DWORD
#IF (%WINVER >= &H401)
   dwSubEntries               AS DWORD                              ' DWORD
   dwDialMode                 AS DWORD                              ' DWORD
   dwDialExtraPercent         AS DWORD                              ' DWORD
   dwDialExtraSampleSeconds   AS DWORD                              ' DWORD
   dwHangUpExtraPercent       AS DWORD                              ' DWORD
   dwHangUpExtraSampleSeconds AS DWORD                              ' DWORD
   dwIdleDisconnectSeconds    AS DWORD                              ' DWORD
#ENDIF
#IF (%WINVER >= &H500)
   dwType                     AS DWORD                              ' DWORD
   dwEncryptionType           AS DWORD                              ' DWORD
   dwCustomAuthKey            AS DWORD                              ' DWORD
   guidId                     AS GUID                               ' GUID
   szCustomDialDll            AS ASCIIZ * %MAX_PATH                 ' CHAR[MAX_PATH]
   dwVpnStrategy              AS DWORD                              ' DWORD
#ENDIF
#IF (%WINVER >= &H501)
   dwfOptions2                AS DWORD                              ' DWORD
   dwfOptions3                AS DWORD                              ' DWORD
   szDnsSuffix                AS ASCIIZ * %RAS_MaxDnsSuffix         ' CHAR[RAS_MaxDnsSuffix]
   dwTcpWindowSize            AS DWORD                              ' DWORD
   szPrerequisitePbk          AS ASCIIZ * %MAX_PATH                 ' CHAR[MAX_PATH]
   szPrerequisiteEntry        AS ASCIIZ * %RAS_MaxEntryName + 1     ' CHAR[RAS_MaxEntryName + 1]
   dwRedialCount              AS DWORD                              ' DWORD
   dwRedialPause              AS DWORD                              ' DWORD
#ENDIF
#IF (%WINVER >= &H600)
   ipv6addrDns                AS RASIPV6ADDR                        ' RASIPV6ADDR
   ipv6addrDnsAlt             AS RASIPV6ADDR                        ' RASIPV6ADDR
   dwIPv4InterfaceMetric      AS DWORD                              ' DWORD
   dwIPv6InterfaceMetric      AS DWORD                              ' DWORD
#ENDIF
#IF (%WINVER >= &H501)
   alignment__(4)             AS BYTE
#ELSE
   alignment__(1)             AS BYTE
#ENDIF
#IF (%WINVER >= &H601)
   ipv6addr                   AS RASIPV6ADDR                        ' RASIPV6ADDR
   dwIPv6PrefixLength         AS DWORD                              ' DWORD
   dwNetworkOutageTime        AS DWORD                              ' DWORD
#ENDIF

END TYPE

'#define RASENTRYW struct tagRASENTRYW
' // Size = 5680 bytes
TYPE RASENTRYW   ' Must be 4 byte aligned
   dwSize                     AS DWORD                                ' DWORD
   dwfOptions                 AS DWORD                                ' DWORD
   dwCountryID                AS DWORD                                ' DWORD
   dwCountryCode              AS DWORD                                ' DWORD
   szAreaCode                 AS WSTRINGZ * %RAS_MaxAreaCode + 1      ' WCHAR[RAS_MaxAreaCode + 1]
   szLocalPhoneNumber         AS WSTRINGZ * %RAS_MaxPhoneNumber + 1   ' WCHAR[RAS_MaxPhoneNumber + 1]
   dwAlternateOffset          AS DWORD                                ' DWORD
   ipaddr                     AS RASIPADDR                            ' RASIPADDR
   ipaddrDns                  AS RASIPADDR                            ' RASIPADDR
   ipaddrDnsAlt               AS RASIPADDR                            ' RASIPADDR
   ipaddrWins                 AS RASIPADDR                            ' RASIPADDR
   ipaddrWinsAlt              AS RASIPADDR                            ' RASIPADDR
   dwFrameSize                AS DWORD                                ' DWORD
   dwfNetProtocols            AS DWORD                                ' DWORD
   dwFramingProtocol          AS DWORD                                ' DWORD
   szScript                   AS WSTRINGZ * %MAX_PATH                 ' WCHAR[MAX_PATH]
   szAutodialDll              AS WSTRINGZ * %MAX_PATH                 ' WCHAR[MAX_PATH]
   szAutodialFunc             AS WSTRINGZ * %MAX_PATH                 ' WCHAR[MAX_PATH]
   szDeviceType               AS WSTRINGZ * %RAS_MaxDeviceType + 1    ' WCHAR[RAS_MaxDeviceType + 1]
   szDeviceName               AS WSTRINGZ * %RAS_MaxDeviceName + 1    ' WCHAR[RAS_MaxDeviceName + 1]
   szX25PadType               AS WSTRINGZ * %RAS_MaxPadType + 1       ' WCHAR[RAS_MaxPadType + 1]
   szX25Address               AS WSTRINGZ * %RAS_MaxX25Address + 1    ' WCHAR[RAS_MaxX25Address + 1]
   szX25Facilities            AS WSTRINGZ * %RAS_MaxFacilities + 1    ' WCHAR[RAS_MaxFacilities + 1]
   szX25UserData              AS WSTRINGZ * %RAS_MaxUserData + 1      ' WCHAR[RAS_MaxUserData + 1]
   dwChannels                 AS DWORD                                ' DWORD
   dwReserved1                AS DWORD                                ' DWORD
   dwReserved2                AS DWORD                                ' DWORD
#IF (%WINVER >= &H401)
   dwSubEntries               AS DWORD                                ' DWORD
   dwDialMode                 AS DWORD                                ' DWORD
   dwDialExtraPercent         AS DWORD                                ' DWORD
   dwDialExtraSampleSeconds   AS DWORD                                ' DWORD
   dwHangUpExtraPercent       AS DWORD                                ' DWORD
   dwHangUpExtraSampleSeconds AS DWORD                                ' DWORD
   dwIdleDisconnectSeconds    AS DWORD                                ' DWORD
#ENDIF
#IF (%WINVER >= &H500)
   dwType                     AS DWORD                                ' DWORD
   dwEncryptionType           AS DWORD                                ' DWORD
   dwCustomAuthKey            AS DWORD                                ' DWORD
   guidId                     AS GUID                                 ' GUID
   szCustomDialDll            AS WSTRINGZ * %MAX_PATH                 ' WCHAR[MAX_PATH]
   dwVpnStrategy              AS DWORD                                ' DWORD
#ENDIF
#IF (%WINVER >= &H501)
   dwfOptions2                AS DWORD                                ' DWORD
   dwfOptions3                AS DWORD                                ' DWORD
   szDnsSuffix                AS WSTRINGZ * %RAS_MaxDnsSuffix         ' WCHAR[RAS_MaxDnsSuffix]
   dwTcpWindowSize            AS DWORD
   szPrerequisitePbk          AS WSTRINGZ * %MAX_PATH                 ' WCHAR[MAX_PATH]
   szPrerequisiteEntry        AS WSTRINGZ * %RAS_MaxEntryName + 1     ' WCHAR[RAS_MaxEntryName + 1]
   dwRedialCount              AS DWORD                                ' DWORD
   dwRedialPause              AS DWORD                                ' DWORD
#ENDIF
#IF (%WINVER >= &H600)
   ipv6addrDns                AS RASIPV6ADDR                          ' RASIPV6ADDR
   ipv6addrDnsAlt             AS RASIPV6ADDR                          ' RASIPV6ADDR
   dwIPv4InterfaceMetric      AS DWORD                                ' DWORD
   dwIPv6InterfaceMetric      AS DWORD                                ' DWORD
#ENDIF
#IF (%WINVER >= &H501)
   alignment__(1)             AS BYTE
#ENDIF
#IF (%WINVER >= &H601)
   ipv6addr                   AS RASIPV6ADDR                          ' RASIPV6ADDR
   dwIPv6PrefixLength         AS DWORD                                ' DWORD
   dwNetworkOutageTime        AS DWORD                                ' DWORD
#ENDIF
END TYPE

MACRO RASENTRY = RASENTRYA

'/* RASENTRY 'dwfOptions' bit flags.
'*/
%RASEO_UseCountryAndAreaCodes    = &H00000001???
%RASEO_SpecificIpAddr            = &H00000002???
%RASEO_SpecificNameServers       = &H00000004???
%RASEO_IpHeaderCompression       = &H00000008???
%RASEO_RemoteDefaultGateway      = &H00000010???
%RASEO_DisableLcpExtensions      = &H00000020???
%RASEO_TerminalBeforeDial        = &H00000040???
%RASEO_TerminalAfterDial         = &H00000080???
%RASEO_ModemLights               = &H00000100???
%RASEO_SwCompression             = &H00000200???
%RASEO_RequireEncryptedPw        = &H00000400???
%RASEO_RequireMsEncryptedPw      = &H00000800???
%RASEO_RequireDataEncryption     = &H00001000???
%RASEO_NetworkLogon              = &H00002000???
%RASEO_UseLogonCredentials       = &H00004000???
%RASEO_PromoteAlternates         = &H00008000???

#IF (%WINVER >= &H401)
%RASEO_SecureLocalFiles          = &H00010000???
#ENDIF

#IF (%WINVER >= &H500)
%RASEO_RequireEAP                = &H00020000???
%RASEO_RequirePAP                = &H00040000???
%RASEO_RequireSPAP               = &H00080000???
%RASEO_Custom                    = &H00100000???

%RASEO_PreviewPhoneNumber        = &H00200000???
%RASEO_SharedPhoneNumbers        = &H00800000???
%RASEO_PreviewUserPw             = &H01000000???
%RASEO_PreviewDomain             = &H02000000???
%RASEO_ShowDialingProgress       = &H04000000???
%RASEO_RequireCHAP               = &H08000000???
%RASEO_RequireMsCHAP             = &H10000000???
%RASEO_RequireMsCHAP2            = &H20000000???
%RASEO_RequireW95MSCHAP          = &H40000000???
%RASEO_CustomScript              = &H80000000???
#ENDIF

#IF (%WINVER >= &H501)
'//
'// RASENTRY dwfOptions2 bit flags
'//
%RASEO2_SecureFileAndPrint       = &H00000001???
%RASEO2_SecureClientForMSNet     = &H00000002???
%RASEO2_DontNegotiateMultilink   = &H00000004???
%RASEO2_DontUseRasCredentials    = &H00000008???
%RASEO2_UsePreSharedKey          = &H00000010???
%RASEO2_Internet                 = &H00000020???
%RASEO2_DisableNbtOverIP         = &H00000040???
%RASEO2_UseGlobalDeviceSettings  = &H00000080???
%RASEO2_ReconnectIfDropped       = &H00000100???
%RASEO2_SharePhoneNumbers        = &H00000200???
#ENDIF

#IF (%WINVER >= &H600)
%RASEO2_SecureRoutingCompartment     = &H00000400???
%RASEO2_UseTypicalSettings           = &H00000800???
%RASEO2_IPv6SpecificNameServers      = &H00001000???
%RASEO2_IPv6RemoteDefaultGateway     = &H00002000???
%RASEO2_RegisterIpWithDNS            = &H00004000???
%RASEO2_UseDNSSuffixForRegistration  = &H00008000???
%RASEO2_IPv4ExplicitMetric           = &H00010000???
%RASEO2_IPv6ExplicitMetric           = &H00020000???
%RASEO2_DisableIKENameEkuCheck       = &H00040000???
#ENDIF

#IF (%WINVER >= &H601)
%RASEO2_DisableClassBasedStaticRoute = &H00080000???
%RASEO2_SpecificIPv6Addr             = &H00100000???
%RASEO2_DisableMobility              = &H00200000???
%RASEO2_RequireMachineCertificates   = &H00400000???
#ENDIF

'/* RASENTRY 'dwProtocols' bit flags.
'*/
%RASNP_NetBEUI                   = &H00000001???
%RASNP_Ipx                       = &H00000002???
%RASNP_Ip                        = &H00000004???
' Note: Removed the condition because this constant is used in an assignment in MPRAPI.inc
'#IF (%WINVER >= &H600)
%RASNP_Ipv6                      = &H00000008???
'#ENDIF

'/* RASENTRY 'dwFramingProtocols' bit flags.
'*/
%RASFP_Ppp                       = &H00000001???
%RASFP_Slip                      = &H00000002???
%RASFP_Ras                       = &H00000004???

'/* RASENTRY 'szDeviceType' default strings.
'*/
$RASDT_Modem                     = "modem"
$RASDT_Isdn                      = "isdn"
$RASDT_X25                       = "x25"
$RASDT_Vpn                       = "vpn"
$RASDT_Pad                       = "pad"
$RASDT_Generic                   = "GENERIC"
$RASDT_Serial                    = "SERIAL"
$RASDT_FrameRelay                = "FRAMERELAY"
$RASDT_Atm                       = "ATM"
$RASDT_Sonet                     = "SONET"
$RASDT_SW56                      = "SW56"
$RASDT_Irda                      = "IRDA"
$RASDT_Parallel                  = "PARALLEL"
#IF (%WINVER >= &H501)
$RASDT_PPPoE                     = "PPPoE"
#ENDIF

$$RASDT_Modem                    = "modem"$$
$$RASDT_Isdn                     = "isdn"$$
$$RASDT_X25                      = "x25"$$
$$RASDT_Vpn                      = "vpn"$$
$$RASDT_Pad                      = "pad"$$
$$RASDT_Generic                  = "GENERIC"$$
$$RASDT_Serial                   = "SERIAL"$$
$$RASDT_FrameRelay               = "FRAMERELAY"$$
$$RASDT_Atm                      = "ATM"$$
$$RASDT_Sonet                    = "SONET"$$
$$RASDT_SW56                     = "SW56"$$
$$RASDT_Irda                     = "IRDA"$$
$$RASDT_Parallel                 = "PARALLEL"$$
#IF (%WINVER >= &H501)
$$RASDT_PPPoE                    = "PPPoE"$$
#ENDIF

#IF %DEF(%UNICODE)
MACRO RASDT_Modem      = $$RASDT_Modem
MACRO RASDT_Isdn       = $$RASDT_Isdn
MACRO RASDT_X25        = $$RASDT_X25
MACRO RASDT_Vpn        = $$RASDT_Vpn
MACRO RASDT_Pad        = $$RASDT_Pad
MACRO RASDT_Generic    = $$RASDT_Generic
MACRO RASDT_Serial     = $$RASDT_Serial
MACRO RASDT_FrameRelay = $$RASDT_FrameRelay
MACRO RASDT_Atm        = $$RASDT_Atm
MACRO RASDT_Sonet      = $$RASDT_Sonet
MACRO RASDT_SW56       = $$RASDT_SW56
MACRO RASDT_Irda       = $$RASDT_Irda
MACRO RASDT_Parallel   = $$RASDT_Parallel
#IF (%WINVER >= &H501)
MACRO RASDT_PPPoE      = $$RASDT_PPPoE
#ENDIF
#ELSE
MACRO RASDT_Modem      = $RASDT_Modem
MACRO RASDT_Isdn       = $RASDT_Isdn
MACRO RASDT_X25        = $RASDT_X25
MACRO RASDT_Vpn        = $RASDT_Vpn
MACRO RASDT_Pad        = $RASDT_Pad
MACRO RASDT_Generic    = $RASDT_Generic
MACRO RASDT_Serial     = $RASDT_Serial
MACRO RASDT_FrameRelay = $RASDT_FrameRelay
MACRO RASDT_Atm        = $RASDT_Atm
MACRO RASDT_Sonet      = $RASDT_Sonet
MACRO RASDT_SW56       = $RASDT_SW56
MACRO RASDT_Irda       = $RASDT_Irda
MACRO RASDT_Parallel   = $RASDT_Parallel
#IF (%WINVER >= &H501)
MACRO RASDT_PPPoE      = $RASDT_PPPoE
#ENDIF
#ENDIF

'// The entry type used to determine which UI properties
'// are to be presented to user.  This generally corresponds
'// to a Connections "add" wizard selection.
'//
%RASET_Phone     = 1  ' // Phone lines: modem, ISDN, X.25, etc
%RASET_Vpn       = 2  ' // Virtual private network

' Note: Removed the condition because this constant is used in an assignment in MPRAPI.inc
'#IF (%WINVER < &H600)
%RASET_Direct    = 3  ' // Direct connect: serial, parallel
'#ENDIF

%RASET_Internet  = 4  ' // BaseCamp internet
#IF (%WINVER >= &H501)
%RASET_Broadband = 5  ' // Broadband
#ENDIF

'/* Old AutoDial DLL function prototype.
'**
'** This prototype is documented for backward-compatibility
'** purposes only.  It is superceded by the RASADFUNCA
'** and RASADFUNCW definitions below.  DO NOT USE THIS
'** PROTOTYPE IN NEW CODE.  SUPPORT FOR IT MAY BE REMOVED
'** IN FUTURE VERSIONS OF RAS.
'*/
'typedef BOOL (WINAPI *ORASADFUNC)( HWND, LPSTR, DWORD, LPDWORD );
'FUNCTION ORASADFUNC (BYVAL DWORD, BYREF ASCIIZ, BYVAL DWORD, BYVAL DWORD) AS LONG

#IF (%WINVER >= &H400)

'/* Flags for RasConnectionNotification().
'*/
%RASCN_Connection        = &H00000001???
%RASCN_Disconnection     = &H00000002???
%RASCN_BandwidthAdded    = &H00000004???
%RASCN_BandwidthRemoved  = &H00000008???
%RASCN_Dormant           = &H00000010???
%RASCN_ReConnection      = &H00000020???

#ENDIF

#IF (%WINVER >= &H401)
'/* RASENTRY 'dwDialMode' values.
'*/
%RASEDM_DialAll                  = 1
%RASEDM_DialAsNeeded             = 2

'/* RASENTRY 'dwIdleDisconnectSeconds' constants.
'*/
%RASIDS_Disabled                 = &Hffffffff???
%RASIDS_UseGlobalValue           = 0

'/* AutoDial DLL function parameter block.
'*/
'#define RASADPARAMS struct tagRASADPARAMS
' // Size = 20 bytes
TYPE RASADPARAMS   ' Must be 4 byte aligned
   dwSize    AS DWORD   ' DWORD
   hwndOwner AS DWORD   ' HWND
   dwFlags   AS DWORD   ' DWORD
   xDlg      AS LONG    ' LONG
   yDlg      AS LONG    ' LONG
END TYPE

'/* AutoDial DLL function parameter block 'dwFlags.'
'*/
%RASADFLG_PositionDlg            = &H00000001???

'/* Prototype AutoDial DLL function.
'*/
'typedef BOOL (WINAPI *RASADFUNCA)( LPSTR, LPSTR, LPRASADPARAMS, LPDWORD );
'FUNCTION RASADFUNCA (BYREF ASCIIZ, BYREF ASCIIZ, BYVAL RASADPARAMS PTR, BYVAL DWORD) AS LONG
'typedef BOOL (WINAPI *RASADFUNCW)( LPWSTR, LPWSTR, LPRASADPARAMS, LPDWORD );
'FUNCTION RASADFUNCW (BYVAL DWORD, BYVAL DWORD, BYVAL RASADPARAMS PTR, BYVAL DWORD) AS LONG

'/* A RAS phone book multilinked sub-entry.
'*/
'#define RASSUBENTRYA struct tagRASSUBENTRYA
' // Size = 288 bytes
TYPE RASSUBENTRYA   ' Must be 4 byte aligned
   dwSize             AS DWORD                              ' DWORD
   dwfFlags           AS DWORD                              ' DWORD
   szDeviceType       AS ASCIIZ * %RAS_MaxDeviceType + 1    ' CHAR[RAS_MaxDeviceType + 1]
   szDeviceName       AS ASCIIZ * %RAS_MaxDeviceName + 1    ' CHAR[RAS_MaxDeviceName + 1]
   szLocalPhoneNumber AS ASCIIZ * %RAS_MaxPhoneNumber + 1   ' CHAR[RAS_MaxPhoneNumber + 1]
   dwAlternateOffset  AS DWORD                              ' DWORD
   alignment__(0)     AS BYTE
END TYPE

'#define RASSUBENTRYW struct tagRASSUBENTRYW
' // Size = 564 bytes
TYPE RASSUBENTRYW   ' Must be 4 byte aligned
   dwSize             AS DWORD                                ' DWORD
   dwfFlags           AS DWORD                                ' DWORD
   szDeviceType       AS WSTRINGZ * %RAS_MaxDeviceType + 1    ' WCHAR[RAS_MaxDeviceType + 1]
   szDeviceName       AS WSTRINGZ * %RAS_MaxDeviceName + 1    ' WCHAR[RAS_MaxDeviceName + 1]
   szLocalPhoneNumber AS WSTRINGZ * %RAS_MaxPhoneNumber + 1   ' WCHAR[RAS_MaxPhoneNumber + 1]
   dwAlternateOffset  AS DWORD                                ' DWORD
   alignment__(1)     AS BYTE
END TYPE

#IF %DEF(%UNICODE)
   MACRO RASSUBENTRY = RASSUBENTRYW
#ELSE
   MACRO RASSUBENTRY = RASSUBENTRYA
#ENDIF

'/* Ras{Get,Set}Credentials structure.  These calls
'** supercede Ras{Get,Set}EntryDialParams.
'*/
'#define RASCREDENTIALSA struct tagRASCREDENTIALSA
' // Size = 540 bytes
TYPE RASCREDENTIALSA   ' Must be 4 byte aligned
   dwSize         AS DWORD                 ' DWORD
   dwMask         AS DWORD                 ' DWORD
   szUserName     AS ASCIIZ * %UNLEN + 1   ' CHAR[UNLEN + 1]
   szPassword     AS ASCIIZ * %PWLEN + 1   ' CHAR[PWLEN + 1]
   szDomain       AS ASCIIZ * %DNLEN + 1   ' CHAR[DNLEN + 1]
   alignment__(1) AS BYTE
END TYPE

'#define RASCREDENTIALSW struct tagRASCREDENTIALSW
' // Size = 1068 bytes
TYPE RASCREDENTIALSW   ' Must be 4 byte aligned
   dwSize     AS DWORD                   ' DWORD
   dwMask     AS DWORD                   ' DWORD
   szUserName AS WSTRINGZ * %UNLEN + 1   ' WCHAR[UNLEN]
   szPassword AS WSTRINGZ * %PWLEN + 1   ' WCHAR[PWLEN]
   szDomain   AS WSTRINGZ * %DNLEN + 1   ' WCHAR[DNLEN]
END TYPE

#IF %DEF(%UNICODE)
   MACRO RASCREDENTIALS = RASCREDENTIALSW
#ELSE
   MACRO RASCREDENTIALS = RASCREDENTIALSA
#ENDIF

'/* RASCREDENTIALS 'dwMask' values.
'*/
%RASCM_UserName           = &H00000001???
%RASCM_Password           = &H00000002???
%RASCM_Domain             = &H00000004???
#IF (%WINVER >= &H501)
%RASCM_DefaultCreds       = &H00000008???
%RASCM_PreSharedKey       = &H00000010???
%RASCM_ServerPreSharedKey = &H00000020???
%RASCM_DDMPreSharedKey    = &H00000040???
#ENDIF

'/* AutoDial address properties.
'*/
'#define RASAUTODIALENTRYA struct tagRASAUTODIALENTRYA
' // Size = 272 bytes
TYPE RASAUTODIALENTRYA   ' Must be 4 byte aligned
   dwSize            AS DWORD                            ' DWORD
   dwFlags           AS DWORD                            ' DWORD
   dwDialingLocation AS DWORD                            ' DWORD
   szEntry           AS ASCIIZ * %RAS_MaxEntryName + 1   ' CHAR[RAS_MaxEntryName + 1]
   alignment__(2)    AS BYTE
END TYPE

'#define RASAUTODIALENTRYW struct tagRASAUTODIALENTRYW
' // Size = 528 bytes
TYPE RASAUTODIALENTRYW   ' Must be 4 byte aligned
   dwSize            AS DWORD                              ' DWORD
   dwFlags           AS DWORD                              ' DWORD
   dwDialingLocation AS DWORD                              ' DWORD
   szEntry           AS WSTRINGZ * %RAS_MaxEntryName + 1   ' WCHAR[RAS_MaxEntryName + 1]
   alignment__(1)    AS BYTE
END TYPE

#IF %DEF(%UNICODE)
   MACRO RASAUTODIALENTRY = RASAUTODIALENTRYW
#ELSE
   MACRO RASAUTODIALENTRY = RASAUTODIALENTRYA
#ENDIF

'/* AutoDial control parameter values for
'** Ras{Get,Set}AutodialParam.
'*/
%RASADP_DisableConnectionQuery          = 0
%RASADP_LoginSessionDisable             = 1
%RASADP_SavedAddressesLimit             = 2
%RASADP_FailedConnectionTimeout         = 3
%RASADP_ConnectionQueryTimeout          = 4

#ENDIF  ' // (WINVER >= 0x401)

#IF (%WINVER >= &H500)

'/* RasGetEapUserIdentity bit flags.
'** These have the same values as the RAS_EAP_FLAG_ flags in raseapif.h
'*/
%RASEAPF_NonInteractive          = &H00000002???
%RASEAPF_Logon                   = &H00000004???
%RASEAPF_Preview                 = &H00000008???

'/* RasGetEapUserIdentity structure.
'*/
'#define RASEAPUSERIDENTITYA struct tagRASEAPUSERIDENTITYA
' // Size = 268 bytes
TYPE RASEAPUSERIDENTITYA   ' Must be 4 byte aligned
   szUserName      AS ASCIIZ * %UNLEN + 1   ' CHAR[UNLEN + 1]
   dwSizeofEapInfo AS DWORD                 ' DWORD
   alignment1__(2) AS BYTE
   pbEapInfo(0)    AS BYTE                  ' BYTE[1]
   alignment2__(2) AS BYTE
END TYPE

' // Size = 524 bytes
TYPE RASEAPUSERIDENTITYW   ' Must be 4 byte aligned
   szUserName      AS WSTRINGZ * %UNLEN + 1   ' WCHAR[UNLEN + 1]
   dwSizeofEapInfo AS DWORD                   ' DWORD
   alignment1__(1) AS BYTE
   pbEapInfo(0)    AS BYTE                    ' BYTE[1]
   alignment2__(2) AS BYTE
END TYPE

#IF %DEF(%UNICODE)
   MACRO RASEAPUSERIDENTITY = RASEAPUSERIDENTITYW
#ELSE
   MACRO RASEAPUSERIDENTITY = RASEAPUSERIDENTITYA
#ENDIF

'typedef DWORD (WINAPI *PFNRASGETBUFFER) (
'                            PBYTE *ppBuffer,
'                            PDWORD pdwSize
'                            );

'FUNCTION FNRASGETBUFFER ( _
'   BYVAL ppBuffer AS DWORD, _
'   BYREF pdwSize AS DWORD _
'   ) AS DWORD

'typedef DWORD (WINAPI *PFNRASFREEBUFFER) (
'                            PBYTE pBufer);

'FUNCTION FNRASFREEBUFFER (BYVAL pBufer AS BYTE PTR) AS DWORD

'typedef DWORD (WINAPI *PFNRASSENDBUFFER) (
'                            HANDLE hPort,
'                            PBYTE  pBuffer,
'                            DWORD  dwSize
'                            );

'FUNCTION FNRASSENDBUFFER ( _
'   BYVAL hPort AS DWORD, _
'   BYVAL pBuffer AS BYTE PTR, _
'   BYVAL dwSize AS DWORD _
'   ) AS DWORD

'typedef DWORD (WINAPI *PFNRASRECEIVEBUFFER) (
'                            HANDLE hPort,
'                            PBYTE pBuffer,
'                            PDWORD pdwSize,
'                            DWORD  dwTimeOut,
'                            HANDLE hEvent
'                            );

'FUNCTION FNRASRECEIVEBUFFER ( _
'   BYVAL hPort AS DWORD, _
'   BYVAL pBuffer AS BYTE PTR, _
'   BYREF pdwSize AS DWORD, _
'   BYVAL dwTimeout AS DWORD, _
'   BYVAL hEvent AS DWORD _
'   ) AS DWORD

'typedef DWORD (WINAPI *PFNRASRETRIEVEBUFFER) (
'                            HANDLE hPort,
'                            PBYTE pBuffer,
'                            PDWORD pdwSize
'                            );

'FUNCTION FNRASRETRIEVEBUFFER (
'   BYVAL hPort AS DWORD, _
'   BYVAL pBuffer AS BYTE PTR, _
'   BYREF pdwSize AS DWORD _
'   ) AS DWORD

'typedef  DWORD (WINAPI *RasCustomScriptExecuteFn) (
'                            HANDLE hPort,
'                            LPCWSTR lpszPhonebook,
'                            LPCWSTR lpszEntryName,
'                            PFNRASGETBUFFER pfnRasGetBuffer,
'                            PFNRASFREEBUFFER pfnRasFreeBuffer,
'                            PFNRASSENDBUFFER pfnRasSendBuffer,
'                            PFNRASRECEIVEBUFFER pfnRasReceiveBuffer,
'                            PFNRASRETRIEVEBUFFER pfnRasRetrieveBuffer,
'                            HWND hWnd,
'                            RASDIALPARAMS *pRasDialParams,
'                            PVOID pvReserved
'                            );

'FUNCTION RasCustomScriptExecuteFn ( _
'   BYVAL hPort AS DWORD, _
'   BYREF lpszPhonebook AS WSTRINGZ, _
'   BYREF lpszEntryName AS WSTRINGZ, _
'   BYVAL pfnRasGetBuffer AS DWORD, _
'   BYVAL pfnRasFreeBuffer AS DWORD, _
'   BYVAL pfnRasSendBuffer AS DWORD, _
'   BYVAL pfnRasReceiveBuffer AS DWORD, _
'   BYVAL pfnRasRetrieveBuffer AS DWORD, _
'   BYVAL hWnd AS DWORD, _
'   BYREF pRasDialParams AS RASDIALPARAMS, _
'   BYVAL pvReserved AS DWORD _
'   ) AS DWORD


#ENDIF   ' // (WINVER >= 0x500)

#IF (%WINVER >= &H0501)

'#define RASCOMMSETTINGS struct tagRASCOMMSETTINGS
' // Size = 8 bytes
TYPE RASCOMMSETTINGS   ' Must be 4 byte aligned
   dwSize    AS DWORD   ' DWORD
   bParity   AS BYTE    ' BYTE
   bStop     AS BYTE    ' BYTE
   bByteSize AS BYTE    ' BYTE
   bAlign    AS BYTE    ' BYTE
END TYPE

'typedef DWORD (WINAPI *PFNRASSETCOMMSETTINGS) (
'                            HANDLE hPort,
'                            RASCOMMSETTINGS *pRasCommSettings,
'                            PVOID  pvReserved
'                            );

'FUNCTION FNRASSETCOMMSETTINGS ( _
'   BYVAL hPort AS DWORD, _
'   BYREF pRasCommSettings AS RASCOMMSETTINGS, _
'   BYVAL pReserved AS DWORD _
'   )

'#define RASCUSTOMSCRIPTEXTENSIONS struct tagRASCUSTOMSCRIPTEXTENSIONS
' // Size = 8 bytes
TYPE RASCUSTOMSCRIPTEXTENSIONS   ' Must be 4 byte aligned
   dwSize                AS DWORD   ' DWORD
   pfnRasSetCommSettings AS DWORD   ' PFNRASSETCOMMSETTINGS
END TYPE

#ENDIF


'/* External RAS API function prototypes.
'*/

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION RasDialA LIB "RasApi32.dll" ALIAS "RasDialA" _
    (lpRasDialExtensions AS RASDIALEXTENSIONS, lpszPhoneBook AS ASCIIZ, _
    lpRasDialParams AS RASDIALPARAMSA, BYVAL dwNotiferTYPE AS DWORD, _
    lpvNotifier AS ANY, lphRasConn AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION RasDialA IMPORT "rasapi32.dll" ALIAS "RasDialA" ( _
   BYREF lpRasDialExtensions AS RASDIALEXTENSIONS _     ' __in_opt  LPRASDIALEXTENSIONS lpRasDialExtensions
 , BYREF lpszPhonebook AS ASCIIZ _                      ' __in_opt  LPCSTR lpszPhonebook
 , BYREF lpRasDialParams AS RASDIALPARAMSA _            ' __in      LPRASDIALPARAMSA lpRasDialParams
 , BYVAL dwNotifierType AS DWORD _                      ' __in      DWORD dwNotifierType
 , BYVAL lpvNotifier AS DWORD _                         ' __in_opt  LPVOID lpvNotifier
 , BYREF lphRasConn AS DWORD _                          ' __out     LPHRASCONN lphRasConn
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION RasDialW LIB "RasApi32.dll" ALIAS "RasDialW" _
    (lpRasDialExtensions AS RASDIALEXTENSIONS, lpszPhoneBook AS WSTRINGZ, _
    lpRasDialParams AS RASDIALPARAMSW, BYVAL dwNotiferTYPE AS DWORD, _
    lpvNotifier AS ANY, lphRasConn AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION RasDialW IMPORT "rasapi32.dll" ALIAS "RasDialW" ( _
   BYREF lpRasDialExtensions AS RASDIALEXTENSIONS _     ' __in_opt  LPRASDIALEXTENSIONS lpRasDialExtensions
 , BYREF lpszPhonebook AS WSTRINGZ _                    ' __in_opt  LPCWSTR lpszPhonebook
 , BYREF lpRasDialParams AS RASDIALPARAMSW _            ' __in      LPRASDIALPARAMSW lpRasDialParams
 , BYVAL dwNotifierType AS DWORD _                      ' __in      DWORD dwNotifierType
 , BYVAL lpvNotifier AS DWORD _                         ' __in_opt  LPVOID lpvNotifier
 , BYREF lphRasConn AS DWORD _                          ' __out     LPHRASCONN lphRasConn
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
   MACRO RasDial = RasDialW
#ELSE
   MACRO RasDial = RasDialA
#ENDIF

DECLARE FUNCTION RasEnumConnectionsA IMPORT "rasapi32.dll" ALIAS "RasEnumConnectionsA" ( _
   BYREF lprasconn AS RASCONNA _                        ' __inout_opt LPRASCONNA lprasconn
 , BYREF lpcb AS DWORD _                                ' __inout     LPDWORD lpcb
 , BYREF lpcConnections AS DWORD _                      ' __out       LPDWORD lpcConnections
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasEnumConnectionsW IMPORT "rasapi32.dll" ALIAS "RasEnumConnectionsW" ( _
   BYREF lprasconn AS RASCONNW _                        ' __inout_opt LPRASCONNW lprasconn
 , BYREF lpcb AS DWORD _                                ' __inout     LPDWORD lpcb
 , BYREF lpcConnections AS DWORD _                      ' __out       LPDWORD lpcConnections
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasEnumConnections = RasEnumConnectionsW
#ELSE
   MACRO RasEnumConnections = RasEnumConnectionsA
#ENDIF

DECLARE FUNCTION RasEnumEntriesA IMPORT "rasapi32.dll" ALIAS "RasEnumEntriesA" ( _
   BYREF reserved AS ASCIIZ _                           ' __in_opt    LPCSTR reserved
 , BYREF lpszPhonebook AS ASCIIZ _                      ' __in_opt    LPCSTR lpszPhonebook
 , BYREF lprasentryname AS RASENTRYNAMEA _              ' __inout_opt LPRASENTRYNAMEA lprasentryname
 , BYREF lpcb AS DWORD _                                ' __inout     LPDWORD lpcb
 , BYREF lpcEntries AS DWORD _                          ' __out       LPDWORD lpcEntries
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasEnumEntriesW IMPORT "rasapi32.dll" ALIAS "RasEnumEntriesW" ( _
   BYREF reserved AS WSTRINGZ _                         ' __in_opt    LPCWSTR reserved
 , BYREF lpszPhonebook AS WSTRINGZ _                    ' __in_opt    LPCWSTR lpszPhonebook
 , BYREF lprasentryname AS RASENTRYNAMEW _              ' __inout_opt LPRASENTRYNAMEW lprasentryname
 , BYREF lpcb AS DWORD _                                ' __inout     LPDWORD lpcb
 , BYREF lpcEntries AS DWORD _                          ' __out       LPDWORD lpcEntries
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasEnumEntries = RasEnumEntriesW
#ELSE
   MACRO RasEnumEntries = RasEnumEntriesA
#ENDIF

DECLARE FUNCTION RasGetConnectStatusA IMPORT "rasapi32.dll" ALIAS "RasGetConnectStatusA" ( _
   BYVAL hrasconn AS DWORD _                            ' __in    HRASCONN hrasconn
 , BYREF lprasconnstatus AS RASCONNSTATUSA _            ' __inout LPRASCONNSTATUSA lprasconnstatus
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasGetConnectStatusW IMPORT "rasapi32.dll" ALIAS "RasGetConnectStatusW" ( _
   BYVAL hrasconn AS DWORD _                            ' __in    HRASCONN hrasconn
 , BYREF lprasconnstatus AS RASCONNSTATUSW _            ' __inout LPRASCONNSTATUSW lprasconnstatus
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasGetConnectStatus = RasGetConnectStatusW
#ELSE
   MACRO RasGetConnectStatus = RasGetConnectStatusA
#ENDIF

DECLARE FUNCTION RasGetErrorStringA IMPORT "rasapi32.dll" ALIAS "RasGetErrorStringA" ( _
   BYVAL uErrorValue AS DWORD _                         ' __in  UINT uErrorValue
 , BYREF lpszErrorString AS ASCIIZ _                    ' __out LPSTR lpszErrorString
 , BYVAL cBufSize AS DWORD _                            ' __in  DWORD cBufSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasGetErrorStringW IMPORT "rasapi32.dll" ALIAS "RasGetErrorStringW" ( _
   BYVAL uErrorValue AS DWORD _                         ' __in  UINT uErrorValue
 , BYREF lpszErrorString AS WSTRINGZ _                  ' __out LPWSTR lpszErrorString
 , BYVAL cBufSize AS DWORD _                            ' __in  DWORD cBufSize
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasGetErrorString = RasGetErrorStringW
#ELSE
   MACRO RasGetErrorString = RasGetErrorStringA
#ENDIF

DECLARE FUNCTION RasHangUpA IMPORT "rasapi32.dll" ALIAS "RasHangUpA" ( _
   BYVAL hrasconn AS DWORD _                            ' __in HRASCONN hrasconn
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasHangUpW IMPORT "rasapi32.dll" ALIAS "RasHangUpW" ( _
   BYVAL hrasconn AS DWORD _                            ' __in HRASCONN hrasconn
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasHangUp = RasHangUpW
#ELSE
   MACRO RasHangUp = RasHangUpA
#ENDIF

DECLARE FUNCTION RasGetProjectionInfoA IMPORT "rasapi32.dll" ALIAS "RasGetProjectionInfoA" ( _
   BYVAL hrasconn AS DWORD _                            ' __in    HRASCONN hrasconn
 , BYVAL rasprojection AS LONG _                        ' __in    RASPROJECTION rasprojection
 , BYREF lpprojection AS ANY _                          ' __out   LPVOID lpprojection
 , BYREF lpcb AS DWORD _                                ' __inout LPDWORD lpcb
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasGetProjectionInfoW IMPORT "rasapi32.dll" ALIAS "RasGetProjectionInfoW" ( _
   BYVAL hrasconn AS DWORD _                            ' __in    HRASCONN hrasconn
 , BYVAL rasprojection AS LONG _                        ' __in    RASPROJECTION rasprojection
 , BYREF lpprojection AS ANY _                          ' __out   LPVOID lpprojection
 , BYREF lpcb AS DWORD _                                ' __inout LPDWORD lpcb
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasGetProjectionInfo = RasGetProjectionInfoW
#ELSE
   MACRO RasGetProjectionInfo = RasGetProjectionInfoA
#ENDIF

DECLARE FUNCTION RasCreatePhonebookEntryA IMPORT "rasapi32.dll" ALIAS "RasCreatePhonebookEntryA" ( _
   BYVAL hwnd AS DWORD _                                ' __in     HWND hwnd
 , BYREF lpszPhonebook AS ASCIIZ _                      ' __in_opt LPCSTR lpszPhonebook
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasCreatePhonebookEntryW IMPORT "rasapi32.dll" ALIAS "RasCreatePhonebookEntryW" ( _
   BYVAL hwnd AS DWORD _                                ' __in     HWND hwnd
 , BYREF lpszPhonebook AS WSTRINGZ _                    ' __in_opt LPCWSTR lpszPhonebook
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasCreatePhonebookEntry = RasCreatePhonebookEntryW
#ELSE
   MACRO RasCreatePhonebookEntry = RasCreatePhonebookEntryA
#ENDIF

DECLARE FUNCTION RasEditPhonebookEntryA IMPORT "rasapi32.dll" ALIAS "RasEditPhonebookEntryA" ( _
   BYVAL hwnd AS DWORD _                                ' __in     HWND hwnd
 , BYREF lpszPhonebook AS ASCIIZ _                      ' __in_opt LPCSTR lpszPhonebook
 , BYREF lpszEntryName AS ASCIIZ _                      ' __in     LPCSTR lpszEntryName
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasEditPhonebookEntryW IMPORT "rasapi32.dll" ALIAS "RasEditPhonebookEntryW" ( _
   BYVAL hwnd AS DWORD _                                ' __in     HWND hwnd
 , BYREF lpszPhonebook AS WSTRINGZ _                    ' __in_opt LPCWSTR lpszPhonebook
 , BYREF lpszEntryName AS WSTRINGZ _                    ' __in     LPCWSTR lpszEntryName
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasEditPhonebookEntry = RasEditPhonebookEntryW
#ELSE
   MACRO RasEditPhonebookEntry = RasEditPhonebookEntryA
#ENDIF

DECLARE FUNCTION RasSetEntryDialParamsA IMPORT "rasapi32.dll" ALIAS "RasSetEntryDialParamsA" ( _
   BYREF lpszPhonebook AS ASCIIZ _                      ' __in LPCSTR lpszPhonebook
 , BYREF lprasdialparams AS RASDIALPARAMSA _            ' __in LPRASDIALPARAMSA lprasdialparams
 , BYVAL fRemovePassword AS LONG _                      ' __in BOOL fRemovePassword
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasSetEntryDialParamsW IMPORT "rasapi32.dll" ALIAS "RasSetEntryDialParamsW" ( _
   BYREF lpszPhonebook AS WSTRINGZ _                    ' __in LPCWSTR lpszPhonebook
 , BYREF lprasdialparams AS RASDIALPARAMSW _            ' __in LPRASDIALPARAMSW lprasdialparams
 , BYVAL fRemovePassword AS LONG _                      ' __in BOOL fRemovePassword
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasSetEntryDialParams = RasSetEntryDialParamsW
#ELSE
   MACRO RasSetEntryDialParams = RasSetEntryDialParamsA
#ENDIF

DECLARE FUNCTION RasGetEntryDialParamsA IMPORT "rasapi32.dll" ALIAS "RasGetEntryDialParamsA" ( _
   BYREF lpszPhonebook AS ASCIIZ _                      ' __in:opt LPCSTR lpszPhonebook
 , BYREF lprasdialparams AS RASDIALPARAMSA _            ' __inout  LPRASDIALPARAMSA lprasdialparams
 , BYREF lpfPassword AS LONG _                          ' __out    LPBOOL lpfPassword
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasGetEntryDialParamsW IMPORT "rasapi32.dll" ALIAS "RasGetEntryDialParamsW" ( _
   BYREF lpszPhonebook AS WSTRINGZ _                    ' __in_opt LPCWSTR lpszPhonebook
 , BYREF lprasdialparams AS RASDIALPARAMSW _            ' __inout  LPRASDIALPARAMSW lprasdialparams
 , BYREF lpfPassword AS LONG _                          ' __out    LPBOOL lpfPassword
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasGetEntryDialParams = RasGetEntryDialParamsW
#ELSE
   MACRO RasGetEntryDialParams = RasGetEntryDialParamsA
#ENDIF

DECLARE FUNCTION RasEnumDevicesA IMPORT "rasapi32.dll" ALIAS "RasEnumDevicesA" ( _
   BYREF lpRasDevInfo AS RASDEVINFOA _                  ' __inout_opr LPRASDEVINFOA lpRasDevInfo
 , BYREF lpcb AS DWORD _                                ' __inout     LPDWORD lpcb
 , BYREF lpcDevices AS DWORD _                          ' __out       LPDWORD lpcDevices
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasEnumDevicesW IMPORT "rasapi32.dll" ALIAS "RasEnumDevicesW" ( _
   BYREF lpRasDevInfo AS RASDEVINFOW _                  ' __inout_opt LPRASDEVINFOW lpRasDevInfo
 , BYREF lpcb AS DWORD _                                ' __inout     LPDWORD lpcb
 , BYREF lpcDevices AS DWORD _                          ' __out       LPDWORD lpcDevices
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasEnumDevices = RasEnumDevicesW
#ELSE
   MACRO RasEnumDevices = RasEnumDevicesA
#ENDIF

DECLARE FUNCTION RasGetCountryInfoA IMPORT "rasapi32.dll" ALIAS "RasGetCountryInfoA" ( _
   BYREF lpRasCtryInfo AS RASCTRYINFOA _                ' __inout_opt LPRASCTRYINFOA lpRasCtryInfo
 , BYREF lpdwSize AS DWORD _                            ' __inout     LPDWORD lpdwSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasGetCountryInfoW IMPORT "rasapi32.dll" ALIAS "RasGetCountryInfoW" ( _
   BYREF lpRasCtryInfo AS RASCTRYINFOW _                ' __inout_opt LPRASCTRYINFOW lpRasCtryInfo
 , BYREF lpdwSize AS DWORD _                            ' __inout     LPDWORD lpdwSize
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasGetCountryInfo = RasGetCountryInfoW
#ELSE
   MACRO RasGetCountryInfo = RasGetCountryInfoA
#ENDIF

DECLARE FUNCTION RasGetEntryPropertiesA IMPORT "rasapi32.dll" ALIAS "RasGetEntryPropertiesA" ( _
   BYREF lpszPhonebook AS ASCIIZ _                      ' __in_opt    LPCSTR lpszPhonebook
 , BYREF lpszEntry AS ASCIIZ _                          ' __in        LPCSTR lpszEntry
 , BYREF lpRasEntry AS RASENTRYA _                      ' __inout_opt LPRASENTRYA lpRasEntry
 , BYREF lpdwEntryInfoSize AS DWORD _                   ' __inout     LPDWORD lpdwEntryInfoSize
 , OPTIONAL BYVAL lpbDeviceInfo AS BYTE PTR _           ' __out_opt   LPBYTE lpbDeviceInfo // This parameter is no longer used and should setto NULL
 , OPTIONAL BYREF lpdwDeviceInfoSize AS DWORD _         ' __inout_opt LPDWORD lpdwDeviceInfoSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasGetEntryPropertiesW IMPORT "rasapi32.dll" ALIAS "RasGetEntryPropertiesW" ( _
   BYREF lpszPhonebook AS WSTRINGZ _                    ' __in_opt    LPCWSTR lpszPhonebook
 , BYREF lpszEntry AS WSTRINGZ _                        ' __in        LPCWSTR lpszEntry
 , BYREF lpRasEntry AS RASENTRYW _                      ' __inout_opt LPRASENTRYW lpRasEntry
 , BYREF lpdwEntryInfoSize AS DWORD _                   ' __inout     LPDWORD lpdwEntryInfoSize
 , OPTIONAL BYVAL lpbDeviceInfo AS BYTE PTR _           ' __out_opt   LPBYTE lpbDeviceInfo // This parameter is no longer used and should setto NULL
 , OPTIONAL BYREF lpdwDeviceInfoSize AS DWORD _         ' __inout_opt LPDWORD lpdwDeviceInfoSize
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasGetEntryProperties = RasGetEntryPropertiesW
#ELSE
   MACRO RasGetEntryProperties = RasGetEntryPropertiesA
#ENDIF

DECLARE FUNCTION RasSetEntryPropertiesA IMPORT "rasapi32.dll" ALIAS "RasSetEntryPropertiesA" ( _
   BYREF lpszPhonebook AS ASCIIZ _                      ' __in_opt LPCSTR lpszPhonebook
 , BYREF lpszEntry AS ASCIIZ _                          ' __in     LPCSTR lpszEntry
 , BYREF lpRasEntry AS RASENTRYA _                      ' __in     LPRASENTRYA lpRasEntry
 , BYVAL dwEntryInfoSize AS DWORD _                     ' __in     DWORD dwEntryInfoSize
 , BYVAL lpbDeviceInfo AS BYTE PTR _                    ' __in_opt LPBYTE lpbDeviceInfo
 , BYVAL dwDeviceInfoSize AS DWORD _                    ' __in     DWORD dwDeviceInfoSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasSetEntryPropertiesW IMPORT "rasapi32.dll" ALIAS "RasSetEntryPropertiesW" ( _
   BYREF lpszPhonebook AS WSTRINGZ _                    ' __in_opt LPCWSTR lpszPhonebook
 , BYREF lpszEntry AS WSTRINGZ _                        ' __in     LPCWSTR lpszEntry
 , BYREF lpRasEntry AS RASENTRYW _                      ' __in     LPRASENTRYW lpRasEntry
 , BYVAL dwEntryInfoSize AS DWORD _                     ' __in     DWORD dwEntryInfoSize
 , BYVAL lpbDeviceInfo AS BYTE PTR _                    ' __in_opt LPBYTE lpbDeviceInfo
 , BYVAL dwDeviceInfoSize AS DWORD _                    ' __in     DWORD dwDeviceInfoSize
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasSetEntryProperties = RasSetEntryPropertiesW
#ELSE
   MACRO RasSetEntryProperties = RasSetEntryPropertiesA
#ENDIF

DECLARE FUNCTION RasRenameEntryA IMPORT "rasapi32.dll" ALIAS "RasRenameEntryA" ( _
   BYREF lpszPhonebook AS ASCIIZ _                      ' __in_opt LPCSTR lpszPhonebook
 , BYREF lpszOldEntry AS ASCIIZ _                       ' __in     LPCSTR lpszOldEntry
 , BYREF lpszNewEntry AS ASCIIZ _                       ' __in     LPCSTR lpszNewEntry
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasRenameEntryW IMPORT "rasapi32.dll" ALIAS "RasRenameEntryW" ( _
   BYREF lpszPhonebook AS WSTRINGZ _                    ' __in_opt LPCWSTR lpszPhonebook
 , BYREF lpszOldEntry AS WSTRINGZ _                     ' __in     LPCWSTR lpszOldEntry
 , BYREF lpszNewEntry AS WSTRINGZ _                     ' __in     LPCWSTR lpszNewEntry
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasRenameEntry = RasRenameEntryW
#ELSE
   MACRO RasRenameEntry = RasRenameEntryA
#ENDIF

DECLARE FUNCTION RasDeleteEntryA IMPORT "rasapi32.dll" ALIAS "RasDeleteEntryA" ( _
   BYREF lpszPhonebook AS ASCIIZ _                      ' __in_opt LPCSTR lpszPhonebook
 , BYREF lpszEntry AS ASCIIZ _                          ' __in     LPCSTR lpszEntry
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasDeleteEntryW IMPORT "rasapi32.dll" ALIAS "RasDeleteEntryW" ( _
   BYREF lpszPhonebook AS WSTRINGZ _                    ' __in_opt LPCWSTR lpszPhonebook
 , BYREF lpszEntry AS WSTRINGZ _                        ' __in     LPCWSTR lpszEntry
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasDeleteEntry = RasDeleteEntryW
#ELSE
   MACRO RasDeleteEntry = RasDeleteEntryA
#ENDIF

DECLARE FUNCTION RasValidateEntryNameA IMPORT "rasapi32.dll" ALIAS "RasValidateEntryNameA" ( _
   BYREF lpszPhonebook AS ASCIIZ _                      ' __in_opt LPCSTR lpszPhonebook
 , BYREF lpszEntry AS ASCIIZ _                          ' __in     LPCSTR lpszEntry
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasValidateEntryNameW IMPORT "rasapi32.dll" ALIAS "RasValidateEntryNameW" ( _
   BYREF lpszPhonebook AS WSTRINGZ _                    ' __in_opt LPCWSTR lpszPhonebook
 , BYREF lpszEntry AS WSTRINGZ _                        ' __in     LPCWSTR lpszEntry
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasValidateEntryName = RasValidateEntryNameW
#ELSE
   MACRO RasValidateEntryName = RasValidateEntryNameA
#ENDIF

DECLARE FUNCTION RasConnectionNotificationA IMPORT "rasapi32.dll" ALIAS "RasConnectionNotificationA" ( _
   BYVAL hrasconn AS DWORD _                            ' __in HRASCONN hrasconn
 , BYVAL hEvent AS DWORD _                              ' __in HANDLE hEvent
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasConnectionNotificationW IMPORT "rasapi32.dll" ALIAS "RasConnectionNotificationW" ( _
   BYVAL hrasconn AS DWORD _                            ' __in HRASCONN hrasconn
 , BYVAL hEvent AS DWORD _                              ' __in HANDLE hEvent
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasConnectionNotification = RasConnectionNotificationW
#ELSE
   MACRO RasConnectionNotification = RasConnectionNotificationA
#ENDIF

#IF (%WINVER >= &H401)
DECLARE FUNCTION RasGetSubEntryHandleA IMPORT "rasapi32.dll" ALIAS "RasGetSubEntryHandleA" ( _
   BYVAL hRasConn AS DWORD _                            ' __in  HRASCONN hRasConn
 , BYVAL dwSubEntry AS DWORD _                          ' __in  DWORD dwSubEntry
 , BYREF lphRasConn AS DWORD _                          ' __out LPHRASCONN lphRasConn
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasGetSubEntryHandleW IMPORT "rasapi32.dll" ALIAS "RasGetSubEntryHandleW" ( _
   BYVAL hRasConn AS DWORD _                            ' __in  HRASCONN hRasConn
 , BYVAL dwSubEntry AS DWORD _                          ' __in  DWORD dwSubEntry
 , BYREF lphRasConn AS DWORD _                          ' __out LPHRASCONN lphRasConn
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasGetSubEntryHandle = RasGetSubEntryHandleW
#ELSE
   MACRO RasGetSubEntryHandle = RasGetSubEntryHandleA
#ENDIF

DECLARE FUNCTION RasGetCredentialsA IMPORT "rasapi32.dll" ALIAS "RasGetCredentialsA" ( _
   BYREF lpszPhonebook AS ASCIIZ _                      ' __in_opt LPCSTR lpszPhonebook
 , BYREF lpszEntry AS ASCIIZ _                          ' __in     LPCSTR lpszEntry
 , BYREF lpCredentials AS RASCREDENTIALSA _             ' __inout  LPRASCREDENTIALSA lpCredentials
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasGetCredentialsW IMPORT "rasapi32.dll" ALIAS "RasGetCredentialsW" ( _
   BYREF lpszPhonebook AS WSTRINGZ _                    ' __in_opt LPCWSTR lpszPhonebook
 , BYREF lpszEntry AS WSTRINGZ _                        ' __in     LPCWSTR lpszEntry
 , BYREF lpCredentials AS RASCREDENTIALSW _             ' __inout  LPRASCREDENTIALSW lpCredentials
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasGetCredentials = RasGetCredentialsW
#ELSE
   MACRO RasGetCredentials = RasGetCredentialsA
#ENDIF

DECLARE FUNCTION RasSetCredentialsA IMPORT "rasapi32.dll" ALIAS "RasSetCredentialsA" ( _
   BYREF lpszPhonebook AS ASCIIZ _                      ' __in_opt LPCSTR lpszPhonebook
 , BYREF lpszEntry AS ASCIIZ _                          ' __in     LPCSTR lpszEntry
 , BYREF lpCredentials AS RASCREDENTIALSA  _            ' __in     LPRASCREDENTIALSA lpCredentials
 , BYVAL fClearCredentials AS LONG _                    ' __in     BOOL fClearCredentials
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasSetCredentialsW IMPORT "rasapi32.dll" ALIAS "RasSetCredentialsW" ( _
   BYREF lpszPhonebook AS WSTRINGZ _                    ' __in_opt LPCWSTR lpszPhonebook
 , BYREF lpszEntry AS WSTRINGZ _                        ' __in     LPCWSTR lpszEntry
 , BYREF lpCredentials AS RASCREDENTIALSW _             ' __in     LPRASCREDENTIALSW lpCredentials
 , BYVAL fClearCredentials AS LONG _                    ' __in     BOOL fClearCredentials
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasSetCredentials = RasSetCredentialsW
#ELSE
   MACRO RasSetCredentials = RasSetCredentialsA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION RasGetSubEntryPropertiesA LIB "RasApi32.dll" _
    ALIAS "RasGetSubEntryPropertiesA" (lpszPhonebook AS ASCIIZ, _
    lpszEntry AS ASCIIZ, BYVAL dwSubEntry AS DWORD, _
    lpRasSubEntry AS RASSUBENTRYA, lpdwcb AS DWORD, lpbDeviceConfig AS BYTE, _
    pd2 AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION RasGetSubEntryPropertiesA IMPORT "rasapi32.dll" ALIAS "RasGetSubEntryPropertiesA" ( _
   BYREF lpszPhonebook AS ASCIIZ _                      ' __in_opt    LPCSTR lpszPhonebook
 , BYREF lpszEntry AS ASCIIZ _                          ' __in        LPCSTR lpszEntry
 , BYVAL dwSubEntry AS DWORD _                          ' __in        DWORD dwSubEntry
 , BYREF lpRasSubEntry AS RASSUBENTRYA _                ' __inout_opt LPRASSUBENTRYA lpRasSubEntry
 , BYREF lpdwcb AS DWORD _                              ' __inout_opt LPDWORD lpdwcb
 , OPTIONAL BYVAL lpbDeviceConfig AS BYTE PTR _         ' __out_opt   LPBYTE lpbDeviceConfig // This parameter is currently unused and should set to NULL
 , OPTIONAL BYREF lpcbDeviceConfig AS DWORD _           ' __inout_opt LPDWORD lpcbDeviceConfig
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION RasGetSubEntryPropertiesW LIB "RasApi32.dll" _
    ALIAS "RasGetSubEntryPropertiesW" (lpszPhonebook AS WSTRINGZ, _
    lpszEntry AS WSTRINGZ, BYVAL dwSubEntry AS DWORD, _
    lpRasSubEntry AS RASSUBENTRYW, lpdwcb AS DWORD, lpbDeviceConfig AS BYTE, _
    pd2 AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION RasGetSubEntryPropertiesW IMPORT "rasapi32.dll" ALIAS "RasGetSubEntryPropertiesW" ( _
   BYREF lpszPhonebook AS WSTRINGZ _                    ' __in_opt    LPCWSTR lpszPhonebook
 , BYREF lpszEntry AS WSTRINGZ _                        ' __in        LPCWSTR lpszEntry
 , BYVAL dwSubEntry AS DWORD _                          ' __in        DWORD dwSubEntry
 , BYREF lpRasSubEntry AS RASSUBENTRYW  _               ' __inout_opt LPRASSUBENTRYW lpRasSubEntry
 , BYREF lpdwcb AS DWORD _                              ' __inout_opt LPDWORD lpdwcb
 , OPTIONAL BYVAL lpbDeviceConfig AS BYTE PTR _         ' __out_opt   LPBYTE lpbDeviceConfig // This parameter is currently unused and should set to NULL
 , OPTIONAL BYREF lpcbDeviceConfig AS DWORD _           ' __inout_opt LPDWORD lpcbDeviceConfig
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
   MACRO RasGetSubEntryProperties = RasGetSubEntryPropertiesW
#ELSE
   MACRO RasGetSubEntryProperties = RasGetSubEntryPropertiesA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION RasSetSubEntryPropertiesA LIB "RasApi32.dll" _
    ALIAS "RasSetSubEntryPropertiesA" (lpszPhonebook AS ASCIIZ, _
    lpszEntry AS ASCIIZ, BYVAL dwSubEntry AS DWORD, _
    lpRasSubEntry AS RASSUBENTRYA, BYVAL d1 AS DWORD, _
    lpbDeviceConfig AS BYTE, BYVAL lpcbDeviceConfig AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION RasSetSubEntryPropertiesA IMPORT "rasapi32.dll" ALIAS "RasSetSubEntryPropertiesA" ( _
   BYREF lpszPhonebook AS ASCIIZ _                      ' __in_opt LPCSTR lpszPhonebook
 , BYREF lpszEntry AS ASCIIZ _                          ' __in     LPCSTR lpszEntry
 , BYVAL dwSubEntry AS DWORD _                          ' __in     DWORD dwSubEntry
 , BYREF lpRasSubEntry AS RASSUBENTRYA _                ' __in     LPRASSUBENTRYA lpRasSubEntry
 , BYVAL dwcbRasSubEntry AS DWORD _                     ' __in     DWORD dwcbRasSubEntry
 , BYVAL lpbDeviceConfig AS BYTE PTR _                  ' __in_opt LPBYTE lpbDeviceConfig
 , BYVAL dwcbDeviceConfig AS DWORD _                    ' __in     DWORD dwcbDeviceConfig
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION RasSetSubEntryPropertiesW LIB "RasApi32.dll" _
    ALIAS "RasSetSubEntryPropertiesW" (lpszPhonebook AS WSTRINGZ, _
    lpszEntry AS WSTRINGZ, BYVAL dwSubEntry AS DWORD, _
    lpRasSubEntry AS RASSUBENTRYW, BYVAL d1 AS DWORD, _
    lpbDeviceConfig AS BYTE, BYVAL lpcbDeviceConfig AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION RasSetSubEntryPropertiesW IMPORT "rasapi32.dll" ALIAS "RasSetSubEntryPropertiesW" ( _
   BYREF lpszPhonebook AS WSTRINGZ _                    ' __in_opt LPCWSTR lpszPhonebook
 , BYREF lpszEntry AS WSTRINGZ _                        ' __in     LPCWSTR lpszEntry
 , BYVAL dwSubEntry AS DWORD _                          ' __in     DWORD dwSubEntry
 , BYREF lpRasSubEntry AS RASSUBENTRYW _                ' __in     LPRASSUBENTRYW lpRasSubEntry
 , BYVAL dwcbRasSubEntry AS DWORD _                     ' __in     DWORD dwcbRasSubEntry
 , BYVAL lpbDeviceConfig AS BYTE PTR _                  ' __in_opt LPBYTE lpbDeviceConfig
  , BYVAL dwcbDeviceConfig AS DWORD _                    ' __in     DWORD dwcbDeviceConfig
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
   MACRO RasSetSubEntryProperties = RasSetSubEntryPropertiesW
#ELSE
   MACRO RasSetSubEntryProperties = RasSetSubEntryPropertiesA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION RasGetAutodialAddressA LIB "RasApi32.dll" _
    ALIAS "RasGetAutodialAddressA" (lpszAddress AS ASCIIZ, _
    lpdwReserved AS DWORD, BYVAL lpAutoDialEntries AS RASAUTODIALENTRYA PTR, _
    lpdwcbAutoDialEntries AS DWORD, lpdwcAutoDialEntries AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION RasGetAutodialAddressA IMPORT "rasapi32.dll" ALIAS "RasGetAutodialAddressA" ( _
   BYREF lpszAddress AS ASCIIZ _                        ' __in_opt    LPCSTR lpszAddress
 , BYVAL lpdwReserved AS DWORD _                        ' __in_opt    LPDWORD lpdwReserved
 , BYREF lpAutoDialEntries AS RASAUTODIALENTRYA _       ' __inout_opt LPRASAUTODIALENTRYA lpAutoDialEntries
 , BYREF lpdwcbAutoDialEntries AS DWORD _               ' __inout     LPDWORD lpdwcbAutoDialEntries
 , BYREF lpdwcAutoDialEntries AS DWORD _                ' __out       LPDWORD lpdwcAutoDialEntries
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION RasGetAutodialAddressW LIB "RasApi32.dll" _
    ALIAS "RasGetAutodialAddressW" (lpszAddress AS WSTRINGZ, _
    lpdwReserved AS DWORD, BYVAL lpAutoDialEntries AS RASAUTODIALENTRYW PTR, _
    lpdwcbAutoDialEntries AS DWORD, lpdwcAutoDialEntries AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION RasGetAutodialAddressW IMPORT "rasapi32.dll" ALIAS "RasGetAutodialAddressW" ( _
   BYREF lpszAddress AS WSTRINGZ _                      ' __in_opt    LPCWSTR lpszAddress
 , BYVAL lpdwReserved AS DWORD _                        ' __in_opt    LPDWORD lpdwReserved
 , BYREF lpAutoDialEntries AS RASAUTODIALENTRYW _       ' __inout_opt LPRASAUTODIALENTRYW lpAutoDialEntries
 , BYREF lpdwcbAutoDialEntries AS DWORD _               ' __inout     LPDWORD lpdwcbAutoDialEntries
 , BYREF lpdwcAutoDialEntries AS DWORD _                ' __out       LPDWORD lpdwcAutoDialEntries
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
   MACRO RasGetAutodialAddress = RasGetAutodialAddressW
#ELSE
   MACRO RasGetAutodialAddress = RasGetAutodialAddressA
#ENDIF

#IF %DEF(%USEPBDECL)
#ELSE
DECLARE FUNCTION RasSetAutodialAddressA IMPORT "rasapi32.dll" ALIAS "RasSetAutodialAddressA" ( _
   BYREF lpszAddress AS ASCIIZ _                        ' __in_opt LPCSTR lpszAddress
 , BYVAL dwReserved AS DWORD _                          ' __in     DWORD dwReserved
 , BYREF lpAutoDialEntries AS RASAUTODIALENTRYA _       ' __in_opt LPRASAUTODIALENTRYA lpAutoDialEntries
 , BYVAL dwcbAutoDialEntries AS DWORD _                 ' __in     DWORD dwcbAutoDialEntries
 , BYVAL dwcAutoDialEntries AS DWORD _                  ' __in     DWORD dwcAutoDialEntries
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION RasSetAutodialAddressW LIB "RasApi32.dll" _
    ALIAS "RasSetAutodialAddressW" (lpszAddress AS WSTRINGZ, _
    BYVAL dwReserved AS DWORD, _
    BYVAL lpAutoDialEntries AS RASAUTODIALENTRYW PTR, _
    BYVAL dwcbAutoDialEntries AS DWORD, BYVAL dwcAutoDialEntries AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION RasSetAutodialAddressW IMPORT "rasapi32.dll" ALIAS "RasSetAutodialAddressW" ( _
   BYREF lpszAddress AS WSTRINGZ _                      ' __in_opt LPCWSTR lpszAddress
 , BYVAL dwReserved AS DWORD _                          ' __in     DWORD dwReserved
 , BYREF lpAutoDialEntries AS RASAUTODIALENTRYW _       ' __in_opt LPRASAUTODIALENTRYW lpAutoDialEntries
 , BYVAL dwcbAutoDialEntries AS DWORD _                 ' __in     DWORD dwcbAutoDialEntries
 , BYVAL dwcAutoDialEntries AS DWORD _                  ' __in     DWORD dwcAutoDialEntries
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
   MACRO RasSetAutodialAddress = RasSetAutodialAddressW
#ELSE
   MACRO RasSetAutodialAddress = RasSetAutodialAddressA
#ENDIF

DECLARE FUNCTION RasEnumAutodialAddressesA IMPORT "rasapi32.dll" ALIAS "RasEnumAutodialAddressesA" ( _
   BYREF lppAddresses AS ANY _                          ' __inout LPSTR* lppAddresses
 , BYREF lpdwcbAddresses AS DWORD _                     ' __inout LPDWORD lpdwcbAddresses
 , BYREF lpdwcAddresses AS DWORD _                      ' __out   LPDWORD lpdwcAddresses
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasEnumAutodialAddressesW IMPORT "rasapi32.dll" ALIAS "RasEnumAutodialAddressesW" ( _
   BYREF lppAddresses AS ANY _                          ' __inout LPWSTR* lppAddresses
 , BYREF lpdwcbAddresses AS DWORD _                     ' __inout LPDWORD lpdwcbAddresses
 , BYREF lpdwcAddresses AS DWORD _                      ' __out   LPDWORD lpdwcAddresses
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasEnumAutodialAddresses = RasEnumAutodialAddressesW
#ELSE
   MACRO RasEnumAutodialAddresses = RasEnumAutodialAddressesA
#ENDIF

DECLARE FUNCTION RasGetAutodialEnableA IMPORT "rasapi32.dll" ALIAS "RasGetAutodialEnableA" ( _
   BYVAL dwDialingLocation AS DWORD _                   ' __in  DWORD dwDialingLocation
 , BYREF lpfEnabled AS LONG _                           ' __out LPBOOL lpfEnabled
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasGetAutodialEnableW IMPORT "rasapi32.dll" ALIAS "RasGetAutodialEnableW" ( _
   BYVAL dwDialingLocation AS DWORD _                   ' __in  DWORD dwDialingLocation
 , BYREF lpfEnabled AS LONG _                           ' __out LPBOOL lpfEnabled
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasGetAutodialEnable = RasGetAutodialEnableW
#ELSE
   MACRO RasGetAutodialEnable = RasGetAutodialEnableA
#ENDIF

DECLARE FUNCTION RasSetAutodialEnableA IMPORT "rasapi32.dll" ALIAS "RasSetAutodialEnableA" ( _
   BYVAL dwDialingLocation AS DWORD _                   ' __in DWORD dwDialingLocation
 , BYVAL fEnabled AS LONG _                             ' __in BOOL fEnabled
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasSetAutodialEnableW IMPORT "rasapi32.dll" ALIAS "RasSetAutodialEnableW" ( _
   BYVAL dwDialingLocation AS DWORD _                   ' __in DWORD dwDialingLocation
 , BYVAL fEnabled AS LONG _                             ' __in BOOL fEnabled
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasSetAutodialEnable = RasSetAutodialEnableW
#ELSE
   MACRO RasSetAutodialEnable = RasSetAutodialEnableA
#ENDIF

DECLARE FUNCTION RasGetAutodialParamA IMPORT "rasapi32.dll" ALIAS "RasGetAutodialParamA" ( _
   BYVAL dwKey AS DWORD _                               ' __in    DWORD dwKey
 , BYREF lpvValue AS ANY _                              ' __out   LPVOID lpvValue
 , BYREF lpdwcbValue AS DWORD _                         ' __inout LPDWORD lpdwcbValue
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasGetAutodialParamW IMPORT "rasapi32.dll" ALIAS "RasGetAutodialParamW" ( _
   BYVAL dwKey AS DWORD _                               ' __in    DWORD dwKey
 , BYREF lpvValue AS ANY _                              ' __out   LPVOID lpvValue
 , BYREF lpdwcbValue AS DWORD _                         ' __inout LPDWORD lpdwcbValue
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasGetAutodialParam = RasGetAutodialParamW
#ELSE
   MACRO RasGetAutodialParam = RasGetAutodialParamA
#ENDIF

DECLARE FUNCTION RasSetAutodialParamA IMPORT "rasapi32.dll" ALIAS "RasSetAutodialParamA" ( _
   BYVAL dwKey AS DWORD _                               ' __in  DWORD dwKey
 , BYREF lpvValue AS ANY _                              ' __out LPVOID lpvValue
 , BYVAL dwcbValue AS DWORD _                           ' __in  DWORD dwcbValue
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasSetAutodialParamW IMPORT "rasapi32.dll" ALIAS "RasSetAutodialParamW" ( _
   BYVAL dwKey AS DWORD _                               ' __in  DWORD dwKey
 , BYREF lpvValue AS ANY _                              ' __out LPVOID lpvValue
 , BYVAL dwcbValue AS DWORD _                           ' __in  DWORD dwcbValue
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasSetAutodialParam = RasSetAutodialParamW
#ELSE
   MACRO RasSetAutodialParam = RasSetAutodialParamA
#ENDIF

#ENDIF

#IF (%WINVER >= &H500)

' // Size = 60 bytes
TYPE RAS_STATS   ' Must be 4 byte aligned
   dwSize                AS DWORD   ' DWORD
   dwBytesXmited         AS DWORD   ' DWORD
   dwBytesRcved          AS DWORD   ' DWORD
   dwFramesXmited        AS DWORD   ' DWORD
   dwFramesRcved         AS DWORD   ' DWORD
   dwCrcErr              AS DWORD   ' DWORD
   dwTimeoutErr          AS DWORD   ' DWORD
   dwAlignmentErr        AS DWORD   ' DWORD
   dwHardwareOverrunErr  AS DWORD   ' DWORD
   dwFramingErr          AS DWORD   ' DWORD
   dwBufferOverrunErr    AS DWORD   ' DWORD
   dwCompressionRatioIn  AS DWORD   ' DWORD
   dwCompressionRatioOut AS DWORD   ' DWORD
   dwBps                 AS DWORD   ' DWORD
   dwConnectDuration     AS DWORD   ' DWORD
END TYPE

'typedef DWORD (WINAPI *RasCustomHangUpFn) (
'                            HRASCONN hRasConn
'                            );
'FUNCTION RasCustomHangUp ( _
'   BYVAL hRasConn AS DWORD, _                           ' HRASCONN hRasConn
'   ) AS DWORD                                           ' DWORD

'typedef DWORD (WINAPI *RasCustomDialFn) (
'      HINSTANCE           hInstDll,
'      LPRASDIALEXTENSIONS lpRasDialExtensions,
'      LPCWSTR             lpszPhonebook,
'      LPRASDIALPARAMS     lpRasDialParams,
'      DWORD               dwNotifierType,
'      LPVOID              lpvNotifier,
'      LPHRASCONN          lphRasConn,
'      DWORD               dwFlags
'        );

'FUNCTION RasCustomDial ( _
'   BYVAL hInstDll AS DWORD, _                           ' HINSTANCE           hInstDll
'   BYREF lpRasDialExtensions AS RASDIALEXTENSIONS, _    ' LPRASDIALEXTENSIONS lpRasDialExtensions
'   BYREF lpszPhonebook AS WSTRINGZ, _                   ' LPCWSTR             lpszPhonebook
'   BYREF lpRasDialParams AS RASDIALPARAMS, _            ' LPRASDIALPARAMS     lpRasDialParams
'   BYVAL dwNotifierType AS DWORD, _                     ' DWORD               dwNotifierType
'   BYVAL lpvNotifier AS DWORD, _                        ' LPVOID              lpvNotifier
'   BYREF lphRasConn AS DWORD, _                         ' LPHRASCONN          lphRasConn
'   BYVAL dwFlags AS DWORD _                             ' DWORD               dwFlags
'   ) AS DWORD                                           ' DWORD

'typedef DWORD (WINAPI *RasCustomDeleteEntryNotifyFn) (
'        LPCWSTR             lpszPhonebook,
'        LPCWSTR             lpszEntry,
'        DWORD               dwFlags);

'FUNCTION RasCustomDeleteEntryNotify ( _
'   BYREF lpszPhonebook AS WSTRINGZ, _                   ' LPCWSTR lpszPhonebook
'   BYREF lpszEntry AS WSTRINGZ, _                       ' LPCWSTR lpszEntry
'   BYVAL dwFlagsAS DWORD _                              ' DWORD   dwFlags)
'   ) AS DWORD                                           ' DWORD

%RCD_SingleUser  = 0
%RCD_AllUsers    = &H00000001???
%RCD_Eap         = &H00000002???
%RCD_Logon       = &H00000004???

DECLARE FUNCTION RasInvokeEapUI IMPORT "rasapi32.dll" ALIAS "RasInvokeEapUI" ( _
   BYVAL hRasConn AS DWORD _                            ' __in HRASCONN hRasConn
 , BYVAL dwSubEntry AS DWORD _                          ' __in DWORD dwSubEntry
 , BYREF lpExtensions AS RASDIALEXTENSIONS _            ' __in LPRASDIALEXTENSIONS lpExtensions
 , BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasGetLinkStatistics IMPORT "rasapi32.dll" ALIAS "RasGetLinkStatistics" ( _
   BYVAL hRasConn AS DWORD _                            ' __in    HRASCONN hRasConn
 , BYVAL dwSubEntry AS DWORD _                          ' __in    DWORD dwSubEntry
 , BYREF lpStatistics AS RAS_STATS _                    ' __inout RAS_STATS *lpStatistics
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasGetConnectionStatistics IMPORT "rasapi32.dll" ALIAS "RasGetConnectionStatistics" ( _
   BYVAL hRasConn AS DWORD _                            ' __in    HRASCONN hRasConn
 , BYREF lpStatistics AS RAS_STATS _                    ' __inout RAS_STATS *lpStatistics
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasClearLinkStatistics IMPORT "rasapi32.dll" ALIAS "RasClearLinkStatistics" ( _
   BYVAL hRasConn AS DWORD _                            ' __in HRASCONN hRasConn
 , BYVAL dwSubEntry AS DWORD _                          ' __in DWORD dwSubEntry
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasClearConnectionStatistics IMPORT "rasapi32.dll" ALIAS "RasClearConnectionStatistics" ( _
   BYVAL hRasConn AS DWORD _                            ' __in HRASCONN hRasConn
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasGetEapUserDataA IMPORT "rasapi32.dll" ALIAS "RasGetEapUserDataA" ( _
   BYVAL hToken AS DWORD _                              ' __in_opt  HANDLE hToken
 , BYREF pszPhonebook AS ASCIIZ _                       ' __in_opt  LPCSTR pszPhonebook
 , BYREF pszEntry AS ASCIIZ _                           ' __in      LPCSTR pszEntry
 , BYVAL pbEapData AS BYTE PTR _                        ' __out_opt BYTE   *pbEapData
 , BYREF pdwSizeofEapData AS DWORD _                    ' __inout   DWORD  *pdwSizeofEapData
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasGetEapUserDataW IMPORT "rasapi32.dll" ALIAS "RasGetEapUserDataW" ( _
   BYVAL hToken AS DWORD _                              ' __in_opt  HANDLE  hToken
 , BYREF pszPhonebook AS WSTRINGZ _                     ' __in_opt  LPCWSTR pszPhonebook
 , BYREF pszEntry AS WSTRINGZ _                         ' __in      LPCWSTR pszEntry
 , BYVAL pbEapData AS BYTE PTR _                        ' __out_opt BYTE    *pbEapData
 , BYREF pdwSizeofEapData AS DWORD _                    ' __inout   DWORD   *pdwSizeofEapData
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasGetEapUserData = RasGetEapUserDataW
#ELSE
   MACRO RasGetEapUserData = RasGetEapUserDataA
#ENDIF

DECLARE FUNCTION RasSetEapUserDataA IMPORT "rasapi32.dll" ALIAS "RasSetEapUserDataA" ( _
   BYVAL hToken AS DWORD _                              ' __in_opt  HANDLE hToken
 , BYREF pszPhonebook AS ASCIIZ _                       ' __in_opt  LPCSTR pszPhonebook
 , BYREF pszEntry AS ASCIIZ _                           ' __in      LPCSTR pszEntry
 , BYVAL pbEapData AS BYTE PTR _                        ' __in      BYTE   *pbEapData
 , BYVAL dwSizeofEapData AS DWORD _                     ' __in      DWORD  dwSizeofEapData
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasSetEapUserDataW IMPORT "rasapi32.dll" ALIAS "RasSetEapUserDataW" ( _
   BYVAL hToken AS DWORD _                              ' __in_opt  HANDLE hToken
 , BYREF pszPhonebook AS WSTRINGZ _                     ' __in_opt  LPCWSTR pszPhonebook
 , BYREF pszEntry AS WSTRINGZ _                         ' __in      LPCWSTR pszEntry
 , BYVAL pbEapData AS BYTE PTR _                        ' __in      BYTE   *pbEapData
 , BYVAL dwSizeofEapData AS DWORD _                     ' __in      DWORD  dwSizeofEapData
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasSetEapUserData = RasSetEapUserDataW
#ELSE
   MACRO RasSetEapUserData = RasSetEapUserDataA
#ENDIF

DECLARE FUNCTION RasGetCustomAuthDataA IMPORT "rasapi32.dll" ALIAS "RasGetCustomAuthDataA" ( _
   BYREF pszPhonebook AS ASCIIZ _                       ' __in_opt  LPCSTR pszPhonebook
 , BYREF pszEntry AS ASCIIZ _                           ' __in      LPCSTR pszEntry
 , BYVAL pbCustomAuthData AS BYTE PTR _                 ' __out_opt BYTE   *pbCustomAuthData
 , BYREF pdwSizeofCustomAuthData AS DWORD _             ' __inout   DWORD  *pdwSizeofCustomAuthData
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasGetCustomAuthDataW IMPORT "rasapi32.dll" ALIAS "RasGetCustomAuthDataW" ( _
   BYREF pszPhonebook AS WSTRINGZ _                     ' __in_opt  LPCWSTR pszPhonebook
 , BYREF pszEntry AS WSTRINGZ _                         ' __in      LPCWSTR pszEntry
 , BYVAL pbCustomAuthData AS BYTE PTR _                 ' __out_opt BYTE    *pbCustomAuthData
 , BYREF pdwSizeofCustomAuthData AS DWORD _             ' __inout   DWORD   *pdwSizeofCustomAuthData
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasGetCustomAuthData = RasGetCustomAuthDataW
#ELSE
   MACRO RasGetCustomAuthData = RasGetCustomAuthDataA
#ENDIF

DECLARE FUNCTION RasSetCustomAuthDataA IMPORT "rasapi32.dll" ALIAS "RasSetCustomAuthDataA" ( _
   BYREF pszPhonebook AS ASCIIZ _                       ' __in_opt LPCSTR pszPhonebook
 , BYREF pszEntry AS ASCIIZ _                           ' __in     LPCSTR pszEntry
 , BYVAL pbCustomAuthData AS BYTE PTR _                 ' __in     BYTE   *pbCustomAuthData
 , BYVAL dwSizeofCustomAuthData AS DWORD _              ' __in     DWORD  dwSizeofCustomAuthData
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasSetCustomAuthDataW IMPORT "rasapi32.dll" ALIAS "RasSetCustomAuthDataW" ( _
   BYREF pszPhonebook AS WSTRINGZ _                     ' __in_opt LPCWSTR pszPhonebook
 , BYREF pszEntry AS WSTRINGZ _                         ' __in     LPCWSTR pszEntry
 , BYVAL pbCustomAuthData AS BYTE PTR _                 ' __in     BYTE    *pbCustomAuthData
 , BYVAL dwSizeofCustomAuthData AS DWORD _              ' __in     DWORD   dwSizeofCustomAuthData
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasSetCustomAuthData = RasSetCustomAuthDataW
#ELSE
   MACRO RasSetCustomAuthData = RasSetCustomAuthDataA
#ENDIF

DECLARE FUNCTION RasGetEapUserIdentityW IMPORT "rasapi32.dll" ALIAS "RasGetEapUserIdentityW" ( _
   BYREF pszPhonebook AS WSTRINGZ _                     ' __in_opt LPCWSTR                pszPhonebook
 , BYREF pszEntry AS WSTRINGZ _                         ' __in     LPCWSTR                pszEntry
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD                  dwFlags
 , BYVAL hwnd AS DWORD _                                ' __in     HWND                   hwnd
 , BYREF ppRasEapUserIdentity AS ANY _                  ' __out    LPRASEAPUSERIDENTITYW* ppRasEapUserIdentity
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasGetEapUserIdentityA IMPORT "rasapi32.dll" ALIAS "RasGetEapUserIdentityA" ( _
   BYREF pszPhonebook AS ASCIIZ _                       ' __in_opt LPCSTR                 pszPhonebook
 , BYREF pszEntry AS ASCIIZ _                           ' __in     LPCSTR                 pszEntry
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD                  dwFlags
 , BYVAL hwnd AS DWORD _                                ' __in     HWND                   hwnd
 , BYREF ppRasEapUserIdentity AS ANY _                  ' __out    LPRASEAPUSERIDENTITYA* ppRasEapUserIdentity
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasGetEapUserIdentity = RasGetEapUserIdentityW
#ELSE
   MACRO RasGetEapUserIdentity = RasGetEapUserIdentityA
#ENDIF

DECLARE SUB RasFreeEapUserIdentityW IMPORT "rasapi32.dll" ALIAS "RasFreeEapUserIdentityW" ( _
   BYREF pRasEapUserIdentity AS RASEAPUSERIDENTITYW _   ' __in LPRASEAPUSERIDENTITYW    pRasEapUserIdentity
 )                                                      ' VOID

DECLARE SUB RasFreeEapUserIdentityA IMPORT "rasapi32.dll" ALIAS "RasFreeEapUserIdentityA" ( _
   BYREF pRasEapUserIdentity AS RASEAPUSERIDENTITYA _   ' __in LPRASEAPUSERIDENTITYA pRasEapUserIdentity
 )                                                      ' VOID

#IF %DEF(%UNICODE)
   MACRO RasFreeEapUserIdentity = RasFreeEapUserIdentityW
#ELSE
   MACRO RasFreeEapUserIdentity = RasFreeEapUserIdentityA
#ENDIF

#ENDIF

#IF (%WINVER >= &H501)

DECLARE FUNCTION RasDeleteSubEntryA IMPORT "rasapi32.dll" ALIAS "RasDeleteSubEntryA" ( _
   BYREF pszPhonebook AS ASCIIZ _                       ' __in_opt LPCSTR pszPhonebook
 , BYREF pszEntry AS ASCIIZ _                           ' __in     LPCSTR pszEntry
 , BYVAL dwSubentryId AS DWORD _                        ' __in     DWORD  dwSubentryId
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RasDeleteSubEntryW IMPORT "rasapi32.dll" ALIAS "RasDeleteSubEntryW" ( _
   BYREF pszPhonebook AS WSTRINGZ _                     ' __in_opt LPCWSTR pszPhonebook
 , BYREF pszEntry AS WSTRINGZ _                         ' __in     LPCWSTR pszEntry
 , BYVAL dwSubentryId AS DWORD _                        ' __in     DWORD   dwSubentryId
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO RasDeleteSubEntry = RasDeleteSubEntryW
#ELSE
   MACRO RasDeleteSubEntry = RasDeleteSubEntryA
#ENDIF

#ENDIF

' // To use Quarantine APIs, applications should explicitly
' // define USES_RAS_QUARANTINE_APIS.

#IF %DEF(%USES_RAS_QUARANTINE_APIS)
DECLARE FUNCTION RasGetNapStatus IMPORT "rasapi32.dll" ALIAS "RasGetNapStatus" ( _
   BYVAL hRasConn AS DWORD _                            ' __in     HRASCONN hRasConn
 , BYREF pNapState AS RASNAPSTATE _                     ' __inout  LPRASNAPSTATE pNapState
 ) AS DWORD                                             ' DWORD
#ENDIF   ' %USES_RAS_QUARANTINE_APIS

#IF (%WINVER >= &H601)

'/* Update an active RAS connection.Localendpoint if specified is used for performing
'/  mobike update.If not specified then dwIfIndex value is used for performing mobike.
'/  (See RasUpdateConnection)
'*/

' // Size = 56 bytes
TYPE RASUPDATECONN   ' Must be 4 byte aligned
   version        AS LONG    ' RASAPIVERSION
   dwSize         AS DWORD   ' DWORD
   dwFlags        AS DWORD   ' DWORD
   dwIfIndex      AS DWORD   ' DWORD
   localEndPoint  AS RASTUNNELENDPOINT
   remoteEndPoint AS RASTUNNELENDPOINT
END TYPE

DECLARE FUNCTION RasUpdateConnection IMPORT "rasapi32.dll" ALIAS "RasUpdateConnection" ( _
   BYVAL hrasconn AS DWORD _                            ' __in HRASCONN        hrasconn
 , BYREF lprasupdateconn AS RASUPDATECONN _             ' __in LPRASUPDATECONN lprasupdateconn
 ) AS DWORD                                             ' DWORD

'/* Ras Projection information for PPP or IKEv2
'*/
DECLARE FUNCTION RasGetProjectionInfoEx IMPORT "rasapi32.dll" ALIAS "RasGetProjectionInfoEx" ( _
   BYVAL hrasconn AS DWORD _                            ' __in        HRASCONN             hrasconn
 , BYREF pRasProjection AS RAS_PROJECTION_INFO _        ' __inout_opt PRAS_PROJECTION_INFO pRasProjection
 , BYREF lpdwSize AS DWORD _                            ' __inout     LPDWORD              lpdwSize
 ) AS DWORD                                             ' DWORD

#ENDIF
