' ########################################################################################
' Microsoft Windows
' File: CertSrv.inc
' Contents: Main Certificate Server header
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CERTSRV_INC = 1

#INCLUDE ONCE "celib.inc"
#INCLUDE ONCE "certadm.inc"
#INCLUDE ONCE "certbcli.inc"
#INCLUDE ONCE "certcli.inc"
#INCLUDE ONCE "certenc.inc"
#INCLUDE ONCE "certexit.inc"
#INCLUDE ONCE "certif.inc"
#INCLUDE ONCE "certpol.inc"
#INCLUDE ONCE "certmod.inc"
#INCLUDE ONCE "certview.inc"

'#ifndef DBG_CERTSRV
'# if defined(_DEBUG)
'#  define DBG_CERTSRV     1
'# elif defined(DBG)
'#  define DBG_CERTSRV     DBG
'# else
'#  define DBG_CERTSRV     0
'# endif
'#endif

$$wszSERVICE_NAME = "CertSvc"$$

'#define wszREGKEYNOSYSTEMCERTSVCPATH \
'            TEXT("CurrentControlSet\\Services\\") \
'            wszSERVICE_NAME
$$wszREGKEYNOSYSTEMCERTSVCPATH = "CurrentControlSet\Services\"$$ & $$wszSERVICE_NAME

'#define wszREGKEYCERTSVCPATH   TEXT("SYSTEM\\") wszREGKEYNOSYSTEMCERTSVCPATH
'#define wszREGKEYBASE      wszREGKEYCERTSVCPATH   // obsolete definition
$$wszREGKEYCERTSVCPATH = "SYSTEM\"$$ & $$wszREGKEYNOSYSTEMCERTSVCPATH
$$wszREGKEYBASE = $$wszREGKEYCERTSVCPATH    ' // obsolete definition

' *** Moved from below ***
'//======================================================================
'// Key Under "CertSvc":
'#define wszREGKEYCONFIG      TEXT("Configuration")
$$wszREGKEYCONFIG = "Configuration"$$

'//======================================================================
'// Full path to "CertSvc\Configuration\":
'#define wszREGKEYCONFIGPATH   wszREGKEYCERTSVCPATH TEXT("\\") wszREGKEYCONFIG
'#define wszREGKEYCONFIGPATH_BS   wszREGKEYCONFIGPATH TEXT("\\")
'#define wszREGKEYCONFIGCANAME   wszREGKEYCONFIGPATH_BS   // obsolete definition

$$wszREGKEYCONFIGPATH = $$wszREGKEYCERTSVCPATH & "\"$$ & $$wszREGKEYCONFIG
$$wszREGKEYCONFIGPATH_BS = $$wszREGKEYCONFIGPATH & "\"$$
$$wszREGKEYCONFIGCANAME = $$wszREGKEYCONFIGPATH_BS   ' // obsolete definition

' *** Moved from below ***
'// Keys Under "CertSvc\Configuration":
'#define wszREGKEYRESTOREINPROGRESS   TEXT("RestoreInProgress")
'#define wszREGKEYDBPARAMETERS        TEXT("DBParameters")
$$wszREGKEYRESTOREINPROGRESS = "RestoreInProgress"$$
$$wszREGKEYDBPARAMETERS      = "DBParameters"$$

'//======================================================================
'// Full path to "CertSvc\Configuration\RestoreInProgress":
$$wszREGKEYCONFIGRESTORE = $$wszREGKEYCONFIGPATH_BS & $$wszREGKEYRESTOREINPROGRESS

' *** Moved above ***
'//======================================================================
'// Key Under "CertSvc":
'#define wszREGKEYCONFIG      TEXT("Configuration")
'$wszREGKEYCONFIG = "Configuration"

'//======================================================================
'// Values Under "CertSvc\Configuration":
$$wszREGACTIVE                  = "Active"$$
$$wszREGDIRECTORY               = "ConfigurationDirectory"$$
$$wszREGDBDIRECTORY             = "DBDirectory"$$
$$wszREGDBLOGDIRECTORY          = "DBLogDirectory"$$
$$wszREGDBSYSDIRECTORY          = "DBSystemDirectory"$$
$$wszREGDBTEMPDIRECTORY         = "DBTempDirectory"$$
$$wszREGDBSESSIONCOUNT          = "DBSessionCount"$$
$$wszREGDBMAXREADSESSIONCOUNT   = "DBMaxReadSessionCount"$$
$$wszREGDBFLAGS                 = "DBFlags"$$
$$wszREGDBLASTFULLBACKUP        = "DBLastFullBackup"$$
$$wszREGDBLASTINCREMENTALBACKUP = "DBLastIncrementalBackup"$$
$$wszREGDBLASTRECOVERY          = "DBLastRecovery"$$
$$wszREGWEBCLIENTCAMACHINE      = "WebClientCAMachine"$$
$$wszREGVERSION                 = "Version"$$
$$wszREGWEBCLIENTCANAME         = "WebClientCAName"$$
$$wszREGWEBCLIENTCATYPE         = "WebClientCAType"$$
$$wszREGLDAPFLAGS               = "LDAPFlags"$$
$$wszREGCERTSRVDEBUG            = "Debug"$$

'// Default value for wszREGDBSESSIONCOUNT
%DBSESSIONCOUNTDEFAULT        = 100

'//==================================
'// Values for wszREGDBFLAGS

%DBFLAGS_READONLY                = &H00000001   ' // ignored in registry
%DBFLAGS_CREATEIFNEEDED          = &H00000002
%DBFLAGS_CIRCULARLOGGING         = &H00000004
%DBFLAGS_LAZYFLUSH               = &H00000008
%DBFLAGS_MAXCACHESIZEX100        = &H00000010
%DBFLAGS_CHECKPOINTDEPTH60MB     = &H00000020
%DBFLAGS_LOGBUFFERSLARGE         = &H00000040
%DBFLAGS_LOGBUFFERSHUGE          = &H00000080
%DBFLAGS_LOGFILESIZE16MB         = &H00000100
%DBFLAGS_MULTITHREADTRANSACTIONS = &H00000200
%DBFLAGS_DISABLESNAPSHOTBACKUP   = &H00000400   ' // ignored in registry
%DBFLAGS_ENABLEVOLATILEREQUESTS  = &H00000800   ' // enables the use of CCertDBMem

%DBFLAGS_DEFAULT = %DBFLAGS_MAXCACHESIZEX100 OR %DBFLAGS_CHECKPOINTDEPTH60MB OR %DBFLAGS_LOGBUFFERSHUGE


'//==================================
'// Values for wszREGLDAPSSLFLAGS
'// Default is zero (same as a missing registry value):
'//    0: Don't use SSL, but sign all LDAP traffic.
'//    3: Use SSL but don't sign LDAP traffic.
%LDAPF_SSLENABLE   = &H00000001   ' // use SSL for LDAP traffic
%LDAPF_SIGNDISABLE = &H00000002   ' // disable signing LDAP traffic

'// Default value for wszREGMAXINCOMINGMESSAGESIZE
%MAXINCOMINGMESSAGESIZEDEFAULT = (64 * 1024)

'// Default value for wszREGMAXINCOMINGALLOCSIZE
%MAXINCOMINGALLOCSIZEDEFAULT = (64 * 1024)

'// Value for wszREGVERSION:

'// win2k version
%CSVER_MAJOR_WIN2K           = 1   ' // actually this wasn't define in win2k
%CSVER_MINOR_WIN2K           = 1

'// whistler version
%CSVER_MAJOR_WHISTLER        = 2
%CSVER_MINOR_WHISTLER_BETA2  = 1
%CSVER_MINOR_WHISTLER_BETA3  = 2

'// longhorn version
%CSVER_MAJOR_LONGHORN        = 3
%CSVER_MINOR_LONGHORN_BETA1  = 1

'// win7 version
%CSVER_MAJOR_WIN7 = 4
%CSVER_MINOR_WIN7 = 1

'// current version
%CSVER_MAJOR          = %CSVER_MAJOR_WIN7   ' // high 16 bits
%CSVER_MINOR          = %CSVER_MINOR_WIN7   ' // low 16 bits

'// version manipulation
'#define CSVER_EXTRACT_MAJOR(version) ((version)>>16)
FUNCTION CSVER_EXTRACT_MAJOR (BYVAL version AS DWORD) AS WORD
   SHIFT RIGHT version, 16
   FUNCTION = version
END FUNCTION

'#define CSVER_EXTRACT_MINOR(version) ((version)&0xffff)
FUNCTION CSVER_EXTRACT_MINOR (BYVAL version AS DWORD) AS WORD
   FUNCTION = version AND &Hffff??
END FUNCTION

'#define CSVER_BUILD_VERSION(major, minor) (((major)<<16)|(minor))
FUNCTION CSVER_BUILD_VERSION (BYVAL major AS DWORD, BYVAL minor AS DWORD) AS DWORD
   SHIFT LEFT major, 16
   FUNCTION = major OR minor
END FUNCTION

' *** Moved above ***
'// Keys Under "CertSvc\Configuration":
'#define wszREGKEYRESTOREINPROGRESS   TEXT("RestoreInProgress")
'#define wszREGKEYDBPARAMETERS        TEXT("DBParameters")
'$wszREGKEYRESTOREINPROGRESS = "RestoreInProgress"
'$wszREGKEYDBPARAMETERS      = "DBParameters"

'//======================================================================
'// Values Under "CertSvc\Configuration\<CAName>":
$$wszREGCADESCRIPTION          = "CADescription"$$
$$wszREGCACERTHASH             = "CACertHash"$$
$$wszREGCASERIALNUMBER         = "CACertSerialNumber"$$
$$wszREGCAXCHGCERTHASH         = "CAXchgCertHash"$$
$$wszREGKRACERTHASH            = "KRACertHash"$$
$$wszREGKRACERTCOUNT           = "KRACertCount"$$
$$wszREGKRAFLAGS               = "KRAFlags"$$
$$wszREGCATYPE                 = "CAType"$$
$$wszREGCERTENROLLCOMPATIBLE   = "CertEnrollCompatible"$$
$$wszREGENFORCEX500NAMELENGTHS = "EnforceX500NameLengths"$$
$$wszREGCOMMONNAME             = "CommonName"$$
$$wszREGCLOCKSKEWMINUTES       = "ClockSkewMinutes"$$

