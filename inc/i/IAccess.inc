' ########################################################################################
' Microsoft Windows
' File: IAccess.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IACCESS_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "accctrl.inc"

' ########################################################################################
' IAccessControl interface
' IID = EEDD23E0-8410-11CE-A1C3-08002B2B8D8F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAccessControl_INTERFACE_DEFINED)
    %IAccessControl_INTERFACE_DEFINED = 1

$IID_IAccessControl = GUID$("{EEDD23E0-8410-11CE-A1C3-08002B2B8D8F}")

INTERFACE IAccessControl $IID_IAccessControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GrantAccessRights ( _                         ' VTable offset = 12
     BYREF pAccessList AS ACTRL_ALISTW _                ' __in PACTRL_ACCESSW pAccessList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAccessRights ( _                           ' VTable offset = 16
     BYREF pAccessList AS ACTRL_ALISTW _                ' __in PACTRL_ACCESSW pAccessList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOwner ( _                                  ' VTable offset = 16
     BYREF pOwner AS TRUSTEE_W _                        ' __in PTRUSTEEW pOwner
   , BYREF pGroup AS TRUSTEE_W _                        ' __in PTRUSTEEW pGroup
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RevokeAccessRights ( _                        ' VTable offset = 20
     BYREF lpProperty AS WSTRINGZ _                     ' __in LPWSTR lpProperty
   , BYVAL cTrustees AS DWORD _                         ' __in ULONG cTrustees
   , BYREF prgTrustees AS TRUSTEE_W _                   ' __in TRUSTEEW prgTrustees[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllAccessRights ( _                        ' VTable offset = 24
     BYREF lpProperty AS WSTRINGZ _                     ' __in LPWSTR lpProperty
   , BYREF ppAccessList AS ACTRL_ALISTW _               ' __out PACTRL_ACCESSW_ALLOCATE_ALL_NODES *ppAccessList
   , BYREF pOwner AS TRUSTEE_W _                        ' __in PTRUSTEEW pOwner
   , BYREF pGroup AS TRUSTEE_W _                        ' __in PTRUSTEEW pGroup
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsAccessAllowed ( _                           ' VTable offset = 28
     BYREF pTrustee AS TRUSTEE_W _                      ' __in PTRUSTEEW pTrustee
   , BYREF lpProperty AS WSTRINGZ _                     ' __in LPWSTR lpProperty
   , BYVAL AccessRights AS DWORD _                      ' __in ACCESS_RIGHTS AccessRights
   , BYREF pfAccessAllowed AS LONG _                    ' __out BOOL *pfAccessAllowed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAccessControl_INTERFACE_DEFINED__ */


' ########################################################################################
' IAuditControl interface
' IID = 1DA6292F-BC66-11CE-AAE3-00AA004C2737
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAuditControl_INTERFACE_DEFINED)
    %IAuditControl_INTERFACE_DEFINED = 1

$IID_IAuditControl = GUID$("{1DA6292F-BC66-11CE-AAE3-00AA004C2737}")

INTERFACE IAuditControl $IID_IAuditControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GrantAuditRights ( _                          ' VTable offset = 12
     BYREF pAuditList AS ACTRL_AUDITW _                 ' __in PACTRL_AUDITW pAuditList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAuditRights ( _                            ' VTable offset = 16
     BYREF pAuditList AS ACTRL_AUDITW _                 ' __in PACTRL_AUDITW pAuditList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RevokeAuditRights ( _                         ' VTable offset = 20
     BYREF lpProperty AS WSTRINGZ _                     ' __in LPWSTR lpProperty
   , BYVAL cTrustees AS DWORD _                         ' __in ULONG cTrustees
   , BYREF prgTrustees AS TRUSTEE_W _                   ' __in TRUSTEEW prgTrustees[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllAuditRights ( _                         ' VTable offset = 24
     BYREF lpProperty AS WSTRINGZ _                     ' __in LPWSTR lpProperty
   , BYREF ppAuditList AS ACTRL_AUDITW _                ' __out PACTRL_AUDITW *ppAuditList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsAccessAudited ( _                           ' VTable offset = 28
     BYREF pTrustee AS TRUSTEE_W _                      ' __in PTRUSTEEW pTrustee
   , BYVAL AuditRights AS DWORD _                       ' __in ACCESS_RIGHTS AuditRights
   , BYREF pfAccessAudited AS LONG _                    ' __out BOOL *pfAccessAudited
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAuditControl_INTERFACE_DEFINED__ */
