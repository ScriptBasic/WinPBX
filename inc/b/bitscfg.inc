' ########################################################################################
' Microsoft Windows
' File: bitscfg.inc
' Library name: BITSExtensionSetup
' Version: 1.0, Locale ID = 0
' Library GUID: {B0937B9C-D66D-4D9B-B741-49C6D66A1CD5}
' Contents: Microsoft BITS Server Extensions Setup 1.0
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%BITSCFG_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "mstask.inc"

'EXTERN_C const IID LIBID_BITSExtensionSetup;
$CLSID_BITSExtensionSetupFactory = GUID$("{EFBBAB68-7286-4783-94BF-9461D8B7E7E9}")

' ########################################################################################
' IBITSExtensionSetup interface
' IID = 29CFBBF7-09E4-4B97-B0BC-F2287E3D8EB3
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IBITSExtensionSetup_INTERFACE_DEFINED)
    %IBITSExtensionSetup_INTERFACE_DEFINED = 1

$IID_IBITSExtensionSetup = GUID$("{29CFBBF7-09E4-4B97-B0BC-F2287E3D8EB3}")

INTERFACE IBITSExtensionSetup $IID_IBITSExtensionSetup

   INHERIT IDispatch

   ' =====================================================================================
   METHOD EnableBITSUploads ( _                         ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisableBITSUploads ( _                        ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCleanupTaskName ( _                        ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pTaskName
   ' =====================================================================================
   METHOD GetCleanupTask ( _                            ' VTable offset = 40
     BYREF riid AS GUID _                               ' __in REFIID riid
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnk
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBITSExtensionSetup_INTERFACE_DEFINED__ */


' ########################################################################################
' IBITSExtensionSetupFactory interface
' IID = D5D2D542-5503-4E64-8B48-72EF91A32EE1
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IBITSExtensionSetupFactory_INTERFACE_DEFINED)
    %IBITSExtensionSetupFactory_INTERFACE_DEFINED = 1

$IID_IBITSExtensionSetupFactory = GUID$("{D5D2D542-5503-4E64-8B48-72EF91A32EE1}")

INTERFACE IBITSExtensionSetupFactory $IID_IBITSExtensionSetupFactory

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetObject ( _                                 ' VTable offset = 28
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   ) AS IBITSExtensionSetup                             ' __retval_out IBITSExtensionSetup **ppExtensionSetup
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBITSExtensionSetupFactory_INTERFACE_DEFINED__ */
