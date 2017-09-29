' ########################################################################################
' Microsoft Windows
' File: AMParse.inc
' Contents: Interface to the parser to get current time.  This is useful for multifile playback.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AMPARSE_INC = 1

' ########################################################################################
' Interface name = IAMParse
' Parser interface - supported by MPEG-2 splitter filter
' IID = {C47A3420-005C-11D2-9038-00A0C9697298}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IAMParse = GUID$("{C47A3420-005C-11D2-9038-00A0C9697298}")

INTERFACE IAMParse $IID_IAMParse

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetParseTime ( _                              ' VTable offset = 12
     BYREF prtCurrent AS QUAD _                         ' __out REFERENCE_TIME *prtCurrent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetParseTime ( _                              ' VTable offset = 16
     BYVAL rtCurrent AS QUAD _                          ' __in REFERENCE_TIME rtCurrent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Flush (        _                              ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE
