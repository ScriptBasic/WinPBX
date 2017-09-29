' ########################################################################################
' Microsoft Windows
' File: WinSock.inc
' Copyright (c) 2010 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

  '/* WINSOCK.H--definitions to be used with the WINSOCK.DLL
' * Copyright (c) Microsoft Corporation. All rights reserved.
' *
' * This header file corresponds to version 1.1 of the Windows Sockets specification.
' *
' * This file includes parts which are Copyright (c) 1982-1986 Regents
' * of the University of California.  All rights reserved.  The
' * Berkeley Software License Agreement specifies the terms and
' * conditions for redistribution.
' *
' */

#INCLUDE THIS ONCE
%WINSOCK_INC = 1

#IF NOT %DEF(%WINSOCKAPI)
    %WINSOCKAPI = 1
    %WINSOCK2API = 1   ' Prevent inclusion of winsock2.inc

#INCLUDE ONCE "windows.inc"

'/*
' * Basic system type definitions, taken from the BSD file sys/types.h.
' */
'typedef unsigned char   u_char;
'typedef unsigned short  u_short;
'typedef unsigned int    u_int;
'typedef unsigned long   u_long;

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
' * INCLUDED IN WINSOCK.H EXACTLY AS SHOWN HERE.
' */
'#ifndef FD_SETSIZE
'#define FD_SETSIZE      64
'#endif /* FD_SETSIZE */

#IF NOT %DEF(%FD_SETSIZE)
    %FD_SETSIZE = 64
#ENDIF

' // Size = 260 bytes
TYPE fd_setstruc DWORD
   fd_count AS DWORD                    ' /* how many are SET? */
   fd_array (%FD_SETSIZE - 1) AS DWORD  ' /* an array of SOCKETs */
END TYPE

MACRO FD_SET_STRUCT = fd_setstruc

'extern int PASCAL FAR __WSAFDIsSet(SOCKET, fd_set FAR *);

DECLARE FUNCTION WSAFDIsSet IMPORT "wsock32.dll" ALIAS "__WSAFDIsSet" ( _
   BYVAL s AS DWORD _                                   ' SOCKET
 , BYREF pfdset AS fd_setstruc _                        ' fd_set FAR *
 ) AS LONG                                              ' int

'#ifdef __cplusplus
'}
'#endif


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
'    if (((fd_set FAR *)(set))->fd_count < FD_SETSIZE) \
'        ((fd_set FAR *)(set))->fd_array[((fd_set FAR *)(set))->fd_count++]=(fd);\
'} while(0)

'#define FD_ZERO(set) (((fd_set FAR *)(set))->fd_count=0)

'#define FD_ISSET(fd, set) __WSAFDIsSet((SOCKET)(fd), (fd_set FAR *)(set))

SUB FD_SET (BYVAL s AS DWORD, BYREF fds AS fd_setstruc)
   IF fds.fd_count < %FD_SETSIZE THEN
      fds.fd_array(fds.fd_count) = s
      INCR fds.fd_count
   END IF
END SUB

SUB FD_ZERO (BYREF fd AS fd_setstruc)
   fd.fd_count = 0
END SUB

FUNCTION FD_ISSET (BYVAL fd AS DWORD, BYREF fds AS fd_setstruc) AS LONG
   FUNCTION = WSAFDIsSet(fd, fds)
END FUNCTION

'/*
' * Structure used in select() call, taken from the BSD file sys/time.h.
' */
'struct timeval {
'        long    tv_sec;         /* seconds */
'        long    tv_usec;        /* and microseconds */
'};

' // Size = 8 bytes
TYPE timeval DWORD
   tv_sec  AS LONG    ' /* seconds */
   tv_usec AS LONG    ' /* and microseconds */
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

MACRO timerisset (tvp) = (tvp.tv_sec OR tvp.tv_usec)

MACRO timerclear (tvp)
   tvp.tv_sec = 0
   tvp.tv_usec = 0
END MACRO

'/*
' * Commands for ioctlsocket(),  taken from the BSD file fcntl.h.
' *
' *
' * Ioctl's have the command encoded in the lower word,
' * and the size of any in or out parameters in the upper
' * word.  The high 2 bits of the upper word are used
' * to encode the in/out status of the parameter; for now
' * we restrict parameters to at most 128 bytes.
' */
'#define IOCPARM_MASK    0x7f            /* parameters must be < 128 bytes */
'#define IOC_VOID        0x20000000      /* no parameters */
'#define IOC_OUT         0x40000000      /* copy out parameters */
'#define IOC_IN          0x80000000      /* copy in parameters */
'#define IOC_INOUT       (IOC_IN|IOC_OUT)
'                                        /* 0x20000000 distinguishes new &
'                                           old ioctl's */

%IOCPARM_MASK = &H7F                  ' parameters must be < 128 bytes
%IOC_VOID     = &H20000000???         ' no parameters
%IOC_OUT      = &H40000000???         ' copy out parameters
%IOC_IN       = &H80000000???         ' copy in parameters
%IOC_INOUT    = (%IOC_IN OR %IOC_OUT) ' &H20000000 distinguishes new &
                                      ' old ioctl's

'#define _IO(x,y)        (IOC_VOID|((x)<<8)|(y))

MACRO FUNCTION IO_ (x, y)
   MACROTEMP t
   LOCAL t AS DWORD
   t = x
   SHIFT LEFT t, 8
END MACRO = (%IOC_VOID OR t OR y)

'#define _IOR(x,y,t)     (IOC_OUT|(((long)sizeof(t)&IOCPARM_MASK)<<16)|((x)<<8)|(y))

MACRO FUNCTION IOR_ (x, y, t)
   MACROTEMP t1, t2
   LOCAL t1 AS DWORD
   LOCAL t2 AS DWORD
   t1 = SIZEOF(t) AND %IOCPARM_MASK
   SHIFT LEFT t1, 16
   t2 = x
   SHIFT LEFT t2, 8
END MACRO = (%IOC_OUT OR t1 OR t2 OR y)

'#define _IOW(x,y,t)     (IOC_IN|(((long)sizeof(t)&IOCPARM_MASK)<<16)|((x)<<8)|(y))

MACRO FUNCTION IOW_ (x, y, t)
   MACROTEMP t1, t2
   LOCAL t1 AS DWORD
   LOCAL t2 AS DWORD
   t1 = SIZEOF(t) AND %IOCPARM_MASK
   SHIFT LEFT t1, 16
   t2 = x
   SHIFT LEFT t2, 8
