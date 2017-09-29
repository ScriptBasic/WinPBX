' ########################################################################################
' Microsoft Windows
' File: CGdipCachedBitmap.inc
' Contents: GDI+ cached bitmap class.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CGDIPCACHEDBITMAP_INC = 1

' ########################################################################################
' CGdipCachedBitmap Class
' ########################################################################################
CLASS CGdipCachedBitmap

   INSTANCE m_hStatus AS LONG
   INSTANCE m_pCachedBitmap AS DWORD

   ' =====================================================================================
   ' Cleanup
   ' =====================================================================================
   CLASS METHOD Destroy
      IF m_pCachedBitmap THEN GdipDeleteCachedBitmap(m_pCachedBitmap)
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   ' IGdipCachedBitmap interface.
   ' #####################################################################################
   INTERFACE IGdipCachedBitmap : INHERIT IAutomation

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to the cached bitmap object.
   ' =====================================================================================
   PROPERTY GET Ptr () THREADSAFE AS DWORD
      PROPERTY = m_pCachedBitmap
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the cached bitmap object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      IF m_pCachedBitmap THEN GdipDeleteCachedBitmap(m_pCachedBitmap)
      m_pCachedBitmap = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a CachedBitmap object based on a Bitmap object and a Graphics object. The
   ' cached bitmap takes the pixel data from the Bitmap object and stores it in a format
   ' that is optimized for the display device associated with the Graphics object.
   ' =====================================================================================
   METHOD CachedBitmap (BYVAL pBitmap AS IGdipBitmap, BYVAL pGraphics AS IGdipGraphics) THREADSAFE AS LONG
      IF m_pCachedBitmap THEN GdipDeleteCachedBitmap(m_pCachedBitmap)
      m_hStatus = GdipCreateCachedBitmap(pBitmap.Ptr, pGraphics.Ptr, m_pCachedBitmap)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
' ########################################################################################
