' ########################################################################################
' Microsoft Windows
' File: GLAux.inc
' Contents: Procedure declarations, constant definitions and macros for the OpenGL Auxiliary Library.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%GLAUX_INC = 1

'/*
' * (c) Copyright 1993, Silicon Graphics, Inc.
' * ALL RIGHTS RESERVED
' * Permission to use, copy, modify, and distribute this software for
' * any purpose and without fee is hereby granted, provided that the above
' * copyright notice appear in all copies and that both the copyright notice
' * and this permission notice appear in supporting documentation, and that
' * the name of Silicon Graphics, Inc. not be used in advertising
' * or publicity pertaining to distribution of the software without specific,
' * written prior permission.
' *
' * THE MATERIAL EMBODIED ON THIS SOFTWARE IS PROVIDED TO YOU "AS-IS"
' * AND WITHOUT WARRANTY OF ANY KIND, EXPRESS, IMPLIED OR OTHERWISE,
' * INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY OR
' * FITNESS FOR A PARTICULAR PURPOSE.  IN NO EVENT SHALL SILICON
' * GRAPHICS, INC.  BE LIABLE TO YOU OR ANYONE ELSE FOR ANY DIRECT,
' * SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY
' * KIND, OR ANY DAMAGES WHATSOEVER, INCLUDING WITHOUT LIMITATION,
' * LOSS OF PROFIT, LOSS OF USE, SAVINGS OR REVENUE, OR THE CLAIMS OF
' * THIRD PARTIES, WHETHER OR NOT SILICON GRAPHICS, INC.  HAS BEEN
' * ADVISED OF THE POSSIBILITY OF SUCH LOSS, HOWEVER CAUSED AND ON
' * ANY THEORY OF LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE
' * POSSESSION, USE OR PERFORMANCE OF THIS SOFTWARE.
' *
' * US Government Users Restricted Rights
' * Use, duplication, or disclosure by the Government is subject to
' * restrictions set forth in FAR 52.227.19(c)(2) or subparagraph
' * (c)(1)(ii) of the Rights in Technical Data and Computer Software
' * clause at DFARS 252.227-7013 and/or in similar or successor
' * clauses in the FAR or the DOD or NASA FAR Supplement.
' * Unpublished-- rights reserved under the copyright laws of the
' * United States.  Contractor/manufacturer is Silicon Graphics,
' * Inc., 2011 N.  Shoreline Blvd., Mountain View, CA 94039-7311.
' *
' * OpenGL(TM) is a trademark of Silicon Graphics, Inc.
' */

#INCLUDE ONCE "WINDOWS.INC"
#INCLUDE ONCE "GL.INC"
#INCLUDE ONCE "GLU.INC"

'/*
'** ToolKit Window Types
'** In the future, AUX_RGBA may be a combination of both RGB and ALPHA
'*/

%AUX_RGB            = 0
%AUX_RGBA           = %AUX_RGB
%AUX_INDEX          = 1
%AUX_SINGLE         = 0
%AUX_DOUBLE         = 2
%AUX_DIRECT         = 0
%AUX_INDIRECT       = 4

%AUX_ACCUM          = 8
%AUX_ALPHA          = 16
%AUX_DEPTH24        = 32     ' /* 24-bit depth buffer */
%AUX_STENCIL        = 64
%AUX_AUX            = 128
%AUX_DEPTH16        = 256    ' /* 16-bit depth buffer */
%AUX_FIXED_332_PAL  = 512
%AUX_DEPTH          = %AUX_DEPTH16  ' /* default is 16-bit depth buffer */

'/*
'** Window Masks
'*/

FUNCTION AUX_WIND_IS_RGB (BYVAL x AS LONG) AS LONG
   FUNCTION = ((x AND %AUX_INDEX) = 0)
END FUNCTION

FUNCTION AUX_WIND_IS_INDEX (BYVAL x AS LONG) AS LONG
   FUNCTION = ((x AND %AUX_INDEX) <> 0)
END FUNCTION

FUNCTION AUX_WIND_IS_SINGLE (BYVAL x AS LONG) AS LONG
   FUNCTION = ((x AND %AUX_DOUBLE) = 0)
END FUNCTION

