' ########################################################################################
' Microsoft Windows
' File: Iads.inc
' Library name: ActiveDs
' Version: 1.0
' Library GUID: {97D25DB0-0363-11CF-ABC4-02608C9E7553}
' Path: C:\WINDOWS\system32\activeds.tlb
' Contents: Active DS Type Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IADS_INC = 1

#INCLUDE ONCE "ole2.inc"

$LIBID_ActiveDs = GUID$("{97D25DB0-0363-11CF-ABC4-02608C9E7553}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {B75AC000-9BDD-11D0-852C-00C04FD8D503}
$PROGID_AccessControlEntry = "AccessControlEntry"
' CLSID = {B85EA052-9BDD-11D0-852C-00C04FD8D503}
$PROGID_AccessControlList = "AccessControlList"
' CLSID = {F270C64A-FFB8-4AE4-85FE-3A75E5347966}
$PROGID_ADsSecurityUtility = "ADsSecurityUtility"
' CLSID = {50B6327F-AFD1-11D2-9CB9-0000F87A369E}
$PROGID_ADSystemInfo = "ADSystemInfo"
' CLSID = {FCBF906F-4080-11D1-A3AC-00C04FB950DC}
$PROGID_BackLink = "BackLink"
' CLSID = {15F88A55-4680-11D1-A3B4-00C04FB950DC}
$PROGID_CaseIgnoreList = "CaseIgnoreList"
' CLSID = {7E99C0A3-F935-11D2-BA96-00C04FB6D0D1}
$PROGID_DNWithBinary = "DNWithBinary"
' CLSID = {334857CC-F934-11D2-BA96-00C04FB6D0D1}
$PROGID_DNWithString = "DNWithString"
' CLSID = {8F92A857-478E-11D1-A3B4-00C04FB950DC}
$PROGID_Email = "Email"
' CLSID = {A5062215-4681-11D1-A3B4-00C04FB950DC}
$PROGID_FaxNumber = "FaxNumber"
' CLSID = {B3AD3E13-4080-11D1-A3AC-00C04FB950DC}
$PROGID_Hold = "Hold"
' CLSID = {927971F5-0939-11D1-8BE1-00C04FD8D503}
$PROGID_LargeInteger = "LargeInteger"
' CLSID = {274FAE1F-3626-11D1-A3A4-00C04FB950DC}
$PROGID_NameTranslate = "NameTranslate"
' CLSID = {B0B71247-4080-11D1-A3AC-00C04FB950DC}
$PROGID_NetAddress = "NetAddress"
' CLSID = {1241400F-4680-11D1-A3B4-00C04FB950DC}
$PROGID_OctetList = "OctetList"
' CLSID = {B2538919-4080-11D1-A3AC-00C04FB950DC}
$PROGID_Path = "Path"
' CLSID = {080D0D78-F421-11D0-A36E-00C04FB950DC}
$PROGID_Pathname = "Pathname"
' CLSID = {0A75AFCD-4680-11D1-A3B4-00C04FB950DC}
$PROGID_PostalAddress = "PostalAddress"
' CLSID = {72D3EDC2-A4C4-11D0-8533-00C04FD8D503}
$PROGID_PropertyEntry = "PropertyEntry"
' CLSID = {7B9E38B0-A97C-11D0-8534-00C04FD8D503}
$PROGID_PropertyValue = "PropertyValue"
' CLSID = {F5D1BADF-4080-11D1-A3AC-00C04FB950DC}
$PROGID_ReplicaPointer = "ReplicaPointer"
' CLSID = {B958F73C-9BDD-11D0-852C-00C04FD8D503}
$PROGID_SecurityDescriptor = "SecurityDescriptor"
' CLSID = {B2BED2EB-4080-11D1-A3AC-00C04FB950DC}
$PROGID_TimeStamp = "TimeStamp"
' CLSID = {B33143CB-4080-11D1-A3AC-00C04FB950DC}
$PROGID_TypedName = "TypedName"
' CLSID = {66182EC4-AFD1-11D2-9CB9-0000F87A369E}
$PROGID_WinNTSystemInfo = "WinNTSystemInfo"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_AccessControlEntry = GUID$("{B75AC000-9BDD-11D0-852C-00C04FD8D503}")
$CLSID_AccessControlList = GUID$("{B85EA052-9BDD-11D0-852C-00C04FD8D503}")
$CLSID_ADsSecurityUtility = GUID$("{F270C64A-FFB8-4AE4-85FE-3A75E5347966}")
$CLSID_ADSystemInfo = GUID$("{50B6327F-AFD1-11D2-9CB9-0000F87A369E}")
$CLSID_BackLink = GUID$("{FCBF906F-4080-11D1-A3AC-00C04FB950DC}")
$CLSID_CaseIgnoreList = GUID$("{15F88A55-4680-11D1-A3B4-00C04FB950DC}")
$CLSID_DNWithBinary = GUID$("{7E99C0A3-F935-11D2-BA96-00C04FB6D0D1}")
$CLSID_DNWithString = GUID$("{334857CC-F934-11D2-BA96-00C04FB6D0D1}")
$CLSID_Email = GUID$("{8F92A857-478E-11D1-A3B4-00C04FB950DC}")
$CLSID_FaxNumber = GUID$("{A5062215-4681-11D1-A3B4-00C04FB950DC}")
$CLSID_Hold = GUID$("{B3AD3E13-4080-11D1-A3AC-00C04FB950DC}")
$CLSID_LargeInteger = GUID$("{927971F5-0939-11D1-8BE1-00C04FD8D503}")
$CLSID_NameTranslate = GUID$("{274FAE1F-3626-11D1-A3A4-00C04FB950DC}")
$CLSID_NetAddress = GUID$("{B0B71247-4080-11D1-A3AC-00C04FB950DC}")
$CLSID_OctetList = GUID$("{1241400F-4680-11D1-A3B4-00C04FB950DC}")
$CLSID_Path = GUID$("{B2538919-4080-11D1-A3AC-00C04FB950DC}")
$CLSID_Pathname = GUID$("{080D0D78-F421-11D0-A36E-00C04FB950DC}")
$CLSID_PostalAddress = GUID$("{0A75AFCD-4680-11D1-A3B4-00C04FB950DC}")
$CLSID_PropertyEntry = GUID$("{72D3EDC2-A4C4-11D0-8533-00C04FD8D503}")
$CLSID_PropertyValue = GUID$("{7B9E38B0-A97C-11D0-8534-00C04FD8D503}")
$CLSID_ReplicaPointer = GUID$("{F5D1BADF-4080-11D1-A3AC-00C04FB950DC}")
$CLSID_SecurityDescriptor = GUID$("{B958F73C-9BDD-11D0-852C-00C04FD8D503}")
$CLSID_Timestamp = GUID$("{B2BED2EB-4080-11D1-A3AC-00C04FB950DC}")
$CLSID_TypedName = GUID$("{B33143CB-4080-11D1-A3AC-00C04FB950DC}")
$CLSID_WinNTSystemInfo = GUID$("{66182EC4-AFD1-11D2-9CB9-0000F87A369E}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IADs = GUID$("{FD8256D0-FD15-11CE-ABC4-02608C9E7553}")
$IID_IADsAccessControlEntry = GUID$("{B4F3A14C-9BDD-11D0-852C-00C04FD8D503}")
$IID_IADsAccessControlList = GUID$("{B7EE91CC-9BDD-11D0-852C-00C04FD8D503}")
$IID_IADsAcl = GUID$("{8452D3AB-0869-11D1-A377-00C04FB950DC}")
$IID_IADsADSystemInfo = GUID$("{5BB11929-AFD1-11D2-9CB9-0000F87A369E}")
$IID_IADsAggregatee = GUID$("{1346CE8C-9039-11D0-8528-00C04FD8D503}")
$IID_IADsAggregator = GUID$("{52DB5FB0-941F-11D0-8529-00C04FD8D503}")
$IID_IADsBackLink = GUID$("{FD1302BD-4080-11D1-A3AC-00C04FB950DC}")
$IID_IADsCaseIgnoreList = GUID$("{7B66B533-4680-11D1-A3B4-00C04FB950DC}")
$IID_IADsClass = GUID$("{C8F93DD0-4AE0-11CF-9E73-00AA004A5691}")
$IID_IADsCollection = GUID$("{72B945E0-253B-11CF-A988-00AA006BC149}")
$IID_IADsComputer = GUID$("{EFE3CC70-1D9F-11CF-B1F3-02608C9E7553}")
$IID_IADsComputerOperations = GUID$("{EF497680-1D9F-11CF-B1F3-02608C9E7553}")
$IID_IADsContainer = GUID$("{001677D0-FD16-11CE-ABC4-02608C9E7553}")
$IID_IADsDeleteOps = GUID$("{B2BD0902-8878-11D1-8C21-00C04FD8D503}")
$IID_IADsDNWithBinary = GUID$("{7E99C0A2-F935-11D2-BA96-00C04FB6D0D1}")
$IID_IADsDNWithString = GUID$("{370DF02E-F934-11D2-BA96-00C04FB6D0D1}")
$IID_IADsDomain = GUID$("{00E4C220-FD16-11CE-ABC4-02608C9E7553}")
$IID_IADsEmail = GUID$("{97AF011A-478E-11D1-A3B4-00C04FB950DC}")
$IID_IADsExtension = GUID$("{3D35553C-D2B0-11D1-B17B-0000F87593A0}")
$IID_IADsFaxNumber = GUID$("{A910DEA9-4680-11D1-A3B4-00C04FB950DC}")
$IID_IADsFileService = GUID$("{A89D1900-31CA-11CF-A98A-00AA006BC149}")
$IID_IADsFileServiceOperations = GUID$("{A02DED10-31CA-11CF-A98A-00AA006BC149}")
$IID_IADsFileShare = GUID$("{EB6DCAF0-4B83-11CF-A995-00AA006BC149}")
$IID_IADsGroup = GUID$("{27636B00-410F-11CF-B1FF-02608C9E7553}")
$IID_IADsHold = GUID$("{B3EB3B37-4080-11D1-A3AC-00C04FB950DC}")
$IID_IADsLargeInteger = GUID$("{9068270B-0939-11D1-8BE1-00C04FD8D503}")
$IID_IADsLocality = GUID$("{A05E03A2-EFFE-11CF-8ABC-00C04FD8D503}")
$IID_IADsMembers = GUID$("{451A0030-72EC-11CF-B03B-00AA006E0975}")
$IID_IADsNamespaces = GUID$("{28B96BA0-B330-11CF-A9AD-00AA006BC149}")
$IID_IADsNameTranslate = GUID$("{B1B272A3-3625-11D1-A3A4-00C04FB950DC}")
$IID_IADsNetAddress = GUID$("{B21A50A9-4080-11D1-A3AC-00C04FB950DC}")
$IID_IADsO = GUID$("{A1CD2DC6-EFFE-11CF-8ABC-00C04FD8D503}")
$IID_IADsObjectOptions = GUID$("{46F14FDA-232B-11D1-A808-00C04FD8D5A8}")
$IID_IADsOctetList = GUID$("{7B28B80F-4680-11D1-A3B4-00C04FB950DC}")
$IID_IADsOpenDSObject = GUID$("{DDF2891E-0F9C-11D0-8AD4-00C04FD8D503}")
$IID_IADsOU = GUID$("{A2F733B8-EFFE-11CF-8ABC-00C04FD8D503}")
$IID_IADsPath = GUID$("{B287FCD5-4080-11D1-A3AC-00C04FB950DC}")
$IID_IADsPathname = GUID$("{D592AED4-F420-11D0-A36E-00C04FB950DC}")
$IID_IADsPostalAddress = GUID$("{7ADECF29-4680-11D1-A3B4-00C04FB950DC}")
$IID_IADsPrintJob = GUID$("{32FB6780-1ED0-11CF-A988-00AA006BC149}")
$IID_IADsPrintJobOperations = GUID$("{9A52DB30-1ECF-11CF-A988-00AA006BC149}")
$IID_IADsPrintQueue = GUID$("{B15160D0-1226-11CF-A985-00AA006BC149}")
$IID_IADsPrintQueueOperations = GUID$("{124BE5C0-156E-11CF-A986-00AA006BC149}")
$IID_IADsProperty = GUID$("{C8F93DD3-4AE0-11CF-9E73-00AA004A5691}")
$IID_IADsPropertyEntry = GUID$("{05792C8E-941F-11D0-8529-00C04FD8D503}")
$IID_IADsPropertyList = GUID$("{C6F602B6-8F69-11D0-8528-00C04FD8D503}")
$IID_IADsPropertyValue = GUID$("{79FA9AD0-A97C-11D0-8534-00C04FD8D503}")
$IID_IADsPropertyValue2 = GUID$("{306E831C-5BC7-11D1-A3B8-00C04FB950DC}")
$IID_IADsReplicaPointer = GUID$("{F60FB803-4080-11D1-A3AC-00C04FB950DC}")
$IID_IADsResource = GUID$("{34A05B20-4AAB-11CF-AE2C-00AA006EBFB9}")
$IID_IADsSecurityDescriptor = GUID$("{B8C787CA-9BDD-11D0-852C-00C04FD8D503}")
$IID_IADsSecurityUtility = GUID$("{A63251B2-5F21-474B-AB52-4A8EFAD10895}")
$IID_IADsService = GUID$("{68AF66E0-31CA-11CF-A98A-00AA006BC149}")
$IID_IADsServiceOperations = GUID$("{5D7B33F0-31CA-11CF-A98A-00AA006BC149}")
$IID_IADsSession = GUID$("{398B7DA0-4AAB-11CF-AE2C-00AA006EBFB9}")
$IID_IADsSyntax = GUID$("{C8F93DD2-4AE0-11CF-9E73-00AA004A5691}")
$IID_IADsTimestamp = GUID$("{B2F5A901-4080-11D1-A3AC-00C04FB950DC}")
$IID_IADsTypedName = GUID$("{B371A349-4080-11D1-A3AC-00C04FB950DC}")
$IID_IADsUser = GUID$("{3E37E320-17E2-11CF-ABC4-02608C9E7553}")
$IID_IADsWinNTSystemInfo = GUID$("{6C6D65DC-AFD1-11D2-9CB9-0000F87A369E}")
$IID_IDirectoryObject = GUID$("{E798DE2C-22E4-11D0-84FE-00C04FD8D503}")
$IID_IDirectorySchemaMgmt = GUID$("{75DB3B9C-A4D8-11D0-A79C-00C04FD8D5A8}")
$IID_IDirectorySearch = GUID$("{109BA8EC-92F0-11D0-A790-00C04FD8D5A8}")
$IID_IPrivateDispatch = GUID$("{86AB4BBE-65F6-11D1-8C13-00C04FD8D503}")
$IID_IPrivateUnknown = GUID$("{89126BAB-6EAD-11D1-8C18-00C04FD8D503}")
$IID_ITypeComp = GUID$("{00020403-0000-0000-C000-000000000046}")
$IID_ITypeInfo = GUID$("{00020401-0000-0000-C000-000000000046}")
$IID_ITypeLib = GUID$("{00020402-0000-0000-C000-000000000046}")

' ========================================================================================

'typedef ADSTYPEENUM ADSTYPE;
'typedef unsigned char BYTE;
'typedef unsigned char *LPBYTE;
'typedef unsigned char *PBYTE;
'typedef LPWSTR ADS_DN_STRING;
'typedef LPWSTR *PADS_DN_STRING;
'typedef LPWSTR ADS_CASE_EXACT_STRING;
'typedef LPWSTR *PADS_CASE_EXACT_STRING;
'typedef LPWSTR ADS_CASE_IGNORE_STRING;
'typedef LPWSTR *PADS_CASE_IGNORE_STRING;
'typedef LPWSTR ADS_PRINTABLE_STRING;
'typedef LPWSTR *PADS_PRINTABLE_STRING;
'typedef LPWSTR ADS_NUMERIC_STRING;
'typedef LPWSTR *PADS_NUMERIC_STRING;
'typedef DWORD ADS_BOOLEAN;
'typedef DWORD *LPNDS_BOOLEAN;
'typedef DWORD ADS_INTEGER;
'typedef DWORD *PADS_INTEGER;
'typedef SYSTEMTIME ADS_UTC_TIME;
'typedef SYSTEMTIME *PADS_UTC_TIME;
'typedef LARGE_INTEGER ADS_LARGE_INTEGER;
'typedef LARGE_INTEGER *PADS_LARGE_INTEGER;
'typedef LPWSTR ADS_OBJECT_CLASS;
'typedef LPWSTR *PADS_OBJECT_CLASS;
'typedef struct _adsvalue *PADSVALUE;
'typedef struct _adsvalue *LPADSVALUE;
'typedef ADS_STATUSENUM ADS_STATUS;
'typedef HANDLE ADS_SEARCH_HANDLE;

' ========================================================================================
' ADSTYPEENUM enum
' ========================================================================================

%ADSTYPE_INVALID                = 0
%ADSTYPE_DN_STRING              = %ADSTYPE_INVALID + 1
%ADSTYPE_CASE_EXACT_STRING      = %ADSTYPE_DN_STRING + 1
%ADSTYPE_CASE_IGNORE_STRING     = %ADSTYPE_CASE_EXACT_STRING + 1
%ADSTYPE_PRINTABLE_STRING       = %ADSTYPE_CASE_IGNORE_STRING + 1
%ADSTYPE_NUMERIC_STRING         = %ADSTYPE_PRINTABLE_STRING + 1
%ADSTYPE_BOOLEAN                = %ADSTYPE_NUMERIC_STRING + 1
%ADSTYPE_INTEGER                = %ADSTYPE_BOOLEAN + 1
%ADSTYPE_OCTET_STRING           = %ADSTYPE_INTEGER + 1
%ADSTYPE_UTC_TIME               = %ADSTYPE_OCTET_STRING + 1
%ADSTYPE_LARGE_INTEGER          = %ADSTYPE_UTC_TIME + 1
%ADSTYPE_PROV_SPECIFIC          = %ADSTYPE_LARGE_INTEGER + 1
%ADSTYPE_OBJECT_CLASS           = %ADSTYPE_PROV_SPECIFIC + 1
%ADSTYPE_CASEIGNORE_LIST        = %ADSTYPE_OBJECT_CLASS + 1
%ADSTYPE_OCTET_LIST             = %ADSTYPE_CASEIGNORE_LIST + 1
%ADSTYPE_PATH                   = %ADSTYPE_OCTET_LIST + 1
%ADSTYPE_POSTALADDRESS          = %ADSTYPE_PATH + 1
%ADSTYPE_TIMESTAMP              = %ADSTYPE_POSTALADDRESS + 1
%ADSTYPE_BACKLINK               = %ADSTYPE_TIMESTAMP + 1
%ADSTYPE_TYPEDNAME              = %ADSTYPE_BACKLINK + 1
%ADSTYPE_HOLD                   = %ADSTYPE_TYPEDNAME + 1
%ADSTYPE_NETADDRESS             = %ADSTYPE_HOLD + 1
%ADSTYPE_REPLICAPOINTER         = %ADSTYPE_NETADDRESS + 1
%ADSTYPE_FAXNUMBER              = %ADSTYPE_REPLICAPOINTER + 1
%ADSTYPE_EMAIL                  = %ADSTYPE_FAXNUMBER + 1
%ADSTYPE_NT_SECURITY_DESCRIPTOR = %ADSTYPE_EMAIL + 1
%ADSTYPE_UNKNOWN                = %ADSTYPE_NT_SECURITY_DESCRIPTOR + 1
%ADSTYPE_DN_WITH_BINARY         = %ADSTYPE_UNKNOWN + 1
%ADSTYPE_DN_WITH_STRING         = %ADSTYPE_DN_WITH_BINARY + 1

' ========================================================================================
' ADS_OCTET_STRING record
' ========================================================================================

' // Size = 8 bytes
TYPE ADS_OCTET_STRING DWORD
   dwLength AS DWORD                 ' DWORD
   lpValue  AS BYTE PTR              ' LPBYTE
END TYPE

' ========================================================================================
' ADS_NT_SECURITY_DESCRIPTOR record
' ========================================================================================

' // Size = 8 bytes
TYPE ADS_NT_SECURITY_DESCRIPTOR DWORD
   dwLength AS DWORD                 ' DWORD
   lpValue  AS BYTE PTR              ' LPBYTE
END TYPE

' ========================================================================================
' ADS_PROV_SPECIFIC record
' ========================================================================================

' // Size = 8 bytes
TYPE ADS_PROV_SPECIFIC DWORD
   dwLength AS DWORD                 ' DWORD
   lpValue  AS BYTE PTR              ' LPBYTE
END TYPE

' ========================================================================================
' _ADS_CASEIGNORE_LIST record
' ========================================================================================

' // Size = 8 bytes
TYPE ADS_CASEIGNORE_LIST DWORD
   Next   AS ADS_CASEIGNORE_LIST PTR   ' struct _ADS_CASEIGNORE_LIST *Next
   String AS WSTRINGZ PTR              ' LPWSTR String
END TYPE

' ========================================================================================
' _ADS_OCTET_LIST record
' ========================================================================================

' // Size = 12 bytes
TYPE ADS_OCTET_LIST DWORD
   Next   AS ADS_OCTET_LIST PTR   ' struct _ADS_OCTET_LIST *Next
   Length AS DWORD                ' DWORD Length
   Data   AS BYTE PTR             ' BYTE *Data
END TYPE

' ========================================================================================
' ADS_PATH record
' ========================================================================================

' // Size = 12 bytes
TYPE ADS_PATH DWORD
   Type       AS DWORD          ' DWORD
   VolumeName AS WSTRINGZ PTR   ' LPWSTR
   Path       AS WSTRINGZ PTR   ' LPWSTR
END TYPE

' ========================================================================================
' ADS_POSTALADDRESS record
' ========================================================================================

' // Size = 24 bytes
TYPE ADS_POSTALADDRESS DWORD
   PostalAddress(5) AS WSTRINGZ PTR   ' LPWSTR PostalAddress[ 6 ]
END TYPE

' ========================================================================================
' ADS_TIMESTAMP record
' ========================================================================================

' // Size = 8 bytes
TYPE ADS_TIMESTAMP DWORD
   WholeSeconds AS DWORD   ' DWORD
   EventID      AS DWORD   ' DWORD
END TYPE

' ========================================================================================
' ADS_BACKLINK record
' ========================================================================================

' // Size = 8 bytes
TYPE ADS_BACKLINK DWORD
   RemoteID   AS DWORD          ' DWORD
   ObjectName AS WSTRINGZ PTR   ' LPWSTR
END TYPE

' ========================================================================================
' ADS_TYPEDNAME record
' ========================================================================================

' // Size = 12 bytes
TYPE ADS_TYPEDNAME
   ObjectName AS WSTRINGZ PTR   ' LPWSTR
   Level      AS DWORD          ' DWORD
   Interval   AS DWORD          ' DWORD
END TYPE

' ========================================================================================
' ADS_HOLD record
' ========================================================================================

' // Size = 8 bytes
TYPE ADS_HOLD DWORD
   ObjectName AS WSTRINGZ PTR   ' LPWSTR
   Amount     AS DWORD          ' DWORD
END TYPE

' ========================================================================================
' ADS_NETADDRESS record
' ========================================================================================

' // Size = 12 bytes
TYPE ADS_NETADDRESS DWORD
   AddressType   AS DWORD      ' DWORD
   AddressLength AS DWORD      ' DWORD
   Address       AS BYTE PTR   ' BYTE*
END TYPE

' ========================================================================================
' ADS_REPLICAPOINTER record
' ========================================================================================

' // Size = 20 bytes
TYPE ADS_REPLICAPOINTER DWORD
   ServerName          AS WSTRINGZ PTR         ' LPWSTR
   ReplicaType         AS DWORD                ' DWORD
   ReplicaNumber       AS DWORD                ' DWORD
   Count               AS DWORD                ' DWORD
   ReplicaAddressHints AS ADS_NETADDRESS PTR   ' PADS_NETADDRESS ReplicaAddressHints
END TYPE

' ========================================================================================
' ADS_FAXNUMBER record
' ========================================================================================

' // Size = 12 bytes
TYPE ADS_FAXNUMBER DWORD
   TelephoneNumber AS DWORD          ' DWORD
   NumberOfBits    AS WSTRINGZ PTR   ' LPWSTR
   Parameters      AS BYTE PTR       ' BYTE*
END TYPE

' ========================================================================================
' ADS_EMAIL record
' ========================================================================================

' // Size = 8 bytes
TYPE ADS_EMAIL DWORD
   Address AS WSTRINGZ PTR   ' LPWSTR
   Type    AS DWORD          ' DWORD
END TYPE

' ========================================================================================
' ADS_DN_WITH_BINARY record
' ========================================================================================

' // Size = 12 bytes
TYPE ADS_DN_WITH_BINARY DWORD
   dwLength      AS DWORD          ' DWORD
   lpBinaryValue AS BYTE PTR       ' BYTE *
   pszDNString   AS WSTRINGZ PTR   ' LPWSTR
END TYPE

' ========================================================================================
' ADS_DN_WITH_STRING record
' ========================================================================================

' // Size = 8 bytes
TYPE ADS_DN_WITH_STRING DWORD
   pszStringValue AS WSTRINGZ PTR   ' LPWSTR
   pszDNString    AS WSTRINGZ PTR   ' LPWSTR
END TYPE

' ========================================================================================
' ADSVALUE record
' ========================================================================================

' // Size = 16 bytes
UNION ADSVALUE_UNION DWORD
   DNString           AS WSTRINGZ PTR                 ' LPWSTR // ADS_DN_STRING
   CaseExactString    AS WSTRINGZ PTR                 ' LPWSTR // ADS_CASE_EXACT_STRING
   CaseIgnoreString   AS WSTRINGZ PTR                 ' LPWSTR // ADS_CASE_IGNORE_STRING
   PrintableString    AS WSTRINGZ PTR                 ' LPWSTR // ADS_PRINTABLE_STRING
   NumericString      AS WSTRINGZ PTR                 ' LPWSTR // ADS_NUMERIC_STRING
   Boolean            AS DWORD                        ' DWORD  // ADS_BOOLEAN
   Integer            AS DWORD                        ' DWORD  // ADS_INTEGER
   OctetString        AS ADS_OCTET_STRING             ' ADS_OCTET_STRING
   UTCTime            AS SYSTEMTIME                   ' ADS_UTC_TIME
   LargeInteger       AS QUAD                         ' ADS_LARGE_INTEGER
   ClassName          AS WSTRINGZ PTR                 ' LPWSTR // ADS_OBJECT_CLASS
   ProviderSpecific   AS ADS_PROV_SPECIFIC            ' ADS_PROV_SPECIFIC
   pCaseIgnoreList    AS ADS_CASEIGNORE_LIST PTR      ' PADS_CASEIGNORE_LIST
   pOctetList         AS ADS_OCTET_LIST PTR           ' PADS_OCTET_LIST
   pPath              AS ADS_PATH PTR                 ' PADS_PATH
   pPostalAddress     AS ADS_POSTALADDRESS PTR        ' PADS_POSTALADDRESS
   Timestamp          AS ADS_TIMESTAMP                ' ADS_TIMESTAMP
   BackLink           AS ADS_BACKLINK                 ' ADS_BACKLINK
   pTypedName         AS ADS_TYPEDNAME PTR            ' PADS_TYPEDNAME
   Hold               AS ADS_HOLD                     ' ADS_HOLD
   pNetAddress        AS ADS_NETADDRESS PTR           ' PADS_NETADDRESS
   pReplicaPointer    AS ADS_REPLICAPOINTER PTR       ' PADS_REPLICAPOINTER
   pFaxNumber         AS ADS_FAXNUMBER PTR            ' PADS_FAXNUMBER
   Email              AS ADS_EMAIL                    ' ADS_EMAIL
   SecurityDescriptor AS ADS_NT_SECURITY_DESCRIPTOR   ' ADS_NT_SECURITY_DESCRIPTOR
   pDNWithBinary      AS ADS_DN_WITH_BINARY PTR       ' PADS_DN_WITH_BINARY
   pDNWithString      AS ADS_DN_WITH_STRING PTR       ' PADS_DN_WITH_STRING
END UNION

' // Size = 24 bytes
TYPE ADSVALUE QWORD   ' Must be 8 bytes aligned
   dwType AS LONG     ' ADSTYPE
   ADSVALUE_UNION
END TYPE


' ========================================================================================
' ADS_ATTR_INFO record
' ========================================================================================

' // Size = 20 bytes
TYPE ADS_ATTR_INFO DWORD
   pszAttrName   AS WSTRINGZ PTR   ' LPWSTR
   dwControlCode AS DWORD          ' DWORD
   dwADsType     AS LONG           ' ADSTYPE
   pADsValues    AS ADSVALUE PTR   ' PADSVALUE
   dwNumValues   AS DWORD          ' DWORD
END TYPE

' ========================================================================================
' ADS_AUTHENTICATION_ENUM enum
' ========================================================================================

%ADS_SECURE_AUTHENTICATION          = &H1???
%ADS_USE_ENCRYPTION                 = &H2???
%ADS_USE_SSL                        = &H2???
%ADS_READONLY_SERVER                = &H4???
%ADS_PROMPT_CREDENTIALS             = &H8???
%ADS_NO_AUTHENTICATION              = &H10???
%ADS_FAST_BIND                      = &H20???
%ADS_USE_SIGNING                    = &H40???
%ADS_USE_SEALING                    = &H80???
%ADS_USE_DELEGATION                 = &H100???
%ADS_SERVER_BIND                    = &H200???
%ADS_AUTH_RESERVED                  = &H80000000???

' ========================================================================================
' ADS_OBJECT_INFO record
' ========================================================================================

' // Size = 20 bytes
TYPE ADS_OBJECT_INFO DWORD
   pszRDN       AS WSTRINGZ PTR  ' LPWSTR
   pszObjectDN  AS WSTRINGZ PTR  ' LPWSTR
   pszParentDN  AS WSTRINGZ PTR  ' LPWSTR
   pszSchemaDN  AS WSTRINGZ PTR  ' LPWSTR
   pszClassName AS WSTRINGZ PTR  ' LPWSTR
END TYPE

' ========================================================================================
' ADS_STATUSENUM enum
' ========================================================================================

%ADS_STATUS_S_OK                    = 0
%ADS_STATUS_INVALID_SEARCHPREF      = %ADS_STATUS_S_OK + 1
%ADS_STATUS_INVALID_SEARCHPREFVALUE = %ADS_STATUS_INVALID_SEARCHPREF + 1

' ========================================================================================
' ADS_DEREFENUM enum
' ========================================================================================

%ADS_DEREF_NEVER                    = 0
%ADS_DEREF_SEARCHING                = 1
%ADS_DEREF_FINDING                  = 2
%ADS_DEREF_ALWAYS                   = 3

' ========================================================================================
' ADS_SCOPEENUM enum
' ========================================================================================

%ADS_SCOPE_BASE                     = 0
%ADS_SCOPE_ONELEVEL                 = 1
%ADS_SCOPE_SUBTREE                  = 2

' ========================================================================================
' ADS_PREFERENCES_ENUM enum
' ========================================================================================

%ADSIPROP_ASYNCHRONOUS              = &H0
%ADSIPROP_DEREF_ALIASES             = &H1
%ADSIPROP_SIZE_LIMIT                = &H2
%ADSIPROP_TIME_LIMIT                = &H3
%ADSIPROP_ATTRIBTYPES_ONLY          = &H4
%ADSIPROP_SEARCH_SCOPE              = &H5
%ADSIPROP_TIMEOUT                   = &H6
%ADSIPROP_PAGESIZE                  = &H7
%ADSIPROP_PAGED_TIME_LIMIT          = &H8
%ADSIPROP_CHASE_REFERRALS           = &H9
%ADSIPROP_SORT_ON                   = &HA
%ADSIPROP_CACHE_RESULTS             = &HB
%ADSIPROP_ADSIFLAG                  = &HC

' ========================================================================================
' ADSI_DIALECT_ENUM enum
' ========================================================================================

%ADSI_DIALECT_LDAP               = 0
%ADSI_DIALECT_SQL                = &H1

' ========================================================================================
' ADS_CHASE_REFERRALS_ENUM enum
' ========================================================================================

%ADS_CHASE_REFERRALS_NEVER       = 0
%ADS_CHASE_REFERRALS_SUBORDINATE = &H20
%ADS_CHASE_REFERRALS_EXTERNAL    = &H40
%ADS_CHASE_REFERRALS_ALWAYS      = %ADS_CHASE_REFERRALS_SUBORDINATE OR %ADS_CHASE_REFERRALS_EXTERNAL

' ========================================================================================
' ADS_SEARCHPREF_ENUM enum
' ========================================================================================

%ADS_SEARCHPREF_ASYNCHRONOUS     = 0
%ADS_SEARCHPREF_DEREF_ALIASES    = %ADS_SEARCHPREF_ASYNCHRONOUS + 1
%ADS_SEARCHPREF_SIZE_LIMIT       = %ADS_SEARCHPREF_DEREF_ALIASES + 1
%ADS_SEARCHPREF_TIME_LIMIT       = %ADS_SEARCHPREF_SIZE_LIMIT + 1
%ADS_SEARCHPREF_ATTRIBTYPES_ONLY = %ADS_SEARCHPREF_TIME_LIMIT + 1
%ADS_SEARCHPREF_SEARCH_SCOPE     = %ADS_SEARCHPREF_ATTRIBTYPES_ONLY + 1
%ADS_SEARCHPREF_TIMEOUT          = %ADS_SEARCHPREF_SEARCH_SCOPE + 1
%ADS_SEARCHPREF_PAGESIZE         = %ADS_SEARCHPREF_TIMEOUT + 1
%ADS_SEARCHPREF_PAGED_TIME_LIMIT = %ADS_SEARCHPREF_PAGESIZE + 1
%ADS_SEARCHPREF_CHASE_REFERRALS  = %ADS_SEARCHPREF_PAGED_TIME_LIMIT + 1
%ADS_SEARCHPREF_SORT_ON          = %ADS_SEARCHPREF_CHASE_REFERRALS + 1
%ADS_SEARCHPREF_CACHE_RESULTS    = %ADS_SEARCHPREF_SORT_ON + 1
%ADS_SEARCHPREF_DIRSYNC          = %ADS_SEARCHPREF_CACHE_RESULTS + 1
%ADS_SEARCHPREF_TOMBSTONE        = %ADS_SEARCHPREF_DIRSYNC + 1
%ADS_SEARCHPREF_VLV              = %ADS_SEARCHPREF_TOMBSTONE + 1
%ADS_SEARCHPREF_ATTRIBUTE_QUERY  = %ADS_SEARCHPREF_VLV + 1
%ADS_SEARCHPREF_SECURITY_MASK    = %ADS_SEARCHPREF_ATTRIBUTE_QUERY + 1
%ADS_SEARCHPREF_DIRSYNC_FLAG     = %ADS_SEARCHPREF_SECURITY_MASK + 1
%ADS_SEARCHPREF_EXTENDED_DN      = %ADS_SEARCHPREF_DIRSYNC_FLAG + 1

' ========================================================================================
' ADS_PASSWORD_ENCODING_ENUM enum
' ========================================================================================

%ADS_PASSWORD_ENCODE_REQUIRE_SSL = 0
%ADS_PASSWORD_ENCODE_CLEAR       = 1

' ========================================================================================
' ADS_SEARCHPREF_INFO record
' ========================================================================================

' // Size = 40 bytes
TYPE ADS_SEARCHPREF_INFO QWORD   ' Must be 8 bytes aligned
   dwSearchPref AS LONG       ' ADS_SEARCHPREF
   vValue       AS ADSVALUE   ' ADSVALUE
   dwStatus     AS LONG       ' ADS_STATUS
END TYPE

' ========================================================================================
' ADS_SEARCH_COLUMN record
' ========================================================================================

' // Size = 20 bytes
TYPE ADS_SEARCH_COLUMN DWORD
   pszAttrName AS WSTRINGZ PTR   ' LPWSTR
   dwADsType   AS LONG           ' ADSTYPE
   pADsValues  AS ADSVALUE PTR   ' PADSVALUE
   dwNumValues AS DWORD          ' DWORD
   hReserved   AS DWORD          ' HANDLE
END TYPE

' ========================================================================================
' ADS_ATTR_DEF record
' ========================================================================================

' // Size = 20 bytes
TYPE ADS_ATTR_DEF DWORD
   pszAttrName  AS WSTRINGZ PTR   ' LPWSTR
   dwADsType    AS LONG           ' ADSTYPE
   dwMinRange   AS DWORD          ' DWORD
   dwMaxRange   AS DWORD          ' DWORD
   fMultiValued AS LONG           ' BOOL
END TYPE

' ========================================================================================
' ADS_CLASS_DEF record
' ========================================================================================

' // Size = 40 bytes
TYPE ADS_CLASS_DEF DWORD
   pszClassName       AS WSTRINGZ PTR   ' LPWSTR
   dwMandatoryAttrs   AS DWORD          ' DWORD
   ppszMandatoryAttrs AS WSTRINGZ PTR   ' LPWSTR
   optionalAttrs      AS DWORD          ' DWORD
   ppszOptionalAttrs  AS WSTRINGZ PTR   ' LPWSTR
   dwNamingAttrs      AS DWORD          ' DWORD
   ppszNamingAttrs    AS WSTRINGZ PTR   ' LPWSTR
   dwSuperClasses     AS DWORD          ' DWORD
   ppszSuperClasses   AS WSTRINGZ PTR   ' LPWSTR
   fIsContainer       AS LONG           ' BOOL
END TYPE

' ========================================================================================
' ADS_SORTKEY record
' ========================================================================================

' // Size = 12 bytes
TYPE ADS_SORTKEY DWORD
   pszAttrType   AS WSTRINGZ PTR   ' LPWSTR
   pszReserved   AS WSTRINGZ PTR   ' LPWSTR
   fReverseorder AS BYTE           ' BOOLEAN
END TYPE

' ========================================================================================
' ADS_VLV record
' Number of members = 7
' ========================================================================================

' // Size = 28 bytes
TYPE ADS_VLV DWORD
   dwBeforeCount     AS DWORD          ' DWORD
   dwAfterCount      AS DWORD          ' DWORD
   dwOffset          AS DWORD          ' DWORD
   dwContentCount    AS DWORD          ' DWORD
   pszTarget         AS WSTRINGZ PTR   ' LPWSTR
   dwContextIDLength AS DWORD          ' DWORD
   lpContextID       AS BYTE PTR       ' LPBYTE
END TYPE

' ========================================================================================
' ADS_PROPERTY_OPERATION_ENUM enum
' ========================================================================================

%ADS_PROPERTY_CLEAR  = 1
%ADS_PROPERTY_UPDATE = 2
%ADS_PROPERTY_APPEND = 3
%ADS_PROPERTY_DELETE = 4

' ========================================================================================
' ADS_USER_FLAG_ENUM enum
' ========================================================================================

%ADS_UF_SCRIPT                                 = &H1
%ADS_UF_ACCOUNTDISABLE                         = &H2
%ADS_UF_HOMEDIR_REQUIRED                       = &H8
%ADS_UF_LOCKOUT                                = &H10
%ADS_UF_PASSWD_NOTREQD                         = &H20
%ADS_UF_PASSWD_CANT_CHANGE                     = &H40
%ADS_UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED        = &H80
%ADS_UF_TEMP_DUPLICATE_ACCOUNT                 = &H100
%ADS_UF_NORMAL_ACCOUNT                         = &H200
%ADS_UF_INTERDOMAIN_TRUST_ACCOUNT              = &H800
%ADS_UF_WORKSTATION_TRUST_ACCOUNT              = &H1000
%ADS_UF_SERVER_TRUST_ACCOUNT                   = &H2000
%ADS_UF_DONT_EXPIRE_PASSWD                     = &H10000
%ADS_UF_MNS_LOGON_ACCOUNT                      = &H20000
%ADS_UF_SMARTCARD_REQUIRED                     = &H40000
%ADS_UF_TRUSTED_FOR_DELEGATION                 = &H80000
%ADS_UF_NOT_DELEGATED                          = &H100000
%ADS_UF_USE_DES_KEY_ONLY                       = &H200000
%ADS_UF_DONT_REQUIRE_PREAUTH                   = &H400000
%ADS_UF_PASSWORD_EXPIRED                       = &H800000
%ADS_UF_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION = &H1000000

' ========================================================================================

%ADS_ATTR_CLEAR  = 1
%ADS_ATTR_UPDATE = 2
%ADS_ATTR_APPEND = 3
%ADS_ATTR_DELETE = 4

'#define   ADS_DIRSYNC_COOKIE   ( L"fc8cb04d-311d-406c-8cb9-1ae8b843b418" )
'#define   ADS_VLV_RESPONSE   ( L"fc8cb04d-311d-406c-8cb9-1ae8b843b419" )
$ADS_DIRSYNC_COOKIE = "FC8CB04D-311D-406C-8CB9-1AE8B843B418"
$$ADS_VLV_RESPONSE   = "FC8CB04D-311D-406C-8CB9-1AE8B843B419"$$

%ADS_EXT_MINEXTDISPID        = 1
%ADS_EXT_MAXEXTDISPID        = 16777215
%ADS_EXT_INITCREDENTIALS     = 1
%ADS_EXT_INITIALIZE_COMPLETE = 2


' ########################################################################################
' Interface name = IADs
' IID = {FD8256D0-FD15-11CE-ABC4-02608C9E7553}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADs_INTERFACE_DEFINED)
    %IADs_INTERFACE_DEFINED = 1

INTERFACE IADs $IID_IADs

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADs_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsContainer
' IID = {001677D0-FD16-11CE-ABC4-02608C9E7553}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsContainer_INTERFACE_DEFINED)
    %IADsContainer_INTERFACE_DEFINED = 1

INTERFACE IADsContainer $IID_IADsContainer

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <2> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   PROPERTY GET Filter <3> ( _                          ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT *pVar
   ' =====================================================================================
   PROPERTY SET Filter <3> ( _                          ' VTable offset = 40
     BYVAL Var AS VARIANT _                             ' __in VARIANT Var
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Hints <4> ( _                           ' VTable offset = 44
   ) AS VARIANT                                         ' __retval_out VARIANT *pvFilter
   ' =====================================================================================
   PROPERTY SET Hints <4> ( _                           ' VTable offset = 48
     BYVAL vHints AS VARIANT _                          ' __in VARIANT vHints
   )                                                    ' void
   ' =====================================================================================
   METHOD GetObject <5> ( _                             ' VTable offset = 52
     BYVAL ClassName AS WSTRING _                       ' __in BSTR ClassName
   , BYVAL RelativeName AS WSTRING _                    ' __in BSTR RelativeName
   ) AS IDispatch                                       ' __retval_out IDispatch **ppObject
   ' =====================================================================================
   METHOD Create <6> ( _                                ' VTable offset = 56
     BYVAL ClassName AS WSTRING _                       ' __in BSTR ClassName
   , BYVAL RelativeName AS WSTRING _                    ' __in BSTR RelativeName
   ) AS IDispatch                                       ' __retval_out IDispatch **ppObject
   ' =====================================================================================
   METHOD Delete <7> ( _                                ' VTable offset = 60
     BYVAL bstrClassName AS WSTRING _                   ' __in BSTR bstrClassName
   , BYVAL bstrRelativeName AS WSTRING _                ' __in BSTR bstrRelativeName
   )                                                    ' void
   ' =====================================================================================
   METHOD CopyHere <8> ( _                              ' VTable offset = 64
     BYVAL SourceName AS WSTRING _                      ' __in BSTR SourceName
   , BYVAL NewName AS WSTRING _                         ' __in BSTR NewName
   ) AS IDispatch                                       ' __retval_out IDispatch **ppObject
   ' =====================================================================================
   METHOD MoveHere <9> ( _                              ' VTable offset = 68
     BYVAL SourceName AS WSTRING _                      ' __in BSTR SourceName
   , BYVAL NewName AS WSTRING _                         ' __in BSTR NewName
   ) AS IDispatch                                       ' __retval_out IDispatch **ppObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsContainer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsCollection
' IID = {72B945E0-253B-11CF-A988-00AA006BC149}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsCollection_INTERFACE_DEFINED)
    %IADsCollection_INTERFACE_DEFINED = 1

INTERFACE IADsCollection $IID_IADsCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        '  __retval_out IUnknown **ppEnumerator
   ' =====================================================================================
   METHOD Add <4> ( _                                   ' VTable offset = 32
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vItem AS VARIANT _                           ' __in VARIANT vItem
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <5> ( _                                ' VTable offset = 36
     BYVAL bstrItemToBeRemoved AS WSTRING _             ' __in BSTR bstrItemToBeRemoved
   )                                                    ' void
   ' =====================================================================================
   METHOD GetObject <6> ( _                             ' VTable offset = 40
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvItem
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsMembers
' IID = {451A0030-72EC-11CF-B03B-00AA006E0975}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsMembers_INTERFACE_DEFINED)
    %IADsMembers_INTERFACE_DEFINED = 1

INTERFACE IADsMembers $IID_IADsMembers

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <2> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnumerator
   ' =====================================================================================
   PROPERTY GET Filter <3> ( _                          ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT *pvFilter
   ' =====================================================================================
   PROPERTY SET Filter <3> ( _                          ' VTable offset = 40
     BYVAL pvFilter AS VARIANT _                        ' __in VARIANT pvFilter
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsMembers_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsPropertyList
' IID = {C6F602B6-8F69-11D0-8528-00C04FD8D503}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsPropertyList_INTERFACE_DEFINED)
    %IADsPropertyList_INTERFACE_DEFINED = 1

INTERFACE IADsPropertyList $IID_IADsPropertyList

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET PropertyCount <2> ( _                   ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   METHOD Next <3> ( _                                  ' VTable offset = 32
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD Skip <4> ( _                                  ' VTable offset = 36
     BYVAL cElements AS LONG _                          ' __in long cElements
   )                                                    ' void
   ' =====================================================================================
   METHOD Reset <5> ( _                                 ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 44
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD GetPropertyItem <6> ( _                       ' VTable offset = 48
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL lnADsType AS LONG _                          ' __in LONG lnADsType
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD PutPropertyItem <7> ( _                       ' VTable offset = 52
     BYVAL varData AS VARIANT _                         ' __in VARIANT varData
   )                                                    ' void
   ' =====================================================================================
   METHOD ResetPropertyItem <8> ( _                     ' VTable offset = 56
     BYVAL varEntry AS VARIANT _                        ' __in VARIANT varEntry
   )                                                    ' void
   ' =====================================================================================
   METHOD PurgePropertyList <9> ( _                     ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsPropertyList_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsPropertyEntry
' IID = {05792C8E-941F-11D0-8529-00C04FD8D503}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsPropertyEntry_INTERFACE_DEFINED)
    %IADsPropertyEntry_INTERFACE_DEFINED = 1

INTERFACE IADsPropertyEntry $IID_IADsPropertyEntry

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Clear <1> ( _                                 ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Name <2> ( _                            ' VTable offset = 36
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ADsType <3> ( _                         ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET ADsType <3> ( _                         ' VTable offset = 44
     BYVAL lnADsType AS LONG _                          ' __in long lnADsType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ControlCode <4> ( _                     ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET ControlCode <4> ( _                     ' VTable offset = 52
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Values <5> ( _                          ' VTable offset = 56
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET Values <5> ( _                          ' VTable offset = 60
     BYVAL vValues AS VARIANT _                         ' __in VARIANT vValues
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsPropertyEntry_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsPropertyValue
' IID = {79FA9AD0-A97C-11D0-8534-00C04FD8D503}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsPropertyValue_INTERFACE_DEFINED)
    %IADsPropertyValue_INTERFACE_DEFINED = 1

INTERFACE IADsPropertyValue $IID_IADsPropertyValue

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Clear <1> ( _                                 ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ADsType <2> ( _                         ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET ADsType <2> ( _                         ' VTable offset = 36
     BYVAL lnADsType AS LONG _                          ' __in long lnADsType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DNString <3> ( _                        ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET DNString <3> ( _                        ' VTable offset = 44
     BYVAL bstrDNString AS WSTRING _                    ' __in BSTR bstrDNString
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CaseExactString <4> ( _                 ' VTable offset = 48
   ) AS WSTRING                                         '  __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET CaseExactString <4> ( _                 ' VTable offset = 52
     BYVAL bstrCaseExactString AS WSTRING _             ' __in BSTR bstrCaseExactString
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CaseIgnoreString <5> ( _                ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET CaseIgnoreString <5> ( _                ' VTable offset = 60
     BYVAL bstrCaseIgnoreString AS WSTRING _            ' __in BSTR bstrCaseIgnoreString
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PrintableString <6> ( _                 ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET PrintableString <6> ( _                 ' VTable offset = 68
     BYVAL bstrPrintableString AS WSTRING _             ' __in BSTR bstrPrintableString
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NumericString <7> ( _                   ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET NumericString <7> ( _                   ' VTable offset = 76
     BYVAL bstrNumericString AS WSTRING _               ' __in BSTR bstrNumericString
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Boolean <8> ( _                         ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET Boolean <8> ( _                         ' VTable offset = 84
     BYVAL lnBoolean AS LONG _                          ' __in long lnBoolean
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Integer <9> ( _                         ' VTable offset = 88
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET Integer <9> ( _                         ' VTable offset = 92
     BYVAL lnInteger AS LONG _                          ' __in long lnInteger
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OctetString <10> ( _                    ' VTable offset = 96
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET OctetString <10> ( _                    ' VTable offset = 100
     BYVAL vOctetString AS VARIANT _                    ' __in VARIANT vOctetString
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SecurityDescriptor <11> ( _             ' VTable offset = 104
   ) AS IDispatch                                       ' __retval_out IDispatch **retval
   ' =====================================================================================
   PROPERTY SET SecurityDescriptor <11> ( _             ' VTable offset = 108
     BYVAL pSecurityDescriptor AS IDispatch _           ' __in IDispatch *pSecurityDescriptor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LargeInteger <12> ( _                   ' VTable offset = 112
   ) AS IDispatch                                       ' __retval_out IDispatch **retval
   ' =====================================================================================
   PROPERTY SET LargeInteger <12> ( _                   ' VTable offset = 116
     BYVAL pLargeInteger AS IDispatch _                 ' __in IDispatch *pLargeInteger
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UTCTime <13> ( _                        ' VTable offset = 120
   ) AS DOUBLE                                          ' __retval_out DATE *retval
   ' =====================================================================================
   PROPERTY SET UTCTime <13> ( _                        ' VTable offset = 124
     BYVAL daUTCTime AS DOUBLE _                        ' __in DATE daUTCTime
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsPropertyValue_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsPropertyValue2
' IID = {306E831C-5BC7-11D1-A3B8-00C04FB950DC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsPropertyValue2_INTERFACE_DEFINED)
    %IADsPropertyValue2_INTERFACE_DEFINED = 1

INTERFACE IADsPropertyValue2 $IID_IADsPropertyValue2

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetObjectProperty <1> ( _                     ' VTable offset = 28
     BYREF lnADsType AS LONG _                          ' __inout long *lnADsType
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutObjectProperty <2> ( _                     ' VTable offset = 32
     BYVAL lnADsType AS LONG _                          ' __in long lnADsType
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsPropertyValue2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPrivateDispatch
' IID = {86AB4BBE-65F6-11D1-8C13-00C04FD8D503}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPrivateDispatch_INTERFACE_DEFINED)
    %IPrivateDispatch_INTERFACE_DEFINED = 1

INTERFACE IPrivateDispatch $IID_IPrivateDispatch

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ADSIInitializeDispatchManager ( _             ' VTable offset = 12
     BYVAL dwExtensionId AS LONG _                      ' __in long dwExtensionId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ADSIGetTypeInfoCount ( _                      ' VTable offset = 16
     BYREF pctinfo AS DWORD _                           ' __out UINT *pctinfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ADSIGetTypeInfo ( _                           ' VTable offset = 20
     BYVAL itinfo AS DWORD _                            ' __in UINT itinfo
   , BYVAL lcid AS DWORD _                              ' __in LCID lcid
   , BYREF pptinfo AS ITypeInfo _                       ' __out ITypeInfo **pptinfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ADSIGetIDsOfNames ( _                         ' VTable offset = 24
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF rgszNames AS WSTRING _                       ' __in OLECHAR **rgszNames
   , BYVAL cNames AS DWORD _                            ' __in UINT cNames
   , BYVAL lcid AS DWORD _                              ' __in LCID lcid
   , BYREF rgdispid AS LONG _                           ' __out DISPID *rgdispid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ADSIInvoke ( _                                ' VTable offset = 28
     BYVAL dispidMember AS DWORD _                      ' __in DISPID dispidMember
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL lcid AS DWORD _                              ' __in LCID lcid
   , BYVAL wFlags AS WORD _                             ' __in WORD wFlags
   , BYREF pdispparams AS DISPPARAMS _                  ' __in DISPPARAMS *pdispparams
   , BYREF pvarResult AS VARIANT _                      ' __out VARIANT *pvarResult
   , BYREF pexcepinfo AS EXCEPINFO _                    ' __out EXCEPINFO *pexcepinfo
   , BYREF puArgErr AS DWORD _                          ' __out UINT *puArgErr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPrivateDispatch_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPrivateUnknown
' IID = {89126BAB-6EAD-11D1-8C18-00C04FD8D503}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPrivateUnknown_INTERFACE_DEFINED)
    %IPrivateUnknown_INTERFACE_DEFINED = 1

INTERFACE IPrivateUnknown $IID_IPrivateUnknown

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ADSIInitializeObject ( _                      ' VTable offset = 12
     BYVAL lpszUserName AS WSTRING _                    ' __in BSTR lpszUserName
   , BYVAL lpszPassword AS WSTRING _                    ' __in BSTR lpszPassword
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ADSIReleaseObject ( _                         ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPrivateUnknown_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsExtension
' IID = {3D35553C-D2B0-11D1-B17B-0000F87593A0}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IADsExtension_INTERFACE_DEFINED)
    %IADsExtension_INTERFACE_DEFINED = 1

INTERFACE IADsExtension $IID_IADsExtension

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Operate ( _                                   ' VTable offset = 12
     BYVAL dwCode AS DWORD _                            ' __in DWORD dwCode
   , BYVAL varData1 AS VARIANT _                        ' __in VARIANT varData1
   , BYVAL varData2 AS VARIANT _                        ' __in VARIANT varData2
   , BYVAL varData3 AS VARIANT _                        ' __in VARIANT varData3
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PrivateGetIDsOfNames ( _                      ' VTable offset = 16
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF rgszNames AS WSTRING _                       ' __in OLECHAR **rgszNames
   , BYVAL cNames AS DWORD _                            ' __in unsigned int cNames
   , BYVAL lcid AS DWORD _                              ' __in LCID lcid
   , BYREF rgDispid AS LONG _                           ' __out DISPID *rgDispid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PrivateInvoke ( _                             ' VTable offset = 20
     BYVAL dispidMember AS LONG _                       ' __in DISPID dispidMember
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL lcid AS DWORD _                              ' __in LCID lcid
   , BYVAL wFlags AS WORD _                             ' __in WORD wFlags
   , BYREF pdispparams AS DISPPARAMS _                  ' __in DISPPARAMS *pdispparams
   , BYREF pvarResult AS VARIANT _                      ' __out VARIANT *pvarResult
   , BYREF pexcepinfo AS EXCEPINFO _                    ' __out EXCEPINFO *pexcepinfo
   , BYREF puArgErr AS DWORD _                          ' __out unsigned int *puArgErr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsExtension_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsDeleteOps
' IID = {B2BD0902-8878-11D1-8C21-00C04FD8D503}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsDeleteOps_INTERFACE_DEFINED)
    %IADsDeleteOps_INTERFACE_DEFINED = 1

INTERFACE IADsDeleteOps $IID_IADsDeleteOps

   INHERIT IDispatch

   ' =====================================================================================
   METHOD DeleteObject <2> ( _                          ' VTable offset = 28
     BYVAL lnFlags AS LONG _                            ' __in long lnFlags
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsDeleteOps_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsNamespaces
' IID = {28B96BA0-B330-11CF-A9AD-00AA006BC149}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IADsNamespaces_INTERFACE_DEFINED)
    %IADsNamespaces_INTERFACE_DEFINED = 1

INTERFACE IADsNamespaces $IID_IADsNamespaces

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IADsNamespaces Methods
   ' =====================================================================================
   PROPERTY GET DefaultContainer <1> ( _                ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET DefaultContainer <1> ( _                ' VTable offset = 84
     BYVAL bstrDefaultContainer AS WSTRING _            ' __in BSTR bstrDefaultContainer
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsNamespaces_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsClass
' IID = {C8F93DD0-4AE0-11CF-9E73-00AA004A5691}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IADsClass_INTERFACE_DEFINED)
    %IADsClass_INTERFACE_DEFINED = 1

INTERFACE IADsClass $IID_IADsClass

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IADsClass Methods
   ' =====================================================================================
   PROPERTY GET PrimaryInterface <15> ( _               ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET CLSID <16> ( _                          ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET CLSID <16> ( _                          ' VTable offset = 88
     BYVAL bstrCLSID AS WSTRING _                       ' __in BSTR bstrCLSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OID <17> ( _                            ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET OID <17> ( _                            ' VTable offset = 96
     BYVAL bstrOID AS WSTRING _                         ' __in BSTR bstrOID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Abstract <18> ( _                       ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retval
   ' =====================================================================================
   PROPERTY SET Abstract <18> ( _                       ' VTable offset = 104
     BYVAL fAbstract AS INTEGER _                       ' __in VARIANT_BOOL fAbstract
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Auxiliary <26> ( _                      ' VTable offset = 108
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retval
   ' =====================================================================================
   PROPERTY SET Auxiliary <26> ( _                      ' VTable offset = 112
     BYVAL fAuxiliary AS INTEGER _                      ' __in VARIANT_BOOL fAuxiliary
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MandatoryProperties <19> ( _            ' VTable offset = 116
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET MandatoryProperties <19> ( _            ' VTable offset = 120
     BYVAL vMandatoryProperties AS VARIANT _            ' __in VARIANT vMandatoryProperties
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OptionalProperties <29> ( _             ' VTable offset = 124
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET OptionalProperties <29> ( _             ' VTable offset = 128
     BYVAL vOptionalProperties AS VARIANT _             ' __in VARIANT vOptionalProperties
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NamingProperties <30> ( _               ' VTable offset = 132
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET NamingProperties <30> ( _               ' VTable offset = 136
     BYVAL vNamingProperties AS VARIANT _               ' __in VARIANT vNamingProperties
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DerivedFrom <20> ( _                    ' VTable offset = 140
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET DerivedFrom <20> ( _                    ' VTable offset = 144
     BYVAL vDerivedFrom AS VARIANT _                    ' __in VARIANT vDerivedFrom
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AuxDerivedFrom <27> ( _                 ' VTable offset = 148
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET AuxDerivedFrom <27> ( _                 ' VTable offset = 152
     BYVAL vAuxDerivedFrom AS VARIANT _                 ' __in VARIANT vAuxDerivedFrom
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PossibleSuperiors <28> ( _              ' VTable offset = 156
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET PossibleSuperiors <28> ( _              ' VTable offset = 160
     BYVAL vPossibleSuperiors AS VARIANT _              ' __in VARIANT vPossibleSuperiors
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Containment <21> ( _                    ' VTable offset = 164
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET Containment <21> ( _                    ' VTable offset = 168
     BYVAL vContainment AS VARIANT _                    ' __in VARIANT vContainment
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Container <22> ( _                      ' VTable offset = 172
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retval
   ' =====================================================================================
   PROPERTY SET Container <22> ( _                      ' VTable offset = 176
     BYVAL fContainer AS INTEGER _                      ' __in VARIANT_BOOL fContainer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HelpFileName <23> ( _                   ' VTable offset = 180
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET HelpFileName <23> ( _                   ' VTable offset = 184
     BYVAL bstrHelpFileName AS WSTRING _                ' __in BSTR bstrHelpFileName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HelpFileContext <24> ( _                ' VTable offset = 188
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET HelpFileContext <24> ( _                ' VTable offset = 192
     BYVAL lnHelpFileContext AS LONG _                  ' __in long lnHelpFileContext
   )                                                    ' void
   ' =====================================================================================
   METHOD Qualifiers <25> ( _                           ' VTable offset = 196
   ) AS IADsCollection                                  ' __retval_out IADsCollection **ppQualifiers
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsClass_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsProperty
' IID = {C8F93DD3-4AE0-11CF-9E73-00AA004A5691}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IADsProperty_INTERFACE_DEFINED)
    %IADsProperty_INTERFACE_DEFINED = 1

INTERFACE IADsProperty $IID_IADsProperty

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IADsProperty Methods
   ' =====================================================================================
   PROPERTY GET OID <17> ( _                            ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET OID <17> ( _                            ' VTable offset = 84
     BYVAL bstrOID AS WSTRING _                         ' __in BSTR bstrOID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Syntax <18> ( _                         ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Syntax <18> ( _                         ' VTable offset = 92
     BYVAL bstrSyntax AS WSTRING _                      ' __in BSTR bstrSyntax
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxRange <19> ( _                       ' VTable offset = 96
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET MaxRange <19> ( _                       ' VTable offset = 100
     BYVAL lnMaxRange AS LONG _                         ' __in long lnMaxRange
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MinRange <20> ( _                       ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET MinRange <20> ( _                       ' VTable offset = 108
     BYVAL lnMinRange AS LONG _                         ' __in long lnMinRange
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MultiValued <21> ( _                    ' VTable offset = 112
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retval
   ' =====================================================================================
   PROPERTY SET MultiValued <21> ( _                    ' VTable offset = 116
     BYVAL fMultiValued AS INTEGER _                    ' __in VARIANT_BOOL fMultiValued
   )                                                    ' void
   ' =====================================================================================
   METHOD Qualifiers <22> ( _                           ' VTable offset = 120
   ) AS IADsCollection                                  ' __retval_out IADsCollection **ppQualifiers
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsProperty_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsSyntax
' IID = {C8F93DD2-4AE0-11CF-9E73-00AA004A5691}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IADsSyntax_INTERFACE_DEFINED)
    %IADsSyntax_INTERFACE_DEFINED = 1

INTERFACE IADsSyntax $IID_IADsSyntax

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IADsSyntax Methods
   ' =====================================================================================
   PROPERTY GET OleAutoDataType <15> ( _                ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET OleAutoDataType <15> ( _                ' VTable offset = 84
     BYVAL lnOleAutoDataType AS LONG _                  ' __in long lnOleAutoDataType
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsSyntax_INTERFACE_DEFINED__ */

' ========================================================================================
' ADS_SYSTEMFLAG_ENUM enum
' ========================================================================================

%ADS_SYSTEMFLAG_DISALLOW_DELETE           = &H80000000???
%ADS_SYSTEMFLAG_CONFIG_ALLOW_RENAME       = &H40000000???
%ADS_SYSTEMFLAG_CONFIG_ALLOW_MOVE         = &H20000000???
%ADS_SYSTEMFLAG_CONFIG_ALLOW_LIMITED_MOVE = &H10000000???
%ADS_SYSTEMFLAG_DOMAIN_DISALLOW_RENAME    = &H8000000???
%ADS_SYSTEMFLAG_DOMAIN_DISALLOW_MOVE      = &H4000000???
%ADS_SYSTEMFLAG_CR_NTDS_NC                = &H1???
%ADS_SYSTEMFLAG_CR_NTDS_DOMAIN            = &H2???
%ADS_SYSTEMFLAG_ATTR_NOT_REPLICATED       = &H1???
%ADS_SYSTEMFLAG_ATTR_IS_CONSTRUCTED       = &H4???


' ########################################################################################
' Interface name = IADsLocality
' IID = {A05E03A2-EFFE-11CF-8ABC-00C04FD8D503}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IADsLocality_INTERFACE_DEFINED)
    %IADsLocality_INTERFACE_DEFINED = 1

INTERFACE IADsLocality $IID_IADsLocality

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IADsLocality Methods
   ' =====================================================================================
   PROPERTY GET Description <15> ( _                    ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Description <15> ( _                    ' VTable offset = 84
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LocalityName <16> ( _                   ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET LocalityName <16> ( _                   ' VTable offset = 92
     BYVAL bstrLocalityName AS WSTRING _                ' __in BSTR bstrLocalityName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PostalAddress <17> ( _                  ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET PostalAddress <17> ( _                  ' VTable offset = 100
     BYVAL bstrPostalAddress AS WSTRING _               ' __in BSTR bstrPostalAddress
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SeeAlso <18> ( _                        ' VTable offset = 104
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET SeeAlso <18> ( _                        ' VTable offset = 108
     BYVAL vSeeAlso AS VARIANT _                        ' __in VARIANT vSeeAlso
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsLocality_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsO
' IID = {A1CD2DC6-EFFE-11CF-8ABC-00C04FD8D503}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IADsO_INTERFACE_DEFINED)
    %IADsO_INTERFACE_DEFINED = 1

INTERFACE IADsO $IID_IADsO

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IADsO Methods
   ' =====================================================================================
   PROPERTY GET Description <15> ( _                    ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Description <15> ( _                    ' VTable offset = 84
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LocalityName <16> ( _                   ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET LocalityName <16> ( _                   ' VTable offset = 92
     BYVAL bstrLocalityName AS WSTRING _                ' __in BSTR bstrLocalityName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PostalAddress <17> ( _                  ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET PostalAddress <17> ( _                  ' VTable offset = 100
     BYVAL bstrPostalAddress AS WSTRING _               ' __in BSTR bstrPostalAddress
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TelephoneNumber <18> ( _                ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET TelephoneNumber <18> ( _                ' VTable offset = 108
     BYVAL bstrTelephoneNumber AS WSTRING _             ' __in BSTR bstrTelephoneNumber
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FaxNumber <19> ( _                      ' VTable offset = 112
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET FaxNumber <19> ( _                      ' VTable offset = 116
     BYVAL bstrFaxNumber AS WSTRING _                   ' __in BSTR bstrFaxNumber
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SeeAlso <20> ( _                        ' VTable offset = 120
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET SeeAlso <20> ( _                        ' VTable offset = 124
     BYVAL vSeeAlso AS VARIANT _                        ' __in VARIANT vSeeAlso
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsO_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsOU
' IID = {A2F733B8-EFFE-11CF-8ABC-00C04FD8D503}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IADsOU_INTERFACE_DEFINED)
    %IADsOU_INTERFACE_DEFINED = 1

INTERFACE IADsOU $IID_IADsOU

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IADsOU Methods
   ' =====================================================================================
   PROPERTY GET Description <15> ( _                    ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Description <15> ( _                    ' VTable offset = 84
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LocalityName <16> ( _                   ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET LocalityName <16> ( _                   ' VTable offset = 92
     BYVAL bstrLocalityName AS WSTRING _                ' __in BSTR bstrLocalityName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PostalAddress <17> ( _                  ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET PostalAddress <17> ( _                  ' VTable offset = 100
     BYVAL bstrPostalAddress AS WSTRING _               ' __in BSTR bstrPostalAddress
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TelephoneNumber <18> ( _                ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET TelephoneNumber <18> ( _                ' VTable offset = 108
     BYVAL bstrTelephoneNumber AS WSTRING _             ' __in BSTR bstrTelephoneNumber
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FaxNumber <19> ( _                      ' VTable offset = 112
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET FaxNumber <19> ( _                      ' VTable offset = 116
     BYVAL bstrFaxNumber AS WSTRING _                   ' __in BSTR bstrFaxNumber
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SeeAlso <20> ( _                        ' VTable offset = 120
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET SeeAlso <20> ( _                        ' VTable offset = 124
     BYVAL vSeeAlso AS VARIANT _                        ' __in VARIANT vSeeAlso
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BusinessCategory <21> ( _               ' VTable offset = 128
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET BusinessCategory <21> ( _               ' VTable offset = 132
     BYVAL bstrBusinessCategory AS WSTRING _            ' __in BSTR bstrBusinessCategory
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsOU_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsDomain
' IID = {00E4C220-FD16-11CE-ABC4-02608C9E7553}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IADsDomain_INTERFACE_DEFINED)
    %IADsDomain_INTERFACE_DEFINED = 1

INTERFACE IADsDomain $IID_IADsDomain

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IADsDomain Methods
   ' =====================================================================================
   PROPERTY GET IsWorkgroup <15> ( _                    ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retval
   ' =====================================================================================
   PROPERTY GET MinPasswordLength <16> ( _              ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET MinPasswordLength <16> ( _              ' VTable offset = 88
     BYVAL lnMinPasswordLength AS LONG _                ' __in long lnMinPasswordLength
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MinPasswordAge <17> ( _                 ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET MinPasswordAge <17> ( _                 ' VTable offset = 96
     BYVAL lnMinPasswordAge AS LONG _                   ' __in long lnMinPasswordAge
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxPasswordAge <18> ( _                 ' VTable offset = 100
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET MaxPasswordAge <18> ( _                 ' VTable offset = 104
     BYVAL lnMaxPasswordAge AS LONG _                   ' __in long lnMaxPasswordAge
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxBadPasswordsAllowed <19> ( _         ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET MaxBadPasswordsAllowed <19> ( _         ' VTable offset = 112
     BYVAL lnMaxBadPasswordsAllowed AS LONG _           ' __in long lnMaxBadPasswordsAllowed
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PasswordHistoryLength <20> ( _          ' VTable offset = 116
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET PasswordHistoryLength <20> ( _          ' VTable offset = 120
     BYVAL lnPasswordHistoryLength AS LONG _            ' __in long lnPasswordHistoryLength
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PasswordAttributes <21> ( _             ' VTable offset = 124
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET PasswordAttributes <21> ( _             ' VTable offset = 128
     BYVAL lnPasswordAttributes AS LONG _               ' __in long lnPasswordAttributes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoUnlockInterval <22> ( _             ' VTable offset = 132
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET AutoUnlockInterval <22> ( _             ' VTable offset = 136
     BYVAL lnAutoUnlockInterval AS LONG _               ' __in long lnAutoUnlockInterval
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LockoutObservationInterval <23> ( _     ' VTable offset = 140
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET LockoutObservationInterval <23> ( _     ' VTable offset = 144
     BYVAL lnLockoutObservationInterval AS LONG _       ' __in long lnLockoutObservationInterval
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsDomain_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsComputer
' IID = {EFE3CC70-1D9F-11CF-B1F3-02608C9E7553}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IADsComputer_INTERFACE_DEFINED)
    %IADsComputer_INTERFACE_DEFINED = 1

INTERFACE IADsComputer $IID_IADsComputer

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IADsComputer Methods
   ' =====================================================================================
   PROPERTY GET ComputerID <16> ( _                     ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Site <18> ( _                           ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Description <19> ( _                    ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Description <19> ( _                    ' VTable offset = 92
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Location <20> ( _                       ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Location <20> ( _                       ' VTable offset = 100
     BYVAL bstrLocation AS WSTRING _                    ' __in BSTR bstrLocation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PrimaryUser <21> ( _                    ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET PrimaryUser <21> ( _                    ' VTable offset = 108
     BYVAL bstrPrimaryUser AS WSTRING _                 ' __in BSTR bstrPrimaryUser
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Owner <22> ( _                          ' VTable offset = 112
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Owner <22> ( _                          ' VTable offset = 116
     BYVAL bstrOwner AS WSTRING _                       ' __in BSTR bstrOwner
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Division <23> ( _                       ' VTable offset = 120
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Division <23> ( _                       ' VTable offset = 124
     BYVAL bstrDivision AS WSTRING _                    ' __in BSTR bstrDivision
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Department <24> ( _                     ' VTable offset = 128
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Department <24> ( _                     ' VTable offset = 132
     BYVAL bstrDepartment AS WSTRING _                  ' __in BSTR bstrDepartment
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Role <25> ( _                           ' VTable offset = 136
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Role <25> ( _                           ' VTable offset = 140
     BYVAL bstrRole AS WSTRING _                        ' __in BSTR bstrRole
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OperatingSystem <26> ( _                ' VTable offset = 144
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET OperatingSystem <26> ( _                ' VTable offset = 148
     BYVAL bstrOperatingSystem AS WSTRING _             ' __in BSTR bstrOperatingSystem
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OperatingSystemVersion <27> ( _         ' VTable offset = 152
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET OperatingSystemVersion <27> ( _         ' VTable offset = 156
     BYVAL bstrOperatingSystemVersion AS WSTRING _      ' __in BSTR bstrOperatingSystemVersion
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Model <28> ( _                          ' VTable offset = 160
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Model <28> ( _                          ' VTable offset = 164
     BYVAL bstrModel AS WSTRING _                       ' __in BSTR bstrModel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Processor <29> ( _                      ' VTable offset = 168
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Processor <29> ( _                      ' VTable offset = 172
     BYVAL bstrProcessor AS WSTRING _                   ' __in BSTR bstrProcessor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProcessorCount <30> ( _                 ' VTable offset = 176
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET ProcessorCount <30> ( _                 ' VTable offset = 180
     BYVAL bstrProcessorCount AS WSTRING _              ' __in BSTR bstrProcessorCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MemorySize <31> ( _                     ' VTable offset = 184
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET MemorySize <31> ( _                     ' VTable offset = 188
     BYVAL bstrMemorySize AS WSTRING _                  ' __in BSTR bstrMemorySize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StorageCapacity <32> ( _                ' VTable offset = 192
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET StorageCapacity <32> ( _                ' VTable offset = 196
     BYVAL bstrStorageCapacity AS WSTRING _             ' __in BSTR bstrStorageCapacity
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NetAddresses <17> ( _                   ' VTable offset = 200
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET NetAddresses <17> ( _                   ' VTable offset = 204
     BYVAL vNetAddresses AS VARIANT _                   ' __in VARIANT vNetAddresses
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsComputer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsComputerOperations
' IID = {EF497680-1D9F-11CF-B1F3-02608C9E7553}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IADsComputerOperations_INTERFACE_DEFINED)
    %IADsComputerOperations_INTERFACE_DEFINED = 1

INTERFACE IADsComputerOperations $IID_IADsComputerOperations

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IADsComputerOperations Methods
   ' =====================================================================================
   METHOD Status <33> ( _                               ' VTable offset = 80
   ) AS IDispatch                                       ' __retval_out IDispatch **ppObject
   ' =====================================================================================
   METHOD Shutdown <34> ( _                             ' VTable offset = 84
     BYVAL bReboot AS INTEGER _                         ' __in VARIANT_BOOL bReboot
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsComputerOperations_INTERFACE_DEFINED__ */

' ========================================================================================
' ADS_GROUP_TYPE_ENUM enum
' ========================================================================================

%ADS_GROUP_TYPE_GLOBAL_GROUP       = &H2???
%ADS_GROUP_TYPE_DOMAIN_LOCAL_GROUP = &H4???
%ADS_GROUP_TYPE_LOCAL_GROUP        = &H4???
%ADS_GROUP_TYPE_UNIVERSAL_GROUP    = &H8???
%ADS_GROUP_TYPE_SECURITY_ENABLED   = &H80000000???

' ########################################################################################
' Interface name = IADsGroup
' IID = {27636B00-410F-11CF-B1FF-02608C9E7553}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IADsGroup_INTERFACE_DEFINED)
    %IADsGroup_INTERFACE_DEFINED = 1

INTERFACE IADsGroup $IID_IADsGroup

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IADsGroup Methods
   ' =====================================================================================
   PROPERTY GET Description <15> ( _                    ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Description <15> ( _                    ' VTable offset = 84
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   METHOD Members <16> ( _                              ' VTable offset = 88
   ) AS IADsMembers                                     ' __retval_out IADsMembers **ppMembers
   ' =====================================================================================
   METHOD IsMember <17> ( _                             ' VTable offset = 92
     BYVAL bstrMember AS WSTRING _                      ' __in BSTR bstrMember
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *bMember
   ' =====================================================================================
   METHOD Add <18> ( _                                  ' VTable offset = 96
     BYVAL bstrNewItem AS WSTRING _                     ' __in BSTR bstrNewItem
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <19> ( _                               ' VTable offset = 100
     BYVAL bstrItemToBeRemoved AS WSTRING _             ' __in BSTR bstrItemToBeRemoved
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsGroup_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsUser
' IID = {3E37E320-17E2-11CF-ABC4-02608C9E7553}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IADsUser_INTERFACE_DEFINED)
    %IADsUser_INTERFACE_DEFINED = 1

INTERFACE IADsUser $IID_IADsUser

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IADsUser Methods
   ' =====================================================================================
   PROPERTY GET BadLoginAddress <53> ( _                ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET BadLoginCount <54> ( _                  ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY GET LastLogin <56> ( _                      ' VTable offset = 88
   ) AS DOUBLE                                          ' __retval_out DATE *retval
   ' =====================================================================================
   PROPERTY GET LastLogoff <57> ( _                     ' VTable offset = 92
   ) AS DOUBLE                                          ' __retval_out DATE *retval
   ' =====================================================================================
   PROPERTY GET LastFailedLogin <58> ( _                ' VTable offset = 96
   ) AS DOUBLE                                          ' __retval_out DATE *retval
   ' =====================================================================================
   PROPERTY GET PasswordLastChanged <59> ( _            ' VTable offset = 100
   ) AS DOUBLE                                          ' __retval_out DATE *retval
   ' =====================================================================================
   PROPERTY GET Description <15> ( _                    ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Description <15> ( _                    ' VTable offset = 108
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Division <19> ( _                       ' VTable offset = 112
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Division <19> ( _                       ' VTable offset = 116
     BYVAL bstrDivision AS WSTRING _                    ' __in BSTR bstrDivision
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Department <122> ( _                    ' VTable offset = 120
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Department <122> ( _                    ' VTable offset = 124
     BYVAL bstrDepartment AS WSTRING _                  ' __in BSTR bstrDepartment
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EmployeeID <20> ( _                     ' VTable offset = 128
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET EmployeeID <20> ( _                     ' VTable offset = 132
     BYVAL bstrEmployeeID AS WSTRING _                  ' __in BSTR bstrEmployeeID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FullName <23> ( _                       ' VTable offset = 136
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET FullName <23> ( _                       ' VTable offset = 140
     BYVAL bstrFullName AS WSTRING _                    ' __in BSTR bstrFullName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FirstName <22> ( _                      ' VTable offset = 144
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET FirstName <22> ( _                      ' VTable offset = 148
     BYVAL bstrFirstName AS WSTRING _                   ' __in BSTR bstrFirstName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LastName <25> ( _                       ' VTable offset = 152
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET LastName <25> ( _                       ' VTable offset = 156
     BYVAL bstrLastName AS WSTRING _                    ' __in BSTR bstrLastName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OtherName <27> ( _                      ' VTable offset = 160
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET OtherName <27> ( _                      ' VTable offset = 164
     BYVAL bstrOtherName AS WSTRING _                   ' __in BSTR bstrOtherName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NamePrefix <114> ( _                    ' VTable offset = 168
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET NamePrefix <114> ( _                    ' VTable offset = 172
     BYVAL bstrNamePrefix AS WSTRING _                  ' __in BSTR bstrNamePrefix
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NameSuffix <115> ( _                    ' VTable offset = 176
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET NameSuffix <115> ( _                    ' VTable offset = 180
     BYVAL bstrNameSuffix AS WSTRING _                  ' __in BSTR bstrNameSuffix
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Title <36> ( _                          ' VTable offset = 184
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Title <36> ( _                          ' VTable offset = 188
     BYVAL bstrTitle AS WSTRING _                       ' __in BSTR bstrTitle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Manager <26> ( _                        ' VTable offset = 192
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Manager <26> ( _                        ' VTable offset = 196
     BYVAL bstrManager AS WSTRING _                     ' __in BSTR bstrManager
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TelephoneHome <32> ( _                  ' VTable offset = 200
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET TelephoneHome <32> ( _                  ' VTable offset = 204
     BYVAL vTelephoneHome AS VARIANT _                  ' __in VARIANT vTelephoneHome
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TelephoneMobile <33> ( _                ' VTable offset = 208
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET TelephoneMobile <33> ( _                ' VTable offset = 212
     BYVAL vTelephoneMobile AS VARIANT _                ' __in VARIANT vTelephoneMobile
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TelephoneNumber <34> ( _                ' VTable offset = 216
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET TelephoneNumber <34> ( _                ' VTable offset = 220
     BYVAL vTelephoneNumber AS VARIANT _                ' __in VARIANT vTelephoneNumber
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TelephonePager <17> ( _                 ' VTable offset = 224
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET TelephonePager <17> ( _                 ' VTable offset = 228
     BYVAL vTelephonePager AS VARIANT _                 ' __in VARIANT vTelephonePager
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FaxNumber <16> ( _                      ' VTable offset = 232
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET FaxNumber <16> ( _                      ' VTable offset = 236
     BYVAL vFaxNumber AS VARIANT _                      ' __in VARIANT vFaxNumber
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OfficeLocations <28> ( _                ' VTable offset = 240
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET OfficeLocations <28> ( _                ' VTable offset = 244
     BYVAL vOfficeLocations AS VARIANT _                ' __in VARIANT vOfficeLocations
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PostalAddresses <30> ( _                ' VTable offset = 248
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET PostalAddresses <30> ( _                ' VTable offset = 252
     BYVAL vPostalAddresses AS VARIANT _                ' __in VARIANT vPostalAddresses
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PostalCodes <31> ( _                    ' VTable offset = 256
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET PostalCodes <31> ( _                    ' VTable offset = 260
     BYVAL vPostalCodes AS VARIANT _                    ' __in VARIANT vPostalCodes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SeeAlso <117> ( _                       ' VTable offset = 264
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET SeeAlso <117> ( _                       ' VTable offset = 268
     BYVAL vSeeAlso AS VARIANT _                        ' __in VARIANT vSeeAlso
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AccountDisabled <37> ( _                ' VTable offset = 272
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retval
   ' =====================================================================================
   PROPERTY SET AccountDisabled <37> ( _                ' VTable offset = 276
     BYVAL fAccountDisabled AS INTEGER _                ' __in VARIANT_BOOL fAccountDisabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AccountExpirationDate <38> ( _          ' VTable offset = 280
   ) AS DOUBLE                                          ' __retval_out DATE *retval
   ' =====================================================================================
   PROPERTY SET AccountExpirationDate <38> ( _          ' VTable offset = 284
     BYVAL daAccountExpirationDate AS DOUBLE _          ' __in DATE daAccountExpirationDate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GraceLoginsAllowed <41> ( _             ' VTable offset = 288
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET GraceLoginsAllowed <41> ( _             ' VTable offset = 292
     BYVAL lnGraceLoginsAllowed AS LONG _               ' __in long lnGraceLoginsAllowed
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GraceLoginsRemaining <42> ( _           ' VTable offset = 296
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET GraceLoginsRemaining <42> ( _           ' VTable offset = 300
     BYVAL lnGraceLoginsRemaining AS LONG _             ' __in long lnGraceLoginsRemaining
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsAccountLocked <43> ( _                ' VTable offset = 304
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retval
   ' =====================================================================================
   PROPERTY SET IsAccountLocked <43> ( _                ' VTable offset = 308
     BYVAL fIsAccountLocked AS INTEGER _                ' __in VARIANT_BOOL fIsAccountLocked
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LoginHours <45> ( _                     ' VTable offset = 312
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET LoginHours <45> ( _                     ' VTable offset = 316
     BYVAL vLoginHours AS VARIANT _                     ' __in VARIANT vLoginHours
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LoginWorkstations <46> ( _              ' VTable offset = 320
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET LoginWorkstations <46> ( _              ' VTable offset = 324
     BYVAL vLoginWorkstations AS VARIANT _              ' __in VARIANT vLoginWorkstations
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxLogins <47> ( _                      ' VTable offset = 328
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET MaxLogins <47> ( _                      ' VTable offset = 332
     BYVAL lnMaxLogins AS LONG _                        ' __in long lnMaxLogins
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxStorage <48> ( _                     ' VTable offset = 336
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET MaxStorage <48> ( _                     ' VTable offset = 340
     BYVAL lnMaxStorage AS LONG _                       ' __in long lnMaxStorage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PasswordExpirationDate <49> ( _         ' VTable offset = 344
   ) AS DOUBLE                                          ' __retval_out DATE *retval
   ' =====================================================================================
   PROPERTY SET PasswordExpirationDate <49> ( _         ' VTable offset = 348
     BYVAL daPasswordExpirationDate AS DOUBLE _         ' __in DATE daPasswordExpirationDate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PasswordMinimumLength <50> ( _          ' VTable offset = 352
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET PasswordMinimumLength <50> ( _          ' VTable offset = 356
     BYVAL lnPasswordMinimumLength AS LONG _            ' __in long lnPasswordMinimumLength
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PasswordRequired <51> ( _               ' VTable offset = 360
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retval
   ' =====================================================================================
   PROPERTY SET PasswordRequired <51> ( _               ' VTable offset = 364
     BYVAL fPasswordRequired AS INTEGER _               ' __in VARIANT_BOOL fPasswordRequired
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RequireUniquePassword <52> ( _          ' VTable offset = 368
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retval
   ' =====================================================================================
   PROPERTY SET RequireUniquePassword <52> ( _          ' VTable offset = 372
     BYVAL fRequireUniquePassword AS INTEGER _          ' __in VARIANT_BOOL fRequireUniquePassword
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EmailAddress <60> ( _                   ' VTable offset = 376
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET EmailAddress <60> ( _                   ' VTable offset = 380
     BYVAL bstrEmailAddress AS WSTRING _                ' __in BSTR bstrEmailAddress
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HomeDirectory <61> ( _                  ' VTable offset = 384
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET HomeDirectory <61> ( _                  ' VTable offset = 388
     BYVAL bstrHomeDirectory AS WSTRING _               ' __in BSTR bstrHomeDirectory
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Languages <62> ( _                      ' VTable offset = 392
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET Languages <62> ( _                      ' VTable offset = 396
     BYVAL vLanguages AS VARIANT _                      ' __in VARIANT vLanguages
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Profile <63> ( _                        ' VTable offset = 400
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Profile <63> ( _                        ' VTable offset = 404
     BYVAL bstrProfile AS WSTRING _                     ' __in BSTR bstrProfile
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LoginScript <64> ( _                    ' VTable offset = 408
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET LoginScript <64> ( _                    ' VTable offset = 412
     BYVAL bstrLoginScript AS WSTRING _                 ' __in BSTR bstrLoginScript
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Picture <65> ( _                        ' VTable offset = 416
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET Picture <65> ( _                        ' VTable offset = 420
     BYVAL vPicture AS VARIANT _                        ' __in VARIANT vPicture
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HomePage <120> ( _                      ' VTable offset = 424
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET HomePage <120> ( _                      ' VTable offset = 428
     BYVAL bstrHomePage AS WSTRING _                    ' __in BSTR bstrHomePage
   )                                                    ' void
   ' =====================================================================================
   METHOD Groups <66> ( _                               ' VTable offset = 432
   ) AS IADsMembers                                     ' __retval_out IADsMembers **ppGroups
   ' =====================================================================================
   METHOD SetPassword <67> ( _                          ' VTable offset = 436
     BYVAL NewPassword AS WSTRING _                     ' __in BSTR NewPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD ChangePassword <68> ( _                       ' VTable offset = 440
     BYVAL bstrOldPassword AS WSTRING _                 ' __in BSTR bstrOldPassword
   , BYVAL bstrNewPassword AS WSTRING _                 ' __in BSTR bstrNewPassword
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsUser_INTERFACE_DEFINED__ */

' ========================================================================================
' ADS_USER_FLAG enum
' ========================================================================================

%ADS_UF_SCRIPT                                 = &H1???
%ADS_UF_ACCOUNTDISABLE                         = &H2???
%ADS_UF_HOMEDIR_REQUIRED                       = &H8???
%ADS_UF_LOCKOUT                                = &H10???
%ADS_UF_PASSWD_NOTREQD                         = &H20???
%ADS_UF_PASSWD_CANT_CHANGE                     = &H40???
%ADS_UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED        = &H80???
%ADS_UF_TEMP_DUPLICATE_ACCOUNT                 = &H100???
%ADS_UF_NORMAL_ACCOUNT                         = &H200???
%ADS_UF_INTERDOMAIN_TRUST_ACCOUNT              = &H800???
%ADS_UF_WORKSTATION_TRUST_ACCOUNT              = &H1000???
%ADS_UF_SERVER_TRUST_ACCOUNT                   = &H2000???
%ADS_UF_DONT_EXPIRE_PASSWD                     = &H10000???
%ADS_UF_MNS_LOGON_ACCOUNT                      = &H20000???
%ADS_UF_SMARTCARD_REQUIRED                     = &H40000???
%ADS_UF_TRUSTED_FOR_DELEGATION                 = &H80000???
%ADS_UF_NOT_DELEGATED                          = &H100000???
%ADS_UF_USE_DES_KEY_ONLY                       = &H200000???
%ADS_UF_DONT_REQUIRE_PREAUTH                   = &H400000???
%ADS_UF_PASSWORD_EXPIRED                       = &H800000???
%ADS_UF_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION = &H1000000???

' ########################################################################################
' Interface name = IADsPrintQueue
' IID = {B15160D0-1226-11CF-A985-00AA006BC149}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IADsPrintQueue_INTERFACE_DEFINED)
    %IADsPrintQueue_INTERFACE_DEFINED = 1

INTERFACE IADsPrintQueue $IID_IADsPrintQueue

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IADsPrintQueue Methods
   ' =====================================================================================
   PROPERTY GET PrinterPath <15> ( _                    ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET PrinterPath <15> ( _                    ' VTable offset = 84
     BYVAL bstrPrinterPath AS WSTRING _                 ' __in BSTR bstrPrinterPath
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Model <16> ( _                          ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Model <16> ( _                          ' VTable offset = 92
     BYVAL bstrModel AS WSTRING _                       ' __in BSTR bstrModel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Datatype <17> ( _                       ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Datatype <17> ( _                       ' VTable offset = 100
     BYVAL bstrDatatype AS WSTRING _                    ' __in BSTR bstrDatatype
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PrintProcessor <18> ( _                 ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET PrintProcessor <18> ( _                 ' VTable offset = 108
     BYVAL bstrPrintProcessor AS WSTRING _              ' __in BSTR bstrPrintProcessor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <19> ( _                    ' VTable offset = 112
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Description <19> ( _                    ' VTable offset = 116
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Location <20> ( _                       ' VTable offset = 120
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Location <20> ( _                       ' VTable offset = 120
     BYVAL bstrLocation AS WSTRING _                    ' __in BSTR bstrLocation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartTime <21> ( _                      ' VTable offset = 128
   ) AS DOUBLE                                          ' __retval_out DATE *retval
   ' =====================================================================================
   PROPERTY SET StartTime <21> ( _                      ' VTable offset = 132
     BYVAL daStartTime AS DOUBLE _                      ' __in DATE daStartTime
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UntilTime <22> ( _                      ' VTable offset = 136
   ) AS DOUBLE                                          ' __retval_out DATE *retval
   ' =====================================================================================
   PROPERTY SET UntilTime <22> ( _                      ' VTable offset = 140
     BYVAL daUntilTime AS DOUBLE _                      ' __in DATE daUntilTime
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultJobPriority <23> ( _             ' VTable offset = 144
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET DefaultJobPriority <23> ( _             ' VTable offset = 148
     BYVAL LONG _                                       ' __in long lnDefaultJobPriority
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Priority <24> ( _                       ' VTable offset = 152
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET Priority <24> ( _                       ' VTable offset = 156
     BYVAL lnPriority AS LONG _                         ' __in long lnPriority
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BannerPage <25> ( _                     ' VTable offset = 160
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET BannerPage <25> ( _                     ' VTable offset = 164
     BYVAL bstrBannerPage AS WSTRING _                  ' __in BSTR bstrBannerPage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PrintDevices <26> ( _                   ' VTable offset = 168
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET PrintDevices <26> ( _                   ' VTable offset = 172
     BYVAL vPrintDevices AS VARIANT _                   ' __in VARIANT vPrintDevices
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NetAddresses <27> ( _                   ' VTable offset = 176
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET NetAddresses <27> ( _                   ' VTable offset = 180
     BYVAL vNetAddresses AS VARIANT _                   ' __in VARIANT vNetAddresses
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsPrintQueue_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsPrintQueueOperations
' IID = {124BE5C0-156E-11CF-A986-00AA006BC149}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IADsPrintQueueOperations_INTERFACE_DEFINED)
    %IADsPrintQueueOperations_INTERFACE_DEFINED = 1

INTERFACE IADsPrintQueueOperations $IID_IADsPrintQueueOperations

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IADsPrintQueueOperations Methods
   ' =====================================================================================
   PROPERTY GET Status <27> ( _                         ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   METHOD PrintJobs <28> ( _                            ' VTable offset = 84
   ) AS IADsCollection                                  ' __retval_out IADsCollection **pObject
   ' =====================================================================================
   METHOD Pause <29> ( _                                ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   METHOD Resume <30> ( _                               ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD Purge <31> ( _                                ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsPrintQueueOperations_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsPrintJob
' IID = {32FB6780-1ED0-11CF-A988-00AA006BC149}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IADsPrintJob_INTERFACE_DEFINED)
    %IADsPrintJob_INTERFACE_DEFINED = 1

INTERFACE IADsPrintJob $IID_IADsPrintJob

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IADsPrintJob Methods
   ' =====================================================================================
   PROPERTY GET HostPrintQueue <15> ( _                 ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET User <16> ( _                           ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET UserPath <17> ( _                       ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET TimeSubmitted <18> ( _                  ' VTable offset = 92
   ) AS DOUBLE                                          ' __retval_out DATE *retval
   ' =====================================================================================
   PROPERTY GET TotalPages <19> ( _                     ' VTable offset = 96
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY GET Size <234> ( _                          ' VTable offset = 100
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY GET Description <20> ( _                    ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Description <20> ( _                    ' VTable offset = 108
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Priority <21> ( _                       ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET Priority <21> ( _                       ' VTable offset = 116
     BYVAL lnPriority AS LONG _                         ' __in long lnPriority
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartTime <22> ( _                      ' VTable offset = 120
   ) AS DOUBLE                                          ' __retval_out DATE *retval
   ' =====================================================================================
   PROPERTY SET StartTime <22> ( _                      ' VTable offset = 124
     BYVAL daStartTime AS DOUBLE _                      ' __in DATE daStartTime
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UntilTime <23> ( _                      ' VTable offset = 128
   ) AS DOUBLE                                          ' __retval_out DATE *retval
   ' =====================================================================================
   PROPERTY SET UntilTime <23> ( _                      ' VTable offset = 132
     BYVAL daUntilTime AS DOUBLE _                      ' __in DATE daUntilTime
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Notify <24> ( _                         ' VTable offset = 136
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Notify <24> ( _                         ' VTable offset = 140
     BYVAL bstrNotify AS WSTRING _                      ' __in BSTR bstrNotify
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NotifyPath <25> ( _                     ' VTable offset = 144
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET NotifyPath <25> ( _                     ' VTable offset = 148
     BYVAL bstrNotifyPath AS WSTRING _                  ' __in BSTR bstrNotifyPath
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsPrintJob_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsPrintJobOperations
' IID = {9A52DB30-1ECF-11CF-A988-00AA006BC149}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IADsPrintJobOperations_INTERFACE_DEFINED)
    %IADsPrintJobOperations_INTERFACE_DEFINED = 1

INTERFACE IADsPrintJobOperations $IID_IADsPrintJobOperations

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IADsPrintJobOperations Methods
   ' =====================================================================================
   PROPERTY GET Status <26> ( _                         ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY GET TimeElapsed <27> ( _                    ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY GET PagesPrinted <28> ( _                   ' VTable offset = 88
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY GET Position <29> ( _                       ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET Position <29> ( _                       ' VTable offset = 96
     BYVAL lnPosition AS LONG _                         ' __in long lnPosition
   )                                                    ' void
   ' =====================================================================================
   METHOD Pause <30> ( _                                ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================
   METHOD Resume <31> ( _                               ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsPrintJobOperations_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsService
' IID = {68AF66E0-31CA-11CF-A98A-00AA006BC149}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IADsService_INTERFACE_DEFINED)
    %IADsService_INTERFACE_DEFINED = 1

INTERFACE IADsService $IID_IADsService

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IADsService Methods
   ' =====================================================================================
   PROPERTY GET HostComputer <15> ( _                   ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET HostComputer <15> ( _                   ' VTable offset = 84
     BYVAL bstrHostComputer AS WSTRING _                ' __in BSTR bstrHostComputer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisplayName <16> ( _                    ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET DisplayName <16> ( _                    ' VTable offset = 92
     BYVAL bstrDisplayName AS WSTRING _                 ' __in BSTR bstrDisplayName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Version <17> ( _                        ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Version <17> ( _                        ' VTable offset = 100
     BYVAL bstrVersion AS WSTRING _                     ' __in BSTR bstrVersion
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ServiceType <18> ( _                    ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET ServiceType <18> ( _                    ' VTable offset = 108
     BYVAL lnServiceType AS LONG _                      ' __in long lnServiceType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartType <19> ( _                      ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET StartType <19> ( _                      ' VTable offset = 116
     BYVAL lnStartType AS LONG _                        ' __in long lnStartType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Path <20> ( _                           ' VTable offset = 120
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Path <20> ( _                           ' VTable offset = 124
     BYVAL bstrPath AS WSTRING _                        ' __in BSTR bstrPath
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartupParameters <21> ( _              ' VTable offset = 128
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET StartupParameters <21> ( _              ' VTable offset = 132
     BYVAL bstrStartupParameters AS WSTRING _           ' __in BSTR bstrStartupParameters
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ErrorControl <22> ( _                   ' VTable offset = 136
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET ErrorControl <22> ( _                   ' VTable offset = 140
     BYVAL lnErrorControl AS LONG _                     ' __in long lnErrorControl
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LoadOrderGroup <23> ( _                 ' VTable offset = 144
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET LoadOrderGroup <23> ( _                 ' VTable offset = 148
     BYVAL bstrLoadOrderGroup AS WSTRING _              ' __in BSTR bstrLoadOrderGroup
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ServiceAccountName <24> ( _             ' VTable offset = 152
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET ServiceAccountName <24> ( _             ' VTable offset = 156
     BYVAL bstrServiceAccountName AS WSTRING _          ' __in BSTR bstrServiceAccountName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ServiceAccountPath <25> ( _             ' VTable offset = 160
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET ServiceAccountPath <25> ( _             ' VTable offset = 164
     BYVAL bstrServiceAccountPath AS WSTRING _          ' __in BSTR bstrServiceAccountPath
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Dependencies <26> ( _                   ' VTable offset = 168
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET Dependencies <26> ( _                   ' VTable offset = 172
     BYVAL vDependencies AS VARIANT _                   ' __in VARIANT vDependencies
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsService_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsServiceOperations
' IID = {5D7B33F0-31CA-11CF-A98A-00AA006BC149}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IADsServiceOperations_INTERFACE_DEFINED)
    %IADsServiceOperations_INTERFACE_DEFINED = 1

INTERFACE IADsServiceOperations $IID_IADsServiceOperations

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IADsServiceOperations Methods
   ' =====================================================================================
   PROPERTY GET Status <27> ( _                         ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   METHOD Start <28> ( _                                ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <29> ( _                                 ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   METHOD Pause <30> ( _                                ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD Continue <31> ( _                             ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPassword <32> ( _                          ' VTable offset = 100
     BYVAL bstrNewPassword AS WSTRING _                 ' __in BSTR bstrNewPassword
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsServiceOperations_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsFileService
' IID = {A89D1900-31CA-11CF-A98A-00AA006BC149}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADsService
' ########################################################################################

#IF NOT %DEF(%IADsFileService_INTERFACE_DEFINED)
    %IADsFileService_INTERFACE_DEFINED = 1

INTERFACE IADsFileService $IID_IADsFileService

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IADsService Methods
   ' =====================================================================================
   PROPERTY GET HostComputer <15> ( _                   ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET HostComputer <15> ( _                   ' VTable offset = 84
     BYVAL bstrHostComputer AS WSTRING _                ' __in BSTR bstrHostComputer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisplayName <16> ( _                    ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET DisplayName <16> ( _                    ' VTable offset = 92
     BYVAL bstrDisplayName AS WSTRING _                 ' __in BSTR bstrDisplayName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Version <17> ( _                        ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Version <17> ( _                        ' VTable offset = 100
     BYVAL bstrVersion AS WSTRING _                     ' __in BSTR bstrVersion
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ServiceType <18> ( _                    ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET ServiceType <18> ( _                    ' VTable offset = 108
     BYVAL lnServiceType AS LONG _                      ' __in long lnServiceType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartType <19> ( _                      ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET StartType <19> ( _                      ' VTable offset = 116
     BYVAL lnStartType AS LONG _                        ' __in long lnStartType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Path <20> ( _                           ' VTable offset = 120
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Path <20> ( _                           ' VTable offset = 124
     BYVAL bstrPath AS WSTRING _                        ' __in BSTR bstrPath
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartupParameters <21> ( _              ' VTable offset = 128
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET StartupParameters <21> ( _              ' VTable offset = 132
     BYVAL bstrStartupParameters AS WSTRING _           ' __in BSTR bstrStartupParameters
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ErrorControl <22> ( _                   ' VTable offset = 136
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET ErrorControl <22> ( _                   ' VTable offset = 140
     BYVAL lnErrorControl AS LONG _                     ' __in long lnErrorControl
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LoadOrderGroup <23> ( _                 ' VTable offset = 144
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET LoadOrderGroup <23> ( _                 ' VTable offset = 148
     BYVAL bstrLoadOrderGroup AS WSTRING _              ' __in BSTR bstrLoadOrderGroup
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ServiceAccountName <24> ( _             ' VTable offset = 152
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET ServiceAccountName <24> ( _             ' VTable offset = 156
     BYVAL bstrServiceAccountName AS WSTRING _          ' __in BSTR bstrServiceAccountName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ServiceAccountPath <25> ( _             ' VTable offset = 160
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET ServiceAccountPath <25> ( _             ' VTable offset = 164
     BYVAL bstrServiceAccountPath AS WSTRING _          ' __in BSTR bstrServiceAccountPath
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Dependencies <26> ( _                   ' VTable offset = 168
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET Dependencies <26> ( _                   ' VTable offset = 172
     BYVAL vDependencies AS VARIANT _                   ' __in VARIANT vDependencies
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IADsFileService Methods
   ' =====================================================================================
   PROPERTY GET Description <33> ( _                    ' VTable offset = 176
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Description <33> ( _                    ' VTable offset = 180
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxUserCount <34> ( _                   ' VTable offset = 184
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET MaxUserCount <34> ( _                   ' VTable offset = 188
     BYVAL lnMaxUserCount AS LONG _                     ' __in long lnMaxUserCount
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsFileService_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsFileServiceOperations
' IID = {A02DED10-31CA-11CF-A98A-00AA006BC149}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADsServiceOperations
' ########################################################################################

#IF NOT %DEF(%IADsFileServiceOperations_INTERFACE_DEFINED)
    %IADsFileServiceOperations_INTERFACE_DEFINED = 1

INTERFACE IADsFileServiceOperations $IID_IADsFileServiceOperations

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IADsServiceOperations Methods
   ' =====================================================================================
   PROPERTY GET Status <27> ( _                         ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   METHOD Start <28> ( _                                ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <29> ( _                                 ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   METHOD Pause <30> ( _                                ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD Continue <31> ( _                             ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPassword <32> ( _                          ' VTable offset = 100
     BYVAL bstrNewPassword AS WSTRING _                 ' __in BSTR bstrNewPassword
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IADsFileServiceOperations Methods
   ' =====================================================================================
   METHOD Sessions <35> ( _                             ' VTable offset = 104
   ) AS IADsCollection                                  ' __retval_out IADsCollection **ppSessions
   ' =====================================================================================
   METHOD Resources <36> ( _                            ' VTable offset = 108
   ) AS IADsCollection                                  ' __retval_out IADsCollection **ppResources
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsFileServiceOperations_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsFileShare
' IID = {EB6DCAF0-4B83-11CF-A995-00AA006BC149}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IADsFileShare_INTERFACE_DEFINED)
    %IADsFileShare_INTERFACE_DEFINED = 1

INTERFACE IADsFileShare $IID_IADsFileShare

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IADsFileShare Methods
   ' =====================================================================================
   PROPERTY GET CurrentUserCount <15> ( _               ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY GET Description <16> ( _                    ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Description <16> ( _                    ' VTable offset = 88
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HostComputer <17> ( _                   ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET HostComputer <17> ( _                   ' VTable offset = 96
     BYVAL bstrHostComputer AS WSTRING _                ' __in BSTR bstrHostComputer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Path <18> ( _                           ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Path <18> ( _                           ' VTable offset = 104
     BYVAL bstrPath AS WSTRING _                        ' __in BSTR bstrPath
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxUserCount <19> ( _                   ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET MaxUserCount <19> ( _                   ' VTable offset = 112
     BYVAL lnMaxUserCount AS LONG _                     ' __in long lnMaxUserCount
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsFileShare_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsSession
' IID = {398B7DA0-4AAB-11CF-AE2C-00AA006EBFB9}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IADsSession_INTERFACE_DEFINED)
    %IADsSession_INTERFACE_DEFINED = 1

INTERFACE IADsSession $IID_IADsSession

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IADsSession Methods
   ' =====================================================================================
   PROPERTY GET User <15> ( _                           ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET UserPath <16> ( _                       ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Computer <17> ( _                       ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ComputerPath <18> ( _                   ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ConnectTime <19> ( _                    ' VTable offset = 96
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY GET IdleTime <20> ( _                       ' VTable offset = 100
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsSession_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsResource
' IID = {34A05B20-4AAB-11CF-AE2C-00AA006EBFB9}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IADsResource_INTERFACE_DEFINED)
    %IADsResource_INTERFACE_DEFINED = 1

INTERFACE IADsResource $IID_IADsResource

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IADsResource Methods
   ' =====================================================================================
   PROPERTY GET User <15> ( _                           ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET UserPath <16> ( _                       ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Path <17> ( _                           ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET LockCount <18> ( _                      ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsResource_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsOpenDSObject
' IID = {DDF2891E-0F9C-11D0-8AD4-00C04FD8D503}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsOpenDSObject_INTERFACE_DEFINED)
    %IADsOpenDSObject_INTERFACE_DEFINED = 1

INTERFACE IADsOpenDSObject $IID_IADsOpenDSObject

   INHERIT IDispatch

   ' =====================================================================================
   METHOD OpenDSObject <1> ( _                          ' VTable offset = 28
     BYVAL lpszDNName AS WSTRING _                      ' __in BSTR lpszDNName
   , BYVAL lpszUserName AS WSTRING _                    ' __in BSTR lpszUserName
   , BYVAL lpszPassword AS WSTRING _                    ' __in BSTR lpszPassword
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   ) AS IDispatch                                       ' __retval_out IDispatch **ppOleDsObj
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsOpenDSObject_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDirectoryObject
' IID = {E798DE2C-22E4-11D0-84FE-00C04FD8D503}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDirectoryObject_INTERFACE_DEFINED)
    %IDirectoryObject_INTERFACE_DEFINED = 1

INTERFACE IDirectoryObject $IID_IDirectoryObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetObjectInformation ( _                      ' VTable offset = 12
     BYREF ADS_OBJECT_INFO _                            ' __out PADS_OBJECT_INFO *ppObjInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjectAttributes ( _                       ' VTable offset = 16
     BYREF pAttributeNames AS DWORD _                   ' __in LPWSTR *pAttributeNames
   , BYVAL dwNumberAttributes AS DWORD _                ' __in DWORD dwNumberAttributes
   , BYREF ppAttributeEntries AS ADS_ATTR_INFO _        ' __out PADS_ATTR_INFO *ppAttributeEntries
   , BYREF pdwNumAttributesReturned AS DWORD _          ' __out DWORD *pdwNumAttributesReturned
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetObjectAttributes ( _                       ' VTable offset = 20
     BYREF pAttributeEntries AS ADS_ATTR_INFO _         ' __in PADS_ATTR_INFO pAttributeEntries
   , BYVAL dwNumAttributes AS DWORD _                   ' __in DWORD dwNumAttributes
   , BYREF pdwNumAttributesModified AS DWORD _          ' __out DWORD *pdwNumAttributesModified
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDSObject ( _                            ' VTable offset = 24
     BYREF pszRDNName AS WSTRINGZ _                     ' __in LPWSTR pszRDNName
   , BYREF pAttributeEntries AS ADS_ATTR_INFO _         ' __in PADS_ATTR_INFO pAttributeEntries
   , BYVAL dwNumAttributes AS DWORD _                   ' __in DWORD dwNumAttributes
   , BYREF ppObject AS IDispatch _                      ' __out IDispatch **ppObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteDSObject ( _                            ' VTable offset = 28
     BYREF pszRDNName AS WSTRINGZ _                     ' __in LPWSTR pszRDNName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDirectoryObject_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDirectorySearch
' IID = {109BA8EC-92F0-11D0-A790-00C04FD8D5A8}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDirectorySearch_INTERFACE_DEFINED)
    %IDirectorySearch_INTERFACE_DEFINED = 1

INTERFACE IDirectorySearch $IID_IDirectorySearch

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetSearchPreference ( _                       ' VTable offset = 12
     BYREF pSearchPrefs AS ADS_SEARCHPREF_INFO _        ' __in PADS_SEARCHPREF_INFO pSearchPrefs
   , BYVAL dwNumPrefs AS DWORD _                        ' __in DWORD dwNumPrefs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExecuteSearch ( _                             ' VTable offset = 16
     BYREF pszSearchFilter AS WSTRINGZ _                ' __in LPWSTR pszSearchFilter
   , BYREF pAttributeNames AS DWORD _                   ' __in LPWSTR *pAttributeNames
   , BYVAL dwNumberAttributes AS DWORD _                ' __in DWORD dwNumberAttributes
   , BYREF phSearchResult AS DWORD _                    ' __out PADS_SEARCH_HANDLE phSearchResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AbandonSearch ( _                             ' VTable offset = 20
     BYVAL phSearchResult AS DWORD _                    ' __in ADS_SEARCH_HANDLE phSearchResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFirstRow ( _                               ' VTable offset = 24
     BYVAL hSearchResult AS DWORD _                     ' __in ADS_SEARCH_HANDLE hSearchResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextRow ( _                                ' VTable offset = 28
     BYVAL hSearchResult AS DWORD _                     ' __in ADS_SEARCH_HANDLE hSearchResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPreviousRow ( _                            ' VTable offset = 32
     BYVAL hSearchResult AS DWORD _                     ' __in ADS_SEARCH_HANDLE hSearchResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextColumnName ( _                         ' VTable offset = 36
     BYVAL hSearchHandle AS DWORD _                     ' __in ADS_SEARCH_HANDLE hSearchHandle
   , BYREF ppszColumnName AS DWORD _                    ' __out LPWSTR *ppszColumnName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColumn ( _                                 ' VTable offset = 40
     BYVAL hSearchResult AS DWORD _                     ' __in ADS_SEARCH_HANDLE hSearchResult
   , BYREF szColumnName AS WSTRINGZ _                   ' __in LPWSTR szColumnName
   , BYREF pSearchColumn AS ADS_SEARCH_COLUMN _         ' __out PADS_SEARCH_COLUMN pSearchColumn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeColumn ( _                                ' VTable offset = 44
     BYREF pSearchColumn AS ADS_SEARCH_COLUMN _         ' __in PADS_SEARCH_COLUMN pSearchColumn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloseSearchHandle ( _                         ' VTable offset = 48
     BYVAL hSearchResult AS DWORD _                     ' __in ADS_SEARCH_HANDLE hSearchResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDirectorySearch_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDirectorySchemaMgmt
' IID = {75DB3B9C-A4D8-11D0-A79C-00C04FD8D5A8}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDirectorySchemaMgmt_INTERFACE_DEFINED)
    %IDirectorySchemaMgmt_INTERFACE_DEFINED = 1

INTERFACE IDirectorySchemaMgmt $IID_IDirectorySchemaMgmt

   INHERIT IUnknown

   ' =====================================================================================
   METHOD EnumAttributes ( _                            ' VTable offset = 12
     BYREF ppszAttrNames AS DWORD _                     ' LPWSTR *ppszAttrNames
   , BYVAL dwNumAttributes AS DWORD _                   ' DWORD dwNumAttributes
   , BYREF ppAttrDefinition AS ADS_ATTR_DEF _           ' PADS_ATTR_DEF *ppAttrDefinition
   , BYREF pdwNumAttributes AS DWORD _                  ' DWORD *pdwNumAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateAttributeDefinition ( _                 ' VTable offset = 16
     BYREF pszAttributeName AS WSTRINGZ _               ' LPWSTR pszAttributeName
   , BYREF pAttributeDefinition AS ADS_ATTR_DEF _       ' PADS_ATTR_DEF pAttributeDefinition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteAttributeDefinition ( _                  ' VTable offset = 20
     BYREF pszAttributeName AS WSTRINGZ _               ' LPWSTR pszAttributeName
   , BYREF pAttributeDefinition AS ADS_ATTR_DEF _       ' PADS_ATTR_DEF pAttributeDefinition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAttributeDefinition ( _                 ' VTable offset = 24
     BYREF pszAttributeName AS WSTRINGZ _               ' LPWSTR pszAttributeName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumClasses ( _                               ' VTable offset = 28
     BYREF ppszClassNames AS DWORD _                    ' LPWSTR *ppszClassNames
   , BYVAL dwNumClasses AS DWORD _                      ' DWORD dwNumClasses
   , BYREF ppClassDefinition AS ADS_CLASS_DEF _         ' PADS_CLASS_DEF *ppClassDefinition
   , BYREF pdwNumClasses AS DWORD _                     ' DWORD *pdwNumClasses
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteClassDefinition ( _                      ' VTable offset = 32
     BYREF pszClassName AS WSTRINGZ _                   ' LPWSTR pszClassName
   , BYREF pClassDefinition AS ADS_CLASS_DEF _          ' PADS_CLASS_DEF pClassDefinition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateClassDefinition ( _                     ' VTable offset = 36
     BYREF pszClassName AS WSTRINGZ _                   ' LPWSTR pszClassName
   , BYREF pClassDefinition AS ADS_CLASS_DEF _          ' PADS_CLASS_DEF pClassDefinition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteClassDefinition ( _                     ' VTable offset = 40
     BYREF pszClassName AS WSTRINGZ _                   ' LPWSTR pszClassName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDirectorySchemaMgmt_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsAggregatee
' IID = {1346CE8C-9039-11D0-8528-00C04FD8D503}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IADsAggregatee_INTERFACE_DEFINED)
    %IADsAggregatee_INTERFACE_DEFINED = 1

INTERFACE IADsAggregatee $IID_IADsAggregatee

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ConnectAsAggregatee ( _                       ' VTable offset = 12
     BYVAL pOuterUnknown AS IUnknown _                  ' IUnknown *pOuterUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisconnectAsAggregatee ( _                    ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RelinquishInterface ( _                       ' VTable offset = 20
     BYREF riid AS GUID _                               ' REFIID riid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RestoreInterface ( _                          ' VTable offset = 24
     BYREF riid AS GUID _                               ' REFIID riid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsAggregatee_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsAggregator
' IID = {52DB5FB0-941F-11D0-8529-00C04FD8D503}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IADsAggregator_INTERFACE_DEFINED)
    %IADsAggregator_INTERFACE_DEFINED = 1

INTERFACE IADsAggregator $IID_IADsAggregator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ConnectAsAggregator ( _                       ' VTable offset = 12
     BYVAL pAggregatee AS IUnknown _                    ' IUnknown *pAggregatee
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisconnectAsAggregator ( _                    ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsAggregator_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsAccessControlEntry
' IID = {B4F3A14C-9BDD-11D0-852C-00C04FD8D503}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsAccessControlEntry_INTERFACE_DEFINED)
    %IADsAccessControlEntry_INTERFACE_DEFINED = 1

INTERFACE IADsAccessControlEntry $IID_IADsAccessControlEntry

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET AccessMask <2> ( _                      ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET AccessMask <2> ( _                      ' VTable offset = 32
     BYVAL lnAccessMask AS LONG _                       ' __in long lnAccessMask
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AceType <3> ( _                         ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET AceType <3> ( _                         ' VTable offset = 40
     BYVAL lnAceType AS LONG _                          ' __in long lnAceType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AceFlags <4> ( _                        ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET AceFlags <4> ( _                        ' VTable offset = 48
     BYVAL lnAceFlags AS LONG _                         ' __in long lnAceFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Flags <5> ( _                           ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET Flags <5> ( _                           ' VTable offset = 56
     BYVAL lnFlags AS LONG _                            ' __in long lnFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectType <6> ( _                      ' VTable offset = 60
   ) AS WSTRING                                         ' retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET ObjectType <6> ( _                      ' VTable offset = 64
     BYVAL bstrObjectType AS WSTRING _                  ' __in BSTR bstrObjectType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InheritedObjectType <7> ( _             ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET InheritedObjectType <7> ( _             ' VTable offset = 72
     BYVAL bstrInheritedObjectType AS WSTRING _         ' __in BSTR bstrInheritedObjectType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Trustee <8> ( _                         ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Trustee <8> ( _                         ' VTable offset = 80
     BYVAL bstrTrustee AS WSTRING _                     ' __in BSTR bstrTrustee
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsAccessControlEntry_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsAccessControlList
' IID = {B7EE91CC-9BDD-11D0-852C-00C04FD8D503}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsAccessControlList_INTERFACE_DEFINED)
    %IADsAccessControlList_INTERFACE_DEFINED = 1

INTERFACE IADsAccessControlList $IID_IADsAccessControlList

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET AclRevision <3> ( _                     ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET AclRevision <3> ( _                     ' VTable offset = 32
     BYVAL lnAclRevision AS LONG _                      ' __in long lnAclRevision
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AceCount <4> ( _                        ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET AceCount <4> ( _                        ' VTable offset = 40
     BYVAL lnAceCount AS LONG _                         ' __in long lnAceCount
   )                                                    ' void
   ' =====================================================================================
   METHOD AddAce <5> ( _                                ' VTable offset = 44
     BYVAL pAccessControlEntry AS IDispatch _           ' __in IDispatch *pAccessControlEntry
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveAce <6> ( _                             ' VTable offset = 48
     BYVAL pAccessControlEntry AS IDispatch _           ' __in IDispatch *pAccessControlEntry
   )                                                    ' void
   ' =====================================================================================
   METHOD CopyAccessList <7> ( _                        ' VTable offset = 52
   ) AS IDispatch                                       ' __retval_out IDispatch **ppAccessControlList
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 56
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsAccessControlList_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsSecurityDescriptor
' IID = {B8C787CA-9BDD-11D0-852C-00C04FD8D503}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsSecurityDescriptor_INTERFACE_DEFINED)
    %IADsSecurityDescriptor_INTERFACE_DEFINED = 1

INTERFACE IADsSecurityDescriptor $IID_IADsSecurityDescriptor

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Revision <2> ( _                        ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET Revision <2> ( _                        ' VTable offset = 32
     BYVAL lnRevision AS LONG _                         ' __in long lnRevision
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Control <3> ( _                         ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET Control <3> ( _                         ' VTable offset = 40
     BYVAL lnControl AS LONG _                          ' __in long lnControl
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Owner <4> ( _                           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Owner <4> ( _                           ' VTable offset = 48
     BYVAL bstrOwner AS WSTRING _                       ' __in BSTR bstrOwner
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OwnerDefaulted <5> ( _                  ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retval
   ' =====================================================================================
   PROPERTY SET OwnerDefaulted <5> ( _                  ' VTable offset = 56
     BYVAL fOwnerDefaulted AS INTEGER _                 ' __in VARIANT_BOOL fOwnerDefaulted
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Group <6> ( _                           ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Group <6> ( _                           ' VTable offset = 64
     BYVAL bstrGroup AS WSTRING _                       ' __in BSTR bstrGroup
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GroupDefaulted <7> ( _                  ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retval
   ' =====================================================================================
   PROPERTY SET GroupDefaulted <7> ( _                  ' VTable offset = 72
     BYVAL fGroupDefaulted AS INTEGER _                 ' __in VARIANT_BOOL fGroupDefaulted
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DiscretionaryAcl <8> ( _                ' VTable offset = 76
   ) AS IDispatch                                       ' __retval_out IDispatch **retval
   ' =====================================================================================
   PROPERTY SET DiscretionaryAcl <8> ( _                ' VTable offset = 80
     BYVAL pDiscretionaryAcl AS IDispatch _             ' __in IDispatch *pDiscretionaryAcl
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DaclDefaulted <9> ( _                   ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retval
   ' =====================================================================================
   PROPERTY SET DaclDefaulted <9> ( _                   ' VTable offset = 88
     BYVAL fDaclDefaulted AS INTEGER _                  ' __in VARIANT_BOOL fDaclDefaulted
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SystemAcl <10> ( _                      ' VTable offset = 92
   ) AS IDispatch                                       ' __retval_out IDispatch **retval
   ' =====================================================================================
   PROPERTY SET SystemAcl <10> ( _                      ' VTable offset = 96
     BYVAL pSystemAcl AS IDispatch _                    ' __in IDispatch *pSystemAcl
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SaclDefaulted <11> ( _                  ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retval
   ' =====================================================================================
   PROPERTY SET SaclDefaulted <11> ( _                  ' VTable offset = 104
     BYVAL fSaclDefaulted AS INTEGER _                  ' __in VARIANT_BOOL fSaclDefaulted
   )                                                    ' void
   ' =====================================================================================
   METHOD CopySecurityDescriptor <12> ( _               ' VTable offset = 108
   ) AS IDispatch                                       ' __retval_out IDispatch **ppSecurityDescriptor
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsSecurityDescriptor_INTERFACE_DEFINED__ */

' ========================================================================================
' ADS_RIGHTS_ENUM enum
' ========================================================================================

%ADS_RIGHT_DELETE                 = &H10000???
%ADS_RIGHT_READ_CONTROL           = &H20000???
%ADS_RIGHT_WRITE_DAC              = &H40000???
%ADS_RIGHT_WRITE_OWNER            = &H80000???
%ADS_RIGHT_SYNCHRONIZE            = &H100000???
%ADS_RIGHT_ACCESS_SYSTEM_SECURITY = &H1000000???
%ADS_RIGHT_GENERIC_READ           = &H80000000???
%ADS_RIGHT_GENERIC_WRITE          = &H40000000???
%ADS_RIGHT_GENERIC_EXECUTE        = &H20000000???
%ADS_RIGHT_GENERIC_ALL            = &H10000000???
%ADS_RIGHT_DS_CREATE_CHILD        = &H1???
%ADS_RIGHT_DS_DELETE_CHILD        = &H2???
%ADS_RIGHT_ACTRL_DS_LIST          = &H4???
%ADS_RIGHT_DS_SELF                = &H8???
%ADS_RIGHT_DS_READ_PROP           = &H10???
%ADS_RIGHT_DS_WRITE_PROP          = &H20???
%ADS_RIGHT_DS_DELETE_TREE         = &H40???
%ADS_RIGHT_DS_LIST_OBJECT         = &H80???
%ADS_RIGHT_DS_CONTROL_ACCESS      = &H100???

' ========================================================================================
' ADS_ACETYPE_ENUM enum
' ========================================================================================

%ADS_ACETYPE_ACCESS_ALLOWED                 = &H0
%ADS_ACETYPE_ACCESS_DENIED                  = &H1
%ADS_ACETYPE_SYSTEM_AUDIT                   = &H2
%ADS_ACETYPE_ACCESS_ALLOWED_OBJECT          = &H5
%ADS_ACETYPE_ACCESS_DENIED_OBJECT           = &H6
%ADS_ACETYPE_SYSTEM_AUDIT_OBJECT            = &H7
%ADS_ACETYPE_SYSTEM_ALARM_OBJECT            = &H8
%ADS_ACETYPE_ACCESS_ALLOWED_CALLBACK        = &H9
%ADS_ACETYPE_ACCESS_DENIED_CALLBACK         = &HA
%ADS_ACETYPE_ACCESS_ALLOWED_CALLBACK_OBJECT = &HB
%ADS_ACETYPE_ACCESS_DENIED_CALLBACK_OBJECT  = &HC
%ADS_ACETYPE_SYSTEM_AUDIT_CALLBACK          = &HD
%ADS_ACETYPE_SYSTEM_ALARM_CALLBACK          = &HE
%ADS_ACETYPE_SYSTEM_AUDIT_CALLBACK_OBJECT   = &HF
%ADS_ACETYPE_SYSTEM_ALARM_CALLBACK_OBJECT   = &H10

' ========================================================================================
' ADS_ACEFLAG_ENUM enum
' ========================================================================================

%ADS_ACEFLAG_INHERIT_ACE              = &H2
%ADS_ACEFLAG_NO_PROPAGATE_INHERIT_ACE = &H4
%ADS_ACEFLAG_INHERIT_ONLY_ACE         = &H8
%ADS_ACEFLAG_INHERITED_ACE            = &H10
%ADS_ACEFLAG_VALID_INHERIT_FLAGS      = &H1F
%ADS_ACEFLAG_SUCCESSFUL_ACCESS        = &H40
%ADS_ACEFLAG_FAILED_ACCESS            = &H80

' ========================================================================================
' ADS_FLAGTYPE_ENUM enum
' ========================================================================================

%ADS_FLAG_OBJECT_TYPE_PRESENT           = &H1
%ADS_FLAG_INHERITED_OBJECT_TYPE_PRESENT = &H2

' ========================================================================================
' ADS_SD_CONTROL_ENUM enum
' ========================================================================================

%ADS_SD_CONTROL_SE_OWNER_DEFAULTED       = &H1???
%ADS_SD_CONTROL_SE_GROUP_DEFAULTED       = &H2???
%ADS_SD_CONTROL_SE_DACL_PRESENT          = &H4???
%ADS_SD_CONTROL_SE_DACL_DEFAULTED        = &H8???
%ADS_SD_CONTROL_SE_SACL_PRESENT          = &H10???
%ADS_SD_CONTROL_SE_SACL_DEFAULTED        = &H20???
%ADS_SD_CONTROL_SE_DACL_AUTO_INHERIT_REQ = &H100???
%ADS_SD_CONTROL_SE_SACL_AUTO_INHERIT_REQ = &H200???
%ADS_SD_CONTROL_SE_DACL_AUTO_INHERITED   = &H400???
%ADS_SD_CONTROL_SE_SACL_AUTO_INHERITED   = &H800???
%ADS_SD_CONTROL_SE_DACL_PROTECTED        = &H1000???
%ADS_SD_CONTROL_SE_SACL_PROTECTED        = &H2000???
%ADS_SD_CONTROL_SE_SELF_RELATIVE         = &H8000???

' ========================================================================================
' ADS_SD_REVISION_ENUM enum
' ========================================================================================

%ADS_SD_REVISION_DS = 4

' ########################################################################################
' Interface name = IADsLargeInteger
' IID = {9068270B-0939-11D1-8BE1-00C04FD8D503}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsLargeInteger_INTERFACE_DEFINED)
    %IADsLargeInteger_INTERFACE_DEFINED = 1

INTERFACE IADsLargeInteger $IID_IADsLargeInteger

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET HighPart <2> ( _                        ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET HighPart <2> ( _                        ' VTable offset = 32
     BYVAL lnHighPart AS LONG _                         ' __in long lnHighPart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LowPart <3> ( _                         ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET LowPart <3> ( _                         ' VTable offset = 40
     BYVAL lnLowPart AS LONG _                          ' __in long lnLowPart
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsLargeInteger_INTERFACE_DEFINED__ */

' ========================================================================================
' ADS_NAME_TYPE_ENUM enum
' ========================================================================================

%ADS_NAME_TYPE_1779                    = 1
%ADS_NAME_TYPE_CANONICAL               = 2
%ADS_NAME_TYPE_NT4                     = 3
%ADS_NAME_TYPE_DISPLAY                 = 4
%ADS_NAME_TYPE_DOMAIN_SIMPLE           = 5
%ADS_NAME_TYPE_ENTERPRISE_SIMPLE       = 6
%ADS_NAME_TYPE_GUID                    = 7
%ADS_NAME_TYPE_UNKNOWN                 = 8
%ADS_NAME_TYPE_USER_PRINCIPAL_NAME     = 9
%ADS_NAME_TYPE_CANONICAL_EX            = 10
%ADS_NAME_TYPE_SERVICE_PRINCIPAL_NAME  = 11
%ADS_NAME_TYPE_SID_OR_SID_HISTORY_NAME = 12

' ========================================================================================
' ADS_NAME_INITTYPE_ENUM enum
' ========================================================================================

%ADS_NAME_INITTYPE_DOMAIN = 1
%ADS_NAME_INITTYPE_SERVER = 2
%ADS_NAME_INITTYPE_GC     = 3

' ########################################################################################
' Interface name = IADsNameTranslate
' IID = {B1B272A3-3625-11D1-A3A4-00C04FB950DC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsNameTranslate_INTERFACE_DEFINED)
    %IADsNameTranslate_INTERFACE_DEFINED = 1

INTERFACE IADsNameTranslate $IID_IADsNameTranslate

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET ChaseReferral <1> ( _                   ' VTable offset = 28
     BYVAL lnChaseReferral AS LONG _                    ' __in long lnChaseReferral
   )                                                    ' void
   ' =====================================================================================
   METHOD Init <2> ( _                                  ' VTable offset = 32
     BYVAL lnSetType AS LONG _                          ' __in long lnSetType
   , BYVAL bstrADsPath AS WSTRING _                     ' __in BSTR bstrADsPath
   )                                                    ' void
   ' =====================================================================================
   METHOD InitEx <3> ( _                                ' VTable offset = 36
     BYVAL lnSetType AS LONG _                          ' __in long lnSetType
   , BYVAL bstrADsPath AS WSTRING _                     ' __in BSTR bstrADsPath
   , BYVAL bstrUserID AS WSTRING _                      ' __in BSTR bstrUserID
   , BYVAL bstrDomain AS WSTRING _                      ' __in BSTR bstrDomain
   , BYVAL bstrPassword AS WSTRING _                    ' __in BSTR bstrPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD Set <4> ( _                                   ' VTable offset = 40
     BYVAL lnSetType AS LONG _                          ' __in long lnSetType
   , BYVAL bstrADsPath AS WSTRING _                     ' __in BSTR bstrADsPath
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <5> ( _                                   ' VTable offset = 44
     BYVAL lnFormatType AS LONG _                       ' __in long lnFormatType
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrADsPath
   ' =====================================================================================
   METHOD SetEx <6> ( _                                 ' VTable offset = 48
     BYVAL lnFormatType AS LONG _                       ' __in long lnFormatType
   , BYVAL pvar AS VARIANT _                            ' __in VARIANT pvar
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <7> ( _                                 ' VTable offset = 52
     BYVAL lnFormatType AS LONG _                       ' __in long lnFormatType
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsNameTranslate_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsCaseIgnoreList
' IID = {7B66B533-4680-11D1-A3B4-00C04FB950DC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsCaseIgnoreList_INTERFACE_DEFINED)
    %IADsCaseIgnoreList_INTERFACE_DEFINED = 1

INTERFACE IADsCaseIgnoreList $IID_IADsCaseIgnoreList

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET CaseIgnoreList <2> ( _                  ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET CaseIgnoreList <2> ( _                  ' VTable offset = 32
     BYVAL vCaseIgnoreList AS VARIANT _                 ' __in VARIANT vCaseIgnoreList
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsCaseIgnoreList_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsFaxNumber
' IID = {A910DEA9-4680-11D1-A3B4-00C04FB950DC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsFaxNumber_INTERFACE_DEFINED)
    %IADsFaxNumber_INTERFACE_DEFINED = 1

INTERFACE IADsFaxNumber $IID_IADsFaxNumber

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET TelephoneNumber <2> ( _                 ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET TelephoneNumber <2> ( _                 ' VTable offset = 32
     BYVAL bstrTelephoneNumber AS WSTRING _             ' __in BSTR bstrTelephoneNumber
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Parameters <3> ( _                      ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET Parameters <3> ( _                      ' VTable offset = 40
     BYVAL vParameters AS VARIANT _                     ' __in VARIANT vParameters
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsFaxNumber_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsNetAddress
' IID = {B21A50A9-4080-11D1-A3AC-00C04FB950DC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsNetAddress_INTERFACE_DEFINED)
    %IADsNetAddress_INTERFACE_DEFINED = 1

INTERFACE IADsNetAddress $IID_IADsNetAddress

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET AddressType <2> ( _                     ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET AddressType <2> ( _                     ' VTable offset = 32
     BYVAL lnAddressType AS LONG _                      ' __in long lnAddressType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Address <3> ( _                         ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET Address <3> ( _                         ' VTable offset = 40
     BYVAL vAddress AS VARIANT _                        ' __in VARIANT vAddress
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsNetAddress_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsOctetList
' IID = {7B28B80F-4680-11D1-A3B4-00C04FB950DC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsOctetList_INTERFACE_DEFINED)
    %IADsOctetList_INTERFACE_DEFINED = 1

INTERFACE IADsOctetList $IID_IADsOctetList

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET OctetList <2> ( _                       ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET OctetList <2> ( _                       ' VTable offset = 32
     BYVAL vOctetList AS VARIANT _                      ' __in VARIANT vOctetList
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsOctetList_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsEmail
' IID = {97AF011A-478E-11D1-A3B4-00C04FB950DC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsEmail_INTERFACE_DEFINED)
    %IADsEmail_INTERFACE_DEFINED = 1

INTERFACE IADsEmail $IID_IADsEmail

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Type <2> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET Type <2> ( _                            ' VTable offset = 32
     BYVAL lnType AS LONG _                             ' __in long lnType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Address <3> ( _                         ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Address <3> ( _                         ' VTable offset = 40
     BYVAL bstrAddress AS WSTRING _                     ' __in BSTR bstrAddress
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsEmail_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsPath
' IID = {B287FCD5-4080-11D1-A3AC-00C04FB950DC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsPath_INTERFACE_DEFINED)
    %IADsPath_INTERFACE_DEFINED = 1

INTERFACE IADsPath $IID_IADsPath

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Type <2> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET Type <2> ( _                            ' VTable offset = 32
     BYVAL lnType AS LONG _                             ' __in long lnType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET VolumeName <3> ( _                      ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET VolumeName <3> ( _                      ' VTable offset = 40
     BYVAL bstrVolumeName AS WSTRING _                  ' __in BSTR bstrVolumeName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Path <4> ( _                            ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET Path <4> ( _                            ' VTable offset = 48
     BYVAL bstrPath AS WSTRING _                        ' __in BSTR bstrPath
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsPath_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsReplicaPointer
' IID = {F60FB803-4080-11D1-A3AC-00C04FB950DC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsReplicaPointer_INTERFACE_DEFINED)
    %IADsReplicaPointer_INTERFACE_DEFINED = 1

INTERFACE IADsReplicaPointer $IID_IADsReplicaPointer

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ServerName <2> ( _                      ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET ServerName <2> ( _                      ' VTable offset = 32
     BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReplicaType <3> ( _                     ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET ReplicaType <3> ( _                     ' VTable offset = 40
     BYVAL lnReplicaType AS LONG _                      ' __in long lnReplicaType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReplicaNumber <4> ( _                   ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET ReplicaNumber <4> ( _                   ' VTable offset = 48
     BYVAL lnReplicaNumber AS LONG _                    ' __in long lnReplicaNumber
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Count <5> ( _                           ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET Count <5> ( _                           ' VTable offset = 56
     BYVAL lnCount AS LONG _                            ' __in long lnCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReplicaAddressHints <6> ( _             ' VTable offset = 60
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET ReplicaAddressHints <6> ( _             ' VTable offset = 64
     BYVAL vReplicaAddressHints AS VARIANT _            ' __in VARIANT vReplicaAddressHints
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsReplicaPointer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsAcl
' IID = {8452D3AB-0869-11D1-A377-00C04FB950DC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsAcl_INTERFACE_DEFINED)
    %IADsAcl_INTERFACE_DEFINED = 1

INTERFACE IADsAcl $IID_IADsAcl

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ProtectedAttrName <2> ( _               ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET ProtectedAttrName <2> ( _               ' VTable offset = 32
     BYVAL bstrProtectedAttrName AS WSTRING _           ' __in BSTR bstrProtectedAttrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubjectName <3> ( _                     ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET SubjectName <3> ( _                     ' VTable offset = 40
     BYVAL bstrSubjectName AS WSTRING _                 ' __in BSTR bstrSubjectName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Privileges <4> ( _                      ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET Privileges <4> ( _                      ' VTable offset = 48
     BYVAL lnPrivileges AS LONG _                       ' __in long lnPrivileges
   )                                                    ' void
   ' =====================================================================================
   METHOD CopyAcl <5> ( _                               ' VTable offset = 52
   ) AS IDispatch                                       ' __retval_out IDispatch **ppAcl
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsAcl_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsTimestamp
' IID = {B2F5A901-4080-11D1-A3AC-00C04FB950DC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsTimestamp_INTERFACE_DEFINED)
    %IADsTimestamp_INTERFACE_DEFINED = 1

INTERFACE IADsTimestamp $IID_IADsTimestamp

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET WholeSeconds <2> ( _                    ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET WholeSeconds <2> ( _                    ' VTable offset = 32
     BYVAL lnWholeSeconds AS LONG _                     ' __in long lnWholeSeconds
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EventID <3> ( _                         ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET EventID <3> ( _                         ' VTable offset = 40
     BYVAL lnEventID AS LONG _                          ' __in long lnEventID
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsTimestamp_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsPostalAddress
' IID = {7ADECF29-4680-11D1-A3B4-00C04FB950DC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsPostalAddress_INTERFACE_DEFINED)
    %IADsPostalAddress_INTERFACE_DEFINED = 1

INTERFACE IADsPostalAddress $IID_IADsPostalAddress

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET PostalAddress <2> ( _                   ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET PostalAddress <2> ( _                   ' VTable offset = 32
     BYVAL vPostalAddress AS VARIANT _                  ' __in VARIANT vPostalAddress
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsPostalAddress_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsBackLink
' IID = {FD1302BD-4080-11D1-A3AC-00C04FB950DC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsBackLink_INTERFACE_DEFINED)
    %IADsBackLink_INTERFACE_DEFINED = 1

INTERFACE IADsBackLink $IID_IADsBackLink

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET RemoteID <2> ( _                        ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET RemoteID <2> ( _                        ' VTable offset = 32
     BYVAL lnRemoteID AS LONG _                         ' __in long lnRemoteID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectName <3> ( _                      ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET ObjectName <3> ( _                      ' VTable offset = 40
     BYVAL bstrObjectName AS WSTRING _                  ' __in BSTR bstrObjectName
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsBackLink_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsTypedName
' IID = {B371A349-4080-11D1-A3AC-00C04FB950DC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsTypedName_INTERFACE_DEFINED)
    %IADsTypedName_INTERFACE_DEFINED = 1

INTERFACE IADsTypedName $IID_IADsTypedName

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ObjectName <2> ( _                      ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET ObjectName <2> ( _                      ' VTable offset = 32
     BYVAL bstrObjectName AS WSTRING _                  ' __in BSTR bstrObjectName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Level <3> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET Level <3> ( _                           ' VTable offset = 40
     BYVAL lnLevel AS LONG _                            ' __in long lnLevel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Interval <4> ( _                        ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET Interval <4> ( _                        ' VTable offset = 48
     BYVAL lnInterval AS LONG _                         ' __in long lnInterval
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsTypedName_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsHold
' IID = {B3EB3B37-4080-11D1-A3AC-00C04FB950DC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsHold_INTERFACE_DEFINED)
    %IADsHold_INTERFACE_DEFINED = 1

INTERFACE IADsHold $IID_IADsHold

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ObjectName <2> ( _                      ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET ObjectName <2> ( _                      ' VTable offset = 32
     BYVAL bstrObjectName AS WSTRING _                  ' __in BSTR bstrObjectName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Amount <3> ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET Amount <3> ( _                          ' VTable offset = 40
     BYVAL lnAmount AS LONG _                           ' __in long lnAmount
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsHold_INTERFACE_DEFINED__ */

' ========================================================================================
' ADS_OPTION_ENUM enum
' ========================================================================================

%ADS_OPTION_SERVERNAME                = 0
%ADS_OPTION_REFERRALS                 = %ADS_OPTION_SERVERNAME + 1
%ADS_OPTION_PAGE_SIZE                 = %ADS_OPTION_REFERRALS + 1
%ADS_OPTION_SECURITY_MASK             = %ADS_OPTION_PAGE_SIZE + 1
%ADS_OPTION_MUTUAL_AUTH_STATUS        = %ADS_OPTION_SECURITY_MASK + 1
%ADS_OPTION_QUOTA                     = %ADS_OPTION_MUTUAL_AUTH_STATUS + 1
%ADS_OPTION_PASSWORD_PORTNUMBER       = %ADS_OPTION_QUOTA + 1
%ADS_OPTION_PASSWORD_METHOD           = %ADS_OPTION_PASSWORD_PORTNUMBER + 1
%ADS_OPTION_ACCUMULATIVE_MODIFICATION = %ADS_OPTION_PASSWORD_METHOD + 1
%ADS_OPTION_SKIP_SID_LOOKUP           = %ADS_OPTION_ACCUMULATIVE_MODIFICATION + 1

' ========================================================================================
' ADS_SECURITY_INFO_ENUM enum
' ========================================================================================

%ADS_SECURITY_INFO_OWNER = &H1
%ADS_SECURITY_INFO_GROUP = &H2
%ADS_SECURITY_INFO_DACL  = &H4
%ADS_SECURITY_INFO_SACL  = &H8

' ########################################################################################
' Interface name = IADsObjectOptions
' IID = {46F14FDA-232B-11D1-A808-00C04FD8D5A8}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsObjectOptions_INTERFACE_DEFINED)
    %IADsObjectOptions_INTERFACE_DEFINED = 1

INTERFACE IADsObjectOptions $IID_IADsObjectOptions

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetOption <2> ( _                             ' VTable offset = 28
     BYVAL lnOption AS LONG _                           ' __in long lnOption
   ) AS VARIANT                                         ' __retval_out VARIANT *pvValue
   ' =====================================================================================
   METHOD SetOption <3> ( _                             ' VTable offset = 32
     BYVAL lnOption AS LONG _                           ' __in long lnOption
   , BYVAL vValue AS VARIANT _                          ' __in VARIANT vValue
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsObjectOptions_INTERFACE_DEFINED__ */

' ========================================================================================
' ADS_SETTYPE_ENUM enum
' ========================================================================================

%ADS_SETTYPE_FULL     = 1
%ADS_SETTYPE_PROVIDER = 2
%ADS_SETTYPE_SERVER   = 3
%ADS_SETTYPE_DN       = 4

' ========================================================================================
' ADS_FORMAT_ENUM enum
' ========================================================================================

%ADS_FORMAT_WINDOWS           = 1
%ADS_FORMAT_WINDOWS_NO_SERVER = 2
%ADS_FORMAT_WINDOWS_DN        = 3
%ADS_FORMAT_WINDOWS_PARENT    = 4
%ADS_FORMAT_X500              = 5
%ADS_FORMAT_X500_NO_SERVER    = 6
%ADS_FORMAT_X500_DN           = 7
%ADS_FORMAT_X500_PARENT       = 8
%ADS_FORMAT_SERVER            = 9
%ADS_FORMAT_PROVIDER          = 10
%ADS_FORMAT_LEAF              = 11

' ========================================================================================
' ADS_DISPLAY_ENUM enum
' ========================================================================================

%ADS_DISPLAY_FULL       = 1
%ADS_DISPLAY_VALUE_ONLY = 2

' ========================================================================================
' ADS_ESCAPE_MODE_ENUM enum
' ========================================================================================

%ADS_ESCAPEDMODE_DEFAULT = 1
%ADS_ESCAPEDMODE_ON      = 2
%ADS_ESCAPEDMODE_OFF     = 3
%ADS_ESCAPEDMODE_OFF_EX  = 4

' ########################################################################################
' Interface name = IADsPathname
' IID = {D592AED4-F420-11D0-A36E-00C04FB950DC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsPathname_INTERFACE_DEFINED)
    %IADsPathname_INTERFACE_DEFINED = 1

INTERFACE IADsPathname $IID_IADsPathname

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Set <2> ( _                                   ' VTable offset = 28
     BYVAL bstrADsPath AS WSTRING _                     ' __in BSTR bstrADsPath
   , BYVAL lnSetType AS LONG _                          ' __in long lnSetType
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDisplayType <3> ( _                        ' VTable offset = 32
     BYVAL lnDisplayType AS LONG _                      ' __in long lnDisplayType
   )                                                    ' void
   ' =====================================================================================
   METHOD Retrieve <4> ( _                              ' VTable offset = 36
     BYVAL lnFormatType AS LONG _                       ' __in long lnFormatType
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrADsPath
   ' =====================================================================================
   METHOD GetNumElements <5> ( _                        ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plnNumPathElements
   ' =====================================================================================
   METHOD GetElement <6> ( _                            ' VTable offset = 44
     BYVAL lnElementIndex AS LONG _                     ' __in long lnElementIndex
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrElement
   ' =====================================================================================
   METHOD AddLeafElement <7> ( _                        ' VTable offset = 48
     BYVAL bstrLeafElement AS WSTRING _                 ' __in BSTR bstrLeafElement
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveLeafElement <8> ( _                     ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD CopyPath <9> ( _                              ' VTable offset = 56
   ) AS IDispatch                                       ' __retval_out IDispatch **ppAdsPath
   ' =====================================================================================
   METHOD GetEscapedElement <10> ( _                    ' VTable offset = 60
     BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   , BYVAL bstrInStr AS WSTRING _                       ' __in BSTR bstrInStr
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrOutStr
   ' =====================================================================================
   PROPERTY GET EscapedMode <11> ( _                    ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET EscapedMode <11> ( _                    ' VTable offset = 68
     BYVAL lnEscapedMode AS LONG _                      ' __in long lnEscapedMode
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsPathname_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsADSystemInfo
' IID = {5BB11929-AFD1-11D2-9CB9-0000F87A369E}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsADSystemInfo_INTERFACE_DEFINED)
    %IADsADSystemInfo_INTERFACE_DEFINED = 1

INTERFACE IADsADSystemInfo $IID_IADsADSystemInfo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET UserName <2> ( _                        ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ComputerName <3> ( _                    ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET SiteName <4> ( _                        ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET DomainShortName <5> ( _                 ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET DomainDNSName <6> ( _                   ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ForestDNSName <7> ( _                   ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET PDCRoleOwner <8> ( _                    ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET SchemaRoleOwner <9> ( _                 ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET IsNativeMode <10> ( _                   ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retval
   ' =====================================================================================
   METHOD GetAnyDCName <11> ( _                         ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pszDCName
   ' =====================================================================================
   METHOD GetDCSiteName <12> ( _                        ' VTable offset = 68
     BYVAL szServer AS WSTRING _                        ' __in BSTR szServer
   ) AS WSTRING                                         ' __retval_out BSTR *pszSiteName
   ' =====================================================================================
   METHOD RefreshSchemaCache <13> ( _                   ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTrees <14> ( _                             ' VTable offset = 76
   ) AS VARIANT                                         ' __retval_out VARIANT *pvTrees
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsADSystemInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsWinNTSystemInfo
' IID = {6C6D65DC-AFD1-11D2-9CB9-0000F87A369E}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsWinNTSystemInfo_INTERFACE_DEFINED)
    %IADsWinNTSystemInfo_INTERFACE_DEFINED = 1

INTERFACE IADsWinNTSystemInfo $IID_IADsWinNTSystemInfo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET UserName <2> ( _                        ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ComputerName <3> ( _                    ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET DomainName <4> ( _                      ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET PDC <5> ( _                             ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsWinNTSystemInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsDNWithBinary
' IID = {7E99C0A2-F935-11D2-BA96-00C04FB6D0D1}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsDNWithBinary_INTERFACE_DEFINED)
    %IADsDNWithBinary_INTERFACE_DEFINED = 1

INTERFACE IADsDNWithBinary $IID_IADsDNWithBinary

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET BinaryValue <2> ( _                     ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY SET BinaryValue <2> ( _                     ' VTable offset = 32
     BYVAL vBinaryValue AS VARIANT _                    ' __in VARIANT vBinaryValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DNString <3> ( _                        ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET DNString <3> ( _                        ' VTable offset = 40
     BYVAL bstrDNString AS WSTRING _                    ' __in BSTR bstrDNString
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsDNWithBinary_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IADsDNWithString
' IID = {370DF02E-F934-11D2-BA96-00C04FB6D0D1}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsDNWithString_INTERFACE_DEFINED)
    %IADsDNWithString_INTERFACE_DEFINED = 1

INTERFACE IADsDNWithString $IID_IADsDNWithString

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET StringValue <2> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET StringValue <2> ( _                     ' VTable offset = 32
     BYVAL bstrStringValue AS WSTRING _                 ' __in BSTR bstrStringValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DNString <3> ( _                        ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY SET DNString <3> ( _                        ' VTable offset = 40
     BYVAL bstrDNString AS WSTRING _                    ' __in BSTR bstrDNString
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsDNWithString_INTERFACE_DEFINED__ */

' ========================================================================================
' ADS_PATHTYPE_ENUM enum
' ========================================================================================

%ADS_PATH_FILE      = 1
%ADS_PATH_FILESHARE = 2
%ADS_PATH_REGISTRY  = 3

' ========================================================================================
' ADS_SD_FORMAT_ENUM enum
' ========================================================================================

%ADS_SD_FORMAT_IID       = 1
%ADS_SD_FORMAT_RAW       = 2
%ADS_SD_FORMAT_HEXSTRING = 3

' ########################################################################################
' Interface name = IADsSecurityUtility
' IID = {A63251B2-5F21-474B-AB52-4A8EFAD10895}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IADsSecurityUtility_INTERFACE_DEFINED)
    %IADsSecurityUtility_INTERFACE_DEFINED = 1

INTERFACE IADsSecurityUtility $IID_IADsSecurityUtility

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetSecurityDescriptor <2> ( _                 ' VTable offset = 28
     BYVAL varPath AS VARIANT _                         ' __in VARIANT varPath
   , BYVAL lPathFormat AS LONG _                        ' __in long lPathFormat
   , BYVAL lFormat AS LONG _                            ' __in long lFormat
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD SetSecurityDescriptor <3> ( _                 ' VTable offset = 32
     BYVAL varPath AS VARIANT _                         ' __in VARIANT varPath
   , BYVAL lPathFormat AS LONG _                        ' __in long lPathFormat
   , BYVAL varData AS VARIANT _                         ' __in VARIANT varData
   , BYVAL lDataFormat AS LONG _                        ' __in long lDataFormat
   )                                                    ' void
   ' =====================================================================================
   METHOD ConvertSecurityDescriptor <4> ( _             ' VTable offset = 36
     BYVAL varSD AS VARIANT _                           ' __in VARIANT varSD
   , BYVAL lDataFormat AS LONG _                        ' __in long lDataFormat
   , BYVAL lOutFormat AS LONG _                         ' __in long lOutFormat
   ) AS VARIANT                                         ' __retval_out VARIANT *pResult
   ' =====================================================================================
   PROPERTY GET SecurityMask <5> ( _                    ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *retval
   ' =====================================================================================
   PROPERTY SET SecurityMask <5> ( _                    ' VTable offset = 44
     BYVAL lnSecurityMask AS LONG _                     ' __in long lnSecurityMask
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IADsSecurityUtility_INTERFACE_DEFINED__ */