$$wszREGCRLNEXTPUBLISH         = "CRLNextPublish"$$
$$wszREGCRLPERIODSTRING        = "CRLPeriod"$$
$$wszREGCRLPERIODCOUNT         = "CRLPeriodUnits"$$
$$wszREGCRLOVERLAPPERIODSTRING = "CRLOverlapPeriod"$$
$$wszREGCRLOVERLAPPERIODCOUNT  = "CRLOverlapUnits"$$

$$wszREGCRLDELTANEXTPUBLISH         = "CRLDeltaNextPublish"$$
$$wszREGCRLDELTAPERIODSTRING        = "CRLDeltaPeriod"$$
$$wszREGCRLDELTAPERIODCOUNT         = "CRLDeltaPeriodUnits"$$
$$wszREGCRLDELTAOVERLAPPERIODSTRING = "CRLDeltaOverlapPeriod"$$
$$wszREGCRLDELTAOVERLAPPERIODCOUNT  = "CRLDeltaOverlapUnits"$$

$$wszREGCRLPUBLICATIONURLS     = "CRLPublicationURLs"$$
$$wszREGCACERTPUBLICATIONURLS  = "CACertPublicationURLs"$$

$$wszREGCAXCHGVALIDITYPERIODSTRING  = "CAXchgValidityPeriod"$$
$$wszREGCAXCHGVALIDITYPERIODCOUNT   = "CAXchgValidityPeriodUnits"$$
$$wszREGCAXCHGOVERLAPPERIODSTRING   = "CAXchgOverlapPeriod"$$
$$wszREGCAXCHGOVERLAPPERIODCOUNT    = "CAXchgOverlapPeriodUnits"$$

$$wszREGCRLPATH_OLD             = "CRLPath"$$
$$wszREGCRLEDITFLAGS            = "CRLEditFlags"$$
$$wszREGCRLFLAGS                = "CRLFlags"$$
$$wszREGCRLATTEMPTREPUBLISH     = "CRLAttemptRepublish"$$
$$wszREGENABLED                 = "Enabled"$$
$$wszREGFORCETELETEX            = "ForceTeletex"$$
$$wszREGLOGLEVEL                = "LogLevel"$$
$$wszREGHIGHSERIAL              = "HighSerial"$$
$$wszREGPOLICYFLAGS             = "PolicyFlags"$$
$$wszREGNAMESEPARATOR           = "SubjectNameSeparator"$$
$$wszREGSUBJECTTEMPLATE         = "SubjectTemplate"$$
$$wszREGCAUSEDS                 = "UseDS"$$
$$wszREGVALIDITYPERIODSTRING    = "ValidityPeriod"$$
$$wszREGVALIDITYPERIODCOUNT     = "ValidityPeriodUnits"$$
$$wszREGPARENTCAMACHINE         = "ParentCAMachine"$$
$$wszREGPARENTCANAME            = "ParentCAName"$$
$$wszREGREQUESTFILENAME         = "RequestFileName"$$
$$wszREGREQUESTID               = "RequestId"$$
$$wszREGREQUESTKEYCONTAINER     = "RequestKeyContainer"$$
$$wszREGREQUESTKEYINDEX         = "RequestKeyIndex"$$
$$wszREGCASERVERNAME            = "CAServerName"$$
$$wszREGCACERTFILENAME          = "CACertFileName"$$
$$wszREGCASECURITY              = "Security"$$
$$wszREGAUDITFILTER             = "AuditFilter"$$
$$wszREGOFFICERRIGHTS           = "OfficerRights"$$
$$wszENROLLMENTAGENTRIGHTS      = "EnrollmentAgentRights"$$
$$wszREGMAXINCOMINGMESSAGESIZE  = "MaxIncomingMessageSize"$$
$$wszREGMAXINCOMINGALLOCSIZE    = "MaxIncomingAllocSize"$$
$$wszREGROLESEPARATIONENABLED   = "RoleSeparationEnabled"$$
$$wszREGALTERNATEPUBLISHDOMAINS = "AlternatePublishDomains"$$

$$wszREGSETUPSTATUS            = "SetupStatus"$$
$$wszREGINTERFACEFLAGS         = "InterfaceFlags"$$
$$wszREGDSCONFIGDN             = "DSConfigDN"$$
$$wszREGDSDOMAINDN             = "DSDomainDN"$$
$$wszREGVIEWAGEMINUTES         = "ViewAgeMinutes"$$
$$wszREGVIEWIDLEMINUTES        = "ViewIdleMinutes"$$

'// This REG_DWORD value determines if the CA accepts OCSP Signing certificate
'// enrollment and renewal requests for replaced CA keys.
'// * If the UseDefinedCACertInRequest does not exist, then the default behavior
'//   is used (do not accept certificate requests on replaced CA keys)
'// * Setting the value to 0 is the default setting
'// * Setting the value to a non-zero value enables the CA for certificate
'//   requests for replaced CA keys
$$wszREGUSEDEFINEDCACERTINREQ  = "UseDefinedCACertInRequest"$$

'// This REG_MULTISZ value allows administrators to customize which OIDs can be
'// present in OCSP requesting certificates in order to enroll or renew against
'// replaced CA keys.
'// * If the EnabledEKUForDefinedCACert multi-string entry does not exist,
'//   then the default behavior is used (enforce OCSP EKU in resultant cert)
'// * If a value is present, a basic ASN1 compliance check must be performed on
'//   CA start-up. If compliance of OID fails validation, the CA must log an
'//   error and default to enforce OCSP EKU in resultant cert.
$$wszREGENABLEDEKUFORDEFINEDCACERT = "EnabledEKUForDefinedCACert"$$

'// This REG_MULTISZ value allows administrators to customize which OIDs can be
'// present in certificates that are being revoked and need to be present in CRL
'// regardless of the certificates validity period.
'// * If the EKUOIDsForPublishExpiredCertInCRL multi-string entry does not exist,
'//   then the default behavior is used (default OIDS defined below).
'// * If a value is present, a basic ASN1 compliance check must be performed on
'//   CA start-up. If compliance of OID fails validation, the CA must log an
'//   error and default OIDs (defined below) would be used.
$$wszREGEKUOIDSFORPUBLISHEXPIREDCERTINCRL = "EKUOIDsForPublishExpiredCertInCRL"$$


'#define wszzDEFAULTEKUOIDSFORPUBLISHEXPIREDCERTINCRL \
'    TEXT(szOID_PKIX_KP_CODE_SIGNING) L"\0" \
'    TEXT(szOID_KP_KERNEL_MODE_CODE_SIGNING) L"\0"

$$wszzDEFAULTEKUOIDSFORPUBLISHEXPIREDCERTINCRL = "1.3.6.1.5.5.7.3.3"$$ & CHR$$(0) & "1.3.6.1.4.1.311.61.1.1"$$ & CHR$$(0)

$$wszCRTFILENAMEEXT        = ".crt"$$
$$wszPFXFILENAMEEXT        = ".p12"$$
$$wszDATFILENAMEEXT        = ".dat"$$
$$wszLOGFILENAMEEXT        = ".log"$$
$$wszDBFILENAMEEXT         = ".edb"$$
$szDBBASENAMEPARM          = "edb"
$$wszDBBASENAMEPARM        = "edb"$$   ' $szDBBASENAMEPARM
$$wszLOGPATH               = "CertLog"$$
$$wszDBBACKUPSUBDIR        = "DataBase"$$
$$wszDBBACKUPCERTBACKDAT   = "certbkxp.dat"$$

#IF NOT %DEF(%ENUM_CATYPES)
    %ENUM_CATYPES = 1

'//==================================
'// Values for wszREGCATYPE:
' enum ENUM_CATYPES
%ENUM_ENTERPRISE_ROOTCA = 0
%ENUM_ENTERPRISE_SUBCA = 1
'//ENUM_UNUSED2 = 2,
%ENUM_STANDALONE_ROOTCA = 3
%ENUM_STANDALONE_SUBCA = 4
%ENUM_UNKNOWN_CA = 5

' // Size = 40 bytes
TYPE CAINFO DWORD
   cbSize                 AS DWORD   ' DWORD
   CAType                 AS LONG    ' ENUM_CATYPES
   cCASignatureCerts      AS DWORD   ' DWORD
   cCAExchangeCerts       AS DWORD   ' DWORD
   cExitModules           AS DWORD   ' DWORD
   lPropIdMax             AS LONG    ' LONG
   lRoleSeparationEnabled AS LONG    ' LONG
   cKRACertUsedCount      AS DWORD   ' DWORD
   cKRACertCount          AS DWORD   ' DWORD
   fAdvancedServer        AS DWORD   ' DWORD
END TYPE

#ENDIF   ' __ENUM_CATYPES__

' *** Moved from below ***
'//======================================================================
'// Value strings for "CertSvc\Configuration\<CAName>\ValidityPeriod", etc.:
$$wszPERIODYEARS     = "Years"$$
$$wszPERIODMONTHS    = "Months"$$
$$wszPERIODWEEKS     = "Weeks"$$
$$wszPERIODDAYS      = "Days"$$
$$wszPERIODHOURS     = "Hours"$$
$$wszPERIODMINUTES   = "Minutes"$$
$$wszPERIODSECONDS   = "Seconds"$$

'// Default value for wszREGCLOCKSKEWMINUTES
%CCLOCKSKEWMINUTESDEFAULT        = 10


'// Default value for wszREGVIEWAGEMINUTES, wszREGVIEWIDLEMINUTES
%CVIEWAGEMINUTESDEFAULT          = 16
%CVIEWIDLEMINUTESDEFAULT         = (%CVIEWAGEMINUTESDEFAULT \ 2)

'// Default validity period for ROOT CA certs:
%dwVALIDITYPERIODCOUNTDEFAULT_ROOT   = 5

'// Default validity periods for certs issued by a CA:
%dwVALIDITYPERIODCOUNTDEFAULT_ENTERPRISE = 2
%dwVALIDITYPERIODCOUNTDEFAULT_STANDALONE = 1
%dwVALIDITYPERIODENUMDEFAULT             = %ENUM_PERIOD_YEARS
$$wszVALIDITYPERIODSTRINGDEFAULT         = $$wszPERIODYEARS

