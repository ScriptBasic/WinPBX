' ########################################################################################
' CSED Editor
' File: CSED_GOTOPROC.INC
' Contents: Procedures to jump to the beginning or end of procedures in the editor.
' Copyright (c) 2012 José Roca
' Adapted from code written by Steve Miltiadous
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

%ID_PROCNULL  = 0
%ID_PROCSTART = 1
%ID_PROCEND   = 2

' ========================================================================================
TYPE CSED_PROCSTRUCT
   WhatIsUp   AS LONG
   WhatIsDown AS LONG
   UpLnNo     AS LONG
   DnLnNo     AS LONG
   ProcName   AS ASCIIZ * 65
END TYPE
' ========================================================================================

' ========================================================================================
' Returns true if cursor within SUB/FUNCTION
' ========================================================================================
SUB CSED_WithinProc (BYREF tProc AS CSED_PROCSTRUCT)

   LOCAL i          AS LONG     ' // Loop counter
   LOCAL curPos     AS LONG     ' // Current position
   LOCAL LineNumber AS LONG     ' // Number of line
   LOCAL LineLen    AS LONG     ' // Length of the line
   LOCAL buffer     AS STRING   ' // buffer
   LOCAL Namebuffer AS STRING   ' // buffer to keep the function name
   LOCAL LineCount  AS LONG     ' // Number of lines

   curPos = SCI_GetCurrentPos(pSed.hEdit)
   LineNumber = SCI_LineFromPosition(pSed.hEdit, curPos)
   LineCount = SCI_GetLineCount(pSed.hEdit)

   tProc.WhatIsUp   = %ID_PROCNULL
   tProc.UpLnNo     = 0
   tProc.WhatIsDown = %ID_PROCNULL
   tProc.DnLnNo     = LineCount
   tProc.ProcName   = ""

   ' // Check current line
   LineLen = SCI_LineLength(pSed.hEdit, LineNumber)
   buffer = SCI_GetLine(pSed.hEdit, LineNumber)
   DO
      IF ISFALSE INSTR(buffer, "  ") THEN EXIT DO
      REPLACE "  " WITH " " IN buffer
   LOOP
   Namebuffer = LTRIM$(buffer)
   buffer = LTRIM$(UCASE$(buffer))
   IF LEFT$(buffer, 4) = "SUB " OR LEFT$(buffer, 9) = "FUNCTION " OR _
      LEFT$(buffer, 7) = "METHOD " OR LEFT$(buffer, 9) = "PROPERTY " OR _
      (LEFT$(buffer, 7) = "STATIC " AND MID$(buffer, 8, 3) = "SUB") OR _
      (LEFT$(buffer, 7) = "STATIC " AND MID$(buffer, 8, 8) = "FUNCTION") OR _
      (LEFT$(buffer, 9) = "CALLBACK " AND MID$(buffer, 10, 8) = "FUNCTION") OR _
      LEFT$(buffer, 9) = "FASTPROC " THEN
      IF LEFT$(buffer, 8) = "FUNCTION" OR LEFT$(buffer, 6) = "METHOD" OR _
         LEFT$(buffer, 8) = "PROPERTY" THEN
         IF LEFT$(buffer, 8) = "FUNCTION" OR LEFT$(buffer, 8) = "PROPERTY" THEN
            Namebuffer = LTRIM$(MID$(Namebuffer, 9))
            buffer = LTRIM$(MID$(buffer, 9))
         ELSEIF LEFT$(buffer, 6) = "METHOD" THEN
            Namebuffer = LTRIM$(MID$(Namebuffer, 7))
            buffer = LTRIM$(MID$(buffer, 7))
         END IF
         IF LEFT$(buffer, 1) <> "=" THEN
            tProc.WhatIsUp = %ID_PROCSTART
            tProc.UpLnNo = LineNumber
         END IF
      ELSE
         tProc.WhatIsUp = %ID_PROCSTART
         tProc.UpLnNo = LineNumber
      END IF
      Namebuffer = TRIM$(MID$(Namebuffer, 1, INSTR(Namebuffer, ANY CHR$(40,13,10)) - 1 ))
      tProc.ProcName = PARSE$(Namebuffer, CHR$(32), PARSECOUNT(Namebuffer, CHR$(32)))
   ELSEIF (LEFT$(buffer, 4) = "END " AND MID$(buffer, 5, 3) = "SUB") OR _
      (LEFT$(buffer, 4) = "END " AND MID$(buffer, 5, 8) = "FUNCTION") OR _
      (LEFT$(buffer, 4) = "END " AND MID$(buffer, 5, 6) = "METHOD") OR _
      (LEFT$(buffer, 4) = "END " AND MID$(buffer, 5, 8) = "PROPERTY") OR _
      (LEFT$(buffer, 4) = "END " AND MID$(buffer, 5, 8) = "FASTPROC") THEN
      tProc.WhatIsDown = %ID_PROCEND
      tProc.DnLnNo = LineNumber
   END IF

   ' // Check for begining if not found
   IF tProc.WhatIsUp = %ID_PROCNULL THEN
      FOR i = LineNumber - 1 TO 0 STEP -1
         LineLen = SCI_LineLength(pSed.hEdit, i)
         buffer = SCI_GetLine(pSed.hEdit, i)
         DO
            IF ISFALSE INSTR(buffer, "  ") THEN EXIT DO
            REPLACE "  " WITH " " IN buffer
         LOOP
         Namebuffer = LTRIM$(buffer)
         buffer = LTRIM$(UCASE$(buffer))
         IF LEFT$(buffer, 4) = "SUB " OR LEFT$(buffer, 9) = "FUNCTION " OR _
            LEFT$(buffer, 7) = "METHOD " OR LEFT$(buffer, 9) = "PROPERTY " OR _
            (LEFT$(buffer, 7) = "STATIC " AND MID$(buffer, 8, 3) = "SUB") OR _
            (LEFT$(buffer, 7) = "STATIC " AND MID$(buffer, 8, 8) = "FUNCTION") OR _
            (LEFT$(buffer, 9) = "CALLBACK " AND MID$(buffer, 10, 8) = "FUNCTION") OR _
            LEFT$(buffer, 9) = "FASTPROC " THEN
            IF LEFT$(buffer, 8) = "FUNCTION" OR LEFT$(buffer, 6) = "METHOD" OR _
               LEFT$(buffer, 8) = "PROPERTY" THEN
               IF LEFT$(buffer, 8) = "FUNCTION" OR LEFT$(buffer, 8) = "PROPERTY" THEN
                  Namebuffer = LTRIM$(MID$(Namebuffer, 9))
                  buffer = LTRIM$(MID$(buffer, 9))
               ELSEIF LEFT$(buffer, 6) = "METHOD" THEN
                  Namebuffer = LTRIM$(MID$(Namebuffer, 7))
                  buffer = LTRIM$(MID$(buffer, 7))
               END IF
               IF LEFT$(buffer, 1) <> "=" THEN
                  tProc.WhatIsUp = %ID_PROCSTART
                  tProc.UpLnNo = i
                  Namebuffer = TRIM$(MID$(Namebuffer, 1, INSTR(Namebuffer, ANY CHR$(40,13,10)) - 1 ))
                  tProc.ProcName = PARSE$(Namebuffer, CHR$(32), PARSECOUNT(Namebuffer, CHR$(32)))
                  EXIT FOR
               END IF
            ELSE
               tProc.WhatIsUp = %ID_PROCSTART
               tProc.UpLnNo = i
               Namebuffer = TRIM$(MID$(Namebuffer, 1, INSTR(Namebuffer, ANY CHR$(40,13,10)) - 1 ))
               tProc.ProcName = PARSE$(Namebuffer, CHR$(32), PARSECOUNT(Namebuffer, CHR$(32)))
               EXIT FOR
            END IF
         ELSEIF (LEFT$(buffer, 4) = "END " AND MID$(buffer, 5, 3) = "SUB") OR _
            (LEFT$(buffer, 4) = "END " AND MID$(buffer, 5, 8) = "FUNCTION") OR _
            (LEFT$(buffer, 4) = "END " AND MID$(buffer, 5, 6) = "METHOD") OR _
            (LEFT$(buffer, 4) = "END " AND MID$(buffer, 5, 8) = "PROPERTY") OR _
            (LEFT$(buffer, 4) = "END " AND MID$(buffer, 5, 8) = "FASTPROC") THEN
            tProc.WhatIsUp = %ID_PROCEND
            tProc.UpLnNo = i
            EXIT FOR
         END IF
      NEXT
   END IF

   ' // Check for End
   IF tProc.WhatIsDown  = %ID_PROCNULL THEN
      FOR i = LineNumber + 1 TO LineCount
         LineLen = SCI_LineLength(pSed.hEdit, i)
         buffer = SCI_GetLine(pSed.hEdit, i)
         DO
            IF ISFALSE INSTR(buffer, "  ") THEN EXIT DO
            REPLACE "  " WITH " " IN buffer
         LOOP
         buffer = LTRIM$(UCASE$(buffer))
         IF (LEFT$(buffer, 4) = "END " AND MID$(buffer, 5, 3) = "SUB") OR _
            (LEFT$(buffer, 4) = "END " AND MID$(buffer, 5, 8) = "FUNCTION") OR _
            (LEFT$(buffer, 4) = "END " AND MID$(buffer, 5, 6) = "METHOD") OR _
            (LEFT$(buffer, 4) = "END " AND MID$(buffer, 5, 8) = "PROPERTY") OR _
            (LEFT$(buffer, 4) = "END " AND MID$(buffer, 5, 8) = "FASTPROC") THEN
            tProc.WhatIsDown = %ID_PROCEND
            tProc.DnLnNo = i
            EXIT FOR
         ELSE
            IF LEFT$(buffer, 4) = "SUB " OR LEFT$(buffer, 9) = "FUNCTION " OR _
               LEFT$(buffer, 7) = "METHOD " OR LEFT$(buffer, 9) = "PROPERTY " OR _
               (LEFT$(buffer, 7) = "STATIC " AND MID$(buffer, 8, 3) = "SUB") OR _
               (LEFT$(buffer, 7) = "STATIC " AND MID$(buffer, 8, 8) = "FUNCTION") OR _
               (LEFT$(buffer, 9) = "CALLBACK " AND MID$(buffer, 10, 8) = "FUNCTION") OR _
               LEFT$(buffer, 9) = "FASTPROC " THEN
               IF LEFT$(buffer, 8) = "FUNCTION" OR LEFT$(buffer, 6) = "METHOD" OR _
                  LEFT$(buffer, 8) = "PROPERTY" THEN
                  IF LEFT$(buffer, 8) = "FUNCTION" OR LEFT$(buffer, 8) = "PROPERTY" THEN
                     buffer = LTRIM$(MID$(buffer, 9))
                  ELSEIF LEFT$(buffer, 6) = "METHOD" THEN
                     buffer = LTRIM$(MID$(buffer, 7))
                  END IF
                  IF LEFT$(buffer, 1) <> "=" THEN
                     tProc.WhatIsDown = %ID_PROCSTART
                     tProc.DnLnNo = i
                     EXIT FOR
                  END IF
               ELSE
                  tProc.WhatIsDown = %ID_PROCSTART
                  tProc.DnLnNo = i
                  EXIT FOR
               END IF
            END IF
         END IF
      NEXT
   END IF

