' ########################################################################################
' Microsoft Windows
' File: ShlGuid.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SHLGUID_INC = 1

'#define DEFINE_SHLGUID(name, l, w1, w2) DEFINE_GUID(name, l, w1, w2, 0xC0,0,0,0,0,0,0,0x46)

$CLSID_NetworkDomain                   = GUID$("{46E06680-4BF0-11D1-83EE-00A0C90DC849}")
$CLSID_NetworkServer                   = GUID$("{C0542A90-4BF0-11D1-83EE-00A0C90DC849}")
$CLSID_NetworkShare                    = GUID$("{54A754C0-4BF1-11D1-83EE-00A0C90DC849}")
$CLSID_MyComputer                      = GUID$("{20D04FE0-3AEA-1069-A2D8-08002B30309D}")
$CLSID_Internet                        = GUID$("{871C5380-42A0-1069-A2EA-08002B30309D}")
$CLSID_RecycleBin                      = GUID$("{645FF040-5081-101B-9F08-00AA002F954E}")
$CLSID_ControlPanel                    = GUID$("{21EC2020-3AEA-1069-A2DD-08002B30309D}")
$CLSID_Printers                        = GUID$("{2227A280-3AEA-1069-A2DE-08002B30309D}")
$CLSID_MyDocuments                     = GUID$("{450D8FBA-AD25-11D0-98A8-0800361B1103}")
'$CLSID_PictureVideoLibrary             = GUID$("{00044B4E-11E6-4BEF-AEC2-BA157D80F660}")   ' // Removed in Windows 7 SDK
'$CLSID_MusicLibrary                    = GUID$("{00875566-ADDC-4883-A2BF-62BBD230DF07}")   ' // Removed in Windows 7 SDK
'$CLSID_DocumentLibrary                 = GUID$("{00F4A6AC-E2E7-4652-B7A7-ECBD232F7818}")   ' // Removed in Windows 7 SDK

'// string version of above CLSIDs
'// useful for doing psfDesktop->ParseDisplayName( L"::" L STR_MYDOCS_CLSID, ...);

$STR_MYDOCS_CLSID                      = "{450D8FBA-AD25-11D0-98A8-0800361B1103}"

'#if (_WIN32_IE >= 0x0400)
$CATID_BrowsableShellExt               = GUID$("{00021490-0000-0000-C000-000000000046}")
$CATID_BrowseInPlace                   = GUID$("{00021491-0000-0000-C000-000000000046}")
$CATID_DeskBand                        = GUID$("{00021492-0000-0000-C000-000000000046}")
$CATID_InfoBand                        = GUID$("{00021493-0000-0000-C000-000000000046}")
$CATID_CommBand                        = GUID$("{00021494-0000-0000-C000-000000000046}")
'#endif

$PSGUID_INTERNETSHORTCUT               = "{000214A0-0000-0000-C000-000000000046}"
$FMTID_Intshcut                        = GUID$("{000214A0-0000-0000-C000-000000000046}")

$PSGUID_INTERNETSITE                   = "{000214A1-0000-0000-C000-000000000046}"
$FMTID_InternetSite                    = GUID$("{000214A1-0000-0000-C000-000000000046}")

$CGID_Explorer                         = GUID$("{000214D0-0000-0000-C000-000000000046}")
$CGID_ShellDocView                     = GUID$("{000214D1-0000-0000-C000-000000000046}")

'#if (_WIN32_IE >= 0x0400)
$CGID_ShellServiceObject               = GUID$("{000214D2-0000-0000-C000-000000000046}")
$CGID_ExplorerBarDoc                   = GUID$("{000214D3-0000-0000-C000-000000000046}")
'#endif

$IID_INewShortcutHookA                 = GUID$("{000214E1-0000-0000-C000-000000000046}")
$IID_INewShortcutHook                  = GUID$("{000214E1-0000-0000-C000-000000000046}")
$IID_IShellBrowser                     = GUID$("{000214E2-0000-0000-C000-000000000046}")
$IID_IShellView                        = GUID$("{000214E3-0000-0000-C000-000000000046}")
$IID_IContextMenu                      = GUID$("{000214E4-0000-0000-C000-000000000046}")
$IID_IShellIcon                        = GUID$("{000214E5-0000-0000-C000-000000000046}")
$IID_IShellFolder                      = GUID$("{000214E6-0000-0000-C000-000000000046}")
$IID_IShellExtInit                     = GUID$("{000214E8-0000-0000-C000-000000000046}")
$IID_IShellPropSheetExt                = GUID$("{000214E9-0000-0000-C000-000000000046}")
$IID_IPersistFolder                    = GUID$("{000214EA-0000-0000-C000-000000000046}")
$IID_IExtractIconA                     = GUID$("{000214EB-0000-0000-C000-000000000046}")
$IID_IExtractIcon                      = GUID$("{000214EB-0000-0000-C000-000000000046}")
$IID_IShellDetails                     = GUID$("{000214EC-0000-0000-C000-000000000046}")
$IID_IDelayedRelease                   = GUID$("{000214ED-0000-0000-C000-000000000046}")
$IID_IShellLinkA                       = GUID$("{000214EE-0000-0000-C000-000000000046}")
$IID_IShellLink                        = GUID$("{000214EE-0000-0000-C000-000000000046}")
$IID_ICopyHookA                        = GUID$("{000214EF-0000-0000-C000-000000000046}")
$IID_ICopyHook                         = GUID$("{000214EF-0000-0000-C000-000000000046}")
$IID_IFileViewerA                      = GUID$("{000214F0-0000-0000-C000-000000000046}")
$IID_IFileViewer                       = GUID$("{000214F0-0000-0000-C000-000000000046}")
$IID_ICommDlgBrowser                   = GUID$("{000214F1-0000-0000-C000-000000000046}")
$IID_IEnumIDList                       = GUID$("{000214F2-0000-0000-C000-000000000046}")
$IID_IFileViewerSite                   = GUID$("{000214F3-0000-0000-C000-000000000046}")
$IID_IContextMenu2                     = GUID$("{000214F4-0000-0000-C000-000000000046}")
$IID_IShellExecuteHookA                = GUID$("{000214F5-0000-0000-C000-000000000046}")
$IID_IShellExecuteHook                 = GUID$("{000214F5-0000-0000-C000-000000000046}")
$IID_IPropSheetPage                    = GUID$("{000214F6-0000-0000-C000-000000000046}")
$IID_INewShortcutHookW                 = GUID$("{000214F7-0000-0000-C000-000000000046}")
$IID_IFileViewerW                      = GUID$("{000214F8-0000-0000-C000-000000000046}")
$IID_IShellLinkW                       = GUID$("{000214F9-0000-0000-C000-000000000046}")
$IID_IExtractIconW                     = GUID$("{000214FA-0000-0000-C000-000000000046}")
$IID_IShellExecuteHookW                = GUID$("{000214FB-0000-0000-C000-000000000046}")
$IID_CopyHookW                         = GUID$("{000214FC-0000-0000-C000-000000000046}")
$IID_IRemoteComputer                   = GUID$("{000214FE-0000-0000-C000-000000000046}")

