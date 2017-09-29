' ########################################################################################
' Microsoft Windows
' File: corsym.inc
' Library name: CorSymLib
' Version: 1.0, Locale ID = 0
' Library GUID: {7E348441-7E1F-380E-A0F6-22668F0F9E4B}
' Contents: Common Language Runtime Symbol Store 1.0 Type Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CORSYM_INC = 1

#INCLUDE ONCE "objidl.inc"

$LIBID_CorSymLib = GUID$("{7E348441-7E1F-380E-A0F6-22668F0F9E4B}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {0A29FF9E-7F9C-4437-8B11-F424491E3931}
$PROGID_CorSymBinder_SxS = "CorSymBinder_SxS"
' CLSID = {0A3976C5-4529-4EF8-B0B0-42EED37082CD}
$PROGID_CorSymReader_SxS = "CorSymReader_SxS"
' CLSID = {0AE2DEB0-F901-478B-BB9F-881EE8066788}
$PROGID_CorSymWriter_SxS = "CorSymWriter_SxS"
' CLSID = {AA544D41-28CB-11D3-BD22-0000F80849BD}
$PROGID_CorSymBinder_deprecated = "SymBinder"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_CorSymReader_deprecated = GUID$("{108296C2-281E-11D3-BD22-0000F80849BD}")
$CLSID_CorSymWriter_deprecated = GUID$("{108296C1-281E-11D3-BD22-0000F80849BD}")
$CLSID_CorSymBinder_SxS = GUID$("{0A29FF9E-7F9C-4437-8B11-F424491E3931}")
$CLSID_CorSymReader_SxS = GUID$("{0A3976C5-4529-4EF8-B0B0-42EED37082CD}")
$CLSID_CorSymWriter_SxS = GUID$("{0AE2DEB0-F901-478B-BB9F-881EE8066788}")
$CLSID_CorSymBinder_deprecated = GUID$("{AA544D41-28CB-11D3-BD22-0000F80849BD}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ISymENCUnmanagedMethod = GUID$("{85E891DA-A631-4c76-ACA2-A44A39C46B8C}")
$IID_ISymNGenWriter = GUID$("{D682FD12-43DE-411C-811B-BE8404CEA126}")
$IID_ISymUnmanagedBinder = GUID$("{AA544D42-28CB-11D3-BD22-0000F80849BD}")
$IID_ISymUnmanagedBinder2 = GUID$("{ACCEE350-89AF-4CCB-8B40-1C2C4C6F9434}")
$IID_ISymUnmanagedBinder3 = GUID$("{28AD3D43-B601-4d26-8A1B-25F9165AF9D7}")
$IID_ISymUnmanagedConstant = GUID$("{48B25ED8-5BAD-41BC-9CEE-CD62FABC74E9}")
$IID_ISymUnmanagedDispose = GUID$("{969708D2-05E5-4861-A3B0-96E473CDF63F}")
$IID_ISymUnmanagedDocument = GUID$("{40DE4037-7C81-3E1E-B022-AE1ABFF2CA08}")
$IID_ISymUnmanagedDocumentWriter = GUID$("{B01FAFEB-C450-3A4D-BEEC-B4CEEC01E006}")
$IID_ISymUnmanagedENCUpdate = GUID$("{E502D2DD-8671-4338-8F2A-FC08229628C4}")
$IID_ISymUnmanagedMethod = GUID$("{B62B923C-B500-3158-A543-24F307A8B7E1}")
$IID_ISymUnmanagedNamespace = GUID$("{0DFF7289-54F8-11D3-BD28-0000F80849BD}")
$IID_ISymUnmanagedReader = GUID$("{B4CE6286-2A6B-3712-A3B7-1EE1DAD467B5}")
$IID_ISymUnmanagedReader2 = GUID$("{A09E53B2-2A57-4CCA-8F63-B84F7C35D4AA}")
$IID_ISymUnmanagedReaderSymbolSearchInfo = GUID$("{20D9645D-03CD-4E34-9C11-9848A5B084F1}")
$IID_ISymUnmanagedScope = GUID$("{68005D0F-B8E0-3B01-84D5-A11A94154942}")
$IID_ISymUnmanagedScope2 = GUID$("{AE932FBA-3FD8-4DBA-8232-30A2309B02DB}")
$IID_ISymUnmanagedSourceServerModule = GUID$("{997DD0CC-A76F-4C82-8D79-EA87559D27AD}")
$IID_ISymUnmanagedSymbolSearchInfo = GUID$("{F8B3534A-A46B-4980-B520-BEC4ACEABA8F}")
$IID_ISymUnmanagedVariable = GUID$("{9F60EEBE-2D9A-3F7C-BF58-80BC991C60BB}")
$IID_ISymUnmanagedWriter = GUID$("{ED14AA72-78E2-4884-84E2-334293AE5214}")
$IID_ISymUnmanagedWriter2 = GUID$("{0B97726E-9E6D-4F05-9A26-424022093CAA}")
$IID_ISymUnmanagedWriter3 = GUID$("{12F1E02C-1E05-4B0E-9468-EBC9D1BB040F}")

'typedef typedef unsigned int UINT32;
'typedef mdToken mdTypeDef;
'typedef mdToken mdMethodDef;
'typedef typedef ULONG_PTR SIZE_T;

'#ifndef __CORHDR_H__
'typedef mdToken mdSignature;
'#endif

$CorSym_LanguageType_C = GUID$("{63a08714-fc37-11d2-904c-00c04fa302a1}")
$CorSym_LanguageType_CPlusPlus = GUID$("{3a12d0b7-c26c-11d0-b442-00a0244a1dd2}")
$CorSym_LanguageType_CSharp = GUID$("{3f5162f8-07c6-11d3-9053-00c04fa302a1}")
$CorSym_LanguageType_Basic = GUID$("{3a12d0b8-c26c-11d0-b442-00a0244a1dd2}")
$CorSym_LanguageType_Java = GUID$("{3a12d0b4-c26c-11d0-b442-00a0244a1dd2}")
$CorSym_LanguageType_Cobol = GUID$("{af046cd1-d0e1-11d2-977c-00a0c9b4d50c}")
$CorSym_LanguageType_Pascal = GUID$("{af046cd2-d0e1-11d2-977c-00a0c9b4d50c}")
$CorSym_LanguageType_ILAssembly = GUID$("{af046cd3-d0e1-11d2-977c-00a0c9b4d50c}")
$CorSym_LanguageType_JScript = GUID$("{3a12d0b6-c26c-11d0-b442-00a0244a1dd2}")
$CorSym_LanguageType_SMC = GUID$("{0d9b9f7b-6611-11d3-bd2a-0000f80849bd}")
$CorSym_LanguageType_MCPlusPlus = GUID$("{4b35fde8-07c6-11d3-905300c04fa302a1}")
$CorSym_LanguageVendor_Microsoft = GUID$("{994b45c4-e6e9-11d2-903f00c04fa302a1}")
$CorSym_DocumentType_Text = GUID$("{5a869d0b-6611-11d3-bd2a-0000f80849bd}")
$CorSym_DocumentType_MC = GUID$("{eb40cb65-3c1f-4352-9d7b-ba0fc47a9d77}")
$CorSym_SourceHash_MD5 = GUID$("{406ea660-64cf-4c82-b6f0-42d48172a799}")
$CorSym_SourceHash_SHA1 = GUID$("{ff1816ec-aa5e-4d10-87f7-6f4963833460}")

'enum CorSymAddrKind
%ADDR_IL_OFFSET          = 1
%ADDR_NATIVE_RVA         = 2
%ADDR_NATIVE_REGISTER    = 3
%ADDR_NATIVE_REGREL      = 4
%ADDR_NATIVE_OFFSET      = 5
%ADDR_NATIVE_REGREG      = 6
%ADDR_NATIVE_REGSTK      = 7
%ADDR_NATIVE_STKREG      = 8
%ADDR_BITFIELD           = 9
%ADDR_NATIVE_ISECTOFFSET = 10

'enum CorSymVarFlag
%VAR_IS_COMP_GEN = 1

' ########################################################################################
' Interface name = ISymUnmanagedBinder
' IID = {AA544D42-28CB-11D3-BD22-0000F80849BD}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISymUnmanagedBinder_INTERFACE_DEFINED)
    %ISymUnmanagedBinder_INTERFACE_DEFINED = 1

INTERFACE ISymUnmanagedBinder $IID_ISymUnmanagedBinder

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetReaderForFile ( _                          ' VTable offset = 12
     BYVAL importer AS IUnknown _                       ' __in IUnknown *importer
   , BYREF filename AS WSTRINGZ _                       ' __in const WCHAR *fileName
   , BYREF searchPath AS WSTRINGZ _                     ' __in const WCHAR *searchPath
   ) AS ISymUnmanagedReader                             ' __retval_out ISymUnmanagedReader **pRetVal
   ' =====================================================================================
   METHOD GetReaderFromStream ( _                       ' VTable offset = 16
     BYVAL importer AS IUnknown _                       ' __in IUnknown *importer
   , BYVAL pstream AS IStream _                         ' __in IStream *pstream
   ) AS ISymUnmanagedReader                             ' __retval_out ISymUnmanagedReader **pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISymUnmanagedBinder_INTERFACE_DEFINED__ */

'enum CorSymSearchPolicyAttributes
%AllowRegistryAccess      = &H1???
%AllowSymbolServerAccess  = &H2???
%AllowOriginalPathAccess  = &H4???
%AllowReferencePathAccess = &H8???

' ########################################################################################
' Interface name = ISymUnmanagedBinder2
' IID = {ACCEE350-89AF-4CCB-8B40-1C2C4C6F9434}
' Inherited interface = ISymUnmanagedBinder
' ########################################################################################

#IF NOT %DEF(%ISymUnmanagedBinder2_INTERFACE_DEFINED)
    %ISymUnmanagedBinder2_INTERFACE_DEFINED = 1

INTERFACE ISymUnmanagedBinder2 $IID_ISymUnmanagedBinder2

   INHERIT IAutomation

   ' =====================================================================================
   ' ISymUnmanagedBinder methods
   ' =====================================================================================
   METHOD GetReaderForFile ( _                          ' VTable offset = 12
     BYVAL importer AS IUnknown _                       ' __in IUnknown *importer
   , BYREF filename AS WSTRINGZ _                       ' __in const WCHAR *fileName
   , BYREF searchPath AS WSTRINGZ _                     ' __in const WCHAR *searchPath
   ) AS ISymUnmanagedReader                             ' __retval_out ISymUnmanagedReader **pRetVal
   ' =====================================================================================
   METHOD GetReaderFromStream ( _                       ' VTable offset = 16
     BYVAL importer AS IUnknown _                       ' __in IUnknown *importer
   , BYVAL pstream AS IStream _                         ' __in IStream *pstream
   ) AS ISymUnmanagedReader                             ' __retval_out ISymUnmanagedReader **pRetVal
   ' =====================================================================================

   ' =====================================================================================
   ' ISymUnmanagedBinder2 methods
   ' =====================================================================================
   METHOD GetReaderForFile2 ( _                         ' VTable offset = 20
     BYVAL importer AS IUnknown _                       ' __in IUnknown *importer
   , BYREF filename AS WSTRINGZ _                       ' __in const WCHAR *fileName
   , BYREF searchPath AS WSTRINGZ _                     ' __in const WCHAR *searchPath
   , BYVAL searchPolicy AS DWORD _                      ' __in ULONG32 searchPolicy
   ) AS ISymUnmanagedReader                             ' __retval_out ISymUnmanagedReader **pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISymUnmanagedBinder2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISymUnmanagedBinder3
' IID = {28AD3D43-B601-4d26-8A1B-25F9165AF9D7}
' Inherited interface = ISymUnmanagedBinder2
' ########################################################################################

#IF NOT %DEF(%ISymUnmanagedBinder2_INTERFACE_DEFINED)
    %ISymUnmanagedBinder2_INTERFACE_DEFINED = 1

INTERFACE ISymUnmanagedBinder2 $IID_ISymUnmanagedBinder2

   INHERIT IAutomation

   ' =====================================================================================
   ' ISymUnmanagedBinder methods
   ' =====================================================================================
   METHOD GetReaderForFile ( _                          ' VTable offset = 12
     BYVAL importer AS IUnknown _                       ' __in IUnknown *importer
   , BYREF filename AS WSTRINGZ _                       ' __in const WCHAR *fileName
   , BYREF searchPath AS WSTRINGZ _                     ' __in const WCHAR *searchPath
   ) AS ISymUnmanagedReader                             ' __retval_out ISymUnmanagedReader **pRetVal
   ' =====================================================================================
   METHOD GetReaderFromStream ( _                       ' VTable offset = 16
     BYVAL importer AS IUnknown _                       ' __in IUnknown *importer
   , BYVAL pstream AS IStream _                         ' __in IStream *pstream
   ) AS ISymUnmanagedReader                             ' __retval_out ISymUnmanagedReader **pRetVal
   ' =====================================================================================

   ' =====================================================================================
   ' ISymUnmanagedBinder2 methods
   ' =====================================================================================
   METHOD GetReaderForFile2 ( _                         ' VTable offset = 20
     BYVAL importer AS IUnknown _                       ' __in IUnknown *importer
   , BYREF filename AS WSTRINGZ _                       ' __in const WCHAR *fileName
   , BYREF searchPath AS WSTRINGZ _                     ' __in const WCHAR *searchPath
   , BYVAL searchPolicy AS DWORD _                      ' __in ULONG32 searchPolicy
   ) AS ISymUnmanagedReader                             ' __retval_out ISymUnmanagedReader **pRetVal
   ' =====================================================================================

   ' =====================================================================================
   ' ISymUnmanagedBinder3 methods
   ' =====================================================================================
   METHOD GetReaderFromCallback ( _                     ' VTable offset = 24
     BYVAL importer AS IUnknown _                       ' __in IUnknown *importer
   , BYREF filename AS WSTRINGZ _                       ' __in const WCHAR *fileName
   , BYREF searchPath AS WSTRINGZ _                     ' __in const WCHAR *searchPath
   , BYVAL searchPolicy AS DWORD _                      ' __in ULONG32 searchPolicy
   , BYVAL callback AS IUnknown _                       ' __in IUnknown *callback
   ) AS ISymUnmanagedReader                             ' __retval_out ISymUnmanagedReader **pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISymUnmanagedBinder2_INTERFACE_DEFINED__ */

'static const int E_SYM_DESTROYED = MAKE_HRESULT(1, FACILITY_ITF, 0xdead);
%E_SYM_DESTROYED = &HFFFFDEAD???

' ########################################################################################
' Interface name = ISymUnmanagedDispose
' IID = {969708D2-05E5-4861-A3B0-96E473CDF63F}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISymUnmanagedDispose_INTERFACE_DEFINED)
    %ISymUnmanagedDispose_INTERFACE_DEFINED = 1

INTERFACE ISymUnmanagedDispose $IID_ISymUnmanagedDispose

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Destroy ( _                                   ' VTable offset = 12
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISymUnmanagedDispose_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISymUnmanagedDocument
' IID = {40DE4037-7C81-3E1E-B022-AE1ABFF2CA08}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISymUnmanagedDocument_INTERFACE_DEFINED)
    %ISymUnmanagedDocument_INTERFACE_DEFINED = 1

INTERFACE ISymUnmanagedDocument $IID_ISymUnmanagedDocument

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetURL ( _                                    ' VTable offset = 12
     BYVAL cchUrl AS DWORD _                            ' __in ULONG32 cchUrl
   , BYREF pcchUrl AS DWORD _                           ' __out ULONG32 *pcchUrl VT_UINT <Dword>
   , BYREF szUrl AS DWORD _                             ' __out WCHAR szUrl[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDocumentType ( _                           ' VTable offset = 16
   ) AS GUID                                            ' __retval_out GUID *pRetVal
   ' =====================================================================================
   METHOD GetLanguage ( _                               ' VTable offset = 20
   ) AS GUID                                            ' __retval_out GUID *pRetVal
   ' =====================================================================================
   METHOD GetLanguageVendor ( _                         ' VTable offset = 24
   ) AS GUID                                            ' __retval_out GUID *pRetVal
   ' =====================================================================================
   METHOD GetCheckSumAlgorithmId ( _                    ' VTable offset = 28
   ) AS GUID                                            ' __retval_out GUID *pRetVal
   ' =====================================================================================
   METHOD GetCheckSum ( _                               ' VTable offset = 32
     BYVAL cData AS DWORD _                             ' __in ULONG32 cData VT_UINT <Dword>
   , BYREF pcData AS DWORD _                            ' __out ULONG32 *pcData VT_UINT <Dword>
   , BYVAL data AS BYTE PTR _                           ' __out BYTE data[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD FindClosestLine ( _                           ' VTable offset = 36
     BYVAL line AS DWORD _                              ' __in ULONG32 line
   ) AS DWORD                                           ' __retval_out ULONG32 *pRetVal
   ' =====================================================================================
   METHOD HasEmbeddedSource ( _                         ' VTable offset = 40
   ) AS LONG                                            ' __retval_out BOOL *pRetVal
   ' =====================================================================================
   METHOD GetSourceLength ( _                           ' VTable offset = 44
   ) AS DWORD                                           ' __retval_out ULONG32 *pRetVal
   ' =====================================================================================
   METHOD GetSourceRange ( _                            ' VTable offset = 48
     BYVAL startLine AS DWORD _                         ' __in ULONG32 startLine
   , BYVAL startColumn AS DWORD _                       ' __in ULONG32 startColumn
   , BYVAL endLine AS DWORD _                           ' __in ULONG32 endLine
   , BYVAL endColumn AS DWORD _                         ' __in ULONG32 endColumn
   , BYVAL cSourceBytes AS DWORD _                      ' __in ULONG32 cSourceBytes
   , BYREF pcSourceBytes AS DWORD _                     ' __out ULONG32 *pcSourceBytes
   , BYVAL source AS BYTE PTR _                         ' __out BYTE source[  ]
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISymUnmanagedDocument_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISymUnmanagedDocumentWriter
' IID = {B01FAFEB-C450-3A4D-BEEC-B4CEEC01E006}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISymUnmanagedDocumentWriter_INTERFACE_DEFINED)
    %ISymUnmanagedDocumentWriter_INTERFACE_DEFINED = 1

INTERFACE ISymUnmanagedDocumentWriter $IID_ISymUnmanagedDocumentWriter

   INHERIT IAutomation

   ' =====================================================================================
   METHOD SetSource ( _                                 ' VTable offset = 12
     BYVAL sourceSize AS DWORD _                        ' __in ULONG32 sourceSize
   , BYVAL source AS BYTE PTR _                         ' __in BYTE source[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD SetCheckSum ( _                               ' VTable offset = 16
     BYVAL algorithmId AS GUID _                        ' __in GUID algorithmId
   , BYVAL checkSumSize AS DWORD _                      ' __in ULONG32 checkSumSize
   , BYVAL checkSum AS BYTE PTR _                       ' __in BYTE checkSum[  ]
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISymUnmanagedDocumentWriter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISymUnmanagedMethod
' IID = {B62B923C-B500-3158-A543-24F307A8B7E1}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISymUnmanagedMethod_INTERFACE_DEFINED)
    %ISymUnmanagedMethod_INTERFACE_DEFINED = 1

INTERFACE ISymUnmanagedMethod $IID_ISymUnmanagedMethod

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetToken ( _                                  ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out mdMethodDef *pToken
   ' =====================================================================================
   METHOD GetSequencePointCount ( _                     ' VTable offset = 16
   ) AS DWORD                                           ' __retval_out ULONG32 *pRetVal
   ' =====================================================================================
   METHOD GetRootScope ( _                              ' VTable offset = 20
   ) AS ISymUnmanagedScope                              ' __retval_out ISymUnmanagedScope **pRetVal
   ' =====================================================================================
   METHOD GetScopeFromOffset ( _                        ' VTable offset = 24
     BYVAL offset AS DWORD _                            ' __in ULONG32 offset
   ) AS ISymUnmanagedScope                              ' __retval_out ISymUnmanagedScope **pRetVal
   ' =====================================================================================
   METHOD GetOffset ( _                                 ' VTable offset = 28
     BYVAL document AS ISymUnmanagedDocument _          ' __in ISymUnmanagedDocument *document
   , BYVAL line AS DWORD _                              ' __in ULONG32 line
   , BYVAL column AS DWORD _                            ' __in ULONG32 column
   ) AS DWORD                                           ' __retval_out ULONG32 *pRetVal
   ' =====================================================================================
   METHOD GetRanges ( _                                 ' VTable offset = 32
     BYVAL document AS ISymUnmanagedDocument _          ' __in ISymUnmanagedDocument *document
   , BYVAL line AS DWORD _                              ' __in ULONG32 line
   , BYVAL column AS DWORD _                            ' __in ULONG32 column
   , BYVAL cRanges AS DWORD _                           ' __in ULONG32 cRanges
   , BYREF pcRanges AS DWORD _                          ' __out ULONG32 *pcRanges
   , BYREF ranges AS DWORD _                            ' __out ULONG32 ranges[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetParameters ( _                             ' VTable offset = 36
     BYVAL cParams AS DWORD _                           ' __in ULONG32 cParams VT_UINT <Dword>
   , BYREF pcParams AS DWORD _                          ' __out ULONG32 *pcParams VT_UINT <Dword>
   , BYREF params AS ISymUnmanagedVariable _            ' __out ISymUnmanagedVariable *params[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetNamespace ( _                              ' VTable offset = 40
     BYREF pRetVal AS ISymUnmanagedNamespace _          ' __out ISymUnmanagedNamespace **pRetVal
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSourceStartEnd ( _                         ' VTable offset = 44
     BYREF docs AS ISymUnmanagedDocument _              ' __in ISymUnmanagedDocument *docs[ 2 ]
   , BYREF lines AS DWORD _                             ' __in ULONG32 lines[ 2 ]
   , BYREF columns AS DWORD _                           ' __in ULONG32 columns[ 2 ]
   , BYREF pRetVal AS LONG _                            ' __out BOOL *pRetVal
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSequencePoints ( _                         ' VTable offset = 48
     BYVAL cPoints AS DWORD _                           ' __in ULONG32 cPoints
   , BYREF pcPoints AS DWORD _                          ' __out ULONG32 *pcPoints
   , BYREF offsets AS DWORD _                           ' __in ULONG32 offsets[  ]
   , BYREF documents AS ISymUnmanagedDocument _         ' __in ISymUnmanagedDocument *documents[  ]
   , BYREF lines AS DWORD _                             ' __in ULONG32 lines[  ]
   , BYREF columns AS DWORD _                           ' __in ULONG32 columns[  ]
   , BYREF endLines AS DWORD _                          ' __in ULONG32 endLines[  ]
   , BYREF endColumns AS DWORD _                        ' __in ULONG32 endColumns[  ]
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISymUnmanagedMethod_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISymENCUnmanagedMethod
' IID = {85E891DA-A631-4c76-ACA2-A44A39C46B8C}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISymENCUnmanagedMethod_INTERFACE_DEFINED)
    %ISymENCUnmanagedMethod_INTERFACE_DEFINED = 1

INTERFACE ISymENCUnmanagedMethod $IID_ISymENCUnmanagedMethod

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetFileNameFromOffset ( _                     ' VTable offset = 12
     BYVAL dwOffset AS DWORD _                          ' __in ULONG32 dwOffset
   , BYVAL cchName AS DWORD _                           ' __in ULONG32 cchName
   , BYREF pcchName AS DWORD _                          ' __out ULONG32 *pcchName
   , BYREF szName AS DWORD _                            ' __out WCHAR szName[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetLineFromOffset ( _                         ' VTable offset = 16
     BYVAL dwOffset AS DWORD _                          ' __in ULONG32 dwOffset
   , BYREF pline AS DWORD _                             ' __out ULONG32 *pline
   , BYREF pcolumn AS DWORD _                           ' __out ULONG32 *pcolumn
   , BYREF pendLine AS DWORD _                          ' __out ULONG32 *pendLine
   , BYREF pendColumn AS DWORD _                        ' __out ULONG32 *pendColumn
   , BYREF pdwStartOffset AS DWORD _                    ' __out ULONG32 *pdwStartOffset
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDocumentsForMethodCount ( _                ' VTable offset = 20
   ) AS DWORD                                           ' __retval_out ULONG32 *pRetVal
   ' =====================================================================================
   METHOD GetDocumentsForMethod  ( _                    ' VTable offset = 24
     BYVAL cDocs AS DWORD _                             ' __in ULONG32 cDocs
   , BYREF pcDocs AS DWORD _                            ' __out ULONG32 *pcDocs
   , BYREF documents AS ISymUnmanagedDocument _         ' __in ISymUnmanagedDocument *documents[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSourceExtentInDocument ( _                 ' VTable offset = 28
     BYVAL document AS ISymUnmanagedDocument _          ' __in ISymUnmanagedDocument *document
   , BYREF pstartLine AS DWORD _                        ' __out ULONG32 *pstartLine
   , BYREF pendLine AS DWORD _                          ' __out ULONG32 *pendLine
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISymENCUnmanagedMethod_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISymUnmanagedNamespace
' IID = {0DFF7289-54F8-11D3-BD28-0000F80849BD}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISymUnmanagedNamespace_INTERFACE_DEFINED)
    %ISymUnmanagedNamespace_INTERFACE_DEFINED = 1

INTERFACE ISymUnmanagedNamespace $IID_ISymUnmanagedNamespace

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 12
     BYVAL cchName AS DWORD _                           ' __in ULONG32 cchName
   , BYREF pcchName AS DWORD _                          ' __out ULONG32 *pcchName
   , BYREF szName AS DWORD _                            ' __out WCHAR szName[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetNamespaces ( _                             ' VTable offset = 16
     BYVAL cNameSpaces AS DWORD _                       ' __in ULONG32 cNameSpaces
   , BYREF pcNameSpaces AS DWORD _                      ' __out ULONG32 *pcNameSpaces
   , BYREF namespaces AS ISymUnmanagedNamespace _       ' __out ISymUnmanagedNamespace *namespaces[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVariables ( _                              ' VTable offset = 20
     BYVAL cVars AS DWORD _                             ' __in ULONG32 cVars
   , BYREF pcVars AS DWORD _                            ' __out ULONG32 *pcVars
   , BYREF pVars AS ISymUnmanagedVariable _             ' __out ISymUnmanagedVariable *pVars[  ]
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISymUnmanagedNamespace_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISymUnmanagedReader
' IID = {B4CE6286-2A6B-3712-A3B7-1EE1DAD467B5}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISymUnmanagedReader_INTERFACE_DEFINED)
    %ISymUnmanagedReader_INTERFACE_DEFINED = 1

INTERFACE ISymUnmanagedReader $IID_ISymUnmanagedReader

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetDocument ( _                               ' VTable offset = 12
     BYREF url AS WSTRINGZ _                            ' __in WCHAR *url
   , BYVAL language AS GUID _                           ' __in GUID language
   , BYVAL languageVendor AS GUID _                     ' __in GUID languageVendor
   , BYVAL documentType AS GUID _                       ' __in GUID documentType
   ) AS ISymUnmanagedDocument                           ' __retval_out ISymUnmanagedDocument **pRetVal
   ' =====================================================================================
   METHOD GetDocuments ( _                              ' VTable offset = 16
     BYVAL cDocs AS DWORD _                             ' __in ULONG32 cDocs
   , BYREF pcDocs AS DWORD _                            ' __out ULONG32 *pcDocs
   , BYREF pDocs AS ISymUnmanagedDocument _             ' __out ISymUnmanagedDocument *pDocs[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetUserEntryPoint ( _                         ' VTable offset = 20
   ) AS DWORD                                           ' __retval_out mdMethodDef *pToken
   ' =====================================================================================
   METHOD GetMethod ( _                                 ' VTable offset = 24
     BYVAL token AS DWORD _                             ' __in mdMethodDef token
   ) AS ISymUnmanagedMethod                             ' __retval_out ISymUnmanagedMethod **pRetVal
   ' =====================================================================================
   METHOD GetMethodByVersion ( _                        ' VTable offset = 28
     BYVAL token AS DWORD _                             ' __in mdMethodDef token
   , BYVAL version AS LONG _                            ' __in int version
   ) AS ISymUnmanagedMethod                             ' __retval_out ISymUnmanagedMethod **pRetVal
   ' =====================================================================================
   METHOD GetVariables ( _                              ' VTable offset = 32
     BYVAL parent AS DWORD _                            ' __in mdToken parent
   , BYVAL cVars AS DWORD _                             ' __in ULONG32 cVars
   , BYREF pcVars AS DWORD _                            ' __out ULONG32 *pcVars
   , BYREF pVars AS ISymUnmanagedVariable _             ' __out ISymUnmanagedVariable *pVars[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetGlobalVariables ( _                        ' VTable offset = 36
     BYVAL cVars AS DWORD _                             ' __in ULONG32 cVars
   , BYREF pcVars AS DWORD _                            ' __out ULONG32 *pcVars
   , BYREF pVars AS ISymUnmanagedVariable _             ' __out ISymUnmanagedVariable *pVars[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMethodFromDocumentPosition ( _             ' VTable offset = 40
     BYVAL document AS ISymUnmanagedDocument _          ' __in ISymUnmanagedDocument *document
   , BYVAL line AS DWORD _                              ' __in ULONG32 line
   , BYVAL column AS DWORD _                            ' __in ULONG32 column
   ) AS ISymUnmanagedMethod                             ' __retval_out ISymUnmanagedMethod **pRetVal
   ' =====================================================================================
   METHOD GetSymAttribute ( _                           ' VTable offset = 44
     BYVAL parent AS DWORD _                            ' __in mdToken parent
   , BYREF name AS WSTRINGZ _                           ' __in WCHAR *name
   , BYVAL cBuffer AS DWORD _                           ' __in ULONG32 cBuffer
   , BYREF pcBuffer AS DWORD _                          ' __out ULONG32 *pcBuffer
   , BYVAL buffer AS BYTE PTR _                         ' __out BYTE buffer[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetNamespaces ( _                             ' VTable offset = 48
     BYVAL cNameSpaces AS DWORD _                       ' __in ULONG32 cNameSpaces
   , BYREF pcNameSpaces AS DWORD _                      ' __out ULONG32 *pcNameSpaces
   , BYREF namespaces AS ISymUnmanagedReader _          ' __out ISymUnmanagedNamespace *namespaces[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 52
     BYVAL importer AS IUnknown _                       ' __in IUnknown *importer
   , BYREF filename AS WSTRINGZ _                       ' __in const WCHAR *filename
   , BYREF searchPath AS WSTRINGZ _                     ' __in const WCHAR *searchPath
   , BYVAL pIStream AS IStream _                        ' __in IStream *pIStream
   )                                                    ' void
   ' =====================================================================================
   METHOD UpdateSymbolStore ( _                         ' VTable offset = 56
     BYREF filename AS WSTRINGZ _                       ' __in const WCHAR *filename
   , BYVAL pIStream AS IStream _                        ' __in IStream *pIStream
   )                                                    ' void
   ' =====================================================================================
   METHOD ReplaceSymbolStore ( _                        ' VTable offset = 60
     BYREF filename AS WSTRINGZ _                       ' __in const WCHAR *filename
   , BYVAL pIStream AS IStream _                        ' __in IStream *pIStream
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSymbolStoreFileName ( _                    ' VTable offset = 64
     BYVAL cchName AS DWORD _                           ' __in ULONG32 cchName
   , BYREF pcchName AS DWORD _                          ' __out ULONG32 *pcchName
   , BYREF szName AS DWORD _                            ' __out szName WCHAR szName[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMethodsFromDocumentPosition ( _            ' VTable offset = 68
     BYVAL document AS ISymUnmanagedDocument _          ' __in ISymUnmanagedDocument *document
   , BYVAL line AS DWORD _                              ' __in ULONG32 line
   , BYVAL column AS DWORD _                            ' __in ULONG32 column
   , BYVAL cMethod AS DWORD _                           ' __in ULONG32 cMethod
   , BYREF pcMethod AS DWORD _                          ' __out ULONG32 *pcMethod
   , BYREF pRetVal AS ISymUnmanagedReader _             ' __out pRetVal ISymUnmanagedMethod *pRetVal[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDocumentVersion ( _                        ' VTable offset = 72
     BYVAL pDoc AS ISymUnmanagedDocument _              ' __in ISymUnmanagedDocument *pDoc
   , BYREF version AS LONG _                            ' __out int *version
   , BYREF pbCurrent AS LONG _                          ' __out BOOL *pbCurrent
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMethodVersion ( _                          ' VTable offset = 76
     BYVAL pMethod AS ISymUnmanagedMethod _             ' __in ISymUnmanagedMethod *pMethod
   , BYREF version AS LONG _                            ' __out int *version
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISymUnmanagedReader_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISymUnmanagedSourceServerModule
' IID = {997DD0CC-A76F-4c82-8D79-EA87559D27AD}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISymUnmanagedSourceServerModule_INTERFACE_DEFINED)
    %ISymUnmanagedSourceServerModule_INTERFACE_DEFINED = 1

INTERFACE ISymUnmanagedSourceServerModule $IID_ISymUnmanagedSourceServerModule

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetSourceServerData ( _                       ' VTable offset = 12
     BYREF pDataByteCount AS DWORD _                    ' __out ULONG *pDataByteCount
   , BYREF ppData AS DWORD _                            ' __out BYTE **ppData
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISymUnmanagedSourceServerModule_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISymUnmanagedENCUpdate
' IID = {E502D2DD-8671-4338-8F2A-FC08229628C4}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISymUnmanagedENCUpdate_INTERFACE_DEFINED)
    %ISymUnmanagedENCUpdate_INTERFACE_DEFINED = 1

' // Size = 4 bytes
TYPE SYMLINEDELTA DWORD
   mdMethod AS DWORD   ' mdMethodDef
   delta    AS LONG    ' INT32
END TYPE

INTERFACE ISymUnmanagedENCUpdate $IID_ISymUnmanagedENCUpdate

   INHERIT IAutomation

   ' =====================================================================================
   METHOD UpdateSymbolStore2 ( _                        ' VTable offset = 12
     BYVAL pIStream AS IStream _                        ' __in IStream *pIStream
   , BYREF pDeltaLines AS SYMLINEDELTA _                ' __in SYMLINEDELTA *pDeltaLines
   , BYVAL cDeltaLines AS DWORD _                       ' __in ULONG cDeltaLines
   )                                                    ' void
   ' =====================================================================================
   METHOD GetLocalVariableCount ( _                     ' VTable offset = 16
     BYVAL mdMethodToken AS DWORD _                     ' __in mdMethodDef mdMethodToken
   , BYREF pcLocals AS DWORD _                          ' __out ULONG *pcLocals
   )                                                    ' void
   ' =====================================================================================
   METHOD GetLocalVariables ( _                         ' VTable offset = 20
     BYVAL mdMethodToken AS DWORD _                     ' __in mdMethodDef mdMethodToken
   , BYVAL cLocals AS DWORD _                           ' __in ULONG cLocals
   , BYREF rgLocals AS ISymUnmanagedVariable _          ' __out ISymUnmanagedVariable *rgLocals[  ]
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeForEnc ( _                          ' VTable offset = 24
   )                                                    ' void
   ' =====================================================================================
   METHOD UpdateMethodLines ( _                         ' VTable offset = 28
     BYVAL mdMethodToken AS DWORD _                     ' __in mdMethodDef mdMethodToken
   , BYREF pDeltas AS LONG _                            ' __in INT32 *pDeltas
   , BYVAL cDeltas AS DWORD _                           ' __in ULONG cDeltas
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISymUnmanagedENCUpdate_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISymUnmanagedReaderSymbolSearchInfo
' IID = {20D9645D-03CD-4E34-9C11-9848A5B084F1}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISymUnmanagedReaderSymbolSearchInfo_INTERFACE_DEFINED)
    %ISymUnmanagedReaderSymbolSearchInfo_INTERFACE_DEFINED = 1

INTERFACE ISymUnmanagedReaderSymbolSearchInfo $IID_ISymUnmanagedReaderSymbolSearchInfo

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetSymbolSearchInfoCount ( _                  ' VTable offset = 12
     BYREF pcSearchInfo AS DWORD _                      ' __out ULONG32 *pcSearchInfo
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSymbolSearchInfo ( _                       ' VTable offset = 16
     BYVAL cSearchInfo AS DWORD _                       ' __in ULONG32 cSearchInfo
   , BYREF pcSearchInfo AS DWORD _                      ' __out ULONG32 *pcSearchInfo
   , BYREF rgpSearchInfo AS ISymUnmanagedSymbolSearchInfo _ ' __out ISymUnmanagedSymbolSearchInfo **rgpSearchInfo
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISymUnmanagedReaderSymbolSearchInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISymUnmanagedScope
' IID = {68005D0F-B8E0-3B01-84D5-A11A94154942}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISymUnmanagedScope_INTERFACE_DEFINED)
    %ISymUnmanagedScope_INTERFACE_DEFINED = 1

INTERFACE ISymUnmanagedScope $IID_ISymUnmanagedScope

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetMethod ( _                                 ' VTable offset = 12
   ) AS ISymUnmanagedMethod                             ' __retval_out ISymUnmanagedMethod **pRetVal
   ' =====================================================================================
   METHOD GetParent ( _                                 ' VTable offset = 16
   ) AS ISymUnmanagedScope                              ' __retval_out ISymUnmanagedScope **pRetVal
   ' =====================================================================================
   METHOD GetChildren ( _                               ' VTable offset = 20
     BYVAL cChildren AS DWORD _                         ' __in ULONG32 cChildren
   , BYREF pcChildren AS DWORD _                        ' __out ULONG32 *pcChildren
   , BYREF children AS ISymUnmanagedScope _             ' __out ISymUnmanagedScope *children[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetStartOffset ( _                            ' VTable offset = 24
   ) AS DWORD                                           ' __retval_out ULONG32 *pRetVal
   ' =====================================================================================
   METHOD GetEndOffset ( _                              ' VTable offset = 28
   ) AS DWORD                                           ' __retval_out ULONG32 *pRetVal
   ' =====================================================================================
   METHOD GetLocalCount ( _                             ' VTable offset = 32
   ) AS DWORD                                           ' __retval_out ULONG32 *pRetVal
   ' =====================================================================================
   METHOD GetLocals ( _                                 ' VTable offset = 36
     BYVAL cLocals AS DWORD _                           ' __in ULONG32 cLocals
   , BYREF pcLocals AS DWORD _                          ' __out ULONG32 *pcLocals
   , BYREF locals AS ISymUnmanagedScope _               ' __out ISymUnmanagedVariable *locals[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetNamespaces ( _                             ' VTable offset = 40
     BYVAL cNameSpaces AS DWORD _                       ' __in ULONG32 cNameSpaces
   , BYREF pcNameSpaces AS DWORD _                      ' __out ULONG32 *pcNameSpaces
   , BYREF namespaces AS ISymUnmanagedScope _           ' __out ISymUnmanagedNamespace *namespaces[  ]
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISymUnmanagedScope_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISymUnmanagedConstant
' IID = {48B25ED8-5BAD-41BC-9CEE-CD62FABC74E9}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISymUnmanagedConstant_INTERFACE_DEFINED)
    %ISymUnmanagedConstant_INTERFACE_DEFINED = 1

INTERFACE ISymUnmanagedConstant $IID_ISymUnmanagedConstant

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 12
     BYVAL cchName AS DWORD _                           ' __in ULONG32 cchName
   , BYREF pcchName AS DWORD _                          ' __out ULONG32 *pcchName
   , BYREF szName AS DWORD _                            ' __out WCHAR szName[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 16
     BYREF pValue AS VARIANT _                          ' __out VARIANT *pValue
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSignature ( _                              ' VTable offset = 20
     BYVAL cSig AS DWORD _                              ' __in ULONG32 cSig
   , BYREF pcSig AS DWORD _                             ' __out ULONG32 *pcSig
   , BYVAL sig AS BYTE PTR _                            ' __out BYTE sig[  ]
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISymUnmanagedConstant_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISymUnmanagedScope2
' IID = {AE932FBA-3FD8-4DBA-8232-30A2309B02DB}
' Inherited interface = ISymUnmanagedScope
' ########################################################################################

#IF NOT %DEF(%ISymUnmanagedScope2_INTERFACE_DEFINED)
    %ISymUnmanagedScope2_INTERFACE_DEFINED = 1

INTERFACE ISymUnmanagedScope2 $IID_ISymUnmanagedScope2

   INHERIT IAutomation

   ' =====================================================================================
   ' ISymUnmanagedScope methods
   ' =====================================================================================
   METHOD GetMethod ( _                                 ' VTable offset = 12
   ) AS ISymUnmanagedMethod                             ' __retval_out ISymUnmanagedMethod **pRetVal
   ' =====================================================================================
   METHOD GetParent ( _                                 ' VTable offset = 16
   ) AS ISymUnmanagedScope                              ' __retval_out ISymUnmanagedScope **pRetVal
   ' =====================================================================================
   METHOD GetChildren ( _                               ' VTable offset = 20
     BYVAL cChildren AS DWORD _                         ' __in ULONG32 cChildren
   , BYREF pcChildren AS DWORD _                        ' __out ULONG32 *pcChildren
   , BYREF children AS ISymUnmanagedScope _             ' __out ISymUnmanagedScope *children[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetStartOffset ( _                            ' VTable offset = 24
   ) AS DWORD                                           ' __retval_out ULONG32 *pRetVal
   ' =====================================================================================
   METHOD GetEndOffset ( _                              ' VTable offset = 28
   ) AS DWORD                                           ' __retval_out ULONG32 *pRetVal
   ' =====================================================================================
   METHOD GetLocalCount ( _                             ' VTable offset = 32
   ) AS DWORD                                           ' __retval_out ULONG32 *pRetVal
   ' =====================================================================================
   METHOD GetLocals ( _                                 ' VTable offset = 36
     BYVAL cLocals AS DWORD _                           ' __in ULONG32 cLocals
   , BYREF pcLocals AS DWORD _                          ' __out ULONG32 *pcLocals
   , BYREF locals AS ISymUnmanagedScope _               ' __out ISymUnmanagedVariable *locals[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetNamespaces ( _                             ' VTable offset = 40
     BYVAL cNameSpaces AS DWORD _                       ' __in ULONG32 cNameSpaces
   , BYREF pcNameSpaces AS DWORD _                      ' __out ULONG32 *pcNameSpaces
   , BYREF namespaces AS ISymUnmanagedScope _           ' __out ISymUnmanagedNamespace *namespaces[  ]
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ISymUnmanagedScope2 methods
   ' =====================================================================================
   METHOD GetConstantCount ( _                          ' VTable offset = 44
   ) AS DWORD                                           ' __retval_out ULONG32 *pRetVal
   ' =====================================================================================
   METHOD GetConstants ( _                              ' VTable offset = 48
     BYVAL cConstants AS DWORD _                        ' __in ULONG32 cConstants
   , BYREF pcConstants AS DWORD _                       ' __out ULONG32 *pcConstants
   , BYREF constants AS ISymUnmanagedConstant _         ' __out ISymUnmanagedConstant *constants[  ]
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISymUnmanagedScope2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISymUnmanagedVariable
' IID = {9F60EEBE-2D9A-3F7C-BF58-80BC991C60BB}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISymUnmanagedVariable_INTERFACE_DEFINED)
    %ISymUnmanagedVariable_INTERFACE_DEFINED = 1

INTERFACE ISymUnmanagedVariable $IID_ISymUnmanagedVariable

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 12
     BYVAL cchName AS DWORD _                           ' __in ULONG32 cchName
   , BYREF pcchName AS DWORD _                          ' __out ULONG32 *pcchName
   , BYREF szName AS DWORD _                            ' __out WCHAR szName[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAttributes ( _                             ' VTable offset = 16
   ) AS DWORD                                           ' __retval_out ULONG32 *pRetVal
   ' =====================================================================================
   METHOD GetSignature ( _                              ' VTable offset = 20
     BYVAL cSig AS DWORD _                              ' __in ULONG32 cSig
   , BYREF pcSig AS DWORD _                             ' __out ULONG32 *pcSig
   , BYVAL sig AS BYTE PTR _                            ' __out BYTE sig[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAddressKind ( _                            ' VTable offset = 24
   ) AS DWORD                                           ' __retval_out ULONG32 *pRetVal
   ' =====================================================================================
   METHOD GetAddressField1 ( _                          ' VTable offset = 28
   ) AS DWORD                                           ' __retval_out ULONG32 *pRetVal
   ' =====================================================================================
   METHOD GetAddressField2 ( _                          ' VTable offset = 32
   ) AS DWORD                                           ' __retval_out ULONG32 *pRetVal
   ' =====================================================================================
   METHOD GetAddressField3 ( _                          ' VTable offset = 36
   ) AS DWORD                                           ' __retval_out ULONG32 *pRetVal
   ' =====================================================================================
   METHOD GetStartOffset ( _                            ' VTable offset = 40
   ) AS DWORD                                           ' __retval_out ULONG32 *pRetVal
   ' =====================================================================================
   METHOD GetEndOffset ( _                              ' VTable offset = 44
   ) AS DWORD                                           ' __retval_out ULONG32 *pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISymUnmanagedVariable_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISymUnmanagedSymbolSearchInfo
' IID = {F8B3534A-A46B-4980-B520-BEC4ACEABA8F}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISymUnmanagedSymbolSearchInfo_INTERFACE_DEFINED)
    %ISymUnmanagedSymbolSearchInfo_INTERFACE_DEFINED = 1

INTERFACE ISymUnmanagedSymbolSearchInfo $IID_ISymUnmanagedSymbolSearchInfo

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetSearchPathLength ( _                       ' VTable offset = 12
     BYREF pcchPath AS DWORD _                          ' __out ULONG32 *pcchPath
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSearchPath ( _                             ' VTable offset = 16
     BYVAL cchPath AS DWORD _                           ' __in ULONG32 cchPath
   , BYREF pcchPath AS DWORD _                          ' __out ULONG32 *pcchPath
   , BYREF szPath AS DWORD _                            ' __out WCHAR szPath[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetHRESULT ( _                                ' VTable offset = 20
     BYREF phr AS LONG _                                ' __out HRESULT *phr
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISymUnmanagedSymbolSearchInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISymUnmanagedWriter
' IID = {ED14AA72-78E2-4884-84E2-334293AE5214}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISymUnmanagedWriter_INTERFACE_DEFINED)
    %ISymUnmanagedWriter_INTERFACE_DEFINED = 1

INTERFACE ISymUnmanagedWriter $IID_ISymUnmanagedWriter

   INHERIT IAutomation

   ' =====================================================================================
   METHOD DefineDocument ( _                            ' VTable offset = 12
     BYREF url AS WSTRINGZ _                            ' __in const WCHAR *url
   , BYREF language AS GUID _                           ' __in const GUID *language
   , BYREF languageVendor AS GUID _                     ' __in const GUID *languageVendor
   , BYREF documentType AS GUID _                       ' __in const GUID *documentType
   ) AS ISymUnmanagedDocumentWriter                     ' __retval_out **pRetVal ISymUnmanagedDocumentWriter <interface>
   ' =====================================================================================
   METHOD SetUserEntryPoint ( _                         ' VTable offset = 16
     BYVAL entryMethod AS DWORD _                       ' __in mdMethodDef entryMethod
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenMethod ( _                                ' VTable offset = 20
     BYVAL method AS DWORD _                            ' __in mdMethodDef method
   )                                                    ' void
   ' =====================================================================================
   METHOD CloseMethod ( _                               ' VTable offset = 24
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenScope ( _                                 ' VTable offset = 28
     BYVAL startOffset AS DWORD _                       ' __in ULONG32 startOffset
   ) AS DWORD                                           ' __retval_out ULONG32 *pRetVal
   ' =====================================================================================
   METHOD CloseScope ( _                                ' VTable offset = 32
     BYVAL endOffset AS DWORD _                         ' __in ULONG32 endOffset
   )                                                    ' void
   ' =====================================================================================
   METHOD SetScopeRange ( _                             ' VTable offset = 36
     BYVAL scopeID AS DWORD _                           ' __in ULONG32 scopeID
   , BYVAL startOffset AS DWORD _                       ' __in ULONG32 startOffset
   , BYVAL endOffset AS DWORD _                         ' __in ULONG32 endOffset
   )                                                    ' void
   ' =====================================================================================
   METHOD DefineLocalVariable ( _                       ' VTable offset = 40
     BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   , BYVAL attributes AS DWORD _                        ' __in ULONG32 attributes
   , BYVAL cSig AS DWORD _                              ' __in ULONG32 cSig
   , BYVAL signature AS BYTE PTR _                      ' __in unsigned char signature[  ]
   , BYVAL addrKind AS DWORD _                          ' __in ULONG32 addrKind
   , BYVAL addr1 AS DWORD _                             ' __in ULONG32 addr1
   , BYVAL addr2 AS DWORD _                             ' __in ULONG32 addr2
   , BYVAL addr3 AS DWORD _                             ' __in ULONG32 addr3
   , BYVAL startOffset AS DWORD _                       ' __in ULONG32 startOffset
   , BYVAL endOffset AS DWORD _                         ' __in ULONG32 endOffset
   )                                                    ' void
   ' =====================================================================================
   METHOD DefineParameter ( _                           ' VTable offset = 44
     BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   , BYVAL attributes AS DWORD _                        ' __in ULONG32 attributes
   , BYVAL sequence AS DWORD _                          ' __in ULONG32 sequence
   , BYVAL addrKind AS DWORD _                          ' __in ULONG32 addrKind
   , BYVAL addr1 AS DWORD _                             ' __in ULONG32 addr1
   , BYVAL addr2 AS DWORD _                             ' __in ULONG32 addr2
   , BYVAL addr3 AS DWORD _                             ' __in ULONG32 addr3
   )                                                    ' void
   ' =====================================================================================
   METHOD DefineField ( _                               ' VTable offset = 48
     BYVAL parent AS DWORD _                            ' __in mdTypeDef parent
   , BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   , BYVAL attributes AS DWORD _                        ' __in ULONG32 attributes
   , BYVAL cSig AS DWORD _                              ' __in ULONG32 cSig
   , BYVAL signature AS BYTE PTR _                      ' __in unsigned char signature[  ]
   , BYVAL addrKind AS DWORD _                          ' __in ULONG32 addrKind
   , BYVAL addr1 AS DWORD _                             ' __in ULONG32 addr1
   , BYVAL addr2 AS DWORD _                             ' __in ULONG32 addr2
   , BYVAL addr3 AS DWORD _                             ' __in ULONG32 addr3
   )                                                    ' void
   ' =====================================================================================
   METHOD DefineGlobalVariable ( _                      ' VTable offset = 52
     BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   , BYVAL attributes AS DWORD _                        ' __in ULONG32 attributes
   , BYVAL cSig AS DWORD _                              ' __in ULONG32 cSig
   , BYVAL signature AS BYTE PTR _                      ' __in unsigned char signature[  ]
   , BYVAL addrKind AS DWORD _                          ' __in ULONG32 addrKind
   , BYVAL addr1 AS DWORD _                             ' __in ULONG32 addr1
   , BYVAL addr2 AS DWORD _                             ' __in ULONG32 addr2
   , BYVAL addr3 AS DWORD _                             ' __in ULONG32 addr3
   )                                                    ' void
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSymAttribute ( _                           ' VTable offset = 60
     BYVAL parent AS DWORD _                            ' __in mdToken parent
   , BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   , BYVAL cData AS DWORD _                             ' __in ULONG32 cData
   , BYVAL data AS BYTE PTR _                           ' __in unsigned char data[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenNamespace ( _                             ' VTable offset = 64
     BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   )                                                    ' void
   ' =====================================================================================
   METHOD CloseNamespace ( _                            ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   METHOD UsingNamespace ( _                            ' VTable offset = 72
     BYREF fullName AS WSTRINGZ _                       ' __in const WCHAR *fullName
   )                                                    ' void
   ' =====================================================================================
   METHOD SetMethodSourceRange ( _                      ' VTable offset = 76
     BYVAL startDoc AS ISymUnmanagedDocumentWriter _    ' __in ISymUnmanagedDocumentWriter *startDoc
   , BYVAL startLine AS DWORD _                         ' __in ULONG32 startLine
   , BYVAL startColumn AS DWORD _                       ' __in ULONG32 startColumn
   , BYVAL endDoc AS ISymUnmanagedDocumentWriter _      ' __in ISymUnmanagedDocumentWriter *endDoc
   , BYVAL endLine AS DWORD _                           ' __in ULONG32 endLine
   , BYVAL endColumn AS DWORD _                         ' __in ULONG32 endColumn
   )                                                    ' void
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 80
     BYVAL emitter AS IUnknown _                        ' __in IUnknown *emitter
   , BYREF filename AS WSTRINGZ _                       ' __in const WCHAR *filename
   , BYVAL pIStream AS IStream _                        ' __in IStream *pIStream
   , BYVAL fFullBuild AS LONG _                         ' __in BOOL fFullBuild
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDebugInfo ( _                              ' VTable offset = 84
     BYREF pIDD AS DWORD _                              ' __inout IMAGE_DEBUG_DIRECTORY *pIDD
   , BYVAL cData AS DWORD _                             ' __in DWORD cData
   , BYREF pcData AS DWORD _                            ' __out DWORD *pcData
   , BYVAL data AS ISymUnmanagedWriter _                ' __out ISymUnmanagedWriter data
   )                                                    ' void
   ' =====================================================================================
   METHOD DefineSequencePoints ( _                      ' VTable offset = 88
     BYVAL document AS ISymUnmanagedDocumentWriter _    ' __in ISymUnmanagedDocumentWriter *document
   , BYVAL spCount AS DWORD _                           ' __in ULONG32 spCount
   , BYREF offsets AS DWORD _                           ' __in ULONG32 *offsets
   , BYREF lines AS DWORD _                             ' __in ULONG32 *lines
   , BYREF columns AS DWORD _                           ' __in ULONG32 *columns
   , BYREF endLines AS DWORD _                          ' __in ULONG32 *endLines
   , BYREF endColumns AS DWORD _                        ' __in ULONG32 *endColumns
   )                                                    ' void
   ' =====================================================================================
   METHOD RemapToken ( _                                ' VTable offset = 92
     BYVAL oldToken AS DWORD _                          ' __in mdToken oldToken
   , BYVAL newToken AS DWORD _                          ' __in mdToken newToken
   )                                                    ' void
   ' =====================================================================================
   METHOD Initialize2 ( _                               ' VTable offset = 96
     BYVAL emitter AS IUnknown _                        ' __in IUnknown *emitter
   , BYREF tempfilename AS WSTRINGZ _                   ' __in const WCHAR *tempfilename
   , BYVAL pIStream AS IStream _                        ' __in IStream *pIStream
   , BYVAL fFullBuild AS LONG _                         ' __in BOOL fFullBuild
   , BYVAL finalfilename AS DWORD _                     ' __in const WCHAR *finalfilename
   )                                                    ' void
   ' =====================================================================================
   METHOD DefineConstant ( _                            ' VTable offset = 100
     BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   , BYVAL value AS VARIANT _                           ' __in VARIANT value
   , BYVAL cSig AS DWORD _                              ' __in ULONG32 cSig
   , BYVAL signature AS BYTE PTR _                      ' __in unsigned char signature[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISymUnmanagedWriter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISymUnmanagedWriter2
' IID = {0B97726E-9E6D-4F05-9A26-424022093CAA}
' Inherited interface = ISymUnmanagedWriter
' ########################################################################################

#IF NOT %DEF(%ISymUnmanagedWriter2_INTERFACE_DEFINED)
    %ISymUnmanagedWriter2_INTERFACE_DEFINED = 1

INTERFACE ISymUnmanagedWriter2 $IID_ISymUnmanagedWriter2

   INHERIT IAutomation

   ' =====================================================================================
   ' ISymUnmanagedWriter methods
   ' =====================================================================================
   METHOD DefineDocument ( _                            ' VTable offset = 12
     BYREF url AS WSTRINGZ _                            ' __in const WCHAR *url
   , BYREF language AS GUID _                           ' __in const GUID *language
   , BYREF languageVendor AS GUID _                     ' __in const GUID *languageVendor
   , BYREF documentType AS GUID _                       ' __in const GUID *documentType
   ) AS ISymUnmanagedDocumentWriter                     ' __retval_out **pRetVal ISymUnmanagedDocumentWriter <interface>
   ' =====================================================================================
   METHOD SetUserEntryPoint ( _                         ' VTable offset = 16
     BYVAL entryMethod AS DWORD _                       ' __in mdMethodDef entryMethod
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenMethod ( _                                ' VTable offset = 20
     BYVAL method AS DWORD _                            ' __in mdMethodDef method
   )                                                    ' void
   ' =====================================================================================
   METHOD CloseMethod ( _                               ' VTable offset = 24
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenScope ( _                                 ' VTable offset = 28
     BYVAL startOffset AS DWORD _                       ' __in ULONG32 startOffset
   ) AS DWORD                                           ' __retval_out ULONG32 *pRetVal
   ' =====================================================================================
   METHOD CloseScope ( _                                ' VTable offset = 32
     BYVAL endOffset AS DWORD _                         ' __in ULONG32 endOffset
   )                                                    ' void
   ' =====================================================================================
   METHOD SetScopeRange ( _                             ' VTable offset = 36
     BYVAL scopeID AS DWORD _                           ' __in ULONG32 scopeID
   , BYVAL startOffset AS DWORD _                       ' __in ULONG32 startOffset
   , BYVAL endOffset AS DWORD _                         ' __in ULONG32 endOffset
   )                                                    ' void
   ' =====================================================================================
   METHOD DefineLocalVariable ( _                       ' VTable offset = 40
     BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   , BYVAL attributes AS DWORD _                        ' __in ULONG32 attributes
   , BYVAL cSig AS DWORD _                              ' __in ULONG32 cSig
   , BYVAL signature AS BYTE PTR _                      ' __in unsigned char signature[  ]
   , BYVAL addrKind AS DWORD _                          ' __in ULONG32 addrKind
   , BYVAL addr1 AS DWORD _                             ' __in ULONG32 addr1
   , BYVAL addr2 AS DWORD _                             ' __in ULONG32 addr2
   , BYVAL addr3 AS DWORD _                             ' __in ULONG32 addr3
   , BYVAL startOffset AS DWORD _                       ' __in ULONG32 startOffset
   , BYVAL endOffset AS DWORD _                         ' __in ULONG32 endOffset
   )                                                    ' void
   ' =====================================================================================
   METHOD DefineParameter ( _                           ' VTable offset = 44
     BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   , BYVAL attributes AS DWORD _                        ' __in ULONG32 attributes
   , BYVAL sequence AS DWORD _                          ' __in ULONG32 sequence
   , BYVAL addrKind AS DWORD _                          ' __in ULONG32 addrKind
   , BYVAL addr1 AS DWORD _                             ' __in ULONG32 addr1
   , BYVAL addr2 AS DWORD _                             ' __in ULONG32 addr2
   , BYVAL addr3 AS DWORD _                             ' __in ULONG32 addr3
   )                                                    ' void
   ' =====================================================================================
   METHOD DefineField ( _                               ' VTable offset = 48
     BYVAL parent AS DWORD _                            ' __in mdTypeDef parent
   , BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   , BYVAL attributes AS DWORD _                        ' __in ULONG32 attributes
   , BYVAL cSig AS DWORD _                              ' __in ULONG32 cSig
   , BYVAL signature AS BYTE PTR _                      ' __in unsigned char signature[  ]
   , BYVAL addrKind AS DWORD _                          ' __in ULONG32 addrKind
   , BYVAL addr1 AS DWORD _                             ' __in ULONG32 addr1
   , BYVAL addr2 AS DWORD _                             ' __in ULONG32 addr2
   , BYVAL addr3 AS DWORD _                             ' __in ULONG32 addr3
   )                                                    ' void
   ' =====================================================================================
   METHOD DefineGlobalVariable ( _                      ' VTable offset = 52
     BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   , BYVAL attributes AS DWORD _                        ' __in ULONG32 attributes
   , BYVAL cSig AS DWORD _                              ' __in ULONG32 cSig
   , BYVAL signature AS BYTE PTR _                      ' __in unsigned char signature[  ]
   , BYVAL addrKind AS DWORD _                          ' __in ULONG32 addrKind
   , BYVAL addr1 AS DWORD _                             ' __in ULONG32 addr1
   , BYVAL addr2 AS DWORD _                             ' __in ULONG32 addr2
   , BYVAL addr3 AS DWORD _                             ' __in ULONG32 addr3
   )                                                    ' void
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSymAttribute ( _                           ' VTable offset = 60
     BYVAL parent AS DWORD _                            ' __in mdToken parent
   , BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   , BYVAL cData AS DWORD _                             ' __in ULONG32 cData
   , BYVAL data AS BYTE PTR _                           ' __in unsigned char data[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenNamespace ( _                             ' VTable offset = 64
     BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   )                                                    ' void
   ' =====================================================================================
   METHOD CloseNamespace ( _                            ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   METHOD UsingNamespace ( _                            ' VTable offset = 72
     BYREF fullName AS WSTRINGZ _                       ' __in const WCHAR *fullName
   )                                                    ' void
   ' =====================================================================================
   METHOD SetMethodSourceRange ( _                      ' VTable offset = 76
     BYVAL startDoc AS ISymUnmanagedDocumentWriter _    ' __in ISymUnmanagedDocumentWriter *startDoc
   , BYVAL startLine AS DWORD _                         ' __in ULONG32 startLine
   , BYVAL startColumn AS DWORD _                       ' __in ULONG32 startColumn
   , BYVAL endDoc AS ISymUnmanagedDocumentWriter _      ' __in ISymUnmanagedDocumentWriter *endDoc
   , BYVAL endLine AS DWORD _                           ' __in ULONG32 endLine
   , BYVAL endColumn AS DWORD _                         ' __in ULONG32 endColumn
   )                                                    ' void
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 80
     BYVAL emitter AS IUnknown _                        ' __in IUnknown *emitter
   , BYREF filename AS WSTRINGZ _                       ' __in const WCHAR *filename
   , BYVAL pIStream AS IStream _                        ' __in IStream *pIStream
   , BYVAL fFullBuild AS LONG _                         ' __in BOOL fFullBuild
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDebugInfo ( _                              ' VTable offset = 84
     BYREF pIDD AS DWORD _                              ' __inout IMAGE_DEBUG_DIRECTORY *pIDD
   , BYVAL cData AS DWORD _                             ' __in DWORD cData
   , BYREF pcData AS DWORD _                            ' __out DWORD *pcData
   , BYVAL data AS ISymUnmanagedWriter _                ' __out ISymUnmanagedWriter data
   )                                                    ' void
   ' =====================================================================================
   METHOD DefineSequencePoints ( _                      ' VTable offset = 88
     BYVAL document AS ISymUnmanagedDocumentWriter _    ' __in ISymUnmanagedDocumentWriter *document
   , BYVAL spCount AS DWORD _                           ' __in ULONG32 spCount
   , BYREF offsets AS DWORD _                           ' __in ULONG32 *offsets
   , BYREF lines AS DWORD _                             ' __in ULONG32 *lines
   , BYREF columns AS DWORD _                           ' __in ULONG32 *columns
   , BYREF endLines AS DWORD _                          ' __in ULONG32 *endLines
   , BYREF endColumns AS DWORD _                        ' __in ULONG32 *endColumns
   )                                                    ' void
   ' =====================================================================================
   METHOD RemapToken ( _                                ' VTable offset = 92
     BYVAL oldToken AS DWORD _                          ' __in mdToken oldToken
   , BYVAL newToken AS DWORD _                          ' __in mdToken newToken
   )                                                    ' void
   ' =====================================================================================
   METHOD Initialize2 ( _                               ' VTable offset = 96
     BYVAL emitter AS IUnknown _                        ' __in IUnknown *emitter
   , BYREF tempfilename AS WSTRINGZ _                   ' __in const WCHAR *tempfilename
   , BYVAL pIStream AS IStream _                        ' __in IStream *pIStream
   , BYVAL fFullBuild AS LONG _                         ' __in BOOL fFullBuild
   , BYREF finalfilename AS WSTRINGZ _                  ' __in const WCHAR *finalfilename
   )                                                    ' void
   ' =====================================================================================
   METHOD DefineConstant ( _                            ' VTable offset = 100
     BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   , BYVAL value AS VARIANT _                           ' __in VARIANT value
   , BYVAL cSig AS DWORD _                              ' __in ULONG32 cSig
   , BYVAL signature AS BYTE PTR _                      ' __in unsigned char signature[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ISymUnmanagedWriter2 methods
   ' =====================================================================================
   METHOD DefineLocalVariable2 ( _                      ' VTable offset = 108
     BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   , BYVAL attributes AS DWORD _                        ' __in ULONG32 attributes
   , BYVAL sigToken AS DWORD _                          ' __in mdSignature sigToken
   , BYVAL addrKind AS DWORD _                          ' __in ULONG32 addrKind
   , BYVAL addr1 AS DWORD _                             ' __in ULONG32 addr1
   , BYVAL addr2 AS DWORD _                             ' __in ULONG32 addr2
   , BYVAL addr3 AS DWORD _                             ' __in ULONG32 addr3
   , BYVAL startOffset AS DWORD _                       ' __in ULONG32 startOffset
   , BYVAL endOffset AS DWORD _                         ' __in ULONG32 endOffset
   )                                                    ' void
   ' =====================================================================================
   METHOD DefineGlobalVariable2 ( _                     ' VTable offset = 112
     BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   , BYVAL attributes AS DWORD _                        ' __in ULONG32 attributes
   , BYVAL sigToken AS DWORD _                          ' __in mdSignature sigToken
   , BYVAL addrKind AS DWORD _                          ' __in ULONG32 addrKind
   , BYVAL addr1 AS DWORD _                             ' __in ULONG32 addr1
   , BYVAL addr2 AS DWORD _                             ' __in ULONG32 addr2
   , BYVAL addr3 AS DWORD _                             ' __in ULONG32 addr3
   )                                                    ' void
   ' =====================================================================================
   METHOD DefineConstant2 ( _                           ' VTable offset = 116
     BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   , BYVAL value AS VARIANT _                           ' __in VARIANT value
   , BYVAL sigToken AS DWORD _                          ' __in mdSignature sigToken
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISymUnmanagedWriter2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISymUnmanagedWriter3
' IID = {12F1E02C-1E05-4B0E-9468-EBC9D1BB040F}
' Inherited interface = ISymUnmanagedWriter2
' ########################################################################################

#IF NOT %DEF(%ISymUnmanagedWriter3_INTERFACE_DEFINED)
    %ISymUnmanagedWriter3_INTERFACE_DEFINED = 1

INTERFACE ISymUnmanagedWriter3 $IID_ISymUnmanagedWriter3

   INHERIT IAutomation

   ' =====================================================================================
   ' ISymUnmanagedWriter methods
   ' =====================================================================================
   METHOD DefineDocument ( _                            ' VTable offset = 12
     BYREF url AS WSTRINGZ _                            ' __in const WCHAR *url
   , BYREF language AS GUID _                           ' __in const GUID *language
   , BYREF languageVendor AS GUID _                     ' __in const GUID *languageVendor
   , BYREF documentType AS GUID _                       ' __in const GUID *documentType
   ) AS ISymUnmanagedDocumentWriter                     ' __retval_out **pRetVal ISymUnmanagedDocumentWriter <interface>
   ' =====================================================================================
   METHOD SetUserEntryPoint ( _                         ' VTable offset = 16
     BYVAL entryMethod AS DWORD _                       ' __in mdMethodDef entryMethod
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenMethod ( _                                ' VTable offset = 20
     BYVAL method AS DWORD _                            ' __in mdMethodDef method
   )                                                    ' void
   ' =====================================================================================
   METHOD CloseMethod ( _                               ' VTable offset = 24
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenScope ( _                                 ' VTable offset = 28
     BYVAL startOffset AS DWORD _                       ' __in ULONG32 startOffset
   ) AS DWORD                                           ' __retval_out ULONG32 *pRetVal
   ' =====================================================================================
   METHOD CloseScope ( _                                ' VTable offset = 32
     BYVAL endOffset AS DWORD _                         ' __in ULONG32 endOffset
   )                                                    ' void
   ' =====================================================================================
   METHOD SetScopeRange ( _                             ' VTable offset = 36
     BYVAL scopeID AS DWORD _                           ' __in ULONG32 scopeID
   , BYVAL startOffset AS DWORD _                       ' __in ULONG32 startOffset
   , BYVAL endOffset AS DWORD _                         ' __in ULONG32 endOffset
   )                                                    ' void
   ' =====================================================================================
   METHOD DefineLocalVariable ( _                       ' VTable offset = 40
     BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   , BYVAL attributes AS DWORD _                        ' __in ULONG32 attributes
   , BYVAL cSig AS DWORD _                              ' __in ULONG32 cSig
   , BYVAL signature AS BYTE PTR _                      ' __in unsigned char signature[  ]
   , BYVAL addrKind AS DWORD _                          ' __in ULONG32 addrKind
   , BYVAL addr1 AS DWORD _                             ' __in ULONG32 addr1
   , BYVAL addr2 AS DWORD _                             ' __in ULONG32 addr2
   , BYVAL addr3 AS DWORD _                             ' __in ULONG32 addr3
   , BYVAL startOffset AS DWORD _                       ' __in ULONG32 startOffset
   , BYVAL endOffset AS DWORD _                         ' __in ULONG32 endOffset
   )                                                    ' void
   ' =====================================================================================
   METHOD DefineParameter ( _                           ' VTable offset = 44
     BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   , BYVAL attributes AS DWORD _                        ' __in ULONG32 attributes
   , BYVAL sequence AS DWORD _                          ' __in ULONG32 sequence
   , BYVAL addrKind AS DWORD _                          ' __in ULONG32 addrKind
   , BYVAL addr1 AS DWORD _                             ' __in ULONG32 addr1
   , BYVAL addr2 AS DWORD _                             ' __in ULONG32 addr2
   , BYVAL addr3 AS DWORD _                             ' __in ULONG32 addr3
   )                                                    ' void
   ' =====================================================================================
   METHOD DefineField ( _                               ' VTable offset = 48
     BYVAL parent AS DWORD _                            ' __in mdTypeDef parent
   , BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   , BYVAL attributes AS DWORD _                        ' __in ULONG32 attributes
   , BYVAL cSig AS DWORD _                              ' __in ULONG32 cSig
   , BYVAL signature AS BYTE PTR _                      ' __in unsigned char signature[  ]
   , BYVAL addrKind AS DWORD _                          ' __in ULONG32 addrKind
   , BYVAL addr1 AS DWORD _                             ' __in ULONG32 addr1
   , BYVAL addr2 AS DWORD _                             ' __in ULONG32 addr2
   , BYVAL addr3 AS DWORD _                             ' __in ULONG32 addr3
   )                                                    ' void
   ' =====================================================================================
   METHOD DefineGlobalVariable ( _                      ' VTable offset = 52
     BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   , BYVAL attributes AS DWORD _                        ' __in ULONG32 attributes
   , BYVAL cSig AS DWORD _                              ' __in ULONG32 cSig
   , BYVAL signature AS BYTE PTR _                      ' __in unsigned char signature[  ]
   , BYVAL addrKind AS DWORD _                          ' __in ULONG32 addrKind
   , BYVAL addr1 AS DWORD _                             ' __in ULONG32 addr1
   , BYVAL addr2 AS DWORD _                             ' __in ULONG32 addr2
   , BYVAL addr3 AS DWORD _                             ' __in ULONG32 addr3
   )                                                    ' void
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSymAttribute ( _                           ' VTable offset = 60
     BYVAL parent AS DWORD _                            ' __in mdToken parent
   , BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   , BYVAL cData AS DWORD _                             ' __in ULONG32 cData
   , BYVAL data AS BYTE PTR _                           ' __in unsigned char data[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenNamespace ( _                             ' VTable offset = 64
     BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   )                                                    ' void
   ' =====================================================================================
   METHOD CloseNamespace ( _                            ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   METHOD UsingNamespace ( _                            ' VTable offset = 72
     BYREF fullName AS WSTRINGZ _                       ' __in const WCHAR *fullName
   )                                                    ' void
   ' =====================================================================================
   METHOD SetMethodSourceRange ( _                      ' VTable offset = 76
     BYVAL startDoc AS ISymUnmanagedDocumentWriter _    ' __in ISymUnmanagedDocumentWriter *startDoc
   , BYVAL startLine AS DWORD _                         ' __in ULONG32 startLine
   , BYVAL startColumn AS DWORD _                       ' __in ULONG32 startColumn
   , BYVAL endDoc AS ISymUnmanagedDocumentWriter _      ' __in ISymUnmanagedDocumentWriter *endDoc
   , BYVAL endLine AS DWORD _                           ' __in ULONG32 endLine
   , BYVAL endColumn AS DWORD _                         ' __in ULONG32 endColumn
   )                                                    ' void
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 80
     BYVAL emitter AS IUnknown _                        ' __in IUnknown *emitter
   , BYREF filename AS WSTRINGZ _                       ' __in const WCHAR *filename
   , BYVAL pIStream AS IStream _                        ' __in IStream *pIStream
   , BYVAL fFullBuild AS LONG _                         ' __in BOOL fFullBuild
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDebugInfo ( _                              ' VTable offset = 84
     BYREF pIDD AS DWORD _                              ' __inout IMAGE_DEBUG_DIRECTORY *pIDD
   , BYVAL cData AS DWORD _                             ' __in DWORD cData
   , BYREF pcData AS DWORD _                            ' __out DWORD *pcData
   , BYVAL data AS ISymUnmanagedWriter _                ' __out ISymUnmanagedWriter data
   )                                                    ' void
   ' =====================================================================================
   METHOD DefineSequencePoints ( _                      ' VTable offset = 88
     BYVAL document AS ISymUnmanagedDocumentWriter _    ' __in ISymUnmanagedDocumentWriter *document
   , BYVAL spCount AS DWORD _                           ' __in ULONG32 spCount
   , BYREF offsets AS DWORD _                           ' __in ULONG32 *offsets
   , BYREF lines AS DWORD _                             ' __in ULONG32 *lines
   , BYREF columns AS DWORD _                           ' __in ULONG32 *columns
   , BYREF endLines AS DWORD _                          ' __in ULONG32 *endLines
   , BYREF endColumns AS DWORD _                        ' __in ULONG32 *endColumns
   )                                                    ' void
   ' =====================================================================================
   METHOD RemapToken ( _                                ' VTable offset = 92
     BYVAL oldToken AS DWORD _                          ' __in mdToken oldToken
   , BYVAL newToken AS DWORD _                          ' __in mdToken newToken
   )                                                    ' void
   ' =====================================================================================
   METHOD Initialize2 ( _                               ' VTable offset = 96
     BYVAL emitter AS IUnknown _                        ' __in IUnknown *emitter
   , BYREF tempfilename AS WSTRINGZ _                   ' __in const WCHAR *tempfilename
   , BYVAL pIStream AS IStream _                        ' __in IStream *pIStream
   , BYVAL fFullBuild AS LONG _                         ' __in BOOL fFullBuild
   , BYVAL finalfilename AS DWORD _                     ' __in const WCHAR *finalfilename
   )                                                    ' void
   ' =====================================================================================
   METHOD DefineConstant ( _                            ' VTable offset = 100
     BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   , BYVAL value AS VARIANT _                           ' __in VARIANT value
   , BYVAL cSig AS DWORD _                              ' __in ULONG32 cSig
   , BYVAL signature AS BYTE PTR _                      ' __in unsigned char signature[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ISymUnmanagedWriter2 methods
   ' =====================================================================================
   METHOD DefineLocalVariable2 ( _                      ' VTable offset = 108
     BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   , BYVAL attributes AS DWORD _                        ' __in ULONG32 attributes
   , BYVAL sigToken AS DWORD _                          ' __in mdSignature sigToken
   , BYVAL addrKind AS DWORD _                          ' __in ULONG32 addrKind
   , BYVAL addr1 AS DWORD _                             ' __in ULONG32 addr1
   , BYVAL addr2 AS DWORD _                             ' __in ULONG32 addr2
   , BYVAL addr3 AS DWORD _                             ' __in ULONG32 addr3
   , BYVAL startOffset AS DWORD _                       ' __in ULONG32 startOffset
   , BYVAL endOffset AS DWORD _                         ' __in ULONG32 endOffset
   )                                                    ' void
   ' =====================================================================================
   METHOD DefineGlobalVariable2 ( _                     ' VTable offset = 112
     BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   , BYVAL attributes AS DWORD _                        ' __in ULONG32 attributes
   , BYVAL sigToken AS DWORD _                          ' __in mdSignature sigToken
   , BYVAL addrKind AS DWORD _                          ' __in ULONG32 addrKind
   , BYVAL addr1 AS DWORD _                             ' __in ULONG32 addr1
   , BYVAL addr2 AS DWORD _                             ' __in ULONG32 addr2
   , BYVAL addr3 AS DWORD _                             ' __in ULONG32 addr3
   )                                                    ' void
   ' =====================================================================================
   METHOD DefineConstant2 ( _                           ' VTable offset = 116
     BYREF name AS WSTRINGZ _                           ' __in const WCHAR *name
   , BYVAL value AS VARIANT _                           ' __in VARIANT value
   , BYVAL sigToken AS DWORD _                          ' __in mdSignature sigToken
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ISymUnmanagedWriter3 methods
   ' =====================================================================================
   METHOD OpenMethod2 ( _                               ' VTable offset = 120
     BYVAL method AS DWORD _                            ' __in mdMethodDef method
   , BYVAL isect AS DWORD _                             ' __in ULONG32 isect
   , BYVAL offset AS DWORD _                            ' __in ULONG32 offset
   )                                                    ' void
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 124
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISymUnmanagedWriter3_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISymUnmanagedReader2
' IID = {A09E53B2-2A57-4CCA-8F63-B84F7C35D4AA}
' Inherited interface = ISymUnmanagedReader
' ########################################################################################

#IF NOT %DEF(%ISymUnmanagedReader2_INTERFACE_DEFINED)
    %ISymUnmanagedReader2_INTERFACE_DEFINED = 1

INTERFACE ISymUnmanagedReader2 $IID_ISymUnmanagedReader2

   INHERIT IAutomation

   ' =====================================================================================
   ' ISymUnmanagedReader methods
   ' =====================================================================================
   METHOD GetDocument ( _                               ' VTable offset = 12
     BYREF url AS WSTRINGZ _                            ' __in WCHAR *url
   , BYVAL language AS GUID _                           ' __in GUID language
   , BYVAL languageVendor AS GUID _                     ' __in GUID languageVendor
   , BYVAL documentType AS GUID _                       ' __in GUID documentType
   ) AS ISymUnmanagedDocument                           ' __retval_out ISymUnmanagedDocument **pRetVal
   ' =====================================================================================
   METHOD GetDocuments ( _                              ' VTable offset = 16
     BYVAL cDocs AS DWORD _                             ' __in ULONG32 cDocs
   , BYREF pcDocs AS DWORD _                            ' __out ULONG32 *pcDocs
   , BYREF pDocs AS ISymUnmanagedDocument _             ' __out ISymUnmanagedDocument *pDocs[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetUserEntryPoint ( _                         ' VTable offset = 20
   ) AS DWORD                                           ' __retval_out mdMethodDef *pToken
   ' =====================================================================================
   METHOD GetMethod ( _                                 ' VTable offset = 24
     BYVAL token AS DWORD _                             ' __in mdMethodDef token
   ) AS ISymUnmanagedMethod                             ' __retval_out ISymUnmanagedMethod **pRetVal
   ' =====================================================================================
   METHOD GetMethodByVersion ( _                        ' VTable offset = 28
     BYVAL token AS DWORD _                             ' __in mdMethodDef token
   , BYVAL version AS LONG _                            ' __in int version
   ) AS ISymUnmanagedMethod                             ' __retval_out ISymUnmanagedMethod **pRetVal
   ' =====================================================================================
   METHOD GetVariables ( _                              ' VTable offset = 32
     BYVAL parent AS DWORD _                            ' __in mdToken parent
   , BYVAL cVars AS DWORD _                             ' __in ULONG32 cVars
   , BYREF pcVars AS DWORD _                            ' __out ULONG32 *pcVars
   , BYREF pVars AS ISymUnmanagedVariable _             ' __out ISymUnmanagedVariable *pVars[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetGlobalVariables ( _                        ' VTable offset = 36
     BYVAL cVars AS DWORD _                             ' __in ULONG32 cVars
   , BYREF pcVars AS DWORD _                            ' __out ULONG32 *pcVars
   , BYREF pVars AS ISymUnmanagedVariable _             ' __out ISymUnmanagedVariable *pVars[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMethodFromDocumentPosition ( _             ' VTable offset = 40
     BYVAL document AS ISymUnmanagedDocument _          ' __in ISymUnmanagedDocument *document
   , BYVAL line AS DWORD _                              ' __in ULONG32 line
   , BYVAL column AS DWORD _                            ' __in ULONG32 column
   ) AS ISymUnmanagedMethod                             ' __retval_out ISymUnmanagedMethod **pRetVal
   ' =====================================================================================
   METHOD GetSymAttribute ( _                           ' VTable offset = 44
     BYVAL parent AS DWORD _                            ' __in mdToken parent
   , BYREF name AS WSTRINGZ _                           ' __in WCHAR *name
   , BYVAL cBuffer AS DWORD _                           ' __in ULONG32 cBuffer
   , BYREF pcBuffer AS DWORD _                          ' __out ULONG32 *pcBuffer
   , BYVAL buffer AS BYTE PTR _                         ' __out BYTE buffer[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetNamespaces ( _                             ' VTable offset = 48
     BYVAL cNameSpaces AS DWORD _                       ' __in ULONG32 cNameSpaces
   , BYREF pcNameSpaces AS DWORD _                      ' __out ULONG32 *pcNameSpaces
   , BYREF namespaces AS ISymUnmanagedReader _          ' __out ISymUnmanagedNamespace *namespaces[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 52
     BYVAL importer AS IUnknown _                       ' __in IUnknown *importer
   , BYREF filename AS WSTRINGZ _                       ' __in const WCHAR *filename
   , BYREF searchPath AS WSTRINGZ _                     ' __in const WCHAR *searchPath
   , BYVAL pIStream AS IStream _                        ' __in IStream *pIStream
   )                                                    ' void
   ' =====================================================================================
   METHOD UpdateSymbolStore ( _                         ' VTable offset = 56
     BYREF filename AS WSTRINGZ _                       ' __in const WCHAR *filename
   , BYVAL pIStream AS IStream _                        ' __in IStream *pIStream
   )                                                    ' void
   ' =====================================================================================
   METHOD ReplaceSymbolStore ( _                        ' VTable offset = 60
     BYREF filename AS WSTRINGZ _                       ' __in const WCHAR *filename
   , BYVAL pIStream AS IStream _                        ' __in IStream *pIStream
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSymbolStoreFileName ( _                    ' VTable offset = 64
     BYVAL cchName AS DWORD _                           ' __in ULONG32 cchName
   , BYREF pcchName AS DWORD _                          ' __out ULONG32 *pcchName
   , BYREF szName AS DWORD _                            ' __out szName WCHAR szName[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMethodsFromDocumentPosition ( _            ' VTable offset = 68
     BYVAL document AS ISymUnmanagedDocument _          ' __in ISymUnmanagedDocument *document
   , BYVAL line AS DWORD _                              ' __in ULONG32 line
   , BYVAL column AS DWORD _                            ' __in ULONG32 column
   , BYVAL cMethod AS DWORD _                           ' __in ULONG32 cMethod
   , BYREF pcMethod AS DWORD _                          ' __out ULONG32 *pcMethod
   , BYREF pRetVal AS ISymUnmanagedReader _             ' __out pRetVal ISymUnmanagedMethod *pRetVal[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDocumentVersion ( _                        ' VTable offset = 72
     BYVAL pDoc AS ISymUnmanagedDocument _              ' __in ISymUnmanagedDocument *pDoc
   , BYREF version AS LONG _                            ' __out int *version
   , BYREF pbCurrent AS LONG _                          ' __out BOOL *pbCurrent
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMethodVersion ( _                          ' VTable offset = 76
     BYVAL pMethod AS ISymUnmanagedMethod _             ' __in ISymUnmanagedMethod *pMethod
   , BYREF version AS LONG _                            ' __out int *version
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ISymUnmanagedReader2 methods
   ' =====================================================================================
   METHOD GetMethodByVersionPreRemap ( _                ' VTable offset = 80
     BYVAL token AS DWORD _                             ' __in mdMethodDef token
   , BYVAL version AS LONG _                            ' __in int version
   ) AS ISymUnmanagedMethod                             ' __retval_out ISymUnmanagedMethod **pRetVal
   ' =====================================================================================
   METHOD GetSymAttributePreRemap ( _                   ' VTable offset = 84
     BYVAL parent AS DWORD _                            ' __in mdToken parent
   , BYREF name AS WSTRINGZ _                           ' __in WCHAR *name
   , BYVAL cBuffer AS DWORD _                           ' __in ULONG32 cBuffer
   , BYREF pcBuffer AS DWORD _                          ' __out ULONG32 *pcBuffer
   , BYVAL buffer AS BYTE PTR _                         ' __out BYTE buffer[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMethodsInDocument ( _                      ' VTable offset = 88
     BYVAL document AS ISymUnmanagedDocument _          ' __in ISymUnmanagedDocument *document
   , BYVAL cMethod AS DWORD _                           ' __in ULONG32 cMethod
   , BYREF pcMethod AS DWORD _                          ' __out ULONG32 *pcMethod
   , BYREF pRetVal AS ISymUnmanagedMethod _             ' __out ISymUnmanagedMethod *pRetVal[  ]
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISymUnmanagedReader2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISymNGenWriter
' IID = v
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISymNGenWriter_INTERFACE_DEFINED)
    %ISymNGenWriter_INTERFACE_DEFINED = 1

INTERFACE ISymNGenWriter $IID_ISymNGenWriter

   INHERIT IAutomation

   ' =====================================================================================
   METHOD AddSymbol ( _                                 ' VTable offset = 12
     BYVAL pSymbol AS WSTRING _¨                        ' __in BSTR pSymbol
   , BYVAL iSection AS WORD _                           ' __in USHORT iSection
   , BYVAL rva AS QUAD _                                ' __in ULONGLONG rva
   )                                                    ' void
   ' =====================================================================================
   METHOD AddSection ( _                                ' VTable offset = 16
     BYVAL iSection AS WORD _                           ' __in USHORT iSection
   , BYVAL flags AS WORD _                              ' __in USHORT flags
   , BYVAL offset AS LONG _                             ' __in long offset
   , BYVAL cb AS LONG _                                 ' __in long cb
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISymNGenWriter_INTERFACE_DEFINED__ */
