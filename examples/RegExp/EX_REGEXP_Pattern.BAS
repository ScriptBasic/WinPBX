' Demonstrates the use of the pattern property.

#COMPILE EXE
#DIM ALL
%UNICODE = 1

#INCLUDE "windows.inc"
#INCLUDE "regexp.inc"

FUNCTION PBMAIN

   LOCAL pRegExp AS IRegExp2
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

   pRegExp.Pattern = " b.*fox"
   pRegExp.Global = %VARIANT_FALSE
   pRegExp.IgnoreCase = %VARIANT_TRUE
   pRegExp.Multiline = %VARIANT_TRUE

   pMatches = pRegExp.Execute("The quick brown fox jumped over the lazy dog.")
   IF ISNOTHING(pMatches) THEN
      MSGBOX "No match found"
      EXIT FUNCTION
   END IF

   nCount = pMatches.Count
   IF nCount = 0 THEN
      MSGBOX "No match found"
      EXIT FUNCTION
   END IF

   FOR i = 0 TO nCount - 1
      pMatch = pMatches.Item(i)
      IF ISNOTHING(pMatch) THEN EXIT FOR
      bstrValue = pMatch.Value
      MSGBOX bstrValue
      pMatch = NOTHING
   NEXT

END FUNCTION
