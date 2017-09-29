' ########################################################################################
' Microsoft Windows
' File: tlbinf32.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: TLI
' Version: 1.0, Locale ID = 0
' Documentation string: TypeLib Information
' DLL: TLBINF32.DLL
' Help file: tlbinf32.chm
' Library GUID: {8B217740-717D-11CE-AB5B-D41203C10000}
' ########################################################################################

#INCLUDE THIS ONCE
%TLBINF32_INC = 1

#INCLUDE ONCE "oaidl.inc"

' ========================================================================================
' Ordinal 5.
' ========================================================================================
DECLARE FUNCTION NewGUID IMPORT "TlbInf32.dll" ALIAS "NewGUID" ( _
   BYREF retVal AS WSTRING _                            ' __retval_out BSTR* retVal
 ) AS LONG                                              ' HRESULT
' ========================================================================================

' ========================================================================================
' Ordinal 6.
' ========================================================================================
DECLARE FUNCTION GetTypeInfoAttributeStrings IMPORT "TlbInf32.dll" ALIAS "GetTypeInfoAttributeStrings" ( _
   BYVAL AttributeMask AS INTEGER _                     ' __in short AttributeMask
 , BYREF AttributeArray AS DWORD _                      ' __out SAFEARRAY(BSTR) *AttributeArray
 , BYREF retVal AS INTEGER _                            ' __retval_out short* retVal
 ) AS LONG                                              ' HRESULT
' ========================================================================================

' ========================================================================================
' Ordinal 7.
' ========================================================================================
DECLARE FUNCTION GetImplAttributeStrings IMPORT "TlbInf32.dll" ALIAS "GetImplAttributeStrings" ( _
   BYVAL AttributeMask AS INTEGER _                     ' __in short AttributeMask
 , BYREF AttributeArray AS DWORD _                      ' __out SAFEARRAY(BSTR) *AttributeArray
 , BYREF retVal AS INTEGER _                            ' __retval_out short* retVal
 ) AS LONG                                              ' HRESULT
' ========================================================================================

' ========================================================================================
' Ordinal 8.
' ========================================================================================
DECLARE FUNCTION GetLibraryAttributeStrings IMPORT "TlbInf32.dll" ALIAS "GetLibraryAttributeStrings" ( _
   BYVAL AttributeMask AS INTEGER _                     ' __in short AttributeMask
 , BYREF AttributeArray AS DWORD _                      ' __out SAFEARRAY(BSTR) *AttributeArray
 , BYREF retVal AS INTEGER _                            ' __retval_out short* retVal
 ) AS LONG                                              ' HRESULT
' ========================================================================================

' ========================================================================================
' Ordinal 9.
' ========================================================================================
DECLARE FUNCTION GetFunctionAttributeStrings IMPORT "TlbInf32.dll" ALIAS "GetFunctionAttributeStrings" ( _
   BYVAL AttributeMask AS INTEGER _                     ' __in short AttributeMask
 , BYREF AttributeArray AS DWORD _                      ' __out SAFEARRAY(BSTR) *AttributeArray
 , BYREF retVal AS INTEGER _                            ' __retval_out short* retVal
 ) AS LONG                                              ' HRESULT
' ========================================================================================

' ========================================================================================
' Ordinal 10.
' ========================================================================================
DECLARE FUNCTION GetVariableAttributeStrings IMPORT "TlbInf32.dll" ALIAS "GetVariableAttributeStrings" ( _
   BYVAL AttributeMask AS INTEGER _                     ' __in short AttributeMask
 , BYREF AttributeArray AS DWORD _                      ' __out SAFEARRAY(BSTR) *AttributeArray
 , BYREF retVal AS INTEGER _                            ' __retval_out short* retVal
 ) AS LONG                                              ' HRESULT
' ========================================================================================

' ========================================================================================
' Ordinal 11.
' ========================================================================================
DECLARE FUNCTION SwapStringArrays IMPORT "TlbInf32.dll" ALIAS "SwapStringArrays" ( _
   BYREF DestArray AS DWORD _                           ' __in_out SAFEARRAY(BSTR) *DestArray
 , BYREF SrcArray AS DWORD _                            ' __in_out SAFEARRAY(BSTR) *SrcArray
 ) AS LONG                                              ' HRESULT
' ========================================================================================

' ========================================================================================
' Ordinal 11.
' Not exported.
' ========================================================================================
'DECLARE FUNCTION SwapLongArrays IMPORT "TlbInf32.dll" ALIAS "SwapLongArrays" ( _
'   BYREF DestArray AS DWORD _                           ' __in_out SAFEARRAY(long) *DestArray
' , BYREF SrcArray AS DWORD _                            ' __in_out SAFEARRAY(long) *SrcArray
' ) AS LONG                                              ' HRESULT
' ========================================================================================

' ========================================================================================
' Ordinal 12.
' ========================================================================================
DECLARE FUNCTION AddressOfStringElement IMPORT "TlbInf32.dll" ALIAS "AddressOfStringElement" ( _
   BYREF InString AS WSTRING _                          ' __in_out BSTR *InString
 , BYVAL Position AS INTEGER _                          ' __in short Position
 , BYREF retval AS LONG _                               ' __retval_out long* retval
 ) AS LONG                                              ' HRESULT
' ========================================================================================

' ========================================================================================
' Ordinal 13.
' Use PB's LO(WORD)
' ========================================================================================
'DECLARE FUNCTION loword IMPORT "TlbInf32.dll" ALIAS "loword" ( _
'   BYVAL DWORD AS LONG _                                ' __in long DWORD
' ) AS INTEGER                                           ' short
' ========================================================================================

' ========================================================================================
' Ordinal 14.
' Use PB's HI(WORD)
' ========================================================================================
'DECLARE FUNCTION hiword IMPORT "TlbInf32.dll" ALIAS "hiword" ( _
'   BYVAL DWORD AS LONG _                                ' __in long DWORD
' ) AS INTEGER                                           ' short
' ========================================================================================

' ========================================================================================
' Ordinal 15.
' Use PB's MAK(LONG)
' ========================================================================================
'DECLARE FUNCTION makelong IMPORT "TlbInf32.dll" ALIAS "makelong" ( _
'   BYVAL LOWORD AS INTEGER _                            ' __in short LOWORD
' , BYVAL HIWORD AS INTEGER _                            ' __in short HIWORD
' ) AS LONG                                              ' long
' ========================================================================================

' ========================================================================================
' Ordinal 16.
' Use PB's LO(BYTE)
' ========================================================================================
'DECLARE FUNCTION lobyte IMPORT "TlbInf32.dll" ALIAS "lobyte" ( _
'   BYVAL WORD AS INTEGER _                              ' __in short WORD
' ) AS INTEGER                                           ' short
' ========================================================================================

' ========================================================================================
' Ordinal 17.
' Use PB's HI(BYTE)
' ========================================================================================
'DECLARE FUNCTION hibyte IMPORT "TlbInf32.dll" ALIAS "hibyte" ( _
'   BYVAL WORD AS INTEGER _                              ' __in short WORD
' ) AS INTEGER                                           ' short
' ========================================================================================

