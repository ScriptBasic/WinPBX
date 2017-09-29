' ########################################################################################
' Microsoft Windows
' File: WinSock2.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

'/* Winsock2.h -- definitions to be used with the WinSock 2 DLL and
' *               WinSock 2 applications.
' *
' * This header file corresponds to version 2.2.x of the WinSock API
' * specification.
' *
' * This file includes parts which are Copyright (c) 1982-1986 Regents
' * of the University of California.  All rights reserved.  The
' * Berkeley Software License Agreement specifies the terms and
' * conditions for redistribution.
' */

#INCLUDE THIS ONCE
%WINSOCK2_INC = 1

#IF NOT %DEF(%WINSOCK2API)
    %WINSOCK2API = 1
    %WINSOCKAPI = 1    ' Prevent inclusion of winsock.inc

'#ifndef _WINSOCK2API_
'#define _WINSOCK2API_
'#define _WINSOCKAPI_   /* Prevent inclusion of winsock.h in windows.h */

'/*
' * Ensure structures are packed consistently.
' * Not necessary for WIN32, it is already packed >=4 and there are
' * no structures in this header that have alignment requirement
' * higher than 4.
' * For WIN64 we do not have compatibility requirement because it is
' * not possible to mix 32/16 bit code with 64 bit code in the same
' * process.
' */

'#if !defined(WIN32) && !defined(_WIN64)
'#include <pshpack4.h>
'/* WIN32 can be defined between here and the required poppack
'   so define this special macro to ensure poppack */
'#define _NEED_POPPACK
'#endif

'/*
' * Default: include function prototypes, don't include function typedefs.
' */

#IF NOT %DEF(%INCL_WINSOCK_API_PROTOTYPES)
%INCL_WINSOCK_API_PROTOTYPES = 1
#ENDIF

#IF NOT %DEF(%INCL_WINSOCK_API_TYPEDEFS)
%INCL_WINSOCK_API_TYPEDEFS = 0
#ENDIF

'/*
' * Pull in WINDOWS.H if necessary
' */
#IF NOT %DEF(%WINDOWS_INC)
    #INCLUDE ONCE "windows.inc"
#ENDIF

'/*
' * Define the current Winsock version. To build an earlier Winsock version
' * application redefine this value prior to including Winsock2.h.
' */

'#if !defined(MAKEWORD)
'#define MAKEWORD(low,high) \
'        ((WORD)(((BYTE)(low)) | ((WORD)((BYTE)(high))) << 8))
'#endif

'#ifndef WINSOCK_VERSION
'#define WINSOCK_VERSION MAKEWORD(2,2)
'#endif

#IF NOT %DEF(%WINSOCK_VERSION)
%WINSOCK_VERSION = &H0202??
#ENDIF

'/*
' * Basic system type definitions, taken from the BSD file sys/types.h.
' */
'typedef unsigned char   u_char;
'typedef unsigned short  u_short;
'typedef unsigned int    u_int;
'typedef unsigned long   u_long;
'typedef unsigned __int64 u_int64;

#INCLUDE ONCE "ws2def.inc"

'/*
' * The new type to be used in all
' * instances which refer to sockets.
' */
'typedef UINT_PTR        SOCKET;

'/*
' * Select uses arrays of SOCKETs.  These macros manipulate such
' * arrays.  FD_SETSIZE may be defined by the user before including
' * this file, but the default here should be >= 64.
' *
' * CAVEAT IMPLEMENTOR and USER: THESE MACROS AND TYPES MUST BE
' * INCLUDED IN WINSOCK2.H EXACTLY AS SHOWN HERE.
' */
'#ifndef FD_SETSIZE
'#define FD_SETSIZE      64
'#endif /* FD_SETSIZE */

%FD_SETSIZE = 64

#IF %DEF(%USEPBDECL)
' // For compatibility with the PB declares
TYPE fd_set DWORD
   fd_count AS DWORD                        ' u_int // /* how many are SET? */
   fd_array(%FD_SETSIZE - 1) AS DWORD PTR   ' SOCKET[FD_SETSIZE] // /* an array of SOCKETs */
END TYPE
#ELSE
' // Size = 260 bytes
TYPE fd_setstruc DWORD
   fd_count AS DWORD                        ' u_int // /* how many are SET? */
   fd_array(%FD_SETSIZE - 1) AS DWORD PTR   ' SOCKET[FD_SETSIZE] // /* an array of SOCKETs */
END TYPE
MACRO FD_SET_STRUCT = fd_setstruc
#ENDIF

'extern int PASCAL FAR __WSAFDIsSet(SOCKET, fd_set FAR *);

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WSAFDIsSet LIB "Ws2_32.dll" ALIAS "__WSAFDIsSet" ( _
    BYVAL fd  AS DWORD, _  ' SOCKET
    BYVAL fds AS fd_set PTR _
    ) AS LONG
#ELSE
DECLARE FUNCTION WSAFDIsSet IMPORT "ws2_32.dll" ALIAS "__WSAFDIsSet" ( _
   BYVAL s AS DWORD _                                   ' SOCKET
 , BYREF pfdset AS fd_setstruc _                        ' fd_set FAR *
 ) AS LONG                                              ' int
#ENDIF

'#define FD_CLR(fd, set) do { \
'    u_int __i; \
'    for (__i = 0; __i < ((fd_set FAR *)(set))->fd_count ; __i++) { \
'        if (((fd_set FAR *)(set))->fd_array[__i] == fd) { \
'            while (__i < ((fd_set FAR *)(set))->fd_count-1) { \
'                ((fd_set FAR *)(set))->fd_array[__i] = \
'                    ((fd_set FAR *)(set))->fd_array[__i+1]; \
'                __i++; \
'            } \
'            ((fd_set FAR *)(set))->fd_count--; \
'            break; \
'        } \
'    } \
'} while(0)

'#define FD_SET(fd, set) do { \
'    u_int __i; \
'    for (__i = 0; __i < ((fd_set FAR *)(set))->fd_count; __i++) { \
'        if (((fd_set FAR *)(set))->fd_array[__i] == (fd)) { \
'            break; \
'        } \
'    } \
'    if (__i == ((fd_set FAR *)(set))->fd_count) { \
'        if (((fd_set FAR *)(set))->fd_count < FD_SETSIZE) { \
'            ((fd_set FAR *)(set))->fd_array[__i] = (fd); \
'            ((fd_set FAR *)(set))->fd_count++; \
'        } \
'    } \
'} while(0)

'#define FD_ZERO(set) (((fd_set FAR *)(set))->fd_count=0)

'#define FD_ISSET(fd, set) __WSAFDIsSet((SOCKET)(fd), (fd_set FAR *)(set))

#IF %DEF(%USEPBDECL)
SUB FD_SET_sub (BYVAL fd AS DWORD, BYVAL fdset AS fd_set PTR)
    LOCAL i AS DWORD
    FOR i = 0 TO @fdset.fd_count - 1
        IF @fdset.fd_array(i) = fd THEN
            EXIT FOR
        END IF
    NEXT
    IF i = @fdset.fd_count THEN
        IF @fdset.fd_count < %FD_SETSIZE THEN
            @fdset.fd_array(i) = fd
            INCR @fdset.fd_count
        END IF
    END IF
END SUB
#ELSE
SUB FD_SET (BYVAL s AS DWORD, BYREF fds AS fd_setstruc)
   IF fds.fd_count < %FD_SETSIZE THEN
      fds.fd_array(fds.fd_count) = s
      INCR fds.fd_count
   END IF
END SUB
#ENDIF

#IF %DEF(%USEPBDECL)
SUB FD_ZERO (BYVAL fdset AS fd_set PTR)
    @fdset.fd_count = 0
END SUB
#ELSE
SUB FD_ZERO (BYREF fd AS fd_setstruc)
   fd.fd_count = 0
END SUB
#ENDIF

#IF %DEF(%USEPBDECL)
MACRO FD_ISSET = WSAFDIsSet
#ELSE
FUNCTION FD_ISSET (BYVAL fd AS DWORD, BYREF fds AS fd_setstruc) AS LONG
   FUNCTION = WSAFDIsSet(fd, fds)
END FUNCTION
#ENDIF

'/*
' * Structure used in select() call, taken from the BSD file sys/time.h.
' */
' // Size = 8 bytes
TYPE timeval DWORD
   tv_sec  AS LONG    ' long /* seconds */
   tv_usec AS LONG    ' long /* and microseconds */
END TYPE

