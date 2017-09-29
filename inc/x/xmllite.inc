' ########################################################################################
' Microsoft Windows
' File: xmllite.inc
' Contents: Lightweight XML parser
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%XMLLITE_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "oaidl.inc"

'////////////////////////////////////////////////////////////////////////////////////////////////////////////
'// XmlReader Constructors

DECLARE FUNCTION CreateXmlReader IMPORT "XMLLITE.DLL" ALIAS "CreateXmlReader" ( _
   BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppvObject AS IUnknown _                        ' __out void ** ppvObject
 , OPTIONAL BYVAL pMalloc AS IMalloc _                  ' __in_opt IMalloc * pMalloc
 ) AS LONG                                              ' HRESULT

'////////////////////////////////////////////////////////////////////////////////////////////////////////////
'// XmlReaderInput Constructors

DECLARE FUNCTION CreateXmlReaderInputWithEncodingCodePage IMPORT "XMLLITE.DLL" ALIAS "CreateXmlReaderInputWithEncodingCodePage" ( _
   BYVAL pInputStream AS IUnknown _                     ' __in IUnknown * pInputStream
 , BYVAL pMalloc AS IMalloc _                           ' __in_opt IMalloc * pMalloc
 , BYVAL nEncodingCodePage AS DWORD _                   ' __in UINT nEncodingCodePage
 , BYVAL fEncodingHint AS LONG _                        ' __in BOOL fEncodingHint
 , BYREF pwszBaseUri AS WSTRINGZ _                      ' __in_opt LPCWSTR pwszBaseUri
 , BYREF ppInput AS IUnknown _                          ' __out IXmlReaderInput ** ppInput
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateXmlReaderInputWithEncodingName IMPORT "XMLLITE.DLL" ALIAS "CreateXmlReaderInputWithEncodingName" ( _
   BYVAL pInputStream AS IUnknown _                     ' __in IUnknown * pInputStream
 , BYVAL pMalloc AS IMalloc _                           ' __in_opt IMalloc * pMalloc
 , BYREF pwszEncodingName AS WSTRINGZ _                 ' __in LPCWSTR pwszEncodingName
 , BYVAL fEncodingHint AS LONG _                        ' __in BOOL fEncodingHint
 , BYREF pwszBaseUri AS WSTRINGZ _                      ' __in_opt LPCWSTR pwszBaseUri
 , BYREF ppInput AS IUnknown _                          ' __out IXmlReaderInput ** ppInput
 ) AS LONG                                              ' HRESULT

'////////////////////////////////////////////////////////////////////////////////////////////////////////////
'// XmlWriter Constructors

DECLARE FUNCTION CreateXmlWriter IMPORT "XMLLITE.DLL" ALIAS "CreateXmlWriter" ( _
   BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppvObject AS IUnknown _                        ' __out void ** ppvObject
 , OPTIONAL BYVAL pMalloc AS IMalloc _                  ' __in_opt IMalloc * pMalloc
 ) AS LONG                                              ' HRESULT

'////////////////////////////////////////////////////////////////////////////////////////////////////////////
'// XmlWriterOutput Constructors

DECLARE FUNCTION CreateXmlWriterOutputWithEncodingCodePage IMPORT "XMLLITE.DLL" ALIAS "CreateXmlWriterOutputWithEncodingCodePage" ( _
   BYVAL pOutputStream AS IUnknown _                    ' __in IUnknown *pOutputStream
 , BYVAL pMalloc AS IMalloc _                           ' __in_opt IMalloc *pMalloc
 , BYVAL nEncodingCodePage AS DWORD _                   ' __in UINT nEncodingCodePage
 , BYREF ppOutput AS IUnknown _                         ' __out IXmlWriterOutput **ppOutput
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateXmlWriterOutputWithEncodingName IMPORT "XMLLITE.DLL" ALIAS "CreateXmlWriterOutputWithEncodingName" ( _
   BYVAL pOutputStream AS IUnknown _                    ' __in IUnknown *pOutputStream
 , BYVAL pMalloc AS IMalloc _                           ' __in_opt IMalloc *pMalloc
 , BYREF pwszEncodingName AS WSTRINGZ _                 ' __in LPCWSTR pwszEncodingName
 , BYREF ppOutput AS IUnknown _                         ' __out IXmlWriterOutput **ppOutput
 ) AS LONG                                              ' HRESULT

' XmlNodeType enum
%XmlNodeType_None                  = 0
%XmlNodeType_Element               = 1
%XmlNodeType_Attribute             = 2
%XmlNodeType_Text                  = 3
%XmlNodeType_CDATA                 = 4
%XmlNodeType_ProcessingInstruction = 7
%XmlNodeType_Comment               = 8
%XmlNodeType_DocumentType          = 10
%XmlNodeType_Whitespace            = 13
%XmlNodeType_EndElement            = 15
%XmlNodeType_XmlDeclaration        = 17
'_XmlNodeType_Last                  = 17

' XmlConformanceLevel enum
%XmlConformanceLevel_Auto     = 0
%XmlConformanceLevel_Fragment = 1
%XmlConformanceLevel_Document = 2
'_XmlConformanceLevel_Last     = 2

' DtdProcessing enum
%DtdProcessing_Prohibit   = 0
%DtdProcessing_Parse      = %DtdProcessing_Prohibit + 1
'_DtdProcessing_Last       = %DtdProcessing_Parse

' XmlReadState enum
%XmlReadState_Initial     = 0
%XmlReadState_Interactive = 1
%XmlReadState_Error       = 2
%XmlReadState_EndOfFile   = 3
%XmlReadState_Closed      = 4

' XmlReaderProperty enum
%XmlReaderProperty_MultiLanguage      = 0
%XmlReaderProperty_ConformanceLevel   = %XmlReaderProperty_MultiLanguage    + 1
%XmlReaderProperty_RandomAccess       = %XmlReaderProperty_ConformanceLevel + 1
%XmlReaderProperty_XmlResolver        = %XmlReaderProperty_RandomAccess     + 1
%XmlReaderProperty_DtdProcessing      = %XmlReaderProperty_XmlResolver      + 1
%XmlReaderProperty_ReadState          = %XmlReaderProperty_DtdProcessing    + 1
%XmlReaderProperty_MaxElementDepth    = %XmlReaderProperty_ReadState        + 1
%XmlReaderProperty_MaxEntityExpansion = %XmlReaderProperty_MaxElementDepth  + 1
'_XmlReaderProperty_Last               = %XmlReaderProperty_MaxEntityExpansion

' XmlError enum
%MX_E_MX                     = &Hc00cee00&
%MX_E_INPUTEND               = (%MX_E_MX                     + 1)
%MX_E_ENCODING               = (%MX_E_INPUTEND               + 1)
%MX_E_ENCODINGSWITCH         = (%MX_E_ENCODING               + 1)
%MX_E_ENCODINGSIGNATURE      = (%MX_E_ENCODINGSWITCH         + 1)
%WC_E_WC                     = &Hc00cee20&
%WC_E_WHITESPACE             = (%WC_E_WC                     + 1)
%WC_E_SEMICOLON              = (%WC_E_WHITESPACE             + 1)
%WC_E_GREATERTHAN            = (%WC_E_SEMICOLON              + 1)
%WC_E_QUOTE                  = (%WC_E_GREATERTHAN            + 1)
%WC_E_EQUAL                  = (%WC_E_QUOTE                  + 1)
%WC_E_LESSTHAN               = (%WC_E_EQUAL                  + 1)
%WC_E_HEXDIGIT               = (%WC_E_LESSTHAN               + 1)
%WC_E_DIGIT                  = (%WC_E_HEXDIGIT               + 1)
%WC_E_LEFTBRACKET            = (%WC_E_DIGIT                  + 1)
%WC_E_LEFTPAREN              = (%WC_E_LEFTBRACKET            + 1)
%WC_E_XMLCHARACTER           = (%WC_E_LEFTPAREN              + 1)
%WC_E_NAMECHARACTER          = (%WC_E_XMLCHARACTER           + 1)
%WC_E_SYNTAX                 = (%WC_E_NAMECHARACTER          + 1)
%WC_E_CDSECT                 = (%WC_E_SYNTAX                 + 1)
%WC_E_COMMENT                = (%WC_E_CDSECT                 + 1)
%WC_E_CONDSECT               = (%WC_E_COMMENT                + 1)
%WC_E_DECLATTLIST            = (%WC_E_CONDSECT               + 1)
%WC_E_DECLDOCTYPE            = (%WC_E_DECLATTLIST            + 1)
%WC_E_DECLELEMENT            = (%WC_E_DECLDOCTYPE            + 1)
%WC_E_DECLENTITY             = (%WC_E_DECLELEMENT            + 1)
%WC_E_DECLNOTATION           = (%WC_E_DECLENTITY             + 1)
%WC_E_NDATA                  = (%WC_E_DECLNOTATION           + 1)
%WC_E_PUBLIC                 = (%WC_E_NDATA                  + 1)
%WC_E_SYSTEM                 = (%WC_E_PUBLIC                 + 1)
%WC_E_NAME                   = (%WC_E_SYSTEM                 + 1)
%WC_E_ROOTELEMENT            = (%WC_E_NAME                   + 1)
%WC_E_ELEMENTMATCH           = (%WC_E_ROOTELEMENT            + 1)
%WC_E_UNIQUEATTRIBUTE        = (%WC_E_ELEMENTMATCH           + 1)
%WC_E_TEXTXMLDECL            = (%WC_E_UNIQUEATTRIBUTE        + 1)
%WC_E_LEADINGXML             = (%WC_E_TEXTXMLDECL            + 1)
%WC_E_TEXTDECL               = (%WC_E_LEADINGXML             + 1)
%WC_E_XMLDECL                = (%WC_E_TEXTDECL               + 1)
%WC_E_ENCNAME                = (%WC_E_XMLDECL                + 1)
%WC_E_PUBLICID               = (%WC_E_ENCNAME                + 1)
%WC_E_PESINTERNALSUBSET      = (%WC_E_PUBLICID               + 1)
%WC_E_PESBETWEENDECLS        = (%WC_E_PESINTERNALSUBSET      + 1)
%WC_E_NORECURSION            = (%WC_E_PESBETWEENDECLS        + 1)
%WC_E_ENTITYCONTENT          = (%WC_E_NORECURSION            + 1)
%WC_E_UNDECLAREDENTITY       = (%WC_E_ENTITYCONTENT          + 1)
%WC_E_PARSEDENTITY           = (%WC_E_UNDECLAREDENTITY       + 1)
%WC_E_NOEXTERNALENTITYREF    = (%WC_E_PARSEDENTITY           + 1)
%WC_E_PI                     = (%WC_E_NOEXTERNALENTITYREF    + 1)
%WC_E_SYSTEMID               = (%WC_E_PI                     + 1)
%WC_E_QUESTIONMARK           = (%WC_E_SYSTEMID               + 1)
%WC_E_CDSECTEND              = (%WC_E_QUESTIONMARK           + 1)
%WC_E_MOREDATA               = (%WC_E_CDSECTEND              + 1)
%WC_E_DTDPROHIBITED          = (%WC_E_MOREDATA               + 1)
%WC_E_INVALIDXMLSPACE        = (%WC_E_DTDPROHIBITED          + 1)
%NC_E_NC                     = &Hc00cee60&
%NC_E_QNAMECHARACTER         = (%NC_E_NC                     + 1)
%NC_E_QNAMECOLON             = (%NC_E_QNAMECHARACTER         + 1)
%NC_E_NAMECOLON              = (%NC_E_QNAMECOLON             + 1)
%NC_E_DECLAREDPREFIX         = (%NC_E_NAMECOLON              + 1)
%NC_E_UNDECLAREDPREFIX       = (%NC_E_DECLAREDPREFIX         + 1)
%NC_E_EMPTYURI               = (%NC_E_UNDECLAREDPREFIX       + 1)
%NC_E_XMLPREFIXRESERVED      = (%NC_E_EMPTYURI               + 1)
%NC_E_XMLNSPREFIXRESERVED    = (%NC_E_XMLPREFIXRESERVED      + 1)
%NC_E_XMLURIRESERVED         = (%NC_E_XMLNSPREFIXRESERVED    + 1)
%NC_E_XMLNSURIRESERVED       = (%NC_E_XMLURIRESERVED         + 1)
%SC_E_SC                     = &Hc00cee80&
%SC_E_MAXELEMENTDEPTH        = (%SC_E_SC                     + 1)
%SC_E_MAXENTITYEXPANSION     = (%SC_E_MAXELEMENTDEPTH        + 1)
%WR_E_WR                     = &Hc00cef00&
%WR_E_NONWHITESPACE          = (%WR_E_WR                     + 1)
%WR_E_NSPREFIXDECLARED       = (%WR_E_NONWHITESPACE          + 1)
%WR_E_NSPREFIXWITHEMPTYNSURI = (%WR_E_NSPREFIXDECLARED       + 1)
%WR_E_DUPLICATEATTRIBUTE     = (%WR_E_NSPREFIXWITHEMPTYNSURI + 1)
%WR_E_XMLNSPREFIXDECLARATION = (%WR_E_DUPLICATEATTRIBUTE     + 1)
%WR_E_XMLPREFIXDECLARATION   = (%WR_E_XMLNSPREFIXDECLARATION + 1)
%WR_E_XMLURIDECLARATION      = (%WR_E_XMLPREFIXDECLARATION   + 1)
%WR_E_XMLNSURIDECLARATION    = (%WR_E_XMLURIDECLARATION      + 1)
%WR_E_NAMESPACEUNDECLARED    = (%WR_E_XMLNSURIDECLARATION    + 1)
%WR_E_INVALIDXMLSPACE        = (%WR_E_NAMESPACEUNDECLARED    + 1)
%WR_E_INVALIDACTION          = (%WR_E_INVALIDXMLSPACE        + 1)
%WR_E_INVALIDSURROGATEPAIR   = (%WR_E_INVALIDACTION          + 1)
%XML_E_INVALID_DECIMAL       = &Hc00ce01d&
%XML_E_INVALID_HEXIDECIMAL   = &Hc00ce01e&
%XML_E_INVALID_UNICODE       = &Hc00ce01f&
%XML_E_INVALIDENCODING       = &Hc00ce06e&

' XmlStandalone enum
%XmlStandalone_Omit = 0
%XmlStandalone_Yes  = 1
%XmlStandalone_No   = 2
'_XmlStandalone_Last = 2

' XmlWriterProperty enum
%XmlWriterProperty_MultiLanguage      = 0
%XmlWriterProperty_Indent             = (%XmlWriterProperty_MultiLanguage      + 1)
%XmlWriterProperty_ByteOrderMark      = (%XmlWriterProperty_Indent             + 1)
%XmlWriterProperty_OmitXmlDeclaration = (%XmlWriterProperty_ByteOrderMark      + 1)
%XmlWriterProperty_ConformanceLevel   = (%XmlWriterProperty_OmitXmlDeclaration + 1)
'_XmlWriterProperty_Last   = %XmlWriterProperty_OmitXmlDeclaration


' ########################################################################################
' Interface name = IXmlReader
' IID = 7279FC81-709D-4095-B63D-69FE4B0D9030
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXmlReader_INTERFACE_DEFINED)
    %IXmlReader_INTERFACE_DEFINED = 1

$IID_IXmlReader = GUID$("{7279FC81-709D-4095-B63D-69FE4B0D9030}")

INTERFACE IXmlReader $IID_IXmlReader

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetInput ( _                                  ' VTable offset = 12
     OPTIONAL BYVAL pInput AS IUnknown _                ' __in_opt IUnknown *pInput
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 16
     BYVAL nProperty AS DWORD _                         ' __in UINT nProperty
   , BYREF ppValue AS LONG _                            ' __out LONG_PTR *ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProperty ( _                               ' VTable offset = 20
     BYVAL nProperty AS DWORD _                         ' __in UINT nProperty
   , OPTIONAL BYVAL pValue AS LONG _                    ' __in_opt LONG_PTR pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Read ( _                                      ' VTable offset = 24
     OPTIONAL BYREF pNodeType AS LONG _                 ' __out_opt XmlNodeType *pNodeType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNodeType ( _                               ' VTable offset = 28
     BYREF pNodeType AS LONG _                          ' __out XmlNodeType *pNodeType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MoveToFirstAttribute ( _                      ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MoveToNextAttribute ( _                       ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MoveToAttributeByName ( _                     ' VTable offset = 40
     BYREF pwszLocalName AS WSTRINGZ _                  ' __in LPCWSTR pwszLocalName
   , OPTIONAL BYREF pwszNamespaceUri AS WSTRINGZ _      ' __in_opt LPCWSTR pwszNamespaceUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MoveToElement ( _                             ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetQualifiedName ( _                          ' VTable offset = 48
     BYREF ppwszQualifiedName AS DWORD _                ' __out LPCWSTR *ppwszQualifiedName
   , OPTIONAL BYREF pcwchQualifiedName AS DWORD _       ' __out_opt UINT *pcwchQualifiedName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNamespaceUri ( _                           ' VTable offset = 52
     BYREF ppwszNamespaceUri AS DWORD _                 ' __out LPCWSTR *ppwszNamespaceUri
   , OPTIONAL BYREF pcwchNamespaceUri AS DWORD _        ' __out_opt UINT *pcwchNamespaceUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLocalName ( _                              ' VTable offset = 56
     BYREF ppwszLocalName AS DWORD _                    ' __out LPCWSTR *ppwszLocalName
   , OPTIONAL BYREF pcwchLocalName AS DWORD _           ' __out_opt UINT *pcwchLocalName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrefix ( _                                 ' VTable offset = 60
     BYREF ppwszPrefix AS DWORD _                       ' __out LPCWSTR *ppwszPrefix
   , OPTIONAL BYREF pcwchPrefix AS DWORD _              ' __out_opt UINT *pcwchPrefix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 64
     BYREF ppwszValue AS DWORD _                        ' __out LPCWSTR *ppwszValue
   , OPTIONAL BYREF pcwchValue AS DWORD _               ' __out_opt UINT *pcwchValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReadValueChunk ( _                            ' VTable offset = 68
     BYREF pwchBuffer AS DWORD _                        ' __out_ecount_part(cwchChunkSize, *pcwchRead)  WCHAR *pwchBuffer
   , BYVAL cwchChunkSize AS DWORD _                     ' __in UINT cwchChunkSize
   , BYREF pcwchRead AS DWORD _                         ' __inout UINT *pcwchRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBaseUri ( _                                ' VTable offset = 72
     BYREF ppwszBaseUri AS DWORD _                      ' __out LPCWSTR *ppwszBaseUri
   , OPTIONAL BYREF pcwchBaseUri AS DWORD _             ' __out_opt UINT *pcwchBaseUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDefault ( _                                 ' VTable offset = 76
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD IsEmptyElement ( _                            ' VTable offset = 80
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD GetLineNumber ( _                             ' VTable offset = 84
     BYREF pnLineNumber AS DWORD _                      ' __out UINT *pnLineNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLinePosition ( _                           ' VTable offset = 88
     BYREF pnLinePosition AS DWORD _                    ' __out UINT *pnLinePosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttributeCount ( _                         ' VTable offset = 92
     BYREF pnAttributeCount AS DWORD _                  ' __out UINT *pnAttributeCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDepth ( _                                  ' VTable offset = 96
     BYREF pnDepth AS DWORD _                           ' __out UINT *pnDepth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsEOF ( _                                     ' VTable offset = 100
   ) AS LONG                                            ' BOOL
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXmlReader_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IXmlResolver
' IID = 7279FC82-709D-4095-B63D-69FE4B0D9030
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXmlResolver_INTERFACE_DEFINED)
    %IXmlResolver_INTERFACE_DEFINED = 1

$IID_IXmlResolver = GUID$("{7279FC82-709D-4095-B63D-69FE4B0D9030}")

INTERFACE IXmlResolver $IID_IXmlResolver

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ResolveUri ( _                                ' VTable offset = 12
     BYREF pwszBaseUri AS WSTRINGZ _                    ' __in_opt LPCWSTR pwszBaseUri
   , BYREF pwszPublicIdentifier AS WSTRINGZ _           ' __in_opt LPCWSTR pwszPublicIdentifier
   , BYREF pwszSystemIdentifier AS WSTRINGZ _           ' __in_opt LPCWSTR pwszSystemIdentifier
   , BYREF ppResolvedInput AS IUnknown _                ' __out IUnknown **ppResolvedInput
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXmlResolver_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IXmlWriter
' IID = 7279FC88-709D-4095-B63D-69FE4B0D9030
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXmlWriter_INTERFACE_DEFINED)
    %IXmlWriter_INTERFACE_DEFINED = 1

$IID_IXmlWriter = GUID$("{7279FC88-709D-4095-B63D-69FE4B0D9030}")

INTERFACE IXmlWriter $IID_IXmlWriter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetOutput ( _                                 ' VTable offset = 12
     OPTIONAL BYVAL pOutput AS IUnknown _               ' __in_opt IUnknown *pOutput
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 16
     BYVAL nProperty AS DWORD _                         ' __in UINT nProperty
   , BYREF ppValue AS LONG _                            ' __out LONG_PTR *ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProperty ( _                               ' VTable offset = 20
     BYVAL nProperty AS DWORD _                         ' __in UINT nProperty
   , OPTIONAL BYVAL pValue AS LONG _                    ' __in_opt LONG_PTR pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteAttributes ( _                           ' VTable offset = 24
     BYVAL pReader AS IXmlReader _                      ' __in IXmlReader *pReader
   , BYVAL fWriteDefaultAttributes AS LONG _            ' __in BOOL fWriteDefaultAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteAttributeString ( _                      ' VTable offset = 28
     OPTIONAL BYREF pwszPrefix AS WSTRINGZ _            ' __in_opt LPCWSTR pwszPrefix
   , OPTIONAL BYREF pwszLocalName AS WSTRINGZ _         ' __in_opt LPCWSTR pwszLocalName
   , OPTIONAL BYREF pwszNamespaceUri AS WSTRINGZ _      ' __in_opt LPCWSTR pwszNamespaceUri
   , OPTIONAL BYREF pwszValue AS WSTRINGZ _             ' __in_opt LPCWSTR pwszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteCData ( _                                ' VTable offset = 32
     OPTIONAL BYREF pwszText AS WSTRINGZ _              ' __in_opt LPCWSTR pwszText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteCharEntity ( _                           ' VTable offset = 36
     BYVAL wch AS DWORD _                               ' __in WCHAR wch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteChars ( _                                ' VTable offset = 40
     BYVAL pwch AS DWORD _                              ' __in_ecount_opt(cwch)  const WCHAR *pwch
   , BYVAL cwch AS DWORD _                              ' __in UINT cwch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteComment ( _                              ' VTable offset = 44
     OPTIONAL BYREF pwszComment AS WSTRINGZ _           ' __in_opt LPCWSTR pwszComment
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteDocType ( _                              ' VTable offset = 48
     OPTIONAL BYREF pwszName AS WSTRINGZ _              ' __in_opt LPCWSTR pwszName
   , OPTIONAL BYREF pwszPublicId AS WSTRINGZ _          ' __in_opt LPCWSTR pwszPublicId
   , OPTIONAL BYREF pwszSystemId AS WSTRINGZ _          ' __in_opt LPCWSTR pwszSystemId
   , OPTIONAL BYREF pwszSubset AS WSTRINGZ _            ' __in_opt LPCWSTR pwszSubset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteElementString ( _                        ' VTable offset = 52
     BYREF pwszPrefix AS WSTRINGZ _                     ' __in_opt LPCWSTR pwszPrefix
   , BYREF pwszLocalName AS WSTRINGZ _                  ' __in LPCWSTR pwszLocalName
   , OPTIONAL BYREF pwszNamespaceUri AS WSTRINGZ _      ' __in_opt LPCWSTR pwszNamespaceUri
   , OPTIONAL BYREF pwszValue AS WSTRINGZ _             ' __in_opt LPCWSTR pwszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteEndDocument ( _                          ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteEndElement ( _                           ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteEntityRef ( _                            ' VTable offset = 64
     BYREF pwszName AS WSTRINGZ _                       ' __in LPCWSTR pwszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteFullEndElement ( _                       ' VTable offset = 68
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteName ( _                                 ' VTable offset = 72
     BYREF pwszName AS WSTRINGZ _                       ' __in LPCWSTR pwszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteNmToken ( _                              ' VTable offset = 76
     BYREF pwszNmToken AS WSTRINGZ _                    ' __in LPCWSTR pwszNmToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteNode ( _                                 ' VTable offset = 80
     BYVAL pReader AS IXmlReader _                      ' __in IXmlReader *pReader
   , BYVAL fWriteDefaultAttributes AS LONG _            ' __in BOOL fWriteDefaultAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteNodeShallow ( _                          ' VTable offset = 84
     BYVAL pReader AS IXmlReader _                      ' __in IXmlReader *pReader
   , BYVAL fWriteDefaultAttributes AS LONG _            ' __in BOOL fWriteDefaultAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteProcessingInstruction ( _                ' VTable offset = 88
     BYREF pwszName AS WSTRINGZ _                       ' __in LPCWSTR pwszName
   , OPTIONAL BYREF pwszText AS WSTRINGZ _              ' __in_opt LPCWSTR pwszText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteQualifiedName ( _                        ' VTable offset = 92
     BYREF pwszLocalName AS WSTRINGZ _                  ' __in LPCWSTR pwszLocalName
   , OPTIONAL BYREF pwszNamespaceUri AS WSTRINGZ _      ' __in_opt LPCWSTR pwszNamespaceUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteRaw ( _                                  ' VTable offset = 96
     OPTIONAL BYREF pwszData AS WSTRINGZ _              ' __in_opt LPCWSTR pwszData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteRawChars ( _                             ' VTable offset = 100
     BYREF pwch AS WSTRINGZ _                           ' __in_ecount_opt(cwch) const WCHAR *pwch
   , BYVAL cwch AS DWORD _                              ' __in UINT cwch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteStartDocument ( _                        ' VTable offset = 104
     BYVAL standalone AS LONG _                         ' __in XmlStandalone standalone
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteStartElement ( _                         ' VTable offset = 108
     BYREF pwszPrefix AS WSTRINGZ _                     ' __in_opt LPCWSTR pwszPrefix
   , BYREF pwszLocalName AS WSTRINGZ _                  ' __in LPCWSTR pwszLocalName
   , OPTIONAL BYREF pwszNamespaceUri AS WSTRINGZ _      ' __in_opt LPCWSTR pwszNamespaceUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteString ( _                               ' VTable offset = 112
     OPTIONAL BYREF pwszText AS WSTRINGZ _              ' __in_opt LPCWSTR pwszText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteSurrogateCharEntity ( _                  ' VTable offset = 116
     BYVAL wchLow AS DWORD _                            ' __in WCHAR wchLow
   , BYVAL wchHigh AS DWORD _                           ' __in WCHAR wchHigh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteWhitespace ( _                           ' VTable offset = 120
     OPTIONAL BYREF pwszWhitespace AS WSTRINGZ _        ' __in_opt LPCWSTR pwszWhitespace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Flush ( _                                     ' VTable offset = 124
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXmlWriter_INTERFACE_DEFINED__ */