FUNCTION AUX_WIND_IS_DOUBLE (BYVAL x AS LONG) AS LONG
   FUNCTION = ((x AND %AUX_DOUBLE) <> 0)
END FUNCTION

FUNCTION AUX_WIND_IS_INDIRECT (BYVAL x AS LONG) AS LONG
   FUNCTION = ((x AND %AUX_INDIRECT) <> 0)
END FUNCTION

FUNCTION AUX_WIND_IS_DIRECT (BYVAL x AS LONG) AS LONG
   FUNCTION = ((x AND %AUX_INDIRECT) = 0)
END FUNCTION

FUNCTION AUX_WIND_HAS_ACCUM (BYVAL x AS LONG) AS LONG
   FUNCTION = ((x AND %AUX_ACCUM) <> 0)
END FUNCTION

FUNCTION AUX_WIND_HAS_ALPHA (BYVAL x AS LONG) AS LONG
   FUNCTION = ((x AND %AUX_ALPHA) <> 0)
END FUNCTION

FUNCTION AUX_WIND_HAS_DEPTH (BYVAL x AS LONG) AS LONG
   FUNCTION = ((x AND (%AUX_DEPTH24 OR %AUX_DEPTH16)) <> 0)
END FUNCTION

FUNCTION AUX_WIND_HAS_STENCIL (BYVAL x AS LONG) AS LONG
   FUNCTION = ((x AND %AUX_STENCIL) <> 0)
END FUNCTION

FUNCTION AUX_WIND_USES_FIXED_332_PAL (BYVAL x AS LONG) AS LONG
   FUNCTION = ((x AND %AUX_FIXED_332_PAL) <> 0)
END FUNCTION

'/*
'** ToolKit Event Structure
'*/

' // Size = 20 bytes
TYPE AUX_EVENTREC
   nEvent   AS LONG   ' GLint
   nData(3) AS LONG   ' GLint[4]
END TYPE

'/*
'** ToolKit Event Types
'*/
%AUX_EXPOSE     = 1
%AUX_CONFIG     = 2
%AUX_DRAW       = 4
%AUX_KEYEVENT   = 8
%AUX_MOUSEDOWN  = 16
%AUX_MOUSEUP    = 32
%AUX_MOUSELOC   = 64

'/*
'** Toolkit Event Data Indices
'*/
%AUX_WINDOWX            = 0
%AUX_WINDOWY            = 1
%AUX_MOUSEX             = 0
%AUX_MOUSEY             = 1
%AUX_MOUSESTATUS        = 3
%AUX_KEY                = 0
%AUX_KEYSTATUS          = 1

'/*
'** ToolKit Event Status Messages
'*/
%AUX_LEFTBUTTON         = 1
%AUX_RIGHTBUTTON        = 2
%AUX_MIDDLEBUTTON       = 4
%AUX_SHIFT              = 1
%AUX_CONTROL            = 2

'/*
'** ToolKit Key Codes
'*/
%AUX_RETURN             = &H0D
%AUX_ESCAPE             = &H1B
%AUX_SPACE              = &H20
%AUX_LEFT               = &H25
%AUX_UP                 = &H26
%AUX_RIGHT              = &H27
%AUX_DOWN               = &H28
$AUX_A                  = "A"
$AUX_B                  = "B"
$AUX_C                  = "C"
$AUX_D                  = "D"
$AUX_E                  = "E"
$AUX_F                  = "F"
$AUX_G                  = "G"
$AUX_H                  = "H"
$AUX_I                  = "I"
$AUX_J                  = "J"
$AUX_K                  = "K"
$AUX_L                  = "L"
$AUX_M                  = "M"
$AUX_N                  = "N"
$AUX_O                  = "O"
$AUX_P                  = "P"
$AUX_Q                  = "Q"
$AUX_R                  = "R"
$AUX_S                  = "S"
$AUX_T                  = "T"
$AUX_U                  = "U"
$AUX_V                  = "V"
$AUX_W                  = "W"
$AUX_X                  = "X"
$AUX_Y                  = "Y"
$AUX_Z                  = "Z"
$AUX_sa                 = "a"
$AUX_sb                 = "b"
$AUX_sc                 = "c"
$AUX_sd                 = "d"
$AUX_se                 = "e"
$AUX_sf                 = "f"
$AUX_sg                 = "g"
$AUX_sh                 = "h"
$AUX_si                 = "i"
$AUX_sj                 = "j"
$AUX_sk                 = "k"
$AUX_sl                 = "l"
$AUX_sm                 = "m"
$AUX_sn                 = "n"
$AUX_so                 = "o"
$AUX_sp                 = "p"
$AUX_sq                 = "q"
$AUX_sr                 = "r"
$AUX_ss                 = "s"
$AUX_st                 = "t"
$AUX_su                 = "u"
$AUX_sv                 = "v"
$AUX_sw                 = "w"
$AUX_sx                 = "x"
$AUX_sy                 = "y"
$AUX_sz                 = "z"
$AUX_0                  = "0"
$AUX_1                  = "1"
$AUX_2                  = "2"
$AUX_3                  = "3"
$AUX_4                  = "4"
$AUX_5                  = "5"
$AUX_6                  = "6"
$AUX_7                  = "7"
$AUX_8                  = "8"
$AUX_9                  = "9"

