' ########################################################################################
' Microsoft C Runtime
' File: excpt.inc
' Contents: This file contains the definitions and prototypes for the compiler-dependent
' intrinsics, support functions and keywords which implement the structured exception
' handling extensions.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%EXCPT_INC = 1

#INCLUDE ONCE "crtdefs.inc"

'/*
' * Exception disposition return values.
' */

ENUM EXCEPTION_DISPOSITION SINGULAR
   ExceptionContinueExecution = 0
   ExceptionContinueSearch
   ExceptionNestedException
   ExceptionCollidedUnwind
END ENUM

'/*
' * Legal values for expression in except().
' */

%EXCEPTION_EXECUTE_HANDLER    = 1
%EXCEPTION_CONTINUE_SEARCH    = 0
%EXCEPTION_CONTINUE_EXECUTION = -1
