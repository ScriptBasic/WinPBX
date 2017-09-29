' ########################################################################################
' Microsoft Windows
' File: CAfxImageList.inc
' Contents: ImageList class.
' Copyright (c) 2011 José Roca.
' Portions Copyright (c) Microsoft Corporation.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CAFXIMAGELIST_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "commctrl.inc"

' ########################################################################################
' CAfxImageList class.
' ########################################################################################
CLASS CAfxImageList

   INSTANCE m_hInstance AS DWORD
   INSTANCE m_hImageList AS DWORD
   INSTANCE m_Overlays() AS LONG
#IF %DEF(%UNICODE)
   INSTANCE m_ImageListName AS WSTRING
#ELSE
   INSTANCE m_ImageListName AS STRING
#ENDIF

   ' =====================================================================================
   ' Create method
   ' =====================================================================================
   CLASS METHOD Create
      REDIM m_Overlays(1 TO 15) AS INSTANCE LONG
      m_hInstance = GetModuleHandle(BYVAL %NULL)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Destroy method
   ' =====================================================================================
   CLASS METHOD Destroy
      IF m_hImageList THEN ImageList_Destroy(m_hImageList)
   END METHOD
   ' =====================================================================================

   ' // Note: I have used IAfxImageList instead of IImageList because the later is already
   ' // used by Microsoft.
   INTERFACE IAfxImageList : INHERIT IAutomation

   ' =====================================================================================
   ' Create the image list
   ' - cx       = The width, in pixels, of each image.
   ' - cy       = The height, in pixels, of each image.
   ' - dwFlags  = A set of bit flags that specify the type of image list to create.
   ' - cInitial = The number of images that the image list initially contains.
   ' - cGrow    = The number of images by which the image list can grow when the system
   '              needs to make room for new images. This parameter represents the number
   '              of new images that the resized image list can contain.
   ' Returns the handle to the image list if successful, or NULL otherwise.
   ' WARNING: Don't destroy the image list. The class does it when it is destroyed.
   ' =====================================================================================
   METHOD CreateImageList (BYVAL cx AS LONG, BYVAL cy AS LONG, OPTIONAL BYVAL dwFlags AS DWORD, _
      OPTIONAL BYVAL cInitial AS LONG, OPTIONAL BYVAL cGrow AS LONG) AS DWORD
      ' // Create and initialize the image list
      IF dwFlags = 0 THEN dwFlags = %ILC_COLOR OR %ILC_MASK
      IF cInitial = 0 THEN cInitial = 16
      m_hImageList = ImageList_Create(cx, cy, dwFlags, cInitial, cGrow)
      METHOD = m_hImageList
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the image list name
   ' =====================================================================================
#IF %DEF(%UNICODE)
   PROPERTY GET Name () AS WSTRING
#ELSE
   PROPERTY GET Name () AS STRING
#ENDIF
      PROPERTY = m_ImageListName
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the image list name
   ' =====================================================================================
#IF %DEF(%UNICODE)
   PROPERTY SET Name (BYVAL strName AS WSTRING)
#ELSE
   PROPERTY SET Name (BYVAL strName AS STRING)
#ENDIF
      m_ImageListName = strName
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the instance handle
   ' =====================================================================================
   PROPERTY GET hInstance () AS DWORD
      PROPERTY = m_hInstance
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the instance handle
   ' =====================================================================================
   PROPERTY SET hInstance (BYVAL hInstance AS DWORD)
      m_hInstance = hInstance
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the handle of the image list
   ' =====================================================================================
   PROPERTY GET hImageList () AS DWORD
      PROPERTY = m_hImageList
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Loads an image from file or resource.
   ' - strImage  = [in] Path to file that contains the image or images (the number of
   '               images is inferred from the width of the bitmap), or name of the bitmap,
   '               icon or cursor in the resource file (.RES). If the image resource uses
   '               an integral identifier, strImage should begin with a number symbol (#)
   '               followed by the identifier in an ASCII format, e.g., "#998". Otherwise,
   '               use the text identifier name for the image.
   ' - dwType    = [in] Specifies the type of image to be loaded(IMAGE_BITMAP, IMAGE_ICON, or IMAGE_CURSOR).
   ' - cxDesired = [in, opt] The desired width, in pixels, of the icon.
   ' - cyDesired = [in, opt] The desired height, in pixels, of the icon.
   ' - hInstance = [in, opt] Handle to the instance that contains the resource.
   ' - bShared   = [in, opt] Shares the image handle if the image is loaded multiple times.
   ' If the function succeeds, the return value is the handle of the newly loaded image.
   ' If the function fails, the return value is NULL.
   ' =====================================================================================
