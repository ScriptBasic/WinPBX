' ########################################################################################
' Microsoft Windows
' File: mfobjects.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MFOBJECTS_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "propsys.inc"
#INCLUDE ONCE "mediaobj.inc"

'typedef ULONGLONG QWORD;

#INCLUDE ONCE "mmreg.inc"

' enum MF_ATTRIBUTE_TYPE
%MF_ATTRIBUTE_UINT32   = %VT_UI4
%MF_ATTRIBUTE_UINT64   = %VT_UI8
%MF_ATTRIBUTE_DOUBLE   = %VT_R8
%MF_ATTRIBUTE_GUID     = %VT_CLSID
%MF_ATTRIBUTE_STRING   = %VT_LPWSTR
%MF_ATTRIBUTE_BLOB     = %VT_VECTOR OR %VT_UI1
%MF_ATTRIBUTE_IUNKNOWN = %VT_UNKNOWN

' enum MF_ATTRIBUTES_MATCH_TYPE
%MF_ATTRIBUTES_MATCH_OUR_ITEMS    = 0
%MF_ATTRIBUTES_MATCH_THEIR_ITEMS  = 1
%MF_ATTRIBUTES_MATCH_ALL_ITEMS    = 2
%MF_ATTRIBUTES_MATCH_INTERSECTION = 3
%MF_ATTRIBUTES_MATCH_SMALLER      = 4


' ########################################################################################
' Interface name = IMFAttributes
' IID = 2CD2D921-C447-44A7-A13C-4ADABFC247E3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFAttributes_INTERFACE_DEFINED)
    %IMFAttributes_INTERFACE_DEFINED = 1

$IID_IMFAttributes = GUID$("{2CD2D921-C447-44A7-A13C-4ADABFC247E3}")

