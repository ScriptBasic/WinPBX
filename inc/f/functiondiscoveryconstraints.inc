' ########################################################################################
' Microsoft Windows
' File: FunctionDiscoveryConstraints.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

'///////////////////////////////////////////////////////////////////////////////
'// QUERY Constraint defines
'///////////////////////////////////////////////////////////////////////////////

#INCLUDE THIS ONCE
%FUNCTIONDISCOVERYCONSTRAINTS_INC = 1

%MAX_FDCONSTRAINTNAME_LENGTH                    = 100
%MAX_FDCONSTRAINTVALUE_LENGTH                   = 1000

'// Common Provider specific Constraints
$$FD_QUERYCONSTRAINT_PROVIDERINSTANCEID           = "ProviderInstanceID"$$
$$FD_QUERYCONSTRAINT_SUBCATEGORY                  = "Subcategory"$$
$$FD_QUERYCONSTRAINT_RECURSESUBCATEGORY           = "RecurseSubcategory"$$
$$FD_QUERYCONSTRAINT_VISIBILITY                   = "Visibility"$$
'    // FD_CONSTRAINTVALUE_VISIBILITY_DEFAULT you want just default instances (visible as defined by the provider)
'    // FD_CONSTRAINTVALUE_VISIBILITY_ALL (default) you want both visible and not visible/hidden instances (as defined by the provider)
$$FD_QUERYCONSTRAINT_COMCLSCONTEXT                = "COMClsContext"$$
$$FD_QUERYCONSTRAINT_ROUTINGSCOPE                 = "RoutingScope"$$

'// Common Provider specific Constraints values
$$FD_CONSTRAINTVALUE_TRUE                         = "TRUE"$$
$$FD_CONSTRAINTVALUE_FALSE                        = "FALSE"$$
$$FD_CONSTRAINTVALUE_RECURSESUBCATEGORY_TRUE      = $$FD_CONSTRAINTVALUE_TRUE
$$FD_CONSTRAINTVALUE_VISIBILITY_DEFAULT           = "0"$$
$$FD_CONSTRAINTVALUE_VISIBILITY_ALL               = "1"$$
$$FD_CONSTRAINTVALUE_COMCLSCONTEXT_INPROC_SERVER  = "1"$$
$$FD_CONSTRAINTVALUE_COMCLSCONTEXT_LOCAL_SERVER   = "4"$$

$$FD_CONSTRAINTVALUE_PAIRED                       = "Paired"$$
$$FD_CONSTRAINTVALUE_UNPAIRED                     = "UnPaired"$$
$$FD_CONSTRAINTVALUE_ALL                          = "All"$$

$$FD_CONSTRAINTVALUE_ROUTINGSCOPE_ALL             = "All"$$
$$FD_CONSTRAINTVALUE_ROUTINGSCOPE_DIRECT          = "Direct"$$

'///////////////////////////////////////////////////////////////////////////////
'// Provider inquiry constraints
$$FD_QUERYCONSTRAINT_PAIRING_STATE                = "PairingState"$$
'    // if unset, provider default is FD_CONSTRAINTVALUE_PAIRED
'    // FD_CONSTRAINTVALUE_PAIRED will return all paired devices
'    // FD_CONSTRAINTVALUE_UNPAIRED will return all unpaired devices within wireless or wired range
'    // FD_CONSTRAINTVALUE_ALL will return all devices cached and within wireless or wired range
$$FD_QUERYCONSTRAINT_INQUIRY_TIMEOUT              = "InquiryModeTimeout"$$   ' // #seconds 6-600 supported, default is 300

'///////////////////////////////////////////////////////////////////////////////
'// PNP Provider specific Constraints
$$PROVIDERPNP_QUERYCONSTRAINT_INTERFACECLASS      = "InterfaceClass"$$
$$PROVIDERPNP_QUERYCONSTRAINT_NOTPRESENT          = "NotPresent"$$
$$PROVIDERPNP_QUERYCONSTRAINT_NOTIFICATIONSONLY   = "NotifyOnly"$$
'    // PNP_CONSTRAINTVALUE_NOTPRESENT you want "not present" instances as well
'    // "FALSE" (default) you want only DIGCF_PRESENT instances.
'// PNP Provider specific Constraints values
$$PNP_CONSTRAINTVALUE_NOTPRESENT                  = $$FD_CONSTRAINTVALUE_TRUE
$$PNP_CONSTRAINTVALUE_NOTIFICATIONSONLY           = $$FD_CONSTRAINTVALUE_TRUE

