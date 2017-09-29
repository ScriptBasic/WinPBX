' ########################################################################################
' Microsoft Windows
' File: datacontainer.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DATACONTAINER_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "WMSBuffer.inc"
#INCLUDE ONCE "WMSContext.inc"
#INCLUDE ONCE "DataContainerVersion.inc"
#INCLUDE ONCE "wmsPacket.inc"

%WMS_DATA_CONTAINER_NONSEEKABLE = &HFFFFFFFFFFFFFFFF&&

$IID_IWMSDataSourcePlugin = GUID$("{E1CD3525-03D7-11D2-9EED-006097D2D7CF}")
$IID_IWMSDataSourcePluginCallback = GUID$("{E1CD3526-03D7-11D2-9EED-006097D2D7CF}")
$IID_IWMSDataContainer = GUID$("{E6EE9A13-0FCC-11D2-9EEE-006097D2D7CF}")
$IID_IWMSDataContainerCallback = GUID$("{2E34AB82-0D3D-11D2-9EEE-006097D2D7CF}")
$IID_IWMSDirectory = GUID$("{6FA365E7-E8B9-437A-8C4B-6552DFBB0C57}")
$IID_IWMSUnknownFormat = GUID$("{9B6C9E51-4813-11D2-9EFF-006097D2D7CF}")
$IID_IWMSDirectoryFormat = GUID$("{7408CEB0-3A5A-41B6-A5EC-9A4E811C9673}")
$IID_IWMSPlaylistSmilFormat = GUID$("{C34294EA-E111-4FB2-BE6B-EC686A1A9757}")

' WMS_DATA_CONTAINER_OPEN_FLAGS enum
%WMS_DATA_CONTAINER_READ_ACCESS          = &H1
%WMS_DATA_CONTAINER_WRITE_ACCESS         = &H2
%WMS_DATA_CONTAINER_CREATE_NEW_CONTAINER = &H4
%WMS_DATA_CONTAINER_ALLOW_BUFFER_IO      = &H8
%WMS_DATA_CONTAINER_SHARED_SOURCE        = &H10

' WMS_DIRECTORY_ENTRY_FLAGS enum
%WMS_DIRECTORY_ENTRY_IS_DIRECTORY = &H1

' WMS_DATA_CONTAINER_GETINFO_VALUES enum
%WMS_DATA_CONTAINER_SIZE                    = 1
%WMS_DATA_CONTAINER_MAX_SUPPORTED_READ_SIZE = 2

' WMS_DATA_CONTAINER_GETINFO_FLAGS enum
%WMS_SEEKABLE_CONTAINER   = &H1
%WMS_LOCAL_DATA_CONTAINER = &H2

' WMS_DATA_CONTAINER_ATTRIBUTES enum
%WMS_DATA_CONTAINER_SUPPORTS_ENUMERATION = &H1

'typedef unsigned __int64 QWORD;

' ########################################################################################
' Interface name = IWMSDataSourcePlugin
' IID = {E1CD3525-03D7-11D2-9EED-006097D2D7CF}
' Provides methods to manage data containers and retrieve information about them.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMSDataSourcePlugin_INTERFACE_DEFINED)
    %IWMSDataSourcePlugin_INTERFACE_DEFINED = 1

