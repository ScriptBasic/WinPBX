' ########################################################################################
' Microsoft Windows
' File: mergemod.inc
' Contents: Interface for MergeMod COM object
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MsmMergeTypeLib
' Version: 2.0, Locale ID = 0
' Description: Microsoft MSM Merge Type Library
' Path: C:\Archivos de programa\Archivos comunes\Microsoft Shared\MSI Tools\mergemod.dll
' Library GUID: {0ADDA82F-2C26-11D2-AD65-00A0C9AF11A6}
' ########################################################################################

#INCLUDE THIS ONCE
%MERGEMOD_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"

$LIBID_MsmMergeTypeLib = GUID$("{0ADDA82F-2C26-11D2-AD65-00A0C9AF11A6}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {0ADDA830-2C26-11D2-AD65-00A0C9AF11A6}
$PROGID_MsmMerge1 = "Msm.Merge.1"
' CLSID = {F94985D5-29F9-4743-9805-99BC3F35B678}
$PROGID_MsmMerge21 = "Msm.Merge2.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {0ADDA830-2C26-11D2-AD65-00A0C9AF11A6}
$PROGID_MsmMerge = "Msm.Merge"
' CLSID = {F94985D5-29F9-4743-9805-99BC3F35B678}
$PROGID_MsmMerge2 = "Msm.Merge2"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_MsmMerge = GUID$("{0ADDA830-2C26-11D2-AD65-00A0C9AF11A6}")
$CLSID_MsmMerge2 = GUID$("{F94985D5-29F9-4743-9805-99BC3F35B678}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IMsmConfigurableItem = GUID$("{4D6E6284-D21D-401E-84F6-909E00B50F71}")
$IID_IMsmConfigurableItems = GUID$("{55BF723C-9A0D-463E-B42B-B4FBC7BE3C7C}")
$IID_IMsmConfigureModule = GUID$("{AC013209-18A7-4851-8A21-2353443D70A0}")
$IID_IMsmDependencies = GUID$("{0ADDA82D-2C26-11D2-AD65-00A0C9AF11A6}")
$IID_IMsmDependency = GUID$("{0ADDA82B-2C26-11D2-AD65-00A0C9AF11A6}")
$IID_IMsmError = GUID$("{0ADDA828-2C26-11D2-AD65-00A0C9AF11A6}")
$IID_IMsmErrors = GUID$("{0ADDA82A-2C26-11D2-AD65-00A0C9AF11A6}")
$IID_IMsmGetFiles = GUID$("{7041AE26-2D78-11D2-888A-00A0C981B015}")
$IID_IMsmMerge = GUID$("{0ADDA82E-2C26-11D2-AD65-00A0C9AF11A6}")
$IID_IMsmMerge2 = GUID$("{351A72AB-21CB-47AB-B7AA-C4D7B02EA305}")
$IID_IMsmStrings = GUID$("{0ADDA827-2C26-11D2-AD65-00A0C9AF11A6}")

' ========================================================================================
' msmErrorType enum
' IID: {0ADDA825-2C26-11D2-AD65-00A0C9AF11A6}
' MSM Merge Error Types
' MergeMod error types, returned from IMsmError::get_Type
' ========================================================================================

%msmErrorLanguageUnsupported = 1
%msmErrorLanguageFailed      = 2
%msmErrorExclusion           = 3
%msmErrorTableMerge          = 4
%msmErrorResequenceMerge     = 5
%msmErrorFileCreate          = 6
%msmErrorDirCreate           = 7
%msmErrorFeatureRequired     = 8
'#if (_WIN32_MSM >= 150)
%msmErrorBadNullSubstitution = 9
%msmErrorBadSubstitutionType = 10
%msmErrorMissingConfigItem   = 11
%msmErrorBadNullResponse     = 12
%msmErrorDataRequestFailed   = 13
%msmErrorPlatformMismatch    = 14
'#endif

'#if (_WIN32_MSM >= 150)

' ========================================================================================
' msmConfigurableItemFormat enum
' IID: {26903062-AC65-493D-8976-29D399FA7268}
' MSM Configurable Item Types
' ========================================================================================

%msmConfigurableItemText     = 0
%msmConfigurableItemKey      = 1
%msmConfigurableItemInteger  = 2
%msmConfigurableItemBitfield = 3

' ========================================================================================
' msmConfigurableItemOptions enum
' MergeMod options for ModuleConfiguration items.
' ========================================================================================

%msmConfigurableOptionKeyNoOrphan = 1
%msmConfigurableOptionNonNullable = 2

'#endif

' ########################################################################################
' Interface name = IEnumMsmString
' IID = 0ADDA826-2C26-11D2-AD65-00A0C9AF11A6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumMsmString_INTERFACE_DEFINED)
    %IEnumMsmString_INTERFACE_DEFINED = 1

$IID_IEnumMsmString = GUID$("{0ADDA826-2C26-11D2-AD65-00A0C9AF11A6}")

INTERFACE IEnumMsmString $IID_IEnumMsmString

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cFetch AS LONG _                             ' __in unsigned long cFetch
   , BYREF rgbstrStrings AS WSTRING _                   ' __out BSTR *rgbstrStrings
   , BYREF pcFetched AS LONG _                          ' __retval_out unsigned long *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cSkip AS DWORD _                             ' __in unsigned long cSkip
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF pemsmStrings AS IEnumMsmString _             ' __retval_out IEnumMsmString **pemsmStrings
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumMsmString_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMsmStrings
' IID = {0ADDA827-2C26-11D2-AD65-00A0C9AF11A6}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMsmStrings_INTERFACE_DEFINED)
    %IMsmStrings_INTERFACE_DEFINED = 1

INTERFACE IMsmStrings $IID_IMsmStrings

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Item AS LONG _                               ' __in long Item
   ) AS WSTRING                                         ' __retval_out BSTR *Return
   ' =====================================================================================
   PROPERTY GET Count <4> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **NewEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMsmStrings_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMsmError
' IID = {0ADDA828-2C26-11D2-AD65-00A0C9AF11A6}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMsmError_INTERFACE_DEFINED)
    %IMsmError_INTERFACE_DEFINED = 1

INTERFACE IMsmError $IID_IMsmError

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Type <1> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out msmErrorType *ErrorType
   ' =====================================================================================
   PROPERTY GET Path <2> ( _                            ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *ErrorPath
   ' =====================================================================================
   PROPERTY GET Language <3> ( _                        ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out short *ErrorLanguage
   ' =====================================================================================
   PROPERTY GET DatabaseTable <4> ( _                   ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *ErrorTable
   ' =====================================================================================
   PROPERTY GET DatabaseKeys <5> ( _                    ' VTable offset = 44
   ) AS IMsmStrings                                     ' __retval_out IMsmStrings **ErrorKeys
   ' =====================================================================================
   PROPERTY GET ModuleTable <6> ( _                     ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *ErrorTable
   ' =====================================================================================
   PROPERTY GET ModuleKeys <7> ( _                      ' VTable offset = 52
   ) AS IMsmStrings                                     ' __retval_out IMsmStrings **ErrorKeys
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMsmError_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumMsmError
' IID = 0ADDA829-2C26-11D2-AD65-00A0C9AF11A6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumMsmError_INTERFACE_DEFINED)
    %IEnumMsmError_INTERFACE_DEFINED = 1

$IID_IEnumMsmError = GUID$("{0ADDA829-2C26-11D2-AD65-00A0C9AF11A6}")

INTERFACE IEnumMsmError $IID_IEnumMsmError

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cFetch AS LONG _                             ' __in unsigned long cFetch
   , BYREF rgmsmErrors AS IMsmError _                   ' __out IMsmError **rgmsmErrors
   , BYREF pcFetched AS LONG _                          ' __retval_out unsigned long *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cSkip AS DWORD _                             ' __in unsigned long cSkip
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF pemsmErrors AS IEnumMsmError _               ' __retval_out IEnumMsmError **pemsmErrors
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumMsmError_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMsmErrors
' IID = {0ADDA82A-2C26-11D2-AD65-00A0C9AF11A6}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMsmErrors_INTERFACE_DEFINED)
    %IMsmErrors_INTERFACE_DEFINED = 1

INTERFACE IMsmErrors $IID_IMsmErrors

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Item AS LONG _                               ' __in long Item
   ) AS IMsmError                                       ' __retval_out IMsmError **Return
   ' =====================================================================================
   PROPERTY GET Count <4> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **NewEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMsmErrors_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMsmDependency
' IID = {0ADDA82B-2C26-11D2-AD65-00A0C9AF11A6}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMsmDependency_INTERFACE_DEFINED)
    %IMsmDependency_INTERFACE_DEFINED = 1

INTERFACE IMsmDependency $IID_IMsmDependency

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Module <1> ( _                          ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Module
   ' =====================================================================================
   PROPERTY GET Language <2> ( _                        ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out short *Language
   ' =====================================================================================
   PROPERTY GET Version <3> ( _                         ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *Version
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMsmDependency_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumMsmDependency
' IID = 0ADDA82C-2C26-11D2-AD65-00A0C9AF11A6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumMsmDependency_INTERFACE_DEFINED)
    %IEnumMsmDependency_INTERFACE_DEFINED = 1

$IID_IEnumMsmDependency = GUID$("{0ADDA82C-2C26-11D2-AD65-00A0C9AF11A6}")

INTERFACE IEnumMsmDependency $IID_IEnumMsmDependency

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cFetch AS LONG _                             ' __in unsigned long cFetch
   , BYREF rgmsmDependencies AS IMsmDependency _        ' __out IMsmDependency **rgmsmDependencies
   , BYREF pcFetched AS LONG _                          ' __retval_out unsigned long *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cSkip AS DWORD _                             ' __in unsigned long cSkip
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF pemsmDependencies AS IEnumMsmDependency _    ' __retval_out IEnumMsmDependency **pemsmDependencies
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumMsmDependency_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMsmDependencies
' IID = {0ADDA82D-2C26-11D2-AD65-00A0C9AF11A6}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMsmDependencies_INTERFACE_DEFINED)
    %IMsmDependencies_INTERFACE_DEFINED = 1

INTERFACE IMsmDependencies $IID_IMsmDependencies

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Item AS LONG _                               ' __in long Item
   ) AS IMsmDependency                                  ' __retval_out IMsmDependency **Return
   ' =====================================================================================
   PROPERTY GET Count <4> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **NewEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMsmDependencies_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMsmGetFiles
' IID = {7041AE26-2D78-11D2-888A-00A0C981B015}
' MSM File Retrieval Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMsmGetFiles_INTERFACE_DEFINED)
    %IMsmGetFiles_INTERFACE_DEFINED = 1

INTERFACE IMsmGetFiles $IID_IMsmGetFiles

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ModuleFiles <1> ( _                     ' VTable offset = 28
   ) AS IMsmStrings                                     ' __retval_out IMsmStrings **Files
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMsmGetFiles_INTERFACE_DEFINED__ */

'// the following interfaces are available only on MergeMod v1.5 or later
'#if (_WIN32_MSM >= 150)

' ########################################################################################
' Interface name = IMsmConfigurableItem
' IID = {4D6E6284-D21D-401E-84F6-909E00B50F71}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMsmConfigurableItem_INTERFACE_DEFINED)
    %IMsmConfigurableItem_INTERFACE_DEFINED = 1

INTERFACE IMsmConfigurableItem $IID_IMsmConfigurableItem

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Format <2> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out msmConfigurableItemFormat *Format
   ' =====================================================================================
   PROPERTY GET Type <3> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *Type
   ' =====================================================================================
   PROPERTY GET Context <4> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *Context
   ' =====================================================================================
   PROPERTY GET DefaultValue <5> ( _                    ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *DefaultValue
   ' =====================================================================================
   PROPERTY GET Attributes <6> ( _                      ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *Attributes
   ' =====================================================================================
   PROPERTY GET DisplayName <7> ( _                     ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *DisplayName
   ' =====================================================================================
   PROPERTY GET Description <8> ( _                     ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *Description
   ' =====================================================================================
   PROPERTY GET HelpLocation <9> ( _                    ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *HelpLocation
   ' =====================================================================================
   PROPERTY GET HelpKeyword <10> ( _                    ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *HelpKeyword
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMsmConfigurableItem_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumMsmConfigurableItem
' IID = 832C6969-4826-4C24-A397-B7002D8196E6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumMsmConfigurableItem_INTERFACE_DEFINED)
    %IEnumMsmConfigurableItem_INTERFACE_DEFINED = 1

$IID_IEnumMsmConfigurableItem = GUID$("{832C6969-4826-4C24-A397-B7002D8196E6}")

INTERFACE IEnumMsmConfigurableItem $IID_IEnumMsmConfigurableItem

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cFetch AS LONG _                             ' __in unsigned long cFetch
   , BYREF rgmsmItems AS IMsmConfigurableItem _         ' __out IMsmConfigurableItem **rgmsmItems
   , BYREF pcFetched AS LONG _                          ' __retval_out unsigned long *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cSkip AS DWORD _                             ' __in unsigned long cSkip
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF pemsmConfigurableItem AS IEnumMsmConfigurableItem _ ' __retval_out IEnumMsmConfigurableItem **pemsmConfigurableItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumMsmDependency_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMsmConfigurableItems
' IID = {55BF723C-9A0D-463E-B42B-B4FBC7BE3C7C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMsmConfigurableItems_INTERFACE_DEFINED)
    %IMsmConfigurableItems_INTERFACE_DEFINED = 1

INTERFACE IMsmConfigurableItems $IID_IMsmConfigurableItems

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Item AS LONG _                               ' __in long Item
   ) AS IMsmConfigurableItem                            ' __retval_out IMsmConfigurableItem **Return
   ' =====================================================================================
   PROPERTY GET Count <4> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **NewEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMsmConfigurableItems_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMsmConfigureModule
' IID = {AC013209-18A7-4851-8A21-2353443D70A0}
' Interface implemented by authoring tool to provide configuration information.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' IMsmConfigureModule - callback interface called by the MergeMod object.
' Allows the client to provide merge configuration information during the merge process.
' ########################################################################################

#IF NOT %DEF(%IMsmConfigureModule_INTERFACE_DEFINED)
    %IMsmConfigureModule_INTERFACE_DEFINED = 1

INTERFACE IMsmConfigureModule $IID_IMsmConfigureModule

   INHERIT IDispatch

   ' =====================================================================================
   METHOD ProvideTextData <1> ( _                       ' VTable offset = 28
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   ) AS WSTRING                                         ' __retval_out BSTR *ConfigData
   ' =====================================================================================
   METHOD ProvideIntegerData <2> ( _                    ' VTable offset = 32
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   ) AS LONG                                            ' __retval_out long *ConfigData
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMsmConfigureModule_INTERFACE_DEFINED__ */

'#endif // _MSM_WIN32 >= 150

' ########################################################################################
' Interface name = IMsmMerge
' IID = {0ADDA82E-2C26-11D2-AD65-00A0C9AF11A6}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMsmMerge_INTERFACE_DEFINED)
    %IMsmMerge_INTERFACE_DEFINED = 1

INTERFACE IMsmMerge $IID_IMsmMerge

   INHERIT IDispatch

   ' =====================================================================================
   METHOD OpenDatabase <1> ( _                          ' VTable offset = 28
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenModule <2> ( _                            ' VTable offset = 32
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   , BYVAL Language AS INTEGER _                        ' __in short Language
   )                                                    ' void
   ' =====================================================================================
   METHOD CloseDatabase <3> ( _                         ' VTable offset = 36
     BYVAL Commit AS INTEGER _                          ' __in VARIANT_BOOL Commit
   )                                                    ' void
   ' =====================================================================================
   METHOD CloseModule <4> ( _                           ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenLog <5> ( _                               ' VTable offset = 44
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   )                                                    ' void
   ' =====================================================================================
   METHOD CloseLog <6> ( _                              ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD Log <7> ( _                                   ' VTable offset = 52
     BYVAL Message AS WSTRING _                         ' __in BSTR Message
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Errors <8> ( _                          ' VTable offset = 56
   ) AS IMsmErrors                                      ' __retval_out IMsmErrors **Errors
   ' =====================================================================================
   PROPERTY GET Dependencies <9> ( _                    ' VTable offset = 60
   ) AS IMsmDependencies                                ' __retval_out IMsmDependencies **Dependencies
   ' =====================================================================================
   METHOD Merge <10> ( _                                ' VTable offset = 64
     BYVAL Feature AS WSTRING _                         ' __in BSTR Feature
   , BYVAL RedirectDir AS WSTRING _                     ' __in BSTR RedirectDir
   )                                                    ' void
   ' =====================================================================================
   METHOD Connect <11> ( _                              ' VTable offset = 68
     BYVAL Feature AS WSTRING _                         ' __in BSTR Feature
   )                                                    ' void
   ' =====================================================================================
   METHOD ExtractCAB <12> ( _                           ' VTable offset = 72
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   )                                                    ' void
   ' =====================================================================================
   METHOD ExtractFiles <13> ( _                         ' VTable offset = 76
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMsmMerge_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMsmGetFiles
' IID = {351A72AB-21CB-47AB-B7AA-C4D7B02EA305}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' IMsmGetFiles - secondary interface to the MergeMod object, allows
' the client to retrieve the files needed in a particular language of the
' module. Requires certain actions be performed via the IMsmMerge interface
' before some calls on this interface will return valid results.
' ########################################################################################

#IF NOT %DEF(%IMsmGetFiles_INTERFACE_DEFINED)
    %IMsmGetFiles_INTERFACE_DEFINED = 1

$IID_IMsmStrings = GUID$("{0ADDA827-2C26-11D2-AD65-00A0C9AF11A6}")

INTERFACE IMsmGetFiles $IID_IMsmGetFiles

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ModuleFiles ( _                         ' VTable offset = 28
   ) AS IMsmStrings                                     ' __retval_out IMsmStrings **Files
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMsmGetFiles_INTERFACE_DEFINED__ */

'// The following interface is available only on MergeMod v1.5 and later
'#if (_WIN32_MSM >= 150)

' ########################################################################################
' Interface name = IMsmMerge2
' IID = {351A72AB-21CB-47AB-B7AA-C4D7B02EA305}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' IMsmMerge2 - primary interface to the MsmMerge2 object. Allows the client
' to open and close databases, perform merges, retrieve the results
' of a merge, control the creation of a debug-level log, and extract the
' files from a module to disk. Extends the original object by adding
' LFN support and configurable module support.
' ########################################################################################

#IF NOT %DEF(%IMsmMerge2_INTERFACE_DEFINED)
    %IMsmMerge2_INTERFACE_DEFINED = 1

INTERFACE IMsmMerge2 $IID_IMsmMerge2

   INHERIT IDispatch

   ' =====================================================================================
   METHOD OpenDatabase <1> ( _                          ' VTable offset = 28
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenModule <2> ( _                            ' VTable offset = 32
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   , BYVAL Language AS INTEGER _                        ' __in short Language
   )                                                    ' void
   ' =====================================================================================
   METHOD CloseDatabase <3> ( _                         ' VTable offset = 36
     BYVAL Commit AS INTEGER _                          ' __in VARIANT_BOOL Commit
   )                                                    ' void
   ' =====================================================================================
   METHOD CloseModule <4> ( _                           ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenLog <5> ( _                               ' VTable offset = 44
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   )                                                    ' void
   ' =====================================================================================
   METHOD CloseLog <6> ( _                              ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD Log <7> ( _                                   ' VTable offset = 52
     BYVAL Message AS WSTRING _                         ' __in BSTR Message
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Errors <8> ( _                          ' VTable offset = 56
   ) AS IMsmErrors                                      ' __retval_out IMsmErrors **Errors
   ' =====================================================================================
   PROPERTY GET Dependencies <9> ( _                    ' VTable offset = 60
   ) AS IMsmDependencies                                ' __retval_out IMsmDependencies **Dependencies
   ' =====================================================================================
   METHOD Merge <10> ( _                                ' VTable offset = 64
     BYVAL Feature AS WSTRING _                         ' __in BSTR Feature
   , BYVAL RedirectDir AS WSTRING _                     ' __in BSTR RedirectDir
   )                                                    ' void
   ' =====================================================================================
   METHOD Connect <11> ( _                              ' VTable offset = 68
     BYVAL Feature AS WSTRING _                         ' __in BSTR Feature
   )                                                    ' void
   ' =====================================================================================
   METHOD ExtractCAB <12> ( _                           ' VTable offset = 72
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   )                                                    ' void
   ' =====================================================================================
   METHOD ExtractFiles <13> ( _                         ' VTable offset = 76
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   )                                                    ' void
   ' =====================================================================================
   METHOD MergeEx <14> ( _                              ' VTable offset = 80
     BYVAL Feature AS WSTRING _                         ' __in BSTR Feature
   , BYVAL RedirectDir AS WSTRING _                     ' __in BSTR RedirectDir
   , BYVAL pConfiguration AS IUnknown _                 ' __in IUnknown *pConfiguration
   )                                                    ' void
   ' =====================================================================================
   METHOD ExtractFilesEx <15> ( _                       ' VTable offset = 84
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   , BYVAL fLongFileNames AS INTEGER _                  ' __in VARIANT_BOOL fLongFileNames
   , BYREF pFilePaths AS IMsmStrings _                  ' __out IMsmStrings **pFilePaths
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ConfigurableItems <16> ( _              ' VTable offset = 88
   ) AS IMsmConfigurableItems                           ' __retval_out IMsmConfigurableItems **ConfigurableItems
   ' =====================================================================================
   METHOD CreateSourceImage <17> ( _                    ' VTable offset = 92
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   , BYVAL fLongFileNames AS INTEGER _                  ' __in VARIANT_BOOL fLongFileNames
   , BYREF pFilePaths AS IMsmStrings _                  ' __out IMsmStrings **pFilePaths
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ModuleFiles <18> ( _                    ' VTable offset = 96
   ) AS IMsmStrings                                     ' __retval_out IMsmStrings **Files
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMsmMerge2_INTERFACE_DEFINED__ */

'#endif // _WIN32_MSM >= 150
