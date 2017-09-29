' ########################################################################################
' Microsoft Windows
' File: StructuredQueryCondition.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%STRUCTUREDQUERYCONDITION_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "propidl.inc"

' enum CONDITION_TYPE
%CT_AND_CONDITION  = 0
%CT_OR_CONDITION   = %CT_AND_CONDITION + 1
%CT_NOT_CONDITION  = %CT_OR_CONDITION  + 1
%CT_LEAF_CONDITION = %CT_NOT_CONDITION + 1

' enum CONDITION_OPERATION
%COP_IMPLICIT             = 0
%COP_EQUAL                = %COP_IMPLICIT           + 1
%COP_NOTEQUAL             = %COP_EQUAL              + 1
%COP_LESSTHAN             = %COP_NOTEQUAL           + 1
%COP_GREATERTHAN          = %COP_LESSTHAN           + 1
%COP_LESSTHANOREQUAL      = %COP_GREATERTHAN        + 1
%COP_GREATERTHANOREQUAL   = %COP_LESSTHANOREQUAL    + 1
%COP_VALUE_STARTSWITH     = %COP_GREATERTHANOREQUAL + 1
%COP_VALUE_ENDSWITH       = %COP_VALUE_STARTSWITH   + 1
%COP_VALUE_CONTAINS       = %COP_VALUE_ENDSWITH     + 1
%COP_VALUE_NOTCONTAINS    = %COP_VALUE_CONTAINS     + 1
%COP_DOSWILDCARDS         = %COP_VALUE_NOTCONTAINS  + 1
%COP_WORD_EQUAL           = %COP_DOSWILDCARDS       + 1
%COP_WORD_STARTSWITH      = %COP_WORD_EQUAL         + 1
%COP_APPLICATION_SPECIFIC = %COP_WORD_STARTSWITH    + 1


' ########################################################################################
' Interface name = IRichChunk
' IID = 4FDEF69C-DBC9-454E-9910-B34F3C64B510
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRichChunk_INTERFACE_DEFINED)
    %IRichChunk_INTERFACE_DEFINED = 1

$IID_IRichChunk = GUID$("{4FDEF69C-DBC9-454E-9910-B34F3C64B510}")

INTERFACE IRichChunk $IID_IRichChunk

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 12
     BYREF pFirstPos AS DWORD _                         ' __out ULONG *pFirstPos
   , BYREF pLength AS DWORD _                           ' __out ULONG *pLength
   , BYREF ppsz AS DWORD _                              ' __out LPWSTR *ppsz
   , BYREF pValue AS PROPVARIANT _                      ' __out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRichChunk_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICondition
' IID = 0FC988D4-C935-4B97-A973-46282EA175C8
' Inherited interface = IPersistStream
' ########################################################################################

#IF NOT %DEF(%ICondition_INTERFACE_DEFINED)
    %ICondition_INTERFACE_DEFINED = 1

$IID_ICondition = GUID$("{0FC988D4-C935-4B97-A973-46282EA175C8}")

