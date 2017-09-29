' ########################################################################################
' Microsoft Windows
' File: gchost.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%GCHOST_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"

' enum COR_GC_STAT_TYPES
%COR_GC_COUNTS      = &H1
%COR_GC_MEMORYUSAGE = &H2

' enum COR_GC_THREAD_STATS_TYPES
%COR_GC_THREAD_HAS_PROMOTED_BYTES = &H1

' // Size = 52 bytes
TYPE COR_GC_STATS DWORD
   Flags                     AS DWORD   ' ULONG
   ExplicitGCCount           AS DWORD   ' SIZE_T
   GenCollectionsTaken(2)    AS DWORD   ' SIZE_T[3]
   CommittedKBytes           AS DWORD   ' SIZE_T
   ReservedKBytes            AS DWORD   ' SIZE_T
   Gen0HeapSizeKBytes        AS DWORD   ' SIZE_T
   Gen1HeapSizeKBytes        AS DWORD   ' SIZE_T
   Gen2HeapSizeKBytes        AS DWORD   ' SIZE_T
   LargeObjectHeapSizeKBytes AS DWORD   ' SIZE_T
   KBytesPromotedFromGen0    AS DWORD   ' SIZE_T
   KBytesPromotedFromGen1    AS DWORD   ' SIZE_T
END TYPE

' // Size = 16 bytes
TYPE COR_GC_THREAD_STATS QWORD
   PerThreadAllocation AS QUAD    ' ULONGLONG
   Flags               AS DWORD   ' ULONG
END TYPE


' ########################################################################################
' Interface name = IGCHost
' IID = {FAC34F6E-0DCD-47B5-8021-531BC5ECCA63}
' Inherited interface = IUnknown
' Provides methods for obtaining information about the garbage collection system and for
' controlling some aspects of garbage collection.
' NOTE: This interface is for expert usage only. It can affect the performance of an
' application if used improperly
' ########################################################################################

#IF NOT %DEF(%IGCHost_INTERFACE_DEFINED)
    %IGCHost_INTERFACE_DEFINED = 1

$IID_IGCHost = GUID$("{FAC34F6E-0DCD-47B5-8021-531BC5ECCA63}")

INTERFACE IGCHost $IID_IGCHost

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetGCStartupLimits ( _                        ' VTable offset = 12
     BYVAL SegmentSize AS DWORD _                       ' __in DWORD SegmentSize
   , BYVAL MaxGen0Size AS DWORD _                       ' __in DWORD MaxGen0Size
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Collect ( _                                   ' VTable offset = 16
     BYVAL Generation AS LONG _                         ' __in LONG Generation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStats ( _                                  ' VTable offset = 20
     BYREF pStats AS COR_GC_STATS _                     ' __inout COR_GC_STATS *pStats
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetThreadStats ( _                            ' VTable offset = 24
     BYREF pFiberCookie AS DWORD _                      ' __in DWORD *pFiberCookie
   , BYREF pStats AS COR_GC_THREAD_STATS _              ' __inout COR_GC_THREAD_STATS *pStats
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVirtualMemLimit ( _                        ' VTable offset = 28
     BYVAL sztMaxVirtualMemMB AS DWORD _                ' __in SIZE_T sztMaxVirtualMemMB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGCHost_INTERFACE_DEFINED__ */
