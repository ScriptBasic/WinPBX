' ########################################################################################
' Microsoft Windows
' File: InetReg.inc
' Contents: String literals for HKEYs in registry
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%INETREG_INC = 1

#INCLUDE ONCE "windows.inc"

'//
'// HKEY: HKEY_CURRENT_USER
'//

'//
'// Top level defines
'//
$TSZMICROSOFTPATH = "Software\Microsoft"
$TSZIEPATH        = $TSZMICROSOFTPATH & "\Internet Explorer"
$TSZWINCURVERPATH = $TSZMICROSOFTPATH & "\windows\CurrentVersion"
$TSZWININETPATH   = $TSZWINCURVERPATH & "\Internet Settings"

'// Windows : HKLM
$REGSTR_PATH_RUNONCE_KEY = $TSZWINCURVERPATH & "\RunOnce"

'// INETCPL : HKLM
$REGSTR_PATH_INETCPL_PS_EXTENTIONS = $TSZWINCURVERPATH & "\Controls Folder\Internet"

'//
'// Explorer : HKCU
'//
$REGSTR_PATH_IEXPLORER           = $TSZIEPATH

'// Main
$SZ_IE_MAIN                      = "Main"
$REGSTR_PATH_MAIN                = $TSZIEPATH & "\" & $SZ_IE_MAIN
$REGSTR_KEY_MAIN                 = $SZ_IE_MAIN

$REGSTR_VAL_SMOOTHSCROLL         = "SmoothScroll"
%REGSTR_VAL_SMOOTHSCROLL_DEF     = %TRUE

$REGSTR_VAL_SHOWTOOLBAR          = "Show_ToolBar"
$REGSTR_VAL_SHOWADDRESSBAR       = "Show_URLToolBar"
$REGSTR_VAL_STARTPAGE            = "Start Page"
$REGSTRA_VAL_STARTPAGE           = "Start Page"
$REGSTR_VAL_SEARCHPAGE           = "Search Page"
$REGSTR_VAL_LOCALPAGE            = "Local Page"

$REGSTR_VAL_USESTYLESHEETS       = "Use Stylesheets"
%REGSTR_VAL_USESTYLESHEETS_TYPE  = %REG_SZ  ' // "yes" or "no"
$REGSTR_VAL_USESTYLESHEETS_DEF   = "yes"

$REGSTR_VAL_USEICM               = "UseICM"
%REGSTR_VAL_USEICM_DEF           = %FALSE

$REGSTR_VAL_SHOWFOCUS            = "Tabstop - MouseDown"
%REGSTR_VAL_SHOWFOCUS_TYPE       = %REG_SZ  ' // "yes" or "no"
$REGSTR_VAL_SHOWFOCUS_DEF        = "no"

$REGSTR_VAL_LOADIMAGES           = "Display Inline Images"
$REGSTR_VAL_PLAYSOUNDS           = "Play_Background_Sounds"
$REGSTR_VAL_PLAYVIDEOS           = "Display Inline Videos"
$REGSTR_VAL_ANCHORUNDERLINE      = "Anchor Underline"
$REGSTR_VAL_USEDLGCOLORS         = "Use_DlgBox_Colors"
$REGSTR_VAL_CHECKASSOC           = "Check_Associations"
$REGSTR_VAL_SHOWFULLURLS         = "Show_FullURL"
$REGSTR_VAL_AUTOSEARCH           = "Do404Search"
$REGSTR_VAL_AUTONAVIGATE         = "SearchForExtensions"
$REGSTR_VAL_HTTP_ERRORS          = "Friendly http errors"

$REGSTR_VAL_PAGETRANSITIONS      = "Page_Transitions"
%REGSTR_VAL_PAGETRANSITIONS_DEF  = %TRUE

$REGSTR_VAL_USEIBAR              = "UseBar"