%dwCAXCHGVALIDITYPERIODCOUNTDEFAULT    = 1
%dwCAXCHGVALIDITYPERIODENUMDEFAULT     = %ENUM_PERIOD_WEEKS
$$wszCAXCHGVALIDITYPERIODSTRINGDEFAULT = $$wszPERIODWEEKS

%dwCAXCHGOVERLAPPERIODCOUNTDEFAULT     = 1
%dwCAXCHGOVERLAPPERIODENUMDEFAULT      = %ENUM_PERIOD_DAYS
$$wszCAXCHGOVERLAPPERIODSTRINGDEFAULT  = $$wszPERIODDAYS

%dwCRLPERIODCOUNTDEFAULT               = 1
$$wszCRLPERIODSTRINGDEFAULT            = $$wszPERIODWEEKS

%dwCRLOVERLAPPERIODCOUNTDEFAULT        =  0     ' // 0 --> disabled
$$wszCRLOVERLAPPERIODSTRINGDEFAULT     = $$wszPERIODHOURS

%dwCRLDELTAPERIODCOUNTDEFAULT          = 1
$$wszCRLDELTAPERIODSTRINGDEFAULT       = $$wszPERIODDAYS

%dwCRLDELTAOVERLAPPERIODCOUNTDEFAULT   = 0     ' // 0 --> disabled
$$wszCRLDELTAOVERLAPPERIODSTRINGDEFAULT = $$wszPERIODMINUTES


'//==================================
'// Values for wszREGLOGLEVEL:
%CERTLOG_MINIMAL    = 0???   ' (DWORD) 0
%CERTLOG_TERSE      = 1???   ' (DWORD) 1
%CERTLOG_ERROR      = 2???   ' (DWORD) 2
%CERTLOG_WARNING    = 3???   ' (DWORD) 3
%CERTLOG_VERBOSE    = 4???   ' (DWORD) 4
%CERTLOG_EXHAUSTIVE = 5???   ' (DWORD) 5


'//==================================
'// Values for wszREGSETUPSTATUS:
%SETUP_SERVER_FLAG             = &H00000001???   ' // server installed
%SETUP_CLIENT_FLAG             = &H00000002???   ' // client installed
%SETUP_SUSPEND_FLAG            = &H00000004???   ' // incomplete install
%SETUP_REQUEST_FLAG            = &H00000008???   ' // new cert requested
%SETUP_ONLINE_FLAG             = &H00000010???   ' // requested online
%SETUP_DENIED_FLAG             = &H00000020???   ' // request denied
%SETUP_CREATEDB_FLAG           = &H00000040???   ' // create new DB
%SETUP_ATTEMPT_VROOT_CREATE    = &H00000080???   ' // try to create vroots
%SETUP_FORCECRL_FLAG           = &H00000100???   ' // force new CRL(s)

 ' // add server type to CA DS object "flags" attr:
%SETUP_UPDATE_CAOBJECT_SVRTYPE = &H00000200???

%SETUP_SERVER_UPGRADED_FLAG    = &H00000400???   ' // server was upgraded

'// still need to upgrade security:
%SETUP_W2K_SECURITY_NOT_UPGRADED_FLAG = &H00000800???

'// permissons changed while CA was down, certsrv will need to update DS &
'// service when it restarts:
%SETUP_SECURITY_CHANGED           = &H00001000???

'// win2k3 SP1 - global DCOM security has been fixed:
%SETUP_DCOM_SECURITY_UPDATED_FLAG = &H00002000???

'// Indicates that the server is up to date:
%SETUP_SERVER_IS_UP_TO_DATE_FLAG  = &H00004000???


'//==================================
'// Values for wszREGCRLFLAGS:
%CRLF_DELTA_USE_OLDEST_UNEXPIRED_BASE    = &H00000001???   ' // use oldest base:
'// else use newest base CRL that satisfies base CRL propagation delay

%CRLF_DELETE_EXPIRED_CRLS                = &H00000002???
%CRLF_CRLNUMBER_CRITICAL                 = &H00000004???
%CRLF_REVCHECK_IGNORE_OFFLINE            = &H00000008???
%CRLF_IGNORE_INVALID_POLICIES            = &H00000010???
%CRLF_REBUILD_MODIFIED_SUBJECT_ONLY      = &H00000020???
%CRLF_SAVE_FAILED_CERTS                  = &H00000040???
%CRLF_IGNORE_UNKNOWN_CMC_ATTRIBUTES      = &H00000080???
%CRLF_IGNORE_CROSS_CERT_TRUST_ERROR      = &H00000100???
%CRLF_PUBLISH_EXPIRED_CERT_CRLS          = &H00000200???
%CRLF_ENFORCE_ENROLLMENT_AGENT           = &H00000400???
%CRLF_DISABLE_RDN_REORDER                = &H00000800???
%CRLF_DISABLE_ROOT_CROSS_CERTS           = &H00001000???
%CRLF_LOG_FULL_RESPONSE                  = &H00002000???   ' // hex dump response to console
%CRLF_USE_XCHG_CERT_TEMPLATE             = &H00004000???   ' // enforce xchg template access
%CRLF_USE_CROSS_CERT_TEMPLATE            = &H00008000???   ' // enforce cross template access
%CRLF_ALLOW_REQUEST_ATTRIBUTE_SUBJECT    = &H00010000???
%CRLF_REVCHECK_IGNORE_NOREVCHECK         = &H00020000???
%CRLF_PRESERVE_EXPIRED_CA_CERTS          = &H00040000???
%CRLF_PRESERVE_REVOKED_CA_CERTS          = &H00080000???
%CRLF_DISABLE_CHAIN_VERIFICATION         = &H00100000???
%CRLF_BUILD_ROOTCA_CRLENTRIES_BASEDONKEY = &H00200000???

'//==================================
'// Values for wszREGKRAFLAGS:
%KRAF_ENABLEFOREIGN                      = &H00000001???   ' // allow foreign cert, key archival
%KRAF_SAVEBADREQUESTKEY                  = &H00000002???   ' // save failed request w/archived key
%KRAF_ENABLEARCHIVEALL                   = &H00000004???
%KRAF_DISABLEUSEDEFAULTPROVIDER          = &H00000008???

'//==================================
'// Values for wszREGINTERFACEFLAGS:
%IF_LOCKICERTREQUEST                     = &H00000001???
%IF_NOREMOTEICERTREQUEST                 = &H00000002???
%IF_NOLOCALICERTREQUEST                  = &H00000004???
%IF_NORPCICERTREQUEST                    = &H00000008???
%IF_NOREMOTEICERTADMIN                   = &H00000010???
%IF_NOLOCALICERTADMIN                    = &H00000020???
%IF_NOREMOTEICERTADMINBACKUP             = &H00000040???
%IF_NOLOCALICERTADMINBACKUP              = &H00000080???
%IF_NOSNAPSHOTBACKUP                     = &H00000100???
%IF_ENFORCEENCRYPTICERTREQUEST           = &H00000200???
%IF_ENFORCEENCRYPTICERTADMIN             = &H00000400???
%IF_ENABLEEXITKEYRETRIEVAL               = &H00000800???
%IF_ENABLEADMINASAUDITOR                 = &H00001000???

%IF_DEFAULT = (%IF_NOREMOTEICERTADMINBACKUP OR %IF_LOCKICERTREQUEST)

'//==================================
'// Values for numeric prefixes for
'// wszREGCRLPUBLICATIONURLS and wszREGCACERTPUBLICATIONURLS:
'//
'// URL publication template Flags values, encoded as a decimal prefix for URL
'// publication templates in the registry:
'//   "1:c:\winnt\System32\CertSrv\CertEnroll\MyCA.crl"
'//   "2:http:\//MyServer.MyDomain.com/CertEnroll\MyCA.crl"

%CSURL_SERVERPUBLISH      = &H00000001???
%CSURL_ADDTOCERTCDP       = &H00000002???
%CSURL_ADDTOFRESHESTCRL   = &H00000004???
%CSURL_ADDTOCRLCDP        = &H00000008???
%CSURL_PUBLISHRETRY       = &H00000010???
%CSURL_ADDTOCERTOCSP      = &H00000020???
%CSURL_SERVERPUBLISHDELTA = &H00000040???
%CSURL_ADDTOIDP           = &H00000080???
'//======================================================================
'// Keys Under "CertSvc\Configuration\<CAName>":
$$wszREGKEYCSP              = "CSP"$$
$$wszREGKEYENCRYPTIONCSP    = "EncryptionCSP"$$
$$wszREGKEYEXITMODULES      = "ExitModules"$$
$$wszREGKEYPOLICYMODULES    = "PolicyModules"$$
$$wszSECUREDATTRIBUTES      = "SignedAttributes"$$

'#define wszzDEFAULTSIGNEDATTRIBUTES TEXT("RequesterName\0")
$$wszzDEFAULTSIGNEDATTRIBUTES = "RequesterName"$$ & CHR$$(0)

'//======================================================================
'// Values Under "CertSvc\Configuration\RestoreInProgress":
$$wszREGBACKUPLOGDIRECTORY = "BackupLogDirectory"$$
$$wszREGCHECKPOINTFILE     = "CheckPointFile"$$
$$wszREGHIGHLOGNUMBER      = "HighLogNumber"$$
$$wszREGLOWLOGNUMBER       = "LowLogNumber"$$
$$wszREGLOGPATH            = "LogPath"$$
$$wszREGRESTOREMAPCOUNT    = "RestoreMapCount"$$
$$wszREGRESTOREMAP         = "RestoreMap"$$
$$wszREGDATABASERECOVERED  = "DatabaseRecovered"$$
$$wszREGRESTORESTATUS      = "RestoreStatus"$$

'// values under \Configuration\PolicyModules in nt5 beta 2
$$wszREGB2ICERTMANAGEMODULE   = "ICertManageModule"$$
'// values under \Configuration in nt4 sp4
$$wszREGSP4DEFAULTCONFIGURATION  = "DefaultConfiguration"$$
'// values under ca in nt4 sp4
$$wszREGSP4KEYSETNAME            = "KeySetName"$$
$$wszREGSP4SUBJECTNAMESEPARATOR  = "SubjectNameSeparator"$$
$$wszREGSP4NAMES                 = "Names"$$
$$wszREGSP4QUERIES               = "Queries"$$
'// both nt4 sp4 and nt5 beta 2
$$wszREGNETSCAPECERTTYPE         = "NetscapeCertType"$$
$$wszNETSCAPEREVOCATIONTYPE      = "Netscape"$$