#IF %DEF(%UNICODE)
    METHOD LoadImage (BYVAL strImage AS WSTRING, BYVAL dwType AS DWORD, OPTIONAL BYVAL cxDesired AS LONG, BYVAL cyDesired AS LONG, BYVAL hInstance AS DWORD, BYVAL bShared AS LONG) AS DWORD
#ELSE
    METHOD LoadImage (BYVAL strImage AS STRING, BYVAL dwType AS DWORD, OPTIONAL BYVAL cxDesired AS LONG, BYVAL cyDesired AS LONG, BYVAL hInstance AS DWORD, BYVAL bShared AS LONG) AS DWORD
#ENDIF
      LOCAL hImage AS DWORD, wID AS WORD, dwID AS DWORD, dwFlag AS DWORD
      IF hInstance = 0 THEN hInstance = m_hInstance
      IF bShared THEN dwFlag = %LR_SHARED
      IF LEFT$(strImage, 1) = "#" THEN
         wID = VAL(MID$(strImage, 2))
         dwID = MAK(DWORD, wID, 0)
         IF hInstance THEN hImage = LoadImage(hInstance, BYVAL dwID, dwType, cxDesired, cyDesired, %LR_DEFAULTCOLOR OR dwFlag)
      ELSEIF INSTR(strImage, ".") THEN
         hImage = LoadImage(%NULL, BYCOPY strImage, dwType, cxDesired, cyDesired, %LR_LOADFROMFILE OR %LR_DEFAULTCOLOR)
      ELSE
         IF hInstance THEN hImage = LoadImage(hInstance, BYCOPY strImage, dwType, cxDesired, cyDesired, %LR_DEFAULTCOLOR)
      END IF
      METHOD = hImage
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Loads a bitmap from file or resource and adds it to the image list.
   ' - strImage  = [in] Path to file that contains the image or images (the number of
   '               images is inferred from the width of the bitmap), or name of the bitmap
   '               in the resource file (.RES). If the image resource uses an integral
   '               identifier, strImage should begin with a number symbol (#) followed by
   '               the identifier in an ASCII format, e.g., "#998". Otherwise, use the
   '               text identifier name for the image.
   ' - cxDesired = [in, opt] The desired width, in pixels, of the icon.
   ' - cyDesired = [in, opt] The desired height, in pixels, of the icon.
   ' - strMask   = [in, opt] Path to file that contains the mask. If no mask is used with
   '               the image list, this parameter is ignored.
   ' - hInstance = [in, opt] Handle to the instance that contains the resource.
   ' Returns the index of the first new image if successful, or -1 otherwise.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD LoadBitmap (BYVAL strImage AS WSTRING, OPTIONAL BYVAL cxDesired AS LONG, BYVAL cyDesired AS LONG, BYVAL strMask AS WSTRING, BYVAL hInstance AS DWORD) AS LONG
#ELSE
   METHOD LoadBitmap (BYVAL strImage AS STRING, OPTIONAL BYVAL cxDesired AS LONG, BYVAL cyDesired AS LONG, BYVAL strMask AS STRING, BYVAL hInstance AS DWORD) AS LONG