'#define IID_IShellCopyHookA                  IID_ICopyHookA
'#define IID_IShellCopyHookW                  IID_ICopyHookW
$IID_IShellCopyHookA                   = GUID$("{000214EF-0000-0000-C000-000000000046}")
$IID_IShellCopyHook                    = GUID$("{000214EF-0000-0000-C000-000000000046}")
$IID_IShellCopyHookW                   = GUID$("{000214FC-0000-0000-C000-000000000046}")
$IID_ICopyHook                         = GUID$("{000214EF-0000-0000-C000-000000000046}")
$IID_ICopyHookA                        = GUID$("{000214EF-0000-0000-C000-000000000046}")
$IID_ICopyHookW                        = GUID$("{000214FC-0000-0000-C000-000000000046}")

'#define SID_LinkSite    IID_IShellLinkW     // IServiceProvider::QueryService() access the link object that is defering to you
$SID_LinkSite                          = GUID$("{000214F9-0000-0000-C000-000000000046}")

'#if (_WIN32_IE >= 0x0400)
$IID_IQueryInfo                        = GUID$("{00021500-0000-0000-C000-000000000046}")
'#endif

$IID_IBriefcaseStg                     = GUID$("{8BCE1FA1-0921-101B-B1FF-00DD010CCC48}")
$IID_IShellView2                       = GUID$("{88E39E80-3578-11CF-AE69-08002B2E1262}")

'#if (_WIN32_IE >= 0x0400)
$IID_IURLSearchHook                    = GUID$("{AC60F6A0-0FD9-11D0-99CB-00C04FD64497}")
$IID_ISearchContext                    = GUID$("{09F656A2-41AF-480C-88F7-16CC0D164615}")
$IID_IURLSearchHook2                   = GUID$("{5EE44DA4-6D32-46E3-86BC-07540DEDD0E0}")
$IID_IDefViewID                        = GUID$("{985F64F0-D410-4E02-BE22-DA07F2B5C5E1}")

'#define IDefViewID   IUnknown

' IDefViewID is used only for its IUnknown functionality. It has no methods of its own.
INTERFACE IDefViewID $IID_IDefViewID
   INHERIT IUnknown
END INTERFACE

'#if (_WIN32_IE >= 0x0500)
$CLSID_FolderShortcut                  = GUID$("{0AFACED1-E828-11D1-9187-B532F1E9575D}")
' CLSID_StorageFolder has been removed in Windows Vista SDK
$CLSID_StorageFolder                   = GUID$("{E773F1AF-3A65-4866-857D-846FC9C4598A}")
'#endif

$IID_IDockingWindowSite                = GUID$("{2A342FC2-7B26-11D0-8CA9-00A0C92DBFE8}")
$IID_IDockingWindowFrame               = GUID$("{47D2657A-7B27-11D0-8CA9-00A0C92DBFE8}")

$IID_IShellIconOverlay                 = GUID$("{7D688A70-C613-11D0-999B-00C04FD655E1}")
$IID_IShellIconOverlayIdentifier       = GUID$("{0C6C4200-C589-11D0-999A-00C04FD655E1}")

$IID_ICommDlgBrowser2                  = GUID$("{10339516-2894-11d2-9039-00C04F8EEB3E}")
$IID_IShellFolderViewCB                = GUID$("{2047E320-F2A9-11CE-AE65-08002B2E1262}")
$SID_IShellFolderViewCB                = GUID$("{2047E320-F2A9-11CE-AE65-08002B2E1262}")
$CLSID_CFSIconOverlayManager           = GUID$("{63B51F81-C868-11D0-999C-00C04FD655E1}")
$IID_IShellIconOverlayManager          = GUID$("{F10B5E34-DD3B-42A7-AA7D-2F4EC54BB09B}")
$IID_IThumbnailCapture                 = GUID$("{4EA39266-7211-409F-B622-F63DBD16C533}")

'#if (_WIN32_IE >= 0x0500)
$IID_IShellImageStore                  = GUID$("{48C8118C-B924-11D1-98D5-00C04FB687DA}")
$IID_IEnumShellImageStore              = GUID$("{6DFD582B-92E3-11D1-98A3-00C04FB687DA}")
$CLSID_ShellThumbnailDiskCache         = GUID$("{1EBDCF80-A200-11D0-A3A4-00C04FD706EC}")
'#endif

$IID_IContextMenu3                     = GUID$("{BCFCE0A0-EC17-11D0-8D10-00A0C90F2719}")

'#endif // _WIN32_IE >= 0x0400

$SID_DefView                           = GUID$("{6D12FE80-7911-11CF-9534-0000C05BAE0B}")
$CGID_DefView                          = GUID$("{4AF07F10-D231-11D0-B942-00A0C90312E1}")
$CLSID_MenuBand                        = GUID$("{5B4DAE26-B807-11D0-9815-00C04FD91972}")

'// IShellFolderBand stuff
$IID_IShellFolderBand                  = GUID$("{7FE80CC8-C247-11D0-B93A-00A0C90312E1}")
$IID_IDefViewFrame                     = GUID$("{710EB7A0-45ED-11D0-924A-0020AFC7AC4D}")

$VID_LargeIcons                        = GUID$("{0057D0E0-3573-11CF-AE69-08002B2E1262}")
$VID_SmallIcons                        = GUID$("{089000C0-3573-11CF-AE69-08002B2E1262}")
$VID_List                              = GUID$("{0E1FA5E0-3573-11CF-AE69-08002B2E1262}")
$VID_Details                           = GUID$("{137E7700-3573-11CF-AE69-08002B2E1262}")
$VID_Tile                              = GUID$("{65F125E5-7BE1-4810-BA9D-D271C8432CE3}")
$VID_Content                           = GUID$("{30C2C434-0889-4C8D-985D-A9F71830B0A9}")

