' ########################################################################################
' Microsoft Windows
' File: PatchWiz.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PATCHWIZ_INC = 1

'#include <windows.h>
'#include <ole2.h>
'#include <strsafe.h>
'#include <stdio.h>
'#include <stdlib.h>

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "ole2.inc"

'/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
'//
'// Function:  UiCreatePatchPackage
'//
'// Synopsis:    Main entry point to PatchWiz.  This method is used for backwards compatibility with the previous
'//            version of PatchWiz.  Its purpose is to create a valid patch.  This method calls the updated version
'//            of UiCreatePatchPackageEx.
'//
'// Arguments:
'//         [in]   szPcpPath - full absolute path to Windows Installer database
'//               (PCP file) that contains appropriate tables of input-data for
'//               Patch creation process such as Properties and TargetImages.
'//         [in]   szPatchPath - optional, full absolute path to Patching Package
'//               file (MSP file) to create and stuff with output.  If this
'//               NULL or an empty string, the api will try to use
'//               Properties.Value where Properties.Name = PatchOutputPath
'//               from the PCP file.
'//         [in]   szLogPath - path to store the log file.
'//         [in]   hwndStatus - optional, handle to a window that displays text.
'//         [in]   szTempFolder - optional location to use for temp files.
'//               Default is %TEMP%\~pcw_tmp.tmp\, if specified, directory must exist.
'//         [in]   fRemoveTempFolderIfPresent - remove temp folder (and all its
'//               contents) if present.  If FALSE and folder is present, api
'//               will fail.
'// Returns:
'//         See UiCreatePatchPackageEx below.
'//
'// Notes:   Used for backwards compatibility.
'//
'/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