'/*
' * Operations on timevals.
' *
' * NB: timercmp does not work for >= or <=.
' */
'#define timerisset(tvp)         ((tvp)->tv_sec || (tvp)->tv_usec)
'#define timercmp(tvp, uvp, cmp) \
'        ((tvp)->tv_sec cmp (uvp)->tv_sec || \
'         (tvp)->tv_sec == (uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
'#define timerclear(tvp)         (tvp)->tv_sec = (tvp)->tv_usec = 0

#IF %DEF(%USEPBDECL)
MACRO timerisset(tvp)=(@tvp.tv_sec OR @tvp.tv_usec)
#ELSE
MACRO timerisset (tvp) = (tvp.tv_sec OR tvp.tv_usec)
#ENDIF

#IF %DEF(%USEPBDECL)
MACRO timerclear(tvp)
    @tvp.tv_usec = 0
    @tvp.tv_sec  = 0
END MACRO
#ELSE
MACRO timerclear (tvp)
   tvp.tv_sec = 0
   tvp.tv_usec = 0
END MACRO
#ENDIF

%FIONREAD = &H4004667F???  ' _IOR('f', 127, u_long) /* get # bytes to read */
%FIONBIO  = &H8004667E???  ' _IOW('f', 126, u_long) /* set/clear non-blocking i/o */
%FIONSYNC = &H8004667D???  ' _IOW('f', 125, u_long) /* set/clear async i/o */

'/* Socket I/O Controls */
%SIOCSHIWAT = &H80047300???  ' _IOW('s',  0, u_long)  /* set high watermark */
%SIOCGHIWAT = &H80047301???  ' _IOR('s',  1, u_long)  /* get high watermark */
%SIOCSLOWAT = &H80047302???  ' _IOW('s',  2, u_long)  /* set low watermark */
%SIOCGLOWAT = &H80047303???  ' _IOR('s',  3, u_long)  /* get low watermark */
%SIOCATMARK = &H80047307???  ' _IOR('s',  7, u_long)  /* at oob mark? */

'/*
' * Structures returned by network data base library, taken from the
' * BSD file netdb.h.  All addresses are supplied in host order, and
' * returned in network order (suitable for use in system calls).
' */

'struct  hostent {
'        char    FAR * h_name;           /* official name of host */
'        char    FAR * FAR * h_aliases;  /* alias list */
'        short   h_addrtype;             /* host address type */
'        short   h_length;               /* length of address */
'        char    FAR * FAR * h_addr_list; /* list of addresses */
'#define h_addr  h_addr_list[0]          /* address, for backward compat */
'};

' // Size = 16 bytes
TYPE hostent DWORD FILL
   h_name      AS ASCIIZ PTR   ' char FAR * /* official name of host */
   h_aliases   AS DWORD        ' char FAR* FAR* /* alias list */
   h_addrtype  AS INTEGER      ' short /* host address type */
   h_length    AS INTEGER      ' short /* length of address */
   h_addr_list AS DWORD        ' char FAR* FAR* /* list of addresses */
END TYPE

'/*
' * It is assumed here that a network number
' * fits in 32 bits.
' */
' // Size = 16 bytes
TYPE netent DWORD
   n_name     AS ASCIIZ PTR  ' char FAR * /* official name of net */
   n_aliases  AS DWORD       ' char FAR * FAR * /* alias list */
   n_addrtype AS INTEGER     ' short /* net address type */
   n_net      AS DWORD       ' u_long /* network # */
END TYPE

' // Size = 16 bytes
TYPE servent DWORD
   s_name    AS ASCIIZ PTR   ' char FAR* /* official service name */
   s_aliases AS DWORD        ' char FAR * FAR * /* alias list */
'#ifdef _WIN64
'   char  FAR * s_proto;          /* protocol to use */
'   short s_port;                 /* port # */
'#else
   s_port    AS INTEGER      ' short /* port # */
   s_proto   AS ASCIIZ PTR   ' char FAR * /* protocol to use */
'#endif
END TYPE

' // Size = 12 bytes
TYPE protoent DWORD
   p_name    AS ASCIIZ PTR   ' char FAR * /* official protocol name */
   p_aliases AS DWORD        ' char FAR * FAR * /* alias list */
   p_proto   AS INTEGER      ' short /* protocol # */
END TYPE

'/*
' * Link numbers
' */
%IMPLINK_IP              = 155
%IMPLINK_LOWEXPER        = 156
%IMPLINK_HIGHEXPER       = 158

#INCLUDE ONCE "inaddr.inc"

%ADDR_ANY         = &H00000000???   ' %INADDR_ANY

%WSADESCRIPTION_LEN = 256
%WSASYS_STATUS_LEN  = 128

' // Size = 400 bytes
TYPE WSADATA DWORD FILL
   wVersion       AS WORD                               ' WORD
   wHighVersion   AS WORD                               ' WORD
'#ifdef _WIN64
'        unsigned short          iMaxSockets;
'        unsigned short          iMaxUdpDg;
'        char FAR *              lpVendorInfo;
'        char                    szDescription[WSADESCRIPTION_LEN+1];
'        char                    szSystemStatus[WSASYS_STATUS_LEN+1];
'#else
   szDescription  AS ASCIIZ * %WSADESCRIPTION_LEN + 1   ' char[WSADESCRIPTION_LEN+1]
   szSystemStatus AS ASCIIZ * %WSASYS_STATUS_LEN + 1    ' char[WSASYS_STATUS_LEN+1]
   iMaxSockets    AS WORD                               ' unsigned short
   iMaxUdpDg      AS WORD                               ' unsigned short
   lpVendorInfo   AS ASCIIZ PTR                         ' char FAR *
'#endif
END TYPE

'/*
' * Definitions related to sockets: types, address families, options,
' * taken from the BSD file sys/socket.h.
' */

'/*
' * This is used instead of -1, since the
' * SOCKET type is unsigned.
' */
%INVALID_SOCKET = &HFFFFFFFF???   ' (SOCKET)(~0)
%SOCKET_ERROR   = -1              ' (-1)

'/*
' * The  following  may  be used in place of the address family, socket type, or
' * protocol  in  a  call  to WSASocket to indicate that the corresponding value
' * should  be taken from the supplied WSAPROTOCOL_INFO structure instead of the
' * parameter itself.
' */
%FROM_PROTOCOL_INFO = -1

'/*
' * Types
' */
%SOCK_STREAM    = 1    ' stream socket
%SOCK_DGRAM     = 2    ' datagram socket
%SOCK_RAW       = 3    ' raw-protocol interface
%SOCK_RDM       = 4    ' reliably-delivered message
%SOCK_SEQPACKET = 5    ' sequenced packet stream

'/*
' * Option flags per-socket.
' */
%SO_DEBUG       = &H0001    ' turn on debugging info recording
%SO_ACCEPTCONN  = &H0002    ' socket has had listen()
%SO_REUSEADDR   = &H0004    ' allow local address reuse
%SO_KEEPALIVE   = &H0008    ' keep connections alive
%SO_DONTROUTE   = &H0010    ' just use interface addresses
%SO_BROADCAST   = &H0020    ' permit sending of broadcast msgs
%SO_USELOOPBACK = &H0040    ' bypass hardware when possible
%SO_LINGER      = &H0080    ' linger on close if data present
%SO_OOBINLINE   = &H0100    ' leave received OOB data in line

'#define SO_DONTLINGER   (int)(~SO_LINGER)
'#define SO_EXCLUSIVEADDRUSE ((int)(~SO_REUSEADDR)) /* disallow local address reuse */
%SO_DONTLINGER       = &HFFFFFF7F   ' CLNG(NOT SO_LINGER)
%SO_EXCLUSIVEADDRUSE = &HFFFFFFFB   ' CLNG(NOT S0_REUSEADDR) disallow local address reuse

'/*
' * Additional options.
' */
%SO_SNDBUF      = &H1001    ' send buffer size
%SO_RCVBUF      = &H1002    ' receive buffer size
%SO_SNDLOWAT    = &H1003    ' send low-water mark
%SO_RCVLOWAT    = &H1004    ' receive low-water mark
%SO_SNDTIMEO    = &H1005    ' send timeout
%SO_RCVTIMEO    = &H1006    ' receive timeout
%SO_ERROR       = &H1007    ' get error status and clear
%SO_TYPE        = &H1008    ' get socket type

'/*
' * WinSock 2 extension -- new options
' */
%SO_GROUP_ID           = &H2001   ' ID of a socket group
%SO_GROUP_PRIORITY     = &H2002   ' the relative priority within a group
%SO_MAX_MSG_SIZE       = &H2003   ' maximum message size
%SO_PROTOCOL_INFO      = &H2004   ' WSAPROTOCOL_INFO structure
%SO_PROTOCOL_INFOW     = &H2005   ' WSAPROTOCOL_INFOW structure */
%PVD_CONFIG            = &H3001   ' configuration info for service provider
%SO_CONDITIONAL_ACCEPT = &H3002   ' enable true conditional accept:
                                  '  connection is not ack-ed to the
                                  '  other side until conditional
                                  '  function returns %CF_ACCEPT
'/*
' * Structure used by kernel to pass protocol
' * information in raw sockets.
' */

' // Size = 4 bytes
TYPE sockproto WORD
  sp_family   AS WORD     ' u_short // address family
  sp_protocol AS WORD     ' u_short // protocol
END TYPE

'/*
' * Protocol families, same as address families for now.
' */
%PF_UNSPEC    = %AF_UNSPEC
%PF_UNIX      = %AF_UNIX
%PF_INET      = %AF_INET
%PF_IMPLINK   = %AF_IMPLINK
%PF_PUP       = %AF_PUP
%PF_CHAOS     = %AF_CHAOS
%PF_NS        = %AF_NS
%PF_IPX       = %AF_IPX
%PF_ISO       = %AF_ISO
%PF_OSI       = %AF_OSI
%PF_ECMA      = %AF_ECMA
%PF_DATAKIT   = %AF_DATAKIT
%PF_CCITT     = %AF_CCITT
%PF_SNA       = %AF_SNA
%PF_DECnet    = %AF_DECnet
%PF_DLI       = %AF_DLI
%PF_LAT       = %AF_LAT
%PF_HYLINK    = %AF_HYLINK
%PF_APPLETALK = %AF_APPLETALK
%PF_VOICEVIEW = %AF_VOICEVIEW
%PF_FIREFOX   = %AF_FIREFOX
%PF_UNKNOWN1  = %AF_UNKNOWN1
%PF_BAN       = %AF_BAN
%PF_ATM       = %AF_ATM
%PF_INET6     = %AF_INET6
'#if(_WIN32_WINNT >= 0x0600)
#IF %WINVER >= &H0600
%PF_BTH       = %AF_BTH
#ENDIF
'#endif //(_WIN32_WINNT >= 0x0600)

%PF_MAX       = %AF_MAX

'/*
' * Structure used for manipulating linger option.
' */

' // ize = 4 bytes
TYPE linger WORD
   l_onoff  AS WORD   ' u_short // option on/off
   l_linger AS WORD   ' u_short // linger time
END TYPE

'/*
' * Level number for (get/set)sockopt() to apply to socket itself.
' */
'#define SOL_SOCKET      0xffff          /* options for socket level */
%SOL_SOCKET = &HFFFF???    ' options for socket level

'/*
' * Maximum queue length specifiable by listen.
' */
%SOMAXCONN = &H7FFFFFFF

%MSG_OOB       = &H1       ' process out-of-band data
%MSG_PEEK      = &H2       ' peek at incoming message
%MSG_DONTROUTE = &H4       ' send without using routing tables

'#if(_WIN32_WINNT >= 0x0502)
%MSG_WAITALL   = &H8       ' /* do not complete until packet is completely filled */
'#endif //(_WIN32_WINNT >= 0x0502)

%MSG_PARTIAL   = &H8000??? ' partial send or recv for message xport

'/*
' * WinSock 2 extension -- new flags for WSASend(), WSASendTo(), WSARecv() and
' *                          WSARecvFrom()
' */
%MSG_INTERRUPT = &H10   ' send/recv in the interrupt context

%MSG_MAXIOVLEN = 16

'/*
' * Define constant based on rfc883, used by gethostbyxxxx() calls.
' */
%MAXGETHOSTSTRUCT = 1024

'/*
' * WinSock 2 extension -- bit values and indices for FD_XXX network events
' */
%FD_READ_BIT    = 0
%FD_READ        = 1   ' (1 << FD_READ_BIT)

%FD_WRITE_BIT   = 1
%FD_WRITE       = 2   ' (1 << FD_WRITE_BIT)

%FD_OOB_BIT     = 2
%FD_OOB         = 4   ' (1 << FD_OOB_BIT)

%FD_ACCEPT_BIT  = 3
%FD_ACCEPT      = 8   ' (1 << FD_ACCEPT_BIT)

%FD_CONNECT_BIT = 4
%FD_CONNECT     = 16   ' (1 << FD_CONNECT_BIT)

%FD_CLOSE_BIT   = 5
%FD_CLOSE       = 32   ' (1 << FD_CLOSE_BIT)

%FD_QOS_BIT     = 6
%FD_QOS         = 64   ' (1 << FD_QOS_BIT)

%FD_GROUP_QOS_BIT = 7
%FD_GROUP_QOS   = 128   ' (1 << FD_GROUP_QOS_BIT)

%FD_ROUTING_INTERFACE_CHANGE_BIT = 8
%FD_ROUTING_INTERFACE_CHANGE = 256   ' (1 << FD_ROUTING_INTERFACE_CHANGE_BIT)

%FD_ADDRESS_LIST_CHANGE_BIT = 9
%FD_ADDRESS_LIST_CHANGE = 512   ' (1 << FD_ADDRESS_LIST_CHANGE_BIT)

%FD_MAX_EVENTS = 10
%FD_ALL_EVENTS = 1024 - 1   ' ((1 << FD_MAX_EVENTS) - 1)


'/*
' * WinSock error codes are also defined in winerror.h
' * Hence the IFDEF.
' */
#IF NOT %DEF(%WSABASEERR) '----------------------------------------------------

'/*
' * All Windows Sockets error constants are biased by WSABASEERR from
' * the "normal"
' */
%WSABASEERR             = 10000

'/*
' * Windows Sockets definitions of regular Microsoft C error constants
' */
%WSAEINTR               = %WSABASEERR + 4
%WSAEBADF               = %WSABASEERR + 9
%WSAEACCES              = %WSABASEERR + 13
%WSAEFAULT              = %WSABASEERR + 14
%WSAEINVAL              = %WSABASEERR + 22
%WSAEMFILE              = %WSABASEERR + 24

'/*
' * Windows Sockets definitions of regular Berkeley error constants
' */
%WSAEWOULDBLOCK         = %WSABASEERR + 35
%WSAEINPROGRESS         = %WSABASEERR + 36
%WSAEALREADY            = %WSABASEERR + 37
%WSAENOTSOCK            = %WSABASEERR + 38
%WSAEDESTADDRREQ        = %WSABASEERR + 39
%WSAEMSGSIZE            = %WSABASEERR + 40
%WSAEPROTOTYPE          = %WSABASEERR + 41
%WSAENOPROTOOPT         = %WSABASEERR + 42
%WSAEPROTONOSUPPORT     = %WSABASEERR + 43
%WSAESOCKTNOSUPPORT     = %WSABASEERR + 44
%WSAEOPNOTSUPP          = %WSABASEERR + 45
%WSAEPFNOSUPPORT        = %WSABASEERR + 46
%WSAEAFNOSUPPORT        = %WSABASEERR + 47
%WSAEADDRINUSE          = %WSABASEERR + 48
%WSAEADDRNOTAVAIL       = %WSABASEERR + 49
%WSAENETDOWN            = %WSABASEERR + 50
%WSAENETUNREACH         = %WSABASEERR + 51
%WSAENETRESET           = %WSABASEERR + 52
%WSAECONNABORTED        = %WSABASEERR + 53
%WSAECONNRESET          = %WSABASEERR + 54
%WSAENOBUFS             = %WSABASEERR + 55
%WSAEISCONN             = %WSABASEERR + 56
%WSAENOTCONN            = %WSABASEERR + 57
%WSAESHUTDOWN           = %WSABASEERR + 58
%WSAETOOMANYREFS        = %WSABASEERR + 59
%WSAETIMEDOUT           = %WSABASEERR + 60
%WSAECONNREFUSED        = %WSABASEERR + 61
%WSAELOOP               = %WSABASEERR + 62
%WSAENAMETOOLONG        = %WSABASEERR + 63
%WSAEHOSTDOWN           = %WSABASEERR + 64
%WSAEHOSTUNREACH        = %WSABASEERR + 65
%WSAENOTEMPTY           = %WSABASEERR + 66
%WSAEPROCLIM            = %WSABASEERR + 67
%WSAEUSERS              = %WSABASEERR + 68
%WSAEDQUOT              = %WSABASEERR + 69
%WSAESTALE              = %WSABASEERR + 70
%WSAEREMOTE             = %WSABASEERR + 71

'/*
' * Extended Windows Sockets error constant definitions
' */
%WSASYSNOTREADY         = %WSABASEERR + 91
%WSAVERNOTSUPPORTED     = %WSABASEERR + 92
%WSANOTINITIALISED      = %WSABASEERR + 93
%WSAEDISCON             = %WSABASEERR + 101
%WSAENOMORE             = %WSABASEERR + 102
%WSAECANCELLED          = %WSABASEERR + 103
%WSAEINVALIDPROCTABLE   = %WSABASEERR + 104
%WSAEINVALIDPROVIDER    = %WSABASEERR + 105
%WSAEPROVIDERFAILEDINIT = %WSABASEERR + 106
%WSASYSCALLFAILURE      = %WSABASEERR + 107
%WSASERVICE_NOT_FOUND   = %WSABASEERR + 108
%WSATYPE_NOT_FOUND      = %WSABASEERR + 109
%WSA_E_NO_MORE          = %WSABASEERR + 110
%WSA_E_CANCELLED        = %WSABASEERR + 111
%WSAEREFUSED            = %WSABASEERR + 112

'/*
' * Error return codes from gethostbyname() and gethostbyaddr()
' * (when using the resolver). Note that these errors are
' * retrieved via WSAGetLastError() and must therefore follow
' * the rules for avoiding clashes with error numbers from
' * specific implementations or language run-time systems.
' * For this reason the codes are based at WSABASEERR+1001.
' * Note also that [WSA]NO_ADDRESS is defined only for
' * compatibility purposes.
' */

'/* Authoritative Answer: Host not found */
%WSAHOST_NOT_FOUND      = %WSABASEERR+1001

'/* Non-Authoritative: Host not found, or SERVERFAIL */
%WSATRY_AGAIN           = %WSABASEERR+1002

'/* Non-recoverable errors, FORMERR, REFUSED, NOTIMP */
%WSANO_RECOVERY         = %WSABASEERR+1003

'/* Valid name, no data record of requested type */
%WSANO_DATA             = %WSABASEERR+1004

'/*
' * Define QOS related error return codes
' *
' */
%WSA_QOS_RECEIVERS               = %WSABASEERR + 1005
         ' /* at least one Reserve has arrived */
%WSA_QOS_SENDERS                 = %WSABASEERR + 1006
         ' /* at least one Path has arrived */
%WSA_QOS_NO_SENDERS              = %WSABASEERR + 1007
         ' /* there are no senders */
%WSA_QOS_NO_RECEIVERS            = %WSABASEERR + 1008
         ' /* there are no receivers */
%WSA_QOS_REQUEST_CONFIRMED       = %WSABASEERR + 1009
         ' /* Reserve has been confirmed */
%WSA_QOS_ADMISSION_FAILURE       = %WSABASEERR + 1010
         ' /* error due to lack of resources */
%WSA_QOS_POLICY_FAILURE          = %WSABASEERR + 1011
         ' /* rejected for administrative reasons - bad credentials */
%WSA_QOS_BAD_STYLE               = %WSABASEERR + 1012
         ' /* unknown or conflicting style */
%WSA_QOS_BAD_OBJECT              = %WSABASEERR + 1013
         ' /* problem with some part of the filterspec or providerspecific
         ' * buffer in general */
%WSA_QOS_TRAFFIC_CTRL_ERROR      = %WSABASEERR + 1014
         ' /* problem with some part of the flowspec */
%WSA_QOS_GENERIC_ERROR           = %WSABASEERR + 1015
         ' /* general error */
%WSA_QOS_ESERVICETYPE            = %WSABASEERR + 1016
         ' /* invalid service type in flowspec */
%WSA_QOS_EFLOWSPEC               = %WSABASEERR + 1017
         ' /* invalid flowspec */
%WSA_QOS_EPROVSPECBUF            = %WSABASEERR + 1018
         ' /* invalid provider specific buffer */
%WSA_QOS_EFILTERSTYLE            = %WSABASEERR + 1019
         ' /* invalid filter style */
%WSA_QOS_EFILTERTYPE             = %WSABASEERR + 1020
         ' /* invalid filter type */
%WSA_QOS_EFILTERCOUNT            = %WSABASEERR + 1021
         ' /* incorrect number of filters */
%WSA_QOS_EOBJLENGTH              = %WSABASEERR + 1022
         ' /* invalid object length */
%WSA_QOS_EFLOWCOUNT              = %WSABASEERR + 1023
         ' /* incorrect number of flows */
%WSA_QOS_EUNKOWNPSOBJ            = %WSABASEERR + 1024
         ' /* unknown object in provider specific buffer */
%WSA_QOS_EPOLICYOBJ              = %WSABASEERR + 1025
         ' /* invalid policy object in provider specific buffer */
%WSA_QOS_EFLOWDESC               = %WSABASEERR + 1026
         ' /* invalid flow descriptor in the list */
%WSA_QOS_EPSFLOWSPEC             = %WSABASEERR + 1027
         ' /* inconsistent flow spec in provider specific buffer */
%WSA_QOS_EPSFILTERSPEC           = %WSABASEERR + 1028
         ' /* invalid filter spec in provider specific buffer */
%WSA_QOS_ESDMODEOBJ              = %WSABASEERR + 1029
         ' /* invalid shape discard mode object in provider specific buffer */
%WSA_QOS_ESHAPERATEOBJ           = %WSABASEERR + 1030
         ' /* invalid shaping rate object in provider specific buffer */
%WSA_QOS_RESERVED_PETYPE         = %WSABASEERR + 1031
         ' /* reserved policy element in provider specific buffer */


'/*
' * WinSock error codes are also defined in winerror.h
' * Hence the IFDEF.
' */
#ENDIF ' #IF NOT %DEF(%WSABASEERR) --------------------------------------------

'/*
' * Compatibility macros.
' */

'#define h_errno         WSAGetLastError()

'#define HOST_NOT_FOUND          WSAHOST_NOT_FOUND
'#define TRY_AGAIN               WSATRY_AGAIN
'#define NO_RECOVERY             WSANO_RECOVERY
'#define NO_DATA                 WSANO_DATA
'/* no address, look for MX record */
'#define WSANO_ADDRESS           WSANO_DATA
'#define NO_ADDRESS              WSANO_ADDRESS

%HOST_NOT_FOUND = %WSAHOST_NOT_FOUND
%TRY_AGAIN      = %WSATRY_AGAIN
%NO_RECOVERY    = %WSANO_RECOVERY
%NO_DATA        = %WSANO_DATA
' no address, look for MX record
%WSANO_ADDRESS  = %WSANO_DATA
%NO_ADDRESS     = %WSANO_ADDRESS


'/*
' * Windows Sockets errors redefined as regular Berkeley error constants.
' * These are commented out in Windows NT to avoid conflicts with errno.h.
' * Use the WSA constants instead.
' */
'#if 0
'#define EWOULDBLOCK             WSAEWOULDBLOCK
'#define EINPROGRESS             WSAEINPROGRESS
'#define EALREADY                WSAEALREADY
'#define ENOTSOCK                WSAENOTSOCK
'#define EDESTADDRREQ            WSAEDESTADDRREQ
'#define EMSGSIZE                WSAEMSGSIZE
'#define EPROTOTYPE              WSAEPROTOTYPE
'#define ENOPROTOOPT             WSAENOPROTOOPT
'#define EPROTONOSUPPORT         WSAEPROTONOSUPPORT
'#define ESOCKTNOSUPPORT         WSAESOCKTNOSUPPORT
'#define EOPNOTSUPP              WSAEOPNOTSUPP
'#define EPFNOSUPPORT            WSAEPFNOSUPPORT
'#define EAFNOSUPPORT            WSAEAFNOSUPPORT
'#define EADDRINUSE              WSAEADDRINUSE
'#define EADDRNOTAVAIL           WSAEADDRNOTAVAIL
'#define ENETDOWN                WSAENETDOWN
'#define ENETUNREACH             WSAENETUNREACH
'#define ENETRESET               WSAENETRESET
'#define ECONNABORTED            WSAECONNABORTED
'#define ECONNRESET              WSAECONNRESET
'#define ENOBUFS                 WSAENOBUFS
'#define EISCONN                 WSAEISCONN
'#define ENOTCONN                WSAENOTCONN
'#define ESHUTDOWN               WSAESHUTDOWN
'#define ETOOMANYREFS            WSAETOOMANYREFS
'#define ETIMEDOUT               WSAETIMEDOUT
'#define ECONNREFUSED            WSAECONNREFUSED
'#define ELOOP                   WSAELOOP
'#define ENAMETOOLONG            WSAENAMETOOLONG
'#define EHOSTDOWN               WSAEHOSTDOWN
'#define EHOSTUNREACH            WSAEHOSTUNREACH
'#define ENOTEMPTY               WSAENOTEMPTY
'#define EPROCLIM                WSAEPROCLIM
'#define EUSERS                  WSAEUSERS
'#define EDQUOT                  WSAEDQUOT
'#define ESTALE                  WSAESTALE
'#define EREMOTE                 WSAEREMOTE
'#endif

'%EWOULDBLOCK     = %WSAEWOULDBLOCK
'%EINPROGRESS     = %WSAEINPROGRESS
'%EALREADY        = %WSAEALREADY
'%ENOTSOCK        = %WSAENOTSOCK
'%EDESTADDRREQ    = %WSAEDESTADDRREQ
'%EMSGSIZE        = %WSAEMSGSIZE
'%EPROTOTYPE      = %WSAEPROTOTYPE
'%ENOPROTOOPT     = %WSAENOPROTOOPT
'%EPROTONOSUPPORT = %WSAEPROTONOSUPPORT
'%ESOCKTNOSUPPORT = %WSAESOCKTNOSUPPORT
'%EOPNOTSUPP      = %WSAEOPNOTSUPP
'%EPFNOSUPPORT    = %WSAEPFNOSUPPORT
'%EAFNOSUPPORT    = %WSAEAFNOSUPPORT
'%EADDRINUSE      = %WSAEADDRINUSE
'%EADDRNOTAVAIL   = %WSAEADDRNOTAVAIL
'%ENETDOWN        = %WSAENETDOWN
'%ENETUNREACH     = %WSAENETUNREACH
'%ENETRESET       = %WSAENETRESET
'%ECONNABORTED    = %WSAECONNABORTED
'%ECONNRESET      = %WSAECONNRESET
'%ENOBUFS         = %WSAENOBUFS
'%EISCONN         = %WSAEISCONN
'%ENOTCONN        = %WSAENOTCONN
'%ESHUTDOWN       = %WSAESHUTDOWN
'%ETOOMANYREFS    = %WSAETOOMANYREFS
'%ETIMEDOUT       = %WSAETIMEDOUT
'%ECONNREFUSED    = %WSAECONNREFUSED
'%ELOOP           = %WSAELOOP
'%ENAMETOOLONG    = %WSAENAMETOOLONG
'%EHOSTDOWN       = %WSAEHOSTDOWN
'%EHOSTUNREACH    = %WSAEHOSTUNREACH
'%ENOTEMPTY       = %WSAENOTEMPTY
'%EPROCLIM        = %WSAEPROCLIM
'%EUSERS          = %WSAEUSERS
'%EDQUOT          = %WSAEDQUOT
'%ESTALE          = %WSAESTALE
'%EREMOTE         = %WSAEREMOTE

'/*
' * WinSock 2 extension -- new error codes and type definition
' */

'#ifdef WIN32

'#define WSAAPI                  FAR PASCAL
'#define WSAEVENT                HANDLE
'#define LPWSAEVENT              LPHANDLE

'#define WSAOVERLAPPED           OVERLAPPED
'typedef struct _OVERLAPPED *    LPWSAOVERLAPPED;

' // Size = 20 bytes
TYPE WSAOVERLAPPED DWORD
   Internal     AS DWORD   ' DWORD
   InternalHigh AS DWORD   ' DWORD
   offset       AS DWORD   ' DWORD
   OffsetHigh   AS DWORD   ' DWORD
   hEvent       AS DWORD   ' DWORD
END TYPE

%WSA_IO_PENDING         = %ERROR_IO_PENDING
%WSA_IO_INCOMPLETE      = %ERROR_IO_INCOMPLETE
%WSA_INVALID_HANDLE     = %ERROR_INVALID_HANDLE
%WSA_INVALID_PARAMETER  = %ERROR_INVALID_PARAMETER
%WSA_NOT_ENOUGH_MEMORY  = %ERROR_NOT_ENOUGH_MEMORY
%WSA_OPERATION_ABORTED  = %ERROR_OPERATION_ABORTED

%WSA_INVALID_EVENT      = 0???
%WSA_MAXIMUM_WAIT_EVENTS= %MAXIMUM_WAIT_OBJECTS
%WSA_WAIT_FAILED        = %WAIT_FAILED
%WSA_WAIT_EVENT_0       = %WAIT_OBJECT_0
%WSA_WAIT_IO_COMPLETION = %WAIT_IO_COMPLETION
%WSA_WAIT_TIMEOUT       = %WAIT_TIMEOUT
%WSA_INFINITE           = %INFINITE

'#else /* WIN16 */

'#define WSAAPI                  FAR PASCAL
'typedef DWORD                   WSAEVENT, FAR * LPWSAEVENT;

'typedef struct _WSAOVERLAPPED {
'    DWORD    Internal;
'    DWORD    InternalHigh;
'    DWORD    Offset;
'    DWORD    OffsetHigh;
'    WSAEVENT hEvent;
'} WSAOVERLAPPED, FAR * LPWSAOVERLAPPED;

'#define WSA_IO_PENDING          (WSAEWOULDBLOCK)
'#define WSA_IO_INCOMPLETE       (WSAEWOULDBLOCK)
'#define WSA_INVALID_HANDLE      (WSAENOTSOCK)
'#define WSA_INVALID_PARAMETER   (WSAEINVAL)
'#define WSA_NOT_ENOUGH_MEMORY   (WSAENOBUFS)
'#define WSA_OPERATION_ABORTED   (WSAEINTR)

'#define WSA_INVALID_EVENT       ((WSAEVENT)NULL)
'#define WSA_MAXIMUM_WAIT_EVENTS (MAXIMUM_WAIT_OBJECTS)
'#define WSA_WAIT_FAILED         ((DWORD)-1L)
'#define WSA_WAIT_EVENT_0        ((DWORD)0)
'#define WSA_WAIT_TIMEOUT        ((DWORD)0x102L)
'#define WSA_INFINITE            ((DWORD)-1L)

'#endif  /* WIN32 */

'/*
' * Include qos.h to pull in FLOWSPEC and related definitions
' */

#INCLUDE ONCE "qos.inc"

' // Size = 72 bytes
TYPE QOS DWORD
  SendingFlowspec   AS FLOWSPEC   ' FLOWSPEC // the flow spec for data sending
  ReceivingFlowspec AS FLOWSPEC   ' FLOWSPEC // the flow spec for data receiving
  ProviderSpecific  AS WSABUF     ' WSABUF   // additional provider-specific stuff
END TYPE

'/*
' * WinSock 2 extension -- manifest constants for return values of the condition function
' */
%CF_ACCEPT = &H0000
%CF_REJECT = &H0001
%CF_DEFER  = &H0002

'/*
' * WinSock 2 extension -- manifest constants for shutdown()
' */
%SD_RECEIVE = &H00
%SD_SEND    = &H01
%SD_BOTH    = &H02

'/*
' * WinSock 2 extension -- data type and manifest constants for socket groups
' */
'typedef unsigned int             GROUP;

%SG_UNCONSTRAINED_GROUP = &H01
%SG_CONSTRAINED_GROUP   = &H02

'/*
' * WinSock 2 extension -- data type for WSAEnumNetworkEvents()
' */
' // Size = 44 bytes
TYPE WSANETWORKEVENTS DWORD
  lNetworkEvents AS LONG                   ' LONG
  iErrorCode(%FD_MAX_EVENTS - 1) AS LONG   ' __int
END TYPE

'/*
' * WinSock 2 extension -- WSAPROTOCOL_INFO structure and associated
' * manifest constants
' */

'#ifndef GUID_DEFINED
'#include <guiddef.h>
'#endif /* GUID_DEFINED */

#IF NOT %DEF(%GUID_DEFINED)
#INCLUDE ONCE "guiddef.inc"
#ENDIF

%MAX_PROTOCOL_CHAIN = 7

%BASE_PROTOCOL      = 1
%LAYERED_PROTOCOL   = 0

' // Size = 32 bytes
TYPE WSAPROTOCOLCHAIN DWORD
  ChainLen AS LONG    ' __int // the length of the chain (=0, layered protocol; =1, base protocol; >1, protocol chain)
  ChainEntries(%MAX_PROTOCOL_CHAIN - 1) AS DWORD   ' DWORD // a list of dwCatalogEntryIds
END TYPE

%WSAPROTOCOL_LEN = 255

' // Size = 372 bytes
TYPE WSAPROTOCOL_INFOA DWORD
   dwServiceFlags1    AS DWORD   ' DWORD
   dwServiceFlags2    AS DWORD   ' DWORD
   dwServiceFlags3    AS DWORD   ' DWORD
   dwServiceFlags4    AS DWORD   ' DWORD
   dwProviderFlags    AS DWORD   ' DWORD
   ProviderId         AS GUID    ' GUID
   dwCatalogEntryId   AS DWORD   ' DWORD
   ProtocolChain      AS WSAPROTOCOLCHAIN
   iVersion           AS LONG    ' __int
   iAddressFamily     AS LONG    ' __int
   iMaxSockAddr       AS LONG    ' __int
   iMinSockAddr       AS LONG    ' __int
   iSocketType        AS LONG    ' __int
   iProtocol          AS LONG    ' __int
   iProtocolMaxOffset AS LONG    ' __int
   iNetworkByteOrder  AS LONG    ' __int
   iSecurityScheme    AS LONG    ' __int
   dwMessageSize      AS DWORD   ' DWORD
   dwProviderReserved AS DWORD   ' DWORD
   szProtocol         AS ASCIIZ * (%WSAPROTOCOL_LEN + 1)   ' CHAR
END TYPE

' // Size = 628 bytes
TYPE WSAPROTOCOL_INFOW DWORD
   dwServiceFlags1    AS DWORD   ' DWORD
   dwServiceFlags2    AS DWORD   ' DWORD
   dwServiceFlags3    AS DWORD   ' DWORD
   dwServiceFlags4    AS DWORD   ' DWORD
   dwProviderFlags    AS DWORD   ' DWORD
   ProviderId         AS GUID    ' GUID
   dwCatalogEntryId   AS DWORD   ' DWORD
   ProtocolChain      AS WSAPROTOCOLCHAIN
   iVersion           AS LONG    ' __int
   iAddressFamily     AS LONG    ' __int
   iMaxSockAddr       AS LONG    ' __int
   iMinSockAddr       AS LONG    ' __int
   iSocketType        AS LONG    ' __int
   iProtocol          AS LONG    ' __int
   iProtocolMaxOffset AS LONG    ' __int
   iNetworkByteOrder  AS LONG    ' __int
   iSecurityScheme    AS LONG    ' __int
   dwMessageSize      AS DWORD   ' DWORD
   dwProviderReserved AS DWORD   ' DWORD
   szProtocol         AS WSTRINGZ * %WSAPROTOCOL_LEN + 1   ' WCHAR
END TYPE

#IF %DEF(%UNICODE)
   MACRO WSAPROTOCOL_INFO = WSAPROTOCOL_INFOAW
#ELSE
   MACRO WSAPROTOCOL_INFO = WSAPROTOCOL_INFOAA
#ENDIF

'/* Flag bit definitions for dwProviderFlags */
%PFL_MULTIPLE_PROTO_ENTRIES   = &H00000001???
%PFL_RECOMMENDED_PROTO_ENTRY  = &H00000002???
%PFL_HIDDEN                   = &H00000004???
%PFL_MATCHES_PROTOCOL_ZERO    = &H00000008???
%PFL_NETWORKDIRECT_PROVIDER   = &H00000010???

'/* Flag bit definitions for dwServiceFlags1 */
%XP1_CONNECTIONLESS           = &H00000001???
%XP1_GUARANTEED_DELIVERY      = &H00000002???
%XP1_GUARANTEED_ORDER         = &H00000004???
%XP1_MESSAGE_ORIENTED         = &H00000008???
%XP1_PSEUDO_STREAM            = &H00000010???
%XP1_GRACEFUL_CLOSE           = &H00000020???
%XP1_EXPEDITED_DATA           = &H00000040???
%XP1_CONNECT_DATA             = &H00000080???
%XP1_DISCONNECT_DATA          = &H00000100???
%XP1_SUPPORT_BROADCAST        = &H00000200???
%XP1_SUPPORT_MULTIPOINT       = &H00000400???
%XP1_MULTIPOINT_CONTROL_PLANE = &H00000800???
%XP1_MULTIPOINT_DATA_PLANE    = &H00001000???
%XP1_QOS_SUPPORTED            = &H00002000???
%XP1_INTERRUPT                = &H00004000???
%XP1_UNI_SEND                 = &H00008000???
%XP1_UNI_RECV                 = &H00010000???
%XP1_IFS_HANDLES              = &H00020000???
%XP1_PARTIAL_MESSAGE          = &H00040000???
%XP1_SAN_SUPPORT_SDP          = &H00080000???

%BIGENDIAN    = &H0000&
%LITTLEENDIAN = &H0001&

%SECURITY_PROTOCOL_NONE = &H0000&

'/*
' * WinSock 2 extension -- manifest constants for WSAJoinLeaf()
' */
%JL_SENDER_ONLY   = &H01???
%JL_RECEIVER_ONLY = &H02???
%JL_BOTH          = &H04???

'/*
' * WinSock 2 extension -- manifest constants for WSASocket()
' */
%WSA_FLAG_OVERLAPPED             = &H01???
%WSA_FLAG_MULTIPOINT_C_ROOT      = &H02???
%WSA_FLAG_MULTIPOINT_C_LEAF      = &H04???
%WSA_FLAG_MULTIPOINT_D_ROOT      = &H08???
%WSA_FLAG_MULTIPOINT_D_LEAF      = &H10???
%WSA_FLAG_ACCESS_SYSTEM_SECURITY = &H40???

'/*
' * WinSock 2 extensions -- data types for the condition function in
' * WSAAccept() and overlapped I/O completion routine.
' */

'typedef
'int
'(CALLBACK * LPCONDITIONPROC)(
'    IN LPWSABUF lpCallerId,
'    IN LPWSABUF lpCallerData,
'    IN OUT LPQOS lpSQOS,
'    IN OUT LPQOS lpGQOS,
'    IN LPWSABUF lpCalleeId,
'    IN LPWSABUF lpCalleeData,
'    OUT GROUP FAR * g,
'    IN DWORD_PTR dwCallbackData
'    );

'FUNCTION CONDITIONPROC ( _
'   BYREF lpCallerId AS WSABUF, _       ' __in LPWSABUF lpCallerId
'   BYREF lpCallerData AS WSABUF, _     ' __in LPWSABUF lpCallerData
'   BYREF lpSQOS AS QOS, _              ' __in_out LPQOS lpSQOS
'   BYREF lpGQOS AS QOS, _              ' __in_out LPQOS lpGQOS
'   BYREF lpCalleeId AS WSABUF, _       ' __in LPWSABUF lpCalleeId
'   BYREF lpCalleeData AS WSABUF, _     ' __in LPWSABUF lpCalleeData
'   BYREF g AS DWORD, _                 ' __out GROUP FAR * g
'   BYVAL dwCallbackData AS DWORD _     ' __in DWORD_PTR dwCallbackData
'   ) AS LONG

'typedef
'void
'(CALLBACK * LPWSAOVERLAPPED_COMPLETION_ROUTINE)(
'    IN DWORD dwError,
'    IN DWORD cbTransferred,
'    IN LPWSAOVERLAPPED lpOverlapped,
'    IN DWORD dwFlags
'    );

'SUB WSAOVERLAPPED_COMPLETION_ROUTINE ( _
'   BYVAL dwError AS DWORD, _              ' __in DWORD dwError
'   BYVAL cbTransferred AS DWORD, _        '  IN DWORD cbTransferred
'   BYREF lpOverlapped AS WSAOVERLAPPED, _ ' __in LPWSAOVERLAPPED lpOverlapped
'   BYVAL dwFlags AS DWORD _               ' __in DWORD dwFlags
'   )

'#if(_WIN32_WINNT >= 0x0501)

'/*
' * WinSock 2 extension -- manifest constants and associated structures
' * for WSANSPIoctl()
' */
'#define SIO_NSP_NOTIFY_CHANGE         _WSAIOW(IOC_WS2,25)
%SIO_NSP_NOTIFY_CHANGE         = &H88000019???

' WSACOMPLETIONTYPE enum
%NSP_NOTIFY_IMMEDIATELY = 0
%NSP_NOTIFY_HWND        = 1
%NSP_NOTIFY_EVENT       = 2
%NSP_NOTIFY_PORT        = 3
%NSP_NOTIFY_APC         = 4

'typedef struct _WSACOMPLETION {
'    WSACOMPLETIONTYPE Type;
'    union {
'        struct {
'            HWND hWnd;
'            UINT uMsg;
'            WPARAM context;
'        } WindowMessage;
'        struct {
'            LPWSAOVERLAPPED lpOverlapped;
'        } Event;
'        struct {
'            LPWSAOVERLAPPED lpOverlapped;
'            LPWSAOVERLAPPED_COMPLETION_ROUTINE lpfnCompletionProc;
'        } Apc;
'        struct {
'            LPWSAOVERLAPPED lpOverlapped;
'            HANDLE hPort;
'            ULONG_PTR Key;
'        } Port;
'    } Parameters;
'} WSACOMPLETION, *PWSACOMPLETION, FAR *LPWSACOMPLETION;

' // Size = 12 bytes
TYPE WSACOMPLETION_WindowMessage DWORD
   hWnd    AS DWORD
   uMsg    AS DWORD
   context AS DWORD
END TYPE

' // Size = 4 bytes
TYPE WSACOMPLETION_Event DWORD
   lpOverlapped AS WSAOVERLAPPED PTR
END TYPE

' // Size = 8 bytes
TYPE WSACOMPLETION_Apc DWORD
   lpOverlapped       AS WSAOVERLAPPED PTR
   lpfnCompletionProc AS DWORD
END TYPE

' // Size = 12 bytes
TYPE WSACOMPLETION_Port DWORD
   lpOverlapped AS WSAOVERLAPPED PTR
   hPort        AS DWORD
   Key          AS DWORD
END TYPE

' // Size = 12 bytes
UNION WSACOMPLETION_Parameters DWORD
   WindowMessage AS WSACOMPLETION_WindowMessage
   Event AS WSACOMPLETION_Event
   Apc AS WSACOMPLETION_Apc
   Port AS WSACOMPLETION_Port
END UNION

' // Size = 16 bytes
TYPE WSACOMPLETION DWORD
   Type AS LONG
   Parameters AS WSACOMPLETION_Parameters
END TYPE
'#endif //(_WIN32_WINNT >= 0x0501)

'/*
' * WinSock 2 extension -- manifest constants for SIO_TRANSLATE_HANDLE ioctl
' */
%TH_NETDEV = &H00000001???
%TH_TAPI   = &H00000002???


'/*
' * Microsoft Windows Extended data types required for the functions to
' * convert   back  and  forth  between  binary  and  string  forms  of
' * addresses.
' */
'typedef struct sockaddr SOCKADDR;
'typedef struct sockaddr *PSOCKADDR;
'typedef struct sockaddr FAR *LPSOCKADDR;

'typedef struct sockaddr_storage SOCKADDR_STORAGE;
'typedef struct sockaddr_storage *PSOCKADDR_STORAGE;
'typedef struct sockaddr_storage FAR *LPSOCKADDR_STORAGE;

'/*
' * Manifest constants and type definitions related to name resolution and
' * registration (RNR) API
' */

'#ifndef _tagBLOB_DEFINED
'#define _tagBLOB_DEFINED
'#define _BLOB_DEFINED
'#define _LPBLOB_DEFINED
'typedef struct _BLOB {
'    ULONG cbSize ;
'#ifdef MIDL_PASS
'    [size_is(cbSize)] BYTE *pBlobData;
'#else  /* MIDL_PASS */
'    BYTE *pBlobData ;
'#endif /* MIDL_PASS */
'} BLOB, *LPBLOB ;
'#endif

#IF NOT %DEF(%BLOB_DEFINED)
%BLOB_DEFINED = 1
' // Size = 8 bytes
TYPE BLOB DWORD
   cbSize    AS DWORD
   pBlobData AS BYTE PTR
END TYPE
#ENDIF

'/*
' * Service Install Flags
' */

%SERVICE_MULTIPLE       = &H00000001???

'/*
' *& Name Spaces
' */

%NS_ALL         = 0

%NS_SAP         = 1
%NS_NDS         = 2
%NS_PEER_BROWSE = 3
%NS_SLP         = 5
%NS_DHCP        = 6

%NS_TCPIP_LOCAL = 10
%NS_TCPIP_HOSTS = 11
%NS_DNS         = 12
%NS_NETBT       = 13
%NS_WINS        = 14

'#if(_WIN32_WINNT >= 0x0501)
%NS_NLA         = 15   ' /* Network Location Awareness */
'#endif //(_WIN32_WINNT >= 0x0501)

'#if(_WIN32_WINNT >= 0x0600)
%NS_BTH         = 16   ' /* Bluetooth SDP Namespace */
'#endif //(_WIN32_WINNT >= 0x0600)

%NS_LOCALNAME   = 19   ' /* Windows Live */

%NS_NBP         = 20

%NS_MS          = 30
%NS_STDA        = 31
%NS_NTDS        = 32

'#if(_WIN32_WINNT >= 0x0600)
%NS_EMAIL       = 37
%NS_PNRPNAME    = 38
%NS_PNRPCLOUD   = 39
'#endif //(_WIN32_WINNT >= 0x0600)

%NS_X500        = 40
%NS_NIS         = 41
%NS_NISPLUS     = 42

%NS_WRQ         = 50

%NS_NETDES      = 60    ' Network Designers Limited

'/*
' * Resolution flags for WSAGetAddressByName().
' * Note these are also used by the 1.1 API GetAddressByName, so
' * leave them around.
' */
%RES_UNUSED_1    = &H00000001???
%RES_FLUSH_CACHE = &H00000002???
#IF NOT %DEF(%RES_SERVICE)
%RES_SERVICE     = &H00000004???
#ENDIF

'/*
' * Well known value names for Service Types
' */

$SERVICE_TYPE_VALUE_IPXPORTA       = "IpxSocket"
$$SERVICE_TYPE_VALUE_IPXPORTW      = "IpxSocket"$$

$SERVICE_TYPE_VALUE_SAPIDA         = "SapId"
$$SERVICE_TYPE_VALUE_SAPIDW        = "SapId"$$

$SERVICE_TYPE_VALUE_TCPPORTA       = "TcpPort"
$$SERVICE_TYPE_VALUE_TCPPORTW      = "TcpPort"$$

$SERVICE_TYPE_VALUE_UDPPORTA       = "UdpPort"
$$SERVICE_TYPE_VALUE_UDPPORTW      = "UdpPort"$$

$SERVICE_TYPE_VALUE_OBJECTIDA      = "ObjectId"
$$SERVICE_TYPE_VALUE_OBJECTIDW     = "ObjectId"$$

'/*
' * SockAddr Information
' */
#IF NOT %DEF(%SOCKET_ADDRESS_DEFINED)
%SOCKET_ADDRESS_DEFINED = 1
' // Size = 8 bytes
TYPE SOCKET_ADDRESS DWORD
   lpSocaddr       AS SOCKADDR PTR   ' LPSOCKADDR lpSockaddr
   iSockaddrLength AS LONG           ' __inT
END TYPE
#ENDIF

'/*
' *  Address Family/Protocol Tuples
' */
' // Size = 8 bytes
TYPE AFPROTOCOLS DWORD
   iAddressFamily AS LONG   ' __inT
   iProtocol      AS LONG   ' __inT
END TYPE

'/*
' * Client Query API Typedefs
' */

'/*
' * The comparators
' */
' WSAECOMPARATOR enum
%COMP_EQUAL   = 0
%COMP_NOTLESS = 1

' // Size = 8 bytes
TYPE WSAVERSION DWORD
   dwVersion AS DWORD   ' DWORD
   ecHow     AS LONG    ' WSAECOMPARATOR
END TYPE

' // Size = 60 bytes
TYPE WSAQUERYSETA DWORD
   dwSize                  AS DWORD             ' DWORD
   lpszServiceInstanceName AS ASCIIZ      PTR   ' LPSTR
   lpServiceClassId        AS GUID        PTR   ' LPGUID
   lpVersion               AS WSAVERSION  PTR   ' LPWSAVERSION
   lpszComment             AS ASCIIZ      PTR   ' LPSTR
   dwNameSpace             AS DWORD             ' DWORD
   lpNSProviderId          AS GUID        PTR   ' LPGUID
   lpszContext             AS ASCIIZ      PTR   ' LPSTR
   dwNumberOfProtocols     AS DWORD             ' DWORD
   lpafpProtocols          AS AFPROTOCOLS PTR   ' LPAFPROTOCOLS
   lpszQueryString         AS ASCIIZ      PTR   ' LPSTR
   dwNumberOfCsAddrs       AS DWORD             ' DWORD
   lpcsaBuffer             AS CSADDR_INFO PTR   ' LPCSADDR_INFO
   dwOutputFlags           AS DWORD             ' DWORD
   lpBlob                  AS BLOB        PTR   ' LPBLOB
END TYPE

' // Size = 60 bytes
TYPE WSAQUERYSETW DWORD
   dwSize                  AS DWORD             ' DWORD
   lpszServiceInstanceName AS WSTRINGZ    PTR   ' LPWSTR
   lpServiceClassId        AS GUID        PTR   ' LPGUID
   lpVersion               AS WSAVERSION  PTR   ' LPWSAVERSION
   lpszComment             AS WSTRINGZ    PTR   ' LPWSTR
   dwNameSpace             AS DWORD             ' DWORD
   lpNSProviderId          AS GUID        PTR   ' LPGUID
   lpszContext             AS WSTRINGZ    PTR   ' LPWSTR
   dwNumberOfProtocols     AS DWORD             ' DWORD
   lpafpProtocols          AS AFPROTOCOLS PTR   ' LPAFPROTOCOLS
   lpszQueryString         AS WSTRINGZ    PTR   ' LPWSTR
   dwNumberOfCsAddrs       AS DWORD             ' DWORD
   lpcsaBuffer             AS CSADDR_INFO PTR   ' LPCSADDR_INFO
   dwOutputFlags           AS DWORD             ' DWORD
   lpBlob                  AS BLOB        PTR   ' LPBLOB
END TYPE

#IF %DEF(%UNICODE)
   MACRO WSAQUERYSET = WSAQUERYSETW
#ELSE
   MACRO WSAQUERYSET = WSAQUERYSETA
#ENDIF

' // Size = 56 bytes
TYPE WSAQUERYSET2A DWORD
   dwSize                  AS DWORD             ' DWORD
   lpszServiceInstanceName AS ASCIIZ      PTR   ' LPSTR
   lpVersion               AS WSAVERSION  PTR   ' LPWSAVERSION
   lpszComment             AS ASCIIZ      PTR   ' LPSTR
   dwNameSpace             AS DWORD             ' DWORD
   lpNSProviderId          AS GUID        PTR   ' LPGUID
   lpszContext             AS ASCIIZ      PTR   ' LPSTR
   dwNumberOfProtocols     AS DWORD             ' DWORD
   lpafpProtocols          AS AFPROTOCOLS PTR   ' LPAFPROTOCOLS
   lpszQueryString         AS ASCIIZ      PTR   ' LPSTR
   dwNumberOfCsAddrs       AS DWORD             ' DWORD
   lpcsaBuffer             AS CSADDR_INFO PTR   ' LPCSADDR_INFO
   dwOutputFlags           AS DWORD             ' DWORD
   lpBlob                  AS BLOB        PTR   ' LPBLOB
END TYPE

' // Size = 56 bytes
TYPE WSAQUERYSET2W DWORD
   dwSize                  AS DWORD             ' DWORD
   lpszServiceInstanceName AS WSTRINGZ    PTR   ' LPWSTR
   lpVersion               AS WSAVERSION  PTR   ' LPWSAVERSION
   lpszComment             AS WSTRINGZ    PTR   ' LPWSTR
   dwNameSpace             AS DWORD             ' DWORD
   lpNSProviderId          AS GUID        PTR   ' LPGUID
   lpszContext             AS WSTRINGZ    PTR   ' LPWSTR
   dwNumberOfProtocols     AS DWORD             ' DWORD
   lpafpProtocols          AS AFPROTOCOLS PTR   ' LPAFPROTOCOLS
   lpszQueryString         AS WSTRINGZ    PTR   ' LPWSTR
   dwNumberOfCsAddrs       AS DWORD             ' DWORD
   lpcsaBuffer             AS CSADDR_INFO PTR   ' LPCSADDR_INFO
   dwOutputFlags           AS DWORD             ' DWORD
   lpBlob                  AS BLOB        PTR   ' LPBLOB
END TYPE

#IF %DEF(%UNICODE)
   MACRO WSAQUERYSET2 = WSAQUERYSET2W
#ELSE
   MACRO WSAQUERYSET2 = WSAQUERYSET2A
#ENDIF

%LUP_DEEP                = &H0001???
%LUP_CONTAINERS          = &H0002???
%LUP_NOCONTAINERS        = &H0004???
%LUP_NEAREST             = &H0008???
%LUP_RETURN_NAME         = &H0010???
%LUP_RETURN_TYPE         = &H0020???
%LUP_RETURN_VERSION      = &H0040???
%LUP_RETURN_COMMENT      = &H0080???
%LUP_RETURN_ADDR         = &H0100???
%LUP_RETURN_BLOB         = &H0200???
%LUP_RETURN_ALIASES      = &H0400???
%LUP_RETURN_QUERY_STRING = &H0800???
%LUP_RETURN_ALL          = &H0FF0???
%LUP_RES_SERVICE         = &H8000???

%LUP_FLUSHCACHE          = &H1000???
%LUP_FLUSHPREVIOUS       = &H2000???

%LUP_NON_AUTHORITATIVE   = &H4000???
%LUP_SECURE              = &H8000???
%LUP_RETURN_PREFERRED_NAMES  = &H10000???

%LUP_ADDRCONFIG          = &H00100000???
%LUP_DUAL_ADDR           = &H00200000???
%LUP_FILESERVER          = &H00400000???

'/*
' * Return flags
' */

%RESULT_IS_ALIAS      = &H0001???
'#if(_WIN32_WINNT >= 0x0501)
%RESULT_IS_ADDED      = &H0010???
%RESULT_IS_CHANGED    = &H0020???
%RESULT_IS_DELETED    = &H0040???
'#endif //(_WIN32_WINNT >= 0x0501)


'/*
' * Service Address Registration and Deregistration Data Types.
' */

' WSAESETSERVICEOP enum
%RNRSERVICE_REGISTER   = 0
%RNRSERVICE_DEREGISTER = 1
%RNRSERVICE_DELETE     = 2

'/*
' * Service Installation/Removal Data Types.
' */

' // Size = 20 bytes
TYPE WSANSCLASSINFOA DWORD
   lpszName    AS ASCIIZ PTR   ' LPSTR
   dwNameSpace AS DWORD        ' DWORD
   dwValueType AS DWORD        ' DWORD
   dwValueSize AS DWORD        ' DWORD
   lpValue     AS DWORD        ' LPVOID
END TYPE

' // Size = 20 bytes
TYPE WSANSCLASSINFOW DWORD
   lpszName    AS WSTRINGZ PTR   ' LPWSTR
   dwNameSpace AS DWORD          ' DWORD
   dwValueType AS DWORD          ' DWORD
   dwValueSize AS DWORD          ' DWORD
   lpValue     AS DWORD          ' LPVOID
END TYPE

#IF %DEF(%UNICODE)
   MACRO WSANSCLASSINFO = WSANSCLASSINFOW
#ELSE
   MACRO WSANSCLASSINFO = WSANSCLASSINFOA
#ENDIF

' // Size = 16 bytes
TYPE WSASERVICECLASSINFOA DWORD
   lpServiceClassId     AS GUID PTR             ' LPGUID
   lpszServiceClassName AS ASCIIZ PTR           ' LPSTR
   dwCount              AS DWORD                ' DWORD
   lpClassInfos         AS WSANSCLASSINFO PTR   ' LPWSANSCLASSINFOA
END TYPE

' // Size = 16 bytes
TYPE WSASERVICECLASSINFOW DWORD
   lpServiceClassId     AS GUID PTR             ' LPGUID
   lpszServiceClassName AS WSTRINGZ PTR         ' LPWSTR
   dwCount              AS DWORD                ' DWORD
   lpClassInfos         AS WSANSCLASSINFOW PTR  ' LPWSANSCLASSINFOW
END TYPE

#IF %DEF(%UNICODE)
   MACRO WSASERVICECLASSINFO = WSASERVICECLASSINFOW
#ELSE
   MACRO WSASERVICECLASSINFO = WSASERVICECLASSINFOA
#ENDIF

' // Size = 32 bytes
TYPE WSANAMESPACE_INFOA DWORD
   NSProviderId   AS GUID         ' GUID
   dwNameSpace    AS DWORD        ' DWORD
   fActive        AS LONG         ' BOOL
   dwVersion      AS DWORD        ' DWORD
   lpszIdentifier AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 32 bytes
TYPE WSANAMESPACE_INFOW DWORD
   NSProviderId   AS GUID           ' GUID
   dwNameSpace    AS DWORD          ' DWORD
   fActive        AS LONG           ' BOOL
   dwVersion      AS DWORD          ' DWORD
   lpszIdentifier AS WSTRINGZ PTR   ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO WSANAMESPACE_INFO = WSANAMESPACE_INFOW
#ELSE
   MACRO WSANAMESPACE_INFO = WSANAMESPACE_INFOA
#ENDIF

' // Size = 40 bytes
TYPE WSANAMESPACE_INFOEXA DWORD
   NSProviderId     AS GUID         ' GUID
   dwNameSpace      AS DWORD        ' DWORD
   fActive          AS LONG         ' BOOL
   dwVersion        AS DWORD        ' DWORD
   lpszIdentifier   AS ASCIIZ PTR   ' LPSTR
   ProviderSpecific AS BLOB         ' BLOB
END TYPE

' // Size = 40 bytes
TYPE WSANAMESPACE_INFOEXW DWORD
   NSProviderId     AS GUID           ' GUID
   dwNameSpace      AS DWORD          ' DWORD
   fActive          AS LONG           ' BOOL
   dwVersion        AS DWORD          ' DWORD
   lpszIdentifier   AS WSTRINGZ PTR   ' LPWSTR
   ProviderSpecific AS BLOB           ' BLOB
END TYPE

#IF %DEF(%UNICODE)
   MACRO WSANAMESPACE_INFOEX = WSANAMESPACE_INFOEXW
#ELSE
   MACRO WSANAMESPACE_INFOEX = WSANAMESPACE_INFOEXA
#ENDIF

'#if(_WIN32_WINNT >= 0x0600)

'/* Event flag definitions for WSAPoll(). */

%POLLRDNORM  = &H0100???
%POLLRDBAND  = &H0200???
%POLLIN      = %POLLRDNORM OR %POLLRDBAND
%POLLPRI     = &H0400???

%POLLWRNORM  = &H0010???
%POLLOUT     = %POLLWRNORM
%POLLWRBAND  = &H0020???

%POLLERR     = &H0001???
%POLLHUP     = &H0002???
%POLLNVAL    = &H0004???

' // Size = 8 bytes
TYPE WSAPOLLFD DWORD FILL
   fd      AS DWORD     ' SOCKET
   events  AS INTEGER   ' SHORT
   revents AS INTEGER   ' SHORT
END TYPE

'#endif // (_WIN32_WINNT >= 0x0600)

'/* Socket function prototypes */

'#IF (%INCL_WINSOCK_API_PROTOTYPES) '-------------------------------------------

DECLARE FUNCTION aaccept IMPORT "ws2_32.dll" ALIAS "accept" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF addr AS sockaddr_in _                          ' __out struct sockaddr FAR *addr
 , BYREF addrlen AS LONG _                              ' __in_out int FAR *addrlen
 ) AS DWORD                                             ' SOCKET

