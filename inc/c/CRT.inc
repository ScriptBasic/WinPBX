' ########################################################################################
' Microsoft C Runtime
' File: CRT.inc
' Contents: Microsoft C Runtime files.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CRT_INC = 1

' // Default version is msvcrt.dll. To use the visual studio versions, define
' // %CRT_VERSION = <number vetween 6 and 10>".
' // msvcr80.dll, msvcr90.dll and msvcr100.dll require the use of a manifest.

#INCLUDE ONCE "crtdefs.inc"
#INCLUDE ONCE "ctype.inc"
#INCLUDE ONCE "errno.inc"
#INCLUDE ONCE "limits.inc"
#INCLUDE ONCE "excpt.inc"
#INCLUDE ONCE "fcntl.inc"
#INCLUDE ONCE "locale.inc"
#INCLUDE ONCE "malloc.inc"
#INCLUDE ONCE "memory.inc"
#INCLUDE ONCE "string.inc"
#INCLUDE ONCE "float.inc"
#INCLUDE ONCE "math.inc"
#INCLUDE ONCE "io.inc"
#INCLUDE ONCE "direct.inc"
#INCLUDE ONCE "stdio.inc"
#INCLUDE ONCE "stdlib.inc"
#INCLUDE ONCE "search.inc"
#INCLUDE ONCE "conio.inc"
#INCLUDE ONCE "time.inc"
#INCLUDE ONCE "timeb.inc"
#INCLUDE ONCE "utime.inc"
