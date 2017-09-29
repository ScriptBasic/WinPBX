' ########################################################################################
' Microsoft Windows
' File: MSAAText.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MSAATEXTLib
' Version: 1.0
' Documentation string: MSAAText 1.0 Type Library
' Path: C:\WINDOWS\system32\msaatext.dll
' Library GUID: {150E2D7A-DAC1-4582-947D-2A8FD78B82CD}
' ########################################################################################

#INCLUDE THIS ONCE
%MSAATEXT_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "textstor.inc"

#IF NOT %DEF(%MSAATEXTLib_LIBRARY_DEFINED)
    %MSAATEXTLib_LIBRARY_DEFINED = 1

$LIBID_MSAATEXTLib = GUID$("{150E2D7A-DAC1-4582-947D-2A8FD78B82CD}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {FC48CC30-4F3E-4FA1-803B-AD0E196A83B1}
$PROGID_AccClientDocMgrAccClientDocMgr1 = "AccClientDocMgr.AccClientDocMgr.1"
' CLSID = {6572EE16-5FE5-4331-BB6D-76A49C56E423}
$PROGID_AccDictionaryAccDictionary1 = "AccDictionary.AccDictionary.1"
' CLSID = {6089A37E-EB8A-482D-BD6F-F9F46904D16D}
$PROGID_AccServerDocMgrAccServerDocMgr1 = "AccServerDocMgr.AccServerDocMgr.1"
' CLSID = {BF426F7E-7A5E-44D6-830C-A390EA9462A3}
$PROGID_DocWrapDocWrap1 = "DocWrap.DocWrap.1"
' CLSID = {5440837F-4BFF-4AE5-A1B1-7722ECC6332A}
$PROGID_MSAATextAccStore1 = "MSAAText.AccStore.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {FC48CC30-4F3E-4FA1-803B-AD0E196A83B1}
$PROGID_AccClientDocMgrAccClientDocMgr = "AccClientDocMgr.AccClientDocMgr"
' CLSID = {6572EE16-5FE5-4331-BB6D-76A49C56E423}
$PROGID_AccDictionaryAccDictionary = "AccDictionary.AccDictionary"
' CLSID = {6089A37E-EB8A-482D-BD6F-F9F46904D16D}
$PROGID_AccServerDocMgrAccServerDocMgr = "AccServerDocMgr.AccServerDocMgr"
' CLSID = {BF426F7E-7A5E-44D6-830C-A390EA9462A3}
$PROGID_DocWrapDocWrap = "DocWrap.DocWrap"
' CLSID = {5440837F-4BFF-4AE5-A1B1-7722ECC6332A}
$PROGID_MSAATextAccStore = "MSAAText.AccStore"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_MSAAControl = GUID$("{08CD963F-7A3E-4F5C-9BD8-D692BB043C5B}")
$CLSID_AccClientDocMgr = GUID$("{FC48CC30-4F3E-4FA1-803B-AD0E196A83B1}")
$CLSID_AccDictionary = GUID$("{6572EE16-5FE5-4331-BB6D-76A49C56E423}")
$CLSID_AccServerDocMgr = GUID$("{6089A37E-EB8A-482D-BD6F-F9F46904D16D}")
$CLSID_DocWrap = GUID$("{BF426F7E-7A5E-44D6-830C-A390EA9462A3}")
$CLSID_AccStore = GUID$("{5440837F-4BFF-4AE5-A1B1-7722ECC6332A}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IAccClientDocMgr = GUID$("{4C896039-7B6D-49E6-A8C1-45116A98292B}")
$IID_IAccDictionary = GUID$("{1DC4CB5F-D737-474D-ADE9-5CCFC9BC1CC9}")
$IID_IAccServerDocMgr = GUID$("{AD7C73CF-6DD5-4855-ABC2-B04BAD5B9153}")
$IID_IAccStore = GUID$("{E2CD4A63-2B72-4D48-B739-95E4765195BA}")
$IID_IDocWrap = GUID$("{DCD285FE-0BE0-43BD-99C9-AAAEC513C555}")
$IID_ITfMSAAControl = GUID$("{B5F8FB3B-393F-4F7C-84CB-504924C2705A}")


' ########################################################################################
' Interface name = ITfMSAAControl
' IID = {B5F8FB3B-393F-4F7C-84CB-504924C2705A}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITfMSAAControl_INTERFACE_DEFINED)
    %ITfMSAAControl_INTERFACE_DEFINED = 1

INTERFACE ITfMSAAControl $IID_ITfMSAAControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SystemEnableMSAA ( _                          ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SystemDisableMSAA ( _                         ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITfMSAAControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAccDictionary
' IID = {1DC4CB5F-D737-474D-ADE9-5CCFC9BC1CC9}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAccDictionary_INTERFACE_DEFINED)
    %IAccDictionary_INTERFACE_DEFINED = 1

INTERFACE IAccDictionary $IID_IAccDictionary

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLocalizedString ( _                        ' VTable offset = 12
     BYREF Term AS GUID _                               ' __in REFGUID Term
   , BYVAL lcid AS DWORD _                              ' __in LCID lcid
   , BYREF pResult AS WSTRING _                         ' __out BSTR *pResult
   , BYREF plcid AS DWORD _                             ' __out LCID *plcid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParentTerm ( _                             ' VTable offset = 16
     BYREF Term AS GUID _                               ' __in REFGUID Term
   , BYREF pParentTerm AS GUID _                        ' __out GUID *pParentTerm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMnemonicString ( _                         ' VTable offset = 20
     BYREF Term AS GUID _                               ' __in REFGUID Term
   , BYREF pResult AS WSTRING _                         ' __out BSTR *pResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LookupMnemonicTerm ( _                        ' VTable offset = 24
     BYVAL bstrMnemonic AS WSTRING _                    ' __in BSTR bstrMnemonic
   , BYREF pTerm AS GUID _                              ' __out GUID *pTerm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertValueToString ( _                      ' VTable offset = 28
     BYREF Term AS GUID _                               ' __in REFGUID Term
   , BYVAL lcid AS DWORD _                              ' __in LCID lcid
   , BYVAL varValue AS VARIANT _                        ' __in VARIANT varValue
   , BYREF pbstrResult AS WSTRING _                     ' __out BSTR *pbstrResult
   , BYREF plcid AS DWORD _                             ' __out LCID *plcid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAccDictionary_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAccStore
' IID = {E2CD4A63-2B72-4D48-B739-95E4765195BA}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAccStore_INTERFACE_DEFINED)
    %IAccStore_INTERFACE_DEFINED = 1

INTERFACE IAccStore $IID_IAccStore

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Register ( _                                  ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unregister ( _                                ' VTable offset = 16
     BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDocuments ( _                              ' VTable offset = 20
     BYREF enumUnknown AS IEnumUnknown _                ' __out IEnumUnknown **enumUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LookupByHWND ( _                              ' VTable offset = 24
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppunk AS IUnknown _                          ' __out IUnknown **ppunk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LookupByPoint ( _                             ' VTable offset = 28
     BYVAL pt AS POINT _                                ' __in POINT pt
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppunk AS IUnknown _                          ' __out IUnknown **ppunk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDocumentFocus ( _                           ' VTable offset = 32
     BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFocused ( _                                ' VTable offset = 36
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppunk AS IUnknown _                          ' __out IUnknown **ppunk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAccStore_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAccServerDocMgr
' IID = {AD7C73CF-6DD5-4855-ABC2-B04BAD5B9153}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAccServerDocMgr_INTERFACE_DEFINED)
    %IAccServerDocMgr_INTERFACE_DEFINED = 1

INTERFACE IAccServerDocMgr $IID_IAccServerDocMgr

   INHERIT IUnknown

   ' =====================================================================================
   METHOD NewDocument ( _                               ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RevokeDocument ( _                            ' VTable offset = 16
     BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDocumentFocus ( _                           ' VTable offset = 20
     BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAccServerDocMgr_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAccClientDocMgr
' IID = {4C896039-7B6D-49E6-A8C1-45116A98292B}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAccClientDocMgr_INTERFACE_DEFINED)
    %IAccClientDocMgr_INTERFACE_DEFINED = 1

INTERFACE IAccClientDocMgr $IID_IAccClientDocMgr

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDocuments ( _                              ' VTable offset = 12
     BYREF enumUnknown AS IEnumUnknown _                ' __out IEnumUnknown **enumUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LookupByHWND ( _                              ' VTable offset = 16
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppunk AS IUnknown _                          ' __out IUnknown **ppunk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LookupByPoint ( _                             ' VTable offset = 20
     BYVAL pt AS POINT _                                ' __in POINT pt
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppunk AS IUnknown _                          ' __out IUnknown **ppunk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFocused ( _                                ' VTable offset = 24
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppunk AS IUnknown _                          ' __out IUnknown **ppunk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAccClientDocMgr_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDocWrap
' IID = {DCD285FE-0BE0-43BD-99C9-AAAEC513C555}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDocWrap_INTERFACE_DEFINED)
    %IDocWrap_INTERFACE_DEFINED = 1

INTERFACE IDocWrap $IID_IDocWrap

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetDoc ( _                                    ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWrappedDoc ( _                             ' VTable offset = 16
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppunk AS IUnknown _                          ' __out IUnknown **ppunk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDocWrap_INTERFACE_DEFINED__ */

#ENDIF    ' /* __MSAATEXTLib_LIBRARY_DEFINED__ */


' ########################################################################################
' Interfaces not included in MSAATEXTLib.
' ########################################################################################

$IID_IInternalDocWrap = GUID$("{E1AA6466-9DB4-40BA-BE03-77C38E8E60B2}")
$IID_ITextStoreACPEx = GUID$("{A2DE3BC2-3D8E-11D3-81A9-F753FBE61A00}")
$IID_ITextStoreAnchorEx = GUID$("{A2DE3BC1-3D8E-11D3-81A9-F753FBE61A00}")
$IID_ITextStoreACPSinkEx = GUID$("{2BDF9464-41E2-43E3-950C-A6865BA25CD4}")
$IID_ITextStoreSinkAnchorEx = GUID$("{25642426-028D-4474-977B-111BB114FE3E}")
$IID_IVersionInfo = GUID$("{401518EC-DB00-4611-9B29-2A0E4B9AFA85}")
$IID_ICoCreateLocally = GUID$("{03DE00AA-F272-41E3-99CB-03C5E8114EA0}")
$IID_ICoCreatedLocally = GUID$("{0A53EB6C-1908-4742-8CFF-2CEE2E93F94C}")
$IID_IClonableWrapper = GUID$("{B33E75FF-E84C-4DCA-A25C-33B8DC003374}")


' ########################################################################################
' Interface name = IInternalDocWrap
' IID = E1AA6466-9DB4-40BA-BE03-77C38E8E60B2
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInternalDocWrap_INTERFACE_DEFINED)
    %IInternalDocWrap_INTERFACE_DEFINED = 1

INTERFACE IInternalDocWrap $IID_IInternalDocWrap

   INHERIT IUnknown

   ' =====================================================================================
   METHOD NotifyRevoke ( _                              ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInternalDocWrap_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITextStoreACPEx
' IID = A2DE3BC2-3D8E-11D3-81A9-F753FBE61A00
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITextStoreACPEx_INTERFACE_DEFINED)
    %ITextStoreACPEx_INTERFACE_DEFINED = 1

INTERFACE ITextStoreACPEx $IID_ITextStoreACPEx

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ScrollToRect ( _                              ' VTable offset = 12
     BYVAL acpStart AS LONG _                           ' __in LONG acpStart
   , BYVAL acpEnd AS LONG _                             ' __in LONG acpEnd
   , BYVAL rc AS RECT _                                 ' __in RECT rc
   , BYVAL dwPosition AS DWORD _                        ' __in DWORD dwPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITextStoreACPEx_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITextStoreAnchorEx
' IID = A2DE3BC1-3D8E-11D3-81A9-F753FBE61A00
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITextStoreAnchorEx_INTERFACE_DEFINED)
    %ITextStoreAnchorEx_INTERFACE_DEFINED = 1

INTERFACE ITextStoreAnchorEx $IID_ITextStoreAnchorEx

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ScrollToRect ( _                              ' VTable offset = 12
     BYVAL pStart AS IAnchor _                          ' __in IAnchor *pStart
   , BYVAL pEnd AS IAnchor _                            ' __in IAnchor *pEnd
   , BYVAL rc AS RECT _                                 ' __in RECT rc
   , BYVAL dwPosition AS DWORD _                        ' __in DWORD dwPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITextStoreAnchorEx_INTERFACE_DEFINED__ */


%TS_STRF_START = 0
%TS_STRF_MID   = 1
%TS_STRF_END   = 2


' ########################################################################################
' Interface name = ITextStoreACPSinkEx
' IID = 2BDF9464-41E2-43E3-950C-A6865BA25CD4
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITextStoreACPSinkEx_INTERFACE_DEFINED)
    %ITextStoreACPSinkEx_INTERFACE_DEFINED = 1

INTERFACE ITextStoreACPSinkEx $IID_ITextStoreACPSinkEx

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnDisconnect ( _                              ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITextStoreACPSinkEx_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITextStoreSinkAnchorEx
' IID = 25642426-028D-4474-977B-111BB114FE3E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITextStoreSinkAnchorEx_INTERFACE_DEFINED)
    %ITextStoreSinkAnchorEx_INTERFACE_DEFINED = 1

INTERFACE ITextStoreSinkAnchorEx $IID_ITextStoreSinkAnchorEx

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnDisconnect ( _                              ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITextStoreSinkAnchorEx_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IVersionInfo
' IID = 401518EC-DB00-4611-9B29-2A0E4B9AFA85
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVersionInfo_INTERFACE_DEFINED)
    %IVersionInfo_INTERFACE_DEFINED = 1

INTERFACE IVersionInfo $IID_IVersionInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSubcomponentCount ( _                      ' VTable offset = 12
     BYVAL ulSub AS DWORD _                             ' __in ULONG ulSub
   , BYREF ulCount AS DWORD _                           ' __out ULONG *ulCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetImplementationID ( _                       ' VTable offset = 16
     BYVAL ulSub AS DWORD _                             ' __in ULONG ulSub
   , BYREF implid AS GUID _                             ' __out GUID *implid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBuildVersion ( _                           ' VTable offset = 20
     BYVAL ulSub AS DWORD _                             ' __in ULONG ulSub
   , BYREF pdwMajor AS DWORD _                          ' __out DWORD *pdwMajor
   , BYREF pdwMinor AS DWORD _                          ' __out DWORD *pdwMinor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetComponentDescription ( _                   ' VTable offset = 24
     BYVAL ulSub AS DWORD _                             ' __in ULONG ulSub
   , BYREF pImplStr AS WSTRING _                        ' __out BSTR *pImplStr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInstanceDescription ( _                    ' VTable offset = 28
     BYVAL ulSub AS DWORD _                             ' __in ULONG ulSub
   , BYREF pImplStr AS WSTRING _                        ' __out BSTR *pImplStr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVersionInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICoCreateLocally
' IID = 03DE00AA-F272-41E3-99CB-03C5E8114EA0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICoCreateLocally_INTERFACE_DEFINED)
    %ICoCreateLocally_INTERFACE_DEFINED = 1

INTERFACE ICoCreateLocally $IID_ICoCreateLocally

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CoCreateLocally ( _                           ' VTable offset = 12
     BYREF rclsid AS GUID _                             ' __in REFCLSID rclsid
   , BYVAL dwClsContext AS DWORD _                      ' __in DWORD dwClsContext
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF punk AS IUnknown _                           ' __out IUnknown **punk
   , BYREF riidParam AS GUID _                          ' __in REFIID riidParam
   , BYVAL punkParam AS IUnknown _                      ' __in IUnknown *punkParam
   , BYVAL varParam AS VARIANT _                        ' __in VARIANT varParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICoCreateLocally_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICoCreatedLocally
' IID = 0A53EB6C-1908-4742-8CFF-2CEE2E93F94C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICoCreatedLocally_INTERFACE_DEFINED)
    %ICoCreatedLocally_INTERFACE_DEFINED = 1

INTERFACE ICoCreatedLocally $IID_ICoCreatedLocally

   INHERIT IUnknown

   ' =====================================================================================
   METHOD LocalInit ( _                                 ' VTable offset = 12
     BYVAL punkLocalObject AS IUnknown _                ' __in IUnknown *punkLocalObject
   , BYREF riidParam AS GUID _                          ' __in REFIID riidParam
   , BYVAL punkParam AS IUnknown _                      ' __in IUnknown *punkParam
   , BYVAL varParam AS VARIANT _                        ' __in VARIANT varParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICoCreatedLocally_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IClonableWrapper
' IID = B33E75FF-E84C-4DCA-A25C-33B8DC003374
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IClonableWrapper_INTERFACE_DEFINED)
    %IClonableWrapper_INTERFACE_DEFINED = 1

INTERFACE IClonableWrapper $IID_IClonableWrapper

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CloneNewWrapper ( _                           ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IClonableWrapper_INTERFACE_DEFINED__ */
