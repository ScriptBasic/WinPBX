' ########################################################################################
' Microsoft Windows
' File: CertView.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CERTVIEW_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "wtypes.inc"
#INCLUDE ONCE "oaidl.inc"

%CV_OUT_BASE64HEADER           = 0
%CV_OUT_BASE64                 = &H1
%CV_OUT_BINARY                 = &H2
%CV_OUT_BASE64REQUESTHEADER    = &H3
%CV_OUT_HEX                    = &H4
%CV_OUT_HEXASCII               = &H5
%CV_OUT_BASE64X509CRLHEADER    = &H9
%CV_OUT_HEXADDR                = &Ha
%CV_OUT_HEXASCIIADDR           = &Hb
%CV_OUT_ENCODEMASK             = &Hff

%CVR_SEEK_NONE                 = 0
%CVR_SEEK_EQ                   = &H1
%CVR_SEEK_LT                   = &H2
%CVR_SEEK_LE                   = &H4
%CVR_SEEK_GE                   = &H8
%CVR_SEEK_GT                   = &H10
%CVR_SEEK_MASK                 = &Hff
%CVR_SEEK_NODELTA              = &H1000
%CVR_SORT_NONE                 = 0
%CVR_SORT_ASCEND               = &H1
%CVR_SORT_DESCEND              = &H2

%CV_COLUMN_QUEUE_DEFAULT       = -1
%CV_COLUMN_LOG_DEFAULT         = -2
%CV_COLUMN_LOG_FAILED_DEFAULT  = -3
%CV_COLUMN_EXTENSION_DEFAULT   = -4
%CV_COLUMN_ATTRIBUTE_DEFAULT   = -5
%CV_COLUMN_CRL_DEFAULT         = -6
%CV_COLUMN_LOG_REVOKED_DEFAULT = -7

%CVRC_COLUMN_SCHEMA            = 0
%CVRC_COLUMN_RESULT            = &H1
%CVRC_COLUMN_VALUE             = &H2
%CVRC_COLUMN_MASK              = &Hfff
%CVRC_TABLE_REQCERT            = 0
%CVRC_TABLE_EXTENSIONS         = &H3000
%CVRC_TABLE_ATTRIBUTES         = &H4000
%CVRC_TABLE_CRL                = &H5000
%CVRC_TABLE_MASK               = &Hf000
%CVRC_TABLE_SHIFT              = 12

$CLSID_CCertView = GUID$("{A12D0F7A-1E84-11D1-9BD6-00C04FB683FA}")

' ########################################################################################
' Interface name = IEnumCERTVIEWCOLUMN
' IID = {9C735BE2-57A5-11D1-9BDB-00C04FB683FA}
' IEnumCERTVIEWCOLUMN Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEnumCERTVIEWCOLUMN_INTERFACE_DEFINED)
    %IEnumCERTVIEWCOLUMN_INTERFACE_DEFINED = 1

$IID_IEnumCERTVIEWCOLUMN = GUID$("{9C735BE2-57A5-11D1-9BDB-00C04FB683FA}")

