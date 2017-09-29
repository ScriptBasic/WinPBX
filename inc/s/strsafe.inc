' ########################################################################################
' Microsoft Windows
' File: strsafe.inc
' Contents: This module defines safer C library string routine replacements. These are
' meant to make C a bit more safe in reference to security and robustness.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%STRSAFE_INC = 1

'// The user may override STRSAFE_MAX_CCH, but it must always be less than INT_MAX
#IF NOT %DEF(%STRSAFE_MAX_CCH)
%STRSAFE_MAX_CCH    = 2147483647  ' // max buffer size, in characters, that we support (same as INT_MAX)
#ENDIF

%STRSAFE_MAX_LENGTH = (%STRSAFE_MAX_CCH - 1)  ' // max buffer length, in characters, that we support

'// Flags for controling the Ex functions
'//
'//      STRSAFE_FILL_BYTE(0xFF)                0x000000FF  // bottom byte specifies fill pattern
%STRSAFE_IGNORE_NULLS                   = &H00000100???  ' // treat null string pointers as TEXT("") -- don't fault on NULL buffers
%STRSAFE_FILL_BEHIND_NULL               = &H00000200???  ' // on success, fill in extra space behind the null terminator with fill pattern
%STRSAFE_FILL_ON_FAILURE                = &H00000400???  ' // on failure, overwrite pszDest with fill pattern and null terminate it
%STRSAFE_NULL_ON_FAILURE                = &H00000800???  ' // on failure, set *pszDest = TEXT('\0')
%STRSAFE_NO_TRUNCATION                  = &H00001000???  ' // instead of returning a truncated result, copy/append nothing to pszDest and null terminate it

%STRSAFE_VALID_FLAGS = (&H000000FF OR %STRSAFE_IGNORE_NULLS OR %STRSAFE_FILL_BEHIND_NULL OR %STRSAFE_FILL_ON_FAILURE OR %STRSAFE_NULL_ON_FAILURE OR %STRSAFE_NO_TRUNCATION)

'// helper macro to set the fill character and specify buffer filling
MACRO STRSAFE_FILL_BYTE(x)              = (BITS(DWORD, (x AND &H000000FF???) OR %STRSAFE_FILL_BEHIND_NULL))
MACRO STRSAFE_FAILURE_BYTE(x)           = (BITS(DWORD, (x AND &H000000FF???) OR %STRSAFE_FILL_ON_FAILURE))

MACRO STRSAFE_GET_FILL_PATTERN(dwFlags) = (BITS(LONG, dwFlags AND &H000000FF???))


'// error return codes
%STRSAFE_E_INSUFFICIENT_BUFFER          = (&H8007007A&) ' // 0x7A = 122L = ERROR_INSUFFICIENT_BUFFER
%STRSAFE_E_INVALID_PARAMETER            = (&H80070057&) ' // 0x57 =  87L = ERROR_INVALID_PARAMETER
%STRSAFE_E_END_OF_FILE                  = (&H80070026&) ' // 0x26 =  38L = ERROR_HANDLE_EOF

'Routine Description:

'    This routine is a safer version of the C built-in function 'strcpy'.
'    The size of the destination buffer (in characters) is a parameter and
'    this function will not write past the end of this buffer and it will
'    ALWAYS null terminate the destination buffer (unless it is zero length).

'    This routine is not a replacement for strncpy.  That function will pad the
'    destination string with extra null termination characters if the count is
'    greater than the length of the source string, and it will fail to null
'    terminate the destination string if the source string length is greater
'    than or equal to the count. You can not blindly use this instead of strncpy:
'    it is common for code to use it to "patch" strings and you would introduce
'    errors if the code started null terminating in the middle of the string.

'    This function returns a hresult, and not a pointer.  It returns
'    S_OK if the string was copied without truncation and null terminated,
'    otherwise it will return a failure code. In failure cases as much of
'    pszSrc will be copied to pszDest as possible, and pszDest will be null
'    terminated.

'Arguments:

'    pszDest        -   destination string

'    cchDest        -   size of destination buffer in characters.
'                       length must be = (_tcslen(src) + 1) to hold all of the
'                       source including the null terminator

'    pszSrc         -   source string which must be null terminated

'Notes:
'    Behavior is undefined if source and destination strings overlap.

'    pszDest and pszSrc should not be NULL. See StringCchCopyEx if you require
'    the handling of NULL values.

'Return Value:

'    S_OK           -   if there was source data and it was all copied and the
'                       resultant dest string was null terminated

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that the copy
'                       operation failed due to insufficient space. When this
'                       error occurs, the destination buffer is modified to
'                       contain a truncated version of the ideal result and is
'                       null terminated. This is useful for situations where
'                       truncation is ok

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function.

'--*/

DECLARE FUNCTION StringCchCopyA IMPORT "strsafe.dll" ALIAS "StringCchCopyA" ( _
   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cchDest) LPSTR pszDest
 , BYVAL cchDest AS DWORD _                             ' __in  size_t cchDest
 , BYREF pszSrc AS ASCIIZ _                             ' __in  LPCSTR pszSrc
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringCchCopyW IMPORT "strsafe.dll" ALIAS "StringCchCopyW" ( _
   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cchDest) LPWSTR pszDest
 , BYVAL cchDest AS DWORD _                             ' __in  size_t cchDest
 , BYREF pszSrc AS WSTRINGZ _                           ' __in  LPCWSTR pszSrc
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCchCopy = StringCchCopyW
#ELSE
   MACRO StringCchCopy = StringCchCopyA
#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'strcpy'.
'    The size of the destination buffer (in bytes) is a parameter and this
'    function will not write past the end of this buffer and it will ALWAYS
'    null terminate the destination buffer (unless it is zero length).

'    This routine is not a replacement for strncpy.  That function will pad the
'    destination string with extra null termination characters if the count is
'    greater than the length of the source string, and it will fail to null
'    terminate the destination string if the source string length is greater
'    than or equal to the count. You can not blindly use this instead of strncpy:
'    it is common for code to use it to "patch" strings and you would introduce
'    errors if the code started null terminating in the middle of the string.

'    This function returns a hresult, and not a pointer.  It returns
'    S_OK if the string was copied without truncation and null terminated,
'    otherwise it will return a failure code. In failure cases as much of pszSrc
'    will be copied to pszDest as possible, and pszDest will be null terminated.

'Arguments:

'    pszDest        -   destination string

'    cbDest         -   size of destination buffer in bytes.
'                       length must be = ((_tcslen(src) + 1) * sizeof(TCHAR)) to
'                       hold all of the source including the null terminator

'    pszSrc         -   source string which must be null terminated

'Notes:
'    Behavior is undefined if source and destination strings overlap.

'    pszDest and pszSrc should not be NULL.  See StringCbCopyEx if you require
'    the handling of NULL values.

'Return Value:

'    S_OK           -   if there was source data and it was all copied and the
'                       resultant dest string was null terminated

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that the copy
'                       operation failed due to insufficient space. When this
'                       error occurs, the destination buffer is modified to
'                       contain a truncated version of the ideal result and is
'                       null terminated. This is useful for situations where
'                       truncation is ok

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function.

'--*/

DECLARE FUNCTION StringCbCopyA IMPORT "strsafe.dll" ALIAS "StringCbCopyA" ( _
   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cbDest) LPSTR pszDest
 , BYVAL cbDest AS DWORD _                              ' __in  size_t cbDest
 , BYREF pszSrc AS ASCIIZ _                             ' __in  LPCSTR pszSrc
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringCbCopyW IMPORT "strsafe.dll" ALIAS "StringCbCopyW" ( _
   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cbDest) LPWSTR pszDest
 , BYVAL cbDest AS DWORD _                              ' __in  size_t cbDest
 , BYREF pszSrc AS WSTRINGZ _                           ' __in  LPCWSTR pszSrc
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCbCopy = StringCbCopyW
#ELSE
   MACRO StringCbCopy = StringCbCopyA
#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'strcpy' with
'    some additional parameters.  In addition to functionality provided by
'    StringCchCopy, this routine also returns a pointer to the end of the
'    destination string and the number of characters left in the destination string
'    including the null terminator. The flags parameter allows additional controls.

'Arguments:

'    pszDest         -   destination string

'    cchDest         -   size of destination buffer in characters.
'                        length must be = (_tcslen(pszSrc) + 1) to hold all of
'                        the source including the null terminator

'    pszSrc          -   source string which must be null terminated

'    ppszDestEnd     -   if ppszDestEnd is non-null, the function will return a
'                        pointer to the end of the destination string.  If the
'                        function copied any data, the result will point to the
'                        null termination character

'    pcchRemaining   -   if pcchRemaining is non-null, the function will return the
'                        number of characters left in the destination string,
'                        including the null terminator

'    dwFlags         -   controls some details of the string copy:

'        STRSAFE_FILL_BEHIND_NULL
'                    if the function succeeds, the low byte of dwFlags will be
'                    used to fill the uninitialize part of destination buffer
'                    behind the null terminator

'        STRSAFE_IGNORE_NULLS
'                    treat NULL string pointers like empty strings (TEXT("")).
'                    this flag is useful for emulating functions like lstrcpy

'        STRSAFE_FILL_ON_FAILURE
'                    if the function fails, the low byte of dwFlags will be
'                    used to fill all of the destination buffer, and it will
'                    be null terminated. This will overwrite any truncated
'                    string returned when the failure is
'                    STRSAFE_E_INSUFFICIENT_BUFFER

'        STRSAFE_NO_TRUNCATION /
'        STRSAFE_NULL_ON_FAILURE
'                    if the function fails, the destination buffer will be set
'                    to the empty string. This will overwrite any truncated string
'                    returned when the failure is STRSAFE_E_INSUFFICIENT_BUFFER.

'Notes:
'    Behavior is undefined if source and destination strings overlap.

'    pszDest and pszSrc should not be NULL unless the STRSAFE_IGNORE_NULLS flag
'    is specified.  If STRSAFE_IGNORE_NULLS is passed, both pszDest and pszSrc
'    may be NULL.  An error may still be returned even though NULLS are ignored
'    due to insufficient space.

'Return Value:

'    S_OK           -   if there was source data and it was all copied and the
'                       resultant dest string was null terminated

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that the copy
'                       operation failed due to insufficient space. When this
'                       error occurs, the destination buffer is modified to
'                       contain a truncated version of the ideal result and is
'                       null terminated. This is useful for situations where
'                       truncation is ok.

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function

'--*/

DECLARE FUNCTION StringCchCopyExA IMPORT "strsafe.dll" ALIAS "StringCchCopyExA" ( _
   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cchDest) LPSTR pszDest
 , BYVAL cchDest AS DWORD _                             ' __in  size_t cchDest
 , BYREF pszSrc AS ASCIIZ _                             ' __in  LPCSTR pszSrc
 , BYREF ppszDestEnd AS DWORD _                         ' __out LPSTR* ppszDestEnd
 , BYREF pcchRemaining AS DWORD _                       ' __out_opt size_t* pcchRemaining
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringCchCopyExW IMPORT "strsafe.dll" ALIAS "StringCchCopyExW" ( _
   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cchDest) LPWSTR pszDest
 , BYVAL cchDest AS DWORD _                             ' __in  size_t cchDest
 , BYREF pszSrc AS WSTRINGZ _                           ' __in  LPCWSTR pszSrc
 , BYREF ppszDestEnd AS DWORD _                         ' __out LPSTR* ppszDestEnd
 , BYREF pcchRemaining AS DWORD _                       ' __out_opt size_t* pcchRemaining
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCchCopyEx = StringCchCopyExW
#ELSE
   MACRO StringCchCopyEx = StringCchCopyExA
