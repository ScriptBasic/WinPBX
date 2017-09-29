' ########################################################################################
' Microsoft Windows
' File: IIIS.inc
' Library name: IISOle
' Version: 1.0, Locale ID = 0
' Library GUID: {49D704A0-89F7-11D0-8527-00C04FD8D503}
' Type library: adsiis.tlb
' Contents: Active DS IIS Namespace Provider
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IIIS_INC = 1

$LIBID_IISOle             = GUID$("{49D704A0-89F7-11D0-8527-00C04FD8D503}")

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_IISNamespace       = GUID$("{D6BFA35E-89F2-11D0-8527-00C04FD8D503}")
$CLSID_IISProvider        = GUID$("{D88966DE-89F2-11D0-8527-00C04FD8D503}")
$CLSID_IPSecurity         = GUID$("{F3287520-BBA3-11D0-9BDC-00A0C922E703}")
$CLSID_MimeMap            = GUID$("{9036B028-A780-11D0-9B3D-0080C710EF95}")
$CLSID_PropertyAttribute  = GUID$("{FD2280A8-51A4-11D2-A601-3078302C2030}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IISBaseObject        = GUID$("{4B42E390-0E96-11D1-9C3F-00A0C922E703}")
$IID_IISIPSecurity        = GUID$("{F3287521-BBA3-11D0-9BDC-00A0C922E703}")
$IID_IISMimeType          = GUID$("{9036B027-A780-11D0-9B3D-0080C710EF95}")
$IID_IISPropertyAttribute = GUID$("{50E21930-A247-11D1-B79C-00A0C922E703}")
$IID_IISSchemaObject      = GUID$("{B6865A9C-3F64-11D2-A600-00A0C922E703}")


' ########################################################################################
' Interface name = IISMimeType
' IID = {9036B027-A780-11D0-9B3D-0080C710EF95}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IISMimeType_INTERFACE_DEFINED)
    %IISMimeType_INTERFACE_DEFINED = 1

INTERFACE IISMimeType $IID_IISMimeType

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET MimeType <4> ( _                        ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET MimeType <4> ( _                        ' VTable offset = 32
     BYVAL bstrMimeType AS WSTRING _                    ' __in BSTR bstrMimeType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Extension <5> ( _                       ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Extension <5> ( _                       ' VTable offset = 40
     BYVAL bstrExtension AS WSTRING _                   ' __in BSTR bstrExtension
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IISMimeType_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IISIPSecurity
' IID = {F3287521-BBA3-11D0-9BDC-00A0C922E703}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IISIPSecurity_INTERFACE_DEFINED)
    %IISIPSecurity_INTERFACE_DEFINED = 1

INTERFACE IISIPSecurity $IID_IISIPSecurity

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET IPDeny <4> ( _                          ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET IPDeny <4> ( _                          ' VTable offset = 32
     BYVAL vIPDeny AS VARIANT _                         ' __in VARIANT vIPDeny
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IPGrant <5> ( _                         ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET IPGrant <5> ( _                         ' VTable offset = 40
     BYVAL vIPGrant AS VARIANT _                        ' __in VARIANT vIPGrant
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DomainDeny <6> ( _                      ' VTable offset = 44
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET DomainDeny <6> ( _                      ' VTable offset = 48
     BYVAL vDomainDeny AS VARIANT _                     ' __in VARIANT vDomainDeny
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DomainGrant <7> ( _                     ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET DomainGrant <7> ( _                     ' VTable offset = 56
     BYVAL vDomainGrant AS VARIANT _                    ' __in VARIANT vDomainGrant
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GrantByDefault <8> ( _                  ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retval
   ' =====================================================================================
   PROPERTY SET GrantByDefault <8> ( _                  ' VTable offset = 64
     BYVAL fGrantByDefault AS INTEGER _                 ' __in VARIANT_BOOL fGrantByDefault
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IISIPSecurity_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IISBaseObject
' IID = {4B42E390-0E96-11D1-9C3F-00A0C922E703}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IISBaseObject_INTERFACE_DEFINED)
    %IISBaseObject_INTERFACE_DEFINED = 1

INTERFACE IISBaseObject $IID_IISBaseObject

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetDataPaths <101> ( _                        ' VTable offset = 28
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL lnAttribute AS LONG _                        ' __in LONG lnAttribute
   ) AS VARIANT                                         ' __retval_out VARIANT *pvPaths
   ' =====================================================================================
   METHOD GetPropertyAttribObj <102> ( _                ' VTable offset = 32
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS IDispatch                                       ' __retval_out IDispatch **ppObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IISBaseObject_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IISSchemaObject
' IID = {B6865A9C-3F64-11D2-A600-00A0C922E703}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IISSchemaObject_INTERFACE_DEFINED)
    %IISSchemaObject_INTERFACE_DEFINED = 1


INTERFACE IISSchemaObject $IID_IISSchemaObject

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetSchemaPropertyAttributes <101> ( _         ' VTable offset = 28
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS IDispatch                                       ' __retval_out IDispatch **ppObject
   ' =====================================================================================
   METHOD PutSchemaPropertyAttributes <102> ( _         ' VTable offset = 32
     BYVAL pObject AS IDispatch _                       ' __in IDispatch *pObject
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IISSchemaObject_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IISPropertyAttribute
' IID = {50E21930-A247-11D1-B79C-00A0C922E703}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IISPropertyAttribute_INTERFACE_DEFINED)
    %IISPropertyAttribute_INTERFACE_DEFINED = 1

INTERFACE IISPropertyAttribute $IID_IISPropertyAttribute

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET PropName <4> ( _                        ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET MetaId <5> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET MetaId <5> ( _                          ' VTable offset = 36
     BYVAL lnMetaId AS LONG _                           ' __in long lnMetaId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UserType <6> ( _                        ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET UserType <6> ( _                        ' VTable offset = 44
     BYVAL lnUserType AS LONG _                         ' __in long lnUserType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllAttributes <7> ( _                   ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY GET Inherit <8> ( _                         ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retval
   ' =====================================================================================
   PROPERTY SET Inherit <8> ( _                         ' VTable offset = 56
     BYVAL fInherit AS INTEGER _                        ' __in VARIANT_BOOL fInherit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Secure <9> ( _                          ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retval
   ' =====================================================================================
   PROPERTY SET Secure <9> ( _                          ' VTable offset = 64
     BYVAL fSecure AS INTEGER _                         ' __in VARIANT_BOOL fSecure
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Reference <10> ( _                      ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retval
   ' =====================================================================================
   PROPERTY SET Reference <10> ( _                      ' VTable offset = 72
     BYVAL fReference AS INTEGER _                      ' __in VARIANT_BOOL fReference
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Volatile <11> ( _                       ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retval
   ' =====================================================================================
   PROPERTY SET Volatile <11> ( _                       ' VTable offset = 80
     BYVAL fVolatile AS INTEGER _                       ' __in VARIANT_BOOL fVolatile
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Isinherit <12> ( _                      ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retval
   ' =====================================================================================
   PROPERTY GET Default <13> ( _                        ' VTable offset = 88
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET Default <13> ( _                        ' VTable offset = 92
     BYVAL vDefault AS VARIANT _                        ' __in VARIANT vDefault
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IISPropertyAttribute_INTERFACE_DEFINED__ */