#ENDIF
      LOCAL hImage AS DWORD, hMask AS DWORD
      METHOD = -1   ' // Assume error for now
      IF hInstance = 0 THEN hInstance = m_hInstance
      IF hInstance = 0 THEN EXIT METHOD
      hImage = ME.LoadImage(strImage, %IMAGE_BITMAP, cxDesired, cyDesired, hInstance)
      IF LEN(strMask) = 0 THEN hMask = ME.LoadImage(strMask, %IMAGE_BITMAP, cxDesired, cyDesired, hInstance)
      IF hImage THEN
         IF m_hImageList THEN METHOD = ImageList_Add(m_hImageList, hImage, hMask)
         DeleteObject hImage
      END IF
      IF hMask THEN DeleteObject hMask
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a bitmap to the image list.
   ' - hImage = [in] Handle to the bitmap that contains the image or images. The number of
   '            images is inferred from the width of the bitmap.
   ' - hMask  = [in, opt] Handle to the bitmap that contains the mask. If no mask is used
   '            with the image list, this parameter is ignored.
   ' Returns the index of the first new image if successful, or -1 otherwise.
   ' =====================================================================================
   METHOD AddBitmap (BYVAL hImage AS DWORD, OPTIONAL BYVAL hMask AS DWORD) AS LONG
      METHOD = -1   ' // Assume error for now
      IF hImage = %NULL THEN EXIT METHOD
      IF m_hImageList THEN METHOD = ImageList_Add(m_hImageList, hImage, hMask)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds an icon to the image list.
   ' - hImage = [in] Handle to the icon or cursor that contains the bitmap and mask for
   '            the new image.
   ' Returns the index of the image if successful, or -1 otherwise.
   ' =====================================================================================
   METHOD AddIcon (BYVAL hImage AS DWORD) AS LONG
      METHOD = -1   ' // Assume error for now
      IF hImage = %NULL THEN EXIT METHOD
      IF m_hImageList THEN ImageList_ReplaceIcon(m_hImageList, -1, hImage)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Loads an icon from file or resource and adds it to the image list.
   ' - strImage  = [in] Path to file that contains the icon, or name of the icon in the
   '               resource file (.RES). If the image resource uses an integral identifier,
   '               strImage should begin with a number symbol (#) followed by the identifier
   '               in an ASCII format, e.g., "#998". Otherwise, use the text identifier
   '               name for the image.
   ' - cxDesired = [in, opt] The desired width, in pixels, of the icon.
   ' - cyDesired = [in, opt] The desired height, in pixels, of the icon.
   ' - hInstance = [in, opt] Handle to the instance that contains the resource.
   ' Returns the index of the image if successful, or -1 otherwise.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD LoadIcon (BYVAL strImage AS WSTRING, OPTIONAL BYVAL cxDesired AS LONG, BYVAL cyDesired AS LONG, BYVAL hInstance AS DWORD) AS LONG
#ELSE
   METHOD LoadIcon (BYVAL strImage AS STRING, OPTIONAL BYVAL cxDesired AS LONG, BYVAL cyDesired AS LONG, BYVAL hInstance AS DWORD) AS LONG