'// Settings
$SZ_IE_SETTINGS = "Settings"
$REGSTR_PATH_IE_SETTINGS         = $TSZIEPATH & "\" & $SZ_IE_SETTINGS
$REGSTR_KEY_IE_SETTINGS          = $SZ_IE_SETTINGS

$REGSTR_VAL_IE_CUSTOMCOLORS      = "Custom Colors"
%REGSTR_VAL_IE_CUSTOMCOLORS_TYPE = %REG_BINARY

$REGSTR_VAL_ANCHORCOLOR          = "Anchor Color"
$REGSTR_VAL_ANCHORCOLORVISITED   = "Anchor Color Visited"
$REGSTR_VAL_BACKGROUNDCOLOR      = "Background Color"
$REGSTR_VAL_TEXTCOLOR            = "Text Color"
$REGSTR_VAL_ANCHORCOLORHOVER     = "Anchor Color Hover"
$REGSTR_VAL_USEHOVERCOLOR        = "Use Anchor Hover Color"

'// Security
$SZ_IE_SECURITY = "Security"
$REGSTR_PATH_IE_SECURITY         = $TSZIEPATH & "\" & $SZ_IE_SECURITY
$REGSTR_KEY_IE_SECURITY          = $SZ_IE_SECURITY

$REGSTR_VAL_SAFETYWARNINGLEVEL   = "Safety Warning Level"

'// HTML Editing
$SZ_IE_DEFAULT_HTML_EDITOR       = "Default HTML Editor"
$REGSTR_PATH_DEFAULT_HTML_EDITOR = $TSZIEPATH & "\" & $SZ_IE_DEFAULT_HTML_EDITOR
$REGSTR_KEY_DEFAULT_HTML_EDITOR  = $SZ_IE_DEFAULT_HTML_EDITOR

'// Autocomplete
$REGSTR_PATH_AUTOCOMPLETE        = $TSZWINCURVERPATH & "\Explorer\AutoComplete"
$REGSTR_VAL_USEAUTOAPPEND        = "Append Completion"
$REGSTR_VAL_USEAUTOSUGGEST       = "AutoSuggest"

'// Old IE4 autocomplete key
$REGSTR_VAL_USEAUTOCOMPLETE      = "Use AutoComplete"

'// iBar
$SZ_IE_IBAR                      = "Bar"
$TSZIBARPATH                     = $TSZIEPATH & "\" & $SZ_IE_IBAR
$REGSTR_PATH_IBAR                = $TSZIBARPATH
$REGSTR_KEY_IBAR                 = $SZ_IE_IBAR

$SZ_IE_IBAR_BANDS                = "Bands"
$REGSTR_PATH_IBAR_BANDS          = $TSZIBARPATH & "\" & $SZ_IE_IBAR_BANDS
$REGSTR_KEY_IBAR_BANDS           = $SZ_IE_IBAR_BANDS


'//
'// Internet : HKCU
'//
'// path to global internet settings (also under HKEY_CURRENT_USER)
$REGSTR_PATH_INTERNETSETTINGS    = $TSZWININETPATH
$REGSTR_PATH_INTERNET_SETTINGS   = $REGSTR_PATH_INTERNETSETTINGS

$REGSTR_VAL_USERAGENT            = "User Agent"

'// path to lan-specific settings
$REGSTR_PATH_INTERNET_LAN_SETTINGS = $REGSTR_PATH_INTERNETSETTINGS & "\LAN"

'// string value under HKCU\REGSTR_PATH_REMOTEACCESS that contains name of
'// connectoid used to connect to internet
$REGSTR_VAL_INTERNETENTRY        = "InternetProfile"
$REGSTR_VAL_INTERNETPROFILE      = $REGSTR_VAL_INTERNETENTRY

$REGSTR_VAL_INTERNETENTRYBKUP    = "BackupInternetProfile"

