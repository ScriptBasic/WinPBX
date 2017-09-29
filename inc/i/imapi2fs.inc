' ########################################################################################
' Microsoft Windows
' File: imapi2fs.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: IMAPI2FS
' Version: 1.0, Locale ID = 0
' Description: Microsoft IMAPI2 File System Image Creator
' Path: C:\Windows\system32\imapi2fs.dll
' Library GUID: {2C941FD0-975B-59BE-A960-9A2A262853A5}
' Help file: C:\Windows\Help\IMAPIv2.chm
' ########################################################################################

#INCLUDE THIS ONCE
%IMAPI2FS_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "imapi2.inc"

'//
'// IMAPIv2 FileSystemImaging version information for TYPELib loading
'//
%IMAPI2FS_MajorVersion         = 1
$IMAPI2FS_MajorVersion_STR     = "1"
$$IMAPI2FS_MajorVersion_WSTR   = "1"$$
%IMAPI2FS_MinorVersion         = 0
$IMAPI2FS_MinorVersion_STR     = "0"
$$IMAPI2FS_MinorVersion_WSTR   = "0"$$
$IMAPI2FS_FullVersion_STR      = "1.0"
$$IMAPI2FS_FullVersion_WSTR    = "1.0"$$

$LIBID_IMAPI2FS = GUID$("{2C941FD0-975B-59BE-A960-9A2A262853A5}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {2C941FCE-975B-59BE-A960-9A2A262853A5}
$PROGID_BootOptions1 = "IMAPI2FS.BootOptions.1"
' CLSID = {2C941FC5-975B-59BE-A960-9A2A262853A5}
$PROGID_MsftFileSystemImage1 = "IMAPI2FS.MsftFileSystemImage.1"
' CLSID = {CEEE3B62-8F56-4056-869B-EF16917E3EFC}
$PROGID_MsftIsoImageManager1 = "IMAPI2FS.MsftIsoImageManager.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {2C941FCE-975B-59BE-A960-9A2A262853A5}
$PROGID_BootOptions = "IMAPI2FS.BootOptions"
' CLSID = {2C941FC5-975B-59BE-A960-9A2A262853A5}
$PROGID_MsftFileSystemImage = "IMAPI2FS.MsftFileSystemImage"
' CLSID = {CEEE3B62-8F56-4056-869B-EF16917E3EFC}
$PROGID_MsftIsoImageManager = "IMAPI2FS.MsftIsoImageManager"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_EnumFsiItems = GUID$("{2C941FC6-975B-59BE-A960-9A2A262853A5}")
$CLSID_EnumProgressItems = GUID$("{2C941FCA-975B-59BE-A960-9A2A262853A5}")
$CLSID_FileSystemImageResult = GUID$("{2C941FCC-975B-59BE-A960-9A2A262853A5}")
$CLSID_FsiDirectoryItem = GUID$("{2C941FC8-975B-59BE-A960-9A2A262853A5}")
$CLSID_FsiFileItem = GUID$("{2C941FC7-975B-59BE-A960-9A2A262853A5}")
$CLSID_FsiNamedStreams = GUID$("{C6B6F8ED-6D19-44B4-B539-B159B793A32D}")
$CLSID_FsiStream = GUID$("{2C941FCD-975B-59BE-A960-9A2A262853A5}")
$CLSID_ProgressItem = GUID$("{2C941FCB-975B-59BE-A960-9A2A262853A5}")
$CLSID_ProgressItems = GUID$("{2C941FC9-975B-59BE-A960-9A2A262853A5}")
$CLSID_BootOptions = GUID$("{2C941FCE-975B-59BE-A960-9A2A262853A5}")
$CLSID_MsftFileSystemImage = GUID$("{2C941FC5-975B-59BE-A960-9A2A262853A5}")
$CLSID_MsftIsoImageManager = GUID$("{CEEE3B62-8F56-4056-869B-EF16917E3EFC}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_DFileSystemImageEvents = GUID$("{2C941FDF-975B-59BE-A960-9A2A262853A5}")
$IID_DFileSystemImageImportEvents = GUID$("{D25C30F9-4087-4366-9E24-E55BE286424B}")
$IID_IBootOptions = GUID$("{2C941FD4-975B-59BE-A960-9A2A262853A5}")
$IID_IEnumFsiItems = GUID$("{2C941FDA-975B-59BE-A960-9A2A262853A5}")
$IID_IEnumProgressItems = GUID$("{2C941FD6-975B-59BE-A960-9A2A262853A5}")
$IID_IFileSystemImage = GUID$("{2C941FE1-975B-59BE-A960-9A2A262853A5}")
$IID_IFileSystemImage2 = GUID$("{D7644B2C-1537-4767-B62F-F1387B02DDFD}")
$IID_IFileSystemImage3 = GUID$("{7CFF842C-7E97-4807-8304-910DD8F7C051}")
$IID_IFileSystemImageResult = GUID$("{2C941FD8-975B-59BE-A960-9A2A262853A5}")
$IID_IFileSystemImageResult2 = GUID$("{B507CA29-2204-11DD-966A-001AA01BBC58}")
$IID_IFsiDirectoryItem = GUID$("{2C941FDC-975B-59BE-A960-9A2A262853A5}")
$IID_IFsiDirectoryItem2 = GUID$("{F7FB4B9B-6D96-4D7B-9115-201B144811EF}")
$IID_IFsiFileItem = GUID$("{2C941FDB-975B-59BE-A960-9A2A262853A5}")
$IID_IFsiFileItem2 = GUID$("{199D0C19-11E1-40EB-8EC2-C8C822A07792}")
$IID_IFsiItem = GUID$("{2C941FD9-975B-59BE-A960-9A2A262853A5}")
$IID_IFsiNamedStreams = GUID$("{ED79BA56-5294-4250-8D46-F9AECEE23459}")
$IID_IIsoImageManager = GUID$("{6CA38BE5-FBBB-4800-95A1-A438865EB0D4}")
$IID_IProgressItem = GUID$("{2C941FD5-975B-59BE-A960-9A2A262853A5}")
$IID_IProgressItems = GUID$("{2C941FD7-975B-59BE-A960-9A2A262853A5}")

%IMAPI2FS_BOOT_ENTRY_COUNT_MAX = 32

' ========================================================================================
' FsiItemType enum
' File system item type
' ========================================================================================

%FsiItemNotFound                                        = 0
%FsiItemDirectory                                       = 1
%FsiItemFile                                            = 2

' ========================================================================================
' FsiFileSystems enum
' Type of file system
' ========================================================================================

%FsiFileSystemNone                                      = 0
%FsiFileSystemISO9660                                   = 1
%FsiFileSystemJoliet                                    = 2
%FsiFileSystemUDF                                       = 4
%FsiFileSystemUnknown                                   = &H40000000

' ========================================================================================
' EmulationType enum
' Boot emulation type
' ========================================================================================

%EmulationNone                                          = 0
%Emulation12MFloppy                                     = 1
%Emulation144MFloppy                                    = 2
%Emulation288MFloppy                                    = 3
%EmulationHardDisk                                      = 4

' ========================================================================================
' PlatformId enum
' Boot platform type
' ========================================================================================

%PlatformX86                                            = 0
%PlatformPowerPC                                        = 1
%PlatformMac                                            = 2
%PlatformEFI                                            = &Hef

' ########################################################################################
' Interface name = IBootOptions
' IID = {2C941FD4-975B-59BE-A960-9A2A262853A5}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IBootOptions_INTERFACE_DEFINED)
    %IBootOptions_INTERFACE_DEFINED = 1

INTERFACE IBootOptions $IID_IBootOptions

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET BootImage <1> ( _                       ' VTable offset = 28
   ) AS IStream                                         ' __retval_out IStream **pVal
   ' =====================================================================================
   PROPERTY GET Manufacturer <2> ( _                    ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET Manufacturer <2> ( _                    ' VTable offset = 36
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PlatformId <3> ( _                      ' VTable offset = 40
   ) AS LONG                                            ' __retval_out PlatformId *pVal
   ' =====================================================================================
   PROPERTY SET PlatformId <3> ( _                      ' VTable offset = 44
     BYVAL newVal AS LONG _                             ' __in PlatformId newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Emulation <4> ( _                       ' VTable offset = 48
   ) AS LONG                                            ' __retval_out EmulationType *pVal
   ' =====================================================================================
   PROPERTY SET Emulation <4> ( _                       ' VTable offset = 52
     BYVAL newVal AS LONG _                             ' __in EmulationType newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ImageSize <5> ( _                       ' VTable offset = 56
   ) AS DWORD                                           ' __retval_out ULONG *pVal
   ' =====================================================================================
   METHOD AssignBootImage <20> ( _                      ' VTable offset = 60
     BYVAL newVal AS IStream _                          ' __in IStream *newVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBootOptions_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IProgressItem
' IID = {2C941FD5-975B-59BE-A960-9A2A262853A5}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IProgressItem_INTERFACE_DEFINED)
    %IProgressItem_INTERFACE_DEFINED = 1

INTERFACE IProgressItem $IID_IProgressItem

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Description <1> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *desc
   ' =====================================================================================
   PROPERTY GET FirstBlock <2> ( _                      ' VTable offset = 32
   ) AS DWORD                                           ' __retval_out ULONG *block
   ' =====================================================================================
   PROPERTY GET LastBlock <3> ( _                       ' VTable offset = 36
   ) AS DWORD                                           ' __retval_out ULONG *block
   ' =====================================================================================
   PROPERTY GET BlockCount <4> ( _                      ' VTable offset = 40
   ) AS DWORD                                           ' __retval_out ULONG *blocks
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProgressItem_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumProgressItems
' IID = {2C941FD6-975B-59BE-A960-9A2A262853A5}
' FileSystemImageResult progress item enumerator
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumProgressItems_INTERFACE_DEFINED)
    %IEnumProgressItems_INTERFACE_DEFINED = 1

INTERFACE IEnumProgressItems $IID_IEnumProgressItems

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS IProgressItem _                     ' __out IProgressItem **rgelt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
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
     BYREF ppEnum AS IEnumProgressItems _               ' __out IEnumProgressItems **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumProgressItems_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IProgressItems
' IID = {2C941FD7-975B-59BE-A960-9A2A262853A5}
' Progress item block mapping collection
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IProgressItems_INTERFACE_DEFINED)
    %IProgressItems_INTERFACE_DEFINED = 1

INTERFACE IProgressItems $IID_IProgressItems

   INHERIT IDispatch

   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 28
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **NewEnum
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS IProgressItem                                   ' __retval_out IProgressItem **item
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out *Count /* *VT_I4 <Long> */
   ' =====================================================================================
   METHOD ProgressItemFromBlock <2> ( _                 ' VTable offset = 40
     BYVAL block AS DWORD _                             ' __in ULONG block
   ) AS IProgressItem                                   ' __retval_out IProgressItem **item
   ' =====================================================================================
   METHOD ProgressItemFromDescription <3> ( _           ' VTable offset = 44
     BYVAL description AS WSTRING _                     ' __in BSTR description
   ) AS IProgressItem                                   ' __retval_out IProgressItem **item
   ' =====================================================================================
   PROPERTY GET EnumProgressItems <4> ( _               ' VTable offset = 48
   ) AS IEnumProgressItems                              ' __retval_out IEnumProgressItems **NewEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProgressItems_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFileSystemImageResult
' IID = {2C941FD8-975B-59BE-A960-9A2A262853A5}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFileSystemImageResult_INTERFACE_DEFINED)
    %IFileSystemImageResult_INTERFACE_DEFINED = 1

INTERFACE IFileSystemImageResult $IID_IFileSystemImageResult

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ImageStream <1> ( _                     ' VTable offset = 28
   ) AS IStream                                         ' __retval_out IStream **pVal
   ' =====================================================================================
   PROPERTY GET ProgressItems <2> ( _                   ' VTable offset = 32
   ) AS IProgressItems                                  ' __retval_out IProgressItems **pVal
   ' =====================================================================================
   PROPERTY GET TotalBlocks <3> ( _                     ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET BlockSize <4> ( _                       ' VTable offset = 40
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET DiscId <5> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileSystemImageResult_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFileSystemImageResult2
' IID = {B507CA29-2204-11DD-966A-001AA01BBC58}
' FileSystemImage result stream (rev.2)
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IFileSystemImageResult
' ########################################################################################

#IF NOT %DEF(%IFileSystemImageResult2_INTERFACE_DEFINED)
    %IFileSystemImageResult2_INTERFACE_DEFINED = 1

INTERFACE IFileSystemImageResult2 $IID_IFileSystemImageResult2

   INHERIT IDispatch

   ' =====================================================================================
   ' IFileSystemImageResult Methods
   ' =====================================================================================
   PROPERTY GET ImageStream <1> ( _                     ' VTable offset = 28
   ) AS IStream                                         ' __retval_out IStream **pVal
   ' =====================================================================================
   PROPERTY GET ProgressItems <2> ( _                   ' VTable offset = 32
   ) AS IProgressItems                                  ' __retval_out IProgressItems **pVal
   ' =====================================================================================
   PROPERTY GET TotalBlocks <3> ( _                     ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET BlockSize <4> ( _                       ' VTable offset = 40
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET DiscId <5> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================

   ' =====================================================================================
   ' IFileSystemImageResult2 Methods
   ' =====================================================================================
   PROPERTY GET ModifiedBlocks <6> ( _                  ' VTable offset = 48
   ) AS IBlockRangeList                                 ' __retval_out IBlockRangeList **pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileSystemImageResult2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFsiItem
' IID = {2C941FD9-975B-59BE-A960-9A2A262853A5}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFsiItem_INTERFACE_DEFINED)
    %IFsiItem_INTERFACE_DEFINED = 1

INTERFACE IFsiItem $IID_IFsiItem

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <11> ( _                           ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET FullPath <12> ( _                       ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET CreationTime <13> ( _                   ' VTable offset = 36
   ) AS DOUBLE                                          ' __retval_out DATE *pVal
   ' =====================================================================================
   PROPERTY SET CreationTime <13> ( _                   ' VTable offset = 40
     BYVAL newVal AS DOUBLE _                           ' __in DATE newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LastAccessedTime <14> ( _               ' VTable offset = 44
   ) AS DOUBLE                                          ' __retval_out DATE *pVal
   ' =====================================================================================
   PROPERTY SET LastAccessedTime <14> ( _               ' VTable offset = 48
     BYVAL newVal AS DOUBLE _                           ' __in DATE newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LastModifiedTime <15> ( _               ' VTable offset = 52
   ) AS DOUBLE                                          ' __retval_out DATE *pVal
   ' =====================================================================================
   PROPERTY SET LastModifiedTime <15> ( _               ' VTable offset = 56
     BYVAL newVal AS DOUBLE _                           ' __in DATE newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsHidden <16> ( _                       ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET IsHidden <16> ( _                       ' VTable offset = 64
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   METHOD FileSystemName <17> ( _                       ' VTable offset = 68
     BYVAL fileSystem AS LONG _                         ' __in FsiFileSystems fileSystem
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD FileSystemPath <18> ( _                       ' VTable offset = 72
     BYVAL fileSystem AS LONG _                         ' __in FsiFileSystems fileSystem
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFsiItem_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumFsiItems
' IID = {2C941FDA-975B-59BE-A960-9A2A262853A5}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumFsiItems_INTERFACE_DEFINED)
    %IEnumFsiItems_INTERFACE_DEFINED = 1

INTERFACE IEnumFsiItems $IID_IEnumFsiItems

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS IFsiItem _                          ' __out IFsiItem **rgelt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
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
     BYREF ppEnum AS IEnumFsiItems _                    ' __out IEnumFsiItems **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumFsiItems_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFsiFileItem
' IID = {2C941FDB-975B-59BE-A960-9A2A262853A5}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IFsiItem
' ########################################################################################

#IF NOT %DEF(%IFsiFileItem_INTERFACE_DEFINED)
    %IFsiFileItem_INTERFACE_DEFINED = 1

INTERFACE IFsiFileItem $IID_IFsiFileItem

   INHERIT IDispatch

   ' =====================================================================================
   ' IFsiItem Methods
   ' =====================================================================================
   PROPERTY GET Name <11> ( _                           ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET FullPath <12> ( _                       ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET CreationTime <13> ( _                   ' VTable offset = 36
   ) AS DOUBLE                                          ' __retval_out DATE *pVal
   ' =====================================================================================
   PROPERTY SET CreationTime <13> ( _                   ' VTable offset = 40
     BYVAL newVal AS DOUBLE _                           ' __in DATE newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LastAccessedTime <14> ( _               ' VTable offset = 44
   ) AS DOUBLE                                          ' __retval_out DATE *pVal
   ' =====================================================================================
   PROPERTY SET LastAccessedTime <14> ( _               ' VTable offset = 48
     BYVAL newVal AS DOUBLE _                           ' __in DATE newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LastModifiedTime <15> ( _               ' VTable offset = 52
   ) AS DOUBLE                                          ' __retval_out DATE *pVal
   ' =====================================================================================
   PROPERTY SET LastModifiedTime <15> ( _               ' VTable offset = 56
     BYVAL newVal AS DOUBLE _                           ' __in DATE newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsHidden <16> ( _                       ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET IsHidden <16> ( _                       ' VTable offset = 64
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   METHOD FileSystemName <17> ( _                       ' VTable offset = 68
     BYVAL fileSystem AS LONG _                         ' __in FsiFileSystems fileSystem
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD FileSystemPath <18> ( _                       ' VTable offset = 72
     BYVAL fileSystem AS LONG _                         ' __in FsiFileSystems fileSystem
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================

   ' =====================================================================================
   ' IFsiFileItem Methods
   ' =====================================================================================
   PROPERTY GET DataSize <41> ( _                       ' VTable offset = 76
   ) AS QUAD                                            ' __retval_out LONGLONG *pVal
   ' =====================================================================================
   PROPERTY GET DataSize32BitLow <42> ( _               ' VTable offset = 80
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET DataSize32BitHigh <43> ( _              ' VTable offset = 84
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET Data <44> ( _                           ' VTable offset = 88
   ) AS IStream                                         ' __retval_out IStream **pVal
   ' =====================================================================================
   PROPERTY SET Data <44> ( _                           ' VTable offset = 92
     BYVAL newVal AS IStream _                          ' __in IStream *newVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFsiFileItem_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFsiFileItem2
' IID = {199D0C19-11E1-40EB-8EC2-C8C822A07792}
' FileSystemImage file item (rev.2)
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IFsiFileItem
' ########################################################################################

#IF NOT %DEF(%IFsiFileItem2_INTERFACE_DEFINED)
    %IFsiFileItem2_INTERFACE_DEFINED = 1

INTERFACE IFsiFileItem2 $IID_IFsiFileItem2

   INHERIT IDispatch

   ' =====================================================================================
   ' IFsiItem Methods
   ' =====================================================================================
   PROPERTY GET Name <11> ( _                           ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET FullPath <12> ( _                       ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET CreationTime <13> ( _                   ' VTable offset = 36
   ) AS DOUBLE                                          ' __retval_out DATE *pVal
   ' =====================================================================================
   PROPERTY SET CreationTime <13> ( _                   ' VTable offset = 40
     BYVAL newVal AS DOUBLE _                           ' __in DATE newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LastAccessedTime <14> ( _               ' VTable offset = 44
   ) AS DOUBLE                                          ' __retval_out DATE *pVal
   ' =====================================================================================
   PROPERTY SET LastAccessedTime <14> ( _               ' VTable offset = 48
     BYVAL newVal AS DOUBLE _                           ' __in DATE newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LastModifiedTime <15> ( _               ' VTable offset = 52
   ) AS DOUBLE                                          ' __retval_out DATE *pVal
   ' =====================================================================================
   PROPERTY SET LastModifiedTime <15> ( _               ' VTable offset = 56
     BYVAL newVal AS DOUBLE _                           ' __in DATE newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsHidden <16> ( _                       ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET IsHidden <16> ( _                       ' VTable offset = 64
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   METHOD FileSystemName <17> ( _                       ' VTable offset = 68
     BYVAL fileSystem AS LONG _                         ' __in FsiFileSystems fileSystem
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD FileSystemPath <18> ( _                       ' VTable offset = 72
     BYVAL fileSystem AS LONG _                         ' __in FsiFileSystems fileSystem
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================

   ' =====================================================================================
   ' IFsiFileItem Methods
   ' =====================================================================================
   PROPERTY GET DataSize <41> ( _                       ' VTable offset = 76
   ) AS QUAD                                            ' __retval_out LONGLONG *pVal
   ' =====================================================================================
   PROPERTY GET DataSize32BitLow <42> ( _               ' VTable offset = 80
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET DataSize32BitHigh <43> ( _              ' VTable offset = 84
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET Data <44> ( _                           ' VTable offset = 88
   ) AS IStream                                         ' __retval_out IStream **pVal
   ' =====================================================================================
   PROPERTY SET Data <44> ( _                           ' VTable offset = 92
     BYVAL newVal AS IStream _                          ' __in IStream *newVal
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IFsiFileItem2 Methods
   ' =====================================================================================
   PROPERTY GET FsiNamedStreams <45> ( _                ' VTable offset = 96
   ) AS IFsiNamedStreams                                ' __retval_out IFsiNamedStreams **streams
   ' =====================================================================================
   PROPERTY GET IsNamedStream <46> ( _                  ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   METHOD AddStream <47> ( _                            ' VTable offset = 104
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYVAL streamData AS IStream _                      ' __in IStream *streamData
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveStream <48> ( _                         ' VTable offset = 108
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsRealTime <49> ( _                     ' VTable offset = 112
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET IsRealTime <49> ( _                     ' VTable offset = 116
     BYVAL pVal AS INTEGER _                            ' __in VARIANT_BOOL pVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFsiFileItem2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFsiNamedStreams
' IID = {ED79BA56-5294-4250-8D46-F9AECEE23459}
' Named stream collection
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFsiNamedStreams_INTERFACE_DEFINED)
    %IFsiNamedStreams_INTERFACE_DEFINED = 1

INTERFACE IFsiNamedStreams $IID_IFsiNamedStreams

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **NewEnum
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS IFsiFileItem2                                   ' __retval_out IFsiFileItem2 **Item
   ' =====================================================================================
   PROPERTY GET Count <81> ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *Count
   ' =====================================================================================
   PROPERTY GET EnumNamedStreams <82> ( _               ' VTable offset = 40
   ) AS IEnumFsiItems                                   ' __retval_out IEnumFsiItems **NewEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFsiNamedStreams_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFsiDirectoryItem
' IID = {2C941FDC-975B-59BE-A960-9A2A262853A5}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IFsiItem
' ########################################################################################

#IF NOT %DEF(%IFsiDirectoryItem_INTERFACE_DEFINED)
    %IFsiDirectoryItem_INTERFACE_DEFINED = 1

INTERFACE IFsiDirectoryItem $IID_IFsiDirectoryItem

   INHERIT IDispatch

   ' =====================================================================================
   ' IFsiItem Methods
   ' =====================================================================================
   PROPERTY GET Name <11> ( _                           ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET FullPath <12> ( _                       ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET CreationTime <13> ( _                   ' VTable offset = 36
   ) AS DOUBLE                                          ' __retval_out DATE *pVal
   ' =====================================================================================
   PROPERTY SET CreationTime <13> ( _                   ' VTable offset = 40
     BYVAL newVal AS DOUBLE _                           ' __in DATE newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LastAccessedTime <14> ( _               ' VTable offset = 44
   ) AS DOUBLE                                          ' __retval_out DATE *pVal
   ' =====================================================================================
   PROPERTY SET LastAccessedTime <14> ( _               ' VTable offset = 48
     BYVAL newVal AS DOUBLE _                           ' __in DATE newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LastModifiedTime <15> ( _               ' VTable offset = 52
   ) AS DOUBLE                                          ' __retval_out DATE *pVal
   ' =====================================================================================
   PROPERTY SET LastModifiedTime <15> ( _               ' VTable offset = 56
     BYVAL newVal AS DOUBLE _                           ' __in DATE newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsHidden <16> ( _                       ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET IsHidden <16> ( _                       ' VTable offset = 64
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   METHOD FileSystemName <17> ( _                       ' VTable offset = 68
     BYVAL fileSystem AS LONG _                         ' __in FsiFileSystems fileSystem
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD FileSystemPath <18> ( _                       ' VTable offset = 72
     BYVAL fileSystem AS LONG _                         ' __in FsiFileSystems fileSystem
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================

   ' =====================================================================================
   ' IFsiDirectoryItem Methods
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 76
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **NewEnum
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 80
     BYVAL path AS WSTRING _                            ' __in BSTR path
   ) AS IFsiItem                                        ' __retval_out IFsiItem **item
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 84
   ) AS LONG                                            ' __retval_out LONG *Count
   ' =====================================================================================
   PROPERTY GET EnumFsiItems <2> ( _                    ' VTable offset = 88
   ) AS IEnumFsiItems                                   ' __retval_out IEnumFsiItems **NewEnum
   ' =====================================================================================
   METHOD AddDirectory <30> ( _                         ' VTable offset = 92
     BYVAL path AS WSTRING _                            ' __in BSTR path
   )                                                    ' void
   ' =====================================================================================
   METHOD AddFile <31> ( _                              ' VTable offset = 96
     BYVAL path AS WSTRING _                            ' __in BSTR path
   , BYVAL fileData AS IStream _                        ' __in IStream *fileData
   )                                                    ' void
   ' =====================================================================================
   METHOD AddTree <32> ( _                              ' VTable offset = 100
     BYVAL sourceDirectory AS WSTRING _                 ' __in BSTR sourceDirectory
   , BYVAL includeBaseDirectory AS INTEGER _            ' __in VARIANT_BOOL includeBaseDirectory
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <33> ( _                                  ' VTable offset = 104
     BYVAL IFsiItem _                                   ' __in IFsiItem *item
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <34> ( _                               ' VTable offset = 108
     BYVAL path AS WSTRING _                            ' __in BSTR path
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveTree <35> ( _                           ' VTable offset = 112
     BYVAL path AS WSTRING _                            ' __in BSTR path
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFsiDirectoryItem_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFsiDirectoryItem2
' IID = {F7FB4B9B-6D96-4D7B-9115-201B144811EF}
' FileSystemImage directory item (rev.2)
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IFsiDirectoryItem
' ########################################################################################

#IF NOT %DEF(%IFsiDirectoryItem2_INTERFACE_DEFINED)
    %IFsiDirectoryItem2_INTERFACE_DEFINED = 1

INTERFACE IFsiDirectoryItem2 $IID_IFsiDirectoryItem2

   INHERIT IDispatch

   ' =====================================================================================
   ' IFsiItem Methods
   ' =====================================================================================
   PROPERTY GET Name <11> ( _                           ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET FullPath <12> ( _                       ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET CreationTime <13> ( _                   ' VTable offset = 36
   ) AS DOUBLE                                          ' __retval_out DATE *pVal
   ' =====================================================================================
   PROPERTY SET CreationTime <13> ( _                   ' VTable offset = 40
     BYVAL newVal AS DOUBLE _                           ' __in DATE newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LastAccessedTime <14> ( _               ' VTable offset = 44
   ) AS DOUBLE                                          ' __retval_out DATE *pVal
   ' =====================================================================================
   PROPERTY SET LastAccessedTime <14> ( _               ' VTable offset = 48
     BYVAL newVal AS DOUBLE _                           ' __in DATE newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LastModifiedTime <15> ( _               ' VTable offset = 52
   ) AS DOUBLE                                          ' __retval_out DATE *pVal
   ' =====================================================================================
   PROPERTY SET LastModifiedTime <15> ( _               ' VTable offset = 56
     BYVAL newVal AS DOUBLE _                           ' __in DATE newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsHidden <16> ( _                       ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET IsHidden <16> ( _                       ' VTable offset = 64
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   METHOD FileSystemName <17> ( _                       ' VTable offset = 68
     BYVAL fileSystem AS LONG _                         ' __in FsiFileSystems fileSystem
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD FileSystemPath <18> ( _                       ' VTable offset = 72
     BYVAL fileSystem AS LONG _                         ' __in FsiFileSystems fileSystem
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================

   ' =====================================================================================
   ' IFsiDirectoryItem Methods
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 76
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **NewEnum
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 80
     BYVAL path AS WSTRING _                            ' __in BSTR path
   ) AS IFsiItem                                        ' __retval_out IFsiItem **item
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 84
   ) AS LONG                                            ' __retval_out LONG *Count
   ' =====================================================================================
   PROPERTY GET EnumFsiItems <2> ( _                    ' VTable offset = 88
   ) AS IEnumFsiItems                                   ' __retval_out IEnumFsiItems **NewEnum
   ' =====================================================================================
   METHOD AddDirectory <30> ( _                         ' VTable offset = 92
     BYVAL path AS WSTRING _                            ' __in BSTR path
   )                                                    ' void
   ' =====================================================================================
   METHOD AddFile <31> ( _                              ' VTable offset = 96
     BYVAL path AS WSTRING _                            ' __in BSTR path
   , BYVAL fileData AS IStream _                        ' __in IStream *fileData
   )                                                    ' void
   ' =====================================================================================
   METHOD AddTree <32> ( _                              ' VTable offset = 100
     BYVAL sourceDirectory AS WSTRING _                 ' __in BSTR sourceDirectory
   , BYVAL includeBaseDirectory AS INTEGER _            ' __in VARIANT_BOOL includeBaseDirectory
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <33> ( _                                  ' VTable offset = 104
     BYVAL IFsiItem _                                   ' __in IFsiItem *item
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <34> ( _                               ' VTable offset = 108
     BYVAL path AS WSTRING _                            ' __in BSTR path
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveTree <35> ( _                           ' VTable offset = 112
     BYVAL path AS WSTRING _                            ' __in BSTR path
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IFsiDirectoryItem2 Methods
   ' =====================================================================================
   METHOD AddTreeWithNamedStreams <36> ( _              ' VTable offset = 116
     BYVAL sourceDirectory AS WSTRING _                 ' __in BSTR sourceDirectory
   , BYVAL includeBaseDirectory AS INTEGER _            ' __in VARIANT_BOOL includeBaseDirectory
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFsiDirectoryItem2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFileSystemImage
' IID = {2C941FE1-975B-59BE-A960-9A2A262853A5}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFileSystemImage_INTERFACE_DEFINED)
    %IFileSystemImage_INTERFACE_DEFINED = 1

INTERFACE IFileSystemImage $IID_IFileSystemImage

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Root <0> ( _                            ' VTable offset = 28
   ) AS IFsiDirectoryItem                               ' __retval_out IFsiDirectoryItem **pVal
   ' =====================================================================================
   PROPERTY GET SessionStartBlock <1> ( _               ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY SET SessionStartBlock <1> ( _               ' VTable offset = 36
     BYVAL newVal AS LONG _                             ' __in LONG newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FreeMediaBlocks <2> ( _                 ' VTable offset = 40
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY SET FreeMediaBlocks <2> ( _                 ' VTable offset = 44
     BYVAL newVal AS LONG _                             ' __in LONG newVal
   )                                                    ' void
   ' =====================================================================================
   METHOD SetMaxMediaBlocksFromDevice <36> ( _          ' VTable offset = 48
     BYVAL discRecorder AS IDiscRecorder2 _             ' __in IDiscRecorder2 *discRecorder
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UsedBlocks <3> ( _                      ' VTable offset = 52
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET VolumeName <4> ( _                      ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET VolumeName <4> ( _                      ' VTable offset = 60
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ImportedVolumeName <5> ( _              ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET BootImageOptions <6> ( _                ' VTable offset = 68
   ) AS IBootOptions                                    ' __retval_out IBootOptions **pVal
   ' =====================================================================================
   PROPERTY SET BootImageOptions <6> ( _                ' VTable offset = 72
     BYVAL newVal AS IBootOptions _                     ' __in IBootOptions *newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileCount <7> ( _                       ' VTable offset = 76
   ) AS LONG                                            ' __retval_out LONG *pVal)
   ' =====================================================================================
   PROPERTY GET DirectoryCount <8> ( _                  ' VTable offset = 80
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET WorkingDirectory <9> ( _                ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET WorkingDirectory <9> ( _                ' VTable offset = 88
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ChangePoint <10> ( _                    ' VTable offset = 92
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET StrictFileSystemCompliance <11> ( _     ' VTable offset = 96
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET StrictFileSystemCompliance <11> ( _     ' VTable offset = 100
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UseRestrictedCharacterSet <12> ( _      ' VTable offset = 104
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET UseRestrictedCharacterSet <12> ( _      ' VTable offset = 108
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileSystemsToCreate <13> ( _            ' VTable offset = 112
   ) AS LONG                                            ' __retval_out FsiFileSystems *pVal
   ' =====================================================================================
   PROPERTY SET FileSystemsToCreate <13> ( _            ' VTable offset = 116
     BYVAL newVal AS LONG _                             ' __in FsiFileSystems newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileSystemsSupported <14> ( _           ' VTable offset = 120
   ) AS LONG                                            ' __retval_out FsiFileSystems *pVal
   ' =====================================================================================
   PROPERTY SET UDFRevision <37> ( _                    ' VTable offset = 124
     BYVAL newVal AS LONG _                             ' __in LONG newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UDFRevision <37> ( _                    ' VTable offset = 128
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET UDFRevisionsSupported <31> ( _          ' VTable offset = 132
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pVal
   ' =====================================================================================
   METHOD ChooseImageDefaults <32> ( _                  ' VTable offset = 136
     BYVAL discRecorder AS IDiscRecorder2 _             ' __in IDiscRecorder2 *discRecorder
   )                                                    ' void
   ' =====================================================================================
   METHOD ChooseImageDefaultsForMediaType <33> ( _      ' VTable offset = 140
     BYVAL value AS LONG _                              ' __in IMAPI_MEDIA_PHYSICAL_TYPE value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ISO9660InterchangeLevel <34> ( _        ' VTable offset = 144
     BYVAL newVal AS LONG _                             ' __in LONG newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ISO9660InterchangeLevel <34> ( _        ' VTable offset = 148
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET ISO9660InterchangeLevelsSupported <38> ( _ ' VTable offset = 152
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pVal
   ' =====================================================================================
   METHOD CreateResultImage <15> ( _                    ' VTable offset = 156
   ) AS IFileSystemImageResult                          ' __retval_out IFileSystemImageResult **resultStream
   ' =====================================================================================
   METHOD Exists <16> ( _                               ' VTable offset = 160
     BYVAL fullPath AS WSTRING _                        ' __in BSTR fullPath
   ) AS LONG                                            ' __retval_out FsiItemType *itemType
   ' =====================================================================================
   METHOD CalculateDiscIdentifier <18> ( _              ' VTable offset = 164
   ) AS WSTRING                                         ' __retval_out BSTR *discIdentifier
   ' =====================================================================================
   METHOD IdentifyFileSystemsOnDisc <19> ( _            ' VTable offset = 168
     BYVAL discRecorder AS IDispatch _                  ' __in IDiscRecorder2 *discRecorder
   ) AS LONG                                            ' __retval_out FsiFileSystems *fileSystems
   ' =====================================================================================
   METHOD GetDefaultFileSystemForImport <20> ( _        ' VTable offset = 172
     BYVAL fileSystems AS LONG _                        ' __in FsiFileSystems fileSystems
   ) AS LONG                                            ' __retval_out FsiFileSystems *importDefault
   ' =====================================================================================
   METHOD ImportFileSystem <21> ( _                     ' VTable offset = 176
   ) AS LONG                                            ' __retval_out FsiFileSystems *importedFileSystem
   ' =====================================================================================
   METHOD ImportSpecificFileSystem <22> ( _             ' VTable offset = 180
     BYVAL fileSystemToUse AS LONG _                    ' __in FsiFileSystems fileSystemToUse
   )                                                    ' void
   ' =====================================================================================
   METHOD RollbackToChangePoint <23> ( _                ' VTable offset = 184
     BYVAL changePoint AS LONG _                        ' __in LONG changePoint
   )                                                    ' void
   ' =====================================================================================
   METHOD LockInChangePoint <24> ( _                    ' VTable offset = 188
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateDirectoryItem <25> ( _                  ' VTable offset = 192
     BYVAL name AS WSTRING _                            ' __in BSTR name
   ) AS IFsiDirectoryItem                               ' __retval_out IFsiDirectoryItem **newItem
   ' =====================================================================================
   METHOD CreateFileItem <26> ( _                       ' VTable offset = 196
     BYVAL name AS WSTRING _                            ' __in BSTR name
   ) AS IFsiFileItem                                    ' __retval_out IFsiFileItem **newItem
   ' =====================================================================================
   PROPERTY GET VolumeNameUDF <27> ( _                  ' VTable offset = 200
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET VolumeNameJoliet <28> ( _               ' VTable offset = 204
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET VolumeNameISO9660 <29> ( _              ' VTable offset = 208
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET StageFiles <30> ( _                     ' VTable offset = 212
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET StageFiles <30> ( _                     ' VTable offset = 216
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MultisessionInterfaces <40> ( _         ' VTable offset = 220
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pVal
   ' =====================================================================================
   PROPERTY SET MultisessionInterfaces <40> ( _         ' VTable offset = 224
     BYVAL newVal AS DWORD _                            ' __in SAFEARRAY * newVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileSystemImage_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFileSystemImage2
' IID = {D7644B2C-1537-4767-B62F-F1387B02DDFD}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IFileSystemImage
' ########################################################################################

#IF NOT %DEF(%IFileSystemImage2_INTERFACE_DEFINED)
    %IFileSystemImage2_INTERFACE_DEFINED = 1

INTERFACE IFileSystemImage2 $IID_IFileSystemImage2

   INHERIT IDispatch

   ' =====================================================================================
   ' IFileSystemImage Methods
   ' =====================================================================================
   PROPERTY GET Root <0> ( _                            ' VTable offset = 28
   ) AS IFsiDirectoryItem                               ' __retval_out IFsiDirectoryItem **pVal
   ' =====================================================================================
   PROPERTY GET SessionStartBlock <1> ( _               ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY SET SessionStartBlock <1> ( _               ' VTable offset = 36
     BYVAL newVal AS LONG _                             ' __in LONG newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FreeMediaBlocks <2> ( _                 ' VTable offset = 40
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY SET FreeMediaBlocks <2> ( _                 ' VTable offset = 44
     BYVAL newVal AS LONG _                             ' __in LONG newVal
   )                                                    ' void
   ' =====================================================================================
   METHOD SetMaxMediaBlocksFromDevice <36> ( _          ' VTable offset = 48
     BYVAL discRecorder AS IDiscRecorder2 _             ' __in IDiscRecorder2 *discRecorder
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UsedBlocks <3> ( _                      ' VTable offset = 52
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET VolumeName <4> ( _                      ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET VolumeName <4> ( _                      ' VTable offset = 60
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ImportedVolumeName <5> ( _              ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET BootImageOptions <6> ( _                ' VTable offset = 68
   ) AS IBootOptions                                    ' __retval_out IBootOptions **pVal
   ' =====================================================================================
   PROPERTY SET BootImageOptions <6> ( _                ' VTable offset = 72
     BYVAL newVal AS IBootOptions _                     ' __in IBootOptions *newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileCount <7> ( _                       ' VTable offset = 76
   ) AS LONG                                            ' __retval_out LONG *pVal)
   ' =====================================================================================
   PROPERTY GET DirectoryCount <8> ( _                  ' VTable offset = 80
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET WorkingDirectory <9> ( _                ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET WorkingDirectory <9> ( _                ' VTable offset = 88
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ChangePoint <10> ( _                    ' VTable offset = 92
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET StrictFileSystemCompliance <11> ( _     ' VTable offset = 96
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET StrictFileSystemCompliance <11> ( _     ' VTable offset = 100
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UseRestrictedCharacterSet <12> ( _      ' VTable offset = 104
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET UseRestrictedCharacterSet <12> ( _      ' VTable offset = 108
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileSystemsToCreate <13> ( _            ' VTable offset = 112
   ) AS LONG                                            ' __retval_out FsiFileSystems *pVal
   ' =====================================================================================
   PROPERTY SET FileSystemsToCreate <13> ( _            ' VTable offset = 116
     BYVAL newVal AS LONG _                             ' __in FsiFileSystems newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileSystemsSupported <14> ( _           ' VTable offset = 120
   ) AS LONG                                            ' __retval_out FsiFileSystems *pVal
   ' =====================================================================================
   PROPERTY SET UDFRevision <37> ( _                    ' VTable offset = 124
     BYVAL newVal AS LONG _                             ' __in LONG newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UDFRevision <37> ( _                    ' VTable offset = 128
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET UDFRevisionsSupported <31> ( _          ' VTable offset = 132
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pVal
   ' =====================================================================================
   METHOD ChooseImageDefaults <32> ( _                  ' VTable offset = 136
     BYVAL discRecorder AS IDiscRecorder2 _             ' __in IDiscRecorder2 *discRecorder
   )                                                    ' void
   ' =====================================================================================
   METHOD ChooseImageDefaultsForMediaType <33> ( _      ' VTable offset = 140
     BYVAL value AS LONG _                              ' __in IMAPI_MEDIA_PHYSICAL_TYPE value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ISO9660InterchangeLevel <34> ( _        ' VTable offset = 144
     BYVAL newVal AS LONG _                             ' __in LONG newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ISO9660InterchangeLevel <34> ( _        ' VTable offset = 148
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET ISO9660InterchangeLevelsSupported <38> ( _ ' VTable offset = 152
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pVal
   ' =====================================================================================
   METHOD CreateResultImage <15> ( _                    ' VTable offset = 156
   ) AS IFileSystemImageResult                          ' __retval_out IFileSystemImageResult **resultStream
   ' =====================================================================================
   METHOD Exists <16> ( _                               ' VTable offset = 160
     BYVAL fullPath AS WSTRING _                        ' __in BSTR fullPath
   ) AS LONG                                            ' __retval_out FsiItemType *itemType
   ' =====================================================================================
   METHOD CalculateDiscIdentifier <18> ( _              ' VTable offset = 164
   ) AS WSTRING                                         ' __retval_out BSTR *discIdentifier
   ' =====================================================================================
   METHOD IdentifyFileSystemsOnDisc <19> ( _            ' VTable offset = 168
     BYVAL discRecorder AS IDispatch _                  ' __in IDiscRecorder2 *discRecorder
   ) AS LONG                                            ' __retval_out FsiFileSystems *fileSystems
   ' =====================================================================================
   METHOD GetDefaultFileSystemForImport <20> ( _        ' VTable offset = 172
     BYVAL fileSystems AS LONG _                        ' __in FsiFileSystems fileSystems
   ) AS LONG                                            ' __retval_out FsiFileSystems *importDefault
   ' =====================================================================================
   METHOD ImportFileSystem <21> ( _                     ' VTable offset = 176
   ) AS LONG                                            ' __retval_out FsiFileSystems *importedFileSystem
   ' =====================================================================================
   METHOD ImportSpecificFileSystem <22> ( _             ' VTable offset = 180
     BYVAL fileSystemToUse AS LONG _                    ' __in FsiFileSystems fileSystemToUse
   )                                                    ' void
   ' =====================================================================================
   METHOD RollbackToChangePoint <23> ( _                ' VTable offset = 184
     BYVAL changePoint AS LONG _                        ' __in LONG changePoint
   )                                                    ' void
   ' =====================================================================================
   METHOD LockInChangePoint <24> ( _                    ' VTable offset = 188
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateDirectoryItem <25> ( _                  ' VTable offset = 192
     BYVAL name AS WSTRING _                            ' __in BSTR name
   ) AS IFsiDirectoryItem                               ' __retval_out IFsiDirectoryItem **newItem
   ' =====================================================================================
   METHOD CreateFileItem <26> ( _                       ' VTable offset = 196
     BYVAL name AS WSTRING _                            ' __in BSTR name
   ) AS IFsiFileItem                                    ' __retval_out IFsiFileItem **newItem
   ' =====================================================================================
   PROPERTY GET VolumeNameUDF <27> ( _                  ' VTable offset = 200
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET VolumeNameJoliet <28> ( _               ' VTable offset = 204
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET VolumeNameISO9660 <29> ( _              ' VTable offset = 208
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET StageFiles <30> ( _                     ' VTable offset = 212
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET StageFiles <30> ( _                     ' VTable offset = 216
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MultisessionInterfaces <40> ( _         ' VTable offset = 220
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pVal
   ' =====================================================================================
   PROPERTY SET MultisessionInterfaces <40> ( _         ' VTable offset = 224
     BYVAL newVal AS DWORD _                            ' __in SAFEARRAY * newVal
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IFileSystemImage2 Methods
   ' =====================================================================================
   PROPERTY GET BootImageOptionsArray ( _               ' VTable offset = 228
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pVal
   ' =====================================================================================
   PROPERTY SET BootImageOptionsArray <40> ( _          ' VTable offset = 232
     BYVAL newVal AS DWORD _                            ' __in SAFEARRAY * newVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileSystemImage2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFileSystemImage3
' IID = {7CFF842C-7E97-4807-8304-910DD8F7C051}
' File system image (rev.3)
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IFileSystemImage2
' ########################################################################################

#IF NOT %DEF(%IFileSystemImage3_INTERFACE_DEFINED)
    %IFileSystemImage3_INTERFACE_DEFINED = 1

INTERFACE IFileSystemImage3 $IID_IFileSystemImage3

   INHERIT IDispatch

   ' =====================================================================================
   ' IFileSystemImage Methods
   ' =====================================================================================
   PROPERTY GET Root <0> ( _                            ' VTable offset = 28
   ) AS IFsiDirectoryItem                               ' __retval_out IFsiDirectoryItem **pVal
   ' =====================================================================================
   PROPERTY GET SessionStartBlock <1> ( _               ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY SET SessionStartBlock <1> ( _               ' VTable offset = 36
     BYVAL newVal AS LONG _                             ' __in LONG newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FreeMediaBlocks <2> ( _                 ' VTable offset = 40
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY SET FreeMediaBlocks <2> ( _                 ' VTable offset = 44
     BYVAL newVal AS LONG _                             ' __in LONG newVal
   )                                                    ' void
   ' =====================================================================================
   METHOD SetMaxMediaBlocksFromDevice <36> ( _          ' VTable offset = 48
     BYVAL discRecorder AS IDiscRecorder2 _             ' __in IDiscRecorder2 *discRecorder
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UsedBlocks <3> ( _                      ' VTable offset = 52
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET VolumeName <4> ( _                      ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET VolumeName <4> ( _                      ' VTable offset = 60
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ImportedVolumeName <5> ( _              ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET BootImageOptions <6> ( _                ' VTable offset = 68
   ) AS IBootOptions                                    ' __retval_out IBootOptions **pVal
   ' =====================================================================================
   PROPERTY SET BootImageOptions <6> ( _                ' VTable offset = 72
     BYVAL newVal AS IBootOptions _                     ' __in IBootOptions *newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileCount <7> ( _                       ' VTable offset = 76
   ) AS LONG                                            ' __retval_out LONG *pVal)
   ' =====================================================================================
   PROPERTY GET DirectoryCount <8> ( _                  ' VTable offset = 80
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET WorkingDirectory <9> ( _                ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET WorkingDirectory <9> ( _                ' VTable offset = 88
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ChangePoint <10> ( _                    ' VTable offset = 92
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET StrictFileSystemCompliance <11> ( _     ' VTable offset = 96
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET StrictFileSystemCompliance <11> ( _     ' VTable offset = 100
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UseRestrictedCharacterSet <12> ( _      ' VTable offset = 104
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET UseRestrictedCharacterSet <12> ( _      ' VTable offset = 108
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileSystemsToCreate <13> ( _            ' VTable offset = 112
   ) AS LONG                                            ' __retval_out FsiFileSystems *pVal
   ' =====================================================================================
   PROPERTY SET FileSystemsToCreate <13> ( _            ' VTable offset = 116
     BYVAL newVal AS LONG _                             ' __in FsiFileSystems newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileSystemsSupported <14> ( _           ' VTable offset = 120
   ) AS LONG                                            ' __retval_out FsiFileSystems *pVal
   ' =====================================================================================
   PROPERTY SET UDFRevision <37> ( _                    ' VTable offset = 124
     BYVAL newVal AS LONG _                             ' __in LONG newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UDFRevision <37> ( _                    ' VTable offset = 128
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET UDFRevisionsSupported <31> ( _          ' VTable offset = 132
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pVal
   ' =====================================================================================
   METHOD ChooseImageDefaults <32> ( _                  ' VTable offset = 136
     BYVAL discRecorder AS IDiscRecorder2 _             ' __in IDiscRecorder2 *discRecorder
   )                                                    ' void
   ' =====================================================================================
   METHOD ChooseImageDefaultsForMediaType <33> ( _      ' VTable offset = 140
     BYVAL value AS LONG _                              ' __in IMAPI_MEDIA_PHYSICAL_TYPE value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ISO9660InterchangeLevel <34> ( _        ' VTable offset = 144
     BYVAL newVal AS LONG _                             ' __in LONG newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ISO9660InterchangeLevel <34> ( _        ' VTable offset = 148
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET ISO9660InterchangeLevelsSupported <38> ( _ ' VTable offset = 152
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pVal
   ' =====================================================================================
   METHOD CreateResultImage <15> ( _                    ' VTable offset = 156
   ) AS IFileSystemImageResult                          ' __retval_out IFileSystemImageResult **resultStream
   ' =====================================================================================
   METHOD Exists <16> ( _                               ' VTable offset = 160
     BYVAL fullPath AS WSTRING _                        ' __in BSTR fullPath
   ) AS LONG                                            ' __retval_out FsiItemType *itemType
   ' =====================================================================================
   METHOD CalculateDiscIdentifier <18> ( _              ' VTable offset = 164
   ) AS WSTRING                                         ' __retval_out BSTR *discIdentifier
   ' =====================================================================================
   METHOD IdentifyFileSystemsOnDisc <19> ( _            ' VTable offset = 168
     BYVAL discRecorder AS IDispatch _                  ' __in IDiscRecorder2 *discRecorder
   ) AS LONG                                            ' __retval_out FsiFileSystems *fileSystems
   ' =====================================================================================
   METHOD GetDefaultFileSystemForImport <20> ( _        ' VTable offset = 172
     BYVAL fileSystems AS LONG _                        ' __in FsiFileSystems fileSystems
   ) AS LONG                                            ' __retval_out FsiFileSystems *importDefault
   ' =====================================================================================
   METHOD ImportFileSystem <21> ( _                     ' VTable offset = 176
   ) AS LONG                                            ' __retval_out FsiFileSystems *importedFileSystem
   ' =====================================================================================
   METHOD ImportSpecificFileSystem <22> ( _             ' VTable offset = 180
     BYVAL fileSystemToUse AS LONG _                    ' __in FsiFileSystems fileSystemToUse
   )                                                    ' void
   ' =====================================================================================
   METHOD RollbackToChangePoint <23> ( _                ' VTable offset = 184
     BYVAL changePoint AS LONG _                        ' __in LONG changePoint
   )                                                    ' void
   ' =====================================================================================
   METHOD LockInChangePoint <24> ( _                    ' VTable offset = 188
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateDirectoryItem <25> ( _                  ' VTable offset = 192
     BYVAL name AS WSTRING _                            ' __in BSTR name
   ) AS IFsiDirectoryItem                               ' __retval_out IFsiDirectoryItem **newItem
   ' =====================================================================================
   METHOD CreateFileItem <26> ( _                       ' VTable offset = 196
     BYVAL name AS WSTRING _                            ' __in BSTR name
   ) AS IFsiFileItem                                    ' __retval_out IFsiFileItem **newItem
   ' =====================================================================================
   PROPERTY GET VolumeNameUDF <27> ( _                  ' VTable offset = 200
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET VolumeNameJoliet <28> ( _               ' VTable offset = 204
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET VolumeNameISO9660 <29> ( _              ' VTable offset = 208
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET StageFiles <30> ( _                     ' VTable offset = 212
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET StageFiles <30> ( _                     ' VTable offset = 216
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MultisessionInterfaces <40> ( _         ' VTable offset = 220
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pVal
   ' =====================================================================================
   PROPERTY SET MultisessionInterfaces <40> ( _         ' VTable offset = 224
     BYVAL newVal AS DWORD _                            ' __in SAFEARRAY * newVal
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IFileSystemImage2 Methods
   ' =====================================================================================
   PROPERTY GET BootImageOptionsArray ( _               ' VTable offset = 228
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pVal
   ' =====================================================================================
   PROPERTY SET BootImageOptionsArray <40> ( _          ' VTable offset = 232
     BYVAL newVal AS DWORD _                            ' __in SAFEARRAY * newVal
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IFileSystemImage3 Methods
   ' =====================================================================================
   PROPERTY GET CreateRedundantUdfMetadataFiles <61> ( _  ' VTable offset = 236
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET CreateRedundantUdfMetadataFiles <61> ( _  ' VTable offset = 240
     BYVAL pVal AS INTEGER _                            ' __in VARIANT_BOOL pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD ProbeSpecificFileSystem <70> ( _              ' VTable offset = 244
     BYVAL fileSystemToProbe AS LONG _                  ' __in FsiFileSystems fileSystemToProbe
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *isAppendable
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileSystemImage3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IIsoImageManager
' IID = {6CA38BE5-FBBB-4800-95A1-A438865EB0D4}
' ISO Image Manager: Helper object for ISO image file manipulation
' Attributes = 4096 [&H1000] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IIsoImageManager_INTERFACE_DEFINED)
    %IIsoImageManager_INTERFACE_DEFINED = 1

INTERFACE IIsoImageManager $IID_IIsoImageManager

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET path <256> ( _                          ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET Stream <257> ( _                        ' VTable offset = 32
   ) AS IStream                                         ' __retval_out IStream **Data
   ' =====================================================================================
   METHOD SetPath <512> ( _                             ' VTable offset = 36
     BYVAL Val AS WSTRING _                             ' __in BSTR Val
   )                                                    ' void
   ' =====================================================================================
   METHOD SetStream <513> ( _                           ' VTable offset = 40
     BYVAL Data AS IStream _                            ' __in IStream *Data
   )                                                    ' void
   ' =====================================================================================
   METHOD Validate <514> ( _                            ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIsoImageManager_INTERFACE_DEFINED__ */


' ########################################################################################
' Class CDFileSystemImageEvents
' Interface name = DFileSystemImageEvents
' IID = {2C941FDF-975B-59BE-A960-9A2A262853A5}
' Provides notification of file system creation progress
' Attributes = 4480 [&H1180] [Nonextensible] [Oleautomation] [Dispatchable]
' ########################################################################################

'%DISPID_DFILESYSTEMIMAGEEVENTS_UPDATE = &H100

'CLASS CDFileSystemImageEvents GUID$("{45AA1E82-6EC2-49A1-ACD6-2ABDF23CDDE8}") AS EVENT

'INTERFACE DFileSystemImageEventsImpl GUID$("{2C941FDF-975B-59BE-A960-9A2A262853A5}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD Update <256> ( _
'     BYVAL pobject AS IDispatch _                       ' __in IDispatch *object
'   , BYVAL currentFile AS WSTRING _                     ' __in BSTR currentFile
'   , BYVAL copiedSectors AS LONG _                      ' __in LONG copiedSectors
'   , BYVAL totalSectors AS LONG _                       ' __in LONG totalSectors
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS

' ########################################################################################
' Class CDFileSystemImageImportEvents
' Interface name = DFileSystemImageImportEvents
' IID = {D25C30F9-4087-4366-9E24-E55BE286424B}
' Provides notification of file system import progress
' Attributes = 4480 [&H1180] [Nonextensible] [Oleautomation] [Dispatchable]
' ########################################################################################

'%DISPID_DFILESYSTEMIMAGEIMPORTEVENTS_UPDATEIMPORT = &H101

'CLASS CDFileSystemImageImportEvents GUID$("{08C6428C-4362-405A-8F4D-EFBB06412A35}") AS EVENT

'INTERFACE DFileSystemImageImportEventsImpl GUID$("{D25C30F9-4087-4366-9E24-E55BE286424B}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD UpdateImport <257> ( _
'     BYVAL pobject AS IDispatch _                       ' __in IDispatch *object
'   , BYVAL fileSystem AS LONG _                         ' __in FsiFileSystems fileSystem
'   , BYVAL currentItem AS WSTRING _                     ' __in BSTR currentItem
'   , BYVAL importedDirectoryItems AS LONG _             ' __in LONG importedDirectoryItems
'   , BYVAL totalDirectoryItems AS LONG _                ' __in LONG totalDirectoryItems
'   , BYVAL importedFileItems AS LONG _                  ' __in LONG importedFileItems
'   , BYVAL totalFileItems AS LONG _                     ' __in LONG totalFileItems
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS
