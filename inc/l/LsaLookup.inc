' ########################################################################################
' Microsoft Windows
' File: LsaLookup.inc
' Contents: LSA Policy Lookup API
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%LSALOOKUP_INC = 1

'#ifdef _NTDEF_

'typedef UNICODE_STRING LSA_UNICODE_STRING, *PLSA_UNICODE_STRING;
'typedef STRING LSA_STRING, *PLSA_STRING;
'typedef OBJECT_ATTRIBUTES LSA_OBJECT_ATTRIBUTES, *PLSA_OBJECT_ATTRIBUTES;

'#else // _NTDEF_

'typedef struct _LSA_UNICODE_STRING {
'    USHORT Length;
'    USHORT MaximumLength;
'#ifdef MIDL_PASS
'    [size_is(MaximumLength/2), length_is(Length/2)]
'#endif // MIDL_PASS
'    PWSTR  Buffer;
'} LSA_UNICODE_STRING, *PLSA_UNICODE_STRING;

'typedef struct _LSA_STRING {
'    USHORT Length;
'    USHORT MaximumLength;
'    PCHAR Buffer;
'} LSA_STRING, *PLSA_STRING;

'typedef struct _LSA_OBJECT_ATTRIBUTES {
'    ULONG Length;
'    HANDLE RootDirectory;
'    PLSA_UNICODE_STRING ObjectName;
'    ULONG Attributes;
'    PVOID SecurityDescriptor;        // Points to type SECURITY_DESCRIPTOR
'    PVOID SecurityQualityOfService;  // Points to type SECURITY_QUALITY_OF_SERVICE
'} LSA_OBJECT_ATTRIBUTES, *PLSA_OBJECT_ATTRIBUTES;

'#endif // _NTDEF_

' // The following structures must be defined before including ntsecapi.inc

' // Size = 8 bytes
TYPE LSA_UNICODE_STRING WORD
   Length        AS WORD           ' USHORT Length
   MaximumLength AS WORD           ' USHORT MaximumLength
   Buffer        AS WSTRINGZ PTR   ' PWSTR  Buffer
END TYPE

' // Size = 8 bytes
TYPE LSA_STRING WORD
   Length        AS WORD         ' USHORT Length
   MaximumLength AS WORD         ' USHORT MaximumLength
   Buffer        AS ASCIIZ PTR   ' PUCHAR  Buffer
END TYPE

' // Size = 24 bytes
TYPE LSA_OBJECT_ATTRIBUTES DWORD
   Length                   AS DWORD                    ' ULONG Length
   RootDirectory            AS DWORD                    ' HANDLE RootDirectory
   ObjectName               AS LSA_UNICODE_STRING PTR   ' PLSA_UNICODE_STRING ObjectName
   Attributes               AS DWORD                    ' ULONG Attributes
   SecurityDescriptor       AS DWORD                    ' PVOID SecurityDescriptor // Points to type SECURITY_DESCRIPTOR
   SecurityQualityOfService AS DWORD                    ' PVOID SecurityQualityOfService // Points to type SECURITY_QUALITY_OF_SERVICE
END TYPE

#INCLUDE ONCE "ntsecapi.inc"

'//
'// The following data type is used to identify a domain
'//

' // Size = 12 bytes
TYPE LSA_TRUST_INFORMATION WORD
   Name AS LSA_UNICODE_STRING
#IF %DEF(%USEPBDECL)
   pSid  AS SID PTR   ' PSID
#ELSE
   Sid  AS SID PTR   ' PSID
#ENDIF
END TYPE

'// where members have the following usage:
'//
'//     Name - The name of the domain.
'//
'//     Sid - A pointer to the Sid of the Domain
'//

'//
'// The following data type is used in name and SID lookup services to
'// describe the domains referenced in the lookup operation.
'//

' // Size = 8 bytes
TYPE LSA_REFERENCED_DOMAIN_LIST DWORD
   Entries AS DWORD   ' ULONG
   Domains AS LSA_TRUST_INFORMATION PTR   ' PLSA_TRUST_INFORMATION
