' ########################################################################################
' Microsoft Windows
' File: dvp.inc
' Contents: DirectDrawVideoPort include file
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DVP_INC = 1

#INCLUDE ONCE "ddraw.inc"

'/*
' * GUIDS used by DirectDrawVideoPort objects
' */


$IID_IDDVideoPortContainer = GUID$("{6C142760-A733-11CE-A521-0020AF0BE560}")
$IID_IDirectDrawVideoPort  = GUID$("{B36D93E0-2B43-11CF-A2DE-00AA00B93356}")

$DDVPTYPE_E_HREFH_VREFH    = GUID$("{54F39980-DA60-11CF-9B06-00A0C903A3B8}")
$DDVPTYPE_E_HREFH_VREFL    = GUID$("{92783220-DA60-11CF-9B06-00A0C903A3B8}")
$DDVPTYPE_E_HREFL_VREFH    = GUID$("{A07A02E0-DA60-11CF-9B06-00A0C903A3B8}")
$DDVPTYPE_E_HREFL_VREFL    = GUID$("{E09C77E0-DA60-11CF-9B06-00A0C903A3B8}")
$DDVPTYPE_CCIR656          = GUID$("{FCA326A0-DA60-11CF-9B06-00A0C903A3B8}")
$DDVPTYPE_BROOKTREE        = GUID$("{1352A560-DA61-11CF-9B06-00A0C903A3B8}")
$DDVPTYPE_PHILIPS          = GUID$("{332CF160-DA61-11CF-9B06-00A0C903A3B8}")

'/*
' * GUIDS used to describe connections
' */


'/*============================================================================
' *
' * DirectDraw Structures
' *
' * Various structures used to invoke DirectDraw.
' *
' *==========================================================================*/

'/*
' * DDVIDEOPORTCONNECT
' */
' // Size = 32 bytes
TYPE DDVIDEOPORTCONNECT DWORD
   dwSize      AS DWORD   ' // size of the DDVIDEOPORTCONNECT structure
   dwPortWidth AS DWORD   ' // Width of the video port
   guidTypeID  AS GUID    ' // Description of video port connection
   dwFlags     AS DWORD   ' // Connection flags
   dwReserved1 AS DWORD   ' // Reserved, set to zero.
END TYPE


'/*
' * DDVIDEOPORTCAPS
' */
' // Size = 72 bytes
TYPE DDVIDEOPORTCAPS DWORD
   dwSize                        AS DWORD   ' // size of the DDVIDEOPORTCAPS structure
   dwFlags                       AS DWORD   ' // indicates which fields contain data
   dwMaxWidth                    AS DWORD   ' // max width of the video port field
   dwMaxVBIWidth                 AS DWORD   ' // max width of the VBI data
   dwMaxHeight                   AS DWORD   ' // max height of the video port field
   dwVideoPortID                 AS DWORD   ' // Video port ID (0 - (dwMaxVideoPorts -1))
   dwCaps                        AS DWORD   ' // Video port capabilities
   dwFX                          AS DWORD   ' // More video port capabilities
   dwNumAutoFlipSurfaces         AS DWORD   ' // Number of autoflippable surfaces
   dwAlignVideoPortBoundary      AS DWORD   ' // Byte restriction of placement within the surface
   dwAlignVideoPortPrescaleWidth AS DWORD   ' // Byte restriction of width after prescaling
   dwAlignVideoPortCropBoundary  AS DWORD   ' // Byte restriction of left cropping
   dwAlignVideoPortCropWidth     AS DWORD   ' // Byte restriction of cropping width
   dwPreshrinkXStep              AS DWORD   ' // Width can be shrunk in steps of 1/x
   dwPreshrinkYStep              AS DWORD   ' // Height can be shrunk in steps of 1/x
   dwNumVBIAutoFlipSurfaces      AS DWORD   ' // Number of VBI autoflippable surfaces
   dwReserved1                   AS DWORD   ' // Reserved for future use
   dwReserved2                   AS DWORD   ' // Reserved for future use
END TYPE

'/*
' * The dwMaxWidth and dwMaxVBIWidth members are valid
' */
%DDVPD_WIDTH      = &H00000001???

'/*
' * The dwMaxHeight member is valid
' */
%DDVPD_HEIGHT     = &H00000002???

'/*
' * The dwVideoPortID member is valid
' */
%DDVPD_ID         = &H00000004???

'/*
' * The dwCaps member is valid
' */
%DDVPD_CAPS       = &H00000008???

'/*
' * The dwFX member is valid
' */
%DDVPD_FX         = &H00000010???

'/*
' * The dwNumAutoFlipSurfaces member is valid
' */
%DDVPD_AUTOFLIP   = &H00000020???

'/*
' * All of the alignment members are valid
' */
%DDVPD_ALIGN      = &H00000040???


'/*
' * DDVIDEOPORTDESC
' */
' // Size = 72 bytes
TYPE DDVIDEOPORTDESC DWORD
   dwSize                 AS DWORD                ' // size of the DDVIDEOPORTDESC structure
   dwFieldWidth           AS DWORD                ' // width of the video port field
   dwVBIWidth             AS DWORD                ' // width of the VBI data
   dwFieldHeight          AS DWORD                ' // height of the video port field
   dwMicrosecondsPerField AS DWORD                ' // Microseconds per video field
   dwMaxPixelsPerSecond   AS DWORD                ' // Maximum pixel rate per second
   dwVideoPortID          AS DWORD                ' // Video port ID (0 - (dwMaxVideoPorts -1))
   dwReserved1            AS DWORD                ' // Reserved for future use - set to zero
   VideoPortType          AS DDVIDEOPORTCONNECT   ' // Description of video port connection
   dwReserved2            AS DWORD                ' // Reserved for future use - set to zero
   dwReserved3            AS DWORD                ' // Reserved for future use - set to zero
END TYPE


'/*
' * DDVIDEOPORTINFO
' */
' // Size = 64 bytes
TYPE DDVIDEOPORTINFO DWORD
   dwSize                AS DWORD               ' // Size of the structure
   dwOriginX             AS DWORD               ' // Placement of the video data within the surface.
   dwOriginY             AS DWORD               ' // Placement of the video data within the surface.
   dwVPFlags             AS DWORD               ' // Video port options
   rCrop                 AS RECT                ' // Cropping rectangle (optional).
   dwPrescaleWidth       AS DWORD               ' // Determines pre-scaling/zooming in the X direction (optional).
   dwPrescaleHeight      AS DWORD               ' // Determines pre-scaling/zooming in the Y direction (optional).
   lpddpfInputFormat     AS DDPIXELFORMAT PTR   ' // Video format written to the video port
   lpddpfVBIInputFormat  AS DDPIXELFORMAT PTR   ' // Input format of the VBI data
   lpddpfVBIOutputFormat AS DDPIXELFORMAT PTR   ' // Output format of the data
   dwVBIHeight           AS DWORD               ' // Specifies the number of lines of data within the vertical blanking interval.
   dwReserved1           AS DWORD               ' // Reserved for future use - set to zero
   dwReserved2           AS DWORD               ' // Reserved for future use - set to zero
END TYPE


'/*
' * DDVIDEOPORTBANDWIDTH
' */
' // Size = 32 bytes
TYPE DDVIDEOPORTBANDWIDTH DWORD
   dwSize               AS DWORD   ' // Size of the structure
   dwCaps               AS DWORD
   dwOverlay            AS DWORD   ' // Zoom factor at which overlay is supported
   dwColorkey           AS DWORD   ' // Zoom factor at which overlay w/ colorkey is supported
   dwYInterpolate       AS DWORD   ' // Zoom factor at which overlay w/ Y interpolation is supported
   dwYInterpAndColorkey AS DWORD   ' // Zoom factor at which ovelray w/ Y interpolation and colorkeying is supported
   dwReserved1          AS DWORD   ' // Reserved for future use - set to zero
   dwReserved2          AS DWORD   ' // Reserved for future use - set to zero
END TYPE


