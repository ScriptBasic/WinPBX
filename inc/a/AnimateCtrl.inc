' ########################################################################################
' Microsoft Windows
' File: AnimateCtrl.inc
' Contents: Animation Control Wrapper Functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ANIMATECTRL_INC = 1

#INCLUDE ONCE "commctrl.inc"

' ========================================================================================
' Closes an AVI clip.
' ========================================================================================
FUNCTION Animate_Close (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = Animate_Open(hwnd, BYVAL %NULL)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates an animation control.
' ========================================================================================
FUNCTION Animate_Create (BYVAL hWndP AS DWORD, BYVAL id AS DWORD, BYVAL dwStyle AS DWORD, BYVAL hInstance AS DWORD) AS DWORD
   FUNCTION = CreateWindow("SysAnimate32", BYVAL %NULL, dwStyle, 0, 0, 0, 0, hWndP, id, hInstance, BYVAL %NULL)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates an animation control.
' ========================================================================================
FUNCTION Animate_IsPlaying (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %ACM_ISPLAYING, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Opens an AVI clip and displays its first frame in an animation control.
' ========================================================================================
FUNCTION Animate_OpenA (BYVAL hwnd AS DWORD, BYREF szName AS ASCIIZ) AS LONG
   FUNCTION = SendMessageA(hwnd, %ACM_OPENA, 0, VARPTR(szName))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION Animate_OpenW (BYVAL hwnd AS DWORD, BYREF wszName AS WSTRINGZ) AS LONG
   FUNCTION = SendMessageW(hwnd, %ACM_OPENW, 0, VARPTR(wszName))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Animate_Open = Animate_OpenW
#ELSE
   MACRO Animate_Open = Animate_OpenA
#ENDIF

' ========================================================================================
' Opens an AVI clip from a resource in a specified module and displays its first frame in
' an animation control.
' ========================================================================================
FUNCTION Animate_OpenExA (BYVAL hwnd AS DWORD, BYVAL hInst AS DWORD, BYREF szName AS ASCIIZ) AS LONG
   FUNCTION = SendMessageA(hwnd, %ACM_OPENA, hInst, VARPTR(szName))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION Animate_OpenExW (BYVAL hwnd AS DWORD, BYVAL hInst AS DWORD, BYREF wszName AS WSTRINGZ) AS LONG
   FUNCTION = SendMessageW(hwnd, %ACM_OPENW, hInst, VARPTR(wszName))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Animate_OpenEx = Animate_OpenExW
#ELSE
   MACRO Animate_OpenEx = Animate_OpenExA
#ENDIF

' ========================================================================================
' Plays an AVI clip in an animation control. The control plays the clip in the background
' while the thread continues executing.
' ========================================================================================
FUNCTION Animate_Play (BYVAL hwnd AS DWORD, BYVAL nFrom AS DWORD, BYVAL nTo AS DWORD, BYVAL rep AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %ACM_PLAY, rep, MAK(LONG, nFrom, nTo))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Directs an animation control to display a particular frame of an AVI clip. The control
' displays the clip in the background while the thread continues executing.
' ========================================================================================
FUNCTION Animate_Seek (BYVAL hwnd AS DWORD, BYVAL nFrame AS LONG) AS LONG
   FUNCTION = Animate_Play(hwnd, nFrame, nFrame, 1)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Stops playing an AVI clip in an animation control.
' ========================================================================================
FUNCTION Animate_Stop (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %ACM_STOP, 0, 0)
END FUNCTION
' ========================================================================================
