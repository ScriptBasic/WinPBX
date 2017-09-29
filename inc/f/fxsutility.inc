' ########################################################################################
' Microsoft Windows
' File: fxsutility.inc
' Contents: Prototypes for "Send to Fax Recipient" functionality.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%FXSUTILITY_INC = 1

' enum SendToMode
%SEND_TO_FAX_RECIPIENT_ATTACHMENT = 0

DECLARE FUNCTION CanSendToFaxRecipient IMPORT "fxsutility.dll" ALIAS "CanSendToFaxRecipient" ( _
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SendToFaxRecipient IMPORT "fxsutility.dll" ALIAS "SendToFaxRecipient" ( _
   BYVAL sndMode AS LONG _                              ' __in SendToMode sndMode
 , BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 ) AS DWORD                                             ' DWORD
