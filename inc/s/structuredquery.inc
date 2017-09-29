' ########################################################################################
' Microsoft Windows
' File: StructuredQuery.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%STRUCTUREDQUERY_INC = 1

'/*
'    STRUCTURED QUERY

'    Overview:

'    The main purpose of Structured Query is to parse an input string that adheres
'    to Advanced Query Syntax (AQS) or Natural Query Syntax (NQS) and produce a
'    parse tree (known as a condition tree) from which a database or index can conveniently
'    be queried. (Note that NQS includes AQS as a subset, and AQS incorporates plain keyword
'    search as a special case.) AQS and NQS allow expressing basic queries over properties,
'    such as whether the value of a string property contains a certain word or whether
'    the value of a numeric property is greater than some constant value, optionally
'    connected by AND, OR and NOT.

'    The minimum preparation for parsing queries is to create an IQueryParser,
'    and give it a schema binary and an LCID. The result is an IQuerySolution object,
'    which encompasses all available information about the query: the query string,
'    how it was tokenized, and a condition tree in the form of an ICondition.

'    The schema binary contains a representation of the application schema (basically
'    what properties there are to query over and some information about them such as
'    types) and a mapping from words and phrases to these properties. One can use a
'    trivial schema, which enables the AND, OR and NOT of primitive queries, but the
'    primitive queries can then not be over any specific properties.

'    An IQueryParser holds a very small state between queries, basically a loaded schema
'    which typically requires 100-150KB of memory. However, it also holds a reference to
'    some word breaker object, which may have a substantially larger state.

'    Query times are typically under 1ms.

'    Expected scenarios:

'    1. Wordwheeling -- The application invokes IQueryParser::Parse for each character
'                       typed and uses the resulting ICondition to create a query which
'                       is run to update a set of results to reflect the current input
'                       string. Typically, the application would turn on the "automatic
'                       wildcard" option so that (partial) words typed will match contents
'                       that begin with these words.

'    2. Type query, press enter --
'                       As above but the user has to actively state when to actually
'                       processa query (such as hitting Enter or clicking a button).
'                       An application may still choose to use "automatic wildcard" but
'                       the benefits are less clear.

'    3. "Query builder" --
'                    a. Input string -> query tree
'                       Pass a query string from the user to IQueryParser::Parse and use
'                       the resulting condition tree to render a graphical representation
'                       of the query. If this graphical representation is not editable,
'                       it serves simply as an explanation to the user how the input string
'                       was interpreted. If is it editable, one may think of the input
'                       string as a way or priming the query builder.

'                    b. Just a query tree
'                       ICondition is useful on its own even if not parsed from AQS or
'                       NQS strings. An IConditionFactory object can be created to build
'                       condition trees (and every IQuerySolution is also an
'                       IConditionFactory).

'                    c. Semantic canvas (two way editing)
'                       This is like alternative a above but not only is the graphical
'                       representation editable, whenever it is edited, the query string
'                       is updated to reflect the new query. Thus, whenever the query string
'                       or the graphical query is edited, the other is updated.

'    API conventions:

'    Any method will return E_INVALIDARG if some input argument is NULL, unless explicitly
'    permitted.

'    Any method will return E_POINTER if some output or input/output argument is NULL,
'    unless explicitly permitted.

'    For any output argument that inherits from IUnknown, the caller must eventually free it
'    using IUnknown::Release.

'    For any output argument of type LPWSTR, the caller must eventually free it using
'    CoTaskMemFree.

'    For any output argument of type PROPVARIANT, it is expected to be uninitialized before the call
'    and after a successful return, the caller must eventually clear it using PropVariantClear.
'*/

' ########################################################################################
' Library name: StructuredQuery1
' Version: 1.0, Locale ID = 0
' Library GUID: {1352FA67-2022-41DF-9D6F-943A5EE97C9F}
' ########################################################################################

'/* header files for imported files */
#INCLUDE ONCE "StructuredQueryCondition.inc"
#INCLUDE ONCE "ObjectArray.inc"
#INCLUDE ONCE "propkeydef.inc"

$LIBID_StructuredQuery1   = GUID$("{1352FA67-2022-41df-9D6F-943A5EE97C9F}")

$CLSID_QueryParser        = GUID$("{B72F8FD8-0FAB-4DD9-BDBF-245A6CE1485B}")
$CLSID_NegationCondition  = GUID$("{8DE9C74C-605A-4ACD-BEE3-2B222AA2D23D}")
$CLSID_CompoundCondition  = GUID$("{116F8D13-101E-4FA5-84D4-FF8279381935}")
$CLSID_LeafCondition      = GUID$("{52F15C89-5A17-48E1-BBCD-46A3F89C7CC2}")
$CLSID_ConditionFactory   = GUID$("{E03E85B0-7BE3-4000-BA98-6C13DE9FA486}")
$CLSID_Interval           = GUID$("{D957171F-4BF9-4DE2-BCD5-C70A7CA55836}")
$CLSID_QueryParserManager = GUID$("{5088B39A-29B4-4D9D-8245-4EE289222F66}")

' enum STRUCTURED_QUERY_SYNTAX
%SQS_NO_SYNTAX             = 0
%SQS_ADVANCED_QUERY_SYNTAX = %SQS_NO_SYNTAX             + 1
%SQS_NATURAL_QUERY_SYNTAX  = %SQS_ADVANCED_QUERY_SYNTAX + 1

