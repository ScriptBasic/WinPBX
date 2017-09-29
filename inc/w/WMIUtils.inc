' ########################################################################################
' Microsoft Windows
' File: WMIUtils.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ========================================================================================
' The interfaces included in this file require Windows XP.
' Windows 2000/NT: Requires the WMI SDK Update or the Microsoft .NET Framework SDK.
' Windows NT: Requires the Microsoft .NET Framework SDK.
' ========================================================================================

#INCLUDE THIS ONCE
%WMIUTILS_INC = 1

$CLSID_WbemDefPath = GUID$("{CF4CC405-E2C5-4DDD-B3CE-5E7582D8C9FA}")
$CLSID_WbemQuery   = GUID$("{EAC8A024-21E2-4523-AD73-A71A0AA2F56A}")

' ========================================================================================
' WBEM_PATH_STATUS_FLAG enum
' ========================================================================================

%WBEMPATH_INFO_ANON_LOCAL_MACHINE    = &H1???
%WBEMPATH_INFO_HAS_MACHINE_NAME      = &H2???
%WBEMPATH_INFO_IS_CLASS_REF          = &H4???
%WBEMPATH_INFO_IS_INST_REF           = &H8???
%WBEMPATH_INFO_HAS_SUBSCOPES         = &H10???
%WBEMPATH_INFO_IS_COMPOUND           = &H20???
%WBEMPATH_INFO_HAS_V2_REF_PATHS      = &H40???
%WBEMPATH_INFO_HAS_IMPLIED_KEY       = &H80???
%WBEMPATH_INFO_CONTAINS_SINGLETON    = &H100???
%WBEMPATH_INFO_V1_COMPLIANT          = &H200???
%WBEMPATH_INFO_V2_COMPLIANT          = &H400???
%WBEMPATH_INFO_CIM_COMPLIANT         = &H800???
%WBEMPATH_INFO_IS_SINGLETON          = &H1000???
%WBEMPATH_INFO_IS_PARENT             = &H2000???
%WBEMPATH_INFO_SERVER_NAMESPACE_ONLY = &H4000???
%WBEMPATH_INFO_NATIVE_PATH           = &H8000???
%WBEMPATH_INFO_WMI_PATH              = &H10000???
%WBEMPATH_INFO_PATH_HAD_SERVER       = &H20000???

' ========================================================================================
' WBEM_PATH_CREATE_FLAG enum
' ========================================================================================

%WBEMPATH_CREATE_ACCEPT_RELATIVE   = &H1???
%WBEMPATH_CREATE_ACCEPT_ABSOLUTE   = &H2???
%WBEMPATH_CREATE_ACCEPT_ALL        = &H4???
%WBEMPATH_TREAT_SINGLE_IDENT_AS_NS = &H8???

' ========================================================================================
' WBEM_GET_TEXT_FLAGS enum
' ========================================================================================

%WBEMPATH_COMPRESSED                    = &H1???
%WBEMPATH_GET_RELATIVE_ONLY             = &H2???
%WBEMPATH_GET_SERVER_TOO                = &H4???
%WBEMPATH_GET_SERVER_AND_NAMESPACE_ONLY = &H8???
%WBEMPATH_GET_NAMESPACE_ONLY            = &H10???
%WBEMPATH_GET_ORIGINAL                  = &H20???

' ========================================================================================
' WBEM_GET_KEY_FLAGS enum
' ========================================================================================

%WBEMPATH_TEXT       = &H1???
%WBEMPATH_QUOTEDTEXT = &H2???

' ========================================================================================
' IWbemPathKeyList interface
' The IWbemPathKeyList interface is used to access the details of the path key(s).
' ========================================================================================

$IID_IWbemPathKeyList = GUID$("{9AE62877-7544-4bb0-AA26-A13824659ED6}")