END SUB
' ========================================================================================

' ========================================================================================
' Goes to the beginning of the SUB/FUNCTION
' ========================================================================================
FUNCTION CSED_GotoBeginThisProc () AS LONG

   LOCAL curPos AS LONG             ' // Current position
   LOCAL tProc  AS CSED_PROCSTRUCT

   CSED_WithinProc(tProc)

   IF tProc.WhatIsUp = %ID_PROCEND AND tProc.WhatIsDown = %ID_PROCSTART OR _
       tProc.WhatIsUp = %ID_PROCNULL AND tProc.WhatIsDown = %ID_PROCSTART THEN EXIT FUNCTION

   IF tProc.WhatIsUp = %ID_PROCSTART THEN
      SCI_GotoLine(pSed.hEdit, tProc.UpLnNo)
      curPos = SCI_GetCurrentPos(pSed.hEdit)
   ELSE
      SCI_GotoLine(pSed.hEdit, tProc.UpLnNo + 1)
      curPos = SCI_GetCurrentPos(pSed.hEdit)
      CSED_MSGBOX pSed.hwndMain, "Missing begin of procedure"
   END IF

   FUNCTION = curPos

END FUNCTION
' ========================================================================================

' ========================================================================================
' Goes to the end of the SUB/FUNCTION
' ========================================================================================
FUNCTION CSED_GotoEndThisProc () AS LONG

   LOCAL curPos AS LONG             ' // Current position
   LOCAL tProc  AS CSED_PROCSTRUCT

   CSED_WithinProc(tProc)

   IF tProc.WhatIsUp =  %ID_PROCEND AND tProc.WhatIsDown = %ID_PROCSTART OR _
       tProc.WhatIsUp =  %ID_PROCNULL AND tProc.WhatIsDown = %ID_PROCSTART THEN EXIT FUNCTION

   IF tProc.WhatIsDown =  %ID_ProcEnd THEN
      SCI_GotoLine(pSed.hEdit, tProc.DnLnNo)
      curPos = SCI_GetCurrentPos(pSed.hEdit)
   ELSE
      SCI_GotoLine(pSed.hEdit, tProc.DnLnNo - 1)
      curPos = SCI_GetCurrentPos(pSed.hEdit)
      CSED_MSGBOX pSed.hwndMain, "Missing end of procedure"
   END IF

   FUNCTION = curPos

