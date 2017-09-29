' ########################################################################################
' Microsoft Windows
' File: D2DUtils.inc
' Contents: Direct2D helper functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D2DUTILS_INC = 1

#INCLUDE ONCE "d2d1.inc"

' ========================================================================================
' Creates a Direct2D bitmap from the specified file name.
' Parameters:
'   pRenderTarget
'     [in] A ID2D1RenderTarget object.
'   pIWICFactory
'     [in] A IWICImagingFactory object.
'   pwszFileName
'     [in] A pointer to a null-terminated unicode string that specifies the path of the
'     file to open.
'   dwDestinationWidth
'     [in] The destination width.
'   dwDestinationHeight
'     [in] The destination height.
'   ppBitmap
'     [out] A ID2D1Bitmap object.
' Return value:
'   If the function succeeds, it returns %S_OK; otherwise, an HRESULT value.
' ========================================================================================

FUNCTION D2D_LoadBitmapFromFile ( _
   BYVAL pRenderTarget AS ID2D1RenderTarget, _
   BYVAL pIWICFactory AS IWICImagingFactory, _
   BYREF wszFileName AS WSTRINGZ, _
   BYVAL dwDestinationWidth AS DWORD, _
   BYVAL dwDestinationHeight AS DWORD, _
   BYREF ppBitmap AS ID2D1Bitmap _
   ) AS LONG

   LOCAL hr AS LONG
   LOCAL pDecoder AS IWICBitmapDecoder
   LOCAL pSource AS IWICBitmapFrameDecode
   LOCAL pStream AS IWICStream
   LOCAL pConverter AS IWICFormatConverter
   LOCAL pScaler AS IWICBitmapScaler

   hr = pIWICFactory.CreateDecoderFromFilename( _
        wszFileName, _
        BYVAL %NULL, _
        %GENERIC_READ, _
        %WICDecodeMetadataCacheOnLoad, _
        pDecoder _
        )

   IF SUCCEEDED(hr) THEN
      ' // Create the initial frame.
      hr = pDecoder.GetFrame(0, pSource)
   END IF

   IF SUCCEEDED(hr) THEN
      ' // Convert the image format to 32bppPBGRA
      ' // (DXGI_FORMAT_B8G8R8A8_UNORM + D2D1_ALPHA_MODE_PREMULTIPLIED).
      hr = pIWICFactory.CreateFormatConverter(pConverter)
   END IF

   IF SUCCEEDED(hr) THEN
      ' // If a new width or height was specified, create an
      ' // IWICBitmapScaler and use it to resize the image.
      IF dwDestinationWidth <> 0 OR dwDestinationHeight <> 0 THEN
         LOCAL dwOriginalWidth, dwOriginalHeight AS DWORD
         hr = pSource.GetSize(dwOriginalWidth, dwOriginalHeight)
         IF SUCCEEDED(hr) THEN
            LOCAL scalar AS SINGLE
            IF dwDestinationWidth = 0 THEN
               scalar = dwDestinationHeight / dwOriginalHeight
               dwDestinationWidth = scalar * dwOriginalWidth
            ELSEIF dwDestinationHeight = 0 THEN
               scalar = dwDestinationWidth / dwOriginalWidth
               dwDestinationHeight = scalar * dwOriginalHeight
            END IF
            hr = pIWICFactory.CreateBitmapScaler(pScaler)
            IF SUCCEEDED(hr) THEN
               hr = pScaler.Initialize( _
                    pSource, _
                    dwDestinationWidth, _
                    dwDestinationHeight, _
                    %WICBitmapInterpolationModeCubic _
                    )
            END IF
            IF SUCCEEDED(hr) THEN
               hr = pConverter.Initialize( _
                    pScaler, _
                    $GUID_WICPixelFormat32bppPBGRA, _
                    %WICBitmapDitherTypeNone, _
                    NOTHING, _
                    0.0!, _
                    %WICBitmapPaletteTypeMedianCut _
                    )
            END IF
         END IF
      ELSE
         hr = pConverter.Initialize( _
              pSource, _
              $GUID_WICPixelFormat32bppPBGRA, _
              %WICBitmapDitherTypeNone, _
              NOTHING, _
              0.0!, _
              %WICBitmapPaletteTypeMedianCut _
              )
      END IF
   END IF

   IF SUCCEEDED(hr) THEN
      ' // Create a Direct2D bitmap from the WIC bitmap.
      hr = pRenderTarget.CreateBitmapFromWicBitmap( _
           pConverter, _
           BYVAL %NULL, _
           ppBitmap _
           )
   END IF

   pDecoder   = NOTHING
   pSource    = NOTHING
   pStream    = NOTHING
   pConverter = NOTHING
   pScaler    = NOTHING

   FUNCTION = hr

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a Direct2D bitmap from a resource in the application resource file.
' Parameters:
'   pRenderTarget
'     [in] A ID2D1RenderTarget object.
'   pIWICFactory
'     [in] A IWICImagingFactory object.
'   hModule
'     [in] A handle to the module whose portable executable file or an accompanying MUI file
'     contains the resource. If this parameter is NULL, the function searches the module
'     used to create the current process.
'   pwszResourceName
'     [in] The name of the resource. Alternately, rather than a pointer, this parameter can be
'     MAKEINTRESOURCE(ID), where ID is the integer identifier of the resource.
'   dwResourceType
'     [in] The resource type. Alternately, rather than a pointer, this parameter can be
'     MAKEINTRESOURCE(ID), where ID is the integer identifier of the given resource type.
'   dwDestinationWidth
'     [in] The destination width.
'   dwDestinationHeight
'     [in] The destination height.
'   ppBitmap
'     [out] A ID2D1Bitmap object.
' Return value:
'   If the function succeeds, it returns %S_OK; otherwise, an HRESULT value.
' ========================================================================================

