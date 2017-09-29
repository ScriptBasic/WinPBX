' ########################################################################################
' Microsoft Windows
' File: RpcNsi.inc
' Contents: Types and function definitions to use the Name Service Independent APIs.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%RPCNSI_INC = 1

#INCLUDE ONCE "rpcdce.inc"

'typedef void * RPC_NS_HANDLE;

%RPC_C_NS_SYNTAX_DEFAULT     = 0
%RPC_C_NS_SYNTAX_DCE         = 3

%RPC_C_PROFILE_DEFAULT_ELT   = 0
%RPC_C_PROFILE_ALL_ELT       = 1
%RPC_C_PROFILE_ALL_ELTS      = %RPC_C_PROFILE_ALL_ELT
%RPC_C_PROFILE_MATCH_BY_IF   = 2
%RPC_C_PROFILE_MATCH_BY_MBR  = 3
%RPC_C_PROFILE_MATCH_BY_BOTH = 4

%RPC_C_NS_DEFAULT_EXP_AGE    = -1

'/* Server APIs */

DECLARE FUNCTION RpcNsBindingExportA IMPORT "RPCNS4.DLL" ALIAS "RpcNsBindingExportA" ( _
   BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYREF EntryName AS ASCIIZ _                          ' __in_opt RPC_CSTR EntryName
 , BYVAL IfSpec AS DWORD _                              ' __in_opt RPC_IF_HANDLE IfSpec
 , BYREF BindingVec AS RPC_BINDING_VECTOR _             ' __in_opt RPC_BINDING_VECTOR *BindingVec
 , BYREF ObjectUuidVec AS UUID_VECTOR _                 ' __in_opt UUID_VECTOR *ObjectUuidVec
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsBindingExportW IMPORT "RPCNS4.DLL" ALIAS "RpcNsBindingExportW" ( _
   BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYVAL EntryName AS DWORD _                           ' __in_opt RPC_CSTR EntryName
 , BYVAL IfSpec AS DWORD _                              ' __in_opt RPC_IF_HANDLE IfSpec
 , BYREF BindingVec AS RPC_BINDING_VECTOR _             ' __in_opt RPC_BINDING_VECTOR *BindingVec
 , BYREF ObjectUuidVec AS UUID_VECTOR _                 ' __in_opt UUID_VECTOR *ObjectUuidVec
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcNsBindingExport = RpcNsBindingExportW
#ELSE
   MACRO RpcNsBindingExport = RpcNsBindingExportA
#ENDIF

DECLARE FUNCTION RpcNsBindingUnexportA IMPORT "RPCNS4.DLL" ALIAS "RpcNsBindingUnexportA" ( _
   BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYREF EntryName AS ASCIIZ _                          ' __in_opt RPC_CSTR EntryName
 , BYVAL IfSpec AS DWORD _                              ' __in_opt RPC_IF_HANDLE IfSpec
 , BYREF ObjectUuidVec AS UUID_VECTOR _                 ' __in_opt UUID_VECTOR *ObjectUuidVec
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsBindingUnexportW IMPORT "RPCNS4.DLL" ALIAS "RpcNsBindingUnexportW" ( _
   BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYVAL EntryName AS DWORD _                           ' __in_opt RPC_CSTR EntryName
 , BYVAL IfSpec AS DWORD _                              ' __in_opt RPC_IF_HANDLE IfSpec
 , BYREF ObjectUuidVec AS UUID_VECTOR _                 ' __in_opt UUID_VECTOR *ObjectUuidVec
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcNsBindingUnexport = RpcNsBindingUnexportW
#ELSE
   MACRO RpcNsBindingUnexport = RpcNsBindingUnexportA
#ENDIF

'/* Server PnP APIs */

DECLARE FUNCTION RpcNsBindingExportPnPA IMPORT "RPCNS4.DLL" ALIAS "RpcNsBindingExportPnPA" ( _
   BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYREF EntryName AS ASCIIZ _                          ' __in_opt RPC_CSTR EntryName
 , BYVAL IfSpec AS DWORD _                              ' __in_opt RPC_IF_HANDLE IfSpec
 , BYREF ObjectVector AS UUID_VECTOR _                  ' __in_opt UUID_VECTOR *ObjectVector
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsBindingExportPnPW IMPORT "RPCNS4.DLL" ALIAS "RpcNsBindingExportPnPW" ( _
   BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYREF EntryName AS WSTRINGZ _                        ' __in_opt RPC_WSTR EntryName
 , BYVAL IfSpec AS DWORD _                              ' __in_opt RPC_IF_HANDLE IfSpec
 , BYREF ObjectVector AS UUID_VECTOR _                  ' __in_opt UUID_VECTOR *ObjectVector
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcNsBindingExportPnP = RpcNsBindingExportPnPW
#ELSE
   MACRO RpcNsBindingExportPnP = RpcNsBindingExportPnPA
#ENDIF

DECLARE FUNCTION RpcNsBindingUnexportPnPA IMPORT "RPCNS4.DLL" ALIAS "RpcNsBindingUnexportPnPA" ( _
   BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYREF EntryName AS ASCIIZ _                          ' __in_opt RPC_CSTR EntryName
 , BYVAL IfSpec AS DWORD _                              ' __in_opt RPC_IF_HANDLE IfSpec
 , BYREF ObjectVector AS UUID_VECTOR _                  ' __in_opt UUID_VECTOR *ObjectVector
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsBindingUnexportPnPW IMPORT "RPCNS4.DLL" ALIAS "RpcNsBindingUnexportPnPW" ( _
   BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYREF EntryName AS WSTRINGZ _                        ' __in_opt RPC_WSTR EntryName
 , BYVAL IfSpec AS DWORD _                              ' __in_opt RPC_IF_HANDLE IfSpec
 , BYREF ObjectVector AS UUID_VECTOR _                  ' __in_opt UUID_VECTOR *ObjectVector
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcNsBindingUnexportPnP = RpcNsBindingUnexportPnPW
#ELSE
   MACRO RpcNsBindingUnexportPnP = RpcNsBindingUnexportPnPA
#ENDIF

'/* Client APIs */

DECLARE FUNCTION RpcNsBindingLookupBeginA IMPORT "RPCNS4.DLL" ALIAS "RpcNsBindingLookupBeginA" ( _
   BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYREF EntryName AS ASCIIZ _                          ' __in_opt RPC_CSTR EntryName
 , BYVAL IfSpec AS DWORD _                              ' __in_opt RPC_IF_HANDLE IfSpec
 , BYREF ObjUuid AS GUID _                              ' __in_opt UUID *ObjUuid
 , BYVAL BindingMaxCount AS DWORD _                     ' __in unsigned long BindingMaxCount
 , BYREF LookupContext AS DWORD _                       ' __out RPC_NS_HANDLE *LookupContext
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsBindingLookupBeginW IMPORT "RPCNS4.DLL" ALIAS "RpcNsBindingLookupBeginW" ( _
   BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYREF EntryName AS WSTRINGZ _                        ' __in_opt RPC_WSTR EntryName
 , BYVAL IfSpec AS DWORD _                              ' __in_opt RPC_IF_HANDLE IfSpec
 , BYREF ObjUuid AS GUID _                              ' __in_opt UUID *ObjUuid
 , BYVAL BindingMaxCount AS DWORD _                     ' __in unsigned long BindingMaxCount
 , BYREF LookupContext AS DWORD _                       ' __out RPC_NS_HANDLE *LookupContext
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcNsBindingLookupBegin = RpcNsBindingLookupBeginW
#ELSE
   MACRO RpcNsBindingLookupBegin = RpcNsBindingLookupBeginA
#ENDIF

DECLARE FUNCTION RpcNsBindingLookupNext IMPORT "RPCNS4.DLL" ALIAS "RpcNsBindingLookupNext" ( _
   BYVAL LookupContext AS DWORD _                       ' __in  RPC_NS_HANDLE LookupContext
 , BYREF BindingVec AS RPC_BINDING_VECTOR _             ' __out RPC_BINDING_VECTOR * * BindingVec
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsBindingLookupDone IMPORT "RPCNS4.DLL" ALIAS "RpcNsBindingLookupDone" ( _
   BYREF LookupContext AS DWORD _                       ' __inout RPC_NS_HANDLE * LookupContext
 ) AS LONG                                              ' RPC_STATUS

'/* Group APIs */

DECLARE FUNCTION RpcNsGroupDeleteA IMPORT "RPCNS4.DLL" ALIAS "RpcNsGroupDeleteA" ( _
   BYVAL GroupNameSyntax AS DWORD _                     ' __in unsigned long GroupNameSyntax
 , BYREF GroupName AS ASCIIZ _                          ' __in_opt RPC_CSTR GroupName
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsGroupDeleteW IMPORT "RPCNS4.DLL" ALIAS "RpcNsGroupDeleteW" ( _
   BYVAL GroupNameSyntax AS DWORD _                     ' __in unsigned long GroupNameSyntax
 , BYREF GroupName AS WSTRINGZ _                        ' __in_opt RPC_WSTR GroupName
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcNsGroupDelete = RpcNsGroupDeleteW
#ELSE
   MACRO RpcNsGroupDelete = RpcNsGroupDeleteA
#ENDIF

DECLARE FUNCTION RpcNsGroupMbrAddA IMPORT "RPCNS4.DLL" ALIAS "RpcNsGroupMbrAddA" ( _
   BYVAL GroupNameSyntax AS DWORD _                     ' __in unsigned long GroupNameSyntax
 , BYREF GroupName AS ASCIIZ _                          ' __in RPC_CSTR GroupName
 , BYVAL MemberNameSyntax AS DWORD _                    ' __in unsigned long MemberNameSyntax
 , BYREF MemberName AS ASCIIZ _                         ' __in RPC_CSTR MemberName
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsGroupMbrAddW IMPORT "RPCNS4.DLL" ALIAS "RpcNsGroupMbrAddW" ( _
   BYVAL GroupNameSyntax AS DWORD _                     ' __in unsigned long GroupNameSyntax
 , BYREF GroupName AS WSTRINGZ _                        ' __in RPC_WSTR GroupName
 , BYVAL MemberNameSyntax AS DWORD _                    ' __in unsigned long MemberNameSyntax
 , BYREF MemberName AS ASCIIZ _                         ' __in RPC_CSTR MemberName
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcNsGroupMbrAdd = RpcNsGroupMbrAddW
#ELSE
   MACRO RpcNsGroupMbrAdd = RpcNsGroupMbrAddA
#ENDIF

DECLARE FUNCTION RpcNsGroupMbrRemoveA IMPORT "RPCNS4.DLL" ALIAS "RpcNsGroupMbrRemoveA" ( _
   BYVAL GroupNameSyntax AS DWORD _                     ' __in unsigned long GroupNameSyntax
 , BYREF GroupName AS ASCIIZ _                          ' __in RPC_CSTR GroupName
 , BYVAL MemberNameSyntax AS DWORD _                    ' __in unsigned long MemberNameSyntax
 , BYREF MemberName AS ASCIIZ _                         ' __in RPC_CSTR MemberName
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsGroupMbrRemoveW IMPORT "RPCNS4.DLL" ALIAS "RpcNsGroupMbrRemoveW" ( _
   BYVAL GroupNameSyntax AS DWORD _                     ' __in unsigned long GroupNameSyntax
 , BYREF GroupName AS WSTRINGZ _                        ' __in RPC_WSTR GroupName
 , BYVAL MemberNameSyntax AS DWORD _                    ' __in unsigned long MemberNameSyntax
 , BYVAL MemberName AS DWORD _                          ' __in RPC_CSTR MemberName
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcNsGroupMbrRemove = RpcNsGroupMbrRemoveW
#ELSE
   MACRO RpcNsGroupMbrRemove = RpcNsGroupMbrRemoveA
#ENDIF

DECLARE FUNCTION RpcNsGroupMbrInqBeginA IMPORT "RPCNS4.DLL" ALIAS "RpcNsGroupMbrInqBeginA" ( _
   BYVAL GroupNameSyntax AS DWORD _                     ' __in unsigned long GroupNameSyntax
 , BYREF GroupName AS ASCIIZ _                          ' __in RPC_CSTR GroupName
 , BYVAL MemberNameSyntax AS DWORD _                    ' __in unsigned long MemberNameSyntax
 , BYREF InquiryContext AS DWORD _                      ' __out RPC_NS_HANDLE *InquiryContext
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsGroupMbrInqBeginW IMPORT "RPCNS4.DLL" ALIAS "RpcNsGroupMbrInqBeginW" ( _
   BYVAL GroupNameSyntax AS DWORD _                     ' __in unsigned long GroupNameSyntax
 , BYREF GroupName AS WSTRINGZ _                        ' __in RPC_WSTR GroupName
 , BYVAL MemberNameSyntax AS DWORD _                    ' __in unsigned long MemberNameSyntax
 , BYREF InquiryContext AS DWORD _                      ' __out RPC_NS_HANDLE *InquiryContext
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcNsGroupMbrInqBegin = RpcNsGroupMbrInqBeginW
#ELSE
   MACRO RpcNsGroupMbrInqBegin = RpcNsGroupMbrInqBeginA
#ENDIF

DECLARE FUNCTION RpcNsGroupMbrInqNextA IMPORT "RPCNS4.DLL" ALIAS "RpcNsGroupMbrInqNextA" ( _
   BYREF InquiryContext AS DWORD _                      ' __inout RPC_NS_HANDLE InquiryContext
 , BYREF MemberName AS DWORD _                          ' __out RPC_CSTR *MemberName
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsGroupMbrInqNextW IMPORT "RPCNS4.DLL" ALIAS "RpcNsGroupMbrInqNextW" ( _
   BYREF InquiryContext AS DWORD _                      ' __inout RPC_NS_HANDLE InquiryContext
 , BYREF MemberName AS DWORD _                          ' __out RPC_WSTR *MemberName
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcNsGroupMbrInqNext = RpcNsGroupMbrInqNextW
#ELSE
   MACRO RpcNsGroupMbrInqNext = RpcNsGroupMbrInqNextA
#ENDIF

DECLARE FUNCTION RpcNsGroupMbrInqDone IMPORT "RPCNS4.DLL" ALIAS "RpcNsGroupMbrInqDone" ( _
   BYREF InquiryContext AS DWORD _                      ' __inout RPC_NS_HANDLE * InquiryContext
 ) AS LONG                                              ' RPC_STATUS

'/* Profile APIs */

DECLARE FUNCTION RpcNsProfileDeleteA IMPORT "RPCNS4.DLL" ALIAS "RpcNsProfileDeleteA" ( _
   BYVAL ProfileNameSyntax AS DWORD _                   ' __in unsigned long ProfileNameSyntax
 , BYREF ProfileName AS ASCIIZ _                        ' __in RPC_CSTR ProfileName
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsProfileDeleteW IMPORT "RPCNS4.DLL" ALIAS "RpcNsProfileDeleteW" ( _
   BYVAL ProfileNameSyntax AS DWORD _                   ' __in unsigned long ProfileNameSyntax
 , BYREF ProfileName AS WSTRINGZ _                      ' __in RPC_WSTR ProfileName
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcNsProfileDelete = RpcNsProfileDeleteW
#ELSE
   MACRO RpcNsProfileDelete = RpcNsProfileDeleteA
#ENDIF

DECLARE FUNCTION RpcNsProfileEltAddA IMPORT "RPCNS4.DLL" ALIAS "RpcNsProfileEltAddA" ( _
   BYVAL ProfileNameSyntax AS DWORD _                   ' __in unsigned long ProfileNameSyntax
 , BYREF ProfileName AS ASCIIZ _                        ' __in RPC_CSTR ProfileName
 , BYVAL IfId AS DWORD _                                ' __in_opt RPC_IF_ID *IfId
 , BYVAL MemberNameSyntax AS DWORD _                    ' __in unsigned long MemberNameSyntax
 , BYREF MemberName AS ASCIIZ _                         ' __in RPC_CSTR MemberName
 , BYVAL Priority AS DWORD _                            ' __in unsigned long Priority
 , BYREF Annotation AS ASCIIZ _                         ' __in_opt RPC_CSTR Annotation
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsProfileEltAddW IMPORT "RPCNS4.DLL" ALIAS "RpcNsProfileEltAddW" ( _
   BYVAL ProfileNameSyntax AS DWORD _                   ' __in unsigned long ProfileNameSyntax
 , BYREF ProfileName AS WSTRINGZ _                      ' __in RPC_WSTR ProfileName
 , BYVAL IfId AS DWORD _                                ' __in_opt RPC_IF_ID *IfId
 , BYVAL MemberNameSyntax AS DWORD _                    ' __in unsigned long MemberNameSyntax
 , BYREF MemberName AS WSTRINGZ _                       ' __in RPC_WSTR MemberName
 , BYVAL Priority AS DWORD _                            ' __in unsigned long Priority
 , BYREF Annotation AS WSTRINGZ _                       ' __in_opt RPC_WSTR Annotation
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcNsProfileEltAdd = RpcNsProfileEltAddW
#ELSE
   MACRO RpcNsProfileEltAdd = RpcNsProfileEltAddA
#ENDIF

DECLARE FUNCTION RpcNsProfileEltRemoveA IMPORT "RPCNS4.DLL" ALIAS "RpcNsProfileEltRemoveA" ( _
   BYVAL ProfileNameSyntax AS DWORD _                   ' __in unsigned long ProfileNameSyntax
 , BYREF ProfileName AS ASCIIZ _                        ' __in RPC_CSTR ProfileName
 , BYVAL IfId AS DWORD _                                ' __in_opt RPC_IF_ID *IfId
 , BYVAL MemberNameSyntax AS DWORD _                    ' __in unsigned long MemberNameSyntax
 , BYREF MemberName AS ASCIIZ _                         ' __in RPC_CSTR MemberName
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsProfileEltRemoveW IMPORT "RPCNS4.DLL" ALIAS "RpcNsProfileEltRemoveW" ( _
   BYVAL ProfileNameSyntax AS DWORD _                   ' __in unsigned long ProfileNameSyntax
 , BYREF ProfileName AS WSTRINGZ _                      ' __in RPC_WSTR ProfileName
 , BYVAL IfId AS DWORD _                                ' __in_opt RPC_IF_ID *IfId
 , BYVAL MemberNameSyntax AS DWORD _                    ' __in unsigned long MemberNameSyntax
 , BYREF MemberName AS WSTRINGZ _                       ' __in RPC_WSTR MemberName
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcNsProfileEltRemove = RpcNsProfileEltRemoveW
#ELSE
   MACRO RpcNsProfileEltRemove = RpcNsProfileEltRemoveA
#ENDIF

DECLARE FUNCTION RpcNsProfileEltInqBeginA IMPORT "RPCNS4.DLL" ALIAS "RpcNsProfileEltInqBeginA" ( _
   BYVAL ProfileNameSyntax AS DWORD _                   ' __in unsigned long ProfileNameSyntax
 , BYREF ProfileName AS ASCIIZ _                        ' __in RPC_CSTR ProfileName
 , BYVAL InquiryType AS DWORD _                         ' __in unsigned long InquiryType
 , BYVAL IfId AS DWORD _                                ' __in_opt RPC_IF_ID *IfId
 , BYVAL VersOption AS DWORD _                          ' __in unsigned long VersOption
 , BYVAL MemberNameSyntax AS DWORD _                    ' __in unsigned long MemberNameSyntax
 , BYREF MemberName AS ASCIIZ _                         ' __in_opt RPC_CSTR MemberName
 , BYREF InquiryContext AS DWORD _                      ' __out RPC_NS_HANDLE *InquiryContext
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsProfileEltInqBeginW IMPORT "RPCNS4.DLL" ALIAS "RpcNsProfileEltInqBeginW" ( _
   BYVAL ProfileNameSyntax AS DWORD _                   ' __in unsigned long ProfileNameSyntax
 , BYREF ProfileName AS WSTRINGZ _                      ' __in RPC_WSTR ProfileName
 , BYVAL InquiryType AS DWORD _                         ' __in unsigned long InquiryType
 , BYVAL IfId AS DWORD _                                ' __in_opt RPC_IF_ID *IfId
 , BYVAL VersOption AS DWORD _                          ' __in unsigned long VersOption
 , BYVAL MemberNameSyntax AS DWORD _                    ' __in unsigned long MemberNameSyntax
 , BYREF MemberName AS WSTRINGZ _                       ' __in_opt RPC_WSTR MemberName
 , BYREF InquiryContext AS DWORD _                      ' __out RPC_NS_HANDLE *InquiryContext
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcNsProfileEltInqBegin = RpcNsProfileEltInqBeginW
#ELSE
   MACRO RpcNsProfileEltInqBegin = RpcNsProfileEltInqBeginA
#ENDIF

DECLARE FUNCTION RpcNsProfileEltInqNextA IMPORT "RPCNS4.DLL" ALIAS "RpcNsProfileEltInqNextA" ( _
   BYVAL InquiryContext AS DWORD _                      ' __in RPC_NS_HANDLE InquiryContext
 , BYREF IfId AS DWORD _                                ' __out_opt RPC_IF_ID *IfId
 , BYREF MemberName AS DWORD _                          ' __out RPC_CSTR *MemberName
 , BYREF Priority AS DWORD _                            ' __out unsigned long *Priority
 , BYREF Annotation AS DWORD _                          ' __out RPC_CSTR *Annotation
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsProfileEltInqNextW IMPORT "RPCNS4.DLL" ALIAS "RpcNsProfileEltInqNextW" ( _
   BYVAL InquiryContext AS DWORD _                      ' __in RPC_NS_HANDLE InquiryContext
 , BYREF IfId AS DWORD _                                ' __out_opt RPC_IF_ID *IfId
 , BYREF MemberName AS DWORD _                          ' __out RPC_WSTR *MemberName
 , BYREF Priority AS DWORD _                            ' __out unsigned long *Priority
 , BYREF Annotation AS DWORD _                          ' __out RPC_WSTR *Annotation
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcNsProfileEltInqNext = RpcNsProfileEltInqNextW
#ELSE
   MACRO RpcNsProfileEltInqNext = RpcNsProfileEltInqNextA
#ENDIF

DECLARE FUNCTION RpcNsProfileEltInqDone IMPORT "RPCNS4.DLL" ALIAS "RpcNsProfileEltInqDone" ( _
   BYREF InquiryContext AS DWORD _                      ' __inout RPC_NS_HANDLE * InquiryContext
 ) AS LONG                                              ' RPC_STATUS

'/* Entry object APIs */

DECLARE FUNCTION RpcNsEntryObjectInqBeginA IMPORT "RPCNS4.DLL" ALIAS "RpcNsEntryObjectInqBeginA" ( _
   BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYREF EntryName AS ASCIIZ _                          ' __in RPC_CSTR EntryName
 , BYREF InquiryContext AS DWORD _                      ' __out RPC_NS_HANDLE *InquiryContext
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsEntryObjectInqBeginW IMPORT "RPCNS4.DLL" ALIAS "RpcNsEntryObjectInqBeginW" ( _
   BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYVAL EntryName AS DWORD _                           ' __in RPC_CSTR EntryName
 , BYREF InquiryContext AS DWORD _                      ' __out RPC_NS_HANDLE *InquiryContext
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcNsEntryObjectInqBegin = RpcNsEntryObjectInqBeginW
#ELSE
   MACRO RpcNsEntryObjectInqBegin = RpcNsEntryObjectInqBeginA
#ENDIF

DECLARE FUNCTION RpcNsEntryObjectInqNext IMPORT "RPCNS4.DLL" ALIAS "RpcNsEntryObjectInqNext" ( _
   BYVAL InquiryContext AS DWORD _                      ' __in  RPC_NS_HANDLE InquiryContext
 , BYREF ObjUuid AS GUID _                              ' __out UUID * ObjUuid
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsEntryObjectInqDone IMPORT "RPCNS4.DLL" ALIAS "RpcNsEntryObjectInqDone" ( _
   BYREF InquiryContext AS DWORD _                      ' IN OUT RPC_NS_HANDLE * InquiryContext
 ) AS LONG                                              ' RPC_STATUS

'/* Management and MISC APIs */

DECLARE FUNCTION RpcNsEntryExpandNameA IMPORT "RPCNS4.DLL" ALIAS "RpcNsEntryExpandNameA" ( _
   BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYREF EntryName AS ASCIIZ _                          ' __in RPC_CSTR EntryName
 , BYREF ExpandedName AS DWORD _                        ' __out RPC_CSTR *ExpandedName
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsEntryExpandNameW IMPORT "RPCNS4.DLL" ALIAS "RpcNsEntryExpandNameW" ( _
   BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYREF EntryName AS WSTRINGZ _                        ' __in RPC_WSTR EntryName
 , BYREF ExpandedName AS DWORD _                        ' __out RPC_WSTR *ExpandedName
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcNsEntryExpandName = RpcNsEntryExpandNameW
#ELSE
   MACRO RpcNsEntryExpandName = RpcNsEntryExpandNameA
#ENDIF

DECLARE FUNCTION RpcNsMgmtBindingUnexportA IMPORT "RPCNS4.DLL" ALIAS "RpcNsMgmtBindingUnexportA" ( _
   BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYREF EntryName AS ASCIIZ _                          ' __in RPC_CSTR EntryName
 , BYVAL IfId AS DWORD _                                ' __in_opt RPC_IF_ID *IfId
 , BYVAL VersOption AS DWORD _                          ' __in unsigned long VersOption
 , BYREF ObjectUuidVec AS UUID_VECTOR _                 ' __in_opt UUID_VECTOR *ObjectUuidVec
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsMgmtBindingUnexportW IMPORT "RPCNS4.DLL" ALIAS "RpcNsMgmtBindingUnexportW" ( _
   BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYREF EntryName AS WSTRINGZ _                        ' __in RPC_WSTR EntryName
 , BYVAL IfId AS DWORD _                                ' __in_opt RPC_IF_ID *IfId
 , BYVAL VersOption AS DWORD _                          ' __in unsigned long VersOption
 , BYREF ObjectUuidVec AS UUID_VECTOR _                 ' __in_opt UUID_VECTOR *ObjectUuidVec
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcNsMgmtBindingUnexport = RpcNsMgmtBindingUnexportW
#ELSE
   MACRO RpcNsMgmtBindingUnexport = RpcNsMgmtBindingUnexportA
#ENDIF

DECLARE FUNCTION RpcNsMgmtEntryCreateA IMPORT "RPCNS4.DLL" ALIAS "RpcNsMgmtEntryCreateA" ( _
   BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYREF EntryName AS ASCIIZ _                          ' __in RPC_CSTR EntryName
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsMgmtEntryCreateW IMPORT "RPCNS4.DLL" ALIAS "RpcNsMgmtEntryCreateW" ( _
   BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYREF EntryName AS WSTRINGZ _                        ' __in RPC_WSTR EntryName
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcNsMgmtEntryCreate = RpcNsMgmtEntryCreateW
#ELSE
   MACRO RpcNsMgmtEntryCreate = RpcNsMgmtEntryCreateA
#ENDIF

DECLARE FUNCTION RpcNsMgmtEntryDeleteA IMPORT "RPCNS4.DLL" ALIAS "RpcNsMgmtEntryDeleteA" ( _
   BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYREF EntryName AS ASCIIZ _                          ' __in RPC_CSTR EntryName
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsMgmtEntryDeleteW IMPORT "RPCNS4.DLL" ALIAS "RpcNsMgmtEntryDeleteW" ( _
   BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYREF EntryName AS WSTRINGZ _                        ' __in RPC_WSTR EntryName
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcNsMgmtEntryDelete = RpcNsMgmtEntryDeleteW
#ELSE
   MACRO RpcNsMgmtEntryDelete = RpcNsMgmtEntryDeleteA
#ENDIF

DECLARE FUNCTION RpcNsMgmtEntryInqIfIdsA IMPORT "RPCNS4.DLL" ALIAS "RpcNsMgmtEntryInqIfIdsA" ( _
   BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYREF EntryName AS ASCIIZ _                          ' __in RPC_CSTR EntryName
 , BYREF IfIdVec AS RPC_IF_ID_VECTOR _                  ' __out RPC_IF_ID_VECTOR * *IfIdVec
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsMgmtEntryInqIfIdsW IMPORT "RPCNS4.DLL" ALIAS "RpcNsMgmtEntryInqIfIdsW" ( _
   BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYREF EntryName AS WSTRINGZ _                        ' __in RPC_WSTR EntryName
 , BYREF IfIdVec AS RPC_IF_ID_VECTOR _                  ' __out RPC_IF_ID_VECTOR * *IfIdVec
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcNsMgmtEntryInqIfIds = RpcNsMgmtEntryInqIfIdsW
#ELSE
   MACRO RpcNsMgmtEntryInqIfIds = RpcNsMgmtEntryInqIfIdsA
#ENDIF

DECLARE FUNCTION RpcNsMgmtHandleSetExpAge IMPORT "RPCNS4.DLL" ALIAS "RpcNsMgmtHandleSetExpAge" ( _
   BYVAL NsHandle AS DWORD _                            ' __in RPC_NS_HANDLE NsHandle
 , BYVAL ExpirationAge AS DWORD _                       ' __in unsigned long ExpirationAge
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsMgmtInqExpAge IMPORT "RPCNS4.DLL" ALIAS "RpcNsMgmtInqExpAge" ( _
   BYREF ExpirationAge As DWORD _                       ' __out unsigned long * ExpirationAge
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsMgmtSetExpAge IMPORT "RPCNS4.DLL" ALIAS "RpcNsMgmtSetExpAge" ( _
   BYVAL ExpirationAge AS DWORD _                       ' __in unsigned long ExpirationAge
 ) AS LONG                                              ' RPC_STATUS

'/* Client API's implemented in wrappers. */

DECLARE FUNCTION RpcNsBindingImportBeginA IMPORT "RPCNS4.DLL" ALIAS "RpcNsBindingImportBeginA" ( _
   BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYREF EntryName AS ASCIIZ _                          ' __in_opt RPC_CSTR EntryName
 , BYVAL IfSpec AS DWORD _                              ' __in_opt RPC_IF_HANDLE IfSpec
 , BYREF ObjUuid AS GUID _                              ' __in_opt UUID *ObjUuid
 , BYREF ImportContext AS DWORD _                       ' __out RPC_NS_HANDLE *ImportContext
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsBindingImportBeginW IMPORT "RPCNS4.DLL" ALIAS "RpcNsBindingImportBeginW" ( _
   BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYVAL EntryName AS DWORD _                           ' __in_opt RPC_CSTR EntryName
 , BYVAL IfSpec AS DWORD _                              ' __in_opt RPC_IF_HANDLE IfSpec
 , BYREF ObjUuid AS GUID _                              ' __in_opt UUID *ObjUuid
 , BYREF ImportContext AS DWORD _                       ' __out RPC_NS_HANDLE *ImportContext
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcNsBindingImportBegin = RpcNsBindingImportBeginW
#ELSE
   MACRO RpcNsBindingImportBegin = RpcNsBindingImportBeginA
#ENDIF

DECLARE FUNCTION RpcNsBindingImportNext IMPORT "RPCNS4.DLL" ALIAS "RpcNsBindingImportNext" ( _
   BYVAL ImportContext AS DWORD _                       ' __in RPC_NS_HANDLE ImportContext
 , BYREF Binding AS DWORD _                             ' __out RPC_BINDING_HANDLE  * Binding
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsBindingImportDone IMPORT "RPCNS4.DLL" ALIAS "RpcNsBindingImportDone" ( _
   BYVAL ImportContext AS DWORD _                       ' __in_out RPC_NS_HANDLE * ImportContext
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsBindingSelect IMPORT "RPCNS4.DLL" ALIAS "RpcNsBindingSelect" ( _
   BYREF BindingVec AS RPC_BINDING_VECTOR _             ' __in_out RPC_BINDING_VECTOR * BindingVec
 , BYREF Binding As DWORD _                             ' __out RPC_BINDING_HANDLE  * Binding
 ) AS LONG                                              ' RPC_STATUS
