' ########################################################################################
' Microsoft Windows
' File: MAPIForm.inc
' Contents: Declarations of interfaces for clients and providers of MAPI forms and form registries.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MAPIFORM_INC = 1

#INCLUDE ONCE "mapix.inc"

'/* HFRMREG is an enumeration which represents a registry container.
' * Microsoft reserves the values from 0 to 0x3FFF for its own use.
' */

'typedef ULONG HFRMREG;

%HFRMREG_DEFAULT  = 0
%HFRMREG_LOCAL    = 1
%HFRMREG_PERSONAL = 2
%HFRMREG_FOLDER   = 3

'typedef const char *FAR * LPPCSTR;

'STDAPI MAPIOpenFormMgr(LPMAPISESSION pSession, LPMAPIFORMMGR * ppmgr);

DECLARE FUNCTION MAPIOpenFormMgr IMPORT "MAPI32.DLL" ALIAS "MAPIOpenFormMgr" ( _
   BYVAL pSession AS IMAPISession _                     ' __in  LPMAPISESSION pSession
 , BYREF ppmgr AS IMAPIFormMgr _                        ' __out LPMAPIFORMMGR * ppmgr
 ) AS LONG                                              ' HRESULT

'STDAPI MAPIOpenLocalFormContainer(LPMAPIFORMCONTAINER * ppfcnt);

DECLARE FUNCTION MAPIOpenLocalFormContainer IMPORT "MAPI32.DLL" ALIAS "MAPIOpenLocalFormContainer" ( _
   BYREF ppfcnt AS IMAPIFormContainer _                 ' __out LPMAPIFORMCONTAINER * ppfcnt
 ) AS LONG                                              ' HRESULT

'/*-- IPersistMessage -------------------------------------------------------*/
'/* This interface is implemented by forms and is used to save,
' * initialize and load forms to and from messages.
' */

