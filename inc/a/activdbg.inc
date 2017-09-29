' ########################################################################################
' Microsoft Windows
' File: ActivDbg.inc
' Contents: ActiveX Debugging Interfaces
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ACTIVDBG_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "activscp.inc"
#INCLUDE ONCE "dbgprop.inc"

$LIBID_ProcessDebugManagerLib = GUID$("{78A51821-51F4-11D0-8F20-00805F2CD064}")
$CLSID_ProcessDebugManager = GUID$("{78a51822-51f4-11d0-8f20-00805f2cd064}")
$CLSID_DebugHelper = GUID$("{0BFCC060-8C1D-11d0-ACCD-00AA0060275C}")
$CLSID_CDebugDocumentHelper = GUID$("{83B8BCA6-687C-11D0-A405-00AA0060275C}")
$CLSID_MachineDebugManager_RETAIL = GUID$("{0C0A3666-30C9-11D0-8F20-00805F2CD064}")
$CLSID_MachineDebugManager_DEBUG = GUID$("{49769CEC-3A55-4bb0-B697-88FEDE77E8EA}")
$CLSID_DefaultDebugSessionProvider = GUID$("{834128a2-51f4-11d0-8f20-00805f2cd064}")

'#ifdef DEBUG
'#define MachineDebugManger MachineDebugManager_DEBUG
'#define CLSID_MachineDebugManager CLSID_MachineDebugManager_DEBUG
'#else
'#define MachineDebugManger MachineDebugManager_RETAIL
'#define CLSID_MachineDebugManager CLSID_MachineDebugManager_RETAIL
'#endif

#IF NOT %DEF(%DEBUG)
$CLSID_MachineDebugManager = $CLSID_MachineDebugManager_RETAIL
#ELSE
$CLSID_MachineDebugManager = $CLSID_MachineDebugManager_DEBUG
#ENDIF

'//
'// Declarations for ActiveX Scripting authoring/Debugging.
'//

' enum BREAKPOINT_STATE
MACRO BREAKPOINT_STATE_ENUM = LONG
%BREAKPOINT_DELETED  = 0
%BREAKPOINT_DISABLED = 1
%BREAKPOINT_ENABLED  = 2

'typedef DWORD APPBREAKFLAGS;
MACRO APPBREAKFLAGS = DWORD
%APPBREAKFLAG_DEBUGGER_BLOCK    = &H1???
%APPBREAKFLAG_DEBUGGER_HALT     = &H2???
%APPBREAKFLAG_STEP              = &H10000???
%APPBREAKFLAG_NESTED            = &H20000???
%APPBREAKFLAG_STEPTYPE_SOURCE   = &H0???
%APPBREAKFLAG_STEPTYPE_BYTECODE = &H100000???
%APPBREAKFLAG_STEPTYPE_MACHINE  = &H200000???
%APPBREAKFLAG_STEPTYPE_MASK     = &Hf00000???
%APPBREAKFLAG_IN_BREAKPOINT     = &H80000000???

' enum BREAKREASON
MACRO BREAKREASON_ENUM = LONG
%BREAKREASON_STEP               = 0
%BREAKREASON_BREAKPOINT         = %BREAKREASON_STEP               + 1
%BREAKREASON_DEBUGGER_BLOCK     = %BREAKREASON_BREAKPOINT         + 1
%BREAKREASON_HOST_INITIATED     = %BREAKREASON_DEBUGGER_BLOCK     + 1
%BREAKREASON_LANGUAGE_INITIATED = %BREAKREASON_HOST_INITIATED     + 1
%BREAKREASON_DEBUGGER_HALT      = %BREAKREASON_LANGUAGE_INITIATED + 1
%BREAKREASON_ERROR              = %BREAKREASON_DEBUGGER_HALT      + 1
%BREAKREASON_JIT                = %BREAKREASON_ERROR              + 1

' enum BREAKRESUMEACTION
MACRO BREAKRESUMEACTION_ENUM = LONG
%BREAKRESUMEACTION_ABORT        = 0
%BREAKRESUMEACTION_CONTINUE     = %BREAKRESUMEACTION_ABORT     + 1
%BREAKRESUMEACTION_STEP_INTO    = %BREAKRESUMEACTION_CONTINUE  + 1
%BREAKRESUMEACTION_STEP_OVER    = %BREAKRESUMEACTION_STEP_INTO + 1
%BREAKRESUMEACTION_STEP_OUT     = %BREAKRESUMEACTION_STEP_OVER + 1
%BREAKRESUMEACTION_IGNORE       = %BREAKRESUMEACTION_STEP_OUT  + 1

' enum ERRORRESUMEACTION
MACRO ERRORRESUMEACTION_ENUM = LONG
%ERRORRESUMEACTION_ReexecuteErrorStatement         = 0
%ERRORRESUMEACTION_AbortCallAndReturnErrorToCaller = %ERRORRESUMEACTION_ReexecuteErrorStatement         + 1
%ERRORRESUMEACTION_SkipErrorStatement              = %ERRORRESUMEACTION_AbortCallAndReturnErrorToCaller + 1

' enum DOCUMENTNAMETYPE
MACRO DOCUMENTNAMETYPE_ENUM = LONG
%DOCUMENTNAMETYPE_APPNODE   = 0
%DOCUMENTNAMETYPE_TITLE     = %DOCUMENTNAMETYPE_APPNODE   + 1
%DOCUMENTNAMETYPE_FILE_TAIL = %DOCUMENTNAMETYPE_TITLE     + 1
%DOCUMENTNAMETYPE_URL       = %DOCUMENTNAMETYPE_FILE_TAIL + 1

'typedef WORD SOURCE_TEXT_ATTR;
' // This macro is also defined in activaut.inc
#IF NOT %DEF(%SOURCE_TEXT_ATTR_DEFINED)
%SOURCE_TEXT_ATTR_DEFINED = 1
MACRO SOURCE_TEXT_ATTR = WORD
#ENDIF

%SOURCETEXT_ATTR_KEYWORD          = &H1??
%SOURCETEXT_ATTR_COMMENT          = &H2??
%SOURCETEXT_ATTR_NONSOURCE        = &H4??
%SOURCETEXT_ATTR_OPERATOR         = &H8??
%SOURCETEXT_ATTR_NUMBER           = &H10??
%SOURCETEXT_ATTR_STRING           = &H20??
%SOURCETEXT_ATTR_FUNCTION_START   = &H40??

'typedef DWORD TEXT_DOC_ATTR;
MACRO TEXT_DOC_ATTR = DWORD

%TEXT_DOC_ATTR_READONLY           = &H1??
%DEBUG_TEXT_ISEXPRESSION          = &H1??
%DEBUG_TEXT_RETURNVALUE           = &H2??
%DEBUG_TEXT_NOSIDEEFFECTS         = &H4??
%DEBUG_TEXT_ALLOWBREAKPOINTS      = &H8??
%DEBUG_TEXT_ALLOWERRORREPORT      = &H10??
%DEBUG_TEXT_EVALUATETOCODECONTEXT = &H20??


' ########################################################################################
' Interface name = IActiveScriptDebug32
' IID = 51973C10-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' Implemented by script engines that support debugging. Typically, an object that
' implements the IActiveScriptDebug interface also implements the IActiveScript interface.
' If this is the case, call the IActiveScript::QueryInterface method to obtain the
' IActiveScriptDebug interface.
' ########################################################################################

#IF NOT %DEF(%IActiveScriptDebug32_INTERFACE_DEFINED)
    %IActiveScriptDebug32_INTERFACE_DEFINED = 1

$IID_IActiveScriptDebug32 = GUID$("{51973C10-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IActiveScriptDebug32 $IID_IActiveScriptDebug32

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetScriptTextAttributes ( _                   ' VTable offset = 12
     BYREF pstrCode AS WSTRINGZ _                       ' __in LPCOLESTR pstrCode
   , BYVAL uNumCodeChars AS DWORD _                     ' __in ULONG uNumCodeChars
   , BYREF pstrDelimiter AS WSTRINGZ _                  ' __in LPCOLESTR pstrDelimiter
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pattr AS SOURCE_TEXT_ATTR _                  ' __inout SOURCE_TEXT_ATTR *pattr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScriptletTextAttributes ( _                ' VTable offset = 16
     BYREF pstrCode AS WSTRINGZ _                       ' __in LPCOLESTR pstrCode
   , BYVAL uNumCodeChars AS DWORD _                     ' __in ULONG uNumCodeChars
   , BYREF pstrDelimiter AS WSTRINGZ _                  ' __in LPCOLESTR pstrDelimiter
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pattr AS SOURCE_TEXT_ATTR _                  ' __inout SOURCE_TEXT_ATTR *pattr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumCodeContextsOfPosition ( _                ' VTable offset = 20
     BYVAL dwSourceContext AS DWORD _                   ' __in DWORD dwSourceContext
   , BYVAL uCharacterOffset AS DWORD _                  ' __in ULONG uCharacterOffset
   , BYVAL uNumChars AS DWORD _                         ' __in ULONG uNumChars
   , BYREF ppescc AS IEnumDebugCodeContexts _           ' __out IEnumDebugCodeContexts **ppescc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptDebug32_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IActiveScriptDebug64
' IID = bc437e23-f5b8-47f4-bb79-7d1ce5483b86
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveScriptDebug64_INTERFACE_DEFINED)
    %IActiveScriptDebug64_INTERFACE_DEFINED = 1

$IID_IActiveScriptDebug64 = GUID$("{bc437e23-f5b8-47f4-bb79-7d1ce5483b86}")

INTERFACE IActiveScriptDebug64 $IID_IActiveScriptDebug64

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetScriptTextAttributes ( _                   ' VTable offset = 12
     BYREF pstrCode AS WSTRINGZ _                       ' __in LPCOLESTR pstrCode
   , BYVAL uNumCodeChars AS DWORD _                     ' __in ULONG uNumCodeChars
   , BYREF pstrDelimiter AS WSTRINGZ _                  ' __in LPCOLESTR pstrDelimiter
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pattr AS SOURCE_TEXT_ATTR _                  ' __inout SOURCE_TEXT_ATTR *pattr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScriptletTextAttributes ( _                ' VTable offset = 16
     BYREF pstrCode AS WSTRINGZ _                       ' __in LPCOLESTR pstrCode
   , BYVAL uNumCodeChars AS DWORD _                     ' __in ULONG uNumCodeChars
   , BYREF pstrDelimiter AS WSTRINGZ _                  ' __in LPCOLESTR pstrDelimiter
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pattr AS SOURCE_TEXT_ATTR _                  ' __inout SOURCE_TEXT_ATTR *pattr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumCodeContextsOfPosition ( _                ' VTable offset = 20
     BYVAL dwSourceContext AS QUAD _                    ' __in DWORDLONG dwSourceContext
   , BYVAL uCharacterOffset AS DWORD _                  ' __in ULONG uCharacterOffset
   , BYVAL uNumChars AS DWORD _                         ' __in ULONG uNumChars
   , BYREF ppescc AS IEnumDebugCodeContexts _           ' __out IEnumDebugCodeContexts **ppescc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptDebug64_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IActiveScriptSiteDebug32
' IID = 51973C11-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveScriptSiteDebug32_INTERFACE_DEFINED)
    %IActiveScriptSiteDebug32_INTERFACE_DEFINED = 1

$IID_IActiveScriptSiteDebug32 = GUID$("{51973C11-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IActiveScriptSiteDebug32 $IID_IActiveScriptSiteDebug32

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDocumentContextFromPosition ( _            ' VTable offset = 12
     BYVAL dwSourceContext AS DWORD _                   ' __in DWORD dwSourceContext
   , BYVAL uCharacterOffset AS DWORD _                  ' __in ULONG uCharacterOffset
   , BYVAL uNumChars AS DWORD _                         ' __in ULONG uNumChars
   , BYREF ppsc AS IDebugDocumentContext _              ' __out IDebugDocumentContext **ppsc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetApplication ( _                            ' VTable offset = 16
     BYREF ppda AS IDebugApplication32 _                ' __out IDebugApplication32 **ppda
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRootApplicationNode ( _                    ' VTable offset = 20
     BYREF ppdanRoot AS IDebugApplicationNode _         ' __out IDebugApplicationNode **ppdanRoot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnScriptErrorDebug ( _                        ' VTable offset = 24
     BYVAL pErrorDebug AS IActiveScriptErrorDebug _     ' __in IActiveScriptErrorDebug *pErrorDebug
   , BYREF pfEnterDebugger AS LONG _                    ' __out BOOL *pfEnterDebugger
   , BYREF pfCallOnScriptErrorWhenContinuing AS LONG _  ' __out BOOL *pfCallOnScriptErrorWhenContinuing
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptSiteDebug32_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IActiveScriptSiteDebug64
' IID = d6b96b0a-7463-402c-92ac-89984226942f
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveScriptSiteDebug64_INTERFACE_DEFINED)
    %IActiveScriptSiteDebug64_INTERFACE_DEFINED = 1

$IID_IActiveScriptSiteDebug64 = GUID$("{d6b96b0a-7463-402c-92ac-89984226942f}")

INTERFACE IActiveScriptSiteDebug64 $IID_IActiveScriptSiteDebug64

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDocumentContextFromPosition ( _            ' VTable offset = 12
     BYVAL dwSourceContext AS QUAD _                    ' __in DWORDLONG dwSourceContext
   , BYVAL uCharacterOffset AS DWORD _                  ' __in ULONG uCharacterOffset
   , BYVAL uNumChars AS DWORD _                         ' __in ULONG uNumChars
   , BYREF ppsc AS IDebugDocumentContext _              ' __out IDebugDocumentContext **ppsc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetApplication ( _                            ' VTable offset = 16
     BYREF ppda AS IDebugApplication64 _                ' __out IDebugApplication64 **ppda
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRootApplicationNode ( _                    ' VTable offset = 20
     BYREF ppdanRoot AS IDebugApplicationNode _         ' __out IDebugApplicationNode **ppdanRoot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnScriptErrorDebug ( _                        ' VTable offset = 24
     BYVAL pErrorDebug AS IActiveScriptErrorDebug _     ' __in IActiveScriptErrorDebug *pErrorDebug
   , BYREF pfEnterDebugger AS LONG _                    ' __out BOOL *pfEnterDebugger
   , BYREF pfCallOnScriptErrorWhenContinuing AS LONG _  ' __out BOOL *pfCallOnScriptErrorWhenContinuing
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptSiteDebug64_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IActiveScriptSiteDebugEx
' IID = BB722CCB-6AD2-41c6-B780-AF9C03EE69F5
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveScriptSiteDebugEx_INTERFACE_DEFINED)
    %IActiveScriptSiteDebugEx_INTERFACE_DEFINED = 1

$IID_IActiveScriptSiteDebugEx = GUID$("{BB722CCB-6AD2-41c6-B780-AF9C03EE69F5}")

INTERFACE IActiveScriptSiteDebugEx $IID_IActiveScriptSiteDebugEx

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnCanNotJITScriptErrorDebug ( _               ' VTable offset = 12
     BYVAL pErrorDebug AS IActiveScriptErrorDebug _     ' __in IActiveScriptErrorDebug *pErrorDebug
   , BYREF pfCallOnScriptErrorWhenContinuing AS LONG _  ' __out BOOL *pfCallOnScriptErrorWhenContinuing
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptSiteDebugEx_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IActiveScriptErrorDebug
' IID = 51973C12-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IActiveScriptError
' ########################################################################################

#IF NOT %DEF(%IActiveScriptErrorDebug_INTERFACE_DEFINED)
    %IActiveScriptErrorDebug_INTERFACE_DEFINED = 1

$IID_IActiveScriptErrorDebug = GUID$("{51973C12-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IActiveScriptErrorDebug $IID_IActiveScriptErrorDebug

   INHERIT IUnknown

   ' ========================================================================================
   ' IActiveScriptError methods
   ' ========================================================================================
   METHOD GetExceptionInfo ( _                          ' VTable offset = 12
     BYREF pexcepinfo AS EXCEPINFO _                    ' __out EXCEPINFO *pexcepinfo
   ) AS LONG                                            ' HRESULT
   ' ========================================================================================
   METHOD GetSourcePosition ( _                         ' VTable offset = 16
     BYREF pdwSourceContext AS DWORD _                  ' __out DWORD *pdwSourceContext
   , BYREF pulLineNumber AS DWORD _                     ' __out ULONG *pulLineNumber
   , BYREF plCharacterPosition AS LONG _                ' __out LONG *plCharacterPosition
   ) AS LONG                                            ' HRESULT
   ' ========================================================================================
   METHOD GetSourceLineText ( _                         ' VTable offset = 20
     BYREF pbstrSourceLine AS WSTRING _                 ' __out BSTR *pbstrSourceLine
   ) AS LONG                                            ' HRESULT
   ' ========================================================================================

   ' ========================================================================================
   ' IActiveScriptErrorDebug methods
   ' ========================================================================================
   METHOD GetDocumentContext ( _                        ' VTable offset = 24
     BYREF ppssc AS IDebugDocumentContext _             ' __out IDebugDocumentContext **ppssc
   ) AS LONG                                            ' HRESULT
   ' ========================================================================================
   METHOD GetStackFrame ( _                             ' VTable offset = 28
     BYREF ppdsf AS IDebugStackFrame _                  ' __out IDebugStackFrame **ppdsf
   ) AS LONG                                            ' HRESULT
   ' ========================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptErrorDebug_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugCodeContext
' IID = 51973C13-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebugCodeContext_INTERFACE_DEFINED)
    %IDebugCodeContext_INTERFACE_DEFINED = 1

$IID_IDebugCodeContext = GUID$("{51973C13-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugCodeContext $IID_IDebugCodeContext

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDocumentContext ( _                        ' VTable offset = 12
     BYREF ppsc AS IDebugDocumentContext _              ' __out IDebugDocumentContext **ppsc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBreakPoint ( _                             ' VTable offset = 16
     BYVAL bps AS BREAKPOINT_STATE_ENUM _               ' __in BREAKPOINT_STATE bps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugCodeContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugExpression
' IID = 51973C14-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebugExpression_INTERFACE_DEFINED)
    %IDebugExpression_INTERFACE_DEFINED = 1

$IID_IDebugExpression = GUID$("{51973C14-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugExpression $IID_IDebugExpression

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 12
     BYVAL pdecb AS IDebugExpressionCallBack _          ' __in IDebugExpressionCallBack *pdecb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryIsComplete ( _                           ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResultAsString ( _                         ' VTable offset = 24
     BYREF phrResult AS LONG _                          ' __out HRESULT *phrResult
   , BYREF pbstrResult AS WSTRING _                     ' __out BSTR *pbstrResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResultAsDebugProperty ( _                  ' VTable offset = 28
     BYREF phrResult AS LONG _                          ' __out HRESULT *phrResult
   , BYREF ppdp AS IDebugProperty _                     ' __out IDebugProperty **ppdp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugExpressionContext
' IID = 51973C15-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebugExpressionContext_INTERFACE_DEFINED)
    %IDebugExpressionContext_INTERFACE_DEFINED = 1

$IID_IDebugExpressionContext = GUID$("{51973C15-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugExpressionContext $IID_IDebugExpressionContext

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ParseLanguageText ( _                         ' VTable offset = 12
     BYREF pstrCode AS WSTRINGZ _                       ' __in LPCOLESTR pstrCode
   , BYVAL nRadix AS DWORD _                            ' __in UINT nRadix
   , BYREF pstrDelimiter AS WSTRINGZ _                  ' __in LPCOLESTR pstrDelimiter
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppe AS IDebugExpression _                    ' __out IDebugExpression **ppe
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLanguageInfo ( _                           ' VTable offset = 16
     BYREF pbstrLanguageName AS WSTRING _               ' __out BSTR *pbstrLanguageName
   , BYREF pLanguageID AS GUID _                        ' __out GUID *pLanguageID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugExpressionContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugExpressionCallBack
' IID = 51973C16-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebugExpressionCallBack_INTERFACE_DEFINED)
    %IDebugExpressionCallBack_INTERFACE_DEFINED = 1

$IID_IDebugExpressionCallBack = GUID$("{51973C16-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugExpressionCallBack $IID_IDebugExpressionCallBack

   INHERIT IUnknown

   ' =====================================================================================
   METHOD onComplete ( _                                ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugExpressionCallBack_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugStackFrame
' IID = 51973C17-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebugStackFrame_INTERFACE_DEFINED)
    %IDebugStackFrame_INTERFACE_DEFINED = 1

$IID_IDebugStackFrame = GUID$("{51973C17-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugStackFrame $IID_IDebugStackFrame

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCodeContext ( _                            ' VTable offset = 12
     BYREF ppcc AS IDebugCodeContext _                  ' __out IDebugCodeContext **ppcc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescriptionString ( _                      ' VTable offset = 16
     BYVAL fLong AS LONG _                              ' __in BOOL fLong
   , BYREF pbstrDescription AS WSTRING _                ' __out BSTR *pbstrDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLanguageString ( _                         ' VTable offset = 20
     BYVAL fLong AS LONG _                              ' __in BOOL fLong
   , BYREF pbstrLanguage AS WSTRING _                   ' __out BSTR *pbstrLanguage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetThread ( _                                 ' VTable offset = 24
     BYREF ppat AS IDebugApplicationThread _            ' __out IDebugApplicationThread **ppat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDebugProperty ( _                          ' VTable offset = 28
     BYREF ppDebugProp AS IDebugProperty _              ' __out IDebugProperty **ppDebugProp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugStackFrame_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugStackFrameSniffer
' IID = 51973C18-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebugStackFrameSniffer_INTERFACE_DEFINED)
    %IDebugStackFrameSniffer_INTERFACE_DEFINED = 1

$IID_IDebugStackFrameSniffer = GUID$("{51973C18-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugStackFrameSniffer $IID_IDebugStackFrameSniffer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD EnumStackFrames ( _                           ' VTable offset = 12
     BYREF ppedsf AS IEnumDebugStackFrames _            ' __out IEnumDebugStackFrames **ppedsf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugStackFrameSniffer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugStackFrameSnifferEx32
' IID = 51973C18-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IDebugStackFrameSniffer
' ########################################################################################

#IF NOT %DEF(%IDebugStackFrameSnifferEx32_INTERFACE_DEFINED)
    %IDebugStackFrameSnifferEx32_INTERFACE_DEFINED = 1

$IID_IDebugStackFrameSnifferEx32 = GUID$("{51973C18-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugStackFrameSnifferEx32 $IID_IDebugStackFrameSnifferEx32

   INHERIT IUnknown

   ' =====================================================================================
   ' IDebugStackFrameSniffer method
   ' =====================================================================================
   METHOD EnumStackFrames ( _                           ' VTable offset = 12
     BYREF ppedsf AS IEnumDebugStackFrames _            ' __out IEnumDebugStackFrames **ppedsf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDebugStackFrameSnifferEx32 method
   ' =====================================================================================
   METHOD EnumStackFramesEx32 ( _                       ' VTable offset = 16
     BYVAL dwSpMin AS DWORD _                           ' __in DWORD dwSpMin
   , BYREF ppedsf AS IEnumDebugStackFrames _            ' __out IEnumDebugStackFrames **ppedsf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugStackFrameSnifferEx32_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugStackFrameSnifferEx64
' IID = 8cd12af4-49c1-4d52-8d8a-c146f47581aa
' Inherited interface = IDebugStackFrameSniffer
' ########################################################################################

#IF NOT %DEF(%IDebugStackFrameSnifferEx64_INTERFACE_DEFINED)
    %IDebugStackFrameSnifferEx64_INTERFACE_DEFINED = 1

$IID_IDebugStackFrameSnifferEx64 = GUID$("{8cd12af4-49c1-4d52-8d8a-c146f47581aa}")

INTERFACE IDebugStackFrameSnifferEx64 $IID_IDebugStackFrameSnifferEx64

   INHERIT IUnknown

   ' =====================================================================================
   ' IDebugStackFrameSniffer method
   ' =====================================================================================
   METHOD EnumStackFrames ( _                           ' VTable offset = 12
     BYREF ppedsf AS IEnumDebugStackFrames _            ' __out IEnumDebugStackFrames **ppedsf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDebugStackFrameSnifferEx64 method
   ' =====================================================================================
   METHOD EnumStackFramesEx64 ( _                       ' VTable offset = 16
     BYVAL dwSpMin AS QUAD _                            ' __in DWORDLONG dwSpMin
   , BYREF ppedsf AS IEnumDebugStackFrames64 _          ' __out IEnumDebugStackFrames64 **ppedsf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugStackFrameSnifferEx64_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugSyncOperation
' IID = 51973C1a-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebugSyncOperation_INTERFACE_DEFINED)
    %IDebugSyncOperation_INTERFACE_DEFINED = 1

$IID_IDebugSyncOperation = GUID$("{51973C1a-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugSyncOperation $IID_IDebugSyncOperation

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTargetThread ( _                           ' VTable offset = 12
     BYREF ppatTarget AS IDebugApplicationThread _      ' __out IDebugApplicationThread **ppatTarget
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Execute ( _                                   ' VTable offset = 16
     BYREF ppunkResult AS IUnknown _                    ' __out IUnknown **ppunkResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InProgressAbort ( _                           ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugSyncOperation_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugAsyncOperation
' IID = 51973C1b-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebugAsyncOperation_INTERFACE_DEFINED)
    %IDebugAsyncOperation_INTERFACE_DEFINED = 1

$IID_IDebugAsyncOperation = GUID$("{51973C1b-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugAsyncOperation $IID_IDebugAsyncOperation

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSyncDebugOperation ( _                     ' VTable offset = 12
     BYREF ppsdo AS IDebugSyncOperation _               ' __out IDebugSyncOperation **ppsdo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 16
     BYVAL padocb AS IDebugAsyncOperationCallBack _     ' __in IDebugAsyncOperationCallBack *padocb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryIsComplete ( _                           ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResult ( _                                 ' VTable offset = 28
     BYREF phrResult AS LONG _                          ' __out HRESULT *phrResult
   , BYREF ppunkResult AS IUnknown _                    ' __out IUnknown **ppunkResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugAsyncOperation_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugAsyncOperationCallBack
' IID = 51973C1c-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebugAsyncOperationCallBack_INTERFACE_DEFINED)
    %IDebugAsyncOperationCallBack_INTERFACE_DEFINED = 1

$IID_IDebugAsyncOperationCallBack = GUID$("{51973C1c-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugAsyncOperationCallBack $IID_IDebugAsyncOperationCallBack

   INHERIT IUnknown

   ' =====================================================================================
   METHOD onComplete ( _                                ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugAsyncOperationCallBack_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumDebugCodeContexts
' IID = 51973C1d-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumDebugCodeContexts_INTERFACE_DEFINED)
    %IEnumDebugCodeContexts_INTERFACE_DEFINED = 1

$IID_IEnumDebugCodeContexts = GUID$("{51973C1d-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IEnumDebugCodeContexts $IID_IEnumDebugCodeContexts

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF pscc AS IDebugCodeContext _                  ' __out IDebugCodeContext **pscc
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppescc AS IEnumDebugCodeContexts _           ' __out IEnumDebugCodeContexts **ppescc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumDebugCodeContexts_INTERFACE_DEFINED__ */

' // Size = 20 bytes
TYPE DebugStackFrameDescriptor DWORD
   pdsf      AS DWORD PTR   ' IDebugStackFrame *
   dwMin     AS DWORD       ' DWORD
   dwLim     AS DWORD       ' DWORD
   fFinal    AS LONG        ' BOOL
   punkFinal AS DWORD PTR   ' IUnknown *
END TYPE

' // Size = 32 bytes
TYPE DebugStackFrameDescriptor64 QWORD FILL
   pdsf      AS DWORD PTR   ' IDebugStackFrame *
   dwMin     AS QUAD        ' DWORDLONG
   dwLim     AS QUAD        ' DWORDLONG
   fFinal    AS LONG        ' BOOL
   punkFinal AS DWORD PTR   ' IUnknown *
END TYPE

' ########################################################################################
' Interface name = IEnumDebugStackFrames
' IID = 51973C1e-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumDebugStackFrames_INTERFACE_DEFINED)
    %IEnumDebugStackFrames_INTERFACE_DEFINED = 1

$IID_IEnumDebugStackFrames = GUID$("{51973C1e-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IEnumDebugStackFrames $IID_IEnumDebugStackFrames

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF prgdsfd AS DebugStackFrameDescriptor _       ' __out DebugStackFrameDescriptor *prgdsfd
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppedsf AS IEnumDebugStackFrames _            ' __out IEnumDebugStackFrames **ppedsf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumDebugStackFrames_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumDebugStackFrames64
' IID = 0dc38853-c1b0-4176-a984-b298361027af
' Inherited interface = IEnumDebugStackFrames
' ########################################################################################

#IF NOT %DEF(%IEnumDebugStackFrames64_INTERFACE_DEFINED)
    %IEnumDebugStackFrames64_INTERFACE_DEFINED = 1

$IID_IEnumDebugStackFrames64 = GUID$("{0dc38853-c1b0-4176-a984-b298361027af}")

INTERFACE IEnumDebugStackFrames64 $IID_IEnumDebugStackFrames64

   INHERIT IUnknown

   ' =====================================================================================
   ' IEnumDebugStackFrames methods
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF prgdsfd AS DebugStackFrameDescriptor _       ' __out DebugStackFrameDescriptor *prgdsfd
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppedsf AS IEnumDebugStackFrames _            ' __out IEnumDebugStackFrames **ppedsf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IEnumDebugStackFrames64 method
   ' =====================================================================================
   METHOD Next64 ( _                                    ' VTable offset = 28
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF prgdsfd AS DebugStackFrameDescriptor64 _     ' __out DebugStackFrameDescriptor64 *prgdsfd
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumDebugStackFrames64_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugDocumentInfo
' IID = 51973C1f-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebugDocumentInfo_INTERFACE_DEFINED)
    %IDebugDocumentInfo_INTERFACE_DEFINED = 1

$IID_IDebugDocumentInfo = GUID$("{51973C1f-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugDocumentInfo $IID_IDebugDocumentInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 12
     BYVAL dnt AS DOCUMENTNAMETYPE_ENUM _               ' __in DOCUMENTNAMETYPE dnt
   , BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDocumentClassId ( _                        ' VTable offset = 16
     BYREF pclsidDocument AS GUID _                     ' __out CLSID *pclsidDocument
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugDocumentInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugDocumentProvider
' IID = 51973C20-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IDebugDocumentInfo
' ########################################################################################

#IF NOT %DEF(%IDebugDocumentProvider_INTERFACE_DEFINED)
    %IDebugDocumentProvider_INTERFACE_DEFINED = 1

$IID_IDebugDocumentProvider = GUID$("{51973C20-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugDocumentProvider $IID_IDebugDocumentProvider

   INHERIT IUnknown

   ' =====================================================================================
   ' IDebugDocumentInfo methods
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 12
     BYVAL dnt AS DOCUMENTNAMETYPE_ENUM _               ' __in DOCUMENTNAMETYPE dnt
   , BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDocumentClassId ( _                        ' VTable offset = 16
     BYREF pclsidDocument AS GUID _                     ' __out CLSID *pclsidDocument
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDebugDocumentProvider method
   ' =====================================================================================
   METHOD GetDocument ( _                               ' VTable offset = 20
     BYREF ppssd AS IDebugDocument _                    ' __out IDebugDocument **ppssd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugDocumentProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugDocument
' IID = 51973C21-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IDebugDocumentInfo
' ########################################################################################

#IF NOT %DEF(%IDebugDocument_INTERFACE_DEFINED)
    %IDebugDocument_INTERFACE_DEFINED = 1

$IID_IDebugDocument = GUID$("{51973C21-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugDocument $IID_IDebugDocument

   INHERIT IUnknown

   ' =====================================================================================
   ' IDebugDocumentInfo methods
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 12
     BYVAL dnt AS DOCUMENTNAMETYPE_ENUM _               ' __in DOCUMENTNAMETYPE dnt
   , BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDocumentClassId ( _                        ' VTable offset = 16
     BYREF pclsidDocument AS GUID _                     ' __out CLSID *pclsidDocument
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugDocument_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugDocumentText
' IID = 51973C22-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IDebugDocument
' ########################################################################################

#IF NOT %DEF(%IDebugDocumentText_INTERFACE_DEFINED)
    %IDebugDocumentText_INTERFACE_DEFINED = 1

$IID_IDebugDocumentText = GUID$("{51973C22-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugDocumentText $IID_IDebugDocumentText

   INHERIT IUnknown

   ' =====================================================================================
   ' IDebugDocumentInfo methods
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 12
     BYVAL dnt AS DOCUMENTNAMETYPE_ENUM _               ' __in DOCUMENTNAMETYPE dnt
   , BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDocumentClassId ( _                        ' VTable offset = 16
     BYREF pclsidDocument AS GUID _                     ' __out CLSID *pclsidDocument
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDebugDocumentText methods
   ' =====================================================================================
   METHOD GetDocumentAttributes ( _                     ' VTable offset = 20
     BYREF ptextdocattr AS TEXT_DOC_ATTR _              ' __out TEXT_DOC_ATTR *ptextdocattr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 24
     BYREF pcNumLines AS DWORD _                        ' __out ULONG *pcNumLines
   , BYREF pcNumChars AS DWORD _                        ' __out ULONG *pcNumChars
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPositionOfLine ( _                         ' VTable offset = 28
     BYVAL cLineNumber AS DWORD _                       ' __in ULONG cLineNumber
   , BYREF pcCharacterPosition AS DWORD _               ' __out ULONG *pcCharacterPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLineOfPosition ( _                         ' VTable offset = 32
     BYVAL cCharacterPosition AS DWORD _                ' __in ULONG cCharacterPosition
   , BYREF pcLineNumber AS DWORD _                      ' __out ULONG *pcLineNumber
   , BYREF pcCharacterOffsetInLine AS DWORD _           ' __out ULONG *pcCharacterOffsetInLine
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetText ( _                                   ' VTable offset = 36
     BYVAL cCharacterPosition AS DWORD _                ' __in ULONG cCharacterPosition
   , BYREF pcharText AS WSTRINGZ _                      ' __inout WCHAR *pcharText
   , BYREF pstaTextAttr AS SOURCE_TEXT_ATTR _           ' __inout SOURCE_TEXT_ATTR *pstaTextAttr
   , BYREF pcNumChars AS DWORD _                        ' __inout ULONG *pcNumChars
   , BYVAL cMaxChars AS DWORD _                         ' __in ULONG cMaxChars
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPositionOfContext ( _                      ' VTable offset = 40
     BYVAL psc AS IDebugDocumentContext _               ' __in IDebugDocumentContext *psc
   , BYREF pcCharacterPosition AS DWORD _               ' __out ULONG *pcCharacterPosition
   , BYREF cNumChars AS DWORD _                         ' __out ULONG *cNumChars
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContextOfPosition ( _                      ' VTable offset = 44
     BYVAL cCharacterPosition AS DWORD _                ' __in ULONG cCharacterPosition
   , BYVAL cNumChars AS DWORD _                         ' __in ULONG cNumChars
   , BYREF ppsc AS IDebugDocumentContext _              ' __out IDebugDocumentContext **ppsc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugDocumentText_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugDocumentTextEvents
' IID = 51973C23-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebugDocumentTextEvents_INTERFACE_DEFINED)
    %IDebugDocumentTextEvents_INTERFACE_DEFINED = 1

$IID_IDebugDocumentTextEvents = GUID$("{51973C23-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugDocumentTextEvents $IID_IDebugDocumentTextEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD onDestroy ( _                                 ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD onInsertText ( _                              ' VTable offset = 16
     BYVAL cCharacterPosition AS DWORD _                ' __in ULONG cCharacterPosition
   , BYVAL cNumToInsert AS DWORD _                      ' __in ULONG cNumToInsert
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD onRemoveText ( _                              ' VTable offset = 20
     BYVAL cCharacterPosition AS DWORD _                ' __in ULONG cCharacterPosition
   , BYVAL cNumToRemove AS DWORD _                      ' __in ULONG cNumToRemove
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD onReplaceText ( _                             ' VTable offset = 24
     BYVAL cCharacterPosition AS DWORD _                ' __in ULONG cCharacterPosition
   , BYVAL cNumToReplace AS DWORD _                     ' __in ULONG cNumToReplace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD onUpdateTextAttributes ( _                    ' VTable offset = 28
     BYVAL cCharacterPosition AS DWORD _                ' __in ULONG cCharacterPosition
   , BYVAL cNumToUpdate AS DWORD _                      ' __in ULONG cNumToUpdate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD onUpdateDocumentAttributes ( _                ' VTable offset = 32
     BYVAL textdocattr AS TEXT_DOC_ATTR _               ' __in TEXT_DOC_ATTR textdocattr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugDocumentTextEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugDocumentTextAuthor
' IID = 51973C24-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IDebugDocumentText
' ########################################################################################

#IF NOT %DEF(%IDebugDocumentTextAuthor_INTERFACE_DEFINED)
    %IDebugDocumentTextAuthor_INTERFACE_DEFINED = 1

$IID_IDebugDocumentTextAuthor = GUID$("{51973C24-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugDocumentTextAuthor $IID_IDebugDocumentTextAuthor

   INHERIT IUnknown

   ' =====================================================================================
   ' IDebugDocumentInfo methods
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 12
     BYVAL dnt AS DOCUMENTNAMETYPE_ENUM _               ' __in DOCUMENTNAMETYPE dnt
   , BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDocumentClassId ( _                        ' VTable offset = 16
     BYREF pclsidDocument AS GUID _                     ' __out CLSID *pclsidDocument
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDebugDocumentText methods
   ' =====================================================================================
   METHOD GetDocumentAttributes ( _                     ' VTable offset = 20
     BYREF ptextdocattr AS TEXT_DOC_ATTR _              ' __out TEXT_DOC_ATTR *ptextdocattr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 24
     BYREF pcNumLines AS DWORD _                        ' __out ULONG *pcNumLines
   , BYREF pcNumChars AS DWORD _                        ' __out ULONG *pcNumChars
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPositionOfLine ( _                         ' VTable offset = 28
     BYVAL cLineNumber AS DWORD _                       ' __in ULONG cLineNumber
   , BYREF pcCharacterPosition AS DWORD _               ' __out ULONG *pcCharacterPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLineOfPosition ( _                         ' VTable offset = 32
     BYVAL cCharacterPosition AS DWORD _                ' __in ULONG cCharacterPosition
   , BYREF pcLineNumber AS DWORD _                      ' __out ULONG *pcLineNumber
   , BYREF pcCharacterOffsetInLine AS DWORD _           ' __out ULONG *pcCharacterOffsetInLine
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetText ( _                                   ' VTable offset = 36
     BYVAL cCharacterPosition AS DWORD _                ' __in ULONG cCharacterPosition
   , BYREF pcharText AS WSTRINGZ _                      ' __inout WCHAR *pcharText
   , BYREF pstaTextAttr AS SOURCE_TEXT_ATTR _           ' __inout SOURCE_TEXT_ATTR *pstaTextAttr
   , BYREF pcNumChars AS DWORD _                        ' __inout ULONG *pcNumChars
   , BYVAL cMaxChars AS DWORD _                         ' __in ULONG cMaxChars
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPositionOfContext ( _                      ' VTable offset = 40
     BYVAL psc AS IDebugDocumentContext _               ' __in IDebugDocumentContext *psc
   , BYREF pcCharacterPosition AS DWORD _               ' __out ULONG *pcCharacterPosition
   , BYREF cNumChars AS DWORD _                         ' __out ULONG *cNumChars
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContextOfPosition ( _                      ' VTable offset = 44
     BYVAL cCharacterPosition AS DWORD _                ' __in ULONG cCharacterPosition
   , BYVAL cNumChars AS DWORD _                         ' __in ULONG cNumChars
   , BYREF ppsc AS IDebugDocumentContext _              ' __out IDebugDocumentContext **ppsc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDebugDocumentTextAuthor methods
   ' =====================================================================================
   METHOD InsertText ( _                                ' VTable offset = 48
     BYVAL cCharacterPosition AS DWORD _                ' __in ULONG cCharacterPosition
   , BYVAL cNumToInsert AS DWORD _                      ' __in ULONG cNumToInsert
   , BYREF pcharText AS WSTRINGZ _                      ' __in OLECHAR pcharText[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveText ( _                                ' VTable offset = 52
     BYVAL cCharacterPosition AS DWORD _                ' __in ULONG cCharacterPosition
   , BYVAL cNumToRemove AS DWORD _                      ' __in ULONG cNumToRemove
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReplaceText ( _                               ' VTable offset = 56
     BYVAL cCharacterPosition AS DWORD _                ' __in ULONG cCharacterPosition
   , BYVAL cNumToReplace AS DWORD _                     ' __in ULONG cNumToReplace
   , BYREF pcharText AS WSTRINGZ _                      ' __in OLECHAR pcharText[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugDocumentTextAuthor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugDocumentTextExternalAuthor
' IID = 51973C25-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebugDocumentTextExternalAuthor_INTERFACE_DEFINED)
    %IDebugDocumentTextExternalAuthor_INTERFACE_DEFINED = 1

$IID_IDebugDocumentTextExternalAuthor = GUID$("{51973C25-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugDocumentTextExternalAuthor $IID_IDebugDocumentTextExternalAuthor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPathName ( _                               ' VTable offset = 12
     BYREF pbstrLongName AS WSTRING _                   ' __out BSTR *pbstrLongName
   , BYREF pfIsOriginalFile AS LONG _                   ' __out BOOL *pfIsOriginalFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFileName ( _                               ' VTable offset = 16
     BYREF pbstrShortName AS WSTRING _                  ' __out BSTR *pbstrShortName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NotifyChanged ( _                             ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugDocumentTextExternalAuthor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugDocumentHelper32
' IID = 51973C26-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebugDocumentHelper32_INTERFACE_DEFINED)
    %IDebugDocumentHelper32_INTERFACE_DEFINED = 1

$IID_IDebugDocumentHelper32 = GUID$("{51973C26-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugDocumentHelper32 $IID_IDebugDocumentHelper32

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Init ( _                                      ' VTable offset = 12
     BYVAL pda AS IDebugApplication32 _                 ' __in IDebugApplication32 *pda
   , BYREF pszShortName AS WSTRINGZ _                   ' __in LPCOLESTR pszShortName
   , BYREF pszLongName AS WSTRINGZ _                    ' __in LPCOLESTR pszLongName
   , BYVAL docAttr AS TEXT_DOC_ATTR _                   ' __in TEXT_DOC_ATTR docAttr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Attach ( _                                    ' VTable offset = 16
     BYVAL pddhParent AS IDebugDocumentHelper32 _       ' __in IDebugDocumentHelper32 *pddhParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Detach ( _                                    ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddUnicodeText ( _                            ' VTable offset = 24
     BYREF pszText AS WSTRINGZ _                        ' __in LPCOLESTR pszText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddDBCSText ( _                               ' VTable offset = 28
     BYREF pszText AS ASCIIZ _                          ' __in LPCSTR pszText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDebugDocumentHost ( _                      ' VTable offset = 32
     BYVAL pddh AS IDebugDocumentHost _                 ' __in IDebugDocumentHost *pddh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddDeferredText ( _                           ' VTable offset = 36
     BYVAL cChars AS DWORD _                            ' __in ULONG cChars
   , BYVAL dwTextStartCookie AS DWORD _                 ' __in DWORD dwTextStartCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DefineScriptBlock ( _                         ' VTable offset = 40
     BYVAL ulCharOffset AS DWORD _                      ' __in ULONG ulCharOffset
   , BYVAL cChars AS DWORD _                            ' __in ULONG cChars
   , BYVAL pas AS IActiveScript _                       ' __in IActiveScript *pas
   , BYVAL fScriptlet AS LONG _                         ' __in BOOL fScriptlet
   , BYREF pdwSourceContext AS DWORD _                  ' __out DWORD *pdwSourceContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultTextAttr ( _                        ' VTable offset = 44
     BYVAL staTextAttr AS SOURCE_TEXT_ATTR _            ' __in SOURCE_TEXT_ATTR staTextAttr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTextAttributes ( _                         ' VTable offset = 48
     BYVAL ulCharOffset AS DWORD _                      ' __in ULONG ulCharOffset
   , BYVAL cChars AS DWORD _                            ' __in ULONG cChars
   , BYREF pstaTextAttr AS SOURCE_TEXT_ATTR _           ' __in SOURCE_TEXT_ATTR *pstaTextAttr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLongName ( _                               ' VTable offset = 52
     BYREF pszLongName AS WSTRINGZ _                    ' __in LPCOLESTR pszLongName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetShortName ( _                              ' VTable offset = 56
     BYREF pszShortName AS WSTRINGZ _                   ' __in LPCOLESTR pszShortName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDocumentAttr ( _                           ' VTable offset = 60
     BYVAL pszAttributes AS TEXT_DOC_ATTR _             ' __in TEXT_DOC_ATTR pszAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDebugApplicationNode ( _                   ' VTable offset = 64
     BYREF ppdan AS IDebugApplicationNode _             ' __out IDebugApplicationNode **ppdan
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScriptBlockInfo ( _                        ' VTable offset = 68
     BYVAL dwSourceContext AS DWORD _                   ' __in DWORD dwSourceContext
   , BYREF ppasd AS IActiveScript _                     ' __out IActiveScript **ppasd
   , BYREF piCharPos AS DWORD _                         ' __out ULONG *piCharPos
   , BYREF pcChars AS DWORD _                           ' __out ULONG *pcChars
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDebugDocumentContext ( _                ' VTable offset = 72
     BYVAL iCharPos AS DWORD _                          ' __in ULONG iCharPos
   , BYVAL cChars AS DWORD _                            ' __in ULONG cChars
   , BYREF ppddc AS IDebugDocumentContext _             ' __out IDebugDocumentContext **ppddc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BringDocumentToTop ( _                        ' VTable offset = 76
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BringDocumentContextToTop ( _                 ' VTable offset = 80
     BYVAL pddc AS IDebugDocumentContext _              ' IDebugDocumentContext *pddc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugDocumentHelper32_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugDocumentHelper64
' IID = c4c7363c-20fd-47f9-bd82-4855e0150871
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebugDocumentHelper64_INTERFACE_DEFINED)
    %IDebugDocumentHelper64_INTERFACE_DEFINED = 1

$IID_IDebugDocumentHelper64 = GUID$("{c4c7363c-20fd-47f9-bd82-4855e0150871}")

INTERFACE IDebugDocumentHelper64 $IID_IDebugDocumentHelper64

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Init ( _                                      ' VTable offset = 12
     BYVAL pda AS IDebugApplication64 _                 ' __in IDebugApplication64 *pda
   , BYREF pszShortName AS WSTRINGZ _                   ' __in LPCOLESTR pszShortName
   , BYREF pszLongName AS WSTRINGZ _                    ' __in LPCOLESTR pszLongName
   , BYVAL docAttr AS TEXT_DOC_ATTR _                   ' __in TEXT_DOC_ATTR docAttr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Attach ( _                                    ' VTable offset = 16
     BYVAL pddhParent AS IDebugDocumentHelper64 _       ' __in IDebugDocumentHelper64 *pddhParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Detach ( _                                    ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddUnicodeText ( _                            ' VTable offset = 24
     BYREF pszText AS WSTRINGZ _                        ' __in LPCOLESTR pszText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddDBCSText ( _                               ' VTable offset = 28
     BYREF pszText AS ASCIIZ _                          ' __in LPCSTR pszText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDebugDocumentHost ( _                      ' VTable offset = 32
     BYVAL pddh AS IDebugDocumentHost _                 ' __in IDebugDocumentHost *pddh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddDeferredText ( _                           ' VTable offset = 36
     BYVAL cChars AS DWORD _                            ' __in ULONG cChars
   , BYVAL dwTextStartCookie AS DWORD _                 ' __in DWORD dwTextStartCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DefineScriptBlock ( _                         ' VTable offset = 40
     BYVAL ulCharOffset AS DWORD _                      ' __in ULONG ulCharOffset
   , BYVAL cChars AS DWORD _                            ' __in ULONG cChars
   , BYVAL pas AS IActiveScript _                       ' __in IActiveScript *pas
   , BYVAL fScriptlet AS LONG _                         ' __in BOOL fScriptlet
   , BYREF pdwSourceContext AS QUAD _                   ' __out DWORDLONG *pdwSourceContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultTextAttr ( _                        ' VTable offset = 44
     BYVAL staTextAttr AS SOURCE_TEXT_ATTR _            ' __in SOURCE_TEXT_ATTR staTextAttr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTextAttributes ( _                         ' VTable offset = 48
     BYVAL ulCharOffset AS DWORD _                      ' __in ULONG ulCharOffset
   , BYVAL cChars AS DWORD _                            ' __in ULONG cChars
   , BYREF pstaTextAttr AS SOURCE_TEXT_ATTR _           ' __in SOURCE_TEXT_ATTR *pstaTextAttr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLongName ( _                               ' VTable offset = 52
     BYREF pszLongName AS WSTRINGZ _                    ' __in LPCOLESTR pszLongName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetShortName ( _                              ' VTable offset = 56
     BYREF pszShortName AS WSTRINGZ _                   ' __in LPCOLESTR pszShortName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDocumentAttr ( _                           ' VTable offset = 60
     BYVAL pszAttributes AS TEXT_DOC_ATTR _             ' __in TEXT_DOC_ATTR pszAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDebugApplicationNode ( _                   ' VTable offset = 64
     BYREF ppdan AS IDebugApplicationNode _             ' __out IDebugApplicationNode **ppdan
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScriptBlockInfo ( _                        ' VTable offset = 68
     BYVAL dwSourceContext AS QUAD _                    ' __in DWORDLONG dwSourceContext
   , BYREF ppasd AS IActiveScript _                     ' __out IActiveScript **ppasd
   , BYREF piCharPos AS DWORD _                         ' __out ULONG *piCharPos
   , BYREF pcChars AS DWORD _                           ' __out ULONG *pcChars
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDebugDocumentContext ( _                ' VTable offset = 72
     BYVAL iCharPos AS DWORD _                          ' __in ULONG iCharPos
   , BYVAL cChars AS DWORD _                            ' __in ULONG cChars
   , BYREF ppddc AS IDebugDocumentContext _             ' __out IDebugDocumentContext **ppddc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BringDocumentToTop ( _                        ' VTable offset = 76
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BringDocumentContextToTop ( _                 ' VTable offset = 80
     BYVAL pddc AS IDebugDocumentContext _              ' IDebugDocumentContext *pddc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugDocumentHelper64_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugDocumentHost
' IID = 51973C27-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebugDocumentHost_INTERFACE_DEFINED)
    %IDebugDocumentHost_INTERFACE_DEFINED = 1

$IID_IDebugDocumentHost = GUID$("{51973C27-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugDocumentHost $IID_IDebugDocumentHost

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDeferredText ( _                           ' VTable offset = 12
     BYVAL dwTextStartCookie AS DWORD _                 ' __in DWORD dwTextStartCookie
   , BYREF pcharText AS WSTRINGZ _                      ' __inout WCHAR *pcharText
   , BYREF pstaTextAttr AS SOURCE_TEXT_ATTR _           ' __inout SOURCE_TEXT_ATTR *pstaTextAttr
   , BYREF pcNumChars AS DWORD _                        ' __inout ULONG *pcNumChars
   , BYVAL cMaxChars AS DWORD _                         ' __in ULONG cMaxChars
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScriptTextAttributes ( _                   ' VTable offset = 16
     BYREF pstrCode AS WSTRINGZ _                       ' __in LPCOLESTR pstrCode
   , BYVAL uNumCodeChars AS DWORD _                     ' __in ULONG uNumCodeChars
   , BYREF pstrDelimiter AS WSTRINGZ _                  ' __in LPCOLESTR pstrDelimiter
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pattr AS SOURCE_TEXT_ATTR _                  ' __inout SOURCE_TEXT_ATTR *pattr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCreateDocumentContext ( _                   ' VTable offset = 20
     BYREF ppunkOuter AS IUnknown _                     ' __out IUnknown **ppunkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPathName ( _                               ' VTable offset = 24
     BYREF pbstrLongName AS WSTRING _                   ' __out BSTR *pbstrLongName
   , BYREF pfIsOriginalFile AS LONG _                   ' __out BOOL *pfIsOriginalFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFileName ( _                               ' VTable offset = 28
     BYREF pbstrShortName AS WSTRING _                  ' __out BSTR *pbstrShortName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NotifyChanged ( _                             ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugDocumentHost_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugDocumentContext
' IID = 51973C28-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebugDocumentContext_INTERFACE_DEFINED)
    %IDebugDocumentContext_INTERFACE_DEFINED = 1

$IID_IDebugDocumentContext = GUID$("{51973C28-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugDocumentContext $IID_IDebugDocumentContext

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDocument ( _                               ' VTable offset = 12
     BYREF ppsd AS IDebugDocument _                     ' __out IDebugDocument **ppsd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumCodeContexts ( _                          ' VTable offset = 16
     BYREF ppescc AS IEnumDebugCodeContexts _           ' __out IEnumDebugCodeContexts **ppescc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugDocumentContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugSessionProvider
' IID = 51973C29-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebugSessionProvider_INTERFACE_DEFINED)
    %IDebugSessionProvider_INTERFACE_DEFINED = 1

$IID_IDebugSessionProvider = GUID$("{51973C29-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugSessionProvider $IID_IDebugSessionProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD StartDebugSession ( _                         ' VTable offset = 12
     BYVAL pda AS IRemoteDebugApplication _             ' __in IRemoteDebugApplication *pda
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugSessionProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IApplicationDebugger
' IID = 51973C2a-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IApplicationDebugger_INTERFACE_DEFINED)
    %IApplicationDebugger_INTERFACE_DEFINED = 1

$IID_IApplicationDebugger = GUID$("{51973C2a-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IApplicationDebugger $IID_IApplicationDebugger

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryAlive ( _                                ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateInstanceAtDebugger ( _                  ' VTable offset = 16
     BYREF rclsid AS GUID _                             ' __in REFCLSID rclsid
   , BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYVAL dwClsContext AS DWORD _                      ' __in DWORD dwClsContext
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS IUnknown _                      ' __out IUnknown **ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD onDebugOutput ( _                             ' VTable offset = 20
     BYREF pstr AS WSTRINGZ _                           ' __in LPCOLESTR pstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD onHandleBreakPoint ( _                        ' VTable offset = 24
     BYVAL prpt AS IRemoteDebugApplicationThread _      ' __in IRemoteDebugApplicationThread *prpt
   , BYVAL br AS BREAKREASON_ENUM _                     ' __in BREAKREASON br
   , BYVAL pError AS IActiveScriptErrorDebug _          ' __in IActiveScriptErrorDebug *pError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD onClose ( _                                   ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD onDebuggerEvent ( _                           ' VTable offset = 28
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IApplicationDebugger_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IApplicationDebuggerUI
' IID = 51973C2b-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IApplicationDebuggerUI_INTERFACE_DEFINED)
    %IApplicationDebuggerUI_INTERFACE_DEFINED = 1

$IID_IApplicationDebuggerUI = GUID$("{51973C2b-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IApplicationDebuggerUI $IID_IApplicationDebuggerUI

   INHERIT IUnknown

   ' =====================================================================================
   METHOD BringDocumentToTop ( _                        ' VTable offset = 12
     BYVAL pddt AS IDebugDocumentText _                 ' __in IDebugDocumentText *pddt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BringDocumentContextToTop ( _                 ' VTable offset = 16
     BYVAL pddc AS IDebugDocumentContext _              ' __in IDebugDocumentContext *pddc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IApplicationDebuggerUI_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMachineDebugManager
' IID = 51973C2c-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMachineDebugManager_INTERFACE_DEFINED)
    %IMachineDebugManager_INTERFACE_DEFINED = 1

$IID_IMachineDebugManager = GUID$("{51973C2c-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IMachineDebugManager $IID_IMachineDebugManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddApplication ( _                            ' VTable offset = 12
     BYVAL pda AS IRemoteDebugApplication _             ' __in IRemoteDebugApplication *pda
   , BYREF pdwAppCookie AS DWORD _                      ' __out DWORD *pdwAppCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveApplication ( _                         ' VTable offset = 16
     BYVAL dwAppCookie AS DWORD _                       ' __in DWORD dwAppCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumApplications ( _                          ' VTable offset = 20
     BYREF ppeda AS IEnumRemoteDebugApplications _      ' __out IEnumRemoteDebugApplications **ppeda
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMachineDebugManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMachineDebugManagerCookie
' IID = 51973C2d-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMachineDebugManagerCookie_INTERFACE_DEFINED)
    %IMachineDebugManagerCookie_INTERFACE_DEFINED = 1

$IID_IMachineDebugManagerCookie = GUID$("{51973C2d-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IMachineDebugManagerCookie $IID_IMachineDebugManagerCookie

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddApplication ( _                            ' VTable offset = 12
     BYVAL pda AS IRemoteDebugApplication _             ' __in IRemoteDebugApplication *pda
   , BYVAL dwDebugAppCookie AS DWORD _                  ' __in DWORD dwDebugAppCookie
   , BYREF pdwAppCookie AS DWORD _                      ' __out DWORD *pdwAppCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveApplication ( _                         ' VTable offset = 16
     BYVAL dwDebugAppCookie AS DWORD _                  ' __in DWORD dwDebugAppCookie
   , BYVAL dwAppCookie AS DWORD _                       ' __in DWORD dwAppCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumApplications ( _                          ' VTable offset = 20
     BYREF ppeda AS IEnumRemoteDebugApplications _      ' __out IEnumRemoteDebugApplications **ppeda
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMachineDebugManagerCookie_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMachineDebugManagerEvents
' IID = 51973C2e-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMachineDebugManagerEvents_INTERFACE_DEFINED)
    %IMachineDebugManagerEvents_INTERFACE_DEFINED = 1

$IID_IMachineDebugManagerEvents = GUID$("{51973C2e-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IMachineDebugManagerEvents $IID_IMachineDebugManagerEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD onAddApplication ( _                          ' VTable offset = 12
     BYVAL pda AS IRemoteDebugApplication _             ' __in IRemoteDebugApplication *pda
   , BYVAL dwAppCookie AS DWORD _                       ' __in DWORD dwAppCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD onRemoveApplication ( _                       ' VTable offset = 16
     BYVAL pda AS IRemoteDebugApplication _             ' __in IRemoteDebugApplication *pda
   , BYVAL dwAppCookie AS DWORD _                       ' __in DWORD dwAppCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMachineDebugManagerEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IProcessDebugManager32
' IID = 51973C2f-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IProcessDebugManager32_INTERFACE_DEFINED)
    %IProcessDebugManager32_INTERFACE_DEFINED = 1

$IID_IProcessDebugManager32 = GUID$("{51973C2f-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IProcessDebugManager32 $IID_IProcessDebugManager32

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateApplication ( _                         ' VTable offset = 12
     BYREF ppda AS IDebugApplication32 _                ' __out IDebugApplication32 **ppda
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultApplication ( _                     ' VTable offset = 16
     BYREF ppda AS IDebugApplication32 _                ' __out IDebugApplication32 **ppda
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddApplication ( _                            ' VTable offset = 20
     BYVAL pda AS IDebugApplication32 _                 ' __in IDebugApplication32 *pda
   , BYREF pdwAppCookie AS DWORD _                      ' __out DWORD *pdwAppCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveApplication ( _                         ' VTable offset = 24
     BYVAL dwAppCookie AS DWORD _                       ' __in DWORD dwAppCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDebugDocumentHelper ( _                 ' VTable offset = 28
     BYVAL punkOuter AS IUnknown _                      ' __in IUnknown *punkOuter
   , BYREF pddh AS IDebugDocumentHelper32 _             ' __out IDebugDocumentHelper32 **pddh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProcessDebugManager32_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IProcessDebugManager64
' IID = 56b9fc1c-63a9-4cc1-ac21-087d69a17fab
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IProcessDebugManager64_INTERFACE_DEFINED)
    %IProcessDebugManager64_INTERFACE_DEFINED = 1

$IID_IProcessDebugManager64 = GUID$("{56b9fc1c-63a9-4cc1-ac21-087d69a17fab}")

INTERFACE IProcessDebugManager64 $IID_IProcessDebugManager64

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateApplication ( _                         ' VTable offset = 12
     BYREF ppda AS IDebugApplication64 _                ' __out IDebugApplication64 **ppda
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultApplication ( _                     ' VTable offset = 16
     BYREF ppda AS IDebugApplication64 _                ' __out IDebugApplication64 **ppda
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddApplication ( _                            ' VTable offset = 20
     BYVAL pda AS IDebugApplication64 _                 ' __in IDebugApplication64 *pda
   , BYREF pdwAppCookie AS DWORD _                      ' __out DWORD *pdwAppCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveApplication ( _                         ' VTable offset = 24
     BYVAL dwAppCookie AS DWORD _                       ' __in DWORD dwAppCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDebugDocumentHelper ( _                 ' VTable offset = 28
     BYVAL punkOuter AS IUnknown _                      ' __in IUnknown *punkOuter
   , BYREF pddh AS IDebugDocumentHelper64 _             ' __out IDebugDocumentHelper64 **pddh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProcessDebugManager64_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRemoteDebugApplication
' IID = 51973C30-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRemoteDebugApplication_INTERFACE_DEFINED)
    %IRemoteDebugApplication_INTERFACE_DEFINED = 1

$IID_IRemoteDebugApplication = GUID$("{51973C30-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IRemoteDebugApplication $IID_IRemoteDebugApplication

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ResumeFromBreakPoint ( _                      ' VTable offset = 12
     BYVAL prptFocus AS IRemoteDebugApplicationThread _ ' __in IRemoteDebugApplicationThread *prptFocus
   , BYVAL bra AS BREAKRESUMEACTION_ENUM _              ' __in BREAKRESUMEACTION bra
   , BYVAL era AS ERRORRESUMEACTION_ENUM _              ' __in ERRORRESUMEACTION era
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CauseBreak ( _                                ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConnectDebugger ( _                           ' VTable offset = 20
     BYVAL pad AS IApplicationDebugger _                ' __in IApplicationDebugger *pad
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisconnectDebugger ( _                        ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDebugger ( _                               ' VTable offset = 28
     BYREF pad AS IApplicationDebugger _                ' __out IApplicationDebugger **pad
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateInstanceAtApplication ( _               ' VTable offset = 32
     BYREF rclsid AS GUID _                             ' __in REFCLSID rclsid
   , BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYVAL dwClsContext AS DWORD _                      ' __in DWORD dwClsContext
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS IUnknown _                      ' __out IUnknown **ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryAlive ( _                                ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumThreads ( _                               ' VTable offset = 40
     BYREF pperdat AS IEnumRemoteDebugApplicationThreads _ '__out IEnumRemoteDebugApplicationThreads **pperdat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 44
     BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRootNode ( _                               ' VTable offset = 48
     BYREF ppdanRoot AS IDebugApplicationNode _         ' __out IDebugApplicationNode **ppdanRoot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumGlobalExpressionContexts ( _              ' VTable offset = 52
     BYREF ppedec AS IEnumDebugExpressionContexts _     ' __out IEnumDebugExpressionContexts **ppedec
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRemoteDebugApplication_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugApplication32
' IID = 51973C32-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IRemoteDebugApplication
' ########################################################################################

#IF NOT %DEF(%IDebugApplication32_INTERFACE_DEFINED)
    %IDebugApplication32_INTERFACE_DEFINED = 1

$IID_IDebugApplication32 = GUID$("{51973C32-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugApplication32 $IID_IDebugApplication32

   INHERIT IUnknown

   ' =====================================================================================
   ' IRemoteDebugApplication methods
   ' =====================================================================================
   METHOD ResumeFromBreakPoint ( _                      ' VTable offset = 12
     BYVAL prptFocus AS IRemoteDebugApplicationThread _ ' __in IRemoteDebugApplicationThread *prptFocus
   , BYVAL bra AS BREAKRESUMEACTION_ENUM _              ' __in BREAKRESUMEACTION bra
   , BYVAL era AS ERRORRESUMEACTION_ENUM _              ' __in ERRORRESUMEACTION era
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CauseBreak ( _                                ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConnectDebugger ( _                           ' VTable offset = 20
     BYVAL pad AS IApplicationDebugger _                ' __in IApplicationDebugger *pad
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisconnectDebugger ( _                        ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDebugger ( _                               ' VTable offset = 28
     BYREF pad AS IApplicationDebugger _                ' __out IApplicationDebugger **pad
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateInstanceAtApplication ( _               ' VTable offset = 32
     BYREF rclsid AS GUID _                             ' __in REFCLSID rclsid
   , BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYVAL dwClsContext AS DWORD _                      ' __in DWORD dwClsContext
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS IUnknown _                      ' __out IUnknown **ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryAlive ( _                                ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumThreads ( _                               ' VTable offset = 40
     BYREF pperdat AS IEnumRemoteDebugApplicationThreads _ '__out IEnumRemoteDebugApplicationThreads **pperdat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 44
     BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRootNode ( _                               ' VTable offset = 48
     BYREF ppdanRoot AS IDebugApplicationNode _         ' __out IDebugApplicationNode **ppdanRoot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumGlobalExpressionContexts ( _              ' VTable offset = 52
     BYREF ppedec AS IEnumDebugExpressionContexts _     ' __out IEnumDebugExpressionContexts **ppedec
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDebugApplication32 methods
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 56
     BYREF pstrName AS WSTRINGZ _                       ' __in LPCOLESTR pstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StepOutComplete ( _                           ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DebugOutput ( _                               ' VTable offset = 64
     BYREF pstr AS WSTRINGZ _                           ' __in LPCOLESTR pstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StartDebugSession ( _                         ' VTable offset = 68
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HandleBreakPoint ( _                          ' VTable offset = 72
     BYVAL br AS BREAKREASON_ENUM _                     ' __in BREAKREASON br
   , BYREF pbra AS BREAKRESUMEACTION_ENUM _             ' __out BREAKRESUMEACTION *pbra
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 76
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBreakFlags ( _                             ' VTable offset = 80
     BYREF pabf AS APPBREAKFLAGS _                      ' __out APPBREAKFLAGS *pabf
   , BYREF pprdatSteppingThread AS IRemoteDebugApplicationThread _ ' __out IRemoteDebugApplicationThread **pprdatSteppingThread
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentThread ( _                          ' VTable offset = 84
     BYREF pat AS IDebugApplicationThread _             ' __out IDebugApplicationThread **pat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateAsyncDebugOperation ( _                 ' VTable offset = 88
     BYVAL psdo AS IDebugSyncOperation _                ' __in IDebugSyncOperation *psdo
   , BYREF ppado AS IDebugAsyncOperation _              ' __out IDebugAsyncOperation **ppado
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddStackFrameSniffer ( _                      ' VTable offset = 92
     BYVAL pdsfs AS IDebugStackFrameSniffer _           ' __in IDebugStackFrameSniffer *pdsfs
   , BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveStackFrameSniffer ( _                   ' VTable offset = 96
     BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryCurrentThreadIsDebuggerThread ( _        ' VTable offset = 100
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SynchronousCallInDebuggerThread ( _           ' VTable offset = 104
     BYVAL pptc AS IDebugThreadCall32 _                 ' __in IDebugThreadCall32 *pptc
   , BYVAL dwParam1 AS DWORD _                          ' __in DWORD dwParam1
   , BYVAL dwParam2 AS DWORD _                          ' __in DWORD dwParam2
   , BYVAL dwParam3 AS DWORD _                          ' __in DWORD dwParam3
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateApplicationNode ( _                     ' VTable offset = 108
     BYREF ppdanNew AS IDebugApplicationNode _          ' __out IDebugApplicationNode **ppdanNew
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FireDebuggerEvent ( _                         ' VTable offset = 112
     BYREF riid AS GUID _                               ' __in REFGUID riid
   , BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HandleRuntimeError ( _                        ' VTable offset = 116
     BYVAL pErrorDebug AS IActiveScriptErrorDebug _     ' __in IActiveScriptErrorDebug *pErrorDebug
   , BYVAL pScriptSite AS IActiveScriptSite _           ' __in IActiveScriptSite *pScriptSite
   , BYREF pbra AS BREAKRESUMEACTION_ENUM _             ' __out BREAKRESUMEACTION *pbra
   , BYREF perra AS ERRORRESUMEACTION_ENUM _            ' __out ERRORRESUMEACTION *perra
   , BYREF pfCallOnScriptError AS LONG _                ' __out BOOL *pfCallOnScriptError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FCanJitDebug ( _                              ' VTable offset = 120
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FIsAutoJitDebugEnabled ( _                    ' VTable offset = 124
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddGlobalExpressionContextProvider ( _        ' VTable offset = 128
     BYVAL pdsfs AS IProvideExpressionContexts _        ' __in IProvideExpressionContexts *pdsfs
   , BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveGlobalExpressionContextProvider ( _     ' VTable offset = 132
     BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugApplication32_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugApplication64
' IID = 4dedc754-04c7-4f10-9e60-16a390fe6e62
' Inherited interface = IRemoteDebugApplication
' ########################################################################################

#IF NOT %DEF(%IDebugApplication64_INTERFACE_DEFINED)
    %IDebugApplication64_INTERFACE_DEFINED = 1

$IID_IDebugApplication64 = GUID$("{4dedc754-04c7-4f10-9e60-16a390fe6e62}")

INTERFACE IDebugApplication64 $IID_IDebugApplication64

   INHERIT IUnknown

   ' =====================================================================================
   ' IRemoteDebugApplication methods
   ' =====================================================================================
   METHOD ResumeFromBreakPoint ( _                      ' VTable offset = 12
     BYVAL prptFocus AS IRemoteDebugApplicationThread _ ' __in IRemoteDebugApplicationThread *prptFocus
   , BYVAL bra AS BREAKRESUMEACTION_ENUM _              ' __in BREAKRESUMEACTION bra
   , BYVAL era AS ERRORRESUMEACTION_ENUM _              ' __in ERRORRESUMEACTION era
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CauseBreak ( _                                ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConnectDebugger ( _                           ' VTable offset = 20
     BYVAL pad AS IApplicationDebugger _                ' __in IApplicationDebugger *pad
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisconnectDebugger ( _                        ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDebugger ( _                               ' VTable offset = 28
     BYREF pad AS IApplicationDebugger _                ' __out IApplicationDebugger **pad
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateInstanceAtApplication ( _               ' VTable offset = 32
     BYREF rclsid AS GUID _                             ' __in REFCLSID rclsid
   , BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYVAL dwClsContext AS DWORD _                      ' __in DWORD dwClsContext
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS IUnknown _                      ' __out IUnknown **ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryAlive ( _                                ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumThreads ( _                               ' VTable offset = 40
     BYREF pperdat AS IEnumRemoteDebugApplicationThreads _ '__out IEnumRemoteDebugApplicationThreads **pperdat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 44
     BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRootNode ( _                               ' VTable offset = 48
     BYREF ppdanRoot AS IDebugApplicationNode _         ' __out IDebugApplicationNode **ppdanRoot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumGlobalExpressionContexts ( _              ' VTable offset = 52
     BYREF ppedec AS IEnumDebugExpressionContexts _     ' __out IEnumDebugExpressionContexts **ppedec
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDebugApplication64 methods
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 56
     BYREF pstrName AS WSTRINGZ _                       ' __in LPCOLESTR pstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StepOutComplete ( _                           ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DebugOutput ( _                               ' VTable offset = 64
     BYREF pstr AS WSTRINGZ _                           ' __in LPCOLESTR pstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StartDebugSession ( _                         ' VTable offset = 68
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HandleBreakPoint ( _                          ' VTable offset = 72
     BYVAL br AS BREAKREASON_ENUM _                     ' __in BREAKREASON br
   , BYREF pbra AS BREAKRESUMEACTION_ENUM _             ' __out BREAKRESUMEACTION *pbra
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 76
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBreakFlags ( _                             ' VTable offset = 80
     BYREF pabf AS APPBREAKFLAGS _                      ' __out APPBREAKFLAGS *pabf
   , BYREF pprdatSteppingThread AS IRemoteDebugApplicationThread _ ' __out IRemoteDebugApplicationThread **pprdatSteppingThread
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentThread ( _                          ' VTable offset = 84
     BYREF pat AS IDebugApplicationThread _             ' __out IDebugApplicationThread **pat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateAsyncDebugOperation ( _                 ' VTable offset = 88
     BYVAL psdo AS IDebugSyncOperation _                ' __in IDebugSyncOperation *psdo
   , BYREF ppado AS IDebugAsyncOperation _              ' __out IDebugAsyncOperation **ppado
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddStackFrameSniffer ( _                      ' VTable offset = 92
     BYVAL pdsfs AS IDebugStackFrameSniffer _           ' __in IDebugStackFrameSniffer *pdsfs
   , BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveStackFrameSniffer ( _                   ' VTable offset = 96
     BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryCurrentThreadIsDebuggerThread ( _        ' VTable offset = 100
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SynchronousCallInDebuggerThread ( _           ' VTable offset = 104
     BYVAL pptc AS IDebugThreadCall64 _                 ' __in IDebugThreadCall64 *pptc
   , BYVAL dwParam1 AS QUAD _                           ' __in DWORDLONG dwParam1
   , BYVAL dwParam2 AS QUAD _                           ' __in DWORDLONG dwParam2
   , BYVAL dwParam3 AS QUAD _                           ' __in DWORDLONG dwParam3
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateApplicationNode ( _                     ' VTable offset = 108
     BYREF ppdanNew AS IDebugApplicationNode _          ' __out IDebugApplicationNode **ppdanNew
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FireDebuggerEvent ( _                         ' VTable offset = 112
     BYREF riid AS GUID _                               ' __in REFGUID riid
   , BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HandleRuntimeError ( _                        ' VTable offset = 116
     BYVAL pErrorDebug AS IActiveScriptErrorDebug _     ' __in IActiveScriptErrorDebug *pErrorDebug
   , BYVAL pScriptSite AS IActiveScriptSite _           ' __in IActiveScriptSite *pScriptSite
   , BYREF pbra AS BREAKRESUMEACTION_ENUM _             ' __out BREAKRESUMEACTION *pbra
   , BYREF perra AS ERRORRESUMEACTION_ENUM _            ' __out ERRORRESUMEACTION *perra
   , BYREF pfCallOnScriptError AS LONG _                ' __out BOOL *pfCallOnScriptError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FCanJitDebug ( _                              ' VTable offset = 120
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FIsAutoJitDebugEnabled ( _                    ' VTable offset = 124
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddGlobalExpressionContextProvider ( _        ' VTable offset = 128
     BYVAL pdsfs AS IProvideExpressionContexts _        ' __in IProvideExpressionContexts *pdsfs
   , BYREF pdwCookie AS QUAD _                          ' __out DWORDLONG *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveGlobalExpressionContextProvider ( _     ' VTable offset = 132
     BYVAL dwCookie AS QUAD _                           ' __in DWORDLONG dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugApplication64_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRemoteDebugApplicationEvents
' IID = 51973C33-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRemoteDebugApplicationEvents_INTERFACE_DEFINED)
    %IRemoteDebugApplicationEvents_INTERFACE_DEFINED = 1

$IID_IRemoteDebugApplicationEvents = GUID$("{51973C33-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IRemoteDebugApplicationEvents $IID_IRemoteDebugApplicationEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnConnectDebugger ( _                         ' VTable offset = 12
     BYVAL pad AS IApplicationDebugger _                ' __in IApplicationDebugger *pad
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDisconnectDebugger ( _                      ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnSetName ( _                                 ' VTable offset = 20
     BYREF pstrName AS WSTRINGZ _                       ' __in LPCOLESTR pstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDebugOutput ( _                             ' VTable offset = 24
     BYREF pstrName AS WSTRINGZ _                       ' __in LPCOLESTR pstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnClose ( _                                   ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnEnterBreakPoint ( _                         ' VTable offset = 32
     BYVAL prdat AS IRemoteDebugApplicationThread _     ' __in IRemoteDebugApplicationThread *prdat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnLeaveBreakPoint ( _                         ' VTable offset = 36
     BYVAL prdat AS IRemoteDebugApplicationThread _     ' __in IRemoteDebugApplicationThread *prdat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCreateThread ( _                            ' VTable offset = 40
     BYVAL prdat AS IRemoteDebugApplicationThread _     ' __in IRemoteDebugApplicationThread *prdat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDestroyThread ( _                           ' VTable offset = 44
     BYVAL prdat AS IRemoteDebugApplicationThread _     ' __in IRemoteDebugApplicationThread *prdat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnBreakFlagChange ( _                         ' VTable offset = 48
     BYVAl abf AS APPBREAKFLAGS _                       ' __in APPBREAKFLAGS abf
   , BYVAL prdatSteppingThread AS IRemoteDebugApplicationThread _ '__in IRemoteDebugApplicationThread *prdatSteppingThread
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRemoteDebugApplicationEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugApplicationNode
' IID = 51973C34-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IDebugDocumentProvider
' ########################################################################################

#IF NOT %DEF(%IDebugApplicationNode_INTERFACE_DEFINED)
    %IDebugApplicationNode_INTERFACE_DEFINED = 1

$IID_IDebugApplicationNode = GUID$("{51973C34-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugApplicationNode $IID_IDebugApplicationNode

   INHERIT IUnknown

   ' =====================================================================================
   ' IDebugDocumentInfo methods
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 12
     BYVAL dnt AS DOCUMENTNAMETYPE_ENUM _               ' __in DOCUMENTNAMETYPE dnt
   , BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDocumentClassId ( _                        ' VTable offset = 16
     BYREF pclsidDocument AS GUID _                     ' __out CLSID *pclsidDocument
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDebugDocumentProvider method
   ' =====================================================================================
   METHOD GetDocument ( _                               ' VTable offset = 20
     BYREF ppssd AS IDebugDocument _                    ' __out IDebugDocument **ppssd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDebugApplicationNode methods
   ' =====================================================================================
   METHOD EnumChildren ( _                              ' VTable offset = 24
     BYREF pperddp AS IEnumDebugApplicationNodes _      ' __out IEnumDebugApplicationNodes **pperddp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParent ( _                                 ' VTable offset = 28
     BYREF pprddp AS IDebugApplicationNode _            ' __out IDebugApplicationNode **pprddp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDocumentProvider ( _                       ' VTable offset = 32
     BYVAL pddp AS IDebugDocumentProvider _             ' __in IDebugDocumentProvider *pddp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Attach ( _                                    ' VTable offset = 40
     BYVAL pdanParent AS IDebugApplicationNode _        ' __in IDebugApplicationNode *pdanParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Detach ( _                                    ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugApplicationNode_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugApplicationNodeEvents
' IID = 51973C35-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebugApplicationNodeEvents_INTERFACE_DEFINED)
    %IDebugApplicationNodeEvents_INTERFACE_DEFINED = 1

$IID_IDebugApplicationNodeEvents = GUID$("{51973C35-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugApplicationNodeEvents $IID_IDebugApplicationNodeEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD onAddChild ( _                                ' VTable offset = 12
     BYVAL prddpChild AS IDebugApplicationNode _        ' __in IDebugApplicationNode *prddpChild
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD onRemoveChild ( _                             ' VTable offset = 16
     BYVAL prddpChild AS IDebugApplicationNode _        ' __in IDebugApplicationNode *prddpChild
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD onDetach ( _                                  ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD onAttach ( _                                  ' VTable offset = 24
     BYVAL prddpParent AS IDebugApplicationNode _       ' __in IDebugApplicationNode *prddpParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugApplicationNodeEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = AsyncIDebugApplicationNodeEvents
' IID = a2e3aa3b-aa8d-4ebf-84cd-648b737b8c13
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%AsyncIDebugApplicationNodeEvents_INTERFACE_DEFINED)
    %AsyncIDebugApplicationNodeEvents_INTERFACE_DEFINED = 1

$IID_AsyncIDebugApplicationNodeEvents = GUID$("{a2e3aa3b-aa8d-4ebf-84cd-648b737b8c13}")

INTERFACE AsyncIDebugApplicationNodeEvents $IID_AsyncIDebugApplicationNodeEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Begin_onAddChild ( _                          ' VTable offset = 12
     BYVAL prddpChild AS IDebugApplicationNode _        ' __in IDebugApplicationNode *prddpChild
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_onAddChild ( _                         ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Begin_onRemoveChild ( _                       ' VTable offset = 20
     BYVAL prddpChild AS IDebugApplicationNode _        ' __in IDebugApplicationNode *prddpChild
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_onRemoveChild ( _                      ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Begin_onDetach ( _                            ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_onDetach ( _                           ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Begin_onAttach ( _                            ' VTable offset = 36
     BYVAL prddpParent AS IDebugApplicationNode _       ' __in IDebugApplicationNode *prddpParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_onAttach ( _                           ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __AsyncIDebugApplicationNodeEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugThreadCall32
' IID = 51973C36-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebugThreadCall32_INTERFACE_DEFINED)
    %IDebugThreadCall32_INTERFACE_DEFINED = 1

$IID_IDebugThreadCall32 = GUID$("{51973C36-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugThreadCall32 $IID_IDebugThreadCall32

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ThreadCallHandler ( _                         ' VTable offset = 12
     BYVAL dwParam1 AS DWORD _                          ' __in DWORD dwParam1
   , BYVAL dwParam2 AS DWORD _                          ' __in DWORD dwParam2
   , BYVAL dwParam3 AS DWORD _                          ' __in DWORD dwParam3
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugThreadCall32_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugThreadCall64
' IID = cb3fa335-e979-42fd-9fcf-a7546a0f3905
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebugThreadCall64_INTERFACE_DEFINED)
    %IDebugThreadCall64_INTERFACE_DEFINED = 1

$IID_IDebugThreadCall64 = GUID$("{cb3fa335-e979-42fd-9fcf-a7546a0f3905}")

INTERFACE IDebugThreadCall64 $IID_IDebugThreadCall64

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ThreadCallHandler ( _                         ' VTable offset = 12
     BYVAL dwParam1 AS QUAD _                           ' __in DWORDLONG dwParam1
   , BYVAL dwParam2 AS QUAD _                           ' __in DWORDLONG dwParam2
   , BYVAL dwParam3 AS QUAD _                           ' __in DWORDLONG dwParam3
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugThreadCall64_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRemoteDebugApplicationThread
' IID = 51973C37-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRemoteDebugApplicationThread_INTERFACE_DEFINED)
    %IRemoteDebugApplicationThread_INTERFACE_DEFINED = 1

$IID_IRemoteDebugApplicationThread = GUID$("{51973C37-CB0C-11d0-B5C9-00A0244A0E7A}")

'typedef DWORD THREAD_STATE;
MACRO THREAD_STATE = DWORD

%THREAD_STATE_RUNNING   = &H1???
%THREAD_STATE_SUSPENDED = &H2???
%THREAD_BLOCKED         = &H4???
%THREAD_OUT_OF_CONTEXT  = &H8???

INTERFACE IRemoteDebugApplicationThread $IID_IRemoteDebugApplicationThread

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSystemThreadId ( _                         ' VTable offset = 12
     BYREF dwThreadId AS DWORD _                        ' __out DWORD *dwThreadId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetApplication ( _                            ' VTable offset = 16
     BYREF pprda AS IRemoteDebugApplication _           ' __out IRemoteDebugApplication **pprda
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumStackFrames ( _                           ' VTable offset = 20
     BYREF ppedsf AS IEnumDebugStackFrames _            ' __out IEnumDebugStackFrames **ppedsf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescription ( _                            ' VTable offset = 24
     BYREF pbstrDescription AS WSTRING _                ' __out BSTR *pbstrDescription
   , BYREF pbstrState AS WSTRING _                      ' __out BSTR *pbstrState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNextStatement ( _                          ' VTable offset = 28
     BYVAL pStackFrame AS IDebugStackFrame _            ' __in IDebugStackFrame *pStackFrame
   , BYVAL pCodeContext AS IDebugCodeContext _          ' __in IDebugCodeContext *pCodeContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 32
     BYREF pState AS DWORD _                            ' __out DWORD *pState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Suspend ( _                                   ' VTable offset = 36
     BYREF pdwCount AS DWORD _                          ' __out DWORD *pdwCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Resume ( _                                    ' VTable offset = 40
     BYREF pdwCount AS DWORD _                          ' __out DWORD *pdwCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSuspendCount ( _                           ' VTable offset = 44
     BYREF pdwCount AS DWORD _                          ' __out DWORD *pdwCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRemoteDebugApplicationThread_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugApplicationThread
' IID = 51973C38-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IRemoteDebugApplicationThread
' ########################################################################################

#IF NOT %DEF(%IDebugApplicationThread_INTERFACE_DEFINED)
    %IDebugApplicationThread_INTERFACE_DEFINED = 1

$IID_IDebugApplicationThread = GUID$("{51973C38-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugApplicationThread $IID_IDebugApplicationThread

   INHERIT IUnknown

   ' =====================================================================================
   ' IRemoteDebugApplicationThread methods
   ' =====================================================================================
   METHOD GetSystemThreadId ( _                         ' VTable offset = 12
     BYREF dwThreadId AS DWORD _                        ' __out DWORD *dwThreadId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetApplication ( _                            ' VTable offset = 16
     BYREF pprda AS IRemoteDebugApplication _           ' __out IRemoteDebugApplication **pprda
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumStackFrames ( _                           ' VTable offset = 20
     BYREF ppedsf AS IEnumDebugStackFrames _            ' __out IEnumDebugStackFrames **ppedsf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescription ( _                            ' VTable offset = 24
     BYREF pbstrDescription AS WSTRING _                ' __out BSTR *pbstrDescription
   , BYREF pbstrState AS WSTRING _                      ' __out BSTR *pbstrState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNextStatement ( _                          ' VTable offset = 28
     BYVAL pStackFrame AS IDebugStackFrame _            ' __in IDebugStackFrame *pStackFrame
   , BYVAL pCodeContext AS IDebugCodeContext _          ' __in IDebugCodeContext *pCodeContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 32
     BYREF pState AS DWORD _                            ' __out DWORD *pState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Suspend ( _                                   ' VTable offset = 36
     BYREF pdwCount AS DWORD _                          ' __out DWORD *pdwCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Resume ( _                                    ' VTable offset = 40
     BYREF pdwCount AS DWORD _                          ' __out DWORD *pdwCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSuspendCount ( _                           ' VTable offset = 44
     BYREF pdwCount AS DWORD _                          ' __out DWORD *pdwCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDebugApplicationThread methods
   ' =====================================================================================
   METHOD SynchronousCallIntoThread32 ( _               ' VTable offset = 52
     BYVAL pstcb AS IDebugThreadCall32 _                ' __in IDebugThreadCall32 *pstcb
   , BYVAL dwParam1 AS DWORD _                          ' __in DWORD dwParam1
   , BYVAL dwParam2 AS DWORD _                          ' __in DWORD dwParam2
   , BYVAL dwParam1 AS DWORD _                          ' __in DWORD dwParam3
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryIsCurrentThread ( _                      ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryIsDebuggerThread ( _                     ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDescription ( _                            ' VTable offset = 64
     BYREF pstrDescription AS WSTRINGZ _                ' __in LPCOLESTR pstrDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStateString ( _                            ' VTable offset = 68
     BYREF pstrState AS WSTRINGZ _                      ' __in LPCOLESTR pstrState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugApplicationThread_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugApplicationThread64
' IID = 9dac5886-dbad-456d-9dee-5dec39ab3dda
' Inherited interface = IDebugApplicationThread
' ########################################################################################

#IF NOT %DEF(%IDebugApplicationThread64_INTERFACE_DEFINED)
    %IDebugApplicationThread64_INTERFACE_DEFINED = 1

$IID_IDebugApplicationThread64 = GUID$("{9dac5886-dbad-456d-9dee-5dec39ab3dda}")

INTERFACE IDebugApplicationThread64 $IID_IDebugApplicationThread64

   INHERIT IUnknown

   ' =====================================================================================
   ' IRemoteDebugApplicationThread methods
   ' =====================================================================================
   METHOD GetSystemThreadId ( _                         ' VTable offset = 12
     BYREF dwThreadId AS DWORD _                        ' __out DWORD *dwThreadId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetApplication ( _                            ' VTable offset = 16
     BYREF pprda AS IRemoteDebugApplication _           ' __out IRemoteDebugApplication **pprda
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumStackFrames ( _                           ' VTable offset = 20
     BYREF ppedsf AS IEnumDebugStackFrames _            ' __out IEnumDebugStackFrames **ppedsf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescription ( _                            ' VTable offset = 24
     BYREF pbstrDescription AS WSTRING _                ' __out BSTR *pbstrDescription
   , BYREF pbstrState AS WSTRING _                      ' __out BSTR *pbstrState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNextStatement ( _                          ' VTable offset = 28
     BYVAL pStackFrame AS IDebugStackFrame _            ' __in IDebugStackFrame *pStackFrame
   , BYVAL pCodeContext AS IDebugCodeContext _          ' __in IDebugCodeContext *pCodeContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 32
     BYREF pState AS DWORD _                            ' __out DWORD *pState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Suspend ( _                                   ' VTable offset = 36
     BYREF pdwCount AS DWORD _                          ' __out DWORD *pdwCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Resume ( _                                    ' VTable offset = 40
     BYREF pdwCount AS DWORD _                          ' __out DWORD *pdwCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSuspendCount ( _                           ' VTable offset = 44
     BYREF pdwCount AS DWORD _                          ' __out DWORD *pdwCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDebugApplicationThread methods
   ' =====================================================================================
   METHOD SynchronousCallIntoThread32 ( _               ' VTable offset = 52
     BYVAL pstcb AS IDebugThreadCall32 _                ' __in IDebugThreadCall32 *pstcb
   , BYVAL dwParam1 AS DWORD _                          ' __in DWORD dwParam1
   , BYVAL dwParam2 AS DWORD _                          ' __in DWORD dwParam2
   , BYVAL dwParam1 AS DWORD _                          ' __in DWORD dwParam3
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryIsCurrentThread ( _                      ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryIsDebuggerThread ( _                     ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDescription ( _                            ' VTable offset = 64
     BYREF pstrDescription AS WSTRINGZ _                ' __in LPCOLESTR pstrDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStateString ( _                            ' VTable offset = 68
     BYREF pstrState AS WSTRINGZ _                      ' __in LPCOLESTR pstrState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDebugApplicationThread64 methods
   ' =====================================================================================
   METHOD SynchronousCallIntoThread64 ( _               ' VTable offset = 72
     BYVAL pstcb AS IDebugThreadCall64 _                ' __in IDebugThreadCall64 *pstcb
   , BYVAL dwParam1 AS QUAD _                           ' __in DWORDLONG dwParam1
   , BYVAL dwParam2 AS QUAD _                           ' __in DWORDLONG dwParam2
   , BYVAL dwParam3 AS QUAD _                           ' __in DWORDLONG dwParam3
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugApplicationThread64_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugCookie
' IID = 51973C39-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebugCookie_INTERFACE_DEFINED)
    %IDebugCookie_INTERFACE_DEFINED = 1

$IID_IDebugCookie = GUID$("{51973C39-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugCookie $IID_IDebugCookie

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetDebugCookie ( _                            ' VTable offset = 12
     BYVAL dwDebugAppCookie AS DWORD _                  ' __in DWORD dwDebugAppCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugCookie_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumDebugApplicationNodes
' IID = 51973C3a-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumDebugApplicationNodes_INTERFACE_DEFINED)
    %IEnumDebugApplicationNodes_INTERFACE_DEFINED = 1

$IID_IEnumDebugApplicationNodes = GUID$("{51973C3a-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IEnumDebugApplicationNodes $IID_IEnumDebugApplicationNodes

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF pprddp AS IDebugApplicationNode _            ' __out IDebugApplicationNode **pprddp
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 24
     BYREF pperddp AS IEnumDebugApplicationNodes _      ' __out IEnumDebugApplicationNodes **pperddp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumDebugApplicationNodes_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumRemoteDebugApplications
' IID = 51973C3b-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumRemoteDebugApplications_INTERFACE_DEFINED)
    %IEnumRemoteDebugApplications_INTERFACE_DEFINED = 1

$IID_IEnumRemoteDebugApplications = GUID$("{51973C3b-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IEnumRemoteDebugApplications $IID_IEnumRemoteDebugApplications

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppda AS IRemoteDebugApplication _            ' __out IRemoteDebugApplication **ppda
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 24
     BYREF ppessd AS IEnumRemoteDebugApplications _     ' __out IEnumRemoteDebugApplications **ppessd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumRemoteDebugApplications_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumRemoteDebugApplicationThreads
' IID = 51973C3c-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumRemoteDebugApplicationThreads_INTERFACE_DEFINED)
    %IEnumRemoteDebugApplicationThreads_INTERFACE_DEFINED = 1

$IID_IEnumRemoteDebugApplicationThreads = GUID$("{51973C3c-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IEnumRemoteDebugApplicationThreads $IID_IEnumRemoteDebugApplicationThreads

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF pprdat AS IRemoteDebugApplicationThread _    ' __out IRemoteDebugApplicationThread **pprdat
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 24
     BYREF pperdat AS IEnumRemoteDebugApplicationThreads _ ' __out IEnumRemoteDebugApplicationThreads **pperdat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumRemoteDebugApplicationThreads_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugFormatter
' IID = 51973C05-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebugFormatter_INTERFACE_DEFINED)
    %IDebugFormatter_INTERFACE_DEFINED = 1

$IID_IDebugFormatter = GUID$("{51973C05-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugFormatter $IID_IDebugFormatter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetStringForVariant ( _                       ' VTable offset = 12
     BYREF pvar AS VARIANT _                            ' __in VARIANT *pvar
   , BYVAL nRadix AS DWORD _                            ' __in ULONG nRadix
   , BYREF pbstrValue AS WSTRING _                      ' __out BSTR *pbstrValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVariantForString ( _                       ' VTable offset = 16
     BYREF pwstrValue AS WSTRINGZ _                     ' __in LPCOLESTR pwstrValue
   , BYREF pvar AS VARIANT _                            ' __out VARIANT *pvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringForVarType ( _                       ' VTable offset = 20
     BYVAL vt AS WORD _                                 ' __in VARTYPE vt
   , BYREF ptdescArrayType AS TYPEDESC _                ' __in TYPEDESC *ptdescArrayType
   , BYREF pbstr AS WSTRING _                           ' __out BSTR *pbstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugFormatter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISimpleConnectionPoint
' IID = 51973C3e-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISimpleConnectionPoint_INTERFACE_DEFINED)
    %ISimpleConnectionPoint_INTERFACE_DEFINED = 1

$IID_ISimpleConnectionPoint = GUID$("{51973C3e-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE ISimpleConnectionPoint $IID_ISimpleConnectionPoint

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetEventCount ( _                             ' VTable offset = 12
     BYREF pulCount AS DWORD _                          ' __out ULONG *pulCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DescribeEvents ( _                            ' VTable offset = 16
     BYVAL iEvent AS DWORD _                            ' __in ULONG iEvent
   , BYVAL cEvents AS DWORD _                           ' __in ULONG cEvents
   , BYREF prgid AS LONG _                              ' __out DISPID *prgid
   , BYREF prgbstr AS WSTRING _                         ' __out BSTR *prgbstr
   , BYREF pcEventsFetched AS DWORD _                   ' __out ULONG *pcEventsFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 20
     BYVAL pdisp AS IDispatch _                         ' __in IDispatch *pdisp
   , BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 24
     BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISimpleConnectionPoint_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebugHelper
' IID = 51973C3f-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebugHelper_INTERFACE_DEFINED)
    %IDebugHelper_INTERFACE_DEFINED = 1

$IID_IDebugHelper = GUID$("{51973C3f-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IDebugHelper $IID_IDebugHelper

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreatePropertyBrowser ( _                     ' VTable offset = 12
     BYREF pvar AS VARIANT _                            ' __in VARIANT *pvar
   , BYREF bstrName AS WSTRINGZ _                       ' __in LPCOLESTR bstrName
   , BYVAL pdat AS IDebugApplicationThread _            ' __in IDebugApplicationThread *pdat
   , BYREF ppdob AS IDebugProperty _                    ' __out IDebugProperty **ppdob
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePropertyBrowserEx ( _                   ' VTable offset = 16
     BYREF pvar AS VARIANT _                            ' __in VARIANT *pvar
   , BYREF bstrName AS WSTRINGZ _                       ' __in LPCOLESTR bstrName
   , BYVAL pdat AS IDebugApplicationThread _            ' __in IDebugApplicationThread *pdat
   , BYVAL pdf AS IDebugFormatter _                     ' __in IDebugFormatter *pdf
   , BYREF ppdob AS IDebugProperty _                    ' __out IDebugProperty **ppdob
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSimpleConnectionPoint ( _               ' VTable offset = 20
     BYVAL psidp AS IDispatch _                         ' __in IDispatch *pdisp
   , BYREF ppscp AS ISimpleConnectionPoint _            ' __out ISimpleConnectionPoint **ppscp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebugHelper_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumDebugExpressionContexts
' IID = 51973C40-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumDebugExpressionContexts_INTERFACE_DEFINED)
    %IEnumDebugExpressionContexts_INTERFACE_DEFINED = 1

$IID_IEnumDebugExpressionContexts = GUID$("{51973C40-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IEnumDebugExpressionContexts $IID_IEnumDebugExpressionContexts

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppdec AS IDebugExpressionContext _           ' __out IDebugExpressionContext **ppdec
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 24
     BYREF ppedec AS IEnumDebugExpressionContexts _     ' __out IEnumDebugExpressionContexts **ppedec
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumDebugExpressionContexts_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IProvideExpressionContexts
' IID = 51973C41-CB0C-11d0-B5C9-00A0244A0E7A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IProvideExpressionContexts_INTERFACE_DEFINED)
    %IProvideExpressionContexts_INTERFACE_DEFINED = 1

$IID_IProvideExpressionContexts = GUID$("{51973C41-CB0C-11d0-B5C9-00A0244A0E7A}")

INTERFACE IProvideExpressionContexts $IID_IProvideExpressionContexts

   INHERIT IUnknown

   ' =====================================================================================
   METHOD EnumExpressionContexts ( _                    ' VTable offset = 12
     BYREF ppedec AS IEnumDebugExpressionContexts _     ' __out IEnumDebugExpressionContexts **ppedec
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProvideExpressionContexts_INTERFACE_DEFINED__ */


' ########################################################################################
' Class CIDebugDocumentTextEvents
' Interface name = IDebugDocumentTextEvents
' IID = {51973C23-CB0C-11D0-B5C9-00A0244A0E7A}
' ########################################################################################

'CLASS CIDebugDocumentTextEvents GUID$("{9AEC207B-8926-4A1C-9A3B-6F469953BD4D}")

'INTERFACE IDebugDocumentTextEventsImpl GUID$("{51973C23-CB0C-11D0-B5C9-00A0244A0E7A}")

'  INHERIT IUnknown

'   ' =====================================================================================
'   METHOD onDestroy () AS LONG

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD onInsertText ( _
'     BYVAL cCharacterPosition AS DWORD _                ' [in] cCharacterPosition VT_UI4 <Dword>
'   , BYVAL cNumToInsert AS DWORD _                      ' [in] cNumToInsert VT_UI4 <Dword>
'   ) AS LONG                                            ' HRESULT

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD onRemoveText ( _
'     BYVAL cCharacterPosition AS DWORD _                ' [in] cCharacterPosition VT_UI4 <Dword>
'   , BYVAL cNumToRemove AS DWORD _                      ' [in] cNumToRemove VT_UI4 <Dword>
'   ) AS LONG                                            ' HRESULT

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD onReplaceText ( _
'     BYVAL cCharacterPosition AS DWORD _                ' [in] cCharacterPosition VT_UI4 <Dword>
'   , BYVAL cNumToReplace AS DWORD _                     ' [in] cNumToReplace VT_UI4 <Dword>
'   ) AS LONG                                            ' HRESULT

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD onUpdateTextAttributes ( _
'     BYVAL cCharacterPosition AS DWORD _                ' [in] cCharacterPosition VT_UI4 <Dword>
'   , BYVAL cNumToUpdate AS DWORD _                      ' [in] cNumToUpdate VT_UI4 <Dword>
'   ) AS LONG                                            ' HRESULT

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD onUpdateDocumentAttributes ( _
'     BYVAL textdocattr AS DWORD _                       ' [in] textdocattr VT_UI4 <Dword>
'   ) AS LONG                                            ' HRESULT

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS
