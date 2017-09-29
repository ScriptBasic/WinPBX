' ########################################################################################
' Microsoft Windows
' File: Asptlb.inc
' Library name: ASPTypeLibrary
' Version: 2.0, Locale ID = 0
' Contents: Microsoft Active Server Pages Object Library
' Library GUID: {D97A6DA0-A85C-11CF-83AE-00A0C90C2BD8}
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ASPTLB_INC = 1

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_ASP_Application      = GUID$("{7C3BAF00-25DE-11D0-A55F-00A0C90C2091}")
$CLSID_ASP_Request          = GUID$("{920C25D0-25D9-11D0-A55F-00A0C90C2091}")
$CLSID_ASP_Response         = GUID$("{46E19BA0-25DD-11D0-A55F-00A0C90C2091}")
$CLSID_ASP_ScriptingContext = GUID$("{D97A6DA0-A868-11CF-83AE-11B0C90C2BD8}")
$CLSID_ASP_Server           = GUID$("{A506D160-25E0-11D0-A55F-00A0C90C2091}")
$CLSID_ASP_Session          = GUID$("{509F8F20-25DE-11D0-A55F-00A0C90C2091}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ASP_IApplicationObject = GUID$("{D97A6DA0-A866-11CF-83AE-10A0C90C2BD8}")
$IID_ASP_IReadCookie        = GUID$("{71EAF260-0CE0-11D0-A53E-00A0C90C2091}")
$IID_ASP_IRequest           = GUID$("{D97A6DA0-A861-11CF-93AE-00A0C90C2BD8}")
$IID_ASP_IRequestDictionary = GUID$("{D97A6DA0-A85F-11DF-83AE-00A0C90C2BD8}")
$IID_ASP_IResponse          = GUID$("{D97A6DA0-A864-11CF-83BE-00A0C90C2BD8}")
$IID_ASP_IScriptingContext  = GUID$("{D97A6DA0-A868-11CF-83AE-00B0C90C2BD8}")
$IID_ASP_IServer            = GUID$("{D97A6DA0-A867-11CF-83AE-01A0C90C2BD8}")
$IID_ASP_ISessionObject     = GUID$("{D97A6DA0-A865-11CF-83AF-00A0C90C2BD8}")
$IID_ASP_IStringList        = GUID$("{D97A6DA0-A85D-11CF-83AE-00A0C90C2BD8}")
$IID_ASP_IVariantDictionary = GUID$("{4A7DEB90-B069-11D0-B373-00A0C90C2BD8}")
$IID_ASP_IWriteCookie       = GUID$("{D97A6DA0-A862-11CF-84AE-00A0C90C2BD8}")
$IID_ASP_IASPError          = GUID$("{F5A6893E-A0F5-11D1-8C4B-00C04FC324A4}")

' ########################################################################################
' Interface name = IStringList
' IID = {D97A6DA0-A85D-11CF-83AE-00A0C90C2BD8}
' A string containing comma separated values
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ASP_IStringList_INTERFACE_DEFINED)
    %ASP_IStringList_INTERFACE_DEFINED = 1

INTERFACE ASP_IStringList $IID_ASP_IStringList

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     OPTIONAL BYVAL i AS VARIANT _                      ' __opt_in VARIANT i
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariantReturn
   ' =====================================================================================
   PROPERTY GET Count <1610743809> ( _                  ' VTable offset = 32
   ) AS LONG                                            ' __retval_out int *cStrRet
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnumReturn
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ASP_IStringList_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRequestDictionary
' IID = {D97A6DA0-A85F-11DF-83AE-00A0C90C2BD8}
' Dictionary for Request collections
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ASP_IRequestDictionary_INTERFACE_DEFINED)
    %ASP_IRequestDictionary_INTERFACE_DEFINED = 1

INTERFACE ASP_IRequestDictionary $IID_ASP_IRequestDictionary

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     OPTIONAL BYVAL Var AS VARIANT _                    ' __opt_in VARIANT Var
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariantReturn
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnumReturn
   ' =====================================================================================
   PROPERTY GET Count <1610743810> ( _                  ' VTable offset = 36
   ) AS LONG                                            ' __retval_out int *cStrRet
   ' =====================================================================================
   PROPERTY GET Key <1610743811> ( _                    ' VTable offset = 40
     BYVAL VarKey AS VARIANT _                          ' __in VARIANT VarKey
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ASP_IRequestDictionary_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRequest
' IID = {D97A6DA0-A861-11CF-93AE-00A0C90C2BD8}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ASP_IRequest_INTERFACE_DEFINED)
    %ASP_IRequest_INTERFACE_DEFINED = 1

INTERFACE ASP_IRequest $IID_ASP_IRequest

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL bstrVar AS WSTRING _                         ' __in BSTR bstrVar
   ) AS IDispatch                                       ' __retval_out IDispatch **ppObjReturn
   ' =====================================================================================
   PROPERTY GET QueryString <1610743809> ( _            ' VTable offset = 32
   ) AS ASP_IRequestDictionary                          ' __retval_out IRequestDictionary **ppDictReturn
   ' =====================================================================================
   PROPERTY GET Form <1610743810> ( _                   ' VTable offset = 36
   ) AS ASP_IRequestDictionary                          ' __retval_out IRequestDictionary **ppDictReturn
   ' =====================================================================================
   PROPERTY GET Body <1610743811> ( _                   ' VTable offset = 40
   ) AS ASP_IRequestDictionary                          ' __retval_out IRequestDictionary **ppDictReturn
   ' =====================================================================================
   PROPERTY GET ServerVariables <1610743812> ( _        ' VTable offset = 44
   ) AS ASP_IRequestDictionary                          ' __retval_out IRequestDictionary **ppDictReturn
   ' =====================================================================================
   PROPERTY GET ClientCertificate <1610743813> ( _      ' VTable offset = 48
   ) AS ASP_IRequestDictionary                          ' __retval_out IRequestDictionary **ppDictReturn
   ' =====================================================================================
   PROPERTY GET Cookies <1610743814> ( _                ' VTable offset = 52
   ) AS ASP_IRequestDictionary                          ' __retval_out IRequestDictionary **ppDictReturn
   ' =====================================================================================
   PROPERTY GET TotalBytes <1610743815> ( _             ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *pcbTotal
   ' =====================================================================================
   METHOD BinaryRead <1610743816> ( _                   ' VTable offset = 60
     BYREF pvarCountToRead AS VARIANT _                 ' __in_out VARIANT *pvarCountToRead
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarReturn
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ASP_IRequest_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IReadCookie
' IID = {71EAF260-0CE0-11D0-A53E-00A0C90C2091}
' Intermediate object for Request.Cookies
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ASP_IReadCookie_INTERFACE_DEFINED)
    %ASP_IReadCookie_INTERFACE_DEFINED = 1

INTERFACE ASP_IReadCookie $IID_ASP_IReadCookie

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     OPTIONAL BYVAL Var AS VARIANT _                    ' __opt_in VARIANT Var
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariantReturn
   ' =====================================================================================
   PROPERTY GET HasKeys <1610743809> ( _                ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfHasKeys
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        '  __retval_out IUnknown **ppEnumReturn
   ' =====================================================================================
   PROPERTY GET Count <1610743811> ( _                  ' VTable offset = 40
   ) AS LONG                                            ' __retval_out int *cStrRet
   ' =====================================================================================
   PROPERTY GET Key <1610743812> ( _                    ' VTable offset = 44
     BYVAL VarKey AS VARIANT _                          ' __in VARIANT VarKey
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ASP_IReadCookie_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWriteCookie
' IID = {D97A6DA0-A862-11CF-84AE-00A0C90C2BD8}
' Intermediate object for Response.Cookies
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ASP_IWriteCookie_INTERFACE_DEFINED)
    %ASP_IWriteCookie_INTERFACE_DEFINED = 1

INTERFACE ASP_IWriteCookie $IID_ASP_IWriteCookie

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 28
     OPTIONAL BYVAL key AS VARIANT _                    ' __opt_in VARIANT key
   , BYVAL bstrValue AS WSTRING _                       ' __in BSTR bstrValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Expires <1610743809> ( _                ' VTable offset = 32
     BYVAL dtExpires AS DOUBLE _                        ' __in DATE dtExpires
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Domain <1610743810> ( _                 ' VTable offset = 36
     BYVAL bstrDomain AS WSTRING _                      ' __in BSTR bstrDomain
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Path <1610743811> ( _                   ' VTable offset = 40
     BYVAL bstrPath AS WSTRING _                        ' __in BSTR bstrPath
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Secure <1610743812> ( _                 ' VTable offset = 44
     BYVAL fSecure AS INTEGER _                         ' __in VARIANT_BOOL fSecure
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HasKeys <1610743813> ( _                ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfHasKeys
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 52
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnumReturn
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ASP_IWriteCookie_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IResponse
' IID = {D97A6DA0-A864-11CF-83BE-00A0C90C2BD8}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ASP_IResponse_INTERFACE_DEFINED)
    %ASP_IResponse_INTERFACE_DEFINED = 1

INTERFACE ASP_IResponse $IID_ASP_IResponse

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Buffer <1610743808> ( _                 ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *fIsBuffering
   ' =====================================================================================
   PROPERTY SET Buffer <1610743808> ( _                 ' VTable offset = 32
     BYVAL fIsBuffering AS INTEGER _                    ' __in VARIANT_BOOL fIsBuffering
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ContentType <1610743810> ( _            ' VTable offset = 36
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrContentTypeRet
   ' =====================================================================================
   PROPERTY SET ContentType <1610743810> ( _            ' VTable offset = 40
     BYVAL bstrContentType AS WSTRING _                 ' __in BSTR bstrContentType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Expires <1610743812> ( _                ' VTable offset = 44
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarExpiresMinutesRet
   ' =====================================================================================
   PROPERTY SET Expires <1610743812> ( _                ' VTable offset = 48
     BYVAL lExpiresMinutes AS LONG _                    ' __in long lExpiresMinutes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExpiresAbsolute <1610743814> ( _        ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarExpiresRet
   ' =====================================================================================
   PROPERTY SET ExpiresAbsolute <1610743814> ( _        ' VTable offset = 56
     BYVAL dtExpires AS DOUBLE _                        ' __in DATE dtExpires
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Cookies <1610743816> ( _                ' VTable offset = 60
   ) AS ASP_IRequestDictionary                          ' __retval_out IRequestDictionary **ppCookies
   ' =====================================================================================
   PROPERTY GET Status <1610743817> ( _                 ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrStatusRet
   ' =====================================================================================
   PROPERTY SET Status <1610743817> ( _                 ' VTable offset = 68
     BYVAL bstrStatus AS WSTRING _                      ' __in BSTR bstrStatus
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <1610743819> ( _                          ' VTable offset = 72
     BYVAL bstrHeaderValue AS WSTRING _                 ' __in BSTR bstrHeaderValue
   , BYVAL bstrHeaderName AS WSTRING _                  ' __in BSTR bstrHeaderName
   )                                                    ' void
   ' =====================================================================================
   METHOD AddHeader <1610743820> ( _                    ' VTable offset = 76
     BYVAL bstrHeaderName AS WSTRING _                  ' __in BSTR bstrHeaderName
   , BYVAL bstrHeaderValue AS WSTRING _                 ' __in BSTR bstrHeaderValue
   )                                                    ' void
   ' =====================================================================================
   METHOD AppendToLog <1610743821> ( _                  ' VTable offset = 80
     BYVAL bstrLogEntry AS WSTRING _                    ' __in BSTR bstrLogEntry
   )                                                    ' void
   ' =====================================================================================
   METHOD BinaryWrite <1610743822> ( _                  ' VTable offset = 84
     BYVAL varInput AS VARIANT _                        ' __in VARIANT varInput
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <1610743823> ( _                        ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   METHOD End <1610743824> ( _                          ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD Flush <1610743825> ( _                        ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD Redirect <1610743826> ( _                     ' VTable offset = 100
     BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   )                                                    ' void
   ' =====================================================================================
   METHOD Write <1610743827> ( _                        ' VTable offset = 104
     BYVAL VARIANT _                                    ' __in VARIANT varText
   )                                                    ' void
   ' =====================================================================================
   METHOD WriteBlock <1610743828> ( _                   ' VTable offset = 108
     BYVAL iBlockNumber AS INTEGER _                    ' __in short iBlockNumber
   )                                                    ' void
   ' =====================================================================================
   METHOD IsClientConnected <1610743829> ( _            ' VTable offset = 112
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfIsClientConnected
   ' =====================================================================================
   PROPERTY GET CharSet <1610743830> ( _                ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCharSetRet
   ' =====================================================================================
   PROPERTY SET CharSet <1610743830> ( _                ' VTable offset = 120
     BYVAL bstrCharSet AS WSTRING _                     ' __in BSTR bstrCharSet
   )                                                    ' void
   ' =====================================================================================
   METHOD Pics <1610743832> ( _                         ' VTable offset = 124
     BYVAL bstrHeaderValue AS WSTRING _                 ' __in BSTR bstrHeaderValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CacheControl <1610743833> ( _           ' VTable offset = 128
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCacheControl
   ' =====================================================================================
   PROPERTY SET CacheControl <1610743833> ( _           ' VTable offset = 132
     BYVAL bstrCacheControl AS WSTRING _                ' __in BSTR bstrCacheControl
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ASP_IResponse_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVariantDictionary
' IID = {4A7DEB90-B069-11D0-B373-00A0C90C2BD8}
' Dictionary for Variant collections
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ASP_IVariantDictionary_INTERFACE_DEFINED)
    %ASP_IVariantDictionary_INTERFACE_DEFINED = 1

INTERFACE ASP_IVariantDictionary $IID_ASP_IVariantDictionary

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL VarKey AS VARIANT _                          ' __in VARIANT VarKey
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY SET Item <0> ( _                            ' VTable offset = 32
     BYVAL VarKey AS VARIANT _                          ' __in VARIANT VarKey
   , BYVAL var AS VARIANT _                             ' __in VARIANT var
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Item <0> ( _                     ' VTable offset = 36
     BYVAL VarKey AS VARIANT _                          ' __in VARIANT VarKey
   , BYVAL var AS VARIANT _                             ' __in VARIANT var
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Key <1610743811> ( _                    ' VTable offset = 40
     BYVAL VarKey AS VARIANT _                          ' __in VARIANT VarKey
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY GET Count <1610743812> ( _                  ' VTable offset = 44
   ) AS LONG                                            ' __retval_out int *cStrRet
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 48
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnumReturn
   ' =====================================================================================
   METHOD Remove ( _                                    ' VTable offset = 52
     BYVAL VarKey AS VARIANT _                          ' __in VARIANT VarKey
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveAll ( _                                 ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ASP_IVariantDictionary_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISessionObject
' IID = {D97A6DA0-A865-11CF-83AF-00A0C90C2BD8}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ASP_ISessionObject_INTERFACE_DEFINED)
    %ASP_ISessionObject_INTERFACE_DEFINED = 1

INTERFACE ASP_ISessionObject $IID_ASP_ISessionObject

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET SessionID <1610743808> ( _              ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrRet
   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 32
     BYVAL bstrValue AS WSTRING _                       ' __in BSTR bstrValue
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY SET Value <0> ( _                           ' VTable offset = 36
     BYVAL bstrValue AS WSTRING _                       ' __in BSTR bstrValue
   , BYVAL var AS VARIANT _                             ' __in VARIANT var
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Value <0> ( _                    ' VTable offset = 40
     BYVAL bstrValue AS WSTRING _                       ' __in BSTR bstrValue
   , BYVAL var AS VARIANT _                             ' __in VARIANT var
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Timeout <1610743812> ( _                ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plvar
   ' =====================================================================================
   PROPERTY SET Timeout <1610743812> ( _                ' VTable offset = 48
     BYVAL lvar AS LONG _                               ' __in long lvar
   )                                                    ' void
   ' =====================================================================================
   METHOD Abandon <1610743814> ( _                      ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CodePage <1610743815> ( _               ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *plvar
   ' =====================================================================================
   PROPERTY SET CodePage <1610743815> ( _               ' VTable offset = 60
     BYVAL lvar AS LONG _                               ' __in long lvar
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LCID <1610743817> ( _                   ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *plvar
   ' =====================================================================================
   PROPERTY SET LCID <1610743817> ( _                   ' VTable offset = 68
     BYVAL lvar AS LONG _                               ' __in long lvar
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StaticObjects <1610743819> ( _          ' VTable offset = 72
   ) AS ASP_IVariantDictionary                          ' __retval_out IVariantDictionary **ppTaggedObjects
   ' =====================================================================================
   PROPERTY GET Contents <1610743820> ( _               ' VTable offset = 76
   ) AS ASP_IVariantDictionary                          ' __retval_out IVariantDictionary **ppProperties
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ASP_ISessionObject_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IApplicationObject
' IID = {D97A6DA0-A866-11CF-83AE-10A0C90C2BD8}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ASP_IApplicationObject_INTERFACE_DEFINED)
    %ASP_IApplicationObject_INTERFACE_DEFINED = 1

INTERFACE ASP_IApplicationObject $IID_ASP_IApplicationObject

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 28
     BYVAL bstrValue AS WSTRING _                       ' __in BSTR bstrValue
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY SET Value <0> ( _                           ' VTable offset = 32
     BYVAL bstrValue AS WSTRING _                       ' __in BSTR bstrValue
   , BYVAL var AS VARIANT _                             ' __in VARIANT var
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Value <0> ( _                    ' VTable offset = 36
     BYVAL bstrValue AS WSTRING _                       ' __in BSTR bstrValue
   , BYVAL var AS VARIANT _                             ' __in VARIANT var
   )                                                    ' void
   ' =====================================================================================
   METHOD Lock <1610743811> ( _                         ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD UnLock <1610743812> ( _                       ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StaticObjects <1610743813> ( _          ' VTable offset = 48
   ) AS ASP_IVariantDictionary                          ' __retval_out IVariantDictionary **ppProperties
   ' =====================================================================================
   PROPERTY GET Contents <1610743814> ( _               ' VTable offset = 52
   ) AS ASP_IVariantDictionary                          ' __retval_out IVariantDictionary **ppProperties
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ASP_IApplicationObject_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IASPError
' IID = {F5A6893E-A0F5-11D1-8C4B-00C04FC324A4}
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ASP_IASPError_INTERFACE_DEFINED)
    %ASP_IASPError_INTERFACE_DEFINED = 1

INTERFACE ASP_IASPError $IID_ASP_IASPError

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ASPCode ( _                             ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrASPCode
   ' =====================================================================================
   PROPERTY GET Number ( _                              ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plNumber
   ' =====================================================================================
   PROPERTY GET Category ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSource
   ' =====================================================================================
   PROPERTY GET File ( _                                ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFileName
   ' =====================================================================================
   PROPERTY GET Line ( _                                ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plLineNumber
   ' =====================================================================================
   PROPERTY GET Description ( _                         ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY GET ASPDescription ( _                      ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY GET Column ( _                              ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *plColumn
   ' =====================================================================================
   PROPERTY GET Source ( _                              ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrLineText
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ASP_IASPError_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IServer
' IID = {D97A6DA0-A867-11CF-83AE-
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ASP_IServer_INTERFACE_DEFINED)
    %ASP_IServer_INTERFACE_DEFINED = 1

INTERFACE ASP_IServer $IID_ASP_IServer

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ScriptTimeout <1610743808> ( _          ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plTimeoutSeconds
   ' =====================================================================================
   PROPERTY SET ScriptTimeout <1610743808> ( _          ' VTable offset = 32
     BYVAL lTimeoutSeconds AS LONG _                    ' __in long lTimeoutSeconds
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateObject <1610743810> ( _                 ' VTable offset = 36
     BYVAL bstrProgID AS WSTRING _                      ' __in BSTR bstrProgID
   ) AS IDispatch                                       ' __retval_out IDispatch **ppDispObject
   ' =====================================================================================
   METHOD HTMLEncode <1610743811> ( _                   ' VTable offset = 40
     BYVAL bstrIn AS WSTRING _                          ' __in BSTR bstrIn
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrEncoded
   ' =====================================================================================
   METHOD MapPath <1610743812> ( _                      ' VTable offset = 44
     BYVAL bstrLogicalPath AS WSTRING _                 ' __in BSTR bstrLogicalPath
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPhysicalPath
   ' =====================================================================================
   METHOD URLEncode <1610743813> ( _                    ' VTable offset = 48
     BYVAL bstrIn AS WSTRING _                          ' __in BSTR bstrIn
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrEncoded
   ' =====================================================================================
   METHOD URLPathEncode <1610743814> ( _                ' VTable offset = 52
     BYVAL bstrIn AS WSTRING _                          ' __in BSTR bstrIn
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrEncoded
   ' =====================================================================================
   METHOD Execute ( _                                   ' VTable offset = 56
     BYVAL bstrLogicalPath AS WSTRING _                 ' __in BSTR bstrLogicalPath
   )                                                    ' void
   ' =====================================================================================
   METHOD Transfer ( _                                  ' VTable offset = 60
     BYVAL bstrLogicalPath AS WSTRING _                 ' __in BSTR bstrLogicalPath
   )                                                    ' void
   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offset = 64
   ) AS ASP_IASPError                                   ' __retval_out IASPError **ppASPErrorObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ASP_IServer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IScriptingContext
' IID = {D97A6DA0-A868-11CF-83AE-00B0C90C2BD8}
' Active Server Page Scripting Context
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ASP_IScriptingContext_INTERFACE_DEFINED)
    %ASP_IScriptingContext_INTERFACE_DEFINED = 1

INTERFACE ASP_IScriptingContext $IID_ASP_IScriptingContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Request <1610743808> ( _                ' VTable offset = 28
   ) AS ASP_IRequest                                    ' __retval_out IRequest **ppRequest
   ' =====================================================================================
   PROPERTY GET Response <1610743809> ( _               ' VTable offset = 32
   ) AS ASP_IResponse                                   ' __retval_out IResponse **ppResponse
   ' =====================================================================================
   PROPERTY GET Server <1610743810> ( _                 ' VTable offset = 36
   ) AS ASP_IServer                                     ' __retval_out IServer **ppServer
   ' =====================================================================================
   PROPERTY GET Session <1610743811> ( _                ' VTable offset = 40
   ) AS ASP_ISessionObject                              ' __retval_out ISessionObject **ppSession
   ' =====================================================================================
   PROPERTY GET Application <1610743812> ( _            ' VTable offset = 44
   ) AS ASP_IApplicationObject                          ' __retval_out IApplicationObject **ppApplication
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ASP_IScriptingContext_INTERFACE_DEFINED__ */
