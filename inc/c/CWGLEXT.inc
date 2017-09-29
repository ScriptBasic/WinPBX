' ########################################################################################
' Microsoft Windows
' File: CWGLEXT.INC
' Contents: Wrapper class for OpenGL windowing system interface
' Copyright (c) 2012 José Roca
' Portions Copyright (c) The Khronos Group Inc.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CWGLEXT_INC = 1

#INCLUDE ONCE "WGLEXT.INC"

' // Note: &H8007007F& is the HRESULT equivalent to the system error code ERROR_PROC_NOT_FOUND:
' // The specified procedure could not be found. You can get a localized string message
' // calling OBJRESULT$.

CLASS CWGLEXT

   INTERFACE IWGLEXT : INHERIT IAutomation

   ' =====================================================================================
   ' HANDLE wglCreateBufferRegionARB (HDC hDC, int iLayerPlane, UINT uType);
   ' =====================================================================================
   METHOD wglCreateBufferRegionARB (BYVAL hdc AS DWORD, BYVAL iLayerPlane AS LONG, BYVAL uType AS DWORD) AS DWORD
      LOCAL dwRes AS DWORD
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglCreateBufferRegionARB")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglCreateBufferRegionARB(hdc, iLayerPlane, uType) TO dwRes
      METHOD = dwRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' VOID wglDeleteBufferRegionARB (HANDLE hRegion);
   ' =====================================================================================
   METHOD wglDeleteBufferRegionARB (BYVAL hRegion AS DWORD)
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglDeleteBufferRegionARB")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglDeleteBufferRegionARB(hRegion)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglSaveBufferRegionARB (HANDLE hRegion, int x, int y, int width, int height);
   ' =====================================================================================
   METHOD wglSaveBufferRegionARB (BYVAL x AS LONG, BYVAL y AS LONG, BYVAL iWidth AS LONG, BYVAL iHeight AS LONG) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglSaveBufferRegionARB")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglSaveBufferRegionARB(x, y, iWidth, iHeight) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglRestoreBufferRegionARB (HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc);
   ' =====================================================================================
   METHOD wglRestoreBufferRegionARB (BYVAL x AS LONG, BYVAL y AS LONG, BYVAL iWidth AS LONG, BYVAL iHeight AS LONG, BYVAL xSrc AS LONG, BYVAL ySrc AS LONG) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglRestoreBufferRegionARB")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglRestoreBufferRegionARB(x, y, iWidth, iHeight, xSrc, ySrc) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' const char * wglGetExtensionsStringARB (HDC hdc);
   ' =====================================================================================
   METHOD wglGetExtensionsStringARB (BYVAL hdc AS DWORD) AS STRING
      LOCAL pRes AS ASCIIZ PTR
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetExtensionsStringARB")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetExtensionsStringARB(hdc) TO pRes
      IF pRes THEN METHOD = @pRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglGetPixelFormatAttribivARB (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, int *piValues);
   ' =====================================================================================
   METHOD wglGetPixelFormatAttribivARB (BYVAL hdc AS DWORD, BYVAL iPixelFormat AS LONG, BYVAL iLayerPlane AS LONG, BYVAL nAttributes AS LONG, BYREF piAttributes AS LONG, BYREF piValues AS LONG) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetPixelFormatAttribivARB")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetPixelFormatAttribivARB(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglGetPixelFormatAttribfvARB (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, FLOAT *pfValues);
   ' =====================================================================================
   METHOD wglGetPixelFormatAttribfvARB (BYVAL hdc AS DWORD, BYVAL iPixelFormat AS LONG, BYVAL iLayerPlane AS LONG, BYVAL nAttributes AS LONG, BYREF piAttributes AS LONG, BYREF pfValues AS SINGLE) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetPixelFormatAttribfvARB")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetPixelFormatAttribfvARB(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglChoosePixelFormatARB (HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
   ' =====================================================================================
   METHOD wglChoosePixelFormatARB (BYVAL hdc AS DWORD, BYREF piAttribIList AS LONG, BYREF pfAttribFList AS SINGLE, BYVAL nMaxFormats AS DWORD, BYREF piFormats AS LONG, BYREF nNumFormats AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglChoosePixelFormatARB")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglChoosePixelFormatARB(hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglMakeContextCurrentARB (HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
   ' =====================================================================================
   METHOD wglMakeContextCurrentARB (BYVAL hDrawDC AS DWORD, BYVAL hReadDC AS DWORD, BYVAL hglrc AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglMakeContextCurrentARB")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglMakeContextCurrentARB(hDrawDC, hReadDC, hglrc) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' HDC wglGetCurrentReadDCARB (void);
   ' =====================================================================================
   METHOD wglGetCurrentReadDCARB () AS DWORD
      LOCAL dwRes AS DWORD
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetCurrentReadDCARB")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetCurrentReadDCARB() TO dwRes
      METHOD = dwRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' HPBUFFERARB wglCreatePbufferARB (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
   ' =====================================================================================
   METHOD wglCreatePbufferARB (BYVAL hdc AS DWORD, BYVAL iPixelFormat AS LONG, BYVAL iWidth AS LONG, BYVAL iHeight AS LONG, BYREF piAttribList AS LONG) AS DWORD
      LOCAL dwRes AS DWORD
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglCreatePbufferARB")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglCreatePbufferARB(hdc, iPixelFormat, iWidth, iHeight, piAttribList) TO dwRes
      METHOD = dwRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' HDC wglGetPbufferDCARB (HPBUFFERARB hPbuffer);
   ' =====================================================================================
   METHOD wglGetPbufferDCARB (BYVAL hPbuffer AS DWORD) AS DWORD
      LOCAL dwRes AS DWORD
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetPbufferDCARB")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetPbufferDCARB(hPbuffer) TO dwRes
      METHOD = dwRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' int wglReleasePbufferDCARB (HPBUFFERARB hPbuffer, HDC hDC);
   ' =====================================================================================
   METHOD wglReleasePbufferDCARB (BYVAL hPbuffer AS DWORD, BYVAL hdc AS DWORD) AS LONG
      LOCAL lRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglReleasePbufferDCARB")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglReleasePbufferDCARB(hPbuffer, hdc) TO lRes
      METHOD = lRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglDestroyPbufferARB (HPBUFFERARB hPbuffer);
   ' =====================================================================================
   METHOD wglDestroyPbufferARB (BYVAL hPbuffer AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglDestroyPbufferARB")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglDestroyPbufferARB(hPbuffer) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglQueryPbufferARB (HPBUFFERARB hPbuffer, int iAttribute, int *piValue);
   ' =====================================================================================
   METHOD wglQueryPbufferARB (BYVAL hPbuffer AS DWORD, BYVAL iAttribute AS LONG, BYREF piValue AS LONG) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglQueryPbufferARB")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglQueryPbufferARB(hPbuffer, iAttribute, piValue) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglBindTexImageARB (HPBUFFERARB hPbuffer, int iBuffer);
   ' =====================================================================================
   METHOD wglBindTexImageARB (BYVAL hPbuffer AS DWORD, BYVAL iBuffer AS LONG) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglBindTexImageARB")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglBindTexImageARB(hPbuffer, iBuffer) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglReleaseTexImageARB (HPBUFFERARB hPbuffer, int iBuffer);
   ' =====================================================================================
   METHOD wglReleaseTexImageARB (BYVAL hPbuffer AS DWORD, BYVAL iBuffer AS LONG) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglReleaseTexImageARB")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglReleaseTexImageARB(hPbuffer, iBuffer) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglSetPbufferAttribARB (HPBUFFERARB hPbuffer, const int *piAttribList);
   ' =====================================================================================
   METHOD wglSetPbufferAttribARB (BYVAL hPbuffer AS DWORD, BYREF piAttribList AS LONG) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglSetPbufferAttribARB")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglSetPbufferAttribARB(hPbuffer, piAttribList) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' HGLRC wglCreateContextAttribsARB (HDC hDC, HGLRC hShareContext, const int *attribList);
   ' =====================================================================================
   METHOD wglCreateContextAttribsARB (BYVAL hdc AS DWORD, BYVAL hShareContext AS DWORD, BYREF attribList AS LONG) AS DWORD
      LOCAL dwRes AS DWORD
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglCreateContextAttribsARB")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglCreateContextAttribsARB(hdc, hShareContext, attribList) TO dwRes
      METHOD = dwRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' GLboolean wglCreateDisplayColorTableEXT (GLushort id);
   ' =====================================================================================
   METHOD wglCreateDisplayColorTableEXT (BYVAL id AS WORD) AS BYTE
      LOCAL bRes AS BYTE
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglCreateDisplayColorTableEXT")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglCreateDisplayColorTableEXT(id) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' GLboolean wglLoadDisplayColorTableEXT (const GLushort *table, GLuint length);
   ' =====================================================================================
   METHOD wglLoadDisplayColorTableEXT (BYREF table AS WORD, BYVAL length AS DWORD) AS BYTE
      LOCAL bRes AS BYTE
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglLoadDisplayColorTableEXT")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglLoadDisplayColorTableEXT(table, length) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' GLboolean wglBindDisplayColorTableEXT (GLushort id);
   ' =====================================================================================
   METHOD wglBindDisplayColorTableEXT (BYVAL id AS WORD) AS BYTE
      LOCAL bRes AS BYTE
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglBindDisplayColorTableEXT")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglBindDisplayColorTableEXT(id) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' VOID wglDestroyDisplayColorTableEXT (GLushort id);
   ' =====================================================================================
   METHOD wglDestroyDisplayColorTableEXT (BYVAL id AS WORD)
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglDestroyDisplayColorTableEXT")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglDestroyDisplayColorTableEXT(id)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' const char * wglGetExtensionsStringEXT (void);
   ' =====================================================================================
   METHOD wglGetExtensionsStringEXT () AS STRING
      LOCAL pRes AS ASCIIZ PTR
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetExtensionsStringEXT")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetExtensionsStringEXT() TO pRes
      IF pRes THEN METHOD = @pRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglMakeContextCurrentEXT (HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
   ' =====================================================================================
   METHOD wglMakeContextCurrentEXT (BYVAL hDrawDC AS DWORD, BYVAL hReadDC AS DWORD, BYVAL hglrc AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglMakeContextCurrentEXT")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglMakeContextCurrentEXT(hDrawDC, hReadDC, hglrc) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' HDC wglGetCurrentReadDCEXT (void);
   ' =====================================================================================
   METHOD wglGetCurrentReadDCEXT () AS DWORD
      LOCAL dwRes AS DWORD
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetCurrentReadDCEXT")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetCurrentReadDCEXT() TO dwRes
      METHOD = dwRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' HPBUFFEREXT wglCreatePbufferEXT (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
   ' =====================================================================================
   METHOD wglCreatePbufferEXT (BYVAL hdc AS DWORD, BYVAL iPixelFormat AS LONG, BYVAL iWidth AS LONG, BYVAL iHeight AS LONG, BYREF piAttribList AS LONG) AS DWORD
      LOCAL dwRes AS DWORD
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglCreatePbufferEXT")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglCreatePbufferEXT(hdc, iPixelFormat, iWidth, iHeight, piAttribList) TO dwRes
      METHOD = dwRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' HDC wglGetPbufferDCEXT (HPBUFFEREXT hPbuffer);
   ' =====================================================================================
   METHOD wglGetPbufferDCEXT (BYVAL hPbuffer AS DWORD) AS DWORD
      LOCAL dwRes AS DWORD
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetPbufferDCEXT")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetPbufferDCEXT(hPbuffer) TO dwRes
      METHOD = dwRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' int wglReleasePbufferDCEXT (HPBUFFEREXT hPbuffer, HDC hDC);
   ' =====================================================================================
   METHOD wglReleasePbufferDCEXT (BYVAL hPbuffer AS DWORD, BYVAL hdc AS DWORD) AS LONG
      LOCAL lRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglReleasePbufferDCEXT")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglReleasePbufferDCEXT(hPbuffer, hdc) TO lRes
      METHOD = lRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglDestroyPbufferEXT (HPBUFFEREXT hPbuffer);
   ' =====================================================================================
   METHOD wglDestroyPbufferEXT (BYVAL hPbuffer AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglDestroyPbufferEXT")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglDestroyPbufferEXT(hPbuffer) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglQueryPbufferEXT (HPBUFFEREXT hPbuffer, int iAttribute, int *piValue);
   ' =====================================================================================
   METHOD wglQueryPbufferEXT (BYVAL hPbuffer AS DWORD, BYVAL iAttribute AS LONG, BYREF piValue AS LONG) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglQueryPbufferEXT")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglQueryPbufferEXT(hPbuffer, iAttribute, piValue) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglGetPixelFormatAttribivEXT (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, int *piValues);
   ' =====================================================================================
   METHOD wglGetPixelFormatAttribivEXT (BYVAL hdc AS DWORD, BYVAL iPixelFormat AS LONG, BYVAL iLayerPlane AS LONG, BYVAL nAttributes AS DWORD, BYREF piAttributes AS LONG, BYREF piValues AS LONG) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetPixelFormatAttribivEXT")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetPixelFormatAttribivEXT(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglGetPixelFormatAttribfvEXT (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, FLOAT *pfValues);
   ' =====================================================================================
   METHOD wglGetPixelFormatAttribfvEXT (BYVAL hdc AS DWORD, BYVAL iPixelFormat AS LONG, BYVAL iLayerPlane AS LONG, BYVAL nAttributes AS DWORD, BYREF piAttributes AS LONG,  BYREF pfValues AS SINGLE) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetPixelFormatAttribfvEXT")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetPixelFormatAttribfvEXT(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglChoosePixelFormatEXT (HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
   ' =====================================================================================
   METHOD wglChoosePixelFormatEXT (BYVAL hdc AS DWORD, BYREF piAttribIList AS LONG, BYREF pfAttribFList AS SINGLE, BYVAL nMaxFormats AS DWORD, BYREF piFormats AS LONG,  BYREF nNumFormats AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglChoosePixelFormatEXT")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglChoosePixelFormatEXT(hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglSwapIntervalEXT (int interval);
   ' =====================================================================================
   METHOD wglSwapIntervalEXT (BYVAL nInterval AS LONG) AS LONG
      LOCAL lRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglSwapIntervalEXT")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglSwapIntervalEXT(nInterval) TO lRes
      METHOD = lRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' int wglGetSwapIntervalEXT (void);
   ' =====================================================================================
   METHOD wglGetSwapIntervalEXT () AS LONG
      LOCAL lRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetSwapIntervalEXT")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetSwapIntervalEXT() TO lRes
      METHOD = lRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' void* wglAllocateMemoryNV (GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority);
   ' =====================================================================================
   METHOD wglAllocateMemoryNV (BYVAL iSize AS LONG, BYVAL readfreq AS SINGLE, BYVAL writefreq AS SINGLE, BYVAL fpriority AS SINGLE) AS DWORD
      LOCAL pRes AS DWORD
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglAllocateMemoryNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglAllocateMemoryNV(iSize, readfreq, writefreq, fpriority) TO pRes
      METHOD = pRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' void wglFreeMemoryNV (void *pointer);
   ' =====================================================================================
   METHOD wglFreeMemoryNV (BYVAL dwPointer AS DWORD)
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglFreeMemoryNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglFreeMemoryNV(dwPointer)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglGetSyncValuesOML (HDC hdc, INT64 *ust, INT64 *msc, INT64 *sbc);
   ' =====================================================================================
   METHOD wglGetSyncValuesOML (BYVAL hdc AS DWORD, BYREF ust AS QUAD, BYREF msc AS QUAD, BYREF sbc AS QUAD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetSyncValuesOML")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetSyncValuesOML(hdc, ust, msc, sbc) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglGetMscRateOML (HDC hdc, INT32 *numerator, INT32 *denominator);
   ' =====================================================================================
   METHOD wglGetMscRateOML (BYVAL hdc AS DWORD, BYREF numerator AS LONG, BYREF denominator AS LONG) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetMscRateOML")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetMscRateOML(hdc, numerator, denominator) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' INT64 wglSwapBuffersMscOML (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder);
   ' =====================================================================================
   METHOD wglSwapBuffersMscOML (BYVAL hdc AS DWORD, BYVAL target_msc AS QUAD, BYVAL divisor AS QUAD, BYVAL remainder AS QUAD) AS QUAD
      LOCAL qRes AS QUAD
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglSwapBuffersMscOML")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglSwapBuffersMscOML(hdc, target_msc, divisor, remainder) TO qRes
      METHOD = qRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' INT64 wglSwapLayerBuffersMscOML (HDC hdc, int fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder);
   ' =====================================================================================
   METHOD wglSwapLayerBuffersMscOML (BYVAL hdc AS DWORD, BYVAL fuPlanes AS LONG, BYVAL target_msc AS QUAD, BYVAL divisor AS QUAD, BYVAL remainder AS QUAD) AS QUAD
      LOCAL qRes AS QUAD
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglSwapLayerBuffersMscOML")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglSwapLayerBuffersMscOML(hdc, fuPlanes, target_msc, divisor, remainder) TO qRes
      METHOD = qRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglWaitForMscOML (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64 *ust, INT64 *msc, INT64 *sbc);
   ' =====================================================================================
   METHOD wglWaitForMscOML (BYVAL hdc AS DWORD, BYVAL target_msc AS QUAD, BYVAL divisor AS QUAD, BYVAL remainder AS QUAD, BYREF ust AS QUAD, BYREF msc AS QUAD, BYREF sbc AS QUAD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglWaitForMscOML")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglWaitForMscOML(hdc, target_msc, divisor, remainder, ust, msc, sbc) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglWaitForSbcOML (HDC hdc, INT64 target_sbc, INT64 *ust, INT64 *msc, INT64 *sbc);
   ' =====================================================================================
   METHOD wglWaitForSbcOML (BYVAL hdc AS DWORD, BYVAL target_msc AS QUAD, BYREF ust AS QUAD, BYREF msc AS QUAD, BYREF sbc AS QUAD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglWaitForSbcOML")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglWaitForSbcOML(hdc, target_msc, ust, msc, sbc) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglGetDigitalVideoParametersI3D (HDC hDC, int iAttribute, int *piValue);
   ' =====================================================================================
   METHOD wglGetDigitalVideoParametersI3D (BYVAL hdc AS DWORD, BYVAL iAttribute AS LONG, BYREF piValue AS LONG) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetDigitalVideoParametersI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetDigitalVideoParametersI3D(hdc, iAttribute, piValue) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglSetDigitalVideoParametersI3D (HDC hDC, int iAttribute, const int *piValue);
   ' =====================================================================================
   METHOD wglSetDigitalVideoParametersI3D (BYVAL hdc AS DWORD, BYVAL iAttribute AS LONG, BYREF piValue AS LONG) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglSetDigitalVideoParametersI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglSetDigitalVideoParametersI3D(hdc, iAttribute, piValue) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglGetGammaTableParametersI3D (HDC hDC, int iAttribute, int *piValue);
   ' =====================================================================================
   METHOD wglGetGammaTableParametersI3D (BYVAL hdc AS DWORD, BYVAL iAttribute AS LONG, BYREF piValue AS LONG) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetGammaTableParametersI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetGammaTableParametersI3D(hdc, iAttribute, piValue) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglSetGammaTableParametersI3D (HDC hDC, int iAttribute, const int *piValue);
   ' =====================================================================================
   METHOD wglSetGammaTableParametersI3D (BYVAL hdc AS DWORD, BYVAL iAttribute AS LONG, BYREF piValue AS LONG) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglSetGammaTableParametersI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglSetGammaTableParametersI3D(hdc, iAttribute, piValue) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglGetGammaTableI3D (HDC hDC, int iEntries, USHORT *puRed, USHORT *puGreen, USHORT *puBlue);
   ' =====================================================================================
   METHOD wglGetGammaTableI3D (BYVAL hdc AS DWORD, BYVAL iEntries AS LONG, BYREF puRed AS WORD, BYREF puGreen AS WORD, BYREF puBlue AS WORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetGammaTableI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetGammaTableI3D(hdc, iEntries, puRed, puGreen, puBlue) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglSetGammaTableI3D (HDC hDC, int iEntries, const USHORT *puRed, const USHORT *puGreen, const USHORT *puBlue);
   ' =====================================================================================
   METHOD wglSetGammaTableI3D (BYVAL hdc AS DWORD, BYVAL iEntries AS LONG, BYREF puRed AS WORD, BYREF puGreen AS WORD, BYREF puBlue AS WORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglSetGammaTableI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglSetGammaTableI3D(hdc, iEntries, puRed, puGreen, puBlue) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglEnableGenlockI3D (HDC hDC);
   ' =====================================================================================
   METHOD wglEnableGenlockI3D (BYVAL hdc AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglEnableGenlockI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglEnableGenlockI3D(hdc) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglDisableGenlockI3D (HDC hDC);
   ' =====================================================================================
   METHOD wglDisableGenlockI3D (BYVAL hdc AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglDisableGenlockI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglDisableGenlockI3D(hdc) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglIsEnabledGenlockI3D (HDC hDC, BOOL *pFlag);
   ' =====================================================================================
   METHOD wglIsEnabledGenlockI3D (BYVAL hdc AS DWORD, BYREF pFlag AS LONG) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglIsEnabledGenlockI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglIsEnabledGenlockI3D(hdc, pFlag) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglGenlockSourceI3D (HDC hDC, UINT uSource);
   ' =====================================================================================
   METHOD wglGenlockSourceI3D (BYVAL hdc AS DWORD, BYVAL uSource AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGenlockSourceI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGenlockSourceI3D(hdc, uSource) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglGetGenlockSourceI3D (HDC hDC, UINT *uSource);
   ' =====================================================================================
   METHOD wglGetGenlockSourceI3D (BYVAL hdc AS DWORD, BYREF uSource AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetGenlockSourceI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetGenlockSourceI3D(hdc, uSource) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglGenlockSourceEdgeI3D (HDC hDC, UINT uEdge);
   ' =====================================================================================
   METHOD wglGenlockSourceEdgeI3D (BYVAL hdc AS DWORD, BYVAL uEdge AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGenlockSourceEdgeI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGenlockSourceEdgeI3D(hdc, uEdge) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglGetGenlockSourceEdgeI3D (HDC hDC, UINT *uEdge);
   ' =====================================================================================
   METHOD wglGetGenlockSourceEdgeI3D (BYVAL hdc AS DWORD, BYREF uEdge AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetGenlockSourceEdgeI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetGenlockSourceI3D(hdc, uEdge) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglGenlockSampleRateI3D (HDC hDC, UINT uRate);
   ' =====================================================================================
   METHOD wglGenlockSampleRateI3D (BYVAL hdc AS DWORD, BYVAL uRate AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGenlockSampleRateI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGenlockSampleRateI3D(hdc, uRate) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglGetGenlockSampleRateI3D (HDC hDC, UINT *uRate);
   ' =====================================================================================
   METHOD wglGetGenlockSampleRateI3D (BYVAL hdc AS DWORD, BYREF uRate AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetGenlockSampleRateI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetGenlockSampleRateI3D(hdc, uRate) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglGenlockSourceDelayI3D (HDC hDC, UINT uDelay);
   ' =====================================================================================
   METHOD wglGenlockSourceDelayI3D (BYVAL hdc AS DWORD, BYVAL uDelay AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGenlockSourceDelayI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGenlockSourceDelayI3D(hdc, uDelay) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglGetGenlockSourceDelayI3D (HDC hDC, UINT *uDelay);
   ' =====================================================================================
   METHOD wglGetGenlockSourceDelayI3D (BYVAL hdc AS DWORD, BYREF uDelay AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetGenlockSourceDelayI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetGenlockSourceDelayI3D(hdc, uDelay) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglQueryGenlockMaxSourceDelayI3D (HDC hDC, UINT *uMaxLineDelay, UINT *uMaxPixelDelay);
   ' =====================================================================================
   METHOD wglQueryGenlockMaxSourceDelayI3D (BYVAL hdc AS DWORD, BYREF uMaxLineDelay AS DWORD, BYREF uMaxPixelDelay AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglQueryGenlockMaxSourceDelayI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglQueryGenlockMaxSourceDelayI3D(hdc, uMaxLineDelay, uMaxPixelDelay) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' LPVOID wglCreateImageBufferI3D (HDC hDC, DWORD dwSize, UINT uFlags);
   ' =====================================================================================
   METHOD wglCreateImageBufferI3D (BYVAL hdc AS DWORD, BYVAL dwSize AS DWORD, BYVAL uFlags AS DWORD) AS DWORD
      LOCAL pRes AS DWORD
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglCreateImageBufferI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglCreateImageBufferI3D(hdc, dwSize, uFlags) TO pRes
      METHOD = pRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglDestroyImageBufferI3D (HDC hDC, LPVOID pAddress);
   ' =====================================================================================
   METHOD wglDestroyImageBufferI3D (BYVAL hdc AS DWORD, BYVAL pAddress AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglDestroyImageBufferI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglDestroyImageBufferI3D(hdc, pAddress) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglAssociateImageBufferEventsI3D (HDC hDC, const HANDLE *pEvent, const LPVOID *pAddress, const DWORD *pSize, UINT count);
   ' =====================================================================================
   METHOD wglAssociateImageBufferEventsI3D (BYVAL hdc AS DWORD, BYREF pEvent AS DWORD, BYREF pAddress AS DWORD, BYREF pSize AS DWORD, BYVAL dwCount AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglAssociateImageBufferEventsI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglAssociateImageBufferEventsI3D(hdc, pEvent, pAddress, pSize, dwCount) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglReleaseImageBufferEventsI3D (HDC hDC, const LPVOID *pAddress, UINT count);
   ' =====================================================================================
   METHOD wglReleaseImageBufferEventsI3D (BYVAL hdc AS DWORD, BYREF pAddress AS DWORD, BYVAL dwCount AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglReleaseImageBufferEventsI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglReleaseImageBufferEventsI3D(hdc, pAddress, dwCount) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglEnableFrameLockI3D (void);
   ' =====================================================================================
   METHOD wglEnableFrameLockI3D () AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglEnableFrameLockI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglEnableFrameLockI3D() TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglDisableFrameLockI3D (void);
   ' =====================================================================================
   METHOD wglDisableFrameLockI3D () AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglDisableFrameLockI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglDisableFrameLockI3D() TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglIsEnabledFrameLockI3D (BOOL *pFlag);
   ' =====================================================================================
   METHOD wglIsEnabledFrameLockI3D (BYREF pFlag AS LONG) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglIsEnabledFrameLockI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglIsEnabledFrameLockI3D(pFlag) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglQueryFrameLockMasterI3D (BOOL *pFlag);
   ' =====================================================================================
   METHOD wglQueryFrameLockMasterI3D (BYREF pFlag AS LONG) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglQueryFrameLockMasterI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglQueryFrameLockMasterI3D(pFlag) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglGetFrameUsageI3D (float *pUsage);
   ' =====================================================================================
   METHOD wglGetFrameUsageI3D (BYREF pUsage AS SINGLE) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetFrameUsageI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetFrameUsageI3D(pUsage) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglBeginFrameTrackingI3D (void);
   ' =====================================================================================
   METHOD wglBeginFrameTrackingI3D () AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglBeginFrameTrackingI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglBeginFrameTrackingI3D() TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglEndFrameTrackingI3D (void);
   ' =====================================================================================
   METHOD wglEndFrameTrackingI3D () AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglEndFrameTrackingI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglEndFrameTrackingI3D() TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglQueryFrameTrackingI3D (DWORD *pFrameCount, DWORD *pMissedFrames, float *pLastMissedUsage);
   ' =====================================================================================
   METHOD wglQueryFrameTrackingI3D (BYREF pFrameCount AS DWORD, BYREF pMissedFrames AS DWORD, BYREF pLastMissedUsage AS SINGLE) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglQueryFrameTrackingI3D")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglQueryFrameTrackingI3D(pFrameCount, pMissedFrames, pLastMissedUsage) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL WINAPI wglSetStereoEmitterState3DL (HDC hDC, UINT uState);
   ' =====================================================================================
   METHOD wglSetStereoEmitterState3DL (BYVAL hDC AS DWORD, BYVAL uState AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglSetStereoEmitterState3DL")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglSetStereoEmitterState3DL(hDC, uState) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' int wglEnumerateVideoDevicesNV(HDC hDc, HVIDEOOUTPUTDEVICENV *phDeviceList);
   ' =====================================================================================
   METHOD wglEnumerateVideoDevicesNV (BYVAL hdc AS DWORD, BYREF phDeviceList AS DWORD) AS LONG
      LOCAL lRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglEnumerateVideoDevicesNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglEnumerateVideoDevicesNV(hdc, phDeviceList) TO lRes
      METHOD = lRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglBindVideoDeviceNV(HDC hDc, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice,
   ' const int *piAttribList);
   ' =====================================================================================
   METHOD wglBindVideoDeviceNV (BYVAL hdc AS DWORD, BYVAL uVideoSlot AS DWORD, BYVAL hVideoDevice AS DWORD, BYREF piAttribList AS LONG) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglBindVideoDeviceNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglBindVideoDeviceNV(hdc, uVideoSlot, hVideoDevice, piAttribList) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglQueryCurrentContextNV(int iAttribute, int *piValue);
   ' =====================================================================================
   METHOD wglQueryCurrentContextNV (BYVAL iAttribute AS LONG, BYREF piValue AS LONG) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglQueryCurrentContextNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglQueryCurrentContextNV(iAttribute, piValue) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglGetVideoDeviceNV(HDC hDC, int numDevices, HPVIDEODEV *hVideoDevice);
   ' =====================================================================================
   METHOD wglGetVideoDeviceNV (BYVAL hdc AS DWORD, BYVAL numDevices AS LONG, BYREF hVideoDevice AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetVideoDeviceNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetVideoDeviceNV(hdc, numDevices, hVideoDevice) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglReleaseVideoDeviceNV(HPVIDEODEV hVideoDevice);
   ' =====================================================================================
   METHOD wglReleaseVideoDeviceNV (BYVAL hVideoDevice AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglReleaseVideoDeviceNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglReleaseVideoDeviceNV(hVideoDevice) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglBindVideoImageNV (HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer);
   ' =====================================================================================
   METHOD wglBindVideoImageNV (BYVAL hVideoDevice AS DWORD, BYVAL hPbuffer AS DWORD, BYVAL iVideoBuffer AS LONG) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglBindVideoImageNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglBindVideoImageNV(hVideoDevice, hPbuffer, iVideoBuffer) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglReleaseVideoImageNV (HPBUFFERARB hPbuffer, int iVideoBuffer);
   ' =====================================================================================
   METHOD wglReleaseVideoImageNV (BYVAL hPbuffer AS DWORD, BYVAL iVideoBuffer AS LONG) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglReleaseVideoImageNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglReleaseVideoImageNV(hPbuffer, iVideoBuffer) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglSendPbufferToVideoNV (HPBUFFERARB hPbuffer, int iBufferType,
   ' unsigned long *pulCounterPbuffer, BOOL bBlock);
   ' =====================================================================================
   METHOD wglSendPbufferToVideoNV (BYVAL hPbuffer AS DWORD, BYVAL iBufferType AS LONG, BYREF pulCounterPbuffer AS DWORD, BYVAL bBlock AS LONG) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglSendPbufferToVideoNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglSendPbufferToVideoNV(hPbuffer, iBufferType, pulCounterPbuffer, bBlock) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglGetVideoInfoNV (HPVIDEODEV hpVideoDevice, unsigned long *pulCounterOutputPbuffer,
   ' unsigned long *pulCounterOutputVideo);
   ' =====================================================================================
   METHOD wglGetVideoInfoNV (BYVAL hpVideoDevice AS DWORD, BYREF pulCounterOutputPbuffer AS DWORD, BYREF pulCounterOutputVideo AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetVideoInfoNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetVideoInfoNV(hpVideoDevice, pulCounterOutputPbuffer, pulCounterOutputVideo) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglJoinSwapGroupNV(HDC hDC, GLuint group);
   ' =====================================================================================
   METHOD wglJoinSwapGroupNV (BYVAL hdc AS DWORD, BYVAL dwgroup AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglJoinSwapGroupNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglJoinSwapGroupNV(hdc, dwgroup) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglBindSwapBarrierNV(GLuint group, GLuint barrier);
   ' =====================================================================================
   METHOD wglBindSwapBarrierNV(BYVAL dwgroup AS DWORD, BYVAL dwbarrier AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglBindSwapBarrierNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglBindSwapBarrierNV(dwgroup, dwbarrier) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglQuerySwapGroupNV(HDC hDC, GLuint *group, GLuint *barrier);
   ' =====================================================================================
   METHOD wglQuerySwapGroupNV(BYVAL hdc AS DWORD, BYREF dwgroup AS DWORD, BYREF dwbarrier AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglQuerySwapGroupNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglQuerySwapGroupNV(hdc, dwgroup, dwbarrier) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglQueryMaxSwapGroupsNV(HDC hDC, GLuint *maxGroups, GLuint *maxBarriers);
   ' =====================================================================================
   METHOD wglQueryMaxSwapGroupsNV(BYVAL hdc AS DWORD, BYREF maxGroups AS DWORD, BYREF maxBarriers AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglQueryMaxSwapGroupsNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglQueryMaxSwapGroupsNV(hdc, maxGroups, maxBarriers) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglQueryFrameCountNV(HDC hDC, GLuint *count);
   ' =====================================================================================
   METHOD wglQueryFrameCountNV(BYVAL hdc AS DWORD, BYREF dwcount AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglQueryFrameCountNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglQueryFrameCountNV(hdc, dwcount) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL wglResetFrameCountNV(HDC hDC);
   ' =====================================================================================
   METHOD wglResetFrameCountNV(BYVAL hdc AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglResetFrameCountNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglResetFrameCountNV(hdc) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL WINAPI wglEnumGpusNV (UINT iIndex, HGPUNV *hGpu);
   ' =====================================================================================
   METHOD wglEnumGpusNV(BYVAL iIndex AS DWORD, BYREF hGpu AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglEnumGpusNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglEnumGpusNV(iIndex, hGpu) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL WINAPI wglEnumGpuDevicesNV (HGPUNV hGpu, UINT iIndex, PGPU_DEVICE pGpuDevice);
   ' =====================================================================================
   METHOD wglEnumGpuDevicesNV(BYVAL hGpu AS DWORD, BYVAL iIndex AS DWORD, BYREF pGpuDevice AS GPU_DEVICE) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglEnumGpuDevicesNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglEnumGpuDevicesNV(hGpu, iIndex, pGpuDevice) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' HDC WINAPI wglCreateAffinityDCNV (const HGPUNV *pGpuList);
   ' =====================================================================================
   METHOD wglCreateAffinityDCNV(BYREF pGpuList AS DWORD) AS DWORD
      LOCAL dwRes AS DWORD
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglCreateAffinityDCNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglCreateAffinityDCNV(pGpuList) TO dwRes
      METHOD = dwRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL WINAPI wglEnumGpusFromAffinityDCNV (HDC hAffinityDC, UINT iIndex, HGPUNV *hGpu);
   ' =====================================================================================
   METHOD wglEnumGpusFromAffinityDCNV(BYVAL hAffinityDC AS DWORD, BYVAL iIndex AS DWORD, BYREF hGpu AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglEnumGpusFromAffinityDCNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglEnumGpusFromAffinityDCNV(hAffinityDC, iIndex, hGpu) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL WINAPI wglDeleteDCNV (HDC hAffinityDC);
   ' =====================================================================================
   METHOD wglDeleteDCNV(BYVAL hAffinityDC AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglDeleteDCNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglDeleteDCNV(hAffinityDC) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' UINT WINAPI wglGetGPUIDsAMD (UINT maxCount, UINT *ids);
   ' =====================================================================================
   METHOD wglGetGPUIDsAMD(BYVAL maxCount AS DWORD, BYREF ids AS DWORD) AS DWORD
      LOCAL dwRes AS DWORD
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetGPUIDsAMD")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetGPUIDsAMD(maxCount, ids) TO dwRes
      METHOD = dwRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' INT WINAPI wglGetGPUInfoAMD (UINT id, int property, GLenum dataType, UINT size, void *data);
   ' =====================================================================================
   METHOD wglGetGPUInfoAMD(BYVAL dwid AS DWORD, BYVAL lproperty AS LONG, BYVAL dataType AS DWORD, BYVAL dwsize AS DWORD, BYVAL pdata AS DWORD) AS LONG
      LOCAL lRes AS DWORD
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetGPUInfoAMD")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetGPUInfoAMD(dwid, lproperty, dataType, dwsize, pdata) TO lRes
      METHOD = lRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' UINT WINAPI wglGetContextGPUIDAMD (HGLRC hglrc);
   ' =====================================================================================
   METHOD wglGetContextGPUIDAMD(BYVAL hglrc AS DWORD) AS DWORD
      LOCAL dwRes AS DWORD
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetContextGPUIDAMD")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetContextGPUIDAMD(hglrc) TO dwRes
      METHOD = dwRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' HGLRC WINAPI wglCreateAssociatedContextAMD (UINT id);
   ' =====================================================================================
   METHOD wglCreateAssociatedContextAMD(BYVAL dwid AS DWORD) AS DWORD
      LOCAL dwRes AS DWORD
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglCreateAssociatedContextAMD")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglCreateAssociatedContextAMD(dwid) TO dwRes
      METHOD = dwRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' HGLRC WINAPI wglCreateAssociatedContextAttribsAMD (UINT id, HGLRC hShareContext, const int *attribList);
   ' =====================================================================================
   METHOD wglCreateAssociatedContextAttribsAMD(BYVAL dwid AS DWORD, BYVAL hShareContext AS DWORD, BYREF attribList AS LONG) AS DWORD
      LOCAL dwRes AS DWORD
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglCreateAssociatedContextAttribsAMD")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglCreateAssociatedContextAttribsAMD(dwid, hShareContext, attribList) TO dwRes
      METHOD = dwRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL WINAPI wglDeleteAssociatedContextAMD (HGLRC hglrc);
   ' =====================================================================================
   METHOD wglDeleteAssociatedContextAMD(BYVAL hglrc AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglDeleteAssociatedContextAMD")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglDeleteAssociatedContextAMD(hglrc) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL WINAPI wglMakeAssociatedContextCurrentAMD (HGLRC hglrc);
   ' =====================================================================================
   METHOD wglMakeAssociatedContextCurrentAMD(BYVAL hglrc AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglMakeAssociatedContextCurrentAMD")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglMakeAssociatedContextCurrentAMD(hglrc) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' HGLRC WINAPI wglGetCurrentAssociatedContextAMD (void);
   ' =====================================================================================
   METHOD wglGetCurrentAssociatedContextAMD() AS DWORD
      LOCAL dwRes AS DWORD
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglGetCurrentAssociatedContextAMD")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglGetCurrentAssociatedContextAMD() TO dwRes
      METHOD = dwRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' VOID WINAPI wglBlitContextFramebufferAMD (HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1,
   ' GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
   ' =====================================================================================
   METHOD wglBlitContextFramebufferAMD (BYVAL dstCtx AS DWORD, BYVAL srcX0 AS LONG, BYVAL srcY0 AS LONG, BYVAL srcX1 AS LONG, BYVAL srcY1 AS LONG, _
      BYVAL dstX0 AS LONG, BYVAL dstY0 AS LONG, BYVAL dstX1 AS LONG, BYVAL dstY1 AS LONG, BYVAL mask AS DWORD, BYVAL filter AS DWORD)
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglBlitContextFramebufferAMD")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglBlitContextFramebufferAMD(dstCtx, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL WINAPI wglBindVideoCaptureDeviceNV (UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice);
   ' =====================================================================================
   METHOD wglBindVideoCaptureDeviceNV(BYVAL uVideoSlot AS DWORD, BYVAL hDevice AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglBindVideoCaptureDeviceNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglBindVideoCaptureDeviceNV(uVideoSlot, hDevice) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' UINT WINAPI wglEnumerateVideoCaptureDevicesNV (HDC hDc, HVIDEOINPUTDEVICENV *phDeviceList);
   ' =====================================================================================
   METHOD wglEnumerateVideoCaptureDevicesNV(BYVAL hDc AS DWORD, BYREF phDeviceList AS DWORD) AS DWORD
      LOCAL dwRes AS DWORD
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglEnumerateVideoCaptureDevicesNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglEnumerateVideoCaptureDevicesNV(hDc, phDeviceList) TO dwRes
      METHOD = dwRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL WINAPI wglLockVideoCaptureDeviceNV (HDC hDc, HVIDEOINPUTDEVICENV hDevice);
   ' =====================================================================================
   METHOD wglLockVideoCaptureDeviceNV(BYVAL hDc AS DWORD, BYVAL hDevice AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglLockVideoCaptureDeviceNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglLockVideoCaptureDeviceNV(hDc, hDevice) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL WINAPI wglQueryVideoCaptureDeviceNV (HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int *piValue);
   ' =====================================================================================
   METHOD wglQueryVideoCaptureDeviceNV(BYVAL hDc AS DWORD, BYVAL hDevice AS DWORD, BYVAL iAttribute AS LONG, BYREF piValue AS LONG) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglQueryVideoCaptureDeviceNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglQueryVideoCaptureDeviceNV(hDc, hDevice, iAttribute, piValue) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL WINAPI wglReleaseVideoCaptureDeviceNV (HDC hDc, HVIDEOINPUTDEVICENV hDevice);
   ' =====================================================================================
   METHOD wglReleaseVideoCaptureDeviceNV(BYVAL hDc AS DWORD, BYVAL hDevice AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglReleaseVideoCaptureDeviceNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglReleaseVideoCaptureDeviceNV(hDc, hDevice) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL WINAPI wglCopyImageSubDataNV (HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel,
   ' GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel,
   ' GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
   ' =====================================================================================
   METHOD wglCopyImageSubDataNV(BYVAL hSrcRC AS DWORD, BYVAL srcName AS DWORD, _
      BYVAL srcTarget AS DWORD, BYVAL srcLevel AS LONG, BYVAL srcX AS LONG, BYVAL srcY AS LONG, _
      BYVAL srcZ AS LONG, BYVAL hDstRC AS DWORD, BYVAL dstName AS DWORD, BYVAL dstTarget AS DWORD, _
      BYVAL dstLevel AS LONG, BYVAL dstX AS LONG, BYVAL dstY AS LONG, BYVAL dstZ AS LONG, _
      BYVAL nwidth AS LONG, BYVAL height AS LONG, BYVAL depth AS LONG) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglCopyImageSubDataNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglCopyImageSubDataNV(hSrcRC, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, hDstRC, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, nwidth, height, depth) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BOOL WINAPI wglDXSetResourceShareHandleNV (void *dxObject, HANDLE shareHandle);
   ' =====================================================================================
   METHOD wglDXSetResourceShareHandleNV(BYVAL dxObject AS DWORD, BYVAL shareHandle AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglDXSetResourceShareHandleNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglDXSetResourceShareHandleNV(dxObject, shareHandle) TO bRes
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' ========================================================================================
   ' HANDLE WINAPI wglDXOpenDeviceNV (void *dxDevice);
   ' ========================================================================================
   METHOD wglDXOpenDeviceNV(BYVAL dxDevice AS DWORD) AS DWORD
      LOCAL dwRes AS DWORD
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglDXOpenDeviceNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglDXOpenDeviceNV(dxDevice) TO dwRes
      METHOD = dwRes
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' BOOL WINAPI wglDXCloseDeviceNV (HANDLE hDevice);
   ' ========================================================================================
   METHOD wglDXCloseDeviceNV(BYVAL hDevice AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglDXCloseDeviceNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglDXCloseDeviceNV(hDevice) TO bRes
      METHOD = bRes
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' HANDLE WINAPI wglDXRegisterObjectNV (HANDLE hDevice, void *dxObject, GLuint name, GLenum type, GLenum access);
   ' ========================================================================================
   METHOD wglDXRegisterObjectNV(BYVAL hDevice AS DWORD, BYVAL dxObject AS DWORD, _
      BYVAL dwName AS DWORD, BYVAL dwType AS DWORD, BYVAL dwAccess AS DWORD) AS DWORD
      LOCAL dwRes AS DWORD
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglDXRegisterObjectNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglDXRegisterObjectNV(hDevice, dxObject, dwName, dwType, dwAccess) TO dwRes
      METHOD = dwRes
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' BOOL WINAPI wglDXUnregisterObjectNV (HANDLE hDevice, HANDLE hObject);
   ' ========================================================================================
   METHOD wglDXUnregisterObjectNV(BYVAL hDevice AS DWORD, BYVAL hObject AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglDXUnregisterObjectNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglDXUnregisterObjectNV(hDevice, hObject) TO bRes
      METHOD = bRes
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' BOOL WINAPI wglDXObjectAccessNV (HANDLE hObject, GLenum access);
   ' ========================================================================================
   METHOD wglDXObjectAccessNV(BYVAL hObject AS DWORD, BYVAL dwAccess AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglDXObjectAccessNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglDXObjectAccessNV(hObject, dwAccess) TO bRes
      METHOD = bRes
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' BOOL WINAPI wglDXLockObjectsNV (HANDLE hDevice, GLint count, HANDLE *hObjects);
   ' ========================================================================================
   METHOD wglDXLockObjectsNV(BYVAL hDevice AS DWORD, BYVAL nCount AS LONG, BYREF hObjects AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglDXLockObjectsNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglDXLockObjectsNV(hDevice, nCount, hObjects) TO bRes
      METHOD = bRes
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' BOOL WINAPI wglDXUnlockObjectsNV (HANDLE hDevice, GLint count, HANDLE *hObjects);
   ' ========================================================================================
   METHOD wglDXUnlockObjectsNV(BYVAL hDevice AS DWORD, BYVAL nCount AS LONG, BYREF hObjects AS DWORD) AS LONG
      LOCAL bRes AS LONG
      LOCAL pProc AS DWORD
      pProc = wglGetProcAddress("wglDXUnlockObjectsNV")
      IF pProc = 0 THEN METHOD OBJRESULT = &H8007007F& : EXIT METHOD
      CALL DWORD pProc USING wglDXUnlockObjectsNV(hDevice, nCount, hObjects) TO bRes
      METHOD = bRes
   END METHOD
   ' ========================================================================================

   END INTERFACE

END CLASS
