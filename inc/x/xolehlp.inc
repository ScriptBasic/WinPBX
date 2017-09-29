' ########################################################################################
' Microsoft Windows
' File: xolehlp.inc
' Contents: DTC helper APIs used by RM's and application clients to obtain the
' transaction manager.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%XOLEHLP_INC = 1

'/*----------------------------------------
'// Constants
'//--------------------------------------*/
%OLE_TM_CONFIG_VERSION_1     = 1???
%OLE_TM_CONFIG_VERSION_2     = 2???

' enum APPLICATIONTYPE
%LOCAL_APPLICATIONTYPE           = 0
%CLUSTERRESOURCE_APPLICATIONTYPE = 1

%OLE_TM_FLAG_NONE            = &H00000000???
%OLE_TM_FLAG_NODEMANDSTART   = &H00000001???

'// If this flag is set, the application specifies that it does not wish
'// to take advantage of any features that need agile recovery
'// support.
'// As a consequence,  the application will be restricted to
'// using the default transaction manager on a cluster.
%OLE_TM_FLAG_NOAGILERECOVERY = &H00000002???

'// The following are flags used specifically for MSDTC.
%OLE_TM_FLAG_QUERY_SERVICE_LOCKSTATUS = &H80000000???
%OLE_TM_FLAG_INTERNAL_TO_TM  =          &H40000000???

'/*----------------------------------------
'//  Structure definitions
'//--------------------------------------*/
' // Size = 8 bytes
TYPE OLE_TM_CONFIG_PARAMS_V1 DWORD
   dwVersion          AS DWORD   ' DWORD
   dwcConcurrencyHint AS DWORD   ' DWORD
END TYPE

' // Size = 28 bytes
TYPE OLE_TM_CONFIG_PARAMS_V2 DWORD
   dwVersion          AS DWORD   ' DWORD
   dwcConcurrencyHint AS DWORD   ' DWORD
   applicationType    AS LONG    ' APPLICATIONTYPE
   clusterResourceId  AS GUID    ' GUID
END TYPE

'/*----------------------------------------
'//  Function Prototypes
'//--------------------------------------*/

'/*----------------------------------------
'//This API should be used to obtain an IUnknown or a ITransactionDispenser
'//interface from the Microsoft Distributed Transaction Coordinator's proxy.
'//Typically, a NULL is passed for the host name and the TM Name. In which
'//case the MS DTC on the same host is contacted and the interface provided
'//for it.
'//--------------------------------------*/

DECLARE FUNCTION DtcGetTransactionManager CDECL IMPORT "xolehlp.dll" ALIAS "DtcGetTransactionManager" ( _
   BYREF i_pszHost AS ASCIIZ _                          ' __in LPSTR i_pszHost
 , BYREF i_pszTmName AS ASCIIZ _                        ' __in LPSTR i_pszTmName
 , BYREF i_riid AS GUID _                               ' __in REFIID i_riid
 , BYVAL i_dwReserved1 AS DWORD _                       ' __in DWORD i_dwReserved1
 , BYVAL i_wcbReserved2 AS WORD _                       ' __in WORD i_wcbReserved2
 , BYVAL i_pvReserved2 AS DWORD _                       ' __in_bcount(i_wcbReserved2) void * i_pvReserved2
 , BYREF o_ppvObject AS IUnknown _                      ' __out void** o_ppvObject
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DtcGetTransactionManagerC CDECL IMPORT "xolehlp.dll" ALIAS "DtcGetTransactionManagerC" ( _
   BYREF i_pszHost AS ASCIIZ _                          ' __in LPSTR i_pszHost
 , BYREF i_pszTmName AS ASCIIZ _                        ' __in LPSTR i_pszTmName
 , BYREF i_riid AS GUID _                               ' __in REFIID i_riid
 , BYVAL i_dwReserved1 AS DWORD _                       ' __in DWORD i_dwReserved1
 , BYVAL i_wcbReserved2 AS WORD _                       ' __in WORD i_wcbReserved2
 , BYVAL i_pvReserved2 AS DWORD _                       ' __in_bcount(i_wcbReserved2) void * i_pvReserved2
 , BYREF o_ppvObject AS IUnknown _                      ' __out void** o_ppvObject
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DtcGetTransactionManagerExA CDECL IMPORT "xolehlp.dll" ALIAS "DtcGetTransactionManagerExA" ( _
   BYREF i_pszHost AS ASCIIZ _                          ' __in LPSTR i_pszHost
 , BYREF i_pszTmName AS ASCIIZ _                        ' __in LPSTR i_pszTmName
 , BYREF i_riid AS GUID _                               ' __in REFIID i_riid
 , BYVAL i_grfOptions AS DWORD _                        ' __in DWORD i_grfOptions
 , BYVAL i_pvConfigParams AS DWORD _                    ' __in void * i_pvConfigParams
 , BYREF o_ppvObject AS IUnknown _                      ' __out void** o_ppvObject
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DtcGetTransactionManagerExW CDECL IMPORT "xolehlp.dll" ALIAS "DtcGetTransactionManagerExW" ( _
   BYREF i_pwszHost AS WSTRINGZ _                       ' __in LPWSTR i_pwszHost
 , BYREF i_pwszTmName AS WSTRINGZ _                     ' __in LPWSTR i_pwszTmName
 , BYREF i_riid AS GUID _                               ' __in REFIID i_riid
 , BYVAL i_grfOptions AS DWORD _                        ' __in DWORD i_grfOptions
 , BYVAL i_pvConfigParams AS DWORD _                    ' __in void * i_pvConfigParams
 , BYREF o_ppvObject AS IUnknown _                      ' __out void** o_ppvObject
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO DtcGetTransactionManagerEx = DtcGetTransactionManagerExW
#ELSE
   MACRO DtcGetTransactionManagerEx = DtcGetTransactionManagerExA
#ENDIF

'/*----------------------------------------
'// Define a CLSID that can be used to obtain a transaction manager instance via CoCreateInstance;
'// this is an alternate to using DtcGetTransactionManager.
'//
'// CLSID_MSDtcTransactionManager = {5B18AB61-091D-11D1-97DF-00C04FB9618A}
'//--------------------------------------*/
$CLSID_MSDtcTransactionManager = GUID$("{5B18AB61-091D-11D1-97DF-00C04FB9618A}")

'/*----------------------------------------
'// Define a CLSID that can be used with CoCreateInstance to instantiate a vanilla transaction
'// object with the local transaction manager. It's equivalent to doing
'//
'//  pTransactionDispenser->BeginTransaction(NULL, ISOLATIONLEVEL_UNSPECIFIED, ISOFLAG_RETAIN_DONTCARE, NULL, &ptx);
'//
'// CLSID_MSDtcTransaction = {39F8D76B-0928-11d1-97DF-00C04FB9618A}
'//--------------------------------------*/
$CLSID_MSDtcTransaction = GUID$("{39F8D76B-0928-11d1-97DF-00C04FB9618A}")
