'/**********************************************************************************
' * Copyright (c) 2008-2009 The Khronos Group Inc.
' *
' * Permission is hereby granted, free of charge, to any person obtaining a
' * copy of this software and/or associated documentation files (the
' * "Materials"), to deal in the Materials without restriction, including
' * without limitation the rights to use, copy, modify, merge, publish,
' * distribute, sublicense, and/or sell copies of the Materials, and to
' * permit persons to whom the Materials are furnished to do so, subject to
' * the following conditions:
' *
' * The above copyright notice and this permission notice shall be included
' * in all copies or substantial portions of the Materials.
' *
' * THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
' * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
' * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
' * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
' * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
' * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
' * MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
' **********************************************************************************/

'/* $Revision: 8748 $ on $Date: 2009-08-27 04:24:36 -0700 (Thu, 27 Aug 2009) $ */

#INCLUDE THIS ONCE
%CL_GL_INC = 1

#INCLUDE ONCE "cl_platform.inc"
#INCLUDE ONCE "gl.inc"

'// NOTE:  Make sure that appropriate GL header file is included separately

'typedef cl_uint     cl_gl_object_type;
'typedef cl_uint     cl_gl_texture_info;
'typedef cl_uint     cl_gl_platform_info;

'// cl_gl_object_type
%CL_GL_OBJECT_BUFFER             = &H2000???
%CL_GL_OBJECT_TEXTURE2D          = &H2001???
%CL_GL_OBJECT_TEXTURE3D          = &H2002???
%CL_GL_OBJECT_RENDERBUFFER       = &H2003???

'// cl_gl_texture_info
%CL_GL_TEXTURE_TARGET            = &H2004???
%CL_GL_MIPMAP_LEVEL              = &H2005???

DECLARE FUNCTION clCreateFromGLBuffer IMPORT "OpenCL.DLL" ALIAS "clCreateFromGLBuffer" ( _
   BYVAL context AS DWORD _                             ' cl_context     /* context */,
 , BYVAL flags AS QUAD _                                ' cl_mem_flags   /* flags */,
 , BYVAL bufobj AS DWORD _                              ' GLuint         /* bufobj */,
 , BYREF errcode_ret AS LONG _                          ' int *          /* errcode_ret */
 ) AS DWORD                                             ' cl_mem


DECLARE FUNCTION clCreateFromGLTexture2D IMPORT "OpenCL.DLL" ALIAS "clCreateFromGLTexture2D" ( _
   BYVAL context AS DWORD _                             ' cl_context     /* context */,
 , BYVAL flags AS QUAD _                                ' cl_mem_flags   /* flags */,
 , BYVAL target AS LONG _                               ' GLenum          /* target */
 , BYVAL miplevel AS LONG _                             ' GLint           /* miplevel */
 , BYVAL texture AS DWORD _                             ' GLuint          /* texture */
 , BYREF errcode_ret AS LONG _                          ' int *          /* errcode_ret */
 ) AS DWORD                                             ' cl_mem

DECLARE FUNCTION clCreateFromGLTexture3D IMPORT "OpenCL.DLL" ALIAS "clCreateFromGLTexture3D" ( _
   BYVAL context AS DWORD _                             ' cl_context     /* context */,
 , BYVAL flags AS QUAD _                                ' cl_mem_flags   /* flags */,
 , BYVAL target AS LONG _                               ' GLenum          /* target */
 , BYVAL miplevel AS LONG _                             ' GLint           /* miplevel */
 , BYVAL texture AS DWORD _                             ' GLuint          /* texture */
 , BYREF errcode_ret AS LONG _                          ' int *          /* errcode_ret */
 ) AS DWORD                                             ' cl_mem

DECLARE FUNCTION clCreateFromGLRenderbuffer IMPORT "OpenCL.DLL" ALIAS "clCreateFromGLRenderbuffer" ( _
   BYVAL context AS DWORD _                             ' cl_context     /* context */,
 , BYVAL flags AS QUAD _                                ' cl_mem_flags   /* flags */,
 , BYVAL renderbuffer AS DWORD _                        ' GLuint       /* renderbuffer */
 , BYREF errcode_ret AS LONG _                          ' int *          /* errcode_ret */
 ) AS DWORD                                             ' cl_mem

DECLARE FUNCTION clGetGLObjectInfo IMPORT "OpenCL.DLL" ALIAS "clGetGLObjectInfo" ( _
   BYVAL memobj AS DWORD _                              ' cl_mem                /* memobj */
 , BYVAL gl_object_type AS DWORD _                      ' cl_gl_object_type *   /* gl_object_type */
 , BYREF gl_object_name AS DWORD _                      ' GLuint *              /* gl_object_name */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clGetGLTextureInfo IMPORT "OpenCL.DLL" ALIAS "clGetGLTextureInfo" ( _
   BYVAL memobj AS DWORD _                              ' cl_mem               /* memobj */
 , BYVAL param_name AS DWORD _                          ' cl_gl_texture_info   /* param_name */
 , BYVAL param_value_size AS DWORD _                    ' size_t               /* param_value_size */
 , BYREF param_value AS ANY _                           ' void *               /* param_value */
 , BYREF param_value_size_ret AS DWORD _                ' size_t *             /* param_value_size_ret */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clEnqueueAcquireGLObjects IMPORT "OpenCL.DLL" ALIAS "clEnqueueAcquireGLObjects" ( _
   BYVAL command_queue AS DWORD _                       ' cl_command_queue      /* command_queue */
 , BYVAL num_objects AS DWORD _                         ' cl_uint               /* num_objects */
 , BYREF mem_objects AS DWORD _                         ' const cl_mem *        /* mem_objects */
 , BYVAL num_events_in_wait_list AS DWORD _             ' cl_uint               /* num_events_in_wait_list */
 , BYREF event_wait_list AS DWORD _                     ' const cl_event *      /* event_wait_list */
 , BYREF event AS DWORD _                               ' cl_event *            /* event */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clEnqueueReleaseGLObjects IMPORT "OpenCL.DLL" ALIAS "clEnqueueReleaseGLObjects" ( _
   BYVAL command_queue AS DWORD _                       ' cl_command_queue      /* command_queue */
 , BYVAL num_objects AS DWORD _                         ' cl_uint               /* num_objects */
 , BYVAL mem_objects AS DWORD _                         ' const cl_mem *        /* mem_objects */
 , BYVAL num_events_in_wait_list AS DWORD _             ' cl_uint               /* num_events_in_wait_list */
 , BYREF event_wait_list AS DWORD _                     ' const cl_event *      /* event_wait_list */
 , BYREF event AS DWORD _                               ' cl_event *            /* event */
 ) AS LONG                                              ' cl_int
