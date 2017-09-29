'/*******************************************************************************
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
' ******************************************************************************/

'/* $Revision: 9283 $ on $Date: 2009-10-14 10:18:57 -0700 (Wed, 14 Oct 2009) $ */

#INCLUDE THIS ONCE
%CL_INC = 1

#INCLUDE ONCE "cl_platform.inc"

'/******************************************************************************/

'typedef struct _cl_platform_id *    cl_platform_id;
'typedef struct _cl_device_id *      cl_device_id;
'typedef struct _cl_context *        cl_context;
'typedef struct _cl_command_queue *  cl_command_queue;
'typedef struct _cl_mem *            cl_mem;
'typedef struct _cl_program *        cl_program;
'typedef struct _cl_kernel *         cl_kernel;
'typedef struct _cl_event *          cl_event;
'typedef struct _cl_sampler *        cl_sampler;

'typedef cl_uint             cl_bool;                     /* WARNING!  Unlike cl_ types in cl_platform.h, cl_bool is not guaranteed to be the same size as the bool in kernels. */
'typedef cl_ulong            cl_bitfield;
'typedef cl_bitfield         cl_device_type;
'typedef cl_uint             cl_platform_info;
'typedef cl_uint             cl_device_info;
'typedef cl_bitfield         cl_device_address_info;
'typedef cl_bitfield         cl_device_fp_config;
'typedef cl_uint             cl_device_mem_cache_type;
'typedef cl_uint             cl_device_local_mem_type;
'typedef cl_bitfield         cl_device_exec_capabilities;
'typedef cl_bitfield         cl_command_queue_properties;

'typedef intptr_t            cl_context_properties;
'typedef cl_uint             cl_context_info;
'typedef cl_uint             cl_command_queue_info;
'typedef cl_uint             cl_channel_order;
'typedef cl_uint             cl_channel_type;
'typedef cl_bitfield         cl_mem_flags;
'typedef cl_uint             cl_mem_object_type;
'typedef cl_uint             cl_mem_info;
'typedef cl_uint             cl_image_info;
'typedef cl_uint             cl_addressing_mode;
'typedef cl_uint             cl_filter_mode;
'typedef cl_uint             cl_sampler_info;
'typedef cl_bitfield         cl_map_flags;
'typedef cl_uint             cl_program_info;
'typedef cl_uint             cl_program_build_info;
'typedef cl_int              cl_build_status;
'typedef cl_uint             cl_kernel_info;
'typedef cl_uint             cl_kernel_work_group_info;
'typedef cl_uint             cl_event_info;
'typedef cl_uint             cl_command_type;
'typedef cl_uint             cl_profiling_info;

' // Size = 8 bytes
TYPE cl_image_format DWORD
   image_channel_order     AS DWORD   ' cl_channel_order
   image_channel_data_type AS DWORD   ' cl_channel_type
END TYPE



'/******************************************************************************/

'// Error Codes
%CL_SUCCESS                                 = 0&
%CL_DEVICE_NOT_FOUND                        = -1&
%CL_DEVICE_NOT_AVAILABLE                    = -2&
%CL_COMPILER_NOT_AVAILABLE                  = -3&
%CL_MEM_OBJECT_ALLOCATION_FAILURE           = -4&
%CL_OUT_OF_RESOURCES                        = -5&
%CL_OUT_OF_HOST_MEMORY                      = -6&
%CL_PROFILING_INFO_NOT_AVAILABLE            = -7&
%CL_MEM_COPY_OVERLAP                        = -8&
%CL_IMAGE_FORMAT_MISMATCH                   = -9&
%CL_IMAGE_FORMAT_NOT_SUPPORTED              = -10&
%CL_BUILD_PROGRAM_FAILURE                   = -11&
%CL_MAP_FAILURE                             = -12&

%CL_INVALID_VALUE                           = -30&
%CL_INVALID_DEVICE_TYPE                     = -31&
%CL_INVALID_PLATFORM                        = -32&
%CL_INVALID_DEVICE                          = -33&
%CL_INVALID_CONTEXT                         = -34&
%CL_INVALID_QUEUE_PROPERTIES                = -35&
%CL_INVALID_COMMAND_QUEUE                   = -36&
%CL_INVALID_HOST_PTR                        = -37&
%CL_INVALID_MEM_OBJECT                      = -38&
%CL_INVALID_IMAGE_FORMAT_DESCRIPTOR         = -39&
%CL_INVALID_IMAGE_SIZE                      = -40&
%CL_INVALID_SAMPLER                         = -41&
%CL_INVALID_BINARY                          = -42&
%CL_INVALID_BUILD_OPTIONS                   = -43&
%CL_INVALID_PROGRAM                         = -44&
%CL_INVALID_PROGRAM_EXECUTABLE              = -45&
%CL_INVALID_KERNEL_NAME                     = -46&
%CL_INVALID_KERNEL_DEFINITION               = -47&
%CL_INVALID_KERNEL                          = -48&
%CL_INVALID_ARG_INDEX                       = -49&
%CL_INVALID_ARG_VALUE                       = -50&
%CL_INVALID_ARG_SIZE                        = -51&
%CL_INVALID_KERNEL_ARGS                     = -52&
%CL_INVALID_WORK_DIMENSION                  = -53&
%CL_INVALID_WORK_GROUP_SIZE                 = -54&
%CL_INVALID_WORK_ITEM_SIZE                  = -55&
%CL_INVALID_GLOBAL_OFFSET                   = -56&
%CL_INVALID_EVENT_WAIT_LIST                 = -57&
%CL_INVALID_EVENT                           = -58&
%CL_INVALID_OPERATION                       = -59&
%CL_INVALID_GL_OBJECT                       = -60&
%CL_INVALID_BUFFER_SIZE                     = -61&
%CL_INVALID_MIP_LEVEL                       = -62&
%CL_INVALID_GLOBAL_WORK_SIZE                = -63&

'// OpenCL Version
%CL_VERSION_1_0                             = 1

'// cl_bool
%CL_FALSE                                   = 0???
%CL_TRUE                                    = 1???

'// cl_platform_info
%CL_PLATFORM_PROFILE                        = &H0900???
%CL_PLATFORM_VERSION                        = &H0901???
%CL_PLATFORM_NAME                           = &H0902???
%CL_PLATFORM_VENDOR                         = &H0903???
%CL_PLATFORM_EXTENSIONS                     = &H0904???

'// cl_device_type - bitfield
%CL_DEVICE_TYPE_DEFAULT                     = 1&&   ' (1 << 0)
%CL_DEVICE_TYPE_CPU                         = 2&&   ' (1 << 1)
%CL_DEVICE_TYPE_GPU                         = 4&&   ' (1 << 2)
%CL_DEVICE_TYPE_ACCELERATOR                 = 8&&   ' (1 << 3)
%CL_DEVICE_TYPE_ALL                         = &HFFFFFFFF&&

'// cl_device_info
%CL_DEVICE_TYPE                              = &H1000???
%CL_DEVICE_VENDOR_ID                         = &H1001???
%CL_DEVICE_MAX_COMPUTE_UNITS                 = &H1002???
%CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS          = &H1003???
%CL_DEVICE_MAX_WORK_GROUP_SIZE               = &H1004???
%CL_DEVICE_MAX_WORK_ITEM_SIZES               = &H1005???
%CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR       = &H1006???
%CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT      = &H1007???
%CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT        = &H1008???
%CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG       = &H1009???
%CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT      = &H100A???
%CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE     = &H100B???
%CL_DEVICE_MAX_CLOCK_FREQUENCY               = &H100C???
%CL_DEVICE_ADDRESS_BITS                      = &H100D???
%CL_DEVICE_MAX_READ_IMAGE_ARGS               = &H100E???
%CL_DEVICE_MAX_WRITE_IMAGE_ARGS              = &H100F???
%CL_DEVICE_MAX_MEM_ALLOC_SIZE                = &H1010???
%CL_DEVICE_IMAGE2D_MAX_WIDTH                 = &H1011???
%CL_DEVICE_IMAGE2D_MAX_HEIGHT                = &H1012???
%CL_DEVICE_IMAGE3D_MAX_WIDTH                 = &H1013???
%CL_DEVICE_IMAGE3D_MAX_HEIGHT                = &H1014???
%CL_DEVICE_IMAGE3D_MAX_DEPTH                 = &H1015???
%CL_DEVICE_IMAGE_SUPPORT                     = &H1016???
%CL_DEVICE_MAX_PARAMETER_SIZE                = &H1017???
%CL_DEVICE_MAX_SAMPLERS                      = &H1018???
%CL_DEVICE_MEM_BASE_ADDR_ALIGN               = &H1019???
%CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE          = &H101A???
%CL_DEVICE_SINGLE_FP_CONFIG                  = &H101B???
%CL_DEVICE_GLOBAL_MEM_CACHE_TYPE             = &H101C???
%CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE         = &H101D???
%CL_DEVICE_GLOBAL_MEM_CACHE_SIZE             = &H101E???
%CL_DEVICE_GLOBAL_MEM_SIZE                   = &H101F???
%CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE          = &H1020???
%CL_DEVICE_MAX_CONSTANT_ARGS                 = &H1021???
%CL_DEVICE_LOCAL_MEM_TYPE                    = &H1022???
%CL_DEVICE_LOCAL_MEM_SIZE                    = &H1023???
%CL_DEVICE_ERROR_CORRECTION_SUPPORT          = &H1024???
%CL_DEVICE_PROFILING_TIMER_RESOLUTION        = &H1025???
%CL_DEVICE_ENDIAN_LITTLE                     = &H1026???
%CL_DEVICE_AVAILABLE                         = &H1027???
%CL_DEVICE_COMPILER_AVAILABLE                = &H1028???
%CL_DEVICE_EXECUTION_CAPABILITIES            = &H1029???
%CL_DEVICE_QUEUE_PROPERTIES                  = &H102A???
%CL_DEVICE_NAME                              = &H102B???
%CL_DEVICE_VENDOR                            = &H102C???
%CL_DRIVER_VERSION                           = &H102D???
%CL_DEVICE_PROFILE                           = &H102E???
%CL_DEVICE_VERSION                           = &H102F???
%CL_DEVICE_EXTENSIONS                        = &H1030???
%CL_DEVICE_PLATFORM                          = &H1031???

'// cl_device_fp_config - bitfield
%CL_FP_DENORM                                = 1&&    ' (1 << 0)
%CL_FP_INF_NAN                               = 2&&    ' (1 << 1)
%CL_FP_ROUND_TO_NEAREST                      = 4&&    ' (1 << 2)
%CL_FP_ROUND_TO_ZERO                         = 8&&    ' (1 << 3)
%CL_FP_ROUND_TO_INF                          = 16&&   ' (1 << 4)
%CL_FP_FMA                                   = 32&&   ' (1 << 5)

'// cl_device_mem_cache_type
%CL_NONE                                     = &H0???
%CL_READ_ONLY_CACHE                          = &H1???
%CL_READ_WRITE_CACHE                         = &H2???

'// cl_device_local_mem_type
%CL_LOCAL                                    = &H1???
%CL_GLOBAL                                   = &H2???

'// cl_device_exec_capabilities - bitfield
%CL_EXEC_KERNEL                              = 1&&   ' (1 << 0)
%CL_EXEC_NATIVE_KERNEL                       = 2&&   ' (1 << 1)

'// cl_command_queue_properties - bitfield
%CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE      = 1&&   ' (1 << 0)
%CL_QUEUE_PROFILING_ENABLE                   = 2&&   ' (1 << 1)

'// cl_context_info
%CL_CONTEXT_REFERENCE_COUNT                  = &H1080???
%CL_CONTEXT_DEVICES                          = &H1081???
%CL_CONTEXT_PROPERTIES                       = &H1082???

'// cl_context_properties
%CL_CONTEXT_PLATFORM                         = &H1084???

'// cl_command_queue_info
%CL_QUEUE_CONTEXT                            = &H1090???
%CL_QUEUE_DEVICE                             = &H1091???
%CL_QUEUE_REFERENCE_COUNT                    = &H1092???
%CL_QUEUE_PROPERTIES                         = &H1093???

'// cl_mem_flags - bitfield
%CL_MEM_READ_WRITE                           = &H1&&    ' (1 << 0)
%CL_MEM_WRITE_ONLY                           = &H2&&    ' (1 << 1)
%CL_MEM_READ_ONLY                            = &H4&&    ' (1 << 2)
%CL_MEM_USE_HOST_PTR                         = &H8&&    ' (1 << 3)
%CL_MEM_ALLOC_HOST_PTR                       = &H16&&   ' (1 << 4)
%CL_MEM_COPY_HOST_PTR                        = &H32&&   ' (1 << 5)

'// cl_channel_order
%CL_R                                        = &H10B0???
%CL_A                                        = &H10B1???
%CL_RG                                       = &H10B2???
%CL_RA                                       = &H10B3???
%CL_RGB                                      = &H10B4???
%CL_RGBA                                     = &H10B5???
%CL_BGRA                                     = &H10B6???
%CL_ARGB                                     = &H10B7???
%CL_INTENSITY                                = &H10B8???
%CL_LUMINANCE                                = &H10B9???

'// cl_channel_type
%CL_SNORM_INT8                               = &H10D0???
%CL_SNORM_INT16                              = &H10D1???
%CL_UNORM_INT8                               = &H10D2???
%CL_UNORM_INT16                              = &H10D3???
%CL_UNORM_SHORT_565                          = &H10D4???
%CL_UNORM_SHORT_555                          = &H10D5???
%CL_UNORM_INT_101010                         = &H10D6???
%CL_SIGNED_INT8                              = &H10D7???
%CL_SIGNED_INT16                             = &H10D8???
%CL_SIGNED_INT32                             = &H10D9???
%CL_UNSIGNED_INT8                            = &H10DA???
%CL_UNSIGNED_INT16                           = &H10DB???
%CL_UNSIGNED_INT32                           = &H10DC???
%CL_HALF_FLOAT                               = &H10DD???
%CL_FLOAT                                    = &H10DE???

'// cl_mem_object_type
%CL_MEM_OBJECT_BUFFER                        = &H10F0???
%CL_MEM_OBJECT_IMAGE2D                       = &H10F1???
%CL_MEM_OBJECT_IMAGE3D                       = &H10F2???