$REGSTR_VAL_CODEDOWNLOAD         = "Code Download"
$REGSTR_VAL_CODEDOWNLOAD_DEF     = "yes"
%REGSTR_VAL_CODEDOWNLOAD_TYPE    = %REG_SZ   ' // "yes" or "no"

'// policy key for inetcpl restrictions

$REGSTR_PATH_INETCPL_RESTRICTIONS  = "Software\Policies\Microsoft\Internet Explorer\Control Panel"

'// reg valuenames to restrict whether a tab should be shown or not;
'// a value of non-zero means don't show that tab.
'// reg key: HKCU\Software\Policies\Microsoft\Internet Explorer\Control Panel
$REGSTR_VAL_INETCPL_GENERALTAB     = "GeneralTab"
$REGSTR_VAL_INETCPL_SECURITYTAB    = "SecurityTab"
$REGSTR_VAL_INETCPL_CONTENTTAB     = "ContentTab"
$REGSTR_VAL_INETCPL_CONNECTIONSTAB = "ConnectionsTab"
$REGSTR_VAL_INETCPL_PROGRAMSTAB    = "ProgramsTab"
$REGSTR_VAL_INETCPL_ADVANCEDTAB    = "AdvancedTab"
$REGSTR_VAL_INETCPL_PRIVACYTAB     = "PrivacyTab"

'// setting to indicate whether or not IEAK launched this instance of inetcpl so extra
'// info can be exposed
'// reg key: HKCU\Software\Policies\Microsoft\Internet Explorer\Control Panel
$REGSTR_VAL_INETCPL_IEAK           = "IEAKContext"

'//
'//  Cache
'//
$REGSTR_PATH_CACHE = $REGSTR_PATH_INTERNETSETTINGS & "\Cache"

$REGSTR_PATH_CACHE_PATHS = $REGSTR_PATH_CACHE & "\Paths"

$REGSTR_PATH_EXTENSIBLE_CACHE = $REGSTR_PATH_CACHE & "\Extensible Cache"

$REGSTR_PATH_TRACKING = $REGSTR_PATH_EXTENSIBLE_CACHE & "\Log"

$REGSTR_PATH_CACHE_SPECIAL_PATHS = $REGSTR_PATH_CACHE & "Special Paths"

$REGSTR_VAL_DIRECTORY            = "Directory"
%REGSTR_VAL_DIRECTORY_TYPE       = 2   ' REG_EXPAND_SZ

$REGSTR_VAL_NEWDIRECTORY         = "NewDirectory"
%REGSTR_VAL_NEWDIRECTORY_TYPE    = 2   ' REG_EXPAND_SZ

$REGSTR_VAL_CACHEPREFIX          = "CachePrefix"
%REGSTR_VAL_CACHEPREFIX_TYPE     = %REG_SZ

$REGSTR_PATH_URLHISTORY = $REGSTR_PATH_INTERNETSETTINGS & "\Url History"

$REGSTR_PATH_SUBSCRIPTION = $REGSTR_PATH_INTERNETSETTINGS & "\Subscription Folder"

'//
'// Search Format Strings
'//
$SZ_IE_SEARCHSTRINGS             = "UrlTemplate"
$REGSTR_PATH_SEARCHSTRINGS       = $REGSTR_PATH_MAIN & "\" & $SZ_IE_SEARCHSTRINGS
$REGSTR_KEY_SEARCHSTRINGS        = $SZ_IE_SEARCHSTRINGS

%MAX_SEARCH_FORMAT_STRING        = 255

'//
'// Server error page dispaly/don't display length thresholds.
'//
$SZ_IE_THRESHOLDS                = "ErrorThresholds"
$REGSTR_PATH_THRESHOLDS          = $REGSTR_PATH_MAIN & "\" & $SZ_IE_THRESHOLDS


'//
'// Access Medium
'//
$REGSTR_VAL_ACCESSMEDIUM         = "AccessMedium"
'// access type (MSN, other)
$REGSTR_VAL_ACCESSTYPE           = "AccessType"

'//
'// AutoDial
'//
'// name of connectoid-specific autodial handler dll and function
$REGSTR_VAL_AUTODIALDLLNAME      = "AutodialDllName"
$REGSTR_VAL_AUTODIALFCNNAME      = "AutodialFcnName"
'// class name for window to receive Winsock activity messages
$REGSTR_VAL_AUTODIAL_MONITORCLASSNAME    = "MS_AutodialMonitor"
$REGSTR_VAL_AUTODIAL_TRYONLYONCE         = "TryAutodialOnce"

'//
'// Remote Access
'//
'// path to RNA values (under HKEY_CURRENT_USER)
$REGSTR_PATH_REMOTEACCESS        = "RemoteAccess"
$REGSTR_PATH_REMOTEACESS         = $REGSTR_PATH_REMOTEACCESS
'// this is under HKLM... we are using this to determine if RNA is installed
'// or not. We can't rely on finding the DLL since removing this component
'// with the control panel's "Add/Remove Software" does not remove the RNAdll.
$REGSTR_PATH_RNACOMPONENT    = $TSZWINCURVERPATH & "\Setup\OptionalComponents\RNA"
$REGSTR_VAL_RNAINSTALLED     = "Installed"

'// values under HKCU\REGSTR_PATH_INTERNET_SETTINGS

'// 4-byte REG_BINARY, autodialing is enabled if this value is present and
'// non-zero, disabled otherwise
'// If ForceAutodial is true, will always dial similar to IE4 behavior.
'// If it's false, will only dial if network is not available.
$REGSTR_VAL_ENABLEAUTODIAL               = "EnableAutodial"
$REGSTR_VAL_ENABLEUNATTENDED             = "EnableUnattended"
$REGSTR_VAL_NONETAUTODIAL                = "NoNetAutodial"

$REGSTR_VAL_REDIALATTEMPTS               = "RedialAttempts"
$REGSTR_VAL_REDIALINTERVAL               = "RedialWait"

$REGSTR_VAL_ENABLEAUTODIALDISCONNECT     = "EnableAutodisconnect"
$REGSTR_VAL_ENABLEAUTODISCONNECT         = $REGSTR_VAL_ENABLEAUTODIALDISCONNECT
$REGSTR_VAL_ENABLEEXITDISCONNECT         = "EnableExitDisconnect"

$REGSTR_VAL_ENABLESECURITYCHECK          = "EnableSecurityCheck"

$REGSTR_VAL_COVEREXCLUDE                 = "CoverExclude"
'// 4-byte REG_BINARY containing number of minutes of idle time to allow
'// before autodisconnect.  Autodisconnect is disabled if this value is zero
'// or not present.
$REGSTR_VAL_DISCONNECTIDLETIME   = "DisconnectIdleTime"

'//
'// MOS
'//
$REGSTR_PATH_MOSDISCONNECT       = $TSZMICROSOFTPATH & "\MOS\Preferences"
$REGSTR_VAL_MOSDISCONNECT        = "DisconnectTimeout"

'//
'// Proxy : These are under REGSTR_PATH_INTERNETSETTINGS
'//
$REGSTR_VAL_PROXYENABLE          = "ProxyEnable"
$REGSTR_VAL_PROXYSERVER          = "ProxyServer"
$REGSTR_VAL_PROXYOVERRIDE        = "ProxyOverride"
$REGSTR_VAL_BYPASSAUTOCONFIG     = "BypassAutoconfig"



'//
'// Security : HKCU\\WININETPATH
'//
$SZTRUSTWARNLEVEL                    = "Trust Warning Level"
$REGSTR_KEY_TRUSTWARNINGLEVEL        = $TSZWININETPATH  & $SZTRUSTWARNLEVEL
$REGSTR_VAL_TRUSTWARNINGLEVEL        = $SZTRUSTWARNLEVEL   ' //"none" will turn off WinVerifyTrust warnings.
%REGSTR_VAL_TRUSTWARNINGLEVEL_TYPE   = %REG_SZ
$REGSTR_VAL_TRUSTWARNINGLEVEL_HIGH   = "High"
$REGSTR_VAL_TRUSTWARNINGLEVEL_MED    = "Medium"
$REGSTR_VAL_TRUSTWARNINGLEVEL_LOW    = "No Security"
'// default depends on MSHTML's prefs nSafetyWarningLevel

$REGSTR_VAL_SECURITYWARNONSEND       = "WarnOnPost"
%REGSTR_VAL_SECURITYWARNONSEND_TYPE  = %REG_BINARY
%REGSTR_VAL_SECURITYWARNONSEND_DEF   = %TRUE

$REGSTR_VAL_SECURITYWARNONSENDALWAYS         = "WarnAlwaysOnPost"
%REGSTR_VAL_SECURITYWARNONSENDALWAYS_TYPE    = %REG_BINARY  ' // FALSE-Only if... TRUE-Always
%REGSTR_VAL_SECURITYWARNONSENDALWAYS_DEF     = %TRUE

$REGSTR_VAL_SECURITYWARNONVIEW       = "WarnOnView"
%REGSTR_VAL_SECURITYWARNONVIEW_TYPE  = %REG_BINARY
%REGSTR_VAL_SECURITYWARNONVIEW_DEF   = %TRUE

$REGSTR_VAL_SECURITYALLOWCOOKIES         = "AllowCookies"
%REGSTR_VAL_SECURITYALLOWCOOKIES_TYPE    = %REG_BINARY
%REGSTR_VAL_SECURITYALLOWCOOKIES_DEF     = %TRUE

$REGSTR_VAL_SECURITYWARNONZONECROSSING       = "WarnOnZoneCrossing"
%REGSTR_VAL_SECURITYWARNONZONECROSSING_TYPE  = %REG_BINARY
%REGSTR_VAL_SECURITYWARNONZONECROSSING_DEF   = %TRUE

$REGSTR_VAL_SECURITYWARNONBADCERTVIEWING         = "WarnOnBadCertRecving"
%REGSTR_VAL_SECURITYWARNONBADCERTVIEWING_TYPE    = %REG_BINARY
%REGSTR_VAL_SECURITYWARNONBADCERTVIEWING_DEF     = %TRUE

$REGSTR_VAL_SECURITYWARNONBADCERTSENDING         = "WarnOnBadCertSending"
%REGSTR_VAL_SECURITYWARNONBADCERTSENDING_TYPE    = %REG_BINARY
%REGSTR_VAL_SECURITYWARNONBADCERTSENDING_DEF     = %TRUE

$REGSTR_VAL_SECURITYDISABLECACHINGOFSSLPAGES       = "DisableCachingOfSSLPages"
%REGSTR_VAL_SECURITYDISABLECACHINGOFSSLPAGES_TYPE  = %REG_DWORD
%REGSTR_VAL_SECURITYDISABLECACHINGOFSSLPAGES_DEF   = %FALSE


'//
'// Run/Show ActiveX / Java : These are under REGSTR_PATH_INTERNETSETTINGS
'//
$REGSTR_VAL_SECURITYACTIVEX              = "Security_RunActiveXControls"
%REGSTR_VAL_SECURITYACTIVEX_TYPE         = %REG_BINARY  ' // TRUE or FALSE
%REGSTR_VAL_SECURITYACTIVEX_DEF          = %TRUE

$REGSTR_VAL_SECURITYACTICEXSCRIPTS       = "Security_RunScripts"
%REGSTR_VAL_SECURITYACTICEXSCRIPTS_TYPE  = %REG_BINARY  ' // TRUE or FALSE
%REGSTR_VAL_SECURITYACTICEXSCRIPTS_DEF   = %TRUE