END TYPE

'// where members have the following usage:
'//
'//     Entries - Is a count of the number of domains described in the
'//         Domains array.
'//
'//     Domains - Is a pointer to an array of Entries LSA_TRUST_INFORMATION data
'//         structures.
'//

'//
'// The following data type is used in name to SID lookup services to describe
'// the domains referenced in the lookup operation.
'//

'#if (_WIN32_WINNT >= 0x0501)
' // Size = 16 bytes
TYPE LSA_TRANSLATED_SID2 DWORD
   Use         AS LONG      ' SID_NAME_USE
#IF %DEF(%USEPBDECL)
   pSid        AS SID PTR   ' PSID
#ELSE
   Sid         AS SID PTR   ' PSID
#ENDIF
   DomainIndex AS LONG      ' LONG
   Flags       AS DWORD     ' ULONG
END TYPE

'// where members have the following usage:
'//
'//     Use - identifies the use of the SID.  If this value is SidUnknown or
'//         SidInvalid, then the remainder of the record is not set and
'//         should be ignored.
'//
'//     Sid - Contains the complete Sid of the tranlated SID
'//
'//     DomainIndex - Is the index of an entry in a related
'//         LSA_REFERENCED_DOMAIN_LIST data structure describing the
'//         domain in which the account was found.
'//
'//         If there is no corresponding reference domain for an entry, then
'//         this field will contain a negative value.
'//
'#endif

'//
'// The following data type is used in SID to name lookup services to
'// describe the domains referenced in the lookup operation.
'//

' // Size = 16 bytes
TYPE LSA_TRANSLATED_NAME WORD
   Use         AS LONG   ' SID_NAME_USE
   Name        AS LSA_UNICODE_STRING
   DomainIndex AS LONG   ' LONG
END TYPE

'// where the members have the following usage:
'//
'//     Use - Identifies the use of the name.  If this value is SidUnknown
'//         or SidInvalid, then the remainder of the record is not set and
'//         should be ignored.  If this value is SidWellKnownGroup then the
'//         Name field is invalid, but the DomainIndex field is not.
'//
'//     Name - Contains the isolated name of the translated SID.
'//
'//     DomainIndex - Is the index of an entry in a related
'//         LSA_REFERENCED_DOMAIN_LIST data structure describing the domain
'//         in which the account was found.
'//
'//         If there is no corresponding reference domain for an entry, then
'//         this field will contain a negative value.
'//

'//
'// The following structure specifies the account domain info
'// (corresponds to the PolicyAccountDomainInformation information class).
'//

' // Size = 12 bytes
TYPE POLICY_ACCOUNT_DOMAIN_INFO WORD
   DomainName AS LSA_UNICODE_STRING
   DomainSid  AS SID PTR   ' PSID
END TYPE

'// where the members have the following usage:
'//
'//     DomainName - Is the name of the domain
'//
'//     DomainSid - Is the Sid of the domain
'//

'//
'// The following structure corresponds to the PolicyDnsDomainInformation
'// information class
'//

' // Size = 44 bytes
TYPE POLICY_DNS_DOMAIN_INFO WORD
   Name          AS LSA_UNICODE_STRING
   DnsDomainName AS LSA_UNICODE_STRING
   DnsForestName AS LSA_UNICODE_STRING
   DomainGuid    AS GUID
#IF %DEF(%USEPBDECL)
   pSid          AS SID PTR   ' PSID
#ELSE
   Sid           AS SID PTR   ' PSID
#ENDIF
END TYPE

'// where the members have the following usage:
'//
'//      Name - Is the name of the Domain
'//
'//      DnsDomainName - Is the DNS name of the domain
'//
'//      DnsForestName - Is the DNS forest name of the domain
'//
'//      DomainGuid - Is the GUID of the domain
'//
'//      Sid - Is the Sid of the domain


'//
'// Access types for the Lookup Policy object
'//
'// Choose values to correspond to the POLICY_* access types
'//