'//======================================================================
'// Values Under "CertSvc\Configuration\<CAName>\CSP":
'// and "CertSvc\Configuration\<CAName>\EncryptionCSP":
$$wszREGPROVIDERTYPE     = "ProviderType"$$
$$wszREGPROVIDER         = "Provider"$$
$$wszHASHALGORITHM       = "HashAlgorithm"$$
$$wszENCRYPTIONALGORITHM = "EncryptionAlgorithm"$$
$$wszMACHINEKEYSET       = "MachineKeyset"$$
$$wszREGKEYSIZE          = "KeySize"$$
$$wszREGSYMMETRICKEYSIZE = "SymmetricKeySize"$$
$$wszCNGPUBLICKEYALGORITHM = "CNGPublicKeyAlgorithm"$$
$$wszCNGHASHALGORITHM       = "CNGHashAlgorithm"$$
$$wszCNGENCRYPTIONALGORITHM = "CNGEncryptionAlgorithm"$$
$$wszREGALTERNATESIGNATUREALGORITHM = "AlternateSignatureAlgorithm"$$

'//======================================================================
'// Value strings for "CertSvc\Configuration\<CAName>\SubjectNameSeparator":
$szNAMESEPARATORDEFAULT  = "\n"
'#define wszNAMESEPARATORDEFAULT   TEXT(szNAMESEPARATORDEFAULT)
$$wszNAMESEPARATORDEFAULT  = "\n"$$


' *** Moved above ***
'//======================================================================
'// Value strings for "CertSvc\Configuration\<CAName>\ValidityPeriod", etc.:
'#define wszPERIODYEARS     TEXT("Years")
'#define wszPERIODMONTHS    TEXT("Months")
'#define wszPERIODWEEKS     TEXT("Weeks")
'#define wszPERIODDAYS      TEXT("Days")
'#define wszPERIODHOURS     TEXT("Hours")
'#define wszPERIODMINUTES   TEXT("Minutes")
'#define wszPERIODSECONDS   TEXT("Seconds")

'//======================================================================
'// Values Under "CertSvc\Configuration\<CAName>\PolicyModules\<ProgId>":
$$wszREGISSUERCERTURLFLAGS    = "IssuerCertURLFlags"$$
$$wszREGEDITFLAGS             = "EditFlags"$$
$$wszREGUPNMAP                = "UPNMap"$$
$$wszREGSUBJECTALTNAME        = "SubjectAltName"$$
$$wszREGSUBJECTALTNAME2       = "SubjectAltName2"$$
$$wszREGREQUESTDISPOSITION    = "RequestDisposition"$$
$$wszREGCAPATHLENGTH          = "CAPathLength"$$
$$wszREGREVOCATIONTYPE        = "RevocationType"$$

$$wszREGLDAPREVOCATIONCRLURL_OLD   = "LDAPRevocationCRLURL"$$
$$wszREGREVOCATIONCRLURL_OLD       = "RevocationCRLURL"$$
$$wszREGFTPREVOCATIONCRLURL_OLD    = "FTPRevocationCRLURL"$$
$$wszREGFILEREVOCATIONCRLURL_OLD   = "FileRevocationCRLURL"$$

$$wszREGREVOCATIONURL      = "RevocationURL"$$

$$wszREGLDAPISSUERCERTURL_OLD   = "LDAPIssuerCertURL"$$
$$wszREGISSUERCERTURL_OLD       = "IssuerCertURL"$$
$$wszREGFTPISSUERCERTURL_OLD    = "FTPIssuerCertURL"$$
$$wszREGFILEISSUERCERTURL_OLD   = "FileIssuerCertURL"$$

$$wszREGENABLEREQUESTEXTENSIONLIST = "EnableRequestExtensionList"$$
$$wszREGENABLEENROLLEEREQUESTEXTENSIONLIST = "EnableEnrolleeRequestExtensionList"$$
$$wszREGDISABLEEXTENSIONLIST = "DisableExtensionList"$$

'// This REG_MULTISZ value allows administrators to control
'// which certificate requests get written to the database.
'// the EnableVolatileRequests registry value must be enabled for this to work
'// * If a value is present, a basic ASN1 compliance check must be performed on
'//   policy module start-up. If the compliance of OIDs fail validation, the policy module must fail to initialize.
$$wszREGEKUOIDSFORVOLATILEREQUESTS = "EKUOIDsforVolatileRequests"$$

'// Following values would be used to configure the ldap session during setup of connection to DC from
'// policy module
'// CertSvc\Configuration\<CAName>\PolicyModules\<ProgId>\LdapSessionOptions\
'//                                        OptionId1\
'//                                                  LDAPSessionOptionValue
'//                                        OptionId2\
'//                                                  LDAPSessionOptionValue
'//                                        OptionId3\
'//                                                  LDAPSessionOptionValue
'//                                        ...
'// OptionId* should be the decimal equivalent of ldap session option identifier
'// (see ldap_set_option for the id and allowed values).
'// LDAPSessionOptionValue should be REG_DWORD (meaning only options whose value
'// is of integer type can be set by configuring this registry key
'//
$$wszREGLDAPSESSIONOPTIONS    = "LDAPSessionOptions"$$
$$wszLDAPSESSIONOPTIONVALUE   = "LDAPSessionOptionValue"$$

$$wszREGDEFAULTSMIME      = "DefaultSMIME"$$

'// wszREGCAPATHLENGTH Values:
%CAPATHLENGTH_INFINITE       = &Hffffffff???

'// wszREGREQUESTDISPOSITION Values:
%REQDISP_PENDING             = &H00000000???
%REQDISP_ISSUE               = &H00000001???
%REQDISP_DENY                = &H00000002???
%REQDISP_USEREQUESTATTRIBUTE = &H00000003???
%REQDISP_MASK                = &H000000ff???
%REQDISP_PENDINGFIRST        = &H00000100???
%REQDISP_DEFAULT_STANDALONE  = %REQDISP_PENDINGFIRST OR %REQDISP_ISSUE
%REQDISP_DEFAULT_ENTERPRISE  = %REQDISP_ISSUE

'// wszREGREVOCATIONTYPE Values:
%REVEXT_CDPLDAPURL_OLD       = &H00000001???
%REVEXT_CDPHTTPURL_OLD       = &H00000002???
%REVEXT_CDPFTPURL_OLD        = &H00000004???
%REVEXT_CDPFILEURL_OLD       = &H00000008???
%REVEXT_CDPURLMASK_OLD       = &H000000ff???
%REVEXT_CDPENABLE            = &H00000100???
%REVEXT_ASPENABLE            = &H00000200???

%REVEXT_DEFAULT_NODS         = %REVEXT_CDPENABLE
%REVEXT_DEFAULT_DS           = %REVEXT_CDPENABLE

'// wszREGISSUERCERTURLFLAGS Values:
%ISSCERT_LDAPURL_OLD         = &H00000001???
%ISSCERT_HTTPURL_OLD         = &H00000002???
%ISSCERT_FTPURL_OLD          = &H00000004???
%ISSCERT_FILEURL_OLD         = &H00000008???
%ISSCERT_URLMASK_OLD         = &H000000ff???
%ISSCERT_ENABLE              = &H00000100???

%ISSCERT_DEFAULT_NODS        = %ISSCERT_ENABLE
%ISSCERT_DEFAULT_DS          = %ISSCERT_ENABLE

'// wszREGEDITFLAGS Values:               Defaults:
'// Under CA key: wszREGCRLEDITFLAGS Values (EDITF_ENABLEAKI* only):
%EDITF_ENABLEREQUESTEXTENSIONS  = &H00000001???   ' // neither
%EDITF_REQUESTEXTENSIONLIST     = &H00000002???   ' // both
%EDITF_DISABLEEXTENSIONLIST     = &H00000004???   ' // both
%EDITF_ADDOLDKEYUSAGE           = &H00000008???   ' // both
%EDITF_ADDOLDCERTTYPE           = &H00000010???   ' // neither
%EDITF_ATTRIBUTEENDDATE         = &H00000020???   ' // Standalone
%EDITF_BASICCONSTRAINTSCRITICAL = &H00000040???   ' // both
%EDITF_BASICCONSTRAINTSCA       = &H00000080???   ' // Standalone
%EDITF_ENABLEAKIKEYID           = &H00000100???   ' // both
%EDITF_ATTRIBUTECA              = &H00000200???   ' // Standalone
%EDITF_IGNOREREQUESTERGROUP     = &H00000400???   ' // neither
%EDITF_ENABLEAKIISSUERNAME      = &H00000800???   ' // neither
%EDITF_ENABLEAKIISSUERSERIAL    = &H00001000???   ' // neither
%EDITF_ENABLEAKICRITICAL        = &H00002000???   ' // neither
%EDITF_SERVERUPGRADED           = &H00004000???   ' // neither
%EDITF_ATTRIBUTEEKU             = &H00008000???   ' // Standalone
%EDITF_ENABLEDEFAULTSMIME       = &H00010000???   ' // Enterprise
%EDITF_EMAILOPTIONAL            = &H00020000???   ' // neither
%EDITF_ATTRIBUTESUBJECTALTNAME2 = &H00040000???   ' // neither
%EDITF_ENABLELDAPREFERRALS      = &H00080000???   ' // neither
%EDITF_ENABLECHASECLIENTDC      = &H00100000???   ' // Enterprise
%EDITF_AUDITCERTTEMPLATELOAD    = &H00200000???   ' // neither
%EDITF_DISABLEOLDOSCNUPN        = &H00400000???   ' // neither
%EDITF_DISABLELDAPPACKAGELIST   = &H00800000???   ' // neither
%EDITF_ENABLEUPNMAP             = &H01000000???   ' // neither
%EDITF_ENABLEOCSPREVNOCHECK     = &H02000000???   ' // neither
%EDITF_ENABLERENEWONBEHALFOF    = &H04000000???   ' // Enterprise

