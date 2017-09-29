' ########################################################################################
' Microsoft Windows
' File: CGuid.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CGUID_INC = 1

$GUID_NULL = GUID$("{00000000-0000-0000-0000-000000000000}")
$CATID_MARSHALER = GUID$("{00000003-0000-0000-C000-000000000046}")
$IID_IRpcChannel = GUID$("{00000004-0000-0000-C000-000000000046}")
$IID_IRpcStub = GUID$("{00000005-0000-0000-C000-000000000046}")
$IID_IStubManager = GUID$("{00000006-0000-0000-C000-000000000046}")
$IID_IRpcProxy = GUID$("{00000007-0000-0000-C000-000000000046}")
$IID_IProxyManager = GUID$("{00000008-0000-0000-C000-000000000046}")
$IID_IPSFactory = GUID$("{00000009-0000-0000-C000-000000000046}")
$IID_IInternalMoniker = GUID$("{00000011-0000-0000-C000-000000000046}")
$IID_IDfReserved1 = GUID$("{00000013-0000-0000-C000-000000000046}")
$IID_IDfReserved2 = GUID$("{00000014-0000-0000-C000-000000000046}")
$IID_IDfReserved3 = GUID$("{00000015-0000-0000-C000-000000000046}")
$CLSID_StdMarshal = GUID$("{00000017-0000-0000-C000-000000000046}")
'extern const CLSID CLSID_AggStdMarshal;
$CLSID_StdAsyncActManager = GUID$("{00000329-0000-0000-C000-000000000046}")
$IID_IStub = GUID$("{00000026-0000-0000-C000-000000000046}")
$IID_IProxy = GUID$("{00000027-0000-0000-C000-000000000046}")
$IID_IEnumGeneric = GUID$("{00000106-0000-0000-C000-000000000046}")
$IID_IEnumHolder = GUID$("{00000107-0000-0000-C000-000000000046}")
$IID_IEnumCallback = GUID$("{00000108-0000-0000-C000-000000000046}")
$IID_IOleManager = GUID$("{0000011F-0000-0000-C000-000000000046}")
$IID_IOlePresObj = GUID$("{00000120-0000-0000-C000-000000000046}")
$IID_IDebug = GUID$("{00000123-0000-0000-C000-000000000046}")
$IID_IDebugStream = GUID$("{00000124-0000-0000-C000-000000000046}")
$CLSID_PSGenObject = GUID$("{0000030C-0000-0000-C000-000000000046}")
$CLSID_PSClientSite = GUID$("{0000030D-0000-0000-C000-000000000046}")
$CLSID_PSClassObject = GUID$("{0000030E-0000-0000-C000-000000000046}")
$CLSID_PSInPlaceActive = GUID$("{0000030F-0000-0000-C000-000000000046}")
$CLSID_PSInPlaceFrame = GUID$("{00000310-0000-0000-C000-000000000046}")
$CLSID_PSDragDrop = GUID$("{00000311-0000-0000-C000-000000000046}")
$CLSID_PSBindCtx = GUID$("{00000312-0000-0000-C000-000000000046}")
$CLSID_PSEnumerators = GUID$("{00000313-0000-0000-C000-000000000046}")
$CLSID_StaticMetafile = GUID$("{00000315-0000-0000-C000-000000000046}")
$CLSID_StaticDib = GUID$("{00000316-0000-0000-C000-000000000046}")
'extern const CLSID CID_CDfsVolume;
$CLSID_DCOMAccessControl = GUID$("{0000031D-0000-0000-C000-000000000046}")
$CLSID_StdGlobalInterfaceTable = GUID$("{00000323-0000-0000-C000-000000000046}")
$CLSID_ComBinding = GUID$("{00000328-0000-0000-C000-000000000046}")
$CLSID_StdEvent = GUID$("{0000032B-0000-0000-C000-000000000046}")
$CLSID_ManualResetEvent = GUID$("{0000032C-0000-0000-C000-000000000046}")
$CLSID_SynchronizeContainer = GUID$("{0000032D-0000-0000-C000-000000000046}")
$CLSID_AddrControl = GUID$("{00000348-0000-0000-C000-000000000046}")

'//********************************************
'//
'// CD Forms CLSIDs
'//
'//********************************************

'//
'// Form Kernel objects
'//
'extern const CLSID CLSID_CCDFormKrnl;
'extern const CLSID CLSID_CCDPropertyPage;
'extern const CLSID CLSID_CCDFormDialog;

'//
'// Control objects
'//
'extern const CLSID CLSID_CCDCommandButton;
'extern const CLSID CLSID_CCDComboBox;
'extern const CLSID CLSID_CCDTextBox;
'extern const CLSID CLSID_CCDCheckBox;
'extern const CLSID CLSID_CCDLabel;
'extern const CLSID CLSID_CCDOptionButton;
'extern const CLSID CLSID_CCDListBox;
'extern const CLSID CLSID_CCDScrollBar;
'extern const CLSID CLSID_CCDGroupBox;

'//
'// Property Pages
'//
'extern const CLSID CLSID_CCDGeneralPropertyPage;
'extern const CLSID CLSID_CCDGenericPropertyPage;
'extern const CLSID CLSID_CCDFontPropertyPage;
'extern const CLSID CLSID_CCDColorPropertyPage;
'extern const CLSID CLSID_CCDLabelPropertyPage;
'extern const CLSID CLSID_CCDCheckBoxPropertyPage;
'extern const CLSID CLSID_CCDTextBoxPropertyPage;
'extern const CLSID CLSID_CCDOptionButtonPropertyPage;
'extern const CLSID CLSID_CCDListBoxPropertyPage;
'extern const CLSID CLSID_CCDCommandButtonPropertyPage;
'extern const CLSID CLSID_CCDComboBoxPropertyPage;
'extern const CLSID CLSID_CCDScrollBarPropertyPage;
'extern const CLSID CLSID_CCDGroupBoxPropertyPage;
'extern const CLSID CLSID_CCDXObjectPropertyPage;

'extern const CLSID CLSID_CStdPropertyFrame;

'extern const CLSID CLSID_CFormPropertyPage;
'extern const CLSID CLSID_CGridPropertyPage;

'extern const CLSID CLSID_CWSJArticlePage;
'extern const CLSID CLSID_CSystemPage;

'extern const CLSID CLSID_IdentityUnmarshal;
$CLSID_IdentityUnmarshal = GUID$("{0000001B-0000-0000-C000-000000000046}")
'extern const CLSID CLSID_InProcFreeMarshaler;
$CLSID_InProcFreeMarshaler = GUID$("{0000001C-0000-0000-C000-000000000046}")

'extern const CLSID CLSID_Picture_Metafile;
$CLSID_Picture_Metafile = GUID$("{00000315-0000-0000-C000-000000000046}")
'extern const CLSID CLSID_Picture_EnhMetafile;
$CLSID_Picture_EnhMetafile = GUID$("{00000319-0000-0000-C000-000000000046}")
'extern const CLSID CLSID_Picture_Dib;
$CLSID_Picture_Dib = GUID$("{00000316-0000-0000-C000-000000000046}")

'//
'// Enumerations
'//
'extern const GUID GUID_TRISTATE;
$GUID_TRISTATE = GUID$("{6650430A-BE0F-101A-8BBB-00AA00300CAB}")