END MACRO = (%IOC_IN OR t1 OR t2 OR y)

'#define FIONREAD    _IOR('f', 127, u_long) /* get # bytes to read */
'#define FIONBIO     _IOW('f', 126, u_long) /* set/clear non-blocking i/o */
'#define FIOASYNC    _IOW('f', 125, u_long) /* set/clear async i/o */

%FIONREAD = &H4004667F???  ' get # bytes to read
%FIONBIO  = &H8004667E???  ' set/clear non-blocking i/o
%FIONSYNC = &H8004667D???  ' set/clear async i/o

'/* Socket I/O Controls */
'#define SIOCSHIWAT  _IOW('s',  0, u_long)  /* set high watermark */
'#define SIOCGHIWAT  _IOR('s',  1, u_long)  /* get high watermark */
'#define SIOCSLOWAT  _IOW('s',  2, u_long)  /* set low watermark */
'#define SIOCGLOWAT  _IOR('s',  3, u_long)  /* get low watermark */
'#define SIOCATMARK  _IOR('s',  7, u_long)  /* at oob mark? */

%SIOCSHIWAT = &H80047300???  ' set high watermark
%SIOCGHIWAT = &H80047301???  ' get high watermark
%SIOCSLOWAT = &H80047302???  ' set low watermark
%SIOCGLOWAT = &H80047303???  ' get low watermark
%SIOCATMARK = &H80047307???  ' at oob mark?

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
   h_name  AS ASCIIZ PTR   ' official name of host
   h_alias AS DWORD        ' alias list (pointer to ASCIIZ PTR list)
   h_addr  AS INTEGER      ' host address type
   h_len   AS INTEGER      ' length of address
   h_list  AS DWORD        ' list of addresses (pointer to ASCIIZ PTR list)
END TYPE

'/*
' * It is assumed here that a network number
' * fits in 32 bits.
' */
'struct  netent {
'        char    FAR * n_name;           /* official name of net */
'        char    FAR * FAR * n_aliases;  /* alias list */
'        short   n_addrtype;             /* net address type */
'        u_long  n_net;                  /* network # */
'};

' // Size = 16 bytes
TYPE netent DWORD
   n_name     AS ASCIIZ PTR  ' official name of net
   n_aliases  AS DWORD       ' alias list (pointer to ASCIIZ PTR list)
   n_addrtype AS INTEGER     ' net address type
   n_net      AS DWORD       ' network #
END TYPE

'struct  servent {
'        char    FAR * s_name;           /* official service name */
'        char    FAR * FAR * s_aliases;  /* alias list */
'#ifdef _WIN64
'        char    FAR * s_proto;          /* protocol to use */
'        short   s_port;                 /* port # */
'#else
'        short   s_port;                 /* port # */
'        char    FAR * s_proto;          /* protocol to use */
'#endif
'};

' // Size = 16 bytes
TYPE servent DWORD
   s_name    AS ASCIIZ PTR   ' official service name
   s_aliases AS DWORD        ' alias list (pointer to ASCIIZ PTR list)
   s_port    AS INTEGER      ' port #
   s_proto   AS ASCIIZ PTR   ' protocol to use
END TYPE

'struct  protoent {
'        char    FAR * p_name;           /* official protocol name */
'        char    FAR * FAR * p_aliases;  /* alias list */
'        short   p_proto;                /* protocol # */
'};

' // Size = 12 bytes
TYPE protoent DWORD
   p_name    AS ASCIIZ PTR   ' official protocol name
   p_aliases AS DWORD        ' alias list (pointer to ASCIIZ PTR list)
   p_proto   AS INTEGER      ' protocol #
END TYPE

'/*
' * Constants and structures defined by the internet system,
' * Per RFC 790, September 1981, taken from the BSD file netinet/in.h.
' */

'/*
' * Protocols
' */
%IPPROTO_IP   = 0                ' dummy for IP
%IPPROTO_ICMP = 1                ' control message protocol
%IPPROTO_GGP  = 2                ' gateway^2 (deprecated)
%IPPROTO_TCP  = 6                ' tcp
%IPPROTO_PUP  = 12               ' pup
%IPPROTO_UDP  = 17               ' user datagram protocol
%IPPROTO_IDP  = 22               ' xns idp
%IPPROTO_ND   = 77               ' UNOFFICIAL net disk proto

%IPPROTO_RAW  = 255              ' raw IP packet
%IPPROTO_MAX  = 256

'/*
' * Port/socket numbers: network standard functions
' */
%IPPORT_ECHO        = 7
%IPPORT_DISCARD     = 9
%IPPORT_SYSTAT      = 11
%IPPORT_DAYTIME     = 13
%IPPORT_NETSTAT     = 15
%IPPORT_FTP         = 21
%IPPORT_TELNET      = 23
%IPPORT_SMTP        = 25
%IPPORT_TIMESERVER  = 37
%IPPORT_NAMESERVER  = 42
%IPPORT_WHOIS       = 43
%IPPORT_MTP         = 57

'/*
' * Port/socket numbers: host specific functions
' */
%IPPORT_TFTP        = 69
%IPPORT_RJE         = 77
%IPPORT_FINGER      = 79
%IPPORT_TTYLINK     = 87
%IPPORT_SUPDUP      = 95

'/*
' * UNIX TCP sockets
' */
%IPPORT_EXECSERVER  = 512
%IPPORT_LOGINSERVER = 513
%IPPORT_CMDSERVER   = 514
%IPPORT_EFSSERVER   = 520

'/*
' * UNIX UDP sockets
' */
%IPPORT_BIFFUDP     = 512
%IPPORT_WHOSERVER   = 513
%IPPORT_ROUTESERVER = 520
'                                        /* 520+1 also used */

'/*
' * Ports < IPPORT_RESERVED are reserved for
' * privileged processes (e.g. root).
' */
%IPPORT_RESERVED    = 1024

'/*
' * Link numbers
' */
%IMPLINK_IP        = 155
%IMPLINK_LOWEXPER  = 156
%IMPLINK_HIGHEXPER = 158

#INCLUDE ONCE "inaddr.inc"

'/*
' * Definitions of bits in internet address integers.
' * On subnets, the decomposition of addresses to host and net parts
' * is done according to subnet mask, not the masks here.
' */
'#define IN_CLASSA(i)            (((long)(i) & 0x80000000) == 0)
'#define IN_CLASSA_NET           0xff000000
'#define IN_CLASSA_NSHIFT        24
'#define IN_CLASSA_HOST          0x00ffffff
'#define IN_CLASSA_MAX           128