' ========================================================================================
' IPersistMessage interface
' $IID_IPersistMessage = GUID$("{0002032A-0000-0000-C000-000000000046}")
' The IPersistMessage interface is used by form viewers to handle the storage of a form
' and to transition between the various states.
' ========================================================================================
INTERFACE IPersistMessage $IID_IPersistMessage

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF lpClassID AS GUID _                          ' __in LPCLSID lpClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDirty ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitNew ( _                                   ' VTable offset = 20
     BYVAL pMessageSite AS IMAPIMessageSite _           ' __in LPMAPIMESSAGESITE pMessageSite
   , BYVAL pMessage AS IMessage _                       ' __in LPMESSAGE pMessage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 24
     BYVAL pMessageSite AS IMAPIMessageSite _           ' __in LPMAPIMESSAGESITE pMessageSite
   , BYVAL pMessage AS IMessage _                       ' __in LPMESSAGE pMessage
   , BYVAL ulMessageStatus AS DWORD _                   ' __in ULONG ulMessageStatus
   , BYVAL ulMessageFlags AS DWORD _                    ' __in ULONG ulMessageFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 28
     BYVAL pMessage AS IMessage _                       ' __in LPMESSAGE pMessage
   , BYVAL fSameAsLoad AS DWORD _                       ' __in ULONG fSameAsLoad
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveCompleted ( _                             ' VTable offset = 32
     BYVAL pMessage AS IMessage _                       ' __in LPMESSAGE pMessage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HandsOffMessage ( _                           ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/*-- IMAPIMessageSite ------------------------------------------------------*/

' ========================================================================================
' IMAPIMessageSite interface
' $IID_IMAPIMessageSite = GUID$("{00020370-0000-0000-C000-000000000046}")
' The IMAPIMessageSite interface manipulates messages and is implemented by the form
' viewer code typically a client application that responds to such manipulation.
' ========================================================================================

INTERFACE IMAPIMessageSite $IID_IMAPIMessageSite

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSession ( _                                ' VTable offset = 12
     BYREF ppSession AS IMAPISession _                  ' __out LPMAPISESSION * ppSession
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStore ( _                                  ' VTable offset = 16
     BYREF ppStore AS IMsgStore _                       ' __out LPMDB * ppStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFolder ( _                                 ' VTable offset = 20
     BYREF ppFolder AS IMAPIFolder _                    ' __out LPMAPIFOLDER * ppFolder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMessage ( _                                ' VTable offset = 24
     BYREF ppmsg AS IMessage _                          ' __out LPMESSAGE * ppmsg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFormManager ( _                            ' VTable offset = 28
     BYREF ppFormMgr AS IMAPIFormMgr _                  ' __out LPMAPIFORMMGR * ppFormMgr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NewMessage ( _                                ' VTable offset = 32
     BYVAL fComposeInFolder AS DWORD _                  ' __in  ULONG fComposeInFolder
   , BYVAL pFolderFocus AS IMAPIFolder _                ' __in  LPMAPIFOLDER pFolderFocus
   , BYVAL pPersistMessage AS IPersistMessage _         ' __in  LPPERSISTMESSAGE pPersistMessage
   , BYREF ppMessage AS IMessage _                      ' __out LPMESSAGE * ppMessage
   , BYREF ppMessageSite AS IMAPIMessageSite _          ' __out LPMAPIMESSAGESITE * ppMessageSite
   , BYREF ppViewContext AS IMAPIViewContext _          ' __out LPMAPIVIEWCONTEXT * ppViewContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyMessage ( _                               ' VTable offset = 36
     BYVAL pFolderDestination AS IMAPIFolder _          ' __in  LPMAPIFOLDER pFolderDestination
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MoveMessage ( _                               ' VTable offset = 40
     BYVAL pFolderDestination AS IMAPIFolder _          ' __in  LPMAPIFOLDER pFolderDestination
   , BYVAL pViewContext AS IMAPIViewContext _           ' __in  LPMAPIVIEWCONTEXT pViewContext
   , BYREF prcPosRect AS RECT _                         ' __in  LPCRECT prcPosRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteMessage ( _                             ' VTable offset = 44
     BYVAL pViewContext AS IMAPIViewContext _           ' __in  LPMAPIVIEWCONTEXT pViewContext
   , BYREF prcPosRect AS RECT _                         ' __in  LPCRECT prcPosRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveMessage ( _                               ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SubmitMessage ( _                             ' VTable offset = 52
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSiteStatus ( _                             ' VTable offset = 56
     BYREF lpulStatus AS DWORD _                        ' __out LPULONG lpulStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/*-- IMAPIForm -------------------------------------------------------------*/
'/* This interface is implemented by forms for the benefit of viewers.
' * One method (ShutdownForm) is provided such that simple forms implementing
' * only IMAPIForm and IPersistMessage have reasonable embedding behavior.
' */

' ========================================================================================
' IMAPIForm interface
' $IID_IMAPIForm = GUID$("{00020327-0000-0000-C000-000000000046}")
' The IMAPIForm interface is used by form viewers to work with form view contexts and form
' notification, to perform form verbs, and to shut down forms.
' ========================================================================================
INTERFACE IMAPIForm $IID_IMAPIForm

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetViewContext ( _                            ' VTable offset = 12
     BYVAL pViewContext AS IMAPIViewContext _           ' __in LPMAPIVIEWCONTEXT pViewContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetViewContext ( _                            ' VTable offset = 16
     BYREF ppViewContext AS IMAPIViewContext _          ' __out LPMAPIVIEWCONTEXT * ppViewContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShutdownForm ( _                              ' VTable offset = 20
     BYVAL ulSaveOptions AS DWORD _                     ' __in ULONG ulSaveOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoVerb ( _                                    ' VTable offset = 24
     BYVAL iVerb AS LONG _                              ' __in LONG iVerb
   , BYVAL lpViewContext AS IMAPIViewContext _          ' __in LPMAPIVIEWCONTEXT lpViewContext /* can be null */
   , BYVAL hwndParent AS DWORD _                        ' __in ULONG hwndParent
   , BYREF lprcPosRect AS RECT _                        ' __in LPCRECT lprcPosRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 28
     BYVAL pAdvise AS LONG _                            ' __in LPMAPIVIEWADVISESINK pAdvise
   , BYREF pdwStatus AS DWORD _                         ' __out ULONG * pdwStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 32
     BYREF ulConnection AS DWORD _                      ' __in ULONG ulConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' SAVEOPTS enum
%SAVEOPTS_SAVEIFDIRTY = 0
%SAVEOPTS_NOSAVE      = 1
%SAVEOPTS_PROMPTSAVE  = 2


'/*-- IMAPIViewContext ------------------------------------------------------*/
'/* Implemented by viewers to support next/previous in forms.
' */

'/* Structure passed in GetPrintSetup  */

' // Size = 20 bytes
TYPE FORMPRINTSETUP DWORD
   ulFlags             AS DWORD   ' ULONG       /* MAPI_UNICODE */
   hDevMode            AS DWORD   ' HDEVMODE
   hDevNames           AS DWORD   ' HDEVNAMES
   ulFirstPageNumber   AS DWORD   ' ULONG
   ulFPrintAttachments AS DWORD   ' ULONG
END TYPE

'/* Values for pulFormat in GetSaveStream */

%SAVE_FORMAT_TEXT     = 1
%SAVE_FORMAT_RICHTEXT = 2

'/* Values from 0 to 0x3fff are reserved for future definition by Microsoft */

' ========================================================================================
' IMAPIViewContext interface
' $IID_IMAPIViewContext = GUID$("{00020321-0000-0000-C000-000000000046}")
' The IMAPIViewContext interface manages a form in a client application's form viewer.
' ========================================================================================
INTERFACE IMAPIViewContext $IID_IMAPIViewContext

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAdviseSink ( _                             ' VTable offset = 12
     BYVAL pmvns AS IMAPIFormAdviseSink _               ' __in  LPMAPIFORMADVISESINK pmvns
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ActivateNext ( _                              ' VTable offset = 16
     BYVAL ulDir AS DWORD _                             ' __in  ULONG ulDir
   , BYREF prcPosRect AS RECT _                         ' __in  LPCRECT prcPosRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrintSetup ( _                             ' VTable offset = 20
     BYVAL ulFlags AS DWORD _                           ' __in  ULONG ulFlags
   , BYREF lppFormPrintSetup AS FORMPRINTSETUP _        ' __out LPFORMPRINTSETUP * lppFormPrintSetup
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSaveStream ( _                             ' VTable offset = 24
     BYREF pulFlags AS DWORD _                          ' __out ULONG * pulFlags
   , BYREF pulFormat AS DWORD _                         ' __out ULONG * pulFormat
   , BYREF ppstm AS IStream _                           ' __out LPSTREAM * ppstm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetViewStatus ( _                             ' VTable offset = 28
     BYREF lpulStatus AS DWORD _                        ' __out LPULONG lpulStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


%VCSTATUS_NEXT           = &H00000001
%VCSTATUS_PREV           = &H00000002
%VCSTATUS_MODAL          = &H00000004
%VCSTATUS_INTERACTIVE    = &H00000008
%VCSTATUS_READONLY       = &H00000010
%VCSTATUS_DELETE         = &H00010000
%VCSTATUS_COPY           = &H00020000
%VCSTATUS_MOVE           = &H00040000
%VCSTATUS_SUBMIT         = &H00080000
%VCSTATUS_DELETE_IS_MOVE = &H00100000
%VCSTATUS_SAVE           = &H00200000
%VCSTATUS_NEW_MESSAGE    = &H00400000

%VCDIR_NEXT              = %VCSTATUS_NEXT
%VCDIR_PREV              = %VCSTATUS_PREV
%VCDIR_DELETE            = %VCSTATUS_DELETE
%VCDIR_MOVE              = %VCSTATUS_MOVE

'/*-- IMAPIFormAdviseSink ---------------------------------------------------*/
'/* Part of form server, held by view; receives notifications from the view.
' *
' * This part of the form server, but is not an interface on the form
' * object.  This means that clients should not expect to QueryInterface
' * from an IMAPIForm* or IOleObject* to this interface, or vice versa.
' */

' ========================================================================================
' IMAPIFormAdviseSink interface
' $IID_IMAPIViewContext = GUID$("{0002032F-0000-0000-C000-000000000046}")
' Used by form viewers to receive notifications from forms.
' ========================================================================================
INTERFACE IMAPIFormAdviseSink $IID_IMAPIFormAdviseSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnChange ( _                                  ' VTable offset = 12
     BYVAL ulDir AS DWORD _                             ' __in ULONG ulDir
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnActivateNext ( _                            ' VTable offset = 16
     BYREF lpszMessageClass AS ASCIIZ _                 ' __in  LPCSTR lpszMessageClass
   , BYVAL ulMessageStatus AS DWORD _                   ' __in  ULONG ulMessageStatus
   , BYVAL ulMessageFlags AS DWORD _                    ' __in  ULONG ulMessageFlags
   , BYREF ppPersistMessage AS IPersistMessage _        ' __out LPPERSISTMESSAGE * ppPersistMessage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/*-- IMAPIViewAdviseSink ---------------------------------------------------*/
'/* Part of view context, held by form; receives notifications from the form.
' */

' ========================================================================================
' IMAPIViewAdviseSink interface
' $IID_IMAPIViewAdviseSink = GUID$("{0002032B-0000-0000-C000-000000000046}")
' Used by form viewers to receive notifications from forms.
' ========================================================================================
INTERFACE IMAPIViewAdviseSink $IID_IMAPIViewAdviseSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnShutdown ( _                                ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnNewMessage ( _                              ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnPrint ( _                                   ' VTable offset = 20
     BYVAL dwPageNumber AS DWORD _                      ' __in ULONG dwPageNumber
   , BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnSubmitted ( _                               ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnSaved ( _                                   ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/*-- IMAPIFormInfo ---------------------------------------------------------*/
'/* Is implemented by registries.  Describes the form.
' */

'/* Single enum value */

' // Size = 8 bytes
TYPE SMAPIFormPropEnumVal DWORD   ' /* fpev */
   pszDisplayName AS ASCIIZ PTR   ' LPTSTR  /* carries the display string */
   nVal           AS DWORD        ' ULONG   /* the value for the above enumeration */
END TYPE

'/* MAPI Form property descriptor */

'/*
' * Values for the tag in the SMAPIFormProp structure
' *
' * Microsoft reserves the range from 0 to 0x3FFF for future use in its other
' * forms registry implementations.
' */

'typedef ULONG FORMPROPSPECIALTYPE;

%FPST_VANILLA            = 0
%FPST_ENUM_PROP          = 1

'typedef struct
'{
'   ULONG ulFlags;           /* Contains MAPI_UNICODE if strings are UNICODE */
'   ULONG nPropType;         /* type of the property, hiword is 0 */
'   MAPINAMEID nmid;         /* id of the property */
'   LPTSTR pszDisplayName;
'   FORMPROPSPECIALTYPE nSpecialType;   /* tag for the following union */
'   union
'   {
'      struct
'      {
'         MAPINAMEID nmidIdx;
'         ULONG cfpevAvailable;   /* # of enums */
'         LPMAPIFORMPROPENUMVAL pfpevAvailable;
'      } s1;               /* Property String/Number association Enumeration */
'   } u;
'} SMAPIFormProp, * LPMAPIFORMPROP;

' // Size = 20 bytes
TYPE SMAPIFormProp_s1 DWORD
   nmidIdx AS MAPINAMEID          ' MAPINAMEID
   cfpevAvailable AS DWORD        ' ULONG
   pfpevAvailable AS DWORD        ' LPMAPIFORMPROPENUMVAL
END TYPE

' // Size = 48 bytes
TYPE SMAPIFormProp DWORD
   ulFlags        AS DWORD        ' ULONG
   nPropType      AS DWORD        ' ULONH
   nmid           AS MAPINAMEID   ' MAPINAMEID
   pszDisplayName AS ASCIIZ PTR   ' LPTSTR
   nSpecialType   AS DWORD        ' FORMPROPSPECIALTYPE
   SMAPIFormProp_s1
END TYPE

'/* Array of form properties */

' // Size = 56 bytes
TYPE SMAPIFormPropArray DWORD
   cProps AS  DWORD                            ' ULONG
   ulPad  AS  DWORD                            ' ULONG  /* Pad to 8-byte alignment for insurance */
   aFormProp(%MAPI_DIM - 1) AS SMAPIFormProp   ' SMAPIFormProp [variable-length array]
END TYPE

'/* Structure defining the layout of an mapi verb description */

' // Size = 20 bytes
TYPE SMAPIVerb DWORD
   lVerb      AS DWORD        ' ULONG
   szVerbname AS ASCIIZ PTR   ' LPTSTR
   fuFlags    AS DWORD        ' DWORD
   grfAttribs AS DWORD        ' DWORD
   ulFlags    AS DWORD        ' ULONG /* Either 0 or MAPI_UNICODE */
END TYPE

'/* Structure used for returning arrays of mapi verbs */

' // Size = 24 bytes
TYPE SMAPIVerbArray DWORD
   cMAPIVerb AS DWORD                      ' ULONG  /* Number of verbs in the structure */
   aMAPIVerb(%MAPI_DIM - 1) AS SMAPIVerb   ' SMAPIVerb [variable-length array]
END TYPE

' ========================================================================================
' IMAPIFormInfo interface (inherits from IMAPIProp)
' $IID_IMAPIFormInfo = GUID$("{00020324-0000-0000-C000-000000000046}")
' The IMAPIFormInfo interface gives client applications access to useful properties
' particular to form definition. By keeping form information in a separate object, the
' form library provider can describe a form to a client without activating the form.
' ========================================================================================
INTERFACE IMAPIFormInfo $IID_IMAPIFormInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offser = 12
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveChanges ( _                               ' VTable offser = 16
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProps ( _                                  ' VTable offser = 20
     BYVAL lpPropTagArray AS DWORD _                    ' __in LPSPropTagArray lpPropTagArray
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcValues AS DWORD _                         ' __out ULONG * lpcValues
   , BYREF lppPropArray AS DWORD _                      ' __out LPSPropValue * lppPropArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropList ( _                               ' VTable offser = 24
     BYVAL ulFlags AS DWORD _                           ' __in ulFlags
   , BYREF lppPropTagArray AS DWORD _                   ' __out LPSPropTagArray * lppPropTagArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenProperty ( _                              ' VTable offser = 28
     BYVAL ulPropTag AS DWORD _                         ' __in ULONG ulPropTag
   , BYREF lpiid AS GUID _                              ' __in LPCIID lpiid
   , BYVAL ulInterfaceOptions AS DWORD _                ' __in ULONG ulInterfaceOptions
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppUnk AS IUnknown _                         ' __out LPUNKNOWN * lppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProps ( _                                  ' VTable offser = 32
     BYVAL cValues AS DWORD _                           ' __in ULONG cValues
   , BYVAL lpPropArray AS SPropValue PTR _              ' __in LPSPropValue lpPropArray [array]
   , BYVAL LPSPropProblemArray AS SPropProblemArray PTR _ ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteProps ( _                               ' VTable offser = 36
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL LPSPropProblemArray AS SPropProblemArray PTR _ ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offser = 40
     BYVAL ciidExclude AS DWORD _                       ' __in ULONG ciidExclude
   , BYREF rgiidExclude AS GUID _                       ' __in LPCIID rgiidExclude
   , BYVAL lpExcludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpExcludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS DWORD _                       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyProps ( _                                 ' VTable offser = 44
     BYVAL lpIncludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpIncludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNamesFromIDs ( _                           ' VTable offser = 48
     BYVAL lppPropTags AS SPropTagArray PTR _           ' __inout LPSPropTagArray * lppPropTags
   , BYREF lpPropSetGuid AS GUID _                      ' __in LPGUID lpPropSetGuid
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcPropNames AS DWORD _                      ' __out ULONG * lpcPropNames
   , BYREF lpppPropNames AS DWORD _                     ' __out LPMAPINAMEID * * lpppPropNames [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIDsFromNames ( _                           ' VTable offser = 52
     BYVAL cPropNames AS DWORD _                        ' __in ULONG cPropNames
   , BYVAL lppPropNames AS MAPINAMEID PTR _             ' __in LPMAPINAMEID * lppPropNames [array]
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppPropTags AS DWORD _                       ' __out LPSPropTagArray * lppPropTags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CalcFormPropSet ( _                           ' VTable offser = 56
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF ppFormPropArray AS DWORD  _                  ' __out LPMAPIFORMPROPARRAY * ppFormPropArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CalcVerbSet ( _                               ' VTable offser = 60
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF ppMAPIVerbArray AS DWORD _                   ' __out LPMAPIVERBARRAY * ppMAPIVerbArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MakeIconFromBinary ( _                        ' VTable offser = 64
     BYVAL nPropID AS DWORD _                           ' __in ULONG nPropID
   , BYREF phicon AS DWORD _                            ' __out HICON* phicon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveForm ( _                                  ' VTable offser = 68
     BYREF szFileName AS ASCIIZ _                       ' __in LPCTSTR szFileName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenFormContainer ( _                         ' VTable offser = 72
     BYREF ppformcontainer AS IMAPIFormContainer _      ' __out LPMAPIFORMCONTAINER * ppformcontainer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/* Enumeration of permissible values for PR_FORM_MESSAGE_BEHAVIOR */

%MAPI_MESSAGE_BEHAVIOR_IPM = 0
%MAPI_MESSAGE_BEHAVIOR_FOLDER = 1


'/*-- IMAPIFormMgr ----------------------------------------------------------*/
'/* The client-visible interface for form resolution and dispatch.
' */

'/* Structure containing an array of message class strings */

' // Size = 8 bytes
TYPE SMessageClassArray DWORD
   cValues AS DWORD                              ' ULONG
   aMessageClass(%MAPI_DIM - 1) AS ASCIIZ PTR    ' LPCSTR [variable-length array]
END TYPE

'/* Structure containing an array of IMAPIFormInfo interfaces */

' // Size = 8 bytes
TYPE SMAPIFormInfoArray DWORD
   cValues AS DWORD                    ' ULONG
   aFormInfo(%MAPI_DIM - 1) AS DWORD   ' LPMAPIFORMINFO [variable-length array]
END TYPE

'/* Flags for IMAPIFormMgr::SelectFormContainer */

%MAPIFORM_SELECT_ALL_REGISTRIES           = 0
%MAPIFORM_SELECT_FOLDER_REGISTRY_ONLY     = 1
%MAPIFORM_SELECT_NON_FOLDER_REGISTRY_ONLY = 2

'/* Flags for IMAPIFormMgr::CalcFormPropSet */

%FORMPROPSET_UNION              = 0
%FORMPROPSET_INTERSECTION       = 1

'/* Flags for IMAPIFormMgr::ResolveMessageClass and
'   IMAPIFormMgr::ResolveMultipleMessageClasses */

%MAPIFORM_EXACTMATCH            = &H0020

' ========================================================================================
' IMAPIFormMgr interface
' $IID_IMAPIFormMgr = GUID$("{00020322-0000-0000-C000-000000000046}")
' The IMAPIFormMgr interface is used by form viewers to get information about and activate
' form servers.
' ========================================================================================
INTERFACE IMAPIFormMgr $IID_IMAPIFormMgr

   INHERIT IUnknown

   ' =====================================================================================
   METHOD LoadForm ( _                                  ' VTable offset = 12
     BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpszMessageClass AS ASCIIZ _                 ' __in LPCSTR lpszMessageClass
   , BYVAL ulMessageStatus AS DWORD _                   ' __in ULONG ulMessageStatus
   , BYVAL ulMessageFlags AS DWORD _                    ' __in ULONG ulMessageFlags
   , BYVAL pFolderFocus AS IMAPIFolder _                ' __in LPMAPIFOLDER pFolderFocus
   , BYVAL pMessageSite AS IMAPIMessageSite _           ' __in LPMAPIMESSAGESITE pMessageSite
   , BYVAL pmsg AS IMessage _                           ' __in LPMESSAGE pmsg
   , BYVAL pViewContext AS IMAPIViewContext _           ' __in LPMAPIVIEWCONTEXT pViewContext
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObj AS IUnknown _                         ' __out LPVOID *ppvObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResolveMessageClass ( _                       ' VTable offset = 16
     BYREF szMsgClass AS ASCIIZ _                       ' __in LPCSTR szMsgClass
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL pFolderFocus AS IMAPIFolder _                ' __in LPMAPIFOLDER pFolderFocus /* can be null */
   , BYREF ppResult AS IMAPIFormInfo _                  ' __out LPMAPIFORMINFO* ppResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResolveMultipleMessageClasses ( _             ' VTable offset = 20
     BYVAL pMsgClasses AS DWORD _                       ' __in LPSMESSAGECLASSARRAY pMsgClasses
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL pFolderFocus AS IMAPIFolder _                ' __in LPMAPIFOLDER pFolderFocus /* can be null */
   , BYREF pfrminfoarray AS DWORD _                     ' __out LPSMAPIFORMINFOARRAY * pfrminfoarray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CalcFormPropSet ( _                           ' VTable offset = 24
     BYVAL pfrminfoarray AS SMAPIFormInfoArray PTR _    ' __in LPSMAPIFORMINFOARRAY pfrminfoarray
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF ppResults AS DWORD _                         ' __out LPMAPIFORMPROPARRAY* ppResults
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateForm ( _                                ' VTable offset = 28
     BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL pfrminfoToActivate AS IMAPIFormInfo _        ' __in LPMAPIFORMINFO pfrminfoToActivate
   , BYREF refiidToAsk AS GUID _                        ' __in REFIID refiidToAsk
   , BYREF ppvObj AS IUnknown _                         ' __out LPVOID* ppvObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectForm ( _                                ' VTable offset = 32
     BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF pszTitle AS ASCIIZ _                         ' __in LPCTSTR pszTitle
   , BYVAL pfld AS IMAPIFolder _                        ' __in LPMAPIFOLDER pfld
   , BYREF ppfrminfoReturned AS IMAPIFormInfo _         ' __out LPMAPIFORMINFO * ppfrminfoReturned
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectMultipleForms ( _                       ' VTable offset = 36
     BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF pszTitle AS ASCIIZ _                         ' __in LPCTSTR pszTitle
   , BYVAL pfld AS IMAPIFolder _                        ' __in LPMAPIFOLDER pfld
   , BYVAL pfrminfoarray AS SMAPIFormInfoArray PTR _    ' __in LPSMAPIFORMINFOARRAY pfrminfoarray
   , BYREF ppfrminfoarray AS DWORD _                    ' __out LPSMAPIFORMINFOARRAY * ppfrminfoarray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectFormContainer ( _                       ' VTable offset = 40
     BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppfcnt AS IMAPIFormContainer _              ' __out LPMAPIFORMCONTAINER * lppfcnt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenFormContainer ( _                         ' VTable offset = 44
     BYVAL hfrmreg AS DWORD _                           ' __in HFRMREG hfrmreg
   , BYVAL lpunk AS IUnknown _                          ' __in LPUNKNOWN lpunk
   , BYREF lppfcnt AS IMAPIFormContainer _              ' __out LPMAPIFORMCONTAINER * lppfcnt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PrepareForm ( _                               ' VTable offset = 48
     BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL pfrminfo AS IMAPIFormInfo _                  ' __in LPMAPIFORMINFO pfrminfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsInConflict ( _                              ' VTable offset = 52
     BYVAL ulMessageFlags AS DWORD _                    ' __in ULONG ulMessageFlags
   , BYVAL ulMessageStatus AS DWORD _                   ' __in ULONG ulMessageStatus
   , BYREF szMessageClass AS ASCIIZ _                   ' __in LPCSTR szMessageClass
   , BYVAL pFolderFocus AS IMAPIFolder _                ' __in LPMAPIFOLDER pFolderFocus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

'/* Platform numbers (used in .CFG files for forms) */

%MAPIFORM_CPU_X86               = 1
%MAPIFORM_CPU_MIP               = 2
%MAPIFORM_CPU_AXP               = 3
%MAPIFORM_CPU_PPC               = 4
%MAPIFORM_CPU_M68               = 5

%MAPIFORM_OS_WIN_31             = 1
%MAPIFORM_OS_WINNT_35           = 2
%MAPIFORM_OS_WIN_95             = 3
%MAPIFORM_OS_MAC_7x             = 4
%MAPIFORM_OS_WINNT_40           = 5

'#define MAPIFORM_PLATFORM(CPU, OS) ((ULONG) ((((ULONG) CPU) << 16) | OS))

FUNCTION MAPIFORM_PLATFORM (BYVAL CPU AS DWORD, BYVAL OS AS DWORD) AS DWORD
   SHIFT LEFT CPU, 16
   FUNCTION = CPU OR OS
END FUNCTION


'/*-- IMAPIFormContainer -------------------------------------------------*/

'/*  Flags for IMAPIFormMgr::CalcFormPropSet */

'/* #define FORMPROPSET_UNION            0   */
'/* #define FORMPROPSET_INTERSECTION     1   */

'/*  Flags for IMAPIFormMgr::InstallForm     */

%MAPIFORM_INSTALL_DIALOG                = %MAPI_DIALOG
%MAPIFORM_INSTALL_OVERWRITEONCONFLICT   = &H0010

'/*  Flags for IMAPIFormContainer::ResolveMessageClass and
'    IMAPIFormContainer::ResolveMultipleMessageClasses */
'/* #define MAPIFORM_EXACTIMATCH    0x0020   */

' ========================================================================================
' IMAPIFormContainer interface
' $IID_IMAPIFormContainer = GUID$("{0002032E-0000-0000-C000-000000000046}")
' The IMAPIFormContainer interface manages forms within form libraries. This interface is
' used to create application-specific form libraries.
' ========================================================================================
INTERFACE IMAPIFormContainer $IID_IMAPIFormContainer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InstallForm ( _                               ' VTable offset = 12
     BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF szCfgPathName AS ASCIIZ _                    ' __in LPCTSTR szCfgPathName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveForm ( _                                ' VTable offset = 16
     BYREF szMessageClass AS ASCIIZ _                   ' __in LPCSTR szMessageClass
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResolveMessageClass ( _                       ' VTable offset = 20
     BYREF szMessageClass AS ASCIIZ _                   ' __in LPCSTR szMessageClass
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF pforminfo AS IMAPIFormInfo _                 ' __out LPMAPIFORMINFO * pforminfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResolveMultipleMessageClasses ( _             ' VTable offset = 24
     BYVAL pMsgClassArray AS DWORD _                    ' __in LPSMESSAGECLASSARRAY pMsgClassArray
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF ppfrminfoarray AS DWORD _                    ' __out LPSMAPIFORMINFOARRAY * ppfrminfoarray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CalcFormPropSet ( _                           ' VTable offset = 28
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF ppResults AS DWORD _                         ' __out LPMAPIFORMPROPARRAY * ppResults
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplay ( _                                ' VTable offset = 32
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF pszDisplayName AS ASCIIZ _                   ' __out LPTSTR * pszDisplayName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/*-- IMAPIFormFactory ------------------------------------------------------*/

' ========================================================================================
' IMAPIFormFactory interface
' $IID_IMAPIFormFactory = GUID$("{00020350-0000-0000-C000-000000000046}")
' The IMAPIFormFactory interface supports the use of configurable run-time forms in
' distributed computing environments.
' ========================================================================================
INTERFACE IMAPIFormFactory $IID_IMAPIFormFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateClassFactory ( _                        ' VTable offset = 12
     BYREF clsidForm AS GUID _                          ' __in REFCLSID clsidForm
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppClassFactory AS IClassFactory _           ' __out LPCLASSFACTORY * lppClassFactory
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockServer ( _                                ' VTable offset = 16
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL fLockServer AS DWORD _                       ' __in ULONG fLockServer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE
