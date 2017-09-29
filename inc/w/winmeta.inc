' ########################################################################################
' Microsoft Windows
' File: winmeta.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINMETA_INC = 1

%WINEVENT_CHANNEL_CLASSIC_TRACE      = &H0
%WINEVENT_CHANNEL_GLOBAL_SYSTEM      = &H8
%WINEVENT_CHANNEL_GLOBAL_APPLICATION = &H9
%WINEVENT_CHANNEL_GLOBAL_SECURITY    = &Ha
%WINEVENT_LEVEL_LOG_ALWAYS           = &H0
%WINEVENT_LEVEL_CRITICAL             = &H1
%WINEVENT_LEVEL_ERROR                = &H2
%WINEVENT_LEVEL_WARNING              = &H3
%WINEVENT_LEVEL_INFO                 = &H4
%WINEVENT_LEVEL_VERBOSE              = &H5
%WINEVENT_LEVEL_RESERVED_6           = &H6
%WINEVENT_LEVEL_RESERVED_7           = &H7
%WINEVENT_LEVEL_RESERVED_8           = &H8
%WINEVENT_LEVEL_RESERVED_9           = &H9
%WINEVENT_LEVEL_RESERVED_10          = &Ha
%WINEVENT_LEVEL_RESERVED_11          = &Hb
%WINEVENT_LEVEL_RESERVED_12          = &Hc
%WINEVENT_LEVEL_RESERVED_13          = &Hd
%WINEVENT_LEVEL_RESERVED_14          = &He
%WINEVENT_LEVEL_RESERVED_15          = &Hf
%WINEVENT_OPCODE_INFO                = &H0
%WINEVENT_OPCODE_START               = &H1
%WINEVENT_OPCODE_STOP                = &H2
%WINEVENT_OPCODE_DC_START            = &H3
%WINEVENT_OPCODE_DC_STOP             = &H4
%WINEVENT_OPCODE_EXTENSION           = &H5
%WINEVENT_OPCODE_REPLY               = &H6
%WINEVENT_OPCODE_RESUME              = &H7
%WINEVENT_OPCODE_SUSPEND             = &H8
%WINEVENT_OPCODE_SEND                = &H9
%WINEVENT_OPCODE_RECEIVE             = &Hf0
%WINEVENT_OPCODE_RESERVED_241        = &Hf1
%WINEVENT_OPCODE_RESERVED_242        = &Hf2
%WINEVENT_OPCODE_RESERVED_243        = &Hf3
%WINEVENT_OPCODE_RESERVED_244        = &Hf4
%WINEVENT_OPCODE_RESERVED_245        = &Hf5
%WINEVENT_OPCODE_RESERVED_246        = &Hf6
%WINEVENT_OPCODE_RESERVED_247        = &Hf7
%WINEVENT_OPCODE_RESERVED_248        = &Hf8
%WINEVENT_OPCODE_RESERVED_249        = &Hf9
%WINEVENT_OPCODE_RESERVED_250        = &Hfa
%WINEVENT_OPCODE_RESERVED_251        = &Hfb
%WINEVENT_OPCODE_RESERVED_252        = &Hfc
%WINEVENT_OPCODE_RESERVED_253        = &Hfd
%WINEVENT_OPCODE_RESERVED_254        = &Hfe
%WINEVENT_OPCODE_RESERVED_255        = &Hff
%WINEVENT_TASK_NONE                  = &H0
%WINEVT_KEYWORD_ANY                  = &H0
%WINEVENT_KEYWORD_RESPONSE_TIME      = &H1000000000000
%WINEVENT_KEYWORD_WDI_CONTEXT        = &H2000000000000
%WINEVENT_KEYWORD_WDI_DIAG           = &H4000000000000
%WINEVENT_KEYWORD_SQM                = &H8000000000000
%WINEVENT_KEYWORD_AUDIT_FAILURE      = &H10000000000000
%WINEVENT_KEYWORD_AUDIT_SUCCESS      = &H20000000000000
%WINEVENT_KEYWORD_CORRELATION_HINT   = &H40000000000000
%WINEVENT_KEYWORD_EVENTLOG_CLASSIC   = &H80000000000000
%WINEVENT_KEYWORD_RESERVED_56        = &H100000000000000
%WINEVENT_KEYWORD_RESERVED_57        = &H200000000000000
%WINEVENT_KEYWORD_RESERVED_58        = &H400000000000000
%WINEVENT_KEYWORD_RESERVED_59        = &H800000000000000
%WINEVENT_KEYWORDE_RESERVED_60       = &H1000000000000000
%WINEVENT_KEYWORD_RESERVED_61        = &H2000000000000000
%WINEVENT_KEYWORD_RESERVED_62        = &H4000000000000000
%WINEVENT_KEYWORD_RESERVED_63        = &H8000000000000000

%MSG_category_Devices             = &H00000001&
%MSG_category_Disk                = &H00000002&
%MSG_category_Network             = &H00000007&
%MSG_category_Printers            = &H00000003&
%MSG_category_Services            = &H00000004&
%MSG_category_Shell               = &H00000005&
%MSG_category_SystemEvent         = &H00000006&
%MSG_channel_Application          = &H00000100&
%MSG_channel_Security             = &H00000101&
%MSG_channel_System               = &H00000102&
%MSG_channel_TraceClassic         = &H90000001&
%MSG_keyword_AnyKeyword           = &H10000000&
%MSG_keyword_AuditFailure         = &H10000035&
%MSG_keyword_AuditSuccess         = &H10000036&
%MSG_keyword_Classic              = &H10000038&
%MSG_keyword_CorrelationHint      = &H10000037&
%MSG_keyword_ResponseTime         = &H10000031&
%MSG_keyword_SQM                  = &H10000034&
%MSG_keyword_WDIContext           = &H10000032&
%MSG_keyword_WDIDiag              = &H10000033&
%MSG_level_Critical               = &H50000001&
%MSG_level_Error                  = &H50000002&
%MSG_level_Informational          = &H50000004&
%MSG_level_LogAlways              = &H50000000&
%MSG_level_Verbose                = &H50000005&
%MSG_level_Warning                = &H50000003&
%MSG_opcode_DCStart               = &H30030000&
%MSG_opcode_DCStop                = &H30040000&
%MSG_opcode_Extension             = &H30050000&
%MSG_opcode_Info                  = &H30000000&
%MSG_opcode_Receive               = &H30F00000&
%MSG_opcode_Reply                 = &H30060000&
%MSG_opcode_Resume                = &H30070000&
%MSG_opcode_Send                  = &H30090000&
%MSG_opcode_Start                 = &H30010000&
%MSG_opcode_Stop                  = &H30020000&
%MSG_opcode_Suspend               = &H30080000&
%MSG_task_None                    = &H70000000&