%LOOKUP_VIEW_LOCAL_INFORMATION       = &H00000001???
%LOOKUP_TRANSLATE_NAMES              = &H00000800???

'//
'// The following data type defines the classes of Lookup Policy
'// Domain Information that may be queried. The values are chosen
'// to match corresponding POLICY_INFORMATION_CLASS values.
'//

' enum LSA_LOOKUP_DOMAIN_INFO_CLASS
%AccountDomainInformation = 5
%DnsDomainInformation     = 12

'//
'// Lookup handle
'//

'typedef PVOID LSA_LOOKUP_HANDLE, *PLSA_LOOKUP_HANDLE;

DECLARE FUNCTION LsaLookupOpenLocalPolicy IMPORT "api-ms-win-security-lsalookup-l1-1-0.dll" ALIAS "LsaLookupOpenLocalPolicy" ( _
   BYREF ObjectAttributes AS LSA_OBJECT_ATTRIBUTES _    ' __in PLSA_OBJECT_ATTRIBUTES ObjectAttributes
 , BYVAL AccessMask AS ACCESS_MASK _                    ' __in ACCESS_MASK AccessMask
 , BYREF PolicyHandle AS DWORD _                        ' __inout PLSA_LOOKUP_HANDLE PolicyHandle
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION LsaLookupClose IMPORT "api-ms-win-security-lsalookup-l1-1-0.dll" ALIAS "LsaLookupClose" ( _
   BYVAL ObjectHandle AS DWORD _                        ' __in LSA_LOOKUP_HANDLE ObjectHandle
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION LsaLookupTranslateSids IMPORT "api-ms-win-security-lsalookup-l1-1-0.dll" ALIAS "LsaLookupTranslateSids" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_LOOKUP_HANDLE PolicyHandle
 , BYVAL Count AS DWORD _                               ' __in ULONG Count
 , BYVAL Sids AS SID PTR _                              ' __in PSID *Sids
 , BYREF ReferencedDomains AS LSA_REFERENCED_DOMAIN_LIST _ ' __out PLSA_REFERENCED_DOMAIN_LIST *ReferencedDomains
 , BYREF Names AS LSA_TRANSLATED_NAME _                 ' __out PLSA_TRANSLATED_NAME *Names
 ) AS LONG                                              ' NTSTATUS

'#if (_WIN32_WINNT >= 0x0501)
DECLARE FUNCTION LsaLookupTranslateNames IMPORT "api-ms-win-security-lsalookup-l1-1-0.dll" ALIAS "LsaLookupTranslateNames" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_LOOKUP_HANDLE PolicyHandle
 , BYVAL Flags AS DWORD _                               ' __in ULONG Flags
 , BYVAL Count AS DWORD _                               ' __in ULONG Count
 , BYREF Names AS LSA_UNICODE_STRING _                  ' __in PLSA_UNICODE_STRING Names
 , BYREF ReferencedDomains AS LSA_REFERENCED_DOMAIN_LIST _ ' __out PLSA_REFERENCED_DOMAIN_LIST *ReferencedDomains
 , BYREF Sids AS LSA_TRANSLATED_SID2 _                  ' __out PLSA_TRANSLATED_SID2 *Sids
 ) AS LONG                                              ' NTSTATUS
'#endif

DECLARE FUNCTION LsaLookupGetDomainInfo IMPORT "api-ms-win-security-lsalookup-l1-1-0.dll" ALIAS "LsaLookupGetDomainInfo" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_LOOKUP_HANDLE PolicyHandle
 , BYVAL DomainInfoClass AS LONG _                      ' __in LSA_LOOKUP_DOMAIN_INFO_CLASS DomainInfoClass
 , BYREF DomainInfo AS DWORD _                          ' __out PVOID *DomainInfo
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION LsaLookupFreeMemory IMPORT "api-ms-win-security-lsalookup-l1-1-0.dll" ALIAS "LsaLookupFreeMemory" ( _
   BYVAL bUFFER AS DWORD _                              ' __in PVOID Buffer
 ) AS LONG                                              ' NTSTATUS
