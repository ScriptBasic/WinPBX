' ########################################################################################
' Microsoft Windows
' File: CertAdm.inc
' Library name: CERTADMINLib
' Version: 1.0, Locale ID = 0
' Library GUID: {35DE99A0-7FB6-11D0-8817-00A0C903B83C}
' Path: C:\Archivos de programa\Microsoft Platform SDK for Windows Server 2003 R2\Bin\CertAdmL.Dll
' Contents: CertAdm 1.0 Type Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CERTADM_INC = 1

$LIBID_CERTADMINLib                 = GUID$("{35DE99A0-7FB6-11D0-8817-00A0C903B83C}")
$CLSID_CCertAdmin                   = GUID$("{37EABAF0-7FB6-11D0-8817-00A0C903B83C}")
$CLSID_CCertView                    = GUID$("{A12D0F7A-1E84-11D1-9BD6-00C04FB683FA}")
$CLSID_OCSPPropertyCollection       = GUID$("{F935A528-BA8A-4DD9-BA79-F283275CB2DE}")
$CLSID_OCSPAdmin                    = GUID$("{D3F73511-92C9-47CB-8FF2-8D891A7C4DE4}")

$IID_ICertAdmin                     = GUID$("{34DF6950-7FB6-11D0-8817-00A0C903B83C}")
$IID_ICertAdmin2                    = GUID$("{F7C3AC41-B8CE-4FB4-AA58-3D1DC0E36B39}")
$IID_ICertView2                     = GUID$("{D594B282-8851-4B61-9C66-3EDADF848863}")
$IID_IOCSPProperty                  = GUID$("{66FB7839-5F04-4C25-AD18-9FF1A8376EE0}")
$IID_IOCSPPropertyCollection        = GUID$("{2597C18D-54E6-4B74-9FA9-A6BFDA99CBBE}")
$IID_IOCSPCAConfiguration           = GUID$("{AEC92B40-3D46-433F-87D1-B84D5C1E790D}")
$IID_IOCSPCAConfigurationCollection = GUID$("{2BEBEA0B-5ECE-4F28-A91C-86B4BB20F0D3}")
$IID_IOCSPAdmin                     = GUID$("{2BEBEA0B-5ECE-4F28-A91C-86B4BB20F0D3}")

'/* header files for imported files */
#INCLUDE ONCE "wtypes.inc"
#INCLUDE ONCE "certview.inc"

%CA_DISP_INCOMPLETE       = 0
%CA_DISP_ERROR            = &H1
%CA_DISP_REVOKED          = &H2
%CA_DISP_VALID            = &H3
%CA_DISP_INVALID          = &H4
%CA_DISP_UNDER_SUBMISSION = &H5

%KRA_DISP_EXPIRED         = 0
%KRA_DISP_NOTFOUND        = &H1
%KRA_DISP_REVOKED         = &H2
%KRA_DISP_VALID           = &H3
%KRA_DISP_INVALID         = &H4
%KRA_DISP_UNTRUSTED       = &H5
%KRA_DISP_NOTLOADED       = &H6

%CA_ACCESS_ADMIN          = &H1
%CA_ACCESS_OFFICER        = &H2
%CA_ACCESS_AUDITOR        = &H4
%CA_ACCESS_OPERATOR       = &H8
%CA_ACCESS_MASKROLES      = &Hff
%CA_ACCESS_READ           = &H100
%CA_ACCESS_ENROLL         = &H200

' ########################################################################################
' Interface name = ICertAdmin
' IID = {34DF6950-7FB6-11D0-8817-00A0C903B83C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertAdmin_INTERFACE_DEFINED)
    %ICertAdmin_INTERFACE_DEFINED = 1