'// cl_mem_info
%CL_MEM_TYPE                                 = &H1100???
%CL_MEM_FLAGS                                = &H1101???
%CL_MEM_SIZE                                 = &H1102???
%CL_MEM_HOST_PTR                             = &H1103???
%CL_MEM_MAP_COUNT                            = &H1104???
%CL_MEM_REFERENCE_COUNT                      = &H1105???
%CL_MEM_CONTEXT                              = &H1106???

'// cl_image_info
%CL_IMAGE_FORMAT                             = &H1110???
%CL_IMAGE_ELEMENT_SIZE                       = &H1111???
%CL_IMAGE_ROW_PITCH                          = &H1112???
%CL_IMAGE_SLICE_PITCH                        = &H1113???
%CL_IMAGE_WIDTH                              = &H1114???
%CL_IMAGE_HEIGHT                             = &H1115???
%CL_IMAGE_DEPTH                              = &H1116???

'// cl_addressing_mode
%CL_ADDRESS_NONE                             = &H1130???
%CL_ADDRESS_CLAMP_TO_EDGE                    = &H1131???
%CL_ADDRESS_CLAMP                            = &H1132???
%CL_ADDRESS_REPEAT                           = &H1133???

'// cl_filter_mode
%CL_FILTER_NEAREST                           = &H1140???
%CL_FILTER_LINEAR                            = &H1141???

'// cl_sampler_info
%CL_SAMPLER_REFERENCE_COUNT                  = &H1150???
%CL_SAMPLER_CONTEXT                          = &H1151???
%CL_SAMPLER_NORMALIZED_COORDS                = &H1152???
%CL_SAMPLER_ADDRESSING_MODE                  = &H1153???
%CL_SAMPLER_FILTER_MODE                      = &H1154???

'// cl_map_flags - bitfield
%CL_MAP_READ                                 = &H1&&   ' (1 << 0)
%CL_MAP_WRITE                                = &H2&&   ' (1 << 1)

'// cl_program_info
%CL_PROGRAM_REFERENCE_COUNT                  = &H1160???
%CL_PROGRAM_CONTEXT                          = &H1161???
%CL_PROGRAM_NUM_DEVICES                      = &H1162???
%CL_PROGRAM_DEVICES                          = &H1163???
%CL_PROGRAM_SOURCE                           = &H1164???
%CL_PROGRAM_BINARY_SIZES                     = &H1165???
%CL_PROGRAM_BINARIES                         = &H1166???

'// cl_program_build_info
%CL_PROGRAM_BUILD_STATUS                     = &H1181???
%CL_PROGRAM_BUILD_OPTIONS                    = &H1182???
%CL_PROGRAM_BUILD_LOG                        = &H1183???

'// cl_build_status
%CL_BUILD_SUCCESS                            = 0&
%CL_BUILD_NONE                               = -1&
%CL_BUILD_ERROR                              = -2&
%CL_BUILD_IN_PROGRESS                        = -3&

'// cl_kernel_info
%CL_KERNEL_FUNCTION_NAME                     = &H1190???
%CL_KERNEL_NUM_ARGS                          = &H1191???
%CL_KERNEL_REFERENCE_COUNT                   = &H1192???
%CL_KERNEL_CONTEXT                           = &H1193???
%CL_KERNEL_PROGRAM                           = &H1194???

'// cl_kernel_work_group_info
%CL_KERNEL_WORK_GROUP_SIZE                   = &H11B0???
%CL_KERNEL_COMPILE_WORK_GROUP_SIZE           = &H11B1???
%CL_KERNEL_LOCAL_MEM_SIZE                    = &H11B2???

'// cl_event_info
%CL_EVENT_COMMAND_QUEUE                      = &H11D0???
%CL_EVENT_COMMAND_TYPE                       = &H11D1???
%CL_EVENT_REFERENCE_COUNT                    = &H11D2???
%CL_EVENT_COMMAND_EXECUTION_STATUS           = &H11D3???

'// cl_command_type
%CL_COMMAND_NDRANGE_KERNEL                   = &H11F0???
%CL_COMMAND_TASK                             = &H11F1???
%CL_COMMAND_NATIVE_KERNEL                    = &H11F2???
%CL_COMMAND_READ_BUFFER                      = &H11F3???
%CL_COMMAND_WRITE_BUFFER                     = &H11F4???
%CL_COMMAND_COPY_BUFFER                      = &H11F5???
%CL_COMMAND_READ_IMAGE                       = &H11F6???
%CL_COMMAND_WRITE_IMAGE                      = &H11F7???
%CL_COMMAND_COPY_IMAGE                       = &H11F8???
%CL_COMMAND_COPY_IMAGE_TO_BUFFER             = &H11F9???
%CL_COMMAND_COPY_BUFFER_TO_IMAGE             = &H11FA???
%CL_COMMAND_MAP_BUFFER                       = &H11FB???
%CL_COMMAND_MAP_IMAGE                        = &H11FC???
%CL_COMMAND_UNMAP_MEM_OBJECT                 = &H11FD???
%CL_COMMAND_MARKER                           = &H11FE???
%CL_COMMAND_ACQUIRE_GL_OBJECTS               = &H11FF???
%CL_COMMAND_RELEASE_GL_OBJECTS               = &H1200???

'// command execution status
%CL_COMPLETE                                 = &H0&
%CL_RUNNING                                  = &H1&
%CL_SUBMITTED                                = &H2&
%CL_QUEUED                                   = &H3&

'// cl_profiling_info
%CL_PROFILING_COMMAND_QUEUED                 = &H1280???
%CL_PROFILING_COMMAND_SUBMIT                 = &H1281???
%CL_PROFILING_COMMAND_START                  = &H1282???
%CL_PROFILING_COMMAND_END                    = &H1283???

'/********************************************************************************************************/

'// Platform API

DECLARE FUNCTION clGetPlatformIDs IMPORT "OpenCL.DLL" ALIAS "clGetPlatformIDs" ( _
   BYVAL num_entries AS DWORD _                         ' cl_uint          /* num_entries */
 , BYREF platforms AS DWORD _                           ' cl_platform_id * /* platforms */
 , BYREF num_platforms AS DWORD _                       ' cl_uint *        /* num_platforms */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clGetPlatformInfo IMPORT "OpenCL.DLL" ALIAS "clGetPlatformInfo" ( _
   BYVAL platform AS DWORD _                            ' cl_platform_id   /* platform */
 , BYVAL param_name AS DWORD _                          ' cl_platform_info /* param_name */
 , BYVAL param_value_size AS DWORD _                    ' size_t           /* param_value_size */
 , BYREF param_value AS ANY _                           ' void *           /* param_value */
 , BYREF param_value_size_ret AS DWORD _                ' size_t *         /* param_value_size_ret */
 ) AS LONG                                              ' cl_int

'// Device APIs

