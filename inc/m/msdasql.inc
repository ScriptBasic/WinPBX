' ########################################################################################
' Microsoft Windows
' File: msdasql.inc
' Contents: Provider Specific definitions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MSDASQL_INC = 1

#INCLUDE ONCE "oledb.inc"

'// Provider Class Id
'#ifdef DBINITCONSTANTS
$IID_ISQLRequestDiagFields        = GUID$("{228972F0-B5FF-11D0-8A80-00C04FD611CD}")
$IID_ISQLGetDiagField             = GUID$("{228972F1-B5FF-11D0-8A80-00C04FD611CD}")
$IID_IRowsetChangeExtInfo         = GUID$("{0C733A8F-2A1C-11CE-ADE5-00aa0044773d}")
$CLSID_MSDASQL                    = GUID$("{C8B522CB-5CF3-11CE-ADE5-00AA0044773D}")
$CLSID_MSDASQL_ENUMERATOR         = GUID$("{C8B522CD-5CF3-11CE-ADE5-00AA0044773D}")
'#endif // DBINITCONSTANTS

'//----------------------------------------------------------------------------
'// MSDASQL specific properties
'#ifdef DBINITCONSTANTS
$DBPROPSET_PROVIDERDATASOURCEINFO = GUID$("{497C60E0-7123-11CF-B171-00AA0057599E}")
$DBPROPSET_PROVIDERROWSET         = GUID$("{497C60E1-7123-11CF-B171-00AA0057599E}")
$DBPROPSET_PROVIDERDBINIT         = GUID$("{497C60E2-7123-11CF-B171-00AA0057599E}")
$DBPROPSET_PROVIDERSTMTATTR       = GUID$("{497C60E3-7123-11CF-B171-00AA0057599E}")
$DBPROPSET_PROVIDERCONNATTR       = GUID$("{497C60E4-7123-11CF-B171-00AA0057599E}")
'#endif // DBINITCONSTANTS

'// PropIds under DBPROPSET_PROVIDERROWSET
%KAGPROP_QUERYBASEDUPDATES      = 2
%KAGPROP_MARSHALLABLE           = 3
%KAGPROP_POSITIONONNEWROW       = 4
%KAGPROP_IRowsetChangeExtInfo   = 5
%KAGPROP_CURSOR                 = 6
%KAGPROP_CONCURRENCY            = 7
%KAGPROP_BLOBSONFOCURSOR        = 8
%KAGPROP_INCLUDENONEXACT        = 9
%KAGPROP_FORCESSFIREHOSEMODE    = 10
%KAGPROP_FORCENOPARAMETERREBIND = 11
%KAGPROP_FORCENOPREPARE         = 12
%KAGPROP_FORCENOREEXECUTE       = 13

'// PropIds under DPBROPSET_PROVIDERDATASOURCEINFO
%KAGPROP_ACCESSIBLEPROCEDURES   = 2
%KAGPROP_ACCESSIBLETABLES       = 3
%KAGPROP_ODBCSQLOPTIEF          = 4
%KAGPROP_OJCAPABILITY           = 5
%KAGPROP_PROCEDURES             = 6
%KAGPROP_DRIVERNAME             = 7
%KAGPROP_DRIVERVER              = 8
%KAGPROP_DRIVERODBCVER          = 9
%KAGPROP_LIKEESCAPECLAUSE       = 10
%KAGPROP_SPECIALCHARACTERS      = 11
%KAGPROP_MAXCOLUMNSINGROUPBY    = 12
%KAGPROP_MAXCOLUMNSININDEX      = 13
%KAGPROP_MAXCOLUMNSINORDERBY    = 14
%KAGPROP_MAXCOLUMNSINSELECT     = 15
%KAGPROP_MAXCOLUMNSINTABLE      = 16
%KAGPROP_NUMERICFUNCTIONS       = 17
%KAGPROP_ODBCSQLCONFORMANCE     = 18
%KAGPROP_OUTERJOINS             = 19
%KAGPROP_STRINGFUNCTIONS        = 20
%KAGPROP_SYSTEMFUNCTIONS        = 21
%KAGPROP_TIMEDATEFUNCTIONS      = 22
%KAGPROP_FILEUSAGE              = 23
%KAGPROP_ACTIVESTATEMENTS       = 24

