' ########################################################################################
' Microsoft Windows
' File: DispEx.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DISEXP_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "ocidl.inc"

'//---------------------------------------------------------------------------=
'// IDispatchEx Interfaces.
'//

#INCLUDE ONCE "servprov.inc"

#IF NOT %DEF(%NO_DISPATCHEX_GUIDS)

$IID_IDispatchEx                 = GUID$("{A6EF9860-C720-11D0-9337-00A0C90DCAA9}")
$IID_IDispError                  = GUID$("{A6EF9861-C720-11D0-9337-00A0C90DCAA9}")
$IID_IVariantChangeType          = GUID$("{A6EF9862-C720-11D0-9337-00A0C90DCAA9}")
$SID_VariantConversion           = GUID$("{1F101481-BCCD-11D0-9336-00A0C90DCAA9}")
$SID_GetCaller                   = GUID$("{4717CC40-BCB9-11D0-9336-00A0C90DCAA9}")
$SID_ProvideRuntimeContext       = GUID$("{74A5040C-DD0C-48f0-AC85-194C3259180A}")
$IID_IProvideRuntimeContext      = GUID$("{10E2414A-EC59-49d2-BC51-5ADD2C36FEBC}")
$IID_IObjectIdentity             = GUID$("{CA04B7E6-0D21-11D1-8CC5-00C04FC2B085}")

'#define SID_GetScriptSite IID_IActiveScriptSite
$SID_GetScriptSite               = GUID$("{DB01A1E3-A42B-11cf-8F20-00805F2CD064}")

#ENDIF   ' // _NO_DISPATCHEX_GUIDS


#IF NOT %DEF(%NO_DISPATCHEX_CONSTS)

'// Input flags for GetDispID
%fdexNameCaseSensitive       = &H00000001???
%fdexNameEnsure              = &H00000002???
%fdexNameImplicit            = &H00000004???
%fdexNameCaseInsensitive     = &H00000008???
%fdexNameInternal            = &H00000010???
%fdexNameNoDynamicProperties = &H00000020???

'// Output flags for GetMemberProperties
%fdexPropCanGet              = &H00000001???
%fdexPropCannotGet           = &H00000002???
%fdexPropCanPut              = &H00000004???
%fdexPropCannotPut           = &H00000008???
%fdexPropCanPutRef           = &H00000010???
%fdexPropCannotPutRef        = &H00000020???
%fdexPropNoSideEffects       = &H00000040???
%fdexPropDynamicType         = &H00000080???
%fdexPropCanCall             = &H00000100???
%fdexPropCannotCall          = &H00000200???
%fdexPropCanConstruct        = &H00000400???
%fdexPropCannotConstruct     = &H00000800???
%fdexPropCanSourceEvents     = &H00001000???
%fdexPropCannotSourceEvents  = &H00002000???

%grfdexPropCanAll = %fdexPropCanGet OR %fdexPropCanPut OR %fdexPropCanPutRef OR _
        %fdexPropCanCall OR %fdexPropCanConstruct OR %fdexPropCanSourceEvents
%grfdexPropCannotAll = %fdexPropCannotGet OR %fdexPropCannotPut OR %fdexPropCannotPutRef OR _
        %fdexPropCannotCall OR %fdexPropCannotConstruct OR %fdexPropCannotSourceEvents
%grfdexPropExtraAll = %fdexPropNoSideEffects OR %fdexPropDynamicType
%grfdexPropAll = %grfdexPropCanAll OR %grfdexPropCannotAll OR %grfdexPropExtraAll

'// Input flags for GetNextDispID
%fdexEnumDefault             = &H00000001???
%fdexEnumAll                 = &H00000002???

'// Additional flags for Invoke - when object member is used as a constructor.
%DISPATCH_CONSTRUCT          = &H4000??

'// Standard DISPIDs
%DISPID_THIS                 = -613
%DISPID_STARTENUM            = %DISPID_UNKNOWN

#ENDIF   ' //_NO_DISPATCHEX_CONSTS


' ########################################################################################
' IDispatchEx interface
' IID = A6EF9860-C720-11D0-9337-00A0C90DCAA9
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDispatchEx_INTERFACE_DEFINED)
    %IDispatchEx_INTERFACE_DEFINED = 1

$IID_IDispatchEx = GUID$("{A6EF9860-C720-11D0-9337-00A0C90DCAA9}")

