' ########################################################################################
' Microsoft Windows
' File: RegExp.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: VBScript_RegExp_55
' Version: 5.5
' Documentation string: Microsoft VBScript Regular Expressions 5.5
' Path: C:\WINDOWS\system32\vbscript.dll\3
' Library GUID: {3F4DACA7-160D-11D2-A8E9-00104B365C9F}
' ########################################################################################

#INCLUDE THIS ONCE
%REGEXP_INC = 1

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {3F4DACA4-160D-11D2-A8E9-00104B365C9F}
$PROGID_VBScriptRegExp = "VBScript.RegExp"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_Match = GUID$("{3F4DACA5-160D-11D2-A8E9-00104B365C9F}")
$CLSID_MatchCollection = GUID$("{3F4DACA6-160D-11D2-A8E9-00104B365C9F}")
$CLSID_SubMatches = GUID$("{3F4DACC0-160D-11D2-A8E9-00104B365C9F}")
$CLSID_RegExp = GUID$("{3F4DACA4-160D-11D2-A8E9-00104B365C9F}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IMatch = GUID$("{3F4DACA1-160D-11D2-A8E9-00104B365C9F}")
$IID_IMatch2 = GUID$("{3F4DACB1-160D-11D2-A8E9-00104B365C9F}")
$IID_IMatchCollection = GUID$("{3F4DACA2-160D-11D2-A8E9-00104B365C9F}")
$IID_IMatchCollection2 = GUID$("{3F4DACB2-160D-11D2-A8E9-00104B365C9F}")
$IID_IRegExp = GUID$("{3F4DACA0-160D-11D2-A8E9-00104B365C9F}")
$IID_IRegExp2 = GUID$("{3F4DACB0-160D-11D2-A8E9-00104B365C9F}")
$IID_ISubMatches = GUID$("{3F4DACB3-160D-11D2-A8E9-00104B365C9F}")

' ########################################################################################
' Interface name = IRegExp
' IID = {3F4DACA0-160D-11D2-A8E9-00104B365C9F}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRegExp_INTERFACE_DEFINED)
    %IRegExp_INTERFACE_DEFINED = 1

INTERFACE IRegExp $IID_IRegExp

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Pattern <10001> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pPattern
   ' =====================================================================================
   PROPERTY SET Pattern <10001> ( _                     ' VTable offset = 32
     BYVAL pPattern AS WSTRING _                        ' __in BSTR pPattern
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IgnoreCase <10002> ( _                  ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pIgnoreCase
   ' =====================================================================================
   PROPERTY SET IgnoreCase <10002> ( _                  ' VTable offset = 40
     BYVAL pIgnoreCase AS INTEGER _                     ' __in VARIANT_BOOL pIgnoreCase
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Global <10003> ( _                      ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pGlobal
   ' =====================================================================================
   PROPERTY SET Global <10003> ( _                      ' VTable offset = 48
     BYVAL pGlobal AS INTEGER _                         ' __in VARIANT_BOOL pGlobal
   )                                                    ' void
   ' =====================================================================================
   METHOD Execute <10004> ( _                           ' VTable offset = 52
     BYVAL sourceString AS WSTRING _                    ' __in BSTR sourceString
   ) AS IDispatch                                       ' __retval_out IDispatch** ppMatches
   ' =====================================================================================
   METHOD Test <10005> ( _                              ' VTable offset = 56
     BYVAL sourceString AS WSTRING _                    ' __in BSTR sourceString
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pMatch
   ' =====================================================================================
   METHOD Replace <10006> ( _                           ' VTable offset = 60
     BYVAL sourceString AS WSTRING _                    ' __in BSTR sourceString
   , BYVAL replaceString AS WSTRING _                   ' __in BSTR replaceString
   ) AS WSTRING                                         ' __retval_out BSTR* pDestString
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRegExp_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMatch
' IID = {3F4DACA1-160D-11D2-A8E9-00104B365C9F}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMatch_INTERFACE_DEFINED)
    %IMatch_INTERFACE_DEFINED = 1

INTERFACE IMatch $IID_IMatch

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pValue
   ' =====================================================================================
   PROPERTY GET FirstIndex <10001> ( _                  ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pFirstIndex
   ' =====================================================================================
   PROPERTY GET Length <10002> ( _                      ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long* pLength
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMatch_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMatchCollection
' IID = {3F4DACA2-160D-11D2-A8E9-00104B365C9F}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMatchCollection_INTERFACE_DEFINED)
    %IMatchCollection_INTERFACE_DEFINED = 1

INTERFACE IMatchCollection $IID_IMatchCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <10001> ( _                        ' VTable offset = 28
     BYVAL index AS LONG _                              ' __in long index
   ) AS IDispatch                                       ' __retval_out IDispatch** ppMatch
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMatchCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRegExp2
' IID = {3F4DACB0-160D-11D2-A8E9-00104B365C9F}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRegExp2_INTERFACE_DEFINED)
    %IRegExp2_INTERFACE_DEFINED = 1

INTERFACE IRegExp2 $IID_IRegExp2

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Pattern <10001> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pPattern
   ' =====================================================================================
   PROPERTY SET Pattern <10001> ( _                     ' VTable offset = 32
     BYVAL pPattern AS WSTRING _                        ' __in BSTR pPattern
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IgnoreCase <10002> ( _                  ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pIgnoreCase
   ' =====================================================================================
   PROPERTY SET IgnoreCase <10002> ( _                  ' VTable offset = 40
     BYVAL pIgnoreCase AS INTEGER _                     ' __in VARIANT_BOOL pIgnoreCase
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Global <10003> ( _                      ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pGlobal
   ' =====================================================================================
   PROPERTY SET Global <10003> ( _                      ' VTable offset = 48
     BYVAL pGlobal AS INTEGER _                         ' __in VARIANT_BOOL pGlobal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Multiline <10007> ( _                   ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pMultiline
   ' =====================================================================================
   PROPERTY SET Multiline <10007> ( _                   ' VTable offset = 56
     BYVAL pMultiline AS INTEGER _                      ' __in VARIANT_BOOL pMultiline
   )                                                    ' void
   ' =====================================================================================
   METHOD Execute <10004> ( _                           ' VTable offset = 60
     BYVAL sourceString AS WSTRING _                    ' __in BSTR sourceString
   ) AS IDispatch                                       ' __retval_out IDispatch** ppMatches
   ' =====================================================================================
   METHOD Test <10005> ( _                              ' VTable offset = 64
     BYVAL sourceString AS WSTRING _                    ' __in BSTR sourceString
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pMatch
   ' =====================================================================================
   METHOD Replace <10006> ( _                           ' VTable offset = 68
     BYVAL sourceString AS WSTRING _                    ' __in BSTR sourceString
   , BYVAL replaceVar AS VARIANT _                      ' __in VARIANT replaceVar
   ) AS WSTRING                                         ' __retval_out BSTR* pDestString
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRegExp2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMatch2
' IID = {3F4DACB1-160D-11D2-A8E9-00104B365C9F}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMatch2_INTERFACE_DEFINED)
    %IMatch2_INTERFACE_DEFINED = 1

INTERFACE IMatch2 $IID_IMatch2

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pValue
   ' =====================================================================================
   PROPERTY GET FirstIndex <10001> ( _                  ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pFirstIndex
   ' =====================================================================================
   PROPERTY GET Length <10002> ( _                      ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long* pLength
   ' =====================================================================================
   PROPERTY GET SubMatches <10003> ( _                  ' VTable offset = 40
   ) AS IDispatch                                       ' __retval_out IDispatch** ppSubMatches
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMatch2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMatchCollection2
' IID = {3F4DACB2-160D-11D2-A8E9-00104B365C9F}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMatchCollection2_INTERFACE_DEFINED)
    %IMatchCollection2_INTERFACE_DEFINED = 1

INTERFACE IMatchCollection2 $IID_IMatchCollection2

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL index AS LONG _                              ' __in long index
   ) AS IDispatch                                       ' __retval_out IDispatch** ppMatch
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMatchCollection2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISubMatches
' IID = {3F4DACB3-160D-11D2-A8E9-00104B365C9F}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISubMatches_INTERFACE_DEFINED)
    %ISubMatches_INTERFACE_DEFINED = 1

INTERFACE ISubMatches $IID_ISubMatches

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL index AS LONG _                              ' __in long index
   ) AS VARIANT                                         ' __retval_out VARIANT* pSubMatch
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISubMatches_INTERFACE_DEFINED__ */
