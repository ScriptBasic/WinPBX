' ########################################################################################
' Microsoft Windows
' File: TCError.inc
' Contents: Traffic Control specific error codes
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TCERROR_INC = 1

%TCBASE = 7500

'//
'// Incompatible TC version number
'//
%ERROR_INCOMPATIBLE_TCI_VERSION			= (%TCBASE+1)

'//
'// Unspecified or bad intserv service type
'//
%ERROR_INVALID_SERVICE_TYPE			   = (%TCBASE+2)

'//
'// Unspecified or bad TokenRate
'//
%ERROR_INVALID_TOKEN_RATE			      = (%TCBASE+3)

'//
'// Bad PeakBandwidth
'//
%ERROR_INVALID_PEAK_RATE				   = (%TCBASE+4)

'//
'// Invalid ShapeDiscardMode
'//
%ERROR_INVALID_SD_MODE				      = (%TCBASE+5)

'//
'// Invalid priority value
'//
%ERROR_INVALID_QOS_PRIORITY			   = (%TCBASE+6)

'//
'// Invalid traffic class value
'//
%ERROR_INVALID_TRAFFIC_CLASS			   = (%TCBASE+7)

'//
'// Invalid address type
'//
%ERROR_INVALID_ADDRESS_TYPE			   = (%TCBASE+8)

'//
'// Attempt to install identical filter on same flow
'//
%ERROR_DUPLICATE_FILTER				      = (%TCBASE+9)

'//
'// Attempt to install conflicting filter
'//
%ERROR_FILTER_CONFLICT				      = (%TCBASE+10)

'//
'// This address type is not supported
'//
%ERROR_ADDRESS_TYPE_NOT_SUPPORTED	   = (%TCBASE+11)

'//
'// This object can not be deleted since its suporting opened objects
'//
%ERROR_TC_SUPPORTED_OBJECTS_EXIST	   = (%TCBASE+12)

'//
'// Incompatable QoS parameters
'//
%ERROR_INCOMPATABLE_QOS				      = (%TCBASE+13)

'//
'// Traffic Control is not supported in the system
'//
%ERROR_TC_NOT_SUPPORTED				      = (%TCBASE+14)

'//
'// TcObjectsLength is inconsistent with CfInfoSize
'//
%ERROR_TC_OBJECT_LENGTH_INVALID        = (%TCBASE+15)

'//
'// Adding an Intserv flow in Diffserv mode or vice versa
'//
%ERROR_INVALID_FLOW_MODE               = (%TCBASE+16)

'//
'// Invalid Diffserv flow
'//
%ERROR_INVALID_DIFFSERV_FLOW           = (%TCBASE+17)

'//
'// DS codepoint already exists
'//
%ERROR_DS_MAPPING_EXISTS               = (%TCBASE+18)

'//
'// Invalid Shape Rate specified
'//
%ERROR_INVALID_SHAPE_RATE              = (%TCBASE+19)

'//
'// Invalid DCLASS
'//
%ERROR_INVALID_DS_CLASS                = (%TCBASE+20)

'//
'// Too many GPC clients
'//
%ERROR_TOO_MANY_CLIENTS                = (%TCBASE+21)