'// NOTE: This has to be the same as the old CLSID_Thumbnails
$VID_Thumbnails                        = GUID$("{8BEBB290-52D0-11D0-B7F4-00C04FD706EC}")

'// ThumbStrip
$VID_ThumbStrip                        = GUID$("{8EEFA624-D1E9-445B-94B7-74FBCE2EA11A}")

'#define SID_SShellBrowser IID_IShellBrowser
$SID_SShellBrowser                     = GUID$("{000214E2-0000-0000-C000-000000000046}")
'#if (_WIN32_IE >= 0x0400)
'#define SID_SShellDesktop CLSID_ShellDesktop
$SID_SShellDesktop                     = GUID$("{00021400-0000-0000-C000-000000000046}")
'#endif

'#if (NTDDI_VERSION >= NTDDI_WIN7)
'// {1D2AE02B-3655-46CC-B63A-285988153BCA}
$SID_SInPlaceBrowser                   = GUID$("{1D2AE02B-3655-46CC-B63A-285988153BCA}")
'#endif // NTDDI_WIN7

'#if (NTDDI_VERSION >= NTDDI_WIN7)
'// {142daa61-516b-4713-b49c-fb985ef82998}
$SID_SSearchBoxInfo                    = GUID$("{142DAA61-516B-4713-B49C-FB985EF82998}")
'#endif // NTDDI_WIN7

'#if (_WIN32_IE >= 0x0400)
'//
'//  IShellDiscardable is an IID-only interface. If the object supports this
'// interface it can be discarded anytime. IWebBrowser::PutProperty QI's for
'// this interface to detect discardable properties.
'//
$IID_IDiscardableBrowserProperty       = GUID$("{49C3DE7C-D329-11D0-AB73-00C04FC33E80}")

'// IShellChangeNotify is a sink of LPCITEMIDLIST notification events
'//
'// D82BE2B1-5764-11D0-A96E-00C04FD705A2
$IID_IShellChangeNotify                = GUID$("{D82BE2B1-5764-11D0-A96E-00C04FD705A2}")

'#endif // _WIN32_IE >= 0x0400

#IF NOT %DEF(%NO_INTSHCUT_GUIDS)
#INCLUDE ONCE "isguids.inc"           ' // internet shortcut GUIDs
#ENDIF

#IF NOT %DEF(%NO_SHDOCVW_GUIDS)

#IF NOT %DEF(%GUID_DEFS_ONLY)
#include ONCE "exdisp.inc"
#include ONCE "shldisp.inc"
#ENDIF


'#if (_WIN32_IE >= 0x0400)
'// UrlHistory Guids
$CLSID_CUrlHistory                     = GUID$("{3C374A40-BAE4-11CF-BF7D-00AA006946EE}")
$SID_SUrlHistory                       = GUID$("{3C374A40-BAE4-11CF-BF7D-00AA006946EE}")

'//UrlSearchHook Guids
$CLSID_CURLSearchHook                  = GUID$("{CFBFAE00-17A6-11D0-99CB-00C04FD64497}")

'#define SID_SInternetExplorer IID_IWebBrowserApp
'#define SID_SWebBrowserApp    IID_IWebBrowserApp
$SID_SInternetExplorer                 = GUID$("{0002DF05-0000-0000-C000-000000000046}")
$SID_SWebBrowserApp                    = GUID$("{0002DF05-0000-0000-C000-000000000046}")

'#define SID_SWebBrowserEventsService IID_IWebBrowserEventsService

'// AutoComplete Guids
' IID_IAutoCompList: not included the Windows Vista SDK
$IID_IAutoCompList                     = GUID$("{00BB2760-6A77-11D0-A535-00C04FD7D062}")
$IID_IObjMgr                           = GUID$("{00BB2761-6A77-11D0-A535-00C04FD7D062}")
$IID_IACList                           = GUID$("{77A130B0-94FD-11D0-A544-00C04FD7d062}")
$IID_IACList2                          = GUID$("{470141A0-5186-11D2-BBB6-0060977B464C}")
$IID_ICurrentWorkingDirectory          = GUID$("{91956D21-9276-11D1-921A-006097DF5BD4}")
$CLSID_AutoComplete                    = GUID$("{00BB2763-6A77-11D0-A535-00C04FD7D062}")
$CLSID_ACLHistory                      = GUID$("{00BB2764-6A77-11D0-A535-00C04FD7D062}")
$CLSID_ACListISF                       = GUID$("{03C036F1-A186-11D0-824A-00AA005B4383}")
$CLSID_ACLMRU                          = GUID$("{6756A641-DE71-11d0-831B-00AA005B4383}")
$CLSID_ACLMulti                        = GUID$("{00BB2765-6A77-11D0-A535-00C04FD7D062}")
'#if (_WIN32_IE >= 0x0600)
$CLSID_ACLCustomMRU                    = GUID$("{6935DB93-21E8-4CCC-BEB9-9FE3C77A297A}")
'#endif

'#if (_WIN32_IE >= 0x0500)
$CLSID_ProgressDialog                  = GUID$("{F8383852-FCD3-11D1-A6B9-006097DF5BD4}")
$IID_IProgressDialog                   = GUID$("{EBBC7C04-315E-11D2-B62F-006097DF5BD4}")
'#endif // _WIN32_IE >= 0x0500

'//
'// Progress objects exposed via QueryService
'//
'#define SID_SProgressUI CLSID_ProgressDialog
$SID_SProgressUI                       = GUID$("{F8383852-FCD3-11D1-A6B9-006097DF5BD4}")

'//
'// Top-most browser implementation in the heirarchy. use IServiceProvider::QueryService()
'// to get to interfaces (IID_IShellBrowser, IID_IBrowserService, etc.)
'//
$SID_STopLevelBrowser                  = GUID$("{4C96BE40-915C-11CF-99D3-00AA004AE837}")

'#endif // _WIN32_IE >= 0x0400

#ENDIF    ' // !NO_SHDOCVW_GUIDS

$CLSID_FileTypes                       = GUID$("{B091E540-83E3-11CF-A713-0020AFD79762}")

'#if (_WIN32_IE >= 0x0400)

$CLSID_ActiveDesktop                   = GUID$("{75048700-EF1F-11D0-9888-006097DEACF9}")
$IID_IActiveDesktop                    = GUID$("{F490EB00-1240-11D1-9888-006097DEACF9}")
$IID_IActiveDesktopP                   = GUID$("{52502EE0-EC80-11D0-89AB-00C04FC2972D}")
$IID_IADesktopP2                       = GUID$("{B22754E2-4574-11D1-9888-006097DEACF9}")
$IID_ISynchronizedCallBack             = GUID$("{74C26041-70D1-11D1-B75A-00A0C90564FE}")

'// Extended column handler interfaces
' IID_IShellDetails3: not included the Windows Vista SDK
$IID_IShellDetails3                    = GUID$("{D2A105C0-87D5-11D1-8391-0000F80461CF}")
$IID_IQueryAssociations                = GUID$("{C46CA590-3C3F-11D2-BEE6-0000F805CA57}")
$CLSID_QueryAssociations               = GUID$("{A07034FD-6CAA-4954-AC3F-97A27216F98A}")
$IID_IColumnProvider                   = GUID$("{E8025004-1C42-11D2-BE2C-00A0C9A83DA1}")
' CLSID_DocFileColumnProvider: not included the Windows Vista SDK
$CLSID_DocFileColumnProvider           = GUID$("{24F14F01-7B1C-11D1-838F-0000F80461CF}")
$CLSID_LinkColumnProvider              = GUID$("{24F14F02-7B1C-11D1-838F-0000F80461CF}")
' CLSID_FileSysColumnProvider: not included the Windows Vista SDK
$CLSID_FileSysColumnProvider           = GUID$("{0D2E74C4-3C34-11D2-A27E-00C04FC30871}")

'// For Internet Shortcut Creation Command
'// The shell uses this command to allow trident to save off it's per frame data in the shortcut
'// and to allow it to fire the OnPersist() event on every frame
'// {93A68750-951A-11d1-946F-000000000000}
$CGID_ShortCut                         = GUID$("{93A68750-951A-11D1-946F-000000000000}")
$IID_INamedPropertyBag                 = GUID$("{FB700430-952C-11D1-946F-000000000000}")
$CLSID_InternetButtons                 = GUID$("{1E796980-9CC5-11D1-A83F-00C04FC99D61}")
'#if (_WIN32_IE >= 0x0500)
$CLSID_MSOButtons                      = GUID$("{178F34B8-A282-11D2-86C5-00C04F8EEA99}")
$CLSID_ToolbarExtButtons               = GUID$("{2CE4B5D8-A28F-11D2-86C5-00C04F8EEA99}")
'#endif // _WIN32_IE >= 0x0500
$CLSID_DarwinAppPublisher              = GUID$("{CFCCC7A0-A282-11D1-9082-006008059382}")
$CLSID_DocHostUIHandler                = GUID$("{7057E952-BD1B-11D1-8919-00C04FC2C836}")

'#if (_WIN32_IE >= 0x0500)
$IID_IShellFolder2                     = GUID$("{93F2F68C-1D1B-11d3-A30E-00C04F79ABD1}")

$PSGUID_SHELLDETAILS                   = "{28636AA6-953D-11D2-B5D6-00C04FD918D0}"
$FMTID_ShellDetails                    = GUID$("{28636AA6-953D-11D2-B5D6-00C04FD918D0}")

%PID_FINDDATA        = 0
%PID_NETRESOURCE     = 1
%PID_DESCRIPTIONID   = 2
%PID_WHICHFOLDER     = 3
%PID_NETWORKLOCATION = 4
%PID_COMPUTERNAME    = 5

'// PSGUID_STORAGE comes from ntquery.inc
'$PSGUID_STORAGE                        = "{B725F130-47EF-101A-A5F1-02608C9EEBAC}"
$FMTID_Storage                         = GUID$("{B725F130-47EF-101A-A5F1-02608C9EEBAC}")

'// Image properties
$PSGUID_IMAGEPROPERTIES                = "{14B81DA1-0135-4D31-96D9-6CBFC9671A99}"
$FMTID_ImageProperties                 = GUID$("{14B81DA1-0135-4D31-96D9-6CBFC9671A99}")

'// Custom Image Properties (not EXIF tags, which go into the auxiliary image property store)
'// {7ECD8B0E-C136-4a9b-9411-4EBD6673CCC3}
$PSGUID_CUSTOMIMAGEPROPERTIES          = "{7ECD8B0E-C136-4A9B-9411-4EBD6673CCC3}"
$FMTID_CustomImageProperties           = GUID$("{7ECD8B0E-C136-4A9B-9411-4EBD6673CCC3}")

'// Library properties
$PSGUID_LIBRARYPROPERTIES              = "{5D76B67F-9B3D-44BB-B6AE-25DA4F638A67}"
$FMTID_LibraryProperties               = GUID$("{5D76B67F-9B3D-44BB-B6AE-25DA4F638A67}")

'// The GUIDs used to identify shell item attributes (columns). See IShellFolder2::GetDetailsEx implementations...

$PSGUID_DISPLACED                      = "{9B174B33-40FF-11D2-A27E-00C04FC30871}"
$FMTID_Displaced                       = GUID$("{9B174B33-40FF-11D2-A27E-00C04FC30871}")
%PID_DISPLACED_FROM = 2
%PID_DISPLACED_DATE = 3

$PSGUID_BRIEFCASE                      = "{328D8B21-7729-4BFC-954C-902B329D56B0}"
$FMTID_Briefcase                       = GUID$("{328D8B21-7729-4BFC-954C-902B329D56B0}")
%PID_SYNC_COPY_IN   = 2

$PSGUID_MISC                           = "{9B174B34-40FF-11D2-A27E-00C04FC30871}"
$FMTID_Misc                            = GUID$("{9B174B34-40FF-11D2-A27E-00C04FC30871}")
%PID_MISC_STATUS      = 2
%PID_MISC_ACCESSCOUNT = 3
%PID_MISC_OWNER       = 4
%PID_HTMLINFOTIPFILE  = 5
%PID_MISC_PICS        = 6
'// Do not add more pids beyond what shipped in Server 2k3 - just add PROPERTYKEYs to propkey.w

$PSGUID_WEBVIEW                        = "{F2275480-F782-4291-BD94-F13693513AEC}"
$FMTID_WebView                         = GUID$("{F2275480-F782-4291-BD94-F13693513AEC}")
%PID_DISPLAY_PROPERTIES = 0
%PID_INTROTEXT          = 1

