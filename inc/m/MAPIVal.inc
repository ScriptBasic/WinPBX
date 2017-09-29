' ########################################################################################
' Microsoft Windows
' File: MAPIVal.inc
' Contents: Functions used to validate parameters on standard MAPI object methods.
' Used in conjunction with routines found in MAPIU.DLL.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MAPIVAL_INC = 1

#INCLUDE ONCE "mapiutil.inc"

' ========================================================================================
' FBadRglpszW
' Validates all strings in an array of Unicode strings.
' Note: This function may not be supported in future versions of MAPI.
' ========================================================================================
DECLARE FUNCTION FBadRglpszW IMPORT "MAPI32.DLL" ALIAS "FBadRglpszW@8" ( _
   BYREF lppszW AS WSTRINGZ _                           ' __in LPWSTR FAR * lppszW
 , BYVAL cStrings AS DWORD _                            ' __in ULONG cStrings
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' FBadRowSet
' Validates all table rows included in a set of table rows.
' Note This function may not be supported in future versions of MAPI.
' ========================================================================================
DECLARE FUNCTION FBadRowSet IMPORT "MAPI32.DLL" ALIAS "FBadRowSet@4" ( _
   BYVAL lpRowSet AS SRowSet PTR _                      ' __in LPSRowSet lpRowSet
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' FBadRglpNameID
' Validates an array of structures that describe named properties and verifies their allocation.
' Note: This function may not be supported in future versions of MAPI.
' ========================================================================================
DECLARE FUNCTION FBadRglpNameID IMPORT "MAPI32.DLL" ALIAS "FBadRglpNameID@8" ( _
   BYREF lppNameId AS MAPINAMEID _                      ' __in LPMAPINAMEID FAR * lppNameId
 , BYVAL cNames AS DWORD _                              ' __in ULONG cNames
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' FBadEntryList
' Validates a list of MAPI entry identifiers.
' Note: This function may not be supported in future versions of MAPI.
' ========================================================================================
DECLARE FUNCTION FBadEntryList IMPORT "MAPI32.DLL" ALIAS "FBadEntryList@4" ( _
   BYVAL lpEntryList AS ENTRYLIST PTR _                 ' __in LPENTRYLIST lpEntryList
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' FBadRestriction
' Validates a restriction used to limit a table view.
' Note: This function may not be supported in future versions of MAPI.
' ========================================================================================
DECLARE FUNCTION FBadRestriction IMPORT "MAPI32.DLL" ALIAS "FBadRestriction@4" ( _
   BYREF lpres AS SRestriction _                        ' __in LPSRestriction lpres
 ) AS DWORD                                             ' ULONG
' ========================================================================================

' ========================================================================================
' FBadPropTag
' Validates a specified property tag.
' Note: This function may not be supported in future versions of MAPI.
' ========================================================================================
DECLARE FUNCTION FBadPropTag IMPORT "MAPI32.DLL" ALIAS "FBadPropTag@4" ( _
   BYVAL ulPropTag AS DWORD _                           ' __in ULONG ulPropTag
 ) AS DWORD                                             ' ULONG
' ========================================================================================

' ========================================================================================
' FBadRow
' Validates a row in a table.
' Note: This function may not be supported in future versions of MAPI.
' ========================================================================================
DECLARE FUNCTION FBadRow IMPORT "MAPI32.DLL" ALIAS "FBadRow@4" ( _
   BYREF lprow AS SRow _                                ' __in LPSRow lprow
 ) AS DWORD                                             ' ULONG
' ========================================================================================

' ========================================================================================
' FBadProp
' Validates a specified property.
' Note_ This function may not be supported in future versions of MAPI.
' ========================================================================================
DECLARE FUNCTION FBadProp IMPORT "MAPI32.DLL" ALIAS "FBadProp@4" ( _
   BYREF lpprop AS SPropValue _                         ' __in LPSPropValue lpprop
 ) AS DWORD                                             ' ULONG
' ========================================================================================

' ========================================================================================
' FBadSortOrderSet
' Validates a sort order set by verifying its memory allocation.
' Note: This function may not be supported in future versions of MAPI.
' ========================================================================================
DECLARE FUNCTION FBadSortOrderSet IMPORT "MAPI32.DLL" ALIAS "FBadSortOrderSet@4" ( _
   BYVAL lpsos AS SSortOrderSet PTR _                   ' __in LPSSortOrderSet lpsos
 ) AS DWORD                                             ' ULONG
' ========================================================================================

' ========================================================================================
' FBadColumnSet
' Tests the validity of a table column set for use by a service provider in a subsequent
' call to the IMAPITable::SetColumns method.
' Note: This function may not be supported in future versions of MAPI.
' ========================================================================================
DECLARE FUNCTION FBadColumnSet IMPORT "MAPI32.DLL" ALIAS "FBadColumnSet@4" ( _
   BYVAL lpptaCols AS SPropTagArray PTR _               ' __in LPSPropTagArray lpptaCols
 ) AS DWORD                                             ' ULONG
' ========================================================================================

'HRESULT STDAPICALLTYPE
'__CPPValidateParameters(METHODS eMethod, const LPVOID ppFirst);

DECLARE FUNCTION CPPValidateParameters IMPORT "MAPI32.DLL" ALIAS "__CPPValidateParameters@8" ( _
   BYVAL eMethod AS DWORD _                             ' __in METHODS eMethod
 , BYREF ppFirst AS ANY _                               ' __out const LPVOID ppFirst
 ) AS LONG                                              ' HRESULT

'HRESULT STDAPICALLTYPE
'__ValidateParameters(METHODS eMethod, LPVOID ppThis);

DECLARE FUNCTION ValidateParmeters IMPORT "MAPI32.DLL" ALIAS "__ValidateParameters@8" ( _
   BYVAL eMethod AS DWORD _                             ' __in METHODS eMethod
 , BYREF ppThis AS ANY _                                ' __out LPVOID ppThis
 ) AS LONG                                              ' HRESULT

'HRESULT STDAPI HrValidateParameters( METHODS eMethod, LPVOID FAR *ppFirstArg );
DECLARE FUNCTION HrValidateParameters IMPORT "MAPI32.DLL" ALIAS "HrValidateParameters@8" ( _
   BYVAL eMethod AS DWORD _                             ' __in METHODS eMethod
 , BYREF ppFirstArg AS ANY _                            ' __out LPVOID FAR *ppFirstArg
 ) AS LONG                                              ' HRESULT
