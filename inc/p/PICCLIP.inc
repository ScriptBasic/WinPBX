' ########################################################################################
' Microsoft Windows
' File: PicClip.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: PicClip
' Version: 1.1, Locale ID = 0
' Documentation string: Microsoft PictureClip Control 6.0 (SP3)
' Path: C:\Software\OCXs\PICCLP32.OCX
' Library GUID: {27395F88-0C0C-101B-A3C9-08002B2F49FB}
' Help file: C:\Software\OCXs\PICCLP98.CHM
' ########################################################################################

#INCLUDE THIS ONCE
%PICCLIP_INC = 1

$RTLKEY_PICTURECLIP = "6FB38640-6AC7-11cf-8ADB-00AA00C00905"

#INCLUDE ONCE "ocidl.inc"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_PictureClip = GUID$("{27395F85-0C0C-101B-A3C9-08002B2F49FB}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_DPicClipEvents = GUID$("{27395F87-0C0C-101B-A3C9-08002B2F49FB}")
$IID_IPicClip = GUID$("{4D6CC9B0-DF77-11CF-8E74-00A0C90F26F8}")

' ========================================================================================
' ErrorConstants enum
' IID: {D9C1A720-E599-11CF-A8B0-00AA00A71809}
' Error Contants
' ========================================================================================

%picOutOfMemory                                         = 7            ' &H7
%picSetNotSupported                                     = 383          ' &H17F
%picSetNotPermitted                                     = 383          ' &H17F
%picGetNotSupported                                     = 394          ' &H18A
%picInvalidPictureFormat                                = 32000        ' &H7D00
%picDisplayContext                                      = 32001        ' &H7D01
%picMemDevContext                                       = 32002        ' &H7D02
%picBitmap                                              = 32003        ' &H7D03
%picSelBitmapObj                                        = 32004        ' &H7D04
%picIntPicStruct                                        = 32005        ' &H7D05
%picBadIndex                                            = 32006        ' &H7D06
%picNoPicSize                                           = 32007        ' &H7D07
%picBitmapsOnly                                         = 32008        ' &H7D08
%picBadClip                                             = 32010        ' &H7D0A
%picGetObjFailed                                        = 32012        ' &H7D0C
%picClipBounds                                          = 32015        ' &H7D0F
%picCellTooSmall                                        = 32016        ' &H7D10
%picRowNotPositive                                      = 32017        ' &H7D11
%picColNotPositive                                      = 32018        ' &H7D12
%picStretchXNegative                                    = 32019        ' &H7D13
%picStretchYNegative                                    = 32020        ' &H7D14
%picNoPicture                                           = 32021        ' &H7D15

' ########################################################################################
' Interface name = IPicClip
' IID = {4D6CC9B0-DF77-11CF-8E74-00A0C90F26F8}
' Microsoft PictureClip Control 6.0 (SP3)
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IPicClip_INTERFACE_DEFINED)
    %IPicClip_INTERFACE_DEFINED = 1

