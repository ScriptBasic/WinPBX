' ########################################################################################
' Microsoft Windows
' File: REND.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: RENDLib
' Version: 1.0
' Documentation string: Microsoft Rendezvous control 1.0 Type Library
' Path: C:\WINDOWS\system32\rend.dll
' Library GUID: {F1029E4D-CB5B-11D0-8D59-00C04FD91AC0}
' ########################################################################################

#INCLUDE THIS ONCE
%REND_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "tapi3if.inc"

%IDISPDIROBJECT        = &H10000
%IDISPDIROBJCONFERENCE = &H20000
%IDISPDIROBJUSER       = &H30000
%IDISPDIRECTORY        = &H10000
%IDISPILSCONFIG        = &H20000

' enum DIRECTORY_TYPE
%DT_NTDS = 1
%DT_ILS  = 2

' enum DIRECTORY_OBJECT_TYPE
%OT_CONFERENCE = 1
%OT_USER       = 2

' enum RND_ADVERTISING_SCOPE
%RAS_LOCAL  = 1
%RAS_SITE   = 2
%RAS_REGION = 3
%RAS_WORLD  = 4

$LIBID_RENDLib = GUID$("{F1029E4D-CB5B-11D0-8D59-00C04FD91AC0}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {F1029E5B-CB5B-11D0-8D59-00C04FD91AC0}
$PROGID_RendRendezvous1 = "Rend.Rendezvous.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {F1029E5B-CB5B-11D0-8D59-00C04FD91AC0}
$PROGID_RendRendezvous = "Rend.Rendezvous"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_Rendezvous = GUID$("{F1029E5B-CB5B-11D0-8D59-00C04FD91AC0}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IEnumDialableAddrs = GUID$("{34621D70-6CFF-11D1-AFF7-00C04FC31FEE}")
$IID_IEnumDirectory = GUID$("{34621D6D-6CFF-11D1-AFF7-00C04FC31FEE}")
$IID_IEnumDirectoryObject = GUID$("{06C9B64A-306D-11D1-9774-00C04FD91AC0}")
$IID_ITDirectory = GUID$("{34621D6C-6CFF-11D1-AFF7-00C04FC31FEE}")
$IID_ITDirectoryObject = GUID$("{34621D6E-6CFF-11D1-AFF7-00C04FC31FEE}")
$IID_ITDirectoryObjectConference = GUID$("{F1029E5D-CB5B-11D0-8D59-00C04FD91AC0}")
$IID_ITDirectoryObjectUser = GUID$("{34621D6F-6CFF-11D1-AFF7-00C04FC31FEE}")
$IID_ITILSConfig = GUID$("{34621D72-6CFF-11D1-AFF7-00C04FC31FEE}")
$IID_ITRendezvous = GUID$("{34621D6B-6CFF-11D1-AFF7-00C04FC31FEE}")


' ########################################################################################
' Interface name = ITDirectoryObjectConference
' IID = {F1029E5D-CB5B-11D0-8D59-00C04FD91AC0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITDirectoryObjectConference_INTERFACE_DEFINED)
    %ITDirectoryObjectConference_INTERFACE_DEFINED = 1

INTERFACE ITDirectoryObjectConference $IID_ITDirectoryObjectConference

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Protocol <131073> ( _                   ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *ppProtocol
   ' =====================================================================================
   PROPERTY GET Originator <131074> ( _                 ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *ppOriginator
   ' =====================================================================================
   PROPERTY SET Originator <131074> ( _                 ' VTable offset = 36
     BYVAL pOriginator AS WSTRING _                     ' __in BSTR pOriginator
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AdvertisingScope <131075> ( _           ' VTable offset = 40
   ) AS LONG                                            ' __retval_out RND_ADVERTISING_SCOPE *pAdvertisingScope
   ' =====================================================================================
   PROPERTY SET AdvertisingScope <131075> ( _           ' VTable offset = 44
     BYVAL AdvertisingScope AS LONG _                   ' __in RND_ADVERTISING_SCOPE AdvertisingScope
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Url <131076> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *ppUrl
   ' =====================================================================================
   PROPERTY SET Url <131076> ( _                        ' VTable offset = 52
     BYVAL pUrl AS WSTRING _                            ' __in BSTR pUrl
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <131077> ( _                ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *ppDescription
   ' =====================================================================================
   PROPERTY SET Description <131077> ( _                ' VTable offset = 60
     BYVAL pDescription AS WSTRING _                    ' __in BSTR pDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsEncrypted <131078> ( _                ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfEncrypted
   ' =====================================================================================
   PROPERTY SET IsEncrypted <131078> ( _                ' VTable offset = 68
     BYVAL fEncrypted AS INTEGER _                      ' __in VARIANT_BOOL fEncrypted
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartTime <131079> ( _                  ' VTable offset = 72
   ) AS DOUBLE                                          ' __retval_out DATE *pDate
   ' =====================================================================================
   PROPERTY SET StartTime <131079> ( _                  ' VTable offset = 76
     BYVAL Date AS DOUBLE _                             ' __in DATE Date
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StopTime <131080> ( _                   ' VTable offset = 80
   ) AS DOUBLE                                          ' __retval_out DATE *pDate
   ' =====================================================================================
   PROPERTY SET StopTime <131080> ( _                   ' VTable offset = 84
     BYVAL Date AS DOUBLE _                             ' __in DATE Date
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITDirectoryObjectConference_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITDirectoryObjectUser
' IID = {34621D6F-6CFF-11D1-AFF7-00C04FC31FEE}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITDirectoryObjectUser_INTERFACE_DEFINED)
    %ITDirectoryObjectUser_INTERFACE_DEFINED = 1

INTERFACE ITDirectoryObjectUser $IID_ITDirectoryObjectUser

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET IPPhonePrimary <196609> ( _             ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *ppName
   ' =====================================================================================
   PROPERTY SET IPPhonePrimary <196609> ( _             ' VTable offset = 32
     BYVAL pName AS WSTRING _                           ' __in BSTR pName
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITDirectoryObjectUser_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumDialableAddrs
' IID = {34621D70-6CFF-11D1-AFF7-00C04FC31FEE}
' Attributes = 528 [&H210] [Hidden] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumDialableAddrs_INTERFACE_DEFINED)
    %IEnumDialableAddrs_INTERFACE_DEFINED = 1

INTERFACE IEnumDialableAddrs $IID_IEnumDialableAddrs

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppElements AS WSTRING _                      ' __out BSTR *ppElements
   , BYREF pcFetched AS DWORD _                         ' __in_out ULONG *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in unsigned long celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumDialableAddrs _               ' __out IEnumDialableAddrs **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumDialableAddrs_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITDirectoryObject
' IID = {34621D6E-6CFF-11D1-AFF7-00C04FC31FEE}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITDirectoryObject_INTERFACE_DEFINED)
    %ITDirectoryObject_INTERFACE_DEFINED = 1

INTERFACE ITDirectoryObject $IID_ITDirectoryObject

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ObjectType <65537> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out DIRECTORY_OBJECT_TYPE *pObjectType
   ' =====================================================================================
   PROPERTY GET Name <65538> ( _                        ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *ppName
   ' =====================================================================================
   PROPERTY SET Name <65538> ( _                        ' VTable offset = 36
     BYVAL pName AS WSTRING _                           ' __in BSTR pName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DialableAddrs <65539> ( _               ' VTable offset = 40
     BYVAL dwAddressType AS LONG _                      ' __in long dwAddressType
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD EnumerateDialableAddrs <65540> ( _            ' VTable offset = 44
     BYVAL dwAddressType AS DWORD _                     ' __in DWORD dwAddressType
   , BYREF IEnumDialableAddrs _                         ' __out IEnumDialableAddrs **ppEnumDialableAddrs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SecurityDescriptor <65541> ( _          ' VTable offset = 48
   ) AS IDispatch                                       ' __retval_out IDispatch **ppSecDes
   ' =====================================================================================
   PROPERTY SET SecurityDescriptor <65541> ( _          ' VTable offset = 52
     BYVAL pSecDes AS IDispatch _                       ' __in IDispatch *pSecDes
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITDirectoryObject_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumDirectoryObject
' IID = {06C9B64A-306D-11D1-9774-00C04FD91AC0}
' Attributes = 528 [&H210] [Hidden] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumDirectoryObject_INTERFACE_DEFINED)
    %IEnumDirectoryObject_INTERFACE_DEFINED = 1

INTERFACE IEnumDirectoryObject $IID_IEnumDirectoryObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF pVal AS ITDirectoryObject _                  ' __out ITDirectoryObject **pVal
   , BYREF pcFetched AS DWORD _                         ' __in_out ULONG *pcFetched
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
     BYREF ppEnum AS IEnumDirectoryObject _             ' __retval_out IEnumDirectoryObject **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumDirectoryObject_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITILSConfig
' IID = {34621D72-6CFF-11D1-AFF7-00C04FC31FEE}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITILSConfig_INTERFACE_DEFINED)
    %ITILSConfig_INTERFACE_DEFINED = 1

INTERFACE ITILSConfig $IID_ITILSConfig

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Port <131073> ( _                       ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pPort
   ' =====================================================================================
   PROPERTY SET Port <131073> ( _                       ' VTable offset = 32
     BYVAL Port AS LONG _                               ' __in long Port
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITILSConfig_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITDirectory
' IID = {34621D6C-6CFF-11D1-AFF7-00C04FC31FEE}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITDirectory_INTERFACE_DEFINED)
    %ITDirectory_INTERFACE_DEFINED = 1

INTERFACE ITDirectory $IID_ITDirectory

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DirectoryType <65537> ( _               ' VTable offset = 28
   ) AS LONG                                            ' __retval_out DIRECTORY_TYPE *pDirectoryType
   ' =====================================================================================
   PROPERTY GET DisplayName <65538> ( _                 ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pName
   ' =====================================================================================
   PROPERTY GET IsDynamic <65539> ( _                   ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfDynamic
   ' =====================================================================================
   PROPERTY GET DefaultObjectTTL <65540> ( _            ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *pTTL
   ' =====================================================================================
   PROPERTY SET DefaultObjectTTL <65540> ( _            ' VTable offset = 44
     BYVAL TTL AS LONG _                                ' __in long TTL
   )                                                    ' void
   ' =====================================================================================
   METHOD EnableAutoRefresh <65541> ( _                 ' VTable offset = 48
     BYVAL fEnable AS INTEGER _                         ' __in VARIANT_BOOL fEnable
   )                                                    ' void
   ' =====================================================================================
   METHOD Connect <65542> ( _                           ' VTable offset = 52
     BYVAL fSecure AS INTEGER _                         ' __in VARIANT_BOOL fSecure
   )                                                    ' void
   ' =====================================================================================
   METHOD Bind <65543> ( _                              ' VTable offset = 56
     BYVAL pDomainName AS WSTRING _                     ' __in BSTR pDomainName
   , BYVAL pUserName AS WSTRING _                       ' __in BSTR pUserName
   , BYVAL pPassword AS WSTRING _                       ' __in BSTR pPassword
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD AddDirectoryObject <65544> ( _                ' VTable offset = 60
     BYVAL pDirectoryObject AS ITDirectoryObject _      ' __in ITDirectoryObject *pDirectoryObject
   )                                                    ' void
   ' =====================================================================================
   METHOD ModifyDirectoryObject <65545> ( _             ' VTable offset = 64
     BYVAL pDirectoryObject AS ITDirectoryObject _      ' __in ITDirectoryObject *pDirectoryObject
   )                                                    ' void
   ' =====================================================================================
   METHOD RefreshDirectoryObject <65546> ( _            ' VTable offset = 68
     BYVAL pDirectoryObject AS ITDirectoryObject _      ' __in ITDirectoryObject *pDirectoryObject
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDirectoryObject <65547> ( _             ' VTable offset = 72
     BYVAL pDirectoryObject AS ITDirectoryObject _      ' __in ITDirectoryObject *pDirectoryObject
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DirectoryObjects <65548> ( _            ' VTable offset = 76
     BYVAL DirectoryObjectType AS LONG _                ' __in DIRECTORY_OBJECT_TYPE DirectoryObjectType
   , BYVAL pName AS WSTRING _                           ' __in BSTR pName
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD EnumerateDirectoryObjects <65549> ( _         ' VTable offset = 80
     BYVAL DirectoryObjectType AS LONG _                ' __in DIRECTORY_OBJECT_TYPE DirectoryObjectType
   , BYVAL pName AS WSTRING _                           ' __in BSTR pName
   , BYREF ppEnumObject AS IEnumDirectoryObject _       ' __out IEnumDirectoryObject **ppEnumObject
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITDirectory_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumDirectory
' IID = {34621D6D-6CFF-11D1-AFF7-00C04FC31FEE}
' Attributes = 528 [&H210] [Hidden] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumDirectory_INTERFACE_DEFINED)
    %IEnumDirectory_INTERFACE_DEFINED = 1

INTERFACE IEnumDirectory $IID_IEnumDirectory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppElements AS ITDirectory _                  ' __out ITDirectory **ppElements
   , BYREF pcFetched AS DWORD _                         ' __in_out ULONG *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
  ) AS LONG                                             ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumDirectory _                   ' __retval_out IEnumDirectory **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumDirectory_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITRendezvous
' IID = {34621D6B-6CFF-11D1-AFF7-00C04FC31FEE}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITRendezvous_INTERFACE_DEFINED)
    %ITRendezvous_INTERFACE_DEFINED = 1

INTERFACE ITRendezvous $IID_ITRendezvous

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DefaultDirectories <1> ( _              ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD EnumerateDefaultDirectories <2> ( _           ' VTable offset = 32
     BYREF ppEnumDirectory AS IEnumDirectory _          ' __out IEnumDirectory **ppEnumDirectory
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateDirectory <3> ( _                       ' VTable offset = 36
     BYVAL DirectoryType AS LONG _                      ' __in DIRECTORY_TYPE DirectoryType
   , BYVAL pName AS WSTRING _                           ' __in BSTR pName
   ) AS ITDirectory                                     ' __retval_out ITDirectory **ppDir
   ' =====================================================================================
   METHOD CreateDirectoryObject <4> ( _                 ' VTable offset = 40
     BYVAL DirectoryObjectType AS LONG _                ' __in DIRECTORY_OBJECT_TYPE DirectoryObjectType
   , BYVAL pName AS WSTRING _                           ' __in BSTR pName
   ) AS ITDirectoryObject                               ' __retval_out ITDirectoryObject **ppDirectoryObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITRendezvous_INTERFACE_DEFINED__ */

#IF NOT %DEF(%RendConstants_MODULE_DEFINED)
    %RendConstants_MODULE_DEFINED = 1

%RENDBIND_AUTHENTICATE       = &H00000001&
%RENDBIND_DEFAULTDOMAINNAME  = &H00000002&
%RENDBIND_DEFAULTUSERNAME    = &H00000004&
%RENDBIND_DEFAULTPASSWORD    = &H00000008&
'/* this is just the previous three |'ed together for convenience. */
%RENDBIND_DEFAULTCREDENTIALS = &H0000000e&

#ENDIF   ' /* __RendConstants_MODULE_DEFINED__ */