'/*
'** ToolKit Gets and Sets
'*/
%AUX_FD                 = 1  ' /* return fd (long) */
%AUX_COLORMAP           = 3  ' /* pass buf of r, g and b (unsigned char) */
%AUX_GREYSCALEMAP       = 4
%AUX_FOGMAP             = 5  ' /* pass fog and color bits (long) */
%AUX_ONECOLOR           = 6  ' /* pass index, r, g, and b (long) */

'/*
'** Color Macros
'*/

%AUX_BLACK              = 0
%AUX_RED                = 13
%AUX_GREEN              = 14
%AUX_YELLOW             = 15
%AUX_BLUE               = 16
%AUX_MAGENTA            = 17
%AUX_CYAN               = 18
%AUX_WHITE              = 19

'extern float auxRGBMap[20][3];

'#define AUX_SETCOLOR(x, y) (AUX_WIND_IS_RGB((x)) ? \
'                           glColor3fv(auxRGBMap[(y)]) : glIndexf((y)))

GLOBAL auxRGBMap () AS SINGLE

SUB AUX_SETCOLOR (BYVAL x AS LONG, BYVAL y AS LONG)
   DIM auxRGBMap(19, 2)
   IF AUX_WIND_IS_RGB(x) THEN
      glColor3fv auxRGBMap(y, 0)
   ELSE
      glIndexf y
   END IF
END SUB

'/*
'** RGB Image Structure
'*/

' // Size = 12 bytes
TYPE AUX_RGBImageRec DWORD
   sizeX AS LONG
   sizeY AS LONG
   nData AS BYTE PTR
END TYPE

'/*
'** Prototypes
'*/

'void APIENTRY auxInitDisplayMode(GLenum);
DECLARE SUB auxInitDisplayMode IMPORT "GLAUX.DLL" ALIAS "auxInitDisplayMode" ( _
   BYVAL mask AS DWORD _                                ' GLenum mask
 )                                                      ' void

'void APIENTRY auxInitPosition(int, int, int, int);
DECLARE SUB auxInitPosition IMPORT "GLAUX.DLL" ALIAS "auxInitPosition" ( _
   BYVAL x AS LONG _                                    ' int x
 , BYVAL y AS LONG _                                    ' int y
 , BYVAL width AS LONG _                                ' int width
 , BYVAL height AS LONG _                               ' int height
 )                                                      ' void

'/* GLenum APIENTRY auxInitWindow(LPCTSTR); */

'GLenum APIENTRY auxInitWindowA(LPCSTR);
DECLARE FUNCTION auxInitWindow IMPORT "GLAUX.DLL" ALIAS "auxInitWindowA" ( _
   BYREF szTitle AS ASCIIZ _                            ' LPCSTR szTitle
 ) AS DWORD                                             ' GLenum

'GLenum APIENTRY auxInitWindowW(LPCWSTR);
DECLARE FUNCTION auxInitWindowW IMPORT "GLAUX.DLL" ALIAS "auxInitWindowW" ( _
   BYREF wszTitle AS WSTRINGZ _                         ' LPCWSTR wszTitle
 ) AS DWORD                                             ' GLenum

'void APIENTRY auxCloseWindow(void);
DECLARE SUB auxCloseWindow IMPORT "GLAUX.DLL" ALIAS "auxCloseWindow" ()   ' void