INTERFACE IMFAttributes $IID_IMFAttributes

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 12
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemType ( _                               ' VTable offset = 16
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pType AS LONG _                              ' __out MF_ATTRIBUTE_TYPE *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareItem ( _                               ' VTable offset = 20
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __in REFPROPVARIANT Value
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Compare ( _                                   ' VTable offset = 24
     BYVAL pTheirs AS IMFAttributes _                   ' __in IMFAttributes *pTheirs
   , BYVAL MatchType AS LONG _                          ' __in MF_ATTRIBUTES_MATCH_TYPE MatchType
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT32 ( _                                 ' VTable offset = 28
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS DWORD _                          ' __out UINT32 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT64 ( _                                 ' VTable offset = 32
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS QUAD _                           ' __out UINT64 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDouble ( _                                 ' VTable offset = 36
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pfValue AS DOUBLE _                          ' __out double *pfValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGUID ( _                                   ' VTable offset = 40
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pguidValue AS GUID _                         ' __out GUID *pguidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringLength ( _                           ' VTable offset = 44
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetString ( _                                 ' VTable offset = 48
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pwszValue AS WSTRINGZ _                      ' __out LPWSTR pwszValue
   , BYVAL cchBufSize AS DWORD _                        ' __in UINT32 cchBufSize
   , BYREF pcchLength AS DWORD _                        ' __in_out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedString ( _                        ' VTable offset = 52
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF ppwszValue AS DWORD _                        ' __out LPWSTR *ppwszValue
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlobSize ( _                               ' VTable offset = 56
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcbBlobSize AS DWORD _                       ' __out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlob ( _                                   ' VTable offset = 60
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __out UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   , BYREF pcbBlobSize AS DWORD _                       ' __in_out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedBlob ( _                          ' VTable offset = 64
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL ppBuf AS DWORD _                             ' __out UINT8 **ppBuf
   , BYREF pcbSize AS DWORD _                           ' __out UINT32 *pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUnknown ( _                                ' VTable offset = 68
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out LPVOID *ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItem ( _                                   ' VTable offset = 72
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __out REFPROPVARIANT Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteItem ( _                                ' VTable offset = 76
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAllItems ( _                            ' VTable offset = 80
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT32 ( _                                 ' VTable offset = 84
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS DWORD _                           ' __in UINT32 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT64 ( _                                 ' VTable offset = 88
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS QUAD _                            ' __in UINT64 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDouble ( _                                 ' VTable offset = 92
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL fValue AS DOUBLE _                           ' __in double fValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGUID ( _                                   ' VTable offset = 96
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF guidValue AS GUID _                          ' __in REFGUID guidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetString ( _                                 ' VTable offset = 100
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF wszValue AS WSTRINGZ _                       ' __in LPCWSTR wszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBlob ( _                                   ' VTable offset = 104
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __in  const UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUnknown ( _                                ' VTable offset = 108
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pUnknown AS IUnknown _                       ' __in IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockStore ( _                                 ' VTable offset = 112
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockStore ( _                               ' VTable offset = 116
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 120
     BYREF pcItems AS DWORD _                           ' __out UINT32 *pcItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemByIndex ( _                            ' VTable offset = 124
     BYVAL unIndex AS DWORD _                           ' __in UINT32 unIndex
   , BYREF pguidKey AS GUID _                           ' __out GUID *pguidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyAllItems ( _                              ' VTable offset = 128
     BYVAL pDest AS LONG _                              ' __in IMFAttributes *pDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFAttributes_INTERFACE_DEFINED__ */


' enum MF_ATTRIBUTE_SERIALIZE_OPTIONS
%MF_ATTRIBUTE_SERIALIZE_UNKNOWN_BYREF = &H1

DECLARE FUNCTION MFSerializeAttributesToStream IMPORT "mfplat.dll" ALIAS "MFSerializeAttributesToStream" ( _
   BYVAL pAttr AS IMFAttributes _                       ' __in IMFAttributes * pAttr
 , BYVAL dwOptions AS DWORD _                           ' __in DWORD dwOptions
 , BYVAL pStm AS IStream _                              ' __in IStream * pStm
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFDeserializeAttributesFromStream IMPORT "mfplat.dll" ALIAS "MFDeserializeAttributesFromStream" ( _
   BYVAL pAttr AS IMFAttributes _                       ' __in IMFAttributes * pAttr
 , BYVAL dwOptions AS DWORD _                           ' __in DWORD dwOptions
 , BYVAL pStm AS IStream _                              ' __in IStream * pStm
 ) AS LONG                                              ' HRESULT


' ########################################################################################
' Interface name = IMFMediaBuffer
' IID = 045FA593-8799-42B8-BC8D-8968C6453507
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFMediaBuffer_INTERFACE_DEFINED)
    %IMFMediaBuffer_INTERFACE_DEFINED = 1

$IID_IMFMediaBuffer = GUID$("{045FA593-8799-42B8-BC8D-8968C6453507}")

INTERFACE IMFMediaBuffer $IID_IMFMediaBuffer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Lock ( _                                      ' VTable offset = 12
     BYREF ppbBuffer AS DWORD _                         ' __out BYTE **ppbBuffer
   , BYREF pcbMaxLength AS DWORD _                      ' __out DWORD *pcbMaxLength
   , BYREF pcbCurrentLength AS DWORD _                  ' __out DWORD *pcbCurrentLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unlock ( _                                    ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentLength ( _                          ' VTable offset = 20
     BYREF pcbCurrentLength AS DWORD _                  ' __out DWORD *pcbCurrentLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCurrentLength ( _                          ' VTable offset = 24
     BYVAL cbCurrentLength AS DWORD _                   ' __in DWORD cbCurrentLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxLength ( _                              ' VTable offset = 28
     BYREF pcbMaxLength AS DWORD _                      ' __out DWORD *pcbMaxLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFMediaBuffer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMFSample
' IID = C40A00F2-B93A-4D80-AE8C-5A1C634F58E4
' Inherited interface = IMFAttributes
' ########################################################################################

#IF NOT %DEF(%IMFSample_INTERFACE_DEFINED)
    %IMFSample_INTERFACE_DEFINED = 1

$IID_IMFSample = GUID$("{C40A00F2-B93A-4D80-AE8C-5A1C634F58E4}")

INTERFACE IMFSample $IID_IMFSample

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFAttributes methods
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 12
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemType ( _                               ' VTable offset = 16
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pType AS LONG _                              ' __out MF_ATTRIBUTE_TYPE *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareItem ( _                               ' VTable offset = 20
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __in REFPROPVARIANT Value
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Compare ( _                                   ' VTable offset = 24
     BYVAL pTheirs AS IMFAttributes _                   ' __in IMFAttributes *pTheirs
   , BYVAL MatchType AS LONG _                          ' __in MF_ATTRIBUTES_MATCH_TYPE MatchType
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT32 ( _                                 ' VTable offset = 28
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS DWORD _                          ' __out UINT32 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT64 ( _                                 ' VTable offset = 32
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS QUAD _                           ' __out UINT64 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDouble ( _                                 ' VTable offset = 36
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pfValue AS DOUBLE _                          ' __out double *pfValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGUID ( _                                   ' VTable offset = 40
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pguidValue AS GUID _                         ' __out GUID *pguidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringLength ( _                           ' VTable offset = 44
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetString ( _                                 ' VTable offset = 48
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pwszValue AS WSTRINGZ _                      ' __out LPWSTR pwszValue
   , BYVAL cchBufSize AS DWORD _                        ' __in UINT32 cchBufSize
   , BYREF pcchLength AS DWORD _                        ' __in_out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedString ( _                        ' VTable offset = 52
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF ppwszValue AS DWORD _                        ' __out LPWSTR *ppwszValue
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlobSize ( _                               ' VTable offset = 56
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcbBlobSize AS DWORD _                       ' __out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlob ( _                                   ' VTable offset = 60
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __out UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   , BYREF pcbBlobSize AS DWORD _                       ' __in_out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedBlob ( _                          ' VTable offset = 64
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL ppBuf AS DWORD _                             ' __out UINT8 **ppBuf
   , BYREF pcbSize AS DWORD _                           ' __out UINT32 *pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUnknown ( _                                ' VTable offset = 68
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out LPVOID *ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItem ( _                                   ' VTable offset = 72
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __out REFPROPVARIANT Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteItem ( _                                ' VTable offset = 76
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAllItems ( _                            ' VTable offset = 80
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT32 ( _                                 ' VTable offset = 84
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS DWORD _                           ' __in UINT32 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT64 ( _                                 ' VTable offset = 88
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS QUAD _                            ' __in UINT64 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDouble ( _                                 ' VTable offset = 92
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL fValue AS DOUBLE _                           ' __in double fValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGUID ( _                                   ' VTable offset = 96
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF guidValue AS GUID _                          ' __in REFGUID guidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetString ( _                                 ' VTable offset = 100
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF wszValue AS WSTRINGZ _                       ' __in LPCWSTR wszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBlob ( _                                   ' VTable offset = 104
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __in  const UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUnknown ( _                                ' VTable offset = 108
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pUnknown AS IUnknown _                       ' __in IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockStore ( _                                 ' VTable offset = 112
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockStore ( _                               ' VTable offset = 116
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 120
     BYREF pcItems AS DWORD _                           ' __out UINT32 *pcItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemByIndex ( _                            ' VTable offset = 124
     BYVAL unIndex AS DWORD _                           ' __in UINT32 unIndex
   , BYREF pguidKey AS GUID _                           ' __out GUID *pguidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyAllItems ( _                              ' VTable offset = 128
     BYVAL pDest AS LONG _                              ' __in IMFAttributes *pDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFSample methods
   ' =====================================================================================
   METHOD GetSampleFlags ( _                            ' VTable offset = 132
     BYREF pdwSampleFlags AS DWORD _                    ' __out DWORD *pdwSampleFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSampleFlags ( _                            ' VTable offset = 136
     BYVAL dwSampleFlags AS DWORD _                     ' __in DWORD dwSampleFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSampleTime ( _                             ' VTable offset = 140
     BYREF phnsSampleTime AS QUAD _                     ' __out LONGLONG *phnsSampleTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSampleTime ( _                             ' VTable offset = 144
     BYVAL hnsSampleTime AS QUAD _                      ' __in LONGLONG hnsSampleTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSampleDuration ( _                         ' VTable offset = 148
     BYREF phnsSampleDuration AS QUAD _                 ' __out LONGLONG *phnsSampleDuration
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSampleDuration ( _                         ' VTable offset = 152
     BYVAL hnsSampleDuration AS QUAD _                  ' __in LONGLONG hnsSampleDuration
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBufferCount ( _                            ' VTable offset = 156
     BYREF pdwBufferCount AS DWORD _                    ' __out DWORD *pdwBufferCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBufferByIndex ( _                          ' VTable offset = 160
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppBuffer AS IMFMediaBuffer _                 ' __out IMFMediaBuffer **ppBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertToContiguousBuffer ( _                 ' VTable offset = 164
     BYREF ppBuffer AS IMFMediaBuffer _                 ' __out IMFMediaBuffer **ppBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddBuffer ( _                                 ' VTable offset = 168
     BYVAL pBuffer AS IMFMediaBuffer _                  ' __in IMFMediaBuffer *pBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveBufferByIndex ( _                       ' VTable offset = 172
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAllBuffers ( _                          ' VTable offset = 176
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTotalLength ( _                            ' VTable offset = 180
     BYREF pcbTotalLength AS DWORD _                    ' __out DWORD *pcbTotalLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyToBuffer ( _                              ' VTable offset = 184
     BYVAL pBuffer AS IMFMediaBuffer _                  ' __in IMFMediaBuffer *pBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFSample_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMF2DBuffer
' IID = 7DC9D5F9-9ED9-44EC-9BBF-0600BB589FBB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMF2DBuffer_INTERFACE_DEFINED)
    %IMF2DBuffer_INTERFACE_DEFINED = 1

$IID_IMF2DBuffer = GUID$("{7DC9D5F9-9ED9-44EC-9BBF-0600BB589FBB}")

INTERFACE IMF2DBuffer $IID_IMF2DBuffer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Lock2D ( _                                    ' VTable offset = 12
     BYREF pbScanline0 AS DWORD _                       ' __out BYTE **pbScanline0
   , BYREF plPitch AS LONG _                            ' __out LONG *plPitch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unlock2D ( _                                  ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScanline0AndPitch ( _                      ' VTable offset = 20
     BYREF pbScanline0 AS DWORD _                       ' __out BYTE **pbScanline0
   , BYREF plPitch AS LONG _                            ' __out LONG *plPitch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsContiguousFormat ( _                        ' VTable offset = 24
     BYREF pfIsContiguous AS LONG _                     ' __out BOOL *pfIsContiguous
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContiguousLength ( _                       ' VTable offset = 28
     BYREF pcbLength AS DWORD _                         ' __out DWORD *pcbLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ContiguousCopyTo ( _                          ' VTable offset = 32
     BYVAL pbDestBuffer AS DWORD _                      ' __out BYTE *pbDestBuffer
   , BYVAL cbDestBuffer AS DWORD _                      ' __in DWORD cbDestBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ContiguousCopyFrom ( _                        ' VTable offset = 36
     BYVAL pbSrcBuffer AS DWORD _                       ' __in const BYTE *pbSrcBuffer
   , BYVAL cbSrcBuffer AS DWORD _                       ' __in DWORD cbSrcBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMF2DBuffer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMFMediaType
' IID = 44AE0FA8-EA31-4109-8D2E-4CAE4997C555
' Inherited interface = IMFAttributes
' ########################################################################################

#IF NOT %DEF(%IMFMediaType_INTERFACE_DEFINED)
    %IMFMediaType_INTERFACE_DEFINED = 1

$IID_IMFMediaType = GUID$("{44AE0FA8-EA31-4109-8D2E-4CAE4997C555}")

INTERFACE IMFMediaType $IID_IMFMediaType

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFAttributes methods
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 12
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemType ( _                               ' VTable offset = 16
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pType AS LONG _                              ' __out MF_ATTRIBUTE_TYPE *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareItem ( _                               ' VTable offset = 20
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __in REFPROPVARIANT Value
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Compare ( _                                   ' VTable offset = 24
     BYVAL pTheirs AS IMFAttributes _                   ' __in IMFAttributes *pTheirs
   , BYVAL MatchType AS LONG _                          ' __in MF_ATTRIBUTES_MATCH_TYPE MatchType
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT32 ( _                                 ' VTable offset = 28
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS DWORD _                          ' __out UINT32 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT64 ( _                                 ' VTable offset = 32
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS QUAD _                           ' __out UINT64 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDouble ( _                                 ' VTable offset = 36
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pfValue AS DOUBLE _                          ' __out double *pfValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGUID ( _                                   ' VTable offset = 40
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pguidValue AS GUID _                         ' __out GUID *pguidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringLength ( _                           ' VTable offset = 44
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetString ( _                                 ' VTable offset = 48
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pwszValue AS WSTRINGZ _                      ' __out LPWSTR pwszValue
   , BYVAL cchBufSize AS DWORD _                        ' __in UINT32 cchBufSize
   , BYREF pcchLength AS DWORD _                        ' __in_out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedString ( _                        ' VTable offset = 52
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF ppwszValue AS DWORD _                        ' __out LPWSTR *ppwszValue
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlobSize ( _                               ' VTable offset = 56
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcbBlobSize AS DWORD _                       ' __out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlob ( _                                   ' VTable offset = 60
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __out UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   , BYREF pcbBlobSize AS DWORD _                       ' __in_out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedBlob ( _                          ' VTable offset = 64
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL ppBuf AS DWORD _                             ' __out UINT8 **ppBuf
   , BYREF pcbSize AS DWORD _                           ' __out UINT32 *pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUnknown ( _                                ' VTable offset = 68
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out LPVOID *ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItem ( _                                   ' VTable offset = 72
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __out REFPROPVARIANT Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteItem ( _                                ' VTable offset = 76
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAllItems ( _                            ' VTable offset = 80
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT32 ( _                                 ' VTable offset = 84
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS DWORD _                           ' __in UINT32 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT64 ( _                                 ' VTable offset = 88
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS QUAD _                            ' __in UINT64 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDouble ( _                                 ' VTable offset = 92
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL fValue AS DOUBLE _                           ' __in double fValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGUID ( _                                   ' VTable offset = 96
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF guidValue AS GUID _                          ' __in REFGUID guidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetString ( _                                 ' VTable offset = 100
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF wszValue AS WSTRINGZ _                       ' __in LPCWSTR wszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBlob ( _                                   ' VTable offset = 104
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __in  const UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUnknown ( _                                ' VTable offset = 108
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pUnknown AS IUnknown _                       ' __in IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockStore ( _                                 ' VTable offset = 112
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockStore ( _                               ' VTable offset = 116
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 120
     BYREF pcItems AS DWORD _                           ' __out UINT32 *pcItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemByIndex ( _                            ' VTable offset = 124
     BYVAL unIndex AS DWORD _                           ' __in UINT32 unIndex
   , BYREF pguidKey AS GUID _                           ' __out GUID *pguidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyAllItems ( _                              ' VTable offset = 128
     BYVAL pDest AS LONG _                              ' __in IMFAttributes *pDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFMediaType methods
   ' =====================================================================================
   METHOD GetMajorType ( _                              ' VTable offset = 132
     BYREF pguidMajorType AS GUID _                     ' __out GUID *pguidMajorType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsCompressedFormat ( _                        ' VTable offset = 136
     BYREF pfCompressed AS LONG _                       ' __out BOOL *pfCompressed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsEqual ( _                                   ' VTable offset = 140
     BYVAL pIMediaType AS IMFMediaType _                ' __in IMFMediaType *pIMediaType
   , BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRepresentation ( _                         ' VTable offset = 144
     BYREF guidRepresentation AS GUID _                 ' __in GUID guidRepresentation
   , BYREF ppvRepresentation AS DWORD _                 ' __out LPVOID *ppvRepresentation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeRepresentation ( _                        ' VTable offset = 148
     BYREF guidRepresentation AS GUID _                 ' __in GUID guidRepresentation
   , BYVAL pvRepresentation AS DWORD _                  ' __in LPVOID pvRepresentation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFMediaType_INTERFACE_DEFINED__ */


%MF_MEDIATYPE_EQUAL_MAJOR_TYPES      = &H00000001???
%MF_MEDIATYPE_EQUAL_FORMAT_TYPES     = &H00000002???
%MF_MEDIATYPE_EQUAL_FORMAT_DATA      = &H00000004???
%MF_MEDIATYPE_EQUAL_FORMAT_USER_DATA = &H00000008???


' ########################################################################################
' Interface name = IMFAudioMediaType
' IID = 26A0ADC3-CE26-4672-9304-69552EDD3FAF
' Inherited interface = IMFMediaType
' ########################################################################################

#IF NOT %DEF(%IMFAudioMediaType_INTERFACE_DEFINED)
    %IMFAudioMediaType_INTERFACE_DEFINED = 1

$IID_IMFAudioMediaType = GUID$("{26A0ADC3-CE26-4672-9304-69552EDD3FAF}")

INTERFACE IMFAudioMediaType $IID_IMFAudioMediaType

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFAttributes methods
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 12
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemType ( _                               ' VTable offset = 16
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pType AS LONG _                              ' __out MF_ATTRIBUTE_TYPE *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareItem ( _                               ' VTable offset = 20
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __in REFPROPVARIANT Value
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Compare ( _                                   ' VTable offset = 24
     BYVAL pTheirs AS IMFAttributes _                   ' __in IMFAttributes *pTheirs
   , BYVAL MatchType AS LONG _                          ' __in MF_ATTRIBUTES_MATCH_TYPE MatchType
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT32 ( _                                 ' VTable offset = 28
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS DWORD _                          ' __out UINT32 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT64 ( _                                 ' VTable offset = 32
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS QUAD _                           ' __out UINT64 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDouble ( _                                 ' VTable offset = 36
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pfValue AS DOUBLE _                          ' __out double *pfValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGUID ( _                                   ' VTable offset = 40
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pguidValue AS GUID _                         ' __out GUID *pguidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringLength ( _                           ' VTable offset = 44
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetString ( _                                 ' VTable offset = 48
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pwszValue AS WSTRINGZ _                      ' __out LPWSTR pwszValue
   , BYVAL cchBufSize AS DWORD _                        ' __in UINT32 cchBufSize
   , BYREF pcchLength AS DWORD _                        ' __in_out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedString ( _                        ' VTable offset = 52
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF ppwszValue AS DWORD _                        ' __out LPWSTR *ppwszValue
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlobSize ( _                               ' VTable offset = 56
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcbBlobSize AS DWORD _                       ' __out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlob ( _                                   ' VTable offset = 60
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __out UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   , BYREF pcbBlobSize AS DWORD _                       ' __in_out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedBlob ( _                          ' VTable offset = 64
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL ppBuf AS DWORD _                             ' __out UINT8 **ppBuf
   , BYREF pcbSize AS DWORD _                           ' __out UINT32 *pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUnknown ( _                                ' VTable offset = 68
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out LPVOID *ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItem ( _                                   ' VTable offset = 72
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __out REFPROPVARIANT Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteItem ( _                                ' VTable offset = 76
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAllItems ( _                            ' VTable offset = 80
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT32 ( _                                 ' VTable offset = 84
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS DWORD _                           ' __in UINT32 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT64 ( _                                 ' VTable offset = 88
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS QUAD _                            ' __in UINT64 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDouble ( _                                 ' VTable offset = 92
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL fValue AS DOUBLE _                           ' __in double fValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGUID ( _                                   ' VTable offset = 96
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF guidValue AS GUID _                          ' __in REFGUID guidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetString ( _                                 ' VTable offset = 100
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF wszValue AS WSTRINGZ _                       ' __in LPCWSTR wszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBlob ( _                                   ' VTable offset = 104
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __in  const UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUnknown ( _                                ' VTable offset = 108
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pUnknown AS IUnknown _                       ' __in IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockStore ( _                                 ' VTable offset = 112
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockStore ( _                               ' VTable offset = 116
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 120
     BYREF pcItems AS DWORD _                           ' __out UINT32 *pcItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemByIndex ( _                            ' VTable offset = 124
     BYVAL unIndex AS DWORD _                           ' __in UINT32 unIndex
   , BYREF pguidKey AS GUID _                           ' __out GUID *pguidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyAllItems ( _                              ' VTable offset = 128
     BYVAL pDest AS LONG _                              ' __in IMFAttributes *pDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFMediaType methods
   ' =====================================================================================
   METHOD GetMajorType ( _                              ' VTable offset = 132
     BYREF pguidMajorType AS GUID _                     ' __out GUID *pguidMajorType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsCompressedFormat ( _                        ' VTable offset = 136
     BYREF pfCompressed AS LONG _                       ' __out BOOL *pfCompressed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsEqual ( _                                   ' VTable offset = 140
     BYVAL pIMediaType AS IMFMediaType _                ' __in IMFMediaType *pIMediaType
   , BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRepresentation ( _                         ' VTable offset = 144
     BYREF guidRepresentation AS GUID _                 ' __in GUID guidRepresentation
   , BYREF ppvRepresentation AS DWORD _                 ' __out LPVOID *ppvRepresentation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeRepresentation ( _                        ' VTable offset = 148
     BYREF guidRepresentation AS GUID _                 ' __in GUID guidRepresentation
   , BYVAL pvRepresentation AS DWORD _                  ' __in LPVOID pvRepresentation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFAudioMediaType method
   ' =====================================================================================
   METHOD GetAudioFormat ( _                            ' VTable offset = 152
   ) AS WAVEFORMATEX                                    ' WAVEFORMATEX *
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFAudioMediaType_INTERFACE_DEFINED__ */


#IF NOT %DEF(%WINGDI_INC)

' // Size = 40 bytes
TYPE BITMAPINFOHEADER DWORD FILL
   biSize          AS DWORD
   biWidth         AS LONG
   biHeight        AS LONG
   biPlanes        AS WORD
   biBitCount      AS WORD
   biCompression   AS DWORD
   biSizeImage     AS DWORD
   biXPelsPerMeter AS LONG
   biYPelsPerMeter AS LONG
   biClrUsed       AS DWORD
   biClrImportant  AS DWORD
END TYPE

' // Size = 44 bytes
TYPE BITMAPINFO DWORD
   bmiHeader     AS BITMAPINFOHEADER
   bmiColors (0) AS RGBQUAD            ' RGBQUAD
END TYPE

#ENDIF

' // Size = 32 bytes
#IF NOT %DEF(%MFT_REGISTER_TYPE_INFO_DEFINED)
%MFT_REGISTER_TYPE_INFO_DEFINED = 1
TYPE MFT_REGISTER_TYPE_INFO DWORD
   guidMajorType AS GUID
   guidSubtype   AS GUID
END TYPE
#ENDIF

#IF NOT %DEF(%MFVIDEOFORMAT)
    %MFVIDEOFORMAT = 1

' enum MFVideoInterlaceMode
%MFVideoInterlace_Unknown                     = 0???
%MFVideoInterlace_Progressive                 = 2???
%MFVideoInterlace_FieldInterleavedUpperFirst  = 3???
%MFVideoInterlace_FieldInterleavedLowerFirst  = 4???
%MFVideoInterlace_FieldSingleUpper            = 5???
%MFVideoInterlace_FieldSingleLower            = 6???
%MFVideoInterlace_MixedInterlaceOrProgressive = 7???
%MFVideoInterlace_Last                        = %MFVideoInterlace_MixedInterlaceOrProgressive + 1
%MFVideoInterlace_ForceDWORD                  = &H7fffffff???

%MFVideoInterlace_FieldSingleUpperFirst = %MFVideoInterlace_FieldSingleUpper
%MFVideoInterlace_FieldSingleLowerFirst = %MFVideoInterlace_FieldSingleLower

' enum MFVideoTransferFunction
%MFVideoTransFunc_Unknown    = 0???
%MFVideoTransFunc_10         = 1???
%MFVideoTransFunc_18         = 2???
%MFVideoTransFunc_20         = 3???
%MFVideoTransFunc_22         = 4???
%MFVideoTransFunc_709        = 5???
%MFVideoTransFunc_240M       = 6???
%MFVideoTransFunc_sRGB       = 7???
%MFVideoTransFunc_28         = 8???
%MFVideoTransFunc_Log_100    = 9???
%MFVideoTransFunc_Log_316    = 10???
%MFVideoTransFunc_709_sym    = 11???
%MFVideoTransFunc_Last       = %MFVideoTransFunc_709_sym + 1
%MFVideoTransFunc_ForceDWORD = &H7fffffff???

' enum MFVideoPrimaries
%MFVideoPrimaries_Unknown       = 0???
%MFVideoPrimaries_reserved      = 1???
%MFVideoPrimaries_BT709         = 2???
%MFVideoPrimaries_BT470_2_SysM  = 3???
%MFVideoPrimaries_BT470_2_SysBG = 4???
%MFVideoPrimaries_SMPTE170M     = 5???
%MFVideoPrimaries_SMPTE240M     = 6???
%MFVideoPrimaries_EBU3213       = 7???
%MFVideoPrimaries_SMPTE_C       = 8???
%MFVideoPrimaries_Last          = %MFVideoPrimaries_SMPTE_C + 1
%MFVideoPrimaries_ForceDWORD    = &H7fffffff???

' enum MFVideoLighting
%MFVideoLighting_Unknown    = 0???
%MFVideoLighting_bright     = 1???
%MFVideoLighting_office     = 2???
%MFVideoLighting_dim        = 3???
%MFVideoLighting_dark       = 4???
%MFVideoLighting_Last       = %MFVideoLighting_dark + 1
%MFVideoLighting_ForceDWORD = &H7fffffff???

' enum MFVideoTransferMatrix
%MFVideoTransferMatrix_Unknown    = 0???
%MFVideoTransferMatrix_BT709      = 1???
%MFVideoTransferMatrix_BT601      = 2???
%MFVideoTransferMatrix_SMPTE240M  = 3???
%MFVideoTransferMatrix_Last       = %MFVideoTransferMatrix_SMPTE240M + 1
%MFVideoTransferMatrix_ForceDWORD = &H7fffffff???

' enum MFVideoChromaSubsampling
%MFVideoChromaSubsampling_Unknown                        = 0???
%MFVideoChromaSubsampling_ProgressiveChroma              = &H8???
%MFVideoChromaSubsampling_Horizontally_Cosited           = &H4???
%MFVideoChromaSubsampling_Vertically_Cosited             = &H2???
%MFVideoChromaSubsampling_Vertically_AlignedChromaPlanes = &H1???
%MFVideoChromaSubsampling_MPEG2                          = %MFVideoChromaSubsampling_Horizontally_Cosited OR %MFVideoChromaSubsampling_Vertically_AlignedChromaPlanes
%MFVideoChromaSubsampling_MPEG1                          = %MFVideoChromaSubsampling_Vertically_AlignedChromaPlanes
%MFVideoChromaSubsampling_DV_PAL                         = %MFVideoChromaSubsampling_Horizontally_Cosited OR %MFVideoChromaSubsampling_Vertically_Cosited
%MFVideoChromaSubsampling_Cosited                        = (%MFVideoChromaSubsampling_Horizontally_Cosited OR %MFVideoChromaSubsampling_Vertically_Cosited)            OR %MFVideoChromaSubsampling_Vertically_AlignedChromaPlanes
%MFVideoChromaSubsampling_Last                           = %MFVideoChromaSubsampling_Cosited +  1
%MFVideoChromaSubsampling_ForceDWORD                     = &H7fffffff???

' enum MFNominalRange
%MFNominalRange_Unknown    = 0???
%MFNominalRange_Normal     = 1???
%MFNominalRange_Wide       = 2???
%MFNominalRange_0_255      = 1???
%MFNominalRange_16_235     = 2???
%MFNominalRange_48_208     = 3???
%MFNominalRange_64_127     = 4???
%MFNominalRange_Last       = %MFNominalRange_64_127 + 1
%MFNominalRange_ForceDWORD = &H7fffffff???

' enum MFVideoFlags
%MFVideoFlag_PAD_TO_Mask           = &H1??? OR &H2???
%MFVideoFlag_PAD_TO_None           = 0 * &H1???
%MFVideoFlag_PAD_TO_4x3            = 1 * &H1???
%MFVideoFlag_PAD_TO_16x9           = 2 * &H1???
%MFVideoFlag_SrcContentHintMask    = (&H4??? OR &H8???) OR &H10???
%MFVideoFlag_SrcContentHintNone    = 0 * &H4???
%MFVideoFlag_SrcContentHint16x9    = 1 * &H4???
%MFVideoFlag_SrcContentHint235_1   = 2 * &H4???
%MFVideoFlag_AnalogProtected       = &H20???
%MFVideoFlag_DigitallyProtected    = &H40???
%MFVideoFlag_ProgressiveContent    = &H80???
%MFVideoFlag_FieldRepeatCountMask  = (&H100??? OR &H200???) OR &H400???
%MFVideoFlag_FieldRepeatCountShift = 8???
%MFVideoFlag_ProgressiveSeqReset   = &H800???
%MFVideoFlag_PanScanEnabled        = &H20000???
%MFVideoFlag_LowerFieldFirst       = &H40000???
%MFVideoFlag_BottomUpLinearRep     = &H80000???
%MFVideoFlags_DXVASurface          = &H100000???
%MFVideoFlags_RenderTargetSurface  = &H400000???
%MFVideoFlags_ForceQWORD           = &H7fffffff???

' // Size = 8 bytes
TYPE MFRatio DWORD
   Numerator   AS DWORD   ' DWORD
   Denominator AS DWORD   ' DWORD
END TYPE

' // Size = 4 bytes
TYPE MFOffset WORD
   fract AS WORD      ' WORD
   value AS INTEGER   ' short
END TYPE

' // Size = 16 bytes
TYPE MFVideoArea DWORD
   OffsetX AS MFOffset
   OffsetY AS MFOffset
   Area    AS SIZE      ' SIZE
END TYPE

' // Size = 112 bytes
TYPE MFVideoInfo QWORD FILL
   dwWidth                 AS DWORD         ' DWORD
   dwHeight                AS DWORD         ' DWORD
   PixelAspectRatio        AS MFRatio
   SourceChromaSubsampling AS DWORD         ' MFVideoChromaSubsampling enum
   InterlaceMode           AS DWORD         ' MFVideoInterlaceMode enum
   TransferFunction        AS DWORD         ' MFVideoTransferFunction enum
   ColorPrimaries          AS DWORD         ' MFVideoPrimaries enum
   TransferMatrix          AS DWORD         ' MFVideoTransferMatrix enum
   SourceLighting          AS DWORD         ' MFVideoLighting enum
   FramesPerSecond         AS MFRatio
   NominalRange            AS DWORD         ' MFNominalRange enum
   GeometricAperture       AS MFVideoArea
   MinimumDisplayAperture  AS MFVideoArea
   PanScanAperture         AS MFVideoArea
   VideoFlags              AS QUAD          ' unsigned __int64
END TYPE

' // Size = 4 bytes
TYPE MFAYUVSample BYTE
   bCrValue      AS BYTE   ' BYTE
   bCbValue      AS BYTE   ' BYTE
   bYValue       AS BYTE   ' BYTE
   bSampleAlpha8 AS BYTE   ' BYTE
END TYPE

' // Size = 4 bytes
TYPE MFARGB BYTE
   rgbBlue  AS BYTE   ' BYTE
   rgbGreen AS BYTE   ' BYTE
   rgbRed   AS BYTE   ' BYTE
   rgbAlpha AS BYTE   ' BYTE
END TYPE

' // Size = 4 bytes
UNION MFPaletteEntry
   ARGB   AS MFARGB
   AYCbCr AS MFAYUVSample
END UNION

' // Size = 12 bytes
TYPE MFVideoSurfaceInfo DWORD
   Format         AS DWORD            ' DWORD
   PaletteEntries AS DWORD            ' DWORD
   Palette(0)     AS MFPaletteEntry
END TYPE

' // Size = 24 bytes
TYPE MFVideoCompressedInfo QWORD
   AvgBitrate         AS QUAD    ' LONGLONG
   AvgBitErrorRate    AS QUAD    ' LONGLONG
   MaxKeyFrameSpacing AS DWORD   ' DWORD
END TYPE

' // Size = 176 bytes
TYPE MFVIDEOFORMAT QWORD
   dwSize         AS DWORD   ' DWORD
   videoInfo      AS MFVideoInfo
   guidFormat     AS GUID
   compressedInfo AS MFVideoCompressedInfo
   surfaceInfo    AS MFVideoSurfaceInfo
END TYPE

' enum MFStandardVideoFormat
%MFStdVideoFormat_reserved     = 0
%MFStdVideoFormat_NTSC         = %MFStdVideoFormat_reserved     + 1
%MFStdVideoFormat_PAL          = %MFStdVideoFormat_NTSC         + 1
%MFStdVideoFormat_DVD_NTSC     = %MFStdVideoFormat_PAL          + 1
%MFStdVideoFormat_DVD_PAL      = %MFStdVideoFormat_DVD_NTSC     + 1
%MFStdVideoFormat_DV_PAL       = %MFStdVideoFormat_DVD_PAL      + 1
%MFStdVideoFormat_DV_NTSC      = %MFStdVideoFormat_DV_PAL       + 1
%MFStdVideoFormat_ATSC_SD480i  = %MFStdVideoFormat_DV_NTSC      + 1
%MFStdVideoFormat_ATSC_HD1080i = %MFStdVideoFormat_ATSC_SD480i  + 1
%MFStdVideoFormat_ATSC_HD720p  = %MFStdVideoFormat_ATSC_HD1080i + 1

#ENDIF


' ########################################################################################
' Interface name = IMFVideoMediaType
' IID = B99F381F-A8F9-47A2-A5AF-CA3A225A3890
' Inherited interface = IMFMediaType
' ########################################################################################

#IF NOT %DEF(%IMFVideoMediaType_INTERFACE_DEFINED)
    %IMFVideoMediaType_INTERFACE_DEFINED = 1

$IID_IMFVideoMediaType = GUID$("{B99F381F-A8F9-47A2-A5AF-CA3A225A3890}")

INTERFACE IMFVideoMediaType $IID_IMFVideoMediaType

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFAttributes methods
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 12
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemType ( _                               ' VTable offset = 16
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pType AS LONG _                              ' __out MF_ATTRIBUTE_TYPE *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareItem ( _                               ' VTable offset = 20
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __in REFPROPVARIANT Value
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Compare ( _                                   ' VTable offset = 24
     BYVAL pTheirs AS IMFAttributes _                   ' __in IMFAttributes *pTheirs
   , BYVAL MatchType AS LONG _                          ' __in MF_ATTRIBUTES_MATCH_TYPE MatchType
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT32 ( _                                 ' VTable offset = 28
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS DWORD _                          ' __out UINT32 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT64 ( _                                 ' VTable offset = 32
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS QUAD _                           ' __out UINT64 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDouble ( _                                 ' VTable offset = 36
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pfValue AS DOUBLE _                          ' __out double *pfValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGUID ( _                                   ' VTable offset = 40
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pguidValue AS GUID _                         ' __out GUID *pguidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringLength ( _                           ' VTable offset = 44
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetString ( _                                 ' VTable offset = 48
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pwszValue AS WSTRINGZ _                      ' __out LPWSTR pwszValue
   , BYVAL cchBufSize AS DWORD _                        ' __in UINT32 cchBufSize
   , BYREF pcchLength AS DWORD _                        ' __in_out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedString ( _                        ' VTable offset = 52
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF ppwszValue AS DWORD _                        ' __out LPWSTR *ppwszValue
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlobSize ( _                               ' VTable offset = 56
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcbBlobSize AS DWORD _                       ' __out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlob ( _                                   ' VTable offset = 60
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __out UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   , BYREF pcbBlobSize AS DWORD _                       ' __in_out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedBlob ( _                          ' VTable offset = 64
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL ppBuf AS DWORD _                             ' __out UINT8 **ppBuf
   , BYREF pcbSize AS DWORD _                           ' __out UINT32 *pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUnknown ( _                                ' VTable offset = 68
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out LPVOID *ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItem ( _                                   ' VTable offset = 72
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __out REFPROPVARIANT Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteItem ( _                                ' VTable offset = 76
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAllItems ( _                            ' VTable offset = 80
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT32 ( _                                 ' VTable offset = 84
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS DWORD _                           ' __in UINT32 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT64 ( _                                 ' VTable offset = 88
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS QUAD _                            ' __in UINT64 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDouble ( _                                 ' VTable offset = 92
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL fValue AS DOUBLE _                           ' __in double fValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGUID ( _                                   ' VTable offset = 96
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF guidValue AS GUID _                          ' __in REFGUID guidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetString ( _                                 ' VTable offset = 100
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF wszValue AS WSTRINGZ _                       ' __in LPCWSTR wszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBlob ( _                                   ' VTable offset = 104
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __in  const UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUnknown ( _                                ' VTable offset = 108
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pUnknown AS IUnknown _                       ' __in IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockStore ( _                                 ' VTable offset = 112
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockStore ( _                               ' VTable offset = 116
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 120
     BYREF pcItems AS DWORD _                           ' __out UINT32 *pcItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemByIndex ( _                            ' VTable offset = 124
     BYVAL unIndex AS DWORD _                           ' __in UINT32 unIndex
   , BYREF pguidKey AS GUID _                           ' __out GUID *pguidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyAllItems ( _                              ' VTable offset = 128
     BYVAL pDest AS LONG _                              ' __in IMFAttributes *pDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFMediaType methods
   ' =====================================================================================
   METHOD GetMajorType ( _                              ' VTable offset = 132
     BYREF pguidMajorType AS GUID _                     ' __out GUID *pguidMajorType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsCompressedFormat ( _                        ' VTable offset = 136
     BYREF pfCompressed AS LONG _                       ' __out BOOL *pfCompressed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsEqual ( _                                   ' VTable offset = 140
     BYVAL pIMediaType AS IMFMediaType _                ' __in IMFMediaType *pIMediaType
   , BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRepresentation ( _                         ' VTable offset = 144
     BYREF guidRepresentation AS GUID _                 ' __in GUID guidRepresentation
   , BYREF ppvRepresentation AS DWORD _                 ' __out LPVOID *ppvRepresentation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeRepresentation ( _                        ' VTable offset = 148
     BYREF guidRepresentation AS GUID _                 ' __in GUID guidRepresentation
   , BYVAL pvRepresentation AS DWORD _                  ' __in LPVOID pvRepresentation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFVideoMediaType methods
   ' =====================================================================================
   METHOD GetVideoFormat ( _                            ' VTable offset = 152
   ) AS MFVIDEOFORMAT                                   ' MFVIDEOFORMAT *
   ' =====================================================================================
   METHOD GetVideoRepresentation ( _                    ' VTable offset = 156
     BYVAL guidRepresentation AS GUID _                 ' __in GUID guidRepresentation
   , BYREF ppvRepresentation AS DWORD _                 ' __out LPVOID *ppvRepresentation
   , BYVAL lStride AS LONG _                            ' __in LONG lStride
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFVideoMediaType_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMFAsyncResult
' IID = AC6B7889-0740-4D51-8619-905994A55CC6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFAsyncResult_INTERFACE_DEFINED)
    %IMFAsyncResult_INTERFACE_DEFINED = 1

$IID_IMFAsyncResult = GUID$("{AC6B7889-0740-4D51-8619-905994A55CC6}")

INTERFACE IMFAsyncResult $IID_IMFAsyncResult

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 12
     BYREF ppunkState AS IUnknown _                     ' __out IUnknown **ppunkState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStatus ( _                                 ' VTable offset = 20
     BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObject ( _                                 ' VTable offset = 24
     BYREF ppObject AS IUnknown _                       ' __out IUnknown **ppObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStateNoAddRef ( _                          ' VTable offset = 28
   ) AS IUnknown                                        ' IUnknown
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFAsyncResult_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMFAsyncCallback
' IID = A27003CF-2354-4F2A-8D6A-AB7CFF15437E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFAsyncCallback_INTERFACE_DEFINED)
    %IMFAsyncCallback_INTERFACE_DEFINED = 1

$IID_IMFAsyncCallback = GUID$("{A27003CF-2354-4F2A-8D6A-AB7CFF15437E}")

INTERFACE IMFAsyncCallback $IID_IMFAsyncCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetParameters ( _                             ' VTable offset = 12
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   , BYREF pdwQueue AS DWORD _                          ' __out DWORD *pdwQueue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Invoke ( _                                    ' VTable offset = 16
     BYVAL pAsyncResult AS IMFAsyncResult _             ' __in IMFAsyncResult *pAsyncResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFAsyncCallback_INTERFACE_DEFINED__ */


%MFASYNC_FAST_IO_PROCESSING_CALLBACK  = &H00000001???
%MFASYNC_SIGNAL_CALLBACK              = &H00000002???
%MFASYNC_CALLBACK_QUEUE_UNDEFINED     = &H00000000???
%MFASYNC_CALLBACK_QUEUE_STANDARD      = &H00000001???
%MFASYNC_CALLBACK_QUEUE_RT            = &H00000002???
%MFASYNC_CALLBACK_QUEUE_IO            = &H00000003???
%MFASYNC_CALLBACK_QUEUE_TIMER         = &H00000004???
%MFASYNC_CALLBACK_QUEUE_LONG_FUNCTION = &H00000007???
%MFASYNC_CALLBACK_QUEUE_PRIVATE_MASK  = &HFFFF0000???
%MFASYNC_CALLBACK_QUEUE_ALL           = &HFFFFFFFF???

' enum __MIDL___MIDL_itf_mfobjects_0000_0009_0001
%MEUnknown                           = 0
%MEError                             = 1
%MEExtendedType                      = 2
%MENonFatalError                     = 3
%MEGenericV1Anchor                   = %MENonFatalError
%MESessionUnknown                    = 100
%MESessionTopologySet                = 101
%MESessionTopologiesCleared          = 102
%MESessionStarted                    = 103
%MESessionPaused                     = 104
%MESessionStopped                    = 105
%MESessionClosed                     = 106
%MESessionEnded                      = 107
%MESessionRateChanged                = 108
%MESessionScrubSampleComplete        = 109
%MESessionCapabilitiesChanged        = 110
%MESessionTopologyStatus             = 111
%MESessionNotifyPresentationTime     = 112
%MENewPresentation                   = 113
%MELicenseAcquisitionStart           = 114
%MELicenseAcquisitionCompleted       = 115
%MEIndividualizationStart            = 116
%MEIndividualizationCompleted        = 117
%MEEnablerProgress                   = 118
%MEEnablerCompleted                  = 119
%MEPolicyError                       = 120
%MEPolicyReport                      = 121
%MEBufferingStarted                  = 122
%MEBufferingStopped                  = 123
%MEConnectStart                      = 124
%MEConnectEnd                        = 125
%MEReconnectStart                    = 126
%MEReconnectEnd                      = 127
%MERendererEvent                     = 128
%MESessionStreamSinkFormatChanged    = 129
%MESessionV1Anchor                   = %MESessionStreamSinkFormatChanged
%MESourceUnknown                     = 200
%MESourceStarted                     = 201
%MEStreamStarted                     = 202
%MESourceSeeked                      = 203
%MEStreamSeeked                      = 204
%MENewStream                         = 205
%MEUpdatedStream                     = 206
%MESourceStopped                     = 207
%MEStreamStopped                     = 208
%MESourcePaused                      = 209
%MEStreamPaused                      = 210
%MEEndOfPresentation                 = 211
%MEEndOfStream                       = 212
%MEMediaSample                       = 213
%MEStreamTick                        = 214
%MEStreamThinMode                    = 215
%MEStreamFormatChanged               = 216
%MESourceRateChanged                 = 217
%MEEndOfPresentationSegment          = 218
%MESourceCharacteristicsChanged      = 219
%MESourceRateChangeRequested         = 220
%MESourceMetadataChanged             = 221
%MESequencerSourceTopologyUpdated    = 222
%MESourceV1Anchor                    = %MESequencerSourceTopologyUpdated
%MESinkUnknown                       = 300
%MEStreamSinkStarted                 = 301
%MEStreamSinkStopped                 = 302
%MEStreamSinkPaused                  = 303
%MEStreamSinkRateChanged             = 304
%MEStreamSinkRequestSample           = 305
%MEStreamSinkMarker                  = 306
%MEStreamSinkPrerolled               = 307
%MEStreamSinkScrubSampleComplete     = 308
%MEStreamSinkFormatChanged           = 309
%MEStreamSinkDeviceChanged           = 310
%MEQualityNotify                     = 311
%MESinkInvalidated                   = 312
%MEAudioSessionNameChanged           = 313
%MEAudioSessionVolumeChanged         = 314
%MEAudioSessionDeviceRemoved         = 315
%MEAudioSessionServerShutdown        = 316
%MEAudioSessionGroupingParamChanged  = 317
%MEAudioSessionIconChanged           = 318
%MEAudioSessionFormatChanged         = 319
%MEAudioSessionDisconnected          = 320
%MEAudioSessionExclusiveModeOverride = 321
%MESinkV1Anchor                      = %MEAudioSessionExclusiveModeOverride
%METrustUnknown                      = 400
%MEPolicyChanged                     = 401
%MEContentProtectionMessage          = 402
%MEPolicySet                         = 403
%METrustV1Anchor                     = %MEPolicySet
%MEWMDRMLicenseBackupCompleted       = 500
%MEWMDRMLicenseBackupProgress        = 501
%MEWMDRMLicenseRestoreCompleted      = 502
%MEWMDRMLicenseRestoreProgress       = 503
%MEWMDRMLicenseAcquisitionCompleted  = 506
%MEWMDRMIndividualizationCompleted   = 508
%MEWMDRMIndividualizationProgress    = 513
%MEWMDRMProximityCompleted           = 514
%MEWMDRMLicenseStoreCleaned          = 515
%MEWMDRMRevocationDownloadCompleted  = 516
%MEWMDRMV1Anchor                     = %MEWMDRMRevocationDownloadCompleted
%METransformUnknown                  = 600
%METransformNeedInput                = %METransformUnknown + 1
%METransformHaveOutput               = %METransformNeedInput + 1
%METransformDrainComplete            = %METransformHaveOutput + 1
%METransformMarker                   = %METransformDrainComplete + 1
%MEReservedMax                       = 10000

'typedef DWORD MediaEventType;

' ########################################################################################
' Interface name = IMFMediaEvent
' IID = DF598932-F10C-4E39-BBA2-C308F101DAA3
' Inherited interface = IMFAttributes
' ########################################################################################

#IF NOT %DEF(%IMFMediaEvent_INTERFACE_DEFINED)
    %IMFMediaEvent_INTERFACE_DEFINED = 1

$IID_IMFMediaEvent = GUID$("{DF598932-F10C-4E39-BBA2-C308F101DAA3}")

INTERFACE IMFMediaEvent $IID_IMFMediaEvent

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFAttributes methods
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 12
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemType ( _                               ' VTable offset = 16
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pType AS LONG _                              ' __out MF_ATTRIBUTE_TYPE *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareItem ( _                               ' VTable offset = 20
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __in REFPROPVARIANT Value
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Compare ( _                                   ' VTable offset = 24
     BYVAL pTheirs AS IMFAttributes _                   ' __in IMFAttributes *pTheirs
   , BYVAL MatchType AS LONG _                          ' __in MF_ATTRIBUTES_MATCH_TYPE MatchType
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT32 ( _                                 ' VTable offset = 28
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS DWORD _                          ' __out UINT32 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT64 ( _                                 ' VTable offset = 32
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS QUAD _                           ' __out UINT64 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDouble ( _                                 ' VTable offset = 36
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pfValue AS DOUBLE _                          ' __out double *pfValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGUID ( _                                   ' VTable offset = 40
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pguidValue AS GUID _                         ' __out GUID *pguidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringLength ( _                           ' VTable offset = 44
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetString ( _                                 ' VTable offset = 48
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pwszValue AS WSTRINGZ _                      ' __out LPWSTR pwszValue
   , BYVAL cchBufSize AS DWORD _                        ' __in UINT32 cchBufSize
   , BYREF pcchLength AS DWORD _                        ' __in_out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedString ( _                        ' VTable offset = 52
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF ppwszValue AS DWORD _                        ' __out LPWSTR *ppwszValue
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlobSize ( _                               ' VTable offset = 56
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcbBlobSize AS DWORD _                       ' __out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlob ( _                                   ' VTable offset = 60
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __out UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   , BYREF pcbBlobSize AS DWORD _                       ' __in_out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedBlob ( _                          ' VTable offset = 64
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL ppBuf AS DWORD _                             ' __out UINT8 **ppBuf
   , BYREF pcbSize AS DWORD _                           ' __out UINT32 *pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUnknown ( _                                ' VTable offset = 68
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out LPVOID *ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItem ( _                                   ' VTable offset = 72
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __out REFPROPVARIANT Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteItem ( _                                ' VTable offset = 76
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAllItems ( _                            ' VTable offset = 80
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT32 ( _                                 ' VTable offset = 84
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS DWORD _                           ' __in UINT32 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT64 ( _                                 ' VTable offset = 88
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS QUAD _                            ' __in UINT64 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDouble ( _                                 ' VTable offset = 92
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL fValue AS DOUBLE _                           ' __in double fValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGUID ( _                                   ' VTable offset = 96
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF guidValue AS GUID _                          ' __in REFGUID guidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetString ( _                                 ' VTable offset = 100
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF wszValue AS WSTRINGZ _                       ' __in LPCWSTR wszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBlob ( _                                   ' VTable offset = 104
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __in  const UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUnknown ( _                                ' VTable offset = 108
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pUnknown AS IUnknown _                       ' __in IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockStore ( _                                 ' VTable offset = 112
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockStore ( _                               ' VTable offset = 116
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 120
     BYREF pcItems AS DWORD _                           ' __out UINT32 *pcItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemByIndex ( _                            ' VTable offset = 124
     BYVAL unIndex AS DWORD _                           ' __in UINT32 unIndex
   , BYREF pguidKey AS GUID _                           ' __out GUID *pguidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyAllItems ( _                              ' VTable offset = 128
     BYVAL pDest AS LONG _                              ' __in IMFAttributes *pDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFMediaEvent methods
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 132
     BYREF pmet AS DWORD _                              ' __out MediaEventType *pmet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetExtendedType ( _                           ' VTable offset = 136
     BYREF pguidExtendedType AS GUID _                  ' __out GUID *pguidExtendedType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 140
     BYREF phrStatus AS LONG _                          ' __out HRESULT *phrStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 144
     BYREF pvValue AS PROPVARIANT _                     ' __out PROPVARIANT *pvValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFMediaEvent_INTERFACE_DEFINED__ */


%MF_EVENT_FLAG_NO_WAIT = &H00000001???


' ########################################################################################
' Interface name = IMFMediaEventGenerator
' IID = 2CD0BD52-BCD5-4B89-B62C-EADC0C031E7D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFMediaEventGenerator_INTERFACE_DEFINED)
    %IMFMediaEventGenerator_INTERFACE_DEFINED = 1

$IID_IMFMediaEventGenerator = GUID$("{2CD0BD52-BCD5-4B89-B62C-EADC0C031E7D}")

INTERFACE IMFMediaEventGenerator $IID_IMFMediaEventGenerator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetEvent ( _                                  ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppEvent AS IMFMediaEvent _                   ' __out IMFMediaEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginGetEvent ( _                             ' VTable offset = 16
     BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL punkState AS IUnknown _                      ' __in IUnknown *punkState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndGetEvent ( _                               ' VTable offset = 20
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   , BYREF ppEvent AS IMFMediaEvent _                   ' __out IMFMediaEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueueEvent ( _                                ' VTable offset = 24
     BYVAL met AS DWORD _                               ' __in MediaEventType met
   , BYREF guidExtendedType AS GUID _                   ' __in REFGUID guidExtendedType
   , BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   , BYREF pvValue AS PROPVARIANT _                     ' __in const PROPVARIANT *pvValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFMediaEventGenerator_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMFRemoteAsyncCallback
' IID = A27003D0-2354-4F2A-8D6A-AB7CFF15437E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFRemoteAsyncCallback_INTERFACE_DEFINED)
    %IMFRemoteAsyncCallback_INTERFACE_DEFINED = 1

$IID_IMFRemoteAsyncCallback = GUID$("{A27003D0-2354-4F2A-8D6A-AB7CFF15437E}")

INTERFACE IMFRemoteAsyncCallback $IID_IMFRemoteAsyncCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Invoke ( _                                    ' VTable offset = 12
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   , BYVAL pRemoteResult AS IUnknown _                  ' __in IUnknown *pRemoteResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFRemoteAsyncCallback_INTERFACE_DEFINED__ */


' enum MFBYTESTREAM_SEEK_ORIGIN
%msoBegin   = 0
%msoCurrent = %msoBegin + 1


' ########################################################################################
' Interface name = IMFByteStream
' IID = AD4C1B00-4BF7-422F-9175-756693D9130D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFByteStream_INTERFACE_DEFINED)
    %IMFByteStream_INTERFACE_DEFINED = 1

$IID_IMFByteStream = GUID$("{AD4C1B00-4BF7-422F-9175-756693D9130D}")

INTERFACE IMFByteStream $IID_IMFByteStream

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCapabilities ( _                           ' VTable offset = 12
     BYREF pdwCapabilities AS DWORD _                   ' __out DWORD *pdwCapabilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF pqwLength AS QUAD _                          ' __out QWORD *pqwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLength ( _                                 ' VTable offset = 20
     BYVAL qwLength AS QUAD _                           ' __in QWORD qwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentPosition ( _                        ' VTable offset = 24
     BYREF pqwPosition AS QUAD _                        ' __out QWORD *pqwPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCurrentPosition ( _                        ' VTable offset = 28
     BYVAL qwPosition AS QUAD _                         ' __in QWORD qwPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsEndOfStream ( _                             ' VTable offset = 32
     BYREF pfEndOfStream AS LONG _                      ' __out BOOL *pfEndOfStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Read ( _                                      ' VTable offset = 36
     BYVAL pb AS BYTE PTR _                             ' __in BYTE *pb
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbRead AS DWORD _                           ' __out ULONG *pcbRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginRead ( _                                 ' VTable offset = 40
     BYVAL pb AS BYTE PTR _                             ' __in BYTE *pb
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL punkState AS IUnknown _                      ' __in IUnknown *punkState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndRead ( _                                   ' VTable offset = 44
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   , BYREF pcbRead AS DWORD _                           ' __out ULONG *pcbRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Write ( _                                     ' VTable offset = 48
     BYVAL pb AS BYTE PTR _                             ' __in const BYTE *pb
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbWritten AS DWORD _                        ' __out ULONG *pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginWrite ( _                                ' VTable offset = 52
     BYVAL pb AS BYTE PTR _                             ' __in const BYTE *pb
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL punkState AS IUnknown _                      ' __in IUnknown *punkState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndWrite ( _                                  ' VTable offset = 56
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   , BYREF pcbWritten AS DWORD _                        ' __out ULONG *pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Seek ( _                                      ' VTable offset = 60
     BYVAL SeekOrigin AS LONG _                         ' __in MFBYTESTREAM_SEEK_ORIGIN SeekOrigin
   , BYVAL llSeekOffset AS QUAD _                       ' __in LONGLONG llSeekOffset
   , BYVAL dwSeekFlags AS DWORD _                       ' __in DWORD dwSeekFlags
   , BYREF pqwCurrentPosition AS QUAD _                 ' __out QWORD *pqwCurrentPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Flush ( _                                     ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFByteStream_INTERFACE_DEFINED__ */


%MFBYTESTREAM_IS_READABLE                 = &H00000001???
%MFBYTESTREAM_IS_WRITABLE                 = &H00000002???
%MFBYTESTREAM_IS_SEEKABLE                 = &H00000004???
%MFBYTESTREAM_IS_REMOTE                   = &H00000008???
%MFBYTESTREAM_IS_DIRECTORY                = &H00000080???
%MFBYTESTREAM_HAS_SLOW_SEEK               = &H00000100???
%MFBYTESTREAM_IS_PARTIALLY_DOWNLOADED     = &H00000200???
'#if (WINVER >= _WIN32_WINNT_WIN7)
%MFBYTESTREAM_SHARE_WRITE                 = &H00000400???
'#endif // (WINVER >= _WIN32_WINNT_WIN7)
%MFBYTESTREAM_SEEK_FLAG_CANCEL_PENDING_IO = &H00000001???

$MF_BYTESTREAM_ORIGIN_NAME        = GUID$("{FC358288-3CB6-460C-A424-B6681260375A}")
$MF_BYTESTREAM_CONTENT_TYPE       = GUID$("{FC358289-3CB6-460C-A424-B6681260375A}")
$MF_BYTESTREAM_DURATION           = GUID$("{FC35828A-3CB6-460C-A424-B6681260375A}")
$MF_BYTESTREAM_LAST_MODIFIED_TIME = GUID$("{FC35828B-3CB6-460C-A424-B6681260375A}")
'#if (WINVER >= _WIN32_WINNT_WIN7)
$MF_BYTESTREAM_IFO_FILE_URI       = GUID$("{FC35828C-3CB6-460C-A424-B6681260375A}")
$MF_BYTESTREAM_DLNA_PROFILE_ID    = GUID$("{FC35828D-3CB6-460C-A424-B6681260375A}")
'#endif // (WINVER >= _WIN32_WINNT_WIN7)

' enum MF_FILE_ACCESSMODE
%MF_ACCESSMODE_READ      = 1
%MF_ACCESSMODE_WRITE     = 2
%MF_ACCESSMODE_READWRITE = 3

' enum MF_FILE_OPENMODE
%MF_OPENMODE_FAIL_IF_NOT_EXIST = 0
%MF_OPENMODE_FAIL_IF_EXIST     = 1
%MF_OPENMODE_RESET_IF_EXIST    = 2
%MF_OPENMODE_APPEND_IF_EXIST   = 3
%MF_OPENMODE_DELETE_IF_EXIST   = 4

' enum MF_FILE_FLAGS
%MF_FILEFLAGS_NONE                = 0
%MF_FILEFLAGS_NOBUFFERING         = &H1
%MF_FILEFLAGS_ALLOW_WRITE_SHARING = &H2


' ########################################################################################
' Interface name = IMFCollection
' IID = 5BC8A76B-869A-46A3-9B03-FA218A66AEBE
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFCollection_INTERFACE_DEFINED)
    %IMFCollection_INTERFACE_DEFINED = 1

$IID_IMFCollection = GUID$("{5BC8A76B-869A-46A3-9B03-FA218A66AEBE}")

INTERFACE IMFCollection $IID_IMFCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetElementCount ( _                           ' VTable offset = 12
     BYREF pcElements AS DWORD _                        ' __out DWORD *pcElements
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetElement ( _                                ' VTable offset = 16
     BYVAL dwElementIndex AS DWORD _                    ' __in DWORD dwElementIndex
   , BYREF ppUnkElement AS IUnknown _                   ' __out IUnknown **ppUnkElement
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddElement ( _                                ' VTable offset = 20
     BYVAL pUnkElement AS IUnknown _                    ' __in IUnknown *pUnkElement
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveElement ( _                             ' VTable offset = 24
     BYVAL dwElementIndex AS DWORD _                    ' __in DWORD dwElementIndex
   , BYREF ppUnkElement AS IUnknown _                   ' __out IUnknown **ppUnkElement
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertElementAt ( _                           ' VTable offset = 28
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYVAL pUnknown AS IUnknown _                       ' __in IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAllElements ( _                         ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMFMediaEventQueue
' IID = 36F846FC-2256-48B6-B58E-E2B638316581
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFMediaEventQueue_INTERFACE_DEFINED)
    %IMFMediaEventQueue_INTERFACE_DEFINED = 1

$IID_IMFMediaEventQueue = GUID$("{36F846FC-2256-48B6-B58E-E2B638316581}")

INTERFACE IMFMediaEventQueue $IID_IMFMediaEventQueue

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetEvent ( _                                  ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppEvent AS IMFMediaEvent _                   ' __out IMFMediaEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginGetEvent ( _                             ' VTable offset = 16
     BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL punkState AS IUnknown _                      ' __in IUnknown *punkState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndGetEvent ( _                               ' VTable offset = 20
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   , BYREF ppEvent AS IMFMediaEvent _                   ' __out IMFMediaEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueueEvent ( _                                ' VTable offset = 24
     BYVAL pEvent AS IMFMediaEvent _                    ' __in IMFMediaEvent *pEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueueEventParamVar ( _                        ' VTable offset = 28
     BYVAL met AS DWORD _                               ' __in MediaEventType met
   , BYREF guidExtendedType AS GUID _                   ' __in REFGUID guidExtendedType
   , BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   , BYREF pvValue AS PROPVARIANT _                     ' __in const PROPVARIANT *pvValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueueEventParamUnk ( _                        ' VTable offset = 32
     BYVAL met AS DWORD _                               ' __in MediaEventType met
   , BYREF guidExtendedType AS GUID _                   ' __in REFGUID guidExtendedType
   , BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   , BYVAL pUnk AS IUnknown _                           ' __in IUnknown *pUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Shutdown ( _                                  ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFMediaEventQueue_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMFActivate
' IID = 7FEE9E9A-4A89-47A6-899C-B6A53A70FB67
' Inherited interface = IMFAttributes
' ########################################################################################

#IF NOT %DEF(%IMFActivate_INTERFACE_DEFINED)
    %IMFActivate_INTERFACE_DEFINED = 1

$IID_IMFActivate = GUID$("{7FEE9E9A-4A89-47A6-899C-B6A53A70FB67}")

INTERFACE IMFActivate $IID_IMFActivate

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFAttributes Methods
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 12
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemType ( _                               ' VTable offset = 16
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pType AS LONG _                              ' __out MF_ATTRIBUTE_TYPE *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareItem ( _                               ' VTable offset = 20
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __in REFPROPVARIANT Value
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Compare ( _                                   ' VTable offset = 24
     BYVAL pTheirs AS IMFAttributes _                   ' __in IMFAttributes *pTheirs
   , BYVAL MatchType AS LONG _                          ' __in MF_ATTRIBUTES_MATCH_TYPE MatchType
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT32 ( _                                 ' VTable offset = 28
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS DWORD _                          ' __out UINT32 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT64 ( _                                 ' VTable offset = 32
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS QUAD _                           ' __out UINT64 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDouble ( _                                 ' VTable offset = 36
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pfValue AS DOUBLE _                          ' __out double *pfValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGUID ( _                                   ' VTable offset = 40
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pguidValue AS GUID _                         ' __out GUID *pguidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringLength ( _                           ' VTable offset = 44
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetString ( _                                 ' VTable offset = 48
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pwszValue AS WSTRINGZ _                      ' __out LPWSTR pwszValue
   , BYVAL cchBufSize AS DWORD _                        ' __in UINT32 cchBufSize
   , BYREF pcchLength AS DWORD _                        ' __in_out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedString ( _                        ' VTable offset = 52
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF ppwszValue AS DWORD _                        ' __out LPWSTR *ppwszValue
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlobSize ( _                               ' VTable offset = 56
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcbBlobSize AS DWORD _                       ' __out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlob ( _                                   ' VTable offset = 60
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __out UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   , BYREF pcbBlobSize AS DWORD _                       ' __in_out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedBlob ( _                          ' VTable offset = 64
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL ppBuf AS DWORD _                             ' __out UINT8 **ppBuf
   , BYREF pcbSize AS DWORD _                           ' __out UINT32 *pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUnknown ( _                                ' VTable offset = 68
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out LPVOID *ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItem ( _                                   ' VTable offset = 72
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __out REFPROPVARIANT Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteItem ( _                                ' VTable offset = 76
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAllItems ( _                            ' VTable offset = 80
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT32 ( _                                 ' VTable offset = 84
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS DWORD _                           ' __in UINT32 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT64 ( _                                 ' VTable offset = 88
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS QUAD _                            ' __in UINT64 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDouble ( _                                 ' VTable offset = 92
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL fValue AS DOUBLE _                           ' __in double fValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGUID ( _                                   ' VTable offset = 96
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF guidValue AS GUID _                          ' __in REFGUID guidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetString ( _                                 ' VTable offset = 100
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF wszValue AS WSTRINGZ _                       ' __in LPCWSTR wszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBlob ( _                                   ' VTable offset = 104
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __in  const UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUnknown ( _                                ' VTable offset = 108
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pUnknown AS IUnknown _                       ' __in IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockStore ( _                                 ' VTable offset = 112
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockStore ( _                               ' VTable offset = 116
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 120
     BYREF pcItems AS DWORD _                           ' __out UINT32 *pcItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemByIndex ( _                            ' VTable offset = 124
     BYVAL unIndex AS DWORD _                           ' __in UINT32 unIndex
   , BYREF pguidKey AS GUID _                           ' __out GUID *pguidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyAllItems ( _                              ' VTable offset = 128
     BYVAL pDest AS LONG _                              ' __in IMFAttributes *pDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFActivate Methods
   ' =====================================================================================
   METHOD ActivateObject ( _                            ' VTable offset = 132
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __retval_out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShutdownObject ( _                            ' VTable offset = 136
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DetachObject ( _                              ' VTable offset = 140
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFActivate_INTERFACE_DEFINED__ */

'#if (WINVER >= _WIN32_WINNT_WIN7)

' enum MF_Plugin_Type
%MF_Plugin_Type_MFT         = 0
%MF_Plugin_Type_MediaSource = 1

' ########################################################################################
' Interface name = IMFPluginControl
' IID = 36F846FC-2256-48B6-B58E-E2B638316581
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFPluginControl_INTERFACE_DEFINED)
    %IMFPluginControl_INTERFACE_DEFINED = 1

$IID_IMFPluginControl = GUID$("{36F846FC-2256-48B6-B58E-E2B638316581}")

INTERFACE IMFPluginControl $IID_IMFPluginControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPreferredClsid ( _                         ' VTable offset = 12
     BYVAL pluginType AS DWORD _                        ' __in DWORD pluginType
   , BYREF selector AS WSTRINGZ _                       ' __in LPCWSTR selector
   , BYREF clsid AS GUID _                              ' __out CLSID *clsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPreferredClsidByIndex ( _                  ' VTable offset = 16
     BYVAL pluginType AS DWORD _                        ' __in DWORD pluginType
   , BYVAL index AS DWORD _                             ' __in DWORD index
   , BYREF selector AS DWORD _                          ' __out LPWSTR *selector
   , BYREF clsid AS GUID _                              ' __out CLSID *clsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPreferredClsid ( _                         ' VTable offset = 20
     BYVAL pluginType AS DWORD _                        ' __in DWORD pluginType
   , BYREF selector AS WSTRINGZ _                       ' __in LPCWSTR selector
   , BYREF clsid AS GUID _                              ' __in_opt const CLSID *clsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDisabled ( _                                ' VTable offset = 24
     BYVAL pluginType AS DWORD _                        ' __in DWORD pluginType
   , BYREF clsid AS GUID _                              ' __in_opt const CLSID *clsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisabledByIndex ( _                        ' VTable offset = 28
     BYVAL pluginType AS DWORD _                        ' __in DWORD pluginType
   , BYVAL index AS DWORD _                             ' __in DWORD index
   , BYREF clsid AS GUID _                              ' __out CLSID *clsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDisabled ( _                               ' VTable offset = 32
     BYVAL pluginType AS DWORD _                        ' __in DWORD pluginType
   , BYREF clsid AS GUID _                              ' __in REFCLSID clsid
   , BYVAL disabled AS LONG _                           ' __in BOOL disabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFPluginControl_INTERFACE_DEFINED__ */

'#endif // (WINVER >= _WIN32_WINNT_WIN7)
