' ========================================================================================
' This example shows how to break a URL into its components, update a component, then
' reconstruct the URL.
' ========================================================================================

' SED_PBCC - Use the console compiler
#COMPILE EXE
#DIM ALL
#INCLUDE "windows.inc"
#INCLUDE "winhttp.inc"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN () AS LONG

   LOCAL urlComp AS URL_COMPONENTSW
   LOCAL wszUrl1 AS WSTRINGZ * 2084   ' %INTERNET_MAX_URL_LENGTH
   LOCAL bstrUrl2 AS WSTRING
   LOCAL dwUrlLen AS DWORD
   LOCAL wszExtraInfo AS WSTRINGZ * 260

   wszUrl1 = "http://search.msn.com/results.asp?RS=CHECKED&FORM=MSNH&v=1&q=wininet"

   ' Initialize the URL_COMPONENTS structure.
   urlComp.dwStructSize = SIZEOF(urlComp)

   ' Set required component lengths to non-zero so that they are cracked.
   urlComp.dwSchemeLength    = -1
   urlComp.dwHostNameLength  = -1
   urlComp.dwUrlPathLength   = -1
   urlComp.dwExtraInfoLength = -1

   ' Crack the URL.
   IF ISFALSE WinHttpCrackUrl(wszUrl1, 0, 0, urlComp) THEN
      PRINT "Error " GetLastError " in WinHttpCrackUrl."
   ELSE
      ' Change the search information.
      ' New info is the same length.
      wszExtraInfo = "?RS=CHECKED&FORM=MSNH&v=1&q=winhttp"
      urlComp.lpszExtraInfo = VARPTR(wszExtraInfo)
      ' Obtain the size of the new URL and allocate memory.
      WinHttpCreateUrl(urlComp, 0, BYVAL %NULL, dwUrlLen)
      bstrUrl2 = SPACE$(dwUrlLen)
      ' Create a new URL.
      IF ISFALSE WinHttpCreateUrl(urlComp, 0, BYVAL STRPTR(bstrUrl2), dwUrlLen) THEN
         PRINT "Error " GetLastError " in WinHttpCreateUrl."
      ELSE
         ' Show both URLs.
         PRINT "Old URL: " & wszUrl1
         PRINT "New URL: " & bstrUrl2
      END IF
   END IF

   WAITKEY$

END FUNCTION
' ========================================================================================
