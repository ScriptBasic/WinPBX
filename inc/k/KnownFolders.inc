' ########################################################################################
' Microsoft Windows
' File: KnownFolders.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%KNOWNFOLDERS_INC = 1

'#ifdef DEFINE_KNOWN_FOLDER
'#undef DEFINE_KNOWN_FOLDER
'#endif

'#ifdef INITGUID
'#define DEFINE_KNOWN_FOLDER(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
'        EXTERN_C const GUID DECLSPEC_SELECTANY name \
'                = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }
'#else
'#define DEFINE_KNOWN_FOLDER(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
'        EXTERN_C const GUID name
'#endif // INITGUID

#IF %DEF(%INITGUID)
#IF NOT %DEF(%DEFINE_KNOWN_FOLDER)
%DEFINE_KNOWN_FOLDER = 1
MACRO DEFINE_KNOWN_FOLDER(guidName, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8)
   guidName.Data1    = l
   guidName.Data2    = w1
   guidName.Data3    = w2
   guidName.Data4(0) = b1
   guidName.Data4(1) = b2
   guidName.Data4(2) = b3
   guidName.Data4(3) = b4
   guidName.Data4(4) = b5
   guidName.Data4(5) = b6
   guidName.Data4(6) = b7
   guidName.Data4(7) = b8
END MACRO
#ENDIF ' // DEFINE_KNOWN_FOLDER
#ENDIF ' // INITGUID

'// legacy CSIDL value: CSIDL_NETWORK
'// display name: "Network"
'// legacy display name: "My Network Places"
'// default path:
'// {D20BEEC4-5CA8-4905-AE3B-BF251EA09B53}
$FOLDERID_NetworkFolder                = GUID$("{D20BEEC4-5CA8-4905-AE3B-BF251EA09B53}")

$FOLDERID_ComputerFolder               = GUID$("{0AC0837C-BBF8-452A-850D-79D08E667CA7}")
$FOLDERID_InternetFolder               = GUID$("{4D9F7874-4E0C-4904-967B-40B0D20C3E4B}")
$FOLDERID_ControlPanelFolder           = GUID$("{82A74AEB-AEB4-465C-A014-D097EE346D63}")
$FOLDERID_PrintersFolder               = GUID$("{76FC4E2D-D6AD-4519-A663-37BD56068185}")
$FOLDERID_SyncManagerFolder            = GUID$("{43668BF8-C14E-49B2-97C9-747784D784B7}")
$FOLDERID_SyncSetupFolder              = GUID$("{0F214138-B1D3-4A90-BBA9-27CBC0C5389A}")
$FOLDERID_ConflictFolder               = GUID$("{4BFEFB45-347D-4006-A5BE-AC0CB0567192}")
$FOLDERID_SyncResultsFolder            = GUID$("{289A9A43-BE44-4057-A41B-587A76D7E7F9}")
$FOLDERID_RecycleBinFolder             = GUID$("{B7534046-3ECB-4C18-BE4E-64CD4CB7D6AC}")
$FOLDERID_ConnectionsFolder            = GUID$("{6F0CD92B-2E97-45D1-88FF-B0D186B8DEDD}")
$FOLDERID_Fonts                        = GUID$("{FD228CB7-AE11-4AE3-864C-16F3910AB8FE}")

'// display name:        "Desktop"
'// default path:        "C:\Users\<UserName>\Desktop"
'// legacy default path: "C:\Documents and Settings\<userName>\Desktop"
'// legacy CSIDL value:  CSIDL_DESKTOP
'// {B4BFCC3A-DB2C-424C-B029-7FE99A87C641}
$FOLDERID_Desktop                      = GUID$("{B4BFCC3A-DB2C-424C-B029-7FE99A87C641}")

