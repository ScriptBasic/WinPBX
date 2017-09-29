' ########################################################################################
' Microsoft Windows
' File: ADSIid.inc
' Contents: Extern references for ADs guids
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ADSIID_INC = 1

'// uuids from oledsiid.lib

$LIBID_ADs                     = GUID$("{97D25DB0-0363-11CF-ABC4-02608C9E7553}")
$IID_IADs                      = GUID$("{FD8256D0-FD15-11CE-ABC4-02608C9E7553}")
$IID_IADsContainer             = GUID$("{001677D0-FD16-11CE-ABC4-02608C9E7553}")
$IID_IADsNamespaces            = GUID$("{28B96BA0-B330-11CF-A9AD-00AA006BC149}")
$IID_IADsDomain                = GUID$("{00E4C220-FD16-11CE-ABC4-02608C9E7553}")
$IID_IADsUser                  = GUID$("{3E37E320-17E2-11CF-ABC4-02608C9E7553}")
$IID_IADsComputerOperations    = GUID$("{EF497680-1D9F-11CF-B1F3-02608C9E7553}")
$IID_IADsComputer              = GUID$("{EFE3CC70-1D9F-11CF-B1F3-02608C9E7553}")
$IID_IADsGroup                 = GUID$("{27636B00-410F-11CF-B1FF-02608C9E7553}")
$IID_IADsMembers               = GUID$("{451A0030-72EC-11CF-B03B-00AA006E0975}")
$IID_IADsPrintQueue            = GUID$("{B15160D0-1226-11CF-A985-00AA006BC149}")
$IID_IADsPrintQueueOperations  = GUID$("{124BE5C0-156E-11CF-A986-00AA006BC149}")
$IID_IADsPrintJobOperations    = GUID$("{9A52DB30-1ECF-11CF-A988-00AA006BC149}")
$IID_IADsPrintJob              = GUID$("{32FB6780-1ED0-11CF-A988-00AA006BC149}")
$IID_IADsCollection            = GUID$("{72B945E0-253B-11CF-A988-00AA006BC149}")
$IID_IADsServiceOperations     = GUID$("{5D7B33F0-31CA-11CF-A98A-00AA006BC149}")
$IID_IADsService               = GUID$("{68AF66E0-31CA-11CF-A98A-00AA006BC149}")
$IID_IADsFileServiceOperations = GUID$("{A02DED10-31CA-11CF-A98A-00AA006BC149}")
$IID_IADsFileService           = GUID$("{A89D1900-31CA-11CF-A98A-00AA006BC149}")
$IID_IADsResource              = GUID$("{34A05B20-4AAB-11CF-AE2C-00AA006EBFB9}")
$IID_IADsSession               = GUID$("{398B7DA0-4AAB-11CF-AE2C-00AA006EBFB9}")
$IID_IADsFileShare             = GUID$("{EB6DCAF0-4B83-11CF-A995-00AA006BC149}")
'extern const GUID IID_IADsSchema;
$IID_IADsClass                 = GUID$("{C8F93DD0-4AE0-11CF-9E73-00AA004A5691}")
$IID_IADsProperty              = GUID$("{C8F93DD3-4AE0-11CF-9E73-00AA004A5691}")
$IID_IADsSyntax                = GUID$("{C8F93DD2-4AE0-11CF-9E73-00AA004A5691}")
$IID_IADsLocality              = GUID$("{A05E03A2-EFFE-11CF-8ABC-00C04FD8D503}")
$IID_IADsO                     = GUID$("{A1CD2DC6-EFFE-11CF-8ABC-00C04FD8D503}")
$IID_IADsOU                    = GUID$("{A2F733B8-EFFE-11CF-8ABC-00C04FD8D503}")
$IID_IADsOpenDSObject          = GUID$("{DDF2891E-0F9C-11D0-8AD4-00C04FD8D503}")
'extern const GUID IID_IADsSearch;
$IID_IADsPropertyList          = GUID$("{C6F602B6-8F69-11D0-8528-00C04FD8D503}")
'extern const GUID IID_IDSObject;
'extern const GUID IID_IDSSearch;
'extern const GUID IID_IDSAttrMgmt;
$IID_IDirectorySearch          = GUID$("{109BA8EC-92F0-11D0-A790-00C04FD8D5A8}")
$IID_IDirectoryObject          = GUID$("{E798DE2C-22E4-11D0-84FE-00C04FD8D503}")
'extern const GUID IID_IDirectoryAttrMgmt;


'//
'// Connection object GUIDs.
'//
$CLSID_LDAPConnectionObject    = GUID$("{7DA2A9C4-0C46-43BD-B04E-D92B1BE27C45}")

'//
'// CLSID for owning LDAP objects interfaces
'//
$CLSID_LDAPObject              = GUID$("{05709878-5195-466C-9E64-487CE3CA20BF}")


'//
'// Query object for the LDAP Provider.
'//
$CLSID_UmiLDAPQueryObject      = GUID$("{CD5D4D76-A818-4F95-B958-7970FD9412CA}")
$CLSID_WinNTConnectionObject   = GUID$("{7992C6EB-D142-4332-831E-3154C50A8316}")

'// Custom interface handling
$CLSID_WinNTObject             = GUID$("{B8324185-4050-4220-980A-AB14623E063A}")

'//
'// OLE DB Provider Guids
'//

$CLSID_ADsDSOObject            = GUID$("{549365D0-EC26-11CF-8310-00AA00B505DB}")
$DBGUID_LDAPDialect            = GUID$("{EFF65380-9C98-11CF-B963-00AA0044773D}")
$DBPROPSET_ADSISEARCH          = GUID$("{CFCFC928-9AA2-11D0-A79A-00C04FD8D5A8}")
$DBPROPSET_ADSIBIND            = GUID$("{6DA66DC8-B7E8-11D2-9D60-00C04F689345}")