'/*
' * DDVIDEOPORTSTATUS
' */
' // Size = 56 bytes
TYPE DDVIDEOPORTSTATUS DWORD
   dwSize        AS DWORD                ' // Size of the structure
   bInUse        AS LONG                 ' // TRUE if video port is currently being used
   dwFlags       AS DWORD                ' // Currently not used
   dwReserved1   AS DWORD                ' // Reserved for future use
   VideoPortType AS DDVIDEOPORTCONNECT   ' // Information about the connection
   dwReserved2   AS DWORD                ' // Reserved for future use
   dwReserved3   AS DWORD                ' // Reserved for future use
END TYPE

'/*============================================================================
' *
' * Video Port Flags
' *
' * All flags are bit flags.
' *
' *==========================================================================*/

'/****************************************************************************
' *
' * VIDEOPORT DDVIDEOPORTCONNECT FLAGS
' *
' ****************************************************************************/

'/*
' * When this is set by the driver and passed to the client, this
' * indicates that the video port is capable of double clocking the data.
' * When this is set by the client, this indicates that the video port
' * should enable double clocking.  This flag is only valid with external
' * syncs.
' */
%DDVPCONNECT_DOUBLECLOCK         = &H00000001???

'/*
' * When this is set by the driver and passed to the client, this
' * indicates that the video port is capable of using an external VACT
' * signal. When this is set by the client, this indicates that the
' * video port should use the external VACT signal.
' */
%DDVPCONNECT_VACT                = &H00000002???

'/*
' * When this is set by the driver and passed to the client, this
' * indicates that the video port is capable of treating even fields
' * like odd fields and visa versa.  When this is set by the client,
' * this indicates that the video port should treat even fields like odd
' * fields.
' */
%DDVPCONNECT_INVERTPOLARITY      = &H00000004???

'/*
' * Indicates that any data written to the video port during the VREF
' * period will not be written into the frame buffer. This flag is read only.
' */
%DDVPCONNECT_DISCARDSVREFDATA    = &H00000008???

'/*
' * When this is set be the driver and passed to the client, this
' * indicates that the device will write half lines into the frame buffer
' * if half lines are provided by the decoder.  If this is set by the client,
' * this indicates that the decoder will be supplying half lines.
' */
%DDVPCONNECT_HALFLINE            = &H00000010???

'/*
' * Indicates that the signal is interlaced. This flag is only
' * set by the client.
' */
%DDVPCONNECT_INTERLACED          = &H00000020???

'/*
' * Indicates that video port is shareable and that this video port
' * will use the even fields.  This flag is only set by the client.
' */
%DDVPCONNECT_SHAREEVEN           = &H00000040???

'/*
' * Indicates that video port is shareable and that this video port
' * will use the odd fields.  This flag is only set by the client.
' */
%DDVPCONNECT_SHAREODD            = &H00000080???

'/****************************************************************************
' *
' * VIDEOPORT DDVIDEOPORTDESC CAPS
' *
' ****************************************************************************/

'/*
' * Flip can be performed automatically to avoid tearing.
' */
%DDVPCAPS_AUTOFLIP             = &H00000001???

'/*
' * Supports interlaced video
' */
%DDVPCAPS_INTERLACED           = &H00000002???

'/*
' * Supports non-interlaced video
' */
%DDVPCAPS_NONINTERLACED        = &H00000004???

'/*
' * Indicates that the device can return whether the current field
' * of an interlaced signal is even or odd.
' */
%DDVPCAPS_READBACKFIELD        = &H00000008???

'/*
' * Indicates that the device can return the current line of video
' * being written into the frame buffer.
' */
%DDVPCAPS_READBACKLINE         = &H00000010???

'/*
' * Allows two gen-locked video streams to share a single video port,
' * where one stream uses the even fields and the other uses the odd
' * fields. Separate parameters (including address, scaling,
' * cropping, etc.) are maintained for both fields.)
' */
%DDVPCAPS_SHAREABLE            = &H00000020???

'/*
' * Even fields of video can be automatically discarded.
' */
%DDVPCAPS_SKIPEVENFIELDS       = &H00000040???

'/*
' * Odd fields of video can be automatically discarded.
' */
%DDVPCAPS_SKIPODDFIELDS        = &H00000080???

'/*
' * Indicates that the device is capable of driving the graphics
' * VSYNC with the video port VSYNC.
' */
%DDVPCAPS_SYNCMASTER           = &H00000100???

'/*
' * Indicates that data within the vertical blanking interval can
' * be written to a different surface.
' */
%DDVPCAPS_VBISURFACE           = &H00000200???

'/*
' * Indicates that the video port can perform color operations
' * on the incoming data before it is written to the frame buffer.
' */
%DDVPCAPS_COLORCONTROL         = &H00000400???

'/*
' * Indicates that the video port can accept VBI data in a different
' * width or format than the regular video data.
' */
%DDVPCAPS_OVERSAMPLEDVBI       = &H00000800???

'/*
' * Indicates that the video port can write data directly to system memory
' */
%DDVPCAPS_SYSTEMMEMORY         = &H00001000???

'/*
' * Indicates that the VBI and video portions of the video stream can
' * be controlled by an independent processes.
' */
%DDVPCAPS_VBIANDVIDEOINDEPENDENT      = &H00002000???


'/****************************************************************************
' *
' * VIDEOPORT DDVIDEOPORTDESC FX
' *
' ****************************************************************************/

'/*
' * Limited cropping is available to crop out the vertical interval data.
' */
%DDVPFX_CROPTOPDATA         = &H00000001???

'/*
' * Incoming data can be cropped in the X direction before it is written
' * to the surface.
' */
%DDVPFX_CROPX            = &H00000002???

'/*
' * Incoming data can be cropped in the Y direction before it is written
' * to the surface.
' */
%DDVPFX_CROPY            = &H00000004???

'/*
' * Supports interleaving interlaced fields in memory.
' */
%DDVPFX_INTERLEAVE         = &H00000008???

'/*
' * Supports mirroring left to right as the video data is written
' * into the frame buffer.
' */
%DDVPFX_MIRRORLEFTRIGHT         = &H00000010???

'/*
' * Supports mirroring top to bottom as the video data is written
' * into the frame buffer.
' */
%DDVPFX_MIRRORUPDOWN         = &H00000020???

'/*
' * Data can be arbitrarily shrunk in the X direction before it
' * is written to the surface.
' */
%DDVPFX_PRESHRINKX         = &H00000040???

'/*
' * Data can be arbitrarily shrunk in the Y direction before it
' * is written to the surface.
' */
%DDVPFX_PRESHRINKY         = &H00000080???

'/*
' * Data can be binary shrunk (1/2, 1/4, 1/8, etc.) in the X
' * direction before it is written to the surface.
' */
%DDVPFX_PRESHRINKXB         = &H00000100???

'/*
' * Data can be binary shrunk (1/2, 1/4, 1/8, etc.) in the Y
' * direction before it is written to the surface.
' */
%DDVPFX_PRESHRINKYB         = &H00000200???

'/*
' * Data can be shrunk in increments of 1/x in the X direction
' * (where X is specified in the DDVIDEOPORTCAPS.dwPreshrinkXStep)
' * before it is written to the surface.
' */
%DDVPFX_PRESHRINKXS         = &H00000400???

'/*
' * Data can be shrunk in increments of 1/x in the Y direction
' * (where X is specified in the DDVIDEOPORTCAPS.dwPreshrinkYStep)
' * before it is written to the surface.
' */
%DDVPFX_PRESHRINKYS         = &H00000800???

'/*
' * Data can be arbitrarily stretched in the X direction before
' * it is written to the surface.
' */
%DDVPFX_PRESTRETCHX         = &H00001000???

'/*
' * Data can be arbitrarily stretched in the Y direction before
' * it is written to the surface.
' */
%DDVPFX_PRESTRETCHY         = &H00002000???

'/*
' * Data can be integer stretched in the X direction before it is
' * written to the surface.
' */
%DDVPFX_PRESTRETCHXN         = &H00004000???

'/*
' * Data can be integer stretched in the Y direction before it is
' * written to the surface.
' */
%DDVPFX_PRESTRETCHYN         = &H00008000???

'/*
' * Indicates that data within the vertical blanking interval can
' * be converted independently of the remaining video data.
' */
%DDVPFX_VBICONVERT         = &H00010000???

'/*
' * Indicates that scaling can be disabled for data within the
' * vertical blanking interval.
' */
%DDVPFX_VBINOSCALE         = &H00020000???

'/*
' * Indicates that the video data can ignore the left and right
' * cropping coordinates when cropping oversampled VBI data.
' */
%DDVPFX_IGNOREVBIXCROP         = &H00040000???

'/*
' * Indicates that interleaving can be disabled for data within the
' * vertical blanking interval.
' */
%DDVPFX_VBINOINTERLEAVE         = &H00080000???


'/****************************************************************************
' *
' * VIDEOPORT DDVIDEOPORTINFO FLAGS
' *
' ****************************************************************************/

'/*
' * Perform automatic flipping.   Auto-flipping is performed between
' * the overlay surface that was attached to the video port using
' * IDirectDrawVideoPort::AttachSurface and the overlay surfaces that
' * are attached to the surface via the IDirectDrawSurface::AttachSurface
' * method.  The flip order is the order in which the overlay surfaces
' * were. attached.
' */
%DDVP_AUTOFLIP            = &H00000001???

'/*
' * Perform conversion using the ddpfOutputFormat information.
' */
%DDVP_CONVERT            = &H00000002???

'/*
' * Perform cropping using the specified rectangle.
' */
%DDVP_CROP            = &H00000004???

'/*
' * Indicates that interlaced fields should be interleaved in memory.
' */
%DDVP_INTERLEAVE            = &H00000008???

'/*
' * Indicates that the data should be mirrored left to right as it's
' * written into the frame buffer.
' */
%DDVP_MIRRORLEFTRIGHT         = &H00000010???

'/*
' * Indicates that the data should be mirrored top to bottom as it's
' * written into the frame buffer.
' */
%DDVP_MIRRORUPDOWN         = &H00000020???

'/*
' * Perform pre-scaling/zooming based on the pre-scale parameters.
' */
%DDVP_PRESCALE            = &H00000040???

'/*
' * Ignore input of even fields.
' */
%DDVP_SKIPEVENFIELDS         = &H00000080???

'/*
' * Ignore input of odd fields.
' */
%DDVP_SKIPODDFIELDS         = &H00000100???

'/*
' * Drive the graphics VSYNCs using the video port VYSNCs.
' */
%DDVP_SYNCMASTER            = &H00000200???

'/*
' * The ddpfVBIOutputFormatFormat member contains data that should be used
' * to convert the data within the vertical blanking interval.
' */
%DDVP_VBICONVERT            = &H00000400???

'/*
' * Indicates that data within the vertical blanking interval
' * should not be scaled.
' */
%DDVP_VBINOSCALE            = &H00000800???

'/*
' * Indicates that these bob/weave decisions should not be
' * overriden by other interfaces.
' */
%DDVP_OVERRIDEBOBWEAVE         = &H00001000???

'/*
' * Indicates that the video data should ignore the left and right
' * cropping coordinates when cropping the VBI data.
' */
%DDVP_IGNOREVBIXCROP         = &H00002000???

'/*
' * Indicates that interleaving can be disabled for data within the
' * vertical blanking interval.
' */
%DDVP_VBINOINTERLEAVE         = &H00004000???


'/****************************************************************************
' *
' * DIRIRECTDRAWVIDEOPORT GETINPUTFORMAT/GETOUTPUTFORMAT FLAGS
' *
' ****************************************************************************/

'/*
' * Return formats for the video data
' */
%DDVPFORMAT_VIDEO         = &H00000001???

'/*
' * Return formats for the VBI data
' */
%DDVPFORMAT_VBI            = &H00000002???

'/****************************************************************************
' *
' * DIRIRECTDRAWVIDEOPORT SETTARGETSURFACE FLAGS
' *
' ****************************************************************************/