$PSGUID_MUSIC                          = "{56A3372E-CE9C-11D2-9F0E-006097C686F6}"
$FMTID_MUSIC                           = GUID$("{56A3372E-CE9C-11D2-9F0E-006097C686F6}")
%PIDSI_ARTIST    = 2
%PIDSI_SONGTITLE = 3
%PIDSI_ALBUM     = 4
%PIDSI_YEAR      = 5
%PIDSI_COMMENT   = 6
%PIDSI_TRACK     = 7
%PIDSI_GENRE     = 11
%PIDSI_LYRICS    = 12
'// Do not add more pids to this file. Add new PROPERTYKEYs to propkey.w instead

$PSGUID_DRM                            = "{AEAC19E4-89AE-4508-B9B7-BB867ABEE2ED}"
$FMTID_DRM                             = GUID$("{AEAC19E4-89AE-4508-B9B7-BB867ABEE2ED}")
%PIDDRSI_PROTECTED   = 2
%PIDDRSI_DESCRIPTION = 3
%PIDDRSI_PLAYCOUNT   = 4
%PIDDRSI_PLAYSTARTS  = 5
%PIDDRSI_PLAYEXPIRES = 6

$PSGUID_VIDEO                          = "{64440491-4C8B-11D1-8B70-080036B11A03}"
'//  FMTID_VideoSummaryInformation property identifiers
%PIDVSI_STREAM_NAME      = &H00000002  ' // "StreamName", VT_LPWSTR
%PIDVSI_FRAME_WIDTH      = &H00000003  ' // "FrameWidth", VT_UI4
%PIDVSI_FRAME_HEIGHT     = &H00000004  ' // "FrameHeight", VT_UI4
%PIDVSI_TIMELENGTH       = &H00000007  ' // "TimeLength", VT_UI4, milliseconds
%PIDVSI_FRAME_COUNT      = &H00000005  ' // "FrameCount". VT_UI4
%PIDVSI_FRAME_RATE       = &H00000006  ' // "FrameRate", VT_UI4, frames/millisecond
%PIDVSI_DATA_RATE        = &H00000008  ' // "DataRate", VT_UI4, bytes/second
%PIDVSI_SAMPLE_SIZE      = &H00000009  ' // "SampleSize", VT_UI4
%PIDVSI_COMPRESSION      = &H0000000A  ' // "Compression", VT_LPWSTR
%PIDVSI_STREAM_NUMBER    = &H0000000B  ' // "StreamNumber", VT_UI2

$PSGUID_AUDIO                          = "{64440490-4C8B-11D1-8B70-080036B1A003}"
'//  FMTID_AudioSummaryInformation property identifiers
%PIDASI_FORMAT           = &H00000002  ' // VT_BSTR
%PIDASI_TIMELENGTH       = &H00000003  ' // VT_UI4, milliseconds
%PIDASI_AVG_DATA_RATE    = &H00000004  ' // VT_UI4,  Hz
%PIDASI_SAMPLE_RATE      = &H00000005  ' // VT_UI4,  bits
%PIDASI_SAMPLE_SIZE      = &H00000006  ' // VT_UI4,  bits
%PIDASI_CHANNEL_COUNT    = &H00000007  ' // VT_UI4
%PIDASI_STREAM_NUMBER    = &H00000008  ' // VT_UI2
%PIDASI_STREAM_NAME      = &H00000009  ' // VT_LPWSTR
%PIDASI_COMPRESSION      = &H0000000A  ' // VT_LPWSTR
'// Do not add more pids to this file. Add new PROPERTYKEYs to propkey.w instead

$PSGUID_CONTROLPANEL                   = "{305CA226-D286-468E-B848-2B2E8E697B74}"
%PID_CONTROLPANEL_CATEGORY = 2
'// Do not add more pids to this file. Add new PROPERTYKEYs to propkey.w instead

$PSGUID_VOLUME                         = "{9B174B35-40FF-11D2-A27E-00C04FC30871}"
$FMTID_Volume                          = GUID$("{9B174B35-40FF-11D2-A27E-00C04FC30871}")
%PID_VOLUME_FREE       = 2
%PID_VOLUME_CAPACITY   = 3
%PID_VOLUME_FILESYSTEM = 4
'// Do not add more pids to this file. Add new PROPERTYKEYs to propkey.w instead

$PSGUID_SHARE                          = "{D8C3986F-813B-449C-845D-87B95D674ADE}"
%PID_SHARE_CSC_STATUS  = 2
'// Do not add more pids to this file. Add new PROPERTYKEYs to propkey.w instead

$PSGUID_LINK                           = "{B9B4B3FC-2B51-4A42-B5D8-324146AFCF25}"
%PID_LINK_TARGET       = 2
%PID_LINK_TARGET_TYPE  = 3

$PSGUID_QUERY_D                        = "{49691C90-7E17-101A-A91C-08002B2ECDA9}"
$FMTID_Query                           = GUID$("{49691C90-7E17-101A-A91C-08002B2ECDA9}")
%PID_QUERY_RANK = 2

'// FMTID_SummaryInformation, see OLE docs for PID_ values for these
$PSGUID_SUMMARYINFORMATION             = "{F29F85E0-4FF9-1068-AB91-08002B27B3D9}"

'// FMTID_DocumentSummaryInformation, see OLE docs on the PID_ values for this
$PSGUID_DOCUMENTSUMMARYINFORMATION     = "{D5CDD502-2E9C-101B-9397-08002B2CF9AE}"

'// FMTID_MediaFileSummaryInformation, see propidl.h PID_ values for this
$PSGUID_MEDIAFILESUMMARYINFORMATION    = "{64440492-4C8B-11D1-8B70-080036B11A03}"

'// FMTID_ImageSummaryInformation,, see propidl.h PID_ values for this
$PSGUID_IMAGESUMMARYINFORMATION        = "{6444048F-4C8B-11D1-8B70-080036B11A03}"

