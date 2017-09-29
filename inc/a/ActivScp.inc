' ########################################################################################
' Microsoft Windows
' File: ActivScp.inc
' Contents: Declarations for ActiveX Scripting host applications and script engines.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ACTIVSCP_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "ocidl.inc"

' CLSIDs (not included in the C header)

$CLSID_VBScript = GUID$("{B54F3741-5B07-11CF-A4B0-00AA004A55E8}")
$CLSID_JScript  = GUID$("{F414C260-6AC0-11CF-B6D1-00AA00BBBB58}")

'/* GUIDs
' ********/

#IF NOT %DEF(%NO_SCRIPT_GUIDS)
$CATID_ActiveScript                    = GUID$("{F0B7A1A1-9847-11cf-8F20-00805F2CD064}")
$CATID_ActiveScriptParse               = GUID$("{F0B7A1A2-9847-11cf-8F20-00805F2CD064}")
$CATID_ActiveScriptEncode              = GUID$("{F0B7A1A3-9847-11cf-8F20-00805F2CD064}")
$IID_IActiveScript                     = GUID$("{BB1A2AE1-A4F9-11cf-8F20-00805F2CD064}")
$IID_IActiveScriptParse                = GUID$("{BB1A2AE2-A4F9-11cf-8F20-00805F2CD064}")
$IID_IActiveScriptParse32              = GUID$("{BB1A2AE2-A4F9-11cf-8F20-00805F2CD064}")
$IID_IActiveScriptParse64              = GUID$("{C7EF7658-E1EE-480E-97EA-D52CB4D76D17}")
$IID_IActiveScriptEncode               = GUID$("{BB1A2AE3-A4F9-11cf-8F20-00805F2CD064}")
$IID_IActiveScriptHostEncode           = GUID$("{BEE9B76E-CFE3-11d1-B747-00C04FC2B085}")
$IID_IActiveScriptParseProcedureOld    = GUID$("{1CFF0050-6FDD-11d0-9328-00A0C90DCAA9}")
$IID_IActiveScriptParseProcedureOld32  = GUID$("{1CFF0050-6FDD-11d0-9328-00A0C90DCAA9}")
$IID_IActiveScriptParseProcedureOld64  = GUID$("{21F57128-08C9-4638-BA12-22D15D88DC5C}")
$IID_IActiveScriptParseProcedure       = GUID$("{AA5B6A80-B834-11d0-932F-00A0C90DCAA9}")
$IID_IActiveScriptParseProcedure32     = GUID$("{AA5B6A80-B834-11d0-932F-00A0C90DCAA9}")
$IID_IActiveScriptParseProcedure64     = GUID$("{C64713B6-E029-4CC5-9200-438B72890B6A}")
$IID_IActiveScriptParseProcedure2      = GUID$("{71EE5B20-FB04-11d1-B3A8-00A0C911E8B2}")
$IID_IActiveScriptParseProcedure2_32   = GUID$("{71EE5B20-FB04-11d1-B3A8-00A0C911E8B2}")
$IID_IActiveScriptParseProcedure2_64   = GUID$("{FE7C4271-210C-448D-9F54-76DAB7047B28}")
$IID_IActiveScriptSite                 = GUID$("{DB01A1E3-A42B-11cf-8F20-00805F2CD064}")
$IID_IActiveScriptSiteTraceInfo        = GUID$("{4B7272AE-1955-4bfe-98B0-780621888569}")
$IID_IActiveScriptSiteWindow           = GUID$("{D10F6761-83E9-11cf-8F20-00805F2CD064}")
$IID_IActiveScriptSiteInterruptPoll    = GUID$("{539698A0-CDCA-11CF-A5EB-00AA0047A063}")
$IID_IActiveScriptSiteUIControl        = GUID$("{AEDAE97E-D7EE-4796-B960-7F092AE844AB}")
$IID_IActiveScriptError                = GUID$("{EAE1BA61-A4ED-11cf-8F20-00805F2CD064}")
$IID_IActiveScriptError64              = GUID$("{B21FB2A1-5B8F-4963-8C21-21450F84ED7F}")
$IID_IBindEventHandler                 = GUID$("{63CDBCB0-C1B1-11d0-9336-00A0C90DCAA9}")
$IID_IActiveScriptStats                = GUID$("{B8DA6310-E19B-11d0-933C-00A0C90DCAA9}")
$IID_IActiveScriptProperty             = GUID$("{4954E0D0-FBC7-11D1-8410-006008C3FBFC}")
$IID_ITridentEventSink                 = GUID$("{1DC9CA50-06EF-11d2-8415-006008C3FBFC}")
$IID_IActiveScriptGarbageCollector     = GUID$("{6AA2C4A0-2B53-11d4-A2A0-00104BD35090}")
$IID_IActiveScriptSIPInfo              = GUID$("{764651D0-38DE-11d4-A2A3-00104BD35090}")
$IID_IActiveScriptTraceInfo            = GUID$("{C35456E7-BEBF-4a1b-86A9-24D56BE8B369}")
$OID_VBSSIP                            = GUID$("{1629F04E-2799-4db5-8FE5-ACE10F17EBAB}")
$OID_JSSIP                             = GUID$("{06C9E010-38CE-11d4-A2A3-00104BD35090}")
$OID_WSFSIP                            = GUID$("{1A610570-38CE-11d4-A2A3-00104BD35090}")
$IID_IActiveScriptStringCompare        = GUID$("{58562769-ED52-42f7-8403-4963514E1F11}")
#ENDIF ' // _NO_SCRIPT_GUIDS

'// Constants used by ActiveX Scripting:
'//

'/* IActiveScript::AddNamedItem() input flags */

%SCRIPTITEM_ISVISIBLE            = &H00000002???
%SCRIPTITEM_ISSOURCE             = &H00000004???
%SCRIPTITEM_GLOBALMEMBERS        = &H00000008???
%SCRIPTITEM_ISPERSISTENT         = &H00000040???
%SCRIPTITEM_CODEONLY             = &H00000200???
%SCRIPTITEM_NOCODE               = &H00000400???

