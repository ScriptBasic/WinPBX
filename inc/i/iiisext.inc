' ########################################################################################
' Microsoft Windows
' File: IIISExt.inc
' Library name: IISExt
' Version: 1.0, Locale ID = 0
' Type library: iisext.tlb
' Library GUID: {2A56EA30-AFEB-11D1-9868-00A0C922E703}
' Contents: Active DS IIS Extension Dll
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IIISEXT_INC = 1

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_IISExtApp              = GUID$("{B4F34438-AFEC-11D1-9868-00A0C922E703}")
$CLSID_IISExtApplicationPool  = GUID$("{E99F9D0C-FB39-402B-9EEB-AA185237BD34}")
$CLSID_IISExtApplicationPools = GUID$("{95863074-A389-406A-A2D7-D98BFC95B905}")
$CLSID_IISExtComputer         = GUID$("{91EF9258-AFEC-11D1-9868-00A0C922E703}")
$CLSID_IISExtDsCrMap          = GUID$("{BC36CDE8-AFEB-11D1-9868-00A0C922E703}")
$CLSID_IISExtServer           = GUID$("{C3B32488-AFEC-11D1-9868-00A0C922E703}")
$CLSID_IISExtWebService       = GUID$("{40B8F873-B30E-475D-BEC5-4D0EBB0DBAF3}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IISApp                   = GUID$("{46FBBB80-0192-11D1-9C39-00A0C922E703}")
$IID_IISApp2                  = GUID$("{603DCBEA-7350-11D2-A7BE-0000F8085B95}")
$IID_IISApp3                  = GUID$("{2812B639-8FAC-4510-96C5-71DDBD1F54FC}")
$IID_IISApplicationPool       = GUID$("{0B3CB1E1-829A-4C06-8B09-F56DA1894C88}")
$IID_IISApplicationPools      = GUID$("{587F123F-49B4-49DD-939E-F4547AA3FA75}")
$IID_IISComputer              = GUID$("{CF87A2E0-078B-11D1-9C3D-00A0C922E703}")
$IID_IISComputer2             = GUID$("{63D89839-5762-4A68-B1B9-3507EA76CBBF}")
$IID_IISDsCrMap               = GUID$("{EDCD6A60-B053-11D0-A62F-00A0C922E752}")
$IID_IISWebService            = GUID$("{EE46D40C-1B38-4A02-898D-358E74DFC9D2}")


' ########################################################################################
' Interface name = IISApplicationPool
' IID = {0B3CB1E1-829A-4C06-8B09-F56DA1894C88}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IISApplicationPool_INTERFACE_DEFINED)
    %IISApplicationPool_INTERFACE_DEFINED = 1

INTERFACE IISApplicationPool $IID_IISApplicationPool

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IISApplicationPool Methods
   ' =====================================================================================
   METHOD Recycle <101> ( _                             ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumAppsInPool <102> ( _                      ' VTable offset = 84
   ) AS VARIANT                                         ' __retval_out VARIANT *bstrBuffer
   ' =====================================================================================
   METHOD Start <103> ( _                               ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <104> ( _                                ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IISApplicationPool_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IISApplicationPools
' IID = {587F123F-49B4-49DD-939E-F4547AA3FA75}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IISApplicationPools_INTERFACE_DEFINED)
    %IISApplicationPools_INTERFACE_DEFINED = 1

INTERFACE IISApplicationPools $IID_IISApplicationPools

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IISApplicationPools_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IISWebService
' IID = {EE46D40C-1B38-4A02-898D-358E74DFC9D2}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IISWebService_INTERFACE_DEFINED)
    %IISWebService_INTERFACE_DEFINED = 1

INTERFACE IISWebService $IID_IISWebService

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IISWebService Methods
   ' =====================================================================================
   METHOD GetCurrentMode <101> ( _                      ' VTable offset = 80
   ) AS VARIANT                                         ' __retval_out VARIANT *pvServerMode
   ' =====================================================================================
   METHOD CreateNewSite <102> ( _                       ' VTable offset = 84
     BYVAL bstrServerComment AS WSTRING _               ' __in BSTR bstrServerComment
   , BYREF pvServerBindings AS VARIANT _                ' __in VARIANT *pvServerBindings
   , BYVAL bstrRootVDirPath AS WSTRING _                ' __in BSTR bstrRootVDirPath
   , OPTIONAL BYVAL vServerID AS VARIANT _              ' __in-opt VARIANT vServerID
   ) AS VARIANT                                         ' __retval_out VARIANT *pvActualID
   ' =====================================================================================
   METHOD EnableApplication <103> ( _                   ' VTable offset = 88
     BYVAL bstrAppName AS WSTRING _                     ' __in BSTR bstrAppName
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveApplication <104> ( _                   ' VTable offset = 92
     BYVAL bstrAppName AS WSTRING _                     ' __in BSTR bstrAppName
   )                                                    ' void
   ' =====================================================================================
   METHOD ListApplications <105> ( _                    ' VTable offset = 96
   ) AS VARIANT                                         ' __retval_out VARIANT *bstrBuffer
   ' =====================================================================================
   METHOD AddDependency <106> ( _                       ' VTable offset = 100
     BYVAL bstrApplication AS WSTRING _                 ' __in BSTR bstrApplication
   , BYVAL bstrGroupID AS WSTRING _                     ' __in BSTR bstrGroupID
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveDependency <107> ( _                    ' VTable offset = 104
     BYVAL bstrApplication AS WSTRING _                 ' __in BSTR bstrApplication
   , BYVAL bstrGroupID AS WSTRING _                     ' __in BSTR bstrGroupID
   )                                                    ' void
   ' =====================================================================================
   METHOD EnableWebServiceExtension <108> ( _           ' VTable offset = 108
     BYVAL bstrExtension AS WSTRING _                   ' __in BSTR bstrExtension
   )                                                    ' void
   ' =====================================================================================
   METHOD DisableWebServiceExtension <109> ( _          ' VTable offset = 112
     BYVAL bstrExtension AS WSTRING _                   ' __in BSTR bstrExtension
   )                                                    ' void
   ' =====================================================================================
   METHOD ListWebServiceExtensions <110> ( _            ' VTable offset = 116
   ) AS VARIANT                                         ' __retval_out VARIANT *bstrBuffer
   ' =====================================================================================
   METHOD EnableExtensionFile <111> ( _                 ' VTable offset = 120
     BYVAL bstrExtensionFile AS WSTRING _               ' __in BSTR bstrExtensionFile
   )                                                    ' void
   ' =====================================================================================
   METHOD DisableExtensionFile <112> ( _                ' VTable offset = 124
     BYVAL bstrExtensionFile AS WSTRING _               ' __in BSTR bstrExtensionFile
   )                                                    ' void
   ' =====================================================================================
   METHOD AddExtensionFile <113> ( _                    ' VTable offset = 128
     BYVAL bstrExtensionFile AS WSTRING _               ' __in BSTR bstrExtensionFile
   , BYVAL bAccess AS VARIANT _                         ' __in VARIANT bAccess
   , BYVAL bstrGroupID AS WSTRING _                     ' __in BSTR bstrGroupID
   , BYVAL bCanDelete AS VARIANT _                      ' __in VARIANT bCanDelete
   , BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteExtensionFileRecord <114> ( _           ' VTable offset = 132
     BYVAL bstrExtensionFile AS WSTRING _                                    ' __in BSTR bstrExtensionFile
   )                                                    ' void
   ' =====================================================================================
   METHOD ListExtensionFiles <115> ( _                  ' VTable offset = 136
   ) AS VARIANT                                         ' __retval_out VARIANT *bstrBuffer
   ' =====================================================================================
   METHOD QueryGroupIDStatus <116> ( _                  ' VTable offset = 140
     BYVAL bstrGroupID AS WSTRING _                     ' __in BSTR bstrGroupID
   ) AS VARIANT                                         ' __retval_out VARIANT *bstrBuffer
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IISWebService_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IISDsCrMap
' IID = {EDCD6A60-B053-11D0-A62F-00A0C922E752}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IISDsCrMap_INTERFACE_DEFINED)
    %IISDsCrMap_INTERFACE_DEFINED = 1

INTERFACE IISDsCrMap $IID_IISDsCrMap

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IISDsCrMap Methods
   ' =====================================================================================
   METHOD CreateMapping <101> ( _                       ' VTable offset = 80
     BYVAL vCert AS VARIANT _                           ' __in VARIANT vCert
   , BYVAL bstrNtAcct AS WSTRING _                      ' __in BSTR bstrNtAcct
   , BYVAL bstrNtPwd AS WSTRING _                       ' __in BSTR bstrNtPwd
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL lEnabled AS LONG _                           ' __in LONG lEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMapping <102> ( _                          ' VTable offset = 84
     BYVAL lMethod AS LONG _                            ' __in LONG lMethod
   , BYVAL vKey AS VARIANT _                            ' __in VARIANT vKey
   , BYREF pvCert AS VARIANT _                          ' __out VARIANT *pvCert
   , BYREF pbstrNtAcct AS VARIANT _                     ' __out VARIANT *pbstrNtAcct
   , BYREF pbstrNtPwd AS VARIANT _                      ' __out VARIANT *pbstrNtPwd
   , BYREF pbstrName AS VARIANT _                       ' __out VARIANT *pbstrName
   , BYREF plEnabled AS VARIANT _                       ' __out VARIANT *plEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteMapping <103> ( _                       ' VTable offset = 88
     BYVAL lMethod AS LONG _                            ' __in LONG lMethod
   , BYVAL vKey AS VARIANT _                            ' __in VARIANT vKey
   )                                                    ' void
   ' =====================================================================================
   METHOD SetEnabled <104> ( _                          ' VTable offset = 92
     BYVAL lMethod AS LONG _                            ' __in LONG lMethod
   , BYVAL vKey AS VARIANT _                            ' __in VARIANT vKey
   , BYVAL lEnabled AS LONG _                           ' __in LONG lEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD SetName <105> ( _                             ' VTable offset = 96
     BYVAL lMethod AS LONG _                            ' __in LONG lMethod
   , BYVAL vKey AS VARIANT _                            ' __in VARIANT vKey
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPwd <106> ( _                              ' VTable offset = 100
     BYVAL lMethod AS LONG _                            ' __in LONG lMethod
   , BYVAL vKey AS VARIANT _                            ' __in VARIANT vKey
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrPwd
   )                                                    ' void
   ' =====================================================================================
   METHOD SetAcct <107> ( _                             ' VTable offset = 104
     BYVAL lMethod AS LONG _                            ' __in LONG lMethod
   , BYVAL vKey AS VARIANT _                            ' __in VARIANT vKey
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrAcct
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IISDsCrMap_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IISApp
' IID = {46FBBB80-0192-11D1-9C39-00A0C922E703}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IISApp_INTERFACE_DEFINED)
    %IISApp_INTERFACE_DEFINED = 1

INTERFACE IISApp $IID_IISApp

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IISApp Methods
   ' =====================================================================================
   METHOD AppCreate <101> ( _                           ' VTable offset = 80
     BYVAL bSetInProcFlag AS INTEGER _                  ' __in VARIANT_BOOL bSetInProcFlag
   )                                                    ' void
   ' =====================================================================================
   METHOD AppDelete <102> ( _                           ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD AppDeleteRecursive <103> ( _                  ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   METHOD AppUnLoad <104> ( _                           ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD AppUnLoadRecursive <105> ( _                  ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD AppDisable <106> ( _                          ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================
   METHOD AppDisableRecursive <107> ( _                 ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================
   METHOD AppEnable <108> ( _                           ' VTable offset = 108
   )                                                    ' void
   ' =====================================================================================
   METHOD AppEnableRecursive <109> ( _                  ' VTable offset = 112
   )                                                    ' void
   ' =====================================================================================
   METHOD AppGetStatus <110> ( _                        ' VTable offset = 116
     BYREF pdwStatus AS DWORD _                         ' __out DWORD *pdwStatus
   )                                                    ' void
   ' =====================================================================================
   METHOD AspAppRestart <111> ( _                       ' VTable offset = 120
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IISApp_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IISApp2
' IID = {603DCBEA-7350-11D2-A7BE-0000F8085B95}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IISApp
' ########################################################################################

#IF NOT %DEF(%IISApp2_INTERFACE_DEFINED)
    %IISApp2_INTERFACE_DEFINED = 1

INTERFACE IISApp2 $IID_IISApp2

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IISApp Methods
   ' =====================================================================================
   METHOD AppCreate <101> ( _                           ' VTable offset = 80
     BYVAL bSetInProcFlag AS INTEGER _                  ' __in VARIANT_BOOL bSetInProcFlag
   )                                                    ' void
   ' =====================================================================================
   METHOD AppDelete <102> ( _                           ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD AppDeleteRecursive <103> ( _                  ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   METHOD AppUnLoad <104> ( _                           ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD AppUnLoadRecursive <105> ( _                  ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD AppDisable <106> ( _                          ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================
   METHOD AppDisableRecursive <107> ( _                 ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================
   METHOD AppEnable <108> ( _                           ' VTable offset = 108
   )                                                    ' void
   ' =====================================================================================
   METHOD AppEnableRecursive <109> ( _                  ' VTable offset = 112
   )                                                    ' void
   ' =====================================================================================
   METHOD AppGetStatus <110> ( _                        ' VTable offset = 116
     BYREF pdwStatus AS DWORD _                         ' __out DWORD *pdwStatus
   )                                                    ' void
   ' =====================================================================================
   METHOD AspAppRestart <111> ( _                       ' VTable offset = 120
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IISApp2 Methods
   ' =====================================================================================
   METHOD AppCreate2 <112> ( _                          ' VTable offset = 124
     BYVAL lAppMode AS LONG _                           ' __in LONG lAppMode
   )                                                    ' void
   ' =====================================================================================
   METHOD AppGetStatus2 <113> ( _                       ' VTable offset = 128
   ) AS LONG                                            ' __retval_out LONG *lpStatus
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IISApp2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IISApp3
' IID = {2812B639-8FAC-4510-96C5-71DDBD1F54FC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IISApp2
' ########################################################################################

#IF NOT %DEF(%IISApp3_INTERFACE_DEFINED)
    %IISApp3_INTERFACE_DEFINED = 1


INTERFACE IISApp3 $IID_IISApp3

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IISApp Methods
   ' =====================================================================================
   METHOD AppCreate <101> ( _                           ' VTable offset = 80
     BYVAL bSetInProcFlag AS INTEGER _                  ' __in VARIANT_BOOL bSetInProcFlag
   )                                                    ' void
   ' =====================================================================================
   METHOD AppDelete <102> ( _                           ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD AppDeleteRecursive <103> ( _                  ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   METHOD AppUnLoad <104> ( _                           ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD AppUnLoadRecursive <105> ( _                  ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD AppDisable <106> ( _                          ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================
   METHOD AppDisableRecursive <107> ( _                 ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================
   METHOD AppEnable <108> ( _                           ' VTable offset = 108
   )                                                    ' void
   ' =====================================================================================
   METHOD AppEnableRecursive <109> ( _                  ' VTable offset = 112
   )                                                    ' void
   ' =====================================================================================
   METHOD AppGetStatus <110> ( _                        ' VTable offset = 116
     BYREF pdwStatus AS DWORD _                         ' __out DWORD *pdwStatus
   )                                                    ' void
   ' =====================================================================================
   METHOD AspAppRestart <111> ( _                       ' VTable offset = 120
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IISApp2 Methods
   ' =====================================================================================
   METHOD AppCreate2 <112> ( _                          ' VTable offset = 124
     BYVAL lAppMode AS LONG _                           ' __in LONG lAppMode
   )                                                    ' void
   ' =====================================================================================
   METHOD AppGetStatus2 <113> ( _                       ' VTable offset = 128
   ) AS LONG                                            ' __retval_out LONG *lpStatus
   ' =====================================================================================

   ' =====================================================================================
   ' IISApp3 Methods
   ' =====================================================================================
   METHOD AppCreate3 <114> ( _                          ' VTable offset = 132
     BYVAL lAppMode AS LONG _                           ' __in LONG lAppMode
   , BYVAL bstrAppPooI AS VARIANT _                     ' __in VARIANT bstrAppPooI
   , BYVAL bCreatePool AS VARIANT _                     ' __in VARIANT bCreatePool
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IISApp3_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IISComputer
' IID = {CF87A2E0-078B-11D1-9C3D-00A0C922E703}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IADs
' ########################################################################################

#IF NOT %DEF(%IISComputer_INTERFACE_DEFINED)
    %IISComputer_INTERFACE_DEFINED = 1

INTERFACE IISComputer $IID_IISComputer

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IISComputer Methods
   ' =====================================================================================
   METHOD Backup <101> ( _                              ' VTable offset = 80
     BYVAL bstrLocation AS WSTRING _                    ' __in BSTR bstrLocation
   , BYVAL lVersion AS LONG _                           ' __in LONG lVersion
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD Restore <102> ( _                             ' VTable offset = 84
     BYVAL bstrLocation AS WSTRING _                    ' __in BSTR bstrLocation
   , BYVAL lVersion AS LONG _                           ' __in LONG lVersion
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumBackups <103> ( _                         ' VTable offset = 88
     BYVAL bstrLocation AS WSTRING _                    ' __in BSTR bstrLocation
   , BYVAL lIndex AS LONG _                             ' __in LONG lIndex
   , BYREF pvVersion AS VARIANT _                       ' __out VARIANT *pvVersion
   , BYREF pvLocations AS VARIANT _                     ' __out VARIANT *pvLocations
   , BYREF pvDate AS VARIANT _                          ' __out VARIANT *pvDate
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteBackup <104> ( _                        ' VTable offset = 92
     BYVAL bstrLocation AS WSTRING _                    ' __in BSTR bstrLocation
   , BYVAL lVersion AS LONG _                           ' __in LONG lVersion
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IISComputer_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IISComputer2
' IID = {63D89839-5762-4A68-B1B9-3507EA76CBBF}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IISComputer
' ########################################################################################

#IF NOT %DEF(%IISComputer2_INTERFACE_DEFINED)
    %IISComputer2_INTERFACE_DEFINED = 1

INTERFACE IISComputer2 $IID_IISComputer2

   INHERIT IDispatch

   ' =====================================================================================
   ' IADs Methods
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Class <3> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET GUID <4> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET ADsPath <5> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Parent <6> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   PROPERTY GET Schema <7> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *retval
   ' =====================================================================================
   METHOD GetInfo <8> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SetInfo <9> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Get <10> ( _                                  ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD Put <11> ( _                                  ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEx <12> ( _                                ' VTable offset = 68
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProp
   ' =====================================================================================
   METHOD PutEx <13> ( _                                ' VTable offset = 72
     BYVAL lnControlCode AS LONG _                      ' __in long lnControlCode
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL vProp AS VARIANT _                           ' __in VARIANT vProp
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInfoEx <14> ( _                            ' VTable offset = 76
     BYVAL vProperties AS VARIANT _                     ' __in VARIANT vProperties
   , BYVAL lnReserved AS LONG _                         ' __in long lnReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IISComputer Methods
   ' =====================================================================================
   METHOD Backup <101> ( _                              ' VTable offset = 80
     BYVAL bstrLocation AS WSTRING _                    ' __in BSTR bstrLocation
   , BYVAL lVersion AS LONG _                           ' __in LONG lVersion
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD Restore <102> ( _                             ' VTable offset = 84
     BYVAL bstrLocation AS WSTRING _                    ' __in BSTR bstrLocation
   , BYVAL lVersion AS LONG _                           ' __in LONG lVersion
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumBackups <103> ( _                         ' VTable offset = 88
     BYVAL bstrLocation AS WSTRING _                    ' __in BSTR bstrLocation
   , BYVAL lIndex AS LONG _                             ' __in LONG lIndex
   , BYREF pvVersion AS VARIANT _                       ' __out VARIANT *pvVersion
   , BYREF pvLocations AS VARIANT _                     ' __out VARIANT *pvLocations
   , BYREF pvDate AS VARIANT _                          ' __out VARIANT *pvDate
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteBackup <104> ( _                        ' VTable offset = 92
     BYVAL bstrLocation AS WSTRING _                    ' __in BSTR bstrLocation
   , BYVAL lVersion AS LONG _                           ' __in LONG lVersion
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IISComputer2 Methods
   ' =====================================================================================
   METHOD BackupWithPassword <105> ( _                  ' VTable offset = 96
     BYVAL bstrLocation AS WSTRING _                    ' __in BSTR bstrLocation
   , BYVAL lVersion AS LONG _                           ' __in LONG lVersion
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL bstrPassword AS WSTRING _                    ' __in BSTR bstrPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD RestoreWithPassword <106> ( _                 ' VTable offset = 100
     BYVAL bstrLocation AS WSTRING _                    ' __in BSTR bstrLocation
   , BYVAL lVersion AS LONG _                           ' __in LONG lVersion
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL bstrPassword AS WSTRING _                    ' __in BSTR bstrPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD Export <107> ( _                              ' VTable offset = 104
     BYVAL bstrPassword AS WSTRING _                    ' __in BSTR bstrPassword
   , BYVAL bstrFilename AS WSTRING _                    ' __in BSTR bstrFilename
   , BYVAL bstrSourcePath AS WSTRING _                  ' __in BSTR bstrSourcePath
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD Import <108> ( _                              ' VTable offset = 108
     BYVAL bstrPassword AS WSTRING _                    ' __in BSTR bstrPassword
   , BYVAL bstrFilename AS WSTRING _                    ' __in BSTR bstrFilename
   , BYVAL bstrSourcePath AS WSTRING _                  ' __in BSTR bstrSourcePath
   , BYVAL bstrDestPath AS WSTRING _                    ' __in BSTR bstrDestPath
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveData <109> ( _                            ' VTable offset = 112
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IISComputer2_INTERFACE_DEFINED__ */
