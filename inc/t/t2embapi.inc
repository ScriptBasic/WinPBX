' ########################################################################################
' Microsoft Windows
' File: t2embapi.inc
' Contents: OpenType embedding services dll (T2EMBED.DLL)
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%T2EMBAPI_INC = 1

'// Charset flags for ulCharSet field of TTEmbedFont
%CHARSET_UNICODE    = 1
%CHARSET_DEFAULT    = 1
%CHARSET_SYMBOL     = 2
%CHARSET_GLYPHIDX   = 3

'// Status returned by TTLoadEmbeddedFont
%EMBED_PREVIEWPRINT = 1
%EMBED_EDITABLE     = 2
%EMBED_INSTALLABLE  = 3
%EMBED_NOEMBEDDING  = 4

'// Use restriction flags
%LICENSE_INSTALLABLE  = &H0000???
%LICENSE_DEFAULT      = &H0000???
%LICENSE_NOEMBEDDING  = &H0002???
%LICENSE_PREVIEWPRINT = &H0004???
%LICENSE_EDITABLE     = &H0008???

'// Options given to TTEmbedFont in uFlags parameter
%TTEMBED_RAW                      = &H00000000???
%TTEMBED_SUBSET                   = &H00000001???
%TTEMBED_TTCOMPRESSED             = &H00000004???
%TTEMBED_FAILIFVARIATIONSIMULATED = &H00000010???
'// Embed EUDC font. If there is typeface EUDC embed it otherwise embed system EUDC.
%TTEMBED_EMBEDEUDC                = &H00000020???
%TTEMBED_WEBOBJECT                = &H00000080???
%TTEMBED_XORENCRYPTDATA           = &H10000000???

'// Bits returned through pulStatus for TTEmbedFont
%TTEMBED_VARIATIONSIMULATED       = &H00000001???
'// Bit set if EUDC embed success.
%TTEMBED_EUDCEMBEDDED             = &H00000002???
'// Bit set if font embedding permissions indicate no subset and subset requested by client.
%TTEMBED_SUBSETCANCEL             = &H00000004???

'// Flag options for TTLoadEmbeddedFont
%TTLOAD_PRIVATE                   = &H00000001???
'// If typeface already has EUDC, overwrite setting.
%TTLOAD_EUDC_OVERWRITE            = &H00000002???

'// Bits returned through pulStatus for TTLoadEmbeddedFont
%TTLOAD_FONT_SUBSETTED       = &H00000001???
%TTLOAD_FONT_IN_SYSSTARTUP   = &H00000002???
%TTLOAD_EUDC_SET             = &H00000004???

'// Flag options for TTDeleteEmbeddedFont
%TTDELETE_DONTREMOVEFONT     = &H00000001???

'// Error codes
%E_NONE                      = &H0000&
%E_API_NOTIMPL               = &H0001&

'// Top level error codes
%E_CHARCODECOUNTINVALID      = &H0002&
%E_CHARCODESETINVALID        = &H0003&
%E_DEVICETRUETYPEFONT        = &H0004&
%E_HDCINVALID                = &H0006&
%E_NOFREEMEMORY              = &H0007&
%E_FONTREFERENCEINVALID      = &H0008&
%E_NOTATRUETYPEFONT          = &H000A&
%E_ERRORACCESSINGFONTDATA    = &H000C&
%E_ERRORACCESSINGFACENAME    = &H000D&
%E_ERRORUNICODECONVERSION    = &H0011&
%E_ERRORCONVERTINGCHARS      = &H0012&
%E_EXCEPTION                 = &H0013&
%E_RESERVEDPARAMNOTNULL      = &H0014&
%E_CHARSETINVALID            = &H0015&
%E_FILE_NOT_FOUND            = &H0017&
%E_TTC_INDEX_OUT_OF_RANGE    = &H0018&
%E_INPUTPARAMINVALID         = &H0019&