$FOLDERID_Startup                      = GUID$("{B97D20BB-F46A-4C97-BA10-5E3608430854}")
$FOLDERID_Programs                     = GUID$("{A77F5D77-2E2B-44C3-A6A2-ABA601054A51}")
$FOLDERID_StartMenu                    = GUID$("{625B53C3-AB48-4EC1-BA1F-A1EF4146FC19}")
$FOLDERID_Recent                       = GUID$("{AE50C081-EBD2-438A-8655-8A092E34987A}")
$FOLDERID_SendTo                       = GUID$("{8983036C-27C0-404B-8F08-102D10DCFD74}")
$FOLDERID_Documents                    = GUID$("{FDD39AD0-238F-46AF-ADB4-6C85480369C7}")
$FOLDERID_Favorites                    = GUID$("{1777F761-68AD-4D8A-87BD-30B759FA33DD}")
$FOLDERID_NetHood                      = GUID$("{C5ABBF53-E17F-4121-8900-86626FC2C973}")
$FOLDERID_PrintHood                    = GUID$("{9274BD8D-CFD1-41C3-B35E-B13F55A758F4}")
$FOLDERID_Templates                    = GUID$("{A63293E8-664E-48DB-A079-DF759E0509F7}")
$FOLDERID_CommonStartup                = GUID$("{82A5EA35-D9CD-47C5-9629-E15D2F714E6E}")
$FOLDERID_CommonPrograms               = GUID$("{0139D44E-6AFE-49F2-8690-3DAFCAE6FFB8}")
$FOLDERID_CommonStartMenu              = GUID$("{A4115719-D62E-491D-AA7C-E74B8BE3B067}")
$FOLDERID_PublicDesktop                = GUID$("{C4AA340D-F20F-4863-AFEF-F87EF2E6BA25}")
$FOLDERID_ProgramData                  = GUID$("{62AB5D82-FDC1-4DC3-A9DD-070D1D495D97}")
$FOLDERID_CommonTemplates              = GUID$("{B94237E7-57AC-4347-9151-B08C6C32D1F7}")
$FOLDERID_PublicDocuments              = GUID$("{ED4824AF-DCE4-45A8-81E2-FC7965083634}")
$FOLDERID_RoamingAppData               = GUID$("{3EB685DB-65F9-4CF6-A03A-E3EF65729F3D}")
$FOLDERID_LocalAppData                 = GUID$("{F1B32785-6FBA-4FCF-9D55-7B8E7F157091}")
$FOLDERID_LocalAppDataLow              = GUID$("{A520A1A4-1780-4FF6-BD18-167343C5AF16}")
$FOLDERID_InternetCache                = GUID$("{352481E8-33BE-4251-BA85-6007CAEDCF9D}")
$FOLDERID_Cookies                      = GUID$("{2B0F765D-C0E9-4171-908E-08A611B84FF6}")
$FOLDERID_History                      = GUID$("{D9DC8A3B-B784-432E-A781-5A1130A75963}")
$FOLDERID_System                       = GUID$("{1AC14E77-02E7-4E5D-B744-2EB1AE5198B7}")
$FOLDERID_SystemX86                    = GUID$("{D65231B0-B2F1-4857-A4CE-A8E7C6EA7D27}")
$FOLDERID_Windows                      = GUID$("{F38BF404-1D43-42F2-9305-67DE0B28FC23}")
$FOLDERID_Profile                      = GUID$("{5E6C858F-0E22-4760-9AFE-EA3317B67173}")
$FOLDERID_Pictures                     = GUID$("{33E28130-4E1E-4676-835A-98395C3BC3BB}")
$FOLDERID_ProgramFilesX86              = GUID$("{7C5A40EF-A0FB-4BFC-874A-C0F2E0B9FA8E}")
$FOLDERID_ProgramFilesCommonX86        = GUID$("{DE974D24-D9C6-4D3E-BF91-F4455120B917}")
$FOLDERID_ProgramFilesX64              = GUID$("{6D809377-6AF0-444b-8957-A3773F02200E}")
$FOLDERID_ProgramFilesCommonX64        = GUID$("{6365D5A7-0F0D-45e5-87F6-0DA56B6A4F7D}")
$FOLDERID_ProgramFiles                 = GUID$("{905E63B6-C1BF-494E-B29C-65B732D3D21A}")
$FOLDERID_ProgramFilesCommon           = GUID$("{F7F1ED05-9F6D-47A2-AAAE-29D317C6F066}")
$FOLDERID_UserProgramFiles             = GUID$("{5CD7AEE2-2219-4A67-B85D-6C9CE15660CB}")
$FOLDERID_UserProgramFilesCommon       = GUID$("{BCBD3057-CA5C-4622-B42D-BC56DB0AE516}")
$FOLDERID_AdminTools                   = GUID$("{724EF170-A42D-4FEF-9F26-B60E846FBA4F}")
$FOLDERID_CommonAdminTools             = GUID$("{D0384E7D-BAC3-4797-8F14-CBA229B392B5}")
$FOLDERID_Music                        = GUID$("{4BD8D571-6D19-48D3-BE97-422220080E43}")
$FOLDERID_Videos                       = GUID$("{18989B1D-99B5-455B-841C-AB7C74E4DDFC}")
$FOLDERID_Ringtones                    = GUID$("{C870044B-F49E-4126-A9C3-B52A1FF411E8}")
$FOLDERID_PublicPictures               = GUID$("{B6EBFB86-6907-413C-9AF7-4FC2ABF07CC5}")
$FOLDERID_PublicMusic                  = GUID$("{3214FAB5-9757-4298-BB61-92A9DEAA44FF}")
$FOLDERID_PublicVideos                 = GUID$("{2400183A-6185-49FB-A2D8-4A392A602BA3}")
$FOLDERID_PublicRingtones              = GUID$("{E555AB60-153B-4D17-9F04-A5FE99FC15EC}")
$FOLDERID_ResourceDir                  = GUID$("{8AD10C31-2ADB-4296-A8F7-E4701232C972}")
$FOLDERID_LocalizedResourcesDir        = GUID$("{2A00375E-224C-49DE-B8D1-440DF7EF3DDC}")
$FOLDERID_CommonOEMLinks               = GUID$("{C1BAE2D0-10DF-4334-BEDD-7AA20B227A9D}")
$FOLDERID_CDBurning                    = GUID$("{9E52AB10-F80D-49DF-ACB8-4330F5687855}")
$FOLDERID_UserProfiles                 = GUID$("{0762D272-C50A-4BB0-A382-697DCD729B80}")
$FOLDERID_Playlists                    = GUID$("{DE92C1C7-837F-4F69-A3BB-86E631204A23}")
$FOLDERID_SamplePlaylists              = GUID$("{15CA69B3-30EE-49C1-ACE1-6B5EC372AFB5}")
$FOLDERID_SampleMusic                  = GUID$("{B250C668-F57D-4EE1-A63C-290EE7D1AA1F}")
$FOLDERID_SamplePictures               = GUID$("{C4900540-2379-4C75-844B-64E6FAF8716B}")
$FOLDERID_SampleVideos                 = GUID$("{859EAD94-2E85-48AD-A71A-0969CB56A6CD}")
$FOLDERID_PhotoAlbums                  = GUID$("{69D2CF90-FC33-4FB7-9A0C-EBB0F0FCB43C}")
$FOLDERID_Public                       = GUID$("{DFDF76A2-C82A-4D63-906A-5644AC457385}")
$FOLDERID_ChangeRemovePrograms         = GUID$("{DF7266AC-9274-4867-8D55-3BD661DE872D}")
$FOLDERID_AppUpdates                   = GUID$("{A305CE99-F527-492B-8B1A-7E76FA98D6E4}")
$FOLDERID_AddNewPrograms               = GUID$("{DE61D971-5EBC-4F02-A3A9-6C82895E5C04}")
$FOLDERID_Downloads                    = GUID$("{374DE290-123F-4565-9164-39C4925E467B}")
$FOLDERID_PublicDownloads              = GUID$("{3D644C9B-1FB8-4F30-9B45-F670235F79C0}")
$FOLDERID_SavedSearches                = GUID$("{7D1D3A04-DEBB-4115-95CF-2F29DA2920DA}")
$FOLDERID_QuickLaunch                  = GUID$("{52A4F021-7B75-48A9-9F6B-4B87A210BC8F}")
$FOLDERID_Contacts                     = GUID$("{56784854-C6CB-462B-8169-88E350ACB882}")
$FOLDERID_SidebarParts                 = GUID$("{A75D362E-50FC-4FB7-AC2C-A8BEAA314493}")
$FOLDERID_SidebarDefaultParts          = GUID$("{7B396E54-9EC5-4300-BE0A-2482EBAE1A26}")
'$FOLDERID_TreeProperties               = GUID$("{5B3749AD-B49F-49C1-83EB-15370FBD4882}")   ' // Removed in Windows 7 SDK
$FOLDERID_PublicGameTasks              = GUID$("{DEBF2536-E1A8-4C59-B6A2-414586476AEA}")
$FOLDERID_GameTasks                    = GUID$("{054FAE61-4DD8-4787-80B6-090220C4B700}")
$FOLDERID_SavedGames                   = GUID$("{4C5C32FF-BB9D-43B0-B5B4-2D72E54EAAA4}")
$FOLDERID_Games                        = GUID$("{CAC52C1A-B53D-4EDC-92D7-6B2E8AC19434}")
'$FOLDERID_RecordedTV                   = GUID$("{BD85E001-112E-431E-983B-7B15AC09FFF1}")   ' // Removed in Windows 7 SDK
$FOLDERID_SEARCH_MAPI                  = GUID$("{98EC0E18-2098-4D44-8644-66979315A281}")
$FOLDERID_SEARCH_CSC                   = GUID$("{EE32E446-31CA-4ABA-814F-A5EBD2FD6D5E}")
$FOLDERID_Links                        = GUID$("{BFB9D5E0-C6A9-404C-B2B2-AE6DB6AF4968}")
$FOLDERID_UsersFiles                   = GUID$("{F3CE0F7C-4901-4ACC-8648-D5D44B04EF8F}")
$FOLDERID_UsersLibraries               = GUID$("{A302545D-DEFF-464B-ABE8-61C8648D939B}")
$FOLDERID_SearchHome                   = GUID$("{190337D1-B8CA-4121-A639-6D472D16972A}")
$FOLDERID_OriginalImages               = GUID$("{2C36C0AA-5812-4B87-BFD0-4CD0DFB19B39}")
$FOLDERID_DocumentsLibrary             = GUID$("{7B0DB17D-9CD2-4A93-9733-46CC89022E7C}")
$FOLDERID_MusicLibrary                 = GUID$("{2112AB0A-C86A-4FFE-A368-0DE96E47012E}")
$FOLDERID_PicturesLibrary              = GUID$("{A990AE9F-A03B-4E80-94BC-9912D7504104}")
$FOLDERID_VideosLibrary                = GUID$("{491E922F-5643-4AF4-A7EB-4E7A138D8174}")
$FOLDERID_RecordedTVLibrary            = GUID$("{1A6FDBA2-F42D-4358-A798-B74D745926C5}")
$FOLDERID_HomeGroup                    = GUID$("{52528A6B-B9E3-4ADD-B60D-588C2DBA842D}")
$FOLDERID_DeviceMetadataStore          = GUID$("{5CE4A5E9-E4EB-479D-B89F-130C02886155}")
$FOLDERID_Libraries                    = GUID$("{1B3EA5DC-B587-4786-B4EF-BD1DC332AEAE}")
$FOLDERID_PublicLibraries              = GUID$("{48DAF80B-E6CF-4F4E-B800-0E69D84EE384}")
$FOLDERID_UserPinned                   = GUID$("{9E3995AB-1F9C-4F13-B827-48B24B6C7174}")
$FOLDERID_ImplicitAppShortcuts         = GUID$("{BCB5256F-79F6-4CEE-B725-DC34E402FD46}")