FUNCTION IN_CLASSA (BYVAL i AS DWORD) AS LONG
   FUNCTION = ((i AND &H80000000???) = 0)
END FUNCTION

%IN_CLASSA_NET    = &HFF000000???
%IN_CLASSA_NSHIFT = 24
%IN_CLASSA_HOST   = &H00FFFFFF
%IN_CLASSA_MAX    = 128

'#define IN_CLASSB(i)            (((long)(i) & 0xc0000000) == 0x80000000)
'#define IN_CLASSB_NET           0xffff0000
'#define IN_CLASSB_NSHIFT        16
'#define IN_CLASSB_HOST          0x0000ffff
'#define IN_CLASSB_MAX           65536

FUNCTION IN_CLASSB (BYVAL i AS DWORD) AS LONG
   FUNCTION = ((i AND &HC0000000???) = &H80000000???)
END FUNCTION

%IN_CLASSB_NET    = &HFFFF0000???
%IN_CLASSB_NSHIFT = 16
%IN_CLASSB_HOST   = &H0000FFFF
%IN_CLASSB_MAX    = 65536

'#define IN_CLASSC(i)            (((long)(i) & 0xe0000000) == 0xc0000000)
'#define IN_CLASSC_NET           0xffffff00
'#define IN_CLASSC_NSHIFT        8
'#define IN_CLASSC_HOST          0x000000ff

FUNCTION IN_CLASSC (BYVAL i AS DWORD) AS LONG
   FUNCTION = ((i AND &He0000000???) = &Hc0000000???)
END FUNCTION

%IN_CLASSC_NET    = &HFFFFFF00???
%IN_CLASSC_NSHIFT = 8??
%IN_CLASSC_HOST   = &H000000FF???

'#define INADDR_ANY              (u_long)0x00000000
'#define INADDR_LOOPBACK         0x7f000001
'#define INADDR_BROADCAST        (u_long)0xffffffff
'#define INADDR_NONE             0xffffffff

%INADDR_ANY       = &H00000000???
%INADDR_LOOPBACK  = &H7F000001???
%INADDR_BROADCAST = &HFFFFFFFF???
%INADDR_NONE      = &HFFFFFFFF???


'/*
' * Socket address, internet style.
' */
' // Size = 16 bytes
TYPE sockaddr_in BYTE
   sin_family AS INTEGER      ' short
   sin_port   AS WORD         ' u_short
   sin_addr   AS in_addr      ' struct in_addr
   sin_zero   AS STRING * 8   ' char[8]
END TYPE

%WSADESCRIPTION_LEN = 256
%WSASYS_STATUS_LEN  = 128

' // Size = 400 bytes
TYPE WSADATA DWORD FILL
   wVersion       AS WORD                               ' WORD
   wHighVersion   AS WORD                               ' WORD
'#ifdef _WIN64
'   unsigned short iMaxSockets;
'   unsigned short iMaxUdpDg;
'   char FAR *     lpVendorInfo;
'   char           szDescription[WSADESCRIPTION_LEN+1];
'   char           szSystemStatus[WSASYS_STATUS_LEN+1];
'#else
   szDescription  AS ASCIIZ * %WSADESCRIPTION_LEN + 1   ' char[[WSADESCRIPTION_LEN+1]
   szSystemStatus AS ASCIIZ * %WSASYS_STATUS_LEN + 1    ' char[WSASYS_STATUS_LEN+1]
   iMaxSockets    AS WORD                               ' unsigned short
   iMaxUdpDg      AS WORD                               ' unsigned short
   lpVendorInfo   AS ASCIIZ PTR                         ' char FAR *
'#endif
END TYPE

'typedef WSADATA FAR *LPWSADATA;

'/*
' * Options for use with [gs]etsockopt at the IP level.
' */
%IP_OPTIONS         = 1           ' set/get IP per-packet options
%IP_MULTICAST_IF    = 2           ' set/get IP multicast interface
%IP_MULTICAST_TTL   = 3           ' set/get IP multicast timetolive
%IP_MULTICAST_LOOP  = 4           ' set/get IP multicast loopback
%IP_ADD_MEMBERSHIP  = 5           ' add  an IP group membership
%IP_DROP_MEMBERSHIP = 6           ' drop an IP group membership
%IP_TTL             = 7           ' set/get IP Time To Live
%IP_TOS             = 8           ' set/get IP Type Of Service
%IP_DONTFRAGMENT    = 9           ' set/get IP Don't Fragment flag

%IP_DEFAULT_MULTICAST_TTL  = 1    ' normally limit m'casts to 1 hop
%IP_DEFAULT_MULTICAST_LOOP = 1    ' normally hear sends if a member
%IP_MAX_MEMBERSHIPS        = 20   ' per socket; must fit in one mbuf

'/*
' * Argument structure for IP_ADD_MEMBERSHIP and IP_DROP_MEMBERSHIP.
' */
' // Size = 8 bytes
TYPE ip_mreq BYTE
   imr_multiaddr AS in_addr  ' struct in_addr // IP multicast address of group
   imr_interface AS in_addr  ' struct in_addr // local IP address of interface
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
' * Types
' */
%SOCK_STREAM    = 1
%SOCK_DGRAM     = 2
%SOCK_RAW       = 3
%SOCK_RDM       = 4
%SOCK_SEQPACKET = 5

'/*
' * Option flags per-socket.
' */
%SO_DEBUG       = &H00001
%SO_ACCEPTCONN  = &H00002
%SO_REUSEADDR   = &H00004
%SO_KEEPALIVE   = &H00008
%SO_DONTROUTE   = &H00010
%SO_BROADCAST   = &H00020
%SO_USELOOPBACK = &H00040
%SO_LINGER      = &H00080
%SO_OOBINLINE   = &H00100

'#define SO_DONTLINGER   (u_int)(~SO_LINGER)
%SO_DONTLINGER  = &H0FF7F          ' CDWD(NOT %SO_LINGER)

'/*
' * Additional options.
' */
%SO_SNDBUF      = &H01001
%SO_RCVBUF      = &H01002
%SO_SNDLOWAT    = &H01003
%SO_RCVLOWAT    = &H01004
%SO_SNDTIMEO    = &H01005
%SO_RCVTIMEO    = &H01006
%SO_ERROR       = &H01007
%SO_TYPE        = &H01008