'/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
'//
'// Function:  UiCreatePatchPackageEx
'//
'// Synopsis:    Updated main entry point to PatchWiz.  This method provides a few new parameter requirements as
'//            listed below.  This method calls each of the five phases in order to create a valid patch as output.
'//
'// Arguments:
'//         [in]   szPcpPath - full absolute path to Windows Installer database
'//               (PCP file) that contains appropriate tables of input-data for
'//               Patch creation process such as Properties and TargetImages.
'//         [in]   szPatchPath - optional, full absolute path to Patching Package
'//               file (MSP file) to create and stuff with output.  If this
'//               NULL or an empty string, the api will try to use
'//               Properties.Value where Properties.Name = PatchOutputPath
'//               from the PCP file.
'//         [in]   szLogPath - path to store the log file.
'//         [in]   hwndStatus - optional, handle to a window that displays text.
'//         [in]   szTempFolder - optional location to use for temp files.
'//               Default is %TEMP%\~pcw_tmp.tmp\, if specified, directory must exist.
'//         [in]   fRemoveTempFolderIfPresent - remove temp folder (and all its
'//               contents) if present.  If FALSE and folder is present, api
'//               will fail.
'//         *NEW PARAMETERS*
'//         [in]   uiLogLevel - Determines what entries are written to the log file.
'//                     - 0x00000000 - No logging.
'//                     - 0x00000001 - INFO
'//                     - 0x00000002 - WARNING
'//                     - 0x00000004 - ERROR
'//         [in]   UILevel - If 0, no UI is shown, else if set to 1 then UI can occur.
'//         [in]   szSummaryOutputPath - optional, path to store any summary output of the patch
'//               functionality and description.  If null, no output is written.
'//
'// Returns:
'//         ERROR_SUCCESS, plus ERROR_PCW_* that are listed in constants.h.
'//
'// Notes:
'//
'/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION UiCreatePatchPackageA IMPORT "patchwiz.dll" ALIAS "UiCreatePatchPackageA" ( _
   BYREF szPcpPath AS ASCIIZ _                          ' __in LPCSTR szPcpPath
 , BYREF szPatchPath AS ASCIIZ _                        ' __in LPCSTR szPatchPath
 , BYREF szLogPath AS ASCIIZ _                          ' __in LPCSTR szLogPath
 , BYVAL hwndStatus AS DWORD _                          ' __in HWND hwndStatus
 , BYREF szTempFolder AS ASCIIZ _                       ' __in LPCSTR szTempFolder
 , BYVAL fRemoveTempFolderIfPresent AS LONG _           ' __in BOOL fRemoveTempFolderIfPresent
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION UiCreatePatchPackageW IMPORT "patchwiz.dll" ALIAS "UiCreatePatchPackageW" ( _
   BYREF szPcpPath AS WSTRINGZ _                        ' __in LPCWSTR szPcpPath
 , BYREF szPatchPath AS WSTRINGZ _                      ' __in LPCWSTR szPatchPath
 , BYREF szLogPath AS WSTRINGZ _                        ' __in LPCWSTR szLogPath
 , BYVAL hwndStatus AS DWORD _                          ' __in HWND hwndStatus
 , BYREF szTempFolder AS WSTRINGZ _                     ' __in LPCWSTR szTempFolder
 , BYVAL fRemoveTempFolderIfPresent AS LONG _           ' __in BOOL fRemoveTempFolderIfPresent
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO UiCreatePatchPackage = UiCreatePatchPackageW
#ELSE
   MACRO UiCreatePatchPackage = UiCreatePatchPackageA
#ENDIF

DECLARE FUNCTION UiCreatePatchPackageExA IMPORT "patchwiz.dll" ALIAS "UiCreatePatchPackageExA" ( _
   BYREF szPcpPath AS ASCIIZ _                          ' __in LPCSTR szPcpPath
 , BYREF szPatchPath AS ASCIIZ _                        ' __in LPCSTR szPatchPath
 , BYREF szLogPath AS ASCIIZ _                          ' __in LPCSTR szLogPath
 , BYVAL hwndStatus AS DWORD _                          ' __in HWND hwndStatus
 , BYREF szTempFolder AS ASCIIZ _                       ' __in LPCSTR szTempFolder
 , BYVAL fRemoveTempFolderIfPresent AS LONG _           ' __in BOOL fRemoveTempFolderIfPresent
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION UiCreatePatchPackageExW IMPORT "patchwiz.dll" ALIAS "UiCreatePatchPackageExW" ( _
   BYREF szPcpPath AS WSTRINGZ _                        ' __in LPCWSTR szPcpPath
 , BYREF szPatchPath AS WSTRINGZ _                      ' __in LPCWSTR szPatchPath
 , BYREF szLogPath AS WSTRINGZ _                        ' __in LPCWSTR szLogPath
 , BYVAL hwndStatus AS DWORD _                          ' __in HWND hwndStatus
 , BYREF szTempFolder AS WSTRINGZ _                     ' __in LPCWSTR szTempFolder
 , BYVAL fRemoveTempFolderIfPresent AS LONG _           ' __in BOOL fRemoveTempFolderIfPresent
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO UiCreatePatchPackageEx = UiCreatePatchPackageExW
#ELSE
   MACRO UiCreatePatchPackageEx = UiCreatePatchPackageExA
#ENDIF

%cchMaxInteger                        = 12&
%LOGNONE                              = &H00000000???   ' // No logging
%LOGINFO                              = &H00000001???   ' // Log INFO: entries
%LOGWARN                              = &H00000002???   ' // Log WARNING: entries
%LOGERR                               = &H00000004???   ' // Log ERROR: entries
%LOGPERFMESSAGES                      = &H00000008???
%LOGALL = %LOGINFO OR %LOGWARN OR %LOGERR OR %LOGPERFMESSAGES
%UINONE                               = &H00000000???   ' // Show NO user interface
%UILOGBITS                            = 15???
%UIALL                                = &H00008000???   ' 1 << UILOGBITS // Show ALL user interface
%DEFAULT_MINIMUM_REQUIRED_MSI_VERSION = 100???
%DEFAULT_FILE_SEQUENCE_START          = 2???            ' // Default sequence start for adding files to cab.
%DEFAULT_DISK_ID                      = 2???            ' // Default disk id to use

'// Return values
%ERROR_PCW_BASE                                 = &HC00E5101???

%ERROR_PCW_PCP_DOESNT_EXIST                    = (%ERROR_PCW_BASE + &H00)
%ERROR_PCW_PCP_BAD_FORMAT                      = (%ERROR_PCW_BASE + &H01)
%ERROR_PCW_CANT_CREATE_TEMP_FOLDER             = (%ERROR_PCW_BASE + &H02)
%ERROR_PCW_MISSING_PATCH_PATH                  = (%ERROR_PCW_BASE + &H03)
%ERROR_PCW_CANT_OVERWRITE_PATCH                = (%ERROR_PCW_BASE + &H04)
%ERROR_PCW_CANT_CREATE_PATCH_FILE              = (%ERROR_PCW_BASE + &H05)
%ERROR_PCW_MISSING_PATCH_GUID                  = (%ERROR_PCW_BASE + &H06)
%ERROR_PCW_BAD_PATCH_GUID                      = (%ERROR_PCW_BASE + &H07)
%ERROR_PCW_BAD_GUIDS_TO_REPLACE                = (%ERROR_PCW_BASE + &H08)
%ERROR_PCW_BAD_TARGET_PRODUCT_CODE_LIST        = (%ERROR_PCW_BASE + &H09)
%ERROR_PCW_NO_UPGRADED_IMAGES_TO_PATCH         = (%ERROR_PCW_BASE + &H0a)
'//#define ERROR_PCW_BAD_API_PATCHING_OPTION_FLAGS       = (ERROR_PCW_BASE + 0x0b) -- obsolete
%ERROR_PCW_BAD_API_PATCHING_SYMBOL_FLAGS       = (%ERROR_PCW_BASE + &H0c)
%ERROR_PCW_OODS_COPYING_MSI                    = (%ERROR_PCW_BASE + &H0d)
%ERROR_PCW_UPGRADED_IMAGE_NAME_TOO_LONG        = (%ERROR_PCW_BASE + &H0e)
%ERROR_PCW_BAD_UPGRADED_IMAGE_NAME             = (%ERROR_PCW_BASE + &H0f)

%ERROR_PCW_DUP_UPGRADED_IMAGE_NAME             = (%ERROR_PCW_BASE + &H10)
%ERROR_PCW_UPGRADED_IMAGE_PATH_TOO_LONG        = (%ERROR_PCW_BASE + &H11)
%ERROR_PCW_UPGRADED_IMAGE_PATH_EMPTY           = (%ERROR_PCW_BASE + &H12)
%ERROR_PCW_UPGRADED_IMAGE_PATH_NOT_EXIST       = (%ERROR_PCW_BASE + &H13)
%ERROR_PCW_UPGRADED_IMAGE_PATH_NOT_MSI         = (%ERROR_PCW_BASE + &H14)
%ERROR_PCW_UPGRADED_IMAGE_COMPRESSED           = (%ERROR_PCW_BASE + &H15)
%ERROR_PCW_TARGET_IMAGE_NAME_TOO_LONG          = (%ERROR_PCW_BASE + &H16)
%ERROR_PCW_BAD_TARGET_IMAGE_NAME               = (%ERROR_PCW_BASE + &H17)
%ERROR_PCW_DUP_TARGET_IMAGE_NAME               = (%ERROR_PCW_BASE + &H18)
%ERROR_PCW_TARGET_IMAGE_PATH_TOO_LONG          = (%ERROR_PCW_BASE + &H19)
%ERROR_PCW_TARGET_IMAGE_PATH_EMPTY             = (%ERROR_PCW_BASE + &H1a)
%ERROR_PCW_TARGET_IMAGE_PATH_NOT_EXIST         = (%ERROR_PCW_BASE + &H1b)
%ERROR_PCW_TARGET_IMAGE_PATH_NOT_MSI           = (%ERROR_PCW_BASE + &H1c)
%ERROR_PCW_TARGET_IMAGE_COMPRESSED             = (%ERROR_PCW_BASE + &H1d)
%ERROR_PCW_TARGET_BAD_PROD_VALIDATE            = (%ERROR_PCW_BASE + &H1e)
%ERROR_PCW_TARGET_BAD_PROD_CODE_VAL            = (%ERROR_PCW_BASE + &H1f)

%ERROR_PCW_UPGRADED_MISSING_SRC_FILES          = (%ERROR_PCW_BASE + &H20)
%ERROR_PCW_TARGET_MISSING_SRC_FILES            = (%ERROR_PCW_BASE + &H21)
%ERROR_PCW_IMAGE_FAMILY_NAME_TOO_LONG          = (%ERROR_PCW_BASE + &H22)
%ERROR_PCW_BAD_IMAGE_FAMILY_NAME               = (%ERROR_PCW_BASE + &H23)
%ERROR_PCW_DUP_IMAGE_FAMILY_NAME               = (%ERROR_PCW_BASE + &H24)
%ERROR_PCW_BAD_IMAGE_FAMILY_SRC_PROP           = (%ERROR_PCW_BASE + &H25)
%ERROR_PCW_UFILEDATA_LONG_FILE_TABLE_KEY       = (%ERROR_PCW_BASE + &H26)
%ERROR_PCW_UFILEDATA_BLANK_FILE_TABLE_KEY      = (%ERROR_PCW_BASE + &H27)
%ERROR_PCW_UFILEDATA_MISSING_FILE_TABLE_KEY    = (%ERROR_PCW_BASE + &H28)
%ERROR_PCW_EXTFILE_LONG_FILE_TABLE_KEY         = (%ERROR_PCW_BASE + &H29)
%ERROR_PCW_EXTFILE_BLANK_FILE_TABLE_KEY        = (%ERROR_PCW_BASE + &H2a)
%ERROR_PCW_EXTFILE_BAD_FAMILY_FIELD            = (%ERROR_PCW_BASE + &H2b)
%ERROR_PCW_EXTFILE_LONG_PATH_TO_FILE           = (%ERROR_PCW_BASE + &H2c)
%ERROR_PCW_EXTFILE_BLANK_PATH_TO_FILE          = (%ERROR_PCW_BASE + &H2d)
%ERROR_PCW_EXTFILE_MISSING_FILE                = (%ERROR_PCW_BASE + &H2e)
'//#define ERROR_PCW_FILERANGE_LONG_FILE_TABLE_KEY       (ERROR_PCW_BASE + 0x2f) -- obsolete

'//#define ERROR_PCW_FILERANGE_BLANK_FILE_TABLE_KEY      (ERROR_PCW_BASE + 0x30) -- obsolete
'//#define ERROR_PCW_FILERANGE_MISSING_FILE_TABLE_KEY    (ERROR_PCW_BASE + 0x31) -- obsolete
'//#define ERROR_PCW_FILERANGE_LONG_PATH_TO_FILE         (ERROR_PCW_BASE + 0x32) -- obsolete
'//#define ERROR_PCW_FILERANGE_MISSING_FILE              (ERROR_PCW_BASE + 0x33) -- obsolete
'//#define ERROR_PCW_FILERANGE_INVALID_OFFSET            (ERROR_PCW_BASE + 0x34) -- obsolete
'//#define ERROR_PCW_FILERANGE_INVALID_SIZE              (ERROR_PCW_BASE + 0x35) -- obsolete
'//#define ERROR_PCW_FILERANGE_INVALID_RETAIN            (ERROR_PCW_BASE + 0x36) -- obsolete
'//#define ERROR_PCW_BAD_MEDIA_SRC_PROP_NAME             (ERROR_PCW_BASE + 0x37) -- obsolete
'//#define ERROR_PCW_BAD_MEDIA_DISK_ID                   (ERROR_PCW_BASE + 0x38) -- obsolete
%ERROR_PCW_BAD_FILE_SEQUENCE_START             = (%ERROR_PCW_BASE + &H39)
%ERROR_PCW_CANT_COPY_FILE_TO_TEMP_FOLDER       = (%ERROR_PCW_BASE + &H3a)
%ERROR_PCW_CANT_CREATE_ONE_PATCH_FILE          = (%ERROR_PCW_BASE + &H3b)
%ERROR_PCW_BAD_IMAGE_FAMILY_DISKID             = (%ERROR_PCW_BASE + &H3c)
%ERROR_PCW_BAD_IMAGE_FAMILY_FILESEQSTART       = (%ERROR_PCW_BASE + &H3d)
%ERROR_PCW_BAD_UPGRADED_IMAGE_FAMILY           = (%ERROR_PCW_BASE + &H3e)
%ERROR_PCW_BAD_TARGET_IMAGE_UPGRADED           = (%ERROR_PCW_BASE + &H3f)

%ERROR_PCW_DUP_TARGET_IMAGE_PACKCODE           = (%ERROR_PCW_BASE + &H40)
%ERROR_PCW_UFILEDATA_BAD_UPGRADED_FIELD        = (%ERROR_PCW_BASE + &H41)
%ERROR_PCW_MISMATCHED_PRODUCT_CODES            = (%ERROR_PCW_BASE + &H42)
%ERROR_PCW_MISMATCHED_PRODUCT_VERSIONS         = (%ERROR_PCW_BASE + &H43)
%ERROR_PCW_CANNOT_WRITE_DDF                    = (%ERROR_PCW_BASE + &H44)
%ERROR_PCW_CANNOT_RUN_MAKECAB                  = (%ERROR_PCW_BASE + &H45)
'//#define ERROR_PCW_CANNOT_CREATE_STORAGE               (ERROR_PCW_BASE + 0x46) -- obsolete
'//#define ERROR_PCW_CANNOT_CREATE_STREAM                (ERROR_PCW_BASE + 0x47) -- obsolete
'//#define ERROR_PCW_CANNOT_WRITE_STREAM                 (ERROR_PCW_BASE + 0x48) -- obsolete
'//#define ERROR_PCW_CANNOT_READ_CABINET                 (ERROR_PCW_BASE + 0x49) -- obsolete
%ERROR_PCW_WRITE_SUMMARY_PROPERTIES            = (%ERROR_PCW_BASE + &H4a)
%ERROR_PCW_TFILEDATA_LONG_FILE_TABLE_KEY       = (%ERROR_PCW_BASE + &H4b)
%ERROR_PCW_TFILEDATA_BLANK_FILE_TABLE_KEY      = (%ERROR_PCW_BASE + &H4c)
%ERROR_PCW_TFILEDATA_MISSING_FILE_TABLE_KEY    = (%ERROR_PCW_BASE + &H4d)
%ERROR_PCW_TFILEDATA_BAD_TARGET_FIELD          = (%ERROR_PCW_BASE + &H4e)
%ERROR_PCW_UPGRADED_IMAGE_PATCH_PATH_TOO_LONG  = (%ERROR_PCW_BASE + &H4f)

%ERROR_PCW_UPGRADED_IMAGE_PATCH_PATH_NOT_EXIST = (%ERROR_PCW_BASE + &H50)
%ERROR_PCW_UPGRADED_IMAGE_PATCH_PATH_NOT_MSI   = (%ERROR_PCW_BASE + &H51)
%ERROR_PCW_DUP_UPGRADED_IMAGE_PACKCODE         = (%ERROR_PCW_BASE + &H52)
%ERROR_PCW_UFILEIGNORE_BAD_UPGRADED_FIELD      = (%ERROR_PCW_BASE + &H53)
%ERROR_PCW_UFILEIGNORE_LONG_FILE_TABLE_KEY     = (%ERROR_PCW_BASE + &H54)
%ERROR_PCW_UFILEIGNORE_BLANK_FILE_TABLE_KEY    = (%ERROR_PCW_BASE + &H55)
%ERROR_PCW_UFILEIGNORE_BAD_FILE_TABLE_KEY      = (%ERROR_PCW_BASE + &H56)
%ERROR_PCW_FAMILY_RANGE_NAME_TOO_LONG          = (%ERROR_PCW_BASE + &H57)
%ERROR_PCW_BAD_FAMILY_RANGE_NAME               = (%ERROR_PCW_BASE + &H58)
%ERROR_PCW_FAMILY_RANGE_LONG_FILE_TABLE_KEY    = (%ERROR_PCW_BASE + &H59)
%ERROR_PCW_FAMILY_RANGE_BLANK_FILE_TABLE_KEY   = (%ERROR_PCW_BASE + &H5a)
%ERROR_PCW_FAMILY_RANGE_LONG_RETAIN_OFFSETS    = (%ERROR_PCW_BASE + &H5b)
%ERROR_PCW_FAMILY_RANGE_BLANK_RETAIN_OFFSETS   = (%ERROR_PCW_BASE + &H5c)
%ERROR_PCW_FAMILY_RANGE_BAD_RETAIN_OFFSETS     = (%ERROR_PCW_BASE + &H5d)
%ERROR_PCW_FAMILY_RANGE_LONG_RETAIN_LENGTHS    = (%ERROR_PCW_BASE + &H5e)
%ERROR_PCW_FAMILY_RANGE_BLANK_RETAIN_LENGTHS   = (%ERROR_PCW_BASE + &H5f)

%ERROR_PCW_FAMILY_RANGE_BAD_RETAIN_LENGTHS     = (%ERROR_PCW_BASE + &H60)
%ERROR_PCW_FAMILY_RANGE_COUNT_MISMATCH         = (%ERROR_PCW_BASE + &H61)
%ERROR_PCW_EXTFILE_LONG_IGNORE_OFFSETS         = (%ERROR_PCW_BASE + &H62)
%ERROR_PCW_EXTFILE_BAD_IGNORE_OFFSETS          = (%ERROR_PCW_BASE + &H63)
%ERROR_PCW_EXTFILE_LONG_IGNORE_LENGTHS         = (%ERROR_PCW_BASE + &H64)
%ERROR_PCW_EXTFILE_BAD_IGNORE_LENGTHS          = (%ERROR_PCW_BASE + &H65)
%ERROR_PCW_EXTFILE_IGNORE_COUNT_MISMATCH       = (%ERROR_PCW_BASE + &H66)
%ERROR_PCW_EXTFILE_LONG_RETAIN_OFFSETS         = (%ERROR_PCW_BASE + &H67)
%ERROR_PCW_EXTFILE_BAD_RETAIN_OFFSETS          = (%ERROR_PCW_BASE + &H68)
'//#define ERROR_PCW_EXTFILE_RETAIN_COUNT_MISMATCH       (ERROR_PCW_BASE + 0x69) -- obsolete
%ERROR_PCW_TFILEDATA_LONG_IGNORE_OFFSETS       = (%ERROR_PCW_BASE + &H6a)
%ERROR_PCW_TFILEDATA_BAD_IGNORE_OFFSETS        = (%ERROR_PCW_BASE + &H6b)
%ERROR_PCW_TFILEDATA_LONG_IGNORE_LENGTHS       = (%ERROR_PCW_BASE + &H6c)
%ERROR_PCW_TFILEDATA_BAD_IGNORE_LENGTHS        = (%ERROR_PCW_BASE + &H6d)
%ERROR_PCW_TFILEDATA_IGNORE_COUNT_MISMATCH     = (%ERROR_PCW_BASE + &H6e)
%ERROR_PCW_TFILEDATA_LONG_RETAIN_OFFSETS       = (%ERROR_PCW_BASE + &H6f)

%ERROR_PCW_TFILEDATA_BAD_RETAIN_OFFSETS        = (%ERROR_PCW_BASE + &H70)
'//#define ERROR_PCW_TFILEDATA_RETAIN_COUNT_MISMATCH     (ERROR_PCW_BASE + 0x71) -- obsolete
%ERROR_PCW_CANT_GENERATE_TRANSFORM             = (%ERROR_PCW_BASE + &H72)
%ERROR_PCW_CANT_CREATE_SUMMARY_INFO            = (%ERROR_PCW_BASE + &H73)
%ERROR_PCW_CANT_GENERATE_TRANSFORM_POUND       = (%ERROR_PCW_BASE + &H74)
%ERROR_PCW_CANT_CREATE_SUMMARY_INFO_POUND      = (%ERROR_PCW_BASE + &H75)
%ERROR_PCW_BAD_UPGRADED_IMAGE_PRODUCT_CODE     = (%ERROR_PCW_BASE + &H76)
%ERROR_PCW_BAD_UPGRADED_IMAGE_PRODUCT_VERSION  = (%ERROR_PCW_BASE + &H77)
%ERROR_PCW_BAD_UPGRADED_IMAGE_UPGRADE_CODE     = (%ERROR_PCW_BASE + &H78)
%ERROR_PCW_BAD_TARGET_IMAGE_PRODUCT_CODE       = (%ERROR_PCW_BASE + &H79)
%ERROR_PCW_BAD_TARGET_IMAGE_PRODUCT_VERSION    = (%ERROR_PCW_BASE + &H7a)
%ERROR_PCW_BAD_TARGET_IMAGE_UPGRADE_CODE       = (%ERROR_PCW_BASE + &H7b)
%ERROR_PCW_MATCHED_PRODUCT_VERSIONS            = (%ERROR_PCW_BASE + &H7c)
%ERROR_PCW_OBSOLETION_WITH_SEQUENCE_DATA       = (%ERROR_PCW_BASE + &H7d)
%ERROR_PCW_OBSOLETION_WITH_MSI30               = (%ERROR_PCW_BASE + &H7e)
%ERROR_PCW_OBSOLETION_WITH_PATCHSEQUENCE       = (%ERROR_PCW_BASE + &H7f)
%ERROR_PCW_CANNOT_CREATE_TABLE                 = (%ERROR_PCW_BASE + &H80)
%ERROR_PCW_CANT_GENERATE_SEQUENCEINFO_MAJORUPGD = (%ERROR_PCW_BASE + &H81)
%ERROR_PCW_MAJOR_UPGD_WITHOUT_SEQUENCING       = (%ERROR_PCW_BASE + &H82)
%ERROR_PCW_BAD_PRODUCTVERSION_VALIDATION       = (%ERROR_PCW_BASE + &H83)
%ERROR_PCW_BAD_TRANSFORMSET                    = (%ERROR_PCW_BASE + &H84)
%ERROR_PCW_BAD_TGT_UPD_IMAGES                  = (%ERROR_PCW_BASE + &H85)
%ERROR_PCW_BAD_SUPERCEDENCE                    = (%ERROR_PCW_BASE + &H86)
%ERROR_PCW_BAD_SEQUENCE                        = (%ERROR_PCW_BASE + &H87)
%ERROR_PCW_BAD_TARGET                          = (%ERROR_PCW_BASE + &H88)
%ERROR_PCW_NULL_PATCHFAMILY                    = (%ERROR_PCW_BASE + &H89)
%ERROR_PCW_NULL_SEQUENCE_NUMBER                = (%ERROR_PCW_BASE + &H8a)
%ERROR_PCW_BAD_VERSION_STRING                  = (%ERROR_PCW_BASE + &H8b)
%ERROR_PCW_BAD_MAJOR_VERSION                   = (%ERROR_PCW_BASE + &H8c)
%ERROR_PCW_SEQUENCING_BAD_TARGET               = (%ERROR_PCW_BASE + &H8d)
%ERROR_PCW_PATCHMETADATA_PROP_NOT_SET          = (%ERROR_PCW_BASE + &H8e)
%ERROR_PCW_INVALID_PATCHMETADATA_PROP          = (%ERROR_PCW_BASE + &H8f)
%ERROR_PCW_INVALID_SUPERCEDENCE                = (%ERROR_PCW_BASE + &H90)
%ERROR_PCW_DUPLICATE_SEQUENCE_RECORD           = (%ERROR_PCW_BASE + &H91)
%ERROR_PCW_WRONG_PATCHMETADATA_STRD_PROP       = (%ERROR_PCW_BASE + &H92)

'/*  NEW in PatchWizEx */
%ERROR_PCW_INVALID_PARAMETER                   = (%ERROR_PCW_BASE + &H93)
%ERROR_PCW_CREATEFILE_LOG_FAILED               = (%ERROR_PCW_BASE + &H94)
%ERROR_PCW_INVALID_LOG_LEVEL                   = (%ERROR_PCW_BASE + &H95)
%ERROR_PCW_INVALID_UI_LEVEL                    = (%ERROR_PCW_BASE + &H96)
%ERROR_PCW_ERROR_WRITING_TO_LOG                = (%ERROR_PCW_BASE + &H97)
%ERROR_PCW_OUT_OF_MEMORY                       = (%ERROR_PCW_BASE + &H98)
%ERROR_PCW_UNKNOWN_ERROR                       = (%ERROR_PCW_BASE + &H99)
%ERROR_PCW_UNKNOWN_INFO                        = (%ERROR_PCW_BASE + &H9a)
%ERROR_PCW_UNKNOWN_WARN                        = (%ERROR_PCW_BASE + &H9b)
%ERROR_PCW_OPEN_VIEW                           = (%ERROR_PCW_BASE + &H9c)
%ERROR_PCW_EXECUTE_VIEW                        = (%ERROR_PCW_BASE + &H9d)
%ERROR_PCW_VIEW_FETCH                          = (%ERROR_PCW_BASE + &H9e)

%ERROR_PCW_FAILED_EXPAND_PATH                  = (%ERROR_PCW_BASE + &H9f)
%ERROR_PCW_INTERNAL_ERROR                      = (%ERROR_PCW_BASE + &H100)
%ERROR_PCW_INVALID_PCP_PROPERTY                = (%ERROR_PCW_BASE + &H101)
%ERROR_PCW_INVALID_PCP_TARGETIMAGES            = (%ERROR_PCW_BASE + &H102)
%ERROR_PCW_LAX_VALIDATION_FLAGS                = (%ERROR_PCW_BASE + &H103)
%ERROR_PCW_FAILED_CREATE_TRANSFORM             = (%ERROR_PCW_BASE + &H104)
%ERROR_PCW_CANT_DELETE_TEMP_FOLDER             = (%ERROR_PCW_BASE + &H105)
%ERROR_PCW_MISSING_DIRECTORY_TABLE             = (%ERROR_PCW_BASE + &H106)
%ERROR_PCW_INVALID_SUPERSEDENCE_VALUE          = (%ERROR_PCW_BASE + &H107)
%ERROR_PCW_INVALID_PATCH_TYPE_SEQUENCING       = (%ERROR_PCW_BASE + &H108)
%ERROR_PCW_CANT_READ_FILE                      = (%ERROR_PCW_BASE + &H109)
%ERROR_PCW_TARGET_WRONG_PRODUCT_VERSION_COMP   = (%ERROR_PCW_BASE + &H10a)
%ERROR_PCW_INVALID_PCP_UPGRADEDFILESTOIGNORE   = (%ERROR_PCW_BASE + &H10b)
%ERROR_PCW_INVALID_PCP_UPGRADEDIMAGES          = (%ERROR_PCW_BASE + &H10c)
%ERROR_PCW_INVALID_PCP_EXTERNALFILES           = (%ERROR_PCW_BASE + &H10d)
%ERROR_PCW_INVALID_PCP_IMAGEFAMILIES           = (%ERROR_PCW_BASE + &H10e)
%ERROR_PCW_INVALID_PCP_PATCHSEQUENCE           = (%ERROR_PCW_BASE + &H10f)
%ERROR_PCW_INVALID_PCP_TARGETFILES_OPTIONALDATA = (%ERROR_PCW_BASE + &H110)
%ERROR_PCW_INVALID_PCP_UPGRADEDFILES_OPTIONALDATA = (%ERROR_PCW_BASE + &H111)
%ERROR_PCW_MISSING_PATCHMETADATA               = (%ERROR_PCW_BASE + &H112)
%ERROR_PCW_IMAGE_PATH_NOT_EXIST                = (%ERROR_PCW_BASE + &H113)
%ERROR_PCW_INVALID_RANGE_ELEMENT               = (%ERROR_PCW_BASE + &H114)
%ERROR_PCW_INVALID_MAJOR_VERSION               = (%ERROR_PCW_BASE + &H115)
%ERROR_PCW_INVALID_PCP_PROPERTIES              = (%ERROR_PCW_BASE + &H116)
%ERROR_PCW_INVALID_PCP_FAMILYFILERANGES        = (%ERROR_PCW_BASE + &H117)

%INFO_BASE                                     = &Hc00f5101???
%INFO_PASSED_MAIN_CONTROL                      = (%INFO_BASE + &H00)
%INFO_ENTERING_PHASE_I_VALIDATION              = (%INFO_BASE + &H01)
%INFO_ENTERING_PHASE_I                         = (%INFO_BASE + &H02)
%INFO_PCP_PATH                                 = (%INFO_BASE + &H03)
%INFO_TEMP_DIR                                 = (%INFO_BASE + &H04)
%INFO_SET_OPTIONS                              = (%INFO_BASE + &H05)
%INFO_PROPERTY                                 = (%INFO_BASE + &H06)
%INFO_ENTERING_PHASE_II                        = (%INFO_BASE + &H07)
%INFO_ENTERING_PHASE_III                       = (%INFO_BASE + &H08)
%INFO_ENTERING_PHASE_IV                        = (%INFO_BASE + &H09)
%INFO_ENTERING_PHASE_V                         = (%INFO_BASE + &H0a)
%INFO_GENERATING_METADATA                      = (%INFO_BASE + &H10)
%INFO_TEMP_DIR_CLEANUP                         = (%INFO_BASE + &H11)
%INFO_PATCHCACHE_FILEINFO_FAILURE              = (%INFO_BASE + &H12)
%INFO_PATCHCACHE_PCI_READFAILURE               = (%INFO_BASE + &H13)
%INFO_PATCHCACHE_PCI_WRITEFAILURE              = (%INFO_BASE + &H14)
%INFO_USING_USER_MSI_FOR_PATCH_TABLES          = (%INFO_BASE + &H15)
%INFO_SUCCESSFUL_PATCH_CREATION                = (%INFO_BASE + &H16)

%WARN_BASE                                     = &Hc0105101???
%WARN_MAJOR_UPGRADE_PATCH                      = (%WARN_BASE + &H00)
%WARN_SEQUENCE_DATA_GENERATION_DISABLED        = (%WARN_BASE + &H01)
%WARN_SEQUENCE_DATA_SUPERSEDENCE_IGNORED       = (%WARN_BASE + &H02)
%WARN_IMPROPER_TRANSFORM_VALIDATION            = (%WARN_BASE + &H03)
%WARN_PCW_MISMATCHED_PRODUCT_CODES             = (%WARN_BASE + &H04)
%WARN_PCW_MISMATCHED_PRODUCT_VERSIONS          = (%WARN_BASE + &H05)
%WARN_INVALID_TRANSFORM_VALIDATION             = (%WARN_BASE + &H06)
%WARN_BAD_MAJOR_VERSION                        = (%WARN_BASE + &H07)
%WARN_FILE_VERSION_DOWNREV                     = (%WARN_BASE + &H08)
%WARN_EQUAL_FILE_VERSION                       = (%WARN_BASE + &H09)
%WARN_PATCHPROPERTYNOTSET                      = (%WARN_BASE + &H0A)
%WARN_OBSOLETION_WITH_SEQUENCE_DATA            = (%WARN_BASE + &H11)
%WARN_OBSOLETION_WITH_MSI30                    = (%WARN_BASE + &H10)
%WARN_OBSOLETION_WITH_PATCHSEQUENCE            = (%WARN_BASE + &H12)