' ========================================================================================
' Ordinal 18.
' Use PB's MAK(WORD)
' ========================================================================================
'DECLARE FUNCTION makeword IMPORT "TlbInf32.dll" ALIAS "makeword" ( _
'   BYVAL LOBYTE AS INTEGER _                            ' __in short LOBYTE
' , BYVAL HIBYTE AS INTEGER _                            ' __in short HIBYTE
' ) AS INTEGER                                           ' short
' ========================================================================================

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_TLI_SearchHelper       = GUID$("{8B217752-717D-11CE-AB5B-D41203C10000}")
$CLSID_TLI_TLIApplication     = GUID$("{8B21775E-717D-11CE-AB5B-D41203C10000}")
$CLSID_TLI_TypeLibInfo        = GUID$("{8B217746-717D-11CE-AB5B-D41203C10000}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_TLI_CoClasses            = GUID$("{8B217744-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_CoClassInfo          = GUID$("{8B217743-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_ConstantInfo         = GUID$("{8B21774D-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_Constants            = GUID$("{8B21774C-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_CustomData           = GUID$("{8B217763-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_CustomDataCollection = GUID$("{8B217764-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_CustomFilter         = GUID$("{8B217760-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_CustomSort           = GUID$("{8B21775F-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_DeclarationInfo      = GUID$("{8B21774F-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_Declarations         = GUID$("{8B21774E-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_InterfaceInfo        = GUID$("{8B217741-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_Interfaces           = GUID$("{8B217742-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_IntrinsicAliases     = GUID$("{8B217762-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_IntrinsicAliasInfo   = GUID$("{8B217761-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_ListBoxNotification  = GUID$("{8B217758-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_MemberInfo           = GUID$("{8B217747-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_Members              = GUID$("{8B217748-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_ParameterInfo        = GUID$("{8B217749-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_Parameters           = GUID$("{8B21774A-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_RecordInfo           = GUID$("{8B21775B-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_Records              = GUID$("{8B21775C-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_SearchItem           = GUID$("{8B217756-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_SearchResults        = GUID$("{8B217757-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_TypeInfo             = GUID$("{8B217759-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_TypeInfos            = GUID$("{8B21775A-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_UnionInfo            = GUID$("{8B217765-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_Unions               = GUID$("{8B217766-717D-11CE-AB5B-D41203C10000}")
$IID_TLI_VarTypeInfo          = GUID$("{8B21774B-717D-11CE-AB5B-D41203C10000}")
$IID__TLI_BaseTypeInfos       = GUID$("{8B217750-717D-11CE-AB5B-D41203C10000}")
$IID__TLI_SearchHelper        = GUID$("{8B217751-717D-11CE-AB5B-D41203C10000}")
$IID__TLI_TLIApplication      = GUID$("{8B21775D-717D-11CE-AB5B-D41203C10000}")
$IID__TLI_TypeLibInfo         = GUID$("{8B217745-717D-11CE-AB5B-D41203C10000}")

' ========================================================================================
' TliErrors enum
' Custom errors raised by TLI
' ========================================================================================

%tliErrNoCurrentTypelib                                 = -2147220991
%tliErrCantLoadLibrary                                  = -2147220990
%tliErrTypeLibNotRegistered                             = -2147220989
%tliErrSearchResultsChanged                             = -2147220988
%tliErrNotApplicable                                    = -2147220987
%tliErrIncompatibleData                                 = -2147220986
%tliErrIncompatibleSearchType                           = -2147220985
%tliErrIncompatibleTypeKind                             = -2147220984
%tliErrInaccessibleImportLib                            = -2147220983
%tliErrNoDefaultValue                                   = -2147220982
%tliErrDataNotAvailable                                 = -2147220981
%tliErrNotAnEntryPoint                                  = -2147220980
%tliErrStopFiltering                                    = -2147220979
%tliErrArrayBoundsNotAvailable                          = -2147220978
%tliErrSearchResultsNotSorted                           = -2147220977
%tliErrTypeNotArray                                     = -2147220976

' ========================================================================================
' TypeFlags enum
' OLE Automation TYPEFLAG values
' The remed constants are already declared in oaidl.inc
' ========================================================================================

%TYPEFLAG_NONE                                          = &H0??
'%TYPEFLAG_FAPPOBJECT                                    = &H1??
'%TYPEFLAG_FCANCREATE                                    = &H2??
'%TYPEFLAG_FLICENSED                                     = &H4??
'%TYPEFLAG_FPREDECLID                                    = &H8??
'%TYPEFLAG_FHIDDEN                                       = &H10??
'%TYPEFLAG_FCONTROL                                      = &H20??
'%TYPEFLAG_FDUAL                                         = &H40??
'%TYPEFLAG_FNONEXTENSIBLE                                = &H80??
'%TYPEFLAG_FOLEAUTOMATION                                = &H100??
'%TYPEFLAG_FRESTRICTED                                   = &H200??
'%TYPEFLAG_FAGGREGATABLE                                 = &H400??
'%TYPEFLAG_FREPLACEABLE                                  = &H800??
'%TYPEFLAG_FDISPATCHABLE                                 = &H1000??
'%TYPEFLAG_FREVERSEBIND                                  = &H2000??
'%TYPEFLAG_FPROXY                                        = &H4000??
%TYPEFLAG_DEFAULTFILTER                                 = &H210??
%TYPEFLAG_COCLASSATTRIBUTES                             = &H63F??
%TYPEFLAG_INTERFACEATTRIBUTES                           = &H7BC0??
%TYPEFLAG_DISPATCHATTRIBUTES                            = &H5AC0??
%TYPEFLAG_ALIASATTRIBUTES                               = &H210??
%TYPEFLAG_MODULEATTRIBUTES                              = &H210??
%TYPEFLAG_ENUMATTRIBUTES                                = &H210??
%TYPEFLAG_RECORDATTRIBUTES                              = &H210??
%TYPEFLAG_UNIONATTRIBUTES                               = &H210??

' ========================================================================================
' ImplTypeFlags enum
' OLE Automation IMPLTYPEFLAG values
' The remed constants are already declared in oaidl.inc
' ========================================================================================

'%IMPLTYPEFLAG_FDEFAULT                                  = &H1??
'%IMPLTYPEFLAG_FSOURCE                                   = &H2??
'%IMPLTYPEFLAG_FRESTRICTED                               = &H4??
'%IMPLTYPEFLAG_FDEFAULTVTABLE                            = &H8??

' ========================================================================================
' TypeKinds enum
' OLE Automation TYPEKIND values
' The remed constants are already declared in oaidl.inc
' ========================================================================================

'%TKIND_ENUM       = 0
'%TKIND_RECORD     = %TKIND_ENUM + 1
'%TKIND_MODULE     = %TKIND_RECORD + 1
'%TKIND_INTERFACE  = %TKIND_MODULE + 1
'%TKIND_DISPATCH   = %TKIND_INTERFACE + 1
'%TKIND_COCLASS    = %TKIND_DISPATCH + 1
'%TKIND_ALIAS      = %TKIND_COCLASS + 1
'%TKIND_UNION      = %TKIND_ALIAS + 1
'%TKIND_MAX        = %TKIND_UNION + 1

' ========================================================================================
' FuncFlags enum
' OLE Automation FUNCFLAG values
' The remed constants are already declared in oaidl.inc
' ========================================================================================

%FUNCFLAG_NONE                                          = &H0??
'%FUNCFLAG_FRESTRICTED                                   = &H1??
'%FUNCFLAG_FSOURCE                                       = &H2??
'%FUNCFLAG_FBINDABLE                                     = &H4??
'%FUNCFLAG_FREQUESTEDIT                                  = &H8??
'%FUNCFLAG_FDISPLAYBIND                                  = &H10??
'%FUNCFLAG_FDEFAULTBIND                                  = &H20??
'%FUNCFLAG_FHIDDEN                                       = &H40??
'%FUNCFLAG_FUSESGETLASTERROR                             = &H80??
'%FUNCFLAG_FDEFAULTCOLLELEM                              = &H100??
'%FUNCFLAG_FUIDEFAULT                                    = &H200??
'%FUNCFLAG_FNONBROWSABLE                                 = &H400??
'%FUNCFLAG_FREPLACEABLE                                  = &H800??
'%FUNCFLAG_FIMMEDIATEBIND                                = &H1000??
%FUNCFLAG_DEFAULTFILTER                                 = &H41??

' ========================================================================================
' VarFlags enum
' OLE Automation VARFLAG values
' The remed constants are already declared in oaidl.inc
' ========================================================================================

%VARFLAG_NONE                                           = &H0??
'%VARFLAG_FREADONLY                                      = &H1??
'%VARFLAG_FSOURCE                                        = &H2??
'%VARFLAG_FBINDABLE                                      = &H4??
'%VARFLAG_FREQUESTEDIT                                   = &H8??
'%VARFLAG_FDISPLAYBIND                                   = &H10??
'%VARFLAG_FDEFAULTBIND                                   = &H20??
'%VARFLAG_FHIDDEN                                        = &H40??
'%VARFLAG_FRESTRICTED                                    = &H80??
'%VARFLAG_FDEFAULTCOLLELEM                               = &H100??
'%VARFLAG_FUIDEFAULT                                     = &H200??
'%VARFLAG_FNONBROWSABLE                                  = &H400??
'%VARFLAG_FREPLACEABLE                                   = &H800??
'%VARFLAG_FIMMEDIATEBIND                                 = &H1000??
%VARFLAG_DEFAULTFILTER                                  = &HC0??

' ========================================================================================
' SysKinds enum
' OLE Automation SYS values
' The remed constants are already declared in oaidl.inc
' ========================================================================================

'%SYS_WIN16                                              = 0
'%SYS_WIN32                                              = 1
'%SYS_MAC                                                = 2

' ========================================================================================
' LibFlags enum
' OLE Automation LIBFLAG values
' The remed constants are already declared in oaidl.inc
' ========================================================================================

'%LIBFLAG_FRESTRICTED                                    = &H1??
'%LIBFLAG_FCONTROL                                       = &H2??
'%LIBFLAG_FHIDDEN                                        = &H4??
'%LIBFLAG_FHASDISKIMAGE                                  = &H8??

' ========================================================================================
' InvokeKinds enum
' OLE Automation INVOKEKIND values
' The remed constants are already declared in oaidl.inc
' ========================================================================================

%INVOKE_UNKNOWN                                         = 0
'%INVOKE_FUNC                                            = 1
'%INVOKE_PROPERTYGET                                     = 2
'%INVOKE_PROPERTYPUT                                     = 4
'%INVOKE_PROPERTYPUTREF                                  = 8
%INVOKE_EVENTFUNC                                       = &H10
%INVOKE_CONST                                           = &H20

' ========================================================================================
' IDLFlags enum
' OLE Automation IDLFLAG values
' The remed constants are already declared in oaidl.inc
' ========================================================================================

'%IDLFLAG_NONE                                           = 0??
'%IDLFLAG_FIN                                            = 1??
'%IDLFLAG_FOUT                                           = 2??
'%IDLFLAG_FLCID                                          = 4??
'%IDLFLAG_FRETVAL                                        = 8??

' ========================================================================================
' ParamFlags enum
' OLE Automation PARAMFLAG values
' The remed constants are already declared in oaidl.inc
' ========================================================================================

'%PARAMFLAG_NONE                                         = &H0??
'%PARAMFLAG_FIN                                          = &H1??
'%PARAMFLAG_FOUT                                         = &H2??
'%PARAMFLAG_FLCID                                        = &H4??
'%PARAMFLAG_FRETVAL                                      = &H8??
'%PARAMFLAG_FOPT                                         = &H10??
'%PARAMFLAG_Fdefault value                                  = &H20??
'%PARAMFLAG_FHASCUSTDATA                                 = &H40??

' ========================================================================================
' DescKinds enum
' OLE Automation DESCKIND values
' The remed constants are already declared in oaidl.inc
' ========================================================================================

%DESCKIND_NONE           = 0
%DESCKIND_FUNCDESC       = %DESCKIND_NONE + 1
%DESCKIND_VARDESC        = %DESCKIND_FUNCDESC + 1

' ========================================================================================
' TliVarType enum
' OLE Automation VARIANT types
' The remed constants are already declared in wtypes.inc
' ========================================================================================

'%VT_EMPTY                                               = 0
'%VT_NULL                                                = 1
'%VT_I2                                                  = 2
'%VT_I4                                                  = 3
'%VT_R4                                                  = 4
'%VT_R8                                                  = 5
'%VT_CY                                                  = 6
'%VT_DATE                                                = 7
'%VT_BSTR                                                = 8
'%VT_DISPATCH                                            = 9
'%VT_ERROR                                               = 10
'%VT_BOOL                                                = 11
'%VT_VARIANT                                             = 12
'%VT_UNKNOWN                                             = 13
'%VT_DECIMAL                                             = 14
'%VT_I1                                                  = 16
'%VT_UI1                                                 = 17
'%VT_UI2                                                 = 18
'%VT_UI4                                                 = 19
'%VT_I8                                                  = 20
'%VT_UI8                                                 = 21
'%VT_INT                                                 = 22
'%VT_UINT                                                = 23
'%VT_VOID                                                = 24
'%VT_HRESULT                                             = 25
'%VT_PTR                                                 = 26
'%VT_SAFEARRAY                                           = 27
'%VT_CARRAY                                              = 28
'%VT_USERDEFINED                                         = 29
'%VT_LPSTR                                               = 30
'%VT_LPWSTR                                              = 31
'%VT_RECORD                                              = 36
'%VT_FILETIME                                            = 64
'%VT_BLOB                                                = 65
'%VT_STREAM                                              = 66
'%VT_STORAGE                                             = 67
'%VT_STREAMED_OBJECT                                     = 68
'%VT_STORED_OBJECT                                       = 69
'%VT_BLOB_OBJECT                                         = 70
'%VT_CF                                                  = 71
'%VT_CLSID                                               = 72
'%VT_VECTOR                                              = &H1000
'%VT_ARRAY                                               = &H2000
'%VT_BYREF                                               = &H4000
'%VT_RESERVED                                            = &H8000

' ========================================================================================
' TliSearchTypes enum
' Determines content of SearchResults collection
' ========================================================================================

%tliStDefault                                           = 4096
%tliStClasses                                           = 1
%tliStEvents                                            = 2
%tliStConstants                                         = 4
%tliStDeclarations                                      = 8
%tliStAppObject                                         = 16
%tliStRecords                                           = 32
%tliStIntrinsicAliases                                  = 64
%tliStUnions                                            = 128
%tliStAll                                               = 239

' ========================================================================================
' TliWindowTypes enum
' Values for window class of hWnd in Get*Direct methods
' ========================================================================================

%tliWtListBox                                           = 0
%tliWtComboBox                                          = 1

' ========================================================================================
' TliItemDataTypes enum
' Determine ItemData content for GetMembers*Direct methods
' ========================================================================================

%tliIdtMemberID                                         = 0
%tliIdtInvokeKinds                                      = 1

' ========================================================================================
' TliCustomFilterAction enum
' Actions for CustomFilter.Visit
' ========================================================================================

%tliCfaLeave                                            = 0
%tliCfaDuplicate                                        = 1
%tliCfaExtract                                          = 2
%tliCfaDelete                                           = 3

' ========================================================================================
' CallConvs enum
' OLE Automation CALLCONV values
' The remed constants are already declared in oaidl.inc
' ========================================================================================

'%CC_FASTCALL   = 0
'%CC_CDECL      = 1
'%CC_MSCPASCAL  = %CC_CDECL + 1
'%CC_PASCAL     = %CC_MSCPASCAL
'%CC_MACPASCAL  = %CC_PASCAL + 1
'%CC_STDCALL    = %CC_MACPASCAL + 1
'%CC_FPFASTCALL = %CC_STDCALL + 1
'%CC_SYSCALL    = %CC_FPFASTCALL + 1
'%CC_MPWCDECL   = %CC_SYSCALL + 1
'%CC_MPWPASCAL  = %CC_MPWCDECL + 1
'%CC_MAX        = %CC_MPWPASCAL + 1

' ########################################################################################
' Interface name = VarTypeInfo
' IID = {8B21774B-717D-11CE-AB5B-D41203C10000}
' VarType information for parameters and return types
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%TLI_VarTypeInfo_INTERFACE_DEFINED)
    %TLI_VarTypeInfo_INTERFACE_DEFINED = 1

INTERFACE TLI_VarTypeInfo $IID_TLI_VarTypeInfo

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS TLI_VarTypeInfo                                 ' __retval_out VarTypeInfo **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OldVarType_ <1610743810> ( _            ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET TypeInfo <1610743811> ( _               ' VTable offset = 40
   ) AS TLI_TypeInfo                                    ' __retval_out TypeInfo **retVal
   ' =====================================================================================
   PROPERTY GET TypeInfoNumber <1610743812> ( _         ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET TypedVariant <1610743813> ( _           ' VTable offset = 48
   ) AS VARIANT                                         ' __retval_out VT_VARIANT *retVal
   ' =====================================================================================
   PROPERTY GET IsExternalType <1610743814> ( _         ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retVal
   ' =====================================================================================
   PROPERTY GET TypeLibInfoExternal <1610743815> ( _    ' VTable offset = 56
   ) AS IDispatch                                       ' __retval_out TypeLibInfo **retVal
   ' =====================================================================================
   PROPERTY GET PointerLevel <1610743816> ( _           ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET VarType <0> ( _                         ' VTable offset = 64
   ) AS LONG                                            ' __retval_out TliVarType *retVal
   ' =====================================================================================
   METHOD ArrayBounds <1610743818> ( _                  ' VTable offset = 68
     BYREF Bounds AS DWORD _                            ' __out SAFEARRAY *Bounds
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET ElementPointerLevel <1610743819> ( _    ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_VarTypeInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ParameterInfo
' IID = {8B217749-717D-11CE-AB5B-D41203C10000}
' Parameter Information
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%TLI_ParameterInfo_INTERFACE_DEFINED)
    %TLI_ParameterInfo_INTERFACE_DEFINED = 1

INTERFACE TLI_ParameterInfo $IID_TLI_ParameterInfo

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS TLI_ParameterInfo                               ' __retval_out ParameterInfo **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET Optional <1610743811> ( _               ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retVal
   ' =====================================================================================
   PROPERTY GET OldFlags_ <1610743812> ( _              ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET VarTypeInfo <1610743813> ( _            ' VTable offset = 48
   ) AS TLI_VarTypeInfo                                 ' __retval_out VarTypeInfo **retVal
   ' =====================================================================================
   PROPERTY GET Default <1610743814> ( _                ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retVal
   ' =====================================================================================
   PROPERTY GET DefaultValue <1610743815> ( _           ' VTable offset = 56
   ) AS VARIANT                                         ' __retval_out VARIANT *retVal
   ' =====================================================================================
   PROPERTY GET HasCustomData <1610743816> ( _          ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CustomDataCollection <1610743817> ( _   ' VTable offset = 64
   ) AS TLI_CustomDataCollection                        ' __retval_out CustomDataCollection **retVal
   ' =====================================================================================
   PROPERTY GET Flags <1610743818> ( _                  ' VTable offset = 68
   ) AS LONG                                            ' __retval_out ParamFlags *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_ParameterInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Parameters
' IID = {8B21774A-717D-11CE-AB5B-D41203C10000}
' Parameters Collection
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%TLI_Parameters_INTERFACE_DEFINED)
    %TLI_Parameters_INTERFACE_DEFINED = 1

INTERFACE TLI_Parameters $IID_TLI_Parameters

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS TLI_Parameters                                  ' __retval_out Parameters **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **retVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Index AS INTEGER _                           ' __in short Index
   ) AS TLI_ParameterInfo                               ' __retval_out ParameterInfo **retVal
   ' =====================================================================================
   PROPERTY GET Count <1610743812> ( _                  ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET OptionalCount <1610743813> ( _          ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET DefaultCount <1610743814> ( _           ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_Parameters_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = MemberInfo
' IID = {8B217747-717D-11CE-AB5B-D41203C10000}
' MemberInfo object
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%TLI_MemberInfo_INTERFACE_DEFINED)
    %TLI_MemberInfo_INTERFACE_DEFINED = 1

INTERFACE TLI_MemberInfo $IID_TLI_MemberInfo

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS TLI_MemberInfo                                  ' __retval_out MemberInfo **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET OldHelpString_ <1610743811> ( _         ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET HelpContext <1610743812> ( _            ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   PROPERTY GET HelpFile <1610743813> ( _               ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET Parameters <1610743814> ( _             ' VTable offset = 52
   ) AS TLI_Parameters                                  ' __retval_out Parameters **retVal
   ' =====================================================================================
   PROPERTY GET ReturnType <1610743815> ( _             ' VTable offset = 56
   ) AS TLI_VarTypeInfo                                 ' __retval_out VarTypeInfo **retVal
   ' =====================================================================================
   PROPERTY GET AttributeMask <1610743816> ( _          ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET AttributeStrings <1610743817> ( _       ' VTable offset = 64
     BYREF IN AttributeArray AS DWORD _                 ' __out SAFEARRAY *AttributeArray
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET OldDescKind_ <1610743818> ( _           ' VTable offset = 68
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET Value <1610743819> ( _                  ' VTable offset = 72
   ) AS VARIANT                                         ' __retval_out VARIANT *retVal
   ' =====================================================================================
   PROPERTY GET MemberId <1610743820> ( _               ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   PROPERTY GET VTableOffset <1610743821> ( _           ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET InvokeKind <1610743822> ( _             ' VTable offset = 84
   ) AS LONG                                            ' __retval_out InvokeKinds *retVal
   ' =====================================================================================
   PROPERTY GET CustomDataCollection <1610743823> ( _   ' VTable offset = 88
   ) AS TLI_CustomDataCollection                        ' __retval_out CustomDataCollection **retVal
   ' =====================================================================================
   PROPERTY GET DescKind <1610743824> ( _               ' VTable offset = 92
   ) AS LONG                                            ' __retval_out DescKinds *retVal
   ' =====================================================================================
   METHOD GetDllEntry <1610743825> ( _                  ' VTable offset = 96
     BYREF DllName AS WSTRING _                         ' __out BSTR *DllName
   , BYREF EntryName AS WSTRING _                       ' __out BSTR *EntryName
   , BYREF Ordinal AS INTEGER _                         ' __out short *Ordinal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HelpString <1610743826> ( _             ' VTable offset = 100
     OPTIONAL BYVAL LCID AS LONG _                      ' __opt_in long LCID [default value = 0]
   ) AS WSTRING                                         ' __retval_out *retVal /* *VT_BSTR */
   ' =====================================================================================
   PROPERTY GET HelpStringDll <1610743827> ( _          ' VTable offset = 104
     OPTIONAL BYVAL LCID AS LONG _                      ' __opt_in long LCID [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET HelpStringContext <1610743828> ( _      ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   PROPERTY GET CallConv <1610743829> ( _               ' VTable offset = 112
   ) AS LONG                                            ' __retval_out CallConvs *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_MemberInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Members
' IID = {8B217748-717D-11CE-AB5B-D41203C10000}
' Members Collection
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%TLI_Members_INTERFACE_DEFINED)
    %TLI_Members_INTERFACE_DEFINED = 1

INTERFACE TLI_Members $IID_TLI_Members

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS TLI_Members                                     ' __retval_out Members **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **retVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Index AS INTEGER _                           ' __in short Index
   ) AS TLI_MemberInfo                                  ' __retval_out MemberInfo **retVal
   ' =====================================================================================
   PROPERTY GET Count <1610743812> ( _                  ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY SET FuncFilter <1610743813> ( _             ' VTable offset = 48
     BYVAL retVal AS LONG _                             ' __in FuncFlags retVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FuncFilter <1610743813> ( _             ' VTable offset = 52
   ) AS LONG                                            ' __retval_out FuncFlags *retVal
   ' =====================================================================================
   PROPERTY SET VarFilter <1610743815> ( _              ' VTable offset = 56
     BYVAL retVal AS LONG _                             ' __in VarFlags retVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET VarFilter <1610743815> ( _              ' VTable offset = 60
   ) AS LONG                                            ' __retval_out VarFlags *retVal
   ' =====================================================================================
   METHOD OldFillList_ <1610743817> ( _                 ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GetFilteredMembers <1610743818> ( _     ' VTable offset = 68
     OPTIONAL BYVAL ShowUnderscore AS INTEGER _         ' __opt_in VARIANT_BOOL ShowUnderscore [default value = 0]
   ) AS TLI_SearchResults                               ' __retval_out SearchResults **retVal
   ' =====================================================================================
   METHOD GetFilteredMembersDirect <1610743819> ( _     ' VTable offset = 72
     BYVAL hWnd AS LONG _                               ' __in int hWnd
   , OPTIONAL BYVAL WindowType AS LONG _                ' __opt_in TliWindowTypes WindowType [default value = 0]
   , OPTIONAL BYVAL ItemDataType AS LONG _              ' __opt_in TliItemDataTypes ItemDataType [default value = 0]
   , OPTIONAL BYVAL ShowUnderscore AS INTEGER _         ' __opt_in VARIANT_BOOL ShowUnderscore [default value = 0]
   ) AS INTEGER                                         ' __retval_out int *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_Members_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = InterfaceInfo
' IID = {8B217741-717D-11CE-AB5B-D41203C10000}
' Members are a subset of TypeInfo object members.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%TLI_InterfaceInfo_INTERFACE_DEFINED)
    %TLI_InterfaceInfo_INTERFACE_DEFINED = 1

INTERFACE TLI_InterfaceInfo $IID_TLI_InterfaceInfo

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS TLI_InterfaceInfo                               ' __retval_out InterfaceInfo **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET GUID <1610743811> ( _                   ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET OldHelpString_ <1610743812> ( _         ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET HelpContext <1610743813> ( _            ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   PROPERTY GET HelpFile <1610743814> ( _               ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET AttributeMask <1610743815> ( _          ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET AttributeStrings <1610743816> ( _       ' VTable offset = 60
     BYREF IN AttributeArray AS DWORD _                 ' __out SAFEARRAY *AttributeArray
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET OldTypeKind_ <1610743817> ( _           ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET TypeKindString <1610743818> ( _         ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET TypeInfoNumber <1610743819> ( _         ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET VTableInterface <1610743820> ( _        ' VTable offset = 76
   ) AS TLI_InterfaceInfo                               ' __retval_out InterfaceInfo **retVal
   ' =====================================================================================
   PROPERTY GET GetMember <1610743821> ( _              ' VTable offset = 80
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS TLI_MemberInfo                                  ' __retval_out MemberInfo **retVal
   ' =====================================================================================
   PROPERTY GET Members <1610743822> ( _                ' VTable offset = 84
   ) AS TLI_Members                                     ' __retval_out Members **retVal
   ' =====================================================================================
   PROPERTY GET Parent <1610743823> ( _                 ' VTable offset = 88
   ) AS IDispatch                                       ' __retval_out TypeLibInfo **retVal
   ' =====================================================================================
   PROPERTY GET ImpliedInterfaces <1610743824> ( _      ' VTable offset = 92
   ) AS TLI_Interfaces                                  ' __retval_out Interfaces **retVal
   ' =====================================================================================
   METHOD DefaultInterface_ <1610743825> ( _            ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD DefaultEventInterface_ <1610743826> ( _       ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TypeKind <1610743827> ( _               ' VTable offset = 104
   ) AS LONG                                            ' __retval_out TypeKinds *retVal
   ' =====================================================================================
   PROPERTY GET ResolvedType <1610743828> ( _           ' VTable offset = 108
   ) AS TLI_VarTypeInfo                                 ' __retval_out VarTypeInfo **retVal
   ' =====================================================================================
   PROPERTY GET CustomDataCollection <1610743829> ( _   ' VTable offset = 112
   ) AS TLI_CustomDataCollection                        ' __retval_out CustomDataCollection **retVal
   ' =====================================================================================
   PROPERTY GET HelpString <1610743830> ( _             ' VTable offset = 116
     OPTIONAL BYVAL LCID AS LONG _                      ' __opt_in long LCID
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET ITypeInfo <1610743831> ( _              ' VTable offset = 120
   ) AS IUnknown                                        ' __retval_out IUnknown **retVal
   ' =====================================================================================
   PROPERTY GET MajorVersion <1610743832> ( _           ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET MinorVersion <1610743833> ( _           ' VTable offset = 128
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET HelpStringDll <1610743834> ( _          ' VTable offset = 132
     OPTIONAL BYVAL LCID AS LONG _                      ' __opt_in long LCID [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET HelpStringContext <1610743835> ( _      ' VTable offset = 136
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_InterfaceInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = _BaseTypeInfos
' IID = {8B217750-717D-11CE-AB5B-D41203C10000}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%TLI_BaseTypeInfos_INTERFACE_DEFINED)
    %TLI_BaseTypeInfos_INTERFACE_DEFINED = 1

INTERFACE TLI_BaseTypeInfos $IID__TLI_BaseTypeInfos

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS TLI_TypeInfos                                   ' __retval_out TypeInfos **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **retVal
   ' =====================================================================================
   PROPERTY GET Count <1610743811> ( _                  ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_BaseTypeInfos_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Interfaces
' IID = {8B217742-717D-11CE-AB5B-D41203C10000}
' Subset of TypeInfos collection.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _BaseTypeInfos
' ########################################################################################

#IF NOT %DEF(%TLI_Interfaces_INTERFACE_DEFINED)
    %TLI_Interfaces_INTERFACE_DEFINED = 1

INTERFACE TLI_Interfaces $IID_TLI_Interfaces

   INHERIT IDispatch

   ' =====================================================================================
   ' _BaseTypeInfos Methods
   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS TLI_TypeInfos                                   ' __retval_out TypeInfos **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **retVal
   ' =====================================================================================
   PROPERTY GET Count <1610743811> ( _                  ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================

   ' =====================================================================================
   ' Interfaces Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 44
     BYVAL Index AS INTEGER _                           ' __in short Index
   ) AS TLI_InterfaceInfo                               ' __retval_out InterfaceInfo **retVal
   ' =====================================================================================
   PROPERTY GET IndexedItem <1610809345> ( _            ' VTable offset = 48
     BYVAL TypeInfoNumber AS INTEGER _                  ' __in short TypeInfoNumber
   ) AS TLI_InterfaceInfo                               ' __retval_out InterfaceInfo **retVal
   ' =====================================================================================
   PROPERTY GET NamedItem <1610809346> ( _              ' VTable offset = 52
     BYREF IN TypeInfoName AS WSTRING _                 ' __in_out BSTR *TypeInfoName
   ) AS TLI_InterfaceInfo                               ' __retval_out InterfaceInfo **retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_Interfaces_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = CoClassInfo
' IID = {8B217743-717D-11CE-AB5B-D41203C10000}
' Members are a subset of TypeInfo object members.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%TLI_CoClassInfo_INTERFACE_DEFINED)
    %TLI_CoClassInfo_INTERFACE_DEFINED = 1

INTERFACE TLI_CoClassInfo $IID_TLI_CoClassInfo

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS TLI_CoClassInfo                                 ' __retval_out CoClassInfo **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET GUID <1610743811> ( _                   ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET OldHelpString_ <1610743812> ( _         ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET HelpContext <1610743813> ( _            ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   PROPERTY GET HelpFile <1610743814> ( _               ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET AttributeMask <1610743815> ( _          ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET AttributeStrings <1610743816> ( _       ' VTable offset = 60
     BYREF IN AttributeArray AS DWORD _                 ' __out SAFEARRAY *AttributeArray
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET OldTypeKind_ <1610743817> ( _           ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET TypeKindString <1610743818> ( _         ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET TypeInfoNumber <1610743819> ( _         ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   METHOD placeholder_VTableInterface_ <1610743820> ( _ ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================
   METHOD placeholder_GetMember_ <1610743821> ( _       ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   METHOD placeholder_Members_ <1610743822> ( _         ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Parent <1610743823> ( _                 ' VTable offset = 88
   ) AS IDispatch                                       ' __retval_out TypeLibInfo **retVal
   ' =====================================================================================
   PROPERTY GET Interfaces <1610743824> ( _             ' VTable offset = 92
   ) AS TLI_Interfaces                                  ' __retval_out Interfaces **retVal
   ' =====================================================================================
   PROPERTY GET DefaultInterface <1610743825> ( _       ' VTable offset = 96
   ) AS TLI_InterfaceInfo                               ' __retval_out InterfaceInfo **retVal
   ' =====================================================================================
   PROPERTY GET DefaultEventInterface <1610743826> ( _  ' VTable offset = 100
   ) AS TLI_InterfaceInfo                               ' __retval_out InterfaceInfo **retVal
   ' =====================================================================================
   PROPERTY GET TypeKind <1610743827> ( _               ' VTable offset = 104
   ) AS LONG                                            ' __retval_out TypeKinds *retVal
   ' =====================================================================================
   PROPERTY GET ResolvedType <1610743828> ( _           ' VTable offset = 108
   ) AS TLI_VarTypeInfo                                 ' __retval_out VarTypeInfo **retVal
   ' =====================================================================================
   PROPERTY GET CustomDataCollection <1610743829> ( _   ' VTable offset = 112
   ) AS TLI_CustomDataCollection                        ' __retval_out CustomDataCollection **retVal
   ' =====================================================================================
   PROPERTY GET HelpString <1610743830> ( _             ' VTable offset = 116
     OPTIONAL BYVAL LCID AS LONG _                      ' __opt_in long LCID [default value = 0]
   ) AS WSTRING                                         ' __retval_out *retVal /* *VT_BSTR */
   ' =====================================================================================
   PROPERTY GET ITypeInfo <1610743831> ( _              ' VTable offset = 120
   ) AS IUnknown                                        ' __retval_out IUnknown **retVal
   ' =====================================================================================
   PROPERTY GET MajorVersion <1610743832> ( _           ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET MinorVersion <1610743833> ( _           ' VTable offset = 128
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET HelpStringDll <1610743834> ( _          ' VTable offset = 132
     OPTIONAL BYVAL LCID AS LONG _                      ' __opt_in long LCID [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET HelpStringContext <1610743835> ( _      ' VTable offset = 136
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_CoClassInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = CoClasses
' IID = {8B217744-717D-11CE-AB5B-D41203C10000}
' Subset of TypeInfos collection.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _BaseTypeInfos
' ########################################################################################

#IF NOT %DEF(%TLI_CoClasses_INTERFACE_DEFINED)
    %TLI_CoClasses_INTERFACE_DEFINED = 1

INTERFACE TLI_CoClasses $IID_TLI_CoClasses

   INHERIT IDispatch

   ' =====================================================================================
   ' _BaseTypeInfos Methods
   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS TLI_TypeInfos                                   ' __retval_out TypeInfos **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **retVal
   ' =====================================================================================
   PROPERTY GET Count <1610743811> ( _                  ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================

   ' =====================================================================================
   ' CoClasses Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 44
     BYVAL Index AS INTEGER _                           ' __in short Index
   ) AS TLI_CoClassInfo                                 ' __retval_out CoClassInfo **retVal
   ' =====================================================================================
   PROPERTY GET IndexedItem <1610809345> ( _            ' VTable offset = 48
     BYVAL TypeInfoNumber AS INTEGER _                  ' __in short TypeInfoNumber
   ) AS TLI_CoClassInfo                                 ' __retval_out CoClassInfo **retVal
   ' =====================================================================================
   PROPERTY GET NamedItem <1610809346> ( _              ' VTable offset = 52
     BYREF IN TypeInfoName AS WSTRING _                 ' __in_out BSTR *TypeInfoName
   ) AS TLI_CoClassInfo                                 ' __retval_out CoClassInfo **retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_CoClasses_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ConstantInfo
' IID = {8B21774D-717D-11CE-AB5B-D41203C10000}
' Members are a subset of TypeInfo object members.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%TLI_ConstantInfo_INTERFACE_DEFINED)
    %TLI_ConstantInfo_INTERFACE_DEFINED = 1

INTERFACE TLI_ConstantInfo $IID_TLI_ConstantInfo

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS TLI_TypeInfo                                    ' __retval_out TypeInfo **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET GUID <1610743811> ( _                   ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET OldHelpString_ <1610743812> ( _         ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET HelpContext <1610743813> ( _            ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   PROPERTY GET HelpFile <1610743814> ( _               ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET AttributeMask <1610743815> ( _          ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET AttributeStrings <1610743816> ( _       ' VTable offset = 60
     BYREF IN AttributeArray AS DWORD _                 ' __out SAFEARRAY *AttributeArray
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET OldTypeKind_ <1610743817> ( _           ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET TypeKindString <1610743818> ( _         ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET TypeInfoNumber <1610743819> ( _         ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   METHOD placeholder_VTableInterface_ <1610743820> ( _ ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GetMember <1610743821> ( _              ' VTable offset = 80
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS TLI_MemberInfo                                  ' __retval_out MemberInfo **retVal
   ' =====================================================================================
   PROPERTY GET Members <1610743822> ( _                ' VTable offset = 84
   ) AS TLI_Members                                     ' __retval_out Members **retVal
   ' =====================================================================================
   PROPERTY GET Parent <1610743823> ( _                 ' VTable offset = 88
   ) AS IDispatch                                       ' __retval_out TypeLibInfo **retVal
   ' =====================================================================================
   METHOD ImpliedInterfaces_ <1610743824> ( _           ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD DefaultInterface_ <1610743825> ( _            ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD DefaultEventInterface_ <1610743826> ( _       ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TypeKind <1610743827> ( _               ' VTable offset = 104
   ) AS LONG                                            ' __retval_out TypeKinds *retVal
   ' =====================================================================================
   PROPERTY GET ResolvedType <1610743828> ( _           ' VTable offset = 108
   ) AS TLI_VarTypeInfo                                 ' __retval_out VarTypeInfo **retVal
   ' =====================================================================================
   PROPERTY GET CustomDataCollection <1610743829> ( _   ' VTable offset = 112
   ) AS TLI_CustomDataCollection                        ' __retval_out CustomDataCollection **retVal
   ' =====================================================================================
   PROPERTY GET HelpString <1610743830> ( _             ' VTable offset = 116
     OPTIONAL BYVAL LCID AS LONG _                      ' __opt_in long LCID [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET ITypeInfo <1610743831> ( _              ' VTable offset = 120
   ) AS IUnknown                                        ' __retval_out IUnknown **retVal
   ' =====================================================================================
   PROPERTY GET MajorVersion <1610743832> ( _           ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET MinorVersion <1610743833> ( _           ' VTable offset = 128
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET HelpStringDll <1610743834> ( _          ' VTable offset = 132
     OPTIONAL BYVAL LCID AS LONG _                      ' __opt_in long LCID [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET HelpStringContext <1610743835> ( _      ' VTable offset = 136
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_ConstantInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Constants
' IID = {8B21774C-717D-11CE-AB5B-D41203C10000}
' Subset of TypeInfos collection.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _BaseTypeInfos
' ########################################################################################

#IF NOT %DEF(%TLI_Constants_INTERFACE_DEFINED)
    %TLI_Constants_INTERFACE_DEFINED = 1

INTERFACE TLI_Constants $IID_TLI_Constants

   INHERIT IDispatch

   ' =====================================================================================
   ' _BaseTypeInfos Methods
   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS TLI_TypeInfos                                   ' __retval_out TypeInfos **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **retVal
   ' =====================================================================================
   PROPERTY GET Count <1610743811> ( _                  ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================

   ' =====================================================================================
   ' Constants Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 44
     BYVAL Index AS INTEGER _                           ' __in short Index
   ) AS TLI_ConstantInfo                                ' __retval_out ConstantInfo **retVal
   ' =====================================================================================
   PROPERTY GET IndexedItem <1610809345> ( _            ' VTable offset = 48
     BYVAL TypeInfoNumber AS INTEGER _                  ' __in short TypeInfoNumber
   ) AS TLI_ConstantInfo                                ' __retval_out ConstantInfo **retVal
   ' =====================================================================================
   PROPERTY GET NamedItem <1610809346> ( _              ' VTable offset = 52
     BYREF IN TypeInfoName AS WSTRING _                 ' __in_out BSTR *TypeInfoName
   ) AS TLI_ConstantInfo                                ' __retval_out ConstantInfo **retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_Constants_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DeclarationInfo
' IID = {8B21774F-717D-11CE-AB5B-D41203C10000}
' Members are a subset of TypeInfo object members.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%TLI_DeclarationInfo_INTERFACE_DEFINED)
    %TLI_DeclarationInfo_INTERFACE_DEFINED = 1

INTERFACE TLI_DeclarationInfo $IID_TLI_DeclarationInfo

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS TLI_DeclarationInfo                             ' __retval_out DeclarationInfo **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET GUID <1610743811> ( _                   ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET OldHelpString_ <1610743812> ( _         ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET HelpContext <1610743813> ( _            ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   PROPERTY GET HelpFile <1610743814> ( _               ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET AttributeMask <1610743815> ( _          ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET AttributeStrings <1610743816> ( _       ' VTable offset = 60
     BYREF IN AttributeArray AS DWORD _                 ' __out SAFEARRAY *AttributeArray
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET OldTypeKind_ <1610743817> ( _           ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET TypeKindString <1610743818> ( _         ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET TypeInfoNumber <1610743819> ( _         ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   METHOD placeholder_VTableInterface_ <1610743820> ( _ ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GetMember <1610743821> ( _              ' VTable offset = 80
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS TLI_MemberInfo                                  ' __retval_out MemberInfo **retVal
   ' =====================================================================================
   PROPERTY GET Members <1610743822> ( _                ' VTable offset = 84
   ) AS TLI_Members                                     ' __retval_out Members **retVal
   ' =====================================================================================
   PROPERTY GET Parent <1610743823> ( _                 ' VTable offset = 88
   ) AS IDispatch                                       ' __retval_out TypeLibInfo **retVal
   ' =====================================================================================
   METHOD ImpliedInterfaces_ <1610743824> ( _           ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD DefaultInterface_ <1610743825> ( _            ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD DefaultEventInterface_ <1610743826> ( _       ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TypeKind <1610743827> ( _               ' VTable offset = 104
   ) AS LONG                                            ' __retval_out TypeKinds *retVal
   ' =====================================================================================
   PROPERTY GET ResolvedType <1610743828> ( _           ' VTable offset = 108
   ) AS TLI_VarTypeInfo                                 ' __retval_out VarTypeInfo **retVal
   ' =====================================================================================
   PROPERTY GET CustomDataCollection <1610743829> ( _   ' VTable offset = 112
   ) AS TLI_CustomDataCollection                        ' __retval_out CustomDataCollection **retVal
   ' =====================================================================================
   PROPERTY GET HelpString <1610743830> ( _             ' VTable offset = 116
     OPTIONAL BYVAL LCID AS LONG _                      ' __opt_in long LCID [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET ITypeInfo <1610743831> ( _              ' VTable offset = 120
   ) AS IUnknown                                        ' __retval_out IUnknown **retVal
   ' =====================================================================================
   PROPERTY GET MajorVersion <1610743832> ( _           ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET MinorVersion <1610743833> ( _           ' VTable offset = 128
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET HelpStringDll <1610743834> ( _          ' VTable offset = 132
     OPTIONAL BYVAL LCID AS LONG _                      ' __opt_in long LCID [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET HelpStringContext <1610743835> ( _      ' VTable offset = 136
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_DeclarationInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Declarations
' IID = {8B21774E-717D-11CE-AB5B-D41203C10000}
' Subset of TypeInfos collection.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _BaseTypeInfos
' ########################################################################################

#IF NOT %DEF(%TLI_Declarations_INTERFACE_DEFINED)
    %TLI_Declarations_INTERFACE_DEFINED = 1

INTERFACE TLI_Declarations $IID_TLI_Declarations

   INHERIT IDispatch

   ' =====================================================================================
   ' _BaseTypeInfos Methods
   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS TLI_TypeInfos                                   ' __retval_out TypeInfos **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **retVal
   ' =====================================================================================
   PROPERTY GET Count <1610743811> ( _                  ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================

   ' =====================================================================================
   ' Declarations Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 44
     BYVAL Index AS INTEGER _                           ' __in short Index
   ) AS TLI_DeclarationInfo                             ' __retval_out DeclarationInfo **retVal
   ' =====================================================================================
   PROPERTY GET IndexedItem <1610809345> ( _            ' VTable offset = 48
     BYVAL TypeInfoNumber AS INTEGER _                  ' __in short TypeInfoNumber
   ) AS TLI_DeclarationInfo                             ' __retval_out DeclarationInfo **retVal
   ' =====================================================================================
   PROPERTY GET NamedItem <1610809346> ( _              ' VTable offset = 52
     BYREF IN TypeInfoName AS WSTRING _                 ' __in_out BSTR *TypeInfoName
   ) AS TLI_DeclarationInfo                             ' __retval_out DeclarationInfo **retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_Declarations_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = _SearchHelper
' IID = {8B217751-717D-11CE-AB5B-D41203C10000}
' Helper object for GetMembersWithSubString and multiple TypeLibs
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%TLI_SearchHelper_INTERFACE_DEFINED)
    %TLI_SearchHelper_INTERFACE_DEFINED = 1

INTERFACE TLI_SearchHelper $IID__TLI_SearchHelper

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out TypeLibInfo **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD OldInit_ <1610743810> ( _                     ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CheckHaveMatch <1610743811> ( _         ' VTable offset = 40
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retVal
   ' =====================================================================================
   ' The Init method, wrongly flagged as get property, is obsolete and does absolutely nothing.
   ' It is included only for compatibility with earlier TLI versions.
   ' =====================================================================================
   METHOD Init <1610743812> ( _                         ' VTable offset = 44
     BYVAL SysKind AS LONG _                            ' __in SysKinds SysKind
   , BYVAL LCID AS LONG _                               ' __in long LCID
   , OPTIONAL BYVAL GrowSize AS INTEGER _               ' __opt_in short GrowSize [default value = 100]
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_SearchHelper_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = TypeInfo
' IID = {8B217759-717D-11CE-AB5B-D41203C10000}
' TypeInfo Information
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%TLI_TypeInfo_INTERFACE_DEFINED)
    %TLI_TypeInfo_INTERFACE_DEFINED = 1

INTERFACE TLI_TypeInfo $IID_TLI_TypeInfo

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS TLI_TypeInfo                                    ' __retval_out TypeInfo **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET GUID <1610743811> ( _                   ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET OldHelpString_ <1610743812> ( _         ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET HelpContext <1610743813> ( _            ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   PROPERTY GET HelpFile <1610743814> ( _               ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET AttributeMask <1610743815> ( _          ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET AttributeStrings <1610743816> ( _       ' VTable offset = 60
     BYREF IN AttributeArray AS DWORD _                 ' __out SAFEARRAY *AttributeArray
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET OldTypeKind_ <1610743817> ( _           ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET TypeKindString <1610743818> ( _         ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET TypeInfoNumber <1610743819> ( _         ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET VTableInterface <1610743820> ( _        ' VTable offset = 76
   ) AS TLI_InterfaceInfo                               ' __retval_out InterfaceInfo **retVal
   ' =====================================================================================
   PROPERTY GET GetMember <1610743821> ( _              ' VTable offset = 80
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS TLI_MemberInfo                                  ' __retval_out MemberInfo **retVal
   ' =====================================================================================
   PROPERTY GET Members <1610743822> ( _                ' VTable offset = 84
   ) AS TLI_Members                                     ' __retval_out Members **retVal
   ' =====================================================================================
   PROPERTY GET Parent <1610743823> ( _                 ' VTable offset = 88
   ) AS IDispatch                                       ' __retval_out TypeLibInfo **retVal
   ' =====================================================================================
   PROPERTY GET Interfaces <1610743824> ( _             ' VTable offset = 92
   ) AS TLI_Interfaces                                  ' __retval_out Interfaces **retVal
   ' =====================================================================================
   PROPERTY GET DefaultInterface <1610743825> ( _       ' VTable offset = 96
   ) AS TLI_InterfaceInfo                               ' __retval_out InterfaceInfo **retVal
   ' =====================================================================================
   PROPERTY GET DefaultEventInterface <1610743826> ( _  ' VTable offset = 100
   ) AS TLI_InterfaceInfo                               ' __retval_out InterfaceInfo **retVal
   ' =====================================================================================
   PROPERTY GET TypeKind <1610743827> ( _               ' VTable offset = 104
   ) AS LONG                                            ' __retval_out TypeKinds *retVal
   ' =====================================================================================
   PROPERTY GET ResolvedType <1610743828> ( _           ' VTable offset = 108
   ) AS TLI_VarTypeInfo                                 ' __retval_out VarTypeInfo **retVal
   ' =====================================================================================
   PROPERTY GET CustomDataCollection <1610743829> ( _   ' VTable offset = 112
   ) AS TLI_CustomDataCollection                        ' __retval_out CustomDataCollection **retVal
   ' =====================================================================================
   PROPERTY GET HelpString <1610743830> ( _             ' VTable offset = 116
     OPTIONAL BYVAL LCID AS LONG _                      ' __opt_in long LCID [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET ITypeInfo <1610743831> ( _              ' VTable offset = 120
   ) AS IUnknown                                        ' __retval_out IUnknown **retVal
   ' =====================================================================================
   PROPERTY GET MajorVersion <1610743832> ( _           ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET MinorVersion <1610743833> ( _           ' VTable offset = 128
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET HelpStringDll <1610743834> ( _          ' VTable offset = 132
     OPTIONAL BYVAL LCID AS LONG _                      ' __opt_in long LCID [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET HelpStringContext <1610743835> ( _      ' VTable offset = 136
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_TypeInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = _TypeLibInfo
' IID = {8B217745-717D-11CE-AB5B-D41203C10000}
' TypeLib information
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%TLI_TypeLibInfo_INTERFACE_DEFINED)
    %TLI_TypeLibInfo_INTERFACE_DEFINED = 1

INTERFACE TLI_TypeLibInfo $IID__TLI_TypeLibInfo

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out TypeLibInfo **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ContainingFile <1610743810> ( _         ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY SET ContainingFile <1610743810> ( _         ' VTable offset = 40
     BYVAL retVal AS WSTRING _                          ' __in retVal /* VT_BSTR */
   )                                                    ' void
   ' =====================================================================================
   METHOD LoadRegTypeLib <1610743812> ( _               ' VTable offset = 44
     BYVAL TypeLibGuid AS WSTRING _                     ' __in BSTR TypeLibGuid
   , BYVAL MajorVersion AS INTEGER _                    ' __in short MajorVersion
   , BYVAL MinorVersion AS INTEGER _                    ' __in short MinorVersion
   , BYVAL LCID AS LONG _                               ' __in long LCID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET OldHelpString_ <1610743814> ( _         ' VTable offset = 52
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET HelpContext <1610743815> ( _            ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   PROPERTY GET HelpFile <1610743816> ( _               ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET GUID <1610743817> ( _                   ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET LCID <1610743818> ( _                   ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   PROPERTY GET OldSysKind_ <1610743819> ( _            ' VTable offset = 72
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET MajorVersion <1610743820> ( _           ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET MinorVersion <1610743821> ( _           ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET AttributeMask <1610743822> ( _          ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET AttributeStrings <1610743823> ( _       ' VTable offset = 88
     BYREF IN AttributeArray AS DWORD _                 ' __out SAFEARRAY *AttributeArray
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET CoClasses <1610743824> ( _              ' VTable offset = 92
   ) AS TLI_CoClasses                                   ' __retval_out CoClasses **retVal
   ' =====================================================================================
   PROPERTY GET Interfaces <1610743825> ( _             ' VTable offset = 96
   ) AS TLI_Interfaces                                  ' __retval_out Interfaces **retVal
   ' =====================================================================================
   PROPERTY GET Constants <1610743826> ( _              ' VTable offset = 100
   ) AS TLI_Constants                                   ' __retval_out Constants **retVal
   ' =====================================================================================
   PROPERTY GET Declarations <1610743827> ( _           ' VTable offset = 104
   ) AS TLI_Declarations                                ' __retval_out Declarations **retVal
   ' =====================================================================================
   PROPERTY GET TypeInfoCount <1610743828> ( _          ' VTable offset = 108
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET OldGetTypeKind_ <1610743829> ( _        ' VTable offset = 112
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET TypeInfo <1610743830> ( _               ' VTable offset = 116
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   ) AS TLI_TypeInfo                                    ' __retval__out TypeInfo *retVal
   ' =====================================================================================
   PROPERTY GET GetTypeInfoNumber <1610743831> ( _      ' VTable offset = 120
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   METHOD IsSameLibrary <1610743832> ( _                ' VTable offset = 124
     BYVAL CheckLib AS IDispatch _                      ' __in TypeLibInfo *CheckLib
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retVal
   ' =====================================================================================
   METHOD OldResetSearchCriteria_ <1610743833> ( _      ' VTable offset = 128
   )                                                    ' void
   ' =====================================================================================
   METHOD OldGetTypesWithMember_ <1610743834> ( _       ' VTable offset = 132
   )                                                    ' void
   ' =====================================================================================
   METHOD OldGetMembersWithSubString_ <1610743835> ( _  ' VTable offset = 136
   )                                                    ' void
   ' =====================================================================================
   METHOD OldGetTypesWithSubString_ <1610743836> ( _    ' VTable offset = 140
   )                                                    ' void
   ' =====================================================================================
   METHOD OldCaseTypeName_ <1610743837> ( _             ' VTable offset = 144
   )                                                    ' void
   ' =====================================================================================
   METHOD OldCaseMemberName_ <1610743838> ( _           ' VTable offset = 148
   )                                                    ' void
   ' =====================================================================================
   METHOD OldFillTypesList_ <1610743839> ( _            ' VTable offset = 152
   )                                                    ' void
   ' =====================================================================================
   METHOD OldFillTypesCombo_ <1610743840> ( _           ' VTable offset = 156
   )                                                    ' void
   ' =====================================================================================
   METHOD OldFillMemberList_ <1610743841> ( _           ' VTable offset = 160
   )                                                    ' void
   ' =====================================================================================
   METHOD OldAddClassTypeToList_ <1610743842> ( _       ' VTable offset = 164
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET AppObjString <1610743843> ( _           ' VTable offset = 168
     BYVAL retVal AS WSTRING _                          ' __in BSTR retVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET LibNum <1610743844> ( _                 ' VTable offset = 172
     BYVAL retVal AS INTEGER _                          ' __in short retVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowLibName <1610743845> ( _            ' VTable offset = 176
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retVal
   ' =====================================================================================
   PROPERTY SET ShowLibName <1610743845> ( _            ' VTable offset = 180
     BYVAL retVal AS INTEGER _                          ' __in VARIANT_BOOL retVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_OldListBoxNotification_ <1610743847> ( _ ' VTable offset = 184
     BYVAL plbn AS TLI_ListBoxNotification _            ' __in *ListBoxNotification
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GetTypeKind <1610743848> ( _            ' VTable offset = 188
     BYVAL TypeInfoNumber AS INTEGER _                  ' __in short TypeInfoNumber
   ) AS LONG                                            ' __retval_out TypeKinds *retVal
   ' =====================================================================================
   PROPERTY GET SysKind <1610743849> ( _                ' VTable offset = 192
   ) AS LONG                                            ' __retval_out SysKinds *retVal
   ' =====================================================================================
   PROPERTY GET SearchDefault <1610743850> ( _          ' VTable offset = 196
   ) AS LONG                                            ' __retval_out TliSearchTypes *retVal
   ' =====================================================================================
   PROPERTY SET SearchDefault <1610743850> ( _          ' VTable offset = 200
     BYVAL LONG _                                       ' __in TliSearchTypes retVal
   )                                                    ' void
   ' =====================================================================================
   METHOD CaseTypeName <1610743852> ( _                 ' VTable offset = 204
     BYREF bstrName AS WSTRING _                        ' __in_out BSTR *bstrName
   , OPTIONAL BYVAL SearchType AS LONG _                ' __opt_in TliSearchTypes SearchType [default value = 4096]
   ) AS LONG                                            ' __retval_out TliSearchTypes *retVal
   ' =====================================================================================
   METHOD CaseMemberName <1610743853> ( _               ' VTable offset = 208
     BYREF bstrName AS WSTRING _                        ' __in_out BSTR *bstrName
   , OPTIONAL BYVAL SearchType AS LONG _                ' __opt_in TliSearchTypes SearchType [default value = 4096]
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retVal
   ' =====================================================================================
   METHOD ResetSearchCriteria <1610743854> ( _          ' VTable offset = 212
     OPTIONAL BYVAL TypeFilter AS LONG _                ' __opt_in TypeFlags TypeFilter [default value = 528]
   , OPTIONAL BYVAL IncludeEmptyTypes AS INTEGER _      ' __opt_in VARIANT_BOOL IncludeEmptyTypes [default value = 0]
   , OPTIONAL BYVAL ShowUnderscore AS INTEGER _         ' __opt_in VARIANT_BOOL ShowUnderscore [default value = 0]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTypesWithMember <1610743855> ( _           ' VTable offset = 216
     BYVAL MemberName AS WSTRING _                      ' __in BSTR MemberName
   , OPTIONAL BYREF StartResults AS TLI_SearchResults _ ' __opt_in_out SearchResults **StartResults [default value = 0]
   , OPTIONAL BYVAL SearchType AS LONG _                ' __opt_in TliSearchTypes SearchType [default value = 4096]
   , OPTIONAL BYVAL Sort AS INTEGER _                   ' __opt_in VARIANT_BOOL Sort [default value = -1]
   , OPTIONAL BYVAL ShowUnderscore AS INTEGER _         ' __opt_in VARIANT_BOOL ShowUnderscore [default value = 0]
   ) AS TLI_SearchResults                               ' __retval_out SearchResults **retVal
   ' =====================================================================================
   METHOD GetTypesWithMemberDirect <1610743856> ( _     ' VTable offset = 220
     BYVAL MemberName AS WSTRING _                      ' __in BSTR MemberName
   , BYVAL hWnd AS LONG _                               ' __in long hWnd
   , OPTIONAL BYVAL WindowType AS LONG _                ' __opt_in TliWindowTypes WindowType [default value = 0]
   , OPTIONAL BYVAL SearchType AS LONG _                ' __opt_in TliSearchTypes SearchType [default value = 4096]
   , OPTIONAL BYVAL ShowUnderscore AS INTEGER _         ' __opt_in VARIANT_BOOL ShowUnderscore [default value = 0]
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   METHOD GetMembersWithSubString <1610743857> ( _      ' VTable offset = 224
     BYVAL SubString AS WSTRING _                       ' __in BSTR SubString
   , OPTIONAL BYREF StartResults AS TLI_SearchResults _ ' __opt_in_out SearchResults **StartResults [default value = 0]
   , OPTIONAL BYVAL SearchType AS LONG _                ' __opt_in TliSearchTypes SearchType [default value = 4096]
   , OPTIONAL BYVAL SearchMiddle AS INTEGER _           ' __opt_in VARIANT_BOOL SearchMiddle [default value = -1]
   , OPTIONAL BYREF Helper AS IDispatch _               ' __opt_in_out SearchHelper **Helper [default value = 0]
   , OPTIONAL BYVAL Sort AS INTEGER _                   ' __opt_in VARIANT_BOOL Sort [default value = -1]
   , OPTIONAL BYVAL ShowUnderscore AS INTEGER _         ' __opt_in VARIANT_BOOL ShowUnderscore [default value = 0]
   ) AS TLI_SearchResults                               ' __retval_out SearchResults **retVal
   ' =====================================================================================
   METHOD GetMembersWithSubStringDirect <1610743858> ( _ ' VTable offset = 228
     BYVAL SubString AS WSTRING _                       ' __in BSTR SubString
   , BYVAL hWnd AS LONG _                               ' __in int hWnd
   , OPTIONAL BYVAL WindowType AS LONG _                ' __opt_in TliWindowTypes WindowType [default value = 0]
   , OPTIONAL BYVAL SearchType AS LONG _                ' __opt_in TliSearchTypes SearchType [default value = 4096]
   , OPTIONAL BYVAL SearchMiddle AS INTEGER _           ' __opt_in VARIANT_BOOL SearchMiddle [default value = -1]
   , OPTIONAL BYREF Helper AS IDispatch _               ' __opt_in_out SearchHelper **Helper [default value = 0]
   , OPTIONAL BYVAL ShowUnderscore AS INTEGER _         ' __opt_in VARIANT_BOOL ShowUnderscore [default value = 0]
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   METHOD GetTypesWithSubString <1610743859> ( _        ' VTable offset = 232
     BYVAL SubString AS WSTRING _                       ' __in BSTR SubString
   , OPTIONAL BYREF StartResults AS TLI_SearchResults _ ' __opt_in_out SearchResults **StartResults <dispinterface> */ [default value = 0]
   , OPTIONAL BYVAL SearchType AS LONG _                ' __opt_in TliSearchTypes SearchType [default value = 4096]
   , OPTIONAL BYVAL SearchMiddle AS INTEGER _           ' __opt_in VARIANT_BOOL SearchMiddle [default value = -1]
   , OPTIONAL BYVAL Sort AS INTEGER _                   ' __opt_in VARIANT_BOOL Sort [default value = -1]
   ) AS TLI_SearchResults                               ' __retval_out SearchResults **retVal
   ' =====================================================================================
   METHOD GetTypesWithSubStringDirect <1610743860> ( _  ' VTable offset = 236
     BYVAL SubString AS WSTRING _                       ' __in BSTR SubString
   , BYVAL hWnd AS LONG _                               ' __in int hWnd
   , OPTIONAL BYVAL WindowType AS LONG _                ' __opt_in TliWindowTypes WindowType [default value = 0]
   , OPTIONAL BYVAL SearchType AS LONG _                ' __opt_in TliSearchTypes SearchType [default value = 4096]
   , OPTIONAL BYVAL SearchMiddle AS INTEGER _           ' __opt_in VARIANT_BOOL SearchMiddle [default value = -1]
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   METHOD GetTypes <1610743861> ( _                     ' VTable offset = 240
     OPTIONAL BYREF StartResults AS TLI_SearchResults _ ' __opt_in_out SearchResults **StartResults [default value = 0]
   , OPTIONAL BYVAL SearchType AS LONG _                ' __opt_in TliSearchTypes SearchType [default value = 4096]
   , OPTIONAL BYVAL Sort AS INTEGER _                   ' __opt_in VARIANT_BOOL Sort [default value = -1]
   ) AS TLI_SearchResults                               ' __retval_out SearchResults **retVal
   ' =====================================================================================
   METHOD GetTypesDirect <1610743862> ( _               ' VTable offset = 244
     BYVAL hWnd AS LONG _                               ' __in int hWnd
   , OPTIONAL BYVAL WindowType AS LONG _                ' __opt_in TliWindowTypes WindowType [default value = 0]
   , OPTIONAL BYVAL SearchType AS LONG _                ' __opt_in TliSearchTypes SearchType [default value = 4096]
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   METHOD GetMembers <1610743863> ( _                   ' VTable offset = 248
     BYVAL SearchData AS LONG _                         ' __in long SearchData
   , OPTIONAL BYVAL ShowUnderscore AS INTEGER _         ' __opt_in VARIANT_BOOL ShowUnderscore [default value = 0]
   ) AS TLI_SearchResults                               ' __retval_out SearchResults **retVal
   ' =====================================================================================
   METHOD GetMembersDirect <1610743864> ( _             ' VTable offset = 252
     BYVAL SearchData AS LONG _                         ' __in long SearchData
   , BYVAL hWnd AS LONG _                               ' __in int hWnd
   , OPTIONAL BYVAL WindowType AS LONG _                ' __opt_in TliWindowTypes WindowType [default value = 0]
   , OPTIONAL BYVAL ItemDataType AS LONG _              ' __opt_in TliItemDataTypes ItemDataType [default value = 0]
   , OPTIONAL BYVAL ShowUnderscore AS INTEGER _         ' __opt_in VARIANT_BOOL ShowUnderscore [default value = 0]
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   METHOD SetMemberFilters <1610743865> ( _             ' VTable offset = 256
     OPTIONAL BYVAL FuncFilter AS LONG _                ' __opt_in FuncFlags FuncFilter [default value = 65]
   , OPTIONAL BYVAL VarFilter AS LONG _                 ' __opt_in VarFlags VarFilter [default value = 192]
   )                                                    ' void
   ' =====================================================================================
   METHOD MakeSearchData <1610743866> ( _               ' VTable offset = 260
     BYVAL TypeInfoName AS WSTRING _                    ' __in BSTR TypeInfoName
   , OPTIONAL BYVAL SearchType AS LONG _                ' __opt_in TliSearchTypes SearchType
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   PROPERTY GET TypeInfos <1610743867> ( _              ' VTable offset = 264
   ) AS TLI_TypeInfos                                   ' __retval_out TypeInfos **retVal
   ' =====================================================================================
   PROPERTY GET Records <1610743868> ( _                ' VTable offset = 268
   ) AS TLI_Records                                     ' __retval_out Records **retVal
   ' =====================================================================================
   PROPERTY GET IntrinsicAliases <1610743869> ( _       ' VTable offset = 272
   ) AS TLI_IntrinsicAliases                            ' __retval_out IntrinsicAliases **retVal
   ' =====================================================================================
   PROPERTY GET CustomDataCollection <1610743870> ( _   ' VTable offset = 276
   ) AS TLI_CustomDataCollection                        ' __retval_out CustomDataCollection **retVal
   ' =====================================================================================
   METHOD GetMemberInfo <1610743871> ( _                ' VTable offset = 280
     BYVAL SearchData AS LONG _                         ' __in long SearchData
   , OPTIONAL BYVAL InvokeKinds AS LONG _               ' __opt_in InvokeKinds InvokeKinds [default value = 0]
   , OPTIONAL BYVAL MemberId AS LONG _                  ' __opt_in long MemberId [default value = -1]
   , OPTIONAL BYVAL MemberName AS WSTRING _             ' __opt_in BSTR MemberName [default value = ""]
   ) AS TLI_MemberInfo                                  ' __retval_out MemberInfo **retVal
   ' =====================================================================================
   PROPERTY GET Unions <1610743872> ( _                 ' VTable offset = 284
   ) AS TLI_Unions                                      ' __retval_out Unions **retVal
   ' =====================================================================================
   METHOD AddTypes <1610743873> ( _                     ' VTable offset = 288
     BYREF TypeInfoNumbers AS DWORD _                   ' __in SAFEARRAY *TypeInfoNumbers
   , OPTIONAL BYREF StartResults AS TLI_SearchResults _ ' __opt_in_out SearchResults **StartResults [default value = 0]
   , OPTIONAL BYVAL SearchType AS LONG _                ' __opt_in TliSearchTypes SearchType [default value = 4096]
   , OPTIONAL BYVAL Sort AS INTEGER _                   ' __opt_in VARIANT_BOOL Sort [default value = -1]
   ) AS TLI_SearchResults                               ' __retval_out SearchResults
   ' =====================================================================================
   METHOD AddTypesDirect <1610743874> ( _               ' VTable offset = 292
     BYREF TypeInfoNumbers AS DWORD _                   ' __in SAFEARRAY *TypeInfoNumbers
   , BYVAL hWnd AS LONG _                               ' __in int hWnd
   , OPTIONAL BYVAL WindowType AS LONG _                ' __opt_in TliWindowTypes WindowType [default value = 0]
   , OPTIONAL BYVAL SearchType AS LONG _                ' __opt_in TliSearchTypes SearchType [default value = 4096]
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   METHOD FreeSearchCriteria <1610743875> ( _           ' VTable offset = 296
   )                                                    ' void
   ' =====================================================================================
   METHOD Register <1610743876> ( _                     ' VTable offset = 300
     OPTIONAL BYVAL HelpDir AS WSTRING _                ' __opt_in BSTR HelpDir [default value = ""]
   )                                                    ' void
   ' =====================================================================================
   METHOD UnRegister <1610743877> ( _                   ' VTable offset = 304
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HelpString <1610743878> ( _             ' VTable offset = 308
     OPTIONAL BYVAL LCID AS LONG _                      ' __opt_in long LCID [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET AppObjString <1610743843> ( _           ' VTable offset = 312
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET LibNum <1610743844> ( _                 ' VTable offset = 316
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   METHOD GetMembersWithSubStringEx <1610743881> ( _    ' VTable offset = 320
     BYVAL SubString AS WSTRING _                       ' __in BSTR SubString
   , BYREF InvokeGroupings AS DWORD _                   ' __in SAFEARRAY *InvokeGroupings
   , OPTIONAL BYREF StartResults AS TLI_SearchResults _ ' __opt_in_out SearchResults **StartResults [default value = 0]
   , OPTIONAL BYVAL SearchType AS LONG _                ' __opt_in TliSearchTypes SearchType [default value = 4096]
   , OPTIONAL BYVAL SearchMiddle AS INTEGER _           ' __opt_in VARIANT_BOOL SearchMiddle [default value = -1]
   , OPTIONAL BYVAL Sort AS INTEGER _                   ' __opt_in VARIANT_BOOL Sort [default value = -1]
   , OPTIONAL BYVAL ShowUnderscore AS INTEGER _         ' __opt_in VARIANT_BOOL ShowUnderscore [default value = 0]
   ) AS TLI_SearchResults                               ' __retval_out SearchResults **retVal
   ' =====================================================================================
   METHOD GetTypesWithMemberEx <1610743882> ( _         ' VTable offset = 324
     BYVAL MemberName AS WSTRING _                      ' __in BSTR MemberName
   , BYVAL InvokeKind AS LONG _                         ' __in InvokeKinds InvokeKind
   , OPTIONAL BYREF StartResults AS TLI_SearchResults _ ' __opt_in_out SearchResults **StartResults [default value = 0]
   , OPTIONAL BYVAL SearchType AS LONG _                ' __opt_in TliSearchTypes SearchType [default value = 4096]
   , OPTIONAL BYVAL Sort AS INTEGER _                   ' __opt_in VARIANT_BOOL Sort */ [default value = -1]
   , OPTIONAL BYVAL ShowUnderscore AS INTEGER _         ' __opt_in VARIANT_BOOL ShowUnderscore [default value = 0]
   ) AS TLI_SearchResults                               ' __retval_out SearchResults **retVal
   ' =====================================================================================
   PROPERTY GET ITypeLib <1610743883> ( _               ' VTable offset = 328
   ) AS IUnknown                                        ' __retval_out IUnknown **retVal
   ' =====================================================================================
   PROPERTY SET putref_ITypeLib <1610743883> ( _        ' VTable offset = 332
     BYVAL retVal AS IUnknown _                         ' __in IUnknown retVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HelpStringDll <1610743885> ( _          ' VTable offset = 336
     OPTIONAL BYVAL LCID AS LONG _                      ' __opt_in long LCID [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET HelpStringContext <1610743886> ( _      ' VTable offset = 340
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   PROPERTY GET BestEquivalentType <1610743887> ( _     ' VTable offset = 344
     BYVAL TypeInfoName AS WSTRING _                    ' __in BSTR TypeInfoName
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_TypeLibInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = SearchItem
' IID = {8B217756-717D-11CE-AB5B-D41203C10000}
' Item in SearchResults collection
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%TLI_SearchItem_INTERFACE_DEFINED)
    %TLI_SearchItem_INTERFACE_DEFINED = 1

INTERFACE TLI_SearchItem $IID_TLI_SearchItem

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS TLI_SearchItem                                  ' __retval_out SearchItem **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET SearchData <1610743811> ( _             ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   PROPERTY GET TypeInfoNumber <1610743812> ( _         ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET OldLibNum_ <1610743813> ( _             ' VTable offset = 48
   ) AS BYTE                                            ' __retval_out unsigned char *retVal
   ' =====================================================================================
   PROPERTY GET SearchType <1610743814> ( _             ' VTable offset = 52
   ) AS LONG                                            ' __retval_out TliSearchTypes *retVal
   ' =====================================================================================
   PROPERTY GET MemberId <1610743815> ( _               ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   PROPERTY GET InvokeKinds <1610743816> ( _            ' VTable offset = 60
   ) AS LONG                                            ' __retval_out InvokeKinds *retVal
   ' =====================================================================================
   PROPERTY GET NamePtrW <1610743817> ( _               ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   PROPERTY GET LibNum <1610743818> ( _                 ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET Constant <1610743819> ( _               ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retVal
   ' =====================================================================================
   PROPERTY GET Hidden <1610743820> ( _                 ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retVal
   ' =====================================================================================
   PROPERTY GET InvokeGroup <1610743821> ( _            ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_SearchItem_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = SearchResults
' IID = {8B217757-717D-11CE-AB5B-D41203C10000}
' SearchResults collection
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%TLI_SearchResults_INTERFACE_DEFINED)
    %TLI_SearchResults_INTERFACE_DEFINED = 1

INTERFACE TLI_SearchResults $IID_TLI_SearchResults

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS TLI_SearchResults                               ' __retval_out SearchResults **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **retVal
   ' =====================================================================================
   PROPERTY GET OldItem_ <1610743811> ( _               ' VTable offset = 40
     BYVAL Index AS INTEGER _                           ' __in short Index
   ) AS TLI_SearchItem                                  ' __retval_out SearchItem **retVal
   ' =====================================================================================
   PROPERTY GET OldCount_ <1610743812> ( _              ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET Sorted <1610743813> ( _                 ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retVal
   ' =====================================================================================
   METHOD Sort <1610743814> ( _                         ' VTable offset = 52
     OPTIONAL BYVAL CustomSort AS TLI_CustomSort _      ' __opt_in CustomSort *CustomSort [default value = 0]
   )                                                    ' void
   ' =====================================================================================
   METHOD Filter <1610743815> ( _                       ' VTable offset = 56
     BYVAL CustomFilter AS TLI_CustomFilter _           ' __in CustomFilter *CustomFilter
   , OPTIONAL BYREF AppendExtractedTo AS TLI_SearchResults _ ' __opt_in_out SearchResults **AppendExtractedTo [default value = 0]
   , OPTIONAL BYVAL StartAfter AS TLI_SearchItem _      ' __opt_in SearchItem *StartAfter [default value = 0]
   ) AS TLI_SearchResults                               ' __retval_out SearchResults **retVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 60
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS TLI_SearchItem                                  ' __retval_out SearchItem **retVal
   ' =====================================================================================
   PROPERTY GET Count <1610743817> ( _                  ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   METHOD LocateSorted <1610743818> ( _                 ' VTable offset = 68
     BYVAL CustomSort AS TLI_CustomSort _               ' __in CustomSort *CustomSort
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   METHOD Locate <1610743819> ( _                       ' VTable offset = 72
     OPTIONAL BYVAL SearchString AS WSTRING _           ' __opt_in BSTR SearchString [default value = ""]
   , OPTIONAL BYVAL CustomSort AS TLI_CustomSort _      ' __opt_in CustomSort *CustomSort [default value = 0]
   , OPTIONAL BYVAL StartAfter AS LONG _                ' __opt_in long StartAfter [default value = 0]
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_SearchResults_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ListBoxNotification
' IID = {8B217758-717D-11CE-AB5B-D41203C10000}
' ListBoxNotification interface, use with Implements and Direct methods
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%TLI_ListBoxNotification_INTERFACE_DEFINED)
    %TLI_ListBoxNotification_INTERFACE_DEFINED = 1

INTERFACE TLI_ListBoxNotification $IID_TLI_ListBoxNotification

   INHERIT IDispatch

   ' =====================================================================================
   METHOD OnAddString <1610743808> ( _                  ' VTable offset = 28
     BYVAL lpstr AS LONG _                              ' __in long lpstr
   , BYVAL fUnicode AS INTEGER _                        ' __in VARIANT_BOOL fUnicode
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_ListBoxNotification_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = CustomSort
' IID = {8B21775F-717D-11CE-AB5B-D41203C10000}
' Interface for custom sorting of a SearchResults collection, use with Implements
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%TLI_CustomSort_INTERFACE_DEFINED)
    %TLI_CustomSort_INTERFACE_DEFINED = 1

INTERFACE TLI_CustomSort $IID_TLI_CustomSort

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Compare <1610743808> ( _                      ' VTable offset = 28
     BYVAL Item1 AS TLI_SearchItem _                    ' __in SearchItem *Item1
   , BYVAL Item2 AS TLI_SearchItem _                    ' __in SearchItem *Item2
   , BYREF Compare AS LONG _                            ' __in_out long *Compare
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_CustomSort_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = CustomFilter
' IID = {8B217760-717D-11CE-AB5B-D41203C10000}
' Interface for modifying or splitting a SearchResults collection, use with Implements
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%TLI_CustomFilter_INTERFACE_DEFINED)
    %TLI_CustomFilter_INTERFACE_DEFINED = 1

INTERFACE TLI_CustomFilter $IID_TLI_CustomFilter

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Visit <1610743808> ( _                        ' VTable offset = 28
     BYVAL Item AS TLI_SearchItem _                     ' __in SearchItem *Item
   , BYREF Action AS LONG _                             ' __in_out TliCustomFilterAction *Action
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_CustomFilter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = _TLIApplication
' IID = {8B21775D-717D-11CE-AB5B-D41203C10000}
' TLIApplication object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%TLI_TLIApplication_INTERFACE_DEFINED)
    %TLI_TLIApplication_INTERFACE_DEFINED = 1

INTERFACE TLI_TLIApplication $IID__TLI_TLIApplication

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out TLIApplication **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD TypeLibInfoFromFile <1610743810> ( _          ' VTable offset = 36
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   ) AS IDispatch                                       ' __retval_out TypeLibInfo **retVal
   ' =====================================================================================
   METHOD InterfaceInfoFromObject <1610743811> ( _      ' VTable offset = 40
     BYVAL Object AS IDispatch _                        ' __in IDispatch Object
   ) AS TLI_InterfaceInfo                               ' __retval_out InterfaceInfo **retVal
   ' =====================================================================================
   PROPERTY GET ListBoxNotification <1610743812> ( _    ' VTable offset = 44
   ) AS TLI_ListBoxNotification                         ' __retval_out ListBoxNotification **retVal
   ' =====================================================================================
   PROPERTY SET putref_ListBoxNotification <1610743812> ( _ ' VTable offset = 48
     BYVAL retVal AS TLI_ListBoxNotification _          ' __in ListBoxNotification *retVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ResolveAliases <1610743814> ( _         ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *retVal
   ' =====================================================================================
   PROPERTY SET ResolveAliases <1610743814> ( _         ' VTable offset = 56
     BYVAL retVal AS INTEGER _                          ' __in VARIANT_BOOL retVal
   )                                                    ' void
   ' =====================================================================================
   METHOD InvokeHook <1610743816> ( _                   ' VTable offset = 60
     BYVAL Object AS IDispatch _                        ' __in IDispatch Object
   , BYVAL NameOrID AS VARIANT _                        ' __in VARIANT NameOrID
   , BYVAL InvokeKind AS LONG _                         ' __in InvokeKinds InvokeKind
   , BYREF ReverseArgList AS DWORD _                    ' __in SAFEARRAY *ReverseArgList
   ) AS VARIANT                                         ' __retval_out VARIANT *retVal
   ' =====================================================================================
   METHOD InvokeHookArray <1610743817> ( _              ' VTable offset = 64
     BYVAL Object AS IDispatch _                        ' __in IDispatch Object
   , BYVAL NameOrID AS VARIANT _                        ' __in VARIANT NameOrID
   , BYVAL InvokeKind AS LONG _                         ' __in InvokeKinds InvokeKind
   , BYREF ReverseArgList AS DWORD _                    ' __in SAFEARRAY *ReverseArgList
   ) AS VARIANT                                         ' __retval_out VARIANT *retVal
   ' =====================================================================================
   METHOD InvokeHookSub <1610743818> ( _                ' VTable offset = 68
     BYVAL Object AS IDispatch _                        ' __in IDispatch Object
   , BYVAL NameOrID AS VARIANT _                        ' __in VARIANT NameOrID
   , BYVAL InvokeKind AS LONG _                         ' __in InvokeKinds InvokeKind
   , BYREF ReverseArgList AS DWORD _                    ' __in SAFEARRAY *ReverseArgList
   )                                                    ' void
   ' =====================================================================================
   METHOD InvokeHookArraySub <1610743819> ( _           ' VTable offset = 72
     BYVAL Object AS IDispatch _                        ' __in IDispatch Object
   , BYVAL NameOrID AS VARIANT _                        ' __in VARIANT NameOrID
   , BYVAL InvokeKind AS LONG _                         ' __in InvokeKinds InvokeKind
   , BYREF ReverseArgList AS DWORD _                    ' __in SAFEARRAY *ReverseArgList
   )                                                    ' void
   ' =====================================================================================
   METHOD ClassInfoFromObject <1610743820> ( _          ' VTable offset = 76
     BYVAL Object AS IUnknown _                         ' __in IUnknown Object
   ) AS TLI_TypeInfo                                    ' __retval_out TypeInfo **retVal
   ' =====================================================================================
   METHOD InvokeID <1610743821> ( _                     ' VTable offset = 80
     BYVAL Object AS IDispatch _                        ' __in IDispatch Object
   , BYVAL Name AS WSTRING _                            ' __in BSTR Name
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   PROPERTY GET InvokeLCID <1610743822> ( _             ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   PROPERTY SET InvokeLCID <1610743822> ( _             ' VTable offset = 88
     BYVAL retVal AS LONG _                             ' __in long retVal
   )                                                    ' void
   ' =====================================================================================
   METHOD TypeInfoFromITypeInfo <1610743824> ( _        ' VTable offset = 92
     BYVAL ptinfo AS IUnknown _                         ' __in IUnknown ptinfo
   ) AS TLI_TypeInfo                                    ' __retval_out TypeInfo **retVal
   ' =====================================================================================
   METHOD TypeLibInfoFromITypeLib <1610743825> ( _      ' VTable offset = 96
     BYVAL pITypeLib AS IUnknown _                      ' __in IUnknown pITypeLib
   ) AS IDispatch                                       ' __retval_out TypeLibInfo **retVal
   ' =====================================================================================
   METHOD TypeLibInfoFromRegistry <1610743826> ( _      ' VTable offset = 100
     BYVAL TypeLibGuid AS WSTRING _                     ' __in BSTR TypeLibGuid
   , BYVAL MajorVersion AS INTEGER _                    ' __in short MajorVersion
   , BYVAL MinorVersion AS INTEGER _                    ' __in short MinorVersion
   , BYVAL LCID AS LONG _                               ' __in long LCID
   ) AS IDispatch                                       ' __retval_out TypeLibInfo **retVal
   ' =====================================================================================
   METHOD TypeInfoFromRecordVariant <1610743827> ( _    ' VTable offset = 104
     BYREF RecordVariant AS VARIANT _                   ' __in VARIANT *RecordVariant
   ) AS TLI_TypeInfo                                    ' __retval_out TypeInfo **retVal
   ' =====================================================================================
   PROPERTY GET RecordField <1610743828> ( _            ' VTable offset = 108
     BYREF IN RecordVariant AS VARIANT _                ' __in_out VARIANT *RecordVariant
   , BYREF IN FieldName AS WSTRING _                    ' __in BSTR *FieldName
   ) AS VARIANT                                         ' __retval_out VARIANT *retVal
   ' =====================================================================================
   PROPERTY SET RecordField <1610743828> ( _            ' VTable offset = 112
     BYREF IN RecordVariant AS VARIANT _                ' __in_out VARIANT *RecordVariant
   , BYREF IN FieldName AS WSTRING _                    ' __in BSTR *FieldName
   , BYREF IN retVal AS VARIANT _                       ' __in VARIANT *retVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_RecordField <1610743828> ( _     ' VTable offset = 116
     BYREF IN RecordVariant AS VARIANT _                ' __in_out VARIANT *RecordVariant
   , BYREF IN FieldName AS WSTRING _                    ' __in BSTR *FieldName
   , BYREF IN retVal AS VARIANT _                       ' __in VARIANT *retVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_TLIApplication_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = TypeInfos
' IID = {8B21775A-717D-11CE-AB5B-D41203C10000}
' TypeInfos Collection
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _BaseTypeInfos
' ########################################################################################

#IF NOT %DEF(%TLI_TypeInfos_INTERFACE_DEFINED)
    %TLI_TypeInfos_INTERFACE_DEFINED = 1

INTERFACE TLI_TypeInfos $IID_TLI_TypeInfos

   INHERIT IDispatch

   ' =====================================================================================
   ' _BaseTypeInfos Methods
   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS TLI_TypeInfos                                   ' __retval_out TypeInfos **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **retVal
   ' =====================================================================================
   PROPERTY GET Count <1610743811> ( _                  ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================

   ' =====================================================================================
   ' TypeInfos Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 44
     BYVAL Index AS INTEGER _                           ' __in short Index
   ) AS TLI_TypeInfo                                    ' __retval_out TypeInfo **retVal
   ' =====================================================================================
   PROPERTY GET IndexedItem <1610809345> ( _            ' VTable offset = 48
     BYVAL TypeInfoNumber AS INTEGER _                  ' __in short TypeInfoNumber
   ) AS TLI_TypeInfo                                    ' __retval_out TypeInfo **retVal
   ' =====================================================================================
   PROPERTY GET NamedItem <1610809346> ( _              ' VTable offset = 52
     BYREF IN TypeInfoName AS WSTRING _                 ' __in_out BSTR *TypeInfoName
   ) AS TLI_TypeInfo                                    ' __retval_out TypeInfo **retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_TypeInfos_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = RecordInfo
' IID = {8B21775B-717D-11CE-AB5B-D41203C10000}
' Members are a subset of TypeInfo object members.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ConstantInfo
' ########################################################################################

#IF NOT %DEF(%TLI_RecordInfo_INTERFACE_DEFINED)
    %TLI_RecordInfo_INTERFACE_DEFINED = 1

INTERFACE TLI_RecordInfo $IID_TLI_RecordInfo

   INHERIT IDispatch

   ' =====================================================================================
   ' ConstantInfo Methods
   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS TLI_TypeInfo                                    ' __retval_out TypeInfo **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET GUID <1610743811> ( _                   ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET OldHelpString_ <1610743812> ( _         ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET HelpContext <1610743813> ( _            ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   PROPERTY GET HelpFile <1610743814> ( _               ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET AttributeMask <1610743815> ( _          ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET AttributeStrings <1610743816> ( _       ' VTable offset = 60
     BYREF IN AttributeArray AS DWORD _                 ' __out SAFEARRAY *AttributeArray
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET OldTypeKind_ <1610743817> ( _           ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET TypeKindString <1610743818> ( _         ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET TypeInfoNumber <1610743819> ( _         ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   METHOD placeholder_VTableInterface_ <1610743820> ( _ ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GetMember <1610743821> ( _              ' VTable offset = 80
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS TLI_MemberInfo                                  ' __retval_out MemberInfo **retVal
   ' =====================================================================================
   PROPERTY GET Members <1610743822> ( _                ' VTable offset = 84
   ) AS TLI_Members                                     ' __retval_out Members **retVal
   ' =====================================================================================
   PROPERTY GET Parent <1610743823> ( _                 ' VTable offset = 88
   ) AS IDispatch                                       ' __retval_out TypeLibInfo **retVal
   ' =====================================================================================
   METHOD ImpliedInterfaces_ <1610743824> ( _           ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD DefaultInterface_ <1610743825> ( _            ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD DefaultEventInterface_ <1610743826> ( _       ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TypeKind <1610743827> ( _               ' VTable offset = 104
   ) AS LONG                                            ' __retval_out TypeKinds *retVal
   ' =====================================================================================
   PROPERTY GET ResolvedType <1610743828> ( _           ' VTable offset = 108
   ) AS TLI_VarTypeInfo                                 ' __retval_out VarTypeInfo **retVal
   ' =====================================================================================
   PROPERTY GET CustomDataCollection <1610743829> ( _   ' VTable offset = 112
   ) AS TLI_CustomDataCollection                        ' __retval_out CustomDataCollection **retVal
   ' =====================================================================================
   PROPERTY GET HelpString <1610743830> ( _             ' VTable offset = 116
     OPTIONAL BYVAL LCID AS LONG _                      ' __opt_in long LCID
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET ITypeInfo <1610743831> ( _              ' VTable offset = 120
   ) AS IUnknown                                        ' __retval_out IUnknown **retVal
   ' =====================================================================================
   PROPERTY GET MajorVersion <1610743832> ( _           ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET MinorVersion <1610743833> ( _           ' VTable offset = 128
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET HelpStringDll <1610743834> ( _          ' VTable offset = 132
     OPTIONAL BYVAL LCID AS LONG _                      ' __opt_in long LCID [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET HelpStringContext <1610743835> ( _      ' VTable offset = 136
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_RecordInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Records
' IID = {8B21775C-717D-11CE-AB5B-D41203C10000}
' Subset of TypeInfos collection.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _BaseTypeInfos
' ########################################################################################

#IF NOT %DEF(%TLI_Records_INTERFACE_DEFINED)
    %TLI_Records_INTERFACE_DEFINED = 1

INTERFACE TLI_Records $IID_TLI_Records

   INHERIT IDispatch

   ' =====================================================================================
   ' _BaseTypeInfos Methods
   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS TLI_TypeInfos                                   ' __retval_out TypeInfos **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **retVal
   ' =====================================================================================
   PROPERTY GET Count <1610743811> ( _                  ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================

   ' =====================================================================================
   ' Records Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 44
     BYVAL Index AS INTEGER _                           ' __in short Index
   ) AS TLI_RecordInfo                                  ' __retval_out RecordInfo **retVal
   ' =====================================================================================
   PROPERTY GET IndexedItem <1610809345> ( _            ' VTable offset = 48
     BYVAL TypeInfoNumber AS INTEGER _                  ' __in short TypeInfoNumber
   ) AS TLI_RecordInfo                                  ' __retval_out RecordInfo **retVal
   ' =====================================================================================
   PROPERTY GET NamedItem <1610809346> ( _              ' VTable offset = 52
     BYREF IN TypeInfoName AS WSTRING _                 ' __in_out BSTR *TypeInfoName
   ) AS TLI_RecordInfo                                  ' __retval_out RecordInfo **retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_Records_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IntrinsicAliasInfo
' IID = {8B217761-717D-11CE-AB5B-D41203C10000}
' Members are a subset of TypeInfo object members.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%TLI_IntrinsicAliasInfo_INTERFACE_DEFINED)
    %TLI_IntrinsicAliasInfo_INTERFACE_DEFINED = 1

INTERFACE TLI_IntrinsicAliasInfo $IID_TLI_IntrinsicAliasInfo

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS TLI_IntrinsicAliasInfo                          ' __retval_out IntrinsicAliasInfo **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET GUID <1610743811> ( _                   ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET OldHelpString_ <1610743812> ( _         ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET HelpContext <1610743813> ( _            ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   PROPERTY GET HelpFile <1610743814> ( _               ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET AttributeMask <1610743815> ( _          ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET AttributeStrings <1610743816> ( _       ' VTable offset = 60
     BYREF IN AttributeArray AS DWORD _                 ' __out SAFEARRAY *AttributeArray
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET OldTypeKind_ <1610743817> ( _           ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET TypeKindString <1610743818> ( _         ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET TypeInfoNumber <1610743819> ( _         ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   METHOD placeholder_VTableInterface_ <1610743820> ( _ ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================
   METHOD placeholder_GetMember_ <1610743821> ( _       ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   METHOD placeholder_Members_ <1610743822> ( _         ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Parent <1610743823> ( _                 ' VTable offset = 88
   ) AS IDispatch                                       ' __retval_out TypeLibInfo **retVal
   ' =====================================================================================
   METHOD ImpliedInterfaces_ <1610743824> ( _           ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD DefaultInterface_ <1610743825> ( _            ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD DefaultEventInterface_ <1610743826> ( _       ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TypeKind <1610743827> ( _               ' VTable offset = 104
   ) AS LONG                                            ' __retval_out TypeKinds *retVal
   ' =====================================================================================
   PROPERTY GET ResolvedType <1610743828> ( _           ' VTable offset = 108
   ) AS TLI_VarTypeInfo                                 ' __retval_out VarTypeInfo **retVal
   ' =====================================================================================
   PROPERTY GET CustomDataCollection <1610743829> ( _   ' VTable offset = 112
   ) AS TLI_CustomDataCollection                        ' __retval_out CustomDataCollection **retVal
   ' =====================================================================================
   PROPERTY GET HelpString <1610743830> ( _             ' VTable offset = 116
     OPTIONAL BYVAL LCID AS LONG _                      ' __opt_in long LCID [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET ITypeInfo <1610743831> ( _              ' VTable offset = 120
   ) AS IUnknown                                        ' __retval_out IUnknown **retVal
   ' =====================================================================================
   PROPERTY GET MajorVersion <1610743832> ( _           ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET MinorVersion <1610743833> ( _           ' VTable offset = 128
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET HelpStringDll <1610743834> ( _          ' VTable offset = 132
     OPTIONAL BYVAL LCID AS LONG _                      ' __opt_in long LCID [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET HelpStringContext <1610743835> ( _      ' VTable offset = 136
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_IntrinsicAliasInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IntrinsicAliases
' IID = {8B217762-717D-11CE-AB5B-D41203C10000}
' Subset of TypeInfos collection.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _BaseTypeInfos
' ########################################################################################

#IF NOT %DEF(%TLI_IntrinsicAliases_INTERFACE_DEFINED)
    %TLI_IntrinsicAliases_INTERFACE_DEFINED = 1

INTERFACE TLI_IntrinsicAliases $IID_TLI_IntrinsicAliases

   INHERIT IDispatch

   ' =====================================================================================
   ' _BaseTypeInfos Methods
   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS TLI_TypeInfos                                   ' __retval_out TypeInfos **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **retVal
   ' =====================================================================================
   PROPERTY GET Count <1610743811> ( _                  ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================

   ' =====================================================================================
   ' IntrinsicAliases Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 44
     BYVAL Index AS INTEGER _                           ' __in short Index
   ) AS TLI_IntrinsicAliasInfo                          ' __retval_out IntrinsicAliasInfo **retVal
   ' =====================================================================================
   PROPERTY GET IndexedItem <1610809345> ( _            ' VTable offset = 48
     BYVAL TypeInfoNumber AS INTEGER _                  ' __in short TypeInfoNumber
   ) AS TLI_IntrinsicAliasInfo                          ' __retval_out IntrinsicAliasInfo **retVal
   ' =====================================================================================
   PROPERTY GET NamedItem <1610809346> ( _              ' VTable offset = 52
     BYREF IN TypeInfoName AS WSTRING _                 ' __in_out BSTR *TypeInfoName
   ) AS TLI_IntrinsicAliasInfo                          ' __retval_out IntrinsicAliasInfo **retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_IntrinsicAliases_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = CustomData
' IID = {8B217763-717D-11CE-AB5B-D41203C10000}
' CustomData Object
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%TLI_CustomData_INTERFACE_DEFINED)
    %TLI_CustomData_INTERFACE_DEFINED = 1

INTERFACE TLI_CustomData $IID_TLI_CustomData

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS TLI_CustomData                                  ' __retval_out CustomData **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GUID <1610743810> ( _                   ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET Value <1610743811> ( _                  ' VTable offset = 40
   ) AS VARIANT                                         ' __retval_out VARIANT *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_CustomData_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = CustomDataCollection
' IID = {8B217764-717D-11CE-AB5B-D41203C10000}
' CustomData Collection
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%TLI_CustomDataCollection_INTERFACE_DEFINED)
    %TLI_CustomDataCollection_INTERFACE_DEFINED = 1

INTERFACE TLI_CustomDataCollection $IID_TLI_CustomDataCollection

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS TLI_CustomDataCollection                        ' __retval_out CustomDataCollection **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **retVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Index AS INTEGER _                           ' __in short Index
   ) AS TLI_CustomData                                  ' __retval_out CustomData **retVal
   ' =====================================================================================
   PROPERTY GET Count <1610743812> ( _                  ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_CustomDataCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = UnionInfo
' IID = {8B217765-717D-11CE-AB5B-D41203C10000}
' Members are a subset of TypeInfo object members.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ConstantInfo
' ########################################################################################

#IF NOT %DEF(%TLI_UnionInfo_INTERFACE_DEFINED)
    %TLI_UnionInfo_INTERFACE_DEFINED = 1

INTERFACE TLI_UnionInfo $IID_TLI_UnionInfo

   INHERIT IDispatch

   ' =====================================================================================
   ' ConstantInfo Methods
   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS TLI_TypeInfo                                    ' __retval_out TypeInfo **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET GUID <1610743811> ( _                   ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET OldHelpString_ <1610743812> ( _         ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET HelpContext <1610743813> ( _            ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================
   PROPERTY GET HelpFile <1610743814> ( _               ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET AttributeMask <1610743815> ( _          ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET AttributeStrings <1610743816> ( _       ' VTable offset = 60
     BYREF IN AttributeArray AS DWORD _                 ' __out SAFEARRAY *AttributeArray
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET OldTypeKind_ <1610743817> ( _           ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET TypeKindString <1610743818> ( _         ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET TypeInfoNumber <1610743819> ( _         ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   METHOD placeholder_VTableInterface_ <1610743820> ( _ ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GetMember <1610743821> ( _              ' VTable offset = 80
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS TLI_MemberInfo                                  ' __retval_out MemberInfo **retVal
   ' =====================================================================================
   PROPERTY GET Members <1610743822> ( _                ' VTable offset = 84
   ) AS TLI_Members                                     ' __retval_out Members **retVal
   ' =====================================================================================
   PROPERTY GET Parent <1610743823> ( _                 ' VTable offset = 88
   ) AS IDispatch                                       ' __retval_out TypeLibInfo **retVal
   ' =====================================================================================
   METHOD ImpliedInterfaces_ <1610743824> ( _           ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD DefaultInterface_ <1610743825> ( _            ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD DefaultEventInterface_ <1610743826> ( _       ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TypeKind <1610743827> ( _               ' VTable offset = 104
   ) AS LONG                                            ' __retval_out TypeKinds *retVal
   ' =====================================================================================
   PROPERTY GET ResolvedType <1610743828> ( _           ' VTable offset = 108
   ) AS TLI_VarTypeInfo                                 ' __retval_out VarTypeInfo **retVal
   ' =====================================================================================
   PROPERTY GET CustomDataCollection <1610743829> ( _   ' VTable offset = 112
   ) AS TLI_CustomDataCollection                        ' __retval_out CustomDataCollection **retVal
   ' =====================================================================================
   PROPERTY GET HelpString <1610743830> ( _             ' VTable offset = 116
     OPTIONAL BYVAL LCID AS LONG _                      ' __opt_in long LCID [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET ITypeInfo <1610743831> ( _              ' VTable offset = 120
   ) AS IUnknown                                        ' __retval_out IUnknown **retVal
   ' =====================================================================================
   PROPERTY GET MajorVersion <1610743832> ( _           ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET MinorVersion <1610743833> ( _           ' VTable offset = 128
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================
   PROPERTY GET HelpStringDll <1610743834> ( _          ' VTable offset = 132
     OPTIONAL BYVAL LCID AS LONG _                      ' __opt_in long LCID [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET HelpStringContext <1610743835> ( _      ' VTable offset = 136
   ) AS LONG                                            ' __retval_out long *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_UnionInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Unions
' IID = {8B217766-717D-11CE-AB5B-D41203C10000}
' Subset of TypeInfos collection.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _BaseTypeInfos
' ########################################################################################

#IF NOT %DEF(%TLI_Unions_INTERFACE_DEFINED)
    %TLI_Unions_INTERFACE_DEFINED = 1

INTERFACE TLI_Unions $IID_TLI_Unions

   INHERIT IDispatch

   ' =====================================================================================
   ' _BaseTypeInfos Methods
   ' =====================================================================================
   METHOD Me <1610743808> ( _                           ' VTable offset = 28
   ) AS TLI_TypeInfos                                   ' __retval_out TypeInfos **retVal
   ' =====================================================================================
   METHOD placeholder_destructor_ <1610743809> ( _      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **retVal
   ' =====================================================================================
   PROPERTY GET Count <1610743811> ( _                  ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out short *retVal
   ' =====================================================================================

   ' =====================================================================================
   ' Unions Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 44
     BYVAL Index AS INTEGER _                           ' __in short Index
   ) AS TLI_UnionInfo                                   ' __retval_out UnionInfo **retVal
   ' =====================================================================================
   PROPERTY GET IndexedItem <1610809345> ( _            ' VTable offset = 48
     BYVAL TypeInfoNumber AS INTEGER _                  ' __in short TypeInfoNumber
   ) AS TLI_UnionInfo                                   ' __retval_out UnionInfo **retVal
   ' =====================================================================================
   PROPERTY GET NamedItem <1610809346> ( _              ' VTable offset = 52
     BYREF IN TypeInfoName AS WSTRING _                 ' __in_out BSTR *TypeInfoName
   ) AS TLI_UnionInfo                                   ' __retval_out UnionInfo **retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __TLI_Unions_INTERFACE_DEFINED__ */