DECLARE FUNCTION clGetDeviceIDs IMPORT "OpenCL.DLL" ALIAS "clGetDeviceIDs" ( _
   BYVAL platform AS DWORD _                            ' cl_platform_id   /* platform */
 , BYVAL cl_device_type AS QUAD _                       ' cl_device_type   /* device_type */
 , BYVAL num_entries AS DWORD _                         ' cl_uint          /* num_entries */
 , BYREF devices AS DWORD _                             ' cl_device_id *   /* devices */
 , BYREF num_devices AS DWORD _                         ' cl_uint *        /* num_devices */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clGetDeviceInfo IMPORT "OpenCL.DLL" ALIAS "clGetDeviceInfo" ( _
   BYVAL device AS DWORD _                              ' cl_device_id    /* device */
 , BYVAL param_name AS DWORD _                          ' cl_device_info  /* param_name */
 , BYVAL param_value_size AS DWORD _                    ' size_t          /* param_value_size */
 , BYREF param_value AS ANY _                           ' void *          /* param_value */
 , BYREF param_value_size_ret AS DWORD _                ' size_t *        /* param_value_size_ret */
 ) AS LONG                                              ' cl_int

'// Context APIs

DECLARE FUNCTION clCreateContext IMPORT "OpenCL.DLL" ALIAS "clCreateContext" ( _
   BYVAL properties AS DWORD _                          ' const cl_context_properties * /* properties */
 , BYVAL num_devices AS DWORD _                         ' cl_uint                       /* num_devices */
 , BYREF devices AS DWORD _                             ' const cl_device_id *          /* devices */
 , BYVAL pfn_notify AS DWORD _                          ' void (*pfn_notify)(const char *, const void *, size_t, void *) /* pfn_notify */
 , BYREF user_data AS ANY _                             ' void *                        /* user_data */
 , BYREF errcode_ret AS LONG _                          ' cl_int *                      /* errcode_ret */
 ) AS DWORD                                             ' cl_context

DECLARE FUNCTION clCreateContextFromType IMPORT "OpenCL.DLL" ALIAS "clCreateContextFromType" ( _
   BYVAL properties AS DWORD _                          ' const cl_context_properties * /* properties */
 , BYVAL device_type AS QUAD _                          ' cl_device_type                /* device_type */
 , BYVAL pfn_notify AS DWORD _                          ' void (*pfn_notify)(const char *, const void *, size_t, void *) /* pfn_notify */
 , BYREF user_data AS ANY _                             ' void *                        /* user_data */
 , BYREF errcode_ret AS LONG _                          ' cl_int *                      /* errcode_ret */
 ) AS DWORD                                             ' cl_context

DECLARE FUNCTION clRetainContext IMPORT "OpenCL.DLL" ALIAS "clRetainContext" ( _
   BYVAL context AS DWORD _                             ' cl_context /* context */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clReleaseContext IMPORT "OpenCL.DLL" ALIAS "clReleaseContext" ( _
   BYVAL context AS DWORD _                             ' cl_context /* context */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clGetContextInfo IMPORT "OpenCL.DLL" ALIAS "clGetContextInfo" ( _
   BYVAL context AS DWORD _                             ' cl_context         /* context */,
 , BYVAL param_name AS DWORD _                          ' cl_context_info    /* param_name */
 , BYVAL param_value_size AS DWORD _                    ' size_t             /* param_value_size */
 , BYREF param_value AS ANY _                           ' void *             /* param_value */
 , BYREF param_value_size_ret AS DWORD _                ' size_t *           /* param_value_size_ret */
 ) AS LONG                                              ' cl_int

'// Command Queue APIs

DECLARE FUNCTION clCreateCommandQueue IMPORT "OpenCL.DLL" ALIAS "clCreateCommandQueue" ( _
   BYVAL context AS DWORD _                             ' cl_context                     /* context */
 , BYVAL device AS DWORD _                              ' cl_device_id                   /* device */
 , BYVAL properties AS QUAD _                           ' cl_command_queue_properties    /* properties */
 , BYREF errcode_ret AS LONG _                          ' cl_int *                       /* errcode_ret */
 ) AS DWORD                                             ' cl_command_queue

DECLARE FUNCTION clRetainCommandQueue IMPORT "OpenCL.DLL" ALIAS "clRetainCommandQueue" ( _
   BYVAL command_queue AS DWORD _                       ' cl_command_queue /* command_queue */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clReleaseCommandQueue IMPORT "OpenCL.DLL" ALIAS "clReleaseCommandQueue" ( _
   BYVAL command_queue AS DWORD _                       ' cl_command_queue /* command_queue */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clGetCommandQueueInfo IMPORT "OpenCL.DLL" ALIAS "clGetCommandQueueInfo" ( _
   BYVAL command_queue AS DWORD _                       ' cl_command_queue      /* command_queue */
 , BYVAL param_name AS DWORD _                          ' cl_command_queue_info /* param_name */
 , BYVAL param_value_size AS DWORD _                    ' size_t                /* param_value_size */
 , BYREF param_value AS ANY _                           ' void *                /* param_value */
 , BYREF param_value_size_ret AS DWORD _                ' size_t *              /* param_value_size_ret */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clSetCommandQueueProperty IMPORT "OpenCL.DLL" ALIAS "clSetCommandQueueProperty" ( _
   BYVAL command_queue AS DWORD _                       ' cl_command_queue              /* command_queue */
 , BYVAL properties AS QUAD _                           ' cl_command_queue_properties   /* properties */
 , BYVAL enable AS DWORD _                              ' cl_bool                       /* enable */
 , BYREF old_properties AS QUAD _                       ' cl_command_queue_properties * /* old_properties */
 ) AS LONG                                              ' cl_int

'// Memory Object APIs

DECLARE FUNCTION clCreateBuffer IMPORT "OpenCL.DLL" ALIAS "clCreateBuffer" ( _
   BYVAL context AS DWORD _                             ' cl_context   /* context */
 , BYVAL flags AS QUAD _                                ' cl_mem_flags /* flags */
 , BYVAL size AS DWORD _                                ' size_t       /* size */
 , BYREF host_ptr AS ANY _                              ' void *       /* host_ptr */
 , BYREF errcode_ret AS LONG _                          ' cl_int *     /* errcode_ret */
 ) AS DWORD                                             ' cl_mem

DECLARE FUNCTION clCreateImage2D IMPORT "OpenCL.DLL" ALIAS "clCreateImage2D" ( _
   BYVAL context AS DWORD _                             ' cl_context              /* context */
 , BYVAL flags AS QUAD _                                ' cl_mem_flags            /* flags */
 , BYREF image_format AS cl_image_format _              ' const cl_image_format * /* image_format */
 , BYVAL image_width AS DWORD _                         ' size_t                  /* image_width */
 , BYVAL image_height AS DWORD _                        ' size_t                  /* image_height */
 , BYVAL image_row_pitch AS DWORD _                     ' size_t                  /* image_row_pitch */
 , BYREF host_ptr AS ANY _                              ' void *                  /* host_ptr */
 , BYREF errcode_ret AS LONG _                          ' cl_int *                /* errcode_ret */
 ) AS DWORD                                             ' cl_mem

