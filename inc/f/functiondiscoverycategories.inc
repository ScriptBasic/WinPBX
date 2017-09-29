' ########################################################################################
' Microsoft Windows
' File: FunctionDiscoveryCategories.inc
' Contents: Master include file for DAO 3.6
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

'// *****************************************************************************
'// Important:  Anything added here should also be added to FunctionDiscoveryManagedKeys.inc
'// *****************************************************************************

#INCLUDE THIS ONCE
%FUNCTIONDISCOVERYCATEGORIES_INC = 1

$$FD_SUBKEY                            = "SOFTWARE\Microsoft\Function Discovery\"$$
$$FD_SUBKEY_CATEGORIES                 = $$FD_SUBKEY & "Categories\"$$

'// *****************************************************************************
'// Function Discovery Categories
'// *****************************************************************************
'// Important:  Anything added here should also be added to FunctionDiscoveryManagedKeys.h
'// *****************************************************************************

'// Provider Categories
'// Windows Vista
$$FCTN_CATEGORY_PNP                       = "Provider\Microsoft.Base.PnP"$$
$$FCTN_CATEGORY_REGISTRY                  = "Provider\Microsoft.Base.Registry"$$
$$FCTN_CATEGORY_SSDP                      = "Provider\Microsoft.Networking.SSDP"$$
$$FCTN_CATEGORY_WSDISCOVERY               = "Provider\Microsoft.Networking.WSD"$$
$$FCTN_CATEGORY_NETBIOS                   = "Provider\Microsoft.Networking.Netbios"$$
$$FCTN_CATEGORY_WCN                       = "Provider\Microsoft.Networking.WCN"$$
$$FCTN_CATEGORY_PUBLICATION               = "Provider\Microsoft.Base.Publication"$$
$$FCTN_CATEGORY_PNPXASSOCIATION           = "Provider\Microsoft.PnPX.Association"$$

'// Wireless Update Release
$$FCTN_CATEGORY_BT                        = "Provider\\Microsoft.Devices.Bluetooth"$$
$$FCTN_CATEGORY_WUSB                      = "Provider\\Microsoft.Devices.WirelessUSB"$$
$$FCTN_CATEGORY_DEVICEDISPLAYOBJECTS      = "Provider\\Microsoft.Base.DeviceDisplayObjects"$$

'// Layered Categories
'// Windows Vista
$$FCTN_CATEGORY_NETWORKDEVICES            = "Layered\\Microsoft.Networking.Devices"$$
$$FCTN_CATEGORY_DEVICES                   = "Layered\\Microsoft.Base.Devices"$$
$$FCTN_CATEGORY_DEVICEFUNCTIONENUMERATORS = "Layered\\Microsoft.Devices.FunctionEnumerators"$$
$$FCTN_CATEGORY_DEVICEPAIRING             = "Layered\\Microsoft.Base.DevicePairing"$$

'// *****************************************************************************
'// Function Discovery SubCategories
'// *****************************************************************************
'// Important:  Anything added here should also be added to FunctionDiscoveryManagedKeys.h
'// *****************************************************************************

'// Subcategories of Devices FCTN_CATEGORY_DEVICES
$$FCTN_SUBCAT_DEVICES_WSDPRINTERS      = "WSDPrinters"$$

'// Subcategories of Devices FCTN_CATEGORY_NETWORKDEVICES
$$FCTN_SUBCAT_NETWORKDEVICES_SSDP      = "SSDP"$$
$$FCTN_SUBCAT_NETWORKDEVICES_WSD       = "WSD"$$

'// Subcategories of Registry
$$FCTN_SUBCAT_REG_PUBLICATION          = "Publication"$$
$$FCTN_SUBCAT_REG_DIRECTED             = "Directed"$$

'// *****************************************************************************
'// Important:  Anything added here should also be added to FunctionDiscoveryManagedKeys.h
'// *****************************************************************************