'///////////////////////////////////////////////////////////////////////////////
'// SSDP Provider specific Constraints
$$PROVIDERSSDP_QUERYCONSTRAINT_TYPE               = "Type"$$
$$PROVIDERSSDP_QUERYCONSTRAINT_CUSTOMXMLPROPERTY  = "CustomXmlProperty"$$

'// SSDP Provider specific Constraints values
$$SSDP_CONSTRAINTVALUE_TYPE_ALL                   = "ssdp:all"$$
$$SSDP_CONSTRAINTVALUE_TYPE_ROOT                  = "upnp:rootdevice"$$
$$SSDP_CONSTRAINTVALUE_TYPE_DEVICE_PREFIX         = "urn:schemas-upnp-org:device:"$$
$$SSDP_CONSTRAINTVALUE_TYPE_SVC_PREFIX            = "urn:schemas-upnp-org:service:"$$

$$SSDP_CONSTRAINTVALUE_TYPE_DEV_LIGHTING          = $$SSDP_CONSTRAINTVALUE_TYPE_DEVICE_PREFIX & "Lighting:1"$$
$$SSDP_CONSTRAINTVALUE_TYPE_DEV_REMINDER          = $$SSDP_CONSTRAINTVALUE_TYPE_DEVICE_PREFIX & "Reminder:1"$$
$$SSDP_CONSTRAINTVALUE_TYPE_DEV_POWERDEVICE       = $$SSDP_CONSTRAINTVALUE_TYPE_DEVICE_PREFIX & "PowerDevice:1"$$
$$SSDP_CONSTRAINTVALUE_TYPE_DEV_IGD               = $$SSDP_CONSTRAINTVALUE_TYPE_DEVICE_PREFIX & "InternetGatewayDevice:1"$$
$$SSDP_CONSTRAINTVALUE_TYPE_DEV_WANDEVICE         = $$SSDP_CONSTRAINTVALUE_TYPE_DEVICE_PREFIX & "WANDevice:1"$$
$$SSDP_CONSTRAINTVALUE_TYPE_DEV_LANDEVICE         = $$SSDP_CONSTRAINTVALUE_TYPE_DEVICE_PREFIX & "LANDevice:1"$$
$$SSDP_CONSTRAINTVALUE_TYPE_DEV_WANCONNDEVICE     = $$SSDP_CONSTRAINTVALUE_TYPE_DEVICE_PREFIX & "WANConnectionDevice:1"$$
$$SSDP_CONSTRAINTVALUE_TYPE_DEV_LUXMETER          = $$SSDP_CONSTRAINTVALUE_TYPE_DEVICE_PREFIX & "Luxmeter:1"$$
$$SSDP_CONSTRAINTVALUE_TYPE_DEV_MDARNDR           = $$SSDP_CONSTRAINTVALUE_TYPE_DEVICE_PREFIX & "MediaRenderer:1"$$
$$SSDP_CONSTRAINTVALUE_TYPE_DEV_MDASRVR           = $$SSDP_CONSTRAINTVALUE_TYPE_DEVICE_PREFIX & "MediaServer:1"$$

$$SSDP_CONSTRAINTVALUE_TYPE_SVC_SCANNER           = $$SSDP_CONSTRAINTVALUE_TYPE_SVC_PREFIX & "Scanner:1"$$
$$SSDP_CONSTRAINTVALUE_TYPE_SVC_DIMMING           = $$SSDP_CONSTRAINTVALUE_TYPE_SVC_PREFIX & "DimmingService:1"$$