'/*
' * Options for connect and disconnect data and options.  Used only by
' * non-TCP/IP transports such as DECNet, OSI TP4, etc.
' */
%SO_CONNDATA    = &H07000
%SO_CONNOPT     = &H07001
%SO_DISCDATA    = &H07002
%SO_DISCOPT     = &H07003
%SO_CONNDATALEN = &H07004
%SO_CONNOPTLEN  = &H07005
%SO_DISCDATALEN = &H07006
%SO_DISCOPTLEN  = &H07007

'/*
' * Option for opening sockets for synchronous access.
' */
%SO_OPENTYPE    = &H07008

%SO_SYNCHRONOUS_ALERT    = &H10
%SO_SYNCHRONOUS_NONALERT = &H20

'/*
' * Other NT-specific options.
' */
%SO_MAXDG                 = &H07009
%SO_MAXPATHDG             = &H0700A
%SO_UPDATE_ACCEPT_CONTEXT = &H0700B
%SO_CONNECT_TIME          = &H0700C

'/*
' * TCP options.
' */
%TCP_NODELAY   = &H00001
%TCP_BSDURGENT = &H07000

'/*
' * Address families.
' */
%AF_UNSPEC    = 0           ' unspecified
%AF_UNIX      = 1           ' local to host (pipes, portals)
%AF_INET      = 2           ' __internetwork: UDP, TCP, etc.
%AF_IMPLINK   = 3           ' arpanet imp addresses
%AF_PUP       = 4           ' pup protocols: e.g. BSP
%AF_CHAOS     = 5           ' mit CHAOS protocols
%AF_NS        = 6           ' XEROX NS protocols
%AF_IPX       = 6           ' IPX and SPX
%AF_ISO       = 7           ' ISO protocols
%AF_OSI       = %AF_ISO     ' OSI is ISO
%AF_ECMA      = 8           ' european computer manufacturers
%AF_DATAKIT   = 9           ' datakit protocols
%AF_CCITT     = 10          ' CCITT protocols, X.25 etc
%AF_SNA       = 11          ' IBM SNA
%AF_DECnet    = 12          ' DECnet
%AF_DLI       = 13          ' Direct data link interface
%AF_LAT       = 14          ' LAT
%AF_HYLINK    = 15          ' NSC Hyperchannel
%AF_APPLETALK = 16          ' AppleTalk
%AF_NETBIOS   = 17          ' NetBios-style addresses
%AF_VOICEVIEW = 18          ' VoiceView
%AF_FIREFOX   = 19          ' FireFox
%AF_UNKNOWN1  = 20          ' Somebody is using this!
%AF_BAN       = 21          ' Banyan

%AF_MAX       = 22

'/*
' * Structure used by kernel to store most
' * addresses.
' */
' // Size = 16 bytes
TYPE sockaddr BYTE
   sa_family AS WORD         ' u_short // address family
   sa_data   AS STRING * 14  ' char[14] // up to 14 bytes of direct address
END TYPE

'/*
' * Structure used by kernel to pass protocol
' * information in raw sockets.
' */
' // Size = 4 bytes
TYPE sockproto WORD
   sp_family   AS WORD  ' u_short // address family
   sp_protocol AS WORD  ' u_short // protocol
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

%PF_MAX       = %AF_MAX

'/*
' * Structure used for manipulating linger option.
' */
' // Size = 4 bytes
TYPE linger WORD
   l_onoff  AS WORD   ' u_short // option on/off
   l_linger AS WORD   ' u_short // linger time
END TYPE

'/*
' * Level number for (get/set)sockopt() to apply to socket itself.
' */
'#define SOL_SOCKET      0xffff          /* options for socket level */
%SOL_SOCKET = &HFFFF???   ' options for socket level

'/*
' * Maximum queue length specifiable by listen.
' */
'#define SOMAXCONN       5

'#define MSG_OOB         0x1             /* process out-of-band data */
'#define MSG_PEEK        0x2             /* peek at incoming message */
'#define MSG_DONTROUTE   0x4             /* send without using routing tables */

'#define MSG_MAXIOVLEN   16

'#define MSG_PARTIAL     0x8000          /* partial send or recv for message xport */

%SOMAXCONN = 5

%MSG_OOB       = &H1       ' process out-of-band data
%MSG_PEEK      = &H2       ' peek at incoming message
%MSG_DONTROUTE = &H4       ' send without using routing tables

%MSG_MAXIOVLEN = 16

%MSG_PARTIAL   = &H8000??? ' partial send or recv for message xport

'/*
' * Define constant based on rfc883, used by gethostbyxxxx() calls.
' */
'#define MAXGETHOSTSTRUCT        1024

%MAXGETHOSTSTRUCT = 1024

'/*
' * Define flags to be used with the WSAAsyncSelect() call.
' */
%FD_READ    = &H001
%FD_WRITE   = &H002
%FD_OOB     = &H004
%FD_ACCEPT  = &H008
%FD_CONNECT = &H010
%FD_CLOSE   = &H020

'/*
' * WinSock error codes are also defined in winerror.h
' * Hence the IFDEF.
' */
'#ifndef WSABASEERR

#IF NOT %DEF(%WSABASEERR) '----------------------------------------------------

'/*
' * All Windows Sockets error constants are biased by WSABASEERR from
' * the "normal"
' */
'#define WSABASEERR              10000

%WSABASEERR = 10000

'/*
' * Windows Sockets definitions of regular Microsoft C error constants
' */
%WSAEINTR           = %WSABASEERR + 4
%WSAEBADF           = %WSABASEERR + 9
%WSAEACCES          = %WSABASEERR + 13
%WSAEFAULT          = %WSABASEERR + 14
%WSAEINVAL          = %WSABASEERR + 22
%WSAEMFILE          = %WSABASEERR + 24