'// Indep level error codes
%E_ERRORCOMPRESSINGFONTDATA    = &H0100&
%E_FONTDATAINVALID             = &H0102&
%E_NAMECHANGEFAILED            = &H0103&
%E_FONTNOTEMBEDDABLE           = &H0104&
%E_PRIVSINVALID                = &H0105&
%E_SUBSETTINGFAILED            = &H0106&
%E_READFROMSTREAMFAILED        = &H0107&
%E_SAVETOSTREAMFAILED          = &H0108&
%E_NOOS2                       = &H0109&
%E_T2NOFREEMEMORY              = &H010A&
%E_ERRORREADINGFONTDATA        = &H010B&
%E_FLAGSINVALID                = &H010C&
%E_ERRORCREATINGFONTFILE       = &H010D&
%E_FONTALREADYEXISTS           = &H010E&
%E_FONTNAMEALREADYEXISTS       = &H010F&
%E_FONTINSTALLFAILED           = &H0110&
%E_ERRORDECOMPRESSINGFONTDATA  = &H0111&
%E_ERRORACCESSINGEXCLUDELIST   = &H0112&
%E_FACENAMEINVALID             = &H0113&
%E_STREAMINVALID               = &H0114&
%E_STATUSINVALID               = &H0115&
%E_PRIVSTATUSINVALID           = &H0116&
%E_PERMISSIONSINVALID          = &H0117&
%E_PBENABLEDINVALID            = &H0118&
%E_SUBSETTINGEXCEPTION         = &H0119&
%E_SUBSTRING_TEST_FAIL         = &H011A&
%E_FONTVARIATIONSIMULATED      = &H011B&
%E_FONTFAMILYNAMENOTINFULL     = &H011D&

'// Bottom level error codes
%E_ADDFONTFAILED             = &H0200&
%E_COULDNTCREATETEMPFILE     = &H0201&
%E_FONTFILECREATEFAILED      = &H0203&
%E_WINDOWSAPI                = &H0204&
%E_FONTFILENOTFOUND          = &H0205&
%E_RESOURCEFILECREATEFAILED  = &H0206&
%E_ERROREXPANDINGFONTDATA    = &H0207&
%E_ERRORGETTINGDC            = &H0208&
%E_EXCEPTIONINDECOMPRESSION  = &H0209&
%E_EXCEPTIONINCOMPRESSION    = &H020A&

'// 1st argument - Stream identifier (file handle or other) (dwStream) */
'// 2nd argument - Address of buffer with data to read or write */
'// 3rd argument - Number of bytes to read or write */
'typedef unsigned long( WINAPIV *READEMBEDPROC ) ( void*, void*, const unsigned long );

'FUNCTION READEMBEDPROC ( _
'   BYVAL lpvReadStream AS DWORD _                       ' __in void *lpvReadStream
' , BYVAL lpvBuffer AS DWORD _                           ' __in void *lpvBuffer
' , BYVAL cbBuffer AS DWORD _                            ' __in const unsigned long cbBuffer
' ) AS DWORD                                             ' unsigned long

'typedef unsigned long( WINAPIV *WRITEEMBEDPROC ) ( void*, const void*, const unsigned long );

'FUNCTION WRITEEMBEDPROC ( _
'   BYVAL lpvReadStream AS DWORD _                       ' __in void *lpvWriteStream
' , BYVAL lpvBuffer AS DWORD _                           ' __in void *lpvBuffer
' , BYVAL cbBuffer AS DWORD _                            ' __in const unsigned long cbBuffer
' ) AS DWORD                                             ' unsigned long

' // Size = 8 bytes
TYPE TTLOADINFO DWORD FILL
   usStructSize AS WORD           ' unsigned short // size in bytes of structure client should set to sizeof(TTLOADINFO)
   usRefStrSize AS WORD           ' unsigned short // size in wide characters of pusRefStr including NULL terminator
   pusRefStr    AS WSTRINGZ PTR   ' unsigned short * // reference or actual string.
END TYPE

' // Size = 8 bytes
TYPE TTEMBEDINFO DWORD FILL
   usStructSize  AS WORD           ' unsigned short // size in bytes of structure client should set to sizeof(TTEMBEDINFO)
   usRootStrSize AS WORD           ' unsigned short // size in wide chars of pusSubStr including NULL terminator(s)
   pusRootStr    AS WSTRINGZ PTR   ' unsigned short * // substring(s) of strings given at load time. can have multiple strings separated
                                   '                  //  by a NULL terminator.
END TYPE

' // Size = 24 bytes
TYPE TTVALIDATIONTESTSPARAMS DWORD FILL
   ulStructSize    AS DWORD          ' unsigned long
   lTestFromSize   AS LONG           ' long
   lTestToSize     AS LONG           ' long
   ulCharSet       AS DWORD          ' unsigned long // Same as ulCharSet param to TTEmbedFont.
   usReserved1     AS WORD           ' unsigned short
   usCharCodeCount AS WORD           ' unsigned short // If zero, we test over all glyphs.
   pusCharCodeSet  AS WSTRINGZ PTR   ' unsigned short * // Pointer to array of Unicode chars.
END TYPE

