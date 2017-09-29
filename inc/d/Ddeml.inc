' ########################################################################################
' Microsoft Windows
' File: ddeml.inc
' Contents: DDEML API header file
' Version 3.10
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DDEML_INC = 1

#INCLUDE ONCE "windows.inc"

'/******** public types ********/

'DECLARE_HANDLE(HCONVLIST);
'DECLARE_HANDLE(HCONV);
'DECLARE_HANDLE(HSZ);
'DECLARE_HANDLE(HDDEDATA);
'#define EXPENTRY        CALLBACK

'/* the following structure is for use with XTYP_WILDCONNECT processing. */

' // Size = 8 bytes
TYPE HSZPAIR DWORD
   hszSvc   AS DWORD   ' HSZ hszSvc
   hszTopic AS DWORD   ' HSZ hszTopic
END TYPE

'/* The following structure is used by DdeConnect() and DdeConnectList() and
'   by XTYP_CONNECT and XTYP_WILDCONNECT callbacks. */

' // Size = 36 bytes
TYPE CONVCONTEXT DWORD
   cb         AS DWORD   ' UINT  cb            /* set to sizeof(CONVCONTEXT) */
   wFlags     AS DWORD   ' UINT  wFlags        /* none currently defined. */
   wCountryID AS DWORD   ' UINT  wCountryID    /* country code for topic/item strings used. */
   iCodePage  AS LONG    ' int   iCodePage     /* codepage used for topic/item strings. */
   dwLangID   AS DWORD   ' DWORD dwLangID      /* language ID for topic/item strings. */
   dwSecurity AS DWORD   ' DWORD dwSecurity    /* Private security code. */
   qos        AS SECURITY_QUALITY_OF_SERVICE   ' SECURITY_QUALITY_OF_SERVICE qos;  /* client side's quality of service */
END TYPE


'/* The following structure is used by DdeQueryConvInfo(): */

' // Size = 96 bytes
TYPE CONVINFO DWORD
   cb            AS DWORD         ' DWORD   cb;            /* sizeof(CONVINFO)  */
   hUser         AS DWORD         ' DWORD_PTR hUser;       /* user specified field  */
   hConvPartner  AS DWORD         ' HCONV   hConvPartner;  /* hConv on other end or 0 if non-ddemgr partner  */
   hszSvcPartner AS DWORD         ' HSZ     hszSvcPartner; /* app name of partner if obtainable  */
   hszServiceReq AS DWORD         ' HSZ     hszServiceReq; /* AppName requested for connection  */
   hszTopic      AS DWORD         ' HSZ     hszTopic;      /* Topic name for conversation  */
   hszItem       AS DWORD         ' HSZ     hszItem;       /* transaction item name or NULL if quiescent  */
   wFmt          AS DWORD         ' UINT    wFmt;          /* transaction format or NULL if quiescent  */
   wType         AS DWORD         ' UINT    wType;         /* XTYP_ for current transaction  */
   wStatus       AS DWORD         ' UINT    wStatus;       /* ST_ constant for current conversation  */
   wConvst       AS DWORD         ' UINT    wConvst;       /* XST_ constant for current transaction  */
   wLastError    AS DWORD         ' UINT    wLastError;    /* last transaction error.  */
   hConvList     AS DWORD         ' HCONVLIST hConvList;   /* parent hConvList if this conversation is in a list */
   ConvCtxt      AS CONVCONTEXT   ' CONVCONTEXT ConvCtxt;  /* conversation context */
   hWnd          AS DWORD         ' HWND    hwnd;          /* window handle for this conversation */
   hwndPartner   AS DWORD         ' HWND    hwndPartner;   /* partner window handle for this conversation */
END TYPE

'/***** conversation states (usState) *****/

%XST_NULL           = 0  ' quiescent states
%XST_INCOMPLETE     = 1
%XST_CONNECTED      = 2
%XST_INIT1          = 3  ' mid-initiation states
%XST_INIT2          = 4
%XST_REQSENT        = 5  ' active conversation states
%XST_DATARCVD       = 6
%XST_POKESENT       = 7
%XST_POKEACKRCVD    = 8
%XST_EXECSENT       = 9
%XST_EXECACKRCVD    = 10
%XST_ADVSENT        = 11
%XST_UNADVSENT      = 12
%XST_ADVACKRCVD     = 13
%XST_UNADVACKRCVD   = 14
%XST_ADVDATASENT    = 15
%XST_ADVDATAACKRCVD = 16

'/* used in LOWORD(dwData1) of XTYP_ADVREQ callbacks... */
%CADV_LATEACK = &HFFFF??

'/***** conversation status bits (fsStatus) *****/