#ENDIF
      LOCAL hImage AS DWORD
      METHOD = -1   ' // Assume error for now
      IF hInstance = 0 THEN hInstance = m_hInstance
      IF hInstance = 0 THEN EXIT METHOD
      hImage = ME.LoadImage(strImage, %IMAGE_ICON, cxDesired, cyDesired, hInstance)
      IF hImage THEN
         IF m_hImageList THEN METHOD = ImageList_ReplaceIcon(m_hImageList, -1, hImage)
         DeleteObject hImage
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Loads an icon from a resource file and adds it to the image list.
   ' - wID       = [in] Identifier of the icon in the resource file.
   ' - cxDesired = [in, opt] The desired width, in pixels, of the icon.
   ' - cyDesired = [in, opt] The desired height, in pixels, of the icon.
   ' - hInstance = [in, opt] Handle to the instance that contains the resource.
   ' - bShared   = [in, opt] Shares the image handle if the image is loaded multiple times.
   ' Returns the index of the image if successful, or -1 otherwise.
   ' =====================================================================================
   METHOD LoadResIcon (BYVAL wID AS WORD, OPTIONAL BYVAL cxDesired AS LONG, BYVAL cyDesired AS LONG, BYVAL hInstance AS DWORD, BYVAL bShared AS LONG) AS LONG
      LOCAL hImage, dwFlag, dwID AS DWORD
      METHOD = -1   ' // Assume error for now
      IF hInstance = 0 THEN hInstance = m_hInstance
      IF hInstance = 0 THEN EXIT METHOD
      dwID = MAK(DWORD, wID, 0)
      IF bShared THEN dwFlag = %LR_SHARED
      hImage = LoadImage(hInstance, BYVAL dwID, %IMAGE_ICON, cxDesired, cyDesired, %LR_DEFAULTCOLOR OR dwFlag)
      IF hImage THEN
         IF m_hImageList THEN METHOD = ImageList_ReplaceIcon(m_hImageList, -1, hImage)
         IF bShared = 0 THEN DeleteObject hImage
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Loads a bitmap from a resource file and adds it to the image list.
   ' - wID       = [in] Identifier of the bitmap in the resource file.
   ' - cxDesired = [in, opt] The desired width, in pixels, of the icon.
   ' - cyDesired = [in, opt] The desired height, in pixels, of the icon.
   ' - hMask     = [in, opt] Handle to the bitmap that contains the mask. If no mask is used
   '               with the image list, this parameter is ignored.
   ' - hInstance = [in, opt] Handle to the instance that contains the resource.
   ' - bShared   = [in, opt] Shares the image handle if the image is loaded multiple times.
   ' Returns the index of the image if successful, or -1 otherwise.
   ' =====================================================================================
   METHOD LoadResBitmap (BYVAL wID AS WORD, OPTIONAL BYVAL cxDesired AS LONG, BYVAL cyDesired AS LONG, BYVAL hMask AS DWORD, BYVAL hInstance AS DWORD, BYVAL bShared AS LONG) AS LONG
      LOCAL hImage, dwFlag, dwID AS DWORD
      METHOD = -1   ' // Assume error for now
      IF hInstance = 0 THEN hInstance = m_hInstance
      IF hInstance = 0 THEN EXIT METHOD
      dwID = MAK(DWORD, wID, 0)
      IF bShared THEN dwFlag = %LR_SHARED
      hImage = LoadImage(hInstance, BYVAL dwID, %IMAGE_BITMAP, cxDesired, cyDesired, %LR_DEFAULTCOLOR OR dwFlag)
      IF hImage THEN
         IF m_hImageList THEN METHOD = ImageList_Add(m_hImageList, hImage, hMask)
         IF bShared = 0 THEN DeleteObject hImage
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Loads an icon from a resource file.
   ' - strName   = [in] Name of the icon in the resource file.
   ' - cxDesired = [in, opt] The desired width, in pixels, of the icon.
   ' - cyDesired = [in, opt] The desired height, in pixels, of the icon.
   ' - hInstance = [in, opt] Handle to the instance that contains the resource.
   ' - bShared   = [in, opt] Shares the image handle if the image is loaded multiple times.
   ' Returns the index of the image if successful, or -1 otherwise.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD LoadNamedResIcon (BYVAL strName AS WSTRING, OPTIONAL BYVAL cxDesired AS LONG, BYVAL cyDesired AS LONG, BYVAL hInstance AS DWORD, BYVAL bShared AS LONG) AS LONG
#ELSE
   METHOD LoadNamedResIcon (BYVAL strName AS STRING, OPTIONAL BYVAL cxDesired AS LONG, BYVAL cyDesired AS LONG, BYVAL hInstance AS DWORD, BYVAL bShared AS LONG) AS LONG
#ENDIF
      LOCAL hImage, dwFlag AS DWORD
      METHOD = -1   ' // Assume error for now
      IF hInstance = 0 THEN hInstance = m_hInstance
      IF hInstance = 0 THEN EXIT METHOD
      IF bShared THEN dwFlag = %LR_SHARED
      hImage = LoadImage(hInstance, BYCOPY strName, %IMAGE_ICON, cxDesired, cyDesired, %LR_DEFAULTCOLOR OR dwFlag)
      IF hImage THEN
         IF m_hImageList THEN METHOD = ImageList_ReplaceIcon(m_hImageList, -1, hImage)
         IF bShared = 0 THEN DeleteObject hImage
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Loads a bitmap from a resource file.
   ' - strName   = [in] Name of the bitmap in the resource file.
   ' - cxDesired = [in, opt] The desired width, in pixels, of the icon.
   ' - cyDesired = [in, opt] The desired height, in pixels, of the icon.
   ' - hMask     = [in, opt] Handle to the bitmap that contains the mask. If no mask is used
   '               with the image list, this parameter is ignored.
   ' - hInstance = [in, opt] Handle to the instance that contains the resource.
   ' - bShared   = [in, opt] Shares the image handle if the image is loaded multiple times.
   ' Returns the index of the image if successful, or -1 otherwise.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD LoadNamedResBitmap (BYVAL strName AS WSTRING, OPTIONAL BYVAL cxDesired AS LONG, BYVAL cyDesired AS LONG, BYVAL hMask AS DWORD, BYVAL hInstance AS DWORD, BYVAL bShared AS LONG) AS LONG