'/*
' * Surface should receive video data (and VBI data if a surface
' * is not explicitly attached for that purpose)
' */
%DDVPTARGET_VIDEO         = &H00000001???

'/*
' * Surface should receive VBI data
' */
%DDVPTARGET_VBI            = &H00000002???


'/****************************************************************************
' *
' * DIRIRECTDRAWVIDEOPORT WAITFORSYNC FLAGS
' *
' ****************************************************************************/

'/*
' * Waits until the beginning of the next VSYNC
' */
%DDVPWAIT_BEGIN            = &H00000001???

'/*
' * Waits until the end of the next/current VSYNC
' */
%DDVPWAIT_END            = &H00000002???

'/*
' * Waits until the beginning of the specified line
' */
%DDVPWAIT_LINE            = &H00000003???

'/****************************************************************************
' *
' * DIRECTDRAWVIDEOPORT FLIP FLAGS
' *
' ****************************************************************************/

'/*
' * Flips the normal video surface
' */
%DDVPFLIP_VIDEO            = &H00000001???

'/*
' * Flips the VBI surface
' */
%DDVPFLIP_VBI            = &H00000002???

'/****************************************************************************
' *
' * DIRIRECTDRAWVIDEOPORT GETVIDEOSIGNALSTATUS VALUES
' *
' ****************************************************************************/

'/*
' * No video signal is present at the video port
' */
%DDVPSQ_NOSIGNAL            = &H00000001???

'/*
' * A valid video signal is present at the video port
' */
%DDVPSQ_SIGNALOK            = &H00000002???

'/****************************************************************************
' *
' * VIDEOPORTBANDWIDTH Flags
' *
' ****************************************************************************/

'/*
' * The specified height/width refer to the size of the video port data
' * written into memory, after prescaling has occured.
' */
%DDVPB_VIDEOPORT            = &H00000001???

'/*
' * The specified height/width refer to the source size of the overlay.
' */
%DDVPB_OVERLAY            = &H00000002???

'/*
' * This is a query for the device to return which caps this device requires.
' */
%DDVPB_TYPE            = &H00000004???

'/****************************************************************************
' *
' * VIDEOPORTBANDWIDTH Caps
' *
' ****************************************************************************/

'/*
' * The bandwidth for this device is dependant on the overlay source size.
' */
%DDVPBCAPS_SOURCE         = &H00000001???

'/*
' * The bandwidth for this device is dependant on the overlay destination
' * size.
' */
%DDVPBCAPS_DESTINATION         = &H00000002???

'/****************************************************************************
' *
' * DDVIDEOPORTCONTAINER CreateVideoPort flags
' *
' ****************************************************************************/

'/*
' * The process only wants to control the VBI portion of the video stream.
' */
%DDVPCREATE_VBIONLY         = &H00000001???

'/*
' * The process only wants to control the non-VBI (video) portion of
' * the video stream.
' */
%DDVPCREATE_VIDEOONLY         = &H00000002???

'/****************************************************************************
' *
' * DDVIDEOPORTSTATUS flags
' *
' ****************************************************************************/

'/*
' * The video port interface is only controlling the VBI portion of the
' * video stream
' */
%DDVPSTATUS_VBIONLY           = &H00000001???

'/*
' * The video port interface is only controlling the video portion of the
' * video stream
' */
%DDVPSTATUS_VIDEOONLY         = &H00000002???


'/*
' * API's
' */
'typedef HRESULT (FAR PASCAL * LPDDENUMVIDEOCALLBACK)(LPDDVIDEOPORTCAPS, LPVOID);

'FUNCTION DDENUMVIDEOCALLBACK (BYREF DDVIDEOPORTCAPS, BYVAL DWORD) AS LONG
'END FUNCTION


'/*
' * INTERFACES FOLLOW:
' *   IDirectDrawVideoPort
' *   IVideoPort
' */

'/*
' * IDirectDrawVideoPortContainer
' */

