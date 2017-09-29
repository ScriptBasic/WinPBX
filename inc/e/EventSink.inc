' ########################################################################################
' Event Sink Class
' Connects/disconnects from the events fired by a server.
' Call EV_Advise to connect events and EV_Unadvise to disconnect.
' Copyright (c) 2011 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%EVENTSINK_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "ole2utils.inc"

' ========================================================================================
' Callback function prototype
' ========================================================================================
DECLARE FUNCTION EV_EventsCallback ( _
   BYVAL pthis AS DWORD _               ' // Pointer to the client's IDispatch
 , BYVAL dispidMember AS LONG _         ' // Identifier of the event
 , BYREF pdispparams AS DISPPARAMS _    ' // Structure containing an array of arguments
 , BYREF pvarResult AS VARIANT _        ' // Pointer to the location where the result is to be stored, or NULL if the caller expects no result
 , BYVAL pCustData AS DWORD _           ' // Pointer to user defined data
 ) AS LONG

' ========================================================================================
' Sample code
' ========================================================================================
'' // Connect events
'hr = EV_Advise(pObject, $IID_ObjectInterface, _
'     CODEPTR(ObjectInterface_EventsCallback), 0, dwCookie)
'
'' // Disconnect events
'hr = EV_Unadvise(pObject, $IID_ObjectInterface, dwCookie)
'
'' // Events callback function
'' // Parameters in DISPPARAMS are in reversed order.
'' // The DispGetParam function can be used to extract values from DISPPARAMS.
'
'FUNCTION ObjectInterface_EventsCallback ( _
'   BYVAL pthis AS DWORD _               ' // Pointer to the client's IDispatch
' , BYVAL dispidMember AS LONG _         ' // Identifier of the event
' , BYREF pdispparams AS DISPPARAMS _    ' // Structure containing an array of arguments
' , BYREF pvarResult AS VARIANT _        ' // Pointer to the location where the result is to be stored, or NULL if the caller expects no result
' , BYVAL pCustData AS DWORD _           ' // Pointer to user defined data
' ) AS LONG                              ' // Return value

'   FUNCTION = %S_OK

'   SELECT CASE AS LONG dispidMember
'      CASE &H00000001  ' (1)  ' // Click
'         MSGBOX "Click"
'      CASE ELSE
'        FUNCTION = %DISP_E_MEMBERNOTFOUND
'   END SELECT

'END FUNCTION

' ########################################################################################
' IConnectionPointContainer::FindConnectionPoint
' Returns a pointer to the IConnectionPoint interface of a connection point for a specified IID,
' if that IID describes a supported outgoing interface.
' ########################################################################################
FUNCTION EV_IConnectionPointContainer_FindConnectionPoint (BYVAL pthis AS DWORD PTR, BYREF riid AS GUID, BYREF ppCP AS DWORD) AS LONG
   LOCAL HRESULT AS LONG
   CALL DWORD @@pthis[4] USING EV_IConnectionPointContainer_FindConnectionPoint(pthis, riid, ppCP) TO HRESULT
   FUNCTION = HRESULT
END FUNCTION
' ########################################################################################

' ########################################################################################
' IConnectionPoint::Advise
' Establishes a connection between the connection point object and the client's sink.
' ########################################################################################
FUNCTION EV_IConnectionPoint_Advise (BYVAL pthis AS DWORD PTR, BYVAL pUnkSink AS DWORD, BYREF pdwCookie AS DWORD) AS LONG
   LOCAL HRESULT AS LONG
   CALL DWORD @@pthis[5] USING EV_IConnectionPoint_Advise(pthis, pUnkSink, pdwCookie) TO HRESULT
   FUNCTION = HRESULT
END FUNCTION
' ########################################################################################

' ########################################################################################
' IConnectionPoint::Unadvise
' Terminates an advisory connection previously established through EV_IConnectionPoint_Advise.
' The dwCookie parameter identifies the connection to terminate.
' ########################################################################################
FUNCTION EV_IConnectionPoint_Unadvise (BYVAL pthis AS DWORD PTR, BYVAL dwCookie AS DWORD) AS LONG
   LOCAL HRESULT AS LONG
   CALL DWORD @@pthis[6] USING EV_IConnectionPoint_Unadvise(pthis, dwCookie) TO HRESULT
   FUNCTION = HRESULT