DECLARE FUNCTION bind IMPORT "ws2_32.dll" ALIAS "bind" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF addr AS sockaddr_in _                          ' __in const struct sockaddr FAR *addr
 , BYVAL namelen AS LONG _                              ' __in int namelen
 ) AS LONG                                              ' int

DECLARE FUNCTION closesocket IMPORT "ws2_32.dll" ALIAS "closesocket" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 ) AS LONG                                              ' int

DECLARE FUNCTION cconnect IMPORT "ws2_32.dll" ALIAS "connect" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF name AS sockaddr_in _                          ' __in const struct sockaddr FAR *name
 , BYVAL namelen AS LONG _                              ' __in int namelen
 ) AS LONG                                              ' int

DECLARE FUNCTION ioctlsocket IMPORT "ws2_32.dll" ALIAS "ioctlsocket" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYVAL cmd AS LONG _                                  ' __in long cmd
 , BYREF argp AS DWORD _                                ' __in_out u_long FAR *argp
 ) AS LONG                                              ' int

DECLARE FUNCTION getpeername IMPORT "ws2_32.dll" ALIAS "getpeername" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF name AS sockaddr_in _                          ' __out struct sockaddr FAR *name
 , BYREF namelen AS LONG _                              ' __in_out int FAR * namelen
 ) AS LONG                                              ' int

