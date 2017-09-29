' ########################################################################################
' Microsoft Windows
' File: CertEnc.inc
' Library name: CERTENCODELib
' Version: 1.0, Locale ID = 0
' Library GUID: {13199C00-7494-11D0-8816-00A0C903B83C}
' Path: C:\Archivos de programa\Microsoft Platform SDK for Windows Server 2003 R2\Bin\CertEncL.Dll
' Contents: CertEnc 1.0 Type Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CERTENC_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "wtypes.inc"
#INCLUDE ONCE "oaidl.inc"

$LIBID_CERTENCODELib = GUID$("{13199C00-7494-11D0-8816-00A0C903B83C}")

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_CCertEncodeAltName     = GUID$("{1CFC4CDA-1271-11D1-9BD4-00C04FB683FA}")
$CLSID_CCertEncodeBitString   = GUID$("{6D6B3CD8-1278-11D1-9BD4-00C04FB683FA}")
$CLSID_CCertEncodeCRLDistInfo = GUID$("{01FA60A0-BBFF-11D0-8825-00A0C903B83C}")
$CLSID_CCertEncodeDateArray   = GUID$("{301F77B0-A470-11D0-8821-00A0C903B83C}")
$CLSID_CCertEncodeLongArray   = GUID$("{4E0680A0-A0A2-11D0-8821-00A0C903B83C}")
$CLSID_CCertEncodeStringArray = GUID$("{19A76FE0-7494-11D0-8816-00A0C903B83C}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ICertEncodeAltName       = GUID$("{1C9A8C70-1271-11D1-9BD4-00C04FB683FA}")
$IID_ICertEncodeBitString     = GUID$("{6DB525BE-1278-11D1-9BD4-00C04FB683FA}")
$IID_ICertEncodeCRLDistInfo   = GUID$("{01958640-BBFF-11D0-8825-00A0C903B83C}")
$IID_ICertEncodeDateArray     = GUID$("{2F9469A0-A470-11D0-8821-00A0C903B83C}")
$IID_ICertEncodeLongArray     = GUID$("{15E2F230-A0A2-11D0-8821-00A0C903B83C}")
$IID_ICertEncodeStringArray   = GUID$("{12A88820-7494-11D0-8816-00A0C903B83C}")


' ########################################################################################
' Interface name = ICertEncodeStringArray
' IID = {12A88820-7494-11D0-8816-00A0C903B83C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertEncodeStringArray_INTERFACE_DEFINED)
    %ICertEncodeStringArray_INTERFACE_DEFINED = 1

INTERFACE ICertEncodeStringArray $IID_ICertEncodeStringArray

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Decode <1610743808> ( _                       ' VTable offset = 28
     BYVAL strBinary AS WSTRING _                       ' __in const BSTR strBinary
   )                                                    ' void
   ' =====================================================================================
   METHOD GetStringType <1610743809> ( _                ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *pStringType
   ' =====================================================================================
   METHOD GetCount <1610743810> ( _                     ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *pCount
   ' =====================================================================================
   METHOD GetValue <1610743811> ( _                     ' VTable offset = 40
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS WSTRING                                         ' __retval_out BSTR *pstr
   ' =====================================================================================
   METHOD Reset <1610743812> ( _                        ' VTable offset = 44
     BYVAL Count AS LONG _                              ' __in LONG Count
   , BYVAL StringType AS LONG _                         ' __in LONG StringType
   )                                                    ' void
   ' =====================================================================================
   METHOD SetValue <1610743813> ( _                     ' VTable offset = 48
     BYVAL Index AS LONG _                              ' __in LONG Index
   , BYVAL str AS WSTRING _                             ' __in const BSTR str
   )                                                    ' void
   ' =====================================================================================
   METHOD Encode <1610743814> ( _                       ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pstrBinary
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertEncodeStringArray_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICertEncodeLongArray
' IID = {15E2F230-A0A2-11D0-8821-00A0C903B83C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertEncodeLongArray_INTERFACE_DEFINED)
    %ICertEncodeLongArray_INTERFACE_DEFINED = 1

INTERFACE ICertEncodeLongArray $IID_ICertEncodeLongArray

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Decode <1610743808> ( _                       ' VTable offset = 28
     BYVAL strBinary AS WSTRING _                       ' __in const BSTR strBinary
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCount <1610743809> ( _                     ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *pCount
   ' =====================================================================================
   METHOD GetValue <1610743810> ( _                     ' VTable offset = 36
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   METHOD Reset <1610743811> ( _                        ' VTable offset = 40
     BYVAL LONG _                                       ' __in LONG Count
   )                                                    ' void
   ' =====================================================================================
   METHOD SetValue <1610743812> ( _                     ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in LONG Index
   , BYVAL Value AS LONG _                              ' __in LONG Value
   )                                                    ' void
   ' =====================================================================================
   METHOD Encode <1610743813> ( _                       ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pstrBinary
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertEncodeLongArray_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICertEncodeDateArray
' IID = {2F9469A0-A470-11D0-8821-00A0C903B83C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertEncodeDateArray_INTERFACE_DEFINED)
    %ICertEncodeDateArray_INTERFACE_DEFINED = 1

INTERFACE ICertEncodeDateArray $IID_ICertEncodeDateArray

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Decode <1610743808> ( _                       ' VTable offset = 28
     BYVAL strBinary AS WSTRING _                       ' __in const BSTR strBinary
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCount <1610743809> ( _                     ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *pCount
   ' =====================================================================================
   METHOD GetValue <1610743810> ( _                     ' VTable offset = 36
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS DOUBLE                                          ' __retval_out DATE *pValue
   ' =====================================================================================
   METHOD Reset <1610743811> ( _                        ' VTable offset = 40
     BYVAL LONG _                                       ' __in LONG Count
   )                                                    ' void
   ' =====================================================================================
   METHOD SetValue <1610743812> ( _                     ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in LONG Index
   , BYVAL Value AS DOUBLE _                            ' __in DATE Value
   )                                                    ' void
   ' =====================================================================================
   METHOD Encode <1610743813> ( _                       ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pstrBinary
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertEncodeDateArray_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICertEncodeCRLDistInfo
' IID = {01958640-BBFF-11D0-8825-00A0C903B83C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertEncodeCRLDistInfo_INTERFACE_DEFINED)
    %ICertEncodeCRLDistInfo_INTERFACE_DEFINED = 1

INTERFACE ICertEncodeCRLDistInfo $IID_ICertEncodeCRLDistInfo

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Decode <1610743808> ( _                       ' VTable offset = 28
     BYVAL strBinary AS WSTRING _                       ' __in const BSTR strBinary
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDistPointCount <1610743809> ( _            ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *pDistPointCount
   ' =====================================================================================
   METHOD GetNameCount <1610743810> ( _                 ' VTable offset = 36
     BYVAL DistPointIndex AS LONG _                     ' __in LONG DistPointIndex
   ) AS LONG                                            ' __retval_out LONG *pNameCount
   ' =====================================================================================
   METHOD GetNameChoice <1610743811> ( _                ' VTable offset = 40
     BYVAL DistPointIndex AS LONG _                     ' __in LONG DistPointIndex
   , BYVAL NameIndex AS LONG _                          ' __in LONG NameIndex
   ) AS LONG                                            ' __retval_out LONG *pNameChoice
   ' =====================================================================================
   METHOD GetName <1610743812> ( _                      ' VTable offset = 44
     BYVAL DistPointIndex AS LONG _                     ' __in LONG DistPointIndex
   , BYVAL NameIndex AS LONG _                          ' __in LONG NameIndex
   ) AS WSTRING                                         ' __retval_out BSTR *pstrName
   ' =====================================================================================
   METHOD Reset <1610743813> ( _                        ' VTable offset = 48
     BYVAL DistPointCount AS LONG _                     ' __in LONG DistPointCount
   )                                                    ' void
   ' =====================================================================================
   METHOD SetNameCount <1610743814> ( _                 ' VTable offset = 52
     BYVAL DistPointIndex AS LONG _                     ' __in LONG DistPointIndex
   , BYVAL NameCount AS LONG _                          ' __in LONG NameCount
   )                                                    ' void
   ' =====================================================================================
   METHOD SetNameEntry <1610743815> ( _                 ' VTable offset = 56
     BYVAL DistPointIndex AS LONG _                     ' __in LONG DistPointIndex
   , BYVAL NameIndex AS LONG _                          ' __in LONG NameIndex
   , BYVAL NameChoice AS LONG _                         ' __in LONG NameChoice
   , BYVAL strName AS WSTRING _                         ' __in const BSTR strName
   )                                                    ' void
   ' =====================================================================================
   METHOD Encode <1610743816> ( _                       ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pstrBinary
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertEncodeCRLDistInfo_INTERFACE_DEFINED__ */


%EAN_NAMEOBJECTID = &H80000000???


' ########################################################################################
' Interface name = ICertEncodeAltName
' IID = {1C9A8C70-1271-11D1-9BD4-00C04FB683FA}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertEncodeAltName_INTERFACE_DEFINED)
    %ICertEncodeAltName_INTERFACE_DEFINED = 1

INTERFACE ICertEncodeAltName $IID_ICertEncodeAltName

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Decode <1610743808> ( _                       ' VTable offset = 28
     BYVAL strBinary AS WSTRING _                       ' __in const BSTR strBinary
   )                                                    ' void
   ' =====================================================================================
   METHOD GetNameCount <1610743809> ( _                 ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *pNameCount
   ' =====================================================================================
   METHOD GetNameChoice <1610743810> ( _                ' VTable offset = 36
     BYVAL NameIndex AS LONG _                          ' __in LONG NameIndex
   ) AS LONG                                            ' __retval_out LONG *pNameChoice
   ' =====================================================================================
   METHOD GetName <1610743811> ( _                      ' VTable offset = 40
     BYVAL NameIndex AS LONG _                          ' __in LONG NameIndex
   ) AS WSTRING                                         ' __retval_out BSTR *pstrName
   ' =====================================================================================
   METHOD Reset <1610743812> ( _                        ' VTable offset = 44
     BYVAL NameCount AS LONG _                          ' __in LONG NameCount
   )                                                    ' void
   ' =====================================================================================
   METHOD SetNameEntry <1610743813> ( _                 ' VTable offset = 48
     BYVAL NameIndex AS LONG _                          ' __in LONG NameIndex
   , BYVAL NameChoice AS LONG _                         ' __in LONG NameChoice
   , BYVAL strName AS WSTRING _                         ' __in const BSTR strName
   )                                                    ' void
   ' =====================================================================================
   METHOD Encode <1610743814> ( _                       ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pstrBinary
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertEncodeAltName_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICertEncodeBitString
' IID = {6DB525BE-1278-11D1-9BD4-00C04FB683FA}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertEncodeBitString_INTERFACE_DEFINED)
    %ICertEncodeBitString_INTERFACE_DEFINED = 1

INTERFACE ICertEncodeBitString $IID_ICertEncodeBitString

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Decode <1610743808> ( _                       ' VTable offset = 28
     BYVAL strBinary AS WSTRING _                       ' __in const BSTR strBinary
   )                                                    ' void
   ' =====================================================================================
   METHOD GetBitCount <1610743809> ( _                  ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *pBitCount
   ' =====================================================================================
   METHOD GetBitString <1610743810> ( _                 ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pstrBitString
   ' =====================================================================================
   METHOD Encode <1610743811> ( _                       ' VTable offset = 40
     BYVAL BitCount AS LONG _                           ' __in LONG BitCount
   , BYVAL strBitString AS WSTRING _                    ' __in BSTR strBitString
   ) AS WSTRING                                         ' __retval_out BSTR *pstrBinary
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertEncodeBitString_INTERFACE_DEFINED__ */
