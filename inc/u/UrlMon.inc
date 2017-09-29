' ########################################################################################
' Microsoft Windows
' File: UrlMon.inc
' Contents: URL monikers allow an application to bind a resource--which is specified by a
' URL--to a moniker.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%URLMON_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "oleidl.inc"
#INCLUDE ONCE "servprov.inc"
#INCLUDE ONCE "msxml.inc"

'//=--------------------------------------------------------------------------=
'// UrlMon.h
'//=--------------------------------------------------------------------------=
'// Copyright (c) Microsoft Corporation.  All rights reserved.
'//
'// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
'// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
'// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
'// PARTICULAR PURPOSE.
'//=--------------------------------------------------------------------------=

'#pragma comment(lib,"uuid.lib")

'//---------------------------------------------------------------------------=
'// URL Moniker Interfaces.

'EXTERN_C const IID IID_IAsyncMoniker;
'EXTERN_C const IID CLSID_StdURLMoniker;
'EXTERN_C const IID CLSID_HttpProtocol;
'EXTERN_C const IID CLSID_FtpProtocol;
'EXTERN_C const IID CLSID_GopherProtocol;
'EXTERN_C const IID CLSID_HttpSProtocol;
'EXTERN_C const IID CLSID_FileProtocol;
'EXTERN_C const IID CLSID_MkProtocol;
'EXTERN_C const IID CLSID_StdURLProtocol;
'EXTERN_C const IID CLSID_UrlMkBindCtx;
'EXTERN_C const IID CLSID_StdEncodingFilterFac;
'EXTERN_C const IID CLSID_DeCompMimeFilter;
'EXTERN_C const IID CLSID_CdlProtocol;
'EXTERN_C const IID CLSID_ClassInstallFilter;
'EXTERN_C const IID IID_IAsyncBindCtx;

$IID_IAsyncBindCtx          = GUID$("{79EAC9D4-BAF9-11CE-8C82-00AA004BA90B}")
$CLSID_StdURLMoniker        = GUID$("{79EAC9E0-BAF9-11CE-8C82-00AA004BA90B}")
$CLSID_HttpProtocol         = GUID$("{79EAC9E2-BAF9-11CE-8C82-00AA004BA90B}")
$CLSID_FtpProtocol          = GUID$("{79EAC9E3-BAF9-11CE-8C82-00AA004BA90B}")
$CLSID_GopherProtocol       = GUID$("{79EAC9E4-BAF9-11CE-8C82-00AA004BA90B}")
$CLSID_HttpSProtocol        = GUID$("{79EAC9E5-BAF9-11CE-8C82-00AA004BA90B}")
$CLSID_FileProtocol         = GUID$("{79EAC9E7-BAF9-11CE-8C82-00AA004BA90B}")
$CLSID_MkProtocol           = GUID$("{79EAC9E6-BAF9-11CE-8C82-00AA004BA90B}")
$CLSID_StdURLProtocol       = GUID$("{79EAC9E1-BAF9-11CE-8C82-00AA004BA90B}")
$CLSID_UrlMkBindCtx         = GUID$("{F2C9EA79-F9BA-CE11-8C82-00AA004BA90B}")
$CLSID_StdEncodingFilterFac = GUID$("{D07CC354-44D9-D011-A9F4-006097942311}")
$CLSID_DeCompMimeFilter     = GUID$("{60036B8F-0DB8-D011-A9B3-006097942311}")
$CLSID_CdlProtocol          = GUID$("{3DD53D40-7B8B-11D0-B013-00AA0059CE02}")
$CLSID_ClassInstallFilter   = GUID$("{BB33B532-AEED-D011-BD5A-00AA00B92AF1}")

'#define SZ_URLCONTEXT      OLESTR("URL Context")
'#define SZ_ASYNC_CALLEE    OLESTR("AsyncCallee")
$SZ_URLCONTEXT         = "URL Context"
$SZ_ASYNC_CALLEE       = "AsyncCallee"

%MKSYS_URLMONIKER           = 6
%URL_MK_LEGACY              = 0
%URL_MK_UNIFORM             = 1
%URL_MK_NO_CANONICALIZE     = 2

'// Side-by-Side clsid
'EXTERN_C const IID CLSID_SBS_StdURLMoniker;
'EXTERN_C const IID CLSID_SBS_HttpProtocol;
'EXTERN_C const IID CLSID_SBS_FtpProtocol;
'EXTERN_C const IID CLSID_SBS_GopherProtocol;
'EXTERN_C const IID CLSID_SBS_HttpSProtocol;
'EXTERN_C const IID CLSID_SBS_FileProtocol;
'EXTERN_C const IID CLSID_SBS_MkProtocol;
'EXTERN_C const IID CLSID_SBS_UrlMkBindCtx;
'EXTERN_C const IID CLSID_SBS_SoftDistExt;
'EXTERN_C const IID CLSID_SBS_StdEncodingFilterFac;
'EXTERN_C const IID CLSID_SBS_DeCompMimeFilter;
'EXTERN_C const IID CLSID_SBS_CdlProtocol;
'EXTERN_C const IID CLSID_SBS_ClassInstallFilter;
'EXTERN_C const IID CLSID_SBS_InternetSecurityManager;
'EXTERN_C const IID CLSID_SBS_InternetZoneManager;
'// END Side-by-Side clsid

$CLSID_SBS_StdURLMoniker               = $CLSID_StdURLMoniker
$CLSID_SBS_HttpProtocol                = $CLSID_HttpProtocol
$CLSID_SBS_FtpProtocol                 = $CLSID_FtpProtocol
$CLSID_SBS_GopherProtocol              = $CLSID_GopherProtocol
$CLSID_SBS_HttpSProtocol               = $CLSID_HttpSProtocol
$CLSID_SBS_FileProtocol                = $CLSID_FileProtocol
$CLSID_SBS_MkProtocol                  = $CLSID_MkProtocol
$CLSID_SBS_UrlMkBindCtx                = $CLSID_UrlMkBindCtx
$CLSID_SBS_StdEncodingFilterFac        = $CLSID_StdEncodingFilterFac
$CLSID_SBS_DeCompMimeFilter            = $CLSID_DeCompMimeFilter
$CLSID_SBS_CdlProtocol                 = $CLSID_CdlProtocol
$CLSID_SBS_ClassInstallFilter          = $CLSID_ClassInstallFilter

'// These are for backwards compatibility with previous URLMON versions

'#define BINDF_DONTUSECACHE BINDF_GETNEWESTVERSION
'#define BINDF_DONTPUTINCACHE BINDF_NOWRITECACHE
'#define BINDF_NOCOPYDATA BINDF_PULLDATA
'#define INVALID_P_ROOT_SECURITY_ID ((BYTE*)-1)
'#define PI_DOCFILECLSIDLOOKUP PI_CLSIDLOOKUP

%INVALID_P_ROOT_SECURITY_ID = -1  ' ((BYTE*)-1)

