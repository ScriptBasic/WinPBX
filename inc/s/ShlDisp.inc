' ########################################################################################
' Microsoft Windows
' File: ShlDisp.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: Shell32
' Version: 1.0
' Documentation string: Microsoft Shell Controls And Automation
' Path: D:\WINDOWS\system32\SHELL32.dll
' Library GUID: {50A7E9B0-70EF-11D1-B75A-00A0C90564FE}
' ########################################################################################

#INCLUDE THIS ONCE
%SHLDISP_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "ocidl.inc"

$LIBID_Shell32 = GUID$("{50A7E9B0-70EF-11D1-B75A-00A0C90564FE}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {13709620-C279-11CE-A49E-444553540000}
$PROGID_ShellApplication1 = "Shell.Application.1"
' CLSID = {9BA05971-F6A8-11CF-A442-00A0C90A8F39}
$PROGID_ShellFolderView1 = "Shell.FolderView.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {13709620-C279-11CE-A49E-444553540000}
$PROGID_ShellApplication = "Shell.Application"
' CLSID = {9BA05971-F6A8-11CF-A442-00A0C90A8F39}
$PROGID_ShellFolderView = "Shell.FolderView"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_FileSearchBand = GUID$("{C4EE31F3-4768-11D2-BE5C-00A0C9A83DA1}")
$CLSID_PassportClientServices = GUID$("{2D2307C8-7DB4-40D6-9100-D52AF4F97A5B}")
$CLSID_SearchCommand = GUID$("{B005E690-678D-11D1-B758-00A0C90564FE}")
$CLSID_ShellDispatchInproc = GUID$("{0A89A860-D7B1-11CE-8350-444553540000}")
$CLSID_ShellFolderItem = GUID$("{2FE352EA-FD1F-11D2-B1F4-00C04F8EEB3E}")
$CLSID_ShellFolderView = GUID$("{62112AA1-EBE4-11CF-A5FB-0020AFE7292D}")
$CLSID_ShellLinkObject = GUID$("{11219420-1768-11D1-95BE-00609797EA4F}")
$CLSID_WebViewFolderContents = GUID$("{1820FED0-473E-11D0-A96C-00C04FD705A2}")
$CLSID_Shell = GUID$("{13709620-C279-11CE-A49E-444553540000}")
$CLSID_ShellFolderViewOC = GUID$("{9BA05971-F6A8-11CF-A442-00A0C90A8F39}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_DFConstraint = GUID$("{4A3DF050-23BD-11D2-939F-00A0C91EEDBA}")
$IID_DSearchCommandEvents = GUID$("{60890160-69F0-11D1-B758-00A0C90564FE}")
$IID_DShellFolderViewEvents = GUID$("{62112AA2-EBE4-11CF-A5FB-0020AFE7292D}")
$IID_ShellFolder = GUID$("{BBCBDE60-C3FF-11CE-8350-444553540000}")
$IID_ShellFolder2 = GUID$("{F0D2D8EF-3890-11D2-BF8B-00C04FB93661}")
$IID_ShellFolder3 = GUID$("{A7AE5F64-C4D7-4D7F-9307-4D24EE54B841}")
$IID_ShellFolderItem = GUID$("{FAC32C80-CBE4-11CE-8350-444553540000}")
$IID_ShellFolderItem2 = GUID$("{EDC817AA-92B8-11D1-B075-00C04FC33AA5}")
$IID_ShellFolderItems = GUID$("{744129E0-CBE5-11CE-8350-444553540000}")
$IID_ShellFolderItems2 = GUID$("{C94F0AD0-F363-11D2-A327-00C04F8EEC7F}")
$IID_ShellFolderItems3 = GUID$("{EAA7C309-BBEC-49D5-821D-64D966CB667F}")
$IID_ShellFolderItemVerb = GUID$("{08EC3E00-50B0-11CF-960C-0080C7F4EE85}")
$IID_ShellFolderItemVerbs = GUID$("{1F8352C0-50B0-11CF-960C-0080C7F4EE85}")
$IID_IFileSearchBand = GUID$("{2D91EEA1-9932-11D2-BE86-00A0C9A83DA1}")
$IID_IFolderViewOC = GUID$("{9BA05970-F6A8-11CF-A442-00A0C90A8F39}")
$IID_INewWDEvents = GUID$("{0751C551-7568-41C9-8E5B-E22E38919236}")
$IID_IPassportClientServices = GUID$("{B30F7305-5967-45D1-B7BC-D6EB7163D770}")
$IID_ISearchCommandExt = GUID$("{1D2EFD50-75CE-11D1-B75A-00A0C90564FE}")
$IID_IShellDispatch = GUID$("{D8F015C0-C278-11CE-A49E-444553540000}")
$IID_IShellDispatch2 = GUID$("{A4C6892C-3BA9-11D2-9DEA-00C04FB16162}")
$IID_IShellDispatch3 = GUID$("{177160CA-BB5A-411C-841D-BD38FACDEAA0}")
$IID_IShellDispatch4 = GUID$("{EFD84B2D-4BCF-4298-BE25-EB542A59FBDA}")
$IID_IShellDispatch5 = GUID$("{866738B9-6CF2-4DE8-8767-F794EBE74F4E}")
$IID_IShellFolderViewDual = GUID$("{E7A1AF80-4D96-11CF-960C-0080C7F4EE85}")
$IID_IShellFolderViewDual2 = GUID$("{31C147B6-0ADE-4A3C-B514-DDF932EF6D17}")
$IID_IShellFolderViewDual3 = GUID$("{29EC8E6C-46D3-411F-BAAA-611A6C9CAC66}")
$IID_IShellLinkDual = GUID$("{88A05C00-F000-11CE-8350-444553540000}")
$IID_IShellLinkDual2 = GUID$("{317EE249-F12E-11D2-B1E4-00C04F8EEB3E}")
$IID_IWebWizardHost = GUID$("{18BCC359-4990-4BFB-B951-3C83702BE5F9}")

' ========================================================================================
' SearchCommandExecuteErrors enum
' IID: {418F4E6A-B903-11D1-B0A6-00C04FC33AA5}
' Search Command Execute Errors
' ========================================================================================

%SCEE_PATHNOTFOUND     = 1
%SCEE_MAXFILESFOUND    = %SCEE_PATHNOTFOUND  + 1
%SCEE_INDEXSEARCH      = %SCEE_MAXFILESFOUND + 1
%SCEE_CONSTRAINT       = %SCEE_INDEXSEARCH   + 1
%SCEE_SCOPEMISMATCH    = %SCEE_CONSTRAINT    + 1
%SCEE_CASESENINDEX     = %SCEE_SCOPEMISMATCH + 1
%SCEE_INDEXNOTCOMPLETE = %SCEE_CASESENINDEX  + 1

' ========================================================================================
' OfflineFolderStatus enum
' IID: {35F1A0D0-3E9A-11D2-8499-005345000000}
' Constants for Folder2.OfflineStatus
' ========================================================================================

%OFS_INACTIVE   = -1
%OFS_ONLINE     = %OFS_INACTIVE + 1
%OFS_OFFLINE    = %OFS_ONLINE + 1
%OFS_SERVERBACK = %OFS_OFFLINE + 1
%OFS_DIRTYCACHE = %OFS_SERVERBACK + 1

' ========================================================================================
' ShellFolderViewOptions enum
' IID: {742A99A0-C77E-11D0-A32C-00A0C91EEDBA}
' Constants for ViewOptions
' ========================================================================================

%SFVVO_SHOWALLOBJECTS       = &H1
%SFVVO_SHOWEXTENSIONS       = &H2
%SFVVO_SHOWCOMPCOLOR        = &H8
%SFVVO_SHOWSYSFILES         = &H20
%SFVVO_WIN95CLASSIC         = &H40
%SFVVO_DOUBLECLICKINWEBVIEW = &H80
%SFVVO_DESKTOPHTML          = &H200

' ========================================================================================
' ShellSpecialFolderConstants enum
' IID: {CA31EA20-48D0-11CF-8350-444553540000}
' Constants for Special Folders for open/Explore
' ========================================================================================

%ssfDESKTOP          = &H0
%ssfPROGRAMS         = &H2
%ssfCONTROLS         = &H3
%ssfPRINTERS         = &H4
%ssfPERSONAL         = &H5
%ssfFAVORITES        = &H6
%ssfSTARTUP          = &H7
%ssfRECENT           = &H8
%ssfSENDTO           = &H9
%ssfBITBUCKET        = &HA
%ssfSTARTMENU        = &HB
%ssfDESKTOPDIRECTORY = &H10
%ssfDRIVES           = &H11
%ssfNETWORK          = &H12
%ssfNETHOOD          = &H13
%ssfFONTS            = &H14
%ssfTEMPLATES        = &H15
%ssfCOMMONSTARTMENU  = &H16
%ssfCOMMONPROGRAMS   = &H17
%ssfCOMMONSTARTUP    = &H18
%ssfCOMMONDESKTOPDIR = &H19
%ssfAPPDATA          = &H1A
%ssfPRINTHOOD        = &H1B
%ssfLOCALAPPDATA     = &H1C
%ssfALTSTARTUP       = &H1D
%ssfCOMMONALTSTARTUP = &H1E
%ssfCOMMONFAVORITES  = &H1F
%ssfINTERNETCACHE    = &H20
%ssfCOOKIES          = &H21
%ssfHISTORY          = &H22
%ssfCOMMONAPPDATA    = &H23
%ssfWINDOWS          = &H24
%ssfSYSTEM           = &H25
%ssfPROGRAMFILES     = &H26
%ssfMYPICTURES       = &H27
%ssfPROFILE          = &H28
%ssfSYSTEMx86        = &H29
%ssfPROGRAMFILESx86  = &H30


' ########################################################################################
' Interface name = IFolderViewOC
' IID = {9BA05970-F6A8-11CF-A442-00A0C90A8F39}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFolderViewOC_INTERFACE_DEFINED)
    %IFolderViewOC_INTERFACE_DEFINED = 1

INTERFACE IFolderViewOC $IID_IFolderViewOC

   INHERIT IDispatch

   ' =====================================================================================
   METHOD SetFolderView <1610743808> ( _                ' VTable offset = 28
     BYVAL pdisp AS IDispatch _                         ' __in IDispatch *pdisp
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFolderViewOC_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = DShellFolderViewEvents
' IID = 62112AA2-EBE4-11CF-A5FB-0020AFE7292D
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%DShellFolderViewEvents_DISPINTERFACE_DEFINED)
'    %DShellFolderViewEvents_DISPINTERFACE_DEFINED = 1

'INTERFACE DShellFolderViewEvents $IID_DShellFolderViewEvents

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __DShellFolderViewEvents_DISPINTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = DFConstraint
' IID = {4A3DF050-23BD-11D2-939F-00A0C91EEDBA}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%DFConstraint_INTERFACE_DEFINED)
    %DFConstraint_INTERFACE_DEFINED = 1

INTERFACE DFConstraint $IID_DFConstraint

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbs
   ' =====================================================================================
   PROPERTY GET Value <1610743809> ( _                  ' VTable offset = 32
   ) AS VARIANT                                         ' __retval_out VARIANT *pv
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DFConstraint_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = FolderItem
' IID = {FAC32C80-CBE4-11CE-8350-444553540000}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ShellFolderItem_INTERFACE_DEFINED)
    %ShellFolderItem_INTERFACE_DEFINED = 1

INTERFACE ShellFolderItem $IID_ShellFolderItem

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Application <1610743808> ( _            ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET Parent <1610743809> ( _                 ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbs
   ' =====================================================================================
   PROPERTY SET Name <0> ( _                            ' VTable offset = 40
     BYVAL bs AS WSTRING _                              ' __in BSTR bs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Path <1610743812> ( _                   ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbs
   ' =====================================================================================
   PROPERTY GET GetLink <1610743813> ( _                ' VTable offset = 48
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET GetFolder <1610743814> ( _              ' VTable offset = 52
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET IsLink <1610743815> ( _                 ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pb
   ' =====================================================================================
   PROPERTY GET IsFolder <1610743816> ( _               ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pb
   ' =====================================================================================
   PROPERTY GET IsFileSystem <1610743817> ( _           ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pb
   ' =====================================================================================
   PROPERTY GET IsBrowsable <1610743818> ( _            ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pb
   ' =====================================================================================
   PROPERTY GET ModifyDate <1610743819> ( _             ' VTable offset = 72
   ) AS DOUBLE                                          ' __retval_out DATE *pdt
   ' =====================================================================================
   PROPERTY SET ModifyDate <1610743819> ( _             ' VTable offset = 76
     BYVAL dt AS DOUBLE _                               ' __in DATE dt
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Size <1610743821> ( _                   ' VTable offset = 80
   ) AS LONG                                            ' __retval_out LONG *pul
   ' =====================================================================================
   PROPERTY GET Type <1610743822> ( _                   ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pbs
   ' =====================================================================================
   METHOD Verbs <1610743823> ( _                        ' VTable offset = 88
   ) AS ShellFolderItemVerbs                            ' __retval_out FolderItemVerbs **ppfic
   ' =====================================================================================
   METHOD InvokeVerb <1610743824> ( _                   ' VTable offset = 92
     OPTIONAL BYVAL vVerb AS VARIANT _                  ' __opt_in VARIANT vVerb
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __FolderItem_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = FolderItems
' IID = {744129E0-CBE5-11CE-8350-444553540000}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ShellFolderItems_INTERFACE_DEFINED)
    %ShellFolderItems_INTERFACE_DEFINED = 1

INTERFACE ShellFolderItems $IID_ShellFolderItems

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET Application <1610743809> ( _            ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET Parent <1610743810> ( _                 ' VTable offset = 36
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   METHOD Item <1610743811> ( _                         ' VTable offset = 40
     OPTIONAL BYVAL index AS VARIANT _                  ' __opt_in VARIANT index
   ) AS ShellFolderItemVerb                             ' __retval_out FolderItemVerb **ppid
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 44
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunk
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __FolderItems_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = FolderItemVerb
' IID = {08EC3E00-50B0-11CF-960C-0080C7F4EE85}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ShellFolderItemVerb_INTERFACE_DEFINED)
    %ShellFolderItemVerb_INTERFACE_DEFINED = 1

INTERFACE ShellFolderItemVerb $IID_ShellFolderItemVerb

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Application <1610743808> ( _            ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET Parent <1610743809> ( _                 ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbs
   ' =====================================================================================
   METHOD DoIt <1610743811> ( _                         ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF              ' /* __FolderItemVerb_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = FolderItemVerbs
' IID = {1F8352C0-50B0-11CF-960C-0080C7F4EE85}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ShellFolderItemVerbs_INTERFACE_DEFINED)
    %ShellFolderItemVerbs_INTERFACE_DEFINED = 1

INTERFACE ShellFolderItemVerbs $IID_ShellFolderItemVerbs

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET Application <1610743809> ( _            ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET Parent <1610743810> ( _                 ' VTable offset = 36
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   METHOD Item <1610743811> ( _                         ' VTable offset = 40
     OPTIONAL BYVAL index AS VARIANT _                  ' __opt_in VARIANT index
   ) AS ShellFolderItem                                 ' __retval_out FolderItem **ppid
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 44
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunk
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __FolderItemVerbs_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Folder
' IID = {BBCBDE60-C3FF-11CE-8350-444553540000}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ShellFolder_INTERFACE_DEFINED)
    %ShellFolder_INTERFACE_DEFINED = 1

INTERFACE ShellFolder $IID_ShellFolder

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Title <0> ( _                           ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbs
   ' =====================================================================================
   PROPERTY GET Application <1610743809> ( _            ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET Parent <1610743810> ( _                 ' VTable offset = 36
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET ParentFolder <1610743811> ( _           ' VTable offset = 40
   ) AS ShellFolder                                     ' __retval_out Folder **ppsf
   ' =====================================================================================
   METHOD Items <1610743812> ( _                        ' VTable offset = 44
   ) AS ShellFolderItems                                ' __retval_out FolderItems **ppid
   ' =====================================================================================
   METHOD ParseName <1610743813> ( _                    ' VTable offset = 48
     BYVAL bName AS WSTRING _                           ' __in BSTR bName
   ) AS ShellFolderItem                                 ' __retval_out FolderItem **ppid
   ' =====================================================================================
   METHOD NewFolder <1610743814> ( _                    ' VTable offset = 52
     BYVAL bName AS WSTRING _                           ' __in BSTR bName
   , OPTIONAL BYVAL vOptions AS VARIANT _               ' __opt_in VARIANT vOptions
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveHere <1610743815> ( _                     ' VTable offset = 56
     BYVAL vItem AS VARIANT _                           ' __in VARIANT vItem
   , OPTIONAL BYVAL vOptions AS VARIANT _               ' __opt_in VARIANT vOptions
   )                                                    ' void
   ' =====================================================================================
   METHOD CopyHere <1610743816> ( _                     ' VTable offset = 60
     BYVAL vItem AS VARIANT _                           ' __in VARIANT vItem
   , OPTIONAL BYVAL vOptions AS VARIANT _               ' __opt_in VARIANT vOptions
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDetailsOf <1610743817> ( _                 ' VTable offset = 64
     BYVAL vItem AS VARIANT _                           ' __in VARIANT vItem
   , BYVAL iColumn AS LONG _                            ' __in int iColumn
   ) AS WSTRING                                         ' __retval_out BSTR *pbs
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Folder_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Folder2
' IID = {F0D2D8EF-3890-11D2-BF8B-00C04FB93661}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = Folder
' ########################################################################################

#IF NOT %DEF(%ShellFolder2_INTERFACE_DEFINED)
    %ShellFolder2_INTERFACE_DEFINED = 1

INTERFACE ShellFolder2 $IID_ShellFolder2

   INHERIT IDispatch

   ' =====================================================================================
   ' Folder Methods
   ' =====================================================================================
   PROPERTY GET Title <0> ( _                           ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbs
   ' =====================================================================================
   PROPERTY GET Application <1610743809> ( _            ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET Parent <1610743810> ( _                 ' VTable offset = 36
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET ParentFolder <1610743811> ( _           ' VTable offset = 40
   ) AS ShellFolder                                     ' __retval_out Folder **ppsf
   ' =====================================================================================
   METHOD Items <1610743812> ( _                        ' VTable offset = 44
   ) AS ShellFolderItems                                ' __retval_out FolderItems **ppid
   ' =====================================================================================
   METHOD ParseName <1610743813> ( _                    ' VTable offset = 48
     BYVAL bName AS WSTRING _                           ' __in BSTR bName
   ) AS ShellFolderItem                                 ' __retval_out FolderItem **ppid
   ' =====================================================================================
   METHOD NewFolder <1610743814> ( _                    ' VTable offset = 52
     BYVAL bName AS WSTRING _                           ' __in BSTR bName
   , OPTIONAL BYVAL vOptions AS VARIANT _               ' __opt_in VARIANT vOptions
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveHere <1610743815> ( _                     ' VTable offset = 56
     BYVAL vItem AS VARIANT _                           ' __in VARIANT vItem
   , OPTIONAL BYVAL vOptions AS VARIANT _               ' __opt_in VARIANT vOptions
   )                                                    ' void
   ' =====================================================================================
   METHOD CopyHere <1610743816> ( _                     ' VTable offset = 60
     BYVAL vItem AS VARIANT _                           ' __in VARIANT vItem
   , OPTIONAL BYVAL vOptions AS VARIANT _               ' __opt_in VARIANT vOptions
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDetailsOf <1610743817> ( _                 ' VTable offset = 64
     BYVAL vItem AS VARIANT _                           ' __in VARIANT vItem
   , BYVAL iColumn AS LONG _                            ' __in int iColumn
   ) AS WSTRING                                         ' __retval_out BSTR *pbs
   ' =====================================================================================

   ' =====================================================================================
   ' Folder2 Methods
   ' =====================================================================================
   PROPERTY GET Self <1610809344> ( _                   ' VTable offset = 68
   ) AS ShellFolderItem                                 ' __retval_out FolderItem **ppfi
   ' =====================================================================================
   PROPERTY GET OfflineStatus <1610809345> ( _          ' VTable offset = 72
   ) AS LONG                                            ' __retval_out LONG *pul
   ' =====================================================================================
   METHOD Synchronize <1610809346> ( _                  ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HaveToShowWebViewBarricade <1> ( _      ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbHaveToShowWebViewBarricade
   ' =====================================================================================
   METHOD DismissedWebViewBarricade <1610809348> ( _    ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Folder2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Folder3
' IID = {A7AE5F64-C4D7-4D7F-9307-4D24EE54B841}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = Folder2
' ########################################################################################

#IF NOT %DEF(%ShellFolder3_INTERFACE_DEFINED)
    %ShellFolder3_INTERFACE_DEFINED = 1

INTERFACE ShellFolder3 $IID_ShellFolder3

   INHERIT IDispatch

   ' =====================================================================================
   ' Folder Methods
   ' =====================================================================================
   PROPERTY GET Title <0> ( _                           ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbs
   ' =====================================================================================
   PROPERTY GET Application <1610743809> ( _            ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET Parent <1610743810> ( _                 ' VTable offset = 36
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET ParentFolder <1610743811> ( _           ' VTable offset = 40
   ) AS ShellFolder                                     ' __retval_out Folder **ppsf
   ' =====================================================================================
   METHOD Items <1610743812> ( _                        ' VTable offset = 44
   ) AS ShellFolderItems                                ' __retval_out FolderItems **ppid
   ' =====================================================================================
   METHOD ParseName <1610743813> ( _                    ' VTable offset = 48
     BYVAL bName AS WSTRING _                           ' __in BSTR bName
   ) AS ShellFolderItem                                 ' __retval_out FolderItem **ppid
   ' =====================================================================================
   METHOD NewFolder <1610743814> ( _                    ' VTable offset = 52
     BYVAL bName AS WSTRING _                           ' __in BSTR bName
   , OPTIONAL BYVAL vOptions AS VARIANT _               ' __opt_in VARIANT vOptions
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveHere <1610743815> ( _                     ' VTable offset = 56
     BYVAL vItem AS VARIANT _                           ' __in VARIANT vItem
   , OPTIONAL BYVAL vOptions AS VARIANT _               ' __opt_in VARIANT vOptions
   )                                                    ' void
   ' =====================================================================================
   METHOD CopyHere <1610743816> ( _                     ' VTable offset = 60
     BYVAL vItem AS VARIANT _                           ' __in VARIANT vItem
   , OPTIONAL BYVAL vOptions AS VARIANT _               ' __opt_in VARIANT vOptions
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDetailsOf <1610743817> ( _                 ' VTable offset = 64
     BYVAL vItem AS VARIANT _                           ' __in VARIANT vItem
   , BYVAL iColumn AS LONG _                            ' __in int iColumn
   ) AS WSTRING                                         ' __retval_out BSTR *pbs
   ' =====================================================================================

   ' =====================================================================================
   ' Folder2 Methods
   ' =====================================================================================
   PROPERTY GET Self <1610809344> ( _                   ' VTable offset = 68
   ) AS ShellFolderItem                                 ' __retval_out FolderItem **ppfi
   ' =====================================================================================
   PROPERTY GET OfflineStatus <1610809345> ( _          ' VTable offset = 72
   ) AS LONG                                            ' __retval_out LONG *pul
   ' =====================================================================================
   METHOD Synchronize <1610809346> ( _                  ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HaveToShowWebViewBarricade <1> ( _      ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbHaveToShowWebViewBarricade
   ' =====================================================================================
   METHOD DismissedWebViewBarricade <1610809348> ( _    ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Folder3 Methods
   ' =====================================================================================
   PROPERTY GET ShowWebViewBarricade <2> ( _            ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbShowWebViewBarricade
   ' =====================================================================================
   PROPERTY SET ShowWebViewBarricade <2> ( _            ' VTable offset = 92
     BYVAL bShowWebViewBarricade AS INTEGER _           ' __in VARIANT_BOOL bShowWebViewBarricade
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Folder3_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = FolderItem2
' IID = {EDC817AA-92B8-11D1-B075-00C04FC33AA5}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = FolderItem
' ########################################################################################

#IF NOT %DEF(%ShellFolderItem2_INTERFACE_DEFINED)
    %ShellFolderItem2_INTERFACE_DEFINED = 1

INTERFACE ShellFolderItem2 $IID_ShellFolderItem2

   INHERIT IDispatch

   ' =====================================================================================
   ' FolderItem Methods
   ' =====================================================================================
   PROPERTY GET Application <1610743808> ( _            ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET Parent <1610743809> ( _                 ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbs
   ' =====================================================================================
   PROPERTY SET Name <0> ( _                            ' VTable offset = 40
     BYVAL bs AS WSTRING _                              ' __in BSTR bs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Path <1610743812> ( _                   ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbs
   ' =====================================================================================
   PROPERTY GET GetLink <1610743813> ( _                ' VTable offset = 48
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET GetFolder <1610743814> ( _              ' VTable offset = 52
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET IsLink <1610743815> ( _                 ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pb
   ' =====================================================================================
   PROPERTY GET IsFolder <1610743816> ( _               ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pb
   ' =====================================================================================
   PROPERTY GET IsFileSystem <1610743817> ( _           ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pb
   ' =====================================================================================
   PROPERTY GET IsBrowsable <1610743818> ( _            ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pb
   ' =====================================================================================
   PROPERTY GET ModifyDate <1610743819> ( _             ' VTable offset = 72
   ) AS DOUBLE                                          ' __retval_out DATE *pdt
   ' =====================================================================================
   PROPERTY SET ModifyDate <1610743819> ( _             ' VTable offset = 76
     BYVAL dt AS DOUBLE _                               ' __in DATE dt
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Size <1610743821> ( _                   ' VTable offset = 80
   ) AS LONG                                            ' __retval_out LONG *pul
   ' =====================================================================================
   PROPERTY GET Type <1610743822> ( _                   ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pbs
   ' =====================================================================================
   METHOD Verbs <1610743823> ( _                        ' VTable offset = 88
   ) AS ShellFolderItemVerbs                            ' __retval_out FolderItemVerbs **ppfic
   ' =====================================================================================
   METHOD InvokeVerb <1610743824> ( _                   ' VTable offset = 92
     OPTIONAL BYVAL vVerb AS VARIANT _                  ' __opt_in VARIANT vVerb
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' FolderItem2 Methods
   ' =====================================================================================
   METHOD InvokeVerbEx <1610809344> ( _                 ' VTable offset = 96
     OPTIONAL BYVAL vVerb AS VARIANT _                  ' __opt_in VARIANT vVerb
   , OPTIONAL BYVAL vArgs AS VARIANT _                  ' __opt_in VARIANT vArgs
   )                                                    ' void
   ' =====================================================================================
   METHOD ExtendedProperty <1610809345> ( _             ' VTable offset = 100
     BYVAL bstrPropName AS WSTRING _                    ' __in BSTR bstrPropName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvRet
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __FolderItem2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = FolderItems2
' IID = {C94F0AD0-F363-11D2-A327-00C04F8EEC7F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = FolderItems
' ########################################################################################

#IF NOT %DEF(%ShellFolderItems2_INTERFACE_DEFINED)
    %ShellFolderItems2_INTERFACE_DEFINED = 1

INTERFACE ShellFolderItems2 $IID_ShellFolderItems2

   INHERIT IDispatch

   ' =====================================================================================
   ' FolderItems Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET Application <1610743809> ( _            ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET Parent <1610743810> ( _                 ' VTable offset = 36
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   METHOD Item <1610743811> ( _                         ' VTable offset = 40
     OPTIONAL BYVAL index AS VARIANT _                  ' __opt_in VARIANT index
   ) AS ShellFolderItemVerb                             ' __retval_out FolderItemVerb **ppid
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 44
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunk
   ' =====================================================================================

   ' =====================================================================================
   ' FolderItems2 Methods
   ' =====================================================================================
   METHOD InvokeVerbEx <1610809344> ( _                 ' VTable offset = 48
     OPTIONAL BYVAL vVerb AS VARIANT _                  ' __opt_in VARIANT vVerb
   , OPTIONAL BYVAL vVerb AS VARIANT _                  ' __opt_in VARIANT vArgs
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __FolderItems2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = FolderItems3
' IID = {EAA7C309-BBEC-49D5-821D-64D966CB667F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = FolderItems2
' ########################################################################################

#IF NOT %DEF(%ShellFolderItems3_INTERFACE_DEFINED)
    %ShellFolderItems3_INTERFACE_DEFINED = 1

INTERFACE ShellFolderItems3 $IID_ShellFolderItems3

   INHERIT IDispatch

   ' =====================================================================================
   ' FolderItems Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET Application <1610743809> ( _            ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET Parent <1610743810> ( _                 ' VTable offset = 36
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   METHOD Item <1610743811> ( _                         ' VTable offset = 40
     OPTIONAL BYVAL index AS VARIANT _                  ' __opt_in VARIANT index
   ) AS ShellFolderItemVerb                             ' __retval_out FolderItemVerb **ppid
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 44
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunk
   ' =====================================================================================

   ' =====================================================================================
   ' FolderItems2 Methods
   ' =====================================================================================
   METHOD InvokeVerbEx <1610809344> ( _                 ' VTable offset = 48
     OPTIONAL BYVAL vVerb AS VARIANT _                  ' __opt_in VARIANT vVerb
   , OPTIONAL BYVAL vVerb AS VARIANT _                  ' __opt_in VARIANT vArgs
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' FolderItems3 Methods
   ' =====================================================================================
   METHOD Filter <1610874880> ( _                       ' VTable offset = 52
     BYVAL grfFlags AS LONG _                           ' __in long grfFlags
   , BYVAL bstrFileSpec AS WSTRING _                    ' __in BSTR bstrFileSpec
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Verbs <0> ( _                           ' VTable offset = 56
   ) AS ShellFolderItemVerbs                            ' __retval_out FolderItemVerbs **ppfic
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __FolderItems3_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IShellLinkDual
' IID = {88A05C00-F000-11CE-8350-444553540000}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IShellLinkDual_INTERFACE_DEFINED)
    %IShellLinkDual_INTERFACE_DEFINED = 1

INTERFACE IShellLinkDual $IID_IShellLinkDual

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Path <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbs
   ' =====================================================================================
   PROPERTY SET Path <1610743808> ( _                   ' VTable offset = 32
     BYVAL bs AS WSTRING _                              ' __in BSTR bs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <1610743810> ( _            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbs
   ' =====================================================================================
   PROPERTY SET Description <1610743810> ( _            ' VTable offset = 40
     BYVAL bs AS WSTRING _                              ' __in BSTR bs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WorkingDirectory <1610743812> ( _       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbs
   ' =====================================================================================
   PROPERTY SET WorkingDirectory <1610743812> ( _       ' VTable offset = 48
     BYVAL bs AS WSTRING _                              ' __in BSTR bs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Arguments <1610743814> ( _              ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbs
   ' =====================================================================================
   PROPERTY SET Arguments <1610743814> ( _              ' VTable offset = 56
     BYVAL bs AS WSTRING _                              ' __in BSTR bs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Hotkey <1610743816> ( _                 ' VTable offset = 60
   ) AS LONG                                            ' __retval_out int *piHK
   ' =====================================================================================
   PROPERTY SET Hotkey <1610743816> ( _                 ' VTable offset = 64
     BYVAL iHK AS LONG _                                ' __in int iHK
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowCommand <1610743818> ( _            ' VTable offset = 68
   ) AS LONG                                            ' __retval_out int *piShowCommand
   ' =====================================================================================
   PROPERTY SET ShowCommand <1610743818> ( _            ' VTable offset = 72
     BYVAL iShowCommand AS LONG _                       ' __in int iShowCommand
   )                                                    ' void
   ' =====================================================================================
   METHOD Resolve <1610743820> ( _                      ' VTable offset = 76
     BYVAL fFlags AS LONG _                             ' __in int fFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD GetIconLocation <1610743821> ( _              ' VTable offset = 80
     BYREF pbs AS WSTRING _                             ' __out BSTR *pbs
   ) AS LONG                                            ' __retval_out int *piIcon
   ' =====================================================================================
   METHOD SetIconLocation <1610743822> ( _              ' VTable offset = 84
     BYVAL bs AS WSTRING _                              ' __in BSTR bs
   , BYVAL iIcon AS LONG _                              ' __in int iIcon
   )                                                    ' void
   ' =====================================================================================
   METHOD Save <1610743823> ( _                         ' VTable offset = 88
     OPTIONAL BYVAL vWhere AS VARIANT _                 ' __opt_in VARIANT vWhere
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellLinkDual_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IShellLinkDual2
' IID = {317EE249-F12E-11D2-B1E4-00C04F8EEB3E}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IShellLinkDual
' ########################################################################################

#IF NOT %DEF(%IShellLinkDual2_INTERFACE_DEFINED)
    %IShellLinkDual2_INTERFACE_DEFINED = 1

INTERFACE IShellLinkDual2 $IID_IShellLinkDual2

   INHERIT IDispatch

   ' =====================================================================================
   ' IShellLinkDual Methods
   ' =====================================================================================
   PROPERTY GET Path <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbs
   ' =====================================================================================
   PROPERTY SET Path <1610743808> ( _                   ' VTable offset = 32
     BYVAL bs AS WSTRING _                              ' __in BSTR bs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <1610743810> ( _            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbs
   ' =====================================================================================
   PROPERTY SET Description <1610743810> ( _            ' VTable offset = 40
     BYVAL bs AS WSTRING _                              ' __in BSTR bs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WorkingDirectory <1610743812> ( _       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbs
   ' =====================================================================================
   PROPERTY SET WorkingDirectory <1610743812> ( _       ' VTable offset = 48
     BYVAL bs AS WSTRING _                              ' __in BSTR bs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Arguments <1610743814> ( _              ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbs
   ' =====================================================================================
   PROPERTY SET Arguments <1610743814> ( _              ' VTable offset = 56
     BYVAL bs AS WSTRING _                              ' __in BSTR bs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Hotkey <1610743816> ( _                 ' VTable offset = 60
   ) AS LONG                                            ' __retval_out int *piHK
   ' =====================================================================================
   PROPERTY SET Hotkey <1610743816> ( _                 ' VTable offset = 64
     BYVAL iHK AS LONG _                                ' __in int iHK
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowCommand <1610743818> ( _            ' VTable offset = 68
   ) AS LONG                                            ' __retval_out int *piShowCommand
   ' =====================================================================================
   PROPERTY SET ShowCommand <1610743818> ( _            ' VTable offset = 72
     BYVAL iShowCommand AS LONG _                       ' __in int iShowCommand
   )                                                    ' void
   ' =====================================================================================
   METHOD Resolve <1610743820> ( _                      ' VTable offset = 76
     BYVAL fFlags AS LONG _                             ' __in int fFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD GetIconLocation <1610743821> ( _              ' VTable offset = 80
     BYREF pbs AS WSTRING _                             ' __out BSTR *pbs
   ) AS LONG                                            ' __retval_out int *piIcon
   ' =====================================================================================
   METHOD SetIconLocation <1610743822> ( _              ' VTable offset = 84
     BYVAL bs AS WSTRING _                              ' __in BSTR bs
   , BYVAL iIcon AS LONG _                              ' __in int iIcon
   )                                                    ' void
   ' =====================================================================================
   METHOD Save <1610743823> ( _                         ' VTable offset = 88
     OPTIONAL BYVAL vWhere AS VARIANT _                 ' __opt_in VARIANT vWhere
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IShellLinkDual2 Methods
   ' =====================================================================================
   PROPERTY GET Target <1610809344> ( _                 ' VTable offset = 92
   ) AS ShellFolderItem                                 ' __retval_out FolderItem **ppfi
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellLinkDual2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IShellFolderViewDual
' IID = {E7A1AF80-4D96-11CF-960C-0080C7F4EE85}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IShellFolderViewDual_INTERFACE_DEFINED)
    %IShellFolderViewDual_INTERFACE_DEFINED = 1

INTERFACE IShellFolderViewDual $IID_IShellFolderViewDual

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Application <1610743808> ( _            ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET Parent <1610743809> ( _                 ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET Folder <1610743810> ( _                 ' VTable offset = 36
   ) AS ShellFolder                                     ' __retval_out Folder **ppid
   ' =====================================================================================
   METHOD SelectedItems <1610743811> ( _                ' VTable offset = 40
   ) AS ShellFolderItems                                ' __retval_out FolderItems **ppid
   ' =====================================================================================
   PROPERTY GET FocusedItem <1610743812> ( _            ' VTable offset = 44
   ) AS ShellFolderItem                                 ' __retval_out FolderItem **ppid
   ' =====================================================================================
   METHOD SelectItem <1610743813> ( _                   ' VTable offset = 48
     BYREF pvfi AS VARIANT _                            ' __in VARIANT *pvfi
   , BYVAL dwFlags AS LONG _                            ' __in int dwFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD PopupItemMenu <1610743814> ( _                ' VTable offset = 52
     BYVAL pfi AS ShellFolderItem _                     ' __in FolderItem *pfi
   , OPTIONAL BYVAL vx AS VARIANT _                     ' __opt_in VARIANT vx
   , OPTIONAL BYVAL vy AS VARIANT _                     ' __opt_in VARIANT vy
   ) AS WSTRING                                         ' __retval_out BSTR *pbs
   ' =====================================================================================
   PROPERTY GET Script <1610743815> ( _                 ' VTable offset = 56
   ) AS IDispatch                                       ' __retval_out IDispatch **ppDisp
   ' =====================================================================================
   PROPERTY GET ViewOptions <1610743816> ( _            ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *plViewOptions
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellFolderViewDual_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IShellFolderViewDual2
' IID = {31C147B6-0ADE-4A3C-B514-DDF932EF6D17}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IShellFolderViewDual
' ########################################################################################

#IF NOT %DEF(%IShellFolderViewDual2_INTERFACE_DEFINED)
    %IShellFolderViewDual2_INTERFACE_DEFINED = 1

INTERFACE IShellFolderViewDual2 $IID_IShellFolderViewDual2

   INHERIT IDispatch

   ' =====================================================================================
   ' IShellFolderViewDual Methods
   ' =====================================================================================
   PROPERTY GET Application <1610743808> ( _            ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET Parent <1610743809> ( _                 ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET Folder <1610743810> ( _                 ' VTable offset = 36
   ) AS ShellFolder                                     ' __retval_out Folder **ppid
   ' =====================================================================================
   METHOD SelectedItems <1610743811> ( _                ' VTable offset = 40
   ) AS ShellFolderItems                                ' __retval_out FolderItems **ppid
   ' =====================================================================================
   PROPERTY GET FocusedItem <1610743812> ( _            ' VTable offset = 44
   ) AS ShellFolderItem                                 ' __retval_out FolderItem **ppid
   ' =====================================================================================
   METHOD SelectItem <1610743813> ( _                   ' VTable offset = 48
     BYREF pvfi AS VARIANT _                            ' __in VARIANT *pvfi
   , BYVAL dwFlags AS LONG _                            ' __in int dwFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD PopupItemMenu <1610743814> ( _                ' VTable offset = 52
     BYVAL pfi AS ShellFolderItem _                     ' __in FolderItem *pfi
   , OPTIONAL BYVAL vx AS VARIANT _                     ' __opt_in VARIANT vx
   , OPTIONAL BYVAL vy AS VARIANT _                     ' __opt_in VARIANT vy
   ) AS WSTRING                                         ' __retval_out BSTR *pbs
   ' =====================================================================================
   PROPERTY GET Script <1610743815> ( _                 ' VTable offset = 56
   ) AS IDispatch                                       ' __retval_out IDispatch **ppDisp
   ' =====================================================================================
   PROPERTY GET ViewOptions <1610743816> ( _            ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *plViewOptions
   ' =====================================================================================

   ' =====================================================================================
   ' IShellFolderViewDual2 Methods
   ' =====================================================================================
   PROPERTY GET CurrentViewMode <1610809344> ( _        ' VTable offset = 64
   ) AS DWORD                                           ' __retval_out UINT *pViewMode
   ' =====================================================================================
   PROPERTY SET CurrentViewMode <1610809344> ( _        ' VTable offset = 68
     BYVAL ViewMode AS DWORD _                          ' __in UINT ViewMode
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectItemRelative <1610809346> ( _           ' VTable offset = 72
     BYVAL iRelative AS LONG _                          ' __in int iRelative
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellFolderViewDual2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IShellFolderViewDual3
' IID = {29EC8E6C-46D3-411F-BAAA-611A6C9CAC66}
' Inherited interface = IShellFolderViewDual2
' ########################################################################################

#IF NOT %DEF(%IShellFolderViewDual3_INTERFACE_DEFINED)
    %IShellFolderViewDual3_INTERFACE_DEFINED = 1

INTERFACE IShellFolderViewDual3 $IID_IShellFolderViewDual3

   INHERIT IDispatch

   ' =====================================================================================
   ' IShellFolderViewDual Methods
   ' =====================================================================================
   PROPERTY GET Application <1610743808> ( _            ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET Parent <1610743809> ( _                 ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET Folder <1610743810> ( _                 ' VTable offset = 36
   ) AS ShellFolder                                     ' __retval_out Folder **ppid
   ' =====================================================================================
   METHOD SelectedItems <1610743811> ( _                ' VTable offset = 40
   ) AS ShellFolderItems                                ' __retval_out FolderItems **ppid
   ' =====================================================================================
   PROPERTY GET FocusedItem <1610743812> ( _            ' VTable offset = 44
   ) AS ShellFolderItem                                 ' __retval_out FolderItem **ppid
   ' =====================================================================================
   METHOD SelectItem <1610743813> ( _                   ' VTable offset = 48
     BYREF pvfi AS VARIANT _                            ' __in VARIANT *pvfi
   , BYVAL dwFlags AS LONG _                            ' __in int dwFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD PopupItemMenu <1610743814> ( _                ' VTable offset = 52
     BYVAL pfi AS ShellFolderItem _                     ' __in FolderItem *pfi
   , OPTIONAL BYVAL vx AS VARIANT _                     ' __opt_in VARIANT vx
   , OPTIONAL BYVAL vy AS VARIANT _                     ' __opt_in VARIANT vy
   ) AS WSTRING                                         ' __retval_out BSTR *pbs
   ' =====================================================================================
   PROPERTY GET Script <1610743815> ( _                 ' VTable offset = 56
   ) AS IDispatch                                       ' __retval_out IDispatch **ppDisp
   ' =====================================================================================
   PROPERTY GET ViewOptions <1610743816> ( _            ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *plViewOptions
   ' =====================================================================================

   ' =====================================================================================
   ' IShellFolderViewDual2 Methods
   ' =====================================================================================
   PROPERTY GET CurrentViewMode <1610809344> ( _        ' VTable offset = 64
   ) AS DWORD                                           ' __retval_out UINT *pViewMode
   ' =====================================================================================
   PROPERTY SET CurrentViewMode <1610809344> ( _        ' VTable offset = 68
     BYVAL ViewMode AS DWORD _                          ' __in UINT ViewMode
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectItemRelative <1610809346> ( _           ' VTable offset = 72
     BYVAL iRelative AS LONG _                          ' __in int iRelative
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IShellFolderViewDual3 Methods
   ' =====================================================================================
   PROPERTY GET GroupBy ( _                             ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrGroupBy
   ' =====================================================================================
   PROPERTY SET GroupBy ( _                             ' VTable offset = 80
      BYVAL bstrGroupBy AS WSTRING _                    ' __in BSTR bstrGroupBy
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FolderFlags ( _                         ' VTable offset = 84
   ) AS DWORD                                           ' __retval_out DWORD *pdwFlags
   ' =====================================================================================
   PROPERTY SET FolderFlags ( _                         ' VTable offset = 88
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SortColumns ( _                         ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSortColumns
   ' =====================================================================================
   PROPERTY SET SortColumns ( _                         ' VTable offset = 96
      BYVAL bstrSortColumns AS WSTRING _                ' __in BSTR bstrSortColumns
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IconSize ( _                            ' VTable offset = 100
   ) AS LONG                                            ' __in int iIconSize
   ' =====================================================================================
   PROPERTY SET IconSize ( _                            ' VTable offset = 100
     BYVAL piIconSize AS LONG _                         ' __retval_out int *piIconSize
   )                                                    ' void
   ' =====================================================================================
   METHOD FilterView ( _                                ' VTable offset = 104
     BYVAL bstrFilterText AS WSTRING _                  ' __in BSTR bstrFilterText
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellFolderViewDual3_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IShellDispatch
' IID = {D8F015C0-C278-11CE-A49E-444553540000}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IShellDispatch_INTERFACE_DEFINED)
    %IShellDispatch_INTERFACE_DEFINED = 1

INTERFACE IShellDispatch $IID_IShellDispatch

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Application <1610743808> ( _            ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET Parent <1610743809> ( _                 ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   METHOD NameSpace <1610743810> ( _                    ' VTable offset = 36
     BYVAL vDir AS VARIANT _                            ' __in VARIANT vDir
   ) AS ShellFolder                                     ' __retval_out Folder **ppsdf
   ' =====================================================================================
   METHOD BrowseForFolder <1610743811> ( _              ' VTable offset = 40
     BYVAL Hwnd AS LONG _                               ' __in long Hwnd
   , BYVAL Title AS WSTRING _                           ' __in BSTR Title
   , BYVAL Options AS LONG _                            ' __in long Options
   , OPTIONAL BYVAL RootFolder AS VARIANT _             ' __opt_in VARIANT RootFolder
   ) AS ShellFolder                                     ' __retval_out Folder **ppsdf
   ' =====================================================================================
   METHOD Windows <1610743812> ( _                      ' VTable offset = 44
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   METHOD Open <1610743813> ( _                         ' VTable offset = 48
     BYVAL vDir AS VARIANT _                            ' __in VARIANT vDir
   )                                                    ' void
   ' =====================================================================================
   METHOD Explore <1610743814> ( _                      ' VTable offset = 52
     BYVAL vDir AS VARIANT _                            ' __in VARIANT vDir
   )                                                    ' void
   ' =====================================================================================
   METHOD MinimizeAll <1610743815> ( _                  ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD UndoMinimizeALL <1610743816> ( _              ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   METHOD FileRun <1610743817> ( _                      ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================
   METHOD CascadeWindows <1610743818> ( _               ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   METHOD TileVertically <1610743819> ( _               ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================
   METHOD TileHorizontally <1610743820> ( _             ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================
   METHOD ShutdownWindows <1610743821> ( _              ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   METHOD Suspend <1610743822> ( _                      ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD EjectPC <1610743823> ( _                      ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTime <1610743824> ( _                      ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD TrayProperties <1610743825> ( _               ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD Help <1610743826> ( _                         ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================
   METHOD FindFiles <1610743827> ( _                    ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================
   METHOD FindComputer <1610743828> ( _                 ' VTable offset = 108
   )                                                    ' void
   ' =====================================================================================
   METHOD RefreshMenu <1610743829> ( _                  ' VTable offset = 112
   )                                                    ' void
   ' =====================================================================================
   METHOD ControlPanelItem <1610743830> ( _             ' VTable offset = 116
     BYVAL szDir AS WSTRING _                           ' __in BSTR szDir
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellDispatch_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IShellDispatch2
' IID = {A4C6892C-3BA9-11D2-9DEA-00C04FB16162}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IShellDispatch
' ########################################################################################

#IF NOT %DEF(%IShellDispatch2_INTERFACE_DEFINED)
    %IShellDispatch2_INTERFACE_DEFINED = 1

INTERFACE IShellDispatch2 $IID_IShellDispatch2

   INHERIT IDispatch

   ' =====================================================================================
   ' IShellDispatch Methods
   ' =====================================================================================
   PROPERTY GET Application <1610743808> ( _            ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET Parent <1610743809> ( _                 ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   METHOD NameSpace <1610743810> ( _                    ' VTable offset = 36
     BYVAL vDir AS VARIANT _                            ' __in VARIANT vDir
   ) AS ShellFolder                                     ' __retval_out Folder **ppsdf
   ' =====================================================================================
   METHOD BrowseForFolder <1610743811> ( _              ' VTable offset = 40
     BYVAL Hwnd AS LONG _                               ' __in long Hwnd
   , BYVAL Title AS WSTRING _                           ' __in BSTR Title
   , BYVAL Options AS LONG _                            ' __in long Options
   , OPTIONAL BYVAL RootFolder AS VARIANT _             ' __opt_in VARIANT RootFolder
   ) AS ShellFolder                                     ' __retval_out Folder **ppsdf
   ' =====================================================================================
   METHOD Windows <1610743812> ( _                      ' VTable offset = 44
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   METHOD Open <1610743813> ( _                         ' VTable offset = 48
     BYVAL vDir AS VARIANT _                            ' __in VARIANT vDir
   )                                                    ' void
   ' =====================================================================================
   METHOD Explore <1610743814> ( _                      ' VTable offset = 52
     BYVAL vDir AS VARIANT _                            ' __in VARIANT vDir
   )                                                    ' void
   ' =====================================================================================
   METHOD MinimizeAll <1610743815> ( _                  ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD UndoMinimizeALL <1610743816> ( _              ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   METHOD FileRun <1610743817> ( _                      ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================
   METHOD CascadeWindows <1610743818> ( _               ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   METHOD TileVertically <1610743819> ( _               ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================
   METHOD TileHorizontally <1610743820> ( _             ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================
   METHOD ShutdownWindows <1610743821> ( _              ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   METHOD Suspend <1610743822> ( _                      ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD EjectPC <1610743823> ( _                      ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTime <1610743824> ( _                      ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD TrayProperties <1610743825> ( _               ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD Help <1610743826> ( _                         ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================
   METHOD FindFiles <1610743827> ( _                    ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================
   METHOD FindComputer <1610743828> ( _                 ' VTable offset = 108
   )                                                    ' void
   ' =====================================================================================
   METHOD RefreshMenu <1610743829> ( _                  ' VTable offset = 112
   )                                                    ' void
   ' =====================================================================================
   METHOD ControlPanelItem <1610743830> ( _             ' VTable offset = 116
     BYVAL szDir AS WSTRING _                           ' __in BSTR szDir
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IShellDispatch2 Methods
   ' =====================================================================================
   METHOD IsRestricted <1610809344> ( _                 ' VTable offset = 120
     BYVAL Group AS WSTRING _                           ' __in BSTR Group
   , BYVAL Restriction AS WSTRING _                     ' __in BSTR Restriction
   ) AS LONG                                            ' __retval_out long *plRestrictValue
   ' =====================================================================================
   METHOD ShellExecute <1610809345> ( _                 ' VTable offset = 124
     BYVAL File AS WSTRING _                            ' __in BSTR File
   , OPTIONAL BYVAL vArgs AS  VARIANT _                 ' __opt_in VARIANT vArgs
   , OPTIONAL BYVALvDir AS  VARIANT _                   ' __opt_in VARIANT vDir
   , OPTIONAL BYVAL vOperation AS VARIANT _             ' __opt_in VARIANT vOperation
   , OPTIONAL BYVAL vShow AS VARIANT _                  ' __opt_in VARIANT vShow
   )                                                    ' void
   ' =====================================================================================
   METHOD FindPrinter <1610809346> ( _                  ' VTable offset = 128
     OPTIONAL BYVAL name AS WSTRING _                   ' __opt_in BSTR name
   , OPTIONAL BYVAL location AS WSTRING _               ' __opt_in BSTR location
   , OPTIONAL BYVAL model AS WSTRING _                  ' __opt_in BSTR model
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSystemInformation <1610809347> ( _         ' VTable offset = 132
     BYVAL name AS WSTRING _                            ' __in BSTR name
   ) AS VARIANT                                         ' __retval_out VARIANT *pv
   ' =====================================================================================
   METHOD ServiceStart <1610809348> ( _                 ' VTable offset = 136
     BYVAL ServiceName AS WSTRING _                     ' __in BSTR ServiceName
   , BYVAL Persistent AS VARIANT _                      ' __in VARIANT Persistent
   ) AS VARIANT                                         ' __retval_out VARIANT *pSuccess
   ' =====================================================================================
   METHOD ServiceStop <1610809349> ( _                  ' VTable offset = 140
     BYVAL ServiceName AS WSTRING _                     ' __in BSTR ServiceName
   , BYVAL Persistent AS VARIANT _                      ' __in VARIANT Persistent
   ) AS VARIANT                                         ' __retval_out VARIANT *pSuccess
   ' =====================================================================================
   METHOD IsServiceRunning <1610809350> ( _             ' VTable offset = 144
     BYVAL ServiceName AS WSTRING _                     ' __in BSTR ServiceName
   ) AS VARIANT                                         ' __retval_out VARIANT *pRunning
   ' =====================================================================================
   METHOD CanStartStopService <1610809351> ( _          ' VTable offset = 148
     BYVAL ServiceName AS WSTRING _                     ' __in BSTR ServiceName
   ) AS VARIANT                                         ' __retval_out VARIANT *pCanStartStop
   ' =====================================================================================
   METHOD ShowBrowserBar <1610809352> ( _               ' VTable offset = 152
     BYVAL bstrClsid AS WSTRING _                       ' __in BSTR bstrClsid
   , BYVAL bShow AS VARIANT _                           ' __in VARIANT bShow
   ) AS VARIANT                                         ' __retval_out VARIANT *pSuccess
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellDispatch2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IShellDispatch3
' IID = {177160CA-BB5A-411C-841D-BD38FACDEAA0}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IShellDispatch2
' ########################################################################################

#IF NOT %DEF(%IShellDispatch3_INTERFACE_DEFINED)
    %IShellDispatch3_INTERFACE_DEFINED = 1

INTERFACE IShellDispatch3 $IID_IShellDispatch3

   INHERIT IDispatch

   ' =====================================================================================
   ' IShellDispatch Methods
   ' =====================================================================================
   PROPERTY GET Application <1610743808> ( _            ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET Parent <1610743809> ( _                 ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   METHOD NameSpace <1610743810> ( _                    ' VTable offset = 36
     BYVAL vDir AS VARIANT _                            ' __in VARIANT vDir
   ) AS ShellFolder                                     ' __retval_out Folder **ppsdf
   ' =====================================================================================
   METHOD BrowseForFolder <1610743811> ( _              ' VTable offset = 40
     BYVAL Hwnd AS LONG _                               ' __in long Hwnd
   , BYVAL Title AS WSTRING _                           ' __in BSTR Title
   , BYVAL Options AS LONG _                            ' __in long Options
   , OPTIONAL BYVAL RootFolder AS VARIANT _             ' __opt_in VARIANT RootFolder
   ) AS ShellFolder                                     ' __retval_out Folder **ppsdf
   ' =====================================================================================
   METHOD Windows <1610743812> ( _                      ' VTable offset = 44
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   METHOD Open <1610743813> ( _                         ' VTable offset = 48
     BYVAL vDir AS VARIANT _                            ' __in VARIANT vDir
   )                                                    ' void
   ' =====================================================================================
   METHOD Explore <1610743814> ( _                      ' VTable offset = 52
     BYVAL vDir AS VARIANT _                            ' __in VARIANT vDir
   )                                                    ' void
   ' =====================================================================================
   METHOD MinimizeAll <1610743815> ( _                  ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD UndoMinimizeALL <1610743816> ( _              ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   METHOD FileRun <1610743817> ( _                      ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================
   METHOD CascadeWindows <1610743818> ( _               ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   METHOD TileVertically <1610743819> ( _               ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================
   METHOD TileHorizontally <1610743820> ( _             ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================
   METHOD ShutdownWindows <1610743821> ( _              ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   METHOD Suspend <1610743822> ( _                      ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD EjectPC <1610743823> ( _                      ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTime <1610743824> ( _                      ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD TrayProperties <1610743825> ( _               ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD Help <1610743826> ( _                         ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================
   METHOD FindFiles <1610743827> ( _                    ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================
   METHOD FindComputer <1610743828> ( _                 ' VTable offset = 108
   )                                                    ' void
   ' =====================================================================================
   METHOD RefreshMenu <1610743829> ( _                  ' VTable offset = 112
   )                                                    ' void
   ' =====================================================================================
   METHOD ControlPanelItem <1610743830> ( _             ' VTable offset = 116
     BYVAL szDir AS WSTRING _                           ' __in BSTR szDir
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IShellDispatch2 Methods
   ' =====================================================================================
   METHOD IsRestricted <1610809344> ( _                 ' VTable offset = 120
     BYVAL Group AS WSTRING _                           ' __in BSTR Group
   , BYVAL Restriction AS WSTRING _                     ' __in BSTR Restriction
   ) AS LONG                                            ' __retval_out long *plRestrictValue
   ' =====================================================================================
   METHOD ShellExecute <1610809345> ( _                 ' VTable offset = 124
     BYVAL File AS WSTRING _                            ' __in BSTR File
   , OPTIONAL BYVAL vArgs AS  VARIANT _                 ' __opt_in VARIANT vArgs
   , OPTIONAL BYVALvDir AS  VARIANT _                   ' __opt_in VARIANT vDir
   , OPTIONAL BYVAL vOperation AS VARIANT _             ' __opt_in VARIANT vOperation
   , OPTIONAL BYVAL vShow AS VARIANT _                  ' __opt_in VARIANT vShow
   )                                                    ' void
   ' =====================================================================================
   METHOD FindPrinter <1610809346> ( _                  ' VTable offset = 128
     OPTIONAL BYVAL name AS WSTRING _                   ' __opt_in BSTR name
   , OPTIONAL BYVAL location AS WSTRING _               ' __opt_in BSTR location
   , OPTIONAL BYVAL model AS WSTRING _                  ' __opt_in BSTR model
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSystemInformation <1610809347> ( _         ' VTable offset = 132
     BYVAL name AS WSTRING _                            ' __in BSTR name
   ) AS VARIANT                                         ' __retval_out VARIANT *pv
   ' =====================================================================================
   METHOD ServiceStart <1610809348> ( _                 ' VTable offset = 136
     BYVAL ServiceName AS WSTRING _                     ' __in BSTR ServiceName
   , BYVAL Persistent AS VARIANT _                      ' __in VARIANT Persistent
   ) AS VARIANT                                         ' __retval_out VARIANT *pSuccess
   ' =====================================================================================
   METHOD ServiceStop <1610809349> ( _                  ' VTable offset = 140
     BYVAL ServiceName AS WSTRING _                     ' __in BSTR ServiceName
   , BYVAL Persistent AS VARIANT _                      ' __in VARIANT Persistent
   ) AS VARIANT                                         ' __retval_out VARIANT *pSuccess
   ' =====================================================================================
   METHOD IsServiceRunning <1610809350> ( _             ' VTable offset = 144
     BYVAL ServiceName AS WSTRING _                     ' __in BSTR ServiceName
   ) AS VARIANT                                         ' __retval_out VARIANT *pRunning
   ' =====================================================================================
   METHOD CanStartStopService <1610809351> ( _          ' VTable offset = 148
     BYVAL ServiceName AS WSTRING _                     ' __in BSTR ServiceName
   ) AS VARIANT                                         ' __retval_out VARIANT *pCanStartStop
   ' =====================================================================================
   METHOD ShowBrowserBar <1610809352> ( _               ' VTable offset = 152
     BYVAL bstrClsid AS WSTRING _                       ' __in BSTR bstrClsid
   , BYVAL bShow AS VARIANT _                           ' __in VARIANT bShow
   ) AS VARIANT                                         ' __retval_out VARIANT *pSuccess
   ' =====================================================================================

   ' =====================================================================================
   ' IShellDispatch3 Methods
   ' =====================================================================================
   METHOD AddToRecent <1610874880> ( _                  ' VTable offset = 156
     BYVAL varFile AS VARIANT _                         ' __in VARIANT varFile
   , OPTIONAL BYVAL bstrCategory AS WSTRING _           ' __opt_in BSTR bstrCategory
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellDispatch3_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IShellDispatch4
' IID = {EFD84B2D-4BCF-4298-BE25-EB542A59FBDA}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IShellDispatch3
' ########################################################################################

#IF NOT %DEF(%IShellDispatch4_INTERFACE_DEFINED)
    %IShellDispatch4_INTERFACE_DEFINED = 1

INTERFACE IShellDispatch4 $IID_IShellDispatch4

   INHERIT IDispatch

   ' =====================================================================================
   ' IShellDispatch Methods
   ' =====================================================================================
   PROPERTY GET Application <1610743808> ( _            ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET Parent <1610743809> ( _                 ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   METHOD NameSpace <1610743810> ( _                    ' VTable offset = 36
     BYVAL vDir AS VARIANT _                            ' __in VARIANT vDir
   ) AS ShellFolder                                     ' __retval_out Folder **ppsdf
   ' =====================================================================================
   METHOD BrowseForFolder <1610743811> ( _              ' VTable offset = 40
     BYVAL Hwnd AS LONG _                               ' __in long Hwnd
   , BYVAL Title AS WSTRING _                           ' __in BSTR Title
   , BYVAL Options AS LONG _                            ' __in long Options
   , OPTIONAL BYVAL RootFolder AS VARIANT _             ' __opt_in VARIANT RootFolder
   ) AS ShellFolder                                     ' __retval_out Folder **ppsdf
   ' =====================================================================================
   METHOD Windows <1610743812> ( _                      ' VTable offset = 44
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   METHOD Open <1610743813> ( _                         ' VTable offset = 48
     BYVAL vDir AS VARIANT _                            ' __in VARIANT vDir
   )                                                    ' void
   ' =====================================================================================
   METHOD Explore <1610743814> ( _                      ' VTable offset = 52
     BYVAL vDir AS VARIANT _                            ' __in VARIANT vDir
   )                                                    ' void
   ' =====================================================================================
   METHOD MinimizeAll <1610743815> ( _                  ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD UndoMinimizeALL <1610743816> ( _              ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   METHOD FileRun <1610743817> ( _                      ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================
   METHOD CascadeWindows <1610743818> ( _               ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   METHOD TileVertically <1610743819> ( _               ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================
   METHOD TileHorizontally <1610743820> ( _             ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================
   METHOD ShutdownWindows <1610743821> ( _              ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   METHOD Suspend <1610743822> ( _                      ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD EjectPC <1610743823> ( _                      ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTime <1610743824> ( _                      ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD TrayProperties <1610743825> ( _               ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD Help <1610743826> ( _                         ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================
   METHOD FindFiles <1610743827> ( _                    ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================
   METHOD FindComputer <1610743828> ( _                 ' VTable offset = 108
   )                                                    ' void
   ' =====================================================================================
   METHOD RefreshMenu <1610743829> ( _                  ' VTable offset = 112
   )                                                    ' void
   ' =====================================================================================
   METHOD ControlPanelItem <1610743830> ( _             ' VTable offset = 116
     BYVAL szDir AS WSTRING _                           ' __in BSTR szDir
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IShellDispatch2 Methods
   ' =====================================================================================
   METHOD IsRestricted <1610809344> ( _                 ' VTable offset = 120
     BYVAL Group AS WSTRING _                           ' __in BSTR Group
   , BYVAL Restriction AS WSTRING _                     ' __in BSTR Restriction
   ) AS LONG                                            ' __retval_out long *plRestrictValue
   ' =====================================================================================
   METHOD ShellExecute <1610809345> ( _                 ' VTable offset = 124
     BYVAL File AS WSTRING _                            ' __in BSTR File
   , OPTIONAL BYVAL vArgs AS  VARIANT _                 ' __opt_in VARIANT vArgs
   , OPTIONAL BYVALvDir AS  VARIANT _                   ' __opt_in VARIANT vDir
   , OPTIONAL BYVAL vOperation AS VARIANT _             ' __opt_in VARIANT vOperation
   , OPTIONAL BYVAL vShow AS VARIANT _                  ' __opt_in VARIANT vShow
   )                                                    ' void
   ' =====================================================================================
   METHOD FindPrinter <1610809346> ( _                  ' VTable offset = 128
     OPTIONAL BYVAL name AS WSTRING _                   ' __opt_in BSTR name
   , OPTIONAL BYVAL location AS WSTRING _               ' __opt_in BSTR location
   , OPTIONAL BYVAL model AS WSTRING _                  ' __opt_in BSTR model
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSystemInformation <1610809347> ( _         ' VTable offset = 132
     BYVAL name AS WSTRING _                            ' __in BSTR name
   ) AS VARIANT                                         ' __retval_out VARIANT *pv
   ' =====================================================================================
   METHOD ServiceStart <1610809348> ( _                 ' VTable offset = 136
     BYVAL ServiceName AS WSTRING _                     ' __in BSTR ServiceName
   , BYVAL Persistent AS VARIANT _                      ' __in VARIANT Persistent
   ) AS VARIANT                                         ' __retval_out VARIANT *pSuccess
   ' =====================================================================================
   METHOD ServiceStop <1610809349> ( _                  ' VTable offset = 140
     BYVAL ServiceName AS WSTRING _                     ' __in BSTR ServiceName
   , BYVAL Persistent AS VARIANT _                      ' __in VARIANT Persistent
   ) AS VARIANT                                         ' __retval_out VARIANT *pSuccess
   ' =====================================================================================
   METHOD IsServiceRunning <1610809350> ( _             ' VTable offset = 144
     BYVAL ServiceName AS WSTRING _                     ' __in BSTR ServiceName
   ) AS VARIANT                                         ' __retval_out VARIANT *pRunning
   ' =====================================================================================
   METHOD CanStartStopService <1610809351> ( _          ' VTable offset = 148
     BYVAL ServiceName AS WSTRING _                     ' __in BSTR ServiceName
   ) AS VARIANT                                         ' __retval_out VARIANT *pCanStartStop
   ' =====================================================================================
   METHOD ShowBrowserBar <1610809352> ( _               ' VTable offset = 152
     BYVAL bstrClsid AS WSTRING _                       ' __in BSTR bstrClsid
   , BYVAL bShow AS VARIANT _                           ' __in VARIANT bShow
   ) AS VARIANT                                         ' __retval_out VARIANT *pSuccess
   ' =====================================================================================

   ' =====================================================================================
   ' IShellDispatch3 Methods
   ' =====================================================================================
   METHOD AddToRecent <1610874880> ( _                  ' VTable offset = 156
     BYVAL varFile AS VARIANT _                         ' __in VARIANT varFile
   , OPTIONAL BYVAL bstrCategory AS WSTRING _           ' __opt_in BSTR bstrCategory
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IShellDispatch4 Methods
   ' =====================================================================================
   METHOD WindowsSecurity <1610940416> ( _              ' VTable offset = 160
   )                                                    ' void
   ' =====================================================================================
   METHOD ToggleDesktop <1610940417> ( _                ' VTable offset = 164
   )                                                    ' void
   ' =====================================================================================
   METHOD ExplorerPolicy <1610940418> ( _               ' VTable offset = 168
     BYVAL bstrPolicyName AS WSTRING _                  ' __in BSTR bstrPolicyName
   ) AS VARIANT                                         ' __retval_out VARIANT *pValue
   ' =====================================================================================
   METHOD GetSetting <1610940419> ( _                   ' VTable offset = 172
     BYVAL lSetting AS LONG _                           ' __in long lSetting
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellDispatch4_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IShellDispatch5
' IID = {866738B9-6CF2-4DE8-8767-F794EBE74F4E}
' Inherited interface = IShellDispatch4
' ########################################################################################

#IF NOT %DEF(%IShellDispatch5_INTERFACE_DEFINED)
    %IShellDispatch5_INTERFACE_DEFINED = 1

INTERFACE IShellDispatch5 $IID_IShellDispatch5

   INHERIT IDispatch

   ' =====================================================================================
   ' IShellDispatch Methods
   ' =====================================================================================
   PROPERTY GET Application <1610743808> ( _            ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   PROPERTY GET Parent <1610743809> ( _                 ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   METHOD NameSpace <1610743810> ( _                    ' VTable offset = 36
     BYVAL vDir AS VARIANT _                            ' __in VARIANT vDir
   ) AS ShellFolder                                     ' __retval_out Folder **ppsdf
   ' =====================================================================================
   METHOD BrowseForFolder <1610743811> ( _              ' VTable offset = 40
     BYVAL Hwnd AS LONG _                               ' __in long Hwnd
   , BYVAL Title AS WSTRING _                           ' __in BSTR Title
   , BYVAL Options AS LONG _                            ' __in long Options
   , OPTIONAL BYVAL RootFolder AS VARIANT _             ' __opt_in VARIANT RootFolder
   ) AS ShellFolder                                     ' __retval_out Folder **ppsdf
   ' =====================================================================================
   METHOD Windows <1610743812> ( _                      ' VTable offset = 44
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   METHOD Open <1610743813> ( _                         ' VTable offset = 48
     BYVAL vDir AS VARIANT _                            ' __in VARIANT vDir
   )                                                    ' void
   ' =====================================================================================
   METHOD Explore <1610743814> ( _                      ' VTable offset = 52
     BYVAL vDir AS VARIANT _                            ' __in VARIANT vDir
   )                                                    ' void
   ' =====================================================================================
   METHOD MinimizeAll <1610743815> ( _                  ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD UndoMinimizeALL <1610743816> ( _              ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   METHOD FileRun <1610743817> ( _                      ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================
   METHOD CascadeWindows <1610743818> ( _               ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   METHOD TileVertically <1610743819> ( _               ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================
   METHOD TileHorizontally <1610743820> ( _             ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================
   METHOD ShutdownWindows <1610743821> ( _              ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   METHOD Suspend <1610743822> ( _                      ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD EjectPC <1610743823> ( _                      ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTime <1610743824> ( _                      ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD TrayProperties <1610743825> ( _               ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD Help <1610743826> ( _                         ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================
   METHOD FindFiles <1610743827> ( _                    ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================
   METHOD FindComputer <1610743828> ( _                 ' VTable offset = 108
   )                                                    ' void
   ' =====================================================================================
   METHOD RefreshMenu <1610743829> ( _                  ' VTable offset = 112
   )                                                    ' void
   ' =====================================================================================
   METHOD ControlPanelItem <1610743830> ( _             ' VTable offset = 116
     BYVAL szDir AS WSTRING _                           ' __in BSTR szDir
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IShellDispatch2 Methods
   ' =====================================================================================
   METHOD IsRestricted <1610809344> ( _                 ' VTable offset = 120
     BYVAL Group AS WSTRING _                           ' __in BSTR Group
   , BYVAL Restriction AS WSTRING _                     ' __in BSTR Restriction
   ) AS LONG                                            ' __retval_out long *plRestrictValue
   ' =====================================================================================
   METHOD ShellExecute <1610809345> ( _                 ' VTable offset = 124
     BYVAL File AS WSTRING _                            ' __in BSTR File
   , OPTIONAL BYVAL vArgs AS  VARIANT _                 ' __opt_in VARIANT vArgs
   , OPTIONAL BYVALvDir AS  VARIANT _                   ' __opt_in VARIANT vDir
   , OPTIONAL BYVAL vOperation AS VARIANT _             ' __opt_in VARIANT vOperation
   , OPTIONAL BYVAL vShow AS VARIANT _                  ' __opt_in VARIANT vShow
   )                                                    ' void
   ' =====================================================================================
   METHOD FindPrinter <1610809346> ( _                  ' VTable offset = 128
     OPTIONAL BYVAL name AS WSTRING _                   ' __opt_in BSTR name
   , OPTIONAL BYVAL location AS WSTRING _               ' __opt_in BSTR location
   , OPTIONAL BYVAL model AS WSTRING _                  ' __opt_in BSTR model
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSystemInformation <1610809347> ( _         ' VTable offset = 132
     BYVAL name AS WSTRING _                            ' __in BSTR name
   ) AS VARIANT                                         ' __retval_out VARIANT *pv
   ' =====================================================================================
   METHOD ServiceStart <1610809348> ( _                 ' VTable offset = 136
     BYVAL ServiceName AS WSTRING _                     ' __in BSTR ServiceName
   , BYVAL Persistent AS VARIANT _                      ' __in VARIANT Persistent
   ) AS VARIANT                                         ' __retval_out VARIANT *pSuccess
   ' =====================================================================================
   METHOD ServiceStop <1610809349> ( _                  ' VTable offset = 140
     BYVAL ServiceName AS WSTRING _                     ' __in BSTR ServiceName
   , BYVAL Persistent AS VARIANT _                      ' __in VARIANT Persistent
   ) AS VARIANT                                         ' __retval_out VARIANT *pSuccess
   ' =====================================================================================
   METHOD IsServiceRunning <1610809350> ( _             ' VTable offset = 144
     BYVAL ServiceName AS WSTRING _                     ' __in BSTR ServiceName
   ) AS VARIANT                                         ' __retval_out VARIANT *pRunning
   ' =====================================================================================
   METHOD CanStartStopService <1610809351> ( _          ' VTable offset = 148
     BYVAL ServiceName AS WSTRING _                     ' __in BSTR ServiceName
   ) AS VARIANT                                         ' __retval_out VARIANT *pCanStartStop
   ' =====================================================================================
   METHOD ShowBrowserBar <1610809352> ( _               ' VTable offset = 152
     BYVAL bstrClsid AS WSTRING _                       ' __in BSTR bstrClsid
   , BYVAL bShow AS VARIANT _                           ' __in VARIANT bShow
   ) AS VARIANT                                         ' __retval_out VARIANT *pSuccess
   ' =====================================================================================

   ' =====================================================================================
   ' IShellDispatch3 Methods
   ' =====================================================================================
   METHOD AddToRecent <1610874880> ( _                  ' VTable offset = 156
     BYVAL varFile AS VARIANT _                         ' __in VARIANT varFile
   , OPTIONAL BYVAL bstrCategory AS WSTRING _           ' __opt_in BSTR bstrCategory
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IShellDispatch4 Methods
   ' =====================================================================================
   METHOD WindowsSecurity <1610940416> ( _              ' VTable offset = 160
   )                                                    ' void
   ' =====================================================================================
   METHOD ToggleDesktop <1610940417> ( _                ' VTable offset = 164
   )                                                    ' void
   ' =====================================================================================
   METHOD ExplorerPolicy <1610940418> ( _               ' VTable offset = 168
     BYVAL bstrPolicyName AS WSTRING _                  ' __in BSTR bstrPolicyName
   ) AS VARIANT                                         ' __retval_out VARIANT *pValue
   ' =====================================================================================
   METHOD GetSetting <1610940419> ( _                   ' VTable offset = 172
     BYVAL lSetting AS LONG _                           ' __in long lSetting
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pResult
   ' =====================================================================================

   ' =====================================================================================
   ' IShellDispatch5 Methods
   ' =====================================================================================
   METHOD WindowSwitcher ( _                            ' VTable offset = 176
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellDispatch5_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IFileSearchBand
' IID = {2D91EEA1-9932-11D2-BE86-00A0C9A83DA1}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFileSearchBand_INTERFACE_DEFINED)
    %IFileSearchBand_INTERFACE_DEFINED = 1

INTERFACE IFileSearchBand $IID_IFileSearchBand

   INHERIT IDispatch

   ' =====================================================================================
   METHOD SetFocus <1> ( _                              ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSearchParameters <2> ( _                   ' VTable offset = 32
     BYREF pbstrSearchID AS WSTRING _                   ' __in BSTR *pbstrSearchID
   , BYVAL bNavToResults AS INTEGER _                   ' __in VARIANT_BOOL bNavToResults
   , OPTIONAL BYREF pvarScope AS VARIANT _              ' __opt_in VARIANT *pvarScope
   , OPTIONAL BYREF pvarQueryFile AS VARIANT _          ' __opt_in VARIANT *pvarQueryFile
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SearchID <3> ( _                        ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSearchID
   ' =====================================================================================
   PROPERTY GET Scope <4> ( _                           ' VTable offset = 40
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarScope
   ' =====================================================================================
   PROPERTY GET QueryFile <5> ( _                       ' VTable offset = 44
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarFile
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileSearchBand_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWebWizardHost
' IID = {18BCC359-4990-4BFB-B951-3C83702BE5F9}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWebWizardHost_INTERFACE_DEFINED)
    %IWebWizardHost_INTERFACE_DEFINED = 1

INTERFACE IWebWizardHost $IID_IWebWizardHost

   INHERIT IDispatch

   ' =====================================================================================
   METHOD FinalBack <0> ( _                             ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD FinalNext <1> ( _                             ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD Cancel <2> ( _                                ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Caption <3> ( _                         ' VTable offset = 40
     BYVAL bstrCaption AS WSTRING _                     ' __in BSTR bstrCaption
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Caption <3> ( _                         ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCaption
   ' =====================================================================================
   PROPERTY SET Property <4> ( _                        ' VTable offset = 48
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   , BYREF IN pvProperty AS VARIANT _                   ' __in VARIANT *pvProperty
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Property <4> ( _                        ' VTable offset = 52
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProperty
   ' =====================================================================================
   METHOD SetWizardButtons <5> ( _                      ' VTable offset = 56
     BYVAL vfEnableBack AS INTEGER _                    ' __in VARIANT_BOOL vfEnableBack
   , BYVAL vfEnableNext AS INTEGER _                    ' __in VARIANT_BOOL vfEnableNext
   , BYVAL vfLastPage AS INTEGER _                      ' __in VARIANT_BOOL vfLastPage
   )                                                    ' void
   ' =====================================================================================
   METHOD SetHeaderText <6> ( _                         ' VTable offset = 60
     BYVAL bstrHeaderTitle AS WSTRING _                 ' __in BSTR bstrHeaderTitle
   , BYVAL bstrHeaderSubtitle AS WSTRING _              ' __in BSTR bstrHeaderSubtitle
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWebWizardHost_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = INewWDEvents
' IID = {0751C551-7568-41C9-8E5B-E22E38919236}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IWebWizardHost
' ########################################################################################

#IF NOT %DEF(%INewWDEvents_INTERFACE_DEFINED)
    %INewWDEvents_INTERFACE_DEFINED = 1

INTERFACE INewWDEvents $IID_INewWDEvents

   INHERIT IDispatch

   ' =====================================================================================
   ' IWebWizardHost Methods
   ' =====================================================================================
   METHOD FinalBack <0> ( _                             ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD FinalNext <1> ( _                             ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD Cancel <2> ( _                                ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Caption <3> ( _                         ' VTable offset = 40
     BYVAL bstrCaption AS WSTRING _                     ' __in BSTR bstrCaption
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Caption <3> ( _                         ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCaption
   ' =====================================================================================
   PROPERTY SET Property <4> ( _                        ' VTable offset = 48
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   , BYREF IN pvProperty AS VARIANT _                   ' __in VARIANT *pvProperty
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Property <4> ( _                        ' VTable offset = 52
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProperty
   ' =====================================================================================
   METHOD SetWizardButtons <5> ( _                      ' VTable offset = 56
     BYVAL vfEnableBack AS INTEGER _                    ' __in VARIANT_BOOL vfEnableBack
   , BYVAL vfEnableNext AS INTEGER _                    ' __in VARIANT_BOOL vfEnableNext
   , BYVAL vfLastPage AS INTEGER _                      ' __in VARIANT_BOOL vfLastPage
   )                                                    ' void
   ' =====================================================================================
   METHOD SetHeaderText <6> ( _                         ' VTable offset = 60
     BYVAL bstrHeaderTitle AS WSTRING _                 ' __in BSTR bstrHeaderTitle
   , BYVAL bstrHeaderSubtitle AS WSTRING _              ' __in BSTR bstrHeaderSubtitle
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' INewWDEvents Methods
   ' =====================================================================================
   METHOD PassportAuthenticate <7> ( _                  ' VTable offset = 64
     BYVAL bstrSignInUrl AS WSTRING _                   ' __in BSTR bstrSignInUrl
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvfAuthenitcated
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INewWDEvents_INTERFACE_DEFINED__ */


' ########################################################################################
' IAutoComplete interface
' IID = 00BB2762-6A77-11D0-A535-00C04FD7D062
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAutoComplete_INTERFACE_DEFINED)
    %IAutoComplete_INTERFACE_DEFINED = 1

$IID_IAutoComplete = GUID$("{00BB2762-6A77-11D0-A535-00C04FD7D062}")

INTERFACE IAutoComplete $IID_IAutoComplete

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Init ( _                                      ' VTable offset = 12
     BYVAL hwndEdit AS DWORD _                          ' __in HWND hwndEdit
   , BYVAL punkACL AS IUnknown _                        ' __in IUnknown *punkACL
   , BYVAL pwszRegKeyPath AS DWORD _                    ' __in LPCOLESTR pwszRegKeyPath
   , BYVAL pwszQuickComplete AS DWORD _                 ' __in LPCOLESTR pwszQuickComplete
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Enable ( _                                    ' VTable offset = 16
     BYVAL fEnable AS LONG _                            ' __in BOOL fEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAutoComplete_INTERFACE_DEFINED__ */


' ########################################################################################
' IAutoComplete2 interface
' IID = 00BB2762-6A77-11D0-A535-00C04FD7D062
' Inherited interface = IAutoComplete
' ########################################################################################

#IF NOT %DEF(%IAutoComplete2_INTERFACE_DEFINED)
    %IAutoComplete2_INTERFACE_DEFINED = 1

' enum AUTOCOMPLETEOPTIONS
%ACO_NONE               = 0
%ACO_AUTOSUGGEST        = &H1
%ACO_AUTOAPPEND         = &H2
%ACO_SEARCH             = &H4
%ACO_FILTERPREFIXES     = &H8
%ACO_USETAB             = &H10
%ACO_UPDOWNKEYDROPSLIST = &H20
%ACO_RTLREADING         = &H40
%ACO_WORD_FILTER        = &H80
%ACO_NOPREFIXFILTERING  = &H100

$IID_IAutoComplete2 = GUID$("{EAC04BC0-3791-11D2-BB95-0060977B464C}")

INTERFACE IAutoComplete2 $IID_IAutoComplete2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Init ( _                                      ' VTable offset = 12
     BYVAL hwndEdit AS DWORD _                          ' __in HWND hwndEdit
   , BYVAL punkACL AS IUnknown _                        ' __in IUnknown *punkACL
   , BYVAL pwszRegKeyPath AS DWORD _                    ' __in LPCOLESTR pwszRegKeyPath
   , BYVAL pwszQuickComplete AS DWORD _                 ' __in LPCOLESTR pwszQuickComplete
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Enable ( _                                    ' VTable offset = 16
     BYVAL fEnable AS LONG _                            ' __in BOOL fEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOptions ( _                                ' VTable offset = 20
     BYVAL dwFlag AS DWORD _                            ' __in DWORD dwFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOptions ( _                                ' VTable offset = 20
     BYREF pdwFlag AS DWORD _                           ' __out DWORD *pdwFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAutoComplete2_INTERFACE_DEFINED__ */


'// INTERFACE: IEnumACString
'//
'// This interface was implemented to return autocomplete strings
'// into the caller's buffer (to reduce the number of memory allocations).
'// A sort index is also returned to control the order of items displayed.
'// by autocomplete.  The sort index should be set to zero if unused.
'//
'// The NextItem method increments the current index by one (similar to Next
'// when one item is requested).
'//

#IF NOT %DEF(%IEnumACString_INTERFACE_DEFINED)
    %IEnumACString_INTERFACE_DEFINED = 1

' ACENUMOPTION enum
%ACEO_NONE            = 0
%ACEO_MOSTRECENTFIRST = &H1
%ACEO_FIRSTUNUSED     = &H10000

$IID_IEnumACString = GUID$("{8E74C210-CF9D-4EAF-A403-7356428F0A5A}")

INTERFACE IEnumACString $IID_IEnumACString

   INHERIT IUnknown

   ' =====================================================================================
   METHOD NextItem ( _                                  ' VTable offset = 12
     BYREF pszUrl AS DWORD _                            ' __out LPOLESTR pszUrl
   , BYVAL cchMax AS DWORD _                            ' __in ULONG cchMax
   , BYREF pulSortIndex AS DWORD _                      ' __out ULONG *pulSortIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEnumOptions ( _                            ' VTable offset = 16
     BYVAL dwOptions AS DWORD _                         ' __in DWORD dwOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEnumOptions ( _                            ' VTable offset = 20
     BYREF pdwOptions AS DWORD _                        ' __out DWORD *pdwOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumACString_INTERFACE_DEFINED__ */


'// INTERFACE: IAsyncOperation
'//
'// This interface was implemented to turn some previously synchronous
'// interfaces into async.  The following example is for
'// doing the IDataObject::Drop() operation asynchronously.
'//
'// Sometimes the rendering of the IDataObject data (IDataObject::GetData() or
'// STGMEDIUM.pStream->Read()) can be time intensive.  The IDropTarget
'// may want to do this on another thread.
'//
'// Implimentation Check list:
'// DoDragDrop Caller:
'//    If this code can support asynch operations, then it needs to
'//    QueryInterface() the IDataObject for IAsyncOperation.
'//    IAsyncOperation::SetAsyncMode(VARIANT_TRUE).
'//    After calling DoDragDrop(), call InOperation().  If any call fails
'//    or InOperation() return FALSE, use the pdwEffect returned by DoDragDrop()
'//    and the operation completed synchrously.
'//
'// OleSetClipboard Caller:
'//    If this code can support asynch operations, then it needs to
'//    QueryInterface() the IDataObject for IAsyncOperation.  Then call
'//    IAsyncOperation::SetAsyncMode(VARIANT_TRUE).
'//    If any of that fails, the final dwEffect should be passed to the IDataObject via
'//    CFSTR_PERFORMEDDROPEFFECT.
'//
'// IDataObect Object:
'//    IAsyncOperation::GetAsyncMode() should return whatever was last passed in
'//          fDoOpAsync to ::SetAsyncMode() or VARIANT_FALSE if ::SetAsyncMode()
'//          was never called.
'//    IAsyncOperation::SetAsyncMode() should AddRef and store paocb.
'//    IAsyncOperation::StartOperation() should store the fact that this was called and
'//          cause InOperation() to return VARIANT_TRUE.  pbcReserved is not used and needs
'//          to be NULL.
'//    IAsyncOperation::InOperation() should return VARIANT_TRUE only if ::StartOperation()
'//          was called.
'//    IAsyncOperation::EndOperation() needs to call paocbpaocb->EndOperation() with the same
'//          parameters.  Then release paocb.
'//    IDataObject::SetData(CFSTR_PERFORMEDDROPEFFECT) When this happens, call
'//          EndOperation(<into VAR>S_OK, NULL, <into VAR>dwEffect) and pass the dwEffect from the hglobal.
'//
'// IDropTarget Object:
'//    IDropTarget::Drop() If asynch operations aren't supported, nothing is required.
'//          The asynch operation can only happen if GetAsyncMode() returns VARIANT_TRUE.
'//          Before starting the asynch operation, StartOperation(NULL) needs to be called before
'//          returning from IDropTarget::Drop().


' ########################################################################################
' IAsyncOperation interface
' IID = 3D8B0590-F691-11d2-8EA9-006097DF5BD4
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAsyncOperation_INTERFACE_DEFINED)
    %IAsyncOperation_INTERFACE_DEFINED = 1

$IID_IAsyncOperation = GUID$("{3D8B0590-F691-11d2-8EA9-006097DF5BD4}")

INTERFACE IAsyncOperation $IID_IAsyncOperation

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAsyncMode ( _                              ' VTable offset = 12
     BYVAL fDoOpAsync AS LONG _                         ' __in BOOL fDoOpAsync
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAsyncMode ( _                              ' VTable offset = 16
     BYREF pfIsOpAsync AS LONG _                        ' __out BOOL *pfIsOpAsync
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StartOperation ( _                            ' VTable offset = 20
     BYVAL pbcReserved AS IBindCtx _                    ' __in IBindCtx *pbcReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InOperation ( _                               ' VTable offset = 24
     BYREF pfInAsyncOp AS LONG _                        ' __out BOOL *pfInAsyncOp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndOperation ( _                              ' VTable offset = 28
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL pbcReserved AS IBindCtx _                    ' __in IBindCtx *pbcReserved
   , BYVAL dwEffects AS DWORD _                         ' __in DWORD dwEffects
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAsyncOperation_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = DSearchCommandEvents
' IID = 60890160-69F0-11D1-B758-00A0C90564FE
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%DSearchCommandEvents_DISPINTERFACE_DEFINED)
'    %DSearchCommandEvents_DISPINTERFACE_DEFINED = 1

'INTERFACE DSearchCommandEvents $IID_DSearchCommandEvents

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __DSearchCommandEvents_DISPINTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISearchCommandExt
' IID = {1D2EFD50-75CE-11D1-B75A-00A0C90564FE}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' Windows Vista: Removed from thepublic headers.
' ########################################################################################

#IF NOT %DEF(%ISearchCommandExt_INTERFACE_DEFINED)
    %ISearchCommandExt_INTERFACE_DEFINED = 1

' SEARCH_FOR_TYPE enum
%SCE_SEARCHFORFILES     = 0
%SCE_SEARCHFORCOMPUTERS = 1

INTERFACE ISearchCommandExt $IID_ISearchCommandExt

   INHERIT IDispatch

   ' =====================================================================================
   METHOD ClearResults <1> ( _                          ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD NavigateToSearchResults <2> ( _               ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProgressText <3> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbs
   ' =====================================================================================
   METHOD SaveSearch <4> ( _                            ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD GetErrorInfo <5> ( _                          ' VTable offset = 44
     BYREF pbs AS WSTRING _                             ' __out BSTR *pbs
   ) AS LONG                                            ' __retval_out int *phr
   ' =====================================================================================
   METHOD SearchFor <6> ( _                             ' VTable offset = 48
     BYVAL iFor AS LONG _                               ' __in int iFor
   )                                                    ' void
   ' =====================================================================================
   METHOD GetScopeInfo <7> ( _                          ' VTable offset = 52
     BYVAL bsScope AS WSTRING _                         ' __in BSTR bsScope
   , BYREF pdwScopeInfo AS LONG _                       ' __out int *pdwScopeInfo
   )                                                    ' void
   ' =====================================================================================
   METHOD RestoreSavedSearch <8> ( _                    ' VTable offset = 56
     BYREF pvarFile AS VARIANT _                        ' __in VARIANT *pvarFile
   )                                                    ' void
   ' =====================================================================================
   METHOD Execute <100> ( _                             ' VTable offset = 60
     OPTIONAL BYREF RecordsAffected AS VARIANT _        ' __opt_in VARIANT *RecordsAffected
   , OPTIONAL BYREF Parameters AS VARIANT _             ' __opt_in VARIANT *Parameters
   , OPTIONAL BYVAL Options AS LONG _                   ' __opt_in long Options
   )                                                    ' void
   ' =====================================================================================
   METHOD AddConstraint <101> ( _                       ' VTable offset = 64
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYVAL Value AS VARIANT _                           ' __in VARIANT Value
   )                                                    ' void
   ' =====================================================================================
   METHOD GetNextConstraint <102> ( _                   ' VTable offset = 68
     BYVAL fReset AS INTEGER _                          ' __in VARIANT_BOOL fReset
   ) AS DFConstraint                                    ' __retval_out DFConstraint **ppdfc
   ' =====================================================================================

END INTERFACE

#ENDIF  '  /* __ISearchCommandExt_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPassportClientServices
' IID = {B30F7305-5967-45D1-B7BC-D6EB7163D770}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' This interface is not supported under Windows Vista and later. It has been removed from
' the public headers.
' ########################################################################################

#IF NOT %DEF(%IPassportClientServices_INTERFACE_DEFINED)
    %IPassportClientServices_INTERFACE_DEFINED = 1

INTERFACE IPassportClientServices $IID_IPassportClientServices

   INHERIT IDispatch

   ' =====================================================================================
   METHOD MemberExists <0> ( _                          ' VTable offset = 28
     BYVAL bstrUser AS WSTRING _                        ' __in BSTR bstrUser
   , BYVAL bstrPassword AS WSTRING _                    ' __in BSTR bstrPassword
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvfExists
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPassportClientServices_INTERFACE_DEFINED__ */
