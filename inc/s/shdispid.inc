' ########################################################################################
' Microsoft Windows
' File: shdispid.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SHDISPID_INC = 1

'// define the events for the shell folder view
%DISPID_SELECTIONCHANGED       = 200    ' // The Selected Items Changed
%DISPID_FILELISTENUMDONE       = 201    ' // Done enumerating the shell folder
%DISPID_VERBINVOKED            = 202    ' // A verb (either from the main or context menu) was invoked in the folder view
%DISPID_DEFAULTVERBINVOKED     = 203    ' // default verb (either from the main or context menu) was invoked in the folder view
%DISPID_BEGINDRAG              = 204    ' // user clicked on an item
%DISPID_VIEWMODECHANGED        = 205    ' // The ListViewMode Changed
%DISPID_NOITEMSTATE_CHANGED    = 206    ' // We went from 0->some or some->0 items in the view
%DISPID_CONTENTSCHANGED        = 207    ' // contents of the view have changed somehow
%DISPID_FOCUSCHANGED           = 208    ' // The Focused Item Changed
%DISPID_CHECKSTATECHANGED      = 209    ' // Checkbox state changed.
%DISPID_ORDERCHANGED           = 210    ' // The order of items changed
%DISPID_VIEWPAINTDONE          = 211    ' // The enumerated items have been inserted into the view and painted
%DISPID_COLUMNSCHANGED         = 212    ' // The set of visible details columns changed
%DISPID_CTRLMOUSEWHEEL         = 213    ' // The mousewheel has been moved while the CTRL key was down
%DISPID_SORTDONE               = 214    ' // Done sorting the shell folder
%DISPID_ICONSIZECHANGED        = 215    ' // The icon size changed in the view

' Removed in the Windows 7 SDK
'%DISPID_ITEMSETOPERATIONSDONE  = 216    ' // Completely done navigating.  This includes enum, sort, filter, all background tasks.

%DISPID_FOLDERCHANGED          = 217    ' // The state of the folder has changed
%DISPID_FILTERINVOKED          = 218    ' // Some filter changed
%DISPID_WORDWHEELEDITED        = 219    ' // Text in WordWheel changed
%DISPID_SELECTEDITEMCHANGED    = 220    ' // One of the selected items has changed (not the same as a selection change)
%DISPID_EXPLORERWINDOWREADY    = 221    ' // Explorer window is open, been painted and is ready
%DISPID_UPDATEIMAGE            = 222    ' // A SHCNE_UPDATEIMAGE notification was received
%DISPID_INITIALENUMERATIONDONE = 223    ' // Used internally by specialized views like the start menu. Not fired when the data source finishes enumeration. To detect when the data source is done enumerating, use DISPID_FILELISTENUMDONE.

' // define the events for the ComboBoxEx control
%DISPID_ENTERPRESSED           = 200     ' // The user hit Enter or Return


'// Define Events for search object
%DISPID_SEARCHCOMMAND_START        = 1
%DISPID_SEARCHCOMMAND_COMPLETE     = 2
%DISPID_SEARCHCOMMAND_ABORT        = 3
%DISPID_SEARCHCOMMAND_UPDATE       = 4
%DISPID_SEARCHCOMMAND_PROGRESSTEXT = 5
%DISPID_SEARCHCOMMAND_ERROR        = 6
%DISPID_SEARCHCOMMAND_RESTORE      = 7


'// Shell Add/Remove Programs events
%DISPID_IADCCTL_DIRTY            = &H100
%DISPID_IADCCTL_PUBCAT           = &H101
%DISPID_IADCCTL_SORT             = &H102
%DISPID_IADCCTL_FORCEX86         = &H103
%DISPID_IADCCTL_SHOWPOSTSETUP    = &H104
%DISPID_IADCCTL_ONDOMAIN         = &H105
%DISPID_IADCCTL_DEFAULTCAT       = &H106
