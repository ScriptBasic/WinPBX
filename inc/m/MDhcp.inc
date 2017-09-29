' ########################################################################################
' Microsoft Windows
' File: MDhcp.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: McastLib
' Version: 1.0, Locale ID = 0
' Documentation string: Microsoft Multicast Address Allocation Client COM Wrapper 1.0 Type Library
' Path: C:\WINDOWS\system32\mdhcp.dll
' Library GUID: {64217CC0-A285-11D1-8697-006008B0E5D2}
' ########################################################################################

#INCLUDE THIS ONCE
%MDHCP_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "tapi3if.inc"

$LIBID_McastLib = GUID$("{64217CC0-A285-11D1-8697-006008B0E5D2}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {DF0DAEF2-A289-11D1-8697-006008B0E5D2}
$PROGID_MdhcpMDhcp1 = "Mdhcp.MDhcp.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {DF0DAEF2-A289-11D1-8697-006008B0E5D2}
$PROGID_MdhcpMDhcp = "Mdhcp.MDhcp"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_McastAddressAllocation = GUID$("{DF0DAEF2-A289-11D1-8697-006008B0E5D2}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IEnumBstr = GUID$("{35372049-0BC6-11D2-A033-00C04FB6809F}")
$IID_IEnumMcastScope = GUID$("{DF0DAF09-A289-11D1-8697-006008B0E5D2}")
$IID_IMcastAddressAllocation = GUID$("{DF0DAEF1-A289-11D1-8697-006008B0E5D2}")
$IID_IMcastLeaseInfo = GUID$("{DF0DAEFD-A289-11D1-8697-006008B0E5D2}")
$IID_IMcastScope = GUID$("{DF0DAEF4-A289-11D1-8697-006008B0E5D2}")


' ########################################################################################
' Interface name = IMcastScope
' IID = {DF0DAEF4-A289-11D1-8697-006008B0E5D2}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMcastScope_INTERFACE_DEFINED)
    %IMcastScope_INTERFACE_DEFINED = 1

INTERFACE IMcastScope $IID_IMcastScope

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ScopeID <1> ( _                         ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pID
   ' =====================================================================================
   PROPERTY GET ServerID <2> ( _                        ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pID
   ' =====================================================================================
   PROPERTY GET InterfaceID <3> ( _                     ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *pID
   ' =====================================================================================
   PROPERTY GET ScopeDescription <4> ( _                ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *ppDescription
   ' =====================================================================================
   PROPERTY GET TTL <5> ( _                             ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *pTTL
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMcastScope_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMcastLeaseInfo
' IID = {DF0DAEFD-A289-11D1-8697-006008B0E5D2}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMcastLeaseInfo_INTERFACE_DEFINED)
    %IMcastLeaseInfo_INTERFACE_DEFINED = 1

INTERFACE IMcastLeaseInfo $IID_IMcastLeaseInfo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET RequestID <1> ( _                       ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *ppRequestID
   ' =====================================================================================
   PROPERTY GET LeaseStartTime <2> ( _                  ' VTable offset = 32
   ) AS DOUBLE                                          ' __retval_out DATE *pTime
   ' =====================================================================================
   PROPERTY SET LeaseStartTime <2> ( _                  ' VTable offset = 36
     BYVAL time AS DOUBLE _                             ' __in DATE time
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LeaseStopTime <3> ( _                   ' VTable offset = 40
   ) AS DOUBLE                                          ' __retval_out DATE *pTime
   ' =====================================================================================
   PROPERTY SET LeaseStopTime <3> ( _                   ' VTable offset = 44
     BYVAL time AS DOUBLE _                             ' __in DATE time
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AddressCount <4> ( _                    ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *pCount
   ' =====================================================================================
   PROPERTY GET ServerAddress <5> ( _                   ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *ppAddress
   ' =====================================================================================
   PROPERTY GET TTL <6> ( _                             ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *pTTL
   ' =====================================================================================
   PROPERTY GET Addresses <7> ( _                       ' VTable offset = 60
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD EnumerateAddresses <8> ( _                    ' VTable offset = 64
   ) AS IEnumBstr                                       ' __retval_out IEnumBstr **ppEnumAddresses
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMcastLeaseInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumMcastScope
' IID = {DF0DAF09-A289-11D1-8697-006008B0E5D2}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumMcastScope_INTERFACE_DEFINED)
    %IEnumMcastScope_INTERFACE_DEFINED = 1

INTERFACE IEnumMcastScope $IID_IEnumMcastScope

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppScopes AS IMcastScope _                    ' __out IMcastScope **ppScopes
   , BYREF pceltFetched AS DWORD _                      ' __inout ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumMcastScope _                  ' __retval_out IEnumMcastScope **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumMcastScope_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMcastAddressAllocation
' IID = {DF0DAEF1-A289-11D1-8697-006008B0E5D2}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMcastAddressAllocation_INTERFACE_DEFINED)
    %IMcastAddressAllocation_INTERFACE_DEFINED = 1

INTERFACE IMcastAddressAllocation $IID_IMcastAddressAllocation

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Scopes <1> ( _                          ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD EnumerateScopes <2> ( _                       ' VTable offset = 32
     BYREF ppEnumMcastScope AS IEnumMcastScope _        ' __out IEnumMcastScope **ppEnumMcastScope
   )                                                    ' void
   ' =====================================================================================
   METHOD RequestAddress <3> ( _                        ' VTable offset = 36
     BYVAL pScope AS IMcastScope _                      ' __in IMcastScope *pScope
   , BYVAL LeaseStartTime AS DOUBLE _                   ' __in DATE LeaseStartTime
   , BYVAL LeaseStopTime AS DOUBLE _                    ' __in DATE LeaseStopTime
   , BYVAL NumAddresses AS LONG _                       ' __in long NumAddresses
   ) AS IMcastLeaseInfo                                 ' __retval_out IMcastLeaseInfo **ppLeaseResponse
   ' =====================================================================================
   METHOD RenewAddress <4> ( _                          ' VTable offset = 40
     BYVAL lReserved AS LONG _                          ' __in long lReserved
   , BYVAL pRenewRequest AS IMcastLeaseInfo _           ' __in IMcastLeaseInfo *pRenewRequest
   ) AS IMcastLeaseInfo                                 ' __retval_out IMcastLeaseInfo **ppRenewResponse
   ' =====================================================================================
   METHOD ReleaseAddress <5> ( _                        ' VTable offset = 44
     BYVAL pReleaseRequest AS IMcastLeaseInfo _         ' __in IMcastLeaseInfo *pReleaseRequest
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateLeaseInfo <6> ( _                       ' VTable offset = 48
     BYVAL LeaseStartTime AS DOUBLE _                   ' __in DATE LeaseStartTime
   , BYVAL LeaseStopTime AS DOUBLE _                    ' __in DATE LeaseStopTime
   , BYVAL dwNumAddresses AS DWORD _                    ' __in DWORD dwNumAddresses
   , BYREF ppAddresses AS DWORD _                       ' __in LPWSTR *ppAddresses
   , BYREF pRequestID AS WSTRINGZ _                     ' __in LPWSTR pRequestID
   , BYREF pServerAddress AS WSTRINGZ _                 ' __in LPWSTR pServerAddress
   ) AS IMcastLeaseInfo                                 ' __retval_out IMcastLeaseInfo **ppReleaseRequest
   ' =====================================================================================
   METHOD CreateLeaseInfoFromVariant <7> ( _            ' VTable offset = 52
     BYVAL LeaseStartTime AS DOUBLE _                   ' __in DATE LeaseStartTime
   , BYVAL LeaseStopTime AS DOUBLE _                    ' __in DATE LeaseStopTime
   , BYVAL vAddresses AS VARIANT _                      ' __in VARIANT vAddresses
   , BYVAL pRequestID AS WSTRING _                      ' __in BSTR pRequestID
   , BYVAL pServerAddress AS WSTRING _                  ' __in BSTR pServerAddress
   ) AS IMcastLeaseInfo                                 ' __retval_out IMcastLeaseInfo **ppReleaseRequest
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMcastAddressAllocation_INTERFACE_DEFINED__ */
