' ########################################################################################
' Microsoft Windows
' File: ComAdmin.inc
' Library name: COMAdmin
' Version: 1.0, Locale ID = 0
' Library GUID: {F618C513-DFB8-11D1-A2CF-00805FC79235}
' Path: C:\WINDOWS\system32\Com\comadmin.dll
' Contents: COM + 1.0 Admin Type Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%COMADMIN_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "objbase.inc"

$LIBID_COMAdmin = GUID$("{F618C513-DFB8-11D1-A2CF-00805FC79235}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {F618C514-DFB8-11D1-A2CF-00805FC79235}
$PROGID_COMAdminCatalog1 = "COMAdmin.COMAdminCatalog.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {F618C514-DFB8-11D1-A2CF-00805FC79235}
$PROGID_COMAdminCatalog = "COMAdmin.COMAdminCatalog"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_COMAdminCatalogCollection = GUID$("{F618C516-DFB8-11D1-A2CF-00805FC79235}")
$CLSID_COMAdminCatalogObject     = GUID$("{F618C515-DFB8-11D1-A2CF-00805FC79235}")
$CLSID_COMAdminCatalog           = GUID$("{F618C514-DFB8-11D1-A2CF-00805FC79235}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_COMAdmin_ICatalogCollection = GUID$("{6EB22872-8A19-11D0-81B6-00A0C9231C29}")
$IID_COMAdmin_ICatalogObject     = GUID$("{6EB22871-8A19-11D0-81B6-00A0C9231C29}")
$IID_COMAdmin_ICOMAdminCatalog   = GUID$("{DD662187-DFC2-11D1-A2CF-00805FC79235}")
$IID_COMAdmin_ICOMAdminCatalog2  = GUID$("{790C6E0B-9194-4CC9-9426-A48A63185696}")


' ########################################################################################
' Interface name = ICOMAdminCatalog
' IID = {DD662187-DFC2-11D1-A2CF-00805FC79235}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%COMAdmin_ICOMAdminCatalog_INTERFACE_DEFINED)
    %COMAdmin_ICOMAdminCatalog_INTERFACE_DEFINED = 1

INTERFACE COMAdmin_ICOMAdminCatalog $IID_COMAdmin_ICOMAdminCatalog

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetCollection <1> ( _                         ' VTable offset = 28
     BYVAL bstrCollName AS WSTRING _                    ' __in BSTR bstrCollName
   ) AS IDispatch                                       ' __retval_out IDispatch **ppCatalogCollection
   ' =====================================================================================
   METHOD Connect <2> ( _                               ' VTable offset = 32
     BYVAL bstrCatalogServerName AS WSTRING _           ' __in BSTR bstrCatalogServerName
   ) AS IDispatch                                       ' __retval_out IDispatch **ppCatalogCollection
   ' =====================================================================================
   PROPERTY GET MajorVersion <3> ( _                    ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plMajorVersion
   ' =====================================================================================
   PROPERTY GET MinorVersion <4> ( _                    ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plMinorVersion
   ' =====================================================================================
   METHOD GetCollectionByQuery <5> ( _                  ' VTable offset = 44
     BYVAL bstrCollName AS WSTRING _                    ' __in BSTR bstrCollName
   , BYVAL ppsaVarQuery AS DWORD _                      ' __in SAFEARRAY * *ppsaVarQuery
   ) AS IDispatch                                       ' __retval_out IDispatch **ppCatalogCollection
   ' =====================================================================================
   METHOD ImportComponent <6> ( _                       ' VTable offset = 48
     BYVAL bstrApplIDOrName AS WSTRING _                ' __in BSTR bstrApplIDOrName
   , BYVAL bstrCLSIDOrProgID AS WSTRING _               ' __in BSTR bstrCLSIDOrProgID
   )                                                    ' void
   ' =====================================================================================
   METHOD InstallComponent <7> ( _                      ' VTable offset = 52
     BYVAL bstrApplIDOrName AS WSTRING _                ' __in BSTR bstrApplIDOrName
   , BYVAL bstrDLL AS WSTRING _                         ' __in BSTR bstrDLL
   , BYVAL bstrTLB AS WSTRING _                         ' __in BSTR bstrTLB
   , BYVAL bstrPSDLL AS WSTRING _                       ' __in BSTR bstrPSDLL
   )                                                    ' void
   ' =====================================================================================
   METHOD ShutdownApplication <8> ( _                   ' VTable offset = 56
     BYVAL bstrApplIDOrName AS WSTRING _                ' __in BSTR bstrApplIDOrName
   )                                                    ' void
   ' =====================================================================================
   METHOD ExportApplication <9> ( _                     ' VTable offset = 60
     BYVAL bstrApplIDOrName AS WSTRING _                ' __in BSTR bstrApplIDOrName
   , BYVAL bstrApplicationFile AS WSTRING _             ' __in BSTR bstrApplicationFile
   , BYVAL lOptions AS LONG _                           ' __in long lOptions
   )                                                    ' void
   ' =====================================================================================
   METHOD InstallApplication <10> ( _                   ' VTable offset = 64
     BYVAL bstrApplicationFile AS WSTRING _             ' __in BSTR bstrApplicationFile
   , OPTIONAL BYVAL bstrDestinationDirectory AS WSTRING _ ' __opt_in BSTR bstrDestinationDirectory
   , OPTIONAL BYVAL lOptions AS LONG _                  ' __opt_in long lOptions
   , OPTIONAL BYVAL bstrUserId AS WSTRING _             ' __opt_in BSTR bstrUserId
   , OPTIONAL BYVAL bstrPassword AS WSTRING _           ' __opt_in BSTR bstrPassword
   , OPTIONAL BYVAL bstrRSN AS WSTRING _                ' __opt_in BSTR bstrRSN
   )                                                    ' void
   ' =====================================================================================
   METHOD StopRouter <11> ( _                           ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   METHOD RefreshRouter <12> ( _                        ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================
   METHOD StartRouter <13> ( _                          ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================
   METHOD Reserved1 <14> ( _                            ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   METHOD Reserved2 <15> ( _                            ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD InstallMultipleComponents <16> ( _            ' VTable offset = 88
     BYVAL bstrApplIDOrName AS WSTRING _                ' __in BSTR bstrApplIDOrName
   , BYVAL ppsaVarFileNames AS DWORD _                  ' __in SAFEARRAY * *ppsaVarFileNames
   , BYVAL ppsaVarCLSIDs AS DWORD _                     ' __in SAFEARRAY * *ppsaVarCLSIDs
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMultipleComponentsInfo <17> ( _            ' VTable offset = 92
     BYVAL bstrApplIdOrName AS WSTRING _                ' __in BSTR bstrApplIdOrName
   , BYVAL ppsaVarFileNames AS DWORD _                  ' __in SAFEARRAY * *ppsaVarFileNames
   , BYREF ppsaVarCLSIDs AS DWORD _                     ' __out SAFEARRAY * *ppsaVarCLSIDs
   , BYREF ppsaVarClassNames AS DWORD _                 ' __out SAFEARRAY * *ppsaVarClassNames
   , BYREF ppsaVarFileFlags AS DWORD _                  ' __out SAFEARRAY * *ppsaVarFileFlags
   , BYREF ppsaVarComponentFlags AS DWORD _             ' __out SAFEARRAY * *ppsaVarComponentFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD RefreshComponents <18> ( _                    ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD BackupREGDB <19> ( _                          ' VTable offset = 100
     BYVAL bstrBackupFilePath AS WSTRING _              ' __in BSTR bstrBackupFilePath
   )                                                    ' void
   ' =====================================================================================
   METHOD RestoreREGDB <20> ( _                         ' VTable offset = 104
     BYVAL bstrBackupFilePath AS WSTRING _              ' __in BSTR bstrBackupFilePath
   )                                                    ' void
   ' =====================================================================================
   METHOD QueryApplicationFile <21> ( _                 ' VTable offset = 108
     BYVAL bstrApplicationFile AS WSTRING _             ' __in BSTR bstrApplicationFile
   , BYREF pbstrApplicationName AS WSTRING _            ' __out BSTR *pbstrApplicationName
   , BYREF pbstrApplicationDescription AS WSTRING _     ' __out BSTR *pbstrApplicationDescription
   , BYREF pbHasUsers AS INTEGER _                      ' __out VARIANT_BOOL *pbHasUsers
   , BYREF pbIsProxy AS INTEGER _                       ' __out VARIANT_BOOL *pbIsProxy
   , BYREF ppsaVarFileNames AS DWORD _                  ' __out SAFEARRAY * *ppsaVarFileNames
   )                                                    ' void
   ' =====================================================================================
   METHOD StartApplication <22> ( _                     ' VTable offset = 112
     BYVAL bstrApplIdOrName AS WSTRING _                ' __in BSTR bstrApplIdOrName
   )                                                    ' void
   ' =====================================================================================
   METHOD ServiceCheck <23> ( _                         ' VTable offset = 116
     BYVAL lService AS LONG _                           ' __in long lService
   ) AS LONG                                            ' __retval_out long *plStatus
   ' =====================================================================================
   METHOD InstallMultipleEventClasses <24> ( _          ' VTable offset = 120
     BYVAL bstrApplIdOrName AS WSTRING _                ' __in BSTR bstrApplIdOrName
   , BYVAL ppsaVarFileNames AS DWORD _                  ' __in SAFEARRAY * *ppsaVarFileNames
   , BYVAL ppsaVarCLSIDS AS DWORD _                     ' __in SAFEARRAY * *ppsaVarCLSIDS
   )                                                    ' void
   ' =====================================================================================
   METHOD InstallEventClass <25> ( _                    ' VTable offset = 124
     BYVAL bstrApplIdOrName AS WSTRING _                ' __in BSTR bstrApplIdOrName
   , BYVAL bstrDLL AS WSTRING _                         ' __in BSTR bstrDLL
   , BYVAL bstrTLB AS WSTRING _                         ' __in BSTR bstrTLB
   , BYVAL bstrPSDLL AS WSTRING _                       ' __in BSTR bstrPSDLL
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEventClassesForIID <26> ( _                ' VTable offset = 128
     BYVAL bstrIID AS WSTRING _                         ' __in BSTR bstrIID
   , BYREF ppsaVarCLSIDs AS WORD _                      ' __out SAFEARRAY * *ppsaVarCLSIDs
   , BYREF ppsaVarProgIDs AS DWORD _                    ' __out SAFEARRAY * *ppsaVarProgIDs
   , BYREF ppsaVarDescriptions AS DWORD _               ' __out SAFEARRAY * *ppsaVarDescriptions
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __COMAdmin_ICOMAdminCatalog_INTERFACE_DEFINED__ */


' enum COMAdminInUse
%COMAdminNotInUse                 = 0
%COMAdminInUseByCatalog           = &H1
%COMAdminInUseByRegistryUnknown   = &H2
%COMAdminInUseByRegistryProxyStub = &H3
%COMAdminInUseByRegistryTypeLib   = &H4
%COMAdminInUseByRegistryClsid     = &H5


' ########################################################################################
' Interface name = ICOMAdminCatalog2
' IID = {790C6E0B-9194-4CC9-9426-A48A63185696}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ICOMAdminCatalog
' ########################################################################################

#IF NOT %DEF(%COMAdmin_ICOMAdminCatalog2_INTERFACE_DEFINED)
    %COMAdmin_ICOMAdminCatalog2_INTERFACE_DEFINED = 1

INTERFACE COMAdmin_ICOMAdminCatalog2 $IID_COMAdmin_ICOMAdminCatalog2

   INHERIT IDispatch

   ' =====================================================================================
   ' ICOMAdminCatalog Methods
   ' =====================================================================================
   METHOD GetCollection <1> ( _                         ' VTable offset = 28
     BYVAL bstrCollName AS WSTRING _                    ' __in BSTR bstrCollName
   ) AS IDispatch                                       ' __retval_out IDispatch **ppCatalogCollection
   ' =====================================================================================
   METHOD Connect <2> ( _                               ' VTable offset = 32
     BYVAL bstrCatalogServerName AS WSTRING _           ' __in BSTR bstrCatalogServerName
   ) AS IDispatch                                       ' __retval_out IDispatch **ppCatalogCollection
   ' =====================================================================================
   PROPERTY GET MajorVersion <3> ( _                    ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plMajorVersion
   ' =====================================================================================
   PROPERTY GET MinorVersion <4> ( _                    ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plMinorVersion
   ' =====================================================================================
   METHOD GetCollectionByQuery <5> ( _                  ' VTable offset = 44
     BYVAL bstrCollName AS WSTRING _                    ' __in BSTR bstrCollName
   , BYVAL ppsaVarQuery AS DWORD _                      ' __in SAFEARRAY * *ppsaVarQuery
   ) AS IDispatch                                       ' __retval_out IDispatch **ppCatalogCollection
   ' =====================================================================================
   METHOD ImportComponent <6> ( _                       ' VTable offset = 48
     BYVAL bstrApplIDOrName AS WSTRING _                ' __in BSTR bstrApplIDOrName
   , BYVAL bstrCLSIDOrProgID AS WSTRING _               ' __in BSTR bstrCLSIDOrProgID
   )                                                    ' void
   ' =====================================================================================
   METHOD InstallComponent <7> ( _                      ' VTable offset = 52
     BYVAL bstrApplIDOrName AS WSTRING _                ' __in BSTR bstrApplIDOrName
   , BYVAL bstrDLL AS WSTRING _                         ' __in BSTR bstrDLL
   , BYVAL bstrTLB AS WSTRING _                         ' __in BSTR bstrTLB
   , BYVAL bstrPSDLL AS WSTRING _                       ' __in BSTR bstrPSDLL
   )                                                    ' void
   ' =====================================================================================
   METHOD ShutdownApplication <8> ( _                   ' VTable offset = 56
     BYVAL bstrApplIDOrName AS WSTRING _                ' __in BSTR bstrApplIDOrName
   )                                                    ' void
   ' =====================================================================================
   METHOD ExportApplication <9> ( _                     ' VTable offset = 60
     BYVAL bstrApplIDOrName AS WSTRING _                ' __in BSTR bstrApplIDOrName
   , BYVAL bstrApplicationFile AS WSTRING _             ' __in BSTR bstrApplicationFile
   , BYVAL lOptions AS LONG _                           ' __in long lOptions
   )                                                    ' void
   ' =====================================================================================
   METHOD InstallApplication <10> ( _                   ' VTable offset = 64
     BYVAL bstrApplicationFile AS WSTRING _             ' __in BSTR bstrApplicationFile
   , OPTIONAL BYVAL bstrDestinationDirectory AS WSTRING _ ' __opt_in BSTR bstrDestinationDirectory
   , OPTIONAL BYVAL lOptions AS LONG _                  ' __opt_in long lOptions
   , OPTIONAL BYVAL bstrUserId AS WSTRING _             ' __opt_in BSTR bstrUserId
   , OPTIONAL BYVAL bstrPassword AS WSTRING _           ' __opt_in BSTR bstrPassword
   , OPTIONAL BYVAL bstrRSN AS WSTRING _                ' __opt_in BSTR bstrRSN
   )                                                    ' void
   ' =====================================================================================
   METHOD StopRouter <11> ( _                           ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   METHOD RefreshRouter <12> ( _                        ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================
   METHOD StartRouter <13> ( _                          ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================
   METHOD Reserved1 <14> ( _                            ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   METHOD Reserved2 <15> ( _                            ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD InstallMultipleComponents <16> ( _            ' VTable offset = 88
     BYVAL bstrApplIDOrName AS WSTRING _                ' __in BSTR bstrApplIDOrName
   , BYVAL ppsaVarFileNames AS DWORD _                  ' __in SAFEARRAY * *ppsaVarFileNames
   , BYVAL ppsaVarCLSIDs AS DWORD _                     ' __in SAFEARRAY * *ppsaVarCLSIDs
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMultipleComponentsInfo <17> ( _            ' VTable offset = 92
     BYVAL bstrApplIdOrName AS WSTRING _                ' __in BSTR bstrApplIdOrName
   , BYVAL ppsaVarFileNames AS DWORD _                  ' __in SAFEARRAY * *ppsaVarFileNames
   , BYREF ppsaVarCLSIDs AS DWORD _                     ' __out SAFEARRAY * *ppsaVarCLSIDs
   , BYREF ppsaVarClassNames AS DWORD _                 ' __out SAFEARRAY * *ppsaVarClassNames
   , BYREF ppsaVarFileFlags AS DWORD _                  ' __out SAFEARRAY * *ppsaVarFileFlags
   , BYREF ppsaVarComponentFlags AS DWORD _             ' __out SAFEARRAY * *ppsaVarComponentFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD RefreshComponents <18> ( _                    ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD BackupREGDB <19> ( _                          ' VTable offset = 100
     BYVAL bstrBackupFilePath AS WSTRING _              ' __in BSTR bstrBackupFilePath
   )                                                    ' void
   ' =====================================================================================
   METHOD RestoreREGDB <20> ( _                         ' VTable offset = 104
     BYVAL bstrBackupFilePath AS WSTRING _              ' __in BSTR bstrBackupFilePath
   )                                                    ' void
   ' =====================================================================================
   METHOD QueryApplicationFile <21> ( _                 ' VTable offset = 108
     BYVAL bstrApplicationFile AS WSTRING _             ' __in BSTR bstrApplicationFile
   , BYREF pbstrApplicationName AS WSTRING _            ' __out BSTR *pbstrApplicationName
   , BYREF pbstrApplicationDescription AS WSTRING _     ' __out BSTR *pbstrApplicationDescription
   , BYREF pbHasUsers AS INTEGER _                      ' __out VARIANT_BOOL *pbHasUsers
   , BYREF pbIsProxy AS INTEGER _                       ' __out VARIANT_BOOL *pbIsProxy
   , BYREF ppsaVarFileNames AS DWORD _                  ' __out SAFEARRAY * *ppsaVarFileNames
   )                                                    ' void
   ' =====================================================================================
   METHOD StartApplication <22> ( _                     ' VTable offset = 112
     BYVAL bstrApplIdOrName AS WSTRING _                ' __in BSTR bstrApplIdOrName
   )                                                    ' void
   ' =====================================================================================
   METHOD ServiceCheck <23> ( _                         ' VTable offset = 116
     BYVAL lService AS LONG _                           ' __in long lService
   ) AS LONG                                            ' __retval_out long *plStatus
   ' =====================================================================================
   METHOD InstallMultipleEventClasses <24> ( _          ' VTable offset = 120
     BYVAL bstrApplIdOrName AS WSTRING _                ' __in BSTR bstrApplIdOrName
   , BYVAL ppsaVarFileNames AS DWORD _                  ' __in SAFEARRAY * *ppsaVarFileNames
   , BYVAL ppsaVarCLSIDS AS DWORD _                     ' __in SAFEARRAY * *ppsaVarCLSIDS
   )                                                    ' void
   ' =====================================================================================
   METHOD InstallEventClass <25> ( _                    ' VTable offset = 124
     BYVAL bstrApplIdOrName AS WSTRING _                ' __in BSTR bstrApplIdOrName
   , BYVAL bstrDLL AS WSTRING _                         ' __in BSTR bstrDLL
   , BYVAL bstrTLB AS WSTRING _                         ' __in BSTR bstrTLB
   , BYVAL bstrPSDLL AS WSTRING _                       ' __in BSTR bstrPSDLL
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEventClassesForIID <26> ( _                ' VTable offset = 128
     BYVAL bstrIID AS WSTRING _                         ' __in BSTR bstrIID
   , BYREF ppsaVarCLSIDs AS WORD _                      ' __out SAFEARRAY * *ppsaVarCLSIDs
   , BYREF ppsaVarProgIDs AS DWORD _                    ' __out SAFEARRAY * *ppsaVarProgIDs
   , BYREF ppsaVarDescriptions AS DWORD _               ' __out SAFEARRAY * *ppsaVarDescriptions
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ICOMAdminCatalog2 Methods
   ' =====================================================================================
   METHOD GetCollectionByQuery2 <27> ( _                ' VTable offset = 132
     BYVAL bstrCollectionName AS WSTRING _              ' __in BSTR bstrCollectionName
   , BYREF pVarQueryStrings AS VARIANT _                ' __in VARIANT *pVarQueryStrings
   ) AS IDispatch                                       ' __retval_out IDispatch **ppCatalogCollection
   ' =====================================================================================
   METHOD GetApplicationInstanceIDFromProcessID <28> ( _ ' VTable offset = 136
     BYVAL lProcessID AS LONG _                         ' __in long lProcessID
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrApplicationInstanceID
   ' =====================================================================================
   METHOD ShutdownApplicationInstances <29> ( _         ' VTable offset = 140
     BYREF pVarApplicationInstanceID AS VARIANT _       ' __in VARIANT *pVarApplicationInstanceID
   )                                                    ' void
   ' =====================================================================================
   METHOD PauseApplicationInstances <30> ( _            ' VTable offset = 144
     BYREF pVarApplicationInstanceID AS VARIANT _       ' __in VARIANT *pVarApplicationInstanceID
   )                                                    ' void
   ' =====================================================================================
   METHOD ResumeApplicationInstances <31> ( _           ' VTable offset = 148
     BYREF pVarApplicationInstanceID AS VARIANT _       ' __in VARIANT *pVarApplicationInstanceID
   )                                                    ' void
   ' =====================================================================================
   METHOD RecycleApplicationInstances <32> ( _          ' VTable offset = 152
     BYREF pVarApplicationInstanceID AS VARIANT _       ' __in VARIANT *pVarApplicationInstanceID
   , BYVAL lReasonCode AS LONG _                        ' __in long lReasonCode
   )                                                    ' void
   ' =====================================================================================
   METHOD AreApplicationInstancesPaused <33> ( _        ' VTable offset = 156
     BYREF pVarApplicationInstanceID AS VARIANT _       ' __in VARIANT *pVarApplicationInstanceID
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVarBoolPaused
   ' =====================================================================================
   METHOD DumpApplicationInstance <34> ( _              ' VTable offset = 160
     BYVAL bstrApplicationInstanceID AS WSTRING _       ' __in BSTR bstrApplicationInstanceID
   , BYVAL bstrDirectory AS WSTRING _                   ' __in BSTR bstrDirectory
   , BYVAL lMaxImages AS LONG _                         ' __in long lMaxImages
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDumpFile
   ' =====================================================================================
   PROPERTY GET IsApplicationInstanceDumpSupported <35> ( _ ' VTable offset = 164
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVarBoolDumpSupported
   ' =====================================================================================
   METHOD CreateServiceForApplication <36> ( _          ' VTable offset = 168
     BYVAL bstrApplicationIDOrName AS WSTRING _         ' __in BSTR bstrApplicationIDOrName
   , BYVAL bstrServiceName AS WSTRING _                 ' __in BSTR bstrServiceName
   , BYVAL bstrStartType AS WSTRING _                   ' __in BSTR bstrStartType
   , BYVAL bstrErrorControl AS WSTRING _                ' __in BSTR bstrErrorControl
   , BYVAL bstrDependencies AS WSTRING _                ' __in BSTR bstrDependencies
   , BYVAL bstrRunAs AS WSTRING _                       ' __in BSTR bstrRunAs
   , BYVAL bstrPassword AS WSTRING _                    ' __in BSTR bstrPassword
   , BYVAL bDesktopOk AS INTEGER _                      ' __in VARIANT_BOOL bDesktopOk
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteServiceForApplication <37> ( _          ' VTable offset = 172
     BYVAL bstrApplicationIDOrName AS WSTRING _         ' __in BSTR bstrApplicationIDOrName
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPartitionID <38> ( _                       ' VTable offset = 176
     BYVAL bstrApplicationIDOrName AS WSTRING _         ' __in BSTR bstrApplicationIDOrName
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPartitionID
   ' =====================================================================================
   METHOD GetPartitionName <39> ( _                     ' VTable offset = 180
     BYVAL bstrApplicationIDOrName AS WSTRING _         ' __in BSTR bstrApplicationIDOrName
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPartitionName
   ' =====================================================================================
   PROPERTY SET CurrentPartition <40> ( _               ' VTable offset = 184
     BYVAL bstrPartitionIDOrName AS WSTRING _           ' __in BSTR bstrPartitionIDOrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentPartitionID <41> ( _             ' VTable offset = 188
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPartitionID
   ' =====================================================================================
   PROPERTY GET CurrentPartitionName <42> ( _           ' VTable offset = 192
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPartitionName
   ' =====================================================================================
   PROPERTY GET GlobalPartitionID <43> ( _              ' VTable offset = 196
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrGlobalPartitionID
   ' =====================================================================================
   METHOD FlushPartitionCache <44> ( _                  ' VTable offset = 200
   )                                                    ' void
   ' =====================================================================================
   METHOD CopyApplications <45> ( _                     ' VTable offset = 204
     BYVAL bstrSourcePartitionIDOrName AS WSTRING _     ' __in BSTR bstrSourcePartitionIDOrName
   , BYREF pVarApplicationID AS VARIANT _               ' __in VARIANT *pVarApplicationID
   , BYVAL bstrDestinationPartitionIDOrName AS WSTRING _ ' __in BSTR bstrDestinationPartitionIDOrName
   )                                                    ' void
   ' =====================================================================================
   METHOD CopyComponents <46> ( _                       ' VTable offset = 208
     BYVAL bstrSourceApplicationIDOrName AS WSTRING _   ' __in BSTR bstrSourceApplicationIDOrName
   , BYREF pVarCLSIDOrProgID AS VARIANT _               ' __in VARIANT *pVarCLSIDOrProgID
   , BYVAL bstrDestinationApplicationIDOrName AS WSTRING _ ' __in BSTR bstrDestinationApplicationIDOrName
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveComponents <47> ( _                       ' VTable offset = 212
     BYVAL bstrSourceApplicationIDOrName AS WSTRING _   ' __in BSTR bstrSourceApplicationIDOrName
   , BYREF pVarCLSIDOrProgID AS VARIANT _               ' __in VARIANT *pVarCLSIDOrProgID
   , BYVAL bstrDestinationApplicationIDOrName AS WSTRING _ ' __in BSTR bstrDestinationApplicationIDOrName
   )                                                    ' void
   ' =====================================================================================
   METHOD AliasComponent <48> ( _                       ' VTable offset = 216
     BYVAL bstrSrcApplicationIDOrName AS WSTRING _      ' __in BSTR bstrSrcApplicationIDOrName
   , BYVAL bstrCLSIDOrProgID AS WSTRING _               ' __in BSTR bstrCLSIDOrProgID
   , BYVAL bstrDestApplicationIDOrName AS WSTRING _     ' __in BSTR bstrDestApplicationIDOrName
   , BYVAL bstrNewProgId AS WSTRING _                   ' __in BSTR bstrNewProgId
   , BYVAL bstrNewClsid AS WSTRING _                    ' __in BSTR bstrNewClsid
   )                                                    ' void
   ' =====================================================================================
   METHOD IsSafeToDelete <49> ( _                       ' VTable offset = 220
     BYVAL bstrDllName AS WSTRING _                     ' __in BSTR bstrDllName
   ) AS LONG                                            ' __retval_out COMAdminInUse *pCOMAdminInUse
   ' =====================================================================================
   METHOD ImportUnconfiguredComponents <50> ( _         ' VTable offset = 224
     BYVAL bstrApplicationIDOrName AS WSTRING _         ' __in BSTR bstrApplicationIDOrName
   , BYREF pVarCLSIDOrProgID AS VARIANT _               ' __in VARIANT *pVarCLSIDOrProgID
   , OPTIONAL BYREF pVarComponentType AS VARIANT _      ' __opt_in VARIANT *pVarComponentType
   )                                                    ' void
   ' =====================================================================================
   METHOD PromoteUnconfiguredComponents <51> ( _        ' VTable offset = 228
     BYVAL bstrApplicationIDOrName AS WSTRING _         ' __in BSTR bstrApplicationIDOrName
   , BYREF pVarCLSIDOrProgID AS VARIANT _               ' __in VARIANT *pVarCLSIDOrProgID,
   , OPTIONAL BYREF pVarComponentType AS VARIANT _      ' __opt_in VARIANT *pVarComponentType
   )                                                    ' void
   ' =====================================================================================
   METHOD ImportComponents <52> ( _                     ' VTable offset = 232
     BYVAL bstrApplicationIDOrName AS WSTRING _         ' __in BSTR bstrApplicationIDOrName
   , BYREF pVarCLSIDOrProgID AS VARIANT _               ' __in VARIANT *pVarCLSIDOrProgID
   , OPTIONAL BYREF pVarComponentType AS VARIANT _      ' __opt_in VARIANT *pVarComponentType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Is64BitCatalogServer <53> ( _           ' VTable offset = 236
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbIs64Bit
   ' =====================================================================================
   METHOD ExportPartition <54> ( _                      ' VTable offset = 240
     BYVAL bstrPartitionIDOrName AS WSTRING _           ' __in BSTR bstrPartitionIDOrName
   , BYVAL bstrPartitionFileName AS WSTRING _           ' __in BSTR bstrPartitionFileName
   , BYVAL lOptions AS LONG _                           ' __in long lOptions
   )                                                    ' void
   ' =====================================================================================
   METHOD InstallPartition <55> ( _                     ' VTable offset = 244
     BYVAL bstrFileName AS WSTRING _                    ' __in BSTR bstrFileName
   , BYVAL bstrDestDirectory AS WSTRING _               ' __in BSTR bstrDestDirectory
   , BYVAL lOptions AS LONG _                           ' __in long lOptions
   , BYVAL bstrUserID AS WSTRING _                      ' __in BSTR bstrUserID
   , BYVAL bstrPassword AS WSTRING _                    ' __in BSTR bstrPassword
   , BYVAL bstrRSN AS WSTRING _                         ' __in BSTR bstrRSN
   )                                                    ' void
   ' =====================================================================================
   METHOD QueryApplicationFile2 <56> ( _                ' VTable offset = 248
     BYVAL bstrApplicationFile AS WSTRING _             ' __in BSTR bstrApplicationFile
   ) AS IDispatch                                       ' __retval_out IDispatch **ppFilesForImport
   ' =====================================================================================
   METHOD GetComponentVersionCount <57> ( _             ' VTable offset = 252
     BYVAL bstrCLSIDOrProgID AS WSTRING _               ' __in BSTR bstrCLSIDOrProgID
   ) AS LONG                                            ' __retval_out long *plVersionCount
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __COMAdmin_ICOMAdminCatalog2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICatalogObject
' IID = {6EB22871-8A19-11D0-81B6-00A0C9231C29}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%COMAdmin_ICatalogObject_INTERFACE_DEFINED)
    %COMAdmin_ICatalogObject_INTERFACE_DEFINED = 1

INTERFACE COMAdmin_ICatalogObject $IID_COMAdmin_ICatalogObject

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Value <1> ( _                           ' VTable offset = 28
     BYVAL bstrPropName AS WSTRING _                    ' __in BSTR bstrPropName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarRetVal
   ' =====================================================================================
   PROPERTY SET Value <1> ( _                           ' VTable offset = 32
     BYVAL bstrPropName AS WSTRING _                    ' __in BSTR bstrPropName
   , BYVAL val AS VARIANT _                             ' __in VARIANT val
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Key <2> ( _                             ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarRetVal
   ' =====================================================================================
   PROPERTY GET Name <3> ( _                            ' VTable offset = 40
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarRetVal
   ' =====================================================================================
   METHOD IsPropertyReadOnly <4> ( _                    ' VTable offset = 44
     BYVAL bstrPropName AS WSTRING _                    ' __in BSTR bstrPropName
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbRetVal
   ' =====================================================================================
   PROPERTY GET Valid <5> ( _                           ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbRetVal
   ' =====================================================================================
   METHOD IsPropertyWriteOnly <6> ( _                   ' VTable offset = 52
     BYVAL bstrPropName AS WSTRING _                    ' __in BSTR bstrPropName
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __COMAdmin_ICatalogObject_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICatalogCollection
' IID = {6EB22872-8A19-11D0-81B6-00A0C9231C29}
' COMAdmin_ICatalogCollection Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%COMAdmin_ICatalogCollection_INTERFACE_DEFINED)
    %COMAdmin_ICatalogCollection_INTERFACE_DEFINED = 1

INTERFACE COMAdmin_ICatalogCollection $IID_COMAdmin_ICatalogCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnumVariant
   ' =====================================================================================
   PROPERTY GET Item <1> ( _                            ' VTable offset = 32
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS IDispatch                                       ' __retval_out IDispatch **ppCatalogObject
   ' =====================================================================================
   PROPERTY GET Count <1610743810> ( _                  ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plObjectCount
   ' =====================================================================================
   METHOD Remove <1610743811> ( _                       ' VTable offset = 40
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <1610743812> ( _                          ' VTable offset = 44
   ) AS IDispatch                                       ' __retval_out IDispatch **ppCatalogObject
   ' =====================================================================================
   METHOD Populate <2> ( _                              ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveChanges <3> ( _                           ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *pcChanges
   ' =====================================================================================
   METHOD GetCollection <4> ( _                         ' VTable offset = 56
     BYVAL bstrCollName AS WSTRING _                    ' __in BSTR bstrCollName
   , BYVAL varObjectKey AS VARIANT _                    ' __in VARIANT varObjectKey
   ) AS IDispatch                                       ' __retval_out IDispatch **ppCatalogCollection
   ' =====================================================================================
   PROPERTY GET Name <6> ( _                            ' VTable offset = 60
   ) AS VARIANT                                         ' __retval_out VARIANT *pVarNamel
   ' =====================================================================================
   PROPERTY GET AddEnabled <7> ( _                      ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVarBool
   ' =====================================================================================
   PROPERTY GET RemoveEnabled <8> ( _                   ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVarBool
   ' =====================================================================================
   METHOD GetUtilInterface <9> ( _                      ' VTable offset = 72
   ) AS IDispatch                                       ' __retval_out IDispatch **ppIDispatch
   ' =====================================================================================
   PROPERTY GET DataStoreMajorVersion <10> ( _          ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *plMajorVersion
   ' =====================================================================================
   PROPERTY GET DataStoreMinorVersion <11> ( _          ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *plMinorVersionl
   ' =====================================================================================
   METHOD PopulateByKey <12> ( _                        ' VTable offset = 84
     BYVAL psaKeys AS DWORD _                           ' __in SAFEARRAY *psaKeys
   )                                                    ' void
   ' =====================================================================================
   METHOD PopulateByQuery <13> ( _                      ' VTable offset = 88
     BYVAL bstrQueryString AS WSTRING _                 ' __in BSTR bstrQueryString
   , BYVAL lQueryType AS LONG _                         ' __in long lQueryType
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __COMAdmin_ICatalogCollection_INTERFACE_DEFINED__ */

' ========================================================================================
' COMAdminComponentType enum
' ComponentType values for ImportComponentAsLegacy
' ========================================================================================

%COMAdmin32BitComponent = &H1???
%COMAdmin64BitComponent = &H2???

' ========================================================================================
' COMAdminApplicationInstallOptions enum
' Application install options - these options can be or'ed together
' ========================================================================================

%COMAdminInstallNoUsers               = 0
%COMAdminInstallUsers                 = 1
%COMAdminInstallForceOverwriteOfFiles = 2

' ========================================================================================
' COMAdminApplicationExportOptions enum
' Application export options - these options can be or'ed together
' ========================================================================================

%COMAdminExportNoUsers               = 0
%COMAdminExportUsers                 = 1
%COMAdminExportApplicationProxy      = 2
%COMAdminExportForceOverwriteOfFiles = 4
%COMAdminExportIn10Format            = 16

' ========================================================================================
' COMAdminThreadingModels enum
' Threading Model Enumerations
' ========================================================================================

%COMAdminThreadingModelApartment    = 0
%COMAdminThreadingModelFree         = 1
%COMAdminThreadingModelMain         = 2
%COMAdminThreadingModelBoth         = 3
%COMAdminThreadingModelNeutral      = 4
%COMAdminThreadingModelNotSpecified = 5

' ========================================================================================
' COMAdminTransactionOptions enum
' Transaction Settings Enumerations
' ========================================================================================

%COMAdminTransactionIgnored     = 0
%COMAdminTransactionNone        = 1
%COMAdminTransactionSupported   = 2
%COMAdminTransactionRequired    = 3
%COMAdminTransactionRequiresNew = 4

' ========================================================================================
' COMAdminTxIsolationLevelOptions enum
' Transaction Isolation Level Enumerations
' ========================================================================================

%COMAdminTxIsolationLevelAny             = 0
%COMAdminTxIsolationLevelReadUnCommitted = %COMAdminTxIsolationLevelAny             + 1
%COMAdminTxIsolationLevelReadCommitted   = %COMAdminTxIsolationLevelReadUnCommitted + 1
%COMAdminTxIsolationLevelRepeatableRead  = %COMAdminTxIsolationLevelReadCommitted   + 1
%COMAdminTxIsolationLevelSerializable    = %COMAdminTxIsolationLevelRepeatableRead  + 1

' ========================================================================================
' COMAdminSynchronizationOptions enum
' Synchronization Settings Enumerations
' ========================================================================================

%COMAdminSynchronizationIgnored     = 0
%COMAdminSynchronizationNone        = 1
%COMAdminSynchronizationSupported   = 2
%COMAdminSynchronizationRequired    = 3
%COMAdminSynchronizationRequiresNew = 4

' ========================================================================================
' COMAdminActivationOptions enum
' Activation Settings Enumerations
' ========================================================================================

%COMAdminActivationInproc = 0
%COMAdminActivationLocal  = 1

' ========================================================================================
' COMAdminAccessChecksLevelOptions enum
' Access Level Settings Enumerations
' ========================================================================================

%COMAdminAccessChecksApplicationLevel          = 0
%COMAdminAccessChecksApplicationComponentLevel = 1

' ========================================================================================
' COMAdminAuthenticationLevelOptions enum
' Authentication Level Settings Enumerations
' ========================================================================================

%COMAdminAuthenticationDefault   = 0
%COMAdminAuthenticationNone      = 1
%COMAdminAuthenticationConnect   = 2
%COMAdminAuthenticationCall      = 3
%COMAdminAuthenticationPacket    = 4
%COMAdminAuthenticationIntegrity = 5
%COMAdminAuthenticationPrivacy   = 6

' ========================================================================================
' COMAdminImpersonationLevelOptions enum
' Impersonation Level Settings Enumerations
' ========================================================================================

%COMAdminImpersonationAnonymous   = 1
%COMAdminImpersonationIdentify    = 2
%COMAdminImpersonationImpersonate = 3
%COMAdminImpersonationDelegate    = 4

' ========================================================================================
' COMAdminAuthenticationCapabilitiesOptions enum
' Authentication Capabilities Settings Enumerations
' ========================================================================================

%COMAdminAuthenticationCapabilitiesNone            = 0???
%COMAdminAuthenticationCapabilitiesSecureReference = &H2???
%COMAdminAuthenticationCapabilitiesStaticCloaking  = &H20???
%COMAdminAuthenticationCapabilitiesDynamicCloaking = &H40???

' ========================================================================================
' COMAdminOS enum
' Operating System Enumerations
' ========================================================================================

%COMAdminOSNotInitialized                  = 0
%COMAdminOSWindows3_1                      = 1
%COMAdminOSWindows9x                       = 2
%COMAdminOSWindows2000                     = 3
%COMAdminOSWindows2000AdvancedServer       = 4
%COMAdminOSWindows2000Unknown              = 5
%COMAdminOSUnknown                         = 6
%COMAdminOSWindowsXPPersonal               = 11
%COMAdminOSWindowsXPProfessional           = 12
%COMAdminOSWindowsNETStandardServer        = 13
%COMAdminOSWindowsNETEnterpriseServer      = 14
%COMAdminOSWindowsNETDatacenterServer      = 15
%COMAdminOSWindowsNETWebServer             = 16
%COMAdminOSWindowsLonghornPersonal         = 17
%COMAdminOSWindowsLonghornProfessional     = 18
%COMAdminOSWindowsLonghornStandardServer   = 19
%COMAdminOSWindowsLonghornEnterpriseServer = 20
%COMAdminOSWindowsLonghornDatacenterServer = 21
%COMAdminOSWindowsLonghornWebServer        = 22
%COMAdminOSWindows7Personal                = 23
%COMAdminOSWindows7Professional            = 24
%COMAdminOSWindows7StandardServer          = 25
%COMAdminOSWindows7EnterpriseServer        = 26
%COMAdminOSWindows7DatacenterServer        = 27
%COMAdminOSWindows7WebServer               = 28

' ========================================================================================
' COMAdminServiceOptions enum
' Service Enumerations
' ========================================================================================

%COMAdminServiceLoadBalanceRouter = 1

' ========================================================================================
' COMAdminServiceStatusOptions enum
' Service Status Enumerations
' ========================================================================================

%COMAdminServiceStopped         = 0
%COMAdminServiceStartPending    = %COMAdminServiceStopped         + 1
%COMAdminServiceStopPending     = %COMAdminServiceStartPending    + 1
%COMAdminServiceRunning         = %COMAdminServiceStopPending     + 1
%COMAdminServiceContinuePending = %COMAdminServiceRunning         + 1
%COMAdminServicePausePending    = %COMAdminServiceContinuePending + 1
%COMAdminServicePaused          = %COMAdminServicePausePending    + 1
%COMAdminServiceUnknownState    = %COMAdminServicePaused          + 1

' ========================================================================================
' COMAdminQCMessageAuthenticateOptions enum
' Queued Components Message Authenticate Enumeration
' ========================================================================================

%COMAdminQCMessageAuthenticateSecureApps = 0
%COMAdminQCMessageAuthenticateOff        = 1
%COMAdminQCMessageAuthenticateOn         = 2

' ========================================================================================
' COMAdminFileFlags enum
' File Flags
' ========================================================================================

%COMAdminFileFlagLoadable                               = &H1???       ' 1
%COMAdminFileFlagCOM                                    = &H2???       ' 2
%COMAdminFileFlagContainsPS                             = &H4???       ' 4
%COMAdminFileFlagContainsComp                           = &H8???       ' 8
%COMAdminFileFlagContainsTLB                            = &H10???      ' 16
%COMAdminFileFlagSelfReg                                = &H20???      ' 32
%COMAdminFileFlagSelfUnReg                              = &H40???      ' 64
%COMAdminFileFlagUnloadableDLL                          = &H80???      ' 128
%COMAdminFileFlagDoesNotExist                           = &H100???     ' 256
%COMAdminFileFlagAlreadyInstalled                       = &H200???     ' 512
%COMAdminFileFlagBadTLB                                 = &H400???     ' 1024
%COMAdminFileFlagGetClassObjFailed                      = &H800???     ' 2048
%COMAdminFileFlagClassNotAvailable                      = &H1000???    ' 4096
%COMAdminFileFlagRegistrar                              = &H2000???    ' 8192
%COMAdminFileFlagNoRegistrar                            = &H4000???    ' 16384
%COMAdminFileFlagDLLRegsvrFailed                        = &H8000???    ' 32768
%COMAdminFileFlagRegTLBFailed                           = &H10000???   ' 65536
%COMAdminFileFlagRegistrarFailed                        = &H20000???   ' 131072
%COMAdminFileFlagError                                  = &H40000???   ' 262144

' ========================================================================================
' COMAdminComponentFlags enum
' Component Flags
' ========================================================================================

%COMAdminCompFlagTypeInfoFound                          = &H1???       ' 1
%COMAdminCompFlagCOMPlusPropertiesFound                 = &H2???       ' 2
%COMAdminCompFlagProxyFound                             = &H4???       ' 4
%COMAdminCompFlagInterfacesFound                        = &H8???       ' 8
%COMAdminCompFlagAlreadyInstalled                       = &H10???      ' 16
%COMAdminCompFlagNotInApplication                       = &H20???      ' 32

' ========================================================================================
' COMAdminComponentFlags enum
' Component Flags
' ========================================================================================

%COMAdminCompFlagTypeInfoFound                          = &H1???       ' 1
%COMAdminCompFlagCOMPlusPropertiesFound                 = &H2???       ' 2
%COMAdminCompFlagProxyFound                             = &H4???       ' 4
%COMAdminCompFlagInterfacesFound                        = &H8???       ' 8
%COMAdminCompFlagAlreadyInstalled                       = &H10???      ' 16
%COMAdminCompFlagNotInApplication                       = &H20???      ' 32

$COMAdminCollectionRoot                   = "Root"
$COMAdminCollectionApplications           = "Applications"
$COMAdminCollectionComponents             = "Components"
$COMAdminCollectionComputerList           = "ComputerList"
$COMAdminCollectionApplicationCluster     = "ApplicationCluster"
$COMAdminCollectionLocalComputer          = "LocalComputer"
$COMAdminCollectionInprocServers          = "InprocServers"
$COMAdminCollectionRelatedCollectionInfo  = "RelatedCollectionInfo"
$COMAdminCollectionPropertyInfo           = "PropertyInfo"
$COMAdminCollectionRoles                  = "Roles"
$COMAdminCollectionErrorInfo              = "ErrorInfo"
$COMAdminCollectionInterfacesForComponent = "InterfacesForComponent"
$COMAdminCollectionRolesForComponent      = "RolesForComponent"
$COMAdminCollectionMethodsForInterface    = "MethodsForInterface"
$COMAdminCollectionRolesForInterface      = "RolesForInterface"
$COMAdminCollectionRolesForMethod         = "RolesForMethod"
$COMAdminCollectionUsersInRole            = "UsersInRole"
$COMAdminCollectionDCOMProtocols          = "DCOMProtocols"
$COMAdminCollectionPartitions             = "Partitions"

' ========================================================================================
' COMAdminErrorCodes enum
' Error codes (HRESULTS)
' ========================================================================================

%COMAdminErrObjectErrors                                = -2146368511&  ' &H80110401
%COMAdminErrObjectInvalid                               = -2146368510&  ' &H80110402
%COMAdminErrKeyMissing                                  = -2146368509&  ' &H80110403
%COMAdminErrAlreadyInstalled                            = -2146368508&  ' &H80110404
%COMAdminErrAppFileWriteFail                            = -2146368505&  ' &H80110407
%COMAdminErrAppFileReadFail                             = -2146368504&  ' &H80110408
%COMAdminErrAppFileVersion                              = -2146368503&  ' &H80110409
%COMAdminErrBadPath                                     = -2146368502&  ' &H8011040A
%COMAdminErrApplicationExists                           = -2146368501&  ' &H8011040B
%COMAdminErrRoleExists                                  = -2146368500&  ' &H8011040C
%COMAdminErrCantCopyFile                                = -2146368499&  ' &H8011040D
%COMAdminErrNoUser                                      = -2146368497&  ' &H8011040F
%COMAdminErrInvalidUserids                              = -2146368496&  ' &H80110410
%COMAdminErrNoRegistryCLSID                             = -2146368495&  ' &H80110411
%COMAdminErrBadRegistryProgID                           = -2146368494&  ' &H80110412
%COMAdminErrAuthenticationLevel                         = -2146368493&  ' &H80110413
%COMAdminErrUserPasswdNotValid                          = -2146368492&  ' &H80110414
%COMAdminErrCLSIDOrIIDMismatch                          = -2146368488&  ' &H80110418
%COMAdminErrRemoteInterface                             = -2146368487&  ' &H80110419
%COMAdminErrDllRegisterServer                           = -2146368486&  ' &H8011041A
%COMAdminErrNoServerShare                               = -2146368485&  ' &H8011041B
%COMAdminErrDllLoadFailed                               = -2146368483&  ' &H8011041D
%COMAdminErrBadRegistryLibID                            = -2146368482&  ' &H8011041E
%COMAdminErrAppDirNotFound                              = -2146368481&  ' &H8011041F
%COMAdminErrRegistrarFailed                             = -2146368477&  ' &H80110423
%COMAdminErrCompFileDoesNotExist                        = -2146368476&  ' &H80110424
%COMAdminErrCompFileLoadDLLFail                         = -2146368475&  ' &H80110425
%COMAdminErrCompFileGetClassObj                         = -2146368474&  ' &H80110426
%COMAdminErrCompFileClassNotAvail                       = -2146368473&  ' &H80110427
%COMAdminErrCompFileBadTLB                              = -2146368472&  ' &H80110428
%COMAdminErrCompFileNotInstallable                      = -2146368471&  ' &H80110429
%COMAdminErrNotChangeable                               = -2146368470&  ' &H8011042A
%COMAdminErrNotDeletable                                = -2146368469&  ' &H8011042B
%COMAdminErrSession                                     = -2146368468&  ' &H8011042C
%COMAdminErrCompMoveLocked                              = -2146368467&  ' &H8011042D
%COMAdminErrCompMoveBadDest                             = -2146368466&  ' &H8011042E
%COMAdminErrRegisterTLB                                 = -2146368464&  ' &H80110430
%COMAdminErrSystemApp                                   = -2146368461&  ' &H80110433
%COMAdminErrCompFileNoRegistrar                         = -2146368460&  ' &H80110434
%COMAdminErrCoReqCompInstalled                          = -2146368459&  ' &H80110435
%COMAdminErrServiceNotInstalled                         = -2146368458&  ' &H80110436
%COMAdminErrPropertySaveFailed                          = -2146368457&  ' &H80110437
%COMAdminErrObjectExists                                = -2146368456&  ' &H80110438
%COMAdminErrComponentExists                             = -2146368455&  ' &H80110439
%COMAdminErrRegFileCorrupt                              = -2146368453&  ' &H8011043B
%COMAdminErrPropertyOverflow                            = -2146368452&  ' &H8011043C
%COMAdminErrNotInRegistry                               = -2146368450&  ' &H8011043E
%COMAdminErrObjectNotPoolable                           = -2146368449&  ' &H8011043F
%COMAdminErrApplidMatchesClsid                          = -2146368442&  ' &H80110446
%COMAdminErrRoleDoesNotExist                            = -2146368441&  ' &H80110447
%COMAdminErrStartAppNeedsComponents                     = -2146368440&  ' &H80110448
%COMAdminErrRequiresDifferentPlatform                   = -2146368439&  ' &H80110449
%COMAdminErrQueuingServiceNotAvailable                  = -2146367998&  ' &H80110602
%COMAdminErrObjectParentMissing                         = -2146367480&  ' &H80110808
%COMAdminErrObjectDoesNotExist                          = -2146367479&  ' &H80110809
%COMAdminErrCanNotExportAppProxy                        = -2146368438&  ' &H8011044A
%COMAdminErrCanNotStartApp                              = -2146368437&  ' &H8011044B
%COMAdminErrCanNotExportSystemApp                       = -2146368436&  ' &H8011044C
%COMAdminErrCanNotSubscribeToComponent                  = -2146368435&  ' &H8011044D
%COMAdminErrAppNotRunning                               = -2146367478&  ' &H8011080A
%COMAdminErrEventClassCannotBeSubscriber                = -2146368434&  ' &H8011044E
%COMAdminErrLibAppProxyIncompatible                     = -2146368433&  ' &H8011044F
%COMAdminErrBasePartitionOnly                           = -2146368432&  ' &H80110450
%COMAdminErrDuplicatePartitionName                      = -2146368425&  ' &H80110457
%COMAdminErrPartitionInUse                              = -2146368423&  ' &H80110459
%COMAdminErrImportedComponentsNotAllowed                = -2146368421&  ' &H8011045B
%COMAdminErrRegdbNotInitialized                         = -2146368398&  ' &H80110472
%COMAdminErrRegdbNotOpen                                = -2146368397&  ' &H80110473
%COMAdminErrRegdbSystemErr                              = -2146368396&  ' &H80110474
%COMAdminErrRegdbAlreadyRunning                         = -2146368395&  ' &H80110475
%COMAdminErrMigVersionNotSupported                      = -2146368384&  ' &H80110480
%COMAdminErrMigSchemaNotFound                           = -2146368383&  ' &H80110481
%COMAdminErrCatBitnessMismatch                          = -2146368382&  ' &H80110482
%COMAdminErrCatUnacceptableBitness                      = -2146368381&  ' &H80110483
%COMAdminErrCatWrongAppBitnessBitness                   = -2146368380&  ' &H80110484
%COMAdminErrCatPauseResumeNotSupported                  = -2146368379&  ' &H80110485
%COMAdminErrCatServerFault                              = -2146368378&  ' &H80110486
%COMAdminErrCantRecycleLibraryApps                      = -2146367473&  ' &H8011080F
%COMAdminErrCantRecycleServiceApps                      = -2146367471&  ' &H80110811
%COMAdminErrProcessAlreadyRecycled                      = -2146367470&  ' &H80110812
%COMAdminErrPausedProcessMayNotBeRecycled               = -2146367469&  ' &H80110813
%COMAdminErrInvalidPartition                            = -2146367477&  ' &H8011080B
%COMAdminErrPartitionMsiOnly                            = -2146367463&  ' &H80110819
%COMAdminErrStartAppDisabled                            = -2146368431&  ' &H80110451
%COMAdminErrCompMoveSource                              = -2146367460&  ' &H8011081C
%COMAdminErrCompMoveDest                                = -2146367459&  ' &H8011081D
%COMAdminErrCompMovePrivate                             = -2146367458&  ' &H8011081E
%COMAdminErrCannotCopyEventClass                        = -2146367456&  ' &H80110820
