' ########################################################################################
' Microsoft Windows
' File: ImgUtil.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: ImgUtilLib
' Version: 1.0, Locale ID = 0
' Documentation string: ImgUtil 1.0 Type Library
' Library GUID: {CF790840-2DC4-11D0-B724-00AA006C1A01}
' ########################################################################################

#INCLUDE THIS ONCE
%IMGUTIL_INC = 1

$LIBID_ImgUtilLib = GUID$("{CF790840-2DC4-11D0-B724-00AA006C1A01}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {A860CE50-3910-11D0-86FC-00A0C913F750}
$PROGID_CoDitherToRGB881 = "ImgUtil.CoDitherToRGB8.1"
' CLSID = {30C3B080-30FB-11D0-B724-00AA006C1A01}
$PROGID_CoMapMIMEToCLSID1 = "ImgUtil.CoMapMIMEToCLSID.1"
' CLSID = {6A01FDA0-30DF-11D0-B724-00AA006C1A01}
$PROGID_CoSniffStream1 = "ImgUtil.CoSniffStream.1"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_CoDitherToRGB8 = GUID$("{A860CE50-3910-11D0-86FC-00A0C913F750}")
$CLSID_CoMapMIMEToCLSID = GUID$("{30C3B080-30FB-11D0-B724-00AA006C1A01}")
$CLSID_CoSniffStream = GUID$("{6A01FDA0-30DF-11D0-B724-00AA006C1A01}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ISniffStream = GUID$("{4EF17940-30E0-11D0-B724-00AA006C1A01}")
$IID_IDithererImpl = GUID$("{7C48E840-3910-11D0-86FC-00A0C913F750}")


'/* header files for imported files */
#INCLUDE ONCE "ocmm.inc"
#INCLUDE ONCE "ddraw.inc"

DECLARE FUNCTION CreateMIMEMap IMPORT "ImgUtil.dll" ALIAS "CreateMIMEMap" ( _
   BYREF ppMap AS IMapMIMEToCLSID _                     ' __out IMapMIMEToCLSID** ppMap
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DecodeImage IMPORT "ImgUtil.dll" ALIAS "DecodeImage" ( _
   BYVAL pStream AS IStream _                           ' __in IStream* pStream
 , BYVAL pMap AS IMapMIMEToCLSID _                      ' __in IMapMIMEToCLSID* pMap
 , BYVAL pEventSink AS IUnknown _                       ' __in IUnknown* pEventSink
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SniffStream IMPORT "ImgUtil.dll" ALIAS "SniffStream" ( _
   BYVAL pInStream AS IStream _                         ' __in IStream* pInStream
 , BYREF pInStream AS DWORD _                           ' __out UINT* pnFormat
 , BYREF ppOutStream AS IUnknown _                      ' __out IUnknown* ppOutStream
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION GetMaxMIMEIDBytes IMPORT "ImgUtil.dll" ALIAS "GetMaxMIMEIDBytes" ( _
   BYREF pnMaxBytes AS DWORD _                          ' __in ULONG* pnMaxBytes
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION IdentifyMIMEType IMPORT "ImgUtil.dll" ALIAS "IdentifyMIMEType" ( _
   BYVAL pbBytes AS BYTE PTR _                          ' __in const BYTE* pbBytes
 , BYVAL nBytes AS DWORD _                              ' __in ULONG nBytes
 , BYREF pnFormat AS DWORD _                            ' __out UINT* pnFormat
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ComputeInvCMAP IMPORT "ImgUtil.dll" ALIAS "ComputeInvCMAP" ( _
   BYREF pRGBColors AS RGBQUAD _                        ' __in const RGBQUAD *pRGBColors
 , BYVAL nColors AS DWORD _                             ' __in ULONG nColors
 , BYVAL pInvTable AS BYTE PTR _                        ' __in BYTE *pInvTable
 , BYVAL cbTable AS DWORD _                             ' __in ULONG cbTable
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DitherTo8 IMPORT "ImgUtil.dll" ALIAS "DitherTo8" ( _
   BYVAL pDestBits AS BYTE PTR _                        ' __in BYTE * pDestBits
 , BYVAL nDestPitch AS LONG _                           ' __in LONG nDestPitch
 , BYVAL pSrcBits AS BYTE PTR _                         ' __in BYTE * pSrcBits
 , BYVAL nSrcPitch AS LONG _                            ' __in LONG nSrcPitch
 , BYREF bfidSrc AS GUID _                              ' __in REFGUID bfidSrc
 , BYREF prgbDestColors AS RGBQUAD _                    ' __in RGBQUAD * prgbDestColors
 , BYREF prgbSrcColors AS RGBQUAD _                     ' __in RGBQUAD * prgbSrcColors
 , BYVAL pbDestInvMap AS BYTE PTR _                     ' __in BYTE * pbDestInvMap
 , BYVAL x AS LONG _                                    ' __in LONG x
 , BYVAL y AS LONG _                                    ' __in LONG y
 , BYVAL cx AS LONG _                                   ' __in LONG cx
 , BYVAL cy AS LONG _                                   ' __in LONG cy
 , BYVAL lDestTrans AS LONG _                           ' __in LONG lDestTrans
 , BYVAL lSrcTrans AS LONG _                            ' __in LONG lSrcTrans
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateDDrawSurfaceOnDIB IMPORT "ImgUtil.dll" ALIAS "CreateDDrawSurfaceOnDIB" ( _
   BYVAL hbmDib AS DWORD _                              ' __in HBITMAP hbmDib
 , BYREF ppSurface AS IDirectDrawSurface _              ' __out IDirectDrawSurface **ppSurface
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DecodeImageEx IMPORT "ImgUtil.dll" ALIAS "DecodeImageEx" ( _
   BYVAL pStream AS IStream _                           ' __in IStream* pStream
 , BYVAL pMap AS IMapMIMEToCLSID _                      ' __in IMapMIMEToCLSID* pMap
 , BYVAL pEventSink AS IUnknown _                       ' __in IUnknown* pEventSink
 , BYREF pszMIMETypeParam AS WSTRINGZ _                 ' __in LPCWSTR pszMIMETypeParam
 ) AS LONG                                              ' HRESULT

' ########################################################################################
' Interface name = ISniffStream
' IID = 4EF17940-30E0-11D0-B724-00AA006C1A01
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISniffStream_INTERFACE_DEFINED)
    %ISniffStream_INTERFACE_DEFINED = 1

INTERFACE ISniffStream $IID_ISniffStream

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Init ( _                                      ' VTable offset = 12
     BYVAL pStream AS IStream _                         ' __in IStream *pStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Peek ( _                                      ' VTable offset = 16
     BYVAL pBuffer AS DWORD _                           ' __in void *pBuffer
   , BYVAL nBytes AS DWORD _                            ' __in ULONG nBytes
   , BYREF pnBytesRead AS DWORD _                       ' __out ULONG *pnBytesRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISniffStream_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDithererImpl
' IID = 7C48E840-3910-11D0-86FC-00A0C913F750
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDithererImpl_INTERFACE_DEFINED)
    %IDithererImpl_INTERFACE_DEFINED = 1

INTERFACE IDithererImpl $IID_IDithererImpl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetDestColorTable ( _                         ' VTable offset = 12
     BYVAL nColors AS DWORD _                           ' __in ULONG nColors
   , BYREF prgbColors AS RGBQUAD _                      ' __in const RGBQUAD *prgbColors
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEventSink ( _                              ' VTable offset = 16
     BYVAL pEventSink AS IImageDecodeEventSink _        ' __in IImageDecodeEventSink *pEventSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDithererImpl_INTERFACE_DEFINED__ */