'// PropIds under DBPROPSET_PROVIDERDBINIT
%KAGPROP_AUTH_TRUSTEDCONNECTION = 2
%KAGPROP_AUTH_SERVERINTEGRATED  = 3


'// Bitmask values for KAGPROP_CONCURRENCY
%KAGPROPVAL_CONCUR_ROWVER       = &H00000001
%KAGPROPVAL_CONCUR_VALUES       = &H00000002
%KAGPROPVAL_CONCUR_LOCK         = &H00000004
%KAGPROPVAL_CONCUR_READ_ONLY    = &H00000008

' ########################################################################################
' IRowsetChangeExtInfo interface
' IID = 0C733A8F-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowsetChangeExtInfo_INTERFACE_DEFINED)
%IRowsetChangeExtInfo_INTERFACE_DEFINED = 1

$IID_IRowsetChangeExtInfo = GUID$("{0C733A8F-2A1C-11CE-ADE5-00AA0044773D}")

INTERFACE IRowsetChangeExtInfo $IID_IRowsetChangeExtInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetOriginalRow ( _                            ' VTable offset = 12
     BYVAL hReserved AS DWORD _                         ' __in HCHAPTER hReserved
   , BYVAL hRow AS DWORD _                              ' __in HROW hRow
   , BYREF phRowOriginal AS DWORD _                     ' __out HROW *phRowOriginal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPendingColumns ( _                         ' VTable offset = 16
     BYVAL hReserved AS DWORD _                         ' __in HCHAPTER hReserved
   , BYVAL hRow AS DWORD _                              ' __in HROW hRow
   , BYVAL cColumnOrdinals AS DWORD _                   ' __in ULONG cColumnOrdinals
   , BYREF rgiOrdinals AS DWORD _                       ' __in const ULONG rgiOrdinals[  ]
   , BYREF rgColumnStatus AS DWORD _                    ' __out DBPENDINGSTATUS rgColumnStatus[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetChangeExtInfo_INTERFACE_DEFINED__ */


' KAGREQDIAGFLAGSENUM enum
%KAGREQDIAGFLAGS_HEADER = &H1
%KAGREQDIAGFLAGS_RECORD = &H2

'// the structure passed in IRequestDiagFields::RequestDiagFields
' // Size = 8 bytes
TYPE KAGREQDIAG WORD
   ulDiagFlags AS DWORD     ' ULONG
   vt          AS WORD      ' VARTYPE
   sDiagField  AS INTEGER   ' SHORT
END TYPE

'// the structure passed in IGetDiagField::GetDiagField
' // Size = 32 bytes
TYPE KAGGETDIAG QWORD
   ulSize     AS DWORD        ' ULONG
   vDiagInfo  AS tagVARIANT   ' VARIANTARG
   sDiagField AS INTEGER      ' SHORT
END TYPE


' ########################################################################################
' ISQLRequestDiagFields interface
' IID = 228972F0-B5FF-11D0-8A80-00C04FD611CD
' Inherited interface = IRowsetChange
' ########################################################################################

#IF NOT %DEF(%ISQLRequestDiagFields_INTERFACE_DEFINED)
%ISQLRequestDiagFields_INTERFACE_DEFINED = 1

$IID_ISQLRequestDiagFields = GUID$("{228972F0-B5FF-11D0-8A80-00C04FD611CD}")

INTERFACE ISQLRequestDiagFields $IID_ISQLRequestDiagFields

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RequestDiagFields ( _                         ' VTable offset = 12
     BYVAL cDiagFields AS DWORD _                       ' __in ULONG cDiagFields
   , BYREF rgDiagFields AS KAGREQDIAG _                 ' __in KAGREQDIAG rgDiagFields[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISQLRequestDiagFields_INTERFACE_DEFINED__ */


' ########################################################################################
' ISQLGetDiagField interface
' IID = 228972F1-B5FF-11D0-8A80-00C04FD611CD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISQLGetDiagField_INTERFACE_DEFINED)
%ISQLGetDiagField_INTERFACE_DEFINED = 1

$IID_ISQLGetDiagField = GUID$("{228972F1-B5FF-11D0-8A80-00C04FD611CD}")

INTERFACE ISQLGetDiagField $IID_ISQLGetDiagField

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDiagField ( _                              ' VTable offset = 12
     BYREF pDiagInfo AS KAGREQDIAG _                    ' __inout KAGGETDIAG *pDiagInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISQLGetDiagField_INTERFACE_DEFINED__ */
