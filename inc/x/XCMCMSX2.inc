' ########################################################################################
' Microsoft Windows
' File: XCMCMSX2.inc
' Contents: Specifies constants and data structures for Microsoft CMC extensions set
' update (forms extensions)
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%XCMCMSX2_INC = 1

#INCLUDE ONCE "xcmc.inc"
#INCLUDE ONCE "xcmcmsxt.inc"
#INCLUDE ONCE "mapidefs.inc"

'/* Get an extended MAPI session from a CMC session */

#IF %DEF(%MAPIX_INC)
DECLARE FUNCTION ScMAPIXFromCMC IMPORT "MAPI32.DLL" ALIAS "ScMAPIXFromCMC" ( _
   BYVAL cmcsession AS DWORD _                          ' __in  CMC_SESSION cmcsession
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG ulFlags
 , BYREF lpInterface AS GUID _                          ' __in  LPCIID lpInterface
 , BYREF lppMAPISession AS IMAPISession _               ' __out LPMAPISESSION FAR * lppMAPISession
 ) AS LONG                                              ' SCODE
#ENDIF   ' /* MAPIX_H */

'/* Extra flag for CMC_X_MS_ATTACH_DATA */
'#define CMC_X_MS_ATTACH_MESSAGE         ((CMC_flags) 4)
%CMC_X_MS_ATTACH_MESSAGE = 4???

'/* Attachment descriptor for CMC_X_ATTACH_DATA */
' // Size = 12 bytes
TYPE CMC_X_MS_ATTACH DWORD
   message AS CMC_message_reference PTR   ' CMC_message_reference FAR *message
   id      AS DWORD                       ' CMC_uint32
   object  AS DWORD                       ' CMC_buffer
END TYPE
