' ########################################################################################
' Microsoft Windows
' File: xlcall.inc
' Contents: Header file for for Excel callbacks
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%XLCALL_INC = 1

'**  Microsoft Excel Developer's Toolkit
'**  Version 12.0
'**
'**  File:           INCLUDE\XLCALL.H
'**  Description:    Header file for for Excel callbacks
'**  Platform:       Microsoft Windows
'**
'**  DEPENDENCY:
'**  Include <windows.h> before you include this.
'**
'**  This file defines the constants and
'**  data types which are used in the
'**  Microsoft Excel C API.

'#pragma once

'/*
'** XL 12 Basic Datatypes
'**/

'typedef INT32 BOOL;        /* Boolean */
'typedef WCHAR XCHAR;       /* Wide Character */
'typedef INT32 RW;          /* XL 12 Row */
'typedef INT32 COL;         /* XL 12 Column */

'/*
'** XLREF structure
'**
'** Describes a single rectangular reference.
'*/

'typedef struct xlref
'{
'   WORD rwFirst;
'   WORD rwLast;
'   BYTE colFirst;
'   BYTE colLast;
'} XLREF, *LPXLREF;

' // Size = 6 bytes
TYPE XLREF BYTE
   rwFirst  AS WORD
   rwLast   AS WORD
   colFirst AS BYTE
   colLast  AS BYTE
END TYPE

'/*
'** XLMREF structure
'**
'** Describes multiple rectangular references.
'** This is a variable size structure, default
'** size is 1 reference.
'*/

'typedef struct xlmref
'{
'   WORD count;
'   XLREF reftbl[1];               /* actually reftbl[count] */
'} XLMREF, *LPXLMREF;

' // Size = 8 bytes
TYPE XLMREF BYTE
   count     AS WORD
   reftbl(0) AS XLREF
END TYPE

'/*
'** XLREF12 structure
'**
'** Describes a single XL 12 rectangular reference.
'*/

'typedef struct xlref12
'{
'   RW rwFirst;
'   RW rwLast;
'   COL colFirst;
'   COL colLast;
'} XLREF12, *LPXLREF12;

' // Size = 16 bytes
TYPE XLREF12 DWORD
   rwFirst  AS LONG
   rwLast   AS LONG
   colFirst AS LONG
   colLast  AS LONG
END TYPE

'/*
'** XLMREF12 structure
'**
'** Describes multiple rectangular XL 12 references.
'** This is a variable size structure, default
'** size is 1 reference.
'*/

'typedef struct xlmref12
'{
'   WORD count;
'   XLREF12 reftbl[1];               /* actually reftbl[count] */
'} XLMREF12, *LPXLMREF12;

' // Size = 20 bytes
TYPE XLMREF12 DWORD
   count     AS WORD
   reftbl(0) AS XLREF12
END TYPE

'/*
'** FP structure
'**
'** Describes FP structure.
'*/

'typedef struct _FP
'{
'    unsigned short int rows;
'    unsigned short int columns;
'    double array[1];        /* Actually, array[rows][columns] */
'} FP;

' // Size = 16 bytes
TYPE FP QWORD FILL
   rows AS INTEGER
   columns AS INTEGER
   array(0) AS DOUBLE
END TYPE

'/*
'** FP12 structure
'**
'** Describes FP structure capable of handling the big grid.
'*/

'typedef struct _FP12
'{
'    INT32 rows;
'    INT32 columns;
'    double array[1];        /* Actually, array[rows][columns] */
'} FP12;

' // Size = 16 bytes
TYPE FP12 DWORD
   rows     AS LONG
   columns  AS LONG
   array(0) AS DOUBLE
END TYPE

'/*
'** XLOPER structure
'**
'** Excel's fundamental data type: can hold data
'** of any type. Use "R" as the argument type in the
'** REGISTER function.
'**/

'typedef struct xloper
'{
'   union
'   {
'      double num;               /* xltypeNum */
'      LPSTR str;               /* xltypeStr */
'#ifdef __cplusplus
'      WORD xbool;               /* xltypeBool */
'#else
'      WORD bool;               /* xltypeBool */
'#endif
'      WORD err;               /* xltypeErr */
'      short int w;               /* xltypeInt */
'      struct
'      {
'         WORD count;            /* always = 1 */
'         XLREF ref;
'      } sref;                  /* xltypeSRef */
'      struct
'      {
'         XLMREF *lpmref;
'         DWORD idSheet;
'      } mref;                  /* xltypeRef */
'      struct
'      {
'         struct xloper *lparray;
'         WORD rows;
'         WORD columns;
'      } array;               /* xltypeMulti */
'      struct
'      {
'         union
'         {
'            short int level;      /* xlflowRestart */
'            short int tbctrl;      /* xlflowPause */
'            DWORD idSheet;         /* xlflowGoto */
'         } valflow;
'         WORD rw;            /* xlflowGoto */
'         BYTE col;            /* xlflowGoto */
'         BYTE xlflow;
'      } flow;                  /* xltypeFlow */
'      struct
'      {
'         union
'         {
'            BYTE *lpbData;         /* data passed to XL */
'            HANDLE hdata;         /* data returned from XL */
'         } h;
'         long cbData;
'      } bigdata;               /* xltypeBigData */
'   } val;
'   WORD xltype;
'} XLOPER, *LPXLOPER;

' // Size = 8 bytes
TYPE XLOPER_SREF_STRUCT BYTE
   count AS WORD
   ref   AS XLREF
END TYPE

' // Size = 8 bytes
TYPE XLOPER_MREF_STRUCT BYTE
   lpmref  AS XLMREF PTR
   idSheet AS DWORD
END TYPE

' // Size = 8 bytes
TYPE XLOPER_ARRAY_STRUCT BYTE
   lparray AS DWORD   ' XLOPER PTR
   rows    AS WORD
   columns AS WORD
END TYPE

' // Size = 4 bytes
UNION XLOPER_VALFLOW_UNION BYTE
   level   AS INTEGER
   tbctrl  AS INTEGER
   idSheet AS DWORD
END UNION

' // Size = 8 bytes
TYPE XLOPER_FLOW_STRUCT BYTE
   valflow AS XLOPER_VALFLOW_UNION
   rw      AS WORD
   col     AS BYTE
   xlflow  AS BYTE
END TYPE

' // Size = 4 bytes
UNION XLOPER_H_UNION BYTE
   lpbData AS BYTE PTR
   hdata   AS DWORD
END UNION

' // Size = 8 bytes
TYPE XLOPER_BIGDATA_STRUCT
   h      AS XLOPER_H_UNION
   cbData AS LONG
END TYPE

' // Size = 8 bytes
UNION XLOPER_VAL_UNION QWORD   ' // 8-byte alignment
   num     AS DOUBLE
   str     AS ASCIIZ PTR
   xbool   AS WORD
   err     AS WORD
   w       AS INTEGER
   sref    AS XLOPER_SREF_STRUCT
   mref    AS XLOPER_MREF_STRUCT
   array   AS XLOPER_ARRAY_STRUCT
   flow    AS XLOPER_FLOW_STRUCT
   bigdata AS XLOPER_BIGDATA_STRUCT
END UNION

' // Size = 16 bytes
TYPE XLOPER QWORD   ' // 8-byte alignment
   val    AS XLOPER_VAL_UNION
   xltype AS WORD
END TYPE

'/*
'** XLOPER12 structure
'**
'** Excel 12's fundamental data type: can hold data
'** of any type. Use "U" as the argument type in the
'** REGISTER function.
'**/

