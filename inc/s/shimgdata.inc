' ########################################################################################
' Microsoft Windows
' File: shimgdata.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SHIMGDATA_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oleidl.inc"
#INCLUDE ONCE "propidl.inc"

'typedef DWORD PixelFormat;
'typedef DWORD InterpolationMode;
'typedef BYTE EncoderParameters;
'typedef BYTE Image;

$$SHIMGKEY_QUALITY    = "Compression"$$
$$SHIMGKEY_RAWFORMAT  = "RawDataFormat"$$

%SHIMGDEC_DEFAULT            = &H00000000???
%SHIMGDEC_THUMBNAIL          = &H00000001???
%SHIMGDEC_LOADFULL           = &H00000002???

'#define  E_NOTVALIDFORANIMATEDIMAGE  MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x01)
%E_NOTVALIDFORANIMATEDIMAGE  = &H80040001&


' ########################################################################################
' IShellImageDataFactory interface
' IID = 9BE8ED5C-EDAB-4D75-90F3-BD5BDBB21C82
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellImageDataFactory_INTERFACE_DEFINED)
    %IShellImageDataFactory_INTERFACE_DEFINED = 1

$IID_IShellImageDataFactory = GUID$("{9BE8ED5C-EDAB-4D75-90F3-BD5BDBB21C82}")

INTERFACE IShellImageDataFactory $IID_IShellImageDataFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateIShellImageData ( _                     ' VTable offset = 12
     BYREF ppshimg AS IShellImageData _                 ' __out IShellImageData **ppshimg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateImageFromFile ( _                       ' VTable offset = 16
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   , BYREF ppshimg AS IShellImageData _                 ' __out IShellImageData **ppshimg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateImageFromStream ( _                     ' VTable offset = 20
     BYVAL pStream AS IStream _                         ' __in IStream *pStream
   , BYREF ppshimg AS IShellImageData _                 ' __out IShellImageData **ppshimg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDataFormatFromPath ( _                     ' VTable offset = 24
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   , BYREF pDataFormat AS GUID _                        ' __out GUID *pDataFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellImageDataFactory_INTERFACE_DEFINED__ */


' ########################################################################################
' IShellImageData interface
' IID = BFDEEC12-8040-4403-A5EA-9E07DAFCF530
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellImageData_INTERFACE_DEFINED)
    %IShellImageData_INTERFACE_DEFINED = 1

$IID_IShellImageData = GUID$("{BFDEEC12-8040-4403-A5EA-9E07DAFCF530}")

INTERFACE IShellImageData $IID_IShellImageData

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Decode ( _                                    ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL cxDesired AS DWORD _                         ' __in ULONG cxDesired
   , BYVAL cyDesired AS DWORD _                         ' __in ULONG cyDesired
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Draw ( _                                      ' VTable offset = 16
     BYVAL hdc AS DWORD _                               ' __in HDC hdc
   , BYREF prcDest AS RECT _                            ' __in LPRECT prcDest
   , BYREF prcSrc AS RECT _                             ' __in LPRECT prcSrc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NextFrame ( _                                 ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NextPage ( _                                  ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PrevPage ( _                                  ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsTransparent ( _                             ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsAnimated ( _                                ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsVector ( _                                  ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsMultipage ( _                               ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsEditable ( _                                ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsPrintable ( _                               ' VTable offset = 52
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDecoded ( _                                 ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentPage ( _                            ' VTable offset = 60
     BYREF pnPage AS DWORD _                            ' __out ULONG *pnPage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPageCount ( _                              ' VTable offset = 64
     BYREF pcPages AS DWORD _                           ' __out ULONG *pcPages
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectPage ( _                                ' VTable offset = 68
     BYVAL iPage AS DWORD _                             ' __in ULONG iPage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 72
     BYREF pSize AS DWORD _                             ' __out SIZE *pSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRawDataFormat ( _                          ' VTable offset = 76
     BYREF pDataFormat AS GUID _                        ' __out GUID *pDataFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelFormat ( _                            ' VTable offset = 80
     BYREF pFormat AS DWORD _                           ' __out PixelFormat *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDelay ( _                                  ' VTable offset = 84
     BYREF pdwDelay AS DWORD _                          ' __out DWORD *pdwDelay
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperties ( _                             ' VTable offset = 88
     BYVAL dwMode AS DWORD _                            ' __in DWORD dwMode
   , BYREF ppPropSet AS IPropertySetStorage _           ' __out IPropertySetStorage **ppPropSet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Rotate ( _                                    ' VTable offset = 92
     BYVAL dwAngle AS DWORD _                           ' __in DWORD dwAngle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Scale ( _                                     ' VTable offset = 96
     BYVAL cx AS DWORD _                                ' __in ULONG cx
   , BYVAL cy AS DWORD _                                ' __in ULONG cy
   , BYVAL hints AS DWORD _                             ' __in InterpolationMode hints
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DiscardEdit ( _                               ' VTable offset = 100
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEncoderParams ( _                          ' VTable offset = 104
     BYVAL pbagEnc AS IPropertyBag _                    ' __in IPropertyBag *pbagEnc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisplayName ( _                               ' VTable offset = 108
     BYREF wszName AS WSTRINGZ _                        ' __in_out LPWSTR wszName
   , BYVAL cch AS DWORD _                               ' __in UINT cch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResolution ( _                             ' VTable offset = 112
     BYREF puResolutionX AS DWORD _                     ' __out ULONG *puResolutionX
   , BYREF puResolutionY AS DWORD _                     ' __out ULONG *puResolutionY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEncoderParams ( _                          ' VTable offset = 116
     BYREF pguidFmt AS GUID _                           ' __in GUID *pguidFmt
   , BYREF ppEncParams AS DWORD _                       ' __out EncoderParameters **ppEncParams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterAbort ( _                             ' VTable offset = 120
     BYVAL pAbort AS IShellImageDataAbort _             ' __in IShellImageDataAbort *pAbort
   , BYREF ppAbortPrev AS IShellImageDataAbort _        ' __out IShellImageDataAbort **ppAbortPrev
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloneFrame ( _                                ' VTable offset = 124
     BYREF ppImg AS DWORD _                             ' __out Image **ppImg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReplaceFrame ( _                              ' VTable offset = 128
     BYVAL pImg AS DWORD _                              ' __in Image *pImg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellImageData_INTERFACE_DEFINED__ */


' ########################################################################################
' IShellImageDataAbort interface
' IID = 53FB8E58-50C0-4003-B4AA-0C8DF28E7F3A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellImageDataAbort_INTERFACE_DEFINED)
    %IShellImageDataAbort_INTERFACE_DEFINED = 1

$IID_IShellImageDataAbort = GUID$("{53FB8E58-50C0-4003-B4AA-0C8DF28E7F3A}")

INTERFACE IShellImageDataAbort $IID_IShellImageDataAbort

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryAbort ( _                                ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* IShellImageDataAbort_INTERFACE_DEFINED */


#IF NOT %DEF(%ShellImageData_LIBRARY_DEFINED)
    %ShellImageData_LIBRARY_DEFINED = 1

'EXTERN_C const IID LIBID_ShellImageData;
'EXTERN_C const CLSID CLSID_ShellImageDataFactory;
$CLSID_ShellImageDataFactory = GUID$("{66E4E4FB-F385-4DD0-8D74-A2EFD1BC6178}")

#ENDIF   ' #IF NOT %DEF(%ShellImageData_LIBRARY_DEFINED)
