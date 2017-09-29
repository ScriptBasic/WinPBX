' ########################################################################################
' Microsoft Windows
' File: GdiPlusMetaHeader.inc
' Contents: GDI+ Metafile Related Structures
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%GDIPLUSMETAHEADER_INC = 1

' // Size = 88 bytes
TYPE ENHMETAHEADER3 DWORD FILL
   itype          AS DWORD   ' Record type EMR_HEADER
   nSize          AS DWORD   ' Record size in bytes.  This may be greater
                             ' than the sizeof(ENHMETAHEADER).
   rclBounds      AS RECTL   ' Inclusive-inclusive bounds in device units
   rclFrame       AS RECTL   ' Inclusive-inclusive Picture Frame .01mm unit
   dSignature     AS DWORD   ' Signature.  Must be ENHMETA_SIGNATURE.
   nVersion       AS DWORD   ' Version number
   nBytes         AS DWORD   ' Size of the metafile in bytes
   nRecords       AS DWORD   ' Number of records in the metafile
   nHandles       AS WORD    ' Number of handles in the handle table
                             ' Handle index zero is reserved.
   sReserved      AS WORD    ' Reserved.  Must be zero.
   nDescription   AS DWORD   ' Number of chars in the unicode desc string
                             ' This is 0 if there is no description string
   offDescription AS DWORD   ' Offset to the metafile description record.
                             ' This is 0 if there is no description string
   nPalEntries    AS DWORD   ' Number of entries in the metafile palette.
   szlDevice      AS SIZEL   ' Size of the reference device in pels
   szlMillimeters AS SIZEL   ' Size of the reference device in millimeters
END TYPE

'// Placeable WMFs

'// Placeable Metafiles were created as a non-standard way of specifying how
'// a metafile is mapped and scaled on an output device.
'// Placeable metafiles are quite wide-spread, but not directly supported by
'// the Windows API. To playback a placeable metafile using the Windows API,
'// you will first need to strip the placeable metafile header from the file.
'// This is typically performed by copying the metafile to a temporary file
'// starting at file offset 22 (0x16). The contents of the temporary file may
'// then be used as input to the Windows GetMetaFile(), PlayMetaFile(),
'// CopyMetaFile(), etc. GDI functions.

'// Each placeable metafile begins with a 22-byte header,
'//  followed by a standard metafile:

'#include <pshpack2.h>   // set structure packing to 2

' // Size = 8 bytes
TYPE PWMFRect16 WORD
   Left   AS INTEGER   ' INT16
   Top    AS INTEGER   ' INT16
   Right  AS INTEGER   ' INT16
   Bottom AS INTEGER   ' INT16
END TYPE

' // Size = 24 bytes
TYPE WmfPlaceableFileHeader WORD
   Key         AS DWORD        ' UINT32     // GDIP_WMF_PLACEABLEKEY
   Hmf         AS INTEGER      ' INT16      // Metafile HANDLE number (always 0)
   BoundingBox AS PWMFRect16   ' PWMFRect16 // Coordinates in metafile units
   Inch        AS INTEGER      ' INT16      // Number of metafile units per inch
   Reserved    AS DWORD        ' UINT32     // Reserved (always 0)
   Checksum    AS INTEGER      ' INT16      // Checksum value for previous 10 WORDs
   alignment__ AS WORD         ' // To keep alignment
END TYPE

'#include <poppack.h>

'// Key contains a special identification value that indicates the presence
'// of a placeable metafile header and is always 0x9AC6CDD7.

'// Handle is used to stored the handle of the metafile in memory. When written
'// to disk, this field is not used and will always contains the value 0.

'// Left, Top, Right, and Bottom contain the coordinates of the upper-left
'// and lower-right corners of the image on the output device. These are
'// measured in twips.

'// A twip (meaning "twentieth of a point") is the logical unit of measurement
'// used in Windows Metafiles. A twip is equal to 1/1440 of an inch. Thus 720
'// twips equal 1/2 inch, while 32,768 twips is 22.75 inches.

'// Inch contains the number of twips per inch used to represent the image.
'// Normally, there are 1440 twips per inch; however, this number may be
'// changed to scale the image. A value of 720 indicates that the image is
'// double its normal size, or scaled to a factor of 2:1. A value of 360
'// indicates a scale of 4:1, while a value of 2880 indicates that the image
'// is scaled down in size by a factor of two. A value of 1440 indicates
'// a 1:1 scale ratio.

'// Reserved is not used and is always set to 0.

'// Checksum contains a checksum value for the previous 10 WORDs in the header.
'// This value can be used in an attempt to detect if the metafile has become
'// corrupted. The checksum is calculated by XORing each WORD value to an
'// initial value of 0.

'// If the metafile was recorded with a reference Hdc that was a display.

%GDIP_EMFPLUSFLAGS_DISPLAY = &H00000001

UNION MetafileHeader_Union
   WmfHeader AS METAHEADER
   EmfHeader AS ENHMETAHEADER3
END UNION

' // Size = 140 bytes
TYPE MetafileHeader DWORD
   Type                 AS DWORD
   Size                 AS DWORD    ' // Size of the metafile (in bytes)
   Version              AS DWORD    ' // EMF+, EMF, or WMF version
   EmfPlusFlags         AS DWORD
   DpiX                 AS SINGLE
   DpiY                 AS SINGLE
   X                    AS LONG     ' // Bounds in device units
   Y                    AS LONG
   Width                AS LONG
   Height               AS LONG
   MetafileHeader_Union
   EmfPlusHeaderSize    AS LONG     ' // size of the EMF+ header in file
   LogicalDpiX          AS LONG     ' // Logical Dpi of reference Hdc
   LogicalDpiY          AS LONG     ' // usually valid only for EMF+
END TYPE
