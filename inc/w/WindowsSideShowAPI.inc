' ########################################################################################
' Microsoft Windows
' File: WindowsSideShowAPI.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINDOWSSIDESHOWAPI_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "propsys.inc"

'#if (_WIN32_WINNT >= 0x0600) // Windows Vista and later
'typedef GUID APPLICATION_ID;
'typedef GUID ENDPOINT_ID;
'typedef LPWSTR DEVICE_ID;
'typedef REFGUID REFAPPLICATION_ID;
'typedef REFGUID REFENDPOINT_ID;
'typedef ENDPOINT_ID *PENDPOINT_ID;
'typedef APPLICATION_ID *PAPPLICATION_ID;
'typedef DEVICE_ID *PDEVICE_ID;
'typedef unsigned long CONTENT_ID;
'typedef CONTENT_ID *PCONTENT_ID;
'typedef unsigned long NOTIFICATION_ID;
'typedef NOTIFICATION_ID *PNOTIFICATION_ID;

'#IF NOT %DEF(%WindowsSideShowApiLibrary_LIBRARY_DEFINED__
'    %WindowsSideShowApiLibrary_LIBRARY_DEFINED__

'EXTERN_C const IID LIBID_WindowsSideShowApiLibrary;

$CLSID_SideShowSession = GUID$("{E20543B9-F785-4EA2-981E-C4FFA76BBC7C}")
$CLSID_SideShowNotification = GUID$("{0CE3E86F-D5CD-4525-A766-1ABAB1A752F5}")
$CLSID_SideShowKeyCollection = GUID$("{DFBBDBF8-18DE-49b8-83DC-EBC727C62D94}")
$CLSID_SideShowPropVariantCollection = GUID$("{E640F415-539E-4923-96CD-5F093BC250CD}")

'#endif /* __WindowsSideShowApiLibrary_LIBRARY_DEFINED__ */

' ########################################################################################
' ISideShowSession interface
' IID = E22331EE-9E7D-4922-9FC2-AB7AA41CE491
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISideShowSession_INTERFACE_DEFINED)
    %ISideShowSession_INTERFACE_DEFINED = 1

$IID_ISideShowSession = GUID$("{E22331EE-9E7D-4922-9FC2-AB7AA41CE491}")

INTERFACE ISideShowSession $IID_ISideShowSession

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RegisterContent ( _                           ' VTable offset = 12
     BYREF in_applicationId AS GUID _                   ' __in REFAPPLICATION_ID in_applicationId
   , BYREF in_endpointId AS GUID _                      ' __in REFENDPOINT_ID in_endpointId
   , BYREF out_ppIContent AS ISideShowContentManager _  ' __out ISideShowContentManager **out_ppIContent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterNotifications ( _                     ' VTable offset = 16
     BYREF in_applicationId AS GUID _                   ' __in REFAPPLICATION_ID in_applicationId
   , BYREF out_ppINotification AS ISideShowNotificationManager _ ' __out ISideShowNotificationManager **out_ppINotification
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISideShowSession_INTERFACE_DEFINED__ */

' ########################################################################################
' ISideShowNotificationManager interface
' IID = 63CEA909-F2B9-4302-B5E1-C68E6D9AB833
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISideShowNotificationManager_INTERFACE_DEFINED)
    %ISideShowNotificationManager_INTERFACE_DEFINED = 1

$IID_ISideShowNotificationManager = GUID$("{63CEA909-F2B9-4302-B5E1-C68E6D9AB833}")