#ELSE
   METHOD LoadNamedResBitmap (BYVAL strName AS STRING, OPTIONAL BYVAL cxDesired AS LONG, BYVAL cyDesired AS LONG, BYVAL hMask AS DWORD, BYVAL hInstance AS DWORD, BYVAL bShared AS LONG) AS LONG
#ENDIF
      LOCAL hImage, dwFlag AS DWORD
      METHOD = -1   ' // Assume error for now
      IF hInstance = 0 THEN hInstance = m_hInstance
      IF hInstance = 0 THEN EXIT METHOD
      IF bShared THEN dwFlag = %LR_SHARED
      hImage = LoadImage(hInstance, BYCOPY strName, %IMAGE_BITMAP, cxDesired, cyDesired, %LR_DEFAULTCOLOR OR dwFlag)
      IF hImage THEN
         IF m_hImageList THEN METHOD = ImageList_Add(m_hImageList, hImage, hMask)
         IF bShared = 0 THEN DeleteObject hImage
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds an image or images to an image list, generating a mask from the specified bitmap.
   ' - hImage      = [in] Handle to the bitmap that contains the image or images. The number of
   '                 images is inferred from the width of the bitmap.
   ' - dwMaskColor = [in, opt] Color used to generate the mask.
   ' Returns the index of the first new image if successful, or -1 otherwise.
   ' =====================================================================================
   METHOD AddMasked (BYVAL hImage AS DWORD, OPTIONAL BYVAL dwMaskColor AS DWORD) AS LONG
      METHOD = -1   ' // Assume error for now
      IF dwMaskColor = 0 THEN dwMaskColor = RGB(255, 0 ,255)
      IF hImage THEN
         IF m_hImageList THEN METHOD = ImageList_AddMasked(m_hImageList, hImage, dwMaskColor)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Loads an image or images to an image list, generating a mask from the specified bitmap.
   ' - strImage    = [in] Path to the bitmap that contains the image or images (the number
   '                 of images is inferred from the width of the bitmap). If the image
   '                 resource uses an integral identifier, strImage should begin with a
   '                 number symbol (#) followed by the identifier in an ASCII format, e.g.,
   '                 "#998". Otherwise, use the text identifier name for the image.
   ' - cxDesired   = [in, opt] The desired width, in pixels, of the icon.
   ' - cyDesired   = [in, opt] The desired height, in pixels, of the icon.
   ' - dwMaskColor = [in] Color used to generate the mask.
   ' - hInstance   = [in, opt] Handle to the instance that contains the resource.
   ' Returns the index of the first new image if successful, or -1 otherwise.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD LoadMasked (BYVAL strImage AS WSTRING, OPTIONAL BYVAL cxDesired AS LONG, BYVAL cyDesired AS LONG, BYVAL dwMaskColor AS DWORD, BYVAL hInstance AS DWORD) AS LONG
#ELSE
   METHOD LoadMasked (BYVAL strImage AS STRING, OPTIONAL BYVAL cxDesired AS LONG, BYVAL cyDesired AS LONG, BYVAL dwMaskColor AS DWORD, BYVAL hInstance AS DWORD) AS LONG
