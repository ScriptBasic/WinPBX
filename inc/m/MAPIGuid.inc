' ########################################################################################
' Microsoft Windows
' File: MAPIGuid.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MAPIGUID_INC = 1

'/*
' *   M A P I G U I D . H
' *
' *   Master definitions of all GUID's for MAPI.
' *
' *   When included without INITGUID defined, this header file
' *   defines symbols that reference IIDs elsewhere.
' *
' *   When included with INITGUID defined and a "USES_IID_I..."
' *   statement for each IID used by the subsystem, it generates the
' *   bytes for those actual IIDs into the associated object file.
' *
' *   This range of 256 GUIDs reserved by OLE for MAPI use October 5, 1992.
' *
' *  Copyright 1986-1999 Microsoft Corporation. All Rights Reserved.
' */

'/*
' *   List of GUIDS allocated by MAPI
' *
' *   0x00020300   IID_IMAPISession
' *   0x00020301   IID_IMAPITable
' *   0x00020302   IID_IMAPIAdviseSink
' *   0x00020303   IID_IMAPIProp
' *   0x00020304   IID_IProfSect
' *   0x00020305   IID_IMAPIStatus
' *   0x00020306   IID_IMsgStore
' *   0x00020307   IID_IMessage
' *   0x00020308   IID_IAttachment
' *   0x00020309   IID_IAddrBook
' *   0x0002030A   IID_IMailUser
' *   0x0002030B   IID_IMAPIContainer
' *   0x0002030C   IID_IMAPIFolder
' *   0x0002030D   IID_IABContainer
' *   0x0002030E   IID_IDistList
' *   0x0002030F   IID_IMAPISup
' *   0x00020310   IID_IMSProvider
' *   0x00020311   IID_IABProvider
' *   0x00020312   IID_IXPProvider
' *   0x00020313   IID_IMSLogon
' *   0x00020314   IID_IABLogon
' *   0x00020315   IID_IXPLogon
' *   0x00020316   IID_IMAPITableData
' *   0x00020317   IID_IMAPISpoolerInit
' *   0x00020318   IID_IMAPISpoolerSession
' *   0x00020319   IID_ITNEF
' *   0x0002031A   IID_IMAPIPropData
' *   0x0002031B   IID_IMAPIControl
' *   0x0002031C   IID_IProfAdmin
' *   0x0002031D   IID_IMsgServiceAdmin
' *   0x0002031E   IID_IMAPISpoolerService
' *   0x0002031F   IID_IMAPIProgress
' *   0x00020320   IID_ISpoolerHook
' *   0x00020321   IID_IMAPIViewContext
' *   0x00020322   IID_IMAPIFormMgr
' *   0x00020323   IID_IEnumMAPIFormProp
' *   0x00020324   IID_IMAPIFormInfo
' *   0x00020325   IID_IProviderAdmin
' *   0x00020327   IID_IMAPIForm
' *   0x00020328   PS_MAPI
' *   0x00020329   PS_PUBLIC_STRINGS
' *   0x0002032A   IID_IPersistMessage
' *   0x0002032B   IID_IMAPIViewAdviseSink
' *   0x0002032C   IID_IStreamDocfile
' *   0x0002032D   IID_IMAPIFormProp
' *   0x0002032E   IID_IMAPIFormContainer
' *   0x0002032F   IID_IMAPIFormAdviseSink
' *   0x00020330   IID_IStreamTnef
' *   0x00020350   IID_IMAPIFormFactory
' *   0x00020370   IID_IMAPIMessageSite
' *   0x00020380   PS_ROUTING_EMAIL_ADDRESSES
' *   0x00020381   PS_ROUTING_ADDRTYPE
' *   0x00020382   PS_ROUTING_DISPLAY_NAME
' *   0x00020383   PS_ROUTING_ENTRYID
' *   0x00020384   PS_ROUTING_SEARCH_KEY
' *   0x00020385   MUID_PROFILE_INSTANCE
' *
' *   The remaining GUIDs from 0x00020300 to 0x000203FF are reserved by
' *   MAPI for future use.  The current maximum used by MAPI is 0x00020385
' *
' */

