' ########################################################################################
' Microsoft Windows
' File: wcmerrors.inc
' Contents: Windows Config Management
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WCMERRORS_INC = 1

'//_____________________________________________________________________________
'//
'// READ THE FOLLOWING BEFORE YOU CHANGE ANY ERROR CODE DEFINITION
'//
'// Error code numbers and names are defined in this file. Be sure to make
'// error code descriptions consistent with the update here.
'//
'// Error code descriptions are listed in other files:
'//   As unmanaged resource, in dll\SmiEngine.rc
'//
'//
'// IMPORTANT NOTE for STATE_MANAGEMENT HRs. HRs in range of 0x80221000 - 0x80221fff
'//   may not be returned from state APIs, but instead may only appear inside a
'//   SettingsResult object.
'//
'//_____________________________________________________________________________


'//
'// Facility 22 is reserved for State Management Error Codes. See WinError.h
'//
'// %FACILITY_STATE_MANAGEMENT        34  // 0x22
'//


'//
'// State engine processing errors
'//


'//
'// MessageId: WCM_E_INTERNALERROR
'//
'// MessageText:
'//
'//  Unspecified internal error in the state engine.
'//
%WCM_E_INTERNALERROR                     = &H80220000&

'//
'// MessageId: WCM_E_STATENODENOTFOUND
'//
'// MessageText:
'//
'//  State node is not found.
'//
%WCM_E_STATENODENOTFOUND                 = &H80220001&

'//
'// MessageId: WCM_E_STATENODENOTALLOWED
'//
'// MessageText:
'//
'//  State node is not allowed.
'//
%WCM_E_STATENODENOTALLOWED               = &H80220002&

'//
'// MessageId: WCM_E_ATTRIBUTENOTFOUND
'//
'// MessageText:
'//
'//  Attribute is not found.
'//
%WCM_E_ATTRIBUTENOTFOUND                 = &H80220003&

'//
'// MessageId: WCM_E_ATTRIBUTENOTALLOWED
'//
'// MessageText:
'//
'//  Attribute is not allowed.
'//
%WCM_E_ATTRIBUTENOTALLOWED               = &H80220004&

'//
'// MessageId: WCM_E_INVALIDVALUE
'//
'// MessageText:
'//
'//  Valie is invalid.
'//
%WCM_E_INVALIDVALUE                      = &H80220005&

'//
'// MessageId: WCM_E_INVALIDVALUEFORMAT
'//
'// MessageText:
'//
'//  Value is in invalid format.
'//
%WCM_E_INVALIDVALUEFORMAT                = &H80220006&

'//
'// MessageId: WCM_E_TYPENOTSPECIFIED
'//
'// MessageText:
'//
'//  XSD type is missing in metadata.
'//
%WCM_E_TYPENOTSPECIFIED                  = &H80220007&

'//
'// MessageId: WCM_E_INVALIDDATATYPE
'//
'// MessageText:
'//
'//  Data type is unexpected, or existing data does not match the type.
'//
%WCM_E_INVALIDDATATYPE                   = &H80220008&

'//
'// MessageId: WCM_E_NOTPOSITIONED
'//
'// MessageText:
'//
'//  Enumerator is not positioned.
'//
%WCM_E_NOTPOSITIONED                     = &H80220009&

'//
'// MessageId: WCM_E_READONLYITEM
'//
'// MessageText:
'//
'//  Cannot update a read-only setting or attribute.
'//
%WCM_E_READONLYITEM                      = &H8022000A&

'//
'// MessageId: WCM_E_INVALIDPATH
'//
'// MessageText:
'//
'//  Name or path of a state node is in invalid format.
'//
%WCM_E_INVALIDPATH                       = &H8022000B&

'//
'// MessageId: WCM_E_WRONGESCAPESTRING
'//
'// MessageText:
'//
'//  Wrong XML escape sequence in string.
'//
%WCM_E_WRONGESCAPESTRING                 = &H8022000C&

'//
'// MessageId: WCM_E_INVALIDVERSIONFORMAT
'//
'// MessageText:
'//
'//  Invalid version format.
'//
%WCM_E_INVALIDVERSIONFORMAT              = &H8022000D&

'//
'// MessageId: WCM_E_INVALIDLANGUAGEFORMAT
'//
'// MessageText:
'//
'//  Invalid language string format.
'//
%WCM_E_INVALIDLANGUAGEFORMAT             = &H8022000E&

