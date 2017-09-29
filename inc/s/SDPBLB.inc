' ########################################################################################
' Microsoft Windows
' File: sdpblb.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: SDPBLBLib
' Version: 1.0
' Documentation string: Microsoft Sdpblb 1.0 Type Library
' Path: C:\WINDOWS\system32\sdpblb.dll
' Library GUID: {C259D79A-C8AB-11D0-8D58-00C04FD91AC0}
' ########################################################################################

#INCLUDE THIS ONCE
%SDPBLB_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

$LIBID_SDPBLBLib = GUID$("{C259D79A-C8AB-11D0-8D58-00C04FD91AC0}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {9B2719DD-B696-11D0-A489-00C04FD91AC0}
$PROGID_SdpConferenceBlobSdpConferenceBlob1 = "SdpConferenceBlob.SdpConferenceBlob.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {9B2719DD-B696-11D0-A489-00C04FD91AC0}
$PROGID_SdpConferenceBlobSdpConferenceBlob = "SdpConferenceBlob.SdpConferenceBlob"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_SdpConferenceBlob = GUID$("{9B2719DD-B696-11D0-A489-00C04FD91AC0}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IEnumMedia = GUID$("{CA8397BE-2FA4-11D1-9774-00C04FD91AC0}")
$IID_IEnumTime = GUID$("{9055322E-2FA8-11D1-9774-00C04FD91AC0}")
$IID_ITAttributeList = GUID$("{5037FB82-CAE9-11D0-8D58-00C04FD91AC0}")
$IID_ITConferenceBlob = GUID$("{C259D7AA-C8AB-11D0-8D58-00C04FD91AC0}")
$IID_ITConnection = GUID$("{8FA381D4-C8C2-11D0-8D58-00C04FD91AC0}")
$IID_ITMedia = GUID$("{0CC1F053-CAEB-11D0-8D58-00C04FD91AC0}")
$IID_ITMediaCollection = GUID$("{6A8E16A2-0ABC-11D1-976D-00C04FD91AC0}")
$IID_ITSdp = GUID$("{9B2719D8-B696-11D0-A489-00C04FD91AC0}")
$IID_ITTime = GUID$("{2652BB78-1516-11D1-9771-00C04FD91AC0}")
$IID_ITTimeCollection = GUID$("{0CC1F04F-CAEB-11D0-8D58-00C04FD91AC0}")


%IDISPCONFBLOB   = &H10000
%IDISPSDP        = &H20000
%IDISPCONNECTION = &H30000
%IDISPATTRLIST   = &H40000
%IDISPMEDIA      = &H50000

' enum BLOB_CHARACTER_SET
%BCS_ASCII = 1
%BCS_UTF7  = 2
%BCS_UTF8  = 3


' ########################################################################################
' Interface name = ITConferenceBlob
' IID = {C259D7AA-C8AB-11D0-8D58-00C04FD91AC0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITConferenceBlob_INTERFACE_DEFINED)
    %ITConferenceBlob_INTERFACE_DEFINED = 1

INTERFACE ITConferenceBlob $IID_ITConferenceBlob

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Init <65537> ( _                              ' VTable offset = 28
     BYVAL pName AS WSTRING _                           ' __in BSTR pName
   , BYVAL CharacterSet AS LONG _                       ' __in BLOB_CHARACTER_SET CharacterSet
   , BYVAL pBlob AS WSTRING _                           ' __in BSTR pBlob
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CharacterSet <65538> ( _                ' VTable offset = 32
   ) AS LONG                                            ' __retval_out BLOB_CHARACTER_SET *pCharacterSet
   ' =====================================================================================
   PROPERTY GET ConferenceBlob <65539> ( _              ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *ppBlob
   ' =====================================================================================
   METHOD SetConferenceBlob <65540> ( _                 ' VTable offset = 40
     BYVAL CharacterSet AS LONG _                       ' __in BLOB_CHARACTER_SET CharacterSet
   , BYVAL pBlob AS WSTRING _                           ' __in BSTR pBlob
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITConferenceBlob_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITMedia
' IID = {0CC1F053-CAEB-11D0-8D58-00C04FD91AC0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITMedia_INTERFACE_DEFINED)
    %ITMedia_INTERFACE_DEFINED = 1

INTERFACE ITMedia $IID_ITMedia

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET MediaName <327681> ( _                  ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *ppMediaName
   ' =====================================================================================
   PROPERTY SET MediaName <327681> ( _                  ' VTable offset = 32
     BYVAL pMediaName AS WSTRING _                      ' __in BSTR pMediaName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartPort <327682> ( _                  ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *pStartPort
   ' =====================================================================================
   PROPERTY GET NumPorts <327683> ( _                   ' VTable offset = 40
   ) AS LONG                                            ' __retval_out LONG *pNumPorts
   ' =====================================================================================
   PROPERTY GET TransportProtocol <327684> ( _          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *ppProtocol
   ' =====================================================================================
   PROPERTY SET TransportProtocol <327684> ( _          ' VTable offset = 48
     BYVAL pProtocol AS WSTRING _                       ' __in BSTR pProtocol
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FormatCodes <327685> ( _                ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY SET FormatCodes <327685> ( _                ' VTable offset = 56
     BYVAL NewVal AS VARIANT _                          ' __in VARIANT NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaTitle <327686> ( _                 ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *ppMediaTitle
   ' =====================================================================================
   PROPERTY SET MediaTitle <327686> ( _                 ' VTable offset = 64
     BYVAL pMediaTitle AS WSTRING _                     ' __in BSTR pMediaTitle
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPortInfo <327687> ( _                      ' VTable offset = 68
     BYVAL StartPort AS LONG _                          ' __in LONG StartPort
   , BYVAL NumPorts AS LONG _                           ' __in LONG NumPorts
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITMedia_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumMedia
' IID = {CA8397BE-2FA4-11D1-9774-00C04FD91AC0}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumMedia_INTERFACE_DEFINED)
    %IEnumMedia_INTERFACE_DEFINED = 1

INTERFACE IEnumMedia $IID_IEnumMedia

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF pVal AS ITMedia _                            ' __out ITMedia **pVal
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
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
     BYREF ppEnum AS IEnumMedia _                       ' __retval_out IEnumMedia **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumMedia_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITMediaCollection
' IID = {6A8E16A2-0ABC-11D1-976D-00C04FD91AC0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITMediaCollection_INTERFACE_DEFINED)
    %ITMediaCollection_INTERFACE_DEFINED = 1

INTERFACE ITMediaCollection $IID_ITMediaCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS ITMedia                                         ' __retval_out ITMedia **pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **pVal
   ' =====================================================================================
   PROPERTY GET EnumerationIf <1> ( _                   ' VTable offset = 40
   ) AS IEnumMedia                                      ' __retval_out IEnumMedia **pVal
   ' =====================================================================================
   METHOD Create <2> ( _                                ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS ITMedia                                         ' __retval_out ITMedia **ppMedia
   ' =====================================================================================
   METHOD Delete <3> ( _                                ' VTable offset = 48
     BYVAL Index AS LONG _                              ' __in LONG Index
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITMediaCollection_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITTime
' IID = {2652BB78-1516-11D1-9771-00C04FD91AC0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITTime_INTERFACE_DEFINED)
    %ITTime_INTERFACE_DEFINED = 1

INTERFACE ITTime $IID_ITTime

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET StartTime <1> ( _                       ' VTable offset = 28
   ) AS DOUBLE                                          ' __retval_out DOUBLE *pTime
   ' =====================================================================================
   PROPERTY SET StartTime <1> ( _                       ' VTable offset = 32
     BYVAL Time AS DOUBLE _                             ' __in DOUBLE Time
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StopTime <2> ( _                        ' VTable offset = 36
   ) AS DOUBLE                                          ' __retval_out DOUBLE *pTime
   ' =====================================================================================
   PROPERTY SET StopTime <2> ( _                        ' VTable offset = 40
     BYVAL Time AS DOUBLE _                             ' __in DOUBLE Time
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITTime_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumTime
' IID = {9055322E-2FA8-11D1-9774-00C04FD91AC0}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumTime_INTERFACE_DEFINED)
    %IEnumTime_INTERFACE_DEFINED = 1

INTERFACE IEnumTime $IID_IEnumTime

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF pVal AS ITTime _                             ' __out ITTime **pVal
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
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
     BYREF ppEnum AS IEnumTime _                        ' __retval_out IEnumTime **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumTime_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITTimeCollection
' IID = {0CC1F04F-CAEB-11D0-8D58-00C04FD91AC0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITTimeCollection_INTERFACE_DEFINED)
    %ITTimeCollection_INTERFACE_DEFINED = 1

INTERFACE ITTimeCollection $IID_ITTimeCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS ITTime                                          ' __retval_out ITTime **pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **pVal
   ' =====================================================================================
   PROPERTY GET EnumerationIf <1> ( _                   ' VTable offset = 40
   ) AS IEnumTime                                       ' __retval_out IEnumTime **pVal
   ' =====================================================================================
   METHOD Create <2> ( _                                ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS ITTime                                          ' __retval_out ITTime **ppTime
   ' =====================================================================================
   METHOD Delete <3> ( _                                ' VTable offset = 48
     BYVAL Index AS LONG _                              ' __in LONG Index
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITTimeCollection_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITSdp
' IID = {9B2719D8-B696-11D0-A489-00C04FD91AC0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITSdp_INTERFACE_DEFINED)
    %ITSdp_INTERFACE_DEFINED = 1

INTERFACE ITSdp $IID_ITSdp

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET IsValid <131073> ( _                    ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfIsValid
   ' =====================================================================================
   PROPERTY GET ProtocolVersion <131074> ( _            ' VTable offset = 32
   ) AS BYTE                                            ' __retval_out unsigned char *pProtocolVersion
   ' =====================================================================================
   PROPERTY GET SessionId <131075> ( _                  ' VTable offset = 36
   ) AS DOUBLE                                          ' __retval_out DOUBLE *pSessionId
   ' =====================================================================================
   PROPERTY GET SessionVersion <131076> ( _             ' VTable offset = 40
   ) AS DOUBLE                                          ' __retval_out DOUBLE *pSessionVersion
   ' =====================================================================================
   PROPERTY SET SessionVersion <131076> ( _             ' VTable offset = 44
     BYVAL SessionVersion AS DOUBLE _                   ' __in DOUBLE SessionVersion
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MachineAddress <131077> ( _             ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *ppMachineAddress
   ' =====================================================================================
   PROPERTY SET MachineAddress <131077> ( _             ' VTable offset = 52
     BYVAL pMachineAddress AS WSTRING _                 ' __in BSTR pMachineAddress
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <131078> ( _                       ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *ppName
   ' =====================================================================================
   PROPERTY SET Name <131078> ( _                       ' VTable offset = 60
     BYVAL pName AS WSTRING _                           ' __in BSTR pName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <131079> ( _                ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *ppDescription
   ' =====================================================================================
   PROPERTY SET Description <131079> ( _                ' VTable offset = 68
     BYVAL pDescription AS WSTRING _                    ' __in BSTR pDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Url <131080> ( _                        ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *ppUrl
   ' =====================================================================================
   PROPERTY SET Url <131080> ( _                        ' VTable offset = 76
     BYVAL pUrl AS WSTRING _                            ' __in BSTR pUrl
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEmailNames <131081> ( _                    ' VTable offset = 80
     BYREF pAddresses AS VARIANT _                      ' __out VARIANT *pAddresses
   , BYREF pNames AS VARIANT _                          ' __out VARIANT *pNames
   )                                                    ' void
   ' =====================================================================================
   METHOD SetEmailNames <131082> ( _                    ' VTable offset = 84
     BYVAL Addresses AS VARIANT _                       ' __in VARIANT Addresses
   , BYVAL Names AS VARIANT _                           ' __in VARIANT Names
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPhoneNumbers <131083> ( _                  ' VTable offset = 88
     BYREF pNumbers AS VARIANT _                        ' __out VARIANT *pNumbers
   , BYREF pNames AS VARIANT _                          ' __out VARIANT *pNames
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPhoneNumbers <131084> ( _                  ' VTable offset = 92
     BYVAL Numbers AS VARIANT _                         ' __in VARIANT Numbers
   , BYVAL Names AS VARIANT _                           ' __in VARIANT Names
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Originator <131085> ( _                 ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *ppOriginator
   ' =====================================================================================
   PROPERTY SET Originator <131085> ( _                 ' VTable offset = 100
     BYVAL pOriginator AS WSTRING _                     ' __in BSTR pOriginator
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaCollection <131086> ( _            ' VTable offset = 104
   ) AS ITMediaCollection                               ' __retval_out ITMediaCollection **ppMediaCollection
   ' =====================================================================================
   PROPERTY GET TimeCollection <131087> ( _             ' VTable offset = 108
   ) AS ITTimeCollection                                ' __retval_out ITTimeCollection **ppTimeCollection
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITSdp_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITConnection
' IID = {8FA381D4-C8C2-11D0-8D58-00C04FD91AC0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITConnection_INTERFACE_DEFINED)
    %ITConnection_INTERFACE_DEFINED = 1

INTERFACE ITConnection $IID_ITConnection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NetworkType <196609> ( _                ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *ppNetworkType
   ' =====================================================================================
   PROPERTY SET NetworkType <196609> ( _                ' VTable offset = 32
     BYVAL pNetworkType AS WSTRING _                    ' __in BSTR pNetworkType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AddressType <196610> ( _                ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *ppAddressType
   ' =====================================================================================
   PROPERTY SET AddressType <196610> ( _                ' VTable offset = 40
     BYVAL pAddressType AS WSTRING _                    ' __in BSTR pAddressType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartAddress <196611> ( _               ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *ppStartAddress
   ' =====================================================================================
   PROPERTY GET NumAddresses <196612> ( _               ' VTable offset = 48
   ) AS LONG                                            ' __retval_out LONG *pNumAddresses
   ' =====================================================================================
   PROPERTY GET Ttl <196613> ( _                        ' VTable offset = 52
   ) AS BYTE                                            ' __retval_out unsigned char *pTtl
   ' =====================================================================================
   PROPERTY GET BandwidthModifier <196614> ( _          ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *ppModifier
   ' =====================================================================================
   PROPERTY GET Bandwidth <196615> ( _                  ' VTable offset = 60
   ) AS DOUBLE                                          ' __retval_out DOUBLE *pBandwidth
   ' =====================================================================================
   METHOD SetAddressInfo <196616> ( _                   ' VTable offset = 64
     BYVAL pStartAddress AS WSTRING _                   ' __in BSTR pStartAddress
   , BYVAL NumAddresses AS LONG _                       ' __in LONG NumAddresses
   , BYVAL Ttl AS BYTE _                                ' __in unsigned char Ttl
   )                                                    ' void
   ' =====================================================================================
   METHOD SetBandwidthInfo <196617> ( _                 ' VTable offset = 68
     BYVAL pModifier AS WSTRING _                       ' __in BSTR pModifier
   , BYVAL Bandwidth AS DOUBLE _                        ' __in DOUBLE Bandwidth
   )                                                    ' void
   ' =====================================================================================
   METHOD SetEncryptionKey <196618> ( _                 ' VTable offset = 72
     BYVAL pKeyType AS WSTRING _                        ' __in BSTR pKeyType
   , BYREF ppKeyData AS WSTRING _                       ' __in BSTR *ppKeyData
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEncryptionKey <196619> ( _                 ' VTable offset = 76
     BYREF ppKeyType AS WSTRING _                       ' __out BSTR *ppKeyType
   , BYREF pfValidKeyData AS INTEGER _                  ' __out VARIANT_BOOL *pfValidKeyData
   , BYREF ppKeyData AS WSTRING _                       ' __out BSTR *ppKeyData
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITConnection_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITAttributeList
' IID = {5037FB82-CAE9-11D0-8D58-00C04FD91AC0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITAttributeList_INTERFACE_DEFINED)
    %ITAttributeList_INTERFACE_DEFINED = 1

INTERFACE ITAttributeList $IID_ITAttributeList

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <262145> ( _                      ' VTable offset = 28
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET Item <262146> ( _                       ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD Add <262147> ( _                              ' VTable offset = 36
     BYVAL Index AS LONG _                              ' __in LONG Index
   , BYVAL pAttribute AS WSTRING _                      ' __in BSTR pAttribute
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <262148> ( _                           ' VTable offset = 40
     BYVAL Index AS LONG _                              ' __in LONG Index
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AttributeList <262149> ( _              ' VTable offset = 44
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY SET AttributeList <262149> ( _              ' VTable offset = 48
     BYVAL newVal AS VARIANT _                          ' __in VARIANT newVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITAttributeList_INTERFACE_DEFINED__ */
