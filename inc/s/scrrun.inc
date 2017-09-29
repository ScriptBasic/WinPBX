' ########################################################################################
' Microsoft Windows
' File: scrrun.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: Scripting
' Version: 1.0
' Documentation string: Microsoft Scripting Runtime
' Path: C:\WINDOWS\system32\scrrun.dll
' Library GUID: {420B2830-E718-11CF-893D-00A0C9054228}
' Help file: C:\WINDOWS\system32\VBENLR98.CHM
' ########################################################################################


' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {EE09B103-97E0-11CF-978F-00A02463E06F}
$PROGID_ScriptingDictionary = "Scripting.Dictionary"
' CLSID = {32DA2B15-CFED-11D1-B747-00C04FC2B085}
$PROGID_ScriptingEncoder = "Scripting.Encoder"
' CLSID = {0D43FE01-F093-11CF-8940-00A0C9054228}
$PROGID_ScriptingFileSystemObject = "Scripting.FileSystemObject"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_Drive = GUID$("{C7C3F5B1-88A3-11D0-ABCB-00A0C90FFFC0}")
$CLSID_Drives = GUID$("{C7C3F5B2-88A3-11D0-ABCB-00A0C90FFFC0}")
$CLSID_File = GUID$("{C7C3F5B5-88A3-11D0-ABCB-00A0C90FFFC0}")
$CLSID_Files = GUID$("{C7C3F5B6-88A3-11D0-ABCB-00A0C90FFFC0}")
$CLSID_Folder = GUID$("{C7C3F5B3-88A3-11D0-ABCB-00A0C90FFFC0}")
$CLSID_Folders = GUID$("{C7C3F5B4-88A3-11D0-ABCB-00A0C90FFFC0}")
$CLSID_TextStream = GUID$("{0BB02EC0-EF49-11CF-8940-00A0C9054228}")
$CLSID_Dictionary = GUID$("{EE09B103-97E0-11CF-978F-00A02463E06F}")
$CLSID_Encoder = GUID$("{32DA2B15-CFED-11D1-B747-00C04FC2B085}")
$CLSID_FileSystemObject = GUID$("{0D43FE01-F093-11CF-8940-00A0C9054228}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IDictionary = GUID$("{42C642C1-97E1-11CF-978F-00A02463E06F}")
$IID_IDrive = GUID$("{C7C3F5A0-88A3-11D0-ABCB-00A0C90FFFC0}")
$IID_IDriveCollection = GUID$("{C7C3F5A1-88A3-11D0-ABCB-00A0C90FFFC0}")
$IID_IFile = GUID$("{C7C3F5A4-88A3-11D0-ABCB-00A0C90FFFC0}")
$IID_IFileCollection = GUID$("{C7C3F5A5-88A3-11D0-ABCB-00A0C90FFFC0}")
$IID_IFileSystem = GUID$("{0AB5A3D0-E5B6-11D0-ABF5-00A0C90FFFC0}")
$IID_IFileSystem3 = GUID$("{2A0B9D10-4B87-11D3-A97A-00104B365C9F}")
$IID_IFolder = GUID$("{C7C3F5A2-88A3-11D0-ABCB-00A0C90FFFC0}")
$IID_IFolderCollection = GUID$("{C7C3F5A3-88A3-11D0-ABCB-00A0C90FFFC0}")
$IID_IScriptEncoder = GUID$("{AADC65F6-CFF1-11D1-B747-00C04FC2B085}")
$IID_ITextStream = GUID$("{53BAD8C1-E718-11CF-893D-00A0C9054228}")

' ========================================================================================
' CompareMethod enum
' ========================================================================================

%CompareMethod_BinaryCompare                            = 0
%CompareMethod_TextCompare                              = 1
%CompareMethod_DatabaseCompare                          = 2

' ========================================================================================
' IOMode enum
' ========================================================================================

%IOMode_ForReading                                      = 1
%IOMode_ForWriting                                      = 2
%IOMode_ForAppending                                    = 8

' ========================================================================================
' Tristate enum
' ========================================================================================

%TristateTrue                                           = -1
%TristateFalse                                          = 0
%TristateUseDefault                                     = -2
%TristateMixed                                          = -2

' ========================================================================================
' FileAttribute enum
' ========================================================================================

%FileAttribute_Normal                                   = 0
%FileAttribute_ReadOnly                                 = 1
%FileAttribute_Hidden                                   = 2
%FileAttribute_System                                   = 4
%FileAttribute_Volume                                   = 8
%FileAttribute_Directory                                = 16
%FileAttribute_Archive                                  = 32
%FileAttribute_Alias                                    = 1024
%FileAttribute_Compressed                               = 2048

' ########################################################################################
' Interface name = IDictionary
' IID = {42C642C1-97E1-11CF-978F-00A02463E06F}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDictionary_INTERFACE_DEFINED)
    %IDictionary_INTERFACE_DEFINED = 1

INTERFACE IDictionary $IID_IDictionary

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET putref_Item <0> ( _                     ' VTable offset = 28
     BYREF IN Key AS VARIANT _                          ' __in VARIANT* Key
   , BYREF IN pRetItem AS VARIANT _                     ' __in VARIANT* pRetItem
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Item <0> ( _                            ' VTable offset = 32
     BYREF IN Key AS VARIANT _                          ' __in VARIANT* Key
   , BYREF IN pRetItem AS VARIANT _                     ' __in VARIANT* pRetItem
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 36
     BYREF IN Key AS VARIANT _                          ' __in VARIANT* Key
   ) AS VARIANT                                         ' __retval_out VARIANT* pRetItem
   ' =====================================================================================
   METHOD Add <1> ( _                                   ' VTable offset = 40
     BYREF Key AS VARIANT _                             ' __in VARIANT* Key
   , BYREF Item AS VARIANT _                            ' __in VARIANT* Item
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Count <2> ( _                           ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long* pCount
   ' =====================================================================================
   METHOD Exists <3> ( _                                ' VTable offset = 48
     BYREF Key AS VARIANT _                             ' __in VARIANT* Key
   ) AS INTEGER                                         ' __retval_out VARIANT* pExists
   ' =====================================================================================
   METHOD Items <4> ( _                                 ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT* pItemsArray
   ' =====================================================================================
   PROPERTY SET Key <5> ( _                             ' VTable offset = 56
     BYREF IN Key AS VARIANT _                          ' __in VARIANT *Key
   , BYREF IN rhs AS VARIANT _                          ' __in VT_VARIANT *rhs
   )                                                    ' void
   ' =====================================================================================
   METHOD Keys <6> ( _                                  ' VTable offset = 60
   ) AS VARIANT                                         ' __retval_out VT_VARIANT* pKeysArray
   ' =====================================================================================
   METHOD Remove <7> ( _                                ' VTable offset = 64
     BYREF Key AS VARIANT _                             ' __in VT_VARIANT* Key
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveAll <8> ( _                             ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET CompareMode <9> ( _                     ' VTable offset = 72
     BYVAL pcomp AS LONG _                              ' __in CompareMethod pcomp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CompareMode <9> ( _                     ' VTable offset = 76
   ) AS LONG                                            ' __retval_out CompareMethod* pcomp
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 80
   ) AS IUnknown                                        ' __retval_out IUnknown** ppunk
   ' =====================================================================================
   PROPERTY GET HashVal <10> ( _                        ' VTable offset = 84
     BYREF IN Key AS VARIANT _                          ' __in VARIANT* Key
   ) AS VARIANT                                         ' __retval_out VARIANT* HashVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDictionary_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFileSystem
' IID = {0AB5A3D0-E5B6-11D0-ABF5-00A0C90FFFC0}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFileSystem_INTERFACE_DEFINED)
    %IFileSystem_INTERFACE_DEFINED = 1

INTERFACE IFileSystem $IID_IFileSystem

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Drives <10010> ( _                      ' VTable offset = 28
   ) AS IDriveCollection                                ' __retval_out IDriveCollection** ppdrives
   ' =====================================================================================
   METHOD BuildPath <10000> ( _                         ' VTable offset = 32
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   , BYVAL Name AS WSTRING _                            ' __in BSTR Name
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrResult
   ' =====================================================================================
   METHOD GetDriveName <10004> ( _                      ' VTable offset = 36
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrResult
   ' =====================================================================================
   METHOD GetParentFolderName <10005> ( _               ' VTable offset = 40
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrResult
   ' =====================================================================================
   METHOD GetFileName <10006> ( _                       ' VTable offset = 44
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrResult
   ' =====================================================================================
   METHOD GetBaseName <10007> ( _                       ' VTable offset = 48
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrResult
   ' =====================================================================================
   METHOD GetExtensionName <10008> ( _                  ' VTable offset = 52
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrResult
   ' =====================================================================================
   METHOD GetAbsolutePathName <10002> ( _               ' VTable offset = 56
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrResult
   ' =====================================================================================
   METHOD GetTempName <10003> ( _                       ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrResult
   ' =====================================================================================
   METHOD DriveExists <10015> ( _                       ' VTable offset = 64
     BYVAL DriveSpec AS WSTRING _                       ' __in BSTR DriveSpec
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfExists
   ' =====================================================================================
   METHOD FileExists <10016> ( _                        ' VTable offset = 68
     BYVAL FileSpec AS WSTRING _                        ' __in BSTR FileSpec
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfExistsVT_BOOL <Integer>
   ' =====================================================================================
   METHOD FolderExists <10017> ( _                      ' VTable offset = 72
     BYVAL FolderSpec AS WSTRING _                      ' __in BSTR FolderSpec
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfExists
   ' =====================================================================================
   METHOD GetDrive <10011> ( _                          ' VTable offset = 76
     BYVAL DriveSpec AS WSTRING _                       ' __in BSTR DriveSpec
   ) AS IDrive                                          ' __retval_out IDrive** ppdrive
   ' =====================================================================================
   METHOD GetFile <10012> ( _                           ' VTable offset = 80
     BYVAL FilePath AS WSTRING _                        ' __in BSTR FilePath
   ) AS IFile                                           ' __retval_out IFile** ppfile
   ' =====================================================================================
   METHOD GetFolder <10013> ( _                         ' VTable offset = 84
     BYVAL FolderPath AS WSTRING _                      ' __in BSTR FolderPath
   ) AS IFolder                                         ' __retval_out IFolder** ppfolder
   ' =====================================================================================
   METHOD GetSpecialFolder <10014> ( _                  ' VTable offset = 88
     BYVAL SpecialFolder AS LONG _                      ' __in SpecialFolderConst SpecialFolder
   ) AS IFolder                                         ' __retval_out IFolder** ppfolder
   ' =====================================================================================
   METHOD DeleteFile <1200> ( _                         ' VTable offset = 92
     BYVAL FileSpec AS WSTRING _                        ' __in BSTR FileSpec
   , OPTIONAL BYVAL Force AS INTEGER _                  ' __opt_in VARIANT_BOOL Force = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteFolder <1201> ( _                       ' VTable offset = 96
     BYVAL FolderSpec AS WSTRING _                      ' __in BSTR FolderSpec
   , OPTIONAL BYVAL Force AS INTEGER _                  ' __in_opt VARIANT_BOOL Force = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveFile <1204> ( _                           ' VTable offset = 100
     BYVAL Source AS WSTRING _                          ' __in BSTR Source
   , BYVAL Destination AS WSTRING _                     ' __in BSTR Destination
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveFolder <1205> ( _                         ' VTable offset = 104
     BYVAL Source AS WSTRING _                          ' __in BSTR Source
   , BYVAL Destination AS WSTRING _                     ' __in BSTR Destination
   )                                                    ' void
   ' =====================================================================================
   METHOD CopyFile <1202> ( _                           ' VTable offset = 108
     BYVAL Source AS WSTRING _                          ' __in BSTR Source
   , BYVAL Destination AS WSTRING _                     ' __in BSTR Destination
   , OPTIONAL BYVAL OverWriteFiles AS INTEGER _         ' __in_opt VARIANT_BOOL OverWriteFiles = -1
   )                                                    ' void
   ' =====================================================================================
   METHOD CopyFolder <1203> ( _                         ' VTable offset = 112
     BYVAL Source AS WSTRING _                          ' __in BSTR Source
   , BYVAL Destination AS WSTRING _                     ' __in BSTR Destination
   , OPTIONAL BYVAL OverWriteFiles AS INTEGER _         ' __in_opt VARIANT_BOOL OverWriteFiles = -1
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateFolder <1120> ( _                       ' VTable offset = 116
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   ) AS IFolder                                         ' __retval_out IFolder** ppfolder
   ' =====================================================================================
   METHOD CreateTextFile <1101> ( _                     ' VTable offset = 120
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   , OPTIONAL BYVAL Overwrite AS INTEGER _              ' __in_opt VARIANT_BOOL Overwrite = -1
   , OPTIONAL BYVAL Unicode AS INTEGER _                ' __in_opt VARIANT_BOOL Unicode = 0
   ) AS ITextStream                                     ' __retval_out ITextStream** ppts
   ' =====================================================================================
   METHOD OpenTextFile <1100> ( _                       ' VTable offset = 124
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   , OPTIONAL BYVAL IOMode AS LONG _                    ' __in_opt IOMode IOMode = 1
   , OPTIONAL BYVAL Create AS INTEGER _                 ' __in_opt VARIANT_BOOL Create = 0
   , OPTIONAL BYVAL Format AS LONG _                    ' __in_opt Tristate Format = 0
   ) AS ITextStream                                     ' __retval_out ITextStream** ppts
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileSystem_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDriveCollection
' IID = {C7C3F5A1-88A3-11D0-ABCB-00A0C90FFFC0}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDriveCollection_INTERFACE_DEFINED)
    %IDriveCollection_INTERFACE_DEFINED = 1

INTERFACE IDriveCollection $IID_IDriveCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Key AS VARIANT _                             ' __in VARIANT Key
   ) AS IDrive                                          ' __retval_out IDrive** ppdrive
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown** ppenum
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long* plCount
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDriveCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDrive
' IID = {C7C3F5A0-88A3-11D0-ABCB-00A0C90FFFC0}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDrive_INTERFACE_DEFINED)
    %IDrive_INTERFACE_DEFINED = 1

INTERFACE IDrive $IID_IDrive

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Path <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrPath
   ' =====================================================================================
   PROPERTY GET DriveLetter <10000> ( _                 ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrLetter
   ' =====================================================================================
   PROPERTY GET ShareName <10001> ( _                   ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrShareName
   ' =====================================================================================
   PROPERTY GET DriveType <10002> ( _                   ' VTable offset = 40
   ) AS LONG                                            ' __retval_out DriveTypeConst* pdt
   ' =====================================================================================
   PROPERTY GET RootFolder <10003> ( _                  ' VTable offset = 44
   ) AS IFolder                                         ' __retval_out IFolder** ppfolder
   ' =====================================================================================
   PROPERTY GET AvailableSpace <10005> ( _              ' VTable offset = 48
   ) AS VARIANT                                         ' __retval_out VARIANT* pvarAvail
   ' =====================================================================================
   PROPERTY GET FreeSpace <10004> ( _                   ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT* pvarFree
   ' =====================================================================================
   PROPERTY GET TotalSize <10006> ( _                   ' VTable offset = 56
   ) AS VARIANT                                         ' __retval_out VARIANT* pvarTotal
   ' =====================================================================================
   PROPERTY GET VolumeName <10007> ( _                  ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrName
   ' =====================================================================================
   PROPERTY SET VolumeName <10007> ( _                  ' VTable offset = 64
     BYVAL pbstrName AS WSTRING _                       ' __in BSTR pbstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileSystem <10008> ( _                  ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrFileSystem
   ' =====================================================================================
   PROPERTY GET SerialNumber <10009> ( _                ' VTable offset = 72
   ) AS LONG                                            ' __retval_out long* pulSerialNumber
   ' =====================================================================================
   PROPERTY GET IsReady <10010> ( _                     ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfReady
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDrive_INTERFACE_DEFINED__ */

' ========================================================================================
' DriveTypeConst enum
' ========================================================================================

%DriveTypeConst_UnknownType                             = 0
%DriveTypeConst_Removable                               = 1
%DriveTypeConst_Fixed                                   = 2
%DriveTypeConst_Remote                                  = 3
%DriveTypeConst_CDRom                                   = 4
%DriveTypeConst_RamDisk                                 = 5

' ########################################################################################
' Interface name = IFolder
' IID = {C7C3F5A2-88A3-11D0-ABCB-00A0C90FFFC0}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFolder_INTERFACE_DEFINED)
    %IFolder_INTERFACE_DEFINED = 1

INTERFACE IFolder $IID_IFolder

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Path <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrPath
   ' =====================================================================================
   PROPERTY GET Name <1000> ( _                         ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrName
   ' =====================================================================================
   PROPERTY SET Name <1000> ( _                         ' VTable offset = 36
     BYVAL pbstrName AS WSTRING _                       ' __in BSTR pbstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShortPath <1002> ( _                    ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrPath
   ' =====================================================================================
   PROPERTY GET ShortName <1001> ( _                    ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrName
   ' =====================================================================================
   PROPERTY GET Drive <1004> ( _                        ' VTable offset = 48
   ) AS IDrive                                          ' __retval_out IDrive** ppdrive
   ' =====================================================================================
   PROPERTY GET ParentFolder <1005> ( _                 ' VTable offset = 52
   ) AS IFolder                                         ' __retval_out IFolder** ppfolder
   ' =====================================================================================
   PROPERTY GET Attributes <1003> ( _                   ' VTable offset = 56
   ) AS LONG                                            ' __retval_out FileAttribute* pfa
   ' =====================================================================================
   PROPERTY SET Attributes <1003> ( _                   ' VTable offset = 60
     BYVAL pfa AS LONG _                                ' __in FileAttribute pfa
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DateCreated <1006> ( _                  ' VTable offset = 64
   ) AS DOUBLE                                          ' __retval_out DATE* pdate
   ' =====================================================================================
   PROPERTY GET DateLastModified <1007> ( _             ' VTable offset = 68
   ) AS DOUBLE                                          ' __retval_out DATE* pdate
   ' =====================================================================================
   PROPERTY GET DateLastAccessed <1008> ( _             ' VTable offset = 72
   ) AS DOUBLE                                          ' __retval_out DATE* pdate
   ' =====================================================================================
   PROPERTY GET Type <1010> ( _                         ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrType
   ' =====================================================================================
   METHOD Delete <1201> ( _                             ' VTable offset = 80
     OPTIONAL BYVAL Force AS INTEGER _                  ' __in_opt VARIANT_BOOL Force = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD Copy <1203> ( _                               ' VTable offset = 84
     BYVAL Destination AS WSTRING _                     ' __in BSTR Destination
   , OPTIONAL BYVAL OverWriteFiles AS INTEGER _         ' __in_opt VARIANT_BOOL OverWriteFiles = -1
   )                                                    ' void
   ' =====================================================================================
   METHOD Move <1205> ( _                               ' VTable offset = 88
     BYVAL Destination AS WSTRING _                     ' __in BSTR Destination
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsRootFolder <10000> ( _                ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfRootFolder
   ' =====================================================================================
   PROPERTY GET Size <1009> ( _                         ' VTable offset = 96
   ) AS VARIANT                                         ' __retval_out VARIANT* pvarSize
   ' =====================================================================================
   PROPERTY GET SubFolders <10001> ( _                  ' VTable offset = 100
   ) AS IFolderCollection                               ' __retval_out IFolderCollection** ppfolders
   ' =====================================================================================
   PROPERTY GET Files <10002> ( _                       ' VTable offset = 104
   ) AS IFileCollection                                 ' __retval_out IFileCollection** ppfiles
   ' =====================================================================================
   METHOD CreateTextFile <1101> ( _                     ' VTable offset = 108
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   , OPTIONAL BYVAL Overwrite AS INTEGER _              ' __in_opt VARIANT_BOOL Overwrite = -1
   , OPTIONAL BYVAL Unicode AS INTEGER _                ' __in_opt VARIANT_BOOL Unicode = 0
   ) AS ITextStream                                     ' __retval_out ITextStream** ppts
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFolder_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFolderCollection
' IID = {C7C3F5A3-88A3-11D0-ABCB-00A0C90FFFC0}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFolderCollection_INTERFACE_DEFINED)
    %IFolderCollection_INTERFACE_DEFINED = 1

INTERFACE IFolderCollection $IID_IFolderCollection

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 28
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   ) AS IFolder                                         ' __retval_out IFolder** ppfolder
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL Key AS VARIANT _                             ' __in VARIANT Key
   ) AS IFolder                                         ' __retval_out IFolder** ppfolder
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** ppenum
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long* plCount
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFolderCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFileCollection
' IID = {C7C3F5A5-88A3-11D0-ABCB-00A0C90FFFC0}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFileCollection_INTERFACE_DEFINED)
    %IFileCollection_INTERFACE_DEFINED = 1

INTERFACE IFileCollection $IID_IFileCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Key AS VARIANT _                             ' __in VARIANT Key
   ) AS IFile                                           ' __retval_out IFile** ppfile
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown** ppenum
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long* plCount
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFile
' IID = {C7C3F5A4-88A3-11D0-ABCB-00A0C90FFFC0}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFile_INTERFACE_DEFINED)
    %IFile_INTERFACE_DEFINED = 1

INTERFACE IFile $IID_IFile

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Path <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrPath
   ' =====================================================================================
   PROPERTY GET Name <1000> ( _                         ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrName
   ' =====================================================================================
   PROPERTY SET Name <1000> ( _                         ' VTable offset = 36
     BYVAL pbstrName AS WSTRING _                       ' __in BSTR pbstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShortPath <1002> ( _                    ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrPath
   ' =====================================================================================
   PROPERTY GET ShortName <1001> ( _                    ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrName
   ' =====================================================================================
   PROPERTY GET Drive <1004> ( _                        ' VTable offset = 48
   ) AS IDrive                                          ' __retval_out IDrive** ppdrive
   ' =====================================================================================
   PROPERTY GET ParentFolder <1005> ( _                 ' VTable offset = 52
   ) AS IFolder                                         ' __retval_out IFolder** ppfolder
   ' =====================================================================================
   PROPERTY GET Attributes <1003> ( _                   ' VTable offset = 56
   ) AS LONG                                            ' __retval_out FileAttribute* pfa
   ' =====================================================================================
   PROPERTY SET Attributes <1003> ( _                   ' VTable offset = 60
     BYVAL pfa AS LONG _                                ' __in FileAttribute pfa
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DateCreated <1006> ( _                  ' VTable offset = 64
   ) AS DOUBLE                                          ' __retval_out DATE* pdate
   ' =====================================================================================
   PROPERTY GET DateLastModified <1007> ( _             ' VTable offset = 68
   ) AS DOUBLE                                          ' __retval_out DATE* pdate
   ' =====================================================================================
   PROPERTY GET DateLastAccessed <1008> ( _             ' VTable offset = 72
   ) AS DOUBLE                                          ' __retval_out DATE* pdate
   ' =====================================================================================
   PROPERTY GET Size <1009> ( _                         ' VTable offset = 76
   ) AS VARIANT                                         ' __retval_out VARIANT* pvarSize
   ' =====================================================================================
   PROPERTY GET Type <1010> ( _                         ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrType
   ' =====================================================================================
   METHOD Delete <1200> ( _                             ' VTable offset = 84
     OPTIONAL BYVAL Force AS INTEGER _                  ' __in_opt VARIANT_BOOL Force = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD Copy <1202> ( _                               ' VTable offset = 88
     BYVAL Destination AS WSTRING _                     ' __in BSTR Destination
   , OPTIONAL BYVAL OverWriteFiles AS INTEGER _         ' __in_opt VARIANT_BOOL OverWriteFiles = -1
   )                                                    ' void
   ' =====================================================================================
   METHOD Move <1204> ( _                               ' VTable offset = 92
     BYVAL Destination AS WSTRING _                     ' __in BSTR Destination
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenAsTextStream <1100> ( _                   ' VTable offset = 96
     OPTIONAL BYVAL IOMode AS LONG _                    ' __in_opt IOMode IOMode = 1
   , OPTIONAL BYVAL Format AS LONG _                    ' __in_opt Tristate Format = 0
   ) AS ITextStream                                     ' __retval_out ITextStream** ppts
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFile_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITextStream
' IID = {53BAD8C1-E718-11CF-893D-00A0C9054228}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITextStream_INTERFACE_DEFINED)
    %ITextStream_INTERFACE_DEFINED = 1

INTERFACE ITextStream $IID_ITextStream

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Line <10000> ( _                        ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* Line
   ' =====================================================================================
   PROPERTY GET Column <-529> ( _                       ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* Column
   ' =====================================================================================
   PROPERTY GET AtEndOfStream <10002> ( _               ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* EOS
   ' =====================================================================================
   PROPERTY GET AtEndOfLine <10003> ( _                 ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* EOL
   ' =====================================================================================
   METHOD Read <10004> ( _                              ' VTable offset = 44
     BYVAL Characters AS LONG _                         ' __in long Characters
   ) AS WSTRING                                         ' __retval_out BSTR* Text
   ' =====================================================================================
   METHOD ReadLine <10005> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR* Text
   ' =====================================================================================
   METHOD ReadAll <10006> ( _                           ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* Text
   ' =====================================================================================
   METHOD Write <10007> ( _                             ' VTable offset = 56
     BYVAL Text AS WSTRING _                            ' __in BSTR Text
   )                                                    ' void
   ' =====================================================================================
   METHOD WriteLine <10008> ( _                         ' VTable offset = 60
     OPTIONAL BYVAL Text AS WSTRING _                   ' __in_opt BSTR Text = L""
   )                                                    ' void
   ' =====================================================================================
   METHOD WriteBlankLines <10009> ( _                   ' VTable offset = 64
     BYVAL Lines AS LONG _                              ' __in long Lines
   )                                                    ' void
   ' =====================================================================================
   METHOD Skip <10010> ( _                              ' VTable offset = 68
     BYVAL Characters AS LONG _                         ' __in long Characters
   )                                                    ' void
   ' =====================================================================================
   METHOD SkipLine <10011> ( _                          ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================
   METHOD Close <10012> ( _                             ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITextStream_INTERFACE_DEFINED__ */

' ========================================================================================
' SpecialFolderConst enum
' ========================================================================================

%SpecialFolder_WindowsFolder                            = 0
%SpecialFolder_SystemFolder                             = 1
%SpecialFolder_TemporaryFolder                          = 2

' ########################################################################################
' Interface name = IFileSystem3
' IID = {2A0B9D10-4B87-11D3-A97A-00104B365C9F}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IFileSystem
' ########################################################################################

#IF NOT %DEF(%IFileSystem3_INTERFACE_DEFINED)
    %IFileSystem3_INTERFACE_DEFINED = 1

INTERFACE IFileSystem3 $IID_IFileSystem3

   INHERIT IDispatch

   ' =====================================================================================
   ' IFileSystem Methods
   ' =====================================================================================
   PROPERTY GET Drives <10010> ( _                      ' VTable offset = 28
   ) AS IDriveCollection                                ' __retval_out IDriveCollection** ppdrives
   ' =====================================================================================
   METHOD BuildPath <10000> ( _                         ' VTable offset = 32
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   , BYVAL Name AS WSTRING _                            ' __in BSTR Name
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrResult
   ' =====================================================================================
   METHOD GetDriveName <10004> ( _                      ' VTable offset = 36
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrResult
   ' =====================================================================================
   METHOD GetParentFolderName <10005> ( _               ' VTable offset = 40
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrResult
   ' =====================================================================================
   METHOD GetFileName <10006> ( _                       ' VTable offset = 44
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrResult
   ' =====================================================================================
   METHOD GetBaseName <10007> ( _                       ' VTable offset = 48
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrResult
   ' =====================================================================================
   METHOD GetExtensionName <10008> ( _                  ' VTable offset = 52
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrResult
   ' =====================================================================================
   METHOD GetAbsolutePathName <10002> ( _               ' VTable offset = 56
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrResult
   ' =====================================================================================
   METHOD GetTempName <10003> ( _                       ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrResult
   ' =====================================================================================
   METHOD DriveExists <10015> ( _                       ' VTable offset = 64
     BYVAL DriveSpec AS WSTRING _                       ' __in BSTR DriveSpec
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfExists
   ' =====================================================================================
   METHOD FileExists <10016> ( _                        ' VTable offset = 68
     BYVAL FileSpec AS WSTRING _                        ' __in BSTR FileSpec
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfExistsVT_BOOL <Integer>
   ' =====================================================================================
   METHOD FolderExists <10017> ( _                      ' VTable offset = 72
     BYVAL FolderSpec AS WSTRING _                      ' __in BSTR FolderSpec
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfExists
   ' =====================================================================================
   METHOD GetDrive <10011> ( _                          ' VTable offset = 76
     BYVAL DriveSpec AS WSTRING _                       ' __in BSTR DriveSpec
   ) AS IDrive                                          ' __retval_out IDrive** ppdrive
   ' =====================================================================================
   METHOD GetFile <10012> ( _                           ' VTable offset = 80
     BYVAL FilePath AS WSTRING _                        ' __in BSTR FilePath
   ) AS IFile                                           ' __retval_out IFile** ppfile
   ' =====================================================================================
   METHOD GetFolder <10013> ( _                         ' VTable offset = 84
     BYVAL FolderPath AS WSTRING _                      ' __in BSTR FolderPath
   ) AS IFolder                                         ' __retval_out IFolder** ppfolder
   ' =====================================================================================
   METHOD GetSpecialFolder <10014> ( _                  ' VTable offset = 88
     BYVAL SpecialFolder AS LONG _                      ' __in SpecialFolderConst SpecialFolder
   ) AS IFolder                                         ' __retval_out IFolder** ppfolder
   ' =====================================================================================
   METHOD DeleteFile <1200> ( _                         ' VTable offset = 92
     BYVAL FileSpec AS WSTRING _                        ' __in BSTR FileSpec
   , OPTIONAL BYVAL Force AS INTEGER _                  ' __opt_in VARIANT_BOOL Force = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteFolder <1201> ( _                       ' VTable offset = 96
     BYVAL FolderSpec AS WSTRING _                      ' __in BSTR FolderSpec
   , OPTIONAL BYVAL Force AS INTEGER _                  ' __in_opt VARIANT_BOOL Force = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveFile <1204> ( _                           ' VTable offset = 100
     BYVAL Source AS WSTRING _                          ' __in BSTR Source
   , BYVAL Destination AS WSTRING _                     ' __in BSTR Destination
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveFolder <1205> ( _                         ' VTable offset = 104
     BYVAL Source AS WSTRING _                          ' __in BSTR Source
   , BYVAL Destination AS WSTRING _                     ' __in BSTR Destination
   )                                                    ' void
   ' =====================================================================================
   METHOD CopyFile <1202> ( _                           ' VTable offset = 108
     BYVAL Source AS WSTRING _                          ' __in BSTR Source
   , BYVAL Destination AS WSTRING _                     ' __in BSTR Destination
   , OPTIONAL BYVAL OverWriteFiles AS INTEGER _         ' __in_opt VARIANT_BOOL OverWriteFiles = -1
   )                                                    ' void
   ' =====================================================================================
   METHOD CopyFolder <1203> ( _                         ' VTable offset = 112
     BYVAL Source AS WSTRING _                          ' __in BSTR Source
   , BYVAL Destination AS WSTRING _                     ' __in BSTR Destination
   , OPTIONAL BYVAL OverWriteFiles AS INTEGER _         ' __in_opt VARIANT_BOOL OverWriteFiles = -1
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateFolder <1120> ( _                       ' VTable offset = 116
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   ) AS IFolder                                         ' __retval_out IFolder** ppfolder
   ' =====================================================================================
   METHOD CreateTextFile <1101> ( _                     ' VTable offset = 120
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   , OPTIONAL BYVAL Overwrite AS INTEGER _              ' __in_opt VARIANT_BOOL Overwrite = -1
   , OPTIONAL BYVAL Unicode AS INTEGER _                ' __in_opt VARIANT_BOOL Unicode = 0
   ) AS ITextStream                                     ' __retval_out ITextStream** ppts
   ' =====================================================================================
   METHOD OpenTextFile <1100> ( _                       ' VTable offset = 124
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   , OPTIONAL BYVAL IOMode AS LONG _                    ' __in_opt IOMode IOMode = 1
   , OPTIONAL BYVAL Create AS INTEGER _                 ' __in_opt VARIANT_BOOL Create = 0
   , OPTIONAL BYVAL Format AS LONG _                    ' __in_opt Tristate Format = 0
   ) AS ITextStream                                     ' __retval_out ITextStream** ppts
   ' =====================================================================================

   ' =====================================================================================
   ' IFileSystem3 Methods
   ' =====================================================================================
   METHOD GetStandardStream <20000> ( _                 ' VTable offset = 128
     BYVAL StandardStreamType AS LONG _                 ' __in StandardStreamTypes StandardStreamType
   , OPTIONAL BYVAL Unicode AS INTEGER _                ' __in_opt VARIANT_BOOL Unicode = 0
   ) AS ITextStream                                     ' __retval_out ITextStream** ppts
   ' =====================================================================================
   METHOD GetFileVersion <20010> ( _                    ' VTable offset = 132
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   ) AS WSTRING                                         ' __retval_out BSTR* FileVersion
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileSystem3_INTERFACE_DEFINED__ */

' ========================================================================================
' StandardStreamTypes enum
' ========================================================================================

%StreamType_StdIn                                       = 0
%StreamType_StdOut                                      = 1
%StreamType_StdErr                                      = 2

' ########################################################################################
' Interface name = IScriptEncoder
' IID = {AADC65F6-CFF1-11D1-B747-00C04FC2B085}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IScriptEncoder_INTERFACE_DEFINED)
    %IScriptEncoder_INTERFACE_DEFINED = 1

INTERFACE IScriptEncoder $IID_IScriptEncoder

   INHERIT IDispatch

   ' =====================================================================================
   METHOD EncodeScriptFile <0> ( _                      ' VTable offset = 28
     BYVAL szExt AS WSTRING _                           ' __in BSTR szExt
   , BYVAL bstrStreamIn AS WSTRING _                    ' __in BSTR bstrStreamIn
   , BYVAL cFlags AS LONG _                             ' __in long cFlags
   , BYVAL bstrDefaultLang AS WSTRING _                 ' __in BSTR bstrDefaultLang
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrStreamOut
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IScriptEncoder_INTERFACE_DEFINED__ */
