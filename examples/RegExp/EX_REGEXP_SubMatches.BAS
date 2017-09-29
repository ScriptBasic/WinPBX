' The following code illustrates how to obtain a SubMatches collection from a regular
' expression search and how to access its individual members.
' Adaptation of the following example from Microsoft:
'
' Function SubMatchTest(inpStr)
'   Dim oRe, oMatch, oMatches
'   Set oRe = New RegExp
'   ' Look for an e-mail address (not a perfect RegExp)
'   oRe.Pattern = "(\w+)@(\w+)\.(\w+)"
'   ' Get the Matches collection
'   Set oMatches = oRe.Execute(inpStr)
'   ' Get the first item in the Matches collection
'   Set oMatch = oMatches(0)
'   ' Create the results string.
'   ' The Match object is the entire match - dragon@xyzzy.com
'   retStr = "Email address is: " & oMatch & vbNewline
'   ' Get the sub-matched parts of the address.
'   retStr = retStr & "Email alias is: " & oMatch.SubMatches(0)  ' dragon
'   retStr = retStr & vbNewline
'   retStr = retStr & "Organization is: " & oMatch. SubMatches(1)' xyzzy
'   SubMatchTest = retStr
' End Function

' MsgBox(SubMatchTest("Please send mail to dragon@xyzzy.com. Thanks!"))

#COMPILE EXE
#DIM ALL
%UNICODE = 1

#INCLUDE "windows.inc"
#INCLUDE "regexp.inc"

FUNCTION PBMAIN

   LOCAL pRegExp AS IRegExp
   LOCAL pMatches AS IMatchCollection
   LOCAL pMatch AS IMatch2
   LOCAL pSubMatches AS ISubMatches
   LOCAL nCount AS LONG
   LOCAL bstrValue AS WSTRING
   LOCAL vValue AS VARIANT

   ' Creates an instance of the RegExp object
   pRegExp = NEWCOM "VBScript.RegExp"
   IF ISNOTHING(pRegExp) THEN
      MSGBOX "Unable to create an instance of the RegExp object"
      EXIT FUNCTION
   END IF

   ' Look for an e-mail address (not a perfect RegExp)
   pRegExp.Pattern = "(\w+)@(\w+)\.(\w+)"

   ' Get the Matches collection
   pMatches = pRegExp.Execute("Please send mail to dragon@xyzzy.com. Thanks!")
   IF ISNOTHING(pMatches) THEN
      MSGBOX "No match found"
      EXIT FUNCTION
   END IF

   nCount = pMatches.Count
   IF nCount = 0 THEN
      MSGBOX "No match found"
      EXIT FUNCTION
   END IF

   ' Get the first item in the Matches collection
   pMatch = pMatches.Item(0)

   ' Create the results string.
   ' The Match object is the entire match - dragon@xyzzy.com
   bstrValue = "Email address is: " & pMatch.Value & $CRLF

   ' Get the SubMatches collection
   pSubMatches = pMatch.SubMatches
   IF ISTRUE ISOBJECT(pSubMatches) THEN
      ' Get the sub-matched parts of the address.
      vValue = pSubMatches.Item(0)
      bstrValue += "Email alias is: " & VARIANT$$(vValue) & $CRLF  ' dragon
      vValue = pSubMatches.Item(1)
      bstrValue += "Organization is: " & VARIANT$$(vValue) & $CRLF  ' xyzzy
   END IF

   ? bstrValue

END FUNCTION