#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'strcpy' with
'    some additional parameters.  In addition to functionality provided by
'    StringCbCopy, this routine also returns a pointer to the end of the
'    destination string and the number of bytes left in the destination string
'    including the null terminator. The flags parameter allows additional controls.

'Arguments:

'    pszDest         -   destination string

'    cbDest          -   size of destination buffer in bytes.
'                        length must be ((_tcslen(pszSrc) + 1) * sizeof(TCHAR)) to
'                        hold all of the source including the null terminator

'    pszSrc          -   source string which must be null terminated

'    ppszDestEnd     -   if ppszDestEnd is non-null, the function will return a
'                        pointer to the end of the destination string.  If the
'                        function copied any data, the result will point to the
'                        null termination character

'    pcbRemaining    -   pcbRemaining is non-null,the function will return the
'                        number of bytes left in the destination string,
'                        including the null terminator

'    dwFlags         -   controls some details of the string copy:

'        STRSAFE_FILL_BEHIND_NULL
'                    if the function succeeds, the low byte of dwFlags will be
'                    used to fill the uninitialize part of destination buffer
'                    behind the null terminator

'        STRSAFE_IGNORE_NULLS
'                    treat NULL string pointers like empty strings (TEXT("")).
'                    this flag is useful for emulating functions like lstrcpy

'        STRSAFE_FILL_ON_FAILURE
'                    if the function fails, the low byte of dwFlags will be
'                    used to fill all of the destination buffer, and it will
'                    be null terminated. This will overwrite any truncated
'                    string returned when the failure is
'                    STRSAFE_E_INSUFFICIENT_BUFFER

'        STRSAFE_NO_TRUNCATION /
'        STRSAFE_NULL_ON_FAILURE
'                    if the function fails, the destination buffer will be set
'                    to the empty string. This will overwrite any truncated string
'                    returned when the failure is STRSAFE_E_INSUFFICIENT_BUFFER.

'Notes:
'    Behavior is undefined if source and destination strings overlap.

'    pszDest and pszSrc should not be NULL unless the STRSAFE_IGNORE_NULLS flag
'    is specified.  If STRSAFE_IGNORE_NULLS is passed, both pszDest and pszSrc
'    may be NULL.  An error may still be returned even though NULLS are ignored
'    due to insufficient space.

'Return Value:

'    S_OK           -   if there was source data and it was all copied and the
'                       resultant dest string was null terminated

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that the copy
'                       operation failed due to insufficient space. When this
'                       error occurs, the destination buffer is modified to
'                       contain a truncated version of the ideal result and is
'                       null terminated. This is useful for situations where
'                       truncation is ok.

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function

'--*/

DECLARE FUNCTION StringCbCopyExA IMPORT "strsafe.dll" ALIAS "StringCbCopyExA" ( _
   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cbDest) LPSTR pszDest
 , BYVAL cbDest AS DWORD _                              ' __in  size_t cbDest
 , BYREF pszSrc AS ASCIIZ _                             ' __in  LPCSTR pszSrc
 , BYREF ppszDestEnd AS DWORD _                         ' __out LPSTR* ppszDestEnd
 , BYREF pcbRemaining AS DWORD _                        ' __out_opt size_t* pcbRemaining
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringCbCopyExW IMPORT "strsafe.dll" ALIAS "StringCbCopyExW" ( _
   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cbDest) LPWSTR pszDest
 , BYVAL cbDest AS DWORD _                              ' __in  size_t cbDest
 , BYREF pszSrc AS WSTRINGZ _                           ' __in  LPCWSTR pszSrc
 , BYREF ppszDestEnd AS DWORD _                         ' __out LPSTR* ppszDestEnd
 , BYREF pcbRemaining AS DWORD _                        ' __out_opt size_t* pcbRemaining
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCbCopyEx = StringCbCopyExW
#ELSE
   MACRO StringCbCopyEx = StringCbCopyExA
#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'strncpy'.
'    The size of the destination buffer (in characters) is a parameter and
'    this function will not write past the end of this buffer and it will
'    ALWAYS null terminate the destination buffer (unless it is zero length).

'    This routine is meant as a replacement for strncpy, but it does behave
'    differently. This function will not pad the destination buffer with extra
'    null termination characters if cchToCopy is greater than the length of pszSrc.

'    This function returns a hresult, and not a pointer.  It returns
'    S_OK if the entire string or the first cchToCopy characters were copied
'    without truncation and the resultant destination string was null terminated,
'    otherwise it will return a failure code. In failure cases as much of pszSrc
'    will be copied to pszDest as possible, and pszDest will be null terminated.

'Arguments:

'    pszDest        -   destination string

'    cchDest        -   size of destination buffer in characters.
'                       length must be = (_tcslen(src) + 1) to hold all of the
'                       source including the null terminator

'    pszSrc         -   source string

'    cchToCopy      -   maximum number of characters to copy from source string,
'                       not including the null terminator.

'Notes:
'    Behavior is undefined if source and destination strings overlap.

'    pszDest and pszSrc should not be NULL. See StringCchCopyNEx if you require
'    the handling of NULL values.

'Return Value:

'    S_OK           -   if there was source data and it was all copied and the
'                       resultant dest string was null terminated

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that the copy
'                       operation failed due to insufficient space. When this
'                       error occurs, the destination buffer is modified to
'                       contain a truncated version of the ideal result and is
'                       null terminated. This is useful for situations where
'                       truncation is ok

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function.

'--*/

DECLARE FUNCTION StringCchCopyNA IMPORT "strsafe.dll" ALIAS "StringCchCopyNA" ( _
   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cchDest) LPSTR pszDest
 , BYVAL cchDest AS DWORD _                             ' __in  size_t cchDest
 , BYREF pszSrc AS ASCIIZ _                             ' __in  LPCSTR pszSrc
 , BYVAL cchToCopy AS DWORD _                           ' __in size_t cchToCopy
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringCchCopyNW IMPORT "strsafe.dll" ALIAS "StringCchCopyNW" ( _
   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cchDest) LPWSTR pszDest
 , BYVAL cchDest AS DWORD _                             ' __in  size_t cchDest
 , BYREF pszSrc AS WSTRINGZ _                           ' __in  LPCWSTR pszSrc
 , BYVAL cchToCopy AS DWORD _                           ' __in size_t cchToCopy
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCchCopyN = StringCchCopyNW
#ELSE
   MACRO StringCchCopyN = StringCchCopyNA
#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'strncpy'.
'    The size of the destination buffer (in bytes) is a parameter and this
'    function will not write past the end of this buffer and it will ALWAYS
'    null terminate the destination buffer (unless it is zero length).

'    This routine is meant as a replacement for strncpy, but it does behave
'    differently. This function will not pad the destination buffer with extra
'    null termination characters if cbToCopy is greater than the size of pszSrc.

'    This function returns a hresult, and not a pointer.  It returns
'    S_OK if the entire string or the first cbToCopy characters were
'    copied without truncation and the resultant destination string was null
'    terminated, otherwise it will return a failure code. In failure cases as
'    much of pszSrc will be copied to pszDest as possible, and pszDest will be
'    null terminated.

'Arguments:

'    pszDest        -   destination string

'    cbDest         -   size of destination buffer in bytes.
'                       length must be = ((_tcslen(src) + 1) * sizeof(TCHAR)) to
'                       hold all of the source including the null terminator

'    pszSrc         -   source string

'    cbToCopy       -   maximum number of bytes to copy from source string,
'                       not including the null terminator.

'Notes:
'    Behavior is undefined if source and destination strings overlap.

'    pszDest and pszSrc should not be NULL.  See StringCbCopyEx if you require
'    the handling of NULL values.

'Return Value:

'    S_OK           -   if there was source data and it was all copied and the
'                       resultant dest string was null terminated

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that the copy
'                       operation failed due to insufficient space. When this
'                       error occurs, the destination buffer is modified to
'                       contain a truncated version of the ideal result and is
'                       null terminated. This is useful for situations where
'                       truncation is ok

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function.

'--*/

DECLARE FUNCTION StringCbCopyNA IMPORT "strsafe.dll" ALIAS "StringCbCopyNA" ( _
   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cbDest) LPSTR pszDest
 , BYVAL cbDest AS DWORD _                              ' __in  size_t cbDest
 , BYREF pszSrc AS ASCIIZ _                             ' __in  LPCSTR pszSrc
 , BYVAL cbToCopy AS DWORD _                            ' __in size_t cbToCopy
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringCchCopyNW IMPORT "strsafe.dll" ALIAS "StringCchCopyNW" ( _
   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cbDest) LPWSTR pszDest
 , BYVAL cbDest AS DWORD _                              ' __in  size_t cbDest
 , BYREF pszSrc AS WSTRINGZ _                           ' __in  LPCWSTR pszSrc
 , BYVAL cbToCopy AS DWORD _                            ' __in size_t cbToCopy
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCbCopyN = StringCchCopyNW
#ELSE
   MACRO StringCbCopyN = StringCchCopyNA
#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'strncpy' with
'    some additional parameters.  In addition to functionality provided by
'    StringCchCopyN, this routine also returns a pointer to the end of the
'    destination string and the number of characters left in the destination
'    string including the null terminator. The flags parameter allows
'    additional controls.

'    This routine is meant as a replacement for strncpy, but it does behave
'    differently. This function will not pad the destination buffer with extra
'    null termination characters if cchToCopy is greater than the length of pszSrc.

'Arguments:

'    pszDest         -   destination string

'    cchDest         -   size of destination buffer in characters.
'                        length must be = (_tcslen(pszSrc) + 1) to hold all of
'                        the source including the null terminator

'    pszSrc          -   source string

'    cchToCopy       -   maximum number of characters to copy from the source
'                        string

'    ppszDestEnd     -   if ppszDestEnd is non-null, the function will return a
'                        pointer to the end of the destination string.  If the
'                        function copied any data, the result will point to the
'                        null termination character

'    pcchRemaining   -   if pcchRemaining is non-null, the function will return the
'                        number of characters left in the destination string,
'                        including the null terminator

'    dwFlags         -   controls some details of the string copy:

'        STRSAFE_FILL_BEHIND_NULL
'                    if the function succeeds, the low byte of dwFlags will be
'                    used to fill the uninitialize part of destination buffer
'                    behind the null terminator

'        STRSAFE_IGNORE_NULLS
'                    treat NULL string pointers like empty strings (TEXT("")).
'                    this flag is useful for emulating functions like lstrcpy

'        STRSAFE_FILL_ON_FAILURE
'                    if the function fails, the low byte of dwFlags will be
'                    used to fill all of the destination buffer, and it will
'                    be null terminated. This will overwrite any truncated
'                    string returned when the failure is
'                    STRSAFE_E_INSUFFICIENT_BUFFER

'        STRSAFE_NO_TRUNCATION /
'        STRSAFE_NULL_ON_FAILURE
'                    if the function fails, the destination buffer will be set
'                    to the empty string. This will overwrite any truncated string
'                    returned when the failure is STRSAFE_E_INSUFFICIENT_BUFFER.

'Notes:
'    Behavior is undefined if source and destination strings overlap.

'    pszDest and pszSrc should not be NULL unless the STRSAFE_IGNORE_NULLS flag
'    is specified. If STRSAFE_IGNORE_NULLS is passed, both pszDest and pszSrc
'    may be NULL. An error may still be returned even though NULLS are ignored
'    due to insufficient space.

'Return Value:

'    S_OK           -   if there was source data and it was all copied and the
'                       resultant dest string was null terminated

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that the copy
'                       operation failed due to insufficient space. When this
'                       error occurs, the destination buffer is modified to
'                       contain a truncated version of the ideal result and is
'                       null terminated. This is useful for situations where
'                       truncation is ok.

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function

'--*/

