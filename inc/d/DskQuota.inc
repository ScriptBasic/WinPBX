' ########################################################################################
' Microsoft Windows
' File: DskQuota.inc
' Library name: DiskQuotaTypeLibrary
' Version: 1.0, Locale ID = 0
' Library GUID: {7988B57C-EC89-11CF-9C00-00AA00A14F56}
' Path: C:\WINDOWS\system32\dskquota.dll
' Contents: Microsoft Disk Quota Type Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DSKQUOTA_INC = 1

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {7988B571-EC89-11CF-9C00-00AA00A14F56}
$PROGID_DiskQuotaControl1 = "Microsoft.DiskQuota.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {7988B571-EC89-11CF-9C00-00AA00A14F56}
$PROGID_DiskQuotaControl = "Microsoft.DiskQuota"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_DiskQuotaControl = GUID$("{7988B571-EC89-11CF-9C00-00AA00A14F56}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_DIDiskQuotaControl = GUID$("{7988B575-EC89-11CF-9C00-00AA00A14F56}")
$IID_DIDiskQuotaControlEvents = GUID$("{7988B581-EC89-11CF-9C00-00AA00A14F56}")
$IID_DIDiskQuotaUser = GUID$("{7988B57A-EC89-11CF-9C00-00AA00A14F56}")
$IID_IDiskQuotaControlEvents = GUID$("{7988B579-EC89-11CF-9C00-00AA00A14F56}")

' ========================================================================================
' AccountStatusConstants enum
' ========================================================================================

%dqAcctResolved                                         = 0            ' &H0
%dqAcctUnavailable                                      = 1            ' &H1
%dqAcctDeleted                                          = 2            ' &H2
%dqAcctInvalid                                          = 3            ' &H3
%dqAcctUnknown                                          = 4            ' &H4
%dqAcctUnresolved                                       = 5            ' &H5

' ========================================================================================
' QuotaStateConstants enum
' ========================================================================================

%dqStateDisable                                         = 0            ' &H0
%dqStateTrack                                           = 1            ' &H1
%dqStateEnforce                                         = 2            ' &H2

' ========================================================================================
' UserNameResolutionConstants enum
' ========================================================================================

%dqResolveNone                                          = 0            ' &H0
%dqResolveSync                                          = 1            ' &H1
%dqResolveAsync                                         = 2            ' &H2

' ########################################################################################
' Interface name = DIDiskQuotaUser
' IID = {7988B57A-EC89-11CF-9C00-00AA00A14F56}
' Automation interface for DiskQuotaUser
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%DIDiskQuotaUser_INTERFACE_DEFINED)
    %DIDiskQuotaUser_INTERFACE_DEFINED = 1

