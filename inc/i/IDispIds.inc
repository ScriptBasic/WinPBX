' ########################################################################################
' Microsoft Windows
' File: IDispIds.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IDISPIDS_INC = 1

%DISPID_READYSTATE                             = -525
%DISPID_READYSTATECHANGE                       = -609
%DISPID_AMBIENT_TRANSFERPRIORITY               = -728
%DISPID_AMBIENT_OFFLINEIFNOTCONNECTED          = -5501
%DISPID_AMBIENT_SILENT                         = -5502

'// Until these appear in OLECTL.H
#IF NOT %DEF(%DISPID_AMBIENT_CODEPAGE)
%DISPID_AMBIENT_CODEPAGE                       = -725
%DISPID_AMBIENT_CHARSET                        = -727
#ENDIF