INTERFACE ICondition $IID_ICondition

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersist methods
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPersistStream methods
   ' =====================================================================================
   METHOD IsDirty ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 20
     BYVAL pStm AS IStream _                            ' __in IStream * pStm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 24
     BYVAL pStm AS IStream _                            ' __in IStream * pStm
   , BYVAL fClearDirty AS LONG _                        ' __in BOOL fClearDirty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSizeMax ( _                                ' VTable offset = 28
     BYREF pcbSize AS QUAD _                            ' __out  ULARGE_INTEGER * pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICondition methods
   ' =====================================================================================
   METHOD GetConditionType ( _                          ' VTable offset = 32
     BYREF pNodeType AS LONG _                          ' __retval_out CONDITION_TYPE *pNodeType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSubConditions ( _                          ' VTable offset = 36
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __retval_out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetComparisonInfo ( _                         ' VTable offset = 40
     BYREF ppszPropertyName AS DWORD _                  ' __out LPWSTR *ppszPropertyName
   , BYREF pOperation AS LONG _                         ' __out CONDITION_OPERATION *pOperation
   , BYREF pValue AS PROPVARIANT _                      ' __out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValueType ( _                              ' VTable offset = 44
     BYREF ppszValueTypeName AS DWORD _                 ' __retval_out LPWSTR *ppszValueTypeName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValueNormalization ( _                     ' VTable offset = 48
     BYREF ppszNormalization AS DWORD _                 ' __retval_out LPWSTR *ppszNormalization
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputTerms ( _                             ' VTable offset = 52
     BYREF ppPropertyTerm AS IRichChunk _               ' __out IRichChunk **ppPropertyTerm
   , BYREF ppOperationTerm AS IRichChunk _              ' __out IRichChunk **ppOperationTerm
   , BYREF ppValueTerm AS IRichChunk _                  ' __out IRichChunk **ppValueTerm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 56
     BYREF ppc AS ICondition _                          ' __retval_out ICondition **ppc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICondition_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICondition2
' IID = 0DB8851D-2E5B-47EB-9208-D28C325A01D7
' Inherited interface = ICondition
' ########################################################################################

#IF NOT %DEF(%ICondition2_INTERFACE_DEFINED)
    %ICondition2_INTERFACE_DEFINED = 1

$IID_ICondition2 = GUID$("{0DB8851D-2E5B-47EB-9208-D28C325A01D7}")

INTERFACE ICondition2 $IID_ICondition2

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersist methods
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPersistStream methods
   ' =====================================================================================
   METHOD IsDirty ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 20
     BYVAL pStm AS IStream _                            ' __in IStream * pStm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 24
     BYVAL pStm AS IStream _                            ' __in IStream * pStm
   , BYVAL fClearDirty AS LONG _                        ' __in BOOL fClearDirty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSizeMax ( _                                ' VTable offset = 28
     BYREF pcbSize AS QUAD _                            ' __out  ULARGE_INTEGER * pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICondition methods
   ' =====================================================================================
   METHOD GetConditionType ( _                          ' VTable offset = 32
     BYREF pNodeType AS LONG _                          ' __retval_out CONDITION_TYPE *pNodeType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSubConditions ( _                          ' VTable offset = 36
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __retval_out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetComparisonInfo ( _                         ' VTable offset = 40
     BYREF ppszPropertyName AS DWORD _                  ' __out LPWSTR *ppszPropertyName
   , BYREF pOperation AS LONG _                         ' __out CONDITION_OPERATION *pOperation
   , BYREF pValue AS PROPVARIANT _                      ' __out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValueType ( _                              ' VTable offset = 44
     BYREF ppszValueTypeName AS DWORD _                 ' __retval_out LPWSTR *ppszValueTypeName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValueNormalization ( _                     ' VTable offset = 48
     BYREF ppszNormalization AS DWORD _                 ' __retval_out LPWSTR *ppszNormalization
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputTerms ( _                             ' VTable offset = 52
     BYREF ppPropertyTerm AS IRichChunk _               ' __out IRichChunk **ppPropertyTerm
   , BYREF ppOperationTerm AS IRichChunk _              ' __out IRichChunk **ppOperationTerm
   , BYREF ppValueTerm AS IRichChunk _                  ' __out IRichChunk **ppValueTerm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 56
     BYREF ppc AS ICondition _                          ' __retval_out ICondition **ppc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICondition2 methods
   ' =====================================================================================
   METHOD GetLocale ( _                                 ' VTable offset = 60
     BYREF ppszLocaleName AS DWORD _                    ' __out LPWSTR *ppszLocaleName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLeafConditionInfo ( _                      ' VTable offset = 64
     BYREF ppropkey AS PROPERTYKEY _                    ' __out_opt PROPERTYKEY *ppropkey
   , BYREF pcop AS LONG _                               ' __out_opt CONDITION_OPERATION *pcop
   , BYREF ppropvar AS PROPVARIANT _                    ' __out_opt PROPVARIANT *ppropvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICondition2_INTERFACE_DEFINED__ */
