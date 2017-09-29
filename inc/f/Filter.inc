' ########################################################################################
' Microsoft Windows
' File: Filter.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%FILTER_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "propidl.inc"

'//+-------------------------------------------------------------------------
'//
'//  Microsoft Windows
'//  Copyright (C) Microsoft Corporation, 1993-1998.
'//
'//--------------------------------------------------------------------------

#IF NOT %DEF(%TAGFULLPROPSPEC_DEFINED)
%TAGFULLPROPSPEC_DEFINED = 1
' // Size = 24 bytes
TYPE FULLPROPSPEC DWORD
   guidPropSet AS GUID       ' GUID
   psProperty  AS PROPSPEC   ' PROPSPEC
END TYPE
#ENDIF   ' TAGFULLPROPSPEC_DEFINED

' ########################################################################################
' IFilter interface
' IID = 89BCB740-6119-101A-BCB7-00DD010655AF
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFilter_INTERFACE_DEFINED)
    %IFilter_INTERFACE_DEFINED = 1

#IF NOT %DEF(%IFILTER_INIT_DEFINED)
%IFILTER_INIT_DEFINED = 1
' enum IFILTER_INIT
%IFILTER_INIT_CANON_PARAGRAPHS        = 1
%IFILTER_INIT_HARD_LINE_BREAKS        = 2
%IFILTER_INIT_CANON_HYPHENS           = 4
%IFILTER_INIT_CANON_SPACES            = 8
%IFILTER_INIT_APPLY_INDEX_ATTRIBUTES  = 16
%IFILTER_INIT_APPLY_OTHER_ATTRIBUTES  = 32
%IFILTER_INIT_APPLY_CRAWL_ATTRIBUTES  = 256
%IFILTER_INIT_INDEXING_ONLY           = 64
%IFILTER_INIT_SEARCH_LINKS            = 128
%IFILTER_INIT_FILTER_OWNED_VALUE_OK   = 512
%IFILTER_INIT_FILTER_AGGRESSIVE_BREAK = 1024
%IFILTER_INIT_DISABLE_EMBEDDED        = 2048
%IFILTER_INIT_EMIT_FORMATTING         = 4096
#ENDIF

#IF NOT %DEF(%IFILTER_FLAGS_DEFINED)
%IFILTER_FLAGS_DEFINED = 1
' enum IFILTER_FLAGS
%IFILTER_FLAGS_OLE_PROPERTIES = 1
#ENDIF

#IF NOT %DEF(%CHUNKSTATE_DEFINED)
%CHUNKSTATE_DEFINED = 1
' enum CHUNKSTATE
%CHUNK_TEXT               = &H1???
%CHUNK_VALUE              = &H2???
%CHUNK_FILTER_OWNED_VALUE = &H4???
#ENDIF

#IF NOT %DEF(%CHUNK_BREAKTYPE_DEFINED)
%CHUNK_BREAKTYPE_DEFINED = 1
' enum CHUNK_BREAKTYPE
%CHUNK_NO_BREAK = 0
%CHUNK_EOW      = 1
%CHUNK_EOS      = 2
%CHUNK_EOP      = 3
%CHUNK_EOC      = 4
#ENDIF

#IF NOT %DEF(%FILTERREGION_DEFINED)
%FILTERREGION_DEFINED = 1
' // Size = 12 bytes
TYPE FILTERREGION DWORD
   idChunk   AS DWORD   ' ULONG
   cwcStart  AS DWORD   ' ULONG
   cwcExtent AS DWORD   ' ULONG
END TYPE
#ENDIF

#IF NOT %DEF(%STAT_CHUNK_DEFINED)
%STAT_CHUNK_DEFINED = 1
' // Size = 52 bytes
TYPE STAT_CHUNK DWORD
   idChunk        AS DWORD          ' ULONG
   breakType      AS LONG           ' CHUNK_BREAKTYPE
   flags          AS DWORD          ' CHUNKSTATE
   locale         AS DWORD          ' LCID
   attribute      AS FULLPROPSPEC   ' FULLPROPSPEC
   idChunkSource  AS DWORD          ' ULONG
   cwcStartSource AS DWORD          ' ULONG
   cwcLenSource   AS DWORD          ' ULONG
END TYPE
#ENDIF

$IID_IFilter = GUID$("{89BCB740-6119-101A-BCB7-00DD010655AF}")

INTERFACE IFilter $IID_IFilter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Init ( _                                      ' VTable offset = 12
     BYVAL grfFlags AS DWORD _                          ' __in ULONG grfFlags
   , BYVAL cAttributes AS DWORD _                       ' __in ULONG cAttributes
   , BYREF aAttributes AS FULLPROPSPEC _                ' __in const FULLPROPSPEC *aAttributes
   , BYREF pFlags AS DWORD _                            ' __out ULONG *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChunk ( _                                  ' VTable offset = 16
     BYREF pStat AS STAT_CHUNK _                        ' __out STAT_CHUNK *pStat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetText ( _                                   ' VTable offset = 20
     BYREF pcwcBuffer AS DWORD _                        ' __in_out ULONG *pcwcBuffer
   , BYREF awcBuffer AS WSTRINGZ _                      ' __out WCHAR *awcBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 24
     BYREF ppPropValue AS PROPVARIANT _                 ' __out PROPVARIANT **ppPropValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindRegion ( _                                ' VTable offset = 28
     BYREF origPos AS FILTERREGION _                    ' __in FILTERREGION origPos
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppunk AS IUnknown _                          ' __out void **ppunk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFilter_INTERFACE_DEFINED__ */