' // Size = 24 bytes
TYPE TTVALIDATIONTESTSPARAMSEX DWORD FILL
   ulStructSize    AS DWORD          ' unsigned loong
   lTestFromSize   AS LONG           ' long
   lTestToSize     AS LONG           ' long
   ulCharSet       AS DWORD          ' unsigned loong // Same as ulCharSet param to TTEmbedFont.
   usReserved1     AS WORD           ' unsigned short
   usCharCodeCount AS WORD           ' unsigned short // If zero, we test over all glyphs.
   pulCharCodeSet  AS WSTRINGZ PTR   ' unsigned short * // Pointer to array of Unicode chars.
END TYPE

'/* Font Embedding APIs ----------------------------------------------------*/

DECLARE FUNCTION TTEmbedFont IMPORT "T2embed.dll" ALIAS "TTEmbedFont" ( _
   BYVAL hDC AS DWORD _                                 ' __in HDC // device-context handle
 , BYVAL ulFlags AS DWORD _                             ' __in ULONG // flags specifying the request
 , BYVAL ulCharSet AS DWORD _                           ' __in ULONG // flags specifying char set
 , BYREF pulPrivStatus AS DWORD _                       ' __out ULONG* pulPrivStatus // upon completion contains embedding priv of font
 , BYREF pulStatus AS DWORD _                           ' __out ULONG* pulStatus // on completion may contain status flags for request
 , BYVAL lpfnWriteToStream AS DWORD _                   ' __callback WRITEEMBEDPROC lpfnWriteToStream // callback function for doc/disk writes
 , BYVAL lpvWriteStream AS DWORD _                      ' __in LPVOID lpvWriteStream // the output stream tokin
 , BYREF pusCharCodeSet AS WORD _                       ' __in_ecount(usCharCodeCount) USHORT* pusCharCodeSet // address of buffer containing optional character codes for subsetting
 , BYVAL usCharCodeCount AS WORD _                      ' __in USHORT usCharCodeCount // number of characters in the lpvCharCodeSet buffer
 , BYVAL usLanguage AS WORD _                           ' __in USHORT usLanguage // specifies the language in the name table to keep set to 0 to keep all
 , BYREF pTTEmbedInfo AS TTEMBEDINFO _                  ' __in_opt TTEMBEDINFO* pTTEmbedInfo // optional security
 ) AS LONG                                              ' LONG

DECLARE FUNCTION TTEmbedFontFromFileA IMPORT "T2embed.dll" ALIAS "TTEmbedFontFromFileA" ( _
   BYVAL hDC AS DWORD _                                 ' __in HDC // device-context handle
 , BYREF szFontFileName AS ASCIIZ _                     ' __in LPCSTR szFontFileName // TrueType font file name
 , BYVAL usTTCIndex AS WORD _                           ' __in USHORT usTTCIndex // If file image is a TTC, this must be zero based index
 , BYVAL ulFlags AS DWORD _                             ' __in ULONG // flags specifying the request
 , BYVAL ulCharSet AS DWORD _                           ' __in ULONG // flags specifying char set
 , BYREF pulPrivStatus AS DWORD _                       ' __out ULONG* pulPrivStatus // upon completion contains embedding priv of font
 , BYREF pulStatus AS DWORD _                           ' __out ULONG* pulStatus // on completion may contain status flags for request
 , BYVAL lpfnWriteToStream AS DWORD _                   ' __callback WRITEEMBEDPROC lpfnWriteToStream // callback function for doc/disk writes
 , BYVAL lpvWriteStream AS DWORD _                      ' __in LPVOID lpvWriteStream // the output stream tokin
 , BYREF pusCharCodeSet AS WORD _                       ' __in_ecount(usCharCodeCount) USHORT* pusCharCodeSet // address of buffer containing optional character codes for subsetting
 , BYVAL usCharCodeCount AS WORD _                      ' __in USHORT usCharCodeCount // number of characters in the lpvCharCodeSet buffer
 , BYVAL usLanguage AS WORD _                           ' __in USHORT usLanguage // specifies the language in the name table to keep set to 0 to keep all
 , BYREF pTTEmbedInfo AS TTEMBEDINFO _                  ' __in_opt TTEMBEDINFO* pTTEmbedInfo // optional security
 ) AS LONG                                              ' LONG

