' ########################################################################################
' Microsoft Windows
' File: IcmpAPI.inc
' Contents: Declarations for the Win32 ICMP Echo request API.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ICMPAPI_INC = 1

#INCLUDE ONCE "windows.inc"

'//
'// Exported Routines.
'//

'//++
'//
'// Routine Name:
'//
'//     IcmpCreateFile
'//
'// Routine Description:
'//
'//     Opens a handle on which ICMP Echo Requests can be issued.
'//
'// Arguments:
'//
'//     None.
'//
'// Return Value:
'//
'//     An open file handle or INVALID_HANDLE_VALUE. Extended error information
'//     is available by calling GetLastError().
'//
'//--

DECLARE FUNCTION IcmpCreateFile IMPORT "Iphlpapi.dll" ALIAS "IcmpCreateFile" ( _
 ) AS DWORD                                             ' HANDLE

'#if (NTDDI_VERSION >= NTDDI_WINXP)
'//++
'//
'// Routine Name:
'//
'//     Icmp6CreateFile
'//
'// Routine Description:
'//
'//     Opens a handle on which ICMPv6 Echo Requests can be issued.
'//
'// Arguments:
'//
'//     None.
'//
'// Return Value:
'//
'//     An open file handle or INVALID_HANDLE_VALUE. Extended error information
'//     is available by calling GetLastError().
'//
'//--

DECLARE FUNCTION Icmp6CreateFile IMPORT "Iphlpapi.dll" ALIAS "Icmp6CreateFile" ( _
 ) AS DWORD                                             ' HANDLE

'#endif

'//++
'//
'// Routine Name:
'//
'//     IcmpCloseHandle
'//
'// Routine Description:
'//
'//     Closes a handle opened by ICMPOpenFile.
'//
'// Arguments:
'//
'//     IcmpHandle  - The handle to close.
'//
'// Return Value:
'//
'//     TRUE if the handle was closed successfully, otherwise FALSE. Extended
'//     error information is available by calling GetLastError().
'//
'//--

DECLARE FUNCTION IcmpCloseHandle IMPORT "Iphlpapi.dll" ALIAS "IcmpCloseHandle" ( _
   BYVAL IcmpHandle AS DWORD _                          ' __in HANDLE IcmpHandle
 ) AS LONG                                              ' BOOL


'//++
'//
'// Routine Name:
'//
'//     IcmpSendEcho
'//
'// Routine Description:
'//
'//     Sends an ICMP Echo request and returns any replies. The
'//     call returns when the timeout has expired or the reply buffer
'//     is filled.
'//
'// Arguments:
'//
'//     IcmpHandle           - An open handle returned by ICMPCreateFile.
'//
'//     DestinationAddress   - The destination of the echo request.
'//
'//     RequestData          - A buffer containing the data to send in the
'//                            request.
'//
'//     RequestSize          - The number of bytes in the request data buffer.
'//
'//     RequestOptions       - Pointer to the IP header options for the request.
'//                            May be NULL.
'//
'//     ReplyBuffer          - A buffer to hold any replies to the request.
'//                            On return, the buffer will contain an array of
'//                            ICMP_ECHO_REPLY structures followed by the
'//                            options and data for the replies. The buffer
'//                            should be large enough to hold at least one
'//                            ICMP_ECHO_REPLY structure plus
'//                            MAX(RequestSize, 8) bytes of data since an ICMP
'//                            error message contains 8 bytes of data.
'//
'//     ReplySize            - The size in bytes of the reply buffer.
'//
'//     Timeout              - The time in milliseconds to wait for replies.
'//
'// Return Value:
'//
'//     Returns the number of ICMP_ECHO_REPLY structures stored in ReplyBuffer.
'//     The status of each reply is contained in the structure. If the return
'//     value is zero, extended error information is available via
'//     GetLastError().
'//
'//--

DECLARE FUNCTION IcmpSendEcho IMPORT "Iphlpapi.dll" ALIAS "IcmpSendEcho" ( _
   BYVAL IcmpHandle AS DWORD _                          ' __in HANDLE IcmpHandle
 , BYVAL DestinationAddress AS DWORD _                  ' __in IPAddr DestinationAddress
 , BYREF RequestData AS ANY _                           ' __in LPVOID RequestData
 , BYVAL RequestSize AS WORD _                          ' __in WORD RequestSize
 , BYREF RequestOptions AS ANY _                        ' __in PIP_OPTION_INFORMATION RequestOptions
 , BYREF ReplyBuffer AS ANY _                           ' __in_out LPVOID ReplyBuffer
 , BYVAL ReplySize AS DWORD _                           ' __in DWORD ReplySize
 , BYVAL Timeout AS DWORD _                             ' __in DWORD Timeout
 ) AS DWORD                                             ' DWORD

