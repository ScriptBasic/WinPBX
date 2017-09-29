' ########################################################################################
' Microsoft Windows
' File: WinBio.inc
' Contents: WinBio public API
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

'#ifndef _WINBIO_H_9B9AD1F6_97B1_4647_923D_583FD7428C4C_
'#define _WINBIO_H_9B9AD1F6_97B1_4647_923D_583FD7428C4C_

#INCLUDE THIS ONCE
%WINBIO_INC = 1

'#if (NTDDI_VERSION >= NTDDI_WIN7)

'//
'// Dependencies...
'//
#INCLUDE ONCE "winbio_types.inc"
#INCLUDE ONCE "winbio_err.inc"

'///////////////////////////////////////////////////////////////////////////////
'//
'// Capability discovery
'//
'///////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION WinBioEnumServiceProviders IMPORT "Winbio.dll" ALIAS "WinBioEnumServiceProviders" ( _
   BYVAL Factor AS DWORD _                              ' __in WINBIO_BIOMETRIC_TYPE Factor
 , BYREF BspSchemaArray AS WINBIO_BSP_SCHEMA _          ' __deref_out_ecount(*BspCount) WINBIO_BSP_SCHEMA **BspSchemaArray
 , BYREF BspCount AS DWORD _                            ' __out SIZE_T *BspCount
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WinBioEnumBiometricUnits IMPORT "Winbio.dll" ALIAS "WinBioEnumBiometricUnits" ( _
   BYVAL Factor AS DWORD _                              ' __in WINBIO_BIOMETRIC_TYPE Factor
 , BYREF UnitSchemaArray AS WINBIO_UNIT_SCHEMA _        ' __deref_out_ecount(*UnitCount) WINBIO_UNIT_SCHEMA **UnitSchemaArray
 , BYREF UnitCount AS DWORD _                           ' __out SIZE_T *UnitCount
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WinBioEnumDatabases IMPORT "Winbio.dll" ALIAS "WinBioEnumDatabases" ( _
   BYVAL Factor AS DWORD _                              ' __in WINBIO_BIOMETRIC_TYPE Factor
 , BYREF StorageSchemaArray AS WINBIO_STORAGE_SCHEMA _  ' __deref_out_ecount(*StorageCount) WINBIO_STORAGE_SCHEMA **StorageSchemaArray
 , BYREF StorageCount AS DWORD _                        ' __out SIZE_T *StorageCount
 ) AS LONG                                              ' HRESULT

'///////////////////////////////////////////////////////////////////////////////
'//
'// Session management
'//
'///////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION WinBioOpenSession IMPORT "Winbio.dll" ALIAS "WinBioOpenSession" ( _
   BYVAL Factor AS DWORD _                              ' __in WINBIO_BIOMETRIC_TYPE Factor
 , BYVAL PoolType AS DWORD _                            ' __in WINBIO_POOL_TYPE PoolType
 , BYVAL Flags AS DWORD _                               ' __in WINBIO_SESSION_FLAGS Flags
 , BYREF UnitArray AS DWORD _                           ' __in_ecount_opt(UnitCount) WINBIO_UNIT_ID *UnitArray
 , BYVAL UnitCount AS DWORD _                           ' __in_opt SIZE_T UnitCount
 , BYREF DatabaseId AS GUID _                           ' __in_opt GUID *DatabaseId
 , BYREF SessionHandle AS DWORD _                       ' __out WINBIO_SESSION_HANDLE *SessionHandle
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WinBioCloseSession IMPORT "Winbio.dll" ALIAS "WinBioCloseSession" ( _
   BYVAL SessionHandle AS DWORD _                       ' __in WINBIO_SESSION_HANDLE SessionHandle
 ) AS LONG                                              ' HRESULT

'///////////////////////////////////////////////////////////////////////////////
'//
'// High-level biometric operations
'//
'///////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION WinBioVerify IMPORT "Winbio.dll" ALIAS "WinBioVerify" ( _
   BYVAL SessionHandle AS DWORD _                       ' __in WINBIO_SESSION_HANDLE SessionHandle
 , BYREF Identity AS WINBIO_IDENTITY _                  ' __in WINBIO_IDENTITY *Identity
 , BYVAL SubFactor AS BYTE _                            ' __in WINBIO_BIOMETRIC_SUBTYPE SubFactor
 , BYREF UnitId AS DWORD _                              ' __out WINBIO_UNIT_ID *UnitId
 , BYREF Match AS BYTE _                                ' __out BOOLEAN *Match
 , BYREF RejectDetail AS DWORD _                        ' __out WINBIO_REJECT_DETAIL *RejectDetail
 ) AS LONG                                              ' HRESULT

