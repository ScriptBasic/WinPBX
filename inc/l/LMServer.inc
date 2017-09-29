' ########################################################################################
' Microsoft Windows
' File: LMServer.inc
' Contents: This file contains information about NetServer APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%LMSERVER_INC = 1

#INCLUDE ONCE "winsvc.inc"   ' // SERVICE_STATUS_HANDLE
#INCLUDE ONCE "lmcons.inc"

'//
'// Function Prototypes - SERVER
'//

DECLARE FUNCTION NetServerEnum IMPORT "NETAPI32.DLL" ALIAS "NetServerEnum" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMCSTR      servername OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD       level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE      *bufptr
 , BYVAL prefmaxlen AS DWORD _                          ' __in  DWORD       prefmaxlen
 , BYREF entriesread AS DWORD _                         ' __out LPDWORD     entriesread
 , BYREF totalentries AS DWORD _                        ' __out LPDWORD     totalentries
 , BYVAL servertype AS DWORD _                          ' __in  DWORD       servertype
 , BYREF domain AS WSTRINGZ _                           ' __in  LMCSTR      domain OPTIONAL
 , BYREF resume_handle AS DWORD _                       ' __in_out LPDWORD  resume_handle OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetServerEnumEx IMPORT "NETAPI32.DLL" ALIAS "NetServerEnumEx" ( _
   BYREF ServerName AS WSTRINGZ _                       ' __in  LMCSTR      ServerName OPTIONAL
 , BYVAL Level AS DWORD _                               ' __in  DWORD       Level
 , BYREF Bufptr AS ANY _                                ' __out LPBYTE      *Bufptr
 , BYVAL PrefMaxlen AS DWORD _                          ' __in  DWORD       PrefMaxlen
 , BYREF EntriesRead AS DWORD _                         ' __out LPDWORD     EntriesRead
 , BYREF totalentries AS DWORD _                        ' __out LPDWORD     totalentries
 , BYVAL servertype AS DWORD _                          ' __in  DWORD       servertype
 , BYREF domain AS WSTRINGZ _                           ' __in  LMCSTR      domain OPTIONAL
 , BYREF FirstNameToReturn AS WSTRINGZ _                ' __in  LMCSTR      FirstNameToReturn OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetServerGetInfo IMPORT "NETAPI32.DLL" ALIAS "NetServerGetInfo" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR   servername OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD   level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE  *bufptr
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetServerSetInfo IMPORT "NETAPI32.DLL" ALIAS "NetServerSetInfo" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR   servername OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD   level
 , BYVAL buf AS BYTE PTR _                              ' __in  LPBYTE  buf
 , BYREF ParmError AS DWORD _                           ' __out LPDWORD ParmError OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS

'//
'// Temporary hack function.
'//

