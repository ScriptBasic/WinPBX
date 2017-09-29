' ########################################################################################
' Microsoft Windows
' File: PortableDeviceTypes.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PORTABLEDEVICETYPES_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "propsys.inc"

'#if (_WIN32_WINNT >= 0x0501) // XP and later

$CLSID_WpdSerializer = GUID$("{0B91A74B-AD7C-4A9D-B563-29EEF9167172}")
$CLSID_PortableDeviceValues = GUID$("{0C15D503-D017-47CE-9016-7B3F978721CC}")
$CLSID_PortableDeviceKeyCollection = GUID$("{DE2D022D-2480-43BE-97F0-D1FA2CF98F4F}")
$CLSID_PortableDevicePropVariantCollection = GUID$("{08A99E2F-6D6D-4B80-AF5A-BAF2BCBE4CB9}")
$CLSID_PortableDeviceValuesCollection = GUID$("{3882134D-14CF-4220-9CB4-435F86D83F60}")

' ########################################################################################
' Interface name = IWpdSerializer
' IID = {B32F4002-BB27-45FF-AF4F-06631C1E8DAD}
' IWpdSerializer Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWpdSerializer_INTERFACE_DEFINED)
    %IWpdSerializer_INTERFACE_DEFINED = 1

$IID_IWpdSerializer = GUID$("{B32F4002-BB27-45FF-AF4F-06631C1E8DAD}")

