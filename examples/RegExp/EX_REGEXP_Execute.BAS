' The following code illustrates the use of the RegExp object.

' Function RegExpTest(patrn, strng)
'   Dim regEx, Match, Matches   ' Create variable.
'   Set regEx = New RegExp   ' Create a regular expression.
'   regEx.Pattern = patrn   ' Set pattern.
'   regEx.IgnoreCase = True   ' Set case insensitivity.
'   regEx.Global = True   ' Set global applicability.
'   Set Matches = regEx.Execute(strng)   ' Execute search.
'   For Each Match in Matches   ' Iterate Matches collection.
'      RetStr = RetStr & "Match found at position "
'      RetStr = RetStr & Match.FirstIndex & ". Match Value is '"
'      RetStr = RetStr & Match.Value & "'." & vbCRLF
'   Next
'   RegExpTest = RetStr
' End Function
' MsgBox(RegExpTest("is.", "IS1 is2 IS3 is4"))

#COMPILE EXE
#DIM ALL
%UNICODE = 1

#INCLUDE "windows.inc"
#INCLUDE "regexp.inc"

FUNCTION PBMAIN

   LOCAL pRegExp AS IRegExp
   LOCAL pMatches AS IMatchCollection
   LOCAL pMatch AS IMatch
   LOCAL nCount AS LONG
   LOCAL i AS LONG
   LOCAL bstrValue AS WSTRING

   ' Creates an instance of the RegExp object
   pRegExp = NEWCOM "VBScript.RegExp"
   IF ISNOTHING(pRegExp) THEN
      MSGBOX "Unable to create an instance of the RegExp object"
      EXIT FUNCTION
   END IF

   ' Set pattern
   pRegExp.Pattern = "is."
   ' Set case insensitivity
   pRegExp.IgnoreCase = %VARIANT_TRUE
   ' Set global applicability
   pRegExp.Global = %VARIANT_TRUE

   ' Execute search
   pMatches = pRegExp.Execute("IS1 is2 IS3 is4")
   IF ISNOTHING(pMatches) THEN
      MSGBOX "No match found"
   ELSE
      nCount = pMatches.Count
      IF nCount = 0 THEN
         MSGBOX "No match found"
         EXIT FUNCTION
      END IF
      ' Iterate the Matches collection
      FOR i = 0 TO nCount - 1
         pMatch = pMatches.Item(i)
         IF ISNOTHING(pMatch) THEN EXIT FOR
         bstrValue += "Match found at position" & STR$(pMatch.FirstIndex) & $CRLF
         bstrValue += "Match value is " & pMatch.Value & $CRLF
         pMatch = NOTHING
      NEXT
      ? bstrValue
   END IF

END FUNCTION
