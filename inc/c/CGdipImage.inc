' ########################################################################################
' Microsoft Windows
' File: CGdipImage.inc
' Contents: GDI+ image class.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CGDIPIMAGE_INC = 1

' ########################################################################################
' CGdipImage Class
' ########################################################################################
CLASS CGdipImage

   INSTANCE m_hStatus AS LONG
   INSTANCE m_pImage AS DWORD

   ' =====================================================================================
   ' Cleanup
   ' =====================================================================================
   CLASS METHOD Destroy
      IF m_pImage THEN GdipDisposeImage(m_pImage)
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   ' IGdipImage interface.
   ' #####################################################################################
   INTERFACE IGdipImage : INHERIT IAutomation

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to the Image object.
   ' =====================================================================================
   PROPERTY GET Ptr () THREADSAFE AS DWORD
      PROPERTY = m_pImage
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the Image object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      IF m_pImage THEN GdipDisposeImage(m_pImage)
      m_pImage = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Creates an Image object based on a file.
   ' =====================================================================================
   METHOD ImageFromFile (BYREF wszFileName AS WSTRINGZ, OPTIONAL BYVAL useIcm AS LONG) THREADSAFE AS LONG
      IF m_pImage THEN GdipDisposeImage(m_pImage)
      IF useIcm THEN
         m_hStatus = GdipLoadImageFromFileICM(wszFileName, m_pImage)
      ELSE
         m_hStatus = GdipLoadImageFromFile(wszFileName, m_pImage)
      END IF
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates an Image object based on a stram.
   ' =====================================================================================
   METHOD ImageFromStream (BYVAL pStream AS IStream, OPTIONAL BYVAL useIcm AS LONG) THREADSAFE AS LONG
      IF m_pImage THEN GdipDisposeImage(m_pImage)
      IF useIcm THEN
         m_hStatus = GdipLoadImageFromStreamICM(pStream, m_pImage)
      ELSE
         m_hStatus = GdipLoadImageFromStream(pStream, m_pImage)
      END IF
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new Image object based on this Image object.
   ' =====================================================================================
   METHOD Clone () THREADSAFE AS IGdipImage
      LOCAL pCloneImage AS IGdipImage
      LOCAL pCloneImagePtr AS DWORD
      m_hStatus = GdipCloneImage(m_pImage, pCloneImagePtr)
      pCloneImage = CLASS "CGdipImage"
      IF ISNOTHING(pCloneImage) THEN EXIT METHOD
      pCloneImage.Ptr = pCloneImagePtr
      METHOD = pCloneImage
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of the parameter list for a specified image encoder
   ' =====================================================================================
   METHOD GetEncoderParameterListSize (BYREF clsidEncoder AS GUID) THREADSAFE AS DWORD
      LOCAL dwSize AS DWORD
      m_hStatus = GdipGetEncoderParameterListSize(m_pImage, clsidEncoder, dwSize)
      METHOD = dwSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a list of the parameters supported by a specified image encoder.
   ' =====================================================================================
   METHOD GetEncoderParameterList (BYREF clsidEncoder AS GUID, BYVAL dwSize AS DWORD, BYREF buffer AS EncoderParameters) THREADSAFE AS LONG
      m_hStatus = GdipGetEncoderParameterList(m_pImage, clsidEncoder, dwSize, buffer)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Saves this image to a file.
   ' =====================================================================================
   METHOD SaveToFile (BYREF wszFileName AS WSTRINGZ, BYREF clsidEncoder AS GUID, BYREF encoderParams AS EncoderParameters) THREADSAFE AS LONG
      m_hStatus = GdipSaveImageToFile(m_pImage, wszFileName, clsidEncoder, encoderParams)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Saves this image to a stream.
   ' =====================================================================================
   METHOD SaveToStream (BYVAL pStream AS IStream, BYREF clsidEncoder AS GUID, BYREF encoderParams AS EncoderParameters) THREADSAFE AS LONG
      m_hStatus = GdipSaveImageToStream(m_pImage, pStream, clsidEncoder, encoderParams)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a frame to a file or stream specified in a previous call to the SaveToFile or
   ' SaveToStream methods. Use this method to save selected frames from a multiple-frame
   ' image to another multiple-frame image.
   ' =====================================================================================
   METHOD SaveAdd (BYREF encoderParams AS EncoderParameters) THREADSAFE AS LONG
      m_hStatus = GdipSaveAdd(m_pImage, encoderParams)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a frame to a file or stream specified in a previous call to the SaveToFile or
   ' SaveToStream methods.
   ' =====================================================================================
   METHOD SaveAddImage (BYVAL pNewImage AS IGdipImage, BYREF encoderParams AS EncoderParameters) THREADSAFE AS LONG
      IF ISNOTHING(pNewImage) THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      m_hStatus = GdipSaveAddImage(m_pImage, pNewImage.Ptr, encoderParams)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the type (bitmap or metafile) of this Image object.
   ' =====================================================================================
   METHOD GetType () THREADSAFE AS LONG
      LOCAL nType AS LONG
      m_hStatus = GdipGetImageType(m_pImage, nType)
      METHOD = nType
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the width and height of this image.
   ' =====================================================================================
   METHOD GetPhysicalDimension (BYREF tSize AS SizeF) THREADSAFE AS LONG
      IF VARPTR(tSize) = 0 THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      LOCAL rWidth, rHeight AS SINGLE
      m_hStatus = GdipGetImageDimension(m_pImage, rWidth, rHeight)
      tSize.Width = rWidth
      tSize.Height = rHeight
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the bounding rectangle for this image.
   ' =====================================================================================
   METHOD GetBounds (BYREF srcRect AS RectF, BYREF srcUnit AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipGetImageBounds(m_pImage, srcRect, srcUnit)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the width, in pixels, of this image.
   ' =====================================================================================
   METHOD GetWidth () THREADSAFE AS DWORD
      LOCAL nWidth AS LONG
      m_hStatus = GdipGetImageWidth(m_pImage, nWidth)
      METHOD = nWidth
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the height, in pixels, of this image.
   ' =====================================================================================
   METHOD GetHeight () THREADSAFE AS DWORD
      LOCAL nHeight AS LONG
      m_hStatus = GdipGetImageHeight(m_pImage, nHeight)
      METHOD = nHeight
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the height, in pixels, of this image.
   ' =====================================================================================
   METHOD GetHorizontalResolution () THREADSAFE AS SINGLE
      LOCAL resolution AS SINGLE
      m_hStatus = GdipGetImageHorizontalResolution(m_pImage, resolution)
      METHOD = resolution
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the width, in pixels, of this image.
   ' =====================================================================================
   METHOD GetVerticalResolution () THREADSAFE AS SINGLE
      LOCAL resolution AS SINGLE
      m_hStatus = GdipGetImageVerticalResolution(m_pImage, resolution)
      METHOD = resolution
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a set of flags that indicate certain attributes of this Image object.
   ' =====================================================================================
   METHOD GetFlags () THREADSAFE AS DWORD
      LOCAL flags AS DWORD
      m_hStatus = GdipGetImageFlags(m_pImage, flags)
      METHOD = flags
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a globally unique identifier ( GUID) that identifies the format of this Image
   ' object. GUIDs that identify various file formats are defined in Gdiplusimaging.inc.
   ' =====================================================================================
   METHOD GetRawFormat (BYREF guidformat AS GUID) THREADSAFE AS LONG
      m_hStatus = GdipGetImageRawFormat(m_pImage, guidformat)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the pixel format of this Image object.
   ' =====================================================================================
   METHOD GetPixelFormat () THREADSAFE AS LONG
      LOCAL pxformat AS LONG
      m_hStatus = GdipGetImagePixelFormat(m_pImage, pxformat)
      METHOD = pxformat
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the pixel format of this Image object.
   ' =====================================================================================
   METHOD GetPaletteSize () THREADSAFE AS LONG
      LOCAL nSize AS LONG
      m_hStatus = GdipGetImagePaletteSize(m_pImage, nSize)
      METHOD = nSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the ColorPalette of this Image object.
   ' =====================================================================================
   METHOD GetPalette (BYREF palette AS ColorPalette, BYVAL nSize AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipGetImagePalette(m_pImage, palette, nSize)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the ColorPalette of this Image object.
   ' =====================================================================================
   METHOD SetPalette (BYREF palette AS ColorPalette) THREADSAFE AS LONG
      m_hStatus = GdipSetImagePalette(m_pImage, palette)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a thumbnail image from this Image object.
   ' =====================================================================================
   METHOD GetThumbnailImage (BYVAL thumbWidth AS DWORD, BYVAL thumbHeight AS DWORD, OPTIONAL BYVAL pCallback AS DWORD, BYVAL callbackData AS DWORD) THREADSAFE AS IGdipImage
      LOCAL thumbimage AS IGdipImage
      LOCAL thumbimageptr AS DWORD
      m_hStatus = GdipGetImageThumbnail(m_pImage, thumbWidth, thumbHeight, thumbimageptr, pCallback, callbackData)
      thumbimage = CLASS "CGdipImage"
      IF ISNOTHING(thumbimage) THEN EXIT METHOD
      thumbimage.Ptr = thumbimageptr
      METHOD = thumbimage
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of frame dimensions in this Image object.
   ' =====================================================================================
   METHOD GetFrameDimensionsCount () THREADSAFE AS DWORD
      LOCAL nCount AS DWORD
      m_hStatus = GdipImageGetFrameDimensionsCount(m_pImage, nCount)
      METHOD = nCount
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the identifiers for the frame dimensions of this Image object.
   ' =====================================================================================
   METHOD GetFrameDimensionsList (BYREF dimensionIDs AS GUID, BYVAL nCount AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipImageGetFrameDimensionsList(m_pImage, dimensionIDs, nCount)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of frames in a specified dimension of this Image object.
   ' =====================================================================================
   METHOD GetFrameCount (BYREF dimensionID AS GUID) THREADSAFE AS DWORD
      LOCAL nCount AS DWORD
      m_hStatus = GdipImageGetFrameCount(m_pImage, dimensionID, nCount)
      METHOD = nCount
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Selects the frame in this Image object specified by a dimension and an index.
   ' =====================================================================================
   METHOD SelectActiveFrame (BYREF dimensionID AS GUID, BYVAL frameIndex AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipImageSelectActiveFrame(m_pImage, dimensionID, frameIndex)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Rotates and flips this image.
   ' =====================================================================================
   METHOD RotateFlip (BYVAL rotateFlipType AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipImageRotateFlip(m_pImage, rotateFlipType)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of properties (pieces of metadata) stored in this Image object.
   ' =====================================================================================
   METHOD GetPropertyCount () THREADSAFE AS DWORD
      LOCAL numProperty AS DWORD
      m_hStatus = GdipGetPropertyCount(m_pImage, numProperty)
      METHOD = numProperty
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of properties (pieces of metadata) stored in this Image object.
   ' =====================================================================================
   METHOD GetPropertyIdList (BYVAL numOfProperty AS DWORD, BYREF list AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipGetPropertyIdList(m_pImage, numOfProperty, list)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of a specified property item of this Image object.
   ' =====================================================================================
   METHOD GetPropertyItemSize (BYVAL propId AS DWORD) THREADSAFE AS DWORD
      LOCAL nSize AS DWORD
      m_hStatus = GdipGetPropertyItemSize(m_pImage, propId, nSize)
      METHOD = nSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a specified property item (piece of metadata) from this Image object.
   ' =====================================================================================
   METHOD GetPropertyItem (BYVAL propId AS DWORD, BYVAL propSize AS DWORD, BYREF buffer AS PropertyItem) THREADSAFE AS LONG
      m_hStatus = GdipGetPropertyItem(m_pImage, propId, propSize, buffer)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the total size, in bytes, of all the property items stored in this Image object.
   ' The GetPropertySize method also gets the number of property items stored in this Image object.
   ' =====================================================================================
   METHOD GetPropertySize (BYREF totalBufferSize AS DWORD, BYREF numProperties AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipGetPropertySize(m_pImage, totalBufferSize, numProperties)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets all the property items (metadata) stored in the specified Image object.
   ' =====================================================================================
   METHOD GetAllPropertyItems (BYVAL totalBufferSize AS DWORD, BYVAL numProperties AS DWORD, BYREF allItems AS PropertyItem) THREADSAFE AS LONG
      m_hStatus = GdipGetAllPropertyItems(m_pImage, totalBufferSize, numProperties, allItems)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets all the property items (metadata) stored in the specified Image object.
   ' =====================================================================================
   METHOD RemovePropertyItem (BYVAL propId AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipRemovePropertyItem(m_pImage, propId)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a property item (piece of metadata) for this Image object. If the item already
   ' exists, then its contents are updated; otherwise, a new item is added.
   ' =====================================================================================
   METHOD SetPropertyItem (BYREF tItem AS PropertyItem) THREADSAFE AS LONG
      m_hStatus = GdipSetPropertyItem(m_pImage, tItem)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

#IF (%GDIPVER >= &H0110)


   ' =====================================================================================
   ' Sets the object whose Abort function is called periodically during time-consuming rendering operation.
   ' =====================================================================================
   METHOD SetAbort (BYVAL pIAbort AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipImageSetAbort(m_pImage, pIAbort)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves the description and the data size of the first metadata item in this Image object.
   ' =====================================================================================
   METHOD FindFirstItem (BYREF tItem AS ImageItemData) THREADSAFE AS LONG
      m_hStatus = GdipFindFirstImageItem(m_pImage, tItem)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The GdipFindNextImageItem function is used along with the GdipFindFirstImageItem
   ' function to enumerate the metadata items stored in this Image object. The
   ' GdipFindNextImageItem function retrieves the description and the data size of the
   ' next metadata item in the Image object.
   ' =====================================================================================
   METHOD FindNextItem (BYREF tItem AS ImageItemData) THREADSAFE AS LONG
      m_hStatus = GdipFindNextImageItem(m_pImage, tItem)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets one piece of metadata from the specified Image object.
   ' =====================================================================================
   METHOD GetItemData (BYREF tItem AS ImageItemData) THREADSAFE AS LONG
      m_hStatus = GdipGetImageItemData(m_pImage, tItem)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

#ENDIF   ' //(GDIPVER >= 0x0110)

   END INTERFACE

   ' #####################################################################################
   ' IGdipBitmap interface.
   ' Inherits from IGdipImage.
   ' #####################################################################################

   INTERFACE IGdipBitmap : INHERIT IAutomation

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to the Image object.
   ' =====================================================================================
   PROPERTY GET Ptr () THREADSAFE AS DWORD
      PROPERTY = m_pImage
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the Image object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      IF m_pImage THEN GdipDisposeImage(m_pImage)
      m_pImage = pPtr
   END PROPERTY
   ' =====================================================================================

   ' *** IGdipImage methods ***

   ' =====================================================================================
   ' Creates an Image object based on a file.
   ' =====================================================================================
   METHOD ImageFromFile (BYREF wszFileName AS WSTRINGZ, BYVAL useIcm AS LONG) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.ImageFromFile(wszFileName, useIcm)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates an Image object based on a stram.
   ' =====================================================================================
   METHOD ImageFromStream (BYVAL pStream AS IStream, BYVAL useIcm AS LONG) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.ImageFromStream(pStream, useIcm)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new Image object based on this Image object.
   ' =====================================================================================
   METHOD Clone () THREADSAFE AS IGdipImage
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.Clone
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of the parameter list for a specified image encoder
   ' =====================================================================================
   METHOD GetEncoderParameterListSize (BYREF clsidEncoder AS GUID) THREADSAFE AS DWORD
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetEncoderParameterListSize(clsidEncoder)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a list of the parameters supported by a specified image encoder.
   ' =====================================================================================
   METHOD GetEncoderParameterList (BYREF clsidEncoder AS GUID, BYVAL dwSize AS DWORD, BYREF buffer AS EncoderParameters) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetEncoderParameterList(clsidEncoder, dwSize, buffer)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Saves this image to a file.
   ' =====================================================================================
   METHOD SaveToFile (BYREF wszFileName AS WSTRINGZ, BYREF clsidEncoder AS GUID, BYREF encoderParams AS EncoderParameters) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.SaveToFile(wszFileName, clsidEncoder, encoderParams)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Saves this image to a stream.
   ' =====================================================================================
   METHOD SaveToStream (BYVAL pStream AS IStream, BYREF clsidEncoder AS GUID, BYREF encoderParams AS EncoderParameters) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.SaveToStream(pStream, clsidEncoder, encoderParams)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a frame to a file or stream specified in a previous call to the SaveToFile or
   ' SaveToStream methods. Use this method to save selected frames from a multiple-frame
   ' image to another multiple-frame image.
   ' =====================================================================================
   METHOD SaveAdd (BYREF encoderParams AS EncoderParameters) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.SaveAdd(encoderParams)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a frame to a file or stream specified in a previous call to the SaveToFile or
   ' SaveToStream methods.
   ' =====================================================================================
   METHOD SaveAddImage (BYVAL pNewImage AS IGdipImage, BYREF encoderParams AS EncoderParameters) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.SaveAddImage(pNewImage, encoderParams)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the type (bitmap or metafile) of this Image object.
   ' =====================================================================================
   METHOD GetType () THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetType
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the width and height of this image.
   ' =====================================================================================
   METHOD GetPhysicalDimension (BYREF tSize AS SizeF) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetPhysicalDimension(tSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the bounding rectangle for this image.
   ' =====================================================================================
   METHOD GetBounds (BYREF srcRect AS RectF, BYREF srcUnit AS LONG) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetBounds(srcRect, srcUnit)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the width, in pixels, of this image.
   ' =====================================================================================
   METHOD GetWidth () THREADSAFE AS DWORD
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetWidth
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the height, in pixels, of this image.
   ' =====================================================================================
   METHOD GetHeight () THREADSAFE AS DWORD
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetHeight
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the height, in pixels, of this image.
   ' =====================================================================================
   METHOD GetHorizontalResolution () THREADSAFE AS SINGLE
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetHorizontalResolution
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the width, in pixels, of this image.
   ' =====================================================================================
   METHOD GetVerticalResolution () THREADSAFE AS SINGLE
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetVerticalResolution
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a set of flags that indicate certain attributes of this Image object.
   ' =====================================================================================
   METHOD GetFlags () THREADSAFE AS DWORD
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetFlags
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a globally unique identifier ( GUID) that identifies the format of this Image
   ' object. GUIDs that identify various file formats are defined in Gdiplusimaging.inc.
   ' =====================================================================================
   METHOD GetRawFormat (BYREF guidformat AS GUID) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetRawFormat(guidformat)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the pixel format of this Image object.
   ' =====================================================================================
   METHOD GetPixelFormat () THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetPixelFormat
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the pixel format of this Image object.
   ' =====================================================================================
   METHOD GetPaletteSize () THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetPaletteSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the ColorPalette of this Image object.
   ' =====================================================================================
   METHOD GetPalette (BYREF palette AS ColorPalette, BYVAL nSize AS LONG) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetPalette(palette, nSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the ColorPalette of this Image object.
   ' =====================================================================================
   METHOD SetPalette (BYREF palette AS ColorPalette) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.SetPalette(palette)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a thumbnail image from this Image object.
   ' =====================================================================================
   METHOD GetThumbnailImage (BYVAL thumbWidth AS DWORD, BYVAL thumbHeight AS DWORD, BYVAL pCallback AS DWORD, BYVAL callbackData AS DWORD) THREADSAFE AS IGdipImage
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetThumbnailImage(thumbWidth, thumbHeight, pCallback, callbackData)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of frame dimensions in this Image object.
   ' =====================================================================================
   METHOD GetFrameDimensionsCount () THREADSAFE AS DWORD
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetFrameDimensionsCount
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the identifiers for the frame dimensions of this Image object.
   ' =====================================================================================
   METHOD GetFrameDimensionsList (BYREF dimensionIDs AS GUID, BYVAL nCount AS DWORD) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetFrameDimensionsList(dimensionIDs, nCount)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of frames in a specified dimension of this Image object.
   ' =====================================================================================
   METHOD GetFrameCount (BYREF dimensionID AS GUID) THREADSAFE AS DWORD
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetFrameCount(dimensionID)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Selects the frame in this Image object specified by a dimension and an index.
   ' =====================================================================================
   METHOD SelectActiveFrame (BYREF dimensionID AS GUID, BYVAL frameIndex AS DWORD) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.SelectActiveFrame(dimensionID, frameIndex)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Rotates and flips this image.
   ' =====================================================================================
   METHOD RotateFlip (BYVAL rotateFlipType AS LONG) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.RotateFlip(rotateFlipType)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of properties (pieces of metadata) stored in this Image object.
   ' =====================================================================================
   METHOD GetPropertyCount () THREADSAFE AS DWORD
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetPropertyCount
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of properties (pieces of metadata) stored in this Image object.
   ' =====================================================================================
   METHOD GetPropertyIdList (BYVAL numOfProperty AS DWORD, BYREF list AS DWORD) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetPropertyIdList(numOfProperty, list)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of a specified property item of this Image object.
   ' =====================================================================================
   METHOD GetPropertyItemSize (BYVAL propId AS DWORD) THREADSAFE AS DWORD
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetPropertyItemSize(propId)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a specified property item (piece of metadata) from this Image object.
   ' =====================================================================================
   METHOD GetPropertyItem (BYVAL propId AS DWORD, BYVAL propSize AS DWORD, BYREF buffer AS PropertyItem) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetPropertyItem(propId, propSize, buffer)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the total size, in bytes, of all the property items stored in this Image object.
   ' The GetPropertySize method also gets the number of property items stored in this Image object.
   ' =====================================================================================
   METHOD GetPropertySize (BYREF totalBufferSize AS DWORD, BYREF numProperties AS DWORD) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetPropertySize(totalBufferSize, numProperties)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets all the property items (metadata) stored in the specified Image object.
   ' =====================================================================================
   METHOD GetAllPropertyItems (BYVAL totalBufferSize AS DWORD, BYVAL numProperties AS DWORD, BYREF allItems AS PropertyItem) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetAllPropertyItems(totalBufferSize, numProperties, allItems)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets all the property items (metadata) stored in the specified Image object.
   ' =====================================================================================
   METHOD RemovePropertyItem (BYVAL propId AS DWORD) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.RemovePropertyItem(propId)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a property item (piece of metadata) for this Image object. If the item already
   ' exists, then its contents are updated; otherwise, a new item is added.
   ' =====================================================================================
   METHOD SetPropertyItem (BYREF tItem AS PropertyItem) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.SetPropertyItem(tItem)
   END METHOD
   ' =====================================================================================

#IF (%GDIPVER >= &H0110)

   ' =====================================================================================
   ' Retrieves the description and the data size of the first metadata item in this Image object.
   ' =====================================================================================
   METHOD FindFirstItem (BYREF tItem AS ImageItemData) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.FindFirstItem(tItem)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The GdipFindNextImageItem function is used along with the GdipFindFirstImageItem
   ' function to enumerate the metadata items stored in this Image object. The
   ' GdipFindNextImageItem function retrieves the description and the data size of the
   ' next metadata item in the Image object.
   ' =====================================================================================
   METHOD FindNextItem (BYREF tItem AS ImageItemData) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.FindNextItem(tItem)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets one piece of metadata from the specified Image object.
   ' =====================================================================================
   METHOD GetItemData (BYREF tItem AS ImageItemData) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetItemData(tItem)
   END METHOD
   ' =====================================================================================

#ENDIF   ' //(GDIPVER >= 0x0110)

   ' *** IGdipBitmap methods ***

   ' =====================================================================================
   ' Creates a Bitmap object based on an image file.
   ' =====================================================================================
   METHOD BitmapFromFile (BYREF wszFileName AS WSTRINGZ, OPTIONAL BYVAL useIcm AS LONG) THREADSAFE AS LONG
      IF m_pImage THEN GdipDisposeImage(m_pImage)
      IF useIcm THEN
         m_hStatus = GdipCreateBitmapFromFileICM(wszFileName, m_pImage)
      ELSE
         m_hStatus = GdipCreateBitmapFromFile(wszFileName, m_pImage)
      END IF
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Bitmap object based on an IStream interface.
   ' =====================================================================================
   METHOD BitmapFromStream (BYVAL pStream AS IStream, OPTIONAL BYVAL useIcm AS LONG) THREADSAFE AS LONG
      IF m_pImage THEN GdipDisposeImage(m_pImage)
      IF useIcm THEN
         m_hStatus = GdipCreateBitmapFromStreamICM(pStream, m_pImage)
      ELSE
         m_hStatus = GdipCreateBitmapFromStream(pStream, m_pImage)
      END IF
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Bitmap object based on an array of bytes along with size and format information.
   ' =====================================================================================
   METHOD BitmapFromScan0 (BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, BYVAL stride AS LONG, BYVAL pxFormat AS LONG, OPTIONAL BYREF scan0 AS BYTE) THREADSAFE AS LONG
      IF m_pImage THEN GdipDisposeImage(m_pImage)
      m_hStatus = GdipCreateBitmapFromScan0(nWidth, nHeight, stride, pxFormat, scan0, m_pImage)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Bitmap object based on size and format information.
   ' =====================================================================================
   METHOD BitmapFromScan (BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, BYVAL pxFormat AS LONG) THREADSAFE AS LONG
      IF m_pImage THEN GdipDisposeImage(m_pImage)
      m_hStatus = GdipCreateBitmapFromScan0(nWidth, nHeight, 0, pxFormat, BYVAL %NULL, m_pImage)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Bitmap object based on a Graphics object, a width, and a height.
   ' =====================================================================================
   METHOD BitmapFromGraphics (BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, BYVAL pTarget AS IGdipGraphics) THREADSAFE AS LONG
      IF m_pImage THEN GdipDisposeImage(m_pImage)
      m_hStatus = GdipCreateBitmapFromGraphics(nWidth, nHeight, pTarget.Ptr, m_pImage)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Bitmap object based on a DirectDraw surface. The Bitmap object maintains a
   ' reference to the DirectDraw surface until the Bitmap object is deleted or goes out of scope.
   ' =====================================================================================
   METHOD BitmapFromIDirectDrawSurface7 (BYVAL surface AS IDirectDrawSurface7) THREADSAFE AS LONG
      IF m_pImage THEN GdipDisposeImage(m_pImage)
      m_hStatus = GdipCreateBitmapFromDirectDrawSurface(surface, m_pImage)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Bitmap object based on a BITMAPINFO structure and an array of pixel data.
   ' =====================================================================================
   METHOD BitmapFromBITMAPINFO (BYREF gdiBitmapInfo AS BITMAPINFO, BYVAL gdiBitmapData AS DWORD) THREADSAFE AS LONG
      IF m_pImage THEN GdipDisposeImage(m_pImage)
      m_hStatus = GdipCreateBitmapFromGdiDib(gdiBitmapInfo, gdiBitmapData, m_pImage)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Bitmap object based on a handle to a Windows Windows Graphics Device
   ' Interface (GDI) bitmap and a handle to a GDI palette.
   ' =====================================================================================
   METHOD BitmapFromHBITMAP (BYVAL hbm AS DWORD, BYVAL hpal AS DWORD) THREADSAFE AS LONG
      IF m_pImage THEN GdipDisposeImage(m_pImage)
      m_hStatus = GdipCreateBitmapFromHBITMAP(hbm, hpal, m_pImage)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Bitmap object based on an icon.
   ' =====================================================================================
   METHOD BitmapFromHICON (BYVAL hicon AS DWORD) THREADSAFE AS LONG
      IF m_pImage THEN GdipDisposeImage(m_pImage)
      m_hStatus = GdipCreateBitmapFromHICON(hicon, m_pImage)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Bitmap object based on an application or DLL instance handle and the name of a bitmap.
   ' =====================================================================================
   METHOD BitmapFromResource (BYVAL hInstance AS DWORD, BYREF bitmapName AS WSTRINGZ) THREADSAFE AS LONG
      IF m_pImage THEN GdipDisposeImage(m_pImage)
      m_hStatus = GdipCreateBitmapFromResource(hInstance, bitmapName, m_pImage)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Windows Graphics Device Interface (GDI) bitmap from this Bitmap object.
   ' =====================================================================================
   METHOD GetHBITMAP (BYVAL colorBackground AS DWORD, BYREF hbmReturn AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipCreateHBITMAPFromBitmap(m_pImage, hbmReturn, colorBackground)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates an icon from this Bitmap object.
   ' =====================================================================================
   METHOD GetHICON (BYREF hiconReturn AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipCreateHICONFromBitmap(m_pImage, hiconReturn)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new Bitmap object by copying a portion of this bitmap.
   ' =====================================================================================
   METHOD CloneArea (BYVAL x AS SINGLE, BYVAL y AS SINGLE, BYVAL nWidth AS SINGLE, BYVAL nHeight AS SINGLE, BYVAL pxFormat AS LONG) THREADSAFE AS IGdipImage
      LOCAL pCloneBitmap AS IGdipImage
      LOCAL pCloneBitmapPtr AS DWORD
      m_hStatus = GdipCloneBitmapArea(x, y, nWidth, nHeight, pxFormat, m_pImage, pCloneBitmapPtr)
      pCloneBitmap = CLASS "CGdipImage"
      IF ISNOTHING(pCloneBitmap) THEN EXIT METHOD
      pCloneBitmap.Ptr = pCloneBitmapPtr
      METHOD = pCloneBitmap
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Locks a rectangular portion of this bitmap and provides a temporary buffer that you
   ' can use to read or write pixel data in a specified format. Any pixel data that you
   ' write to the buffer is copied to the Bitmap object when you call UnlockBits.
   ' =====================================================================================
   METHOD LockBits (BYREF rc AS RECT, BYVAL flags AS DWORD, BYVAL pxFormat AS LONG, BYREF lockedBitmapData AS BitmapData) THREADSAFE AS LONG
      m_hStatus = GdipBitmapLockBits(m_pImage, rc, flags, pxFormat, lockedBitmapData)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Unlocks a portion of this bitmap that was previously locked by a call to LockBits.
   ' =====================================================================================
   METHOD UnlockBits (BYREF lockedBitmapData AS BitmapData) THREADSAFE AS LONG
      m_hStatus = GdipBitmapUnlockBits(m_pImage, lockedBitmapData)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the color of a specified pixel in this bitmap.
   ' =====================================================================================
   METHOD GetPixel (BYVAL x AS LONG, BYVAL y AS LONG, BYREF colour AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipBitmapGetPixel(m_pImage, x, y, colour)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the color of a specified pixel in this bitmap.
   ' =====================================================================================
   METHOD SetPixel (BYVAL x AS LONG, BYVAL y AS LONG, BYVAL colour AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipBitmapSetPixel(m_pImage, x, y, colour)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

#IF (%GDIPVER >= &H0110)

   ' =====================================================================================
   ' Converts a bitmap to a specified pixel format. The original pixel data in the bitmap
   ' is replaced by the new pixel data.
   ' =====================================================================================
   METHOD ConvertFormat (BYVAL pxFormat AS LONG, BYVAL dithertype AS LONG, BYVAL palettetype AS LONG, BYREF palette AS ColorPalette, BYVAL alphaThresholdPercent AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipBitmapConvertFormat(m_pImage, pxFormat, dithertype, palettetype, palette, alphaThresholdPercent)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a standard, optimal, or custom color palette.
   ' =====================================================================================
   METHOD InitializePalette (BYREF palette AS ColorPalette, BYVAL palettetype AS LONG, BYREF optimalColors AS LONG, BYVAL useTransparentColor AS LONG, BYVAL pBitmap AS IGdipBitmap) THREADSAFE AS LONG
      m_hStatus = GdipInitializePalette(palette, palettetype, optimalColors, useTransparentColor, _
                  IIF(ISOBJECT(pBitmap), pBitmap.Ptr, %NULL))
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new Bitmap object by applying a specified effect to an existing Bitmap object.
   ' =====================================================================================
   METHOD CreateApplyEffect (BYREF pInputs AS IGdipBitmap, BYVAL numInputs AS LONG, BYVAL pEffect AS IGdipEffect, _
   BYREF ROI AS RECT, BYREF outputRect AS RECT, BYREF pOutputBitmap AS IGdipBitmap) THREADSAFE AS LONG

      IF numInputs < 0 OR ISNOTHING(pEffect) OR ISNOTHING(pOutputBitmap) THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      REDIM rgInputs(numInputs - 1) AS DWORD
      LOCAL i AS LONG
      FOR i = 0 TO numInputs - 1
         rgInputs(i) = pInputs.Ptr
      NEXT
      LOCAL pOutputBitmapPtr AS DWORD
      LOCAL auxData AS DWORD, auxDataSize AS LONG
      m_hStatus = GdipBitmapCreateApplyEffect(rgInputs(0), numInputs, pEffect.Ptr, ROI, outputRect, _
                  pOutputBitmapPtr, pEffect.GetUseAuxData, auxData, auxDataSize)
      IF m_hStatus = %StatusOk THEN
         IF pEffect.GetAuxData THEN GdipFree(pEffect.GetAuxData)
         pEffect.SetAuxData(auxData)
         pEFfect.SetAuxDataSize(auxDataSize)
         pOutputBitmap.Ptr = pOutputBitmapPtr
      END IF
      METHOD = m_hStatus

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Alters this Bitmap object by applying a specified effect.
   ' =====================================================================================
   METHOD ApplyEffect (BYVAL pEffect AS IGdipEffect, BYREF ROI AS RECT) THREADSAFE AS LONG
      IF ISNOTHING(pEffect) OR VARPTR(roi) = 0 THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      LOCAL auxData AS DWORD, auxDataSize AS LONG
      m_hStatus = GdipBitmapApplyEffect(m_pImage, pEffect.Ptr, ROI, pEffect.GetUseAuxData, auxData, auxDataSize)
      IF m_hStatus = %StatusOk THEN
         IF pEffect.GetAuxData THEN GdipFree(pEffect.GetAuxData)
         pEffect.SetAuxData(auxData)
         pEFfect.SetAuxDataSize(auxDataSize)
      END IF
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns one or more histograms for specified color channels of this Bitmap object.
   ' =====================================================================================
   METHOD GetHistogram (BYVAL nFormat AS LONG, BYVAL NumberOfEntries AS DWORD, BYREF channel0 AS DWORD, BYREF channel1 AS DWORD, BYREF channel2 AS DWORD, BYREF channel3 AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipBitmapGetHistogram(m_pImage, nFormat, NumberOfEntries, channel0, channel1, channel2, channel3)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of elements (in an array of UINTs) that you must allocate before you call the
   ' GetHistogram method of a Bitmap object.
   ' =====================================================================================
   METHOD GetHistogramSize (BYVAL nFormat AS LONG, BYREF NumberOfEntries AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipBitmapGetHistogramSize(nFormat, NumberOfEntries)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

#ENDIF   ' // (GDIPVER >= 0x0110)

   ' =====================================================================================
   ' Sets the resolution of this Bitmap object.
   ' =====================================================================================
   METHOD SetResolution (BYVAL xdpi AS SINGLE, BYVAL ydpi AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipBitmapSetResolution(m_pImage, xdpi, ydpi)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   END INTERFACE

   ' #####################################################################################
   ' IGdipMetafile interface.
   ' Inherits from IGdipImage.
   ' #####################################################################################
   INTERFACE IGdipMetafile : INHERIT IAutomation

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to the Image object.
   ' =====================================================================================
   PROPERTY GET Ptr () THREADSAFE AS DWORD
      PROPERTY = m_pImage
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the Image object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      IF m_pImage THEN GdipDisposeImage(m_pImage)
      m_pImage = pPtr
   END PROPERTY
   ' =====================================================================================

   ' *** IGdipImage methods ***

   ' =====================================================================================
   ' Creates an Image object based on a file.
   ' =====================================================================================
   METHOD ImageFromFile (BYREF wszFileName AS WSTRINGZ, BYVAL useIcm AS LONG) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.ImageFromFile(wszFileName, useIcm)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates an Image object based on a stram.
   ' =====================================================================================
   METHOD ImageFromStream (BYVAL pStream AS IStream, BYVAL useIcm AS LONG) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.ImageFromStream(pStream, useIcm)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new Image object based on this Image object.
   ' =====================================================================================
   METHOD Clone () THREADSAFE AS IGdipImage
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.Clone
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of the parameter list for a specified image encoder
   ' =====================================================================================
   METHOD GetEncoderParameterListSize (BYREF clsidEncoder AS GUID) THREADSAFE AS DWORD
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetEncoderParameterListSize(clsidEncoder)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a list of the parameters supported by a specified image encoder.
   ' =====================================================================================
   METHOD GetEncoderParameterList (BYREF clsidEncoder AS GUID, BYVAL dwSize AS DWORD, BYREF buffer AS EncoderParameters) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetEncoderParameterList(clsidEncoder, dwSize, buffer)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Saves this image to a file.
   ' =====================================================================================
   METHOD Save (BYREF wszFileName AS WSTRINGZ, BYREF clsidEncoder AS GUID, OPTIONAL BYREF encoderParams AS EncoderParameters) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.SaveToFile(wszFileName, clsidEncoder, encoderParams)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Saves this image to a file.
   ' =====================================================================================
   METHOD SaveToFile (BYREF wszFileName AS WSTRINGZ, BYREF clsidEncoder AS GUID, OPTIONAL BYREF encoderParams AS EncoderParameters) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.SaveToFile(wszFileName, clsidEncoder, encoderParams)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Saves this image to a stream.
   ' =====================================================================================
   METHOD SaveToStream (BYVAL pStream AS IStream, BYREF clsidEncoder AS GUID, OPTIONAL BYREF encoderParams AS EncoderParameters) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.SaveToStream(pStream, clsidEncoder, encoderParams)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a frame to a file or stream specified in a previous call to the SaveToFile or
   ' SaveToStream methods. Use this method to save selected frames from a multiple-frame
   ' image to another multiple-frame image.
   ' =====================================================================================
   METHOD SaveAdd (BYREF encoderParams AS EncoderParameters) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.SaveAdd(encoderParams)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a frame to a file or stream specified in a previous call to the SaveToFile or
   ' SaveToStream methods.
   ' =====================================================================================
   METHOD SaveAddImage (BYVAL pNewImage AS IGdipImage, BYREF encoderParams AS EncoderParameters) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.SaveAddImage(pNewImage, encoderParams)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the type (bitmap or metafile) of this Image object.
   ' =====================================================================================
   METHOD GetType () THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetType
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the width and height of this image.
   ' =====================================================================================
   METHOD GetPhysicalDimension (BYREF tSize AS SizeF) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetPhysicalDimension(tSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the bounding rectangle for this image.
   ' =====================================================================================
   METHOD GetBounds (BYREF srcRect AS RectF, BYREF srcUnit AS LONG) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetBounds(srcRect, srcUnit)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the width, in pixels, of this image.
   ' =====================================================================================
   METHOD GetWidth () THREADSAFE AS DWORD
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetWidth
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the height, in pixels, of this image.
   ' =====================================================================================
   METHOD GetHeight () THREADSAFE AS DWORD
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetHeight
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the height, in pixels, of this image.
   ' =====================================================================================
   METHOD GetHorizontalResolution () THREADSAFE AS SINGLE
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetHorizontalResolution
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the width, in pixels, of this image.
   ' =====================================================================================
   METHOD GetVerticalResolution () THREADSAFE AS SINGLE
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetVerticalResolution
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a set of flags that indicate certain attributes of this Image object.
   ' =====================================================================================
   METHOD GetFlags () THREADSAFE AS DWORD
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetFlags
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a globally unique identifier ( GUID) that identifies the format of this Image
   ' object. GUIDs that identify various file formats are defined in Gdiplusimaging.inc.
   ' =====================================================================================
   METHOD GetRawFormat (BYREF guidformat AS GUID) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetRawFormat(guidformat)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the pixel format of this Image object.
   ' =====================================================================================
   METHOD GetPixelFormat () THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetPixelFormat
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the pixel format of this Image object.
   ' =====================================================================================
   METHOD GetPaletteSize () THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetPaletteSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the ColorPalette of this Image object.
   ' =====================================================================================
   METHOD GetPalette (BYREF palette AS ColorPalette, BYVAL nSize AS LONG) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetPalette(palette, nSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the ColorPalette of this Image object.
   ' =====================================================================================
   METHOD SetPalette (BYREF palette AS ColorPalette) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.SetPalette(palette)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a thumbnail image from this Image object.
   ' =====================================================================================
   METHOD GetThumbnailImage (BYVAL thumbWidth AS DWORD, BYVAL thumbHeight AS DWORD, BYVAL pCallback AS DWORD, BYVAL callbackData AS DWORD) THREADSAFE AS IGdipImage
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetThumbnailImage(thumbWidth, thumbHeight, pCallback, callbackData)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of frame dimensions in this Image object.
   ' =====================================================================================
   METHOD GetFrameDimensionsCount () THREADSAFE AS DWORD
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetFrameDimensionsCount
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the identifiers for the frame dimensions of this Image object.
   ' =====================================================================================
   METHOD GetFrameDimensionsList (BYREF dimensionIDs AS GUID, BYVAL nCount AS DWORD) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetFrameDimensionsList(dimensionIDs, nCount)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of frames in a specified dimension of this Image object.
   ' =====================================================================================
   METHOD GetFrameCount (BYREF dimensionID AS GUID) THREADSAFE AS DWORD
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetFrameCount(dimensionID)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Selects the frame in this Image object specified by a dimension and an index.
   ' =====================================================================================
   METHOD SelectActiveFrame (BYREF dimensionID AS GUID, BYVAL frameIndex AS DWORD) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.SelectActiveFrame(dimensionID, frameIndex)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Rotates and flips this image.
   ' =====================================================================================
   METHOD RotateFlip (BYVAL rotateFlipType AS LONG) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.RotateFlip(rotateFlipType)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of properties (pieces of metadata) stored in this Image object.
   ' =====================================================================================
   METHOD GetPropertyCount () THREADSAFE AS DWORD
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetPropertyCount
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of properties (pieces of metadata) stored in this Image object.
   ' =====================================================================================
   METHOD GetPropertyIdList (BYVAL numOfProperty AS DWORD, BYREF list AS DWORD) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetPropertyIdList(numOfProperty, list)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size, in bytes, of a specified property item of this Image object.
   ' =====================================================================================
   METHOD GetPropertyItemSize (BYVAL propId AS DWORD) THREADSAFE AS DWORD
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetPropertyItemSize(propId)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a specified property item (piece of metadata) from this Image object.
   ' =====================================================================================
   METHOD GetPropertyItem (BYVAL propId AS DWORD, BYVAL propSize AS DWORD, BYREF buffer AS PropertyItem) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetPropertyItem(propId, propSize, buffer)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the total size, in bytes, of all the property items stored in this Image object.
   ' The GetPropertySize method also gets the number of property items stored in this Image object.
   ' =====================================================================================
   METHOD GetPropertySize (BYREF totalBufferSize AS DWORD, BYREF numProperties AS DWORD) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetPropertySize(totalBufferSize, numProperties)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets all the property items (metadata) stored in the specified Image object.
   ' =====================================================================================
   METHOD GetAllPropertyItems (BYVAL totalBufferSize AS DWORD, BYVAL numProperties AS DWORD, BYREF allItems AS PropertyItem) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetAllPropertyItems(totalBufferSize, numProperties, allItems)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets all the property items (metadata) stored in the specified Image object.
   ' =====================================================================================
   METHOD RemovePropertyItem (BYVAL propId AS DWORD) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.RemovePropertyItem(propId)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a property item (piece of metadata) for this Image object. If the item already
   ' exists, then its contents are updated; otherwise, a new item is added.
   ' =====================================================================================
   METHOD SetPropertyItem (BYREF tItem AS PropertyItem) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.SetPropertyItem(tItem)
   END METHOD
   ' =====================================================================================

#IF (%GDIPVER >= &H0110)

   ' =====================================================================================
   ' Retrieves the description and the data size of the first metadata item in this Image object.
   ' =====================================================================================
   METHOD FindFirstItem (BYREF tItem AS ImageItemData) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.FindFirstItem(tItem)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The GdipFindNextImageItem function is used along with the GdipFindFirstImageItem
   ' function to enumerate the metadata items stored in this Image object. The
   ' GdipFindNextImageItem function retrieves the description and the data size of the
   ' next metadata item in the Image object.
   ' =====================================================================================
   METHOD FindNextItem (BYREF tItem AS ImageItemData) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.FindNextItem(tItem)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets one piece of metadata from the specified Image object.
   ' =====================================================================================
   METHOD GetItemData (BYREF tItem AS ImageItemData) THREADSAFE AS LONG
      LOCAL pImage AS IGdipImage
      pImage = ME
      METHOD = pImage.GetItemData(tItem)
   END METHOD
   ' =====================================================================================

#ENDIF   ' //(GDIPVER >= 0x0110)

   ' *** IGdipMetafile methods ***

   ' =====================================================================================
   ' Creates a Windows GDI+ Metafile object for recording. The format will be placeable metafile.
   ' =====================================================================================
   METHOD MetafileFromWmf (BYVAL hWmf AS DWORD, BYREF wmfPFH AS WmfPlaceableFileHeader, OPTIONAL BYVAL deleteWmf AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipCreateMetafileFromWmf(hWmf, deleteWmf, wmfPFH, m_pImage)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Windows GDI+ Metafile::Metafile object for playback based on a Windows
   ' Graphics Device Interface (GDI) Enhanced Metafile (EMF) file.
   ' =====================================================================================
   METHOD MetafileFromEmf (BYVAL hEmf AS DWORD, OPTIONAL BYVAL deleteEmf AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipCreateMetafileFromEmf(hEmf, deleteEmf, m_pImage)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Metafile object for playback.
   ' =====================================================================================
   METHOD MetafileFromFile (BYREF wszFileName AS WSTRINGZ) THREADSAFE AS LONG
      m_hStatus = GdipCreateMetafileFromFile(wszFileName, m_pImage)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Metafile object for playback.
   ' =====================================================================================
   METHOD MetafileFromWmfFile (BYREF wszFileName AS WSTRINGZ, BYREF wmfPFH AS WmfPlaceableFileHeader) THREADSAFE AS LONG
      m_hStatus = GdipCreateMetafileFromWmfFile(wszFileName, wmfPFH, m_pImage)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Metafile object from an IStream interface for playback.
   ' =====================================================================================
   METHOD MetafileFromStream (BYVAL pStream AS IStream) THREADSAFE AS LONG
      m_hStatus = GdipCreateMetafileFromStream(pStream, m_pImage)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Metafile object for recording
   ' =====================================================================================
   METHOD RecordMetafile (BYVAL referenceHdc AS DWORD, OPTIONAL BYVAL nType AS LONG, BYREF description AS WSTRINGZ) THREADSAFE AS LONG
      IF nType = 0 THEN nType = %EmfTypeEmfPlusDual
      m_hStatus = GdipRecordMetafile(referenceHdc, nType, BYVAL %NULL, %MetafileFrameUnitGdi, description, m_pImage)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Metafile object for recording
   ' =====================================================================================
   METHOD RecordMetafileRect (BYVAL referenceHdc AS DWORD, BYREF frmRect AS RectF, OPTIONAL BYVAL frameUnit AS LONG, BYVAL nType AS LONG, BYREF description AS WSTRINGZ) THREADSAFE AS LONG
      IF frameUnit = 0 THEN frameUnit = %MetafileFrameUnitGdi
      IF nType = 0 THEN nType = %EmfTypeEmfPlusDual
      m_hStatus = GdipRecordMetafile(referenceHdc, nType, frmRect, frameUnit, description, m_pImage)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Metafile object for recording
   ' =====================================================================================
   METHOD RecordMetafileFileName (BYREF wszFileName AS WSTRINGZ, BYVAL referenceHdc AS DWORD, OPTIONAL BYVAL nType AS LONG, BYREF description AS WSTRINGZ) THREADSAFE AS LONG
      IF nType = 0 THEN nType = %EmfTypeEmfPlusDual
      m_hStatus = GdipRecordMetafileFileName(wszFileName, referenceHdc, nType, BYVAL %NULL, %MetafileFrameUnitGdi, description, m_pImage)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Metafile object for recording
   ' =====================================================================================
   METHOD RecordMetafileFileNameRect (BYREF wszFileName AS WSTRINGZ, BYVAL referenceHdc AS DWORD, BYREF frmRect AS RectF, _
   OPTIONAL BYVAL frameUnit AS LONG, BYVAL nType AS LONG, BYREF description AS WSTRINGZ) THREADSAFE AS LONG
      IF frameUnit = 0 THEN frameUnit = %MetafileFrameUnitGdi
      IF nType = 0 THEN nType = %EmfTypeEmfPlusDual
      m_hStatus = GdipRecordMetafileFileName(wszFileName, referenceHdc, nType, frmRect, frameUnit, description, m_pImage)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Metafile object for recording to an IStream interface.
   ' =====================================================================================
   METHOD RecordMetafileStream (BYVAL pStream AS IStream, BYVAL referenceHdc AS DWORD, OPTIONAL BYVAL nType AS LONG, BYREF description AS WSTRINGZ) THREADSAFE AS LONG
      IF nType = 0 THEN nType = %EmfTypeEmfPlusDual
      m_hStatus = GdipRecordMetafileStream(pStream, referenceHdc, nType, BYVAL %NULL, %MetafileFrameUnitGdi, description, m_pImage)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Metafile object for recording to an IStream interface.
   ' =====================================================================================
   METHOD RecordMetafileStreamRect (BYVAL pStream AS IStream, BYVAL referenceHdc AS DWORD, BYREF frmRect AS RectF, _
   OPTIONAL BYVAL frameUnit AS LONG, BYVAL nType AS LONG, BYREF description AS WSTRINGZ) THREADSAFE AS LONG
      IF frameUnit = 0 THEN frameUnit = %MetafileFrameUnitGdi
      IF nType = 0 THEN nType = %EmfTypeEmfPlusDual
      m_hStatus = GdipRecordMetafileStream(pStream, referenceHdc, nType, frmRect, frameUnit, description, m_pImage)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The GetMetafileHeader method gets the metafile header of this metafile.
   ' =====================================================================================
   METHOD GetMetafileHeaderFromWmf (BYVAL hWmf AS DWORD, BYREF wmfPFH AS WmfPlaceableFileHeader, BYREF mh AS MetafileHeader) THREADSAFE AS LONG
      m_hStatus = GdipGetMetafileHeaderFromWmf(hWmf, wmfPFH, mh)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the metafile header of the specified metafile.
   ' =====================================================================================
   METHOD GetMetafileHeaderFromEmf (BYVAL hEmf AS DWORD, BYREF mh AS MetafileHeader) THREADSAFE AS LONG
      m_hStatus = GdipGetMetafileHeaderFromEmf(hEmf, mh)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the metafile header of the specified file.
   ' =====================================================================================
   METHOD GetMetafileHeaderFromFile (BYREF wsFileName AS WSTRINGZ, BYREF mh AS MetafileHeader) THREADSAFE AS LONG
      m_hStatus = GdipGetMetafileHeaderFromFile(wsFileName, mh)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the metafile header of the specified stream.
   ' =====================================================================================
   METHOD GetMetafileHeaderFromStream (BYVAL pStream AS IStream, BYREF mh AS MetafileHeader) THREADSAFE AS LONG
      m_hStatus = GdipGetMetafileHeaderFromStream(pStream, mh)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the metafile header of this metafile. [Default method.]
   ' =====================================================================================
   METHOD GetMetafileHeader (BYREF mh AS MetafileHeader) THREADSAFE AS LONG
      m_hStatus = GdipGetMetafileHeaderFromMetafile(m_pImage, mh)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a Windows handle to an Enhanced Metafile (EMF) file.
   ' // Once this method is called, the Metafile object is in an invalid state and can no
   ' // longer be used.  It is the responsiblity of the caller to invoke DeleteEnhMetaFile
   ' // to delete this hEmf.
   ' =====================================================================================
   METHOD GetHENHMETAFILE () THREADSAFE AS DWORD
      LOCAL hEmf AS DWORD
      m_hStatus = GdipGetHemfFromMetafile(m_pImage, hEmf)
      METHOD = hEmf
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Plays a metafile record.
   ' // Used in conjuction with EnumerateMetafile to play an EMF+
   ' // The data must be DWORD aligned if it's an EMF or EMF+.  It must be
   ' // WORD aligned if it's a WMF.
   ' =====================================================================================
   METHOD PlayRecord (BYVAL recordType AS LONG, BYVAL flags AS DWORD, BYVAL dataSize AS DWORD, BYREF rgData AS BYTE) THREADSAFE AS DWORD
      m_hStatus = GdipPlayMetafileRecord(m_pImage, recordType, flags, dataSize, rgData)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the resolution for certain brush bitmaps that are stored in this metafile.
   ' // If you're using a printer HDC for the metafile, but you want the
   ' // metafile rasterized at screen resolution, then use this API to set
   ' // the rasterization dpi of the metafile to the screen resolution,
   ' // e.g. 96 dpi or 120 dpi.
   ' =====================================================================================
   METHOD SetDownLevelRasterizationLimit (BYVAL metafileRasterizationLimitDpi AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipSetMetafileDownLevelRasterizationLimit(m_pImage, metafileRasterizationLimitDpi)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the rasterization limit currently set for this metafile. The rasterization limit
   ' is the resolution used for certain brush bitmaps that are stored in the metafile.
   ' =====================================================================================
   METHOD GetDownLevelRasterizationLimit () THREADSAFE AS DWORD
      LOCAL metafileRasterizationLimitDpi AS DWORD
      m_hStatus = GdipGetMetafileDownLevelRasterizationLimit(m_pImage, metafileRasterizationLimitDpi)
      METHOD = metafileRasterizationLimitDpi
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Converts an enhanced-format metafile to a Windows Metafile Format (WMF) metafile and
   ' stores the converted records in a specified buffer.
   ' =====================================================================================
   METHOD EmfToWmfBits (BYVAL hEmf AS DWORD, BYVAL cbData16 AS DWORD, BYREF pData16 AS BYTE, OPTIONAL BYVAL vMapMode AS VARIANT, BYVAL vFlags AS VARIANT) THREADSAFE AS LONG
      LOCAL iMapMode AS LONG
      LOCAL eFlags AS LONG
      IF ISMISSING(vMapMode) THEN iMapMode = %MM_ANISOTROPIC ELSE iMapMode = VARIANT#(vMapMode)
      IF ISMISSING(vFlags) THEN eFlags = %EmfToWmfBitsFlagsDefault ELSE eFlags = VARIANT#(vFlags)
      m_hStatus = GdipEmfToWmfBits(hEmf, cbData16, pData16, iMapMode, eFlags)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

#IF (%GDIPVER >= &H0110)

   ' =====================================================================================
   ' Converts this Metafile object to the EMF+ format.
   ' =====================================================================================
   METHOD ConvertToEmfPlus (BYVAL refGraphics AS IGdipGraphics, OPTIONAL BYREF conversionFailureFlag AS LONG, BYVAL vemfType AS VARIANT, BYREF description AS WSTRINGZ) THREADSAFE AS LONG
      LOCAL pMetafile AS DWORD
      LOCAL emfType AS LONG
      IF ISMISSING(vemfType) THEN emfType = %EmfTypeEmfPlusOnly ELSE emfType = VARIANT#(vemfType)
      m_hStatus = GdipConvertToEmfPlus(refGraphics.Ptr, m_pImage, conversionFailureFlag, emfType, description, pMetafile)
      IF pMetafile <> %NULL THEN
         IF m_hStatus = %StatusOK THEN
            IF m_pImage THEN GdipDisposeImage(m_pImage)
            m_pImage = pMetafile
         ELSE
            IF m_pImage THEN GdipDisposeImage(pMetafile)
         END IF
      END IF
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Converts this Metafile object to the EMF+ format.
   ' =====================================================================================
   METHOD ConvertToEmfPlusToFile (BYVAL refGraphics AS IGdipGraphics, BYREF wszFileName AS WSTRINGZ, _
   OPTIONAL BYREF conversionFailureFlag AS LONG, BYVAL vemfType AS VARIANT, BYREF description AS WSTRINGZ) THREADSAFE AS LONG
      LOCAL pMetafile AS DWORD
      LOCAL emfType AS LONG
      IF ISMISSING(vemfType) THEN emfType = %EmfTypeEmfPlusOnly ELSE emfType = VARIANT#(vemfType)
      m_hStatus = GdipConvertToEmfPlusToFile(refGraphics.Ptr, m_pImage, conversionFailureFlag, wszFileName, emfType, description, pMetafile)
      IF pMetafile <> %NULL THEN
         IF m_hStatus = %StatusOK THEN
            IF m_pImage THEN GdipDisposeImage(m_pImage)
            m_pImage = pMetafile
         ELSE
            IF m_pImage THEN GdipDisposeImage(pMetafile)
         END IF
      END IF
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Converts this Metafile object to the EMF+ format.
   ' =====================================================================================
   METHOD ConvertToEmfPlusToStream (BYVAL refGraphics AS IGdipGraphics, BYVAL pStream AS IStream, _
   OPTIONAL BYREF conversionFailureFlag AS LONG, BYVAL vemfType AS VARIANT, BYREF description AS WSTRINGZ) THREADSAFE AS LONG
      LOCAL pMetafile AS DWORD
      LOCAL emfType AS LONG
      IF ISMISSING(vemfType) THEN emfType = %EmfTypeEmfPlusOnly ELSE emfType = VARIANT#(vemfType)
      m_hStatus = GdipConvertToEmfPlusToStream(refGraphics.Ptr, m_pImage, conversionFailureFlag, pStream, emfType, description, pMetafile)
      IF pMetafile <> %NULL THEN
         IF m_hStatus = %StatusOK THEN
            IF m_pImage THEN GdipDisposeImage(m_pImage)
            m_pImage = pMetafile
         ELSE
            IF m_pImage THEN GdipDisposeImage(pMetafile)
         END IF
      END IF
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

#ENDIF   ' //(GDIPVER >= 0x0110)

   END INTERFACE

END CLASS
' ########################################################################################