DECLARE FUNCTION clCreateImage3D IMPORT "OpenCL.DLL" ALIAS "clCreateImage3D" ( _
   BYVAL context AS DWORD _                             ' cl_context              /* context */
 , BYVAL flags AS QUAD _                                ' cl_mem_flags            /* flags */
 , BYREF image_format AS cl_image_format _              ' const cl_image_format * /* image_format */
 , BYVAL image_width AS DWORD _                         ' size_t                  /* image_width */
 , BYVAL image_height AS DWORD _                        ' size_t                  /* image_height */
 , BYVAL image_depth AS DWORD _                         ' size_t                  /* image_depth */
 , BYVAL image_row_pitch AS DWORD _                     ' size_t                  /* image_row_pitch */
 , BYVAL image_slice_pitch AS DWORD _                   ' size_t                  /* image_slice_pitch */
 , BYREF host_ptr AS ANY _                              ' void *                  /* host_ptr */
 , BYREF errcode_ret AS LONG _                          ' cl_int *                /* errcode_ret */
 ) AS DWORD                                             ' cl_mem

DECLARE FUNCTION clRetainMemObject IMPORT "OpenCL.DLL" ALIAS "clRetainMemObject" ( _
   BYVAL memobj AS DWORD _                              ' cl_mem /* memobj */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clReleaseMemObject IMPORT "OpenCL.DLL" ALIAS "clReleaseMemObject" ( _
   BYVAL memobj AS DWORD _                              ' cl_mem /* memobj */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clGetSupportedImageFormats IMPORT "OpenCL.DLL" ALIAS "clGetSupportedImageFormats" ( _
   BYVAL context AS DWORD _                             ' cl_context           /* context */
 , BYVAL flags AS DWORD _                               ' cl_mem_flags         /* flags */
 , BYVAL image_type AS DWORD _                          ' cl_mem_object_type   /* image_type */
 , BYVAL num_entries AS DWORD _                         ' cl_uint              /* num_entries */
 , BYREF image_formats AS cl_image_format _             ' cl_image_format *    /* image_formats */
 , BYREF num_image_formats AS DWORD _                   ' cl_uint *            /* num_image_formats */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clGetMemObjectInfo IMPORT "OpenCL.DLL" ALIAS "clGetMemObjectInfo" ( _
   BYVAL memobj AS DWORD _                              ' cl_mem           /* memobj */
 , BYVAL param_name AS DWORD _                          ' cl_mem_info      /* param_name */
 , BYVAL param_value_size AS DWORD _                    ' size_t           /* param_value_size */
 , BYREF param_value AS ANY _                           ' void *           /* param_value */
 , BYREF param_value_size_ret AS DWORD _                ' size_t *         /* param_value_size_ret */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clGetImageInfo IMPORT "OpenCL.DLL" ALIAS "clGetImageInfo" ( _
   BYVAL image AS DWORD _                               ' cl_mem           /* image */
 , BYVAL param_name AS DWORD _                          ' cl_image_info    /* param_name */
 , BYVAL param_value_size AS DWORD _                    ' size_t           /* param_value_size */
 , BYREF param_value AS ANY _                           ' void *           /* param_value */
 , BYREF param_value_size_ret AS DWORD _                ' size_t *         /* param_value_size_ret */
 ) AS LONG                                              ' cl_int

'// Sampler APIs

DECLARE FUNCTION clCreateSampler IMPORT "OpenCL.DLL" ALIAS "clCreateSampler" ( _
   BYVAL context AS DWORD _                             ' cl_context          /* context */,
 , BYVAL normalized_coords AS DWORD _                   ' cl_bool             /* normalized_coords */,
 , BYVAL addressing_mode AS DWORD _                     ' cl_addressing_mode  /* addressing_mode */,
 , BYVAL filter_mode AS DWORD _                         ' cl_filter_mode      /* filter_mode */,
 , BYREF errcode_ret AS LONG _                          ' cl_int *            /* errcode_ret */
 ) AS DWORD                                             ' cl_sampler

DECLARE FUNCTION clRetainSampler IMPORT "OpenCL.DLL" ALIAS "clRetainSampler" ( _
   BYVAL samples AS DWORD _                             ' cl_sampler /* sampler */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clReleaseSampler IMPORT "OpenCL.DLL" ALIAS "clReleaseSampler" ( _
   BYVAL sampler AS DWORD _                             ' cl_sampler /* sampler */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clGetSamplerInfo IMPORT "OpenCL.DLL" ALIAS "clGetSamplerInfo" ( _
   BYVAL sampler AS DWORD _                             ' cl_sampler         /* sampler */
 , BYVAL param_name AS DWORD _                          ' cl_sampler_info    /* param_name */
 , BYVAL param_value_size AS DWORD _                    ' size_t             /* param_value_size */
 , BYREF param_value AS ANY _                           ' void *             /* param_value */
 , BYREF param_value_size_ret AS DWORD _                ' size_t *           /* param_value_size_ret */
 ) AS LONG                                              ' cl_int

'// Program Object APIs

DECLARE FUNCTION clCreateProgramWithSource IMPORT "OpenCL.DLL" ALIAS "clCreateProgramWithSource" ( _
   BYVAL context AS DWORD _                             ' cl_context        /* context */
 , BYVAL count AS DWORD _                               ' cl_uint           /* count */
 , BYREF strings AS STRING _                            ' const char **     /* strings */
 , BYREF lengths AS DWORD _                             ' const size_t *    /* lengths */
 , BYREF errcode_ret AS LONG _                          ' cl_int *          /* errcode_ret */
 ) AS DWORD                                             ' cl_program

DECLARE FUNCTION clCreateProgramWithBinary IMPORT "OpenCL.DLL" ALIAS "clCreateProgramWithBinary" ( _
   BYVAL context AS DWORD _                             ' cl_context             /* context */
 , BYVAL num_devices AS DWORD _                         ' cl_uint                /* num_devices */
 , BYREF device_list AS DWORD _                         ' const cl_device_id *   /* device_list */
 , BYREF lengths AS DWORD _                             ' const size_t *         /* lengths */
 , BYREF binaries AS STRING _                           ' const unsigned char ** /* binaries */
 , BYREF binary_status AS LONG _                        ' cl_int *               /* binary_status */
 , BYREF errcode_ret AS LONG _                          ' cl_int *               /* errcode_ret */
 ) AS DWORD                                             ' cl_program