INTERFACE IEnumCERTVIEWCOLUMN $IID_IEnumCERTVIEWCOLUMN

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Next <1610743808> ( _                         ' VTable offset = 28
   ) AS LONG                                            ' __retval_out LONG *pIndex
   ' =====================================================================================
   METHOD GetName <1610743809> ( _                      ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pstrOut
   ' =====================================================================================
   METHOD GetDisplayName <1610743810> ( _               ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pstrOut
   ' =====================================================================================
   METHOD GetType <1610743811> ( _                      ' VTable offset = 40
   ) AS LONG                                            ' __retval_out LONG *pType
   ' =====================================================================================
   METHOD IsIndexed <1610743812> ( _                    ' VTable offset = 44
   ) AS LONG                                            ' __retval_out LONG *pIndexed
   ' =====================================================================================
   METHOD GetMaxLength <1610743813> ( _                 ' VTable offset = 48
   ) AS LONG                                            ' __retval_out LONG *pMaxLength
   ' =====================================================================================
   METHOD GetValue <1610743814> ( _                     ' VTable offset = 52
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarValue
   ' =====================================================================================
   METHOD Skip <1610743815> ( _                         ' VTable offset = 56
     BYVAL celt AS LONG _                               ' __in LONG celt
   )                                                    ' void
   ' =====================================================================================
   METHOD Reset <1610743816> ( _                        ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <1610743817> ( _                        ' VTable offset = 64
   ) AS IEnumCERTVIEWCOLUMN                             '__retval_out IEnumCERTVIEWCOLUMN **ppenum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumCERTVIEWCOLUMN_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumCERTVIEWATTRIBUTE
' IID = {E77DB656-7653-11D1-9BDE-00C04FB683FA}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEnumCERTVIEWATTRIBUTE_INTERFACE_DEFINED)
    %IEnumCERTVIEWATTRIBUTE_INTERFACE_DEFINED = 1

$IID_IEnumCERTVIEWATTRIBUTE = GUID$("{E77DB656-7653-11D1-9BDE-00C04FB683FA}")

INTERFACE IEnumCERTVIEWATTRIBUTE $IID_IEnumCERTVIEWATTRIBUTE

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Next <1610743808> ( _                         ' VTable offset = 28
   ) AS LONG                                            ' __retval_out LONG *pIndex
   ' =====================================================================================
   METHOD GetName <1610743809> ( _                      ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pstrOut
   ' =====================================================================================
   METHOD GetValue <1610743810> ( _                     ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pstrOut
   ' =====================================================================================
   METHOD Skip <1610743811> ( _                         ' VTable offset = 40
     BYVAL celt AS LONG _                               ' __in LONG celt
   )                                                    ' void
   ' =====================================================================================
   METHOD Reset <1610743812> ( _                        ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <1610743813> ( _                        ' VTable offset = 48
   ) AS IEnumCERTVIEWATTRIBUTE                          ' __retval_out IEnumCERTVIEWATTRIBUTE **ppenum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumCERTVIEWATTRIBUTE_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumCERTVIEWEXTENSION
' IID = {E7DD1466-7653-11D1-9BDE-00C04FB683FA}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEnumCERTVIEWEXTENSION_INTERFACE_DEFINED)
    %IEnumCERTVIEWEXTENSION_INTERFACE_DEFINED = 1

$IID_IEnumCERTVIEWEXTENSION = GUID$("{E7DD1466-7653-11D1-9BDE-00C04FB683FA}")

INTERFACE IEnumCERTVIEWEXTENSION $IID_IEnumCERTVIEWEXTENSION

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Next <1610743808> ( _                         ' VTable offset = 28
   ) AS LONG                                            ' __retval_out LONG *pIndex
   ' =====================================================================================
   METHOD GetName <1610743809> ( _                      ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pstrOut
   ' =====================================================================================
   METHOD GetFlags <1610743810> ( _                     ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *pFlags
   ' =====================================================================================
   METHOD GetValue <1610743811> ( _                     ' VTable offset = 40
     BYVAL Type AS LONG _                               ' __in LONG Type
   , BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarValue
   ' =====================================================================================
   METHOD Skip <1610743812> ( _                         ' VTable offset = 44
     BYVAL celt AS LONG _                               ' __in LONG celt
   )                                                    ' void
   ' =====================================================================================
   METHOD Reset <1610743813> ( _                        ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <1610743814> ( _                        ' VTable offset = 52
   ) AS IEnumCERTVIEWEXTENSION                          ' __retval_out IEnumCERTVIEWEXTENSION **ppenum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumCERTVIEWEXTENSION_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumCERTVIEWROW
' IID = {D1157F4C-5AF2-11D1-9BDC-00C04FB683FA}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEnumCERTVIEWROW_INTERFACE_DEFINED)
    %IEnumCERTVIEWROW_INTERFACE_DEFINED = 1

$IID_IEnumCERTVIEWROW = GUID$("{D1157F4C-5AF2-11D1-9BDC-00C04FB683FA}")

INTERFACE IEnumCERTVIEWROW $IID_IEnumCERTVIEWROW

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Next <1610743808> ( _                         ' VTable offset = 28
   ) AS LONG                                            ' __retval_out LONG *pIndex
   ' =====================================================================================
   METHOD EnumCertViewColumn <1610743809> ( _           ' VTable offset = 32
   ) AS IEnumCERTVIEWCOLUMN                             ' __retval_out IEnumCERTVIEWCOLUMN **ppenum
   ' =====================================================================================
   METHOD EnumCertViewAttribute <1610743810> ( _        ' VTable offset = 36
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS IEnumCERTVIEWATTRIBUTE                          ' __retval_out IEnumCERTVIEWATTRIBUTE **ppenum
   ' =====================================================================================
   METHOD EnumCertViewExtension <1610743811> ( _        ' VTable offset = 40
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS IEnumCERTVIEWEXTENSION                          ' __retval_out IEnumCERTVIEWEXTENSION **ppenum
   ' =====================================================================================
   METHOD Skip <1610743812> ( _                         ' VTable offset = 44
     BYVAL celt AS LONG _                               ' __in LONG celt
   )                                                    ' void
   ' =====================================================================================
   METHOD Reset <1610743813> ( _                        ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <1610743814> ( _                        ' VTable offset = 52
   ) AS IEnumCERTVIEWROW                                ' __retval_out IEnumCERTVIEWROW **ppenum
   ' =====================================================================================
   METHOD GetMaxIndex <1610743815> ( _                  ' VTable offset = 56
   ) AS LONG                                            ' __retval_out LONG *pIndex
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumCERTVIEWROW_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertView
' IID = {C3FAC344-1E84-11D1-9BD6-00C04FB683FA}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertView_INTERFACE_DEFINED)
    %ICertView_INTERFACE_DEFINED = 1

$IID_ICertView = GUID$("{C3FAC344-1E84-11D1-9BD6-00C04FB683FA}")

INTERFACE ICertView $IID_ICertView

   INHERIT IDispatch

   ' =====================================================================================
   METHOD OpenConnection <1610743808> ( _               ' VTable offset = 28
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumCertViewColumn <1610743809> ( _           ' VTable offset = 32
     BYVAL fResultColumn AS LONG _                      ' __in LONG fResultColumn
   ) AS IEnumCERTVIEWCOLUMN                             ' __retval_out IEnumCERTVIEWCOLUMN **ppenum
   ' =====================================================================================
   METHOD GetColumnCount <1610743810> ( _               ' VTable offset = 36
     BYVAL fResultColumn AS LONG _                      ' __in LONG fResultColumn
   ) AS LONG                                            ' __retval_out LONG *pcColumn
   ' =====================================================================================
   METHOD GetColumnIndex <1610743811> ( _               ' VTable offset = 40
     BYVAL fResultColumn AS LONG _                      ' __in LONG fResultColumn
   , BYVAL strColumnName AS WSTRING _                   ' __in const BSTR strColumnName
   ) AS LONG                                            ' __retval_out LONG *pColumnIndex
   ' =====================================================================================
   METHOD SetResultColumnCount <1610743812> ( _         ' VTable offset = 44
     BYVAL cResultColumn AS LONG _                      ' __in LONG cResultColumn
   )                                                    ' void
   ' =====================================================================================
   METHOD SetResultColumn <1610743813> ( _              ' VTable offset = 48
     BYVAL ColumnIndex AS LONG _                        ' __in LONG ColumnIndex
   )                                                    ' void
   ' =====================================================================================
   METHOD SetRestriction <1610743814> ( _               ' VTable offset = 52
     BYVAL ColumnIndex AS LONG _                        ' __in LONG ColumnIndex
   , BYVAL SeekOperator AS LONG _                       ' __in LONG SeekOperator
   , BYVAL SortOrder AS LONG _                          ' __in LONG SortOrder
   , BYREF pvarValue AS VARIANT _                       ' __in const VARIANT *pvarValue
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenView <1610743815> ( _                     ' VTable offset = 56
   ) AS IEnumCERTVIEWROW                                ' __retval_out IEnumCERTVIEWROW **ppenum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertView_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICertView2
' IID = {D594B282-8851-4B61-9C66-3EDADF848863}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ICertView
' ########################################################################################

#IF NOT %DEF(%ICertView2_INTERFACE_DEFINED)
    %ICertView2_INTERFACE_DEFINED = 1

$IID_ICertView2 = GUID$("{D594B282-8851-4B61-9C66-3EDADF848863}")

INTERFACE ICertView2 $IID_ICertView2

   INHERIT IDispatch

   ' =====================================================================================
   ' ICertView Methods
   ' =====================================================================================
   METHOD OpenConnection <1610743808> ( _               ' VTable offset = 28
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumCertViewColumn <1610743809> ( _           ' VTable offset = 32
     BYVAL fResultColumn AS LONG _                      ' __in LONG fResultColumn
   ) AS IEnumCERTVIEWCOLUMN                             ' __retval_out IEnumCERTVIEWCOLUMN **ppenum
   ' =====================================================================================
   METHOD GetColumnCount <1610743810> ( _               ' VTable offset = 36
     BYVAL fResultColumn AS LONG _                      ' __in LONG fResultColumn
   ) AS LONG                                            ' __retval_out LONG *pcColumn
   ' =====================================================================================
   METHOD GetColumnIndex <1610743811> ( _               ' VTable offset = 40
     BYVAL fResultColumn AS LONG _                      ' __in LONG fResultColumn
   , BYVAL strColumnName AS WSTRING _                   ' __in const BSTR strColumnName
   ) AS LONG                                            ' __retval_out LONG *pColumnIndex
   ' =====================================================================================
   METHOD SetResultColumnCount <1610743812> ( _         ' VTable offset = 44
     BYVAL cResultColumn AS LONG _                      ' __in LONG cResultColumn
   )                                                    ' void
   ' =====================================================================================
   METHOD SetResultColumn <1610743813> ( _              ' VTable offset = 48
     BYVAL ColumnIndex AS LONG _                        ' __in LONG ColumnIndex
   )                                                    ' void
   ' =====================================================================================
   METHOD SetRestriction <1610743814> ( _               ' VTable offset = 52
     BYVAL ColumnIndex AS LONG _                        ' __in LONG ColumnIndex
   , BYVAL SeekOperator AS LONG _                       ' __in LONG SeekOperator
   , BYVAL SortOrder AS LONG _                          ' __in LONG SortOrder
   , BYREF pvarValue AS VARIANT _                       ' __in const VARIANT *pvarValue
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenView <1610743815> ( _                     ' VTable offset = 56
   ) AS IEnumCERTVIEWROW                                ' __retval_out IEnumCERTVIEWROW **ppenum
   ' =====================================================================================

   ' =====================================================================================
   ' ICertView2 Methods
   ' =====================================================================================
   METHOD SetTable <1610809344> ( _                     ' VTable offset = 60
     BYVAL Table AS LONG _                              ' __in LONG Table
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertView2_INTERFACE_DEFINED__ */