#ENDIF
      LOCAL hImage, hMask AS DWORD
      METHOD = -1   ' // Assume error for now
      IF hInstance = 0 THEN hInstance = m_hInstance
      IF hInstance = 0 THEN EXIT METHOD
      hImage = ME.LoadImage(strImage, %IMAGE_BITMAP, cxDesired, cyDesired, hInstance)
      IF hImage THEN
         IF dwMaskColor = 0 THEN dwMaskColor = RGB(255, 0 ,255)
         IF m_hImageList THEN METHOD = ImageList_AddMasked(m_hImageList, hImage, dwMaskColor)
         DeleteObject hImage
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Loads an image or images to an image list, generating a mask from the specified mask color.
   ' - wID         = [in] Identifier of the bitmap in the resource file.
   ' - cxDesired   = [in, opt] The desired width, in pixels, of the icon.
   ' - cyDesired   = [in, opt] The desired height, in pixels, of the icon.
   ' - dwMaskColor = [in, opt] Color used to generate the mask.
   ' - hInstance   = [in, opt] Handle to the instance that contains the resource.
   ' Returns the index of the image if successful, or -1 otherwise.
   ' =====================================================================================
   METHOD LoadResBitmapMasked (BYVAL wID AS WORD, OPTIONAL BYVAL cxDesired AS LONG, BYVAL cyDesired AS LONG, BYVAL dwMaskColor AS DWORD, BYVAL hInstance AS DWORD) AS LONG
      LOCAL hImage, dwID AS DWORD
      METHOD = -1   ' // Assume error for now
      IF hInstance = 0 THEN hInstance = m_hInstance
      IF hInstance = 0 THEN EXIT METHOD
      dwID = MAK(DWORD, wID, 0)
      hImage = LoadImage(hInstance, BYVAL dwID, %IMAGE_BITMAP, cxDesired, cyDesired, %LR_DEFAULTCOLOR)
      IF hImage THEN
         IF dwMaskColor = 0 THEN dwMaskColor = RGB(255, 0 ,255)
         IF m_hImageList THEN METHOD = ImageList_AddMasked(m_hImageList, hImage, dwMaskColor)
         DeleteObject hImage
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Loads a bitmap from a resource file.
   ' - strName     = [in] Name of the bitmap in the resource file.
   ' - cxDesired   = [in, opt] The desired width, in pixels, of the icon.
   ' - cyDesired   = [in, opt] The desired height, in pixels, of the icon.
   ' - dwMaskColor = [in, opt] Color used to generate the mask.
   ' - hInstance   = [in, opt] Handle to the instance that contains the resource.
   ' Returns the index of the image if successful, or -1 otherwise.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD LoadNamedResBitmapMasked (BYVAL strName AS WSTRING, OPTIONAL BYVAL cxDesired AS LONG, BYVAL cyDesired AS LONG, BYVAL dwMaskColor AS DWORD, BYVAL hInstance AS DWORD) AS LONG
#ELSE
   METHOD LoadNamedResBitmapMasked (BYVAL strName AS STRING, OPTIONAL BYVAL cxDesired AS LONG, BYVAL cyDesired AS LONG, BYVAL dwMaskColor AS DWORD, BYVAL hInstance AS DWORD) AS LONG