%EDITF_DEFAULT_STANDALONE = %EDITF_REQUESTEXTENSIONLIST OR _
                            %EDITF_DISABLEEXTENSIONLIST OR _
                            %EDITF_ADDOLDKEYUSAGE OR _
                            %EDITF_ATTRIBUTEENDDATE OR _
                            %EDITF_BASICCONSTRAINTSCRITICAL OR _
                            %EDITF_BASICCONSTRAINTSCA OR _
                            %EDITF_ENABLEAKIKEYID OR _
                            %EDITF_ATTRIBUTECA OR _
                            %EDITF_ATTRIBUTEEKU

%EDITF_DEFAULT_ENTERPRISE = %EDITF_REQUESTEXTENSIONLIST OR _
                            %EDITF_DISABLEEXTENSIONLIST OR _
                            %EDITF_ADDOLDKEYUSAGE OR _
                            %EDITF_BASICCONSTRAINTSCRITICAL OR _
                            %EDITF_ENABLEAKIKEYID OR _
                            %EDITF_ENABLEDEFAULTSMIME OR _
                            %EDITF_ENABLECHASECLIENTDC


'//======================================================================
'// Values Under "CertSvc\Configuration\<CAName>\ExitModules\<ProgId>":

'// LDAP based CRL and URL issuance
$$wszREGLDAPREVOCATIONDN_OLD         = "LDAPRevocationDN"$$
$$wszREGLDAPREVOCATIONDNTEMPLATE_OLD = "LDAPRevocationDNTemplate"$$
$$wszCRLPUBLISHRETRYCOUNT            = "CRLPublishRetryCount"$$
$$wszREGCERTPUBLISHFLAGS             = "PublishCertFlags"$$

'// wszREGCERTPUBLISHFLAGS Values:
%EXITPUB_FILE            = &H00000001???
%EXITPUB_ACTIVEDIRECTORY = &H00000002???
%EXITPUB_REMOVEOLDCERTS  = &H00000010???

%EXITPUB_DEFAULT_ENTERPRISE = %EXITPUB_ACTIVEDIRECTORY

%EXITPUB_DEFAULT_STANDALONE = %EXITPUB_FILE

$$wszCLASS_CERTADMIN     = "CertificateAuthority.Admin"$$
$$wszCLASS_CERTCONFIG    = "CertificateAuthority.Config"$$
$$wszCLASS_CERTGETCONFIG = "CertificateAuthority.GetConfig"$$

$$wszCLASS_CERTENCODE       = "CertificateAuthority.Encode"$$
$$wszCLASS_CERTDBMEM        = "CertificateAuthority.DBMem"$$   ' // no_certs
$$wszCLASS_CERTREQUEST      = "CertificateAuthority.Request"$$
$$wszCLASS_CERTSERVEREXIT   = "CertificateAuthority.ServerExit"$$
$$wszCLASS_CERTSERVERPOLICY = "CertificateAuthority.ServerPolicy"$$
$$wszCLASS_CERTVIEW         = "CertificateAuthority.View"$$

'// class name templates
$$wszMICROSOFTCERTMODULE_PREFIX = "CertificateAuthority_MicrosoftDefault"$$
$$wszCERTMANAGE_SUFFIX = "Manage"$$
$$wszCERTEXITMODULE_POSTFIX = ".Exit"$$
$$wszCERTMANAGEEXIT_POSTFIX = $$wszCERTEXITMODULE_POSTFIX & $$wszCERTMANAGE_SUFFIX
$$wszCERTPOLICYMODULE_POSTFIX = ".Policy"$$
$$wszCERTMANAGEPOLICY_POSTFIX = $$wszCERTPOLICYMODULE_POSTFIX & $$wszCERTMANAGE_SUFFIX

'// actual policy/exit manage class names
$$wszCLASS_CERTMANAGEEXITMODULE = $$wszMICROSOFTCERTMODULE_PREFIX & $$wszCERTMANAGEEXIT_POSTFIX

$$wszCLASS_CERTMANAGEPOLICYMODULE = $$wszMICROSOFTCERTMODULE_PREFIX & $$wszCERTMANAGEPOLICY_POSTFIX

'// actual policy/exit class names
$$wszCLASS_CERTEXIT = $$wszMICROSOFTCERTMODULE_PREFIX & $$wszCERTEXITMODULE_POSTFIX

$$wszCLASS_CERTPOLICY = $$wszMICROSOFTCERTMODULE_PREFIX & $$wszCERTPOLICYMODULE_POSTFIX


$$wszCAPOLICYFILE         = "CAPolicy.inf"$$

$$wszINFSECTION_CDP      = "CRLDistributionPoint"$$
$$wszINFSECTION_AIA      = "AuthorityInformationAccess"$$
$$wszINFSECTION_EKU      = "EnhancedKeyUsageExtension"$$
$$wszINFSECTION_CCDP     = "CrossCertificateDistributionPointsExtension"$$

$$wszINFSECTION_CERTSERVER              = "certsrv_server"$$
$$wszINFKEY_RENEWALKEYLENGTH            = "RenewalKeyLength"$$
$$wszINFKEY_RENEWALVALIDITYPERIODSTRING = "RenewalValidityPeriod"$$
$$wszINFKEY_RENEWALVALIDITYPERIODCOUNT  = "RenewalValidityPeriodUnits"$$
$$wszINFKEY_UTF8                        = "UTF8"$$
$$wszINFKEY_CRLPERIODSTRING             = $$wszREGCRLPERIODSTRING
$$wszINFKEY_CRLPERIODCOUNT              = $$wszREGCRLPERIODCOUNT
$$wszINFKEY_CRLDELTAPERIODSTRING        = $$wszREGCRLDELTAPERIODSTRING
$$wszINFKEY_CRLDELTAPERIODCOUNT         = $$wszREGCRLDELTAPERIODCOUNT
$$wszINFKEY_LOADDEFAULTTEMPLATES        = "LoadDefaultTemplates"$$
$$wszINFKEY_ENABLEKEYCOUNTING           = "EnableKeyCounting"$$
$$wszINFKEY_FORCEUTF8                   = "ForceUTF8"$$
$$wszINFKEY_ALTERNATESIGNATUREALGORITHM = $$wszREGALTERNATESIGNATUREALGORITHM
$$wszINFKEY_SHOWALLCSPS                 = "ShowAllCSPs"$$

$$wszINFKEY_CRITICAL      = "Critical"$$
$$wszINFKEY_EMPTY         = "Empty"$$

$$wszINFKEY_CCDPSYNCDELTATIME   = "SyncDeltaTime"$$

$$wszINFSECTION_CAPOLICY                   = "CAPolicy"$$
$$wszINFSECTION_POLICYSTATEMENT            = "PolicyStatementExtension"$$
$$wszINFSECTION_APPLICATIONPOLICYSTATEMENT = "ApplicationPolicyStatementExtension"$$
$$wszINFKEY_POLICIES                       = "Policies"$$
$$wszINFKEY_OID                            = "OID"$$
$$wszINFKEY_NOTICE                         = "Notice"$$
$$wszINFKEY_FLAGS                          = "Flags"$$

$$wszINFSECTION_REQUESTATTRIBUTES   = "RequestAttributes"$$

$$wszINFSECTION_NAMECONSTRAINTS = "NameConstraintsExtension"$$
$$wszINFKEY_INCLUDE             = "Include"$$
$$wszINFKEY_EXCLUDE             = "Exclude"$$

'// for [Extensions] section Name Constraints processing:
$$wszINFKEY_SUBTREE      = "SubTree"$$

$$wszINFKEY_UPN           = "UPN"$$
$$wszINFKEY_EMAIL         = "EMail"$$
$$wszINFKEY_DNS           = "DNS"$$
$$wszINFKEY_DIRECTORYNAME = "DirectoryName"$$
$$wszINFKEY_URL           = "URL"$$
$$wszINFKEY_IPADDRESS     = "IPAddress"$$
$$wszINFKEY_REGISTEREDID  = "RegisteredId"$$
$$wszINFKEY_OTHERNAME     = "OtherName"$$

$$wszINFSECTION_POLICYMAPPINGS = "PolicyMappingsExtension"$$
$$wszINFSECTION_APPLICATIONPOLICYMAPPINGS = "ApplicationPolicyMappingsExtension"$$

$$wszINFSECTION_POLICYCONSTRAINTS            = "PolicyConstraintsExtension"$$
$$wszINFSECTION_APPLICATIONPOLICYCONSTRAINTS = "ApplicationPolicyConstraintsExtension"$$
$$wszINFKEY_REQUIREEXPLICITPOLICY            = "RequireExplicitPolicy"$$
$$wszINFKEY_INHIBITPOLICYMAPPING             = "InhibitPolicyMapping"$$

$$wszINFSECTION_BASICCONSTRAINTS = "BasicConstraintsExtension"$$
$$wszINFKEY_PATHLENGTH           = "PathLength"$$

$$wszINFSECTION_EXTENSIONS   = "Extensions"$$
$$wszINFSECTION_PROPERTIES   = "Properties"$$

$$wszINFKEY_CONTINUE      = "_continue_"$$

' *** Moved from below ***
'//+--------------------------------------------------------------------------
'// Request properties:
$$wszPROPREQUESTDOT               = "Request."$$

