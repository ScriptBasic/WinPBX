' ########################################################################################
' Microsoft Windows
' File: InputScope.inc
' Contents: InputScope declarations
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%INPUTSCOPE_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

#IF NOT %DEF(%INPUTSCOPE_DEFINED)
    %INPUTSCOPE_DEFINED = 1

#INCLUDE ONCE "windows.inc"

' enum InputScope
%IS_DEFAULT                       = 0
%IS_URL                           = 1
%IS_FILE_FULLFILEPATH             = 2
%IS_FILE_FILENAME                 = 3
%IS_EMAIL_USERNAME                = 4
%IS_EMAIL_SMTPEMAILADDRESS        = 5
%IS_LOGINNAME                     = 6
%IS_PERSONALNAME_FULLNAME         = 7
%IS_PERSONALNAME_PREFIX           = 8
%IS_PERSONALNAME_GIVENNAME        = 9
%IS_PERSONALNAME_MIDDLENAME       = 10
%IS_PERSONALNAME_SURNAME          = 11
%IS_PERSONALNAME_SUFFIX           = 12
%IS_ADDRESS_FULLPOSTALADDRESS     = 13
%IS_ADDRESS_POSTALCODE            = 14
%IS_ADDRESS_STREET                = 15
%IS_ADDRESS_STATEORPROVINCE       = 16
%IS_ADDRESS_CITY                  = 17
%IS_ADDRESS_COUNTRYNAME           = 18
%IS_ADDRESS_COUNTRYSHORTNAME      = 19
%IS_CURRENCY_AMOUNTANDSYMBOL      = 20
%IS_CURRENCY_AMOUNT               = 21
%IS_DATE_FULLDATE                 = 22
%IS_DATE_MONTH                    = 23
%IS_DATE_DAY                      = 24
%IS_DATE_YEAR                     = 25
%IS_DATE_MONTHNAME                = 26
%IS_DATE_DAYNAME                  = 27
%IS_DIGITS                        = 28
%IS_NUMBER                        = 29
%IS_ONECHAR                       = 30
%IS_PASSWORD                      = 31
%IS_TELEPHONE_FULLTELEPHONENUMBER = 32
%IS_TELEPHONE_COUNTRYCODE         = 33
%IS_TELEPHONE_AREACODE            = 34
%IS_TELEPHONE_LOCALNUMBER         = 35
%IS_TIME_FULLTIME                 = 36
%IS_TIME_HOUR                     = 37
%IS_TIME_MINORSEC                 = 38
%IS_NUMBER_FULLWIDTH              = 39
%IS_ALPHANUMERIC_HALFWIDTH        = 40
%IS_ALPHANUMERIC_FULLWIDTH        = 41
%IS_CURRENCY_CHINESE              = 42
%IS_BOPOMOFO                      = 43
%IS_HIRAGANA                      = 44
%IS_KATAKANA_HALFWIDTH            = 45
%IS_KATAKANA_FULLWIDTH            = 46
%IS_HANJA                         = 47
%IS_HANGUL_HALFWIDTH              = 48
%IS_HANGUL_FULLWIDTH              = 49
%IS_PHRASELIST                    = -1
%IS_REGULAREXPRESSION             = -2
%IS_SRGS                          = -3
%IS_XML                           = -4
%IS_ENUMSTRING                    = -5

DECLARE FUNCTION SetInputScope IMPORT "Msctf.dll" ALIAS "SetInputScope" ( _
   BYVAL hwnd AS DWORD _                                  ' __in HWND hwnd
 , BYVAL inputscope AS LONG _                             ' __in InputScope inputscope
 ) AS LONG                                                ' HRESULT

DECLARE FUNCTION SetInputScopes IMPORT "Msctf.dll" ALIAS "SetInputScopes" ( _
   BYVAL hwnd AS DWORD _                                  ' __in HWND hwnd
 , BYREF pInputScopes AS LONG _                           ' __in const InputScope *pInputScopes
 , BYVAL cInputScopes AS DWORD _                          ' __in UINT cInputScopes
 , BYREF ppszPhraseList AS WSTRINGZ _                     ' __in WCHAR **ppszPhraseList
 , BYVAL cPhrases AS DWORD _                              ' __in UINT cPhrases
 , BYREF pszRegExp AS WSTRINGZ _                          ' __in WCHAR *pszRegExp
 , BYREF pszSRGS AS WSTRINGZ _                            ' __in WCHAR *pszSRGS
 ) AS LONG                                                ' HRESULT

