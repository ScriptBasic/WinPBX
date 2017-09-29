' ########################################################################################
' Microsoft Windows
' File: D3D10_1shader.inc
' Contents: D3D10.1 Shader Types and APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D3D10_1SHADER_INC = 1

#INCLUDE ONCE "d3d10shader.inc"

'//----------------------------------------------------------------------------
'// Shader debugging structures
'//----------------------------------------------------------------------------

'typedef enum D3D10_SHADER_DEBUG_REGTYPE
%D3D10_SHADER_DEBUG_REG_INPUT              = 0???
%D3D10_SHADER_DEBUG_REG_OUTPUT             = 1???
%D3D10_SHADER_DEBUG_REG_CBUFFER            = 2???
%D3D10_SHADER_DEBUG_REG_TBUFFER            = 3???
%D3D10_SHADER_DEBUG_REG_TEMP               = 4???
%D3D10_SHADER_DEBUG_REG_TEMPARRAY          = 5???
%D3D10_SHADER_DEBUG_REG_TEXTURE            = 6???
%D3D10_SHADER_DEBUG_REG_SAMPLER            = 7???
%D3D10_SHADER_DEBUG_REG_IMMEDIATECBUFFER   = 8???
%D3D10_SHADER_DEBUG_REG_LITERAL            = 9???
%D3D10_SHADER_DEBUG_REG_UNUSED             = 10???
%D3D11_SHADER_DEBUG_REG_INTERFACE_POINTERS = 11???
%D3D10_SHADER_DEBUG_REG_FORCE_DWORD        = &H7fffffff???

' enum D3D10_SHADER_DEBUG_SCOPETYPE
%D3D10_SHADER_DEBUG_SCOPE_GLOBAL      = 0???
%D3D10_SHADER_DEBUG_SCOPE_BLOCK       = 1???
%D3D10_SHADER_DEBUG_SCOPE_FORLOOP     = 2???
%D3D10_SHADER_DEBUG_SCOPE_STRUCT      = 3???
%D3D10_SHADER_DEBUG_SCOPE_FUNC_PARAMS = 4???
%D3D10_SHADER_DEBUG_SCOPE_STATEBLOCK  = 5???
%D3D10_SHADER_DEBUG_SCOPE_NAMESPACE   = 6???
%D3D10_SHADER_DEBUG_SCOPE_ANNOTATION  = 7???
%D3D10_SHADER_DEBUG_SCOPE_FORCE_DWORD = &H7fffffff???

' enum D3D10_SHADER_DEBUG_VARTYPE
%D3D10_SHADER_DEBUG_VAR_VARIABLE    = 0???
%D3D10_SHADER_DEBUG_VAR_FUNCTION    = 1???
%D3D10_SHADER_DEBUG_VAR_FORCE_DWORD = &H7fffffff???

'/////////////////////////////////////////////////////////////////////
'// These are the serialized structures that get written to the file
'/////////////////////////////////////////////////////////////////////

' // Size = 20 bytes
TYPE D3D10_SHADER_DEBUG_TOKEN_INFO DWORD
   File        AS DWORD   ' UINT // offset into file list
   Line        AS DWORD   ' UINT // line #
   Column      AS DWORD   ' UINT // column #
   TokenLength AS DWORD   ' UINT
   TokenId     AS DWORD   ' UINT // offset to LPCSTR of length TokenLength in string datastore
END TYPE

'// Variable list
' // Size = 24 bytes
TYPE D3D10_SHADER_DEBUG_VAR_INFO DWORD
   ' // Index into token list for declaring identifier
   TokenId        AS DWORD   ' UINT
   Type           AS DWORD   ' D3D10_SHADER_VARIABLE_TYPE
   ' // register and component for this variable, only valid/necessary for arrays
   Register       AS DWORD   ' UINT
   Component      AS DWORD   ' UINT
   ' // gives the original variable that declared this variable
   ScopeVar       AS DWORD   ' UINT
   ' // this variable's offset in its ScopeVar
   ScopeVarOffset AS DWORD   ' UINT
END TYPE

