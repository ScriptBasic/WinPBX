' ########################################################################################
' Microsoft Windows
' File: Wia.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WIA_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "propidl.inc"

' // Size = 24 bytes
TYPE WIA_DITHER_PATTERN_DATA DWORD
   lSize           AS LONG       ' LONG
   bstrPatternName AS DWORD      ' BSTR
   lPatternWidth   AS LONG       ' LONG
   lPatternLength  AS LONG       ' LONG
   cbPattern       AS LONG       ' LONG
   pbPattern       AS BYTE PTR   ' BYTE *
END TYPE

' // Size = 8 bytes
TYPE WIA_PROPID_TO_NAME DWORD
   propid  AS DWORD          ' PROPID
   pszName AS WSTRINGZ PTR   ' LPOLESTR
END TYPE

' // Size = 20 bytes
TYPE WIA_FORMAT_INFO DWORD
   guidFormatID AS GUID
   lTymed       AS LONG
END TYPE

#INCLUDE ONCE "wiadef.inc"


' ########################################################################################
' Interface name = IWiaDevMgr
' IID = {5EB2502A-8CF1-11D1-BF92-0060081ED811}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWiaDevMgr_INTERFACE_DEFINED)
    %IWiaDevMgr_INTERFACE_DEFINED = 1

$IID_IWiaDevMgr = GUID$("{5EB2502A-8CF1-11D1-BF92-0060081ED811}")