DECLARE FUNCTION StringCchCopyNExA IMPORT "strsafe.dll" ALIAS "StringCchCopyNExA" ( _
   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cchDest) LPSTR pszDest
 , BYVAL cchDest AS DWORD _                             ' __in  size_t cchDest
 , BYREF pszSrc AS ASCIIZ _                             ' __in  LPCSTR pszSrc
 , BYVAL cchToCopy AS DWORD _                           ' __in size_t cchToCopy
 , BYREF ppszDestEnd AS DWORD _                         ' __out LPSTR* ppszDestEnd
 , BYREF pcchRemaining AS DWORD _                       ' __out_opt size_t* pcchRemaining
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringCchCopyNExW IMPORT "strsafe.dll" ALIAS "StringCchCopyNExW" ( _
   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cchDest) LPWSTR pszDest
 , BYVAL cchDest AS DWORD _                             ' __in  size_t cchDest
 , BYREF pszSrc AS WSTRINGZ _                           ' __in  LPCWSTR pszSrc
 , BYVAL cchToCopy AS DWORD _                           ' __in size_t cchToCopy
 , BYREF ppszDestEnd AS DWORD _                         ' __out LPSWTR* ppszDestEnd
 , BYREF pcchRemaining AS DWORD _                       ' __out_opt size_t* pcchRemaining
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCchCopyNEx = StringCchCopyNExW
#ELSE
   MACRO StringCchCopyNEx = StringCchCopyNExA
#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'strncpy' with
'    some additional parameters.  In addition to functionality provided by
'    StringCbCopyN, this routine also returns a pointer to the end of the
'    destination string and the number of bytes left in the destination string
'    including the null terminator. The flags parameter allows additional controls.

'    This routine is meant as a replacement for strncpy, but it does behave
'    differently. This function will not pad the destination buffer with extra
'    null termination characters if cbToCopy is greater than the size of pszSrc.

'Arguments:

'    pszDest         -   destination string

'    cbDest          -   size of destination buffer in bytes.
'                        length must be ((_tcslen(pszSrc) + 1) * sizeof(TCHAR)) to
'                        hold all of the source including the null terminator

'    pszSrc          -   source string

'    cbToCopy        -   maximum number of bytes to copy from source string

'    ppszDestEnd     -   if ppszDestEnd is non-null, the function will return a
'                        pointer to the end of the destination string.  If the
'                        function copied any data, the result will point to the
'                        null termination character

'    pcbRemaining    -   pcbRemaining is non-null,the function will return the
'                        number of bytes left in the destination string,
'                        including the null terminator

'    dwFlags         -   controls some details of the string copy:

'        STRSAFE_FILL_BEHIND_NULL
'                    if the function succeeds, the low byte of dwFlags will be
'                    used to fill the uninitialize part of destination buffer
'                    behind the null terminator

'        STRSAFE_IGNORE_NULLS
'                    treat NULL string pointers like empty strings (TEXT("")).
'                    this flag is useful for emulating functions like lstrcpy

'        STRSAFE_FILL_ON_FAILURE
'                    if the function fails, the low byte of dwFlags will be
'                    used to fill all of the destination buffer, and it will
'                    be null terminated. This will overwrite any truncated
'                    string returned when the failure is
'                    STRSAFE_E_INSUFFICIENT_BUFFER

'        STRSAFE_NO_TRUNCATION /
'        STRSAFE_NULL_ON_FAILURE
'                    if the function fails, the destination buffer will be set
'                    to the empty string. This will overwrite any truncated string
'                    returned when the failure is STRSAFE_E_INSUFFICIENT_BUFFER.

'Notes:
'    Behavior is undefined if source and destination strings overlap.

'    pszDest and pszSrc should not be NULL unless the STRSAFE_IGNORE_NULLS flag
'    is specified.  If STRSAFE_IGNORE_NULLS is passed, both pszDest and pszSrc
'    may be NULL.  An error may still be returned even though NULLS are ignored
'    due to insufficient space.

'Return Value:

'    S_OK           -   if there was source data and it was all copied and the
'                       resultant dest string was null terminated

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that the copy
'                       operation failed due to insufficient space. When this
'                       error occurs, the destination buffer is modified to
'                       contain a truncated version of the ideal result and is
'                       null terminated. This is useful for situations where
'                       truncation is ok.

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function

'--*/

DECLARE FUNCTION StringCbCopyNExA IMPORT "strsafe.dll" ALIAS "StringCbCopyNExA" ( _
   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cbDest) LPSTR pszDest
 , BYVAL cbDest AS DWORD _                              ' __in  size_t cbDest
 , BYREF pszSrc AS ASCIIZ _                             ' __in  LPCSTR pszSrc
 , BYVAL cbToCopy AS DWORD _                            ' __in size_t cbToCopy
 , BYREF ppszDestEnd AS DWORD _                         ' __out LPSTR* ppszDestEnd
 , BYREF pcbRemaining AS DWORD _                        ' __out_opt size_t* pcbRemaining
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringCbCopyNExW IMPORT "strsafe.dll" ALIAS "StringCbCopyNExW" ( _
   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cbDest) LPWSTR pszDest
 , BYVAL cbDest AS DWORD _                              ' __in  size_t cbDest
 , BYREF pszSrc AS WSTRINGZ _                           ' __in  LPCWSTR pszSrc
 , BYVAL cbToCopy AS DWORD _                            ' __in size_t cbToCopy
 , BYREF ppszDestEnd AS DWORD _                         ' __out LPSWTR* ppszDestEnd
 , BYREF pcbRemaining AS DWORD _                        ' __out_opt size_t* pcbRemaining
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCbCopyNEx = StringCbCopyNExW
#ELSE
   MACRO StringCbCopyNEx = StringCbCopyNExA
#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'strcat'.
'    The size of the destination buffer (in characters) is a parameter and this
'    function will not write past the end of this buffer and it will ALWAYS
'    null terminate the destination buffer (unless it is zero length).

'    This function returns a hresult, and not a pointer.  It returns
'    S_OK if the string was concatenated without truncation and null terminated,
'    otherwise it will return a failure code. In failure cases as much of pszSrc
'    will be appended to pszDest as possible, and pszDest will be null
'    terminated.

'Arguments:

'    pszDest     -  destination string which must be null terminated

'    cchDest     -  size of destination buffer in characters.
'                   length must be = (_tcslen(pszDest) + _tcslen(pszSrc) + 1)
'                   to hold all of the combine string plus the null
'                   terminator

'    pszSrc      -  source string which must be null terminated

'Notes:
'    Behavior is undefined if source and destination strings overlap.

'    pszDest and pszSrc should not be NULL.  See StringCchCatEx if you require
'    the handling of NULL values.

'Return Value:

'    S_OK           -   if there was source data and it was all concatenated and
'                       the resultant dest string was null terminated

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that the operation
'                       failed due to insufficient space. When this error occurs,
'                       the destination buffer is modified to contain a truncated
'                       version of the ideal result and is null terminated. This
'                       is useful for situations where truncation is ok.

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function

'--*/

DECLARE FUNCTION StringCchCatA IMPORT "strsafe.dll" ALIAS "StringCchCatA" ( _
   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cchDest) LPSTR pszDest
 , BYVAL cchDest AS DWORD _                             ' __in  size_t cchDest
 , BYREF pszSrc AS ASCIIZ _                             ' __in  LPCSTR pszSrc
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringCchCatW IMPORT "strsafe.dll" ALIAS "StringCchCatW" ( _
   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cchDest) LPWSTR pszDest
 , BYVAL cchDest AS DWORD _                             ' __in  size_t cchDest
 , BYREF pszSrc AS WSTRINGZ _                           ' __in  LPCWSTR pszSrc
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCchCat = StringCchCatW
#ELSE
   MACRO StringCchCat = StringCchCatA
#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'strcat'.
'    The size of the destination buffer (in bytes) is a parameter and this
'    function will not write past the end of this buffer and it will ALWAYS
'    null terminate the destination buffer (unless it is zero length).

'    This function returns a hresult, and not a pointer.  It returns
'    S_OK if the string was concatenated without truncation and null terminated,
'    otherwise it will return a failure code. In failure cases as much of pszSrc
'    will be appended to pszDest as possible, and pszDest will be null
'    terminated.

'Arguments:

'    pszDest     -  destination string which must be null terminated

'    cbDest      -  size of destination buffer in bytes.
'                   length must be = ((_tcslen(pszDest) + _tcslen(pszSrc) + 1) * sizeof(TCHAR)
'                   to hold all of the combine string plus the null
'                   terminator

'    pszSrc      -  source string which must be null terminated

'Notes:
'    Behavior is undefined if source and destination strings overlap.

'    pszDest and pszSrc should not be NULL.  See StringCbCatEx if you require
'    the handling of NULL values.

'Return Value:

'    S_OK           -   if there was source data and it was all concatenated and
'                       the resultant dest string was null terminated

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that the operation
'                       failed due to insufficient space. When this error occurs,
'                       the destination buffer is modified to contain a truncated
'                       version of the ideal result and is null terminated. This
'                       is useful for situations where truncation is ok.

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function

'--*/

DECLARE FUNCTION StringCbCatA IMPORT "strsafe.dll" ALIAS "StringCbCatA" ( _
   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cbDest) LPSTR pszDest
 , BYVAL cbDest AS DWORD _                              ' __in  size_t cbDest
 , BYREF pszSrc AS ASCIIZ _                             ' __in  LPCSTR pszSrc
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringCbCatW IMPORT "strsafe.dll" ALIAS "StringCbCatW" ( _
   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cbDest) LPWSTR pszDest
 , BYVAL cbDest AS DWORD _                              ' __in  size_t cbDest
 , BYREF pszSrc AS WSTRINGZ _                           ' __in  LPCWSTR pszSrc
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCbCat = StringCbCatW
#ELSE
   MACRO StringCbCat = StringCbCatA
#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'strcat' with
'    some additional parameters.  In addition to functionality provided by
'    StringCchCat, this routine also returns a pointer to the end of the
'    destination string and the number of characters left in the destination string
'    including the null terminator. The flags parameter allows additional controls.

'Arguments:

'    pszDest         -   destination string which must be null terminated

'    cchDest         -   size of destination buffer in characters
'                        length must be (_tcslen(pszDest) + _tcslen(pszSrc) + 1)
'                        to hold all of the combine string plus the null
'                        terminator.

'    pszSrc          -   source string which must be null terminated

'    ppszDestEnd     -   if ppszDestEnd is non-null, the function will return a
'                        pointer to the end of the destination string.  If the
'                        function appended any data, the result will point to the
'                        null termination character

'    pcchRemaining   -   if pcchRemaining is non-null, the function will return the
'                        number of characters left in the destination string,
'                        including the null terminator

'    dwFlags         -   controls some details of the string copy:

'        STRSAFE_FILL_BEHIND_NULL
'                    if the function succeeds, the low byte of dwFlags will be
'                    used to fill the uninitialize part of destination buffer
'                    behind the null terminator

'        STRSAFE_IGNORE_NULLS
'                    treat NULL string pointers like empty strings (TEXT("")).
'                    this flag is useful for emulating functions like lstrcat

'        STRSAFE_FILL_ON_FAILURE
'                    if the function fails, the low byte of dwFlags will be
'                    used to fill all of the destination buffer, and it will
'                    be null terminated. This will overwrite any pre-existing
'                    or truncated string

'        STRSAFE_NULL_ON_FAILURE
'                    if the function fails, the destination buffer will be set
'                    to the empty string. This will overwrite any pre-existing or
'                    truncated string

'        STRSAFE_NO_TRUNCATION
'                    if the function returns STRSAFE_E_INSUFFICIENT_BUFFER, pszDest
'                    will not contain a truncated string, it will remain unchanged.

'Notes:
'    Behavior is undefined if source and destination strings overlap.

