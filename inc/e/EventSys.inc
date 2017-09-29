' ########################################################################################
' Microsoft Windows
' File: EventSys.inc
' Library name: EventSystemLib
' Version: 1.0, Locale ID = 0
' Library GUID: {4E14FB90-2E22-11D1-9964-00C04FBBB345}
' Path: C:\WINDOWS\system32\es.dll
' Contents: EventSystem 1.0 Type Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%EVENTSYS_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {CDBEC9C0-7A68-11D1-88F9-0080C7D771BF}
$PROGID_CEventClass1 = "EventSystem.EventClass.1"
' CLSID = {AB944620-79C6-11D1-88F9-0080C7D771BF}
$PROGID_CEventPublisher1 = "EventSystem.EventPublisher.1"
' CLSID = {7542E960-79C7-11D1-88F9-0080C7D771BF}
$PROGID_CEventSubscription1 = "EventSystem.EventSubscription.1"
' CLSID = {4E14FBA2-2E22-11D1-9964-00C04FBBB345}
$PROGID_CEventSystem1 = "EventSystem.EventSystem.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {CDBEC9C0-7A68-11D1-88F9-0080C7D771BF}
$PROGID_CEventClass = "EventSystem.EventClass"
' CLSID = {AB944620-79C6-11D1-88F9-0080C7D771BF}
$PROGID_CEventPublisher = "EventSystem.EventPublisher"
' CLSID = {7542E960-79C7-11D1-88F9-0080C7D771BF}
$PROGID_CEventSubscription = "EventSystem.EventSubscription"
' CLSID = {4E14FBA2-2E22-11D1-9964-00C04FBBB345}
$PROGID_CEventSystem = "EventSystem.EventSystem"

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IDontSupportEventSubscription = GUID$("{784121F1-62A6-4b89-855F-D65F296DE83A}")
$IID_IEnumEventObject = GUID$("{F4A07D63-2E25-11D1-9964-00C04FBBB345}")
$IID_IEventClass = GUID$("{FB2B72A0-7A68-11D1-88F9-0080C7D771BF}")
$IID_IEventClass2 = GUID$("{FB2B72A1-7A68-11D1-88F9-0080C7D771BF}")
$IID_IEventClass3 = GUID$("{7FB7EA43-2D76-4EA8-8CD9-3DECC270295E}")
$IID_IEventClassParallelFiringTimeout = GUID$("{A5657E5C-7BAE-4E81-9C17-284655918763}")
$IID_IEventControl = GUID$("{0343E2F4-86F6-11D1-B760-00C04FB926AF}")
$IID_IEventObjectChange = GUID$("{F4A07D70-2E25-11D1-9964-00C04FBBB345}")
$IID_IEventObjectChange2 = GUID$("{7701A9C3-BD68-438F-83E0-67BF4F53A422}")
$IID_IEventObjectCollection = GUID$("{F89AC270-D4EB-11D1-B682-00805FC79216}")
$IID_IEventProperty = GUID$("{DA538EE2-F4DE-11D1-B6BB-00805FC79216}")
$IID_IEventPublisher = GUID$("{E341516B-2E32-11D1-9964-00C04FBBB345}")
$IID_IEventSubscription = GUID$("{4A6B0E15-2E38-11D1-9965-00C04FBBB345}")
$IID_IEventSubscription2 = GUID$("{4A6B0E16-2E38-11D1-9965-00C04FBBB345}")
$IID_IEventSubscription3 = GUID$("{FBC1D17D-C498-43A0-81AF-423DDD530AF6}")
$IID_IEventSystem = GUID$("{4E14FB9F-2E22-11D1-9964-00C04FBBB345}")
$IID_IEventSystem2 = GUID$("{99CC098F-A48A-4E9C-8E58-965C0AFC19D5}")
$IID_IFiringControl = GUID$("{E0498C93-4EFE-11D1-9971-00C04FBBB345}")
$IID_IMultiInterfaceEventControl = GUID$("{0343E2F5-86F6-11D1-B760-00C04FB926AF}")
$IID_IMultiInterfacePublisherFilter = GUID$("{465E5CC1-7B26-11D1-88FB-0080C7D771BF}")
$IID_IPublisherFilter = GUID$("{465E5CC0-7B26-11D1-88FB-0080C7D771BF}")

' // Included in the typelib of es.dll, but not in EventSys.h
$IID_IAmAFiringAgent = GUID$("{0771CB93-DA7C-44B5-8196-422E6A2FBC40}")
$IID_IEventClassInternal = GUID$("{9F83871A-195F-44B5-A46F-18FFFE152F7C}")
$IID_IEventSubscriptionInternal = GUID$("{9B724996-D383-4C5F-B0F6-2814708C7633}")

' ########################################################################################
' Interface name = IEventSystem
' IID = {4E14FB9F-2E22-11D1-9964-00C04FBBB345}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' This is a Deprecated interface - Use COMAdmin interfaces instead.
' ########################################################################################

#IF NOT %DEF(%IEventSystem_INTERFACE_DEFINED)
    %IEventSystem_INTERFACE_DEFINED = 1