INTERFACE IWMSDataSourcePlugin $IID_IWMSDataSourcePlugin

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDataSourceAttributes ( _                   ' VTable offset = 12
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRootDirectories ( _                        ' VTable offset = 16
     BYREF pstrRootDirectoryList AS DWORD _             ' __in LPWSTR *pstrRootDirectoryList
   , BYVAL dwMaxRoots AS DWORD _                        ' __in DWORD dwMaxRoots
   , BYVAL pCallback AS IWMSDataSourcePluginCallback _  ' __in IWMSDataSourcePluginCallback *pCallback
   , BYVAL qwContext AS QUAD _                          ' __in QWORD qwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenDataContainer ( _                         ' VTable offset = 20
     BYVAL pCommandContext AS IWMSCommandContext _      ' __in IWMSCommandContext *pCommandContext
   , BYVAL pUserContext AS IWMSContext _                ' __in IWMSContext *pUserContext
   , BYVAL pPresentationContext AS IWMSContext _        ' __in IWMSContext *pPresentationContext
   , BYREF pszContainerName AS WSTRINGZ _               ' __in LPWSTR pszContainerName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pBufferAllocator AS IWMSBufferAllocator _    ' __in IWMSBufferAllocator *pBufferAllocator
   , BYVAL pCallback AS IWMSDataSourcePluginCallback _  ' __in IWMSDataSourcePluginCallback *pCallback
   , BYVAL qwContext AS QUAD _                          ' __in QWORD qwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenDirectory ( _                             ' VTable offset = 24
     BYVAL pCommandContext AS IWMSCommandContext _      ' __in IWMSCommandContext *pCommandContext
   , BYVAL pUserContext AS IWMSContext _                ' __in IWMSContext *pUserContext
   , BYVAL pPresentationContext AS IWMSContext _        ' __in IWMSContext *pPresentationContext
   , BYREF pszContainerName AS WSTRINGZ _               ' __in LPWSTR pszContainerName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pBufferAllocator AS IWMSBufferAllocator _    ' __in IWMSBufferAllocator *pBufferAllocator
   , BYVAL pCallback AS IWMSDataSourcePluginCallback _  ' __in IWMSDataSourcePluginCallback *pCallback
   , BYVAL qwContext AS QUAD _                          ' __in QWORD qwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteDataContainer ( _                       ' VTable offset = 28
     BYREF pszContainerName AS WSTRINGZ _               ' __in LPWSTR pszContainerName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pCallback AS IWMSDataSourcePluginCallback _  ' __in IWMSDataSourcePluginCallback *pCallback
   , BYVAL qwContext AS QUAD _                          ' __in QWORD qwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDataContainerVersion ( _                   ' VTable offset = 32
     BYVAL pCommandContext AS IWMSCommandContext _      ' __in IWMSCommandContext *pCommandContext
   , BYVAL pUserContext AS IWMSContext _                ' __in IWMSContext *pUserContext
   , BYVAL pPresContext AS IWMSContext _                ' __in IWMSContext *pPresContext
   , BYREF pszContainerName AS WSTRINGZ _               ' __in LPWSTR pszContainerName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pCallback AS IWMSDataSourcePluginCallback _  ' __in IWMSDataSourcePluginCallback *pCallback
   , BYVAL qwContext AS QUAD _                          ' __in QWORD qwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDataSourceDirectory ( _                 ' VTable offset = 36
     BYVAL pCommandContext AS IWMSCommandContext _      ' __in IWMSCommandContext *pCommandContext
   , BYREF pszContainerName AS WSTRINGZ _               ' __in LPWSTR pszContainerName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pCallback AS IWMSDataSourcePluginCallback _  ' __in IWMSDataSourcePluginCallback *pCallback
   , BYVAL qwContext AS QUAD _                          ' __in QWORD qwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteDirectory ( _                           ' VTable offset = 40
     BYREF pszContainerName AS WSTRINGZ _               ' __in LPWSTR pszContainerName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pCallback AS IWMSDataSourcePluginCallback _  ' __in IWMSDataSourcePluginCallback *pCallback
   , BYVAL qwContext AS QUAD _                          ' __in QWORD qwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMSDataSourcePlugin_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMSDataSourcePluginCallback
' IID = {E1CD3526-03D7-11D2-9EED-006097D2D7CF}
' Provides methods to return the results of IWMSDataContainer method calls.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMSDataSourcePluginCallback_INTERFACE_DEFINED)
    %IWMSDataSourcePluginCallback_INTERFACE_DEFINED = 1

INTERFACE IWMSDataSourcePluginCallback $IID_IWMSDataSourcePluginCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnOpenDataContainer ( _                       ' VTable offset = 12
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   , BYVAL pDataContainer AS IWMSDataContainer _        ' __in IWMSDataContainer *pDataContainer
   , BYVAL qwContext AS QUAD _                          ' __in QWORD qwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnOpenDirectory ( _                           ' VTable offset = 16
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   , BYVAL pDirectory AS IWMSDirectory _                ' __in IWMSDirectory *pDirectory
   , BYVAL qwContext AS QUAD _                          ' __in QWORD qwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnOpenPacketStreamDataContainer ( _           ' VTable offset = 20
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   , BYVAL pLiveDataContainer AS IUnknown _             ' __in IUnknown *pLiveDataContainer
   , BYVAL qwContext AS QUAD _                          ' __in QWORD qwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDeleteDataContainer ( _                     ' VTable offset = 24
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   , BYVAL qwContext AS QUAD _                          ' __in QWORD qwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnGetDataContainerVersion ( _                 ' VTable offset = 28
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   , BYVAL pVersion AS IWMSDataContainerVersion _       ' __in IWMSDataContainerVersion *pVersion
   , BYVAL qwContext AS QUAD _                          ' __in QWORD qwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnGetRootDirectories ( _                      ' VTable offset = 32
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   , BYVAL dwNumReturnedRoots AS DWORD _                ' __in DWORD dwNumReturnedRoots
   , BYVAL dwTotalNumRoots AS DWORD _                   ' __in DWORD dwTotalNumRoots
   , BYVAL qwContext AS QUAD _                          ' __in QWORD qwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCreateDirectory ( _                         ' VTable offset = 36
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   , BYVAL qwContext AS QUAD _                          ' __in QWORD qwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDeleteDirectory ( _                         ' VTable offset = 40
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   , BYVAL qwContext AS QUAD _                          ' __in QWORD qwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMSDataSourcePluginCallback_INTERFACE_DEFINED__ */

' // Size = 16 bytes
TYPE WMSDirectoryEntryInfo DWORD
   pstrName AS WORD  PTR   ' LPOLESTR
   dwFlags  AS DWORD       ' DWORD
   qwSize   AS QUAD        ' QWORD
END TYPE

' ########################################################################################
' Interface name = IWMSDataContainer
' IID = {E6EE9A13-0FCC-11D2-9EEE-006097D2D7CF}
' Provides methods to manage a data container.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMSDataContainer_INTERFACE_DEFINED)
    %IWMSDataContainer_INTERFACE_DEFINED = 1

INTERFACE IWMSDataContainer $IID_IWMSDataContainer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetContainerFormat ( _                        ' VTable offset = 12
     BYREF pFormat AS GUID _                            ' __out GUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDataSourcePlugin ( _                       ' VTable offset = 16
     BYREF ppDataSource AS IWMSDataSourcePlugin _       ' __out IWMSDataSourcePlugin **ppDataSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInfo ( _                                   ' VTable offset = 20
     BYVAL dwInfoValueId AS DWORD _                     ' __in DWORD dwInfoValueId
   , BYVAL pCallback AS IWMSDataContainerCallback _     ' __in IWMSDataContainerCallback *pCallback
   , BYVAL qwContext AS QUAD _                          ' __in QWORD qwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Read ( _                                      ' VTable offset = 24
     BYREF pbBuffer AS BYTE _                           ' __in BYTE *pbBuffer
   , BYVAL qwOffset AS QUAD _                           ' __in QWORD qwOffset
   , BYVAL dwMaxDataSize AS DWORD _                     ' __in DWORD dwMaxDataSize
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pCallback AS IWMSDataContainerCallback _     ' __in IWMSDataContainerCallback *pCallback
   , BYVAL qwContext AS QUAD _                          ' __in QWORD qwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Write ( _                                     ' VTable offset = 28
     BYREF pbBuffer AS BYTE _                           ' __in BYTE *pbBuffer
   , BYVAL dwDataSize AS DWORD _                        ' __in DWORD dwDataSize
   , BYVAL qwWritePosition AS QUAD _                    ' __in QWORD qwWritePosition
   , BYVAL pCallback AS IWMSDataContainerCallback _     ' __in IWMSDataContainerCallback *pCallback
   , BYVAL qwContext AS QUAD _                          ' __in QWORD qwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransferParameters ( _                     ' VTable offset = 32
     BYVAL qwDesiredOffset AS QUAD _                    ' __in QWORD qwDesiredOffset
   , BYVAL dwDesiredMinSize AS DWORD _                  ' __in DWORD dwDesiredMinSize
   , BYVAL dwDesiredMaxSize AS DWORD _                  ' __in DWORD dwDesiredMaxSize
   , BYREF pqwOffset AS QUAD _                          ' __out QWORD *pqwOffset
   , BYREF pdwSize AS DWORD _                           ' __out DWORD *pdwSize
   , BYREF pdwBufferAlignment AS DWORD _                ' __out DWORD *pdwBufferAlignment
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoDataContainerExtendedCommand ( _            ' VTable offset = 36
     BYREF szCommandName AS WSTRINGZ _                  ' __in LPWSTR szCommandName
   , BYVAL pCommand AS IWMSCommandContext _             ' __in IWMSCommandContext *pCommand
   , BYVAL dwCallFlags AS DWORD _                       ' __in DWORD dwCallFlags
   , BYVAL pCallback AS IWMSDataContainerCallback _     ' __in IWMSDataContainerCallback *pCallback
   , BYVAL qwContext AS QUAD _                          ' __in QWORD qwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FinishParsingPacketlist ( _                   ' VTable offset = 40
     BYVAL pPacketList AS IWMSPacketList _              ' __in IWMSPacketList *pPacketList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMSDataContainer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMSDataContainerCallback
' IID = {2E34AB82-0D3D-11D2-9EEE-006097D2D7CF}
' Provides methods to return the results of IWMSDataContainer method calls.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMSDataContainerCallback_INTERFACE_DEFINED)
    %IWMSDataContainerCallback_INTERFACE_DEFINED = 1

INTERFACE IWMSDataContainerCallback $IID_IWMSDataContainerCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnGetInfo ( _                                 ' VTable offset = 12
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL qwInfoValue AS QUAD _                        ' __in QWORD qwInfoValue
   , BYVAL qwContext AS QUAD _                          ' __in QWORD qwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnRead ( _                                    ' VTable offset = 16
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   , BYVAL dwActualBytesTransferred AS DWORD _          ' __in DWORD dwActualBytesTransferred
   , BYVAL dwChangeType AS DWORD _                      ' __in DWORD dwChangeType
   , BYVAL qwChangeParameter AS QUAD _                  ' __in QWORD qwChangeParameter
   , BYVAL qwContext AS QUAD _                          ' __in QWORD qwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnWrite ( _                                   ' VTable offset = 20
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   , BYVAL dwActualBytesTransferred AS DWORD _          ' __in DWORD dwActualBytesTransferred
   , BYVAL qwContext AS QUAD _                          ' __in QWORD qwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDoDataContainerExtendedCommand ( _          ' VTable offset = 24
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   , BYVAL qwContext AS QUAD _                          ' __in QWORD qwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMSDataContainerCallback_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMSDirectory
' IID = {6FA365E7-E8B9-437A-8C4B-6552DFBB0C57}
' Provides methods for navigating the structure of a directory data container.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMSDirectory_INTERFACE_DEFINED)
    %IWMSDirectory_INTERFACE_DEFINED = 1

INTERFACE IWMSDirectory $IID_IWMSDirectory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDataSourcePlugin ( _                       ' VTable offset = 12
     BYREF ppDataSource AS IWMSDataSourcePlugin _       ' __out IWMSDataSourcePlugin **ppDataSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 16
     BYREF pstrValue AS DWORD _                         ' __out LPWSTR *pstrValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChildInfo ( _                              ' VTable offset = 20
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF pInfo AS WMSDirectoryEntryInfo _             ' __out WMSDirectoryEntryInfo *pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMSDirectory_INTERFACE_DEFINED__ */