'/* Derive from IUnknown */
$IID_IMAPISession           = GUID$("{00020300-0000-0000-C000-000000000046}")
$IID_IMAPITable             = GUID$("{00020301-0000-0000-C000-000000000046}")
$IID_IMAPIAdviseSink        = GUID$("{00020302-0000-0000-C000-000000000046}")
$IID_IMAPIControl           = GUID$("{0002031B-0000-0000-C000-000000000046}")
$IID_IProfAdmin             = GUID$("{0002031C-0000-0000-C000-000000000046}")
$IID_IMsgServiceAdmin       = GUID$("{0002031D-0000-0000-C000-000000000046}")
$IID_IProviderAdmin         = GUID$("{00020325-0000-0000-C000-000000000046}")
$IID_IMAPIProgress          = GUID$("{0002031F-0000-0000-C000-000000000046}")

'/* MAPIProp or derive from MAPIProp */
$IID_IMAPIProp              = GUID$("{00020303-0000-0000-C000-000000000046}")
$IID_IProfSect              = GUID$("{00020304-0000-0000-C000-000000000046}")
$IID_IMAPIStatus            = GUID$("{00020305-0000-0000-C000-000000000046}")
$IID_IMsgStore              = GUID$("{00020306-0000-0000-C000-000000000046}")
$IID_IMessage               = GUID$("{00020307-0000-0000-C000-000000000046}")
' Defined as IAttachment in MAPIX and as IAttach in MIMEDIR
$IID_IAttachment            = GUID$("{00020308-0000-0000-C000-000000000046}")
$IID_IAttach                = GUID$("{00020308-0000-0000-C000-000000000046}")
$IID_IAddrBook              = GUID$("{00020309-0000-0000-C000-000000000046}")
$IID_IMailUser              = GUID$("{0002030A-0000-0000-C000-000000000046}")

'/* MAPIContainer or derive from MAPIContainer */
$IID_IMAPIContainer         = GUID$("{0002030B-0000-0000-C000-000000000046}")
$IID_IMAPIFolder            = GUID$("{0002030C-0000-0000-C000-000000000046}")
$IID_IABContainer           = GUID$("{0002030D-0000-0000-C000-000000000046}")
$IID_IDistList              = GUID$("{0002030E-0000-0000-C000-000000000046}")

'/* MAPI Support Object */
' Defined as IMAPISup in MAPIX and as IMAPISupport in MIMEDIR
$IID_IMAPISup               = GUID$("{0002030F-0000-0000-C000-000000000046}")
$IID_IMAPISupport           = GUID$("{0002030F-0000-0000-C000-000000000046}")

'/* Provider INIT objects */
$IID_IMSProvider            = GUID$("{00020310-0000-0000-C000-000000000046}")
$IID_IABProvider            = GUID$("{00020311-0000-0000-C000-000000000046}")
$IID_IXPProvider            = GUID$("{00020312-0000-0000-C000-000000000046}")

'/* Provider LOGON Objects */
$IID_IMSLogon               = GUID$("{00020313-0000-0000-C000-000000000046}")
$IID_IABLogon               = GUID$("{00020314-0000-0000-C000-000000000046}")
$IID_IXPLogon               = GUID$("{00020315-0000-0000-C000-000000000046}")

'/* IMAPITable-in-memory Table Data Object */
' Defined as IMAPITableData in MAPIX and as ITableData in MIMEDIR
$IID_IMAPITableData         = GUID$("{00020316-0000-0000-C000-000000000046}")
$IID_ITableData             = GUID$("{00020316-0000-0000-C000-000000000046}")

'/* MAPI Spooler Init Object (internal) */
$IID_IMAPISpoolerInit       = GUID$("{00020317-0000-0000-C000-000000000046}")

'/* MAPI Spooler Session Object (internal) */
$IID_IMAPISpoolerSession    = GUID$("{00020318-0000-0000-C000-000000000046}")

'/* MAPI TNEF Object Interface */
$IID_ITNEF                  = GUID$("{00020319-0000-0000-C000-000000000046}")

'/* IMAPIProp-in-memory Property Data Object */
' Defined as IMAPIPropData in MAPIX and as IPropData in MIMEDIR
$IID_IMAPIPropData          = GUID$("{0002031A-0000-0000-C000-000000000046}")
$IID_IPropData              = GUID$("{0002031A-0000-0000-C000-000000000046}")

'/* MAPI Spooler Hook Object */
$IID_ISpoolerHook           = GUID$("{00020320-0000-0000-C000-000000000046}")

'/* MAPI Spooler Service Object */
$IID_IMAPISpoolerService    = GUID$("{0002031E-0000-0000-C000-000000000046}")

'/* MAPI forms, form manager, etc. */
$IID_IMAPIViewContext       = GUID$("{00020321-0000-0000-C000-000000000046}")
$IID_IMAPIFormMgr           = GUID$("{00020322-0000-0000-C000-000000000046}")
$IID_IEnumMAPIFormProp      = GUID$("{00020323-0000-0000-C000-000000000046}")
$IID_IMAPIFormInfo          = GUID$("{00020324-0000-0000-C000-000000000046}")
$IID_IMAPIForm              = GUID$("{00020327-0000-0000-C000-000000000046}")

'/* Well known guids for name<->id mappings */

'/*  The name of MAPI's property set  */
$PS_MAPI                    = GUID$("{00020328-0000-0000-C000-000000000046}")

'/*  The name of the set of public strings  */
$PS_PUBLIC_STRINGS          = GUID$("{00020329-0000-0000-C000-000000000046}")

'/* MAPI forms, form manager, (cont) */
$IID_IPersistMessage        = GUID$("{0002032A-0000-0000-C000-000000000046}")

'/* IMAPIViewAdviseSink */
$IID_IMAPIViewAdviseSink    = GUID$("{0002032B-0000-0000-C000-000000000046}")

'/* Message Store OpenProperty */
$IID_IStreamDocfile         = GUID$("{0002032C-0000-0000-C000-000000000046}")

'/* IMAPIFormProp */
$IID_IMAPIFormProp          = GUID$("{0002032D-0000-0000-C000-000000000046}")

'/* IMAPIFormContainer */
$IID_IMAPIFormContainer     = GUID$("{0002032E-0000-0000-C000-000000000046}")

'/* IMAPIFormAdviseSink */
$IID_IMAPIFormAdviseSink    = GUID$("{0002032F-0000-0000-C000-000000000046}")

'/* TNEF OpenProperty */
$IID_IStreamTnef            = GUID$("{00020330-0000-0000-C000-000000000046}")

'/* IMAPIFormFactory */
$IID_IMAPIFormFactory       = GUID$("{00020350-0000-0000-C000-000000000046}")

'/* IMAPIMessageSite */
$IID_IMAPIMessageSite       = GUID$("{00020370-0000-0000-C000-000000000046}")


'/* Well known guids routing property sets.
'   Usefull when writing applications that route documents
'   (i.e. Workflow) across gateways.  Gateways that speak MAPI
'   should convert the properties found in the follow property
'   sets appropriately. */

'/*  PS_ROUTING_EMAIL_ADDRESSES:  Addresses that need converting at gateways, etc. */
$PS_ROUTING_EMAIL_ADDRESSES = GUID$("{00020380-0000-0000-C000-000000000046}")

'/*  PS_ROUTING_ADDRTYPE:  Address types that need converting at gateways, etc. */
$PS_ROUTING_ADDRTYPE        = GUID$("{00020381-0000-0000-C000-000000000046}")

'/*  PS_ROUTING_DISPLAY_NAME:  Display Name that corresponds to the other props */
$PS_ROUTING_DISPLAY_NAME    = GUID$("{00020382-0000-0000-C000-000000000046}")

'/*  PS_ROUTING_ENTRYID:  (optional) EntryIDs that need converting at gateways, etc. */
$PS_ROUTING_ENTRYID         = GUID$("{00020383-0000-0000-C000-000000000046}")

'/*  PS_ROUTING_SEARCH_KEY:  (optional) search keys that need converting at gateways, etc. */
$PS_ROUTING_SEARCH_KEY      = GUID$("{00020384-0000-0000-C000-000000000046}")

'/*   MUID_PROFILE_INSTANCE
'   Well known section in a profile which contains a property (PR_SEARCH_KEY) which is unique
'   for any given profile.  Applications and providers can depend on this value as being
'   different for each unique profile. */
$MUID_PROFILE_INSTANCE      = GUID$("{00020385-0000-0000-C000-000000000046}")

$pbGlobalProfileSectionGuid = GUID$("{13DBB0C8-AA05-101A-9BB0-00AA002FC45A}")