INTERFACE IEventSystem $IID_IEventSystem

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Query <1> ( _                                 ' VTable offset = 28
     BYVAL progID AS WSTRING _                          ' __in BSTR progID
   , BYVAL queryCriteria AS WSTRING _                   ' __in BSTR queryCriteria
   , BYREF errorIndex AS LONG _                         ' __out int *errorIndex
   ) AS IUnknown                                        ' __retval_out IUnknown **ppInterface
   ' =====================================================================================
   METHOD Store <2> ( _                                 ' VTable offset = 32
     BYVAL ProgID AS WSTRING _                          ' __in BSTR ProgID
   , BYVAL pInterface AS IUnknown _                     ' __in IUnknown *pInterface
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 36
     BYVAL progID AS WSTRING _                          ' __in BSTR progID
   , BYVAL queryCriteria AS WSTRING _                   ' __in BSTR queryCriteria
   , BYREF errorIndex AS LONG _                         ' __out int *errorIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EventObjectChangeEventClassID <4> ( _   ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrEventClassID
   ' =====================================================================================
   METHOD QueryS <5> ( _                                ' VTable offset = 44
     BYVAL progID AS WSTRING _                          ' __in BSTR progID
   , BYVAL queryCriteria AS WSTRING _                   ' __in BSTR queryCriteria
   ) AS IUnknown                                        ' __retval_out IUnknown **ppInterface
   ' =====================================================================================
   METHOD RemoveS <6> ( _                               ' VTable offset = 48
     BYVAL progID AS WSTRING _                          ' __in BSTR progID
   , BYVAL queryCriteria AS WSTRING _                   ' __in BSTR queryCriteria
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventSystem_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEventPublisher
' IID = {E341516B-2E32-11D1-9964-00C04FBBB345}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' This is a Deprecated interface - Do Not Use.
' ########################################################################################

#IF NOT %DEF(%IEventPublisher_INTERFACE_DEFINED)
    %IEventPublisher_INTERFACE_DEFINED = 1

INTERFACE IEventPublisher $IID_IEventPublisher

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET PublisherID <1> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPublisherID
   ' =====================================================================================
   PROPERTY SET PublisherID <1> ( _                     ' VTable offset = 32
     BYVAL bstrPublisherID AS WSTRING _                 ' __in BSTR bstrPublisherID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PublisherName <2> ( _                   ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPublisherName
   ' =====================================================================================
   PROPERTY SET PublisherName <2> ( _                   ' VTable offset = 40
     BYVAL bstrPublisherName AS WSTRING _               ' __in BSTR bstrPublisherName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PublisherType <3> ( _                   ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPublisherType
   ' =====================================================================================
   PROPERTY SET PublisherType <3> ( _                   ' VTable offset = 48
     BYVAL bstrPublisherType AS WSTRING _               ' __in BSTR bstrPublisherType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OwnerSID <4> ( _                        ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrOwnerSID
   ' =====================================================================================
   PROPERTY SET OwnerSID <4> ( _                        ' VTable offset = 56
     BYVAL bstrOwnerSID AS WSTRING _                    ' __in BSTR bstrOwnerSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <5> ( _                     ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <5> ( _                     ' VTable offset = 64
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDefaultProperty <6> ( _                    ' VTable offset = 68
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   ) AS VARIANT                                         ' __retval_out VARIANT *propertyValue
   ' =====================================================================================
   METHOD PutDefaultProperty <7> ( _                    ' VTable offset = 72
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   , BYREF propertyValue AS VARIANT _                   ' __in VARIANT *propertyValue
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveDefaultProperty <8> ( _                 ' VTable offset = 76
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDefaultPropertyCollection <9> ( _          ' VTable offset = 80
   ) AS IEventObjectCollection                          ' __retval_out IEventObjectCollection **collection
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventPublisher_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEventClass
' IID = {FB2B72A0-7A68-11D1-88F9-0080C7D771BF}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEventClass_INTERFACE_DEFINED)
    %IEventClass_INTERFACE_DEFINED = 1

INTERFACE IEventClass $IID_IEventClass

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET EventClassID <1> ( _                    ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrEventClassID
   ' =====================================================================================
   PROPERTY SET EventClassID <1> ( _                    ' VTable offset = 32
     BYVAL bstrEventClassID AS WSTRING _                ' __in BSTR bstrEventClassID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EventClassName <2> ( _                  ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrEventClassName
   ' =====================================================================================
   PROPERTY SET EventClassName <2> ( _                  ' VTable offset = 40
     BYVAL bstrEventClassName AS WSTRING _              ' __in BSTR bstrEventClassName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OwnerSID <3> ( _                        ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrOwnerSID
   ' =====================================================================================
   PROPERTY SET OwnerSID <3> ( _                        ' VTable offset = 48
     BYVAL bstrOwnerSID AS WSTRING _                    ' __in BSTR bstrOwnerSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FiringInterfaceID <4> ( _               ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFiringInterfaceID
   ' =====================================================================================
   PROPERTY SET FiringInterfaceID <4> ( _               ' VTable offset = 56
     BYVAL bstrFiringInterfaceID AS WSTRING _           ' __in BSTR bstrFiringInterfaceID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <5> ( _                     ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <5> ( _                     ' VTable offset = 64
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CustomConfigCLSID <6> ( _               ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCustomConfigCLSID
   ' =====================================================================================
   PROPERTY SET CustomConfigCLSID <6> ( _               ' VTable offset = 72
     BYVAL bstrCustomConfigCLSID AS WSTRING _           ' __in BSTR bstrCustomConfigCLSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TypeLib <7> ( _                         ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTypeLib
   ' =====================================================================================
   PROPERTY SET TypeLib <7> ( _                         ' VTable offset = 80
     BYVAL bstrTypeLib AS WSTRING _                     ' __in BSTR bstrTypeLib
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventClass_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEventClass2
' IID = {FB2B72A1-7A68-11D1-88F9-0080C7D771BF}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IEventClass
' ########################################################################################

#IF NOT %DEF(%IEventClass2_INTERFACE_DEFINED)
    %IEventClass2_INTERFACE_DEFINED = 1

INTERFACE IEventClass2 $IID_IEventClass2

   INHERIT IDispatch

   ' =====================================================================================
   ' IEventClass Methods
   ' =====================================================================================
   PROPERTY GET EventClassID <1> ( _                    ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrEventClassID
   ' =====================================================================================
   PROPERTY SET EventClassID <1> ( _                    ' VTable offset = 32
     BYVAL bstrEventClassID AS WSTRING _                ' __in BSTR bstrEventClassID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EventClassName <2> ( _                  ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrEventClassName
   ' =====================================================================================
   PROPERTY SET EventClassName <2> ( _                  ' VTable offset = 40
     BYVAL bstrEventClassName AS WSTRING _              ' __in BSTR bstrEventClassName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OwnerSID <3> ( _                        ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrOwnerSID
   ' =====================================================================================
   PROPERTY SET OwnerSID <3> ( _                        ' VTable offset = 48
     BYVAL bstrOwnerSID AS WSTRING _                    ' __in BSTR bstrOwnerSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FiringInterfaceID <4> ( _               ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFiringInterfaceID
   ' =====================================================================================
   PROPERTY SET FiringInterfaceID <4> ( _               ' VTable offset = 56
     BYVAL bstrFiringInterfaceID AS WSTRING _           ' __in BSTR bstrFiringInterfaceID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <5> ( _                     ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <5> ( _                     ' VTable offset = 64
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CustomConfigCLSID <6> ( _               ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCustomConfigCLSID
   ' =====================================================================================
   PROPERTY SET CustomConfigCLSID <6> ( _               ' VTable offset = 72
     BYVAL bstrCustomConfigCLSID AS WSTRING _           ' __in BSTR bstrCustomConfigCLSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TypeLib <7> ( _                         ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTypeLib
   ' =====================================================================================
   PROPERTY SET TypeLib <7> ( _                         ' VTable offset = 80
     BYVAL bstrTypeLib AS WSTRING _                     ' __in BSTR bstrTypeLib
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IEventClass2 Methods
   ' =====================================================================================
   PROPERTY GET PublisherID <8> ( _                     ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPublisherID
   ' =====================================================================================
   PROPERTY SET PublisherID <8> ( _                     ' VTable offset = 88
     BYVAL bstrPublisherID AS WSTRING _                 ' __in BSTR bstrPublisherID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MultiInterfacePublisherFilterCLSID <9> ( _ ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPubFilCLSID
   ' =====================================================================================
   PROPERTY SET MultiInterfacePublisherFilterCLSID <9> ( _ ' VTable offset = 96
     BYVAL bstrPubFilCLSID AS WSTRING _                 ' __in BSTR bstrPubFilCLSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowInprocActivation <10> ( _          ' VTable offset = 100
   ) AS LONG                                            ' __retval_out BOOL *pfAllowInprocActivation
   ' =====================================================================================
   PROPERTY SET AllowInprocActivation <10> ( _          ' VTable offset = 104
     BYVAL fAllowInprocActivation AS LONG _             ' __in BOOL fAllowInprocActivation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FireInParallel <11> ( _                 ' VTable offset = 108
   ) AS LONG                                            ' __retval_out BOOL *pfFireInParallel
   ' =====================================================================================
   PROPERTY SET FireInParallel <11> ( _                 ' VTable offset = 112
     BYVAL fFireInParallel AS LONG _                    ' __in BOOL fFireInParallel
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventClass2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEventSubscription
' IID = {4A6B0E15-2E38-11D1-9965-00C04FBBB345}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEventSubscription_INTERFACE_DEFINED)
    %IEventSubscription_INTERFACE_DEFINED = 1

INTERFACE IEventSubscription $IID_IEventSubscription

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET SubscriptionID <1> ( _                  ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSubscriptionID
   ' =====================================================================================
   PROPERTY SET SubscriptionID <1> ( _                  ' VTable offset = 32
     BYVAL bstrSubscriptionID AS WSTRING _              ' __in BSTR bstrSubscriptionID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubscriptionName <2> ( _                ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSubscriptionName
   ' =====================================================================================
   PROPERTY SET SubscriptionName <2> ( _                ' VTable offset = 40
     BYVAL bstrSubscriptionName AS WSTRING _            ' __in BSTR bstrSubscriptionName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PublisherID <3> ( _                     ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPublisherID
   ' =====================================================================================
   PROPERTY SET PublisherID <3> ( _                     ' VTable offset = 48
     BYVAL bstrPublisherID AS WSTRING _                 ' __in BSTR bstrPublisherID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EventClassID <4> ( _                    ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrEventClassID
   ' =====================================================================================
   PROPERTY SET EventClassID <4> ( _                    ' VTable offset = 56
     BYVAL bstrEventClassID AS WSTRING _                ' __in BSTR bstrEventClassID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET methodName <5> ( _                      ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrMethodName
   ' =====================================================================================
   PROPERTY SET methodName <5> ( _                      ' VTable offset = 64
     BYVAL bstrMethodName AS WSTRING _                  ' __in BSTR bstrMethodName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubscriberCLSID <6> ( _                 ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSubscriberCLSID
   ' =====================================================================================
   PROPERTY SET SubscriberCLSID <6> ( _                 ' VTable offset = 72
     BYVAL bstrSubscriberCLSID AS WSTRING _             ' __in BSTR bstrSubscriberCLSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubscriberInterface <7> ( _             ' VTable offset = 76
   ) AS IUnknown                                        ' __retval_out IUnknown **ppSubscriberInterface
   ' =====================================================================================
   PROPERTY SET SubscriberInterface <7> ( _             ' VTable offset = 80
     BYVAL pSubscriberInterface AS IUnknown _           ' __in IUnknown *pSubscriberInterface
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PerUser <8> ( _                         ' VTable offset = 84
   ) AS LONG                                            ' __retval_out BOOL *pfPerUser
   ' =====================================================================================
   PROPERTY SET PerUser <8> ( _                         ' VTable offset = 88
     BYVAL fPerUser AS LONG _                           ' __in BOOL fPerUser
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OwnerSID <9> ( _                        ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrOwnerSID
   ' =====================================================================================
   PROPERTY SET OwnerSID <9> ( _                        ' VTable offset = 96
     BYVAL bstrOwnerSID AS WSTRING _                    ' __in BSTR bstrOwnerSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <10> ( _                        ' VTable offset = 100
   ) AS LONG                                            ' __retval_out BOOL *pfEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <10> ( _                        ' VTable offset = 104
     BYVAL fEnabled AS LONG _                           ' __in BOOL fEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <11> ( _                    ' VTable offset = 108
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <11> ( _                    ' VTable offset = 112
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MachineName <12> ( _                    ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrMachineName
   ' =====================================================================================
   PROPERTY SET MachineName <12> ( _                    ' VTable offset = 120
     BYVAL bstrMachineName AS WSTRING _                 ' __in BSTR bstrMachineName
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPublisherProperty <13> ( _                 ' VTable offset = 124
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   ) AS VARIANT                                         ' __retval_out VARIANT *propertyValue
   ' =====================================================================================
   METHOD PutPublisherProperty <14> ( _                 ' VTable offset = 128
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   , BYREF propertyValue AS VARIANT _                   ' __in VARIANT *propertyValue
   )                                                    ' void
   ' =====================================================================================
   METHOD RemovePublisherProperty <15> ( _              ' VTable offset = 132
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPublisherPropertyCollection <16> ( _       ' VTable offset = 136
   ) AS IEventObjectCollection                          ' __retval_out IEventObjectCollection **collection
   ' =====================================================================================
   METHOD GetSubscriberProperty <17> ( _                ' VTable offset = 140
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   ) AS VARIANT                                         ' __retval_out VARIANT *propertyValue
   ' =====================================================================================
   METHOD PutSubscriberProperty <18> ( _                ' VTable offset = 144
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   , BYREF propertyValue AS VARIANT _                   ' __in VARIANT *propertyValue
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveSubscriberProperty <19> ( _             ' VTable offset = 148
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSubscriberPropertyCollection <20> ( _      ' VTable offset = 152
   ) AS IEventObjectCollection                          ' __retval_out IEventObjectCollection **collection
   ' =====================================================================================
   PROPERTY GET InterfaceID <21> ( _                    ' VTable offset = 156
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrInterfaceID
   ' =====================================================================================
   PROPERTY SET InterfaceID <21> ( _                    ' VTable offset = 160
     BYVAL bstrInterfaceID AS WSTRING _                 ' __in BSTR bstrInterfaceID
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventSubscription_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IFiringControl
' IID = {E0498C93-4EFE-11D1-9971-00C04FBBB345}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFiringControl_INTERFACE_DEFINED)
    %IFiringControl_INTERFACE_DEFINED = 1

INTERFACE IFiringControl $IID_IFiringControl

   INHERIT IDispatch

   ' =====================================================================================
   METHOD FireSubscription <1> ( _                      ' VTable offset = 28
     BYVAL subscription AS IEventSubscription _         ' __in IEventSubscription *subscription
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFiringControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPublisherFilter
' IID = {465E5CC0-7B26-11D1-88FB-0080C7D771BF}
' Inherited interface = IUnknown
' This is a Deprecated interface - Use IMultiInterfacePublisherFilter instead.
' ########################################################################################

#IF NOT %DEF(%IPublisherFilter_INTERFACE_DEFINED)
    %IPublisherFilter_INTERFACE_DEFINED = 1

INTERFACE IPublisherFilter $IID_IPublisherFilter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL methodName AS WSTRING _                      ' __in BSTR methodName
   , BYVAL dispUserDefined AS IDispatch _               ' __in IDispatch *dispUserDefined
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PrepareToFire ( _                             ' VTable offset = 16
     BYVAL methodName AS WSTRING _                      ' __in BSTR methodName
   , BYVAL firingControl AS IFiringControl _            ' __in IFiringControl *firingControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' __IPublisherFilter_INTERFACE_DEFINED__


' ########################################################################################
' Interface name = IMultiInterfacePublisherFilter
' IID = {465E5CC1-7B26-11D1-88FB-0080C7D771BF}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMultiInterfacePublisherFilter_INTERFACE_DEFINED)
    %IMultiInterfacePublisherFilter_INTERFACE_DEFINED = 1

INTERFACE IMultiInterfacePublisherFilter $IID_IMultiInterfacePublisherFilter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pEIC AS IMultiInterfaceEventControl _        ' __in IMultiInterfaceEventControl *pEIC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PrepareToFire ( _                             ' VTable offset = 16
     BYREF iid AS GUID _                                ' __in REFIID iid
   , BYVAL methodName AS WSTRING _                      ' __in BSTR methodName
   , BYVAL firingControl AS IFiringControl _            ' __in IFiringControl *firingControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMultiInterfacePublisherFilter_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEventObjectChange
' IID = {F4A07D70-2E25-11D1-9964-00C04FBBB345}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEventObjectChange_INTERFACE_DEFINED)
    %IEventObjectChange_INTERFACE_DEFINED = 1

' EOC_ChangeType enum
%EOC_NewObject      = 0
%EOC_ModifiedObject = %EOC_NewObject + 1
%EOC_DeletedObject  = %EOC_ModifiedObject + 1

INTERFACE IEventObjectChange $IID_IEventObjectChange

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ChangedSubscription ( _                       ' VTable offset = 12
     BYVAL changeType AS LONG _                         ' __in EOC_ChangeType changeType
   , BYVAL bstrSubscriptionID AS WSTRING _              ' __in BSTR bstrSubscriptionID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ChangedEventClass ( _                         ' VTable offset = 16
     BYVAL changeType AS LONG _                         ' __in EOC_ChangeType changeType
   , BYVAL bstrEventClassID AS WSTRING _                ' __in BSTR bstrEventClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ChangedPublisher ( _                          ' VTable offset = 20
     BYVAL changeType AS LONG _                         ' __in EOC_ChangeType changeType
   , BYVAL bstrPublisherID AS WSTRING _                 ' __in BSTR bstrPublisherID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventObjectChange_INTERFACE_DEFINED__ */

' // Size = 180 bytes
TYPE COMEVENTSYSCHANGEINFO DWORD
   cbSize        AS DWORD   ' DWORD cbSize
   changeType    AS LONG    ' EOC_ChangeType changeType
   objectID      AS DWORD   ' BSTR objectId
   partitionId   AS DWORD   ' BSTR partitionId
   applicationId AS DWORD   ' BSTR applicationId
   reserved(9)   AS GUID    ' GUID reserved[ 10 ]
END TYPE


' ########################################################################################
' Interface name = IEventObjectChange2
' IID = {7701A9C3-BD68-438F-83E0-67BF4F53A422}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEventObjectChange2_INTERFACE_DEFINED)
    %IEventObjectChange2_INTERFACE_DEFINED = 1

INTERFACE IEventObjectChange2 $IID_IEventObjectChange2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ChangedSubscription ( _                       ' VTable offset = 12
     BYREF pInfo AS COMEVENTSYSCHANGEINFO _             ' __in COMEVENTSYSCHANGEINFO *pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ChangedEventClass ( _                         ' VTable offset = 16
     BYREF pInfo AS COMEVENTSYSCHANGEINFO _             ' __in COMEVENTSYSCHANGEINFO *pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventObjectChange2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumEventObject
' IID = {F4A07D63-2E25-11D1-9964-00C04FBBB345}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumEventObject_INTERFACE_DEFINED)
    %IEnumEventObject_INTERFACE_DEFINED = 1

INTERFACE IEnumEventObject $IID_IEnumEventObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 12
     BYREF ppInterface AS IEnumEventObject _            ' __out IEnumEventObject **ppInterface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 16
     BYVAL cReqElem AS DWORD _                          ' __in ULONG cReqElem
   , BYREF ppInterface AS IUnknown _                    ' __out IUnknown **ppInterface
   , BYREF cRetElem AS DWORD _                          ' __out ULONG *cRetElem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 24
     BYVAL cSkipElem AS DWORD _                         ' __in ULONG cSkipElem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumEventObject_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEventObjectCollection
' IID = {F89AC270-D4EB-11D1-B682-00805FC79216}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEventObjectCollection_INTERFACE_DEFINED)
    %IEventObjectCollection_INTERFACE_DEFINED = 1

INTERFACE IEventObjectCollection $IID_IEventObjectCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnkEnum
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL objectID AS WSTRING _                        ' __in BSTR objectID
   ) AS VARIANT                                         ' __retval_out VARIANT *pItem
   ' =====================================================================================
   PROPERTY GET NewEnum <1> ( _                         ' VTable offset = 36
   ) AS IEnumEventObject                                ' __retval_out IEnumEventObject **ppEnum
   ' =====================================================================================
   PROPERTY GET Count <2> ( _                           ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *pCount
   ' =====================================================================================
   METHOD Add <3> ( _                                   ' VTable offset = 44
     BYREF item AS VARIANT _                            ' __in VARIANT *item
   , BYVAL objectID AS WSTRING _                        ' __in BSTR objectID
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <4> ( _                                ' VTable offset = 48
     BYVAL objectID AS WSTRING _                        ' __in BSTR objectID
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventObjectCollection_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEventProperty
' IID = {DA538EE2-F4DE-11D1-B6BB-00805FC79216}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEventProperty_INTERFACE_DEFINED)
    %IEventProperty_INTERFACE_DEFINED = 1

INTERFACE IEventProperty $IID_IEventProperty

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *propertyName
   ' =====================================================================================
   PROPERTY SET Name <1> ( _                            ' VTable offset = 32
     BYVAL propertyName AS WSTRING _                    ' __in BSTR propertyName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Value <2> ( _                           ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT *propertyValue
   ' =====================================================================================
   PROPERTY SET Value <2> ( _                           ' VTable offset = 40
     BYREF IN propertyValue AS VARIANT _                ' __in VARIANT *propertyValue
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventProperty_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEventControl
' IID = {0343E2F4-86F6-11D1-B760-00C04FB926AF}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' This is a Deprecated interface - Use IMultiInterfaceEventControl instead.
' ########################################################################################

#IF NOT %DEF(%IEventControl_INTERFACE_DEFINED)
    %IEventControl_INTERFACE_DEFINED = 1

INTERFACE IEventControl $IID_IEventControl

   INHERIT IDispatch

   ' =====================================================================================
   METHOD SetPublisherFilter <1> ( _                    ' VTable offset = 28
     BYVAL methodName AS WSTRING _                      ' __in BSTR methodName
   , BYVAL pPublisherFilter AS IPublisherFilter _       ' __in IPublisherFilter *pPublisherFilter
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowInprocActivation <2> ( _           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out BOOL *pfAllowInprocActivation
   ' =====================================================================================
   PROPERTY SET AllowInprocActivation <2> ( _           ' VTable offset = 36
     BYVAL fAllowInprocActivation AS LONG _             ' __in BOOL fAllowInprocActivation
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSubscriptions <3> ( _                      ' VTable offset = 40
     BYVAL methodName AS WSTRING _                      ' __in BSTR methodName
   , BYVAL optionalCriteria AS WSTRING _                ' __in BSTR optionalCriteria
   , BYREF optionalErrorIndex AS LONG _                 ' __in int *optionalErrorIndex
   ) AS IEventObjectCollection                          ' __retval_out IEventObjectCollection **ppCollection
   ' =====================================================================================
   METHOD SetDefaultQuery <4> ( _                       ' VTable offset = 44
     BYVAL methodName AS WSTRING _                      ' __in BSTR methodName
   , BYVAL criteria AS WSTRING _                        ' __in BSTR criteria
   ) AS LONG                                            ' __retval_out int *errorIndex
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMultiInterfaceEventControl
' IID = {0343E2F5-86F6-11D1-B760-00C04FB926AF}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMultiInterfaceEventControl_INTERFACE_DEFINED)
    %IMultiInterfaceEventControl_INTERFACE_DEFINED = 1

INTERFACE IMultiInterfaceEventControl $IID_IMultiInterfaceEventControl

   INHERIT IAutomation

   ' =====================================================================================
   METHOD SetMultiInterfacePublisherFilter ( _          ' VTable offset = 12
     BYVAL classFilter AS IMultiInterfacePublisherFilter _ ' __in IMultiInterfacePublisherFilter *classFilter
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSubscriptions ( _                          ' VTable offset = 16
     BYREF eventIID AS GUID _                           ' __in REFIID eventIID
   , BYVAL bstrMethodName AS WSTRING _                  ' __in BSTR bstrMethodName
   , BYVAL optionalCriteria AS WSTRING _                ' __in BSTR optionalCriteria
   , BYREF optionalErrorIndex AS LONG _                 ' __in int *optionalErrorIndex
   ) AS IEventObjectCollection                          ' __retval_out IEventObjectCollection **ppCollection
   ' =====================================================================================
   METHOD SetDefaultQuery ( _                           ' VTable offset = 20
     BYREF eventIID AS GUID _                           ' __in REFIID eventIID
   , BYVAL bstrMethodName AS WSTRING _                  ' __in BSTR bstrMethodName
   , BYVAL bstrCriteria AS WSTRING _                    ' __in BSTR bstrCriteria
   ) AS LONG                                            ' __retval_out int *errorIndex
   ' =====================================================================================
   PROPERTY GET AllowInprocActivation ( _               ' VTable offset = 24
   ) AS LONG                                            ' __retval_out BOOL *pfAllowInprocActivation
   ' =====================================================================================
   PROPERTY SET AllowInprocActivation ( _               ' VTable offset = 28
     BYVAL fAllowInprocActivation AS LONG _             ' __in BOOL fAllowInprocActivation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FireInParallel ( _                      ' VTable offset = 32
   ) AS LONG                                            ' __retval_out BOOL *pfFireInParallel
   ' =====================================================================================
   PROPERTY SET FireInParallel ( _                      ' VTable offset = 36
     BYVAL fFireInParallel AS LONG _                    ' __in BOOL fFireInParallel
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMultiInterfaceEventControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDontSupportEventSubscription
' IID = 784121F1-62A6-4b89-855F-D65F296DE83A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDontSupportEventSubscription_INTERFACE_DEFINED)
    %IDontSupportEventSubscription_INTERFACE_DEFINED = 1

INTERFACE IDontSupportEventSubscription $IID_IDontSupportEventSubscription

   INHERIT IUnknown

END INTERFACE

#ENDIF   ' /* __IDontSupportEventSubscription_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEventClass3
' IID = {7FB7EA43-2D76-4EA8-8CD9-3DECC270295E}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IEventClass2
' ########################################################################################

#IF NOT %DEF(%IEventClass3_INTERFACE_DEFINED)
    %IEventClass3_INTERFACE_DEFINED = 1

INTERFACE IEventClass3 $IID_IEventClass3

   INHERIT IDispatch

   ' =====================================================================================
   ' IEventClass Methods
   ' =====================================================================================
   PROPERTY GET EventClassID <1> ( _                    ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrEventClassID
   ' =====================================================================================
   PROPERTY SET EventClassID <1> ( _                    ' VTable offset = 32
     BYVAL bstrEventClassID AS WSTRING _                ' __in BSTR bstrEventClassID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EventClassName <2> ( _                  ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrEventClassName
   ' =====================================================================================
   PROPERTY SET EventClassName <2> ( _                  ' VTable offset = 40
     BYVAL bstrEventClassName AS WSTRING _              ' __in BSTR bstrEventClassName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OwnerSID <3> ( _                        ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrOwnerSID
   ' =====================================================================================
   PROPERTY SET OwnerSID <3> ( _                        ' VTable offset = 48
     BYVAL bstrOwnerSID AS WSTRING _                    ' __in BSTR bstrOwnerSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FiringInterfaceID <4> ( _               ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFiringInterfaceID
   ' =====================================================================================
   PROPERTY SET FiringInterfaceID <4> ( _               ' VTable offset = 56
     BYVAL bstrFiringInterfaceID AS WSTRING _           ' __in BSTR bstrFiringInterfaceID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <5> ( _                     ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <5> ( _                     ' VTable offset = 64
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CustomConfigCLSID <6> ( _               ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCustomConfigCLSID
   ' =====================================================================================
   PROPERTY SET CustomConfigCLSID <6> ( _               ' VTable offset = 72
     BYVAL bstrCustomConfigCLSID AS WSTRING _           ' __in BSTR bstrCustomConfigCLSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TypeLib <7> ( _                         ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTypeLib
   ' =====================================================================================
   PROPERTY SET TypeLib <7> ( _                         ' VTable offset = 80
     BYVAL bstrTypeLib AS WSTRING _                     ' __in BSTR bstrTypeLib
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IEventClass2 Methods
   ' =====================================================================================
   PROPERTY GET PublisherID <8> ( _                     ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPublisherID
   ' =====================================================================================
   PROPERTY SET PublisherID <8> ( _                     ' VTable offset = 88
     BYVAL bstrPublisherID AS WSTRING _                 ' __in BSTR bstrPublisherID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MultiInterfacePublisherFilterCLSID <9> ( _ ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPubFilCLSID
   ' =====================================================================================
   PROPERTY SET MultiInterfacePublisherFilterCLSID <9> ( _ ' VTable offset = 96
     BYVAL bstrPubFilCLSID AS WSTRING _                 ' __in BSTR bstrPubFilCLSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowInprocActivation <10> ( _          ' VTable offset = 100
   ) AS LONG                                            ' __retval_out BOOL *pfAllowInprocActivation
   ' =====================================================================================
   PROPERTY SET AllowInprocActivation <10> ( _          ' VTable offset = 104
     BYVAL fAllowInprocActivation AS LONG _             ' __in BOOL fAllowInprocActivation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FireInParallel <11> ( _                 ' VTable offset = 108
   ) AS LONG                                            ' __retval_out BOOL *pfFireInParallel
   ' =====================================================================================
   PROPERTY SET FireInParallel <11> ( _                 ' VTable offset = 112
     BYVAL fFireInParallel AS LONG _                    ' __in BOOL fFireInParallel
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IEventClass3 Methods
   ' =====================================================================================
   PROPERTY GET EventClassPartitionID <12> ( _          ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrEventClassPartitionID
   ' =====================================================================================
   PROPERTY SET EventClassPartitionID <12> ( _          ' VTable offset = 120
     BYVAL bstrEventClassPartitionID AS WSTRING _       ' __in BSTR bstrEventClassPartitionID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EventClassApplicationID <13> ( _        ' VTable offset = 124
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrEventClassApplicationID
   ' =====================================================================================
   PROPERTY SET EventClassApplicationID <13> ( _        ' VTable offset = 128
     BYVAL bstrEventClassApplicationID AS WSTRING _     ' __in BSTR bstrEventClassApplicationID
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventClass3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventClassParallelFiringTimeout
' IID = {A5657E5C-7BAE-4E81-9C17-284655918763}
' Attributes = 64 [&H40] [Dual]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEventClassParallelFiringTimeout_INTERFACE_DEFINED)
    %IEventClassParallelFiringTimeout_INTERFACE_DEFINED = 1

INTERFACE IEventClassParallelFiringTimeout $IID_IEventClassParallelFiringTimeout

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ParallelFiringTimeout <1> ( _           ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out unsigned long* pdwParallelFiringTimeout
   ' =====================================================================================
   PROPERTY SET ParallelFiringTimeout <1> ( _           ' VTable offset = 16
     BYVAL pdwParallelFiringTimeout AS DWORD _          ' __in unsigned long pdwParallelFiringTimeout
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventClassParallelFiringTimeout_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventSubscription2
' IID = {4A6B0E16-2E38-11D1-9965-00C04FBBB345}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IEventSubscription
' ########################################################################################

#IF NOT %DEF(%IEventSubscription2_INTERFACE_DEFINED)
    %IEventSubscription2_INTERFACE_DEFINED = 1

INTERFACE IEventSubscription2 $IID_IEventSubscription2

   INHERIT IDispatch

   ' =====================================================================================
   ' IEventSubscription Methods
   ' =====================================================================================
   PROPERTY GET SubscriptionID <1> ( _                  ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSubscriptionID
   ' =====================================================================================
   PROPERTY SET SubscriptionID <1> ( _                  ' VTable offset = 32
     BYVAL bstrSubscriptionID AS WSTRING _              ' __in BSTR bstrSubscriptionID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubscriptionName <2> ( _                ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSubscriptionName
   ' =====================================================================================
   PROPERTY SET SubscriptionName <2> ( _                ' VTable offset = 40
     BYVAL bstrSubscriptionName AS WSTRING _            ' __in BSTR bstrSubscriptionName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PublisherID <3> ( _                     ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPublisherID
   ' =====================================================================================
   PROPERTY SET PublisherID <3> ( _                     ' VTable offset = 48
     BYVAL bstrPublisherID AS WSTRING _                 ' __in BSTR bstrPublisherID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EventClassID <4> ( _                    ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrEventClassID
   ' =====================================================================================
   PROPERTY SET EventClassID <4> ( _                    ' VTable offset = 56
     BYVAL bstrEventClassID AS WSTRING _                ' __in BSTR bstrEventClassID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET methodName <5> ( _                      ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrMethodName
   ' =====================================================================================
   PROPERTY SET methodName <5> ( _                      ' VTable offset = 64
     BYVAL bstrMethodName AS WSTRING _                  ' __in BSTR bstrMethodName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubscriberCLSID <6> ( _                 ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSubscriberCLSID
   ' =====================================================================================
   PROPERTY SET SubscriberCLSID <6> ( _                 ' VTable offset = 72
     BYVAL bstrSubscriberCLSID AS WSTRING _             ' __in BSTR bstrSubscriberCLSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubscriberInterface <7> ( _             ' VTable offset = 76
   ) AS IUnknown                                        ' __retval_out IUnknown **ppSubscriberInterface
   ' =====================================================================================
   PROPERTY SET SubscriberInterface <7> ( _             ' VTable offset = 80
     BYVAL pSubscriberInterface AS IUnknown _           ' __in IUnknown *pSubscriberInterface
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PerUser <8> ( _                         ' VTable offset = 84
   ) AS LONG                                            ' __retval_out BOOL *pfPerUser
   ' =====================================================================================
   PROPERTY SET PerUser <8> ( _                         ' VTable offset = 88
     BYVAL fPerUser AS LONG _                           ' __in BOOL fPerUser
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OwnerSID <9> ( _                        ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrOwnerSID
   ' =====================================================================================
   PROPERTY SET OwnerSID <9> ( _                        ' VTable offset = 96
     BYVAL bstrOwnerSID AS WSTRING _                    ' __in BSTR bstrOwnerSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <10> ( _                        ' VTable offset = 100
   ) AS LONG                                            ' __retval_out BOOL *pfEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <10> ( _                        ' VTable offset = 104
     BYVAL fEnabled AS LONG _                           ' __in BOOL fEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <11> ( _                    ' VTable offset = 108
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <11> ( _                    ' VTable offset = 112
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MachineName <12> ( _                    ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrMachineName
   ' =====================================================================================
   PROPERTY SET MachineName <12> ( _                    ' VTable offset = 120
     BYVAL bstrMachineName AS WSTRING _                 ' __in BSTR bstrMachineName
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPublisherProperty <13> ( _                 ' VTable offset = 124
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   ) AS VARIANT                                         ' __retval_out VARIANT *propertyValue
   ' =====================================================================================
   METHOD PutPublisherProperty <14> ( _                 ' VTable offset = 128
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   , BYREF propertyValue AS VARIANT _                   ' __in VARIANT *propertyValue
   )                                                    ' void
   ' =====================================================================================
   METHOD RemovePublisherProperty <15> ( _              ' VTable offset = 132
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPublisherPropertyCollection <16> ( _       ' VTable offset = 136
   ) AS IEventObjectCollection                          ' __retval_out IEventObjectCollection **collection
   ' =====================================================================================
   METHOD GetSubscriberProperty <17> ( _                ' VTable offset = 140
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   ) AS VARIANT                                         ' __retval_out VARIANT *propertyValue
   ' =====================================================================================
   METHOD PutSubscriberProperty <18> ( _                ' VTable offset = 144
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   , BYREF propertyValue AS VARIANT _                   ' __in VARIANT *propertyValue
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveSubscriberProperty <19> ( _             ' VTable offset = 148
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSubscriberPropertyCollection <20> ( _      ' VTable offset = 152
   ) AS IEventObjectCollection                          ' __retval_out IEventObjectCollection **collection
   ' =====================================================================================
   PROPERTY GET InterfaceID <21> ( _                    ' VTable offset = 156
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrInterfaceID
   ' =====================================================================================
   PROPERTY SET InterfaceID <21> ( _                    ' VTable offset = 160
     BYVAL bstrInterfaceID AS WSTRING _                 ' __in BSTR bstrInterfaceID
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IEventSubscription2 Methods
   ' =====================================================================================
   PROPERTY GET FilterCriteria <22> ( _                 ' VTable offset = 164
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrFilterCriteria
   ' =====================================================================================
   PROPERTY SET FilterCriteria <22> ( _                 ' VTable offset = 168
     BYVAL pbstrFilterCriteria AS WSTRING _             ' __in BSTR pbstrFilterCriteria
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubscriberMoniker <23> ( _              ' VTable offset = 172
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrMoniker
   ' =====================================================================================
   PROPERTY SET SubscriberMoniker <23> ( _              ' VTable offset = 176
     BYVAL pbstrMoniker AS WSTRING _                    ' __in BSTR pbstrMoniker
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventSubscription2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventSubscription3
' IID = {FBC1D17D-C498-43A0-81AF-423DDD530AF6}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IEventSubscription2
' ########################################################################################

#IF NOT %DEF(%IEventSubscription3_INTERFACE_DEFINED)
    %IEventSubscription3_INTERFACE_DEFINED = 1

INTERFACE IEventSubscription3 $IID_IEventSubscription3

   INHERIT IDispatch

   ' =====================================================================================
   ' IEventSubscription Methods
   ' =====================================================================================
   PROPERTY GET SubscriptionID <1> ( _                  ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSubscriptionID
   ' =====================================================================================
   PROPERTY SET SubscriptionID <1> ( _                  ' VTable offset = 32
     BYVAL bstrSubscriptionID AS WSTRING _              ' __in BSTR bstrSubscriptionID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubscriptionName <2> ( _                ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSubscriptionName
   ' =====================================================================================
   PROPERTY SET SubscriptionName <2> ( _                ' VTable offset = 40
     BYVAL bstrSubscriptionName AS WSTRING _            ' __in BSTR bstrSubscriptionName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PublisherID <3> ( _                     ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPublisherID
   ' =====================================================================================
   PROPERTY SET PublisherID <3> ( _                     ' VTable offset = 48
     BYVAL bstrPublisherID AS WSTRING _                 ' __in BSTR bstrPublisherID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EventClassID <4> ( _                    ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrEventClassID
   ' =====================================================================================
   PROPERTY SET EventClassID <4> ( _                    ' VTable offset = 56
     BYVAL bstrEventClassID AS WSTRING _                ' __in BSTR bstrEventClassID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET methodName <5> ( _                      ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrMethodName
   ' =====================================================================================
   PROPERTY SET methodName <5> ( _                      ' VTable offset = 64
     BYVAL bstrMethodName AS WSTRING _                  ' __in BSTR bstrMethodName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubscriberCLSID <6> ( _                 ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSubscriberCLSID
   ' =====================================================================================
   PROPERTY SET SubscriberCLSID <6> ( _                 ' VTable offset = 72
     BYVAL bstrSubscriberCLSID AS WSTRING _             ' __in BSTR bstrSubscriberCLSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubscriberInterface <7> ( _             ' VTable offset = 76
   ) AS IUnknown                                        ' __retval_out IUnknown **ppSubscriberInterface
   ' =====================================================================================
   PROPERTY SET SubscriberInterface <7> ( _             ' VTable offset = 80
     BYVAL pSubscriberInterface AS IUnknown _           ' __in IUnknown *pSubscriberInterface
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PerUser <8> ( _                         ' VTable offset = 84
   ) AS LONG                                            ' __retval_out BOOL *pfPerUser
   ' =====================================================================================
   PROPERTY SET PerUser <8> ( _                         ' VTable offset = 88
     BYVAL fPerUser AS LONG _                           ' __in BOOL fPerUser
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OwnerSID <9> ( _                        ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrOwnerSID
   ' =====================================================================================
   PROPERTY SET OwnerSID <9> ( _                        ' VTable offset = 96
     BYVAL bstrOwnerSID AS WSTRING _                    ' __in BSTR bstrOwnerSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <10> ( _                        ' VTable offset = 100
   ) AS LONG                                            ' __retval_out BOOL *pfEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <10> ( _                        ' VTable offset = 104
     BYVAL fEnabled AS LONG _                           ' __in BOOL fEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <11> ( _                    ' VTable offset = 108
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <11> ( _                    ' VTable offset = 112
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MachineName <12> ( _                    ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrMachineName
   ' =====================================================================================
   PROPERTY SET MachineName <12> ( _                    ' VTable offset = 120
     BYVAL bstrMachineName AS WSTRING _                 ' __in BSTR bstrMachineName
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPublisherProperty <13> ( _                 ' VTable offset = 124
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   ) AS VARIANT                                         ' __retval_out VARIANT *propertyValue
   ' =====================================================================================
   METHOD PutPublisherProperty <14> ( _                 ' VTable offset = 128
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   , BYREF propertyValue AS VARIANT _                   ' __in VARIANT *propertyValue
   )                                                    ' void
   ' =====================================================================================
   METHOD RemovePublisherProperty <15> ( _              ' VTable offset = 132
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPublisherPropertyCollection <16> ( _       ' VTable offset = 136
   ) AS IEventObjectCollection                          ' __retval_out IEventObjectCollection **collection
   ' =====================================================================================
   METHOD GetSubscriberProperty <17> ( _                ' VTable offset = 140
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   ) AS VARIANT                                         ' __retval_out VARIANT *propertyValue
   ' =====================================================================================
   METHOD PutSubscriberProperty <18> ( _                ' VTable offset = 144
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   , BYREF propertyValue AS VARIANT _                   ' __in VARIANT *propertyValue
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveSubscriberProperty <19> ( _             ' VTable offset = 148
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSubscriberPropertyCollection <20> ( _      ' VTable offset = 152
   ) AS IEventObjectCollection                          ' __retval_out IEventObjectCollection **collection
   ' =====================================================================================
   PROPERTY GET InterfaceID <21> ( _                    ' VTable offset = 156
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrInterfaceID
   ' =====================================================================================
   PROPERTY SET InterfaceID <21> ( _                    ' VTable offset = 160
     BYVAL bstrInterfaceID AS WSTRING _                 ' __in BSTR bstrInterfaceID
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IEventSubscription2 Methods
   ' =====================================================================================
   PROPERTY GET FilterCriteria <22> ( _                 ' VTable offset = 164
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrFilterCriteria
   ' =====================================================================================
   PROPERTY SET FilterCriteria <22> ( _                 ' VTable offset = 168
     BYVAL pbstrFilterCriteria AS WSTRING _             ' __in BSTR pbstrFilterCriteria
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubscriberMoniker <23> ( _              ' VTable offset = 172
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrMoniker
   ' =====================================================================================
   PROPERTY SET SubscriberMoniker <23> ( _              ' VTable offset = 176
     BYVAL pbstrMoniker AS WSTRING _                    ' __in BSTR pbstrMoniker
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IEventSubscription3 Methods
   ' =====================================================================================
   PROPERTY GET EventClassPartitionID <24> ( _          ' VTable offset = 180
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrEventClassPartitionID
   ' =====================================================================================
   PROPERTY SET EventClassPartitionID <24> ( _          ' VTable offset = 184
     BYVAL pbstrEventClassPartitionID AS WSTRING _      ' __in BSTR pbstrEventClassPartitionID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EventClassApplicationID <25> ( _        ' VTable offset = 188
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrEventClassApplicationID
   ' =====================================================================================
   PROPERTY SET EventClassApplicationID <25> ( _        ' VTable offset = 192
     BYVAL pbstrEventClassApplicationID AS WSTRING _    ' __in BSTR pbstrEventClassApplicationID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubscriberPartitionID <26> ( _          ' VTable offset = 196
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrSubscriberPartitionID
   ' =====================================================================================
   PROPERTY SET SubscriberPartitionID <26> ( _          ' VTable offset = 200
     BYVAL pbstrSubscriberPartitionID AS WSTRING _      ' __in BSTR pbstrSubscriberPartitionID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubscriberApplicationID <27> ( _        ' VTable offset = 204
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrSubscriberApplicationID
   ' =====================================================================================
   PROPERTY SET SubscriberApplicationID <27> ( _        ' VTable offset = 208
     BYVAL pbstrSubscriberApplicationID AS WSTRING _    ' __in BSTR pbstrSubscriberApplicationID
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventSubscription3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventSystem2
' IID = {99CC098F-A48A-4E9C-8E58-965C0AFC19D5}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IEventSystem
' ########################################################################################

#IF NOT %DEF(%IEventSystem2_INTERFACE_DEFINED)
    %IEventSystem2_INTERFACE_DEFINED = 1

INTERFACE IEventSystem2 $IID_IEventSystem2

   INHERIT IDispatch

   ' =====================================================================================
   ' IEventSystem Methods
   ' =====================================================================================
   METHOD Query <1> ( _                                 ' VTable offset = 28
     BYVAL progID AS WSTRING _                          ' __in BSTR progID
   , BYVAL queryCriteria AS WSTRING _                   ' __in BSTR queryCriteria
   , BYREF errorIndex AS LONG _                         ' __out int *errorIndex
   ) AS IUnknown                                        ' __retval_out IUnknown **ppInterface
   ' =====================================================================================
   METHOD Store <2> ( _                                 ' VTable offset = 32
     BYVAL ProgID AS WSTRING _                          ' __in BSTR ProgID
   , BYVAL pInterface AS IUnknown _                     ' __in IUnknown *pInterface
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 36
     BYVAL progID AS WSTRING _                          ' __in BSTR progID
   , BYVAL queryCriteria AS WSTRING _                   ' __in BSTR queryCriteria
   , BYREF errorIndex AS LONG _                         ' __out int *errorIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EventObjectChangeEventClassID <4> ( _   ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrEventClassID
   ' =====================================================================================
   METHOD QueryS <5> ( _                                ' VTable offset = 44
     BYVAL progID AS WSTRING _                          ' __in BSTR progID
   , BYVAL queryCriteria AS WSTRING _                   ' __in BSTR queryCriteria
   ) AS IUnknown                                        ' __retval_out IUnknown **ppInterface
   ' =====================================================================================
   METHOD RemoveS <6> ( _                               ' VTable offset = 48
     BYVAL progID AS WSTRING _                          ' __in BSTR progID
   , BYVAL queryCriteria AS WSTRING _                   ' __in BSTR queryCriteria
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IEventSystem2 Methods
   ' =====================================================================================
   METHOD GetVersion <7> ( _                            ' VTable offset = 52
     BYREF pnVersion AS LONG _                          ' __out int* pnVersion
   )                                                    ' void
   ' =====================================================================================
   METHOD VerifyTransientSubscribers <8> ( _            ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventSystem2_INTERFACE_DEFINED__ */

' // Included in the typelib of es.dll, but not in EventSys.h

' ########################################################################################
' Interface name = IEventClassInternal
' IID = {9F83871A-195F-44B5-A46F-18FFFE152F7C}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEventClassInternal_INTERFACE_DEFINED)
    %IEventClassInternal_INTERFACE_DEFINED = 1

INTERFACE IEventClassInternal $IID_IEventClassInternal

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetAllowPerUserInprocActivation ( _           ' VTable offset = 12
     BYREF pfAllowPerUserInprocActivation AS LONG _     ' __out long *pfAllowPerUserInprocActivation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllowPerUserActivateAsActivator ( _        ' VTable offset = 16
     BYREF pfAllowPerUserActivateAsActivator AS LONG _  ' __out long *pfAllowPerUserActivateAsActivator
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllowPerUserMoniker ( _                    ' VTable offset = 20
     BYREF pfAllowPerUserMoniker AS LONG _              ' __out long *pfAllowPerUserMoniker
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSerialFiringTimeout ( _                    ' VTable offset = 24
     BYREF pdwSerialFiringTimeout AS DWORD _            ' __out DWORD *pdwSerialFiringTimeout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventClassInternal_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAmAFiringAgent
' IID = {0771CB93-DA7C-44B5-8196-422E6A2FBC40}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAmAFiringAgent_INTERFACE_DEFINED)
    %IAmAFiringAgent_INTERFACE_DEFINED = 1

INTERFACE IAmAFiringAgent $IID_IAmAFiringAgent

   INHERIT IUnknown

END INTERFACE

#ENDIF   ' /* __IAmAFiringAgent_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventSubscriptionInternal
' IID = {9B724996-D383-4C5F-B0F6-2814708C7633}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEventSubscriptionInternal_INTERFACE_DEFINED)
    %IEventSubscriptionInternal_INTERFACE_DEFINED = 1

INTERFACE IEventSubscriptionInternal $IID_IEventSubscriptionInternal

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsTransient ( _                               ' VTable offset = 12
     BYREF pfIsTransient AS LONG _                      ' __out long *pfIsTransient
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventSubscriptionInternal_INTERFACE_DEFINED__ */