DECLARE FUNCTION CreateURLMoniker IMPORT "URLMON.DLL" ALIAS "CreateURLMoniker" ( _
   BYVAL pmkContext AS IMoniker _                       ' __in IMoniker *pmkContext
 , BYREF szURL AS WSTRINGZ _                            ' __in LPCWSTR szURL
 , BYREF ppmk AS IMoniker _                             ' __out LPMONIKER FAR * ppmk
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateURLMonikerEx IMPORT "URLMON.DLL" ALIAS "CreateURLMonikerEx" ( _
   BYVAL pMkCtx AS IMoniker _                           ' __in LPMONIKER pMkCtx
 , BYREF szURL AS WSTRINGZ _                            ' __in LPCWSTR szURL
 , BYREF ppmk AS IMoniker _                             ' __out LPMONIKER FAR * ppmk
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

' Not implemented.
'STDAPI GetClassURL(LPCWSTR szURL, CLSID *pClsID);
'DECLARE FUNCTION GetClassURL IMPORT "URLMON.DLL" ALIAS "GetClassURL" ( _
' , BYREF szURL AS WSTRINGZ _                            ' __in LPCWSTR szURL
' , BYREF pClsID AS GUID _                               ' __out CLSID *pClsID
' ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateAsyncBindCtx IMPORT "URLMON.DLL" ALIAS "CreateAsyncBindCtx" ( _
   BYVAL reserved AS DWORD _                            ' __in DWORD reserved
 , BYVAL pbscb AS IBindStatusCallback _                 ' __in IBindStatusCallback *pbscb
 , BYVAL pEFetc AS IEnumFORMATETC _                     ' __in IEnumFORMATETC *pEFetc
 , BYREF ppbc AS IBindCtx _                             ' __out IBindCtx **ppbc
 ) AS LONG                                              ' HRESULT

'#if (_WIN32_IE >= _WIN32_IE_IE70)
DECLARE FUNCTION CreateURLMonikerEx2 IMPORT "URLMON.DLL" ALIAS "CreateURLMonikerEx2" ( _
   BYVAL pMkCtx AS IMoniker _                           ' __in LPMONIKER pMkCtx
 , BYVAL pUri AS IUri _                                 ' __in IUri* pUri
 , BYREF ppmk AS IMoniker _                             ' __out LPMONIKER FAR * ppmk
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT
'#endif

DECLARE FUNCTION CreateAsyncBindCtxEx IMPORT "URLMON.DLL" ALIAS "CreateAsyncBindCtxEx" ( _
   BYVAL pbc AS IBindCtx _                              ' __in IBindCtx *pbc
 , BYVAL dwOptions AS DWORD _                           ' __in DWORD dwOptions
 , BYVAL pbscb AS IBindStatusCallback _                 ' __in IBindStatusCallback *pbscb
 , BYVAL pEnum AS IEnumFORMATETC _                      ' __in IEnumFORMATETC *pEnum
 , BYREF ppbc AS IBindCtx _                             ' __out IBindCtx **ppbc
 , BYVAL reserved AS DWORD _                            ' __in DWORD reserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MkParseDisplayNameEx IMPORT "URLMON.DLL" ALIAS "MkParseDisplayNameEx" ( _
   BYVAL pbc AS IBindCtx _                              ' __in IBindCtx *pbc
 , BYREF szDisplayName AS WSTRINGZ _                    ' __in LPCWSTR szDisplayName
 , BYREF pchEaten AS DWORD _                            ' __out ULONG *pchEaten
 , BYREF ppmk AS IMoniker _                             ' __out LPMONIKER *ppmk
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RegisterBindStatusCallback IMPORT "URLMON.DLL" ALIAS "RegisterBindStatusCallback" ( _
   BYVAL pbc AS IBindCtx _                              ' __in LPBC pbc
 , BYVAL pbscb AS IBindStatusCallback _                 ' __in IBindStatusCallback *pbscb
 , BYREF ppBSCBPrev AS IBindStatusCallback _            ' __out IBindStatusCallback** ppBSCBPrev
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RevokeBindStatusCallback IMPORT "URLMON.DLL" ALIAS "RevokeBindStatusCallback" ( _
   BYVAL pbc AS IBindCtx _                              ' __in LPBC pbc
 , BYVAL pbscb AS IBindStatusCallback _                 ' __in IBindStatusCallback *pbscb
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION GetClassFileOrMime IMPORT "URLMON.DLL" ALIAS "GetClassFileOrMime" ( _
   BYVAL pbc AS IBindCtx _                              ' __in LPBC pbc
 , BYREF szFilename AS WSTRINGZ _                       ' __in LPCWSTR szFilename
 , BYVAL pBuffer AS DWORD _                             ' __in LPVOID pBuffer
 , BYVAL cbSize AS DWORD _                              ' __in DWORD cbSize
 , BYREF szMime AS WSTRINGZ _                           ' __in LPCWSTR szMime
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 , BYREF pclsid AS GUID _                               ' __out CLSID *pclsid
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION IsValidURL IMPORT "URLMON.DLL" ALIAS "IsValidURL" ( _
   BYVAL pbc AS IBindCtx _                              ' __in LPBC pbc
 , BYREF szURL AS WSTRINGZ _                            ' __in LPCWSTR szURL
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoGetClassObjectFromURL IMPORT "URLMON.DLL" ALIAS "CoGetClassObjectFromURL" ( _
   BYREF rclsid AS GUID _                               ' __in REFCLSID rclsid
 , BYREF szCodeURL AS WSTRINGZ _                        ' __in LPCWSTR szCodeURL
 , BYVAL dwFileVersionMS AS DWORD _                     ' __in DWORD dwFileVersionMS
 , BYVAL dwFileVersionLS AS DWORD _                     ' __in DWORD dwFileVersionLS
 , BYREF szContentType AS WSTRINGZ _                    ' __in LPCWSTR szContentType
 , BYVAL pBindCtx AS IBindCtx _                         ' __in LPBINDCTX pBindCtx
 , BYVAL dwClsContext AS DWORD _                        ' __in DWORD dwClsContext
 , BYVAL pvReserved AS DWORD _                          ' __in LPVOID pvReserved
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS ANY _                                   ' __out LPVOID * ppv
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION IEInstallScope IMPORT "URLMON.DLL" ALIAS "IEInstallScope" ( _
   BYREF pdwScope AS DWORD _                            ' __ out LPDWORD pdwScope
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION FaultInIEFeature IMPORT "URLMON.DLL" ALIAS "FaultInIEFeature" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF pClassSpec AS uCLSSPEC _                       ' __in uCLSSPEC *pClassSpec
 , BYREF pQuery AS QUERYCONTEXT _                       ' __in_out QUERYCONTEXT *pQuery
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION GetComponentIDFromCLSSPEC IMPORT "URLMON.DLL" ALIAS "GetComponentIDFromCLSSPEC" ( _
   BYREF pClassSpec AS uCLSSPEC _                       ' __in uCLSSPEC *pClassSpec
 , BYREF ppszComponentID AS ASCIIZ _                    ' __out LPSTR *ppszComponentID
 ) AS LONG                                              ' HRESULT

'// flags for FaultInIEFeature
%FIEF_FLAG_FORCE_JITUI                  = &H1???   ' // force JIT ui even if
                                                   ' // previoulsy rejected by
                                                   ' // user in this session or
                                                   ' // marked as Never Ask Again
%FIEF_FLAG_PEEK                         = &H2???   ' // just peek, don't faultin
%FIEF_FLAG_SKIP_INSTALLED_VERSION_CHECK = &H4???   ' // force JIT without checking local version

'//helper apis
DECLARE FUNCTION IsAsyncMoniker IMPORT "URLMON.DLL" ALIAS "IsAsyncMoniker" ( _
   BYVAL pmk AS IMoniker _                              ' __in IMoniker* pmk
 ) AS LONG                                              ' HRESULT

' Not currently implemented.
'STDAPI CreateURLBinding(LPCWSTR lpszUrl, IBindCtx *pbc, IBinding **ppBdg);
'DECLARE FUNCTION CreateURLBinding IMPORT "URLMON.DLL" ALIAS "CreateURLBinding" ( _
'   BYREF lpszUrl AS WSTRINGZ _                          ' __in LPCWSTR lpszUrl
' , BYVAL pbc AS IBindCtx _                              ' __in IBindCtx *pbc
' , BYREF ppBdg AS IBinding _                            ' __out IBinding **ppBdg
' ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RegisterMediaTypes IMPORT "URLMON.DLL" ALIAS "RegisterMediaTypes" ( _
   BYVAL ctypes AS DWORD _                              ' __in UINT ctypes
 , BYREF rgszTypes AS ASCIIZ _                          ' __in const LPCSTR* rgszTypes
 , BYREF rgcfTypes AS DWORD _                           ' __out CLIPFORMAT* rgcfTypes
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION FindMediaType IMPORT "URLMON.DLL" ALIAS "FindMediaType" ( _
   BYREF rgszTypes AS ASCIIZ _                          ' __in LPCSTR rgszTypes
 , BYREF rgcfTypes AS DWORD _                           ' __out CLIPFORMAT* rgcfTypes
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateFormatEnumerator IMPORT "URLMON.DLL" ALIAS "CreateFormatEnumerator" ( _
   BYVAL cfmtetc AS DWORD _                             ' __in UINT cfmtetc
 , BYREF rgfmtetc AS FORMATETC _                        ' __in FORMATETC* rgfmtetc
 , BYREF ppenumfmtetc AS IEnumFORMATETC _               ' __out IEnumFORMATETC** ppenumfmtetc
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RegisterFormatEnumerator IMPORT "URLMON.DLL" ALIAS "RegisterFormatEnumerator" ( _
   BYVAL pbc AS IBindCtx _                              ' __in LPBC pbc
 , BYVAL pEFetc AS IEnumFORMATETC _                     ' __in IEnumFORMATETC *pEFetc
 , BYVAL reserved AS DWORD _                            ' __in DWORD reserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RevokeFormatEnumerator IMPORT "URLMON.DLL" ALIAS "RevokeFormatEnumerator" ( _
   BYVAL pbc AS IBindCtx _                              ' __in LPBC pbc
 , BYVAL pEFetc AS IEnumFORMATETC _                     ' __in IEnumFORMATETC *pEFetc
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RegisterMediaTypeClass IMPORT "URLMON.DLL" ALIAS "RegisterMediaTypeClass" ( _
   BYVAL pbc AS IBindCtx _                              ' __in LPBC pbc
 , BYVAL ctypes AS DWORD _                              ' __in UINT ctypes
 , BYREF rgszTypes AS ASCIIZ _                          ' __in const LPCSTR* rgszTypes
 , BYREF rgclsID AS GUID _                              ' __in CLSID *rgclsID
 , BYVAL reserved AS DWORD _                            ' __in DWORD reserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION FindMediaTypeClass IMPORT "URLMON.DLL" ALIAS "FindMediaTypeClass" ( _
   BYVAL pbc AS IBindCtx _                              ' __in LPBC pbc
 , BYREF szType AS ASCIIZ _                             ' __in LPCSTR szType
 , BYREF pclsID AS GUID _                               ' __out CLSID *pclsID
 , BYVAL reserved AS DWORD _                            ' __in DWORD reserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UrlMkSetSessionOption IMPORT "URLMON.DLL" ALIAS "UrlMkSetSessionOption" ( _
   BYVAL dwOption AS DWORD _                            ' __in DWORD dwOption
 , BYVAL pBuffer AS DWORD _                             ' __in LPVOID pBuffer
 , BYVAL dwBufferLength AS DWORD _                      ' __in DWORD dwBufferLength
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UrlMkGetSessionOption IMPORT "URLMON.DLL" ALIAS "UrlMkGetSessionOption" ( _
   BYVAL dwOption AS DWORD _                            ' __in DWORD dwOption
 , BYVAL pBuffer AS DWORD _                             ' __in LPVOID pBuffer
 , BYVAL dwBufferLength AS DWORD _                      ' __in DWORD dwBufferLength
 , BYREF pdwBufferLength AS DWORD _                     ' __out DWORD *pdwBufferLength
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION FindMimeFromData IMPORT "URLMON.DLL" ALIAS "FindMimeFromData" ( _
   BYVAL pbc AS IBindCtx _                              ' __in LPBC pbc
 , BYREF pwzUrl AS WSTRINGZ _                           ' __in LPCWSTR pwzUrl
 , BYVAL pBuffer AS DWORD _                             ' __in LPVOID pBuffer
 , BYVAL cbSize AS DWORD _                              ' __in DWORD cbSize
 , BYREF pwzMimeProposed AS WSTRINGZ _                  ' __in LPCWSTR pwzMimeProposed
 , BYVAL dwMimeFlags AS DWORD _                         ' __in DWORD dwMimeFlags
 , BYREF ppwzMimeOut AS DWORD _                         ' __out LPWSTR *ppwzMimeOut
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' HRESULT

%FMFD_DEFAULT             = &H00000000???
%FMFD_URLASFILENAME       = &H00000001???
'#if (_WIN32_IE >= _WIN32_IE_IE60SP2)
%FMFD_ENABLEMIMESNIFFING  = &H00000002???
%FMFD_IGNOREMIMETEXTPLAIN = &H00000004???
'#endif //(_WIN32_IE >= _WIN32_IE_IE60SP2)
%FMFD_SERVERMIME          = &H00000008???
%UAS_EXACTLEGACY          = &H00001000???

DECLARE FUNCTION ObtainUserAgentString IMPORT "URLMON.DLL" ALIAS "ObtainUserAgentString" ( _
   BYVAL dwOption AS DWORD _                            ' __in DWORD dwOption
 , BYREF pszUAOut AS ASCIIZ _                           ' __in LPSTR pszUAOut
 , BYVAL cbSize AS DWORD _                              ' __in DWORD* cbSize
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CompareSecurityIds IMPORT "URLMON.DLL" ALIAS "CompareSecurityIds" ( _
   BYVAL pbSecurityId1 AS BYTE PTR _                    ' __in BYTE* pbSecurityId1
 , BYVAL dwLen1 AS DWORD _                              ' __in DWORD dwLen1
 , BYVAL pbSecurityId2 AS BYTE PTR _                    ' __in BYTE* pbSecurityId2
 , BYVAL dwLen2 AS DWORD _                              ' __in DWORD dwLen2
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CompatFlagsFromClsid IMPORT "URLMON.DLL" ALIAS "CompatFlagsFromClsid" ( _
   BYREF pclsid AS GUID _                               ' __in CLSID *pclsid
 , BYREF pdwCompatFlags AS DWORD _                      ' __out LPDWORD pdwCompatFlags
 , BYREF pdwMiscStatusFlags AS DWORD _                  ' __out LPDWORD pdwMiscStatusFlags
 ) AS LONG                                              ' HRESULT

'// URLMON-specific defines for UrlMkSetSessionOption() above
%URLMON_OPTION_USERAGENT           = &H10000001???
%URLMON_OPTION_USERAGENT_REFRESH   = &H10000002???
%URLMON_OPTION_URL_ENCODING        = &H10000004???
'#if (_WIN32_IE >= _WIN32_IE_IE60SP2)
%URLMON_OPTION_USE_BINDSTRINGCREDS = &H10000008???
'#endif //(_WIN32_IE >= _WIN32_IE_IE60SP2)
'#if (_WIN32_IE >= _WIN32_IE_IE70)
%URLMON_OPTION_USE_BROWSERAPPSDOCUMENTS = &H10000010???
'#endif //(_WIN32_IE >= _WIN32_IE_IE70)

'#define CF_NULL                 0
'#define CFSTR_MIME_NULL         NULL
'#define CFSTR_MIME_TEXT         (TEXT("text/plain"))
'#define CFSTR_MIME_RICHTEXT     (TEXT("text/richtext"))
'#define CFSTR_MIME_X_BITMAP     (TEXT("image/x-xbitmap"))
'#define CFSTR_MIME_POSTSCRIPT   (TEXT("application/postscript"))
'#define CFSTR_MIME_AIFF         (TEXT("audio/aiff"))
'#define CFSTR_MIME_BASICAUDIO   (TEXT("audio/basic"))
'#define CFSTR_MIME_WAV          (TEXT("audio/wav"))
'#define CFSTR_MIME_X_WAV        (TEXT("audio/x-wav"))
'#define CFSTR_MIME_GIF          (TEXT("image/gif"))
'#define CFSTR_MIME_PJPEG        (TEXT("image/pjpeg"))
'#define CFSTR_MIME_JPEG         (TEXT("image/jpeg"))
'#define CFSTR_MIME_TIFF         (TEXT("image/tiff"))
'#define CFSTR_MIME_X_PNG        (TEXT("image/x-png"))
'#define CFSTR_MIME_BMP          (TEXT("image/bmp"))
'#define CFSTR_MIME_X_ART        (TEXT("image/x-jg"))
'#define CFSTR_MIME_X_EMF        (TEXT("image/x-emf"))
'#define CFSTR_MIME_X_WMF        (TEXT("image/x-wmf"))
'#define CFSTR_MIME_AVI          (TEXT("video/avi"))
'#define CFSTR_MIME_MPEG         (TEXT("video/mpeg"))
'#define CFSTR_MIME_FRACTALS     (TEXT("application/fractals"))
'#define CFSTR_MIME_RAWDATA      (TEXT("application/octet-stream"))
'#define CFSTR_MIME_RAWDATASTRM  (TEXT("application/octet-stream"))
'#define CFSTR_MIME_PDF          (TEXT("application/pdf"))
'#define CFSTR_MIME_HTA          (TEXT("application/hta"))
'#define CFSTR_MIME_X_AIFF       (TEXT("audio/x-aiff"))
'#define CFSTR_MIME_X_REALAUDIO  (TEXT("audio/x-pn-realaudio"))
'#define CFSTR_MIME_XBM          (TEXT("image/xbm"))
'#define CFSTR_MIME_QUICKTIME    (TEXT("video/quicktime"))
'#define CFSTR_MIME_X_MSVIDEO    (TEXT("video/x-msvideo"))
'#define CFSTR_MIME_X_SGI_MOVIE  (TEXT("video/x-sgi-movie"))
'#define CFSTR_MIME_HTML         (TEXT("text/html"))
'#define CFSTR_MIME_XML          (TEXT("text/xml"))

%CF_NULL                 = 0
%CFSTR_MIME_NULL         = %NULL
$CFSTR_MIME_TEXT         = "text/plain"
$CFSTR_MIME_RICHTEXT     = "text/richtext"
$CFSTR_MIME_X_BITMAP     = "image/x-xbitmap"
$CFSTR_MIME_POSTSCRIPT   = "application/postscript"
$CFSTR_MIME_AIFF         = "audio/aiff"
$CFSTR_MIME_BASICAUDIO   = "audio/basic"
$CFSTR_MIME_WAV          = "audio/wav"
$CFSTR_MIME_X_WAV        = "audio/x-wav"
$CFSTR_MIME_GIF          = "image/gif"
$CFSTR_MIME_PJPEG        = "image/pjpeg"
$CFSTR_MIME_JPEG         = "image/jpeg"
$CFSTR_MIME_TIFF         = "image/tiff"
$CFSTR_MIME_X_PNG        = "image/x-png"
$CFSTR_MIME_BMP          = "image/bmp"
$CFSTR_MIME_X_ART        = "image/x-jg"
$CFSTR_MIME_X_EMF        = "image/x-emf"
$CFSTR_MIME_X_WMF        = "image/x-wmf"
$CFSTR_MIME_AVI          = "video/avi"
$CFSTR_MIME_MPEG         = "video/mpeg"
$CFSTR_MIME_FRACTALS     = "application/fractals"
$CFSTR_MIME_RAWDATA      = "application/octet-stream"
$CFSTR_MIME_RAWDATASTRM  = "application/octet-stream"
$CFSTR_MIME_PDF          = "application/pdf"
$CFSTR_MIME_HTA          = "application/hta"
$CFSTR_MIME_X_AIFF       = "audio/x-aiff"
$CFSTR_MIME_X_REALAUDIO  = "audio/x-pn-realaudio"
$CFSTR_MIME_XBM          = "image/xbm"
$CFSTR_MIME_QUICKTIME    = "video/quicktime"
$CFSTR_MIME_X_MSVIDEO    = "video/x-msvideo"
$CFSTR_MIME_X_SGI_MOVIE  = "video/x-sgi-movie"
$CFSTR_MIME_HTML         = "text/html"
$CFSTR_MIME_XML          = "text/xml"

'// MessageId: MK_S_ASYNCHRONOUS
'// MessageText: Operation is successful, but will complete asynchronously.
'//
'#define MK_S_ASYNCHRONOUS    _HRESULT_TYPEDEF_(0x000401E8L)
'#ifndef S_ASYNCHRONOUS
'#define S_ASYNCHRONOUS       MK_S_ASYNCHRONOUS
'#endif

'#ifndef E_PENDING
'#define E_PENDING _HRESULT_TYPEDEF_(0x8000000AL)
'#endif

%MK_S_ASYNCHRONOUS    = &H000401E8&
#IF NOT %DEF(%S_ASYNCHRONOUS)
%S_ASYNCHRONOUS       = %MK_S_ASYNCHRONOUS
#ENDIF

#IF NOT %DEF(%E_PENDING)
%E_PENDING            = &H8000000A&
#ENDIF

'//
'//
'// WinINet and protocol specific errors are mapped to one of the following
'// error which are returned in IBSC::OnStopBinding
'//
'//
'// Note: FACILITY C is split into ranges of 1k
'// C0000 - C03FF  INET_E_ (URLMON's original hresult)
'// C0400 - C07FF  INET_E_CLIENT_xxx
'// C0800 - C0BFF  INET_E_SERVER_xxx
'// C0C00 - C0FFF  INET_E_????
'// C1000 - C13FF  INET_E_AGENT_xxx (info delivery agents)

%INET_E_INVALID_URL                  = &H800C0002&
%INET_E_NO_SESSION                   = &H800C0003&
%INET_E_CANNOT_CONNECT               = &H800C0004&
%INET_E_RESOURCE_NOT_FOUND           = &H800C0005&
%INET_E_OBJECT_NOT_FOUND             = &H800C0006&
%INET_E_DATA_NOT_AVAILABLE           = &H800C0007&
%INET_E_DOWNLOAD_FAILURE             = &H800C0008&
%INET_E_AUTHENTICATION_REQUIRED      = &H800C0009&
%INET_E_NO_VALID_MEDIA               = &H800C000A&
%INET_E_CONNECTION_TIMEOUT           = &H800C000B&
%INET_E_INVALID_REQUEST              = &H800C000C&
%INET_E_UNKNOWN_PROTOCOL             = &H800C000D&
%INET_E_SECURITY_PROBLEM             = &H800C000E&
%INET_E_CANNOT_LOAD_DATA             = &H800C000F&
%INET_E_CANNOT_INSTANTIATE_OBJECT    = &H800C0010&
%INET_E_INVALID_CERTIFICATE          = &H800C0019&
%INET_E_REDIRECT_FAILED              = &H800C0014&
%INET_E_REDIRECT_TO_DIR              = &H800C0015&
%INET_E_CANNOT_LOCK_REQUEST          = &H800C0016&
%INET_E_USE_EXTEND_BINDING           = &H800C0017&
%INET_E_TERMINATED_BIND              = &H800C0018&
%INET_E_RESERVED_1                   = &H800C001A&
%INET_E_BLOCKED_REDIRECT_XSECURITYID = &H800C001B&
%INET_E_ERROR_FIRST                  = &H800C0002&
%INET_E_CODE_DOWNLOAD_DECLINED       = &H800C0100&
%INET_E_RESULT_DISPATCHED            = &H800C0200&
%INET_E_CANNOT_REPLACE_SFP_FILE      = &H800C0300&
'#if (_WIN32_IE >= _WIN32_IE_IE60SP2)
%INET_E_CODE_INSTALL_SUPPRESSED      = &H800C0400&
'#endif //(_WIN32_IE >= _WIN32_IE_IE60SP2)
%INET_E_CODE_INSTALL_BLOCKED_BY_HASH_POLICY = &H800C0500&
%INET_E_DOWNLOAD_BLOCKED_BY_INPRIVATE = &H800C0501&
%INET_E_ERROR_LAST                    = %INET_E_DOWNLOAD_BLOCKED_BY_INPRIVATE

' ########################################################################################
' IAsyncMoniker interface
' IID = 79EAC9D3-BAF9-11CE-8C82-00AA004BA90B
' Inherited interface = IUnknown
' This interface provides an implementation of the IUnknown interface, which allows client
' programs to determine if a moniker supports asynchronous binding. No additional methods
' are supported by this interface.
' Note: Removed from the Vista SDK.
' ########################################################################################

$IID_IAsyncMoniker = GUID$("{79EAC9D3-BAF9-11CE-8C82-00AA004BA90B}")

INTERFACE IAsyncMoniker $IID_IAsyncMoniker

   INHERIT IUnknown

END INTERFACE


' ########################################################################################
' IPersistMoniker interface
' IID = 79EAC9C9-BAF9-11CE-8C82-00AA004BA90B
' Inherited interface = IUnknown
' This interface provides methods that offer more control over the binding of
' persistent data.
' ########################################################################################

#IF NOT %DEF(%IPersistMoniker_INTERFACE_DEFINED)
    %IPersistMoniker_INTERFACE_DEFINED = 1

$IID_IPersistMoniker = GUID$("{79EAC9C9-BAF9-11CE-8C82-00AA004BA90B}")

INTERFACE IPersistMoniker $IID_IPersistMoniker

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDirty ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 20
     BYVAL fFullyAvailable AS DWORD _                   ' __in BOOL fFullyAvailable
   , BYVAL pimkName AS IMoniker _                       ' __in IMoniker *pimkName
   , BYVAL pibc AS IBindCtx _                           ' __in LPBC pibc
   , BYVAL grfMode AS DWORD _                           ' __in DWORD grfMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 24
     BYVAL pimkName AS IMoniker _                       ' __in IMoniker *pimkName
   , BYVAL pbc AS IBindCtx _                            ' __in LPBC pbc
   , BYVAL fRemember AS LONG _                          ' __in BOOL fRemember
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveCompleted ( _                             ' VTable offset = 28
     BYVAL pimkName AS IMoniker _                       ' __in IMoniker *pimkName
   , BYVAL pibc AS IBindCtx _                           ' __in LPBC pibc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurMoniker ( _                             ' VTable offset = 32
     BYREF ppimkName AS IMoniker _                      ' __out IMoniker *ppimkName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPersistMoniker_INTERFACE_DEFINED__ */

' ########################################################################################
' IMonikerProp interface
' IID = A5CA5F7F-1847-4D87-9C5B-918509F7511D
' Inherited interface = IUnknown
' This interface provides access to the properties of a moniker.
' This interface is implemented by persistent monikers, such as a MIME handler, to
' retrieve properties about the moniker being handled.
' ########################################################################################

#IF NOT %DEF(%IMonikerProp_INTERFACE_DEFINED)
    %IMonikerProp_INTERFACE_DEFINED = 1

' MONIKERPROPERTY enum
%MIMETYPEPROP        = 0
%USE_SRC_URL         = &H1
%CLASSIDPROP         = &H2
%TRUSTEDDOWNLOADPROP = &H3
%POPUPLEVELPROP      = &H4

$IID_IMonikerProp = GUID$("{A5CA5F7F-1847-4D87-9C5B-918509F7511D}")

INTERFACE IMonikerProp $IID_IMonikerProp

   INHERIT IUnknown

   ' =====================================================================================
   METHOD PutProperty ( _                               ' VTable offset = 12
     BYVAL mkp AS DWORD _                               ' __in MONIKERPROPERTY mkp
   , BYREF val AS WSTRINGZ _                            ' __in LPCWSTR val
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMonikerProp_INTERFACE_DEFINED__ */


' ########################################################################################
' IBindProtocol interface
' IID = 79EAC9CD-BAF9-11CE-8C82-00AA004BA90B
' Inherited interface = IUnknown
' Nor currently supported.
' ########################################################################################

#IF NOT %DEF(%IBindProtocol_INTERFACE_DEFINED)
    %IBindProtocol_INTERFACE_DEFINED = 1

$IID_IBindProtocol = GUID$("{79EAC9CD-BAF9-11CE-8C82-00AA004BA90B}")

INTERFACE IBindProtocol $IID_IBindProtocol

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateBinding ( _                             ' VTable offset = 12
     BYREF szUrl AS WSTRINGZ _                          ' __in LPCWSTR szUrl
   , BYVAL pbc AS IBindCtx _                            ' __in IBindCtx *pbc
   , BYREF ppb AS IBinding _                            ' __out IBinding **ppb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBindProtocol_INTERFACE_DEFINED__ */


#IF NOT %DEF(%IBinding_INTERFACE_DEFINED)
    %IBinding_INTERFACE_DEFINED = 1

$IID_IBinding = GUID$("{79EAC9C0-BAF9-11CE-8C82-00AA004BA90B}")

' ########################################################################################
' IBinding interface
' IID = 79EAC9C0-BAF9-11CE-8C82-00AA004BA90B
' Inherited interface = IUnknown
' This interface provides methods that allow the client program using an asynchronous
' moniker to control the progress of the bind operation.
' An asynchronous moniker calls the client's IBindStatusCallback::OnStartBinding method to
' provide the client program with a pointer to the IBinding interface.
' ########################################################################################

INTERFACE IBinding $IID_IBinding

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Suspend ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Resume ( _                                    ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPriority ( _                               ' VTable offset = 24
     BYVAL nPriority AS LONG _                          ' __in LONG nPriority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPriority ( _                               ' VTable offset = 28
     BYREF pnPriority AS LONG _                         ' __out LONG *pnPriority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBindResult ( _                             ' VTable offset = 32
     BYREF pclsidProtocol AS GUID _                     ' __out CLSID *pclsidProtocol
   , BYREF pdwResult AS DWORD _                         ' __out DWORD *pdwResult
   , BYREF pszResult AS DWORD _                         ' __out LPOLESTR *pszResult
   , BYREF pdwReserved AS DWORD _                       ' __in_out DWORD *pdwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBinding_INTERFACE_DEFINED__ */


' ########################################################################################
' IBindStatusCallback interface
' IID = 79EAC9C1-BAF9-11CE-8C82-00AA004BA90B
' Inherited interface = IUnknown
' This interface accepts information on an asynchronous bind operation.
' A client requesting an asynchronous bind operation must provide a notification object
' exposing the IBindStatusCallback interface. The asynchronous moniker provides
' information on the bind operation to the client by calling notification methods on the
' client's IBindStatusCallback interface. This interface also allows the client to pass
' additional bind information to the moniker by calling the
' IBindStatusCallback::GetBindInfo and IBindStatusCallback::GetPriority methods after
' receiving a call from IMoniker::BindToObject or IMoniker::BindToStorage.
' Only the last IBindStatusCallback interface that was registered will be called.
' ########################################################################################

#IF NOT %DEF(%IBindStatusCallback_INTERFACE_DEFINED)
    %IBindStatusCallback_INTERFACE_DEFINED = 1

' BINDVERB enum
%BINDVERB_GET       = 0
%BINDVERB_POST      = &H1
%BINDVERB_PUT       = &H2
%BINDVERB_CUSTOM    = &H3
%BINDVERB_RESERVED1 = &H4

' BINDINFOF enum
%BINDINFOF_URLENCODESTGMEDDATA = &H1
%BINDINFOF_URLENCODEDEXTRAINFO = &H2

' BINDF enum
%BINDF_ASYNCHRONOUS             = &H1???
%BINDF_ASYNCSTORAGE             = &H2???
%BINDF_NOPROGRESSIVERENDERING   = &H4???
%BINDF_OFFLINEOPERATION         = &H8???
%BINDF_GETNEWESTVERSION         = &H10???
%BINDF_NOWRITECACHE             = &H20???
%BINDF_NEEDFILE                 = &H40???
%BINDF_PULLDATA                 = &H80???
%BINDF_IGNORESECURITYPROBLEM    = &H100???
%BINDF_RESYNCHRONIZE            = &H200???
%BINDF_HYPERLINK                = &H400???
%BINDF_NO_UI                    = &H800???
%BINDF_SILENTOPERATION          = &H1000???
%BINDF_PRAGMA_NO_CACHE          = &H2000???
%BINDF_GETCLASSOBJECT           = &H4000???
%BINDF_RESERVED_1               = &H8000???
%BINDF_FREE_THREADED            = &H10000???
%BINDF_DIRECT_READ              = &H20000???
%BINDF_FORMS_SUBMIT             = &H40000???
%BINDF_GETFROMCACHE_IF_NET_FAIL = &H80000???
%BINDF_FROMURLMON               = &H100000???
%BINDF_FWD_BACK                 = &H200000???
%BINDF_PREFERDEFAULTHANDLER     = &H400000???
%BINDF_ENFORCERESTRICTED        = &H800000???

%BINDF_DONTUSECACHE   = %BINDF_GETNEWESTVERSION
%BINDF_DONTPUTINCACHE = %BINDF_NOWRITECACHE
%BINDF_NOCOPYDATA     = %BINDF_PULLDATA

' URL_ENCODING enum
%URL_ENCODING_NONE         = 0
%URL_ENCODING_ENABLE_UTF8  = &H10000000???
%URL_ENCODING_DISABLE_UTF8 = &H20000000???

' // Size = 84 bytes
TYPE BINDINFO DWORD
   cbSize             AS DWORD                   ' ULONG cbSize
   szExtraInfo        AS WSTRINGZ PTR            ' LPWSTR szExtraInfo
   stgmedData         AS STGMEDIUM               ' STGMEDIUM stgmedData
   grfBindInfoF       AS DWORD                   ' DWORD grfBindInfoF
   dwBindVerb         AS DWORD                   ' DWORD dwBindVerb
   szCustomVerb       AS WSTRINGZ PTR            ' LPWSTR szCustomVerb
   cbStgmedData       AS DWORD                   ' DWORD cbstgmedData
   dwOptions          AS DWORD                   ' DWORD dwOptions
   dwOptionsFlags     AS DWORD                   ' DWORD dwOptionsFlags
   dwCodePage         AS DWORD                   ' DWORD dwCodePage
   securityAttributes AS SECURITY_ATTRIBUTES     ' SECURITY_ATTRIBUTES securityAttributes
   iid                AS GUID                    ' IID iid
   pUnk               AS DWORD PTR               ' IUnknown *pUnk
   dwReserved         AS DWORD                   ' DWORD dwReserved
END TYPE

' BINDINFO_OPTIONS enum
%BINDINFO_OPTIONS_WININETFLAG              = &H10000???
%BINDINFO_OPTIONS_ENABLE_UTF8              = &H20000???
%BINDINFO_OPTIONS_DISABLE_UTF8             = &H40000???
%BINDINFO_OPTIONS_USE_IE_ENCODING          = &H80000???
%BINDINFO_OPTIONS_BINDTOOBJECT             = &H100000???
%BINDINFO_OPTIONS_SECURITYOPTOUT           = &H200000???
%BINDINFO_OPTIONS_IGNOREMIMETEXTPLAIN      = &H400000???
%BINDINFO_OPTIONS_USEBINDSTRINGCREDS       = &H800000???
%BINDINFO_OPTIONS_IGNOREHTTPHTTPSREDIRECTS = &H1000000???
%BINDINFO_OPTIONS_IGNORE_SSLERRORS_ONCE    = &H2000000???
%BINDINFO_WPC_DOWNLOADBLOCKED              = &H8000000???
%BINDINFO_WPC_LOGGING_ENABLED              = &H10000000???
%BINDINFO_OPTIONS_ALLOWCONNECTDATA         = &H20000000???
%BINDINFO_OPTIONS_DISABLEAUTOREDIRECTS     = &H40000000???
%BINDINFO_OPTIONS_SHDOCVW_NAVIGATE         = &H80000000&   ' ( int  )0x80000000

' BSCF enum
%BSCF_FIRSTDATANOTIFICATION        = &H1???
%BSCF_INTERMEDIATEDATANOTIFICATION = &H2???
%BSCF_LASTDATANOTIFICATION         = &H4???
%BSCF_DATAFULLYAVAILABLE           = &H8???
%BSCF_AVAILABLEDATASIZEUNKNOWN     = &H10???
%BSCF_SKIPDRAINDATAFORFILEURLS     = &H20???
%BSCF_64BITLENGTHDOWNLOAD          = &H40???

' BINDSTATUS enum
%BINDSTATUS_FINDINGRESOURCE            = 1
%BINDSTATUS_CONNECTING                 = %BINDSTATUS_FINDINGRESOURCE            + 1
%BINDSTATUS_REDIRECTING                = %BINDSTATUS_CONNECTING                 + 1
%BINDSTATUS_BEGINDOWNLOADDATA          = %BINDSTATUS_REDIRECTING                + 1
%BINDSTATUS_DOWNLOADINGDATA            = %BINDSTATUS_BEGINDOWNLOADDATA          + 1
%BINDSTATUS_ENDDOWNLOADDATA            = %BINDSTATUS_DOWNLOADINGDATA            + 1
%BINDSTATUS_BEGINDOWNLOADCOMPONENTS    = %BINDSTATUS_ENDDOWNLOADDATA            + 1
%BINDSTATUS_INSTALLINGCOMPONENTS       = %BINDSTATUS_BEGINDOWNLOADCOMPONENTS    + 1
%BINDSTATUS_ENDDOWNLOADCOMPONENTS      = %BINDSTATUS_INSTALLINGCOMPONENTS       + 1
%BINDSTATUS_USINGCACHEDCOPY            = %BINDSTATUS_ENDDOWNLOADCOMPONENTS      + 1
%BINDSTATUS_SENDINGREQUEST             = %BINDSTATUS_USINGCACHEDCOPY            + 1
%BINDSTATUS_CLASSIDAVAILABLE           = %BINDSTATUS_SENDINGREQUEST             + 1
%BINDSTATUS_MIMETYPEAVAILABLE          = %BINDSTATUS_CLASSIDAVAILABLE           + 1
%BINDSTATUS_CACHEFILENAMEAVAILABLE     = %BINDSTATUS_MIMETYPEAVAILABLE          + 1
%BINDSTATUS_BEGINSYNCOPERATION         = %BINDSTATUS_CACHEFILENAMEAVAILABLE     + 1
%BINDSTATUS_ENDSYNCOPERATION           = %BINDSTATUS_BEGINSYNCOPERATION         + 1
%BINDSTATUS_BEGINUPLOADDATA            = %BINDSTATUS_ENDSYNCOPERATION           + 1
%BINDSTATUS_UPLOADINGDATA              = %BINDSTATUS_BEGINUPLOADDATA            + 1
%BINDSTATUS_ENDUPLOADDATA              = %BINDSTATUS_UPLOADINGDATA              + 1
%BINDSTATUS_PROTOCOLCLASSID            = %BINDSTATUS_ENDUPLOADDATA              + 1
%BINDSTATUS_ENCODING                   = %BINDSTATUS_PROTOCOLCLASSID            + 1
%BINDSTATUS_VERIFIEDMIMETYPEAVAILABLE  = %BINDSTATUS_ENCODING                   + 1
%BINDSTATUS_CLASSINSTALLLOCATION       = %BINDSTATUS_VERIFIEDMIMETYPEAVAILABLE  + 1
%BINDSTATUS_DECODING                   = %BINDSTATUS_CLASSINSTALLLOCATION       + 1
%BINDSTATUS_LOADINGMIMEHANDLER         = %BINDSTATUS_DECODING                   + 1
%BINDSTATUS_CONTENTDISPOSITIONATTACH   = %BINDSTATUS_LOADINGMIMEHANDLER         + 1
%BINDSTATUS_FILTERREPORTMIMETYPE       = %BINDSTATUS_CONTENTDISPOSITIONATTACH   + 1
%BINDSTATUS_CLSIDCANINSTANTIATE        = %BINDSTATUS_FILTERREPORTMIMETYPE       + 1
%BINDSTATUS_IUNKNOWNAVAILABLE          = %BINDSTATUS_CLSIDCANINSTANTIATE        + 1
%BINDSTATUS_DIRECTBIND                 = %BINDSTATUS_IUNKNOWNAVAILABLE          + 1
%BINDSTATUS_RAWMIMETYPE                = %BINDSTATUS_DIRECTBIND                 + 1
%BINDSTATUS_PROXYDETECTING             = %BINDSTATUS_RAWMIMETYPE                + 1
%BINDSTATUS_ACCEPTRANGES               = %BINDSTATUS_PROXYDETECTING             + 1
%BINDSTATUS_COOKIE_SENT                = %BINDSTATUS_ACCEPTRANGES               + 1
%BINDSTATUS_COMPACT_POLICY_RECEIVED    = %BINDSTATUS_COOKIE_SENT                + 1
%BINDSTATUS_COOKIE_SUPPRESSED          = %BINDSTATUS_COMPACT_POLICY_RECEIVED    + 1
%BINDSTATUS_COOKIE_STATE_UNKNOWN       = %BINDSTATUS_COOKIE_SUPPRESSED          + 1
%BINDSTATUS_COOKIE_STATE_ACCEPT        = %BINDSTATUS_COOKIE_STATE_UNKNOWN       + 1
%BINDSTATUS_COOKIE_STATE_REJECT        = %BINDSTATUS_COOKIE_STATE_ACCEPT        + 1
%BINDSTATUS_COOKIE_STATE_PROMPT        = %BINDSTATUS_COOKIE_STATE_REJECT        + 1
%BINDSTATUS_COOKIE_STATE_LEASH         = %BINDSTATUS_COOKIE_STATE_PROMPT        + 1
%BINDSTATUS_COOKIE_STATE_DOWNGRADE     = %BINDSTATUS_COOKIE_STATE_LEASH         + 1
%BINDSTATUS_POLICY_HREF                = %BINDSTATUS_COOKIE_STATE_DOWNGRADE     + 1
%BINDSTATUS_P3P_HEADER                 = %BINDSTATUS_POLICY_HREF                + 1
%BINDSTATUS_SESSION_COOKIE_RECEIVED    = %BINDSTATUS_P3P_HEADER                 + 1
%BINDSTATUS_PERSISTENT_COOKIE_RECEIVED = %BINDSTATUS_SESSION_COOKIE_RECEIVED    + 1
%BINDSTATUS_SESSION_COOKIES_ALLOWED    = %BINDSTATUS_PERSISTENT_COOKIE_RECEIVED + 1
%BINDSTATUS_CACHECONTROL               = %BINDSTATUS_SESSION_COOKIES_ALLOWED    + 1
%BINDSTATUS_CONTENTDISPOSITIONFILENAME = %BINDSTATUS_CACHECONTROL               + 1
%BINDSTATUS_MIMETEXTPLAINMISMATCH      = %BINDSTATUS_CONTENTDISPOSITIONFILENAME + 1
%BINDSTATUS_PUBLISHERAVAILABLE         = %BINDSTATUS_MIMETEXTPLAINMISMATCH      + 1
%BINDSTATUS_DISPLAYNAMEAVAILABLE       = %BINDSTATUS_PUBLISHERAVAILABLE         + 1
%BINDSTATUS_SSLUX_NAVBLOCKED           = %BINDSTATUS_DISPLAYNAMEAVAILABLE       + 1
%BINDSTATUS_SERVER_MIMETYPEAVAILABLE   = %BINDSTATUS_SSLUX_NAVBLOCKED           + 1
%BINDSTATUS_SNIFFED_CLASSIDAVAILABLE   = %BINDSTATUS_SERVER_MIMETYPEAVAILABLE   + 1
%BINDSTATUS_64BIT_PROGRESS             = %BINDSTATUS_SNIFFED_CLASSIDAVAILABLE   + 1

$IID_IBindStatusCallback = GUID$("{79EAC9C1-BAF9-11CE-8C82-00AA004BA90B}")

INTERFACE IBindStatusCallback $IID_IBindStatusCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnStartBinding ( _                            ' VTable offset = 12
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   , BYVAL pib AS IBinding _                            ' __in IBinding *pib
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPriority ( _                               ' VTable offset = 16
     BYREF pnPriority AS LONG _                         ' __out LONG *pnPriority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnLowResource ( _                             ' VTable offset = 20
     BYVAL reserved AS DWORD _                          ' __in DWORD reserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnProgress ( _                                ' VTable offset = 24
     BYVAL ulProgress AS DWORD _                        ' __in ULONG ulProgress
   , BYVAL ulProgressMax AS DWORD _                     ' __in ULONG ulProgressMax
   , BYVAL ulStatusCode AS DWORD _                      ' __in ULONG ulStatusCode
   , BYREF szStatusText AS WSTRINGZ _                   ' __in LPCWSTR szStatusText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnStopBinding ( _                             ' VTable offset = 28
     BYVAL hresult AS LONG _                            ' __in HRESULT hresult
   , BYREF szError AS WSTRINGZ _                        ' __in LPCWSTR szError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBindInfo ( _                               ' VTable offset = 32
     BYREF grfBINDF AS DWORD _                          ' __out DWORD *grfBINDF
   , BYREF pbindinfo AS BINDINFO _                      ' __in_out BINDINFO *pbindinfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDataAvailable ( _                           ' VTable offset = 36
     BYVAL grfBSCF AS DWORD _                           ' __in DWORD grfBSCF
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pformatetc AS FORMATETC _                    ' __in FORMATETC *pformatetc
   , BYREF pstgmed AS STGMEDIUM _                       ' __in STGMEDIUM *pstgmed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnObjectAvailable ( _                         ' VTable offset = 40
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBindStatusCallback_INTERFACE_DEFINED__ */

' ########################################################################################
' IBindStatusCallbackEx interface
' IID = AAA74EF9-8EE7-4659-88D9-F8C504DA73CC
' Inherited interface = IBindStatusCallback
' ########################################################################################

#IF NOT %DEF(%IBindStatusCallbackEx_INTERFACE_DEFINED)
    %IBindStatusCallbackEx_INTERFACE_DEFINED = 1

' enum BINDF2
%BINDF2_DISABLEBASICOVERHTTP              = &H1
%BINDF2_DISABLEAUTOCOOKIEHANDLING         = &H2
%BINDF2_READ_DATA_GREATER_THAN_4GB        = &H4
%BINDF2_DISABLE_HTTP_REDIRECT_XSECURITYID = &H8
%BINDF2_RESERVED_3                        = &H20000000
%BINDF2_RESERVED_2                        = &H40000000
%BINDF2_RESERVED_1                        = &H80000000

$IID_IBindStatusCallbackEx = GUID$("{AAA74EF9-8EE7-4659-88D9-F8C504DA73CC}")

INTERFACE IBindStatusCallbackEx $IID_IBindStatusCallbackEx

   INHERIT IUnknown

   ' =====================================================================================
   ' IBindStatusCallback methods
   ' =====================================================================================
   METHOD OnStartBinding ( _                            ' VTable offset = 12
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   , BYVAL pib AS IBinding _                            ' __in IBinding *pib
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPriority ( _                               ' VTable offset = 16
     BYREF pnPriority AS LONG _                         ' __out LONG *pnPriority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnLowResource ( _                             ' VTable offset = 20
     BYVAL reserved AS DWORD _                          ' __in DWORD reserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnProgress ( _                                ' VTable offset = 24
     BYVAL ulProgress AS DWORD _                        ' __in ULONG ulProgress
   , BYVAL ulProgressMax AS DWORD _                     ' __in ULONG ulProgressMax
   , BYVAL ulStatusCode AS DWORD _                      ' __in ULONG ulStatusCode
   , BYREF szStatusText AS WSTRINGZ _                   ' __in LPCWSTR szStatusText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnStopBinding ( _                             ' VTable offset = 28
     BYVAL hresult AS LONG _                            ' __in HRESULT hresult
   , BYREF szError AS WSTRINGZ _                        ' __in LPCWSTR szError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBindInfo ( _                               ' VTable offset = 32
     BYREF grfBINDF AS DWORD _                          ' __out DWORD *grfBINDF
   , BYREF pbindinfo AS BINDINFO _                      ' __in_out BINDINFO *pbindinfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDataAvailable ( _                           ' VTable offset = 36
     BYVAL grfBSCF AS DWORD _                           ' __in DWORD grfBSCF
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pformatetc AS FORMATETC _                    ' __in FORMATETC *pformatetc
   , BYREF pstgmed AS STGMEDIUM _                       ' __in STGMEDIUM *pstgmed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnObjectAvailable ( _                         ' VTable offset = 40
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IBindStatusCallbackEx methods
   ' =====================================================================================
   METHOD GetBindInfoEx ( _                             ' VTable offset = 44
     BYREF grfBINDF AS DWORD _                          ' __out DWORD *grfBINDF
   , BYREF pbindinfo AS BINDINFO _                      ' __inout BINDINFO *pbindinfo
   , BYREF grfBINDF2 AS DWORD _                         ' __out DWORD *grfBINDF2
   , BYREF pdwReserved AS DWORD _                       ' __out DWORD *pdwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBindStatusCallbackEx_INTERFACE_DEFINED__ */

' ########################################################################################
' IAuthenticate interface
' IID = 79EAC9D0-BAF9-11CE-8C82-00AA004BA90B
' Inherited interface = IUnknown
' This interface is implemented by the client application to provide the URL moniker with
' information to authenticate the user.
' Urlmon.dll uses the QueryInterface method on the client application's implementation of
' IBindStatusCallback to obtain a pointer to the client application's IAuthenticate
' interface. If the client application is hosting Mshtml.dll, Mshtml.dll will request a
' pointer to the client application's implementation of IAuthenticate interface by calling
' QueryInterface on the client application's IServiceProvider interface.
' ########################################################################################

#IF NOT %DEF(%IAuthenticate_INTERFACE_DEFINED)
    %IAuthenticate_INTERFACE_DEFINED = 1

$IID_IAuthenticate = GUID$("{79EAC9D0-BAF9-11CE-8C82-00AA004BA90B}")

INTERFACE IAuthenticate $IID_IAuthenticate

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Authenticate ( _                              ' VTable offset = 12
     BYREF phwnd AS DWORD _                             ' __out HWND *phwnd
   , BYREF pszUsername AS DWORD _                       ' __out LPWSTR *pszUsername
   , BYREF pszPassword AS DWORD _                       ' __out LPWSTR *pszPassword
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAuthenticate_INTERFACE_DEFINED__ */

' ########################################################################################
' IAuthenticateEx interface
' IID = 2AD1EDAF-D83D-48B5-9ADF-03DBE19F53BD
' Inherited interface = IAuthenticate
' ########################################################################################

#IF NOT %DEF(%IAuthenticateEx_INTERFACE_DEFINED)
    %IAuthenticateEx_INTERFACE_DEFINED = 1

' enum AUTHENTICATEF
%AUTHENTICATEF_PROXY = &H1
%AUTHENTICATEF_BASIC = &H2
%AUTHENTICATEF_HTTP  = &H4

TYPE AUTHENTICATEINFO DWORD
   dwFlags    AS DWORD   ' DWORD
   dwReserved AS DWORD   ' DWORD
END TYPE

$IID_IAuthenticateEx = GUID$("{2AD1EDAF-D83D-48B5-9ADF-03DBE19F53BD}")

INTERFACE IAuthenticateEx $IID_IAuthenticateEx

   INHERIT IUnknown

   ' =====================================================================================
   ' IAuthenticate method
   ' =====================================================================================
   METHOD Authenticate ( _                              ' VTable offset = 12
     BYREF phwnd AS DWORD _                             ' __out HWND *phwnd
   , BYREF pszUsername AS DWORD _                       ' __out LPWSTR *pszUsername
   , BYREF pszPassword AS DWORD _                       ' __out LPWSTR *pszPassword
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IAuthenticateEx method
   ' =====================================================================================
   METHOD AuthenticateEx ( _                            ' VTable offset = 16
     BYREF phwnd AS DWORD _                             ' __out HWND *phwnd
   , BYREF pszUsername AS DWORD _                       ' __out LPWSTR *pszUsername
   , BYREF pszPassword AS DWORD _                       ' __out LPWSTR *pszPassword
   , BYREF pauthinfo AS AUTHENTICATEINFO _              ' __in AUTHENTICATEINFO *pauthinfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAuthenticateEx_INTERFACE_DEFINED__ */

' ########################################################################################
' IHttpNegotiate interface
' IID = 79EAC9D2-BAF9-11CE-8C82-00AA004BA90B
' Inherited interface = IUnknown
' This interface is implemented by a client application to provide support for HTTP
' negotiations.
' Urlmon.dll uses the QueryInterface method on your implementation of IBindStatusCallback
' to obtain a pointer to your IHttpNegotiate interface.
' ########################################################################################

#IF NOT %DEF(%IHttpNegotiate_INTERFACE_DEFINED)
    %IHttpNegotiate_INTERFACE_DEFINED = 1

$IID_IHttpNegotiate = GUID$("{79EAC9D2-BAF9-11CE-8C82-00AA004BA90B}")

INTERFACE IHttpNegotiate $IID_IHttpNegotiate

   INHERIT IUnknown

   ' =====================================================================================
   METHOD BeginningTransaction ( _                      ' VTable offset = 12
     BYREF szURL AS WSTRINGZ _                          ' __in LPCWSTR szURL
   , BYREF szHeaders AS WSTRINGZ _                      ' __in LPCWSTR szHeaders
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   , BYREF pszAdditionalHeaders AS DWORD _              ' __out LPWSTR *pszAdditionalHeaders
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnResponse ( _                                ' VTable offset = 16
     BYVAL dwResponseCode AS DWORD _                    ' __in DWORD dwResponseCode
   , BYREF szResponseHeaders AS WSTRINGZ _              ' __in LPCWSTR szResponseHeaders
   , BYREF szRequestHeaders AS WSTRINGZ _               ' __in LPCWSTR szRequestHeaders
   , BYREF pszAdditionalRequestHeaders AS DWORD _       ' __out LPWSTR *pszAdditionalRequestHeaders
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHttpNegotiate_INTERFACE_DEFINED__ */

' ########################################################################################
' IHttpNegotiate2 interface
' IID = 4F9F9FCB-E0F4-48EB-B7AB-FA2EA9365CB4
' Inherited interface = IHttpNegotiate
' This interface is implemented by a client application to provide support for HTTP
' negotiations. It extends the IHttpNegotiate interface.
' ########################################################################################

#IF NOT %DEF(%IHttpNegotiate2_INTERFACE_DEFINED)
    %IHttpNegotiate2_INTERFACE_DEFINED = 1

$IID_IHttpNegotiate2 = GUID$("{4F9F9FCB-E0F4-48EB-B7AB-FA2EA9365CB4}")

INTERFACE IHttpNegotiate2 $IID_IHttpNegotiate2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD BeginningTransaction ( _                      ' VTable offset = 12
     BYREF szURL AS WSTRINGZ _                          ' __in LPCWSTR szURL
   , BYREF szHeaders AS WSTRINGZ _                      ' __in LPCWSTR szHeaders
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   , BYREF pszAdditionalHeaders AS DWORD _              ' __out LPWSTR *pszAdditionalHeaders
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnResponse ( _                                ' VTable offset = 16
     BYVAL dwResponseCode AS DWORD _                    ' __in DWORD dwResponseCode
   , BYREF szResponseHeaders AS WSTRINGZ _              ' __in LPCWSTR szResponseHeaders
   , BYREF szRequestHeaders AS WSTRINGZ _               ' __in LPCWSTR szRequestHeaders
   , BYREF pszAdditionalRequestHeaders AS DWORD _       ' __out LPWSTR *pszAdditionalRequestHeaders
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRootSecurityId ( _                         ' VTable offset = 20
     BYVAL pbSecurityId AS BYTE PTR _                   ' __out BYTE *pbSecurityId
   , BYREF pcbSecurityId AS DWORD _                     ' __in_out DWORD *pcbSecurityId
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD_PTR dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHttpNegotiate2_INTERFACE_DEFINED__ */

' ########################################################################################
' IHttpNegotiate3 interface
' IID = 57B6C80A-34C2-4602-BC26-66A02FC57153
' Inherited interface = IHttpNegotiate2
' ########################################################################################

#IF NOT %DEF(%IHttpNegotiate3_INTERFACE_DEFINED)
    %IHttpNegotiate3_INTERFACE_DEFINED = 1

$IID_IHttpNegotiate3 = GUID$("{57B6C80A-34C2-4602-BC26-66A02FC57153}")

INTERFACE IHttpNegotiate3 $IID_IHttpNegotiate3

   INHERIT IUnknown

   ' =====================================================================================
   ' IHttpNegotiate2 methods
   ' =====================================================================================
   METHOD BeginningTransaction ( _                      ' VTable offset = 12
     BYREF szURL AS WSTRINGZ _                          ' __in LPCWSTR szURL
   , BYREF szHeaders AS WSTRINGZ _                      ' __in LPCWSTR szHeaders
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   , BYREF pszAdditionalHeaders AS DWORD _              ' __out LPWSTR *pszAdditionalHeaders
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnResponse ( _                                ' VTable offset = 16
     BYVAL dwResponseCode AS DWORD _                    ' __in DWORD dwResponseCode
   , BYREF szResponseHeaders AS WSTRINGZ _              ' __in LPCWSTR szResponseHeaders
   , BYREF szRequestHeaders AS WSTRINGZ _               ' __in LPCWSTR szRequestHeaders
   , BYREF pszAdditionalRequestHeaders AS DWORD _       ' __out LPWSTR *pszAdditionalRequestHeaders
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRootSecurityId ( _                         ' VTable offset = 20
     BYVAL pbSecurityId AS BYTE PTR _                   ' __out BYTE *pbSecurityId
   , BYREF pcbSecurityId AS DWORD _                     ' __in_out DWORD *pcbSecurityId
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD_PTR dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IHttpNegotiate3 methods
   ' =====================================================================================
   METHOD GetSerializedClientCertContext ( _            ' VTable offset = 24
     BYREF ppbCert AS DWORD _                           ' __out BYTE **ppbCert
   , BYREF pcbCert AS DWORD _                           ' __out DWORD *pcbCert
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHttpNegotiate3_INTERFACE_DEFINED__ */

' ########################################################################################
' IWinInetFileStream interface
' IID = F134C4B7-B1F8-4E75-B886-74B90943BECB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWinInetFileStream_INTERFACE_DEFINED)
    %IWinInetFileStream_INTERFACE_DEFINED = 1

$IID_IWinInetFileStream = GUID$("{F134C4B7-B1F8-4E75-B886-74B90943BECB}")

INTERFACE IWinInetFileStream $IID_IWinInetFileStream

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetHandleForUnlock ( _                        ' VTable offset = 12
     BYVAL hWinInetLockHandle AS DWORD _                ' __in DWORD_PTR hWinInetLockHandle
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD_PTR dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDeleteFile ( _                             ' VTable offset = 16
     BYVAL dwReserved AS DWORD _                        ' __in DWORD_PTR dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWinInetFileStream_INTERFACE_DEFINED__ */


' ########################################################################################
' IWindowForBindingUI interface
' IID = 79EAC9D5-BAFA-11CE-8C82-00AA004BA90B
' Inherited interface = IUnknown
' This interface allows clients of URL monikers to display information in the client's
' user interface when necessary.
' This interface is usually implemented by OLE containers that also implement the
' IBindHost interface.
' ########################################################################################

#IF NOT %DEF(%IWindowForBindingUI_INTERFACE_DEFINED)
    %IWindowForBindingUI_INTERFACE_DEFINED = 1

$IID_IWindowForBindingUI = GUID$("{79EAC9D5-BAFA-11CE-8C82-00AA004BA90B}")

INTERFACE IWindowForBindingUI $IID_IWindowForBindingUI

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetWindow ( _                                 ' VTable offset = 12
     BYREF rguidReason AS GUID _                        ' __in REFGUID rguidReason
   , BYREF phwnd AS DWORD _                             ' __out HWND *phwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWindowForBindingUI_INTERFACE_DEFINED__ */


' ########################################################################################
' ICodeInstall interface
' IID = 79EAC9D1-BAF9-11CE-8C82-00AA004BA90B
' Inherited interface = IWindowForBindingUI
' Callback interface for problems with application installations or file downloads.
' ########################################################################################

#IF NOT %DEF(%ICodeInstall_INTERFACE_DEFINED)
    %ICodeInstall_INTERFACE_DEFINED = 1

' CIP_STATUS enum
%CIP_DISK_FULL                            = 0
%CIP_ACCESS_DENIED                        = %CIP_DISK_FULL                            + 1
%CIP_NEWER_VERSION_EXISTS                 = %CIP_ACCESS_DENIED                        + 1
%CIP_OLDER_VERSION_EXISTS                 = %CIP_NEWER_VERSION_EXISTS                 + 1
%CIP_NAME_CONFLICT                        = %CIP_OLDER_VERSION_EXISTS                 + 1
%CIP_TRUST_VERIFICATION_COMPONENT_MISSING = %CIP_NAME_CONFLICT                        + 1
%CIP_EXE_SELF_REGISTERATION_TIMEOUT       = %CIP_TRUST_VERIFICATION_COMPONENT_MISSING + 1
%CIP_UNSAFE_TO_ABORT                      = %CIP_EXE_SELF_REGISTERATION_TIMEOUT       + 1
%CIP_NEED_REBOOT                          = %CIP_UNSAFE_TO_ABORT                      + 1
%CIP_NEED_REBOOT_UI_PERMISSION            = %CIP_NEED_REBOOT                          + 1

$IID_ICodeInstall = GUID$("{79EAC9D1-BAF9-11CE-8C82-00AA004BA90B}")

INTERFACE ICodeInstall $IID_ICodeInstall

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetWindow ( _                                 ' VTable offset = 12
     BYREF rguidReason AS GUID _                        ' __in REFGUID rguidReason
   , BYREF phwnd AS DWORD _                             ' __out HWND *phwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCodeInstallProblem ( _                      ' VTable offset = 16
     BYVAL ulStatusCode AS DWORD _                      ' __in ULONG ulStatusCode
   , BYREF szDestination AS WSTRINGZ _                  ' __in LPCWSTR szDestination
   , BYREF szSource AS WSTRINGZ _                       ' __in LPCWSTR szSource
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICodeInstall_INTERFACE_DEFINED__ */


' ########################################################################################
' IUri interface
' IID = A39EE748-6A27-4817-A6F2-13914BEF5890
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUri_INTERFACE_DEFINED)
    %IUri_INTERFACE_DEFINED = 1

$IID_IUri = GUID$("{A39EE748-6A27-4817-A6F2-13914BEF5890}")

' enum Uri_PROPERTY
%Uri_PROPERTY_ABSOLUTE_URI   = 0
%Uri_PROPERTY_STRING_START   = %Uri_PROPERTY_ABSOLUTE_URI   + 1
%Uri_PROPERTY_AUTHORITY      = 1
%Uri_PROPERTY_DISPLAY_URI    = 2
%Uri_PROPERTY_DOMAIN         = 3
%Uri_PROPERTY_EXTENSION      = 4
%Uri_PROPERTY_FRAGMENT       = 5
%Uri_PROPERTY_HOST           = 6
%Uri_PROPERTY_PASSWORD       = 7
%Uri_PROPERTY_PATH           = 8
%Uri_PROPERTY_PATH_AND_QUERY = 9
%Uri_PROPERTY_QUERY          = 10
%Uri_PROPERTY_RAW_URI        = 11
%Uri_PROPERTY_SCHEME_NAME    = 12
%Uri_PROPERTY_USER_INFO      = 13
%Uri_PROPERTY_USER_NAME      = 14
%Uri_PROPERTY_STRING_LAST    = %Uri_PROPERTY_USER_NAME
%Uri_PROPERTY_HOST_TYPE      = 15
%Uri_PROPERTY_DWORD_START    = %Uri_PROPERTY_HOST_TYPE
%Uri_PROPERTY_PORT           = 16
%Uri_PROPERTY_SCHEME         = 17
%Uri_PROPERTY_ZONE           = 18
%Uri_PROPERTY_DWORD_LAST     = %Uri_PROPERTY_ZONE

' enum Uri_HOST_TYPE
%Uri_HOST_UNKNOWN = 0
%Uri_HOST_DNS     = %Uri_HOST_UNKNOWN + 1
%Uri_HOST_IPV4    = %Uri_HOST_DNS     + 1
%Uri_HOST_IPV6    = %Uri_HOST_IPV4    + 1
%Uri_HOST_IDN     = %Uri_HOST_IPV6    + 1

INTERFACE IUri $IID_IUri

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPropertyBSTR ( _                           ' VTable offset = 12
     BYVAL uriProp AS LONG _                            ' __in Uri_PROPERTY uriProp
   , BYREF pbstrProperty AS WSTRING _                   ' __out BSTR *pbstrProperty
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyLength ( _                         ' VTable offset = 16
     BYVAL uriProp AS LONG _                            ' __in Uri_PROPERTY uriProp
   , BYREF pcchProperty AS DWORD _                      ' __out DWORD *pcchProperty
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyDWORD ( _                          ' VTable offset = 20
     BYVAL uriProp AS LONG _                            ' __in Uri_PROPERTY uriProp
   , BYREF pdwProperty AS DWORD _                       ' __out DWORD *pdwProperty
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HasProperty ( _                               ' VTable offset = 24
     BYVAL uriProp AS LONG _                            ' __in Uri_PROPERTY uriProp
   , BYREF pfHasProperty AS LONG _                      ' __out BOOL *pfHasProperty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAbsoluteUri ( _                            ' VTable offset = 28
     BYREF pbstrAbsoluteUri AS WSTRING _                ' __out BSTR *pbstrAbsoluteUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAuthority ( _                              ' VTable offset = 32
     BYREF pbstrAuthority AS WSTRING _                  ' __out BSTR *pbstrAuthority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayUri ( _                             ' VTable offset = 36
     BYREF pbstrDisplayString AS WSTRING _              ' __out BSTR *pbstrDisplayString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDomain ( _                                 ' VTable offset = 40
     BYREF pbstrDomain AS WSTRING _                     ' __out BSTR *pbstrDomain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetExtension ( _                              ' VTable offset = 44
     BYREF pbstrExtension AS WSTRING _                  ' __out BSTR *pbstrExtension
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFragment ( _                               ' VTable offset = 48
     BYREF pbstrFragment AS WSTRING _                   ' __out BSTR *pbstrFragment
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHost ( _                                   ' VTable offset = 52
     BYREF pbstrHost AS WSTRING _                       ' __out BSTR *pbstrHost
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPassword ( _                               ' VTable offset = 56
     BYREF pbstrPassword AS WSTRING _                   ' __out BSTR *pbstrPassword
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPath ( _                                   ' VTable offset = 60
     BYREF pbstrPath AS WSTRING _                       ' __out BSTR *pbstrPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPathAndQuery ( _                           ' VTable offset = 64
     BYREF pbstrPathAndQuery AS WSTRING _               ' __out BSTR *pbstrPathAndQuery
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetQuery ( _                                  ' VTable offset = 68
     BYREF pbstrQuery AS WSTRING _                      ' __out BSTR *pbstrQuery
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRawUri ( _                                 ' VTable offset = 72
     BYREF pbstrRawUri AS WSTRING _                     ' __out BSTR *pbstrRawUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSchemeName ( _                             ' VTable offset = 76
     BYREF pbstrSchemeName AS WSTRING _                 ' __out BSTR *pbstrSchemeName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUserInfo ( _                               ' VTable offset = 80
     BYREF pbstrUserInfo AS WSTRING _                   ' __out BSTR *pbstrUserInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUserName ( _                               ' VTable offset = 84
     BYREF pbstrUserName AS WSTRING _                   ' __out BSTR *pbstrUserName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHostType ( _                               ' VTable offset = 88
     BYREF pdwHostType AS DWORD _                       ' __out DWORD *pdwHostType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPort ( _                                   ' VTable offset = 92
     BYREF pdwPort AS DWORD _                           ' __out DWORD *pdwPort
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScheme ( _                                 ' VTable offset = 96
     BYREF pdwScheme AS DWORD _                         ' __out DWORD *pdwScheme
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetZone ( _                                   ' VTable offset = 100
     BYREF pdwZone AS DWORD _                           ' __out DWORD *pdwZone
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperties ( _                             ' VTable offset = 104
     BYREF pdwFlags AS DWORD _                          ' __out LPDWORD pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsEqual ( _                                   ' VTable offset = 108
     BYVAL pUri AS IUri _                               ' __in IUri *pUri
   , BYREF pfEqual AS LONG _                            ' __out BOOL *pfEqual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUri_INTERFACE_DEFINED__ */

DECLARE FUNCTION CreateUri IMPORT "URLMON.DLL" ALIAS "CreateUri" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD_PTR dwReserved   // must be 0
 , BYREF ppURI AS IUri _                                ' __out IUri** ppURI
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateUriWithFragment IMPORT "URLMON.DLL" ALIAS "CreateUriWithFragment" ( _
   BYREF pwzURI AS WSTRINGZ _                           ' __in LPCWSTR pwzURI
 , BYREF pwzFragment AS WSTRINGZ _                      ' __in_opt LPCWSTR pwzFragment  // can be NULL
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD_PTR dwReserved     // must be 0
 , BYREF ppURI AS IUri _                                ' __out IUri** ppURI
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateUriFromMultiByteString IMPORT "URLMON.DLL" ALIAS "CreateUriFromMultiByteString" ( _
   BYREF pszANSIInputUri AS ASCIIZ _                    '  __in LPCSTR pszANSIInputUri
 , BYVAL dwEncodingFlags AS DWORD _                     '  __in DWORD dwEncodingFlags  // ORed set of Uri_ENCODING_ flags
 , BYVAL dwCodePage AS DWORD _                          '  __in DWORD dwCodePage
 , BYVAL dwCreateFlags AS DWORD _                       '  __in DWORD dwCreateFlags
 , BYVAL dwReserved AS DWORD _                          '  __in DWORD_PTR dwReserved   // must be 0
 , BYREF ppUri AS IUri _                                '  __out IUri** ppUri
 ) AS LONG                                              ' HRESULT

'//The following flags are used with IUri::GetProperties.
%Uri_HAS_ABSOLUTE_URI    = &H00000001???   ' (1 << Uri_PROPERTY_ABSOLUTE_URI)
%Uri_HAS_AUTHORITY       = &H00000004???   ' (1 << Uri_PROPERTY_AUTHORITY)
%Uri_HAS_DISPLAY_URI     = &H00000008???   ' (1 << Uri_PROPERTY_DISPLAY_URI)
%Uri_HAS_DOMAIN          = &H00000010???   ' (1 << Uri_PROPERTY_DOMAIN)
%Uri_HAS_EXTENSION       = &H00000020???   ' (1 << Uri_PROPERTY_EXTENSION)
%Uri_HAS_FRAGMENT        = &H00000040???   ' (1 << Uri_PROPERTY_FRAGMENT)
%Uri_HAS_HOST            = &H00000080???   ' (1 << Uri_PROPERTY_HOST)
%Uri_HAS_PASSWORD        = &H00000100???   ' (1 << Uri_PROPERTY_PASSWORD)
%Uri_HAS_PATH            = &H00000200???   ' (1 << Uri_PROPERTY_PATH)
%Uri_HAS_QUERY           = &H00000800???   ' (1 << Uri_PROPERTY_QUERY)
%Uri_HAS_RAW_URI         = &H00001000???   ' (1 << Uri_PROPERTY_RAW_URI)
%Uri_HAS_SCHEME_NAME     = &H00002000???   ' (1 << Uri_PROPERTY_SCHEME_NAME)
%Uri_HAS_USER_NAME       = &H00008000???   ' (1 << Uri_PROPERTY_USER_NAME)
%Uri_HAS_PATH_AND_QUERY  = &H00000400???   ' (1 << Uri_PROPERTY_PATH_AND_QUERY)
%Uri_HAS_USER_INFO       = &H00004000???   ' (1 << Uri_PROPERTY_USER_INFO)
%Uri_HAS_HOST_TYPE       = &H00020000???   ' (1 << Uri_PROPERTY_HOST_TYPE)
%Uri_HAS_PORT            = &H00080000???   ' (1 << Uri_PROPERTY_PORT)
%Uri_HAS_SCHEME          = &H00100000???   ' (1 << Uri_PROPERTY_SCHEME)
%Uri_HAS_ZONE            = &H00200000???   ' (1 << Uri_PROPERTY_ZONE)

'//The following public Uri_CREATE flags may be passed in
'//through the dwFlags parameter of the CreateUri functions.
'//Note that ALLOW_RELATIVE and ALLOW_IMPLICIT_WILDCARD_SCHEME are mutually exclusive and may not be passed together.
%Uri_CREATE_ALLOW_RELATIVE                 = &H00000001???    ' // When the scheme is unspecified and not implicit file, assume relative.
%Uri_CREATE_ALLOW_IMPLICIT_WILDCARD_SCHEME = &H00000002???    ' // When the scheme is unspecified and not implicit file, assume wildcard.
%Uri_CREATE_ALLOW_IMPLICIT_FILE_SCHEME     = &H00000004???    ' // When the scheme is unspecified and it starts with X: or \\ assume its a file scheme.
%Uri_CREATE_NOFRAG                         = &H00000008???    ' // If there's a query string don't look for a fragment
%Uri_CREATE_NO_CANONICALIZE                = &H00000010???    ' // Do not canonicalize the scheme, host, authority, or path
%Uri_CREATE_CANONICALIZE                   = &H00000100???    ' // DEFAULT: Canonicalize the scheme, host, authority, and path
%Uri_CREATE_FILE_USE_DOS_PATH              = &H00000020???    ' // Use DOS path compat mode for file URI creation
%Uri_CREATE_DECODE_EXTRA_INFO              = &H00000040???    ' // Beta2 DEFAULT: Decode the contents of query and fragment, then re-encode reserved characters
%Uri_CREATE_NO_DECODE_EXTRA_INFO           = &H00000080???    ' // Beta1 DEFAULT: Neither decode nor re-encode any part of the query or fragment
%Uri_CREATE_CRACK_UNKNOWN_SCHEMES          = &H00000200???    ' // Beta2 DEFAULT: Heirarchical URIs with present and unknown schemes will be treated like heirarchical URIs
%Uri_CREATE_NO_CRACK_UNKNOWN_SCHEMES       = &H00000400???    ' // Beta1 DEFAULT: Heirarchical URIs with present and unknown schemes will be treated like opaque URIs
%Uri_CREATE_PRE_PROCESS_HTML_URI           = &H00000800???    ' // DEFAULT:  Perform pre-processing on the URI to remove control characters and whitespace as if the URI comes from the raw href value of an HTML page.
%Uri_CREATE_NO_PRE_PROCESS_HTML_URI        = &H00001000???    ' // Don't perform pre-processing to remove control characters and whitespace as appropriate.
%Uri_CREATE_IE_SETTINGS                    = &H00002000???    ' // Use IE registry settings for such things as whether or not to use IDN.
%Uri_CREATE_NO_IE_SETTINGS                 = &H00004000???    ' // DEFAULT: Don't use IE registry settings.
%Uri_CREATE_NO_ENCODE_FORBIDDEN_CHARACTERS = &H00008000???    ' // Don't percent-encode characters that are forbidden by the RFC.

'' //The following flags may be passed in through the dwFlags
'' //parameter of the IUri::GetPropertyBSTR or IUri::GetPropertyLength functions.
'' //The following flags apply only to the property Uri_PROPERTY_DISPLAY_URI:
%Uri_DISPLAY_NO_FRAGMENT               = &H00000001???    ' // Exclude fragment from the DisplayUri, if one exists
%Uri_PUNYCODE_IDN_HOST                 = &H00000002???    ' // Show the hostname encoded as punycode inside the Host, Domain, or AbsoluteUri properties, if the Uri is IDN
%Uri_DISPLAY_IDN_HOST                  = &H00000004???    ' // Show the hostname encoded as punycode or Unicode as it would appear in the DisplayUri property. This applies to the Host, Domain, and AbsoluteUri properties.

'' // The following are Uri_ENCODING_ flags for use with the function CreateUriFromMultiByteString
%Uri_ENCODING_USER_INFO_AND_PATH_IS_PERCENT_ENCODED_UTF8  = &H00000001???
%Uri_ENCODING_USER_INFO_AND_PATH_IS_CP                    = &H00000002???
%Uri_ENCODING_HOST_IS_IDN                                 = &H00000004???
%Uri_ENCODING_HOST_IS_PERCENT_ENCODED_UTF8                = &H00000008???
%Uri_ENCODING_HOST_IS_PERCENT_ENCODED_CP                  = &H00000010???
%Uri_ENCODING_QUERY_AND_FRAGMENT_IS_PERCENT_ENCODED_UTF8  = &H00000020???
%Uri_ENCODING_QUERY_AND_FRAGMENT_IS_CP                    = &H00000040???
%Uri_ENCODING_RFC = %Uri_ENCODING_USER_INFO_AND_PATH_IS_PERCENT_ENCODED_UTF8 OR %Uri_ENCODING_HOST_IS_PERCENT_ENCODED_UTF8 OR %Uri_ENCODING_QUERY_AND_FRAGMENT_IS_PERCENT_ENCODED_UTF8

'' //The following flags may be passed in through the dwUriBuilderFlags
'' //parameter of the IUriBuilder::CreateUri
%UriBuilder_USE_ORIGINAL_FLAGS             = &H00000001???    ' // Use the create flags from the underlying IUri if they are available.


' ########################################################################################
' IUriContainer interface
' IID = A158A630-ED6F-45FB-B987-F68676F57752
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUriContainer_INTERFACE_DEFINED)
    %IUriContainer_INTERFACE_DEFINED = 1

$IID_IUriContainer = GUID$("{A158A630-ED6F-45FB-B987-F68676F57752}")

INTERFACE IUriContainer $IID_IUriContainer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetIUri ( _                                   ' VTable offset = 12
     BYREF ppIUri AS IUri _                             ' __out IUri **ppIUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUriContainer_INTERFACE_DEFINED__ */


' ########################################################################################
' IUriBuilder interface
' IID = 4221B2E1-8955-46C0-BD5B-DE9897565DE7
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUriBuilder_INTERFACE_DEFINED)
    %IUriBuilder_INTERFACE_DEFINED = 1

$IID_IUriBuilder = GUID$("{4221B2E1-8955-46C0-BD5B-DE9897565DE7}")

INTERFACE IUriBuilder $IID_IUriBuilder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateUriSimple ( _                           ' VTable offset = 12
     BYVAL dwAllowEncodingPropertyMask AS DWORD _       ' __in DWORD dwAllowEncodingPropertyMask
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD_PTR dwReserved
   , BYREF ppIUri AS IUri _                             ' __out IUri **ppIUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateUri ( _                                 ' VTable offset = 16
     BYVAL dwCreateFlags AS DWORD _                     ' __in DWORD dwCreateFlags
   , BYVAL dwAllowEncodingPropertyMask AS DWORD _       ' __in DWORD dwAllowEncodingPropertyMask
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD_PTR dwReserved
   , BYREF ppIUri AS IUri _                             ' __out IUri **ppIUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateUriWithFlags ( _                        ' VTable offset = 20
     BYVAL dwCreateFlags AS DWORD _                     ' __in DWORD dwCreateFlags
   , BYVAL dwUriBuilderFlags AS DWORD _                 ' __in DWORD dwUriBuilderFlags
   , BYVAL dwAllowEncodingPropertyMask AS DWORD _       ' __in DWORD dwAllowEncodingPropertyMask
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD_PTR dwReserved
   , BYREF ppIUri AS IUri _                             ' __out IUri **ppIUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIUri ( _                                   ' VTable offset = 24
     BYREF ppIUri AS IUri _                             ' __out IUri **ppIUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIUri ( _                                   ' VTable offset = 28
     BYVAL pIUri AS IUri _                              ' __in IUri *pIUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFragment ( _                               ' VTable offset = 32
     BYREF pcchFragment AS DWORD _                      ' __out DWORD *pcchFragment
   , BYREF ppwzFragment AS DWORD _                      ' __out LPCWSTR *ppwzFragment
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHost ( _                                   ' VTable offset = 36
     BYREF pcchHost AS DWORD _                          ' __out DWORD *pcchHost
   , BYREF ppwzHost AS DWORD _                          ' __out LPCWSTR *ppwzHost
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPassword ( _                               ' VTable offset = 40
     BYREF pcchPassword AS DWORD _                      ' __out DWORD *pcchPassword
   , BYREF ppwzPassword AS DWORD _                      ' __out LPCWSTR *ppwzPassword
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPath ( _                                   ' VTable offset = 44
     BYREF pcchPath AS DWORD _                          ' __out DWORD *pcchPath
   , BYREF ppwzPath AS DWORD _                          ' __out LPCWSTR *ppwzPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPort ( _                                   ' VTable offset = 48
     BYREF pfHasPort AS LONG _                          ' __out BOOL *pfHasPort
   , BYREF pdwPort AS DWORD _                           ' __out DWORD *pdwPort
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetQuery ( _                                  ' VTable offset = 52
     BYREF pcchQuery AS DWORD _                         ' __out DWORD *pcchQuery
   , BYREF ppwzQuery AS DWORD _                         ' __out LPCWSTR *ppwzQuery
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSchemeName ( _                             ' VTable offset = 56
     BYREF pcchSchemeName AS DWORD _                    ' __out DWORD *pcchSchemeName
   , BYREF ppwzSchemeName AS DWORD _                    ' __out LPCWSTR *ppwzSchemeName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUserName ( _                               ' VTable offset = 60
     BYREF pcchUserName AS DWORD _                      ' __out DWORD *pcchUserName
   , BYREF ppwzUserName AS DWORD _                      ' __out LPCWSTR *ppwzUserName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFragment ( _                               ' VTable offset = 64
     BYREF pwzNewValue AS WSTRINGZ _                    ' __in LPCWSTR pwzNewValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHost ( _                                   ' VTable offset = 68
     BYREF pwzNewValue AS WSTRINGZ _                    ' __in LPCWSTR pwzNewValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPassword ( _                               ' VTable offset = 72
     BYREF pwzNewValue AS WSTRINGZ _                    ' __in LPCWSTR pwzNewValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPath ( _                                   ' VTable offset = 76
     BYREF pwzNewValue AS WSTRINGZ _                    ' __in LPCWSTR pwzNewValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPort ( _                                   ' VTable offset = 80
     BYVAL fHasPort AS LONG _                           ' __in BOOL fHasPort
   , BYVAL dwNewValue AS DWORD _                        ' __in DWORD dwNewValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetQuery ( _                                  ' VTable offset = 84
     BYREF pwzNewValue AS WSTRINGZ _                    ' __in LPCWSTR pwzNewValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSchemeName ( _                             ' VTable offset = 88
     BYREF pwzNewValue AS WSTRINGZ _                    ' __in LPCWSTR pwzNewValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUserName ( _                               ' VTable offset = 92
     BYREF pwzNewValue AS WSTRINGZ _                    ' __in LPCWSTR pwzNewValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveProperties ( _                          ' VTable offset = 96
     BYVAL dwPropertyMask AS DWORD _                    ' __in DWORD dwPropertyMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HasBeenModified ( _                           ' VTable offset = 100
     BYREF pfModified AS LONG _                         ' __out BOOL *pfModified
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUriBuilder_INTERFACE_DEFINED__ */

' ########################################################################################
' IUriBuilderFactory interface
' IID = E982CE48-0B96-440C-BC37-0C869B27A29E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUriBuilderFactory_INTERFACE_DEFINED)
    %IUriBuilderFactory_INTERFACE_DEFINED = 1

$IID_IUriBuilderFactory = GUID$("{E982CE48-0B96-440C-BC37-0C869B27A29E}")

INTERFACE IUriBuilderFactory $IID_IUriBuilderFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateIUriBuilder ( _                         ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD_PTR dwReserved
   , BYREF ppIUriBuilder AS IUriBuilder _               ' __out IUriBuilder **ppIUriBuilder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateInitializedIUriBuilder ( _              ' VTable offset = 16
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD_PTR dwReserved
   , BYREF ppIUriBuilder AS IUriBuilder _               ' __out IUriBuilder **ppIUriBuilder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUriBuilderFactory_INTERFACE_DEFINED__ */


DECLARE FUNCTION CreateIUriBuilder IMPORT "URLMON.DLL" ALIAS "CreateIUriBuilder" ( _
   BYVAL pIUri AS IUri _                                ' __in_opt IUri *pIUri
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD_PTR dwReserved
 , BYREF ppIUriBuilder AS IUriBuilder _                 ' __out IUriBuilder **ppIUriBuilder
 ) AS LONG                                              ' HRESULT


' ########################################################################################
' IWinInetInfo interface
' IID = 79EAC9D6-BAFA-11CE-8C82-00AA004BA90B
' Inherited interface = IUnknown
' This interface retrieves option information used by the underlying Microsoft Win32
' Internet functions.
' Client applications can call QueryInterface on the IBinding interface to get a pointer
' to the IWinInetInfo interface after your implementation of the
' IBindStatusCallback::OnProgress method has been called. Not all protocol schemes support
' this interface.
' ########################################################################################

#IF NOT %DEF(%IWinInetInfo_INTERFACE_DEFINED)
    %IWinInetInfo_INTERFACE_DEFINED = 1

$IID_IWinInetInfo = GUID$("{79EAC9D6-BAFA-11CE-8C82-00AA004BA90B}")

INTERFACE IWinInetInfo $IID_IWinInetInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryOption ( _                               ' VTable offset = 12
     BYVAL dwOption AS DWORD _                          ' __in DWORD dwOption
   , BYVAL pBuffer AS DWORD _                           ' __in_out LPVOID pBuffer
   , BYREF pcbBuf AS DWORD _                            ' __in_out DWORD *pcbBuf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWinInetInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' IHttpSecurity interface
' IID = 79EAC9D7-BAFA-11CE-8C82-00AA004BA90B
' Inherited interface = IWindowForBindingUI
' This interface notifies a client application of authentication problems.
' Urlmon.dll uses the QueryInterface method on your implementation of IBindStatusCallback
' to obtain a pointer to your IHttpSecurity interface. If the application is hosting
' Mshtml.dll, Mshtml.dll will request a pointer to your IHttpSecurity interface by calling
' QueryInterface on your IServiceProvider interface.
' ########################################################################################

#IF NOT %DEF(%IHttpSecurity_INTERFACE_DEFINED)
    %IHttpSecurity_INTERFACE_DEFINED = 1

$IID_IHttpSecurity = GUID$("{79EAC9D7-BAFA-11CE-8C82-00AA004BA90B}")

INTERFACE IHttpSecurity $IID_IHttpSecurity

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetWindow ( _                                 ' VTable offset = 12
     BYREF rguidReason AS GUID _                        ' __in REFGUID rguidReason
   , BYREF phwnd AS DWORD _                             ' __out HWND *phwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnSecurityProblem ( _                         ' VTable offset = 16
     BYVAL dwProblem AS DWORD _                         ' __in DWORD dwProblem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHttpSecurity_INTERFACE_DEFINED__ */

' ########################################################################################
' IWinInetHttpInfo interface
' IID = 79EAC9D8-BAFA-11CE-8C82-00AA004BA90B
' Inherited interface = IWinInetInfo
' This interface checks information on HTTP requests made through the underlying Microsoft
' Win32 Internet functions.
' Client applications can call QueryInterface on the IBinding interface to get a pointer
' to the IWinInetHttpInfo interface after your implementation of the
' IBindStatusCallback::OnProgress method has been called.
' ########################################################################################

#IF NOT %DEF(%IWinInetHttpInfo_INTERFACE_DEFINED)
    %IWinInetHttpInfo_INTERFACE_DEFINED = 1

$IID_IWinInetHttpInfo = GUID$("{79EAC9D8-BAFA-11CE-8C82-00AA004BA90B}")

INTERFACE IWinInetHttpInfo $IID_IWinInetHttpInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryOption ( _                               ' VTable offset = 12
     BYVAL dwOption AS DWORD _                          ' __in DWORD dwOption
   , BYVAL pBuffer AS DWORD _                           ' __in_out LPVOID pBuffer
   , BYREF pcbBuf AS DWORD _                            ' __in_out DWORD *pcbBuf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryInfo ( _                                 ' VTable offset = 16
     BYVAL dwOption AS DWORD _                          ' __in DWORD dwOption
   , BYVAL pBuffer AS DWORD _                           ' __in_out LPVOID pBuffer
   , BYREF pcbBuf AS DWORD _                            ' __in_out DWORD *pcbBuf
   , BYREF pdwFlags AS DWORD _                          ' __in_out DWORD *pdwFlags
   , BYREF pdwReserved AS DWORD _                       ' __in_out DWORD *pdwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWinInetHttpInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' IWinInetCacheHints interface
' IID = 79EAC9D8-BAFA-11CE-8C82-00AA004BA90B
' Inherited interface = IUnknown
' Allows an URLMON client to change the file extension on the Microsoft Win32 Internet
' (WinInet) cache file.
' The IWinInetCacheHints interface was introduced in Internet Explorer 6 for Microsoft
' Windows XP Service Pack 2 (SP2).
' ########################################################################################

#IF NOT %DEF(%IWinInetCacheHints_INTERFACE_DEFINED)
    %IWinInetCacheHints_INTERFACE_DEFINED = 1

$IID_IWinInetCacheHints = GUID$("{79EAC9D8-BAFA-11CE-8C82-00AA004BA90B}")

INTERFACE IWinInetCacheHints $IID_IWinInetCacheHints

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetCacheExtension ( _                         ' VTable offset = 12
     BYREF pwzExt AS WSTRINGZ _                         ' __in LPCWSTR pwzExt
   , BYVAL pszCacheFile AS DWORD _                      ' __in_out LPVOID pszCacheFile
   , BYREF pcbCacheFile AS DWORD _                      ' __in_out DWORD *pcbCacheFile
   , BYREF pdwWinInetError AS DWORD _                   ' __in_out DWORD *pdwWinInetError
   , BYREF pdwReserved AS DWORD _                       ' __in_out DWORD *pdwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWinInetCacheHints_INTERFACE_DEFINED__ */

' ########################################################################################
' IWinInetCacheHints2 interface
' IID = 7857AEAC-D31F-49BF-884E-DD46DF36780A
' Inherited interface = IWinInetCacheHints
' ########################################################################################

#IF NOT %DEF(%IWinInetCacheHints2_INTERFACE_DEFINED)
    %IWinInetCacheHints2_INTERFACE_DEFINED = 1

$IID_IWinInetCacheHints2 = GUID$("{7857AEAC-D31F-49BF-884E-DD46DF36780A}")

INTERFACE IWinInetCacheHints2 $IID_IWinInetCacheHints2

   INHERIT IUnknown

   ' =====================================================================================
   ' IWinInetCacheHints Method
   ' =====================================================================================
   METHOD SetCacheExtension ( _                         ' VTable offset = 12
     BYREF pwzExt AS WSTRINGZ _                         ' __in LPCWSTR pwzExt
   , BYVAL pszCacheFile AS DWORD _                      ' __in_out LPVOID pszCacheFile
   , BYREF pcbCacheFile AS DWORD _                      ' __in_out DWORD *pcbCacheFile
   , BYREF pdwWinInetError AS DWORD _                   ' __in_out DWORD *pdwWinInetError
   , BYREF pdwReserved AS DWORD _                       ' __in_out DWORD *pdwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWinInetCacheHints2 Method
   ' =====================================================================================
   METHOD SetCacheExtension2 ( _                        ' VTable offset = 16
     BYREF pwzExt AS WSTRINGZ _                         ' __in LPCWSTR pwzExt
   , BYREF pwzCacheFile AS IWinInetCacheHints2 _        ' __out WCHAR *pwzCacheFile
   , BYREF pcchCacheFile AS DWORD _                     ' __in_out DWORD *pcchCacheFile
   , BYREF pdwWinInetError AS DWORD _                   ' __out DWORD *pdwWinInetError
   , BYREF pdwReserved AS DWORD _                       ' __out DWORD *pdwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWinInetCacheHints2_INTERFACE_DEFINED__ */

' ########################################################################################
' IBindHost interface
' IID = FC4801A1-2BA9-11CF-A229-00AA003D7352
' Inherited interface = IUnknown
' This interface is implemented by an Microsoft ActiveX container to allow controls to
' perform asynchronous data transfers through the container.
' ########################################################################################

#IF NOT %DEF(%IBindHost_INTERFACE_DEFINED)
    %IBindHost_INTERFACE_DEFINED = 1

$IID_IBindHost = GUID$("{FC4801A1-2BA9-11CF-A229-00AA003D7352}")
$SID_IBindHost = GUID$("{FC4801A1-2BA9-11CF-A229-00AA003D7352}")

INTERFACE IBindHost $IID_IBindHost

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateMoniker ( _                             ' VTable offset = 12
     BYVAL szName AS DWORD _                            ' __in LPOLESTR szName
   , BYVAL pbc AS IBindCtx _                            ' __in IBindCtx *pbc
   , BYREF ppmk AS IMoniker _                           ' __out IMoniker **ppmk
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MonikerBindToStorage ( _                      ' VTable offset = 16
     BYVAL pMk AS IMoniker _                            ' __in IMoniker *pMk
   , BYVAL pbc AS IBindCtx _                            ' __in IBindCtx *pbc
   , BYVAL pbsc AS IBindStatusCallback _                ' __in IBindStatusCallback *pbsc
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObj AS IUnknown _                         ' __out void **ppvObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MonikerBindToObject ( _                       ' VTable offset = 20
     BYVAL pMk AS IMoniker _                            ' __in IMoniker *pMk
   , BYVAL pbc AS IBindCtx _                            ' __in IBindCtx *pbc
   , BYVAL pbsc AS IBindStatusCallback _                ' __in IBindStatusCallback *pbsc
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObj AS IUnknown _                         ' __out void **ppvObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBindHost_INTERFACE_DEFINED__ */

'// These are for backwards compatibility with previous URLMON versions
'// Flags for the UrlDownloadToCacheFile
%URLOSTRM_USECACHEDCOPY_ONLY = &H1   ' // Only get from cache
%URLOSTRM_USECACHEDCOPY      = &H2   ' // Get from cache if available else download
%URLOSTRM_GETNEWESTVERSION   = &H3   ' // Get new version only. But put it in cache too

'struct IBindStatusCallback;

DECLARE FUNCTION HlinkSimpleNavigateToString IMPORT "URLMON.DLL" ALIAS "HlinkSetSimpleNavigateToString" ( _
   BYREF szTarget AS WSTRINGZ _                         ' __in LPCWSTR szTarget
 , BYREF szLocation AS WSTRINGZ _                       ' __in LPCWSTR szLocation
 , BYREF szTargetFrameName AS WSTRINGZ _                ' __in LPCWSTR szTargetFrameName
 , BYVAL pUnk AS IUnknown _                             ' __in IUnknown *pUnk
 , BYVAL pbc AS IBindCtx _                              ' __in IBindCtx *pbc
 , BYVAL pbsc AS IBindStatusCallback _                  ' __in IBindStatusCallback *pbsc
 , BYVAL grfHLNF AS DWORD _                             ' __in DWORD grfHLNF
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION HlinkSimpleNavigateToMoniker IMPORT "URLMON.DLL" ALIAS "HlinkSetSimpleNavigateToMoniker" ( _
   BYVAL pmkTarget AS IMoniker _                        ' __in IMoniker *pmkTarget
 , BYREF szLocation AS WSTRINGZ _                       ' __in LPCWSTR szLocation
 , BYREF szTargetFrameName AS WSTRINGZ _                ' __in LPCWSTR szTargetFrameName
 , BYVAL pUnk AS IUnknown _                             ' __in IUnknown *pUnk
 , BYVAL pbc AS IBindCtx _                              ' __in IBindCtx *pbc
 , BYVAL pbsc AS IBindStatusCallback _                  ' __in IBindStatusCallback *pbsc
 , BYVAL grfHLNF AS DWORD _                             ' __in DWORD grfHLNF
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION URLOpenStreamA IMPORT "URLMON.DLL" ALIAS "URLOpenStreamA" ( _
   BYVAL pCaller AS IUnknown _                          ' __in LPUNKNOWN pCaller
 , BYREF szURL AS ASCIIZ _                              ' __in LPCSTR szURL
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 , BYVAL lpfnCB AS IBindStatusCallback _                ' __in LPBINDSTATUSCALLBACK lpfnCB
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION URLOpenStreamW IMPORT "URLMON.DLL" ALIAS "URLOpenStreamW" ( _
   BYVAL pCaller AS IUnknown _                          ' __in LPUNKNOWN pCaller
 , BYREF szURL AS WSTRINGZ _                            ' __in LPCWSTR szURL
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 , BYVAL lpfnCB AS IBindStatusCallback _                ' __in LPBINDSTATUSCALLBACK lpfnCB
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO URLOpenStream = URLOpenStreamW
#ELSE
   MACRO URLOpenStream = URLOpenStreamA
#ENDIF

DECLARE FUNCTION URLOpenPullStreamA IMPORT "URLMON.DLL" ALIAS "URLOpenPullStreamA" ( _
   BYVAL pCaller AS IUnknown _                          ' __in LPUNKNOWN pCaller
 , BYREF szURL AS ASCIIZ _                              ' __in LPCSTR szURL
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 , BYVAL lpfnCB AS IBindStatusCallback _                ' __in LPBINDSTATUSCALLBACK lpfnCB
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION URLOpenPullStreamW IMPORT "URLMON.DLL" ALIAS "URLOpenPullStreamW" ( _
   BYVAL pCaller AS IUnknown _                          ' __in LPUNKNOWN pCaller
 , BYREF szURL AS WSTRINGZ _                            ' __in LPCWSTR szURL
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 , BYVAL lpfnCB AS IBindStatusCallback _                ' __in LPBINDSTATUSCALLBACK lpfnCB
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO URLOpenPullStream = URLOpenPullStreamW
#ELSE
   MACRO URLOpenPullStream = URLOpenPullStreamA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION URLDownloadToFileA LIB "UrlMon.dll" _
    ALIAS "URLDownloadToFileA" ( _
    BYVAL pCaller    AS DWORD, _
    szURL            AS ASCIIZ, _
    szFileName       AS ASCIIZ, _
    BYVAL dwReserved AS DWORD, _
    BYVAL lpfnCB     AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION URLDownloadToFileA IMPORT "URLMON.DLL" ALIAS "URLDownloadToFileA" ( _
   BYVAL pCaller AS IUnknown _                          ' __in LPUNKNOWN pCaller
 , BYREF szURL AS ASCIIZ _                              ' __in LPCSTR szURL
 , BYREF szFileName AS ASCIIZ _                         ' __in LPCSTR szFileName
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 , BYVAL lpfnCB AS IBindStatusCallback _                ' __in LPBINDSTATUSCALLBACK lpfnCB
 ) AS LONG                                              ' HRESULT
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION URLDownloadToFileW LIB "UrlMon.dll" _
    ALIAS "URLDownloadToFileW" ( _
    BYVAL pCaller    AS DWORD, _
    szURL            AS WSTRINGZ, _
    szFileName       AS WSTRINGZ, _
    BYVAL dwReserved AS DWORD, _
    BYVAL lpfnCB     AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION URLDownloadToFileW IMPORT "URLMON.DLL" ALIAS "URLDownloadToFileW" ( _
   BYVAL pCaller AS IUnknown _                          ' __in LPUNKNOWN pCaller
 , BYREF szURL AS WSTRINGZ _                            ' __in LPCWSTR szURL
 , BYREF szFileName AS WSTRINGZ _                       ' __in LPCWSTR szFileName
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 , BYVAL lpfnCB AS IBindStatusCallback _                ' __in LPBINDSTATUSCALLBACK lpfnCB
 ) AS LONG                                              ' HRESULT
#ENDIF

#IF %DEF(%UNICODE)
   MACRO URLDownloadToFile = URLDownloadToFileW
#ELSE
   MACRO URLDownloadToFile = URLDownloadToFileA
#ENDIF

DECLARE FUNCTION URLDownloadToCacheFileA IMPORT "URLMON.DLL" ALIAS "URLDownloadToCacheFileA" ( _
   BYVAL lpUnkcaller AS IUnknown _                      ' __in LPUNKNOWN lpUnkcaller
 , BYREF szURL AS ASCIIZ _                              ' __in LPCSTR szURL
 , BYREF szFileName AS ASCIIZ _                         ' __in LPCSTR szFileName
 , BYVAL dwBufLength AS DWORD _                         ' __in DWORD dwBufLength
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 , BYVAL pbsc AS IBindStatusCallback _                  ' __in IBindStatusCallback *pbsc
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION URLDownloadToCacheFileW IMPORT "URLMON.DLL" ALIAS "URLDownloadToCacheFileW" ( _
   BYVAL lpUnkcaller AS IUnknown _                      ' __in LPUNKNOWN lpUnkcaller
 , BYREF szURL AS WSTRINGZ _                            ' __in LPCWSTR szURL
 , BYREF szFileName AS WSTRINGZ _                       ' __in LPWSTR szFileName
 , BYVAL dwBufLength AS DWORD _                         ' __in DWORD dwBufLength
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 , BYVAL pbsc AS IBindStatusCallback _                  ' __in IBindStatusCallback *pbsc
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO URLDownloadToCacheFile = URLDownloadToCacheFileW
#ELSE
   MACRO URLDownloadToCacheFile = URLDownloadToCacheFileA
#ENDIF

DECLARE FUNCTION URLOpenBlockingStreamA IMPORT "URLMON.DLL" ALIAS "URLOpenBlockingStreamA" ( _
   BYVAL pCaller AS IUnknown _                          ' __in LPUNKNOWN pCaller
 , BYREF szURL AS ASCIIZ _                              ' __in LPCSTR szURL
 , BYREF ppStream AS IStream _                          ' __out LPSTREAM *ppStream
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 , BYVAL lpfnCB AS IBindStatusCallback _                ' __in LPBINDSTATUSCALLBACK lpfnCB
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION URLOpenBlockingStreamW IMPORT "URLMON.DLL" ALIAS "URLOpenBlockingStreamW" ( _
   BYVAL pCaller AS IUnknown _                          ' __in LPUNKNOWN pCaller
 , BYREF szURL AS WSTRINGZ _                            ' __in LPCWSTR szURL
 , BYREF ppStream AS IStream _                          ' __out LPSTREAM *ppStream
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 , BYVAL lpfnCB AS IBindStatusCallback _                ' __in LPBINDSTATUSCALLBACK lpfnCB
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO URLOpenBlockingStream = URLOpenBlockingStreamW
#ELSE
   MACRO URLOpenBlockingStream = URLOpenBlockingStreamA
#ENDIF

DECLARE FUNCTION HlinkGoBack IMPORT "URLMON.DLL" ALIAS "HlinkGoBack" ( _
   BYVAL pUnk AS IUnknown _                             ' __in IUnknown *pUnk
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION HlinkGoForward IMPORT "URLMON.DLL" ALIAS "HlinkGoForward" ( _
   BYVAL pUnk AS IUnknown _                             ' __in IUnknown *pUnk
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION HlinkNavigateString IMPORT "URLMON.DLL" ALIAS "HlinkNavigateString" ( _
   BYVAL pUnk AS IUnknown _                             ' __in IUnknown *pUnk
 , BYREF szTarget AS WSTRINGZ _                         ' __in LPCWSTR szTarget
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION HlinkNavigateMoniker IMPORT "URLMON.DLL" ALIAS "HlinkNavigateMoniker" ( _
   BYVAL pUnk AS IUnknown _                             ' __in IUnknown *pUnk
 , BYVAL pmkTarget AS IMoniker _                        ' __in IMoniker *pmkTarget
 ) AS LONG                                              ' HRESULT

#IF NOT %DEF(%URLMON_NO_ASYNC_PLUGABLE_PROTOCOLS)
    %URLMON_NO_ASYNC_PLUGABLE_PROTOCOLS = 1

' ########################################################################################
' IInternet interface
' IID = 79EAC9E0-BAF9-11CE-8C82-00AA004BA90B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInternet_INTERFACE_DEFINED)
    %IInternet_INTERFACE_DEFINED = 1

$IID_IInternet = GUID$("{79EAC9E0-BAF9-11CE-8C82-00AA004BA90B}")

INTERFACE IInternet $IID_IInternet

   INHERIT IUnknown

END INTERFACE

#ENDIF   ' /* __IInternet_INTERFACE_DEFINED__ */

' ########################################################################################
' IInternetBindInfo interface
' IID = 79EAC9E1-BAF9-11CE-8C82-00AA004BA90B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInternetBindInfo_INTERFACE_DEFINED)
    %IInternetBindInfo_INTERFACE_DEFINED = 1

' BINDSTRING enum
%BINDSTRING_HEADERS             = 1
%BINDSTRING_ACCEPT_MIMES        = %BINDSTRING_HEADERS             + 1
%BINDSTRING_EXTRA_URL           = %BINDSTRING_ACCEPT_MIMES        + 1
%BINDSTRING_LANGUAGE            = %BINDSTRING_EXTRA_URL           + 1
%BINDSTRING_USERNAME            = %BINDSTRING_LANGUAGE            + 1
%BINDSTRING_PASSWORD            = %BINDSTRING_USERNAME            + 1
%BINDSTRING_UA_PIXELS           = %BINDSTRING_PASSWORD            + 1
%BINDSTRING_UA_COLOR            = %BINDSTRING_UA_PIXELS           + 1
%BINDSTRING_OS                  = %BINDSTRING_UA_COLOR            + 1
%BINDSTRING_USER_AGENT          = %BINDSTRING_OS                  + 1
%BINDSTRING_ACCEPT_ENCODINGS    = %BINDSTRING_USER_AGENT          + 1
%BINDSTRING_POST_COOKIE         = %BINDSTRING_ACCEPT_ENCODINGS    + 1
%BINDSTRING_POST_DATA_MIME      = %BINDSTRING_POST_COOKIE         + 1
%BINDSTRING_URL                 = %BINDSTRING_POST_DATA_MIME      + 1
%BINDSTRING_IID                 = %BINDSTRING_URL                 + 1
%BINDSTRING_FLAG_BIND_TO_OBJECT = %BINDSTRING_IID                 + 1
%BINDSTRING_PTR_BIND_CONTEXT    = %BINDSTRING_FLAG_BIND_TO_OBJECT + 1
%BINDSTRING_XDR_ORIGIN          = %BINDSTRING_PTR_BIND_CONTEXT    + 1

$IID_IInternetBindInfo = GUID$("{79EAC9E1-BAF9-11CE-8C82-00AA004BA90B}")

INTERFACE IInternetBindInfo $IID_IInternetBindInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetBindInfo ( _                               ' VTable offset = 12
     BYREF grfBINDF AS DWORD _                          ' __out DWORD *grfBINDF
   , BYREF pbindinfo AS BINDINFO _                      ' __in_out BINDINFO *pbindinfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBindString ( _                             ' VTable offset = 16
     BYVAL ulStringType AS DWORD _                      ' __in ULONG ulStringType
   , BYREF ppwzStr AS DWORD _                           ' __in_out LPOLESTR *ppwzStr
   , BYVAL cEl AS DWORD _                               ' __in ULONG cEl
   , BYREF pcElFetched AS DWORD _                       ' __in_out ULONG *pcElFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInternetBindInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' IInternetBindInfoEx interface
' IID = A3E015B7-A82C-4DCD-A150-569AEEED36AB
' Inherited interface = IInternetBindInfo
' ########################################################################################

#IF NOT %DEF(%IInternetBindInfoEx_INTERFACE_DEFINED)
    %IInternetBindInfoEx_INTERFACE_DEFINED = 1

$IID_IInternetBindInfoEx = GUID$("{A3E015B7-A82C-4DCD-A150-569AEEED36AB}")

INTERFACE IInternetBindInfoEx $IID_IInternetBindInfoEx

   INHERIT IUnknown

   ' =====================================================================================
   ' IInternetBindInfo methods
   ' =====================================================================================
   METHOD GetBindInfo ( _                               ' VTable offset = 12
     BYREF grfBINDF AS DWORD _                          ' __out DWORD *grfBINDF
   , BYREF pbindinfo AS BINDINFO _                      ' __in_out BINDINFO *pbindinfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBindString ( _                             ' VTable offset = 16
     BYVAL ulStringType AS DWORD _                      ' __in ULONG ulStringType
   , BYREF ppwzStr AS DWORD _                           ' __in_out LPOLESTR *ppwzStr
   , BYVAL cEl AS DWORD _                               ' __in ULONG cEl
   , BYREF pcElFetched AS DWORD _                       ' __in_out ULONG *pcElFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IInternetBindInfoEx methods
   ' =====================================================================================
   METHOD GetBindInfoEx ( _                             ' VTable offset = 20
     BYREF grfBINDF AS DWORD _                          ' __out DWORD *grfBINDF
   , BYREF pbindinfo AS BINDINFO _                      ' __inout BINDINFO *pbindinfo
   , BYREF grfBINDF2 AS DWORD _                         ' __out DWORD *grfBINDF2
   , BYREF pdwReserved AS DWORD _                       ' __out DWORD *pdwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInternetBindInfoEx_INTERFACE_DEFINED__ */

' ########################################################################################
' IInternetProtocolRoot interface
' IID = 79EAC9E3-BAF9-11CE-8C82-00AA004BA90B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInternetProtocolRoot_INTERFACE_DEFINED)
    %IInternetProtocolRoot_INTERFACE_DEFINED = 1

' PI_FLAGS enum
%PI_PARSE_URL            = &H1???
%PI_FILTER_MODE          = &H2???
%PI_FORCE_ASYNC          = &H4???
%PI_USE_WORKERTHREAD     = &H8???
%PI_MIMEVERIFICATION     = &H10???
%PI_CLSIDLOOKUP          = &H20???
%PI_DATAPROGRESS         = &H40???
%PI_SYNCHRONOUS          = &H80???
%PI_APARTMENTTHREADED    = &H100???
%PI_CLASSINSTALL         = &H200???
%PI_PASSONBINDCTX        = &H2000???
%PI_NOMIMEHANDLER        = &H8000???
%PI_LOADAPPDIRECT        = &H4000???
%PD_FORCE_SWITCH         = &H10000???
%PI_PREFERDEFAULTHANDLER = &H20000???

%PI_DOCFILECLSIDLOOKUP   = %PI_CLSIDLOOKUP

' // Size = 16 bytes
TYPE PROTOCOLDATA DWORD
   grfFlags AS DWORD   ' DWORD grfFlags
   dwState  AS DWORD   ' DWORD dwState
   pData    AS DWORD   ' LPVOID pData
   cbData   AS DWORD   ' ULONG cbData
END TYPE

' // Size = 24 bytes
TYPE StartParam DWORD
   iid       AS GUID        ' IID iid
   pIBindCtx AS DWORD PTR   ' IBindCtx *pIBindCtx
   pItf      AS DWORD PTR   ' IUnknown *pItf
END TYPE

$IID_IInternetProtocolRoot = GUID$("{79EAC9E3-BAF9-11CE-8C82-00AA004BA90B}")

INTERFACE IInternetProtocolRoot $IID_IInternetProtocolRoot

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 12
     BYREF szUrl AS WSTRINGZ _                          ' __in LPCWSTR szUrl
   , BYVAL pOIProtSink AS IInternetProtocolSink _       ' __in IInternetProtocolSink *pOIProtSink
   , BYVAL pOIBindInfo AS IInternetBindInfo _           ' __in IInternetBindInfo *pOIBindInfo
   , BYVAL grfPI AS DWORD _                             ' __in DWORD grfPI
   , BYVAL dwReserved AS DWORD _                        ' __in HANDLE_PTR dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Continue ( _                                  ' VTable offset = 16
     BYREF pProtocolData AS PROTOCOLDATA _              ' __in PROTOCOLDATA *pProtocolData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 20
     BYVAL hrReason AS DWORD _                          ' __in HRESULT hrReason
   , BYVAL dwOptions AS DWORD _                         ' __in DWORD dwOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Terminate ( _                                 ' VTable offset = 24
     BYVAL dwOptions AS DWORD _                         ' __in DWORD dwOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Suspend ( _                                   ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Resume ( _                                    ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInternetProtocolRoot_INTERFACE_DEFINED__ */

' ########################################################################################
' IInternetProtocol interface
' IID = 79EAC9E4-BAF9-11CE-8C82-00AA004BA90B
' Inherited interface = IInternetProtocolRoot
' ########################################################################################

#IF NOT %DEF(%IInternetProtocol_INTERFACE_DEFINED)
    %IInternetProtocol_INTERFACE_DEFINED = 1

$IID_IInternetProtocol = GUID$("{79EAC9E4-BAF9-11CE-8C82-00AA004BA90B}")

INTERFACE IInternetProtocol $IID_IInternetProtocol

   INHERIT IUnknown

   ' =====================================================================================
   ' IInternetProtocolRoot Methods
   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 12
     BYREF szUrl AS WSTRINGZ _                          ' __in LPCWSTR szUrl
   , BYVAL pOIProtSink AS IInternetProtocolSink _       ' __in IInternetProtocolSink *pOIProtSink
   , BYVAL pOIBindInfo AS IInternetBindInfo _           ' __in IInternetBindInfo *pOIBindInfo
   , BYVAL grfPI AS DWORD _                             ' __in DWORD grfPI
   , BYVAL dwReserved AS DWORD _                        ' __in HANDLE_PTR dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Continue ( _                                  ' VTable offset = 16
     BYREF pProtocolData AS PROTOCOLDATA _              ' __in PROTOCOLDATA *pProtocolData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 20
     BYVAL hrReason AS DWORD _                          ' __in HRESULT hrReason
   , BYVAL dwOptions AS DWORD _                         ' __in DWORD dwOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Terminate ( _                                 ' VTable offset = 24
     BYVAL dwOptions AS DWORD _                         ' __in DWORD dwOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Suspend ( _                                   ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Resume ( _                                    ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IInternetProtocol Methods
   ' =====================================================================================
   METHOD Read ( _                                      ' VTable offset = 36
     BYREF pv AS DWORD _                                ' __in_out void *pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbRead AS DWORD _                           ' __out ULONG *pcbRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Seek ( _                                      ' VTable offset = 40
     BYVAL dlibMove AS QUAD _                           ' __in LARGE_INTEGER dlibMove
   , BYVAL dwOrigin AS DWORD _                          ' __in DWORD dwOrigin
   , BYREF plibNewPosition AS QUAD _                    ' __out ULARGE_INTEGER *plibNewPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockRequest ( _                               ' VTable offset = 44
     BYVAL dwOptions AS DWORD _                         ' __in DWORD dwOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockRequest ( _                             ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInternetProtocol_INTERFACE_DEFINED__ */

' ########################################################################################
' IInternetProtocolEx interface
' IID = C7A98E66-1010-492C-A1C8-C809E1F75905
' Inherited interface = IInternetProtocol
' ########################################################################################

#IF NOT %DEF(%IInternetProtocolEx_INTERFACE_DEFINED)
    %IInternetProtocol_INTERFACE_DEFINED = 1

$IID_IInternetProtocolEx = GUID$("{C7A98E66-1010-492C-A1C8-C809E1F75905}")

INTERFACE IInternetProtocolEx $IID_IInternetProtocolEx

   INHERIT IUnknown

   ' =====================================================================================
   ' IInternetProtocolRoot Methods
   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 12
     BYREF szUrl AS WSTRINGZ _                          ' __in LPCWSTR szUrl
   , BYVAL pOIProtSink AS IInternetProtocolSink _       ' __in IInternetProtocolSink *pOIProtSink
   , BYVAL pOIBindInfo AS IInternetBindInfo _           ' __in IInternetBindInfo *pOIBindInfo
   , BYVAL grfPI AS DWORD _                             ' __in DWORD grfPI
   , BYVAL dwReserved AS DWORD _                        ' __in HANDLE_PTR dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Continue ( _                                  ' VTable offset = 16
     BYREF pProtocolData AS PROTOCOLDATA _              ' __in PROTOCOLDATA *pProtocolData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 20
     BYVAL hrReason AS DWORD _                          ' __in HRESULT hrReason
   , BYVAL dwOptions AS DWORD _                         ' __in DWORD dwOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Terminate ( _                                 ' VTable offset = 24
     BYVAL dwOptions AS DWORD _                         ' __in DWORD dwOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Suspend ( _                                   ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Resume ( _                                    ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IInternetProtocol Methods
   ' =====================================================================================
   METHOD Read ( _                                      ' VTable offset = 36
     BYREF pv AS DWORD _                                ' __in_out void *pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbRead AS DWORD _                           ' __out ULONG *pcbRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Seek ( _                                      ' VTable offset = 40
     BYVAL dlibMove AS QUAD _                           ' __in LARGE_INTEGER dlibMove
   , BYVAL dwOrigin AS DWORD _                          ' __in DWORD dwOrigin
   , BYREF plibNewPosition AS QUAD _                    ' __out ULARGE_INTEGER *plibNewPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockRequest ( _                               ' VTable offset = 44
     BYVAL dwOptions AS DWORD _                         ' __in DWORD dwOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockRequest ( _                             ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IInternetProtocolEx Methods
   ' =====================================================================================
   METHOD StartEx ( _                                   ' VTable offset = 52
     BYVAL pUri AS IUri _                               ' __in IUri *pUri
   , BYVAL pOIProtSink AS IInternetProtocolSink _       ' __in IInternetProtocolSink *pOIProtSink
   , BYVAL pOIBindInfo AS IInternetBindInfo _           ' __in IInternetBindInfo *pOIBindInfo
   , BYVAL grfPI AS DWORD _                             ' __in DWORD grfPI
   , BYVAL dwReserved AS DWORD _                        ' __in HANDLE_PTR dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInternetProtocolEx_INTERFACE_DEFINED__ */

' ########################################################################################
' IInternetProtocolSink interface
' IID = 79EAC9E5-BAF9-11CE-8C82-00AA004BA90B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInternetProtocolSink_INTERFACE_DEFINED)
    %IInternetProtocolSink_INTERFACE_DEFINED = 1

$IID_IInternetProtocolSink = GUID$("{79EAC9E5-BAF9-11CE-8C82-00AA004BA90B}")

INTERFACE IInternetProtocolSink $IID_IInternetProtocolSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Switch ( _                                    ' VTable offset = 12
     BYREF pProtocolData AS PROTOCOLDATA _              ' __in PROTOCOLDATA *pProtocolData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReportProgress ( _                            ' VTable offset = 20
     BYVAL ulStatusCode AS DWORD _                      ' __in ULONG ulStatusCode
   , BYREF szStatusText AS WSTRINGZ _                   ' __in LPCWSTR szStatusText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReportData ( _                                ' VTable offset = 24
     BYVAL grfBSCF AS DWORD _                           ' __in DWORD grfBSCF
   , BYVAL ulProgress AS DWORD _                        ' __in ULONG ulProgress
   , BYVAL ulProgressMax AS DWORD _                     ' __in ULONG ulProgressMax
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReportResult ( _                              ' VTable offset = 28
     BYVAL hrResult AS LONG _                           ' __in HRESULT hrResult
   , BYVAL dwError AS DWORD _                           ' __in DWORD dwError
   , BYREF szResult AS WSTRINGZ _                       ' __in LPCWSTR szResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInternetProtocolSink_INTERFACE_DEFINED__ */


' ########################################################################################
' IInternetProtocolSinkStackable interface
' IID = 79EAC9F0-BAF9-11CE-8C82-00AA004BA90B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInternetProtocolSinkStackable_INTERFACE_DEFINED)
    %IInternetProtocolSinkStackable_INTERFACE_DEFINED = 1

$IID_IInternetProtocolSinkStackable = GUID$("{79EAC9F0-BAF9-11CE-8C82-00AA004BA90B}")

INTERFACE IInternetProtocolSinkStackable $IID_IInternetProtocolSinkStackable

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SwitchSink ( _                                ' VTable offset = 12
     BYVAL pOIProtSink AS IInternetProtocolSink _       ' __in IInternetProtocolSink *pOIProtSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CommitSwitch ( _                              ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RollbackSwitch ( _                            ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInternetProtocolSinkStackable_INTERFACE_DEFINED__ */


' ########################################################################################
' IInternetSession interface
' IID = 79EAC9E7-BAF9-11CE-8C82-00AA004BA90B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInternetSession_INTERFACE_DEFINED)
    %IInternetSession_INTERFACE_DEFINED = 1

' OIBDG_FLAGS enum
%OIBDG_APARTMENTTHREADED = &H100???
%OIBDG_DATAONLY          = &H1000???

$IID_IInternetSession = GUID$("{79EAC9E7-BAF9-11CE-8C82-00AA004BA90B}")

INTERFACE IInternetSession $IID_IInternetSession

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RegisterNameSpace ( _                         ' VTable offset = 12
     BYVAL pCF AS IClassFactory _                       ' __in IClassFactory *pCF
   , BYREF rclsid AS GUID _                             ' __in REFCLSID rclsid
   , BYREF pwzProtocol AS WSTRINGZ _                    ' __in LPCWSTR pwzProtocol
   , BYVAL cPatterns AS DWORD _                         ' __in ULONG cPatterns
   , BYREF ppwzPatterns AS DWORD _                      ' __in const LPCWSTR *ppwzPatterns [array]
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterNameSpace ( _                       ' VTable offset = 16
     BYVAL pCF AS IClassFactory _                       ' __in IClassFactory *pCF
   , BYREF pszProtocol AS WSTRINGZ _                    ' __in LPCWSTR pszProtocol
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterMimeFilter ( _                        ' VTable offset = 20
     BYVAL pCF AS IClassFactory _                       ' __in IClassFactory *pCF
   , BYREF rclsid AS GUID _                             ' __in REFCLSID rclsid
   , BYREF pwzType AS WSTRINGZ _                        ' __in LPCWSTR pwzType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterMimeFilter ( _                      ' VTable offset = 24
     BYVAL pCF AS IClassFactory _                       ' __in IClassFactory *pCF
   , BYREF pwzType AS WSTRINGZ _                        ' __in LPCWSTR pwzType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBinding ( _                             ' VTable offset = 28
     BYVAL pBC AS IBindCtx _                            ' __in LPBC pBC
   , BYREF szUrl AS WSTRINGZ _                          ' __in LPCWSTR szUrl
   , BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF ppUnk AS IUnknown _                          ' __out IUnknown **ppUnk
   , BYREF ppOInetProt AS IInternetProtocol _           ' __out IInternetProtocol **ppOInetProt
   , BYVAL dwOption AS DWORD _                          ' __in DWORD dwOption
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSessionOption ( _                          ' VTable offset = 32
     BYVAL dwOption AS DWORD _                          ' __in DWORD dwOption
   , BYVAL pBuffer AS DWORD _                           ' __in LPVOID pBuffer
   , BYVAL dwBufferLength AS DWORD _                    ' __in DWORD dwBufferLength
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSessionOption ( _                          ' VTable offset = 36
     BYVAL dwOption AS DWORD _                          ' __in DWORD dwOption
   , BYVAL pBuffer AS DWORD _                           ' __in_out LPVOID pBuffer
   , BYREF pdwBufferLength AS DWORD _                   ' __in_out DWORD *pdwBufferLength
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInternetSession_INTERFACE_DEFINED__ */

' ########################################################################################
' IInternetThreadSwitch interface
' IID = 79EAC9E8-BAF9-11CE-8C82-00AA004BA90B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInternetThreadSwitch_INTERFACE_DEFINED)
    %IInternetThreadSwitch_INTERFACE_DEFINED = 1

$IID_IInternetThreadSwitch = GUID$("{79EAC9E8-BAF9-11CE-8C82-00AA004BA90B}")

INTERFACE IInternetThreadSwitch $IID_IInternetThreadSwitch

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Prepare ( _                                   ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Continue ( _                                  ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInternetThreadSwitch_INTERFACE_DEFINED__ */

' ########################################################################################
' IInternetPriority interface
' IID = 79EAC9EB-BAF9-11CE-8C82-00AA004BA90B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInternetPriority_INTERFACE_DEFINED)
    %IInternetPriority_INTERFACE_DEFINED = 1

$IID_IInternetPriority = GUID$("{79EAC9EB-BAF9-11CE-8C82-00AA004BA90B}")

INTERFACE IInternetPriority $IID_IInternetPriority

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetPriority ( _                               ' VTable offset = 12
     BYVAL nPriority AS LONG _                          ' __in LONG nPriority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPriority ( _                               ' VTable offset = 16
     BYREF pnPriority AS LONG _                         ' __out LONG *pnPriority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInternetPriority_INTERFACE_DEFINED__ */

' ########################################################################################
' IInternetProtocolInfo interface
' IID = 79EAC9EC-BAF9-11CE-8C82-00AA004BA90B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInternetProtocolInfo_INTERFACE_DEFINED)
    %IInternetProtocolInfo_INTERFACE_DEFINED = 1

' PARSEACTION enum
%PARSE_CANONICALIZE    = 1
%PARSE_FRIENDLY        = %PARSE_CANONICALIZE    + 1
%PARSE_SECURITY_URL    = %PARSE_FRIENDLY        + 1
%PARSE_ROOTDOCUMENT    = %PARSE_SECURITY_URL    + 1
%PARSE_DOCUMENT        = %PARSE_ROOTDOCUMENT    + 1
%PARSE_ANCHOR          = %PARSE_DOCUMENT        + 1
%PARSE_ENCODE          = %PARSE_ANCHOR          + 1
%PARSE_DECODE          = %PARSE_ENCODE          + 1
%PARSE_PATH_FROM_URL   = %PARSE_DECODE          + 1
%PARSE_URL_FROM_PATH   = %PARSE_PATH_FROM_URL   + 1
%PARSE_MIME            = %PARSE_URL_FROM_PATH   + 1
%PARSE_SERVER          = %PARSE_MIME            + 1
%PARSE_SCHEMA          = %PARSE_SERVER          + 1
%PARSE_SITE            = %PARSE_SCHEMA          + 1
%PARSE_DOMAIN          = %PARSE_SITE            + 1
%PARSE_LOCATION        = %PARSE_DOMAIN          + 1
%PARSE_SECURITY_DOMAIN = %PARSE_LOCATION        + 1
%PARSE_ESCAPE          = %PARSE_SECURITY_DOMAIN + 1
%PARSE_UNESCAPE        = %PARSE_ESCAPE          + 1

' PSUACTION enum
%PSU_DEFAULT           = 1
%PSU_SECURITY_URL_ONLY = %PSU_DEFAULT + 1

' QUERYOPTION enum
%QUERY_EXPIRATION_DATE     = 1
%QUERY_TIME_OF_LAST_CHANGE = %QUERY_EXPIRATION_DATE     + 1
%QUERY_CONTENT_ENCODING    = %QUERY_TIME_OF_LAST_CHANGE + 1
%QUERY_CONTENT_TYPE        = %QUERY_CONTENT_ENCODING    + 1
%QUERY_REFRESH             = %QUERY_CONTENT_TYPE        + 1
%QUERY_RECOMBINE           = %QUERY_REFRESH             + 1
%QUERY_CAN_NAVIGATE        = %QUERY_RECOMBINE           + 1
%QUERY_USES_NETWORK        = %QUERY_CAN_NAVIGATE        + 1
%QUERY_IS_CACHED           = %QUERY_USES_NETWORK        + 1
%QUERY_IS_INSTALLEDENTRY   = %QUERY_IS_CACHED           + 1
%QUERY_IS_CACHED_OR_MAPPED = %QUERY_IS_INSTALLEDENTRY   + 1
%QUERY_USES_CACHE          = %QUERY_IS_CACHED_OR_MAPPED + 1
%QUERY_IS_SECURE           = %QUERY_USES_CACHE          + 1
%QUERY_IS_SAFE             = %QUERY_IS_SECURE           + 1
%QUERY_USES_HISTORYFOLDER  = %QUERY_IS_SAFE             + 1

$IID_IInternetProtocolInfo = GUID$("{79EAC9EC-BAF9-11CE-8C82-00AA004BA90B}")

INTERFACE IInternetProtocolInfo $IID_IInternetProtocolInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ParseUrl ( _                                  ' VTable offset = 12
     BYREF pwzUrl AS WSTRINGZ _                         ' __in LPCWSTR pwzUrl
   , BYVAL ParseAction AS DWORD _                       ' __in PARSEACTION ParseAction
   , BYVAL dwParseFlags AS DWORD _                      ' __in DWORD dwParseFlags
   , BYREF pwzResult AS WSTRINGZ _                      ' __out LPWSTR pwzResult
   , BYVAL cchResult AS DWORD _                         ' __in DWORD cchResult
   , BYREF pcchResult AS DWORD _                        ' __out DWORD *pcchResult
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CombineUrl ( _                                ' VTable offset = 16
     BYREF pwzBaseUrl AS WSTRINGZ _                     ' __in LPCWSTR pwzBaseUrl
   , BYREF pwzRelativeUrl AS WSTRINGZ _                 ' __in LPCWSTR pwzRelativeUrl
   , BYVAL dwCombineFlags AS DWORD _                    ' __in DWORD dwCombineFlags
   , BYREF pwzResult AS WSTRINGZ _                      ' __out LPWSTR pwzResult
   , BYVAL cchResult AS DWORD _                         ' __in DWORD cchResult
   , BYREF pcchResult AS DWORD _                        ' __out DWORD *pcchResult
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareUrl ( _                                ' VTable offset = 20
     BYREF pwzUrl1 AS WSTRINGZ _                        ' __in LPCWSTR pwzUrl1
   , BYREF pwzUrl2 AS WSTRINGZ _                        ' __in LPCWSTR pwzUrl2
   , BYVAL dwCompareFlags AS DWORD _                    ' __in DWORD dwCompareFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryInfo ( _                                 ' VTable offset = 24
     BYREF pwzUrl AS WSTRINGZ _                         ' __in LPCWSTR pwzUrl
   , BYVAL OueryOption AS DWORD _                       ' __in QUERYOPTION OueryOption
   , BYVAL dwQueryFlags AS DWORD _                      ' __in DWORD dwQueryFlags
   , BYVAL pBuffer AS DWORD _                           ' __in_out LPVOID pBuffer
   , BYVAL cbBuffer AS DWORD _                          ' __in DWORD cbBuffer
   , BYREF pcbBuf AS DWORD _                            ' __in_out DWORD *pcbBuf
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInternetProtocolInfo_INTERFACE_DEFINED__ */


'#ifndef URLMON_STRICT
'// PARSE_ENCODE was misnamed and is deprecated for PARSE_UNESCAPE
'#define PARSE_ENCODE PARSE_ENCODE_IS_UNESCAPE
'// PARSE_DECODE was misnamed and is deprecated for PARSE_ESCAPE
'#define PARSE_DECODE PARSE_DECODE_IS_ESCAPE
'#endif //!URLMON_STRICT
'#endif
'#define IOInet               IInternet
'#define IOInetBindInfo       IInternetBindInfo
'#define IOInetBindInfoEx     IInternetBindInfoEx
'#define IOInetProtocolRoot   IInternetProtocolRoot
'#define IOInetProtocol       IInternetProtocol
'#if (_WIN32_IE >= _WIN32_IE_IE70)
'#define IOInetProtocolEx     IInternetProtocolEx
'#endif //(_WIN32_IE >= _WIN32_IE_IE70)
'#define IOInetProtocolSink   IInternetProtocolSink
'#define IOInetProtocolInfo   IInternetProtocolInfo
'#define IOInetSession        IInternetSession
'#define IOInetPriority       IInternetPriority
'#define IOInetThreadSwitch   IInternetThreadSwitch
'#define IOInetProtocolSinkStackable   IInternetProtocolSinkStackable
'#define LPOINET              LPIINTERNET
'#define LPOINETPROTOCOLINFO  LPIINTERNETPROTOCOLINFO
'#define LPOINETBINDINFO      LPIINTERNETBINDINFO
'#define LPOINETPROTOCOLROOT  LPIINTERNETPROTOCOLROOT
'#define LPOINETPROTOCOL      LPIINTERNETPROTOCOL
'#if (_WIN32_IE >= _WIN32_IE_IE70)
'#define LPOINETPROTOCOLEX    LPIINTERNETPROTOCOLEX
'#endif //(_WIN32_IE >= _WIN32_IE_IE70)
'#define LPOINETPROTOCOLSINK  LPIINTERNETPROTOCOLSINK
'#define LPOINETSESSION       LPIINTERNETSESSION
'#define LPOINETTHREADSWITCH  LPIINTERNETTHREADSWITCH
'#define LPOINETPRIORITY      LPIINTERNETPRIORITY
'#define LPOINETPROTOCOLINFO  LPIINTERNETPROTOCOLINFO
'#define LPOINETPROTOCOLSINKSTACKABLE  LPIINTERNETPROTOCOLSINKSTACKABLE
'#define IID_IOInet               IID_IInternet
'#define IID_IOInetBindInfo       IID_IInternetBindInfo
'#define IID_IOInetBindInfoEx     IID_IInternetBindInfoEx
'#define IID_IOInetProtocolRoot   IID_IInternetProtocolRoot
'#define IID_IOInetProtocol       IID_IInternetProtocol
'#if (_WIN32_IE >= _WIN32_IE_IE70)
'#define IID_IOInetProtocolEx     IID_IInternetProtocolEx
'#endif //(_WIN32_IE >= _WIN32_IE_IE70)
'#define IID_IOInetProtocolSink   IID_IInternetProtocolSink
'#define IID_IOInetProtocolInfo   IID_IInternetProtocolInfo
'#define IID_IOInetSession        IID_IInternetSession
'#define IID_IOInetPriority       IID_IInternetPriority
'#define IID_IOInetThreadSwitch   IID_IInternetThreadSwitch
'#define IID_IOInetProtocolSinkStackable   IID_IInternetProtocolSinkStackable


DECLARE FUNCTION CoInternetParseUrl IMPORT "URLMON.DLL" ALIAS "CoInternetParseUrl" ( _
   BYREF pwzUrl AS WSTRINGZ _                           ' __in LPCWSTR pwzUrl
 , BYVAL ParseAction AS DWORD _                         ' __in PARSEACTION ParseAction
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pszResult AS WSTRINGZ _                        ' __in LPWSTR pszResult
 , BYVAL cchResult AS DWORD _                           ' __in DWORD cchResult
 , BYREF pcchResult AS DWORD _                          ' __out DWORD *pcchResult
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' HRESULT

'#if (_WIN32_IE >= _WIN32_IE_IE70)
DECLARE FUNCTION CoInternetParseIUri IMPORT "URLMON.DLL" ALIAS "CoInternetParseIUri" ( _
   BYVAL pIUri AS IUri _                                ' __in IUri   *pIUri
 , BYREF ParseAction AS DWORD _                         ' __in PARSEACTION  ParseAction
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD        dwFlags
 , BYREF pwzResult AS WSTRINGZ _                        ' __in LPWSTR       pwzResult
 , BYVAL cchResult AS DWORD _                           ' __in DWORD        cchResult
 , BYREF pcchResult AS DWORD _                          ' __out DWORD *pcchResult
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD_PTR    dwReserved
 ) AS LONG                                              ' HRESULT
'#endif //(_WIN32_IE >= _WIN32_IE_IE70)

DECLARE FUNCTION CoInternetCombineUrl IMPORT "URLMON.DLL" ALIAS "CoInternetCombineUrl" ( _
   BYREF pwzBaseUrl AS WSTRINGZ _                       ' __in LPCWSTR pwzBaseUrl
 , BYREF pwzRelativeUrl AS WSTRINGZ _                   ' __in LPCWSTR pwzRelativeUrl
 , BYVAL dwCombineFlags AS DWORD _                      ' __in DWORD dwCombineFlags
 , BYREF pszResult AS WSTRINGZ _                        ' __in LPWSTR pszResult
 , BYVAL cchResult AS DWORD _                           ' __in DWORD cchResult
 , BYREF pcchResult AS DWORD _                          ' __out DWORD *pcchResult
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' HRESULT

'#if (_WIN32_IE >= _WIN32_IE_IE70)
DECLARE FUNCTION CoInternetCombineUrlEx IMPORT "URLMON.DLL" ALIAS "CoInternetCombineUrlEx" ( _
   BYVAL pBaseUri AS IUri _                             ' __in_opt IUri *pBaseUri
 , BYREF pwzRelativeUrl AS WSTRINGZ _                   ' __in_opt LPCWSTR pwzRelativeUrl
 , BYVAL dwCombineFlags AS DWORD _                      ' __in DWORD dwCombineFlags
 , BYREF ppCombinedUri AS IUri _                        ' __out IUri **ppCombinedUri
 , BYVAL dwReserved AS DWORD _                          ' __in_opt DWORD_PTR dwReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoInternetCombineIUri IMPORT "URLMON.DLL" ALIAS "CoInternetCombineIUri" ( _
   BYVAL pBaseUri AS IUri _                             ' __in IUri *pBaseUri
 , BYVAL pRelativeUri AS IUri _                         ' __in IUri *pRelativeUri
 , BYVAL dwCombineFlags AS DWORD _                      ' __in DWORD dwCombineFlags
 , BYREF ppCombinedUri AS IUri _                        ' __out IUri **ppCombinedUri
 , BYVAL dwReserved AS DWORD _                          ' __in_opt DWORD_PTR dwReserved
 ) AS LONG                                              ' HRESULT
'#endif //(_WIN32_IE >= _WIN32_IE_IE70)

DECLARE FUNCTION CoInternetCompareUrl IMPORT "URLMON.DLL" ALIAS "CoInternetCompareUrl" ( _
   BYREF pwzUrl1 AS WSTRINGZ _                          ' __in LPCWSTR pwzUrl1
 , BYREF pwzUrl2 AS WSTRINGZ _                          ' __in LPCWSTR pwzUrl2
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoInternetGetProtocolFlags IMPORT "URLMON.DLL" ALIAS "CoInternetGetProtocolFlags" ( _
   BYREF pwzUrl AS WSTRINGZ _                           ' __in LPCWSTR pwzUrl
 , BYREF pdwFlags AS DWORD _                            ' __out DWORD *pdwFlags
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoInternetQueryInfo IMPORT "URLMON.DLL" ALIAS "CoInternetQueryInfo" ( _
   BYREF pwzUrl AS WSTRINGZ _                           ' __in LPCWSTR pwzUrl
 , BYVAL QueryOptions AS DWORD _                        ' __in QUERYOPTION QueryOptions
 , BYVAL dwQueryFlags AS DWORD _                        ' __in DWORD dwQueryFlags
 , BYVAL pvBuffer AS DWORD _                            ' __in LPVOID pvBuffer
 , BYVAL cbBuffer AS DWORD _                            ' __in DWORD cbBuffer
 , BYREF pcbBuffer AS DWORD _                           ' __out DWORD *pcbBuffer
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoInternetGetSession IMPORT "URLMON.DLL" ALIAS "CoInternetGetSession" ( _
   BYVAL dwSessionMode AS DWORD _                       ' __in DWORD dwSessionMode
 , BYREF ppIInternetSession AS IInternetSession _       ' __out IInternetSession **ppIInternetSession
 , BYVAL dwReserved AS DWORD _                          ' __in dwReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoInternetGetSecurityUrl IMPORT "URLMON.DLL" ALIAS "CoInternetGetSecurityUrl" ( _
   BYREF pwzUrl AS WSTRINGZ _                           ' __in LPCWSTR pwzUrl
 , BYREF ppwzSecUrl AS DWORD _                          ' __out LPWSTR *ppwzSecUrl
 , BYVAL psuAction AS DWORD _                           ' __in PSUACTION psuAction
 , BYVAL dwReserved AS DWORD _                          ' __in dwReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION AsyncInstallDistributionUnit IMPORT "URLMON.DLL" ALIAS "AsyncInstallDistributionUnit" ( _
   BYREF szDistUnit AS WSTRINGZ _                       ' __in LPCWSTR szDistUnit
 , BYREF szTYPE AS WSTRINGZ _                           ' __in LPCWSTR szTYPE
 , BYREF szExt AS WSTRINGZ _                            ' __in LPCWSTR szExt
 , BYVAL dwFileVersionMS AS DWORD _                     ' __in DWORD dwFileVersionMS
 , BYVAL dwFileVersionLS AS DWORD _                     ' __in DWORD dwFileVersionLS
 , BYREF szURL AS WSTRINGZ _                            ' __in LPCWSTR szURL
 , BYVAL pbc AS IBindCtx _                              ' __in IBindCtx *pbc
 , BYVAL pvReserved AS DWORD _                          ' __in LPVOID pvReserved
 , BYVAL flags AS DWORD _                               ' __in DWORD flags
 ) AS LONG                                              ' HRESULT

'#if (_WIN32_IE >= _WIN32_IE_IE70)
DECLARE FUNCTION CoInternetGetSecurityUrlEx IMPORT "URLMON.DLL" ALIAS "CoInternetGetSecurityUrlEx" ( _
   BYVAL pUri AS IUri _                                 ' __in IUri         *pUri
 , BYREF ppSecUri AS IUri _                             ' __out IUri **ppSecUri
 , BYVAL psuAction AS LONG _                            ' __in PSUACTION psuAction
 , BYVAL dwReserved AS DWORD _                          ' __reserved  DWORD_PTR dwReserved
 ) AS LONG                                              ' HRESULT
'#endif //(_WIN32_IE >= _WIN32_IE_IE70)

'#if (_WIN32_IE >= _WIN32_IE_IE60SP2)
'#ifndef _INTERNETFEATURELIST_DEFINED
'#define _INTERNETFEATURELIST_DEFINED
' INTERNETFEATURELIST enum
%FEATURE_OBJECT_CACHING                 = 0
%FEATURE_ZONE_ELEVATION                 = %FEATURE_OBJECT_CACHING                 + 1
%FEATURE_MIME_HANDLING                  = %FEATURE_ZONE_ELEVATION                 + 1
%FEATURE_MIME_SNIFFING                  = %FEATURE_MIME_HANDLING                  + 1
%FEATURE_WINDOW_RESTRICTIONS            = %FEATURE_MIME_SNIFFING                  + 1
%FEATURE_WEBOC_POPUPMANAGEMENT          = %FEATURE_WINDOW_RESTRICTIONS            + 1
%FEATURE_BEHAVIORS                      = %FEATURE_WEBOC_POPUPMANAGEMENT          + 1
%FEATURE_DISABLE_MK_PROTOCOL            = %FEATURE_BEHAVIORS                      + 1
%FEATURE_LOCALMACHINE_LOCKDOWN          = %FEATURE_DISABLE_MK_PROTOCOL            + 1
%FEATURE_SECURITYBAND                   = %FEATURE_LOCALMACHINE_LOCKDOWN          + 1
%FEATURE_RESTRICT_ACTIVEXINSTALL        = %FEATURE_SECURITYBAND                   + 1
%FEATURE_VALIDATE_NAVIGATE_URL          = %FEATURE_RESTRICT_ACTIVEXINSTALL        + 1
%FEATURE_RESTRICT_FILEDOWNLOAD          = %FEATURE_VALIDATE_NAVIGATE_URL          + 1
%FEATURE_ADDON_MANAGEMENT               = %FEATURE_RESTRICT_FILEDOWNLOAD          + 1
%FEATURE_PROTOCOL_LOCKDOWN              = %FEATURE_ADDON_MANAGEMENT               + 1
%FEATURE_HTTP_USERNAME_PASSWORD_DISABLE = %FEATURE_PROTOCOL_LOCKDOWN              + 1
%FEATURE_SAFE_BINDTOOBJECT              = %FEATURE_HTTP_USERNAME_PASSWORD_DISABLE + 1
%FEATURE_UNC_SAVEDFILECHECK             = %FEATURE_SAFE_BINDTOOBJECT              + 1
%FEATURE_GET_URL_DOM_FILEPATH_UNENCODED = %FEATURE_UNC_SAVEDFILECHECK             + 1
%FEATURE_TABBED_BROWSING                = %FEATURE_GET_URL_DOM_FILEPATH_UNENCODED + 1
%FEATURE_SSLUX                          = %FEATURE_TABBED_BROWSING                + 1
%FEATURE_DISABLE_NAVIGATION_SOUNDS      = %FEATURE_SSLUX                          + 1
%FEATURE_DISABLE_LEGACY_COMPRESSION     = %FEATURE_DISABLE_NAVIGATION_SOUNDS      + 1
%FEATURE_FORCE_ADDR_AND_STATUS          = %FEATURE_DISABLE_LEGACY_COMPRESSION     + 1
%FEATURE_XMLHTTP                        = %FEATURE_FORCE_ADDR_AND_STATUS          + 1
%FEATURE_DISABLE_TELNET_PROTOCOL        = %FEATURE_XMLHTTP                        + 1
%FEATURE_FEEDS                          = %FEATURE_DISABLE_TELNET_PROTOCOL        + 1
%FEATURE_BLOCK_INPUT_PROMPTS            = %FEATURE_FEEDS                          + 1
%FEATURE_ENTRY_COUNT                    = %FEATURE_BLOCK_INPUT_PROMPTS            + 1

'// CoInternetSetFeatureEnabled can be used to set/reset features.
'// The following flags control where the feature is set

%SET_FEATURE_ON_THREAD                = &H00000001???
%SET_FEATURE_ON_PROCESS               = &H00000002???
%SET_FEATURE_IN_REGISTRY              = &H00000004???
%SET_FEATURE_ON_THREAD_LOCALMACHINE   = &H00000008???
%SET_FEATURE_ON_THREAD_INTRANET       = &H00000010???
%SET_FEATURE_ON_THREAD_TRUSTED        = &H00000020???
%SET_FEATURE_ON_THREAD_INTERNET       = &H00000040???
%SET_FEATURE_ON_THREAD_RESTRICTED     = &H00000080???

'// CoInternetIsFeatureEnabled can be used to get features.
'// The following flags control where the feature is obtained from
'// default is from process

%GET_FEATURE_FROM_THREAD              = &H00000001???
%GET_FEATURE_FROM_PROCESS             = &H00000002???
%GET_FEATURE_FROM_REGISTRY            = &H00000004???
%GET_FEATURE_FROM_THREAD_LOCALMACHINE = &H00000008???
%GET_FEATURE_FROM_THREAD_INTRANET     = &H00000010???
%GET_FEATURE_FROM_THREAD_TRUSTED      = &H00000020???
%GET_FEATURE_FROM_THREAD_INTERNET     = &H00000040???
%GET_FEATURE_FROM_THREAD_RESTRICTED   = &H00000080???
'#endif

DECLARE FUNCTION CoInternetSetFeatureEnabled IMPORT "URLMON.DLL" ALIAS "CoInternetSetFeatureEnabled" ( _
   BYVAL FeatureEntry AS DWORD _                        ' __in INTERNETFEATURELIST FeatureEntry
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL fEnable AS DWORD _                             ' __in BOOL fEnable
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoInternetIsFeatureEnabled IMPORT "URLMON.DLL" ALIAS "CoInternetIsFeatureEnabled" ( _
   BYVAL FeatureEntry AS DWORD _                        ' __in INTERNETFEATURELIST FeatureEntry
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoInternetIsFeatureEnabledForUrl IMPORT "URLMON.DLL" ALIAS "CoInternetIsFeatureEnabledForUrl" ( _
   BYVAL FeatureEntry AS DWORD _                        ' __in INTERNETFEATURELIST FeatureEntry
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF szURL AS WSTRINGZ _                            ' __in LPCWSTR szURL
 , BYVAL pSecMgr AS IInternetSecurityManager _          ' __in IInternetSecurityManager *pSecMgr
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CoInternetIsFeatureZoneElevationEnabled IMPORT "URLMON.DLL" ALIAS "CoInternetIsFeatureZoneElevationEnabled" ( _
   BYREF szFromURL AS WSTRINGZ _                        ' __in LPCWSTR szFromURL
 , BYREF szToURL AS WSTRINGZ _                          ' __in LPCWSTR szToURL
 , BYVAL pSecMgr AS IInternetSecurityManager _          ' __in IInternetSecurityManager *pSecMgr
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT
'#endif //(_WIN32_IE >= _WIN32_IE_IE60SP2)

DECLARE FUNCTION CopyStgMedium IMPORT "URLMON.DLL" ALIAS "CopyStgMedium" ( _
   BYREF pcstgmedSrc AS STGMEDIUM _                     ' __in const STGMEDIUM * pcstgmedSrc
 , BYREF pstgmedDest AS STGMEDIUM _                     ' __in STGMEDIUM * pstgmedDest
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CopyBindInfo IMPORT "URLMON.DLL" ALIAS "CopyBindInfo" ( _
   BYREF pcbiSrc AS BINDINFO _                          ' __in const BINDINFO * pcbiSrc
 , BYREF pbiDest AS BINDINFO _                          ' __in BINDINFO * pbiDest
 ) AS LONG                                              ' HRESULT

DECLARE SUB ReleaseBindInfo IMPORT "URLMON.DLL" ALIAS "ReleaseBindInfo" ( _
   BYREF pbindinfo AS BINDINFO _                        ' __in BINDINFO * pbindinfo
 )                                                      ' void

%INET_E_USE_DEFAULT_PROTOCOLHANDLER = &H800C0011???
%INET_E_USE_DEFAULT_SETTING         = &H800C0012???
%INET_E_DEFAULT_ACTION              = %INET_E_USE_DEFAULT_PROTOCOLHANDLER
%INET_E_QUERYOPTION_UNKNOWN         = &H800C0013???
%INET_E_REDIRECTING                 = &H800C0014???

'#define OInetParseUrl               CoInternetParseUrl
'#define OInetCombineUrl             CoInternetCombineUrl
'#if (_WIN32_IE >= _WIN32_IE_IE70)
'#define OInetCombineUrlEx           CoInternetCombineUrlEx
'#define OInetCombineIUri            CoInternetCombineIUri
'#endif //(_WIN32_IE >= _WIN32_IE_IE70)
'#define OInetCompareUrl             CoInternetCompareUrl
'#define OInetQueryInfo              CoInternetQueryInfo
'#define OInetGetSession             CoInternetGetSession

#ENDIF   ' // !_URLMON_NO_ASYNC_PLUGABLE_PROTOCOLS_

'//
'// Static Protocol flags
'//
%PROTOCOLFLAG_NO_PICS_CHECK        = &H00000001???

'// Creates the security manager object. The first argument is the Service provider
'// to allow for delegation

DECLARE FUNCTION CoInternetCreateSecurityManager IMPORT "URLMON.DLL" ALIAS "CoInternetCreateSecurityManager" ( _
   BYVAL pSP AS IServiceProvider _                      ' __in IServiceProvider *pSP
 , BYREF ppSM AS IInternetSecurityManager _             ' __out IInternetSecurityManager **ppSM
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CoInternetCreateZoneManager IMPORT "URLMON.DLL" ALIAS "CoInternetCreateZoneManager" ( _
   BYVAL pSP AS IServiceProvider _                      ' __in IServiceProvider *pSP
 , BYREF ppZM AS IInternetZoneManager _                 ' __out IInternetZoneManager **ppZM
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' BOOL

'// Security manager CLSID's
'EXTERN_C const IID CLSID_InternetZoneManager;
'EXTERN_C const IID CLSID_PersistentZoneIdentifier;
$CLSID_InternetZoneManager      = GUID$("{7B8A2D95-0AC9-11D1-896C-00C04FB6BFC4}")
$CLSID_SBS_InternetZoneManager  = $CLSID_InternetZoneManager
'#if (_WIN32_IE >= _WIN32_IE_IE60SP2)
$CLSID_PersistentZoneIdentifier = GUID$("{0968E258-16C7-4DBA-AA86-462DD61E31A3}")
'#endif //(_WIN32_IE >= _WIN32_IE_IE60SP2)


' ########################################################################################
' IInternetSecurityMgrSite interface
' IID = 79EAC9ED-BAF9-11CE-8C82-00AA004BA90B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInternetSecurityMgrSite_INTERFACE_DEFINED)
    %IInternetSecurityMgrSite_INTERFACE_DEFINED = 1

$IID_IInternetSecurityMgrSite = GUID$("{79EAC9ED-BAF9-11CE-8C82-00AA004BA90B}")

INTERFACE IInternetSecurityMgrSite $IID_IInternetSecurityMgrSite

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetWindow ( _                                 ' VTable offset = 12
     BYREF phwnd AS DWORD _                             ' __out HWND *phwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnableModeless ( _                            ' VTable offset = 16
     BYVAL fEnable AS LONG _                            ' __in BOOL fEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInternetSecurityMgrSite_INTERFACE_DEFINED__ */


' ########################################################################################
' IInternetSecurityManager interface
' IID = 79EAC9EE-BAF9-11CE-8C82-00AA004BA90B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInternetSecurityManager_INTERFACE_DEFINED)
    %IInternetSecurityManager_INTERFACE_DEFINED = 1

$CLSID_InternetSecurityManager     = GUID$("{7B8A2D94-0AC9-11D1-896C-00C04FB6BFC4}")
$CLSID_SBS_InternetSecurityManager = $CLSID_InternetSecurityManager
$IID_IInternetSecurityManager      = GUID$("{79EAC9EE-BAF9-11CE-8C82-00AA004BA90B}")
$SID_SInternetSecurityManager      = $IID_IInternetSecurityManager

%MUTZ_NOSAVEDFILECHECK        = &H00000001???  ' // don't check file: for saved file comment
%MUTZ_ISFILE                  = &H00000002???  ' // Assume URL if File, url does not need file: ' //
%MUTZ_ACCEPT_WILDCARD_SCHEME  = &H00000080???  ' // Accept a wildcard scheme
%MUTZ_ENFORCERESTRICTED       = &H00000100???  ' // enforce restricted zone independent of URL
%MUTZ_RESERVED                = &H00000200???  ' // This is same as PUAF_NOSAVEDFILECHECK. However we already have MUTZ_NOSAVEDFILECHECK for this.
%MUTZ_REQUIRESAVEDFILECHECK   = &H00000400???  ' // always check the file for MOTW (overriding FEATURE_UNC_SAVEDFILECHECK)
%MUTZ_DONT_UNESCAPE           = &H00000800???  ' // Do not unescape the url
%MUTZ_DONT_USE_CACHE          = &H00001000???  ' // Do not check the cache
%MUTZ_FORCE_INTRANET_FLAGS    = &H00002000???  ' // Force the intranet flags to be active
%MUTZ_IGNORE_ZONE_MAPPINGS    = &H00004000???  ' // Don't look up the Zone Mappings

'// MapUrlToZone returns the zone index given a URL
%MAX_SIZE_SECURITY_ID = 512 ' // bytes

' PUAF enum
%PUAF_DEFAULT                      = 0
%PUAF_NOUI                         = &H1???
%PUAF_ISFILE                       = &H2???
%PUAF_WARN_IF_DENIED               = &H4???
%PUAF_FORCEUI_FOREGROUND           = &H8???
%PUAF_CHECK_TIFS                   = &H10???
%PUAF_DONTCHECKBOXINDIALOG         = &H20???
%PUAF_TRUSTED                      = &H40???
%PUAF_ACCEPT_WILDCARD_SCHEME       = &H80???
%PUAF_ENFORCERESTRICTED            = &H100???
%PUAF_NOSAVEDFILECHECK             = &H200???
%PUAF_REQUIRESAVEDFILECHECK        = &H400???
%PUAF_DONT_USE_CACHE               = &H1000???
%PUAF_RESERVED1                    = &H2000???
%PUAF_RESERVED2                    = &H4000???
%PUAF_LMZ_UNLOCKED                 = &H10000???
%PUAF_LMZ_LOCKED                   = &H20000???
%PUAF_DEFAULTZONEPOL               = &H40000???
%PUAF_NPL_USE_LOCKED_IF_RESTRICTED = &H80000???
%PUAF_NOUIIFLOCKED                 = &H100000???
%PUAF_DRAGPROTOCOLCHECK            = &H200000???

' PUAFOUT enum
%PUAFOUT_DEFAULT          = 0
%PUAFOUT_ISLOCKZONEPOLICY = &H1

'// This is the wrapper function that most clients will use.
'// It figures out the current Policy for the passed in Action,
'// and puts up UI if the current Policy indicates that the user
'// should be queried. It returns back the Policy which the caller
'// will use to determine if the action should be allowed
'// This is the wrapper function to conveniently read a custom policy.

' SZM_FLAGS enum
%SZM_CREATE   = 0
%SZM_DELETE   = &H1

'// SetZoneMapping
'//    lpszPattern: string denoting a URL pattern
'//        Examples of valid patterns:
'//            *://*.msn.com
'//            http://*.sony.co.jp
'//            *://et.msn.com
'//            ftp://157.54.23.41/
'//            https://localsvr
'//            file:\localsvr\share
'//            *://157.54.100-200.*
'//        Examples of invalid patterns:
'//            http://*.lcs.mit.edu
'//            ftp://*
'//    dwFlags: SZM_FLAGS values


INTERFACE IInternetSecurityManager $IID_IInternetSecurityManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetSecuritySite ( _                           ' VTable offset = 12
     BYVAL pSite AS IInternetSecurityMgrSite _          ' __in IInternetSecurityMgrSite *pSite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSecuritySite ( _                           ' VTable offset = 16
     BYREF ppSite AS IInternetSecurityMgrSite _         ' __out IInternetSecurityMgrSite **ppSite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MapUrlToZone ( _                              ' VTable offset = 20
     BYREF pwszUrl AS WSTRINGZ _                        ' __in LPCWSTR pwszUrl
   , BYREF pdwZone AS DWORD _                           ' __out DWORD *pdwZone
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSecurityId ( _                             ' VTable offset = 24
     BYREF pwszUrl AS WSTRINGZ _                        ' __in LPCWSTR pwszUrl
   , BYVAL pbSecurityId AS BYTE PTR _                   ' __out BYTE *pbSecurityId
   , BYREF pcbSecurityId AS DWORD _                     ' __in_out DWORD *pcbSecurityId
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD_PTR dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessUrlAction ( _                          ' VTable offset = 28
     BYREF pwszUrl AS WSTRINGZ _                        ' __in LPCWSTR pwszUrl
   , BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYVAL pPolicy AS BYTE PTR _                        ' __out BYTE *pPolicy
   , BYVAL cbPolicy AS DWORD _                          ' __in DWORD cbPolicy
   , BYVAL pContext AS BYTE PTR _                       ' __in BYTE *pContext
   , BYVAL cbContext AS DWORD _                         ' __in DWORD cbContext
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryCustomPolicy ( _                         ' VTable offset = 32
     BYREF pwszUrl AS WSTRINGZ _                        ' __in LPCWSTR pwszUrl
   , BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF ppPolicy AS DWORD _                          ' __out BYTE **ppPolicy
   , BYREF pcbPolicy AS DWORD _                         ' __out DWORD *pcbPolicy
   , BYVAL pContext AS BYTE PTR _                       ' __in BYTE *pContext
   , BYVAL cbContext AS DWORD _                         ' __in DWORD cbContext
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetZoneMapping ( _                            ' VTable offset = 36
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYREF lpszPattern AS WSTRINGZ _                    ' __in LPCWSTR lpszPattern
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetZoneMappings ( _                           ' VTable offset = 40
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYREF ppenumString AS IEnumString _                ' __out IEnumString **ppenumString
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInternetSecurityManager_INTERFACE_DEFINED__ */

' ########################################################################################
' IInternetSecurityManagerEx interface
' IID = F164EDF1-CC7C-4f0d-9A94-34222625C393
' Inherited interface = IInternetSecurityManager
' ########################################################################################

#IF NOT %DEF(%IInternetSecurityManagerEx_INTERFACE_DEFINED)
    %IInternetSecurityManagerEx_INTERFACE_DEFINED = 1

'/* interface IInternetSecurityManagerEx */
'/* [object][unique][helpstring][uuid] */

'// This is the wrapper function that most clients will use.
'// It figures out the current Policy for the passed in Action,
'// and puts up UI if the current Policy indicates that the user
'// should be queried. It returns back the Policy which the caller
'// will use to determine if the action should be allowed

$IID_IInternetSecurityManagerEx = GUID$("{F164EDF1-CC7C-4f0d-9A94-34222625C393}")
$SID_SInternetSecurityManagerEx = $IID_IInternetSecurityManagerEx

INTERFACE IInternetSecurityManagerEx $IID_IInternetSecurityManagerEx

   INHERIT IUnknown

   ' =====================================================================================
   ' IInternetSecurityManager Methods
   ' =====================================================================================
   METHOD SetSecuritySite ( _                           ' VTable offset = 12
     BYVAL pSite AS IInternetSecurityMgrSite _          ' __in IInternetSecurityMgrSite *pSite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSecuritySite ( _                           ' VTable offset = 16
     BYREF ppSite AS IInternetSecurityMgrSite _         ' __out IInternetSecurityMgrSite **ppSite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MapUrlToZone ( _                              ' VTable offset = 20
     BYREF pwszUrl AS WSTRINGZ _                        ' __in LPCWSTR pwszUrl
   , BYREF pdwZone AS DWORD _                           ' __out DWORD *pdwZone
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSecurityId ( _                             ' VTable offset = 24
     BYREF pwszUrl AS WSTRINGZ _                        ' __in LPCWSTR pwszUrl
   , BYVAL pbSecurityId AS BYTE PTR _                   ' __out BYTE *pbSecurityId
   , BYREF pcbSecurityId AS DWORD _                     ' __in_out DWORD *pcbSecurityId
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD_PTR dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessUrlAction ( _                          ' VTable offset = 28
     BYREF pwszUrl AS WSTRINGZ _                        ' __in LPCWSTR pwszUrl
   , BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYVAL pPolicy AS BYTE PTR _                        ' __out BYTE *pPolicy
   , BYVAL cbPolicy AS DWORD _                          ' __in DWORD cbPolicy
   , BYVAL pContext AS BYTE PTR _                       ' __in BYTE *pContext
   , BYVAL cbContext AS DWORD _                         ' __in DWORD cbContext
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryCustomPolicy ( _                         ' VTable offset = 32
     BYREF pwszUrl AS WSTRINGZ _                        ' __in LPCWSTR pwszUrl
   , BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF ppPolicy AS DWORD _                          ' __out BYTE **ppPolicy
   , BYREF pcbPolicy AS DWORD _                         ' __out DWORD *pcbPolicy
   , BYVAL pContext AS BYTE PTR _                       ' __in BYTE *pContext
   , BYVAL cbContext AS DWORD _                         ' __in DWORD cbContext
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetZoneMapping ( _                            ' VTable offset = 36
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYREF lpszPattern AS WSTRINGZ _                    ' __in LPCWSTR lpszPattern
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetZoneMappings ( _                           ' VTable offset = 40
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYREF ppenumString AS IEnumString _                ' __out IEnumString **ppenumString
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IInternetSecurityManagerEx Methods
   ' =====================================================================================
   METHOD ProcessUrlActionEx ( _                        ' VTable offset = 44
     BYREF pwszUrl AS WSTRINGZ _                        ' __in LPCWSTR pwszUrl
   , BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYVAL pPolicy AS BYTE PTR _                        ' __out BYTE *pPolicy
   , BYVAL cbPolicy AS DWORD _                          ' __in DWORD cbPolicy
   , BYVAL pContext AS BYTE PTR _                       ' __in BYTE *pContext
   , BYVAL cbContext AS DWORD _                         ' __in DWORD cbContext
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   , BYREF pdwOutFlags AS DWORD _                       ' __out DWORD *pdwOutFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInternetSecurityManagerEx_INTERFACE_DEFINED__ */

' ########################################################################################
' IInternetSecurityManagerEx2 interface
' IID = F164EDF1-CC7C-4f0d-9A94-34222625C393
' Inherited interface = IInternetSecurityManagerEx
' ########################################################################################

#IF NOT %DEF(%IInternetSecurityManagerEx2_INTERFACE_DEFINED)
    %IInternetSecurityManagerEx2_INTERFACE_DEFINED = 1

$IID_IInternetSecurityManagerEx2 = GUID$("{F164EDF1-CC7C-4f0d-9A94-34222625C393}")
$SID_SInternetSecurityManagerEx2 = $IID_IInternetSecurityManagerEx2

INTERFACE IInternetSecurityManagerEx2 $IID_IInternetSecurityManagerEx2

   INHERIT IUnknown

   ' =====================================================================================
   ' IInternetSecurityManager Methods
   ' =====================================================================================
   METHOD SetSecuritySite ( _                           ' VTable offset = 12
     BYVAL pSite AS IInternetSecurityMgrSite _          ' __in IInternetSecurityMgrSite *pSite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSecuritySite ( _                           ' VTable offset = 16
     BYREF ppSite AS IInternetSecurityMgrSite _         ' __out IInternetSecurityMgrSite **ppSite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MapUrlToZone ( _                              ' VTable offset = 20
     BYREF pwszUrl AS WSTRINGZ _                        ' __in LPCWSTR pwszUrl
   , BYREF pdwZone AS DWORD _                           ' __out DWORD *pdwZone
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSecurityId ( _                             ' VTable offset = 24
     BYREF pwszUrl AS WSTRINGZ _                        ' __in LPCWSTR pwszUrl
   , BYVAL pbSecurityId AS BYTE PTR _                   ' __out BYTE *pbSecurityId
   , BYREF pcbSecurityId AS DWORD _                     ' __in_out DWORD *pcbSecurityId
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD_PTR dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessUrlAction ( _                          ' VTable offset = 28
     BYREF pwszUrl AS WSTRINGZ _                        ' __in LPCWSTR pwszUrl
   , BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYVAL pPolicy AS BYTE PTR _                        ' __out BYTE *pPolicy
   , BYVAL cbPolicy AS DWORD _                          ' __in DWORD cbPolicy
   , BYVAL pContext AS BYTE PTR _                       ' __in BYTE *pContext
   , BYVAL cbContext AS DWORD _                         ' __in DWORD cbContext
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryCustomPolicy ( _                         ' VTable offset = 32
     BYREF pwszUrl AS WSTRINGZ _                        ' __in LPCWSTR pwszUrl
   , BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF ppPolicy AS DWORD _                          ' __out BYTE **ppPolicy
   , BYREF pcbPolicy AS DWORD _                         ' __out DWORD *pcbPolicy
   , BYVAL pContext AS BYTE PTR _                       ' __in BYTE *pContext
   , BYVAL cbContext AS DWORD _                         ' __in DWORD cbContext
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetZoneMapping ( _                            ' VTable offset = 36
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYREF lpszPattern AS WSTRINGZ _                    ' __in LPCWSTR lpszPattern
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetZoneMappings ( _                           ' VTable offset = 40
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYREF ppenumString AS IEnumString _                ' __out IEnumString **ppenumString
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IInternetSecurityManagerEx Methods
   ' =====================================================================================
   METHOD ProcessUrlActionEx ( _                        ' VTable offset = 44
     BYREF pwszUrl AS WSTRINGZ _                        ' __in LPCWSTR pwszUrl
   , BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYVAL pPolicy AS BYTE PTR _                        ' __out BYTE *pPolicy
   , BYVAL cbPolicy AS DWORD _                          ' __in DWORD cbPolicy
   , BYVAL pContext AS BYTE PTR _                       ' __in BYTE *pContext
   , BYVAL cbContext AS DWORD _                         ' __in DWORD cbContext
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   , BYREF pdwOutFlags AS DWORD _                       ' __out DWORD *pdwOutFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IInternetSecurityManagerEx2 Methods
   ' =====================================================================================
   METHOD MapUrlToZoneEx2 ( _                           ' VTable offset = 48
     BYVAL pUri AS IUri _                               ' __in IUri *pUri
   , BYREF pdwZone AS DWORD _                           ' __out DWORD *pdwZone
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppwszMappedUrl AS DWORD _                    ' __out LPWSTR *ppwszMappedUrl
   , BYREF pdwOutFlags AS DWORD _                       ' __out DWORD *pdwOutFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessUrlActionEx2 ( _                       ' VTable offset = 52
     BYVAL pUri AS IUri _                               ' __in IUri *pUri
   , BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYVAL pPolicy AS BYTE PTR _                        ' __out BYTE *pPolicy
   , BYVAL cbPolicy AS DWORD _                          ' __in DWORD cbPolicy
   , BYVAL pContext AS BYTE PTR _                       ' __in BYTE *pContext
   , BYVAL cbContext AS DWORD _                         ' __in DWORD cbContext
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD_PTR dwReserved
   , BYREF pdwOutFlags AS DWORD _                       ' __out DWORD *pdwOutFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSecurityIdEx2 ( _                          ' VTable offset = 56
     BYVAL pUri AS IUri _                               ' __in IUri *pUri
   , BYVAL pbSecurityId AS BYTE PTR _                   ' __out BYTE *pbSecurityId
   , BYREF pcbSecurityId AS DWORD _                     ' __in_out DWORD *pcbSecurityId
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD_PTR dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryCustomPolicyEx2 ( _                      ' VTable offset = 60
     BYVAL pUri AS IUri _                               ' __in IUri *pUri
   , BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF ppPolicy AS DWORD _                          ' __out BYTE **ppPolicy
   , BYREF pcbPolicy AS DWORD _                         ' __out DWORD *pcbPolicy
   , BYVAL pContext AS BYTE PTR _                       ' __in BYTE *pContext
   , BYVAL cbContext AS DWORD _                         ' __in DWORD cbContext
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD_PTR dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInternetSecurityManagerEx2_INTERFACE_DEFINED__ */

' ########################################################################################
' IZoneIdentifier interface
' IID = CD45F185-1B21-48E2-967B-EAD743A8914E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IZoneIdentifier_INTERFACE_DEFINED)
    %IZoneIdentifier_INTERFACE_DEFINED = 1

$IID_IZoneIdentifier = GUID$("{CD45F185-1B21-48E2-967B-EAD743A8914E}")

INTERFACE IZoneIdentifier $IID_IZoneIdentifier

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetId ( _                                     ' VTable offset = 12
     BYREF pdwZone AS DWORD _                           ' __out DWORD *pdwZone
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetId ( _                                     ' VTable offset = 16
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Remove ( _                                    ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IZoneIdentifier_INTERFACE_DEFINED__ */

'//This is the interface MSHTML exposes to its clients
'//The clients need not pass in a URL to these functions
'//since MSHTML maintains the notion of the current URL

' ########################################################################################
' IInternetHostSecurityManager interface
' IID = 3AF280B6-CB3F-11D0-891E-00C04FB6BFC4
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInternetHostSecurityManager_INTERFACE_DEFINED)
    %IInternetHostSecurityManager_INTERFACE_DEFINED = 1

$IID_IInternetHostSecurityManager = GUID$("{3AF280B6-CB3F-11D0-891E-00C04FB6BFC4}")
$SID_SInternetHostSecurityManager = $IID_IInternetHostSecurityManager

INTERFACE IInternetHostSecurityManager $IID_IInternetHostSecurityManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSecurityId ( _                             ' VTable offset = 12
     BYVAL pbSecurityId AS BYTE PTR _                   ' __out BYTE *pbSecurityId
   , BYREF pcbSecurityId AS DWORD _                     ' __in_out DWORD *pcbSecurityId
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD_PTR dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessUrlAction ( _                          ' VTable offset = 16
     BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYVAL pPolicy AS BYTE PTR _                        ' __out BYTE *pPolicy
   , BYVAL cbPolicy AS DWORD _                          ' __in DWORD cbPolicy
   , BYVAL pContext AS BYTE PTR _                       ' __in BYTE *pContext
   , BYVAL cbContext AS DWORD _                         ' __in DWORD cbContext
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryCustomPolicy ( _                         ' VTable offset = 20
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF ppPolicy AS DWORD _                          ' __out BYTE **ppPolicy
   , BYREF pcbPolicy AS DWORD _                         ' __out DWORD *pcbPolicy
   , BYVAL pContext AS BYTE PTR _                       ' __in BYTE *pContext
   , BYVAL cbContext AS DWORD _                         ' __in DWORD cbContext
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInternetHostSecurityManager_INTERFACE_DEFINED__ */


'// The zone manager maintains policies for a set of standard actions.
'// These actions are identified by integral values (called action indexes)
'// specified below.

'// Minimum legal value for an action
%URLACTION_MIN                                          = &H00001000???

%URLACTION_DOWNLOAD_MIN                                 = &H00001000???
%URLACTION_DOWNLOAD_SIGNED_ACTIVEX                      = &H00001001???
%URLACTION_DOWNLOAD_UNSIGNED_ACTIVEX                    = &H00001004???
%URLACTION_DOWNLOAD_CURR_MAX                            = &H00001004???
%URLACTION_DOWNLOAD_MAX                                 = &H000011FF???

%URLACTION_ACTIVEX_MIN                                  = &H00001200???
%URLACTION_ACTIVEX_RUN                                  = &H00001200???
%URLPOLICY_ACTIVEX_CHECK_LIST                           = &H00010000???
%URLACTION_ACTIVEX_OVERRIDE_OBJECT_SAFETY               = &H00001201??? ' // aggregate next four
%URLACTION_ACTIVEX_OVERRIDE_DATA_SAFETY                 = &H00001202??? ' //
%URLACTION_ACTIVEX_OVERRIDE_SCRIPT_SAFETY               = &H00001203??? ' //
%URLACTION_SCRIPT_OVERRIDE_SAFETY                       = &H00001401??? ' //
%URLACTION_ACTIVEX_CONFIRM_NOOBJECTSAFETY               = &H00001204??? ' //
%URLACTION_ACTIVEX_TREATASUNTRUSTED                     = &H00001205???
%URLACTION_ACTIVEX_NO_WEBOC_SCRIPT                      = &H00001206???
%URLACTION_ACTIVEX_OVERRIDE_REPURPOSEDETECTION          = &H00001207???
%URLACTION_ACTIVEX_OVERRIDE_OPTIN                       = &H00001208???
%URLACTION_ACTIVEX_SCRIPTLET_RUN                        = &H00001209???
%URLACTION_ACTIVEX_DYNSRC_VIDEO_AND_ANIMATION           = &H0000120A???   ' //
%URLACTION_ACTIVEX_OVERRIDE_DOMAINLIST                  = &H0000120B???
%URLACTION_ACTIVEX_CURR_MAX                             = &H0000120B???
%URLACTION_ACTIVEX_MAX                                  = &H000013ff???

%URLACTION_SCRIPT_MIN                                   = &H00001400???
%URLACTION_SCRIPT_RUN                                   = &H00001400???
%URLACTION_SCRIPT_JAVA_USE                              = &H00001402???
%URLACTION_SCRIPT_SAFE_ACTIVEX                          = &H00001405???
%URLACTION_CROSS_DOMAIN_DATA                            = &H00001406???
%URLACTION_SCRIPT_PASTE                                 = &H00001407???
%URLACTION_ALLOW_XDOMAIN_SUBFRAME_RESIZE                = &H00001408???
%URLACTION_SCRIPT_XSSFILTER                             = &H00001409???
%URLACTION_SCRIPT_CURR_MAX                              = &H00001409???
%URLACTION_SCRIPT_MAX                                   = &H000015ff???

%URLACTION_HTML_MIN                                     = &H00001600???
%URLACTION_HTML_SUBMIT_FORMS                            = &H00001601??? ' // aggregate next two
%URLACTION_HTML_SUBMIT_FORMS_FROM                       = &H00001602??? ' //
%URLACTION_HTML_SUBMIT_FORMS_TO                         = &H00001603??? ' //
%URLACTION_HTML_FONT_DOWNLOAD                           = &H00001604???
%URLACTION_HTML_JAVA_RUN                                = &H00001605??? ' // derive from Java custom policy
%URLACTION_HTML_USERDATA_SAVE                           = &H00001606???
%URLACTION_HTML_SUBFRAME_NAVIGATE                       = &H00001607???
%URLACTION_HTML_META_REFRESH                            = &H00001608???
%URLACTION_HTML_INCLUDE_FILE_PATH                       = &H0000160A???
%URLACTION_HTML_MIXED_CONTENT                           = &H00001609???
%URLACTION_HTML_INCLUDE_FILE_PATH                       = &H0000160A???
%URLACTION_HTML_MAX                                     = &H000017ff???

%URLACTION_SHELL_MIN                                    = &H00001800???
%URLACTION_SHELL_INSTALL_DTITEMS                        = &H00001800???
%URLACTION_SHELL_MOVE_OR_COPY                           = &H00001802???
%URLACTION_SHELL_FILE_DOWNLOAD                          = &H00001803???
%URLACTION_SHELL_VERB                                   = &H00001804???
%URLACTION_SHELL_WEBVIEW_VERB                           = &H00001805???
%URLACTION_SHELL_SHELLEXECUTE                           = &H00001806???
'#if (_WIN32_IE >= _WIN32_IE_IE60SP2)
%URLACTION_SHELL_EXECUTE_HIGHRISK                       = &H00001806???
%URLACTION_SHELL_EXECUTE_MODRISK                        = &H00001807???
%URLACTION_SHELL_EXECUTE_LOWRISK                        = &H00001808???
%URLACTION_SHELL_POPUPMGR                               = &H00001809???
%URLACTION_SHELL_RTF_OBJECTS_LOAD                       = &H0000180A???
%URLACTION_SHELL_ENHANCED_DRAGDROP_SECURITY             = &H0000180B???
%URLACTION_SHELL_EXTENSIONSECURITY                      = &H0000180C???
%URLACTION_SHELL_SECURE_DRAGSOURCE                      = &H0000180D???
'#endif //(_WIN32_IE >= _WIN32_IE_IE60SP2)
'#if (_WIN32_IE >= _WIN32_IE_WIN7)
%URLACTION_SHELL_REMOTEQUERY                            = &H0000180E???
%URLACTION_SHELL_PREVIEW                                = &H0000180F???
'#endif //(_WIN32_IE >= _WIN32_IE_WIN7)
%URLACTION_SHELL_CURR_MAX                               = &H0000180F???
%URLACTION_SHELL_MAX                                    = &H000019ff???

%URLACTION_NETWORK_MIN                                  = &H00001A00???

%URLACTION_CREDENTIALS_USE                              = &H00001A00???
%URLPOLICY_CREDENTIALS_SILENT_LOGON_OK                  = &H00000000???
%URLPOLICY_CREDENTIALS_MUST_PROMPT_USER                 = &H00010000???
%URLPOLICY_CREDENTIALS_CONDITIONAL_PROMPT               = &H00020000???
%URLPOLICY_CREDENTIALS_ANONYMOUS_ONLY                   = &H00030000???

%URLACTION_AUTHENTICATE_CLIENT                          = &H00001A01???
%URLPOLICY_AUTHENTICATE_CLEARTEXT_OK                    = &H00000000???
%URLPOLICY_AUTHENTICATE_CHALLENGE_RESPONSE              = &H00010000???
%URLPOLICY_AUTHENTICATE_MUTUAL_ONLY                     = &H00030000???


%URLACTION_COOKIES                                      = &H00001A02???
%URLACTION_COOKIES_SESSION                              = &H00001A03???

%URLACTION_CLIENT_CERT_PROMPT                           = &H00001A04???

%URLACTION_COOKIES_THIRD_PARTY                          = &H00001A05???
%URLACTION_COOKIES_SESSION_THIRD_PARTY                  = &H00001A06???

%URLACTION_COOKIES_ENABLED                              = &H00001A10???

%URLACTION_NETWORK_CURR_MAX                             = &H00001A10???
%URLACTION_NETWORK_MAX                                  = &H00001Bff???

%URLACTION_JAVA_MIN                                     = &H00001C00???
%URLACTION_JAVA_PERMISSIONS                             = &H00001C00???
%URLPOLICY_JAVA_PROHIBIT                                = &H00000000???
%URLPOLICY_JAVA_HIGH                                    = &H00010000???
%URLPOLICY_JAVA_MEDIUM                                  = &H00020000???
%URLPOLICY_JAVA_LOW                                     = &H00030000???
%URLPOLICY_JAVA_CUSTOM                                  = &H00800000???
%URLACTION_JAVA_CURR_MAX                                = &H00001C00???
%URLACTION_JAVA_MAX                                     = &H00001Cff???

'// The following Infodelivery actions should have no default policies
'// in the registry.  They assume that no default policy means fall
'// back to the global restriction.  If an admin sets a policy per
'// zone, then it overrides the global restriction.

%URLACTION_INFODELIVERY_MIN                             = &H00001D00???
%URLACTION_INFODELIVERY_NO_ADDING_CHANNELS              = &H00001D00???
%URLACTION_INFODELIVERY_NO_EDITING_CHANNELS             = &H00001D01???
%URLACTION_INFODELIVERY_NO_REMOVING_CHANNELS            = &H00001D02???
%URLACTION_INFODELIVERY_NO_ADDING_SUBSCRIPTIONS         = &H00001D03???
%URLACTION_INFODELIVERY_NO_EDITING_SUBSCRIPTIONS        = &H00001D04???
%URLACTION_INFODELIVERY_NO_REMOVING_SUBSCRIPTIONS       = &H00001D05???
%URLACTION_INFODELIVERY_NO_CHANNEL_LOGGING              = &H00001D06???
%URLACTION_INFODELIVERY_CURR_MAX                        = &H00001D06???
%URLACTION_INFODELIVERY_MAX                             = &H00001Dff???
%URLACTION_CHANNEL_SOFTDIST_MIN                         = &H00001E00???
%URLACTION_CHANNEL_SOFTDIST_PERMISSIONS                 = &H00001E05???
%URLPOLICY_CHANNEL_SOFTDIST_PROHIBIT                    = &H00010000???
%URLPOLICY_CHANNEL_SOFTDIST_PRECACHE                    = &H00020000???
%URLPOLICY_CHANNEL_SOFTDIST_AUTOINSTALL                 = &H00030000???
%URLACTION_CHANNEL_SOFTDIST_MAX                         = &H00001Eff???
'#if (_WIN32_IE >= _WIN32_IE_IE80)
%URLACTION_DOTNET_USERCONTROLS                          = &H00002005???
'#endif //(_WIN32_IE >= _WIN32_IE_IE80)
'#if (_WIN32_IE >= _WIN32_IE_IE60SP2)
%URLACTION_BEHAVIOR_MIN                                 = &H00002000???
%URLACTION_BEHAVIOR_RUN                                 = &H00002000???
%URLPOLICY_BEHAVIOR_CHECK_LIST                          = &H00010000???

'// The following actions correspond to the Feature options above.
'// However, they are NOT in the same order.
%URLACTION_FEATURE_MIN                                  = &H00002100???
%URLACTION_FEATURE_MIME_SNIFFING                        = &H00002100???
%URLACTION_FEATURE_ZONE_ELEVATION                       = &H00002101???
%URLACTION_FEATURE_WINDOW_RESTRICTIONS                  = &H00002102???
%URLACTION_FEATURE_SCRIPT_STATUS_BAR                    = &H00002103???
%URLACTION_FEATURE_FORCE_ADDR_AND_STATUS                = &H00002104???
%URLACTION_FEATURE_BLOCK_INPUT_PROMPTS                  = &H00002105???
%URLACTION_FEATURE_DATA_BINDING                         = &H00002106???

%URLACTION_AUTOMATIC_DOWNLOAD_UI_MIN                    = &H00002200???
%URLACTION_AUTOMATIC_DOWNLOAD_UI                        = &H00002200???
%URLACTION_AUTOMATIC_ACTIVEX_UI                         = &H00002201???

%URLACTION_ALLOW_RESTRICTEDPROTOCOLS                    = &H00002300???

'#endif //(_WIN32_IE >= _WIN32_IE_IE60SP2)

'#if (_WIN32_IE >= _WIN32_IE_IE70)
'// Whether to do the Anti-Phishing check.
%URLACTION_ALLOW_APEVALUATION                           = &H00002301???

'// The following ExpressAPP and XPS actions are trumped by registry in
'// case of Internet Explorer upgrade from IE 6.0 which honors registry.
%URLACTION_WINDOWS_BROWSER_APPLICATIONS                = &H00002400???
%URLACTION_XPS_DOCUMENTS                               = &H00002401???
%URLACTION_LOOSE_XAML                                  = &H00002402???
%URLACTION_LOWRIGHTS                                   = &H00002500???
'// The following action belong to WinFX Bootstrapper
%URLACTION_WINFX_SETUP                                 = &H00002600???

%URLACTION_INPRIVATE_BLOCKING                          = &H00002700???
'#endif //(_WIN32_IE >= _WIN32_IE_IE70)

'// For each action specified above the system maintains
'// a set of policies for the action.
'// The only policies supported currently are permissions (i.e. is something allowed)
'// and logging status.
'// IMPORTANT: If you are defining your own policies don't overload the meaning of the
'// loword of the policy. You can use the hiword to store any policy bits which are only
'// meaningful to your action.
'// For an example of how to do this look at the URLPOLICY_JAVA above

'// Permissions
%URLPOLICY_ALLOW                = &H00???
%URLPOLICY_QUERY                = &H01???
%URLPOLICY_DISALLOW             = &H03???

'// Notifications are not done when user already queried.
%URLPOLICY_NOTIFY_ON_ALLOW      = &H10???
%URLPOLICY_NOTIFY_ON_DISALLOW   = &H20???

'// Logging is done regardless of whether user was queried.
%URLPOLICY_LOG_ON_ALLOW         = &H40???
%URLPOLICY_LOG_ON_DISALLOW      = &H80???

%URLPOLICY_MASK_PERMISSIONS     = &H0f???
'#define GetUrlPolicyPermissions(dw)        (dw & URLPOLICY_MASK_PERMISSIONS)
'#define SetUrlPolicyPermissions(dw,dw2)    ((dw) = ((dw) & ~(URLPOLICY_MASK_PERMISSIONS)) | (dw2))

MACRO GetUrlPolicyPermissions(dw_) = dw_ AND %URLPOLICY_MASK_PERMISSIONS
MACRO SetUrlPolicyPermissions(dw_,dw2) = dw_ = ((dw_ AND (NOT %URLPOLICY_MASK_PERMISSIONS) OR dw2)

%URLPOLICY_DONTCHECKDLGBOX      = &H100???

'// The ordinal #'s that define the predefined zones internet explorer knows about.
'// When we support user-defined zones their zone numbers should be between
'// URLZONE_USER_MIN and URLZONE_USER_MAX
'// Custom policy to query whether the local machine zone
'// has been unlocked for current document.

'#if (_WIN32_IE >= _WIN32_IE_IE60SP2)
'// Custom policy to query whether the local machine zone
'// has been unlocked for current document.
'EXTERN_C const GUID GUID_CUSTOM_LOCALMACHINEZONEUNLOCKED;
'#endif //(_WIN32_IE >= _WIN32_IE_IE60SP2)

' ########################################################################################
' IInternetZoneManager interface
' IID = 79EAC9EF-BAF9-11CE-8C82-00AA004BA90B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInternetZoneManager_INTERFACE_DEFINED)
    %IInternetZoneManager_INTERFACE_DEFINED = 1

' URLZONE enum
%URLZONE_PREDEFINED_MIN = 0
%URLZONE_LOCAL_MACHINE  = 0
%URLZONE_INTRANET       = %URLZONE_LOCAL_MACHINE + 1
%URLZONE_TRUSTED        = %URLZONE_INTRANET      + 1
%URLZONE_INTERNET       = %URLZONE_TRUSTED       + 1
%URLZONE_UNTRUSTED      = %URLZONE_INTERNET      + 1
%URLZONE_PREDEFINED_MAX = 999
%URLZONE_USER_MIN       = 1000
%URLZONE_USER_MAX       = 10000

'// Enhanced Security Configuration zone mapping flag for IInternetSecurityManager::SetZoneMapping

%URLZONE_ESC_FLAG       = &H100

' URLTEMPLATE enum
%URLTEMPLATE_CUSTOM         = 0
%URLTEMPLATE_PREDEFINED_MIN = &H10000???
%URLTEMPLATE_LOW            = &H10000???
%URLTEMPLATE_MEDLOW         = &H10500???
%URLTEMPLATE_MEDIUM         = &H11000???
%URLTEMPLATE_MEDHIGH        = &H11500???
%URLTEMPLATE_HIGH           = &H12000???
%URLTEMPLATE_PREDEFINED_MAX = &H20000???

' __MIDL_IInternetZoneManager_0001 enum
%MAX_ZONE_PATH        = 260
%MAX_ZONE_DESCRIPTION = 200

' ZAFLAGS enum
%ZAFLAGS_CUSTOM_EDIT              = &H1???
%ZAFLAGS_ADD_SITES                = &H2???
%ZAFLAGS_REQUIRE_VERIFICATION     = &H4???
%ZAFLAGS_INCLUDE_PROXY_OVERRIDE   = &H8???
%ZAFLAGS_INCLUDE_INTRANET_SITES   = &H10???
%ZAFLAGS_NO_UI                    = &H20???
%ZAFLAGS_SUPPORTS_VERIFICATION    = &H40???
%ZAFLAGS_UNC_AS_INTRANET          = &H80???
%ZAFLAGS_DETECT_INTRANET          = &H100???
%ZAFLAGS_USE_LOCKED_ZONES         = &H10000???
%ZAFLAGS_VERIFY_TEMPLATE_SETTINGS = &H20000???
%ZAFLAGS_NO_CACHE                 = &H40000???

' // Size = 1460 bytes
TYPE ZONEATTRIBUTES DWORD
   cbSize                 AS DWORD            ' ULONG cbSize
   szDisplayName          AS WSTRINGZ * 260   ' WCHAR szDisplayName[ 260 ]
   szDescription          AS WSTRINGZ * 200   ' WCHAR szDescription[ 200 ]
   szIconPath             AS WSTRINGZ * 260   ' WCHAR szIconPath[ 260 ]
   dwTemplateMinLevel     AS DWORD            ' DWORD dwTemplateMinLevel
   dwTemplateRecommended  AS DWORD            ' DWORD dwTemplateRecommended
   dwTemplateCurrentLevel AS DWORD            ' DWORD dwTemplateCurrentLevel
   dwFlags                AS DWORD            ' DWORD dwFlags
END TYPE

'// Gets the zone attributes (information in registry other than actual security
'// policies associated with the zone).  Zone attributes are fixed as:
'// Sets the zone attributes (information in registry other than actual security
'// policies associated with the zone).  Zone attributes as above.
'// Returns S_OK or ??? if failed to write the zone attributes.
'/* Registry Flags

'    When reading, default behavior is:
'        If HKLM allows override and HKCU value exists
'            Then use HKCU value
'            Else use HKLM value
'    When writing, default behavior is same as HKCU
'        If HKLM allows override
'           Then Write to HKCU
'           Else Fail
'*/

' URLZONEREG enum
%URLZONEREG_DEFAULT = 0
%URLZONEREG_HKLM    = %URLZONEREG_DEFAULT + 1
%URLZONEREG_HKCU    = %URLZONEREG_HKLM + 1

'// Gets a named custom policy associated with a zone;
'// e.g. the Java VM settings can be defined with a unique key such as 'Java'.
'// Custom policy support is intended to allow extensibility from the predefined
'// set of policies that IE4 has built in.
'//
'// pwszKey is the string name designating the custom policy.  Components are
'//   responsible for having unique names.
'// ppPolicy is the callee allocated buffer for the policy byte blob; caller is
'//   responsible for freeing this buffer eventually.
'// pcbPolicy is the size of the byte blob returned.
'// dwRegFlags determines how registry is accessed (see above).
'// Returns S_OK if key is found and buffer allocated; ??? if key is not found (no buffer alloced).
'// Sets a named custom policy associated with a zone;
'// e.g. the Java VM settings can be defined with a unique key such as 'Java'.
'// Custom policy support is intended to allow extensibility from the predefined
'// set of policies that IE4 has built in.
'//
'// pwszKey is the string name designating the custom policy.  Components are
'//   responsible for having unique names.
'// ppPolicy is the caller allocated buffer for the policy byte blob.
'// pcbPolicy is the size of the byte blob to be set.
'// dwRegFlags determines if HTCU or HKLM is set.
'// Returns S_OK or ??? if failed to write the zone custom policy.
'// Gets action policy associated with a zone, the builtin, fixed-length policies info.

'// dwAction is the action code for the action as defined above.
'// pPolicy is the caller allocated buffer for the policy data.
'// cbPolicy is the size of the caller allocated buffer.
'// dwRegFlags determines how registry is accessed (see above).
'// Returns S_OK if action is valid; ??? if action is not valid.

$IID_IInternetZoneManager = GUID$("{79EAC9EF-BAF9-11CE-8C82-00AA004BA90B}")

INTERFACE IInternetZoneManager $IID_IInternetZoneManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetZoneAttributes ( _                         ' VTable offset = 12
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYREF pZoneAttributes AS ZONEATTRIBUTES _          ' __in_out ZONEATTRIBUTES *pZoneAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetZoneAttributes ( _                         ' VTable offset = 16
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYREF pZoneAttributes AS ZONEATTRIBUTES _          ' __in ZONEATTRIBUTES *pZoneAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetZoneCustomPolicy ( _                       ' VTable offset = 20
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF ppPolicy AS DWORD _                          ' __out BYTE **ppPolicy
   , BYREF pcbPolicy AS DWORD _                         ' __out DWORD *pcbPolicy
   , BYVAL urlZoneReg AS DWORD _                        ' __in URLZONEREG urlZoneReg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetZoneCustomPolicy ( _                       ' VTable offset = 24
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pPolicy AS BYTE PTR _                        ' __in BYTE *pPolicy
   , BYVAL cbPolicy AS DWORD _                          ' __in DWORD cbPolicy
   , BYVAL urlZoneReg AS DWORD _                        ' __in URLZONEREG urlZoneReg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetZoneActionPolicy ( _                       ' VTable offset = 28
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYVAL pPolicy AS BYTE PTR _                        ' __out BYTE *pPolicy
   , BYVAL cbPolicy AS DWORD _                          ' __in DWORD cbPolicy
   , BYVAL urlZoneReg AS DWORD _                        ' __in URLZONEREG urlZoneReg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetZoneActionPolicy ( _                       ' VTable offset = 32
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYVAL pPolicy AS BYTE PTR _                        ' __in BYTE *pPolicy
   , BYVAL cbPolicy AS DWORD _                          ' __in DWORD cbPolicy
   , BYVAL urlZoneReg AS DWORD _                        ' __in URLZONEREG urlZoneReg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PromptAction ( _                              ' VTable offset = 36
     BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYREF pwszUrl AS WSTRINGZ _                        ' __in LPCWSTR pwszUrl
   , BYREF pwszText AS WSTRINGZ _                       ' __in LPCWSTR pwszText
   , BYVAL dwPromptFlags AS DWORD _                     ' __in DWORD dwPromptFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LogAction ( _                                 ' VTable offset = 40
     BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYREF pwszUrl AS WSTRINGZ _                        ' __in LPCWSTR pwszUrl
   , BYREF pwszText AS WSTRINGZ _                       ' __in LPCWSTR pwszText
   , BYVAL dwLogFlags AS DWORD _                        ' __in DWORD dwLogFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateZoneEnumerator ( _                      ' VTable offset = 44
     BYREF pdwEnum AS DWORD _                           ' __out DWORD *pdwEnum
   , BYREF pdwCount AS DWORD _                          ' __out DWORD *pdwCount
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetZoneAt ( _                                 ' VTable offset = 48
     BYVAL dwEnum AS DWORD _                            ' __in DWORD dwEnum
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF pdwZone AS DWORD _                           ' __out DWORD *pdwZone
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DestroyZoneEnumerator ( _                     ' VTable offset = 52
     BYVAL dwEnum AS DWORD _                            ' __in DWORD dwEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTemplatePoliciesToZone ( _                ' VTable offset = 56
     BYVAL dwTemplate AS DWORD _                        ' __in DWORD dwTemplate
   , BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInternetZoneManager_INTERFACE_DEFINED__ */

' ########################################################################################
' IInternetZoneManagerEx interface
' IID = A4C23339-8E06-431E-9BF4-7E711C085648
' Inherited interface = IInternetZoneManager
' ########################################################################################

#IF NOT %DEF(%IInternetZoneManagerEx_INTERFACE_DEFINED)
    %IInternetZoneManagerEx_INTERFACE_DEFINED = 1

'// Gets action policy associated with a zone, the builtin, fixed-length policies info.

'// dwAction is the action code for the action as defined above.
'// pPolicy is the caller allocated buffer for the policy data.
'// cbPolicy is the size of the caller allocated buffer.
'// dwRegFlags determines how registry is accessed (see above).
'// dwFlags determine which registry policies are accessed (see above).
'// Returns S_OK if action is valid; ??? if action is not valid.

$IID_IInternetZoneManagerEx = GUID$("{A4C23339-8E06-431E-9BF4-7E711C085648}")

INTERFACE IInternetZoneManagerEx $IID_IInternetZoneManagerEx

   INHERIT IUnknown

   ' =====================================================================================
   ' IInternetZoneManager Methods
   ' =====================================================================================
   METHOD GetZoneAttributes ( _                         ' VTable offset = 12
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYREF pZoneAttributes AS ZONEATTRIBUTES _          ' __in_out ZONEATTRIBUTES *pZoneAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetZoneAttributes ( _                         ' VTable offset = 16
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYREF pZoneAttributes AS ZONEATTRIBUTES _          ' __in ZONEATTRIBUTES *pZoneAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetZoneCustomPolicy ( _                       ' VTable offset = 20
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF ppPolicy AS DWORD _                          ' __out BYTE **ppPolicy
   , BYREF pcbPolicy AS DWORD _                         ' __out DWORD *pcbPolicy
   , BYVAL urlZoneReg AS DWORD _                        ' __in URLZONEREG urlZoneReg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetZoneCustomPolicy ( _                       ' VTable offset = 24
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pPolicy AS BYTE PTR _                        ' __in BYTE *pPolicy
   , BYVAL cbPolicy AS DWORD _                          ' __in DWORD cbPolicy
   , BYVAL urlZoneReg AS DWORD _                        ' __in URLZONEREG urlZoneReg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetZoneActionPolicy ( _                       ' VTable offset = 28
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYVAL pPolicy AS BYTE PTR _                        ' __out BYTE *pPolicy
   , BYVAL cbPolicy AS DWORD _                          ' __in DWORD cbPolicy
   , BYVAL urlZoneReg AS DWORD _                        ' __in URLZONEREG urlZoneReg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetZoneActionPolicy ( _                       ' VTable offset = 32
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYVAL pPolicy AS BYTE PTR _                        ' __in BYTE *pPolicy
   , BYVAL cbPolicy AS DWORD _                          ' __in DWORD cbPolicy
   , BYVAL urlZoneReg AS DWORD _                        ' __in URLZONEREG urlZoneReg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PromptAction ( _                              ' VTable offset = 36
     BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYREF pwszUrl AS WSTRINGZ _                        ' __in LPCWSTR pwszUrl
   , BYREF pwszText AS WSTRINGZ _                       ' __in LPCWSTR pwszText
   , BYVAL dwPromptFlags AS DWORD _                     ' __in DWORD dwPromptFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LogAction ( _                                 ' VTable offset = 40
     BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYREF pwszUrl AS WSTRINGZ _                        ' __in LPCWSTR pwszUrl
   , BYREF pwszText AS WSTRINGZ _                       ' __in LPCWSTR pwszText
   , BYVAL dwLogFlags AS DWORD _                        ' __in DWORD dwLogFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateZoneEnumerator ( _                      ' VTable offset = 44
     BYREF pdwEnum AS DWORD _                           ' __out DWORD *pdwEnum
   , BYREF pdwCount AS DWORD _                          ' __out DWORD *pdwCount
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetZoneAt ( _                                 ' VTable offset = 48
     BYVAL dwEnum AS DWORD _                            ' __in DWORD dwEnum
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF pdwZone AS DWORD _                           ' __out DWORD *pdwZone
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DestroyZoneEnumerator ( _                     ' VTable offset = 52
     BYVAL dwEnum AS DWORD _                            ' __in DWORD dwEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTemplatePoliciesToZone ( _                ' VTable offset = 56
     BYVAL dwTemplate AS DWORD _                        ' __in DWORD dwTemplate
   , BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IInternetZoneManagerEx Methods
   ' =====================================================================================
   METHOD GetZoneActionPolicyEx ( _                     ' VTable offset = 60
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYVAL pPolicy AS BYTE PTR _                        ' __out BYTE *pPolicy
   , BYVAL cbPolicy AS DWORD _                          ' __in DWORD cbPolicy
   , BYVAL urlZoneReg AS DWORD _                        ' __in URLZONEREG urlZoneReg
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetZoneActionPolicyEx ( _                     ' VTable offset = 64
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYVAL pPolicy AS BYTE PTR _                        ' __in BYTE *pPolicy
   , BYVAL cbPolicy AS DWORD _                          ' __in DWORD cbPolicy
   , BYVAL urlZoneReg AS DWORD _                        ' __in URLZONEREG urlZoneReg
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInternetZoneManagerEx_INTERFACE_DEFINED__ */

' ########################################################################################
' IInternetZoneManagerEx2 interface
' IID = EDC17559-DD5D-4846-8EEF-8BECBA5A4ABF
' Inherited interface = IInternetZoneManagerEx
' ########################################################################################

#IF NOT %DEF(%IInternetZoneManagerEx2_INTERFACE_DEFINED)
    %IInternetZoneManagerEx2_INTERFACE_DEFINED = 1

'// Gets the zone attributes (information in registry other than actual security
'// policies associated with the zone).  Zone attributes are fixed as:
'// Can also verify template settings by matching current settings with security template

$IID_IInternetZoneManagerEx2 = GUID$("{EDC17559-DD5D-4846-8EEF-8BECBA5A4ABF}")

INTERFACE IInternetZoneManagerEx2 $IID_IInternetZoneManagerEx2

   INHERIT IUnknown

   ' =====================================================================================
   ' IInternetZoneManager Methods
   ' =====================================================================================
   METHOD GetZoneAttributes ( _                         ' VTable offset = 12
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYREF pZoneAttributes AS ZONEATTRIBUTES _          ' __in_out ZONEATTRIBUTES *pZoneAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetZoneAttributes ( _                         ' VTable offset = 16
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYREF pZoneAttributes AS ZONEATTRIBUTES _          ' __in ZONEATTRIBUTES *pZoneAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetZoneCustomPolicy ( _                       ' VTable offset = 20
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF ppPolicy AS DWORD _                          ' __out BYTE **ppPolicy
   , BYREF pcbPolicy AS DWORD _                         ' __out DWORD *pcbPolicy
   , BYVAL urlZoneReg AS DWORD _                        ' __in URLZONEREG urlZoneReg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetZoneCustomPolicy ( _                       ' VTable offset = 24
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pPolicy AS BYTE PTR _                        ' __in BYTE *pPolicy
   , BYVAL cbPolicy AS DWORD _                          ' __in DWORD cbPolicy
   , BYVAL urlZoneReg AS DWORD _                        ' __in URLZONEREG urlZoneReg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetZoneActionPolicy ( _                       ' VTable offset = 28
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYVAL pPolicy AS BYTE PTR _                        ' __out BYTE *pPolicy
   , BYVAL cbPolicy AS DWORD _                          ' __in DWORD cbPolicy
   , BYVAL urlZoneReg AS DWORD _                        ' __in URLZONEREG urlZoneReg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetZoneActionPolicy ( _                       ' VTable offset = 32
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYVAL pPolicy AS BYTE PTR _                        ' __in BYTE *pPolicy
   , BYVAL cbPolicy AS DWORD _                          ' __in DWORD cbPolicy
   , BYVAL urlZoneReg AS DWORD _                        ' __in URLZONEREG urlZoneReg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PromptAction ( _                              ' VTable offset = 36
     BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYREF pwszUrl AS WSTRINGZ _                        ' __in LPCWSTR pwszUrl
   , BYREF pwszText AS WSTRINGZ _                       ' __in LPCWSTR pwszText
   , BYVAL dwPromptFlags AS DWORD _                     ' __in DWORD dwPromptFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LogAction ( _                                 ' VTable offset = 40
     BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYREF pwszUrl AS WSTRINGZ _                        ' __in LPCWSTR pwszUrl
   , BYREF pwszText AS WSTRINGZ _                       ' __in LPCWSTR pwszText
   , BYVAL dwLogFlags AS DWORD _                        ' __in DWORD dwLogFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateZoneEnumerator ( _                      ' VTable offset = 44
     BYREF pdwEnum AS DWORD _                           ' __out DWORD *pdwEnum
   , BYREF pdwCount AS DWORD _                          ' __out DWORD *pdwCount
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetZoneAt ( _                                 ' VTable offset = 48
     BYVAL dwEnum AS DWORD _                            ' __in DWORD dwEnum
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF pdwZone AS DWORD _                           ' __out DWORD *pdwZone
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DestroyZoneEnumerator ( _                     ' VTable offset = 52
     BYVAL dwEnum AS DWORD _                            ' __in DWORD dwEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTemplatePoliciesToZone ( _                ' VTable offset = 56
     BYVAL dwTemplate AS DWORD _                        ' __in DWORD dwTemplate
   , BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IInternetZoneManagerEx Methods
   ' =====================================================================================
   METHOD GetZoneActionPolicyEx ( _                     ' VTable offset = 60
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYVAL pPolicy AS BYTE PTR _                        ' __out BYTE *pPolicy
   , BYVAL cbPolicy AS DWORD _                          ' __in DWORD cbPolicy
   , BYVAL urlZoneReg AS DWORD _                        ' __in URLZONEREG urlZoneReg
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetZoneActionPolicyEx ( _                     ' VTable offset = 64
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYVAL pPolicy AS BYTE PTR _                        ' __in BYTE *pPolicy
   , BYVAL cbPolicy AS DWORD _                          ' __in DWORD cbPolicy
   , BYVAL urlZoneReg AS DWORD _                        ' __in URLZONEREG urlZoneReg
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IInternetZoneManagerEx2 Methods
   ' =====================================================================================
   METHOD GetZoneAttributesEx ( _                       ' VTable offset = 68
     BYVAL dwZone AS DWORD _                            ' __in DWORD dwZone
   , BYREF pZoneAttributes AS ZONEATTRIBUTES _          ' __in ZONEATTRIBUTES *pZoneAttributes
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetZoneSecurityState ( _                      ' VTable offset = 72
     BYVAL dwZoneIndex AS DWORD _                       ' __in DWORD dwZoneIndex
   , BYVAL fRespectPolicy AS LONG _                     ' __in BOOL fRespectPolicy
   , BYREF pdwState AS DWORD _                          ' __in_out LPDWORD pdwState
   , BYREF pfPolicyEncountered AS LONG _                ' __in_out BOOL *pfPolicyEncountered
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIESecurityState ( _                        ' VTable offset = 76
     BYVAL fRespectPolicy AS LONG _                     ' __in BOOL fRespectPolicy
   , BYREF pdwState AS DWORD _                          ' __in_out LPDWORD pdwState
   , BYREF pfPolicyEncountered AS LONG _                ' __in_out BOOL *pfPolicyEncountered
   , BYVAL fNoCache AS LONG _                           ' __in BOOL fNoCache
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FixUnsecureSettings ( _                       ' VTable offset = 80
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInternetZoneManagerEx2_INTERFACE_DEFINED__ */


%SOFTDIST_FLAG_USAGE_EMAIL         = &H00000001???
%SOFTDIST_FLAG_USAGE_PRECACHE      = &H00000002???
%SOFTDIST_FLAG_USAGE_AUTOINSTALL   = &H00000004???
%SOFTDIST_FLAG_DELETE_SUBSCRIPTION = &H00000008???

%SOFTDIST_ADSTATE_NONE             = &H00000000???
%SOFTDIST_ADSTATE_AVAILABLE        = &H00000001???
%SOFTDIST_ADSTATE_DOWNLOADED       = &H00000002???
%SOFTDIST_ADSTATE_INSTALLED        = &H00000003???

' // Size = 24 bytes
TYPE CODEBASEHOLD DWORD
   cbSize      AS DWORD          ' ULONG cbSize
   szDistUnit  AS WSTRINGZ PTR   ' LPWSTR szDistUnit
   szCodeBase  AS WSTRINGZ PTR   ' LPWSTR szCodeBase
   dwVersionMS AS DWORD          ' DWORD dwVersionMS
   dwVersionLS AS DWORD          ' DWORD dwVersionLS
   dwStyle     AS DWORD          ' DWORD dwStyle
END TYPE

' // Size = 52 bytes
TYPE SOFTDISTINFO DWORD
   cbSize                AS DWORD         ' ULONG cbSize
   dwFlags               AS DWORD         ' DWORD dwFlags
   dwAdState             AS DWORD         ' DWORD dwAdState
   szTitle               AS WSTRINGZ PTR  ' LPWSTR szTitle
   szAbstract            AS WSTRINGZ PTR  ' LPWSTR szAbstract
   szHREF                AS WSTRINGZ PTR  ' LPWSTR szHREF
   dwInstalledVersionMS  AS DWORD         ' DWORD dwInstalledVersionMS
   dwInstalledVersionLS  AS DWORD         ' DWORD dwInstalledVersionLS
   dwUpdateVersionMS     AS DWORD         ' DWORD dwUpdateVersionMS
   dwUpdateVersionLS     AS DWORD         ' DWORD dwUpdateVersionLS
   dwAdvertisedVersionMS AS DWORD         ' DWORD dwAdvertisedVersionMS
   dwAdvertisedVersionLS AS DWORD         ' DWORD dwAdvertisedVersionLS
   dwReserved            AS DWORD         ' DWORD dwReserved
END TYPE

' ########################################################################################
' ISoftDistExt interface
' IID = B15B8DC1-C7E1-11D0-8680-00AA00BDCB71
' Inherited interface = IUnknown
' Not currently implemented.
' ########################################################################################

#IF NOT %DEF(%ISoftDistExt_INTERFACE_DEFINED)
    %ISoftDistExt_INTERFACE_DEFINED = 1

$IID_ISoftDistExt = GUID$("{B15B8DC1-C7E1-11D0-8680-00AA00BDCB71}")
$CLSID_SBS_SoftDistExt = $IID_ISoftDistExt

INTERFACE ISoftDistExt $IID_ISoftDistExt

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ProcessSoftDist ( _                           ' VTable offset = 12
     BYREF szCDFURL AS WSTRINGZ _                       ' __in LPCWSTR szCDFURL
   , BYVAL pSoftDistElement AS IXMLElement _            ' __in IXMLElement *pSoftDistElement
   , BYREF lpsdi AS SOFTDISTINFO _                      ' __in_out LPSOFTDISTINFO lpsdi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFirstCodeBase ( _                          ' VTable offset = 16
     BYREF szCodeBase AS DWORD _                        ' __in LPWSTR *szCodeBase
   , BYVAL dwMaxSize AS DWORD _                         ' __in LPDWORD dwMaxSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextCodeBase ( _                           ' VTable offset = 20
     BYREF szCodeBase AS DWORD _                        ' __in LPWSTR *szCodeBase
   , BYVAL dwMaxSize AS DWORD _                         ' __in LPDWORD dwMaxSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AsyncInstallDistributionUnit ( _              ' VTable offset = 24
     BYVAL pbc AS IBindCtx _                            ' __in IBindCtx *pbc
   , BYVAL pvReserved AS DWORD _                        ' __in LPVOID pvReserved
   , BYVAL flags AS DWORD _                             ' __in DWORD flags
   , BYREF lpcbh AS CODEBASEHOLD _                      ' __in LPCODEBASEHOLD lpcbh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISoftDistExt_INTERFACE_DEFINED__ */

DECLARE FUNCTION GetSoftwareUpdateInfo IMPORT "URLMON.DLL" ALIAS "GetSoftwareUpdateInfo" ( _
   BYREF szDistUnit AS WSTRINGZ _                       ' __in  LPCWSTR szDistUnit
 , BYREF psdi AS SOFTDISTINFO _                         ' __out LPSOFTDISTINFO psdi
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SetSoftwareUpdateAdvertisementState IMPORT "URLMON.DLL" ALIAS "GetSoftwareUpdateInfo" ( _
   BYREF szDistUnit AS WSTRINGZ _                       ' __in LPCWSTR szDistUnit
 , BYVAL dwAdState AS DWORD _                           ' __in DWORD dwAdState
 , BYVAL dwAdvertisedVersionMS AS DWORD _               ' __in DWORD dwAdvertisedVersionMS
 , BYVAL dwAdvertisedVersionLS AS DWORD _               ' __in DWORD dwAdvertisedVersionLS
 ) AS LONG                                              ' HRESULT

' ########################################################################################
' ICatalogFileInfo interface
' IID = 711C7600-6B48-11D1-B403-00AA00B92AF1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICatalogFileInfo_INTERFACE_DEFINED)
    %ICatalogFileInfo_INTERFACE_DEFINED = 1

$IID_ICatalogFileInfo = GUID$("{711C7600-6B48-11D1-B403-00AA00B92AF1}")

INTERFACE ICatalogFileInfo $IID_ICatalogFileInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCatalogFile ( _                            ' VTable offset = 12
     BYREF ppszCatalogFile AS DWORD _                   ' __out LPSTR *ppszCatalogFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetJavaTrust ( _                              ' VTable offset = 16
     BYREF ppJavaTrust AS DWORD _                       ' __out void **ppJavaTrust
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICatalogFileInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' IDataFilter interface
' IID = 69D14C80-C18E-11D0-A9CE-006097942311
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDataFilter_INTERFACE_DEFINED)
    %IDataFilter_INTERFACE_DEFINED = 1

$IID_IDataFilter = GUID$("{69D14C80-C18E-11D0-A9CE-006097942311}")

INTERFACE IDataFilter $IID_IDataFilter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD DoEncode ( _                                  ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL lInBufferSize AS LONG _                      ' __in LONG lInBufferSize
   , BYVAL pbInBuffer AS BYTE PTR _                     ' __in BYTE *pbInBuffer
   , BYVAL lOutBufferSize AS LONG _                     ' __in LONG lOutBufferSize
   , BYVAL pbOutBuffer AS BYTE PTR _                    ' __out BYTE *pbOutBuffer
   , BYVAL lInBytesAvailable AS DWORD _                 ' __in LONG lInBytesAvailable
   , BYREF plInBytesRead AS LONG _                      ' __out LONG *plInBytesRead
   , BYREF plOutBytesWritten AS LONG _                  ' __out LONG *plOutBytesWritten
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoDecode ( _                                  ' VTable offset = 16
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL lInBufferSize AS LONG _                      ' __in LONG lInBufferSize
   , BYVAL pbInBuffer AS BYTE PTR _                     ' __in BYTE *pbInBuffer
   , BYVAL lOutBufferSize AS LONG _                     ' __in LONG lOutBufferSize
   , BYVAL pbOutBuffer AS BYTE PTR _                    ' __out BYTE *pbOutBuffer
   , BYVAL lInBytesAvailable AS DWORD _                 ' __in LONG lInBytesAvailable
   , BYREF plInBytesRead AS LONG _                      ' __out LONG *plInBytesRead
   , BYREF plOutBytesWritten AS LONG _                  ' __out LONG *plOutBytesWritten
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEncodingLevel ( _                          ' VTable offset = 20
     BYVAL dwEncLevel AS DWORD _                        ' __in DWORD dwEncLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDataFilter_INTERFACE_DEFINED__ */

' // Size = 20 bytes
TYPE PROTOCOLFILTERDATA DWORD
   cbSize        AS DWORD       ' DWORD cbSize
   pProtocolSink AS DWORD PTR   ' IInternetProtocolSink *pProtocolSink
   pProtocol     AS DWORD PTR   ' IInternetProtocol *pProtocol
   pUnk          AS DWORD PTR   ' IUnknown *pUnk
   dwFilterFlags AS DWORD       ' DWORD dwFilterFlags
END TYPE

' ########################################################################################
' IEncodingFilterFactory interface
' IID = 70BDDE00-C18E-11D0-A9CE-006097942311
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEncodingFilterFactory_INTERFACE_DEFINED)
    %IEncodingFilterFactory_INTERFACE_DEFINED = 1

' // Size = 16 bytes
TYPE DATAINFO DWORD
   ulTotalSize      AS DWORD   ' ULONG ulTotalSize
   ulavrPacketSize  AS DWORD   ' ULONG ulavrPacketSize
   ulConnectSpeed   AS DWORD   ' ULONG ulConnectSpeed
   ulProcessorSpeed AS DWORD   ' ULONG ulProcessorSpeed
END TYPE

$IID_IEncodingFilterFactory = GUID$("{70BDDE00-C18E-11D0-A9CE-006097942311}")

INTERFACE IEncodingFilterFactory $IID_IEncodingFilterFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD FindBestFilter ( _                            ' VTable offset = 12
     BYREF pwzCodeIn AS WSTRINGZ _                      ' __in LPCWSTR pwzCodeIn
   , BYREF pwzCodeOut AS WSTRINGZ _                     ' __in LPCWSTR pwzCodeOut
   , BYREF info AS DATAINFO _                           ' __in DATAINFO info
   , BYREF ppDF AS IDataFilter _                        ' __out IDataFilter **ppDF
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultFilter ( _                          ' VTable offset = 16
     BYREF pwzCodeIn AS WSTRINGZ _                      ' __in LPCWSTR pwzCodeIn
   , BYREF pwzCodeOut AS WSTRINGZ _                     ' __in LPCWSTR pwzCodeOut
   , BYREF ppDF AS IDataFilter _                        ' __out IDataFilter **ppDF
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEncodingFilterFactory_INTERFACE_DEFINED__ */


'// Logging-specific apis

DECLARE FUNCTION IsLoggingEnabledA IMPORT "URLMON.DLL" ALIAS "IsLoggingEnabledA" ( _
   BYREF pszUrl AS ASCIIZ _                             ' __in LPCSTR pszUrl
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsLoggingEnabledW IMPORT "URLMON.DLL" ALIAS "IsLoggingEnabledW" ( _
   BYREF pszUrl AS WSTRINGZ _                           ' __in LPCWSTR pszUrl
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO IsLoggingEnabled = IsLoggingEnabledW
#ELSE
   MACRO IsLoggingEnabled = IsLoggingEnabledA
#ENDIF

' // Size = 44 bytes
TYPE HIT_LOGGING_INFO DWORD
   dwStructSize      AS DWORD        ' DWORD dwStructSize
   lpszLoggedUrlName AS ASCIIZ PTR   ' LPSTR lpszLoggedUrlName
   StartTime         AS SYSTEMTIME   ' SYSTEMTIME StartTime
   EndTime           AS SYSTEMTIME   ' SYSTEMTIME EndTime
   lpszExtendedInfo  AS ASCIIZ PTR   ' LPSTR lpszExtendedInfo
END TYPE

DECLARE FUNCTION WriteHitLogging IMPORT "URLMON.DLL" ALIAS "WriteHitLogging" ( _
   BYREF lpLogginginfo AS HIT_LOGGING_INFO _            ' __in LPHIT_LOGGING_INFO lpLogginginfo
 ) AS LONG                                              ' BOOL

%CONFIRMSAFETYACTION_LOADOBJECT = &H00000001???

' // Size = 24 bytes
TYPE CONFIRMSAFETY DWORD
   clsid   AS GUID        ' CLSID clsid
   pUnk    AS DWORD PTR   ' IUnknown *pUnk
   dwFlags AS DWORD       ' DWORD dwFlags
END TYPE

'EXTERN_C const GUID GUID_CUSTOM_CONFIRMOBJECTSAFETY;
$GUID_CUSTOM_CONFIRMOBJECTSAFETY = GUID$("{10200490-FA38-11D0-AC0E-00A0C90FFF00}")

' ########################################################################################
' IWrappedProtocol interface
' IID = 53C84785-8425-4DC5-971B-E58D9C19F9B6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWrappedProtocol_INTERFACE_DEFINED)
    %IWrappedProtocol_INTERFACE_DEFINED = 1

$IID_IWrappedProtocol = GUID$("{53C84785-8425-4DC5-971B-E58D9C19F9B6}")

INTERFACE IWrappedProtocol $IID_IWrappedProtocol

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetWrapperCode ( _                            ' VTable offset = 12
     BYREF pnCode AS DWORD _                            ' __out LONG *pnCode
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD_PTR dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWrappedProtocol_INTERFACE_DEFINED__ */
