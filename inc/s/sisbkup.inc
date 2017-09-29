' ########################################################################################
' Microsoft Windows
' File: sisbkup.inc
' Contents: External interface for the SIS Backup dll
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SISBKUP_INC = 1

DECLARE FUNCTION SisCreateBackupStructure IMPORT "Sisbkup.dll" ALIAS "SisCreateBackupStructure" ( _
   BYREF volumeRoot AS WSTRINGZ _                       ' __in  PWCHAR volumeRoot
 , BYREF sisBackupStructure AS DWORD _                  ' __out PVOID *sisBackupStructure
 , BYREF commonStoreRootPathname AS DWORD _             ' __out PWCHAR *commonStoreRootPathname
 , BYREF countOfCommonStoreFilesToBackup AS DWORD _     ' __out PULONG countOfCommonStoreFilesToBackup
 , BYREF commonStoreFilesToBackup AS DWORD _            ' __out PWCHAR **commonStoreFilesToBackup
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SisCSFilesToBackupForLink IMPORT "Sisbkup.dll" ALIAS "SisCSFilesToBackupForLink" ( _
   BYVAL sisBackupStructure AS DWORD _                  ' __in  PVOID sisBackupStructure
 , BYVAL reparseData AS DWORD _                         ' __in  PVOID reparseData
 , BYVAL reparseDataSize AS DWORD _                     ' __in  ULONG reparseDataSize
 , BYVAL thisFileContext AS DWORD _                     ' __in_opt PVOID thisFileContext
 , BYREF matchingFileContext AS DWORD _                 ' __out_opt PVOID *matchingFileContext
 , BYREF countOfCommonStoreFilesToBackup AS DWORD _     ' __out PULONG countOfCommonStoreFilesToBackup
 , BYREF commonStoreFilesToBackup AS DWORD _            ' __out PWCHAR **commonStoreFilesToBackup
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SisFreeBackupStructure IMPORT "Sisbkup.dll" ALIAS "SisFreeBackupStructure" ( _
   BYVAL sisBackupStructure AS DWORD _                  ' __in  PVOID sisBackupStructure
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SisCreateRestoreStructure IMPORT "Sisbkup.dll" ALIAS "SisCreateRestoreStructure" ( _
   BYREF volumeRoot AS WSTRINGZ _                       ' __in  PWCHAR volumeRoot
 , BYREF sisRestoreStructure AS DWORD _                 ' __out PVOID *sisRestoreStructure
 , BYREF commonStoreRootPathname AS DWORD _             ' __out PWCHAR *commonStoreRootPathname
 , BYREF countOfCommonStoreFilesToRestore AS DWORD _    ' __out PULONG countOfCommonStoreFilesToRestore
 , BYREF commonStoreFilesToRestore AS DWORD _           ' __out PWCHAR **commonStoreFilesToRestore
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SisRestoredLink IMPORT "Sisbkup.dll" ALIAS "SisRestoredLink" ( _
   BYVAL sisRestoreStructure AS DWORD _                 ' __in  PVOID sisRestoreStructure
 , BYREF restoredFileName AS WSTRINGZ _                 ' __in  PWCHAR restoredFileName
 , BYVAL reparseData AS DWORD _                         ' __in  PVOID reparseData
 , BYVAL reparseDataSize AS DWORD _                     ' __in  ULONG reparseDataSize
 , BYREF countOfCommonStoreFilesToRestore AS DWORD _    ' __out PULONG countOfCommonStoreFilesToRestore
 , BYREF commonStoreFilesToRestore AS DWORD _           ' __out PWCHAR **commonStoreFilesToRestore
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SisRestoredCommonStoreFile IMPORT "Sisbkup.dll" ALIAS "SisRestoredCommonStoreFile" ( _
   BYVAL sisRestoreStructure AS DWORD _                 ' __in  PVOID sisRestoreStructure
 , BYREF commonStoreFileName AS WSTRINGZ _              ' __in  PWCHAR commonStoreFileName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SisFreeRestoreStructure IMPORT "Sisbkup.dll" ALIAS "SisFreeRestoreStructure" ( _
   BYVAL sisRestoreStructure AS DWORD _                 ' __in  PVOID sisRestoreStructure
 ) AS LONG                                              ' BOOL

DECLARE SUB SisFreeAllocatedMemory IMPORT "Sisbkup.dll" ALIAS "SisFreeAllocatedMemory" ( _
   BYVAL allocatedSpace AS DWORD _                      ' __in  PVOID allocatedSpace
 )                                                      ' void