$IID_IEnumExtraSearch                  = GUID$("{0E700BE1-9DB6-11D1-A1CE-00C04FD75D13}")
' CLSID_MountedVolume has been removed in Windows Vista SDK
$CLSID_MountedVolume                   = GUID$("{12518493-00B2-11D2-9FA5-9E3420524153}")
$CLSID_HWShellExecute                  = GUID$("{FFB8655F-81B9-4FCE-B89C-9A6BA76D13E7}")
$IID_IMountedVolume                    = GUID$("{12518492-00B2-11D2-9FA5-9E3420524153}")
$CLSID_DragDropHelper                  = GUID$("{4657278A-411B-11D2-839A-00C04FD918D0}")
$CLSID_CAnchorBrowsePropertyPage       = GUID$("{3050F3BB-98B5-11CF-BB82-00AA00BDCE0B}")
$CLSID_CImageBrowsePropertyPage        = GUID$("{3050F3B3-98B5-11CF-BB82-00AA00BDCE0B}")
$CLSID_CDocBrowsePropertyPage          = GUID$("{3050F3B4-98B5-11CF-BB82-00AA00BDCE0B}")
$IID_IFileSystemBindData               = GUID$("{01E18D10-4D8B-11D2-855D-006008059367}")
$SID_STopWindow                        = GUID$("{49E1B500-4636-11D3-97F7-00C04F45D0B3}")
$SID_SGetViewFromViewDual              = GUID$("{889A935D-971E-4B12-B90C-24DFC9E1E5E8}")

$CLSID_FolderItem                      = GUID$("{FEF10FA2-355E-4e06-9381-9B24D7F7CC88}")
' CLSID_FolderItemsFDF: Name changed to CLSID_FolderItemsMultiLevel in Windows Vista SDK
'$CLSID_FolderItemsFDF                  = GUID$("{53C74826-AB99-4d33-ACA4-3117F51D3788}")
$CLSID_FolderItemsMultiLevel           = GUID$("{53C74826-AB99-4d33-ACA4-3117F51D3788}")
$CLSID_NewMenu                         = GUID$("{D969A300-E7FF-11D0-A93B-00A0C90F2719}")

'//  BHIDs for IShellItem::BindToHandler()
'#define BHID_LocalCopyHelper     CLSID_LocalCopyHelper
' BHID_LocalCopyHelper: Removed in Windows Vista SDK
$BHID_LocalCopyHelper                  = GUID$("{021003E9-AAC0-4975-979F-14B5D4E717F8}")
$BHID_SFObject                         = GUID$("{3981E224-F559-11D3-8E3A-00C04F6837D5}")
$BHID_SFUIObject                       = GUID$("{3981E225-F559-11D3-8E3A-00C04F6837D5}")
$BHID_SFViewObject                     = GUID$("{3981E226-F559-11D3-8E3A-00C04F6837D5}")
$BHID_Storage                          = GUID$("{3981E227-F559-11D3-8E3A-00C04F6837D5}")
$BHID_Stream                           = GUID$("{1CEBB3AB-7C10-499A-A417-92CA16C4CB83}")
$BHID_LinkTargetItem                   = GUID$("{3981E228-F559-11D3-8E3A-00C04F6837D5}")
$BHID_StorageEnum                      = GUID$("{4621A4E3-F0D6-4773-8A9C-46E77B174840}")
'// if the item is a folder use this to get an ITransferSource or ITransferDestiation object
$BHID_Transfer                         = GUID$("{5D080304-FE2C-48FC-84CE-CF620B0F3C53}")
'// use this to get an IPropertyStore or IPropertyStoreFactory
'// to have more control over the property store for the item
$BHID_PropertyStore                    = GUID$("{0384E1A4-1523-439C-A4C8-AB911052f586}")
'// use this to get IExtractImage / IThumbnailProvider for an item
$BHID_ThumbnailHandler                 = GUID$("{7B2E650A-8E20-4F4A-B09E-6597AFC72FB0}")
'// if the item is a folder use this to get an IEnumShellItems that enumerates all items
'// in the folder including folders, non folders and hidden items
$BHID_EnumItems                        = GUID$("{94f60519-2850-4924-AA5A-D15E84868039}")
'// use this to get an IDataObject for an item or an array of items IShellItem/IShellItemArray::BindToHandler()
$BHID_DataObject                       = GUID$("{B8C0BD9F-ED24-455C-83E6-D5390C4FE8C4}")
'// use this to get an IQueryAssociations for an item or an array of items IShellItem/IShellItemArray::BindToHandler()
$BHID_AssociationArray                 = GUID$("{BEA9EF17-82F1-4F60-9284-4F8DB75C3BE9}")
'// use this to get an IFilter for an item
$BHID_Filter                           = GUID$("{38D08778-F557-4690-9EBF-BA54706AD8F7}")

'// use this to retrieve an IEnumAssocHandlers that enumerates the association handlers for the given item.  Returns an
'// enumeration of recommended handlers, similar to calling SHAssocEnumHandlers with ASSOC_FILTER_RECOMMENDED.
'// {b8ab0b9c-c2ec-4f7a-918d-314900e6280a}
$BHID_EnumAssocHandlers                = GUID$("{B8AB0B9C-C2EC-4F7A-918D-314900E6280A}")

'#endif // _WIN32_IE >= 0x0500

'#if _WIN32_IE >= 0x0600
$SID_CtxQueryAssociations              = GUID$("{FAADFC40-B777-4B69-AA81-77035EF0E6E8}")
'#endif // _WIN32_IE >= 0x0600

$IID_IDocViewSite                      = GUID$("{87D605E0-C511-11CF-89A9-00A0C9054129}")
$CLSID_QuickLinks                      = GUID$("{0E5CBF21-D15F-11d0-8301-00AA005B4383}")

'// The IShellFolder band
$CLSID_ISFBand                         = GUID$("{D82BE2B0-5764-11D0-A96E-00C04FD705A2}")

$IID_CDefView                          = GUID$("{4434FF80-EF4C-11CE-AE65-08002B2E1262}")
$CLSID_ShellFldSetExt                  = GUID$("{6D5313C0-8C62-11D1-B2CD-006097DF8C11}")
$SID_SMenuBandChild                    = GUID$("{ED9CC020-08B9-11D1-9823-00C04FD91972}")
$SID_SMenuBandParent                   = GUID$("{8C278EEC-3EAB-11D1-8CB0-00C04FD918D0}")
$SID_SMenuPopup                        = GUID$("{D1E7AFEB-6A2E-11D0-8C78-00C04FD918B4}")
$SID_SMenuBandBottomSelected           = GUID$("{165EBAF4-6D51-11D2-83AD-00C04FD918D0}")
$SID_SMenuBandBottom                   = GUID$("{743CA664-0DEB-11D1-9825-00C04FD91972}")
$SID_MenuShellFolder                   = GUID$("{A6C17EB4-2D65-11D2-838F-00C04FD918D0}")
$SID_SMenuBandContextMenuModifier      = GUID$("{39545874-7162-465E-B783-2AA1874FEF81}")
$SID_SMenuBandBKContextMenu            = GUID$("{164BBD86-1D0D-4DE0-9A3B-D9729647C2B8}")