'///////////////////////////////////////////////////////////////////////////////
'// WSD Provider specific Constraints
$$PROVIDERWSD_QUERYCONSTRAINT_DIRECTEDADDRESS          = "RemoteAddress"$$
$$PROVIDERWSD_QUERYCONSTRAINT_TYPE                     = "Type"$$
$$PROVIDERWSD_QUERYCONSTRAINT_SCOPE                    = "Scope"$$
$$PROVIDERWSD_QUERYCONSTRAINT_SECURITY_REQUIREMENTS    = "SecurityRequirements"$$
$$PROVIDERWSD_QUERYCONSTRAINT_SSL_CERT_FOR_CLIENT_AUTH = "SSLClientAuthCert"$$

'// WSD provider specific Constraint values
$$WSD_CONSTRAINTVALUE_REQUIRE_SECURECHANNEL                      = "1"$$
$$WSD_CONSTRAINTVALUE_REQUIRE_SECURECHANNEL_AND_COMPACTSIGNATURE = "2"$$
$$WSD_CONSTRAINTVALUE_NO_TRUST_VERIFICATION                      = "3"$$

'///////////////////////////////////////////////////////////////////////////////
'// NetBios Provider specific Constraints
$$PROVIDERWNET_QUERYCONSTRAINT_TYPE               = "Type"$$
$$PROVIDERWNET_QUERYCONSTRAINT_PROPERTIES         = "Properties"$$
$$PROVIDERWNET_QUERYCONSTRAINT_RESOURCETYPE       = "ResourceType"$$

$$PROVIDERWNET_QUERYCONSTRAINT_TYPE               = "Type"$$
$$PROVIDERWNET_QUERYCONSTRAINT_PROPERTIES         = "Properties"$$
$$PROVIDERWNET_QUERYCONSTRAINT_RESOURCETYPE       = "ResourceType"$$

$$WNET_CONSTRAINTVALUE_PROPERTIES_ALL             = "All"$$
$$WNET_CONSTRAINTVALUE_PROPERTIES_LIMITED         = "Limited"$$  ' // Default

$$WNET_CONSTRAINTVALUE_RESOURCETYPE_DISK          = "Disk"$$            ' // All non-printer shares (dwDisplayType == RESOURCEDISPLAYTYPE_SHARE and dwType != RESOURCETYPE_PRINT)
$$WNET_CONSTRAINTVALUE_RESOURCETYPE_PRINTER       = "Printer"$$         ' // All printer shares (dwDisplayType == RESOURCEDISPLAYTYPE_SHARE and dwType == RESOURCETYPE_PRINT)
$$WNET_CONSTRAINTVALUE_RESOURCETYPE_DISKORPRINTER = "DiskOrPrinter"$$   ' // All shares (dwDisplayType == RESOURCEDISPLAYTYPE_SHARE)

$$ONLINE_PROVIDER_DEVICES_QUERYCONSTRAINT_OWNERNAME = "OwnerName"$$

'///////////////////////////////////////////////////////////////////////////////
'// Device Display Object Provider specific Constraints
$$PROVIDERDDO_QUERYCONSTRAINT_DEVICEFUNCTIONDISPLAYOBJECTS = "DeviceFunctionDisplayObjects"$$
$$PROVIDERDDO_QUERYCONSTRAINT_ONLYCONNECTEDDEVICES         = "OnlyConnectedDevices"$$
$$PROVIDERDDO_QUERYCONSTRAINT_DEVICEINTERFACES             = "DeviceInterfaces"$$

'///////////////////////////////////////////////////////////////////////////////
'// PROPERTY Constraint defines
'///////////////////////////////////////////////////////////////////////////////

#IF NOT %DEF(%FDPropertyConstraint)
%FDPropertyConstraint = 1
' enum PropertyConstraint alias tagQueryUpdateAction
%QC_EQUALS             = 0
%QC_NOTEQUAL           = 1
%QC_LESSTHAN           = 2
%QC_LESSTHANOREQUAL    = 3
%QC_GREATERTHAN        = 4
%QC_GREATERTHANOREQUAL = 5
%QC_STARTSWITH         = 6   ' // Strings only
%QC_EXISTS             = 7
%QC_DOESNOTEXIST       = 8
%QC_CONTAINS           = 9   ' // Strings and VT_VECTOR only
#ENDIF