%SCRIPTITEM_ALL_FLAGS            = %SCRIPTITEM_ISSOURCE      OR _
                                   %SCRIPTITEM_ISVISIBLE     OR _
                                   %SCRIPTITEM_ISPERSISTENT  OR _
                                   %SCRIPTITEM_GLOBALMEMBERS OR _
                                   %SCRIPTITEM_NOCODE        OR _
                                   %SCRIPTITEM_CODEONLY

'/* IActiveScript::AddTypeLib() input flags */

%SCRIPTTYPELIB_ISCONTROL         = &H00000010???
%SCRIPTTYPELIB_ISPERSISTENT      = &H00000040???
%SCRIPTTYPELIB_ALL_FLAGS         = %SCRIPTTYPELIB_ISCONTROL OR _
                                   %SCRIPTTYPELIB_ISPERSISTENT

'/* IActiveScriptParse::AddScriptlet() and IActiveScriptParse::ParseScriptText() input flags */

%SCRIPTTEXT_DELAYEXECUTION       = &H00000001???
%SCRIPTTEXT_ISVISIBLE            = &H00000002???
%SCRIPTTEXT_ISEXPRESSION         = &H00000020???
%SCRIPTTEXT_ISPERSISTENT         = &H00000040???
%SCRIPTTEXT_HOSTMANAGESSOURCE    = &H00000080???
%SCRIPTTEXT_ISXDOMAIN            = &H00000100???
%SCRIPTTEXT_ALL_FLAGS            = %SCRIPTTEXT_DELAYEXECUTION    OR _
                                   %SCRIPTTEXT_ISVISIBLE         OR _
                                   %SCRIPTTEXT_ISEXPRESSION      OR _
                                   %SCRIPTTEXT_ISPERSISTENT      OR _
                                   %SCRIPTTEXT_HOSTMANAGESSOURCE OR _
                                   %SCRIPTTEXT_ISXDOMAIN

'/* IActiveScriptParseProcedure::ParseProcedureText() input flags */

%SCRIPTPROC_ISEXPRESSION         = &H00000020???
%SCRIPTPROC_HOSTMANAGESSOURCE    = &H00000080???
%SCRIPTPROC_IMPLICIT_THIS        = &H00000100???
%SCRIPTPROC_IMPLICIT_PARENTS     = &H00000200???
%SCRIPTPROC_ISXDOMAIN            = &H00000400???
%SCRIPTPROC_ALL_FLAGS            = %SCRIPTPROC_HOSTMANAGESSOURCE OR _
                                   %SCRIPTPROC_ISEXPRESSION      OR _
                                   %SCRIPTPROC_IMPLICIT_THIS     OR _
                                   %SCRIPTPROC_IMPLICIT_PARENTS  OR _
                                   %SCRIPTPROC_ISXDOMAIN

'/* IActiveScriptSite::GetItemInfo() input flags */

%SCRIPTINFO_IUNKNOWN             = &H00000001???
%SCRIPTINFO_ITYPEINFO            = &H00000002???
%SCRIPTINFO_ALL_FLAGS            = %SCRIPTINFO_IUNKNOWN OR _
                                   %SCRIPTINFO_ITYPEINFO

'/* IActiveScript::Interrupt() Flags */

%SCRIPTINTERRUPT_DEBUG           = &H00000001???
%SCRIPTINTERRUPT_RAISEEXCEPTION  = &H00000002???
%SCRIPTINTERRUPT_ALL_FLAGS       = %SCRIPTINTERRUPT_DEBUG OR _
                                   %SCRIPTINTERRUPT_RAISEEXCEPTION

'/* IActiveScriptStats::GetStat() values */

%SCRIPTSTAT_STATEMENT_COUNT      = 1
%SCRIPTSTAT_INSTRUCTION_COUNT    = 2
%SCRIPTSTAT_INTSTRUCTION_TIME    = 3
%SCRIPTSTAT_TOTAL_TIME           = 4

'/* IActiveScriptEncode::AddSection() input flags */

%SCRIPT_ENCODE_SECTION               = &H00000001???

%SCRIPT_ENCODE_DEFAULT_LANGUAGE      = &H00000001???
%SCRIPT_ENCODE_NO_ASP_LANGUAGE       = &H00000002???

'/* Properties for IActiveScriptProperty */
%SCRIPTPROP_NAME                     = &H00000000???
%SCRIPTPROP_MAJORVERSION             = &H00000001???
%SCRIPTPROP_MINORVERSION             = &H00000002???
%SCRIPTPROP_BUILDNUMBER              = &H00000003???

%SCRIPTPROP_DELAYEDEVENTSINKING      = &H00001000???
%SCRIPTPROP_CATCHEXCEPTION           = &H00001001???
%SCRIPTPROP_CONVERSIONLCID           = &H00001002???
%SCRIPTPROP_HOSTSTACKREQUIRED        = &H00001003???

%SCRIPTPROP_DEBUGGER                 = &H00001100???
%SCRIPTPROP_JITDEBUG                 = &H00001101???

%SCRIPTPROP_GCCONTROLSOFTCLOSE       = &H00002000???

%SCRIPTPROP_INTEGERMODE              = &H00003000???
%SCRIPTPROP_STRINGCOMPAREINSTANCE    = &H00003001???

%SCRIPTPROP_INVOKEVERSIONING         = &H00004000???

'// These properties are defined and available, but are not
'// officially supported.
%SCRIPTPROP_HACK_FIBERSUPPORT        = &H70000000???
%SCRIPTPROP_HACK_TRIDENTEVENTSINK    = &H70000001???
%SCRIPTPROP_ABBREVIATE_GLOBALNAME_RESOLUTION  = &H70000002???

'/* script language version values for SCRIPTPROP_INVOKEVERSIONING property */