'//Command Group ID for MenuDeskBar
$CGID_MENUDESKBAR                      = GUID$("{5C9F0A12-959E-11D0-A3A4-00A0C9082636}")

$SID_SMenuBandTop                      = GUID$("{9493A810-EC38-11D0-BC46-00AA006CE2F5}")
$CLSID_MenuToolbarBase                 = GUID$("{40B96610-B522-11D1-B3B4-00AA006EFDE7}")
$IID_IBanneredBar                      = GUID$("{596A9A94-013E-11D1-8D34-00A0C90F2719}")
$CLSID_MenuBandSite                    = GUID$("{E13EF4E4-D2F2-11D0-9816-00C04FD91972}")
$SID_SCommDlgBrowser                   = GUID$("{80F30233-B7DF-11D2-A33B-006097DF5BD4}")

'//
'// These GUIDs may be assigned to the CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR::guidFieldType
'// member by Microsoft ICredentialProvider implementations.
'//

$CPFG_LOGON_USERNAME                   = GUID$("{DA15BBE8-954D-4FD3-B0F4-1FB5B90B174B}")
$CPFG_LOGON_PASSWORD                   = GUID$("{60624CFA-A477-47B1-8A8E-3A4A19981827}")
$CPFG_SMARTCARD_USERNAME               = GUID$("{3E1ECF69-568C-4D96-9D59-46444174E2D6}")
$CPFG_SMARTCARD_PIN                    = GUID$("{4FE5263B-9181-46C1-B0A4-9DEDD4DB7DEA}")

'//
'//  Known Folder IDs
'//
#INCLUDE ONCE "knownfolders.inc"

'// some known folder types

'$FOLDERTYPEID_NotSpecified              = GUID$("{5C4F28B5-F869-4E84-8E60-F11DB97C5CC7}")   ' // Removed in Windows 7 SDK

'// FOLDERTYPEID_Invalid:              {57807898-8c4f-4462-bb63-71042380b109}
$FOLDERTYPEID_Invalid                   = GUID$("{57807898-8C4F-4462-BB63-71042380B109}")

'// FOLDERTYPEID_Generic:              {5c4f28b5-f869-4e84-8e60-f11db97c5cc7}
$FOLDERTYPEID_Generic                   = GUID$("{5C4F28B5-F869-4E84-8E60-F11DB97C5CC7}")

'// FOLDERTYPEID_GenericSearchResults: {7fde1a1e-8b31-49a5-93b8-6be14cfa4943}
$FOLDERTYPEID_GenericSearchResults      = GUID$("{7FDE1A1E-8B31-49A5-93B8-6BE14CFA4943}")

'// FOLDERTYPEID_GenericLibrary:       {5f4eab9a-6833-4f61-899d-31cf46979d49}
$FOLDERTYPEID_GenericLibrary            = GUID$("{5F4EAB9A-6833-4F61-899D-31CF46979D49}")

'// FOLDERTYPEID_Documents:            {7d49d726-3c21-4f05-99aa-fdc2c9474656}
$FOLDERTYPEID_Documents                 = GUID$("{7D49D726-3C21-4F05-99AA-FDC2C9474656}")

'// FOLDERTYPEID_Pictures:             {b3690e58-e961-423b-b687-386ebfd83239}
$FOLDERTYPEID_Pictures                  = GUID$("{B3690E58-E961-423B-B687-386EBFD83239}")

'// FOLDERTYPEID_Music:                {94d6ddcc-4a68-4175-a374-bd584a510b78}
$FOLDERTYPEID_Music                     = GUID$("{94D6DDCC-4A68-4175-A374-BD584A510B78}")

' // Removed
'$FOLDERTYPEID_MusicDetails              = GUID$("{AF9C03D6-7DB9-4A15-9464-13BF9FB69A2A}")
'$FOLDERTYPEID_MusicIcons                = GUID$("{0B7467FB-84BA-4AAE-A09B-15B71097AF9E}")

'// FOLDERTYPEID_Videos:               {5fa96407-7e77-483c-ac93-691d05850de8}
$FOLDERTYPEID_Videos                    = GUID$("{5FA96407-7E77-483C-AC93-691D05850DE8}")

'// FOLDERTYPEID_UserFiles:            {CD0FC69B-71E2-46e5-9690-5BCD9F57AAB3}
$FOLDERTYPEID_UserFiles                 = GUID$("{CD0FC69B-71E2-46E5-9690-5BCD9F57AAB3}")

'// FOLDERTYPID_UsersLibraries         {C4D98F09-6124-4fe0-9942-826416082DA9}
$FOLDERTYPEID_UsersLibraries            = GUID$("{C4D98F09-6124-4FE0-9942-826416082DA9}")

'// FOLDERTYPEID_OtherUsers,           {B337FD00-9DD5-4635-A6D4-DA33FD102B7A}
$FOLDERTYPEID_OtherUsers                = GUID$("{B337FD00-9DD5-4635-A6D4-DA33FD102B7A}")

'// {7F2F5B96-FF74-41da-AFD8-1C78A5F3AEA2}
$FOLDERTYPEID_PublishedItems            = GUID$("{7F2F5B96-FF74-41DA-AFD8-1C78A5F3AEA2}")

'// FOLDERTYPEID_Communications:       {91475fe5-586b-4eba-8d75-d17434b8cdf6}
$FOLDERTYPEID_Communications            = GUID$("{91475FE5-586B-4EBA-8D75-D17434B8CDF6}")

'// FOLDERTYPEID_Contacts:             {de2b70ec-9bf7-4a93-bd3d-243f7881d492}
$FOLDERTYPEID_Contacts                  = GUID$("{DE2B70EC-9BF7-4A93-BD3D-243F7881D492}")

'// FOLDERTYPEID_StartMenu:            {ef87b4cb-f2ce-4785-8658-4ca6c63e38c6}
$FOLDERTYPEID_StartMenu                 = GUID$("{EF87B4CB-F2CE-4785-8658-4CA6C63E38C6}")

'// FOLDERTYPEID_RecordedTV:           {5557a28f-5da6-4f83-8809-c2c98a11a6fa}
$FOLDERTYPEID_RecordedTV                = GUID$("{5557A28F-5DA6-4F83-8809-C2C98A11A6FA}")

'// FOLDERTYPEID_SavedGames:           {d0363307-28cb-4106-9f23-2956e3e5e0e7}
$FOLDERTYPEID_SavedGames                = GUID$("{D0363307-28CB-4106-9F23-2956E3E5E0E7}")

'// FOLDERTYPEID_OpenSearch:           {8faf9629-1980-46ff-8023-9dceab9c3ee3}
$FOLDERTYPEID_OpenSearch                = GUID$("{8FAF9629-1980-46FF-8023-9DCEAB9C3EE3}")

'// FOLDERTYPEID_SearchConnector:      {982725ee-6f47-479e-b447-812bfa7d2e8f}
$FOLDERTYPEID_SearchConnector           = GUID$("{982725EE-6F47-479E-B447-812BFA7D2E8F}")

'// foldertypes that do not have top views are below

'// FOLDERTYPEID_Games Folder          {b689b0d0-76d3-4cbb-87f7-585d0e0ce070}
$FOLDERTYPEID_Games                     = GUID$("{B689B0D0-76D3-4CBB-87F7-585D0E0CE070}")

'// category view of control panel
$FOLDERTYPEID_ControlPanelCategory      = GUID$("{DE4F0660-FA10-4B8F-A494-068B20B22307}")

'// classic-mode control panel
$FOLDERTYPEID_ControlPanelClassic       = GUID$("{0C3794F3-B545-43AA-A329-C37430C58D2A}")

'// prnfldr
$FOLDERTYPEID_Printers                  = GUID$("{2C7BBEC6-C844-4A0A-91FA-CEF6F59CFDA1}")

'// bbckfldr
$FOLDERTYPEID_RecycleBin                = GUID$("{D6D9E004-CD87-442B-9D57-5E0AEB4F6F72}")

'// software explorer for ARP
$FOLDERTYPEID_SoftwareExplorer          = GUID$("{D674391B-52D9-4E07-834E-67C98610F39D}")

'// ZIP folders
$FOLDERTYPEID_CompressedFolder          = GUID$("{80213E82-BCFD-4C4F-8817-BB27601267A9}")

'// NetworkExplorerFolder
$FOLDERTYPEID_NetworkExplorer           = GUID$("{25CC242B-9A7C-4F51-80E0-7A2928FEBE42}")

'// searches folder
'// FOLDERTYPEID_Searches:             {0b0ba2e3-405f-415e-a6ee-cad625207853}
$FOLDERTYPEID_Searches                  = GUID$("{0B0BA2E3-405F-415E-A6EE-CAD625207853}")

'// search home
'// FOLDERTYPEID_SearchHome:           {834d8a44-0974-4ed6-866e-f203d80b3810}
$FOLDERTYPEID_SearchHome                = GUID$("{834D8A44-0974-4ED6-866E-F203D80B3810}")

'//
'// Sync Manager object IDs.  These are GUIDs used in calls to the GetObject()
'// method on ISyncMgrHandler and ISyncMgrSyncItem, defined in SyncMgr.idl.
'//

$SYNCMGR_OBJECTID_Icon                  = GUID$("{6DBC85C3-5D07-4C72-A777-7FEC78072C06}")
$SYNCMGR_OBJECTID_EventStore            = GUID$("{4BEF34B9-A786-4075-BA88-0C2B9D89A98F}")
$SYNCMGR_OBJECTID_ConflictStore         = GUID$("{D78181F4-2389-47E4-A960-60BCC2ED930B}")
$SYNCMGR_OBJECTID_BrowseContent         = GUID$("{57CBB584-E9B4-47AE-A120-C4DF3335DEE2}")
$SYNCMGR_OBJECTID_ShowSchedule          = GUID$("{EDC6F3E3-8441-4109-ADF3-6C1CA0B7DE47}")
$SYNCMGR_OBJECTID_QueryBeforeActivate   = GUID$("{D882D80B-E7AA-49ED-86B7-E6E1F714CDFE}")
$SYNCMGR_OBJECTID_QueryBeforeDeactivate = GUID$("{A0EFC282-60E0-460E-9374-EA88513CFC80}")
$SYNCMGR_OBJECTID_QueryBeforeEnable     = GUID$("{04CBF7F0-5BEB-4DE1-BC90-908345C480F6}")
$SYNCMGR_OBJECTID_QueryBeforeDisable    = GUID$("{BB5F64AA-F004-4EB5-8E4D-26751966344C}")
$SYNCMGR_OBJECTID_QueryBeforeDelete     = GUID$("{F76C3397-AFB3-45D7-A59F-5A49E905437E}")
$SYNCMGR_OBJECTID_EventLinkClick        = GUID$("{2203BDC1-1AF1-4082-8C30-28399F41384C}")

'// IExplorerPaneVisibility constants
$EP_NavPane                             = GUID$("{CB316B22-25F7-42B8-8A09-540D23A43C2F}")
$EP_Commands                            = GUID$("{D9745868-CA5F-4A76-91CD-F5A129FBB076}")
$EP_Commands_Organize                   = GUID$("{72E81700-E3EC-4660-BF24-3C3B7B648806}")
$EP_Commands_View                       = GUID$("{21F7C32D-EEAA-439B-BB51-37B96FD6A943}")
$EP_DetailsPane                         = GUID$("{43ABF98B-89B8-472D-B9CE-E69B8229F019}")
$EP_PreviewPane                         = GUID$("{893C63D1-45C8-4D17-BE19-223BE71BE365}")
$EP_QueryPane                           = GUID$("{65BCDE4F-4F07-4F27-83A7-1AFCA4DF7DDD}")
$EP_AdvQueryPane                        = GUID$("{B4E9DB8B-34BA-4C39-B5CC-16A1BD2C411C}")

$CATID_LocationFactory                  = GUID$("{965C4D51-8B76-4E57-80B7-564D2EA4B55E}")
$CATID_LocationProvider                 = GUID$("{1B3CA474-2614-414B-B813-1ACECA3E3DD8}")

'// ItemsView
'// {ABBF5C45-5CCC-47b7-BB4E-87CB87BBD162}
$ItemCount_Property_GUID                = GUID$("{ABBF5C45-5CCC-47B7-BB4E-87CB87BBD162}")
'// {8FE316D2-0E52-460a-9C1E-48F273D470A3}
$SelectedItemCount_Property_GUID        = GUID$("{8FE316D2-0E52-460A-9C1E-48F273D470A3}")
'// {92A053DA-2969-4021-BF27-514CFC2E4A69}
$ItemIndex_Property_GUID                = GUID$("{92A053DA-2969-4021-BF27-514CFC2E4A69}")