END FUNCTION
' ########################################################################################

' ########################################################################################
' IDispatch virtual table
' ########################################################################################
TYPE EV_IDispatchEventsVtbl
   QueryInterface   AS DWORD   ' // Returns pointers to supported interfaces
   AddRef           AS DWORD   ' // Increments reference count
   Release          AS DWORD   ' // Decrements reference count
   GetTypeInfoCount AS DWORD   ' // Retrieves the number of type descriptions
   GetTypeInfo      AS DWORD   ' // Retrieves a description of object's programmable interface
   GetIDsOfNames    AS DWORD   ' // Maps name of method or property to DispId
   Invoke           AS DWORD   ' // Calls one of the object's methods, or gets/sets one of its properties
   pVtblAddr        AS DWORD   ' // Address of the virtual table
   cRef             AS DWORD   ' // Reference count
   pthis            AS DWORD   ' // IUnknown or IDispatch of the control that fires the events
   pCallback        AS DWORD   ' // Address of the callback function
   pCustData        AS DWORD   ' // Pointer to custom data
   dwCookie         AS DWORD   ' // Cookie
   riid             AS GUID    ' // GUID of the events interface
END TYPE
' ########################################################################################

' ########################################################################################
' Builds the IDispatch Virtual Table
' ########################################################################################
FUNCTION EV_IDispatchEvents_BuildVtbl (BYVAL pthis AS DWORD, BYREF riid AS GUID, BYVAL pCallback AS DWORD, BYVAL pCustData AS DWORD) AS DWORD

   LOCAL pVtbl AS EV_IDispatchEventsVtbl PTR
   LOCAL pUnk AS EV_IDispatchEventsVtbl PTR

   pVtbl = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(@pVtbl))
   IF pVtbl = 0 THEN EXIT FUNCTION

   @pVtbl.QueryInterface   = CODEPTR(EV_IDispatchEvents_QueryInterface)
   @pVtbl.AddRef           = CODEPTR(EV_IDIspatchEvents_AddRef)
   @pVtbl.Release          = CODEPTR(EV_IDispatchEvents_Release)
   @pVtbl.GetTypeInfoCount = CODEPTR(EV_EV_IDispatchEvents_GetTypeInfoCount)
   @pVtbl.GetTypeInfo      = CODEPTR(EV_IDispatchEvents_GetTypeInfo)
   @pVtbl.GetIDsOfNames    = CODEPTR(EV_IDispatchEvents_GetIDsOfNames)
   @pVtbl.Invoke           = CODEPTR(EV_IDispatchEvents_Invoke)
   @pVtbl.pVtblAddr        = pVtbl
   @pVtbl.pthis            = pthis
   @pVtbl.riid             = riid
   @pVtbl.pCallback        = pCallback
   @pVtbl.pCustData        = pCustData

   pUnk = VARPTR(@pVtbl.pVtblAddr)
   FUNCTION = pUnk

END FUNCTION
' ########################################################################################

' ########################################################################################
' HRESULT QueryInterface([in] *GUID riid, [out] **VOID ppvObj)
' Returns the IUnknown of our class and increments the reference counter.
' ########################################################################################
FUNCTION EV_IDispatchEvents_QueryInterface (BYVAL pUnkSink AS EV_IDispatchEventsVtbl PTR, _
   BYREF riid AS GUID, BYREF ppvObj AS DWORD) AS LONG
   IF riid = $IID_IUnknown OR _     ' // IUnknown interface
      riid = $IID_IDispatch OR _    ' // IDispatch interface
      riid = @@pUnkSink.riid THEN   ' // Events dispatch interface
      ppvObj = pUnkSink
      EV_IDIspatchEvents_AddRef pUnkSink
      FUNCTION = %S_OK
   ELSE
      ppvObj = %NULL
      FUNCTION = %E_NOINTERFACE
   END IF
END FUNCTION
' ########################################################################################