DECLARE FUNCTION TTLoadEmbeddedFont IMPORT "T2embed.dll" ALIAS "TTLoadEmbeddedFont" ( _
   BYREF phFontReference AS DWORD _                     ' __out HANDLE* phFontReference // on completion, contains handle to identify embedded font installed on system
 , BYVAL ulFlags AS DWORD _                             ' __in ULONG // flags specifying the request
 , BYREF pulPrivStatus AS DWORD _                       ' __out ULONG* pulPrivStatus // on completion, contains the embedding status
 , BYVAL ulPrivs AS DWORD _                             ' __in ULONG ulPrivs // allows for the reduction of licensing privileges
 , BYREF pulStatus AS DWORD _                           ' __out ULONG* pulStatus // on completion, may contain status flags for request
 , BYVAL lpfnReadFromStream AS DWORD _                  ' __in READEMBEDPROC lpfnReadFromStream // callback function for doc/disk reads
 , BYVAL lpvReadStream AS DWORD _                       ' __in LPVOID lpvReadStream // the input stream tokin
 , BYREF szWinFamilyName AS WSTRINGZ _                  ' __in_opt LPWSTR szWinFamilyName // the new 16 bit windows family name can be NULL
 , BYREF szMacFamilyName AS ASCIIZ _                    ' __in_opt LPSTR szMacFamilyName // the new 8 bit mac family name can be NULL
 , BYREF pTTLoadInfo AS TTLOADINFO _                    ' __in_opt TTLOADINFO* pTTLoadInfo // optional security
 ) AS LONG                                              ' LONG

DECLARE FUNCTION TTGetEmbeddedFontInfo IMPORT "T2embed.dll" ALIAS "TTGetEmbeddedFontInfo" ( _
   BYVAL ulFlags AS DWORD _                             ' __in ULONG ulFlags // flags specifying the request
 , BYREF pulPrivStatus AS DWORD _                       ' __out ULONG* pulPrivStatus // on completion, contains the embedding status
 , BYVAL ulPrivs AS DWORD _                             ' __in ULONG ulPrivs // allows for the reduction of licensing privileges
 , BYREF pulStatus AS DWORD _                           ' __out ULONG* pulStatus // on completion, may contain status flags for request
 , BYVAL lpfnReadFromStream AS DWORD _                  ' __callback READEMBEDPROC lpfnReadFromStream // callback function for doc/disk reads
 , BYVAL lpvReadStream AS DWORD _                       ' __in LPVOID lpvReadStream // the input stream tokin
 , BYREF pTTLoadInfo AS TTLOADINFO _                    ' __in_opt TTLOADINFO* pTTLoadInfo // optional security
 ) AS LONG                                              ' LONG

DECLARE FUNCTION TTDeleteEmbeddedFont IMPORT "T2embed.dll" ALIAS "TTDeleteEmbeddedFont" ( _
   BYVAL hFontReference AS DWORD _                      ' __in HANDLE hFontReference // Reference to font value provided by load functions
 , BYVAL ulFlags AS DWORD _                             ' __in ULONG ulFlags
 , BYREF pulStatus AS DWORD _                           ' __out ULONG* pulStatus
 ) AS LONG                                              ' LONG

DECLARE FUNCTION TTGetEmbeddingType IMPORT "T2embed.dll" ALIAS "TTGetEmbeddingType" ( _
   BYVAL hDC AS DWORD _                                 ' __in HDC hDC // device context handle
 , BYREF pulEmbedType AS DWORD _                        ' __out ULONG* pulEmbedType // upon completion, contains the embedding status
 ) AS LONG                                              ' LONG

DECLARE FUNCTION TTCharToUnicode IMPORT "T2embed.dll" ALIAS "TTCharToUnicode" ( _
   BYVAL hDC AS DWORD _                                 ' __in HDC hDC // device context handle
 , BYREF pucCharCodes AS BYTE _                         ' __in_ecount(ulCharCodeSize) UCHAR* pucCharCodes // array of 8 bit character codes to convert
 , BYVAL ulCharCodeSize AS DWORD _                      ' __in ULONG ulCharCodeSize // size of 8 bit character code array
 , BYREF pusShortCodes AS WORD _                        ' __out_ecount(ulShortCodeSize) USHORT* pusShortCodes // buffer to recieve Unicode code points
 , BYVAL ulShortCodeSize AS DWORD _                     ' __in ULONG ulShortCodeSize // size in wide characters of 16 bit character code array
 , BYVAL ulFlags AS DWORD _                             ' __in ULONG ulFlags // Control flags
 ) AS LONG                                              ' LONG

DECLARE FUNCTION TTRunValidationTests IMPORT "T2embed.dll" ALIAS "TTRunValidationTests" ( _
   BYVAL hDC AS DWORD _                                 ' __in HDC hDC // device context handle
 , BYREF pTestParam AS TTVALIDATIONTESTSPARAMS _        ' __in TTVALIDATIONTESTSPARAMS* pTestParam
 ) AS LONG                                              ' LONG


