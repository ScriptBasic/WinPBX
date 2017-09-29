' ########################################################################################
' Microsoft C Runtime
' File: fcntl.inc
' Contents: Constants for the file control options used by the _open() function.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%FCNTL_INC = 1

#INCLUDE ONCE "crtdefs.inc"

%O_RDONLY       = &H0000&  ' /* open for reading only */
%O_WRONLY       = &H0001&  ' /* open for writing only */
%O_RDWR         = &H0002&  ' /* open for reading and writing */
%O_APPEND       = &H0008&  ' /* writes done at eof */

%O_CREAT        = &H0100&  ' /* create and open file */
%O_TRUNC        = &H0200&  ' /* open and truncate */
%O_EXCL         = &H0400&  ' /* open only if file doesn't already exist */

'/* O_TEXT files have <cr><lf> sequences translated to <lf> on read()'s,
'** and <lf> sequences translated to <cr><lf> on write()'s
'*/

%O_TEXT         = &H4000&    ' /* file mode is text (translated) */
%O_BINARY       = &H8000&    ' /* file mode is binary (untranslated) */
%O_WTEXT        = &H10000&   ' /* file mode is UTF16 (translated) */
%O_U16TEXT      = &H20000&   ' /* file mode is UTF16 no BOM (translated) */
%O_U8TEXT       = &H40000&   ' /* file mode is UTF8  no BOM (translated) */

'/* macro to translate the C 2.0 name used to force binary mode for files */

%O_RAW          = %O_BINARY

'/* Open handle inherit bit */

%O_NOINHERIT    = &H0080&  ' /* child process doesn't inherit file */

'/* Temporary file bit - file is deleted when last handle is closed */

%O_TEMPORARY    = &H0040&  ' /* temporary file bit */

'/* temporary access hint */

%O_SHORT_LIVED  = &H1000&  ' /* temporary storage file, try not to flush */

'/* sequential/random access hints */

%O_SEQUENTIAL   = &H0020&  ' /* file access is primarily sequential */
%O_RANDOM       = &H0010&  ' /* file access is primarily random */