INTERFACE IWbemPathKeyList $IID_IWbemPathKeyList

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF puKeyCount AS DWORD _                        ' __out ULONG *puKeyCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetKey ( _                                    ' VTable offset = 16
     BYREF wszName AS WSTRINGZ _                        ' __in LPCWSTR wszName
   , BYVAL uFlags AS DWORD _                            ' __in ULONG uFlags
   , BYVAL uCimType AS DWORD _                          ' __in ULONG uCimType
   , BYVAL pKeyVal AS DWORD _                           ' __in LPVOID pKeyVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetKey2 ( _                                   ' VTable offset = 20
     BYREF wszName AS WSTRINGZ _                        ' __in LPCWSTR wszName
   , BYVAL uFlags AS DWORD _                            ' __in ULONG uFlags
   , BYVAL uCimType AS DWORD _                          ' __in ULONG uCimType
   , BYREF pKeyVal AS VARIANT _                         ' __in VARIANT pKeyVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetKey ( _                                    ' VTable offset = 24
     BYVAL uKeyIx AS DWORD _                            ' __in ULONG uKeyIx
   , BYVAL uFlags AS DWORD _                            ' __in ULONG uFlags
   , BYREF puNameBufSize AS DWORD _                     ' __inout ULONG *puNameBufSize
   , BYREF pszKeyName AS WSTRINGZ _                     ' __inout LPWSTR pszKeyName
   , BYREF puKeyValBufSize AS DWORD _                   ' __inout ULONG *puKeyValBufSize
   , BYVAL pKeyVal AS DWORD _                           ' __inout LPVOID pKeyVal
   , BYREF puApparentCimType AS DWORD _                 ' __out ULONG *puApparentCimType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetKey2 ( _                                   ' VTable offset = 28
     BYVAL uKeyIx AS DWORD _                            ' __in ULONG uKeyIx
   , BYVAL uFlags AS DWORD _                            ' __in ULONG uFlags
   , BYREF puNameBufSize AS DWORD _                     ' __inout ULONG *puNameBufSize
   , BYREF pszKeyName AS WSTRINGZ _                     ' __inout LPWSTR pszKeyName
   , BYREF pKeyValue AS VARIANT _                       ' __inout VARIANT pKeyValue
   , BYREF puApparentCimType AS DWORD _                 ' __out ULONG *puApparentCimType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveKey ( _                                 ' VTable offset = 32
     BYREF wszName AS WSTRINGZ _                        ' __in LPCWSTR wszName
   , BYVAL uFlags AS DWORD _                            ' __in ULONG uFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAllKeys ( _                             ' VTable offset = 36
     BYVAL uFlags AS DWORD _                            ' __in ULONG uFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MakeSingleton ( _                             ' VTable offset = 40
     BYVAL bSet AS BYTE _                               ' __in boolean bSet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInfo ( _                                   ' VTable offset = 44
     BYVAL uRequestedInfo AS DWORD _                    ' __in ULONG uRequestedInfo
   , BYREF puResponse AS QUAD _                         ' __out ULONGLONG *puResponse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetText ( _                                   ' VTable offset = 48
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF puBuffLength AS DWORD _                      ' __inout ULONG *puBuffLength
   , BYREF pszText AS WSTRINGZ _                        ' __inout LPWSTR pszText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE
' ========================================================================================


' ========================================================================================
' IWbemPath interface
' The IWbemPath interface is the primary interface for the object path parser and makes
' parsing a path available to programs in a standard way. This interface is the main
' interface for setting and retrieving path information.
' ========================================================================================

$IID_IWbemPath = GUID$("{3BC15AF2-736C-477E-9E51-238AF8667DCC}")