'/*
' * Windows Sockets definitions of regular Berkeley error constants
' */
%WSAEWOULDBLOCK     = %WSABASEERR + 35
%WSAEINPROGRESS     = %WSABASEERR + 36
%WSAEALREADY        = %WSABASEERR + 37
%WSAENOTSOCK        = %WSABASEERR + 38
%WSAEDESTADDRREQ    = %WSABASEERR + 39
%WSAEMSGSIZE        = %WSABASEERR + 40
%WSAEPROTOTYPE      = %WSABASEERR + 41
%WSAENOPROTOOPT     = %WSABASEERR + 42
%WSAEPROTONOSUPPORT = %WSABASEERR + 43
%WSAESOCKTNOSUPPORT = %WSABASEERR + 44
%WSAEOPNOTSUPP      = %WSABASEERR + 45
%WSAEPFNOSUPPORT    = %WSABASEERR + 46
%WSAEAFNOSUPPORT    = %WSABASEERR + 47
%WSAEADDRINUSE      = %WSABASEERR + 48
%WSAEADDRNOTAVAIL   = %WSABASEERR + 49
%WSAENETDOWN        = %WSABASEERR + 50
%WSAENETUNREACH     = %WSABASEERR + 51
%WSAENETRESET       = %WSABASEERR + 52
%WSAECONNABORTED    = %WSABASEERR + 53
%WSAECONNRESET      = %WSABASEERR + 54
%WSAENOBUFS         = %WSABASEERR + 55
%WSAEISCONN         = %WSABASEERR + 56
%WSAENOTCONN        = %WSABASEERR + 57
%WSAESHUTDOWN       = %WSABASEERR + 58
%WSAETOOMANYREFS    = %WSABASEERR + 59
%WSAETIMEDOUT       = %WSABASEERR + 60
%WSAECONNREFUSED    = %WSABASEERR + 61
%WSAELOOP           = %WSABASEERR + 62
%WSAENAMETOOLONG    = %WSABASEERR + 63
%WSAEHOSTDOWN       = %WSABASEERR + 64
%WSAEHOSTUNREACH    = %WSABASEERR + 65
%WSAENOTEMPTY       = %WSABASEERR + 66
%WSAEPROCLIM        = %WSABASEERR + 67
%WSAEUSERS          = %WSABASEERR + 68
%WSAEDQUOT          = %WSABASEERR + 69
%WSAESTALE          = %WSABASEERR + 70
%WSAEREMOTE         = %WSABASEERR + 71

%WSAEDISCON         = %WSABASEERR + 101

'/*
' * Extended Windows Sockets error constant definitions
' */
%WSASYSNOTREADY     = %WSABASEERR + 91
%WSAVERNOTSUPPORTED = %WSABASEERR + 92
%WSANOTINITIALISED  = %WSABASEERR + 93

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
%WSAHOST_NOT_FOUND           = %WSABASEERR + 1001

'/* Non-Authoritative: Host not found, or SERVERFAIL */
%WSATRY_AGAIN                = %WSABASEERR + 1002

'/* Non recoverable errors, FORMERR, REFUSED, NOTIMP */
%WSANO_RECOVERY              = %WSABASEERR + 1003

'/* Valid name, no data record of requested type */
%WSANO_DATA                  = %WSABASEERR + 1004

'/* Authoritative Answer: Host not found Securely */
%WSA_SECURE_HOST_NOT_FOUND   = %WSABASEERR + 1032

'/* Name based IPSEC policy could not be added*/
%WSA_IPSEC_NAME_POLICY_ERROR = %WSABASEERR + 1033

'/*
' * WinSock error codes are also defined in winerror.h
' * Hence the IFDEF.
' */
'#endif /* ifdef WSABASEERR */

#ENDIF  ' #IF %DEF(%WSABASEERR) -----------------------------------------------

'/*
' * Compatibility macros.
' */

'#define h_errno         WSAGetLastError()

MACRO h_errno = WSAGetLastError()

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

%EWOULDBLOCK     = %WSAEWOULDBLOCK
%EINPROGRESS     = %WSAEINPROGRESS
%EALREADY        = %WSAEALREADY
%ENOTSOCK        = %WSAENOTSOCK
%EDESTADDRREQ    = %WSAEDESTADDRREQ
%EMSGSIZE        = %WSAEMSGSIZE
%EPROTOTYPE      = %WSAEPROTOTYPE
%ENOPROTOOPT     = %WSAENOPROTOOPT
%EPROTONOSUPPORT = %WSAEPROTONOSUPPORT
%ESOCKTNOSUPPORT = %WSAESOCKTNOSUPPORT
%EOPNOTSUPP      = %WSAEOPNOTSUPP
%EPFNOSUPPORT    = %WSAEPFNOSUPPORT
%EAFNOSUPPORT    = %WSAEAFNOSUPPORT
%EADDRINUSE      = %WSAEADDRINUSE
%EADDRNOTAVAIL   = %WSAEADDRNOTAVAIL
%ENETDOWN        = %WSAENETDOWN
%ENETUNREACH     = %WSAENETUNREACH
%ENETRESET       = %WSAENETRESET
%ECONNABORTED    = %WSAECONNABORTED
%ECONNRESET      = %WSAECONNRESET
%ENOBUFS         = %WSAENOBUFS
%EISCONN         = %WSAEISCONN
%ENOTCONN        = %WSAENOTCONN
%ESHUTDOWN       = %WSAESHUTDOWN
%ETOOMANYREFS    = %WSAETOOMANYREFS
%ETIMEDOUT       = %WSAETIMEDOUT
%ECONNREFUSED    = %WSAECONNREFUSED
%ELOOP           = %WSAELOOP
%ENAMETOOLONG    = %WSAENAMETOOLONG
%EHOSTDOWN       = %WSAEHOSTDOWN
%EHOSTUNREACH    = %WSAEHOSTUNREACH
%ENOTEMPTY       = %WSAENOTEMPTY
%EPROCLIM        = %WSAEPROCLIM
%EUSERS          = %WSAEUSERS
%EDQUOT          = %WSAEDQUOT
%ESTALE          = %WSAESTALE
%EREMOTE         = %WSAEREMOTE

'/* Socket function prototypes */

DECLARE FUNCTION aaccept IMPORT "wsock32.dll" ALIAS "accept" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF addr AS sockaddr_in _                          ' __out struct sockaddr FAR *addr
 , BYREF addrlen AS LONG _                              ' __in_out int FAR *addrlen
 ) AS DWORD                                             ' SOCKET

DECLARE FUNCTION bind IMPORT "wsock32.dll" ALIAS "bind" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF addr AS sockaddr_in _                          ' __in const struct sockaddr FAR *addr
 , BYVAL namelen AS LONG _                              ' __in int namelen
 ) AS LONG                                              ' int

DECLARE FUNCTION closesocket IMPORT "wsock32.dll" ALIAS "closesocket" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 ) AS LONG                                              ' int

DECLARE FUNCTION cconnect IMPORT "wsock32.dll" ALIAS "connect" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF name AS sockaddr_in _                          ' __in const struct sockaddr FAR *name
 , BYVAL namelen AS LONG _                              ' __in int namelen
 ) AS LONG                                              ' int