DECLARE FUNCTION getsockname IMPORT "ws2_32.dll" ALIAS "getsockname" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF name AS sockaddr_in  _                         ' __out struct sockaddr FAR *name
 , BYREF namelen AS LONG _                              ' __in_out int FAR * namelen
 ) AS LONG                                              ' int

DECLARE FUNCTION getsockopt IMPORT "ws2_32.dll" ALIAS "getsockopt" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYVAL level AS LONG _                                ' __in int level
 , BYVAL optname AS LONG _                              ' __in int optname
 , BYREF optval AS ANY _                                ' __out char FAR * optval
 , BYREF optlen AS LONG _                               ' __in_out int FAR *optlen
 ) AS LONG                                              ' int

DECLARE FUNCTION htonl IMPORT "ws2_32.dll" ALIAS "htonl" ( _
   BYVAL hostlong AS DWORD _                            ' __in u_long hostlong
 ) AS DWORD                                             ' u_long

DECLARE FUNCTION htons IMPORT "ws2_32.dll" ALIAS "htons" ( _
   BYVAL hostshort AS WORD _                            ' __in u_short hostshort
 ) AS WORD                                              ' u_short

DECLARE FUNCTION inet_addr IMPORT "ws2_32.dll" ALIAS "inet_addr" ( _
   BYREF cp AS ASCIIZ _                                 ' __in const char FAR * cp
 ) AS DWORD                                             ' unsigned long