'void APIENTRY auxQuit(void);
DECLARE SUB auxQuit IMPORT "GLAUX.DLL" ALIAS "auxQuit" ()   ' void

'void APIENTRY auxSwapBuffers(void);
DECLARE SUB auxSwapBuffers IMPORT "GLAUX.DLL" ALIAS "auxSwapBuffers" ()   ' void

'typedef void (CALLBACK* AUXMAINPROC)(void);
'void APIENTRY auxMainLoop(AUXMAINPROC);
DECLARE SUB auxMainLoop IMPORT "GLAUX.DLL" ALIAS "auxMainLoop" ( _
   BYVAL func AS DWORD _                                ' AUXMAINPROC func
 )                                                      ' void

'typedef void (CALLBACK* AUXEXPOSEPROC)(int, int);
'void APIENTRY auxExposeFunc(AUXEXPOSEPROC);
DECLARE SUB auxExposeFunc IMPORT "GLAUX.DLL" ALIAS "auxExposeFunc" ( _
   BYVAL func AS DWORD _                                ' AUXEXPOSEPROC func
 )                                                      ' void

'typedef void (CALLBACK* AUXRESHAPEPROC)(GLsizei, GLsizei);
'void APIENTRY auxReshapeFunc(AUXRESHAPEPROC);
DECLARE SUB auxReshapeFunc IMPORT "GLAUX.DLL" ALIAS "auxReshapeFunc" ( _
   BYVAL func AS DWORD _                                ' AUXRESHAPEPROC func
 )                                                      ' void

'typedef void (CALLBACK* AUXIDLEPROC)(void);
'void APIENTRY auxIdleFunc(AUXIDLEPROC);
DECLARE SUB auxIdleFunc IMPORT "GLAUX.DLL" ALIAS "auxIdleFunc" ( _
   BYVAL func AS DWORD _                                ' AUXIDLEPROC func
 )                                                      ' void

'typedef void (CALLBACK* AUXKEYPROC)(void);
'void APIENTRY auxKeyFunc(int, AUXKEYPROC);
DECLARE SUB auxKeyFunc IMPORT "GLAUX.DLL" ALIAS "auxKeyFunc" ( _
   BYVAL key AS LONG _                                  ' key int
 , BYVAL func AS DWORD _                                ' AUXKEYPROC func
 )                                                      ' void

'typedef void (CALLBACK* AUXMOUSEPROC)(AUX_EVENTREC *);
'void APIENTRY auxMouseFunc(int, int, AUXMOUSEPROC);
DECLARE SUB auxMouseFunc IMPORT "GLAUX.DLL" ALIAS "auxMouseFunc" ( _
   BYVAL button AS LONG _                               ' int button
 , BYVAL mode AS LONG _                                 ' int mode
 , BYVAL func AS DWORD _                                ' AUXMOUSEPROC func
 )                                                      ' void

'int  APIENTRY auxGetColorMapSize(void);
DECLARE FUNCTION auxGetColorMapSize IMPORT "GLAUX.DLL" ALIAS "auxGetColorMapSize" ( _
 ) AS LONG                                              ' int

'void APIENTRY auxGetMouseLoc(int *, int *);
DECLARE SUB auxGetMouseLoc IMPORT "GLAUX.DLL" ALIAS "auxGetMouseLoc" ( _
   BYREF x AS LONG _                                    ' int *x
 , BYREF y AS LONG _                                    ' int *y
 )                                                      ' void

'void APIENTRY auxSetOneColor(int, float, float, float);
DECLARE SUB auxSetOneColor IMPORT "GLAUX.DLL" ALIAS "auxSetOneColor" ( _
   BYVAL index AS LONG _                                ' int index
 , BYVAL red AS SINGLE _                                ' float red
 , BYVAL green AS SINGLE _                              ' float green
 , BYVAL blue AS SINGLE _                               ' float blue
 )                                                      ' void

'void APIENTRY auxSetFogRamp(int, int);
DECLARE SUB auxSetFogRamp IMPORT "GLAUX.DLL" ALIAS "auxSetFogRamp" ( _
   BYVAL density AS LONG _                              ' int density
 , BYVAL startindex AS LONG _                           ' int startindex
 )                                                      ' void

