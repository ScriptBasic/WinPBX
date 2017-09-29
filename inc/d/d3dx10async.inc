' ########################################################################################
' Microsoft Windows
' File: D3DX10Async.inc
' Contents: D3DX10 Asynchronous Effect / Shader loaders / compilers
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D3DX10ASYNC_INC = 1

#INCLUDE ONCE "d3dx10.inc"

'//----------------------------------------------------------------------------
'// D3DX10Compile:
'// ------------------
'// Compiles an effect or shader.
'//
'// Parameters:
'//  pSrcFile
'//      Source file name.
'//  hSrcModule
'//      Module handle. if NULL, current module will be used.
'//  pSrcResource
'//      Resource name in module.
'//  pSrcData
'//      Pointer to source code.
'//  SrcDataLen
'//      Size of source code, in bytes.
'//  pDefines
'//      Optional NULL-terminated array of preprocessor macro definitions.
'//  pInclude
'//      Optional interface pointer to use for handling #include directives.
'//      If this parameter is NULL, #includes will be honored when compiling
'//      from file, and will error when compiling from resource or memory.
'//  pFunctionName
'//      Name of the entrypoint function where execution should begin.
'//  pProfile
'//      Instruction set to be used when generating code.  Currently supported
'//      profiles are "vs_1_1", "vs_2_0", "vs_2_a", "vs_2_sw", "ps_2_0",
'//      "ps_2_a", "ps_2_sw", "tx_1_0"
'//  Flags1
'//      See D3D10_SHADER_xxx flags.
'//  Flags2
'//      See D3D10_EFFECT_xxx flags.
'//  ppShader
'//      Returns a buffer containing the created shader.  This buffer contains
'//      the compiled shader code, as well as any embedded debug and symbol
'//      table info.  (See D3D10GetShaderConstantTable)
'//  ppErrorMsgs
'//      Returns a buffer containing a listing of errors and warnings that were
'//      encountered during the compile.  If you are running in a debugger,
'//      these are the same messages you will see in your debug output.
'//  pHResult
'//      Pointer to a memory location to receive the return value upon completion.
'//      Maybe NULL if not needed.
'//      If pPump != NULL, pHResult must be a valid memory location until the
'//      the asynchronous execution completes.
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DX10CompileFromFileA IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CompileFromFileA" ( _
   BYREF pSrcFile AS ASCIIZ _                           ' __in  LPCSTR pSrcFile
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO* pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3D10INCLUDE pInclude
 , BYREF pFunctionName AS ASCIIZ _                      ' __in  LPCSTR pFunctionName
 , BYREF pProfile AS ASCIIZ _                           ' __in  LPCSTR pProfile
 , BYVAL Flags1 AS DWORD _                              ' __in  UINT Flags1
 , BYVAL Flags2 AS DWORD _                              ' __in  UINT Flags2
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump* pPump
 , BYREF ppShader AS ID3D10Blob _                       ' __out ID3D10Blob** ppShader
 , BYREF ppErrorMsgs AS ID3D10Blob _                    ' __out ID3D10Blob** ppErrorMsgs
 , BYREF pHResult AS LONG _                             ' __out HRESULT* pHResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10CompileFromFileW IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CompileFromFileW" ( _
   BYREF pSrcFile AS WSTRINGZ _                         ' __in  LPCWSTR pSrcFile
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO* pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3D10INCLUDE pInclude
 , BYREF pFunctionName AS ASCIIZ _                      ' __in  LPCSTR pFunctionName
 , BYREF pProfile AS ASCIIZ _                           ' __in  LPCSTR pProfile
 , BYVAL Flags1 AS DWORD _                              ' __in  UINT Flags1
 , BYVAL Flags2 AS DWORD _                              ' __in  UINT Flags2
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump* pPump
 , BYREF ppShader AS ID3D10Blob _                       ' __out ID3D10Blob** ppShader
 , BYREF ppErrorMsgs AS ID3D10Blob _                    ' __out ID3D10Blob** ppErrorMsgs
 , BYREF pHResult AS LONG _                             ' __out HRESULT* pHResult
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DX10CompileFromFile = D3DX10CompileFromFileW
#ELSE
   MACRO D3DX10CompileFromFile = D3DX10CompileFromFileA
#ENDIF

DECLARE FUNCTION D3DX10CompileFromResourceA IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CompileFromResourceA" ( _
   BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE hSrcModule
 , BYREF pSrcResource AS ASCIIZ _                       ' __in  LPCSTR pSrcResource
 , BYREF pSrcFileName AS ASCIIZ _                       ' __in  LPCSTR pSrcFileName
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO* pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3D10INCLUDE pInclude
 , BYREF pFunctionName AS ASCIIZ _                      ' __in  LPCSTR pFunctionName
 , BYREF pProfile AS ASCIIZ _                           ' __in  LPCSTR pProfile
 , BYVAL Flags1 AS DWORD _                              ' __in  UINT Flags1
 , BYVAL Flags2 AS DWORD _                              ' __in  UINT Flags2
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump* pPump
 , BYREF ppShader AS ID3D10Blob _                       ' __out ID3D10Blob** ppShader
 , BYVAL ppErrorMsgs AS ID3D10Blob _                    ' __out ID3D10Blob** ppErrorMsgs
 , BYREF pHResult AS LONG _                             ' __out HRESULT* pHResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10CompileFromResourceW IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CompileFromResourceW" ( _
   BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE hSrcModule
 , BYREF pSrcResource AS WSTRINGZ _                     ' __in  LPCWSTR pSrcResource
 , BYREF pSrcFileName AS WSTRINGZ _                     ' __in  LPCWSTR pSrcFileName
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO* pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3D10INCLUDE pInclude
 , BYREF pFunctionName AS ASCIIZ _                      ' __in  LPCSTR pFunctionName
 , BYREF pProfile AS ASCIIZ _                           ' __in  LPCSTR pProfile
 , BYVAL Flags1 AS DWORD _                              ' __in  UINT Flags1
 , BYVAL Flags2 AS DWORD _                              ' __in  UINT Flags2
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump* pPump
 , BYREF ppShader AS ID3D10Blob _                       ' __out ID3D10Blob** ppShader
 , BYVAL ppErrorMsgs AS ID3D10Blob _                    ' __out ID3D10Blob** ppErrorMsgs
 , BYREF pHResult AS LONG _                             ' __out HRESULT* pHResult
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DX10CompileFromResource = D3DX10CompileFromResourceW
#ELSE
   MACRO D3DX10CompileFromResource = D3DX10CompileFromResourceA
#ENDIF

DECLARE FUNCTION D3DX10CompileFromMemory IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CompileFromMemory" ( _
   BYREF pSrcData AS ASCIIZ _                           ' __in  LPCSTR pSrcData
 , BYVAL SrcDataLen AS DWORD _                          ' __in  SIZE_T SrcDataLen
 , BYREF pFileName AS ASCIIZ _                          ' __in  LPCSTR pFileName
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO* pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3D10INCLUDE pInclude
 , BYREF pFunctionName AS ASCIIZ _                      ' __in  LPCSTR pFunctionName
 , BYREF pProfile AS ASCIIZ _                           ' __in  LPCSTR pProfile
 , BYVAL Flags1 AS DWORD _                              ' __in  UINT Flags1
 , BYVAL Flags2 AS DWORD _                              ' __in  UINT Flags2
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump* pPump
 , BYREF ppShader AS ID3D10Blob _                       ' __out ID3D10Blob** ppShader
 , BYVAL ppErrorMsgs AS ID3D10Blob _                    ' __out ID3D10Blob** ppErrorMsgs
 , BYREF pHResult AS LONG _                             ' __out HRESULT* pHResult
 ) AS LONG                                              ' HRESULT

'//----------------------------------------------------------------------------
'// D3DX10CreateEffectFromXXXX:
'// --------------------------
'// Creates an effect from a binary effect or file
'//
'// Parameters:
'//
'// [in]
'//
'//
'//  pFileName
'//      Name of the ASCII (uncompiled) or binary (compiled) Effect file to load
'//
'//  hModule
'//      Handle to the module containing the resource to compile from
'//  pResourceName
'//      Name of the resource within hModule to compile from
'//
'//  pData
'//      Blob of effect data, either ASCII (uncompiled) or binary (compiled)
'//  DataLength
'//      Length of the data blob
'//
'//  pDefines
'//      Optional NULL-terminated array of preprocessor macro definitions.
'//  pInclude
'//      Optional interface pointer to use for handling #include directives.
'//      If this parameter is NULL, #includes will be honored when compiling
'//      from file, and will error when compiling from resource or memory.
'//  pProfile
'//      Profile to use when compiling the effect.
'//  HLSLFlags
'//      Compilation flags pertaining to shaders and data types, honored by
'//      the HLSL compiler
'//  FXFlags
'//      Compilation flags pertaining to Effect compilation, honored
'//      by the Effect compiler
'//  pDevice
'//      Pointer to the D3D10 device on which to create Effect resources
'//  pEffectPool
'//      Pointer to an Effect pool to share variables with or NULL
'//
'// [out]
'//
'//  ppEffect
'//      Address of the newly created Effect interface
'//  ppEffectPool
'//      Address of the newly created Effect pool interface
'//  ppErrors
'//      If non-NULL, address of a buffer with error messages that occurred
'//      during parsing or compilation
'//  pHResult
'//      Pointer to a memory location to receive the return value upon completion.
'//      Maybe NULL if not needed.
'//      If pPump != NULL, pHResult must be a valid memory location until the
'//      the asynchronous execution completes.
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DX10CreateEffectFromFileA IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateEffectFromFileA" ( _
   BYREF pFileName AS ASCIIZ _                          ' __in  LPCSTR pFileName
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO *pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  ID3D10Include *pInclude
 , BYREF pProfile AS ASCIIZ _                           ' __in  LPCSTR pProfile
 , BYVAL HLSLFlags AS DWORD _                           ' __in  UINT HLSLFlags
 , BYVAL FXFlags AS DWORD _                             ' __in  UINT FXFlags
 , BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device *pDevice
 , BYVAL pEffectPool AS ID3D10EffectPool _              ' __in  ID3D10EffectPool *pEffectPool
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump* pPump
 , BYREF ppEffect AS ID3D10Effect _                     ' __out ID3D10Effect **ppEffect
 , BYREF ppErrors AS ID3D10Blob _                       ' __out ID3D10Blob **ppErrors
 , BYREF pHResult AS LONG _                             ' __out HRESULT* pHResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10CreateEffectFromFileW IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateEffectFromFileW" ( _
   BYREF pFileName AS WSTRINGZ _                        ' __in  LPCWSTR pFileName
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO *pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  ID3D10Include *pInclude
 , BYREF pProfile AS ASCIIZ _                           ' __in  LPCSTR pProfile
 , BYVAL HLSLFlags AS DWORD _                           ' __in  UINT HLSLFlags
 , BYVAL FXFlags AS DWORD _                             ' __in  UINT FXFlags
 , BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device *pDevice
 , BYVAL pEffectPool AS ID3D10EffectPool _              ' __in  ID3D10EffectPool *pEffectPool
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump* pPump
 , BYREF ppEffect AS ID3D10Effect _                     ' __out ID3D10Effect **ppEffect
 , BYREF ppErrors AS ID3D10Blob _                       ' __out ID3D10Blob **ppErrors
 , BYREF pHResult AS LONG _                             ' __out HRESULT* pHResult
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DX10CreateEffectFromFile = D3DX10CreateEffectFromFileW
#ELSE
   MACRO D3DX10CreateEffectFromFile = D3DX10CreateEffectFromFileA
#ENDIF

DECLARE FUNCTION D3DX10CreateEffectFromMemory IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateEffectFromMemory" ( _
   BYVAL pData AS DWORD _                               ' __in  LPCVOID pData
 , BYVAL DataLength AS DWORD _                          ' __in  SIZE_T DataLength
 , BYREF pSrcFileName AS ASCIIZ _                       ' __in  LPCSTR pSrcFileName
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO *pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  ID3D10Include *pInclude
 , BYREF pProfile AS ASCIIZ _                           ' __in  LPCSTR pProfile
 , BYVAL HLSLFlags AS DWORD _                           ' __in  UINT HLSLFlags
 , BYVAL FXFlags AS DWORD _                             ' __in  UINT FXFlags
 , BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device *pDevice
 , BYVAL pEffectPool AS ID3D10EffectPool _              ' __in  ID3D10EffectPool *pEffectPool
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump* pPump
 , BYREF ppEffect AS ID3D10Effect _                     ' __out ID3D10Effect **ppEffect
 , BYREF ppErrors AS ID3D10Blob _                       ' __out ID3D10Blob **ppErrors
 , BYREF pHResult AS LONG _                             ' __out HRESULT* pHResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10CreateEffectFromResourceA IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateEffectFromResourceA" ( _
   BYVAL hModule AS DWORD _                             ' __in  HMODULE hModule
 , BYREF pResourceName AS ASCIIZ _                      ' __in  LPCSTR pResourceName
 , BYREF pSrcFileName AS ASCIIZ _                       ' __in  LPCSTR pSrcFileName
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO *pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  ID3D10Include *pInclude
 , BYREF pProfile AS ASCIIZ _                           ' __in  LPCSTR pProfile
 , BYVAL HLSLFlags AS DWORD _                           ' __in  UINT HLSLFlags
 , BYVAL FXFlags AS DWORD _                             ' __in  UINT FXFlags
 , BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device *pDevice
 , BYVAL pEffectPool AS ID3D10EffectPool _              ' __in  ID3D10EffectPool *pEffectPool
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump* pPump
 , BYREF ppEffect AS ID3D10Effect _                     ' __out ID3D10Effect **ppEffect
 , BYREF ppErrors AS ID3D10Blob _                       ' __out ID3D10Blob **ppErrors
 , BYREF pHResult AS LONG _                             ' __out HRESULT* pHResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10CreateEffectFromResourceW IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateEffectFromResourceW" ( _
   BYVAL hModule AS DWORD _                             ' __in  HMODULE hModule
 , BYREF pResourceName AS WSTRINGZ _                    ' __in  LPCWSTR pResourceName
 , BYREF pSrcFileName AS WSTRINGZ _                     ' __in  LPCWSTR pSrcFileName
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO *pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  ID3D10Include *pInclude
 , BYREF pProfile AS ASCIIZ _                           ' __in  LPCSTR pProfile
 , BYVAL HLSLFlags AS DWORD _                           ' __in  UINT HLSLFlags
 , BYVAL FXFlags AS DWORD _                             ' __in  UINT FXFlags
 , BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device *pDevice
 , BYVAL pEffectPool AS ID3D10EffectPool _              ' __in  ID3D10EffectPool *pEffectPool
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump* pPump
 , BYREF ppEffect AS ID3D10Effect _                     ' __out ID3D10Effect **ppEffect
 , BYREF ppErrors AS ID3D10Blob _                       ' __out ID3D10Blob **ppErrors
 , BYREF pHResult AS LONG _                             ' __out HRESULT* pHResult
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DX10CreateEffectFromResource = D3DX10CreateEffectFromResourceW
#ELSE
   MACRO D3DX10CreateEffectFromResource = D3DX10CreateEffectFromResourceA
#ENDIF

DECLARE FUNCTION D3DX10CreateEffectPoolFromFileA IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateEffectPoolFromFileA" ( _
   BYREF pFileName AS ASCIIZ _                          ' __in  LPCSTR pFileName
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO *pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  ID3D10Include *pInclude
 , BYREF pProfile AS ASCIIZ _                           ' __in  LPCSTR pProfile
 , BYVAL HLSLFlags AS DWORD _                           ' __in  UINT HLSLFlags
 , BYVAL FXFlags AS DWORD _                             ' __in  UINT FXFlags
 , BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device *pDevice
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump* pPump
 , BYREF ppEffectPool AS ID3D10EffectPool _             ' __out ID3D10EffectPool **ppEffectPool
 , BYREF ppErrors AS ID3D10Blob _                       ' __out ID3D10Blob **ppErrors
 , BYREF pHResult AS LONG _                             ' __out HRESULT* pHResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10CreateEffectPoolFromFileW IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateEffectPoolFromFileW" ( _
   BYREF pFileName AS WSTRINGZ _                        ' __in  LPCWSTR pFileName
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO *pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  ID3D10Include *pInclude
 , BYREF pProfile AS ASCIIZ _                           ' __in  LPCSTR pProfile
 , BYVAL HLSLFlags AS DWORD _                           ' __in  UINT HLSLFlags
 , BYVAL FXFlags AS DWORD _                             ' __in  UINT FXFlags
 , BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device *pDevice
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump* pPump
 , BYREF ppEffectPool AS ID3D10EffectPool _             ' __out ID3D10EffectPool **ppEffectPool
 , BYREF ppErrors AS ID3D10Blob _                       ' __out ID3D10Blob **ppErrors
 , BYREF pHResult AS LONG _                             ' __out HRESULT* pHResult
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DX10CreateEffectPoolFromFile = D3DX10CreateEffectPoolFromFileW
#ELSE
   MACRO D3DX10CreateEffectPoolFromFile = D3DX10CreateEffectPoolFromFileA
#ENDIF

DECLARE FUNCTION D3DX10CreateEffectPoolFromMemory IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateEffectPoolFromMemory" ( _
   BYVAL pData AS DWORD _                               ' __in  LPCVOID pData
 , BYVAL DataLength AS DWORD _                          ' __in  SIZE_T DataLength
 , BYREF pSrcFileName AS ASCIIZ _                       ' __in  LPCSTR pSrcFileName
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO *pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  ID3D10Include *pInclude
 , BYREF pProfile AS ASCIIZ _                           ' __in  LPCSTR pProfile
 , BYVAL HLSLFlags AS DWORD _                           ' __in  UINT HLSLFlags
 , BYVAL FXFlags AS DWORD _                             ' __in  UINT FXFlags
 , BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device *pDevice
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump* pPump
 , BYREF ppEffectPool AS ID3D10EffectPool _             ' __out ID3D10EffectPool **ppEffectPool
 , BYREF ppErrors AS ID3D10Blob _                       ' __out ID3D10Blob **ppErrors
 , BYREF pHResult AS LONG _                             ' __out HRESULT* pHResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10CreateEffectPoolFromResourceA IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateEffectPoolFromResourceA" ( _
   BYVAL hModule AS DWORD _                             ' __in  HMODULE hModule
 , BYREF pResourceName AS ASCIIZ _                      ' __in  LPCSTR pResourceName
 , BYREF pSrcFileName AS ASCIIZ _                       ' __in  LPCSTR pSrcFileName
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO *pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  ID3D10Include *pInclude
 , BYREF pProfile AS ASCIIZ _                           ' __in  LPCSTR pProfile
 , BYVAL HLSLFlags AS DWORD _                           ' __in  UINT HLSLFlags
 , BYVAL FXFlags AS DWORD _                             ' __in  UINT FXFlags
 , BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device *pDevice
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump* pPump
 , BYREF ppEffectPool AS ID3D10EffectPool _             ' __out ID3D10EffectPool **ppEffectPool
 , BYREF ppErrors AS ID3D10Blob _                       ' __out ID3D10Blob **ppErrors
 , BYREF pHResult AS LONG _                             ' __out HRESULT* pHResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10CreateEffectPoolFromResourceW IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateEffectPoolFromResourceW" ( _
   BYVAL hModule AS DWORD _                             ' __in  HMODULE hModule
 , BYREF pResourceName AS WSTRINGZ _                    ' __in  LPCWSTR pResourceName
 , BYREF pSrcFileName AS WSTRINGZ _                     ' __in  LPCWSTR pSrcFileName
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO *pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  ID3D10Include *pInclude
 , BYREF pProfile AS ASCIIZ _                           ' __in  LPCSTR pProfile
 , BYVAL HLSLFlags AS DWORD _                           ' __in  UINT HLSLFlags
 , BYVAL FXFlags AS DWORD _                             ' __in  UINT FXFlags
 , BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device *pDevice
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump* pPump
 , BYREF ppEffectPool AS ID3D10EffectPool _             ' __out ID3D10EffectPool **ppEffectPool
 , BYREF ppErrors AS ID3D10Blob _                       ' __out ID3D10Blob **ppErrors
 , BYREF pHResult AS LONG _                             ' __out HRESULT* pHResult
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DX10CreateEffectPoolFromResource = D3DX10CreateEffectPoolFromResourceW
#ELSE
   MACRO D3DX10CreateEffectPoolFromResource = D3DX10CreateEffectPoolFromResourceA
#ENDIF

DECLARE FUNCTION D3DX10PreprocessShaderFromFileA IMPORT $D3DX10_DLLNAME ALIAS "D3DX10PreprocessShaderFromFileA" ( _
   BYREF pFileName AS ASCIIZ _                          ' __in  LPCSTR pFileName
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO *pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  ID3D10Include *pInclude
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump* pPump
 , BYREF ppShaderText AS ID3D10Blob _                   ' __out ID3D10Blob **ppShaderText
 , BYREF ppErrors AS ID3D10Blob _                       ' __out ID3D10Blob **ppErrors
 , BYREF pHResult AS LONG _                             ' __out HRESULT* pHResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10PreprocessShaderFromFileW IMPORT $D3DX10_DLLNAME ALIAS "D3DX10PreprocessShaderFromFileW" ( _
   BYREF pFileName AS WSTRINGZ _                        ' __in  LPCWSTR pFileName
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO *pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  ID3D10Include *pInclude
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump* pPump
 , BYREF ppShaderText AS ID3D10Blob _                   ' __out ID3D10Blob **ppShaderText
 , BYREF ppErrors AS ID3D10Blob _                       ' __out ID3D10Blob **ppErrors
 , BYREF pHResult AS LONG _                             ' __out HRESULT* pHResult
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DX10PreprocessShaderFromFile = D3DX10PreprocessShaderFromFileW
#ELSE
   MACRO D3DX10PreprocessShaderFromFile = D3DX10PreprocessShaderFromFileA
#ENDIF

DECLARE FUNCTION D3DX10PreprocessShaderFromMemory IMPORT $D3DX10_DLLNAME ALIAS "D3DX10PreprocessShaderFromMemory" ( _
   BYREF pSrcData AS ASCIIZ _                           ' __in  LPCSTR pSrcData
 , BYVAL SrcDataSize AS DWORD _                         ' __in  SIZE_T SrcDataSize
 , BYREF pFileName AS ASCIIZ _                          ' __in  LPCSTR pFileName
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO* pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3D10INCLUDE pInclude
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump *pPump
 , BYREF ppShaderText AS ID3D10Blob _                   ' __out ID3D10Blob** ppShaderText
 , BYREF ppErrorMsgs AS ID3D10Blob _                    ' __out ID3D10Blob** ppErrorMsgs
 , BYREF pHResult AS LONG _                             ' __out HRESULT* pHResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10PreprocessShaderFromResourceA IMPORT $D3DX10_DLLNAME ALIAS "D3DX10PreprocessShaderFromResourceA" ( _
   BYVAL hModule AS DWORD _                             ' __in  HMODULE hModule
 , BYREF pResourceName AS ASCIIZ _                      ' __in  LPCSTR pResourceName
 , BYREF pSrcFileName AS ASCIIZ _                       ' __in  LPCSTR pSrcFileName
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO* pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3D10INCLUDE pInclude
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump *pPump
 , BYREF ppShaderText AS ID3D10Blob _                   ' __out ID3D10Blob** ppShaderText
 , BYREF ppErrorMsgs AS ID3D10Blob _                    ' __out ID3D10Blob** ppErrorMsgs
 , BYREF pHResult AS LONG _                             ' __out HRESULT* pHResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10PreprocessShaderFromResourceW IMPORT $D3DX10_DLLNAME ALIAS "D3DX10PreprocessShaderFromResourceW" ( _
   BYVAL hModule AS DWORD _                             ' __in  HMODULE hModule
 , BYREF pResourceName AS WSTRINGZ _                    ' __in  LPCWSTR pResourceName
 , BYREF pSrcFileName AS WSTRINGZ _                     ' __in  LPCWSTR pSrcFileName
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO* pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3D10INCLUDE pInclude
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump *pPump
 , BYREF ppShaderText AS ID3D10Blob _                   ' __out ID3D10Blob** ppShaderText
 , BYREF ppErrorMsgs AS ID3D10Blob _                    ' __out ID3D10Blob** ppErrorMsgs
 , BYREF pHResult AS LONG _                             ' __out HRESULT* pHResult
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DX10PreprocessShaderFromResource = D3DX10PreprocessShaderFromResourceW
#ELSE
   MACRO D3DX10PreprocessShaderFromResource = D3DX10PreprocessShaderFromResourceA
#ENDIF

'//----------------------------------------------------------------------------
'// Async processors
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DX10CreateAsyncCompilerProcessor IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateAsyncCompilerProcessor" ( _
   BYREF pFileName AS ASCIIZ _                          ' __in  LPCSTR pFileName
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO* pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3D10INCLUDE pInclude
 , BYREF pFunctionName AS ASCIIZ _                      ' __in  LPCSTR pFunctionName
 , BYREF pProfile AS ASCIIZ _                           ' __in  LPCSTR pProfile
 , BYVAL Flags1 AS DWORD _                              ' __in  UINT Flags1
 , BYVAL Flags2 AS DWORD _                              ' __in  UINT Flags2
 , BYREF ppCompiledShader AS ID3D10Blob _               ' __out ID3D10Blob **ppCompiledShader
 , BYREF ppErrorBuffer AS ID3D10Blob _                  ' __out ID3D10Blob **ppErrorBuffer
 , BYREF ppProcessor AS DWORD _                         ' __out ID3DX10DataProcessor **ppProcessor
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10CreateAsyncEffectCreateProcessor IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateAsyncEffectCreateProcessor" ( _
   BYREF pFileName AS ASCIIZ _                          ' __in  LPCSTR pFileName
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO* pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3D10INCLUDE pInclude
 , BYREF pProfile AS ASCIIZ _                           ' __in  LPCSTR pProfile
 , BYVAL Flags1 AS DWORD _                              ' __in  UINT Flags1
 , BYVAL FXFlags AS DWORD _                             ' __in  UINT FXFlags
 , BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device *pDevice
 , BYVAL pPool AS ID3D10EffectPool _                    ' __in  ID3D10EffectPool *pPool
 , BYREF ppErrorBuffer AS ID3D10Blob _                  ' __out ID3D10Blob **ppErrorBuffer
 , BYREF ppProcessor AS DWORD _                         ' __out ID3DX10DataProcessor **ppProcessor
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10CreateAsyncEffectPoolCreateProcessor IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateAsyncEffectPoolCreateProcessor" ( _
   BYREF pFileName AS ASCIIZ _                          ' __in  LPCSTR pFileName
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO* pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3D10INCLUDE pInclude
 , BYREF pProfile AS ASCIIZ _                           ' __in  LPCSTR pProfile
 , BYVAL Flags1 AS DWORD _                              ' __in  UINT Flags1
 , BYVAL FXFlags AS DWORD _                             ' __in  UINT FXFlags
 , BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device *pDevice
 , BYVAL pPool AS ID3D10EffectPool _                    ' __in  ID3D10EffectPool *pPool
 , BYREF ppErrorBuffer AS ID3D10Blob _                  ' __out ID3D10Blob **ppErrorBuffer
 , BYREF ppProcessor AS DWORD _                         ' __out ID3DX10DataProcessor **ppProcessor
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10CreateAsyncShaderPreprocessProcessor IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateAsyncShaderPreprocessProcessor" ( _
   BYREF pFileName AS ASCIIZ _                          ' __in  LPCSTR pFileName
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO* pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3D10INCLUDE pInclude
 , BYREF ppShaderText AS ID3D10Blob _                   ' __out ID3D10Blob **ppShaderText
 , BYREF ppErrorBuffer AS ID3D10Blob _                  ' __out ID3D10Blob **ppErrorBuffer
 , BYREF ppProcessor AS DWORD _                         ' __out ID3DX10DataProcessor **ppProcessor
 ) AS LONG                                              ' HRESULT


'//----------------------------------------------------------------------------
'// D3DX10 Asynchronous texture I/O (advanced mode)
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DX10CreateAsyncFileLoaderW IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateAsyncFileLoaderW" ( _
   BYREF pFileName AS WSTRINGZ _                        ' __in  LPCWSTR pFileName
 , BYREF ppDataLoader AS DWORD _                        ' __out ID3DX10DataLoader **ppDataLoader
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10CreateAsyncFileLoaderA IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateAsyncFileLoaderA" ( _
   BYREF pFileName AS ASCIIZ _                          ' __in  LPCSTR pFileName
 , BYREF ppDataLoader AS DWORD _                        ' __out ID3DX10DataLoader **ppDataLoader
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DX10CreateAsyncFileLoader = D3DX10CreateAsyncFileLoaderW
#ELSE
   MACRO D3DX10CreateAsyncFileLoader = D3DX10CreateAsyncFileLoaderA
#ENDIF

DECLARE FUNCTION D3DX10CreateAsyncMemoryLoader IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateAsyncMemoryLoader" ( _
   BYVAL pData AS DWORD _                               ' __in  LPCVOID pData
 , BYVAL cbData AS DWORD _                              ' __in  SIZE_T cbData
 , BYREF ppDataLoader AS DWORD _                        ' __out ID3DX10DataLoader **ppDataLoader
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10CreateAsyncResourceLoaderW IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateAsyncResourceLoaderW" ( _
   BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE hSrcModule
 , BYREF pSrcResource AS WSTRINGZ _                     ' __in  LPCWSTR pSrcResource
 , BYREF ppDataLoader AS DWORD _                        ' __out ID3DX10DataLoader **ppDataLoader
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10CreateAsyncResourceLoaderA IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateAsyncResourceLoaderA" ( _
   BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE hSrcModule
 , BYREF pSrcResource AS ASCIIZ _                       ' __in  LPCSTR pSrcResource
 , BYREF ppDataLoader AS DWORD _                        ' __out ID3DX10DataLoader **ppDataLoader
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DX10CreateAsyncResourceLoader = D3DX10CreateAsyncResourceLoaderW
#ELSE
   MACRO D3DX10CreateAsyncResourceLoader = D3DX10CreateAsyncResourceLoaderA
#ENDIF

DECLARE FUNCTION D3DX10CreateAsyncTextureProcessor IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateAsyncTextureProcessor" ( _
   BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device *pDevice
 , BYREF pLoadInfo AS D3DX10_IMAGE_LOAD_INFO _          ' __in  D3DX10_IMAGE_LOAD_INFO *pLoadInfo
 , BYREF ppDataProcessor AS DWORD _                     ' __out ID3DX10DataProcessor **ppDataProcessor
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10CreateAsyncTextureInfoProcessor IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateAsyncTextureInfoProcessor" ( _
   BYREF pLoadInfo AS D3DX10_IMAGE_LOAD_INFO _          ' __in  D3DX10_IMAGE_LOAD_INFO *pLoadInfo
 , BYREF ppDataProcessor AS DWORD _                     ' __out ID3DX10DataProcessor **ppDataProcessor
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10CreateAsyncShaderResourceViewProcessor IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateAsyncShaderResourceViewProcessor" ( _
   BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device *pDevice
 , BYREF pLoadInfo AS D3DX10_IMAGE_LOAD_INFO _          ' __in  D3DX10_IMAGE_LOAD_INFO *pLoadInfo
 , BYREF ppDataProcessor AS DWORD _                     ' __out ID3DX10DataProcessor **ppDataProcessor
 ) AS LONG                                              ' HRESULT