INTERFACE IPicClip $IID_IPicClip

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Picture_ <0> ( _                        ' VTable offset = 28
   ) AS IPictureDisp                                    ' __out_retval IPictureDisp** ppPicture
   ' =====================================================================================
   PROPERTY SET Picture_ <0> ( _                        ' VTable offset = 32
     BYVAL ppPicture AS IPictureDisp _                  ' __in IPictureDisp* ppPicture
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Picture_ <0> ( _                 ' VTable offset = 36
     BYVAL ppPicture AS IPictureDisp _                  ' __in IPictureDisp* ppPicture
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CellHeight <11> ( _                     ' VTable offset = 40
   ) AS INTEGER                                         ' __out_retval short* psCellHeight
   ' =====================================================================================
   PROPERTY SET CellHeight <11> ( _                     ' VTable offset = 44
     BYVAL psCellHeight AS INTEGER _                    ' __in short psCellHeight
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CellWidth <10> ( _                      ' VTable offset = 48
   ) AS INTEGER                                         ' __out_retval short* psCellWidth
   ' =====================================================================================
   PROPERTY SET CellWidth <10> ( _                      ' VTable offset = 52
     BYVAL psCellWidth AS INTEGER _                     ' __in short psCellWidth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Clip <14> ( _                           ' VTable offset = 56
   ) AS IPictureDisp                                    ' __out_retval IPictureDisp** ppPictureDisp
   ' =====================================================================================
   PROPERTY SET Clip <14> ( _                           ' VTable offset = 60
     BYVAL ppPictureDisp AS IPictureDisp _              ' __in IPictureDisp* ppPictureDisp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Clip <14> ( _                    ' VTable offset = 64
     BYVAL ppPictureDisp AS IPictureDisp _              ' __in IPictureDisp* ppPictureDisp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ClipHeight <7> ( _                      ' VTable offset = 68
   ) AS INTEGER                                         ' __out_retval short* psClipHeight
   ' =====================================================================================
   PROPERTY SET ClipHeight <7> ( _                      ' VTable offset = 72
     BYVAL psClipHeight AS INTEGER _                    ' __in short psClipHeight
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ClipWidth <6> ( _                       ' VTable offset = 76
   ) AS INTEGER                                         ' __out_retval short* psClipWidth
   ' =====================================================================================
   PROPERTY SET ClipWidth <6> ( _                       ' VTable offset = 80
     BYVAL psClipWidth AS INTEGER _                     ' __in short psClipWidth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ClipX <4> ( _                           ' VTable offset = 84
   ) AS INTEGER                                         ' __out_retval short* psClipX
   ' =====================================================================================
   PROPERTY SET ClipX <4> ( _                           ' VTable offset = 88
     BYVAL psClipX AS INTEGER _                         ' __in short psClipX
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ClipY <5> ( _                           ' VTable offset = 92
   ) AS INTEGER                                         ' __out_retval short* psClipY
   ' =====================================================================================
   PROPERTY SET ClipY <5> ( _                           ' VTable offset = 96
     BYVAL psClipY AS INTEGER _                         ' __in short psClipY
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Cols <3> ( _                            ' VTable offset = 100
   ) AS INTEGER                                         ' __out_retval short* psCols
   ' =====================================================================================
   PROPERTY SET Cols <3> ( _                            ' VTable offset = 104
     BYVAL psCols AS INTEGER _                          ' __in short psCols
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Height <13> ( _                         ' VTable offset = 108
   ) AS INTEGER                                         ' __out_retval short* psHeight
   ' =====================================================================================
   PROPERTY SET Height <13> ( _                         ' VTable offset = 112
     BYVAL psHeight AS INTEGER _                        ' __in short psHeight
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Picture <1> ( _                         ' VTable offset = 116
   ) AS IPictureDisp                                    ' __out_retval IPictureDisp** ppPictureDisp
   ' =====================================================================================
   PROPERTY SET Picture <1> ( _                         ' VTable offset = 120
     BYVAL ppPictureDisp AS IPictureDisp _              ' __in IPictureDisp* ppPictureDisp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Picture <1> ( _                  ' VTable offset = 124
     BYVAL ppPictureDisp AS IPictureDisp _              ' __in IPictureDisp* ppPictureDisp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Rows <2> ( _                            ' VTable offset = 128
   ) AS INTEGER                                         ' __out_retval short* psRows
   ' =====================================================================================
   PROPERTY SET Rows <2> ( _                            ' VTable offset = 132
     BYVAL psRows AS INTEGER _                          ' __in short psRows
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StretchX <8> ( _                        ' VTable offset = 136
   ) AS INTEGER                                         ' __out_retval short* psStretchX
   ' =====================================================================================
   PROPERTY SET StretchX <8> ( _                        ' VTable offset = 140
     BYVAL psStretchX AS INTEGER _                      ' __in short psStretchX
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StretchY <9> ( _                        ' VTable offset = 144
   ) AS INTEGER                                         ' __out_retval short* psStretchY
   ' =====================================================================================
   PROPERTY SET StretchY <9> ( _                        ' VTable offset = 148
     BYVAL psStretchY AS INTEGER _                      ' __in short psStretchY
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Width <12> ( _                          ' VTable offset = 152
   ) AS INTEGER                                         ' __out_retval short* psWidth
   ' =====================================================================================
   PROPERTY SET Width <12> ( _                          ' VTable offset = 156
     BYVAL psWidth AS INTEGER _                         ' __in short psWidth
   )                                                    ' void
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 160
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GraphicCell <15> ( _                    ' VTable offset = 164
     BYVAL sIndex AS INTEGER _                          ' __in short sIndex
   ) AS IPictureDisp                                    ' __out_retval IPictureDisp** ppPictureDisp
   ' =====================================================================================
   PROPERTY SET GraphicCell <15> ( _                    ' VTable offset = 168
     BYVAL sIndex AS INTEGER _                          ' __in short sIndex
   , BYVAL ppPictureDisp AS IPictureDisp _              ' __in IPictureDisp* ppPictureDisp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_GraphicCell <15> ( _             ' VTable offset = 172
     BYVAL sIndex AS INTEGER _                          ' __in short sIndex
   , BYVAL ppPictureDisp AS IPictureDisp _              ' __in IPictureDisp* ppPictureDisp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Hwnd <-515> ( _                         ' VTable offset = 176
   ) AS LONG                                            ' __out_retval OLE_HANDLE* phWnd
   ' =====================================================================================
   PROPERTY SET Hwnd <-515> ( _                         ' VTable offset = 180
     BYVAL phWnd AS LONG _                              ' __in OLE_HANDLE phWnd
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPicClip_INTERFACE_DEFINED__ */