'typedef struct xloper12
'{
'   union
'   {
'      double num;                      /* xltypeNum */
'      XCHAR *str;                      /* xltypeStr */
'      BOOL xbool;                      /* xltypeBool */
'      int err;                      /* xltypeErr */
'      int w;
'      struct
'      {
'         WORD count;                   /* always = 1 */
'         XLREF12 ref;
'      } sref;                  /* xltypeSRef */
'      struct
'      {
'         XLMREF12 *lpmref;
'         DWORD idSheet;
'      } mref;                  /* xltypeRef */
'      struct
'      {
'         struct xloper12 *lparray;
'         RW rows;
'         COL columns;
'      } array;               /* xltypeMulti */
'      struct
'      {
'         union
'         {
'            int level;         /* xlflowRestart */
'            int tbctrl;         /* xlflowPause */
'            DWORD idSheet;         /* xlflowGoto */
'         } valflow;
'         RW rw;                      /* xlflowGoto */
'         COL col;                   /* xlflowGoto */
'         BYTE xlflow;
'      } flow;                  /* xltypeFlow */
'      struct
'      {
'         union
'         {
'            BYTE *lpbData;         /* data passed to XL */
'            HANDLE hdata;         /* data returned from XL */
'         } h;
'         long cbData;
'      } bigdata;               /* xltypeBigData */
'   } val;
'   DWORD xltype;
'} XLOPER12, *LPXLOPER12;

' // Size = 20 bytes
TYPE XLOPER12_SREF_STRUCT DWORD
   count AS WORD
   ref   AS XLREF12
END TYPE

' // Size = 8 bytes
TYPE XLOPER12_MREF_STRUCT DWORD
   lpmref  AS XLMREF12 PTR
   idSheet AS DWORD
END TYPE

' // Size = 12 bytes
TYPE XLOPER12_ARRAY_STRUCT DWORD
   lparray AS DWORD   ' XLOPER12 PTR
   rows    AS WORD
   columns AS WORD
END TYPE

' // Size = 4 bytes
UNION XLOPER12_VALFLOW_UNION DWORD
   level   AS INTEGER
   tbctrl  AS INTEGER
   idSheet AS DWORD
END UNION

' // Size = 16 bytes
TYPE XLOPER12_FLOW_STRUCT DWORD
   valflow AS XLOPER12_VALFLOW_UNION
   rw      AS WORD
   col     AS BYTE
   xlflow  AS BYTE
END TYPE

' // Size = 4 bytes
UNION XLOPER12_H_UNION DWORD
   lpbData AS BYTE PTR
   hdata   AS DWORD
END UNION

' // Size = 8 bytes
TYPE XLOPER12_BIGDATA_STRUCT DWORD
   h      AS XLOPER12_H_UNION
   cbData AS LONG
END TYPE

' // Size = 24 bytes
UNION XLOPER12_VAL_UNION QWORD   ' // 8-byte alignment
   num     AS DOUBLE
   str     AS WSTRINGZ PTR   ' XCHAR
   xbool   AS LONG
   err     AS LONG
   w       AS LONG
   sref    AS XLOPER12_SREF_STRUCT
   mref    AS XLOPER12_MREF_STRUCT
   array   AS XLOPER12_ARRAY_STRUCT
   flow    AS XLOPER12_FLOW_STRUCT
   bigdata AS XLOPER12_BIGDATA_STRUCT
END UNION

' // Size = 32 bytes
TYPE XLOPER12 QWORD   ' // 8-byte alignment
   val    AS XLOPER12_VAL_UNION
   xltype AS DWORD
END TYPE

'/*
'** XLOPER and XLOPER12 data types
'**
'** Used for xltype field of XLOPER and XLOPER12 structures
'*/

%xltypeNum     = &H0001???
%xltypeStr     = &H0002???
%xltypeBool    = &H0004???
%xltypeRef     = &H0008???
%xltypeErr     = &H0010???
%xltypeFlow    = &H0020???
%xltypeMulti   = &H0040???
%xltypeMissing = &H0080???
%xltypeNil     = &H0100???
%xltypeSRef    = &H0400???
%xltypeInt     = &H0800???

%xlbitXLFree   = &H1000???
%xlbitDLLFree  = &H4000???

%xltypeBigData = %xltypeStr OR %xltypeInt


'/*
'** Error codes
'**
'** Used for val.err field of XLOPER and XLOPER12 structures
'** when constructing error XLOPERs and XLOPER12s
'*/

%xlerrNull   = 0
%xlerrDiv0   = 7
%xlerrValue  = 15
%xlerrRef    = 23
%xlerrName   = 29
%xlerrNum    = 36
%xlerrNA     = 42


'/*
'** Flow data types
'**
'** Used for val.flow.xlflow field of XLOPER and XLOPER12 structures
'** when constructing flow-control XLOPERs and XLOPER12s
'**/

%xlflowHalt    = 1
%xlflowGoto    = 2
%xlflowRestart = 8
%xlflowPause   = 16
%xlflowResume  = 64


'/*
'** Return codes
'**
'** These values can be returned from Excel4(), Excel4v(), Excel12() or Excel12v().
'*/

%xlretSuccess       = 0    ' /* success */
%xlretAbort         = 1    ' /* macro halted */
%xlretInvXlfn       = 2    ' /* invalid function number */
%xlretInvCount      = 4    ' /* invalid number of arguments */
%xlretInvXloper     = 8    ' /* invalid OPER structure */
%xlretStackOvfl     = 16   ' /* stack overflow */
%xlretFailed        = 32   ' /* command failed */
%xlretUncalced      = 64   ' /* uncalced cell */
%xlretNotThreadSafe = 128  ' /* not allowed during multi-threaded calc */


'/*
'** Function prototypes
'*/

'#ifdef __cplusplus
'extern "C" {
'#endif

'int _cdecl Excel4(int xlfn, LPXLOPER operRes, int count,... );
'/* followed by count LPXLOPERs */

DECLARE FUNCTION Excel4 CDECL IMPORT "xlcall32.dll" ALIAS "Excel4" ( _
   BYVAL xlfn AS LONG _                                 ' int xlfn
 , BYREF operRes AS XLOPER _                            ' LPXLOPER operRes
 , BYVAL count AS LONG _                                ' int count
 , OPTIONAL BYREF XLOPER _                              ' ...
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 , OPTIONAL BYREF XLOPER _
 ) AS LONG                                              ' int

'int pascal Excel4v(int xlfn, LPXLOPER operRes, int count, LPXLOPER opers[]);

DECLARE FUNCTION Excel4v IMPORT "xlcall32.dll" ALIAS "Excel4v" ( _
   BYVAL xlfn AS LONG _                                 ' int xlfn
 , BYREF operRes AS XLOPER _                            ' LPXLOPER operRes
 , BYVAL count AS LONG _                                ' int count
 , BYREF opers AS XLOPER _                              ' LPXLOPER opers[]
 ) AS LONG                                              ' int

'int pascal XLCallVer(void);

DECLARE FUNCTION XLCallVer IMPORT "xlcall32.dll" ALIAS "XLCallVer" ( _
 ) AS LONG                                              ' int

'long pascal LPenHelper(int wCode, VOID *lpv);

DECLARE FUNCTION LPenHelper IMPORT "xlcall32.dll" ALIAS "LPenHelper" ( _
   BYVAL wCode AS LONG _                                ' int wCode
 , BYREF lpv AS ANY _                                   ' VOID *lpv
 ) AS LONG                                              ' int

'int _cdecl Excel12(int xlfn, LPXLOPER12 operRes, int count,... );
'/* followed by count LPXLOPER12s */

DECLARE FUNCTION Excel12 CDECL IMPORT "xlcall32.dll" ALIAS "Excel12" ( _
   BYVAL xlfn AS LONG _                                 ' int xlfn
 , BYREF operRes AS XLOPER12 _                          ' LPXLOPER12 operRes
 , BYVAL count AS LONG _                                ' int count
 , OPTIONAL BYREF XLOPER12 _                            ' ...
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 , OPTIONAL BYREF XLOPER12 _
 ) AS LONG                                              ' int

'int pascal Excel12v(int xlfn, LPXLOPER12 operRes, int count, LPXLOPER12 opers[]);

DECLARE FUNCTION Excel12v IMPORT "xlcall32.dll" ALIAS "Excel12v" ( _
   BYVAL xlfn AS LONG _                                 ' int xlfn
 , BYREF operRes AS XLOPER12 _                          ' LPXLOPER12 operRes
 , BYVAL count AS LONG _                                ' int count
 , BYREF opers AS XLOPER12 _                            ' LPXLOPER opers[]
 ) AS LONG                                              ' int

'#ifdef __cplusplus
'}
'#endif


'/*
'** Function number bits
'*/

%xlCommand    = &H8000??
%xlSpecial    = &H4000??
%xlIntl       = &H2000??
%xlPrompt     = &H1000??


'/*
'** Auxiliary function numbers
'**
'** These functions are available only from the C API,
'** not from the Excel macro language.
'*/

%xlFree             = (0  OR %xlSpecial)
%xlStack            = (1  OR %xlSpecial)
%xlCoerce           = (2  OR %xlSpecial)
%xlSet              = (3  OR %xlSpecial)
%xlSheetId          = (4  OR %xlSpecial)
%xlSheetNm          = (5  OR %xlSpecial)
%xlAbort            = (6  OR %xlSpecial)
%xlGetInst          = (7  OR %xlSpecial)
%xlGetHwnd          = (8  OR %xlSpecial)
%xlGetName          = (9  OR %xlSpecial)
%xlEnableXLMsgs     = (10 OR %xlSpecial)
%xlDisableXLMsgs    = (11 OR %xlSpecial)
%xlDefineBinaryName = (12 OR %xlSpecial)
%xlGetBinaryName    = (13 OR %xlSpecial)
'/* GetFooInfo are valid only for calls to LPenHelper */
%xlGetFmlaInfo      = (14 OR %xlSpecial)
%xlGetMouseInfo     = (15 OR %xlSpecial)

'/* edit modes */
%xlModeReady  = 0   ' // not in edit mode
%xlModeEnter  = 1   ' // enter mode
%xlModeEdit   = 2   ' // edit mode
%xlModePoint  = 4   ' // point mode

'/* document(page) types */
%dtNil = &H7f   ' // window is not a sheet, macro, chart or basic
'// OR window is not the selected window at idle state
%dtSheet = 0   ' // sheet
%dtProc  = 1   ' // XLM macro
%dtChart = 2   ' // Chart
%dtBasic = 6   ' // VBA

'/* hit test codes */
%htNone      = &H00   ' // none of below
%htClient    = &H01   ' // internal for "in the client are", should never see
%htVSplit    = &H02   ' // vertical split area with split panes
%htHSplit    = &H03   ' // horizontal split area
%htColWidth  = &H04   ' // column width adjuster area
%htRwHeight  = &H05   ' // row height adjuster area
%htRwColHdr  = &H06   ' // the intersection of row and column headers
%htObject_   = &H07   ' // the body of an object
' Note: Renamed as htObject_ because it conflicts with the HTOBJECT equate in WinUser.inc
' // the following are for size handles of draw objects
%htTopLeft_  = &H08
' Note: Renamed as htTopLeft_ because it conflicts with the HTTOPLEFT equate in WinUser.inc
%htBotLeft   = &H09
%htLeft      = &H0A
%htTopRight_ = &H0B
' Note: Renamed as htTopRight_ because it conflicts with the HTTOPRIGHT equate in WinUser.inc
%htBotRight  = &H0C
%htRight_    = &H0D
' Note: Renamed as htRight_ because it conflicts with the HTRIGHT equate in WinUser.inc
%htTop_      = &H0E
' Note: Renamed as htTop_ because it conflicts with the HTTOP equate in WinUser.inc
%htBot       = &H0F
' // end size handles
%htRwGut     = &H10   ' // row area of outline gutter
%htColGut    = &H11   ' // column area of outline gutter
%htTextBox   = &H12   ' // body of a text box (where we shouw I-Beam cursor)
%htRwLevels  = &H13   ' // row levels buttons of outline gutter
%htColLevels = &H14   ' // column levels buttons of outline gutter
%htDman      = &H15   ' // the drag/drop handle of the selection
%htDmanFill  = &H16   ' // the auto-fill handle of the selection
%htXSplit    = &H17   ' // the intersection of the horz & vert pane splits
%htVertex    = &H18   ' // a vertex of a polygon draw object
%htAddVtx    = &H19   ' // htVertex in add a vertex mode
%htDelVtx    = &H1A   ' // htVertex in delete a vertex mode
%htRwHdr     = &H1B   ' // row header
%htColHdr    = &H1C   ' // column header
%htRwShow    = &H1D   ' // Like htRowHeight except means grow a hidden column
%htColShow   = &H1E   ' // column version of htRwShow
%htSizing    = &H1F   ' // Internal use only
%htSxpivot   = &H20   ' // a drag/drop tile in a pivot table
%htTabs      = &H21   ' // the sheet paging tabs
%htEdit      = &H22   ' // Internal use only

'typedef struct _fmlainfo
'{
'   int wPointMode;   // current edit mode.  0 => rest of struct undefined
'   int cch;          // count of characters in formula
'   char *lpch;       // pointer to formula characters.  READ ONLY!!!
'   int ichFirst;     // char offset to start of selection
'   int ichLast;      // char offset to end of selection (may be > cch)
'   int ichCaret;     // char offset to blinking caret
'} FMLAINFO;

' // Size = 24 bytes
TYPE FMLAINFO DWORD
   wPointMode AS LONG
   cch        AS LONG
   lpch       AS ASCIIZ PTR
   ichFirst   AS LONG
   ichLast    AS LONG
   ichCaret   AS LONG
END TYPE

'typedef struct _mouseinfo
'{
'   /* input section */
'   HWND hwnd;      // window to get info on
'   POINT pt;      // mouse position to get info on

'   /* output section */
'   int dt;         // document(page) type
'   int ht;         // hit test code
'   int rw;         // row @ mouse (-1 if #n/a)
'   int col;      // col @ mouse (-1 if #n/a)
'} MOUSEINFO;

' // Size = 28 bytes
TYPE MOUSEINFO DWORD
   hwnd AS DWORD
   pt   AS POINT
   dt   AS LONG
   ht   AS LONG
   rw   AS LONG
   col  AS LONG
END TYPE


'/*
'** User defined function
'**
'** First argument should be a function reference.
'*/

%xlUDF = 255


'/*
'** Built-in Excel functions and command equivalents
'*/


'// Excel function numbers

%xlfCount                  = 0
%xlfIsna                   = 2
%xlfIserror                = 3
%xlfSum                    = 4
%xlfAverage                = 5
%xlfMin                    = 6
%xlfMax                    = 7
%xlfRow                    = 8
%xlfColumn                 = 9
%xlfNa                     = 10
%xlfNpv                    = 11
%xlfStdev                  = 12
%xlfDollar                 = 13
%xlfFixed                  = 14
%xlfSin                    = 15
%xlfCos                    = 16
%xlfTan                    = 17
%xlfAtan                   = 18
%xlfPi                     = 19
%xlfSqrt                   = 20
%xlfExp                    = 21
%xlfLn                     = 22
%xlfLog10                  = 23
%xlfAbs                    = 24
%xlfInt                    = 25
%xlfSign                   = 26
%xlfRound                  = 27
%xlfLookup                 = 28
%xlfIndex                  = 29
%xlfRept                   = 30
%xlfMid                    = 31
%xlfLen                    = 32
%xlfValue                  = 33
%xlfTrue                   = 34
%xlfFalse                  = 35
%xlfAnd                    = 36
%xlfOr                     = 37
%xlfNot                    = 38
%xlfMod                    = 39
%xlfDcount                 = 40
%xlfDsum                   = 41
%xlfDaverage               = 42
%xlfDmin                   = 43
%xlfDmax                   = 44
%xlfDstdev                 = 45
%xlfVar                    = 46
%xlfDvar                   = 47
%xlfText                   = 48
%xlfLinest                 = 49
%xlfTrend                  = 50
%xlfLogest                 = 51
%xlfGrowth                 = 52
%xlfGoto                   = 53
%xlfHalt                   = 54
%xlfPv                     = 56
%xlfFv                     = 57
%xlfNper                   = 58
%xlfPmt                    = 59
%xlfRate                   = 60
%xlfMirr                   = 61
%xlfIrr                    = 62
%xlfRand                   = 63
%xlfMatch                  = 64
%xlfDate                   = 65
%xlfTime                   = 66
%xlfDay                    = 67
%xlfMonth                  = 68
%xlfYear                   = 69
%xlfWeekday                = 70
%xlfHour                   = 71
%xlfMinute                 = 72
%xlfSecond                 = 73
%xlfNow                    = 74
%xlfAreas                  = 75
%xlfRows                   = 76
%xlfColumns                = 77
%xlfOffset                 = 78
%xlfAbsref                 = 79
%xlfRelref                 = 80
%xlfArgument               = 81
%xlfSearch                 = 82
%xlfTranspose              = 83
%xlfError                  = 84
%xlfStep                   = 85
%xlfType                   = 86
%xlfEcho                   = 87
%xlfSetName                = 88
%xlfCaller                 = 89
%xlfDeref                  = 90
%xlfWindows                = 91
%xlfSeries                 = 92
%xlfDocuments              = 93
%xlfActiveCell             = 94
%xlfSelection              = 95
%xlfResult                 = 96
%xlfAtan2                  = 97
%xlfAsin                   = 98
%xlfAcos                   = 99
%xlfChoose                 = 100
%xlfHlookup                = 101
%xlfVlookup                = 102
%xlfLinks                  = 103
%xlfInput                  = 104
%xlfIsref                  = 105
%xlfGetFormula             = 106
%xlfGetName                = 107
%xlfSetValue               = 108
%xlfLog                    = 109
%xlfExec                   = 110
%xlfChar                   = 111
%xlfLower                  = 112
%xlfUpper                  = 113
%xlfProper                 = 114
%xlfLeft                   = 115
%xlfRight                  = 116
%xlfExact                  = 117
%xlfTrim                   = 118
%xlfReplace                = 119
%xlfSubstitute             = 120
%xlfCode                   = 121
%xlfNames                  = 122
%xlfDirectory              = 123
%xlfFind                   = 124
%xlfCell                   = 125
%xlfIserr                  = 126
%xlfIstext                 = 127
%xlfIsnumber               = 128
%xlfIsblank                = 129
%xlfT                      = 130
%xlfN                      = 131
%xlfFopen                  = 132
%xlfFclose                 = 133
%xlfFsize                  = 134
%xlfFreadln                = 135
%xlfFread                  = 136
%xlfFwriteln               = 137
%xlfFwrite                 = 138
%xlfFpos                   = 139
%xlfDatevalue              = 140
%xlfTimevalue              = 141
%xlfSln                    = 142
%xlfSyd                    = 143
%xlfDdb                    = 144
%xlfGetDef                 = 145
%xlfReftext                = 146
%xlfTextref                = 147
%xlfIndirect               = 148
%xlfRegister               = 149
%xlfCall                   = 150
%xlfAddBar                 = 151
%xlfAddMenu                = 152
%xlfAddCommand             = 153
%xlfEnableCommand          = 154
%xlfCheckCommand           = 155
%xlfRenameCommand          = 156
%xlfShowBar                = 157
%xlfDeleteMenu             = 158
%xlfDeleteCommand          = 159
%xlfGetChartItem           = 160
%xlfDialogBox              = 161
%xlfClean                  = 162
%xlfMdeterm                = 163
%xlfMinverse               = 164
%xlfMmult                  = 165
%xlfFiles                  = 166
%xlfIpmt                   = 167
%xlfPpmt                   = 168
%xlfCounta                 = 169
%xlfCancelKey              = 170
%xlfInitiate               = 175
%xlfRequest                = 176
%xlfPoke                   = 177
%xlfExecute                = 178
%xlfTerminate              = 179
%xlfRestart                = 180
%xlfHelp                   = 181
%xlfGetBar                 = 182
%xlfProduct                = 183
%xlfFact                   = 184
%xlfGetCell                = 185
%xlfGetWorkspace           = 186
%xlfGetWindow              = 187
%xlfGetDocument            = 188
%xlfDproduct               = 189
%xlfIsnontext              = 190
%xlfGetNote                = 191
%xlfNote                   = 192
%xlfStdevp                 = 193
%xlfVarp                   = 194
%xlfDstdevp                = 195
%xlfDvarp                  = 196
%xlfTrunc                  = 197
%xlfIslogical              = 198
%xlfDcounta                = 199
%xlfDeleteBar              = 200
%xlfUnregister             = 201
%xlfUsdollar               = 204
%xlfFindb                  = 205
%xlfSearchb                = 206
%xlfReplaceb               = 207
%xlfLeftb                  = 208
%xlfRightb                 = 209
%xlfMidb                   = 210
%xlfLenb                   = 211
%xlfRoundup                = 212
%xlfRounddown              = 213
%xlfAsc                    = 214
%xlfDbcs                   = 215
%xlfRank                   = 216
%xlfAddress                = 219
%xlfDays360                = 220
%xlfToday                  = 221
%xlfVdb                    = 222
%xlfMedian                 = 227
%xlfSumproduct             = 228
%xlfSinh                   = 229
%xlfCosh                   = 230
%xlfTanh                   = 231
%xlfAsinh                  = 232
%xlfAcosh                  = 233
%xlfAtanh                  = 234
%xlfDget                   = 235
%xlfCreateObject           = 236
%xlfVolatile               = 237
%xlfLastError              = 238
%xlfCustomUndo             = 239
%xlfCustomRepeat           = 240
%xlfFormulaConvert         = 241
%xlfGetLinkInfo            = 242
%xlfTextBox                = 243
%xlfInfo                   = 244
%xlfGroup                  = 245
%xlfGetObject              = 246
%xlfDb                     = 247
%xlfPause                  = 248
%xlfResume                 = 251
%xlfFrequency              = 252
%xlfAddToolbar             = 253
%xlfDeleteToolbar          = 254
%xlfResetToolbar           = 256
%xlfEvaluate               = 257
%xlfGetToolbar             = 258
%xlfGetTool                = 259
%xlfSpellingCheck          = 260
%xlfErrorType              = 261
%xlfAppTitle               = 262
%xlfWindowTitle            = 263
%xlfSaveToolbar            = 264
%xlfEnableTool             = 265
%xlfPressTool              = 266
%xlfRegisterId             = 267
%xlfGetWorkbook            = 268
%xlfAvedev                 = 269
%xlfBetadist               = 270
%xlfGammaln                = 271
%xlfBetainv                = 272
%xlfBinomdist              = 273
%xlfChidist                = 274
%xlfChiinv                 = 275
%xlfCombin                 = 276
%xlfConfidence             = 277
%xlfCritbinom              = 278
%xlfEven                   = 279
%xlfExpondist              = 280
%xlfFdist                  = 281
%xlfFinv                   = 282
%xlfFisher                 = 283
%xlfFisherinv              = 284
%xlfFloor                  = 285
%xlfGammadist              = 286
%xlfGammainv               = 287
%xlfCeiling                = 288
%xlfHypgeomdist            = 289
%xlfLognormdist            = 290
%xlfLoginv                 = 291
%xlfNegbinomdist           = 292
%xlfNormdist               = 293
%xlfNormsdist              = 294
%xlfNorminv                = 295
%xlfNormsinv               = 296
%xlfStandardize            = 297
%xlfOdd                    = 298
%xlfPermut                 = 299
%xlfPoisson                = 300
%xlfTdist                  = 301
%xlfWeibull                = 302
%xlfSumxmy2                = 303
%xlfSumx2my2               = 304
%xlfSumx2py2               = 305
%xlfChitest                = 306
%xlfCorrel                 = 307
%xlfCovar                  = 308
%xlfForecast               = 309
%xlfFtest                  = 310
%xlfIntercept              = 311
%xlfPearson                = 312
%xlfRsq                    = 313
%xlfSteyx                  = 314
%xlfSlope                  = 315
%xlfTtest                  = 316
%xlfProb                   = 317
%xlfDevsq                  = 318
%xlfGeomean                = 319
%xlfHarmean                = 320
%xlfSumsq                  = 321
%xlfKurt                   = 322
%xlfSkew                   = 323
%xlfZtest                  = 324
%xlfLarge                  = 325
%xlfSmall                  = 326
%xlfQuartile               = 327
%xlfPercentile             = 328
%xlfPercentrank            = 329
%xlfMode                   = 330
%xlfTrimmean               = 331
%xlfTinv                   = 332
%xlfMovieCommand           = 334
%xlfGetMovie               = 335
%xlfConcatenate            = 336
%xlfPower                  = 337
%xlfPivotAddData           = 338
%xlfGetPivotTable          = 339
%xlfGetPivotField          = 340
%xlfGetPivotItem           = 341
%xlfRadians                = 342
%xlfDegrees                = 343
%xlfSubtotal               = 344
%xlfSumif                  = 345
%xlfCountif                = 346
%xlfCountblank             = 347
%xlfScenarioGet            = 348
%xlfOptionsListsGet        = 349
%xlfIspmt                  = 350
%xlfDatedif                = 351
%xlfDatestring             = 352
%xlfNumberstring           = 353
%xlfRoman                  = 354
%xlfOpenDialog             = 355
%xlfSaveDialog             = 356
%xlfViewGet                = 357
%xlfGetpivotdata           = 358
%xlfHyperlink              = 359
%xlfPhonetic               = 360
%xlfAveragea               = 361
%xlfMaxa                   = 362
%xlfMina                   = 363
%xlfStdevpa                = 364
%xlfVarpa                  = 365
%xlfStdeva                 = 366
%xlfVara                   = 367
%xlfBahttext               = 368
%xlfThaidayofweek          = 369
%xlfThaidigit              = 370
%xlfThaimonthofyear        = 371
%xlfThainumsound           = 372
%xlfThainumstring          = 373
%xlfThaistringlength       = 374
%xlfIsthaidigit            = 375
%xlfRoundbahtdown          = 376
%xlfRoundbahtup            = 377
%xlfThaiyear               = 378
%xlfRtd                    = 379
%xlfCubevalue              = 380
%xlfCubemember             = 381
%xlfCubememberproperty     = 382
%xlfCuberankedmember       = 383
%xlfHex2bin                = 384
%xlfHex2dec                = 385
%xlfHex2oct                = 386
%xlfDec2bin                = 387
%xlfDec2hex                = 388
%xlfDec2oct                = 389
%xlfOct2bin                = 390
%xlfOct2hex                = 391
%xlfOct2dec                = 392
%xlfBin2dec                = 393
%xlfBin2oct                = 394
%xlfBin2hex                = 395
%xlfImsub                  = 396
%xlfImdiv                  = 397
%xlfImpower                = 398
%xlfImabs                  = 399
%xlfImsqrt                 = 400
%xlfImln                   = 401
%xlfImlog2                 = 402
%xlfImlog10                = 403
%xlfImsin                  = 404
%xlfImcos                  = 405
%xlfImexp                  = 406
%xlfImargument             = 407
%xlfImconjugate            = 408
%xlfImaginary              = 409
%xlfImreal                 = 410
%xlfComplex                = 411
%xlfImsum                  = 412
%xlfImproduct              = 413
%xlfSeriessum              = 414
%xlfFactdouble             = 415
%xlfSqrtpi                 = 416
%xlfQuotient               = 417
%xlfDelta                  = 418
%xlfGestep                 = 419
%xlfIseven                 = 420
%xlfIsodd                  = 421
%xlfMround                 = 422
%xlfErf                    = 423
%xlfErfc                   = 424
%xlfBesselj                = 425
%xlfBesselk                = 426
%xlfBessely                = 427
%xlfBesseli                = 428
%xlfXirr                   = 429
%xlfXnpv                   = 430
%xlfPricemat               = 431
%xlfYieldmat               = 432
%xlfIntrate                = 433
%xlfReceived               = 434
%xlfDisc                   = 435
%xlfPricedisc              = 436
%xlfYielddisc              = 437
%xlfTbilleq                = 438
%xlfTbillprice             = 439
%xlfTbillyield             = 440
%xlfPrice                  = 441
%xlfYield                  = 442
%xlfDollarde               = 443
%xlfDollarfr               = 444
%xlfNominal                = 445
%xlfEffect                 = 446
%xlfCumprinc               = 447
%xlfCumipmt                = 448
%xlfEdate                  = 449
%xlfEomonth                = 450
%xlfYearfrac               = 451
%xlfCoupdaybs              = 452
%xlfCoupdays               = 453
%xlfCoupdaysnc             = 454
%xlfCoupncd                = 455
%xlfCoupnum                = 456
%xlfCouppcd                = 457
%xlfDuration               = 458
%xlfMduration              = 459
%xlfOddlprice              = 460
%xlfOddlyield              = 461
%xlfOddfprice              = 462
%xlfOddfyield              = 463
%xlfRandbetween            = 464
%xlfWeeknum                = 465
%xlfAmordegrc              = 466
%xlfAmorlinc               = 467
%xlfConvert                = 468
%xlfAccrint                = 469
%xlfAccrintm               = 470
%xlfWorkday                = 471
%xlfNetworkdays            = 472
%xlfGcd                    = 473
%xlfMultinomial            = 474
%xlfLcm                    = 475
%xlfFvschedule             = 476
%xlfCubekpimember          = 477
%xlfCubeset                = 478
%xlfCubesetcount           = 479
%xlfIferror                = 480
%xlfCountifs               = 481
%xlfSumifs                 = 482
%xlfAverageif              = 483
%xlfAverageifs             = 484

'/* Excel command numbers */
%xlcBeep                   = (0   OR %xlCommand)
%xlcOpen                   = (1   OR %xlCommand)
%xlcOpenLinks              = (2   OR %xlCommand)
%xlcCloseAll               = (3   OR %xlCommand)
%xlcSave                   = (4   OR %xlCommand)
%xlcSaveAs                 = (5   OR %xlCommand)
%xlcFileDelete             = (6   OR %xlCommand)
%xlcPageSetup              = (7   OR %xlCommand)
%xlcPrint                  = (8   OR %xlCommand)
%xlcPrinterSetup           = (9   OR %xlCommand)
%xlcQuit                   = (10  OR %xlCommand)
%xlcNewWindow              = (11  OR %xlCommand)
%xlcArrangeAll             = (12  OR %xlCommand)
%xlcWindowSize             = (13  OR %xlCommand)
%xlcWindowMove             = (14  OR %xlCommand)
%xlcFull                   = (15  OR %xlCommand)
%xlcClose                  = (16  OR %xlCommand)
%xlcRun                    = (17  OR %xlCommand)
%xlcSetPrintArea           = (22  OR %xlCommand)
%xlcSetPrintTitles         = (23  OR %xlCommand)
%xlcSetPageBreak           = (24  OR %xlCommand)
%xlcRemovePageBreak        = (25  OR %xlCommand)
%xlcFont                   = (26  OR %xlCommand)
%xlcDisplay                = (27  OR %xlCommand)
%xlcProtectDocument        = (28  OR %xlCommand)
%xlcPrecision              = (29  OR %xlCommand)
%xlcA1R1c1                 = (30  OR %xlCommand)
%xlcCalculateNow           = (31  OR %xlCommand)
%xlcCalculation            = (32  OR %xlCommand)
%xlcDataFind               = (34  OR %xlCommand)
%xlcExtract                = (35  OR %xlCommand)
%xlcDataDelete             = (36  OR %xlCommand)
%xlcSetDatabase            = (37  OR %xlCommand)
%xlcSetCriteria            = (38  OR %xlCommand)
%xlcSort                   = (39  OR %xlCommand)
%xlcDataSeries             = (40  OR %xlCommand)
%xlcTable                  = (41  OR %xlCommand)
%xlcFormatNumber           = (42  OR %xlCommand)
%xlcAlignment              = (43  OR %xlCommand)
%xlcStyle                  = (44  OR %xlCommand)
%xlcBorder                 = (45  OR %xlCommand)
%xlcCellProtection         = (46  OR %xlCommand)
%xlcColumnWidth            = (47  OR %xlCommand)
%xlcUndo                   = (48  OR %xlCommand)
%xlcCut                    = (49  OR %xlCommand)
%xlcCopy                   = (50  OR %xlCommand)
%xlcPaste                  = (51  OR %xlCommand)
%xlcClear                  = (52  OR %xlCommand)
%xlcPasteSpecial           = (53  OR %xlCommand)
%xlcEditDelete             = (54  OR %xlCommand)
%xlcInsert                 = (55  OR %xlCommand)
%xlcFillRight              = (56  OR %xlCommand)
%xlcFillDown               = (57  OR %xlCommand)
%xlcDefineName             = (61  OR %xlCommand)
%xlcCreateNames            = (62  OR %xlCommand)
%xlcFormulaGoto            = (63  OR %xlCommand)
%xlcFormulaFind            = (64  OR %xlCommand)
%xlcSelectLastCell         = (65  OR %xlCommand)
%xlcShowActiveCell         = (66  OR %xlCommand)
%xlcGalleryArea            = (67  OR %xlCommand)
%xlcGalleryBar             = (68  OR %xlCommand)
%xlcGalleryColumn          = (69  OR %xlCommand)
%xlcGalleryLine            = (70  OR %xlCommand)
%xlcGalleryPie             = (71  OR %xlCommand)
%xlcGalleryScatter         = (72  OR %xlCommand)
%xlcCombination            = (73  OR %xlCommand)
%xlcPreferred              = (74  OR %xlCommand)
%xlcAddOverlay             = (75  OR %xlCommand)
%xlcGridlines              = (76  OR %xlCommand)
%xlcSetPreferred           = (77  OR %xlCommand)
%xlcAxes                   = (78  OR %xlCommand)
%xlcLegend                 = (79  OR %xlCommand)
%xlcAttachText             = (80  OR %xlCommand)
%xlcAddArrow               = (81  OR %xlCommand)
%xlcSelectChart            = (82  OR %xlCommand)
%xlcSelectPlotArea         = (83  OR %xlCommand)
%xlcPatterns               = (84  OR %xlCommand)
%xlcMainChart              = (85  OR %xlCommand)
%xlcOverlay                = (86  OR %xlCommand)
%xlcScale                  = (87  OR %xlCommand)
%xlcFormatLegend           = (88  OR %xlCommand)
%xlcFormatText             = (89  OR %xlCommand)
%xlcEditRepeat             = (90  OR %xlCommand)
%xlcParse                  = (91  OR %xlCommand)
%xlcJustify                = (92  OR %xlCommand)
%xlcHide                   = (93  OR %xlCommand)
%xlcUnhide                 = (94  OR %xlCommand)
%xlcWorkspace              = (95  OR %xlCommand)
%xlcFormula                = (96  OR %xlCommand)
%xlcFormulaFill            = (97  OR %xlCommand)
%xlcFormulaArray           = (98  OR %xlCommand)
%xlcDataFindNext           = (99  OR %xlCommand)
%xlcDataFindPrev           = (100 OR %xlCommand)
%xlcFormulaFindNext        = (101 OR %xlCommand)
%xlcFormulaFindPrev        = (102 OR %xlCommand)
%xlcActivate               = (103 OR %xlCommand)
%xlcActivateNext           = (104 OR %xlCommand)
%xlcActivatePrev           = (105 OR %xlCommand)
%xlcUnlockedNext           = (106 OR %xlCommand)
%xlcUnlockedPrev           = (107 OR %xlCommand)
%xlcCopyPicture            = (108 OR %xlCommand)
%xlcSelect                 = (109 OR %xlCommand)
%xlcDeleteName             = (110 OR %xlCommand)
%xlcDeleteFormat           = (111 OR %xlCommand)
%xlcVline                  = (112 OR %xlCommand)
%xlcHline                  = (113 OR %xlCommand)
%xlcVpage                  = (114 OR %xlCommand)
%xlcHpage                  = (115 OR %xlCommand)
%xlcVscroll                = (116 OR %xlCommand)
%xlcHscroll                = (117 OR %xlCommand)
%xlcAlert                  = (118 OR %xlCommand)
%xlcNew                    = (119 OR %xlCommand)
%xlcCancelCopy             = (120 OR %xlCommand)
%xlcShowClipboard          = (121 OR %xlCommand)
%xlcMessage                = (122 OR %xlCommand)
%xlcPasteLink              = (124 OR %xlCommand)
%xlcAppActivate            = (125 OR %xlCommand)
%xlcDeleteArrow            = (126 OR %xlCommand)
%xlcRowHeight              = (127 OR %xlCommand)
%xlcFormatMove             = (128 OR %xlCommand)
%xlcFormatSize             = (129 OR %xlCommand)
%xlcFormulaReplace         = (130 OR %xlCommand)
%xlcSendKeys               = (131 OR %xlCommand)
%xlcSelectSpecial          = (132 OR %xlCommand)
%xlcApplyNames             = (133 OR %xlCommand)
%xlcReplaceFont            = (134 OR %xlCommand)
%xlcFreezePanes            = (135 OR %xlCommand)
%xlcShowInfo               = (136 OR %xlCommand)
%xlcSplit                  = (137 OR %xlCommand)
%xlcOnWindow               = (138 OR %xlCommand)
%xlcOnData                 = (139 OR %xlCommand)
%xlcDisableInput           = (140 OR %xlCommand)
%xlcEcho                   = (141 OR %xlCommand)
%xlcOutline                = (142 OR %xlCommand)
%xlcListNames              = (143 OR %xlCommand)
%xlcFileClose              = (144 OR %xlCommand)
%xlcSaveWorkbook           = (145 OR %xlCommand)
%xlcDataForm               = (146 OR %xlCommand)
%xlcCopyChart              = (147 OR %xlCommand)
%xlcOnTime                 = (148 OR %xlCommand)
%xlcWait                   = (149 OR %xlCommand)
%xlcFormatFont             = (150 OR %xlCommand)
%xlcFillUp                 = (151 OR %xlCommand)
%xlcFillLeft               = (152 OR %xlCommand)
%xlcDeleteOverlay          = (153 OR %xlCommand)
%xlcNote                   = (154 OR %xlCommand)
%xlcShortMenus             = (155 OR %xlCommand)
%xlcSetUpdateStatus        = (159 OR %xlCommand)
%xlcColorPalette           = (161 OR %xlCommand)
%xlcDeleteStyle            = (162 OR %xlCommand)
%xlcWindowRestore          = (163 OR %xlCommand)
%xlcWindowMaximize         = (164 OR %xlCommand)
%xlcError                  = (165 OR %xlCommand)
%xlcChangeLink             = (166 OR %xlCommand)
%xlcCalculateDocument      = (167 OR %xlCommand)
%xlcOnKey                  = (168 OR %xlCommand)
%xlcAppRestore             = (169 OR %xlCommand)
%xlcAppMove                = (170 OR %xlCommand)
%xlcAppSize                = (171 OR %xlCommand)
%xlcAppMinimize            = (172 OR %xlCommand)
%xlcAppMaximize            = (173 OR %xlCommand)
%xlcBringToFront           = (174 OR %xlCommand)
%xlcSendToBack             = (175 OR %xlCommand)
%xlcMainChartType          = (185 OR %xlCommand)
%xlcOverlayChartType       = (186 OR %xlCommand)
%xlcSelectEnd              = (187 OR %xlCommand)
%xlcOpenMail               = (188 OR %xlCommand)
%xlcSendMail               = (189 OR %xlCommand)
%xlcStandardFont           = (190 OR %xlCommand)
%xlcConsolidate            = (191 OR %xlCommand)
%xlcSortSpecial            = (192 OR %xlCommand)
%xlcGallery3dArea          = (193 OR %xlCommand)
%xlcGallery3dColumn        = (194 OR %xlCommand)
%xlcGallery3dLine          = (195 OR %xlCommand)
%xlcGallery3dPie           = (196 OR %xlCommand)
%xlcView3d                 = (197 OR %xlCommand)
%xlcGoalSeek               = (198 OR %xlCommand)
%xlcWorkgroup              = (199 OR %xlCommand)
%xlcFillGroup              = (200 OR %xlCommand)
%xlcUpdateLink             = (201 OR %xlCommand)
%xlcPromote                = (202 OR %xlCommand)
%xlcDemote                 = (203 OR %xlCommand)
%xlcShowDetail             = (204 OR %xlCommand)
%xlcUngroup                = (206 OR %xlCommand)
%xlcObjectProperties       = (207 OR %xlCommand)
%xlcSaveNewObject          = (208 OR %xlCommand)
%xlcShare                  = (209 OR %xlCommand)
%xlcShareName              = (210 OR %xlCommand)
%xlcDuplicate              = (211 OR %xlCommand)
%xlcApplyStyle             = (212 OR %xlCommand)
%xlcAssignToObject         = (213 OR %xlCommand)
%xlcObjectProtection       = (214 OR %xlCommand)
%xlcHideObject             = (215 OR %xlCommand)
%xlcSetExtract             = (216 OR %xlCommand)
%xlcCreatePublisher        = (217 OR %xlCommand)
%xlcSubscribeTo            = (218 OR %xlCommand)
%xlcAttributes             = (219 OR %xlCommand)
%xlcShowToolbar            = (220 OR %xlCommand)
%xlcPrintPreview           = (222 OR %xlCommand)
%xlcEditColor              = (223 OR %xlCommand)
%xlcShowLevels             = (224 OR %xlCommand)
%xlcFormatMain             = (225 OR %xlCommand)
%xlcFormatOverlay          = (226 OR %xlCommand)
%xlcOnRecalc               = (227 OR %xlCommand)
%xlcEditSeries             = (228 OR %xlCommand)
%xlcDefineStyle            = (229 OR %xlCommand)
%xlcLinePrint              = (240 OR %xlCommand)
%xlcEnterData              = (243 OR %xlCommand)
%xlcGalleryRadar           = (249 OR %xlCommand)
%xlcMergeStyles            = (250 OR %xlCommand)
%xlcEditionOptions         = (251 OR %xlCommand)
%xlcPastePicture           = (252 OR %xlCommand)
%xlcPastePictureLink       = (253 OR %xlCommand)
%xlcSpelling               = (254 OR %xlCommand)
%xlcZoom                   = (256 OR %xlCommand)
%xlcResume                 = (258 OR %xlCommand)
%xlcInsertObject           = (259 OR %xlCommand)
%xlcWindowMinimize         = (260 OR %xlCommand)
%xlcSize                   = (261 OR %xlCommand)
%xlcMove                   = (262 OR %xlCommand)
%xlcSoundNote              = (265 OR %xlCommand)
%xlcSoundPlay              = (266 OR %xlCommand)
%xlcFormatShape            = (267 OR %xlCommand)
%xlcExtendPolygon          = (268 OR %xlCommand)
%xlcFormatAuto             = (269 OR %xlCommand)
%xlcGallery3dBar           = (272 OR %xlCommand)
%xlcGallery3dSurface       = (273 OR %xlCommand)
%xlcFillAuto               = (274 OR %xlCommand)
%xlcCustomizeToolbar       = (276 OR %xlCommand)
%xlcAddTool                = (277 OR %xlCommand)
%xlcEditObject             = (278 OR %xlCommand)
%xlcOnDoubleclick          = (279 OR %xlCommand)
%xlcOnEntry                = (280 OR %xlCommand)
%xlcWorkbookAdd            = (281 OR %xlCommand)
%xlcWorkbookMove           = (282 OR %xlCommand)
%xlcWorkbookCopy           = (283 OR %xlCommand)
%xlcWorkbookOptions        = (284 OR %xlCommand)
%xlcSaveWorkspace          = (285 OR %xlCommand)
%xlcChartWizard            = (288 OR %xlCommand)
%xlcDeleteTool             = (289 OR %xlCommand)
%xlcMoveTool               = (290 OR %xlCommand)
%xlcWorkbookSelect         = (291 OR %xlCommand)
%xlcWorkbookActivate       = (292 OR %xlCommand)
%xlcAssignToTool           = (293 OR %xlCommand)
%xlcCopyTool               = (295 OR %xlCommand)
%xlcResetTool              = (296 OR %xlCommand)
%xlcConstrainNumeric       = (297 OR %xlCommand)
%xlcPasteTool              = (298 OR %xlCommand)
%xlcPlacement              = (300 OR %xlCommand)
%xlcFillWorkgroup          = (301 OR %xlCommand)
%xlcWorkbookNew            = (302 OR %xlCommand)
%xlcScenarioCells          = (305 OR %xlCommand)
%xlcScenarioDelete         = (306 OR %xlCommand)
%xlcScenarioAdd            = (307 OR %xlCommand)
%xlcScenarioEdit           = (308 OR %xlCommand)
%xlcScenarioShow           = (309 OR %xlCommand)
%xlcScenarioShowNext       = (310 OR %xlCommand)
%xlcScenarioSummary        = (311 OR %xlCommand)
%xlcPivotTableWizard       = (312 OR %xlCommand)
%xlcPivotFieldProperties   = (313 OR %xlCommand)
%xlcPivotField             = (314 OR %xlCommand)
%xlcPivotItem              = (315 OR %xlCommand)
%xlcPivotAddFields         = (316 OR %xlCommand)
%xlcOptionsCalculation     = (318 OR %xlCommand)
%xlcOptionsEdit            = (319 OR %xlCommand)
%xlcOptionsView            = (320 OR %xlCommand)
%xlcAddinManager           = (321 OR %xlCommand)
%xlcMenuEditor             = (322 OR %xlCommand)
%xlcAttachToolbars         = (323 OR %xlCommand)
%xlcVbaactivate            = (324 OR %xlCommand)
%xlcOptionsChart           = (325 OR %xlCommand)
%xlcVbaInsertFile          = (328 OR %xlCommand)
%xlcVbaProcedureDefinition = (330 OR %xlCommand)
%xlcRoutingSlip            = (336 OR %xlCommand)
%xlcRouteDocument          = (338 OR %xlCommand)
%xlcMailLogon              = (339 OR %xlCommand)
%xlcInsertPicture          = (342 OR %xlCommand)
%xlcEditTool               = (343 OR %xlCommand)
%xlcGalleryDoughnut        = (344 OR %xlCommand)
%xlcChartTrend             = (350 OR %xlCommand)
%xlcPivotItemProperties    = (352 OR %xlCommand)
%xlcWorkbookInsert         = (354 OR %xlCommand)
%xlcOptionsTransition      = (355 OR %xlCommand)
%xlcOptionsGeneral         = (356 OR %xlCommand)
%xlcFilterAdvanced         = (370 OR %xlCommand)
%xlcMailAddMailer          = (373 OR %xlCommand)
%xlcMailDeleteMailer       = (374 OR %xlCommand)
%xlcMailReply              = (375 OR %xlCommand)
%xlcMailReplyAll           = (376 OR %xlCommand)
%xlcMailForward            = (377 OR %xlCommand)
%xlcMailNextLetter         = (378 OR %xlCommand)
%xlcDataLabel              = (379 OR %xlCommand)
%xlcInsertTitle            = (380 OR %xlCommand)
%xlcFontProperties         = (381 OR %xlCommand)
%xlcMacroOptions           = (382 OR %xlCommand)
%xlcWorkbookHide           = (383 OR %xlCommand)
%xlcWorkbookUnhide         = (384 OR %xlCommand)
%xlcWorkbookDelete         = (385 OR %xlCommand)
%xlcWorkbookName           = (386 OR %xlCommand)
%xlcGalleryCustom          = (388 OR %xlCommand)
%xlcAddChartAutoformat     = (390 OR %xlCommand)
%xlcDeleteChartAutoformat  = (391 OR %xlCommand)
%xlcChartAddData           = (392 OR %xlCommand)
%xlcAutoOutline            = (393 OR %xlCommand)
%xlcTabOrder               = (394 OR %xlCommand)
%xlcShowDialog             = (395 OR %xlCommand)
%xlcSelectAll              = (396 OR %xlCommand)
%xlcUngroupSheets          = (397 OR %xlCommand)
%xlcSubtotalCreate         = (398 OR %xlCommand)
%xlcSubtotalRemove         = (399 OR %xlCommand)
%xlcRenameObject           = (400 OR %xlCommand)
%xlcWorkbookScroll         = (412 OR %xlCommand)
%xlcWorkbookNext           = (413 OR %xlCommand)
%xlcWorkbookPrev           = (414 OR %xlCommand)
%xlcWorkbookTabSplit       = (415 OR %xlCommand)
%xlcFullScreen             = (416 OR %xlCommand)
%xlcWorkbookProtect        = (417 OR %xlCommand)
%xlcScrollbarProperties    = (420 OR %xlCommand)
%xlcPivotShowPages         = (421 OR %xlCommand)
%xlcTextToColumns          = (422 OR %xlCommand)
%xlcFormatCharttype        = (423 OR %xlCommand)
%xlcLinkFormat             = (424 OR %xlCommand)
%xlcTracerDisplay          = (425 OR %xlCommand)
%xlcTracerNavigate         = (430 OR %xlCommand)
%xlcTracerClear            = (431 OR %xlCommand)
%xlcTracerError            = (432 OR %xlCommand)
%xlcPivotFieldGroup        = (433 OR %xlCommand)
%xlcPivotFieldUngroup      = (434 OR %xlCommand)
%xlcCheckboxProperties     = (435 OR %xlCommand)
%xlcLabelProperties        = (436 OR %xlCommand)
%xlcListboxProperties      = (437 OR %xlCommand)
%xlcEditboxProperties      = (438 OR %xlCommand)
%xlcPivotRefresh           = (439 OR %xlCommand)
%xlcLinkCombo              = (440 OR %xlCommand)
%xlcOpenText               = (441 OR %xlCommand)
%xlcHideDialog             = (442 OR %xlCommand)
%xlcSetDialogFocus         = (443 OR %xlCommand)
%xlcEnableObject           = (444 OR %xlCommand)
%xlcPushbuttonProperties   = (445 OR %xlCommand)
%xlcSetDialogDefault       = (446 OR %xlCommand)
%xlcFilter                 = (447 OR %xlCommand)
%xlcFilterShowAll          = (448 OR %xlCommand)
%xlcClearOutline           = (449 OR %xlCommand)
%xlcFunctionWizard         = (450 OR %xlCommand)
%xlcAddListItem            = (451 OR %xlCommand)
%xlcSetListItem            = (452 OR %xlCommand)
%xlcRemoveListItem         = (453 OR %xlCommand)
%xlcSelectListItem         = (454 OR %xlCommand)
%xlcSetControlValue        = (455 OR %xlCommand)
%xlcSaveCopyAs             = (456 OR %xlCommand)
%xlcOptionsListsAdd        = (458 OR %xlCommand)
%xlcOptionsListsDelete     = (459 OR %xlCommand)
%xlcSeriesAxes             = (460 OR %xlCommand)
%xlcSeriesX                = (461 OR %xlCommand)
%xlcSeriesY                = (462 OR %xlCommand)
%xlcErrorbarX              = (463 OR %xlCommand)
%xlcErrorbarY              = (464 OR %xlCommand)
%xlcFormatChart            = (465 OR %xlCommand)
%xlcSeriesOrder            = (466 OR %xlCommand)
%xlcMailLogoff             = (467 OR %xlCommand)
%xlcClearRoutingSlip       = (468 OR %xlCommand)
%xlcAppActivateMicrosoft   = (469 OR %xlCommand)
%xlcMailEditMailer         = (470 OR %xlCommand)
%xlcOnSheet                = (471 OR %xlCommand)
%xlcStandardWidth          = (472 OR %xlCommand)
%xlcScenarioMerge          = (473 OR %xlCommand)
%xlcSummaryInfo            = (474 OR %xlCommand)
%xlcFindFile               = (475 OR %xlCommand)
%xlcActiveCellFont         = (476 OR %xlCommand)
%xlcEnableTipwizard        = (477 OR %xlCommand)
%xlcVbaMakeAddin           = (478 OR %xlCommand)
%xlcInsertdatatable        = (480 OR %xlCommand)
%xlcWorkgroupOptions       = (481 OR %xlCommand)
%xlcMailSendMailer         = (482 OR %xlCommand)
%xlcAutocorrect            = (485 OR %xlCommand)
%xlcPostDocument           = (489 OR %xlCommand)
%xlcPicklist               = (491 OR %xlCommand)
%xlcViewShow               = (493 OR %xlCommand)
%xlcViewDefine             = (494 OR %xlCommand)
%xlcViewDelete             = (495 OR %xlCommand)
%xlcSheetBackground        = (509 OR %xlCommand)
%xlcInsertMapObject        = (510 OR %xlCommand)
%xlcOptionsMenono          = (511 OR %xlCommand)
%xlcNormal                 = (518 OR %xlCommand)
%xlcLayout                 = (519 OR %xlCommand)
%xlcRmPrintArea            = (520 OR %xlCommand)
%xlcClearPrintArea         = (521 OR %xlCommand)
%xlcAddPrintArea           = (522 OR %xlCommand)
%xlcMoveBrk                = (523 OR %xlCommand)
%xlcHidecurrNote           = (545 OR %xlCommand)
%xlcHideallNotes           = (546 OR %xlCommand)
%xlcDeleteNote             = (547 OR %xlCommand)
%xlcTraverseNotes          = (548 OR %xlCommand)
%xlcActivateNotes          = (549 OR %xlCommand)
%xlcProtectRevisions       = (620 OR %xlCommand)
%xlcUnprotectRevisions     = (621 OR %xlCommand)
%xlcOptionsMe              = (647 OR %xlCommand)
%xlcWebPublish             = (653 OR %xlCommand)
%xlcNewwebquery            = (667 OR %xlCommand)
%xlcPivotTableChart        = (673 OR %xlCommand)
%xlcOptionsSave            = (753 OR %xlCommand)
%xlcOptionsSpell           = (755 OR %xlCommand)
%xlcHideallInkannots       = (808 OR %xlCommand)
