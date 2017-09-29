' ########################################################################################
' Microsoft Windows
' File: adc.inc
' Contents: Adc external constants and GUIDS
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ADC_INC = 1

$CLSID_FoxRowset          = GUID$("{3ff292b6-b204-11cf-8d23-00aa005ffe58}")
$DBPROPSET_ADC            = GUID$("{b68e3cc1-6deb-11d0-8df6-00aa005ffe58}")
$IID_IAsyncAllowed        = GUID$("{f5f2893a-ba9e-11d0-abb9-00c04fc29f8f}")
$IID_IRowsetADCExtensions = GUID$("{F17324c4-68E0-11D0-AD45-00C04FC29863}")
$IID_IUpdateInfo          = GUID$("{a0385420-62b8-11d1-9a06-00a0c903aa45}")
$IID_IRowsetSynchronize   = GUID$("{1be41e60-807a-11d1-9a14-00a0c903aa45}")
$IID_IRowsetProperties    = GUID$("{1e837070-bcfc-11d1-9a2c-00a0c903aa45}")

' Enum ADCPROPENUM
%DBPROP_ADC_ASYNCHFETCHSIZE          = 3
%DBPROP_ADC_BATCHSIZE                = 4
%DBPROP_ADC_UPDATECRITERIA           = 5
'// dropping support for the UPDATEOPERTION property, but should not reuse the number
'// DBPROP_ADC_UPDATEOPERATION = 6
%DBPROP_ADC_ASYNCHPREFETCHSIZE       = 7
%DBPROP_ADC_ASYNCHTHREADPRIORITY     = 8
%DBPROP_ADC_CACHECHILDROWS           = 9
%DBPROP_ADC_MAINTAINCHANGESTATUS     = 10
%DBPROP_ADC_AUTORECALC               = 11
%DBPROP_ADC_UNIQUETABLE              = 13
%DBPROP_ADC_UNIQUESCHEMA             = 14
%DBPROP_ADC_UNIQUECATALOG            = 15
%DBPROP_ADC_CUSTOMRESYNCH            = 16
%DBPROP_ADC_CEVER                    = 17
%DBPROP_ADC_RESHAPENAME              = 18
%DBPROP_ADC_UPDATERESYNC             = 19
'// removing SaveMode, but we should not reuse the number
'// DBPROP_ADC_SAVEMODE = 20
%DBPROP_ADC_BACKINGSTORE             = 21
%DBPROP_ADC_RELEASESHAPEONDISCONNECT = 22

'// these enums are defined in both adc.h and adoint.h
'// do not re define them here if adoint.h has already been included
#IF NOT %DEF(%COMMON_ADC_AND_ADO_PROPS)
    %COMMON_ADC_AND_ADO_PROPS = 1

' Enum ADCPROP_UPDATECRITERIA_ENUM
%adCriteriaKey       = 0
%adCriteriaAllCols   = 1
%adCriteriaUpdCols   = 2
%adCriteriaTimeStamp = 3

' Enum ADCPROP_ASYNCTHREADPRIORITY_ENUM
%adPriorityLowest      = 1
%adPriorityBelowNormal = 2
%adPriorityNormal      = 3
%adPriorityAboveNormal = 4
%adPriorityHighest     = 5

' Enum ADCPROP_UPDATERESYNC_ENUM
%adResyncNone          = 0
%adResyncAutoIncrement = &H1
%adResyncConflicts     = &H2
%adResyncUpdates       = &H4
%adResyncInserts       = &H8
%adResyncAll           = &H0F

' Enum ADCPROP_AUTORECALC_ENUM
%adRecalcUpFront = 0
%adRecalcAlways  = 1

#ENDIF   ' // _COMMON_ADC_AND_ADO_PROPS_

' Enum FOXROWSETPROPENUM
%DBPROP_FOXTABLENAME = &Heeff&