DECLARE FUNCTION NetServerSetInfoCommandLine IMPORT "NETAPI32.DLL" ALIAS "NetServerSetInfoCommandLine" ( _
   BYVAL argc AS WORD _                                 ' __in WORD  argc
 , BYREF argv AS ANY _                                  ' __in LMSTR argv[]
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetServerDiskEnum IMPORT "NETAPI32.DLL" ALIAS "NetServerDiskEnum" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR       servername OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD       level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE      *bufptr
 , BYVAL prefmaxlen AS DWORD _                          ' __in  DWORD       prefmaxlen
 , BYREF entriesread AS DWORD _                         ' __out LPDWORD     entriesread
 , BYREF totalentries AS DWORD _                        ' __out LPDWORD     totalentries
 , BYREF resume_handle AS DWORD _                       ' __in OUT LPDWORD  resume_handle OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetServerComputerNameAdd IMPORT "NETAPI32.DLL" ALIAS "NetServerComputerNameAdd" ( _
   BYREF ServerName AS WSTRINGZ _                       ' __in LMSTR  ServerName         OPTIONAL
 , BYREF EmulatedDomainName AS WSTRINGZ _               ' __in LMSTR  EmulatedDomainName OPTIONAL
 , BYREF EmulatedServerName AS WSTRINGZ _               ' __in LMSTR  EmulatedServerName
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetServerComputerNameDel IMPORT "NETAPI32.DLL" ALIAS "NetServerComputerNameDel" ( _
   BYREF ServerName AS WSTRINGZ _                       ' __in LMSTR  ServerName        OPTIONAL
 , BYREF EmulatedServerName AS WSTRINGZ _               ' __in LMSTR  EmulatedServerName
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetServerTransportAdd IMPORT "NETAPI32.DLL" ALIAS "NetServerTransportAdd" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR   servername
 , BYVAL level AS DWORD _                               ' __in  DWORD   level
 , BYVAL bufptr AS BYTE PTR _                           ' __in  LPBYTE  bufptr
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetServerTransportAddEx IMPORT "NETAPI32.DLL" ALIAS "NetServerTransportAddEx" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR   servername      OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD   level
 , BYVAL bufptr AS BYTE PTR _                           ' __in  LPBYTE  bufptr
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetServerTransportDel IMPORT "NETAPI32.DLL" ALIAS "NetServerTransportDel" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR   servername
 , BYVAL level AS DWORD _                               ' __in  DWORD   level
 , BYVAL bufptr AS BYTE PTR _                           ' __in  LPBYTE  bufptr
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetServerTransportEnum IMPORT "NETAPI32.DLL" ALIAS "NetServerTransportEnum" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR       servername
 , BYVAL level AS DWORD _                               ' __in  DWORD       level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE      *bufptr
 , BYVAL prefmaxlen AS DWORD _                          ' __in  DWORD       prefmaxlen
 , BYREF entriesread AS DWORD _                         ' __out LPDWORD     entriesread
 , BYREF totalentries AS DWORD _                        ' __out LPDWORD     totalentries
 , BYREF resumehandle AS DWORD _                        ' __in OUT LPDWORD  resumehandle
 ) AS DWORD                                             ' NET_API_STATUS

'//
'// The following function can be called by Win NT services to register
'// their service type.  This function is exported from advapi32.dll.
'// Therefore, if this is the only function called by that service, then
'// it is not necessary to link to netapi32.lib.
'//

DECLARE FUNCTION SetServiceBits IMPORT "ADVAPI32.DLL" ALIAS "SetServiceBits" ( _
   BYVAL hServiceStatus AS DWORD _                      ' __in SERVICE_STATUS_HANDLE    hServiceStatus
 , BYVAL dwServiceBits AS DWORD _                       ' __in DWORD                    dwServiceBits
 , BYVAL bSetBitsOn AS LONG _                           ' __in BOOL                     bSetBitsOn
 , BYVAL bUpdateImmediately AS LONG _                   ' __in BOOL                     bUpdateImmediately
 ) AS LONG                                              ' BOOL

'//
'// Data Structures - SERVER
'//

' // Size = 8 bytes
TYPE SERVER_INFO_100 DWORD
   sv100_platform_id   AS DWORD          ' DWORD sv100_platform_id
   sv100_name          AS WSTRINGZ PTR   ' LMSTR sv100_name
END TYPE

' // Size = 24 bytes
TYPE SERVER_INFO_101 DWORD
   sv101_platform_id   AS DWORD          ' DWORD sv101_platform_id
   sv101_name          AS WSTRINGZ PTR   ' LMSTR sv101_name
   sv101_version_major AS DWORD          ' DWORD sv101_version_major
   sv101_version_minor AS DWORD          ' DWORD sv101_version_minor
   sv101_type          AS DWORD          ' DWORD sv101_type
   sv101_comment       AS WSTRINGZ PTR   ' LMSTR sv101_comment
END TYPE

' // Size = 52 bytes
TYPE SERVER_INFO_102 DWORD
   sv102_platform_id   AS DWORD          ' DWORD sv102_platform_id
   sv102_name          AS WSTRINGZ PTR   ' LMSTR sv102_name
   sv102_version_major AS DWORD          ' DWORD sv102_version_major
   sv102_version_minor AS DWORD          ' DWORD sv102_version_minor
   sv102_type          AS DWORD          ' DWORD sv102_type
   sv102_comment       AS WSTRINGZ PTR   ' LMSTR sv102_comment
   sv102_users         AS DWORD          ' DWORD sv102_users
   sv102_disc          AS DWORD          ' LONG  sv102_disc
   sv102_hidden        AS LONG           ' BOOL  sv102_hidden
   sv102_announce      AS DWORD          ' DWORD sv102_announce
   sv102_anndelta      AS DWORD          ' DWORD sv102_anndelta
   sv102_licenses      AS DWORD          ' DWORD sv102_licenses
   sv102_userpath      AS WSTRINGZ PTR   ' LMSTR sv102_userpath
END TYPE

' // Size = 56 bytes
TYPE SERVER_INFO_103 DWORD
   sv103_platform_id   AS DWORD          ' DWORD sv103_platform_id
   sv103_name          AS WSTRINGZ PTR   ' LMSTR sv103_name
   sv103_version_major AS DWORD          ' DWORD sv103_version_major
   sv103_version_minor AS DWORD          ' DWORD sv103_version_minor
   sv103_type          AS DWORD          ' DWORD sv103_type
   sv103_comment       AS WSTRINGZ PTR   ' LMSTR sv103_comment
   sv103_users         AS DWORD          ' DWORD sv103_users
   sv103_disc          AS LONG           ' LONG  sv103_disc
   sv103_hidden        AS LONG           ' BOOL  sv103_hidden
   sv103_announce      AS DWORD          ' DWORD sv103_announce
   sv103_anndelta      AS DWORD          ' DWORD sv103_anndelta
   sv103_licenses      AS DWORD          ' DWORD sv103_licenses
   sv103_userpath      AS WSTRINGZ PTR   ' LMSTR sv103_userpath
   sv103_capabilities  AS DWORD          ' DWORD sv103_capabilities
END TYPE

' // Size = 124 bytes
TYPE SERVER_INFO_402 DWORD
   sv402_ulist_mtime   AS DWORD          ' DWORD sv402_ulist_mtime
   sv402_glist_mtime   AS DWORD          ' DWORD sv402_glist_mtime
   sv402_alist_mtime   AS DWORD          ' DWORD sv402_alist_mtime
   sv402_alerts        AS WSTRINGZ PTR   ' LMSTR sv402_alerts
   sv402_security      AS DWORD          ' DWORD sv402_security
   sv402_numadmin      AS DWORD          ' DWORD sv402_numadmin
   sv402_lanmask       AS DWORD          ' DWORD sv402_numadmin
   sv402_guestacct     AS WSTRINGZ PTR   ' LMSTR sv402_guestacct
   sv402_chdevs        AS DWORD          ' DWORD sv402_chdevs
   sv402_chdevq        AS DWORD          ' DWORD sv402_chdevq
   sv402_chdevjobs     AS DWORD          ' DWORD sv402_chdevjobs
   sv402_connections   AS DWORD          ' DWORD sv402_connections
   sv402_shares        AS DWORD          ' DWORD sv402_shares
   sv402_openfiles     AS DWORD          ' DWORD sv402_openfiles
   sv402_sessopens     AS DWORD          ' DWORD sv402_sessopens
   sv402_sessvcs       AS DWORD          ' DWORD sv402_sessvcs
   sv402_sessreqs      AS DWORD          ' DWORD sv402_sessreqs
   sv402_opensearch    AS DWORD          ' DWORD sv402_opensearch
   sv402_activelocks   AS DWORD          ' DWORD sv402_activelocks
   sv402_numreqbuf     AS DWORD          ' DWORD sv402_numreqbuf
   sv402_sizreqbuf     AS DWORD          ' DWORD sv402_sizreqbuf
   sv402_numbigbuf     AS DWORD          ' DWORD sv402_numbigbuf
   sv402_numfiletasks  AS DWORD          ' DWORD sv402_numfiletasks
   sv402_alertsched    AS DWORD          ' DWORD sv402_alertsched
   sv402_erroralert    AS DWORD          ' DWORD sv402_erroralert
   sv402_logonalert    AS DWORD          ' DWORD sv402_logonalert
   sv402_accessalert   AS DWORD          ' DWORD sv402_accessalert
   sv402_diskalert     AS DWORD          ' DWORD sv402_diskalert
   sv402_netioalert    AS DWORD          ' DWORD sv402_netioalert
   sv402_maxauditsz    AS DWORD          ' DWORD sv402_maxauditsz
   sv402_srvheuristics AS WSTRINGZ PTR   ' LMSTR sv402_srvheuristics
END TYPE

' // Size = 136 bytes
TYPE SERVER_INFO_403 DWORD
   sv403_ulist_mtime   AS DWORD          ' DWORD sv403_ulist_mtime
   sv403_glist_mtime   AS DWORD          ' DWORD sv403_glist_mtime
   sv403_alist_mtime   AS DWORD          ' DWORD sv403_alist_mtime
   sv403_alerts        AS WSTRINGZ PTR   ' LMSTR sv403_alerts
   sv403_security      AS DWORD          ' DWORD sv403_security
   sv403_numadmin      AS DWORD          ' DWORD sv403_numadmin
   sv403_lanmask       AS DWORD          ' DWORD sv403_lanmask
   sv403_guestacct     AS WSTRINGZ PTR   ' LMSTR sv403_guestacct
   sv403_chdevs        AS DWORD          ' DWORD sv403_chdevs
   sv403_chdevq        AS DWORD          ' DWORD sv403_chdevq
   sv403_chdevjobs     AS DWORD          ' DWORD sv403_chdevjobs
   sv403_connections   AS DWORD          ' DWORD sv403_connections
   sv403_shares        AS DWORD          ' DWORD sv403_shares
   sv403_openfiles     AS DWORD          ' DWORD sv403_openfiles
   sv403_sessopens     AS DWORD          ' DWORD sv403_sessopens
   sv403_sessvcs       AS DWORD          ' DWORD sv403_sessvcs
   sv403_sessreqs      AS DWORD          ' DWORD sv403_sessreqs
   sv403_opensearch    AS DWORD          ' DWORD sv403_opensearch
   sv403_activelocks   AS DWORD          ' DWORD sv403_activelocks
   sv403_numreqbuf     AS DWORD          ' DWORD sv403_numreqbuf
   sv403_sizreqbuf     AS DWORD          ' DWORD sv403_sizreqbuf
   sv403_numbigbuf     AS DWORD          ' DWORD sv403_numbigbuf
   sv403_numfiletasks  AS DWORD          ' DWORD sv403_numfiletasks
   sv403_alertsched    AS DWORD          ' DWORD sv403_alertsched
   sv403_erroralert    AS DWORD          ' DWORD sv403_erroralert
   sv403_logonalert    AS DWORD          ' DWORD sv403_logonalert
   sv403_accessalert   AS DWORD          ' DWORD sv403_accessalert
   sv403_diskalert     AS DWORD          ' DWORD sv403_diskalert
   sv403_netioalert    AS DWORD          ' DWORD sv403_netioalert
   sv403_maxauditsz    AS DWORD          ' DWORD sv403_maxauditsz
   sv403_srvheuristics AS WSTRINGZ PTR   ' LMSTR sv403_srvheuristics
   sv403_auditedevents AS DWORD          ' DWORD sv403_auditedevents
   sv403_autoprofile   AS DWORD          ' DWORD sv403_autoprofile
   sv403_autopath      AS WSTRINGZ PTR   ' LMSTR sv403_autopath
END TYPE

' // Size = 72 bytes
TYPE SERVER_INFO_502 DWORD
   sv502_sessopens              AS DWORD   ' DWORD sv502_sessopens
   sv502_sessvcs                AS DWORD   ' DWORD sv502_sessvcs
   sv502_opensearch             AS DWORD   ' DWORD sv502_opensearch
   sv502_sizreqbuf              AS DWORD   ' DWORD sv502_sizreqbuf
   sv502_initworkitems          AS DWORD   ' DWORD sv502_initworkitems
   sv502_maxworkitems           AS DWORD   ' DWORD sv502_maxworkitems
   sv502_rawworkitems           AS DWORD   ' DWORD sv502_rawworkitems
   sv502_irpstacksize           AS DWORD   ' DWORD sv502_irpstacksize
   sv502_maxrawbuflen           AS DWORD   ' DWORD sv502_maxrawbuflen
   sv502_sessusers              AS DWORD   ' DWORD sv502_sessusers
   sv502_sessconns              AS DWORD   ' DWORD sv502_sessconns
   sv502_maxpagedmemoryusage    AS DWORD   ' DWORD sv502_maxpagedmemoryusage
   sv502_maxnonpagedmemoryusage AS DWORD   ' DWORD sv502_maxnonpagedmemoryusage
   sv502_enablesoftcompat       AS LONG    ' BOOL  sv502_enablesoftcompat
   sv502_enableforcedlogoff     AS LONG    ' BOOL  sv502_enableforcedlogoff
   sv502_timesource             AS LONG    ' BOOL  sv502_timesource
   sv502_acceptdownlevelapis    AS LONG    ' BOOL  sv502_acceptdownlevelapis
   sv502_lmannounce             AS LONG    ' BOOL  sv502_lmannounce
END TYPE

' // Size = 168 bytes
TYPE SERVER_INFO_503 DWORD
   sv503_sessopens               AS DWORD          ' DWORD sv503_sessopens
   sv503_sessvcs                 AS DWORD          ' DWORD sv503_sessvcs
   sv503_opensearch              AS DWORD          ' DWORD sv503_opensearch
   sv503_sizreqbuf               AS DWORD          ' DWORD sv503_sizreqbuf
   sv503_initworkitems           AS DWORD          ' DWORD sv503_initworkitems
   sv503_maxworkitems            AS DWORD          ' DWORD sv503_maxworkitems
   sv503_rawworkitems            AS DWORD          ' DWORD sv503_rawworkitems
   sv503_irpstacksize            AS DWORD          ' DWORD sv503_irpstacksize
   sv503_maxrawbuflen            AS DWORD          ' DWORD sv503_maxrawbuflen
   sv503_sessusers               AS DWORD          ' DWORD sv503_sessusers
   sv503_sessconns               AS DWORD          ' DWORD sv503_sessconns
   sv503_maxpagedmemoryusage     AS DWORD          ' DWORD sv503_maxpagedmemoryusage
   sv503_maxnonpagedmemoryusage  AS DWORD          ' DWORD sv503_maxnonpagedmemoryusage
   sv503_enablesoftcompat        AS LONG           ' BOOL  sv503_enablesoftcompat
   sv503_enableforcedlogoff      AS LONG           ' BOOL  sv503_enableforcedlogoff
   sv503_timesource              AS LONG           ' BOOL  sv503_timesource
   sv503_acceptdownlevelapis     AS LONG           ' BOOL  sv503_acceptdownlevelapis
   sv503_lmannounce              AS LONG           ' BOOL  sv503_lmannounce
   sv503_domain                  AS WSTRINGZ PTR   ' LMSTR sv503_domain
   sv503_maxcopyreadlen          AS DWORD          ' DWORD sv503_maxcopyreadlen
   sv503_maxcopywritelen         AS DWORD          ' DWORD sv503_maxcopywritelen
   sv503_minkeepsearch           AS DWORD          ' DWORD sv503_minkeepsearch
   sv503_maxkeepsearch           AS DWORD          ' DWORD sv503_maxkeepsearch
   sv503_minkeepcomplsearch      AS DWORD          ' DWORD sv503_minkeepcomplsearch
   sv503_maxkeepcomplsearch      AS DWORD          ' DWORD sv503_maxkeepcomplsearch
   sv503_threadcountadd          AS DWORD          ' DWORD sv503_threadcountadd
   sv503_numblockthreads         AS DWORD          ' DWORD sv503_numblockthreads
   sv503_scavtimeout             AS DWORD          ' DWORD sv503_scavtimeout
   sv503_minrcvqueue             AS DWORD          ' DWORD sv503_minrcvqueue
   sv503_minfreeworkitems        AS DWORD          ' DWORD sv503_minfreeworkitems
   sv503_xactmemsize             AS DWORD          ' DWORD sv503_xactmemsize
   sv503_threadpriority          AS DWORD          ' DWORD sv503_threadpriority
   sv503_maxmpxct                AS DWORD          ' DWORD sv503_maxmpxct
   sv503_oplockbreakwait         AS DWORD          ' DWORD sv503_oplockbreakwait
   sv503_oplockbreakresponsewait AS DWORD          ' DWORD sv503_oplockbreakresponsewait
   sv503_enableoplocks           AS LONG           ' BOOL  sv503_enableoplocks
   sv503_enableoplockforceclose  AS LONG           ' BOOL  sv503_enableoplockforceclose
   sv503_enablefcbopens          AS LONG           ' BOOL  sv503_enablefcbopens
   sv503_enableraw               AS LONG           ' BOOL  sv503_enableraw
   sv503_enablesharednetdrives   AS LONG           ' BOOL  sv503_enablesharednetdrives
   sv503_minfreeconnections      AS DWORD          ' DWORD sv503_minfreeconnections
   sv503_maxfreeconnections      AS DWORD          ' DWORD sv503_maxfreeconnections
END TYPE

' // Size = 224 bytes
TYPE SERVER_INFO_599 DWORD
   sv599_sessopens               AS DWORD          ' DWORD sv599_sessopens
   sv599_sessvcs                 AS DWORD          ' DWORD sv599_sessvcs
   sv599_opensearch              AS DWORD          ' DWORD sv599_opensearch
   sv599_sizreqbuf               AS DWORD          ' DWORD sv599_sizreqbuf
   sv599_initworkitems           AS DWORD          ' DWORD sv599_initworkitems
   sv599_maxworkitems            AS DWORD          ' DWORD sv599_maxworkitems
   sv599_rawworkitems            AS DWORD          ' DWORD sv599_rawworkitems
   sv599_irpstacksize            AS DWORD          ' DWORD sv599_irpstacksize
   sv599_maxrawbuflen            AS DWORD          ' DWORD sv599_maxrawbuflen
   sv599_sessusers               AS DWORD          ' DWORD sv599_sessusers
   sv599_sessconns               AS DWORD          ' DWORD sv599_sessconns
   sv599_maxpagedmemoryusage     AS DWORD          ' DWORD sv599_maxpagedmemoryusage
   sv599_maxnonpagedmemoryusage  AS DWORD          ' DWORD sv599_maxnonpagedmemoryusage
   sv599_enablesoftcompat        AS LONG           ' BOOL  sv599_enablesoftcompat
   sv599_enableforcedlogoff      AS LONG           ' BOOL  sv599_enableforcedlogoff
   sv599_timesource              AS LONG           ' BOOL  sv599_timesource
   sv599_acceptdownlevelapis     AS LONG           ' BOOL  sv599_acceptdownlevelapis
   sv599_lmannounce              AS LONG           ' BOOL  sv599_lmannounce
   sv599_domain                  AS WSTRINGZ PTR   ' LMSTR sv599_domain
   sv599_maxcopyreadlen          AS DWORD          ' DWORD sv599_maxcopyreadlen
   sv599_maxcopywritelen         AS DWORD          ' DWORD sv599_maxcopywritelen
   sv599_minkeepsearch           AS DWORD          ' DWORD sv599_minkeepsearch
   sv599_maxkeepsearch           AS DWORD          ' DWORD sv599_maxkeepsearch
   sv599_minkeepcomplsearch      AS DWORD          ' DWORD sv599_minkeepcomplsearch
   sv599_maxkeepcomplsearch      AS DWORD          ' DWORD sv599_maxkeepcomplsearch
   sv599_threadcountadd          AS DWORD          ' DWORD sv599_threadcountadd
   sv599_numblockthreads         AS DWORD          ' DWORD sv599_numblockthreads
   sv599_scavtimeout             AS DWORD          ' DWORD sv599_scavtimeout
   sv599_minrcvqueue             AS DWORD          ' DWORD sv599_minrcvqueue
   sv599_minfreeworkitems        AS DWORD          ' DWORD sv599_minfreeworkitems
   sv599_xactmemsize             AS DWORD          ' DWORD sv599_xactmemsize
   sv599_threadpriority          AS DWORD          ' DWORD sv599_threadpriority
   sv599_maxmpxct                AS DWORD          ' DWORD sv599_maxmpxct
   sv599_oplockbreakwait         AS DWORD          ' DWORD sv599_oplockbreakwait
   sv599_oplockbreakresponsewait AS DWORD          ' DWORD sv599_oplockbreakresponsewait
   sv599_enableoplocks           AS LONG           ' BOOL  sv599_enableoplocks
   sv599_enableoplockforceclose  AS LONG           ' BOOL  sv599_enableoplockforceclose
   sv599_enablefcbopens          AS LONG           ' BOOL  sv599_enablefcbopens
   sv599_enableraw               AS LONG           ' BOOL  sv599_enableraw
   sv599_enablesharednetdrives   AS LONG           ' BOOL  sv599_enablesharednetdrives
   sv599_minfreeconnections      AS DWORD          ' DWORD sv599_minfreeconnections
   sv599_maxfreeconnections      AS DWORD          ' DWORD sv599_maxfreeconnections
   sv599_initsesstable           AS DWORD          ' DWORD sv599_initsesstable
   sv599_initconntable           AS DWORD          ' DWORD sv599_initconntable
   sv599_initfiletable           AS DWORD          ' DWORD sv599_initfiletable
   sv599_initsearchtable         AS DWORD          ' DWORD sv599_initsearchtable
   sv599_alertschedule           AS DWORD          ' DWORD sv599_alertschedule
   sv599_errorthreshold          AS DWORD          ' DWORD sv599_errorthreshold
   sv599_networkerrorthreshold   AS DWORD          ' DWORD sv599_networkerrorthreshold
   sv599_diskspacethreshold      AS DWORD          ' DWORD sv599_diskspacethreshold
   sv599_reserved                AS DWORD          ' DWORD sv599_reserved
   sv599_maxlinkdelay            AS DWORD          ' DWORD sv599_maxlinkdelay
   sv599_minlinkthroughput       AS DWORD          ' DWORD sv599_minlinkthroughput
   sv599_linkinfovalidtime       AS DWORD          ' DWORD sv599_linkinfovalidtime
   sv599_scavqosinfoupdatetime   AS DWORD          ' DWORD sv599_scavqosinfoupdatetime
   sv599_maxworkitemidletime     AS DWORD          ' DWORD sv599_maxworkitemidletime
END TYPE

' // Size = 184 bytes
TYPE SERVER_INFO_598 DWORD
   sv598_maxrawworkitems                 AS DWORD   ' DWORD sv598_maxrawworkitems
   sv598_maxthreadsperqueue              AS DWORD   ' DWORD sv598_maxthreadsperqueue
   sv598_producttype                     AS DWORD   ' DWORD sv598_producttype
   sv598_serversize                      AS DWORD   ' DWORD sv598_serversize
   sv598_connectionlessautodisc          AS DWORD   ' DWORD sv598_connectionlessautodisc
   sv598_sharingviolationretries         AS DWORD   ' DWORD sv598_sharingviolationretries
   sv598_sharingviolationdelay           AS DWORD   ' DWORD sv598_sharingviolationdelay
   sv598_maxglobalopensearch             AS DWORD   ' DWORD sv598_maxglobalopensearch
   sv598_removeduplicatesearches         AS DWORD   ' DWORD sv598_removeduplicatesearches
   sv598_lockviolationoffset             AS DWORD   ' DWORD sv598_lockviolationoffset
   sv598_lockviolationdelay              AS DWORD   ' DWORD sv598_lockviolationdelay
   sv598_mdlreadswitchover               AS DWORD   ' DWORD sv598_mdlreadswitchover
   sv598_cachedopenlimit                 AS DWORD   ' DWORD sv598_cachedopenlimit
   sv598_otherqueueaffinity              AS DWORD   ' DWORD sv598_otherqueueaffinity
   sv598_restrictnullsessaccess          AS LONG    ' BOOL  sv598_restrictnullsessaccess
   sv598_enablewfw311directipx           AS LONG    ' BOOL  sv598_enablewfw311directipx
   sv598_queuesamplesecs                 AS DWORD   ' DWORD sv598_queuesamplesecs
   sv598_balancecount                    AS DWORD   ' DWORD sv598_balancecount
   sv598_preferredaffinity               AS DWORD   ' DWORD sv598_preferredaffinity
   sv598_maxfreerfcbs                    AS DWORD   ' DWORD sv598_maxfreerfcbs
   sv598_maxfreemfcbs                    AS DWORD   ' DWORD sv598_maxfreemfcbs
   sv598_maxfreelfcbs                    AS DWORD   ' DWORD sv598_maxfreelfcbs
   sv598_maxfreepagedpoolchunks          AS DWORD   ' DWORD sv598_maxfreepagedpoolchunks
   sv598_minpagedpoolchunksize           AS DWORD   ' DWORD sv598_minpagedpoolchunksize
   sv598_maxpagedpoolchunksize           AS DWORD   ' DWORD sv598_maxpagedpoolchunksize
   sv598_sendsfrompreferredprocessor     AS LONG    ' BOOL  sv598_sendsfrompreferredprocessor
   sv598_cacheddirectorylimit            AS DWORD   ' DWORD sv598_cacheddirectorylimit
   sv598_maxcopylength                   AS DWORD   ' DWORD sv598_maxcopylength
   sv598_enablecompression               AS LONG    ' BOOL  sv598_enablecompression
   sv598_autosharewks                    AS LONG    ' BOOL  sv598_autosharewks
   sv598_autoshareserver                 AS LONG    ' BOOL  sv598_autoshareserver
   sv598_enablesecuritysignature         AS LONG    ' BOOL  sv598_enablesecuritysignature
   sv598_requiresecuritysignature        AS LONG    ' BOOL  sv598_requiresecuritysignature
   sv598_minclientbuffersize             AS DWORD   ' DWORD sv598_minclientbuffersize
   sv598_serverguid                      AS GUID    ' GUID  sv598_serverguid
   sv598_ConnectionNoSessionsTimeout     AS DWORD   ' DWORD sv598_ConnectionNoSessionsTimeout
   sv598_IdleThreadTimeOut               AS DWORD   ' DWORD sv598_IdleThreadTimeOut
   sv598_enableW9xsecuritysignature      AS LONG    ' BOOL  sv598_enableW9xsecuritysignature
   sv598_enforcekerberosreauthentication AS LONG    ' BOOL  sv598_enforcekerberosreauthentication
   sv598_disabledos                      AS LONG    ' BOOL  sv598_disabledos
   sv598_lowdiskspaceminimum             AS DWORD   ' DWORD sv598_lowdiskspaceminimum
   sv598_disablestrictnamechecking       AS LONG    ' BOOL  sv598_disablestrictnamechecking
   sv598_enableauthenticateusersharing   AS LONG    ' BOOL  sv598_enableauthenticateusersharing
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1005 DWORD
   sv1005_comment AS WSTRINGZ PTR   ' LMSTR sv1005_comment
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1107 DWORD
   sv1107_users AS DWORD   ' DWORD sv1107_users
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1010 DWORD
   sv1010_disc AS LONG   ' LONG sv1010_disc
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1016 DWORD
   sv1016_hidden AS LONG   ' BOOL sv1016_hidden
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1017 DWORD
   sv1017_announce AS DWORD   ' DWORD sv1017_announce
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1018 DWORD
   sv1018_anndelta AS DWORD   ' DWORD sv1018_anndelta
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1501 DWORD
   sv1501_sessopens AS DWORD   ' DWORD sv1501_sessopens
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1502 DWORD
   sv1502_sessvcs AS DWORD   ' DWORD sv1502_sessvcs
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1503 DWORD
   sv1503_opensearch AS DWORD   ' DWORD sv1503_opensearch
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1506 DWORD
   sv1506_maxworkitems AS DWORD   ' DWORD sv1506_maxworkitems
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1509 DWORD
   sv1509_maxrawbuflen AS DWORD   ' DWORD sv1509_maxrawbuflen
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1510 DWORD
   sv1510_sessusers AS DWORD   ' DWORD sv1510_sessusers
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1511 DWORD
   sv1511_sessconns AS DWORD   ' DWORD sv1511_sessconns;
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1512 DWORD
   sv1512_maxnonpagedmemoryusage AS DWORD   ' DWORD sv1512_maxnonpagedmemoryusage
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1513 DWORD
   sv1513_maxpagedmemoryusage AS DWORD   ' DWORD sv1513_maxpagedmemoryusage
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1514 DWORD
   sv1514_enablesoftcompat AS LONG   ' BOOL sv1514_enablesoftcompat
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1515 DWORD
   sv1515_enableforcedlogoff AS LONG   ' BOOL sv1515_enableforcedlogoff
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1516 DWORD
   sv1516_timesource AS LONG   ' BOOL sv1516_timesource
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1518 DWORD
   sv1518_lmannounce AS LONG   ' BOOL sv1518_lmannounce
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1520 DWORD
   sv1520_maxcopyreadlen AS DWORD   ' DWORD sv1520_maxcopyreadlen
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1521 DWORD
   sv1521_maxcopywritelen AS DWORD   ' DWORD sv1521_maxcopywritelen
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1522 DWORD
   sv1522_minkeepsearch AS DWORD   ' DWORD sv1522_minkeepsearch
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1523 DWORD
   sv1523_maxkeepsearch AS DWORD   ' DWORD sv1523_maxkeepsearch
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1524 DWORD
   sv1524_minkeepcomplsearch AS DWORD   ' DWORD sv1524_minkeepcomplsearch
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1525 DWORD
   sv1525_maxkeepcomplsearch AS DWORD   ' DWORD sv1525_maxkeepcomplsearch
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1528 DWORD
   sv1528_scavtimeout AS DWORD   ' DWORD sv1528_scavtimeout
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1529 DWORD
   sv1529_minrcvqueue AS DWORD   ' DWORD sv1529_minrcvqueue
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1530 DWORD
   sv1530_minfreeworkitems AS DWORD   ' DWORD sv1530_minfreeworkitems
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1533 DWORD
   sv1533_maxmpxct AS DWORD   ' DWORD sv1533_maxmpxct
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1534 DWORD
   sv1534_oplockbreakwait AS DWORD   ' DWORD sv1534_oplockbreakwait
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1535 DWORD
   sv1535_oplockbreakresponsewait AS DWORD   ' DWORD sv1535_oplockbreakresponsewait
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1536 DWORD
   sv1536_enableoplocks AS LONG   ' BOOL sv1536_enableoplocks
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1537 DWORD
   sv1537_enableoplockforceclose AS LONG   ' BOOL sv1537_enableoplockforceclose
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1538 DWORD
   sv1538_enablefcbopens AS LONG   ' BOOL sv1538_enablefcbopens
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1539 DWORD
   sv1539_enableraw AS LONG   ' BOOL sv1539_enableraw
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1540 DWORD
   sv1540_enablesharednetdrives AS LONG   ' BOOL sv1540_enablesharednetdrives
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1541 DWORD
   sv1541_minfreeconnections AS LONG   ' BOOL sv1541_minfreeconnections
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1542 DWORD
   sv1542_maxfreeconnections AS LONG   ' BOOL sv1542_maxfreeconnections
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1543 DWORD
   sv1543_initsesstable AS DWORD   ' DWORD sv1543_initsesstable
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1544 DWORD
   sv1544_initconntable AS DWORD   ' DWORD sv1544_initconntable
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1545 DWORD
   sv1545_initfiletable AS DWORD   ' DWORD sv1545_initfiletable
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1546 DWORD
   sv1546_initsearchtable AS DWORD   ' DWORD sv1546_initsearchtable
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1547 DWORD
   sv1547_alertschedule AS DWORD   ' DWORD sv1547_alertschedule
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1548 DWORD
   sv1548_errorthreshold AS DWORD   ' DWORD sv1548_errorthreshold
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1549 DWORD
   sv1549_networkerrorthreshold AS DWORD   ' DWORD sv1549_networkerrorthreshold
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1550 DWORD
   sv1550_diskspacethreshold AS DWORD   ' DWORD sv1550_diskspacethreshold
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1552 DWORD
   sv1552_maxlinkdelay AS DWORD   ' DWORD sv1552_maxlinkdelay
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1553 DWORD
   sv1553_minlinkthroughput AS DWORD   ' DWORD sv1553_minlinkthroughput
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1554 DWORD
   sv1554_linkinfovalidtime AS DWORD   ' DWORD sv1554_linkinfovalidtime
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1555 DWORD
   sv1555_scavqosinfoupdatetime AS DWORD   ' DWORD sv1555_scavqosinfoupdatetime
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1556 DWORD
   sv1556_maxworkitemidletime AS DWORD   ' DWORD sv1556_maxworkitemidletime
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1557 DWORD
   sv1557_maxrawworkitems AS DWORD   ' DWORD sv1557_maxrawworkitems
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1560 DWORD
   sv1560_producttype AS DWORD   ' DWORD sv1560_producttype
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1561 DWORD
   sv1561_serversize AS DWORD   ' DWORD sv1561_serversize
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1562 DWORD
   sv1562_connectionlessautodisc AS DWORD   ' DWORD sv1562_connectionlessautodisc
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1563 DWORD
   sv1563_sharingviolationretries AS DWORD   ' DWORD sv1563_sharingviolationretries
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1564 DWORD
   sv1564_sharingviolationdelay AS DWORD   ' DWORD sv1564_sharingviolationdelay
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1565 DWORD
   sv1565_maxglobalopensearch AS DWORD   ' DWORD sv1565_maxglobalopensearch
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1566 DWORD
   sv1566_removeduplicatesearches AS LONG   ' BOOL sv1566_removeduplicatesearches
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1567 DWORD
   sv1567_lockviolationretries AS DWORD   ' DWORD sv1567_lockviolationretries
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1568 DWORD
   sv1568_lockviolationoffset AS DWORD   ' DWORD sv1568_lockviolationoffset
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1569 DWORD
   sv1569_lockviolationdelay AS DWORD   ' DWORD sv1569_lockviolationdelay
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1570 DWORD
   sv1570_mdlreadswitchover AS DWORD   ' DWORD sv1570_mdlreadswitchover
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1571 DWORD
   sv1571_cachedopenlimit AS DWORD   ' DWORD sv1571_cachedopenlimit
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1572 DWORD
   sv1572_criticalthreads AS DWORD   ' DWORD sv1572_criticalthreads
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1573 DWORD
   sv1573_restrictnullsessaccess AS DWORD   ' DWORD sv1573_restrictnullsessaccess
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1574 DWORD
   sv1574_enablewfw311directipx AS DWORD   ' DWORD sv1574_enablewfw311directipx
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1575 DWORD
   sv1575_otherqueueaffinity AS DWORD   ' DWORD sv1575_otherqueueaffinity
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1576 DWORD
   sv1576_queuesamplesecs AS DWORD   ' DWORD sv1576_queuesamplesecs
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1577 DWORD
   sv1577_balancecount AS DWORD   ' DWORD sv1577_balancecount
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1578 DWORD
   sv1578_preferredaffinity AS DWORD   ' DWORD sv1578_preferredaffinity
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1579 DWORD
   sv1579_maxfreerfcbs AS DWORD   ' DWORD sv1579_maxfreerfcbs
END TYPE

'typedef struct _SERVER_INFO_1580 {
'    ;
'} SERVER_INFO_1580, *PSERVER_INFO_1580, *LPSERVER_INFO_1580;

' // Size = 4 bytes
TYPE SERVER_INFO_1580 DWORD
   sv1580_maxfreemfcbs AS DWORD   ' DWORD sv1580_maxfreemfcbs
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1581 DWORD
   sv1581_maxfreemlcbs AS DWORD   ' DWORD sv1581_maxfreemlcbs
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1582 DWORD
   sv1582_maxfreepagedpoolchunks AS DWORD   ' DWORD sv1582_maxfreepagedpoolchunks
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1583 DWORD
   sv1583_minpagedpoolchunksize AS DWORD   ' DWORD sv1583_minpagedpoolchunksize
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1584 DWORD
   sv1584_maxpagedpoolchunksize AS DWORD   ' DWORD sv1584_maxpagedpoolchunksize
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1585 DWORD
   sv1585_sendsfrompreferredprocessor AS LONG   ' BOOL sv1585_sendsfrompreferredprocessor
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1586 DWORD
   sv1586_maxthreadsperqueue AS DWORD   ' DWORD sv1586_maxthreadsperqueue
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1587 DWORD
   sv1587_cacheddirectorylimit AS DWORD   ' DWORD sv1587_cacheddirectorylimit
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1588 DWORD
   sv1588_maxcopylength AS DWORD   ' DWORD sv1588_maxcopylength
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1590 DWORD
   sv1590_enablecompression AS DWORD   ' DWORD sv1590_enablecompression
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1591 DWORD
   sv1591_autosharewks AS DWORD   ' DWORD sv1591_autosharewks
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1592 DWORD
   sv1592_autosharewks AS DWORD   ' DWORD sv1592_autosharewks
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1593 DWORD
   sv1593_enablesecuritysignature AS DWORD   'DWORD sv1593_enablesecuritysignature
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1594 DWORD
   sv1594_requiresecuritysignature AS DWORD   ' DWORD sv1594_requiresecuritysignature
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1595 DWORD
   sv1595_minclientbuffersize AS DWORD   ' DWORD sv1595_minclientbuffersize
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1596 DWORD
   sv1596_ConnectionNoSessionsTimeout AS DWORD   ' DWORD sv1596_ConnectionNoSessionsTimeout
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1597 DWORD
   sv1597_IdleThreadTimeOut AS DWORD   ' DWORD sv1597_IdleThreadTimeOut
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1598 DWORD
   sv1598_enableW9xsecuritysignature AS DWORD   ' DWORD sv1598_enableW9xsecuritysignature
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1599 DWORD
   sv1598_enforcekerberosreauthentication AS DWORD   ' DWORD sv1598_enforcekerberosreauthentication
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1600 DWORD
   sv1598_disabledos AS DWORD   ' DWORD sv1598_disabledos
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1601 DWORD
   sv1598_lowdiskspaceminimum AS DWORD   ' DWORD sv1598_lowdiskspaceminimum
END TYPE

' // Size = 4 bytes
TYPE SERVER_INFO_1602 DWORD
   sv_1598_disablestrictnamechecking AS DWORD   ' DWORD sv_1598_disablestrictnamechecking
END TYPE

'//
'// A special structure definition is required in order for this
'// structure to work with RPC.  The problem is that having addresslength
'// indicate the number of bytes in address means that RPC must know the
'// link between the two.
'//

' // Size = 20 bytes
TYPE SERVER_TRANSPORT_INFO_0 DWORD
   svti0_numberofvcs            AS DWORD          ' DWORD  svti0_numberofvcs
   svti0_transportname          AS WSTRINGZ PTR   ' LMSTR  svti0_transportname
   svti0_transportaddress       AS BYTE PTR       ' LPBYTE svti0_transportaddress
   svti0_transportaddresslength AS DWORD          ' DWORD  svti0_transportaddresslength
   svti0_networkaddress         AS WSTRINGZ PTR   ' LMSTR  svti0_networkaddress
END TYPE

' // Size = 24 bytes
TYPE SERVER_TRANSPORT_INFO_1 DWORD
   svti1_numberofvcs            AS DWORD          ' DWORD  svti1_numberofvcs
   svti1_transportname          AS WSTRINGZ PTR   ' LMSTR  svti1_transportname
   svti1_transportaddress       AS BYTE PTR       ' LPBYTE svti1_transportaddress
   svti1_transportaddresslength AS DWORD          ' DWORD  svti1_transportaddresslength
   svti1_networkaddress         AS WSTRINGZ PTR   ' LMSTR  svti1_networkaddress
   svti1_domain                 AS WSTRINGZ PTR   ' LMSTR  svti1_domain
END TYPE

' // Size = 28 bytes
TYPE SERVER_TRANSPORT_INFO_2 DWORD
   svti2_numberofvcs            AS DWORD          ' DWORD  svti2_numberofvcs
   svti2_transportname          AS WSTRINGZ PTR   ' LMSTR  svti2_transportname
   svti2_transportaddress       AS BYTE PTR       ' LPBYTE svti2_transportaddress
   svti2_transportaddresslength AS DWORD          ' DWORD  svti2_transportaddresslength
   svti2_networkaddress         AS WSTRINGZ PTR   ' LMSTR  svti2_networkaddress
   svti2_domain                 AS WSTRINGZ PTR   ' LMSTR  svti2_domain
   svti2_flags                  AS DWORD          ' ULONG  svti2_flags
END TYPE

' // Size = 288 bytes
TYPE SERVER_TRANSPORT_INFO_3 DWORD
   svti3_numberofvcs            AS DWORD              ' DWORD  svti3_numberofvcs
   svti3_transportname          AS WSTRINGZ PTR       ' LMSTR  svti3_transportname
   svti3_transportaddress       AS BYTE PTR           ' LPBYTE svti3_transportaddress
   svti3_transportaddresslength AS DWORD              ' DWORD  svti3_transportaddresslength
   svti3_networkaddress         AS WSTRINGZ PTR       ' LMSTR  svti3_networkaddress
   svti3_domain                 AS WSTRINGZ PTR       ' LMSTR  svti3_domain
   svti3_flags                  AS DWORD              ' ULONG  svti3_flags
   svti3_passwordlength         AS DWORD              ' DWORD  svti3_passwordlength
#IF %DEF(%USEPBDECL)
   svti3_password(255)          AS BYTE
#ELSE
   svti3_password               AS STRING * 256       ' BYTE   svti3_password[ 256 ]
#ENDIF
END TYPE

'//
'// Defines - SERVER
'//

'//
'// The platform ID indicates the levels to use for platform-specific
'// information.
'//

%SV_PLATFORM_ID_OS2 = 400
%SV_PLATFORM_ID_NT  = 500

'//
'//      Mask to be applied to svX_version_major in order to obtain
'//      the major version number.
'//

%MAJOR_VERSION_MASK = &H0F

'//
'//      Bit-mapped values for svX_type fields. X = 1, 2 or 3.
'//

%SV_TYPE_WORKSTATION         = &H00000001???
%SV_TYPE_SERVER              = &H00000002???
%SV_TYPE_SQLSERVER           = &H00000004???
%SV_TYPE_DOMAIN_CTRL         = &H00000008???
%SV_TYPE_DOMAIN_BAKCTRL      = &H00000010???
%SV_TYPE_TIME_SOURCE         = &H00000020???
%SV_TYPE_AFP                 = &H00000040???
%SV_TYPE_NOVELL              = &H00000080???
%SV_TYPE_DOMAIN_MEMBER       = &H00000100???
%SV_TYPE_PRINTQ_SERVER       = &H00000200???
%SV_TYPE_DIALIN_SERVER       = &H00000400???
%SV_TYPE_XENIX_SERVER        = &H00000800???
%SV_TYPE_SERVER_UNIX         = %SV_TYPE_XENIX_SERVER
%SV_TYPE_NT                  = &H00001000???
%SV_TYPE_WFW                 = &H00002000???
%SV_TYPE_SERVER_MFPN         = &H00004000???
%SV_TYPE_SERVER_NT           = &H00008000???
%SV_TYPE_POTENTIAL_BROWSER   = &H00010000???
%SV_TYPE_BACKUP_BROWSER      = &H00020000???
%SV_TYPE_MASTER_BROWSER      = &H00040000???
%SV_TYPE_DOMAIN_MASTER       = &H00080000???
%SV_TYPE_SERVER_OSF          = &H00100000???
%SV_TYPE_SERVER_VMS          = &H00200000???
%SV_TYPE_WINDOWS             = &H00400000??? ' /* Windows95 and above */
%SV_TYPE_DFS                 = &H00800000??? ' /* Root of a DFS tree */
%SV_TYPE_CLUSTER_NT          = &H01000000??? ' /* NT Cluster */
%SV_TYPE_TERMINALSERVER      = &H02000000??? ' /* Terminal Server(Hydra) */
%SV_TYPE_CLUSTER_VS_NT       = &H04000000??? ' /* NT Cluster Virtual Server Name */
%SV_TYPE_DCE                 = &H10000000??? ' /* IBM DSS (Directory and Security Services) or equivalent */
%SV_TYPE_ALTERNATE_XPORT     = &H20000000??? ' /* return list for alternate transport */
%SV_TYPE_LOCAL_LIST_ONLY     = &H40000000??? ' /* Return local list only */
%SV_TYPE_DOMAIN_ENUM         = &H80000000???
%SV_TYPE_ALL                 = &HFFFFFFFF??? ' /* handy for NetServerEnum2 */

'//
'//      Special value for sv102_disc that specifies infinite disconnect
'//      time.
'//

%SV_NODISC           = -1&  ' /* No autodisconnect timeout enforced */

'//
'//      Values of svX_security field. X = 2 or 3.
'//

%SV_USERSECURITY    = 1
%SV_SHARESECURITY   = 0

'//
'//      Values of svX_hidden field. X = 2 or 3.
'//

%SV_HIDDEN      = 1
%SV_VISIBLE     = 0

'//
'//      Values for ParmError parameter to NetServerSetInfo.
'//

%SV_PLATFORM_ID_PARMNUM          = 101
%SV_NAME_PARMNUM                 = 102
%SV_VERSION_MAJOR_PARMNUM        = 103
%SV_VERSION_MINOR_PARMNUM        = 104
%SV_TYPE_PARMNUM                 = 105
%SV_COMMENT_PARMNUM              = 5
%SV_USERS_PARMNUM                = 107
%SV_DISC_PARMNUM                 = 10
%SV_HIDDEN_PARMNUM               = 16
%SV_ANNOUNCE_PARMNUM             = 17
%SV_ANNDELTA_PARMNUM             = 18
%SV_USERPATH_PARMNUM             = 112

%SV_ULIST_MTIME_PARMNUM          = 401
%SV_GLIST_MTIME_PARMNUM          = 402
%SV_ALIST_MTIME_PARMNUM          = 403
%SV_ALERTS_PARMNUM               = 11
%SV_SECURITY_PARMNUM             = 405
%SV_NUMADMIN_PARMNUM             = 406
%SV_LANMASK_PARMNUM              = 407
%SV_GUESTACC_PARMNUM             = 408
%SV_CHDEVQ_PARMNUM               = 410
%SV_CHDEVJOBS_PARMNUM            = 411
%SV_CONNECTIONS_PARMNUM          = 412
%SV_SHARES_PARMNUM               = 413
%SV_OPENFILES_PARMNUM            = 414
%SV_SESSREQS_PARMNUM             = 417
%SV_ACTIVELOCKS_PARMNUM          = 419
%SV_NUMREQBUF_PARMNUM            = 420
%SV_NUMBIGBUF_PARMNUM            = 422
%SV_NUMFILETASKS_PARMNUM         = 423
%SV_ALERTSCHED_PARMNUM           = 37
%SV_ERRORALERT_PARMNUM           = 38
%SV_LOGONALERT_PARMNUM           = 39
%SV_ACCESSALERT_PARMNUM          = 40
%SV_DISKALERT_PARMNUM            = 41
%SV_NETIOALERT_PARMNUM           = 42
%SV_MAXAUDITSZ_PARMNUM           = 43
%SV_SRVHEURISTICS_PARMNUM        = 431

%SV_SESSOPENS_PARMNUM                       = 501
%SV_SESSVCS_PARMNUM                         = 502
%SV_OPENSEARCH_PARMNUM                      = 503
%SV_SIZREQBUF_PARMNUM                       = 504
%SV_INITWORKITEMS_PARMNUM                   = 505
%SV_MAXWORKITEMS_PARMNUM                    = 506
%SV_RAWWORKITEMS_PARMNUM                    = 507
%SV_IRPSTACKSIZE_PARMNUM                    = 508
%SV_MAXRAWBUFLEN_PARMNUM                    = 509
%SV_SESSUSERS_PARMNUM                       = 510
%SV_SESSCONNS_PARMNUM                       = 511
%SV_MAXNONPAGEDMEMORYUSAGE_PARMNUM          = 512
%SV_MAXPAGEDMEMORYUSAGE_PARMNUM             = 513
%SV_ENABLESOFTCOMPAT_PARMNUM                = 514
%SV_ENABLEFORCEDLOGOFF_PARMNUM              = 515
%SV_TIMESOURCE_PARMNUM                      = 516
%SV_ACCEPTDOWNLEVELAPIS_PARMNUM             = 517
%SV_LMANNOUNCE_PARMNUM                      = 518
%SV_DOMAIN_PARMNUM                          = 519
%SV_MAXCOPYREADLEN_PARMNUM                  = 520
%SV_MAXCOPYWRITELEN_PARMNUM                 = 521
%SV_MINKEEPSEARCH_PARMNUM                   = 522
%SV_MAXKEEPSEARCH_PARMNUM                   = 523
%SV_MINKEEPCOMPLSEARCH_PARMNUM              = 524
%SV_MAXKEEPCOMPLSEARCH_PARMNUM              = 525
%SV_THREADCOUNTADD_PARMNUM                  = 526
%SV_NUMBLOCKTHREADS_PARMNUM                 = 527
%SV_SCAVTIMEOUT_PARMNUM                     = 528
%SV_MINRCVQUEUE_PARMNUM                     = 529
%SV_MINFREEWORKITEMS_PARMNUM                = 530
%SV_XACTMEMSIZE_PARMNUM                     = 531
%SV_THREADPRIORITY_PARMNUM                  = 532
%SV_MAXMPXCT_PARMNUM                        = 533
%SV_OPLOCKBREAKWAIT_PARMNUM                 = 534
%SV_OPLOCKBREAKRESPONSEWAIT_PARMNUM         = 535
%SV_ENABLEOPLOCKS_PARMNUM                   = 536
%SV_ENABLEOPLOCKFORCECLOSE_PARMNUM          = 537
%SV_ENABLEFCBOPENS_PARMNUM                  = 538
%SV_ENABLERAW_PARMNUM                       = 539
%SV_ENABLESHAREDNETDRIVES_PARMNUM           = 540
%SV_MINFREECONNECTIONS_PARMNUM              = 541
%SV_MAXFREECONNECTIONS_PARMNUM              = 542
%SV_INITSESSTABLE_PARMNUM                   = 543
%SV_INITCONNTABLE_PARMNUM                   = 544
%SV_INITFILETABLE_PARMNUM                   = 545
%SV_INITSEARCHTABLE_PARMNUM                 = 546
%SV_ALERTSCHEDULE_PARMNUM                   = 547
%SV_ERRORTHRESHOLD_PARMNUM                  = 548
%SV_NETWORKERRORTHRESHOLD_PARMNUM           = 549
%SV_DISKSPACETHRESHOLD_PARMNUM              = 550
%SV_MAXLINKDELAY_PARMNUM                    = 552
%SV_MINLINKTHROUGHPUT_PARMNUM               = 553
%SV_LINKINFOVALIDTIME_PARMNUM               = 554
%SV_SCAVQOSINFOUPDATETIME_PARMNUM           = 555
%SV_MAXWORKITEMIDLETIME_PARMNUM             = 556
%SV_MAXRAWWORKITEMS_PARMNUM                 = 557
%SV_PRODUCTTYPE_PARMNUM                     = 560
%SV_SERVERSIZE_PARMNUM                      = 561
%SV_CONNECTIONLESSAUTODISC_PARMNUM          = 562
%SV_SHARINGVIOLATIONRETRIES_PARMNUM         = 563
%SV_SHARINGVIOLATIONDELAY_PARMNUM           = 564
%SV_MAXGLOBALOPENSEARCH_PARMNUM             = 565
%SV_REMOVEDUPLICATESEARCHES_PARMNUM         = 566
%SV_LOCKVIOLATIONRETRIES_PARMNUM            = 567
%SV_LOCKVIOLATIONOFFSET_PARMNUM             = 568
%SV_LOCKVIOLATIONDELAY_PARMNUM              = 569
%SV_MDLREADSWITCHOVER_PARMNUM               = 570
%SV_CACHEDOPENLIMIT_PARMNUM                 = 571
%SV_CRITICALTHREADS_PARMNUM                 = 572
%SV_RESTRICTNULLSESSACCESS_PARMNUM          = 573
%SV_ENABLEWFW311DIRECTIPX_PARMNUM           = 574
%SV_OTHERQUEUEAFFINITY_PARMNUM              = 575
%SV_QUEUESAMPLESECS_PARMNUM                 = 576
%SV_BALANCECOUNT_PARMNUM                    = 577
%SV_PREFERREDAFFINITY_PARMNUM               = 578
%SV_MAXFREERFCBS_PARMNUM                    = 579
%SV_MAXFREEMFCBS_PARMNUM                    = 580
%SV_MAXFREELFCBS_PARMNUM                    = 581
%SV_MAXFREEPAGEDPOOLCHUNKS_PARMNUM          = 582
%SV_MINPAGEDPOOLCHUNKSIZE_PARMNUM           = 583
%SV_MAXPAGEDPOOLCHUNKSIZE_PARMNUM           = 584
%SV_SENDSFROMPREFERREDPROCESSOR_PARMNUM     = 585
%SV_MAXTHREADSPERQUEUE_PARMNUM              = 586
%SV_CACHEDDIRECTORYLIMIT_PARMNUM            = 587
%SV_MAXCOPYLENGTH_PARMNUM                   = 588
%SV_ENABLECOMPRESSION_PARMNUM               = 590
%SV_AUTOSHAREWKS_PARMNUM                    = 591
%SV_AUTOSHARESERVER_PARMNUM                 = 592
%SV_ENABLESECURITYSIGNATURE_PARMNUM         = 593
%SV_REQUIRESECURITYSIGNATURE_PARMNUM        = 594
%SV_MINCLIENTBUFFERSIZE_PARMNUM             = 595
%SV_CONNECTIONNOSESSIONSTIMEOUT_PARMNUM     = 596
%SV_IDLETHREADTIMEOUT_PARMNUM               = 597
%SV_ENABLEW9XSECURITYSIGNATURE_PARMNUM      = 598
%SV_ENFORCEKERBEROSREAUTHENTICATION_PARMNUM = 599
%SV_DISABLEDOS_PARMNUM                      = 600
%SV_LOWDISKSPACEMINIMUM_PARMNUM             = 601
%SV_DISABLESTRICTNAMECHECKING_PARMNUM       = 602
%SV_ENABLEAUTHENTICATEUSERSHARING_PARMNUM   = 603

'//
'// Single-field infolevels for NetServerSetInfo.
'//

%SV_COMMENT_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_COMMENT_PARMNUM
%SV_USERS_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_USERS_PARMNUM
%SV_DISC_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_DISC_PARMNUM
%SV_HIDDEN_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_HIDDEN_PARMNUM
%SV_ANNOUNCE_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_ANNOUNCE_PARMNUM
%SV_ANNDELTA_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_ANNDELTA_PARMNUM
%SV_SESSOPENS_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_SESSOPENS_PARMNUM
%SV_SESSVCS_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_SESSVCS_PARMNUM
%SV_OPENSEARCH_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_OPENSEARCH_PARMNUM
%SV_MAXWORKITEMS_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MAXWORKITEMS_PARMNUM
%SV_MAXRAWBUFLEN_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MAXRAWBUFLEN_PARMNUM
%SV_SESSUSERS_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_SESSUSERS_PARMNUM
%SV_SESSCONNS_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_SESSCONNS_PARMNUM
%SV_MAXNONPAGEDMEMORYUSAGE_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MAXNONPAGEDMEMORYUSAGE_PARMNUM
%SV_MAXPAGEDMEMORYUSAGE_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MAXPAGEDMEMORYUSAGE_PARMNUM
%SV_ENABLESOFTCOMPAT_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_ENABLESOFTCOMPAT_PARMNUM
%SV_ENABLEFORCEDLOGOFF_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_ENABLEFORCEDLOGOFF_PARMNUM
%SV_TIMESOURCE_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_TIMESOURCE_PARMNUM
%SV_LMANNOUNCE_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_LMANNOUNCE_PARMNUM
%SV_MAXCOPYREADLEN_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MAXCOPYREADLEN_PARMNUM
%SV_MAXCOPYWRITELEN_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MAXCOPYWRITELEN_PARMNUM
%SV_MINKEEPSEARCH_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MINKEEPSEARCH_PARMNUM
%SV_MAXKEEPSEARCH_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MAXKEEPSEARCH_PARMNUM
%SV_MINKEEPCOMPLSEARCH_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MINKEEPCOMPLSEARCH_PARMNUM
%SV_MAXKEEPCOMPLSEARCH_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MAXKEEPCOMPLSEARCH_PARMNUM
%SV_SCAVTIMEOUT_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_SCAVTIMEOUT_PARMNUM
%SV_MINRCVQUEUE_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MINRCVQUEUE_PARMNUM
%SV_MINFREEWORKITEMS_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MINFREEWORKITEMS_PARMNUM
%SV_MAXMPXCT_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MAXMPXCT_PARMNUM
%SV_OPLOCKBREAKWAIT_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_OPLOCKBREAKWAIT_PARMNUM
%SV_OPLOCKBREAKRESPONSEWAIT_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_OPLOCKBREAKRESPONSEWAIT_PARMNUM
%SV_ENABLEOPLOCKS_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_ENABLEOPLOCKS_PARMNUM
%SV_ENABLEOPLOCKFORCECLOSE_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_ENABLEOPLOCKFORCECLOSE_PARMNUM
%SV_ENABLEFCBOPENS_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_ENABLEFCBOPENS_PARMNUM
%SV_ENABLERAW_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_ENABLERAW_PARMNUM
%SV_ENABLESHAREDNETDRIVES_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_ENABLESHAREDNETDRIVES_PARMNUM
%SV_MINFREECONNECTIONS_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MINFREECONNECTIONS_PARMNUM
%SV_MAXFREECONNECTIONS_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MAXFREECONNECTIONS_PARMNUM
%SV_INITSESSTABLE_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_INITSESSTABLE_PARMNUM
%SV_INITCONNTABLE_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_INITCONNTABLE_PARMNUM
%SV_INITFILETABLE_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_INITFILETABLE_PARMNUM
%SV_INITSEARCHTABLE_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_INITSEARCHTABLE_PARMNUM
%SV_ALERTSCHEDULE_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_ALERTSCHEDULE_PARMNUM
%SV_ERRORTHRESHOLD_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_ERRORTHRESHOLD_PARMNUM
%SV_NETWORKERRORTHRESHOLD_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_NETWORKERRORTHRESHOLD_PARMNUM
%SV_DISKSPACETHRESHOLD_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_DISKSPACETHRESHOLD_PARMNUM
%SV_MAXLINKDELAY_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MAXLINKDELAY_PARMNUM
%SV_MINLINKTHROUGHPUT_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MINLINKTHROUGHPUT_PARMNUM
%SV_LINKINFOVALIDTIME_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_LINKINFOVALIDTIME_PARMNUM
%SV_SCAVQOSINFOUPDATETIME_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_SCAVQOSINFOUPDATETIME_PARMNUM
%SV_MAXWORKITEMIDLETIME_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MAXWORKITEMIDLETIME_PARMNUM
%SV_MAXRAWWORKITEMS_INFOLOEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MAXRAWWORKITEMS_PARMNUM
%SV_PRODUCTTYPE_INFOLOEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_PRODUCTTYPE_PARMNUM
%SV_SERVERSIZE_INFOLOEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_SERVERSIZE_PARMNUM
%SV_CONNECTIONLESSAUTODISC_INFOLOEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_CONNECTIONLESSAUTODISC_PARMNUM
%SV_SHARINGVIOLATIONRETRIES_INFOLOEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_SHARINGVIOLATIONRETRIES_PARMNUM
%SV_SHARINGVIOLATIONDELAY_INFOLOEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_SHARINGVIOLATIONDELAY_PARMNUM
%SV_MAXGLOBALOPENSEARCH_INFOLOEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MAXGLOBALOPENSEARCH_PARMNUM
%SV_REMOVEDUPLICATESEARCHES_INFOLOEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_REMOVEDUPLICATESEARCHES_PARMNUM
%SV_LOCKVIOLATIONRETRIES_INFOLOEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_LOCKVIOLATIONRETRIES_PARMNUM
%SV_LOCKVIOLATIONOFFSET_INFOLOEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_LOCKVIOLATIONOFFSET_PARMNUM
%SV_LOCKVIOLATIONDELAY_INFOLOEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_LOCKVIOLATIONDELAY_PARMNUM
%SV_MDLREADSWITCHOVER_INFOLOEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MDLREADSWITCHOVER_PARMNUM
%SV_CACHEDOPENLIMIT_INFOLOEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_CACHEDOPENLIMIT_PARMNUM
%SV_CRITICALTHREADS_INFOLOEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_CRITICALTHREADS_PARMNUM
%SV_RESTRICTNULLSESSACCESS_INFOLOEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_RESTRICTNULLSESSACCESS_PARMNUM
%SV_ENABLEWFW311DIRECTIPX_INFOLOEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_ENABLEWFW311DIRECTIPX_PARMNUM
%SV_OTHERQUEUEAFFINITY_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_OTHERQUEUEAFFINITY_PARMNUM
%SV_QUEUESAMPLESECS_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_QUEUESAMPLESECS_PARMNUM
%SV_BALANCECOUNT_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_BALANCECOUNT_PARMNUM
%SV_PREFERREDAFFINITY_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_PREFERREDAFFINITY_PARMNUM
%SV_MAXFREERFCBS_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MAXFREERFCBS_PARMNUM
%SV_MAXFREEMFCBS_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MAXFREEMFCBS_PARMNUM
%SV_MAXFREELFCBS_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MAXFREELFCBS_PARMNUM
%SV_MAXFREEPAGEDPOOLCHUNKS_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MAXFREEPAGEDPOOLCHUNKS_PARMNUM
%SV_MINPAGEDPOOLCHUNKSIZE_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MINPAGEDPOOLCHUNKSIZE_PARMNUM
%SV_MAXPAGEDPOOLCHUNKSIZE_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MAXPAGEDPOOLCHUNKSIZE_PARMNUM
%SV_SENDSFROMPREFERREDPROCESSOR_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_SENDSFROMPREFERREDPROCESSOR_PARMNUM
%SV_MAXTHREADSPERQUEUE_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MAXTHREADSPERQUEUE_PARMNUM
%SV_CACHEDDIRECTORYLIMIT_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_CACHEDDIRECTORYLIMIT_PARMNUM
%SV_MAXCOPYLENGTH_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MAXCOPYLENGTH_PARMNUM
%SV_ENABLECOMPRESSION_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_ENABLECOMPRESSION_PARMNUM
%SV_AUTOSHAREWKS_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_AUTOSHAREWKS_PARMNUM
%SV_AUTOSHARESERVER_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_AUTOSHARESERVER_PARMNUM
%SV_ENABLESECURITYSIGNATURE_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_ENABLESECURITYSIGNATURE_PARMNUM
%SV_REQUIRESECURITYSIGNATURE_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_REQUIRESECURITYSIGNATURE_PARMNUM
%SV_MINCLIENTBUFFERSIZE_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_MINCLIENTBUFFERSIZE_PARMNUM
%SV_CONNECTIONNOSESSIONSTIMEOUT_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_CONNECTIONNOSESSIONSTIMEOUT_PARMNUM
%SV_IDLETHREADTIMEOUT_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_IDLETHREADTIMEOUT_PARMNUM
%SV_ENABLEW9XSECURITYSIGNATURE_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_ENABLEW9XSECURITYSIGNATURE_PARMNUM
%SV_ENFORCEKERBEROSREAUTHENTICATION_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_ENFORCEKERBEROSREAUTHENTICATION_PARMNUM
%SV_DISABLEDOS_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_DISABLEDOS_PARMNUM
%SV_LOWDISKSPACEMINIMUM_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_LOWDISKSPACEMINIMUM_PARMNUM
%SV_DISABLESTRICTNAMECHECKING_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_DISABLESTRICTNAMECHECKING_PARMNUM
%SV_ENABLEAUTHENTICATEUSERSHARING_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SV_ENABLEAUTHENTICATEUSERSHARING_PARMNUM

%SVI1_NUM_ELEMENTS      = 5
%SVI2_NUM_ELEMENTS      = 40
%SVI3_NUM_ELEMENTS      = 44

'//
'//      Maxmimum length for command string to NetServerAdminCommand.
'//

%SV_MAX_CMD_LEN         = %PATHLEN

'//
'//      Masks describing AUTOPROFILE parameters
'//

%SW_AUTOPROF_LOAD_MASK  = &H1
%SW_AUTOPROF_SAVE_MASK  = &H2

'//
'//      Max size of svX_srvheuristics.
'//

%SV_MAX_SRV_HEUR_LEN    = 32     ' // Max heuristics info string length.

'//
'//      Equate for use with sv102_licenses.
'//

%SV_USERS_PER_LICENSE   = 5

'//
'// Equate for use with svti2_flags in NetServerTransportAddEx.
'//

%SVTI2_REMAP_PIPE_NAMES = &H2
%SVTI2_SCOPED_NAME      = &H4
%SVTI2_VALID_FLAGS      = %SVTI2_REMAP_PIPE_NAMES OR %SVTI2_SCOPED_NAME

'//
'// Server capability information
'//

%SRV_SUPPORT_HASH_GENERATION = &H0001
%SRV_HASH_GENERATION_ACTIVE  = &H0002