INTERFACE IWiaDevMgr $IID_IWiaDevMgr

   INHERIT IAutomation

   ' =====================================================================================
   METHOD EnumDeviceInfo ( _                            ' VTable offset = 12
     BYVAL lFlag AS LONG _                              ' __in LONG lFlag
   ) AS IEnumWIA_DEV_INFO                               ' __retval_out IEnumWIA_DEV_INFO **ppIEnum
   ' =====================================================================================
   METHOD CreateDevice ( _                              ' VTable offset = 16
     BYVAL bstrDeviceID AS WSTRING _                    ' __in BSTR bstrDeviceID
   ) AS IWiaItem                                        ' __out IWiaItem **ppWiaItemRoot
   ' =====================================================================================
   METHOD SelectDeviceDlg ( _                           ' VTable offset = 20
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYVAL lDeviceType AS LONG _                        ' __in LONG lDeviceType
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYREF pbstrDeviceID AS WSTRING _                   ' __inout BSTR *pbstrDeviceID
   ) AS IWiaItem                                        ' __retval_out IWiaItem **ppItemRoot
   ' =====================================================================================
   METHOD SelectDeviceDlgID ( _                         ' VTable offset = 24
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYVAL lDeviceType AS LONG _                        ' __in LONG lDeviceType
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDeviceID
   ' =====================================================================================
   METHOD GetImageDlg ( _                               ' VTable offset = 28
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYVAL lDeviceType AS LONG _                        ' __in LONG lDeviceType
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL lIntent AS LONG _                            ' __in LONG lIntent
   , BYVAL pItemRoot AS IWiaItem _                      ' __in IWiaItem *pItemRoot
   , BYVAL bstrFilename AS WSTRING _                    ' __in BSTR bstrFilename
   , BYREF pguidFormat AS GUID _                        ' __inout GUID *pguidFormat
   )                                                    ' void
   ' =====================================================================================
   METHOD RegisterEventCallbackProgram ( _              ' VTable offset = 32
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL bstrDeviceID AS WSTRING _                    ' __in BSTR bstrDeviceID
   , BYREF pEventGUID AS GUID _                         ' __in const GUID *pEventGUID
   , BYVAL bstrCommandline AS WSTRING _                 ' __in BSTR bstrCommandline
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   , BYVAL bstrIcon AS WSTRING _                        ' __in BSTR bstrIcon
   )                                                    ' void
   ' =====================================================================================
   METHOD RegisterEventCallbackInterface ( _            ' VTable offset = 36
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL bstrDeviceID AS WSTRING _                    ' __in BSTR bstrDeviceID
   , BYREF pEventGUID AS GUID _                         ' __in const GUID *pEventGUID
   , BYVAL pIWiaEventCallback AS IWiaEventCallback _    ' __in IWiaEventCallback *pIWiaEventCallback
   , BYREF pEventObject AS IUnknown _                   ' __out IUnknown **pEventObject
   )                                                    ' void
   ' =====================================================================================
   METHOD RegisterEventCallbackCLSID ( _                ' VTable offset = 40
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL bstrDeviceID AS WSTRING _                    ' __in BSTR bstrDeviceID
   , BYREF pEventGUID AS GUID _                         ' __in const GUID *pEventGUID
   , BYREF pClsID AS GUID _                             ' __in const GUID *pClsID
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   , BYVAL bstrIcon AS WSTRING _                        ' __in BSTR bstrIcon
   )                                                    ' void
   ' =====================================================================================
   METHOD AddDeviceDlg ( _                              ' VTable offset = 44
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWiaDevMgr_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumWIA_DEV_INFO
' IID = {5E38B83C-8CF1-11D1-BF92-0060081ED811}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumWIA_DEV_INFO_INTERFACE_DEFINED)
    %IEnumWIA_DEV_INFO_INTERFACE_DEFINED = 1

$IID_IEnumWIA_DEV_INFO = GUID$("{5E38B83C-8CF1-11D1-BF92-0060081ED811}")

INTERFACE IEnumWIA_DEV_INFO $IID_IEnumWIA_DEV_INFO

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS LONG _                               ' __in ULONG celt
   , BYREF rgelt AS IWiaPropertyStorage _               ' __out IWiaPropertyStorage **rgelt
   , BYREF pceltFetched AS DWORD _                      ' __inout ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppIEnum AS IEnumWIA_DEV_INFO _               ' __out IEnumWIA_DEV_INFO **ppIEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 28
     BYREF celt AS DWORD _                              ' __out ULONG *celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumWIA_DEV_INFO_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWiaEventCallback
' IID = {AE6287B0-0084-11D2-973B-00A0C9068F2E}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWiaEventCallback_INTERFACE_DEFINED)
    %IWiaEventCallback_INTERFACE_DEFINED = 1

$IID_IWiaEventCallback = GUID$("{AE6287B0-0084-11D2-973B-00A0C9068F2E}")

INTERFACE IWiaEventCallback $IID_IWiaEventCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ImageEventCallback ( _                        ' VTable offset = 12
     BYREF pEventGUID AS GUID _                         ' __in const GUID *pEventGUID
   , BYVAL bstrEventDescription AS WSTRING _            ' __in BSTR bstrEventDescription
   , BYVAL bstrDeviceID AS WSTRING _                    ' __in BSTR bstrDeviceID
   , BYVAL bstrDeviceDescription AS WSTRING _           ' __in BSTR bstrDeviceDescription
   , BYVAL dwDeviceType AS DWORD _                      ' __in DWORD dwDeviceType
   , BYVAL bstrFullItemName AS WSTRING _                ' __in BSTR bstrFullItemName
   , BYREF pulEventType AS DWORD _                      ' __inout ULONG *pulEventType
   , BYVAL ulReserved AS DWORD _                        ' __in ULONG ulReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF    ' /* __IWiaEventCallback_INTERFACE_DEFINED__ */


' // Size = 28 bytes
TYPE WIA_DATA_CALLBACK_HEADER DWORD
   lSize        AS LONG
   guidFormatID AS GUID
   lBufferSize  AS LONG
   lPageCount   AS LONG
END TYPE

' ########################################################################################
' Interface name = IWiaDataCallback
' IID = {A558A866-A5B0-11D2-A08F-00C04F72DC3C}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWiaDataCallback_INTERFACE_DEFINED)
    %IWiaDataCallback_INTERFACE_DEFINED = 1

$IID_IWiaDataCallback = GUID$("{A558A866-A5B0-11D2-A08F-00C04F72DC3C}")

INTERFACE IWiaDataCallback $IID_IWiaDataCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD BandedDataCallback ( _                        ' VTable offset = 12
     BYVAL lMessage AS LONG _                           ' __in LONG lMessage
   , BYVAL lStatus AS LONG _                            ' __in LONG lStatus
   , BYVAL lPercentComplete AS LONG _                   ' __in LONG lPercentComplete
   , BYVAL lOffset AS LONG _                            ' __in LONG lOffset
   , BYVAL lLength AS LONG _                            ' __in LONG lLength
   , BYVAL lReserved AS LONG _                          ' __in LONG lReserved
   , BYVAL lResLength AS LONG _                         ' __in LONG lResLength
   , BYVAL pbBuffer AS BYTE PTR _                       ' __in BYTE *pbBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWiaDataCallback_INTERFACE_DEFINED__ */


' // Size = 28 bytes
TYPE WIA_DATA_TRANSFER_INFO DWORD
   ulSize        AS DWORD   ' ULONG
   ulSection     AS DWORD   ' ULONG
   ulBufferSize  AS DWORD   ' ULONG
   bDoubleBuffer AS LONG    ' BOOL
   ulReserved1   AS DWORD   ' ULONG
   ulReserved2   AS DWORD   ' ULONG
   ulReserved3   AS DWORD   ' ULONG
END TYPE

' // Size = 20 bytes
TYPE WIA_EXTENDED_TRANSFER_INFO DWORD
   ulSize              AS DWORD   ' ULONG
   ulMinBufferSize     AS DWORD   ' ULONG
   ulOptimalBufferSize AS DWORD   ' ULONG
   ulMaxBufferSize     AS DWORD   ' ULONG
   ulNumBuffers        AS DWORD   ' ULONG
END TYPE


' ########################################################################################
' Interface name = IWiaDataTransfer
' IID = {A6CEF998-A5B0-11D2-A08F-00C04F72DC3C}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWiaDataTransfer_INTERFACE_DEFINED)
    %IWiaDataTransfer_INTERFACE_DEFINED = 1

$IID_IWiaDataTransfer = GUID$("{A6CEF998-A5B0-11D2-A08F-00C04F72DC3C}")

INTERFACE IWiaDataTransfer $IID_IWiaDataTransfer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD idtGetData ( _                                ' VTable offset = 12
     BYREF pMedium AS STGMEDIUM _                       ' __inout LPSTGMEDIUM pMedium
   , BYVAL pIWiaDataCallback AS IWiaDataCallback _      ' __in IWiaDataCallback *pIWiaDataCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD idtGetBandedData ( _                          ' VTable offset = 16
     BYREF pWiaDataTransInfo AS WIA_DATA_TRANSFER_INFO _ ' __in PWIA_DATA_TRANSFER_INFO pWiaDataTransInfo
   , BYVAL pIWiaDataCallback AS IWiaDataCallback _      ' __in IWiaDataCallback *pIWiaDataCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD idtQueryGetData ( _                           ' VTable offset = 20
     BYREF pfe AS WIA_FORMAT_INFO _                     ' __in WIA_FORMAT_INFO *pfe
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD idtEnumWIA_FORMAT_INFO ( _                    ' VTable offset = 24
     BYREF ppEnum AS IEnumWIA_FORMAT_INFO _             ' __out IEnumWIA_FORMAT_INFO **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD idtGetExtendedTransferInfo ( _                ' VTable offset = 28
     BYREF pExtendedTransferInfo AS WIA_EXTENDED_TRANSFER_INFO _ ' __out PWIA_EXTENDED_TRANSFER_INFO pExtendedTransferInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWiaDataTransfer_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWiaItem
' IID = {4DB1AD10-3391-11D2-9A33-00C04FA36145}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWiaItem_INTERFACE_DEFINED)
    %IWiaItem_INTERFACE_DEFINED = 1

$IID_IWiaItem = GUID$("{4DB1AD10-3391-11D2-9A33-00C04FA36145}")

INTERFACE IWiaItem $IID_IWiaItem

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetItemType ( _                               ' VTable offset = 12
     BYREF pItemType AS LONG _                          ' __out LONG *pItemType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AnalyzeItem ( _                               ' VTable offset = 16
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumChildItems ( _                            ' VTable offset = 20
     BYREF ppIEnumWiaItem AS IEnumWiaItem _             ' __out IEnumWiaItem **ppIEnumWiaItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteItem ( _                                ' VTable offset = 24
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateChildItem ( _                           ' VTable offset = 28
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL bstrItemName AS WSTRING _                    ' __in BSTR bstrItemName
   , BYVAL bstrFullItemName AS WSTRING _                ' __in BSTR bstrFullItemName
   , BYREF ppIWiaItem AS IWiaItem _                     ' __out IWiaItem **ppIWiaItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumRegisterEventInfo ( _                     ' VTable offset = 32
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYREF pEventGUID AS GUID _                         ' __in const GUID *pEventGUID
   , BYREF ppIEnum AS IEnumWIA_DEV_CAPS _               ' __out IEnumWIA_DEV_CAPS **ppIEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindItemByName ( _                            ' VTable offset = 36
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL bstrFullItemName AS WSTRING _                ' __in BSTR bstrFullItemName
   , BYREF ppIWiaItem AS IWiaItem _                     ' __out IWiaItem **ppIWiaItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeviceDlg ( _                                 ' VTable offset = 40
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL lIntent AS LONG _                            ' __in LONG lIntent
   , BYREF plItemCount AS LONG _                        ' __out LONG *plItemCount
   , BYREF ppIWiaItem AS IWiaItem _                     ' __out IWiaItem ***ppIWiaItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeviceCommand ( _                             ' VTable offset = 44
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYREF pCmdGUID AS GUID _                           ' __in const GUID *pCmdGUID
   , BYREF pIWiaItem AS IWiaItem _                      ' __inout IWiaItem **pIWiaItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRootItem ( _                               ' VTable offset = 48
     BYREF ppIWiaItem AS IWiaItem _                     ' __out IWiaItem **ppIWiaItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumDeviceCapabilities ( _                    ' VTable offset = 52
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYREF ppIEnumWIA_DEV_CAPS AS IEnumWIA_DEV_CAPS _   ' __out IEnumWIA_DEV_CAPS **ppIEnumWIA_DEV_CAPS
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DumpItemData ( _                              ' VTable offset = 56
     BYREF bstrData AS WSTRING _                        ' __out BSTR *bstrData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DumpDrvItemData ( _                           ' VTable offset = 60
     BYREF bstrData AS WSTRING _                        ' __out BSTR *bstrData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DumpTreeItemData ( _                          ' VTable offset = 64
     BYREF bstrData AS WSTRING _                        ' __out BSTR *bstrData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Diagnostic ( _                                ' VTable offset = 68
     BYVAL ulSize AS DWORD _                            ' __in ULONG ulSize
   , BYVAL pBuffer AS BYTE PTR _                        ' __in BYTE *pBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWiaItem_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWiaPropertyStorage
' IID = {98B5E8A0-29CC-491a-AAC0-E6DB4FDCCEB6}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWiaPropertyStorage_INTERFACE_DEFINED)
    %IWiaPropertyStorage_INTERFACE_DEFINED = 1

$IID_IWiaPropertyStorage = GUID$("{98B5E8A0-29CC-491a-AAC0-E6DB4FDCCEB6}")

INTERFACE IWiaPropertyStorage $IID_IWiaPropertyStorage

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ReadMultiple ( _                              ' VTable offset = 12
     BYVAL cpspec AS DWORD _                            ' __in ULONG cpspec
   , BYREF rgpspec AS PROPSPEC _                        ' __in const PROPSPEC rgpspec[  ]
   , BYREF rgpropvar AS PROPVARIANT _                   ' __out PROPVARIANT rgpropvar[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteMultiple ( _                             ' VTable offset = 16
     BYVAL cpspec AS DWORD _                            ' __in ULONG cpspec
   , BYREF rgpspec AS PROPSPEC _                        ' __in const PROPSPEC rgpspec[  ]
   , BYREF rgpropvar AS PROPVARIANT _                   ' __in const PROPVARIANT rgpropvar[  ]
   , BYVAL propidNameFirst AS DWORD _                   ' __in PROPID propidNameFirst
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteMultiple ( _                            ' VTable offset = 20
     BYVAL cpspec AS DWORD _                            ' __in ULONG cpspec
   , BYREF rgpspec AS PROPSPEC _                        ' __in const PROPSPEC rgpspec[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReadPropertyNames ( _                         ' VTable offset = 24
     BYVAL cpropid AS DWORD _                           ' __in ULONG cpropid
   , BYREF rgpropid AS DWORD _                          ' __in const PROPID rgpropid[  ]
   , BYREF rglpwstrName AS DWORD _                      ' __out LPOLESTR rglpwstrName[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WritePropertyNames ( _                        ' VTable offset = 28
     BYVAL cpropid AS DWORD _                           ' __in ULONG cpropid
   , BYREF rgpropid AS DWORD _                          ' __in const PROPID rgpropid[  ]
   , BYREF rglpwstrName AS DWORD _                      ' __in const LPOLESTR rglpwstrName[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeletePropertyNames ( _                       ' VTable offset = 32
     BYVAL cpropid AS DWORD _                           ' __in ULONG cpropid
   , BYREF rgpropid AS DWORD _                          ' __in const PROPID rgpropid[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 36
     BYVAL grfCommitFlags AS DWORD _                    ' __in DWORD grfCommitFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Revert ( _                                    ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Enum ( _                                      ' VTable offset = 44
     BYREF ppenum AS IEnumSTATPROPSTG _                 ' __out IEnumSTATPROPSTG **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTimes ( _                                  ' VTable offset = 48
     BYREF pctime AS FILETIME _                         ' __in const FILETIME *pctime
   , BYREF patime AS FILETIME _                         ' __in const FILETIME *patime
   , BYREF pmtime AS FILETIME _                         ' __in const FILETIME *pmtime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClass ( _                                  ' VTable offset = 52
     BYREF clsid AS GUID _                              ' __in REFCLSID clsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stat ( _                                      ' VTable offset = 56
     BYREF pstatpsstg AS STATPROPSETSTG _               ' __out STATPROPSETSTG *pstatpsstg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyAttributes ( _                     ' VTable offset = 60
     BYVAL cpspec AS DWORD _                            ' __in ULONG cpspec
   , BYREF rgpspec AS PROPSPEC _                        ' __in PROPSPEC rgpspec[  ]
   , BYREF rgflags AS DWORD _                           ' __out ULONG rgflags[  ]
   , BYREF rgpropvar AS PROPVARIANT _                   ' __out PROPVARIANT rgpropvar[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 64
     BYREF pulNumProps AS DWORD _                       ' __out ULONG *pulNumProps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyStream ( _                         ' VTable offset = 68
     BYREF pCompatibilityId AS GUID _                   ' __out GUID *pCompatibilityId
   , BYREF ppIStream AS IStream _                       ' __out IStream **ppIStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPropertyStream ( _                         ' VTable offset = 72
     BYREF pCompatibilityId AS GUID _                   ' __in GUID *pCompatibilityId
   , BYVAL pIStream AS IStream _                        ' __in IStream *pIStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWiaPropertyStorage_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumWiaItem
' IID = {5E8383FC-3391-11D2-9A33-00C04FA36145}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumWiaItem_INTERFACE_DEFINED)
    %IEnumWiaItem_INTERFACE_DEFINED = 1

$IID_IEnumWiaItem = GUID$("{5E8383FC-3391-11D2-9A33-00C04FA36145}")

INTERFACE IEnumWiaItem $IID_IEnumWiaItem

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppIWiaItem AS IWiaItem _                     ' __out IWiaItem **ppIWiaItem
   , BYREF pceltFetched AS DWORD _                      ' __inout ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppIEnum AS IEnumWiaItem _                    ' __out IEnumWiaItem **ppIEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 28
     BYREF celt AS DWORD _                              ' __out ULONG *celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumWiaItem_INTERFACE_DEFINED__ */


' // Size = 36 bytes
TYPE WIA_DEV_CAP DWORD
   guid            AS GUID    ' GUID
   ulFlags         AS DWORD   ' ULONG
   bstrName        AS DWORD   ' BSTR
   bstrDescription AS DWORD   ' BSTR
   bstrIcon        AS DWORD   ' BSTR
   bstrCommandline AS DWORD   ' BSTR
END TYPE


' ########################################################################################
' Interface name = IEnumWIA_DEV_CAPS
' IID = {1FCC4287-ACA6-11D2-A093-00C04F72DC3C}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumWIA_DEV_CAPS_INTERFACE_DEFINED)
    %IEnumWIA_DEV_CAPS_INTERFACE_DEFINED = 1

$IID_IEnumWIA_DEV_CAPS = GUID$("{1FCC4287-ACA6-11D2-A093-00C04F72DC3C}")

INTERFACE IEnumWIA_DEV_CAPS $IID_IEnumWIA_DEV_CAPS

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS WIA_DEV_CAP _                       ' __out WIA_DEV_CAP *rgelt
   , BYREF pceltFetched AS DWORD _                      ' __inout ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppIEnum AS IEnumWIA_DEV_CAPS _               '  __out IEnumWIA_DEV_CAPS **ppIEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 28
     BYREF pcelt AS DWORD _                             ' __out ULONG *pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumWIA_DEV_CAPS_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumWIA_FORMAT_INFO
' IID = {81BEFC5B-656D-44f1-B24C-D41D51B4DC81}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumWIA_FORMAT_INFO_INTERFACE_DEFINED)
    %IEnumWIA_FORMAT_INFO_INTERFACE_DEFINED = 1

$IID_IEnumWIA_FORMAT_INFO = GUID$("{81BEFC5B-656D-44f1-B24C-D41D51B4DC81}")

INTERFACE IEnumWIA_FORMAT_INFO $IID_IEnumWIA_FORMAT_INFO

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS WIA_FORMAT_INFO _                   ' __out WIA_FORMAT_INFO *rgelt
   , BYREF pceltFetched AS DWORD _                      ' __inout ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppIEnum AS IEnumWIA_FORMAT_INFO _            ' __out IEnumWIA_FORMAT_INFO **ppIEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 28
     BYREF pcelt AS DWORD _                             ' __out ULONG *pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumWIA_FORMAT_INFO_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWiaLog
' IID = {A00C10B6-82A1-452F-8B6C-86062AAD6890}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWiaLog_INTERFACE_DEFINED)
    %IWiaLog_INTERFACE_DEFINED = 1

$IID_IWiaLog = GUID$("{A00C10B6-82A1-452F-8B6C-86062AAD6890}")

INTERFACE IWiaLog $IID_IWiaLog

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InitializeLog ( _                             ' VTable offset = 12
     BYVAL hInstance AS LONG _                          ' __in LONG hInstance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD hResult ( _                                   ' VTable offset = 16
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Log ( _                                       ' VTable offset = 20
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL lResID AS LONG _                             ' __in LONG lResID
   , BYVAL lDetail AS LONG _                            ' __in LONG lDetail
   , BYVAL bstrText AS WSTRING _                        ' __in BSTR bstrText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWiaLog_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWiaLogEx
' IID = {AF1F22AC-7A40-4787-B421-AEb47A1FBD0B}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWiaLogEx_INTERFACE_DEFINED)
    %IWiaLogEx_INTERFACE_DEFINED = 1

$IID_IWiaLogEx = GUID$("{AF1F22AC-7A40-4787-B421-AEb47A1FBD0B}")

INTERFACE IWiaLogEx $IID_IWiaLogEx

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InitializeLogEx ( _                           ' VTable offset = 12
     BYVAL hInstance AS LONG _                          ' __in LONG hInstance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD hResult ( _                                   ' VTable offset = 16
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Log ( _                                       ' VTable offset = 20
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL lResID AS LONG _                             ' __in LONG lResID
   , BYVAL lDetail AS LONG _                            ' __in LONG lDetail
   , BYVAL bstrText AS WSTRING _                        ' __in BSTR bstrText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD hResultEx ( _                                 ' VTable offset = 24
     BYVAL lMethodId AS LONG _                          ' __in LONG lMethodId
   , BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LogEx ( _                                     ' VTable offset = 28
     BYVAL lMethodId AS LONG _                          ' __in LONG lMethodId
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL lResID AS LONG _                             ' __in LONG lResID
   , BYVAL lDetail AS LONG _                            ' __in LONG lDetail
   , BYVAL bstrText AS WSTRING _                        ' __in BSTR bstrText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWiaLogEx_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWiaNotifyDevMgr
' IID = {70681EA0-E7BF-4291-9FB1-4E8813A3F78E}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWiaNotifyDevMgr_INTERFACE_DEFINED)
    %IWiaNotifyDevMgr_INTERFACE_DEFINED = 1

$IID_IWiaNotifyDevMgr = GUID$("{70681EA0-E7BF-4291-9FB1-4E8813A3F78E}")

INTERFACE IWiaNotifyDevMgr $IID_IWiaNotifyDevMgr

   INHERIT IUnknown

   ' =====================================================================================
   METHOD NewDeviceArrival ( _                          ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWiaNotifyDevMgr_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWiaItemExtras
' IID = {6291EF2C-36EF-4532-876A-8E132593778D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWiaItemExtras_INTERFACE_DEFINED)
    %IWiaItemExtras_INTERFACE_DEFINED = 1

$IID_IWiaItemExtras = GUID$("{6291EF2C-36EF-4532-876A-8E132593778D}")

INTERFACE IWiaItemExtras $IID_IWiaItemExtras

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetExtendedErrorInfo ( _                      ' VTable offset = 12
     BYREF bstrErrorText AS WSTRING _                   ' __out BSTR *bstrErrorText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Escape ( _                                    ' VTable offset = 16
     BYVAL dwEscapeCode AS DWORD _                      ' __in DWORD dwEscapeCode
   , BYVAL lpInData AS BYTE PTR _                       ' __in BYTE *lpInData
   , BYVAL cbInDataSize AS DWORD _                      ' __in DWORD cbInDataSize
   , BYVAL pOutData AS BYTE PTR _                       ' __out BYTE *pOutData
   , BYVAL dwOutDataSize AS DWORD _                     ' __in DWORD dwOutDataSize
   , BYREF pdwActualDataSize AS DWORD _                 ' __out DWORD *pdwActualDataSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CancelPendingIO ( _                           ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWiaItemExtras_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWiaAppErrorHandler
' IID = {6C16186C-D0A6-400c-80F4-D26986A0E734}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWiaAppErrorHandler_INTERFACE_DEFINED)
    %IWiaAppErrorHandler_INTERFACE_DEFINED = 1

$IID_IWiaAppErrorHandler = GUID$("{6C16186C-D0A6-400c-80F4-D26986A0E734}")

INTERFACE IWiaAppErrorHandler $IID_IWiaAppErrorHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetWindow ( _                                 ' VTable offset = 12
     BYREF phwnd AS DWORD _                             ' __out HWND *phwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReportStatus ( _                              ' VTable offset = 16
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL pWiaItem2 AS IWiaItem2 _                     ' __in IWiaItem2 *pWiaItem2
   , BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   , BYVAL lPercentComplete AS LONG _                   ' __in LONG lPercentComplete
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWiaAppErrorHandler_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWiaErrorHandler
' IID = {6C16186C-D0A6-400c-80F4-D26986A0E734}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWiaErrorHandler_INTERFACE_DEFINED)
    %IWiaErrorHandler_INTERFACE_DEFINED = 1

$IID_IWiaErrorHandler = GUID$("{6C16186C-D0A6-400c-80F4-D26986A0E734}")

INTERFACE IWiaErrorHandler $IID_IWiaErrorHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ReportStatus ( _                              ' VTable offset = 12
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYVAL pWiaItem2 AS IWiaItem2 _                     ' __in IWiaItem2 *pWiaItem2
   , BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   , BYVAL lPercentComplete AS LONG _                   ' __in LONG lPercentComplete
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatusDescription ( _                      ' VTable offset = 16
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL pWiaItem2 AS IWiaItem2 _                     ' __in IWiaItem2 *pWiaItem2
   , BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   , BYREF pbstrDescription AS WSTRING _                ' __out BSTR *pbstrDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWiaErrorHandler_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWiaTransfer
' IID = {C39D6942-2F4E-4D04-92FE-4EF4D3A1DE5A}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWiaTransfer_INTERFACE_DEFINED)
    %IWiaTransfer_INTERFACE_DEFINED = 1

$IID_IWiaTransfer = GUID$("{C39D6942-2F4E-4D04-92FE-4EF4D3A1DE5A}")

INTERFACE IWiaTransfer $IID_IWiaTransfer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Download ( _                                  ' VTable offset = 12
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL pIWiaTransferCallback AS IWiaTransferCallback _ ' __in IWiaTransferCallback *pIWiaTransferCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Upload ( _                                    ' VTable offset = 16
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL pSource AS IStream _                         ' __in IStream *pSource
   , BYVAL pIWiaTransferCallback AS IWiaTransferCallback _ ' __in IWiaTransferCallback *pIWiaTransferCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumWIA_FORMAT_INFO ( _                       ' VTable offset = 24
     BYREF ppEnum AS IEnumWIA_FORMAT_INFO _             ' __out IEnumWIA_FORMAT_INFO **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWiaTransfer_INTERFACE_DEFINED__ */

' // Size = 24 bytes
TYPE WiaTransferParams   ' Must be 8 byte aligned
   lMessage           AS LONG    ' LONG
   lPercentComplete   AS LONG    ' LONG
   ulTransferredBytes AS QUAD    ' ULONG64
   hrErrorStatus      AS LONG    ' HRESULT
   alignment__        AS DWORD   ' // To keep 8 byte alignment
END TYPE


' ########################################################################################
' Interface name = IWiaTransferCallback
' IID = {C39D6942-2F4E-4D04-92FE-4EF4D3A1DE5A}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWiaTransferCallback_INTERFACE_DEFINED)
    %IWiaTransferCallback_INTERFACE_DEFINED = 1

$IID_IWiaTransferCallback = GUID$("{C39D6942-2F4E-4D04-92FE-4EF4D3A1DE5A}")

INTERFACE IWiaTransferCallback $IID_IWiaTransferCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD TransferCallback ( _                          ' VTable offset = 12
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL pWiaTransferParams AS WiaTransferParams _    ' __in WiaTransferParams *pWiaTransferParams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextStream ( _                             ' VTable offset = 16
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL bstrItemName AS WSTRING _                    ' __in BSTR bstrItemName
   , BYVAL bstrFullItemName AS WSTRING _                ' __in BSTR bstrFullItemName
   , BYREF ppDestination AS IStream _                   ' __out IStream **ppDestination
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWiaTransferCallback_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWiaSegmentationFilter
' IID = {EC46A697-AC04-4447-8F65-FF63D5154B21}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWiaSegmentationFilter_INTERFACE_DEFINED)
    %IWiaSegmentationFilter_INTERFACE_DEFINED = 1

$IID_IWiaSegmentationFilter = GUID$("{EC46A697-AC04-4447-8F65-FF63D5154B21}")

INTERFACE IWiaSegmentationFilter $IID_IWiaSegmentationFilter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD DetectRegions ( _                             ' VTable offset = 12
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL pInputStream AS IStream _                    ' __in IStream *pInputStream
   , BYVAL pWiaItem2 AS IWiaItem2 _                     ' __in IWiaItem2 *pWiaItem2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWiaSegmentationFilter_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWiaImageFilter
' IID = {A8A79FFA-450B-41F1-8F87-849CCD94EBF6}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWiaImageFilter_INTERFACE_DEFINED)
    %IWiaImageFilter_INTERFACE_DEFINED = 1

$IID_IWiaImageFilter = GUID$("{A8A79FFA-450B-41F1-8F87-849CCD94EBF6}")

INTERFACE IWiaImageFilter $IID_IWiaImageFilter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InitializeFilter ( _                          ' VTable offset = 12
     BYVAL pWiaItem2 AS IWiaItem2 _                     ' __in IWiaItem2 *pWiaItem2
   , BYVAL pWiaTransferCallback AS IWiaTransferCallback _ ' __in IWiaTransferCallback *pWiaTransferCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNewCallback ( _                            ' VTable offset = 16
     BYVAL pWiaTransferCallback AS IWiaTransferCallback _ ' __in IWiaTransferCallback *pWiaTransferCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FilterPreviewImage ( _                        ' VTable offset = 20
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL pWiaChildItem2 AS IWiaItem2 _                ' __in IWiaItem2 *pWiaChildItem2
   , BYVAL InputImageExtents AS RECT _                  ' __in RECT InputImageExtents
   , BYVAL pInputStream AS IStream _                    ' __in IStream *pInputStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ApplyProperties ( _                           ' VTable offset = 24
     BYVAL pWiaPropertyStorage AS IWiaPropertyStorage _ ' __in IWiaPropertyStorage *pWiaPropertyStorage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWiaImageFilter_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWiaImageFilter
' IID = {95C2B4FD-33F2-4D86-AD40-9431F0DF08F7}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWiaPreview_INTERFACE_DEFINED)
    %IWiaPreview_INTERFACE_DEFINED = 1

$IID_IWiaPreview = GUID$("{95C2B4FD-33F2-4D86-AD40-9431F0DF08F7}")

INTERFACE IWiaPreview $IID_IWiaPreview

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNewPreview ( _                             ' VTable offset = 12
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL pWiaItem2 AS IWiaItem2 _                     ' __in IWiaItem2 *pWiaItem2
   , BYVAL pWiaTransferCallback AS IWiaTransferCallback _ ' __in IWiaTransferCallback *pWiaTransferCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdatePreview ( _                             ' VTable offset = 16
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL pChildWiaItem2 AS IWiaItem2 _                ' __in IWiaItem2 *pChildWiaItem2
   , BYVAL pWiaTransferCallback AS IWiaTransferCallback _ ' __in IWiaTransferCallback *pWiaTransferCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DetectRegions ( _                             ' VTable offset = 20
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWiaPreview_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumWiaItem2
' IID = {59970AF4-CD0D-44D9-AB24-52295630E582}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumWiaItem2_INTERFACE_DEFINED)
    %IEnumWiaItem2_INTERFACE_DEFINED = 1

$IID_IEnumWiaItem2 = GUID$("{59970AF4-CD0D-44D9-AB24-52295630E582}")

INTERFACE IEnumWiaItem2 $IID_IEnumWiaItem2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppIWiaItem2 AS IWiaItem2 _                   ' __out IWiaItem2 **ppIWiaItem2
   , BYREF pceltFetched AS DWORD _                      ' __inout ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cElt AS DWORD _                              ' __in ULONG cElt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppIEnum AS IEnumWiaItem2 _                   ' __out IEnumWiaItem2 **ppIEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 28
     BYREF cElt AS DWORD _                              ' __out ULONG *cElt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumWiaItem2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWiaItem2
' IID = {6CBA0075-1287-407D-9B77-CF0E030435CC}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWiaItem2_INTERFACE_DEFINED)
    %IWiaItem2_INTERFACE_DEFINED = 1

$IID_IWiaItem2 = GUID$("{6CBA0075-1287-407D-9B77-CF0E030435CC}")

INTERFACE IWiaItem2 $IID_IWiaItem2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateChildItem ( _                           ' VTable offset = 12
     BYVAL lItemFlags AS LONG _                         ' __in LONG lItemFlags
   , BYVAL lCreationFlags AS LONG _                     ' __in LONG lCreationFlags
   , BYVAL bstrItemName AS WSTRING _                    ' __in BSTR bstrItemName
   , BYREF ppIWiaItem2 AS IWiaItem2 _                   ' __out IWiaItem2 **ppIWiaItem2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteItem ( _                                ' VTable offset = 16
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumChildItems ( _                            ' VTable offset = 20
     BYREF pCategoryGUID AS GUID _                      ' __in const GUID *pCategoryGUID
   , BYREF ppIEnumWiaItem2 AS IEnumWiaItem2 _           ' __out IEnumWiaItem2 **ppIEnumWiaItem2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindItemByName ( _                            ' VTable offset = 24
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL bstrFullItemName AS WSTRING _                ' __in BSTR bstrFullItemName
   , BYREF ppIWiaItem2 AS IWiaItem2 _                   ' __out IWiaItem2 **ppIWiaItem2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemCategory ( _                           ' VTable offset = 28
     BYREF pItemCategoryGUID AS GUID _                  ' __out GUID *pItemCategoryGUID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemType ( _                               ' VTable offset = 32
     BYREF pItemType AS LONG _                          ' __out LONG *pItemType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeviceDlg ( _                                 ' VTable offset = 36
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYVAL bstrFolderName AS WSTRING _                  ' __in BSTR bstrFolderName
   , BYVAL bstrFilename AS WSTRING _                    ' __in BSTR bstrFilename
   , BYREF plNumFiles AS LONG _                         ' __in LONG *plNumFiles
   , BYREF ppbstrFilePaths AS WSTRING _                 ' __in BSTR **ppbstrFilePaths
   , BYREF ppItem AS IWiaItem2 _                        ' __inout IWiaItem2 **ppItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeviceCommand ( _                             ' VTable offset = 40
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYREF pCmdGUID AS GUID _                           ' __in const GUID *pCmdGUID
   , BYREF ppIWiaItem2 AS IWiaItem2 _                   ' __inout IWiaItem2 **ppIWiaItem2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumDeviceCapabilities ( _                    ' VTable offset = 44
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYREF ppIEnumWIA_DEV_CAPS AS IEnumWIA_DEV_CAPS _   ' __out IEnumWIA_DEV_CAPS **ppIEnumWIA_DEV_CAPS
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckExtension ( _                            ' VTable offset = 48
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYREF riidExtensionInterface AS GUID _             ' __in REFIID riidExtensionInterface
   , BYREF pbExtensionExists AS LONG _                  ' __out BOOL *pbExtensionExists
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetExtension ( _                              ' VTable offset = 52
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYREF riidExtensionInterface AS GUID _             ' __in REFIID riidExtensionInterface
   , BYREF ppOut AS IUnknown _                          ' __out void **ppOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParentItem ( _                             ' VTable offset = 56
     BYREF ppIWiaItem2 AS IWiaItem2 _                   ' __out IWiaItem2 **ppIWiaItem2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRootItem ( _                               ' VTable offset = 60
     BYREF ppIWiaItem2 AS IWiaItem2 _                   ' __out IWiaItem2 **ppIWiaItem2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPreviewComponent ( _                       ' VTable offset = 64
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYREF ppWiaPreview AS IWiaPreview _                ' __out IWiaPreview **ppWiaPreview
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumRegisterEventInfo ( _                     ' VTable offset = 68
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYREF pEventGUID AS GUID _                         ' __in const GUID *pEventGUID
   , BYREF ppIEnum AS IEnumWIA_DEV_CAPS _               ' __out IEnumWIA_DEV_CAPS **ppIEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Diagnostic ( _                                ' VTable offset = 72
     BYVAL ulSize AS DWORD _                            ' __in ULONG ulSize
   , BYVAL pBuffer AS BYTE PTR _                        ' __in BYTE *pBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWiaItem2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWiaDevMgr2
' IID = {79C07CF1-CBDD-41EE-8EC3-F00080CADA7A}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWiaDevMgr2_INTERFACE_DEFINED)
    %IWiaDevMgr2_INTERFACE_DEFINED = 1

$IID_IWiaDevMgr2 = GUID$("{79C07CF1-CBDD-41EE-8EC3-F00080CADA7A}")

INTERFACE IWiaDevMgr2 $IID_IWiaDevMgr2

   INHERIT IAutomation

   ' =====================================================================================
   METHOD EnumDeviceInfo ( _                            ' VTable offset = 12
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   ) AS IEnumWIA_DEV_INFO                               ' __retval_out IEnumWIA_DEV_INFO **ppIEnum
   ' =====================================================================================
   METHOD CreateDevice ( _                              ' VTable offset = 16
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL bstrDeviceID AS WSTRING _                    ' __in BSTR bstrDeviceID
   , BYREF ppWiaItem2Root AS IWiaItem2 _                ' __out IWiaItem2 **ppWiaItem2Root
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectDeviceDlg ( _                           ' VTable offset = 20
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYVAL lDeviceType AS LONG _                        ' __in LONG lDeviceType
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYREF pbstrDeviceID AS WSTRING _                   ' __inout BSTR *pbstrDeviceID
   ) AS IWiaItem2                                       ' __retval_out IWiaItem2 **ppItemRoot
   ' =====================================================================================
   METHOD SelectDeviceDlgID ( _                         ' VTable offset = 24
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYVAL lDeviceType AS LONG _                        ' __in LONG lDeviceType
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDeviceID
   ' =====================================================================================
   METHOD RegisterEventCallbackInterface ( _            ' VTable offset = 28
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL bstrDeviceID AS WSTRING _                    ' __in BSTR bstrDeviceID
   , BYREF pEventGUID AS GUID _                         ' __in const GUID *pEventGUID
   , BYVAL pIWiaEventCallback AS IWiaEventCallback _    ' __in IWiaEventCallback *pIWiaEventCallback
   , BYREF pEventObject AS IUnknown _                   ' __out IUnknown **pEventObject
   )                                                    ' void
   ' =====================================================================================
   METHOD RegisterEventCallbackProgram ( _              ' VTable offset = 32
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL bstrDeviceID AS WSTRING _                    ' __in BSTR bstrDeviceID
   , BYREF pEventGUID AS GUID _                         ' __in const GUID *pEventGUID
   , BYVAL bstrFullAppName AS WSTRING _                 ' __in BSTR bstrFullAppName
   , BYVAL bstrCommandLineArg AS WSTRING _              ' __in BSTR bstrCommandLineArg
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   , BYVAL bstrIcon AS WSTRING _                        ' __in BSTR bstrIcon
   )                                                    ' void
   ' =====================================================================================
   METHOD RegisterEventCallbackCLSID ( _                ' VTable offset = 36
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL bstrDeviceID AS WSTRING _                    ' __in BSTR bstrDeviceID
   , BYREF pEventGUID AS GUID _                         ' __in const GUID *pEventGUID
   , BYREF pClsID AS GUID _                             ' __in const GUID *pClsID
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   , BYVAL bstrIcon AS WSTRING _                        ' __in BSTR bstrIcon
   )                                                    ' void
   ' =====================================================================================
   METHOD GetImageDlg ( _                               ' VTable offset = 40
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL bstrDeviceID AS WSTRING _                    ' __in BSTR bstrDeviceID
   , BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYVAL bstrFolderName AS WSTRING _                  ' __in BSTR bstrFolderName
   , BYVAL bstrFilename AS WSTRING _                    ' __in BSTR bstrFilename
   , BYVAL plNumFiles AS LONG _                         ' __in LONG *plNumFiles
   , BYVAL ppbstrFilePaths AS WSTRING _                 ' __in BSTR **ppbstrFilePaths
   , BYREF ppItem AS IWiaItem2 _                        ' __inout IWiaItem2 **ppItem
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWiaDevMgr2_INTERFACE_DEFINED__ */

#IF NOT %DEF(%WiaDevMgr_LIBRARY_DEFINED)
%WiaDevMgr_LIBRARY_DEFINED = 1

'EXTERN_C const IID LIBID_WiaDevMgr;

$CLSID_WiaDevMgr  = GUID$("{A1F4E726-8CF1-11D1-BF92-0060081ED811}")
$CLSID_WiaDevMgr2 = GUID$("{B6C292BC-7C88-41EE-8B54-8EC92617E599}")
$CLSID_WiaLog     = GUID$("{A1E75357-881A-419e-83E2-BB16DB197C68}")

#ENDIF   ' /* __WiaDevMgr_LIBRARY_DEFINED__ */
