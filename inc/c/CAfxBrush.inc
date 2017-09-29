' ########################################################################################
' Microsoft Windows
' File: CAfxBrush.inc
' Contents: Brush class.
' Copyright (c) 2011 José Roca.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CAFXBRUSH_INC = 1

#INCLUDE ONCE "windows.inc"

' ########################################################################################
' CAfxBrush class.
' ########################################################################################
CLASS CAfxBrush

   INSTANCE m_hBrush  AS DWORD
   INSTANCE m_dwStyle AS DWORD
   INSTANCE m_dwColor AS DWORD
   INSTANCE m_lHatch  AS LONG
   INSTANCE m_fDirty  AS LONG

#IF %DEF(%UNICODE)
   INSTANCE m_BrushName AS WSTRING
#ELSE
   INSTANCE m_BrushName AS STRING
#ENDIF

   ' =====================================================================================
   ' Create method
   ' =====================================================================================
   CLASS METHOD Create
      m_fDirty = -1
      m_dwStyle  = %BS_SOLID
      m_dwColor  = &H00FFFFFF???
      m_BrushName = "Default brush"
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Destroy method
   ' =====================================================================================
   CLASS METHOD Destroy
      IF m_hBrush THEN DeleteObject(m_hBrush)
   END METHOD
   ' =====================================================================================

   INTERFACE IAfxBrush : INHERIT IAutomation

   ' =====================================================================================
   ' Creates a brush and returns an handle to it.
   ' =====================================================================================
   METHOD CreateBrush() AS DWORD
      LOCAL tlb AS LOGBRUSH
      IF m_fDirty THEN
         IF m_hBrush THEN
            DeleteObject m_hBrush
            m_hBrush = %NULL
         END IF
         tlb.lbStyle = m_dwStyle
         tlb.lbColor = m_dwColor
         tlb.lbHatch = m_lHatch
         m_hBrush = CreateBrushIndirect(tlb)
         m_fDirty = 0
      END IF
      METHOD = m_hBrush
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the handle of the brush. If the handle is null or the characteristics have
   ' been changed, it deletes the old brush and creates a new one.
   ' =====================================================================================
   PROPERTY GET hBrush() AS DWORD
      IF m_fDirty THEN ME.CreateBrush
      PROPERTY = m_hBrush
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the style of the brush.
   ' =====================================================================================
   PROPERTY GET Style() AS DWORD
      PROPERTY = m_dwStyle
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the style of the brush
   ' =====================================================================================
   PROPERTY SET Style (BYVAL dwStyle AS DWORD)
      m_fDirty = -1
      m_dwStyle = dwStyle
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the color of the brush.
   ' =====================================================================================
   PROPERTY GET Color() AS DWORD
      PROPERTY = m_dwColor
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the color of the brush.
   ' =====================================================================================
   PROPERTY SET Color (BYVAL dwColor AS DWORD)
      m_fDirty = -1
      m_dwColor = dwColor
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the hatch of the brush.
   ' =====================================================================================
   PROPERTY GET Hatch() AS LONG
      PROPERTY = m_lHatch
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the hatch of the brush.
   ' =====================================================================================
   PROPERTY SET Hatch (BYVAL lHatch AS LONG)
      m_fDirty = -1
      m_lHatch = lHatch
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the Brush name
   ' =====================================================================================
#IF %DEF(%UNICODE)
   PROPERTY GET Name () AS WSTRING
#ELSE
   PROPERTY GET Name () AS STRING
#ENDIF
      PROPERTY = m_BrushName
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the Brush name
   ' =====================================================================================
#IF %DEF(%UNICODE)
   PROPERTY SET Name (BYVAL strName AS WSTRING)
#ELSE
   PROPERTY SET Name (BYVAL strName AS STRING)
#ENDIF
      m_BrushName = strName
   END PROPERTY
   ' =====================================================================================

   END INTERFACE
   ' =====================================================================================

END CLASS
' ########################################################################################