INTERFACE IWpdSerializer $IID_IWpdSerializer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetIPortableDeviceValuesFromBuffer ( _        ' VTable offset = 12
     BYREF pBuffer AS BYTE _                            ' __in BYTE* pBuffer
   , BYVAL dwInputBufferLength AS DWORD _               ' __in DWORD dwInputBufferLength
   , BYREF ppParams AS IPortableDeviceValues _          ' __out IPortableDeviceValues** ppParams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteIPortableDeviceValuesToBuffer ( _        ' VTable offset = 16
     BYVAL dwOutputBufferLength AS DWORD _              ' __in DWORD dwOutputBufferLength
   , BYVAL pResults AS IPortableDeviceValues _          ' __in IPortableDeviceValues* pResults
   , BYREF pBuffer AS BYTE _                            ' __out BYTE* pBuffer
   , BYREF pdwBytesWritten AS DWORD _                   ' __out DWORD* pdwBytesWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBufferFromIPortableDeviceValues ( _        ' VTable offset = 20
     BYVAL pSource AS IPortableDeviceValues _           ' __in IPortableDeviceValues* pSource
   , BYREF ppBuffer AS DWORD _                          ' __out BYTE** ppBuffer
   , BYREF pdwBufferSize AS DWORD _                     ' __out DWORD* pdwBufferSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSerializedSize ( _                         ' VTable offset = 24
     BYVAL pSource AS IPortableDeviceValues _           ' __in IPortableDeviceValues* pSource
   , BYREF pdwSize AS DWORD _                           ' __out DWORD* pdwSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWpdSerializer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPortableDeviceValues
' IID = {6848F6F2-3155-4F86-B6F5-263EEEAB3143}
' IPortableDeviceValues Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPortableDeviceValues_INTERFACE_DEFINED)
    %IPortableDeviceValues_INTERFACE_DEFINED = 1

$IID_IPortableDeviceValues = GUID$("{6848F6F2-3155-4F86-B6F5-263EEEAB3143}")

INTERFACE IPortableDeviceValues $IID_IPortableDeviceValues

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF pcelt AS DWORD _                             ' __in DWORD* pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL index AS DWORD _                             ' __in DWORD index
   , BYREF pKey AS PROPERTYKEY _                        ' __in_out PROPERTYKEY* pKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT* pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetValue ( _                                  ' VTable offset = 20
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYREF pValue AS PROPVARIANT _                      ' __in PROPVARIANT* pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 24
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYREF pValue AS PROPVARIANT _                      ' __out PROPVARIANT* pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStringValue ( _                            ' VTable offset = 28
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYREF Value AS WSTRINGZ _                          ' __in LPCWSTR Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringValue ( _                            ' VTable offset = 32
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYREF pValue AS DWORD _                            ' __out LPWSTR *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUnsignedIntegerValue ( _                   ' VTable offset = 36
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYVAL Value AS DWORD _                             ' __in const ULONG Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUnsignedIntegerValue ( _                   ' VTable offset = 40
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYREF pValue AS DWORD _                            ' __out ULONG *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSignedIntegerValue ( _                     ' VTable offset = 44
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYVAL Value AS LONG _                              ' __in const LONG Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSignedIntegerValue ( _                     ' VTable offset = 48
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYREF pValue AS LONG _                             ' __out LONG *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUnsignedLargeIntegerValue ( _              ' VTable offset = 52
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYVAL Value AS QUAD _                              ' __in const ULONGLONG Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUnsignedLargeIntegerValue ( _              ' VTable offset = 56
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYREF pValue AS QUAD _                             ' __out ULONGLONG *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSignedLargeIntegerValue ( _                ' VTable offset = 60
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYVAL Value AS QUAD _                              ' __in const LONGLONG Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSignedLargeIntegerValue ( _                ' VTable offset = 64
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYREF pValue AS QUAD _                             ' __out LONGLONG *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFloatValue ( _                             ' VTable offset = 68
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYVAL Value AS SINGLE _                            ' __in const FLOAT Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFloatValue ( _                             ' VTable offset = 72
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYREF pValue AS SINGLE _                           ' __out FLOAT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetErrorValue ( _                             ' VTable offset = 76
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYVAL Value AS LONG _                              ' __in const HRESULT Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetErrorValue ( _                             ' VTable offset = 80
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYREF pValue AS LONG _                             ' __out HRESULT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetKeyValue ( _                               ' VTable offset = 84
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYREF Value AS PROPERTYKEY _                       ' __in PROPERTYKEY* Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetKeyValue ( _                               ' VTable offset = 88
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYREF pValue AS PROPERTYKEY _                      ' __out PROPERTYKEY *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBoolValue ( _                              ' VTable offset = 92
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYVAL Value AS LONG _                              ' __in const BOOL Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBoolValue ( _                              ' VTable offset = 96
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYREF pValue AS LONG _                             ' __out BOOL *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIUnknownValue ( _                          ' VTable offset = 100
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYVAL pValue AS IUnknown _                         ' __in IUnknown *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIUnknownValue ( _                          ' VTable offset = 104
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYREF ppValue AS IUnknown _                        ' __out IUnknown **ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGuidValue ( _                              ' VTable offset = 108
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYREF Value AS GUID _                              ' __in REFGUID Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGuidValue ( _                              ' VTable offset = 112
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYREF pValue AS GUID _                             ' __out GUID* pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBufferValue ( _                            ' VTable offset = 116
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYREF pValue AS BYTE _                             ' __in BYTE* pValue
   , BYVAL cbValue AS DWORD _                           ' __in DWORD cbValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBufferValue ( _                            ' VTable offset = 120
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYREF ppValue AS DWORD _                           ' __out BYTE** ppValue
   , BYREF pcbValue AS DWORD _                          ' __out DWORD* pcbValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIPortableDeviceValuesValue ( _             ' VTable offset = 124
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYVAL pValue AS IPortableDeviceValues _            ' __in IPortableDeviceValues* pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIPortableDeviceValuesValue ( _             ' VTable offset = 128
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYREF ppValue AS IPortableDeviceValues _           ' __out IPortableDeviceValues** ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIPortableDevicePropVariantCollectionValue ( _ ' VTable offset = 132
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYVAL pValue AS IPortableDevicePropVariantCollection _ ' __in IPortableDevicePropVariantCollection* pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIPortableDevicePropVariantCollectionValue ( _ ' VTable offset = 136
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYREF ppValue AS IPortableDevicePropVariantCollection _ ' __out IPortableDevicePropVariantCollection** ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIPortableDeviceKeyCollectionValue ( _      ' VTable offset = 140
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYVAL pValue AS IPortableDeviceKeyCollection _     ' __in IPortableDeviceKeyCollection* pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIPortableDeviceKeyCollectionValue ( _      ' VTable offset = 144
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYREF ppValue AS IPortableDeviceKeyCollection _    ' __out IPortableDeviceKeyCollection** ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIPortableDeviceValuesCollectionValue ( _   ' VTable offset = 148
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYVAL pValue AS IPortableDeviceValuesCollection _  ' __in IPortableDeviceValuesCollection* pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIPortableDeviceValuesCollectionValue ( _   ' VTable offset = 152
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   , BYREF ppValue AS IPortableDeviceValuesCollection _ ' __out IPortableDeviceValuesCollection* *ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveValue ( _                               ' VTable offset = 156
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyValuesFromPropertyStore ( _               ' VTable offset = 160
     BYVAL pStore AS IPropertyStore _                   ' __in IPropertyStore* pStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyValuesToPropertyStore ( _                 ' VTable offset = 164
     BYVAL pStore AS IPropertyStore _                   ' __in IPropertyStore* pStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 168
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPortableDeviceValues_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPortableDeviceKeyCollection
' IID = {DADA2357-E0AD-492E-98DB-DD61C53BA353}
' IPortableDeviceKeyCollection Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPortableDeviceKeyCollection_INTERFACE_DEFINED)
    %IPortableDeviceKeyCollection_INTERFACE_DEFINED = 1

$IID_IPortableDeviceKeyCollection = GUID$("{DADA2357-E0AD-492E-98DB-DD61C53BA353}")

INTERFACE IPortableDeviceKeyCollection $IID_IPortableDeviceKeyCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF pcElems AS DWORD _                           ' __in DWORD* pcElems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL dwIndex AS DWORD _                           ' __in const DWORD dwIndex
   , BYREF pKey AS PROPERTYKEY _                        ' __in PROPERTYKEY* pKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Add ( _                                       ' VTable offset = 20
     BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY* key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAt ( _                                  ' VTable offset = 28
     BYVAL dwIndex AS DWORD _                           ' __in const DWORD dwIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPortableDeviceKeyCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPortableDevicePropVariantCollection
' IID = {89B2E422-4F1B-4316-BCEF-A44AFEA83EB3}
' IPortableDevicePropVariantCollection Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPortableDevicePropVariantCollection_INTERFACE_DEFINED)
    %IPortableDevicePropVariantCollection_INTERFACE_DEFINED = 1

$IID_IPortableDevicePropVariantCollection = GUID$("{89B2E422-4F1B-4316-BCEF-A44AFEA83EB3}")

INTERFACE IPortableDevicePropVariantCollection $IID_IPortableDevicePropVariantCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF pcElems AS DWORD _                           ' __in DWORD* pcElems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL dwIndex AS DWORD _                           ' __in unsigned long dwIndex
   , BYREF pValue AS PROPVARIANT _                      ' __in PROPVARIANT* pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Add ( _                                       ' VTable offset = 20
     BYREF pValue AS PROPVARIANT _                      ' __in const PROPVARIANT* pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 24
     BYREF pvt AS WORD _                                ' __out VARTYPE* pvt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ChangeType ( _                                ' VTable offset = 28
     BYVAL vt AS WORD _                                 ' __in const VARTYPE vt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAt ( _                                  ' VTable offset = 36
     BYVAL dwIndex AS DWORD _                           ' __in const DWORD dwIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPortableDevicePropVariantCollection_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPortableDeviceValuesCollection
' IID = {6E3F2D79-4E07-48C4-8208-D8C2E5AF4A99}
' IPortableDeviceValuesCollection Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPortableDeviceValuesCollection_INTERFACE_DEFINED)
    %IPortableDeviceValuesCollection_INTERFACE_DEFINED = 1

$IID_IPortableDeviceValuesCollection = GUID$("{6E3F2D79-4E07-48C4-8208-D8C2E5AF4A99}")

INTERFACE IPortableDeviceValuesCollection $IID_IPortableDeviceValuesCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF pcElems AS DWORD _                           ' __in DWORD* pcElems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL dwIndex AS DWORD _                           ' __in const DWORD dwIndex
   , BYREF ppValues AS IPortableDeviceValues _          ' __out IPortableDeviceValues** ppValues
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Add ( _                                       ' VTable offset = 20
     BYVAL pValues AS IPortableDeviceValues _           ' __in IPortableDeviceValues* pValues
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAt ( _                                  ' VTable offset = 28
     BYVAL dwIndex AS DWORD _                           ' __in const DWORD dwIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPortableDeviceValuesCollection_INTERFACE_DEFINED__ */

'#endif // (_WIN32_WINNT >= 0x0501)