INTERFACE IWbemPath $IID_IWbemPath

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetText ( _                                   ' VTable offset = 12
     BYVAL puKeyCount AS DWORD _                        ' __out ULONG *puKeyCount
   , BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetText ( _                                   ' VTable offset = 16
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF puBuffLength AS DWORD _                      ' __inout ULONG *puBuffLength
   , BYREF pszText AS WSTRINGZ _                        ' __inout LPWSTR pszText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInfo ( _                                   ' VTable offset = 20
     BYVAL uRequestedInfo AS DWORD _                    ' __in ULONG uRequestedInfo
   , BYREF puResponse AS QUAD _                         ' __out ULONGLONG *puResponse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetServer ( _                                 ' VTable offset = 24
     BYREF Name AS WSTRINGZ _                           ' __in LPCWSTR Name
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServer ( _                                 ' VTable offset = 28
     BYREF puNameBufLength AS DWORD _                   ' __inout ULONG *puNameBufLength
   , BYREF pName AS WSTRINGZ _                          ' __inout LPWSTR pName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNamespaceCount ( _                         ' VTable offset = 32
     BYREF puCount AS DWORD _                           ' __out ULONG *puCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNamespaceAt ( _                            ' VTable offset = 36
     BYVAL uIndex AS DWORD _                            ' __in ULONG uIndex
   , BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNamespaceAt ( _                            ' VTable offset = 40
     BYVAL uIndex AS DWORD _                            ' __in ULONG uIndex
   , BYREF puNameBufLength AS DWORD _                   ' __inout ULONG *puNameBufLength
   , BYREF pName AS WSTRINGZ _                          ' __inout LPWSTR pName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveNamespaceAt ( _                         ' VTable offset = 44
     BYVAL uIndex AS DWORD _                            ' __in ULONG uIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAllNamespaces ( _                       ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScopeCount ( _                             ' VTable offset = 52
     BYREF puCount AS DWORD _                           ' __out ULONG *puCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetScope ( _                                  ' VTable offset = 56
     BYVAL uIndex AS DWORD _                            ' __in ULONG uIndex
   , BYREF pszClass AS WSTRINGZ _                       ' __in LPWSTR pszClass
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetScopeFromText ( _                          ' VTable offset = 60
     BYVAL uIndex AS DWORD _                            ' __in ULONG uIndex
   , BYREF pszText AS WSTRINGZ _                        ' __in LPWSTR pszText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScope ( _                                  ' VTable offset = 64
     BYVAL uIndex AS DWORD _                            ' __in ULONG uIndex
   , BYREF puClassNameBufSize AS DWORD _                ' __inout ULONG *puClassNameBufSize
   , BYREF pszClass AS WSTRINGZ _                       ' __inout LPWSTR pszClass
   , BYREF pKeyList AS IWbemPathKeyList _               ' __out IWbemPathKeyList **pKeyList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScopeAsText ( _                            ' VTable offset = 68
     BYVAL uIndex AS DWORD _                            ' __in ULONG uIndex
   , BYREF puTextBufSize AS DWORD _                     ' __inout ULONG *puTextBufSize
   , BYREF pszText AS WSTRINGZ _                        ' __inout LPWSTR pszText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveScope ( _                               ' VTable offset = 72
     BYVAL uIndex AS DWORD _                            ' __in ULONG uIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAllScopes ( _                           ' VTable offset = 76
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClassName ( _                              ' VTable offset = 80
     BYREF Name AS WSTRINGZ _                           ' __in LPCWSTR Name
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClassName ( _                              ' VTable offset = 84
     BYREF puBuffLength AS DWORD _                      ' __inout ULONG *puBuffLength
   , BYREF pszName AS WSTRINGZ _                        ' __inout LPWSTR pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetKeyList ( _                                ' VTable offset = 88
     BYREF pOut AS IWbemPathKeyList _                   ' __out IWbemPathKeyList **pOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateClassPart ( _                           ' VTable offset = 92
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF Name AS WSTRINGZ _                           ' __in LPCWSTR Name
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteClassPart ( _                           ' VTable offset = 96
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsRelative ( _                                ' VTable offset = 100
     BYREF wszMachine AS WSTRINGZ _                     ' __in LPWSTR wszMachine
   , BYREF wszNamespace AS WSTRINGZ _                   ' __in LPWSTR wszNamespace
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD IsRelativeOrChild ( _                         ' VTable offset = 104
     BYREF wszMachine AS WSTRINGZ _                     ' __in LPWSTR wszMachine
   , BYREF wszNamespace AS WSTRINGZ _                    ' __in LPWSTR wszNamespace
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD IsLocal ( _                                   ' VTable offset = 108
     BYREF wszMachine AS WSTRINGZ _                     ' __in LPCWSTR wszMachine
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD IsSameClassName ( _                           ' VTable offset = 112
     BYREF wszClass AS WSTRINGZ _                       ' __in LPCWSTR wszClass
   ) AS LONG                                            ' BOOL
   ' =====================================================================================

END INTERFACE


' ========================================================================================
' IWbemQuery interface
' The IWbemQuery interface provides an entry point through which a WMI Query Language
' (WQL) query can be parsed. This interface was added in Windows XP.
' ========================================================================================

$IID_IWbemQuery = GUID$("{81166F58-DD98-11D3-A120-00105A1F515A}")

INTERFACE IWbemQuery $IID_IWbemQuery

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Empty ( _                                     ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLanguageFeatures ( _                       ' VTable offset = 16
     BYVAL uFlags AS DWORD _                            ' __in ULONG uFlags
   , BYVAL uArraySize AS DWORD _                        ' __in ULONG uArraySize
   , BYVAL puFeatures AS DWORD _                        ' __in ULONG *puFeatures
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TestLanguageFeatures ( _                      ' VTable offset = 20
     BYVAL uFlags AS DWORD _                            ' __in ULONG uFlags
   , BYREF uArraySize AS DWORD _                        ' __inout ULONG *uArraySize
   , BYREF puFeatures AS DWORD _                        ' __out ULONG *puFeatures
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Parse ( _                                     ' VTable offset = 24
     BYREF pszLang AS WSTRINGZ _                        ' __in LPCWSTR pszLang
   , BYREF pszQuery AS WSTRINGZ _                       ' __in LPCWSTR pszQuery
   , BYVAL uFlags AS DWORD _                            ' __in ULONG uFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAnalysis ( _                               ' VTable offset = 28
     BYVAL uAnalysisType AS DWORD _                     ' __in ULONG uAnalysisType
   , BYVAL uFlags AS DWORD _                            ' __in ULONG uFlags
   , BYREF pAnalysis AS DWORD _                         ' __out LPVOID *pAnalysis
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeMemory ( _                                ' VTable offset = 32
     BYVAL pMem AS DWORD _                              ' __in LPVOID pMem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetQueryInfo ( _                              ' VTable offset = 36
     BYVAL uAnalysisType AS DWORD _                     ' __in ULONG uAnalysisType
   , BYVAL uInfoId AS DWORD _                           ' __in ULONG uInfoId
   , BYVAL uBufSize AS DWORD _                          ' __in ULONG uBufSize
   , BYVAL pDestBuf AS DWORD _                          ' __out LPVOID pDestBuf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ========================================================================================
' WMIQ_ANALYSIS_TYPE enum
' ========================================================================================

%WMIQ_ANALYSIS_RPN_SEQUENCE         = &H1???
%WMIQ_ANALYSIS_ASSOC_QUERY          = &H2???
%WMIQ_ANALYSIS_PROP_ANALYSIS_MATRIX = &H3???
%WMIQ_ANALYSIS_QUERY_TEXT           = &H4???
%WMIQ_ANALYSIS_RESERVED             = &H8000000???

' ========================================================================================
' WMIQ_RPN_TOKEN_FLAGS enum
' ========================================================================================

%WMIQ_RPN_TOKEN_EXPRESSION    = 1???
%WMIQ_RPN_TOKEN_AND           = 2???
%WMIQ_RPN_TOKEN_OR            = 3???
%WMIQ_RPN_TOKEN_NOT           = 4???
%WMIQ_RPN_OP_UNDEFINED        = 0???
%WMIQ_RPN_OP_EQ               = 1???
%WMIQ_RPN_OP_NE               = 2???
%WMIQ_RPN_OP_GE               = 3???
%WMIQ_RPN_OP_LE               = 4???
%WMIQ_RPN_OP_LT               = 5???
%WMIQ_RPN_OP_GT               = 6???
%WMIQ_RPN_OP_LIKE             = 7???
%WMIQ_RPN_OP_ISA              = 8???
%WMIQ_RPN_OP_ISNOTA           = 9???
%WMIQ_RPN_OP_ISNULL           = 10???
%WMIQ_RPN_OP_ISNOTNULL        = 11???
%WMIQ_RPN_LEFT_PROPERTY_NAME  = &H1???
%WMIQ_RPN_RIGHT_PROPERTY_NAME = &H2???
%WMIQ_RPN_CONST2              = &H4???
%WMIQ_RPN_CONST               = &H8???
%WMIQ_RPN_RELOP               = &H10???
%WMIQ_RPN_LEFT_FUNCTION       = &H20???
%WMIQ_RPN_RIGHT_FUNCTION      = &H40???
%WMIQ_RPN_GET_TOKEN_TYPE      = 1???
%WMIQ_RPN_GET_EXPR_SHAPE      = 2???
%WMIQ_RPN_GET_LEFT_FUNCTION   = 3???
%WMIQ_RPN_GET_RIGHT_FUNCTION  = 4???
%WMIQ_RPN_GET_RELOP           = 5???
%WMIQ_RPN_NEXT_TOKEN          = 1???
%WMIQ_RPN_FROM_UNARY          = &H1???
%WMIQ_RPN_FROM_PATH           = &H2???
%WMIQ_RPN_FROM_CLASS_LIST     = &H4???
%WMIQ_RPN_FROM_MULTIPLE       = &H8???

' ========================================================================================
' WMIQ_ASSOCQ_FLAGS enum
' ========================================================================================

%WMIQ_ASSOCQ_ASSOCIATORS            = &H1???
%WMIQ_ASSOCQ_REFERENCES             = &H2???
%WMIQ_ASSOCQ_RESULTCLASS            = &H4???
%WMIQ_ASSOCQ_ASSOCCLASS             = &H8???
%WMIQ_ASSOCQ_ROLE                   = &H10???
%WMIQ_ASSOCQ_RESULTROLE             = &H20???
%WMIQ_ASSOCQ_REQUIREDQUALIFIER      = &H40???
%WMIQ_ASSOCQ_REQUIREDASSOCQUALIFIER = &H80???
%WMIQ_ASSOCQ_CLASSDEFSONLY          = &H100???
%WMIQ_ASSOCQ_KEYSONLY               = &H200???
%WMIQ_ASSOCQ_SCHEMAONLY             = &H400???
%WMIQ_ASSOCQ_CLASSREFSONLY          = &H800???

' ========================================================================================
' SWbemQueryQualifiedName structure
' ========================================================================================

' // Size = 28 bytes
TYPE SWbemQueryQualifiedName DWORD
   m_uVersion      AS DWORD          ' ULONG
   m_uTokenType    AS DWORD          ' ULONG
   m_uNameListSize AS DWORD          ' ULONG
   m_ppszNameList  AS WSTRINGZ PTR   ' LPCWSTR *
   m_bArraysUsed   AS LONG           ' BOOL
   m_pbArrayElUsed AS LONG PTR       ' BOOL *
   m_puArrayIndex  AS DWORD PTR      ' ULONG *
END TYPE

' ========================================================================================
' SWbemRpnConst union
' ========================================================================================

' // Size = 8 bytes
UNION SWbemRpnConst   ' Must be 8 byte aligned
   m_pszStrVal AS WSTRINGZ PTR   ' LPCWSTR
   m_bBoolVal  AS LONG           ' BOOL
   m_lLongVal  AS LONG           ' LONG
   m_uLongVal  AS DWORD          ' ULONG
   m_dblVal    AS DOUBLE         ' double
   m_lVal64    AS QUAD           ' __int64
   m_uVal64    AS QUAD           ' __int64
END UNION

' ========================================================================================
' SWbemRpnQueryToken structure
' ========================================================================================

' // Size = 64 bytes
TYPE SWbemRpnQueryToken QWORD FILL
   m_uVersion            AS DWORD                         ' ULONG
   m_uTokenType          AS DWORD                         ' ULONG
   m_uSubexpressionShape AS DWORD                         ' ULONG
   m_uOperator           AS DWORD                         ' ULONG
   m_pRightIdent         AS SWbemQueryQualifiedName PTR   ' SWbemQueryQualifiedName *
   m_pLeftIdent          AS SWbemQueryQualifiedName PTR   ' SWbemQueryQualifiedName *
   m_uConstApparentType  AS DWORD                         ' ULONG
   m_Const               AS SWbemRpnConst                 ' SWbemRpnConst
   m_uConst2ApparentType AS DWORD                         ' ULONG
   m_Const2              AS SWbemRpnConst                 ' SWbemRpnConst
   m_pszRightFunc        AS WSTRINGZ PTR                  ' LPCWSTR
   m_pszLeftFunc         AS WSTRINGZ PTR                  ' LPCWSTR
END TYPE

' ========================================================================================
' SWbemRpnTokenList structure
' ========================================================================================

' // Size = 12 bytes
TYPE SWbemRpnTokenList DWORD
   m_uVersion   AS DWORD   ' ULONG
   m_uTokenType AS DWORD   ' ULONG
   m_uNumTokens AS DWORD   ' ULONG
END TYPE

' ========================================================================================
' WMIQ_LANGUAGE_FEATURES enum
' ========================================================================================

%WMIQ_LF1_BASIC_SELECT                = 1
%WMIQ_LF2_CLASS_NAME_IN_QUERY         = 2
%WMIQ_LF3_STRING_CASE_FUNCTIONS       = 3
%WMIQ_LF4_PROP_TO_PROP_TESTS          = 4
%WMIQ_LF5_COUNT_STAR                  = 5
%WMIQ_LF6_ORDER_BY                    = 6
%WMIQ_LF7_DISTINCT                    = 7
%WMIQ_LF8_ISA                         = 8
%WMIQ_LF9_THIS                        = 9
%WMIQ_LF10_COMPEX_SUBEXPRESSIONS      = 10
%WMIQ_LF11_ALIASING                   = 11
%WMIQ_LF12_GROUP_BY_HAVING            = 12
%WMIQ_LF13_WMI_WITHIN                 = 13
%WMIQ_LF14_SQL_WRITE_OPERATIONS       = 14
%WMIQ_LF15_GO                         = 15
%WMIQ_LF16_SINGLE_LEVEL_TRANSACTIONS  = 16
%WMIQ_LF17_QUALIFIED_NAMES            = 17
%WMIQ_LF18_ASSOCIATONS                = 18
%WMIQ_LF19_SYSTEM_PROPERTIES          = 19
%WMIQ_LF20_EXTENDED_SYSTEM_PROPERTIES = 20
%WMIQ_LF21_SQL89_JOINS                = 21
%WMIQ_LF22_SQL92_JOINS                = 22
%WMIQ_LF23_SUBSELECTS                 = 23
%WMIQ_LF24_UMI_EXTENSIONS             = 24
%WMIQ_LF25_DATEPART                   = 25
%WMIQ_LF26_LIKE                       = 26
%WMIQ_LF27_CIM_TEMPORAL_CONSTRUCTS    = 27
%WMIQ_LF28_STANDARD_AGGREGATES        = 28
%WMIQ_LF29_MULTI_LEVEL_ORDER_BY       = 29
%WMIQ_LF30_WMI_PRAGMAS                = 30
%WMIQ_LF31_QUALIFIER_TESTS            = 31
%WMIQ_LF32_SP_EXECUTE                 = 32
%WMIQ_LF33_ARRAY_ACCESS               = 33
%WMIQ_LF34_UNION                      = 34
%WMIQ_LF35_COMPLEX_SELECT_TARGET      = 35
%WMIQ_LF36_REFERENCE_TESTS            = 36
%WMIQ_LF37_SELECT_INTO                = 37
%WMIQ_LF38_BASIC_DATETIME_TESTS       = 38
%WMIQ_LF39_COUNT_COLUMN               = 39
%WMIQ_LF40_BETWEEN                    = 40
%WMIQ_LF_LAST                         = 40

' ========================================================================================
' WMIQ_RPNQ_FEATURE enum
' ========================================================================================

%WMIQ_RPNF_WHERE_CLAUSE_PRESENT = &H1???
%WMIQ_RPNF_QUERY_IS_CONJUNCTIVE = &H2???
%WMIQ_RPNF_QUERY_IS_DISJUNCTIVE = &H4???
%WMIQ_RPNF_PROJECTION           = &H8???
%WMIQ_RPNF_FEATURE_SELECT_STAR  = &H10???
%WMIQ_RPNF_EQUALITY_TESTS_ONLY  = &H20???
%WMIQ_RPNF_COUNT_STAR           = &H40???
%WMIQ_RPNF_QUALIFIED_NAMES_USED = &H80???
%WMIQ_RPNF_SYSPROP_CLASS_USED   = &H100???
%WMIQ_RPNF_PROP_TO_PROP_TESTS   = &H200???
%WMIQ_RPNF_ORDER_BY             = &H400???
%WMIQ_RPNF_ISA_USED             = &H800???
%WMIQ_RPNF_GROUP_BY_HAVING      = &H1000???
%WMIQ_RPNF_ARRAY_ACCESS_USED    = &H2000???

' ========================================================================================
' SWbemRpnEncodedQuery structure
' ========================================================================================

' // Size = 88 bytes
TYPE SWbemRpnEncodedQuery   ' Must be 8 byte aligned
   m_uVersion            AS DWORD                         ' ULONG
   m_uTokenType          AS DWORD                         ' ULONG
   m_uParsedFeatureMask  AS QUAD                          ' unsigned __int64
   m_uDetectedArraySize  AS DWORD                         ' ULONG
   m_puDetectedFeatures  AS DWORD PTR                     ' ULONG *
   m_uSelectListSize     AS DWORD                         ' ULONG
   m_ppSelectList        AS SWbemQueryQualifiedName PTR   ' SWbemQueryQualifiedName **
   m_uFromTargetType     AS DWORD                         ' ULONG
   m_pszOptionalFromPath AS WSTRINGZ PTR                  ' LPCWSTR
   m_uFromListSize       AS DWORD                         ' ULONG
   m_ppszFromList        AS WSTRINGZ PTR                  ' LPCWSTR
   m_uWhereClauseSize    AS DWORD                         ' ULONG
   m_ppRpnWhereClause    AS SWbemRpnQueryToken PTR        ' SWbemRpnQueryToken **
   m_dblWithinPolling    AS DOUBLE                        ' double
   m_dblWithinWindow     AS DOUBLE                        ' double
   m_uOrderByListSize    AS DWORD                         ' ULONG
   m_ppszOrderByList     AS WSTRINGZ PTR                  ' LPCWSTR *
   m_uOrderDirectionEl   AS DWORD PTR                     ' ULONG *
   alignment__           AS DWORD                         ' // To keep 8 byte alignment
END TYPE

' ========================================================================================
' SWbemAnalysisMatrix structure
' ========================================================================================

' // Size = 28 bytes
TYPE SWbemAnalysisMatrix DWORD
   m_uVersion      AS DWORD          ' ULONG
   m_uMatrixType   AS DWORD          ' ULONG
   m_pszProperty   AS WSTRINGZ PTR   ' LPCWSTR
   m_uPropertyType AS DWORD          ' ULONG
   m_uEntries      AS DWORD          ' ULONG
   m_pValues       AS DWORD          ' LPVOID *
   m_pbTruthTable  AS LONG PTR       ' BOOL *
END TYPE

' ========================================================================================
' SWbemAnalysisMatrixList structure
' ========================================================================================

' // Size = 16 bytes
TYPE SWbemAnalysisMatrixList DWORD
   m_uVersion     AS DWORD                     ' ULONG
   m_uMatrixType  AS DWORD                     ' ULONG
   m_uNumMatrices AS DWORD                     ' ULONG
   m_pMatrices    AS SWbemAnalysisMatrix PTR   ' SWbemAnalysisMatrix *
END TYPE

' ========================================================================================
' SWbemAssocQueryInf structure
' ========================================================================================

' // Size = 48 bytes
TYPE SWbemAssocQueryInf DWORD
   m_uVersion                  AS DWORD          ' ULONG
   m_uAnalysisType             AS DWORD          ' ULONG
   m_uFeatureMask              AS DWORD          ' ULONG
   m_pPath                     AS DWORD          ' IWbemPath *
   m_pszPath                   AS WSTRINGZ PTR   ' LPWSTR
   m_pszQueryText              AS WSTRINGZ PTR   ' LPWSTR
   m_pszResultClass            AS WSTRINGZ PTR   ' LPWSTR
   m_pszAssocClass             AS WSTRINGZ PTR   ' LPWSTR
   m_pszRole                   AS WSTRINGZ PTR   ' LPWSTR
   m_pszResultRole             AS WSTRINGZ PTR   ' LPWSTR
   m_pszRequiredQualifier      AS WSTRINGZ PTR   ' LPWSTR
   m_pszRequiredAssocQualifier AS WSTRINGZ PTR   ' LPWSTR
END TYPE
