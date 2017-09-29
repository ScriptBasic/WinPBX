' ########################################################################################
' Microsoft Windows
' File: OutlCtl.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: OLXLib
' Version: 1.0, Locale ID = 0
' Description: Microsoft Office Outlook View Control
' Path: C:\Program Files\Microsoft Office\OFFICE11\OUTLCTL.DLL
' Library GUID: {0006F062-0000-0000-C000-000000000046}
' ########################################################################################

#INCLUDE THIS ONCE
%OUTLCTL_INC = 1

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {0468C085-CA5B-11D0-AF08-00609797F0E0}
$PROGID_OVCtl_DataCtl1 = "DataCtl.DataCtl.1"
' CLSID = {0006F063-0000-0000-C000-000000000046}
$PROGID_OVCtl_ViewCtl1 = "OVCtl.OVCtl.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {0468C085-CA5B-11D0-AF08-00609797F0E0}
$PROGID_OVCtl_DataCtl = "DataCtl.DataCtl"
' CLSID = {0006F063-0000-0000-C000-000000000046}
$PROGID_OVCtl_ViewCtl = "OVCtl.OVCtl"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_OVCtl_ObjectModelCtl = GUID$("{0006F069-0000-0000-C000-000000000046}")
$CLSID_OVCtl_DataCtl = GUID$("{0468C085-CA5B-11D0-AF08-00609797F0E0}")
$CLSID_OVCtl_ViewCtl = GUID$("{0006F063-0000-0000-C000-000000000046}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_OVCtl_IDataCtl = GUID$("{0468C084-CA5B-11D0-AF08-00609797F0E0}")
$IID_OVCtl_IObjectModelAccess = GUID$("{00067276-0000-0000-C000-000000000046}")
$IID_OVCtl_IViewCtl = GUID$("{00067274-0000-0000-C000-000000000046}")
$IID_OVCtl_ViewCtlEvents = GUID$("{BA4CF450-EE13-11D3-8C45-00C04F4C517C}")

' ========================================================================================
' OlxDefaultFolders enum
' ========================================================================================

%olxFolderDeletedItems                                  = 3            ' &H3
%olxFolderOutbox                                        = 4            ' &H4
%olxFolderSentMail                                      = 5            ' &H5
%olxFolderInbox                                         = 6            ' &H6
%olxFolderCalendar                                      = 9            ' &H9
%olxFolderContacts                                      = 10           ' &HA
%olxFolderJournal                                       = 11           ' &HB
%olxFolderNotes                                         = 12           ' &HC
%olxFolderTasks                                         = 13           ' &HD
%olxFolderDrafts                                        = 16           ' &H10

' ========================================================================================
' FR_REFRESHOPTIONS enum <alias> FIELDREGISTRY_REFRESHOPTIONS
' ========================================================================================

%fro_Forms                                              = 0            ' &H0
%fro_Fields                                             = 1            ' &H1
%fro_View                                               = 2            ' &H2

' ########################################################################################
' Interface name = IObjectModelAccess
' IID = {00067276-0000-0000-C000-000000000046}
' IObjectModelAccess Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%OVCtl_IObjectModelAccess_INTERFACE_DEFINED)
    %OVCtl_IObjectModelAccess_INTERFACE_DEFINED = 1

INTERFACE OVCtl_IObjectModelAccess $IID_OVCtl_IObjectModelAccess

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET OutlookApplication <1> ( _              ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out IDispatch **pVal
   ' =====================================================================================
   PROPERTY SET OutlookApplication <1> ( _              ' VTable offset = 32
     BYVAL pVal AS IDispatch _                          ' __in IDispatch *pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPref <2> ( _                               ' VTable offset = 36
     BYVAL szname AS WSTRING _                          ' __in BSTR szname
   , BYVAL szvalue AS WSTRING _                         ' __in BSTR szvalue
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPref <3> ( _                               ' VTable offset = 40
     BYVAL szname AS WSTRING _                          ' __in BSTR szname
   ) AS WSTRING                                         ' __retval_out *pszvalue
   ' =====================================================================================
   METHOD DeletePrefs <4> ( _                           ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ActiveDesktop <5> ( _                   ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *pfActiveDesktop
   ' =====================================================================================
   PROPERTY SET ActiveDesktop <5> ( _                   ' VTable offset = 52
     BYVAL pfActiveDesktop AS LONG _                    ' __in long pfActiveDesktop
   )                                                    ' void
   ' =====================================================================================
   METHOD EnableInProcOptimizations <6> ( _             ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD FindPerson <7> ( _                            ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDate <8> ( _                               ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDate
   ' =====================================================================================
   METHOD PickEmailFolders <9> ( _                      ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __OVCtl_IObjectModelAccess_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IViewCtl
' IID = {00067274-0000-0000-C000-000000000046}
' IViewCtl Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%OVCtl_IViewCtl_INTERFACE_DEFINED)
    %OVCtl_IViewCtl_INTERFACE_DEFINED = 1

INTERFACE OVCtl_IViewCtl $IID_OVCtl_IViewCtl

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET View <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET View <1> ( _                            ' VTable offset = 32
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Folder <2> ( _                          ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET Folder <2> ( _                          ' VTable offset = 40
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Namespace <3> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET Namespace <3> ( _                       ' VTable offset = 48
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ActiveFolder <4> ( _                    ' VTable offset = 52
   ) AS IDispatch                                       ' __retval_out IDispatch **pVal
   ' =====================================================================================
   PROPERTY GET OutlookApplication <5> ( _              ' VTable offset = 56
   ) AS IDispatch                                       ' __retval_out IDispatch **pVal
   ' =====================================================================================
   PROPERTY GET Restriction <6> ( _                     ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET Restriction <6> ( _                     ' VTable offset = 64
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DeferUpdate <7> ( _                     ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET DeferUpdate <7> ( _                     ' VTable offset = 72
     BYVAL pVal AS INTEGER _                            ' __in VARIANT_BOOL pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Open <8> ( _                                  ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================
   METHOD Reply <9> ( _                                 ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   METHOD ReplyAll <10> ( _                             ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD Forward <11> ( _                              ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   METHOD ReplyInFolder <12> ( _                        ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD NewDefaultItem <13> ( _                       ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD NewOfficeDocument <14> ( _                    ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveAs <15> ( _                               ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================
   METHOD PrintItem <16> ( _                            ' VTable offset = 108
   )                                                    ' void
   ' =====================================================================================
   METHOD FlagItem <17> ( _                             ' VTable offset = 112
   )                                                    ' void
   ' =====================================================================================
   METHOD ForceUpdate <18> ( _                          ' VTable offset = 116
   )                                                    ' void
   ' =====================================================================================
   METHOD Categories <19> ( _                           ' VTable offset = 120
   )                                                    ' void
   ' =====================================================================================
   METHOD MarkAllAsRead <20> ( _                        ' VTable offset = 124
   )                                                    ' void
   ' =====================================================================================
   METHOD GoToToday <21> ( _                            ' VTable offset = 128
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <22> ( _                               ' VTable offset = 132
   )                                                    ' void
   ' =====================================================================================
   METHOD AdvancedFind <23> ( _                         ' VTable offset = 136
   )                                                    ' void
   ' =====================================================================================
   METHOD AddressBook <24> ( _                          ' VTable offset = 140
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveItem <25> ( _                             ' VTable offset = 144
   )                                                    ' void
   ' =====================================================================================
   METHOD NewForm <26> ( _                              ' VTable offset = 148
   )                                                    ' void
   ' =====================================================================================
   METHOD NewMessage <27> ( _                           ' VTable offset = 152
   )                                                    ' void
   ' =====================================================================================
   METHOD NewPost <28> ( _                              ' VTable offset = 156
   )                                                    ' void
   ' =====================================================================================
   METHOD NewAppointment <29> ( _                       ' VTable offset = 160
   )                                                    ' void
   ' =====================================================================================
   METHOD NewMeetingRequest <30> ( _                    ' VTable offset = 164
   )                                                    ' void
   ' =====================================================================================
   METHOD NewTask <31> ( _                              ' VTable offset = 168
   )                                                    ' void
   ' =====================================================================================
   METHOD NewTaskRequest <32> ( _                       ' VTable offset = 172
   )                                                    ' void
   ' =====================================================================================
   METHOD NewContact <33> ( _                           ' VTable offset = 176
   )                                                    ' void
   ' =====================================================================================
   METHOD NewJournalEntry <34> ( _                      ' VTable offset = 180
   )                                                    ' void
   ' =====================================================================================
   METHOD CustomizeView <35> ( _                        ' VTable offset = 184
   )                                                    ' void
   ' =====================================================================================
   METHOD Sort <36> ( _                                 ' VTable offset = 188
   )                                                    ' void
   ' =====================================================================================
   METHOD GroupBy <37> ( _                              ' VTable offset = 192
   )                                                    ' void
   ' =====================================================================================
   METHOD ShowFields <38> ( _                           ' VTable offset = 196
   )                                                    ' void
   ' =====================================================================================
   METHOD CollapseAllGroups <39> ( _                    ' VTable offset = 200
   )                                                    ' void
   ' =====================================================================================
   METHOD ExpandAllGroups <40> ( _                      ' VTable offset = 204
   )                                                    ' void
   ' =====================================================================================
   METHOD CollapseGroup <41> ( _                        ' VTable offset = 208
   )                                                    ' void
   ' =====================================================================================
   METHOD ExpandGroup <42> ( _                          ' VTable offset = 212
   )                                                    ' void
   ' =====================================================================================
   METHOD AddToPFFavorites <43> ( _                     ' VTable offset = 216
   )                                                    ' void
   ' =====================================================================================
   METHOD SynchFolder <44> ( _                          ' VTable offset = 220
   )                                                    ' void
   ' =====================================================================================
   METHOD SendAndReceive <45> ( _                       ' VTable offset = 224
   )                                                    ' void
   ' =====================================================================================
   METHOD MarkAsRead <46> ( _                           ' VTable offset = 228
   )                                                    ' void
   ' =====================================================================================
   METHOD MarkAsUnread <47> ( _                         ' VTable offset = 232
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenSharedDefaultFolder <48> ( _              ' VTable offset = 236
     BYVAL bstrRecipient AS WSTRING _                   ' __in BSTR bstrRecipient
   , BYVAL FolderType AS LONG _                         ' __in OlxDefaultFolders FolderType
   )                                                    ' void
   ' =====================================================================================
   METHOD NewNote <49> ( _                              ' VTable offset = 240
   )                                                    ' void
   ' =====================================================================================
   METHOD NewDistributionList <50> ( _                  ' VTable offset = 244
   )                                                    ' void
   ' =====================================================================================
   METHOD AddressMessage <51> ( _                       ' VTable offset = 248
     BYVAL pdispContainer AS IDispatch _                ' __in IDispatch *pdispContainer
   )                                                    ' void
   ' =====================================================================================
   METHOD AddressMeeting <52> ( _                       ' VTable offset = 252
     BYVAL pdispContainer AS IDispatch _                ' __in IDispatch *pdispContainer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Dirty <53> ( _                          ' VTable offset = 256
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET Dirty <53> ( _                          ' VTable offset = 260
     BYVAL pVal AS INTEGER _                            ' __in VARIANT_BOOL pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveView <54> ( _                             ' VTable offset = 264
     BYVAL ViewName AS WSTRING _                        ' __in BSTR ViewName
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDesignMode <55> ( _                        ' VTable offset = 268
   )                                                    ' void
   ' =====================================================================================
   METHOD GoToDate <60> ( _                             ' VTable offset = 272
     BYVAL newDate AS WSTRING _                         ' __in BSTR newDate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Filter <63> ( _                         ' VTable offset = 276
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET Filter <63> ( _                         ' VTable offset = 280
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FilterAppend <64> ( _                   ' VTable offset = 284
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET FilterAppend <64> ( _                   ' VTable offset = 288
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ItemCount <65> ( _                      ' VTable offset = 292
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   METHOD RefreshFieldRegistry <66> ( _                 ' VTable offset = 296
     BYVAL fro AS LONG _                                ' __in FIELDREGISTRY_REFRESHOPTIONS fro
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableRowPersistance <67> ( _           ' VTable offset = 300
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET EnableRowPersistance <67> ( _           ' VTable offset = 304
     BYVAL pVal AS INTEGER _                            ' __in VARIANT_BOOL pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Selection <68> ( _                      ' VTable offset = 308
   ) AS IDispatch                                       ' __retval_out IDispatch **pVal
   ' =====================================================================================
   PROPERTY GET ViewXML <70> ( _                        ' VTable offset = 312
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET ViewXML <70> ( _                        ' VTable offset = 316
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelectedDate <71> ( _                   ' VTable offset = 320
   ) AS DOUBLE                                          ' __retval_out DATE *pVal
   ' =====================================================================================
   METHOD ExplorerActivate <61441> ( _                  ' VTable offset = 324
   )                                                    ' void
   ' =====================================================================================
   METHOD ExplorerSelectionChange <61447> ( _           ' VTable offset = 328
   )                                                    ' void
   ' =====================================================================================
   METHOD ExplorerViewSwitch <61444> ( _                ' VTable offset = 332
   )                                                    ' void
   ' =====================================================================================
   METHOD ExplorerBeforeViewSwitch <61445> ( _          ' VTable offset = 336
     BYVAL bStrNewView AS WSTRING _                     ' __in BSTR bStrNewView
   , BYREF pVarCancel AS INTEGER _                      ' __out VARIANT_BOOL *pVarCancel
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __OVCtl_IViewCtl_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDataCtl
' IID = {0468C084-CA5B-11D0-AF08-00609797F0E0}
' IDataCtl Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%OVCtl_IDataCtl_INTERFACE_DEFINED)
    %OVCtl_IDataCtl_INTERFACE_DEFINED = 1

INTERFACE OVCtl_IDataCtl $IID_OVCtl_IDataCtl

   INHERIT IUnknown

END INTERFACE

#ENDIF   ' /* __OVCtl_IDataCtl_INTERFACE_DEFINED__ */