' ########################################################################################
' UI4 AddRef()
' Increments the reference count.
' ########################################################################################
FUNCTION EV_IDIspatchEvents_AddRef (BYVAL pUnkSink AS EV_IDispatchEventsVtbl PTR) AS DWORD
   INCR @@pUnkSink.cRef
   FUNCTION = @@pUnkSink.cRef
END FUNCTION
' ########################################################################################

' ########################################################################################
' UI4 Release()
' Releases our class if there is only a reference to him and decrements the reference counter.
' ########################################################################################
FUNCTION EV_IDispatchEvents_Release (BYVAL pUnkSink AS EV_IDispatchEventsVtbl PTR) AS DWORD
   LOCAL pVtblAddr AS DWORD
   IF @@pUnkSink.cRef = 1 THEN
      pVtblAddr = @@pUnkSink.pVtblAddr
      IF ISTRUE HeapFree(GetProcessHeap(), 0, BYVAL pVtblAddr) THEN
         FUNCTION = 0
         EXIT FUNCTION
      ELSE
         FUNCTION = @@pUnkSink.cRef
         EXIT FUNCTION
      END IF
   END IF
   DECR @@pUnkSink.cRef
   FUNCTION = @@pUnkSink.cRef
END FUNCTION
' ########################################################################################

' ########################################################################################
' HRESULT GetTypeInfoCount([out] *UINT pctinfo)
' ########################################################################################
FUNCTION EV_EV_IDispatchEvents_GetTypeInfoCount (BYVAL pUnkSink AS EV_IDispatchEventsVtbl PTR, BYREF pctInfo AS DWORD) AS LONG
   pctInfo = 0
   FUNCTION = %S_OK
END FUNCTION
' ########################################################################################

' ########################################################################################
' HRESULT GetTypeInfo([in] UINT itinfo, [in] UI4 lcid, [out] **VOID pptinfo)
' ########################################################################################
FUNCTION EV_IDispatchEvents_GetTypeInfo (BYVAL pUnkSink AS EV_IDispatchEventsVtbl PTR, _
   BYVAL itinfo AS DWORD, BYVAL lcid AS DWORD, BYREF pptinfo AS DWORD) AS LONG
   FUNCTION = %E_NOTIMPL
END FUNCTION
' ########################################################################################

' ########################################################################################
' HRESULT GetIDsOfNames([in] *GUID riid, [in] **I1 rgszNames, [in] UINT cNames, [in] UI4 lcid, [out] *I4 rgdispid)
' ########################################################################################
FUNCTION EV_IDispatchEvents_GetIDsOfNames (BYVAL pUnkSink AS EV_IDispatchEventsVtbl PTR, _
   BYREF riid AS GUID, BYREF rgszNames AS WSTRING, BYVAL cNames AS DWORD, BYVAL lcid AS DWORD, BYREF rgdispid AS LONG) AS LONG
   FUNCTION = %E_NOTIMPL
END FUNCTION
' ########################################################################################

' ########################################################################################
' HRESULT Invoke([in] I4 dispidMember, [in] *GUID riid, [in] UI4 lcid, [in] UI2 wFlags, [in] *DISPPARAMS pdispparams, [out] *VARIANT pvarResult, [out] *EXCEPINFO pexcepinfo, [out] *UINT puArgErr)
' ########################################################################################
FUNCTION EV_IDispatchEvents_Invoke (BYVAL pUnkSink AS EV_IDispatchEventsVtbl PTR, BYVAL dispidMember AS LONG, BYREF riid AS GUID, _
   BYVAL lcid AS DWORD, BYVAL wFlags AS WORD, BYREF pdispparams AS DISPPARAMS, BYREF pvarResult AS VARIANT, _
   BYREF pexcepinfo AS EXCEPINFO, BYREF puArgErr AS DWORD) AS LONG

   LOCAL hr AS LONG
   IF @pUnkSink.pCallback THEN
      CALL DWORD @@pUnkSink.pCallback USING EV_EventsCallback ( _
           @@pUnkSink.pthis, dispidMember, pdispparams, pvarResult, @@pUnkSink.pCustData) TO hr
      FUNCTION = hr
   END IF

END FUNCTION
' ########################################################################################