$$wszPROPREQUESTREQUESTID                = "RequestID"$$
$$wszPROPREQUESTRAWREQUEST               = "RawRequest"$$
$$wszPROPREQUESTRAWARCHIVEDKEY           = "RawArchivedKey"$$
$$wszPROPREQUESTARCHIVEDKEY              = "ArchivedKey"$$   ' // constructed
$$wszPROPREQUESTKEYRECOVERYHASHES        = "KeyRecoveryHashes"$$
$$wszPROPREQUESTRAWOLDCERTIFICATE        = "RawOldCertificate"$$
$$wszPROPREQUESTATTRIBUTES               = "RequestAttributes"$$
$$wszPROPREQUESTTYPE                     = "RequestType"$$
$$wszPROPREQUESTFLAGS                    = "RequestFlags"$$
$$wszPROPREQUESTSTATUSCODE               = "StatusCode"$$
$$wszPROPREQUESTDISPOSITION              = "Disposition"$$
$$wszPROPREQUESTDISPOSITIONMESSAGE       = "DispositionMessage"$$
$$wszPROPREQUESTSUBMITTEDWHEN            = "SubmittedWhen"$$
$$wszPROPREQUESTRESOLVEDWHEN             = "ResolvedWhen"$$
$$wszPROPREQUESTREVOKEDWHEN              = "RevokedWhen"$$
$$wszPROPREQUESTREVOKEDEFFECTIVEWHEN     = "RevokedEffectiveWhen"$$
$$wszPROPREQUESTREVOKEDREASON            = "RevokedReason"$$
$$wszPROPREQUESTERNAME                   = "RequesterName"$$
$$wszPROPCALLERNAME                      = "CallerName"$$
$$wszPROPSIGNERPOLICIES                  = "SignerPolicies"$$
$$wszPROPSIGNERAPPLICATIONPOLICIES       = "SignerApplicationPolicies"$$
$$wszPROPOFFICER                         = "Officer"$$
$$wszPROPPUBLISHEXPIREDCERTINCRL         = "PublishExpiredCertInCRL"$$
$$wszPROPREQUESTERNAMEFROMOLDCERTIFICATE = "RequesterNameFromOldCertificate"$$

$$wszINFSECTION_NEWREQUEST      = "NewRequest"$$
$$wszINFKEY_SUBJECT             = "Subject"$$
$$wszINFKEY_SUBJECTNAMEFLAGS    = "SubjectNameFlags"$$
$$wszINFKEY_X500NAMEFLAGS       = "X500NameFlags"$$
$$wszINFKEY_EXPORTABLE          = "Exportable"$$
$$wszINFKEY_EXPORTABLEENCRYPTED = "ExportableEncrypted"$$
$$wszINFKEY_HASHALGORITHM       = "HashAlgorithm"$$
$$wszINFKEY_KEYALGORITHM        = "KeyAlgorithm"$$
$$wszINFKEY_KEYCONTAINER        = "KeyContainer"$$
$$wszINFKEY_KEYLENGTH           = "KeyLength"$$
$$wszINFKEY_LEGACYKEYSPEC       = "KeySpec"$$
$$wszINFKEY_KEYUSAGEEXTENSION   = "KeyUsage"$$
$$wszINFKEY_KEYUSAGEPROPERTY    = "KeyUsageProperty"$$
$$wszINFKEY_MACHINEKEYSET       = "MachineKeySet"$$
$$wszINFKEY_PRIVATEKEYARCHIVE   = "PrivateKeyArchive"$$
$$wszINFKEY_ENCRYPTIONALGORITHM = "EncryptionAlgorithm"$$
$$wszINFKEY_ENCRYPTIONLENGTH    = "EncryptionLength"$$
$$wszINFKEY_PROVIDERNAME        = "ProviderName"$$
$$wszINFKEY_PROVIDERTYPE        = "ProviderType"$$
$$wszINFKEY_RENEWALCERT         = "RenewalCert"$$
$$wszINFKEY_REQUESTERNAME       = $$wszPROPREQUESTERNAME
$$wszINFKEY_REQUESTTYPE         = "RequestType"$$
$$wszINFKEY_SECURITYDESCRIPTOR  = "SecurityDescriptor"$$
'// #define wszINFKEY_ALTERNATESIGNATUREALGORITHM wszREGALTERNATESIGNATUREALGORITHM
$$wszINFKEY_SILENT              = "Silent"$$
$$wszINFKEY_SMIME               = "SMIME"$$
$$wszINFKEY_SUPPRESSDEFAULTS    = "SuppressDefaults"$$
$$wszINFKEY_USEEXISTINGKEY      = "UseExistingKeySet"$$
$$wszINFKEY_USERPROTECTED       = "UserProtected"$$   '// deprecated
$$wszINFKEY_KEYPROTECTION       = "KeyProtection"$$
$$wszINFKEY_UICONTEXTMESSAGE    = "UIContextMessage"$$
$$wszINFKEY_FRIENDLYNAME        = "FriendlyName"$$

$$wszINFVALUE_REQUESTTYPE_PKCS10 = "PKCS10"$$
$$wszINFVALUE_REQUESTTYPE_PKCS7  = "PKCS7"$$
$$wszINFVALUE_REQUESTTYPE_CMC    = "CMC"$$
$$wszINFVALUE_REQUESTTYPE_CERT   = "Cert"$$

'//======================================================================
'// Values Under "CertSvc\Configuration\<CAName>\ExitModules\CertificateAuthority_MicrosoftDefault.Exit\SMTP":
'//
'// exit module mail support
'//
$$wszREGEXITSMTPKEY            = "SMTP"$$
$$wszREGEXITSMTPTEMPLATES      = "Templates"$$
$$wszREGEXITSMTPEVENTFILTER    = "EventFilter"$$
$$wszREGEXITSMTPSERVER         = "SMTPServer"$$
$$wszREGEXITSMTPAUTHENTICATE   = "SMTPAuthenticate"$$

'// Subkeys:
$$wszREGEXITDENIEDKEY      = "Denied"$$
$$wszREGEXITISSUEDKEY      = "Issued"$$
$$wszREGEXITPENDINGKEY     = "Pending"$$
$$wszREGEXITREVOKEDKEY     = "Revoked"$$
$$wszREGEXITCRLISSUEDKEY   = "CRLIssued"$$
$$wszREGEXITSHUTDOWNKEY    = "Shutdown"$$
$$wszREGEXITSTARTUPKEY     = "Startup"$$
$$wszREGEXITIMPORTEDKEY    = "Imported"$$

'//======================================================================
'// Values Under
'// "CertSvc\Configuration\<CAName>\ExitModules\CertificateAuthority_MicrosoftDefault.Exit\SMTP\Issued|
'// Pending|Denied|Revoked|CRLIssued|Shutdown":
$$wszREGEXITSMTPFROM    = "From"$$
$$wszREGEXITSMTPTO      = "To"$$
$$wszREGEXITSMTPCC      = "Cc"$$
$$wszREGEXITTITLEFORMAT = "TitleFormat"$$
$$wszREGEXITTITLEARG    = "TitleArg"$$
$$wszREGEXITBODYFORMAT  = "BodyFormat"$$
$$wszREGEXITBODYARG     = "BodyArg"$$

$$wszREGEXITPROPNOTFOUND = "???"$$

'//======================================================================
'// Full path to HKLM or HKCU "AutoEnrollment" key:
$$wszREGKEYENROLLMENT = "SOFTWARE\\Microsoft\\Cryptography\\AutoEnrollment"$$
$$wszREGKEYGROUPPOLICYENROLLMENT = "SOFTWARE\\Policies\\Microsoft\\Cryptography\\AutoEnrollment"$$

'// Values Under "...\Cryptography\AutoEnrollment"

$$wszREGMAXPENDINGREQUESTDAYS = "MaxPendingRequestDays"$$
$$wszREGAELOGLEVEL_OLD        = "AEEventLogLevel"$$   ' // obsolete
'// #define wszREGLOGLEVEL      TEXT("LogLevel")   // new
'// #define wszREGCERTSRVDEBUG      TEXT("Debug")
'// #define AUTO_ENROLLMENT_FLAG      TEXT("AEFlags")       // autoenr.h
$$wszREGENROLLFLAGS      = "EnrollFlags"$$
$$wszREGVERIFYFLAGS      = "VerifyFlags"$$


'//+--------------------------------------------------------------------------
'// Name properties:

$$wszPROPDISTINGUISHEDNAME   = "DistinguishedName"$$
$$wszPROPRAWNAME             = "RawName"$$

$$wszPROPCOUNTRY             = "Country"$$
$$wszPROPORGANIZATION        = "Organization"$$
$$wszPROPORGUNIT             = "OrgUnit"$$
$$wszPROPCOMMONNAME          = "CommonName"$$
$$wszPROPLOCALITY            = "Locality"$$
$$wszPROPSTATE               = "State"$$
$$wszPROPTITLE               = "Title"$$
$$wszPROPGIVENNAME           = "GivenName"$$
$$wszPROPINITIALS            = "Initials"$$
$$wszPROPSURNAME             = "SurName"$$
$$wszPROPDOMAINCOMPONENT     = "DomainComponent"$$
$$wszPROPEMAIL               = "EMail"$$
$$wszPROPSTREETADDRESS       = "StreetAddress"$$
$$wszPROPUNSTRUCTUREDNAME    = "UnstructuredName"$$
$$wszPROPUNSTRUCTUREDADDRESS = "UnstructuredAddress"$$
$$wszPROPDEVICESERIALNUMBER  = "DeviceSerialNumber"$$

'//+--------------------------------------------------------------------------
'// Subject Name properties:

$$wszPROPSUBJECTDOT = "Subject."$$
$$wszPROPSUBJECTDISTINGUISHEDNAME = $$wszPROPSUBJECTDOT & $$wszPROPDISTINGUISHEDNAME
$$wszPROPSUBJECTRAWNAME = $$wszPROPSUBJECTDOT & $$wszPROPRAWNAME

$$wszPROPSUBJECTCOUNTRY       = $$wszPROPSUBJECTDOT & $$wszPROPCOUNTRY
$$wszPROPSUBJECTORGANIZATION  = $$wszPROPSUBJECTDOT & $$wszPROPORGANIZATION
$$wszPROPSUBJECTORGUNIT       = $$wszPROPSUBJECTDOT & $$wszPROPORGUNIT
$$wszPROPSUBJECTCOMMONNAME    = $$wszPROPSUBJECTDOT & $$wszPROPCOMMONNAME
$$wszPROPSUBJECTLOCALITY      = $$wszPROPSUBJECTDOT & $$wszPROPLOCALITY
$$wszPROPSUBJECTSTATE         = $$wszPROPSUBJECTDOT & $$wszPROPSTATE
$$wszPROPSUBJECTTITLE         = $$wszPROPSUBJECTDOT & $$wszPROPTITLE
$$wszPROPSUBJECTGIVENNAME     = $$wszPROPSUBJECTDOT & $$wszPROPGIVENNAME
$$wszPROPSUBJECTINITIALS      = $$wszPROPSUBJECTDOT & $$wszPROPINITIALS
$$wszPROPSUBJECTSURNAME       = $$wszPROPSUBJECTDOT & $$wszPROPSURNAME
$$wszPROPSUBJECTDOMAINCOMPONENT = $$wszPROPSUBJECTDOT & $$wszPROPDOMAINCOMPONENT
$$wszPROPSUBJECTEMAIL         = $$wszPROPSUBJECTDOT & $$wszPROPEMAIL
$$wszPROPSUBJECTSTREETADDRESS = $$wszPROPSUBJECTDOT & $$wszPROPSTREETADDRESS
$$wszPROPSUBJECTUNSTRUCTUREDNAME = $$wszPROPSUBJECTDOT & $$wszPROPUNSTRUCTUREDNAME
$$wszPROPSUBJECTUNSTRUCTUREDADDRESS = $$wszPROPSUBJECTDOT & $$wszPROPUNSTRUCTUREDADDRESS
$$wszPROPSUBJECTDEVICESERIALNUMBER = $$wszPROPSUBJECTDOT & $$wszPROPDEVICESERIALNUMBER