$REGSTR_VAL_SECURITYJAVA                 = "Security_RunJavaApplets"
%REGSTR_VAL_SECURITYJAVA_TYPE            = %REG_BINARY  ' // TRUE or FALSE
%REGSTR_VAL_SECURITYJAVA_DEF             = %TRUE

'//
'// Java VM exclusively : HKCU
'//
$SZJAVAVMPATH                            = "\\Java VM"
$REGSTR_PATH_JAVAVM                      = $TSZMICROSOFTPATH & $SZJAVAVMPATH

$REGSTR_VAL_JAVAJIT                      = "EnableJIT"
%REGSTR_VAL_JAVAJIT_TYPE                 = %REG_DWORD   ' // TRUE or FALSE
%REGSTR_VAL_JAVAJIT_DEF                  = %FALSE

$REGSTR_VAL_JAVALOGGING                  = "EnableLogging"
%REGSTR_VAL_JAVALOGGING_TYPE             = %REG_DWORD   ' // TRUE or FALSE
%REGSTR_VAL_JAVALOGGING_DEF              = %FALSE


'//
'// QuickLinks
'//
'// this is where custom quicklinks are stored
$SZTOOLBAR               = "\Toolbar"
$TSZTOOLBAR              = $SZTOOLBAR
$REGSTR_PATH_TOOLBAR     = $TSZIEPATH & $SZTOOLBAR
$REGSTR_KEY_QUICKLINKS   = $TSZIEPATH & $TSZTOOLBAR & "\Links"
$REGSTR_VAL_DAYSTOKEEP   = "DaysToKeep"

$SZNOTEXT                = "NoText"
$REGSTR_VAL_NOTEXT       = $SZNOTEXT
$REGSTR_KEY_NOTEXT       = $TSZIEPATH & $TSZTOOLBAR & "\" & $SZNOTEXT
$SZVISIBLE               = "VisibleBands"
$REGSTR_VAL_VISIBLE      = $SZVISIBLE
$REGSTR_KEY_VISIBLE      = $TSZIEPATH & $TSZTOOLBAR & "\" & $SZVISIBLE


$REGSTR_VAL_VISIBLEBANDS         = "VisibleBands"
%REGSTR_VAL_VISIBLEBANDS_TYPE    = 4      ' REG_DWORD   // 3 bits (see below)
%REGSTR_VAL_VISIBLEBANDS_DEF     = &H7    ' // all three bands
%TOOLSBAND                       = &H1
%ADDRESSBAND                     = &H2
%LINKSBAND                       = &H4

$SZBACKBITMAP                = "BackBitmap"
$REGSTR_VAL_BACKBITMAP       = "BackBitmap"
%REGSTR_VAL_BACKBITMAP_TYPE  = %REG_SZ
'// "" = no bitmap or fillin with valid path, delete for default

$REGSTR_KEY_BACKBITMAP   = $TSZIEPATH & $TSZTOOLBAR & "\" & $SZBACKBITMAP

$REGSTR_PATH_QUICKCOMPLETE = $REGSTR_PATH_TOOLBAR & "\" & "QuickComplete"
$REGSTR_SHIFTQUICKSUFFIX = "ShiftQuickCompleteSuffix"

'//
'// Schannel Settings: HKLM
'//

$TSZSCHANNELPATH             = "SYSTEM\CurrentControlSet\Control\SecurityProviders\SCHANNEL"
$TSZSCHANNELPROTOCOLSPATH    = $TSZSCHANNELPATH & "\\Protocols"

$REGSTR_PATH_PCT1            = $TSZSCHANNELPROTOCOLSPATH & "\PCT 1.0\Client"
$REGSTR_PATH_SSL2            = $TSZSCHANNELPROTOCOLSPATH & "\SSL 2.0\Client"
$REGSTR_PATH_SSL3            = $TSZSCHANNELPROTOCOLSPATH & "\SSL 3.0\Client"
$REGSTR_PATH_UNIHELLO        = $TSZSCHANNELPROTOCOLSPATH & "\Multi-Protocol Unified Hello\Client"

$REGSTR_VAL_SCHANNELENABLEPROTOCOL         = "Enabled"
%REGSTR_VAL_SCHANNELENABLEPROTOCOL_TYPE    = %REG_DWORD
%REGSTR_VAL_SCHANNELENABLEPROTOCOL_DEF     = %TRUE


'//
'// Mail and News: HKLM
'//

$TSZINTERNETCLIENTSPATH      = "Software\\Clients"
$REGSTR_PATH_MAILCLIENTS     = $TSZINTERNETCLIENTSPATH  & "\Mail"
$REGSTR_PATH_NEWSCLIENTS     = $TSZINTERNETCLIENTSPATH  & "\News"
$REGSTR_PATH_CALENDARCLIENTS = $TSZINTERNETCLIENTSPATH  & "\Calendar"
$REGSTR_PATH_CONTACTCLIENTS  = $TSZINTERNETCLIENTSPATH  & "\Contacts"
$REGSTR_PATH_CALLCLIENTS     = $TSZINTERNETCLIENTSPATH  & "\Internet Call"

'// this is under the mail and news paths
$TSZPROTOCOLSPATH            = "Protocols\"
'// and one these is under the protocols path
$TSZMAILTOPROTOCOL           = "mailto"
$TSZNEWSPROTOCOL             = "news"
$TSZCALLTOPROTOCOL           = "callto"
$TSZLDAPPROTOCOL             = "ldap"
$TSZCALENDARPROTOCOL         = "unk"

'//
'// International and Fonts: HKCU\\TSZIEPATH
'//
$REGSTR_PATH_INTERNATIONAL   = $TSZIEPATH & "\International"

$REGSTR_PATH_INTERNATIONAL_SCRIPTS = $TSZIEPATH & "\International\Scripts"

$REGSTR_VAL_DEFAULT_CODEPAGE         = "Default_CodePage"
%REGSTR_VAL_DEFAULT_CODEPAGE_TYPE    = %REG_SZ  ' // code page
'                   // will grab default from system if not found

$REGSTR_VAL_DEFAULT_SCRIPT         = "Default_Script"
%REGSTR_VAL_DEFAULT_SCRIPT_TYPE    = %REG_SZ
                                         ' // will grab default from system if not found


$REGSTR_VAL_ACCEPT_LANGUAGE          = "AcceptLanguage"
%REGSTR_VAL_ACCETP_LANGUAGE_TYPE     = %REG_SZ


'// each CHARSET has a unique key under REGSTR_PATH_INTERNATIONAL
'// which has the following values defined
$REGSTR_VAL_FONT_SCRIPTS          = "Scripts"
$REGSTR_VAL_FONT_SCRIPT           = "Script"
%REGSTR_VAL_FONT_SCRIPT_TYPE      = %REG_SZ  ' // friendly name of font if other than system
                                                  ' // no default

$REGSTR_VAL_FONT_SCRIPT_NAME           = "Script"
%REGSTR_VAL_FONT_SCRIPT_NAME_TYPE      = %REG_SZ


$REGSTR_VAL_DEF_ENCODING         = "Default_Encoding"
%REGSTR_VAL_DEF_ENCODING_TYPE    = %REG_SZ  ' // internal MIME table name
                                       '         // no default

$REGSTR_VAL_DEF_INETENCODING         = "Default_InternetEncoding"
%REGSTR_VAL_DEF_INETENCODING_TYPE    = %REG_DWORD
                                           ' // no default

$REGSTR_VAL_FIXED_FONT       = "IEFixedFontName"
%REGSTR_VAL_FIXED_FONT_TYPE  = %REG_SZ  ' // must match a registered font name
                                   '         // no default

$REGSTR_VAL_SCRIPT_FIXED_FONT       = "IEFixedFontName"
%REGSTR_VAL_SCRIPT_FIXED_FONT_TYPE  = %REG_SZ  ' // must match a registered font name
                                          '         // no default

$REGSTR_VAL_PROP_FONT        = "IEPropFontName"
%REGSTR_VAL_PROP_FONT_TYPE   = %REG_SZ  ' // must match a registered font name
                                   '         // no default

$REGSTR_VAL_SCRIPT_PROP_FONT        = "IEPropFontName"
%REGSTR_VAL_SCRIPT_PROP_FONT_TYPE   = %REG_SZ  ' // must match a registered font name
                                          '         // no default

$REGSTR_VAL_FONT_SIZE        = "IEFontSize"
%REGSTR_VAL_FONT_SIZE_TYPE   = %REG_BINARY
%REGSTR_VAL_FONT_SIZE_DEF    = 2   ' // default size : Medium

$REGSTR_VAL_AUTODETECT         = "AutoDetect"
%REGSTR_VAL_AUTODETECT_TYPE    = %REG_SZ

'// MIME database charset extension
$REGSTR_PATH_MIME_DATABASE           = "MIME\Database"
$REGSTR_KEY_MIME_DATABASE_CHARSET    = $REGSTR_PATH_MIME_DATABASE & "\Charset"
$REGSTR_KEY_MIME_DATABASE_CODEPAGE   = $REGSTR_PATH_MIME_DATABASE & "\CodePage"
$REGSTR_KEY_MIME_DATABASE_RFC1766    = $REGSTR_PATH_MIME_DATABASE & "\Rfc1766"

$REGSTR_VAL_CODEPAGE                 = "CodePage"
%REGSTR_VAL_CODEPAGE_TYPE            = %REG_DWORD

$REGSTR_VAL_INETENCODING             = "InternetEncoding"
%REGSTR_VAL_INETENCODING_TYPE        = %REG_DWORD

$REGSTR_VAL_FAMILY                   = "Family"
%REGSTR_VAL_FAMILY_TYPE              = %REG_DWORD

$REGSTR_VAL_LEVEL                    = "Level"
%REGSTR_VAL_LEVEL_TYPE               = %REG_DWORD

$REGSTR_VAL_ALIASTO                  = "AliasForCharset"
%REGSTR_VAL_ALIASTO_TYPE             = %REG_SZ

$REGSTR_VAL_ENCODENAME               = "EncodingName"
%REGSTR_VAL_ENCODENAME_TYPE          = %REG_SZ

$REGSTR_VAL_DESCRIPTION              = "Description"
%REGSTR_VAL_DESCRIPTION_TYPE         = %REG_SZ

$REGSTR_VAL_WEBCHARSET               = "WebCharset"
%REGSTR_VAL_WEBCHARSET_TYPE          = %REG_SZ

$REGSTR_VAL_BODYCHARSET              = "BodyCharset"
%REGSTR_VAL_BODYCHARSET_TYPE         = %REG_SZ

$REGSTR_VAL_HEADERCHARSET            = "HeaderCharset"
%REGSTR_VAL_HEADERCHARSET_TYPE       = %REG_SZ

$REGSTR_VAL_FIXEDWIDTHFONT           = "FixedWidthFont"
%REGSTR_VAL_FIXEDWIDTHFONT_TYPE      = %REG_SZ

$REGSTR_VAL_PROPORTIONALFONT         = "ProportionalFont"
%REGSTR_VAL_PROPOPRTIONALFONT_TYPE   = %REG_SZ

$REGSTR_VAL_PRIVCONVERTER            = "PrivConverter"
%REGSTR_VAL_PRIVCONVERTER_TYPE       = %REG_SZ

$REGSTR_PATH_DEFAULT_FEEDS = $REGSTR_PATH_MAIN & "\Default Feeds"