' enum STRUCTURED_QUERY_SINGLE_OPTION
%SQSO_SCHEMA               = 0
%SQSO_LOCALE_WORD_BREAKING = %SQSO_SCHEMA               + 1
%SQSO_WORD_BREAKER         = %SQSO_LOCALE_WORD_BREAKING + 1
%SQSO_NATURAL_SYNTAX       = %SQSO_WORD_BREAKER         + 1
%SQSO_AUTOMATIC_WILDCARD   = %SQSO_NATURAL_SYNTAX       + 1
%SQSO_TRACE_LEVEL          = %SQSO_AUTOMATIC_WILDCARD   + 1
%SQSO_LANGUAGE_KEYWORDS    = %SQSO_TRACE_LEVEL          + 1
%SQSO_SYNTAX               = %SQSO_LANGUAGE_KEYWORDS    + 1
%SQSO_TIME_ZONE            = %SQSO_SYNTAX               + 1
%SQSO_IMPLICIT_CONNECTOR   = %SQSO_TIME_ZONE            + 1
%SQSO_CONNECTOR_CASE       = %SQSO_IMPLICIT_CONNECTOR   + 1

' enum STRUCTURED_QUERY_MULTIOPTION
%SQMO_VIRTUAL_PROPERTY   = 0
%SQMO_DEFAULT_PROPERTY   = %SQMO_VIRTUAL_PROPERTY + 1
%SQMO_GENERATOR_FOR_TYPE = %SQMO_DEFAULT_PROPERTY + 1
%SQMO_MAP_PROPERTY       = %SQMO_GENERATOR_FOR_TYPE + 1

' enum STRUCTURED_QUERY_PARSE_ERROR
%SQPE_NONE                      = 0
%SQPE_EXTRA_OPENING_PARENTHESIS = %SQPE_NONE                      + 1
%SQPE_EXTRA_CLOSING_PARENTHESIS = %SQPE_EXTRA_OPENING_PARENTHESIS + 1
%SQPE_IGNORED_MODIFIER          = %SQPE_EXTRA_CLOSING_PARENTHESIS + 1
%SQPE_IGNORED_CONNECTOR         = %SQPE_IGNORED_MODIFIER          + 1
%SQPE_IGNORED_KEYWORD           = %SQPE_IGNORED_CONNECTOR         + 1
%SQPE_UNHANDLED                 = %SQPE_IGNORED_KEYWORD           + 1

' enum STRUCTURED_QUERY_RESOLVE_OPTION
%SQRO_DEFAULT                           = 0
%SQRO_DONT_RESOLVE_DATETIME             = &H1&
%SQRO_ALWAYS_ONE_INTERVAL               = &H2&
%SQRO_DONT_SIMPLIFY_CONDITION_TREES     = &H4&
%SQRO_DONT_MAP_RELATIONS                = &H8&
%SQRO_DONT_RESOLVE_RANGES               = &H10&
%SQRO_DONT_REMOVE_UNRESTRICTED_KEYWORDS = &H20&
%SQRO_DONT_SPLIT_WORDS                  = &H40&
%SQRO_IGNORE_PHRASE_ORDER               = &H80&
%SQRO_ADD_VALUE_TYPE_FOR_PLAIN_VALUES   = &H100
%SQRO_ADD_ROBUST_ITEM_NAME              = &H200

' enum CASE_REQUIREMENT
%CASE_REQUIREMENT_ANY          = 0
%CASE_REQUIREMENT_UPPER_IF_AQS = %CASE_REQUIREMENT_ANY + 1

' enum INTERVAL_LIMIT_KIND
%ILK_EXPLICIT_INCLUDED   = 0
%ILK_EXPLICIT_EXCLUDED   = %ILK_EXPLICIT_INCLUDED + 1
%ILK_NEGATIVE_INFINITY   = %ILK_EXPLICIT_EXCLUDED + 1
%ILK_POSITIVE_INFINITY   = %ILK_NEGATIVE_INFINITY + 1

' enum QUERY_PARSER_MANAGER_OPTION
%QPMO_SCHEMA_BINARY_NAME              = 0
%QPMO_PRELOCALIZED_SCHEMA_BINARY_PATH = %QPMO_SCHEMA_BINARY_NAME              + 1
%QPMO_UNLOCALIZED_SCHEMA_BINARY_PATH  = %QPMO_PRELOCALIZED_SCHEMA_BINARY_PATH + 1
%QPMO_LOCALIZED_SCHEMA_BINARY_PATH    = %QPMO_UNLOCALIZED_SCHEMA_BINARY_PATH  + 1
%QPMO_APPEND_LCID_TO_LOCALIZED_PATH   = %QPMO_LOCALIZED_SCHEMA_BINARY_PATH    + 1
%QPMO_LOCALIZER_SUPPORT               = %QPMO_APPEND_LCID_TO_LOCALIZED_PATH   + 1


' ########################################################################################
' Interface name = IQueryParser
' IID = 2EBDEE67-3505-43F8-9946-EA44ABC8E5B0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IQueryParser_INTERFACE_DEFINED)
    %IQueryParser_INTERFACE_DEFINED = 1

