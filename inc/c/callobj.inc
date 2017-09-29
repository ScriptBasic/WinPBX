' ########################################################################################
' Microsoft Windows
' File: callobj.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CALLOBJ_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"

#IF NOT %DEF(%ICallFrame_INTERFACE_DEFINED)
    %ICallFrame_INTERFACE_DEFINED = 1

' // Size = 60 bytes
TYPE CALLFRAMEINFO DWORD
   iMethod               AS DWORD   ' ULONG iMethod
   fHasInValues          AS LONG    ' BOOL  fHasInValues
   fHasInOutValues       AS LONG    ' BOOL  fHasInOutValues
   fHasOutValues         AS LONG    ' BOOL  fHasOutValues
   fDerivesFromIDispatch AS LONG    ' BOOL  fDerivesFromIDispatch
   cInInterfacesMax      AS LONG    ' LONG  cInInterfacesMax
   cInOutInterfacesMax   AS LONG    ' LONG  cInOutInterfacesMax
   cOutInterfacesMax     AS LONG    ' LONG  cOutInterfacesMax
   cTopLevelInInterfaces AS LONG    ' LONG  cTopLevelInInterfaces
   iid                   AS GUID    ' IID   iid
   cMethod               AS DWORD   ' ULONG cMethod
   cParams               AS DWORD   ' ULONG cParams
END TYPE

' // Size = 12 bytes
TYPE CALLFRAMEPARAMINFO WORD
   fIn         AS BYTE    ' BOOLEAN fIn
   fOut        AS BYTE    ' BOOLEAN fOut
   stackOffset AS DWORD   ' ULONG   stackOffset
   cbParam     AS DWORD   ' ULONG   cbParam
END TYPE


MACRO CALLFRAME_COPY_ENUM = LONG
' CALLFRAME_COPY enum
%CALLFRAME_COPY_NESTED      = 1
%CALLFRAME_COPY_INDEPENDENT = 2

MACRO CALLFRAME_FREE_ENUM = LONG
' CALLFRAME_FREE enum
%CALLFRAME_FREE_NONE      = 0
%CALLFRAME_FREE_IN        = 1
%CALLFRAME_FREE_INOUT     = 2
%CALLFRAME_FREE_OUT       = 4
%CALLFRAME_FREE_TOP_INOUT = 8
%CALLFRAME_FREE_TOP_OUT   = 16
%CALLFRAME_FREE_ALL       = 31

MACRO CALLFRAME_NULL_ENUM = LONG
' CALLFRAME_NULL enum
%CALLFRAME_NULL_NONE  = 0
%CALLFRAME_NULL_INOUT = 2
%CALLFRAME_NULL_OUT   = 4
%CALLFRAME_NULL_ALL   = 6

MACRO CALLFRAME_WALK_ENUM = LONG
' CALLFRAME_WALK enum
%CALLFRAME_WALK_IN    = 1
%CALLFRAME_WALK_INOUT = 2
%CALLFRAME_WALK_OUT   = 4

' // Size = 32 bytes
TYPE CALLFRAME_MARSHALCONTEXT DWORD
   fIn                AS BYTE    ' BOOLEAN fIn
   dwDestContext      AS DWORD   ' DWORD dwDestContext
   pvDestContext      AS DWORD   ' LPVOID pvDestContext
   mshlmgr            AS DWORD   ' IUnknown *punkReserved
   guidTransferSyntax AS GUID    ' GUID guidTransferSyntax
END TYPE


' ########################################################################################
' ICallFrame interface
' IID = D573B4B0-894E-11D2-B8B6-00C04FB9618A
' Inherited interface = IUnknown
' ########################################################################################

$IID_ICallFrame = GUID$("{D573B4B0-894E-11D2-B8B6-00C04FB9618A}")

