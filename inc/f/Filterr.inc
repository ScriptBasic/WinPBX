' ########################################################################################
' Microsoft Windows
' File: Filterr.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%FILTERR_INC = 1

#IF NOT %DEF(%FACILITY_WINDOWS)
'//
'//  Values are 32 bit values laid out as follows:
'//
'//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
'//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
'//  +---+-+-+-----------------------+-------------------------------+
'//  |Sev|C|R|     Facility          |               Code            |
'//  +---+-+-+-----------------------+-------------------------------+
'//
'//  where
'//
'//      Sev - is the severity code
'//
'//          00 - Success
'//          01 - Informational
'//          10 - Warning
'//          11 - Error
'//
'//      C - is the Customer code flag
'//
'//      R - is a reserved bit
'//
'//      Facility - is the facility code
'//
'//      Code - is the facility's status code
'//
'//
'// Define the facility codes
'//

%FACILITY_WINDOWS                 = &H8
%FACILITY_ITF                     = &H4

'//
'// Define the severity codes
'//

%STATUS_SEVERITY_SUCCESS          = &H0
%STATUS_SEVERITY_COFAIL           = &H3
%STATUS_SEVERITY_COERROR          = &H2


'//
'// MessageId: NOT_AN_ERROR
'//
'// MessageText:
'//
'// NOTE:  This dummy error message is necessary to force MC to output
'//        the above defines inside the FACILITY_WINDOWS guard instead
'//        of leaving it empty.
'//
%NOT_AN_ERROR                     = &H00080000&

#ENDIF   ' // FACILITY_WINDOWS

'//
'// Codes 0x1700-0x172F are reserved for FILTER
'//
'//
'// MessageId: FILTER_E_END_OF_CHUNKS
'//
'// MessageText:
'//
'// No more chunks of text available in object.
'//
%FILTER_E_END_OF_CHUNKS           = &H80041700&

'//
'// MessageId: FILTER_E_NO_MORE_TEXT
'//
'// MessageText:
'//
'// No more text available in chunk.
'//
%FILTER_E_NO_MORE_TEXT            = &H80041701&

'//
'// MessageId: FILTER_E_NO_MORE_VALUES
'//
'// MessageText:
'//
'// No more property values available in chunk.
'//
%FILTER_E_NO_MORE_VALUES          = &H80041702&

'//
'// MessageId: FILTER_E_ACCESS
'//
'// MessageText:
'//
'// Unable to access object.
'//
%FILTER_E_ACCESS                  = &H80041703&

'//
'// MessageId: FILTER_W_MONIKER_CLIPPED
'//
'// MessageText:
'//
'// Moniker doesn't cover entire region.
'//
%FILTER_W_MONIKER_CLIPPED         = &H00041704&

'//
'// MessageId: FILTER_E_NO_TEXT
'//
'// MessageText:
'//
'// No text in current chunk.
'//
%FILTER_E_NO_TEXT                 = &H80041705&

'//
'// MessageId: FILTER_E_NO_VALUES
'//
'// MessageText:
'//
'// No values in current chunk.
'//
%FILTER_E_NO_VALUES               = &H80041706&

'//
'// MessageId: FILTER_E_EMBEDDING_UNAVAILABLE
'//
'// MessageText:
'//
'// Unable to bind IFilter for embedded object.
'//
%FILTER_E_EMBEDDING_UNAVAILABLE   = &H80041707&

'//
'// MessageId: FILTER_E_LINK_UNAVAILABLE
'//
'// MessageText:
'//
'// Unable to bind IFilter for linked object.
'//
%FILTER_E_LINK_UNAVAILABLE        = &H80041708&

'//
'// MessageId: FILTER_S_LAST_TEXT
'//
'// MessageText:
'//
'// This is the last text in the current chunk.
'//
%FILTER_S_LAST_TEXT               = &H00041709&

'//
'// MessageId: FILTER_S_LAST_VALUES
'//
'// MessageText:
'//
'// This is the last value in the current chunk.
'//
%FILTER_S_LAST_VALUES             = &H0004170A&

'//
'// MessageId: FILTER_E_PASSWORD
'//
'// MessageText:
'//
'// File was not filtered due to password protection.
'//
%FILTER_E_PASSWORD                = &H8004170B&

'//
'// MessageId: FILTER_E_UNKNOWNFORMAT
'//
'// MessageText:
'//
'// The document format is not recognized by the flter.
'//
%FILTER_E_UNKNOWNFORMAT           = &H8004170C&
