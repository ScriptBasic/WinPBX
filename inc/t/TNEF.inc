' ########################################################################################
' Microsoft Windows
' File: TNEF.inc
' Copyright (c) 2010 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TNEF_INC = 1

'/*
' *   T N E F . H
' *
' *
' *   This file contains structure and function definitions for the
' *   MAPI implementation of the Transport Neutral Encapsilation Format
' *   used by MAPI providers for the neutral serialization of a MAPI
' *   message.  This implementation sits on top of the IStream object as
' *   documented in the OLE 2 Specs.
' *
' *  Copyright 1986-1999 Microsoft Corporation. All Rights Reserved.
' */

#INCLUDE ONCE "mapix.inc"

'/* ------------------------------------ */
'/* TNEF Problem and TNEF Problem Arrays */
'/* ------------------------------------ */

' // Size = 16 bytes
TYPE STnefProblem DWORD
   ulComponent AS DWORD   ' ULONG
   ulAttribute AS DWORD   ' ULONG
   ulPropTag   AS DWORD   ' ULONG
   scode       AS LONG    ' SCODE
END TYPE

' // Size = 20 bytes
TYPE STnefProblemArray DWORD
   cProblem AS DWORD                         ' ULONG
   aProblem(%MAPI_DIM - 1) AS STnefProblem   ' STnefProblem [variable-length array]
END TYPE

