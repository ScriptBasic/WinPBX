' ########################################################################################
' Microsoft Windows
' File: SciCtrl.inc
' Contents: Wrapper functions for the Scintilla control v. 3.0.3.
' Copyright (c) 2012 José Roca. All Rights Reserved.
' Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SCICTRL_INC = 1

#INCLUDE ONCE "Scintilla.inc"

' ########################################################################################
'                            Text retrieval and modification
' ########################################################################################

' ========================================================================================
' SCI_GETTEXT(int length, char *text)
' This returns length-1 characters of text from the start of the document plus one
' terminating 0 character. To collect all the text in a document, use SCI_GETLENGTH to
' get the number of characters in the document (nLen), allocate a character buffer of
' length nLen+1 bytes, then call SCI_GETTEXT(nLen+1, char *text). If the text argument
' is 0 then the length that should be allocated to store the entire document is returned.
' If you then save the text, you should use SCI_SETSAVEPOINT to mark the text as unmodified.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetText (BYVAL hSci AS DWORD) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = SendMessage(hSci, %SCI_GETLENGTH, 0, 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen + 1)
   SendMessageA(hSci, %SCI_GETTEXT, nLen + 1, STRPTR(buffer))
   FUNCTION = REMOVE$(buffer, CHR$(0))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetText (BYVAL pSci AS DWORD) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = Scintilla_DirectFunction(pSci, %SCI_GETLENGTH, 0, 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen + 1)
   Scintilla_DirectFunction(pSci, %SCI_GETTEXT, nLen + 1, STRPTR(buffer))
   FUNCTION = REMOVE$(buffer, CHR$(0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETTEXT(<unused>, const char *text)
' Replaces all the text in the document with the zero terminated text string you pass in.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetText (BYVAL hSci AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETTEXT, 0, STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetText (BYVAL pSci AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETTEXT, 0, STRPTR(strText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETSAVEPOINT
' This message tells Scintilla that the current state of the document is unmodified. This
' is usually done when the file is saved or loaded, hence the name "save point". As
' Scintilla performs undo and redo operations, it notifies the container that it has
' entered or left the save point with SCN_SAVEPOINTREACHED and SCN_SAVEPOINTLEFT
' notification messages, allowing the container to know if the file should be considered
' dirty or not.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetSavePoint (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETSAVEPOINT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetSavePoint (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETSAVEPOINT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETLINE(int line, char *text)
' This fills the buffer defined by text with the contents of the nominated line (lines
' start at 0). The buffer is not terminated by a 0 character. It is up to you to make sure
' that the buffer is long enough for the text, use SCI_LINELENGTH(int line). The returned
' value is the number of characters copied to the buffer. The returned text includes any
' end of line characters. If you ask for a line number outside the range of lines in the
' document, 0 characters are copied. If the text argument is 0 then the length that should
' be allocated to store the entire line is returned.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetLine (BYVAL hSci AS DWORD, BYVAL nLine AS LONG) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = SendMessageA(hSci, %SCI_LINELENGTH, nLine , 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen)
   SendMessageA hSci, %SCI_GETLINE, nLine, STRPTR(buffer)
   FUNCTION = buffer
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetLine (BYVAL pSci AS DWORD, BYVAL nLine AS LONG) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = Scintilla_DirectFunction(pSci, %SCI_LINELENGTH, nLine , 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen)
   Scintilla_DirectFunction pSci, %SCI_GETLINE, nLine, STRPTR(buffer)
   FUNCTION = buffer
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_REPLACESEL(<unused>, const char *text)
' The currently selected text between the anchor and the current position is replaced by
' the 0 terminated text string. If the anchor and current position are the same, the text
' is inserted at the caret position. The caret is positioned after the inserted text and
' the caret is scrolled into view.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_ReplaceSel (BYVAL hSci AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_REPLACESEL, 0, STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ReplaceSel (BYVAL pSci AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_REPLACESEL, 0, STRPTR(strText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETREADONLY(bool readOnly)
' Sets the read-only flag for the document. If you mark a document as read only, attempts
' to modify the text cause the SCN_MODIFYATTEMPTRO notification.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetReadOnly (BYVAL hSci AS DWORD, BYVAL bReadOnly AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETREADONLY, bReadOnly, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetReadOnly (BYVAL pSci AS DWORD, BYVAL bReadOnly AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETREADONLY, bReadOnly, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETREADONLY
' Sets the read-only flag for the document.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetReadOnly (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETREADONLY, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetReadOnly (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETREADONLY, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETTEXTRANGE(<unused>, Sci_TextRange *tr)
' This collects the text between the positions cpMin and cpMax and copies it to lpstrText
' (see struct Sci_TextRange in Scintilla.h). If cpMax is -1, text is returned to the end
' of the document. The text is 0 terminated, so you must supply a buffer that is at least
' 1 character longer than the number of characters you wish to read. The return value is
' the length of the returned text not including the terminating 0.
' // NOTE: For the wrapper functions we are using individual parameters instead of an structure.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetTextRange (BYVAL hSci AS DWORD, BYVAL cpMin AS LONG, BYVAL cpMax AS LONG) AS STRING
   LOCAL p AS LONG
   LOCAL buffer AS STRING
   LOCAL txtrg AS Sci_TextRange
   txtrg.chrg.cpMin = cpMin
   txtrg.chrg.cpMax = cpMax
   buffer = SPACE$(cpMax - cpMin + 1)
   txtrg.lpstrText = STRPTR(buffer)
   SendMessageA(hSci, %SCI_GETTEXTRANGE, 0, VARPTR(txtrg))
   p = INSTR(buffer, CHR$(0))
   IF p THEN buffer = LEFT$(buffer, p - 1)
   FUNCTION = buffer
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetTextRange (BYVAL pSci AS DWORD, BYVAL cpMin AS LONG, BYVAL cpMax AS LONG) AS STRING
   LOCAL p AS LONG
   LOCAL buffer AS STRING
   LOCAL txtrg AS Sci_TextRange
   txtrg.chrg.cpMin = cpMin
   txtrg.chrg.cpMax = cpMax
   buffer = SPACE$(cpMax - cpMin + 1)
   txtrg.lpstrText = STRPTR(buffer)
   Scintilla_DirectFunction(pSci, %SCI_GETTEXTRANGE, 0, VARPTR(txtrg))
   p = INSTR(buffer, CHR$(0))
   IF p THEN buffer = LEFT$(buffer, p - 1)
   FUNCTION = buffer
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_ALLOCATE(int bytes, <unused>)
' Allocate a document buffer large enough to store a given number of bytes. The document
' will not be made smaller than its current contents.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_Allocate (BYVAL hSci AS DWORD, BYVAL nBytes AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ALLOCATE, nBytes, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_Allocate (BYVAL pSci AS DWORD, BYVAL nBytes AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ALLOCATE, nBytes, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_ADDTEXT(int length, const char *s)
' This inserts the first length characters from the string at the current position. This
' will include any 0's in the string that you might have expected to stop the insert
' operation. The current position is set at the end of the inserted text, but it is not
' scrolled into view.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AddText (BYVAL hSci AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ADDTEXT, LEN(strText), STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AddText (BYVAL pSci AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ADDTEXT, LEN(strText), STRPTR(strText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_ADDSTYLEDTEXT(int length, cell *s)
' This behaves just like SCI_ADDTEXT, but inserts styled text.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AddStyledText (BYVAL hSci AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ADDSTYLEDTEXT, LEN(strText), STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AddStyledText (BYVAL pSci AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ADDSTYLEDTEXT, LEN(strText), STRPTR(strText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_APPENDTEXT(int length, const char *s)
' This adds the first length characters from the string s to the end of the document. This
' will include any 0's in the string that you might have expected to stop the operation.
' The current selection is not changed and the new text is not scrolled into view.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AppendText (BYVAL hSci AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_APPENDTEXT, LEN(strText), STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AppendText (BYVAL pSci AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_APPENDTEXT, LEN(strText), STRPTR(strText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_INSERTTEXT(int pos, const char *text)
' This inserts the zero terminated text string at position pos or at the current position
' if pos is -1. If the current position is after the insertion point then it is moved
' along with its surrounding text but no scrolling is performed.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_InsertText (BYVAL hSci AS DWORD, BYVAL nPos AS LONG, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_INSERTTEXT, nPos, STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_InsertText (BYVAL pSci AS DWORD, BYVAL nPos AS LONG, BYVAL strText AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_INSERTTEXT, nPos, STRPTR(strText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_CHANGEINSERTION(int length, const char *text)
' This may only be called from a SC_MOD_INSERTCHECK notification handler and will change
' the text being inserted to that provided.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_ChangeInsertion (BYVAL hSci AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CHANGEINSERTION, LEN(strText), STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ChangeInsertion (BYVAL pSci AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CHANGEINSERTION, LEN(strText), STRPTR(strText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_CLEARALL
' Unless the document is read-only, this deletes all the text.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_ClearAll (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CLEARALL, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ClearAll (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CLEARALL, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_DELETERANGE (int pos, int deleteLength)
' Deletes a range of text in the document.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_DeleteRange (BYVAL hSci AS DWORD, BYVAL nPos AS LONG, BYVAL deleteLength AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_DELETERANGE, nPos, deleteLength)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_DeleteRange (BYVAL pSci AS DWORD, BYVAL nPos AS LONG, BYVAL deleteLength AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_DELETERANGE, nPos, deleteLength)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_CLEARDOCUMENTSTYLE
' When wanting to completely restyle the document, for example after choosing a lexer, the
' SCI_CLEARDOCUMENTSTYLE can be used to clear all styling information and reset the
' folding state.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_ClearDocumentStyle (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CLEARDOCUMENTSTYLE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ClearDocumentStyle (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CLEARDOCUMENTSTYLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETCHARAT(int pos)
' This returns the character at pos in the document or 0 if pos is negative or past the
' end of the document.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetCharAt (BYVAL hSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETCHARAT, nPos, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetCharAt (BYVAL pSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETCHARAT, nPos, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETSTYLEAT(int pos)
' This returns the style at pos in the document, or 0 if pos is negative or past the end
' of the document.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetStyleAt (BYVAL hSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETSTYLEAT, nPos, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetStyleAt (BYVAL pSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETSTYLEAT, nPos, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETSTYLEDTEXT(<unused>, Sci_TextRange *tr)
' This collects styled text into a buffer using two bytes for each cell, with the character
' at the lower address of each pair and the style byte at the upper address. Characters
' between the positions cpMin and cpMax are copied to lpstrText (see struct Sci_TextRange
' in Scintilla.h). Two 0 bytes are added to the end of the text, so the buffer that
' lpstrText points at must be at least 2*(cpMax-cpMin)+2 bytes long. No check is made for
' sensible values of cpMin or cpMax. Positions outside the document return character codes
' and style bytes of 0.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetStyledTextRange (BYVAL hSci AS DWORD, BYVAL cpMin AS LONG, BYVAL cpMax AS LONG) AS STRING
   LOCAL p AS LONG
   LOCAL buffer AS STRING
   LOCAL txtrg AS Sci_TextRange
   txtrg.chrg.cpMin = cpMin
   txtrg.chrg.cpMax = cpMax
   buffer = SPACE$(2 * (cpMax - cpMin) + 2)
   txtrg.lpstrText = STRPTR(buffer)
   SendMessageA(hSci, %SCI_GETSTYLEDTEXT, 0, VARPTR(txtrg))
   p = INSTR(buffer, CHR$(0))
   IF p THEN buffer = LEFT$(buffer, p - 1)
   FUNCTION = buffer
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetStyledTextRange (BYVAL pSci AS DWORD, BYVAL cpMin AS LONG, BYVAL cpMax AS LONG) AS STRING
   LOCAL p AS LONG
   LOCAL buffer AS STRING
   LOCAL txtrg AS Sci_TextRange
   txtrg.chrg.cpMin = cpMin
   txtrg.chrg.cpMax = cpMax
   buffer = SPACE$(2 * (cpMax - cpMin) + 2)
   txtrg.lpstrText = STRPTR(buffer)
   Scintilla_DirectFunction(pSci, %SCI_GETSTYLEDTEXT, 0, VARPTR(txtrg))
   p = INSTR(buffer, CHR$(0))
   IF p THEN buffer = LEFT$(buffer, p - 1)
   FUNCTION = buffer
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETSTYLEBITS(int bits)
' Sets the number of bits in each cell to use for styling, to a maximum of 8 style bits.
' The remaining bits can be used as indicators. The standard setting is SCI_SETSTYLEBITS(5).
' The number of styling bits needed by the current lexer can be found with
' SCI_GETSTYLEBITSNEEDED.
' Deprecated
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetStyleBits (BYVAL hSci AS DWORD, BYVAL nBits AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETSTYLEBITS, nBits, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetStyleBits (BYVAL pSci AS DWORD, BYVAL nBits AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETSTYLEBITS, nBits, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETSTYLEBITS
' Returns the number of bits in each cell to use for styling, to a maximum of 8 style bits.
' Deprecated.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetStyleBits (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETSTYLEBITS, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetStyleBits (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETSTYLEBITS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_RELEASEALLEXTENDEDSTYLES
' SCI_ALLOCATEEXTENDEDSTYLES(int numberStyles)
' Extended styles are used for features like textual margins and annotations as well as
' internally by Scintilla. They are outside the range 0..255 used for the styles bytes
' associated with document bytes. These functions manage the use of extended styles to
' ensures that components cooperate in defining styles. SCI_RELEASEALLEXTENDEDSTYLES
' releases any extended styles allocated by the container. SCI_ALLOCATEEXTENDEDSTYLES
' allocates a range of style numbers after the byte style values and returns the number
' of the first allocated style. Ranges for margin and annotation styles should be allocated
' before calling SCI_MARGINSETSTYLEOFFSET or SCI_ANNOTATIONSETSTYLEOFFSET.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_ReleaseAllExtendedStyles (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_RELEASEALLEXTENDEDSTYLES, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ReleaseAllExtendedStyles (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_RELEASEALLEXTENDEDSTYLES, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AllocateExtendedStyles (BYVAL hSci AS DWORD, BYVAL numberStyles AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ALLOCATEEXTENDEDSTYLES, 0, numberStyles)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AllocateExtendedStyles (BYVAL pSci AS DWORD, BYVAL numberStyles AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ALLOCATEEXTENDEDSTYLES, 0, numberStyles)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                       Searching
' ########################################################################################

' ========================================================================================
' SCI_FINDTEXT(int searchFlags, Sci_TextToFind *ttf)
' This message searches for text in the document. It does not use or move the current
' selection. The searchFlags argument controls the search type, which includes regular
' expression searches.
' The Sci_TextToFind structure is defined in Scintilla.h; set chrg.cpMin and chrg.cpMax
' with the range of positions in the document to search. If SCFIND_REGEXP is not included
' in the flags, you can search backwards by setting chrg.cpMax less than chrg.cpMin. If
' SCFIND_REGEXP is included, the search is always forwards (even if chrg.cpMax is less
' than chrg.cpMin). Set the lpstrText member of Sci_TextToFind to point at a zero
' terminated text string holding the search pattern. If your language makes the use of
' Sci_TextToFind difficult, you should consider using SCI_SEARCHINTARGET instead.
' The return value is -1 if the search fails or the position of the start of the found
' text if it succeeds. The chrgText.cpMin and chrgText.cpMax members of Sci_TextToFind are
' filled in with the start and end positions of the found text.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_FindText (BYVAL hSci AS DWORD, BYVAL searchFlags AS LONG, BYREF ttf AS Sci_TextToFind) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_FINDTEXT, searchFlags, VARPTR(ttf))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_FindText (BYVAL pSci AS DWORD, BYVAL searchFlags AS LONG, BYREF ttf AS Sci_TextToFind) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_FINDTEXT, searchFlags, VARPTR(ttf))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SEARCHANCHOR
' Sets the search start point used by SCI_SEARCHNEXT and SCI_SEARCHPREV to the start of
' the current selection, that is, the end of the selection that is nearer to the start of
' the document. You should always call this before calling either of SCI_SEARCHNEXT or
' SCI_SEARCHPREV.
' The return value is -1 if nothing is found, otherwise the return value is the start
' position of the matching text. The selection is updated to show the matched text, but
' is not scrolled into view.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SearchAnchor (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SEARCHANCHOR, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SearchAnchor (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SEARCHANCHOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SEARCHNEXT(int searchFlags, const char *text)
' SCI_SEARCHNEXT search for the next occurrence of the zero terminated search string
' pointed at by text. The search is modified by the searchFlags.
' The return value is -1 if nothing is found, otherwise the return value is the start
' position of the matching text. The selection is updated to show the matched text, but
' is not scrolled into view.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SearchNext (BYVAL hSci AS DWORD, BYVAL searchFlags AS LONG, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SEARCHNEXT, searchFlags, STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SearchNext (BYVAL pSci AS DWORD, BYVAL searchFlags AS LONG, BYVAL strText AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SEARCHNEXT, searchFlags, STRPTR(strText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SEARCHPREV(int searchFlags, const char *text)
' SCI_SEARCHPREV search for the previous occurrence of the zero terminated search string
' pointed at by text. The search is modified by the searchFlags. If you request a regular
' expression, SCI_SEARCHPREV finds the first occurrence of the search string in the
' document, not the previous one before the anchor point.
' The return value is -1 if nothing is found, otherwise the return value is the start
' position of the matching text. The selection is updated to show the matched text, but
' is not scrolled into view.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SearchPrev (BYVAL hSci AS DWORD, BYVAL searchFlags AS LONG, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SEARCHPREV, searchFlags, STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SearchPrev (BYVAL pSci AS DWORD, BYVAL searchFlags AS LONG, BYVAL strText AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SEARCHPREV, searchFlags, STRPTR(strText))
END FUNCTION
' ========================================================================================

' ########################################################################################
'                          Search and replace using the target
' ########################################################################################

' ========================================================================================
' SCI_SETTARGETSTART(int pos)
' Sets the start of the target. When searching in non-regular expression mode, you can set
' start greater than end to find the last matching text in the target rather than the
' first matching text. The target is also set by a successful SCI_SEARCHINTARGET.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetTargetStart (BYVAL hSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETTARGETSTART, nPos, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetTargetStart (BYVAL pSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETTARGETSTART, nPos, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETTARGETSTART
' Gets the start of the target.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetTargetStart (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETTARGETSTART, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetTargetStart (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETTARGETSTART, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETTARGETEND(int pos)
' Sets the end of the target.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetTargetEnd (BYVAL hSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETTARGETEND, nPos, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetTargetEnd (BYVAL pSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETTARGETEND, nPos, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETTARGETEND
' Gets the end of the target.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetTargetEnd (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETTARGETEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetTargetEnd (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETTARGETEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETTARGETRANGE(int start, int end)
' Sets the range of the target.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetTargetRange (BYVAL hSci AS DWORD, BYVAL nStart AS LONG, BYVAL nEnd AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETTARGETRANGE, nStart, nEnd)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetTargetRange (BYVAL pSci AS DWORD, BYVAL nStart AS LONG, BYVAL nEnd AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETTARGETRANGE, nStart, nEnd)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_TARGETFROMSELECTION
' Set the target start and end to the start and end positions of the selection.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_TargetFromSelection (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_TARGETFROMSELECTION, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_TargetFromSelection (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_TARGETFROMSELECTION, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETSEARCHFLAGS(int searchFlags)
' Setd the searchFlags used by SCI_SEARCHINTARGET. There are several option flags
' including a simple regular expression search.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetSearchFlags (BYVAL hSci AS DWORD, BYVAL searchFlags AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETSEARCHFLAGS, searchFlags, 0)
END FUNCTION
' ========================================================================================
FUNCTION SCIP_SetSearchFlags (BYVAL pSci AS DWORD, BYVAL searchFlags AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETSEARCHFLAGS, searchFlags, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETSEARCHFLAGS
' Gets the searchFlags used by SCI_SEARCHINTARGET. There are several option flags
' including a simple regular expression search.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetSearchFlags (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETSEARCHFLAGS, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetSearchFlags (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETSEARCHFLAGS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SEARCHINTARGET(int length, const char *text)
' This searches for the first occurrence of a text string in the target defined by
' SCI_SETTARGETSTART and SCI_SETTARGETEND. The text string is not zero terminated; the
' size is set by length. The search is modified by the search flags set by
' SCI_SETSEARCHFLAGS. If the search succeeds, the target is set to the found text and the
' return value is the position of the start of the matching text. If the search fails, the
' result is -1.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SearchInTarget (BYVAL hSci AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SEARCHINTARGET, LEN(strText), STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SearchInTarget (BYVAL pSci AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SEARCHINTARGET, LEN(strText), STRPTR(strText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETTARGETTEXT(<unused>, char *text)
' Retrieve the value in the target.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetTargetText (BYVAL hSci AS DWORD) AS STRING
   LOCAL pszText AS ASCIIZ PTR
   SendMessageA(hSci, %SCI_GETTARGETTEXT, 0, pszText)
   IF pszText THEN FUNCTION = @pszText
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetTargetText (BYVAL pSci AS DWORD) AS STRING
   LOCAL pszText AS ASCIIZ PTR
   Scintilla_DirectFunction(pSci, %SCI_GETTARGETTEXT, 0, pszText)
   IF pszText THEN FUNCTION = @pszText
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_REPLACETARGET(int length, const char *text)
' If length is -1, text is a zero terminated string, otherwise length sets the number of
' character to replace the target with. After replacement, the target range refers to the
' replacement text. The return value is the length of the replacement string.
' Note that the recommended way to delete text in the document is to set the target to the
' text to be removed, and to perform a replace target with an empty string.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_ReplaceTarget (BYVAL hSci AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_REPLACETARGET, LEN(strText), STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ReplaceTarget (BYVAL pSci AS DWORD,BYVAL strText AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_REPLACETARGET, LEN(strText), STRPTR(strText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_REPLACETARGETRE(int length, const char *text)
' Replaces the target using regular expressions. If length is -1, text is a zero terminated
' string, otherwise length is the number of characters to use. The replacement string is
' formed from the text string with any sequences of \1 through \9 replaced by tagged
' matches from the most recent regular expression search. After replacement, the target
' range refers to the replacement text. The return value is the length of the replacement
' string.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_ReplaceTargetRE (BYVAL hSci AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_REPLACETARGETRE, LEN(strText), STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ReplaceTargetRE (BYVAL pSci AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_REPLACETARGETRE, LEN(strText), STRPTR(strText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETTAG(int tagNumber, char *tagValue)
' Discover what text was matched by tagged expressions in a regular expression search.
' This is useful if the application wants to interpret the replacement string itself.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetTag (BYVAL hSci AS DWORD, BYVAL tagNumber AS LONG) AS STRING
   LOCAL tagValue AS ASCIIZ * 3
   SendMessageA(hSci, %SCI_GETTAG, tagNumber, VARPTR(tagValue))
   FUNCTION = tagValue
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetTag (BYVAL pSci AS DWORD, BYVAL tagNumber AS LONG) AS STRING
   LOCAL tagValue AS ASCIIZ * 3
   Scintilla_DirectFunction(pSci, %SCI_GETTAG, tagNumber, VARPTR(tagValue))
   FUNCTION = tagValue
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                      Overtype
' ########################################################################################

' ========================================================================================
' SCI_SETOVERTYPE(bool overType)
' When overtype is enabled, each typed character replaces the character to the right of
' the text caret. When overtype is disabled, characters are inserted at the caret.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetOvertype (BYVAL hSci AS DWORD, BYVAL overType AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETOVERTYPE, overType, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetOvertype (BYVAL pSci AS DWORD, BYVAL overType AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETOVERTYPE, overType, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETOVERTYPE
' Returns TRUE (1) if overtyping is active, otherwise FALSE (0) will be returned.
' Use SCI_SETOVERTYPE to set the overtype mode.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetOvertype (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETOVERTYPE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetOvertype (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETOVERTYPE, 0, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                 Cut, copy and paste
' ########################################################################################

' ========================================================================================
' These commands perform the standard tasks of cutting and copying data to the clipboard,
' pasting from the clipboard into the document, and clearing the document. SCI_CANPASTE
' returns non-zero if the document isn't read-only and if the selection doesn't contain
' protected text. If you need a "can copy" or "can cut", use
' SCI_GETSELECTIONSTART()-SCI_GETSELECTIONEND(), which will be non-zero if you can copy or
' cut to the clipboard.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_Cut (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CUT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_Cut (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CUT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_Copy (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_COPY, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_Copy (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_COPY, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_Paste (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_PASTE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_Paste (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_PASTE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_Clear (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CLEAR, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_Clear (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CLEAR, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_CanPaste (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CANPASTE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CanPaste (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CANPASTE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_CanCut (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = ((SCI_GetSelectionStart(hSci) - SCI_GetSelectionEnd(hSci)) <> 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CanCut (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = ((SCIP_GetSelectionStart(pSci) - SCIP_GetSelectionEnd(pSci)) <> 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_CanCopy (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = ((SCI_GetSelectionStart(hSci) - SCI_GetSelectionEnd(hSci)) <> 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CanCopy (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = ((SCIP_GetSelectionStart(pSci) - SCIP_GetSelectionEnd(pSci)) <> 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_COPYALLOWLINE
' Works the same as SCI_COPY except that if the selection is empty then the current line
' is copied. On Windows, an extra "MSDEVLineSelect" marker is added to the clipboard which
' is then used in SCI_PASTE to paste the whole line before the current line.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_CopyAllowLine (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_COPYALLOWLINE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CopyAllowLine (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_COPYALLOWLINE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_COPYRANGE(int start, int end)
' Copies a range of text from the document to the system clipboard.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_CopyRange (BYVAL hSci AS DWORD, BYVAL nStart AS LONG, BYVAL nEnd AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_COPYRANGE, nStart, nEnd)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CopyRange (BYVAL pSci AS DWORD, BYVAL nStart AS LONG, BYVAL nEnd AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_COPYRANGE, nStart, nEnd)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_COPYTEXT(int length, const char *text)
' Copies a supplied piece of text to the system clipboard.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_CopyText (BYVAL hSci AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_COPYTEXT, LEN(strText), STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CopyText (BYVAL pSci AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_COPYTEXT, LEN(strText), STRPTR(strText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETPASTECONVERTENDINGS(bool convert)
' If this property is set then when text is pasted any line ends are converted to match
' the document's end of line mode as set with SCI_SETEOLMODE
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetPasteConvertEndings (BYVAL hSci AS DWORD, BYVAL bConvert AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETPASTECONVERTENDINGS, bConvert, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetPasteConvertEndings (BYVAL pSci AS DWORD, BYVAL bConvert AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETPASTECONVERTENDINGS, bConvert, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetPasteConvertEndings (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETPASTECONVERTENDINGS, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetPasteConvertEndings (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETPASTECONVERTENDINGS, 0, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                      Error Handling
' ########################################################################################

' ========================================================================================
' SCI_SETSTATUS(int status)
' SCI_GETSTATUS
' If an error occurs, Scintilla may set an internal error number that can be retrieved
' with SCI_GETSTATUS. To clear the error status call SCI_SETSTATUS(0). The currently
' defined statuses are:
'   SC_STATUS_OK         0    No failures
'   SC_STATUS_FAILURE    1    Generic failure
'   SC_STATUS_BADALLOC   2    Memory is exhausted
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetStatus (BYVAL hSci AS DWORD, BYVAL nStatus AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETSTATUS, nStatus, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetStatus (BYVAL pSci AS DWORD, BYVAL nStatus AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETSTATUS, nStatus, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetStatus (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETSTATUS, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetStatus (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETSTATUS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_UNDO
' SCI_CANUNDO
' SCI_UNDO undoes one action, or if the undo buffer has reached a SCI_ENDUNDOACTION point,
' all the actions back to the corresponding SCI_BEGINUNDOACTION.
' SCI_CANUNDO returns 0 if there is nothing to undo, and 1 if there is. You would
' typically use the result of this message to enable/disable the Edit menu Undo command.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_Undo (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_UNDO, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_Undo (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_UNDO, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_CanUndo (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CANUNDO, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CanUndo (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CANUNDO, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_REDO
' SCI_CANREDO
' SCI_REDO undoes the effect of the last SCI_UNDO operation.
' SCI_CANREDO returns 0 if there is no action to redo and 1 if there are undo actions to
' redo. You could typically use the result of this message to enable/disable the Edit menu
' Redo command.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_Redo (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_REDO, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_Redo (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_REDO, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_CanRedo (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CANREDO, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CanRedo (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CANREDO, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_EMPTYUNDOBUFFER
' This command tells Scintilla to forget any saved undo or redo history. It also sets the
' save point to the start of the undo buffer, so the document will appear to be unmodified.
' This does not cause the SCN_SAVEPOINTREACHED notification to be sent to the container.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_EmptyUndoBuffer (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_EMPTYUNDOBUFFER, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_EmptyUndoBuffer (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_EMPTYUNDOBUFFER, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETUNDOCOLLECTION(bool collectUndo)
' SCI_GETUNDOCOLLECTION
' You can control whether Scintilla collects undo information with SCI_SETUNDOCOLLECTION.
' Pass in true (1) to collect information and false (0) to stop collecting. If you stop
' collection, you should also use SCI_EMPTYUNDOBUFFER to avoid the undo buffer being
' unsynchronized with the data in the buffer.
' You might wish to turn off saving undo information if you use the Scintilla to store
' text generated by a program (a Log view) or in a display window where text is often
' deleted and regenerated.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetUndoCollection (BYVAL hSci AS DWORD, BYVAL collectUndo AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETUNDOCOLLECTION, collectUndo, 0)
END FUNCTION
' ========================================================================================
FUNCTION SCIP_SetUndoCollection (BYVAL pSci AS DWORD, BYVAL collectUndo AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETUNDOCOLLECTION, collectUndo, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetUndoCollection (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETUNDOCOLLECTION, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetUndoCollection (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETUNDOCOLLECTION, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_BEGINUNDOACTION
' SCI_ENDUNDOACTION
' Send these two messages to Scintilla to mark the beginning and end of a set of operations
' that you want to undo all as one operation but that you have to generate as several
' operations. Alternatively, you can use these to mark a set of operations that you do not
' want to have combined with the preceding or following operations if they are undone.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_BeginUndoAction (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_BEGINUNDOACTION, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_BeginUndoAction (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_BEGINUNDOACTION, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_EndUndoAction (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ENDUNDOACTION, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_EndUndoAction (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ENDUNDOACTION, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_ADDUNDOACTION(int token, int flags)
' The container can add its own actions into the undo stack by calling SCI_ADDUNDOACTION
' and an SCN_MODIFIED notification will be sent to the container with the SC_MOD_CONTAINER
' flag when it is time to undo (SC_PERFORMED_UNDO) or redo (SC_PERFORMED_REDO) the action.
' The token argument supplied is returned in the token field of the notification.
' For example, if the container wanted to allow undo and redo of a 'toggle bookmark'
' command then it could call SCI_ADDUNDOACTION(line, 0) each time the command is performed.
' Then when it receives a notification to undo or redo it toggles a bookmark on the line
' given by the token field. If there are different types of commands or parameters that
' need to be stored into the undo stack then the container should maintain a stack of its
' own for the document and use the current position in that stack as the argument to
' SCI_ADDUNDOACTION(line). SCI_ADDUNDOACTION commands are not combined together into a
' single undo transaction unless grouped with SCI_BEGINUNDOACTION and SCI_ENDUNDOACTION.
' The flags argument can be UNDO_MAY_COALESCE (1) if the container action may be coalesced
' along with any insertion and deletion actions into a single compound action, otherwise 0.
' Coalescing treats coalescible container actions as transparent so will still only group
' together insertions that look like typing or deletions that look like multiple uses of
' the Backspace or Delete keys.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AddUndoAction (BYVAL hSci AS DWORD, BYVAL token AS LONG, BYVAL flags AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ADDUNDOACTION, token, flags)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AddUndoAction (BYVAL pSci AS DWORD, BYVAL token AS LONG, BYVAL flags AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ADDUNDOACTION, token, flags)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                               Selection and information
' ########################################################################################

' ========================================================================================
' SCI_GETTEXTLENGTH, SCI_GETLENGTH
' Return the length of the document in bytes.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetTextLength (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETTEXTLENGTH, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetTextLength (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETTEXTLENGTH, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetLength (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETLENGTH, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetLength (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETLENGTH, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETLINECOUNT
' This returns the number of lines in the document. An empty document contains 1 line. A
' document holding only an end of line sequence has 2 lines.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetLineCount (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETLINECOUNT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetLineCount (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETLINECOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETFIRSTVISIBLELINE(int lineDisplay)
' SCI_GETFIRSTVISIBLELINE
' These messages retrieve and set the line number of the first visible line in the
' Scintilla view. The first line in the document is numbered 0. The value is a visible
' line rather than a document line.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetFirstVisibleLine (BYVAL hSci AS DWORD, BYVAL lineDisplay AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETFIRSTVISIBLELINE, lineDisplay, 0)
END FUNCTION
' ========================================================================================
FUNCTION SCIP_SetFirstVisibleLine (BYVAL pSci AS DWORD, BYVAL lineDisplay AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETFIRSTVISIBLELINE, lineDisplay, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetFirstVisibleLine (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETFIRSTVISIBLELINE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetFirstVisibleLine (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETFIRSTVISIBLELINE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_LINESONSCREEN
' This returns the number of complete lines visible on the screen. With a constant line
' height, this is the vertical space available divided by the line separation. Unless you
' arrange to size your window to an integral number of lines, there may be a partial line
' visible at the bottom of the view.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_LinesOnScreen (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LINESONSCREEN, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LinesOnScreen (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LINESONSCREEN, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETMODIFY
' This returns non-zero if the document is modified and 0 if it is unmodified. The modified
' status of a document is determined by the undo position relative to the save point. The
' save point is set by SCI_SETSAVEPOINT, usually when you have saved data to a file.
' If you need to be notified when the document becomes modified, Scintilla notifies the
' container that it has entered or left the save point with the SCN_SAVEPOINTREACHED and
' SCN_SAVEPOINTLEFT notification messages.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetModify (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETMODIFY, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetModify (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETMODIFY, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETSEL(int anchorPos, int currentPos)
' This message sets both the anchor and the current position. If currentPos is negative,
' it means the end of the document. If anchorPos is negative, it means remove any selection
' (i.e. set the anchor to the same position as currentPos). The caret is scrolled into
' view after this operation.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetSel (BYVAL hSci AS DWORD, BYVAL anchorPos AS LONG, BYVAL currentPos AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETSEL, anchorPos, currentPos)
END FUNCTION
' ========================================================================================
FUNCTION SCIP_SetSel (BYVAL pSci AS DWORD, BYVAL anchorPos AS LONG, BYVAL currentPos AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETSEL, anchorPos, currentPos)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GOTOPOS(int pos)
' This removes any selection, sets the caret at pos and scrolls the view to make the caret
' visible, if necessary. It is equivalent to SCI_SETSEL(pos, pos). The anchor position is
' set the same as the current position.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GotoPos (BYVAL hSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GOTOPOS, nPos, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GotoPos (BYVAL pSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GOTOPOS, nPos, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GOTOLINE(int line)
' This removes any selection and sets the caret at the start of line number line and
' scrolls the view (if needed) to make it visible. The anchor position is set the same as
' the current position. If line is outside the lines in the document (first line is 0),
' the line set is the first or last.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GotoLine (BYVAL hSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GOTOLINE, nLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GotoLine (BYVAL pSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GOTOLINE, nLine, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETCURRENTPOS(int pos)
' This sets the current position and creates a selection between the anchor and the current
' position. The caret is not scrolled into view.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetCurrentPos (BYVAL hSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETCURRENTPOS, nPos, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetCurrentPos (BYVAL pSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETCURRENTPOS, nPos, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETCURRENTPOS
' This returns the current position.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetCurrentPos (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETCURRENTPOS, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetCurrentPos (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETCURRENTPOS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETANCHOR(int pos)
' This sets the anchor position and creates a selection between the anchor position and
' the current position. The caret is not scrolled into view.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetAnchor (BYVAL hSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETANCHOR, nPos, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetAnchor (BYVAL pSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETANCHOR, nPos, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETANCHOR
' This returns the current anchor position.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetAnchor (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETANCHOR, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetAnchor (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETANCHOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETSELECTIONSTART(int pos)
' SCI_SETSELECTIONEND(int pos)
' These set the selection based on the assumption that the anchor position is less than
' the current position. They do not make the caret visible. The table shows the positions
' of the anchor and the current position after using these messages.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetSelectionStart (BYVAL hSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETSELECTIONSTART, nPos, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetSelectionStart (BYVAL pSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETSELECTIONSTART, nPos, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetSelectionEnd (BYVAL hSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETSELECTIONEND, nPos, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetSelectionEnd (BYVAL pSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETSELECTIONEND, nPos, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETSELECTIONSTART
' SCI_GETSELECTIONEND
' These return the start and end of the selection without regard to which end is the
' current position and which is the anchor. SCI_GETSELECTIONSTART returns the smaller of
' the current position or the anchor position. SCI_GETSELECTIONEND returns the larger of
' the two values.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetSelectionStart (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETSELECTIONSTART, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetSelectionStart (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETSELECTIONSTART, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetSelectionEnd (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETSELECTIONEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetSelectionEnd (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETSELECTIONEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' This removes any selection and sets the caret at pos. The caret is not scrolled into view.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetEmptySelection (BYVAL hSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETEMPTYSELECTION, nPos, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetEmptySelection (BYVAL pSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETEMPTYSELECTION, nPos, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SELECTALL
' This selects all the text in the document. The current position is not scrolled into view.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SelectAll (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SELECTALL, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_LINEFROMPOSITION(int pos)
' This message returns the line that contains the position pos in the document. The return
' value is 0 if pos <= 0. The return value is the last line if pos is beyond the end of the
' document.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_LineFromPosition (BYVAL hSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LINEFROMPOSITION, nPos, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LineFromPosition (BYVAL pSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LINEFROMPOSITION, nPos, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_POSITIONFROMLINE(int line)
' This returns the document position that corresponds with the start of the line. If line
' is negative, the position of the line holding the start of the selection is returned.
' If line is greater than the lines in the document, the return value is -1. If line is
' equal to the number of lines in the document (i.e. 1 line past the last line), the return
' value is the end of the document.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_PositionFromLine (BYVAL hSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_POSITIONFROMLINE, nLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_PositionFromLine (BYVAL pSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_POSITIONFROMLINE, nLine, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETLINEENDPOSITION(int line)
' This returns the position at the end of the line, before any line end characters. If
' line is the last line in the document (which does not have any end of line characters),
' the result is the size of the document. If line is negative or line >= SCI_GETLINECOUNT(),
' the result is undefined.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetLineEndPosition (BYVAL hSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETLINEENDPOSITION, nLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetLineEndPosition (BYVAL pSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETLINEENDPOSITION, nLine, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_LINELENGTH(int line)
' This returns the length of the line, including any line end characters. If line is
' negative or beyond the last line in the document, the result is 0. If you want the
' length of the line not including any end of line characters, use
' SCI_GETLINEENDPOSITION(line) - SCI_POSITIONFROMLINE(line).
' ========================================================================================
' ========================================================================================
FUNCTION SCI_LineLength (BYVAL hSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LINELENGTH, nLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LineLength (BYVAL pSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LINELENGTH, nLine, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETSELTEXT(<unused>, char *text)
' This copies the currently selected text and a terminating 0 byte to the text buffer.
' The buffer size should be determined by calling with a NULL pointer for the text
' argument SCI_GETSELTEXT(0,0). This allows for rectangular and discontiguous selections
' as well as simple selections. See Multiple Selection for information on how multiple
' and rectangular selections and virtual space are copied.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetSelText (BYVAL hSci AS DWORD) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = SendMessageA(hSci, %SCI_GETSELTEXT, 0, 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen)
   SendMessageA(hSci, %SCI_GETSELTEXT, 0, STRPTR(buffer))
   FUNCTION = REMOVE$(buffer, CHR$(0))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetSelText (BYVAL pSci AS DWORD) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = Scintilla_DirectFunction(pSci, %SCI_GETSELTEXT, 0, 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen)
   Scintilla_DirectFunction(pSci, %SCI_GETSELTEXT, 0, STRPTR(buffer))
   FUNCTION = REMOVE$(buffer, CHR$(0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETCURLINE(int textLen, char *text)
' This retrieves the text of the line containing the caret and returns the position within
' the line of the caret. Pass in char* text pointing at a buffer large enough to hold the
' text you wish to retrieve and a terminating 0 character. Set textLen to the length of
' the buffer which must be at least 1 to hold the terminating 0 character. If the text
' argument is 0 then the length that should be allocated to store the entire current line
' is returned.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetCurLine (BYVAL hSci AS DWORD) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = SendMessageA(hSci, %SCI_GETCURLINE, 0, 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen + 1)
   SendMessageA(hSci, %SCI_GETCURLINE, 0, STRPTR(buffer))
   FUNCTION = REMOVE$(buffer, CHR$(0))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetCurLine (BYVAL pSci AS DWORD) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = Scintilla_DirectFunction(pSci, %SCI_GETCURLINE, 0, 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen + 1)
   Scintilla_DirectFunction(pSci, %SCI_GETCURLINE, 0, STRPTR(buffer))
   FUNCTION = REMOVE$(buffer, CHR$(0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SELECTIONISRECTANGLE
' This returns 1 if the current selection is in rectangle mode, 0 if not.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SelectionIsRectangle (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SELECTIONISRECTANGLE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SelectionIsRectangle (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SELECTIONISRECTANGLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETSELECTIONMODE(int mode)
' SCI_GETSELECTIONMODE
' The two functions set and get the selection mode, which can be stream (SC_SEL_STREAM=0)
' or rectangular (SC_SEL_RECTANGLE=1) or by lines (SC_SEL_LINES=2) or thin rectangular
' (SC_SEL_THIN=3). When set in these modes, regular caret moves will extend or reduce the
' selection, until the mode is cancelled by a call with same value or with SCI_CANCEL.
' The get function returns the current mode even if the selection was made by mouse or
' with regular extended moves. SC_SEL_THIN is the mode after a rectangular selection has
' been typed into and ensures that no characters are selected.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetSelectionMode (BYVAL hSci AS DWORD, BYVAL nMode AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETSELECTIONMODE, nMode, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetSelectionMode (BYVAL pSci AS DWORD, BYVAL nMode AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETSELECTIONMODE, nMode, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetSelectionMode (BYVAL hSci AS DWORD, BYVAL nMode AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETSELECTIONMODE, nMode, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetSelectionMode (BYVAL pSci AS DWORD, BYVAL nMode AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETSELECTIONMODE, nMode, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETLINESELSTARTPOSITION(int line)
' SCI_GETLINESELENDPOSITION(int line)
' Retrieve the position of the start and end of the selection at the given line with
' INVALID_POSITION returned if no selection on this line.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetLineSelStartPosition (BYVAL hSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETLINESELSTARTPOSITION, nLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetLineSelStartPosition (BYVAL pSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETLINESELSTARTPOSITION, nLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetLineSelEndPosition (BYVAL hSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETLINESELENDPOSITION, nLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetLineSelEndPosition (BYVAL pSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETLINESELENDPOSITION, nLine, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_MOVECARETINSIDEVIEW
' If the caret is off the top or bottom of the view, it is moved to the nearest line that
' is visible to its current position. Any selection is lost.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_MoveCaretInsideView (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETLINESELENDPOSITION, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MoveCaretInsideView (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETLINESELENDPOSITION, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_WORDENDPOSITION(int position, bool onlyWordCharacters)
' SCI_WORDSTARTPOSITION(int position, bool onlyWordCharacters)
' These messages return the start and end of words using the same definition of words as
' used internally within Scintilla. You can set your own list of characters that count as
' words with SCI_SETWORDCHARS. The position sets the start or the search, which is forwards
' when searching for the end and backwards when searching for the start.
' Set onlyWordCharacters to true (1) to stop searching at the first non-word character in
' the search direction. If onlyWordCharacters is false (0), the first character in the
' search direction sets the type of the search as word or non-word and the search stops at
' the first non-matching character. Searches are also terminated by the start or end of
' the document.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_WordEndPosition (BYVAL hSci AS DWORD, BYVAL nPos AS LONG, BYVAL onlyWordCharacters AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_WORDENDPOSITION, nPos, onlyWordCharacters)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_WordEndPosition (BYVAL pSci AS DWORD, BYVAL nPos AS LONG, BYVAL onlyWordCharacters AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_WORDENDPOSITION, nPos, onlyWordCharacters)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_WordStartPosition (BYVAL hSci AS DWORD, BYVAL nPos AS LONG, BYVAL onlyWordCharacters AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_WORDSTARTPOSITION, nPos, onlyWordCharacters)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_WordStartPosition (BYVAL pSci AS DWORD, BYVAL nPos AS LONG, BYVAL onlyWordCharacters AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_WORDSTARTPOSITION, nPos, onlyWordCharacters)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_POSITIONBEFORE(int position)
' SCI_POSITIONAFTER(int position)
' These messages return the position before and after another position in the document
' taking into account the current code page. The minimum position returned is 0 and the
' maximum is the last position in the document. If called with a position within a multi
' byte character will return the position of the start/end of that character.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_PositionBefore (BYVAL hSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_POSITIONBEFORE, nPos, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_PositionBefore (BYVAL pSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_POSITIONBEFORE, nPos, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_PositionAfter (BYVAL hSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_POSITIONAFTER, nPos, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_PositionAfter (BYVAL pSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_POSITIONAFTER, nPos, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_POSITIONRELATIVE(int position, int relative)
' Count a number of whole characters before or after the argument position and return that
' position. The minimum position returned is 0 and the maximum is the last position in the
' document.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_PositionRelative (BYVAL hSci AS DWORD, BYVAL nPosition AS LONG, BYVAL relative AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_POSITIONRELATIVE, nPosition, relative)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_PositionRelative (BYVAL pSci AS DWORD, BYVAL nPosition AS LONG, BYVAL relative AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_POSITIONRELATIVE, nPosition, relative)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the number of whole characters between two positions.
' ========================================================================================
FUNCTION SCI_CountCharacters (BYVAL hSci AS DWORD, BYVAL startPos AS LONG, BYVAL endPos AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_COUNTCHARACTERS, startPos, endPos)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CountCharacters (BYVAL pSci AS DWORD, BYVAL startPos AS LONG, BYVAL endPos AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_COUNTCHARACTERS, startPos, endPos)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_TEXTWIDTH(int styleNumber, const char *text)
' This returns the pixel width of a string drawn in the given styleNumber which can be
' used, for example, to decide how wide to make the line number margin in order to display
' a given number of numerals.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_TextWidth (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_TEXTWIDTH, styleNumber, STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_TextWidth (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL strText AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_TEXTWIDTH, styleNumber, STRPTR(strText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_TEXTHEIGHT(int line)
' This returns the height in pixels of a particular line. Currently all lines are the
' same height.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_TextHeight (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_TEXTHEIGHT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_TextHeight (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_TEXTHEIGHT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETCOLUMN(int pos)
' This message returns the column number of a position pos within the document taking the
' width of tabs into account. This returns the column number of the last tab on the line
' before pos, plus the number of characters between the last tab and pos. If there are no
' tab characters on the line, the return value is the number of characters up to the
' position on the line. In both cases, double byte characters count as a single character.
' This is probably only useful with monospaced fonts.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetColumn (BYVAL hSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETCOLUMN, nPos, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetColumn (BYVAL pSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETCOLUMN, nPos, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_FINDCOLUMN(int line, int column)
' This message returns the position of a column on a line taking the width of tabs into
' account. It treats a multi-byte character as a single column. Column numbers, like lines
' start at 0.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_FindColumn (BYVAL hSci AS DWORD, BYVAL nLine AS LONG, BYVAL nColumn AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_FINDCOLUMN, nLine, nColumn)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_FindColumn (BYVAL pSci AS DWORD, BYVAL nline AS LONG, BYVAL nColumn AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_FINDCOLUMN, nLine, nColumn)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_POSITIONFROMPOINT(int x, int y)
' SCI_POSITIONFROMPOINTCLOSE(int x, int y)
' SCI_POSITIONFROMPOINT finds the closest character position to a point and
' SCI_POSITIONFROMPOINTCLOSE is similar but returns -1 if the point is outside the window
' or not close to any characters.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_PositionFromPoint (BYVAL hSci AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_POSITIONFROMPOINT, x, y)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_PositionFromPoint (BYVAL pSci AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_POSITIONFROMPOINT, x, y)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_PositionFromPointClose (BYVAL hSci AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_POSITIONFROMPOINTCLOSE, x, y)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_PositionFromPointClose (BYVAL pSci AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_POSITIONFROMPOINTCLOSE, x, y)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_CHARPOSITIONFROMPOINT(int x, int y)
' SCI_CHARPOSITIONFROMPOINTCLOSE(int x, int y)
' SCI_CHARPOSITIONFROMPOINT finds the closest character to a point and
' SCI_CHARPOSITIONFROMPOINTCLOSE is similar but returns -1 if the point is outside the
' window or not close to any characters. This is similar to the previous methods but finds
' characters rather than inter-character positions.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_CharPositionFromPoint (BYVAL hSci AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CHARPOSITIONFROMPOINT, x, y)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CharPositionFromPoint (BYVAL pSci AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CHARPOSITIONFROMPOINT, x, y)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_CharPositionFromPointClose (BYVAL hSci AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CHARPOSITIONFROMPOINTCLOSE, x, y)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CharPositionFromPointClose (BYVAL pSci AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CHARPOSITIONFROMPOINTCLOSE, x, y)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_POINTXFROMPOSITION(<unused>, int pos)
' SCI_POINTYFROMPOSITION(<unused>, int pos)
' These messages return the x and y display pixel location of text at position pos in the
' document.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_PointXFromPosition (BYVAL hSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_POINTXFROMPOSITION, 0, nPos)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_PointXFromPosition (BYVAL pSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_POINTXFROMPOSITION, 0, nPos)
END FUNCTION
' ========================================================================================
FUNCTION SCI_PointYFromPosition (BYVAL hSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_POINTYFROMPOSITION, 0, nPos)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_PointYFromPosition (BYVAL pSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_POINTYFROMPOSITION, 0, nPos)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_HIDESELECTION(bool hide)
' The normal state is to make the selection visible by drawing it as set by SCI_SETSELFORE
' and SCI_SETSELBACK. However, if you hide the selection, it is drawn as normal text.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_HideSelection (BYVAL hSci AS DWORD, BYVAL bHide AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_HIDESELECTION, bHide, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_HideSelection (BYVAL pSci AS DWORD, BYVAL bHide AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_HIDESELECTION, bHide, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_CHOOSECARETX
' Scintilla remembers the x value of the last position horizontally moved to explicitly by
' the user and this value is then used when moving vertically such as by using the up and
' down keys. This message sets the current x position of the caret as the remembered value.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_ChooseCaretX (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CHOOSECARETX, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ChooseCaretX (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CHOOSECARETX, 0, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                         Multiple Selection and Virtual Space
' ########################################################################################

' ========================================================================================
' SCI_SETMULTIPLESELECTION(bool multipleSelection)
' SCI_GETMULTIPLESELECTION
' Enable or disable multiple selection.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetMultipleSelection (BYVAL hSci AS DWORD, BYVAL multipleSelection AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETMULTIPLESELECTION, multipleSelection, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetMultipleSelection (BYVAL pSci AS DWORD, BYVAL multipleSelection AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETMULTIPLESELECTION, multipleSelection, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetMultipleSelection (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETMULTIPLESELECTION, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetMultipleSelection (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETMULTIPLESELECTION, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETADDITIONALSELECTIONTYPING(bool additionalSelectionTyping)
' SCI_GETADDITIONALSELECTIONTYPING
' Whether typing, backspace, or delete works with multiple selections simultaneously.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetAdditionalSelectionTyping (BYVAL hSci AS DWORD, BYVAL additionalSelectionTyping AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETMULTIPLESELECTION, additionalSelectionTyping, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetAdditionalSelectionTyping (BYVAL pSci AS DWORD, BYVAL additionalSelectionTyping AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETMULTIPLESELECTION, additionalSelectionTyping, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetAdditionalSelectionTyping (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETADDITIONALSELECTIONTYPING, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetAdditionalSelectionTyping (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETADDITIONALSELECTIONTYPING, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETMULTIPASTE(int multiPaste)
' SCI_GETMULTIPASTE
' When pasting into multiple selections, the pasted text can go into just the main
' selection with SC_MULTIPASTE_ONCE=0 or into each selection with SC_MULTIPASTE_EACH=1.
' SC_MULTIPASTE_ONCE is the default.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetMultiPaste (BYVAL hSci AS DWORD, BYVAL multiPaste AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETMULTIPASTE, multiPaste, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetMultiPaste (BYVAL pSci AS DWORD, BYVAL multiPaste AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETMULTIPASTE, multiPaste, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetMultiPaste (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETMULTIPASTE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetMultiPaste (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETMULTIPASTE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETVIRTUALSPACEOPTIONS(int virtualSpace)
' SCI_GETVIRTUALSPACEOPTIONS
' Virtual space can be enabled or disabled for rectangular selections or in other
' circumstances or in both. There are two bit flags SCVS_RECTANGULARSELECTION=1 and
' SCVS_USERACCESSIBLE=2 which can be set independently. SCVS_NONE=0, the default, disables
' all use of virtual space.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetVirtualSpaceOptions (BYVAL hSci AS DWORD, BYVAL virtualSpace AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETVIRTUALSPACEOPTIONS, virtualSpace, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetVirtualSpaceOptions (BYVAL pSci AS DWORD, BYVAL virtualSpace AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETVIRTUALSPACEOPTIONS, virtualSpace, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetVirtualSpaceOptions (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETVIRTUALSPACEOPTIONS, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetVirtualSpaceOptions (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETVIRTUALSPACEOPTIONS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETRECTANGULARSELECTIONMODIFIER(int modifier)
' SCI_GETRECTANGULARSELECTIONMODIFIER
' On GTK+, the key used to indicate that a rectangular selection should be created when
' combined with a mouse drag can be set. The three possible values are SCMOD_CTRL=2
' (default), SCMOD_ALT=4 or SCMOD_SUPER=8. Since SCMOD_ALT is often already used by a
' window manager, the window manager may need configuring to allow this choice.
' SCMOD_SUPER is often a system dependent modifier key such as the Left Windows key on a
' Windows keyboard or the Command key on a Mac.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetRectangularSelectionModifier (BYVAL hSci AS DWORD, BYVAL modifier AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETRECTANGULARSELECTIONMODIFIER, modifier, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetRectangularSelectionModifier (BYVAL pSci AS DWORD, BYVAL modifier AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETRECTANGULARSELECTIONMODIFIER, modifier, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetRectangularSelectionModifier (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETRECTANGULARSELECTIONMODIFIER, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetRectangularSelectionModifier (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETRECTANGULARSELECTIONMODIFIER, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETSELECTIONS
' Return the number of selections currently active.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetSelections (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETSELECTIONS, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetSelections (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETSELECTIONS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETSELECTIONEMPTY
' Return 1 if every selected range is empty else 0.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetSelectionEmpty (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETSELECTIONEMPTY, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetSelectionEmpty (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETSELECTIONEMPTY, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_CLEARSELECTIONS
' Set a single empty selection at 0 as the only selection.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_ClearSelections (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CLEARSELECTIONS, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ClearSelections (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CLEARSELECTIONS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETSELECTION(int caret, int anchor)
' Set a single selection from anchor to caret as the only selection.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetSelection (BYVAL hSci AS DWORD, BYVAL caret AS LONG, BYVAL anchor AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETSELECTION, caret, anchor)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetSelection (BYVAL pSci AS DWORD, BYVAL caret AS LONG, BYVAL anchor AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETSELECTION, caret, anchor)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_ADDSELECTION(int caret, int anchor)
' Add a new selection from anchor to caret as the main selection retaining all other
' selections as additional selections. Since there is always at least one selection, to
' set a list of selections, the first selection should be added with SCI_SETSELECTION and
' later selections added with SCI_ADDSELECTION.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AddSelection (BYVAL hSci AS DWORD, BYVAL caret AS LONG, BYVAL anchor AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ADDSELECTION, caret, anchor)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AddSelection (BYVAL pSci AS DWORD, BYVAL caret AS LONG, BYVAL anchor AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ADDSELECTION, caret, anchor)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_DROPSELECTIONN(int selection)
' If there are multiple selections, remove the indicated selection. If this was the main
' selection then make the previous selection the main and if it was the first then the
' last selection becomes main. If there is only one selection, or there is no selection,
' then there is no effect.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_DropSelectionN (BYVAL hSci AS DWORD, BYVAL selection AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_DROPSELECTIONN, selection, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_DropSelectionN (BYVAL pSci AS DWORD, BYVAL selection AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_DROPSELECTIONN, selection, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETMAINSELECTION(int selection)
' SCI_GETMAINSELECTION
' One of the selections is the main selection which is used to determine what range of
' text is automatically visible. The main selection may be displayed in different colours
' or with a differently styled caret. Only an already existing selection can be made main.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetMainSelection (BYVAL hSci AS DWORD, BYVAL selection AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETMAINSELECTION, selection, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetMainSelection (BYVAL pSci AS DWORD, BYVAL selection AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETMAINSELECTION, selection, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetMainSelection (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETMAINSELECTION, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetMainSelection (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETMAINSELECTION, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETSELECTIONNCARET(int selection, int pos)
' SCI_GETSELECTIONNCARET(int selection)
' SCI_SETSELECTIONNCARETVIRTUALSPACE(int selection, int space)
' SCI_GETSELECTIONNCARETVIRTUALSPACE(int selection)
' SCI_SETSELECTIONNANCHOR(int selection, int posAnchor)
' SCI_GETSELECTIONNANCHOR(int selection)
' SCI_SETSELECTIONNANCHORVIRTUALSPACE(int selection, int space)
' SCI_GETSELECTIONNANCHORVIRTUALSPACE(int selection)
' Set or query the position and amount of virtual space for the caret and anchor of each
' already existing selection.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetSelectionCaret (BYVAL hSci AS DWORD, BYVAL selection AS LONG, BYVAL nPos AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETSELECTIONNCARET, selection, nPos)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetSelectionCaret (BYVAL pSci AS DWORD, BYVAL selection AS LONG, BYVAL nPos AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETSELECTIONNCARET, selection, nPos)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetSelectionCaret (BYVAL hSci AS DWORD, BYVAL selection AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETSELECTIONNCARET, selection, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetSelectionCaret (BYVAL pSci AS DWORD, BYVAL selection AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETSELECTIONNCARET, selection, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_SetSelectionCaretVirtualSpace (BYVAL hSci AS DWORD, BYVAL selection AS LONG, BYVAL nSpace AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETSELECTIONNCARETVIRTUALSPACE, selection, nSpace)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetSelectionCaretVirtualSpace (BYVAL pSci AS DWORD, BYVAL selection AS LONG, BYVAL nSpace AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETSELECTIONNCARETVIRTUALSPACE, selection, nSpace)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetSelectionCaretVirtualSpace (BYVAL hSci AS DWORD, BYVAL selection AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETSELECTIONNCARETVIRTUALSPACE, selection, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetSelectionCaretVirtualSpace (BYVAL pSci AS DWORD, BYVAL selection AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETSELECTIONNCARETVIRTUALSPACE, selection, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_SetSelectionAnchor (BYVAL hSci AS DWORD, BYVAL selection AS LONG, BYVAL posAnchor AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETSELECTIONNANCHOR, selection, posAnchor)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetSelectionAnchor (BYVAL pSci AS DWORD, BYVAL selection AS LONG, BYVAL posAnchor AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETSELECTIONNANCHOR, selection, posAnchor)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetSelectionAnchor (BYVAL hSci AS DWORD, BYVAL selection AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETSELECTIONNANCHOR, selection, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetSelectionAnchor (BYVAL pSci AS DWORD, BYVAL selection AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETSELECTIONNANCHOR, selection, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_SetSelectionAnchorVirtualSpace (BYVAL hSci AS DWORD, BYVAL selection AS LONG, BYVAL nSpace AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETSELECTIONNANCHORVIRTUALSPACE, selection, nSpace)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetSelectionAnchorVirtualSpace (BYVAL pSci AS DWORD, BYVAL selection AS LONG, BYVAL nSpace AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETSELECTIONNANCHORVIRTUALSPACE, selection, nSpace)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetSelectionAnchorVirtualSpace (BYVAL hSci AS DWORD, BYVAL selection AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETSELECTIONNANCHORVIRTUALSPACE, selection, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetSelectionAnchorVirtualSpace (BYVAL pSci AS DWORD, BYVAL selection AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETSELECTIONNANCHORVIRTUALSPACE, selection, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETRECTANGULARSELECTIONCARET(int pos)
' SCI_GETRECTANGULARSELECTIONCARET
' SCI_SETRECTANGULARSELECTIONCARETVIRTUALSPACE(int space)
' SCI_GETRECTANGULARSELECTIONCARETVIRTUALSPACE
' SCI_SETRECTANGULARSELECTIONANCHOR(int posAnchor)
' SCI_GETRECTANGULARSELECTIONANCHOR
' SCI_SETRECTANGULARSELECTIONANCHORVIRTUALSPACE(int space)
' SCI_GETRECTANGULARSELECTIONANCHORVIRTUALSPACE
' Set or query the position and amount of virtual space for the caret and anchor of the
' rectangular selection. After setting the rectangular selection, this is broken down into
' multiple selections, one for each line.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetRectangularSelectionCaret (BYVAL hSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETRECTANGULARSELECTIONCARET, nPos, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetRectangularSelectionCaret (BYVAL pSci AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETRECTANGULARSELECTIONCARET, nPos, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetRectangularSelectionCaret (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETSELECTIONNEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetRectangularSelectionCaret (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETSELECTIONNEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_SetRectangularSelectionCaretVirtualSpace (BYVAL hSci AS DWORD, BYVAL nSpace AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETRECTANGULARSELECTIONCARETVIRTUALSPACE, nSpace, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetRectangularSelectionCaretVirtualSpace (BYVAL pSci AS DWORD, BYVAL nSpace AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETRECTANGULARSELECTIONCARETVIRTUALSPACE, nSpace, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetRectangularSelectionCaretVirtualSpace (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETRECTANGULARSELECTIONCARETVIRTUALSPACE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetRectangularSelectionCaretVirtualSpace (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETRECTANGULARSELECTIONCARETVIRTUALSPACE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_SetRectangularSelectionAnchor (BYVAL hSci AS DWORD, BYVAL posAnchor AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETRECTANGULARSELECTIONANCHOR, posAnchor, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetRectangularSelectionAnchor (BYVAL pSci AS DWORD, BYVAL posAnchor AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETRECTANGULARSELECTIONANCHOR, posAnchor, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetRectangularSelectionAnchor (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETRECTANGULARSELECTIONANCHOR, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetRectangularSelectionAnchor (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETRECTANGULARSELECTIONANCHOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_SetRectangularSelectionAnchorVirtualSpace (BYVAL hSci AS DWORD, BYVAL nSpace AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETRECTANGULARSELECTIONANCHORVIRTUALSPACE, nSpace, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetRectangularSelectionAnchorVirtualSpace (BYVAL pSci AS DWORD, BYVAL nSpace AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETRECTANGULARSELECTIONANCHORVIRTUALSPACE, nSpace, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetRectangularSelectionAnchorVirtualSpace (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETRECTANGULARSELECTIONANCHORVIRTUALSPACE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetRectangularSelectionAnchorVirtualSpace (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETRECTANGULARSELECTIONANCHORVIRTUALSPACE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETADDITIONALSELALPHA(int alpha)
' SCI_GETADDITIONALSELALPHA
' SCI_SETADDITIONALSELFORE(int colour)
' SCI_SETADDITIONALSELBACK(int colour)
' Modify the appearence of additional selections so that they can be differentiated from
' the main selection which has its appearence set with SCI_SETSELALPHA, SCI_GETSELALPHA,
' SCI_SETSELFORE, and SCI_SETSELBACK.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetAdditionalSelAlpha (BYVAL hSci AS DWORD, BYVAL alpha AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETADDITIONALSELALPHA, alpha, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetAdditionalSelAlpha (BYVAL pSci AS DWORD, BYVAL alpha AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETADDITIONALSELALPHA, alpha, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetAdditionalSelAlpha (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETADDITIONALSELALPHA, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetAdditionalSelAlpha (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETADDITIONALSELALPHA, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_SetAdditionalSelFore (BYVAL hSci AS DWORD, BYVAL colour AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETADDITIONALSELFORE, colour, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetAdditionalSelFore (BYVAL pSci AS DWORD, BYVAL colour AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETADDITIONALSELFORE, colour, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_SetAdditionalSelBack (BYVAL hSci AS DWORD, BYVAL colour AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETADDITIONALSELBACK, colour, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetAdditionalSelBack (BYVAL pSci AS DWORD, BYVAL colour AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETADDITIONALSELBACK, colour, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETADDITIONALCARETFORE(int colour)
' SCI_GETADDITIONALCARETFORE
' SCI_SETADDITIONALCARETSBLINK(bool additionalCaretsBlink)
' SCI_GETADDITIONALCARETSBLINK
' Modify the appearence of additional carets so that they can be differentiated from the
' main caret which has its appearence set with SCI_SETCARETFORE, SCI_GETCARETFORE,
' SCI_SETCARETPERIOD, and SCI_GETCARETPERIOD.
' ========================================================================================

' ========================================================================================
FUNCTION SCI_SetAdditionalCaretFore (BYVAL hSci AS DWORD, BYVAL colour AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETADDITIONALCARETFORE, colour, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetAdditionalCaretFore (BYVAL pSci AS DWORD, BYVAL colour AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETADDITIONALCARETFORE, colour, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetAdditionalCaretFore (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETADDITIONALCARETFORE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetAdditionalCaretFore (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETADDITIONALCARETFORE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_SetAdditionalCaretsBlink (BYVAL hSci AS DWORD, BYVAL additionalCaretsBlink AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETADDITIONALCARETSBLINK, additionalCaretsBlink, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetAdditionalCaretsBlink (BYVAL pSci AS DWORD, BYVAL additionalCaretsBlink AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETADDITIONALCARETSBLINK, additionalCaretsBlink, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetAdditionalCaretsBlink (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETADDITIONALCARETSBLINK, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetAdditionalCaretsBlink (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETADDITIONALCARETSBLINK, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETADDITIONALCARETSVISIBLE(bool additionalCaretsVisible)
' SCI_GETADDITIONALCARETSVISIBLE
' Determine whether to show additional carets (defaults to true).
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetAdditionalCaretsVisible (BYVAL hSci AS DWORD, BYVAL additionalCaretsVisible AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETADDITIONALCARETSVISIBLE, additionalCaretsVisible, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetAdditionalCaretsVisible (BYVAL pSci AS DWORD, BYVAL additionalCaretsVisible AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETADDITIONALCARETSVISIBLE, additionalCaretsVisible, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetAdditionalCaretsVisible (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETADDITIONALCARETSVISIBLE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetAdditionalCaretsVisible (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETADDITIONALCARETSVISIBLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SWAPMAINANCHORCARET
' SCI_ROTATESELECTION
' These commands may be assigned to keys to make it possible to manipulate multiple
' selections. SCI_SWAPMAINANCHORCARET moves the caret to the opposite end of the main
' selection. SCI_ROTATESELECTION makes the next selection be the main selection.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SwapMainChorCaret (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SWAPMAINANCHORCARET, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SwapMainChorCaret (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SWAPMAINANCHORCARET, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_RotateSelection (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ROTATESELECTION, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_RotateSelection (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ROTATESELECTION, 0, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                            Scrolling and automatic scrolling
' ########################################################################################

' ========================================================================================
' SCI_LINESCROLL(int column, int line)
' This will attempt to scroll the display by the number of columns and lines that you
' specify. Positive line values increase the line number at the top of the screen (i.e.
' they move the text upwards as far as the user is concerned), Negative line values do the
' reverse.
' The column measure is the width of a space in the default style. Positive values
' increase the column at the left edge of the view (i.e. they move the text leftwards as
' far as the user is concerned). Negative values do the reverse.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_LineScroll (BYVAL hSci AS DWORD, BYVAL nColumn AS LONG, BYVAL nLine AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LINESCROLL, nColumn, nLine)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LineScroll (BYVAL pSci AS DWORD, BYVAL nColumn AS LONG, BYVAL nLine AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LINESCROLL, nColumn, nLine)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SCROLLCARET
' If the current position (this is the caret if there is no selection) is not visible, the
' view is scrolled to make it visible according to the current caret policy.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_ScrollCaret (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SCROLLCARET, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ScrollCaret (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SCROLLCARET, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SCROLLRANGE(int secondary, int primary)
' Scroll the argument positions and the range between them into view giving priority to
' the primary position then the secondary position. The behaviour is similar to
' SCI_SCROLLCARET with the primary position used instead of the caret. An effort is then
' made to ensure that the secondary position and range between are also visible. This may
' be used to make a search match visible.
' ========================================================================================
FUNCTION SCI_ScrollRange (BYVAL hSci AS DWORD, BYVAL secondary AS LONG, BYVAL primary AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SCROLLRANGE, secondary, primary)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ScrollRange (BYVAL pSci AS DWORD, BYVAL secondary AS LONG, BYVAL primary AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SCROLLRANGE, secondary, primary)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETXCARETPOLICY(int caretPolicy, int caretSlop)
' SCI_SETYCARETPOLICY(int caretPolicy, int caretSlop)
' These set the caret policy. The value of caretPolicy is a combination of CARET_SLOP,
' CARET_STRICT, CARET_JUMPS and CARET_EVEN.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetXCaretPolicy (BYVAL hSci AS DWORD, BYVAL caretPolicy AS LONG, BYVAL caretSlop AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETXCARETPOLICY, caretPolicy, caretSlop)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetXCaretPolicy (BYVAL pSci AS DWORD, BYVAL caretPolicy AS LONG, BYVAL caretSlop AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETXCARETPOLICY, caretPolicy, caretSlop)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetYCaretPolicy (BYVAL hSci AS DWORD, BYVAL caretPolicy AS LONG, BYVAL caretSlop AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETYCARETPOLICY, caretPolicy, caretSlop)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetYCaretPolicy (BYVAL pSci AS DWORD, BYVAL caretPolicy AS LONG, BYVAL caretSlop AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETYCARETPOLICY, caretPolicy, caretSlop)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETVISIBLEPOLICY(int caretPolicy, int caretSlop)
' This determines how the vertical positioning is determined when SCI_ENSUREVISIBLEENFORCEPOLICY
' is called. It takes VISIBLE_SLOP and VISIBLE_STRICT flags for the policy parameter. It
' is similar in operation to SCI_SETYCARETPOLICY(int caretPolicy, int caretSlop).
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetVisiblePolicy (BYVAL hSci AS DWORD, BYVAL caretPolicy AS LONG, BYVAL caretSlop AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETVISIBLEPOLICY, caretPolicy, caretSlop)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetVisiblePolicy (BYVAL pSci AS DWORD, BYVAL caretPolicy AS LONG, BYVAL caretSlop AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETVISIBLEPOLICY, caretPolicy, caretSlop)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETHSCROLLBAR(bool visible)
' SCI_GETHSCROLLBAR
' The horizontal scroll bar is only displayed if it is needed for the assumed width. If you
' never wish to see it, call SCI_SETHSCROLLBAR(0). Use SCI_SETHSCROLLBAR(1) to enable it
' again. SCI_GETHSCROLLBAR returns the current state. The default state is to display it
' when needed.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetHScrollbar (BYVAL hSci AS DWORD, BYVAL bVisible AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETHSCROLLBAR, bVisible, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetHScrollbar (BYVAL pSci AS DWORD, BYVAL bVisible AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETHSCROLLBAR, bVisible, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetHScrollbar (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETHSCROLLBAR, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetHScrollbar (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(pSci, %SCI_GETHSCROLLBAR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETVSCROLLBAR(bool visible)
' SCI_GETVSCROLLBAR
' By default, the vertical scroll bar is always displayed when required. You can choose to
' hide or show it with SCI_SETVSCROLLBAR and get the current state with SCI_GETVSCROLLBAR.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetVScrollbar (BYVAL hSci AS DWORD, BYVAL bVisible AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETVSCROLLBAR, bVisible, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetVScrollbar (BYVAL pSci AS DWORD, BYVAL bVisible AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETVSCROLLBAR, bVisible, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetVScrollbar (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETVSCROLLBAR, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetVScrollbar (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETVSCROLLBAR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETXOFFSET(int xOffset)
' SCI_GETXOFFSET
' The xOffset is the horizontal scroll position in pixels of the start of the text view.
' A value of 0 is the normal position with the first text column visible at the left of
' the view.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetXOffset (BYVAL hSci AS DWORD, BYVAL xOffset AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETXOFFSET, xOffset, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetXOffset (BYVAL pSci AS DWORD, BYVAL xOffset AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETXOFFSET, xOffset, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetXOffset (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETXOFFSET, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetXOffset (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETXOFFSET, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETSCROLLWIDTH(int pixelWidth)
' SCI_GETSCROLLWIDTH
' For performance, Scintilla does not measure the display width of the document to
' determine the properties of the horizontal scroll bar. Instead, an assumed width is used.
' These messages set and get the document width in pixels assumed by Scintilla. The default
' value is 2000. To ensure the width of the currently visible lines can be scrolled use
' SCI_SETSCROLLWIDTHTRACKING
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetScrollWidth (BYVAL hSci AS DWORD, BYVAL pixelWidth AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETSCROLLWIDTH, pixelWidth, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetScrollWidth (BYVAL pSci AS DWORD, BYVAL pixelWidth AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETSCROLLWIDTH, pixelWidth, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetScrollWidth (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETSCROLLWIDTH, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetScrollWidth (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETSCROLLWIDTH, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETSCROLLWIDTHTRACKING(bool tracking)
' SCI_GETSCROLLWIDTHTRACKING
' If scroll width tracking is enabled then the scroll width is adjusted to ensure that all
' of the lines currently displayed can be completely scrolled. This mode never adjusts the
' scroll width to be narrower.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetScrollWidthTracking (BYVAL hSci AS DWORD, BYVAL tracking AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETSCROLLWIDTHTRACKING, tracking, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetScrollWidthTracking (BYVAL pSci AS DWORD, BYVAL tracking AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETSCROLLWIDTHTRACKING, tracking, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetScrollWidthTracking (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETSCROLLWIDTHTRACKING, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetScrollWidthTracking (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETSCROLLWIDTHTRACKING, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETENDATLASTLINE(bool endAtLastLine)
' SCI_GETENDATLASTLINE
' SCI_SETENDATLASTLINE sets the scroll range so that maximum scroll position has the last
' line at the bottom of the view (default). Setting this to false allows scrolling one
' page below the last line.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetEndAtLastLine (BYVAL hSci AS DWORD, BYVAL endAtLastLine AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETENDATLASTLINE, endAtLastLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetEndAtLastLine (BYVAL pSci AS DWORD, BYVAL endAtLastLine AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETENDATLASTLINE, endAtLastLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetEndAtLastLine (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETENDATLASTLINE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetEndAtLastLine (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETENDATLASTLINE, 0, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                        White Space
' ########################################################################################

' ========================================================================================
' SCI_SETVIEWWS(int wsMode)
' SCI_GETVIEWWS
' White space can be made visible which may be useful for languages in which white space
' is significant, such as Python. Space characters appear as small centred dots and tab
' characters as light arrows pointing to the right. There are also ways to control the
' display of end of line characters. The two messages set and get the white space display
' mode. The wsMode argument can be one of:
'  SCWS_INVISIBLE             0    The normal display mode with white space displayed as an empty background colour.
'  SCWS_VISIBLEALWAYS         1    White space characters are drawn as dots and arrows,
'  SCWS_VISIBLEAFTERINDENT    2    White space used for indentation is displayed normally but after the first visible character, it is shown as dots and arrows.
' The effect of using any other wsMode value is undefined.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetViews (BYVAL hSci AS DWORD, BYVAL wsMode AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETVIEWWS, wsMode, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetViews (BYVAL pSci AS DWORD, BYVAL wsMode AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETVIEWWS, wsMode, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetViews (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETVIEWWS, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetViews (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETVIEWWS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETWHITESPACEFORE(bool useWhitespaceForeColour, int colour)
' SCI_SETWHITESPACEBACK(bool useWhitespaceBackColour, int colour)
' By default, the colour of visible white space is determined by the lexer in use. The
' foreground and/or background colour of all visible white space can be set globally,
' overriding the lexer's colours with SCI_SETWHITESPACEFORE and SCI_SETWHITESPACEBACK.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetWhiteSpaceFore (BYVAL hSci AS DWORD, BYVAL useWhitespaceForeColour AS BYTE, BYVAL colour AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETWHITESPACEFORE, useWhitespaceForeColour, colour)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetWhiteSpaceFore (BYVAL pSci AS DWORD, BYVAL useWhitespaceForeColour AS BYTE, BYVAL colour AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETWHITESPACEFORE, useWhitespaceForeColour, colour)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_SetWhiteSpaceBack (BYVAL hSci AS DWORD, BYVAL useWhitespaceBackColour AS BYTE, BYVAL colour AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETWHITESPACEBACK, useWhitespaceBackColour, colour)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetWhiteSpaceBack (BYVAL pSci AS DWORD, BYVAL useWhitespaceBackColour AS BYTE, BYVAL colour AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETWHITESPACEBACK, useWhitespaceBackColour, colour)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETWHITESPACESIZE(int size)
' SCI_GETWHITESPACESIZE
' SCI_SETWHITESPACESIZE sets the size of the dots used for mark space characters. The
' SCI_GETWHITESPACESIZE message retrieves the current size.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetWhiteSpaceSize (BYVAL hSci AS DWORD, BYVAL nSize AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETWHITESPACESIZE, nSize, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetWhiteSpaceSize (BYVAL pSci AS DWORD, BYVAL nSize AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETWHITESPACESIZE, nSize, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetWhiteSpaceSize (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETWHITESPACESIZE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetWhiteSpaceSize (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETWHITESPACESIZE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETEXTRAASCENT(int extraAscent)
' SCI_GETEXTRAASCENT
' SCI_SETEXTRADESCENT(int extraDescent)
' SCI_GETEXTRADESCENT
' Text is drawn with the base of each character on a 'baseline'. The height of a line is
' found from the maximum that any style extends above the baseline (its 'ascent'), added
' to the maximum that any style extends below the baseline (its 'descent'). Space may be
' added to the maximum ascent (SCI_SETEXTRAASCENT) and the maximum descent
' (SCI_SETEXTRADESCENT) to allow for more space between lines. This may done to make the
' text easier to read or to accomodate underlines or highlights.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetExtraAscent (BYVAL hSci AS DWORD, BYVAL extraAscent AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETEXTRAASCENT, extraAscent, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetExtraAscent (BYVAL pSci AS DWORD, BYVAL extraAscent AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETEXTRAASCENT, extraAscent, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetExtraAscent (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETEXTRAASCENT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetExtraAscent (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETEXTRAASCENT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_SetExtraDescent (BYVAL hSci AS DWORD, BYVAL extraDescent AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETEXTRADESCENT, extraDescent, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetExtraDescent (BYVAL pSci AS DWORD, BYVAL extraDescent AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETEXTRADESCENT, extraDescent, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetExtraDescent (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETEXTRADESCENT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetExtraDescent (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETEXTRADESCENT, 0, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                         Cursor
' ########################################################################################

' ========================================================================================
' SCI_SETCURSOR(int curType)
' SCI_GETCURSOR
' The cursor is normally chosen in a context sensitive way, so it will be different over
' the margin than when over the text. When performing a slow action, you may wish to change
' to a wait cursor. You set the cursor type with SCI_SETCURSOR. The curType argument can be:
'  SC_CURSORNORMAL  -1    The normal cursor is displayed.
'  SC_CURSORWAIT     4    The wait cursor is displayed when the mouse is over or owned by
'                         the Scintilla window.
' Cursor values 1 through 7 have defined cursors, but only SC_CURSORWAIT is usefully
' controllable. Other values of curType cause a pointer to be displayed. The SCI_GETCURSOR
' message returns the last cursor type you set, or SC_CURSORNORMAL (-1) if you have not set
' a cursor type.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetCursor (BYVAL hSci AS DWORD, BYVAL curType AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETCURSOR, curType, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetCursor (BYVAL pSci AS DWORD, BYVAL curType AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETCURSOR, curType, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetCursor (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETCURSOR, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetCursor (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETCURSOR, 0, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                     Mouse capture
' ########################################################################################

' ========================================================================================
' SCI_SETMOUSEDOWNCAPTURES(bool captures)
' SCI_GETMOUSEDOWNCAPTURES
' When the mouse is pressed inside Scintilla, it is captured so future mouse movement
' events are sent to Scintilla. This behavior may be turned off with SCI_SETMOUSEDOWNCAPTURES(0).
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetMouseDownCaptures (BYVAL hSci AS DWORD, BYVAL captures AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETMOUSEDOWNCAPTURES, captures, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetMouseDownCaptures (BYVAL pSci AS DWORD, BYVAL captures AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETMOUSEDOWNCAPTURES, captures, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetMouseDownCaptures (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETMOUSEDOWNCAPTURES, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetMouseDownCaptures (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETMOUSEDOWNCAPTURES, 0, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                     Line Endings
' ########################################################################################

' ========================================================================================
' Scintilla can interpret any of the three major line end conventions, Macintosh (\r),
' Unix (\n) and CP/M / DOS / Windows (\r\n). When the user presses the Enter key, one of
' these line end strings is inserted into the buffer. The default is \r\n in Windows and
' \n in Unix, but this can be changed with the SCI_SETEOLMODE message. You can also convert
' the entire document to one of these line endings with SCI_CONVERTEOLS. Finally, you can
' choose to display the line endings with SCI_SETVIEWEOL.
' ========================================================================================

' ========================================================================================
' SCI_SETEOLMODE(int eolMode)
' SCI_GETEOLMODE
' SCI_SETEOLMODE sets the characters that are added into the document when the user presses
' the Enter key. You can set eolMode to one of SC_EOL_CRLF (0), SC_EOL_CR (1), or SC_EOL_LF
' (2). The SCI_GETEOLMODE message retrieves the current state.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetEOLMode (BYVAL hSci AS DWORD, BYVAL eolMode AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETEOLMODE, eolMode, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetEOLMode (BYVAL pSci AS DWORD, BYVAL eolMode AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETEOLMODE, eolMode, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetEOLMode (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETEOLMODE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetEOLMode (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETEOLMODE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_CONVERTEOLS(int eolMode)
' This message changes all the end of line characters in the document to match eolMode.
' Valid values are: SC_EOL_CRLF (0), SC_EOL_CR (1), or SC_EOL_LF (2).
' ========================================================================================
' ========================================================================================
FUNCTION SCI_ConvertEOLs (BYVAL hSci AS DWORD, BYVAL eolMode AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CONVERTEOLS, eolMode, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ConvertEOLs (BYVAL pSci AS DWORD, BYVAL eolMode AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CONVERTEOLS, eolMode, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETVIEWEOL(bool visible)
' SCI_GETVIEWEOL
' Normally, the end of line characters are hidden, but SCI_SETVIEWEOL allows you to display
' (or hide) them by setting visible true (or false). The visible rendering of the end of
' line characters is similar to (CR), (LF), or (CR)(LF). SCI_GETVIEWEOL returns the current
' state.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetViewEOL (BYVAL hSci AS DWORD, BYVAL bVisible AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETVIEWEOL, bVisible, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetViewEOL (BYVAL pSci AS DWORD, BYVAL bVisible AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETVIEWEOL, bVisible, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetViewEOL (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETVIEWEOL, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetViewEOL (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETVIEWEOL, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETLINEENDTYPESSUPPORTED
' SCI_GETLINEENDTYPESSUPPORTED reports the different types of line ends supported by the
' current lexer. This is a bit set although there is currently only a single choice with
' either SC_LINE_END_TYPE_DEFAULT (0) or SC_LINE_END_TYPE_UNICODE (1). These values are
' also used by the other messages concerned with Unicode line ends.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetLineEndTypesSupported (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETLINEENDTYPESSUPPORTED, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetLineEndTypesSupported (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETLINEENDTYPESSUPPORTED, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETLINEENDTYPESALLOWED(int lineEndBitSet)
' SCI_GETLINEENDTYPESALLOWED
' By default, only the ASCII line ends are interpreted. Unicode line ends may be requested
' with SCI_SETLINEENDTYPESALLOWED(SC_LINE_END_TYPE_UNICODE) but this will be ineffective
' unless the lexer also allows you Unicode line ends. SCI_GETLINEENDTYPESALLOWED returns
' the current state.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetLineEndTypesAllowed (BYVAL hSci AS DWORD, BYVAL lineEndBitSet AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETLINEENDTYPESALLOWED, lineEndBitSet, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetLineEndTypesAllowed (BYVAL pSci AS DWORD, BYVAL lineEndBitSet AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETLINEENDTYPESALLOWED, lineEndBitSet, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetLineEndTypesAllowed (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETLINEENDTYPESALLOWED, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetLineEndTypesAllowed (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETLINEENDTYPESALLOWED, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETLINEENDTYPESACTIVE
' SCI_GETLINEENDTYPESACTIVE reports the set of line ends currently interpreted by Scintilla.
' It is SCI_GETLINEENDTYPESSUPPORTED & SCI_GETLINEENDTYPESALLOWED.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetLineEndTypesActive (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETLINEENDTYPESACTIVE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetLineEndTypesActive (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETLINEENDTYPESACTIVE, 0, 0)
END FUNCTION
' ========================================================================================


' ########################################################################################
'                                       Styling
' ########################################################################################

' ========================================================================================
' The styling messages allow you to assign styles to text. The standard Scintilla settings
' divide the 8 style bits available for each character into 5 bits (0 to 4 = styles 0 to 31)
' that set a style and three bits (5 to 7) that define indicators. You can change the
' balance between styles and indicators with SCI_SETSTYLEBITS. If your styling needs can
' be met by one of the standard lexers, or if you can write your own, then a lexer is
' probably the easiest way to style your document. If you choose to use the container to
' do the styling you can use the SCI_SETLEXER command to select SCLEX_CONTAINER, in which
' case the container is sent a SCN_STYLENEEDED notification each time text needs styling
' for display. As another alternative, you might use idle time to style the document.
' Even if you use a lexer, you might use the styling commands to mark errors detected by a
' compiler. The following commands can be used.
' ========================================================================================

' ========================================================================================
' SCI_GETENDSTYLED
' Scintilla keeps a record of the last character that is likely to be styled correctly.
' This is moved forwards when characters after it are styled and moved backwards if changes
' are made to the text of the document before it. Before drawing text, this position is
' checked to see if any styling is needed and, if so, a SCN_STYLENEEDED notification
' message is sent to the container. The container can send SCI_GETENDSTYLED to work out
' where it needs to start styling. Scintilla will always ask to style whole lines.
' ========================================================================================
FUNCTION SCI_GetEndStyled (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETENDSTYLED, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetEndStyled (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETENDSTYLED, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_STARTSTYLING(int pos, int mask)
' This prepares for styling by setting the styling position pos to start at and a mask
' indicating which bits of the style bytes can be set. The mask allows styling to occur
' over several passes, with, for example, basic styling done on an initial pass to ensure
' that the text of the code is seen quickly and correctly, and then a second slower pass,
' detecting syntax errors and using indicators to show where these are. For example, with
' the standard settings of 5 style bits and 3 indicator bits, you would use a mask value
' of 31 (0x1f) if you were setting text styles and did not want to change the indicators.
' After SCI_STARTSTYLING, send multiple SCI_SETSTYLING messages for each lexical entity to
' style.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_StartStyling (BYVAL hSci AS DWORD, BYVAL nPos AS LONG, BYVAL mask AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STARTSTYLING, nPos, mask)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StartStyling (BYVAL pSci AS DWORD, BYVAL nPos AS LONG, BYVAL mask AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STARTSTYLING, nPos, mask)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETSTYLING(int length, int style)
' This message sets the style of length characters starting at the styling position and
' then increases the styling position by length, ready for the next call. If sCell is the
' style byte, the operation is:
' if ((sCell & mask) != style) sCell = (sCell & ~mask) | (style & mask);
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetStyling (BYVAL hSci AS DWORD, BYVAL nLength AS LONG, BYVAL nStyle AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETSTYLING, nLength, nStyle)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetStyling (BYVAL pSci AS DWORD, BYVAL nLength AS LONG, BYVAL nStyle AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETSTYLING, nLength, nStyle)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETSTYLINGEX(int length, const char *styles)
' As an alternative to SCI_SETSTYLING, which applies the same style to each byte, you can
' use this message which specifies the styles for each of length bytes from the styling
' position and then increases the styling position by length, ready for the next call.
' The length styling bytes pointed at by styles should not contain any bits not set in mask.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetStylingEx (BYVAL hSci AS DWORD, BYVAL nLength AS LONG, BYVAL strStyles AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETSTYLINGEX, nLength, STRPTR(strStyles))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetStylingEx (BYVAL pSci AS DWORD, BYVAL nLength AS LONG, BYVAL strStyles AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETSTYLINGEX, nLength, STRPTR(strStyles))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETLINESTATE(int line, int value)
' SCI_GETLINESTATE(int line)
' As well as the 8 bits of lexical state stored for each character there is also an integer
' stored for each line. This can be used for longer lived parse states such as what the
' current scripting language is in an ASP page. Use SCI_SETLINESTATE to set the integer
' value and SCI_GETLINESTATE to get the value. Changing the value produces a
' SC_MOD_CHANGELINESTATE notification.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetLineState (BYVAL hSci AS DWORD, BYVAL nLine AS LONG, BYVAL nValue AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETLINESTATE, nLine, nValue)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetLineState (BYVAL pSci AS DWORD, BYVAL nLine AS LONG, BYVAL nValue AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETLINESTATE, nLine, nValue)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetLineState (BYVAL hSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETLINESTATE, nLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetLineState (BYVAL pSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETLINESTATE, nLine, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETMAXLINESTATE
' This returns the last line that has any line state.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetMaxLineState (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETMAXLINESTATE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetMaxLineState (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETMAXLINESTATE, 0, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                    Style definition
' ########################################################################################

' ========================================================================================
' SCI_STYLERESETDEFAULT
' This message resets STYLE_DEFAULT to its state when Scintilla was initialised.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_StyleResetDefault (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLERESETDEFAULT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleResetDefault (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLERESETDEFAULT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_STYLECLEARALL
' This message sets all styles to have the same attributes as STYLE_DEFAULT. If you are
' setting up Scintilla for syntax colouring, it is likely that the lexical styles you set
' will be very similar. One way to set the styles is to:
' 1. Set STYLE_DEFAULT to the common features of all styles.
' 2. Use SCI_STYLECLEARALL to copy this to all styles.
' 3. Set the style attributes that make your lexical styles different.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_StyleClearAll (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLECLEARALL, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleClearAll (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLECLEARALL, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_STYLESETFONT(int styleNumber, const char *fontName)
' SCI_STYLEGETFONT(int styleNumber, char *fontName)
' SCI_STYLESETSIZE(int styleNumber, int sizeInPoints)
' SCI_STYLEGETSIZE(int styleNumber)
' SCI_STYLESETSIZEFRACTIONAL(int styleNumber, int sizeInHundredthPoints)
' SCI_STYLEGETSIZEFRACTIONAL(int styleNumber)
' SCI_STYLESETBOLD(int styleNumber, bool bold)
' SCI_STYLEGETBOLD(int styleNumber)
' SCI_STYLESETWEIGHT(int styleNumber, int weight)
' SCI_STYLEGETWEIGHT(int styleNumber)
' SCI_STYLESETITALIC(int styleNumber, bool italic)
' SCI_STYLEGETITALIC(int styleNumber)
' These messages (plus SCI_STYLESETCHARACTERSET) set the font attributes that are used to
' match the fonts you request to those available. The fontName is a zero terminated string
' holding the name of a font. Under Windows, only the first 32 characters of the name are
' used and the name is not case sensitive. For internal caching, Scintilla tracks fonts by
' name and does care about the casing of font names, so please be consistent.
' ========================================================================================

' ========================================================================================
FUNCTION SCI_StyleSetFont (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL strFontName AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLESETFONT, styleNumber, STRPTR(strFontName))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleSetFont (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL strFontName AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLESETFONT, styleNumber, STRPTR(strFontName))
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_StyleGetFont (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = SendMessageA(hSci, %SCI_STYLEGETFONT, styleNumber, 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen + 1)
   SendMessageA(hSci, %SCI_STYLEGETFONT, styleNumber, STRPTR(buffer))
   FUNCTION = REMOVE$(buffer, CHR$(0))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleGetFont (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = Scintilla_DirectFunction(pSci, %SCI_STYLEGETFONT, styleNumber, 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen + 1)
   Scintilla_DirectFunction(pSci, %SCI_STYLEGETFONT, styleNumber, STRPTR(buffer))
   FUNCTION = REMOVE$(buffer, CHR$(0))
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_StyleSetSize (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL sizeInPoints AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLESETSIZE, styleNumber, sizeInPoints)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleSetSize (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL sizeInPoints AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLESETSIZE, styleNumber, sizeInPoints)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_StyleGetSize (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLEGETSIZE, styleNumber, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleGetSize (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLEGETSIZE, styleNumber, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_StyleSetSizeFractional (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL sizeInHundredthPoints AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLESETSIZEFRACTIONAL, styleNumber, sizeInHundredthPoints)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleSetSizeFractional (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL sizeInHundredthPoints AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLESETSIZEFRACTIONAL, styleNumber, sizeInHundredthPoints)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_StyleGetSizeFractional (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLEGETSIZEFRACTIONAL, styleNumber, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleGetSizeFractional (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLEGETSIZEFRACTIONAL, styleNumber, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_StyleSetBold (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL bBold AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLESETBOLD, styleNumber, bBold)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleSetBold (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL bBold AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLESETBOLD, styleNumber, bBold)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_StyleGetBold (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLEGETBOLD, styleNumber, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleGetBold (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLEGETBOLD, styleNumber, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_StyleSetWeight (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL weight AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLESETBOLD, styleNumber, weight)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleSetWeight (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL weight AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLESETBOLD, styleNumber, weight)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_StyleGetWeight (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLEGETWEIGHT, styleNumber, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleGetWeight (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLEGETWEIGHT, styleNumber, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_StyleSetItalic (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL bItalic AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLESETITALIC, styleNumber, bItalic)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleSetItalic (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL bItalic AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLESETITALIC, styleNumber, bItalic)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_StyleGetItalic (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLEGETITALIC, styleNumber, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleGetItalic (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLEGETITALIC, styleNumber, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_STYLESETUNDERLINE(int styleNumber, bool underline)
' SCI_STYLEGETUNDERLINE(int styleNumber)
' You can set a style to be underlined. The underline is drawn in the foreground colour.
' All characters with a style that includes the underline attribute are underlined, even
' if they are white space.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_StyleSetUnderline (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL bUnderline AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLESETUNDERLINE, styleNumber, bUnderline)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleSetUnderline (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL bUnderline AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLESETUNDERLINE, styleNumber, bUnderline)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_StyleGetUnderline (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLEGETUNDERLINE, styleNumber, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleGetUnderline (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLEGETUNDERLINE, styleNumber, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_STYLESETFORE(int styleNumber, int colour)
' SCI_STYLEGETFORE(int styleNumber)
' SCI_STYLESETBACK(int styleNumber, int colour)
' SCI_STYLEGETBACK(int styleNumber)
' Text is drawn in the foreground colour. The space in each character cell that is not
' occupied by the character is drawn in the background colour.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_StyleSetFore (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL colour AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLESETFORE, styleNumber, colour)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleSetFore (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL colour AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLESETFORE, styleNumber, colour)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_StyleGetFore (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLEGETFORE, styleNumber, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleGetFore (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLEGETFORE, styleNumber, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_StyleSetBack (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL colour AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLESETBACK, styleNumber, colour)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleSetBack (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL colour AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLESETBACK, styleNumber, colour)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_StyleGetBack (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLEGETBACK, styleNumber, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleGetBack (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLEGETBACK, styleNumber, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_STYLESETEOLFILLED(int styleNumber, bool eolFilled)
' SCI_STYLEGETEOLFILLED(int styleNumber)
' If the last character in the line has a style with this attribute set, the remainder of
' the line up to the right edge of the window is filled with the background colour set for
' the last character. This is useful when a document contains embedded sections in another
' language such as HTML pages with embedded JavaScript. By setting eolFilled to true and a
' consistent background colour (different from the background colour set for the HTML styles)
' to all JavaScript styles then JavaScript sections will be easily distinguished from HTML.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_StyleSetEOLFilled (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL eolFilled AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLESETEOLFILLED, styleNumber, eolFilled)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleSetEOLFilled (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL eolFilled AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLESETEOLFILLED, styleNumber, eolFilled)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_StyleGetEOLFilled (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLEGETEOLFILLED, styleNumber, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleGetEOLFilled (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLEGETEOLFILLED, styleNumber, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_STYLESETCHARACTERSET(int styleNumber, int charSet)
' SCI_STYLEGETCHARACTERSET(int styleNumber)
' You can set a style to use a different character set than the default. The places where
' such characters sets are likely to be useful are comments and literal strings. For
' example, SCI_STYLESETCHARACTERSET(SCE_C_STRING, SC_CHARSET_RUSSIAN) would ensure that
' strings in Russian would display correctly in C and C++ (SCE_C_STRING is the style number
' used by the C and C++ lexer to display literal strings; it has the value 6).
' The character sets supported on Windows are:
' SC_CHARSET_ANSI, SC_CHARSET_ARABIC, SC_CHARSET_BALTIC, SC_CHARSET_CHINESEBIG5,
' SC_CHARSET_DEFAULT, SC_CHARSET_EASTEUROPE, SC_CHARSET_GB2312, SC_CHARSET_GREEK,
' SC_CHARSET_HANGUL, SC_CHARSET_HEBREW, SC_CHARSET_JOHAB, SC_CHARSET_MAC, SC_CHARSET_OEM,
' SC_CHARSET_RUSSIAN (code page 1251), SC_CHARSET_SHIFTJIS, SC_CHARSET_SYMBOL,
' SC_CHARSET_THAI, SC_CHARSET_TURKISH, and SC_CHARSET_VIETNAMESE.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_StyleSetCharacterSet (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL charSet AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLESETCHARACTERSET, styleNumber, charSet)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleSetCharacterSet (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL charSet AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLESETCHARACTERSET, styleNumber, charSet)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_StyleGetCharacterSet (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLEGETCHARACTERSET, styleNumber, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleGetCharacterSet (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLEGETCHARACTERSET, styleNumber, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_STYLESETCASE(int styleNumber, int caseMode)
' SCI_STYLEGETCASE(int styleNumber)
' The value of caseMode determines how text is displayed. You can set upper case
' (SC_CASE_UPPER, 1) or lower case (SC_CASE_LOWER, 2) or display normally (SC_CASE_MIXED, 0).
' This does not change the stored text, only how it is displayed.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_StyleSetCase (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL caseMode AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLESETCASE, styleNumber, caseMode)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleSetCase (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL caseMode AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLESETCASE, styleNumber, caseMode)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_StyleGetCase (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLEGETCASE, styleNumber, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleGetCase (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLEGETCASE, styleNumber, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_STYLESETVISIBLE(int styleNumber, bool visible)
' SCI_STYLEGETVISIBLE(int styleNumber)
' Text is normally visible. However, you can completely hide it by giving it a style with
' the visible set to 0. This could be used to hide embedded formatting instructions or
' hypertext keywords in HTML or XML.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_StyleSetVisible (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL bVisible AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLESETVISIBLE, styleNumber, bVisible)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleSetVisible (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL bVisible AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLESETVISIBLE, styleNumber, bVisible)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_StyleGetVisible (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLEGETVISIBLE, styleNumber, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleGetVisible (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLEGETVISIBLE, styleNumber, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_STYLESETCHANGEABLE(int styleNumber, bool changeable)
' SCI_STYLEGETCHANGEABLE(int styleNumber)
' This is an experimental and incompletely implemented style attribute. The default setting
' is changeable set true but when set false it makes text read-only. Currently it only
' stops the caret from being within not-changeable text and does not yet stop deleting a
' range that contains not-changeable text.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_StyleSetChangeable (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL bChangeable AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLESETCHANGEABLE, styleNumber, bChangeable)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleSetChangeable (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL bChangeable AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLESETCHANGEABLE, styleNumber, bChangeable)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_StyleGetChangeable (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLEGETCHANGEABLE, styleNumber, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleGetChangeable (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLEGETCHANGEABLE, styleNumber, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_STYLESETHOTSPOT(int styleNumber, bool hotspot)
' SCI_STYLEGETHOTSPOT(int styleNumber)
' This style is used to mark ranges of text that can detect mouse clicks. The cursor
' changes to a hand over hotspots, and the foreground, and background colours may change
' and an underline appear to indicate that these areas are sensitive to clicking. This may
' be used to allow hyperlinks to other documents.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_StyleSetHotSpot (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL bHotSpot AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLESETHOTSPOT, styleNumber, bHotSpot)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleSetHotSpot (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG, BYVAL bHotSpot AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLESETHOTSPOT, styleNumber, bHotSpot)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_StyleGetHotSpot (BYVAL hSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STYLEGETHOTSPOT, styleNumber, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StyleGetHotSpot (BYVAL pSci AS DWORD, BYVAL styleNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STYLEGETHOTSPOT, styleNumber, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                         Caret, selection, and hotspot styles
' ########################################################################################

' ========================================================================================
' The selection is shown by changing the foreground and/or background colours. If one of
' these is not set then that attribute is not changed for the selection. The default is to
' show the selection by changing the background to light gray and leaving the foreground
' the same as when it was not selected. When there is no selection, the current insertion
' point is marked by the text caret. This is a vertical line that is normally blinking on
' and off to attract the users attention.
' ========================================================================================

' ========================================================================================
' SCI_SETSELFORE(bool useSelectionForeColour, int colour)
' SCI_SETSELBACK(bool useSelectionBackColour, int colour)
' You can choose to override the default selection colouring with these two messages. The
' colour you provide is used if you set useSelection*Colour to true. If it is set to false,
' the default styled colouring is used and the colour argument has no effect.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetSelFore (BYVAL hSci AS DWORD, BYVAL useSelectionForeColour AS BYTE, BYVAL colour AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETSELFORE, useSelectionForeColour, colour)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetSelFore (BYVAL pSci AS DWORD, BYVAL useSelectionForeColour AS BYTE, BYVAL colour AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETSELFORE, useSelectionForeColour, colour)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetSelBack (BYVAL hSci AS DWORD, BYVAL useSelectionBackColour AS BYTE, BYVAL colour AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETSELBACK, useSelectionBackColour, colour)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetSelBack (BYVAL pSci AS DWORD, BYVAL useSelectionBackColour AS BYTE, BYVAL colour AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETSELBACK, useSelectionBackColour, colour)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETSELALPHA(int alpha)
' SCI_GETSELALPHA
' The selection can be drawn translucently in the selection background colour by setting
' an alpha value.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetSelAlpha (BYVAL hSci AS DWORD, BYVAL alpha AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETSELALPHA, alpha, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetSelAlpha (BYVAL pSci AS DWORD, BYVAL alpha AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETSELALPHA, alpha, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetSelAlpha (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETSELALPHA, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetSelAlpha (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETSELALPHA, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETSELEOLFILLED(bool filled)
' SCI_GETSELEOLFILLED
' The selection can be drawn up to the right hand border by setting this property.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetSelEOLFilled (BYVAL hSci AS DWORD, BYVAL filled AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETSELEOLFILLED, filled, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetSelEOLFilled (BYVAL pSci AS DWORD, BYVAL filled AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETSELEOLFILLED, filled, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetSelEOLFilled (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETSELEOLFILLED, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetSelEOLFilled (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETSELEOLFILLED, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETCARETFORE(int colour)
' SCI_GETCARETFORE
' The colour of the caret can be set with SCI_SETCARETFORE and retrieved with SCI_GETCARETFORE.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetCaretFore (BYVAL hSci AS DWORD, BYVAL colour AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETCARETFORE, colour, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetCaretFore (BYVAL pSci AS DWORD, BYVAL colour AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETCARETFORE, colour, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetCaretFore (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETCARETFORE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetCaretFore (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETCARETFORE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETCARETLINEVISIBLE(bool show)
' SCI_GETCARETLINEVISIBLE
' SCI_SETCARETLINEBACK(int colour)
' SCI_GETCARETLINEBACK
' SCI_SETCARETLINEBACKALPHA(int alpha)
' SCI_GETCARETLINEBACKALPHA
' You can choose to make the background colour of the line containing the caret different
' with these messages. To do this, set the desired background colour with
' SCI_SETCARETLINEBACK, then use SCI_SETCARETLINEVISIBLE(true) to enable the effect.
' You can cancel the effect with SCI_SETCARETLINEVISIBLE(false). The two SCI_GETCARET*
' functions return the state and the colour. This form of background colouring has highest
' priority when a line has markers that would otherwise change the background colour. The
' caret line may also be drawn translucently which allows other background colours to show
' through. This is done by setting the alpha (translucency) value by calling
' SCI_SETCARETLINEBACKALPHA. When the alpha is not SC_ALPHA_NOALPHA, the caret line is
' drawn after all other features so will affect the colour of all other features.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetCaretLineVisible (BYVAL hSci AS DWORD, BYVAL bShow AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETCARETLINEVISIBLE, bShow, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetCaretLineVisible (BYVAL pSci AS DWORD, BYVAL bShow AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETCARETLINEVISIBLE, bShow, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetCaretLineVisible (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETCARETLINEVISIBLE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetCaretLineVisible (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETCARETLINEVISIBLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_SetCaretLineBack (BYVAL hSci AS DWORD, BYVAL colour AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETCARETLINEBACK, colour, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetCaretLineBack (BYVAL pSci AS DWORD, BYVAL colour AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETCARETLINEBACK, colour, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetCaretLineBack (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETCARETLINEBACK, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetCaretLineBack (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETCARETLINEBACK, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_SetCaretLineBackAlpha (BYVAL hSci AS DWORD, BYVAL alpha AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETCARETLINEBACKALPHA, alpha, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetCaretLineBackAlpha (BYVAL pSci AS DWORD, BYVAL alpha AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETCARETLINEBACKALPHA, alpha, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetCaretLineBackAlpha (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETCARETLINEBACKALPHA, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetCaretLineBackAlpha (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETCARETLINEBACKALPHA, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETCARETLINEVISIBLEALWAYS(bool alwaysVisible)
' SCI_GETCARETLINEVISIBLEALWAYS
' Choose to make the caret line always visible even when the window is not in focus.
' Default behaviour SCI_SETCARETLINEVISIBLEALWAYS(false) the caret line is only visible
' when the window is in focus.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetCaretLineVisibleAlways (BYVAL hSci AS DWORD, BYVAL alwaysVisible AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETCARETLINEVISIBLEALWAYS, alwaysVisible, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetCaretLineVisibleAlways (BYVAL pSci AS DWORD, BYVAL alwaysVisible AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETCARETLINEVISIBLEALWAYS, alwaysVisible, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetCaretLineVisibleAlways (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETCARETLINEVISIBLEALWAYS, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetCaretLineVisibleAlways (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETCARETLINEVISIBLEALWAYS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETCARETPERIOD(int milliseconds)
' SCI_GETCARETPERIOD
' The rate at which the caret blinks can be set with SCI_SETCARETPERIOD which determines
' the time in milliseconds that the caret is visible or invisible before changing state.
' Setting the period to 0 stops the caret blinking. The default value is 500 milliseconds.
' SCI_GETCARETPERIOD returns the current setting.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetCaretPeriod (BYVAL hSci AS DWORD, BYVAL milliseconds AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETCARETPERIOD, milliseconds, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetCaretPeriod (BYVAL pSci AS DWORD, BYVAL milliseconds AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETCARETPERIOD, milliseconds, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetCaretPeriod (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETCARETPERIOD, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetCaretPeriod (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETCARETPERIOD, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETCARETSTYLE(int style)
' SCI_GETCARETSTYLE
' The style of the caret can be set with SCI_SETCARETSTYLE to be a line caret (CARETSTYLE_LINE=1),
' a block caret (CARETSTYLE_BLOCK=2) or to not draw at all (CARETSTYLE_INVISIBLE=0). The
' default value is the line caret (CARETSTYLE_LINE=1). You can determine the current caret
' style setting using SCI_GETCARETSTYLE.
' The block character draws most combining and multibyte character sequences successfully,
' though some fonts like Thai Fonts (and possibly others) can sometimes appear strange when
' the cursor is positioned at these characters, which may result in only drawing a part of
' the cursor character sequence. This is most notable on Windows platforms.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetCaretStyle (BYVAL hSci AS DWORD, BYVAL nStyle AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETCARETSTYLE, nStyle, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetCaretStyle (BYVAL pSci AS DWORD, BYVAL nStyle AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETCARETSTYLE, nStyle, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetCaretStyle (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETCARETSTYLE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetCaretStyle (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETCARETSTYLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETCARETWIDTH(int pixels)
' SCI_GETCARETWIDTH
' The width of the line caret can be set with SCI_SETCARETWIDTH to a value of 0, 1, 2 or
' 3 pixels. The default width is 1 pixel. You can read back the current width with
' SCI_GETCARETWIDTH. A width of 0 makes the caret invisible (added at version 1.50),
' similar to setting the caret style to CARETSTYLE_INVISIBLE (though not interchangable).
' This setting only affects the width of the cursor when the cursor style is set to line
' caret mode, it does not affect the width for a block caret.
' ========================================================================================

' ========================================================================================
FUNCTION SCI_SetCaretWidth (BYVAL hSci AS DWORD, BYVAL nPixels AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETCARETWIDTH, nPixels, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetCaretWidth (BYVAL pSci AS DWORD, BYVAL nPixels AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETCARETWIDTH, nPixels, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetCaretWidth (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETCARETWIDTH, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetCaretWidth (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETCARETWIDTH, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETHOTSPOTACTIVEFORE(bool useHotSpotForeColour, int colour)
' SCI_GETHOTSPOTACTIVEFORE
' SCI_SETHOTSPOTACTIVEBACK(bool useHotSpotBackColour, int colour)
' SCI_GETHOTSPOTACTIVEBACK
' SCI_SETHOTSPOTACTIVEUNDERLINE(bool underline)
' SCI_GETHOTSPOTACTIVEUNDERLINE
' SCI_SETHOTSPOTSINGLELINE(bool singleLine)
' SCI_GETHOTSPOTSINGLELINE
' While the cursor hovers over text in a style with the hotspot attribute set, the default
' colouring can be modified and an underline drawn with these settings. Single line mode
' stops a hotspot from wrapping onto next line.
' ========================================================================================

' ========================================================================================
FUNCTION SCI_SetHotSpotActiveFore (BYVAL hSci AS DWORD, BYVAL useHotSpotForeColour AS BYTE, BYVAL colour AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETHOTSPOTACTIVEFORE, useHotSpotForeColour, colour)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetHotSpotActiveFore (BYVAL pSci AS DWORD, BYVAL useHotSpotForeColour AS BYTE, BYVAL colour AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETHOTSPOTACTIVEFORE, useHotSpotForeColour, colour)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetHotSpotActiveFore (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETHOTSPOTACTIVEFORE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetHotSpotActiveFore (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETHOTSPOTACTIVEFORE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_SetHotSpotActiveBack (BYVAL hSci AS DWORD, BYVAL useHotSpotBackColour AS BYTE, BYVAL colour AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETHOTSPOTACTIVEBACK, useHotSpotBackColour, colour)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetHotSpotActiveBack (BYVAL pSci AS DWORD, BYVAL useHotSpotBackColour AS BYTE, BYVAL colour AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETHOTSPOTACTIVEBACK, useHotSpotBackColour, colour)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetHotSpotActiveBack (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETHOTSPOTACTIVEBACK, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetHotSpotActiveBack (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETHOTSPOTACTIVEBACK, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_SetHotSpotActiveUnderline (BYVAL hSci AS DWORD, BYVAL underline AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETHOTSPOTACTIVEUNDERLINE, underline, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetHotSpotActiveUnderline (BYVAL pSci AS DWORD, BYVAL underline AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETHOTSPOTACTIVEUNDERLINE, underline, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetHotSpotActiveUnderline (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETHOTSPOTACTIVEUNDERLINE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetHotSpotActiveUnderline (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETHOTSPOTACTIVEUNDERLINE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_SetHotSpotSingleLine (BYVAL hSci AS DWORD, BYVAL singleLine AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETHOTSPOTSINGLELINE, singleLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetHotSpotSingleLine (BYVAL pSci AS DWORD, BYVAL singleLine AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETHOTSPOTSINGLELINE, singleLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetHotSpotSingleLine (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETHOTSPOTSINGLELINE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetHotSpotSingleLine (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETHOTSPOTSINGLELINE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETCONTROLCHARSYMBOL(int symbol)
' SCI_GETCONTROLCHARSYMBOL
' By default, Scintilla displays control characters (characters with codes less than 32)
' in a rounded rectangle as ASCII mnemonics: "NUL", "SOH", "STX", "ETX", "EOT", "ENQ",
' "ACK", "BEL", "BS", "HT", "LF", "VT", "FF", "CR", "SO", "SI", "DLE", "DC1", "DC2", "DC3",
' "DC4", "NAK", "SYN", "ETB", "CAN", "EM", "SUB", "ESC", "FS", "GS", "RS", "US". These
' mnemonics come from the early days of signaling, though some are still used (LF = Line
' Feed, BS = Back Space, CR = Carriage Return, for example).
' You can choose to replace these mnemonics by a nominated symbol with an ASCII code in
' the range 32 to 255. If you set a symbol value less than 32, all control characters are
' displayed as mnemonics. The symbol you set is rendered in the font of the style set for
' the character. You can read back the current symbol with the SCI_GETCONTROLCHARSYMBOL
' message. The default symbol value is 0.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetControlCharSymbol (BYVAL hSci AS DWORD, BYVAL symbol AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETCONTROLCHARSYMBOL, symbol, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetControlCharSymbol (BYVAL pSci AS DWORD, BYVAL symbol AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETCONTROLCHARSYMBOL, symbol, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetControlCharSymbol (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETCONTROLCHARSYMBOL, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetControlCharSymbol (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETCONTROLCHARSYMBOL, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETREPRESENTATION(const char *encodedCharacter, const char *representation)
' SCI_GETREPRESENTATION(const char *encodedCharacter, char *representation)
' SCI_CLEARREPRESENTATION(const char *encodedCharacter)
' Any character, including those normally displayed as mnemonics may be represented by a
' string inverted in a rounded rectangle.
' For example, the Ohm sign ? U+2126 looks very similar to the Greek Omega character
' O U+03C9 so, for the UTF-8 encoding, to distinguish the Ohm sign as "U+2126 ?" this call
' could be made: SCI_SETREPRESENTATION("\xe2\x84\xa6", "U+2126 \xe2\x84\xa6")
' The encodedCharacter parameter is a NUL-terminated string of the bytes for one character
' in the current encoding. This can not be used to set a representation for
' multiple-character strings.
' The NUL (0) character is a special case since the encodedCharacter parameter is NUL
' terminated, the NUL character is specified as an empty string.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetRepresentation (BYVAL hSci AS DWORD, BYREF encodedCharacter AS ASCIIZ, BYREF representation AS ASCIIZ) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETREPRESENTATION, VARPTR(encodedCharacter), VARPTR(representation))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetRepresentation (BYVAL pSci AS DWORD, BYREF encodedCharacter AS ASCIIZ, BYREF representation AS ASCIIZ) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETREPRESENTATION, VARPTR(encodedCharacter), VARPTR(representation))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetRepresentation (BYVAL hSci AS DWORD, BYREF encodedCharacter AS ASCIIZ, BYREF representation AS ASCIIZ) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETREPRESENTATION, VARPTR(encodedCharacter), VARPTR(representation))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetRepresentation (BYVAL pSci AS DWORD, BYREF encodedCharacter AS ASCIIZ, BYREF representation AS ASCIIZ) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETREPRESENTATION, VARPTR(encodedCharacter), VARPTR(representation))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_ClearRepresentation (BYVAL hSci AS DWORD, BYREF encodedCharacter AS ASCIIZ) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CLEARREPRESENTATION, VARPTR(encodedCharacter), 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ClearRepresentation (BYVAL pSci AS DWORD, BYREF encodedCharacter AS ASCIIZ) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CLEARREPRESENTATION, VARPTR(encodedCharacter), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETCARETSTICKY(int useCaretStickyBehaviour)
' SCI_GETCARETSTICKY
' SCI_TOGGLECARETSTICKY
' These messages set, get or toggle the caretSticky setting which controls when the last
' position of the caret on the line is saved.
' When set to SC_CARETSTICKY_OFF (0), the sticky flag is off; all text changes (and all
' caret position changes) will remember the caret's new horizontal position when moving to
' different lines. This is the default.
' When set to SC_CARETSTICKY_ON (1), the sticky flag is on, and the only thing which will
' cause the editor to remember the horizontal caret position is moving the caret with mouse
' or keyboard (left/right arrow keys, home/end keys, etc).
' When set to SC_CARETSTICKY_WHITESPACE (2), the caret acts like mode 0 (sticky off) except
' under one special case; when space or tab characters are inserted. (Including pasting
' only space/tabs -- undo, redo, etc. do not exhibit this behavior..).
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetCaretSticky (BYVAL hSci AS DWORD, BYVAL useCaretStickyBehaviour AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETCARETSTICKY, useCaretStickyBehaviour, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetCaretSticky (BYVAL pSci AS DWORD, BYVAL useCaretStickyBehaviour AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETCARETSTICKY, useCaretStickyBehaviour, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetCaretSticky (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETCARETSTICKY, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetCaretSticky (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETCARETSTICKY, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_TOGGLECARETSTICKY switches from SC_CARETSTICKY_ON and SC_CARETSTICKY_WHITESPACE to
' SC_CARETSTICKY_OFF and from SC_CARETSTICKY_OFF to SC_CARETSTICKY_ON.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_ToggleCaretSticky (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_TOGGLECARETSTICKY, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ToggleCaretSticky (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_TOGGLECARETSTICKY, 0, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                          Margins
' ########################################################################################

' ========================================================================================
' SCI_SETMARGINTYPEN(int margin, int iType)
' SCI_GETMARGINTYPEN(int margin)
' These two routines set and get the type of a margin. The margin argument should be 0, 1,
' 2, 3 or 4. You can use the predefined constants SC_MARGIN_SYMBOL (0) and SC_MARGIN_NUMBER
' (1) to set a margin as either a line number or a symbol margin. A margin with application
' defined text may use SC_MARGIN_TEXT (4) or SC_MARGIN_RTEXT (5) to right justify the text.
' By convention, margin 0 is used for line numbers and the next two are used for symbols.
' You can also use the constants SC_MARGIN_BACK (2) and SC_MARGIN_FORE (3) for symbol
' margins that set their background colour to match the STYLE_DEFAULT background and
' foreground colours.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetMarginTypeN (BYVAL hSci AS DWORD, BYVAL nMargin AS LONG, BYVAL nType AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETMARGINTYPEN, nMargin, nType)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetMarginTypeN (BYVAL pSci AS DWORD, BYVAL nMargin AS LONG, BYVAL nType AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETMARGINTYPEN, nMargin, nType)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetMarginTypeN (BYVAL hSci AS DWORD, BYVAL nMargin AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETMARGINTYPEN, nMargin, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetMarginTypeN (BYVAL pSci AS DWORD, BYVAL nMargin AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETMARGINTYPEN, nMargin, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETMARGINWIDTHN(int margin, int pixelWidth)
' SCI_GETMARGINWIDTHN(int margin)
' These routines set and get the width of a margin in pixels. A margin with zero width is
' invisible. By default, Scintilla sets margin 1 for symbols with a width of 16 pixels, so
' this is a reasonable guess if you are not sure what would be appropriate. Line number
' margins widths should take into account the number of lines in the document and the line
' number style. You could use something like SCI_TEXTWIDTH(STYLE_LINENUMBER, "_99999") to
' get a suitable width.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetMarginWidthN (BYVAL hSci AS DWORD, BYVAL nMargin AS LONG, BYVAL pixelWidth AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETMARGINWIDTHN, nMargin, pixelWidth)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetMarginWidthN (BYVAL pSci AS DWORD, BYVAL nMargin AS LONG, BYVAL pixelWidth AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETMARGINWIDTHN, nMargin, pixelWidth)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetMarginWidthN (BYVAL hSci AS DWORD, BYVAL nMargin AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETMARGINWIDTHN, nMargin, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetMarginWidthN (BYVAL pSci AS DWORD, BYVAL nMargin AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETMARGINWIDTHN, nMargin, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETMARGINMASKN(int margin, int mask)
' SCI_GETMARGINMASKN(int margin)
' The mask is a 32-bit value. Each bit corresponds to one of 32 logical symbols that can
' be displayed in a margin that is enabled for symbols. There is a useful constant,
' SC_MASK_FOLDERS (0xFE000000 or -33554432), that is a mask for the 7 logical symbols used
' to denote folding. You can assign a wide range of symbols and colours to each of the 32
' logical symbols, see Markers for more information. If (mask & SC_MASK_FOLDERS)==0, the
' margin background colour is controlled by style 33 (STYLE_LINENUMBER).
' You add logical markers to a line with SCI_MARKERADD. If a line has an associated marker
' that does not appear in the mask of any margin with a non-zero width, the marker changes
' the background colour of the line. For example, suppose you decide to use logical marker
' 10 to mark lines with a syntax error and you want to show such lines by changing the
' background colour. The mask for this marker is 1 shifted left 10 times (1<<10) which is
' 0x400. If you make sure that no symbol margin includes 0x400 in its mask, any line with
' the marker gets the background colour changed.
' To set a non-folding margin 1 use SCI_SETMARGINMASKN(1, ~SC_MASK_FOLDERS) which is the
' default set by Scintilla. To set a folding margin 2 use SCI_SETMARGINMASKN(2, SC_MASK_FOLDERS).
' ~SC_MASK_FOLDERS is 0x1FFFFFF in hexadecimal or 33554431 decimal. Of course, you may need
' to display all 32 symbols in a margin, in which case use SCI_SETMARGINMASKN(margin, -1).
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetMarginMaskN (BYVAL hSci AS DWORD, BYVAL nMargin AS LONG, BYVAL mask AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETMARGINMASKN, nMargin, mask)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetMarginMaskN (BYVAL pSci AS DWORD, BYVAL nMargin AS LONG, BYVAL mask AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETMARGINMASKN, nMargin, mask)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetMarginMaskN (BYVAL hSci AS DWORD, BYVAL nMargin AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETMARGINMASKN, nMargin, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetMarginMaskN (BYVAL pSci AS DWORD, BYVAL nMargin AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETMARGINMASKN, nMargin, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETMARGINSENSITIVEN(int margin, bool sensitive)
' SCI_GETMARGINSENSITIVEN(int margin)
' Each of the five margins can be set sensitive or insensitive to mouse clicks. A click in
' a sensitive margin sends a SCN_MARGINCLICK notification to the container. Margins that
' are not sensitive act as selection margins which make it easy to select ranges of lines.
' By default, all margins are insensitive.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetMarginSensitiveN (BYVAL hSci AS DWORD, BYVAL nMargin AS LONG, BYVAL bSensitive AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETMARGINSENSITIVEN, nMargin, bSensitive)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetMarginSensitiveN (BYVAL pSci AS DWORD, BYVAL nMargin AS LONG, BYVAL bSensitive AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETMARGINSENSITIVEN, nMargin, bSensitive)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetMarginSensitiveN (BYVAL hSci AS DWORD, BYVAL nMargin AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETMARGINSENSITIVEN, nMargin, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetMarginSensitiveN (BYVAL pSci AS DWORD, BYVAL nMargin AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETMARGINSENSITIVEN, nMargin, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETMARGINCURSORN(int margin, int cursor)
' SCI_GETMARGINCURSORN(int margin)
' A reversed arrow cursor is normally shown over all margins. This may be changed to a
' normal arrow with SCI_SETMARGINCURSORN(margin, SC_CURSORARROW) or restored to a reversed
' arrow with SCI_SETMARGINCURSORN(margin, SC_CURSORREVERSEARROW).
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetMarginCursorN (BYVAL hSci AS DWORD, BYVAL nMargin AS LONG, BYVAL nCursor AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETMARGINCURSORN, nMargin, nCursor)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetMarginCursorN (BYVAL pSci AS DWORD, BYVAL nMargin AS LONG, BYVAL nCursor AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETMARGINCURSORN, nMargin, nCursor)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetMarginCursorN (BYVAL hSci AS DWORD, BYVAL nMargin AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETMARGINCURSORN, nMargin, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetMarginCursorN (BYVAL pSci AS DWORD, BYVAL nMargin AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETMARGINCURSORN, nMargin, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETMARGINLEFT(<unused>, int pixels)
' SCI_GETMARGINLEFT
' SCI_SETMARGINRIGHT(<unused>, int pixels)
' SCI_GETMARGINRIGHT
' These messages set and get the width of the blank margin on both sides of the text in
' pixels. The default is to one pixel on each side.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetMarginLeft (BYVAL hSci AS DWORD, BYVAL nPixels AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETMARGINLEFT, 0, nPixels)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetMarginLeft (BYVAL pSci AS DWORD, BYVAL nPixels AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETMARGINLEFT, 0, nPixels)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetMarginLeft (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETMARGINSENSITIVEN, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetMarginLeft (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETMARGINSENSITIVEN, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_SetMarginRight (BYVAL hSci AS DWORD, BYVAL nPixels AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETMARGINRIGHT, 0, nPixels)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetMarginRight (BYVAL pSci AS DWORD, BYVAL nPixels AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETMARGINRIGHT, 0, nPixels)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetMarginRight (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETMARGINRIGHT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetMarginRight (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETMARGINRIGHT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETFOLDMARGINCOLOUR(bool useSetting, int colour)
' SCI_SETFOLDMARGINHICOLOUR(bool useSetting, int colour)
' These messages allow changing the colour of the fold margin and fold margin highlight.
' On Windows the fold margin colour defaults to ::GetSysColor(COLOR_3DFACE) and the fold
' margin highlight colour to ::GetSysColor(COLOR_3DHIGHLIGHT).
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetFoldMarginColour (BYVAL hSci AS DWORD, BYVAL useSetting AS BYTE, BYVAL colour AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETFOLDMARGINCOLOUR, useSetting, colour)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetFoldMarginColour (BYVAL pSci AS DWORD, BYVAL useSetting AS BYTE, BYVAL colour AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETFOLDMARGINCOLOUR, useSetting, colour)
END FUNCTION
' ========================================================================================

MACRO SCI_SetFoldMarginColor = SCI_SetFoldMarginColour
MACRO SCIP_SetFoldMarginColor = SCIP_SetFoldMarginColour

' ========================================================================================
FUNCTION SCI_SetFoldMarginHiColour (BYVAL hSci AS DWORD, BYVAL useSetting AS BYTE, BYVAL colour AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETFOLDMARGINHICOLOUR, useSetting, colour)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetFoldMarginHiColour (BYVAL pSci AS DWORD, BYVAL useSetting AS BYTE, BYVAL colour AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETFOLDMARGINHICOLOUR, useSetting, colour)
END FUNCTION
' ========================================================================================

MACRO SCI_SetFoldMarginHiColor = SCI_SetFoldMarginHiColour
MACRO SCIP_SetFoldMarginHiColor = SCIP_SetFoldMarginHiColour

' ========================================================================================
' SCI_MARGINSETTEXT(int line, char *text)
' SCI_MARGINGETTEXT(int line, char *text)
' SCI_MARGINSETSTYLE(int line, int style)
' SCI_MARGINGETSTYLE(int line)
' SCI_MARGINSETSTYLES(int line, char *styles)
' SCI_MARGINGETSTYLES(int line, char *styles)
' SCI_MARGINTEXTCLEARALL
' Text margins are created with the type SC_MARGIN_TEXT or SC_MARGIN_RTEXT. A different
' string may be set for each line with SCI_MARGINSETTEXT. The whole of the text margin on
' a line may be displayed in a particular style with SCI_MARGINSETSTYLE or each character
' may be individually styled with SCI_MARGINSETSTYLES which uses an array of bytes with
' each byte setting the style of the corresponding text byte similar to SCI_SETSTYLINGEX.
' Setting a text margin will cause a SC_MOD_CHANGEMARGIN notification to be sent.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_MarginSetText (BYVAL hSci AS DWORD, BYVAL nLine AS LONG, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_MARGINSETTEXT, nLine, STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MarginSetText (BYVAL pSci AS DWORD, BYVAL nLine AS LONG, BYVAL strText AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_MARGINSETTEXT, nLine, STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_MarginGetText (BYVAL hSci AS DWORD, BYVAL nType AS LONG) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = SendMessageA(hSci, %SCI_MARGINGETTEXT, nType, 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen + 1)
   SendMessageA(hSci, %SCI_MARGINGETTEXT, nType, STRPTR(buffer))
   FUNCTION = REMOVE$(buffer, CHR$(0))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MarginGetText (BYVAL pSci AS DWORD, BYVAL nType AS LONG) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = Scintilla_DirectFunction(pSci, %SCI_MARGINGETTEXT, nType, 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen + 1)
   Scintilla_DirectFunction(pSci, %SCI_MARGINGETTEXT, nType, STRPTR(buffer))
   FUNCTION = REMOVE$(buffer, CHR$(0))
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_MarginSetStyle (BYVAL hSci AS DWORD, BYVAL nLine AS LONG, BYVAL nStyle AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_MARGINSETSTYLE, nLine, nStyle)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MarginSetStyle (BYVAL pSci AS DWORD, BYVAL nLine AS LONG, BYVAL nStyle AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_MARGINSETSTYLE, nLine, nStyle)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_MarginGetStyle (BYVAL hSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_MARGINGETSTYLE, nLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MarginGetStyle (BYVAL pSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_MARGINGETSTYLE, nLine, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_MarginSetStyles (BYVAL hSci AS DWORD, BYVAL nLine AS LONG, BYVAL strStyles AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_MARGINSETSTYLES, nLine, STRPTR(strStyles))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MarginSetStyles (BYVAL pSci AS DWORD, BYVAL nLine AS LONG, BYVAL strStyles AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_MARGINSETSTYLES, nLine, STRPTR(strStyles))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_MarginGetStyles (BYVAL hSci AS DWORD, BYVAL nType AS LONG) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = SendMessageA(hSci, %SCI_MARGINGETSTYLES, nType, 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen + 1)
   SendMessageA(hSci, %SCI_MARGINGETSTYLES, nType, STRPTR(buffer))
   FUNCTION = REMOVE$(buffer, CHR$(0))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MarginGetStyles (BYVAL pSci AS DWORD, BYVAL nType AS LONG) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = Scintilla_DirectFunction(pSci, %SCI_MARGINGETSTYLES, nType, 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen + 1)
   Scintilla_DirectFunction(pSci, %SCI_MARGINGETSTYLES, nType, STRPTR(buffer))
   FUNCTION = REMOVE$(buffer, CHR$(0))
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_MarginTextClearAll (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_MARGINTEXTCLEARALL, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MarginTextClearAll (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_MARGINTEXTCLEARALL, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_MARGINSETSTYLEOFFSET(int style)
' SCI_MARGINGETSTYLEOFFSET
' Margin styles may be completely separated from standard text styles by setting a style
' offset. For example, SCI_MARGINSETSTYLEOFFSET(256) would allow the margin styles to be
' numbered from 256 upto 511 so they do not overlap styles set by lexers. Each style
' number set with SCI_MARGINSETSTYLE or SCI_MARGINSETSTYLES has the offset added before
' looking up the style.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_MarginSetStyleOffset (BYVAL hSci AS DWORD, BYVAL nStyle AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_MARGINSETSTYLEOFFSET, nStyle, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MarginSetStyleOffset (BYVAL pSci AS DWORD, BYVAL nStyle AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_MARGINSETSTYLEOFFSET, nStyle, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_MarginGetStyleOffset (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_MARGINGETSTYLEOFFSET, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MarginGetStyleOffset (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_MARGINGETSTYLEOFFSET, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Define margin options by enabling appropriate bit flags. At the moment, only one flag is
' available SC_MARGINOPTION_SUBLINESELECT=1, which controls how wrapped lines are selected
' when clicking on margin in front of them. If SC_MARGINOPTION_SUBLINESELECT is set only
' sub line of wrapped line is selected, otherwise whole wrapped line is selected. Margin
' options are set to SC_MARGINOPTION_NONE=0 by default.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetMarginOptions (BYVAL hSci AS DWORD, BYVAL marginOptions AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETMARGINOPTIONS, marginOptions, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetMarginOptions (BYVAL pSci AS DWORD, BYVAL marginOptions AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETMARGINOPTIONS, marginOptions, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_GetMarginOptions (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETMARGINOPTIONS, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetMarginOptions (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETMARGINOPTIONS, 0, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                        Annotations
' ########################################################################################

' ========================================================================================
' SCI_ANNOTATIONSETTEXT(int line, char *text)
' SCI_ANNOTATIONGETTEXT(int line, char *text)
' SCI_ANNOTATIONSETSTYLE(int line, int style)
' SCI_ANNOTATIONGETSTYLE(int line)
' SCI_ANNOTATIONSETSTYLES(int line, char *styles)
' SCI_ANNOTATIONGETSTYLES(int line, char *styles)
' SCI_ANNOTATIONGETLINES(int line)
' SCI_ANNOTATIONCLEARALL
' A different string may be set for each line with SCI_ANNOTATIONSETTEXT. To clear
' annotations call SCI_ANNOTATIONSETTEXT with a NULL pointer. The whole of the text
' ANNOTATION on a line may be displayed in a particular style with SCI_ANNOTATIONSETSTYLE
' or each character may be individually styled with SCI_ANNOTATIONSETSTYLES which uses an
' array of bytes with each byte setting the style of the corresponding text byte similar
' to SCI_SETSTYLINGEX. The text must be set first as it specifies how long the annotation
' is so how many bytes of styling to read. Setting an annotation will cause a
' SC_MOD_CHANGEANNOTATION notification to be sent.
' The number of lines annotating a line can be retrieved with SCI_ANNOTATIONGETLINES. All
' the lines can be cleared of annotations with SCI_ANNOTATIONCLEARALL which is equivalent
' to clearing each line (setting to 0) and then deleting other memory used for this feature.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AnnotationSetText (BYVAL hSci AS DWORD, BYVAL nLine AS LONG, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ANNOTATIONSETTEXT, nLine, STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AnnotationSetText (BYVAL pSci AS DWORD, BYVAL nLine AS LONG, BYVAL strText AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ANNOTATIONSETTEXT, nLine, STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AnnotationGetText (BYVAL hSci AS DWORD, BYVAL nLine AS LONG) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = SendMessageA(hSci, %SCI_ANNOTATIONGETTEXT, nLine, 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen + 1)
   SendMessageA(hSci, %SCI_ANNOTATIONGETTEXT, nLine, STRPTR(buffer))
   FUNCTION = REMOVE$(buffer, CHR$(0))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AnnotationGetText (BYVAL pSci AS DWORD, BYVAL nLine AS LONG) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = Scintilla_DirectFunction(pSci, %SCI_ANNOTATIONGETTEXT, nLine, 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen + 1)
   Scintilla_DirectFunction(pSci, %SCI_ANNOTATIONGETTEXT, nLine, STRPTR(buffer))
   FUNCTION = REMOVE$(buffer, CHR$(0))
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_AnnotationSetStyle (BYVAL hSci AS DWORD, BYVAL nLine AS LONG, BYVAL nStyle AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ANNOTATIONSETSTYLE, nLine, nStyle)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AnnotationSetStyle (BYVAL pSci AS DWORD, BYVAL nLine AS LONG, BYVAL nStyle AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ANNOTATIONSETSTYLE, nLine, nStyle)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AnnotationGetStyle (BYVAL hSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ANNOTATIONGETSTYLE, nLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AnnotationGetStyle (BYVAL pSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ANNOTATIONGETSTYLE, nLine, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_AnnotationSetStyles (BYVAL hSci AS DWORD, BYVAL nLine AS LONG, BYVAL strStyles AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ANNOTATIONSETSTYLES, nLine, STRPTR(strStyles))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AnnotationSetStyles (BYVAL pSci AS DWORD, BYVAL nLine AS LONG, BYVAL strStyles AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ANNOTATIONSETSTYLES, nLine, STRPTR(strStyles))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AnnotationGetStyles (BYVAL hSci AS DWORD, BYVAL nLine AS LONG) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = SendMessageA(hSci, %SCI_ANNOTATIONGETSTYLES, nLine, 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen + 1)
   SendMessageA(hSci, %SCI_ANNOTATIONGETSTYLES, nLine, STRPTR(buffer))
   FUNCTION = REMOVE$(buffer, CHR$(0))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AnnotationGetStyles (BYVAL pSci AS DWORD, BYVAL nLine AS LONG) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = Scintilla_DirectFunction(pSci, %SCI_ANNOTATIONGETSTYLES, nLine, 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen + 1)
   Scintilla_DirectFunction(pSci, %SCI_ANNOTATIONGETSTYLES, nLine, STRPTR(buffer))
   FUNCTION = REMOVE$(buffer, CHR$(0))
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_AnnotationGetLines (BYVAL hSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ANNOTATIONGETLINES, nLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AnnotationGetLines (BYVAL pSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ANNOTATIONGETLINES, nLine, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_AnnotationClearAll (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ANNOTATIONGETLINES, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AnnotationClearAll (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ANNOTATIONGETLINES, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_ANNOTATIONSETVISIBLE(int visible)
' SCI_ANNOTATIONGETVISIBLE
' Annotations can be made visible in a view and there is a choice of display style when
' visible. The two messages set and get the annotation display mode. The visible argument
' can be one of:
' ANNOTATION_HIDDEN    0    Annotations are not displayed.
' ANNOTATION_STANDARD  1    Annotations are drawn left justified with no adornment.
' ANNOTATION_BOXED     2    Annotations are indented to match the text and are surrounded by a box.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AnnotationSetVisible (BYVAL hSci AS DWORD, BYVAL bVisible AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ANNOTATIONSETVISIBLE, bVisible, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AnnotationSetVisible (BYVAL pSci AS DWORD, BYVAL bVisible AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ANNOTATIONSETVISIBLE, bVisible, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AnnotationGetVisible (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ANNOTATIONGETVISIBLE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AnnotationGetVisible (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ANNOTATIONGETVISIBLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_ANNOTATIONSETSTYLEOFFSET(int style)
' SCI_ANNOTATIONGETSTYLEOFFSET
' Annotation styles may be completely separated from standard text styles by setting a
' style offset. For example, SCI_ANNOTATIONSETSTYLEOFFSET(512) would allow the annotation
' styles to be numbered from 512 upto 767 so they do not overlap styles set by lexers (or
' margins if margins offset is 256). Each style number set with SCI_ANNOTATIONSETSTYLE or
' SCI_ANNOTATIONSETSTYLES has the offset added before looking up the style.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AnnotationSetStyleOffset (BYVAL hSci AS DWORD, BYVAL nStyle AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ANNOTATIONSETSTYLEOFFSET, nStyle, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AnnotationSetStyleOffset (BYVAL pSci AS DWORD, BYVAL nStyle AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ANNOTATIONSETSTYLEOFFSET, nStyle, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AnnotationGetStyleOffset (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ANNOTATIONGETSTYLEOFFSET, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AnnotationGetStyleOffset (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ANNOTATIONGETSTYLEOFFSET, 0, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                    Other Settings
' ########################################################################################

' ========================================================================================
' Deprecated.
' SCI_SETUSEPALETTE(bool allowPaletteUse)
' SCI_GETUSEPALETTE
' On 8 bit displays, which can only display a maximum of 256 colours, the graphics
' environment mediates between the colour needs of applications through the use of palettes.
' On Windows, there are some problems with visual flashing when switching between
' applications with palettes and it is also necessary for the application containing the
' Scintilla control to forward some messages to Scintilla for its palette code to work.
' Because of this, by default, the palette is not used and the application must tell
' Scintilla to use one. If Scintilla is not using a palette, it will only display in those
' colours already available, which are often the 20 Windows system colours.
' To see an example of how to enable palette support in Scintilla, search the text of
' SciTE for WM_PALETTECHANGED, WM_QUERYNEWPALETTE and SCI_SETUSEPALETTE. The Windows
' messages to forward are: WM_SYSCOLORCHANGE, WM_PALETTECHANGED, WM_QUERYNEWPALETTE (should return TRUE).
' To forward a message (WM_XXXX, WPARAM, LPARAM) to Scintilla, you can use
' SendMessage(hScintilla, WM_XXXX, WPARAM, LPARAM) where hScintilla is the handle to the
' Scintilla window you created as your editor.
' While we are on the subject of forwarding messages in Windows, the top level window
' should forward any WM_SETTINGCHANGE messages to Scintilla (this is currently used to
' collect changes to mouse settings, but could be used for other user interface items in
' the future).
' ========================================================================================
' ========================================================================================
'FUNCTION SCI_SetUsePalette (BYVAL hSci AS DWORD, BYVAL allowPaletteUse AS BYTE) AS LONG
'   FUNCTION = SendMessageA(hSci, %SCI_SETUSEPALETTE, allowPaletteUse, 0)
'END FUNCTION
' ========================================================================================
' ========================================================================================
'FUNCTION SCIP_SetUsePalette (BYVAL pSci AS DWORD, BYVAL allowPaletteUse AS BYTE) AS LONG
'   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETUSEPALETTE, allowPaletteUse, 0)
'END FUNCTION
' ========================================================================================
' ========================================================================================
'FUNCTION SCI_GetUsePalette (BYVAL hSci AS DWORD) AS LONG
'   FUNCTION = SendMessageA(hSci, %SCI_GETUSEPALETTE, 0, 0)
'END FUNCTION
' ========================================================================================
' ========================================================================================
'FUNCTION SCIP_GetUsePalette (BYVAL pSci AS DWORD) AS LONG
'   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETUSEPALETTE, 0, 0)
'END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETBUFFEREDDRAW(bool isBuffered)
' SCI_GETBUFFEREDDRAW
' These messages turn buffered drawing on or off and report the buffered drawing state.
' Buffered drawing draws each line into a bitmap rather than directly to the screen and
' then copies the bitmap to the screen. This avoids flickering although it does take longer.
' The default is for drawing to be buffered.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetBufferedDraw (BYVAL hSci AS DWORD, BYVAL isBuffered AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETBUFFEREDDRAW, isBuffered, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetBufferedDraw (BYVAL pSci AS DWORD, BYVAL isBuffered AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETBUFFEREDDRAW, isBuffered, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetBufferedDraw (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETBUFFEREDDRAW, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetBufferedDraw (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETBUFFEREDDRAW, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETPHASESDRAW(int phases)
' SCI_GETPHASESDRAW
' There are several orders in which the text area may be drawn offering a trade-off between
' speed and allowing all pixels of text to be seen even when they overlap other elements.
' In single phase drawing (SC_PHASES_ONE) each run of characters in one style is drawn
' along with its background. If a character overhangs the end of a run, such as in "V_"
' where the "V" is in a different style from the "_", then this can cause the right hand
' side of the "V" to be overdrawn by the background of the "_" which cuts it off.
' Two phase drawing (SC_PHASES_TWO) fixes this by drawing all the backgrounds of a line
' first and then drawing the text in transparent mode. Lines are drawn separately and no
' line will overlap another so any pixels that overlap into another line such as extreme
' ascenders and descenders on characters will be cut off. Two phase drawing may flicker
' more than single phase unless buffered drawing is on or the platform is naturally buffered.
' The default is for drawing to be two phase.
' Multiple phase drawing (SC_PHASES_MULTIPLE) draws the whole area multiple times, once
' for each feature, building up the the appearance in layers or phases. The coloured
' backgrounds for all lines are drawn before any text and then all the text is drawn in
' transparent mode over this combined background without clipping text to the line
' boundaries. This allows extreme ascenders and descenders to overflow into the adjacent
' lines. This mode is incompatible with buffered drawing and will act as SC_PHASES_TWO if
' buffered drawing is turned on. Multiple phase drawing is slower than two phase drawing.
' Setting the layout cache to SC_CACHE_PAGE or higher can ensure that multiple phase
' drawing is not significantly slower.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetPhasesDraw (BYVAL hSci AS DWORD, BYVAL phases AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETPHASESDRAW, phases, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetPhasesDraw (BYVAL pSci AS DWORD, BYVAL phases AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETPHASESDRAW, phases, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetPhasesDraw (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETPHASESDRAW, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetPhasesDraw (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETPHASESDRAW, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETTWOPHASEDRAW(bool twoPhase)
' SCI_GETTWOPHASEDRAW
' Two phase drawing is a better but slower way of drawing text. In single phase drawing
' each run of characters in one style is drawn along with its background. If a character
' overhangs the end of a run, such as in "V_" where the "V" is in a different style from
' the "_", then this can cause the right hand side of the "V" to be overdrawn by the
' background of the "_" which cuts it off. Two phase drawing fixes this by drawing all the
' backgrounds first and then drawing the text in transparent mode. Two phase drawing may
' flicker more than single phase unless buffered drawing is on. The default is for drawing
' to be two phase.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetTwoPhaseDraw (BYVAL hSci AS DWORD, BYVAL twoPhase AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETTWOPHASEDRAW, twoPhase, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetTwoPhaseDraw (BYVAL pSci AS DWORD, BYVAL twoPhase AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETTWOPHASEDRAW, twoPhase, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetTwoPhaseDraw (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETTWOPHASEDRAW, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetTwoPhaseDraw (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETTWOPHASEDRAW, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETTECHNOLOGY(int technology)
' SCI_GETTECHNOLOGY
' The technology property allows choosing between different drawing APIs and options. On
' most platforms, the only choice is SC_TECHNOLOGY_DEFAULT (0). On Windows Vista or later,
' SC_TECHNOLOGY_DIRECTWRITE (1) can be chosen to use the Direct2D and DirectWrite APIs for
' higher quality antialiased drawing.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetTechnology (BYVAL hSci AS DWORD, BYVAL technology AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETTECHNOLOGY, technology, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetTechnology (BYVAL pSci AS DWORD, BYVAL technology AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETTECHNOLOGY, technology, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetTechnology (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETTECHNOLOGY, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetTechnology (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETTECHNOLOGY, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETFONTQUALITY(int fontQuality)
' SCI_GETFONTQUALITY
' Manage font quality (antialiasing method). Currently, the following values are available
' on Windows: SC_EFF_QUALITY_DEFAULT (backward compatible), SC_EFF_QUALITY_NON_ANTIALIASED,
' SC_EFF_QUALITY_ANTIALIASED, SC_EFF_QUALITY_LCD_OPTIMIZED.
' In case it is necessary to squeeze more options into this property, only a limited number
' of bits defined by SC_EFF_QUALITY_MASK (0xf) will be used for quality.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetFontQuality (BYVAL hSci AS DWORD, BYVAL fontQuality AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETFONTQUALITY, fontQuality, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetFontQuality (BYVAL pSci AS DWORD, BYVAL fontQuality AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETFONTQUALITY, fontQuality, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetFontQuality (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETFONTQUALITY, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetFontQuality (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETFONTQUALITY, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETCODEPAGE(int codePage)
' SCI_GETCODEPAGE
' Scintilla has some support for Japanese, Chinese and Korean DBCS. Use this message with
' codePage set to the code page number to set Scintilla to use code page information to
' ensure double byte characters are treated as one character rather than two. This also
' stops the caret from moving between the two bytes in a double byte character. Do not use
' this message to choose between different single byte character sets: it doesn't do that.
' Call with codePage set to zero to disable DBCS support. The default is SCI_SETCODEPAGE(0).
' Code page SC_CP_UTF8 (65001) sets Scintilla into Unicode mode with the document treated
' as a sequence of characters expressed in UTF-8. The text is converted to the platform's
' normal Unicode encoding before being drawn by the OS and thus can display Hebrew, Arabic,
' Cyrillic, and Han characters. Languages which can use two characters stacked vertically
' in one horizontal space, such as Thai, will mostly work but there are some issues where
' the characters are drawn separately leading to visual glitches. Bi-directional text is
' not supported.
' Code page can be set to 932 (Japanese Shift-JIS), 936 (Simplified Chinese GBK), 949
' (Korean Unified Hangul Code), 950 (Traditional Chinese Big5), or 1361 (Korean Johab)
' although these may require installation of language specific support.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetCodePage (BYVAL hSci AS DWORD, BYVAL codePage AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETCODEPAGE, codePage, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetCodePage (BYVAL pSci AS DWORD, BYVAL codePage AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETCODEPAGE, codePage, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetCodePage (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETCODEPAGE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetCodePage (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETCODEPAGE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETIMEINTERACTION(int imeInteraction)
' SCI_GETIMEINTERACTION
' When entering text in Chinese, Japanese, or Korean an Input Method Editor (IME) may be
' displayed. The IME may be an extra window appearing above Scintilla or may be displayed
' by Scintilla itself as text. On some platforms there is a choice between the two techniques.
' A windowed IME SC_IME_WINDOWED (0) may be more similar in appearance and behaviour to
' the IME in other applications. An inline IME SC_IME_INLINE (1) may work better with some
' Scintilla features such as rectangular and multiple selection.
' The windowed behaviour can be chosen with SCI_SETIMEINTERACTION(SC_IME_WINDOWED) and the
' inline behaviour with SCI_SETIMEINTERACTION(SC_IME_INLINE). Scintilla may ignore this call
' in some cases. For example, the inline behaviour might only be supported for some languages.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetImeInteraction (BYVAL hSci AS DWORD, BYVAL imeInteraction AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETIMEINTERACTION, imeInteraction, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetImeInteraction (BYVAL pSci AS DWORD, BYVAL imeInteraction AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETIMEINTERACTION, imeInteraction, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetImeInteraction (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETIMEINTERACTION, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetImeInteraction (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETIMEINTERACTION, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETKEYSUNICODE(bool keysUnicode)
' SCI_GETKEYSUNICODE
' On Windows, character keys are normally handled differently depending on whether Scintilla
' is a wide or narrow character window with character messages treated as Unicode when wide
' and as 8 bit otherwise. Set this property to always treat as Unicode. This option is
' needed for Delphi.
' ========================================================================================
#IF %DEF(%INCLUDE_DEPRECATED_FEATURES)
' ========================================================================================
FUNCTION SCI_SetKeysUnicode (BYVAL hSci AS DWORD, BYVAL keysUnicode AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETKEYSUNICODE, keysUnicode, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetKeysUnicode (BYVAL pSci AS DWORD, BYVAL keysUnicode AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETKEYSUNICODE, keysUnicode, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetKeysUnicode (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETKEYSUNICODE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetKeysUnicode (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETKEYSUNICODE, 0, 0)
END FUNCTION
' ========================================================================================
#ENDIF

' ========================================================================================
' SCI_SETWORDCHARS(<unused>, const char *chars)
' Scintilla has several functions that operate on words, which are defined to be contiguous
' sequences of characters from a particular set of characters. This message defines which
' characters are members of that set. The character sets are set to default values before
' processing this function. For example, if you don't allow '_' in your set of characters
' use:
' SCI_SETWORDCHARS(0, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetWordChars (BYVAL hSci AS DWORD, BYVAL strChars AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETWORDCHARS, 0, STRPTR(strChars))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetWordChars (BYVAL pSci AS DWORD, BYVAL strChars AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETWORDCHARS, 0, STRPTR(strChars))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETWORDCHARS(<unused>, char *characters)
' This fills the characters parameter with all the characters included in words. The
' characters parameter must be large enough to hold all of the characters. If the
' characters parameter is 0 then the length that should be allocated to store the entire
' set is returned.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetWordChars (BYVAL hSci AS DWORD) AS STRING
   LOCAL nLen AS LONG
   nLen = SendMessageA(hSci, %SCI_GETWORDCHARS, 0, 0)
   IF nLen = 0 THEN EXIT FUNCTION
   LOCAL buffer AS STRING
   buffer = SPACE$(nLen + 1)
   SendMessageA(hSci, %SCI_GETWORDCHARS, 0, STRPTR(buffer))
   FUNCTION = LEFT$(buffer, LEN(buffer) - 1)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetWordChars (BYVAL pSci AS DWORD) AS STRING
   LOCAL nLen AS LONG
   nLen = Scintilla_DirectFunction(pSci, %SCI_GETWORDCHARS, 0, 0)
   IF nLen = 0 THEN EXIT FUNCTION
   LOCAL buffer AS STRING
   buffer = SPACE$(nLen + 1)
   Scintilla_DirectFunction(pSci, %SCI_GETWORDCHARS, 0, STRPTR(buffer))
   FUNCTION = LEFT$(buffer, LEN(buffer) - 1)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETWHITESPACECHARS(<unused>, const char *characters)
' SCI_GETWHITESPACECHARS(<unused>, char *characters)
' Similar to SCI_SETWORDCHARS, this message allows the user to define which chars Scintilla
' considers as whitespace. Setting the whitespace chars allows the user to fine-tune
' Scintilla's behaviour doing such things as moving the cursor to the start or end of a
' word; for example, by defining punctuation chars as whitespace, they will be skipped over
' when the user presses ctrl+left or ctrl+right. This function should be called after
' SCI_SETWORDCHARS as it will reset the whitespace characters to the default set.
' SCI_GETWHITESPACECHARS behaves similarly to SCI_GETWORDCHARS.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetWhiteSpaceChars (BYVAL hSci AS DWORD, BYVAL strChars AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETWHITESPACECHARS, 0, STRPTR(strChars))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetWhiteSpaceChars (BYVAL pSci AS DWORD, BYVAL strChars AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETWHITESPACECHARS, 0, STRPTR(strChars))
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_GetWhiteSpaceChars (BYVAL hSci AS DWORD) AS STRING
   LOCAL nLen AS LONG
   nLen = SendMessageA(hSci, %SCI_GETWHITESPACECHARS, 0, 0)
   IF nLen = 0 THEN EXIT FUNCTION
   LOCAL buffer AS STRING
   buffer = SPACE$(nLen + 1)
   SendMessageA(hSci, %SCI_GETWHITESPACECHARS, 0, STRPTR(buffer))
   FUNCTION = LEFT$(buffer, LEN(buffer) - 1)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetWhiteSpaceChars (BYVAL pSci AS DWORD) AS STRING
   LOCAL nLen AS LONG
   nLen = Scintilla_DirectFunction(pSci, %SCI_GETWHITESPACECHARS, 0, 0)
   IF nLen = 0 THEN EXIT FUNCTION
   LOCAL buffer AS STRING
   buffer = SPACE$(nLen + 1)
   Scintilla_DirectFunction(pSci, %SCI_GETWHITESPACECHARS, 0, STRPTR(buffer))
   FUNCTION = LEFT$(buffer, LEN(buffer) - 1)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETPUNCTUATIONCHARS(<unused>, const char *characters)
' SCI_GETPUNCTUATIONCHARS(<unused>, char *characters)
' Similar to SCI_SETWORDCHARS and SCI_SETWHITESPACECHARS, this message allows the user to
' define which chars Scintilla considers as punctuation. SCI_GETPUNCTUATIONCHARS behaves
' similarly to SCI_GETWORDCHARS.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetPunctuationChars (BYVAL hSci AS DWORD, BYVAL strChars AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETPUNCTUATIONCHARS, 0, STRPTR(strChars))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetPunctuationChars (BYVAL pSci AS DWORD, BYVAL strChars AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETPUNCTUATIONCHARS, 0, STRPTR(strChars))
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_GetPunctuationChars (BYVAL hSci AS DWORD) AS STRING
   LOCAL nLen AS LONG
   nLen = SendMessageA(hSci, %SCI_GETPUNCTUATIONCHARS, 0, 0)
   IF nLen = 0 THEN EXIT FUNCTION
   LOCAL buffer AS STRING
   buffer = SPACE$(nLen + 1)
   SendMessageA(hSci, %SCI_GETPUNCTUATIONCHARS, 0, STRPTR(buffer))
   FUNCTION = LEFT$(buffer, LEN(buffer) - 1)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetPunctuationChars (BYVAL pSci AS DWORD) AS STRING
   LOCAL nLen AS LONG
   nLen = Scintilla_DirectFunction(pSci, %SCI_GETPUNCTUATIONCHARS, 0, 0)
   IF nLen = 0 THEN EXIT FUNCTION
   LOCAL buffer AS STRING
   buffer = SPACE$(nLen + 1)
   Scintilla_DirectFunction(pSci, %SCI_GETPUNCTUATIONCHARS, 0, STRPTR(buffer))
   FUNCTION = LEFT$(buffer, LEN(buffer) - 1)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETCHARSDEFAULT
' Use the default sets of word and whitespace characters. This sets whitespace to space,
' tab and other characters with codes less than 0x20, with word characters set to
' alphanumeric and '_'.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetCharsetDefault (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETCHARSDEFAULT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetCharsetDefault (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETCHARSDEFAULT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GRABFOCUS
' SCI_SETFOCUS(bool focus)
' SCI_GETFOCUS
' Scintilla can be told to grab the focus with this message.
' The internal focus flag can be set with SCI_SETFOCUS. This is used by clients that have
' complex focus requirements such as having their own window that gets the real focus but
' with the need to indicate that Scintilla has the logical focus.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GrabFocus (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GRABFOCUS, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GrabFocus (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GRABFOCUS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_SetFocus (BYVAL hSci AS DWORD, BYVAL bFocus AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETFOCUS, bFocus, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetFocus (BYVAL pSci AS DWORD, BYVAL bFocus AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETFOCUS, bFocus, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_GetFocus (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETFOCUS, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetFocus (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETFOCUS, 0, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                  Brace highlighting
' ########################################################################################

' ========================================================================================
' SCI_BRACEHIGHLIGHT(int pos1, int pos2)
' Up to two characters can be highlighted in a 'brace highlighting style', which is defined
' as style number STYLE_BRACELIGHT (34). If you have enabled indent guides, you may also
' wish to highlight the indent that corresponds with the brace. You can locate the column
' with SCI_GETCOLUMN and highlight the indent with SCI_SETHIGHLIGHTGUIDE.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_BraceHighLight (BYVAL hSci AS DWORD, BYVAL pos1 AS LONG, BYVAL pos2 AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_BRACEHIGHLIGHT, pos1, pos2)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_BraceHighLight (BYVAL pSci AS DWORD, BYVAL pos1 AS LONG, BYVAL pos2 AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_BRACEHIGHLIGHT, pos1, pos2)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Use specified indicator to highlight matching braces instead of changing their style.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_BraceHighLightIndicator (BYVAL hSci AS DWORD, BYVAL useBraceHighlightIndicator AS BYTE, BYVAL indicatorNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_BRACEHIGHLIGHTINDICATOR, useBraceHighlightIndicator, indicatorNumber)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_BraceHighLightIndicator (BYVAL pSci AS DWORD, BYVAL useBraceHighlightIndicator AS BYTE, BYVAL indicatorNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_BRACEHIGHLIGHTINDICATOR, useBraceHighlightIndicator, indicatorNumber)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_BRACEBADLIGHT(int pos1)
' If there is no matching brace then the brace badlighting style, style STYLE_BRACEBAD (35),
' can be used to show the brace that is unmatched. Using a position of INVALID_POSITION (-1)
' removes the highlight.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_BraceBadLight (BYVAL hSci AS DWORD, BYVAL pos1 AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_BRACEBADLIGHT, pos1, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_BraceBadLight (BYVAL pSci AS DWORD, BYVAL pos1 AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_BRACEBADLIGHT, pos1, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Use specified indicator to highlight non matching brace instead of changing its style.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_BraceBadHighLightIndicator (BYVAL hSci AS DWORD, BYVAL useBraceBadLightIndicator AS BYTE, BYVAL indicatorNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_BRACEBADLIGHTINDICATOR, useBraceBadLightIndicator, indicatorNumber)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_BraceBadHighLightIndicator (BYVAL pSci AS DWORD, BYVAL useBraceBadLightIndicator AS BYTE, BYVAL indicatorNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_BRACEBADLIGHTINDICATOR, useBraceBadLightIndicator, indicatorNumber)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_BRACEMATCH(int pos, int maxReStyle)
' The SCI_BRACEMATCH message finds a corresponding matching brace given pos, the position
' of one brace. The brace characters handled are '(', ')', '[', ']', '{', '}', '<', and '>'.
' The search is forwards from an opening brace and backwards from a closing brace. If the
' character at position is not a brace character, or a matching brace cannot be found, the
' return value is -1. Otherwise, the return value is the position of the matching brace.
' A match only occurs if the style of the matching brace is the same as the starting brace
' or the matching brace is beyond the end of styling. Nested braces are handled correctly.
' The maxReStyle parameter must currently be 0 - it may be used in the future to limit the
' length of brace searches.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_BraceMatch (BYVAL hSci AS DWORD, BYVAL position AS LONG, BYVAL maxReStyle AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_BRACEMATCH, position, maxReStyle)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_BraceMatch (BYVAL pSci AS DWORD, BYVAL position AS LONG, BYVAL maxReStyle AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_BRACEMATCH, position, maxReStyle)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                              Tabs and Indentation Guides
' ########################################################################################

' ========================================================================================
' Indentation (the white space at the start of a line) is often used by programmers to
' clarify program structure and in some languages, for example Python, it may be part of
' the language syntax. Tabs are normally used in editors to insert a tab character or to
' pad text with spaces up to the next tab.
' Scintilla can be set to treat tab and backspace in the white space at the start of a
' line in a special way: inserting a tab indents the line to the next indent position
' rather than just inserting a tab at the current character position and backspace
' unindents the line rather than deleting a character. Scintilla can also display
' indentation guides (vertical lines) to help you to generate code.
' ========================================================================================

' ========================================================================================
' SCI_SETTABWIDTH(int widthInChars)
' SCI_GETTABWIDTH
' SCI_SETTABWIDTH sets the size of a tab as a multiple of the size of a space character in
' STYLE_DEFAULT. The default tab width is 8 characters. There are no limits on tab sizes,
' but values less than 1 or large values may have undesirable effects.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetTabWidth (BYVAL hSci AS DWORD, BYVAL widthInChars AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETTABWIDTH, widthInChars, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetTabWidth (BYVAL pSci AS DWORD, BYVAL widthInChars AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETTABWIDTH, widthInChars, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetTabWidth (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETTABWIDTH, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetTabWidth (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETTABWIDTH, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_CLEARTABSTOPS(int line)
' SCI_ADDTABSTOP(int line, int x)
' SCI_GETNEXTTABSTOP(int line, int x)
' SCI_CLEARTABSTOPS clears explicit tabstops on a line. SCI_ADDTABSTOP adds an explicit
' tabstop at the specified distance from the left (in pixels), and SCI_GETNEXTTABSTOP gets
' the next explicit tabstop position set after the given x position, or zero if there
' aren't any. Changing tab stops produces a SC_MOD_CHANGETABSTOPS notification.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_ClearTabStops (BYVAL hSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CLEARTABSTOPS, nLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ClearTabStops (BYVAL pSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CLEARTABSTOPS, nLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AddTabStop (BYVAL hSci AS DWORD, BYVAL nLine AS LONG, BYVAL x AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ADDTABSTOP, nLine, x)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AddTabStop (BYVAL pSci AS DWORD, BYVAL nLine AS LONG, BYVAL x AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ADDTABSTOP, nLine, x)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetNextTabStop (BYVAL hSci AS DWORD, BYVAL nLine AS LONG, BYVAL x AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETNEXTTABSTOP, nLine, x)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetNextTabStop (BYVAL pSci AS DWORD, BYVAL nLine AS LONG, BYVAL x AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETNEXTTABSTOP, nLine, x)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETUSETABS(bool useTabs)
' SCI_GETUSETABS
' SCI_SETUSETABS determines whether indentation should be created out of a mixture of tabs
' and spaces or be based purely on spaces. Set useTabs to false (0) to create all tabs and
' indents out of spaces. The default is true. You can use SCI_GETCOLUMN to get the column
' of a position taking the width of a tab into account.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetUseTabs (BYVAL hSci AS DWORD, BYVAL useTabs AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETUSETABS, useTabs, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetUseTabs (BYVAL pSci AS DWORD, BYVAL useTabs AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETUSETABS, useTabs, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetUseTabs (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETUSETABS, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetUseTabs (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETUSETABS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETINDENT(int widthInChars)
' SCI_GETINDENT
' SCI_SETINDENT sets the size of indentation in terms of the width of a space in
' STYLE_DEFAULT. If you set a width of 0, the indent size is the same as the tab size.
' There are no limits on indent sizes, but values less than 0 or large values may have
' undesirable effects.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetIndent (BYVAL hSci AS DWORD, BYVAL widthInChars AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETINDENT, widthInChars, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetIndent (BYVAL pSci AS DWORD, BYVAL widthInChars AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETINDENT, widthInChars, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetIndent (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETINDENT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetIndent (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETINDENT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETTABINDENTS(bool tabIndents)
' SCI_GETTABINDENTS
' SCI_SETBACKSPACEUNINDENTS(bool bsUnIndents)
' SCI_GETBACKSPACEUNINDENTS
' Inside indentation white space, the tab and backspace keys can be made to indent and
' unindent rather than insert a tab character or delete a character with the
' SCI_SETTABINDENTS and SCI_SETBACKSPACEUNINDENTS functions.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetTabIndents (BYVAL hSci AS DWORD, BYVAL tabIndents AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETTABINDENTS, tabIndents, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetTabIndents (BYVAL pSci AS DWORD, BYVAL tabIndents AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETTABINDENTS, tabIndents, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetTabIndents (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETTABINDENTS, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetTabIndents (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETTABINDENTS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_SetBackSpaceUnindents (BYVAL hSci AS DWORD, BYVAL bsUnIndents AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETBACKSPACEUNINDENTS, bsUnIndents, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetBackSpaceUnindents (BYVAL pSci AS DWORD, BYVAL bsUnIndents AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETBACKSPACEUNINDENTS, bsUnIndents, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetBackSpaceUnindents (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETBACKSPACEUNINDENTS, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetBackSpaceUnindents (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETBACKSPACEUNINDENTS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETLINEINDENTATION(int line, int indentation)
' SCI_GETLINEINDENTATION(int line)
' The amount of indentation on a line can be discovered and set with SCI_GETLINEINDENTATION
' and SCI_SETLINEINDENTATION. The indentation is measured in character columns, which
' correspond to the width of space characters.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetLineIndentation (BYVAL hSci AS DWORD, BYVAL nLine AS LONG, BYVAL indentation AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETLINEINDENTATION, nLine, indentation)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetLineIndentation (BYVAL pSci AS DWORD, BYVAL nLine AS LONG, BYVAL indentation AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETLINEINDENTATION, nLine, indentation)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetLineIndentation (BYVAL hSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETLINEINDENTATION, nLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetLineIndentation (BYVAL pSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETLINEINDENTATION, nLine, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETLINEINDENTPOSITION(int line)
' This returns the position at the end of indentation of a line.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetLineIndentPosition (BYVAL hSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETLINEINDENTPOSITION, nLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetLineIndentPosition (BYVAL pSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETLINEINDENTPOSITION, nLine, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETINDENTATIONGUIDES(int indentView)
' SCI_GETINDENTATIONGUIDES
' Indentation guides are dotted vertical lines that appear within indentation white space
' every indent size columns. They make it easy to see which constructs line up especially
' when they extend over multiple pages. Style STYLE_INDENTGUIDE (37) is used to specify the
' foreground and background colour of the indentation guides.
' There are 4 indentation guide views. SC_IV_NONE turns the feature off but the other 3
' states determine how far the guides appear on empty lines.
' SC_IV_NONE        No indentation guides are shown.
' SC_IV_REAL        Indentation guides are shown inside real indentation white space.
' SC_IV_LOOKFORWARD Indentation guides are shown beyond the actual indentation up to the
'                   level of the next non-empty line. If the previous non-empty line was a
'                   fold header then indentation guides are shown for one more level of
'                   indent than that line. This setting is good for Python.
' SC_IV_LOOKBOTH    Indentation guides are shown beyond the actual indentation up to the
'                   level of the next non-empty line or previous non-empty line whichever
'                   is the greater. This setting is good for most languages.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetIndentationGuides (BYVAL hSci AS DWORD, BYVAL indentView AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETINDENTATIONGUIDES, indentView, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetIndentationGuides (BYVAL pSci AS DWORD, BYVAL indentView AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETINDENTATIONGUIDES, indentView, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetIndentationGuides (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETINDENTATIONGUIDES, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetIndentationGuides (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETINDENTATIONGUIDES, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETHIGHLIGHTGUIDE(int column)
' SCI_GETHIGHLIGHTGUIDE
' When brace highlighting occurs, the indentation guide corresponding to the braces may be
' highlighted with the brace highlighting style, STYLE_BRACELIGHT (34). Set column to 0 to
' cancel this highlight.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetHighlightGuide (BYVAL hSci AS DWORD, BYVAL nColumn AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETHIGHLIGHTGUIDE, nColumn, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetHighlightGuide (BYVAL pSci AS DWORD, BYVAL nColumn AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETHIGHLIGHTGUIDE, nColumn, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetHighlightGuide (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETHIGHLIGHTGUIDE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetHighlightGuide (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETHIGHLIGHTGUIDE, 0, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                         Markers
' ########################################################################################

' ========================================================================================
' SCI_MARKERDEFINE(int markerNumber, int markerSymbols)
' This message associates a marker number in the range 0 to 31 with one of the marker
' symbols or an ASCII character. The general-purpose marker symbols currently available are:
' SC_MARK_CIRCLE, SC_MARK_ROUNDRECT, SC_MARK_ARROW, SC_MARK_SMALLRECT, SC_MARK_SHORTARROW,
' SC_MARK_EMPTY, SC_MARK_ARROWDOWN, SC_MARK_MINUS, SC_MARK_PLUS, SC_MARK_ARROWS,
' SC_MARK_DOTDOTDOT, SC_MARK_BACKGROUND, SC_MARK_LEFTRECT, SC_MARK_FULLRECT, and SC_MARK_UNDERLINE.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_MarkerDefine (BYVAL hSci AS DWORD, BYVAL markerNumber AS LONG, BYVAL markerSymbols AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_MARKERDEFINE, markerNumber, markerSymbols)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MarkerDefine (BYVAL pSci AS DWORD, BYVAL markerNumber AS LONG, BYVAL markerSymbols AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_MARKERDEFINE, markerNumber, markerSymbols)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_MARKERDEFINEPIXMAP(int markerNumber, const char *xpm)
' Markers can be set to pixmaps with this message. The XPM format is used for the pixmap
' and it is limited to pixmaps that use one character per pixel with no named colours. The
' transparent colour may be named 'None'. The data should be null terminated. Pixmaps use
' the SC_MARK_PIXMAP marker symbol.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_MarkerDefinePixMap (BYVAL hSci AS DWORD, BYVAL markerNumber AS LONG, BYVAL xpm AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_MARKERDEFINEPIXMAP, markerNumber, STRPTR(xpm))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MarkerDefinePixMap (BYVAL pSci AS DWORD, BYVAL markerNumber AS LONG, BYVAL xpm AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_MARKERDEFINEPIXMAP, markerNumber, STRPTR(xpm))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Markers can be set to translucent pixmaps with this message. The RGBA format is used for
' the pixmap. The width and height must previously been set with the SCI_RGBAIMAGESETWIDTH
' and SCI_RGBAIMAGESETHEIGHT messages. Pixmaps use the SC_MARK_RGBAIMAGE marker symbol.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_RGBAImageSetWidth (BYVAL hSci AS DWORD, BYVAL nWidth AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_RGBAIMAGESETWIDTH, nWidth, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_RGBAImageSetWidth (BYVAL pSci AS DWORD, BYVAL nWidth AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_RGBAIMAGESETWIDTH, nWidth, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_RGBAImageSetHeight (BYVAL hSci AS DWORD, BYVAL nHeight AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_RGBAIMAGESETHEIGHT, nHeight, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_RGBAImageSetHeight (BYVAL pSci AS DWORD, BYVAL nHeight AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_RGBAIMAGESETHEIGHT, nHeight, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_RGBAImageSetScale (BYVAL hSci AS DWORD, BYVAL scalePercent AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_RGBAIMAGESETSCALE, scalePercent, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_RGBAImageSetScale (BYVAL pSci AS DWORD, BYVAL scalePercent AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_RGBAIMAGESETSCALE, scalePercent, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_MarkerDefineRGBAImage (BYVAL hSci AS DWORD, BYVAL markerNumber AS LONG, BYVAL pixs AS BYTE PTR) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_MARKERDEFINERGBAIMAGE, markerNumber, pixs)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MarkerDefineRGBAImage (BYVAL pSci AS DWORD, BYVAL markerNumber AS LONG, BYVAL pixs AS BYTE PTR) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_MARKERDEFINERGBAIMAGE, markerNumber, pixs)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_MARKERSYMBOLDEFINED(int markerNumber)
' Returns the symbol defined for a markerNumber with SCI_MARKERDEFINE or SC_MARK_PIXMAP if
' defined with SCI_MARKERDEFINEPIXMAP.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_MarkerSymbolDefined (BYVAL hSci AS DWORD, BYVAL markerNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_MARKERSYMBOLDEFINED, markerNumber, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MarkerSymbolDefined (BYVAL pSci AS DWORD, BYVAL markerNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_MARKERSYMBOLDEFINED, markerNumber, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_MARKERSETFORE(int markerNumber, int colour)
' SCI_MARKERSETBACK(int markerNumber, int colour)
' These two messages set the foreground and background colour of a marker number.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_MarkerSetFore (BYVAL hSci AS DWORD, BYVAL markerNumber AS LONG, BYVAL colour AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_MARKERSETFORE, markerNumber, colour)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MarkerSetFore (BYVAL pSci AS DWORD, BYVAL markerNumber AS LONG, BYVAL colour AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_MARKERSETFORE, markerNumber, colour)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_MarkerSetBack (BYVAL hSci AS DWORD, BYVAL markerNumber AS LONG, BYVAL colour AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_MARKERSETBACK, markerNumber, colour)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MarkerSetBack (BYVAL pSci AS DWORD, BYVAL markerNumber AS LONG, BYVAL colour AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_MARKERSETBACK, markerNumber, colour)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_MARKERSETALPHA(int markerNumber, int alpha)
' When markers are drawn in the content area, either because there is no margin for them
' or they are of SC_MARK_BACKGROUND or SC_MARK_UNDERLINE types, they may be drawn
' translucently by setting an alpha value.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_MarkerSetAlpha (BYVAL hSci AS DWORD, BYVAL markerNumber AS LONG, BYVAL alpha AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_MARKERSETALPHA, markerNumber, alpha)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MarkerSetAlpha (BYVAL pSci AS DWORD, BYVAL markerNumber AS LONG, BYVAL alpha AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_MARKERSETALPHA, markerNumber, alpha)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_MARKERADD(int line, int markerNumber)
' This message adds marker number markerNumber to a line. The message returns -1 if this
' fails (illegal line number, out of memory) or it returns a marker handle number that
' identifies the added marker. You can use this returned handle with SCI_MARKERLINEFROMHANDLE
' to find where a marker is after moving or combining lines and with SCI_MARKERDELETEHANDLE
' to delete the marker based on its handle. The message does not check the value of
' markerNumber, nor does it check if the line already contains the marker.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_MarkerAdd (BYVAL hSci AS DWORD, BYVAL nLine AS LONG, BYVAL markerNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_MARKERADD, nLine, markerNumber)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MarkerAdd (BYVAL pSci AS DWORD, BYVAL nLine AS LONG, BYVAL markerNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_MARKERADD, nLine, markerNumber)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_MARKERADDSET(int line, int markerMask)
' This message can add one or more markers to a line with a single call, specified in the
' same "one-bit-per-marker" 32-bit integer format returned by SCI_MARKERGET (and used by
' the mask-based marker search functions SCI_MARKERNEXT and SCI_MARKERPREVIOUS). As with
' SCI_MARKERADD, no check is made to see if any of the markers are already present on the
' targeted line.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_MarkerAddSet (BYVAL hSci AS DWORD, BYVAL nLine AS LONG, BYVAL markerMask AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_MARKERADDSET, nLine, markerMask)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MarkerAddSet (BYVAL pSci AS DWORD, BYVAL nLine AS LONG, BYVAL markerMask AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_MARKERADDSET, nLine, markerMask)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_MARKERDELETE(int line, int markerNumber)
' This searches the given line number for the given marker number and deletes it if it is
' present. If you added the same marker more than once to the line, this will delete one
' copy each time it is used. If you pass in a marker number of -1, all markers are deleted
' from the line.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_MarkerDelete (BYVAL hSci AS DWORD, BYVAL nLine AS LONG, BYVAL markerNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_MARKERDELETE, nLine, markerNumber)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MarkerDelete (BYVAL pSci AS DWORD, BYVAL nLine AS LONG, BYVAL markerNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_MARKERDELETE, nLine, markerNumber)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_MARKERDELETEALL(int markerNumber)
' This removes markers of the given number from all lines. If markerNumber is -1, it
' deletes all markers from all lines.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_MarkerDeleteAll (BYVAL hSci AS DWORD, BYVAL markerNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_MARKERDELETEALL, markerNumber, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MarkerDeleteAll (BYVAL pSci AS DWORD, BYVAL markerNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_MARKERDELETEALL, markerNumber, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_MARKERGET(int line)
' This returns a 32-bit integer that indicates which markers were present on the line. Bit
' 0 is set if marker 0 is present, bit 1 for marker 1 and so on.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_MarkerGet (BYVAL hSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_MARKERGET, nLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MarkerGet (BYVAL pSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_MARKERGET, nLine, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_MARKERNEXT(int lineStart, int markerMask)
' SCI_MARKERPREVIOUS(int lineStart, int markerMask)
' These messages search efficiently for lines that include a given set of markers. The
' search starts at line number lineStart and continues forwards to the end of the file
' (SCI_MARKERNEXT) or backwards to the start of the file (SCI_MARKERPREVIOUS). The
' markerMask argument should have one bit set for each marker you wish to find. Set bit 0
' to find marker 0, bit 1 for marker 1 and so on. The message returns the line number of
' the first line that contains one of the markers in markerMask or -1 if no marker is found.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_MarkerNext (BYVAL hSci AS DWORD, BYVAL lineStart AS LONG, BYVAL markerMask AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_MARKERNEXT, lineStart, markerMask)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MarkerNext (BYVAL pSci AS DWORD, BYVAL lineStart AS LONG, BYVAL markerMask AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_MARKERNEXT, lineStart, markerMask)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_MarkerPrevious (BYVAL hSci AS DWORD, BYVAL lineStart AS LONG, BYVAL markerMask AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_MARKERPREVIOUS, lineStart, markerMask)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MarkerPrevious (BYVAL pSci AS DWORD, BYVAL lineStart AS LONG, BYVAL markerMask AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_MARKERPREVIOUS, lineStart, markerMask)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_MARKERLINEFROMHANDLE(int markerHandle)
' The markerHandle argument is an identifier for a marker returned by SCI_MARKERADD. This
' function searches the document for the marker with this handle and returns the line
' number that contains it or -1 if it is not found.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_MarkerLineFromHandle (BYVAL hSci AS DWORD, BYVAL markerHandle AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_MARKERLINEFROMHANDLE, markerHandle, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MarkerLineFromHandle (BYVAL pSci AS DWORD, BYVAL markerHandle AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_MARKERLINEFROMHANDLE, markerHandle, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_MARKERDELETEHANDLE(int markerHandle)
' The markerHandle argument is an identifier for a marker returned by SCI_MARKERADD. This
' function searches the document for the marker with this handle and deletes the marker if
' it is found.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_MarkerDeleteHandle (BYVAL hSci AS DWORD, BYVAL markerHandle AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_MARKERDELETEHANDLE, markerHandle, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MarkerDeleteHandle (BYVAL pSci AS DWORD, BYVAL markerHandle AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_MARKERDELETEHANDLE, markerHandle, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                       Indicators
' ########################################################################################

' ========================================================================================
' SCI_INDICSETSTYLE(int indicatorNumber, int indicatorStyle)
' SCI_INDICGETSTYLE(int indicatorNumber)
' These two messages set and get the style for a particular indicator.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_IndicSetStyle (BYVAL hSci AS DWORD, BYVAL indicatorNumber AS LONG, BYVAL indicatorStyle AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_INDICSETSTYLE, indicatorNumber, indicatorStyle)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_IndicSetStyle (BYVAL pSci AS DWORD, BYVAL indicatorNumber AS LONG, BYVAL indicatorStyle AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_INDICSETSTYLE, indicatorNumber, indicatorStyle)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_IndicGetStyle (BYVAL hSci AS DWORD, BYVAL indicatorNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_INDICGETSTYLE, indicatorNumber, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_IndicGetStyle (BYVAL pSci AS DWORD, BYVAL indicatorNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_INDICGETSTYLE, indicatorNumber, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_INDICSETFORE(int indicatorNumber, int colour)
' SCI_INDICGETFORE(int indicatorNumber)
' These two messages set and get the colour used to draw an indicator.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_IndicSetFore (BYVAL hSci AS DWORD, BYVAL indicatorNumber AS LONG, BYVAL colour AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_INDICSETFORE, indicatorNumber, colour)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_IndicSetFore (BYVAL pSci AS DWORD, BYVAL indicatorNumber AS LONG, BYVAL colour AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_INDICSETFORE, indicatorNumber, colour)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_IndicGetFore (BYVAL hSci AS DWORD, BYVAL indicatorNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_INDICGETFORE, indicatorNumber, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_IndicGetFore (BYVAL pSci AS DWORD, BYVAL indicatorNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_INDICGETFORE, indicatorNumber, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' These two messages set and get the alpha transparency used for drawing the outline colour
' of the INDIC_ROUNDBOX and INDIC_STRAIGHTBOX rectangle. The alpha value can range from 0
' (completely transparent) to 255 (no transparency).
' ========================================================================================
' ========================================================================================
FUNCTION SCI_IndicSetOutlineAlpha (BYVAL hSci AS DWORD, BYVAL indicatorNumber AS LONG, BYVAL alpha AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_INDICSETOUTLINEALPHA, indicatorNumber, alpha)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_IndicSetOutlineAlpha (BYVAL pSci AS DWORD, BYVAL indicatorNumber AS LONG, BYVAL alpha AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_INDICSETOUTLINEALPHA, indicatorNumber, alpha)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_IndicGetOutlineAlpha (BYVAL hSci AS DWORD, BYVAL indicatorNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_INDICGETOUTLINEALPHA, indicatorNumber, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_IndicGetOutlineAlpha (BYVAL pSci AS DWORD, BYVAL indicatorNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_INDICGETOUTLINEALPHA, indicatorNumber, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_INDICSETALPHA(int indicatorNumber, int alpha)
' SCI_INDICGETALPHA(int indicatorNumber)
' These two messages set and get the alpha transparency used for drawing the fill color of
' the INDIC_ROUNDBOX rectangle. The alpha value can range from 0 (completely transparent)
' to 255 (no transparency).
' ========================================================================================
' ========================================================================================
FUNCTION SCI_IndicSetAlpha (BYVAL hSci AS DWORD, BYVAL indicatorNumber AS LONG, BYVAL alpha AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_INDICSETALPHA, indicatorNumber, alpha)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_IndicSetAlpha (BYVAL pSci AS DWORD, BYVAL indicatorNumber AS LONG, BYVAL alpha AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_INDICSETALPHA, indicatorNumber, alpha)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_IndicGetAlpha (BYVAL hSci AS DWORD, BYVAL indicatorNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_INDICGETALPHA, indicatorNumber, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_IndicGetAlpha (BYVAL pSci AS DWORD, BYVAL indicatorNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_INDICGETALPHA, indicatorNumber, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_INDICSETUNDER(int indicatorNumber, bool under)
' SCI_INDICGETUNDER(int indicatorNumber)
' These two messages set and get whether an indicator is drawn under text or over(default).
' Drawing under text works only for modern indicators when two phase drawing is enabled.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_IndicSetUnder (BYVAL hSci AS DWORD, BYVAL indicatorNumber AS LONG, BYVAL under AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_INDICSETUNDER, indicatorNumber, under)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_IndicSetUnder (BYVAL pSci AS DWORD, BYVAL indicatorNumber AS LONG, BYVAL under AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_INDICSETUNDER, indicatorNumber, under)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_IndicGetUnder (BYVAL hSci AS DWORD, BYVAL indicatorNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_INDICGETUNDER, indicatorNumber, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_IndicGetUnder (BYVAL pSci AS DWORD, BYVAL indicatorNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_INDICGETUNDER, indicatorNumber, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_INDICSETHOVERSTYLE(int indicatorNumber, int indicatorStyle)
' SCI_INDICGETHOVERSTYLE(int indicatorNumber)
' SCI_INDICSETHOVERFORE(int indicatorNumber, int colour)
' SCI_INDICGETHOVERFORE(int indicatorNumber)
' These messages set and get the colour and style used to draw indicators when the mouse
' is over them or the caret moved into them. The mouse cursor also changes when an indicator
' is drawn in hover style. The default is for the hover appearance to be the same as the
' normal appearance and calling SCI_INDICSETFORE or SCI_INDICSETSTYLE will also reset the
' hover attribute.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_IndicSetHoverStyle (BYVAL hSci AS DWORD, BYVAL indicatorNumber AS LONG, BYVAL indicatorStyle AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_INDICSETHOVERSTYLE, indicatorNumber, indicatorStyle)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_IndicSetHoverStyle (BYVAL pSci AS DWORD, BYVAL indicatorNumber AS LONG, BYVAL indicatorStyle AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_INDICSETHOVERSTYLE, indicatorNumber, indicatorStyle)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_IndicGetHoverStyle (BYVAL hSci AS DWORD, BYVAL indicatorNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_INDICGETHOVERSTYLE, indicatorNumber, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_IndicGetHoverStyle (BYVAL pSci AS DWORD, BYVAL indicatorNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_INDICGETHOVERSTYLE, indicatorNumber, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_IndicSetHoverFore (BYVAL hSci AS DWORD, BYVAL indicatorNumber AS LONG, BYVAL colour AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_INDICSETHOVERFORE, indicatorNumber, colour)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_IndicSetHoverFore (BYVAL pSci AS DWORD, BYVAL indicatorNumber AS LONG, BYVAL colour AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_INDICSETHOVERFORE, indicatorNumber, colour)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_IndicGetHoverFore (BYVAL hSci AS DWORD, BYVAL indicatorNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_INDICGETHOVERFORE, indicatorNumber, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_IndicGetHoverFore (BYVAL pSci AS DWORD, BYVAL indicatorNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_INDICGETHOVERFORE, indicatorNumber, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_INDICSETFLAGS(int indicatorNumber, int flags)
' SCI_INDICGETFLAGS(int indicatorNumber)
' These messages set and get the flags associated with an indicator. There is currently
' one flag defined, SC_INDICFLAG_VALUEFORE: when this flag is set the colour used by the
' indicator is not from the indicator's fore setting but instead from the value of the
' indicator at that point in the file. This allows many colours to be displayed for a
' single indicator. The value is an RGB integer colour that has been ored with
' SC_INDICVALUEBIT(0x1000000) when calling SCI_SETINDICATORVALUE. To find the colour from
' the value, and the value with SC_INDICVALUEMASK(0xFFFFFF).
' ========================================================================================
' ========================================================================================
FUNCTION SCI_IndicSetFlags (BYVAL hSci AS DWORD, BYVAL indicatorNumber AS LONG, BYVAL flags AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_INDICSETFLAGS, indicatorNumber, flags)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_IndicSetFlags (BYVAL pSci AS DWORD, BYVAL indicatorNumber AS LONG, BYVAL flags AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_INDICSETFLAGS, indicatorNumber, flags)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_IndicGetFlags (BYVAL hSci AS DWORD, BYVAL indicatorNumber AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_INDICGETFLAGS, indicatorNumber, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_IndicGetFlags (BYVAL pSci AS DWORD, BYVAL indicatorNumber AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_INDICGETFLAGS, indicatorNumber, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                    Modern indicators
' ########################################################################################

' ========================================================================================
' SCI_SETINDICATORCURRENT(int indicator)
' SCI_GETINDICATORCURRENT
' These two messages set and get the indicator that will be affected by calls to
' SCI_INDICATORFILLRANGE and SCI_INDICATORCLEARRANGE.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetIndicatorCurrent (BYVAL hSci AS DWORD, BYVAL indicator AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETINDICATORCURRENT, indicator, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetIndicatorCurrent (BYVAL pSci AS DWORD, BYVAL indicator AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETINDICATORCURRENT, indicator, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetIndicatorCurrent (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETINDICATORCURRENT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetIndicatorCurrent (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETINDICATORCURRENT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETINDICATORVALUE(int value)
' SCI_GETINDICATORVALUE
' These two messages set and get the value that will be set by calls to SCI_INDICATORFILLRANGE.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetIndicatorValue (BYVAL hSci AS DWORD, BYVAL value AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETINDICATORVALUE, value, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetIndicatorValue (BYVAL pSci AS DWORD, BYVAL value AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETINDICATORVALUE, value, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetIndicatorValue (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETINDICATORVALUE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetIndicatorValue (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETINDICATORVALUE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_INDICATORFILLRANGE(int position, int fillLength)
' SCI_INDICATORCLEARRANGE(int position, int clearLength)
' These two messages fill or clear a range for the current indicator.
' SCI_INDICATORFILLRANGE fills with the the current value.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_IndicatorFillRange (BYVAL hSci AS DWORD, BYVAL position AS LONG, BYVAL fillLength AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_INDICATORFILLRANGE, position, fillLength)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_IndicatorFillRange (BYVAL pSci AS DWORD, BYVAL position AS LONG, BYVAL fillLength AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_INDICATORFILLRANGE, position, fillLength)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_IndicatorClearRange (BYVAL hSci AS DWORD, BYVAL position AS LONG, BYVAL clearLength AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_INDICATORCLEARRANGE, position, clearLength)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_IndicatorClearRange (BYVAL pSci AS DWORD, BYVAL position AS LONG, BYVAL clearLength AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_INDICATORCLEARRANGE, position, clearLength)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_INDICATORALLONFOR(int position)
' Retrieve a bitmap value representing which indicators are non-zero at a position.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_IndicatorAllOnFor (BYVAL hSci AS DWORD, BYVAL position AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETINDICATORVALUE, position, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_IndicatorAllOnFor (BYVAL pSci AS DWORD, BYVAL position AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETINDICATORVALUE, position, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_INDICATORVALUEAT(int indicator, int position)
' Retrieve the value of a particular indicator at a position.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_IndicatorValueAt (BYVAL hSci AS DWORD, BYVAL indicator AS LONG, BYVAL position AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_INDICATORVALUEAT, indicator, position)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_IndicatorValueAt (BYVAL pSci AS DWORD, BYVAL indicator AS LONG, BYVAL position AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_INDICATORVALUEAT, indicator, position)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_INDICATORSTART(int indicator, int position)
' SCI_INDICATOREND(int indicator, int position)
' Find the start or end of a range with one value from a position within the range. Can be
' used to iterate through the document to discover all the indicator positions.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_IndicatorStart (BYVAL hSci AS DWORD, BYVAL indicator AS LONG, BYVAL position AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_INDICATORSTART, indicator, position)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_IndicatorStart (BYVAL pSci AS DWORD, BYVAL indicator AS LONG, BYVAL position AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_INDICATORSTART, indicator, position)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_IndicatorEnd (BYVAL hSci AS DWORD, BYVAL indicator AS LONG, BYVAL position AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_INDICATOREND, indicator, position)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_IndicatorEnd (BYVAL pSci AS DWORD, BYVAL indicator AS LONG, BYVAL position AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_INDICATOREND, indicator, position)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                      Autocompletion
' ########################################################################################

' ========================================================================================
' SCI_AUTOCSHOW(int lenEntered, const char *list)
' This message causes a list to be displayed. lenEntered is the number of characters of
' the word already entered and list is the list of words separated by separator characters.
' The initial separator character is a space but this can be set or got with
' SCI_AUTOCSETSEPARATOR and SCI_AUTOCGETSEPARATOR.
' The list of words should be in sorted order. If set to ignore case mode with
' SCI_AUTOCSETIGNORECASE, then strings are matched after being converted to upper case.
' One result of this is that the list should be sorted with the punctuation characters
' '[', '\', ']', '^', '_', and '`' sorted after letters.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocShow (BYVAL hSci AS DWORD, BYVAL lenEntered AS LONG, BYVAL strList AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCSHOW, lenEntered, STRPTR(strList))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocShow (BYVAL pSci AS DWORD, BYVAL lenEntered AS LONG, BYVAL strList AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCSHOW, lenEntered, STRPTR(strList))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_AUTOCCANCEL
' This message cancels any displayed autocompletion list. When in autocompletion mode, the
' list should disappear when the user types a character that can not be part of the
' autocompletion, such as '.', '(' or '[' when typing an identifier. A set of characters
' that will cancel autocompletion can be specified with SCI_AUTOCSTOPS.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocCancel (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCCANCEL, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocCancel (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCCANCEL, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_AUTOCACTIVE
' This message returns non-zero if there is an active autocompletion list and zero if there is not.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocActive (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCACTIVE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocActive (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCACTIVE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_AUTOCPOSSTART
' This returns the value of the current position when SCI_AUTOCSHOW started display of the list.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocPosStart (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCPOSSTART, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocPosStart (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCPOSSTART, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_AUTOCCOMPLETE
' This message triggers autocompletion. This has the same effect as the tab key.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocComplete (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCCOMPLETE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocComplete (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCCOMPLETE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_AUTOCSTOPS(<unused>, const char *chars)
' The chars argument is a string containing a list of characters that will automatically
' cancel the autocompletion list. When you start the editor, this list is empty.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocStops (BYVAL hSci AS DWORD, BYVAL strChars AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCSTOPS, 0, STRPTR(strChars))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocStops (BYVAL pSci AS DWORD, BYVAL strChars AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCSTOPS, 0, STRPTR(strChars))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_AUTOCSETSEPARATOR(char separator)
' SCI_AUTOCGETSEPARATOR
' These two messages set and get the separator character used to separate words in the
' SCI_AUTOCSHOW list. The default is the space character.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocSetSeparator (BYVAL hSci AS DWORD, BYVAL strSeparator AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCSETSEPARATOR, ASC(strSeparator), 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocSetSeparator (BYVAL pSci AS DWORD, BYVAL strSeparator AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCSETSEPARATOR, ASC(strSeparator), 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocGetSeparator (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCGETSEPARATOR, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocGetSeparator (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCGETSEPARATOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_AUTOCSELECT(<unused>, const char *select)
' SCI_AUTOCGETCURRENT
' This message selects an item in the autocompletion list. It searches the list of words
' for the first that matches select. By default, comparisons are case sensitive, but you
' can change this with SCI_AUTOCSETIGNORECASE. The match is character by character for the
' length of the select string. That is, if select is "Fred" it will match "Frederick" if
' this is the first item in the list that begins with "Fred". If an item is found, it is
' selected. If the item is not found, the autocompletion list closes if auto-hide is true
' (see SCI_AUTOCSETAUTOHIDE).
' The current selection index can be retrieved with SCI_AUTOCGETCURRENT.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocSelect (BYVAL hSci AS DWORD, BYVAL strSelect AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCSELECT, 0, STRPTR(strSelect))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocSelect (BYVAL pSci AS DWORD, BYVAL strSelect AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCSELECT, 0, STRPTR(strSelect))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocGetCurrent (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCGETCURRENT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocGetCurrent (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCGETCURRENT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_AUTOCGETCURRENTTEXT(<unused>, char *text)
' This message retrieves the current selected text in the autocompletion list. Normally the
' SCN_AUTOCSELECTION notification is used instead.
' The value is copied to the text buffer, returning the length (not including the
' terminating 0). If not found, an empty string is copied to the buffer and 0 is returned.
' If the value argument is 0 then the length that should be allocated to store the value
' is returned; again, the terminating 0 is not included.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocGetCurrentText (BYVAL hSci AS DWORD) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = SendMessageA(hSci, %SCI_AUTOCGETCURRENTTEXT, 0, 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen + 1)
   SendMessageA(hSci, %SCI_AUTOCGETCURRENTTEXT, 0, STRPTR(buffer))
   FUNCTION = REMOVE$(buffer, CHR$(0))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocGetCurrentText (BYVAL pSci AS DWORD) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = Scintilla_DirectFunction(pSci, %SCI_AUTOCGETCURRENTTEXT, 0, 0)
   buffer = SPACE$(nLen + 1)
   Scintilla_DirectFunction(pSci, %SCI_AUTOCGETCURRENTTEXT, 0, STRPTR(buffer))
   FUNCTION = REMOVE$(buffer, CHR$(0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_AUTOCSETCANCELATSTART(bool cancel)
' SCI_AUTOCGETCANCELATSTART
' The default behavior is for the list to be cancelled if the caret moves before the
' location it was at when the list was displayed. By calling this message with a false
' argument, the list is not cancelled until the caret moves before the first character of
' the word being completed.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocSetCancelStart (BYVAL hSci AS DWORD, BYVAL bCancel AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCSETCANCELATSTART, bCancel, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocSetCancelStart (BYVAL pSci AS DWORD, BYVAL bCancel AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCSETCANCELATSTART, bCancel, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocGetCancelStart (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCGETCANCELATSTART, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocGetCancelStart (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCGETCANCELATSTART, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_AUTOCSETFILLUPS(<unused>, const char *chars)
' If a fillup character is typed with an autocompletion list active, the currently
' selected item in the list is added into the document, then the fillup character is added.
' Common fillup characters are '(', '[' and '.' but others are possible depending on the
' language. By default, no fillup characters are set.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocFillUps (BYVAL hSci AS DWORD, BYVAL strChars AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCSETFILLUPS, 0, STRPTR(strChars))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocFillUps (BYVAL pSci AS DWORD, BYVAL strChars AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCSETFILLUPS, 0, STRPTR(strChars))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_AUTOCSETCHOOSESINGLE(bool chooseSingle)
' SCI_AUTOCGETCHOOSESINGLE
' If you use SCI_AUTOCSETCHOOSESINGLE(1) and a list has only one item, it is automatically
' added and no list is displayed. The default is to display the list even if there is only
' a single item.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocSetChooseSingle (BYVAL hSci AS DWORD, BYVAL chooseSingle AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCSETCHOOSESINGLE, chooseSingle, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocSetChooseSingle (BYVAL pSci AS DWORD, BYVAL chooseSingle AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCSETCHOOSESINGLE, chooseSingle, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocGetChooseSingle (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCGETCHOOSESINGLE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocGetChooseSingle (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCGETCHOOSESINGLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_AUTOCSETIGNORECASE(bool ignoreCase)
' SCI_AUTOCGETIGNORECASE
' By default, matching of characters to list members is case sensitive. These messages let
' you set and get case sensitivity.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocSetIgnoreCase (BYVAL hSci AS DWORD, BYVAL ignoreCase AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCSETIGNORECASE, ignoreCase, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocSetIgnoreCase (BYVAL pSci AS DWORD, BYVAL ignoreCase AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCSETIGNORECASE, ignoreCase, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocGetIgnoreCase (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCGETIGNORECASE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocGetIgnoreCase (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCGETIGNORECASE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_AUTOCSETCASEINSENSITIVEBEHAVIOUR(int behaviour)
' SCI_AUTOCGETCASEINSENSITIVEBEHAVIOUR
' When autocompletion is set to ignore case (SCI_AUTOCSETIGNORECASE), by default it will
' nonetheless select the first list member that matches in a case sensitive way to entered
' characters. This corresponds to a behaviour property of SC_CASEINSENSITIVEBEHAVIOUR_RESPECTCASE (0).
' If you want autocompletion to ignore case at all, choose SC_CASEINSENSITIVEBEHAVIOUR_IGNORECASE (1).
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocSetCaseInsensitiveBehaviour (BYVAL hSci AS DWORD, BYVAL behaviour AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCSETCASEINSENSITIVEBEHAVIOUR, behaviour, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocSetCaseInsensitiveBehaviour (BYVAL pSci AS DWORD, BYVAL behaviour AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCSETCASEINSENSITIVEBEHAVIOUR, behaviour, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocGetCaseInsensitiveBehaviour (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCGETCASEINSENSITIVEBEHAVIOUR, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocGetCaseInsensitiveBehaviour (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCGETCASEINSENSITIVEBEHAVIOUR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_AUTOCSETMULTI(int multi)
' SCI_AUTOCGETMULTI
' When autocompleting with multiple selections present, the autocompleted text can go into
' just the main selection with SC_MULTIAUTOC_ONCE (0) or into each selection with
' SC_MULTIAUTOC_EACH (1). The default is SC_MULTIAUTOC_ONCE.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocSetMulti (BYVAL hSci AS DWORD, BYVAL multi AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCSETMULTI, multi, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocSetMulti (BYVAL pSci AS DWORD, BYVAL multi AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCSETMULTI, multi, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocGetMulti (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCGETMULTI, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocGetMulti (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCGETMULTI, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_AUTOCSETORDER(int order)
' SCI_AUTOCGETORDER
' The default setting SC_ORDER_PRESORTED (0) requires that the list be provided in
' alphabetical sorted order.
' Sorting the list can be done by Scintilla instead of the application with
' SC_ORDER_PERFORMSORT (1). This will take additional time.
' Applications that wish to prioritize some values and show the list in order of priority
' instead of alphabetical order can use SC_ORDER_CUSTOM (2). This requires extra processing
' in SCI_AUTOCSHOW to create a sorted index.
' Setting the order should be done before calling SCI_AUTOCSHOW.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocSetOrder (BYVAL hSci AS DWORD, BYVAL order AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCSETORDER, order, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocSetOrder (BYVAL pSci AS DWORD, BYVAL order AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCSETORDER, order, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocGetOrder (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCGETORDER, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocGetOrder (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCGETORDER, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_AUTOCSETAUTOHIDE(bool autoHide)
' SCI_AUTOCGETAUTOHIDE
' By default, the list is cancelled if there are no viable matches (the user has typed
' characters that no longer match a list entry). If you want to keep displaying the
' original list, set autoHide to false. This also effects SCI_AUTOCSELECT.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocSetAutoHide (BYVAL hSci AS DWORD, BYVAL autoHide AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCSETAUTOHIDE, autoHide, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocSetAutoHide (BYVAL pSci AS DWORD, BYVAL autoHide AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCSETAUTOHIDE, autoHide, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocGetAutoHide (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCGETAUTOHIDE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocGetAutoHide (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCGETAUTOHIDE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_AUTOCSETDROPRESTOFWORD(bool dropRestOfWord)
' SCI_AUTOCGETDROPRESTOFWORD
' When an item is selected, any word characters following the caret are first erased if
' dropRestOfWord is set true. The default is false.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocSetDropRestOfWord (BYVAL hSci AS DWORD, BYVAL dropRestOfWord AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCSETDROPRESTOFWORD, dropRestOfWord, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocSetDropRestOfWord (BYVAL pSci AS DWORD, BYVAL dropRestOfWord AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCSETDROPRESTOFWORD, dropRestOfWord, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocGetDropRestOfWord (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCGETDROPRESTOFWORD, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocGetDropRestOfWord (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCGETDROPRESTOFWORD, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_REGISTERIMAGE(int type, const char *xpmData)
' SCI_REGISTERRGBAIMAGE(int type, const char *pixels)
' SCI_CLEARREGISTEREDIMAGES
' SCI_AUTOCSETTYPESEPARATOR(char separatorCharacter)
' SCI_AUTOCGETTYPESEPARATOR
' Autocompletion list items may display an image as well as text. Each image is first
' registered with an integer type. Then this integer is included in the text of the list
' separated by a '?' from the text. For example, "fclose?2 fopen" displays image 2 before
' the string "fclose" and no image before "fopen". The images are in either the XPM format
' (SCI_REGISTERIMAGE) or RGBA format (SCI_REGISTERRGBAIMAGE). For SCI_REGISTERRGBAIMAGE
' the width and height must previously been set with the SCI_RGBAIMAGESETWIDTH and
' SCI_RGBAIMAGESETHEIGHT messages. The set of registered images can be cleared with
' SCI_CLEARREGISTEREDIMAGES and the '?' separator changed with SCI_AUTOCSETTYPESEPARATOR.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_RegisterImage (BYVAL hSci AS DWORD, BYVAL nType AS LONG, BYVAL xpmData AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_REGISTERIMAGE, nType, STRPTR(xpmData))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_RegisterImage (BYVAL pSci AS DWORD, BYVAL nType AS LONG, BYVAL xpmData AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_REGISTERIMAGE, nType, STRPTR(xpmData))
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_RegisterRGBAImage (BYVAL hSci AS DWORD, BYVAL nType AS LONG, BYVAL pixs AS BYTE PTR) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_REGISTERRGBAIMAGE, nType, pixs)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_RegisterRGBAImage (BYVAL pSci AS DWORD, BYVAL nType AS LONG, BYVAL pixs AS BYTE PTR) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_REGISTERRGBAIMAGE, nType, pixs)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_ClearRegisteredImages (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CLEARREGISTEREDIMAGES, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ClearRegisteredImages (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CLEARREGISTEREDIMAGES, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_AutocSetTypeSeparator (BYVAL hSci AS DWORD, BYVAL separatorCharacter AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCSETTYPESEPARATOR, separatorCharacter, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocSetTypeSeparator (BYVAL pSci AS DWORD, BYVAL separatorCharacter AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCSETTYPESEPARATOR, separatorCharacter, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocGetTypeSeparator (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCGETTYPESEPARATOR, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocGetTypeSeparator (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCGETTYPESEPARATOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_AUTOCSETMAXHEIGHT(int rowCount)
' SCI_AUTOCGETMAXHEIGHT
' Get or set the maximum number of rows that will be visible in an autocompletion list. If
' there are more rows in the list, then a vertical scrollbar is shown. The default is 5.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocSetMaxHeight (BYVAL hSci AS DWORD, BYVAL rowCount AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCSETMAXHEIGHT, rowCount, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocSetMaxHeight (BYVAL pSci AS DWORD, BYVAL rowCount AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCSETMAXHEIGHT, rowCount, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocGetMaxHeight (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCGETMAXHEIGHT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocGetMaxHeight (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCGETMAXHEIGHT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_AUTOCSETMAXWIDTH(int characterCount)
' SCI_AUTOCGETMAXWIDTH
' Get or set the maximum width of an autocompletion list expressed as the number of
' characters in the longest item that will be totally visible. If zero (the default) then
' the list's width is calculated to fit the item with the most characters. Any items that
' cannot be fully displayed within the available width are indicated by the presence of
' ellipsis.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocSetMaxWidth (BYVAL hSci AS DWORD, BYVAL characterCount AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCSETMAXWIDTH, characterCount, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocSetMaxWidth (BYVAL pSci AS DWORD, BYVAL characterCount AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCSETMAXWIDTH, characterCount, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AutocGetMaxWidth (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_AUTOCGETMAXWIDTH, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AutocGetMaxWidth (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_AUTOCGETMAXWIDTH, 0, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                       User Lists
' ########################################################################################

' ========================================================================================
' SCI_USERLISTSHOW(int listType, const char *list)
' The listType parameter is returned to the container as the wParam field of the
' SCNotification structure. It must be greater than 0 as this is how Scintilla tells the
' difference between an autocompletion list and a user list. If you have different types
' of list, for example a list of buffers and a list of macros, you can use listType to
' tell which one has returned a selection.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_UserListShow (BYVAL hSci AS DWORD, BYVAL listType AS LONG, BYVAL strList AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_USERLISTSHOW, listType, STRPTR(strList))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_UserListShow (BYVAL pSci AS DWORD, BYVAL listType AS LONG, BYVAL strList AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_USERLISTSHOW, listType, STRPTR(strList))
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                         Call Tips
' ########################################################################################

' ========================================================================================
' SCI_CALLTIPSHOW(int posStart, const char *definition)
' This message starts the process by displaying the call tip window. If a call tip is
' already active, this has no effect. posStart is the position in the document at which to
' align the call tip. The call tip text is aligned to start 1 line below this character
' unless you have included up and/or down arrows in the call tip text in which case the
' tip is aligned to the right-hand edge of the rightmost arrow. The assumption is that you
' will start the text with something like "\001 1 of 3 \002". ' definition is the call tip
' text. This can contain multiple lines separated by '\n' (Line Feed, ASCII code 10)
' characters. Do not include '\r' (Carriage Return, ASCII code 13), as this will most
' likely print as an empty box. '\t' (Tab, ASCII code 9) is supported if you set a tabsize
' with SCI_CALLTIPUSESTYLE.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_CallTipShow (BYVAL hSci AS DWORD, BYVAL posStart AS LONG, BYVAL strDefinition AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CALLTIPSHOW, posStart, STRPTR(strDefinition))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CallTipShow (BYVAL pSci AS DWORD, BYVAL posStart AS LONG, BYVAL strDefinition AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CALLTIPSHOW, posStart, STRPTR(strDefinition))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_CALLTIPCANCEL
' This message cancels any displayed call tip. Scintilla will also cancel call tips for
' you if you use any keyboard commands that are not compatible with editing the argument
' list of a function.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_CallTipCancel (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CALLTIPCANCEL, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CallTipCancel (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CALLTIPCANCEL, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_CALLTIPACTIVE
' This returns 1 if a call tip is active and 0 if it is not active.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_CallTipActive (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CALLTIPACTIVE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CallTipActive (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CALLTIPACTIVE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_CALLTIPPOSSTART
' This message returns the value of the current position when SCI_CALLTIPSHOW started to
' display the tip.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_CallTipPosStart (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CALLTIPPOSSTART, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CallTipPosStart (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CALLTIPPOSSTART, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_CALLTIPSETPOSSTART (int posStart)
' This message sets the value of the current position when SCI_CALLTIPSHOW started to
' display the tip.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_CallTipSetPosStart (BYVAL hSci AS DWORD, BYVAL posStart AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CALLTIPSETPOSSTART, posStart, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CallTipSetPosStart (BYVAL pSci AS DWORD, BYVAL posStart AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CALLTIPSETPOSSTART, posStart, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_CALLTIPSETHLT(int hlStart, int hlEnd)
' This sets the region of the call tips text to display in a highlighted style. hlStart is
' the zero-based index into the string of the first character to highlight and hlEnd is the
' index of the first character after the highlight. hlEnd must be greater than hlStart;
' hlEnd-hlStart is the number of characters to highlight. Highlights can extend over line
' ends if this is required.
' Unhighlighted text is drawn in a mid gray. Selected text is drawn in a dark blue. The
' background is white. These can be changed with SCI_CALLTIPSETBACK, SCI_CALLTIPSETFORE,
' and SCI_CALLTIPSETFOREHLT.
' ========================================================================================
FUNCTION SCI_CallTipSetHlt (BYVAL hSci AS DWORD, BYVAL hlStart AS LONG, BYVAL hlEnd AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CALLTIPSETHLT, hlStart, hlEnd)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CallTipSetHlt (BYVAL pSci AS DWORD, BYVAL hlStart AS LONG, BYVAL hlEnd AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CALLTIPSETHLT, hlStart, hlEnd)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_CALLTIPSETBACK(int colour)
' The background colour of call tips can be set with this message; the default colour is
' white. It is not a good idea to set a dark colour as the background as the default
' colour for normal calltip text is mid gray and the defaultcolour for highlighted text is
' dark blue. This also sets the background colour of STYLE_CALLTIP.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_CallTipSetBack (BYVAL hSci AS DWORD, BYVAL colour AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CALLTIPSETBACK, colour, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CallTipSetBack (BYVAL pSci AS DWORD, BYVAL colour AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CALLTIPSETBACK, colour, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_CALLTIPSETFORE(int colour)
' The colour of call tip text can be set with this message; the default colour is mid gray.
' This also sets the foreground colour of STYLE_CALLTIP.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_CallTipSetFore (BYVAL hSci AS DWORD, BYVAL colour AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CALLTIPSETFORE, colour, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CallTipSetFore (BYVAL pSci AS DWORD, BYVAL colour AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CALLTIPSETFORE, colour, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_CALLTIPSETFOREHLT(int colour)
' The colour of highlighted call tip text can be set with this message; the default colour
' is dark blue.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_CallTipSetForeHlt (BYVAL hSci AS DWORD, BYVAL colour AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CALLTIPSETFOREHLT, colour, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CallTipSetForeHlt (BYVAL pSci AS DWORD, BYVAL colour AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CALLTIPSETFOREHLT, colour, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_CALLTIPUSESTYLE(int tabsize)
' This message changes the style used for call tips from STYLE_DEFAULT to STYLE_CALLTIP
' and sets a tab size in screen pixels. If tabsize is less than 1, Tab characters are not
' treated specially. Once this call has been used, the call tip foreground and background
' colours are also taken from the style.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_CallTipUseStyle (BYVAL hSci AS DWORD, BYVAL tabsize AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CALLTIPUSESTYLE, tabsize, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CallTipUseStyle (BYVAL pSci AS DWORD, BYVAL tabsize AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CALLTIPUSESTYLE, tabsize, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' By default the calltip is displayed below the text, setting above to true (1) will
' display it above the text.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_CallTipSetPosition (BYVAL hSci AS DWORD, BYVAL above AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CALLTIPSETPOSITION, above, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CallTipSetPosition (BYVAL pSci AS DWORD, BYVAL above AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CALLTIPSETPOSITION, above, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                   Keyboard Commands
' ########################################################################################

' ========================================================================================
' To allow the container application to perform any of the actions available to the user
' with keyboard, all the keyboard actions are messages. They do not take any parameters.
' These commands are also used when redefining the key bindings with the SCI_ASSIGNCMDKEY
' message.
' ========================================================================================

' ========================================================================================
FUNCTION SCI_LineDown (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LINEDOWN, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LineDown (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LINEDOWN, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_LineDownExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LINEDOWNEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LineDownExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LINEDOWNEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_LineDownRectExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LINEDOWNRECTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LineDownRectExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LINEDOWNRECTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_LineScrollDown (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LINESCROLLDOWN, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LineScrollDown (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LINESCROLLDOWN, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_LineUp (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LINEUP, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LineUp (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LINEUP, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_LineUpExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LINEUPEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LineUpExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LINEUPEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_LineUpRectExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LINEUPRECTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LineUpRectExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LINEUPRECTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_LineScrollUp (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LINESCROLLUP, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LineScrollUp (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LINESCROLLUP, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_ParaDown (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_PARADOWN, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ParaDown (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_PARADOWN, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_ParaDownExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_PARADOWNEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ParaDownExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_PARADOWNEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_ParaUp (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_PARAUP, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ParaUp (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_PARAUP, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_ParaUpExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_PARAUPEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ParaUpExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_PARAUPEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_CharLeft (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CHARLEFT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CharLeft (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CHARLEFT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_CharLeftExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CHARLEFTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CharLeftExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CHARLEFTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_CharLeftRectExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CHARLEFTRECTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CharLeftRectExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CHARLEFTRECTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_CharRight (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CHARRIGHT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CharRight (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CHARRIGHT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_CharRightExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CHARRIGHTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CharRightExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CHARRIGHTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_CharRightRectExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CHARRIGHTRECTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CharRightRectExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CHARRIGHTRECTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_WordLeft (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_WORDLEFT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_WordLeft (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_WORDLEFT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_WordLeftExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_WORDLEFTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_WordLeftExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_WORDLEFTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_WordRightExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_WORDRIGHTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_WordRightExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_WORDRIGHTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_WordLeftEnd (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_WORDLEFTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_WordLeftEnd (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_WORDLEFTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_WordLeftEndExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_WORDLEFTENDEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_WordLeftEndExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_WORDLEFTENDEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_WordRightEnd (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_WORDRIGHTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_WordRightEnd (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_WORDRIGHTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_WordRightEndExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_WORDRIGHTENDEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_WordRightEndExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_WORDRIGHTENDEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_WordPartLeft (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_WORDPARTLEFT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_WordPartLeft (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_WORDPARTLEFT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_WordPartLeftExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_WORDPARTLEFTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_WordPartLeftExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_WORDPARTLEFTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_WordPartRight (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_WORDPARTRIGHT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_WordPartRight (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_WORDPARTRIGHT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_WordPartRightExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_WORDPARTRIGHTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_WordPartRightExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_WORDPARTRIGHTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_Home (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_HOME, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_Home (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_HOME, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_HomeExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_HOMEEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_HomeExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_HOMEEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_HomeRectExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_HOMERECTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_HomeRectExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_HOMERECTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_HomeDisplay (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_HOMEDISPLAY, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_HomeDisplay (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_HOMEDISPLAY, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_HomeDisplayExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_HOMEDISPLAYEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_HomeDisplayExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_HOMEDISPLAYEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_HomeWrap (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_HOMEWRAP, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_HomeWrap (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_HOMEWRAP, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_HomeWrapExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_HOMEWRAPEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_HomeWrapExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_HOMEWRAPEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_VCHome (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_VCHOME, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_VCHome (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_VCHOME, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_VCHomeExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_VCHOMEEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_VCHomeExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_VCHOMEEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_VCHomeRectExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_VCHOMERECTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_VCHomeRectExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_VCHOMERECTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_VCHomeWrap (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_VCHOMEWRAP, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_VCHomeWrap (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_VCHOMEWRAP, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_VCHomeWrapExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_VCHOMEWRAPEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_VCHomeWrapExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_VCHOMEWRAPEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_LineEnd (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LINEEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LineEnd (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LINEEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_LineEndExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LINEENDEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LineEndExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LINEENDEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_LineEndRectExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LINEENDRECTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LineEndRectExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LINEENDRECTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_LineEndDisplay (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LINEENDDISPLAY, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LineEndRectDisplay (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LINEENDDISPLAY, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_LineEndDisplayExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LINEENDDISPLAYEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LineEndRectDisplayExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LINEENDDISPLAYEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_LineEndWrap (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LINEENDWRAP, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LineEndWrap (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LINEENDWRAP, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_LineEndWrapExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LINEENDWRAPEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LineEndWrapExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LINEENDWRAPEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_DocumentStart (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_DOCUMENTSTART, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_DocumentStart (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_DOCUMENTSTART, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_DocumentStartExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_DOCUMENTSTARTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_DocumentStartExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_DOCUMENTSTARTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_DocumentEnd (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_DOCUMENTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_DocumentEnd (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_DOCUMENTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_DocumentEndExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_DOCUMENTENDEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_DocumentEndExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_DOCUMENTENDEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_PageUp (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_PAGEUP, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_PageUp (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_PAGEUP, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_PageUpExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_PAGEUPEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_PageUpExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_PAGEUPEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_PageUpRectExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_PAGEUPRECTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_PageUpRectExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_PAGEUPRECTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_PageDown (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_PAGEDOWN, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_PageDown (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_PAGEDOWN, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_PageDownExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_PAGEDOWNEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_PageDownExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_PAGEDOWNEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_PageDownRectExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_PAGEDOWNRECTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_PageDownRectExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_PAGEDOWNRECTEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_StUtteredPageUp (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STUTTEREDPAGEUP, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StUtteredPageUp (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STUTTEREDPAGEUP, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_StUtteredPageUpExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STUTTEREDPAGEUPEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StUtteredPageUpExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STUTTEREDPAGEUPEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_StUtteredPageDownExtend (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STUTTEREDPAGEDOWNEXTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StUtteredPageDownExtend (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STUTTEREDPAGEDOWNEXTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_DeleteBack (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_DELETEBACK, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_DeleteBack (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_DELETEBACK, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_DeleteBackNotLine (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_DELETEBACKNOTLINE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_DeleteBackNotLine (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_DELETEBACKNOTLINE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_DelWordLeft (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_DELWORDLEFT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_DelWordLeft (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_DELWORDLEFT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_DelWordRight (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_DELWORDRIGHT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_DelWordRight (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_DELWORDRIGHT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_DelWordRightEnd (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_DELWORDRIGHTEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_DelWordRightEnd (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_DELWORDRIGHTEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_DelLineLeft (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_DELLINELEFT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_DelLineLeft (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_DELLINELEFT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_DelLineRight (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_DELLINERIGHT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_DelLineRight (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_DELLINERIGHT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_LineDelete (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LINEDELETE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LineDelete (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LINEDELETE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_LineCut (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LINECUT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LineCut (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LINECUT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_LineCopy (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LINECOPY, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LineCopy (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LINECOPY, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_LineTranspose (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LINETRANSPOSE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LineTranspose (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LINETRANSPOSE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_LineDuplicate (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LINEDUPLICATE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LineDuplicate (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LINEDUPLICATE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_LowerCase (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LOWERCASE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LowerCase (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LOWERCASE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_UpperCase (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_UPPERCASE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_UpperCase (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_UPPERCASE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_Cancel (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CANCEL, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_Cancel (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CANCEL, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_EditToggleOvertype (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_EDITTOGGLEOVERTYPE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_EditToggleOvertype (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_EDITTOGGLEOVERTYPE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_NewLine (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_NEWLINE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_NewLine (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_NEWLINE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_FormFeed (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_FORMFEED, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_FormFeed (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_FORMFEED, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_Tab (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_TAB, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_Tab (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_TAB, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_BackTab (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_BACKTAB, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_BackTab (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_BACKTAB, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_SelectionDuplicate (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SELECTIONDUPLICATE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SelectionDuplicate (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SELECTIONDUPLICATE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_VerticalCentreCaret (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_VERTICALCENTRECARET, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_VerticalCentreCaret (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_VERTICALCENTRECARET, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_MoveSelectedLinesUp (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_MOVESELECTEDLINESUP, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MoveSelectedLinesUp (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_MOVESELECTEDLINESUP, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_MoveSelectedLinesDown (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_MOVESELECTEDLINESDOWN, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_MoveSelectedLinesDown (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_MOVESELECTEDLINESDOWN, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_SetMouseSelectionRectangularSwitch (BYVAL hSci AS DWORD, BYVAL mouseSelectionRectangularSwitch AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETMOUSESELECTIONRECTANGULARSWITCH, mouseSelectionRectangularSwitch, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetMouseSelectionRectangularSwitch (BYVAL pSci AS DWORD, BYVAL mouseSelectionRectangularSwitch AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETMOUSESELECTIONRECTANGULARSWITCH, mouseSelectionRectangularSwitch, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_GetMouseSelectionRectangularSwtich (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETMOUSESELECTIONRECTANGULARSWITCH, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetMouseSelectionRectangularSwtich (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETMOUSESELECTIONRECTANGULARSWITCH, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_ScrollToStart (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SCROLLTOSTART, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ScrollToStart (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SCROLLTOSTART, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_ScrollToEnd (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SCROLLTOEND, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ScrollToEnd (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SCROLLTOEND, 0, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                      Key bindings
' ########################################################################################

' ========================================================================================
' SCI_ASSIGNCMDKEY(int keyDefinition, int sciCommand)
' This assigns the given key definition to a Scintilla command identified by sciCommand.
' sciCommand can be any SCI_* command that has no arguments.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AssignCmdKey (BYVAL hSci AS DWORD, BYVAL keyDefinition AS LONG, BYVAL sciCommand AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ASSIGNCMDKEY, keyDefinition, sciCommand)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AssignCmdKey (BYVAL pSci AS DWORD, BYVAL keyDefinition AS LONG, BYVAL sciCommand AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ASSIGNCMDKEY, keyDefinition, sciCommand)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_CLEARCMDKEY(int keyDefinition)
' This makes the given key definition do nothing by assigning the action SCI_NULL to it.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_ClearCmdKey (BYVAL hSci AS DWORD, BYVAL keyDefinition AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ASSIGNCMDKEY, keyDefinition, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ClearCmdKey (BYVAL pSci AS DWORD, BYVAL keyDefinition AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ASSIGNCMDKEY, keyDefinition, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_CLEARALLCMDKEYS
' This command removes all keyboard command mapping by setting an empty mapping table.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_ClearCmdKeys (BYVAL hSci AS DWORD, BYVAL keyDefinition AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CLEARCMDKEY, keyDefinition, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ClearCmdKeys (BYVAL pSci AS DWORD, BYVAL keyDefinition AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CLEARCMDKEY, keyDefinition, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_NULL
' The SCI_NULL does nothing and is the value assigned to keys that perform no action.
' SCI_NULL ensures that keys do not propagate to the parent window as that may cause focus
' to move. If you want the standard platform behaviour use the constant 0 instead.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_Null (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_NULL, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_Null (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_NULL, 0, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                     Popup edit menu
' ########################################################################################

' ========================================================================================
' SCI_USEPOPUP(bool bEnablePopup)
' Clicking the wrong button on the mouse pops up a short default editing menu. This may be
' turned off with SCI_USEPOPUP(0). If you turn it off, context menu commands (in Windows,
' WM_CONTEXTMENU) will not be handled by Scintilla, so the parent of the Scintilla window
' will have the opportunity to handle the message.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_UsePopUp (BYVAL hSci AS DWORD, BYVAL bEnablePopup AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_USEPOPUP, bEnablePopup, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_UsePopUp (BYVAL pSci AS DWORD, BYVAL bEnablePopup AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_USEPOPUP, bEnablePopup, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                    Macro recording
' ########################################################################################

' ========================================================================================
' SCI_STARTRECORD
' SCI_STOPRECORD
' These two messages turn macro recording on and off.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_StartRecord (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STARTRECORD, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StartRecord (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STARTRECORD, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_StopRecord (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_STOPRECORD, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_StopRecord (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_STOPRECORD, 0, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                       Printing
' ########################################################################################

' ========================================================================================
' On Windows SCI_FORMATRANGE can be used to draw the text onto a display context which can
' include a printer display context. Printed output shows text styling as on the screen,
' but it hides all margins except a line number margin. All special marker effects are
' removed and the selection and caret are hidden.
' ========================================================================================

' ========================================================================================
' SCI_FORMATRANGE(bool bDraw, Sci_RangeToFormat *pfr)
' This call allows Windows users to render a range of text into a device context. If you
' use this for printing, you will probably want to arrange a page header and footer;
' Scintilla does not do this for you. See SciTEWin::Print() in SciTEWinDlg.cxx for an
' example. Each use of this message renders a range of text into a rectangular area and
' returns the position in the document of the next character to print.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_FormatRange (BYVAL hSci AS DWORD, BYVAL bDraw AS BYTE, BYREF pfr AS Sci_RangeToFormat) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_FORMATRANGE, bDraw, VARPTR(pfr))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_FormatRange (BYVAL pSci AS DWORD, BYVAL bDraw AS BYTE, BYREF pfr AS Sci_RangeToFormat) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_FORMATRANGE, bDraw, VARPTR(pfr))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETPRINTMAGNIFICATION(int magnification)
' SCI_GETPRINTMAGNIFICATION
' SCI_GETPRINTMAGNIFICATION lets you to print at a different size than the screen font.
' magnification is the number of points to add to the size of each screen font. A value of
' -3 or -4 gives reasonably small print. You can get this value with SCI_GETPRINTMAGNIFICATION.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetPrintMagnification (BYVAL hSci AS DWORD, BYVAL magnification AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETPRINTMAGNIFICATION, magnification, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetPrintMagnification (BYVAL pSci AS DWORD, BYVAL magnification AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETPRINTMAGNIFICATION, magnification, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_GetPrintMagnification (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETPRINTMAGNIFICATION, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetPrintMagnification (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETPRINTMAGNIFICATION, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETPRINTCOLOURMODE(int mode)
' SCI_GETPRINTCOLOURMODE
' These two messages set and get the method used to render coloured text on a printer that
' is probably using white paper. It is especially important to consider the treatment of
' colour if you use a dark or black screen background. Printing white on black uses up
' toner and ink very many times faster than the other way around. You can set the mode to
' one of:
' Symbol                           Value  Purpose
' SC_PRINT_NORMAL                    0    Print using the current screen colours. This is the default.
' SC_PRINT_INVERTLIGHT               1    If you use a dark screen background this saves ink by inverting the light value of all colours and printing on a white background.
' SC_PRINT_BLACKONWHITE              2    Print all text as black on a white background.
' SC_PRINT_COLOURONWHITE             3    Everything prints in its own colour on a white background.
' SC_PRINT_COLOURONWHITEDEFAULTBG    4    Everything prints in its own colour on a white background except that line numbers use their own background colour.
' ========================================================================================

' ========================================================================================
FUNCTION SCI_SetPrintColourMode (BYVAL hSci AS DWORD, BYVAL nMode AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETPRINTCOLOURMODE, nMode, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetPrintColourMode (BYVAL pSci AS DWORD, BYVAL nMode AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETPRINTCOLOURMODE, nMode, 0)
END FUNCTION
' ========================================================================================

MACRO SCI_SetPrintColorMode = SCI_SetPrintColourMode
MACRO SCIP_SetPrintColorMode = SCIP_SetPrintColourMode

' ========================================================================================
FUNCTION SCI_GetPrintColourMode (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETPRINTCOLOURMODE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetPrintColourMode (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETPRINTCOLOURMODE, 0, 0)
END FUNCTION
' ========================================================================================

MACRO SCI_GetPrintColorMode = SCI_GetPrintColourMode
MACRO SCIP_GetPrintColorMode = SCIP_GetPrintColourMode

' ========================================================================================
' SCI_SETPRINTWRAPMODE(int wrapMode)
' SCI_GETPRINTWRAPMODE
' These two functions get and set the printer wrap mode. wrapMode can be set to
' SC_WRAP_NONE (0), SC_WRAP_WORD (1) or SC_WRAP_CHAR (2). The default is SC_WRAP_WORD,
' which wraps printed output so that all characters fit into the print rectangle. If you
' set SC_WRAP_NONE, each line of text generates one line of output and the line is
' truncated if it is too long to fit into the print area.
' SC_WRAP_WORD tries to wrap only between words as indicated by white space or style
' changes although if a word is longer than a line, it will be wrapped before the line end.
' SC_WRAP_CHAR is preferred to SC_WRAP_WORD for Asian languages where there is no white
' space between words.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetPrintWrapMode (BYVAL hSci AS DWORD, BYVAL nMode AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETPRINTWRAPMODE, nMode, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetPrintWrapMode (BYVAL pSci AS DWORD, BYVAL nMode AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETPRINTWRAPMODE, nMode, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_GetPrintWrapMode (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETPRINTWRAPMODE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetPrintWrapMode (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETPRINTWRAPMODE, 0, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                      Direct access
' ########################################################################################

' ========================================================================================
' SCI_GETDIRECTFUNCTION
' This message returns the address of the function to call to handle Scintilla messages
' without the overhead of passing through the Windows messaging system. You need only call
' this once, regardless of the number of Scintilla windows you create.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetDirectFunction (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETDIRECTFUNCTION, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' This returns a pointer to data that identifies which Scintilla window is in use. You
' must call this once for each Scintilla window you create. When you call the direct
' function, you must pass in the direct pointer associated with the target window.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetDirectPointer (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETDIRECTPOINTER, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETRANGEPOINTER(int position, int rangeLength)
' SCI_GETRANGEPOINTER provides direct access to just the range requested. The gap is not
' moved unless it is within the requested range so this call can be faster than
' SCI_GETCHARACTERPOINTER. This can be used by application code that is able to act on
' blocks of text or ranges of lines.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetRangePointer (BYVAL hSci AS DWORD, BYVAL nPosition AS LONG, BYVAL rangeLength AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETRANGEPOINTER, nPosition, rangeLength)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETGAPPOSITION
' SCI_GETGAPPOSITION returns the current gap position. This is a hint that applications can
' use to avoid calling SCI_GETRANGEPOINTER with a range that contains the gap and consequent
' costs of moving the gap.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetGapPosition (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETGAPPOSITION, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETCHARACTERPOINTER
' Move the gap within Scintilla so that the text of the document is stored consecutively
' and ensure there is a NUL character after the text, then return a pointer to the first
' character. Applications may then pass this to a function that accepts a character pointer
' such as a regular expression search or a parser. The pointer should not be written to as
' that may desynchronize the internal state of Scintilla.
' Since any action in Scintilla may change its internal state this pointer becomes invalid
' after any call or by allowing user interface activity. The application should reacquire
' the pointer after making any call to Scintilla or performing any user-interface calls
' such as modifying a progress indicator.
' This call takes similar time to inserting a character at the end of the document and
' this may include moving the document contents. Specifically, all the characters after
' the document gap are moved to before the gap. This compacted state should persist over
' calls and user interface actions that do not change the document contents so reacquiring
' the pointer afterwards is very quick. If this call is used to implement a global replace
' operation, then each replacement will move the gap so if SCI_GETCHARACTERPOINTER is
' called after each replacement then the operation will become O(n^2) rather than O(n).
' Instead, all matches should be found and remembered, then all the replacements performed.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetCharacterPointer (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETCHARACTERPOINTER, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetCharacterPointer (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETCHARACTERPOINTER, 0, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                     Multiple views
' ########################################################################################

' ========================================================================================
' SCI_GETDOCPOINTER
' This returns a pointer to the document currently in use by the window. It has no other
' effect.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetDocPointer (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETDOCPOINTER, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetDocPointer (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETDOCPOINTER, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETDOCPOINTER(<unused>, document *pDoc)
' This message does the following:
' 1. It removes the current window from the list held by the current document.
' 2. It reduces the reference count of the current document by 1.
' 3. If the reference count reaches 0, the document is deleted.
' 4. pDoc is set as the new document for the window.
' 5. If pDoc was 0, a new, empty document is created and attached to the window.
' 6. If pDoc was not 0, its reference count is increased by 1.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetDocPointer (BYVAL hSci AS DWORD, BYVAL pDoc AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETDOCPOINTER, 0, pDoc)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetDocPointer (BYVAL pSci AS DWORD, BYVAL pDoc AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETDOCPOINTER, 0, pDoc)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_CREATEDOCUMENT
' This message creates a new, empty document and returns a pointer to it. This document is
' not selected into the editor and starts with a reference count of 1. This means that you
' have ownership of it and must either reduce its reference count by 1 after using
' SCI_SETDOCPOINTER so that the Scintilla window owns it or you must make sure that you
' reduce the reference count by 1 with SCI_RELEASEDOCUMENT before you close the application
' to avoid memory leaks.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_CreateDocument (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CREATEDOCUMENT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_CreateDocument (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CREATEDOCUMENT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_ADDREFDOCUMENT(<unused>, document *pDoc)
' This increases the reference count of a document by 1. If you want to replace the current
' document in the Scintilla window and take ownership of the current document, for example
' if you are editing many documents in one window, do the following:
' 1. Use SCI_GETDOCPOINTER to get a pointer to the document, pDoc.
' 2. Use SCI_ADDREFDOCUMENT(0, pDoc) to increment the reference count.
' 3. Use SCI_SETDOCPOINTER(0, pNewDoc) to set a different document or SCI_SETDOCPOINTER(0, 0)
'    to set a new, empty document.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AddRefDocument (BYVAL hSci AS DWORD, BYVAL pDoc AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ADDREFDOCUMENT, 0, pDoc)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AddRefDocument (BYVAL pSci AS DWORD, BYVAL pDoc AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ADDREFDOCUMENT, 0, pDoc)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_RELEASEDOCUMENT(<unused>, document *pDoc)
' This message reduces the reference count of the document identified by pDoc. pDoc must
' be the result of SCI_GETDOCPOINTER or SCI_CREATEDOCUMENT and must point at a document
' that still exists. If you call this on a document with a reference count of 1 that is
' still attached to a Scintilla window, bad things will happen. To keep the world spinning
' in its orbit you must balance each call to SCI_CREATEDOCUMENT or SCI_ADDREFDOCUMENT with
' a call to SCI_RELEASEDOCUMENT.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_ReleaseDocument (BYVAL hSci AS DWORD, BYVAL pDoc AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_RELEASEDOCUMENT, 0, pDoc)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ReleaseDocument (BYVAL pSci AS DWORD, BYVAL pDoc AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_RELEASEDOCUMENT, 0, pDoc)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                        Folding
' ########################################################################################

' ========================================================================================
' SCI_VISIBLEFROMDOCLINE(int docLine)
' When some lines are folded, then a particular line in the document may be displayed at a
' different position to its document position. If no lines are folded, this message returns
' docLine. Otherwise, this returns the display line (counting the very first visible line
' as 0). The display line of an invisible line is the same as the previous visible line.
' The display line number of the first line in the document is 0. If there is folding and
' docLine is outside the range of lines in the document, the return value is -1. Lines can
' occupy more than one display line if they wrap.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_VisibleFromDocLine (BYVAL hSci AS DWORD, BYVAL docLine AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_VISIBLEFROMDOCLINE, 0, docLine)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_VisibleFromDocLine (BYVAL pSci AS DWORD, BYVAL docLine AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_VISIBLEFROMDOCLINE, 0, docLine)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_DOCLINEFROMVISIBLE(int displayLine)
' When some lines are hidden, then a particular line in the document may be displayed at a
' different position to its document position. This message returns the document line
' number that corresponds to a display line (counting the display line of the first line
' in the document as 0). If displayLine is less than or equal to 0, the result is 0. If
' displayLine is greater than or equal to the number of displayed lines, the result is the
' number of lines in the document.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_DeclineFromVisible (BYVAL hSci AS DWORD, BYVAL displayLine AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_DOCLINEFROMVISIBLE, 0, displayLine)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_DeclineFromVisible (BYVAL pSci AS DWORD, BYVAL displayLine AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_DOCLINEFROMVISIBLE, 0, displayLine)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SHOWLINES(int lineStart, int lineEnd)
' SCI_HIDELINES(int lineStart, int lineEnd)
' SCI_GETLINEVISIBLE(int line)
' SCI_GETALLLINESVISIBLE
' The first two messages mark a range of lines as visible or invisible and then redraw the
' display. SCI_GETLINEVISIBLE reports on the visible state of a line and returns 1 if it
' is visible and 0 if it is not visible. SCI_GETALLLINESVISIBLE returns 1 if all lines are
' visible and 0 if some lines are hidden. These messages have no effect on fold levels or
' fold flags. The first line can not be hidden.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_ShowLines (BYVAL hSci AS DWORD, BYVAL lineStart AS LONG, BYVAL lineEnd AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SHOWLINES, lineStart, lineEnd)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ShowLines (BYVAL pSci AS DWORD, BYVAL lineStart AS LONG, BYVAL lineEnd AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SHOWLINES, lineStart, lineEnd)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_HideLines (BYVAL hSci AS DWORD, BYVAL lineStart AS LONG, BYVAL lineEnd AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_HIDELINES, lineStart, lineEnd)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_HideLines (BYVAL pSci AS DWORD, BYVAL lineStart AS LONG, BYVAL lineEnd AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_HIDELINES, lineStart, lineEnd)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_GetLineVisible (BYVAL hSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETLINEVISIBLE, nLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetLineVisible (BYVAL pSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETLINEVISIBLE, nLine, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_GetAllLinesVisible (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETALLLINESVISIBLE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetAllLinesVisible (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETALLLINESVISIBLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETFOLDLEVEL(int line, int level)
' SCI_GETFOLDLEVEL(int line)
' These two messages set and get a 32-bit value that contains the fold level of a line and
' some flags associated with folding. The fold level is a number in the range 0 to
' SC_FOLDLEVELNUMBERMASK (4095). However, the initial fold level is set to SC_FOLDLEVELBASE
' (1024) to allow unsigned arithmetic on folding levels. There are two addition flag bits.
' SC_FOLDLEVELWHITEFLAG indicates that the line is blank and allows it to be treated
' slightly different then its level may indicate. For example, blank lines should generally
' not be fold points and will be considered part of the preceding section even though they
' may have a lesser fold level. SC_FOLDLEVELHEADERFLAG indicates that the line is a header
' (fold point).
' Use SCI_GETFOLDLEVEL(line) & SC_FOLDLEVELNUMBERMASK to get the fold level of a line.
' Likewise, use SCI_GETFOLDLEVEL(line) & SC_FOLDLEVEL*FLAG to get the state of the flags.
' To set the fold level you must or in the associated flags. For instance, to set the level
' to thisLevel and mark a line as being a fold point use: SCI_SETFOLDLEVEL(line, thisLevel |
' SC_FOLDLEVELHEADERFLAG).
' If you use a lexer, you should not need to use SCI_SETFOLDLEVEL as this is far better
' handled by the lexer. You will need to use SCI_GETFOLDLEVEL to decide how to handle user
' folding requests. If you do change the fold levels, the folding margin will update to
' match your changes.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetFoldLevel (BYVAL hSci AS DWORD, BYVAL nLine AS LONG, BYVAL nLevel AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETFOLDLEVEL, nLine, nLevel)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetFoldLevel (BYVAL pSci AS DWORD, BYVAL nLine AS LONG, BYVAL nLevel AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETFOLDLEVEL, nLine, nLevel)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_GetFoldLevel (BYVAL hSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETFOLDLEVEL, nLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetFoldLevel (BYVAL pSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETFOLDLEVEL, nLine, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETFOLDFLAGS(int flags)
' In addition to showing markers in the folding margin, you can indicate folds to the user
' by drawing lines in the text area. The lines are drawn in the foreground colour set for
' STYLE_DEFAULT. Bits set in flags determine where folding lines are drawn:
' Symbol                            Value  Effect
'                                      1    Experimental feature that has been removed.
' SC_FOLDFLAG_LINEBEFORE_EXPANDED      2    Draw above if expanded
' SC_FOLDFLAG_LINEBEFORE_CONTRACTED    4    Draw above if not expanded
' SC_FOLDFLAG_LINEAFTER_EXPANDED       8    Draw below if expanded
' SC_FOLDFLAG_LINEAFTER_CONTRACTED    16    Draw below if not expanded
' SC_FOLDFLAG_LEVELNUMBERS            64    display hexadecimal fold levels in line margin
'                                           to aid debugging of folding. The appearance of
'                                           this feature may change in the future.
' This message causes the display to redraw.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetFoldFlags (BYVAL hSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETFOLDFLAGS, nLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetFoldFlags (BYVAL pSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETFOLDFLAGS, nLine, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETLASTCHILD(int startLine, int level)
' This message searches for the next line after startLine, that has a folding level that
' is less than or equal to level and then returns the previous line number. If you set
' level to -1, level is set to the folding level of line startLine. If from is a fold
' point, SCI_GETLASTCHILD(from, -1) returns the last line that would be in made visible
' or hidden by toggling the fold state.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetLastChild (BYVAL hSci AS DWORD, BYVAL startLine AS LONG, BYVAL nLevel AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETLASTCHILD, startLine, nLevel)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetLastChild (BYVAL pSci AS DWORD, BYVAL startLine AS LONG, BYVAL nLevel AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETLASTCHILD, startLine, nLevel)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETFOLDPARENT(int startLine)
' This message returns the line number of the first line before startLine that is marked
' as a fold point with SC_FOLDLEVELHEADERFLAG and has a fold level less than the startLine.
' If no line is found, or if the header flags and fold levels are inconsistent, the return
' value is -1.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetFoldParent (BYVAL hSci AS DWORD, BYVAL startLine AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETFOLDPARENT, startLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetFoldParent (BYVAL pSci AS DWORD, BYVAL startLine AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETFOLDPARENT, startLine, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_TOGGLEFOLD(int line)
' Each fold point may be either expanded, displaying all its child lines, or contracted,
' hiding all the child lines. This message toggles the folding state of the given line as
' long as it has the SC_FOLDLEVELHEADERFLAG set. This message takes care of folding or
' expanding all the lines that depend on the line. The display updates after this message.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_ToggleFold (BYVAL hSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_TOGGLEFOLD, nLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ToggleFold (BYVAL pSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_TOGGLEFOLD, nLine, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_FOLDLINE(int line, int action)
' SCI_FOLDCHILDREN(int line, int action)
' SCI_FOLDALL(int action)
' These messages provide a higher-level approach to folding instead of setting expanded flags and showing or hiding individual lines.
' An individual fold can be contracted/expanded/toggled with SCI_FOLDLINE. To affect all child folds as well call SCI_FOLDCHILDREN.
' To affect the entire document call SCI_FOLDALL. With SC_FOLDACTION_TOGGLE the first fold header in the document is examined to decide whether to expand or contract.
' Symbol                 Value   Effect
' SC_FOLDACTION_CONTRACT   0     Contract.
' SC_FOLDACTION_EXPAND     1     Expand.
' SC_FOLDACTION_TOGGLE     2     Toggle between contracted and expanded.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_FoldLine (BYVAL hSci AS DWORD, BYVAL nLine AS LONG, BYVAL nAction AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_FOLDLINE, nLine, nAction)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_FoldLine(BYVAL pSci AS DWORD, BYVAL nLine AS LONG, BYVAL nAction AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_FOLDLINE, nLine, nAction)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_FoldChildren (BYVAL hSci AS DWORD, BYVAL nLine AS LONG, BYVAL nAction AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_FOLDCHILDREN, nLine, nAction)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_FoldChildren(BYVAL pSci AS DWORD, BYVAL nLine AS LONG, BYVAL nAction AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_FOLDCHILDREN, nLine, nAction)
END FUNCTION
' ========================================================================================
' ========================================================================================
'FUNCTION SCI_FoldAll (BYVAL hSci AS DWORD, BYVAL nAction AS LONG) AS LONG
'   FUNCTION = SendMessageA(hSci, %SCI_FOLDCHILDREN, nAction, 0)
'END FUNCTION
' ========================================================================================
' ========================================================================================
'FUNCTION SCIP_FoldAll(BYVAL pSci AS DWORD, BYVAL nAction AS LONG) AS LONG
'   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_FOLDCHILDREN, nAction, 0)
'END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_EXPANDCHILDREN(int line, int level)
' This is used to respond to a change to a line causing its fold level or whether it is a
' header to change, perhaps when adding or removing a '{'.
' By the time the container has received the notification that the line has changed, the
' fold level has already been set, so the container has to use the previous level in this
' call so that any range hidden underneath this line can be shown.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_ExpandChildren (BYVAL hSci AS DWORD, BYVAL nLine AS LONG, BYVAL nLevel AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_EXPANDCHILDREN, nLine, nLevel)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ExpandChildren(BYVAL pSci AS DWORD, BYVAL nLine AS LONG, BYVAL nLevel AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_EXPANDCHILDREN, nLine, nLevel)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETAUTOMATICFOLD(int automaticFold)
' SCI_GETAUTOMATICFOLD
' Instead of implementing all the logic for handling folding in the container, Scintilla
' can provide behaviour that is adequate for many applications. The automaticFold argument
' is a bit set defining which of the 3 pieces of folding implementation should be enabled.
' Most applications should be able to use the SC_AUTOMATICFOLD_SHOW and SC_AUTOMATICFOLD_CHANGE
' flags unless they wish to implement quite different behaviour such as defining their own
' fold structure. SC_AUTOMATICFOLD_CLICK is more likely to be set off when an application
' would like to add or change click behaviour such as showing method headers only when
' Shift+Alt is used in conjunction with a click.
' Symbol                Value  Effect
' SC_AUTOMATICFOLD_SHOW   1    Automatically show lines as needed. This avoids sending the SCN_NEEDSHOWN notification.
' SC_AUTOMATICFOLD_CLICK  2    Handle clicks in fold margin automatically. This avoids sending the SCN_MARGINCLICK notification for folding margins.
' SC_AUTOMATICFOLD_CHANGE 4    Show lines as needed when fold structure is changed. The SCN_MODIFIED notification is still sent unless it is disabled by the container.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetAutomaticFold (BYVAL hSci AS DWORD, BYVAL automaticFold AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETAUTOMATICFOLD, automaticFold, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetAutomaticFold (BYVAL pSci AS DWORD, BYVAL automaticFold AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETAUTOMATICFOLD, automaticFold, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetAutomaticFold (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETAUTOMATICFOLD, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetAutomaticFold (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETAUTOMATICFOLD, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETFOLDEXPANDED(int line, bool expanded)
' SCI_GETFOLDEXPANDED(int line)
' These messages set and get the expanded state of a single line. The set message has no
' effect on the visible state of the line or any lines that depend on it. It does change
' the markers in the folding margin. If you ask for the expansion state of a line that is
' outside the document, the result is false (0).
' If you just want to toggle the fold state of one line and handle all the lines that are
' dependent on it, it is much easier to use SCI_TOGGLEFOLD. You would use the
' SCI_SETFOLDEXPANDED message to process many folds without updating the display until you
' had finished. See SciTEBase::FoldAll() and SciTEBase::Expand() for examples of the use
' of these messages.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetFoldExpanded (BYVAL hSci AS DWORD, BYVAL nLine AS LONG, BYVAL bExpanded AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETFOLDEXPANDED, nLine, bExpanded)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetFoldExpanded (BYVAL pSci AS DWORD, BYVAL nLine AS LONG, BYVAL bExpanded AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETFOLDEXPANDED, nLine, bExpanded)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_GetFoldExpanded (BYVAL hSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETFOLDEXPANDED, nLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetFoldExpanded (BYVAL pSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETFOLDEXPANDED, nLine, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_CONTRACTEDFOLDNEXT(int lineStart)
' Search efficiently for lines that are contracted fold headers. This is useful when
' saving the user's folding when switching documents or saving folding with a file. The
' search starts at line number lineStart and continues forwards to the end of the file.
' lineStart is returned if it is a contracted fold header otherwise the next contracted
' fold header is returned. If there are no more contracted fold headers then -1 is
' returned.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_ContractedFoldNext (BYVAL hSci AS DWORD, BYVAL lineStart AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CONTRACTEDFOLDNEXT, lineStart, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ContractedFoldNext (BYVAL pSci AS DWORD, BYVAL lineStart AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CONTRACTEDFOLDNEXT, lineStart, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_ENSUREVISIBLE(int line)
' SCI_ENSUREVISIBLEENFORCEPOLICY(int line)
' A line may be hidden because more than one of its parent lines is contracted. Both these
' message travels up the fold hierarchy, expanding any contracted folds until they reach
' the top level. The line will then be visible. If you use SCI_ENSUREVISIBLEENFORCEPOLICY,
' the vertical caret policy set by SCI_SETVISIBLEPOLICY is then applied.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_EnsureVisible (BYVAL hSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ENSUREVISIBLE, nLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_EnsureVisible (BYVAL pSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ENSUREVISIBLE, nLine, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_EnsureVisibleEnforcePolicy (BYVAL hSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ENSUREVISIBLEENFORCEPOLICY, nLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_EnsureVisibleEnforcePolicy (BYVAL pSci AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ENSUREVISIBLEENFORCEPOLICY, nLine, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                     Line wrapping
' ########################################################################################

' ========================================================================================
' SCI_SETWRAPVISUALFLAGS(int wrapVisualFlags)
' SCI_GETWRAPVISUALFLAGS
' You can enable the drawing of visual flags to indicate a line is wrapped. Bits set in
' wrapVisualFlags determine which visual flags are drawn.
' Symbol                        Value  Effect
' SC_WRAPVISUALFLAG_NONE          0    No visual flags
' SC_WRAPVISUALFLAG_END           1    Visual flag at end of subline of a wrapped line.
' SC_WRAPVISUALFLAG_START         2    Visual flag at begin of subline of a wrapped line.
' Subline is indented by at least 1 to make room for the flag.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetWrapVisualFlags (BYVAL hSci AS DWORD, BYVAL wrapVisualFlags AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETWRAPVISUALFLAGS, wrapVisualFlags, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetWrapVisualFlags (BYVAL pSci AS DWORD, BYVAL wrapVisualFlags AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETWRAPVISUALFLAGS, wrapVisualFlags, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETWRAPVISUALFLAGSLOCATION(int wrapVisualFlagsLocation)
' SCI_GETWRAPVISUALFLAGSLOCATION
' You can set whether the visual flags to indicate a line is wrapped are drawn near the border or near the text. Bits set in wrapVisualFlagsLocation set the location to near the text for the corresponding visual flag.
' Symbol                              Value  Effect
' SC_WRAPVISUALFLAGLOC_DEFAULT          0    Visual flags drawn near border
' SC_WRAPVISUALFLAGLOC_END_BY_TEXT      1    Visual flag at end of subline drawn near text
' SC_WRAPVISUALFLAGLOC_START_BY_TEXT    2    Visual flag at beginning of subline drawn near text
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetWrapVisualFlagsLocation (BYVAL hSci AS DWORD, BYVAL wrapVisualFlagsLocation AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETWRAPVISUALFLAGSLOCATION, wrapVisualFlagsLocation, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetWrapVisualFlagsLocation (BYVAL pSci AS DWORD, BYVAL wrapVisualFlagsLocation AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETWRAPVISUALFLAGSLOCATION, wrapVisualFlagsLocation, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_GetWrapVisualFlagsLocation (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETWRAPVISUALFLAGSLOCATION, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetWrapVisualFlagsLocation (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETWRAPVISUALFLAGSLOCATION, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETWRAPINDENTMODE(int indentMode)
' SCI_GETWRAPINDENTMODE
' Wrapped sublines can be indented to the position of their first subline or one more
' indent level. The default is SC_WRAPINDENT_FIXED. The modes are:
' Symbol                Value  Effect
' SC_WRAPINDENT_FIXED     0    Wrapped sublines aligned to left of window plus amount set by SCI_SETWRAPSTARTINDENT
' SC_WRAPINDENT_SAME      1    Wrapped sublines are aligned to first subline indent
' SC_WRAPINDENT_INDENT    2    Wrapped sublines are aligned to first subline indent plus one more level of indentation
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetWrapIndentMode (BYVAL hSci AS DWORD, BYVAL indentMode AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETWRAPINDENTMODE, indentMode, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetWrapIndentMode (BYVAL pSci AS DWORD, BYVAL indentMode AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETWRAPINDENTMODE, indentMode, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_GetWrapIndentMode (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETWRAPINDENTMODE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetWrapIndentMode (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETWRAPINDENTMODE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETWRAPSTARTINDENT(int indent)
' SCI_GETWRAPSTARTINDENT
' SCI_SETWRAPSTARTINDENT sets the size of indentation of sublines for wrapped lines in
' terms of the average character width in STYLE_DEFAULT. There are no limits on indent
' sizes, but values less than 0 or large values may have undesirable effects.
' The indention of sublines is independent of visual flags, but if SC_WRAPVISUALFLAG_START
' is set an indent of at least 1 is used.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetWrapStartIndent (BYVAL hSci AS DWORD, BYVAL indent AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETWRAPSTARTINDENT, indent, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetWrapStartIndent (BYVAL pSci AS DWORD, BYVAL indent AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETWRAPSTARTINDENT, indent, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_GetWrapStartIndent (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETWRAPSTARTINDENT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetWrapStartIndent (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETWRAPSTARTINDENT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETLAYOUTCACHE(int cacheMode)
' SCI_GETLAYOUTCACHE
' You can set cacheMode to one of the symbols in the table:
' Symbol             Value  Layout cached for these lines
' SC_CACHE_NONE        0    No lines are cached.
' SC_CACHE_CARET       1    The line containing the text caret. This is the default.
' SC_CACHE_PAGE        2    Visible lines plus the line containing the caret.
' SC_CACHE_DOCUMENT    3    All lines in the document.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetLayoutCache (BYVAL hSci AS DWORD, BYVAL cacheMode AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETLAYOUTCACHE, cacheMode, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetLayoutCache (BYVAL pSci AS DWORD, BYVAL cacheMode AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETLAYOUTCACHE, cacheMode, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_GetLayoutCache (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETLAYOUTCACHE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetLayoutCache (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETLAYOUTCACHE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETPOSITIONCACHE(int size)
' SCI_GETPOSITIONCACHE
' The position cache stores position information for short runs of text so that their
' layout can be determined more quickly if the run recurs. The size in entries of this
' cache can be set with SCI_SETPOSITIONCACHE.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetPositionCache (BYVAL hSci AS DWORD, BYVAL nSize AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETPOSITIONCACHE, nSize, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetPositionCache (BYVAL pSci AS DWORD, BYVAL nSize AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETPOSITIONCACHE, nSize, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_GetPositionCache (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETPOSITIONCACHE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetPositionCache (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETPOSITIONCACHE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_LINESSPLIT(int pixelWidth)
' Split a range of lines indicated by the target into lines that are at most pixelWidth
' wide. Splitting occurs on word boundaries wherever possible in a similar manner to line
' wrapping. When pixelWidth is 0 then the width of the window is used.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_LineSplit (BYVAL hSci AS DWORD, BYVAL pixelWidth AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LINESSPLIT, pixelWidth, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LineSplit (BYVAL pSci AS DWORD, BYVAL pixelWidth AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LINESSPLIT, pixelWidth, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_LINESJOIN
' Join a range of lines indicated by the target into one line by removing line end
' characters. Where this would lead to no space between words, an extra space is inserted.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_LinesJoin (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LINESJOIN, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LinesJoin (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LINESJOIN, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_WRAPCOUNT(int docLine)
' Document lines can occupy more than one display line if they wrap and this returns the
' number of display lines needed to wrap a document line.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_WrapCount (BYVAL hSci AS DWORD, BYVAL docLine AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_WRAPCOUNT, docLine, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_WrapCount (BYVAL pSci AS DWORD, BYVAL docLine AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_WRAPCOUNT, docLine, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                         Zooming
' ########################################################################################

' ========================================================================================
' SCI_ZOOMIN
' SCI_ZOOMOUT
' SCI_ZOOMIN increases the zoom factor by one point if the current zoom factor is less
' than 20 points. SCI_ZOOMOUT decreases the zoom factor by one point if the current zoom
' factor is greater than -10 points.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_ZoomIn (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ZOOMIN, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ZoomIn (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ZOOMIN, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_ZoomOut (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ZOOMOUT, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ZoomOut (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ZOOMOUT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETZOOM(int zoomInPoints)
' SCI_GETZOOM
' These messages let you set and get the zoom factor directly. There is no limit set on
' the factors you can set, so limiting yourself to -10 to +20 to match the incremental
' zoom functions is a good idea.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetZoom (BYVAL hSci AS DWORD, BYVAL zoomInPoints AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETZOOM, zoomInPoints, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetZoom (BYVAL pSci AS DWORD, BYVAL zoomInPoints AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETZOOM, zoomInPoints, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_GetZoom (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETZOOM, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetZoom (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETZOOM, 0, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                       Long lines
' ########################################################################################

' ========================================================================================
' SCI_SETEDGEMODE(int edgeMode)
' SCI_GETEDGEMODE
' These two messages set and get the mode used to display long lines. You can set one of
' the values in the table:
' Symbol           Value  Long line display mode
' EDGE_NONE          0    Long lines are not marked. This is the default state.
' EDGE_LINE          1    A vertical line is drawn at the column number set by SCI_SETEDGECOLUMN.
'                         This works well for monospaced fonts. The line is drawn at a
'                         position based on the width of a space character in STYLE_DEFAULT,
'                         so it may not work very well if your styles use proportional
'                         fonts or if your style have varied font sizes or you use a
'                         mixture of bold, italic and normal text.
' EDGE_BACKGROUND    2    The background colour of characters after the column limit is
'                         changed to the colour set by SCI_SETEDGECOLOUR. This is
'                         recommended for proportional fonts.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetEdgeMode (BYVAL hSci AS DWORD, BYVAL edgeMode AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETEDGEMODE, edgeMode, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetEdgeMode (BYVAL pSci AS DWORD, BYVAL edgeMode AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETEDGEMODE, edgeMode, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_GetEdgeMode (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETEDGEMODE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetEdgeMode (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETEDGEMODE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETEDGECOLUMN(int column)
' SCI_GETEDGECOLUMN
' These messages set and get the column number at which to display the long line marker.
' When drawing lines, the column sets a position in units of the width of a space character
' in STYLE_DEFAULT. When setting the background colour, the column is a character count
' (allowing for tabs) into the line.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetEdgeColumn (BYVAL hSci AS DWORD, BYVAL nColumn AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETEDGECOLUMN, nColumn, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetEdgeColumn (BYVAL pSci AS DWORD, BYVAL nColumn AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETEDGECOLUMN, nColumn, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_GetEdgeColumn (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETEDGECOLUMN, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetEdgeColumn (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETEDGECOLUMN, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETEDGECOLOUR(int colour)
' SCI_GETEDGECOLOUR
' These messages set and get the colour of the marker used to show that a line has exceeded
' the length set by SCI_SETEDGECOLUMN.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetEdgeColour (BYVAL hSci AS DWORD, BYVAL colour AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETEDGECOLOUR, colour, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetEdgeColour (BYVAL pSci AS DWORD, BYVAL colour AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETEDGECOLOUR, colour, 0)
END FUNCTION
' ========================================================================================

MACRO SCI_SetEdgeColor = SCI_SetEdgeColour
MACRO SCIP_SetEdgeColor = SCIP_SetEdgeColour

' ========================================================================================
FUNCTION SCI_GetEdgeColour (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETEDGECOLOUR, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetEdgeColour (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETEDGECOLOUR, 0, 0)
END FUNCTION
' ========================================================================================

MACRO SCI_GetEdgeColor = SCI_GetEdgeColour
MACRO SCIP_GetEdgeColor = SCIP_GetEdgeColour

' ########################################################################################
'                                           Lexer
' ########################################################################################

' ========================================================================================
' SCI_SETLEXER(int lexer)
' SCI_GETLEXER
' You can select the lexer to use with an integer code from the SCLEX_* enumeration in
' Scintilla.h. There are two codes in this sequence that do not use lexers: SCLEX_NULL to
' select no lexing action and SCLEX_CONTAINER which sends the SCN_STYLENEEDED notification
' to the container whenever a range of text needs to be styled. You cannot use the
' SCLEX_AUTOMATIC value; this identifies additional external lexers that Scintilla assigns
' unused lexer numbers to.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetLexer (BYVAL hSci AS DWORD, BYVAL lexer AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETLEXER, lexer, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetLexer (BYVAL pSci AS DWORD, BYVAL lexer AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETLEXER, lexer, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_GetLexer (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETLEXER, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetLexer (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETLEXER, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETLEXERLANGUAGE(<unused>, const char *name)
' SCI_GETLEXERLANGUAGE(<unused>, char *name)
' SCI_SETLEXERLANGUAGE lets you select a lexer by name, and is the only method if you are
' using an external lexer or if you have written a lexer module for a language of your own
' and do not wish to assign it an explicit lexer number. To select an existing lexer, set
' name to match the (case sensitive) name given to the module, for example "ada" or
' "python", not "Ada" or "Python". To locate the name for the built-in lexers, open the
' relevant Lex*.cxx file and search for LexerModule. The third argument in the LexerModule
' constructor is the name to use.
' To test if your lexer assignment worked, use SCI_GETLEXER before and after setting the
' new lexer to see if the lexer number changed.
' SCI_GETLEXERLANGUAGE retrieves the name of the lexer.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetLexerLanguage (BYVAL hSci AS DWORD, BYVAL strName AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETLEXERLANGUAGE, 0, STRPTR(strName))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetLexerLanguage (BYVAL pSci AS DWORD, BYVAL strName AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETLEXERLANGUAGE, 0, STRPTR(strName))
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_GetLexerLanguage (BYVAL hSci AS DWORD) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = SendMessageA(hSci, %SCI_GETLEXERLANGUAGE, 0, 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen + 1)
   SendMessageA(hSci, %SCI_GETLEXERLANGUAGE, 0, STRPTR(buffer))
   FUNCTION = REMOVE$(buffer, CHR$(0))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetLexerLanguage (BYVAL pSci AS DWORD) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = Scintilla_DirectFunction(pSci, %SCI_GETLEXERLANGUAGE, 0, 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen + 1)
   Scintilla_DirectFunction(pSci, %SCI_GETLEXERLANGUAGE, 0, STRPTR(buffer))
   FUNCTION = REMOVE$(buffer, CHR$(0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_LOADLEXERLIBRARY(<unused>, const char *path)
' Load a lexer implemented in a shared library. This is a .so file on GTK+/Linux or a .DLL
' file on Windows.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_LoadLexerLibrary (BYVAL hSci AS DWORD, BYVAL strPath AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_LOADLEXERLIBRARY, 0, STRPTR(strPath))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_LoadLexerLibrary (BYVAL pSci AS DWORD, BYVAL strPath AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_LOADLEXERLIBRARY, 0, STRPTR(strPath))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_COLOURISE(int startPos, int endPos)
' This requests the current lexer or the container (if the lexer is set to SCLEX_CONTAINER)
' to style the document between startPos and endPos. If endPos is -1, the document is
' styled from startPos to the end. If the "fold" property is set to "1" and your lexer or
' container supports folding, fold levels are also set. This message causes a redraw.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_Colourise (BYVAL hSci AS DWORD, BYVAL startPos AS LONG, BYVAL endPos AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_COLOURISE, startPos, endPos)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_Colourise (BYVAL pSci AS DWORD, BYVAL startPos AS LONG, BYVAL endPos AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_COLOURISE, startPos, endPos)
END FUNCTION
' ========================================================================================

MACRO SCI_Colorize = SCI_Colourise
MACRO SCIP_Colorize = SCIP_Colourise

' ========================================================================================
' SCI_CHANGELEXERSTATE(int startPos, int endPos)
' Indicate that the internal state of a lexer has changed over a range and therefore there
' may be a need to redraw.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_ChangeLexerState (BYVAL hSci AS DWORD, BYVAL startPos AS LONG, BYVAL endPos AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_CHANGELEXERSTATE, startPos, endPos)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ChangeLexerState (BYVAL pSci AS DWORD, BYVAL startPos AS LONG, BYVAL endPos AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_CHANGELEXERSTATE, startPos, endPos)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_PROPERTYNAMES(<unused>, char *names)
' SCI_PROPERTYTYPE(const char *name)
' SCI_DESCRIBEPROPERTY(const char *name, char *description)
' Information may be retrieved about the properties that can be set for the current lexer.
' This information is only available for newer lexers. SCI_PROPERTYNAMES returns a string
' with all of the valid properties separated by "\n". If the lexer does not support this
' call then an empty string is returned. Properties may be boolean (SC_TYPE_BOOLEAN),
' integer (SC_TYPE_INTEGER), or string (SC_TYPE_STRING) and this is found with
' SCI_PROPERTYTYPE. A description of a property in English is returned by SCI_DESCRIBEPROPERTY.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_PropertyNames (BYVAL hSci AS DWORD, BYVAL strNames AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_PROPERTYNAMES, 0, STRPTR(strNames))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_PropertyNames (BYVAL pSci AS DWORD, BYVAL strNames AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_PROPERTYNAMES, 0, STRPTR(strNames))
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_PropertyType (BYVAL hSci AS DWORD, BYVAL strName AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_PROPERTYNAMES, 0, STRPTR(strName))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_PropertyType (BYVAL pSci AS DWORD, BYVAL strName AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_PROPERTYNAMES, 0, STRPTR(strName))
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_DescribeProperty (BYVAL hSci AS DWORD, BYVAL strName AS STRING, BYVAL strDescription AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_PROPERTYNAMES, STRPTR(strName), STRPTR(strDescription))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_DescribeProperty (BYVAL pSci AS DWORD, BYVAL strName AS STRING, BYVAL strDescription AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_PROPERTYNAMES, STRPTR(strName), STRPTR(strDescription))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETPROPERTY(const char *key, const char *value)
' You can communicate settings to lexers with keyword:value string pairs. There is no
' limit to the number of keyword pairs you can set, other than available memory. key is a
' case sensitive keyword, value is a string that is associated with the keyword. If there
' is already a value string associated with the keyword, it is replaced. If you pass a
' zero length string, the message does nothing. Both key and value are used without
' modification; extra spaces at the beginning or end of key are significant.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetProperty (BYVAL hSci AS DWORD, BYVAL strKey AS STRING, BYVAL strValue AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETPROPERTY, STRPTR(strKey), STRPTR(strValue))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetProperty (BYVAL pSci AS DWORD, BYVAL strKey AS STRING, BYVAL strValue AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETPROPERTY, STRPTR(strKey), STRPTR(strValue))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETPROPERTY(const char *key, char *value)
' Lookup a keyword:value pair using the specified key; if found, copy the value to the
' user-supplied buffer and return the length (not including the terminating 0). If not
' found, copy an empty string to the buffer and return 0.
' Note that "keyword replacement" as described in SCI_SETPROPERTY will not be performed.
' If the value argument is 0 then the length that should be allocated to store the value
' is returned; again, the terminating 0 is not included.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetProperty (BYVAL hSci AS DWORD, BYVAL strKey AS STRING) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = SendMessageA(hSci, %SCI_GETPROPERTY, STRPTR(strKey), 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen + 1)
   SendMessageA(hSci, %SCI_GETPROPERTY, STRPTR(strKey), STRPTR(buffer))
   FUNCTION = REMOVE$(buffer, CHR$(0))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetProperty (BYVAL pSci AS DWORD, BYVAL strKey AS STRING) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = Scintilla_DirectFunction(pSci, %SCI_GETPROPERTY, STRPTR(strKey), 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen + 1)
   Scintilla_DirectFunction(pSci, %SCI_GETPROPERTY, STRPTR(strKey), STRPTR(buffer))
   FUNCTION = REMOVE$(buffer, CHR$(0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETPROPERTYEXPANDED(const char *key, char *value)
' Lookup a keyword:value pair using the specified key; if found, copy the value to the
' user-supplied buffer and return the length (not including the terminating 0). If not
' found, copy an empty string to the buffer and return 0.
' Note that "keyword replacement" as described in SCI_SETPROPERTY will be performed.
' If the value argument is 0 then the length that should be allocated to store the value
' (including any indicated keyword replacement) is returned; again, the terminating 0 is
' not included.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetPropertyExpanded (BYVAL hSci AS DWORD, BYVAL strKey AS STRING) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = SendMessageA(hSci, %SCI_GETPROPERTYEXPANDED, STRPTR(strKey), 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen + 1)
   SendMessageA(hSci, %SCI_GETPROPERTYEXPANDED, STRPTR(strKey), STRPTR(buffer))
   FUNCTION = REMOVE$(buffer, CHR$(0))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetPropertyExpanded (BYVAL pSci AS DWORD, BYVAL strKey AS STRING) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = Scintilla_DirectFunction(pSci, %SCI_GETPROPERTYEXPANDED, STRPTR(strKey), 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen + 1)
   Scintilla_DirectFunction(pSci, %SCI_GETPROPERTYEXPANDED, STRPTR(strKey), STRPTR(buffer))
   FUNCTION = REMOVE$(buffer, CHR$(0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETPROPERTYINT(const char *key, int default)
' Lookup a keyword:value pair using the specified key; if found, interpret the value as an
' integer and return it. If not found (or the value is an empty string) then return the
' supplied default. If the keyword:value pair is found but is not a number, then return 0.
' Note that "keyword replacement" as described in SCI_SETPROPERTY will be performed before
' any numeric interpretation.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetPropertyint (BYVAL hSci AS DWORD, BYVAL strKey AS STRING, BYVAL nDefault AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETPROPERTYINT, STRPTR(strKey), nDefault)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetPropertyint (BYVAL pSci AS DWORD, BYVAL strKey AS STRING, BYVAL nDefault AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETPROPERTYINT, STRPTR(strKey), nDefault)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETKEYWORDS(int keyWordSet, const char *keyWordList)
' You can set up to 9 lists of keywords for use by the current lexer. This was increased
' from 6 at revision 1.50. keyWordSet can be 0 to 8 (actually 0 to KEYWORDSET_MAX) and
' selects which keyword list to replace. keyWordList is a list of keywords separated by
' spaces, tabs, "\n" or "\r" or any combination of these. It is expected that the keywords
' will be composed of standard ASCII printing characters, but there is nothing to stop you
' using any non-separator character codes from 1 to 255 (except common sense).
' How these keywords are used is entirely up to the lexer. Some languages, such as HTML
' may contain embedded languages, VBScript and JavaScript are common for HTML. For HTML,
' key word set 0 is for HTML, 1 is for JavaScript and 2 is for VBScript, 3 is for Python,
' 4 is for PHP and 5 is for SGML and DTD keywords. Review the lexer code to see examples
' of keyword list. A fully conforming lexer sets the fourth argument of the LexerModule
' constructor to be a list of strings that describe the uses of the keyword lists.
' Alternatively, you might use set 0 for general keywords, set 1 for keywords that cause
' indentation and set 2 for keywords that cause unindentation. Yet again, you might have
' a simple lexer that colours keywords and you could change languages by changing the
' keywords in set 0. There is nothing to stop you building your own keyword lists into
' the lexer, but this means that the lexer must be rebuilt if more keywords are added.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetKeywords (BYVAL hSci AS DWORD, BYVAL keyWordSet AS LONG, BYVAL keyWordList AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETKEYWORDS, keyWordSet, STRPTR(keyWordList))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetKeywords (BYVAL pSci AS DWORD, BYVAL keyWordSet AS LONG, BYVAL keyWordList AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETKEYWORDS, keyWordSet, STRPTR(keyWordList))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_DESCRIBEKEYWORDSETS(<unused>, char *descriptions)
' A description of all of the keyword sets separated by "\n" is returned by SCI_DESCRIBEKEYWORDSETS.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_DescribeKeywordSets (BYVAL hSci AS DWORD, BYVAL strDescriptions AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_DESCRIBEKEYWORDSETS, 0, STRPTR(strDescriptions))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_DescribeKeywordSets (BYVAL pSci AS DWORD, BYVAL strDescriptions AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_DESCRIBEKEYWORDSETS, 0, STRPTR(strDescriptions))
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETSTYLEBITSNEEDED
' Retrieve the number of bits the current lexer needs for styling. This should normally be
' the argument to SCI_SETSTYLEBITS.
' Deprecated.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetStyleBitsNeeded (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETSTYLEBITSNEEDED, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetStyleBitsNeeded (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETSTYLEBITSNEEDED, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETIDENTIFIER(int identifier)
' SCI_GETIDENTIFIER
' These two messages set and get the identifier of the Scintilla instance which is included
' in notifications as the idFrom field. When an application creates multiple Scintilla
' widgets, this allows the source of each notification to be found. On Windows, this value
' is initialised in the CreateWindow call and stored as the GWLP_ID attribute of the window.
' The value should be small, preferrably less than 16 bits, rather than a pointer as some
' of the functions will only transmit 16 or 32 bits.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SetIdentifier (BYVAL hSci AS DWORD, BYVAL identifier AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETIDENTIFIER, 0, identifier)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetIdentifier (BYVAL pSci AS DWORD, BYVAL identifier AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETIDENTIFIER, 0, identifier)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION SCI_GetIdentifier (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETIDENTIFIER, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetIdentifier (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETIDENTIFIER, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Substyles
' Lexers may support several different sublanguages and each sublanguage may want to style
' some number of sets of identifiers (or similar lexemes such as documentation keywords)
' uniquely. Preallocating a large number for each purpose would exhaust the number of
' allowed styles quickly. This is alleviated by substyles which allow the application to
' determine how many sets of identifiers to allocate for each purpose. Lexers have to
' explicitly support this feature by implementing the methods in ILexerWithSubStyles.
' ========================================================================================

' ========================================================================================
' SCI_GETSUBSTYLEBASES(<unused>, char *styles)
' Fill styles with a byte for each style that can be split into substyles.
' ========================================================================================
FUNCTION SCI_GetSubStyleBases (BYVAL hSci AS DWORD, BYREF rgStyles AS BYTE) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETSUBSTYLEBASES, 0, rgStyles)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetSubStyleBases (BYVAL pSci AS DWORD, BYREF rgStyles AS BYTE) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETSUBSTYLEBASES, 0, rgStyles)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_DISTANCETOSECONDARYSTYLES
' Returns the distance between a primary style and its corresponding secondary style.
' ========================================================================================
FUNCTION SCI_DistanceToSecondaryStyles (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_DISTANCETOSECONDARYSTYLES, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_DistanceToSecondaryStyles (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_DISTANCETOSECONDARYSTYLES, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_ALLOCATESUBSTYLES(int styleBase, int numberStyles)
' Allocate some number of substyles for a particular base style returning the first
' substyle number allocated. Substyles are allocated contiguously.
' ========================================================================================
' ========================================================================================
FUNCTION SCI_AllocateSubstyles (BYVAL hSci AS DWORD, BYVAL styleBase AS LONG, BYVAL numberStyles AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_ALLOCATESUBSTYLES, styleBase, numberStyles)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_AllocateSubstyles (BYVAL pSci AS DWORD, BYVAL styleBase AS LONG, BYVAL numberStyles AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_ALLOCATESUBSTYLES, styleBase, numberStyles)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_FREESUBSTYLES
' Free all allocated substyles.
' ========================================================================================
FUNCTION SCI_FreeSubstyles (BYVAL hSci AS DWORD) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_FREESUBSTYLES, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_FreeSubstyles (BYVAL pSci AS DWORD) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_FREESUBSTYLES, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETSUBSTYLESSTART(int styleBase)
' SCI_GETSUBSTYLESLENGTH(int styleBase)
' Return the start and length of the substyles allocated for a base style.
' ========================================================================================
FUNCTION SCI_GetSubstylesStart (BYVAL hSci AS DWORD, BYVAL styleBase AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETSUBSTYLESSTART, styleBase, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetSubstylesStart (BYVAL pSci AS DWORD, BYVAL styleBase AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETSUBSTYLESSTART, styleBase, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetSubstylesLength (BYVAL hSci AS DWORD, BYVAL styleBase AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETSUBSTYLESLENGTH, styleBase, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetSubstylesLength (BYVAL pSci AS DWORD, BYVAL styleBase AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETSUBSTYLESLENGTH, styleBase, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETSTYLEFROMSUBSTYLE(int subStyle)
' For a sub style, return the base style, else return the argument.
' ========================================================================================
FUNCTION SCI_GetStyleFromSubstyle (BYVAL hSci AS DWORD, BYVAL subStyle AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETSTYLEFROMSUBSTYLE, subStyle, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetStyleFromSubstyle (BYVAL pSci AS DWORD, BYVAL subStyle AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETSTYLEFROMSUBSTYLE, subStyle, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_GETPRIMARYSTYLEFROMSTYLE(int style)
' For a secondary style, return the primary style, else return the argument.
' ========================================================================================
FUNCTION SCI_GetPrimaryStyleFromStyle (BYVAL hSci AS DWORD, BYVAL nStyle AS LONG) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_GETPRIMARYSTYLEFROMSTYLE, nStyle, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetPrimaryStyleFromStyle (BYVAL pSci AS DWORD, BYVAL nStyle AS LONG) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_GETPRIMARYSTYLEFROMSTYLE, nStyle, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' SCI_SETIDENTIFIERS(int style, const char *identifiers)
' Similar to SCI_SETKEYWORDS but for substyles. The prefix feature available with
' SCI_SETKEYWORDS is not implemented for SCI_SETIDENTIFIERS.
' ========================================================================================
FUNCTION SCI_SetIdentifiers (BYVAL hSci AS DWORD, BYVAL nStyle AS LONG, BYVAL identifiers AS STRING) AS LONG
   FUNCTION = SendMessageA(hSci, %SCI_SETIDENTIFIERS, nStyle, STRPTR(identifiers))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_SetIdentifiers (BYVAL pSci AS DWORD, BYVAL nStyle AS LONG, BYVAL identifiers AS STRING) AS LONG
   FUNCTION = Scintilla_DirectFunction(pSci, %SCI_SETIDENTIFIERS, nStyle, STRPTR(identifiers))
END FUNCTION
' ========================================================================================

' ########################################################################################
'                               *** WRAPPER FUNCTIONS ***
' ########################################################################################

' ========================================================================================
' Retrieves the zero-based line number at the caret position
' ========================================================================================
FUNCTION SCI_GetCurrentLineNumber (BYVAL hSci AS DWORD) AS LONG
   LOCAL curPos AS LONG
   curPos = SCI_GetCurrentPos(hSci)
   FUNCTION = SCI_LineFromPosition(hSci, curPos)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetCurrentLineNumber (BYVAL pSci AS DWORD) AS LONG
   LOCAL curPos AS LONG
   curPos = SCIP_GetCurrentPos(pSci)
   FUNCTION = SCIP_LineFromPosition(pSci, curPos)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the zero-based column number at the caret position
' ========================================================================================
FUNCTION SCI_GetCurrentColumnNumber (BYVAL hSci AS DWORD) AS LONG
   LOCAL curPos AS LONG
   curPos = SCI_GetCurrentPos(hSci)
   FUNCTION = SCI_GetColumn(hSci, curPos)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_GetCurrentColumnNumber (BYVAL pSci AS DWORD) AS LONG
   LOCAL curPos AS LONG
   curPos = SCIP_GetCurrentPos(pSci)
   FUNCTION = SCIP_GetColumn(pSci, curPos)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Selects the specified line
' ========================================================================================
SUB SCI_SelectLine (BYVAL hSci AS DWORD, BYVAL LineNumber AS DWORD)
   LOCAL curPos AS LONG
   SCI_GotoLine(hSci, LineNumber)
   curPos = SCI_PositionFromLine(hSci, LineNumber)
   SCI_SetSelectionStart(hSci, curPos)
   SCI_SetSelectionEnd(hSci, SCI_GetLineEndPosition(hSci, LineNumber))
END SUB
' ========================================================================================
' ========================================================================================
SUB SCIP_SelectLine (BYVAL pSci AS DWORD, BYVAL LineNumber AS DWORD)
   LOCAL curPos AS LONG
   SCIP_GotoLine(pSci, LineNumber)
   curPos = SCIP_PositionFromLine(pSci, LineNumber)
   SCIP_SetSelectionStart(pSci, curPos)
   SCIP_SetSelectionEnd(pSci, SCIP_GetLineEndPosition(pSci, LineNumber))
END SUB
' ========================================================================================

' ========================================================================================
' Toggles the current fold point.
' ========================================================================================
FUNCTION SCI_ToggleCurFold (BYVAL hSci AS DWORD, BYVAL LineNumber AS LONG) AS LONG
   IF (SCI_GetFoldLEvel(hSci, LineNumber) AND %SC_FOLDLEVELHEADERFLAG) = 0 THEN
      ' // Get the number of the head line of the procedure or function
      LineNumber = SCI_GetFoldParent(hSci, LineNumber)
   END IF
   IF LineNumber > -1 THEN
      ' // Toggle the fold point
      SCI_ToggleFold(hSci, LineNumber)
      ' // Set the caret position
      SCI_GotoLine(hSci, LineNumber)
   END IF
   ' // Return the current line
   FUNCTION = LineNumber
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCIP_ToggleCurFold (BYVAL pSci AS DWORD, BYVAL LineNumber AS LONG) AS LONG
   IF (SCIP_GetFoldLEvel(pSci, LineNumber) AND %SC_FOLDLEVELHEADERFLAG) = 0 THEN
      ' // Get the number of the head line of the procedure or function
      LineNumber = SCIP_GetFoldParent(pSci, LineNumber)
   END IF
   IF LineNumber > -1 THEN
      ' // Toggle the fold point
      SCIP_ToggleFold(pSci, LineNumber)
      ' // Set the caret position
      SCIP_GotoLine(pSci, LineNumber)
   END IF
   ' // Return the current line
   FUNCTION = LineNumber
END FUNCTION
' ========================================================================================

' ========================================================================================
' Toggles the curent fold point and, if it is a base level, all the base level fold points below.
' ========================================================================================
SUB SCIP_ToggleFoldsOnwards (BYVAL pSci AS DWORD, BYVAL LineNumber AS LONG)

   LOCAL i         AS LONG    ' // Loop counter
   LOCAL FoldState AS LONG    ' // Folder state
   LOCAL LineCount AS LONG    ' // Number of lines

   IF pSci = 0 THEN EXIT SUB
   ' // Force the lexer to style the whole document
   SCIP_Colorize(pSci, 0, -1)
   ' // Toggle the first sub or function
   LineNumber = SCIP_ToggleCurFold(pSci, LineNumber)
   ' // Determine whether the fold is expanded or not
   FoldState = SCIP_GetFoldExpanded(pSci, LineNumber)
   ' // Number of lines
   LineCount = SCIP_GetLineCount(pSci)
   ' // Show hourglass mouse
   SetCursor LoadCursorA(BYVAL %NULL, BYVAL %IDC_APPSTARTING)
   ' // Toggle the rest of functions/procedures
'   FOR i = LineNumber TO LineCount
'      ' // If we are in the head line ...
'      IF (SCIP_GetFoldLevel(pSci, i) AND %SC_FOLDLEVELHEADERFLAG) THEN
'         ' // If the state is different ...
'         IF SCIP_GetFoldExpanded(pSci, i) <> FoldState THEN
'            ' // Toggle it
'            SCIP_ToggleFold(pSci, i)
'         END IF
'      END IF
'   NEXT
   ' // Alternate option: Toggle only the line headers
   FOR i = LineNumber TO LineCount
        ' // If we are in the head line ...
      IF (SCIP_GetFoldLevel(pSci, i) AND %SC_FOLDLEVELNUMBERMASK) = %SC_FOLDLEVELBASE THEN
         ' // If the state is different ...
         IF SCIP_GetFoldExpanded(pSci, i) <> FoldState THEN
            ' // Toggle it
            SCIP_ToggleFold(pSci, i)
         END IF
      END IF
   NEXT

   ' // Show standard mouse
   SetCursor LoadCursorA(BYVAL %NULL, BYVAL %IDC_ARROW)

END SUB
' ========================================================================================
' ========================================================================================
SUB SCI_ToggleFoldsOnwards (BYVAL hSci AS DWORD, BYVAL LineNumber AS LONG)
   SCIP_ToggleFoldsOnwards(SCI_GetDirectPointer(hSci), LineNumber)
END SUB
' ========================================================================================

' ========================================================================================
' Folds all the base level fold points.
' ========================================================================================
SUB SCIP_FoldAll (BYVAL pSci AS DWORD)

   LOCAL i         AS LONG    ' // Loop counter
   LOCAL LineCount AS LONG    ' // Line number

   IF pSci = 0 THEN EXIT SUB
   ' // Force the lexer to style the whole document
   SCIP_Colorize(pSci, 0, -1)
   ' // Number of lines
   LineCount = SCIP_GetLineCount(pSci)
   ' // Show hourglass mouse
   SetCursor LoadCursorA(BYVAL %NULL, BYVAL %IDC_APPSTARTING)
   ' // Toggle the functions/procedures
'   FOR i = 0 TO LineCount
'      ' // If we are in the head line ...
'      IF (SCIP_GetFoldLevel(pSci, i) AND %SC_FOLDLEVELHEADERFLAG) THEN
'         ' // If it is expanded...
'         IF SCIP_GetFoldExpanded(pSci, i) THEN
'            // ... fold it
'            SCIP_ToggleFold(pSci, i)
'         END IF
'      END IF
'   NEXT
   ' Alternate option: Fold only the line headers
   FOR i = 0 TO LineCount
      ' // If we are in the head line ...
      IF (SCIP_GetFoldLevel(pSci, i) AND %SC_FOLDLEVELNUMBERMASK) = %SC_FOLDLEVELBASE THEN
         ' // If it is expanded...
         IF SCIP_GetFoldExpanded(pSci, i) THEN
            ' // ... fold it
            SCIP_ToggleFold(pSci, i)
         END IF
      END IF
   NEXT

   ' // Show standard mouse
   SetCursor LoadCursorA(BYVAL %NULL, BYVAL %IDC_ARROW)

END SUB
' ========================================================================================
' ========================================================================================
' Folds all the fold points.
' ========================================================================================
SUB SCI_FoldAll (BYVAL hSci AS DWORD)
   SCIP_FoldAll(SCI_GetDirectPointer(hSci))
END SUB
' ========================================================================================

' ========================================================================================
' Unfolds all the fold points.
' ========================================================================================
SUB SCIP_UnfoldAll (BYVAL pSci AS DWORD)

   LOCAL i         AS LONG    ' // Loop counter
   LOCAL LineCount AS LONG    ' // Line count

   IF ISFALSE pSci THEN EXIT SUB
   ' // Force the lexer to style the whole document
   SCIP_Colorize(pSci, 0, -1)
   ' // Number of lines
   LineCount = SCIP_GetLineCount(pSci)
   ' // Show hourglass mouse
   SetCursor LoadCursorA(BYVAL %NULL, BYVAL %IDC_APPSTARTING)
'   FOR i = 1 TO LineCount
'      ' // If we are in the head line ...
'      IF (SCIP_GetFoldLevel(pSci, i) AND %SC_FOLDLEVELHEADERFLAG) THEN
'         ' // If it is not expanded...
'         IF ISFALSE SCIP_GetFoldExpanded(pSci, i) THEN
'            ' // ... expand it
'            SCIP_ToggleFold(pSci, i)
'         END IF
'      END IF
'   NEXT
   ' // Alternate option: Expand only the line headers
   FOR i = 1 TO LineCount
      ' // If we are in the head line ...
      IF (SCIP_GetFoldLevel(pSci, i) AND %SC_FOLDLEVELNUMBERMASK) = %SC_FOLDLEVELBASE THEN
         ' // If it is not expanded...
         IF ISFALSE SCIP_GetFoldExpanded(pSci, i) THEN
            ' // ... expand it
            SCIP_ToggleFold(pSci, i)
         END IF
      END IF
   NEXT

   ' // Show standard mouse
   SetCursor LoadCursorA(BYVAL %NULL, BYVAL %IDC_ARROW)

END SUB
' ========================================================================================
' ========================================================================================
' Unfolds all the fold points.
' ========================================================================================
SUB SCI_UnfoldAll (BYVAL hSci AS DWORD)
   SCIP_UnfoldAll(SCI_GetDirectPointer(hSci))
END SUB
' ========================================================================================

' ========================================================================================
' Replace tabs with spaces
' ========================================================================================
SUB SCI_ReplaceTabsWithSpaces (BYVAL hSci AS DWORD)

   LOCAL i AS LONG
   LOCAL nLen AS LONG
   LOCAL nLines AS LONG
   LOCAL TabSize AS LONG
   LOCAL LineNumber AS LONG
   LOCAL strText AS STRING
   LOCAL pSb AS IStringBuilderA

   pSb = CLASS "StringBuilderA"
   IF ISNOTHING(pSb) THEN EXIT SUB

   ' // Get the current line
   LineNumber = SCI_GetCurrentLineNumber(hSci)
   ' // Get the tab size
   TabSize = SCI_GetTabWidth(hSci)
   IF TabSize < 1 THEN EXIT SUB
   ' // Get the length of the text
   nLen = SCI_GetTextLength(hSci)
   ' // Stimate a 20% of size increase
   pSb.Capacity = nLen \ 5 + nLen
   ' // Get the number of lines
   nLines = SCI_GetLineCount(hSci)
   ' // Remove tabs, line by line
   FOR i = 0 TO nLines - 1
      strText = SCI_GetLine(hSci, i)
      pSb.Add(TAB$(strText, TabSize))
   NEXT
   ' // Set the new text
   SCI_SetText(hSci, pSb.String)
   ' // Set the caret position
   SCI_GotoLine(hSci, LineNumber)

END SUB
' ========================================================================================
' ========================================================================================
' Replace tabs with spaces
' ========================================================================================
SUB SCIP_ReplaceTabsWithSpaces (BYVAL pSci AS DWORD)

   LOCAL i AS LONG
   LOCAL nLen AS LONG
   LOCAL nLines AS LONG
   LOCAL TabSize AS LONG
   LOCAL LineNumber AS LONG
   LOCAL strText AS STRING
   LOCAL pSb AS IStringBuilderA

   pSb = CLASS "StringBuilderA"
   IF ISNOTHING(pSb) THEN EXIT SUB

   ' // Get the current line
   LineNumber = SCI_GetCurrentLineNumber(pSci)
   ' // Get the tab size
   TabSize = SCI_GetTabWidth(pSci)
   IF TabSize < 1 THEN EXIT SUB
   ' // Get the length of the text
   nLen = SCI_GetTextLength(pSci)
   ' // Stimate a 20% of size increase
   pSb.Capacity = nLen \ 5 + nLen
   ' // Get the number of lines
   nLines = SCI_GetLineCount(pSci)
   ' // Remove tabs, line by line
   FOR i = 0 TO nLines - 1
      strText = SCI_GetLine(pSci, i)
      pSb.Add(TAB$(strText, TabSize))
   NEXT
   ' // Set the new text
   SCI_SetText(pSci, pSb.String)
   ' // Set the caret position
   SCI_GotoLine(pSci, LineNumber)

END SUB
' ========================================================================================

' ========================================================================================
' Converts selected text to uppercase
' fCase = 1 (upper case), 2 (lower case), 3 (mixed case)
' ========================================================================================
SUB SCIP_ChangeSelectionCase (BYVAL pSci AS DWORD, BYVAL fCase AS LONG)

   LOCAL startSelPos AS LONG        ' // Starting position
   LOCAL endSelPos   AS LONG        ' // Ending position
   LOCAL strText     AS STRING      ' // Selected text

   IF fCase < 1 OR fCase > 3 THEN EXIT SUB
   ' // If startSelPos and endSelPos are the same there is not selection,
   startSelPos = SCIP_GetSelectionStart(pSci)
   endSelPos = SCIP_GetSelectionEnd(pSci)
   IF startSelPos = endSelPos THEN EXIT SUB
   ' // Retrieve the text
   strText = SCIP_GetTextRange(pSci, startSelPos, endSelPos)
   ' Convert it to upper or lower case
   IF fCase = 1 THEN
      strText = UCASE$(strText)
   ELSEIF fCase = 2 THEN
      strText = LCASE$(strText)
   ELSEIF fCase = 3 THEN
      strText = MCASE$(strText)
   END IF
   ' // Replace the selected text
   SCIP_ReplaceSel(pSci, strText)

END SUB
' ========================================================================================
' ========================================================================================
SUB SCI_ChangeSelectionCase (BYVAL hSci AS DWORD, BYVAL fCase AS LONG)
   SCIP_ChangeSelectionCase(SCI_GetDirectPointer(hSci), fCase)
END SUB
' ========================================================================================

' ========================================================================================
' Change selected text to upper case
' ========================================================================================
SUB SCIP_ChangeSelectionToUpperCase (BYVAL pSci AS DWORD)
   SCIP_ChangeSelectionCase(pSci, 1)
END SUB
' ========================================================================================
SUB SCI_ChangeSelectionToUpperCase (BYVAL hSci AS DWORD)
   SCIP_ChangeSelectionCase(SCI_GetDirectPointer(hSci), 1)
END SUB
' ========================================================================================

' ========================================================================================
' Change selected text to lower case
' ========================================================================================
SUB SCIP_ChangeSelectionToLowerCase (BYVAL pSci AS DWORD)
   SCIP_ChangeSelectionCase(pSci, 2)
END SUB
' ========================================================================================
SUB SCI_ChangeSelectionToLowerCase (BYVAL hSci AS DWORD)
   SCIP_ChangeSelectionCase(SCI_GetDirectPointer(hSci), 2)
END SUB
' ========================================================================================

' ========================================================================================
' Change selected text to mixed case
' ========================================================================================
SUB SCIP_ChangeSelectionToMixedCase (BYVAL pSci AS DWORD)
   SCIP_ChangeSelectionCase(pSci, 3)
END SUB
' ========================================================================================
SUB SCI_ChangeSelectionToMixedCase (BYVAL hSci AS DWORD)
   SCIP_ChangeSelectionCase(SCI_GetDirectPointer(hSci), 3)
END SUB
' ========================================================================================

' ========================================================================================
' Toggles bookmark
' ========================================================================================
SUB SCI_ToggleBookmark (BYVAL hSci AS DWORD)
   LOCAL fMark AS LONG
   fMark = SCI_MarkerGet(hSci, SCI_GetCurrentLineNumber(hSci))
   IF BIT(fMark, 0) = %TRUE THEN
      SCI_MarkerDelete(hSci, SCI_GetCurrentLineNumber(hSci), 0)
   ELSE
      SCI_MarkerAdd(hSci, SCI_GetCurrentLineNumber(hSci), 0)
   END IF
END SUB
' ========================================================================================
' ========================================================================================
SUB SCIP_ToggleBookmark (BYVAL pSci AS DWORD)
   LOCAL fMark AS LONG
   fMark = SCIP_MarkerGet(pSci, SCIP_GetCurrentLineNumber(pSci))
   IF BIT(fMark, 0) = %TRUE THEN
      SCIP_MarkerDelete(pSci, SCIP_GetCurrentLineNumber(pSci), 0)
   ELSE
      SCIP_MarkerAdd(pSci, SCIP_GetCurrentLineNumber(pSci), 0)
   END IF
END SUB
' ========================================================================================

' ========================================================================================
' Next bookmark
' ========================================================================================
SUB SCI_NextBookmark (BYVAL hSci AS DWORD)
   LOCAL fMark AS LONG
   LOCAL nLine AS LONG
   BIT SET fMark, 0
   nLine = SCI_MarkerNext(hSci, SCI_GetCurrentLineNumber(hSci) + 1, fMark)
   IF nLine > -1 THEN
      SCI_GotoLine(hSci, nLine)
   ELSE
      nLine = SCI_MarkerNext(hSci, 0, fMark)
      IF nLine > - 1 THEN
         SCI_GotoLine(hSci, nLine)
      END IF
   END IF
END SUB
' ========================================================================================
' ========================================================================================
SUB SCIP_NextBookmark (BYVAL pSci AS DWORD)
   LOCAL fMark AS LONG
   LOCAL nLine AS LONG
   BIT SET fMark, 0
   nLine = SCI_MarkerNext(pSci, SCIP_GetCurrentLineNumber(pSci) + 1, fMark)
   IF nLine > -1 THEN
      SCIP_GotoLine(pSci, nLine)
   ELSE
      nLine = SCIP_MarkerNext(pSci, 0, fMark)
      IF nLine > - 1 THEN
         SCIP_GotoLine(pSci, nLine)
      END IF
   END IF
END SUB
' ========================================================================================

' ========================================================================================
' Previous bookmark
' ========================================================================================
SUB SCI_PrevBookmark (BYVAL hSci AS DWORD)
   LOCAL fMark AS LONG
   LOCAL nLine AS LONG
   BIT SET fMark, 0
   nLine = SCI_MarkerPrevious(hSci, SCI_GetCurrentLineNumber(hSci) - 1, fMark)
   IF nLine > -1 THEN
      SCI_GotoLine(hSci, nLine)
   ELSE
      nLine = SCI_MarkerPrevious(hSci, SCI_GetLineCount(hSci) - 1, fMark)
      IF nLine > - 1 THEN
         SCI_GotoLine(hSci, nLine)
      END IF
   END IF
END SUB
' ========================================================================================
' ========================================================================================
SUB SCIP_PrevBookmark (BYVAL pSci AS DWORD)
   LOCAL fMark AS LONG
   LOCAL nLine AS LONG
   BIT SET fMark, 0
   nLine = SCIP_MarkerPrevious(pSci, SCIP_GetCurrentLineNumber(pSci) - 1, fMark)
   IF nLine > -1 THEN
      SCIP_GotoLine(pSci, nLine)
   ELSE
      nLine = SCIP_MarkerPrevious(pSci, SCIP_GetLineCount(pSci) - 1, fMark)
      IF nLine > - 1 THEN
         SCIP_GotoLine(pSci, nLine)
      END IF
   END IF
END SUB
' ========================================================================================

' ========================================================================================
' Delete all bookmarks
' ========================================================================================
SUB SCI_DeleteBookmark (BYVAL hSci AS DWORD)
   SCI_MarkerDeleteAll(hSci, 0)
END SUB
' ========================================================================================
' ========================================================================================
SUB SCIP_DeleteBookmark (BYVAL pSci AS DWORD)
   SCIP_MarkerDeleteAll(pSci, 0)
END SUB
' ========================================================================================

' ========================================================================================
' Block comment
' ========================================================================================
SUB SCIP_BlockComment (BYVAL pSci AS DWORD)

   LOCAL i           AS LONG     ' // Loop counter
   LOCAL x           AS LONG     ' // Loop counter
   LOCAL curPos      AS LONG     ' // Current position
   LOCAL startPos    AS LONG     ' // Starting position
   LOCAL endPos      AS LONG     ' // Ending position
   LOCAL startLine   AS LONG     ' // Starting line
   LOCAL endLine     AS LONG     ' // Ending line
   LOCAL nCol        AS LONG     ' // Column
   LOCAL nPos        AS LONG     ' // Position
   LOCAL strLineText AS STRING   ' // Buffer
   LOCAL strText     AS STRING   ' // Portion of the line to replace
   LOCAL IndentSize  AS LONG     ' // Size of indentation
   LOCAL nCount      AS LONG     ' // Number of "'" added

   IF pSci = 0 THEN EXIT SUB
   curPos = SCIP_GetCurrentPos(pSci)
   startPos = SCIP_GetSelectionStart(pSci)
   startLine = SCIP_LineFromPosition(pSci, startPos)
   endPos = SCIP_GetSelectionEnd(pSci)
   endLine = SCIP_LineFromPosition(pSci, endPos)
   nCol = SCIP_GetColumn(pSci, endPos)
   IF nCol = 0  AND endLine > startLine THEN endLine = endLine - 1
   SCIP_GotoLine(pSci, startLine)
   ' // If is the head line...
   IF (SCIP_GetFoldLevel(pSci, startLine) AND %SC_FOLDLEVELHEADERFLAG) <> 0 THEN
      ' // If it is folded...
      IF ISFALSE SCIP_GetFoldExpanded(pSci, startLine) THEN
         ' // ... toggle it
         SCIP_ToggleFold(pSci, startLine)
      END IF
   END IF
   FOR i = startLine TO endLine
      strText = ""
      strLineText = SCIP_GetLine(pSci, i)
      IndentSize = SCIP_GetIndent(pSci)
      FOR x = 1 TO LEN(strLineText)
         IF MID$(strLineText, x, 1) <> " " AND MID$(strLineText, x, 1) <> CHR$(9) THEN
            strText = LEFT$(strLineText, x - 1)
            EXIT FOR
         END IF
      NEXT
      strLineText = LTRIM$(strLineText, ANY CHR$(32, 9, 13, 10))
      nPos = SCIP_PositionFromLine(pSci, i)
      IF LEN(strLineText) THEN
         strText = "'" & strText
         SCIP_SetTargetStart(pSci, nPos)
         SCIP_SetTargetEnd(pSci, nPos + LEN(strText) - 1)
         SCIP_ReplaceTarget(pSci, strText)
         IF startLine <> endLine THEN curPos = curPos + 1
         INCR nCount
      END IF
   NEXT
   IF startPos <> endPos THEN
      SCIP_SetSelectionStart(pSci, startPos)
      SCIP_SetSelectionEnd(pSci, endPos + nCount)
   ELSE
      SCIP_SetSelectionStart(pSci, endPos + nCount)
      SCIP_SetSelectionEnd(pSci, endPos + nCount)
   END IF

END SUB
' ========================================================================================
' ========================================================================================
SUB SCI_BlockComment (BYVAL hSci AS DWORD)
   SCIP_BlockComment(SCI_GetDirectPointer(hSci))
END SUB
' ========================================================================================

' ========================================================================================
' Block uncomment
' ========================================================================================
SUB SCIP_BlockUncomment (BYVAL pSci AS DWORD)

   LOCAL i           AS LONG     ' // Loop counter
   LOCAL x           AS LONG     ' // Loop counter
   LOCAL curPos      AS LONG     ' // Current position
   LOCAL startPos    AS LONG     ' // Starting position
   LOCAL endPos      AS LONG     ' // Ending position
   LOCAL startLine   AS LONG     ' // Starting line
   LOCAL endLine     AS LONG     ' // Ending line
   LOCAL nCol        AS LONG     ' // Column
   LOCAL nPos        AS LONG     ' // Position
   LOCAL nLen        AS LONG     ' // Length of the line
   LOCAL strLineText AS STRING   ' // Buffer
   LOCAL strText     AS STRING   ' // Portion of the line to replace
   LOCAL IndentSize  AS LONG     ' // Size of indentation
   LOCAL nCount      AS LONG     ' // Number of "'" removed

   IF ISFALSE pSci THEN EXIT SUB
   curPos = SCIP_GetCurrentPos(pSci)
   startPos = SCIP_GetSelectionStart(pSci)
   startLine = SCIP_LineFromPosition(pSci, startPos)
   endPos = SCIP_GetSelectionEnd(pSci)
   endLine = SCIP_LineFromPosition(pSci, endPos)
   nCol = SCIP_GetColumn(pSci, endPos)
   IF nCol = 0  AND endLine > startLine THEN endLine = endLine - 1
   SCIP_GotoLine(pSci, startLine)
   ' // If is the head line...
   IF (SCIP_GetFoldLevel(pSci, startLine) AND %SC_FOLDLEVELHEADERFLAG) <> 0 THEN
      ' // If it is folded...
      IF ISFALSE SCIP_GetFoldExpanded(pSci, startLine) THEN
         ' // ...toggle it
         SCIP_ToggleFold(pSci, startLine)
      END IF
   END IF
   FOR i = startLine TO endLine
      strText = ""
      strLineText = SCIP_GetLine(pSci, i)
      IndentSize = SCIP_GetIndent(pSci)
      FOR x = 1 TO LEN(strLineText)
         IF MID$(strLineText, x, 1) <> " " AND MID$(strLineText, x, 1) <> CHR$(9) THEN
            strText = LEFT$(strLineText, x - 1)
            EXIT FOR
         END IF
      NEXT
      strLineText = LTRIM$(strLineText, ANY CHR$(32, 9, 13, 10))
      nPos = SCIP_PositionFromLine(pSci, i)
      IF LEN(strLineText) THEN
         IF LEFT$(strLineText, 1) = "'" THEN
            SCIP_SetTargetStart(pSci, nPos)
            SCIP_SetTargetEnd(pSci, nPos + LEN(strText) + 1)
            SCIP_ReplaceTarget(pSci, strText)
            IF startLine <> endLine THEN curPos = curPos - 1
            INCR nCount
         END IF
      END IF
   NEXT
   IF startPos <> endPos THEN
      SCIP_SetSelectionStart(pSci, startPos)
      SCIP_SetSelectionEnd(pSci, endPos - nCount)
   ELSE
      SCIP_SetSelectionStart(pSci, endPos - nCount)
      SCIP_SetSelectionEnd(pSci, endPos - nCount)
   END IF

END SUB
' ========================================================================================
' ========================================================================================
SUB SCI_BlockUncomment (BYVAL hSci AS DWORD)
   SCIP_BlockUncomment(SCI_GetDirectPointer(hSci))
END SUB
' ========================================================================================

' ========================================================================================
' Find and replace text
' Return value: new position if successful; -1 if text not found.
' ========================================================================================
FUNCTION SCIP_FindReplace (BYVAL pSci AS DWORD, BYVAL strFindText AS STRING, BYVAL strReplaceText AS STRING) AS LONG

   LOCAL findFlags AS LONG
   LOCAL startPos  AS LONG
   LOCAL endPos    AS LONG
   LOCAL newPos    AS LONG

   ' // Find flags
   findFlags = %SCFIND_MATCHCASE OR %SCFIND_WHOLEWORD
   ' // Begin to search from the current position
   startPos = SCIP_GetCurrentPos(pSci)
   ' // End position = length of the document
   endPos = SCIP_GetTextLength(pSci)
   ' // Set the start position
   SCIP_SetTargetStart(pSci, startPos)
   ' // Set the end position
   SCIP_SetTargetEnd(pSci, endPos)
   ' // Set the search flags
   SCIP_SetSearchFlags(pSci, findFlags)
   ' // Search the text to replace
   newPos = SCIP_SearchInTarget(pSci, strFindText)
   ' // Return -1 if not found
   IF CINT(newPos) = - 1 THEN FUNCTION = -1 : EXIT FUNCTION
   ' // Position the caret and select the text
   SCIP_SetCurrentPos(pSci, newPos)
   SCIP_GotoPos(pSci, newPos)
   SCIP_SetSelectionStart(pSci, newPos)
   SCIP_SetSelectionEnd(pSci, newPos + LEN(strFindText))
   ' // Replace the selection
   SCIP_ReplaceSel(pSci, strReplaceText)
   ' // Return the new position
   FUNCTION = newPos

END FUNCTION
' ========================================================================================

' ========================================================================================
' Find and replace text
' ========================================================================================
FUNCTION SCI_FindReplace (BYVAL hSci AS DWORD, BYVAL strFindText AS STRING, BYVAL strReplaceText AS STRING) AS LONG
   FUNCTION = SCIP_FindReplace(SCI_GetDirectPointer(hSci), strFindText, strReplaceText)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Get word at the specified location or under the cursor
' ========================================================================================
FUNCTION SCIP_GetWord (BYVAL pSci AS DWORD, OPTIONAL BYVAL curPos AS LONG) AS STRING

   LOCAL x      AS LONG     ' // Word starting position
   LOCAL y      AS LONG     ' // Word ending position
   LOCAL p      AS LONG     ' // Position
   LOCAL buffer AS STRING   ' // General purpose buffer

   ' // Retrieve the current position
   IF curPos = 0 THEN curPos = SCIP_GetCurrentPos(pSci)
   ' // Retrieve the starting position of the word
   x = SCIP_WordStartPosition(pSci, curPos, %TRUE)
   ' // Retrieve the ending position of the word
   y = SCIP_WordEndPosition(pSci, curPos, %FALSE)
   IF y > x THEN
      ' // Text range
      buffer = SCIP_GetTextRange(pSci, x, y)
      ' // Remove the $NUL
      p = INSTR(buffer, CHR$(0))
      IF p THEN  buffer = LEFT$(buffer, p - 1)
   END IF
   buffer = REMOVE$(buffer, ANY CHR$(13, 10))
   buffer = REMOVE$(buffer, ANY "()%," & $DQ)
   FUNCTION = buffer

END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_GetWord (BYVAL hSci AS DWORD, OPTIONAL BYVAL curPos AS LONG) AS STRING
   FUNCTION = SCIP_GetWord(SCI_GetDirectPointer(hSci), curPos)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Replaces spaces with tabs
' Based on code originally written by Steve Miltiadous
' ========================================================================================
FUNCTION SCIP_SpacesToTabs (BYVAL pSci AS DWORD, BYVAL strIn AS STRING) AS STRING

   LOCAL i       AS LONG     ' // Loop counter
   LOCAL TabSize AS LONG     ' // Size of the tab
   LOCAL strSpc  AS STRING   ' // Spaces
   LOCAL strTab  AS STRING   ' // Tabs
   LOCAL strOut  AS STRING   ' // Output string

   IF ISNULL(strIn) THEN EXIT FUNCTION

   ' // Retrieve the tab size
   TabSize = SCIP_GetTabWidth(pSci)
   IF TabSize < 1 THEN
      FUNCTION = strIn
      EXIT FUNCTION
   END IF

   ' // Calculate the number of spaces and tabs needed
   FOR i = 1 TO LEN(strIn)
      IF INSTR(MID$(strIn, i, 1), CHR$(32))  THEN
         strSpc += MID$(strIn, i, 1)
      ELSEIF INSTR(MID$(strIn, i, 1), CHR$(9) ) THEN
         strTab += MID$(strIn, i, 1)
      ELSE
         EXIT FOR
      END IF
   NEXT

   ' // Replace spaces with tabs
   IF LEN(strSpc) >= TabSize THEN
      REPLACE SPACE$(TabSize) WITH $TAB IN strSpc
      strOut = strTab & strSpc & MID$(strIn, i)
   ELSE
      strOut = strIn
   END IF

   ' // Return the resulting string
   FUNCTION = strOut

END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION SCI_SpacesToTabs (BYVAL hSci AS DWORD, BYVAL strIn AS STRING) AS STRING
   FUNCTION = SCIP_SpacesToTabs(SCI_GetDirectPointer(hSci), strIn)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Formats the selected region removing/adding spaces where nessesary
' Based on code originally written by Steve Miltiadous
' ========================================================================================
SUB SCIP_FormatRegion (BYVAL pSci AS DWORD)

   LOCAL startPos        AS LONG     ' // Start of selected text
   LOCAL endPos          AS LONG     ' // End of selected text
   LOCAL startLine       AS LONG     ' // Starting line
   LOCAL endLine         AS LONG     ' // Ending line
   LOCAL LineLen         AS LONG     ' // Length of the line
   LOCAL buffer          AS STRING   ' // Buffer
   LOCAL i               AS LONG     ' // Loop counter
   LOCAL strFill         AS STRING   ' // Filler string
   LOCAL RemLine         AS STRING   ' // REMed line
   LOCAL bIsWithinString AS LONG     ' // Flag

   startPos = SCIP_GetSelectionStart(pSci)
   endPos = SCIP_GetSelectionEnd(pSci)
   startLine = SCIP_LineFromPosition(pSci, startPos)
   endLine = SCIP_LineFromPosition(pSci, endPos)

   WHILE startLine <= endLine

      RemLine = ""
      buffer = SCIP_GetLine(pSci, startLine)
      IF LEN(REMOVE$(buffer, ANY CHR$(13, 10, 32))) THEN
         FOR i = 1 TO LEN(buffer)
            IF INSTR(MID$(buffer, i, 1), ANY CHR$(32, 9)) = 0 THEN EXIT FOR
         NEXT
         strFill = MID$(buffer, 1 , i - 1)
         WHILE i < LEN(buffer)
            IF ASC(MID$(buffer, i, 1)) = 34 THEN
               bIsWithinString = IIF&(bIsWithinString = %TRUE, %FALSE, %TRUE)
            END IF
            IF ISFALSE bIsWithinString THEN
               SELECT CASE MID$(buffer, i, 1)
                  CASE ">"   ' // ASC 62
                     IF ASC(MID$(strFill, -1)) = 32 AND (ASC(MID$(strFill, -2)) = 61 OR ASC(MID$(strFill, -2)) = 60) THEN
                        strFill = MID$(strFill, 1, LEN(strFill) - 1) & MID$(buffer, i, 1) & " "
                     ELSE
                        IF ASC(MID$(strFill, -1)) = 32 THEN
                           strFill += MID$(buffer, i, 1) & " "
                        ELSE
                           strFill += " " & MID$(buffer, i, 1) & " "
                        END IF
                     END IF
                  CASE "<"   ' // ASC 60
                     IF ASC(MID$(strFill, - 1)) = 32 AND (ASC(MID$(strFill, - 2)) = 61 OR ASC(MID$(strFill, - 2)) = 62) THEN
                        strFill = MID$(strFill, 1, LEN(strFill) - 1) & MID$(buffer, i, 1) & " "
                     ELSE
                        IF ASC(MID$(strFill, - 1)) = 32 THEN
                           strFill += MID$(buffer, i, 1) & " "
                        ELSE
                           strFill += " " & MID$(buffer, i, 1) & " "
                        END IF
                     END IF
                  CASE "'"
                     RemLine = REMOVE$(MID$(buffer, i), $CRLF)
                     EXIT LOOP
                  CASE " "
                     IF MID$(strFill, -1) <> " " AND _
                     MID$(strFill, -1) <> "(" THEN strFill = strFill & " "
                  CASE "-"
                     IF MID$(strFill, -1) <> " " THEN
                        IF MID$(strFill, -2, 1) <> "=" THEN
                           strFill = strFill & " " & MID$(buffer, i, 1) & " "
                        ELSE
                           strFill = strFill & " " & MID$(buffer, i, 1)
                        END IF
                     ELSE
                        IF MID$(strFill, -2, 1) <> "=" THEN
                           strFill = strFill & MID$(buffer, i, 1) & " "
                        ELSE
                           strFill = strFill & MID$(buffer, i, 1)
                        END IF
                     END IF
                  CASE "="
                     SELECT CASE MID$(strFill, -1)
                        CASE ">", "<" : strFill = strFill & MID$(buffer, i, 1) & " "
                        CASE " "
                           IF ASC(MID$(strFill, -2)) = 60 OR ASC(MID$(strFill, -2)) = 62 THEN
                              strFill = MID$(strFill, 1, LEN(strFill) - 1) & MID$(buffer, i, 1) & " "
                           ELSE
                              strFill += MID$(buffer, i, 1) & " "
                           END IF
                        CASE ELSE
                           strFill += " " & MID$(buffer, i, 1) & " "
                     END SELECT
                  CASE "+", "*", "/"
                     IF MID$(strFill, -1) <> " " THEN
                        strFill += " " & MID$(buffer, i, 1) & " "
                     ELSE
                        strFill += MID$(buffer, i, 1) & " "
                     END IF
                  CASE ","
                     IF MID$(strFill, -1) = " " THEN
                        strFill = MID$(strFill, 1, LEN(strFill) - 1) & MID$(buffer, i, 1)
                     ELSE
                        strFill = strFill & MID$(buffer, i, 1) & " "
                     END IF
                  CASE ")"
                     IF MID$(strFill, -1) = " " THEN
                        strFill = MID$(strFill, 1, LEN(strFill) - 1) & MID$(buffer, i, 1)
                     ELSE
                        IF MID$(buffer, i + 1, 1) = "." THEN
                           strFill += MID$(buffer, i, 1)
                        ELSE
                           strFill += MID$(buffer, i, 1) & " "
                        END IF
                     END IF
                  CASE ELSE
                     strFill = strFill & MID$(buffer, i, 1)
               END SELECT
            ELSE
               IF MID$(buffer, i, 1) = "_" THEN   ' // Line continuation
                  IF MID$(strFill, -1) <> " " THEN strFill = strFill & " "
               END IF
               strFill = strFill & MID$(buffer, i, 1)
            END IF
            INCR i
         WEND
         strFill = REMOVE$(strFill, CHR$(13))
         strFill = RTRIM$(strFill)   ' // Remove trailing spaces
         IF LEN(RemLine) > 0 THEN strFill += SPACE$((i - 1) - LEN(strFill)) & RemLine
         IF SCIP_GetUseTabs(pSci) THEN strFill = SCIP_SpacesToTabs(pSci, strFill)
         SCIP_GotoPos(pSci, SCIP_PositionFromLine(pSci, startLine))
         SCIP_SetAnchor(pSci, SCIP_GetLineEndPosition(pSci, startLine))
         SCIP_ReplaceSel(pSci, strFill)
      END IF
      INCR startLine
   WEND

END SUB
' ========================================================================================
' ========================================================================================
SUB SCI_FormatRegion (BYVAL hSci AS DWORD)
   SCIP_FormatRegion(SCI_GetDirectPointer(hSci))
END SUB
' ========================================================================================

' ========================================================================================
' Tabulate the selected region removing/adding spaces where nessesary
' Based on code originally written by Steve Miltiadous
' ========================================================================================
SUB SCIP_TabulateRegion (BYVAL pSci AS DWORD)

   LOCAL i             AS LONG     ' // Loop counter
   LOCAL j             AS LONG     ' // Loop counter
   LOCAL startPos      AS LONG     ' // Start of selected text
   LOCAL endPos        AS LONG     ' // End of selected text
   LOCAL indent        AS LONG     ' // Indentation
   LOCAL startLine     AS LONG     ' // Starting line
   LOCAL prevStartLine AS LONG     ' // Previous starting line
   LOCAL endLine       AS LONG     ' // Ending line
   LOCAL buffer        AS STRING   ' // Buffer
   LOCAL strFill       AS STRING   ' // Filling string
   LOCAL TabSize       AS LONG     ' // Tab size
   LOCAL nSpaces       AS LONG     ' // Number of spaces
   LOCAL WordNumber    AS LONG     ' // Number of words
   LOCAL rgLines()     AS STRING   ' // Array of lines
   LOCAL rgRemLines()  AS STRING   ' // Array of remed lines
   LOCAL rgWords()     AS STRING   ' // Array of words
   LOCAL rgPrevLines() AS LONG     ' // Array of previous lines
   LOCAL nCol          AS LONG     ' // Number of column

   TabSize = SCIP_GetTabWidth(pSci)
   startPos = SCIP_GetSelectionStart(pSci)
   endPos = SCIP_GetSelectionEnd(pSci)
   startLine = SCIP_LineFromPosition(pSci, startPos)
   endLine = SCIP_LineFromPosition(pSci, endPos)
   nCol = SCIP_GetColumn(pSci, endPos)
   IF nCol = 0  AND endLine > startLine THEN endLine = endLine - 1
   prevStartLine = startLine

   indent = -1

   WHILE startLine <= endLine
      strFill = ""
      buffer = SCIP_GetLine(pSci, startLine)
      nSpaces = 0
      IF LEN(REMOVE$(buffer, ANY CHR$(13, 10, 32, 9))) THEN
         FOR i = 1 TO LEN(buffer)
            IF MID$(buffer, i, 1) <> $SPC THEN
               IF MID$(buffer, i, 1) = $TAB THEN
                  nSpaces += TabSize
               ELSE
                  EXIT FOR
               END IF
            ELSE
               INCR nSpaces
            END IF
         NEXT
         IF LEN(REMOVE$(buffer, $CRLF)) THEN
            IF indent = -1 OR indent > nSpaces THEN indent = nSpaces
         END IF
         REDIM PRESERVE rgRemLines(UBOUND(rgRemLines) + 1)
         rgRemLines(UBOUND(rgRemLines)) = ""
         WHILE i < LEN(buffer)
            SELECT CASE MID$(buffer, i, 1)
               CASE "'"
                  rgRemLines(UBOUND(rgRemLines)) = REMOVE$(MID$(buffer, i ), $CRLF)
                  EXIT LOOP
               CASE " "
                  IF MID$(strFill, -1) <> " " AND _
                  IIF(i + 1 < LEN(buffer), IIF( INSTR(MID$(buffer, i + 1, 1), ANY CHR$(32, 13, 10))  <> 0,%FALSE, %TRUE) , %FALSE ) AND _
                  MID$(strFill, -1) <> "(" THEN strFill += " "
               CASE "-"
                  IF MID$(strFill, -1) <> " " THEN
                     IF MID$(strFill, -2, 1) <> "=" THEN
                        strFill += " " & MID$(buffer, i, 1) & " "
                     ELSE
                        strFill += " " & MID$(buffer, i, 1)
                     END IF
                  ELSE
                     IF MID$(strFill, -2, 1) <> "=" THEN
                        strFill += MID$(buffer, i, 1) & " "
                     ELSE
                        strFill += MID$(buffer, i, 1)
                     END IF
                  END IF
               CASE "=" , "+",  "*", "/"
                  IF MID$(strFill, -1) <> " " THEN
                     strFill += " " + MID$(buffer, i, 1) & " "
                  ELSE
                     strFill += MID$(buffer, i, 1) & " "
                  END IF
               CASE "," , ")"
                  IF MID$(strFill, -1) = " " THEN
                     strFill = MID$(strFill, 1, LEN(strFill) - 1) & MID$(buffer, i, 1)
                  ELSE
                     strFill += MID$(buffer, i, 1) & " "
                  END IF
                CASE ELSE
                  strFill += MID$(buffer, i, 1)
            END SELECT
            INCR i
         WEND
         strFill = REMOVE$(strFill, CHR$(13))
         IF WordNumber < PARSECOUNT(strFill, " " ) THEN
            WordNumber = PARSECOUNT(strFill, " " )
            REDIM PRESERVE rgPrevLines(WordNumber)
         END IF
         REDIM PRESERVE rgLines(UBOUND(rgLines) + 1)
         rgLines(UBOUND(rgLines)) = strFill
         FOR i = 1 TO PARSECOUNT(strFill, " " )
            IF rgPrevLines(i-1) < LEN( PARSE$(strFill, " " , i)) THEN rgPrevLines(i - 1) = LEN(PARSE$(strFill, " " , i))
         NEXT
      ELSE
         REDIM PRESERVE rgLines(UBOUND(rgLines) + 1)
         rgLines(UBOUND(rgLines)) = REMOVE$(buffer, CHR$(13, 10))
         REDIM PRESERVE rgRemLines(UBOUND(rgRemLines) + 1)
         rgRemLines(UBOUND(rgRemLines)) = ""
      END IF
      INCR startLine
   WEND
   FOR i = 0 TO UBOUND(rgLines)
      IF LEN(REMOVE$(rgLines(i), ANY CHR$(13, 10, 32, 9)))  THEN
         strFill = SPACE$(indent)
         REDIM rgWords(PARSECOUNT(rgLines(i), ANY  " "))
         PARSE rgLines(i), rgWords(), ANY " "
         FOR j = 0 TO UBOUND(rgWords)
            IF j < UBOUND(rgWords) THEN
               strFill += rgWords(j) & SPACE$(rgPrevLines(j) - LEN(rgWords(j)) + 1)
            ELSE
               IF rgWords(j) = $CRLF THEN
                  IF MID$(strFill,-1, 1) = " " THEN
                     strFill = MID$(strFill, 1, LEN(strFill) - 1) & rgWords(j)
                  ELSE
                     strFill += rgWords(j)
                  END IF
               ELSE
                  strFill += rgWords(j)
               END IF
            END IF
         NEXT
         nSpaces = 0
         IF i <= UBOUND(rgRemLines) THEN
            FOR j = 0 TO UBOUND(rgPrevLines)
               nSpaces = nSpaces + rgPrevLines(j) + 1
            NEXT
            strFill += SPACE$((nSpaces + indent) - LEN(strFill)) & rgRemLines(i)
            strFill = RTRIM$(strFill)
         END IF
      ELSE
         ITERATE FOR
      END IF
      IF SCIP_GetUseTabs(pSci) THEN strFill = SCIP_SpacesToTabs(pSci, strFill)
      SCIP_GotoPos(pSci, SCIP_PositionFromLine(pSci, prevStartLine + i))
      SCIP_SetAnchor(pSci, SCIP_GetLineEndPosition(pSci, prevStartLine + i))
      SCIP_ReplaceSel(pSci, strFill)
   NEXT

END SUB
' ========================================================================================
' ========================================================================================
SUB SCI_TabulateRegion (BYVAL hSci AS DWORD)
   SCIP_TabulateRegion(SCI_GetDirectPointer(hSci))
END SUB
' ========================================================================================

' ========================================================================================
' Shrinks the text
' ========================================================================================
SUB SCIP_Shrink (BYVAL pSci AS DWORD, OPTIONAL BYVAL bTrimTrailingBlanks AS LONG)
   LOCAL p AS LONG
   LOCAL buffer AS STRING
   ' // Get the text
   buffer = SCIP_GetText(pSci)
   ' // Shink it
   buffer = SHRINK$(buffer, CHR$(32, 9))
   ' // Trim trailing spaces and tabs
   IF bTrimTrailingBlanks THEN
      DO
         p = LEN(buffer)
         REPLACE " " & $CR WITH $CR IN buffer
         REPLACE $TAB & $CR WITH $CR IN buffer
      LOOP UNTIL p = LEN(buffer)
   END IF
   ' // Set the text
   SCIP_SetText(pSci, buffer)
END SUB
' ========================================================================================
' ========================================================================================
SUB SCI_Shrink (BYVAL hSci AS DWORD, OPTIONAL BYVAL bTrimTrailingBlanks AS LONG)
   SCIP_Shrink(SCI_GetDirectPointer(hSci), bTrimTrailingBlanks)
END SUB
' ========================================================================================