%ST_CONNECTED  = &H0001???
%ST_ADVISE     = &H0002???
%ST_ISLOCAL    = &H0004???
%ST_BLOCKED    = &H0008???
%ST_CLIENT     = &H0010???
%ST_TERMINATED = &H0020???
%ST_INLIST     = &H0040???
%ST_BLOCKNEXT  = &H0080???
%ST_ISSELF     = &H0100???

'/* DDE constants for wStatus field */

%DDE_FACK          = &H8000???
%DDE_FBUSY         = &H4000???
%DDE_FDEFERUPD     = &H4000???
%DDE_FACKREQ       = &H8000???
%DDE_FRELEASE      = &H2000???
%DDE_FREQUESTED    = &H1000???
%DDE_FAPPSTATUS    = &H00FF???
%DDE_FNOTPROCESSED = &H0000???

%DDE_FACKRESERVED = NOT (%DDE_FACK OR %DDE_FBUSY OR %DDE_FAPPSTATUS)
%DDE_FADVRESERVED = NOT (%DDE_FACKREQ OR %DDE_FDEFERUPD)
%DDE_FDATRESERVED = NOT (%DDE_FACKREQ OR %DDE_FRELEASE OR %DDE_FREQUESTED)
%DDE_FPOKRESERVED = NOT (%DDE_FRELEASE)

'/***** message filter hook types *****/

%MSGF_DDEMGR             = &H8001&

'/***** codepage constants ****/

%CP_WINANSI    = 1004&  ' default codepage for windows old DDE convs.
%CP_WINUNICODE = 1200&

'/***** transaction types *****/

%XTYPF_NOBLOCK = &H0002???     ' CBR_BLOCK will not work
%XTYPF_NODATA  = &H0004???     ' DDE_FDEFERUPD
%XTYPF_ACKREQ  = &H0008???     ' DDE_FACKREQ

%XCLASS_MASK         = &HFC00???
%XCLASS_BOOL         = &H1000???
%XCLASS_DATA         = &H2000???
%XCLASS_FLAGS        = &H4000???
%XCLASS_NOTIFICATION = &H8000???

%XTYP_ERROR           = &H0000 OR %XCLASS_NOTIFICATION OR %XTYPF_NOBLOCK
%XTYP_ADVDATA         = &H0010 OR %XCLASS_FLAGS
%XTYP_ADVREQ          = &H0020 OR %XCLASS_DATA OR %XTYPF_NOBLOCK
%XTYP_ADVSTART        = &H0030 OR %XCLASS_BOOL
%XTYP_ADVSTOP         = &H0040 OR %XCLASS_NOTIFICATION
%XTYP_EXECUTE         = &H0050 OR %XCLASS_FLAGS
%XTYP_CONNECT         = &H0060 OR %XCLASS_BOOL OR %XTYPF_NOBLOCK
%XTYP_CONNECT_CONFIRM = &H0070 OR %XCLASS_NOTIFICATION OR %XTYPF_NOBLOCK
%XTYP_XACT_COMPLETE   = &H0080 OR %XCLASS_NOTIFICATION
%XTYP_POKE            = &H0090 OR %XCLASS_FLAGS
%XTYP_REGISTER        = &H00A0 OR %XCLASS_NOTIFICATION OR %XTYPF_NOBLOCK
%XTYP_REQUEST         = &H00B0 OR %XCLASS_DATA
%XTYP_DISCONNECT      = &H00C0 OR %XCLASS_NOTIFICATION OR %XTYPF_NOBLOCK
%XTYP_UNREGISTER      = &H00D0 OR %XCLASS_NOTIFICATION OR %XTYPF_NOBLOCK
%XTYP_WILDCONNECT     = &H00E0 OR %XCLASS_DATA OR %XTYPF_NOBLOCK

%XTYP_MASK            = &H00F0
%XTYP_SHIFT           = 4  ' shift to turn XTYP_ into an index

'/***** Timeout constants *****/

%TIMEOUT_ASYNC = &HFFFFFFFF???

'/***** Transaction ID constants *****/

%QID_SYNC  = &HFFFFFFFF???

'/****** public strings used in DDE ******/

'#ifdef UNICODE
'#define SZDDESYS_TOPIC         L"System"
'#define SZDDESYS_ITEM_TOPICS   L"Topics"
'#define SZDDESYS_ITEM_SYSITEMS L"SysItems"
'#define SZDDESYS_ITEM_RTNMSG   L"ReturnMessage"
'#define SZDDESYS_ITEM_STATUS   L"Status"
'#define SZDDESYS_ITEM_FORMATS  L"Formats"
'#define SZDDESYS_ITEM_HELP     L"Help"
'#define SZDDE_ITEM_ITEMLIST    L"TopicItemList"
'#else
'#define SZDDESYS_TOPIC         "System"
'#define SZDDESYS_ITEM_TOPICS   "Topics"
'#define SZDDESYS_ITEM_SYSITEMS "SysItems"
'#define SZDDESYS_ITEM_RTNMSG   "ReturnMessage"
'#define SZDDESYS_ITEM_STATUS   "Status"
'#define SZDDESYS_ITEM_FORMATS  "Formats"
'#define SZDDESYS_ITEM_HELP     "Help"
'#define SZDDE_ITEM_ITEMLIST    "TopicItemList"
'#endif

