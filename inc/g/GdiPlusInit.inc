' ########################################################################################
' Microsoft Windows
' File: GdiPlusInit.inc
' Contents: GDI+ Startup and Shutdown APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%GDIPLUSINIT_INC = 1

' enum DebugEventLevel
%DebugEventLevelFatal = 0
%DebugEventLevelWarning = 1

'// Callback function that GDI+ can call, on debug builds, for assertions
'// and warnings.

'typedef VOID (WINAPI *DebugEventProc)(DebugEventLevel level, CHAR *message);

'// Notification functions which the user must call appropriately if
'// "SuppressBackgroundThread" (below) is set.

'typedef Status (WINAPI *NotificationHookProc)(OUT ULONG_PTR *token);
'typedef VOID (WINAPI *NotificationUnhookProc)(ULONG_PTR token);

'// Input structure for GdiplusStartup()

'struct GdiplusStartupInput
'{
'	 UINT32 GdiplusVersion;				 // Must be 1
'	 DebugEventProc DebugEventCallback; // Ignored on free builds
'	 BOOL SuppressBackgroundThread;	  // FALSE unless you're prepared to call
'													// the hook/unhook functions properly
'	 BOOL SuppressExternalCodecs;		 // FALSE unless you want GDI+ only to use
'													// its internal image codecs.

'	 GdiplusStartupInput(
'		  DebugEventProc debugEventCallback = NULL,
'		  BOOL suppressBackgroundThread = FALSE,
'		  BOOL suppressExternalCodecs = FALSE)
'	 {
'		  GdiplusVersion = 1;
'		  DebugEventCallback = debugEventCallback;
'		  SuppressBackgroundThread = suppressBackgroundThread;
'		  SuppressExternalCodecs = suppressExternalCodecs;
'	 }
'};

' // Size = 16 bytes
TYPE GdiplusStartupInput DWORD
   GdiplusVersion           AS DWORD
   DebugEventCallback       AS DWORD
   SuppressBackgroundThread AS LONG
   SuppressExternalCodecs   AS LONG
END TYPE

#IF (%GDIPVER >= &H0110)
'struct GdiplusStartupInputEx : GdiplusStartupInput
'{
'    INT StartupParameters;  // Do we not set the FPU rounding mode

'    GdiplusStartupInputEx(
'        INT startupParameters = 0,
'        DebugEventProc debugEventCallback = NULL,
'        BOOL suppressBackgroundThread = FALSE,
'        BOOL suppressExternalCodecs = FALSE)
'    {
'        GdiplusVersion = 2;
'        DebugEventCallback = debugEventCallback;
'        SuppressBackgroundThread = suppressBackgroundThread;
'        SuppressExternalCodecs = suppressExternalCodecs;
'        StartupParameters = startupParameters;
'    }
'};

' // Size = 20 bytes
TYPE GdiplusStartupInputEx DWORD
   GdiplusVersion           AS DWORD
   DebugEventCallback       AS DWORD
   SuppressBackgroundThread AS LONG
   SuppressExternalCodecs   AS LONG
   StartupParameters        AS LONG
END TYPE

' enum GdiplusStartupParams
%GdiplusStartupDefault          = 0
%GdiplusStartupNoSetRound       = 1
%GdiplusStartupSetPSValue       = 2
%GdiplusStartupTransparencyMask = &HFF000000

#ENDIF   ' #IF (%GDIPVER >= &H0110)

'// Output structure for GdiplusStartup()

'struct GdiplusStartupOutput
'{
'	 // The following 2 fields are NULL if SuppressBackgroundThread is FALSE.
'	 // Otherwise, they are functions which must be called appropriately to
'	 // replace the background thread.
'	 //
'	 // These should be called on the application's main message loop - i.e.
'	 // a message loop which is active for the lifetime of GDI+.
'	 // "NotificationHook" should be called before starting the loop,
'	 // and "NotificationUnhook" should be called after the loop ends.

'	 NotificationHookProc NotificationHook;
'	 NotificationUnhookProc NotificationUnhook;
'};

' // Size = 8 bytes
TYPE GdiplusStartupOutput DWORD
   NotificationHook   AS DWORD
   NotificationUnhook AS DWORD
END TYPE

'// GDI+ initialization. Must not be called from DllMain - can cause deadlock.
'//
'// Must be called before GDI+ API's or constructors are used.
'//
'// token  - may not be NULL - accepts a token to be passed in the corresponding
'//			 GdiplusShutdown call.
'// input  - may not be NULL
'// output - may be NULL only if input->SuppressBackgroundThread is FALSE.

'extern "C" Status WINAPI GdiplusStartup(
'	 OUT ULONG_PTR *token,
'	 const GdiplusStartupInput *input,
'	 OUT GdiplusStartupOutput *output);

DECLARE FUNCTION GdiplusStartup IMPORT "GDIPLUS.DLL" ALIAS "GdiplusStartup" ( _
   BYREF token AS DWORD _                               ' __out token ULONG_PTR
 , BYREF input AS GdiplusStartupInput _                 ' __in  input GdiplusStartupInput <record>
 , BYREF output AS GdiplusStartupOutput _               ' __out output GdiplusStartupOutput <record>
 ) AS LONG                                              ' GpStatus

'// GDI+ termination. Must be called before GDI+ is unloaded.
'// Must not be called from DllMain - can cause deadlock.
'//
'// GDI+ API's may not be called after GdiplusShutdown. Pay careful attention
'// to GDI+ object destructors.

'extern "C" VOID WINAPI GdiplusShutdown(ULONG_PTR token);

DECLARE SUB GdiplusShutdown IMPORT "GDIPLUS.DLL" ALIAS "GdiplusShutdown" ( _
   BYVAL token AS DWORD _                               ' __in token ULONG_PTR
 )                                                      ' void