'/* Font Enabling APIs -----------------------------------------------------*/

DECLARE FUNCTION TTIsEmbeddingEnabled IMPORT "T2embed.dll" ALIAS "TTIsEmbeddingEnabled" ( _
   BYVAL hDC AS DWORD _                                 ' __in HDC hDC // device context handle
 , BYREF pbEnabled AS LONG _                            ' __out BOOL* pbEnabled // upon completion will indicate if enabled
 ) AS LONG                                              ' LONG

DECLARE FUNCTION TTIsEmbeddingEnabledForFacename IMPORT "T2embed.dll" ALIAS "TTIsEmbeddingEnabledForFacename" ( _
   BYREF lpszFacename AS ASCIIZ _                       ' __in LPCSTR lpszFacename // facename
 , BYREF pbEnabled AS LONG _                            ' __out BOOL* pbEnabled // upon completion will indicate if enabled
 ) AS LONG                                              ' LONG

' If fEnable != 0, it removes the indicated typeface name from the "embedding
' exclusion list".  Else, it enters the indicated typeface name in the "embedding exclusion list".
DECLARE FUNCTION TTEnableEmbeddingForFacename IMPORT "T2embed.dll" ALIAS "TTEnableEmbeddingForFacename" ( _
   BYREF lpszFacename AS ASCIIZ _                       ' __in LPCSTR lpszFacename
 , BYVAL bEnable AS LONG _                              ' __in BOOL bEnable
 ) AS LONG                                              ' LONG

DECLARE FUNCTION TTEmbedFontEx IMPORT "T2embed.dll" ALIAS "TTEmbedFontEx" ( _
   BYVAL hDC AS DWORD _                                 ' __in HDC // device-context handle
 , BYVAL ulFlags AS DWORD _                             ' __in ULONG // flags specifying the request
 , BYVAL ulCharSet AS DWORD _                           ' __in ULONG // flags specifying char set
 , BYREF pulPrivStatus AS DWORD _                       ' __out ULONG* pulPrivStatus // upon completion contains embedding priv of font
 , BYREF pulStatus AS DWORD _                           ' __out ULONG* pulStatus // on completion may contain status flags for request
 , BYVAL lpfnWriteToStream AS DWORD _                   ' __callback WRITEEMBEDPROC lpfnWriteToStream // callback function for doc/disk writes
 , BYVAL lpvWriteStream AS DWORD _                      ' __in LPVOID lpvWriteStream // the output stream tokin
 , BYREF pulCharCodeSet AS DWORD _                      ' __in_ecount(usCharCodeCount) USHORT* pulCharCodeSet // address of buffer containing optional character codes for subsetting
 , BYVAL usCharCodeCount AS WORD _                      ' __in USHORT usCharCodeCount // number of characters in the lpvCharCodeSet buffer
 , BYVAL usLanguage AS WORD _                           ' __in USHORT usLanguage // specifies the language in the name table to keep set to 0 to keep all
 , BYREF pTTEmbedInfo AS TTEMBEDINFO _                  ' __in_opt TTEMBEDINFO* pTTEmbedInfo // optional security
 ) AS LONG                                              ' LONG

DECLARE FUNCTION TTRunValidationTestsEx IMPORT "T2embed.dll" ALIAS "TTRunValidationTestsEx" ( _
   BYVAL hDC AS DWORD _                                 ' __in HDC // device-context handle
 , BYREF pTestParam AS TTVALIDATIONTESTSPARAMSEX _      ' __in TTVALIDATIONTESTSPARAMSEX* pTestParam
 ) AS LONG                                              ' LONG

DECLARE FUNCTION TTGetNewFontName IMPORT "T2embed.dll" ALIAS "TTGetNewFontName" ( _
   BYVAL phFontReference AS DWORD _                     ' __in HANDLE* phFontReference // contains handle to identify embedded font installed on system
 , BYREF wzWinFamilyName AS WSTRINGZ _                  ' __out LPWSTR wzWinFamilyName // the new 16 bit windows family name. Must be at least LF_FACESIZE long.
 , BYVAL cchMaxWinName AS LONG _                        ' __in LONG cchMaxWinName // actual length of the windows name.
 , BYREF szMacFamilyName AS ASCIIZ _                    ' __out LPSTR szMacFamilyName // the new 8 bit mac family name. Must be at least LF_FACESIZE long.
 , BYVAL cchMaxMacName AS LONG _                        ' __in LONG cchMaxMacName // actual length of the macintosh name.
 ) AS LONG                                              ' LONG