INTERFACE IDispatchEx $IID_IDispatchEx

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetDispID ( _                                 ' VTable offset = 28
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL grfdex AS DWORD _                            ' __in DWORD grfdex
   , BYREF pid AS LONG _                                ' __out DISPID *pid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InvokeEx ( _                                  ' VTable offset = 32
     BYVAL id AS LONG _                                 ' __in DISPID id
   , BYVAL lcid AS DWORD _                              ' __in LCID lcid
   , BYVAL wFlags AS WORD _                             ' __in WORD wFlags
   , BYREF pdp AS DISPPARAMS _                          ' __in DISPPARAMS *pdp
   , BYREF pvarRes AS VARIANT _                         ' __out VARIANT *pvarRes
   , BYREF pei AS EXCEPINFO _                           ' __out EXCEPINFO *pei
   , BYVAL pspCaller AS IServiceProvider _              ' __in IServiceProvider *pspCaller
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteMemberByName ( _                        ' VTable offset = 36
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL grfdex AS DWORD _                            ' __in DWORD grfdex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteMemberByDispID ( _                      ' VTable offset = 40
     BYVAL id AS LONG _                                 ' __in DISPID id
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMemberProperties ( _                       ' VTable offset = 44
     BYVAL id AS LONG _                                 ' __in DISPID id
   , BYVAL grfdexFetch AS DWORD _                       ' __in DWORD grfdexFetch
   , BYREF pgrfdex AS DWORD _                           ' __out DWORD *pgrfdex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMemberName ( _                             ' VTable offset = 48
     BYVAL id AS LONG _                                 ' __in DISPID id
   , BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextDispID ( _                             ' VTable offset = 52
     BYVAL grfdex AS DWORD _                            ' __in DWORD grfdex
   , BYVAL id AS LONG _                                 ' __in DISPID id
   , BYREF pid AS LONG _                                ' __out DISPID *pid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNameSpaceParent ( _                        ' VTable offset = 56
     BYREF ppunk AS IUnknown _                          ' __out IUnknown **ppunk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDispatchEx_INTERFACE_DEFINED__ */


' ########################################################################################
' IDispError interface
' IID = A6EF9861-C720-11D0-9337-00A0C90DCAA9
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDispError_INTERFACE_DEFINED)
    %IDispError_INTERFACE_DEFINED = 1

$IID_IDispError = GUID$("{A6EF9861-C720-11D0-9337-00A0C90DCAA9}")

INTERFACE IDispError $IID_IDispError

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryErrorInfo ( _                            ' VTable offset = 12
     BYREF guidErrorType AS GUID _                      ' __in GUID guidErrorType
   , BYREF ppde AS IDispError _                         ' __out IDispError **ppde
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNext ( _                                   ' VTable offset = 16
     BYREF ppde AS IDispError _                         ' __out IDispError **ppde
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHresult ( _                                ' VTable offset = 20
     BYREF phr AS LONG _                                ' __out HRESULT *phr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSource ( _                                 ' VTable offset = 24
     BYREF pbstrSource AS WSTRING _                     ' __out BSTR *pbstrSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHelpInfo ( _                               ' VTable offset = 28
     BYREF pbstrSource AS WSTRING _                     ' __out BSTR *pbstrSource
   , BYREF pdwContext AS DWORD _                        ' __out DWORD *pdwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescription ( _                            ' VTable offset = 32
     BYREF pbstrDescription AS WSTRING _                ' __out BSTR *pbstrDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDispError_INTERFACE_DEFINED__ */


' ########################################################################################
' IVariantChangeType interface
' IID = A6EF9862-C720-11D0-9337-00A0C90DCAA9
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVariantChangeType_INTERFACE_DEFINED)
    %IVariantChangeType_INTERFACE_DEFINED = 1

$IID_IVariantChangeType = GUID$("{A6EF9862-C720-11D0-9337-00A0C90DCAA9}")

INTERFACE IVariantChangeType $IID_IVariantChangeType

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ChangeType ( _                                ' VTable offset = 12
     BYREF pvarDst AS VARIANT _                         ' __inout VARIANT *pvarDst
   , BYREF pvarSrc AS VARIANT _                         ' __in VARIANT *pvarSrc
   , BYVAL lcid AS DWORD _                              ' __in LCID lcid
   , BYVAL vtNew AS WORD _                              ' __in VARTYPE vtNew
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVariantChangeType_INTERFACE_DEFINED__ */


' ########################################################################################
' IObjectIdentity interface
' IID = CA04B7E6-0D21-11D1-8CC5-00C04FC2B085
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IObjectIdentity_INTERFACE_DEFINED)
    %IObjectIdentity_INTERFACE_DEFINED = 1

$IID_IObjectIdentity = GUID$("{CA04B7E6-0D21-11D1-8CC5-00C04FC2B085}")

INTERFACE IObjectIdentity $IID_IObjectIdentity

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsEqualObject ( _                             ' VTable offset = 12
     BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjectIdentity_INTERFACE_DEFINED__ */


' ########################################################################################
' IProvideRuntimeContext interface
' IID = 10E2414A-EC59-49d2-BC51-5ADD2C36FEBC
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IProvideRuntimeContext_INTERFACE_DEFINED)
    %IProvideRuntimeContext_INTERFACE_DEFINED = 1

$IID_IProvideRuntimeContext = GUID$("{10E2414A-EC59-49d2-BC51-5ADD2C36FEBC}")

INTERFACE IProvideRuntimeContext $IID_IProvideRuntimeContext

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCurrentSourceContext ( _                   ' VTable offset = 12
     BYREF pdwContext AS DWORD _                        ' __out DWORD_PTR *pdwContext
   , BYREF pfExecutingGlobalCode AS INTEGER _           ' __out VARIANT_BOOL *pfExecutingGlobalCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProvideRuntimeContext_INTERFACE_DEFINED__ */