$$SZDDESYS_TOPIC         = "System"$$
$$SZDDESYS_ITEM_TOPICS   = "Topics"$$
$$SZDDESYS_ITEM_SYSITEMS = "SysItems"$$
$$SZDDESYS_ITEM_RTNMSG   = "ReturnMessage"$$
$$SZDDESYS_ITEM_STATUS   = "Status"$$
$$SZDDESYS_ITEM_FORMATS  = "Formats"$$
$$SZDDESYS_ITEM_HELP     = "Help"$$
$$SZDDE_ITEM_ITEMLIST    = "TopicItemList"$$

$SZDDESYS_TOPIC         = "System"
$SZDDESYS_ITEM_TOPICS   = "Topics"
$SZDDESYS_ITEM_SYSITEMS = "SysItems"
$SZDDESYS_ITEM_RTNMSG   = "ReturnMessage"
$SZDDESYS_ITEM_STATUS   = "Status"
$SZDDESYS_ITEM_FORMATS  = "Formats"
$SZDDESYS_ITEM_HELP     = "Help"
$SZDDE_ITEM_ITEMLIST    = "TopicItemList"

#IF %DEF(%UNICODE)
MACRO SZDDESYS_TOPIC = $$SZDDESYS_TOPIC
MACRO SZDDESYS_ITEM_TOPICS = $$SZDDESYS_ITEM_TOPICS
MACRO SZDDESYS_ITEM_SYSITEMS = $$SZDDESYS_ITEM_SYSITEMS
MACRO SZDDESYS_ITEM_RTNMSG = $$SZDDESYS_ITEM_RTNMSG
MACRO SZDDESYS_ITEM_STATUS = $$SZDDESYS_ITEM_STATUS
MACRO SZDDESYS_ITEM_FORMATS = $$SZDDESYS_ITEM_FORMATS
MACRO SZDDESYS_ITEM_HELP = $$SZDDESYS_ITEM_HELP
MACRO SZDDE_ITEM_ITEMLIST = $$SZDDE_ITEM_ITEMLIST
#ELSE
MACRO SZDDESYS_TOPIC = $SZDDESYS_TOPIC
MACRO SZDDESYS_ITEM_TOPICS = $SZDDESYS_ITEM_TOPICS
MACRO SZDDESYS_ITEM_SYSITEMS = $SZDDESYS_ITEM_SYSITEMS
MACRO SZDDESYS_ITEM_RTNMSG = $SZDDESYS_ITEM_RTNMSG
MACRO SZDDESYS_ITEM_STATUS = $SZDDESYS_ITEM_STATUS
MACRO SZDDESYS_ITEM_FORMATS = $SZDDESYS_ITEM_FORMATS
MACRO SZDDESYS_ITEM_HELP = $SZDDESYS_ITEM_HELP
MACRO SZDDE_ITEM_ITEMLIST = $SZDDE_ITEM_ITEMLIST
#ENDIF

'/****** API entry points ******/

'typedef HDDEDATA CALLBACK FNCALLBACK(UINT wType, UINT wFmt, HCONV hConv,
'        HSZ hsz1, HSZ hsz2, HDDEDATA hData, ULONG_PTR dwData1, ULONG_PTR dwData2);
'typedef HDDEDATA (CALLBACK *PFNCALLBACK)(UINT wType, UINT wFmt, HCONV hConv,
'        HSZ hsz1, HSZ hsz2, HDDEDATA hData, ULONG_PTR dwData1, ULONG_PTR dwData2);

'#define     CBR_BLOCK           ((HDDEDATA)-1)
%CBR_BLOCK = &HFFFFFFFF???

'/* DLL registration functions */

DECLARE FUNCTION DdeInitializeA IMPORT "USER32.DLL" ALIAS "DdeInitializeA" ( _
   BYREF pidInst AS DWORD _                        ' __out LPDWORD pidInst
 , BYVAL pfnCallback AS DWORD _                    ' __in  PFNCALLBACK pfnCallback
 , BYVAL afCmd AS DWORD _                          ' __in  DWORD afCmd
 , BYVAL ulRes AS DWORD _                          ' __in  DWORD ulRes
 ) AS DWORD                                        ' UINT