'typedef
'VOID
'(CALLBACK *PWINBIO_VERIFY_CALLBACK)(
'    __in_opt PVOID VerifyCallbackContext,
'    __in HRESULT OperationStatus,
'    __in WINBIO_UNIT_ID UnitId,
'    __in BOOLEAN Match,
'    __in WINBIO_REJECT_DETAIL RejectDetail
'    );

'SUB WINBIO_VERIFY_CALLBACK ( _
'   BYVAL VerifyCallbackContext AS DWORD _               ' __in_opt PVOID VerifyCallbackContext
' , BYVAL OperationStatus AS LONG _                      ' __in HRESULT OperationStatus
' , BYVAL UnitId AS DWORD _                              ' __in WINBIO_UNIT_ID UnitId
' , BYVAL Match AS BYTE _                                ' __in BOOLEAN Match
' , BYVAL RejectDetail AS DWORD _                        ' __in WINBIO_REJECT_DETAIL RejectDetail
' )                                                      ' VOID

DECLARE FUNCTION WinBioVerifyWithCallback IMPORT "Winbio.dll" ALIAS "WinBioVerifyWithCallback" ( _
   BYVAL SessionHandle AS DWORD _                       ' __in WINBIO_SESSION_HANDLE SessionHandle
 , BYREF Identity AS WINBIO_IDENTITY _                  ' __in WINBIO_IDENTITY *Identity
 , BYVAL SubFactor AS BYTE _                            ' __in WINBIO_BIOMETRIC_SUBTYPE SubFactor
 , BYVAL VerifyCallback AS DWORD _                      ' __in PWINBIO_VERIFY_CALLBACK VerifyCallback
 , OPTIONAL BYVAL VerifyCallbackContext AS DWORD _      ' __in_opt PVOID VerifyCallbackContext
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WinBioIdentify IMPORT "Winbio.dll" ALIAS "WinBioIdentify" ( _
   BYVAL SessionHandle AS DWORD _                       ' __in WINBIO_SESSION_HANDLE SessionHandle
 , BYVAL UnitId AS DWORD _                              ' __out WINBIO_UNIT_ID *UnitId
 , BYREF Identity AS WINBIO_IDENTITY _                  ' __out WINBIO_IDENTITY *Identity
 , BYREF SubFactor AS BYTE _                            ' __out WINBIO_BIOMETRIC_SUBTYPE *SubFactor
 , BYREF RejectDetail AS DWORD _                        ' __out WINBIO_REJECT_DETAIL *RejectDetail
 ) AS LONG                                              ' HRESULT

'typedef
'VOID
'(CALLBACK *PWINBIO_IDENTIFY_CALLBACK)(
'    __in_opt PVOID IdentifyCallbackContext,
'    __in HRESULT OperationStatus,
'    __in WINBIO_UNIT_ID UnitId,
'    __in WINBIO_IDENTITY *Identity,
'    __in WINBIO_BIOMETRIC_SUBTYPE SubFactor,
'    __in WINBIO_REJECT_DETAIL RejectDetail
'    );

'SUB WINBIO_IDENTIFY_CALLBACK ( _
'   BYVAL IdentifyCallbackContext AS DWORD _             ' __in_opt PVOID IdentifyCallbackContext
' , BYVAL OperationStatus AS LONG _                      ' __in HRESULT OperationStatus
' , BYVAL UnitId AS DWORD _                              ' __in WINBIO_UNIT_ID UnitId
' , BYREF Identity AS WINBIO_IDENTITY _                  ' __in WINBIO_IDENTITY *Identity
' , BYVAL SubFactor AS BYTE _                            ' __in WINBIO_BIOMETRIC_SUBTYPE SubFactor
' , BYVAL RejectDetail AS DWORD _                        ' __in WINBIO_REJECT_DETAIL RejectDetail
' )                                                      ' VOID

DECLARE FUNCTION WinBioIdentifyWithCallback IMPORT "Winbio.dll" ALIAS "WinBioIdentifyWithCallback" ( _
   BYVAL SessionHandle AS DWORD _                       ' __in WINBIO_SESSION_HANDLE SessionHandle
 , BYVAL IdentifyCallback AS DWORD _                    ' __in PWINBIO_IDENTIFY_CALLBACK IdentifyCallback
 , OPTIONAL BYVAL IdentifyCallbackContext AS DWORD _    ' __in_opt PVOID IdentifyCallbackContext
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WinBioWait IMPORT "Winbio.dll" ALIAS "WinBioWait" ( _
   BYVAL SessionHandle AS DWORD _                       ' __in WINBIO_SESSION_HANDLE SessionHandle
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WinBioCancel IMPORT "Winbio.dll" ALIAS "WinBioCancel" ( _
   BYVAL SessionHandle AS DWORD _                       ' __in WINBIO_SESSION_HANDLE SessionHandle
 ) AS LONG                                              ' HRESULT

'///////////////////////////////////////////////////////////////////////////////
'//
'// Sensor-location operations
'//
'///////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION WinBioLocateSensor IMPORT "Winbio.dll" ALIAS "WinBioLocateSensor" ( _
   BYVAL SessionHandle AS DWORD _                       ' __in WINBIO_SESSION_HANDLE SessionHandle
 , BYREF UnitId AS DWORD _                              ' __out WINBIO_UNIT_ID *UnitId
 ) AS LONG                                              ' HRESULT

'typedef
'VOID
'(CALLBACK *PWINBIO_LOCATE_SENSOR_CALLBACK)(
'    __in_opt PVOID LocateCallbackContext,
'    __in HRESULT OperationStatus,
'    __in WINBIO_UNIT_ID UnitId
'    );

'SUB WINBIO_LOCATE_SENSOR_CALLBACK ( _
'   BYVAL LocateCallbackContext AS DWORD _               ' __in_opt PVOID LocateCallbackContext
' , BYVAL OperationStatus AS LONG _                      ' __in HRESULT OperationStatus
' , BYVAL UnitId AS DWORD _                              ' __in WINBIO_UNIT_ID UnitId
' )                                                      ' VOID

DECLARE FUNCTION WinBioLocateSensorWithCallback IMPORT "Winbio.dll" ALIAS "WinBioLocateSensorWithCallback" ( _
   BYVAL SessionHandle AS DWORD _                       ' __in WINBIO_SESSION_HANDLE SessionHandle
 , BYVAL LocateCallback AS DWORD _                      ' __in PWINBIO_LOCATE_SENSOR_CALLBACK LocateCallback
 , OPTIONAL LocateCallbackContext AS DWORD _            ' __in_opt PVOID LocateCallbackContext
 ) AS LONG                                              ' HRESULT

'///////////////////////////////////////////////////////////////////////////////
'//
'// Enrollment operations
'//
'///////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION WinBioEnrollBegin IMPORT "Winbio.dll" ALIAS "WinBioEnrollBegin" ( _
   BYVAL SessionHandle AS DWORD _                       ' __in WINBIO_SESSION_HANDLE SessionHandle
 , BYVAL SubFactor AS BYTE _                            ' __in WINBIO_BIOMETRIC_SUBTYPE SubFactor
 , BYVAL UnitId AS DWORD _                              ' __in WINBIO_UNIT_ID UnitId
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WinBioEnrollCapture IMPORT "Winbio.dll" ALIAS "WinBioEnrollCapture" ( _
   BYVAL SessionHandle AS DWORD _                       ' __in WINBIO_SESSION_HANDLE SessionHandle
 , BYREF RejectDetail AS DWORD _                        ' __out WINBIO_REJECT_DETAIL *RejectDetail
 ) AS LONG                                              ' HRESULT

'typedef
'VOID
'(CALLBACK *PWINBIO_ENROLL_CAPTURE_CALLBACK)(
'    __in_opt PVOID EnrollCallbackContext,
'    __in HRESULT OperationStatus,
'    __in WINBIO_REJECT_DETAIL RejectDetail
'    );

'SUB WINBIO_ENROLL_CAPTURE_CALLBACK ( _
'   BYVAL EnrollCallbackContext AS DWORD _               ' __in_opt PVOID EnrollCallbackContext
' , BYVAL OperationStatus AS LONG _                      ' __in HRESULT OperationStatus
' , BYREF RejectDetail AS DWORD _                        ' __in WINBIO_REJECT_DETAIL RejectDetail
' )                                                      ' VOID

DECLARE FUNCTION WinBioEnrollCaptureWithCallback IMPORT "Winbio.dll" ALIAS "WinBioEnrollCaptureWithCallback" ( _
   BYVAL SessionHandle AS DWORD _                       ' __in WINBIO_SESSION_HANDLE SessionHandle
 , BYVAL EnrollCallback AS DWORD _                      ' __in PWINBIO_ENROLL_CAPTURE_CALLBACK EnrollCallback
 , OPTIONAL EnrollCallbackContext AS DWORD _            ' __in_opt PVOID EnrollCallbackContext
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WinBioEnrollCommit IMPORT "Winbio.dll" ALIAS "WinBioEnrollCommit" ( _
   BYVAL SessionHandle AS DWORD _                       ' __in WINBIO_SESSION_HANDLE SessionHandle
 , BYREF Identity AS WINBIO_IDENTITY _                  ' __out WINBIO_IDENTITY *Identity
 , BYREF IsNewTemplate AS BYTE _                        ' __out BOOLEAN *IsNewTemplate
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WinBioEnrollDiscard IMPORT "Winbio.dll" ALIAS "WinBioEnrollDiscard" ( _
   BYVAL SessionHandle AS DWORD _                       ' __in WINBIO_SESSION_HANDLE SessionHandle
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WinBioEnumEnrollments IMPORT "Winbio.dll" ALIAS "WinBioEnumEnrollments" ( _
   BYVAL SessionHandle AS DWORD _                       ' __in WINBIO_SESSION_HANDLE SessionHandle
 , BYVAL UnitId AS DWORD _                              ' __in WINBIO_UNIT_ID UnitId
 , BYREF Identity AS WINBIO_IDENTITY _                  ' __in WINBIO_IDENTITY *Identity
 , BYREF SubFactorArray AS BYTE _                       ' __deref_out_ecount(*SubFactorCount) WINBIO_BIOMETRIC_SUBTYPE **SubFactorArray
 , BYREF SubFactorCount AS DWORD _                      ' __out SIZE_T *SubFactorCount
 ) AS LONG                                              ' HRESULT

'///////////////////////////////////////////////////////////////////////////////
'//
'// Event monitors
'//
'///////////////////////////////////////////////////////////////////////////////
'typedef
'VOID
'(CALLBACK *PWINBIO_EVENT_CALLBACK)(
'    __in_opt PVOID EventCallbackContext,
'    __in HRESULT OperationStatus,
'    __in PWINBIO_EVENT Event
'    );

'SUB WINBIO_EVENT_CALLBACK ( _
'   BYVAL EventCallbackContext AS DWORD _                ' __in_opt PVOID EventCallbackContext
' , BYVAL OperationStatus AS LONG _                      ' __in HRESULT OperationStatus
' , BYREF pEvent AS WINBIO_EVENT _                       ' __in PWINBIO_EVENT Event
' )                                                      ' VOID

DECLARE FUNCTION WinBioRegisterEventMonitor IMPORT "Winbio.dll" ALIAS "WinBioRegisterEventMonitor" ( _
   BYVAL SessionHandle AS DWORD _                       ' __in WINBIO_SESSION_HANDLE SessionHandle
 , BYVAL EventMask AS DWORD _                           ' __in WINBIO_EVENT_TYPE EventMask
 , BYVAL EventCallback AS DWORD _                       ' __in PWINBIO_EVENT_CALLBACK EventCallback
 , OPTIONAL EventCallbackContext AS DWORD _             ' __in_opt PVOID EventCallbackContext
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WinBioUnregisterEventMonitor IMPORT "Winbio.dll" ALIAS "WinBioUnregisterEventMonitor" ( _
   BYVAL SessionHandle AS DWORD _                       ' __in WINBIO_SESSION_HANDLE SessionHandle
 ) AS LONG                                              ' HRESULT

'///////////////////////////////////////////////////////////////////////////////
'//
'// Raw biometric operations
'//
'///////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION WinBioCaptureSample IMPORT "Winbio.dll" ALIAS "WinBioCaptureSample" ( _
   BYVAL SessionHandle AS DWORD _                       ' __in WINBIO_SESSION_HANDLE SessionHandle
 , BYVAL Purpose AS BYTE _                              ' __in WINBIO_BIR_PURPOSE Purpose
 , BYVAL Flags AS DWORD _                               ' __in WINBIO_BIR_DATA_FLAGS Flags
 , BYREF UnitId AS DWORD _                              ' __out WINBIO_UNIT_ID *UnitId
 , BYREF Sample AS WINBIO_BIR _                         ' __deref_out_bcount(*SampleSize) PWINBIO_BIR *Sample
 , BYREF SampleSize AS DWORD _                          ' __out SIZE_T *SampleSize
 , BYREF RejectDetail AS DWORD _                        ' __out WINBIO_REJECT_DETAIL *RejectDetail
 ) AS LONG                                              ' HRESULT

'typedef
'VOID
'(CALLBACK *PWINBIO_CAPTURE_CALLBACK)(
'    __in_opt PVOID CaptureCallbackContext,
'    __in HRESULT OperationStatus,
'    __in WINBIO_UNIT_ID UnitId,
'    __in_bcount(SampleSize) PWINBIO_BIR Sample,
'    __in SIZE_T SampleSize,
'    __in WINBIO_REJECT_DETAIL RejectDetail
'    );

'SUB WINBIO_CAPTURE_CALLBACK ( _
'   BYVAL CaptureCallbackContext AS DWORD _              ' __in_opt PVOID CaptureCallbackContext
' , BYVAL OperationStatus AS LONG _                      ' __in HRESULT OperationStatus
' , BYVAL UnitId AS DWORD _                              ' __in WINBIO_UNIT_ID UnitId
' , BYREF Sample AS WINBIO_BIR _                         ' __in_bcount(SampleSize) PWINBIO_BIR Sample
' , BYVAL SampleSize AS DWORD _                          ' __in SIZE_T SampleSize
' , BYVAL RejectDetail AS DWORD _                        ' __in WINBIO_REJECT_DETAIL RejectDetail
' )                                                      ' VOID

DECLARE FUNCTION WinBioCaptureSampleWithCallback IMPORT "Winbio.dll" ALIAS "WinBioCaptureSampleWithCallback" ( _
   BYVAL SessionHandle AS DWORD _                       ' __in WINBIO_SESSION_HANDLE SessionHandle
 , BYVAL Purpose AS BYTE _                              ' __in WINBIO_BIR_PURPOSE Purpose
 , BYVAL Flags AS DWORD _                               ' __in WINBIO_BIR_DATA_FLAGS Flags
 , BYVAL CaptureCallback AS DWORD _                     ' __in PWINBIO_CAPTURE_CALLBACK CaptureCallback
 , OPTIONAL CaptureCallbackContext AS DWORD _           ' __in_opt PVOID CaptureCallbackContext
 ) AS LONG                                              ' HRESULT

'///////////////////////////////////////////////////////////////////////////////
'//
'// Storage management
'//
'///////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION WinBioDeleteTemplate IMPORT "Winbio.dll" ALIAS "WinBioDeleteTemplate" ( _
   BYVAL SessionHandle AS DWORD _                       ' __in WINBIO_SESSION_HANDLE SessionHandle
 , BYVAL UnitId AS DWORD _                              ' __in WINBIO_UNIT_ID UnitId
 , BYREF Identity AS WINBIO_IDENTITY _                  ' __in WINBIO_IDENTITY *Identity
 , BYVAL SubFactor AS BYTE _                            ' __in WINBIO_BIOMETRIC_SUBTYPE SubFactor
 ) AS LONG                                              ' HRESULT

'///////////////////////////////////////////////////////////////////////////////
'//
'// Extension interface
'//
'///////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION WinBioLockUnit IMPORT "Winbio.dll" ALIAS "WinBioLockUnit" ( _
   BYVAL SessionHandle AS DWORD _                       ' __in WINBIO_SESSION_HANDLE SessionHandle
 , BYVAL UnitId AS DWORD _                              ' __in WINBIO_UNIT_ID UnitId
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WinBioUnlockUnit IMPORT "Winbio.dll" ALIAS "WinBioUnlockUnit" ( _
   BYVAL SessionHandle AS DWORD _                       ' __in WINBIO_SESSION_HANDLE SessionHandle
 , BYVAL UnitId AS DWORD _                              ' __in WINBIO_UNIT_ID UnitId
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WinBioControlUnit IMPORT "Winbio.dll" ALIAS "WinBioControlUnit" ( _
   BYVAL SessionHandle AS DWORD _                       ' __in WINBIO_SESSION_HANDLE SessionHandle
 , BYVAL UnitId AS DWORD _                              ' __in WINBIO_UNIT_ID UnitId
 , BYVAL Component AS DWORD _                           ' __in WINBIO_COMPONENT Component
 , BYVAL ControlCode AS DWORD _                         ' __in ULONG ControlCode
 , BYVAL SendBuffer AS BYTE PTR _                       ' __in PUCHAR SendBuffer
 , BYVAL SendBufferSize AS DWORD _                      ' __in SIZE_T SendBufferSize
 , BYVAL ReceiveBuffer AS BYTE PTR _                    ' __in PUCHAR ReceiveBuffer
 , BYVAL ReceiveBufferSize AS DWORD _                   ' __in SIZE_T ReceiveBufferSize
 , BYREF ReceiveDataSize AS DWORD _                     ' __out SIZE_T *ReceiveDataSize
 , BYREF OperationStatus AS DWORD _                     ' __out ULONG *OperationStatus
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WinBioControlUnitPrivileged IMPORT "Winbio.dll" ALIAS "WinBioControlUnitPrivileged" ( _
   BYVAL SessionHandle AS DWORD _                       ' __in WINBIO_SESSION_HANDLE SessionHandle
 , BYVAL UnitId AS DWORD _                              ' __in WINBIO_UNIT_ID UnitId
 , BYVAL Component AS DWORD _                           ' __in WINBIO_COMPONENT Component
 , BYVAL ControlCode AS DWORD _                         ' __in ULONG ControlCode
 , BYVAL SendBuffer AS BYTE PTR _                       ' __in PUCHAR SendBuffer
 , BYVAL SendBufferSize AS DWORD _                      ' __in SIZE_T SendBufferSize
 , BYVAL ReceiveBuffer AS BYTE PTR _                    ' __in PUCHAR ReceiveBuffer
 , BYVAL ReceiveBufferSize AS DWORD _                   ' __in SIZE_T ReceiveBufferSize
 , BYREF ReceiveDataSize AS DWORD _                     ' __out SIZE_T *ReceiveDataSize
 , BYREF OperationStatus AS DWORD _                     ' __out ULONG *OperationStatus
 ) AS LONG                                              ' HRESULT


'///////////////////////////////////////////////////////////////////////////////
'//
'// Get/set property operations
'//
'///////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION WinBioGetProperty IMPORT "Winbio.dll" ALIAS "WinBioGetProperty" ( _
   BYVAL SessionHandle AS DWORD _                       ' __in WINBIO_SESSION_HANDLE SessionHandle
 , BYVAL PropertyType AS DWORD _                        ' __in WINBIO_PROPERTY_TYPE PropertyType
 , BYVAL PropertyId AS DWORD _                          ' __in WINBIO_PROPERTY_ID PropertyId
 , BYVAL UnitId AS DWORD _                              ' __in_opt WINBIO_UNIT_ID UnitId
 , BYREF Identity AS WINBIO_IDENTITY _                  ' __in_opt WINBIO_IDENTITY *Identity
 , BYVAL SubFactor AS BYTE _                            ' __in_opt WINBIO_BIOMETRIC_SUBTYPE SubFactor
 , BYREF PropertyBuffer AS ANY _                        ' __deref_out_bcount(*PropertyBufferSize) PVOID *PropertyBuffer
 , BYREF PropertyBufferSize AS DWORD _                  ' __out SIZE_T *PropertyBufferSize
 ) AS LONG                                              ' HRESULT

'///////////////////////////////////////////////////////////////////////////////
'//
'// Resource management
'//
'///////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION WinBioFree IMPORT "Winbio.dll" ALIAS "WinBioFree" ( _
   BYVAL Address AS DWORD _                             ' __in PVOID Address
 ) AS LONG                                              ' HRESULT

'///////////////////////////////////////////////////////////////////////////////
'//
'// Credential management
'//
'///////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION WinBioSetCredential IMPORT "Winbio.dll" ALIAS "WinBioSetCredential" ( _
   BYVAL Type AS DWORD _                                ' __in WINBIO_CREDENTIAL_TYPE Type
 , BYVAL Credential AS BYTE PTR _                       ' __in_bcount(CredentialSize) PUCHAR Credential
 , BYVAL CredentialSize AS DWORD _                      ' __in SIZE_T CredentialSize
 , BYVAL Format AS DWORD _                              ' __in WINBIO_CREDENTIAL_FORMAT Format
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WinBioRemoveCredential IMPORT "Winbio.dll" ALIAS "WinBioRemoveCredential" ( _
   BYREF Identity AS WINBIO_IDENTITY _                  ' __in WINBIO_IDENTITY Identity
 , BYVAL Type AS DWORD _                                ' __in WINBIO_CREDENTIAL_TYPE Type
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WinBioRemoveAllCredentials IMPORT "Winbio.dll" ALIAS "WinBioRemoveAllCredentials" ( _
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WinBioRemoveAllDomainCredentials IMPORT "Winbio.dll" ALIAS "WinBioRemoveAllDomainCredentials" ( _
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WinBioGetCredentialState IMPORT "Winbio.dll" ALIAS "WinBioGetCredentialState" ( _
   BYREF Identity AS WINBIO_IDENTITY _                  ' __in WINBIO_IDENTITY Identity
 , BYVAL Type AS DWORD _                                ' __in WINBIO_CREDENTIAL_TYPE Type
 , BYREF CredentialState AS DWORD _                     ' __out WINBIO_CREDENTIAL_STATE *CredentialState
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WinBioLogonIdentifiedUser IMPORT "Winbio.dll" ALIAS "WinBioLogonIdentifiedUser" ( _
   BYVAL SessionHandle AS DWORD _                       ' __in WINBIO_SESSION_HANDLE SessionHandle
 ) AS LONG                                              ' HRESULT

'///////////////////////////////////////////////////////////////////////////////
'//
'// Settings
'//
'///////////////////////////////////////////////////////////////////////////////

DECLARE SUB WinBioGetEnabledSetting IMPORT "Winbio.dll" ALIAS "WinBioGetEnabledSetting" ( _
   BYREF Value AS BYTE _                                ' __out BOOLEAN* Value
 , BYREF Source AS DWORD _                              ' __out PWINBIO_SETTING_SOURCE_TYPE Source
 )                                                      ' VOID

DECLARE SUB WinBioGetLogonSetting IMPORT "Winbio.dll" ALIAS "WinBioGetLogonSetting" ( _
   BYREF Value AS BYTE _                                ' __out BOOLEAN* Value
 , BYREF Source AS DWORD _                              ' __out PWINBIO_SETTING_SOURCE_TYPE Source
 )                                                      ' VOID

DECLARE SUB WinBioGetDomainLogonSetting IMPORT "Winbio.dll" ALIAS "WinBioGetDomainLogonSetting" ( _
    __out BOOLEAN* Value,
    __out PWINBIO_SETTING_SOURCE_TYPE Source
 )                                                      ' VOID

'///////////////////////////////////////////////////////////////////////////////
'//
'// Focus tracking management
'//
'///////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION WinBioAcquireFocus IMPORT "Winbio.dll" ALIAS "WinBioAcquireFocus" ( _
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WinBioReleaseFocus IMPORT "Winbio.dll" ALIAS "WinBioReleaseFocus" ( _
 ) AS LONG                                              ' HRESULT

'#endif // (NTDDI_VERSION >= NTDDI_WIN7)
