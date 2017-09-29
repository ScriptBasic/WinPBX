' ########################################################################################
' Microsoft Windows
' File: wmdrmsdk.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: WMDRMContentEnablerLib
' Version: 1.0, Locale ID = 0
' Library GUID: {82435BE0-F7C1-4DF9-8103-EEABEBF3D6E1}
' ########################################################################################

#INCLUDE THIS ONCE
%WMDRMSDK_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "mfobjects.inc"
#INCLUDE ONCE "mfidl.inc"

#IF NOT %DEF(%WMDRMContentEnablerLib_LIBRARY_DEFINED)
    %WMDRMContentEnablerLib_LIBRARY_DEFINED = 1

' IID LIBID_WMDRMContentEnablerLib;
$LIBID_WMDRMContentEnablerLib = GUID$("{82435BE0-F7C1-4DF9-8103-EEABEBF3D6E1}")
$CLSID_WMDRMContentEnablerActivate = GUID$("{82435BDF-F7C1-4DF9-8103-EEABEBF3D6E1}")

#ENDIF   ' /* __WMDRMContentEnablerLib_LIBRARY_DEFINED__ */

$$g_wszWMDRM_ACTIONLIST_TAG                     = "ACTIONLIST"$$
$$g_wszWMDRM_ACTION_TAG                         = "ACTION"$$
$$g_wszWMDRM_RIGHT_PLAYBACK                     = "Play"$$
$$g_wszWMDRM_RIGHT_COPY                         = "Copy"$$
$$g_wszWMDRM_RIGHT_PLAYLIST_BURN                = "PlaylistBurn"$$
$$g_wszWMDRM_RIGHT_CREATE_THUMBNAIL_IMAGE       = "CreateThumbnailImage"$$
$$g_wszWMDRM_RIGHT_COPY_TO_CD                   = "Print.redbook"$$
$$g_wszWMDRM_RIGHT_COPY_TO_SDMI_DEVICE          = "Transfer.SDMI"$$
$$g_wszWMDRM_RIGHT_COPY_TO_NON_SDMI_DEVICE      = "Transfer.NONSDMI"$$
$$g_wszWMDRM_RIGHT_BACKUP                       = "Backup"$$
$$g_wszWMDRM_RIGHT_COLLABORATIVE_PLAY           = "CollaborativePlay"$$
$$g_wszWMDRM_ActionAllowed                      = "ActionAllowed."$$
$$g_wszWMDRM_ActionAllowed_Playback             = "ActionAllowed.Play"$$
$$g_wszWMDRM_ActionAllowed_Copy                 = "ActionAllowed.Copy"$$
$$g_wszWMDRM_ActionAllowed_PlaylistBurn         = "ActionAllowed.PlaylistBurn"$$
$$g_wszWMDRM_ActionAllowed_CreateThumbnailImage = "ActionAllowed.CreateThumbnailImage"$$
$$g_wszWMDRM_ActionAllowed_CopyToCD             = "ActionAllowed.Print.redbook"$$
$$g_wszWMDRM_ActionAllowed_CopyToSDMIDevice     = "ActionAllowed.Transfer.SDMI"$$
$$g_wszWMDRM_ActionAllowed_CopyToNonSDMIDevice  = "ActionAllowed.Transfer.NONSDMI"$$
$$g_wszWMDRM_ActionAllowed_Backup               = "ActionAllowed.Backup"$$
$$g_wszWMDRM_ActionAllowed_CollaborativePlay    = "ActionAllowed.CollaborativePlay"$$
$$g_wszWMDRM_LicenseState                       = "LicenseStateData."$$
$$g_wszWMDRM_LicenseState_Playback              = "LicenseStateData.Play"$$
$$g_wszWMDRM_LicenseState_Copy                  = "LicenseStateData.Copy"$$
$$g_wszWMDRM_LicenseState_PlaylistBurn          = "LicenseStateData.PlaylistBurn"$$
$$g_wszWMDRM_LicenseState_CreateThumbnailImage  = "LicenseStateData.CreateThumbnailImage"$$
$$g_wszWMDRM_LicenseState_CopyToCD              = "LicenseStateData.Print.redbook"$$
$$g_wszWMDRM_LicenseState_CopyToSDMIDevice      = "LicenseStateData.Transfer.SDMI"$$
$$g_wszWMDRM_LicenseState_CopyToNonSDMIDevice   = "LicenseStateData.Transfer.NONSDMI"$$
$$g_wszWMDRM_LicenseState_Backup                = "LicenseStateData.Backup"$$
$$g_wszWMDRM_LicenseState_CollaborativePlay     = "LicenseStateData.CollaborativePlay"$$
$$g_wszWMDRMNET_Revocation                      = "WMDRMNET_REVOCATION"$$
$$g_wszWMDRM_SAPLEVEL                           = "SAPLEVE"$$
$$g_wszWMDRM_SAPRequired                        = "SAPRequired"$$
$$g_wszWMDRM_SOURCEID_                          = "SOURCEID"$$   ' // Added a "_" because conflicts with g_wszWMDRM_SourceID in wmsdkidl.inc
$$g_wszWMDRM_PRIORITY                           = "PRIORITY"$$
$$g_wszWMDRM_ISSUEDATE                          = "ISSUEDATE"$$
$$g_wszWMDRM_UplinkID                           = "UplinkID"$$
$$g_wszWMDRM_REVINFOVERSION                     = "REVINFOVERSION"$$

%DRM_LICENSE_STATE_DATA_VAGUE              = 1
%DRM_LICENSE_STATE_DATA_OPL_PRESENT        = 2
%DRM_LICENSE_STATE_DATA_SAP_PRESENT        = 4
%WMDRM_BACKUP_OVERWRITE                    = &H00000001???
%WMDRM_RESTORE_INDIVIDUALIZE               = &H00000002???
%WMDRM_SECURITY_PERFORM_INDIV              = &H00000001???
%WMDRM_SECURITY_PERFORM_REVOCATION_REFRESH = &H00000002???
%WMDRM_SECURITY_PERFORM_FORCE_INDIV        = &H00000004???
%WMDRM_LICENSE_TYPE_XML                    = &H00000001???
%WMDRM_LICENSE_TYPE_XMR                    = &H00000002???
%WMDRM_CERTIFICATE_TYPE_V1                 = &H00000001???
%WMDRM_CERTIFICATE_TYPE_V2                 = &H00000002???
%WMDRM_ACQUIRE_LICENSE_SILENT              = &H00000001???
%WMDRM_ACQUIRE_LICENSE_NONSILENT           = &H00000002???
%WMDRM_ACQUIRE_LICENSE_LEGACY_NONSILENT    = &H00000004???
%WMDRM_DELETE_LICENSE_IMMEDIATELY          = &H00000001???
%WMDRM_DELETE_LICENSE_MARK_FOR_PURGE       = &H00000002???
%WMDRM_CLEAN_LICENSE_STORE_SYNC            = &H00000001???
%WMDRM_CLEAN_LICENSE_STORE_ASYNC           = &H00000002???
%WMDRM_CERTIFICATE_TYPE_XML                = 1
%WMDRM_PROTECTION_TYPE_RC4                 = 1

$WMDRM_REVOCATIONTYPE_APP     = GUID$("{90A37313-0ECF-4CAA-A906-B188F6129300}")
$WMDRM_REVOCATIONTYPE_DEVICE  = GUID$("{3129E375-CEB0-47D5-9CCA-9DB74CFD4332}")
$WMDRM_REVOCATIONTYPE_CARDEA  = GUID$("{CD75E604-543D-4A9C-9F09-FE6D24E8BF90}")
$WMDRM_REVOCATIONTYPE_REVINFO = GUID$("{CCDE5A55-A688-4405-A88B-D13F90D5BA3E}")
$WMDRM_REVOCATIONTYPE_GRL     = GUID$("{A2190240-B2CA-40B3-B48D-9BC4C2DC428D}")
$WMDRM_REVOCATIONTYPE_HDCP    = GUID$("{E627553A-820F-40FD-B465-A42830A574C9}")

' enum DRM_CRYPTO_TYPE
%CRYPTO_TYPE_MCE = 0

#IF NOT %DEF(%DRM_LICENSE_STATE_TYPES_DEFINED)
%DRM_LICENSE_STATE_TYPES_DEFINED = 1

' enum DRM_LICENSE_STATE_CATEGORY
%WM_DRM_LICENSE_STATE_NORIGHT                   = 0
%WM_DRM_LICENSE_STATE_UNLIM                     = %WM_DRM_LICENSE_STATE_NORIGHT          + 1
%WM_DRM_LICENSE_STATE_COUNT                     = %WM_DRM_LICENSE_STATE_UNLIM            + 1
%WM_DRM_LICENSE_STATE_FROM                      = %WM_DRM_LICENSE_STATE_COUNT            + 1
%WM_DRM_LICENSE_STATE_UNTIL                     = %WM_DRM_LICENSE_STATE_FROM             + 1
%WM_DRM_LICENSE_STATE_FROM_UNTIL                = %WM_DRM_LICENSE_STATE_UNTIL            + 1
%WM_DRM_LICENSE_STATE_COUNT_FROM                = %WM_DRM_LICENSE_STATE_FROM_UNTIL       + 1
%WM_DRM_LICENSE_STATE_COUNT_UNTIL               = %WM_DRM_LICENSE_STATE_COUNT_FROM       + 1
%WM_DRM_LICENSE_STATE_COUNT_FROM_UNTIL          = %WM_DRM_LICENSE_STATE_COUNT_UNTIL      + 1
%WM_DRM_LICENSE_STATE_EXPIRATION_AFTER_FIRSTUSE = %WM_DRM_LICENSE_STATE_COUNT_FROM_UNTIL + 1

' // Size = 68 bytes
TYPE DRM_LICENSE_STATE_DATA DWORD FILL
   dwStreamId  AS DWORD      ' DWORD
   dwCategory  AS LONG       ' DRM_LICENSE_STATE_CATEGORY
   dwNumCounts AS DWORD      ' DWORD
   dwCount(3)  AS DWORD      ' DWORD
   dwNumDates  AS DWORD      ' DWORD
   datetime(3) AS FILETIME
   dwVague     AS DWORD      ' DWORD
END TYPE

#ENDIF

' enum MSDRM_STATUS
%DRM_ERROR                       = 0
%DRM_INFORMATION                 = 1
%DRM_BACKUPRESTORE_BEGIN         = 2
%DRM_BACKUPRESTORE_END           = 3
%DRM_BACKUPRESTORE_CONNECTING    = 4
%DRM_BACKUPRESTORE_DISCONNECTING = 5
%DRM_ERROR_WITHURL               = 6
%DRM_RESTRICTED_LICENSE          = 7
%DRM_NEEDS_INDIVIDUALIZATION     = 8
%DRM_PLAY_OPL_NOTIFICATION       = 9
%DRM_COPY_OPL_NOTIFICATION       = 10
%DRM_REFRESHCRL_COMPLETE         = 11

' enum DRM_ATTR_DATATYPE
%DRM_TYPE_DWORD  = 0
%DRM_TYPE_STRING = 1
%DRM_TYPE_BINARY = 2
%DRM_TYPE_BOOL   = 3
%DRM_TYPE_QWORD  = 4
%DRM_TYPE_WORD   = 5
%DRM_TYPE_GUID   = 6

' enum DRM_HTTP_STATUS
%HTTP_NOTINITIATED = 0
%HTTP_CONNECTING   = %HTTP_NOTINITIATED + 1
%HTTP_REQUESTING   = %HTTP_CONNECTING   + 1
%HTTP_RECEIVING    = %HTTP_REQUESTING   + 1
%HTTP_COMPLETED    = %HTTP_RECEIVING    + 1

' enum DRM_INDIVIDUALIZATION_STATUS
%INDI_UNDEFINED = 0
%INDI_BEGIN     = &H1
%INDI_SUCCEED   = &H2
%INDI_FAIL      = &H4
%INDI_CANCEL    = &H8
%INDI_DOWNLOAD  = &H10
%INDI_INSTALL   = &H20

' enum DRM_ACTION_ALLOWED_QUERY_RESULTS
%DRM_ACTION_ALLOWED_QUERY_NOT_ENABLED                      = &H1
%DRM_ACTION_ALLOWED_QUERY_NOT_ENABLED_NO_LICENSE           = &H2
%DRM_ACTION_ALLOWED_QUERY_NOT_ENABLED_NO_RIGHT             = &H4
%DRM_ACTION_ALLOWED_QUERY_NOT_ENABLED_EXHAUSTED            = &H8
%DRM_ACTION_ALLOWED_QUERY_NOT_ENABLED_EXPIRED              = &H10
%DRM_ACTION_ALLOWED_QUERY_NOT_ENABLED_NOT_STARTED          = &H20
%DRM_ACTION_ALLOWED_QUERY_NOT_ENABLED_APPSEC_TOO_LOW       = &H40
%DRM_ACTION_ALLOWED_QUERY_NOT_ENABLED_REQ_INDIV            = &H80
%DRM_ACTION_ALLOWED_QUERY_NOT_ENABLED_COPY_OPL_TOO_LOW     = &H100
%DRM_ACTION_ALLOWED_QUERY_NOT_ENABLED_COPY_OPL_EXCLUDED    = &H200
%DRM_ACTION_ALLOWED_QUERY_NOT_ENABLED_NO_CLOCK_SUPPORT     = &H400
%DRM_ACTION_ALLOWED_QUERY_NOT_ENABLED_NO_METERING_SUPPORT  = &H800
%DRM_ACTION_ALLOWED_QUERY_NOT_ENABLED_CHAIN_DEPTH_TOO_HIGH = &H1000

' // Size = 24 bytes
TYPE WMDRMCryptoData QWORD FILL
   cryptoType  AS LONG   ' DRM_CRYPTO_TYPE enum
   qwCounterID AS QUAD   ' unsigned __int64
   qwOffset    AS QUAD   ' unsigned __int64
END TYPE

' // Size = 28 bytes
TYPE WM_INDIVIDUALIZE_STATUS DWORD FILL
   hr                 AS LONG         ' HRESULT
   enIndiStatus       AS LONG         ' DRM_INDIVIDUALIZATION_STATUS
   pszIndiRespUrl     AS ASCIIZ PTR   ' LPSTR
   dwHTTPRequest      AS DWORD        ' DWORD
   enHTTPStatus       AS LONG         ' DRM_HTTP_STATUS
   dwHTTPReadProgress AS DWORD        ' DWORD
   dwHTTPReadTotal    AS DWORD        ' DWORD
END TYPE

MACRO WMIndividualizeStatus = WM_INDIVIDUALIZE_STATUS

' // Size = 8 bytes
TYPE WM_BACKUP_RESTORE_STATUS DWORD FILL
   eStatus   AS LONG    ' MSDRM_STATUS
   bstrError AS DWORD   ' BSTR
END TYPE

MACRO WMBackupRestoreData = WM_BACKUP_RESTORE_STATUS

#IF NOT %DEF(%DRM_OPL_TYPES)
%DRM_OPL_TYPES = 1

%WMDRM_OPL_PLAY = &H00000001???
%WMDRM_OPL_COPY = &H00000002???

