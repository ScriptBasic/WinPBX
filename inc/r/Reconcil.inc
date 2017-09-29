' ########################################################################################
' Microsoft Windows
' File: Reconcil.inc
' Contents: OLE reconciliation interface definitions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%REONCIL_INC = 1

'/* Headers
' **********/

#INCLUDE ONCE "recguids.inc"
#INCLUDE ONCE "objidl.inc"

'/* Constants
' ************/

'/* for use in IStorage::SetStateBits() */

%STATEBITS_FLAT                 = &H0001

'/* reconciliation SCODEs */

'#define REC_S_IDIDTHEUPDATES           MAKE_SCODE(SEVERITY_SUCCESS, FACILITY_ITF, 0x1000)
'#define REC_S_NOTCOMPLETE              MAKE_SCODE(SEVERITY_SUCCESS, FACILITY_ITF, 0x1001)
'#define REC_S_NOTCOMPLETEBUTPROPAGATE  MAKE_SCODE(SEVERITY_SUCCESS, FACILITY_ITF, 0x1002)

'#define REC_E_ABORTED                  MAKE_SCODE(SEVERITY_ERROR,   FACILITY_ITF, 0x1000)
'#define REC_E_NOCALLBACK               MAKE_SCODE(SEVERITY_ERROR,   FACILITY_ITF, 0x1001)
'#define REC_E_NORESIDUES               MAKE_SCODE(SEVERITY_ERROR,   FACILITY_ITF, 0x1002)
'#define REC_E_TOODIFFERENT             MAKE_SCODE(SEVERITY_ERROR,   FACILITY_ITF, 0x1003)
'#define REC_E_INEEDTODOTHEUPDATES      MAKE_SCODE(SEVERITY_ERROR,   FACILITY_ITF, 0x1004)

%REC_S_IDIDTHEUPDATES          = &H00041000&
%REC_S_NOTCOMPLETE             = &H00041001&
%REC_S_NOTCOMPLETEBUTPROPAGATE = &H00041002&

%REC_E_ABORTED                 = &H80041000&
%REC_E_NOCALLBACK              = &H80041001&
%REC_E_NORESIDUES              = &H80041002&
%REC_E_TOODIFFERENT            = &H80041003&
%REC_E_INEEDTODOTHEUPDATES     = &H80041004&

'/* Interfaces
' *************/

' ########################################################################################
' INotifyReplica interface
' IID = 99180163-DA16-101A-935C-444553540000
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE INotifyReplica $IID_INotifyReplica

   INHERIT IUnknown

   ' =====================================================================================
   METHOD YouAreAReplica ( _                            ' VTable offset = 12
     BYVAL ulcOtherReplicas AS DWORD _                  ' __in  ULONG ulcOtherReplicas
   , BYREF rgpmkOtherReplicas AS IMoniker _             ' __out IMoniker **rgpmkOtherReplicas
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' IReconcileInitiator interface
' IID = 99180161-DA16-101A-935C-444553540000
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IReconcileInitiator $IID_IReconcileInitiator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAbortCallback ( _                          ' VTable offset = 12
     BYVAL punkForAbort AS IUnknown _                   ' __in IUnknown *punkForAbort
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProgressFeedback ( _                       ' VTable offset = 16
     BYVAL ulProgress AS DWORD _                        ' __in ULONG ulProgress
   , BYVAL ulProgressMax AS DWORD _                     ' __in ULONG ulProgressMax
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/* IReconcilableObject::Reconcile() flags */

' enum RECONCILEF

'/* interaction with the user is allowed */
%RECONCILEF_MAYBOTHERUSER         = &H0001

'/*
'* hwndProgressFeedback may be used to provide reconciliation progress
'* feedback to the user.
'*/

%RECONCILEF_FEEDBACKWINDOWVALID   = &H0002

'/* residue support not required */

%RECONCILEF_NORESIDUESOK          = &H0004

'/* caller not interested in callee's residues */

%RECONCILEF_OMITSELFRESIDUE       = &H0008

'/*
' * Reconcile() call resuming after a previous Reconcile() call returned
' * REC_E_NOTCOMPLETE
' */

%RECONCILEF_RESUMERECONCILIATION  = &H0010

'/* Object may perform all updates. */

%RECONCILEF_YOUMAYDOTHEUPDATES    = &H0020

'/* Only this object has been changed. */

%RECONCILEF_ONLYYOUWERECHANGED    = &H0040

'/* flag combinations */

%ALL_RECONCILE_FLAGS = %RECONCILEF_MAYBOTHERUSER OR _
                       %RECONCILEF_FEEDBACKWINDOWVALID OR _
                       %RECONCILEF_NORESIDUESOK OR _
                       %RECONCILEF_OMITSELFRESIDUE OR _
                       %RECONCILEF_RESUMERECONCILIATION OR _
                       %RECONCILEF_YOUMAYDOTHEUPDATES OR _
                       %RECONCILEF_ONLYYOUWERECHANGED


' ########################################################################################
' IReconcilableObject interface
' IID =99180162-DA16-101A-935C-444553540000
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IReconcilableObject $IID_IReconcilableObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Reconcile ( _                                 ' VTable offset = 12
     BYVAL pInitiator AS IReconcileInitiator _          ' __in  IReconcileInitiator *pInitiator
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYVAL hwndOwner AS DWORD _                         ' __in  HWND hwndOwner
   , BYVAL hwndProgressFeedback AS DWORD _              ' __in  HWND hwndProgressFeedback
   , BYVAL ulcInput AS DWORD _                          ' __in  ULONG ulcInput
   , BYREF rgpmkOtherInput AS IMoniker _                ' __out IMoniker **rgpmkOtherInput
   , BYREF plOutIndex AS LONG _                         ' __out PLONG plOutIndex
   , BYVAL pstgNewResidues AS IUnknown _                ' __in  IStorage *pstgNewResidues
   , BYVAL pvReserved AS DWORD _                        ' __in  PVOID pvReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProgressFeedbackMaxEstimate ( _            ' VTable offset = 16
     BYREF pulProgressMax AS DWORD _                    ' __out PULONG pulProgressMax
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IBriefcaseInitiator interface
' IID = 99180164-DA16-101A-935C-444553540000
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IBriefcaseInitiator $IID_IBriefcaseInitiator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsMonikerInBriefcase ( _                      ' VTable offset = 12
     BYVAL pmk AS IMoniker _                            ' __in IMoniker *pmk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE
