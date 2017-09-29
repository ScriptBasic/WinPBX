' ########################################################################################
' Microsoft Windows
' File: WMI.inc
' Contents: Master include file for WMI
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ========================================================================================
' Using the interface definitions included in this file you can access Windows Management
' Instrumentation (WMI) services using PBWIN 9.0+ and PBCC 5.0+.
' Each of the many different WMI objects inherit from an interface that is ultimately
' inherited from the IUnknown interface. COM dictates how object implementers, or
' interfaces, handle tasks such as memory management, parameter management, and
' multithreading. By conforming to COM, the COM API for WMI guarantees that it supports
' the functionality provided by the interfaces of each WMI object.
' ========================================================================================

#INCLUDE THIS ONCE
%WMI_INC = 1

#INCLUDE ONCE "ole2.inc"
#INCLUDE ONCE "wbemcli.inc"
#INCLUDE ONCE "wbemdisp.inc"
#INCLUDE ONCE "wbemprov.inc"
#INCLUDE ONCE "wbemads.inc"
#INCLUDE ONCE "wmiutils.inc"

' ########################################################################################
'                          H E L P E R    F U N C T I O N S
' ########################################################################################

' ========================================================================================
' Converts a display name into a moniker that identifies the object named, and then binds
' to the object identified by the moniker.
' ========================================================================================
FUNCTION WmiGetObject (BYVAL bstrDisplayName AS WSTRING) AS IDispatch
   LOCAL hr AS LONG
   LOCAL pDisp AS IDispatch
   hr = CoGetObject(BYCOPY bstrDisplayName, BYVAL %NULL, $IID_IDispatch, pDisp)
   IF hr = %S_OK THEN FUNCTION = pDisp
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns a reference to a WMI collection
' Note: Takes advantage of the fact that all the NewEnum methods of all the WMI
' collections have an offset of 28.
' ========================================================================================
DECLARE FUNCTION Proto_WmiNewEnum (BYVAL pthis AS DWORD PTR, BYREF ppenum AS IUnknown) AS LONG
' ========================================================================================
FUNCTION WmiNewEnum (BYVAL oObj AS DISPATCH, BYREF ppenum AS IUnknown) AS LONG
   LOCAL HRESULT AS LONG
   LOCAL pthis AS DWORD PTR
   pthis = OBJPTR(oObj)
   IF ISFALSE ISOBJECT(oObj) OR VARPTR(ppenum) = %NULL THEN FUNCTION = %E_POINTER : EXIT FUNCTION
   CALL DWORD @@pthis[7] USING Proto_WmiNewEnum(pthis, ppenum) TO HRESULT
   FUNCTION = HRESULT
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a WMI date.
' Note: The UDT is returned as an string.
' Use TYPE SET to assign the string to an WMI_DATE udt, e.g.
' DIM tDate AS WMI_DATE
' TYPE SET tDate = WmiDateToUdt(vDate)
' ========================================================================================
' // Size = 32 bytes
TYPE WMI_DATE DWORD
   Year         AS LONG
   Month        AS LONG
   Day          AS LONG
   Hours        AS LONG
   Minutes      AS LONG
   Seconds      AS LONG
   Microseconds AS LONG
   UTC          AS LONG
END TYPE

FUNCTION WmiDate2Udt (BYVAL vDate AS VARIANT) AS STRING

   LOCAL pDateTime AS ISWbemDateTime
   LOCAL tDate AS WMI_DATE
   LOCAL bstrDate AS WSTRING

   bstrDate = VARIANT$$(vDate)
   IF bstrDate = "" THEN EXIT FUNCTION

   pDateTime = NEWCOM "WbemScripting.SWbemDateTime"
   IF ISNOTHING(pDateTime) THEN EXIT FUNCTION
   pDateTime.Value = bstrDate
   tDate.Year = pDateTime.Year
   tDate.Month = pDateTime.Month
   tDate.Day = pDateTime.Day
   tDate.Hours = pDateTime.Hours
   tDate.Minutes = pDateTime.Minutes
   tDate.Seconds = pDateTime.Seconds
   tDate.Microseconds = pDateTime.Microseconds
   tDate.UTC = pDateTime.UTC
   pDateTime = NOTHING
   FUNCTION = tDate

END FUNCTION
' ========================================================================================

' ========================================================================================
' Helper function for IWbemStatusCodeText.GetErrorCodeText.
' Returns the text string description associated with the error code.
' ========================================================================================
FUNCTION WmiGetErrorCodeText (BYVAL hResult AS LONG) AS WSTRING

   LOCAL hr                   AS LONG
   LOCAL wsErrMsg             AS WSTRING
   LOCAL pIWbemStatusCodeText AS IWbemStatusCodeText

   pIWbemStatusCodeText = NEWCOM CLSID $CLSID_WbemStatusCodeText
   IF ISNOTHING(pIWbemStatusCodeText) THEN EXIT FUNCTION
   hr = pIWbemStatusCodeText.GetErrorCodeText(hResult, 0, 0, wsErrMsg)
   IF hr = %S_OK THEN FUNCTION = wsErrMsg

END FUNCTION
' ========================================================================================

' ========================================================================================
' Helper function for IWbemStatusCodeText.GetFacilityCodeText.
' Returns the name of the subsystem where the error occurred
' ========================================================================================
FUNCTION WmiGetFacilityCodeText (BYVAL hResult AS LONG) AS WSTRING

   LOCAL hr                   AS LONG
   LOCAL wsErrMsg             AS WSTRING
   LOCAL pIWbemStatusCodeText AS IWbemStatusCodeText

   pIWbemStatusCodeText = NEWCOM CLSID $CLSID_WbemStatusCodeText
   IF ISNOTHING(pIWbemStatusCodeText) THEN EXIT FUNCTION
   hr = pIWbemStatusCodeText.GetFacilityCodeText(hResult, 0, 0, wsErrMsg)
   IF hr = %S_OK THEN FUNCTION = wsErrMsg

END FUNCTION
' ========================================================================================