' ########################################################################################
' Establishes a connection between the connection point object and the client's sink.
' Parameters:
'   [in]  pdisp = Pointer to the client's IDispatch.
'   [in]  riid = The GUID of the connection point (the iid of the events interface).
'   [in]  pCallback = Address of the callback function that will receive the events.
'   [in]  pCustData = Pointer to user defined data.
'   [out] pdwCookie = A token that uniquely identifies this connection.
' Return value:
'   Returns %S_OK or an error code.
' ########################################################################################
FUNCTION EV_Advise (BYVAL pdisp AS IDispatch, BYREF riid AS GUID, BYVAL pCallback AS DWORD, BYVAL pCustData AS DWORD, BYREF pdwCookie AS DWORD) AS LONG

   LOCAL HRESULT  AS LONG                         ' // HRESULT code
   LOCAL pthis    AS DWORD                        ' // Pointer to the client's IDispatch
   LOCAL pCPC     AS DWORD                        ' // IConnectionPointContainer
   LOCAL pCP      AS DWORD                        ' // IConnectionPoint
   LOCAL dwCookie AS DWORD                        ' // Returned token
   LOCAL pUnkSink AS EV_IDispatchEventsVtbl PTR   ' // IUnknown of the event sink class

   pthis = OBJPTR(pdisp)
   IF pthis = 0 THEN FUNCTION = %E_POINTER : EXIT FUNCTION
   IF VARPTR(riid) = 0 THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION
   IF VARPTR(pdwCookie) = 0 THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION
   HRESULT = IUnknown_QueryInterface(pthis, $IID_IConnectionPointContainer, pCPC)
   IF HRESULT <> %S_OK THEN FUNCTION = HRESULT : EXIT FUNCTION

   HRESULT = EV_IConnectionPointContainer_FindConnectionPoint(pCPC, riid, pCP)
   IUnknown_Release pCPC
   IF HRESULT <> %S_OK THEN FUNCTION = HRESULT : EXIT FUNCTION

   pUnkSink = EV_IDispatchEvents_BuildVtbl(pthis, riid, pCallback, pCustData)
   IF ISTRUE pUnkSink THEN HRESULT = EV_IConnectionPoint_Advise(pCP, pUnkSink, dwCookie)
   IUnknown_Release pCP
   pdwCookie = dwCookie
   @@pUnkSink.dwCookie = dwCookie
   FUNCTION = HRESULT

END FUNCTION
' ########################################################################################

' ########################################################################################
' Releases the events connection identified with the cookie returned by the ConnectEvents function
' Parameters:
'   [in] pdisp = Pointer to the Client's IDispatch.
'   [in] riid = The GUID of the connection point (the iid of the events interface).
'   [in] dwCookie = the token returned in the call to EV_Advise.
' Return value:
'   Returns %S_OK or an error code.
' ########################################################################################
FUNCTION EV_Unadvise (BYVAL pdisp AS IDispatch, BYREF riid AS GUID, BYVAL dwCookie AS DWORD) AS LONG

   LOCAL HRESULT AS LONG    ' HRESULT code
   LOCAL pthis   AS DWORD   ' Pointer to the client's IDispatch
   LOCAL pCPC    AS DWORD   ' IConnectionPointContainer
   LOCAL pCP     AS DWORD   ' IConnectionPoint

   pthis = OBJPTR(pdisp)
   IF pthis = 0 THEN FUNCTION = %E_POINTER : EXIT FUNCTION
   IF VARPTR(riid) = 0 THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION
   HRESULT = IUnknown_QueryInterface(pthis, $IID_IConnectionPointContainer, pCPC)
   IF HRESULT <> %S_OK THEN FUNCTION = HRESULT : EXIT FUNCTION

   HRESULT = EV_IConnectionPointContainer_FindConnectionPoint(pCPC, riid, pCP)
   IUnknown_Release pCPC
   IF HRESULT <> %S_OK THEN FUNCTION = HRESULT : EXIT FUNCTION

   HRESULT = EV_IConnectionPoint_Unadvise(pCP, dwCookie)
   IUnknown_Release pCP
   FUNCTION = HRESULT

END FUNCTION
' ########################################################################################
