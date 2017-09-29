' ########################################################################################
' Microsoft Windows
' File: locking.inc
' Contents: This file defines the flags for the locking() function.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%LOCKING = 1

%LK_UNLCK  = 0   ' /* unlock the file region */
%LK_LOCK   = 1   ' /* lock the file region */
%LK_NBLCK  = 2   ' /* non-blocking lock */
%LK_RLCK   = 3   ' /* lock for writing */
%LK_NBRLCK = 4   ' /* non-blocking lock for writing */
