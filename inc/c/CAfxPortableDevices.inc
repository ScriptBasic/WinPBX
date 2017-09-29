' ########################################################################################
' Microsoft Windows
' File: CAfxPortableDevices.inc
' Contents: Portable devices class.
' Copyright (c) 2012 José Roca.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CAFXPORTABLEDEVICES_INC = 1

#INCLUDE ONCE "PortableDeviceApi.inc"

' ########################################################################################
' CPortableDevices class.
' ########################################################################################
CLASS CAfxPortableDevices

   INSTANCE m_pPortableDeviceManager AS IPortableDeviceManager
   INSTANCE m_rgDeviceIDs() AS WSTRINGZ PTR
   INSTANCE m_pDeviceIDs AS IPowerCollection

   ' =====================================================================================
   ' Create method
   ' =====================================================================================
   CLASS METHOD Create
      m_pDeviceIDs = CLASS "PowerCollection"
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Destroy method
   ' =====================================================================================
   CLASS METHOD Destroy
      ' // Free the array of device identifiers
      LOCAL i AS LONG
      FOR i = LBOUND(m_rgDeviceIDs) TO UBOUND(m_rgDeviceIDs)
         CoTaskMemFree(BYVAL m_rgDeviceIDs(i))
      NEXT
   END METHOD
   ' =====================================================================================

   INTERFACE IAfxPortableDeviceManager : INHERIT IAutomation

   ' =====================================================================================
   ' Returns the number of portable devices.
   ' =====================================================================================
   PROPERTY GET Count () AS LONG
      PROPERTY = m_pDeviceIDs.Count
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves a reference to a collection of portable devices identifiers.
   ' =====================================================================================
   PROPERTY GET Devices() AS IPowerCollection
      m_pPortableDeviceManager = NEWCOM CLSID $CLSID_PortableDeviceManager
      IF ISNOTHING(m_pPortableDeviceManager) THEN PROPERTY OBJRESULT = %E_FAIL : EXIT PROPERTY
      LOCAL hr AS LONG
      LOCAL cPnPDeviceIDs AS DWORD
      m_pPortableDeviceManager.GetDevices(BYVAL %NULL, cPnPDeviceIDs)
      IF cPnPDeviceIDs = 0 THEN PROPERTY OBJRESULT = %E_FAIL : EXIT PROPERTY
      REDIM m_rgDeviceIDs(cPnPDeviceIDs - 1) AS INSTANCE WSTRINGZ PTR
      hr = m_pPortableDeviceManager.GetDevices(m_rgDeviceIDs(0), cPnPDeviceIDs)
      IF FAILED(hr) THEN PROPERTY OBJRESULT = hr : EXIT PROPERTY
      ' // Clear the collection
      m_pDeviceIDs.Clear
      ' // Save the IDs in the collection
      LOCAL i AS LONG
      LOCAL bstrIdx AS WSTRING
      LOCAL vID AS VARIANT
      FOR i = LBOUND(m_rgDeviceIDs) TO UBOUND(m_rgDeviceIDs)
         bstrIdx = FORMAT$(i)
         m_pDeviceIDs.Add bstrIdx, m_rgDeviceIDs(i)
      NEXT
      PROPERTY = m_pDeviceIDs
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Refreshes the list of devices that are connected to the computer.
   ' =====================================================================================
   METHOD RefreshDeviceList
      ' // Free the array of device identifiers
      LOCAL i AS LONG
      FOR i = LBOUND(m_rgDeviceIDs) TO UBOUND(m_rgDeviceIDs)
         CoTaskMemFree(BYVAL m_rgDeviceIDs(i))
      NEXT
      ' // Retrieve the collection of device identifiers
      IF ISNOTHING(m_pPortableDeviceManager) THEN
         ME.Devices
      ELSE
         LOCAL hr AS LONG
         LOCAL cPnPDeviceIDs AS DWORD
         m_pPortableDeviceManager.RefreshDeviceList
         m_pPortableDeviceManager.GetDevices(BYVAL %NULL, cPnPDeviceIDs)
         IF cPnPDeviceIDs = 0 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
         REDIM m_rgDeviceIDs(cPnPDeviceIDs - 1) AS INSTANCE WSTRINGZ PTR
         hr = m_pPortableDeviceManager.GetDevices(m_rgDeviceIDs(0), cPnPDeviceIDs)
         IF FAILED(hr) THEN METHOD OBJRESULT = hr : EXIT METHOD
         ' // Clear the collection
         m_pDeviceIDs.Clear
         ' // Save the IDs in the collection
         LOCAL bstrIdx AS WSTRING
         LOCAL vID AS VARIANT
         FOR i = LBOUND(m_rgDeviceIDs) TO UBOUND(m_rgDeviceIDs)
            bstrIdx = FORMAT$(i)
            m_pDeviceIDs.Add bstrIdx, m_rgDeviceIDs(i)
         NEXT
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the device string.
   ' =====================================================================================
   PROPERTY GET DeviceString (BYVAL idx AS DWORD) AS WSTRING
      LOCAL pwsz AS WSTRINGZ PTR
      IF idx < LBOUND(m_rgDeviceIDs) OR idx > UBOUND(m_rgDeviceIDs) THEN EXIT PROPERTY
      pwsz = m_rgDeviceIDs(idx)
      IF pwsz THEN PROPERTY = @pwsz
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves the description of a device.
   ' =====================================================================================
   PROPERTY GET Description (BYVAL vDeviceID AS VARIANT) AS WSTRING
      LOCAL pszPnPDeviceID AS DWORD
      pszPnPDeviceID = VARIANT#(vDeviceID)
      IF pszPnPDeviceID = 0 THEN PROPERTY OBJRESULT = %E_POINTER : EXIT PROPERTY
      IF ISNOTHING(m_pPortableDeviceManager) THEN PROPERTY OBJRESULT = %E_FAIL : EXIT PROPERTY
      LOCAL hr AS LONG
      LOCAL cchDeviceDescription AS DWORD
      LOCAL bstrDescription AS WSTRING
      m_pPortableDeviceManager.GetDeviceDescription(pszPnPDeviceID, %NULL, cchDeviceDescription)
      IF cchDeviceDescription = 0 THEN PROPERTY OBJRESULT = %E_FAIL : EXIT PROPERTY
      bstrDescription = NUL$(cchDeviceDescription)
      hr = m_pPortableDeviceManager.GetDeviceDescription(pszPnPDeviceID, STRPTR(bstrDescription), cchDeviceDescription)
      IF FAILED(hr) THEN PROPERTY OBJRESULT = hr : EXIT PROPERTY
      PROPERTY = bstrDescription
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves the friendly name of a device.
   ' =====================================================================================
   PROPERTY GET FriendlyName (BYVAL vDeviceID AS VARIANT) AS WSTRING
      LOCAL pszPnPDeviceID AS DWORD
      pszPnPDeviceID = VARIANT#(vDeviceID)
      IF pszPnPDeviceID = 0 THEN PROPERTY OBJRESULT = %E_POINTER : EXIT PROPERTY
      IF ISNOTHING(m_pPortableDeviceManager) THEN PROPERTY OBJRESULT = %E_FAIL : EXIT PROPERTY
      LOCAL hr AS LONG
      LOCAL cchDeviceFriendlyName AS DWORD
      LOCAL bstrFriendlyName AS WSTRING
      m_pPortableDeviceManager.GetDeviceFriendlyName(pszPnPDeviceID, %NULL, cchDeviceFriendlyName)
      IF cchDeviceFriendlyName = 0 THEN PROPERTY OBJRESULT = %E_FAIL : EXIT PROPERTY
      bstrFriendlyName = NUL$(cchDeviceFriendlyName)
      hr = m_pPortableDeviceManager.GetDeviceFriendlyName(pszPnPDeviceID, STRPTR(bstrFriendlyName), cchDeviceFriendlyName)
      IF FAILED(hr) THEN PROPERTY OBJRESULT = hr : EXIT PROPERTY
      PROPERTY = bstrFriendlyName
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves the manufacturer of a device.
   ' =====================================================================================
   PROPERTY GET Manufacturer (BYVAL vDeviceID AS VARIANT) AS WSTRING
      LOCAL pszPnPDeviceID AS DWORD
      pszPnPDeviceID = VARIANT#(vDeviceID)
      IF pszPnPDeviceID = 0 THEN PROPERTY OBJRESULT = %E_POINTER : EXIT PROPERTY
      IF ISNOTHING(m_pPortableDeviceManager) THEN PROPERTY OBJRESULT = %E_FAIL : EXIT PROPERTY
      LOCAL hr AS LONG
      LOCAL cchDeviceManufacturer AS DWORD
      LOCAL bstrManufacturer AS WSTRING
      m_pPortableDeviceManager.GetDeviceFriendlyName(pszPnPDeviceID, %NULL, cchDeviceManufacturer)
      IF cchDeviceManufacturer = 0 THEN PROPERTY OBJRESULT = %E_FAIL : EXIT PROPERTY
      bstrManufacturer = NUL$(cchDeviceManufacturer)
      hr = m_pPortableDeviceManager.GetDeviceManufacturer(pszPnPDeviceID, STRPTR(bstrManufacturer), cchDeviceManufacturer)
      IF FAILED(hr) THEN PROPERTY OBJRESULT = hr : EXIT PROPERTY
      PROPERTY = bstrManufacturer
   END PROPERTY
   ' =====================================================================================

   END INTERFACE

END CLASS
' ########################################################################################