FUNCTION D2D_LoadBitmapFromResource ( _
   BYVAL pRenderTarget AS ID2D1RenderTarget, _
   BYVAL pIWICFactory AS IWICImagingFactory, _
   BYVAL hModule AS DWORD, _
   BYREF wszResourceName AS WSTRINGZ, _
   BYREF wszResourceType AS WSTRINGZ, _
   BYVAL dwDestinationWidth AS DWORD, _
   BYVAL dwDestinationHeight AS DWORD, _
   BYREF ppBitmap AS ID2D1Bitmap _
   ) AS LONG

   LOCAL hr AS LONG
   LOCAL pDecoder AS IWICBitmapDecoder
   LOCAL pSource AS IWICBitmapFrameDecode
   LOCAL pStream AS IWICStream
   LOCAL pConverter AS IWICFormatConverter
   LOCAL pScaler AS IWICBitmapScaler

   LOCAL hImageRes AS DWORD
   LOCAL hImageResData AS DWORD
   LOCAL pImageFile AS DWORD
   LOCAL dwImageFileSize AS DWORD

   ' // Locate the resource.
   hImageRes = FindResourceW(hModule, wszResourceName, wszResourceType)

   hr = IIF&(hImageRes, %S_OK, %E_FAIL)
   IF SUCCEEDED(hr) THEN
      ' // Load the resource.
      hImageResData = LoadResource(hModule, hImageRes)
      hr = IIF&(hImageResData, %S_OK, %E_FAIL)
   END IF
   IF SUCCEEDED(hr) THEN
      ' // Lock it to get a system memory pointer.
      pImageFile = LockResource(hImageResData)
      hr = IIF&(pImageFile, %S_OK, %E_FAIL)
   END IF
   IF SUCCEEDED(hr) THEN
      ' // Calculate the size.
      dwImageFileSize = SizeofResource(hModule, hImageRes)
      hr = IIF&(dwImageFileSize, %S_OK, %E_FAIL)
   END IF
   IF SUCCEEDED(hr) THEN
      ' // Create a WIC stream to map onto the memory.
      hr = pIWICFactory.CreateStream(pStream)
   END IF
   IF SUCCEEDED(hr) THEN
      ' // Initialize the stream with the memory pointer and size.
      hr = pStream.InitializeFromMemory( _
           pImageFile, _
           dwImageFileSize _
           )
   END IF
   IF SUCCEEDED(hr) THEN
      ' // Create a decoder for the stream.
      hr = pIWICFactory.CreateDecoderFromStream( _
           pStream, _
           BYVAL %NULL, _
           %WICDecodeMetadataCacheOnLoad, _
           pDecoder _
           )
   END IF
   IF SUCCEEDED(hr) THEN
      ' // Create the initial frame.
      hr = pDecoder.GetFrame(0, pSource)
   END IF
   IF SUCCEEDED(hr) THEN
      ' // Convert the image format to 32bppPBGRA
      ' // (DXGI_FORMAT_B8G8R8A8_UNORM + D2D1_ALPHA_MODE_PREMULTIPLIED).
      hr = pIWICFactory.CreateFormatConverter(pConverter)
   END IF
   IF SUCCEEDED(hr) THEN
      ' // If a new width or height was specified, create an
      ' // IWICBitmapScaler and use it to resize the image.
      IF dwDestinationWidth <> 0 OR dwDestinationHeight <> 0 THEN
         LOCAL dwOriginalWidth, dwOriginalHeight AS DWORD
         hr = pSource.GetSize(dwOriginalWidth, dwOriginalHeight)
         IF SUCCEEDED(hr) THEN
            LOCAL scalar AS SINGLE
            IF dwDestinationWidth = 0 THEN
               scalar = dwDestinationHeight / dwOriginalHeight
               dwDestinationWidth = scalar * dwOriginalWidth
            ELSEIF dwDestinationHeight = 0 THEN
               scalar = dwDestinationWidth / dwOriginalWidth
               dwDestinationHeight = scalar * dwOriginalHeight
            END IF
            hr = pIWICFactory.CreateBitmapScaler(pScaler)
            IF SUCCEEDED(hr) THEN
               hr = pScaler.Initialize( _
                    pSource, _
                    dwDestinationWidth, _
                    dwDestinationHeight, _
                    %WICBitmapInterpolationModeCubic _
                    )
            END IF
            IF SUCCEEDED(hr) THEN
               hr = pConverter.Initialize( _
                    pScaler, _
                    $GUID_WICPixelFormat32bppPBGRA, _
                    %WICBitmapDitherTypeNone, _
                    NOTHING, _
                    0.0!, _
                    %WICBitmapPaletteTypeMedianCut _
                    )
            END IF
         END IF
      ELSE
         hr = pConverter.Initialize( _
              pSource, _
              $GUID_WICPixelFormat32bppPBGRA, _
              %WICBitmapDitherTypeNone, _
              NOTHING, _
              0.0!, _
              %WICBitmapPaletteTypeMedianCut _
              )
      END IF
   END IF
   IF SUCCEEDED(hr) THEN
      ' //create a Direct2D bitmap from the WIC bitmap.
      hr = pRenderTarget.CreateBitmapFromWicBitmap( _
           pConverter, _
           BYVAL %NULL, _
           ppBitmap _
           )
   END IF

   pDecoder   = NOTHING
   pSource    = NOTHING
   pStream    = NOTHING
   pConverter = NOTHING
   pScaler    = NOTHING

   FUNCTION = hr

END FUNCTION
' ========================================================================================