DECLARE FUNCTION DdeInitializeW IMPORT "USER32.DLL" ALIAS "DdeInitializeW" ( _
   BYREF pidInst AS DWORD _                        ' __in  OUT LPDWORD pidInst
 , BYVAL pfnCallback AS DWORD _                    ' __in  PFNCALLBACK pfnCallback
 , BYVAL afCmd AS DWORD _                          ' __in  DWORD afCmd
 , BYVAL ulRes AS DWORD _                          ' __in  DWORD ulRes
 ) AS DWORD                                        ' UINT

#IF %DEF(%UNICODE)
   MACRO DdeInitialize = DdeInitializeW
#ELSE
   MACRO DdeInitialize = DdeInitializeA
#ENDIF

'/*
' * Callback filter flags for use with standard apps.
' */

%CBF_FAIL_SELFCONNECTIONS   = &H00001000???
%CBF_FAIL_CONNECTIONS       = &H00002000???
%CBF_FAIL_ADVISES           = &H00004000???
%CBF_FAIL_EXECUTES          = &H00008000???
%CBF_FAIL_POKES             = &H00010000???
%CBF_FAIL_REQUESTS          = &H00020000???
%CBF_FAIL_ALLSVRXACTIONS    = &H0003F000???

%CBF_SKIP_CONNECT_CONFIRMS  = &H00040000???
%CBF_SKIP_REGISTRATIONS     = &H00080000???
%CBF_SKIP_UNREGISTRATIONS   = &H00100000???
%CBF_SKIP_DISCONNECTS       = &H00200000???
%CBF_SKIP_ALLNOTIFICATIONS  = &H003C0000???

'/*
' * Application command flags
' */
%APPCMD_CLIENTONLY          = &H00000010???
%APPCMD_FILTERINITS         = &H00000020???
%APPCMD_MASK                = &H00000FF0???

'/*
' * Application classification flags
' */
%APPCLASS_STANDARD          = &H00000000???
%APPCLASS_MASK              = &H0000000F???

DECLARE FUNCTION DdeUninitialize IMPORT "USER32.DLL" ALIAS "DdeUninitialize" ( _
   BYVAL idInst AS DWORD _                         ' __in  DWORD idInst
 ) AS LONG                                              ' BOOL

'/*
' * conversation enumeration functions
' */

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DdeConnectList LIB "User32.dll" ALIAS "DdeConnectList" ( _
    BYVAL idInst        AS DWORD, _
    BYVAL hszService    AS DWORD, _  ' HSZ
    BYVAL hszTopic      AS DWORD, _  ' HSZ
    BYVAL hConvList     AS DWORD, _  ' HCONVLIST
    OPTIONAL BYVAL pCC  AS CONVCONTEXT PTR _
    ) AS DWORD  ' HCONVLIST
#ELSE
DECLARE FUNCTION DdeConnectList IMPORT "USER32.DLL" ALIAS "DdeConnectList" ( _
   BYVAL idInst AS DWORD _                              ' __in  DWORD idInst
 , BYVAL hszService AS DWORD _                          ' __in  HSZ hszService
 , BYVAL hszTopic AS DWORD _                            ' __in  HSZ hszTopic
 , BYVAL hConvList AS DWORD _                           ' __in  HCONVLIST hConvList
 , OPTIONAL BYREF pCC AS CONVCONTEXT _                  ' __in_opt PCONVCONTEXT pCC
 ) AS DWORD                                             ' HCONVLIST
#ENDIF

DECLARE FUNCTION DdeQueryNextServer IMPORT "USER32.DLL" ALIAS "DdeQueryNextServer" ( _
   BYVAL hConvList AS DWORD _                           ' __in  HCONVLIST hConvList
 , BYVAL hConvPrev AS DWORD _                           ' __in  HCONV hConvPrev
 ) AS DWORD                                             ' HCONV

DECLARE FUNCTION DdeDisconnectList IMPORT "USER32.DLL" ALIAS "DdeDisconnectList" ( _
   BYVAL hConvList AS DWORD _                           ' __in  HCONVLIST hConvList
 ) AS LONG                                              ' BOOL

'/*
' * conversation control functions
' */

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DdeConnect LIB "User32.dll" ALIAS "DdeConnect" ( _
    BYVAL idInst       AS DWORD, _
    BYVAL hszService   AS DWORD, _  ' HSZ
    BYVAL hszTopic     AS DWORD, _  ' HSZ
    OPTIONAL BYVAL pCC AS CONVCONTEXT PTR _
    ) AS DWORD  ' HCONV