'//
'// MessageId: WCM_E_KEYNOTCHANGEABLE
'//
'// MessageText:
'//
'//  Not allowed to change value in a key member.
'//
%WCM_E_KEYNOTCHANGEABLE                  = &H8022000F&

'//
'// MessageId: WCM_E_EXPRESSIONNOTFOUND
'//
'// MessageText:
'//
'//  Expression is not defined.
'//
%WCM_E_EXPRESSIONNOTFOUND                = &H80220010&

'//
'// MessageId: WCM_E_SUBSTITUTIONNOTFOUND
'//
'// MessageText:
'//
'//  Substitution is not defined.
'//
%WCM_E_SUBSTITUTIONNOTFOUND              = &H80220011&

'//
'// MessageId: WCM_E_USERALREADYREGISTERED
'//
'// MessageText:
'//
'//  User is already registered.
'//
%WCM_E_USERALREADYREGISTERED             = &H80220012&

'//
'// MessageId: WCM_E_USERNOTFOUND
'//
'// MessageText:
'//
'//  User is not registered.
'//
%WCM_E_USERNOTFOUND                      = &H80220013&

'//
'// MessageId: WCM_E_NAMESPACENOTFOUND
'//
'// MessageText:
'//
'//  Namespace is not registered.
'//
%WCM_E_NAMESPACENOTFOUND                 = &H80220014&

'//
'// MessageId: WCM_E_NAMESPACEALREADYREGISTERED
'//
'// MessageText:
'//
'//  Namespace is already registered.
'//
%WCM_E_NAMESPACEALREADYREGISTERED        = &H80220015&

'//
'// MessageId: WCM_E_STORECORRUPTED
'//
'// MessageText:
'//
'//  State store is in corrupted state.
'//
%WCM_E_STORECORRUPTED                    = &H80220016&

'//
'// MessageId: WCM_E_INVALIDEXPRESSIONSYNTAX
'//
'// MessageText:
'//
'//  Expression format is invalid.
'//
%WCM_E_INVALIDEXPRESSIONSYNTAX           = &H80220017&

'//
'// MessageId: WCM_E_NOTIFICATIONNOTFOUND
'//
'// MessageText:
'//
'//  No matching Notification found.
'//
%WCM_E_NOTIFICATIONNOTFOUND              = &H80220018&

'//
'// MessageId: WCM_E_CONFLICTINGASSERTION
'//
'// MessageText:
'//
'//  New restriction is conflicting with existing restriction.
'//
%WCM_E_CONFLICTINGASSERTION              = &H80220019&

'//
'// MessageId: WCM_E_ASSERTIONFAILED
'//
'// MessageText:
'//
'//  Assertion Validation failed.
'//
%WCM_E_ASSERTIONFAILED                   = &H8022001A&

'//
'// MessageId: WCM_E_DUPLICATENAME
'//
'// MessageText:
'//
'//  Name already exists.
'//
%WCM_E_DUPLICATENAME                     = &H8022001B&

'//
'// MessageId: WCM_E_INVALIDKEY
'//
'// MessageText:
'//
'//  Member referenced by the key does not match the complexType definition.
'//
%WCM_E_INVALIDKEY                        = &H8022001C&

'//
'// MessageId: WCM_E_INVALIDSTREAM
'//
'// MessageText:
'//
'//  Tried to load invalid data from stream.
'//
%WCM_E_INVALIDSTREAM                     = &H8022001D&

'//
'// MessageId: WCM_E_HANDLERNOTFOUND
'//
'// MessageText:
'//
'//  Handler is not defined.
'//
%WCM_E_HANDLERNOTFOUND                   = &H8022001E&

'//
'// MessageId: WCM_E_INVALIDHANDLERSYNTAX
'//
'// MessageText:
'//
'//  Handler attribute is of invalid syntax.
'//
%WCM_E_INVALIDHANDLERSYNTAX              = &H8022001F&

'//
'// MessageId: WCM_E_VALIDATIONFAILED
'//
'// MessageText:
'//
'//  Validation of metadata failed.
'//
%WCM_E_VALIDATIONFAILED                  = &H80220020&

'//
'// MessageId: WCM_E_RESTRICTIONFAILED
'//
'// MessageText:
'//
'//  Invalid setting value on restriction.
'//
%WCM_E_RESTRICTIONFAILED                 = &H80220021&

'//
'// MessageId: WCM_E_MANIFESTCOMPILATIONFAILED
'//
'// MessageText:
'//
'//  XSD/XML Manifest compilation failed.
'//
%WCM_E_MANIFESTCOMPILATIONFAILED         = &H80220022&