'DECLARE_INTERFACE_( IDDVideoPortContainer, IUnknown )
'{
'    /*** IUnknown methods ***/
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) PURE;
'    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG,Release) (THIS) PURE;
'    /*** IDirectDrawVideoPort methods ***/
'    STDMETHOD(CreateVideoPort)(THIS_ DWORD, LPDDVIDEOPORTDESC, LPDIRECTDRAWVIDEOPORT FAR *, IUnknown FAR *) PURE;
'    STDMETHOD(EnumVideoPorts)(THIS_ DWORD, LPDDVIDEOPORTCAPS, LPVOID,LPDDENUMVIDEOCALLBACK ) PURE;
'    STDMETHOD(GetVideoPortConnectInfo)(THIS_ DWORD, LPDWORD, LPDDVIDEOPORTCONNECT ) PURE;
'    STDMETHOD(QueryVideoPortStatus)(THIS_ DWORD, LPDDVIDEOPORTSTATUS ) PURE;
'};

' ########################################################################################
' Interface name = IDDVideoPortContainer
' IID = {6C142760-A733-11CE-A521-0020AF0BE560}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDDVideoPortContainer_INTERFACE_DEFINED)
    %IDDVideoPortContainer_INTERFACE_DEFINED = 1

INTERFACE IDDVideoPortContainer $IID_IDDVideoPortContainer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateVideoPort ( _                           ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpDDVideoPortDesc AS DDVIDEOPORTDESC _       ' __in LPDDVIDEOPORTDESC lpDDVideoPortDesc
   , BYREF lplpDDVideoPort AS IUnknown _                ' __out LPDIRECTDRAWVIDEOPORT FAR* lplpDDVideoPort
   , BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown FAR* pUnkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumVideoPorts ( _                            ' VTable offset = 16
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpDDVideoPortCaps AS DDVIDEOPORTCAPS _       ' __in LPDDVIDEOPORTCAPS lpDDVideoPortCaps
   , BYVAL lpContext AS DWORD _                         ' __in LPVOID lpContext
   , BYVAL lpEnumVideoCallback AS DWORD _               ' __in LPDDENUMVIDEOCALLBACK lpEnumVideoCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoPortConnectInfo ( _                   ' VTable offset = 20
     BYVAL dwPortId AS DWORD _                          ' __in DWORD dwPortId
   , BYVAL lpNumEntries AS DWORD _                      ' __in LPDWORD lpNumEntries
   , BYREF lpConnectInfo AS DDVIDEOPORTCONNECT _        ' __out LPDDVIDEOPORTCONNECT lpConnectInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryVideoPortStatus ( _                      ' VTable offset = 24
     BYVAL dwPortId AS DWORD _                          ' __in DWORD dwPortId
   , BYREF lpVPStatus AS DDVIDEOPORTSTATUS _            ' __out LPDDVIDEOPORTSTATUS lpVPStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDDVideoPortContainer_INTERFACE_DEFINED__ */

'/*
' * IDirectDrawVideoPort
' */

'DECLARE_INTERFACE_( IDirectDrawVideoPort, IUnknown )
'{
'    STDMETHOD(Flip)(THIS_ LPDIRECTDRAWSURFACE, DWORD) PURE;
'    STDMETHOD(GetBandwidthInfo)(THIS_ LPDDPIXELFORMAT, DWORD, DWORD, DWORD, LPDDVIDEOPORTBANDWIDTH) PURE;
'    STDMETHOD(GetColorControls)(THIS_ LPDDCOLORCONTROL) PURE;
'    STDMETHOD(GetInputFormats)(THIS_ LPDWORD, LPDDPIXELFORMAT, DWORD) PURE;
'    STDMETHOD(GetOutputFormats)(THIS_ LPDDPIXELFORMAT, LPDWORD, LPDDPIXELFORMAT, DWORD) PURE;
'    STDMETHOD(GetFieldPolarity)(THIS_ LPBOOL) PURE;
'    STDMETHOD(GetVideoLine)(THIS_ LPDWORD) PURE;
'    STDMETHOD(GetVideoSignalStatus)(THIS_ LPDWORD) PURE;
'    STDMETHOD(SetColorControls)(THIS_ LPDDCOLORCONTROL) PURE;
'    STDMETHOD(SetTargetSurface)(THIS_ LPDIRECTDRAWSURFACE, DWORD) PURE;
'    STDMETHOD(StartVideo)(THIS_ LPDDVIDEOPORTINFO) PURE;
'    STDMETHOD(StopVideo)(THIS) PURE;
'    STDMETHOD(UpdateVideo)(THIS_ LPDDVIDEOPORTINFO) PURE;
'    STDMETHOD(WaitForSync)(THIS_ DWORD, DWORD, DWORD) PURE;
'};

' ########################################################################################
' Interface name = IDirectDrawVideoPort
' IID = {B36D93E0-2B43-11CF-A2DE-00AA00B93356}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDirectDrawVideoPort_INTERFACE_DEFINED)
    %IDirectDrawVideoPort_INTERFACE_DEFINED = 1

INTERFACE IDirectDrawVideoPort $IID_IDirectDrawVideoPort

   INHERIT IUnknown


   ' =====================================================================================
   METHOD Flip ( _                                      ' VTable offset = 12
     BYVAL lpDDSurface AS IDirectDrawSurface _          ' __in LPDIRECTDRAWSURFACE lpDDSurface
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBandwidthInfo ( _                          ' VTable offset = 16
     BYREF lpddpfFormat AS DDPIXELFORMAT _              ' __in LPDDPIXELFORMAT lpddpfFormat
   , BYVAL dwWidth AS DWORD _                           ' __in DWORD dwWidth
   , BYVAL dwHeight AS DWORD _                          ' __in DWORD dwHeight
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpBandwidth AS DDVIDEOPORTBANDWIDTH _        ' __out LPDDVIDEOPORTBANDWIDTH lpBandwidth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorControls ( _                          ' VTable offset = 20
     BYREF lpColorControl AS DDCOLORCONTROL _           ' __out LPDDCOLORCONTROL lpColorControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputFormats ( _                           ' VTable offset = 24
     BYVAL lpNumFormats AS DWORD _                      ' __in LPDWORD lpNumFormats
   , BYREF lpFormats AS DDPIXELFORMAT _                 ' __out LPDDPIXELFORMAT lpFormats
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputFormats ( _                          ' VTable offset = 28
     BYREF lpInputFormat AS DDPIXELFORMAT _             ' __in LPDDPIXELFORMAT lpInputFormat
   , BYREF lpNumFormats AS DWORD _                      ' __inout LPDWORD lpNumFormats
   , BYREF lpFormats AS DDPIXELFORMAT _                 ' __out LPDDPIXELFORMAT lpFormats
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFieldPolarity ( _                          ' VTable offset = 32
     BYREF lpbFieldPolarity AS LONG _                   ' __out LPBOOL lpbFieldPolarity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoLine ( _                              ' VTable offset = 36
     BYREF lpdwLine AS DWORD _                          ' __out LPDWORD lpdwLine
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoSignalStatus ( _                      ' VTable offset = 40
     BYREF lpdwStatus AS DWORD _                        ' __out LPDWORD lpdwStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColorControls ( _                          ' VTable offset = 44
     BYREF lpColorControl AS DDCOLORCONTROL _           ' __in LPDDCOLORCONTROL lpColorControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTargetSurface ( _                          ' VTable offset = 48
     BYVAL lpDDSurface AS IDirectDrawSurface _          ' __in LPDIRECTDRAWSURFACE lpDDSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StartVideo ( _                                ' VTable offset = 52
     BYREF lpVideoInfo AS DDVIDEOPORTINFO _             ' __in LPDDVIDEOPORTINFO lpVideoInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StopVideo ( _                                 ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateVideo ( _                               ' VTable offset = 60
     BYREF lpVideoInfo AS DDVIDEOPORTINFO _             ' __in LPDDVIDEOPORTINFO lpVideoInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WaitForSync ( _                               ' VTable offset = 64
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwLine AS DWORD _                            ' __in DWORD dwLine
   , BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDirectDrawVideoPort_INTERFACE_DEFINED__ */