DECLARE FUNCTION ioctlsocket IMPORT "wsock32.dll" ALIAS "ioctlsocket" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYVAL cmd AS LONG _                                  ' __in long cmd
 , BYREF argp AS DWORD _                                ' __in_out u_long FAR *argp
 ) AS LONG                                              ' int

DECLARE FUNCTION getpeername IMPORT "wsock32.dll" ALIAS "getpeername" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF name AS sockaddr_in _                          ' __out struct sockaddr FAR *name
 , BYREF namelen AS LONG _                              ' __in_out int FAR * namelen
 ) AS LONG                                              ' int

DECLARE FUNCTION getsockname IMPORT "wsock32.dll" ALIAS "getsockname" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF name AS sockaddr_in _                          ' __out struct sockaddr FAR *name
 , BYREF namelen AS LONG _                              ' __in_out int FAR * namelen
 ) AS LONG                                              ' int

DECLARE FUNCTION getsockopt IMPORT "wsock32.dll" ALIAS "getsockopt" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYVAL level AS LONG _                                ' __in int level
 , BYVAL optname AS LONG _                              ' __in int optname
 , BYREF optval AS ANY _                                ' __out char FAR * optval
 , BYREF optlen AS LONG _                               ' __in_out int FAR *optlen
 ) AS LONG                                              ' int

DECLARE FUNCTION htonl IMPORT "wsock32.dll" ALIAS "htonl" ( _
   BYVAL hostlong AS DWORD _                            ' __in u_long hostlong
 ) AS DWORD                                             ' u_long

DECLARE FUNCTION htons IMPORT "wsock32.dll" ALIAS "htons" ( _
   BYVAL hostshort AS WORD _                            ' __in u_short hostshort
 ) AS WORD                                              ' u_short

DECLARE FUNCTION inet_addr IMPORT "wsock32.dll" ALIAS "inet_addr" ( _
   BYREF cp AS ASCIIZ _                                 ' __in const char FAR * cp
 ) AS DWORD                                             ' unsigned long

DECLARE FUNCTION inet_ntoa IMPORT "wsock32.dll" ALIAS "inet_ntoa" ( _
   BYVAL in_ AS DWORD _                                ' __in struct in_addr in
 ) AS DWORD                                            ' char FAR*

DECLARE FUNCTION listen IMPORT "wsock32.dll" ALIAS "listen" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYVAL backlog AS LONG _                              ' __in int backlog
 ) AS LONG                                              ' int

DECLARE FUNCTION ntohl IMPORT "wsock32.dll" ALIAS "ntohl" ( _
   BYVAL netlong AS DWORD _                             ' __in u_long netlong
 ) AS DWORD                                             ' u_long

DECLARE FUNCTION ntohs IMPORT "wsock32.dll" ALIAS "ntohs" ( _
   BYVAL netshort AS WORD _                             ' __in u_short netshort
 ) AS WORD                                              ' u_short

DECLARE FUNCTION rrecv IMPORT "wsock32.dll" ALIAS "recv" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF buf AS ANY _                                   ' __out char FAR * buf
 , BYVAL len AS LONG _                                  ' __in int len
 , BYVAL flags AS LONG _                                ' __in int flags
 ) AS LONG                                              ' int

DECLARE FUNCTION recvfrom IMPORT "wsock32.dll" ALIAS "recvfrom" ( _
   BYVAL s AS LONG _                                    ' __in SOCKET s
 , BYREF buf AS ANY _                                   ' __out char FAR * buf
 , BYVAL len AS LONG _                                  ' __in int len
 , BYVAL flags AS LONG _                                ' __in int flags
 , BYREF from AS sockaddr_in _                          ' __out struct sockaddr FAR *from
 , BYREF fromlen AS LONG _                              ' __in_out int FAR * fromlen
 ) AS LONG                                              ' int

DECLARE FUNCTION sselect IMPORT "wsock32.dll" ALIAS "select" ( _
   BYVAL nfds AS LONG _                                 ' __in int nfds
 , BYREF readfds AS fd_setstruc _                       ' __in_out fd_set FAR *readfds
 , BYREF writefds AS fd_setstruc _                      ' __in_out fd_set FAR *writefds
 , BYREF exceptfds AS fd_setstruc _                     ' __in_out fd_set FAR *exceptfds
 , BYREF timeout AS timeval _                           ' __in const struct timeval FAR *timeout
 ) AS LONG                                              ' int

DECLARE FUNCTION ssend IMPORT "wsock32.dll" ALIAS "send" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF buf AS ANY _                                   ' __in const char FAR * buf
 , BYVAL len AS LONG _                                  ' __in int len
 , BYVAL flags AS LONG _                                ' __in int flags
 ) AS LONG                                              ' int

DECLARE FUNCTION sendto IMPORT "wsock32.dll" ALIAS "sendto" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF buf AS ANY _                                   ' __in const char FAR * buf
 , BYVAL len AS LONG _                                  ' __in int len
 , BYVAL flags AS LONG _                                ' __in int flags
 , BYREF to AS sockaddr_in _                            ' __in const struct sockaddr FAR *to
 , BYVAL tolen AS LONG _                                ' __in int tolen
 ) AS LONG                                              ' int

DECLARE FUNCTION setsockopt IMPORT "wsock32.dll" ALIAS "setsockopt" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYVAL level AS LONG _                                ' __in int level
 , BYVAL optname AS LONG _                              ' __in int optname
 , BYREF optval AS ANY _                                ' __in const char FAR * optval
 , BYVAL optlen AS LONG _                               ' __in int optlen
 ) AS LONG                                              ' int

DECLARE FUNCTION shutdown IMPORT "wsock32.dll" ALIAS "shutdown" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYVAL how AS LONG _                                  ' __in int how
 ) AS LONG                                              ' int

DECLARE FUNCTION socket IMPORT "wsock32.dll" ALIAS "socket" ( _
   BYVAL af AS DWORD _                                  ' __in int af
 , BYVAL type AS LONG _                                 ' __in int type
 , BYVAL protocol AS LONG _                             ' __in int protocol
 ) AS DWORD                                             ' SOCKET

'/* Database function prototypes */

DECLARE FUNCTION gethostbyaddr IMPORT "wsock32.dll"  ALIAS "gethostbyaddr" ( _
   BYREF addr AS ANY _                                  ' __in const char FAR * addr
 , BYVAL len AS LONG _                                  ' __in int len
 , BYVAL type AS LONG _                                 ' __in int type
 ) AS DWORD                                             ' struct hostent FAR *