INTERFACE ICallFrame $IID_ICallFrame

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetInfo ( _                                   ' VTable offset = 12
     BYREF pInfo AS CALLFRAMEINFO _                     ' __out CALLFRAMEINFO *pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIIDAndMethod ( _                           ' VTable offset = 16
     BYREF pIID AS GUID _                               ' __out IID *pIID
   , BYREF piMethod AS DWORD _                          ' __out ULONG *piMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNames ( _                                  ' VTable offset = 20
     BYREF pwszInterface AS DWORD _                     ' __out LPWSTR *pwszInterface
   , BYREF pwszMethod AS DWORD _                        ' __out LPWSTR *pwszMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStackLocation ( _                          ' VTable offset = 24
   ) AS DWORD                                           ' PVOID
   ' =====================================================================================
   METHOD SetStackLocation ( _                          ' VTable offset = 28
     BYVAL pvStack AS DWORD _                           ' __in PVOID pvStack
   )                                                    ' void
   ' =====================================================================================
   METHOD SetReturnValue ( _                            ' VTable offset = 32
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
     )                                                  ' void
   ' =====================================================================================
   METHOD GetReturnValue ( _                            ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParamInfo ( _                              ' VTable offset = 40
     BYVAL iparam AS DWORD _                            ' __in ULONG iparam
   , BYREF pInfo AS CALLFRAMEPARAMINFO _                ' __out CALLFRAMEPARAMINFO *pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetParam ( _                                  ' VTable offset = 44
     BYVAL iparam AS DWORD _                            ' __in ULONG iparam
   , BYREF pvar AS VARIANT _                            ' __in VARIANT *pvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParam ( _                                  ' VTable offset = 48
     BYVAL iparam AS DWORD _                            ' __in ULONG iparam
   , BYREF pvar AS VARIANT _                            ' __out VARIANT *pvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Copy ( _                                      ' VTable offset = 52
     BYVAL copyControl AS CALLFRAME_COPY_ENUM _         ' __in CALLFRAME_COPY copyControl
   , BYVAL pWalker AS ICallFrameWalker _                ' __in ICallFrameWalker *pWalker
   , BYREF ppFrame AS ICallFrame _                      ' __out ICallFrame **ppFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Free ( _                                      ' VTable offset = 56
     BYVAL pframeArgsDest AS ICallFrame _               ' __in ICallFrame *pframeArgsDest
   , BYVAL pWalkerDestFree AS ICallFrameWalker _        ' __in ICallFrameWalker *pWalkerDestFree
   , BYVAL pWalkerCopy AS ICallFrameWalker _            ' __in ICallFrameWalker *pWalkerCopy
   , BYVAL freeFlags AS DWORD _                         ' __in DWORD freeFlags
   , BYVAL pWalkerFree AS ICallFrameWalker _            ' __in ICallFrameWalker *pWalkerFree
   , BYVAL nullFlags AS DWORD _                         ' __in DWORD nullFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeParam ( _                                 ' VTable offset = 60
     BYVAL iparam AS DWORD _                            ' __in ULONG iparam
   , BYVAL freeFlags AS DWORD _                         ' __in DWORD freeFlags
   , BYVAL pWalkerFree AS ICallFrameWalker _            ' __in ICallFrameWalker *pWalkerFree
   , BYVAL nullFlags AS DWORD _                         ' __in DWORD nullFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WalkFrame ( _                                 ' VTable offset = 64
     BYVAL walkWhat AS DWORD _                          ' __in DWORD walkWhat
   , BYVAL pWalker AS ICallFrameWalker _                ' __in ICallFrameWalker *pWalker
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMarshalSizeMax ( _                         ' VTable offset = 68
     BYREF pmshlContext AS CALLFRAME_MARSHALCONTEXT _   ' __in CALLFRAME_MARSHALCONTEXT *pmshlContext
   , BYVAL mshlflags AS DWORD _                         ' __in MSHLFLAGS mshlflags
   , BYREF pcbBufferNeeded AS DWORD _                   ' __out ULONG *pcbBufferNeeded
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Marshal ( _                                   ' VTable offset = 72
     BYREF pmshlContext AS CALLFRAME_MARSHALCONTEXT _   ' __in CALLFRAME_MARSHALCONTEXT *pmshlContext
   , BYVAL mshlflags AS DWORD _                         ' __in MSHLFLAGS mshlflags
   , BYVAL pBuffer AS DWORD _                           ' __in PVOID pBuffer
   , BYVAL cbBuffer AS DWORD _                          ' __in ULONG cbBuffer
   , BYREF pcbBufferUsed AS DWORD _                     ' __out ULONG *pcbBufferUsed
   , BYREF pdataRep AS DWORD _                          ' __out RPCOLEDATAREP *pdataRep
   , BYREF prpcFlags AS DWORD _                         ' __out ULONG *prpcFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unmarshal ( _                                 ' VTable offset = 76
     BYVAL pBuffer AS DWORD _                           ' __in PVOID pBuffer
   , BYVAL cbBuffer AS DWORD _                          ' __in ULONG cbBuffer
   , BYVAL dataRep AS DWORD _                           ' __in RPCOLEDATAREP dataRep
   , BYREF pcontext AS CALLFRAME_MARSHALCONTEXT _       ' __in CALLFRAME_MARSHALCONTEXT *pcontext
   , BYREF pcbUnmarshalled AS DWORD _                   ' __out ULONG *pcbUnmarshalled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseMarshalData ( _                        ' VTable offset = 80
     BYVAL pBuffer AS DWORD _                           ' __in PVOID pBuffer
   , BYVAL cbBuffer AS DWORD _                          ' __in ULONG cbBuffer
   , BYVAL ibFirstRelease AS DWORD _                    ' __in ULONG ibFirstRelease
   , BYVAL dataRep AS DWORD _                           ' __in RPCOLEDATAREP dataRep
   , BYREF pcontext AS CALLFRAME_MARSHALCONTEXT _       ' __in CALLFRAME_MARSHALCONTEXT *pcontext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Invoke ( _                                    ' VTable offset = 84
     BYVAL pvReceiver AS DWORD _                        ' __in void *pvReceiver
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICallFrame_INTERFACE_DEFINED__ */


' ########################################################################################
' ICallIndirect interface
' IID = D573B4B1-894E-11D2-B8B6-00C04FB9618A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICallIndirect_INTERFACE_DEFINED)
    %ICallIndirect_INTERFACE_DEFINED = 1

$IID_ICallIndirect = GUID$("{D573B4B1-894E-11D2-B8B6-00C04FB9618A}")

INTERFACE ICallIndirect $IID_ICallIndirect

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CallIndirect ( _                              ' VTable offset = 12
     BYREF phrReturn AS LONG _                          ' __out HRESULT *phrReturn
   , BYVAL iMethod AS DWORD _                           ' __in ULONG iMethod
   , BYVAL pvArgs AS DWORD _                            ' __in void *pvArgs
   , BYREF cbArgs AS DWORD _                            ' __out ULONG *cbArgs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMethodInfo ( _                             ' VTable offset = 16
     BYVAL iMethod AS DWORD _                           ' __in ULONG iMethod
   , BYREF pInfo AS CALLFRAMEINFO _                     ' __out CALLFRAMEINFO *pInfo
   , BYREF pwszMethod AS DWORD _                        ' __out LPWSTR *pwszMethod)
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStackSize ( _                              ' VTable offset = 20
     BYVAL iMethod AS DWORD _                           ' __in ULONG iMethod
   , BYREF cbArgs AS DWORD _                            ' __out ULONG *cbArgs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIID ( _                                    ' VTable offset = 24
     BYREF piid AS GUID _                               ' __out IID *piid
   , BYREF pfDerivesFromIDispatch AS LONG _             ' __out BOOL *pfDerivesFromIDispatch
   , BYREF pcMethod AS DWORD _                          ' __out ULONG *pcMethod
   , BYREF pwszInterface AS DWORD _                     ' __out LPWSTR *pwszInterface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICallIndirect_INTERFACE_DEFINED__ */


' ########################################################################################
' ICallInterceptor interface
' IID = 60C7CA75-896D-11Dd2-B8B6-00C04FB9618A
' Inherited interface = ICallIndirect
' ########################################################################################

#IF NOT %DEF(%ICallInterceptor_INTERFACE_DEFINED)
    %ICallInterceptor_INTERFACE_DEFINED = 1

$IID_ICallInterceptor = GUID$("{60C7CA75-896D-11D2-B8B6-00C04FB9618A}")

INTERFACE ICallInterceptor $IID_ICallInterceptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CallIndirect ( _                              ' VTable offset = 12
     BYREF phrReturn AS LONG _                          ' __out HRESULT *phrReturn
   , BYVAL iMethod AS DWORD _                           ' __in ULONG iMethod
   , BYVAL pvArgs AS DWORD _                            ' __in void *pvArgs
   , BYREF cbArgs AS DWORD _                            ' __out ULONG *cbArgs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMethodInfo ( _                             ' VTable offset = 16
     BYVAL iMethod AS DWORD _                           ' __in ULONG iMethod
   , BYREF pInfo AS CALLFRAMEINFO _                     ' __out CALLFRAMEINFO *pInfo
   , BYREF pwszMethod AS DWORD _                        ' __out LPWSTR *pwszMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStackSize ( _                              ' VTable offset = 20
     BYVAL iMethod AS DWORD _                           ' __in ULONG iMethod
   , BYREF cbArgs AS DWORD _                            ' __out ULONG *cbArgs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIID ( _                                    ' VTable offset = 24
     BYREF piid AS GUID _                               ' __out IID *piid
   , BYREF pfDerivesFromIDispatch AS LONG _             ' __out BOOL *pfDerivesFromIDispatch
   , BYREF pcMethod AS DWORD _                          ' __out ULONG *pcMethod
   , BYREF pwszInterface AS DWORD _                     ' __out LPWSTR *pwszInterface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterSink ( _                              ' VTable offset = 28
     BYVAL psink AS ICallFrameEvents _                  ' __in ICallFrameEvents *psink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRegisteredSink ( _                         ' VTable offset = 32
     BYREF ppsink AS ICallFrameEvents _                 ' __out ICallFrameEvents **ppsink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICallInterceptor_INTERFACE_DEFINED__ */


' ########################################################################################
' ICallFrameEvents interface
' IID = FD5E0843-FC91-11d0-97D7-00C04FB9618A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICallFrameEvents_INTERFACE_DEFINED)
    %ICallFrameEvents_INTERFACE_DEFINED = 1

$IID_ICallFrameEvents = GUID$("{FD5E0843-FC91-11D0-97D7-00C04FB9618A}")

INTERFACE ICallFrameEvents $IID_ICallFrameEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnCall ( _                                    ' VTable offset = 12
     BYVAL pFrame AS ICallFrame _                       ' __in ICallFrame *pFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICallFrameEvents_INTERFACE_DEFINED__ */


' ########################################################################################
' ICallUnmarshal interface
' IID = 5333B003-2E42-11D2-B89D-00C04FB9618A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICallUnmarshal_INTERFACE_DEFINED)
    %ICallUnmarshal_INTERFACE_DEFINED = 1

$IID_ICallUnmarshal = GUID$("{5333B003-2E42-11D2-B89D-00C04FB9618A}")

INTERFACE ICallUnmarshal $IID_ICallUnmarshal

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Unmarshal ( _                                 ' VTable offset = 12
     BYVAL iMethod AS DWORD _                           ' __in ULONG iMethod
   , BYVAL pBuffer AS DWORD _                           ' __in PVOID pBuffer
   , BYVAL cbBuffer AS DWORD _                          ' __in ULONG cbBuffer
   , BYVAL fForceBufferCopy AS LONG _                   ' __in BOOL fForceBufferCopy
   , BYVAL dataRep AS DWORD _                           ' __in RPCOLEDATAREP dataRep
   , BYREF pcontext AS CALLFRAME_MARSHALCONTEXT _       ' __in CALLFRAME_MARSHALCONTEXT *pcontext
   , BYREF pcbUnmarshalled AS DWORD _                   ' __out ULONG *pcbUnmarshalled
   , BYREF ppFrame AS ICallFrame _                      ' __out ICallFrame **ppFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseMarshalData ( _                        ' VTable offset = 16
     BYVAL iMethod AS DWORD _                           ' __in ULONG iMethod
   , BYVAL pBuffer AS DWORD _                           ' __in PVOID pBuffer
   , BYVAL cbBuffer AS DWORD _                          ' __in ULONG cbBuffer
   , BYVAL ibFirstRelease AS DWORD _                    ' __in ULONG ibFirstRelease
   , BYVAL dataRep AS DWORD _                           ' __in RPCOLEDATAREP dataRep
   , BYREF pcontext AS CALLFRAME_MARSHALCONTEXT _       ' __in CALLFRAME_MARSHALCONTEXT *pcontext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICallUnmarshal_INTERFACE_DEFINED__ */


' ########################################################################################
' ICallFrameWalker interface
' IID = 08B23919-392D-11d2-B8A4-00C04FB9618A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICallFrameWalker_INTERFACE_DEFINED)
    %ICallFrameWalker_INTERFACE_DEFINED = 1

$IID_ICallFrameWalker = GUID$("{08B23919-392D-11D2-B8A4-00C04FB9618A}")

INTERFACE ICallFrameWalker $IID_ICallFrameWalker

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnWalkInterface ( _                           ' VTable offset = 12
     BYREF iid AS GUID _                                ' __in REFIID iid
   , BYVAL ppvInterface AS DWORD _                      ' __in PVOID *ppvInterface
   , BYVAL fIn AS LONG _                                ' __in BOOL fIn
   , BYVAL fOut AS LONG _                               ' __in BOOL fOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICallFrameWalker_INTERFACE_DEFINED__ */


' ########################################################################################
' IInterfaceRelated interface
' IID = D1FB5A79-7706-11d1-ADBA-00C04FC2ADC0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInterfaceRelated_INTERFACE_DEFINED)
    %IInterfaceRelated_INTERFACE_DEFINED = 1

$IID_IInterfaceRelated = GUID$("{D1FB5A79-7706-11d1-ADBA-00C04FC2ADC0}")

INTERFACE IInterfaceRelated $IID_IInterfaceRelated

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetIID ( _                                    ' VTable offset = 12
     BYREF iid AS GUID _                                ' __in REFIID iid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIID ( _                                    ' VTable offset = 16
     BYREF piid AS GUID _                               ' __out IID *piid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInterfaceRelated_INTERFACE_DEFINED__ */


'#define CALLFRAME_E_ALREADYINVOKED  _HRESULT_TYPEDEF_(  0x8004d090 )
'#define CALLFRAME_E_COULDNTMAKECALL _HRESULT_TYPEDEF_(  0x8004d091 )
%CALLFRAME_E_ALREADYINVOKED  = &H8004d090
%CALLFRAME_E_COULDNTMAKECALL = &H8004d091

#IF NOT %DEF(%ICallFrameAPIs_INTERFACE_DEFINED)
    %ICallFrameAPIs_INTERFACE_DEFINED = 1

DECLARE FUNCTION CoGetInterceptor IMPORT "OLE32.DLL" ALIAS "CoGetInterceptor" ( _
   BYREF iidIntercepted AS GUID _                       ' __in REFIID iidIntercepted
 , BYVAL punkOuter AS IUnknown _                        ' __in IUnknown *punkOuter
 , BYREF iid AS GUID _                                  ' __in REFIID iid
 , BYREF ppv AS ANY _                                   ' __out void **ppv
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoGetInterceptorFromTypeInfo IMPORT "OLE32.DLL" ALIAS "CoGetInterceptorFromTypeInfo" ( _
   BYREF iidIntercepted AS GUID _                       ' __in REFIID iidIntercepted
 , BYVAL punkOuter AS IUnknown _                        ' __in IUnknown *punkOuter
 , BYVAL typeInfo AS ITypeInfo _                        ' __in ITypeInfo *typeInfo
 , BYREF iid AS GUID _                                  ' __in REFIID iid
 , BYREF ppv AS ANY _                                   ' __out void **ppv
 ) AS LONG                                              ' HRESULT

#ENDIF   ' /* __ICallFrameAPIs_INTERFACE_DEFINED__ */