'    pszDest and pszSrc should not be NULL unless the STRSAFE_IGNORE_NULLS flag
'    is specified.  If STRSAFE_IGNORE_NULLS is passed, both pszDest and pszSrc
'    may be NULL.  An error may still be returned even though NULLS are ignored
'    due to insufficient space.

'Return Value:

'    S_OK           -   if there was source data and it was all concatenated and
'                       the resultant dest string was null terminated

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that the operation
'                       failed due to insufficient space. When this error
'                       occurs, the destination buffer is modified to contain
'                       a truncated version of the ideal result and is null
'                       terminated. This is useful for situations where
'                       truncation is ok.

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function

'--*/

DECLARE FUNCTION StringCchCatExA IMPORT "strsafe.dll" ALIAS "StringCchCatExA" ( _
   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cchDest) LPSTR pszDest
 , BYVAL cchDest AS DWORD _                             ' __in  size_t cchDest
 , BYREF pszSrc AS ASCIIZ _                             ' __in  LPCSTR pszSrc
 , BYREF ppszDestEnd AS DWORD _                         ' __out LPSTR* ppszDestEnd
 , BYREF pcchRemaining AS DWORD _                       ' __out_opt size_t* pcchRemaining
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringCchCatExW IMPORT "strsafe.dll" ALIAS "StringCchCatExW" ( _
   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cchDest) LPWSTR pszDest
 , BYVAL cchDest AS DWORD _                             ' __in  size_t cchDest
 , BYREF pszSrc AS WSTRINGZ _                           ' __in  LPCWSTR pszSrc
 , BYREF ppszDestEnd AS DWORD _                         ' __out LPSTR* ppszDestEnd
 , BYREF pcchRemaining AS DWORD _                       ' __out_opt size_t* pcchRemaining
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCchCatEx = StringCchCatExW
#ELSE
   MACRO StringCchCatEx = StringCchCatExA
#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'strcat' with
'    some additional parameters.  In addition to functionality provided by
'    StringCbCat, this routine also returns a pointer to the end of the
'    destination string and the number of bytes left in the destination string
'    including the null terminator. The flags parameter allows additional controls.

'Arguments:

'    pszDest         -   destination string which must be null terminated

'    cbDest          -   size of destination buffer in bytes.
'                        length must be ((_tcslen(pszDest) + _tcslen(pszSrc) + 1) * sizeof(TCHAR)
'                        to hold all of the combine string plus the null
'                        terminator.

'    pszSrc          -   source string which must be null terminated

'    ppszDestEnd     -   if ppszDestEnd is non-null, the function will return a
'                        pointer to the end of the destination string.  If the
'                        function appended any data, the result will point to the
'                        null termination character

'    pcbRemaining    -   if pcbRemaining is non-null, the function will return
'                        the number of bytes left in the destination string,
'                        including the null terminator

'    dwFlags         -   controls some details of the string copy:

'        STRSAFE_FILL_BEHIND_NULL
'                    if the function succeeds, the low byte of dwFlags will be
'                    used to fill the uninitialize part of destination buffer
'                    behind the null terminator

'        STRSAFE_IGNORE_NULLS
'                    treat NULL string pointers like empty strings (TEXT("")).
'                    this flag is useful for emulating functions like lstrcat

'        STRSAFE_FILL_ON_FAILURE
'                    if the function fails, the low byte of dwFlags will be
'                    used to fill all of the destination buffer, and it will
'                    be null terminated. This will overwrite any pre-existing
'                    or truncated string

'        STRSAFE_NULL_ON_FAILURE
'                    if the function fails, the destination buffer will be set
'                    to the empty string. This will overwrite any pre-existing or
'                    truncated string

'        STRSAFE_NO_TRUNCATION
'                    if the function returns STRSAFE_E_INSUFFICIENT_BUFFER, pszDest
'                    will not contain a truncated string, it will remain unchanged.

'Notes:
'    Behavior is undefined if source and destination strings overlap.

'    pszDest and pszSrc should not be NULL unless the STRSAFE_IGNORE_NULLS flag
'    is specified.  If STRSAFE_IGNORE_NULLS is passed, both pszDest and pszSrc
'    may be NULL.  An error may still be returned even though NULLS are ignored
'    due to insufficient space.

'Return Value:

'    S_OK           -   if there was source data and it was all concatenated
'                       and the resultant dest string was null terminated

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that the operation
'                       failed due to insufficient space. When this error
'                       occurs, the destination buffer is modified to contain
'                       a truncated version of the ideal result and is null
'                       terminated. This is useful for situations where
'                       truncation is ok.

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function

'--*/

DECLARE FUNCTION StringCbCatExA IMPORT "strsafe.dll" ALIAS "StringCbCatExA" ( _
   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cbDest) LPSTR pszDest
 , BYVAL cbDest AS DWORD _                              ' __in  size_t cbDest
 , BYREF pszSrc AS ASCIIZ _                             ' __in  LPCSTR pszSrc
 , BYREF ppszDestEnd AS DWORD _                         ' __out LPSTR* ppszDestEnd
 , BYREF pcbRemaining AS DWORD _                        ' __out_opt size_t* pcbRemaining
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringCbCatExW IMPORT "strsafe.dll" ALIAS "StringCbCatExW" ( _
   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cbDest) LPWSTR pszDest
 , BYVAL cbDest AS DWORD _                              ' __in  size_t cbDest
 , BYREF pszSrc AS WSTRINGZ _                           ' __in  LPCWSTR pszSrc
 , BYREF ppszDestEnd AS DWORD _                         ' __out LPSTR* ppszDestEnd
 , BYREF pcbRemaining AS DWORD _                        ' __out_opt size_t* pcbRemaining
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCbCatEx = StringCbCatExW
#ELSE
   MACRO StringCbCatEx = StringCbCatExA
#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'strncat'.
'    The size of the destination buffer (in characters) is a parameter as well as
'    the maximum number of characters to append, excluding the null terminator.
'    This function will not write past the end of the destination buffer and it will
'    ALWAYS null terminate pszDest (unless it is zero length).

'    This function returns a hresult, and not a pointer.  It returns
'    S_OK if all of pszSrc or the first cchToAppend characters were appended
'    to the destination string and it was null terminated, otherwise it will
'    return a failure code. In failure cases as much of pszSrc will be appended
'    to pszDest as possible, and pszDest will be null terminated.

'Arguments:

'    pszDest         -   destination string which must be null terminated

'    cchDest         -   size of destination buffer in characters.
'                        length must be (_tcslen(pszDest) + min(cchToAppend, _tcslen(pszSrc)) + 1)
'                        to hold all of the combine string plus the null
'                        terminator.

'    pszSrc          -   source string

'    cchToAppend     -   maximum number of characters to append

'Notes:
'    Behavior is undefined if source and destination strings overlap.

'    pszDest and pszSrc should not be NULL. See StringCchCatNEx if you require
'    the handling of NULL values.

'Return Value:

'    S_OK           -   if all of pszSrc or the first cchToAppend characters
'                       were concatenated to pszDest and the resultant dest
'                       string was null terminated

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that the operation
'                       failed due to insufficient space. When this error
'                       occurs, the destination buffer is modified to contain
'                       a truncated version of the ideal result and is null
'                       terminated. This is useful for situations where
'                       truncation is ok.

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function

'--*/

DECLARE FUNCTION StringCchCatNA IMPORT "strsafe.dll" ALIAS "StringCchCatNA" ( _
   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cchDest) LPSTR pszDest
 , BYVAL cchDest AS DWORD _                             ' __in size_t cchDest
 , BYREF pszSrc AS ASCIIZ _                             ' __in LPCSTR pszSrc
 , BYVAL cchToAppend AS DWORD _                         ' __in size_t cchToAppend
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringCchCatNW IMPORT "strsafe.dll" ALIAS "StringCchCatNW" ( _
   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cchDest) LPWSTR pszDest
 , BYVAL cchDest AS DWORD _                             ' __in size_t cchDest
 , BYREF pszSrc AS WSTRINGZ _                           ' __in LPCWSTR pszSrc
 , BYVAL cchToAppend AS DWORD _                         ' __in size_t cchToAppend
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCchCatN = StringCchCatNW
#ELSE
   MACRO StringCchCatN = StringCchCatNA
#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'strncat'.
'    The size of the destination buffer (in bytes) is a parameter as well as
'    the maximum number of bytes to append, excluding the null terminator.
'    This function will not write past the end of the destination buffer and it will
'    ALWAYS null terminate pszDest (unless it is zero length).

'    This function returns a hresult, and not a pointer.  It returns
'    S_OK if all of pszSrc or the first cbToAppend bytes were appended
'    to the destination string and it was null terminated, otherwise it will
'    return a failure code. In failure cases as much of pszSrc will be appended
'    to pszDest as possible, and pszDest will be null terminated.

'Arguments:

'    pszDest         -   destination string which must be null terminated

'    cbDest          -   size of destination buffer in bytes.
'                        length must be ((_tcslen(pszDest) + min(cbToAppend / sizeof(TCHAR), _tcslen(pszSrc)) + 1) * sizeof(TCHAR)
'                        to hold all of the combine string plus the null
'                        terminator.

'    pszSrc          -   source string

'    cbToAppend      -   maximum number of bytes to append

'Notes:
'    Behavior is undefined if source and destination strings overlap.

'    pszDest and pszSrc should not be NULL. See StringCbCatNEx if you require
'    the handling of NULL values.

'Return Value:

'    S_OK           -   if all of pszSrc or the first cbToAppend bytes were
'                       concatenated to pszDest and the resultant dest string
'                       was null terminated

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that the operation
'                       failed due to insufficient space. When this error
'                       occurs, the destination buffer is modified to contain
'                       a truncated version of the ideal result and is null
'                       terminated. This is useful for situations where
'                       truncation is ok.

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function

'--*/

DECLARE FUNCTION StringCbCatNA IMPORT "strsafe.dll" ALIAS "StringCbCatNA" ( _
   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cbDest) LPSTR pszDest
 , BYVAL cbDest AS DWORD _                              ' __in size_t cbDest
 , BYREF pszSrc AS ASCIIZ _                             ' __in LPCSTR pszSrc
 , BYVAL cbToAppend AS DWORD _                          ' __in size_t cbToAppend
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringCbCatNW IMPORT "strsafe.dll" ALIAS "StringCbCatNW" ( _
   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cbDest) LPWSTR pszDest
 , BYVAL cbDest AS DWORD _                              ' __in size_t cbDest
 , BYREF pszSrc AS WSTRINGZ _                           ' __in LPCWSTR pszSrc
 , BYVAL cbToAppend AS DWORD _                          ' __in size_t cbToAppend
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCbCatN = StringCbCatNW
#ELSE
   MACRO StringCbCatN = StringCbCatNA
#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'strncat', with
'    some additional parameters.  In addition to functionality provided by
'    StringCchCatN, this routine also returns a pointer to the end of the
'    destination string and the number of characters left in the destination string
'    including the null terminator. The flags parameter allows additional controls.

'Arguments:

'    pszDest         -   destination string which must be null terminated

'    cchDest         -   size of destination buffer in characters.
'                        length must be (_tcslen(pszDest) + min(cchToAppend, _tcslen(pszSrc)) + 1)
'                        to hold all of the combine string plus the null
'                        terminator.

'    pszSrc          -   source string

'    cchToAppend     -   maximum number of characters to append

'    ppszDestEnd     -   if ppszDestEnd is non-null, the function will return a
'                        pointer to the end of the destination string.  If the
'                        function appended any data, the result will point to the
'                        null termination character

'    pcchRemaining   -   if pcchRemaining is non-null, the function will return the
'                        number of characters left in the destination string,
'                        including the null terminator

