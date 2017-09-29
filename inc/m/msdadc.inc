' ########################################################################################
' Microsoft Windows
' File: msdadc.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MSDADC_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "oledb.inc"

' ########################################################################################
' IDataConvert interface
' IID = 0C733A8D-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDataConvert_INTERFACE_DEFINED)
   %IDataConvert_INTERFACE_DEFINED = 1

'typedef DWORD DBDATACONVERT;

' DBDATACONVERTENUM
%DBDATACONVERT_DEFAULT          = 0
%DBDATACONVERT_SETDATABEHAVIOR  = &H1
%DBDATACONVERT_LENGTHFROMNTS    = &H2
%DBDATACONVERT_DSTISFIXEDLENGTH = &H4
%DBDATACONVERT_DECIMALSCALE     = &H8

$IID_IDataConvert = GUID$("{0C733A8D-2A1C-11CE-ADE5-00AA0044773D}")

INTERFACE IDataConvert $IID_IDataConvert

   INHERIT IUnknown

   ' =====================================================================================
   METHOD DataConvert ( _                               ' VTable offset = 12
     BYVAL wSrcType AS WORD _                           ' __in DBTYPE wSrcType
   , BYVAL wDstType AS WORD _                           ' __in DBTYPE wDstType
   , BYVAL cbSrcLength AS DWORD _                       ' __in DBLENGTH cbSrcLength
   , BYREF pcbDstLength AS DWORD _                      ' __inout DBLENGTH *pcbDstLength
   , BYVAL pSrc AS DWORD _                              ' __in void *pSrc
   , BYREF pDst AS DWORD _                              ' __out void *pDst
   , BYVAL cbDstMaxLength AS DWORD _                    ' __in DBLENGTH cbDstMaxLength
   , BYVAL dbsSrcStatus AS DWORD _                      ' __in DBSTATUS dbsSrcStatus
   , BYREF pdbsStatus AS DWORD _                        ' __out DBSTATUS *pdbsStatus
   , BYVAL bPrecision AS BYTE _                         ' __in BYTE bPrecision
   , BYVAL bScale AS BYTE _                             ' __in BYTE bScale
   , BYVAL dwFlags AS BYTE _                            ' __in DBDATACONVERT dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CanConvert ( _                                ' VTable offset = 16
     BYVAL wSrcType AS WORD _                           ' __in DBTYPE wSrcType
   , BYVAL wDstType AS WORD _                           ' __in DBTYPE wDstType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConversionType ( _                         ' VTable offset = 20
     BYVAL wSrcType AS WORD _                           ' __in DBTYPE wSrcType
   , BYVAL wDstType AS WORD _                           ' __in DBTYPE wDstType
   , BYVAL pcbSrcLength AS DWORD _                      ' __in DBLENGTH *pcbSrcLength
   , BYREF pcbDstLength AS DWORD _                      ' __out DBLENGTH *pcbDstLength
   , BYVAL pSrc AS DWORD _                              ' __in void *pSrc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDataConvert_INTERFACE_DEFINED__ */


' ########################################################################################
' IDCInfo interface
' IID = 0C733A9C-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDCInfo_INTERFACE_DEFINED)
%IDCInfo_INTERFACE_DEFINED = 1

'typedef DWORD DCINFOTYPE;

' DCINFOTYPEENUM
%DCINFOTYPE_VERSION = 1

' // Size = 24 bytes
TYPE DCINFO QWORD FILL
   eInfoType AS DWORD        ' DCINFOTYPE
   vData     AS tagVARIANT   ' VARIANT
END TYPE

$IID_IDCInfo = GUID$("{0C733A9C-2A1C-11CE-ADE5-00AA0044773D}")

INTERFACE IDCInfo $IID_IDCInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetInfo ( _                                   ' VTable offset = 12
     BYVAL cInfo AS DWORD _                             ' __in ULONG cInfo
   , BYREF rgeInfoType AS DWORD _                       ' __in DCINFOTYPE rgeInfoType[  ]
   , BYREF prgInfo AS DWORD _                           ' __out DCINFO **prgInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInfo ( _                                   ' VTable offset = 16
     BYVAL cInfo AS DWORD _                             ' __in ULONG cInfo
   , BYREF rgInfo AS DCINFO _                           ' __in DCINFO rgInfo[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDCInfo_INTERFACE_DEFINED__ */

'#include <poppack.h>     // restore original structure packing