'#define CbNewSTnefProblemArray(_cprob) \
'   (offsetof(STnefProblemArray,aProblem) + (_cprob)*sizeof(STnefProblem))
'#define CbSTnefProblemArray(_lparray) \
'   (offsetof(STnefProblemArray,aProblem) + \
'   (UINT) ((_lparray)->cProblem*sizeof(STnefProblem)))

'/* Pointers to TNEF Interface ---------------------------------------- */

'/*   OpenTNEFStream */

%TNEF_DECODE                = 0???
%TNEF_ENCODE                = 2???

%TNEF_PURE                  = &H00010000???
%TNEF_COMPATIBILITY         = &H00020000???
%TNEF_BEST_DATA             = &H00040000???
%TNEF_COMPONENT_ENCODING    = &H80000000???

'/*   AddProps, ExtractProps */

%TNEF_PROP_INCLUDE          = &H00000001???
%TNEF_PROP_EXCLUDE          = &H00000002???
%TNEF_PROP_CONTAINED        = &H00000004???
%TNEF_PROP_MESSAGE_ONLY     = &H00000008???
%TNEF_PROP_ATTACHMENTS_ONLY = &H00000010???
%TNEF_PROP_CONTAINED_TNEF   = &H00000040???

'/*   FinishComponent */

%TNEF_COMPONENT_MESSAGE     = &H00001000???
%TNEF_COMPONENT_ATTACHMENT  = &H00002000???

' ========================================================================================
' ITnef interface
' $IID_ITNEF = GUID$("{00020319-0000-0000-C000-000000000046}")
' The ITnef interface provides methods for encapsulating those MAPI properties not
' supported by a messaging system into binary streams that can be attached to messages.
' The format used for this encapsulation is Transport-Neutral Encapsulation Format (TNEF).
' The target transport provider or MAPI-based client application can then, on receiving a
' message including a TNEF attachment, recover the properties from the attachment.
' ========================================================================================
INTERFACE ITnef $IID_ITNEF

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddProps ( _                                  ' VTable offset = 12
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL ulElemID AS DWORD _                          ' __in ULONG ulElemID
   , BYVAL lpvData AS DWORD _                           ' __in LPVOID lpvData
   , BYVAL lpPropList AS SPropTagArray PTR _            ' __in LPSPropTagArray lpPropList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExtractProps ( _                              ' VTable offset = 16
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lpPropList AS SPropTagArray PTR _            ' __in LPSPropTagArray lpPropList
   , BYREF lpProblems AS DWORD _                        ' __out LPSTnefProblemArray *lpProblems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish ( _                                    ' VTable offset = 20
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpKey AS DWORD _                             ' __out WORD *lpKey
   , BYREF lpProblems AS DWORD _                        ' __out LPSTnefProblemArray *lpProblems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenTaggedBody ( _                            ' VTable offset = 24
     BYVAL lpMessage AS IMessage _                      ' __in LPMESSAGE lpMessage
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppStream AS IStream _                       ' __out LPSTREAM *lppStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProps ( _                                  ' VTable offset = 28
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL ulElemID AS DWORD _                          ' __in ULONG ulElemID
   , BYVAL cValues AS DWORD _                           ' __in ULONG cValues
   , BYREF lpProps AS SPropValue _                      ' __in LPSPropValue lpProps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EncodeRecips ( _                              ' VTable offset = 32
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lpRecipientTable AS IMAPITable _             ' __in LPMAPITABLE lpRecipientTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FinishComponent ( _                           ' VTable offset = 36
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL ulComponentID AS DWORD _                     ' __in ULONG ulComponentID
   , BYVAL lpCustomPropList AS SPropTagArray PTR _      ' __in LPSPropTagArray lpCustomPropList
   , BYREF lpCustomProps AS SPropValue _                ' __in LPSPropValue lpCustomProps
   , BYVAL lpPropList AS SPropTagArray PTR _            ' __in LPSPropTagArray lpPropList
   , BYREF lpProblems AS DWORD _                        ' __out LPSTnefProblemArray *lpProblems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ========================================================================================
' OpenTnefStream
' The OpenTnefStream function is called by a transport provider to initiate a MAPI
' Transport Neutral Encapsulation Format (TNEF) session.
' ========================================================================================
DECLARE FUNCTION OpenTnefStream IMPORT "MAPI32.DLL" ALIAS "OpenTnefStream" ( _
   BYVAL lpvSupport AS IUnknown _                       ' __in LPVOID lpvSupport
 , BYVAL lpStream AS IStream _                          ' __in LPSTREAM lpStream
 , BYREF lpszStreamName AS ASCIIZ _                     ' __in LPTSTR lpszStreamName
 , BYVAL ulFlags AS DWORD _                             ' __in ULONG ulFlags
 , BYVAL lpMessage AS IMessage _                        ' __in LPMESSAGE lpMessage
 , BYVAL wKey AS WORD _                                 ' __in WORD wKey
 , BYREF lppTNEF AS ITnef _                             ' __out LPITNEF *lppTNEF
 ) AS LONG                                              ' HRESULT
' ========================================================================================

' ========================================================================================
' OpenTnefStreamEx
' The OpenTnefStreamEx function creates a TNEF object that can be used to encode or decode
' a message object into a TNEF data stream for use by transports or gateways and message
' stores. This is the entry point for TNEF access.
' ========================================================================================
DECLARE FUNCTION OpenTnefStreamEx IMPORT "MAPI32.DLL" ALIAS "OpenTnefStreamEx" ( _
   BYVAL lpvSupport AS IUnknown _                       ' __in LPVOID lpvSupport
 , BYVAL lpStreamName AS IStream _                      ' __in LPSTREAM lpStreamName
 , BYREF lpszStreamName AS ASCIIZ _                     ' __in LPTSTR lpszStreamName
 , BYVAL ulFlags AS DWORD _                             ' __in ULONG ulFlags
 , BYVAL lpMessage AS IMessage _                        ' __in LPMESSAGE lpMessage
 , BYVAL wKeyVal AS WORD _                              ' __in WORD wKeyVal
 , BYVAL lpAdressBook AS IAddrBook _                    ' __in LPADRBOOK lpAdressBook
 , BYREF lppTNEF AS ITnef _                             ' __out LPITNEF *lppTNEF
 ) AS LONG                                              ' HRESULT
' ========================================================================================

DECLARE FUNCTION GetTnefStreamCodepage IMPORT "MAPI32.DLL" ALIAS "GetTnefStreamCodepage" ( _
   BYVAL lpStream AS IStream _                          ' __in LPSTREAM lpStream
 , BYREF lpulCodepage AS DWORD _                        ' __out ULONG *lpulCodepage
 , BYREF lpulSubCodepage AS DWORD _                     ' __out ULONG *lpulSubCodepage
 ) AS LONG                                              ' HRESULT

$OPENTNEFSTREAM = "OpenTnefStream"
$OPENTNEFSTREAMEX = "OpenTnefStreamEx"
$GETTNEFSTREAMCODEPAGE = "GetTnefStreamCodePage"

'/* -------------------------- */
'/* TNEF Signature and Version */
'/* -------------------------- */

'#define MAKE_TNEF_VERSION(_mj,_mn)   (((ULONG)(0x0000FFFF & _mj) << 16) | (ULONG)(0x0000FFFF & _mn))
FUNCTION MAKE_TNEF_VERSION (BYVAL mj AS DWORD, BYVAL mn AS DWORD) AS DWORD
   LOCAL v AS DWORD
   v = &H0000FFFF AND mj
   SHIFT LEFT v, 16
   FUNCTION = v OR (&H0000FFFF AND mn)
END FUNCTION

%TNEF_SIGNATURE = &H223E9F78???

'#define TNEF_VERSION   ((ULONG) MAKE_TNEF_VERSION(1,0))
%TNEF_VERSION = 65536???


'/* ------------------------------------------- */
'/* TNEF Down-level Attachment Types/Structures */
'/* ------------------------------------------- */

'typedef WORD ATYP;

'enum { atypNull, atypFile, atypOle, atypPicture, atypMax };

%atypNull    = 0
%atypFile    = 1
%atypOle     = 2
%atypPicture = 3
%atypMax     = 4

%MAC_BINARY = &H00000001???

'#include <pshpack1.h>
' // Size = 14 bytes
TYPE RENDDATA BYTE
   atyp       AS WORD    ' ATYP
   ulPosition AS DWORD   ' ULONG
   dxWidth    AS WORD    ' WORD
   dyHeight   AS WORD    ' WORD
   dwFlags    AS DWORD   ' DWORD
END TYPE
'#include <poppack.h>


'/* ----------------------------------- */
'/* TNEF Down-level Date/Time Structure */
'/* ----------------------------------- */

'#include <pshpack1.h>
' // Size = 14 bytes
TYPE DTR BYTE
   wYear      AS WORD
   wMonth     AS WORD
   wDay       AS WORD
   wHour      AS WORD
   wMinute    AS WORD
   wSecond    AS WORD
   wDayOfWeek AS WORD
END TYPE
'#include <poppack.h>


'/* ----------------------------- */
'/* TNEF Down-level Message Flags */
'/* ----------------------------- */

%fmsNull      = &H00?
%fmsModified  = &H01?
%fmsLocal     = &H02?
%fmsSubmitted = &H04?
%fmsRead      = &H20?
%fmsHasAttach = &H80?


'/* ----------------------------------------- */
'/* TNEF Down-level Triple Address Structures */
'/* ----------------------------------------- */

%trpidNull                 = &H0000??
%trpidUnresolved           = &H0001??
%trpidResolvedNSID         = &H0002??
%trpidResolvedAddress      = &H0003??
%trpidOneOff               = &H0004??
%trpidGroupNSID            = &H0005??
%trpidOffline              = &H0006??
%trpidIgnore               = &H0007??
%trpidClassEntry           = &H0008??
%trpidResolvedGroupAddress = &H0009??

' // Size = 8 bytes
TYPE TRP WORD
   trpid   AS WORD
   cbgrtrp AS WORD
   cch     AS WORD
   cbRgb   AS WORD
END TYPE

'#define CbOfTrp(_p)      (sizeof(TRP) + (_p)->cch + (_p)->cbRgb)
'#define LpszOfTrp(_p)   ((LPSTR)(((LPTRP) (_p)) + 1))
'#define LpbOfTrp(_p)   (((LPBYTE)(((LPTRP)(_p)) + 1)) + (_p)->cch)
'#define LptrpNext(_p)   ((LPTRP)((LPBYTE)(_p) + CbOfTrp(_p)))

'typedef DWORD XTYPE;

%xtypeUnknown  = 0???
%xtypeInternet = 6???

%cbDisplayName = 41
%cbEmailName   = 11
%cbSeverName   = 12

' // Size = 72 bytes
TYPE ADDRALIAS
   rgchName    AS ASCIIZ * %cbDisplayName   ' char rgchName[cbDisplayName]
   rgchEName   AS ASCIIZ * %cbEmailName     ' char rgchEName[cbEmailName]
   rgchSrvr    AS ASCIIZ * %cbSeverName     ' char rgchSrvr[cbSeverName]
   dibDetail   AS DWORD                     ' ULONG
   type        AS WORD                      ' WORD
   alignment__ AS WORD
END TYPE

'#define cbALIAS sizeof(ALIAS)

%cbTYPE      = 16
%cbMaxIdData = 200

' // Size = 72 bytes
UNION NSID_Address_UNION
   alias           AS ADDRALIAS   ' ADDRALIAS alias
   rgchInterNet(0) AS BYTE        ' char rgchInterNet[1]
END UNION

' // Size = 100 bytes
TYPE NSID DWORD
   dwSize  AS DWORD              ' DWORD
   uchType AS ASCIIZ * %cbType   ' unsigned char[cbTYPE];
   xtype   AS DWORD              ' XTYPE
   lTime   AS LONG               ' LONG
   address AS NSID_Address_UNION
END TYPE

'#define cbNSID sizeof(NSID)

'/* -------------------------- */
'/* TNEF Down-level Priorities */
'/* -------------------------- */

%prioLow  = 3
%prioNorm = 2
%prioHigh = 1


'/* ------------------------------------- */
'/* TNEF Down-level Attributes/Properties */
'/* ------------------------------------- */

%atpTriples = &H0000??
%atpString  = &H0001??
%atpText    = &H0002??
%atpDate    = &H0003??
%atpShort   = &H0004??
%atpLong    = &H0005??
%atpByte    = &H0006??
%atpWord    = &H0007??
%atpDword   = &H0008??
%atpMax     = &H0009??

%LVL_MESSAGE    = &H01?
%LVL_ATTACHMENT = &H02?

'#define ATT_ID(_att)            ((WORD) ((_att) & 0x0000FFFF))
FUNCTION ATT_ID (BYVAL att_ AS DWORD) AS WORD
   FUNCTION = att_ AND &H0000FFFF
END FUNCTION

'#define ATT_TYPE(_att)            ((WORD) (((_att) >> 16) & 0x0000FFFF))
FUNCTION ATT_TYPE (BYVAL att_ AS DWORD) AS WORD
   SHIFT RIGHT att_, 16
   FUNCTION = att_ AND &H0000FFFF
END FUNCTION

'#define ATT(_atp, _id)            ((((DWORD) (_atp)) << 16) | ((WORD) (_id)))
FUNCTION ATT (BYVAL atp AS WORD, BYVAL id AS WORD) AS DWORD
   LOCAL dwatp AS DWORD
   dwatp = atp
   SHIFT LEFT dwatp, 16
   FUNCTION = dwatp OR id
END FUNCTION

%attNull                    = &H00000000   ' ATT(0,          0x0000)
%attFrom                    = &H00008000   ' ATT(atpTriples, 0x8000) /* PR_ORIGINATOR_RETURN_ADDRESS */
%attSubject                 = &H00018004   ' ATT(atpString,  0x8004) /* PR_SUBJECT */
%attDateSent                = &H00038005   ' ATT(atpDate,    0x8005) /* PR_CLIENT_SUBMIT_TIME */
%attDateRecd                = &H00038006   ' ATT(atpDate,    0x8006) /* PR_MESSAGE_DELIVERY_TIME */
%attMessageStatus           = &H00058007   ' ATT(atpByte,    0x8007) /* PR_MESSAGE_FLAGS */
%attMessageClass            = &H00078008   ' ATT(atpWord,    0x8008) /* PR_MESSAGE_CLASS */
%attMessageID               = &H00018009   ' ATT(atpString,  0x8009) /* PR_MESSAGE_ID */
%attParentID                = &H0001800A   ' ATT(atpString,  0x800A) /* PR_PARENT_ID */
%attConversationID          = &H0001800B   ' ATT(atpString,  0x800B) /* PR_CONVERSATION_ID */
%attBody                    = &H0002800C   ' ATT(atpText,    0x800C) /* PR_BODY */
%attPriority                = &H0004800D   ' ATT(atpShort,   0x800D) /* PR_IMPORTANCE */
%attAttachData              = &H0006800F   ' ATT(atpByte,    0x800F) /* PR_ATTACH_DATA_xxx */
%attAttachTitle             = &H00018010   ' ATT(atpString,  0x8010) /* PR_ATTACH_FILENAME */
%attAttachMetaFile          = &H00068011   ' ATT(atpByte,    0x8011) /* PR_ATTACH_RENDERING */
%attAttachCreateDate        = &H00038012   ' ATT(atpDate,    0x8012) /* PR_CREATION_TIME */
%attAttachModifyDate        = &H00038013   ' ATT(atpDate,    0x8013) /* PR_LAST_MODIFICATION_TIME */
%attDateModified            = &H00038020   ' ATT(atpDate,    0x8020) /* PR_LAST_MODIFICATION_TIME */
%attAttachTransportFilename = &H00069001   ' ATT(atpByte,    0x9001) /* PR_ATTACH_TRANSPORT_NAME */
%attAttachRenddata          = &H00069002   ' ATT(atpByte,    0x9002)
%attMAPIProps               = &H00069003   ' ATT(atpByte,    0x9003)
%attRecipTable              = &H00069004   ' ATT(atpByte,    0x9004) /* PR_MESSAGE_RECIPIENTS */
%attAttachment              = &H00069005   ' ATT(atpByte,    0x9005)
%attTnefVersion             = &H00089006   ' ATT(atpDword,   0x9006)
%attOemCodepage             = &H00069007   ' ATT(atpByte,    0x9007)
%attOriginalMessageClass    = &H00070006   ' ATT(atpWord,    0x0006) /* PR_ORIG_MESSAGE_CLASS */

%attOwner                   = &H00060000   ' ATT(atpByte,    0x0000) /* PR_RCVD_REPRESENTING_xxx  or PR_SENT_REPRESENTING_xxx */
%attSentFor                 = &H00060001   ' ATT(atpByte,    0x0001) /* PR_SENT_REPRESENTING_xxx */
%attDelegate                = &H00060002   ' ATT(atpByte,    0x0002) /* PR_RCVD_REPRESENTING_xxx */
%attDateStart               = &H00030006   ' ATT(atpDate,    0x0006) /* PR_DATE_START */
%attDateEnd                 = &H00030007   ' ATT(atpDate,    0x0007) /* PR_DATE_END */
%attAidOwner                = &H00050008   ' ATT(atpLong,    0x0008) /* PR_OWNER_APPT_ID */
%attRequestRes              = &H00040009   ' ATT(atpShort,   0x0009) /* PR_RESPONSE_REQUESTED */