'    dwFlags         -   controls some details of the string copy:

'        STRSAFE_FILL_BEHIND_NULL
'                    if the function succeeds, the low byte of dwFlags will be
'                    used to fill the uninitialize part of destination buffer
'                    behind the null terminator

'        STRSAFE_IGNORE_NULLS
'                    treat NULL string pointers like empty strings (TEXT(""))

'        STRSAFE_FILL_ON_FAILURE
'                    if the function fails, the low byte of dwFlags will be
'                    used to fill all of the destination buffer, and it will
'                    be null terminated. This will overwrite any pre-existing
'                    or truncated string

'        STRSAFE_NULL_ON_FAILURE
'                    if the function fails, the destination buffer will be set
'                    to the empty string. This will overwrite any pre-existing or
'                    truncated string

'        STRSAFE_NO_TRUNCATION
'                    if the function returns STRSAFE_E_INSUFFICIENT_BUFFER, pszDest
'                    will not contain a truncated string, it will remain unchanged.

'Notes:
'    Behavior is undefined if source and destination strings overlap.

'    pszDest and pszSrc should not be NULL unless the STRSAFE_IGNORE_NULLS flag
'    is specified.  If STRSAFE_IGNORE_NULLS is passed, both pszDest and pszSrc
'    may be NULL.  An error may still be returned even though NULLS are ignored
'    due to insufficient space.

'Return Value:

'    S_OK           -   if all of pszSrc or the first cchToAppend characters
'                       were concatenated to pszDest and the resultant dest
'                       string was null terminated

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that the operation
'                       failed due to insufficient space. When this error
'                       occurs, the destination buffer is modified to contain
'                       a truncated version of the ideal result and is null
'                       terminated. This is useful for situations where
'                       truncation is ok.

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function

'--*/

DECLARE FUNCTION StringCchCatNExA IMPORT "strsafe.dll" ALIAS "StringCchCatNExA" ( _
   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cchDest) LPSTR pszDest
 , BYVAL cchDest AS DWORD _                             ' __in size_t cchDest
 , BYREF pszSrc AS ASCIIZ _                             ' __in LPCSTR pszSrc
 , BYVAL cchToAppend AS DWORD _                         ' __in size_t cchToAppend
 , BYREF ppszDestEnd AS DWORD _                         ' __out LPSTR* ppszDestEnd
 , BYREF pcchRemaining AS DWORD _                       ' __out_opt size_t* pcchRemaining
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringCchCatNExW IMPORT "strsafe.dll" ALIAS "StringCchCatNExW" ( _
   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cchDest) LPWSTR pszDest
 , BYVAL cchDest AS DWORD _                             ' __in size_t cchDest
 , BYREF pszSrc AS WSTRINGZ _                           ' __in LPCWSTR pszSrc
 , BYVAL cchToAppend AS DWORD _                         ' __in size_t cchToAppend
 , BYREF ppszDestEnd AS DWORD _                         ' __out LPWSTR* ppszDestEnd
 , BYREF pcchRemaining AS DWORD _                       ' __out_opt size_t* pcchRemaining
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCchCatNEx = StringCchCatNExW
#ELSE
   MACRO StringCchCatNEx = StringCchCatNExA
#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'strncat', with
'    some additional parameters.  In addition to functionality provided by
'    StringCbCatN, this routine also returns a pointer to the end of the
'    destination string and the number of bytes left in the destination string
'    including the null terminator. The flags parameter allows additional controls.

'Arguments:

'    pszDest         -   destination string which must be null terminated

'    cbDest          -   size of destination buffer in bytes.
'                        length must be ((_tcslen(pszDest) + min(cbToAppend / sizeof(TCHAR), _tcslen(pszSrc)) + 1) * sizeof(TCHAR)
'                        to hold all of the combine string plus the null
'                        terminator.

'    pszSrc          -   source string

'    cbToAppend      -   maximum number of bytes to append

'    ppszDestEnd     -   if ppszDestEnd is non-null, the function will return a
'                        pointer to the end of the destination string.  If the
'                        function appended any data, the result will point to the
'                        null termination character

'    pcbRemaining    -   if pcbRemaining is non-null, the function will return the
'                        number of bytes left in the destination string,
'                        including the null terminator

'    dwFlags         -   controls some details of the string copy:

'        STRSAFE_FILL_BEHIND_NULL
'                    if the function succeeds, the low byte of dwFlags will be
'                    used to fill the uninitialize part of destination buffer
'                    behind the null terminator

'        STRSAFE_IGNORE_NULLS
'                    treat NULL string pointers like empty strings (TEXT(""))

'        STRSAFE_FILL_ON_FAILURE
'                    if the function fails, the low byte of dwFlags will be
'                    used to fill all of the destination buffer, and it will
'                    be null terminated. This will overwrite any pre-existing
'                    or truncated string

'        STRSAFE_NULL_ON_FAILURE
'                    if the function fails, the destination buffer will be set
'                    to the empty string. This will overwrite any pre-existing or
'                    truncated string

'        STRSAFE_NO_TRUNCATION
'                    if the function returns STRSAFE_E_INSUFFICIENT_BUFFER, pszDest
'                    will not contain a truncated string, it will remain unchanged.

'Notes:
'    Behavior is undefined if source and destination strings overlap.

'    pszDest and pszSrc should not be NULL unless the STRSAFE_IGNORE_NULLS flag
'    is specified.  If STRSAFE_IGNORE_NULLS is passed, both pszDest and pszSrc
'    may be NULL.  An error may still be returned even though NULLS are ignored
'    due to insufficient space.

'Return Value:

'    S_OK           -   if all of pszSrc or the first cbToAppend bytes were
'                       concatenated to pszDest and the resultant dest string
'                       was null terminated

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that the operation
'                       failed due to insufficient space. When this error
'                       occurs, the destination buffer is modified to contain
'                       a truncated version of the ideal result and is null
'                       terminated. This is useful for situations where
'                       truncation is ok.

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function

'--*/

DECLARE FUNCTION StringCbCatNExA IMPORT "strsafe.dll" ALIAS "StringCbCatNExA" ( _
   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cbDest) LPSTR pszDest
 , BYVAL cbDest AS DWORD _                              ' __in size_t cbDest
 , BYREF pszSrc AS ASCIIZ _                             ' __in LPCSTR pszSrc
 , BYVAL cbToAppend AS DWORD _                          ' __in size_t cbToAppend
 , BYREF ppszDestEnd AS DWORD _                         ' __out LPSTR* ppszDestEnd
 , BYREF pcbRemaining AS DWORD _                        ' __out_opt size_t* pcbRemaining
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringCbCatNExW IMPORT "strsafe.dll" ALIAS "StringCbCatNExW" ( _
   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cbDest) LPWSTR pszDest
 , BYVAL cbDest AS DWORD _                              ' __in size_t cbDest
 , BYREF pszSrc AS WSTRINGZ _                           ' __in LPCWSTR pszSrc
 , BYVAL cbToAppend AS DWORD _                          ' __in size_t cbToAppend
 , BYREF ppszDestEnd AS DWORD _                         ' __out LPWSTR* ppszDestEnd
 , BYREF pcbRemaining AS DWORD _                        ' __out_opt size_t* pcbRemaining
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCbCatNEx = StringCbCatNExW
#ELSE
   MACRO StringCbCatNEx = StringCbCatNExA
#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'vsprintf'.
'    The size of the destination buffer (in characters) is a parameter and
'    this function will not write past the end of this buffer and it will
'    ALWAYS null terminate the destination buffer (unless it is zero length).

'    This function returns a hresult, and not a pointer.  It returns
'    S_OK if the string was printed without truncation and null terminated,
'    otherwise it will return a failure code. In failure cases it will return
'    a truncated version of the ideal result.

'Arguments:

'    pszDest     -  destination string

'    cchDest     -  size of destination buffer in characters
'                   length must be sufficient to hold the resulting formatted
'                   string, including the null terminator.

'    pszFormat   -  format string which must be null terminated

'    argList     -  va_list from the variable arguments according to the
'                   stdarg.h convention

'Notes:
'    Behavior is undefined if destination, format strings or any arguments
'    strings overlap.

'    pszDest and pszFormat should not be NULL.  See StringCchVPrintfEx if you
'    require the handling of NULL values.

'Return Value:

'    S_OK           -   if there was sufficient space in the dest buffer for
'                       the resultant string and it was null terminated.

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that the print
'                       operation failed due to insufficient space. When this
'                       error occurs, the destination buffer is modified to
'                       contain a truncated version of the ideal result and is
'                       null terminated. This is useful for situations where
'                       truncation is ok.

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function

'--*/

DECLARE FUNCTION StringCchVPrintfA IMPORT "strsafe.dll" ALIAS "StringCchVPrintfA" ( _
   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cchDest) LPSTR pszDest
 , BYVAL cchDest AS DWORD _                             ' __in size_t cchDest
 , BYREF pszFormat AS ASCIIZ _                          ' __in LPCSTR pszFormat
 , BYREF argList AS ANY _                               ' __in va_list argList
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringCchVPrintfW IMPORT "strsafe.dll" ALIAS "StringCchVPrintfW" ( _
   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cchDest) LPWSTR pszDest
 , BYVAL cchDest AS DWORD _                             ' __in size_t cchDest
 , BYREF pszFormat AS WSTRINGZ _                        ' __in LPCWSTR pszFormat
 , BYREF argList AS ANY _                               ' __in va_list argList
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCchVPrintf = StringCchVPrintfW
#ELSE
   MACRO StringCchVPrintf = StringCchVPrintfA
#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'vsprintf'.
'    The size of the destination buffer (in bytes) is a parameter and
'    this function will not write past the end of this buffer and it will
'    ALWAYS null terminate the destination buffer (unless it is zero length).

'    This function returns a hresult, and not a pointer.  It returns
'    S_OK if the string was printed without truncation and null terminated,
'    otherwise it will return a failure code. In failure cases it will return
'    a truncated version of the ideal result.

'Arguments:

'    pszDest     -  destination string

'    cbDest      -  size of destination buffer in bytes
'                   length must be sufficient to hold the resulting formatted
'                   string, including the null terminator.

'    pszFormat   -  format string which must be null terminated

'    argList     -  va_list from the variable arguments according to the
'                   stdarg.h convention

'Notes:
'    Behavior is undefined if destination, format strings or any arguments
'    strings overlap.

'    pszDest and pszFormat should not be NULL.  See StringCbVPrintfEx if you
'    require the handling of NULL values.


'Return Value:

'    S_OK           -   if there was sufficient space in the dest buffer for
'                       the resultant string and it was null terminated.

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that the print
'                       operation failed due to insufficient space. When this
'                       error occurs, the destination buffer is modified to
'                       contain a truncated version of the ideal result and is
'                       null terminated. This is useful for situations where
'                       truncation is ok.

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function

'--*/

DECLARE FUNCTION StringCbVPrintfA IMPORT "strsafe.dll" ALIAS "StringCbVPrintfA" ( _
   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cbDest) LPSTR pszDest
 , BYVAL cbDest AS DWORD _                              ' __in size_t cbDest
 , BYREF pszFormat AS ASCIIZ _                          ' __in LPCSTR pszFormat
 , BYREF argList AS ANY _                               ' __in va_list argList
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringCbVPrintfW IMPORT "strsafe.dll" ALIAS "StringCbVPrintfW" ( _
   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cbDest) LPWSTR pszDest
 , BYVAL cbDest AS DWORD _                              ' __in size_t cbDest
 , BYREF pszFormat AS WSTRINGZ _                        ' __in LPCWSTR pszFormat
 , BYREF argList AS ANY _                               ' __in va_list argList
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCbVPrintf = StringCbVPrintfW
#ELSE
   MACRO StringCbVPrintf = StringCbVPrintfA