INTERFACE ICertAdmin $IID_ICertAdmin

   INHERIT IDispatch

   ' =====================================================================================
   METHOD IsValidCertificate <1610743808> ( _           ' VTable offset = 28
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL strSerialNumber AS WSTRING _                 ' __in const BSTR strSerialNumber
   ) AS LONG                                            ' __retval_out LONG *pDisposition
   ' =====================================================================================
   METHOD GetRevocationReason <1610743809> ( _          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *pReason
   ' =====================================================================================
   METHOD RevokeCertificate <1610743810> ( _            ' VTable offset = 36
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL strSerialNumber AS WSTRING _                 ' __in const BSTR strSerialNumber
   , BYVAL Reason AS LONG _                             ' __in LONG Reason
   , BYVAL Date AS DOUBLE _                             ' __in DATE Date
   )                                                    ' void
   ' =====================================================================================
   METHOD SetRequestAttributes <1610743811> ( _         ' VTable offset = 40
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL RequestId AS LONG _                          ' __in LONG RequestId
   , BYVAL strAttributes AS WSTRING _                   ' __in const BSTR strAttributes
   )                                                    ' void
   ' =====================================================================================
   METHOD SetCertificateExtension <1610743812> ( _      ' VTable offset = 44
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL RequestId AS LONG _                          ' __in LONG RequestId
   , BYVAL strExtensionName AS WSTRING _                ' __in const BSTR strExtensionName
   , BYVAL Type AS LONG _                               ' __in LONG Type
   , BYVAL Flags AS LONG _                              ' __in LONG Flags
   , BYREF pvarValue AS VARIANT _                       ' __in const VARIANT *pvarValue
   )                                                    ' void
   ' =====================================================================================
   METHOD DenyRequest <1610743813> ( _                  ' VTable offset = 48
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL RequestId AS LONG _                          ' __in LONG RequestId
   )                                                    ' void
   ' =====================================================================================
   METHOD ResubmitRequest <1610743814> ( _              ' VTable offset = 52
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL RequestId AS LONG _                          ' __in LONG RequestId
   ) AS LONG                                            ' __in RequestId /* VT_I4 <Long> */
   ' =====================================================================================
   METHOD PublishCRL <1610743815> ( _                   ' VTable offset = 56
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL Date AS DOUBLE _                             ' __in DATE Date
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCRL <1610743816> ( _                       ' VTable offset = 60
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS WSTRING                                         ' __retval_out BSTR *pstrCRL
   ' =====================================================================================
   METHOD ImportCertificate <1610743817> ( _            ' VTable offset = 64
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL strCertificate AS WSTRING _                  ' __in const BSTR strCertificate
   , BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS LONG                                            ' __retval_out LONG *pRequestId
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertAdmin_INTERFACE_DEFINED__ */

%CA_CRL_BASE              = &H1
%CA_CRL_DELTA             = &H2
%CA_CRL_REPUBLISH         = &H10
%ICF_ALLOWFOREIGN         = &H10000
%ICF_EXISTINGROW          = &H20000
%IKF_OVERWRITE            = &H10000
%CDR_EXPIRED              = 1
%CDR_REQUEST_LAST_CHANGED = 2


' ########################################################################################
' Interface name = ICertAdmin2
' IID = {F7C3AC41-B8CE-4FB4-AA58-3D1DC0E36B39}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ICertAdmin
' ########################################################################################

#IF NOT %DEF(%ICertAdmin2_INTERFACE_DEFINED)
    %ICertAdmin2_INTERFACE_DEFINED = 1

INTERFACE ICertAdmin2 $IID_ICertAdmin2

   INHERIT IDispatch

   ' =====================================================================================
   ' ICertAdmin Methods
   ' =====================================================================================
   METHOD IsValidCertificate <1610743808> ( _           ' VTable offset = 28
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL strSerialNumber AS WSTRING _                 ' __in const BSTR strSerialNumber
   ) AS LONG                                            ' __retval_out LONG *pDisposition
   ' =====================================================================================
   METHOD GetRevocationReason <1610743809> ( _          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *pReason
   ' =====================================================================================
   METHOD RevokeCertificate <1610743810> ( _            ' VTable offset = 36
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL strSerialNumber AS WSTRING _                 ' __in const BSTR strSerialNumber
   , BYVAL Reason AS LONG _                             ' __in LONG Reason
   , BYVAL Date AS DOUBLE _                             ' __in DATE Date
   )                                                    ' void
   ' =====================================================================================
   METHOD SetRequestAttributes <1610743811> ( _         ' VTable offset = 40
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL RequestId AS LONG _                          ' __in LONG RequestId
   , BYVAL strAttributes AS WSTRING _                   ' __in const BSTR strAttributes
   )                                                    ' void
   ' =====================================================================================
   METHOD SetCertificateExtension <1610743812> ( _      ' VTable offset = 44
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL RequestId AS LONG _                          ' __in LONG RequestId
   , BYVAL strExtensionName AS WSTRING _                ' __in const BSTR strExtensionName
   , BYVAL Type AS LONG _                               ' __in LONG Type
   , BYVAL Flags AS LONG _                              ' __in LONG Flags
   , BYREF pvarValue AS VARIANT _                       ' __in const VARIANT *pvarValue
   )                                                    ' void
   ' =====================================================================================
   METHOD DenyRequest <1610743813> ( _                  ' VTable offset = 48
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL RequestId AS LONG _                          ' __in LONG RequestId
   )                                                    ' void
   ' =====================================================================================
   METHOD ResubmitRequest <1610743814> ( _              ' VTable offset = 52
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL RequestId AS LONG _                          ' __in LONG RequestId
   ) AS LONG                                            ' __in RequestId /* VT_I4 <Long> */
   ' =====================================================================================
   METHOD PublishCRL <1610743815> ( _                   ' VTable offset = 56
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL Date AS DOUBLE _                             ' __in DATE Date
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCRL <1610743816> ( _                       ' VTable offset = 60
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS WSTRING                                         ' __retval_out BSTR *pstrCRL
   ' =====================================================================================
   METHOD ImportCertificate <1610743817> ( _            ' VTable offset = 64
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL strCertificate AS WSTRING _                  ' __in const BSTR strCertificate
   , BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS LONG                                            ' __retval_out LONG *pRequestId
   ' =====================================================================================

   ' =====================================================================================
   ' ICertAdmin2 Methods
   ' =====================================================================================
   METHOD PublishCRLs <1610809344> ( _                  ' VTable offset = 68
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL Date AS DOUBLE _                             ' __in DATE Date
   , BYVAL CRLFlags AS LONG _                           ' __in LONG CRLFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCAProperty <1610809345> ( _                ' VTable offset = 72
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL PropId AS LONG _                             ' __in LONG PropId
   , BYVAL PropIndex AS LONG _                          ' __in LONG PropIndex
   , BYVAL PropType AS LONG _                           ' __in LONG PropType
   , BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarPropertyValue
   ' =====================================================================================
   METHOD SetCAProperty <1610809346> ( _                ' VTable offset = 76
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL PropId AS LONG _                             ' __in LONG PropId
   , BYVAL PropIndex AS LONG _                          ' __in LONG PropIndex
   , BYVAL PropType AS LONG _                           ' __in LONG PropType
   , BYREF pvarPropertyValue AS VARIANT _               ' __in VARIANT *pvarPropertyValue
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCAPropertyFlags <1610809347> ( _           ' VTable offset = 80
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL PropId AS LONG _                             ' __in LONG PropId
   ) AS LONG                                            ' __retval_out LONG *pPropFlags
   ' =====================================================================================
   METHOD GetCAPropertyDisplayName <1610809348> ( _     ' VTable offset = 84
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL PropId AS LONG _                             ' __in LONG PropId
   ) AS WSTRING                                         ' __retval_out BSTR *pstrDisplayName
   ' =====================================================================================
   METHOD GetArchivedKey <1610809349> ( _               ' VTable offset = 88
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL RequestId AS LONG _                          ' __in LONG RequestId
   , BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS WSTRING                                         ' __retval_out BSTR *pstrArchivedKey
   ' =====================================================================================
   METHOD GetConfigEntry <1610809350> ( _               ' VTable offset = 92
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL strNodePath AS WSTRING _                     ' __in const BSTR strNodePath
   , BYVAL strEntryName AS WSTRING _                    ' __in const BSTR strEntryName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarEntry
   ' =====================================================================================
   METHOD SetConfigEntry <1610809351> ( _               ' VTable offset = 96
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL strNodePath AS WSTRING _                     ' __in const BSTR strNodePath
   , BYVAL strEntryName AS WSTRING _                    ' __in const BSTR strEntryName
   , BYREF pvarEntry AS VARIANT _                       ' __in VARIANT *pvarEntry
   )                                                    ' void
   ' =====================================================================================
   METHOD ImportKey <1610809352> ( _                    ' VTable offset = 100
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL RequestId AS LONG _                          ' __in LONG RequestId
   , BYVAL strCertHash AS WSTRING _                     ' __in const BSTR strCertHash
   , BYVAL Flags AS LONG _                              ' __in LONG Flags
   , BYVAL strKey AS WSTRING _                          ' __in const BSTR strKey
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMyRoles <1610809353> ( _                   ' VTable offset = 104
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   ) AS LONG                                            ' __retval_out LONG *pRoles
   ' =====================================================================================
   METHOD DeleteRow <1610809354> ( _                    ' VTable offset = 108
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL Flags AS LONG _                              ' __in LONG Flags
   , BYVAL Date AS DOUBLE _                             ' __in DATE Date
   , BYVAL Table AS LONG _                              ' __in LONG Table
   , BYVAL RowId AS LONG _                              ' __in LONG RowId
   ) AS LONG                                            ' __retval_out LONG *pcDeleted
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertAdmin2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IOCSPProperty
' IID = {66FB7839-5F04-4C25-AD18-9FF1A8376EE0}
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IOCSPProperty_INTERFACE_DEFINED)
    %IOCSPProperty_INTERFACE_DEFINED = 1

INTERFACE IOCSPProperty $IID_IOCSPProperty

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET Value <2> ( _                           ' VTable offset = 32
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY SET Value <2> ( _                           ' VTable offset = 36
     BYVAL newVal AS VARIANT _                          ' __in VARIANT newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Modified <3> ( _                        ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOCSPProperty_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IOCSPPropertyCollection
' IID = {2597C18D-54E6-4B74-9FA9-A6BFDA99CBBE}
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IOCSPPropertyCollection_INTERFACE_DEFINED)
    %IOCSPPropertyCollection_INTERFACE_DEFINED = 1

INTERFACE IOCSPPropertyCollection $IID_IOCSPPropertyCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **ppVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET ItemByName <2> ( _                      ' VTable offset = 40
     BYVAL bstrPropName AS WSTRING _                    ' __in const BSTR bstrPropName
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   METHOD CreateProperty <3> ( _                        ' VTable offset = 44
     BYVAL bstrPropName AS WSTRING _                    ' __in const BSTR bstrPropName
   , BYVAL pVarPropValue AS VARIANT _                   ' __in const VARIANT *pVarPropValue
   ) AS IOCSPProperty                                   ' __retval_out IOCSPProperty **ppVal
   ' =====================================================================================
   METHOD DeleteProperty <4> ( _                        ' VTable offset = 48
     BYVAL bstrPropName AS WSTRING _                    ' __in const BSTR bstrPropName
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromProperties <5> ( _              ' VTable offset = 52
     BYVAL pVarProperties AS VARIANT _                  ' __in const VARIANT *pVarProperties
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAllProperties <6> ( _                      ' VTable offset = 56
   ) AS VARIANT                                         ' __retval_out VARIANT *pVarProperties
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOCSPPropertyCollection_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IOCSPCAConfiguration
' IID = {AEC92B40-3D46-433F-87D1-B84D5C1E790D}
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IOCSPCAConfiguration_INTERFACE_DEFINED)
    %IOCSPCAConfiguration_INTERFACE_DEFINED = 1

INTERFACE IOCSPCAConfiguration $IID_IOCSPCAConfiguration

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Identifier <1> ( _                      ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET CACertificate <2> ( _                   ' VTable offset = 32
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY GET HashAlgorithm <3> ( _                   ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET HashAlgorithm <3> ( _                   ' VTable offset = 40
     BYVAL newVal AS WSTRING _                          ' __in const BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SigningFlags <4> ( _                    ' VTable offset = 44
   ) AS DWORD                                           ' __retval_out ULONG *pVal
   ' =====================================================================================
   PROPERTY SET SigningFlags <4> ( _                    ' VTable offset = 48
     BYVAL newVal AS DWORD _                            ' __in ULONG newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SigningCertificate <5> ( _              ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY SET SigningCertificate <5> ( _              ' VTable offset = 56
     BYVAL newVal AS VARIANT _                          ' __in VARIANT newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReminderDuration <6> ( _                ' VTable offset = 60
   ) AS DWORD                                           ' __retval_out ULONG *pVal
   ' =====================================================================================
   PROPERTY SET ReminderDuration <6> ( _                ' VTable offset = 64
     BYVAL newVal AS DWORD _                            ' __in ULONG newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ErrorCode <7> ( _                       ' VTable offset = 68
   ) AS DWORD                                           ' __retval_out ULONG *pVal
   ' =====================================================================================
   PROPERTY GET CSPName <8> ( _                         ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET KeySpec <9> ( _                         ' VTable offset = 76
   ) AS DWORD                                           ' __retval_out ULONG *pVal
   ' =====================================================================================
   PROPERTY GET ProviderCLSID <10> ( _                  ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET ProviderCLSID <10> ( _                  ' VTable offset = 84
     BYVAL newVal AS WSTRING _                          ' __in const BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProviderProperties <11> ( _             ' VTable offset = 88
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY SET ProviderProperties <11> ( _             ' VTable offset = 92
     BYVAL newVal AS VARIANT _                          ' __in VARIANT newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Modified <12> ( _                       ' VTable offset = 96
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY GET LocalRevocationInformation <13> ( _     ' VTable offset = 100
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY SET LocalRevocationInformation <13> ( _     ' VTable offset = 104
     BYVAL newVal AS VARIANT _                          ' __in VARIANT newVal
   )                                                    ' void
   ' =====================================================================================
   ' Added in the Windows Server 2008 SDK:
   ' =====================================================================================
   PROPERTY GET SigningCertificateTemplate ( _          ' VTable offset = 108
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET SigningCertificateTemplate ( _          ' VTable offset = 112
     BYVAL newVal AS WSTRING _                          ' __in VARIANT const BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CAConfig ( _                            ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET CAConfig ( _                            ' VTable offset = 120
     BYVAL newVal AS WSTRING _                          ' __in VARIANT const BSTR newVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOCSPCAConfiguration_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IOCSPCAConfigurationCollection
' IID = {2BEBEA0B-5ECE-4F28-A91C-86B4BB20F0D3}
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IOCSPCAConfigurationCollection_INTERFACE_DEFINED)
    %IOCSPCAConfigurationCollection_INTERFACE_DEFINED = 1

INTERFACE IOCSPCAConfigurationCollection $IID_IOCSPCAConfigurationCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **pVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET ItemByName <2> ( _                      ' VTable offset = 40
     BYVAL bstrIdentifier AS WSTRING _                  ' __in const BSTR bstrIdentifier
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   METHOD CreateCAConfiguration <3> ( _                 ' VTable offset = 44
     BYVAL bstrIdentifier AS WSTRING _                  ' __in const BSTR bstrIdentifier
   , BYVAL varCACert AS VARIANT _                       ' __in VARIANT varCACert
   ) AS IOCSPCAConfiguration                            ' __retval_out IOCSPCAConfiguration **ppVal
   ' =====================================================================================
   METHOD DeleteCAConfiguration <4> ( _                 ' VTable offset = 48
     BYVAL bstrIdentifier AS WSTRING _                  ' __in const BSTR bstrIdentifier
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOCSPCAConfigurationCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IOCSPAdmin
' IID = {322E830D-67DB-4FE9-9577-4596D9F09294}
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IOCSPAdmin_INTERFACE_DEFINED)
    %IOCSPAdmin_INTERFACE_DEFINED = 1

INTERFACE IOCSPAdmin $IID_IOCSPAdmin

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET OCSPServiceProperties <1> ( _           ' VTable offset = 28
   ) AS IOCSPPropertyCollection                         ' __retval_out IOCSPPropertyCollection **ppVal
   ' =====================================================================================
   PROPERTY GET OCSPCAConfigurationCollection <2> ( _   ' VTable offset = 32
   ) AS IOCSPCAConfigurationCollection                  ' __retval_out IOCSPCAConfigurationCollection **pVal
   ' =====================================================================================
   METHOD GetConfiguration <3> ( _                      ' VTable offset = 36
     BYVAL bstrServerName AS WSTRING _                  ' __in const BSTR bstrServerName
   , BYVAL bForce AS INTEGER _                          ' __in VARIANT_BOOL bForce
   )                                                    ' void
   ' =====================================================================================
   METHOD SetConfiguration <4> ( _                      ' VTable offset = 40
     BYVAL bstrServerName AS WSTRING _                  ' __in const BSTR bstrServerName
   , BYVAL bForce AS INTEGER _                          ' __in VARIANT_BOOL bForce
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMyRoles <5> ( _                            ' VTable offset = 44
     BYVAL bstrServerName AS WSTRING _                  ' __in const BSTR bstrServerName
   ) AS LONG                                            ' __retval_out LONG *pRoles
   ' =====================================================================================
   METHOD Ping <6> ( _                                  ' VTable offset = 48
     BYVAL bstrServerName AS WSTRING _                  ' __in const BSTR bstrServerName
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSecurity <7> ( _                           ' VTable offset = 52
     BYVAL bstrServerName AS WSTRING _                  ' __in const BSTR bstrServerName
   , BYVAL bstrVal AS WSTRING _                         ' __in const BSTR bstrVal
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSecurity <8> ( _                           ' VTable offset = 56
     BYVAL bstrServerName AS WSTRING _                  ' __in const BSTR bstrServerName
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD GetSigningCertificates <9> ( _                ' VTable offset = 60
     BYVAL bstrServerName AS WSTRING _                  ' __in const BSTR bstrServerName
   , BYVAL pCACertVar AS VARIANT _                      ' __in const VARIANT *pCACertVar
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   METHOD GetHashAlgorithms <10> ( _                    ' VTable offset = 64
     BYVAL bstrServerName AS WSTRING _                  ' __in const BSTR bstrServerName
   , BYVAL bstrServerName AS WSTRING _                  ' __in const BSTR bstrCAId
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOCSPAdmin_INTERFACE_DEFINED__ */

' enum OCSPSigningFlag
%OCSP_SF_SILENT                           = &H1
%OCSP_SF_USE_CACERT                       = &H2
%OCSP_SF_ALLOW_SIGNINGCERT_AUTORENEWAL    = &H4
%OCSP_SF_FORCE_SIGNINGCERT_ISSUER_ISCA    = &H8
%OCSP_SF_AUTODISCOVER_SIGNINGCERT         = &H10
%OCSP_SF_MANUAL_ASSIGN_SIGNINGCERT        = &H20
%OCSP_SF_RESPONDER_ID_KEYHASH             = &H40
%OCSP_SF_RESPONDER_ID_NAME                = &H80
%OCSP_SF_ALLOW_NONCE_EXTENSION            = &H100
%OCSP_SF_ALLOW_SIGNINGCERT_AUTOENROLLMENT = &H200

' enum OCSPRequestFlag
%OCSP_RF_REJECT_SIGNED_REQUESTS = &H1

$$wszOCSPCAPROP_CACERTIFICATE              = "CACertificate"$$
$$wszOCSPCAPROP_HASHALGORITHMID            = "HashAlgorithmId"$$
$$wszOCSPCAPROP_SIGNINGFLAGS               = "SigningFlags"$$
$$wszOCSPCAPROP_REMINDERDURATION           = "ReminderDuration"$$
$$wszOCSPCAPROP_SIGNINGCERTIFICATE         = "SigningCertificate"$$
$$wszOCSPCAPROP_CSPNAME                    = "CSPName"$$
$$wszOCSPCAPROP_KEYSPEC                    = "KeySpec"$$
$$wszOCSPCAPROP_ERRORCODE                  = "ErrorCode"$$
$$wszOCSPCAPROP_PROVIDERCLSID              = "ProviderCLSID"$$
$$wszOCSPCAPROP_PROVIDERPROPERTIES         = "Provider"$$
$$wszOCSPCAPROP_LOCALREVOCATIONINFORMATION = "LocalRevocationInformation"$$
$$wszOCSPCAPROP_SIGNINGCERTIFICATETEMPLATE = "SigningCertificateTemplate"$$
$$wszOCSPCAPROP_CACONFIG                   = "CAConfig"$$
$$wszOCSPPROP_LOGLEVEL                     = "LogLevel"$$
$$wszOCSPPROP_DEBUG                        = "Debug"$$
$$wszOCSPPROP_AUDITFILTER                  = "AuditFilter"$$
$$wszOCSPPROP_ARRAYCONTROLLER              = "ArrayController"$$
$$wszOCSPPROP_ARRAYMEMBERS                 = "ArrayMembers"$$
$$wszOCSPPROP_ENROLLPOLLINTERVAL           = "EnrollPollInterval"$$
$$wszOCSPISAPIPROP_VIRTUALROOTNAME         = "VirtualRootName"$$
$$wszOCSPISAPIPROP_NUMOFTHREADS            = "NumOfThreads"$$
$$wszOCSPISAPIPROP_NUMOFBACKENDCONNECTIONS = "NumOfBackendConnections"$$
$$wszOCSPISAPIPROP_REFRESHRATE             = "RefreshRate"$$
$$wszOCSPISAPIPROP_MAXNUMOFCACHEENTRIES    = "MaxNumOfCacheEntries"$$
$$wszOCSPISAPIPROP_MAXAGE                  = "MaxAge"$$
$$wszOCSPISAPIPROP_DEBUG                   = "ISAPIDebug"$$
$$wszOCSPCOMMONPROP_REQFLAGS               = "RequestFlags"$$
$$wszOCSPPROP_MAXINCOMINGMESSAGESIZE       = "MaxIncomingMessageSize"$$
$$wszOCSPREVPROP_CRLURLTIMEOUT             = "CrlUrlTimeOut"$$
$$wszOCSPREVPROP_BASECRLURLS               = "BaseCrlUrls"$$
$$wszOCSPREVPROP_BASECRL                   = "BaseCrl"$$
$$wszOCSPREVPROP_DELTACRLURLS              = "DeltaCrlUrls"$$
$$wszOCSPREVPROP_DELTACRL                  = "DeltaCrl"$$
$$wszOCSPREVPROP_REFRESHTIMEOUT            = "RefreshTimeOut"$$
$$wszOCSPREVPROP_AUDITFILTER               = "RevocationAuditFilter"$$   ' Removed in the Windows Server 2008 SDK
$$wszOCSPREVPROP_ERRORCODE                 = "RevocationErrorCode"$$