'' *** Moved above ***
''//+--------------------------------------------------------------------------
''// Request properties:
''#define wszPROPREQUESTDOT               TEXT("Request.")
'$wszPROPREQUESTDOT               = "Request."

''#define wszPROPREQUESTREQUESTID          TEXT("RequestID")
''#define wszPROPREQUESTRAWREQUEST       TEXT("RawRequest")
''#define wszPROPREQUESTRAWARCHIVEDKEY       TEXT("RawArchivedKey")
''#define wszPROPREQUESTARCHIVEDKEY       TEXT("ArchivedKey")   // constructed
''#define wszPROPREQUESTKEYRECOVERYHASHES       TEXT("KeyRecoveryHashes")
''#define wszPROPREQUESTRAWOLDCERTIFICATE       TEXT("RawOldCertificate")
''#define wszPROPREQUESTATTRIBUTES       TEXT("RequestAttributes")
''#define wszPROPREQUESTTYPE          TEXT("RequestType")
''#define wszPROPREQUESTFLAGS          TEXT("RequestFlags")
''#define wszPROPREQUESTSTATUSCODE       TEXT("StatusCode")
''#define wszPROPREQUESTDISPOSITION       TEXT("Disposition")
''#define wszPROPREQUESTDISPOSITIONMESSAGE    TEXT("DispositionMessage")
''#define wszPROPREQUESTSUBMITTEDWHEN       TEXT("SubmittedWhen")
''#define wszPROPREQUESTRESOLVEDWHEN       TEXT("ResolvedWhen")
''#define wszPROPREQUESTREVOKEDWHEN       TEXT("RevokedWhen")
''#define wszPROPREQUESTREVOKEDEFFECTIVEWHEN  TEXT("RevokedEffectiveWhen")
''#define wszPROPREQUESTREVOKEDREASON       TEXT("RevokedReason")
''#define wszPROPREQUESTERNAME          TEXT("RequesterName")
''#define wszPROPCALLERNAME          TEXT("CallerName")
''#define wszPROPSIGNERPOLICIES          TEXT("SignerPolicies")
''#define wszPROPSIGNERAPPLICATIONPOLICIES    TEXT("SignerApplicationPolicies")
''#define wszPROPOFFICER             TEXT("Officer")
''#define wszPROPPUBLISHEXPIREDCERTINCRL      TEXT("PublishExpiredCertInCRL")
''#define wszPROPREQUESTERNAMEFROMOLDCERTIFICATE TEXT("RequesterNameFromOldCertificate")

'//+--------------------------------------------------------------------------
'// Request attribute properties:

$$wszPROPCHALLENGE         = "Challenge"$$
$$wszPROPEXPECTEDCHALLENGE = "ExpectedChallenge"$$

$$wszPROPDISPOSITION        = "Disposition"$$
$$wszPROPDISPOSITIONDENY    = "Deny"$$
$$wszPROPDISPOSITIONPENDING = "Pending"$$

$$wszPROPVALIDITYPERIODSTRING = "ValidityPeriod"$$
$$wszPROPVALIDITYPERIODCOUNT  = "ValidityPeriodUnits"$$
$$wszPROPEXPIRATIONDATE       = "ExpirationDate"$$

$$wszPROPCERTTYPE     = "CertType"$$
$$wszPROPCERTTEMPLATE = "CertificateTemplate"$$
$$wszPROPCERTUSAGE    = "CertificateUsage"$$

$$wszPROPREQUESTOSVERSION   = "RequestOSVersion"$$
$$wszPROPREQUESTCSPPROVIDER = "RequestCSPProvider"$$

$$wszPROPEXITCERTFILE         = "CertFile"$$
$$wszPROPCLIENTBROWSERMACHINE = "cbm"$$
$$wszPROPCERTCLIENTMACHINE    = "ccm"$$
$$wszPROPCLIENTDCDNS          = "cdc"$$
$$wszPROPREQUESTMACHINEDNS    = "rmd"$$
$$wszPROPSUBJECTALTNAME2      = "san"$$
$$wszPROPDNS                  = "dns"$$
$$wszPROPDN                   = "dn"$$
$$wszPROPURL                  = "url"$$
$$wszPROPIPADDRESS            = "ipaddress"$$
$$wszPROPGUID                 = "guid"$$
$$wszPROPOID                  = "oid"$$
$$wszPROPUPN                  = "upn"$$
$$wszPROPUPN                  = "upn"$$

$szPROPASNTAG                = "{asn}"

$$wszPROPUTF8TAG             = "{utf8}"$$
$$wszPROPOCTETTAG            = "{octet}"$$
$$wszPROPHEXTAG              = "{hex}"$$
$$wszPROPASNTAG              = "{asn}"$$   ' $szPROPASNTAG
$$wszPROPTEXTTAG             = "{text}"$$

'//+--------------------------------------------------------------------------
'// "System" properties
'// ".#" means ".0", ".1", ".2" ... may be appended to the property name to
'// collect context specific values.  For some properties, the suffix selects
'// the CA certificate context.  For others, it selects the the CA CRL context.

$$wszPROPCATYPE                       = "CAType"$$
$$wszPROPSANITIZEDCANAME              = "SanitizedCAName"$$
$$wszPROPSANITIZEDSHORTNAME           = "SanitizedShortName"$$
$$wszPROPMACHINEDNSNAME               = "MachineDNSName"$$
$$wszPROPMODULEREGLOC                 = "ModuleRegistryLocation"$$
$$wszPROPUSEDS                        = "fUseDS"$$
$$wszPROPDELTACRLSDISABLED            = "fDeltaCRLsDisabled"$$
$$wszPROPSERVERUPGRADED               = "fServerUpgraded"$$
$$wszPROPCONFIGDN                     = "ConfigDN"$$
$$wszPROPDOMAINDN                     = "DomainDN"$$
$$wszPROPLOGLEVEL                     = "LogLevel"$$
$$wszPROPSESSIONCOUNT                 = "SessionCount"$$
$$wszPROPTEMPLATECHANGESEQUENCENUMBER = "TemplateChangeSequenceNumber"$$
$$wszPROPVOLATILEMODE                 = "VolatileMode"$$

'// ".#" suffix for ENUM_PERIOD_SECONDS, ... ENUM_PERIOD_YEARS
$$wszLOCALIZEDTIMEPERIODUNITS = "LocalizedTimePeriodUnits"$$

'// Request Context properties:

$$wszPROPREQUESTERCAACCESS = "RequesterCAAccess"$$
$$wszPROPUSERDN            = "UserDN"$$
$$wszPROPKEYARCHIVED       = "KeyArchived"$$

'// CA Certificate properties: (all ".#" extensible except wszPROPCERTCOUNT)

$$wszPROPCERTCOUNT                = "CertCount"$$
$$wszPROPRAWCACERTIFICATE         = "RawCACertificate"$$
$$wszPROPCERTSTATE                = "CertState"$$
$$wszPROPCERTSUFFIX               = "CertSuffix"$$

'// CA CRL properties: (all ".#" extensible)

$$wszPROPRAWCRL                   = "RawCRL"$$
$$wszPROPRAWDELTACRL              = "RawDeltaCRL"$$
$$wszPROPCRLINDEX                 = "CRLIndex"$$
$$wszPROPCRLSTATE                 = "CRLState"$$
$$wszPROPCRLSUFFIX                = "CRLSuffix"$$

'// Values for wszPROPCERTSTATE (see certadm.h):
'//   CA_DISP_REVOKED    // This Cert has been revoked.
'//   CA_DISP_VALID      // This Cert is still valid
'//   CA_DISP_INVALID    // This Cert has expired.
'//   CA_DISP_ERROR      // Cert unavailable (placehholder in registry?)

'// Values for wszPROPCRLSTATE (see certadm.h):
'//   CA_DISP_REVOKED   // All unexpired certs using this Cert's CRL have been
'//         // revoked.
'//   CA_DISP_VALID   // This Cert is still publishing CRLs as needed.
'//   CA_DISP_INVALID    // All certs using this Cert's CRL are expired.
'//   CA_DISP_ERROR      // This Cert's CRL is managed by another Cert.

'// "Settable" system properties:
$$wszPROPEVENTLOGTERSE      = "EventLogTerse"$$
$$wszPROPEVENTLOGERROR      = "EventLogError"$$
$$wszPROPEVENTLOGWARNING    = "EventLogWarning"$$
$$wszPROPEVENTLOGVERBOSE    = "EventLogVerbose"$$
$$wszPROPEVENTLOGEXHAUSTIVE = "EventLogExhaustive"$$
$$wszPROPDCNAME             = "DCName"$$
$$wszPROPCROSSFOREST        = "CrossForest"$$
$$wszPROPREQUESTERSAMNAME   = "RequesterSAMName"$$
$$wszPROPREQUESTERUPN       = "RequesterUPN"$$
$$wszPROPREQUESTERDN        = "RequesterDN"$$

'// "Settable" system properties (".#" extensible)
$$wszPROPSEAUDITID          = "SEAuditId"$$

'// "Fetchable" system properties
'#define wszPROPSEAUDITFILTER      TEXT("SEAuditFilter")
$$wszPROPSEAUDITFILTER      = "SEAuditFilter"$$