DECLARE FUNCTION SetInputScopeXML IMPORT "Msctf.dll" ALIAS "SetInputScopeXML" ( _
   BYVAL hwnd AS DWORD _                                  ' __in HWND hwnd
 , BYREF pszXML AS WSTRINGZ _                              ' __in WCHAR *pszXML
 ) AS LONG                                                ' HRESULT

DECLARE FUNCTION SetInputScopes2 IMPORT "Msctf.dll" ALIAS "SetInputScopes2" ( _
   BYVAL hwnd AS DWORD _                                  ' __in HWND hwnd
 , BYREF pInputScopes AS LONG _                           ' __in const InputScope *pInputScopes
 , BYVAL cInputScopes AS DWORD _                          ' __in UINT cInputScopes
 , BYVAL pEnumString AS IEnumString _                     ' __in IEnumString *pEnumString
 , OPTIONAL BYREF pszRegExp AS WSTRINGZ _                 ' __in_opt WCHAR *pszRegExp
 , OPTIONAL BYREF pszSRGS AS WSTRINGZ _                   ' __in_opt WCHAR *pszSRGS
 ) AS LONG                                                ' HRESULT


$IID_ITfInputScope    = GUID$("{FDE1EAEE-6924-4CDF-91E7-DA38CFF5559D}")
$IID_ITfInputScope2   = GUID$("{5731EAA0-6BC2-4681-A532-92FBB74D7C41}")
$GUID_PROP_INPUTSCOPE = GUID$("{1713DD5A-68E7-4A5B-9AF6-592A595C778D}")


' ########################################################################################
' ITfInputScope interface
' IID = FDE1EAEE-6924-4CDF-91E7-DA38CFF5559D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITfInputScope_INTERFACE_DEFINED)
    %ITfInputScope_INTERFACE_DEFINED = 1

INTERFACE ITfInputScope $IID_ITfInputScope

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetInputScopes ( _                            ' VTable offset = 12
     BYREF pprgInputScopes AS LONG _                    ' __out InputScope **pprgInputScopes
   , BYREF pcCount AS DWORD _                           ' __out UINT *pcCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPhrase ( _                                 ' VTable offset = 16
     BYREF ppbstrPhrases AS WSTRING _                   ' __out BSTR **ppbstrPhrases
   , BYREF pcCount AS DWORD _                           ' __out UINT *pcCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRegularExpression ( _                      ' VTable offset = 20
     BYREF pbstrRegExp AS WSTRING _                     ' __out BSTR *pbstrRegExp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSRGS ( _                                   ' VTable offset = 24
     BYREF pbstrSRGS AS WSTRING _                       ' __out BSTR *pbstrSRGS
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetXML ( _                                    ' VTable offset = 28
     BYREF pbstrXML AS WSTRING _                        ' __out BSTR *pbstrXML
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITfInputScope_INTERFACE_DEFINED__ */

' ########################################################################################
' ITfInputScope2 interface
' IID = 5731EAA0-6BC2-4681-A532-92FBB74D7C41
' Inherited interface = ITfInputScope
' ########################################################################################

#IF NOT %DEF(%ITfInputScope2_INTERFACE_DEFINED)
    %ITfInputScope2_INTERFACE_DEFINED = 1

INTERFACE ITfInputScope2 $IID_ITfInputScope2

   INHERIT IUnknown

   ' =====================================================================================
   ' ITfInputScope methods
   ' =====================================================================================
   METHOD GetInputScopes ( _                            ' VTable offset = 12
     BYREF pprgInputScopes AS LONG _                    ' __out InputScope **pprgInputScopes
   , BYREF pcCount AS DWORD _                           ' __out UINT *pcCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPhrase ( _                                 ' VTable offset = 16
     BYREF ppbstrPhrases AS WSTRING _                   ' __out BSTR **ppbstrPhrases
   , BYREF pcCount AS DWORD _                           ' __out UINT *pcCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRegularExpression ( _                      ' VTable offset = 20
     BYREF pbstrRegExp AS WSTRING _                     ' __out BSTR *pbstrRegExp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSRGS ( _                                   ' VTable offset = 24
     BYREF pbstrSRGS AS WSTRING _                       ' __out BSTR *pbstrSRGS
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetXML ( _                                    ' VTable offset = 28
     BYREF pbstrXML AS WSTRING _                        ' __out BSTR *pbstrXML
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ITfInputScope2 method
   ' =====================================================================================
   METHOD EnumWordList ( _                              ' VTable offset = 32
     BYREF ppEnumString AS IEnumString _                ' __out IEnumString **ppEnumString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITfInputScope_INTERFACE_DEFINED__ */

#ENDIF   ' // INPUTSCOPE_DEFINED
