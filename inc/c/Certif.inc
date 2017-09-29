' ########################################################################################
' Microsoft Windows
' File: Certif.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CERTIF_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "wtypes.inc"
#INCLUDE ONCE "oaidl.inc"

%ENUMEXT_OBJECTID = &H1

' ########################################################################################
' Interface name = ICertServerPolicy
' IID = {AA000922-FFBE-11CF-8800-00A0C903B83C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertServerPolicy_INTERFACE_DEFINED)
    %ICertServerPolicy_INTERFACE_DEFINED = 1

$IID_ICertServerPolicy = GUID$("{AA000922-FFBE-11CF-8800-00A0C903B83C}")

INTERFACE ICertServerPolicy $IID_ICertServerPolicy

   INHERIT IDispatch

   ' =====================================================================================
   METHOD SetContext <1610743808> ( _                   ' VTable offset = 28
     BYVAL Context AS LONG _                            ' __in LONG Context
   )                                                    ' void
   ' =====================================================================================
   METHOD GetRequestProperty <1610743809> ( _           ' VTable offset = 32
     BYVAL strPropertyName AS WSTRING _                 ' __in const BSTR strPropertyName
   , BYVAL PropertyType AS LONG _                       ' __in LONG PropertyType
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarPropertyValue
   ' =====================================================================================
   METHOD GetRequestAttribute <1610743810> ( _          ' VTable offset = 36
     BYVAL strAttributeName AS WSTRING _                ' __in const BSTR strAttributeName
   ) AS WSTRING                                         ' __retval_out BSTR *pstrAttributeValue
   ' =====================================================================================
   METHOD GetCertificateProperty <1610743811> ( _       ' VTable offset = 40
     BYVAL strPropertyName AS WSTRING _                 ' __in const BSTR strPropertyName
   , BYVAL PropertyType AS LONG _                       ' __in LONG PropertyType
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarPropertyValue
   ' =====================================================================================
   METHOD SetCertificateProperty <1610743812> ( _       ' VTable offset = 44
     BYVAL strPropertyName AS WSTRING _                 ' __in const BSTR strPropertyName
   , BYVAL PropertyType AS LONG _                       ' __in LONG PropertyType
   , BYREF pvarPropertyValue AS VARIANT _               ' __in const VARIANT *pvarPropertyValue
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCertificateExtension <1610743813> ( _      ' VTable offset = 48
     BYVAL strExtensionName AS WSTRING _                ' __in const BSTR strExtensionName
   , BYVAL Type AS LONG _                               ' __in LONG Type
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarValue
   ' =====================================================================================
   METHOD GetCertificateExtensionFlags <1610743814> ( _ ' VTable offset = 52
   ) AS LONG                                            ' __retval_out LONG *pExtFlags
   ' =====================================================================================
   METHOD SetCertificateExtension <1610743815> ( _      ' VTable offset = 56
     BYVAL strExtensionName AS WSTRING _                ' __in const BSTR strExtensionName
   , BYVAL Type AS LONG _                               ' __in LONG Type
   , BYVAL ExtFlags AS LONG _                           ' __in LONG ExtFlags
   , BYREF pvarValue AS VARIANT _                       ' __in const VARIANT *pvarValue
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateExtensionsSetup <1610743816> ( _     ' VTable offset = 60
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateExtensions <1610743817> ( _          ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pstrExtensionName
   ' =====================================================================================
   METHOD EnumerateExtensionsClose <1610743818> ( _     ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateAttributesSetup <1610743819> ( _     ' VTable offset = 72
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateAttributes <1610743820> ( _          ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *pstrAttributeName
   ' =====================================================================================
   METHOD EnumerateAttributesClose <1610743821> ( _     ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertServerPolicy_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICertServerExit
' IID = {4BA9EB90-732C-11D0-8816-00A0C903B83C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertServerExit_INTERFACE_DEFINED)
    %ICertServerExit_INTERFACE_DEFINED = 1

$IID_ICertServerExit = GUID$("{4BA9EB90-732C-11D0-8816-00A0C903B83C}")

INTERFACE ICertServerExit $IID_ICertServerExit

   INHERIT IDispatch

   ' =====================================================================================
   METHOD SetContext <1610743808> ( _                   ' VTable offset = 28
     BYVAL Context AS LONG _                            ' __in LONG Context
   )                                                    ' void
   ' =====================================================================================
   METHOD GetRequestProperty <1610743809> ( _           ' VTable offset = 32
     BYVAL strPropertyName AS WSTRING _                 ' __in const BSTR strPropertyName
   , BYVAL PropertyType AS LONG _                       ' __in LONG PropertyType
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarPropertyValue
   ' =====================================================================================
   METHOD GetRequestAttribute <1610743810> ( _          ' VTable offset = 36
     BYVAL strAttributeName AS WSTRING _                ' __in const BSTR strAttributeName
   ) AS WSTRING                                         ' __retval_out BSTR *pstrAttributeValue
   ' =====================================================================================
   METHOD GetCertificateProperty <1610743811> ( _       ' VTable offset = 40
     BYVAL strPropertyName AS WSTRING _                 ' __in const BSTR strPropertyName
   , BYVAL PropertyType AS LONG _                       ' __in LONG PropertyType
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarPropertyValue
   ' =====================================================================================
   METHOD GetCertificateExtension <1610743812> ( _      ' VTable offset = 44
     BYVAL strExtensionName AS WSTRING _                ' __in const BSTR strExtensionName
   , BYVAL Type AS LONG _                               ' __in LONG Type
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarValue
   ' =====================================================================================
   METHOD GetCertificateExtensionFlags <1610743813> ( _ ' VTable offset = 48
   ) AS LONG                                            ' __retval_out LONG *pExtFlags
   ' =====================================================================================
   METHOD EnumerateExtensionsSetup <1610743814> ( _     ' VTable offset = 52
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateExtensions <1610743815> ( _          ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pstrExtensionName
   ' =====================================================================================
   METHOD EnumerateExtensionsClose <1610743816> ( _     ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateAttributesSetup <1610743817> ( _     ' VTable offset = 64
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateAttributes <1610743818> ( _          ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pstrAttributeName
   ' =====================================================================================
   METHOD EnumerateAttributesClose <1610743819> ( _     ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertServerExit_INTERFACE_DEFINED__ */
