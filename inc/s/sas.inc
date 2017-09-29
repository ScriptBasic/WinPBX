' ########################################################################################
' Microsoft Windows
' File: sas.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SAS_INC = 1

'#pragma once

'#ifdef __cplusplus
'extern "C"
'{
'#endif

'VOID
'WINAPI
'SendSAS(
'    __in BOOL AsUser );

DECLARE SUB SendSAS IMPORT "Sas.dll" ALIAS "SendSAS" ( _
   BYVAL AsUser AS LONG _                               ' __in BOOL AsUser
 )                                                      ' VOID

'#ifdef __cplusplus
'}
'#endif
