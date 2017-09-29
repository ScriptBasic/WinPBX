' ########################################################################################
' Microsoft Windows
' File: MAPIUtil.inc
' Contents: Definitions and prototypes for utility functions provided by MAPI in MAPI[xx].DLL.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MAPIUTIL_INC = 1

#INCLUDE ONCE "mapix.inc"

'/* IMAPITable in memory */

'/* ITableData Interface ---------------------------------------------------- */

'typedef void (STDAPICALLTYPE CALLERRELEASE)(
'   ULONG         ulCallerData,
'   LPTABLEDATA   lpTblData,
'   LPMAPITABLE   lpVue
');

' ========================================================================================
' ITableData interface
' $IID_IMAPITableData = GUID$("{00020316-0000-0000-C000-000000000046}")
' The ITableData interface provides utility methods for working with tables. Table data
' objects -- or objects that implement ITableData -- are provided by MAPI to help service
' providers perform table maintenance. To obtain a table data object, service providers
' call the CreateTable function.
' ========================================================================================

INTERFACE ITableData $IID_ITableData

   INHERIT IUnknown

   ' =====================================================================================
   METHOD HrGetView ( _                                 ' VTable offset = 12
     BYVAL lpSSortOrderSet AS SSortOrderSet PTR _       ' __in LPSSortOrderSet lpSSortOrderSet
   , BYVAL lpfCallerRelease AS DWORD _                  ' __in CALLERRELEASE * lpfCallerRelease
   , BYVAL ulCallerData AS DWORD _                      ' __in ULONG ulCallerData
   , BYREF lppMAPITable AS IMAPITable _                 ' __out LPMAPITABLE * lppMAPITable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HrModifyRow ( _                               ' VTable offset = 16
     BYREF lpSRow AS SRow _                             ' __in LPSRow lpSRow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HrDeleteRow ( _                               ' VTable offset = 20
     BYREF lpSPropValue AS SPropValue _                 ' __in LPSPropValue lpSPropValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HrQueryRow ( _                                ' VTable offset = 24
     BYREF lpsPropValue AS SPropValue _                 ' __in LPSPropValue lpsPropValue
   , BYREF lppSRow AS DWORD _                           ' __out LPSRow * lppSRow
   , BYVAL lpuliRow AS DWORD _                          ' __in_out ULONG * lpuliRow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HrEnumRow ( _                                 ' VTable offset = 28
     BYVAL ulRowNumber AS DWORD _                       ' __in ULONG ulRowNumber
   , BYREF lppSRow AS DWORD _                           ' __out LPSRow * lppSRow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HrNotify ( _                                  ' VTable offset = 32
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL cValues AS DWORD _                           ' __in ULONG cValues
   , BYREF lpSPropValue AS SPropValue _                 ' __in LPSPropValue lpSPropValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HrInsertRow ( _                               ' VTable offset = 36
     BYVAL uliRow AS DWORD _                            ' __in uliRow
   , BYREF lpSRow AS SRow _                             ' __in LPSRow lpSRow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HrModifyRows ( _                              ' VTable offset = 40
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lpSRowSet AS SRowSet PTR _                   ' __in LPSRowSet lpSRowSet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HrDeleteRows ( _                              ' VTable offset = 44
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lprowsetToDelete AS SRowSet PTR _            ' __in LPSRowSet lprowsetToDelete
   , BYREF cRowsDeleted AS DWORD _                      ' __out ULONG * cRowsDeleted
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/* Entry Point for in memory ITable */


'/*   CreateTable()
' *      Creates the internal memory structures and object handle
' *      to bring a new table into existence.
' *
' *   lpInterface
' *      Interface ID of the TableData object (IID_IMAPITableData)
' *
' *   lpAllocateBuffer, lpAllocateMore, and lpFreeBuffer
' *      Function addresses are provided by the caller so that
' *      this DLL allocates/frees memory appropriately.
' *   lpvReserved
' *      Reserved.  Should be NULL.
' *   ulTableType
' *      TBLTYPE_DYNAMIC, etc.  Visible to the calling application
' *      as part of the GetStatus return data on its views
' *   ulPropTagIndexColumn
' *      Index column for use when changing the data
' *   lpSPropTagArrayColumns
' *      Column proptags for the minimum set of columns in the table
' *   lppTableData
' *      Address of the pointer which will receive the TableData object
' */

DECLARE FUNCTION CreateTable IMPORT "MAPI32.DLL" ALIAS "CreateTable@36" ( _
   BYREF lpInterface AS GUID _                          ' __in LPCIID lpInterface
 , BYVAL lpAllocateBuffer AS DWORD _                    ' __in ALLOCATEBUFFER * lpAllocateBuffer
 , BYVAL lpAllocateMore AS DWORD _                      ' __in ALLOCATEMORE * lpAllocateMore
 , BYVAL lpFreeBuffer AS DWORD _                        ' __in FREEBUFFER * lpFreeBuffer
 , BYVAL lpvReserved AS DWORD _                         ' __in LPVOID lpvReserved
 , BYVAL ulTableType AS DWORD _                         ' __in ULONG ulTableType
 , BYVAL ulPropTagIndexColumn AS DWORD _                ' __in ULONG ulPropTagIndexColumn
 , BYVAL lpSPropTagArrayColumns AS SPropTagArray PTR _  ' __in LPSPropTagArray lpSPropTagArrayColumns
 , BYREF lppTableData AS ITableData _                   ' __out LPTABLEDATA * lppTableData
 ) AS LONG                                              ' SCODE

'/*   HrGetView()
' *      This function obtains a new view on the underlying data
' *      which supports the IMAPITable interface.  All rows and columns
' *      of the underlying table data are initially visible
' *   lpSSortOrderSet
' *      if specified, results in the view being sorted
' *   lpfCallerRelease
' *      pointer to a routine to be called when the view is released, or
' *      NULL.
' *   ulCallerData
' *      arbitrary data the caller wants saved with this view and returned in
' *      the Release callback.
' */

'/*   HrModifyRows()
' *      Add or modify a set of rows in the table data
' *   ulFlags
' *      Must be zero
' *   lpSRowSet
' *      Each row in the row set contains all the properties for one row
' *      in the table.  One of the properties must be the index column.  Any
' *      row in the table with the same value for its index column is
' *      replaced, or if there is no current row with that value the
' *      row is added.
' *      Each row in LPSRowSet MUST have a unique Index column!
' *      If any views are open, the view is updated as well.
' *      The properties do not have to be in the same order as the
' *      columns in the current table
' */

'/*   HrModifyRow()
' *      Add or modify one row in the table
' *   lpSRow
' *      This row contains all the properties for one row in the table.
' *      One of the properties must be the index column.    Any row in
' *      the table with the same value for its index column is
' *      replaced, or if there is no current row with that value the
' *      row is added
' *      If any views are open, the view is updated as well.
' *      The properties do not have to be in the same order as the
' *      columns in the current table
' */

'/*   HrDeleteRows()
' *      Delete a row in the table.
' *   ulFlags
' *      TAD_ALL_ROWS - Causes all rows in the table to be deleted
' *                  lpSRowSet is ignored in this case.
' *   lpSRowSet
' *      Each row in the row set contains all the properties for one row
' *      in the table.  One of the properties must be the index column.  Any
' *      row in the table with the same value for its index column is
' *      deleted.
' *      Each row in LPSRowSet MUST have a unique Index column!
' *      If any views are open, the view is updated as well.
' *      The properties do not have to be in the same order as the
' *      columns in the current table
' */
%TAD_ALL_ROWS  = 1

'/*   HrDeleteRow()
' *      Delete a row in the table.
' *   lpSPropValue
' *      This property value specifies the row which has this value
' *      for its index column
' */

'/*   HrQueryRow()
' *      Returns the values of a specified row in the table
' *   lpSPropValue
' *      This property value specifies the row which has this value
' *      for its index column
' *   lppSRow
' *      Address of where to return a pointer to an SRow
' *   lpuliRow
' *     Address of where to return the row number. This can be NULL
' *     if the row number is not required.
' *
' */

'/*   HrEnumRow()
' *      Returns the values of a specific (numbered) row in the table
' *   ulRowNumber
' *      Indicates row number 0 to n-1
' *   lppSRow
' *      Address of where to return a pointer to a SRow
' */

'/*   HrInsertRow()
' *      Inserts a row into the table.
' *   uliRow
' *      The row number before which this row will be inserted into the table.
' *      Row numbers can be from 0 to n where o to n-1 result in row insertion
' *     a row number of n results in the row being appended to the table.
' *   lpSRow
' *      This row contains all the properties for one row in the table.
' *      One of the properties must be the index column.    Any row in
' *      the table with the same value for its index column is
' *      replaced, or if there is no current row with that value the
' *      row is added
' *      If any views are open, the view is updated as well.
' *      The properties do not have to be in the same order as the
' *      columns in the current table
' */


'/* IMAPIProp in memory */

'/* IPropData Interface ---------------------------------------------------- */


' ========================================================================================
' IPropData interface (inherits from  IMAPIProp)
' $IID_IMAPIPropData = GUID$("{0002031A-0000-0000-C000-000000000046}")
' The IPropData interface provides the ability to retrieve and change the access for an
' object's properties.
' ========================================================================================
INTERFACE IPropData $IID_IPropData

   INHERIT IUnknown

   ' =====================================================================================
   ' IMAPIProp Methods
   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offser = 12
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveChanges ( _                               ' VTable offser = 16
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProps ( _                                  ' VTable offser = 20
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcValues AS DWORD _                         ' __out ULONG * lpcValues
   , BYREF lppPropArray AS DWORD _                      ' __out LPSPropValue * lppPropArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropList ( _                               ' VTable offser = 24
     BYVAL ulFlags AS DWORD _                           ' __in ulFlags
   , BYREF lppPropTagArray AS DWORD _                   ' __out LPSPropTagArray * lppPropTagArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenProperty ( _                              ' VTable offser = 28
     BYVAL ulPropTag AS DWORD _                         ' __in ULONG ulPropTag
   , BYREF lpiid AS GUID _                              ' __in LPCIID lpiid
   , BYVAL ulInterfaceOptions AS DWORD _                ' __in ULONG ulInterfaceOptions
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppUnk AS IUnknown _                         ' __out LPUNKNOWN * lppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProps ( _                                  ' VTable offser = 32
     BYVAL cValues AS DWORD _                           ' __in ULONG cValues
   , BYVAL lpPropArray AS SPropValue PTR _              ' __in LPSPropValue lpPropArray [array]
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteProps ( _                               ' VTable offser = 36
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offser = 40
     BYVAL ciidExclude AS DWORD _                       ' __in ULONG ciidExclude
   , BYREF rgiidExclude AS GUID _                       ' __in LPCIID rgiidExclude
   , BYVAL lpExcludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpExcludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyProps ( _                                 ' VTable offser = 44
     BYVAL lpIncludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpIncludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNamesFromIDs ( _                           ' VTable offser = 48
     BYVAL lppPropTags AS SPropTagArray PTR _           ' __inout LPSPropTagArray * lppPropTags
   , BYREF lpPropSetGuid AS GUID _                      ' __in LPGUID lpPropSetGuid
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcPropNames AS DWORD _                      ' __out ULONG * lpcPropNames
   , BYREF lpppPropNames AS DWORD _                     ' __out LPMAPINAMEID * * lpppPropNames [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIDsFromNames ( _                           ' VTable offser = 52
     BYVAL cPropNames AS DWORD _                        ' __in ULONG cPropNames
   , BYVAL lppPropNames AS MAPINAMEID PTR _             ' __in LPMAPINAMEID * lppPropNames [array]
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppPropTags AS DWORD _                       ' __out LPSPropTagArray * lppPropTags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPropData Methods
   ' =====================================================================================
   METHOD HrSetObjAccess ( _                            ' VTable offser = 56
     BYVAL ulAccess AS DWORD _                          ' __in ULONG ulAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HrSetPropAccess ( _                           ' VTable offser = 60
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYREF rgulAccess AS DWORD _                        ' __in ULONG * rgulAccess [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HrGetPropAccess ( _                           ' VTable offser = 64
     BYVAL lppPropTagArray AS SPropTagArray PTR _       ' __in_out LPSPropTagArray * lppPropTagArray
   , BYREF lprgulAccess AS DWORD _                      ' __out ULONG * * lprgulAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HrAddObjProps ( _                             ' VTable offser = 68
     BYVAL lppPropTagArray AS SPropTagArray PTR _       ' __in LPSPropTagArray lppPropTagArray
   , BYVAL lprgulAccess AS SPropProblemArray PTR _      ' __in_out LPSPropProblemArray * lprgulAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/* Entry Point for in memory IMAPIProp */


'/*   CreateIProp()
' *      Creates the internal memory structures and object handle
' *      to bring a new property interface into existance.
' *
' *   lpInterface
' *      Interface ID of the TableData object (IID_IMAPIPropData)
' *
' *   lpAllocateBuffer, lpAllocateMore, and lpFreeBuffer
' *      Function addresses are provided by the caller so that
' *      this DLL allocates/frees memory appropriately.
' *   lppPropData
' *      Address of the pointer which will receive the IPropData object
' *   lpvReserved
' *      Reserved.  Should be NULL.
' */

DECLARE FUNCTION CreateIProp IMPORT "MAPI32.DLL" ALIAS "CreateIProp@24" ( _
   BYREF lpInterface AS GUID _                          ' __in LPCIID lpInterface
 , BYVAL lpAllocateBuffer AS DWORD _                    ' __in ALLOCATEBUFFER * lpAllocateBuffer
 , BYVAL lpAllocateMore AS DWORD _                      ' __in ALLOCATEMORE * lpAllocateMore
 , BYVAL lpFreeBuffer AS DWORD _                        ' __in FREEBUFFER * lpFreeBuffer
 , BYVAL lpvReserved AS DWORD _                         ' __in LPVOID lpvReserved
 , BYREF lppPropData AS IPropData _                     ' __out LPPROPDATA * lppPropData
 ) AS LONG                                              ' SCODE

DECLARE FUNCTION WABCreateIProp IMPORT "MAPI32.DLL" ALIAS "CreateIProp@24" ( _
   BYREF lpInterface AS GUID _                          ' __in LPCIID lpInterface
 , BYVAL lpAllocateBuffer AS DWORD _                    ' __in ALLOCATEBUFFER * lpAllocateBuffer
 , BYVAL lpAllocateMore AS DWORD _                      ' __in ALLOCATEMORE * lpAllocateMore
 , BYVAL lpFreeBuffer AS DWORD _                        ' __in FREEBUFFER * lpFreeBuffer
 , BYVAL lpvReserved AS DWORD _                         ' __in LPVOID lpvReserved
 , BYREF lppPropData AS IPropData _                     ' __out LPPROPDATA * lppPropData
 ) AS LONG                                              ' SCODE

'/*
' *   Defines for prop/obj access
' */
%IPROP_READONLY      = &H00000001???
%IPROP_READWRITE     = &H00000002???
%IPROP_CLEAN         = &H00010000???
%IPROP_DIRTY         = &H00020000???

'/*
' -   HrSetPropAccess
' -
' *   Sets access right attributes on a per-property basis.  By default,
' *   all properties are read/write.
' *
' */

'/*
' -   HrSetObjAccess
' -
' *   Sets access rights for the object itself.  By default, the object has
' *   read/write access.
' *
' */

#IF NOT %DEF(%NOIDLEENGINE)

'/* Idle time scheduler */

'/*
' *   PRI
' *
' *   Priority of an idle task.
' *   The idle engine sorts tasks by priority, and the one with the higher
' *   value runs first. Within a priority level, the functions are called
' *   round-robin.
' */

%PRILOWEST  = -32768
%PRIHIGHEST =  32767
%PRIUSER    =  0

'/*
' *   IRO
' *
' *   Idle routine options.  This is a combined bit mask consisting of
' *   individual firo's.   Listed below are the possible bit flags.
' *
' *      FIROWAIT and FIROINTERVAL are mutually exclusive.
' *      If neither of the flags are specified, the default action
' *      is to ignore the time parameter of the idle function and
' *      call it as often as possible if firoPerBlock is not set;
' *      otherwise call it one time only during the idle block
' *      once the time constraint has been set. FIROINTERVAL
' *      is also incompatible with FIROPERBLOCK.
' *
' *      FIROWAIT      - time given is minimum idle time before calling
' *                    for the first time in the block of idle time,
' *                    afterwhich call as often as possible.
' *      FIROINTERVAL   - time given is minimum interval between each
' *                    successive call
' *      FIROPERBLOCK   - called only once per contiguous block of idle
' *                    time
' *      FIRODISABLED   - initially disabled when registered, the
' *                    default is to enable the function when registered.
' *      FIROONCEONLY   - called only one time by the scheduler and then
' *                    deregistered automatically.
' */

%IRONULL        = &H0000??
%FIROWAIT       = &H0001??
%FIROINTERVAL   = &H0002??
%FIROPERBLOCK   = &H0004??
%FIRODISABLED   = &H0020??
%FIROONCEONLY   = &H0040??

'/*
' *   IRC
' *
' *   Idle routine change options. This is a combined bit mask consisting
' *   of individual firc's; each one identifies an aspect of the idle task
' *   that can be changed.
' *
' */

%IRCNULL       = &H0000??
%FIRCPFN       = &H0001??  ' /* change function pointer */
%FIRCPV        = &H0002??  ' /* change parameter block  */
%FIRCPRI       = &H0004??  ' /* change priority         */
%FIRCCSEC      = &H0008??  ' /* change time            */
%FIRCIRO       = &H0010??  ' /* change routine options  */

'/*
' *   Type definition for idle functions.    An idle function takes one
' *   parameter, an PV, and returns a BOOL value.
' */

'typedef BOOL (STDAPICALLTYPE FNIDLE) (LPVOID);
'typedef FNIDLE *PFNIDLE;

'/*
' *   FTG
' *
' *   Function Tag.  Used to identify a registered idle function.
' *
' */

'typedef void *FTG;
'typedef FTG  *PFTG;
'#define FTGNULL         ((FTG) NULL)

'/*
' -   MAPIInitIdle/MAPIDeinitIdle
' -
' *   Purpose:
' *      Initialises the idle engine
' *      If the initialisation succeded, returns 0, else returns -1
' *
' *   Arguments:
' *      lpvReserved      Reserved, must be NULL.
' */

DECLARE FUNCTION MAPIInitIdle IMPORT "MAPI32.DLL" ALIAS "MAPIInitIdle@4" ( _
   BYVAL lpvReserved AS DWORD _                         ' __in LPVOID lpvReserved
 ) AS LONG                                              ' LONG

DECLARE SUB MAPIDeInitIdle IMPORT "MAPI32.DLL" ALIAS "MAPIDeInitIdle@0" ()

'/*
' *   FtgRegisterIdleRoutine
' *
' *      Registers the function pfn of type PFNIDLE, i.e., (BOOL (*)(LPVOID))
' *      as an idle function.
' *
' *      The idle function will be called with the parameter pv by the
' *      idle engine. The function has initial priority priIdle,
' *      associated time csecIdle, and options iroIdle.
' */

DECLARE FUNCTION FtgRegisterIdleRoutine IMPORT "MAPI32.DLL" ALIAS "FtgRegisterIdleRoutine@20" ( _
   BYVAL pfnIdle AS DWORD _                             ' __in PFNIDLE pfnIdle
 , BYVAL pvIdleParam AS DWORD _                         ' __in LPVOID pvIdleParam
 , BYVAL priIdle AS INTEGER _                           ' __in short priIdle
 , BYVAL csecIdle AS DWORD _                            ' __in ULONG csecIdle
 , BYVAL iroIdle AS WORD _                              ' __in USHORT iroIdle
 ) AS DWORD                                             ' FTG

'/*
' *   DeregisterIdleRoutine
' *
' *      Removes the given routine from the list of idle routines.
' *      The routine will not be called again.  It is the responsibility
' *      of the caller to clean up any data structures pointed to by the
' *      pvIdleParam parameter; this routine does not free the block.
' */

DECLARE SUB DeregisterIdleRoutine IMPORT "MAPI32.DLL" ALIAS "DeregisterIdleRoutine@4" ( _
   BYVAL ftg AS DWORD _                                 ' __in FTG ftg
 )                                                      ' void

'/*
' *   EnableIdleRoutine
' *
' *      Enables or disables an idle routine.
' */

DECLARE SUB EnableIdleRoutine IMPORT "MAPI32.DLL" ALIAS "EnableIdleRoutine@8" ( _
   BYVAL ftg AS DWORD _                                 ' __in FTG ftg
 , BYVAL fEnable AS LONG _                              ' __in BOOL fEnable
 )                                                      ' void

'/*
' *   ChangeIdleRoutine
' *
' *      Changes some or all of the characteristics of the given idle
' *      function. The changes to make are indicated with flags in the
' *      ircIdle parameter.
' */

DECLARE SUB ChangeIdleRoutine IMPORT "MAPI32.DLL" ALIAS "ChangeIdleRoutine@28" ( _
   BYVAL ftg AS DWORD _                                 ' __in FTG ftg
 , BYVAL pfnIdle AS DWORD _                             ' __in PFNIDLE pfnIdle
 , BYVAL pvIdleParam AS DWORD _                         ' __in LPVOID pvIdleParam
 , BYVAL priIdle AS INTEGER _                           ' __in short priIdle
 , BYVAL csecIdle AS DWORD _                            ' __in ULONG csecIdle
 , BYVAL iroIdle AS WORD _                              ' __in USHORT iroIdle
 , BYVAL ircIdle AS WORD _                              ' __in USHORT ircIdle
 )                                                      ' void


#ENDIF   ' /* ! NOIDLEENGINE */


'/* IMalloc Utilities */

DECLARE FUNCTION MAPIGetDefaultMalloc IMPORT "MAPI32.DLL" ALIAS "MAPIGetDefaultMalloc@0" () AS DWORD


'/* StreamOnFile (SOF) */

'/*
' *   Methods and #define's for implementing an OLE 2.0 storage stream
' *   (as defined in the OLE 2.0 specs) on top of a system file.
' */

%SOF_UNIQUEFILENAME = &H80000000&

DECLARE FUNCTION OpenStreamOnFile IMPORT "MAPI32.DLL" ALIAS "OpenStreamOnFile" ( _
   BYVAL lpAllocateBuffer AS DWORD _                    ' __in LPALLOCATEBUFFER lpAllocateBuffer
 , BYVAL lpFreeBuffer AS DWORD _                        ' __in LPFREEBUFFER lpFreeBuffer
 , BYVAL ulFlags AS DWORD _                             ' __in ULONG ulFlags
 , BYREF lpszFileName AS ASCIIZ _                       ' __in LPTSTR lpszFileName
 , BYREF lpszPrefix AS ASCIIZ _                         ' __in_opt LPTSTR lpszPrefix
 , BYREF lppStream AS IStream _                         ' __out LPSTREAM * lppStream
 ) AS LONG                                              ' HRESULT

$OPENSTREAMONFILE = "OpenStreamOnFile"

'/* Property interface utilities */

'/*
' *   Copies a single SPropValue from Src to Dest.  Handles all the various
' *   types of properties and will link its allocations given the master
' *   allocation object and an allocate more function.
' */

DECLARE FUNCTION PropCopyMore IMPORT "MAPI32.DLL" ALIAS "PropCopyMore@16" ( _
   BYREF lpSPropValueDest AS SPropValue _               ' __out LPSPropValue lpSPropValueDest
 , BYREF lpSPropValueSrc AS SPropValue _                ' __in LPSPropValue lpSPropValueSrc
 , BYVAL lpfAllocMore AS DWORD _                        ' __in ALLOCATEMORE * lpfAllocMore
 , BYVAL lpvObject AS DWORD _                           ' __in LPVOID lpvObject
 ) AS LONG                                              ' SCODE

'/*
' *   Returns the size in bytes of structure at lpSPropValue, including the
' *   Value.
' */

DECLARE FUNCTION UlPropSize IMPORT "MAPI32.DLL" ALIAS "UlPropSize@4" ( _
   BYREF lpSPropValue AS SPropValue _                   ' __in LPSPropValue lpSPropValue
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION FEqualNames IMPORT "MAPI32.DLL" ALIAS "FEqualNames@8" ( _
   BYREF lpName1 AS MAPINAMEID _                        ' __in LPMAPINAMEID lpName1
 , BYREF lpName2 AS MAPINAMEID _                        ' __in LPMAPINAMEID lpName2
 ) AS LONG                                              ' BOOL

DECLARE SUB GetInstance IMPORT "MAPI32.DLL" ALIAS "GetInstance" ( _
   BYREF pvalMv AS SPropValue _                         ' __in LPSPropValue pvalMv
 , BYREF pvalSv AS SPropValue _                         ' __in LPSPropValue pvalSv
 , BYVAL uliInst AS DWORD _                             ' __in ULONG uliInst
 )                                                      ' void

'extern char rgchCsds[];
'extern char rgchCids[];
'extern char rgchCsdi[];
'extern char rgchCidi[];

DECLARE FUNCTION FPropContainsProp IMPORT "MAPI32.DLL" ALIAS "FPropContainsProp@12" ( _
   BYREF lpSPropValueDst AS SPropValue _                ' __in LPSPropValue lpSPropValueDst
 , BYREF lpSPropValueSrc AS SPropValue _                ' __in LPSPropValue lpSPropValueSrc
 , BYVAL ulFuzzyLevel AS DWORD _                        ' __in ULONG ulFuzzyLevel
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FPropCompareProp IMPORT "MAPI32.DLL" ALIAS "FPropCompareProp@12" ( _
   BYREF lpSPropValue1 AS SPropValue _                  ' __in LPSPropValue lpSPropValue1
 , BYVAL ulRelOp AS DWORD _                             ' __in ULONG ulRelOp
 , BYREF lpSPropValue2 AS SPropValue _                  ' __in LPSPropValue lpSPropValue2
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION LPropCompareProp IMPORT "MAPI32.DLL" ALIAS "LPropCompareProp@8" ( _
   BYREF lpSPropValueA AS SPropValue _                  ' __in LPSPropValue lpSPropValueA
 , BYREF lpSPropValueB AS SPropValue _                  ' __in LPSPropValue lpSPropValueB
 ) AS LONG                                              ' LONG

DECLARE FUNCTION HrAddColumns IMPORT "MAPI32.DLL" ALIAS "HrAddColumns@16" ( _
   BYVAL lptbl AS IMAPITable _                          ' __in LPMAPITABLE lptbl
 , BYVAL lpproptagColumnsNew AS SPropTagArray PTR _     ' __in LPSPropTagArray lpproptagColumnsNew
 , BYVAL lpAllocateBuffer AS DWORD _                    ' __in LPALLOCATEBUFFER lpAllocateBuffer
 , BYVAL lpFreeBuffer AS DWORD _                        ' __in LPFREEBUFFER lpFreeBuffer
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION HrAddColumnsEx IMPORT "MAPI32.DLL" ALIAS "HrAddColumnsEx@20" ( _
   BYVAL lptbl AS IMAPITable _                          ' __in LPMAPITABLE lptbl
 , BYVAL lpproptagColumnsNew AS SPropTagArray PTR _     ' __in LPSPropTagArray lpproptagColumnsNew
 , BYVAL lpAllocateBuffer AS DWORD _                    ' __in LPALLOCATEBUFFER lpAllocateBuffer
 , BYVAL lpFreeBuffer AS DWORD _                        ' __in LPFREEBUFFER lpFreeBuffer
 , BYVAL lpfnFilterColumns AS DWORD _                   ' __in void (FAR * lpfnFilterColumns) (LPSPropTagArray ptaga)
 ) AS LONG                                              ' HRESULT


'/* Notification utilities */

'/*
' *   Function that creates an advise sink object given a notification
' *   callback function and context.
' */

DECLARE FUNCTION HrAllocAdviseSink IMPORT "MAPI32.DLL" ALIAS "HrAllocAdviseSink" ( _
   BYVAL lpfnCallback AS DWORD _                        ' __in LPNOTIFCALLBACK lpfnCallback
 , BYVAL lpvContext AS DWORD _                          ' __in LPVOID lpvContext
 , BYREF lppAdviseSink AS IMAPIAdviseSink _             ' __out LPMAPIADVISESINK * lppAdviseSink
 ) AS LONG                                              ' HRESULT

'/*
' *   Wraps an existing advise sink with another one which guarantees
' *   that the original advise sink will be called in the thread on
' *   which it was created.
' */

DECLARE FUNCTION HrThisThreadAdviseSink IMPORT "MAPI32.DLL" ALIAS "HrThisThreadAdviseSink@8" ( _
   BYVAL lpAdviseSink AS IMAPIAdviseSink _              ' __in LPMAPIADVISESINK lpAdviseSink
 , BYREF lppAdviseSink AS IMAPIAdviseSink _             ' __out LPMAPIADVISESINK * lppAdviseSink
 ) AS LONG                                              ' HRESULT

'/*
' *   Allows a client and/or provider to force notifications
' *   which are currently queued in the MAPI notification engine
' *   to be dispatched without doing a message dispatch.
' */

DECLARE FUNCTION HrDispatchNotifications IMPORT "MAPI32.DLL" ALIAS "HrDispatchNotifications@4" ( _
   BYVAL ulFlags AS DWORD _                             ' __in ULONG ulFlags
 ) AS LONG                                              ' HRESULT

'/* Service Provider Utilities */

'/*
' *   Structures and utility function for building a display table
' *   from resources.
' */

'typedef struct {
'   ULONG         ulCtlType;         /* DTCT_LABEL, etc. */
'   ULONG         ulCtlFlags;        /* DT_REQUIRED, etc. */
'   LPBYTE        lpbNotif;          /*   pointer to notification data */
'   ULONG         cbNotif;           /* count of bytes of notification data */
'   LPTSTR        lpszFilter;        /* character filter for edit/combobox */
'   ULONG         ulItemID;          /* to validate parallel dlg template entry */
'   union {                          /* ulCtlType discriminates */
'      LPVOID            lpv;        /* Initialize this to avoid warnings */
'      LPDTBLLABEL       lplabel;
'      LPDTBLEDIT        lpedit;
'      LPDTBLLBX         lplbx;
'      LPDTBLCOMBOBOX    lpcombobox;
'      LPDTBLDDLBX       lpddlbx;
'      LPDTBLCHECKBOX    lpcheckbox;
'      LPDTBLGROUPBOX    lpgroupbox;
'      LPDTBLBUTTON      lpbutton;
'      LPDTBLRADIOBUTTON lpradiobutton;
'      LPDTBLMVLISTBOX   lpmvlbx;
'      LPDTBLMVDDLBX     lpmvddlbx;
'      LPDTBLPAGE        lppage;
'   } ctl;
'} DTCTL, *LPDTCTL;

' // Size = 4 bytes
UNION DTCTL_UNION
   lpv           AS DWORD                 ' LPVOID
   lplabel       AS DTBLLABEL       PTR   ' LPDTBLLABEL
   lpedit        AS DTBLEDIT        PTR   ' LPDTBLEDIT
   lplbx         AS DTBLLBX         PTR   ' LPDTBLLBX
   lpcombobox    AS DTBLCOMBOBOX    PTR   ' LPDTBLCOMBOBOX
   lpddlbx       AS DTBLDDLBX       PTR   ' LPDTBLDDLBX
   lpcheckbox    AS DTBLCHECKBOX    PTR   ' LPDTBLCHECKBOX
   lpgroupbox    AS DTBLGROUPBOX    PTR   ' LPDTBLGROUPBOX
   lpbutton      AS DTBLBUTTON      PTR   ' LPDTBLBUTTON
   lpradiobutton AS DTBLRADIOBUTTON PTR   ' LPDTBLRADIOBUTTON
   lpmvlbx       AS DTBLMVLISTBOX   PTR   ' LPDTBLMVLISTBOX
   lpmvddlbx     AS DTBLMVDDLBX     PTR   ' LPDTBLMVDDLBX
   lppage        AS DTBLPAGE        PTR   ' LPDTBLPAGE
END UNION

' // Size = 28 bytes
TYPE DTCTL DWORD
   ulCtlType  AS DWORD        ' ULONG
   ulCtlFlags AS DWORD        ' ULONG
   lpbNotif   AS GUID PTR     ' LPBYTE
   cbNotif    AS DWORD        ' ULONG
   lpszFilter AS ASCIIZ PTR   ' LPTSTR
   ulItemID   AS DWORD        ' ULONG
   ctl AS DTCTL_UNION
END TYPE

'typedef struct {
'   ULONG          cctl;
'   LPTSTR         lpszResourceName;   /* as usual, may be an integer ID */
'   union {                            /* as usual, may be an integer ID */
'      LPTSTR      lpszComponent;
'      ULONG       ulItemID;
'   };
'   LPDTCTL        lpctl;
'} DTPAGE, *LPDTPAGE;

' // Size = 4 bytes
UNION DTPAGE_UNION DWORD
   lpszComponent AS ASCIIZ PTR   ' LPTSTR
   ulItemID      AS DWORD        ' ULONG
END UNION

' // Size = 16 bytes
TYPE DTPAGE
   cctl             AS DWORD        ' ULONG
   lpszResourceName AS ASCIIZ PTR   ' LPTSTR
   DTPAGE_UNION
   lpctl            AS DWORD        ' LPDTCTL [array]
END TYPE

DECLARE FUNCTION BuildDisplayTable IMPORT "MAPI32.DLL" ALIAS "BuildDisplayTable@40" ( _
   BYVAL lpAllocateBuffer AS DWORD _                    ' __in LPALLOCATEBUFFER lpAllocateBuffer
 , BYVAL lpAllocateMore AS DWORD _                      ' __in LPALLOCATEMORE lpAllocateMore
 , BYVAL lpFreeBuffer AS DWORD _                        ' __in LPFREEBUFFER lpFreeBuffer
 , BYVAL lpMalloc AS IMalloc _                          ' __in LPMALLOC lpMalloc
 , BYVAL hInstance AS DWORD _                           ' __in HINSTANCE hInstance
 , BYVAL cPages AS DWORD _                              ' __in UINT cPages
 , BYREF lpPage AS DTPAGE _                             ' __in LPDTPAGE lpPage
 , BYVAL ulFlags AS DWORD _                             ' __in ULONG ulFlags
 , BYREF lppTable AS IMAPITable _                       ' __out LPMAPITABLE lppTable
 , BYREF lppTblData AS ITableData _                     ' __out LPTABLEDATA lppTblData
 ) AS LONG                                              ' HRESULT


'/* MAPI structure validation/copy utilities */

'/*
' *   Validate, copy, and adjust pointers in MAPI structures:
' *      notification
' *      property value array
' *      option data
' */

DECLARE FUNCTION ScCountNotifications IMPORT "MAPI32.DLL" ALIAS "ScCountNotifications@12" ( _
   BYVAL cntf AS LONG _                                 ' __in int cntf
 , BYREF rgntf AS NOTIFICATION _                        ' __in LPNOTIFICATION rgntf
 , BYREF pcb AS DWORD _                                 ' __out ULONG * pcb
 ) AS LONG                                              ' SCODE

DECLARE FUNCTION ScCopyNotifications IMPORT "MAPI32.DLL" ALIAS "ScCopyNotifications@16" ( _
   BYVAL cntf AS LONG _                                 ' __in int cntf
 , BYREF rgntf AS NOTIFICATION _                        ' __in LPNOTIFICATION rgntf [array]
 , BYVAL pvDst AS DWORD _                               ' __in LPVOID pvDst
 , BYREF pcb AS DWORD _                                 ' __out ULONG * pcb
 ) AS LONG                                              ' SCODE

DECLARE FUNCTION ScRelocNotifications IMPORT "MAPI32.DLL" ALIAS "ScRelocNotifications@20" ( _
   BYVAL cntf AS LONG _                                 ' __in int cntf
 , BYREF rgntf AS NOTIFICATION _                        ' __in LPNOTIFICATION rgntf
 , BYVAL pvBaseOld AS DWORD _                           ' __in LPVOID pvBaseOld
 , BYVAL pvBaseNew AS DWORD _                           ' __in LPVOID pvBaseNew
 , BYREF pcb AS DWORD _                                 ' __out ULONG * pcb
 ) AS LONG                                              ' SCODE

DECLARE FUNCTION ScCountProps IMPORT "MAPI32.DLL" ALIAS "ScCountProps@12" ( _
   BYVAL cprop AS LONG _                                ' __in int cprop
 , BYREF rgprop AS SPropValue _                         ' __in LPSPropValue rgprop [array]
 , BYREF pcb AS DWORD _                                 ' __out ULONG * pcb
 ) AS LONG                                              ' SCODE

DECLARE FUNCTION LpValFindProp IMPORT "MAPI32.DLL" ALIAS "LpValFindProp@12" ( _
   BYVAL ulPropTag AS DWORD _                           ' __in ULONG ulPropTag
 , BYVAL cValues AS DWORD _                             ' __in ULONG cValues
 , BYREF lpPropArray AS SPropValue _                    ' __in LPSPropValue lpPropArray
 ) AS LONG                                              ' SCODE

DECLARE FUNCTION ScCopyProps IMPORT "MAPI32.DLL" ALIAS "ScCopyProps@16" ( _
   BYVAL cprop AS LONG _                                ' __in int cprop
 , BYREF rgprop AS SPropValue _                         ' __in LPSPropValue rgprop [array]
 , BYVAL pvDst AS DWORD _                               ' __in LPVOID pvDst
 , BYREF pcb AS DWORD _                                 ' __out ULONG * pcb
 ) AS LONG                                              ' SCODE

DECLARE FUNCTION ScRelocProps IMPORT "MAPI32.DLL" ALIAS "ScRelocProps@20" ( _
   BYVAL cprop AS LONG _                                ' __in int cprop
 , BYREF rgprop AS SPropValue _                         ' __in LPSPropValue rgprop
 , BYVAL pvBaseOld AS DWORD _                           ' __in LPVOID pvBaseOld
 , BYVAL pvBaseNew AS DWORD _                           ' __in LPVOID pvBaseNew
 , BYREF pcb AS DWORD _                                 ' __out ULONG * pcb
 ) AS LONG                                              ' SCODE

DECLARE FUNCTION ScDupPropset IMPORT "MAPI32.DLL" ALIAS "ScDupPropset@16" ( _
   BYVAL cprop AS LONG _                                ' __in int cprop
 , BYVAL rgprop AS DWORD _                              ' __in LPSPropValue rgprop
 , BYVAL lpAllocateBuffer AS DWORD _                    ' __in LPALLOCATEBUFFER lpAllocateBuffer
 , BYREF prgprop AS DWORD _                             ' __out LPSPropValue * prgprop
 ) AS LONG                                              ' SCODE

'/* General utility functions */

'/* Related to the OLE Component object model */

DECLARE FUNCTION UlAddRef IMPORT "MAPI32.DLL" ALIAS "UlAddRef@4" ( _
   BYVAL punk AS DWORD _                                ' __in LPVOID punk
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION UlRelease IMPORT "MAPI32.DLL" ALIAS "UlRelease@4" ( _
   BYVAL punk AS DWORD _                                ' __in LPVOID punk
 ) AS DWORD                                             ' ULONG

'/* Related to the MAPI interface */

DECLARE FUNCTION HrGetOneProp IMPORT "MAPI32.DLL" ALIAS "HrGetOneProp@12" ( _
   BYVAL pmp AS IMAPIProp _                             ' __in LPMAPIPROP pmp
 , BYVAL ulPropTag AS DWORD _                           ' __in ULONG ulPropTag
 , BYREF ppprop AS DWORD _                              ' __out LPSPropValue * ppprop
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION HrSetOneProp IMPORT "MAPI32.DLL" ALIAS "HrSetOneProp@8" ( _
   BYVAL pmp AS IMAPIProp _                             ' __in LPMAPIPROP pmp
 , BYREF pprop AS SPropValue _                          ' __in LPSPropValue pprop
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION FPropExists IMPORT "MAPI32.DLL" ALIAS "FPropExists@8" ( _
   BYVAL pobj AS IMAPIProp _                            ' __in LPMAPIPROP pobj
 , BYVAL ulPropTag AS DWORD _                           ' __in ULONG ulPropTag
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PpropFindProp IMPORT "MAPI32.DLL" ALIAS "PpropFindProp@12" ( _
   BYREF rgprop AS SPropValue _                         ' __in LPSPropValue rgprop [array]
 , BYVAL cprop AS DWORD _                               ' __in ULONG cprop
 , BYVAL ulPropTag AS DWORD _                           ' __in ULONG ulPropTag
 ) AS DWORD                                             ' LPSPropValue

DECLARE SUB FreePadrlist IMPORT "MAPI32.DLL" ALIAS "FreePadrlist@4" ( _
   BYVAL padrlist AS ADRLIST PTR _                      ' __in LPADRLIST padrlist
 )                                                      ' void

DECLARE SUB FreeProws IMPORT "MAPI32.DLL" ALIAS "FreeProws@4" ( _
   BYVAL prows AS SRowSet PTR _                         ' __in LPSRowSet prows
 )                                                      ' void

DECLARE FUNCTION HrQueryAllRows IMPORT "MAPI32.DLL" ALIAS "HrQueryAllRows@24" ( _
   BYVAL ptable AS IMAPITable _                         ' __in LPMAPITABLE ptable
 , BYVAL ptaga AS SPropTagArray PTR _                   ' __in LPSPropTagArray ptaga
 , BYREF pres AS SRestriction _                         ' __in LPSRestriction pres
 , BYVAL psos AS SSortOrderSet PTR _                    ' __in LPSSortOrderSet psos
 , BYVAL crowsMax AS DWORD _                            ' __in LONG crowsMax
 , BYREF pprows AS DWORD _                              ' __out LPSRowSet * pprows
 ) AS LONG                                              ' HRESULT

'/* Create or validate the IPM folder tree in a message store */

%MAPI_FORCE_CREATE  = 1
%MAPI_FULL_IPM_TREE = 2

DECLARE FUNCTION HrValidateIPMSubtree IMPORT "MAPI32.DLL" ALIAS "HrValidateIPMSubtree@20" ( _
   BYVAL lpMDB AS IMsgStore _                           ' __in LPMDB lpMDB
 , BYVAL ulFlags AS DWORD _                             ' __in ULONG ulFlags
 , BYREF lpcValues AS DWORD _                           ' __in_out ULONG * lpcValues
 , BYVAL lppProps AS SPropValue PTR _                   ' __in_out LPSPropValue * lppProps
 , BYREF lppMapiError AS DWORD _                        ' __out LPMAPIERROR * lppMapiError
 ) AS LONG                                              ' HRESULT

'/* Encoding and decoding strings */

DECLARE FUNCTION FBinFromHex IMPORT "MAPI32.DLL" ALIAS "FBinFromHex@8" ( _
   BYREF sz AS ASCIIZ _                                 ' __in LPTSTR sz
 , BYREF pb AS ANY _                                    ' __out LPBYTE pb
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ScBinFromHexBounded IMPORT "MAPI32.DLL" ALIAS "ScBinFromHexBounded@12" ( _
   BYREF sz AS ASCIIZ _                                 ' __in LPTSTR sz
 , BYREF pb AS ANY _                                    ' __out LPBYTE pb
 , BYVAL cb AS DWORD _                                  ' __in ULONG cb
 ) AS LONG                                              ' SCODE

DECLARE SUB HexFromBin IMPORT "MAPI32.DLL" ALIAS "HexFromBin@12" ( _
   BYVAL pb AS BYTE PTR _                               ' __in LPBYTE pb
 , BYVAL cb AS LONG _                                   ' __in int cb
 , BYREF sz AS ASCIIZ _                                 ' __out LPTSTR sz
 )                                                      ' void

DECLARE FUNCTION UlFromSzHex IMPORT "MAPI32.DLL" ALIAS "UlFromSzHex@4" ( _
   BYREF lpsz AS ASCIIZ _                               ' __in LPCTSTR lpsz
 ) AS DWORD                                             ' ULONG

'/* Encoding and decoding entry IDs */

DECLARE FUNCTION HrEntryIDFromSz IMPORT "MAPI32.DLL" ALIAS "HrEntryIDFromSz@12" ( _
   BYREF sz AS ASCIIZ _                                 ' __in LPTSTR sz
 , BYREF pcb AS DWORD _                                 ' __out ULONG * pcb
 , BYREF ppentry AS DWORD _                             ' __out LPENTRYID * ppentry
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION HrSzFromEntryID IMPORT "MAPI32.DLL" ALIAS "HrSzFromEntryID@12" ( _
   BYVAL cb AS DWORD _                                  ' __in ULONG cb
 , BYVAL pentry AS ENTRYID PTR _                        ' __in LPENTRYID pentry
 , BYREF psz AS DWORD _                                 ' __out LPTSTR * psz
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION HrComposeEID IMPORT "MAPI32.DLL" ALIAS "HrComposeEID@28" ( _
   BYVAL psession AS IMAPISession _                     ' __in LPMAPISESSION psession
 , BYVAL cbStoreRecordKey AS DWORD _                    ' __in ULONG cbStoreRecordKey
 , BYVAL pStoreRecordKey AS BYTE PTR _                  ' __in LPBYTE pStoreRecordKey
 , BYVAL cbMsgEID AS DWORD _                            ' __in ULONG cbMsgEID
 , BYVAL pMsgEID AS ENTRYID PTR _                       ' __in LPENTRYID pMsgEID
 , BYREF pcbEID AS DWORD _                              ' __out ULONG * pcbEID
 , BYREF ppEID AS DWORD _                               ' __out LPENTRYID * ppEID
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION HrDecomposeEID IMPORT "MAPI32.DLL" ALIAS "HrDecomposeEID@24" ( _
   BYVAL psession AS IMAPISession _                     ' __in LPMAPISESSION psession
 , BYVAL cbEID AS DWORD _                               ' __in ULONG cbEID
 , BYVAL pEID AS ENTRYID PTR _                          ' __in LPENTRYID pEID
 , BYREF pcbStoreEID AS DWORD _                         ' __out ULONG * pcbStoreEID
 , BYREF ppStoreEID AS DWORD _                          ' __out LPENTRYID * ppStoreEID
 , BYREF pcbMsgEID AS DWORD _                           ' __out ULONG * pcbMsgEID
 , BYREF ppMsgEID AS DWORD _                            ' __out LPENTRYID * ppMsgEID
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION HrComposeMsgID IMPORT "MAPI32.DLL" ALIAS "HrComposeMsgID@24" ( _
   BYVAL psession AS IMAPISession _                     ' __in LPMAPISESSION psession
 , BYVAL cbStoreRecordKey AS DWORD _                    ' __in ULONG cbStoreRecordKey
 , BYVAL pStoreRecordKey AS BYTE PTR _                  ' __in LPBYTE pStoreRecordKey
 , BYVAL cbMsgEID AS DWORD _                            ' __in ULONG cbMsgEID
 , BYVAL pMsgEID AS ENTRYID PTR _                       ' __in LPENTRYID pMsgEID
 , BYREF pszMsgID AS DWORD _                            ' __out LPTSTR * pszMsgID
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION HrDecomposeMsgID IMPORT "MAPI32.DLL" ALIAS "HrDecomposeMsgID" ( _
   BYVAL psession AS IMAPISession _                     ' __in LPMAPISESSION psession
 , BYREF szMsgID AS ASCIIZ _                            ' __in LPTSTR szMsgID
 , BYREF pcbStoreEID AS DWORD _                         ' __out ULONG * pcbStoreEID
 , BYREF ppStoreEID AS DWORD _                          ' __out LPENTRYID * ppStoreEID
 , BYREF pcbMsgEID AS DWORD _                           ' __out ULONG * pcbMsgEID
 , BYREF ppMsgEID AS DWORD _                            ' __out LPENTRYID * ppMsgEID
 ) AS LONG                                              ' HRESULT

'/* C runtime substitutes */

DECLARE FUNCTION SzFindCh IMPORT "MAPI32.DLL" ALIAS "SzFindCh@8" ( _
   BYREF lpsz AS ASCIIZ _                               ' __in LPCTSTR lpsz
 , BYVAL ch AS WORD _                                   ' __in USHORT ch
 ) AS DWORD                                             ' LPTSTR

DECLARE FUNCTION SzFindLastCh IMPORT "MAPI32.DLL" ALIAS "SzFindLastCh@8" ( _
   BYREF lpsz AS ASCIIZ _                               ' __in LPCTSTR lpsz
 , BYVAL ch AS WORD _                                   ' __in USHORT ch
 ) AS DWORD                                             ' LPTSTR

DECLARE FUNCTION SzFindSz IMPORT "MAPI32.DLL" ALIAS "SzFindSz@8" ( _
   BYREF lpsz AS ASCIIZ _                               ' __in LPCTSTR lpsz
 , BYREF lpszKey AS ASCIIZ _                            ' __in LPCTSTR lpszKey
 ) AS DWORD                                             ' LPTSTR

DECLARE FUNCTION UFromSz IMPORT "MAPI32.DLL" ALIAS "UFromSz@4" ( _
   BYREF lpsz AS ASCIIZ _                               ' __in LPCTSTR lpsz
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION ScUNCFromLocalPath IMPORT "MAPI32.DLL" ALIAS "ScUNCFromLocalPath@12" ( _
   BYREF szLocal AS ASCIIZ _                            ' __in LPSTR szLocal
 , BYREF szUNC AS ASCIIZ _                              ' __out LPSTR szUNC
 , BYVAL cchUNC AS DWORD _                              ' __in UINT cchUNC
 ) AS LONG                                              ' SCODE

DECLARE FUNCTION ScLocalPathFromUNC IMPORT "MAPI32.DLL" ALIAS "ScLocalPathFromUNC@12" ( _
   BYREF szUNC AS ASCIIZ _                              ' __in LPSTR szUNC
 , BYREF szLocal AS ASCIIZ _                            ' __out LPSTR szLocal
 , BYVAL cchLocal AS DWORD _                            ' __in UINT cchLocal
 ) AS LONG                                              ' SCODE

'/* 64-bit arithmetic with times */

DECLARE FUNCTION FtAddFt IMPORT "MAPI32.DLL" ALIAS "FtAddFt@16" ( _
   BYVAL Addend1 AS FILETIME _                          ' __in FILETIME Addend1
 , BYVAL Addend2 AS FILETIME _                          ' __in FILETIME Addend2
 ) AS DWORD                                             ' FILETIME

DECLARE FUNCTION FtMulDwDw IMPORT "MAPI32.DLL" ALIAS "FtMulDwDw@8" ( _
   BYVAL Multiplicand AS DWORD _                        ' __in DWORD Multiplicand
 , BYVAL Multiplier AS DWORD _                          ' __in DWORD Multiplier
 ) AS DWORD                                             ' FILETIME

DECLARE FUNCTION FtMulDw IMPORT "MAPI32.DLL" ALIAS "FtMulDw@12" ( _
   BYVAL Multiplier AS DWORD _                          ' __in DWORD Multiplier
 , BYVAL Multiplicand AS FILETIME _                     ' __in FILETIME Multiplicand
 ) AS DWORD                                             ' FILETIME

DECLARE FUNCTION FtSubFt IMPORT "MAPI32.DLL" ALIAS "FtSubFt@16" ( _
   BYVAL Minuend AS FILETIME _                          ' __in FILETIME Minuend
 , BYVAL Subtrahend AS FILETIME _                       ' __in FILETIME Subtrahend
 ) AS DWORD                                             ' FILETIME

DECLARE FUNCTION FtNegFt IMPORT "MAPI32.DLL" ALIAS "FtNegFt@8" ( _
   BYVAL ft AS FILETIME _                               ' __in FILETIME ft
 ) AS DWORD                                             ' FILETIME

'/* Message composition */

DECLARE FUNCTION ScCreateConversationIndex IMPORT "MAPI32.DLL" ALIAS "ScCreateConversationIndex@16" ( _
   BYVAL cbParent AS DWORD _                            ' ULONG cbParent
 , BYVAL lpbParent AS BYTE PTR _                        ' LPBYTE lpbParent
 , BYREF lpcbConvIndex AS DWORD _                       ' ULONG * lpcbConvIndex
 , BYREF lppbConvIndex AS ANY _                         ' LPBYTE * lppbConvIndex
 ) AS LONG                                              ' SCODE

'/* Store support */

DECLARE FUNCTION WrapStoreEntryID IMPORT "MAPI32.DLL" ALIAS "WrapStoreEntryID@24" ( _
   BYVAL ulFlags AS DWORD _                             ' __in ULONG ulFlags
 , BYREF szDLLName AS ASCIIZ _                          ' __in LPTSTR szDLLName
 , BYVAL cbOrigEntry AS DWORD _                         ' __in ULONG cbOrigEntry
 , BYVAL lpOrigEntry AS ENTRYID PTR _                   ' __in LPENTRYID lpOrigEntry
 , BYREF lpcbWrappedEntry AS DWORD _                    ' __out ULONG * lpcbWrappedEntry
 , BYREF lppWrappedEntry AS DWORD _                     ' __out LPENTRYID * lppWrappedEntry
 ) AS LONG                                              ' HRESULT

'/* RTF Sync Utilities */

%RTF_SYNC_RTF_CHANGED   = &H00000001&
%RTF_SYNC_BODY_CHANGED  = &H00000002&

DECLARE FUNCTION RTFSync IMPORT "MAPI32.DLL" ALIAS "RTFSync" ( _
   BYVAL lpMessage AS IMessage _                        ' __in LPMESSAGE lpMessage
 , BYVAL ulFlags AS DWORD _                             ' __in ULONG ulFlags
 , BYREF lpfMessageUpdated AS LONG _                    ' __out BOOL * lpfMessageUpdated
 ) AS LONG                                              ' HRESULT


'/* Flags for WrapCompressedRTFStream() */

'/****** MAPI_MODIFY            ((ULONG) 0x00000001) mapidefs.h */
'/****** STORE_UNCOMPRESSED_RTF   ((ULONG) 0x00008000) mapidefs.h */

DECLARE FUNCTION WrapCompressedRTFStream IMPORT "MAPI32.DLL" ALIAS "WrapCompressedRTFStream" ( _
   BYVAL lpCompressedRTFStream AS IStream _             ' __in LPSTREAM lpCompressedRTFStream
 , BYVAL ulflags AS DWORD _                             ' __in ULONG ulflags
 , BYREF lpUncompressedRTFStream AS IStream _           ' __out LPSTREAM * lpUncompressedRTFStream
 ) AS LONG                                              ' HRESULT

'/* Storage on Stream */

'#if defined(_WIN32) || defined(WIN16)
DECLARE FUNCTION HrIStorageFromStream IMPORT "MAPI32.DLL" ALIAS "HrIStorageFromStream" ( _
   BYVAL lpUnkIn AS IUnknown _                          ' LPUNKNOWN lpUnkIn
 , BYREF lpInterface AS GUID _                          ' PIID lpInterface
 , BYVAL ulFlags AS DWORD _                             ' ULONG ulFlags
 , BYREF lppStorageOut AS IStorage _                    ' LPSTORAGE * lppStorageOut
 ) AS LONG                                              ' HRESULT
'#endif


'/*
' * Setup and cleanup.
' *
' * Providers never need to make these calls.
' *
' * Test applications and the like which do not call MAPIInitialize
' * may want to call them, so that the few utility functions which
' * need MAPI allocators (and do not ask for them explicitly)
' * will work.
' */

'/* All flags are reserved for ScInitMapiUtil. */

DECLARE FUNCTION ScInitMapiUtil IMPORT "MAPI32.DLL" ALIAS "ScInitMapiUtil@4" ( _
   BYVAL ulFlags AS DWORD _                             ' __in ULONG ulFlags
 ) AS LONG                                              ' SCODE

DECLARE SUB DeinitMapiUtil IMPORT "MAPI32.DLL" ALIAS "DeinitMapiUtil@0" ()


'/*
' *   Entry point names.
' *
' *   These are for new entry points defined since MAPI first shipped
' *   in Windows 95. Using these names in a GetProcAddress call makes
' *   it easier to write code which uses them optionally.
' */

'#if defined (WIN16)
'#define szHrDispatchNotifications "HrDispatchNotifications"
'#elif defined (_WIN32) && defined (_X86_)
'#define szHrDispatchNotifications "_HrDispatchNotifications@4"
'#elif defined (_ALPHA_) || defined (_MIPS_) || defined (_PPC_) || defined(_IA64_)
'#define szHrDispatchNotifications "HrDispatchNotifications"
'#endif

$szHrDispatchNotifications = "HrDispatchNotifications@4"

'typedef HRESULT (STDAPICALLTYPE DISPATCHNOTIFICATIONS)(ULONG ulFlags);
'typedef DISPATCHNOTIFICATIONS * LPDISPATCHNOTIFICATIONS;

'#if defined (WIN16)
'#define szScCreateConversationIndex "ScCreateConversationIndex"
'#elif defined (_WIN32) && defined (_X86_)
'#define szScCreateConversationIndex "_ScCreateConversationIndex@16"
'#elif defined (_ALPHA_) || defined (_MIPS_) || defined (_PPC_) || defined(_IA64_)
'#define szScCreateConversationIndex "ScCreateConversationIndex"
'#endif

$szScCreateConversationIndex = "ScCreateConversationIndex@16"

'typedef SCODE (STDAPICALLTYPE CREATECONVERSATIONINDEX)(ULONG cbParent,
'   LPBYTE lpbParent, ULONG *lpcbConvIndex, LPBYTE *lppbConvIndex);
'typedef CREATECONVERSATIONINDEX *LPCREATECONVERSATIONINDEX;