END FUNCTION
' ========================================================================================

' ========================================================================================
' Goes to the beginning of the SUB/FUNCTION
' ========================================================================================
FUNCTION CSED_GotoBeginProc () AS LONG

   LOCAL i              AS LONG     ' // Loop counter
   LOCAL curPos         AS LONG     ' // Current position
   LOCAL LineNumber     AS LONG     ' // Number of line
   LOCAL LineLen        AS LONG     ' // Length of the line
   LOCAL bIsNotProc     AS LONG     ' // Flag
   LOCAL buffer         AS STRING   ' // buffer

   curPos = SCI_GetCurrentPos(pSed.hEdit)
   LineNumber = SCI_LineFromPosition(pSed.hEdit, curPos) - 1
   FOR i = LineNumber TO 0 STEP -1
      LineLen = SCI_LineLength(pSed.hEdit, i)
      buffer = SCI_GetLine(pSed.hEdit, i)
      bIsNotProc = %FALSE
      buffer = LTRIM$(UCASE$(buffer))
      DO
         IF ISFALSE INSTR(buffer, "  ") THEN EXIT DO
         REPLACE "  " WITH " " IN buffer
      LOOP
      IF LEFT$(buffer, 4) = "SUB " OR LEFT$(buffer, 9) = "FUNCTION " OR _
         LEFT$(buffer, 7) = "METHOD " OR LEFT$(buffer, 9) = "PROPERTY " OR _
         (LEFT$(buffer, 7) = "STATIC " AND MID$(buffer, 8, 3) = "SUB") OR _
         (LEFT$(buffer, 7) = "STATIC " AND MID$(buffer, 8, 8) = "FUNCTION") OR _
         (LEFT$(buffer, 9) = "CALLBACK " AND MID$(buffer, 10, 8) = "FUNCTION") OR _
         LEFT$(buffer, 9) = "FASTPROC " THEN
         IF LEFT$(buffer, 8) = "FUNCTION" OR LEFT$(buffer, 6) = "METHOD" OR _
            LEFT$(buffer, 8) = "PROPERTY" THEN
            IF LEFT$(buffer, 8) = "FUNCTION" OR LEFT$(buffer, 8) = "PROPERTY" THEN
               buffer = LTRIM$(MID$(buffer, 9))
            ELSEIF LEFT$(buffer, 6) = "METHOD" THEN
               buffer = LTRIM$(MID$(buffer, 7))
            END IF
            IF LEFT$(buffer, 1) = "=" THEN bIsNotProc = %TRUE
         END IF
         IF ISFALSE bIsNotProc THEN
            SCI_GotoLine(pSed.hEdit, i)
            curPos = SCI_GetCurrentPos(pSed.hEdit)
            EXIT FOR
         END IF
      END IF
   NEXT

   FUNCTION = curPos

