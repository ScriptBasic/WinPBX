' ########################################################################################
' Microsoft Windows
' File: mfapi.inc
' Contents: Microsoft Windows Media Foundation
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

'//
'// MFAPI.h is the header containing the APIs for using the MF platform.
'//

#INCLUDE THIS ONCE
%MFAPI_INC = 1

#INCLUDE ONCE "amvideo.inc"    ' for VIDEOINFOHEADER structure
#INCLUDE ONCE "dvdmedia.inc"   ' for VIDEOINFOHEADER2 structure
#INCLUDE ONCE "strmif.inc"     ' for AM_MEDIA_TYPE structure

'#pragma pack(push, mfhrds)
#INCLUDE ONCE "mfobjects.inc"
'#pragma pack(pop, mfhrds)

#INCLUDE ONCE "mmreg.inc"

#INCLUDE ONCE "avrt.inc"
'#ifndef AVRT_DATA
'#define AVRT_DATA
'#endif
'#ifndef AVRT_BSS
'#define AVRT_BSS
'#endif

'#if !defined(MF_VERSION)
'#if (WINVER >= _WIN32_WINNT_WIN7)
'#define MF_SDK_VERSION 0x0002
'#else // Vista
'#define MF_SDK_VERSION 0x0001
'#endif // (WINVER >= _WIN32_WINNT_WIN7)
'#define MF_API_VERSION 0x0070 // This value is unused in the Win7 release and left at its Vista release value
'#define MF_VERSION (MF_SDK_VERSION << 16 | MF_API_VERSION)
'#endif //!defined(MF_VERSION)

#IF NOT %DEF(%MF_VERSION)
%MF_SDK_VERSION = &H0001
%MF_API_VERSION = &H0070  ' // Increment this whenever you change an API
%MF_VERSION     = &H10070
#ENDIF

%MFSTARTUP_NOSOCKET = &H1
%MFSTARTUP_LITE = %MFSTARTUP_NOSOCKET
%MFSTARTUP_FULL = 0

'////////////////////////////////////////////////////////////////////////////////
'///////////////////////////////   Startup/Shutdown  ////////////////////////////
'////////////////////////////////////////////////////////////////////////////////

'//
'// Initializes the platform object.
'// Must be called before using Media Foundation.
'// A matching MFShutdown call must be made when the application is done using
'// Media Foundation.
'// The "Version" parameter should be set to MF_API_VERSION.
'// Application should not call MFStartup / MFShutdown from workqueue threads
'//