INTERFACE DIDiskQuotaUser $IID_DIDiskQuotaUser

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ID <1610743808> ( _                     ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* pID
   ' =====================================================================================
   PROPERTY GET AccountContainerName <1610743809> ( _   ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pContainerName
   ' =====================================================================================
   PROPERTY GET LogonName <1610743810> ( _              ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pLogonName
   ' =====================================================================================
   PROPERTY GET DisplayName <1610743811> ( _            ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR* pDisplayName
   ' =====================================================================================
   PROPERTY GET QuotaThreshold <1610743812> ( _         ' VTable offset = 44
   ) AS DOUBLE                                          ' __retval_out double* pThreshold /* *VT_R8 <Double> */
   ' =====================================================================================
   PROPERTY SET QuotaThreshold <1610743812> ( _         ' VTable offset = 48
     BYVAL pThreshold AS DOUBLE _                       ' __in double pThreshold
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET QuotaThresholdText <1610743814> ( _     ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* pThresholdText
   ' =====================================================================================
   PROPERTY GET QuotaLimit <1610743815> ( _             ' VTable offset = 56
   ) AS DOUBLE                                          ' __retval_out double* pLimit
   ' =====================================================================================
   PROPERTY SET QuotaLimit <1610743815> ( _             ' VTable offset = 60
     BYVAL pLimit AS DOUBLE _                           ' __in double pLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET QuotaLimitText <1610743817> ( _         ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR* pLimitText
   ' =====================================================================================
   PROPERTY GET QuotaUsed <1610743818> ( _              ' VTable offset = 68
   ) AS DOUBLE                                          ' __retval_out double* pUsed
   ' =====================================================================================
   PROPERTY GET QuotaUsedText <1610743819> ( _          ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR* pUsedText
   ' =====================================================================================
   PROPERTY GET AccountStatus <1610743820> ( _          ' VTable offset = 76
   ) AS LONG                                            ' __retval_out AccountStatusConstants* pStatus
   ' =====================================================================================
   METHOD Invalidate <1610743821> ( _                   ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DIDiskQuotaUser_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DIDiskQuotaControl
' IID = {7988B575-EC89-11CF-9C00-00AA00A14F56}
' Automation interface for DiskQuotaControl object
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%DIDiskQuotaControl_INTERFACE_DEFINED)
    %DIDiskQuotaControl_INTERFACE_DEFINED = 1

INTERFACE DIDiskQuotaControl $IID_DIDiskQuotaControl

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET QuotaState <1610743808> ( _             ' VTable offset = 28
     BYVAL pState AS LONG _                             ' __in QuotaStateConstants pState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET QuotaState <1610743808> ( _             ' VTable offset = 32
   ) AS LONG                                            ' __retval_out QuotaStateConstants* pState
   ' =====================================================================================
   PROPERTY GET QuotaFileIncomplete <1610743810> ( _    ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbIncomplete
   ' =====================================================================================
   PROPERTY GET QuotaFileRebuilding <1610743811> ( _    ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbRebuilding
   ' =====================================================================================
   PROPERTY SET LogQuotaThreshold <1610743812> ( _      ' VTable offset = 44
     BYVAL pbLogThreshold AS INTEGER _                  ' __in VARIANT_BOOL pbLogThreshold
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogQuotaThreshold <1610743812> ( _      ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbLogThreshold
   ' =====================================================================================
   PROPERTY SET LogQuotaLimit <1610743814> ( _          ' VTable offset = 52
     BYVAL pbLogLimit AS INTEGER _                      ' __in VARIANT_BOOL pbLogLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogQuotaLimit <1610743814> ( _          ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbLogLimit
   ' =====================================================================================
   PROPERTY SET DefaultQuotaThreshold <1610743816> ( _  ' VTable offset = 60
     BYVAL pThreshold AS DOUBLE _                       ' __in double pThreshold
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultQuotaThreshold <1610743816> ( _  ' VTable offset = 64
   ) AS DOUBLE                                          ' __retval_out double* pThreshold
   ' =====================================================================================
   PROPERTY GET DefaultQuotaThresholdText <1610743818> ( _ ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR* pThresholdText
   ' =====================================================================================
   PROPERTY SET DefaultQuotaLimit <1610743819> ( _      ' VTable offset = 72
     BYVAL pLimit AS DOUBLE _                           ' __in double pLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultQuotaLimit <1610743819> ( _      ' VTable offset = 76
   ) AS DOUBLE                                          ' __retval_out double* pLimit
   ' =====================================================================================
   PROPERTY GET DefaultQuotaLimitText <1610743821> ( _  ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR* pLimitText
   ' =====================================================================================
   PROPERTY SET UserNameResolution <1610743822> ( _     ' VTable offset = 84
     BYVAL UserNameResolutionConstants AS LONG _        ' __in UserNameResolutionConstants pResolutionType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UserNameResolution <1610743822> ( _     ' VTable offset = 88
   ) AS LONG                                            ' __retval_out UserNameResolutionConstants* pResolutionType
   ' =====================================================================================
   METHOD Initialize <1610743824> ( _                   ' VTable offset = 92
     BYVAL path AS WSTRING _                            ' __in BSTR path
   , BYVAL bReadWrite AS INTEGER _                      ' __in VARIANT_BOOL bReadWrite
   )                                                    ' void
   ' =====================================================================================
   METHOD ShutdownNameResolution <1610743825> ( _       ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD AddUser <1610743826> ( _                      ' VTable offset = 100
     BYVAL LogonName AS WSTRING _                       ' __in BSTR LogonName
   ) AS DIDiskQuotaUser                                 ' __retval_out DIDiskQuotaUser** ppUser
   ' =====================================================================================
   METHOD DeleteUser <1610743827> ( _                   ' VTable offset = 104
     BYVAL pUser AS DIDiskQuotaUser _                   ' __in DIDiskQuotaUser* pUser
   )                                                    ' void
   ' =====================================================================================
   METHOD FindUser <1610743828> ( _                     ' VTable offset = 108
     BYVAL LogonName AS WSTRING _                       ' __in BSTR LogonName
   ) AS DIDiskQuotaUser                                 ' __retval_out DIDiskQuotaUser** ppUser
   ' =====================================================================================
   METHOD InvalidateSidNameCache <1610743829> ( _       ' VTable offset = 112
   )                                                    ' void
   ' =====================================================================================
   METHOD GiveUserNameResolutionPriority <1610743830> ( _ ' VTable offset = 116
     BYVAL pUser AS DIDiskQuotaUser _                   ' __in DIDiskQuotaUser* pUser
   )                                                    ' void
   ' =====================================================================================
   METHOD TranslateLogonNameToSID <1610743831> ( _      ' VTable offset = 120
     BYVAL LogonName AS WSTRING _                       ' __in BSTR LogonName
   ) AS WSTRING                                         ' __retval_out BSTR* psid
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 124
   ) AS IDispatch                                       ' __retval_out IDispatch** ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DIDiskQuotaControl_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDiskQuotaControlEvents
' IID = {7988B579-EC89-11CF-9C00-00AA00A14F56}
' Dual interface for DiskQuotaControl Events
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDiskQuotaControlEvents_INTERFACE_DEFINED)
    %IDiskQuotaControlEvents_INTERFACE_DEFINED = 1

INTERFACE IDiskQuotaControlEvents $IID_IDiskQuotaControlEvents

   INHERIT IDispatch

   ' =====================================================================================
   METHOD OnUserNameChanged <1610743808> ( _            ' VTable offset = 28
     BYVAL pUser AS DIDiskQuotaUser _                   ' __in DIDiskQuotaUser* pUser
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDiskQuotaControlEvents_INTERFACE_DEFINED__ */
