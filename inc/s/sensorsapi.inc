' ########################################################################################
' Microsoft Windows
' File: sensorsapi.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SENSORSAPI_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "propsys.inc"
#INCLUDE ONCE "PortableDeviceTypes.inc"

' enum SensorState
%SENSOR_STATE_MIN           = 0
%SENSOR_STATE_READY         = %SENSOR_STATE_MIN
%SENSOR_STATE_NOT_AVAILABLE = %SENSOR_STATE_READY         + 1
%SENSOR_STATE_NO_DATA       = %SENSOR_STATE_NOT_AVAILABLE + 1
%SENSOR_STATE_INITIALIZING  = %SENSOR_STATE_NO_DATA       + 1
%SENSOR_STATE_ACCESS_DENIED = %SENSOR_STATE_INITIALIZING  + 1
%SENSOR_STATE_ERROR         = %SENSOR_STATE_ACCESS_DENIED + 1
%SENSOR_STATE_MAX           = %SENSOR_STATE_ERROR

' enum SensorConnectionType
%SENSOR_CONNECTION_TYPE_PC_INTEGRATED = 0
%SENSOR_CONNECTION_TYPE_PC_ATTACHED   = %SENSOR_CONNECTION_TYPE_PC_INTEGRATED + 1
%SENSOR_CONNECTION_TYPE_PC_EXTERNAL   = %SENSOR_CONNECTION_TYPE_PC_ATTACHED   + 1

' enum LOCATION_DESIRED_ACCURACY
%LOCATION_DESIRED_ACCURACY_DEFAULT = 0
%LOCATION_DESIRED_ACCURACY_HIGH    = %LOCATION_DESIRED_ACCURACY_DEFAULT + 1

'typedef GUID SENSOR_CATEGORY_ID;
'typedef REFGUID REFSENSOR_CATEGORY_ID;
'typedef GUID SENSOR_TYPE_ID;
'typedef REFGUID REFSENSOR_TYPE_ID;
'typedef GUID SENSOR_ID;
'typedef REFGUID REFSENSOR_ID;

$CLSID_SensorManager = GUID$("{77A1C827-FCD2-4689-8915-9D613CC5FA3E}")
$CLSID_SensorCollection = GUID$("{79C43ADB-A429-469F-AA39-2F2B74B75937}")
$CLSID_Sensor = GUID$("{E97CED00-523A-4133-BF6F-D3A2DAE7F6BA}")
$CLSID_SensorDataReport = GUID$("{4EA9D6EF-694B-4218-8816-CCDA8DA74BBA}")
$CLSID_LogicalSensorManager = GUID$("{50A7B286-7D23-41E6-9440-4DAEE00DC5F0}")

$IID_ISensorManager = GUID$("{BD77DB67-45A8-42DC-8D00-6DCF15F8377A}")
$IID_ISensorCollection = GUID$("{23571E11-E545-4DD8-A337-B89BF44B10DF}")
$IID_ISensor = GUID$("{5FA08F80-2657-458E-AF75-46F73FA6AC5C}")
$IID_ISensorDataReport = GUID$("{0AB9DF9B-C4B5-4796-8898-0470706A2E1D}")
$IID_ISensorManagerEvents = GUID$("{9B3B0B86-266A-4AAD-B21F-FDE5501001B7}")
$IID_ISensorEvents = GUID$("{5D8DCC91-4641-47E7-B7C3-B74F48A6C391}")
$IID_ILogicalSensorManager = GUID$("{7490B4D4-1BE9-469A-9743-37A27C1D80AF}")

' ########################################################################################
' Interface name = ISensorManager
' IID = BD77DB67-45A8-42DC-8D00-6DCF15F8377A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISensorManager_INTERFACE_DEFINED)
    %ISensorManager_INTERFACE_DEFINED = 1

INTERFACE ISensorManager $IID_ISensorManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSensorsByCategory ( _                      ' VTable offset = 12
     BYREF sensorCategory AS GUID _                     ' __in REFSENSOR_CATEGORY_ID sensorCategory
   , BYREF ppSensorsFound AS ISensorCollection _        ' __out ISensorCollection **ppSensorsFound
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSensorsByType ( _                          ' VTable offset = 16
     BYREF sensorType AS GUID _                         ' __in REFSENSOR_TYPE_ID sensorType
   , BYREF ppSensorsFound AS ISensorCollection _        ' __out ISensorCollection **ppSensorsFound
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSensorByID ( _                             ' VTable offset = 20
     BYREF sensorID AS GUID _                           ' __in REFSENSOR_ID sensorID
   , BYREF ppSensor AS ISensor _                        ' __out ISensor **ppSensor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEventSink ( _                              ' VTable offset = 24
     BYVAL pEvents AS ISensorManagerEvents _            ' __in ISensorManagerEvents *pEvents
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestPermissions ( _                        ' VTable offset = 28
     BYVAL hParent AS DWORD _                           ' __in HWND hParent
   , BYVAL pSensors AS ISensorCollection _              ' __in ISensorCollection *pSensors
   , BYVAL fModal AS LONG _                             ' __in BOOL fModal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISensorManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISensorCollection
' IID = 23571E11-E545-4DD8-A337-B89BF44B10DF
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISensorCollection_INTERFACE_DEFINED)
    %ISensorCollection_INTERFACE_DEFINED = 1

INTERFACE ISensorCollection $IID_ISensorCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 12
     BYVAL ulIndex AS DWORD _                           ' __in ULONG ulIndex
   , BYREF ppSensor AS ISensor _                        ' __out ISensor **ppSensor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 16
     BYREF pCount AS DWORD _                            ' __out ULONG *pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Add ( _                                       ' VTable offset = 20
     BYVAL pSensor AS ISensor _                         ' __in ISensor *pSensor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Remove ( _                                    ' VTable offset = 24
     BYVAL pSensor AS ISensor _                         ' __in ISensor *pSensor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveByID ( _                                ' VTable offset = 28
     BYREF sensorID AS GUID _                           ' __in REFSENSOR_ID sensorID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISensorCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISensor
' IID = E97CED00-523A-4133-BF6F-D3A2DAE7F6BA
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISensor_INTERFACE_DEFINED)
    %ISensor_INTERFACE_DEFINED = 1

INTERFACE ISensor $IID_ISensor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetID ( _                                     ' VTable offset = 12
     BYREF pID AS GUID _                                ' __out SENSOR_ID *pID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCategory ( _                               ' VTable offset = 16
     BYREF pSensorCategory AS GUID _                    ' __out SENSOR_CATEGORY_ID *pSensorCategory
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 20
     BYREF pSensorType AS GUID _                        ' __out SENSOR_TYPE_ID *pSensorType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFriendlyName ( _                           ' VTable offset = 24
     BYREF pFriendlyName AS WSTRING _                   ' __out BSTR *pFriendlyName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 28
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY key
   , BYREF pProperty AS PROPVARIANT _                   ' __out PROPVARIANT *pProperty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperties ( _                             ' VTable offset = 32
     BYVAL pKeys AS IPortableDeviceKeyCollection _      ' __in IPortableDeviceKeyCollection *pKeys
   , BYREF ppProperties AS IPortableDeviceValues _      ' __out IPortableDeviceValues **ppProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSupportedDataFields ( _                    ' VTable offset = 36
     BYREF ppDataFields AS IPortableDeviceKeyCollection _ ' __out IPortableDeviceKeyCollection **ppDataFields
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProperties ( _                             ' VTable offset = 40
     BYVAL pProperties AS IPortableDeviceValues _       ' __in IPortableDeviceValues *pProperties
   , BYREF ppResults AS IPortableDeviceValues _         ' __out IPortableDeviceValues **ppResults
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SupportsDataField ( _                         ' VTable offset = 44
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY key
   , BYREF pIsSupported AS INTEGER _                    ' __out VARIANT_BOOL *pIsSupported
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 48
     BYREF pState AS LONG _                             ' __out SensorState *pState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 52
     BYREF ppDataReport AS ISensorDataReport _          ' __out ISensorDataReport **ppDataReport
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SupportsEvent ( _                             ' VTable offset = 56
     BYREF eventGuid AS GUID _                          ' __in REFGUID eventGuid
   , BYREF pIsSupported AS INTEGER _                    ' __out VARIANT_BOOL *pIsSupported
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEventInterest ( _                          ' VTable offset = 60
     BYREF ppValues AS GUID _                           ' __out GUID **ppValues
   , BYREF pCount AS DWORD _                            ' __out ULONG *pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEventInterest ( _                          ' VTable offset = 64
     BYREF pValues AS GUID _                            ' __in GUID *pValues
   , BYVAL count AS DWORD _                             ' __in ULONG count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEventSink ( _                              ' VTable offset = 68
     BYVAL pEvents AS ISensorEvents _                   ' __in ISensorEvents *pEvents
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISensor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISensorDataReport
' IID = 0AB9DF9B-C4B5-4796-8898-0470706A2E1D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISensorDataReport_INTERFACE_DEFINED)
    %ISensorDataReport_INTERFACE_DEFINED = 1

INTERFACE ISensorDataReport $IID_ISensorDataReport

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTimestamp ( _                              ' VTable offset = 12
     BYREF pTimeStamp AS SYSTEMTIME _                   ' __out SYSTEMTIME *pTimeStamp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSensorValue ( _                            ' VTable offset = 16
     BYREF pKey AS PROPERTYKEY _                        ' __in REFPROPERTYKEY pKey
   , BYREF pValue AS PROPVARIANT _                      ' __out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSensorValues ( _                           ' VTable offset = 20
     BYVAL pKeys AS IPortableDeviceKeyCollection _      ' __in IPortableDeviceKeyCollection *pKeys
   , BYREF ppValues AS IPortableDeviceValues _          ' __out IPortableDeviceValues **ppValues
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISensorDataReport_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISensorManagerEvents
' IID = 9B3B0B86-266A-4AAD-B21F-FDE5501001B7
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISensorManagerEvents_INTERFACE_DEFINED)
    %ISensorManagerEvents_INTERFACE_DEFINED = 1

INTERFACE ISensorManagerEvents $IID_ISensorManagerEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnSensorEnter ( _                             ' VTable offset = 12
     BYVAL pSensor AS ISensor _                         ' __in ISensor *pSensor
   , BYVAL state AS LONG _                              ' __in SensorState state
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISensorManagerEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISensorEvents
' IID = 5D8DCC91-4641-47E7-B7C3-B74F48A6C391
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISensorEvents_INTERFACE_DEFINED)
    %ISensorEvents_INTERFACE_DEFINED = 1

INTERFACE ISensorEvents $IID_ISensorEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnStateChanged ( _                            ' VTable offset = 12
     BYVAL pSensor AS ISensor _                         ' __in ISensor *pSensor
   , BYVAL state AS LONG _                              ' __in SensorState state
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDataUpdated ( _                             ' VTable offset = 12
     BYVAL pSensor AS ISensor _                         ' __in ISensor *pSensor
   , BYVAL pNewData AS ISensorDataReport _              ' __in ISensorDataReport *pNewData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnEvent ( _                                   ' VTable offset = 16
     BYVAL pSensor AS ISensor _                         ' __in ISensor *pSensor
   , BYREF eventID AS GUID _                            ' __in REFGUID eventID
   , BYVAL pEventData AS IPortableDeviceValues _        ' __in IPortableDeviceValues *pEventData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnLeave ( _                                   ' VTable offset = 20
     BYREF ID AS GUID _                                 ' __in REFSENSOR_ID ID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISensorEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ILogicalSensorManager
' IID = 7490B4D4-1BE9-469A-9743-37A27C1D80AF
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ILogicalSensorManager_INTERFACE_DEFINED)
    %ILogicalSensorManager_INTERFACE_DEFINED = 1

INTERFACE ILogicalSensorManager $IID_ILogicalSensorManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Connect ( _                                   ' VTable offset = 12
     BYREF logicalID AS GUID _                          ' __in REFGUID logicalID
   , BYVAL pPropertyStore AS IPropertyStore _           ' __in IPropertyStore *pPropertyStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Uninstall ( _                                 ' VTable offset = 16
     BYREF logicalID AS GUID _                          ' __in REFGUID logicalID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Disconnect ( _                                ' VTable offset = 20
     BYREF logicalID AS GUID _                          ' __in REFGUID logicalID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ILogicalSensorManager_INTERFACE_DEFINED__ */