#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'sprintf'.
'    The size of the destination buffer (in characters) is a parameter and
'    this function will not write past the end of this buffer and it will
'    ALWAYS null terminate the destination buffer (unless it is zero length).

'    This function returns a hresult, and not a pointer.  It returns
'    S_OK if the string was printed without truncation and null terminated,
'    otherwise it will return a failure code. In failure cases it will return
'    a truncated version of the ideal result.

'Arguments:

'    pszDest     -  destination string

'    cchDest     -  size of destination buffer in characters
'                   length must be sufficient to hold the resulting formatted
'                   string, including the null terminator.

'    pszFormat   -  format string which must be null terminated

'    ...         -  additional parameters to be formatted according to
'                   the format string

'Notes:
'    Behavior is undefined if destination, format strings or any arguments
'    strings overlap.

'    pszDest and pszFormat should not be NULL.  See StringCchPrintfEx if you
'    require the handling of NULL values.

'Return Value:

'    S_OK           -   if there was sufficient space in the dest buffer for
'                       the resultant string and it was null terminated.

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that the print
'                       operation failed due to insufficient space. When this
'                       error occurs, the destination buffer is modified to
'                       contain a truncated version of the ideal result and is
'                       null terminated. This is useful for situations where
'                       truncation is ok.

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function

'--*/

DECLARE FUNCTION StringCchPrintfA CDECL IMPORT "strsafe.dll" ALIAS "StringCchPrintfA" ( _
   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cchDest) LPSTR pszDest
 , BYVAL cchDest AS DWORD _                             ' __in size_t cchDest
 , BYREF pszFormat AS ASCIIZ _                          ' __in LPCSTR pszFormat
 , OPTIONAL BYREF ANY  _                                ' optional arguments
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringCchPrintfW CDECL IMPORT "strsafe.dll" ALIAS "StringCchPrintfW" ( _
   BYVAL pszDest AS DWORD _                             ' __out_ecount(cchDest) LPSTR pszDest
 , BYVAL cchDest AS DWORD _                             ' __in size_t cchDest
 , BYREF pszFormat AS WSTRINGZ _                        ' __in LPCWSTR pszFormat
 , OPTIONAL BYREF ANY  _                                ' optional arguments
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCchPrintf = StringCchPrintfW
#ELSE
   MACRO StringCchPrintf = StringCchPrintfA
#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'sprintf'.
'    The size of the destination buffer (in bytes) is a parameter and
'    this function will not write past the end of this buffer and it will
'    ALWAYS null terminate the destination buffer (unless it is zero length).

'    This function returns a hresult, and not a pointer.  It returns
'    S_OK if the string was printed without truncation and null terminated,
'    otherwise it will return a failure code. In failure cases it will return
'    a truncated version of the ideal result.

'Arguments:

'    pszDest     -  destination string

'    cbDest      -  size of destination buffer in bytes
'                   length must be sufficient to hold the resulting formatted
'                   string, including the null terminator.

'    pszFormat   -  format string which must be null terminated

'    ...         -  additional parameters to be formatted according to
'                   the format string

'Notes:
'    Behavior is undefined if destination, format strings or any arguments
'    strings overlap.

'    pszDest and pszFormat should not be NULL.  See StringCbPrintfEx if you
'    require the handling of NULL values.


'Return Value:

'    S_OK           -   if there was sufficient space in the dest buffer for
'                       the resultant string and it was null terminated.

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that the print
'                       operation failed due to insufficient space. When this
'                       error occurs, the destination buffer is modified to
'                       contain a truncated version of the ideal result and is
'                       null terminated. This is useful for situations where
'                       truncation is ok.

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function

DECLARE FUNCTION StringCbPrintfA CDECL IMPORT "strsafe.dll" ALIAS "StringCbPrintfA" ( _
   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cbDest) LPSTR pszDest
 , BYVAL cbDest AS DWORD _                              ' __in size_t cbDest
 , BYREF pszFormat AS ASCIIZ _                          ' __in LPCSTR pszFormat
 , OPTIONAL BYREF ANY  _                                ' optional arguments
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringCbPrintfW CDECL IMPORT "strsafe.dll" ALIAS "StringCbPrintfW" ( _
   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cbDest) LPSTR pszDest
 , BYVAL cbDest AS DWORD _                              ' __in size_t cbDest
 , BYREF pszFormat AS WSTRINGZ _                        ' __in LPCWSTR pszFormat
 , OPTIONAL BYREF ANY  _                                ' optional arguments
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCbPrintf = StringCbPrintfW
#ELSE
   MACRO StringCbPrintf = StringCbPrintfA
#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'sprintf' with
'    some additional parameters.  In addition to functionality provided by
'    StringCchPrintf, this routine also returns a pointer to the end of the
'    destination string and the number of characters left in the destination string
'    including the null terminator. The flags parameter allows additional controls.

'Arguments:

'    pszDest         -   destination string

'    cchDest         -   size of destination buffer in characters.
'                        length must be sufficient to contain the resulting
'                        formatted string plus the null terminator.

'    ppszDestEnd     -   if ppszDestEnd is non-null, the function will return a
'                        pointer to the end of the destination string.  If the
'                        function printed any data, the result will point to the
'                        null termination character

'    pcchRemaining   -   if pcchRemaining is non-null, the function will return
'                        the number of characters left in the destination string,
'                        including the null terminator

'    dwFlags         -   controls some details of the string copy:

'        STRSAFE_FILL_BEHIND_NULL
'                    if the function succeeds, the low byte of dwFlags will be
'                    used to fill the uninitialize part of destination buffer
'                    behind the null terminator

'        STRSAFE_IGNORE_NULLS
'                    treat NULL string pointers like empty strings (TEXT(""))

'        STRSAFE_FILL_ON_FAILURE
'                    if the function fails, the low byte of dwFlags will be
'                    used to fill all of the destination buffer, and it will
'                    be null terminated. This will overwrite any truncated
'                    string returned when the failure is
'                    STRSAFE_E_INSUFFICIENT_BUFFER

'        STRSAFE_NO_TRUNCATION /
'        STRSAFE_NULL_ON_FAILURE
'                    if the function fails, the destination buffer will be set
'                    to the empty string. This will overwrite any truncated string
'                    returned when the failure is STRSAFE_E_INSUFFICIENT_BUFFER.

'    pszFormat       -   format string which must be null terminated

'    ...             -   additional parameters to be formatted according to
'                        the format string

'Notes:
'    Behavior is undefined if destination, format strings or any arguments
'    strings overlap.

'    pszDest and pszFormat should not be NULL unless the STRSAFE_IGNORE_NULLS
'    flag is specified.  If STRSAFE_IGNORE_NULLS is passed, both pszDest and
'    pszFormat may be NULL.  An error may still be returned even though NULLS
'    are ignored due to insufficient space.

'Return Value:

'    S_OK           -   if there was sufficient space in the dest buffer for
'                       the resultant string and it was null terminated.

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that the print
'                       operation failed due to insufficient space. When this
'                       error occurs, the destination buffer is modified to
'                       contain a truncated version of the ideal result and is
'                       null terminated. This is useful for situations where
'                       truncation is ok.

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function

DECLARE FUNCTION StringCchPrintfExA CDECL IMPORT "strsafe.dll" ALIAS "StringCchPrintfExA" ( _
   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cchDest) LPSTR pszDest
 , BYVAL cchDest AS DWORD _                             ' __in size_t cchDest
 , BYREF ppszDestEnd AS DWORD _                         ' __out LPSTR* ppszDestEnd
 , BYREF pcchRemaining AS DWORD _                       ' __out_opt size_t* pcchRemaining
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pszFormat AS ASCIIZ _                          ' __in LPCSTR pszFormat
 , OPTIONAL BYREF ANY  _                                ' optional arguments
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 ) AS LONG                                              ' HRESULT


DECLARE FUNCTION StringCchPrintfExW CDECL IMPORT "strsafe.dll" ALIAS "StringCchPrintfExW" ( _
   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cchDest) LPWSTR pszDest
 , BYVAL cchDest AS DWORD _                             ' __in size_t cchDest
 , BYREF ppszDestEnd AS DWORD _                         ' __out LPWSTR* ppszDestEnd
 , BYREF pcchRemaining AS DWORD _                       ' __out_opt size_t* pcchRemaining
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pszFormat AS WSTRINGZ _                        ' __in LPCWSTR pszFormat
 , OPTIONAL BYREF ANY  _                                ' optional arguments
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCchPrintfEx = StringCchPrintfExW
#ELSE
   MACRO StringCchPrintfEx = StringCchPrintfExA
#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'sprintf' with
'    some additional parameters.  In addition to functionality provided by
'    StringCbPrintf, this routine also returns a pointer to the end of the
'    destination string and the number of bytes left in the destination string
'    including the null terminator. The flags parameter allows additional controls.

'Arguments:

'    pszDest         -   destination string

'    cbDest          -   size of destination buffer in bytes.
'                        length must be sufficient to contain the resulting
'                        formatted string plus the null terminator.

'    ppszDestEnd     -   if ppszDestEnd is non-null, the function will return a
'                        pointer to the end of the destination string.  If the
'                        function printed any data, the result will point to the
'                        null termination character

'    pcbRemaining    -   if pcbRemaining is non-null, the function will return
'                        the number of bytes left in the destination string,
'                        including the null terminator

'    dwFlags         -   controls some details of the string copy:

'        STRSAFE_FILL_BEHIND_NULL
'                    if the function succeeds, the low byte of dwFlags will be
'                    used to fill the uninitialize part of destination buffer
'                    behind the null terminator

'        STRSAFE_IGNORE_NULLS
'                    treat NULL string pointers like empty strings (TEXT(""))

'        STRSAFE_FILL_ON_FAILURE
'                    if the function fails, the low byte of dwFlags will be
'                    used to fill all of the destination buffer, and it will
'                    be null terminated. This will overwrite any truncated
'                    string returned when the failure is
'                    STRSAFE_E_INSUFFICIENT_BUFFER

'        STRSAFE_NO_TRUNCATION /
'        STRSAFE_NULL_ON_FAILURE
'                    if the function fails, the destination buffer will be set
'                    to the empty string. This will overwrite any truncated string
'                    returned when the failure is STRSAFE_E_INSUFFICIENT_BUFFER.

'    pszFormat       -   format string which must be null terminated

'    ...             -   additional parameters to be formatted according to
'                        the format string

'Notes:
'    Behavior is undefined if destination, format strings or any arguments
'    strings overlap.

'    pszDest and pszFormat should not be NULL unless the STRSAFE_IGNORE_NULLS
'    flag is specified.  If STRSAFE_IGNORE_NULLS is passed, both pszDest and
'    pszFormat may be NULL.  An error may still be returned even though NULLS
'    are ignored due to insufficient space.

'Return Value:

'    S_OK           -   if there was source data and it was all concatenated and
'                       the resultant dest string was null terminated

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that the print
'                       operation failed due to insufficient space. When this
'                       error occurs, the destination buffer is modified to
'                       contain a truncated version of the ideal result and is
'                       null terminated. This is useful for situations where
'                       truncation is ok.

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function

'--*/

DECLARE FUNCTION StringCbPrintfExA CDECL IMPORT "strsafe.dll" ALIAS "StringCbPrintfExA" ( _
   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cbDest) LPSTR pszDest
 , BYVAL cbDest AS DWORD _                              ' __in size_t cbDest
 , BYREF ppszDestEnd AS DWORD _                         ' __out LPSTR* ppszDestEnd
 , BYREF pcchRemaining AS DWORD _                       ' __out_opt size_t* pcchRemaining
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pszFormat AS ASCIIZ _                          ' __in LPCSTR pszFormat
 , OPTIONAL BYREF ANY  _                                ' optional arguments
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 ) AS LONG                                              ' HRESULT


DECLARE FUNCTION StringCbPrintfExW CDECL IMPORT "strsafe.dll" ALIAS "StringCbPrintfExW" ( _
   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cbDest) LPWSTR pszDest
 , BYVAL cbDest AS DWORD _                              ' __in size_t cbDest
 , BYREF ppszDestEnd AS DWORD _                         ' __out LPWSTR* ppszDestEnd
 , BYREF pcchRemaining AS DWORD _                       ' __out_opt size_t* pcchRemaining
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pszFormat AS WSTRINGZ _                        ' __in LPCWSTR pszFormat
 , OPTIONAL BYREF ANY  _                                ' optional arguments
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCbPrintfEx = StringCbPrintfExW
#ELSE
   MACRO StringCbPrintfEx = StringCbPrintfExA
#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'vsprintf' with
'    some additional parameters.  In addition to functionality provided by
'    StringCchVPrintf, this routine also returns a pointer to the end of the
'    destination string and the number of characters left in the destination string
'    including the null terminator. The flags parameter allows additional controls.

'Arguments:

'    pszDest         -   destination string

'    cchDest         -   size of destination buffer in characters.
'                        length must be sufficient to contain the resulting
'                        formatted string plus the null terminator.

'    ppszDestEnd     -   if ppszDestEnd is non-null, the function will return a
'                        pointer to the end of the destination string.  If the
'                        function printed any data, the result will point to the
'                        null termination character

'    pcchRemaining   -   if pcchRemaining is non-null, the function will return
'                        the number of characters left in the destination string,
'                        including the null terminator

'    dwFlags         -   controls some details of the string copy:

'        STRSAFE_FILL_BEHIND_NULL
'                    if the function succeeds, the low byte of dwFlags will be
'                    used to fill the uninitialize part of destination buffer
'                    behind the null terminator

'        STRSAFE_IGNORE_NULLS
'                    treat NULL string pointers like empty strings (TEXT(""))

'        STRSAFE_FILL_ON_FAILURE
'                    if the function fails, the low byte of dwFlags will be
'                    used to fill all of the destination buffer, and it will
'                    be null terminated. This will overwrite any truncated
'                    string returned when the failure is
'                    STRSAFE_E_INSUFFICIENT_BUFFER

'        STRSAFE_NO_TRUNCATION /
'        STRSAFE_NULL_ON_FAILURE
'                    if the function fails, the destination buffer will be set
'                    to the empty string. This will overwrite any truncated string
'                    returned when the failure is STRSAFE_E_INSUFFICIENT_BUFFER.

'    pszFormat       -   format string which must be null terminated

'    argList         -   va_list from the variable arguments according to the
'                        stdarg.h convention

'Notes:
'    Behavior is undefined if destination, format strings or any arguments
'    strings overlap.

'    pszDest and pszFormat should not be NULL unless the STRSAFE_IGNORE_NULLS
'    flag is specified.  If STRSAFE_IGNORE_NULLS is passed, both pszDest and
'    pszFormat may be NULL.  An error may still be returned even though NULLS
'    are ignored due to insufficient space.

'Return Value:

'    S_OK           -   if there was source data and it was all concatenated and
'                       the resultant dest string was null terminated

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that the print
'                       operation failed due to insufficient space. When this
'                       error occurs, the destination buffer is modified to
'                       contain a truncated version of the ideal result and is
'                       null terminated. This is useful for situations where
'                       truncation is ok.

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function

'--*/

DECLARE FUNCTION StringCchVPrintfExA IMPORT "strsafe.dll" ALIAS "StringCchVPrintfExA" ( _
   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cchDest) LPSTR pszDest
 , BYVAL cchDest AS DWORD _                             ' __in size_t cchDest
 , BYREF ppszDestEnd AS DWORD _                         ' __out LPSTR* ppszDestEnd
 , BYREF pcchRemaining AS DWORD _                       ' __out_opt size_t* pcchRemaining
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pszFormat AS ASCIIZ _                          ' __in LPCSTR pszFormat
 , BYREF argList AS ANY _                               ' __in va_list argList
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringCchVPrintfExW IMPORT "strsafe.dll" ALIAS "StringCchVPrintfExW" ( _
   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cchDest) LPSWTR pszDest
 , BYVAL cchDest AS DWORD _                             ' __in size_t cchDest
 , BYREF ppszDestEnd AS DWORD _                         ' __out LPWSTR* ppszDestEnd
 , BYREF pcchRemaining AS DWORD _                       ' __out_opt size_t* pcchRemaining
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pszFormat AS WSTRINGZ _                        ' __in LPCWSTR pszFormat
 , BYREF argList AS ANY _                               ' __in va_list argList
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCchVPrintfEx = StringCchVPrintfExW
#ELSE
   MACRO StringCchVPrintfEx = StringCchVPrintfExA
#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'vsprintf' with
'    some additional parameters.  In addition to functionality provided by
'    StringCbVPrintf, this routine also returns a pointer to the end of the
'    destination string and the number of characters left in the destination string
'    including the null terminator. The flags parameter allows additional controls.

'Arguments:

'    pszDest         -   destination string

'    cbDest          -   size of destination buffer in bytes.
'                        length must be sufficient to contain the resulting
'                        formatted string plus the null terminator.

'    ppszDestEnd     -   if ppszDestEnd is non-null, the function will return
'                        a pointer to the end of the destination string.  If the
'                        function printed any data, the result will point to the
'                        null termination character

'    pcbRemaining    -   if pcbRemaining is non-null, the function will return
'                        the number of bytes left in the destination string,
'                        including the null terminator

'    dwFlags         -   controls some details of the string copy:

'        STRSAFE_FILL_BEHIND_NULL
'                    if the function succeeds, the low byte of dwFlags will be
'                    used to fill the uninitialize part of destination buffer
'                    behind the null terminator

'        STRSAFE_IGNORE_NULLS
'                    treat NULL string pointers like empty strings (TEXT(""))

'        STRSAFE_FILL_ON_FAILURE
'                    if the function fails, the low byte of dwFlags will be
'                    used to fill all of the destination buffer, and it will
'                    be null terminated. This will overwrite any truncated
'                    string returned when the failure is
'                    STRSAFE_E_INSUFFICIENT_BUFFER

'        STRSAFE_NO_TRUNCATION /
'        STRSAFE_NULL_ON_FAILURE
'                    if the function fails, the destination buffer will be set
'                    to the empty string. This will overwrite any truncated string
'                    returned when the failure is STRSAFE_E_INSUFFICIENT_BUFFER.

'    pszFormat       -   format string which must be null terminated

'    argList         -   va_list from the variable arguments according to the
'                        stdarg.h convention

'Notes:
'    Behavior is undefined if destination, format strings or any arguments
'    strings overlap.

'    pszDest and pszFormat should not be NULL unless the STRSAFE_IGNORE_NULLS
'    flag is specified.  If STRSAFE_IGNORE_NULLS is passed, both pszDest and
'    pszFormat may be NULL.  An error may still be returned even though NULLS
'    are ignored due to insufficient space.

'Return Value:

'    S_OK           -   if there was source data and it was all concatenated and
'                       the resultant dest string was null terminated

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that the print
'                       operation failed due to insufficient space. When this
'                       error occurs, the destination buffer is modified to
'                       contain a truncated version of the ideal result and is
'                       null terminated. This is useful for situations where
'                       truncation is ok.

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function

'--*/

DECLARE FUNCTION StringCbVPrintfExA IMPORT "strsafe.dll" ALIAS "StringCbVPrintfExA" ( _
   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cbDest) LPSTR pszDest
 , BYVAL cbDest AS DWORD _                              ' __in size_t cbDest
 , BYREF ppszDestEnd AS DWORD _                         ' __out LPSTR* ppszDestEnd
 , BYREF pcbRemaining AS DWORD _                        ' __out_opt size_t* pcbRemaining
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pszFormat AS ASCIIZ _                          ' __in LPCSTR pszFormat
 , BYREF argList AS ANY _                               ' __in va_list argList
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringCbVPrintfExW IMPORT "strsafe.dll" ALIAS "StringCbVPrintfExW" ( _
   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cbDest) LPWSTR pszDest
 , BYVAL cbDest AS DWORD _                              ' __in size_t cbDest
 , BYREF ppszDestEnd AS DWORD _                         ' __out LPWSTR* ppszDestEnd
 , BYREF pcbRemaining AS DWORD _                        ' __out_opt size_t* pcbRemaining
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pszFormat AS WSTRINGZ _                        ' __in LPCWSTR pszFormat
 , BYREF argList AS ANY _                               ' __in va_list argList
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCbVPrintfEx = StringCbVPrintfExW
#ELSE
   MACRO StringCbVPrintfEx = StringCbVPrintfExA
#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'gets'.
'    The size of the destination buffer (in characters) is a parameter and
'    this function will not write past the end of this buffer and it will
'    ALWAYS null terminate the destination buffer (unless it is zero length).

'    This routine is not a replacement for fgets.  That function does not replace
'    newline characters with a null terminator.

'    This function returns a hresult, and not a pointer.  It returns
'    S_OK if any characters were read from stdin and copied to pszDest and
'    pszDest was null terminated, otherwise it will return a failure code.

'Arguments:

'    pszDest     -   destination string

'    cchDest     -   size of destination buffer in characters.

'Notes:
'    pszDest should not be NULL. See StringCchGetsEx if you require the handling
'    of NULL values.

'    cchDest must be > 1 for this function to succeed.

'Return Value:

'    S_OK           -   data was read from stdin and copied, and the resultant
'                       dest string was null terminated

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_END_OF_FILE /
'      HRESULT_CODE(hr) == ERROR_HANDLE_EOF
'                   -   this return value indicates an error or end-of-file
'                       condition, use feof or ferror to determine which one has
'                       occured.

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that there was
'                       insufficient space in the destination buffer to copy any
'                       data

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function.

'--*/

' Note: Not exported

DECLARE FUNCTION StringCchGetsA IMPORT "strsafe.dll" ALIAS "StringCchGetsA" ( _
   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cchDest) LPSTR pszDest
 , BYVAL cchDest AS DWORD _                             ' __in size_t cchDest
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringCchGetsW IMPORT "strsafe.dll" ALIAS "StringCchGetsW" ( _
   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cchDest) LPWSTR pszDest
 , BYVAL cchDest AS DWORD _                             ' __in size_t cchDest
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCchGets = StringCchGetsW
#ELSE
   MACRO StringCchGets = StringCchGetsA
#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'gets'.
'    The size of the destination buffer (in bytes) is a parameter and
'    this function will not write past the end of this buffer and it will
'    ALWAYS null terminate the destination buffer (unless it is zero length).

'    This routine is not a replacement for fgets.  That function does not replace
'    newline characters with a null terminator.

'    This function returns a hresult, and not a pointer.  It returns
'    S_OK if any characters were read from stdin and copied to pszDest
'    and pszDest was null terminated, otherwise it will return a failure code.

'Arguments:

'    pszDest     -   destination string

'    cbDest      -   size of destination buffer in bytes.

'Notes:
'    pszDest should not be NULL. See StringCbGetsEx if you require the handling
'    of NULL values.

'    cbDest must be > sizeof(TCHAR) for this function to succeed.

'Return Value:

'    S_OK           -   data was read from stdin and copied, and the resultant
'                       dest string was null terminated

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_END_OF_FILE /
'      HRESULT_CODE(hr) == ERROR_HANDLE_EOF
'                   -   this return value indicates an error or end-of-file
'                       condition, use feof or ferror to determine which one has
'                       occured.

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that there was
'                       insufficient space in the destination buffer to copy any
'                       data

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function.

'--*/

