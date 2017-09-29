' ########################################################################################
' Microsoft Windows
' File: seo.inc
' Contents: Definitions for the COM interface for Server Extension Objects.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: SEOLib
' Version: 1.0, Locale ID = 0
' Description: Server Extension Objects COM Library
' Library GUID: {BBF0FC10-2238-11D0-A9CE-00AA00685C74}
' ########################################################################################

#INCLUDE THIS ONCE
%SEO_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "wtypes.inc"
#INCLUDE ONCE "ocidl.inc"

'#ifndef SEODLLIMPORT
'     #define SEODLLIMPORT _declspec(dllimport)
'#endif
'#ifndef SEODLLEXPORT
'     #define SEODLLEXPORT _declspec(dllexport)
'#endif
'#ifndef SEODLLDEF
'     #ifndef SEODLL_IMPLEMENTATION
'             #define SEODLLDEF EXTERN_C SEODLLIMPORT
'     #else
'             #define SEODLLDEF EXTERN_C SEODLLEXPORT
'     #endif
'#endif

$BD_OBJECT                    = "Object"
$BD_PROGID                    = "ProgID"
$BD_PRIORITY                  = "Priority"
$BD_RULEENGINE                = "RuleEngine"
$BD_EXCLUSIVE                 = "Exclusive"
$BD_BINDINGS                  = "Bindings"
$BD_DISPATCHER                = "Dispatcher"
$BD_BINDINGPOINTS             = "BindingPoints"
$BD_RULE                      = "Rule"

%PRIO_HIGHEST                 = 0
%PRIO_HIGH                    = 8191
%PRIO_MEDIUM                  = 16383
%PRIO_LOW                     = 24575
%PRIO_LOWEST                  = 32767
%PRIO_DEFAULT                 = %PRIO_LOW

'#define PRIO_HIGHEST_STR             L"PRIO_HIGHEST"
'#define PRIO_HIGH_STR                L"PRIO_HIGH"
'#define PRIO_MEDIUM_STR              L"PRIO_MEDIUM"
'#define PRIO_LOW_STR                 L"PRIO_LOW"
'#define PRIO_LOWEST_STR              L"PRIO_LOWEST"
'#define PRIO_DEFAULT_STR             L"PRIO_DEFAULT"

$PRIO_HIGHEST_STR             = "PRIO_HIGHEST"
$PRIO_HIGH_STR                = "PRIO_HIGH"
$PRIO_MEDIUM_STR              = "PRIO_MEDIUM"
$PRIO_LOW_STR                 = "PRIO_LOW"
$PRIO_LOWEST_STR              = "PRIO_LOWEST"
$PRIO_DEFAULT_STR             = "PRIO_DEFAULT"

'#define PRIO_MIN                     PRIO_HIGHEST
'#define PRIO_MAX                     PRIO_LOWEST

%PRIO_MIN                     = %PRIO_HIGHEST
%PRIO_MAX                     = %PRIO_LOWEST

$LIBID_SEOLib = GUID$("{BBF0FC10-2238-11D0-A9CE-00AA00685C74}")

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_CEventBindingManager = GUID$("{53D01080-AF98-11D0-A9EB-00AA00685C74}")
$CLSID_CEventComCat = GUID$("{AE1EF300-CD8F-11D0-A9F8-00AA00685C74}")
$CLSID_CEventLock = GUID$("{2E3ABB30-AF88-11D0-A9EB-00AA00685C74}")
$CLSID_CEventManager = GUID$("{35172920-A700-11D0-A9EA-00AA00685C74}")
$CLSID_CEventMetabaseDatabaseManager = GUID$("{8A58CDC0-CBDC-11D0-A9F8-00AA00685C74}")
$CLSID_CEventRouter = GUID$("{9F82F020-F6FD-11D0-AA14-00AA006BC80B}")
$CLSID_CEventUtil = GUID$("{A1E041D0-CD73-11D0-A9F8-00AA00685C74}")
$CLSID_CSEODictionaryItem = GUID$("{2E3A0EC0-89D7-11D0-A9E6-00AA00685C74}")
$CLSID_CSEOGenericMoniker = GUID$("{7E3BF330-B28E-11D0-8BD8-00C04FD42E37}")
$CLSID_CSEOMemDictionary = GUID$("{C4DF0042-2D33-11D0-A9CF-00AA00685C74}")
$CLSID_CSEOMetaDictionary = GUID$("{C4DF0043-2D33-11D0-A9CF-00AA00685C74}")
$CLSID_CSEOMimeDictionary = GUID$("{C4DF0041-2D33-11D0-A9CF-00AA00685C74}")
$CLSID_CSEORegDictionary = GUID$("{C4DF0040-2D33-11D0-A9CF-00AA00685C74}")
$CLSID_CSEORouter = GUID$("{83D63730-94FD-11D0-A9E8-00AA00685C74}")
$CLSID_CSEOStream = GUID$("{ED1343B0-A8A6-11D0-A9EA-00AA00685C74}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IEventBinding = GUID$("{8E398CE0-A64E-11D0-A9EA-00AA00685C74}")
$IID_IEventBindingManager = GUID$("{0B4CDBC0-A64F-11D0-A9EA-00AA00685C74}")
$IID_IEventBindings = GUID$("{1080B910-A636-11D0-A9EA-00AA00685C74}")
$IID_IEventComCat = GUID$("{65A70EC0-CD87-11D0-A9F8-00AA00685C74}")
$IID_IEventCreateOptions = GUID$("{C0287BFE-EF7F-11D1-9FFF-00C04FA37348}")
$IID_IEventDatabaseManager = GUID$("{ADC25B30-CBD8-11D0-A9F8-00AA00685C74}")
$IID_IEventDatabasePlugin = GUID$("{4915FB10-AF97-11D0-A9EB-00AA00685C74}")
$IID_IEventDeliveryOptions = GUID$("{0688A660-A3FF-11D0-A9E9-00AA00685C74}")
$IID_IEventDispatcher = GUID$("{C980F550-ED9E-11D0-AA10-00AA006BC80B}")
$IID_IEventDispatcherChain = GUID$("{58A90754-FB15-11D1-A00C-00C04FA37348}")
$IID_IEventIsCacheable = GUID$("{22E0F830-1E81-11D1-AA29-00AA006BC80B}")
$IID_IEventLock = GUID$("{1B7058F0-AF88-11D0-A9EB-00AA00685C74}")
$IID_IEventManager = GUID$("{5F6012B0-A651-11D0-A9EA-00AA00685C74}")
$IID_IEventNotifyBindingChange = GUID$("{08F4F2A0-DC5B-11D0-AA0F-00AA006BC80B}")
$IID_IEventNotifyBindingChangeDisp = GUID$("{DC3D83B0-E99F-11D0-AA10-00AA006BC80B}")
$IID_IEventPersistBinding = GUID$("{E9311660-1A98-11D1-AA26-00AA006BC80B}")
$IID_IEventPropertyBag = GUID$("{AABB23E0-A705-11D0-A9EA-00AA00685C74}")
$IID_IEventRouter = GUID$("{1A00B970-EDA0-11D0-AA10-00AA006BC80B}")
$IID_IEventRuleEngine = GUID$("{DA816090-F343-11D0-AA14-00AA006BC80B}")
$IID_IEventSinkNotify = GUID$("{BDF065B0-F346-11D0-AA14-00AA006BC80B}")
$IID_IEventSinkNotifyDisp = GUID$("{33A79660-F347-11D0-AA14-00AA006BC80B}")
$IID_IEventSource = GUID$("{B1DCB040-A652-11D0-A9EA-00AA00685C74}")
$IID_IEventSources = GUID$("{73E8C930-A652-11D0-A9EA-00AA00685C74}")
$IID_IEventSourceType = GUID$("{063A62E0-A652-11D0-A9EA-00AA00685C74}")
$IID_IEventSourceTypes = GUID$("{CAF30FD0-A651-11D0-A9EA-00AA00685C74}")
$IID_IEventType = GUID$("{4A993B80-A654-11D0-A9EA-00AA00685C74}")
$IID_IEventTypes = GUID$("{CAB29EF0-A64F-11D0-A9EA-00AA00685C74}")
$IID_IEventTypeSinks = GUID$("{A1063F50-A654-11D0-A9EA-00AA00685C74}")
$IID_IEventUtil = GUID$("{C61670E0-CD6E-11D0-A9F8-00AA00685C74}")
$IID_IMCISMessageFilter = GUID$("{F174E5B0-9046-11D0-A9E8-00AA00685C74}")
$IID_ISEOBindingConverter = GUID$("{EE4E64D0-31F1-11D0-A9D0-00AA00685C74}")
$IID_ISEOBindingRuleEngine = GUID$("{F2D1DAF0-2236-11D0-A9CE-00AA00685C74}")
$IID_ISEODictionary = GUID$("{D8177B40-7BAC-11D0-A9E0-00AA00685C74}")
$IID_ISEODictionaryItem = GUID$("{16D63630-83AE-11D0-A9E3-00AA00685C74}")
$IID_ISEODispatcher = GUID$("{8CA89880-31F1-11D0-A9D0-00AA00685C74}")
$IID_ISEOEventSink = GUID$("{1CAB4C20-94F4-11D0-A9E8-00AA00685C74}")
$IID_ISEOInitObject = GUID$("{9BB6AAB0-AF6D-11D0-8BD2-00C04FD42E37}")
$IID_ISEORegDictionary = GUID$("{347CACB0-2D1E-11D0-A9CF-00AA00685C74}")
$IID_ISEORouter = GUID$("{2B6AC0F0-7E03-11D0-A9E0-00AA00685C74}")

' ########################################################################################
' Interface name = ISEODictionaryItem
' IID = {16D63630-83AE-11D0-A9E3-00AA00685C74}
' SEOCOM dictionary item (OA-compatible)
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISEODictionaryItem_INTERFACE_DEFINED)
    %ISEODictionaryItem_INTERFACE_DEFINED = 1