' // Size = 10 bytes
TYPE DRM_MINIMUM_OUTPUT_PROTECTION_LEVELS WORD
   wCompressedDigitalVideo   AS WORD   ' WORD
   wUncompressedDigitalVideo AS WORD   ' WORD
   wAnalogVideo              AS WORD   ' WORD
   wCompressedDigitalAudio   AS WORD   ' WORD
   wUncompressedDigitalAudio AS WORD   ' WORD
END TYPE

' // Size = 8 bytes
TYPE DRM_OPL_OUTPUT_IDS DWORD FILL
   cIds  AS WORD       ' WORD
   rgIds AS GUID PTR   ' GUID*
END TYPE

%VER_DRM_PLAY_OPL_V1             = 1
%VER_DRM_PLAY_OPL                = 2
%VER_DRM_VIDEO_OUTPUT_PROTECTION = 2

' // Size = 20 bytes
TYPE DRM_OUTPUT_PROTECTION DWORD
   guidId      AS GUID
   bConfigData AS BYTE
END TYPE

' // Size = 24 bytes
TYPE DRM_OUTPUT_PROTECTION_EX DWORD
   dwVersion    AS DWORD
   guidId       AS GUID
   dwConfigData AS DWORD
END TYPE

MACRO DRM_AUDIO_OUTPUT_PROTECTION    = DRM_OUTPUT_PROTECTION
MACRO DRM_VIDEO_OUTPUT_PROTECTION    = DRM_OUTPUT_PROTECTION
MACRO DRM_AUDIO_OUTPUT_PROTECTION_EX = DRM_OUTPUT_PROTECTION_EX
MACRO DRM_VIDEO_OUTPUT_PROTECTION_EX = DRM_OUTPUT_PROTECTION_EX

' // Size = 8 bytes
TYPE DRM_VIDEO_OUTPUT_PROTECTION_IDS DWORD FILL
   cEntries AS WORD
   rgVop    AS DRM_VIDEO_OUTPUT_PROTECTION PTR   ' DRM_VIDEO_OUTPUT_PROTECTION*
END TYPE

' // Size = 12 bytes
TYPE DRM_VIDEO_OUTPUT_PROTECTION_IDS_EX DWORD FILL
   dwVersion AS DWORD                                ' DWORD
   cEntries  AS WORD                                 ' WORD
   rgVop     AS DRM_VIDEO_OUTPUT_PROTECTION_EX PTR   ' DRM_VIDEO_OUTPUT_PROTECTION_EX*
END TYPE

' // Size = 8 bytes
TYPE DRM_AUDIO_OUTPUT_PROTECTION_IDS DWORD FILL
   cEntries AS WORD                              ' WORD
   rgAop    AS DRM_AUDIO_OUTPUT_PROTECTION PTR   ' DRM_AUDIO_OUTPUT_PROTECTION*
END TYPE

' // Size = 12 bytes
TYPE DRM_AUDIO_OUTPUT_PROTECTION_IDS_EX DWORD FILL
   dwVersion AS DWORD                                ' DWORD
   cEntries  AS WORD                                 ' WORD
   rgAop     AS DRM_AUDIO_OUTPUT_PROTECTION_EX PTR   ' DRM_AUDIO_OUTPUT_PROTECTION_EX*
END TYPE

' // Size = 28 bytes
TYPE DRM_PLAY_OPL DWORD FILL
   minOPL        AS DRM_MINIMUM_OUTPUT_PROTECTION_LEVELS
   oplIdReserved AS DRM_OPL_OUTPUT_IDS
   vopi          AS DRM_VIDEO_OUTPUT_PROTECTION_IDS
END TYPE

' // Size = 36 bytes
TYPE DRM_PLAY_OPL_EX DWORD FILL
   dwVersion     AS DWORD   ' DWORD
   minOPL        AS DRM_MINIMUM_OUTPUT_PROTECTION_LEVELS
   oplIdReserved AS DRM_OPL_OUTPUT_IDS
   vopi          AS DRM_VIDEO_OUTPUT_PROTECTION_IDS_EX
END TYPE

' // Size = 20 bytes
TYPE DRM_COPY_OPL DWORD FILL
   wMinimumCopyLevel AS WORD   ' WORD
   oplIdIncludes     AS DRM_OPL_OUTPUT_IDS
   oplIdExcludes     AS DRM_OPL_OUTPUT_IDS
END TYPE

#ENDIF ' // DRM_OPL_TYPES

' // Size = 12 bytes
TYPE WMDRM_OUTPUT_PROTECTION_LEVELS WORD
   wCompressedDigitalVideo     AS WORD   ' WORD
   wUncompressedDigitalVideo   AS WORD   ' WORD
   wAnalogVideo                AS WORD   ' WORD
   wCompressedDigitalAudio     AS WORD   ' WORD
   wUncompressedDigitalAudio   AS WORD   ' WORD
   wMinimumCopyProtectionLevel AS WORD   ' WORD
END TYPE

MACRO WMDRMOutputProtectionLevels = WMDRM_OUTPUT_PROTECTION_LEVELS

' // Size = 20 bytes
TYPE WMDRM_ANALOG_VIDEO_RESTRICTIONS DWORD
   guidRestrictionID AS GUID    ' GUID
   dwRestrictionData AS DWORD   ' DWORD
END TYPE

MACRO WMDRMAnalogVideoRestrictions = WMDRM_ANALOG_VIDEO_RESTRICTIONS

' // Size = 28 bytes
TYPE WMDRM_ANALOG_VIDEO_RESTRICTIONS_EX DWORD
   dwVersion         AS DWORD      ' DWORD
   guidRestrictionID AS GUID       ' GUID
   cbRestrictionData AS DWORD      ' DWORD
   pbRestrictionData AS BYTE PTR   ' BYTE*
END TYPE

MACRO WMDRMAnalogVideoRestrictionsEx = WMDRM_ANALOG_VIDEO_RESTRICTIONS_EX

' enum WMDRMNET_POLICY_TYPE
%WMDRMNET_POLICY_TYPE_UNDEFINED      = 0
%WMDRMNET_POLICY_TYPE_TRANSCRYPTPLAY = &H1

' // Size = 8 bytes
TYPE WMDRMNET_POLICY DWORD
   ePolicyType AS LONG       ' WMDRMNET_POLICY_TYPE
   pbPolicy    AS BYTE PTR   ' BYTE *
END TYPE

' // Size = 8 bytes
TYPE WMDRMNET_POLICY_TRANSCRYPTPLAY DWORD
   cbData AS DWORD      ' DWORD
   pbData AS BYTE PTR   ' BYTE*
END TYPE

' // Size = 16 bytes
TYPE WMDRM_ENCRYPT_SCATTER_INFO DWORD
   dwStreamID                AS DWORD      ' DWORD
   dwSampleProtectionVersion AS DWORD      ' DWORD
   cbProtectionInfo          AS DWORD      ' DWORD
   pbProtectionInfo          AS BYTE PTR   ' BYTE*
END TYPE

' // Size = 12 bytes
TYPE WMDRM_ENCRYPT_SCATTER_BLOCK DWORD
   dwStreamID AS DWORD      ' DWORD
   cbBlock    AS DWORD      ' DWORD
   pbBlock    AS BYTE PTR   ' BYTE*
END TYPE

DECLARE FUNCTION WMDRMStartup IMPORT "wmdrmsdk.dll" ALIAS "WMDRMStartup" () AS LONG
DECLARE FUNCTION WMDRMShutdown IMPORT "wmdrmsdk.dll" ALIAS "WMDRMShutdown" () AS LONG

