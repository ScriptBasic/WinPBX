' ########################################################################################
' Microsoft Windows
' File: XCMCExt.inc
' Contents: Specifies constants and data structures for CMC Common extensions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%XCMCEXT_INC = 1

'/* COMMON EXTENSIONS DECLARATIONS */

%CMC_XS_COM                  = 0???

'/* FUNCTION EXTENSIONS */

'/* Query for extension support in implementation */
%CMC_X_COM_SUPPORT_EXT       = 16???

' // Size = 8 bytes
TYPE CMC_X_COM_support DWORD
   item_code AS DWORD   ' CMC_uint32
   flags     AS DWORD   ' CMC_flags
END TYPE

%CMC_X_COM_SUPPORTED             = 1???
%CMC_X_COM_NOT_SUPPORTED         = 2???
%CMC_X_COM_DATA_EXT_SUPPORTED    = 4???
%CMC_X_COM_FUNC_EXT_SUPPORTED    = 8???
%CMC_X_COM_SUP_EXCLUDE           = 16???

'/* Get back a structure with configuration data */

%CMC_X_COM_CONFIG_DATA           = 17???

' // Size = 40 bytes
TYPE CMC_X_COM_configuration BYTE
   ver_spec        AS WORD         ' CMC_uint16
   ver_implem      AS WORD         ' CMC_uint16
   character_set   AS ASCIIZ PTR   ' CMC_object_identifier FAR *
   line_term       AS LONG         ' CMC_enum
   default_service AS ASCIIZ PTR   ' CMC_string
   default_user    AS ASCIIZ PTR   ' CMC_string
   req_password    AS LONG         ' CMC_enum
   req_service     AS LONG         ' CMC_enum
   req_user        AS LONG         ' CMC_enum
   ui_avail        AS WORD         ' CMC_boolean
   sup_nomkmsgread AS WORD         ' CMC_boolean
   sup_counted_str AS WORD         ' CMC_boolean
   alignment__     AS WORD         ' // To keep DWORD alignment
END TYPE


'/* Check to see if/when a recipient can be sent */
%CMC_X_COM_CAN_SEND_RECIP    = 18???

%CMC_X_COM_READY             = 0&
%CMC_X_COM_NOT_READY         = 1&
%CMC_X_COM_DEFER             = 2&

'/* Save a message to the inbox */

%CMC_X_COM_SAVE_MESSAGE      = 19???

'/* Get back a message structure for the message just sent */

%CMC_X_COM_SENT_MESSAGE      = 20???

'/* DATA EXTENSIONS */

'/* attach a receive date to message and message summary structures */
%CMC_X_COM_TIME_RECEIVED     = 128???

'/* attach a unique id to resolved recipient structures */
%CMC_X_COM_RECIP_ID          = 129???

'/* set character position in the message text to display an icon
'   associated with a particular attachment */

%CMC_X_COM_ATTACH_CHARPOS    = 130???

%CMC_X_COM_PRIORITY          = 131???

%CMC_X_COM_NORMAL            = 0&
%CMC_X_COM_URGENT            = 1&
%CMC_X_COM_LOW               = 2&
