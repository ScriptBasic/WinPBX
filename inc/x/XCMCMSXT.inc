' ########################################################################################
' Microsoft Windows
' File: XCMCMSXT.inc
' Contents: Specifies constants and data structures for Microsoft CMC extension set
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%XCMCMSXT_INC = 1

'/***********************************************************************
' Warning: Value for MS_EXT_SET_ID has not been finalized yet.
' ***********************************************************************/
%MS_EXT_SET_ID                   = 512???

%CMC_XS_MS                       = %MS_EXT_SET_ID

'/*** FUNCTION EXTENSIONS ***/

'/* Describes extra flags used for logging on/off a session */
%CMC_X_MS_SESSION_FLAGS          = %MS_EXT_SET_ID + 16???
%CMC_X_MS_NEW_SESSION            = 1???
%CMC_X_MS_FORCE_DOWNLOAD         = 4???

'/* Flags used by various functions */
%CMC_X_MS_FUNCTION_FLAGS         = %MS_EXT_SET_ID + 17???
%CMC_X_MS_READ_ENV_ONLY          = 1???
%CMC_X_MS_READ_BODY_AS_FILE      = 2???
%CMC_X_MS_LIST_GUARANTEE_FIFO    = 4???
%CMC_X_MS_AB_NO_MODIFY           = 8???

'/* Extra options when displaying the Address Book UI */
%CMC_X_MS_ADDRESS_UI             = %MS_EXT_SET_ID + 18???

'/*** DATA EXTENSIONS ***/

'/* Extra flags for attachments */
%CMC_X_MS_ATTACH_DATA            = %MS_EXT_SET_ID + 128???
%CMC_X_MS_ATTACH_OLE             = 1???
%CMC_X_MS_ATTACH_OLE_STATIC      = 2???

'/* Extra data for messages */
%CMC_X_MS_MESSAGE_DATA           = %MS_EXT_SET_ID + 129???
%CMC_X_MS_MSG_RECEIPT_REQ        = 1???