DECLARE FUNCTION inet_ntoa IMPORT "ws2_32.dll" ALIAS "inet_ntoa" ( _
   BYVAL in_ AS in_addr _                               ' __in struct in_addr in
 ) AS DWORD                                             ' char FAR*

DECLARE FUNCTION listen IMPORT "ws2_32.dll" ALIAS "listen" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYVAL backlog AS LONG _                              ' __in int backlog
 ) AS LONG                                              ' int

DECLARE FUNCTION ntohl IMPORT "ws2_32.dll" ALIAS "ntohl" ( _
   BYVAL netlong AS DWORD _                             ' __in u_long netlong
 ) AS DWORD                                             ' u_long

DECLARE FUNCTION ntohs IMPORT "ws2_32.dll" ALIAS "ntohs" ( _
   BYVAL netshort AS WORD _                             ' __in u_short netshort
 ) AS WORD                                              ' u_short

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION rrecv LIB "ws2_32.dll" ALIAS "recv" ( _
    BYVAL s      AS DWORD, _   ' SOCKET
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG, _
    BYVAL flags  AS LONG _
    ) AS LONG
#ELSE
DECLARE FUNCTION rrecv IMPORT "ws2_32.dll" ALIAS "recv" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF buf AS ANY _                                   ' __out char FAR * buf
 , BYVAL len AS LONG _                                  ' __in int len
 , BYVAL flags AS LONG _                                ' __in int flags
 ) AS LONG                                              ' int
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION recvfrom LIB "ws2_32.dll" ALIAS "recvfrom" ( _
    BYVAL s      AS DWORD, _   ' SOCKET
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG, _
    BYVAL flags  AS LONG, _
    saFrom       AS SOCKADDR, _
    fromlen      AS LONG _
    ) AS LONG
#ELSE
DECLARE FUNCTION recvfrom IMPORT "ws2_32.dll" ALIAS "recvfrom" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF buf AS ANY _                                   ' __out char FAR * buf
 , BYVAL len AS LONG _                                  ' __in int len
 , BYVAL flags AS LONG _                                ' __in int flags
 , BYREF from AS sockaddr_in _                          ' __out struct sockaddr FAR *from
 , BYREF fromlen AS LONG _                              ' __in_out int FAR * fromlen
 ) AS LONG                                              ' int
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION sselect LIB "ws2_32.dll" ALIAS "select" ( _
    BYVAL nfds AS LONG, _
    readfds    AS fd_set, _
    writefds   AS fd_set, _
    exceptfds  AS FD_SET, _
    tymeout    AS timeval _
    ) AS LONG
#ELSE
DECLARE FUNCTION sselect IMPORT "ws2_32.dll" ALIAS "select" ( _
   BYVAL nfds AS LONG _                                 ' __in int nfds
 , BYREF readfds AS fd_setstruc _                       ' __in_out fd_set FAR *readfds
 , BYREF writefds AS fd_setstruc _                      ' __in_out fd_set FAR *writefds
 , BYREF exceptfds AS fd_setstruc _                     ' __in_out fd_set FAR *exceptfds
 , BYREF timeout AS TIMEVAL _                           ' __in const struct timeval FAR *timeout
 ) AS LONG                                              ' int
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ssend LIB "ws2_32.dll" ALIAS "send" ( _
    BYVAL s      AS DWORD, _  ' SOCKET
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG, _
    BYVAL flags  AS LONG _
    ) AS LONG
#ELSE
DECLARE FUNCTION ssend IMPORT "ws2_32.dll" ALIAS "send" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF buf AS ANY _                                   ' __in const char FAR * buf
 , BYVAL len AS LONG _                                  ' __in int len
 , BYVAL flags AS LONG _                                ' __in int flags
 ) AS LONG                                              ' int
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION sendto LIB "ws2_32.dll" ALIAS "sendto" ( _
    BYVAL s      AS DWORD, _
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG, _
    BYVAL flags  AS LONG, _
    to_addr      AS SOCKADDR, _
    BYVAL tolen  AS LONG _
    ) AS LONG
#ELSE
DECLARE FUNCTION sendto IMPORT "ws2_32.dll" ALIAS "sendto" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF buf AS ANY _                                   ' __in const char FAR * buf
 , BYVAL len AS LONG _                                  ' __in int len
 , BYVAL flags AS LONG _                                ' __in int flags
 , BYREF to AS sockaddr_in _                            ' __in const struct sockaddr FAR *to
 , BYVAL tolen AS LONG _                                ' __in int tolen
 ) AS LONG                                              ' int
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION setsockopt LIB "ws2_32.dll" ALIAS "setsockopt" ( _
    BYVAL s       AS DWORD, _   ' SOCKET
    BYVAL level   AS LONG, _
    BYVAL optname AS LONG, _
    BYVAL optval  AS BYTE PTR, _
    BYVAL optlen  AS LONG _
    ) AS LONG
#ELSE
DECLARE FUNCTION setsockopt IMPORT "ws2_32.dll" ALIAS "setsockopt" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYVAL level AS LONG _                                ' __in int level
 , BYVAL optname AS LONG _                              ' __in int optname
 , BYREF optval AS ANY _                                ' __in const char FAR * optval
 , BYVAL optlen AS LONG _                               ' __in int optlen
 ) AS LONG                                              ' int
#ENDIF

DECLARE FUNCTION shutdown IMPORT "ws2_32.dll" ALIAS "shutdown" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYVAL how AS LONG _                                  ' __in int how
 ) AS LONG                                              ' int

DECLARE FUNCTION socket IMPORT "ws2_32.dll" ALIAS "socket" ( _
   BYVAL af AS DWORD _                                  ' __in int af
 , BYVAL type AS LONG _                                 ' __in int type
 , BYVAL protocol AS LONG _                             ' __in int protocol
 ) AS DWORD                                             ' SOCKET

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION gethostbyaddr LIB "ws2_32.dll"  ALIAS "gethostbyaddr" ( _
    BYVAL saAddr    AS BYTE PTR, _
    BYVAL addr_len  AS LONG, _
    BYVAL addr_type AS LONG _
    ) AS DWORD   ' hostent PTR
#ELSE
DECLARE FUNCTION gethostbyaddr IMPORT "ws2_32.dll"  ALIAS "gethostbyaddr" ( _
   BYREF addr AS ANY _                                  ' __in const char FAR * addr
 , BYVAL len AS LONG _                                  ' __in int len
 , BYVAL type AS LONG _                                 ' __in int type
 ) AS DWORD                                             ' struct hostent FAR *
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION gethostbyname LIB "ws2_32.dll" ALIAS "gethostbyname" ( _
    hname AS ASCIIZ _
    ) AS DWORD   ' hostent PTR
#ELSE
DECLARE FUNCTION gethostbyname IMPORT "ws2_32.dll" ALIAS "gethostbyname" ( _
   BYREF name AS ASCIIZ _                               ' __in const char FAR * name
 ) AS LONG                                              ' struct hostent FAR *
#ENDIF

DECLARE FUNCTION gethostname IMPORT "ws2_32.dll" ALIAS "gethostname" ( _
   BYREF name AS ASCIIZ _                               ' __out char FAR * name
 , BYVAL namelen AS LONG _                              ' __in int namelen
 ) AS LONG                                              ' int

DECLARE FUNCTION getservbyport IMPORT "ws2_32.dll" ALIAS "getservbyport" ( _
   BYVAL port AS LONG _                                 ' __in int port
 , BYREF proto AS ASCIIZ _                              ' __in const char FAR * proto
 ) AS DWORD                                             ' struct servent FAR *

DECLARE FUNCTION getservbyname IMPORT "ws2_32.dll" ALIAS "getservbyname" ( _
   BYREF name AS ASCIIZ _                               ' __in const char FAR * name
 , BYREF proto AS ASCIIZ _                              ' __in const char FAR * proto
 ) AS DWORD                                             ' struct servent FAR *

DECLARE FUNCTION getprotobynumber IMPORT "ws2_32.dll" ALIAS "getprotobynumber" ( _
   BYVAL proto AS LONG _                                ' __in int proto
 ) AS DWORD                                             ' struct protoent FAR *

DECLARE FUNCTION getprotobyname IMPORT "ws2_32.dll" ALIAS "getprotobyname" ( _
   BYREF name AS ASCIIZ _                               ' __in const char FAR * name
 ) AS DWORD                                             ' struct protoent FAR *

DECLARE FUNCTION WSAStartup IMPORT "ws2_32.dll" ALIAS "WSAStartup" ( _
   BYVAL wVersionRequired AS WORD _                     ' __in WORD wVersionRequired
 , BYREF lpWSAData AS WSADATA _                         ' __out LPWSADATA lpWSAData
 ) AS LONG                                              ' int

DECLARE FUNCTION WSACleanup IMPORT "ws2_32.dll" ALIAS "WSACleanup" ( _
 ) AS LONG                                              ' int

DECLARE SUB WSASetLastError IMPORT "ws2_32.dll" ALIAS "WSASetLastError" ( _
   BYVAL iError AS LONG _                               ' __in int iError
 )                                                      ' void

DECLARE FUNCTION WSAGetLastError IMPORT "ws2_32.dll" ALIAS "WSAGetLastError" ( _
 ) AS LONG                                              ' int