' Note: Not exported

'DECLARE FUNCTION StringCbGetsA IMPORT "strsafe.dll" ALIAS "StringCbGetsA" ( _
'   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cbDest) LPSTR pszDest
' , BYVAL cbDest AS DWORD _                              ' __in size_t cbDest
' ) AS LONG                                              ' HRESULT

'DECLARE FUNCTION StringCbGetsW IMPORT "strsafe.dll" ALIAS "StringCbGetsW" ( _
'   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cbDest) LPWSTR pszDest
' , BYVAL cbDest As DWORD _                              ' __in size_t cbDest
' ) AS LONG                                              ' HRESULT

'#IF %DEF(%UNICODE)
'   MACRO StringCbGets = StringCbGetsW
'#ELSE
'   MACRO StringCbGets = StringCbGetsA
'#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'gets' with
'    some additional parameters. In addition to functionality provided by
'    StringCchGets, this routine also returns a pointer to the end of the
'    destination string and the number of characters left in the destination string
'    including the null terminator. The flags parameter allows additional controls.

'Arguments:

'    pszDest         -   destination string

'    cchDest         -   size of destination buffer in characters.

'    ppszDestEnd     -   if ppszDestEnd is non-null, the function will return a
'                        pointer to the end of the destination string.  If the
'                        function copied any data, the result will point to the
'                        null termination character

'    pcchRemaining   -   if pcchRemaining is non-null, the function will return the
'                        number of characters left in the destination string,
'                        including the null terminator

'    dwFlags         -   controls some details of the string copy:

'        STRSAFE_FILL_BEHIND_NULL
'                    if the function succeeds, the low byte of dwFlags will be
'                    used to fill the uninitialize part of destination buffer
'                    behind the null terminator

'        STRSAFE_IGNORE_NULLS
'                    treat NULL string pointers like empty strings (TEXT("")).

'        STRSAFE_FILL_ON_FAILURE
'                    if the function fails, the low byte of dwFlags will be
'                    used to fill all of the destination buffer, and it will
'                    be null terminated.

'        STRSAFE_NO_TRUNCATION /
'        STRSAFE_NULL_ON_FAILURE
'                    if the function fails, the destination buffer will be set
'                    to the empty string.

'Notes:
'    pszDest should not be NULL unless the STRSAFE_IGNORE_NULLS flag is specified.
'    If STRSAFE_IGNORE_NULLS is passed and pszDest is NULL, an error may still be
'    returned even though NULLS are ignored

'    cchDest must be > 1 for this function to succeed.

'Return Value:

'    S_OK           -   data was read from stdin and copied, and the resultant
'                       dest string was null terminated

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_END_OF_FILE /
'      HRESULT_CODE(hr) == ERROR_HANDLE_EOF
'                   -   this return value indicates an error or end-of-file
'                       condition, use feof or ferror to determine which one has
'                       occured.

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that there was
'                       insufficient space in the destination buffer to copy any
'                       data

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function.

'--*/

' Note: Not exported.

'DECLARE FUNCTION StringCchGetsExA IMPORT "strsafe.dll" ALIAS "StringCchGetsExA" ( _
'   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cchDest) LPSTR pszDest
' , BYVAL cchDest AS DWORD _                             ' __in size_t cchDest
' , BYREF ppszDestEnd AS DWORD _                         ' __out LPSTR* ppszDestEnd
' , BYREF pcchRemaining AS DWORD _                       ' __out_opt size_t* pcchRemaining
' , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
' ) AS LONG                                              ' HRESULT

'DECLARE FUNCTION StringCchGetsExW IMPORT "strsafe.dll" ALIAS "StringCchGetsExW" ( _
'   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cchDest) LPWSTR pszDest
' , BYVAL cchDest AS DWORD _                             ' __in size_t cchDest
' , BYREF ppszDestEnd AS DWORD _                         ' __out LPWSTR* ppszDestEnd
' , BYREF pcchRemaining AS DWORD _                       ' __out_opt size_t* pcchRemaining
' , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
' ) AS LONG                                              ' HRESULT

'#IF %DEF(%UNICODE)
'   MACRO StringCchGetsEx = StringCchGetsExW
'#ELSE
'   MACRO StringCchGetsEx = StringCchGetsExA
'#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'gets' with
'    some additional parameters. In addition to functionality provided by
'    StringCbGets, this routine also returns a pointer to the end of the
'    destination string and the number of characters left in the destination string
'    including the null terminator. The flags parameter allows additional controls.

'Arguments:

'    pszDest         -   destination string

'    cbDest          -   size of destination buffer in bytes.

'    ppszDestEnd     -   if ppszDestEnd is non-null, the function will return a
'                        pointer to the end of the destination string.  If the
'                        function copied any data, the result will point to the
'                        null termination character

'    pcbRemaining    -   if pcbRemaining is non-null, the function will return the
'                        number of bytes left in the destination string,
'                        including the null terminator

'    dwFlags         -   controls some details of the string copy:

'        STRSAFE_FILL_BEHIND_NULL
'                    if the function succeeds, the low byte of dwFlags will be
'                    used to fill the uninitialize part of destination buffer
'                    behind the null terminator

'        STRSAFE_IGNORE_NULLS
'                    treat NULL string pointers like empty strings (TEXT("")).

'        STRSAFE_FILL_ON_FAILURE
'                    if the function fails, the low byte of dwFlags will be
'                    used to fill all of the destination buffer, and it will
'                    be null terminated.

'        STRSAFE_NO_TRUNCATION /
'        STRSAFE_NULL_ON_FAILURE
'                    if the function fails, the destination buffer will be set
'                    to the empty string.

'Notes:
'    pszDest should not be NULL unless the STRSAFE_IGNORE_NULLS flag is specified.
'    If STRSAFE_IGNORE_NULLS is passed and pszDest is NULL, an error may still be
'    returned even though NULLS are ignored

'    cbDest must be > sizeof(TCHAR) for this function to succeed

'Return Value:

'    S_OK           -   data was read from stdin and copied, and the resultant
'                       dest string was null terminated

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'      STRSAFE_E_END_OF_FILE /
'      HRESULT_CODE(hr) == ERROR_HANDLE_EOF
'                   -   this return value indicates an error or end-of-file
'                       condition, use feof or ferror to determine which one has
'                       occured.

'      STRSAFE_E_INSUFFICIENT_BUFFER /
'      HRESULT_CODE(hr) == ERROR_INSUFFICIENT_BUFFER
'                   -   this return value is an indication that there was
'                       insufficient space in the destination buffer to copy any
'                       data

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function.

'--*/

' Note: Not exported.

'DECLARE FUNCTION StringCbGetsExA IMPORT "strsafe.dll" ALIAS "StringCbGetsExA" ( _
'   BYREF pszDest AS ASCIIZ _                            ' __out_ecount(cbDest) LPSTR pszDest
' , BYVAL cbDest AS DWORD _                              ' __in size_t cbDest
' , BYREF ppszDestEnd AS DWORD _                         ' __out LPSTR* ppszDestEnd
' , BYREF pcbRemaining AS DWORD _                        ' __out_opt size_t* pcbRemaining
' , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
' ) AS LONG                                              ' HRESULT

'DECLARE FUNCTION StringCchGetsExW IMPORT "strsafe.dll" ALIAS "StringCchGetsExW" ( _
'   BYREF pszDest AS WSTRINGZ _                          ' __out_ecount(cbDest) LPWSTR pszDest
' , BYVAL cbDest AS DWORD _                              ' __in size_t cbDest
' , BYREF ppszDestEnd AS DWORD _                         ' __out LPWSTR* ppszDestEnd
' , BYREF pcbRemaining AS DWORD _                        ' __out_opt size_t* pcbRemaining
' , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
' ) AS LONG                                              ' HRESULT

'#IF %DEF(%UNICODE)
'   MACRO StringCbGetsEx = StringCchGetsExW
'#ELSE
'   MACRO StringCbGetsEx = StringCchGetsExA
'#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'strlen'.
'    It is used to make sure a string is not larger than a given length, and
'    it optionally returns the current length in characters not including
'    the null terminator.

'    This function returns a hresult, and not a pointer.  It returns
'    S_OK if the string is non-null and the length including the null
'    terminator is less than or equal to cchMax characters.

'Arguments:

'    psz         -   string to check the length of

'    cchMax      -   maximum number of characters including the null terminator
'                    that psz is allowed to contain

'    pcch        -   if the function succeeds and pcch is non-null, the current length
'                    in characters of psz excluding the null terminator will be returned.
'                    This out parameter is equivalent to the return value of strlen(psz)

'Notes:
'    psz can be null but the function will fail

'    cchMax should be greater than zero or the function will fail

'Return Value:

'    S_OK           -   psz is non-null and the length including the null
'                       terminator is less than or equal to cchMax characters

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function.

'--*/

DECLARE FUNCTION StringCchLengthA IMPORT "strsafe.dll" ALIAS "StringCchLengthA" ( _
   BYREF psz AS ASCIIZ _                                ' __in_opt LPCSTR psz
 , BYVAL cchMax AS DWORD _                              ' __in size_t cchMax
 , BYREF pcchLength AS DWORD _                          ' __out_opt size_t* pcchLength
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringCchLengthW IMPORT "strsafe.dll" ALIAS "StringCchLengthW" ( _
   BYREF psz AS WSTRINGZ _                              ' __in_opt LPCWSTR psz
 , BYVAL cchMax AS DWORD _                              ' __in size_t cchMax
 , BYREF pcchLength AS DWORD _                          ' __out_opt size_t* pcchLength
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCchLength = StringCchLengthW
#ELSE
   MACRO StringCchLength = StringCchLengthA
#ENDIF

'Routine Description:

'    This routine is a safer version of the C built-in function 'strlen'.
'    It is used to make sure a string is not larger than a given length, and
'    it optionally returns the current length in bytes not including
'    the null terminator.

'    This function returns a hresult, and not a pointer.  It returns
'    S_OK if the string is non-null and the length including the null
'    terminator is less than or equal to cbMax bytes.

'Arguments:

'    psz         -   string to check the length of

'    cbMax       -   maximum number of bytes including the null terminator
'                    that psz is allowed to contain

'    pcb         -   if the function succeeds and pcb is non-null, the current length
'                    in bytes of psz excluding the null terminator will be returned.
'                    This out parameter is equivalent to the return value of strlen(psz) * sizeof(TCHAR)

'Notes:
'    psz can be null but the function will fail

'    cbMax should be greater than or equal to sizeof(TCHAR) or the function will fail

'Return Value:

'    S_OK           -   psz is non-null and the length including the null
'                       terminator is less than or equal to cbMax bytes

'    failure        -   you can use the macro HRESULT_CODE() to get a win32
'                       error code for all hresult failure cases

'    It is strongly recommended to use the SUCCEEDED() / FAILED() macros to test the
'    return value of this function.

'--*/

DECLARE FUNCTION StringCbLengthA IMPORT "strsafe.dll" ALIAS "StringCbLengthA" ( _
   BYREF psz AS ASCIIZ _                                ' __in_opt LPCSTR psz
 , BYVAL cbMax AS DWORD _                               ' __in size_t cbMax
 , BYREF pcbLength AS DWORD _                           ' __out_opt size_t* pcbLength
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StringCbLengthW IMPORT "strsafe.dll" ALIAS "StringCbLengthW" ( _
   BYREF psz AS WSTRINGZ _                              ' __in_opt LPCWSTR psz
 , BYVAL cbMax AS DWORD _                               ' __in size_t cbMax
 , BYREF pcbLength AS DWORD _                           ' __out_opt size_t* pcbLength
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StringCbLength = StringCbLengthW
#ELSE
   MACRO StringCbLength = StringCbLengthA
#ENDIF
