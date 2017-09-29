' The following code illustrates use of the Replace method.

' Function ReplaceTest(patrn, replStr)
'  Dim regEx, str1               ' Create variables.
'  str1 = "The quick brown fox jumped over the lazy dog."
'  Set regEx = New RegExp            ' Create regular expression.
'  regEx.Pattern = patrn            ' Set pattern.
'  regEx.IgnoreCase = True            ' Make case insensitive.
'  ReplaceTest = regEx.Replace(str1, replStr)   ' Make replacement.
' End Function

' MsgBox(ReplaceTest("fox", "cat"))      ' Replace 'fox' with 'cat'.

' In addition, the Replace method can replace subexpressions in the pattern.
' The following call to the function shown in the previous example swaps the first
' pair of words in the original string:
' MsgBox(ReplaceTest("(\S+)(\s+)(\S+)", "$3$2$1"))   ' Swap first pair of words.

#COMPILE EXE
#DIM ALL
%UNICODE = 1

#INCLUDE "windows.inc"
#INCLUDE "regexp.inc"

FUNCTION PBMAIN

   LOCAL pRegExp AS IRegExp
   LOCAL bstrText AS WSTRING
   LOCAL bstrRetVal AS WSTRING

   ' Creates an instance of the RegExp object
   pRegExp = NEWCOM "VBScript.RegExp"
   IF ISNOTHING(pRegExp) THEN
      MSGBOX "Unable to create an instance of the RegExp object"
      EXIT FUNCTION
   END IF

   ' Set pattern
   pRegExp.Pattern = "(\S+)(\s+)(\S+)"
   ' Set case insensitivity
   pRegExp.IgnoreCase = %VARIANT_TRUE

   bstrText = "The quick brown fox jumped over the lazy dog."

   ' Make replacement
   bstrRetVal = pRegExp.Replace(bstrText, "$3$2$1")
   ? bstrRetVal

END FUNCTION
