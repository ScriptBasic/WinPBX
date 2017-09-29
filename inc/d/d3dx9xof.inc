' ########################################################################################
' Microsoft Windows
' File: d3dx9xof.inc
' Contents: D3DX .X File types and functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D3DX9XOF_INC = 1

#INCLUDE ONCE "d3dx9.inc"

'//----------------------------------------------------------------------------
'// D3DXF_FILEFORMAT
'//   This flag is used to specify what file type to use when saving to disk.
'//   _BINARY, and _TEXT are mutually exclusive, while
'//   _COMPRESSED is an optional setting that works with all file types.
'//----------------------------------------------------------------------------

'typedef DWORD D3DXF_FILEFORMAT;

%D3DXF_FILEFORMAT_BINARY         = 0
%D3DXF_FILEFORMAT_TEXT           = 1
%D3DXF_FILEFORMAT_COMPRESSED     = 2

'//----------------------------------------------------------------------------
'// D3DXF_FILESAVEOPTIONS
'//   This flag is used to specify where to save the file to. Each flag is
'//   mutually exclusive, indicates the data location of the file, and also
'//   chooses which additional data will specify the location.
'//   _TOFILE is paired with a filename (LPCSTR)
'//   _TOWFILE is paired with a filename (LPWSTR)
'//----------------------------------------------------------------------------

'typedef DWORD D3DXF_FILESAVEOPTIONS;

%D3DXF_FILESAVE_TOFILE    = &H00???
%D3DXF_FILESAVE_TOWFILE   = &H01???

'//----------------------------------------------------------------------------
'// D3DXF_FILELOADOPTIONS
'//   This flag is used to specify where to load the file from. Each flag is
'//   mutually exclusive, indicates the data location of the file, and also
'//   chooses which additional data will specify the location.
'//   _FROMFILE is paired with a filename (LPCSTR)
'//   _FROMWFILE is paired with a filename (LPWSTR)
'//   _FROMRESOURCE is paired with a (D3DXF_FILELOADRESOUCE*) description.
'//   _FROMMEMORY is paired with a (D3DXF_FILELOADMEMORY*) description.
'//----------------------------------------------------------------------------

'typedef DWORD D3DXF_FILELOADOPTIONS;

%D3DXF_FILELOAD_FROMFILE     = &H00???
%D3DXF_FILELOAD_FROMWFILE    = &H01???
%D3DXF_FILELOAD_FROMRESOURCE = &H02???
%D3DXF_FILELOAD_FROMMEMORY   = &H03???

'//----------------------------------------------------------------------------
'// D3DXF_FILELOADRESOURCE:
'//----------------------------------------------------------------------------

' // Size = 12 bytes
TYPE D3DXF_FILELOADRESOURCE DWORD
   hModule AS DWORD        ' HMODULE
   lpName  AS ASCIIZ PTR   ' LPCSTR
   lpType  AS ASCIIZ PTR   ' LPCSTR
END TYPE

'//----------------------------------------------------------------------------
'// D3DXF_FILELOADMEMORY:
'//----------------------------------------------------------------------------

' // Size = 8 bytes
TYPE D3DXF_FILELOADMEMORY DWORD
   lpMemory AS DWORD   ' LPCVOID
   dSize    AS DWORD   ' SIZE_T
END TYPE

$IID_ID3DXFile           = GUID$("{CEF08CF9-7B4F-4429-9624-2A690A933201}")
$IID_ID3DXFileSaveObject = GUID$("{CEF08CFA-7B4F-4429-9624-2A690A933201}")
$IID_ID3DXFileSaveData   = GUID$("{CEF08CFB-7B4F-4429-9624-2A690A933201}")
$IID_ID3DXFileEnumObject = GUID$("{CEF08CFC-7B4F-4429-9624-2A690A933201}")
$IID_ID3DXFileData       = GUID$("{CEF08CFD-7B4F-4429-9624-2A690A933201}")


'//////////////////////////////////////////////////////////////////////////////
'// ID3DXFile /////////////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

INTERFACE ID3DXFile $IID_ID3DXFile

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateEnumObject ( _                          ' VTable offset = 12
     BYVAL pvSource AS DWORD _                          ' __in  LPCVOID pvSource
   , BYVAL loadflags AS DWORD _                         ' __in  D3DXF_FILELOADOPTIONS loadflags
   , BYREF ppEnumObj AS ID3DXFileEnumObject _           ' __out ID3DXFileEnumObject ** ppEnumObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSaveObject ( _                          ' VTable offset = 16
     BYVAL pData AS DWORD _                             ' __in  LPCVOID pData
   , BYVAL flags AS DWORD _                             ' __in  D3DXF_FILESAVEOPTIONS flags
   , BYVAL dwFileFormat AS DWORD _                      ' __in  D3DXF_FILEFORMAT dwFileFormat
   , BYREF ppSaveObj AS ID3DXFileSaveObject _           ' __out ID3DXFileSaveObject ** ppSaveObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterTemplates ( _                         ' VTable offset = 20
     BYVAL pvData AS DWORD _                            ' __in LPCVOID pvData
   , BYVAL cbSize AS DWORD _                            ' __in SIZE_T cbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterEnumTemplates ( _                     ' VTable offset = 24
     BYVAL pEnum AS ID3DXFileEnumObject _               ' __in ID3DXFileEnumObject * pEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

'//////////////////////////////////////////////////////////////////////////////
'// ID3DXFileSaveObject ///////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

INTERFACE ID3DXFileSaveObject $IID_ID3DXFileSaveObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetFile ( _                                   ' VTable offset = 12
     BYREF ppFile AS ID3DXFile _                        ' __out ID3DXFile ** ppFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddDataObject ( _                             ' VTable offset = 16
     BYREF rguidTemplate AS GUID _                      ' __in  REFGUID rguidTemplate
   , BYREF szName AS ASCIIZ _                           ' __in  LPCSTR szName
   , BYREF pId AS GUID _                                ' __in  CONST GUID * pId
   , BYVAL cbSize AS DWORD _                            ' __in  SIZE_T cbSize
   , BYVAL pvData AS DWORD _                            ' __in  LPCVOID pvData
   , BYREF ppObj AS ID3DXFileSaveData _                 ' __out ID3DXFileSaveData ** ppObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'//////////////////////////////////////////////////////////////////////////////
'// ID3DXFileSaveData /////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

INTERFACE ID3DXFileSaveData $IID_ID3DXFileSaveData

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSave ( _                                   ' VTable offset = 12
     BYREF ppObj AS ID3DXFileSaveObject _               ' __in ID3DXFileSaveObject ** ppObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 16
     BYREF szName AS ASCIIZ _                           ' __in  LPSTR szName
   , BYREF puiSize AS DWORD _                           ' __out SIZE_T * puiSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetId ( _                                     ' VTable offset = 20
     BYREF pId AS GUID _                                ' __out LPGUID pId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 24
     BYREF type AS GUID _                               ' __out GUID * type
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddDataObject ( _                             ' VTable offset = 28
     BYREF rguidTemplate AS GUID _                      ' __in  REFGUID rguidTemplate
   , BYREF szName AS ASCIIZ _                           ' __in  LPCSTR szName
   , BYREF pId AS GUID _                                ' __in  CONST GUID * pId
   , BYVAL cbSize AS DWORD _                            ' __in  SIZE_T cbSize
   , BYVAL pvData AS DWORD _                            ' __in  LPCVOID pvData
   , BYREF ppObj AS ID3DXFileSaveData _                 ' __out ID3DXFileSaveData ** ppObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddDataReference ( _                          ' VTable offset = 32
     BYREF szName AS ASCIIZ _                           ' __in LPCSTR szName
   , BYREF pId AS GUID _                                ' __in CONST GUID * pId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'//////////////////////////////////////////////////////////////////////////////
'// ID3DXFileEnumObject ///////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

INTERFACE ID3DXFileEnumObject $IID_ID3DXFileEnumObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetFile ( _                                   ' VTable offset = 12
     BYREF ppFile AS ID3DXFile _                        ' __out ID3DXFile ** ppFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChildren ( _                               ' VTable offset = 16
     BYREF puiChildren AS DWORD _                       ' __out SIZE_T * puiChildren
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChild ( _                                  ' VTable offset = 20
     BYVAL id AS DWORD _                                ' __in  SIZE_T id
   , BYREF ppObj AS ID3DXFileData _                     ' __out ID3DXFileData ** ppObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDataObjectById ( _                         ' VTable offset = 24
     BYREF rguid AS GUID _                              ' __in  REFGUID rguid
   , BYREF ppDataObj AS ID3DXFileData _                 ' __out LPD3DXFILEDATA * ppDataObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDataObjectByName ( _                       ' VTable offset = 28
     BYREF szName AS ASCIIZ _                           ' __in  LPCSTR szName
   , BYREF ppDataObj AS ID3DXFileData _                 ' __out LPD3DXFILEDATA * ppDataObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'//////////////////////////////////////////////////////////////////////////////
'// ID3DXFileData /////////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

INTERFACE ID3DXFileData $IID_ID3DXFileData

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetEnum ( _                                   ' VTable offset = 12
     BYREF ppObj AS ID3DXFileEnumObject _               ' __out ID3DXFileEnumObject ** ppObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 16
     BYREF szName AS ASCIIZ _                           ' __in  LPSTR szName
   , BYREF puiSize AS DWORD _                           ' __out SIZE_T * puiSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetId ( _                                     ' VTable offset = 20
     BYREF pId AS GUID _                                ' __out LPGUID pId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Lock ( _                                      ' VTable offset = 24
     BYREF pSize AS DWORD _                             ' __out SIZE_T * pSize
   , BYREF ppData AS DWORD _                            ' __out CONST VOID ** ppData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unlock ( _                                    ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 32
     BYREF pType AS GUID _                              ' __out CONST GUID * pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsReference ( _                               ' VTable offset = 36
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD GetChildren ( _                               ' VTable offset = 40
     BYREF puiChildren AS DWORD _                       ' __out SIZE_T * puiChildren
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD GetChild ( _                                  ' VTable offset = 44
     BYVAL uiChild AS DWORD _                           ' __in  SIZE_T uiChild
   , BYREF ppChild AS ID3DXFileData _                   ' __out ID3DXFileData ** ppChild
   ) AS LONG                                            ' BOOL
   ' =====================================================================================

END INTERFACE


' Creates an instance of an ID3DXFile object.
DECLARE FUNCTION D3DXFileCreate IMPORT $D3DX_DLLNAME ALIAS "D3DXFileCreate" (_
   BYREF lplpDirectXFile AS ID3DXFile _                 ' __out ID3DXFile** lplpDirectXFile
   ) AS LONG                                            ' HRESULT

'/*
' * DirectX File errors.
' */

'#define _FACD3DXF 0x876
%FACD3DXF = &H876

%D3DXFERR_BADOBJECT             = &H88760384&   ' MAKE_HRESULT( 1, _FACD3DXF, 900 )
%D3DXFERR_BADVALUE              = &H88760385&   ' MAKE_HRESULT( 1, _FACD3DXF, 901 )
%D3DXFERR_BADTYPE               = &H88760386&   ' MAKE_HRESULT( 1, _FACD3DXF, 902 )
%D3DXFERR_NOTFOUND              = &H88760387&   ' MAKE_HRESULT( 1, _FACD3DXF, 903 )
%D3DXFERR_NOTDONEYET            = &H88760388&   ' MAKE_HRESULT( 1, _FACD3DXF, 904 )
%D3DXFERR_FILENOTFOUND          = &H88760389&   ' MAKE_HRESULT( 1, _FACD3DXF, 905 )
%D3DXFERR_RESOURCENOTFOUND      = &H8876038A&   ' MAKE_HRESULT( 1, _FACD3DXF, 906 )
%D3DXFERR_BADRESOURCE           = &H8876038B&   ' MAKE_HRESULT( 1, _FACD3DXF, 907 )
%D3DXFERR_BADFILETYPE           = &H8876038C&   ' MAKE_HRESULT( 1, _FACD3DXF, 908 )
%D3DXFERR_BADFILEVERSION        = &H8876038D&   ' MAKE_HRESULT( 1, _FACD3DXF, 909 )
%D3DXFERR_BADFILEFLOATSIZE      = &H8876038E&   ' MAKE_HRESULT( 1, _FACD3DXF, 910 )
%D3DXFERR_BADFILE               = &H8876038F&   ' MAKE_HRESULT( 1, _FACD3DXF, 911 )
%D3DXFERR_PARSEERROR            = &H88760390&   ' MAKE_HRESULT( 1, _FACD3DXF, 912 )
%D3DXFERR_BADARRAYSIZE          = &H88760391&   ' MAKE_HRESULT( 1, _FACD3DXF, 913 )
%D3DXFERR_BADDATAREFERENCE      = &H88760392&   ' MAKE_HRESULT( 1, _FACD3DXF, 914 )
%D3DXFERR_NOMOREOBJECTS         = &H88760393&   ' MAKE_HRESULT( 1, _FACD3DXF, 915 )
%D3DXFERR_NOMOREDATA            = &H88760394&   ' MAKE_HRESULT( 1, _FACD3DXF, 916 )
%D3DXFERR_BADCACHEFILE          = &H88760395&   ' MAKE_HRESULT( 1, _FACD3DXF, 917 )