END FUNCTION
' ========================================================================================

' ========================================================================================
' Goes to the end of the SUB/FUNCTION
' ========================================================================================
FUNCTION CSED_GotoEndProc () AS LONG

   LOCAL i          AS LONG     ' // Loop counter
   LOCAL curPos     AS LONG     ' // Current position
   LOCAL LineNumber AS LONG     ' // Number of line
   LOCAL LineCount  AS LONG     ' // Number of lines
   LOCAL LineLen    AS LONG     ' // Length of the line
   LOCAL buffer     AS STRING   ' // buffer

   LineCount = SCI_GetLineCount(pSed.hEdit)
   curPos = SCI_GetCurrentPos(pSed.hEdit)
   LineNumber = SCI_LineFromPosition(pSed.hEdit, curPos) + 1
   FOR i = LineNumber TO LineCount
      LineLen = SCI_LineLength(pSed.hEdit, i)
      buffer = SCI_GetLine(pSed.hEdit, i)
      buffer = LTRIM$(UCASE$(buffer))
      DO
         IF ISFALSE INSTR(buffer, "  ") THEN EXIT DO
         REPLACE "  " WITH " " IN buffer
      LOOP
      IF (LEFT$(buffer, 4) = "END " AND MID$(buffer, 5, 3) = "SUB") OR _
         (LEFT$(buffer, 4) = "END " AND MID$(buffer, 5, 8) = "FUNCTION") OR _
         (LEFT$(buffer, 4) = "END " AND MID$(buffer, 5, 6) = "METHOD") OR _
         (LEFT$(buffer, 4) = "END " AND MID$(buffer, 5, 8) = "PROPERTY") OR _
         (LEFT$(buffer, 4) = "END " AND MID$(buffer, 5, 8) = "FASTPROC") THEN
         SCI_GotoLine(pSed.hEdit, i)
         curPos = SCI_GetCurrentPos(pSed.hEdit)
         EXIT FOR
      END IF
   NEXT

   FUNCTION = curPos

END FUNCTION
' =======================================================================================