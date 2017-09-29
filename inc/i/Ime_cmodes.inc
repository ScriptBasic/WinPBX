' ########################################################################################
' Microsoft Windows
' File: Ime_cmodes.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IME_CMODES_INC = 1

'// bit field for conversion mode
%IME_CMODE_ALPHANUMERIC   = &H0000???
%IME_CMODE_NATIVE         = &H0001???
%IME_CMODE_CHINESE        = %IME_CMODE_NATIVE
%IME_CMODE_HANGUL         = %IME_CMODE_NATIVE
%IME_CMODE_JAPANESE       = %IME_CMODE_NATIVE
%IME_CMODE_KATAKANA       = &H0002???
%IME_CMODE_LANGUAGE       = &H0003???
%IME_CMODE_FULLSHAPE      = &H0008???
%IME_CMODE_ROMAN          = &H0010???
%IME_CMODE_CHARCODE       = &H0020???
%IME_CMODE_HANJACONVERT   = &H0040???