INTERFACE ISEODictionaryItem $IID_ISEODictionaryItem

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 28
     OPTIONAL BYREF IN pvarIndex AS VARIANT _           ' __in_opt VARIANT *pvarIndex
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarResult
   ' =====================================================================================
   METHOD AddValue <1610743809> ( _                     ' VTable offset = 32
     BYREF pvarIndex AS VARIANT _                       ' __in VARIANT *pvarIndex
   , BYREF pvarValue AS VARIANT _                       ' __in VARIANT *pvarValue
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteValue <1610743810> ( _                  ' VTable offset = 36
     BYREF pvarIndex AS VARIANT _                       ' __in VARIANT *pvarIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Count <1610743811> ( _                  ' VTable offset = 40
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarResult
   ' =====================================================================================
   METHOD GetStringA <1610743812> ( _                   ' VTable offset = 44
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF pchCount AS DWORD _                          ' __inout DWORD *pchCount
   , BYREF pszResult AS ASCIIZ _                        ' __out LPSTR pszResult
   )                                                    ' void
   ' =====================================================================================
   METHOD GetStringW <1610743813> ( _                   ' VTable offset = 48
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF pchCount AS DWORD _                          ' __inout DWORD *pchCount
   , BYREF pszResult AS WSTRINGZ _                      ' __out LPWSTR pszResult
   )                                                    ' void
   ' =====================================================================================
   METHOD AddStringA <1610743814> ( _                   ' VTable offset = 52
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF pszValue AS ASCIIZ _                         ' __in LPSTR pszValue
   )                                                    ' void
   ' =====================================================================================
   METHOD AddStringW <1610743815> ( _                   ' VTable offset = 56
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF pszValue AS WSTRINGZ _                       ' __in LPWSTR pszValue
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISEODictionaryItem_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISEODictionary
' IID = {D8177B40-7BAC-11D0-A9E0-00AA00685C74}
' SEOCOM dictionary (OA-compatible).
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISEODictionary_INTERFACE_DEFINED)
    %ISEODictionary_INTERFACE_DEFINED = 1

INTERFACE ISEODictionary $IID_ISEODictionary

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYREF IN pvarName AS VARIANT _                     ' __in VARIANT *pvarName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarResult
   ' =====================================================================================
   PROPERTY SET Item <0> ( _                            ' VTable offset = 32
     BYREF IN pvarName AS VARIANT _                     ' __in VARIANT *pvarName
   , BYREF IN pvarResult AS VARIANT _                   ' __in VARIANT *pvarResult
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunkResult
   ' =====================================================================================
   METHOD GetVariantA <1610743811> ( _                  ' VTable offset = 40
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarResult
   ' =====================================================================================
   METHOD GetVariantW <1610743812> ( _                  ' VTable offset = 44
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarResult
   ' =====================================================================================
   METHOD SetVariantA <1610743813> ( _                  ' VTable offset = 48
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYREF pvarValue AS VARIANT _                       ' __in VARIANT *pvarValue
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVariantW <1610743814> ( _                  ' VTable offset = 52
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF pvarValue AS VARIANT _                       ' __in VARIANT *pvarValue
   )                                                    ' void
   ' =====================================================================================
   METHOD GetStringA <1610743815> ( _                   ' VTable offset = 56
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYREF pchCount AS DWORD _                          ' __inout DWORD *pchCount
   , BYREF pszResult AS ASCIIZ _                        ' __out LPSTR pszResult
   )                                                    ' void
   ' =====================================================================================
   METHOD GetStringW <1610743816> ( _                   ' VTable offset = 60
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF pchCount AS DWORD _                          ' __inout DWORD *pchCount
   , BYREF pszResult AS WSTRINGZ _                      ' __out LPWSTR pszResult
   )                                                    ' void
   ' =====================================================================================
   METHOD SetStringA <1610743817> ( _                   ' VTable offset = 64
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL chCount AS DWORD _                           ' __in DWORD chCount
   , BYREF pszValue AS ASCIIZ _                         ' __in LPCSTR pszValue
   )                                                    ' void
   ' =====================================================================================
   METHOD SetStringW <1610743818> ( _                   ' VTable offset = 68
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYVAL chCount AS DWORD _                           ' __in DWORD chCount
   , BYREF pszValue AS WSTRINGZ _                       ' __in LPCWSTR pszValue
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDWordA <1610743819> ( _                    ' VTable offset = 72
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   ) AS DWORD                                           ' __retval_out DWORD *pdwResult
   ' =====================================================================================
   METHOD GetDWordW <1610743820> ( _                    ' VTable offset = 76
     BYREF pszName AS WSTRINGZ _                        ' __in pszName LPCWSTR
   ) AS DWORD                                           ' __retval_out *pdwResult VT_UI4 <Dword>
   ' =====================================================================================
   METHOD SetDWordA <1610743821> ( _                    ' VTable offset = 80
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL dwValue AS DWORD _                           ' __in DWORD dwValue
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDWordW <1610743822> ( _                    ' VTable offset = 84
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYVAL dwValue AS DWORD _                           ' __in DWORD dwValue
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInterfaceA <1610743823> ( _                ' VTable offset = 88
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYREF iidDesired AS GUID _                         ' __in REFIID iidDesired
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunkResult
   ' =====================================================================================
   METHOD GetInterfaceW <1610743824> ( _                ' VTable offset = 92
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF iidDesired AS GUID _                         ' __in REFIID iidDesired
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunkResult
   ' =====================================================================================
   METHOD SetInterfaceA <1610743825> ( _                ' VTable offset = 96
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL punkValue AS IUnknown _                      ' __in IUnknown *punkValue
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInterfaceW <1610743826> ( _                ' VTable offset = 100
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYVAL punkValue AS IUnknown _                      ' __in IUnknown *punkValue
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISEODictionary_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventLock
' IID = {1B7058F0-AF88-11D0-A9EB-00AA00685C74}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEventLock_INTERFACE_DEFINED)
    %IEventLock_INTERFACE_DEFINED = 1

INTERFACE IEventLock $IID_IEventLock

   INHERIT IDispatch

   ' =====================================================================================
   METHOD LockRead <1610743808> ( _                     ' VTable offset = 28
     BYVAL iTimeoutMS AS LONG _                         ' __in int iTimeoutMS
   )                                                    ' void
   ' =====================================================================================
   METHOD UnlockRead <1610743809> ( _                   ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD LockWrite <1610743810> ( _                    ' VTable offset = 36
     BYVAL iTimeoutMS AS LONG _                         ' __in int iTimeoutMS
   )                                                    ' void
   ' =====================================================================================
   METHOD UnlockWrite <1610743811> ( _                  ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventLock_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISEORouter
' IID = {2B6AC0F0-7E03-11D0-A9E0-00AA00685C74}
' SEOCOM event router
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISEORouter_INTERFACE_DEFINED)
    %ISEORouter_INTERFACE_DEFINED = 1

INTERFACE ISEORouter $IID_ISEORouter

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Database ( _                            ' VTable offset = 12
   ) AS ISEODictionary                                  ' __retval_out ISEODictionary **ppdictResult
   ' =====================================================================================
   PROPERTY SET Database ( _                            ' VTable offset = 16
     BYVAL ppdictResult AS ISEODictionary _             ' __in ISEODictionary *ppdictResult
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Server ( _                              ' VTable offset = 20
   ) AS ISEODictionary                                  ' __retval_out ISEODictionary **ppdictResult
   ' =====================================================================================
   PROPERTY SET Server ( _                              ' VTable offset = 24
     BYVAL ppdictResult AS ISEODictionary _             ' __in ISEODictionary *ppdictResult
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Applications ( _                        ' VTable offset = 28
   ) AS ISEODictionary                                  ' __retval_out ISEODictionary **ppdictResult
   ' =====================================================================================
   METHOD GetDispatcher ( _                             ' VTable offset = 32
     BYREF iidEvent AS GUID _                           ' __in REFIID iidEvent
   , BYREF iidDesired AS GUID _                         ' __in REFIID iidDesired
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunkResult
   ' =====================================================================================
   METHOD GetDispatcherByCLSID ( _                      ' VTable offset = 36
     BYREF clsidDispatcher AS GUID _                    ' __in REFCLSID clsidDispatcher
   , BYREF iidEvent AS GUID _                           ' __in REFIID iidEvent
   , BYREF iidDesired AS GUID _                         ' __in REFIID iidDesired
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunkResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISEORouter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMCISMessageFilter
' IID = {F174E5B0-9046-11D0-A9E8-00AA00685C74}
' SEOCOM MCIS message filter.
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMCISMessageFilter_INTERFACE_DEFINED)
    %IMCISMessageFilter_INTERFACE_DEFINED = 1

INTERFACE IMCISMessageFilter $IID_IMCISMessageFilter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnMessage ( _                                 ' VTable offset = 12
     BYVAL pstreamMessage AS IStream _                  ' __in IStream *pstreamMessage IStream
   , BYVAL pdictEnvelope AS ISEODictionary _            ' __in ISEODictionary *pdictEnvelope
   , BYVAL pdictBinding AS ISEODictionary _             ' __in ISEODictionary *pdictBinding
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMCISMessageFilter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISEOBindingRuleEngine
' IID = {F2D1DAF0-2236-11D0-A9CE-00AA00685C74}
' SEOCOM Rule Engine
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISEOBindingRuleEngine_INTERFACE_DEFINED)
    %ISEOBindingRuleEngine_INTERFACE_DEFINED = 1

INTERFACE ISEOBindingRuleEngine $IID_ISEOBindingRuleEngine

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Evaluate ( _                                  ' VTable offset = 12
     BYVAL pdictEvent AS ISEODictionary _               ' __in ISEODictionary *pdictEvent
   , BYVAL pdictBinding AS ISEODictionary _             ' __in ISEODictionary *pdictBinding
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISEOBindingRuleEngine_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISEOEventSink
' IID = {1CAB4C20-94F4-11D0-A9E8-00AA00685C74}
' SEOCOM Event Notification
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISEOEventSink_INTERFACE_DEFINED)
    %ISEOEventSink_INTERFACE_DEFINED = 1

INTERFACE ISEOEventSink $IID_ISEOEventSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnEvent ( _                                   ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISEOEventSink_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISEORegDictionary
' IID = {347CACB0-2D1E-11D0-A9CF-00AA00685C74}
' SEOCOM extended ISEODictionary, implemented on the registry
' Attributes = 4096 [&H1000] [Dispatchable]
' Inherited interface = ISEODictionary
' ########################################################################################

#IF NOT %DEF(%ISEORegDictionary_INTERFACE_DEFINED)
    %ISEORegDictionary_INTERFACE_DEFINED = 1

'typedef SIZE_T SEO_HKEY;

INTERFACE ISEORegDictionary $IID_ISEORegDictionary

   INHERIT IDispatch

   ' =====================================================================================
   ' ISEODictionary Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYREF IN pvarName AS VARIANT _                     ' __in VARIANT *pvarName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarResult
   ' =====================================================================================
   PROPERTY SET Item <0> ( _                            ' VTable offset = 32
     BYREF IN pvarName AS VARIANT _                     ' __in VARIANT *pvarName
   , BYREF IN pvarResult AS VARIANT _                   ' __in VARIANT *pvarResult
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunkResult
   ' =====================================================================================
   METHOD GetVariantA <1610743811> ( _                  ' VTable offset = 40
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarResult
   ' =====================================================================================
   METHOD GetVariantW <1610743812> ( _                  ' VTable offset = 44
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarResult
   ' =====================================================================================
   METHOD SetVariantA <1610743813> ( _                  ' VTable offset = 48
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYREF pvarValue AS VARIANT _                       ' __in VARIANT *pvarValue
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVariantW <1610743814> ( _                  ' VTable offset = 52
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF pvarValue AS VARIANT _                       ' __in VARIANT *pvarValue
   )                                                    ' void
   ' =====================================================================================
   METHOD GetStringA <1610743815> ( _                   ' VTable offset = 56
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYREF pchCount AS DWORD _                          ' __inout DWORD *pchCount
   , BYREF pszResult AS ASCIIZ _                        ' __out LPSTR pszResult
   )                                                    ' void
   ' =====================================================================================
   METHOD GetStringW <1610743816> ( _                   ' VTable offset = 60
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF pchCount AS DWORD _                          ' __inout DWORD *pchCount
   , BYREF pszResult AS WSTRINGZ _                      ' __out LPWSTR pszResult
   )                                                    ' void
   ' =====================================================================================
   METHOD SetStringA <1610743817> ( _                   ' VTable offset = 64
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL chCount AS DWORD _                           ' __in DWORD chCount
   , BYREF pszValue AS ASCIIZ _                         ' __in LPCSTR pszValue
   )                                                    ' void
   ' =====================================================================================
   METHOD SetStringW <1610743818> ( _                   ' VTable offset = 68
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYVAL chCount AS DWORD _                           ' __in DWORD chCount
   , BYREF pszValue AS WSTRINGZ _                       ' __in LPCWSTR pszValue
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDWordA <1610743819> ( _                    ' VTable offset = 72
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   ) AS DWORD                                           ' __retval_out DWORD *pdwResult
   ' =====================================================================================
   METHOD GetDWordW <1610743820> ( _                    ' VTable offset = 76
     BYREF pszName AS WSTRINGZ _                        ' __in pszName LPCWSTR
   ) AS DWORD                                           ' __retval_out *pdwResult VT_UI4 <Dword>
   ' =====================================================================================
   METHOD SetDWordA <1610743821> ( _                    ' VTable offset = 80
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL dwValue AS DWORD _                           ' __in DWORD dwValue
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDWordW <1610743822> ( _                    ' VTable offset = 84
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYVAL dwValue AS DWORD _                           ' __in DWORD dwValue
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInterfaceA <1610743823> ( _                ' VTable offset = 88
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYREF iidDesired AS GUID _                         ' __in REFIID iidDesired
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunkResult
   ' =====================================================================================
   METHOD GetInterfaceW <1610743824> ( _                ' VTable offset = 92
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF iidDesired AS GUID _                         ' __in REFIID iidDesired
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunkResult
   ' =====================================================================================
   METHOD SetInterfaceA <1610743825> ( _                ' VTable offset = 96
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL punkValue AS IUnknown _                      ' __in IUnknown *punkValue
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInterfaceW <1610743826> ( _                ' VTable offset = 100
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYVAL punkValue AS IUnknown _                      ' __in IUnknown *punkValue
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ISEORegDictionary Methods
   ' =====================================================================================
   METHOD Load <1610809344> ( _                         ' VTable offset = 104
     BYREF pszMachine AS WSTRINGZ _                     ' __in LPCOLESTR pszMachine
   , BYVAL skBaseKey AS DWORD _                         ' __in SEO_HKEY skBaseKey
   , BYREF pszSubKey AS WSTRINGZ _                      ' __in LPCOLESTR pszSubKey
   , BYVAL pErrorLog AS IErrorLog _                     ' __in IErrorLog *pErrorLog
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISEORegDictionary_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISEOBindingConverter
' IID = {EE4E64D0-31F1-11D0-A9D0-00AA00685C74}
' SEOCOM Converter for Event Binding Data
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISEOBindingConverter_INTERFACE_DEFINED)
    %ISEOBindingConverter_INTERFACE_DEFINED = 1

INTERFACE ISEOBindingConverter $IID_ISEOBindingConverter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Convert ( _                                   ' VTable offset = 12
     BYVAL lEventData AS LONG _                         ' __in LONG lEventData
   , BYREF ppiResult AS ISEODictionary _                ' __retval_out ISEODictionary **ppiResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISEOBindingConverter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISEODispatcher
' IID = {8CA89880-31F1-11D0-A9D0-00AA00685C74}
' SEOCOM Binding Dispatcher
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISEODispatcher_INTERFACE_DEFINED)
    %ISEODispatcher_INTERFACE_DEFINED = 1

INTERFACE ISEODispatcher $IID_ISEODispatcher

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetContext ( _                                ' VTable offset = 12
     BYVAL piRouter AS ISEORouter _                     ' __in ISEORouter *piRouter
   , BYVAL pdictBP AS ISEODictionary _                  ' __in ISEODictionary *pdictBP
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISEODispatcher_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventDeliveryOptions
' IID = {0688A660-A3FF-11D0-A9E9-00AA00685C74}
' Provides access to event delivery options.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEventDeliveryOptions_INTERFACE_DEFINED)
    %IEventDeliveryOptions_INTERFACE_DEFINED = 1

INTERFACE IEventDeliveryOptions $IID_IEventDeliveryOptions

   INHERIT IDispatch

END INTERFACE

#ENDIF   ' /* __IEventDeliveryOptions_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventTypeSinks
' IID = {A1063F50-A654-11D0-A9EA-00AA00685C74}
' Provides access to a collection of sinks for an event type.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEventTypeSinks_INTERFACE_DEFINED)
    %IEventTypeSinks_INTERFACE_DEFINED = 1

INTERFACE IEventTypeSinks $IID_IEventTypeSinks

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 28
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS WSTRING                                         ' __retval_out BSTR *pstrTypeSink
   ' =====================================================================================
   METHOD Add <1610743809> ( _                          ' VTable offset = 32
     BYVAL pszTypeSink AS WSTRING _                     ' __in BSTR pszTypeSink
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <1610743810> ( _                       ' VTable offset = 36
     BYVAL pszTypeSink AS WSTRING _                     ' __in BSTR pszTypeSink
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Count <1610743811> ( _                  ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 44
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnkEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventTypeSinks_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventType
' IID = {4A993B80-A654-11D0-A9EA-00AA00685C74}
' Provides access to information about an event type.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEventType_INTERFACE_DEFINED)
    %IEventType_INTERFACE_DEFINED = 1

INTERFACE IEventType $IID_IEventType

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ID <1610743808> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pstrID
   ' =====================================================================================
   PROPERTY GET DisplayName <1610743809> ( _            ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pstrDisplayName
   ' =====================================================================================
   PROPERTY GET Sinks <1610743810> ( _                  ' VTable offset = 36
   ) AS IEventTypeSinks                                 ' __retval_out IEventTypeSinks **ppTypeSinks
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventType_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventPropertyBag
' IID = {AABB23E0-A705-11D0-A9EA-00AA00685C74}
' Implements IPropertyBag, in an automation-compatible way.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEventPropertyBag_INTERFACE_DEFINED)
    %IEventPropertyBag_INTERFACE_DEFINED = 1

INTERFACE IEventPropertyBag $IID_IEventPropertyBag

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 28
     BYREF pvarPropDesired AS VARIANT _                 ' __in VARIANT *pvarPropDesired
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarPropValue
   ' =====================================================================================
   METHOD Name <1610743809> ( _                         ' VTable offset = 32
     BYVAL lPropIndex AS LONG _                         ' __in long lPropIndex
   ) AS WSTRING                                         ' __retval_out BSTR *pstrPropName
   ' =====================================================================================
   METHOD Add <1610743810> ( _                          ' VTable offset = 36
     BYVAL pszPropName AS WSTRING _                     ' __in BSTR pszPropName
   , BYREF pvarPropValue AS VARIANT _                   ' __in VARIANT *pvarPropValue
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <1610743811> ( _                       ' VTable offset = 40
     BYREF pvarPropDesired AS VARIANT _                 ' __in VARIANT *pvarPropDesired
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Count <1610743812> ( _                  ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 48
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnkEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventPropertyBag_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventBinding
' IID = {8E398CE0-A64E-11D0-A9EA-00AA00685C74}
' Provides access to an event binding.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEventBinding_INTERFACE_DEFINED)
    %IEventBinding_INTERFACE_DEFINED = 1

INTERFACE IEventBinding $IID_IEventBinding

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ID <1610743808> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pstrBindingID
   ' =====================================================================================
   PROPERTY GET DisplayName <1610743809> ( _            ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pstrDisplayName
   ' =====================================================================================
   PROPERTY SET DisplayName <1610743809> ( _            ' VTable offset = 36
     BYVAL pstrDisplayName AS WSTRING _                 ' __in BSTR pstrDisplayName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_DisplayName <1610743809> ( _     ' VTable offset = 40
     BYREF IN pstrDisplayName AS WSTRING _              ' __in BSTR *pstrDisplayName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SinkClass <1610743812> ( _              ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pstrSinkClass
   ' =====================================================================================
   PROPERTY SET SinkClass <1610743812> ( _              ' VTable offset = 48
     BYVAL pstrSinkClass AS WSTRING _                   ' __in BSTR pstrSinkClass
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_SinkClass <1610743812> ( _       ' VTable offset = 52
     BYREF IN pstrSinkClass AS WSTRING _                ' __in BSTR *pstrSinkClass
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SinkProperties <1610743815> ( _         ' VTable offset = 56
   ) AS IEventPropertyBag                               ' __retval_out IEventPropertyBag **ppSinkProperties
   ' =====================================================================================
   PROPERTY GET SourceProperties <1610743816> ( _       ' VTable offset = 60
   ) AS IEventPropertyBag                               ' __retval_out IEventPropertyBag **ppSourceProperties
   ' =====================================================================================
   PROPERTY GET EventBindingProperties <1610743817> ( _  ' VTable offset = 64
   ) AS IEventPropertyBag                               ' __retval_out IEventPropertyBag **ppEventBindingProperties
   ' =====================================================================================
   PROPERTY GET Enabled <1610743818> ( _                ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <1610743818> ( _                ' VTable offset = 72
     BYVAL pbEnabled AS INTEGER _                       ' __in VARIANT_BOOL pbEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Enabled <1610743818> ( _         ' VTable offset = 76
     BYREF IN pbEnabled AS INTEGER _                    ' __in VARIANT_BOOL *pbEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Expiration <1610743821> ( _             ' VTable offset = 80
   ) AS DOUBLE                                          ' __retval_out DATE *pdateExpiration
   ' =====================================================================================
   PROPERTY SET Expiration <1610743821> ( _             ' VTable offset = 84
     BYVAL pdateExpiration AS DOUBLE _                  ' __in DATE pdateExpiration
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Expiration <1610743821> ( _      ' VTable offset = 88
     BYREF IN pdateExpiration AS DOUBLE _               ' __in DATE *pdateExpiration
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxFirings <1610743824> ( _             ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *plMaxFirings
   ' =====================================================================================
   PROPERTY SET MaxFirings <1610743824> ( _             ' VTable offset = 96
     BYVAL plMaxFirings AS LONG _                       ' __in long plMaxFirings
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_MaxFirings <1610743824> ( _      ' VTable offset = 100
     BYREF IN plMaxFirings AS LONG _                    ' __in long *plMaxFirings
   )                                                    ' void
   ' =====================================================================================
   METHOD Save <1610743827> ( _                         ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventBinding_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventBindings
' IID = {1080B910-A636-11D0-A9EA-00AA00685C74}
' Provides access to a collection of event bindings.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEventBindings_INTERFACE_DEFINED)
    %IEventBindings_INTERFACE_DEFINED = 1

INTERFACE IEventBindings $IID_IEventBindings

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 28
     BYREF pvarDesired AS VARIANT _                     ' __in VARIANT *pvarDesired
   ) AS IEventBinding                                   ' __retval_out IEventBinding **ppEventBinding
   ' =====================================================================================
   METHOD Add <1610743809> ( _                          ' VTable offset = 32
     BYVAL strBinding AS WSTRING _                      ' __in BSTR strBinding
   ) AS IEventBinding                                   ' __retval_out IEventBinding **ppBinding
   ' =====================================================================================
   METHOD Remove <1610743810> ( _                       ' VTable offset = 36
     BYREF pvarDesired AS VARIANT _                     ' __in VARIANT *pvarDesired
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Count <1610743811> ( _                  ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 44
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnkEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventBindings_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventTypes
' IID = {CAB29EF0-A64F-11D0-A9EA-00AA00685C74}
' Provides access to a collection of event types.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEventTypes_INTERFACE_DEFINED)
    %IEventTypes_INTERFACE_DEFINED = 1

INTERFACE IEventTypes $IID_IEventTypes

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 28
     BYREF pvarDesired AS VARIANT _                     ' __in VARIANT *pvarDesired
   ) AS IEventType                                      ' __retval_out IEventType **ppEventType
   ' =====================================================================================
   METHOD Add <1610743809> ( _                          ' VTable offset = 32
     BYVAL pszEventType AS WSTRING _                    ' __in BSTR pszEventType
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <1610743810> ( _                       ' VTable offset = 36
     BYVAL pszEventType AS WSTRING _                    ' __in BSTR pszEventType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Count <1610743811> ( _                  ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 44
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnkEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventTypes_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventBindingManager
' IID = {0B4CDBC0-A64F-11D0-A9EA-00AA00685C74}
' Provides access to an instance of a binding database.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEventBindingManager_INTERFACE_DEFINED)
    %IEventBindingManager_INTERFACE_DEFINED = 1

INTERFACE IEventBindingManager $IID_IEventBindingManager

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Bindings <1610743808> ( _               ' VTable offset = 28
     BYVAL pszEventType AS WSTRING _                    ' __in BSTR pszEventType
   ) AS IEventBindings                                  ' __retval_out IEventBindings **ppBindings
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnkEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventBindingManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventBindingManagerCopier
' IID = {64BAD540-F88D-11D0-AA14-00AA006BC80B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEventBindingManagerCopier_INTERFACE_DEFINED)
    %IEventBindingManagerCopier_INTERFACE_DEFINED = 1

$IID_IEventBindingManagerCopier = GUID$("{64BAD540-F88D-11D0-AA14-00AA006BC80B}")

INTERFACE IEventBindingManagerCopier $IID_IEventBindingManagerCopier

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Copy ( _                                      ' VTable offset = 28
     BYVAL lTimeout AS LONG _                           ' __in long lTimeout
   ) AS IEventBindingManager                            ' __retval_out IEventBindingManager **ppBindingManager
   ' =====================================================================================
   METHOD EmptyCopy ( _                                 ' VTable offset = 32
   ) AS IEventBindingManager                            ' __retval_out IEventBindingManager **ppBindingManager
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventBindingManagerCopier_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventRouter
' IID = {1A00B970-EDA0-11D0-AA10-00AA006BC80B}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEventRouter_INTERFACE_DEFINED)
    %IEventRouter_INTERFACE_DEFINED = 1

INTERFACE IEventRouter $IID_IEventRouter

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Database ( _                            ' VTable offset = 12
   ) AS IEventBindingManager                            ' __retval_out IEventBindingManager **ppBindingManager
   ' =====================================================================================
   PROPERTY SET Database ( _                            ' VTable offset = 16
     BYVAL ppBindingManager AS IEventBindingManager _   ' __in IEventBindingManager *ppBindingManager
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Database ( _                     ' VTable offset = 20
     BYREF IN ppBindingManager AS IEventBindingManager _ ' __in IEventBindingManager **ppBindingManager
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDispatcher ( _                             ' VTable offset = 24
     BYREF iidEvent AS GUID _                           ' __in REFIID iidEvent
   , BYREF iidDesired AS GUID _                         ' __in REFIID iidDesired
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunkResult
   ' =====================================================================================
   METHOD GetDispatcherByCLSID ( _                      ' VTable offset = 28
     BYREF clsidDispatcher AS GUID _                    ' __in REFCLSID clsidDispatcher
   , BYREF iidEvent AS GUID _                           ' __in REFIID iidEvent
   , BYREF iidDesired AS GUID _                         ' __in REFIID iidDesired
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunkResult
   ' =====================================================================================
   METHOD GetDispatcherByClassFactory ( _               ' VTable offset = 32
     BYREF clsidDispatcher AS GUID _                    ' __in REFCLSID clsidDispatcher
   , BYVAL piClassFactory AS IClassFactory _            ' __in IClassFactory *piClassFactory
   , BYREF iidEvent AS GUID _                           ' __in REFIID iidEvent
   , BYREF iidDesired AS GUID _                         ' __in REFIID iidDesired
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunkResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventRouter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventDispatcher
' IID = {C980F550-ED9E-11D0-AA10-00AA006BC80B}
' Dispatches an event.
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEventDispatcher_INTERFACE_DEFINED)
    %IEventDispatcher_INTERFACE_DEFINED = 1

INTERFACE IEventDispatcher $IID_IEventDispatcher

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetContext ( _                                ' VTable offset = 12
     BYREF guidEventType AS GUID _                      ' __in REFGUID *guidEventType
   , BYVAL piRouter AS IEventRouter _                   ' __in IEventRouter *piRouter
   , BYVAL pBindings AS IEventBindings _                ' __in IEventBindings *pBindings
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventDispatcher_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventSource
' IID = {B1DCB040-A652-11D0-A9EA-00AA00685C74}
' Provides information about an event source.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEventSource_INTERFACE_DEFINED)
    %IEventSource_INTERFACE_DEFINED = 1

INTERFACE IEventSource $IID_IEventSource

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ID <1610743808> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pstrID
   ' =====================================================================================
   PROPERTY GET DisplayName <1610743809> ( _            ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pstrDisplayName
   ' =====================================================================================
   PROPERTY SET DisplayName <1610743809> ( _            ' VTable offset = 36
     BYVAL pstrDisplayName AS WSTRING _                 ' __in BSTR pstrDisplayName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_DisplayName <1610743809> ( _     ' VTable offset = 40
     BYREF IN pstrDisplayName AS WSTRING _              ' __in BSTR *pstrDisplayName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BindingManagerMoniker <1610743812> ( _  ' VTable offset = 44
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnkMoniker
   ' =====================================================================================
   PROPERTY SET BindingManagerMoniker <1610743812> ( _  ' VTable offset = 48
     BYVAL ppUnkMoniker AS IUnknown _                   ' __in IUnknown *ppUnkMoniker
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_BindingManagerMoniker <1610743812> ( _  ' VTable offset = 52
     BYREF IN ppUnkMoniker AS IUnknown _                ' __in IUnknown **ppUnkMoniker
   )                                                    ' void
   ' =====================================================================================
   METHOD GetBindingManager <1610743815> ( _            ' VTable offset = 56
   ) AS IEventBindingManager                            ' __retval_out IEventBindingManager **ppBindingManager
   ' =====================================================================================
   PROPERTY GET Properties <1610743816> ( _             ' VTable offset = 60
   ) AS IEventPropertyBag                               ' __retval_out IEventPropertyBag **ppProperties
   ' =====================================================================================
   METHOD Save <1610743817> ( _                         ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventSource_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventSources
' IID = {73E8C930-A652-11D0-A9EA-00AA00685C74}
' Provides access to a collection of event sources.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEventSources_INTERFACE_DEFINED)
    %IEventSources_INTERFACE_DEFINED = 1

INTERFACE IEventSources $IID_IEventSources

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 28
     BYREF pvarDesired AS VARIANT _                     ' __in VARIANT *pvarDesired
   ) AS IEventSource                                    ' __retval_out IEventSource **ppSource
   ' =====================================================================================
   METHOD Add <1610743809> ( _                          ' VTable offset = 32
     BYVAL pszSource AS WSTRING _                       ' __in BSTR pszSource
   ) AS IEventSource                                    ' __retval_out IEventSource **ppSource
   ' =====================================================================================
   METHOD Remove <1610743810> ( _                       ' VTable offset = 36
     BYREF pvarDesired AS VARIANT _                     ' __in VARIANT *pvarDesired
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Count <1610743811> ( _                  ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 44
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnkEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventSources_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventSourceType
' IID = {063A62E0-A652-11D0-A9EA-00AA00685C74}
' Provides access to information about a source type.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEventSourceType_INTERFACE_DEFINED)
    %IEventSourceType_INTERFACE_DEFINED = 1

INTERFACE IEventSourceType $IID_IEventSourceType

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ID <1610743808> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pstrID
   ' =====================================================================================
   PROPERTY GET DisplayName <1610743809> ( _            ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pstrDisplayName
   ' =====================================================================================
   PROPERTY SET DisplayName <1610743809> ( _            ' VTable offset = 36
     BYVAL pstrDisplayName AS WSTRING _                 ' __in BSTR pstrDisplayName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_DisplayName <1610743809> ( _     ' VTable offset = 40
     BYREF IN pstrDisplayName AS WSTRING _              ' __in BSTR *pstrDisplayName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EventTypes <1610743812> ( _             ' VTable offset = 44
   ) AS IEventTypes                                     ' __retval_out IEventTypes **ppEventTypes
   ' =====================================================================================
   PROPERTY GET Sources <1610743813> ( _                ' VTable offset = 48
   ) AS IEventSources                                   ' __retval_out IEventSources **ppSources
   ' =====================================================================================
   METHOD Save <1610743814> ( _                         ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventSourceType_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventSourceTypes
' IID = {CAF30FD0-A651-11D0-A9EA-00AA00685C74}
' Provides access to a collection of event source types.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEventSourceTypes_INTERFACE_DEFINED)
    %IEventSourceTypes_INTERFACE_DEFINED = 1

INTERFACE IEventSourceTypes $IID_IEventSourceTypes

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 28
     BYREF pvarDesired AS VARIANT _                     ' __in VARIANT *pvarDesired
   ) AS IEventSourceType                                ' __retval_out IEventSourceType **ppSourceType
   ' =====================================================================================
   METHOD Add <1610743809> ( _                          ' VTable offset = 32
     BYVAL pszSourceType AS WSTRING _                   ' __in BSTR pszSourceType
   ) AS IEventSourceType                                ' __retval_out IEventSourceType **ppSourceType
   ' =====================================================================================
   METHOD Remove <1610743810> ( _                       ' VTable offset = 36
     BYREF pvarDesired AS VARIANT _                     ' __in VARIANT *pvarDesired
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Count <1610743811> ( _                  ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 44
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnkEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventSourceTypes_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventManager
' IID = {5F6012B0-A651-11D0-A9EA-00AA00685C74}
' Provides access to registered source types, and facilities for firing events.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEventManager_INTERFACE_DEFINED)
    %IEventManager_INTERFACE_DEFINED = 1

INTERFACE IEventManager $IID_IEventManager

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET SourceTypes <1610743808> ( _            ' VTable offset = 28
   ) AS IEventSourceTypes                               ' __retval_out IEventSourceTypes **ppSourceTypes
   ' =====================================================================================
   METHOD CreateSink <1610743809> ( _                   ' VTable offset = 32
     BYVAL pBinding AS IEventBinding _                  ' __in IEventBinding *pBinding
   , BYVAL pDeliveryOptions AS IEventDeliveryOptions _  ' __in IEventDeliveryOptions *pDeliveryOptions
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnkSink
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventDatabasePlugin
' IID = {4915FB10-AF97-11D0-A9EB-00AA00685C74}
' Provides facilities for pluggable binding database stores.
' Attributes = 272 [&H110] [Hidden] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEventDatabasePlugin_INTERFACE_DEFINED)
    %IEventDatabasePlugin_INTERFACE_DEFINED = 1

INTERFACE IEventDatabasePlugin $IID_IEventDatabasePlugin

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Database ( _                            ' VTable offset = 12
   ) AS IEventPropertyBag                               ' __retval_out IEventPropertyBag **ppDatabase
   ' =====================================================================================
   PROPERTY SET Database ( _                            ' VTable offset = 16
     BYVAL ppDatabase AS IEventPropertyBag _            ' __in IEventPropertyBag *ppDatabase
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Database ( _                     ' VTable offset = 20
     BYREF IN ppDatabase AS IEventPropertyBag _         ' __in IEventPropertyBag **ppDatabase
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name ( _                                ' VTable offset = 24
   ) AS WSTRING                                         ' __retval_out BSTR *pstrName
   ' =====================================================================================
   PROPERTY SET Name ( _                                ' VTable offset = 28
     BYVAL pstrName AS WSTRING _                        ' __in BSTR pstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Name ( _                         ' VTable offset = 32
     BYREF IN pstrName AS WSTRING _                     ' __in BSTR *pstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Parent ( _                              ' VTable offset = 36
   ) AS IEventPropertyBag                               ' __retval_out IEventPropertyBag **ppParent
   ' =====================================================================================
   PROPERTY SET Parent ( _                              ' VTable offset = 40
     BYVAL ppParent AS IEventPropertyBag _              ' __in IEventPropertyBag *ppParent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Parent ( _                       ' VTable offset = 44
     BYREF IN ppParent AS IEventPropertyBag _           ' __in IEventPropertyBag **ppParent
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventDatabasePlugin_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventDatabaseManager
' IID = {ADC25B30-CBD8-11D0-A9F8-00AA00685C74}
' Provides facilities for managing a binding database.
' Attributes = 4352 [&H1100] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEventDatabaseManager_INTERFACE_DEFINED)
    %IEventDatabaseManager_INTERFACE_DEFINED = 1

INTERFACE IEventDatabaseManager $IID_IEventDatabaseManager

   INHERIT IDispatch

   ' =====================================================================================
   METHOD CreateDatabase <1610743808> ( _               ' VTable offset = 28
     BYVAL strPath AS WSTRING _                         ' __in BSTR strPath
   ) AS IUnknown                                        ' __retval_out IUnknown **ppMonDatabase
   ' =====================================================================================
   METHOD EraseDatabase <1610743809> ( _                ' VTable offset = 32
     BYVAL strPath AS WSTRING _                         ' __in BSTR strPath
   )                                                    ' void
   ' =====================================================================================
   METHOD MakeVServerPath <1610743810> ( _              ' VTable offset = 36
     BYVAL strService AS WSTRING _                      ' __in BSTR strService
   , BYVAL lInstance AS LONG _                          ' __in long lInstance
   ) AS WSTRING                                         ' __retval_out BSTR *pstrPath
   ' =====================================================================================
   METHOD MakeVRootPath <1610743811> ( _                ' VTable offset = 40
     BYVAL strService AS WSTRING _                      ' __in BSTR strService
   , BYVAL lInstance AS LONG _                          ' __in long lInstance
   , BYVAL strRoot AS WSTRING _                         ' __in BSTR strRoot
   ) AS WSTRING                                         ' __retval_out BSTR *pstrPath
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventDatabaseManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventUtil
' IID = {C61670E0-CD6E-11D0-A9F8-00AA00685C74}
' Provides utility functions.
' Attributes = 4352 [&H1100] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEventUtil_INTERFACE_DEFINED)
    %IEventUtil_INTERFACE_DEFINED = 1

INTERFACE IEventUtil $IID_IEventUtil

   INHERIT IDispatch

   ' =====================================================================================
   METHOD DisplayNameFromMoniker <1610743808> ( _       ' VTable offset = 28
     BYVAL pUnkMoniker AS IUnknown _                    ' __in IUnknown *pUnkMoniker
   ) AS WSTRING                                         ' __retval_out BSTR *pstrDisplayName
   ' =====================================================================================
   METHOD MonikerFromDisplayName <1610743809> ( _       ' VTable offset = 32
     BYVAL strDisplayName AS WSTRING _                  ' __in BSTR strDisplayName
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnkMoniker
   ' =====================================================================================
   METHOD ObjectFromMoniker <1610743810> ( _            ' VTable offset = 36
     BYVAL pUnkMoniker AS IUnknown _                    ' __in IUnknown *pUnkMoniker
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnkObject
   ' =====================================================================================
   METHOD GetNewGUID <1610743811> ( _                   ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pstrGUID
   ' =====================================================================================
   METHOD CopyPropertyBag <1610743812> ( _              ' VTable offset = 44
     BYVAL pUnkInput AS IUnknown _                      ' __in IUnknown *pUnkInput
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnkOutput
   ' =====================================================================================
   METHOD CopyPropertyBagShallow <1610743813> ( _       ' VTable offset = 48
     BYVAL pUnkInput AS IUnknown _                      ' __in IUnknown *pUnkInput
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnkOutput
   ' =====================================================================================
   METHOD DispatchFromObject <1610743814> ( _           ' VTable offset = 52
     BYVAL pUnkObject AS IUnknown _                     ' __in IUnknown *pUnkObject
   ) AS IDispatch                                       ' __retval_out IDispatch **ppDispOutput
   ' =====================================================================================
   METHOD GetIndexedGUID <1610743815> ( _               ' VTable offset = 56
     BYVAL strGUID AS WSTRING _                         ' __in BSTR strGUID
   , BYVAL lValue AS LONG _                             ' __in long lValue
   ) AS WSTRING                                         ' __retval_out BSTR *pstrResult
   ' =====================================================================================
   METHOD RegisterSource <1610743816> ( _               ' VTable offset = 60
     BYVAL strSourceType AS WSTRING _                   ' __in BSTR strSourceType
   , BYVAL strSource AS WSTRING _                       ' __in BSTR strSource
   , BYVAL lInstance AS LONG _                          ' __in long lInstance
   , BYVAL strService AS WSTRING _                      ' __in BSTR strService
   , BYVAL strVRoot AS WSTRING _                        ' __in BSTR strVRoot
   , BYVAL strDatabaseManager AS WSTRING _              ' __in BSTR strDatabaseManager
   , BYVAL strDisplayName AS WSTRING _                  ' __in BSTR strDisplayName
   ) AS IEventBindingManager                            ' __retval_out IEventBindingManager **ppBindingManager
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventUtil_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventComCat
' IID = {65A70EC0-CD87-11D0-A9F8-00AA00685C74}
' Provides access to component categories.
' Attributes = 4352 [&H1100] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEventComCat_INTERFACE_DEFINED)
    %IEventComCat_INTERFACE_DEFINED = 1

INTERFACE IEventComCat $IID_IEventComCat

   INHERIT IDispatch

   ' =====================================================================================
   METHOD RegisterCategory <1610743808> ( _             ' VTable offset = 28
     BYVAL pszCategory AS WSTRING _                     ' __in BSTR pszCategory
   , BYVAL pszDescription AS WSTRING _                  ' __in BSTR pszDescription
   , BYVAL lcidLanguage AS LONG _                       ' __in long lcidLanguage
   )                                                    ' void
   ' =====================================================================================
   METHOD UnRegisterCategory <1610743809> ( _           ' VTable offset = 32
     BYVAL pszCategory AS WSTRING _                     ' __in BSTR pszCategory
   )                                                    ' void
   ' =====================================================================================
   METHOD RegisterClassImplementsCategory <1610743810> ( _  ' VTable offset = 36
     BYVAL pszClass AS WSTRING _                        ' __in BSTR pszClass
   , BYVAL pszCategory AS WSTRING _                     ' __in BSTR pszCategory
   )                                                    ' void
   ' =====================================================================================
   METHOD UnRegisterClassImplementsCategory <1610743811> ( _  ' VTable offset = 40
     BYVAL pszClass AS WSTRING _                        ' __in BSTR pszClass
   , BYVAL pszCategory AS WSTRING _                     ' __in BSTR pszCategory
   )                                                    ' void
   ' =====================================================================================
   METHOD RegisterClassRequiresCategory <1610743812> ( _  ' VTable offset = 44
     BYVAL pszClass AS WSTRING _                        ' __in BSTR pszClass
   , BYVAL pszCategory AS WSTRING _                     ' __in BSTR pszCategory
   )                                                    ' void
   ' =====================================================================================
   METHOD UnRegisterClassRequiresCategory <1610743813> ( _  ' VTable offset = 48
     BYVAL pszClass AS WSTRING _                        ' __in BSTR pszClass
   , BYVAL pszCategory AS WSTRING _                     ' __in BSTR pszCategory
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCategories <1610743814> ( _                ' VTable offset = 52
   ) AS DWORD                                           ' __retval_out SAFEARRAY **psaCategories
   ' =====================================================================================
   METHOD GetCategoryDescription <1610743815> ( _       ' VTable offset = 56
     BYVAL pszCategory AS WSTRING _                     ' __in BSTR pszCategory
   , BYVAL lcidLanguage AS LONG _                       ' __in long lcidLanguage
   ) AS WSTRING                                         ' __retval_out BSTR *pstrDescription
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventComCat_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISEOInitObject
' IID = {9BB6AAB0-AF6D-11D0-8BD2-00C04FD42E37}
' Same interface as IPersistPropertyBag but uses shallow binding.
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IPersistPropertyBag
' ########################################################################################

#IF NOT %DEF(%ISEOInitObject_INTERFACE_DEFINED)
    %ISEOInitObject_INTERFACE_DEFINED = 1

INTERFACE ISEOInitObject $IID_ISEOInitObject

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersist Methods
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID *pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPersistPropertyBag Methods
   ' =====================================================================================
   METHOD InitNew ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 20
     BYVAL pPropBag AS IPropertyBag _                   ' __in IPropertyBag *pPropBag
   , BYVAL pErrorLog AS IErrorLog _                     ' __in IErrorLog *pErrorLog
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 24
     BYVAL pPropBag AS IPropertyBag _                   ' __in IPropertyBag *pPropBag
   , BYVAL fClearDirty AS LONG _                        ' __in BOOL fClearDirty
   , BYVAL fSaveAllProperties AS LONG _                 ' __in BOOL fSaveAllProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISEOInitObject_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventRuleEngine
' IID = {DA816090-F343-11D0-AA14-00AA006BC80B}
' Evaluates events against rules.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEventRuleEngine_INTERFACE_DEFINED)
    %IEventRuleEngine_INTERFACE_DEFINED = 1

INTERFACE IEventRuleEngine $IID_IEventRuleEngine

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Evaluate ( _                                  ' VTable offset = 12
     BYVAL pEvent AS IUnknown _                         ' __in IUnknown *pEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventRuleEngine_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventPersistBinding
' IID = {E9311660-1A98-11D1-AA26-00AA006BC80B}
' Persists an object to/from a binding.
' Inherited interface = IPersist
' ########################################################################################

#IF NOT %DEF(%IEventPersistBinding_INTERFACE_DEFINED)
    %IEventPersistBinding_INTERFACE_DEFINED = 1

INTERFACE IEventPersistBinding $IID_IEventPersistBinding

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersist Methods
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID *pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IEventPersistBinding Methods
   ' =====================================================================================
   METHOD IsDirty ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 20
     BYVAL piBinding AS IEventBinding _                 ' __in IEventBinding *piBinding
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 24
     BYVAL piBinding AS IEventBinding _                 ' __in IEventBinding *piBinding
   , BYVAL fClearDirty AS INTEGER _                     ' __in VARIANT_BOOL fClearDirty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventPersistBinding_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventSinkNotify
' IID = {BDF065B0-F346-11D0-AA14-00AA006BC80B}
' Generic sink interface.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEventSinkNotify_INTERFACE_DEFINED)
    %IEventSinkNotify_INTERFACE_DEFINED = 1

INTERFACE IEventSinkNotify $IID_IEventSinkNotify

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnEvent ( _                                   ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventSinkNotify_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventSinkNotifyDisp
' IID = {33A79660-F347-11D0-AA14-00AA006BC80B}
' Generic sink interface (IDispatch).
' Attributes = 4096 [&H1000] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEventSinkNotifyDisp_INTERFACE_DEFINED)
    %IEventSinkNotifyDisp_INTERFACE_DEFINED = 1

INTERFACE IEventSinkNotifyDisp $IID_IEventSinkNotifyDisp

   INHERIT IDispatch

   ' =====================================================================================
   METHOD OnEvent <0> ( _                               ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventSinkNotifyDisp_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventIsCacheable
' IID = {22E0F830-1E81-11D1-AA29-00AA006BC80B}
' Determine whether or not the object should be cached
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEventIsCacheable_INTERFACE_DEFINED)
    %IEventIsCacheable_INTERFACE_DEFINED = 1

INTERFACE IEventIsCacheable $IID_IEventIsCacheable

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsCacheable ( _                               ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventIsCacheable_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventCreateOptions
' IID = {C0287BFE-EF7F-11D1-9FFF-00C04FA37348}
' Provide options for creating objects.
' Attributes = 4112 [&H1010] [Hidden] [Dispatchable]
' Inherited interface = IEventDeliveryOptions
' ########################################################################################

#IF NOT %DEF(%IEventCreateOptions_INTERFACE_DEFINED)
    %IEventCreateOptions_INTERFACE_DEFINED = 1

INTERFACE IEventCreateOptions $IID_IEventCreateOptions

   INHERIT IDispatch

   ' =====================================================================================
   ' IEventDeliveryOptions Methods
   ' =====================================================================================

   ' This interface only has the inherited IDispatch methods.

   ' =====================================================================================
   ' IEventCreateOptions Methods
   ' =====================================================================================
   METHOD CreateBindCtx <1610809344> ( _                ' VTable offset = 28
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   , BYREF ppBindCtx AS IBindCtx _                      ' __out IBindCtx **ppBindCtx
   )                                                    ' void
   ' =====================================================================================
   METHOD MkParseDisplayName <1610809345> ( _           ' VTable offset = 32
     BYVAL pBindCtx AS IBindCtx _                       ' __in IBindCtx *pBindCtx
   , BYREF pszUserName AS WSTRINGZ _                    ' __in LPCOLESTR pszUserName
   , BYREF pchEaten AS DWORD _                          ' __out ULONG *pchEaten
   , BYREF ppMoniker AS IMoniker _                      ' __out IMoniker **ppMoniker
   )                                                    ' void
   ' =====================================================================================
   METHOD BindToObject <1610809346> ( _                 ' VTable offset = 36
     BYVAL pMoniker AS IMoniker _                       ' __in IMoniker *pMoniker
   , BYVAL pBindCtx AS IBindCtx _                       ' __in IBindCtx *pBindCtx
   , BYVAL pmkLeft AS IMoniker _                        ' __in IMoniker *pmkLeft
   , BYREF riidResult AS GUID _                         ' __in REFIID riidResult
   , BYREF ppvResult AS DWORD _                         ' __out LPVOID *ppvResult
   )                                                    ' void
   ' =====================================================================================
   METHOD CoCreateInstance <1610809347> ( _             ' VTable offset = 40
     BYREF rclsidDesired AS GUID _                      ' __in REFCLSID rclsidDesired
   , BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYVAL dwClsCtx AS DWORD _                          ' __in DWORD dwClsCtx
   , BYREF riidResult AS GUID _                         ' __in REFIID riidResult
   , BYREF ppvResult AS DWORD _                         ' __out LPVOID *ppvResult
   )                                                    ' void
   ' =====================================================================================
   METHOD Init <1610809348> ( _                         ' VTable offset = 44
     BYREF riidObject AS GUID _                         ' __in REFIID riidObject
   , BYREF ppUnkObject AS IUnknown _                    ' __inout IUnknown **ppUnkObject
   , BYVAL pBinding AS IEventBinding _                  ' __in IEventBinding *pBinding
   , BYVAL pInitProps AS IUnknown _                     ' __in IUnknown *pInitProps
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventCreateOptions_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventDispatcherChain
' IID = {58A90754-FB15-11D1-A00C-00C04FA37348}
' Provide chaining of dispatcher instances.
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEventDispatcherChain_INTERFACE_DEFINED)
    %IEventDispatcherChain_INTERFACE_DEFINED = 1

INTERFACE IEventDispatcherChain $IID_IEventDispatcherChain

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetPrevious ( _                               ' VTable offset = 12
     BYVAL pUnkPrevious AS IUnknown _                   ' __in IUnknown *pUnkPrevious
   , BYREF ppUnkPreload AS IUnknown _                   ' __out IUnknown **ppUnkPreload
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventDispatcherChain_INTERFACE_DEFINED__ */

'#ifndef __SEOLib_LIBRARY_DEFINED__
'#define __SEOLib_LIBRARY_DEFINED__

%SEO_S_MOREDATA       = &H41001&
%SEO_E_NOTPRESENT     = &H80041002&
%SEO_E_TIMEOUT        = &H80041003&
%SEO_S_DONEPROCESSING = &H80041004&
%EVENTS_E_BADDATA     = &H80041005&
%EVENTS_E_TIMEOUT     = &H80041006&
%EVENTS_E_DISABLED    = &H80041007&

'#endif /* __SEOLib_LIBRARY_DEFINED__ */


DECLARE FUNCTION MCISInitSEOA IMPORT "seo.dll" ALIAS "MCISInitSEOA" ( _
   BYREF pszService AS ASCIIZ _                         ' __in LPCSTR pszService
 , BYVAL dwVirtualServer AS DWORD _                     ' __in DWORD dwVirtualServer
 , BYREF pprouterResult AS ISEORouter _                 ' __inout_opt ISEORouter **pprouterResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MCISInitSEOW IMPORT "seo.dll" ALIAS "MCISInitSEOW" ( _
   BYREF pszService AS WSTRINGZ _                       ' __in LPCWSTR pszService
 , BYVAL dwVirtualServer AS DWORD _                     ' __in DWORD dwVirtualServer
 , BYREF pprouterResult AS ISEORouter _                 ' __inout_opt ISEORouter **pprouterResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SEOCreateDictionaryFromMultiSzA IMPORT "seo.dll" ALIAS "SEOCreateDictionaryFromMultiSzA" ( _
   BYVAL dwCount AS DWORD _                             ' __in DWORD dwCount
 , BYREF ppszNames AS ASCIIZ _                          ' __in_opt LPCSTR *ppszNames
 , BYREF ppszValues AS ASCIIZ _                         ' __in_opt LPCSTR *ppszValues
 , BYVAL bCopy AS LONG _                                ' __in BOOL bCopy
 , BYVAL bReadOnly AS LONG _                            ' __in BOOL bReadOnly
 , BYREF ppdictResult AS ISEODictionary _               ' __out_opt ISEODictionary **ppdictResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SEOCreateDictionaryFromMultiSzW IMPORT "seo.dll" ALIAS "SEOCreateDictionaryFromMultiSzW" ( _
   BYVAL dwCount AS DWORD _                             ' __in DWORD dwCount
 , BYREF ppszNames AS WSTRINGZ _                        ' __in_opt LPCWSTR *ppszNames
 , BYREF ppszValues AS WSTRINGZ _                       ' __in_opt LPCWSTR *ppszValues
 , BYVAL bCopy AS LONG _                                ' __in BOOL bCopy
 , BYVAL bReadOnly AS LONG _                            ' __in BOOL bReadOnly
 , BYREF ppdictResult AS ISEODictionary _               ' __out_opt ISEODictionary **ppdictResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SEOCreateMultiSzFromDictionaryA IMPORT "seo.dll" ALIAS "SEOCreateMultiSzFromDictionaryA" ( _
   BYVAL pdictDictionary AS ISEODictionary _            ' __in ISEODictionary *pdictDictionary
 , BYREF pdwCount AS DWORD _                            ' __out DWORD *pdwCount
 , BYREF pppszNames AS ASCIIZ _                         ' __deref_out_ecount(*pdwCount) LPSTR **pppszNames
 , BYREF pppszValues AS ASCIIZ _                        ' __deref_out_ecount(*pdwCount) LPSTR **pppszValues
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SEOCreateMultiSzFromDictionaryW IMPORT "seo.dll" ALIAS "SEOCreateMultiSzFromDictionaryW" ( _
   BYVAL pdictDictionary AS ISEODictionary _            ' __in ISEODictionary *pdictDictionary
 , BYREF pdwCount AS DWORD _                            ' __out DWORD *pdwCount
 , BYREF pppszNames AS DWORD _                          ' __deref_out_ecount(*pdwCount) LPWSTR **pppszNames
 , BYREF pppszValues AS DWORD _                         ' __deref_out_ecount(*pdwCount) LPWSTR **pppszValues
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MCISGetBindingInMetabaseA IMPORT "seo.dll" ALIAS "MCISGetBindingInMetabaseA" ( _
   BYREF pszService AS ASCIIZ _                         ' __in LPCSTR pszService
 , BYVAL dwVirtualServer AS DWORD _                     ' __in DWORD dwVirtualServer
 , BYREF guidEventSource AS GUID _                      ' __in REFGUID guidEventSource
 , BYREF pszBinding AS ASCIIZ _                         ' __in LPCSTR pszBinding
 , BYVAL bCreate AS LONG _                              ' __in BOOL bCreate
 , BYVAL fLock AS LONG _                                ' __in BOOL fLock
 , BYREF ppdictResult AS ISEODictionary _               ' __out_opt ISEODictionary **ppdictResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MCISGetBindingInMetabaseW IMPORT "seo.dll" ALIAS "MCISGetBindingInMetabaseW" ( _
   BYREF pszService AS WSTRINGZ _                       ' __in LPCWSTR pszService
 , BYVAL dwVirtualServer AS DWORD _                     ' __in DWORD dwVirtualServer
 , BYREF guidEventSource AS GUID _                      ' __in REFGUID guidEventSource
 , BYREF pszBinding AS WSTRINGZ _                       ' __in LPCWSTR pszBinding
 , BYVAL bCreate AS LONG _                              ' __in BOOL bCreate
 , BYVAL fLock AS LONG _                                ' __in BOOL fLock
 , BYREF ppdictResult AS ISEODictionary _               ' __out_opt ISEODictionary **ppdictResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SEOListenForEvent IMPORT "seo.dll" ALIAS "SEOListenForEvent" ( _
   BYVAL piRouter AS ISEORouter _                       ' __in ISEORouter *piRouter
 , BYVAL hEvent AS DWORD _                              ' __in HANDLE hEvent
 , BYVAL psinkEventSink AS ISEOEventSink _              ' __in ISEOEventSink *psinkEventSink
 , BYVAL bOnce AS LONG _                                ' __in BOOL bOnce
 , BYREF pdwListenHandle AS DWORD _                     ' __in DWORD *pdwListenHandle
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SEOCancelListenForEvent IMPORT "seo.dll" ALIAS "SEOCancelListenForEvent" ( _
   BYVAL dwHandle AS DWORD _                            ' __in DWORD dwHandle
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SEOCreateIStreamFromFileA IMPORT "seo.dll" ALIAS "SEOCreateIStreamFromFileA" ( _
   BYVAL hFile AS DWORD _                               ' __in DWORD hFile
 , BYREF pszFile AS ASCIIZ _                            ' __in LPCSTR pszFile
 , BYREF ppstreamResult AS IStream _                    ' __out_opt IStream **ppstreamResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SEOCreateIStreamFromFileW IMPORT "seo.dll" ALIAS "SEOCreateIStreamFromFileW" ( _
   BYVAL hFile AS DWORD _                               ' __in DWORD hFile
 , BYREF pszFile AS WSTRINGZ _                          ' __in LPCWSTR pszFile
 , BYREF ppstreamResult AS IStream _                    ' __out_opt IStream **ppstreamResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SEOCopyDictionary IMPORT "seo.dll" ALIAS "SEOCopyDictionary" ( _
   BYVAL pdictIn AS ISEODictionary _                    ' __in ISEODictionary *pdictIn
 , BYREF ppdictResult AS ISEODictionary _               ' __inout_opt ISEODictionary **ppdictResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SEOCreateDictionaryFromIStream IMPORT "seo.dll" ALIAS "SEOCreateDictionaryFromIStream" ( _
   BYVAL pstreamIn AS IStream _                         ' __inout_opt IStream *pstreamIn
 , BYREF ppdictResult AS ISEODictionary _               ' __out_opt ISEODictionary **ppdictResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SEOWriteDictionaryToIStream IMPORT "seo.dll" ALIAS "SEOWriteDictionaryToIStream" ( _
   BYVAL pdictIn AS ISEODictionary _                    ' __in ISEODictionary *pdictIn
 , BYVAL pstreamOut AS ISTream _                        ' __in IStream *pstreamOut
 ) AS LONG                                              ' HRESULT


' ########################################################################################
' Class CIEventNotifyBindingChange
' Interface name = IEventNotifyBindingChange
' IID = {08F4F2A0-DC5B-11D0-AA0F-00AA006BC80B}
' Receives notifications of changes to a binding database.
' Attributes = 16 [&H10] [Hidden]
' ########################################################################################

'CLASS CIEventNotifyBindingChange GUID$("{FE080348-ED51-4B05-97DA-585B2CDDFCE5}")

'INTERFACE IEventNotifyBindingChangeImpl GUID$("{08F4F2A0-DC5B-11D0-AA0F-00AA006BC80B}")

'  INHERIT IUnknown

'   ' =====================================================================================
'   METHOD OnChange () AS LONG

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS

' ########################################################################################
' Class CIEventNotifyBindingChangeDisp
' Interface name = IEventNotifyBindingChangeDisp
' IID = {DC3D83B0-E99F-11D0-AA10-00AA006BC80B}
' Receives notifications of changes to a binding database.
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' ########################################################################################

'CLASS CIEventNotifyBindingChangeDisp GUID$("{8CF4244F-4F3B-41BF-9AF1-6FBC4D67ACFA}") AS EVENT

'INTERFACE IEventNotifyBindingChangeDispImpl GUID$("{DC3D83B0-E99F-11D0-AA10-00AA006BC80B}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD OnChange <1>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS
