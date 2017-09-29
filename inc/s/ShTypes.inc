' ########################################################################################
' Microsoft Windows
' File: ShTypes.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SHTYPES_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "wtypes.inc"

'//===========================================================================
'//
'// Object identifiers in the explorer's name space (ItemID and IDList)
'//
'//  All the items that the user can browse with the explorer (such as files,
'// directories, servers, work-groups, etc.) has an identifier which is unique
'// among items within the parent folder. Those identifiers are called item
'// IDs (SHITEMID). Since all its parent folders have their own item IDs,
'// any items can be uniquely identified by a list of item IDs, which is called
'// an ID list (ITEMIDLIST).
'//
'//  ID lists are almost always allocated by the task allocator (see some
'// description below as well as OLE 2.0 SDK) and may be passed across
'// some of shell interfaces (such as IShellFolder). Each item ID in an ID list
'// is only meaningful to its parent folder (which has generated it), and all
'// the clients must treat it as an opaque binary data except the first two
'// bytes, which indicates the size of the item ID.
'//
'//  When a shell extension -- which implements the IShellFolder interace --
'// generates an item ID, it may put any information in it, not only the data
'// with that it needs to identifies the item, but also some additional
'// information, which would help implementing some other functions efficiently.
'// For example, the shell's IShellFolder implementation of file system items
'// stores the primary (long) name of a file or a directory as the item
'// identifier, but it also stores its alternative (short) name, size and date
'// etc.
'//
'//  When an ID list is passed to one of shell APIs (such as SHGetPathFromIDList),
'// it is always an absolute path -- relative from the root of the name space,
'// which is the desktop folder. When an ID list is passed to one of IShellFolder
'// member function, it is always a relative path from the folder (unless it
'// is explicitly specified).
'//
'//===========================================================================
'//
'// SHITEMID -- Item ID  (mkid)
'//     USHORT      cb;             // Size of the ID (including cb itself)
'//     BYTE        abID[];         // The item ID (variable length)
'//
'#include <pshpack1.h>
' // Size = 3 bytes
TYPE SHITEMID BYTE
   cb       AS WORD   ' USHORT cb
   abID (0) AS BYTE   ' BYTE abID[ 1 ]
END TYPE
MACRO ShortItemId = SHITEMID   ' name used by PB's includes
'#include <poppack.h>

'//
'// ITEMIDLIST -- List if item IDs (combined with 0-terminator)
'//
'#include <pshpack1.h>
' // Size = 3 bytes
TYPE ITEMIDLIST BYTE
   mkid AS SHITEMID   ' SHITEMID mkid
END TYPE
'#include <poppack.h>

'//-------------------------------------------------------------------------
'//
'// struct STRRET
'//
'// structure for returning strings from IShellFolder member functions
'//
'//-------------------------------------------------------------------------
'//
'//  uType indicate which union member to use
'//    STRRET_WSTR    Use STRRET.pOleStr     must be freed by caller of GetDisplayNameOf
'//    STRRET_OFFSET  Use STRRET.uOffset     Offset into SHITEMID for ANSI string
'//    STRRET_CSTR    Use STRRET.cStr        ANSI Buffer
'//

' STRRET_TYPE enum
%STRRET_WSTR   = 0
%STRRET_OFFSET = &H1
%STRRET_CSTR   = &H2

'#include <pshpack8.h>
'typedef struct _STRRET
'    {
'    UINT uType;
'    /* [switch_is][switch_type] */ union
'        {
'        /* [case()][string] */ LPWSTR pOleStr;
'        /* [case()] */ UINT uOffset;
'        /* [case()] */ char cStr[ 260 ];
'        }    DUMMYUNIONNAME;
'    }    STRRET;

' // Size = 260 bytes
UNION STRRETUNION
   pOleStr AS WSTRINGZ PTR   ' LPWSTR pOleStr
   uOffset AS DWORD          ' UINT uOffset
   cStr    AS ASCIIZ * 260   ' char cStr[ 260 ]
END UNION

' // Size = 264 bytes
TYPE STRRET DWORD
   uType AS DWORD
   STRRETUNION
END TYPE
'#include <poppack.h>

'//-------------------------------------------------------------------------
'//
'// struct SHELLDETAILS
'//
'// structure for returning strings from IShellDetails
'//
'//-------------------------------------------------------------------------
'//
'//  fmt;            // LVCFMT_* value (header only)
'//  cxChar;         // Number of 'average' characters (header only)
'//  str;            // String information
'//
'#include <pshpack1.h>
' // Size = 272 bytes
TYPE SHELLDETAILS BYTE
   fmt    AS LONG     ' int fmt
   cxChar AS LONG     ' int cxChar
   str    AS STRRET   ' STRRET str
END TYPE
'#include <poppack.h>

'#if (_WIN32_IE >= _WIN32_IE_IE60SP2)
' enum PERCEIVED
%PERCEIVED_TYPE_FIRST       = -3
%PERCEIVED_TYPE_CUSTOM      = -3
%PERCEIVED_TYPE_UNSPECIFIED = -2
%PERCEIVED_TYPE_FOLDER      = -1
%PERCEIVED_TYPE_UNKNOWN     = 0
%PERCEIVED_TYPE_TEXT        = 1
%PERCEIVED_TYPE_IMAGE       = 2
%PERCEIVED_TYPE_AUDIO       = 3
%PERCEIVED_TYPE_VIDEO       = 4
%PERCEIVED_TYPE_COMPRESSED  = 5
%PERCEIVED_TYPE_DOCUMENT    = 6
%PERCEIVED_TYPE_SYSTEM      = 7
%PERCEIVED_TYPE_APPLICATION = 8
%PERCEIVED_TYPE_GAMEMEDIA   = 9
%PERCEIVED_TYPE_CONTACTS    = 10
%PERCEIVED_TYPE_LAST        = 10

%PERCEIVEDFLAG_UNDEFINED     = &H0000???
%PERCEIVEDFLAG_SOFTCODED     = &H0001???
%PERCEIVEDFLAG_HARDCODED     = &H0002???
%PERCEIVEDFLAG_NATIVESUPPORT = &H0004???
%PERCEIVEDFLAG_GDIPLUS       = &H0010???
%PERCEIVEDFLAG_WMSDK         = &H0020???
%PERCEIVEDFLAG_ZIPFOLDER     = &H0040???
'typedef DWORD PERCEIVEDFLAG;

'#endif  // _WIN32_IE_IE60SP2

'#if (NTDDI_VERSION >= NTDDI_VISTA)
' // Size = 8 bytes
TYPE COMDLG_FILTERSPEC DWORD
   pszName AS WSTRINGZ PTR   ' LPCWSTR
   pszSpec AS WSTRINGZ PTR   ' LPCWSTR
END TYPE

'typedef DWORD KF_REDIRECT_FLAGS;
'typedef GUID KNOWNFOLDERID;

'#endif  // NTDDI_VISTA

' enum SHCOLSTATE
%SHCOLSTATE_DEFAULT            = 0???
%SHCOLSTATE_TYPE_STR           = &H1???
%SHCOLSTATE_TYPE_INT           = &H2???
%SHCOLSTATE_TYPE_DATE          = &H3???
%SHCOLSTATE_TYPEMASK           = &Hf???
%SHCOLSTATE_ONBYDEFAULT        = &H10???
%SHCOLSTATE_SLOW               = &H20???
%SHCOLSTATE_EXTENDED           = &H40???
%SHCOLSTATE_SECONDARYUI        = &H80???
%SHCOLSTATE_HIDDEN             = &H100???
%SHCOLSTATE_PREFER_VARCMP      = &H200???
%SHCOLSTATE_PREFER_FMTCMP      = &H400???
%SHCOLSTATE_NOSORTBYFOLDERNESS = &H800???
%SHCOLSTATE_VIEWONLY           = &H10000???
%SHCOLSTATE_BATCHREAD          = &H20000???
%SHCOLSTATE_NO_GROUPBY         = &H40000???
%SHCOLSTATE_FIXED_WIDTH        = &H1000???
%SHCOLSTATE_NODPISCALE         = &H2000???
%SHCOLSTATE_FIXED_RATIO        = &H4000???
%SHCOLSTATE_DISPLAYMASK        = &Hf000???

'typedef DWORD SHCOLSTATEF;

'typedef PROPERTYKEY SHCOLUMNID;

' // Size = 20 bytes
TYPE SHCOLUMNID DWORD
   fmtid AS GUID      ' GUID fmtid
   pid   AS DWORD     ' DWORD pid
END TYPE