DECLARE FUNCTION WMDRMCreateProvider IMPORT "wmdrmsdk.dll" ALIAS "WMDRMCreateProvider" ( _
   BYREF ppDRMProvider AS IWMDRMProvider _              ' __out IWMDRMProvider **ppDRMProvider
 ) AS LONG                                              ' HRESULT

'//
'// WMDRMCreateProtectedProvider is only available via a Microsoft issued WMDRMSDK stub library
'//
DECLARE FUNCTION WMDRMCreateProtectedProvider IMPORT "wmdrmsdk.dll" ALIAS "WMDRMCreateProtectedProvider" ( _
   BYREF ppDRMProvider AS IWMDRMProvider _              ' __out IWMDRMProvider **ppDRMProvider
 ) AS LONG                                              ' HRESULT


' ########################################################################################
' Interface name = IDRMStatusCallback
' IID = 08548704-75B1-4982-9B26-FB385DEE741D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDRMStatusCallback_INTERFACE_DEFINED)
    %IDRMStatusCallback_INTERFACE_DEFINED = 1

$IID_IDRMStatusCallback = GUID$("{08548704-75B1-4982-9B26-FB385DEE741D}")

INTERFACE IDRMStatusCallback $IID_IDRMStatusCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnStatus ( _                                  ' VTable offset = 12
     BYVAL Status AS LONG _                             ' __in MSDRM_STATUS Status
   , BYVAL hr AS LONG _                                 ' __in HRESULT hr
   , BYVAL dwType AS LONG _                             ' __in DRM_ATTR_DATATYPE dwType
   , BYVAL pValue AS BYTE PTR _                         ' __in BYTE *pValue
   , BYVAL pvContext AS DWORD _                         ' __in void *pvContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDRMStatusCallback_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWMDRMEventGenerator
' IID = CE11CC91-E615-4E0B-BE1F-09B5AEC033F2
' Inherited interface = IMFMediaEventGenerator
' ########################################################################################

#IF NOT %DEF(%IWMDRMEventGenerator_INTERFACE_DEFINED)
    %IWMDRMEventGenerator_INTERFACE_DEFINED = 1

$IID_IWMDRMEventGenerator = GUID$("{CE11CC91-E615-4E0B-BE1F-09B5AEC033F2}")

INTERFACE IWMDRMEventGenerator $IID_IWMDRMEventGenerator

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFMediaEventGenerator methods
   ' =====================================================================================
   METHOD GetEvent ( _                                  ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppEvent AS IMFMediaEvent _                   ' __out IMFMediaEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginGetEvent ( _                             ' VTable offset = 16
     BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL punkState AS IUnknown _                      ' __in IUnknown *punkState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndGetEvent ( _                               ' VTable offset = 20
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   , BYREF ppEvent AS IMFMediaEvent _                   ' __out IMFMediaEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueueEvent ( _                                ' VTable offset = 24
     BYVAL met AS DWORD _                               ' __in MediaEventType met
   , BYREF guidExtendedType AS GUID _                   ' __in REFGUID guidExtendedType
   , BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   , BYREF pvValue AS PROPVARIANT _                     ' __in const PROPVARIANT *pvValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWMDRMEventGenerator methods
   ' =====================================================================================
   METHOD CancelAsyncOperation ( _                      ' VTable offset = 28
     BYVAL punkCancelationCookie AS IUnknown _          ' __in IUnknown *punkCancelationCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Shutdown ( _                                  ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMDRMEventGenerator_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWMDRMProvider
' IID = 98DC8917-8640-4B1D-9F1E-A590D40357EE
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMDRMProvider_INTERFACE_DEFINED)
    %IWMDRMProvider_INTERFACE_DEFINED = 1

$IID_IWMDRMProvider = GUID$("{98DC8917-8640-4B1D-9F1E-A590D40357EE}")

INTERFACE IWMDRMProvider $IID_IWMDRMProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateObject ( _                              ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS IUnknown _                      ' __out void **ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMDRMProvider_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWMDRMSecurity
' IID = 70800F56-5239-4A0B-A8B8-D53C6BAE4171
' Inherited interface = IWMDRMEventGenerator
' ########################################################################################

#IF NOT %DEF(%IWMDRMSecurity_INTERFACE_DEFINED)
    %IWMDRMSecurity_INTERFACE_DEFINED = 1

$IID_IWMDRMSecurity = GUID$("{70800F56-5239-4A0B-A8B8-D53C6BAE4171}")

INTERFACE IWMDRMSecurity $IID_IWMDRMSecurity

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFMediaEventGenerator methods
   ' =====================================================================================
   METHOD GetEvent ( _                                  ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppEvent AS IMFMediaEvent _                   ' __out IMFMediaEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginGetEvent ( _                             ' VTable offset = 16
     BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL punkState AS IUnknown _                      ' __in IUnknown *punkState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndGetEvent ( _                               ' VTable offset = 20
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   , BYREF ppEvent AS IMFMediaEvent _                   ' __out IMFMediaEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueueEvent ( _                                ' VTable offset = 24
     BYVAL met AS DWORD _                               ' __in MediaEventType met
   , BYREF guidExtendedType AS GUID _                   ' __in REFGUID guidExtendedType
   , BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   , BYREF pvValue AS PROPVARIANT _                     ' __in const PROPVARIANT *pvValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWMDRMEventGenerator methods
   ' =====================================================================================
   METHOD CancelAsyncOperation ( _                      ' VTable offset = 28
     BYVAL punkCancelationCookie AS IUnknown _          ' __in IUnknown *punkCancelationCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Shutdown ( _                                  ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWMDRMSecurity methods
   ' =====================================================================================
   METHOD GetSecurityVersion ( _                        ' VTable offset = 36
     BYREF pbstrVersion AS WSTRING _                    ' __out BSTR *pbstrVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMachineCertificate ( _                     ' VTable offset = 40
     BYVAL dwCertificateType AS DWORD _                 ' __in DWORD dwCertificateType
   , BYREF rgbVersion AS BYTE _                         ' __out BYTE rgbVersion[ 4 ]
   , BYREF ppbCertificate AS DWORD _                    ' __out BYTE **ppbCertificate
   , BYREF pcbCertificate AS DWORD _                    ' __out DWORD *pcbCertificate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PerformSecurityUpdate ( _                     ' VTable offset = 44
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppunkCancelationCookie AS IUnknown _         ' __out IUnknown **ppunkCancelationCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRevocationData ( _                         ' VTable offset = 48
     BYREF guidRevocationType AS GUID _                 ' __in REFGUID guidRevocationType
   , BYVAL pbCRL AS BYTE PTR _                          ' __in BYTE *pbCRL
   , BYVAL cbCRL AS DWORD _                             ' __in DWORD cbCRL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRevocationData ( _                         ' VTable offset = 52
     BYREF guidRevocationType AS GUID _                 ' __in REFGUID guidRevocationType
   , BYVAL pbCRL AS BYTE PTR _                          ' __out BYTE *pbCRL
   , BYREF pcbCRL AS DWORD _                            ' __inout DWORD *pcbCRL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRevocationDataVersion ( _                  ' VTable offset = 56
     BYREF guidRevocationType AS GUID _                 ' __in REFGUID guidRevocationType
   , BYREF pdwCRLVersion AS QUAD _                      ' __out ULONGLONG *pdwCRLVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckCertForRevocation ( _                    ' VTable offset = 60
     BYREF rguidRevocationList AS GUID _                ' __in REFGUID rguidRevocationList
   , BYVAL pbCert AS BYTE PTR _                         ' __in BYTE *pbCert
   , BYVAL cbCert AS DWORD _                            ' __in DWORD cbCert
   , BYREF pfRevoked AS LONG _                          ' __out BOOL *pfRevoked
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContentEnablersForRevocations ( _          ' VTable offset = 64
     BYVAL rgpbCerts AS DWORD _                         ' __in BYTE **rgpbCerts
   , BYREF rgpdwCertSizes AS DWORD _                    ' __in DWORD *rgpdwCertSizes
   , BYREF rgpguidCerts AS GUID _                       ' __in GUID **rgpguidCerts
   , BYVAL cCerts AS DWORD _                            ' __in DWORD cCerts
   , BYVAL hResultHint AS LONG _                        ' __in HRESULT hResultHint
   , BYREF prgContentEnablers AS IMFContentEnabler _    ' __out IMFContentEnabler **prgContentEnablers
   , BYREF pcContentEnablers AS DWORD _                 ' __inout DWORD *pcContentEnablers
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContentEnablersFromHashes ( _              ' VTable offset = 68
     BYVAL rgpbCertHashes AS WSTRING _                  ' __in BSTR *rgpbCertHashes
   , BYVAL cCerts AS DWORD _                            ' __in DWORD cCerts
   , BYVAL hResultHint AS LONG _                        ' __in HRESULT hResultHint
   , BYREF prgContentEnablers AS IMFContentEnabler _    ' __out IMFContentEnabler **prgContentEnablers
   , BYREF pcContentEnablers AS DWORD _                 ' __inout DWORD *pcContentEnablers
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMDRMSecurity_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWMDRMEncrypt
' IID = C9E0A5F4-DD22-4DC4-B795-88FA91F0516B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMDRMEncrypt_INTERFACE_DEFINED)
    %IWMDRMEncrypt_INTERFACE_DEFINED = 1

$IID_IWMDRMEncrypt = GUID$("{C9E0A5F4-DD22-4DC4-B795-88FA91F0516B}")

INTERFACE IWMDRMEncrypt $IID_IWMDRMEncrypt

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Encrypt ( _                                   ' VTable offset = 12
     BYVAL pbData AS BYTE PTR _                         ' __inout BYTE *pbData
   , BYVAL cbData AS DWORD _                            ' __in DWORD cbData
   , BYREF pWMCryptoData AS WMDRMCryptoData _           ' __in WMDRMCryptoData *pWMCryptoData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMDRMEncrypt_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWMDRMEncryptScatter
' IID = 2662FA39-4C62-481A-956C-7BFCB33C2888
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMDRMEncryptScatter_INTERFACE_DEFINED)
    %IWMDRMEncryptScatter_INTERFACE_DEFINED = 1

$IID_IWMDRMEncryptScatter = GUID$("{2662FA39-4C62-481A-956C-7BFCB33C2888}")

INTERFACE IWMDRMEncryptScatter $IID_IWMDRMEncryptScatter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InitEncryptScatter ( _                        ' VTable offset = 12
     BYVAL cStreams AS DWORD _                          ' __in DWORD cStreams
   , BYREF rgInfos AS WMDRM_ENCRYPT_SCATTER_INFO _      ' __in WMDRM_ENCRYPT_SCATTER_INFO *rgInfos
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EncryptScatter ( _                            ' VTable offset = 16
     BYVAL cBlocks AS DWORD _                           ' __in DWORD cBlocks
   , BYREF rgBlocks AS WMDRM_ENCRYPT_SCATTER_BLOCK _    ' __in WMDRM_ENCRYPT_SCATTER_BLOCK *rgBlocks
   , BYREF pWMCryptoData AS WMDRMCryptoData _           ' __in WMDRMCryptoData *pWMCryptoData
   , BYVAL cbOutput AS DWORD _                          ' __in DWORD cbOutput
   , BYVAL pbOutput AS BYTE PTR _                       ' __out BYTE *pbOutput
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMDRMEncryptScatter_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWMDRMDecrypt
' IID = C9E0A5F5-DD22-4DC4-B795-88FA91F0516B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMDRMDecrypt_INTERFACE_DEFINED)
    %IWMDRMDecrypt_INTERFACE_DEFINED = 1

$IID_IWMDRMDecrypt = GUID$("{C9E0A5F5-DD22-4DC4-B795-88FA91F0516B}")

INTERFACE IWMDRMDecrypt $IID_IWMDRMDecrypt

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Decrypt ( _                                   ' VTable offset = 12
     BYVAL pbData AS BYTE PTR _                         ' __inout BYTE *pbData
   , BYVAL cbData AS DWORD _                            ' __in DWORD cbData
   , BYREF pWMCryptoData AS WMDRMCryptoData _           ' __in WMDRMCryptoData *pWMCryptoData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMDRMDecrypt_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWMDRMLicense
' IID = C9E0A5F3-DD22-4DC4-B795-88FA91F0516B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMDRMLicense_INTERFACE_DEFINED)
    %IWMDRMLicense_INTERFACE_DEFINED = 1

$IID_IWMDRMLicense = GUID$("{C9E0A5F3-DD22-4DC4-B795-88FA91F0516B}")

INTERFACE IWMDRMLicense $IID_IWMDRMLicense

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ResetEnumeration ( _                          ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNext ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLicense ( _                                ' VTable offset = 20
     BYREF ppbLicense AS DWORD _                        ' __out BYTE **ppbLicense
   , BYREF pcbLicense AS DWORD _                        ' __out DWORD *pcbLicense
   , BYREF pdwLicenseType AS DWORD _                    ' __out DWORD *pdwLicenseType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLicenseProperty ( _                        ' VTable offset = 24
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYREF ppropVariant AS PROPVARIANT _                ' __out PROPVARIANT *ppropVariant
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDecryptor ( _                           ' VTable offset = 28
     BYREF ppDecryptor AS IWMDRMDecrypt _               ' __out IWMDRMDecrypt **ppDecryptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSecureDecryptor ( _                     ' VTable offset = 32
     BYVAL pbCertificate AS BYTE PTR _                  ' __in BYTE *pbCertificate
   , BYVAL cbCertificate AS DWORD _                     ' __in DWORD cbCertificate
   , BYVAL dwCertificateType AS DWORD _                 ' __in DWORD dwCertificateType
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pbInitializationVector AS BYTE _             ' __out BYTE *pbInitializationVector
   , BYREF pcbInitializationVector AS DWORD _           ' __out DWORD *pcbInitializationVector
   , BYREF ppDecryptor AS IWMDRMDecrypt _               ' __out IWMDRMDecrypt **ppDecryptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateEncryptor ( _                           ' VTable offset = 36
     BYREF ppEncryptor AS IWMDRMEncrypt _               ' __out IWMDRMEncrypt **ppEncryptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PersistLicense ( _                            ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CanPersist ( _                                ' VTable offset = 44
     BYREF pfCanPersist AS LONG _                       ' __out BOOL *pfCanPersist
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAnalogVideoRestrictionLevels ( _           ' VTable offset = 48
     BYREF rgAnalogVideoRestrictions AS WMDRM_ANALOG_VIDEO_RESTRICTIONS _ ' __out WMDRM_ANALOG_VIDEO_RESTRICTIONS rgAnalogVideoRestrictions[  ]
   , BYREF pcRestrictions AS DWORD _                    ' __inout DWORD *pcRestrictions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputProtectionLevels ( _                 ' VTable offset = 52
     BYREF pOPLs AS WMDRM_OUTPUT_PROTECTION_LEVELS _    ' __out WMDRM_OUTPUT_PROTECTION_LEVELS *pOPLs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInclusionList ( _                          ' VTable offset = 56
     BYREF ppGuids AS GUID _                            ' __out GUID **ppGuids
   , BYREF pcGuids AS DWORD _                           ' __out DWORD *pcGuids
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPolicy ( _                                 ' VTable offset = 60
     BYREF ppbPolicy AS DWORD _                         ' __out BYTE **ppbPolicy
   , BYREF pcbPolicy AS DWORD _                         ' __out DWORD *pcbPolicy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMDRMLicense_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWMDRMLicenseQuery
' IID = 20B970DF-0A58-4D3C-817C-4E3CCBB253AC
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMDRMLicenseQuery_INTERFACE_DEFINED)
    %IWMDRMLicenseQuery_INTERFACE_DEFINED = 1

$IID_IWMDRMLicenseQuery = GUID$("{20B970DF-0A58-4D3C-817C-4E3CCBB253AC}")

INTERFACE IWMDRMLicenseQuery $IID_IWMDRMLicenseQuery

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryLicenseState ( _                         ' VTable offset = 12
     BYVAL bstrKID AS WSTRING _                         ' __in BSTR bstrKID
   , BYVAL cActionsToQuery AS DWORD _                   ' __in DWORD cActionsToQuery
   , BYREF rgbstrActionsToQuery AS WSTRING _            ' __in BSTR rgbstrActionsToQuery[  ]
   , BYREF rgResultStateData AS DRM_LICENSE_STATE_DATA _ ' __out DRM_LICENSE_STATE_DATA rgResultStateData[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetActionAllowedQueryParams ( _               ' VTable offset = 16
     BYVAL fIsMF AS LONG _                              ' __in BOOL fIsMF
   , BYVAL dwAppSecLevel AS DWORD _                     ' __in DWORD dwAppSecLevel
   , BYVAL fHasSerialNumber AS LONG _                   ' __in BOOL fHasSerialNumber
   , BYVAL bstrDeviceCert AS WSTRING _                  ' __in BSTR bstrDeviceCert
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryActionAllowed ( _                        ' VTable offset = 20
     BYVAL bstrKID AS WSTRING _                         ' __in BSTR bstrKID
   , BYVAL bstrMinReqIndivVersion AS WSTRING _          ' __in BSTR bstrMinReqIndivVersion
   , BYVAL cActionsToQuery AS DWORD _                   ' __in DWORD cActionsToQuery
   , BYREF rgbstrActionsToQuery AS WSTRING _            ' __in BSTR rgbstrActionsToQuery[  ]
   , BYREF rgdwQueryResult AS DWORD _                   ' __out DWORD rgdwQueryResult[  ])
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMDRMLicenseQuery_INTERFACE_DEFINED__ */


' // Size = 16 bytes
TYPE WMDRM_LICENSE_FILTER DWORD
   dwVersion            AS DWORD   ' DWORD
   bstrKID              AS DWORD   ' BSTR
   bstrRights           AS DWORD   ' BSTR
   bstrAllowedSourceIDs AS DWORD   ' BSTR
END TYPE


' ########################################################################################
' Interface name = IWMDRMLicenseManagement
' IID = F4828DC7-8945-4D05-AB05-667AB99D29EE
' Inherited interface = IWMDRMEventGenerator
' ########################################################################################

#IF NOT %DEF(%IWMDRMLicenseManagement_INTERFACE_DEFINED)
    %IWMDRMLicenseManagement_INTERFACE_DEFINED = 1

$IID_IWMDRMLicenseManagement = GUID$("{F4828DC7-8945-4D05-AB05-667AB99D29EE}")

INTERFACE IWMDRMLicenseManagement $IID_IWMDRMLicenseManagement

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFMediaEventGenerator methods
   ' =====================================================================================
   METHOD GetEvent ( _                                  ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppEvent AS IMFMediaEvent _                   ' __out IMFMediaEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginGetEvent ( _                             ' VTable offset = 16
     BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL punkState AS IUnknown _                      ' __in IUnknown *punkState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndGetEvent ( _                               ' VTable offset = 20
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   , BYREF ppEvent AS IMFMediaEvent _                   ' __out IMFMediaEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueueEvent ( _                                ' VTable offset = 24
     BYVAL met AS DWORD _                               ' __in MediaEventType met
   , BYREF guidExtendedType AS GUID _                   ' __in REFGUID guidExtendedType
   , BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   , BYREF pvValue AS PROPVARIANT _                     ' __in const PROPVARIANT *pvValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWMDRMEventGenerator methods
   ' =====================================================================================
   METHOD CancelAsyncOperation ( _                      ' VTable offset = 28
     BYVAL punkCancelationCookie AS IUnknown _          ' __in IUnknown *punkCancelationCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Shutdown ( _                                  ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWMDRMLicenseManagement methods
   ' =====================================================================================
   METHOD CreateLicenseEnumeration ( _                  ' VTable offset = 36
     BYREF pLicenseFilter AS WMDRM_LICENSE_FILTER _     ' __in WMDRM_LICENSE_FILTER *pLicenseFilter
   , BYREF pEnumerator AS IWMDRMLicense _               ' __out IWMDRMLicense **pEnumerator
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteLicense ( _                             ' VTable offset = 40
     BYVAL bstrKID AS WSTRING _                         ' __in BSTR bstrKID
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CleanLicenseStore ( _                         ' VTable offset = 44
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppunkCancelationCookie AS IUnknown _         ' __out IUnknown **ppunkCancelationCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StoreLicense ( _                              ' VTable offset = 48
     BYVAL bstrLicenseResponse AS WSTRING _             ' __in BSTR bstrLicenseResponse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AcquireLicense ( _                            ' VTable offset = 52
     BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   , BYVAL bstrHeaderData AS WSTRING _                  ' __in BSTR bstrHeaderData
   , BYVAL bstrActions AS WSTRING _                     ' __in BSTR bstrActions
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppunkCancelationCookie AS IUnknown _         ' __out IUnknown **ppunkCancelationCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MonitorLicenseAcquisition ( _                 ' VTable offset = 56
     BYVAL bstrKID AS WSTRING _                         ' __in BSTR bstrKID
   , BYVAL bstrHeader AS WSTRING _                      ' __in BSTR bstrHeader
   , BYVAL bstrActions AS WSTRING _                     ' __in BSTR bstrActions
   , BYREF ppunkCancelationCookie AS IUnknown _         ' __out IUnknown **ppunkCancelationCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BackupLicenses ( _                            ' VTable offset = 60
     BYVAL bstrBackupDirectory AS WSTRING _             ' __in BSTR bstrBackupDirectory
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppunkCancelationCookie AS IUnknown _         ' __out IUnknown **ppunkCancelationCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RestoreLicenses ( _                           ' VTable offset = 64
     BYVAL bstrBackupDirectory AS WSTRING _             ' __in BSTR bstrBackupDirectory
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppunkCancelationCookie AS IUnknown _         ' __out IUnknown **ppunkCancelationCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateLicenseRevocationChallenge ( _          ' VTable offset = 68
     BYVAL pbMachineID AS BYTE PTR _                    ' __in BYTE *pbMachineID
   , BYVAL cbMachineID AS DWORD _                       ' __in DWORD cbMachineID
   , BYVAL pbChallenge AS BYTE PTR _                    ' __in BYTE *pbChallenge
   , BYVAL cbChallenge AS DWORD _                       ' __in DWORD cbChallenge
   , BYREF ppbChallengeOutput AS DWORD _                ' __out BYTE **ppbChallengeOutput
   , BYREF pcbChallengeOutput AS DWORD _                ' __out DWORD *pcbChallengeOutput
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessLicenseRevocationResponse ( _          ' VTable offset = 72
     BYVAL pbSignedLRB AS BYTE PTR _                    ' __in BYTE *pbSignedLRB
   , BYVAL cbSignedLRB AS DWORD _                       ' __in DWORD cbSignedLRB
   , BYREF ppbSignedACK AS DWORD _                      ' __out BYTE **ppbSignedACK
   , BYREF pcbSignedACK AS DWORD _                      ' __out DWORD *pcbSignedACK
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessLicenseDeletionMessage ( _             ' VTable offset = 76
     BYVAL bstrDeletionMessage AS WSTRING _             ' __in BSTR bstrDeletionMessage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMDRMLicenseManagement_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWMDRMNetReceiver
' IID = F9C074A4-15D6-44C0-8A6D-2446ACC109AE
' Inherited interface = IWMDRMEventGenerator
' ########################################################################################

#IF NOT %DEF(%IWMDRMNetReceiver_INTERFACE_DEFINED)
    %IWMDRMNetReceiver_INTERFACE_DEFINED = 1

$IID_IWMDRMNetReceiver = GUID$("{F9C074A4-15D6-44C0-8A6D-2446ACC109AE}")

INTERFACE IWMDRMNetReceiver $IID_IWMDRMNetReceiver

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFMediaEventGenerator methods
   ' =====================================================================================
   METHOD GetEvent ( _                                  ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppEvent AS IMFMediaEvent _                   ' __out IMFMediaEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginGetEvent ( _                             ' VTable offset = 16
     BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL punkState AS IUnknown _                      ' __in IUnknown *punkState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndGetEvent ( _                               ' VTable offset = 20
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   , BYREF ppEvent AS IMFMediaEvent _                   ' __out IMFMediaEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueueEvent ( _                                ' VTable offset = 24
     BYVAL met AS DWORD _                               ' __in MediaEventType met
   , BYREF guidExtendedType AS GUID _                   ' __in REFGUID guidExtendedType
   , BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   , BYREF pvValue AS PROPVARIANT _                     ' __in const PROPVARIANT *pvValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWMDRMEventGenerator methods
   ' =====================================================================================
   METHOD CancelAsyncOperation ( _                      ' VTable offset = 28
     BYVAL punkCancelationCookie AS IUnknown _          ' __in IUnknown *punkCancelationCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Shutdown ( _                                  ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWMDRMNetReceiver methods
   ' =====================================================================================
   METHOD GetRegistrationChallenge ( _                  ' VTable offset = 36
     BYREF ppbRegistrationChallenge AS DWORD _          ' __out BYTE **ppbRegistrationChallenge
   , BYREF pcbRegistrationChallenge AS DWORD _          ' __out DWORD *pcbRegistrationChallenge
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessRegistrationResponse ( _               ' VTable offset = 40
     BYVAL pbRegistrationResponse AS BYTE PTR _         ' __in BYTE *pbRegistrationResponse
   , BYVAL cbRegistrationResponse AS DWORD _            ' __in DWORD cbRegistrationResponse
   , BYREF ppunkCancellationCookie AS IUnknown _        ' __out IUnknown **ppunkCancellationCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLicenseChallenge ( _                       ' VTable offset = 44
     BYVAL bstrAction AS WSTRING _                      ' __in BSTR bstrAction
   , BYREF ppbLicenseChallenge AS DWORD _               ' __out BYTE **ppbLicenseChallenge
   , BYREF pcbLicenseChallenge AS DWORD _               ' __out DWORD *pcbLicenseChallenge
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessLicenseResponse ( _                    ' VTable offset = 48
     BYVAL pbLicenseResponse AS BYTE PTR _              ' __in BYTE *pbLicenseResponse
   , BYVAL cbLicenseResponse AS DWORD _                 ' __in DWORD cbLicenseResponse
   , BYREF ppbWMDRMNetLicenseRepresentation AS DWORD _  ' __out BYTE **ppbWMDRMNetLicenseRepresentation
   , BYREF pcbWMDRMNetLicenseRepresentation AS DWORD _  ' __out DWORD *pcbWMDRMNetLicenseRepresentation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMDRMNetReceiver_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMDRMNetReceiver2
' IID = 7B97237F-4B5D-442D-86C7-4F88961AF76B
' Inherited interface = IWMDRMNetReceiver
' ########################################################################################

#IF NOT %DEF(%IWMDRMNetReceiver2_INTERFACE_DEFINED)
    %IWMDRMNetReceiver2_INTERFACE_DEFINED = 1

$IID_IWMDRMNetReceiver2 = GUID$("{7B97237F-4B5D-442D-86C7-4F88961AF76B}")

INTERFACE IWMDRMNetReceiver2 $IID_IWMDRMNetReceiver2

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFMediaEventGenerator methods
   ' =====================================================================================
   METHOD GetEvent ( _                                  ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppEvent AS IMFMediaEvent _                   ' __out IMFMediaEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginGetEvent ( _                             ' VTable offset = 16
     BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL punkState AS IUnknown _                      ' __in IUnknown *punkState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndGetEvent ( _                               ' VTable offset = 20
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   , BYREF ppEvent AS IMFMediaEvent _                   ' __out IMFMediaEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueueEvent ( _                                ' VTable offset = 24
     BYVAL met AS DWORD _                               ' __in MediaEventType met
   , BYREF guidExtendedType AS GUID _                   ' __in REFGUID guidExtendedType
   , BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   , BYREF pvValue AS PROPVARIANT _                     ' __in const PROPVARIANT *pvValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWMDRMEventGenerator methods
   ' =====================================================================================
   METHOD CancelAsyncOperation ( _                      ' VTable offset = 28
     BYVAL punkCancelationCookie AS IUnknown _          ' __in IUnknown *punkCancelationCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Shutdown ( _                                  ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWMDRMNetReceiver methods
   ' =====================================================================================
   METHOD GetRegistrationChallenge ( _                  ' VTable offset = 36
     BYREF ppbRegistrationChallenge AS DWORD _          ' __out BYTE **ppbRegistrationChallenge
   , BYREF pcbRegistrationChallenge AS DWORD _          ' __out DWORD *pcbRegistrationChallenge
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessRegistrationResponse ( _               ' VTable offset = 40
     BYVAL pbRegistrationResponse AS BYTE PTR _         ' __in BYTE *pbRegistrationResponse
   , BYVAL cbRegistrationResponse AS DWORD _            ' __in DWORD cbRegistrationResponse
   , BYREF ppunkCancellationCookie AS IUnknown _        ' __out IUnknown **ppunkCancellationCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLicenseChallenge ( _                       ' VTable offset = 44
     BYVAL bstrAction AS WSTRING _                      ' __in BSTR bstrAction
   , BYREF ppbLicenseChallenge AS DWORD _               ' __out BYTE **ppbLicenseChallenge
   , BYREF pcbLicenseChallenge AS DWORD _               ' __out DWORD *pcbLicenseChallenge
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessLicenseResponse ( _                    ' VTable offset = 48
     BYVAL pbLicenseResponse AS BYTE PTR _              ' __in BYTE *pbLicenseResponse
   , BYVAL cbLicenseResponse AS DWORD _                 ' __in DWORD cbLicenseResponse
   , BYREF ppbWMDRMNetLicenseRepresentation AS DWORD _  ' __out BYTE **ppbWMDRMNetLicenseRepresentation
   , BYREF pcbWMDRMNetLicenseRepresentation AS DWORD _  ' __out DWORD *pcbWMDRMNetLicenseRepresentation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWMDRMNetReceiver2 methods
   ' =====================================================================================
   METHOD ProcessRegistrationResponseEx ( _             ' VTable offset = 52
     BYVAL pbRegistrationResponse AS BYTE _             ' __in BYTE *pbRegistrationResponse
   , BYVAL cbRegistrationResponse AS DWORD _            ' __in DWORD cbRegistrationResponse
   , BYVAL dwLocalIPv6ScopeID AS DWORD _                ' __in DWORD dwLocalIPv6ScopeID
   , BYREF ppunkCancellationCookie AS IUnknown _        ' __out IUnknown **ppunkCancellationCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessLicenseUpdate ( _                      ' VTable offset = 56
     BYVAL pbLicenseUpdate AS BYTE _                    ' __in BYTE *pbLicenseUpdate
   , BYVAL cbLicenseUpdate AS DWORD _                   ' __in DWORD cbLicenseUpdate
   , BYREF ppLicense AS IWMDRMLicense _                 ' __out IWMDRMLicense **ppLicense
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMDRMNetReceiver2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMDRMNetTransmitter
' IID = F040C12B-4415-4F20-93F0-453EB519A756
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMDRMNetTransmitter_INTERFACE_DEFINED)
    %IWMDRMNetTransmitter_INTERFACE_DEFINED = 1

$IID_IWMDRMNetTransmitter = GUID$("{F040C12B-4415-4F20-93F0-453EB519A756}")

INTERFACE IWMDRMNetTransmitter $IID_IWMDRMNetTransmitter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetLicenseChallenge ( _                       ' VTable offset = 12
     BYVAL pbLicenseChallenge AS BYTE PTR _             ' __in BYTE *pbLicenseChallenge
   , BYVAL cbLicenseChallenge AS DWORD _                ' __in DWORD cbLicenseChallenge
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRootLicenseResponse ( _                    ' VTable offset = 16
     BYVAL bstrKID AS WSTRING _                         ' __in BSTR bstrKID
   , BYREF ppbLicenseResponse AS DWORD _                ' __out BYTE **ppbLicenseResponse
   , BYREF pcbLicenseResponse AS DWORD _                ' __out DWORD *pcbLicenseResponse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLeafLicenseResponse ( _                    ' VTable offset = 20
     BYVAL bstrKID AS WSTRING _                         ' __in BSTR bstrKID
   , BYREF pPolicy AS WMDRMNET_POLICY _                 ' __in WMDRMNET_POLICY *pPolicy
   , BYREF ppIWMDRMEncrypt AS IWMDRMEncrypt _           ' __out IWMDRMEncrypt **ppIWMDRMEncrypt
   , BYREF ppbLicenseResponse AS DWORD _                ' __out BYTE **ppbLicenseResponse
   , BYREF pcbLicenseResponse AS DWORD _                ' __out DWORD *pcbLicenseResponse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMDRMNetTransmitter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMDRMNetTransmitter2
' IID = 26BCB422-30C0-48B4-A641-D9FB1E656265
' Inherited interface = IWMDRMNetTransmitter
' ########################################################################################

#IF NOT %DEF(%IWMDRMNetTransmitter2_INTERFACE_DEFINED)
    %IWMDRMNetTransmitter2_INTERFACE_DEFINED = 1

$IID_IWMDRMNetTransmitter2 = GUID$("{26BCB422-30C0-48B4-A641-D9FB1E656265}")

INTERFACE IWMDRMNetTransmitter2 $IID_IWMDRMNetTransmitter2

   INHERIT IUnknown

   ' =====================================================================================
   ' IWMDRMNetTransmitter Methods
   ' =====================================================================================
   METHOD SetLicenseChallenge ( _                       ' VTable offset = 12
     BYVAL pbLicenseChallenge AS BYTE PTR _             ' __in BYTE *pbLicenseChallenge
   , BYVAL cbLicenseChallenge AS DWORD _                ' __in DWORD cbLicenseChallenge
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRootLicenseResponse ( _                    ' VTable offset = 16
     BYVAL bstrKID AS WSTRING _                         ' __in BSTR bstrKID
   , BYREF ppbLicenseResponse AS DWORD _                ' __out BYTE **ppbLicenseResponse
   , BYREF pcbLicenseResponse AS DWORD _                ' __out DWORD *pcbLicenseResponse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLeafLicenseResponse ( _                    ' VTable offset = 20
     BYVAL bstrKID AS WSTRING _                         ' __in BSTR bstrKID
   , BYREF pPolicy AS WMDRMNET_POLICY _                 ' __in WMDRMNET_POLICY *pPolicy
   , BYREF ppIWMDRMEncrypt AS IWMDRMEncrypt _           ' __out IWMDRMEncrypt **ppIWMDRMEncrypt
   , BYREF ppbLicenseResponse AS DWORD _                ' __out BYTE **ppbLicenseResponse
   , BYREF pcbLicenseResponse AS DWORD _                ' __out DWORD *pcbLicenseResponse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWMDRMNetTransmitter2 Method
   ' =====================================================================================
   METHOD GetSimpleLicenseResponse ( _                  ' VTable offset = 24
     BYVAL bstrKID AS WSTRING _                         ' __in BSTR bstrKID
   , BYREF pPolicy AS WMDRMNET_POLICY _                 ' __in WMDRMNET_POLICY *pPolicy
   , BYREF ppIWMDRMEncrypt AS IWMDRMEncrypt _           ' __out IWMDRMEncrypt **ppIWMDRMEncrypt
   , BYREF ppbLicenseResponse AS DWORD _                ' __out BYTE **ppbLicenseResponse
   , BYREF pcbLicenseResponse AS DWORD _                ' __out DWORD *pcbLicenseResponse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMDRMNetTransmitter2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMDRMIndividualizationStatus
' IID = 7DB091BD-DB6A-4FA4-BCBF-0783E256C78C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMDRMIndividualizationStatus_INTERFACE_DEFINED)
    %IWMDRMIndividualizationStatus_INTERFACE_DEFINED = 1

$IID_IWMDRMIndividualizationStatus = GUID$("{7DB091BD-DB6A-4FA4-BCBF-0783E256C78C}")

INTERFACE IWMDRMIndividualizationStatus $IID_IWMDRMIndividualizationStatus

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 12
     BYREF pStatus AS WM_INDIVIDUALIZE_STATUS _         ' __out WM_INDIVIDUALIZE_STATUS *pStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMDRMIndividualizationStatus_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWMDRMLicenseBackupRestoreStatus
' IID = F653C5A2-0EB3-4503-9D88-C200552D0D55
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMDRMLicenseBackupRestoreStatus_INTERFACE_DEFINED)
    %IWMDRMLicenseBackupRestoreStatus_INTERFACE_DEFINED = 1

$IID_IWMDRMLicenseBackupRestoreStatus = GUID$("{F653C5A2-0EB3-4503-9D88-C200552D0D55}")

INTERFACE IWMDRMLicenseBackupRestoreStatus $IID_IWMDRMLicenseBackupRestoreStatus

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 12
     BYREF pStatus AS WM_BACKUP_RESTORE_STATUS _        ' __out WM_BACKUP_RESTORE_STATUS *pStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMDRMLicenseBackupRestoreStatus_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWMDRMNonSilentLicenseAquisition
' IID = 8AE059DD-BE6B-481A-863A-59056B50B748
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMDRMNonSilentLicenseAquisition_INTERFACE_DEFINED)
    %IWMDRMNonSilentLicenseAquisition_INTERFACE_DEFINED = 1

$IID_IWMDRMNonSilentLicenseAquisition = GUID$("{8AE059DD-BE6B-481A-863A-59056B50B748}")

INTERFACE IWMDRMNonSilentLicenseAquisition $IID_IWMDRMNonSilentLicenseAquisition

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetURL ( _                                    ' VTable offset = 12
     BYREF pbstrURL AS WSTRING _                        ' __out BSTR *pbstrURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChallenge ( _                              ' VTable offset = 16
     BYREF pbstrChallenge AS WSTRING _                  ' __out BSTR *pbstrChallenge
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMDRMNonSilentLicenseAquisition_INTERFACE_DEFINED__ */
