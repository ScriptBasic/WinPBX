' ########################################################################################
' Microsoft Windows
' File: LMUseFlg.inc
' Contents: This file contains deletion force levels for deleting a connection
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%LMUSEFLG_INC = 1

'//
'// Definition for NetWkstaTransportDel and NetUseDel deletion force levels
'//

%USE_NOFORCE       = 0
%USE_FORCE         = 1
%USE_LOTS_OF_FORCE = 2