DECLARE FUNCTION clRetainProgram IMPORT "OpenCL.DLL" ALIAS "clRetainProgram" ( _
   BYVAL program AS DWORD _                             ' cl_program /* program */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clReleaseProgram IMPORT "OpenCL.DLL" ALIAS "clReleaseProgram" ( _
   BYVAL program AS DWORD _                             ' cl_program /* program */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clBuildProgram IMPORT "OpenCL.DLL" ALIAS "clBuildProgram" ( _
   BYVAL program AS DWORD _                             ' cl_program           /* program */
 , BYVAL num_devices AS DWORD _                         ' cl_uint              /* num_devices */,
 , BYREF device_list AS DWORD _                         ' const cl_device_id * /* device_list */,
 , BYREF options AS ASCIIZ _                            ' const char *         /* options */,
 , BYVAL pfn_notify AS DWORD _                          ' void (*pfn_notify)(cl_program /* program */, void * /* user_data */),
 , BYREF user_data AS ANY _                             ' void *               /* user_data */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clUnloadCompiler IMPORT "OpenCL.DLL" ALIAS "clUnloadCompiler" ( _
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clGetProgramInfo IMPORT "OpenCL.DLL" ALIAS "clGetProgramInfo" ( _
   BYVAL program AS DWORD _                             ' cl_program         /* program */
 , BYVAL param_name AS DWORD _                          ' cl_program_info    /* param_name */
 , BYVAL param_value_size AS DWORD _                    ' size_t             /* param_value_size */
 , BYREF param_value AS ANY _                           ' void *             /* param_value */
 , BYREF param_value_size_ret AS DWORD _                ' size_t *           /* param_value_size_ret */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clGetProgramBuildInfo IMPORT "OpenCL.DLL" ALIAS "clGetProgramBuildInfo" ( _
   BYVAL program AS DWORD _                             ' cl_program            /* program */
 , BYVAL device AS DWORD _                              ' cl_device_id          /* device */
 , BYVAL param_name AS DWORD _                          ' cl_program_build_info /* param_name */
 , BYVAL param_value_size AS DWORD _                    ' size_t                /* param_value_size */
 , BYREF param_value AS ANY _                           ' void *                /* param_value */
 , BYREF param_value_size_ret AS DWORD _                ' size_t *              /* param_value_size_ret */
 ) AS LONG                                              ' cl_int

'// Kernel Object APIs

DECLARE FUNCTION clCreateKernel IMPORT "OpenCL.DLL" ALIAS "clCreateKernel" ( _
   BYVAL program AS DWORD _                             ' cl_program      /* program */
 , BYREF kernel_name AS ASCIIZ _                        ' const char *    /* kernel_name */
 , BYREF errcode_ret AS LONG _                          ' cl_int *        /* errcode_ret */
 ) AS DWORD                                             ' cl_kernel

DECLARE FUNCTION clCreateKernelsInProgram IMPORT "OpenCL.DLL" ALIAS "clCreateKernelsInProgram" ( _
   BYVAL program AS DWORD _                             ' cl_program     /* program */
 , BYVAL num_kernels AS DWORD _                         ' cl_uint        /* num_kernels */
 , BYREF kernels AS DWORD _                             ' cl_kernel *    /* kernels */
 , BYREF num_kernels_ret AS DWORD _                     ' cl_uint *      /* num_kernels_ret */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clRetainKernel IMPORT "OpenCL.DLL" ALIAS "clRetainKernel" ( _
   BYVAL kernel AS DWORD _                              ' cl_kernel    /* kernel */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clReleaseKernel IMPORT "OpenCL.DLL" ALIAS "clReleaseKernel" ( _
   BYVAL kernel AS DWORD _                              ' cl_kernel    /* kernel */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clSetKernelArg IMPORT "OpenCL.DLL" ALIAS "clSetKernelArg" ( _
   BYVAL kernel AS DWORD _                              ' cl_kernel    /* kernel */
 , BYVAL arg_index AS DWORD _                           ' cl_uint      /* arg_index */
 , BYVAL arg_size AS DWORD _                            ' size_t       /* arg_size */
 , BYREF arg_value AS ANY _                             ' const void * /* arg_value */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clGetKernelInfo IMPORT "OpenCL.DLL" ALIAS "clGetKernelInfo" ( _
   BYVAL kernel AS DWORD _                              ' cl_kernel       /* kernel */
 , BYVAL param_name AS DWORD _                          ' cl_kernel_info  /* param_name */
 , BYVAL param_value_size AS DWORD _                    ' size_t          /* param_value_size */
 , BYREF param_value AS ANY _                           ' void *          /* param_value */
 , BYREF param_value_size_ret AS DWORD _                ' size_t *        /* param_value_size_ret */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clGetKernelWorkGroupInfo IMPORT "OpenCL.DLL" ALIAS "clGetKernelWorkGroupInfo" ( _
   BYVAL kernel AS DWORD _                              ' cl_kernel                  /* kernel */
 , BYVAL device AS DWORD _                              ' cl_device_id               /* device */
 , BYVAL param_name AS DWORD _                          ' cl_kernel_work_group_info  /* param_name */
 , BYVAL param_value_size AS DWORD _                    ' size_t                     /* param_value_size */
 , BYREF param_value AS ANY _                           ' void *                     /* param_value */
 , BYREF param_value_size_ret AS DWORD _                ' size_t *                   /* param_value_size_ret */
 ) AS LONG                                              ' cl_int

'// Event Object APIs

DECLARE FUNCTION clWaitForEvents IMPORT "OpenCL.DLL" ALIAS "clWaitForEvents" ( _
   BYVAL num_events AS DWORD _                          ' cl_uint             /* num_events */,
 , BYREF event_list AS DWORD _                          ' const cl_event *    /* event_list */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clGetEventInfo IMPORT "OpenCL.DLL" ALIAS "clGetEventInfo" ( _
   BYVAL event AS DWORD _                               ' cl_event         /* event */
 , BYVAL param_name AS DWORD _                          ' cl_event_info    /* param_name */
 , BYVAL param_value_size AS DWORD _                    ' size_t           /* param_value_size */
 , BYREF param_value AS ANY _                           ' void *           /* param_value */
 , BYREF param_value_size_ret AS DWORD _                ' size_t *         /* param_value_size_ret */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clRetainEvent IMPORT "OpenCL.DLL" ALIAS "clRetainEvent" ( _
   BYVAL event AS DWORD _                               ' cl_event         /* event */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clReleaseEvent IMPORT "OpenCL.DLL" ALIAS "clReleaseEvent" ( _
   BYVAL event AS DWORD _                               ' cl_event         /* event */
 ) AS LONG                                              ' cl_int

'// Profiling APIs

DECLARE FUNCTION clGetEventProfilingInfo IMPORT "OpenCL.DLL" ALIAS "clGetEventProfilingInfo" ( _
   BYVAL event AS DWORD _                               ' cl_event            /* event */
 , BYVAL param_name AS DWORD _                          ' cl_profiling_info   /* param_name */
 , BYVAL param_value_size AS DWORD _                    ' size_t              /* param_value_size */
 , BYREF param_value AS ANY _                           ' void *              /* param_value */
 , BYREF param_value_size_ret AS DWORD _                ' size_t *            /* param_value_size_ret */
 ) AS LONG                                              ' cl_int

'// Flush and Finish APIs

DECLARE FUNCTION clFlush IMPORT "OpenCL.DLL" ALIAS "clFlush" ( _
   BYVAL command_queue AS DWORD _                       ' cl_command_queue /* command_queue */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clFinish IMPORT "OpenCL.DLL" ALIAS "clFinish" ( _
   BYVAL command_queue AS DWORD _                       ' cl_command_queue /* command_queue */
 ) AS LONG                                              ' cl_int

'// Enqueued Commands APIs

DECLARE FUNCTION clEnqueueReadBuffer IMPORT "OpenCL.DLL" ALIAS "clEnqueueReadBuffer" ( _
   BYVAL command_queue AS DWORD _                       ' cl_command_queue    /* command_queue */
 , BYVAL buffer AS DWORD _                              ' cl_mem              /* buffer */
 , BYVAL blocking_read AS DWORD _                       ' cl_bool             /* blocking_read */
 , BYVAL offset AS DWORD _                              ' size_t              /* offset */
 , BYVAL cb AS DWORD _                                  ' size_t              /* cb */
 , BYREF ptr AS ANY _                                   ' void *              /* ptr */
 , BYVAL num_events_in_wait_list AS DWORD _             ' cl_uint             /* num_events_in_wait_list */
 , BYREF event_wait_list AS DWORD _                     ' const cl_event *    /* event_wait_list */
 , BYREF event AS DWORD _                               ' cl_event *          /* event */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clEnqueueWriteBuffer IMPORT "OpenCL.DLL" ALIAS "clEnqueueWriteBuffer" ( _
   BYVAL command_queue AS DWORD _                       ' cl_command_queue   /* command_queue */
 , BYVAL buffer AS DWORD _                              ' cl_mem             /* buffer */
 , BYVAL blocking_write AS DWORD _                      ' cl_bool            /* blocking_write */
 , BYVAL offset AS DWORD _                              ' size_t             /* offset */
 , BYVAL cb AS DWORD _                                  ' size_t             /* cb */
 , BYREF ptr AS ANY _                                   ' const void *       /* ptr */
 , BYVAL num_events_in_wait_list AS DWORD _             ' cl_uint            /* num_events_in_wait_list */
 , BYREF event_wait_list AS DWORD _                     ' const cl_event *   /* event_wait_list */
 , BYREF event AS DWORD _                               ' cl_event *         /* event */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clEnqueueCopyBuffer IMPORT "OpenCL.DLL" ALIAS "clEnqueueCopyBuffer" ( _
   BYVAL command_queue AS DWORD _                       ' cl_command_queue    /* command_queue */
 , BYVAL src_buffer AS DWORD _                          ' cl_mem              /* src_buffer */
 , BYVAL dst_buffer AS DWORD _                          ' cl_mem              /* dst_buffer */
 , BYVAL src_offset AS DWORD _                          ' size_t              /* src_offset */
 , BYVAL dst_offset AS DWORD _                          ' size_t              /* dst_offset */
 , BYVAL cb AS DWORD _                                  ' size_t              /* cb */
 , BYVAL num_events_in_wait_list AS DWORD _             ' cl_uint             /* num_events_in_wait_list */
 , BYREF event_wait_list AS DWORD _                     ' const cl_event *    /* event_wait_list */
 , BYREF event AS DWORD _                               ' cl_event *          /* event */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clEnqueueReadImage IMPORT "OpenCL.DLL" ALIAS "clEnqueueReadImage" ( _
   BYVAL command_queue AS DWORD _                       ' cl_command_queue /* command_queue */
 , BYVAL image AS DWORD _                               ' cl_mem           /* image */
 , BYVAL blocking_read AS DWORD _                       ' cl_bool          /* blocking_read */
 , BYREF origin AS DWORD _                              ' const size_t *   /* origin[3] */
 , BYREF region AS DWORD _                              ' const size_t *   /* region[3] */
 , BYVAL row_pitch AS DWORD _                           ' size_t           /* row_pitch */
 , BYVAL slice_pitch AS DWORD _                         ' size_t           /* slice_pitch */
 , BYREF ptr AS ANY _                                   ' void *           /* ptr */
 , BYVAL num_events_in_wait_list AS DWORD _             ' cl_uint          /* num_events_in_wait_list */
 , BYREF event_wait_list AS DWORD _                     ' const cl_event * /* event_wait_list */
 , BYREF event AS DWORD _                               ' cl_event *       /* event */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clEnqueueWriteImage IMPORT "OpenCL.DLL" ALIAS "clEnqueueWriteImage" ( _
   BYVAL command_queue AS DWORD _                       ' cl_command_queue /* command_queue */
 , BYVAL image AS DWORD _                               ' cl_mem           /* image */
 , BYVAL blocking_write AS DWORD _                      ' cl_bool          /* blocking_write */
 , BYREF origin AS DWORD _                              ' const size_t *   /* origin[3] */
 , BYREF region AS DWORD _                              ' const size_t *   /* region[3] */
 , BYVAL input_row_pitch AS DWORD _                     ' size_t           /* input_row_pitch */
 , BYVAL input_slice_pitch AS DWORD _                   ' size_t           /* input_slice_pitch */
 , BYREF ptr AS ANY _                                   ' void *           /* ptr */
 , BYVAL num_events_in_wait_list AS DWORD _             ' cl_uint          /* num_events_in_wait_list */
 , BYREF event_wait_list AS DWORD _                     ' const cl_event * /* event_wait_list */
 , BYREF event AS DWORD _                               ' cl_event *       /* event */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clEnqueueCopyImage IMPORT "OpenCL.DLL" ALIAS "clEnqueueCopyImage" ( _
   BYVAL command_queue AS DWORD _                       ' cl_command_queue /* command_queue */
 , BYVAL src_image AS DWORD _                           ' cl_mem           /* src_image */
 , BYVAL dst_image AS DWORD _                           ' cl_mem           /* dst_image */
 , BYREF src_origin AS DWORD _                          ' const size_t *   /* src_origin[3] */
 , BYREF dst_origin AS DWORD _                          ' const size_t *   /* dst_origin[3] */
 , BYREF region AS DWORD _                              ' const size_t *   /* region[3] */
 , BYVAL num_events_in_wait_list AS DWORD _             ' cl_uint          /* num_events_in_wait_list */
 , BYREF event_wait_list AS DWORD _                     ' const cl_event * /* event_wait_list */
 , BYREF event AS DWORD _                               ' cl_event *       /* event */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clEnqueueCopyImageToBuffer IMPORT "OpenCL.DLL" ALIAS "clEnqueueCopyImageToBuffer" ( _
   BYVAL command_queue AS DWORD _                       ' cl_command_queue /* command_queue */
 , BYVAL src_image AS DWORD _                           ' cl_mem           /* src_image */
 , BYVAL dst_buffer AS DWORD _                          ' cl_mem           /* dst_buffer */
 , BYREF src_origin AS DWORD _                          ' const size_t *   /* src_origin[3] */
 , BYREF region AS DWORD _                              ' const size_t *   /* region[3] */
 , BYVAL dst_offset AS DWORD _                          ' size_t           /* dst_offset */
 , BYVAL num_events_in_wait_list AS DWORD _             ' cl_uint          /* num_events_in_wait_list */
 , BYREF event_wait_list AS DWORD _                     ' const cl_event * /* event_wait_list */
 , BYREF event AS DWORD _                               ' cl_event *       /* event */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clEnqueueCopyBufferToImage IMPORT "OpenCL.DLL" ALIAS "clEnqueueCopyBufferToImage" ( _
   BYVAL command_queue AS DWORD _                       ' cl_command_queue /* command_queue */
 , BYVAL src_buffer AS DWORD _                          ' cl_mem           /* src_buffer */
 , BYVAL dst_image AS DWORD _                           ' cl_mem           /* dst_image */
 , BYVAL src_offset AS DWORD _                          ' size_t           /* src_offset */
 , BYREF dst_origin AS DWORD _                          ' const size_t *   /* dst_origin[3] */
 , BYREF region AS DWORD _                              ' const size_t *   /* region[3] */
 , BYVAL num_events_in_wait_list AS DWORD _             ' cl_uint          /* num_events_in_wait_list */
 , BYREF event_wait_list AS DWORD _                     ' const cl_event * /* event_wait_list */
 , BYREF event AS DWORD _                               ' cl_event *       /* event */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clEnqueueMapBuffer IMPORT "OpenCL.DLL" ALIAS "clEnqueueMapBuffer" ( _
   BYVAL command_queue AS DWORD _                       ' cl_command_queue /* command_queue */
 , BYVAL buffer AS DWORD _                              ' cl_mem           /* buffer */
 , BYVAL blocking_map AS DWORD _                        ' cl_bool          /* blocking_map */
 , BYVAL map_flags AS QUAD _                            ' cl_map_flags     /* map_flags */
 , BYVAL offset AS DWORD _                              ' size_t           /* offset */
 , BYVAL cb AS DWORD _                                  ' size_t           /* cb */
 , BYVAL num_events_in_wait_list AS DWORD _             ' cl_uint          /* num_events_in_wait_list */
 , BYREF event_wait_list AS DWORD _                     ' const cl_event * /* event_wait_list */
 , BYREF event AS DWORD _                               ' cl_event *       /* event */
 , BYREF errcode_ret AS LONG _                          ' cl_int *         /* errcode_ret */
 ) AS DWORD                                             ' void *

DECLARE FUNCTION clEnqueueMapImage IMPORT "OpenCL.DLL" ALIAS "clEnqueueMapImage" ( _
   BYVAL command_queue AS DWORD _                       ' cl_command_queue /* command_queue */
 , BYVAL image AS DWORD _                               ' cl_mem           /* image */
 , BYVAL blocking_map AS DWORD _                        ' cl_bool          /* blocking_map */
 , BYVAL map_flags AS QUAD _                            ' cl_map_flags     /* map_flags */
 , BYREF origin AS DWORD _                              ' const size_t *   /* origin[3] */
 , BYREF region AS DWORD _                              ' const size_t *   /* region[3] */
 , BYREF image_row_pitch AS DWORD _                     ' size_t *         /* image_row_pitch */
 , BYREF image_slice_pitch AS DWORD _                   ' size_t *         /* image_slice_pitch */
 , BYVAL num_events_in_wait_list AS DWORD _             ' cl_uint          /* num_events_in_wait_list */
 , BYREF event_wait_list AS DWORD _                     ' const cl_event * /* event_wait_list */
 , BYREF event AS DWORD _                               ' cl_event *       /* event */
 , BYREF errcode_ret AS LONG _                          ' cl_int *         /* errcode_ret */
 ) AS DWORD                                             ' void *

DECLARE FUNCTION clEnqueueUnmapMemObject IMPORT "OpenCL.DLL" ALIAS "clEnqueueUnmapMemObject" ( _
   BYVAL command_queue AS DWORD _                       ' cl_command_queue /* command_queue */
 , BYVAL memobj AS DWORD _                              ' cl_mem           /* memobj */
 , BYREF mapped_ptr AS ANY _                            ' void *           /* mapped_ptr */
 , BYVAL num_events_in_wait_list AS DWORD _             ' cl_uint          /* num_events_in_wait_list */
 , BYREF event_wait_list AS DWORD _                     ' const cl_event * /* event_wait_list */
 , BYREF event AS DWORD _                               ' cl_event *       /* event */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clEnqueueNDRangeKernel IMPORT "OpenCL.DLL" ALIAS "clEnqueueNDRangeKernel" ( _
   BYVAL command_queue AS DWORD _                       ' cl_command_queue /* command_queue */
 , BYVAL kernel AS DWORD _                              ' cl_kernel        /* kernel */
 , BYVAL work_dim AS DWORD _                            ' cl_uint          /* work_dim */
 , BYREF global_work_offset AS DWORD _                  ' const size_t *   /* global_work_offset */
 , BYREF global_work_size AS DWORD _                    ' const size_t *   /* global_work_size */
 , BYREF local_work_size AS DWORD _                     ' const size_t *   /* local_work_size */
 , BYVAL num_events_in_wait_list AS DWORD _             ' cl_uint          /* num_events_in_wait_list */
 , BYREF event_wait_list AS DWORD _                     ' const cl_event * /* event_wait_list */
 , BYREF event AS DWORD _                               ' cl_event *       /* event */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clEnqueueTask IMPORT "OpenCL.DLL" ALIAS "clEnqueueTask" ( _
   BYVAL command_queue AS DWORD _                       ' cl_command_queue /* command_queue */
 , BYVAL kernel AS DWORD _                              ' cl_kernel        /* kernel */
 , BYVAL num_events_in_wait_list AS DWORD _             ' cl_uint          /* num_events_in_wait_list */
 , BYREF event_wait_list AS DWORD _                     ' const cl_event * /* event_wait_list */
 , BYREF event AS DWORD _                               ' cl_event *       /* event */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clEnqueueNativeKernel IMPORT "OpenCL.DLL" ALIAS "clEnqueueNativeKernel" ( _
   BYVAL command_queue AS DWORD _                       ' cl_command_queue /* command_queue */
 , BYVAL user_func AS DWORD _                           ' void (*user_func)(void *)
 , BYREF args AS ANY _                                  ' void *           /* args */
 , BYVAL cb_args AS DWORD _                             ' size_t           /* cb_args */
 , BYVAL num_mem_objects AS DWORD _                     ' cl_uint          /* num_mem_objects */
 , BYREF mem_list AS DWORD _                            ' const cl_mem *   /* mem_list */
 , BYREF args_mem_loc AS DWORD _                        ' const void **    /* args_mem_loc */
 , BYVAL num_events_in_wait_list AS DWORD _             ' cl_uint          /* num_events_in_wait_list */
 , BYREF event_wait_list AS DWORD _                     ' const cl_event * /* event_wait_list */
 , BYREF event AS DWORD _                               ' cl_event *       /* event */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clEnqueueMarker IMPORT "OpenCL.DLL" ALIAS "clEnqueueMarker" ( _
   BYVAL command_queue AS DWORD _                       ' cl_command_queue /* command_queue */
 , BYREF event AS DWORD _                               ' cl_event *       /* event */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clEnqueueWaitForEvents IMPORT "OpenCL.DLL" ALIAS "clEnqueueWaitForEvents" ( _
   BYVAL command_queue AS DWORD _                       ' cl_command_queue /* command_queue */
 , BYVAL num_events AS DWORD _                          ' cl_uint          /* num_events */
 , BYREF event_list AS DWORD _                          ' const cl_event * /* event_list */
 ) AS LONG                                              ' cl_int

DECLARE FUNCTION clEnqueueBarrier IMPORT "OpenCL.DLL" ALIAS "clEnqueueBarrier" ( _
   BYVAL command_queue AS DWORD _                       ' cl_command_queue /* command_queue */
 ) AS LONG                                              ' cl_int

'// Extension function access
'//
'// Returns the extension function address for the given function name,
'// or NULL if a valid function can not be found.  The client must
'// check to make sure the address is not NULL, before using or
'// calling the returned function address.
'//
DECLARE FUNCTION clGetExtensionFunctionAddress IMPORT "OpenCL.DLL" ALIAS "clGetExtensionFunctionAddress" ( _
   BYREF func_name AS ASCIIZ _                          ' const char * /* func_name */
 ) AS DWORD                                             ' void *