#ELSE
DECLARE FUNCTION DdeConnect IMPORT "USER32.DLL" ALIAS "DdeConnect" ( _
   BYVAL idInst AS DWORD _                              ' __in  DWORD idInst
 , BYVAL hszService AS DWORD _                          ' __in  HSZ hszService
 , BYVAL hszTopic AS DWORD _                            ' __in  HSZ hszTopic
 , OPTIONAL BYREF pCC AS CONVCONTEXT _                  ' __in_opt PCONVCONTEXT pCC
 ) AS DWORD                                             ' HCONV
#ENDIF

DECLARE FUNCTION DdeDisconnect IMPORT "USER32.DLL" ALIAS "DdeDisconnect" ( _
   BYVAL hConv AS DWORD _                               ' __inout HCONV hConv
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DdeReconnect IMPORT "USER32.DLL" ALIAS "DdeReconnect" ( _
   BYVAL hConv AS DWORD _                               ' __in  HCONV hConv
 ) AS DWORD                                             ' HCONV

DECLARE FUNCTION DdeQueryConvInfo IMPORT "USER32.DLL" ALIAS "DdeQueryConvInfo" ( _
   BYVAL hConv AS DWORD _                               ' __in  HCONV hConv
 , BYVAL idTransaction AS DWORD _                       ' __in  DWORD idTransaction
 , BYREF pConvInfo AS CONVINFO _                        ' __inout PCONVINFO pConvInfo
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION DdeSetUserHandle IMPORT "USER32.DLL" ALIAS "DdeSetUserHandle" ( _
   BYVAL hConv AS DWORD _                               ' __in HCONV hConv
 , BYVAL id AS DWORD _                                  ' __in DWORD id
 , BYVAL hUser AS DWORD _                               ' __in DWORD_PTR hUser
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DdeAbandonTransaction IMPORT "USER32.DLL" ALIAS "DdeAbandonTransaction" ( _
   BYVAL idInst AS DWORD _                              ' __in DWORD idInst
 , BYVAL hConv AS DWORD _                               ' __in HCONV hConv
 , BYVAL idTransaction AS DWORD _                       ' __in DWORD idTransaction
 ) AS LONG                                              ' BOOL

'/*
' * app server interface functions
' */

DECLARE FUNCTION DdePostAdvise IMPORT "USER32.DLL" ALIAS "DdePostAdvise" ( _
   BYVAL idInst AS DWORD _                              ' __in DWORD idInst
 , BYVAL hszTopic AS DWORD _                            ' __in HSZ hszTopic
 , BYVAL hszItem AS DWORD _                             ' __in HSZ hszItem
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DdeEnableCallback IMPORT "USER32.DLL" ALIAS "DdeEnableCallback" ( _
   BYVAL idInst AS DWORD _                              ' __in DWORD idInst
 , BYVAL hConv AS DWORD _                               ' __in HCONV hConv
 , BYVAL wCmd AS DWORD _                                ' __in UINT wCmd
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DdeImpersonateClient IMPORT "USER32.DLL" ALIAS "DdeImpersonateClient" ( _
   BYVAL hConv AS DWORD _                               ' __in HCONV hConv
 ) AS LONG                                              ' BOOL

%EC_ENABLEALL    = 0
%EC_ENABLEONE    = %ST_BLOCKNEXT
%EC_DISABLE      = %ST_BLOCKED
%EC_QUERYWAITING = 2

DECLARE FUNCTION DdeNameService IMPORT "USER32.DLL" ALIAS "DdeNameService" ( _
   BYVAL idInst AS DWORD _                              ' __in DWORD idInst
 , BYVAL hsz1 AS DWORD _                                ' __in HSZ hsz1
 , BYVAL hsz2 AS DWORD _                                ' __in HSZ hsz2
 , BYVAL afCmd AS LONG _                                ' __in UINT afCmd
 ) AS DWORD                                             ' HDDEDATA

%DNS_REGISTER   = &H0001???
%DNS_UNREGISTER = &H0002???
%DNS_FILTERON   = &H0004???
%DNS_FILTEROFF  = &H0008???

'/*
' * app client interface functions
' */

DECLARE FUNCTION DdeClientTransaction IMPORT "USER32.DLL" ALIAS "DdeClientTransaction" ( _
   BYVAL pData AS BYTE PTR _                            ' __in LPBYTE pData
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 , BYVAL hConv AS DWORD _                               ' __in HCONV hConv
 , BYVAL hszItem AS DWORD _                             ' __in HSZ hszItem
 , BYVAL wFmt AS DWORD _                                ' __in UINT wFmt
 , BYVAL wType AS DWORD _                               ' __in UINT wType
 , BYVAL dwTimeout AS DWORD _                           ' __in DWORD dwTimeout
 , BYREF pdwResult AS DWORD _                           ' __out LPDWORD pdwResult
 ) AS DWORD                                             ' HDDEDATA

'/*
' *data transfer functions
' */

DECLARE FUNCTION DdeCreateDataHandle IMPORT "USER32.DLL" ALIAS "DdeCreateDataHandle" ( _
   BYVAL idInst AS DWORD _                              ' __in DWORD idInst
 , BYVAL pSrc AS BYTE PTR _                             ' __in LPBYTE pSrc
 , BYVAL cb AS DWORD _                                  ' __in DWORD cb
 , BYVAL cbOff AS DWORD _                               ' __in DWORD cbOff
 , BYVAL hszItem AS DWORD _                             ' __in HSZ hszItem
 , BYVAL wFmt AS DWORD _                                ' __in UINT wFmt
 , BYVAL afCmd AS DWORD _                               ' __in UINT afCmd
 ) AS DWORD                                             ' HDDEDATA

DECLARE FUNCTION DdeAddData IMPORT "USER32.DLL" ALIAS "DdeAddData" ( _
   BYVAL hData AS DWORD _                               ' __in HDDEDATA hData
 , BYVAL pSrc AS BYTE PTR _                             ' __in LPBYTE pSrc
 , BYVAL cb AS DWORD _                                  ' __in DWORD cb
 , BYVAL cbOff AS DWORD _                               ' __in DWORD cbOff
 ) AS DWORD                                             ' HDDEDATA

DECLARE FUNCTION DdeGetData IMPORT "USER32.DLL" ALIAS "DdeGetData" ( _
   BYVAL hData AS DWORD _                               ' __in  HDDEDATA hData
 , BYVAL pDst AS BYTE PTR _                             ' __out LPBYTE pDst
 , BYVAL cbMax AS DWORD _                               ' __in  DWORD cbMax
 , BYVAL cbOff AS DWORD _                               ' __in  DWORD cbOff
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DdeAccessData IMPORT "USER32.DLL" ALIAS "DdeAccessData" ( _
   BYVAL hData AS DWORD _                               ' __in  HDDEDATA hData
 , BYREF pcbDataSize AS DWORD _                         ' __out LPDWORD pcbDataSize
 ) AS DWORD                                             ' LPBYTE

DECLARE FUNCTION DdeUnaccessData IMPORT "USER32.DLL" ALIAS "DdeUnaccessData" ( _
   BYVAL hData AS DWORD _                               ' __in HDDEDATA hData
 ) AS LONG                                              ' BOOL

'#IF %DEF(%USEPBDECL)
'DECLARE FUNCTION DdeFreeDataHandle LIB "User32.dll" _
'    ALIAS "DdeFreeDataHandle" ( _
'    hData AS DWORD _  ' HDDEDATA   ' // This is wrong. It should be BYVAL
'    ) AS LONG  ' BOOL
'#ELSE
DECLARE FUNCTION DdeFreeDataHandle IMPORT "USER32.DLL" ALIAS "DdeFreeDataHandle" ( _
   BYVAL hData AS DWORD _                               ' __in HDDEDATA hData
 ) AS LONG                                              ' BOOL
'#ENDIF

%HDATA_APPOWNED = &H0001???

DECLARE FUNCTION DdeGetLastError IMPORT "USER32.DLL" ALIAS "DdeGetLastError" ( _
   BYVAL idInst AS DWORD _                              ' __in DWORD idInst
 ) AS DWORD                                             ' UINT

%DMLERR_NO_ERROR            = 0      ' must be 0

%DMLERR_FIRST               = &H4000???

%DMLERR_ADVACKTIMEOUT       = &H4000???
%DMLERR_BUSY                = &H4001???
%DMLERR_DATAACKTIMEOUT      = &H4002???
%DMLERR_DLL_NOT_INITIALIZED = &H4003???
%DMLERR_DLL_USAGE           = &H4004???
%DMLERR_EXECACKTIMEOUT      = &H4005???
%DMLERR_INVALIDPARAMETER    = &H4006???
%DMLERR_LOW_MEMORY          = &H4007???
%DMLERR_MEMORY_ERROR        = &H4008???
%DMLERR_NOTPROCESSED        = &H4009???
%DMLERR_NO_CONV_ESTABLISHED = &H400A???
%DMLERR_POKEACKTIMEOUT      = &H400B???
%DMLERR_POSTMSG_FAILED      = &H400C???
%DMLERR_REENTRANCY          = &H400D???
%DMLERR_SERVER_DIED         = &H400E???
%DMLERR_SYS_ERROR           = &H400F???
%DMLERR_UNADVACKTIMEOUT     = &H4010???
%DMLERR_UNFOUND_QUEUE_ID    = &H4011???

%DMLERR_LAST                = &H4011???

DECLARE FUNCTION DdeCreateStringHandleA IMPORT "USER32.DLL" ALIAS "DdeCreateStringHandleA" ( _
   BYVAL idInst AS DWORD _                              ' __in DWORD idInst
 , BYREF psz AS ASCIIZ _                                ' __in LPCSTR psz
 , BYVAL iCodePage AS DWORD _                           ' __in int iCodePage
 ) AS DWORD                                             ' HSZ

DECLARE FUNCTION DdeCreateStringHandleW IMPORT "USER32.DLL" ALIAS "DdeCreateStringHandleW" ( _
   BYVAL idInst AS DWORD _                              ' __in DWORD idInst
 , BYREF psz AS WSTRINGZ _                              ' __in LPCWSTR psz
 , BYVAL iCodePage AS DWORD _                           ' __in int iCodePage
 ) AS DWORD                                             ' HSZ

#IF %DEF(%UNICODE)
   MACRO DdeCreateStringHandle = DdeCreateStringHandleW
#ELSE
   MACRO DdeCreateStringHandle = DdeCreateStringHandleA
#ENDIF

DECLARE FUNCTION DdeQueryStringA IMPORT "USER32.DLL" ALIAS "DdeQueryStringA" ( _
   BYVAL idInst AS DWORD _                              ' __in DWORD idInst
 , BYVAL hsz AS DWORD _                                 ' __in HSZ hsz
 , BYREF psz AS ASCIIZ _                                ' __inout LPSTR psz
 , BYVAL cchMax AS DWORD _                              ' __in DWORD cchMax
 , BYVAL iCodePage AS LONG _                            ' __in int iCodePage
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DdeQueryStringW IMPORT "USER32.DLL" ALIAS "DdeQueryStringW" ( _
   BYVAL idInst AS DWORD _                              ' __in DWORD idInst
 , BYVAL hsz AS DWORD _                                 ' __in HSZ hsz
 , BYREF psz AS WSTRINGZ _                              ' __inout LPWSTR psz
 , BYVAL cchMax AS DWORD _                              ' __in DWORD cchMax
 , BYVAL iCodePage AS LONG _                            ' __in int iCodePage
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO DdeQueryString = DdeQueryStringW
#ELSE
   MACRO DdeQueryString = DdeQueryStringA
#ENDIF

DECLARE FUNCTION DdeFreeStringHandle IMPORT "USER32.DLL" ALIAS "DdeFreeStringHandle" ( _
   BYVAL idInst AS DWORD _                              ' __in DWORD idInst
 , BYVAL hsz AS DWORD _                                 ' __inout HSZ hsz
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DdeKeepStringHandle IMPORT "USER32.DLL" ALIAS "DdeKeepStringHandle" ( _
   BYVAL idInst AS DWORD _                              ' __in DWORD idInst
 , BYVAL hsz AS DWORD _                                 ' __inout HSZ hsz
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DdeCmpStringHandles IMPORT "USER32.DLL" ALIAS "DdeCmpStringHandles" ( _
   BYVAL hsz1 AS DWORD _                                ' __in HSZ hsz1
 , BYVAL hsz2 AS DWORD _                                ' __in HSZ hsz2
 ) AS LONG                                              ' int

'#ifndef NODDEMLSPY
'/*
' * DDEML public debugging header file info
' */

' // Size = 44 bytes
TYPE DDEML_MSG_HOOK_DATA
   uiLo    AS DWORD   ' UINT_PTR uiLo;  // unpacked lo and hi parts of lParam
   uiHi    AS DWORD   ' UINT_PTR uiHi;
   cbData  AS DWORD   ' DWORD cbData;   // amount of data in message, if any. May be > than 32 bytes.
   Data(7) AS DWORD   ' DWORD Data[8];  // data peeking by DDESPY is limited to 32 bytes.
END TYPE

' // Size = 72 bytes
TYPE MONMSGSTRUCT DWORD
   cb     AS DWORD                 ' UINT    cb
   hWndTo AS DWORD                 ' HWND    hwndTo
   dwTime AS DWORD                 ' DWORD   dwTime
   htask  AS DWORD                 ' HANDLE  hTask
   wMsg   AS DWORD                 ' UINT    wMsg
   wParam AS DWORD                 ' WPARAM  wParam
   lParam AS LONG                  ' LPARAM  lParam
   dmhd   AS DDEML_MSG_HOOK_DATA   ' DDEML_MSG_HOOK_DATA dmhd;       // new for NT
END TYPE

' // Size = 120 bytes
TYPE MONCBSTRUCT DWORD
   cb      AS DWORD         ' UINT   cb
   dwTime  AS DWORD         ' DWORD  dwTime
   htask   AS DWORD         ' HANDLE hTask
   dwRet   AS DWORD         ' DWORD  dwRet
   wType   AS DWORD         ' UINT   wType
   wFmt    AS DWORD         ' UINT   wFmt
   hConv   AS DWORD         ' HCONV  hConv
   hsz1    AS DWORD         ' HSZ    hsz1
   hsz2    AS DWORD         ' HSZ    hsz2
   hData   AS DWORD         ' HDDEDATA hData
   dwData1 AS DWORD         ' ULONG_PTR dwData1
   dwData2 AS DWORD         ' ULONG_PTR dwData2
   cc      AS CONVCONTEXT   ' CONVCONTEXT cc;  // new for NT for XTYP_CONNECT callbacks
   cbData  AS DWORD         ' DWORD  cbData;   // new for NT for data peeking
   Data(7) AS DWORD         ' DWORD  Data[8];  // new for NT for data peeking
END TYPE

' // Size = 24 bytes
TYPE MONHSZSTRUCTA DWORD
   cb       AS DWORD        ' UINT    cb
   fsAction AS LONG         ' BOOL    fsAction;    /* MH_ value */
   dwTime   AS DWORD        ' DWORD   dwTime
   hsz      AS DWORD        ' HSZ     hsz
   htask    AS DWORD        ' HANDLE  hTask
   str      AS ASCIIZ * 1   ' CHAR    str[1]
END TYPE

' // Size = 24 bytes
TYPE MONHSZSTRUCTW DWORD
   cb       AS DWORD          ' UINT    cb
   fsAction AS LONG           ' BOOL    fsAction;    /* MH_ value */
   dwTime   AS DWORD          ' DWORD   dwTime
   hsz      AS DWORD          ' HSZ     hsz
   htask    AS DWORD          ' HANDLE  hTask
   str      AS WSTRINGZ * 1   ' WCHAR   str[1]
END TYPE

#IF %DEF(%UNICODE)
   MACRO MONHSZSTRUCT = MONHSZSTRUCTW
#ELSE
   MACRO MONHSZSTRUCT = MONHSZSTRUCTA
#ENDIF

%MH_CREATE  = 1
%MH_KEEP    = 2
%MH_DELETE  = 3
%MH_CLEANUP = 4

' // Size = 16 bytes
TYPE MONERRSTRUCT DWORD
   cb         AS DWORD   ' UINT    cb
   wLastError AS DWORD   ' UINT    wLastError
   dwTime     AS DWORD   ' DWORD   dwTime
   htask      AS DWORD   ' HANDLE  hTask
END TYPE

' // Size = 48 bytes
TYPE MONLINKSTRUCT DWORD
   cb           AS DWORD   ' UINT    cb
   dwTime       AS DWORD   ' DWORD   dwTime
   htask        AS DWORD   ' HANDLE  hTask
   fEstablished AS LONG    ' BOOL    fEstablished
   fNoData      AS LONG    ' BOOL    fNoData
   hszSvc       AS LONG    ' HSZ     hszSvc
   hszTopic     AS DWORD   ' HSZ     hszTopic
   hszItem      AS DWORD   ' HSZ     hszItem
   wFmt         AS DWORD   ' UINT    wFmt
   fServer      AS LONG    ' BOOL    fServer
   hConvServer  AS LONG    ' HCONV   hConvServer
   hConvClient  AS LONG    ' HCONV   hConvClient
END TYPE

' // Size = 32 bytes
TYPE MONCONVSTRUCT DWORD
   cb          AS DWORD   ' UINT    cb
   fConnect    AS LONG    ' BOOL    fConnect
   dwTime      AS DWORD   ' DWORD   dwTime
   htask       AS DWORD   ' HANDLE  hTask
   hszSvc      AS LONG    ' HSZ     hszSvc
   hszTopic    AS DWORD   ' HSZ     hszTopic
   hConvClient AS DWORD   ' HCONV   hConvClient  // Globally unique value != apps local hConv
   hConvServer AS DWORD   ' HCONV   hConvServer  // Globally unique value != apps local hConv
END TYPE

%MAX_MONITORS     = 4
%APPCLASS_MONITOR = &H00000001???
%XTYP_MONITOR     = &H00F0 OR %XCLASS_NOTIFICATION OR %XTYPF_NOBLOCK

'/*
' * Callback filter flags for use with MONITOR apps - 0 implies no monitor
' * callbacks.
' */
%MF_HSZ_INFO  = &H01000000???
%MF_SENDMSGS  = &H02000000???
%MF_POSTMSGS  = &H04000000???
%MF_CALLBACKS = &H08000000???
%MF_ERRORS    = &H10000000???
%MF_LINKS     = &H20000000???
%MF_CONV      = &H40000000???

%MF_MASK      = &HFF000000???

'#endif /* NODDEMLSPY */