' // Size = 24 bytes
TYPE D3D10_SHADER_DEBUG_INPUT_INFO DWORD
   ' // index into array of variables of variable to initialize
   Var                AS DWORD   ' UINT
   ' // input, cbuffer, tbuffer
   InitialRegisterSet AS DWORD   ' D3D10_SHADER_DEBUG_REGTYPE
   ' // set to cbuffer or tbuffer slot, geometry shader input primitive #,
   ' // identifying register for indexable temp, or -1
   InitialBank        AS DWORD   ' UINT
   ' // -1 if temp, otherwise gives register in register set
   InitialRegister    AS DWORD   ' UINT
   ' // -1 if temp, otherwise gives component
   InitialComponent   AS DWORD   ' UINT
   ' // initial value if literal
   InitialValue       AS DWORD   ' UINT
END TYPE

' // Size = 44 bytes
TYPE D3D10_SHADER_DEBUG_SCOPEVAR_INFO DWORD
   ' // Index into variable token
   TokenId           AS DWORD   ' UINT
   VarType           AS DWORD   ' D3D10_SHADER_DEBUG_VARTYPE // variable or function (different namespaces)
   Class             AS DWORD   ' D3D10_SHADER_VARIABLE_CLASS
   Rows              AS DWORD   ' UINT // number of rows (matrices)
   Columns           AS DWORD   ' UINT // number of columns (vectors and matrices)
   ' // In an array of structures, one struct member scope is provided, and
   ' // you'll have to add the array stride times the index to the variable
   ' // index you find, then find that variable in this structure's list of
   ' // variables.
   ' // gives a scope to look up struct members. -1 if not a struct
   StructMemberScope AS DWORD   ' UINT
   ' // number of array indices
   uArrayIndices     AS DWORD   ' UINT // a[3][2][1] has 3 indices
   ' // maximum array index for each index
   ' // offset to UINT[uArrayIndices] in UINT datastore
   ArrayElements     AS DWORD   ' UINT // a[3][2][1] has {3, 2, 1}
   ' // how many variables each array index moves
   ' // offset to UINT[uArrayIndices] in UINT datastore
   ArrayStrides      AS DWORD   ' UINT // a[3][2][1] has {2, 1, 1}
   uVariables        AS DWORD   ' UINT
   ' // index of the first variable, later variables are offsets from this one
   uFirstVariable    AS DWORD   ' UINT
END TYPE

'// scope data, this maps variable names to debug variables (useful for the watch window)
' // Size = 20 bytes
TYPE D3D10_SHADER_DEBUG_SCOPE_INFO DWORD
   ScopeType    AS DWORD   ' D3D10_SHADER_DEBUG_SCOPETYPE
   Name         AS DWORD   ' UINT // offset to name of scope in strings list
   uNameLen     AS DWORD   ' UINT // length of name string
   uVariables   AS DWORD   ' UINT
   VariableData AS DWORD   ' UINT // Offset to UINT[uVariables] indexing the Scope Variable list
END TYPE

'// instruction outputs
' // Size = 36 bytes
TYPE D3D10_SHADER_DEBUG_OUTPUTVAR DWORD
   ' // index variable being written to, if -1 it's not going to a variable
   Var          AS LONG     ' INT
   ' // range data that the compiler expects to be true
   uValueMin    AS DWORD    ' UINT
   uValueMax    AS DWORD    ' UINT
   iValueMin    AS LONG     ' INT
   iValueMax    AS LONG     ' INT
   fValueMin    AS SINGLE   ' FLOAT
   fValueMax    AS SINGLE   ' FLOAT
   bNaNPossible AS LONG     ' BOOL
   bInfPossible AS LONG     ' BOOL
END TYPE