' Enum SCRIPTLANGUAGEVERSION
MACRO SCRIPTLANGUAGEVERSION_ENUM = LONG
%SCRIPTLANGUAGEVERSION_DEFAULT  = 0
%SCRIPTLANGUAGEVERSION_5_7	     = 1
%SCRIPTLANGUAGEVERSION_5_8	     = 2
%SCRIPTLANGUAGEVERSION_MAX	     = 255

' Enum SCRIPTSTATE
MACRO SCRIPTSTATE_ENUM = LONG
%SCRIPTSTATE_UNINITIALIZED      = 0
%SCRIPTSTATE_INITIALIZED        = 5
%SCRIPTSTATE_STARTED            = 1
%SCRIPTSTATE_CONNECTED          = 2
%SCRIPTSTATE_DISCONNECTED       = 3
%SCRIPTSTATE_CLOSED             = 4

' Enum SCRIPTTRACEINFO
MACRO SCRIPTTRACEINFO_ENUM = LONG
%SCRIPTTRACEINFO_SCRIPTSTART    = 0
%SCRIPTTRACEINFO_SCRIPTEND      = 1
%SCRIPTTRACEINFO_COMCALLSTART   = 2
%SCRIPTTRACEINFO_COMCALLEND     = 3
%SCRIPTTRACEINFO_CREATEOBJSTART = 4
%SCRIPTTRACEINFO_CREATEOBJEND   = 5
%SCRIPTTRACEINFO_GETOBJSTART    = 6
%SCRIPTTRACEINFO_GETOBJEND      = 7

'/* script thread state values */

' Enum SCRIPTTHREADSTATE
MACRO SCRIPTTHREADSTATE_ENUM = LONG
%SCRIPTTHREADSTATE_NOTINSCRIPT  = 0
%SCRIPTTHREADSTATE_RUNNING      = 1

'/* IActiveScriptCollectGarbage constants */

' Enum SCRIPTGCTYPE
MACRO SCRIPTGCTYPE_ENUM = LONG
%SCRIPTGCTYPE_NORMAL            = 0
%SCRIPTGCTYPE_EXHAUSTIVE        = 1

'/* IActiveScriptSiteUIControl constants*/

' Enum SCRIPTUICITEM
MACRO SCRIPTUICITEM_ENUM = LONG
%SCRIPTUICITEM_INPUTBOX         = 1
%SCRIPTUICITEM_MSGBOX           = 2

' Enum SCRIPTUICHANDLING
MACRO SCRIPTUICHANDLING_ENUM = LONG
%SCRIPTUICHANDLING_ALLOW        = 0
%SCRIPTUICHANDLING_NOUIERROR    = 1
%SCRIPTUICHANDLING_NOUIDEFAULT  = 2

'/* Thread IDs */

'typedef DWORD SCRIPTTHREADID;
MACRO SCRIPTTHREADID = DWORD

%SCRIPTTHREADID_CURRENT         = &HFFFFFFFF???   ' ((SCRIPTTHREADID)-1)
%SCRIPTTHREADID_BASE            = &HFFFFFFFE???   ' ((SCRIPTTHREADID)-2)
%SCRIPTTHREADID_ALL             = &HFFFFFFFD???   ' ((SCRIPTTHREADID)-3)

'/* Structures */

'/* Interfaces
' *************/

' ########################################################################################
' Interface name = IActiveScriptSite
' IID = {DB01A1E3-A42B-11cf-8F20-00805F2CD064}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveScriptSite_INTERFACE_DEFINED)
    %IActiveScriptSite_INTERFACE_DEFINED = 1