'void APIENTRY auxSetGreyRamp(void);
DECLARE SUB auxSetGreyRamp IMPORT "GLAUX.DLL" ALIAS "auxSetGreyRamp" ()   ' void

'void APIENTRY auxSetRGBMap(int, float *);
DECLARE SUB auxSetRGBMap IMPORT "GLAUX.DLL" ALIAS "auxSetRGBMap" ( _
   BYVAL size AS LONG _                                 ' int size
 , BYREF rgb AS SINGLE _                                ' float *rgb
 )                                                      ' void

'/* AUX_RGBImageRec * APIENTRY auxRGBImageLoad(LPCTSTR); */

'AUX_RGBImageRec * APIENTRY auxRGBImageLoadA(LPCSTR);
DECLARE FUNCTION auxRGBImageLoad IMPORT "GLAUX.DLL" ALIAS "auxRGBImageLoadA" ( _
   BYREF filename AS ASCIIZ _                           ' LPCSTR filename
 ) AS DWORD                                             ' AUX_RGBImageRec

'AUX_RGBImageRec * APIENTRY auxRGBImageLoadW(LPCWSTR);
DECLARE FUNCTION auxRGBImageLoadW IMPORT "GLAUX.DLL" ALIAS "auxRGBImageLoadW" ( _
   BYREF filename AS WSTRINGZ _                         ' LPCWSTR filename
 ) AS DWORD                                             ' AUX_RGBImageRec *

'AUX_RGBImageRec * APIENTRY auxDIBImageLoadA(LPCSTR);
DECLARE FUNCTION auxDIBImageLoad IMPORT "GLAUX.DLL" ALIAS "auxDIBImageLoadA" ( _
   BYREF filename AS ASCIIZ _                           ' LPCSTR
 ) AS DWORD                                             ' AUX_RGBImageRec *

'AUX_RGBImageRec * APIENTRY auxDIBImageLoadW(LPCWSTR);
DECLARE FUNCTION auxDIBImageLoadW IMPORT "GLAUX.DLL" ALIAS "auxDIBImageLoadW" ( _
   BYREF filename AS WSTRINGZ _                         ' LPCWSTR
 ) AS DWORD                                             ' AUX_RGBImageRec *

'void APIENTRY auxCreateFont(void);
DECLARE SUB auxCreateFont IMPORT "GLAUX.DLL" ALIAS "auxCreateFont" ()   ' void

'/* void APIENTRY auxDrawStr(LPCTSTR); */

'void APIENTRY auxDrawStrA(LPCSTR);
DECLARE SUB auxDrawStr IMPORT "GLAUX.DLL" ALIAS "auxDrawStrA" ( _
   BYREF str AS ASCIIZ _                                ' LPCSTR str
 )                                                      ' void

'void APIENTRY auxDrawStrW(LPCWSTR);
DECLARE SUB auxDrawStrW IMPORT "GLAUX.DLL" ALIAS "auxDrawStrW" ( _
   BYREF str AS WSTRINGZ _                              ' LPCWSTR str
 )                                                      ' void

'void APIENTRY auxWireSphere(GLdouble);
DECLARE SUB auxWireSphere IMPORT "GLAUX.DLL" ALIAS "auxWireSphere" ( _
   BYVAL radius AS DOUBLE _                             ' GLdouble radius
 )                                                      ' void

'void APIENTRY auxSolidSphere(GLdouble);
DECLARE SUB auxSolidSphere IMPORT "GLAUX.DLL" ALIAS "auxSolidSphere" ( _
   BYVAL radius AS DOUBLE _                             ' GLdouble radius
 )                                                      ' void

'void APIENTRY auxWireCube(GLdouble);
DECLARE SUB auxWireCube IMPORT "GLAUX.DLL" ALIAS "auxWireCube" ( _
   BYVAL width AS DOUBLE _                              ' GLdouble width
 )                                                      ' void

'void APIENTRY auxSolidCube(GLdouble);
DECLARE SUB auxSolidCube IMPORT "GLAUX.DLL" ALIAS "auxSolidCube" ( _
   BYVAL width AS DOUBLE _                              ' GLdouble width
 )                                                      ' void

'void APIENTRY auxWireBox(GLdouble, GLdouble, GLdouble);
DECLARE SUB auxWireBox IMPORT "GLAUX.DLL" ALIAS "auxWireBox" ( _
   BYVAL width AS DOUBLE _                              ' GLdouble width
 , BYVAL heigth AS DOUBLE _                             ' GLdouble heigth
 , BYVAL depth AS DOUBLE _                              ' GLdouble depth
 )                                                      ' void

'void APIENTRY auxSolidBox(GLdouble, GLdouble, GLdouble);
DECLARE SUB auxSolidBox IMPORT "GLAUX.DLL" ALIAS "auxSolidBox" ( _
   BYVAL width AS DOUBLE _                              ' GLdouble width
 , BYVAL heigth AS DOUBLE _                             ' GLdouble heigth
 , BYVAL depth AS DOUBLE _                              ' GLdouble depth
 )                                                      ' void

'void APIENTRY auxWireTorus(GLdouble, GLdouble);
DECLARE SUB auxWireTorus IMPORT "GLAUX.DLL" ALIAS "auxWireTorus" ( _
   BYVAL innerRadius AS DOUBLE _                        ' GLdouble innerRadius
 , BYVAL outerRadius AS DOUBLE _                        ' GLdouble outerRadius
 )                                                      ' void

'void APIENTRY auxSolidTorus(GLdouble, GLdouble);
DECLARE SUB auxSolidTorus IMPORT "GLAUX.DLL" ALIAS "auxSolidTorus" ( _
   BYVAL innerRadius AS DOUBLE _                        ' GLdouble innerRadius
 , BYVAL outerRadius AS DOUBLE _                        ' GLdouble outerRadius
 )                                                      ' void

'void APIENTRY auxWireCylinder(GLdouble, GLdouble);
DECLARE SUB auxWireCylinder IMPORT "GLAUX.DLL" ALIAS "auxWireCylinder" ( _
   BYVAL radius AS DOUBLE _                             ' GLdouble radius
 , BYVAL height AS DOUBLE _                             ' GLdouble height
 )                                                      ' void

'void APIENTRY auxSolidCylinder(GLdouble, GLdouble);
DECLARE SUB auxSolidCylinder IMPORT "GLAUX.DLL" ALIAS "auxSolidCylinder" ( _
   BYVAL radius AS DOUBLE _                             ' GLdouble radius
 , BYVAL height AS DOUBLE _                             ' GLdouble height
 )                                                      ' void

'void APIENTRY auxWireIcosahedron(GLdouble);
DECLARE SUB auxWireIcosahedron IMPORT "GLAUX.DLL" ALIAS "auxWireIcosahedron" ( _
   BYVAL radius AS DOUBLE _                             ' GLdouble radius
 )                                                      ' void

'void APIENTRY auxSolidIcosahedron(GLdouble);
DECLARE SUB auxSolidIcosahedron IMPORT "GLAUX.DLL" ALIAS "auxSolidIcosahedron" ( _
   BYVAL radius AS DOUBLE _                             ' GLdouble radius
 )                                                      ' void

'void APIENTRY auxWireOctahedron(GLdouble);
DECLARE SUB auxWireOctahedron IMPORT "GLAUX.DLL" ALIAS "auxWireOctahedron" ( _
   BYVAL radius AS DOUBLE _                             ' GLdouble radius
 )                                                      ' void

'void APIENTRY auxSolidOctahedron(GLdouble);
DECLARE SUB auxSolidOctahedron IMPORT "GLAUX.DLL" ALIAS "auxSolidOctahedron" ( _
   BYVAL radius AS DOUBLE _                             ' GLdouble radius
 )                                                      ' void

'void APIENTRY auxWireTetrahedron(GLdouble);
DECLARE SUB auxWireTetrahedron IMPORT "GLAUX.DLL" ALIAS "auxWireTetrahedron" ( _
   BYVAL radius AS DOUBLE _                             ' GLdouble radius
 )                                                      ' void

'void APIENTRY auxSolidTetrahedron(GLdouble);
DECLARE SUB auxSolidTetrahedron IMPORT "GLAUX.DLL" ALIAS "auxSolidTetrahedron" ( _
   BYVAL radius AS DOUBLE _                             ' GLdouble radius
 )                                                      ' void

'void APIENTRY auxWireDodecahedron(GLdouble);
DECLARE SUB auxWireDodecahedron IMPORT "GLAUX.DLL" ALIAS "auxWireDodecahedron" ( _
   BYVAL radius AS DOUBLE _                             ' GLdouble radius
 )                                                      ' void

'void APIENTRY auxSolidDodecahedron(GLdouble);
DECLARE SUB auxSolidDodecahedron IMPORT "GLAUX.DLL" ALIAS "auxSolidDodecahedron" ( _
   BYVAL radius AS DOUBLE _                             ' GLdouble radius
 )                                                      ' void

'void APIENTRY auxWireCone(GLdouble, GLdouble);
DECLARE SUB auxWireCone IMPORT "GLAUX.DLL" ALIAS "auxWireCone" ( _
   BYVAL radius AS DOUBLE _                             ' GLdouble radius
 , BYVAL height AS DOUBLE _                             ' GLdouble height
 )                                                      ' void

'void APIENTRY auxSolidCone(GLdouble, GLdouble);
DECLARE SUB auxSolidCone IMPORT "GLAUX.DLL" ALIAS "auxSolidCone" ( _
   BYVAL radius AS DOUBLE _                             ' GLdouble radius
 , BYVAL height AS DOUBLE _                             ' GLdouble height
 )                                                      ' void

'void APIENTRY auxWireTeapot(GLdouble);
DECLARE SUB auxWireTeapot IMPORT "GLAUX.DLL" ALIAS "auxWireTeapot" ( _
   BYVAL size AS DOUBLE _                               ' GLdouble size
 )                                                      ' void

'void APIENTRY auxSolidTeapot(GLdouble);
DECLARE SUB auxSolidTeapot IMPORT "GLAUX.DLL" ALIAS "auxSolidTeapot" ( _
   BYVAL size AS DOUBLE _                               ' GLdouble size
 )                                                      ' void

'/*
'** Window specific functions
'** hwnd, hdc, and hglrc valid after auxInitWindow()
'*/
'HWND  APIENTRY auxGetHWND(void);
DECLARE FUNCTION auxGetHWND IMPORT "GLAUX.DLL" ALIAS "auxGetHWND" ( _
 ) AS DWORD                                             ' HWND

'HDC   APIENTRY auxGetHDC(void);
DECLARE FUNCTION auxGetHDC IMPORT "GLAUX.DLL" ALIAS "auxGetHDC" ( _
 ) AS DWORD                                             ' HDC

'HGLRC APIENTRY auxGetHGLRC(void);
DECLARE FUNCTION auxGetHGLRC IMPORT "GLAUX.DLL" ALIAS "auxGetHGLRC" ( _
 ) AS DWORD                                             ' HGLRC

'/*
'** Viewperf support functions and constants
'*/
'/* Display Mode Selection Criteria */

%AUX_USE_ID           = 1
%AUX_EXACT_MATCH      = 2
%AUX_MINIMUM_CRITERIA = 3

'void   APIENTRY auxInitDisplayModePolicy(GLenum);
DECLARE SUB auxInitDisplayModePolicy IMPORT "GLAUX.DLL" ALIAS "auxInitDisplayModePolicy" ( _
   BYVAL type AS DWORD _                                ' GLenum type
 )                                                      ' void

'GLenum APIENTRY auxInitDisplayModeID(GLint);
DECLARE FUNCTION auxInitDisplayModeID IMPORT "GLAUX.DLL" ALIAS "auxInitDisplayModeID" ( _
   BYVAL id AS LONG _                                   ' GLint id
 ) AS DWORD                                             ' GLenum

'GLenum APIENTRY auxGetDisplayModePolicy(void);
DECLARE FUNCTION auxGetDisplayModePolicy IMPORT "GLAUX.DLL" ALIAS "auxGetDisplayModePolicy" ( _
 ) AS DWORD                                             ' GLenum

'GLint  APIENTRY auxGetDisplayModeID(void);
DECLARE FUNCTION auxGetDisplayModeID IMPORT "GLAUX.DLL" ALIAS "auxGetDisplayModeID" ( _
 ) AS LONG                                              ' GLint

'GLenum APIENTRY auxGetDisplayMode(void);
DECLARE FUNCTION auxGetDisplayMode IMPORT "GLAUX.DLL" ALIAS "auxGetDisplayMode" ( _
 ) AS DWORD                                             ' GLenum
