# CMemBmp Class

The **CMemBmp** class implements a memory bitmap.

You can create an empty bitmap of the specified width an height, e.g.

```
DIM pMemBmp AS CMemBmp = CMemBmp(500, 400)
```

or loading an image

```
DIM pMemBmp AS CMemBmp = CMemBmp($"C:\Users\Pepe\Pictures\MyPicture.jpg")
```

You can manipulate its contents using GDI+ or GDI, e.g.

```
Rectangle pMemBmp.GetMemDC, 10, 10, 150, 150
LineTo pMemBmp.GetMemDC, 30, 180
```

And you can display it in a Graphic Control, e.g.

```
pGraphCtx.DrawBitmap pMemBmp
```

The bitmap can be saved to a file with

```
SaveBitmap
SaveBitmapAsBmp
SaveBitmapAsJpeg
SaveBitmapAsPng
SaveBitmapAsGif
SaveBitmapAsTiff
```

Finally, the **PrintBitmap** method prints the bitmap in the default printer.

The bitmap created by **CMemBmp** is a DDB (Device-Dependent Bitmap), compatible with the device that is associated with the specified device context (hDC parameter of the default constructor). If no device context is specified or the memory bitmap is constructed using the other two additional constructors (the one that use an image from a disk file or a resource file), the created memory bitmap will be compatible with the device context of the screen.

To create a DIB (device-independent bitmap) from the memory bitmap, use the function **GetDIBits**.

To create a GDI+ bitmap from the memory bitmap, use the function **GdipCreateBitmapFromHBITMAP**.

As the **CGraphCtx** graphic control uses DIBs, to draw a **CMemBmp** memory bitmap into it call the method DrawBitmap of the **CGraphCtx** class.