DECLARE FUNCTION WSAIsBlocking IMPORT "ws2_32.dll" ALIAS "WSAIsBlocking" ( _
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WSAUnhookBlockingHook IMPORT "ws2_32.dll" ALIAS "WSAUnhookBlockingHook" ( _
 ) AS LONG                                              ' int

DECLARE FUNCTION WSASetBlockingHook IMPORT "ws2_32.dll" ALIAS "WSASetBlockingHook" ( _
   BYVAL lpBlockFunc AS DWORD _                         ' __in FARPROC lpBlockFunc
 ) AS DWORD                                             ' FARPROC

DECLARE FUNCTION WSACancelBlockingCall IMPORT "ws2_32.dll" ALIAS "WSACancelBlockingCall" ( _
 ) AS LONG                                              ' int

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WSAAsyncGetServByName LIB "ws2_32.dll" _
    ALIAS "WSAAsyncGetServByName" ( _
    BYVAL hWnd   AS DWORD, _   ' HWND
    BYVAL wMsg   AS DWORD, _
    serv_name    AS ASCIIZ, _
    proto        AS ASCIIZ, _
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG _
    ) AS DWORD   ' HANDLE
#ELSE
DECLARE FUNCTION WSAAsyncGetServByName IMPORT "ws2_32.dll" ALIAS "WSAAsyncGetServByName" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL wMsg AS DWORD _                                ' __in u_int wMsg
 , BYREF name AS ASCIIZ _                               ' __in const char FAR * name
 , BYREF proto AS ASCIIZ _                              ' __in const char FAR * proto
 , BYREF buf AS ASCIIZ _                                ' __out char FAR * buf
 , BYVAL buflen AS LONG _                               ' __in int buflen
 ) AS DWORD                                             ' HANDLE
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WSAAsyncGetServByPort LIB "ws2_32.dll" _
    ALIAS "WSAAsyncGetServByPort" ( _
    BYVAL hWnd   AS DWORD, _  ' HWND
    BYVAL wMsg   AS DWORD, _
    BYVAL lPort  AS LONG, _
    proto        AS ASCIIZ, _
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG _
    ) AS DWORD   ' HANDLE
#ELSE
DECLARE FUNCTION WSAAsyncGetServByPort IMPORT "ws2_32.dll" ALIAS "WSAAsyncGetServByPort" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL wMsg AS DWORD _                                ' __in u_int wMsg
 , BYVAL port AS LONG _                                 ' __in int port
 , BYREF proto AS ASCIIZ _                              ' __in const char FAR * proto
 , BYREF buf AS ASCIIZ _                                ' __out char FAR * buf
 , BYVAL buflen AS LONG _                               ' __in int buflen
 ) AS DWORD                                             ' HANDLE
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WSAAsyncGetProtoByName LIB "ws2_32.dll" _
    ALIAS "WSAAsyncGetProtoByName" ( _
    BYVAL hWnd   AS DWORD, _  ' HWND
    BYVAL wMsg   AS DWORD, _
    proto_name   AS ASCIIZ, _
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG _
    ) AS DWORD  ' HANDLE
#ELSE
DECLARE FUNCTION WSAAsyncGetProtoByName IMPORT "ws2_32.dll" ALIAS "WSAAsyncGetProtoByName" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL wMsg AS DWORD _                                ' __in u_int wMsg
 , BYREF name AS ASCIIZ _                               ' __in const char FAR * name
 , BYREF buf AS ASCIIZ _                                ' __out char FAR * buf
 , BYVAL buflen AS LONG _                               ' __in int buflen
 ) AS DWORD                                             ' HANDLE
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WSAAsyncGetProtoByNumber LIB "ws2_32.dll" _
    ALIAS "WSAAsyncGetProtoByNumber" ( _
    BYVAL hWnd   AS DWORD, _   ' HWND
    BYVAL wMsg   AS DWORD, _
    BYVAL number AS LONG, _
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG _
    ) AS DWORD  ' HANDLE
#ELSE
DECLARE FUNCTION WSAAsyncGetProtoByNumber IMPORT "ws2_32.dll" ALIAS "WSAAsyncGetProtoByNumber" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL wMsg AS DWORD _                                ' __in u_int wMsg
 , BYVAL name AS LONG _                                 ' __in int number
 , BYREF buf AS ASCIIZ _                                ' __out char FAR * buf
 , BYVAL buflen AS LONG _                               ' __in int buflen
 ) AS DWORD                                             ' HANDLE
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WSAAsyncGetHostByName LIB "ws2_32.dll" _
    ALIAS "WSAAsyncGetHostByName" ( _
    BYVAL hWnd   AS DWORD, _
    BYVAL wMsg   AS DWORD, _
    host_name    AS ASCIIZ, _
    BYVAL buf    AS BYTE PTR, _
    BYVAL buflen AS LONG _
    ) AS DWORD  ' HANDLE
#ELSE
DECLARE FUNCTION WSAAsyncGetHostByName IMPORT "ws2_32.dll" ALIAS "WSAAsyncGetHostByName" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL wMsg AS DWORD _                                ' __in u_int wMsg
 , BYREF name AS ASCIIZ _                               ' __in const char FAR * name
 , BYREF buf AS ASCIIZ _                                ' __out char FAR * buf
 , BYVAL buflen AS LONG _                               ' __in int buflen
 ) AS DWORD                                             ' HANDLE
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WSAAsyncGetHostByAddr LIB "ws2_32.dll" _
    ALIAS "WSAAsyncGetHostByAddr" ( _
    BYVAL hWnd      AS DWORD, _   ' HWND
    BYVAL wMsg      AS DWORD, _
    BYVAL address   AS BYTE PTR, _
    BYVAL addr_len  AS LONG, _
    BYVAL addr_type AS LONG, _
    BYVAL buf       AS BYTE PTR, _
    BYVAL buflen    AS LONG _
    ) AS DWORD  ' HANDLE
#ELSE
DECLARE FUNCTION WSAAsyncGetHostByAddr IMPORT "ws2_32.dll" ALIAS "WSAAsyncGetHostByAddr" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL wMsg AS DWORD _                                ' __in u_int wMsg
 , BYREF addr AS ASCIIZ _                               ' __in const char FAR * addr
 , BYVAL len AS LONG _                                  ' __in int len
 , BYVAL type AS LONG _                                 ' __in int type
 , BYREF buf AS ASCIIZ _                                ' __out char FAR * buf
 , BYVAL buflen AS LONG _                               ' __in int buflen
 ) AS DWORD                                             ' HANDLE
#ENDIF

DECLARE FUNCTION WSACancelAsyncRequest IMPORT "ws2_32.dll" ALIAS "WSACancelAsyncRequest" ( _
   BYVAL hAsyncTaskHandle AS DWORD _                    ' __in HANDLE hAsyncTaskHandle
 ) AS LONG                                              ' int

DECLARE FUNCTION WSAAsyncSelect IMPORT "ws2_32.dll" ALIAS "WSAAsyncSelect" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL wMsg AS DWORD _                                ' __in u_int wMsg
 , BYVAL lEvent AS LONG _                               ' __in long lEvent
 ) AS LONG                                              ' int

'/* WinSock 2 API new function prototypes */

DECLARE FUNCTION WSAAccept IMPORT "ws2_32.dll" ALIAS "WSAAccept" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF addr AS SOCKADDR _                             ' __out struct sockaddr FAR * addr
 , BYREF addrlen AS LONG _                              ' __in_out LPINT addrlen
 , BYVAL lpfnCondition AS DWORD _                       ' __in LPCONDITIONPROC lpfnCondition
 , BYVAL dwCallbackData AS DWORD _                      ' __in DWORD_PTR dwCallbackData
 ) AS DWORD                                             ' SOCKET

DECLARE FUNCTION WSACloseEvent IMPORT "ws2_32.dll" ALIAS "WSACloseEvent" ( _
   BYVAL hEvent AS DWORD _                              ' __in WSAEVENT hEvent
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WSAConnect IMPORT "ws2_32.dll" ALIAS "WSAConnect" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF name AS SOCKADDR _                             ' __in const struct sockaddr FAR * name
 , BYVAL namelen AS LONG _                              ' __in int namelen
 , BYREF lpCallerData AS WSABUF _                       ' __in LPWSABUF lpCallerData
 , BYREF lpCalleeData AS WSABUF _                       ' __out LPWSABUF lpCalleeData
 , BYREF lpSQOS AS QOS _                                ' __in LPQOS lpSQOS
 , BYREF lpGQOS AS QOS _                                ' __in LPQOS lpGQOS
 ) AS LONG                                              ' int

DECLARE FUNCTION WSAConnectByNameW IMPORT "ws2_32.dll" ALIAS "WSAConnectByNameW" ( _
   BYVAL s AS DWORD  _                                  ' __in SOCKET s
 , BYREF nodename AS WSTRINGZ _                         ' __in_z LPWSTR nodename
 , BYREF servicename AS WSTRINGZ _                      ' __in_z LPWSTR servicename
 , BYREF LocalAddressLength AS DWORD _                  ' __in_out LPDWORD LocalAddressLength
 , BYREF LocalAddress AS SOCKADDR _                     ' __out LPSOCKADDR LocalAddress
 , BYREF RemoteAddressLength AS DWORD _                 ' __in_out LPDWORD RemoteAddressLength
 , BYREF RemoteAddress AS SOCKADDR _                    ' __out LPSOCKADDR RemoteAddress
 , BYREF timeout AS TIMEVAL _                           ' __in const struct timeval * timeout
 , BYREF Reserved AS WSAOVERLAPPED _                    ' __in_opt LPWSAOVERLAPPED Reserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WSAConnectByNameA IMPORT "ws2_32.dll" ALIAS "WSAConnectByNameA" ( _
   BYVAL s AS DWORD  _                                  ' __in SOCKET s
 , BYREF nodename AS ASCIIZ _                           ' __in_z LPCSTR nodename
 , BYREF servicename AS ASCIIZ _                        ' __in_z LPCSTR servicename
 , BYREF LocalAddressLength AS DWORD _                  ' __in_out LPDWORD LocalAddressLength
 , BYREF LocalAddress AS SOCKADDR _                     ' __out LPSOCKADDR LocalAddress
 , BYREF RemoteAddressLength AS DWORD _                 ' __in_out LPDWORD RemoteAddressLength
 , BYREF RemoteAddress AS SOCKADDR _                    ' __out LPSOCKADDR RemoteAddress
 , BYREF timeout AS TIMEVAL _                           ' __in const struct timeval * timeout
 , BYREF Reserved AS WSAOVERLAPPED _                    ' __in_opt LPWSAOVERLAPPED Reserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO WSAConnectByName = WSAConnectByNameW
#ELSE
   MACRO WSAConnectByName = WSAConnectByNameA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WSAConnectByList LIB "ws2_32.dll" _
    ALIAS "WSAConnectByList" ( _
    BYVAL s             AS DWORD, _  ' SOCKET
    BYVAL SocketAddress AS SOCKET_ADDRESS_LIST PTR, _
    LocalAddressLength  AS DWORD, _
    LocalAddress        AS SOCKADDR, _
    RemoteAddressLength AS DWORD, _
    RemoteAddress       AS SOCKADDR, _
    TIMEOUT             AS timeval, _
    Reserved            AS WSAOVERLAPPED _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION WSAConnectByList IMPORT "ws2_32.dll" ALIAS "WSAConnectByList" ( _
   BYVAL s AS DWORD  _                                  ' __in SOCKET s
 , BYREF SocketAddress AS SOCKET_ADDRESS _              ' __in PSOCKET_ADDRESS_LIST SocketAddress
 , BYREF LocalAddressLength AS DWORD _                  ' __in_out LPDWORD LocalAddressLength
 , BYREF LocalAddress AS SOCKADDR _                     ' __out LPSOCKADDR LocalAddress
 , BYREF RemoteAddressLength AS DWORD _                 ' __in_out LPDWORD RemoteAddressLength
 , BYREF RemoteAddress AS SOCKADDR _                    ' __out LPSOCKADDR RemoteAddress
 , BYREF timeout AS TIMEVAL _                           ' __in const struct timeval * timeout
 , BYREF Reserved AS WSAOVERLAPPED _                    ' __in_opt LPWSAOVERLAPPED Reserved
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION WSACreateEvent IMPORT "ws2_32.dll" ALIAS "WSACreateEvent" ( _
 ) AS DWORD                                             ' WSAEVENT

DECLARE FUNCTION WSADuplicateSocketA IMPORT "ws2_32.dll" ALIAS "WSADuplicateSocketA" ( _
   BYVAL s AS DWORD  _                                  ' __in SOCKET s
 , BYVAL dwProcessId AS DWORD _                         ' __in DWORD dwProcessId
 , BYREF lpProtocolInfo AS WSAPROTOCOL_INFOA _          ' __out LPWSAPROTOCOL_INFOA lpProtocolInfo
 ) AS LONG                                              ' int

DECLARE FUNCTION WSADuplicateSocketW IMPORT "ws2_32.dll" ALIAS "WSADuplicateSocketW" ( _
   BYVAL s AS DWORD  _                                  ' __in SOCKET s
 , BYVAL dwProcessId AS DWORD _                         ' __in DWORD dwProcessId
 , BYREF lpProtocolInfo AS WSAPROTOCOL_INFOW _          ' __out LPWSAPROTOCOL_INFOW lpProtocolInfo
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO WSADuplicateSocket = WSADuplicateSocketW
#ELSE
   MACRO WSADuplicateSocket = WSADuplicateSocketA
#ENDIF

DECLARE FUNCTION WSAEnumNetworkEvents IMPORT "ws2_32.dll" ALIAS "WSAEnumNetworkEvents" ( _
   BYVAL s AS DWORD  _                                  ' __in SOCKET s
 , BYVAL hEventObject AS DWORD _                        ' __in WSAEVENT hEventObject
 , BYREF lpNetworkEvents AS WSANETWORKEVENTS _          ' __out LPWSANETWORKEVENTS lpNetworkEvents
 ) AS LONG                                              ' int

DECLARE FUNCTION WSAEnumProtocolsA IMPORT "ws2_32.dll" ALIAS "WSAEnumProtocolsA" ( _
   BYREF lpiProtocols AS LONG _                         ' __in LPINT lpiProtocols
 , BYREF lpProtocolBuffer AS WSAPROTOCOL_INFOA _        ' __out LPWSAPROTOCOL_INFOA lpProtocolBuffer
 , BYREF lpdwBufferLength AS DWORD _                    ' __in_out LPDWORD lpdwBufferLength
 ) AS LONG                                              ' int

DECLARE FUNCTION WSAEnumProtocolsW IMPORT "ws2_32.dll" ALIAS "WSAEnumProtocolsW" ( _
   BYREF lpiProtocols AS LONG _                         ' __in LPINT lpiProtocols
 , BYREF lpProtocolBuffer AS WSAPROTOCOL_INFOW _        ' __out LPWSAPROTOCOL_INFOW lpProtocolBuffer
 , BYREF lpdwBufferLength AS DWORD _                    ' __in_out LPDWORD lpdwBufferLength
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO WSAEnumProtocols = WSAEnumProtocolsW
#ELSE
   MACRO WSAEnumProtocols = WSAEnumProtocolsA
#ENDIF

DECLARE FUNCTION WSAEventSelect IMPORT "ws2_32.dll" ALIAS "WSAEventSelect" ( _
   BYVAL s AS DWORD  _                                  ' __in SOCKET s
 , BYVAL hEventObject AS DWORD _                        ' __in WSAEVENT hEventObject
 , BYVAL lNetworkEvents AS LONG _                       ' __in long lNetworkEvents
 ) AS LONG                                              ' int

DECLARE FUNCTION WSAGetOverlappedResult IMPORT "ws2_32.dll" ALIAS "WSAGetOverlappedResult" ( _
   BYVAL s AS DWORD  _                                  ' __in SOCKET s
 , BYREF lpOverlapped AS WSAOVERLAPPED _                ' __in LPWSAOVERLAPPED lpOverlapped
 , BYREF lpcbTransfer AS DWORD _                        ' __out LPDWORD lpcbTransfer
 , BYVAL fWait AS LONG _                                ' __in BOOL fWait
 , BYREF lpdwFlags AS DWORD _                           ' __out LPDWORD lpdwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WSAGetQOSByName IMPORT "ws2_32.dll" ALIAS "WSAGetQOSByName" ( _
   BYVAL s AS DWORD  _                                  ' __in SOCKET s
 , BYREF lpQOSName AS WSABUF _                          ' __in LPWSABUF lpQOSName
 , BYREF lpQOS AS QOS _                                 ' __out LPQOS lpQOS
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WSAHtonl IMPORT "ws2_32.dll" ALIAS "WSAHtonl" ( _
   BYVAL s AS DWORD  _                                  ' __in SOCKET s
 , BYVAL hostlong AS DWORD _                            ' __in u_long hostlong
 , BYREF lpnetlong AS DWORD _                           ' __out u_long FAR * lpnetlong
 ) AS LONG                                              ' int

DECLARE FUNCTION WSAHtons IMPORT "ws2_32.dll" ALIAS "WSAHtons" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYVAL hostshort AS WORD _                            ' __in u_short hostshort
 , BYREF lpnetshort AS WORD _                           ' __out u_short FAR * lpnetshort
 ) AS LONG                                              ' int

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WSAIoctl LIB "ws2_32.dll" ALIAS "WSAIoctl" ( _
    BYVAL s                   AS DWORD, _  ' SOCKET
    BYVAL dwIoControlCode     AS DWORD, _
    lpvInBuffer               AS ANY, _    ' LPVOID
    BYVAL cbInBuffer          AS DWORD, _
    lpvOutBuffer              AS ANY, _    ' LPVOID
    BYVAL cbOutBuffer         AS DWORD, _
    lpcbBytesReturned         AS DWORD, _
    lpOverlapped              AS WSAOVERLAPPED, _
    BYVAL lpCompletionRoutine AS DWORD _   ' LPWSAOVERLAPPED_COMPLETION_ROUTINE
    ) AS LONG
#ELSE
DECLARE FUNCTION WSAIoctl IMPORT "ws2_32.dll" ALIAS "WSAIoctl" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYVAL dwIoControlCode AS DWORD _                     ' __in DWORD dwIoControlCode
 , BYVAL lpvInBuffer AS DWORD _                         ' __in LPVOID lpvInBuffer
 , BYVAL cbInBuffer AS DWORD _                          ' __in DWORD cbInBuffer
 , BYVAL lpvOutBuffer AS DWORD _                        ' __out LPVOID lpvOutBuffer
 , BYVAL cbOutBuffer AS DWORD _                         ' __in DWORD cbOutBuffer
 , BYREF lpcbBytesReturned AS DWORD _                   ' __out LPDWORD lpcbBytesReturned
 , BYREF lpOverlapped AS WSAOVERLAPPED _                ' __in LPWSAOVERLAPPED lpOverlapped
 , BYVAL lpCompletionRoutine AS DWORD _                 ' __in LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
 ) AS LONG                                              ' int
#ENDIF

DECLARE FUNCTION WSAJoinLeaf IMPORT "ws2_32.dll" ALIAS "WSAJoinLeaf" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF name AS SOCKADDR _                             ' __in const struct sockaddr FAR * name
 , BYVAL namelen AS LONG _                              ' __in int namelen
 , BYREF lpCallerData AS WSABUF _                       ' __in LPWSABUF lpCallerData
 , BYREF lpCalleeData AS WSABUF _                       ' __out LPWSABUF lpCalleeData
 , BYREF lpSQOS AS QOS _                                ' __in LPQOS lpSQOS
 , BYREF lpGQOS AS QOS _                                ' __in LPQOS lpGQOS
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' SOCKET

DECLARE FUNCTION WSANtohl IMPORT "ws2_32.dll" ALIAS "WSANtohl" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYVAL netlong AS DWORD _                             ' __in u_long netlong
 , BYREF lphostlong AS DWORD _                          ' __out u_long FAR * lphostlong
 ) AS LONG                                              ' int

DECLARE FUNCTION WSANtohs IMPORT "ws2_32.dll" ALIAS "WSANtohs" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYVAL netshort AS WORD _                             ' __in u_short netshort
 , BYREF lphostshort AS WORD _                          ' __out u_short FAR * lphostshort
 ) AS LONG                                              ' int

DECLARE FUNCTION WSARecv IMPORT "ws2_32.dll" ALIAS "WSARecv" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF lpBuffers AS WSABUF _                          ' __in_out LPWSABUF lpBuffers
 , BYVAL dwBufferCount AS DWORD _                       ' __in DWORD dwBufferCount
 , BYREF lpNumberOfBytesRecvd AS DWORD _                ' __out LPDWORD lpNumberOfBytesRecvd
 , BYREF lpFlags AS DWORD _                             ' __in_out LPDWORD lpFlags
 , BYREF lpOverlapped AS WSAOVERLAPPED _                ' __in LPWSAOVERLAPPED lpOverlapped
 , BYVAL lpCompletionRoutine AS DWORD _                 ' __in LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
 ) AS LONG                                              ' int

DECLARE FUNCTION WSARecvDisconnect IMPORT "ws2_32.dll" ALIAS "WSARecvDisconnect" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF lpInboundDisconnectData AS WSABUF _            ' __out LPWSABUF lpInboundDisconnectData
 ) AS LONG                                              ' int

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WSARecvFrom LIB "ws2_32.dll" ALIAS "WSARecvFrom" ( _
    BYVAL s                   AS DWORD, _  ' SOCKET
    BYVAL lpBuffers           AS WSABUF PTR, _
    BYVAL dwBufferCount       AS DWORD, _
    lpNumberOfBytesRecvd      AS DWORD, _
    lpFlags                   AS DWORD, _
    lpFrom                    AS SOCKADDR, _
    lpFromlen                 AS LONG, _
    lpOverlapped              AS WSAOVERLAPPED, _
    BYVAL lpCompletionRoutine AS DWORD _   ' LPWSAOVERLAPPED_COMPLETION_ROUTINE
    ) AS LONG
