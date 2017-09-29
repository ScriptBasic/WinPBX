' ########################################################################################
' Microsoft Windows
' File: amva.inc
' Contents: DirectShowMotionComp include file.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AMVA_INC = 1

#INCLUDE ONCE "ddraw.inc"

%AMVA_TYPEINDEX_OUTPUTFRAME   = &HFFFFFFFF???

'//  Flags for QueryRenderStatus
%AMVA_QUERYRENDERSTATUSF_READ = &H00000001??? ' // Query for read
                                              ' // set this bit to 0
                                              ' // if query for update

' // Size = 40 bytes
TYPE AMVAUncompBufferInfo DWORD
   dwMinNumSurfaces    AS DWORD            ' DWORD // __in min number of surfaces to be allocated
   dwMaxNumSurfaces    AS DWORD            ' DWORD // __in max number of surfaces to be allocated
   ddUncompPixelFormat AS DDPIXELFORMAT    ' DWORD // __in pixel format of surfaces to be allocated
END TYPE

' // Size = 40 bytes
TYPE AMVAUncompDataInfo DWORD
   dwUncompWidth       AS DWORD            ' DWORD // __in width of uncompressed data
   dwUncompHeight      AS DWORD            ' DWORD // __in height of uncompressed data
   ddUncompPixelFormat AS DDPIXELFORMAT    ' DDPIXELFORMAT // __in pixel-format of uncompressed data
END TYPE

' // Size = 4 bytes
TYPE AMVAInternalMemInfo DWORD
   dwScratchMemAlloc AS DWORD              ' DWORD // __out amount of scratch memory will the hal allocate for its private use
END TYPE

' // Size = 64 bytes
TYPE AMVACompBufferInfo DWORD
   dwNumCompBuffers  AS DWORD              ' DWORD // __out number of buffers reqd for compressed data
   dwWidthToCreate   AS DWORD              ' DWORD // __out Width of surface to create
   dwHeightToCreate  AS DWORD              ' DWORD // __out Height of surface to create
   dwBytesToAllocate AS DWORD              ' DWORD // __out Total number of bytes used by each surface
   ddCompCaps        AS DDSCAPS2           ' DDSCAPS2 // __out caps to create surfaces to store compressed data
   ddPixelFormat     AS DDPIXELFORMAT      ' DDPIXELFORMAT // __out fourcc to create surfaces to store compressed data
END TYPE

' // Size = 20 bytes
TYPE AMVABeginFrameInfo DWORD
   dwDestSurfaceIndex AS DWORD             ' DWORD // __in  destination buffer in which to decoding this frame
   pInputData         AS DWORD             ' DWORD // __in  pointer to misc data
   dwSizeInputData    AS DWORD             ' DWORD // __in  size of other misc data to begin frame
   pOutputData        AS DWORD             ' DWORD // __out pointer to data which the VGA is going to fill
   dwSizeOutputData   AS DWORD             ' DWORD // __in  size of data which the VGA is going to fill
END TYPE

'// Note that you are NOT allowed to store any pointer in pMiscData
' // Size = 8 bytes
TYPE AMVAEndFrameInfo DWORD
   dwSizeMiscData AS DWORD                 ' DWORD // __in size of other misc data to begin frame
   pMiscData      AS DWORD                 ' DWORD // __in pointer to misc data
END TYPE

' // Size = 16 bytes
TYPE AMVABUFFERINFO DWORD
   dwTypeIndex   AS DWORD                  ' DWORD // __in Type of buffer
   dwBufferIndex AS DWORD                  ' DWORD // __in Buffer index
   dwDataOffset  AS DWORD                  ' DWORD // __in offset of relevant data from the beginning of buffer
   dwDataSize    AS DWORD                  ' DWORD // __in size of relevant data
END TYPE