' // Size = 180 bytes
TYPE D3D10_SHADER_DEBUG_OUTPUTREG_INFO DWORD
   ' // Only temp, indexable temp, and output are valid here
   OutputRegisterSet   AS DWORD   ' D3D10_SHADER_DEBUG_REGTYPE
   ' // -1 means no output
   OutputReg           AS DWORD   ' UINT
   ' // if a temp array, identifier for which one
   TempArrayReg        AS DWORD   ' UINT
   ' // -1 means masked out
   OutputComponents(3) AS DWORD   ' UINT
   OutputVars(3)       AS D3D10_SHADER_DEBUG_OUTPUTVAR
   ' // when indexing the output, get the value of this register, then add
   ' // that to uOutputReg. If uIndexReg is -1, then there is no index.
   ' // find the variable whose register is the sum (by looking in the ScopeVar)
   ' // and component matches, then set it. This should only happen for indexable
   ' // temps and outputs.
   IndexReg            AS DWORD   ' UINT
   IndexComp           AS DWORD   ' UINT
END TYPE

'// per instruction data
' // Size = 396 bytes
TYPE D3D10_SHADER_DEBUG_INST_INFO DWORD
   Id               AS DWORD   ' UINT // Which instruction this is in the bytecode
   Opcode           AS DWORD   ' UINT // instruction type
   ' // 0, 1, or 2
   uOutputs         AS DWORD   ' UINT
   ' // up to two outputs per instruction
   pOutputs(1)      AS D3D10_SHADER_DEBUG_OUTPUTREG_INFO
   ' // index into the list of tokens for this instruction's token
   TokenId          AS DWORD   ' UINT
   ' // how many function calls deep this instruction is
   NestingLevel     AS DWORD   ' UINT
   ' // list of scopes from outer-most to inner-most
   ' // Number of scopes
   Scopes           AS DWORD   ' UINT
   ScopeInfo        AS DWORD   ' UINT // Offset to UINT[uScopes] specifying indices of the ScopeInfo Array
   ' // list of variables accessed by this instruction
   ' // Number of variables
   AccessedVars     AS DWORD   ' UINT
   AccessedVarsInfo AS DWORD   ' UINT // Offset to UINT[AccessedVars] specifying indices of the ScopeVariableInfo Array
END TYPE

' // Size = 16 bytes
TYPE D3D10_SHADER_DEBUG_FILE_INFO DWORD
   FileName    AS DWORD   ' UINT // Offset to LPCSTR for file name
   FileNameLen AS DWORD   ' UINT // Length of file name
   FileData    AS DWORD   ' UINT // Offset to LPCSTR of length FileLen
   FileLen     AS DWORD   ' UINT // Length of file
END TYPE

' // Size = 84 bytes
TYPE D3D10_SHADER_DEBUG_INFO DWORD
   Size              AS DWORD   ' UINT // sizeof(D3D10_SHADER_DEBUG_INFO)
   Creator           AS DWORD   ' UINT // Offset to LPCSTR for compiler version
   EntrypointName    AS DWORD   ' UINT // Offset to LPCSTR for Entry point name
   ShaderTarget      AS DWORD   ' UINT // Offset to LPCSTR for shader target
   CompileFlags      AS DWORD   ' UINT // flags used to compile
   Files             AS DWORD   ' UINT // number of included files
   FileInfo          AS DWORD   ' UINT // Offset to D3D10_SHADER_DEBUG_FILE_INFO[Files]
   Instructions      AS DWORD   ' UINT // number of instructions
   InstructionInfo   AS DWORD   ' UINT // Offset to D3D10_SHADER_DEBUG_INST_INFO[Instructions]
   Variables         AS DWORD   ' UINT // number of variables
   VariableInfo      AS DWORD   ' UINT // Offset to D3D10_SHADER_DEBUG_VAR_INFO[Variables]
   InputVariables    AS DWORD   ' UINT // number of variables to initialize before running
   InputVariableInfo AS DWORD   ' UINT // Offset to D3D10_SHADER_DEBUG_INPUT_INFO[InputVariables]
   Tokens            AS DWORD   ' UINT // number of tokens to initialize
   TokenInfo         AS DWORD   ' UINT // Offset to D3D10_SHADER_DEBUG_TOKEN_INFO[Tokens]
   Scopes            AS DWORD   ' UINT // number of scopes
   ScopeInfo         AS DWORD   ' UINT // Offset to D3D10_SHADER_DEBUG_SCOPE_INFO[Scopes]
   ScopeVariables    AS DWORD   ' UINT // number of variables declared
   ScopeVariableInfo AS DWORD   ' UINT // Offset to D3D10_SHADER_DEBUG_SCOPEVAR_INFO[Scopes]
   UintOffset        AS DWORD   ' UINT // Offset to the UINT datastore, all UINT offsets are from this offset
   StringOffset      AS DWORD   ' UINT // Offset to the string datastore, all string offsets are from this offset
END TYPE


' ########################################################################################
' ID3D10ShaderReflection1 interface
' IID = C3457783-A846-47CE-9520-CEA6F66E7447
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ID3D10ShaderReflection1_INTERFACE_DEFINED)
    %ID3D10ShaderReflection1_INTERFACE_DEFINED = 1

$IID_ID3D10ShaderReflection1 = GUID$("{C3457783-A846-47CE-9520-CEA6F66E7447}")

INTERFACE ID3D10ShaderReflection1 $IID_ID3D10ShaderReflection1

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 12
     BYREF pDesc AS D3D10_SHADER_DESC _                 ' __out D3D10_SHADER_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConstantBufferByIndex ( _                  ' VTable offset = 16
     BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS ID3D10ShaderReflectionConstantBuffer            ' ID3D10ShaderReflectionConstantBuffer *
   ' =====================================================================================
   METHOD GetConstantBufferByName ( _                   ' VTable offset = 20
     BYREF Name AS ASCIIZ _                             ' __in LPCSTR Name
   ) AS ID3D10ShaderReflectionConstantBuffer            ' ID3D10ShaderReflectionConstantBuffer *
   ' =====================================================================================
   METHOD GetResourceBindingDesc ( _                    ' VTable offset = 24
     BYVAL ResourceIndex AS DWORD _                     ' __in  UINT ResourceIndex
   , BYREF pDesc AS D3D10_SHADER_INPUT_BIND_DESC _      ' __out D3D10_SHADER_INPUT_BIND_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputParameterDesc ( _                     ' VTable offset = 28
     BYVAL ParameterIndex AS DWORD _                    ' __in  UINT ParameterIndex
   , BYREF pDesc AS D3D10_SIGNATURE_PARAMETER_DESC _    ' __out D3D10_SIGNATURE_PARAMETER_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputParameterDesc ( _                    ' VTable offset = 32
     BYVAL ParameterIndex AS DWORD _                    ' __in  UINT ParameterIndex
   , BYREF pDesc AS D3D10_SIGNATURE_PARAMETER_DESC _    ' __out D3D10_SIGNATURE_PARAMETER_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVariableByName ( _                         ' VTable offset = 36
     BYREF ASCIIZ _                                     ' __in LPCSTR Name
   ) AS ID3D10ShaderReflectionVariable                  ' ID3D10ShaderReflectionVariable*
   ' =====================================================================================
   METHOD GetResourceBindingDescByName ( _              ' VTable offset = 40
     BYREF Name AS ASCIIZ _                             ' __in  LPCSTR Name
   , BYREF pDesc AS D3D10_SHADER_INPUT_BIND_DESC _      ' __out D3D10_SHADER_INPUT_BIND_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMovInstructionCount ( _                    ' VTable offset = 44
     BYREF pCount AS DWORD _                            ' __out UINT* pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMovcInstructionCount ( _                   ' VTable offset = 48
     BYREF pCount AS DWORD _                            ' __out UINT* pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConversionInstructionCount ( _             ' VTable offset = 52
     BYREF pCount AS DWORD _                            ' __out UINT* pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBitwiseInstructionCount ( _                ' VTable offset = 56
     BYREF pCount AS DWORD _                            ' __out UINT* pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGSInputPrimitive ( _                       ' VTable offset = 60
     BYREF pPrim AS DWORD _                             ' __out D3D10_PRIMITIVE* pPrim
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsLevel9Shader ( _                            ' VTable offset = 64
     BYREF pbLevel9Shader AS LONG _                     ' __out BOOL* pbLevel9Shader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsSampleFrequencyShader ( _                   ' VTable offset = 68
     BYREF pbSampleFrequency AS LONG _                  ' __out BOOL* pbSampleFrequency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10ShaderReflection1_INTERFACE_DEFINED__ */
