#INCLUDE THIS ONCE
%WIN32API_INC = 1

#INCLUDE ONCE "windows.inc"

' // For compatibility with the PB includes
#INCLUDE ONCE "Excpt.inc"
#INCLUDE ONCE "CommDlg.inc"
#INCLUDE ONCE "CommCtrl.inc"
#INCLUDE ONCE "UrlMon.inc"
#INCLUDE ONCE "WindowsX.inc"

' // Note: For some reason, shlobj.inc adds 5632 bytes to the disk size of the application,
' // although not to the image size.
#INCLUDE ONCE "ShlObj.inc"

' --- Windows Common Controls wrappers ---

#INCLUDE ONCE "AnimateCtrl.inc"
#INCLUDE ONCE "ButtonCtrl.inc"
#INCLUDE ONCE "ComboBoxCtrl.inc"
#INCLUDE ONCE "ComboBoxExCtrl.inc"
#INCLUDE ONCE "DateTimeCtrl.inc"
#INCLUDE ONCE "EditCtrl.inc"
#INCLUDE ONCE "HeaderCtrl.inc"
#INCLUDE ONCE "HotKeyCtrl.inc"
#INCLUDE ONCE "IPAddressCtrl.inc"
#INCLUDE ONCE "ListBoxCtrl.inc"
#INCLUDE ONCE "ListViewCtrl.inc"
#INCLUDE ONCE "MonthCalCtrl.inc"
#INCLUDE ONCE "PagerCtrl.inc"
#INCLUDE ONCE "ProgressBarCtrl.inc"
#INCLUDE ONCE "RebarCtrl.inc"
#INCLUDE ONCE "RichEditCtrl.inc"
#INCLUDE ONCE "ScrollBarCtrl.inc"
#INCLUDE ONCE "StaticCtrl.inc"
#INCLUDE ONCE "StatusbarCtrl.inc"
#INCLUDE ONCE "SysLinkCtrl.inc"
#INCLUDE ONCE "TabCtrl.inc"
#INCLUDE ONCE "TaskDialogCtrl.inc"
#INCLUDE ONCE "ToolbarCtrl.inc"
#INCLUDE ONCE "TrackbarCtrl.inc"
#INCLUDE ONCE "TreeViewCtrl.inc"
#INCLUDE ONCE "UpDownCtrl.inc"