#ELSE
DECLARE FUNCTION WSARecvFrom IMPORT "ws2_32.dll" ALIAS "WSARecvFrom" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF lpBuffers AS WSABUF _                          ' __in_out LPWSABUF lpBuffers
 , BYVAL dwBufferCount AS DWORD _                       ' __in DWORD dwBufferCount
 , BYREF lpNumberOfBytesRecvd AS DWORD _                ' __out LPDWORD lpNumberOfBytesRecvd
 , BYREF lpFlags AS DWORD _                             ' __in_out LPDWORD lpFlags
 , BYREF lpFrom AS SOCKADDR _                           ' __out struct sockaddr FAR * lpFrom
 , BYREF lpFromlen AS LONG _                            ' __in_out LPINT lpFromlen
 , BYREF lpOverlapped AS WSAOVERLAPPED _                ' __in LPWSAOVERLAPPED lpOverlapped
 , BYVAL lpCompletionRoutine AS DWORD _                 ' __in LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
 ) AS LONG                                              ' int
#ENDIF

DECLARE FUNCTION WSAResetEvent IMPORT "ws2_32.dll" ALIAS "WSAResetEvent" ( _
   BYVAL hEvent AS DWORD _                              ' __in WSAEVENT hEvent
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WSASend IMPORT "ws2_32.dll" ALIAS "WSASend" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF lpBuffers AS WSABUF _                          ' __in LPWSABUF lpBuffers
 , BYVAL dwBufferCount AS DWORD _                       ' __in DWORD dwBufferCount
 , BYREF lpNumberOfBytesSent AS DWORD _                 ' __out LPDWORD lpNumberOfBytesSent
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF lpOverlapped AS WSAOVERLAPPED _                ' __in LPWSAOVERLAPPED lpOverlapped
 , BYVAL lpCompletionRoutine AS DWORD _                 ' __in LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
 ) AS LONG                                              ' int

DECLARE FUNCTION WSASendMsg IMPORT "ws2_32.dll" ALIAS "WSASendMsg" ( _
   BYVAL s AS DWORD  _                                  ' __in SOCKET s
 , BYREF lpMsg AS WSAMSG _                              ' __in LPWSAMSG lpMsg
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF lpNumberOfBytesSent AS DWORD _                 ' __out_opt LPDWORD lpNumberOfBytesSent
 , BYREF lpOverlapped AS WSAOVERLAPPED _                ' __in_opt LPWSAOVERLAPPED lpOverlapped
 , BYVAL lpCompletionRoutine AS DWORD _                 ' __in_opt LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
 ) AS LONG                                              ' int

DECLARE FUNCTION WSASendDisconnect IMPORT "ws2_32.dll" ALIAS "WSASendDisconnect" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF lpOutboundDisconnectData AS WSABUF _           ' __in LPWSABUF lpOutboundDisconnectData
 ) AS LONG                                              ' int

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WSASendTo LIB "ws2_32.dll" ALIAS "WSASendTo" ( _
    BYVAL s                   AS DWORD, _  ' SOCKET
    BYVAL lpBuffers           AS WSABUF PTR, _
    BYVAL dwBufferCount       AS DWORD, _
    lpNumberOfBytesSent       AS DWORD, _
    BYVAL dwFlags             AS DWORD, _
    lpTo                      AS SOCKADDR, _
    BYVAL iTolen              AS LONG, _
    lpOverlapped              AS WSAOVERLAPPED, _
    BYVAL lpCompletionRoutine AS DWORD _   ' LPWSAOVERLAPPED_COMPLETION_ROUTINE
    ) AS LONG
#ELSE
DECLARE FUNCTION WSASendTo IMPORT "ws2_32.dll" ALIAS "WSASendTo" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF lpBuffers AS WSABUF _                          ' __in LPWSABUF lpBuffers
 , BYVAL dwBufferCount AS DWORD _                       ' __in DWORD dwBufferCount
 , BYREF lpNumberOfBytesSent AS DWORD _                 ' __out LPDWORD lpNumberOfBytesSent
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF lpTo AS SOCKADDR _                             ' __in const struct sockaddr FAR * lpTo
 , BYVAL iTolen AS LONG _                               ' __in int iTolen
 , BYREF lpOverlapped AS WSAOVERLAPPED _                ' __in LPWSAOVERLAPPED lpOverlapped
 , BYVAL lpCompletionRoutine AS DWORD _                 ' __in LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
 ) AS LONG                                              ' int
#ENDIF