'//+--------------------------------------------------------------------------
'// Certificate properties:

$$wszPROPCERTIFICATEREQUESTID            = "RequestID"$$
$$wszPROPRAWCERTIFICATE                  = "RawCertificate"$$
$$wszPROPCERTIFICATEHASH                 = "CertificateHash"$$
$$wszPROPCERTIFICATETEMPLATE             = "CertificateTemplate"$$
$$wszPROPCERTIFICATEENROLLMENTFLAGS      = "EnrollmentFlags"$$
$$wszPROPCERTIFICATEGENERALFLAGS         = "GeneralFlags"$$
$$wszPROPCERTIFICATESERIALNUMBER         = "SerialNumber"$$
$$wszPROPCERTIFICATENOTBEFOREDATE        = "NotBefore"$$
$$wszPROPCERTIFICATENOTAFTERDATE         = "NotAfter"$$
$$wszPROPCERTIFICATESUBJECTKEYIDENTIFIER = "SubjectKeyIdentifier"$$
$$wszPROPCERTIFICATERAWPUBLICKEY         = "RawPublicKey"$$
$$wszPROPCERTIFICATEPUBLICKEYLENGTH      = "PublicKeyLength"$$
$$wszPROPCERTIFICATEPUBLICKEYALGORITHM   = "PublicKeyAlgorithm"$$
$$wszPROPCERTIFICATERAWPUBLICKEYALGORITHMPARAMETERS = "RawPublicKeyAlgorithmParameters"$$
$$wszPROPCERTIFICATEUPN                  = "UPN"$$

'// Obsolete:
$$wszPROPCERTIFICATETYPE                 = "CertificateType"$$
$$wszPROPCERTIFICATERAWSMIMECAPABILITIES = "RawSMIMECapabilities"$$
$$wszPROPNAMETYPE                        = "NameType"$$

'//+--------------------------------------------------------------------------
'// Certificate extension properties:

%EXTENSION_CRITICAL_FLAG       = &H00000001???
%EXTENSION_DISABLE_FLAG        = &H00000002???
%EXTENSION_DELETE_FLAG         = &H00000004???
%EXTENSION_POLICY_MASK         = &H0000ffff???   ' // Settable by admin+policy

%EXTENSION_ORIGIN_REQUEST      = &H00010000???
%EXTENSION_ORIGIN_POLICY       = &H00020000???
%EXTENSION_ORIGIN_ADMIN        = &H00030000???
%EXTENSION_ORIGIN_SERVER       = &H00040000???
%EXTENSION_ORIGIN_RENEWALCERT  = &H00050000???
%EXTENSION_ORIGIN_IMPORTEDCERT = &H00060000???
%EXTENSION_ORIGIN_PKCS7        = &H00070000???
%EXTENSION_ORIGIN_CMC          = &H00080000???
%EXTENSION_ORIGIN_CACERT       = &H00090000???
%EXTENSION_ORIGIN_MASK         = &H000f0000???

'//+--------------------------------------------------------------------------
'// Extension properties:

$$wszPROPEXTREQUESTID     = "ExtensionRequestId"$$
$$wszPROPEXTNAME          = "ExtensionName"$$
$$wszPROPEXTFLAGS         = "ExtensionFlags"$$
$$wszPROPEXTRAWVALUE      = "ExtensionRawValue"$$

'//+--------------------------------------------------------------------------
'// Attribute properties:

$$wszPROPATTRIBREQUESTID  = "AttributeRequestId"$$
$$wszPROPATTRIBNAME       = "AttributeName"$$
$$wszPROPATTRIBVALUE      = "AttributeValue"$$

'//+--------------------------------------------------------------------------
'// CRL properties:

$$wszPROPCRLROWID               = "CRLRowId"$$
$$wszPROPCRLNUMBER              = "CRLNumber"$$
$$wszPROPCRLMINBASE             = "CRLMinBase"$$   ' // Delta CRLs only
$$wszPROPCRLNAMEID              = "CRLNameId"$$
$$wszPROPCRLCOUNT               = "CRLCount"$$
$$wszPROPCRLTHISUPDATE          = "CRLThisUpdate"$$
$$wszPROPCRLNEXTUPDATE          = "CRLNextUpdate"$$
$$wszPROPCRLTHISPUBLISH         = "CRLThisPublish"$$
$$wszPROPCRLNEXTPUBLISH         = "CRLNextPublish"$$
$$wszPROPCRLEFFECTIVE           = "CRLEffective"$$
$$wszPROPCRLPROPAGATIONCOMPLETE = "CRLPropagationComplete"$$
$$wszPROPCRLLASTPUBLISHED       = "CRLLastPublished"$$
$$wszPROPCRLPUBLISHATTEMPTS     = "CRLPublishAttempts"$$
$$wszPROPCRLPUBLISHFLAGS        = "CRLPublishFlags"$$
$$wszPROPCRLPUBLISHSTATUSCODE   = "CRLPublishStatusCode"$$
$$wszPROPCRLPUBLISHERROR        = "CRLPublishError"$$
$$wszPROPCRLRAWCRL              = "CRLRawCRL"$$

'//+--------------------------------------------------------------------------
'// CRL Published Flags:

%CPF_BASE                      = &H00000001???
%CPF_DELTA                     = &H00000002???
%CPF_COMPLETE                  = &H00000004???
%CPF_SHADOW                    = &H00000008???
%CPF_CASTORE_ERROR             = &H00000010???
%CPF_BADURL_ERROR              = &H00000020???
%CPF_MANUAL                    = &H00000040???
%CPF_SIGNATURE_ERROR           = &H00000080???
%CPF_LDAP_ERROR                = &H00000100???
%CPF_FILE_ERROR                = &H00000200???
%CPF_FTP_ERROR                 = &H00000400???
%CPF_HTTP_ERROR                = &H00000800???
%CPF_POSTPONED_BASE_LDAP_ERROR = &H00001000???
%CPF_POSTPONED_BASE_FILE_ERROR = &H00002000???

'//+--------------------------------------------------------------------------
'// GetProperty/SetProperty Flags:
'//
'// Choose one Type

%PROPTYPE_LONG       = &H00000001???   ' // Signed long
%PROPTYPE_DATE       = &H00000002???   ' // Date+Time
%PROPTYPE_BINARY     = &H00000003???   ' // Binary data
%PROPTYPE_STRING     = &H00000004???   ' // Unicode String
%PROPTYPE_MASK       = &H000000ff???

'// Choose one Caller:

%PROPCALLER_SERVER    = &H00000100???
%PROPCALLER_POLICY    = &H00000200???
%PROPCALLER_EXIT      = &H00000300???
%PROPCALLER_ADMIN     = &H00000400???
%PROPCALLER_REQUEST   = &H00000500???
%PROPCALLER_MASK      = &H00000f00???
%PROPFLAGS_INDEXED    = &H00010000???

'// RequestFlags definitions:

%CR_FLG_FORCETELETEX            = &H00000001???
%CR_FLG_RENEWAL                 = &H00000002???
%CR_FLG_FORCEUTF8               = &H00000004???
%CR_FLG_CAXCHGCERT              = &H00000008???
%CR_FLG_ENROLLONBEHALFOF        = &H00000010???
%CR_FLG_SUBJECTUNMODIFIED       = &H00000020???
%CR_FLG_VALIDENCRYPTEDKEYHASH   = &H00000040???
%CR_FLG_CACROSSCERT             = &H00000080???
%CR_FLG_ENFORCEUTF8             = &H00000100???
%CR_FLG_DEFINEDCACERT           = &H00000200???
%CR_FLG_PUBLISHERROR            = &H80000000???


'// Disposition property values:

'// Disposition values for requests in the queue:
%DB_DISP_ACTIVE         = 8    ' // being processed
%DB_DISP_PENDING        = 9    ' // taken under submission
%DB_DISP_QUEUE_MAX      = 9    ' // max disposition value for queue view

%DB_DISP_FOREIGN        = 12   ' // archived foreign cert

%DB_DISP_CA_CERT        = 15   ' // CA cert
%DB_DISP_CA_CERT_CHAIN  = 16   ' // CA cert chain
%DB_DISP_KRA_CERT       = 17   ' // KRA cert

' // Disposition values for requests in the log:
%DB_DISP_LOG_MIN        = 20   ' // min disposition value for log view
%DB_DISP_ISSUED         = 20   ' // cert issued
%DB_DISP_REVOKED        = 21   ' // issued and revoked

' // Disposition values for failed requests in the log:
%DB_DISP_LOG_FAILED_MIN = 30   ' // min disposition value for log view
%DB_DISP_ERROR          = 30   ' // request failed
%DB_DISP_DENIED         = 31   ' // request denied


'// VerifyRequest() return values

%VR_PENDING             = 0    ' // request will be accepted or denied later
%VR_INSTANT_OK          = 1    ' // request was accepted
%VR_INSTANT_BAD         = 2    ' // request was rejected


'//+--------------------------------------------------------------------------
'// Known request Attribute names and Value strings

'// RequestType attribute name:
$$wszCERT_TYPE      = "RequestType"$$   ' // attribute name

'// RequestType attribute values:
'// Not specified:             // Non-specific certificate
$$wszCERT_TYPE_CLIENT    = "Client"$$        ' // Client authentication cert
$$wszCERT_TYPE_SERVER    = "Server"$$        ' // Server authentication cert
$$wszCERT_TYPE_CODESIGN  = "CodeSign"$$      ' // Code signing certificate
$$wszCERT_TYPE_CUSTOMER  = "SetCustomer"$$   ' // SET Customer certificate
$$wszCERT_TYPE_MERCHANT  = "SetMerchant"$$   ' // SET Merchant certificate
$$wszCERT_TYPE_PAYMENT   = "SetPayment"$$    ' // SET Payment certificate

'// Version attribute name:
$$wszCERT_VERSION        = "Version"$$   ' // attribute name

'// Version attribute values:
'// Not specified:             // Whetever is current
$$wszCERT_VERSION_1   = "1"$$     ' // Version one certificate
$$wszCERT_VERSION_2   = "2"$$     ' // Version two certificate
$$wszCERT_VERSION_3   = "3"$$     ' // Version three certificate
