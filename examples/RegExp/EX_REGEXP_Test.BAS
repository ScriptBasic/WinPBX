' The following code illustrates the use of the Test method.

#COMPILE EXE
#DIM ALL
%UNICODE = 1

#INCLUDE "windows.inc"
#INCLUDE "regexp.inc"

FUNCTION PBMAIN

   LOCAL pRegExp AS IRegExp

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

   ' Execute search
   IF ISTRUE pRegExp.Test("IS1 is2 IS3 is4") THEN
      ? "One or more matches were found"
   ELSE
      ? "No match was found"
   END IF

END FUNCTION