DECLARE FUNCTION WSASetEvent IMPORT "ws2_32.dll" ALIAS "WSASetEvent" ( _
   BYVAL hEvent AS DWORD _                              ' __in WSAEVENT hEvent
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WSASocketA IMPORT "ws2_32.dll" ALIAS "WSASocketA" ( _
   BYVAL af AS LONG _                                   ' __in int af
 , BYVAL type AS LONG _                                 ' __in int type
 , BYVAL protocol AS LONG _                             ' __in int protocol
 , BYREF lpProtocolInfo AS WSAPROTOCOL_INFOA _          ' __in LPWSAPROTOCOL_INFOA lpProtocolInfo
 , BYVAL g AS DWORD _                                   ' __in GROUP g
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' SOCKET

DECLARE FUNCTION WSASocketW IMPORT "ws2_32.dll" ALIAS "WSASocketW" ( _
   BYVAL af AS LONG _                                   ' __in int af
 , BYVAL type AS LONG _                                 ' __in int type
 , BYVAL protocol AS LONG _                             ' __in int protocol
 , BYREF lpProtocolInfo AS WSAPROTOCOL_INFOW _          ' __in LPWSAPROTOCOL_INFOW lpProtocolInfo
 , BYVAL g AS DWORD _                                   ' __in GROUP g
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' SOCKET

#IF %DEF(%UNICODE)
   MACRO WSASocket = WSASocketW
#ELSE
   MACRO WSASocket = WSASocketA
#ENDIF

DECLARE FUNCTION WSAWaitForMultipleEvents IMPORT "ws2_32.dll" ALIAS "WSAWaitForMultipleEvents" ( _
   BYVAL cEvents AS DWORD _                             ' __in DWORD cEvents
 , BYVAL lphEvents AS DWORD PTR _                       ' __in const WSAEVENT FAR * lphEvents
 , BYVAL fWaitAll AS LONG _                             ' __in BOOL fWaitAll
 , BYVAL dwTimeout AS DWORD _                           ' __in DWORD dwTimeout
 , BYVAL fAlertable AS LONG _                           ' __in BOOL fAlertable
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION WSAAddressToStringA IMPORT "ws2_32.dll" ALIAS "WSAAddressToStringA" ( _
   BYREF lpsaAddress AS SOCKADDR _                      ' __in     LPSOCKADDR          lpsaAddress
 , BYVAL dwAddressLength AS DWORD _                     ' __in     DWORD               dwAddressLength
 , BYREF lpProtocolInfo AS WSAPROTOCOL_INFOA _          ' __in     LPWSAPROTOCOL_INFOA lpProtocolInfo
 , BYREF lpszAddressString AS ASCIIZ _                  ' __in_out LPSTR               lpszAddressString
 , BYREF lpdwAddressStringLength AS DWORD _             ' __in_out LPDWORD             lpdwAddressStringLength
 ) AS LONG                                              ' int

DECLARE FUNCTION WSAAddressToStringW IMPORT "ws2_32.dll" ALIAS "WSAAddressToStringW" ( _
   BYREF lpsaAddress AS SOCKADDR _                      ' __in     LPSOCKADDR          lpsaAddress
 , BYVAL dwAddressLength AS DWORD _                     ' __in     DWORD               dwAddressLength
 , BYREF lpProtocolInfo AS WSAPROTOCOL_INFOW _          ' __in     LPWSAPROTOCOL_INFOW lpProtocolInfo
 , BYREF lpszAddressString AS WSTRINGZ _                ' __in_out LPWSTR              lpszAddressString
 , BYREF lpdwAddressStringLength AS DWORD _             ' __in_out LPDWORD             lpdwAddressStringLength
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO WSAAddressToString = WSAAddressToStringW
#ELSE
   MACRO WSAAddressToString = WSAAddressToStringA
#ENDIF

DECLARE FUNCTION WSAStringToAddressA IMPORT "ws2_32.dll" ALIAS "WSAStringToAddressA" ( _
   BYREF AddressString AS ASCIIZ _                      ' __in     LPSTR               AddressString
 , BYVAL AddressFamily AS LONG _                        ' __in     INT                 AddressFamily
 , BYREF lpProtocolInfo AS WSAPROTOCOL_INFOA _          ' __in     LPWSAPROTOCOL_INFOA lpProtocolInfo
 , BYREF lpAddress AS SOCKADDR _                        ' __out    LPSOCKADDR          lpAddress
 , BYREF lpAddressLength AS LONG _                      ' __in_out LPINT               lpAddressLength
 ) AS LONG                                              ' int

DECLARE FUNCTION WSAStringToAddressW IMPORT "ws2_32.dll" ALIAS "WSAStringToAddressW" ( _
   BYREF AddressString AS WSTRINGZ _                    ' __in     LPWSTR              AddressString
 , BYVAL AddressFamily AS LONG _                        ' __in     INT                 AddressFamily
 , BYREF lpProtocolInfo AS WSAPROTOCOL_INFOW _          ' __in     LPWSAPROTOCOL_INFOW lpProtocolInfo
 , BYREF lpAddress AS SOCKADDR _                        ' __out    LPSOCKADDR          lpAddress
 , BYREF lpAddressLength AS LONG _                      ' __in_out LPINT               lpAddressLength
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO WSAStringToAddress = WSAStringToAddressW
#ELSE
   MACRO WSAStringToAddress = WSAStringToAddressA
#ENDIF

'/* Registration and Name Resolution API functions */

DECLARE FUNCTION WSALookupServiceBeginA IMPORT "ws2_32.dll" ALIAS "WSALookupServiceBeginA" ( _
   BYREF lpqsRestrictions AS WSAQUERYSETA _             ' __in  LPWSAQUERYSETA lpqsRestrictions
 , BYVAL dwControlFlags AS DWORD _                      ' __in  DWORD          dwControlFlags
 , BYREF lphLookup AS DWORD _                           ' __out LPHANDLE       lphLookup
 ) AS LONG                                              ' int

DECLARE FUNCTION WSALookupServiceBeginW IMPORT "ws2_32.dll" ALIAS "WSALookupServiceBeginW" ( _
   BYREF lpqsRestrictions AS WSAQUERYSETW _             ' __in  LPWSAQUERYSETW lpqsRestrictions
 , BYVAL dwControlFlags AS DWORD _                      ' __in  DWORD          dwControlFlags
 , BYREF lphLookup AS DWORD _                           ' __out LPHANDLE       lphLookup
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO WSALookupServiceBegin = WSALookupServiceBeginW
#ELSE
   MACRO WSALookupServiceBegin = WSALookupServiceBeginA
#ENDIF

DECLARE FUNCTION WSALookupServiceNextA IMPORT "ws2_32.dll" ALIAS "WSALookupServiceNextA" ( _
   BYVAL hLookup AS DWORD _                             ' __in     HANDLE           hLookup
 , BYVAL dwControlFlags AS DWORD _                      ' __in     DWORD            dwControlFlags
 , BYREF lpdwBufferLength AS DWORD _                    ' __in_out LPDWORD          lpdwBufferLength
 , BYREF lpqsResults AS WSAQUERYSETA _                  ' __out    LPWSAQUERYSETA   lpqsResults
 ) AS LONG                                              ' int

DECLARE FUNCTION WSALookupServiceNextW IMPORT "ws2_32.dll" ALIAS "WSALookupServiceNextW" ( _
   BYVAL hLookup AS DWORD _                             ' __in     HANDLE           hLookup
 , BYVAL dwControlFlags AS DWORD _                      ' __in     DWORD            dwControlFlags
 , BYREF lpdwBufferLength AS DWORD _                    ' __in_out LPDWORD          lpdwBufferLength
 , BYREF lpqsResults AS WSAQUERYSETW _                  ' __out    LPWSAQUERYSETW   lpqsResults
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO WSALookupServiceNext = WSALookupServiceNextW
#ELSE
   MACRO WSALookupServiceNext = WSALookupServiceNextA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WSANSPIoctl LIB "ws2_32.dll" ALIAS "WSANSPIoctl" ( _
    BYVAL hLookup       AS DWORD, _  ' HANDLE
    BYVAL dwControlCode AS DWORD, _
    lpvInBuffer         AS ANY, _    ' LPVOID
    BYVAL cbInBuffer    AS DWORD, _
    lpvOutBuffer        AS ANY, _    ' LPVOID
    BYVAL cbOutBuffer   AS DWORD, _
    lpcbBytesReturned   AS DWORD, _
    lpCompletion        AS WSACOMPLETION _
    ) AS LONG
#ELSE
DECLARE FUNCTION WSANSPIoctl IMPORT "ws2_32.dll" ALIAS "WSANSPIoctl" ( _
   BYVAL hLookup AS DWORD _                             ' __in  HANDLE           hLookup
 , BYVAL dwControlCode AS DWORD _                       ' __in  DWORD            dwControlCode
 , BYVAL lpvInBuffer AS DWORD _                         ' __in  LPVOID           lpvInBuffer
 , BYVAL cbInBuffer AS DWORD _                          ' __in  DWORD            cbInBuffer
 , BYVAL lpvOutBuffer AS DWORD _                        ' __out LPVOID           lpvOutBuffer
 , BYVAL cbOutBuffer AS DWORD _                         ' __in  DWORD            cbOutBuffer
 , BYREF lpcbBytesReturned AS DWORD _                   ' __out LPDWORD          lpcbBytesReturned
 , BYREF lpCompletion AS WSACOMPLETION _                ' __in  LPWSACOMPLETION  lpCompletion
 ) AS LONG                                              ' int
#ENDIF

DECLARE FUNCTION WSALookupServiceEnd IMPORT "ws2_32.dll" ALIAS "WSALookupServiceEnd" ( _
   BYVAL hLookup AS DWORD _                             ' __in HANDLE  hLookup
 ) AS LONG                                              ' int

DECLARE FUNCTION WSAInstallServiceClassA IMPORT "ws2_32.dll" ALIAS "WSAInstallServiceClassA" ( _
   BYREF lpServiceClassInfo AS WSASERVICECLASSINFOA _   ' __in  LPWSASERVICECLASSINFOA   lpServiceClassInfo
 ) AS LONG                                              ' int

DECLARE FUNCTION WSAInstallServiceClassW IMPORT "ws2_32.dll" ALIAS "WSAInstallServiceClassW" ( _
   BYREF lpServiceClassInfo AS WSASERVICECLASSINFOW _   ' __in  LPWSASERVICECLASSINFOW   lpServiceClassInfo
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO WSAInstallServiceClass = WSAInstallServiceClassW
#ELSE
   MACRO WSAInstallServiceClass = WSAInstallServiceClassA
#ENDIF

'#if INCL_WINSOCK_API_PROTOTYPES
DECLARE FUNCTION WSARemoveServiceClass IMPORT "ws2_32.dll" ALIAS "WSARemoveServiceClass" ( _
   BYREF lpServiceClassId AS GUID _                     ' __in  LPGUID  lpServiceClassId
 ) AS LONG                                              ' int

DECLARE FUNCTION WSAGetServiceClassInfoA IMPORT "ws2_32.dll" ALIAS "WSAGetServiceClassInfoA" ( _
   BYREF lpProviderId AS GUID _                         ' __in  LPGUID  lpProviderId
 , BYREF lpServiceClassId AS GUID _                     ' __in  LPGUID  lpServiceClassId
 , BYREF lpdwBufSize AS DWORD _                         ' __in_out LPDWORD  lpdwBufSize
 , BYREF lpServiceClassInfo AS WSASERVICECLASSINFOA _   ' __out LPWSASERVICECLASSINFOA lpServiceClassInfo
 ) AS LONG                                              ' int

DECLARE FUNCTION WSAGetServiceClassInfoW IMPORT "ws2_32.dll" ALIAS "WSAGetServiceClassInfoW" ( _
   BYREF lpProviderId AS GUID _                         ' __in  LPGUID  lpProviderId
 , BYREF lpServiceClassId AS GUID _                     ' __in  LPGUID  lpServiceClassId
 , BYREF lpdwBufSize AS DWORD _                         ' __in_out LPDWORD  lpdwBufSize
 , BYREF lpServiceClassInfo AS WSASERVICECLASSINFOW _   ' __out LPWSASERVICECLASSINFOW lpServiceClassInfo
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO WSAGetServiceClassInfo = WSAGetServiceClassInfoW
#ELSE
   MACRO WSAGetServiceClassInfo = WSAGetServiceClassInfoA
#ENDIF

DECLARE FUNCTION WSAEnumNameSpaceProvidersA IMPORT "ws2_32.dll" ALIAS "WSAEnumNameSpaceProvidersA" ( _
   BYREF lpdwBufferLength AS DWORD _                    ' __in_out LPDWORD              lpdwBufferLength
 , BYREF lpnspBuffer AS WSANAMESPACE_INFOA _            ' __out    LPWSANAMESPACE_INFOA lpnspBuffer
 ) AS LONG                                              ' int

DECLARE FUNCTION WSAEnumNameSpaceProvidersW IMPORT "ws2_32.dll" ALIAS "WSAEnumNameSpaceProvidersW" ( _
   BYREF lpdwBufferLength AS DWORD _                    ' __in_out LPDWORD              lpdwBufferLength
 , BYREF lpnspBuffer AS WSANAMESPACE_INFOW _            ' __out    LPWSANAMESPACE_INFOW lpnspBuffer
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO WSAEnumNameSpaceProviders = WSAEnumNameSpaceProvidersW
#ELSE
   MACRO WSAEnumNameSpaceProviders = WSAEnumNameSpaceProvidersA
#ENDIF

'#if (_WIN32_WINNT >= 0x0600)
DECLARE FUNCTION WSAEnumNameSpaceProvidersExA IMPORT "ws2_32.dll" ALIAS "WSAEnumNameSpaceProvidersExA" ( _
   BYREF lpdwBufferLength AS DWORD _                    ' __in_out LPDWORD             lpdwBufferLength
 , BYREF lpnspBuffer AS WSANAMESPACE_INFOEXA _          ' __out LPWSANAMESPACE_INFOEXA lpnspBuffer
 ) AS LONG                                              ' int

DECLARE FUNCTION WSAEnumNameSpaceProvidersExW IMPORT "ws2_32.dll" ALIAS "WSAEnumNameSpaceProvidersExW" ( _
   BYREF lpdwBufferLength AS DWORD _                    ' __in_out LPDWORD             lpdwBufferLength
 , BYREF lpnspBuffer AS WSANAMESPACE_INFOEXW _          ' __out LPWSANAMESPACE_INFOEXW lpnspBuffer
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO WSAEnumNameSpaceProvidersEx = WSAEnumNameSpaceProvidersExW
#ELSE
   MACRO WSAEnumNameSpaceProvidersEx = WSAEnumNameSpaceProvidersExA
#ENDIF
'#endif //(_WIN32_WINNT >= 0x600)

DECLARE FUNCTION WSAGetServiceClassNameByClassIdA IMPORT "ws2_32.dll" ALIAS "WSAGetServiceClassNameByClassIdA" ( _
   BYREF lpServiceClassId AS GUID _                     ' __in      LPGUID  lpServiceClassId
 , BYREF lpszServiceClassName AS ASCIIZ _               ' __out     LPSTR   lpszServiceClassName
 , BYREF lpdwBufferLength AS DWORD _                    ' __in_out  LPDWORD lpdwBufferLength
 ) AS LONG                                              ' int

DECLARE FUNCTION WSAGetServiceClassNameByClassIdW IMPORT "ws2_32.dll" ALIAS "WSAGetServiceClassNameByClassIdW" ( _
   BYREF lpServiceClassId AS GUID _                     ' __in      LPGUID  lpServiceClassId
 , BYREF lpszServiceClassName AS WSTRINGZ _             ' __out     LPWSTR  lpszServiceClassName
 , BYREF lpdwBufferLength AS DWORD _                    ' __in_out  LPDWORD lpdwBufferLength
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO WSAGetServiceClassNameByClassId = WSAGetServiceClassNameByClassIdW
#ELSE
   MACRO WSAGetServiceClassNameByClassId = WSAGetServiceClassNameByClassIdA
#ENDIF

DECLARE FUNCTION WSASetServiceA IMPORT "ws2_32.dll" ALIAS "WSASetServiceA" ( _
   BYREF lpqsRegInfo AS WSAQUERYSETA _                  ' __in LPWSAQUERYSETA lpqsRegInfo
 , BYVAL essoperation AS LONG _                         ' __in WSAESETSERVICEOP essoperation
 , BYVAL dwControlFlags AS DWORD _                      ' __in DWORD dwControlFlags
 ) AS LONG                                              ' int

DECLARE FUNCTION WSASetServiceW IMPORT "ws2_32.dll" ALIAS "WSASetServiceW" ( _
   BYREF lpqsRegInfo AS WSAQUERYSETW _                  ' __in LPWSAQUERYSETW lpqsRegInfo
 , BYVAL essoperation AS LONG _                         ' __in WSAESETSERVICEOP essoperation
 , BYVAL dwControlFlags AS DWORD _                      ' __in DWORD dwControlFlags
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO WSASetService = WSASetServiceW
#ELSE
   MACRO WSASetService = WSASetServiceA
#ENDIF

DECLARE FUNCTION WSAProviderConfigChange IMPORT "ws2_32.dll" ALIAS "WSAProviderConfigChange" ( _
   BYREF lpNotificationHandle AS DWORD _                ' __in_out LPHANDLE lpNotificationHandle
 , BYREF lpOverlapped AS WSAOVERLAPPED _                ' __in LPWSAOVERLAPPED lpOverlapped
 , BYVAL lpCompletionRoutine AS DWORD _                 ' __in LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
 ) AS LONG                                              ' int

'#if(_WIN32_WINNT >= 0x0600)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WSAPoll LIB "ws2_32.dll" ALIAS "WSAPoll" ( _
    BYVAL fdArray AS WSAPOLLFD PTR, _
    BYVAL fds     AS DWORD, _
    BYVAL TIMEOUT AS LONG _
    ) AS LONG
#ELSE
DECLARE FUNCTION WSAPoll IMPORT "ws2_32.dll" ALIAS "WSAPoll" ( _
   BYREF fdArray AS WSAPOLLFD _                         ' __in_out LPWSAPOLLFD fdArray
 , BYVAL fds AS DWORD _                                 ' __in ULONG fds
 , BYVAL timeout AS LONG _                              ' __in INT timeout
 ) AS LONG                                              ' int
#ENDIF
'#endif // (_WIN32_WINNT >= 0x0600)

'#ENDIF ' #IF (%INCL_WINSOCK_API_PROTOTYPES) -----------------------------------

'/* Microsoft Windows Extended data types */
'typedef struct sockaddr_in SOCKADDR_IN;
'typedef struct sockaddr_in *PSOCKADDR_IN;
'typedef struct sockaddr_in FAR *LPSOCKADDR_IN;

'typedef struct linger LINGER;
'typedef struct linger *PLINGER;
'typedef struct linger FAR *LPLINGER;

'typedef struct in_addr IN_ADDR;
'typedef struct in_addr *PIN_ADDR;
'typedef struct in_addr FAR *LPIN_ADDR;

'typedef struct fd_set FD_SET;
'typedef struct fd_set *PFD_SET;
'typedef struct fd_set FAR *LPFD_SET;

'typedef struct hostent HOSTENT;
'typedef struct hostent *PHOSTENT;
'typedef struct hostent FAR *LPHOSTENT;

'typedef struct servent SERVENT;
'typedef struct servent *PSERVENT;
'typedef struct servent FAR *LPSERVENT;

'typedef struct protoent PROTOENT;
'typedef struct protoent *PPROTOENT;
'typedef struct protoent FAR *LPPROTOENT;

'typedef struct timeval TIMEVAL;
'typedef struct timeval *PTIMEVAL;
'typedef struct timeval FAR *LPTIMEVAL;

'/*
' * Windows message parameter composition and decomposition
' * macros.
' *
' * WSAMAKEASYNCREPLY is intended for use by the Windows Sockets implementation
' * when constructing the response to a WSAAsyncGetXByY() routine.
' */
'#define WSAMAKEASYNCREPLY(buflen,error)     MAKELONG(buflen,error)

FUNCTION WSAMAKEASYNCREPLY (BYVAL wbuflen AS WORD, BYVAL werror AS WORD) AS LONG
   FUNCTION = MAK(LONG, wbuflen, werror)
END FUNCTION

'/*
' * WSAMAKESELECTREPLY is intended for use by the Windows Sockets implementation
' * when constructing the response to WSAAsyncSelect().
' */
'#define WSAMAKESELECTREPLY(event,error)     MAKELONG(event,error)

FUNCTION WSAMAKESELECTREPLY (BYVAL wevent AS WORD, BYVAL werror AS WORD) AS LONG
   FUNCTION = MAK(LONG, wevent, werror)
END FUNCTION

'/*
' * WSAGETASYNCBUFLEN is intended for use by the Windows Sockets application
' * to extract the buffer length from the lParam in the response
' * to a WSAAsyncGetXByY().
' */
'#define WSAGETASYNCBUFLEN(lParam)           LOWORD(lParam)

FUNCTION WSAGETASYNCBUFLEN (BYVAL lParam AS LONG) AS WORD
   FUNCTION = LO(WORD, lParam)
END FUNCTION

'/*
' * WSAGETASYNCERROR is intended for use by the Windows Sockets application
' * to extract the error code from the lParam in the response
' * to a WSAGetXByY().
' */
'#define WSAGETASYNCERROR(lParam)            HIWORD(lParam)

FUNCTION WSAGETASYNCERROR (BYVAL lParam AS LONG) AS WORD
   FUNCTION = HI(WORD, lParam)
END FUNCTION

'/*
' * WSAGETSELECTEVENT is intended for use by the Windows Sockets application
' * to extract the event code from the lParam in the response
' * to a WSAAsyncSelect().
' */
'#define WSAGETSELECTEVENT(lParam)           LOWORD(lParam)

FUNCTION WSAGETSELECTEVENT (BYVAL lParam AS LONG) AS WORD
   FUNCTION = LO(WORD, lParam)
END FUNCTION

'/*
' * WSAGETSELECTERROR is intended for use by the Windows Sockets application
' * to extract the error code from the lParam in the response
' * to a WSAAsyncSelect().
' */
'#define WSAGETSELECTERROR(lParam)           HIWORD(lParam)

FUNCTION WSAGETSELECTERROR (BYVAL lParam AS LONG) AS WORD
   FUNCTION = HI(WORD, lParam)
END FUNCTION

' Return a pointer to all of the host IP addresses
FUNCTION GetHostAddr () AS DWORD
   LOCAL phostent  AS hostent PTR
   LOCAL hostname AS ASCIIZ * 256
   IF gethostname(hostname, SIZEOF(hostname)) = 0 THEN
      IF LEN(hostname) THEN
         phostent = gethostbyname(hostname)
         IF phostent THEN
            FUNCTION = @phostent.h_addr_list
         END IF
      END IF
   END IF
END FUNCTION

FUNCTION h_errno () AS LONG
   FUNCTION = WSAGetLastError
END FUNCTION

'#if(_WIN32_WINNT >= 0x0501)
'#ifdef IPV6STRICT
'#include <wsipv6ok.h>
'#endif // IPV6STRICT
'#endif //(_WIN32_WINNT >= 0x0501)

#ENDIF   ' #IF NOT %DEF(%WINSOCK2API)