DECLARE FUNCTION MFStartup IMPORT "MFPLAT.DLL" ALIAS "MFStartup" ( _
   BYVAL Version AS DWORD _                             ' __in ULONG Version
 , BYVAL dwFlags As DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

'//
'// Shuts down the platform object.
'// Releases all resources including threads.
'// Application should call MFShutdown the same number of times as MFStartup
'// Application should not call MFStartup / MFShutdown from workqueue threads
'//

DECLARE FUNCTION MFShutdown IMPORT "MFPLAT.DLL" ALIAS "MFShutdown" () AS LONG

'////////////////////////////////////////////////////////////////////////////////
'/////////////////////////////////    Platform    ///////////////////////////////
'////////////////////////////////////////////////////////////////////////////////

'//
'// These functions can be used to keep the MF platform object in place.
'// Every call to MFLockPlatform should have a matching call to MFUnlockPlatform
'//

DECLARE FUNCTION MFLockPlatform IMPORT "MFPLAT.DLL" ALIAS "MFLockPlatform" () AS LONG
DECLARE FUNCTION MFUnlockPlatform IMPORT "MFPLAT.DLL" ALIAS "MFUnlockPlatform" () AS LONG

'///////////////////////////////////////////////////////////////////////////////

'//
'// MF workitem functions
'//
'typedef unsigned __int64 MFWORKITEM_KEY;

DECLARE FUNCTION MFPutWorkItem IMPORT "MFPLAT.DLL" ALIAS "MFPutWorkItem" ( _
   BYVAL dwQueue AS DWORD _                             ' __in DWORD dwQueue
 , BYVAL pCallback AS IMFAsyncCallback _                ' __in IMFAsyncCallback* pCallback
 , BYVAL pState AS IUnknown _                           ' __in IUnknown* pState
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFPutWorkItemEx IMPORT "MFPLAT.DLL" ALIAS "MFPutWorkItemEx" ( _
   BYVAL dwQueue AS DWORD _                             ' __in DWORD dwQueue
 , BYVAL pResult AS IMFAsyncResult _                    ' __in IMFAsyncResult* pResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFScheduleWorkItem IMPORT "MFPLAT.DLL" ALIAS "MFScheduleWorkItem" ( _
   BYVAL pCallback AS IMFAsyncCallback _                ' __in  IMFAsyncCallback* pCallback
 , BYVAL pState AS IUnknown _                           ' __in  IUnknown* pState
 , BYVAL Timeout AS QUAD _                              ' __in  INT64 Timeout
 , BYREF pKey AS QUAD _                                 ' __out_opt MFWORKITEM_KEY* pKey
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFScheduleWorkItemEx IMPORT "MFPLAT.DLL" ALIAS "MFScheduleWorkItemEx" ( _
   BYVAL pResult AS IMFAsyncResult _                    ' __in  IMFAsyncResult* pResult
 , BYVAL Timeout AS QUAD _                              ' __in  INT64 Timeout
 , BYREF pKey AS QUAD _                                 ' __out_opt MFWORKITEM_KEY* pKey
 ) AS LONG                                              ' HRESULT

'//
'//   The CancelWorkItem method is used by objects to cancel scheduled operation
'//   Due to asynchronous nature of timers, application might still get a
'//   timer callback after MFCancelWorkItem has returned.
'//
DECLARE FUNCTION MFCancelWorkItem IMPORT "MFPLAT.DLL" ALIAS "MFCancelWorkItem" ( _
   BYVAL Key AS QUAD _                                  ' __in MFWORKITEM_KEY Key
 ) AS LONG                                              ' HRESULT

'///////////////////////////////////////////////////////////////////////////////

'//
'// MF periodic callbacks
'//

DECLARE FUNCTION MFGetTimerPeriodicity IMPORT "MFPLAT.DLL" ALIAS "MFGetTimerPeriodicity" ( _
   BYREF Periodicity AS DWORD _                         ' __out DWORD* Periodicity
 ) AS LONG                                              ' HRESULT

'typedef void (*MFPERIODICCALLBACK)(IUnknown* pContext);
'SUB MFPERIODICCALLBACK (BYVAL pContext AS IUnknown)

DECLARE FUNCTION MFAddPeriodicCallback IMPORT "MFPLAT.DLL" ALIAS "MFAddPeriodicCallback" ( _
   BYVAL Callback AS DWORD _                            ' __in  MFPERIODICCALLBACK Callback
 , BYVAL pContext AS IUnknown _                         ' __in  IUnknown* pContext
 , BYREF pdwKey AS DWORD _                              ' __out_opt DWORD* pdwKey
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFRemovePeriodicCallback IMPORT "MFPLAT.DLL" ALIAS "MFRemovePeriodicCallback" ( _
   BYVAL dwKey AS DWORD _                               ' __in DWORD dwKey
 ) AS LONG                                              ' HRESULT

'///////////////////////////////////////////////////////////////////////////////

'//
'// MF work queues
'//

'#if (WINVER >= _WIN32_WINNT_WIN7)
'//
'// MFASYNC_WORKQUEUE_TYPE: types of work queue used by MFAllocateWorkQueueEx
'//
' enum MFASYNC_WORKQUEUE_TYPE
' // MF_STANDARD_WORKQUEUE: Work queue in a thread without Window
' // message loop.
%MF_STANDARD_WORKQUEUE = 0

' // MF_WINDOW_WORKQUEUE: Work queue in a thread running Window
' // Message loop that calls PeekMessage() / DispatchMessage()..
%MF_WINDOW_WORKQUEUE = 1

DECLARE FUNCTION MFAllocateWorkQueueEx IMPORT "MFPLAT.DLL" ALIAS "MFAllocateWorkQueueEx" ( _
   BYVAL WorkQueueType AS LONG _                        ' __in MFASYNC_WORKQUEUE_TYPE WorkQueueType
 , BYREF pdwWorkQueue AS DWORD _                        ' __out OUT DWORD * pdwWorkQueue
 ) AS LONG                                              ' HRESULT
'#endif // (WINVER >= _WIN32_WINNT_WIN7)

'//
'// Allocate a standard work queue. the behaviour is the same with:
'// MFAllocateWorkQueueEx( MF_STANDARD_WORKQUEUE, pdwWorkQueue )
'//
DECLARE FUNCTION MFAllocateWorkQueue IMPORT "MFPLAT.DLL" ALIAS "MFAllocateWorkQueue" ( _
   BYREF pdwWorkQueue AS DWORD _                        ' __out DWORD* pdwWorkQueue
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFLockWorkQueue IMPORT "MFPLAT.DLL" ALIAS "MFLockWorkQueue" ( _
   BYVAL dwWorkQueue AS DWORD _                         ' __in DWORD dwWorkQueue
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFUnlockWorkQueue IMPORT "MFPLAT.DLL" ALIAS "MFUnlockWorkQueue" ( _
   BYVAL dwWorkQueue AS DWORD _                         ' __in DWORD dwWorkQueue
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFBeginRegisterWorkQueueWithMMCSS IMPORT "MFPLAT.DLL" ALIAS "MFBeginRegisterWorkQueueWithMMCSS" ( _
   BYVAL dwWorkQueueId AS DWORD _                       ' __in DWORD dwWorkQueueId
 , BYREF wszClass AS WSTRINGZ _                         ' __in LPCWSTR wszClass
 , BYVAL dwTaskId AS DWORD _                            ' __in DWORD dwTaskId
 , BYVAL pDoneCallback AS IMFAsyncCallback _            ' __in IMFAsyncCallback* pDoneCallback
 , BYREF pDoneState AS IUnknown _                       ' __in IUnknown* pDoneState
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFEndRegisterWorkQueueWithMMCSS IMPORT "MFPLAT.DLL" ALIAS "MFEndRegisterWorkQueueWithMMCSS" ( _
   BYVAL pResult AS IUnknown _                          ' __in IMFAsyncResult* pResult
 , BYREF pdwTaskId AS DWORD _                           ' __out DWORD* pdwTaskId
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFBeginUnregisterWorkQueueWithMMCSS IMPORT "MFPLAT.DLL" ALIAS "MFBeginUnregisterWorkQueueWithMMCSS" ( _
   BYVAL dwWorkQueueId AS DWORD _                       ' __in DWORD dwWorkQueueId
 , BYVAL pDoneCallback AS IMFAsyncCallback _            ' __in IMFAsyncCallback* pDoneCallback
 , BYVAL pDoneState AS IUnknown _                       ' __in IUnknown* pDoneState
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFEndUnregisterWorkQueueWithMMCSS IMPORT "MFPLAT.DLL" ALIAS "MFEndUnregisterWorkQueueWithMMCSS" ( _
   BYVAL pResult AS IMFAsyncResult _                    ' __in IMFAsyncResult* pResult
 ) AS LONG                                              ' HRESULT

' // Removed in the Windows 7 SDK
'DECLARE FUNCTION MFSetWorkQueueClass IMPORT "MFPLAT.DLL" ALIAS "MFSetWorkQueueClass" ( _
'   BYVAL dwWorkQueueId AS DWORD _                       ' __in DWORD dwWorkQueueId
' , BYREF szClass AS WSTRINGZ _                          ' __in LPCWSTR szClass
' ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFGetWorkQueueMMCSSClass IMPORT "MFPLAT.DLL" ALIAS "MFGetWorkQueueMMCSSClass" ( _
   BYVAL dwWorkQueueId AS DWORD _                       ' __in DWORD dwWorkQueueId
 , BYREF pwszClass AS WSTRINGZ _                        ' __in LPWSTR pwszClass
 , BYREF pcchClass AS DWORD _                           ' __in_out DWORD *pcchClass
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFGetWorkQueueMMCSSTaskId IMPORT "MFPLAT.DLL" ALIAS "MFGetWorkQueueMMCSSTaskId" ( _
   BYVAL dwWorkQueueId AS DWORD _                       ' __in DWORD dwWorkQueueId
 , BYREF pdwTaskId AS DWORD _                           ' __out LPDWORD pdwTaskId
 ) AS LONG                                              ' HRESULT

'///////////////////////////////////////////////////////////////////////////////
'/////////////////////////////////    Async Model //////////////////////////////
'///////////////////////////////////////////////////////////////////////////////

'//
'// Instantiates the MF-provided Async Result implementation
'//

DECLARE FUNCTION MFCreateAsyncResult IMPORT "MFPLAT.DLL" ALIAS "MFGetWorkQueueMMCSSTaskId" ( _
   BYVAL punkObject AS IUnknown _                       ' __in IUnknown* punkObject
 , BYVAL pCallback AS IMFAsyncCallback _                ' __in IMFAsyncCallback* pCallback
 , BYVAL punkState AS IUnknown _                        ' __in IUnknown* punkState
 , BYREF ppAsyncResult AS IMFAsyncResult _              ' __out IMFAsyncResult ** ppAsyncResult
 ) AS LONG                                              ' HRESULT

'//
'// Helper for calling IMFAsyncCallback::Invoke
'//

DECLARE FUNCTION MFInvokeCallback IMPORT "MFPLAT.DLL" ALIAS "MFInvokeCallback" ( _
   BYVAL pAsyncResult AS IMFAsyncResult _               ' __in IMFAsyncResult* pAsyncResult
 ) AS LONG                                              ' HRESULT

'//
'// MFASYNCRESULT struct.
'// Any implementation of IMFAsyncResult must inherit from this struct;
'// the Media Foundation workqueue implementation depends on this.
'//

' // Size = 40 bytes
TYPE MFASYNCRESULT DWORD
   AsyncResult        AS DWORD PTR    ' IMFAsyncResult
   overlapped         AS OVERLAPPED
   pCallback          AS DWORD        ' IMFAsyncCallback*
   hrStatusResult     AS LONG         ' HRESULT
   dwBytesTransferred AS DWORD        ' DWORD
   hEvent             AS DWORD        ' HANDLE
END TYPE

'///////////////////////////////////////////////////////////////////////////////
'/////////////////////////////////    Files       //////////////////////////////
'///////////////////////////////////////////////////////////////////////////////

'//
'// Regardless of the access mode with which the file is opened, the sharing
'// permissions will allow shared reading and deleting.
'//

DECLARE FUNCTION MFCreateFile IMPORT "MFPLAT.DLL" ALIAS "MFCreateFile" ( _
   BYVAL AccessMode AS LONG _                           ' __in  MF_FILE_ACCESSMODE  AccessMode
 , BYVAL OpenMode AS LONG _                             ' __in  MF_FILE_OPENMODE    OpenMode
 , BYVAL fFlags AS DWORD _                              ' __in  MF_FILE_FLAGS       fFlags
 , BYREF pwszFileURL AS WSTRINGZ _                      ' __in  LPCWSTR             pwszFileURL
 , BYREF ppIByteStream AS IMFByteStream _               ' __out IMFByteStream       **ppIByteStream
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateTempFile IMPORT "MFPLAT.DLL" ALIAS "MFCreateTempFile" ( _
   BYVAL AccessMode AS LONG _                           ' __in  MF_FILE_ACCESSMODE  AccessMode
 , BYVAL OpenMode AS LONG _                             ' __in  MF_FILE_OPENMODE    OpenMode
 , BYVAL fFlags AS DWORD _                              ' __in  MF_FILE_FLAGS       fFlags
 , BYREF ppIByteStream AS IMFByteStream _               ' __out IMFByteStream       **ppIByteStream
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFBeginCreateFile IMPORT "MFPLAT.DLL" ALIAS "MFBeginCreateFile" ( _
   BYVAL AccessMode AS LONG _                           ' __in  MF_FILE_ACCESSMODE  AccessMode
 , BYVAL OpenMode AS LONG _                             ' __in  MF_FILE_OPENMODE    OpenMode
 , BYVAL fFlags AS DWORD _                              ' __in  MF_FILE_FLAGS       fFlags
 , BYREF pwszFilePath AS WSTRINGZ _                     ' __in  LPCWSTR             pwszFilePath
 , BYVAL pCallback AS IMFAsyncCallback _                ' __in  IMFAsyncCallback*  pCallback
 , BYVAL pState AS IUnknown _                           ' __in  IUnknown*          pState
 , BYREF ppCancelCookie AS IUnknown _                   ' __out IUnknown **         ppCancelCookie
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFEndCreateFile IMPORT "MFPLAT.DLL" ALIAS "MFEndCreateFile" ( _
   BYVAL pResult AS IMFAsyncResult _                    ' __in  IMFAsyncResult* pResult
 , BYREF ppFile AS IMFByteStream _                      ' __out IMFByteStream ** ppFile
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCancelCreateFile IMPORT "MFPLAT.DLL" ALIAS "MFCancelCreateFile" ( _
   BYVAL pCancelCookie AS IUnknown _                    ' __in IUnknown* pCancelCookie
 ) AS LONG                                              ' HRESULT

'///////////////////////////////////////////////////////////////////////////////
'/////////////////////////////////    Buffers     //////////////////////////////
'///////////////////////////////////////////////////////////////////////////////

'//
'// Creates an IMFMediaBuffer in memory
'//

DECLARE FUNCTION MFCreateMemoryBuffer IMPORT "MFPLAT.DLL" ALIAS "MFCreateMemoryBuffer" ( _
   BYVAL cbMaxLength AS DWORD _                         ' __in DWORD              cbMaxLength
 , BYREF ppBuffer AS IMFMediaBuffer _                   ' __out IMFMediaBuffer ** ppBuffer
 ) AS LONG                                              ' HRESULT

'//
'// Creates an IMFMediaBuffer wrapper at the given offset and length
'// within an existing IMFMediaBuffer
'//

DECLARE FUNCTION MFCreateMediaBufferWrapper IMPORT "MFPLAT.DLL" ALIAS "MFCreateMediaBufferWrapper" ( _
   BYVAL pBuffer AS IMFMediaBuffer _                    ' __in IMFMediaBuffer*    pBuffer
 , BYVAL cbOffset AS DWORD _                            ' __in DWORD              cbOffset
 , BYVAL dwLength AS DWORD _                            ' __in DWORD              dwLength
 , BYREF ppBuffer AS IMFMediaBuffer _                   ' __out IMFMediaBuffer ** ppBuffer
 ) AS LONG                                              ' HRESULT

'//
'// Creates a legacy buffer (IMediaBuffer) wrapper at the given offset within
'// an existing IMFMediaBuffer.
'// pSample is optional.  It can point to the original IMFSample from which this
'// IMFMediaBuffer came.  If provided, then *ppMediaBuffer will succeed
'// QueryInterface for IID_IMFSample, from which the original sample's attributes
'// can be obtained
'//

DECLARE FUNCTION MFCreateLegacyMediaBufferOnMFMediaBuffer IMPORT "MFPLAT.DLL" ALIAS "MFCreateLegacyMediaBufferOnMFMediaBuffer" ( _
   BYVAL pSample AS IMFSample _                         ' __in_opt IMFSample*   pSample
 , BYVAL pMFMediaBuffer AS IMFMediaBuffer _             ' __in IMFMediaBuffer*  pMFMediaBuffer
 , BYVAL cbOffset AS DWORD _                            ' __in DWORD            cbOffset
 , BYREF ppMediaBuffer AS IMediaBuffer _                ' __out IMediaBuffer ** ppMediaBuffer
 ) AS LONG                                              ' HRESULT

'//
'// Create a DirectX surface buffer
'//

DECLARE FUNCTION MFCreateDXSurfaceBuffer IMPORT "MFPLAT.DLL" ALIAS "MFCreateDXSurfaceBuffer" ( _
   BYREF riid AS GUID _                                 ' __in REFIID             riid
 , BYVAL punkSurface AS IUnknown _                      ' __in IUnknown*          punkSurface
 , BYVAL fBottomUpWhenLinear AS LONG _                  ' __in BOOL               fBottomUpWhenLinear
 , BYREF ppBuffer AS IMFMediaBuffer _                   ' __out IMFMediaBuffer ** ppBuffer
 ) AS LONG                                              ' HRESULT

'//
'// Create an aligned memory buffer.
'// The following constants were chosen for parity with the alignment constants
'// in ntioapi.h
'//

%MF_1_BYTE_ALIGNMENT       = &H00000000???
%MF_2_BYTE_ALIGNMENT       = &H00000001???
%MF_4_BYTE_ALIGNMENT       = &H00000003???
%MF_8_BYTE_ALIGNMENT       = &H00000007???
%MF_16_BYTE_ALIGNMENT      = &H0000000f???
%MF_32_BYTE_ALIGNMENT      = &H0000001f???
%MF_64_BYTE_ALIGNMENT      = &H0000003f???
%MF_128_BYTE_ALIGNMENT     = &H0000007f???
%MF_256_BYTE_ALIGNMENT     = &H000000ff???
%MF_512_BYTE_ALIGNMENT     = &H000001ff???

DECLARE FUNCTION MFCreateAlignedMemoryBuffer IMPORT "MFPLAT.DLL" ALIAS "MFCreateAlignedMemoryBuffer" ( _
   BYVAL cbMaxLength AS DWORD _                         ' __in DWORD              cbMaxLength
 , BYVAL cbAligment AS DWORD _                          ' __in DWORD              cbAligment
 , BYREF ppBuffer AS IMFMediaBuffer _                   ' __out IMFMediaBuffer ** ppBuffer
 ) AS LONG                                              ' HRESULT

'//
'// This GUID is used in IMFGetService::GetService calls to retrieve
'// interfaces from the buffer.  Its value is defined in evr.h
'//
'EXTERN_C const GUID MR_BUFFER_SERVICE;

$MR_BUFFER_SERVICE = GUID$("{A562248C-9AC6-4FFC-9FBA-3AF8F8AD1A4D}")


'///////////////////////////////////////////////////////////////////////////////
'/////////////////////////////////    Events      //////////////////////////////
'///////////////////////////////////////////////////////////////////////////////

'//
'// Instantiates the MF-provided Media Event implementation.
'//

DECLARE FUNCTION MFCreateMediaEvent IMPORT "MFPLAT.DLL" ALIAS "MFCreateMediaEvent" ( _
   BYVAL met AS DWORD _                                 ' __in  MediaEventType met
 , BYREF guidExtendedType AS GUID _                     ' __in  REFGUID guidExtendedType
 , BYVAL hrStatus AS LONG _                             ' __in  HRESULT hrStatus
 , BYREF pvValue AS ANY _                               ' __in  const PROPVARIANT* pvValue
 , BYREF ppEvent AS IMFMediaEvent _                     ' __out IMFMediaEvent ** ppEvent
 ) AS LONG                                              ' HRESULT

'//
'// Instantiates an object that implements IMFMediaEventQueue.
'// Components that provide an IMFMediaEventGenerator can use this object
'// internally to do their Media Event Generator work for them.
'// IMFMediaEventGenerator calls should be forwarded to the similar call
'// on this object's IMFMediaEventQueue interface (e.g. BeginGetEvent,
'// EndGetEvent), and the various IMFMediaEventQueue::QueueEventXXX methods
'// can be used to queue events that the caller will consume.
'//

DECLARE FUNCTION MFCreateEventQueue IMPORT "MFPLAT.DLL" ALIAS "MFCreateEventQueue" ( _
   BYREF ppMediaEventQueue AS IMFMediaEventQueue _      ' __out IMFMediaEventQueue **ppMediaEventQueue
 ) AS LONG                                              ' HRESULT

'//
'// Event attributes
'// Some of the common Media Foundation events have associated attributes
'// that go in their IMFAttributes stores
'//

'//
'// MESessionCapabilitiesChanged attributes
'//

'// MF_EVENT_SESSIONCAPS {7E5EBCD0-11B8-4ABE-AFAD-10F6599A7F42}
'// Type: UINT32
$MF_EVENT_SESSIONCAPS = GUID$("{7E5EBCD0-11B8-4ABE-AFAD-10F6599A7F42}")

'// MF_EVENT_SESSIONCAPS_DELTA {7E5EBCD1-11B8-4ABE-AFAD-10F6599A7F42}
'// Type: UINT32
$MF_EVENT_SESSIONCAPS_DELTA = GUID$("{7E5EBCD1-11B8-4ABE-AFAD-10F6599A7F42}")

'// Session capabilities bitflags
%MFSESSIONCAP_START              = &H00000001???
%MFSESSIONCAP_SEEK               = &H00000002???
%MFSESSIONCAP_PAUSE              = &H00000004???
%MFSESSIONCAP_RATE_FORWARD       = &H00000010???
%MFSESSIONCAP_RATE_REVERSE       = &H00000020???

'//
'// MESessionTopologyStatus attributes
'//

'// Possible values for MF_EVENT_TOPOLOGY_STATUS attribute.
'//
'// For a given topology, these status values will arrive via
'// MESessionTopologyStatus in the order below.
'//
'// However, there are no guarantees about how these status values will be
'// ordered between two consecutive topologies.  For example,
'// MF_TOPOSTATUS_READY could arrive for topology n+1 before
'// MF_TOPOSTATUS_ENDED arrives for topology n if the application called
'// IMFMediaSession::SetTopology for topology n+1 well enough in advance of the
'// end of topology n.  Conversely, if topology n ends before the application
'// calls IMFMediaSession::SetTopology for topology n+1, then
'// MF_TOPOSTATUS_ENDED will arrive for topology n before MF_TOPOSTATUS_READY
'// arrives for topology n+1.

'typedef enum
'{
'    // MF_TOPOSTATUS_INVALID: Invalid value; will not be sent
'    MF_TOPOSTATUS_INVALID = 0,

'    // MF_TOPOSTATUS_READY: The topology has been put in place and is
'    // ready to start.  All GetService calls to the Media Session will use
'    // this topology.
'    MF_TOPOSTATUS_READY     = 100,

'    // MF_TOPOSTATUS_STARTED_SOURCE: The Media Session has started to read
'    // and process data from the Media Source(s) in this topology.
'    MF_TOPOSTATUS_STARTED_SOURCE = 200,

'#if (WINVER >= _WIN32_WINNT_WIN7)
'    // MF_TOPOSTATUS_DYNAMIC_CHANGED: The topology has been dynamic changed
'    // due to the format change.
'    MF_TOPOSTATUS_DYNAMIC_CHANGED = 210,
'#endif // (WINVER >= _WIN32_WINNT_WIN7)

'    // MF_TOPOSTATUS_SINK_SWITCHED: The Media Sinks in the pipeline have
'    // switched from a previous topology to this topology.
'    // Note that this status does not get sent for the first topology;
'    // applications can assume that the sinks are playing the first
'    // topology when they receive MESessionStarted.
'    MF_TOPOSTATUS_SINK_SWITCHED = 300,

'    // MF_TOPOSTATUS_ENDED: Playback of this topology is complete.
'    // Before deleting this topology, however, the application should wait
'    // for either MESessionEnded or the MF_TOPOSTATUS_STARTED_SOURCE status
'    // on the next topology to ensure that the Media Session is no longer
'    // using this topology.
'    MF_TOPOSTATUS_ENDED = 400,

'}   MF_TOPOSTATUS;

' enum MF_TOPOSTATUS
%MF_TOPOSTATUS_INVALID         = 0
%MF_TOPOSTATUS_READY           = 100
%MF_TOPOSTATUS_STARTED_SOURCE  = 200
%MF_TOPOSTATUS_SINK_SWITCHED   = 300
'#if (WINVER >= _WIN32_WINNT_WIN7)
%MF_TOPOSTATUS_DYNAMIC_CHANGED = 210
'#endif // (WINVER >= _WIN32_WINNT_WIN7)
%MF_TOPOSTATUS_ENDED           = 400

'// MF_EVENT_TOPOLOGY_STATUS {30C5018D-9A53-454B-AD9E-6D5F8FA7C43B}
'// Type: UINT32 {MF_TOPOLOGY_STATUS}
$MF_EVENT_TOPOLOGY_STATUS = GUID$("{30C5018D-9A53-454B-AD9E-6D5F8FA7C43B}")

'//
'// MESessionNotifyPresentationTime attributes
'//

'// MF_EVENT_START_PRESENTATION_TIME {5AD914D0-9B45-4A8D-A2C0-81D1E50BFB07}
'// Type: UINT64
$MF_EVENT_START_PRESENTATION_TIME = GUID$("{5AD914D0-9B45-4A8D-A2C0-81D1E50BFB07}")

'// MF_EVENT_PRESENTATION_TIME_OFFSET {5AD914D1-9B45-4A8D-A2C0-81D1E50BFB07}
'// Type: UINT64
$MF_EVENT_PRESENTATION_TIME_OFFSET = GUID$("{5AD914D1-9B45-4A8D-A2C0-81D1E50BFB07}")

'// MF_EVENT_START_PRESENTATION_TIME_AT_OUTPUT {5AD914D2-9B45-4A8D-A2C0-81D1E50BFB07}
'// Type: UINT64
$MF_EVENT_START_PRESENTATION_TIME_AT_OUTPUT = GUID$("{5AD914D2-9B45-4A8D-A2C0-81D1E50BFB07}")

'//

'//
'// MESourceStarted attributes
'//

'// MF_EVENT_SOURCE_FAKE_START {A8CC55A7-6B31-419F-845D-FFB351A2434B}
'// Type: UINT32
$MF_EVENT_SOURCE_FAKE_START = GUID$("{A8CC55A7-6B31-419F-845D-FFB351A2434B}")

'// MF_EVENT_SOURCE_PROJECTSTART {A8CC55A8-6B31-419F-845D-FFB351A2434B}
'// Type: UINT64
$MF_EVENT_SOURCE_PROJECTSTART = GUID$("{A8CC55A8-6B31-419F-845D-FFB351A2434B}")

'// MF_EVENT_SOURCE_ACTUAL_START {A8CC55A9-6B31-419F-845D-FFB351A2434B}
'// Type: UINT64
$MF_EVENT_SOURCE_ACTUAL_START = GUID$("{A8CC55A9-6B31-419F-845D-FFB351A2434B}")

'//
'// MEEndOfPresentationSegment attributes
'//

'// MF_EVENT_SOURCE_TOPOLOGY_CANCELED {DB62F650-9A5E-4704-ACF3-563BC6A73364}
'// Type: UINT32
$MF_EVENT_SOURCE_TOPOLOGY_CANCELED = GUID$("{DB62F650-9A5E-4704-ACF3-563BC6A73364}")

'//
'// MESourceCharacteristicsChanged attributes
'//

'// MF_EVENT_SOURCE_CHARACTERISTICS {47DB8490-8B22-4F52-AFDA-9CE1B2D3CFA8}
'// Type: UINT32
$MF_EVENT_SOURCE_CHARACTERISTICS = GUID$("{47DB8490-8B22-4F52-AFDA-9CE1B2D3CFA8}")

'// MF_EVENT_SOURCE_CHARACTERISTICS_OLD {47DB8491-8B22-4F52-AFDA-9CE1B2D3CFA8}
'// Type: UINT32
$MF_EVENT_SOURCE_CHARACTERISTICS_OLD = GUID$("{47DB8491-8B22-4f52-AFDA-9CE1B2D3CFA8}")

'//
'// MESourceRateChangeRequested attributes
'//

'// MF_EVENT_DO_THINNING {321EA6FB-DAD9-46E4-B31D-D2EAE7090E30}
'// Type: UINT32
$MF_EVENT_DO_THINNING = GUID$("{321EA6FB-DAD9-46E4-B31D-D2EAE7090E30}")

'//
'// MEStreamSinkScrubSampleComplete attributes
'//

'// MF_EVENT_SCRUBSAMPLE_TIME {9AC712B3-DCB8-44d5-8D0C-37455A2782E3}
'// Type: UINT64
$MF_EVENT_SCRUBSAMPLE_TIME = GUID$("{9AC712B3-DCB8-44d5-8D0C-37455A2782E3}")

'//
'// MESinkInvalidated and MESessionStreamSinkFormatChanged attributes
'//

'// MF_EVENT_OUTPUT_NODE {830F1A8B-C060-46DD-A801-1C95DEC9B107}
'// Type: UINT64
$MF_EVENT_OUTPUT_NODE = GUID$("{830F1A8B-C060-46DD-A801-1C95DEC9B107}")

'#if (WINVER >= _WIN32_WINNT_WIN7)
'//
'// METransformNeedInput attributes
'//

'// MF_EVENT_MFT_INPUT_STREAM_ID {F29C2CCA-7AE6-42d2-B284-BF837CC874E2}
'// Type: UINT32
$MF_EVENT_MFT_INPUT_STREAM_ID = GUID$("{F29C2CCA-7AE6-42d2-B284-BF837CC874E2}")

'//
'// METransformDrainComplete and METransformMarker attributes
'//

'// MF_EVENT_MFT_CONTEXT {B7CD31F1-899E-4b41-80C9-26A896D32977}
'// Type: UINT64
$MF_EVENT_MFT_CONTEXT = GUID$("{B7CD31F1-899E-4b41-80C9-26A896D32977}")

'#endif // (WINVER >= _WIN32_WINNT_WIN7)

'////////////////////////////////////////////////////////////////////////////////
'///////////////////////////////  Samples  //////////////////////////////////////
'////////////////////////////////////////////////////////////////////////////////

'//
'// Creates an instance of the Media Foundation implementation of IMFSample
'//

DECLARE FUNCTION MFCreateSample IMPORT "MFPLAT.DLL" ALIAS "MFCreateSample" ( _
   BYREF ppIMFSample AS IMFSample _                     ' __out IMFSample **ppIMFSample
 ) AS LONG                                              ' HRESULT

'//
'// Sample attributes
'// These are the well-known attributes that can be present on an MF Sample's
'// IMFAttributes store
'//

'// MFSampleExtension_CleanPoint {9CDF01D8-A0F0-43BA-B077-EAA06CBD728A}
'// Type: UINT32
'// If present and nonzero, indicates that the sample is a clean point (key
'// frame), and decoding can begin at this sample.
$MFSampleExtension_CleanPoint = GUID$("{9CDF01D8-A0F0-43BA-B077-EAA06CBD728A}")

'// MFSampleExtension_Discontinuity {9CDF01D9-A0F0-43BA-B077-EAA06CBD728A}
'// Type: UINT32
'// If present and nonzero, indicates that the sample data represents the first
'// sample following a discontinuity (gap) in the stream of samples.
'// This can happen, for instance, if the previous sample was lost in
'// transmission.
$MFSampleExtension_Discontinuity = GUID$("{9CDF01D9-A0F0-43BA-B077-EAA06CBD728A}")

'// MFSampleExtension_Token {8294DA66-F328-4805-B551-00DEB4C57A61}
'// Type: IUNKNOWN
'// When an IMFMediaStream delivers a sample via MEMediaStream, this attribute
'// should be set to the IUnknown *pToken argument that was passed with the
'// IMFMediaStream::RequestSample call to which this sample corresponds.
$MFSampleExtension_Token = GUID$("{8294DA66-F328-4805-B551-00DEB4C57A61}")

'//
'// The following four sample attributes are used for encrypted samples
'//

'// MFSampleExtension_DescrambleData {43483BE6-4903-4314-B032-2951365936FC}
'// Type: UINT64
$MFSampleExtension_DescrambleData = GUID$("{43483BE6-4903-4314-B032-2951365936FC}")

'// MFSampleExtension_SampleKeyID {9ED713C8-9B87-4B26-8297-A93B0C5A8ACC}
'// Type: UINT32
$MFSampleExtension_SampleKeyID = GUID$("{9ED713C8-9B87-4B26-8297-A93B0C5A8ACC}")

'// MFSampleExtension_GenKeyFunc {441CA1EE-6B1F-4501-903A-DE87DF42F6ED}
'// Type: UINT64
$MFSampleExtension_GenKeyFunc = GUID$("{441CA1EE-6B1F-4501-903A-DE87DF42F6ED}")

'// MFSampleExtension_GenKeyCtx {188120CB-D7DA-4B59-9B3E-9252FD37301C}
'// Type: UINT64
$MFSampleExtension_GenKeyCtx = GUID$("{188120CB-D7DA-4B59-9B3E-9252FD37301C}")

'// MFSampleExtension_PacketCrossOffsets {2789671D-389F-40BB-90D9-C282F77F9ABD}
'// Type: BLOB
$MFSampleExtension_PacketCrossOffsets = GUID$("{2789671D-389F-40BB-90D9-C282F77F9ABD}")

'/////////////////////////////////////////////////////////////////////////////
'//
'// MFSample STANDARD EXTENSION ATTRIBUTE GUIDs
'//
'/////////////////////////////////////////////////////////////////////////////

'// {B1D5830A-DEB8-40E3-90FA-389943716461}   MFSampleExtension_Interlaced                {UINT32 (BOOL)}
$MFSampleExtension_Interlaced = GUID$("{B1D5830A-DEB8-40E3-90FA-389943716461}")

'// {941CE0A3-6AE3-4DDA-9A08-A64298340617}   MFSampleExtension_BottomFieldFirst          {UINT32 (BOOL)}
$MFSampleExtension_BottomFieldFirst = GUID$("{941CE0A3-6AE3-4DDA-9A08-A64298340617}")

'// {304D257C-7493-4FBD-B149-9228DE8D9A99}   MFSampleExtension_RepeatFirstField          {UINT32 (BOOL)}
$MFSampleExtension_RepeatFirstField = GUID$("{304D257C-7493-4FBD-B149-9228DE8D9A99}")

'// {9D85F816-658B-455A-BDE0-9FA7E15AB8F9}   MFSampleExtension_SingleField               {UINT32 (BOOL)}
$MFSampleExtension_SingleField = GUID$("{9D85F816-658B-455A-BDE0-9FA7E15AB8F9}")

'// {6852465A-AE1C-4553-8E9B-C3420FCB1637}   MFSampleExtension_DerivedFromTopField       {UINT32 (BOOL)}
$MFSampleExtension_DerivedFromTopField = GUID$("{6852465A-AE1C-4553-8E9B-C3420FCB1637}")


'///////////////////////////////////////////////////////////////////////////////////////////////////////////////  Attributes ////////////////////////////////////
'////////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION MFCreateAttributes IMPORT "MFPLAT.DLL" ALIAS "MFCreateAttributes" ( _
   BYREF ppMFAttributes AS IMFAttributes _              ' __out IMFAttributes** ppMFAttributes
 , BYVAL cInitialSize AS DWORD _                        ' __in  UINT32          cInitialSize
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFInitAttributesFromBlob IMPORT "MFPLAT.DLL" ALIAS "MFInitAttributesFromBlob" ( _
   BYVAL pAttributes AS IMFAttributes _                 ' __in IMFAttributes*   pAttributes
 , BYREF pBuf AS BYTE _                                 ' __in const UINT8*     pBuf
 , BYVAL cbBufSize AS DWORD _                           ' __in UINT             cbBufSize
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFGetAttributesAsBlobSize IMPORT "MFPLAT.DLL" ALIAS "MFGetAttributesAsBlobSize" ( _
   BYVAL pAttributes AS IMFAttributes _                 ' __in  IMFAttributes*  pAttributes
 , BYREF pcbBufSize AS DWORD _                          ' __out UINT32*         pcbBufSize
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFGetAttributesAsBlob IMPORT "MFPLAT.DLL" ALIAS "MFGetAttributesAsBlob" ( _
   BYVAL pAttributes AS IMFAttributes _                 ' __in  IMFAttributes*  pAttributes
 , BYREF pBuf AS BYTE _                                 ' __out UINT8*          pBuf
 , BYVAL cbBufSize AS DWORD _                           ' __in  UINT            cbBufSize
 ) AS LONG                                              ' HRESULT

'///////////////////////////////////////////////////////////////////////////////////////////////////////////////  MFT Register & Enum ////////////////////////////
'////////////////////////////////////////////////////////////////////////////////

'//
'// MFT Registry categories
'//

#IF NOT %DEF(%MF_INIT_GUIDS)
#INCLUDE ONCE "initguid.inc"
#ENDIF

'// {D6C02D4B-6833-45B4-971A-05A4B04BAB91}   MFT_CATEGORY_VIDEO_DECODER
$MFT_CATEGORY_VIDEO_DECODER = GUID$("{D6C02D4B-6833-45B4-971A-05A4B04BAB91}")

'// {F79EAC7D-E545-4387-BDEE-D647D7BDE42A}   MFT_CATEGORY_VIDEO_ENCODER
$MFT_CATEGORY_VIDEO_ENCODER = GUID$("{F79EAC7D-E545-4387-BDEE-D647D7BDE42A}")

'// {12E17C21-532C-4A6E-8A1C-40825A736397}   MFT_CATEGORY_VIDEO_EFFECT
$MFT_CATEGORY_VIDEO_EFFECT = GUID$("{12E17C21-532C-4A6E-8A1C-40825A736397}")

'// {059C561E-05AE-4B61-B69D-55B61EE54A7B}   MFT_CATEGORY_MULTIPLEXER
$MFT_CATEGORY_MULTIPLEXER = GUID$("{059C561E-05AE-4B61-B69D-55B61EE54A7B}")

'// {A8700A7A-939B-44C5-99D7-76226B23B3F1}   MFT_CATEGORY_DEMULTIPLEXER
$MFT_CATEGORY_DEMULTIPLEXER = GUID$("{A8700A7A-939B-44C5-99D7-76226B23B3F1}")

'// {9EA73FB4-EF7A-4559-8D5D-719D8F0426C7}   MFT_CATEGORY_AUDIO_DECODER
$MFT_CATEGORY_AUDIO_DECODER = GUID$("{9EA73FB4-EF7A-4559-8D5D-719D8F0426C7}")

'// {91C64BD0-F91E-4D8C-9276-DB248279D975}   MFT_CATEGORY_AUDIO_ENCODER
$MFT_CATEGORY_AUDIO_ENCODER = GUID$("{91C64BD0-F91E-4D8C-9276-DB248279D975}")

'// {11064C48-3648-4ED0-932E-05CE8AC811B7}   MFT_CATEGORY_AUDIO_EFFECT
$MFT_CATEGORY_AUDIO_EFFECT = GUID$("{11064C48-3648-4ED0-932E-05CE8AC811B7}")

'#if (WINVER >= _WIN32_WINNT_WIN7)
'// {302EA3FC-AA5F-47f9-9F7A-C2188BB163021}...MFT_CATEGORY_VIDEO_PROCESSOR
$MFT_CATEGORY_VIDEO_PROCESSOR = GUID$("{302EA3FC-AA5F-47f9-9F7A-C2188BB16302}")
'#endif // (WINVER >= _WIN32_WINNT_WIN7)

'// {90175D57-B7EA-4901-AEB3-933A8747756F}   MFT_CATEGORY_OTHER
$MFT_CATEGORY_OTHER = GUID$("{90175D57-B7EA-4901-AEB3-933A8747756F}")

'//
'// "Flags" is for future expansion - for now must be 0
'//

DECLARE FUNCTION MFTRegister IMPORT "MFPLAT.DLL" ALIAS "MFTRegister" ( _
   BYREF clsidMFT AS GUID _                             ' __in CLSID                   clsidMFT
 , BYREF pszName AS GUID _                              ' __in GUID                    guidCategory
 , BYREF pszName AS WSTRINGZ _                          ' __in LPWSTR                  pszName
 , BYVAL Flags AS DWORD _                               ' __in UINT32                  Flags
 , BYVAL cInputTypes AS DWORD _                         ' __in UINT32                  cInputTypes
 , BYREF pInputTypes AS MFT_REGISTER_TYPE_INFO _        ' __in MFT_REGISTER_TYPE_INFO* pInputTypes
 , BYVAL cOutputTypes AS DWORD _                        ' __in UINT32                  cOutputTypes
 , BYREF pOutputTypes AS MFT_REGISTER_TYPE_INFO _       ' __in MFT_REGISTER_TYPE_INFO* pOutputTypes
 , BYVAL pAttributes AS IMFAttributes _                 ' __in IMFAttributes           pAttributes
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFTUnregister IMPORT "MFPLAT.DLL" ALIAS "MFTUnregister" ( _
   BYREF clsidMFT AS GUID _                             ' __in CLSID clsidMFT
 ) AS LONG                                              ' HRESULT

'#if (WINVER >= _WIN32_WINNT_WIN7)
'//  Register an MFT class in-process
DECLARE FUNCTION MFTRegisterLocal IMPORT "MFPLAT.DLL" ALIAS "MFTRegisterLocal" ( _
   BYVAL pClassFactory AS IClassFactory _               ' __in IClassFactory* pClassFactory
 , BYREF guidCategory AS GUID _                         ' __in REFGUID guidCategory
 , BYREF pszName AS WSTRINGZ _                          ' __in LPCWSTR pszName
 , BYVAL Flags AS DWORD _                               ' __in UINT32 Flags
 , BYVAL cInputTypes AS DWORD _                         ' __in UINT32 cInputTypes
 , BYREF pInputTypes AS MFT_REGISTER_TYPE_INFO _        ' __in const MFT_REGISTER_TYPE_INFO* pInputTypes
 , BYVAL cOutputTypes AS DWORD _                        ' __in UINT32 cOutputTypes
 , BYREF pOutputTypes AS MFT_REGISTER_TYPE_INFO _       ' __in const MFT_REGISTER_TYPE_INFO* pOutputTypes
 ) AS LONG                                              ' HRESULT

'//  Unregister locally registered MFT
'//  If pClassFactory is NULL all local MFTs are unregistered
DECLARE FUNCTION MFTUnregisterLocal IMPORT "MFPLAT.DLL" ALIAS "MFTUnregisterLocal" ( _
   OPTIONAL BYVAL pClassFactory AS IClassFactory _      ' __in_opt IClassFactory* pClassFactory
 ) AS LONG                                              ' HRESULT

'// Register an MFT class in-process, by CLSID
DECLARE FUNCTION MFTRegisterLocalByCLSID IMPORT "MFPLAT.DLL" ALIAS "MFTRegisterLocalByCLSID" ( _
   BYREF clisdMFT AS GUID _                             ' __in REFCLSID clisdMFT
 , BYREF guidCategory AS GUID _                         ' __in REFGUID guidCategory
 , BYREF pszName AS WSTRINGZ _                          ' __in LPCWSTR pszName
 , BYVAL Flags AS DWORD _                               ' __in UINT32 Flags
 , BYVAL cInputTypes AS DWORD _                         ' __in UINT32 cInputTypes
 , BYREF pInputTypes AS MFT_REGISTER_TYPE_INFO _        ' __in const MFT_REGISTER_TYPE_INFO* pInputTypes
 , BYVAL cOutputTypes AS DWORD _                        ' __in UINT32 cOutputTypes
 , BYREF pOutputTypes AS MFT_REGISTER_TYPE_INFO _       ' __in const MFT_REGISTER_TYPE_INFO* pOutputTypes
 ) AS LONG                                              ' HRESULT

'// Unregister locally registered MFT by CLSID
DECLARE FUNCTION MFTUnregisterLocalByCLSID IMPORT "MFPLAT.DLL" ALIAS "MFTUnregisterLocalByCLSID" ( _
   BYVAL clisdMFT AS GUID _                             ' __in CLSID clisdMFT
 ) AS LONG                                              ' HRESULT
'#endif // (WINVER >= _WIN32_WINNT_WIN7)

'//
'// result *ppclsidMFT must be freed with CoTaskMemFree.
'//

DECLARE FUNCTION MFTEnum IMPORT "MFPLAT.DLL" ALIAS "MFTEnum" ( _
   BYREF guidCategory AS GUID _                         ' __in  GUID                    guidCategory
 , BYVAL Flags AS DWORD _                               ' __in  UINT32                  Flags
 , BYREF pInputType AS MFT_REGISTER_TYPE_INFO _         ' __in  MFT_REGISTER_TYPE_INFO* pInputType
 , BYREF pOutputType AS MFT_REGISTER_TYPE_INFO _        ' __in  MFT_REGISTER_TYPE_INFO* pOutputType
 , BYVAL pAttributes AS IMFAttributes _                 ' __in  IMFAttributes*          pAttributes
 , BYREF ppclsidMFT AS DWORD _                          ' __out CLSID**                 ppclsidMFT // must be freed with CoTaskMemFree
 , BYREF pcMFTs AS DWORD _                              ' __out UINT32*                 pcMFTs
 ) AS LONG                                              ' HRESULT

'#if (WINVER >= _WIN32_WINNT_WIN7)

' enum MFT_ENUM_FLAG
%MFT_ENUM_FLAG_SYNCMFT        = &H00000001???   ' // Enumerates V1 MFTs. This is default.
%MFT_ENUM_FLAG_ASYNCMFT       = &H00000002???   ' // Enumerates only software async MFTs also known as V2 MFTs
%MFT_ENUM_FLAG_HARDWARE       = &H00000004???   ' // Enumerates V2 hardware async MFTs
%MFT_ENUM_FLAG_FIELDOFUSE     = &H00000008???   ' // Enumerates MFTs that require unlocking
%MFT_ENUM_FLAG_LOCALMFT       = &H00000010???   ' // Enumerates Locally (in-process) registered MFTs
%MFT_ENUM_FLAG_TRANSCODE_ONLY = &H00000020???   ' // Enumerates decoder MFTs used by transcode only
%MFT_ENUM_FLAG_SORTANDFILTER  = &H00000040???   ' // Apply system local, do not use and preferred sorting and filtering
%MFT_ENUM_FLAG_ALL            = &H0000003F???   ' // Enumerates all MFTs including SW and HW MFTs and applies filtering

'//
'// result *pppMFTActivate must be freed with CoTaskMemFree. Each IMFActivate pointer inside this
'// buffer should be released.
'//

DECLARE FUNCTION MFTEnumEx IMPORT "MFPLAT.DLL" ALIAS "MFTEnumEx" ( _
   BYREF guidCategory AS GUID _                         ' __in  GUID                    guidCategory
 , BYVAL Flags AS DWORD _                               ' __in  UINT32                  Flags
 , BYREF pInputType AS MFT_REGISTER_TYPE_INFO _         ' __in  MFT_REGISTER_TYPE_INFO* pInputType
 , BYREF pOutputType AS MFT_REGISTER_TYPE_INFO _        ' __in  MFT_REGISTER_TYPE_INFO* pOutputType
 , BYREF IMFActivate AS IMFActivate _                   ' __out IMFActivate***          pppMFTActivate
 , BYREF pnumMFTActivate AS DWORD _                     ' __out UINT32*                 pnumMFTActivate
 ) AS LONG                                              ' HRESULT
'#endif // (WINVER >= _WIN32_WINNT_WIN7)

'//
'// results *pszName, *ppInputTypes, and *ppOutputTypes must be freed with CoTaskMemFree.
'// *ppAttributes must be released.
'//

DECLARE FUNCTION MFTGetInfo IMPORT "MFPLAT.DLL" ALIAS "MFTGetInfo" ( _
   BYREF clsidMFT AS GUID _                             ' __in  CLSID                      clsidMFT
 , BYREF pszName AS WSTRINGZ _                          ' __out LPWSTR*                    pszName
 , BYREF ppInputTypes AS DWORD _                        ' __out MFT_REGISTER_TYPE_INFO**   ppInputTypes
 , BYREF pcInputTypes AS DWORD _                        ' __out UINT32*                    pcInputTypes
 , BYREF ppOutputTypes AS DWORD _                       ' __out MFT_REGISTER_TYPE_INFO**   ppOutputTypes
 , BYREF pcOutputTypes AS DWORD _                       ' __out UINT32*                    pcOutputTypes
 , BYREF ppAttributes AS IMFAttributes _                ' __out IMFAttributes**            ppAttributes
 ) AS LONG                                              ' HRESULT

'#if (WINVER >= _WIN32_WINNT_WIN7)

'//
'//  Get the plugin control API
'//
DECLARE FUNCTION MFGetPluginControl IMPORT "MFPLAT.DLL" ALIAS "MFGetPluginControl" ( _
   BYREF ppPluginControl AS IMFPluginControl _          ' __out IMFPluginControl **ppPluginControl
 ) AS LONG                                              ' HRESULT

'//
'//  Get MFT's merit - checking that is has a valid certificate
'//
DECLARE FUNCTION MFGetMFTMerit IMPORT "MFPLAT.DLL" ALIAS "MFGetMFTMerit" ( _
   BYVAL pMFT AS IUnknown _                             ' __inout IUnknown *pMFT
 , BYVAL cbVerifier AS DWORD _                          ' __in UINT32 cbVerifier
 , BYREF verifier AS ANY _                              ' __in const BYTE * verifier
 , BYREF merit AS DWORD _                               ' __out DWORD *merit
 ) AS LONG                                              ' HRESULT

'#endif // (WINVER >= _WIN32_WINNT_WIN7)

'///////////////////////////////////////////////////////////////////////////////////////////////////////////////  MFT  Attributes GUIDs ////////////////////////////
'// {53476A11-3F13-49FB-AC42-EE2733C96741} MFT_SUPPORT_DYNAMIC_FORMAT_CHANGE {UINT32 (BOOL)}
$MFT_SUPPORT_DYNAMIC_FORMAT_CHANGE = GUID$("{53476A11-3F13-49FB-AC42-EE2733C96741}")

'///////////////////////////////////////////////////////////////////////////////////////////////////////////////  Media Type GUIDs ////////////////////////////
'////////////////////////////////////////////////////////////////////////////////

'//
'// GUIDs for media types
'//

'//
'// In MF, media types for uncompressed video formats MUST be composed from a FourCC or D3DFORMAT combined with
'// the "base GUID" {00000000-0000-0010-8000-00AA00389B71} by replacing the initial 32 bits with the FourCC/D3DFORMAT
'//
'// Audio media types for types which already have a defined wFormatTag value can be constructed similarly, by
'// putting the wFormatTag (zero-extended to 32 bits) into the first 32 bits of the base GUID.
'//
'// Compressed video or audio can also use any well-known GUID that exists, or can create a new GUID.
'//
'// GUIDs for common media types are defined below.
'//

'#ifndef FCC
'#define FCC(ch4) ((((DWORD)(ch4) & 0xFF) << 24) |     \
'                  (((DWORD)(ch4) & 0xFF00) << 8) |    \
'                  (((DWORD)(ch4) & 0xFF0000) >> 8) |  \
'                  (((DWORD)(ch4) & 0xFF000000) >> 24))
'#endif

'//
'// this macro creates a media type GUID from a FourCC, D3DFMT, or WAVE_FORMAT
'//
'#ifndef DEFINE_MEDIATYPE_GUID
'#define DEFINE_MEDIATYPE_GUID(name, format) \
'    DEFINE_GUID(name,                       \
'    format, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);
'#endif

'//
'// video media types
'//

'//
'// If no D3D headers have been included yet, define local versions of D3DFMT constants we use.
'// We can't include D3D headers from this header because we need it to be compatible with all versions
'// of D3D.
'//
'#IF NOT %DEF(%DIRECT3D_VERSION)
'%D3DFMT_R8G8B8        = 20???
'%D3DFMT_A8R8G8B8      = 21???
'%D3DFMT_X8R8G8B8      = 22???
'%D3DFMT_R5G6B5        = 23???
'%D3DFMT_X1R5G5B5      = 24???
'%D3DFMT_P8            = 41???
'%LOCAL_D3DFMT_DEFINES = 1
'#ENDIF

'DEFINE_MEDIATYPE_GUID( MFVideoFormat_Base,      0x00000000 );
$MFVideoFormat_Base = GUID$("{00000000-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_RGB32,     D3DFMT_X8R8G8B8 );
$MFVideoFormat_RGB32 = GUID$("{00000016-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_ARGB32,    D3DFMT_A8R8G8B8 );
$MFVideoFormat_ARGB32 = GUID$("{00000015-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_RGB24,     D3DFMT_R8G8B8 );
$MFVideoFormat_RGB24 = GUID$("{00000014-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_RGB555,    D3DFMT_X1R5G5B5 );
$MFVideoFormat_RGB555 = GUID$("{00000018-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_RGB565,    D3DFMT_R5G6B5 );
$MFVideoFormat_RGB565 = GUID$("{00000017-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_RGB8,      D3DFMT_P8 );
$MFVideoFormat_RGB8 = GUID$("{00000029-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_AI44,      FCC('AI44') );
$MFVideoFormat_AI44 = GUID$("{34344941-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_AYUV,      FCC('AYUV') );
$MFVideoFormat_AYUV = GUID$("{56555941-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_YUY2,      FCC('YUY2') );
$MFVideoFormat_YUY2 = GUID$("{32595559-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_YVYU,      FCC('YVYU') );
$MFVideoFormat_YVYU = GUID$("{55595659-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_YVU9,      FCC('YVU9') );
$MFVideoFormat_YVU9 = GUID$("{39555659-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_UYVY,      FCC('UYVY') );
$MFVideoFormat_UYVY = GUID$("{59565955-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_NV11,      FCC('NV11') );
$MFVideoFormat_NV11 = GUID$("{3131564E-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_NV12,      FCC('NV12') );
$MFVideoFormat_NV12 = GUID$("{3231564E-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_YV12,      FCC('YV12') );
$MFVideoFormat_YV12 = GUID$("{32315659-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_I420,      FCC('I420') );
$MFVideoFormat_I420 = GUID$("{30323449-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_IYUV,      FCC('IYUV') );
$MFVideoFormat_IYUV = GUID$("{56555949-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_Y210,      FCC('Y210') );
$MFVideoFormat_Y210 = GUID$("{30313259-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_Y216,      FCC('Y216') );
$MFVideoFormat_Y216 = GUID$("{36313259-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_Y410,      FCC('Y410') );
$MFVideoFormat_Y410 = GUID$("{30313459-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_Y416,      FCC('Y416') );
$MFVideoFormat_Y416 = GUID$("{36313459-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_Y41P,      FCC('Y41P') );
$MFVideoFormat_Y41P = GUID$("{50313459-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_Y41T,      FCC('Y41T') );
$MFVideoFormat_Y41T = GUID$("{54313459-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_Y42T,      FCC('Y42T') );
$MFVideoFormat_Y42T = GUID$("{54323459-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_P210,      FCC('P210') );
$MFVideoFormat_P210 = GUID$("{30313250-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_P216,      FCC('P216') );
$MFVideoFormat_P216 = GUID$("{36313250-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_P010,      FCC('P010') );
$MFVideoFormat_P010 = GUID$("{30313050-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_P016,      FCC('P016') );
$MFVideoFormat_P016 = GUID$("{36313050-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_v210,      FCC('v210') );
$MFVideoFormat_v210 = GUID$("{30313276-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_v216,      FCC('v216') );
$MFVideoFormat_v216 = GUID$("{36313276-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_v410,      FCC('v410') );
$MFVideoFormat_v410 = GUID$("{30313476-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_MP43,      FCC('MP43') );
$MFVideoFormat_MP43 = GUID$("{3334504D-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_MP4S,      FCC('MP4S') );
$MFVideoFormat_MP4S = GUID$("{5334504D-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_M4S2,      FCC('M4S2') );
$MFVideoFormat_M4S2 = GUID$("{3253344D-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_MP4V,      FCC('MP4V') );
$MFVideoFormat_MP4V = GUID$("{5634504D-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_WMV1,      FCC('WMV1') );
$MFVideoFormat_WMV1 = GUID$("{31564D57-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_WMV2,      FCC('WMV2') );
$MFVideoFormat_WMV2 = GUID$("{32564D57-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_WMV3,      FCC('WMV3') );
$MFVideoFormat_WMV3 = GUID$("{33564D57-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_WVC1,      FCC('WVC1') );
$MFVideoFormat_WVC1 = GUID$("{31435657-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_MSS1,      FCC('MSS1') );
$MFVideoFormat_MSS1 = GUID$("{3153534D-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_MSS2,      FCC('MSS2') );
$MFVideoFormat_MSS2 = GUID$("{3253534D-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_MPG1,      FCC('MPG1') );
$MFVideoFormat_MPG1 = GUID$("{3147504D-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_DVSL,      FCC('dvsl') );
$MFVideoFormat_DVSL = GUID$("{4C535644-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_DVSD,      FCC('dvsd') );
$MFVideoFormat_DVSD = GUID$("{44535644-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_DVHD,      FCC('dvhd') );
$MFVideoFormat_DVHD = GUID$("{64687664-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_DV25,      FCC('dv25') );
$MFVideoFormat_DV25 = GUID$("{35325644-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_DV50,      FCC('dv50') );
$MFVideoFormat_DV50 = GUID$("{30355644-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_DVH1,      FCC('dvh1') );
$MFVideoFormat_DVH1 = GUID$("{31485644-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_DVC,       FCC('dvc ') );
$MFVideoFormat_DVC  = GUID$("{20637664-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_H264,      FCC('H264') );
$MFVideoFormat_H264 = GUID$("{34363248-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFVideoFormat_MJPG,      FCC('MJPG') );
$MFVideoFormat_MJPG = GUID$("{47504A4D-0000-0010-8000-00AA00389B71}")

'//
'// undef the local D3DFMT definitions to avoid later clashes with D3D headers
'//
'#ifdef LOCAL_D3DFMT_DEFINES
'#undef D3DFMT_R8G8B8
'#undef D3DFMT_A8R8G8B8
'#undef D3DFMT_X8R8G8B8
'#undef D3DFMT_R5G6B5
'#undef D3DFMT_X1R5G5B5
'#undef D3DFMT_P8
'#undef LOCAL_D3DFMT_DEFINES
'#endif

'//
'// some legacy formats that don't fit the common pattern
'//

'// {E06D8026-DB46-11CF-B4D1-00805F6CBBEA}       MFVideoFormat_MPEG2
$MFVideoFormat_MPEG2 = GUID$("{E06D8026-DB46-11CF-B4D1-00805F6CBBEA}")

'#define MFVideoFormat_MPG2 MFVideoFormat_MPEG2
$MFVideoFormat_MPG2 = $MFVideoFormat_MPEG2

'//
'// audio media types
'//
'DEFINE_MEDIATYPE_GUID( MFAudioFormat_Base,              0x00000000 );
$MFAudioFormat_Base = GUID$("{00000000-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFAudioFormat_PCM,               WAVE_FORMAT_PCM );
$MFAudioFormat_PCM = GUID$("{00000001-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFAudioFormat_Float,             WAVE_FORMAT_IEEE_FLOAT );
$MFAudioFormat_Float = GUID$("{00000003-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFAudioFormat_DTS,               WAVE_FORMAT_DTS );
$MFAudioFormat_DTS = GUID$("{00000008-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFAudioFormat_Dolby_AC3_SPDIF,   WAVE_FORMAT_DOLBY_AC3_SPDIF );
$MFAudioFormat_Dolby_AC3_SPDIF = GUID$("{00000092-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFAudioFormat_DRM,               WAVE_FORMAT_DRM );
$MFAudioFormat_DRM = GUID$("{00000009-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFAudioFormat_WMAudioV8,         WAVE_FORMAT_WMAUDIO2 );
$MFAudioFormat_WMAudioV8 = GUID$("{00000161-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFAudioFormat_WMAudioV9,         WAVE_FORMAT_WMAUDIO3 );
$MFAudioFormat_WMAudioV9 = GUID$("{00000162-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFAudioFormat_WMAudio_Lossless,  WAVE_FORMAT_WMAUDIO_LOSSLESS );
$MFAudioFormat_WMAudio_Lossless = GUID$("{00000163-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFAudioFormat_WMASPDIF,          WAVE_FORMAT_WMASPDIF );
$MFAudioFormat_WMASPDIF = GUID$("{00000164-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFAudioFormat_MSP1,              WAVE_FORMAT_WMAVOICE9 );
$MFAudioFormat_MSP1 = GUID$("{0000000A-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFAudioFormat_MP3,               WAVE_FORMAT_MPEGLAYER3 );
$MFAudioFormat_MP3 = GUID$("{00000055-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFAudioFormat_MPEG,              WAVE_FORMAT_MPEG );
$MFAudioFormat_MPEG = GUID$("{00000050-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFAudioFormat_AAC,               WAVE_FORMAT_MPEG_HEAAC );
$MFAudioFormat_AAC = GUID$("{00001610-0000-0010-8000-00AA00389B71}")
'DEFINE_MEDIATYPE_GUID( MFAudioFormat_ADTS,              WAVE_FORMAT_MPEG_ADTS_AAC );
$MFAudioFormat_ADTS = GUID$("{00001600-0000-0010-8000-00AA00389B71}")

'//
'// MPEG-4 media types
'//

'// {00000000-767a-494d-b478-f29d25dc9037}       MFMPEG4Format_Base
$MFMPEG4Format_Base = GUID$("{00000000-767a-494d-b478-f29d25dc9037}")

'///////////////////////////////////////////////////////////////////////////////////////////////////////////////  Media Type Attributes GUIDs ////////////////////////////
'////////////////////////////////////////////////////////////////////////////////

'//
'// GUIDs for IMFMediaType properties - prefix 'MF_MT_' - basic prop type in {},
'// with type to cast to in ().
'//


'//
'// core info for all types
'//
'// {48EBA18E-F8C9-4687-BF11-0A74C9F96A8F}   MF_MT_MAJOR_TYPE                {GUID}
$MF_MT_MAJOR_TYPE = GUID$("{48EBA18E-F8C9-4687-BF11-0A74C9F96A8F}")

'// {F7E34C9A-42E8-4714-B74B-CB29D72C35E5}   MF_MT_SUBTYPE                   {GUID}
$MF_MT_SUBTYPE = GUID$("{F7E34C9A-42E8-4714-B74B-CB29D72C35E5}")

'// {C9173739-5E56-461C-B713-46FB995CB95F}   MF_MT_ALL_SAMPLES_INDEPENDENT   {UINT32 (BOOL)}
$MF_MT_ALL_SAMPLES_INDEPENDENT = GUID$("{C9173739-5E56-461C-B713-46FB995CB95F}")

'// {B8EBEFAF-B718-4E04-B0A9-116775E3321B}   MF_MT_FIXED_SIZE_SAMPLES        {UINT32 (BOOL)}
$MF_MT_FIXED_SIZE_SAMPLES = GUID$("{B8EBEFAF-B718-4E04-B0A9-116775E3321B}")

'// {3AFD0CEE-18F2-4BA5-A110-8BEA502E1F92}   MF_MT_COMPRESSED                {UINT32 (BOOL)}
$MF_MT_COMPRESSED = GUID$("{3AFD0CEE-18F2-4BA5-A110-8BEA502E1F92}")

'//
'// MF_MT_SAMPLE_SIZE is only valid if MF_MT_FIXED_SIZED_SAMPLES is TRUE
'//
'// {DAD3AB78-1990-408B-BCE2-EBA673DACC10}   MF_MT_SAMPLE_SIZE               {UINT32}
$MF_MT_SAMPLE_SIZE = GUID$("{DAD3AB78-1990-408B-BCE2-EBA673DACC10}")

'// 4D3F7B23-D02F-4E6C-9BEE-E4BF2C6C695D     MF_MT_WRAPPED_TYPE              {Blob}
$MF_MT_WRAPPED_TYPE = GUID$("{4D3F7B23-D02F-4E6C-9BEE-E4BF2C6C695D}")

'//
'// AUDIO data
'//

'// {37E48BF5-645E-4C5B-89DE-ADA9E29B696A}   MF_MT_AUDIO_NUM_CHANNELS            {UINT32}
$MF_MT_AUDIO_NUM_CHANNELS = GUID$("{37E48BF5-645E-4C5B-89DE-ADA9E29B696A}")

'// {5FAEEAE7-0290-4C31-9E8A-C534F68D9DBA}   MF_MT_AUDIO_SAMPLES_PER_SECOND      {UINT32}
$MF_MT_AUDIO_SAMPLES_PER_SECOND = GUID$("{5FAEEAE7-0290-4C31-9E8A-C534F68D9DBA}")

'// {FB3B724A-CFB5-4319-AEFE-6E42B2406132}   MF_MT_AUDIO_FLOAT_SAMPLES_PER_SECOND {double}
$MF_MT_AUDIO_FLOAT_SAMPLES_PER_SECOND = GUID$("{FB3B724A-CFB5-4319-AEFE-6E42B2406132}")

'// {1AAB75C8-CFEF-451C-AB95-AC034B8E1731}   MF_MT_AUDIO_AVG_BYTES_PER_SECOND    {UINT32}
$MF_MT_AUDIO_AVG_BYTES_PER_SECOND = GUID$("{1AAB75C8-CFEF-451C-AB95-AC034B8E1731}")

'// {322DE230-9EEB-43BD-AB7A-FF412251541D}   MF_MT_AUDIO_BLOCK_ALIGNMENT         {UINT32}
$MF_MT_AUDIO_BLOCK_ALIGNMENT = GUID$("{322DE230-9EEB-43BD-AB7A-FF412251541D}")

'// {F2DEB57F-40FA-4764-AA33-ED4F2D1FF669}   MF_MT_AUDIO_BITS_PER_SAMPLE         {UINT32}
$MF_MT_AUDIO_BITS_PER_SAMPLE = GUID$("{F2DEB57F-40FA-4764-AA33-ED4F2D1FF669}")

'// {D9BF8D6A-9530-4B7C-9DDF-FF6FD58BBD06}   MF_MT_AUDIO_VALID_BITS_PER_SAMPLE   {UINT32}
$MF_MT_AUDIO_VALID_BITS_PER_SAMPLE = GUID$("{D9BF8D6A-9530-4B7C-9DDF-FF6FD58BBD06}")

'// {AAB15AAC-E13A-4995-9222-501EA15C6877}   MF_MT_AUDIO_SAMPLES_PER_BLOCK       {UINT32}
$MF_MT_AUDIO_SAMPLES_PER_BLOCK = GUID$("{AAB15AAC-E13A-4995-9222-501EA15C6877}")

'// {55FB5765-644A-4CAF-8479-938983BB1588}`  MF_MT_AUDIO_CHANNEL_MASK            {UINT32}
$MF_MT_AUDIO_CHANNEL_MASK = GUID$("{55FB5765-644A-4CAF-8479-938983BB1588}")

'//
'// MF_MT_AUDIO_FOLDDOWN_MATRIX stores folddown structure from multichannel to stereo
'//

' // Size = 272 bytes
TYPE MFFOLDDOWN_MATRIX DWORD
   cbSize        AS DWORD   ' UINT32
   cSrcChannels  AS DWORD   ' UINT32 // number of source channels
   cDstChannels  AS DWORD   ' UINT32 // number of destination channels
   dwChannelMask AS DWORD   ' UINT32 // mask
   Coeff(63)     AS LONG    ' LONG[64]
END TYPE

'// {9D62927C-36BE-4CF2-B5C4-A3926E3E8711}`  MF_MT_AUDIO_FOLDDOWN_MATRIX         {BLOB, MFFOLDDOWN_MATRIX}
$MF_MT_AUDIO_FOLDDOWN_MATRIX = GUID$("{9D62927C-36BE-4CF2-B5C4-A3926E3E8711}")

'// {9D62927D-36BE-4CF2-B5C4-A3926E3E8711}`  MF_MT_AUDIO_WMADRC_PEAKREF         {UINT32}
$MF_MT_AUDIO_WMADRC_PEAKREF = GUID$("{9D62927D-36BE-4CF2-B5C4-A3926E3E8711}")

'// {9D62927E-36BE-4CF2-B5C4-A3926E3E8711}`  MF_MT_AUDIO_WMADRC_PEAKTARGET        {UINT32}
$MF_MT_AUDIO_WMADRC_PEAKTARGET = GUID$("{9D62927E-36BE-4CF2-B5C4-A3926E3E8711}")

'// {9D62927F-36BE-4CF2-B5C4-A3926E3E8711}`  MF_MT_AUDIO_WMADRC_AVGREF         {UINT32}
$MF_MT_AUDIO_WMADRC_AVGREF = GUID$("{9D62927F-36BE-4CF2-B5C4-A3926E3E8711}")

'// {9D629280-36BE-4CF2-B5C4-A3926E3E8711}`  MF_MT_AUDIO_WMADRC_AVGTARGET      {UINT32}
$MF_MT_AUDIO_WMADRC_AVGTARGET = GUID$("{9D629280-36BE-4CF2-B5C4-A3926E3E8711}")

'//
'// MF_MT_AUDIO_PREFER_WAVEFORMATEX tells the converter to prefer a plain WAVEFORMATEX rather than
'// a WAVEFORMATEXTENSIBLE when converting to a legacy type. It is set by the WAVEFORMATEX->IMFMediaType
'// conversion routines when the original format block is a non-extensible WAVEFORMATEX.
'//
'// This preference can be overridden and does not guarantee that the type can be correctly expressed
'// by a non-extensible type.
'//
'// {A901AABA-E037-458A-BDF6-545BE2074042}   MF_MT_AUDIO_PREFER_WAVEFORMATEX     {UINT32 (BOOL)}
$MF_MT_AUDIO_PREFER_WAVEFORMATEX = GUID$("{A901AABA-E037-458A-BDF6-545BE2074042}")

'#if (WINVER >= _WIN32_WINNT_WIN7)
'//
'// AUDIO - AAC extra data
'//

'// {BFBABE79-7434-4d1c-94F0-72A3B9E17188} MF_MT_AAC_PAYLOAD_TYPE       {UINT32}
$MF_MT_AAC_PAYLOAD_TYPE = GUID$("{BFBABE79-7434-4d1c-94F0-72A3B9E17188}")

'// {7632F0E6-9538-4d61-ACDA-EA29C8C14456} MF_MT_AAC_AUDIO_PROFILE_LEVEL_INDICATION       {UINT32}
$MF_MT_AAC_AUDIO_PROFILE_LEVEL_INDICATION = GUID$("{7632F0E6-9538-4d61-ACDA-EA29C8C14456}")

'#endif // (WINVER >= _WIN32_WINNT_WIN7)

'//
'// VIDEO core data
'//

'// {1652C33D-D6B2-4012-B834-72030849A37D}   MF_MT_FRAME_SIZE                {UINT64 (HI32(Width),LO32(Height))}
$MF_MT_FRAME_SIZE = GUID$("{1652C33D-D6B2-4012-B834-72030849A37D}")

'// {C459A2E8-3D2C-4E44-B132-FEE5156C7BB0}   MF_MT_FRAME_RATE                {UINT64 (HI32(Numerator),LO32(Denominator))}
$MF_MT_FRAME_RATE = GUID$("{C459A2E8-3D2C-4E44-B132-FEE5156C7BB0}")

'// {C6376A1E-8D0A-4027-BE45-6D9A0AD39BB6}   MF_MT_PIXEL_ASPECT_RATIO        {UINT64 (HI32(Numerator),LO32(Denominator))}
$MF_MT_PIXEL_ASPECT_RATIO = GUID$("{C6376A1E-8D0A-4027-BE45-6D9A0AD39BB6}")

'// {8772F323-355A-4CC7-BB78-6D61A048AE82}   MF_MT_DRM_FLAGS                 {UINT32 (anyof MFVideoDRMFlags)}
$MF_MT_DRM_FLAGS = GUID$("{8772F323-355A-4CC7-BB78-6D61A048AE82}")

' enum MFVideoDRMFlags
%MFVideoDRMFlag_None               = 0
%MFVideoDRMFlag_AnalogProtected    = 1
%MFVideoDRMFlag_DigitallyProtected = 2

'// {4D0E73E5-80EA-4354-A9D0-1176CEB028EA}   MF_MT_PAD_CONTROL_FLAGS         {UINT32 (oneof MFVideoPadFlags)}
$MF_MT_PAD_CONTROL_FLAGS = GUID$("{4D0E73E5-80EA-4354-A9D0-1176CEB028EA}")

' enum MFVideoPadFlags
%MFVideoPadFlag_PAD_TO_None = 0
%MFVideoPadFlag_PAD_TO_4x3  = 1
%MFVideoPadFlag_PAD_TO_16x9 = 2

'// {68ACA3CC-22D0-44E6-85F8-28167197FA38}   MF_MT_SOURCE_CONTENT_HINT       {UINT32 (oneof MFVideoSrcContentHintFlags)}
$MF_MT_SOURCE_CONTENT_HINT = GUID$("{68ACA3CC-22D0-44E6-85F8-28167197FA38}")

' enum MFVideoSrcContentHintFlags {
%MFVideoSrcContentHintFlag_None  = 0
%MFVideoSrcContentHintFlag_16x9  = 1
%MFVideoSrcContentHintFlag_235_1 = 2

'// {65DF2370-C773-4C33-AA64-843E068EFB0C}   MF_MT_CHROMA_SITING             {UINT32 (anyof MFVideoChromaSubsampling)}
$MF_MT_CHROMA_SITING = GUID$("{65DF2370-C773-4C33-AA64-843E068EFB0C}")

'// {E2724BB8-E676-4806-B4B2-A8D6EFB44CCD}   MF_MT_INTERLACE_MODE            {UINT32 (oneof MFVideoInterlaceMode)}
$MF_MT_INTERLACE_MODE = GUID$("{E2724BB8-E676-4806-B4B2-A8D6EFB44CCD}")

'// {5FB0FCE9-BE5C-4935-A811-EC838F8EED93}   MF_MT_TRANSFER_FUNCTION         {UINT32 (oneof MFVideoTransferFunction)}
$MF_MT_TRANSFER_FUNCTION = GUID$("{5FB0FCE9-BE5C-4935-A811-EC838F8EED93}")

'// {DBFBE4D7-0740-4EE0-8192-850AB0E21935}   MF_MT_VIDEO_PRIMARIES           {UINT32 (oneof MFVideoPrimaries)}
$MF_MT_VIDEO_PRIMARIES = GUID$("{DBFBE4D7-0740-4EE0-8192-850AB0E21935}")

'// {47537213-8CFB-4722-AA34-FBC9E24D77B8}   MF_MT_CUSTOM_VIDEO_PRIMARIES    {BLOB (MT_CUSTOM_VIDEO_PRIMARIES)}
$MF_MT_CUSTOM_VIDEO_PRIMARIES = GUID$("{47537213-8CFB-4722-AA34-FBC9E24D77B8}")

' // Size = 32 bytes
TYPE MT_CUSTOM_VIDEO_PRIMARIES DWORD
   fRx AS SINGLE   ' float
   fRy AS SINGLE   ' float
   fGx AS SINGLE   ' float
   fGy AS SINGLE   ' float
   fBx AS SINGLE   ' float
   fBy AS SINGLE   ' float
   fWx AS SINGLE   ' float
   fWy AS SINGLE   ' float
END TYPE

'// {3E23D450-2C75-4D25-A00E-B91670D12327}   MF_MT_YUV_MATRIX                {UINT32 (oneof MFVideoTransferMatrix)}
$MF_MT_YUV_MATRIX = GUID$("{3E23D450-2C75-4D25-A00E-B91670D12327}")

'// {53A0529C-890B-4216-8BF9-599367AD6D20}   MF_MT_VIDEO_LIGHTING            {UINT32 (oneof MFVideoLighting)}
$MF_MT_VIDEO_LIGHTING = GUID$("{53A0529C-890B-4216-8BF9-599367AD6D20}")

'// {C21B8EE5-B956-4071-8DAF-325EDF5CAB11}   MF_MT_VIDEO_NOMINAL_RANGE       {UINT32 (oneof MFNominalRange)}
$MF_MT_VIDEO_NOMINAL_RANGE = GUID$("{C21B8EE5-B956-4071-8DAF-325EDF5CAB11}")

'// {66758743-7E5F-400D-980A-AA8596C85696}   MF_MT_GEOMETRIC_APERTURE        {BLOB (MFVideoArea)}
$MF_MT_GEOMETRIC_APERTURE = GUID$("{66758743-7E5F-400D-980A-AA8596C85696}")

'// {D7388766-18FE-48C6-A177-EE894867C8C4}   MF_MT_MINIMUM_DISPLAY_APERTURE  {BLOB (MFVideoArea)}
$MF_MT_MINIMUM_DISPLAY_APERTURE = GUID$("{D7388766-18FE-48C6-A177-EE894867C8C4}")

'// {79614DDE-9187-48FB-B8C7-4D52689DE649}   MF_MT_PAN_SCAN_APERTURE         {BLOB (MFVideoArea)}
$MF_MT_PAN_SCAN_APERTURE = GUID$("{79614DDE-9187-48FB-B8C7-4D52689DE649}")

'// {4B7F6BC3-8B13-40B2-A993-ABF630B8204E}   MF_MT_PAN_SCAN_ENABLED          {UINT32 (BOOL)}
$MF_MT_PAN_SCAN_ENABLED = GUID$("{4B7F6BC3-8B13-40B2-A993-ABF630B8204E}")

'// {20332624-FB0D-4D9E-BD0D-CBF6786C102E}   MF_MT_AVG_BITRATE               {UINT32}
$MF_MT_AVG_BITRATE = GUID$("{20332624-FB0D-4D9E-BD0D-CBF6786C102E}")

'// {799CABD6-3508-4DB4-A3C7-569CD533DEB1}   MF_MT_AVG_BIT_ERROR_RATE        {UINT32}
$MF_MT_AVG_BIT_ERROR_RATE = GUID$("{799CABD6-3508-4DB4-A3C7-569CD533DEB1}")

'// {C16EB52B-73A1-476F-8D62-839D6A020652}   MF_MT_MAX_KEYFRAME_SPACING      {UINT32}
$MF_MT_MAX_KEYFRAME_SPACING = GUID$("{C16EB52B-73A1-476F-8D62-839D6A020652}")

'//
'// VIDEO - uncompressed format data
'//

'// {644B4E48-1E02-4516-B0EB-C01CA9D49AC6}   MF_MT_DEFAULT_STRIDE            {UINT32 (INT32)} // in bytes
$MF_MT_DEFAULT_STRIDE = GUID$("{644B4E48-1E02-4516-B0EB-C01CA9D49AC6}")

'// {6D283F42-9846-4410-AFD9-654D503B1A54}   MF_MT_PALETTE                   {BLOB (array of MFPaletteEntry - usually 256)}
$MF_MT_PALETTE = GUID$("{6D283F42-9846-4410-AFD9-654D503B1A54}")

'//
'// the following is only used for legacy data that was stuck at the end of the format block when the type
'// was converted from a VIDEOINFOHEADER or VIDEOINFOHEADER2 block in an AM_MEDIA_TYPE.
'//
'// {B6BC765F-4C3B-40A4-BD51-2535B66FE09D}   MF_MT_USER_DATA                 {BLOB}
$MF_MT_USER_DATA = GUID$("{B6BC765F-4C3B-40A4-BD51-2535B66FE09D}")

'// {73D1072D-1870-4174-A063-29FF4FF6C11E}   MF_MT_AM_FORMAT_TYPE
$MF_MT_AM_FORMAT_TYPE = GUID$("{73D1072D-1870-4174-A063-29FF4FF6C11E}")

'//
'// VIDEO - MPEG1/2 extra data
'//

'// {91F67885-4333-4280-97CD-BD5A6C03A06E}   MF_MT_MPEG_START_TIME_CODE      {UINT32}
$MF_MT_MPEG_START_TIME_CODE = GUID$("{91F67885-4333-4280-97CD-BD5A6C03A06E}")

'// {AD76A80B-2D5C-4E0B-B375-64E520137036}   MF_MT_MPEG2_PROFILE             {UINT32 (oneof AM_MPEG2Profile)}
$MF_MT_MPEG2_PROFILE = GUID$("{AD76A80B-2D5C-4E0B-B375-64E520137036}")

'// {96F66574-11C5-4015-8666-BFF516436DA7}   MF_MT_MPEG2_LEVEL               {UINT32 (oneof AM_MPEG2Level)}
$MF_MT_MPEG2_LEVEL = GUID$("{96F66574-11C5-4015-8666-BFF516436DA7}")

'// {31E3991D-F701-4B2F-B426-8AE3BDA9E04B}   MF_MT_MPEG2_FLAGS               {UINT32 (anyof AMMPEG2_xxx flags)}
$MF_MT_MPEG2_FLAGS = GUID$("{31E3991D-F701-4B2F-B426-8AE3BDA9E04B}")

'// {3C036DE7-3AD0-4C9E-9216-EE6D6AC21CB3}   MF_MT_MPEG_SEQUENCE_HEADER      {BLOB}
$MF_MT_MPEG_SEQUENCE_HEADER = GUID$("{3C036DE7-3AD0-4C9E-9216-EE6D6AC21CB3}")

'//
'// INTERLEAVED - DV extra data
'//
'// {84BD5D88-0FB8-4AC8-BE4B-A8848BEF98F3}   MF_MT_DV_AAUX_SRC_PACK_0        {UINT32}
$MF_MT_DV_AAUX_SRC_PACK_0 = GUID$("{84BD5D88-0FB8-4AC8-BE4B-A8848BEF98F3}")

'// {F731004E-1DD1-4515-AABE-F0C06AA536AC}   MF_MT_DV_AAUX_CTRL_PACK_0       {UINT32}
$MF_MT_DV_AAUX_CTRL_PACK_0 = GUID$("{F731004E-1DD1-4515-AABE-F0C06AA536AC}")

'// {720E6544-0225-4003-A651-0196563A958E}   MF_MT_DV_AAUX_SRC_PACK_1        {UINT32}
$MF_MT_DV_AAUX_SRC_PACK_1 = GUID$("{720E6544-0225-4003-A651-0196563A958E}")

'// {CD1F470D-1F04-4FE0-BFB9-D07AE0386AD8}   MF_MT_DV_AAUX_CTRL_PACK_1       {UINT32}
$MF_MT_DV_AAUX_CTRL_PACK_1 = GUID$("{CD1F470D-1F04-4FE0-BFB9-D07AE0386AD8}")

'// {41402D9D-7B57-43C6-B129-2CB997F15009}   MF_MT_DV_VAUX_SRC_PACK          {UINT32}
$MF_MT_DV_VAUX_SRC_PACK = GUID$("{41402D9D-7B57-43C6-B129-2CB997F15009}")

'// {2F84E1C4-0DA1-4788-938E-0DFBFBB34B48}   MF_MT_DV_VAUX_CTRL_PACK         {UINT32}
$MF_MT_DV_VAUX_CTRL_PACK = GUID$("{2F84E1C4-0DA1-4788-938E-0DFBFBB34B48}")

'#if (WINVER >= _WIN32_WINNT_WIN7)
'//
'// ARBITRARY
'//

'//
'// MT_ARBITRARY_HEADER stores information about the format of an arbitrary media type
'//
' // Size = 60 bytes
TYPE MT_ARBITRARY_HEADER DWORD
   majortype            AS GUID    ' GUID
   subtype              AS GUID    ' GUID
   bFixedSizeSamples    AS LONG    ' BOOL
   bTemporalCompression AS LONG    ' BOOL
   lSampleSize          AS DWORD   ' ULONG
   formattype           AS GUID    ' GUID
END TYPE

'// {9E6BD6F5-0109-4f95-84AC-9309153A19FC}   MF_MT_ARBITRARY_HEADER          {MT_ARBITRARY_HEADER}
$MF_MT_ARBITRARY_HEADER = GUID$("{9E6BD6F5-0109-4f95-84AC-9309153A19FC}")

'// {5A75B249-0D7D-49a1-A1C3-E0D87F0CADE5}   MF_MT_ARBITRARY_FORMAT          {Blob}
$MF_MT_ARBITRARY_FORMAT = GUID$("{5A75B249-0D7D-49a1-A1C3-E0D87F0CADE5}")


'//
'// IMAGE
'//
'// {ED062CF4-E34E-4922-BE99-934032133D7C}   MF_MT_IMAGE_LOSS_TOLERANT       {UINT32 (BOOL)}
$MF_MT_IMAGE_LOSS_TOLERANT = GUID$("{ED062CF4-E34E-4922-BE99-934032133D7C}")


'//
'// MPEG-4 Media Type Attributes
'//
'// {261E9D83-9529-4B8F-A111-8B9C950A81A9}   MF_MT_MPEG4_SAMPLE_DESCRIPTION   {BLOB}
$MF_MT_MPEG4_SAMPLE_DESCRIPTION = GUID$("{261E9D83-9529-4B8F-A111-8B9C950A81A9}")

'// {9aa7e155-b64a-4c1d-a500-455d600b6560}   MF_MT_MPEG4_CURRENT_SAMPLE_ENTRY {UINT32}
$MF_MT_MPEG4_CURRENT_SAMPLE_ENTRY = GUID$("{9aa7e155-b64a-4c1d-a500-455d600b6560}")

'//
'// Save original format information for AVI and WAV files
'//
'// {d7be3fe0-2bc7-492d-b843-61a1919b70c3}   MF_MT_ORIGINAL_4CC               (UINT32)
$MF_MT_ORIGINAL_4CC = GUID$("{d7be3fe0-2bc7-492d-b843-61a1919b70c3}")

'// {8cbbc843-9fd9-49c2-882f-a72586c408ad}   MF_MT_ORIGINAL_WAVE_FORMAT_TAG   (UINT32)
$MF_MT_ORIGINAL_WAVE_FORMAT_TAG = GUID$("{8cbbc843-9fd9-49c2-882f-a72586c408ad}")


'//
'// Video Capture Media Type Attributes
'//

'// {D2E7558C-DC1F-403f-9A72-D28BB1EB3B5E}   MF_MT_FRAME_RATE_RANGE_MIN      {UINT64 (HI32(Numerator),LO32(Denominator))}
$MF_MT_FRAME_RATE_RANGE_MIN = GUID$("{D2E7558C-DC1F-403f-9A72-D28BB1EB3B5E}")

'// {E3371D41-B4CF-4a05-BD4E-20B88BB2C4D6}   MF_MT_FRAME_RATE_RANGE_MAX      {UINT64 (HI32(Numerator),LO32(Denominator))}
$MF_MT_FRAME_RATE_RANGE_MAX = GUID$("{E3371D41-B4CF-4a05-BD4E-20B88BB2C4D6}")

'#endif // (WINVER >= _WIN32_WINNT_WIN7)

'////////////////////////////////////////////////////////////////////////////////
'///////////////////////////////  Media Type GUIDs //////////////////////////////
'////////////////////////////////////////////////////////////////////////////////

'//
'// Major types
'//

$MFMediaType_Default      = GUID$("{81A412E6-8103-4B06-857F-1862781024AC}")
$MFMediaType_Audio        = GUID$("{73647561-0000-0010-8000-00AA00389B71}")
$MFMediaType_Video        = GUID$("{73646976-0000-0010-8000-00AA00389B71}")
$MFMediaType_Protected    = GUID$("{7B4B6FE6-9D04-4494-BE14-7E0BD076C8E4}")
$MFMediaType_SAMI         = GUID$("{E69669A0-3DCD-40CB-9E2E-3708387C0616}")
$MFMediaType_Script       = GUID$("{72178C22-E45B-11D5-BC2A-00B0D0F3F4AB}")
$MFMediaType_Image        = GUID$("{72178C23-E45B-11D5-BC2A-00B0D0F3F4AB}")
$MFMediaType_HTML         = GUID$("{72178C24-E45B-11D5-BC2A-00B0D0F3F4AB}")
$MFMediaType_Binary       = GUID$("{72178C25-E45B-11D5-BC2A-00B0D0F3F4AB}")
$MFMediaType_FileTransfer = GUID$("{72178C26-E45B-11D5-BC2A-00B0D0F3F4AB}")

'//
'// Representations
'//

$AM_MEDIA_TYPE_REPRESENTATION = GUID$("{E2E42AD2-132C-491E-A268-3C7C2DCA181F}")
$FORMAT_MFVideoFormat         = GUID$("{AED4AB2D-7326-43CB-9464-C879CAB9C43D}")

'///////////////////////////////////////////////////////////////////////////////////////////////////////////////  Media Type functions //////////////////////////
'////////////////////////////////////////////////////////////////////////////////

'//
'// Forward declaration
'//
'struct tagVIDEOINFOHEADER;
'typedef struct tagVIDEOINFOHEADER VIDEOINFOHEADER;
'struct tagVIDEOINFOHEADER2;
'typedef struct tagVIDEOINFOHEADER2 VIDEOINFOHEADER2;
'struct tagMPEG1VIDEOINFO;
'typedef struct tagMPEG1VIDEOINFO MPEG1VIDEOINFO;
'struct tagMPEG2VIDEOINFO;
'typedef struct tagMPEG2VIDEOINFO MPEG2VIDEOINFO;
'struct _AMMediaType;
'typedef struct _AMMediaType AM_MEDIA_TYPE;

DECLARE FUNCTION MFValidateMediaTypeSize IMPORT "MFPLAT.DLL" ALIAS "MFValidateMediaTypeSize" ( _
   BYVAL FormatType AS GUID _                           ' __in GUID    FormatType
 , BYVAL pBlock AS BYTE PTR _                           ' __in UINT8*  pBlock
 , BYVAL cbSize AS DWORD _                              ' __in UINT32  cbSize
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateMediaType IMPORT "MFPLAT.DLL" ALIAS "MFCreateMediaType" ( _
   BYREF ppMFType AS IMFMediaType _                     ' __out IMFMediaType** ppMFType
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateMFVideoFormatFromMFMediaType IMPORT "MFPLAT.DLL" ALIAS "MFCreateMFVideoFormatFromMFMediaType" ( _
   BYVAL pMFType AS IMFMediaType _                      ' __in  IMFMediaType*   pMFType
 , BYREF ppMFVF AS DWORD _                              ' __out MFVIDEOFORMAT** ppMFVF  // must be deleted with CoTaskMemFree
 , BYREF pcbSize AS DWORD _                             ' __out UINT32*         pcbSize
 ) AS LONG                                              ' HRESULT

' enum _MFWaveFormatExConvertFlags
%MFWaveFormatExConvertFlag_Normal            = 0
%MFWaveFormatExConvertFlag_ForceExtensible   = 1

DECLARE FUNCTION MFCreateWaveFormatExFromMFMediaType IMPORT "MFPLAT.DLL" ALIAS "MFCreateWaveFormatExFromMFMediaType" ( _
   BYVAL pMFType AS IMFMediaType _                      ' __in  IMFMediaType*   pMFType
 , BYREF ppWF AS DWORD _                                ' __out WAVEFORMATEX**  ppWF  // must be freed with CoTaskMemFree
 , BYREF pcbSize AS DWORD _                             ' __out UINT32*         pcbSize
 , BYVAL Flags AS DWORD _                               ' __in  UINT32          Flags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFInitMediaTypeFromVideoInfoHeader IMPORT "MFPLAT.DLL" ALIAS "MFInitMediaTypeFromVideoInfoHeader" ( _
   BYVAL pMFType AS IMFMediaType _                      ' __in IMFMediaType*           pMFType
 , BYREF pVIH AS VIDEOINFOHEADER _                      ' __in const VIDEOINFOHEADER*  pVIH
 , BYVAL cbBufSize AS DWORD _                           ' __in UINT32                  cbBufSize
 , BYREF pSubtype AS GUID _                             ' __in const GUID*             pSubtype
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFInitMediaTypeFromVideoInfoHeader2 IMPORT "MFPLAT.DLL" ALIAS "MFInitMediaTypeFromVideoInfoHeader2" ( _
   BYVAL pMFType AS IMFMediaType _                      ' __in IMFMediaType*           pMFType
 , BYREF pVIH2 AS VIDEOINFOHEADER2 _                    ' __in const VIDEOINFOHEADER2* pVIH2
 , BYVAL cbBufSize AS DWORD _                           ' __in UINT32                  cbBufSize
 , BYREF pSubtype AS GUID _                             ' __in const GUID*             pSubtype
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFInitMediaTypeFromMPEG1VideoInfo IMPORT "MFPLAT.DLL" ALIAS "MFInitMediaTypeFromMPEG1VideoInfo" ( _
   BYVAL pMFType AS IMFMediaType _                      ' __in IMFMediaType*           pMFType
 , BYREF pMP1VI AS MPEG1VIDEOINFO _                     ' __in const MPEG1VIDEOINFO*   pMP1VI
 , BYVAL cbBufSize AS DWORD _                           ' __in UINT32                  cbBufSize
 , BYREF pSubtype AS GUID _                             ' __in const GUID*             pSubtype
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFInitMediaTypeFromMPEG2VideoInfo IMPORT "MFPLAT.DLL" ALIAS "MFInitMediaTypeFromMPEG2VideoInfo" ( _
   BYVAL pMFType AS IMFMediaType _                      ' __in IMFMediaType*           pMFType
 , BYREF pMP2VI AS MPEG2VIDEOINFO _                     ' __in const MPEG2VIDEOINFO*   pMP2VI
 , BYVAL cbBufSize AS DWORD _                           ' __in UINT32                  cbBufSize
 , BYREF pSubtype AS GUID _                             ' __in const GUID*             pSubtype
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCalculateBitmapImageSize IMPORT "MFPLAT.DLL" ALIAS "MFCalculateBitmapImageSize" ( _
   BYREF pBMIH AS BITMAPINFOHEADER _                    ' __in  const BITMAPINFOHEADER* pBMIH
 , BYVAL cbBufSize AS DWORD _                           ' __in  UINT32                  cbBufSize
 , BYREF pcbImageSize AS DWORD _                        ' __out UINT32*                 pcbImageSize
 , BYREF pbKnown AS LONG _                              ' __out BOOL*                   pbKnown
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCalculateImageSize IMPORT "MFPLAT.DLL" ALIAS "MFCalculateImageSize" ( _
   BYREF guidSubtype AS GUID _                          ' __in  REFGUID guidSubtype
 , BYVAL unWidth AS DWORD _                             ' __in  UINT32  unWidth
 , BYVAL unHeight AS DWORD _                            ' __in  UINT32  unHeight
 , BYREF pcbImageSize AS DWORD _                        ' __out UINT32* pcbImageSize
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFFrameRateToAverageTimePerFrame IMPORT "MFPLAT.DLL" ALIAS "MFFrameRateToAverageTimePerFrame" ( _
   BYVAL unNumerator AS DWORD _                         ' __in  UINT32  unNumerator
 , BYVAL unDenominator AS DWORD _                       ' __in  UINT32  unDenominator
 , BYREF punAverageTimePerFrame AS QUAD _               ' __out UINT64* punAverageTimePerFrame
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFAverageTimePerFrameToFrameRate IMPORT "MFPLAT.DLL" ALIAS "MFAverageTimePerFrameToFrameRate" ( _
   BYVAL unAverageTimePerFrame AS QUAD _                ' __in  UINT64  unAverageTimePerFrame
 , BYREF punNumerator AS DWORD _                        ' __out UINT32* punNumerator
 , BYREF punDenominator AS DWORD _                      ' __out UINT32* punDenominator
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFInitMediaTypeFromMFVideoFormat IMPORT "MFPLAT.DLL" ALIAS "MFInitMediaTypeFromMFVideoFormat" ( _
   BYVAL pMFType AS IMFMediaType _                      ' __in IMFMediaType*        pMFType
 , BYREF pMFVF AS MFVIDEOFORMAT _                       ' __in const MFVIDEOFORMAT* pMFVF
 , BYVAL cbBufSize AS DWORD _                           ' __in UINT32               cbBufSize
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFInitMediaTypeFromWaveFormatEx IMPORT "MFPLAT.DLL" ALIAS "MFInitMediaTypeFromWaveFormatEx" ( _
   BYVAL pMFType AS IMFMediaType _                      ' __in IMFMediaType*        pMFType
 , BYREF pWaveFormat AS WAVEFORMATEX _                  ' __in const WAVEFORMATEX*  pWaveFormat
 , BYVAL cbBufSize AS DWORD _                           ' __in UINT32               cbBufSize
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFInitMediaTypeFromAMMediaType IMPORT "MFPLAT.DLL" ALIAS "MFInitMediaTypeFromAMMediaType" ( _
   BYVAL pMFType AS IMFMediaType _                      ' __in IMFMediaType*        pMFType
 , BYREF pAMType AS AM_MEDIA_TYPE _                     ' __in const AM_MEDIA_TYPE* pAMType
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFInitAMMediaTypeFromMFMediaType IMPORT "MFPLAT.DLL" ALIAS "MFInitAMMediaTypeFromMFMediaType" ( _
   BYVAL pMFType AS IMFMediaType _                      ' __in IMFMediaType*        pMFType
 , BYVAL guidFormatBlockType AS GUID _                  ' __in GUID                 guidFormatBlockType
 , BYREF pAMType AS AM_MEDIA_TYPE _                     ' __in_out AM_MEDIA_TYPE*   pAMType
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateAMMediaTypeFromMFMediaType IMPORT "MFPLAT.DLL" ALIAS "MFCreateAMMediaTypeFromMFMediaType" ( _
   BYVAL pMFType AS IMFMediaType _                      ' __in IMFMediaType*        pMFType
 , BYVAL guidFormatBlockType AS GUID _                  ' __in GUID                 guidFormatBlockType
 , BYREF ppAMType AS AM_MEDIA_TYPE _                    ' __in_out AM_MEDIA_TYPE**  ppAMType // delete with DeleteMediaType
 ) AS LONG                                              ' HRESULT

'//
'// This function compares a full media type to a partial media type.
'//
'// A "partial" media type is one that is given out by a component as a possible
'// media type it could accept. Many attributes may be unset, which represents
'// a "don't care" status for that attribute.
'//
'// For example, a video effect may report that it supports YV12,
'// but not want to specify a particular size. It simply creates a media type and sets
'// the major type to MFMediaType_Video and the subtype to MEDIASUBTYPE_YV12.
'//
'// The comparison function succeeds if the partial type contains at least a major type,
'// and all of the attributes in the partial type exist in the full type and are set to
'// the same value.
'//

DECLARE FUNCTION MFCompareFullToPartialMediaType IMPORT "MFPLAT.DLL" ALIAS "MFCompareFullToPartialMediaType" ( _
   BYVAL pMFTypeFull AS IMFMediaType _                  ' __in IMFMediaType*   pMFTypeFull
 , BYVAL pMFTypePartial AS IMFMediaType _               ' __in IMFMediaType*   pMFTypePartial
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MFWrapMediaType IMPORT "MFPLAT.DLL" ALIAS "MFWrapMediaType" ( _
   BYVAL pOrig AS IMFMediaType _                        ' __in  IMFMediaType*  pOrig
 , BYREF MajorType AS GUID _                            ' __in  REFGUID        MajorType
 , BYREF SubType AS GUID _                              ' __in  REFGUID        SubType
 , BYREF ppWrap AS IMFMediaType _                       ' __out IMFMediaType **ppWrap
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFUnwrapMediaType IMPORT "MFPLAT.DLL" ALIAS "MFUnwrapMediaType" ( _
   BYVAL pWrap AS IMFMediaType _                        ' __in  IMFMediaType*  pWrap
 , BYREF ppOrig AS IMFMediaType _                       ' __out IMFMediaType **ppOrig
 ) AS LONG                                              ' HRESULT

'//
'// MFCreateVideoMediaType
'//

'#ifdef _KSMEDIA_
'STDAPI MFCreateVideoMediaTypeFromVideoInfoHeader(
'    const KS_VIDEOINFOHEADER* pVideoInfoHeader,
'    DWORD cbVideoInfoHeader,
'    DWORD dwPixelAspectRatioX,
'    DWORD dwPixelAspectRatioY,
'    MFVideoInterlaceMode InterlaceMode,
'    QWORD VideoFlags,
'    const GUID* pSubtype,
'    IMFVideoMediaType** ppIVideoMediaType
'    );

'STDAPI MFCreateVideoMediaTypeFromVideoInfoHeader2(
'    const KS_VIDEOINFOHEADER2* pVideoInfoHeader,
'    DWORD cbVideoInfoHeader,
'    QWORD AdditionalVideoFlags,
'    const GUID* pSubtype,
'    IMFVideoMediaType** ppIVideoMediaType
'    );

'#endif

DECLARE FUNCTION MFCreateVideoMediaType IMPORT "MFPLAT.DLL" ALIAS "MFCreateVideoMediaType" ( _
   BYREF pVideoFormat AS MFVIDEOFORMAT _                ' __in  const MFVIDEOFORMAT* pVideoFormat
 , BYREF ppIVideoMediaType AS IMFVideoMediaType _       ' __out IMFVideoMediaType** ppIVideoMediaType
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateVideoMediaTypeFromSubtype IMPORT "MFPLAT.DLL" ALIAS "MFCreateVideoMediaTypeFromSubtype" ( _
   BYREF pAMSubtype AS GUID _                           ' __in  const GUID* pAMSubtype
 , BYREF ppIVideoMediaType AS IMFVideoMediaType _       ' __out IMFVideoMediaType** ppIVideoMediaType
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFIsFormatYUV IMPORT "EVR.DLL" ALIAS "MFIsFormatYUV" ( _
   BYVAL Format AS DWORD _                              ' __in DWORD Format
 ) AS LONG                                              ' BOOL

'//
'//  These depend on BITMAPINFOHEADER being defined
'//

DECLARE FUNCTION MFCreateVideoMediaTypeFromBitMapInfoHeader IMPORT "MFPLAT.DLL" ALIAS "MFCreateVideoMediaTypeFromBitMapInfoHeader" ( _
   BYREF pbmihBitMapInfoHeader AS BITMAPINFOHEADER _    ' __in  const BITMAPINFOHEADER* pbmihBitMapInfoHeader
 , BYVAL dwPixelAspectRatioX AS DWORD _                 ' __in  DWORD dwPixelAspectRatioX
 , BYVAL dwPixelAspectRatioY AS DWORD _                 ' __in  DWORD dwPixelAspectRatioY
 , BYVAL InterlaceMode AS LONG _                        ' __in  MFVideoInterlaceMode InterlaceMode
 , BYVAL VideoFlags AS QUAD _                           ' __in  QWORD VideoFlags
 , BYVAL qwFramesPerSecondNumerator AS QUAD _           ' __in  QWORD qwFramesPerSecondNumerator
 , BYVAL qwFramesPerSecondDenominator AS QUAD _         ' __in  QWORD qwFramesPerSecondDenominator
 , BYVAL dwMaxBitRate AS DWORD _                        ' __in  DWORD dwMaxBitRate
 , BYREF ppIVideoMediaType AS IMFVideoMediaType _       ' __out IMFVideoMediaType** ppIVideoMediaType
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFGetStrideForBitmapInfoHeader IMPORT "MFPLAT.DLL" ALIAS "MFGetStrideForBitmapInfoHeader" ( _
   BYVAL format AS DWORD _                              ' __in  DWORD format
 , BYVAL dwWidth AS DWORD _                             ' __in  DWORD dwWidth
 , BYREF pStride AS LONG _                              ' __out LONG* pStride
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFGetPlaneSize IMPORT "MFPLAT.DLL" ALIAS "MFGetPlaneSize" ( _
   BYVAL format AS DWORD _                              ' __in  DWORD format
 , BYVAL dwWidth AS DWORD _                             ' __in  DWORD dwWidth
 , BYVAL dwHeight AS DWORD _                            ' __in  DWORD dwHeight
 , BYREF pdwPlaneSize AS DWORD _                        ' __out DWORD* pdwPlaneSize
 ) AS LONG                                              ' HRESULT

'#if (WINVER >= _WIN32_WINNT_WIN7)
'//
'// MFCreateVideoMediaTypeFromBitMapInfoHeaderEx
'//
DECLARE FUNCTION MFCreateVideoMediaTypeFromBitMapInfoHeaderEx IMPORT "MFPLAT.DLL" ALIAS "MFCreateVideoMediaTypeFromBitMapInfoHeaderEx" ( _
   BYREF pbmihBitMapInfoHeader AS BITMAPINFOHEADER _    ' __in const BITMAPINFOHEADER* pbmihBitMapInfoHeader
 , BYVAL cbBitMapInfoHeader AS DWORD _                  ' __in UINT32 cbBitMapInfoHeader
 , BYVAL dwPixelAspectRatioX AS DWORD _                 ' __in DWORD dwPixelAspectRatioX
 , BYVAL dwPixelAspectRatioY AS DWORD _                 ' __in DWORD dwPixelAspectRatioY
 , BYVAL InterlaceMode AS LONG _                        ' __in MFVideoInterlaceMode InterlaceMode
 , BYVAL VideoFlags AS QUAD _                           ' __in QWORD VideoFlags
 , BYVAL dwFramesPerSecondNumerator AS DWORD _          ' __in DWORD dwFramesPerSecondNumerator
 , BYVAL dwFramesPerSecondDenominator AS DWORD _        ' __in DWORD dwFramesPerSecondDenominator
 , BYVAL dwMaxBitRate AS DWORD _                        ' __in DWORD dwMaxBitRate
 , BYREF ppIVideoMediaType AS IMFVideoMediaType _       ' __out IMFVideoMediaType** ppIVideoMediaType
 ) AS LONG                                              ' HRESULT

'#endif // (WINVER >= _WIN32_WINNT_WIN7)

'//
'// MFCreateMediaTypeFromRepresentation
'//

DECLARE FUNCTION MFCreateMediaTypeFromRepresentation IMPORT "MFPLAT.DLL" ALIAS "MFCreateMediaTypeFromRepresentation" ( _
   BYVAL guidRepresentation AS GUID _                   ' __in  GUID guidRepresentation
 , BYVAL pvRepresentation AS DWORD _                    ' __in  LPVOID pvRepresentation
 , BYREF ppIMediaType AS IMFMediaType _                 ' __out IMFMediaType** ppIMediaType
 ) AS LONG                                              ' HRESULT

'//
'// MFCreateAudioMediaType
'//

DECLARE FUNCTION MFCreateAudioMediaType IMPORT "MFPLAT.DLL" ALIAS "MFCreateAudioMediaType" ( _
   BYREF pAudioFormat AS WAVEFORMATEX _                 ' __in  const WAVEFORMATEX* pAudioFormat
 , BYREF ppIAudioMediaType AS IMFAudioMediaType _       ' __out IMFAudioMediaType** ppIAudioMediaType
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFGetUncompressedVideoFormat IMPORT "MFPLAT.DLL" ALIAS "MFGetUncompressedVideoFormat" ( _
   BYREF pVideoFormat AS MFVIDEOFORMAT _                ' __in const MFVIDEOFORMAT* pVideoFormat
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MFInitVideoFormat IMPORT "MFPLAT.DLL" ALIAS "MFInitVideoFormat" ( _
   BYREF pVideoFormat AS MFVIDEOFORMAT _                ' __in MFVIDEOFORMAT*        pVideoFormat
 , BYVAL type AS LONG _                                 ' __in MFStandardVideoFormat type
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFInitVideoFormat_RGB IMPORT "MFPLAT.DLL" ALIAS "MFInitVideoFormat_RGB" ( _
   BYREF pVideoFormat AS MFVIDEOFORMAT _                ' __in MFVIDEOFORMAT* pVideoFormat
 , BYVAL dwWidth AS DWORD _                             ' __in DWORD          dwWidth
 , BYVAL dwHeight AS DWORD _                            ' __in DWORD          dwHeight
 , BYVAL D3Dfmt AS DWORD _                              ' __in DWORD          D3Dfmt /* 0 indicates sRGB */
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFConvertColorInfoToDXVA IMPORT "MFPLAT.DLL" ALIAS "MFConvertColorInfoToDXVA" ( _
   BYREF pdwToDXVA AS DWORD _                           ' __out DWORD* pdwToDXVA
 , BYREF pFromFormat AS MFVIDEOFORMAT _                 ' __in  const MFVIDEOFORMAT* pFromFormat
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFConvertColorInfoFromDXVA IMPORT "MFPLAT.DLL" ALIAS "MFConvertColorInfoFromDXVA" ( _
   BYREF pToFormat AS MFVIDEOFORMAT _                   ' __in MFVIDEOFORMAT* pToFormat
 , BYVAL dwFromDXVA AS DWORD _                          ' __in DWORD dwFromDXVA
 ) AS LONG                                              ' HRESULT

'//
'// Optimized stride copy function
'//

DECLARE FUNCTION MFCopyImage IMPORT "MFPLAT.DLL" ALIAS "MFCopyImage" ( _
   BYVAL pDest AS BYTE PTR _                            ' BYTE* pDest
 , BYVAL lDestStride AS LONG _                          ' LONG  lDestStride
 , BYVAL pSrc AS BYTE PTR _                             ' const BYTE* pSrc
 , BYVAL lSrcStride AS LONG _                           ' LONG  lSrcStride
 , BYVAL dwWidthInBytes AS DWORD _                      ' DWORD dwWidthInBytes
 , BYVAL dwLines AS DWORD _                             ' DWORD dwLines
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFConvertFromFP16Array IMPORT "MFPLAT.DLL" ALIAS "MFConvertFromFP16Array" ( _
   BYREF pDest AS SINGLE _                              ' float* pDest
 , BYREF pSrc AS WORD _                                 ' const WORD* pSrc
 , BYVAL dwCount AS DWORD _                             ' DWORD dwCount
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFConvertToFP16Array IMPORT "MFPLAT.DLL" ALIAS "MFConvertToFP16Array" ( _
   BYREF pDest AS DWORD _                               ' WORD* pDest
 , BYREF pSrc AS SINGLE _                               ' const float* pSrc
 , BYVAL dwCount AS DWORD _                             ' DWORD dwCount
 ) AS LONG                                              ' HRESULT



'///////////////////////////////////////////////////////////////////////////////////////////////////////////////  Attributes Utility functions ////////////////////////////
'////////////////////////////////////////////////////////////////////////////////

'#ifdef __cplusplus

'//
'// IMFAttributes inline UTILITY FUNCTIONS - used for IMFMediaType as well
'//
'inline
'UINT32
'HI32(UINT64 unPacked)
'{
'    return (UINT32)(unPacked >> 32);
'}

' Use HI(DWORD, unPacked)

'inline
'UINT32
'LO32(UINT64 unPacked)
'{
'    return (UINT32)unPacked;
'}

' Use LO(DWORD, unPacked)


'inline
'UINT64
'Pack2UINT32AsUINT64(UINT32 unHigh, UINT32 unLow)
'{
'    return ((UINT64)unHigh << 32) | unLow;
'}

FUNCTION Pack2UINT32AsUINT64(BYVAL unHigh AS DWORD, BYVAL unLow AS DWORD) AS QUAD
   SHIFT LEFT unHigh, 32
   FUNCTION = unHigh OR unLow
END FUNCTION

'inline
'void
'Unpack2UINT32AsUINT64(UINT64 unPacked, UINT32* punHigh, UINT32* punLow)
'{
'    *punHigh = HI32(unPacked);
'    *punLow = LO32(unPacked);
'}

SUB Unpack2UINT32AsUINT64(BYVAL unPacked AS QUAD, BYREF punHigh AS DWORD, BYREF punLow AS DWORD)
   punHigh = HI(DWORD, unPacked)
   punLow = LO(DWORD, unPacked)
END SUB

'inline
'UINT64
'PackSize(UINT32 unWidth, UINT32 unHeight)
'{
'    return Pack2UINT32AsUINT64(unWidth, unHeight);
'}

FUNCTION PackSize(BYVAL unWidth AS DWORD, BYVAL unHeight AS DWORD) AS QUAD
   FUNCTION = Pack2UINT32AsUINT64(unWidth, unHeight)
END FUNCTION

'inline
'void
'UnpackSize(UINT64 unPacked, UINT32* punWidth, UINT32* punHeight)
'{
'    Unpack2UINT32AsUINT64(unPacked, punWidth, punHeight);
'}

SUB UnpackSize(BYVAL unPacked AS QUAD, BYREF punWidth AS DWORD, BYREF punHeight AS DWORD)
   Unpack2UINT32AsUINT64(unPacked, punWidth, punHeight)
END SUB

'inline
'UINT64
'PackRatio(INT32 nNumerator, UINT32 unDenominator)
'{
'    return Pack2UINT32AsUINT64((UINT32)nNumerator, unDenominator);
'}

FUNCTION PackRatio(BYVAL nNumerator AS DWORD, BYVAL unDenominator AS DWORD) AS QUAD
   FUNCTION = Pack2UINT32AsUINT64(nNumerator, unDenominator)
END FUNCTION

'inline
'void
'UnpackRatio(UINT64 unPacked, INT32* pnNumerator, UINT32* punDenominator)
'{
'    Unpack2UINT32AsUINT64(unPacked, (UINT32*)pnNumerator, punDenominator);
'}

SUB UnpackRatio(BYVAL unPacked AS QUAD, BYREF pnNumerator AS DWORD, BYREF punDenominator AS DWORD)
   Unpack2UINT32AsUINT64(unPacked, pnNumerator, punDenominator)
END SUB

'//
'// "failsafe" inline get methods - return the stored value or return a default
'//
'inline
'UINT32
'MFGetAttributeUINT32(
'    IMFAttributes*  pAttributes,
'    REFGUID         guidKey,
'    UINT32          unDefault
'    )
'{
'    UINT32 unRet;
'    if (FAILED(pAttributes->GetUINT32(guidKey, &unRet))) {
'        unRet = unDefault;
'    }
'    return unRet;
'}

FUNCTION MFGetAttributeUINT32( _
   BYVAL pAttributes AS IMFAttributes, _
   BYREF guidKey AS GUID, _
   BYVAL unDefault AS DWORD) AS DWORD

   LOCAL unRet AS DWORD
   IF FAILED(pAttributes.GetUINT32(guidKey, unRet)) THEN unRet = unDefault
   FUNCTION = unRet

END FUNCTION

'inline
'UINT64
'MFGetAttributeUINT64(
'    IMFAttributes*  pAttributes,
'    REFGUID         guidKey,
'    UINT64          unDefault
'    )
'{
'    UINT64 unRet;
'    if (FAILED(pAttributes->GetUINT64(guidKey, &unRet))) {
'        unRet = unDefault;
'    }
'    return unRet;
'}

FUNCTION MFGetAttributeUINT64( _
   BYVAL pAttributes AS IMFAttributes, _
   BYREF guidKey AS GUID, _
   BYVAL unDefault AS QUAD) AS QUAD

   LOCAL unRet AS QUAD
   IF FAILED(pAttributes.GetUINT64(guidKey, unRet)) THEN unRet = unDefault
   FUNCTION = unRet

END FUNCTION

'inline
'double
'MFGetAttributeDouble(
'    IMFAttributes*  pAttributes,
'    REFGUID         guidKey,
'    double          fDefault
'    )
'{
'    double fRet;
'    if (FAILED(pAttributes->GetDouble(guidKey, &fRet))) {
'        fRet = fDefault;
'    }
'    return fRet;
'}

FUNCTION MFGetAttributeDouble( _
   BYVAL pAttributes AS IMFAttributes, _
   BYREF guidKey AS GUID, _
   BYVAL fDefault AS DOUBLE) AS DOUBLE

   LOCAL fRet AS DOUBLE
   IF FAILED(pAttributes.GetDouble(guidKey, fRet)) THEN fRet = fDefault
   FUNCTION = fRet

END FUNCTION

'//
'// helpers for getting/setting ratios and sizes
'//

'inline
'HRESULT
'MFGetAttribute2UINT32asUINT64(
'    IMFAttributes*  pAttributes,
'    REFGUID         guidKey,
'    UINT32*         punHigh32,
'    UINT32*         punLow32
'    )
'{
'    UINT64 unPacked;
'    HRESULT hr = S_OK;

'    hr = pAttributes->GetUINT64(guidKey, &unPacked);
'    if (FAILED(hr)) {
'        return hr;
'    }
'    Unpack2UINT32AsUINT64(unPacked, punHigh32, punLow32);

'    return hr;
'}

FUNCTION MFGetAttribute2UINT32asUINT64( _
   BYVAL pAttributes AS IMFAttributes, _
   BYREF guidKey AS GUID, _
   BYREF punHigh32 AS DWORD, _
   BYREF punLow32 AS DWORD) AS LONG

   LOCAL unPacked AS QUAD
   LOCAL hr AS LONG
   hr = pAttributes.GetUINT64(guidKey, unPacked)
   IF FAILED(hr) THEN
      FUNCTION = hr
      EXIT FUNCTION
   END IF
   Unpack2UINT32AsUINT64(unPacked, punHigh32, punLow32)
   FUNCTION = hr

END FUNCTION

'inline
'HRESULT
'MFSetAttribute2UINT32asUINT64(
'    IMFAttributes*  pAttributes,
'    REFGUID         guidKey,
'    UINT32          unHigh32,
'    UINT32          unLow32
'    )
'{
'    return pAttributes->SetUINT64(guidKey, Pack2UINT32AsUINT64(unHigh32, unLow32));
'}

FUNCTION MFSetAttribute2UINT32asUINT64( _
   BYVAL pAttributes AS IMFAttributes, _
   BYREF guidKey AS GUID, _
   BYVAL unHigh32 AS DWORD, _
   BYVAL unLow32 AS DWORD) AS LONG

   FUNCTION = pAttributes.SetUINT64(guidKey, Pack2UINT32AsUINT64(unHigh32, unLow32))

END FUNCTION

'inline
'HRESULT
'MFGetAttributeRatio(
'    IMFAttributes*  pAttributes,
'    REFGUID         guidKey,
'    UINT32*         punNumerator,
'    UINT32*         punDenominator
'    )
'{
'    return MFGetAttribute2UINT32asUINT64(pAttributes, guidKey, punNumerator, punDenominator);
'}

FUNCTION MFGetAttributeRatio( _
   BYVAL pAttributes AS IMFAttributes, _
   BYREF guidKey AS GUID, _
   BYREF punNumerator AS DWORD, _
   BYREF punDenominator AS DWORD) AS LONG

   FUNCTION = MFGetAttribute2UINT32asUINT64(pAttributes, guidKey, punNumerator, punDenominator)

END FUNCTION

'inline
'HRESULT
'MFGetAttributeSize(
'    IMFAttributes*  pAttributes,
'    REFGUID         guidKey,
'    UINT32*         punWidth,
'    UINT32*         punHeight
'    )
'{
'    return MFGetAttribute2UINT32asUINT64(pAttributes, guidKey, punWidth, punHeight);
'}

FUNCTION MFGetAttributeSize( _
   BYVAL pAttributes AS IMFAttributes, _
   BYREF guidKey AS GUID, _
   BYREF punWidth AS DWORD, _
   BYREF punHeight AS DWORD) AS LONG

   FUNCTION = MFGetAttribute2UINT32asUINT64(pAttributes, guidKey, punWidth, punHeight)

END FUNCTION

'inline
'HRESULT
'MFSetAttributeRatio(
'    IMFAttributes*  pAttributes,
'    REFGUID         guidKey,
'    UINT32          unNumerator,
'    UINT32          unDenominator
'    )
'{
'    return MFSetAttribute2UINT32asUINT64(pAttributes, guidKey, unNumerator, unDenominator);
'}

FUNCTION MFSetAttributeRatio( _
   BYVAL pAttributes AS IMFAttributes, _
   BYREF guidKey AS GUID, _
   BYVAL unNumerator AS DWORD, _
   BYVAL unDenominator AS DWORD) AS LONG

   FUNCTION = MFSetAttribute2UINT32asUINT64(pAttributes, guidKey, unNumerator, unDenominator)

END FUNCTION

'inline
'HRESULT
'MFSetAttributeSize(
'    IMFAttributes*  pAttributes,
'    REFGUID         guidKey,
'    UINT32          unWidth,
'    UINT32          unHeight
'    )
'{
'    return MFSetAttribute2UINT32asUINT64(pAttributes, guidKey, unWidth, unHeight);
'}

FUNCTION MFSetAttributeSize( _
   BYVAL pAttributes AS IMFAttributes, _
   BYREF guidKey AS GUID, _
   BYVAL unWidth AS DWORD, _
   BYVAL unHeight AS DWORD) AS LONG

   FUNCTION = MFSetAttribute2UINT32asUINT64(pAttributes, guidKey, unWidth, unHeight)

END FUNCTION

'#endif

'////////////////////////////////////////////////////////////////////////////////
'////////////////////////////////  Memory Management ////////////////////////////
'////////////////////////////////////////////////////////////////////////////////

'//
'// Heap alloc/free
'//
' enum EAllocationType
%eAllocationTypeDynamic  = 0
%eAllocationTypeRT       = 1
%eAllocationTypePageable = 2
%eAllocationTypeIgnore   = 3

DECLARE FUNCTION MFHeapAlloc IMPORT "MFPLAT.DLL" ALIAS "MFHeapAlloc" ( _
   BYVAL nSize AS DWORD _                               ' __in size_t nSize
 , BYVAL dwFlags AS DWORD _                             ' __in ULONG dwFlags
 , BYREF pszFile AS ASCIIZ _                            ' __in char *pszFile
 , BYVAL line AS LONG _                                 ' __in int line
 , BYVAL eat AS LONG _                                  ' __in EAllocationType eat
 ) AS DWORD                                             ' void*

DECLARE SUB MFHeapFree IMPORT "MFPLAT.DLL" ALIAS "MFHeapFree" ()

'///////////////////////////////  Collection         ////////////////////////////
'////////////////////////////////////////////////////////////////////////////////

'//
'// Instantiates the MF-provided IMFCollection implementation
'//

DECLARE FUNCTION MFCreateCollection IMPORT "MFPLAT.DLL" ALIAS "MFCreateCollection" ( _
   BYREF ppIMFCollection AS IMFCollection _             ' __out IMFCollection **ppIMFCollection
 ) AS LONG                                              ' HRESULT


'//////////////////////////       SourceResolver     ////////////////////////////
'////////////////////////////////////////////////////////////////////////////////

$CLSID_MFSourceResolver = GUID$("{90EAB60F-E43A-4188-BCC4-E47FDF04868C}")

'#if (WINVER >= _WIN32_WINNT_WIN7)
'//  Return (a * b + d) / c
'//  Returns _I64_MAX or LLONG_MIN on failure or _I64_MAX if mplat.dll is not available
DECLARE FUNCTION MFllMulDiv IMPORT "MFPLAT.DLL" ALIAS "MFllMulDiv" ( _
   BYVAL a AS QUAD _                                    ' LONGLONG a
 , BYVAL b AS QUAD _                                    ' LONGLONG b
 , BYVAL c AS QUAD _                                    ' LONGLONG c
 , BYVAL d AS QUAD _                                    ' LONGLONG d
 ) AS QUAD                                              ' LONGLONG
'#endif // (WINVER >= _WIN32_WINNT_WIN7)

' ========================================================================================
' Wrapper procedure to delete AM_MEDIA_TYPE structures
' ========================================================================================
SUB DeleteMediaType (BYREF mt AS AM_MEDIA_TYPE)

   IF mt.cbFormat THEN
      CoTaskMemFree BYVAL mt.pbFormat
      mt.cbFormat = 0
      mt.pbFormat = %NULL
   END IF
'   IF mt.pUnk THEN
'      ' // Unecessary because pUnk should not be used, but safest.
'      IUnknown_Release mt.pUnk
'      mt.pUnk = %NULL
'   END IF
   CoTaskMemFree BYVAL VARPTR(mt)

END SUB
' ========================================================================================
