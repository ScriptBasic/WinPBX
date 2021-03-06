' ########################################################################################
' Microsoft Windows
' File: AudioAPOTypes.inc
' Copyright (c) 2011 Jos� Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AUDIOAPOTYPES_INC = 1

'typedef LONGLONG    HNSTIME;   // hundred nanosecond unit
'typedef LONGLONG    MFTIME;    // hundred nanosecond unit

'typedef float       FLOAT32;   // float
'typedef double      FLOAT64;   // double

'// Validation flags for APO_CONNECTION_PROPERTY. Each APO connection has
'// an APO_CONNECTION_PROPERTY structure associated with it. The buffer
'// for each connection may be either invalid, valid, or silent.
'typedef enum APO_BUFFER_FLAGS
'{
'    // BUFFER_INVALID means that there is no valid data in  the connection
'    // buffer. The buffer pointer will still be valid and capable of holding
'    // the amount of valid audio data specified in the APO_CONNECTION_PROPERTY.
'    // The processor will mark every connection BUFFER_INVALID before running
'    // the IAudioOutputEndpoint::GetOutputDataPointer,
'    // IAudioInputEndpointRT::GetInputDataPointer, or
'    // IAudioProcessingObjectRT::APOProcess each time its IAudioProcess::Process
'    // routine is called.
'    BUFFER_INVALID  = 0,

'    // Connection buffer has valid data. This is the "normal" operational
'    // state of the connection buffer. An APO will set this flag once it
'    // writes valid data into a buffer.
'    BUFFER_VALID    = 1,

'    // The connection buffer should be treated as if it contains silence.
'    // APOs will mark their output connection buffers as silent (instead
'    // of writing silence into the buffer) if they generate a buffer of
'    // silence. This typically only happens when the buffer(s) going in
'    // are marked BUFFER_SILENT.
'    BUFFER_SILENT   = 2
'} APO_BUFFER_FLAGS;

' enum APO_BUFFER_FLAGS
MACRO APO_BUFFER_FLAGS_ENUM = DWORD
%BUFFER_INVALID = 0???
%BUFFER_VALID   = 1???
%BUFFER_SILENT  = 2???

'// This structure contains the dynamically changing connection properties.
'// The connection between APOs ends up resolving to the APO_CONNECTION_PROPERTY
'// structure for the IAudioProcessingObjectRT::APOProcess call.  This structure
'// is passed in IAudioInputEndpointRT::GetInputDataPointer and
'// IAudioOutputEndpointRT::ReleaseOutputDataPointer.
'typedef struct APO_CONNECTION_PROPERTY
'{
'    // The connection buffer. APOs use this buffer to read and write
'    // audio data.
'    //
'    // Alignment required
'    // (128 bit or frame aligned)
'    //            |
'    //      +-----+
'    //      V
'    //      +-------------------------------------------------------------+
'    //      |                                                             |
'    //      |                                                             |
'    //      |                     audio buffer                            |
'    //      |                                                             |
'    //      |                                                             |
'    //      +-------------------------------------------------------------+
'    //      ^
'    //      |
'    //   pBuffer
'    //
'    UINT_PTR pBuffer;

'    // Number of valid frames in the connection buffer. This must
'    // be less than or equal to APO_CONNECTION_DESCRIPTOR.u32MaxFrameCount.
'    // An APO will use the valid frame count to determine how much data to
'    // process on an input buffer. An APO will set the valid frame count
'    // upon writing data into its output connection(s).
'    UINT32 u32ValidFrameCount;

'    // Connection flags for this buffer.  Tells APOs if the buffer is valid,
'    // in valid, or silent. See APO_BUFFER_FLAGS.
'    APO_BUFFER_FLAGS u32BufferFlags;

'    // A tag identifying a valid APO_CONNECTION_PROPERTY structure.
'    UINT32 u32Signature;
'} APO_CONNECTION_PROPERTY;

' // Size = 16 bytes
TYPE APO_CONNECTION_PROPERTY DWORD
   pBuffer            AS DWORD                   ' UINT_PTR
   u32ValidFrameCount AS DWORD                   ' UINT32
   u32BufferFlags     AS APO_BUFFER_FLAGS_ENUM   ' APO_BUFFER_FLAGS
   u32Signature       AS DWORD                   ' UINT32
END TYPE