#ENDIF
      LOCAL hImage, dwFlag AS DWORD
      METHOD = -1   ' // Assume error for now
      IF hInstance = 0 THEN hInstance = m_hInstance
      IF hInstance = 0 THEN EXIT METHOD
      hImage = LoadImage(hInstance, BYCOPY strName, %IMAGE_BITMAP, cxDesired, cyDesired, %LR_DEFAULTCOLOR)
      IF hImage THEN
         IF dwMaskColor = 0 THEN dwMaskColor = RGB(255, 0 ,255)
         IF m_hImageList THEN METHOD = ImageList_AddMasked(m_hImageList, hImage, dwMaskColor)
         DeleteObject hImage
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a specified image to the list of images to be used as overlay masks. An image
   ' list can have up to four overlay masks in version 4.70 and earlier and up to 15 in
   ' version 4.71. This method assigns an overlay mask index to the specified image.
   ' - iImage   = The zero-based index of an image in the image list. This index
   '              identifies the image to use as an overlay mask.
   ' - iOverlay = The one-based index of the overlay mask.
   ' =====================================================================================
   METHOD OverlayImage (BYVAL iImage AS LONG, BYVAL iOverlay AS LONG)
      LOCAL iItem     AS LONG
      IF (iOverlay >= 1) AND (iOverlay <= 15) THEN
         IF ImageList_SetOverlayImage(m_hImageList, iImage, iOverlay) <> %E_INVALIDARG THEN
            ' // Note: the image index is increased by one to be able to distinguish when
            ' // a slot has been initialized.
            m_Overlays(iOverlay) = iImage + 1
        END IF
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the overlay index for the specified image index.
   ' iImage = The zero-based index of an image in image list that is used as an overlay mask.
   ' =====================================================================================
   METHOD OverlayIndex (BYVAL iImage AS LONG) AS LONG
      LOCAL iItem, iOverlay  AS LONG
      INCR iImage
      iItem = 1
      WHILE iOverlay <= 15
         IF m_Overlays(iItem) = iImage THEN
            iOverlay = iItem
            EXIT LOOP
         END IF
         INCR iItem
      WEND
      METHOD = iOverlay
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a duplicate of the image list.
   ' =====================================================================================
   METHOD Duplicate () AS DWORD
      IF m_hImageList THEN METHOD = ImageList_Duplicate(m_hImageList)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Copies images within the image list.
   ' - iDst   = The zero-based index of the image to be used as the destination of the copy operation.
   ' - iSrc   = The zero-based index of the image to be used as the source of the copy operation.
   ' - dwFlag = The bit flag value that specifies the type of copy operation to be made.
   '   This parameter can be one of the following values:
   '   ILCF_MOVE = The source image is copied to the destination image's index. This
   '               operation results in multiple instances of a given image.
   '   ILCF_SWAP = The source and destination images exchange positions within the image list.
   ' Returns nonzero if successful, or zero otherwise.
   ' =====================================================================================
   METHOD Copy (BYVAL iDst AS LONG, BYVAL iSrc AS LONG, BYVAL dwFlag AS DWORD) AS LONG
      IF m_hImageList THEN METHOD = ImageList_Copy(m_hImageList, iDst, m_hImageList, iSrc, dwFlag)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Removes an image from an image list.
   ' idx = The index of the image to remove. If this parameter is -1, then all images are removed.
   ' Returns nonzero if successful, or zero otherwise.
   ' =====================================================================================
   METHOD Remove (BYVAL idx AS LONG) AS LONG
      IF m_hImageList THEN METHOD = ImageList_Remove(m_hImageList, idx)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves the dimensions of images in an image list. All images in an image list have
   ' the same dimensions.
   ' cx = The width, in pixels, of each image.
   ' cy = The height, in pixels, of each image.
   ' Returns nonzero if successful, or zero otherwise.
   ' =====================================================================================
   METHOD GetIconSize (BYREF cx AS LONG, BYREF cy AS LONG) AS LONG
      IF m_hImageList THEN METHOD = ImageList_GetIconSize(m_hImageList, cx, cy)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves the number of images in an image list.
   ' =====================================================================================
   PROPERTY GET ImageCount () AS LONG
      IF m_hImageList THEN PROPERTY = ImageList_GetImageCount(m_hImageList)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves the current background color for an image list.
   ' =====================================================================================
   PROPERTY GET BackgroundColor () AS DWORD
      IF m_hImageList THEN PROPERTY = ImageList_GetBkColor(m_hImageList)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the background color for an image list. This function only works if you add an
   ' icon or use ImageList_AddMasked with a black and white bitmap. Without a mask, the
   ' entire image is drawn; hence the background color is not visible.
   ' =====================================================================================
   PROPERTY SET BackgroundColor (BYVAL clrBk AS DWORD)
      IF m_hImageList THEN ImageList_SetBkColor(m_hImageList, clrBk)
   END PROPERTY
   ' =====================================================================================

   END INTERFACE
   ' =====================================================================================

END CLASS
' ########################################################################################

' ========================================================================================
' Creates a new instance of the CAfxImageList class and initializes it.
' ========================================================================================
FUNCTION NewAfxImageList (BYVAL cx AS LONG, BYVAL cy AS LONG, OPTIONAL BYVAL dwFlags AS DWORD, OPTIONAL BYVAL cInitial AS LONG, OPTIONAL BYVAL cGrow AS LONG) AS IAfxImageList
   LOCAL pImageList AS IAfxImageList
   ' // Create an instance of the class
   pImageList = CLASS "CAfxImageList"
   IF ISNOTHING(pImageList) THEN EXIT FUNCTION
   ' // Create the image list
   pImageList.CreateImageList(cx, cy, dwFlags, cInitial, cGrow)
   FUNCTION = pImageList
END FUNCTION
' ========================================================================================