DECLARE FUNCTION gethostbyname IMPORT "wsock32.dll" ALIAS "gethostbyname" ( _
   BYREF name AS ASCIIZ _                               ' __in const char FAR * name
 ) AS DWORD                                             ' struct hostent FAR *

DECLARE FUNCTION gethostname IMPORT "wsock32.dll" ALIAS "gethostname" ( _
   BYREF name AS ASCIIZ _                               ' __out char FAR * name
 , BYVAL namelen AS LONG _                              ' __in int namelen
 ) AS LONG                                              ' int

DECLARE FUNCTION getservbyport IMPORT "wsock32.dll" ALIAS "getservbyport" ( _
   BYVAL port AS LONG _                                 ' __in int port
 , BYREF proto AS ASCIIZ _                              ' __in const char FAR * proto
 ) AS DWORD                                             ' struct servent FAR *

DECLARE FUNCTION getservbyname IMPORT "wsock32.dll" ALIAS "getservbyname" ( _
   BYREF name AS ASCIIZ _                               ' __in const char FAR * name
 , BYREF proto AS ASCIIZ _                              ' __in const char FAR * proto
 ) AS DWORD                                             ' struct servent FAR *

DECLARE FUNCTION getprotobynumber IMPORT "wsock32.dll" ALIAS "getprotobynumber" ( _
   BYVAL proto AS LONG _                                ' __in int proto
 ) AS DWORD                                             ' struct protoent FAR *

DECLARE FUNCTION getprotobyname IMPORT "wsock32.dll" ALIAS "getprotobyname" ( _
   BYREF name AS ASCIIZ _                               ' __in const char FAR * name
 ) AS DWORD                                             ' struct protoent FAR *

'/* Microsoft Windows Extension function prototypes */

DECLARE FUNCTION WSAStartup IMPORT "wsock32.dll" ALIAS "WSAStartup" ( _
   BYVAL wVersionRequired AS WORD _                     ' __in WORD wVersionRequired
 , BYREF lpWSAData AS WSADATA _                         ' __out LPWSADATA lpWSAData
 ) AS LONG                                              ' int

DECLARE FUNCTION WSACleanup IMPORT "wsock32.dll" ALIAS "WSACleanup" ( _
 ) AS LONG                                              ' int

DECLARE SUB WSASetLastError IMPORT "wsock32.dll" ALIAS "WSASetLastError" ( _
   BYVAL iError AS LONG _                               ' __in int iError
 )                                                      ' void

DECLARE FUNCTION WSAGetLastError IMPORT "wsock32.dll" ALIAS "WSAGetLastError" ( _
 ) AS LONG                                              ' int

DECLARE FUNCTION WSAIsBlocking IMPORT "wsock32.dll" ALIAS "WSAIsBlocking" ( _
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WSAUnhookBlockingHook IMPORT "wsock32.dll" ALIAS "WSAUnhookBlockingHook" ( _
 ) AS LONG                                              ' int

DECLARE FUNCTION WSASetBlockingHook IMPORT "wsock32.dll" ALIAS "WSASetBlockingHook" ( _
   BYVAL lpBlockFunc AS DWORD _                         ' __in FARPROC lpBlockFunc
 ) AS DWORD                                             ' FARPROC

DECLARE FUNCTION WSACancelBlockingCall IMPORT "wsock32.dll" ALIAS "WSACancelBlockingCall" ( _
 ) AS LONG                                              ' int

DECLARE FUNCTION WSAAsyncGetServByName IMPORT "wsock32.dll" ALIAS "WSAAsyncGetServByName" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL wMsg AS DWORD _                                ' __in u_int wMsg
 , BYREF name AS ASCIIZ _                               ' __in const char FAR * name
 , BYREF proto AS ASCIIZ _                              ' __in const char FAR * proto
 , BYREF buf AS ASCIIZ _                                ' __out char FAR * buf
 , BYVAL buflen AS LONG _                               ' __in int buflen
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION WSAAsyncGetServByPort IMPORT "wsock32.dll" ALIAS "WSAAsyncGetServByPort" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL wMsg AS DWORD _                                ' __in u_int wMsg
 , BYVAL port AS LONG _                                 ' __in int port
 , BYREF proto AS ASCIIZ _                              ' __in const char FAR * proto
 , BYREF buf AS ASCIIZ _                                ' __out char FAR * buf
 , BYVAL buflen AS LONG _                               ' __in int buflen
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION WSAAsyncGetProtoByName IMPORT "wsock32.dll" ALIAS "WSAAsyncGetProtoByName" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL wMsg AS DWORD _                                ' __in u_int wMsg
 , BYREF name AS ASCIIZ _                               ' __in const char FAR * name
 , BYREF buf AS ASCIIZ  _                               ' __out char FAR * buf
 , BYVAL buflen AS LONG _                               ' __in int buflen
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION WSAAsyncGetProtoByNumber IMPORT "wsock32.dll" ALIAS "WSAAsyncGetProtoByNumber" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL wMsg AS DWORD _                                ' __in u_int wMsg
 , BYVAL number AS LONG _                               ' __in int number
 , BYREF buf AS ASCIIZ _                                ' __out char FAR * buf
 , BYVAL buflen AS LONG _                               ' __in int buflen
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION WSAAsyncGetHostByName IMPORT "wsock32.dll" ALIAS "WSAAsyncGetHostByName" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL wMsg AS DWORD _                                ' __in u_int wMsg
 , BYREF name AS ASCIIZ _                               ' __in const char FAR * name
 , BYREF buf AS ASCIIZ _                                ' __out char FAR * buf
 , BYVAL buflen AS LONG _                               ' __in int buflen
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION WSAAsyncGetHostByAddr IMPORT "wsock32.dll" ALIAS "WSAAsyncGetHostByAddr" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL wMsg AS DWORD _                                ' __in u_int wMsg
 , BYREF addr AS ASCIIZ _                               ' __in const char FAR * addr
 , BYVAL len AS LONG _                                  ' __in int len
 , BYVAL type AS LONG _                                 ' __in int type
 , BYREF buf AS ASCIIZ _                                ' __out char FAR * buf
 , BYVAL buflen AS LONG _                               ' __in int buflen
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION WSACancelAsyncRequest IMPORT "wsock32.dll" ALIAS "WSACancelAsyncRequest" ( _
   BYVAL hAsyncTaskHandle AS DWORD _                    ' __in HANDLE hAsyncTaskHandle
 ) AS LONG                                              ' int

DECLARE FUNCTION WSAAsyncSelect IMPORT "wsock32.dll" ALIAS "WSAAsyncSelect" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL wMsg AS DWORD _                                ' __in u_int wMsg
 , BYVAL lEvent AS LONG _                               ' __in long lEvent
 ) AS LONG                                              ' int