$IID_IQueryParser = GUID$("{2EBDEE67-3505-43F8-9946-EA44ABC8E5B0}")

INTERFACE IQueryParser $IID_IQueryParser

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Parse ( _                                     ' VTable offset = 12
     BYREF pszInputString AS WSTRINGZ _                 ' __in LPCWSTR pszInputString
   , BYVAL pCustomProperties AS IEnumUnknown _          ' __in IEnumUnknown *pCustomProperties
   , BYREF ppSolution AS IQuerySolution _               ' __out IQuerySolution **ppSolution
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOption ( _                                 ' VTable offset = 16
     BYVAL option AS LONG _                             ' __in STRUCTURED_QUERY_SINGLE_OPTION option
   , BYREF pOptionValue AS PROPVARIANT _                ' __in const PROPVARIANT *pOptionValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOption ( _                                 ' VTable offset = 20
     BYVAL option AS LONG _                             ' __in STRUCTURED_QUERY_SINGLE_OPTION option
   , BYREF pOptionValue AS PROPVARIANT _                ' __out const PROPVARIANT *pOptionValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMultiOption ( _                            ' VTable offset = 24
     BYVAL option AS LONG _                             ' __in STRUCTURED_QUERY_MULTIOPTION option
   , BYREF pszOptionKey AS WSTRINGZ _                   ' __in LPCWSTR pszOptionKey
   , BYREF pOptionValue AS PROPVARIANT _                ' __in const PROPVARIANT *pOptionValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSchemaProvider ( _                         ' VTable offset = 28
     BYREF ppSchemaProvider AS ISchemaProvider _        ' __out ISchemaProvider **ppSchemaProvider
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RestateToString ( _                           ' VTable offset = 32
     BYVAL pCondition AS ICondition _                   ' __in ICondition *pCondition
   , BYVAL fUseEnglish AS LONG _                        ' __in BOOL fUseEnglish
   , BYREF ppszQueryString AS DWORD _                   ' __out LPWSTR *ppszQueryString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ParsePropertyValue ( _                        ' VTable offset = 36
     BYREF pszPropertyName AS WSTRINGZ _                ' __in LPCWSTR pszPropertyName
   , BYREF pszInputString AS WSTRINGZ _                 ' __in LPCWSTR pszInputString
   , BYREF ppSolution AS IQuerySolution _               ' __out IQuerySolution **ppSolution
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RestatePropertyValueToString ( _              ' VTable offset = 40
     BYVAL pCondition AS ICondition _                   ' __in ICondition *pCondition
   , BYVAL fUseEnglish AS LONG _                        ' __in BOOL fUseEnglish
   , BYREF ppszPropertyName AS DWORD _                  ' __out LPWSTR *ppszPropertyName
   , BYREF ppszQueryString AS DWORD _                   ' __out LPWSTR *ppszQueryString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IQueryParser_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IConditionFactory
' IID = A5EFE073-B16F-474f-9F3E-9F8B497A3E08
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IConditionFactory_INTERFACE_DEFINED)
    %IConditionFactory_INTERFACE_DEFINED = 1

$IID_IConditionFactory = GUID$("{A5EFE073-B16F-474f-9F3E-9F8B497A3E08}")

INTERFACE IConditionFactory $IID_IConditionFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD MakeNot ( _                                   ' VTable offset = 12
     BYVAL pSubCondition AS ICondition _                ' __in ICondition *pSubCondition
   , BYVAL simplify AS LONG _                           ' __in BOOL simplify
   , BYREF ppResultQuery AS ICondition _                ' __out ICondition **ppResultQuery
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MakeAndOr ( _                                 ' VTable offset = 16
     BYVAL nodeType AS LONG _                           ' __in CONDITION_TYPE nodeType
   , BYVAL pSubConditions AS IEnumUnknown _             ' __in IEnumUnknown *pSubConditions
   , BYVAL simplify AS LONG _                           ' __in BOOL simplify
   , BYREF ppResultQuery AS ICondition _                ' __out ICondition **ppResultQuery
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MakeLeaf ( _                                  ' VTable offset = 20
     BYREF pszPropertyName AS WSTRINGZ _                ' __in LPCWSTR pszPropertyName
   , BYVAL op AS LONG _                                 ' __in CONDITION_OPERATION op
   , BYREF pszValueType AS WSTRINGZ _                   ' __in LPCWSTR pszValueType
   , BYREF pValue AS PROPVARIANT _                      ' __in const PROPVARIANT *pValue
   , BYVAL pPropertyNameTerm AS IRichChunk _            ' __in IRichChunk *pPropertyNameTerm
   , BYVAL pOperationTerm AS IRichChunk _               ' __in IRichChunk *pOperationTerm
   , BYVAL pValueTerm AS IRichChunk _                   ' __in IRichChunk *pValueTerm
   , BYVAL expand AS LONG _                             ' __in BOOL expand
   , BYREF ppResultQuery AS ICondition _                ' __out ICondition **ppResultQuery
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Resolve ( _                                   ' VTable offset = 24
     BYVAL pConditionTree AS ICondition _               ' __in ICondition *pConditionTree
   , BYVAL sqro AS LONG _                               ' __in STRUCTURED_QUERY_RESOLVE_OPTION sqro
   , BYREF pstReferenceTime AS SYSTEMTIME _             ' __in const SYSTEMTIME *pstReferenceTime
   , BYREF ppResolvedConditionTree AS ICondition _      ' __out ICondition **ppResolvedConditionTree
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IConditionFactory_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IQuerySolution
' IID = D6EBC66B-8921-4193-AFDD-A1789FB7FF57
' Inherited interface = IConditionFactory
' ########################################################################################

#IF NOT %DEF(%IQuerySolution_INTERFACE_DEFINED)
    %IQuerySolution_INTERFACE_DEFINED = 1

$IID_IQuerySolution = GUID$("{D6EBC66B-8921-4193-AFDD-A1789FB7FF57}")

INTERFACE IQuerySolution $IID_IQuerySolution

   INHERIT IUnknown

   ' =====================================================================================
   ' IConditionFactory methods
   ' =====================================================================================
   METHOD MakeNot ( _                                   ' VTable offset = 12
     BYVAL pSubCondition AS ICondition _                ' __in ICondition *pSubCondition
   , BYVAL simplify AS LONG _                           ' __in BOOL simplify
   , BYREF ppResultQuery AS ICondition _                ' __out ICondition **ppResultQuery
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MakeAndOr ( _                                 ' VTable offset = 16
     BYVAL nodeType AS LONG _                           ' __in CONDITION_TYPE nodeType
   , BYVAL pSubConditions AS IEnumUnknown _             ' __in IEnumUnknown *pSubConditions
   , BYVAL simplify AS LONG _                           ' __in BOOL simplify
   , BYREF ppResultQuery AS ICondition _                ' __out ICondition **ppResultQuery
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MakeLeaf ( _                                  ' VTable offset = 20
     BYREF pszPropertyName AS WSTRINGZ _                ' __in LPCWSTR pszPropertyName
   , BYVAL op AS LONG _                                 ' __in CONDITION_OPERATION op
   , BYREF pszValueType AS WSTRINGZ _                   ' __in LPCWSTR pszValueType
   , BYREF pValue AS PROPVARIANT _                      ' __in const PROPVARIANT *pValue
   , BYVAL pPropertyNameTerm AS IRichChunk _            ' __in IRichChunk *pPropertyNameTerm
   , BYVAL pOperationTerm AS IRichChunk _               ' __in IRichChunk *pOperationTerm
   , BYVAL pValueTerm AS IRichChunk _                   ' __in IRichChunk *pValueTerm
   , BYVAL expand AS LONG _                             ' __in BOOL expand
   , BYREF ppResultQuery AS ICondition _                ' __out ICondition **ppResultQuery
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Resolve ( _                                   ' VTable offset = 24
     BYVAL pConditionTree AS ICondition _               ' __in ICondition *pConditionTree
   , BYVAL sqro AS LONG _                               ' __in STRUCTURED_QUERY_RESOLVE_OPTION sqro
   , BYREF pstReferenceTime AS SYSTEMTIME _             ' __in const SYSTEMTIME *pstReferenceTime
   , BYREF ppResolvedConditionTree AS ICondition _      ' __out ICondition **ppResolvedConditionTree
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IQuerySolution methods
   ' =====================================================================================
   METHOD GetQuery ( _                                  ' VTable offset = 28
     BYREF ppQueryNode AS ICondition _                  ' __out ICondition **ppQueryNode
   , BYREF ppMainType AS IEntity _                      ' __out IEntity **ppMainType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetErrors ( _                                 ' VTable offset = 32
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppParseErrors AS IUnknown _                  ' __out void **ppParseErrors
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLexicalData ( _                            ' VTable offset = 36
     BYREF ppszInputString AS DWORD _                   ' __out LPWSTR *ppszInputString
   , BYREF ppTokens AS ITokenCollection _               ' __out ITokenCollection **ppTokens
   , BYREF pLocale AS LONG _                            ' __out LCID *pLocale
   , BYREF ppWordBreaker AS IUnknown _                  ' __out IUnknown **ppWordBreaker
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IQuerySolution_INTERFACE_DEFINED__ */

' enum CONDITION_CREATION_OPTIONS
%CONDITION_CREATION_DEFAULT            = 0
%CONDITION_CREATION_NONE               = 0
%CONDITION_CREATION_SIMPLIFY           = &H1
%CONDITION_CREATION_VECTOR_AND         = &H2
%CONDITION_CREATION_VECTOR_OR          = &H4
%CONDITION_CREATION_VECTOR_LEAF        = &H8
%CONDITION_CREATION_USE_CONTENT_LOCALE = &H10

' ########################################################################################
' Interface name = IConditionFactory2
' IID = 71D222E1-432F-429e-8C13-B6DAFDE5077A
' Inherited interface = IConditionFactory
' ########################################################################################

#IF NOT %DEF(%IConditionFactory2_INTERFACE_DEFINED)
    %IConditionFactory2_INTERFACE_DEFINED = 1

$IID_IConditionFactory2 = GUID$("{71D222E1-432F-429e-8C13-B6DAFDE5077A}")

INTERFACE IConditionFactory2 $IID_IConditionFactory2

   INHERIT IUnknown

   ' =====================================================================================
   ' IConditionFactory methods
   ' =====================================================================================
   METHOD MakeNot ( _                                   ' VTable offset = 12
     BYVAL pSubCondition AS ICondition _                ' __in ICondition *pSubCondition
   , BYVAL simplify AS LONG _                           ' __in BOOL simplify
   , BYREF ppResultQuery AS ICondition _                ' __out ICondition **ppResultQuery
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MakeAndOr ( _                                 ' VTable offset = 16
     BYVAL nodeType AS LONG _                           ' __in CONDITION_TYPE nodeType
   , BYVAL pSubConditions AS IEnumUnknown _             ' __in IEnumUnknown *pSubConditions
   , BYVAL simplify AS LONG _                           ' __in BOOL simplify
   , BYREF ppResultQuery AS ICondition _                ' __out ICondition **ppResultQuery
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MakeLeaf ( _                                  ' VTable offset = 20
     BYREF pszPropertyName AS WSTRINGZ _                ' __in LPCWSTR pszPropertyName
   , BYVAL op AS LONG _                                 ' __in CONDITION_OPERATION op
   , BYREF pszValueType AS WSTRINGZ _                   ' __in LPCWSTR pszValueType
   , BYREF pValue AS PROPVARIANT _                      ' __in const PROPVARIANT *pValue
   , BYVAL pPropertyNameTerm AS IRichChunk _            ' __in IRichChunk *pPropertyNameTerm
   , BYVAL pOperationTerm AS IRichChunk _               ' __in IRichChunk *pOperationTerm
   , BYVAL pValueTerm AS IRichChunk _                   ' __in IRichChunk *pValueTerm
   , BYVAL expand AS LONG _                             ' __in BOOL expand
   , BYREF ppResultQuery AS ICondition _                ' __out ICondition **ppResultQuery
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Resolve ( _                                   ' VTable offset = 24
     BYVAL pConditionTree AS ICondition _               ' __in ICondition *pConditionTree
   , BYVAL sqro AS LONG _                               ' __in STRUCTURED_QUERY_RESOLVE_OPTION sqro
   , BYREF pstReferenceTime AS SYSTEMTIME _             ' __in const SYSTEMTIME *pstReferenceTime
   , BYREF ppResolvedConditionTree AS ICondition _      ' __out ICondition **ppResolvedConditionTree
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IConditionFactory2 methods
   ' =====================================================================================
   METHOD CreateTrueFalse ( _                           ' VTable offset = 28
     BYVAL fVal AS LONG _                               ' __in BOOL fVal
   , BYVAL cco AS LONG _                                ' __in CONDITION_CREATION_OPTIONS cco
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateNegation ( _                            ' VTable offset = 32
     BYVAL pcSub AS ICondition _                        ' __in ICondition *pcSub
   , BYVAL cco AS LONG _                                ' __in CONDITION_CREATION_OPTIONS cco
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateCompoundFromObjectArray ( _             ' VTable offset = 36
     BYVAL ct AS LONG _                                 ' __in CONDITION_TYPE ct
   , BYVAL poaSubs AS IObjectArray _                    ' __in_opt IObjectArray *poaSubs
   , BYVAL cco AS LONG _                                ' __in CONDITION_CREATION_OPTIONS cco
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateCompoundFromArray ( _                   ' VTable offset = 40
     BYVAL ct AS LONG _                                 ' __in CONDITION_TYPE ct
   , BYREF ppcondSubs AS ICondition _                   ' __in_opt ICondition **ppcondSubs
   , BYVAL cSubs AS DWORD _                             ' __in ULONG cSubs
   , BYVAL cco AS LONG _                                ' __in CONDITION_CREATION_OPTIONS cco
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateStringLeaf ( _                          ' VTable offset = 44
     BYREF propkey AS PROPERTYKEY _                     ' __in REFPROPERTYKEY propkey
   , BYVAL cop AS LONG _                                ' __in CONDITION_OPERATION cop
   , BYREF pszValue AS WSTRINGZ _                       ' __in LPCWSTR pszValue
   , BYREF pszLocaleName AS WSTRINGZ _                  ' __in_opt LPCWSTR pszLocaleName
   , BYVAL cco AS LONG _                                ' __in CONDITION_CREATION_OPTIONS cco
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateIntegerLeaf ( _                         ' VTable offset = 48
     BYREF propkey AS PROPERTYKEY _                     ' __in REFPROPERTYKEY propkey
   , BYVAL cop AS LONG _                                ' __in CONDITION_OPERATION cop
   , BYVAL lValue AS LONG _                             ' __in INT32 lValue
   , BYVAL cco AS LONG _                                ' __in CONDITION_CREATION_OPTIONS cco
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBooleanLeaf ( _                         ' VTable offset = 52
     BYREF propkey AS PROPERTYKEY _                     ' __in REFPROPERTYKEY propkey
   , BYVAL cop AS LONG _                                ' __in CONDITION_OPERATION cop
   , BYVAL fValue AS LONG _                             ' __in BOOL fValue
   , BYVAL cco AS LONG _                                ' __in CONDITION_CREATION_OPTIONS cco
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateLeaf ( _                                ' VTable offset = 56
     BYREF propkey AS PROPERTYKEY _                     ' __in REFPROPERTYKEY propkey
   , BYVAL cop AS LONG _                                ' __in CONDITION_OPERATION cop
   , BYREF propvar AS PROPVARIANT _                     ' __in REFPROPVARIANT propvar
   , BYREF pszSemanticType AS WSTRINGZ _                ' __in_opt LPCWSTR pszSemanticType
   , BYREF pszLocaleName AS WSTRINGZ _                  ' __in_opt LPCWSTR pszLocaleName
   , BYVAL pPropertyNameTerm AS IRichChunk _            ' __in_opt IRichChunk *pPropertyNameTerm
   , BYVAL pOperationTerm AS IRichChunk _               ' __in_opt IRichChunk *pOperationTerm
   , BYVAL pValueTerm AS IRichChunk _                   ' __in_opt IRichChunk *pValueTerm
   , BYVAL cco AS LONG _                                ' __in CONDITION_CREATION_OPTIONS cco
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResolveCondition ( _                          ' VTable offset = 60
     BYVAL pc AS ICondition _                           ' __in ICondition *pc
   , BYVAL sqro AS LONG _                               ' __in STRUCTURED_QUERY_RESOLVE_OPTION sqro
   , BYREF pstReferenceTime AS SYSTEMTIME _             ' __in_opt const SYSTEMTIME *pstReferenceTime
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IConditionFactory2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IConditionGenerator
' IID = 92D2CC58-4386-45A3-B98C-7E0CE64A4117
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IConditionGenerator_INTERFACE_DEFINED)
    %IConditionGenerator_INTERFACE_DEFINED = 1

$IID_IConditionGenerator = GUID$("{92D2CC58-4386-45A3-B98C-7E0CE64A4117}")

INTERFACE IConditionGenerator $IID_IConditionGenerator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pSchemaProvider AS ISchemaProvider _         ' __in ISchemaProvider *pSchemaProvider
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RecognizeNamedEntities ( _                    ' VTable offset = 16
     BYREF pszInputString AS WSTRINGZ _                 ' __in LPCWSTR pszInputString
   , BYVAL lcid AS LONG _                               ' __in LCID lcid
   , BYVAL pTokenCollection AS ITokenCollection _       ' __in ITokenCollection *pTokenCollection
   , BYREF pNamedEntities AS INamedEntityCollector _    ' __inout INamedEntityCollector *pNamedEntities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GenerateForLeaf ( _                           ' VTable offset = 20
     BYVAL pConditionFactory AS IConditionFactory _     ' __in IConditionFactory *pConditionFactory
   , BYREF pszPropertyName AS WSTRINGZ _                ' __in LPCWSTR pszPropertyName
   , BYVAL op AS LONG _                                 ' __in CONDITION_OPERATION op
   , BYREF pszValueType AS WSTRINGZ _                   ' __in LPCWSTR pszValueType
   , BYREF pszValue AS WSTRINGZ _                       ' __in LPCWSTR pszValue
   , BYREF pszValue2 AS WSTRINGZ _                      ' __in LPCWSTR pszValue2
   , BYVAL pPropertyNameTerm AS IRichChunk _            ' __in IRichChunk *pPropertyNameTerm
   , BYVAL pOperationTerm AS IRichChunk _               ' __in IRichChunk *pOperationTerm
   , BYVAL pValueTerm AS IRichChunk _                   ' __in IRichChunk *pValueTerm
   , BYVAL automaticWildcard AS LONG _                  ' __in BOOL automaticWildcard
   , BYREF pNoStringQuery AS LONG _                     ' __out BOOL *pNoStringQuery
   , BYREF ppQueryExpression AS ICondition _            ' __out ICondition **ppQueryExpression
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DefaultPhrase ( _                             ' VTable offset = 24
     BYREF pszValueType AS WSTRINGZ _                   ' __in LPCWSTR pszValueType
   , BYREF ppropvar AS PROPVARIANT _                    ' __in const PROPVARIANT *ppropvar
   , BYVAL fUseEnglish AS LONG _                        ' __in BOOL fUseEnglish
   , BYREF ppszPhrase AS DWORD _                        ' __out LPWSTR *ppszPhrase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IConditionGenerator_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IInterval
' IID = 6BF0A714-3C18-430B-8B5D-83B1C234D3DB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInterval_INTERFACE_DEFINED)
    %IInterval_INTERFACE_DEFINED = 1

$IID_IInterval = GUID$("{6BF0A714-3C18-430B-8B5D-83B1C234D3DB}")

INTERFACE IInterval $IID_IInterval

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLimits ( _                                 ' VTable offset = 12
     BYREF pilkLower AS LONG _                          ' __out INTERVAL_LIMIT_KIND *pilkLower
   , BYREF ppropvarLower AS PROPVARIANT _               ' __out PROPVARIANT *ppropvarLower
   , BYREF pilkUpper AS LONG _                          ' __out INTERVAL_LIMIT_KIND *pilkUpper
   , BYREF ppropvarUpper AS PROPVARIANT _               ' __out PROPVARIANT *ppropvarUpper
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInterval_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMetaData
' IID = 780102B0-C43B-4876-BC7B-5E9BA5C88794
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMetaData_INTERFACE_DEFINED)
    %IMetaData_INTERFACE_DEFINED = 1

$IID_IMetaData = GUID$("{780102B0-C43B-4876-BC7B-5E9BA5C88794}")

INTERFACE IMetaData $IID_IMetaData

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 12
     BYREF ppszKey AS DWORD _                           ' __out LPWSTR *ppszKey
   , BYREF ppszValue AS DWORD _                         ' __out LPWSTR *ppszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMetaData_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEntity
' IID = 24264891-E80B-4FD3-B7CE-4FF2FAE8931F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEntity_INTERFACE_DEFINED)
    %IEntity_INTERFACE_DEFINED = 1

$IID_IEntity = GUID$("{24264891-E80B-4FD3-B7CE-4FF2FAE8931F}")

INTERFACE IEntity $IID_IEntity

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Name ( _                                      ' VTable offset = 12
     BYREF ppszName AS DWORD _                          ' __out LPWSTR *ppszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Base ( _                                      ' VTable offset = 16
     BYREF pBaseEntity AS IEntity _                     ' __out IEntity **pBaseEntity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Relationships ( _                             ' VTable offset = 20
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF pRelationships AS IUnknown _                 ' __out void **pRelationships
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRelationship ( _                           ' VTable offset = 24
     BYREF pszRelationName AS WSTRINGZ _                ' __in LPCWSTR pszRelationName
   , BYREF pRelationship AS IRelationship _             ' __out IRelationship **pRelationship
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MetaData ( _                                  ' VTable offset = 28
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF pMetaData AS IUnknown _                      ' __out void **pMetaData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NamedEntities ( _                             ' VTable offset = 32
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF pNamedEntities AS IUnknown _                 ' __out void **pNamedEntities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNamedEntity ( _                            ' VTable offset = 36
     BYREF pszValue AS WSTRINGZ _                       ' __in LPCWSTR pszValue
   , BYREF ppNamedEntity AS INamedEntity _              ' __out INamedEntity **ppNamedEntity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DefaultPhrase ( _                             ' VTable offset = 40
     BYREF ppszPhrase AS DWORD _                        ' __out LPWSTR *ppszPhrase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEntity_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRelationship
' IID = 2769280B-5108-498C-9C7F-A51239B63147
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRelationship_INTERFACE_DEFINED)
    %IRelationship_INTERFACE_DEFINED = 1

$IID_IRelationship = GUID$("{2769280B-5108-498C-9C7F-A51239B63147}")

INTERFACE IRelationship $IID_IRelationship

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Name ( _                                      ' VTable offset = 12
     BYREF ppszName AS DWORD _                          ' __out LPWSTR *ppszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsReal ( _                                    ' VTable offset = 16
     BYREF pIsReal AS LONG _                            ' __out BOOL *pIsReal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Destination ( _                               ' VTable offset = 20
     BYREF pDestinationEntity AS IEntity _              ' __out IEntity **pDestinationEntity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MetaData ( _                                  ' VTable offset = 24
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF pMetaData AS IUnknown _                      ' __out void **pMetaData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DefaultPhrase ( _                             ' VTable offset = 28
     BYREF ppszPhrase AS DWORD _                        ' __out LPWSTR *ppszPhrase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRelationship_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = INamedEntity
' IID = ABDBD0B1-7D54-49FB-AB5C-BFF4130004CD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%INamedEntity_INTERFACE_DEFINED)
    %INamedEntity_INTERFACE_DEFINED = 1

$IID_INamedEntity = GUID$("{ABDBD0B1-7D54-49FB-AB5C-BFF4130004CD}")

INTERFACE INamedEntity $IID_INamedEntity

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 12
     BYREF ppszValue AS DWORD _                         ' __out LPWSTR *ppszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DefaultPhrase ( _                             ' VTable offset = 16
     BYREF ppszPhrase AS DWORD _                        ' __out LPWSTR *ppszPhrase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INamedEntity_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISchemaProvider
' IID = 8CF89BCB-394C-49B2-AE28-A59DD4ED7F68
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISchemaProvider_INTERFACE_DEFINED)
    %ISchemaProvider_INTERFACE_DEFINED = 1

$IID_ISchemaProvider = GUID$("{8CF89BCB-394C-49B2-AE28-A59DD4ED7F68}")

INTERFACE ISchemaProvider $IID_ISchemaProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Entities ( _                                  ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF pEntities AS IUnknown _                      ' __out void **pEntities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RootEntity ( _                                ' VTable offset = 16
     BYREF pRootEntity AS IEntity _                     ' __out IEntity **pRootEntity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEntity ( _                                 ' VTable offset = 20
     BYREF pszEntityName AS WSTRINGZ _                  ' __in LPCWSTR pszEntityName
   , BYREF pEntity AS IEntity _                         ' __out IEntity **pEntity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MetaData ( _                                  ' VTable offset = 24
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF pMetaData AS IUnknown _                      ' __out void **pMetaData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Localize ( _                                  ' VTable offset = 28
     BYVAL lcid AS LONG _                               ' __in LCID lcid
   , BYVAL pSchemaLocalizerSupport AS ISchemaLocalizerSupport _ ' __in ISchemaLocalizerSupport *pSchemaLocalizerSupport
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveBinary ( _                                ' VTable offset = 32
     BYREF pszSchemaBinaryPath AS WSTRINGZ _            ' __in LPCWSTR pszSchemaBinaryPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LookupAuthoredNamedEntity ( _                 ' VTable offset = 36
     BYVAL pEntity AS IEntity _                         ' __in IEntity *pEntity
   , BYREF pszInputString AS WSTRINGZ _                 ' __in LPCWSTR pszInputString
   , BYVAL pTokenCollection AS ITokenCollection _       ' __in ITokenCollection *pTokenCollection
   , BYVAL cTokensBegin AS DWORD _                      ' __in ULONG cTokensBegin
   , BYREF pcTokensLength AS DWORD _                    ' __out ULONG *pcTokensLength
   , BYREF ppszValue AS DWORD _                         ' __out LPWSTR *ppszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISchemaProvider_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITokenCollection
' IID = 22D8B4F2-F577-4ADB-A335-C2AE88416FAB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITokenCollection_INTERFACE_DEFINED)
    %ITokenCollection_INTERFACE_DEFINED = 1

$IID_ITokenCollection = GUID$("{22D8B4F2-F577-4ADB-A335-C2AE88416FAB}")

INTERFACE ITokenCollection $IID_ITokenCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD NumberOfTokens ( _                            ' VTable offset = 12
     BYREF pCount AS DWORD _                            ' __out ULONG *pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetToken ( _                                  ' VTable offset = 16
     BYVAL i AS LONG _                                  ' __in ULONG i
   , BYREF pBegin AS DWORD _                            ' __out ULONG *pBegin
   , BYREF pLength AS DWORD _                           ' __out ULONG *pLength
   , BYREF ppsz AS DWORD _                              ' __out LPWSTR *ppsz
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITokenCollection_INTERFACE_DEFINED__ */


' NAMED_ENTITY_CERTAINTY enum
%NEC_LOW    = 0
%NEC_MEDIUM = %NEC_LOW    + 1
%NEC_HIGH   = %NEC_MEDIUM + 1


' ########################################################################################
' Interface name = INamedEntityCollector
' IID = AF2440F6-8AFC-47D0-9A7F-396A0ACFB43D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%INamedEntityCollector_INTERFACE_DEFINED)
    %INamedEntityCollector_INTERFACE_DEFINED = 1

$IID_INamedEntityCollector = GUID$("{AF2440F6-8AFC-47D0-9A7F-396A0ACFB43D}")

INTERFACE INamedEntityCollector $IID_INamedEntityCollector

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Add ( _                                       ' VTable offset = 12
     BYVAL beginSpan AS DWORD _                         ' __in ULONG beginSpan
   , BYVAL endSpan AS DWORD _                           ' __in ULONG endSpan
   , BYVAL beginActual AS DWORD _                       ' __in ULONG beginActual
   , BYVAL endActual AS DWORD _                         ' __in ULONG endActual
   , BYVAL pType AS IEntity _                           ' __in IEntity *pType
   , BYREF pszValue AS WSTRINGZ _                       ' __in LPCWSTR pszValue
   , BYVAL certainty AS LONG _                          ' __in NAMED_ENTITY_CERTAINTY certainty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INamedEntityCollector_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISchemaLocalizerSupport
' IID = CA3FDCA2-BFBE-4EED-90D7-0CAEF0A1BDA1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISchemaLocalizerSupport_INTERFACE_DEFINED)
    %ISchemaLocalizerSupport_INTERFACE_DEFINED = 1

$IID_ISchemaLocalizerSupport = GUID$("{CA3FDCA2-BFBE-4EED-90D7-0CAEF0A1BDA1}")

INTERFACE ISchemaLocalizerSupport $IID_ISchemaLocalizerSupport

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Localize ( _                                  ' VTable offset = 12
     BYREF pszGlobalString AS WSTRINGZ _                ' __in LPCWSTR pszGlobalString
   , BYREF ppszLocalString AS DWORD _                   ' __out LPWSTR *ppszLocalString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISchemaLocalizerSupport_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IQueryParserManager
' IID = A879E3C4-AF77-44FB-8F37-EBD1487CF920
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IQueryParserManager_INTERFACE_DEFINED)
    %IQueryParserManager_INTERFACE_DEFINED = 1

$IID_IQueryParserManager = GUID$("{A879E3C4-AF77-44FB-8F37-EBD1487CF920}")

INTERFACE IQueryParserManager $IID_IQueryParserManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateLoadedParser ( _                        ' VTable offset = 12
     BYREF pszCatalog AS WSTRINGZ _                     ' __in LPCWSTR pszCatalog
   , BYVAL langidForKeywords AS WORD _                  ' __in LANGID langidForKeywords
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppQueryParser AS IUnknown _                  ' __out void **ppQueryParser
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitializeOptions ( _                         ' VTable offset = 16
     BYVAL fUnderstandNQS AS LONG _                     ' __in BOOL fUnderstandNQS
   , BYVAL fAutoWildCard AS LONG _                      ' __in BOOL fAutoWildCard
   , BYVAL pQueryParser AS IQueryParser _               ' __in IQueryParser *pQueryParser
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOption ( _                                 ' VTable offset = 20
     BYVAL option AS LONG _                             ' __in QUERY_PARSER_MANAGER_OPTION option
   , BYREF pOptionValue AS PROPVARIANT _                ' __in const PROPVARIANT *pOptionValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IQueryParserManager_INTERFACE_DEFINED__ */

' // Size = 8 bytes
TYPE HITRANGE DWORD
   iPosition AS DWORD   ' ULONG
   cLength   AS DWORD   ' ULONG
END TYPE