'//++
'//
'// Routine Description:
'//
'//    Sends an ICMP Echo request and the call returns either immediately
'//    (if Event or ApcRoutine is NonNULL) or returns after the specified
'//    timeout.   The ReplyBuffer contains the ICMP responses, if any.
'//
'// Arguments:
'//
'//    IcmpHandle           - An open handle returned by ICMPCreateFile.
'//
'//    Event                - This is the event to be signalled whenever an IcmpResponse
'//                           comes in.
'//
'//    ApcRoutine           - This routine would be called when the calling thread
'//                           is in an alertable thread and an ICMP reply comes in.
'//
'//    ApcContext           - This optional parameter is given to the ApcRoutine when
'//                           this call succeeds.
'//
'//    DestinationAddress   - The destination of the echo request.
'//
'//    RequestData          - A buffer containing the data to send in the
'//                           request.
'//
'//    RequestSize          - The number of bytes in the request data buffer.
'//
'//    RequestOptions       - Pointer to the IP header options for the request.
'//                           May be NULL.
'//
'//    ReplyBuffer          - A buffer to hold any replies to the request.
'//                           On return, the buffer will contain an array of
'//                           ICMP_ECHO_REPLY structures followed by options
'//                           and data. The buffer must be large enough to
'//                           hold at least one ICMP_ECHO_REPLY structure.
'//                           It should be large enough to also hold
'//                           8 more bytes of data - this is the size of
'//                           an ICMP error message.
'//
'//    ReplySize            - The size in bytes of the reply buffer.
'//
'//    Timeout              - The time in milliseconds to wait for replies.
'//                           This is NOT used if ApcRoutine is not NULL or if Event
'//                           is not NULL.
'//
'// Return Value:
'//
'//    Returns the number of replies received and stored in ReplyBuffer. If
'//    the return value is zero, extended error information is available
'//    via GetLastError().
'//
'// Remarks:
'//
'//    On NT platforms,
'//    If used Asynchronously (either ApcRoutine or Event is specified), then
'//    ReplyBuffer and ReplySize are still needed.  This is where the response
'//    comes in.
'//    ICMP Response data is copied to the ReplyBuffer provided, and the caller of
'//    this function has to parse it asynchronously.  The function IcmpParseReply
'//    is provided for this purpose.
'//
'//    On non-NT platforms,
'//    Event, ApcRoutine and ApcContext are IGNORED.
'//
'//--

DECLARE FUNCTION IcmpSendEcho2 IMPORT "Iphlpapi.dll" ALIAS "IcmpSendEcho2" ( _
   BYVAL IcmpHandle AS DWORD _                          ' __in  HANDLE IcmpHandle
 , BYVAL Event AS DWORD _                               ' __in  HANDLE Event
 , BYVAL ApcRoutine AS DWORD _                          ' __in  FARPROC ApcRoutine
 , BYREF ApcContext AS ANY _                            ' __in  PVOID ApcContext
 , BYVAL DestinationAddress AS DWORD _                  ' __in  IPAddr DestinationAddress
 , BYREF RequestData AS ANY _                           ' __in  LPVOID RequestData
 , BYVAL RequestSize AS WORD _                          ' __in  WORD RequestSize
 , BYREF RequestOptions AS ANY _                        ' __in  PIP_OPTION_INFORMATION RequestOptions
 , BYREF ReplyBuffer AS ANY _                           ' __out LPVOID ReplyBuffer
 , BYVAL ReplySize AS DWORD _                           ' __in  DWORD ReplySize
 , BYVAL Timeout AS DWORD _                             ' __in  DWORD Timeout
 ) AS DWORD                                             ' DWORD