INTERFACE ISideShowNotificationManager $IID_ISideShowNotificationManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Show ( _                                      ' VTable offset = 12
     BYVAL in_pINotification AS ISideShowNotification _ ' __in ISideShowNotification *in_pINotification
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Revoke ( _                                    ' VTable offset = 16
     BYVAL in_notificationId AS DWORD _                 ' __in const NOTIFICATION_ID in_notificationId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RevokeAll ( _                                 ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISideShowNotificationManager_INTERFACE_DEFINED__ */

' ########################################################################################
' ISideShowNotification interface
' IID = 03C93300-8AB2-41C5-9B79-46127A30E148
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISideShowNotification_INTERFACE_DEFINED)
    %ISideShowNotification_INTERFACE_DEFINED = 1

$IID_ISideShowNotification = GUID$("{03C93300-8AB2-41C5-9B79-46127A30E148}")

INTERFACE ISideShowNotification $IID_ISideShowNotification

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_NotificationId ( _                        ' VTable offset = 12
     BYREF out_pNotificationId AS GUID _                ' __out PNOTIFICATION_ID out_pNotificationId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_NotificationId ( _                        ' VTable offset = 16
     BYREF in_notificationId AS GUID _                  ' __in NOTIFICATION_ID in_notificationId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Title ( _                                 ' VTable offset = 20
     BYREF out_ppwszTitle AS DWORD _                    ' __out LPWSTR *out_ppwszTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Title ( _                                 ' VTable offset = 24
     BYREF in_pwszTitle AS WSTRINGZ _                   ' __in LPWSTR in_pwszTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Message ( _                               ' VTable offset = 28
     BYREF out_ppwszMessage AS DWORD _                  ' __out LPWSTR *out_ppwszMessage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Message ( _                               ' VTable offset = 32
     BYREF in_pwszMessage AS WSTRINGZ _                 ' __in LPWSTR in_pwszMessage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Image ( _                                 ' VTable offset = 36
     BYREF out_phIcon AS DWORD _                        ' __out HICON *out_phIcon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Image ( _                                 ' VTable offset = 40
     BYVAL in_hIcon AS DWORD _                          ' __in HICON in_hIcon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ExpirationTime ( _                        ' VTable offset = 44
     BYREF out_pTime AS SYSTEMTIME _                    ' __out SYSTEMTIME *out_pTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ExpirationTime ( _                        ' VTable offset = 48
     BYREF in_pTime AS SYSTEMTIME _                     ' __in SYSTEMTIME *in_pTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISideShowNotification_INTERFACE_DEFINED__ */

' ########################################################################################
' ISideShowContentManager interface
' IID = A5D5B66B-EEF9-41DB-8D7E-E17C33AB10B0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISideShowContentManager_INTERFACE_DEFINED)
    %ISideShowContentManager_INTERFACE_DEFINED = 1

$IID_ISideShowContentManager = GUID$("{A5D5B66B-EEF9-41DB-8D7E-E17C33AB10B0}")

INTERFACE ISideShowContentManager $IID_ISideShowContentManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Add ( _                                       ' VTable offset = 12
     BYVAL in_pIContent AS ISideShowContent _           ' __in ISideShowContent *in_pIContent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Remove ( _                                    ' VTable offset = 16
     BYREF in_contentId AS GUID _                       ' __in const CONTENT_ID in_contentId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAll ( _                                 ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEventSink ( _                              ' VTable offset = 24
     BYVAL in_pIEvents AS ISideShowEvents _             ' __in ISideShowEvents *in_pIEvents
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceCapabilities ( _                     ' VTable offset = 28
     BYREF out_ppCollection AS ISideShowCapabilitiesCollection _ ' __out ISideShowCapabilitiesCollection **out_ppCollection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISideShowContentManager_INTERFACE_DEFINED__ */

' ########################################################################################
' ISideShowContent interface
' IID = C18552ED-74FF-4FEC-BE07-4CFED29D4887
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISideShowContent_INTERFACE_DEFINED)
    %ISideShowContent_INTERFACE_DEFINED = 1

$IID_ISideShowContent = GUID$("{C18552ED-74FF-4FEC-BE07-4CFED29D4887}")

INTERFACE ISideShowContent $IID_ISideShowContent

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetContent ( _                                ' VTable offset = 12
     BYVAL in_pICapabilities AS ISideShowCapabilities _ ' __in ISideShowCapabilities *in_pICapabilities
   , BYREF out_pdwSize AS DWORD _                       ' __out DWORD *out_pdwSize
   , BYREF out_ppbData AS DWORD _                       ' __out BYTE **out_ppbData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ContentId ( _                             ' VTable offset = 16
     BYREF out_pcontentId AS DWORD _                    ' __out PCONTENT_ID out_pcontentId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_DifferentiateContent ( _                  ' VTable offset = 20
     BYREF out_pfDifferentiateContent AS LONG _         ' __out BOOL *out_pfDifferentiateContent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISideShowContent_INTERFACE_DEFINED__ */

' ########################################################################################
' ISideShowEvents interface
' IID = 61FECA4C-DEB4-4A7E-8D75-51F1132D615B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISideShowEvents_INTERFACE_DEFINED)
    %ISideShowEvents_INTERFACE_DEFINED = 1

$IID_ISideShowEvents = GUID$("{61FECA4C-DEB4-4A7E-8D75-51F1132D615B}")

INTERFACE ISideShowEvents $IID_ISideShowEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ContentMissing ( _                            ' VTable offset = 12
     BYVAL in_contentId AS DWORD _                      ' __in const CONTENT_ID in_contentId
   , BYREF out_ppIContent AS ISideShowContent _         ' __out ISideShowContent **out_ppIContent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ApplicationEvent ( _                          ' VTable offset = 16
     BYVAL in_pICapabilities AS ISideShowCapabilities _ ' __in ISideShowCapabilities *in_pICapabilities
   , BYVAL in_dwEventId AS DWORD _                      ' __in const DWORD in_dwEventId
   , BYVAL in_dwEventSize AS DWORD _                    ' __in const DWORD in_dwEventSize
   , BYVAL in_pbEventData AS BYTE PTR _                 ' __in const BYTE *in_pbEventData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeviceAdded ( _                               ' VTable offset = 20
     BYVAL in_pIDevice AS ISideShowCapabilities _       ' __in ISideShowCapabilities *in_pIDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeviceRemoved ( _                             ' VTable offset = 24
     BYVAL in_pIDevice AS ISideShowCapabilities _       ' __in ISideShowCapabilities *in_pIDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISideShowEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' ISideShowCapabilities interface
' IID = 535E1379-C09E-4A54-A511-597BAB3A72B8
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISideShowCapabilities_INTERFACE_DEFINED)
    %ISideShowCapabilities_INTERFACE_DEFINED = 1

$IID_ISideShowCapabilities = GUID$("{535E1379-C09E-4A54-A511-597BAB3A72B8}")

INTERFACE ISideShowCapabilities $IID_ISideShowCapabilities

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCapability ( _                             ' VTable offset = 12
     BYREF in_keyCapability AS PROPERTYKEY _            ' __in REFPROPERTYKEY in_keyCapability
   , BYREF inout_pValue AS PROPVARIANT _                ' __in_out PROPVARIANT *inout_pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISideShowCapabilities_INTERFACE_DEFINED__ */

' ########################################################################################
' ISideShowCapabilitiesCollection interface
' IID = 50305597-5E0D-4FF7-B3AF-33D0D9BD52DD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISideShowCapabilitiesCollection_INTERFACE_DEFINED)
    %ISideShowCapabilitiesCollection_INTERFACE_DEFINED = 1

$IID_ISideShowCapabilitiesCollection = GUID$("{50305597-5E0D-4FF7-B3AF-33D0D9BD52DD}")

INTERFACE ISideShowCapabilitiesCollection $IID_ISideShowCapabilitiesCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF out_pdwCount AS DWORD _                      ' __out DWORD *out_pdwCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL in_dwIndex AS DWORD _                        ' __in DWORD in_dwIndex
   , BYREF out_ppCapabilities AS ISideShowCapabilities _ ' __out ISideShowCapabilities **out_ppCapabilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISideShowCapabilitiesCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' ISideShowBulkCapabilities interface
' IID = 3A2B7FBC-3AD5-48bd-BBF1-0E6CFBD10807
' Inherited interface = ISideShowCapabilities
' ########################################################################################

#IF NOT %DEF(%ISideShowBulkCapabilities_INTERFACE_DEFINED)
    %ISideShowBulkCapabilities_INTERFACE_DEFINED = 1

$IID_ISideShowBulkCapabilities = GUID$("{3A2B7FBC-3AD5-48bd-BBF1-0E6CFBD10807}")

INTERFACE ISideShowBulkCapabilities $IID_ISideShowBulkCapabilities

   INHERIT IUnknown

   ' =====================================================================================
   ' ISideShowCapabilities method
   ' =====================================================================================
   METHOD GetCapability ( _                             ' VTable offset = 12
     BYREF in_keyCapability AS PROPERTYKEY _            ' __in REFPROPERTYKEY in_keyCapability
   , BYREF inout_pValue AS PROPVARIANT _                ' __in_out PROPVARIANT *inout_pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISideShowBulkCapabilities method
   ' =====================================================================================
   METHOD GetCapabilities ( _                           ' VTable offset = 16
     BYVAL in_keyCollection AS ISideShowKeyCollection _ ' __in ISideShowKeyCollection *in_keyCollection
   , BYREF inout_pValues AS ISideShowPropVariantCollection _ ' __inout ISideShowPropVariantCollection **inout_pValues
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISideShowBulkCapabilities_INTERFACE_DEFINED__ */

' ########################################################################################
' ISideShowKeyCollection interface
' IID = 045473BC-A37B-4957-B144-68105411ED8E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISideShowKeyCollection_INTERFACE_DEFINED)
    %ISideShowKeyCollection_INTERFACE_DEFINED = 1

$IID_ISideShowKeyCollection = GUID$("{045473BC-A37B-4957-B144-68105411ED8E}")

INTERFACE ISideShowKeyCollection $IID_ISideShowKeyCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Add ( _                                       ' VTable offset = 12
     BYREF Key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY Key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 20
     BYVAL dwIndex AS DWORD _                           ' __in const DWORD dwIndex
   , BYREF pKey AS PROPERTYKEY _                        ' __inout PROPERTYKEY *pKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 24
     BYREF pcElems AS DWORD _                           ' __in DWORD *pcElems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAt ( _                                  ' VTable offset = 28
     BYVAL dwIndex AS DWORD _                           ' __in const DWORD dwIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISideShowKeyCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' ISideShowPropVariantCollection interface
' IID = 2EA7A549-7BFF-4aae-BAB0-22D43111DE49
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISideShowPropVariantCollection_INTERFACE_DEFINED)
    %ISideShowPropVariantCollection_INTERFACE_DEFINED = 1

$IID_ISideShowPropVariantCollection = GUID$("{2EA7A549-7BFF-4aae-BAB0-22D43111DE49}")

INTERFACE ISideShowPropVariantCollection $IID_ISideShowPropVariantCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Add ( _                                       ' VTable offset = 12
     BYREF pValue AS PROPVARIANT _                      ' __in REFPROPERTYKEY pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 20
     BYVAL dwIndex AS DWORD _                           ' __in const DWORD dwIndex
   , BYREF pValue AS PROPVARIANT _                      ' __inout PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 24
     BYREF pcElems AS DWORD _                           ' __in DWORD *pcElems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAt ( _                                  ' VTable offset = 28
     BYVAL dwIndex AS DWORD _                           ' __in const DWORD dwIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF ' /* __ISideShowPropVariantCollection_INTERFACE_DEFINED__ */

'#endif // (_WIN32_WINNT >= 0x0600)
