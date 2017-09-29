' ########################################################################################
' Microsoft Windows
' File: TaskDialogCtrl.inc
' Contents: Task Dialog Wrapper Functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TASKDIALOGCTRL_INC = 1

#INCLUDE ONCE "commctrl.inc"

' ========================================================================================
' Simulates the action of a button click in the Task Dialog.
' ========================================================================================
FUNCTION TaskDialog_ClickButton (BYVAL hTaskDlg AS DWORD, BYVAL nButton AS DWORD) AS LONG
   FUNCTION = SendMessage(hTaskDlg, %TDM_CLICK_BUTTON, nButton, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Simulates the action of a radio button click in the TaskDialog.
' ========================================================================================
FUNCTION TaskDialog_ClickRadioButton (BYVAL hTaskDlg AS DWORD, BYVAL nRadioButton AS DWORD) AS LONG
   FUNCTION = SendMessage(hTaskDlg, %TDM_CLICK_RADIO_BUTTON, nRadioButton, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Simulates a click on the verification checkbox of the Task Dialog, if it exists.
' ========================================================================================
SUB TaskDialog_ClickVerification (BYVAL hTaskDlg AS DWORD, BYVAL fChecked AS LONG, BYVAL fFocused AS LONG)
   SendMessage hTaskDlg, %TDM_CLICK_VERIFICATION, fChecked, fFocused
END SUB
' ========================================================================================

' ========================================================================================
' Enables or disables a push button in the TaskDialog.
' ========================================================================================
SUB TaskDialog_EnableButton (BYVAL hTaskDlg AS DWORD, BYVAL nButton AS LONG, BYVAL fEnable AS LONG)
   SendMessage hTaskDlg, %TDM_ENABLE_BUTTON, nButton, fEnable
END SUB
' ========================================================================================

' ========================================================================================
' Enables or disables a radio button in the TaskDialog.
' ========================================================================================
SUB TaskDialog_EnableRadioButton (BYVAL hTaskDlg AS DWORD, BYVAL nRadioButton AS LONG, BYVAL fEnable AS LONG)
   SendMessage hTaskDlg, %TDM_ENABLE_RADIO_BUTTON, nRadioButton, fEnable
END SUB
' ========================================================================================

' ========================================================================================
' Refreshes the contents of the Task Dialog.
' ========================================================================================
SUB TaskDialog_NavigatePage (BYVAL hTaskDlg AS DWORD, BYREF pTaskConfig AS TASKDIALOGCONFIG)
   SendMessage hTaskDlg, %TDM_NAVIGATE_PAGE, 0, VARPTR(pTaskConfig)
END SUB
' ========================================================================================

' ========================================================================================
' Used by clients to designate whether a given Task Dialog button or command link should
' have a User Account Control (UAC) shield icon (in other words, whether the action
' invoked by the button requires elevation).
' ========================================================================================
SUB TaskDialog_SetButtonElevationRequiredState (BYVAL hTaskDlg AS DWORD, BYVAL nButton AS LONG, BYVAL fElevation AS LONG)
   SendMessage hTaskDlg, %TDM_SET_BUTTON_ELEVATION_REQUIRED_STATE, nButton, fElevation
END SUB
' ========================================================================================

' ========================================================================================
' Used by clients to update a text element on the Task Dialog.
' ========================================================================================
SUB TaskDialog_SetElementText (BYVAL hTaskDlg AS DWORD, BYVAL eElement AS LONG, BYREF pszNewText AS WSTRINGZ)
   SendMessage hTaskDlg, %TDM_SET_ELEMENT_TEXT, eElement, VARPTR(pszNewText)
END SUB
' ========================================================================================

' ========================================================================================
' Indicates whether the hosted progress bar should be displayed in marquee mode.
' ========================================================================================
SUB TaskDialog_SetMarqueeProgressBar (BYVAL hTaskDlg AS DWORD, BYVAL fMarquee AS LONG)
   SendMessage hTaskDlg, %TDM_SET_MARQUEE_PROGRESS_BAR, fMarquee, 0
END SUB
' ========================================================================================

' ========================================================================================
' Starts and stops the marquee display of the progress bar, and sets the speed of the marquee.
' ========================================================================================
SUB TaskDialog_SetProgressBarMarquee (BYVAL hTaskDlg AS DWORD, BYVAL fMarquee AS LONG, BYVAL nSpeed AS LONG)
   SendMessage hTaskDlg, %TDM_SET_PROGRESS_BAR_MARQUEE, fMarquee, nSpeed
END SUB
' ========================================================================================

' ========================================================================================
' The TDM_SET_PROGRESS_BAR_POS message is used set the current position for a progress bar.
' ========================================================================================
FUNCTION TaskDialog_SetProgressBarPos (BYVAL hTaskDlg AS DWORD, BYVAL nNewPos AS LONG) AS LONG
   FUNCTION = SendMessage(hTaskDlg, %TDM_SET_PROGRESS_BAR_POS, nNewPos, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' The TDM_SET_PROGRESS_BAR_RANGE message is used set the minimum and maximum values for
' the hosted progress bar.
' ========================================================================================
FUNCTION TaskDialog_SetProgressBarRange (BYVAL hTaskDlg AS DWORD, BYVAL nMinRange AS LONG, BYVAL nMaxRange AS LONG) AS LONG
   FUNCTION = SendMessage(hTaskDlg, %TDM_SET_PROGRESS_BAR_RANGE, 0, MAK(LONG, nMinRange, nMaxRange))
END FUNCTION
' ========================================================================================

' ========================================================================================
' The TDM_SET_PROGRESS_BAR_POS message is used set the current position for a progress bar.
' ========================================================================================
FUNCTION TaskDialog_SetProgressBarState (BYVAL hTaskDlg AS DWORD, BYVAL nNewState AS LONG) AS LONG
   FUNCTION = SendMessage(hTaskDlg, %TDM_SET_PROGRESS_BAR_STATE, nNewState, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' The TDM_UPDATE_ELEMENT_TEXT message is available for use by clients to update a text
' element on the Task Dialog.
' ========================================================================================
SUB TaskDialog_UpdateElementText (BYVAL hTaskDlg AS DWORD, BYVAL eElement AS LONG, BYREF pszNewText AS WSTRINGZ)
   SendMessage hTaskDlg, %TDM_UPDATE_ELEMENT_TEXT, eElement, VARPTR(pszNewText)
END SUB
' ========================================================================================

' ========================================================================================
' Refreshes the icon of a task dialog. A window receives this message through its
' WindowProc function.
' ========================================================================================
SUB TaskDialog_UpdateIcon (BYVAL hTaskDlg AS DWORD, BYVAL nIconElement AS LONG, BYVAL idResource AS DWORD)
   SendMessage hTaskDlg, %TDM_UPDATE_ICON, nIconElement, idResource
END SUB
' ========================================================================================
