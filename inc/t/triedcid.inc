' ########################################################################################
' Microsoft Windows
' File: triedcid.inc
' Copyright (c) 2011 José Roca
' Contents: Command IDs for TriEdit's IOleCommandTarget
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TRIEDCID_INC = 1

'// GUID_TriEditCommandGroup {2582F1C0-084E-11d1-9A0E-006097C9B344}

%IDM_TRIED_NUDGE_ELEMENT            =  2  ' //[in,VT_BYREF VARIANT.byref=LPPOINT]
%IDM_TRIED_SET_ALIGNMENT            =  3  ' //[in,VT_BYREF VARIANT.byref=LPPOINT]
%IDM_TRIED_MAKE_ABSOLUTE            =  4
%IDM_TRIED_LOCK_ELEMENT             =  5
%IDM_TRIED_SEND_TO_BACK             =  6
%IDM_TRIED_BRING_TO_FRONT           =  7
%IDM_TRIED_SEND_BACKWARD            =  8
%IDM_TRIED_BRING_FORWARD            =  9
%IDM_TRIED_SEND_BELOW_TEXT          = 10
%IDM_TRIED_BRING_ABOVE_TEXT         = 11
%IDM_TRIED_CONSTRAIN                = 12  ' //[in,VT_BOOL]
%IDM_TRIED_ABSOLUTE_DROP_MODE       = 13  ' //[in,VT_BOOL]
%IDM_TRIED_INSERTROW                = 14
%IDM_TRIED_INSERTCOL                = 15
%IDM_TRIED_DELETEROWS               = 16
%IDM_TRIED_DELETECOLS               = 17
%IDM_TRIED_MERGECELLS               = 18
%IDM_TRIED_SPLITCELL                = 19
%IDM_TRIED_INSERTCELL               = 20
%IDM_TRIED_DELETECELLS              = 21
%IDM_TRIED_INSERTTABLE              = 22  ' //[in, VT_ARRAY]
%IDM_TRIED_ACTIVATEACTIVEXCONTROLS  = 23
%IDM_TRIED_ACTIVATEAPPLETS          = 24
%IDM_TRIED_ACTIVATEDTCS             = 25
%IDM_TRIED_BACKCOLOR                = 26
%IDM_TRIED_BLOCKFMT                 = 27
%IDM_TRIED_BOLD                     = 28
%IDM_TRIED_BROWSEMODE               = 29
%IDM_TRIED_COPY                     = 30
%IDM_TRIED_CUT                      = 31
%IDM_TRIED_DELETE                   = 32
%IDM_TRIED_EDITMODE                 = 33
%IDM_TRIED_FIND                     = 34
%IDM_TRIED_FONT                     = 35
%IDM_TRIED_FONTNAME                 = 36
%IDM_TRIED_FONTSIZE                 = 37
%IDM_TRIED_FORECOLOR                = 38
%IDM_TRIED_GETBLOCKFMTS             = 39
%IDM_TRIED_HYPERLINK                = 40
%IDM_TRIED_IMAGE                    = 41
%IDM_TRIED_INDENT                   = 42
%IDM_TRIED_ITALIC                   = 43
%IDM_TRIED_JUSTIFYCENTER            = 44
%IDM_TRIED_JUSTIFYLEFT              = 45
%IDM_TRIED_JUSTIFYRIGHT             = 46
%IDM_TRIED_ORDERLIST                = 47
%IDM_TRIED_OUTDENT                  = 48
%IDM_TRIED_PASTE                    = 50
%IDM_TRIED_PRINT                    = 51
%IDM_TRIED_REDO                     = 52
%IDM_TRIED_REMOVEFORMAT             = 53
%IDM_TRIED_SELECTALL                = 54
%IDM_TRIED_SHOWBORDERS              = 55
%IDM_TRIED_SHOWDETAILS              = 56
%IDM_TRIED_UNDERLINE                = 57
%IDM_TRIED_UNDO                     = 58
%IDM_TRIED_UNLINK                   = 59
%IDM_TRIED_UNORDERLIST              = 60
%IDM_TRIED_DOVERB                   = 61

'//WARNING WARNING WARNING!!! Don't forget to modify IDM_TRIED_LAST_CID
'//when you add new Command IDs

%IDM_TRIED_LAST_CID             = %IDM_TRIED_DOVERB

'//These are old command IDs that are here for backward compatibility
'//We don't recommend using these any more
%IDM_TRIED_IS_1D_ELEMENT         = 0  ' //[out,VT_BOOL]
%IDM_TRIED_IS_2D_ELEMENT         = 1  ' //[out,VT_BOOL]
%IDM_TRIED_SEND_TO_FRONT         = %IDM_TRIED_BRING_TO_FRONT
%IDM_TRIED_SEND_FORWARD          = %IDM_TRIED_BRING_FORWARD
%IDM_TRIED_SEND_BEHIND_1D        = %IDM_TRIED_SEND_BELOW_TEXT
%IDM_TRIED_SEND_FRONT_1D         = %IDM_TRIED_BRING_ABOVE_TEXT
%IDM_TRIED_SET_2D_DROP_MODE      = %IDM_TRIED_ABSOLUTE_DROP_MODE
