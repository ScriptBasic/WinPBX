' ########################################################################################
' Microsoft Windows
' File: CGdipFontCollection.inc
' Contents: GDI+ Font collections class.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CGDIPFONTCOLLECTION_INC = 1

' ########################################################################################
' GdipFontCollection Class
' ########################################################################################
CLASS CGdipFontCollection

   INSTANCE m_hStatus AS LONG
   INSTANCE m_pFontCollection AS DWORD
   INSTANCE m_pPrivateFontCollection AS DWORD
   INSTANCE m_pInstalledFontCollection AS DWORD

   ' =====================================================================================
   ' Create method
   ' =====================================================================================
   CLASS METHOD Create
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Cleanup
   ' =====================================================================================
   CLASS METHOD Destroy
      IF m_pPrivateFontCollection THEN GdipDeletePrivateFontCollection(m_pPrivateFontCollection)
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   ' // Bridge interface to allow to pas both an IGdipPrivateFontCollection or an
   ' // IGdipInstalledFontCollection as a parameter.
   ' #####################################################################################
   INTERFACE IGdipFontCollection : INHERIT IAutomation
   ' #####################################################################################

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to the object.
   ' =====================================================================================
   PROPERTY GET Ptr () THREADSAFE AS DWORD
      PROPERTY = m_pFontCollection
   END PROPERTY
   ' =====================================================================================

   END INTERFACE

   ' #####################################################################################
   INTERFACE IGdipPrivateFontCollection : INHERIT IAutomation
   ' #####################################################################################

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to the object.
   ' =====================================================================================
   PROPERTY GET Ptr () THREADSAFE AS DWORD
      PROPERTY = m_pPrivateFontCollection
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      IF m_pPrivateFontCollection THEN GdipDeletePrivateFontCollection(m_pPrivateFontCollection)
      m_pPrivateFontCollection = pPtr
      m_pFontCollection = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Creates an empty PrivateFontCollection object.
   ' =====================================================================================
   METHOD PrivateFontCollection () THREADSAFE AS LONG
      m_hStatus = GdipNewPrivateFontCollection(m_pPrivateFontCollection)
      m_pFontCollection = m_pPrivateFontCollection
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a font file to this private font collection.
   ' =====================================================================================
   METHOD AddFontFile (BYREF wszFileName AS WSTRINGZ) THREADSAFE AS LONG
      m_hStatus = GdipPrivateAddFontFile(m_pPrivateFontCollection, wszFileName)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a font that is contained in system memory to a Windows GDI+ font collection.
   ' =====================================================================================
   METHOD AddMemoryFont (BYVAL pMemory AS DWORD, BYVAL length AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipPrivateAddMemoryFont(m_pPrivateFontCollection, pMemory, length)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   END INTERFACE

   ' #####################################################################################
   INTERFACE IGdipInstalledFontCollection : INHERIT IAutomation
   ' #####################################################################################

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to the object.
   ' =====================================================================================
   PROPERTY GET Ptr () THREADSAFE AS DWORD
      PROPERTY = m_pInstalledFontCollection
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      m_pInstalledFontCollection = pPtr
      m_pFontCollection = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Creates an empty InstalledFontCollection object.
   ' =====================================================================================
   METHOD InstalledFontCollection () THREADSAFE AS LONG
      m_hStatus = GdipNewinstalledFontCollection(m_pInstalledFontCollection)
      m_pFontCollection = m_pInstalledFontCollection
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of font families contained in this font collection.
   ' =====================================================================================
   METHOD GetFamilyCount () THREADSAFE AS LONG
      LOCAL numFound AS LONG
      m_hStatus = GdipGetFontCollectionFamilyCount(m_pInstalledFontCollection, numFound)
      METHOD = numFound
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the font families contained in this font collection.
   ' =====================================================================================
   METHOD GetFamilies (BYVAL numSought AS LONG, BYREF gpfamilies AS IGdipInstalledFontCollection, BYREF numFound AS LONG) THREADSAFE AS LONG
      IF numSought <= 0 OR VARPTR(gpfamilies) = 0 OR VARPTR(numFound) = 0 THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      LOCAL i AS LONG
      REDIM rgfamilies(numSought - 1) AS DWORD
      m_hStatus = GdipGetFontCollectionFamilyList(m_pInstalledFontCollection, numSought, rgfamilies(0), numFound)
      IF m_hStatus = %StatusOK THEN
         LOCAL pFamilyPtr AS DWORD
         REDIM pFamilies(numSought - 1) AS IGdipInstalledFontCollection AT VARPTR(gpfamilies)
         FOR i = 0 TO numFound - 1
            m_hStatus = GdipCloneFontFamily(rgfamilies(i), pFamilyPtr)
            pFamilies(i).Ptr = pFamilyPtr
         NEXT
      END IF
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
' ########################################################################################