INTERFACE IActiveScriptSite $IID_IActiveScriptSite

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLCID ( _                                   ' VTable offset = 12
     BYREF plcid AS DWORD _                             ' __out LCID *plcid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemInfo ( _                               ' VTable offset = 16
     BYREF pstrName AS WSTRINGZ _                       ' __in LPCOLESTR pstrName
   , BYVAL dwReturnMask AS DWORD _                      ' __in DWORD dwReturnMask
   , BYREF ppiunkItem AS IUnknown _                     ' __out IUnknown **ppiunkItem
   , BYREF ppti AS ITypeInfo _                          ' __out ITypeInfo **ppti
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDocVersionString ( _                       ' VTable offset = 20
     BYREF pbstrVersion AS WSTRING _                    ' __out BSTR *pbstrVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnScriptTerminate ( _                         ' VTable offset = 24
     BYREF pvarResult AS VARIANT _                      ' __in const VARIANT *pvarResult
   , BYREF pexcepinfo AS EXCEPINFO _                    ' __in const EXCEPINFO *pexcepinfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnStateChange ( _                             ' VTable offset = 28
     BYVAL ssScriptState AS SCRIPTSTATE_ENUM _          ' __in SCRIPTSTATE ssScriptState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnScriptError ( _                             ' VTable offset = 32
     BYVAL pscripterror AS IActiveScriptError _         ' __in IActiveScriptError *pscripterror
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnEnterScript ( _                             ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnLeaveScript ( _                             ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptSite_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IActiveScriptError
' IID = {EAE1BA61-A4ED-11cf-8F20-00805F2CD064}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveScriptError_INTERFACE_DEFINED)
    %IActiveScriptError_INTERFACE_DEFINED = 1

INTERFACE IActiveScriptError $IID_IActiveScriptError

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetExceptionInfo ( _                          ' VTable offset = 12
     BYREF pexcepinfo AS EXCEPINFO _                    ' __out EXCEPINFO *pexcepinfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSourcePosition ( _                         ' VTable offset = 16
     BYREF pdwSourceContext AS DWORD _                  ' __out DWORD *pdwSourceContext
   , BYREF pulLineNumber AS DWORD _                     ' __out ULONG *pulLineNumber
   , BYREF plCharacterPosition AS LONG _                ' __out LONG *plCharacterPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSourceLineText ( _                         ' VTable offset = 20
     BYREF pbstrSourceLine AS WSTRING _                 ' __out BSTR *pbstrSourceLine
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptError_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IActiveScriptError64
' IID = {B21FB2A1-5B8F-4963-8C21-21450F84ED7F}
' Inherited interface = IActiveScriptError
' ########################################################################################

#IF NOT %DEF(%IActiveScriptError64_INTERFACE_DEFINED)
    %IActiveScriptError_INTERFACE_DEFINED = 1

INTERFACE IActiveScriptError64 $IID_IActiveScriptError64

   INHERIT IUnknown

   ' =====================================================================================
   ' IActiveScriptError methods
   ' =====================================================================================
   METHOD GetExceptionInfo ( _                          ' VTable offset = 12
     BYREF pexcepinfo AS EXCEPINFO _                    ' __out EXCEPINFO *pexcepinfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSourcePosition ( _                         ' VTable offset = 16
     BYREF pdwSourceContext AS DWORD _                  ' __out DWORD *pdwSourceContext
   , BYREF pulLineNumber AS DWORD _                     ' __out ULONG *pulLineNumber
   , BYREF plCharacterPosition AS LONG _                ' __out LONG *plCharacterPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSourceLineText ( _                         ' VTable offset = 20
     BYREF pbstrSourceLine AS WSTRING _                 ' __out BSTR *pbstrSourceLine
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IActiveScriptError64 methods
   ' =====================================================================================
   METHOD GetSourcePosition64 ( _                       ' VTable offset = 24
     BYREF pdwSourceContext AS QUAD _                   ' __out DWORDLONG *pdwSourceContext
   , BYREF pulLineNumber AS DWORD _                     ' __out ULONG *pulLineNumber
   , BYREF plCharacterPosition AS LONG _                ' __out LONG *plCharacterPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptError64_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IActiveScriptSiteWindow
' IID = {D10F6761-83E9-11cf-8F20-00805F2CD064}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveScriptSiteWindow_INTERFACE_DEFINED)
    %IActiveScriptSiteWindow_INTERFACE_DEFINED = 1

INTERFACE IActiveScriptSiteWindow $IID_IActiveScriptSiteWindow

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetWindow ( _                                 ' VTable offset = 12
     BYREF phwnd AS DWORD _                             ' __out HWND *phwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnableModeless ( _                            ' VTable offset = 16
     BYVAL fEnable AS LONG _                            ' __in BOOL fEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptSiteWindow_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IActiveScriptSiteUIControl
' IID = {AEDAE97E-D7EE-4796-B960-7F092AE844AB}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveScriptSiteUIControl_INTERFACE_DEFINED)
    %IActiveScriptSiteUIControl_INTERFACE_DEFINED = 1

INTERFACE IActiveScriptSiteUIControl $IID_IActiveScriptSiteUIControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetUIBehavior ( _                             ' VTable offset = 12
     BYVAL UicItem AS SCRIPTUICITEM_ENUM _              ' __in SCRIPTUICITEM UicItem
   , BYREF pUicHandling AS SCRIPTUICHANDLING_ENUM _     ' __out SCRIPTUICHANDLING *pUicHandling
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptSiteUIControl_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IActiveScriptSiteInterruptPoll
' IID = {539698A0-CDCA-11CF-A5EB-00AA0047A063}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveScriptSiteInterruptPoll_INTERFACE_DEFINED)
    %IActiveScriptSiteInterruptPoll_INTERFACE_DEFINED = 1

INTERFACE IActiveScriptSiteInterruptPoll $IID_IActiveScriptSiteInterruptPoll

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryContinue ( _                             ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptSiteInterruptPoll_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IActiveScript
' IID = {BB1A2AE1-A4F9-11cf-8F20-00805F2CD064}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveScript_INTERFACE_DEFINED)
    %IActiveScript_INTERFACE_DEFINED = 1

INTERFACE IActiveScript $IID_IActiveScript

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetScriptSite ( _                             ' VTable offset = 12
     BYVAL pass AS IActiveScriptSite _                  ' __in IActiveScriptSite *pass
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScriptSite ( _                             ' VTable offset = 16
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS IUnknown _                      ' __out void **ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetScriptState ( _                            ' VTable offset = 20
     BYVAL ss AS SCRIPTSTATE_ENUM _                     ' __in SCRIPTSTATE ss
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScriptState ( _                            ' VTable offset = 24
     BYREF ss AS SCRIPTSTATE_ENUM _                     ' __out SCRIPTSTATE ss
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddNamedItem ( _                              ' VTable offset = 32
     BYREF pstrName AS WSTRINGZ _                       ' __in LPCOLESTR pstrName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddTypeLib ( _                                ' VTable offset = 36
     BYREF rguidTypeLib AS GUID _                       ' __in REFGUID rguidTypeLib
   , BYVAL dwMajor AS DWORD _                           ' __in DWORD dwMajor
   , BYVAL dwMinor AS DWORD _                           ' __in DWORD dwMinor
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScriptDispatch ( _                         ' VTable offset = 40
     BYREF pstrItemName AS WSTRINGZ _                   ' __in LPCOLESTR pstrItemName
   , BYREF ppdisp AS IDispatch _                        ' __out IDispatch **ppdisp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentScriptThreadID ( _                  ' VTable offset = 44
     BYREF pstidThread AS SCRIPTTHREADID _              ' __out SCRIPTTHREADID *pstidThread
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScriptThreadID ( _                         ' VTable offset = 48
     BYVAL dwWin32ThreadId AS DWORD _                   ' __in DWORD dwWin32ThreadId
   , BYREF pstidThread AS SCRIPTTHREADID _              ' __out SCRIPTTHREADID *pstidThread
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScriptThreadState ( _                      ' VTable offset = 52
     BYVAL stidThread AS SCRIPTTHREADID _               ' __in SCRIPTTHREADID stidThread
   , BYREF pstsState AS SCRIPTTHREADSTATE_ENUM _        ' __out SCRIPTTHREADSTATE *pstsState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InterruptScriptThread ( _                     ' VTable offset = 56
     BYVAL stidThread AS SCRIPTTHREADID _               ' __in SCRIPTTHREADID stidThread
   , BYREF pexcepinfo AS EXCEPINFO _                    ' __in const EXCEPINFO *pexcepinfo
   , BYVAL DWORD _                                      ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 60
     BYREF ppscript AS IActiveScript _                  ' __out IActiveScript **ppscript
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScript_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IActiveScriptParse
' IID = {BB1A2AE2-A4F9-11cf-8F20-00805F2CD064}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveScriptParse_INTERFACE_DEFINED)
    %IActiveScriptParse_INTERFACE_DEFINED = 1

INTERFACE IActiveScriptParse $IID_IActiveScriptParse

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InitNew ( _                                   ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddScriptlet ( _                              ' VTable offset = 16
     BYREF pstrDefaultName AS WSTRINGZ _                ' __in LPCOLESTR pstrDefaultName
   , BYREF pstrCode AS WSTRINGZ _                       ' __in LPCOLESTR pstrCode
   , BYREF pstrItemName AS WSTRINGZ _                   ' __in LPCOLESTR pstrItemName
   , BYREF pstrSubItemName AS WSTRINGZ _                ' __in LPCOLESTR pstrSubItemName
   , BYREF pstrEventName AS WSTRINGZ _                  ' __in LPCOLESTR pstrEventName
   , BYREF pstrDelimiter AS WSTRINGZ _                  ' __in LPCOLESTR pstrDelimiter
   , BYVAL dwSourceContextCookie AS DWORD _             ' __in DWORD dwSourceContextCookie
   , BYVAL ulStartingLineNumber As DWORD _              ' __in ULONG ulStartingLineNumber
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   , BYREF pexcepinfo AS EXCEPINFO _                    ' __out EXCEPINFO *pexcepinfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ParseScriptText ( _                           ' VTable offset = 20
     BYREF pstrCode AS WSTRINGZ _                       ' __in LPCOLESTR pstrCode
   , BYREF pstrItemName AS WSTRINGZ _                   ' __in LPCOLESTR pstrItemName
   , BYVAL punkContext AS IUnknown _                    ' __in IUnknown *punkContext
   , BYREF pstrDelimiter AS WSTRINGZ _                  ' __in LPCOLESTR pstrDelimiter
   , BYVAL dwSourceContextCookie AS DWORD _             ' __in DWORD dwSourceContextCookie
   , BYVAL ulStartingLineNumber AS DWORD _              ' __in ULONG ulStartingLineNumber
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pvarResult AS VARIANT _                      ' __out VARIANT *pvarResult
   , BYREF pexcepinfo AS EXCEPINFO _                    ' __out EXCEPINFO *pexcepinfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptParse_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IActiveScriptParse64
' IID = {C7EF7658-E1EE-480E-97EA-D52CB4D76D17}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveScriptParse64_INTERFACE_DEFINED)
    %IActiveScriptParse64_INTERFACE_DEFINED = 1

INTERFACE IActiveScriptParse64 $IID_IActiveScriptParse64

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InitNew ( _                                   ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddScriptlet ( _                              ' VTable offset = 16
     BYREF pstrDefaultName AS WSTRINGZ _                ' __in LPCOLESTR pstrDefaultName
   , BYREF pstrCode AS WSTRINGZ _                       ' __in LPCOLESTR pstrCode
   , BYREF pstrItemName AS WSTRINGZ _                   ' __in LPCOLESTR pstrItemName
   , BYREF pstrSubItemName AS WSTRINGZ _                ' __in LPCOLESTR pstrSubItemName
   , BYREF pstrEventName AS WSTRINGZ _                  ' __in LPCOLESTR pstrEventName
   , BYREF pstrDelimiter AS WSTRINGZ _                  ' __in LPCOLESTR pstrDelimiter
   , BYVAL dwSourceContextCookie AS QUAD _              ' __in DWORDLONG dwSourceContextCookie
   , BYVAL ulStartingLineNumber AS DWORD _              ' __in ULONG ulStartingLineNumber
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   , BYREF pexcepinfo AS EXCEPINFO _                    ' __out EXCEPINFO *pexcepinfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ParseScriptText ( _                           ' VTable offset = 20
     BYREF pstrCode AS WSTRINGZ _                       ' __in LPCOLESTR pstrCode
   , BYREF pstrItemName AS WSTRINGZ _                   ' __in LPCOLESTR pstrItemName
   , BYVAL punkContext AS IUnknown _                    ' __in IUnknown *punkContext
   , BYREF pstrDelimiter AS WSTRINGZ _                  ' __in LPCOLESTR pstrDelimiter
   , BYVAL dwSourceContextCookie AS QUAD _              ' __in DWORDLONG dwSourceContextCookie
   , BYVAL ulStartingLineNumber AS DWORD _              ' __in ULONG ulStartingLineNumber
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pvarResult AS VARIANT _                      ' __out VARIANT *pvarResult
   , BYREF pexcepinfo AS EXCEPINFO _                    ' __out EXCEPINFO *pexcepinfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptParse64_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IActiveScriptParseProcedureOld
' IID = {1CFF0050-6FDD-11d0-9328-00A0C90DCAA9}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveScriptParseProcedureOld_INTERFACE_DEFINED)
    %IActiveScriptParseProcedureOld_INTERFACE_DEFINED = 1

INTERFACE IActiveScriptParseProcedureOld $IID_IActiveScriptParseProcedureOld

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ParseProcedureText ( _                        ' VTable offset = 12
     BYREF pstrCode AS WSTRINGZ _                       ' __in LPCOLESTR pstrCode
   , BYREF pstrFormalParams AS WSTRINGZ _               ' __in LPCOLESTR pstrFormalParams
   , BYREF pstrItemName AS WSTRINGZ _                   ' __in LPCOLESTR pstrItemName
   , BYVAL punkContext AS IUnknown _                    ' __in IUnknown *punkContext
   , BYREF pstrDelimiter AS WSTRINGZ _                  ' __in LPCOLESTR pstrDelimiter
   , BYVAL dwSourceContextCookie AS DWORD _             ' __in DWORD dwSourceContextCookie
   , BYVAL ulStartingLineNumber AS DWORD _              ' __in ULONG ulStartingLineNumber
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppdisp AS IDispatch _                        ' __out IDispatch **ppdisp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptParseProcedureOld_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IActiveScriptParseProcedureOld64
' IID = {21F57128-08C9-4638-BA12-22D15D88DC5C}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveScriptParseProcedureOld64_INTERFACE_DEFINED)
    %IActiveScriptParseProcedureOld64_INTERFACE_DEFINED = 1

INTERFACE IActiveScriptParseProcedureOld64 $IID_IActiveScriptParseProcedureOld64

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ParseProcedureText ( _                        ' VTable offset = 12
     BYREF pstrCode AS WSTRINGZ _                       ' __in LPCOLESTR pstrCode
   , BYREF pstrFormalParams AS WSTRINGZ _               ' __in LPCOLESTR pstrFormalParams
   , BYREF pstrItemName AS WSTRINGZ _                   ' __in LPCOLESTR pstrItemName
   , BYVAL punkContext AS IUnknown _                    ' __in IUnknown *punkContext
   , BYREF pstrDelimiter AS WSTRINGZ _                  ' __in LPCOLESTR pstrDelimiter
   , BYVAL dwSourceContextCookie AS QUAD _              ' __in DWORDLONG dwSourceContextCookie
   , BYVAL ulStartingLineNumber AS DWORD _              ' __in ULONG ulStartingLineNumber
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppdisp AS IDispatch _                        ' __out IDispatch **ppdisp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptParseProcedureOld64_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IActiveScriptParseProcedure
' IID = {AA5B6A80-B834-11d0-932F-00A0C90DCAA9}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveScriptParseProcedure_INTERFACE_DEFINED)
    %IActiveScriptParseProcedure_INTERFACE_DEFINED = 1

INTERFACE IActiveScriptParseProcedure $IID_IActiveScriptParseProcedure

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ParseProcedureText ( _                        ' VTable offset = 12
     BYREF pstrCode AS WSTRINGZ _                       ' __in LPCOLESTR pstrCode
   , BYREF pstrFormalParams AS WSTRINGZ _               ' __in LPCOLESTR pstrFormalParams
   , BYREF pstrProcedureName AS WSTRINGZ _              ' __in LPCOLESTR pstrProcedureName
   , BYREF pstrItemName AS WSTRINGZ _                   ' __in LPCOLESTR pstrItemName
   , BYVAL punkContext AS IUnknown _                    ' __in IUnknown *punkContext
   , BYREF pstrDelimiter AS WSTRINGZ _                  ' __in LPCOLESTR pstrDelimiter
   , BYVAL dwSourceContextCookie AS DWORD _             ' __in DWORD dwSourceContextCookie
   , BYVAL ulStartingLineNumber AS DWORD _              ' __in ULONG ulStartingLineNumber
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppdisp AS IDispatch _                        ' __out IDispatch **ppdisp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptParseProcedure_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IActiveScriptParseProcedure64
' IID = {C64713B6-E029-4CC5-9200-438B72890B6A}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveScriptParseProcedure64_INTERFACE_DEFINED)
    %IActiveScriptParseProcedure64_INTERFACE_DEFINED = 1

INTERFACE IActiveScriptParseProcedure64 $IID_IActiveScriptParseProcedure64

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ParseProcedureText ( _                        ' VTable offset = 12
     BYREF pstrCode AS WSTRINGZ _                       ' __in LPCOLESTR pstrCode
   , BYREF pstrFormalParams AS WSTRINGZ _               ' __in LPCOLESTR pstrFormalParams
   , BYREF pstrProcedureName AS WSTRINGZ _              ' __in LPCOLESTR pstrProcedureName
   , BYREF pstrItemName AS WSTRINGZ _                   ' __in LPCOLESTR pstrItemName
   , BYVAL punkContext AS IUnknown _                    ' __in IUnknown *punkContext
   , BYREF pstrDelimiter AS WSTRINGZ _                  ' __in LPCOLESTR pstrDelimiter
   , BYVAL dwSourceContextCookie AS QUAD _              ' __in DWORDLONG dwSourceContextCookie
   , BYVAL ulStartingLineNumber AS DWORD _              ' __in ULONG ulStartingLineNumber
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppdisp AS IDispatch _                        ' __out IDispatch **ppdisp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptParseProcedure64_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IActiveScriptParseProcedure2
' IID = {71EE5B20-FB04-11d1-B3A8-00A0C911E8B2}
' Inherited interface = IActiveScriptParseProcedure
' ########################################################################################

#IF NOT %DEF(%IActiveScriptParseProcedure2_INTERFACE_DEFINED)
    %IActiveScriptParseProcedure2_INTERFACE_DEFINED = 1

INTERFACE IActiveScriptParseProcedure2 $IID_IActiveScriptParseProcedure2

   INHERIT IUnknown

   ' =====================================================================================
   ' IActiveScriptParseProcedure methods
   ' =====================================================================================
   METHOD ParseProcedureText ( _                        ' VTable offset = 12
     BYREF pstrCode AS WSTRINGZ _                       ' __in LPCOLESTR pstrCode
   , BYREF pstrFormalParams AS WSTRINGZ _               ' __in LPCOLESTR pstrFormalParams
   , BYREF pstrProcedureName AS WSTRINGZ _              ' __in LPCOLESTR pstrProcedureName
   , BYREF pstrItemName AS WSTRINGZ _                   ' __in LPCOLESTR pstrItemName
   , BYVAL punkContext AS IUnknown _                    ' __in IUnknown *punkContext
   , BYREF pstrDelimiter AS WSTRINGZ _                  ' __in LPCOLESTR pstrDelimiter
   , BYVAL dwSourceContextCookie AS DWORD _             ' __in DWORD dwSourceContextCookie
   , BYVAL ulStartingLineNumber AS DWORD _              ' __in ULONG ulStartingLineNumber
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppdisp AS IDispatch _                        ' __out IDispatch **ppdisp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptParseProcedure2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IActiveScriptParseProcedure2_64
' IID = {FE7C4271-210C-448D-9F54-76DAB7047B28}
' Inherited interface = IActiveScriptParseProcedure64
' ########################################################################################

#IF NOT %DEF(%IActiveScriptParseProcedure64_INTERFACE_DEFINED)
    %IActiveScriptParseProcedure2_64_INTERFACE_DEFINED = 1

INTERFACE IActiveScriptParseProcedure2_64 $IID_IActiveScriptParseProcedure2_64

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ParseProcedureText ( _                        ' VTable offset = 12
     BYREF pstrCode AS WSTRINGZ _                       ' __in LPCOLESTR pstrCode
   , BYREF pstrFormalParams AS WSTRINGZ _               ' __in LPCOLESTR pstrFormalParams
   , BYREF pstrProcedureName AS WSTRINGZ _              ' __in LPCOLESTR pstrProcedureName
   , BYREF pstrItemName AS WSTRINGZ _                   ' __in LPCOLESTR pstrItemName
   , BYVAL punkContext AS IUnknown _                    ' __in IUnknown *punkContext
   , BYREF pstrDelimiter AS WSTRINGZ _                  ' __in LPCOLESTR pstrDelimiter
   , BYVAL dwSourceContextCookie AS QUAD _              ' __in DWORDLONG dwSourceContextCookie
   , BYVAL ulStartingLineNumber AS DWORD _              ' __in ULONG ulStartingLineNumber
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppdisp AS IDispatch _                        ' __out IDispatch **ppdisp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptParseProcedure2_64_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IActiveScriptEncode
' IID = {BB1A2AE3-A4F9-11cf-8F20-00805F2CD064}
' Inherited interface = IUnknown
' Undocumented.
' ########################################################################################

#IF NOT %DEF(%IActiveScriptEncode_INTERFACE_DEFINED)
    %IActiveScriptEncode_INTERFACE_DEFINED = 1

INTERFACE IActiveScriptEncode $IID_IActiveScriptEncode

   INHERIT IUnknown

   ' =====================================================================================
   METHOD EncodeSection ( _                             ' VTable offset = 12
     BYREF pchIn AS WSTRINGZ _                          ' __in LPCOLESTR pchIn
   , BYVAL cchIn AS DWORD _                             ' __in DWORD cchIn
   , BYREF pchOut AS WSTRINGZ _                         ' __in_out LPOLESTR pchOut
   , BYVAL cchOut AS DWORD _                            ' __in DWORD cchOut
   , BYREF pcchRet AS DWORD _                           ' __in_out DWORD *pcchRet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DecodeScript ( _                              ' VTable offset = 16
     BYREF pchIn AS WSTRINGZ _                          ' __in LPCOLESTR pchIn
   , BYVAL cchIn AS DWORD _                             ' __in DWORD cchIn
   , BYREF pchOut AS WSTRINGZ _                         ' __in_out LPOLESTR pchOut
   , BYVAL cchOut AS DWORD _                            ' __in DWORD cchOut
   , BYREF pcchRet AS DWORD _                           ' __in_out DWORD *pcchRet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEncodeProgId ( _                           ' VTable offset = 20
     BYREF pbstrOut AS WSTRING _                        ' __in_out BSTR *pbstrOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptEncode_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IActiveScriptHostEncode
' IID = {BEE9B76E-CFE3-11d1-B747-00C04FC2B085}
' Inherited interface = IUnknown
' Undocumented.
' ########################################################################################

#IF NOT %DEF(%IActiveScriptHostEncode_INTERFACE_DEFINED)
    %IActiveScriptHostEncode_INTERFACE_DEFINED = 1

INTERFACE IActiveScriptHostEncode $IID_IActiveScriptHostEncode

   INHERIT IUnknown

   ' =====================================================================================
   METHOD EncodeScriptHostFile ( _                      ' VTable offset = 12
     BYVAL bstrInFile AS WSTRING _                      ' __in BSTR bstrInFile
   , BYREF pbstrOutFile AS WSTRING _                    ' __in_out BSTR *pbstrOutFile
   , BYVAL cFlags AS DWORD _                            ' __in unsigned long cFlags
   , BYVAL bstrDefaultLang AS WSTRING _                 ' __in BSTR bstrDefaultLang
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptHostEncode_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IBindEventHandler
' IID = {63CDBCB0-C1B1-11d0-9336-00A0C90DCAA9}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBindEventHandler_INTERFACE_DEFINED)
    %IBindEventHandler_INTERFACE_DEFINED = 1

INTERFACE IBindEventHandler $IID_IBindEventHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD BindHandler ( _                               ' VTable offset = 12
     BYREF pstrEvent AS WSTRINGZ _                      ' __in LPCOLESTR pstrEvent
   , BYVAL pdisp AS IDispatch _                         ' __in IDispatch *pdisp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBindEventHandler_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IActiveScriptStats
' IID = {B8DA6310-E19B-11d0-933C-00A0C90DCAA9}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveScriptStats_INTERFACE_DEFINED)
    %IActiveScriptStats_INTERFACE_DEFINED = 1

INTERFACE IActiveScriptStats $IID_IActiveScriptStats

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetStat ( _                                   ' VTable offset = 12
     BYVAL stid AS DWORD _                              ' __in DWORD stid
   , BYREF pluHi AS DWORD _                             ' __out ULONG *pluHi
   , BYREF pluLo AS DWORD _                             ' __out ULONG *pluLo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatEx ( _                                 ' VTable offset = 16
     BYREF guid AS GUID _                               ' __in REFGUID guid
   , BYREF pluHi AS DWORD _                             ' __out ULONG *pluHi
   , BYREF pluLo AS DWORD _                             ' __out ULONG *pluLo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResetStats ( _                                ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptStats_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IActiveScriptProperty
' IID = {4954E0D0-FBC7-11D1-8410-006008C3FBFC}
' Inherited interface = IUnknown
' Undocumented.
' ########################################################################################

#IF NOT %DEF(%IActiveScriptProperty_INTERFACE_DEFINED)
    %IActiveScriptProperty_INTERFACE_DEFINED = 1

INTERFACE IActiveScriptProperty $IID_IActiveScriptProperty

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 12
     BYVAL dwProperty AS DWORD _                        ' __in DWORD dwProperty
   , BYREF pvarIndex AS VARIANT _                       ' __in VARIANT *pvarIndex
   , BYREF pvarValue AS VARIANT _                       ' __out VARIANT *pvarValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProperty ( _                               ' VTable offset = 16
     BYVAL dwProperty AS DWORD _                        ' __in DWORD dwProperty
   , BYREF pvarIndex AS VARIANT _                       ' __in VARIANT *pvarIndex
   , BYREF pvarValue AS VARIANT _                       ' __in VARIANT *pvarValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptProperty_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITridentEventSink
' IID = {1DC9CA50-06EF-11d2-8415-006008C3FBFC}
' Inherited interface = IUnknown
' Undocumented.
' ########################################################################################

#IF NOT %DEF(%ITridentEventSink_INTERFACE_DEFINED)
    %ITridentEventSink_INTERFACE_DEFINED = 1

INTERFACE ITridentEventSink $IID_ITridentEventSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD FireEvent ( _                                 ' VTable offset = 12
     BYREF pstrEvent AS WSTRINGZ _                      ' __in LPCOLESTR pstrEvent
   , BYREF pdp AS DISPPARAMS _                          ' __in DISPPARAMS *pdp
   , BYREF pvarRes AS VARIANT _                         ' __out VARIANT *pvarRes
   , BYREF pei AS EXCEPINFO _                           ' __out EXCEPINFO *pei
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITridentEventSink_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IActiveScriptGarbageCollector
' IID = {6AA2C4A0-2B53-11d4-A2A0-00104BD35090}
' Inherited interface = IUnknown
' Undocumented.
' ########################################################################################

#IF NOT %DEF(%IActiveScriptGarbageCollector_INTERFACE_DEFINED)
    %IActiveScriptGarbageCollector_INTERFACE_DEFINED = 1

INTERFACE IActiveScriptGarbageCollector $IID_IActiveScriptGarbageCollector

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CollectGarbage ( _                            ' VTable offset = 12
     BYVAL scriptgctype AS SCRIPTGCTYPE_ENUM _          ' __in SCRIPTGCTYPE scriptgctype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptGarbageCollector_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IActiveScriptSIPInfo
' IID = {764651D0-38DE-11d4-A2A3-00104BD35090}
' Inherited interface = IUnknown
' Undocumented.
' ########################################################################################

#IF NOT %DEF(%IActiveScriptSIPInfo_INTERFACE_DEFINED)
    %IActiveScriptSIPInfo_INTERFACE_DEFINED = 1

INTERFACE IActiveScriptSIPInfo $IID_IActiveScriptSIPInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CollectGarbage ( _                            ' VTable offset = 12
     BYREF poid_sip AS GUID _                           ' __out GUID *poid_sip
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptSIPInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IActiveScriptSiteTraceInfo
' IID = {4B7272AE-1955-4bfe-98B0-780621888569}
' Inherited interface = IUnknown
' Undocumented.
' ########################################################################################

#IF NOT %DEF(%IActiveScriptSiteTraceInfo_INTERFACE_DEFINED)
    %IActiveScriptSiteTraceInfo_INTERFACE_DEFINED = 1

INTERFACE IActiveScriptSiteTraceInfo $IID_IActiveScriptSiteTraceInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SendScriptTraceInfo ( _                       ' VTable offset = 12
     BYVAL stiEventType AS SCRIPTTRACEINFO_ENUM _       ' __in SCRIPTTRACEINFO stiEventType
   , BYREF guidContextID AS GUID _                      ' __in GUID guidContextID
   , BYVAL dwScriptContextCookie AS DWORD _             ' __in DWORD dwScriptContextCookie
   , BYVAL lScriptStatementStart AS LONG _              ' __in LONG lScriptStatementStart
   , BYVAL lScriptStatementEnd AS LONG _                ' __in LONG lScriptStatementEnd
   , BYVAL dwReserved AS QUAD _                         ' __in DWORD64 dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptSiteTraceInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IActiveScriptTraceInfo
' IID = {C35456E7-BEBF-4a1b-86A9-24D56BE8B369}
' Inherited interface = IUnknown
' Undocumented.
' ########################################################################################

#IF NOT %DEF(%IActiveScriptTraceInfo_INTERFACE_DEFINED)
    %IActiveScriptTraceInfo_INTERFACE_DEFINED = 1

INTERFACE IActiveScriptTraceInfo $IID_IActiveScriptTraceInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD StartScriptTracing ( _                        ' VTable offset = 12
     BYVAL pSiteTraceInfo AS IActiveScriptSiteTraceInfo _ ' __in IActiveScriptSiteTraceInfo *pSiteTraceInfo
   , BYREF guidContextID AS GUID _                      ' __in GUID guidContextID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StopScriptTracing ( _                         ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptTraceInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IActiveScriptStringCompare
' IID = {58562769-ED52-42f7-8403-4963514E1F11}
' Inherited interface = IUnknown
' Undocumented.
' ########################################################################################

#IF NOT %DEF(%IActiveScriptStringCompare_INTERFACE_DEFINED)
    %IActiveScriptStringCompare_INTERFACE_DEFINED = 1

INTERFACE IActiveScriptStringCompare $IID_IActiveScriptStringCompare

   INHERIT IUnknown

   ' =====================================================================================
   METHOD StrComp ( _                                   ' VTable offset = 12
     BYVAL bszStr1 AS WSTRING _                         ' __in BSTR bszStr1
   , BYVAL bszStr2 AS WSTRING _                         ' __in BSTR bszStr2
   , BYREF iRet AS LONG _                               ' __retval_out LONG *iRet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptStringCompare_INTERFACE_DEFINED__ */