DECLARE FUNCTION WSARecvEx IMPORT "wsock32.dll" ALIAS "WSARecvEx" ( _
   BYVAL s AS DWORD _                                   ' __in SOCKET s
 , BYREF buf AS ANY _                                   ' __out char FAR * buf
 , BYVAL len AS LONG _                                  ' __in int len
 , BYVAL flags AS LONG _                                ' __in_out int FAR *flags
 ) AS LONG                                              ' int

' // Size = 16 bytes
TYPE TRANSMIT_FILE_BUFFERS DWORD
   Head       AS DWORD   ' DWORD
   HeadLength AS DWORD   ' DWORD
   Tail       AS DWORD   ' PVOID
   TailLength AS DWORD   ' DWORD
END TYPE

%TF_DISCONNECT   = &H01
%TF_REUSE_SOCKET = &H02
%TF_WRITE_BEHIND = &H04

DECLARE FUNCTION TransmitFile IMPORT "wsock32.dll" ALIAS "TransmitFile" ( _
   BYVAL hSocket AS DWORD _                             ' __in SOCKET hSocket
 , BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYVAL nNumberOfBytesToWrite AS DWORD _               ' __in DWORD nNumberOfBytesToWrite
 , BYVAL nNumberOfBytesPerSend AS DWORD _               ' __in DWORD nNumberOfBytesPerSend
 , BYREF lpOverlapped AS OVERLAPPED _                   ' __in LPOVERLAPPED lpOverlapped
 , BYREF lpTransmitBuffers AS TRANSMIT_FILE_BUFFERS _   ' __in LPTRANSMIT_FILE_BUFFERS lpTransmitBuffers
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AcceptEx IMPORT "wsock32.dll" ALIAS "AcceptEx" ( _
   BYVAL sListenSocket AS DWORD _                       ' __in SOCKET sListenSocket
 , BYVAL sAcceptSocket AS DWORD _                       ' __in SOCKET sAcceptSocket
 , BYREF lpOutputBuffer AS ANY _                        ' __in PVOID lpOutputBuffer
 , BYVAL dwReceiveDataLength AS DWORD _                 ' __in DWORD dwReceiveDataLength
 , BYVAL dwLocalAddressLength AS DWORD _                ' __in DWORD dwLocalAddressLength
 , BYVAL dwRemoteAddressLength AS DWORD _               ' __in DWORD dwRemoteAddressLength
 , BYREF lpdwBytesReceived AS DWORD _                   ' __out LPDWORD lpdwBytesReceived
 , BYREF lpOverlapped AS OVERLAPPED _                   ' __in LPOVERLAPPED lpOverlapped
 ) AS LONG                                              ' BOOL

DECLARE SUB GetAcceptExSockaddrs IMPORT "wsock32.dll" ALIAS "GetAcceptExSockaddrs" ( _
   BYREF lpOutputBuffer AS ANY _                        ' __in PVOID lpOutputBuffer
 , BYVAL dwReceiveDataLength AS DWORD _                 ' __in DWORD dwReceiveDataLength
 , BYVAL dwLocalAddressLength AS DWORD _                ' __in DWORD dwLocalAddressLength
 , BYVAL dwRemoteAddressLength AS DWORD _               ' __in DWORD dwRemoteAddressLength
 , BYREF LocalSockaddr AS DWORD _                       ' __out struct sockaddr **LocalSockaddr
 , BYREF LocalSockaddrLength AS LONG _                  ' __out LPINT LocalSockaddrLength
 , BYREF RemoteSockaddr AS DWORD _                      ' __out struct sockaddr **RemoteSockaddr
 , BYREF RemoteSockaddrLength AS LONG _                 ' __out LPINT RemoteSockaddrLength
 )                                                      ' void

'/* Microsoft Windows Extended data types */
'typedef struct sockaddr SOCKADDR;
'typedef struct sockaddr *PSOCKADDR;
'typedef struct sockaddr FAR *LPSOCKADDR;

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
MACRO WSAMAKEASYNCREPLY (buflen, errorno) = MAK(LONG, buflen, errorno)

'/*
' * WSAMAKESELECTREPLY is intended for use by the Windows Sockets implementation
' * when constructing the response to WSAAsyncSelect().
' */
MACRO WSAMAKESELECTREPLY(xevent, errorno) = MAK(LONG, xevent, errorno)

'/*
' * WSAGETASYNCBUFLEN is intended for use by the Windows Sockets application
' * to extract the buffer length from the lParam in the response
' * to a WSAGetXByY().
' */
MACRO WSAGETASYNCBUFLEN(lParam) = LO(WORD, lParam)

'/*
' * WSAGETASYNCERROR is intended for use by the Windows Sockets application
' * to extract the error code from the lParam in the response
' * to a WSAGetXByY().
' */
MACRO WSAGETASYNCERROR(lParam) = HI(WORD, lParam)

'/*
' * WSAGETSELECTEVENT is intended for use by the Windows Sockets application
' * to extract the event code from the lParam in the response
' * to a WSAAsyncSelect().
' */
'#define WSAGETSELECTEVENT(lParam)           LOWORD(lParam)

MACRO WSAGETSELECTEVENT(lParam) = LO(WORD, lParam)

'/*
' * WSAGETSELECTERROR is intended for use by the Windows Sockets application
' * to extract the error code from the lParam in the response
' * to a WSAAsyncSelect().
' */
'#define WSAGETSELECTERROR(lParam)           HIWORD(lParam)

MACRO WSAGETSELECTERROR(lParam) = HI(WORD, lParam)

' Return a pointer to all of the host IP addresses
FUNCTION GetHostAddr () AS DWORD
   LOCAL phostent  AS hostent PTR
   LOCAL hostname AS ASCIIZ * 256
   IF gethostname(hostname, SIZEOF(hostname)) = 0 THEN
      IF LEN(hostname) THEN
         phostent = gethostbyname(hostname)
         IF phostent THEN
            FUNCTION = @phostent.h_list
         END IF
      END IF
   END IF
END FUNCTION

'#ifdef IPV6STRICT
'#error WINSOCK2 required.
'#endif // IPV6STRICT

#ENDIF  ' #IF NOT %DEF(%WINSOCKAPI)
