' ########################################################################################
' Microsoft Windows
' File: CGdipLineCaps.inc
' Contents: GDI+ custom line cap class.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CGDIPLINECAPS_INC = 1

' ########################################################################################
' CGdipCustomLineCap Class
' ########################################################################################
CLASS CGdipCustomLineCap

   INSTANCE m_hStatus AS LONG
   INSTANCE m_pCustomLineCap AS DWORD

   ' =====================================================================================
   ' Cleanup
   ' =====================================================================================
   CLASS METHOD Destroy
      IF m_pCustomLineCap THEN GdipDeleteCustomLineCap(m_pCustomLineCap)
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   ' IGdipCustomLineCap interface
   ' #####################################################################################
   INTERFACE IGdipCustomLineCap : INHERIT IAutomation

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to the Image object.
   ' =====================================================================================
   PROPERTY GET Ptr () THREADSAFE AS DWORD
      PROPERTY = m_pCustomLineCap
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the Image object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      IF m_pCustomLineCap THEN GdipDeleteCustomLineCap(m_pCustomLineCap)
      m_pCustomLineCap = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a CustomLineCap object from a fill path and a stroke path.
   ' =====================================================================================
   METHOD CustomLineCap (BYVAL pFillPath AS IGdipGraphicsPath, BYVAL pStrokePath AS IGdipGraphicsPath, OPTIONAL BYVAL baseCap AS LONG, BYVAL baseInset AS SINGLE) THREADSAFE AS LONG
      IF m_pCustomLineCap THEN GdipDeleteCustomLineCap(m_pCustomLineCap)
      m_hStatus = GdipCreateCustomLineCap(IIF(ISOBJECT(pFillPath), pFillPath.Ptr, %NULL), _
                  IIF(ISOBJECT(pStrokePath), pStrokePath.Ptr, %NULL), baseCap, baseinset, m_pCustomLineCap)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the LineCap object used to start and end lines within the GraphicsPath object
   ' that defines this CustomLineCap object.
   ' =====================================================================================
   METHOD SetStrokeCaps (BYVAL startCap AS LONG, BYVAL endCap AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetCustomLineCapStrokeCaps(m_pCustomLineCap, startCap, endCap)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The SetStrokeCap method sets the LineCap object used to start and end lines within
   ' the GraphicsPath object that defines this CustomLineCap object.
   ' =====================================================================================
   METHOD SetStrokeCap (BYVAL strokeCap AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetCustomLineCapStrokeCaps(m_pCustomLineCap, strokeCap, strokeCap)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the end cap styles for both the start line cap and the end line cap. Line caps
   ' are LineCap objects that end the individual lines within a path.
   ' =====================================================================================
   METHOD GetStrokeCaps (BYREF startCap AS LONG, BYREF endCap AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipGetCustomLineCapStrokeCaps(m_pCustomLineCap, startCap, endCap)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the style of line join for the stroke. The line join specifies how two lines that
   ' intersect within the GraphicsPath object that makes up the custom line cap are joined.
   ' =====================================================================================
   METHOD SetStrokeJoin (BYVAL lineJoin AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetCustomLineCapStrokeJoin(m_pCustomLineCap, lineJoin)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the style of LineJoin used to join multiple lines in the same GraphicsPath object.
   ' =====================================================================================
   METHOD GetStrokeJoin () THREADSAFE AS LONG
      LOCAL lineJoin AS LONG
      m_hStatus = GdipGetCustomLineCapStrokeJoin(m_pCustomLineCap, lineJoin)
      METHOD = lineJoin
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the LineCap that appears as part of this CustomLineCap at the end of a line.
   ' =====================================================================================
   METHOD SetBaseCap (BYVAL baseCap AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetCustomLineCapBaseCap(m_pCustomLineCap, baseCap)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the style of the base cap. The base cap is a LineCap object used as a cap at the
   ' end of a line along with this CustomLineCap object.
   ' =====================================================================================
   METHOD GetBaseCap () THREADSAFE AS LONG
      LOCAL baseCap AS LONG
      m_hStatus = GdipGetCustomLineCapBaseCap(m_pCustomLineCap, baseCap)
      METHOD = baseCap
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the base inset value of this custom line cap. This is the distance between the
   ' end of a line and the base cap.
   ' =====================================================================================
   METHOD SetBaseInset (BYVAL inset AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipSetCustomLineCapBaseInset(m_pCustomLineCap, inset)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the distance between the base cap to the start of the line.
   ' =====================================================================================
   METHOD GetBaseInset () THREADSAFE AS SINGLE
      LOCAL inset AS SINGLE
      m_hStatus = GdipGetCustomLineCapBaseInset(m_pCustomLineCap, inset)
      METHOD = inset
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the value of the scale width. This is the amount to scale the custom line cap
   ' relative to the width of the Pen used to draw lines. The default value of 1.0 does
   ' not scale the line cap.
   ' =====================================================================================
   METHOD SetWidthScale (BYVAL widthScale AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipSetCustomLineCapWidthScale(m_pCustomLineCap, widthScale)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the value of the scale width. This is the amount to scale the custom line cap
   ' relative to the width of the Pen object used to draw a line. The default value of 1.0
   ' does not scale the line cap.
   ' =====================================================================================
   METHOD GetWidthScale () THREADSAFE AS SINGLE
      LOCAL widthScale AS SINGLE
      m_hStatus = GdipGetCustomLineCapWidthScale(m_pCustomLineCap, widthScale)
      METHOD = widthScale
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new CustomLineCap object based on this CustomLineCap object.
   ' =====================================================================================
   METHOD Clone () THREADSAFE AS IGdipCustomLineCap
      LOCAL pCustomLineCap AS IGdipCustomLineCap
      LOCAL pCustomLineCapPtr AS DWORD
      m_hStatus = GdipCloneCustomLineCap(m_pCustomLineCap, pCustomLineCapPtr)
      pCustomLineCap = CLASS "CGdipCustomLineCap"
      pCustomLineCap.Ptr = pCustomLineCapPtr
      METHOD = pCustomLineCap
   END METHOD
   ' =====================================================================================

   END INTERFACE

   ' #####################################################################################
   ' IGdipAdjustableArrowCap interface
   ' Inherits from IGdipCustomeLineCap.
   ' #####################################################################################
   INTERFACE IGdipAdjustableArrowCap : INHERIT IAutomation

   ' *** IGdipCustomeLineCap methods ***

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to the Image object.
   ' =====================================================================================
   PROPERTY GET Ptr () THREADSAFE AS DWORD
      PROPERTY = m_pCustomLineCap
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the Image object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      LOCAL pGdipAdjustableArrowCap AS IGdipCustomLineCap
      pGdipAdjustableArrowCap = ME
      pGdipAdjustableArrowCap.Ptr = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new instance of the CGdipCustomLineCap class from a fill path and a stroke path.
   ' =====================================================================================
   METHOD CustomLineCap (BYVAL pFillPath AS IGdipGraphicsPath, BYVAL pStrokePath AS IGdipGraphicsPath, BYVAL baseCap AS LONG, BYVAL baseInset AS SINGLE) THREADSAFE AS LONG
      LOCAL pGdipAdjustableArrowCap AS IGdipCustomLineCap
      pGdipAdjustableArrowCap = ME
      METHOD = pGdipAdjustableArrowCap.CustomLineCap(pFillPath, pStrokePath, baseCap, baseinset)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the LineCap object used to start and end lines within the GraphicsPath object
   ' that defines this CustomLineCap object.
   ' =====================================================================================
   METHOD SetStrokeCaps (BYVAL startCap AS LONG, BYVAL endCap AS LONG) THREADSAFE AS LONG
      LOCAL pGdipAdjustableArrowCap AS IGdipCustomLineCap
      pGdipAdjustableArrowCap = ME
      METHOD = pGdipAdjustableArrowCap.SetStrokeCaps(startCap, endCap)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The SetStrokeCap method sets the LineCap object used to start and end lines within
   ' the GraphicsPath object that defines this CustomLineCap object.
   ' =====================================================================================
   METHOD SetStrokeCap (BYVAL strokeCap AS LONG) THREADSAFE AS LONG
      LOCAL pGdipAdjustableArrowCap AS IGdipCustomLineCap
      pGdipAdjustableArrowCap = ME
      METHOD = pGdipAdjustableArrowCap.SetStrokeCaps(strokeCap, strokeCap)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the end cap styles for both the start line cap and the end line cap. Line caps
   ' are LineCap objects that end the individual lines within a path.
   ' =====================================================================================
   METHOD GetStrokeCaps (BYREF startCap AS LONG, BYREF endCap AS LONG) THREADSAFE AS LONG
      LOCAL pGdipAdjustableArrowCap AS IGdipCustomLineCap
      pGdipAdjustableArrowCap = ME
      METHOD = pGdipAdjustableArrowCap.GetStrokeCaps(startCap, endCap)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the style of line join for the stroke. The line join specifies how two lines that
   ' intersect within the GraphicsPath object that makes up the custom line cap are joined.
   ' =====================================================================================
   METHOD SetStrokeJoin (BYVAL lineJoin AS LONG) THREADSAFE AS LONG
      LOCAL pGdipAdjustableArrowCap AS IGdipCustomLineCap
      pGdipAdjustableArrowCap = ME
      METHOD = pGdipAdjustableArrowCap.SetStrokeJoin(lineJoin)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the style of LineJoin used to join multiple lines in the same GraphicsPath object.
   ' =====================================================================================
   METHOD GetStrokeJoin () THREADSAFE AS LONG
      LOCAL pGdipAdjustableArrowCap AS IGdipCustomLineCap
      pGdipAdjustableArrowCap = ME
      METHOD = pGdipAdjustableArrowCap.GetStrokeJoin
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the LineCap that appears as part of this CustomLineCap at the end of a line.
   ' =====================================================================================
   METHOD SetBaseCap (BYVAL baseCap AS LONG) THREADSAFE AS LONG
      LOCAL pGdipAdjustableArrowCap AS IGdipCustomLineCap
      pGdipAdjustableArrowCap = ME
      METHOD = pGdipAdjustableArrowCap.SetBaseCap(baseCap)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the style of LineJoin used to join multiple lines in the same GraphicsPath object.
   ' =====================================================================================
   METHOD GetBaseCap () THREADSAFE AS LONG
      LOCAL pGdipAdjustableArrowCap AS IGdipCustomLineCap
      pGdipAdjustableArrowCap = ME
      METHOD = pGdipAdjustableArrowCap.GetBaseCap
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the base inset value of this custom line cap. This is the distance between the
   ' end of a line and the base cap.
   ' =====================================================================================
   METHOD SetBaseInset (BYVAL inset AS SINGLE) THREADSAFE AS LONG
      LOCAL pGdipAdjustableArrowCap AS IGdipCustomLineCap
      pGdipAdjustableArrowCap = ME
      METHOD = pGdipAdjustableArrowCap.SetBaseInset(inset)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the distance between the base cap to the start of the line.
   ' =====================================================================================
   METHOD GetBaseInset () THREADSAFE AS SINGLE
      LOCAL pGdipAdjustableArrowCap AS IGdipCustomLineCap
      pGdipAdjustableArrowCap = ME
      METHOD = pGdipAdjustableArrowCap.GetBaseInset
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the value of the scale width. This is the amount to scale the custom line cap
   ' relative to the width of the Pen used to draw lines. The default value of 1.0 does
   ' not scale the line cap.
   ' =====================================================================================
   METHOD SetWidthScale (BYVAL widthScale AS SINGLE) THREADSAFE AS LONG
      LOCAL pGdipAdjustableArrowCap AS IGdipCustomLineCap
      pGdipAdjustableArrowCap = ME
      METHOD = pGdipAdjustableArrowCap.SetWidthScale(widthScale)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the value of the scale width. This is the amount to scale the custom line cap
   ' relative to the width of the Pen object used to draw a line. The default value of 1.0
   ' does not scale the line cap.
   ' =====================================================================================
   METHOD GetWidthScale () THREADSAFE AS SINGLE
      LOCAL pGdipAdjustableArrowCap AS IGdipCustomLineCap
      pGdipAdjustableArrowCap = ME
      METHOD = pGdipAdjustableArrowCap.GetWidthScale
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new CustomLineCap object based on this CustomLineCap object.
   ' =====================================================================================
   METHOD Clone () THREADSAFE AS IGdipCustomLineCap
      LOCAL pGdipAdjustableArrowCap AS IGdipCustomLineCap
      pGdipAdjustableArrowCap = ME
      METHOD = pGdipAdjustableArrowCap.Clone
   END METHOD
   ' =====================================================================================

   ' *** IGdipAdjustableArrowCap methods ***

   ' =====================================================================================
   ' Creates an adjustable arrow line cap with the specified height and width. The arrow
   ' line cap can be filled or nonfilled. The middle inset defaults to zero.
   ' =====================================================================================
   METHOD AdjustableArrowCap (BYVAL nHeight AS SINGLE, BYVAL nWidth AS SINGLE, BYVAL isFilled AS LONG) THREADSAFE AS LONG
      IF m_pCustomLineCap THEN GdipDeleteCustomLineCap(m_pCustomLineCap)
      m_hStatus = GdipCreateAdjustableArrowCap(nHeight, nWidth, isFilled, m_pCustomLineCap)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the height of the arrow cap. This is the distance from the base of the arrow to its vertex.
   ' =====================================================================================
   METHOD SetHeight (BYVAL nHeight AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipSetAdjustableArrowCapHeight(m_pCustomLineCap, nHeight)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the height of the arrow cap. This is the distance from the base of the arrow to its vertex.
   ' =====================================================================================
   METHOD GetHeight () THREADSAFE AS SINGLE
      LOCAL height_ AS SINGLE
      m_hStatus = GdipGetAdjustableArrowCapHeight(m_pCustomLineCap, height_)
      METHOD = height_
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the width of the arrow cap. The width is the distance between the endpoints of the base of the arrow.
   ' =====================================================================================
   METHOD SetWidth (BYVAL nWidth AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipSetAdjustableArrowCapWidth(m_pCustomLineCap, nWidth)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the width of the arrow cap. This is the distance from the base of the arrow to its vertex.
   ' =====================================================================================
   METHOD GetWidth () THREADSAFE AS SINGLE
      LOCAL width_ AS SINGLE
      m_hStatus = GdipGetAdjustableArrowCapWidth(m_pCustomLineCap, width_)
      METHOD = width_
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the number of units that the midpoint of the base shifts towards the vertex.
   ' =====================================================================================
   METHOD SetMiddleInset (BYVAL middleInset AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipSetAdjustableArrowCapMiddleInset(m_pCustomLineCap, middleInset)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the value of the inset. The middle inset is the number of units that the midpoint
   ' of the base shifts towards the vertex.
   ' =====================================================================================
   METHOD GetMiddleInset () THREADSAFE AS SINGLE
      LOCAL middleInset AS SINGLE
      m_hStatus = GdipGetAdjustableArrowCapMiddleInset(m_pCustomLineCap, middleInset)
      METHOD = middleInset
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the fill state of the arrow cap. If the arrow cap is not filled, only the outline is drawn.
   ' =====================================================================================
   METHOD SetFillState (BYVAL isFilled AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetAdjustableArrowCapFillState(m_pCustomLineCap, isFilled)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Determines whether the arrow cap is filled.
   ' =====================================================================================
   METHOD IsFilled () THREADSAFE AS LONG
      LOCAL isFilled AS LONG
      m_hStatus = GdipGetAdjustableArrowCapFillState(m_pCustomLineCap, isFilled)
      METHOD = isFilled
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