'//
'// MessageId: WCM_E_CYCLICREFERENCE
'//
'// MessageText:
'//
'//  Cyclic reference detected.
'//
%WCM_E_CYCLICREFERENCE                   = &H80220023&

'//
'// MessageId: WCM_E_MIXTYPEASSERTION
'//
'// MessageText:
'//
'//  Assertions using shared and per-user settings are not supported
'//
%WCM_E_MIXTYPEASSERTION                 = &H80220024&

'//
'// MessageId: WCM_E_NOTSUPPORTEDFUNCTION
'//
'// MessageText:
'//
'//  Not supported function is found
'//
%WCM_E_NOTSUPPORTEDFUNCTION             = &H80220025&

'//
'// MessageId: WCM_E_VALUETOOBIG
'//
'// MessageText:
'//
'//  A value is too big to process
'//
%WCM_E_VALUETOOBIG                      = &H80220026&

'//
'// MessageId: WCM_E_INVALIDATTRIBUTECOMBINATION
'//
'// MessageText:
'//
'//  Invalid attribute combination
'//
%WCM_E_INVALIDATTRIBUTECOMBINATION      = &H80220027&

'//
'// MessageId: WCM_E_ABORTOPERATION
'//
'// MessageText:
'//
'//  Current operation should be aborted
'//
%WCM_E_ABORTOPERATION                   = &H80220028&

'//
'// MessageId: WCM_E_MISSINGCONFIGURATION
'//
'// MessageText:
'//
'//  CONFIGURATION and or related tags are missing
'//
%WCM_E_MISSINGCONFIGURATION              = &H80220029&

'//
'// MessageId: WCM_E_INVALIDPROCESSORFORMAT
'//
'// MessageText:
'//
'//  The processor architecture attribute has an invalid value
'//
%WCM_E_INVALIDPROCESSORFORMAT            = &H8022002A&

'//
'// MessageId: WCM_E_SOURCEMANEMPTYVALUE
'//
'// MessageText:
'//
'//  The source manifest has empty value
'//
%WCM_E_SOURCEMANEMPTYVALUE               = &H8022002B&

'//
'// HRs below this point should not be returned from APIs. Rather, they
'// should only be embedded in SettingsResult objects.
'//

'//
'// MessageId: WCM_S_INTERNALERROR
'//
'// NOTE: This HR should never be returned from APIs or as a result
'//
'// MessageText:
'//
'//  Unspecified internal warning in the state engine.
'//
%WCM_S_INTERNALERROR                     = &H00221000&

'//
'// MessageId: WCM_S_ATTRIBUTENOTFOUND
'//
'// NOTE: This HR may not be returned from APIs, but must always be contained
'//      within a SettingsResult object.
'//
'// MessageText:
'//
'//  Attribute not found
'//
%WCM_S_ATTRIBUTENOTFOUND                 = &H00221001&

'//
'// MessageId: WCM_S_LEGACYSETTINGWARNING
'//
'// NOTE: This HR may not be returned from APIs, but must always be contained
'//      within a SettingsResult object.
'//
'// MessageText:
'//
'//  Legacy setting usage for this case may have unpredictable results
'//
%WCM_S_LEGACYSETTINGWARNING              = &H00221002&

'//
'// MessageId: WCM_S_INVALIDATTRIBUTECOMBINATION
'//
'// NOTE: This HR may not be returned from APIs, but must always be contained
'//      within a SettingsResult object.
'//
'// MessageText:
'//
'//  Invalid attribute combination
'//
%WCM_S_INVALIDATTRIBUTECOMBINATION       = &H00221004&

'//
'// MessageId: WCM_S_ATTRIBUTENOTALLOWED
'//
'// MessageText:
'//
'//  Attribute is not allowed.
'//
%WCM_S_ATTRIBUTENOTALLOWED               = &H00221005&

'//
'// MessageId: WCM_S_NAMESPACENOTFOUND
'//
'// MessageText:
'//
'//  Attribute is not allowed.
'//
%WCM_S_NAMESPACENOTFOUND                 = &H00221006&

'//
'// MessageId: WCM_E_UNKNOWNRESULT
'//
'// NOTE: This HR may not be returned from APIs, but must always be contained
'//      within a SettingsResult object.
'//
'// MessageText:
'//
'//  Unknown value
'//
%WCM_E_UNKNOWNRESULT                     = &H80221003&