'#if (NTDDI_VERSION >= NTDDI_VISTASP1)
DECLARE FUNCTION IcmpSendEcho2Ex IMPORT "Iphlpapi.dll" ALIAS "IcmpSendEcho2Ex" ( _
   BYVAL IcmpHandle AS DWORD _                          ' __in  HANDLE IcmpHandle
 , BYVAL Event AS DWORD _                               ' __in  HANDLE Event
 , BYVAL ApcRoutine AS DWORD _                          ' __in  FARPROC ApcRoutine
 , BYREF ApcContext AS ANY _                            ' __in  PVOID ApcContext
 , BYVAL SourceAddress AS DWORD _                       ' __in  IPAddr SourceAddress
 , BYVAL DestinationAddress AS DWORD _                  ' __in  IPAddr DestinationAddress
 , BYREF RequestData AS ANY _                           ' __in  LPVOID RequestData
 , BYVAL RequestSize AS WORD _                          ' __in  WORD RequestSize
 , BYREF RequestOptions AS ANY _                        ' __in  PIP_OPTION_INFORMATION RequestOptions
 , BYREF ReplyBuffer AS ANY _                           ' __out LPVOID ReplyBuffer
 , BYVAL ReplySize AS DWORD _                           ' __in  DWORD ReplySize
 , BYVAL Timeout AS DWORD _                             ' __in  DWORD Timeout
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_WINXP)
DECLARE FUNCTION Icmp6SendEcho2 IMPORT "Iphlpapi.dll" ALIAS "Icmp6SendEcho2" ( _
   BYVAL IcmpHandle AS DWORD _                          ' __in  HANDLE IcmpHandle
 , BYVAL Event AS DWORD _                               ' __in  HANDLE Event
 , BYVAL ApcRoutine AS DWORD _                          ' __in  FARPROC ApcRoutine
 , BYREF ApcContext AS ANY _                            ' __in  PVOID ApcContext
 , BYREF SourceAddress AS ANY _                         ' __in  struct sockaddr_in6 *SourceAddress
 , BYREF DestinationAddress AS ANY _                    ' __in  struct sockaddr_in6 *DestinationAddress
 , BYREF RequestData AS ANY _                           ' __in  LPVOID RequestData
 , BYVAL RequestSize AS WORD _                          ' __in  WORD RequestSize
 , BYREF RequestOptions AS ANY _                        ' __in  PIP_OPTION_INFORMATION RequestOptions
 , BYREF ReplyBuffer AS ANY _                           ' __out LPVOID ReplyBuffer
 , BYVAL ReplySize AS DWORD _                           ' __in  DWORD ReplySize
 , BYVAL Timeout AS DWORD _                             ' __in  DWORD Timeout
 ) AS DWORD                                             ' DWORD
'#endif

'//++
'//
'// Routine Description:
'//
'//    Parses the reply buffer provided and returns the number of ICMP responses found.
'//
'// Arguments:
'//
'//    ReplyBuffer            - This must be the same buffer that was passed to IcmpSendEcho2
'//                             This is rewritten to hold an array of ICMP_ECHO_REPLY structures.
'//                             (i.e. the type is PICMP_ECHO_REPLY).
'//
'//    ReplySize              - This must be the size of the above buffer.
'//
'// Return Value:
'//    Returns the number of ICMP responses found.  If there is an errors, return value is
'//    zero.  The error can be determined by a call to GetLastError.
'//
'// Remarks:
'//    This function SHOULD NOT BE USED on a reply buffer that was passed to SendIcmpEcho.
'//    SendIcmpEcho actually parses the buffer before returning back to the user.  This function
'//    is meant to be used only with SendIcmpEcho2.
'//--

DECLARE FUNCTION IcmpParseReplies IMPORT "Iphlpapi.dll" ALIAS "IcmpParseReplies" ( _
   BYREF ReplyBuffer AS ANY  _                          ' __in  LPVOID ReplyBuffer
 , BYVAL ReplySize AS DWORD _                           ' __in  DWORD ReplySize
 ) AS DWORD                                             ' DWORD

'#if (NTDDI_VERSION >= NTDDI_WINXP)
DECLARE FUNCTION Icmp6ParseReplies IMPORT "Iphlpapi.dll" ALIAS "Icmp6ParseReplies" ( _
   BYREF ReplyBuffer AS ANY _                           ' __in  LPVOID ReplyBuffer
 , BYVAL ReplySize AS DWORD _                           ' __in  DWORD ReplySize
 ) AS DWORD                                             ' DWORD
'#endif
