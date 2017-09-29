' ########################################################################################
' Microsoft Windows
' File: vssym32.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

'//-------------------------------------------------------------------------//
'//  VisualStyle Core Win32/ComCtl32 symbols
'//-------------------------------------------------------------------------//

#INCLUDE THIS ONCE
%VSSYM32_INC = 1

#INCLUDE ONCE "VSStyle.inc"

'//
'//  enumerated property values
'//

' enum BGTYPE
%BT_IMAGEFILE  = 0
%BT_BORDERFILL = 1
%BT_NONE       = 2

'//
'//  enumerated property values
'//

' enum IMAGELAYOUT
%IL_VERTICAL   = 0
%IL_HORIZONTAL = 1

'//
'//  enumerated property values
'//

' enum BORDERTYPE
%BT_RECT      = 0
%BT_ROUNDRECT = 1
%BT_ELLIPSE   = 2

'//
'//  enumerated property values
'//

' enum FILLTYPE
%FT_SOLID          = 0
%FT_VERTGRADIENT   = 1
%FT_HORZGRADIENT   = 2
%FT_RADIALGRADIENT = 3
%FT_TILEIMAGE      = 4

'//
'//  enumerated property values
'//

%ST_TRUESIZE = 0
%ST_STRETCH  = 1
%ST_TILE     = 2

'//
'//  enumerated property values
'//

' enum HALIGN
%HA_LEFT   = 0
%HA_CENTER = 1
%HA_RIGHT  = 2

'//
'//  enumerated property values
'//

' enum CONTENTALIGNMENT
%CA_LEFT   = 0
%CA_CENTER = 1
%CA_RIGHT  = 2

'//
'//  enumerated property values
'//

' enum VALIGN
%VA_TOP    = 0
%VA_CENTER = 1
%VA_BOTTOM = 2

'//
'//  enumerated property values
'//

' enum OFFSETTYPE
%OT_TOPLEFT           = 0
%OT_TOPRIGHT          = 1
%OT_TOPMIDDLE         = 2
%OT_BOTTOMLEFT        = 3
%OT_BOTTOMRIGHT       = 4
%OT_BOTTOMMIDDLE      = 5
%OT_MIDDLELEFT        = 6
%OT_MIDDLERIGHT       = 7
%OT_LEFTOFCAPTION     = 8
%OT_RIGHTOFCAPTION    = 9
%OT_LEFTOFLASTBUTTON  = 10
%OT_RIGHTOFLASTBUTTON = 11
%OT_ABOVELASTBUTTON   = 12
%OT_BELOWLASTBUTTON   = 13

'//
'//  enumerated property values
'//

' enum ICONEFFECT {
%ICE_NONE   = 0
%ICE_GLOW   = 1
%ICE_SHADOW = 2
%ICE_PULSE  = 3
%ICE_ALPHA  = 4

'//
'//  enumerated property values
'//

' enum TEXTSHADOWTYPE {
%TST_NONE       = 0
%TST_SINGLE     = 1
%TST_CONTINUOUS = 2

'//
'//  enumerated property values
'//

' enum GLYPHTYPE
%GT_NONE       = 0
%GT_IMAGEGLYPH = 1
%GT_FONTGLYPH  = 2

'//
'//  enumerated property values
'//

' enum IMAGESELECTTYPE
%IST_NONE = 0
%IST_SIZE = 1
%IST_DPI  = 2

'//
'//  enumerated property values
'//

' enum TRUESIZESCALINGTYPE
%TSST_NONE = 0
%TSST_SIZE = 1
%TSST_DPI  = 2

'//
'//  enumerated property values
'//

' enum GLYPHFONTSIZINGTYPE
%GFST_NONE = 0
%GFST_SIZE = 1
%GFST_DPI  = 2

'//
'//  property symbol definitions
'//

%TMT_RESERVEDLOW             = 0
%TMT_RESERVEDHIGH            = 7999

%TMT_DIBDATA                 = 2
%TMT_GLYPHDIBDATA            = 8
%TMT_ENUM                    = 200
%TMT_STRING                  = 201
%TMT_INT                     = 202
%TMT_BOOL                    = 203
%TMT_COLOR                   = 204
%TMT_MARGINS                 = 205
%TMT_FILENAME                = 206
%TMT_SIZE                    = 207
%TMT_POSITION                = 208
%TMT_RECT                    = 209
%TMT_FONT                    = 210
%TMT_INTLIST                 = 211
%TMT_HBITMAP                 = 212
%TMT_DISKSTREAM              = 213
%TMT_STREAM                  = 214
%TMT_BITMAPREF               = 215
%TMT_COLORSCHEMES            = 401
%TMT_SIZES                   = 402
%TMT_CHARSET                 = 403
%TMT_NAME                    = 600
%TMT_DISPLAYNAME             = 601
%TMT_TOOLTIP                 = 602
%TMT_COMPANY                 = 603
%TMT_AUTHOR                  = 604
%TMT_COPYRIGHT               = 605
%TMT_URL                     = 606
%TMT_VERSION                 = 607
%TMT_DESCRIPTION             = 608
%TMT_FIRST_RCSTRING_NAME     = %TMT_DISPLAYNAME
%TMT_LAST_RCSTRING_NAME      = %TMT_DESCRIPTION
%TMT_CAPTIONFONT             = 801
%TMT_SMALLCAPTIONFONT        = 802
%TMT_MENUFONT                = 803
%TMT_STATUSFONT              = 804
%TMT_MSGBOXFONT              = 805
%TMT_ICONTITLEFONT           = 806
%TMT_HEADING1FONT            = 807
%TMT_HEADING2FONT            = 808
%TMT_BODYFONT                = 809
%TMT_FIRSTFONT               = %TMT_CAPTIONFONT
%TMT_LASTFONT                = %TMT_BODYFONT
%TMT_FLATMENUS               = 1001
%TMT_FIRSTBOOL               = %TMT_FLATMENUS
%TMT_LASTBOOL                = %TMT_FLATMENUS
%TMT_SIZINGBORDERWIDTH       = 1201
%TMT_SCROLLBARWIDTH          = 1202
%TMT_SCROLLBARHEIGHT         = 1203
%TMT_CAPTIONBARWIDTH         = 1204
%TMT_CAPTIONBARHEIGHT        = 1205
%TMT_SMCAPTIONBARWIDTH       = 1206
%TMT_SMCAPTIONBARHEIGHT      = 1207
%TMT_MENUBARWIDTH            = 1208
%TMT_MENUBARHEIGHT           = 1209
%TMT_PADDEDBORDERWIDTH       = 1210
%TMT_FIRSTSIZE               = %TMT_SIZINGBORDERWIDTH
%TMT_LASTSIZE                = %TMT_PADDEDBORDERWIDTH
%TMT_MINCOLORDEPTH           = 1301
%TMT_FIRSTINT                = %TMT_MINCOLORDEPTH
%TMT_LASTINT                 = %TMT_MINCOLORDEPTH
%TMT_CSSNAME                 = 1401
%TMT_XMLNAME                 = 1402
%TMT_LASTUPDATED             = 1403
%TMT_ALIAS                   = 1404
%TMT_FIRSTSTRING             = %TMT_CSSNAME
%TMT_LASTSTRING              = %TMT_ALIAS
%TMT_SCROLLBAR               = 1601
%TMT_BACKGROUND              = 1602
%TMT_ACTIVECAPTION           = 1603
%TMT_INACTIVECAPTION         = 1604
%TMT_MENU                    = 1605
%TMT_WINDOW                  = 1606
%TMT_WINDOWFRAME             = 1607
%TMT_MENUTEXT                = 1608
%TMT_WINDOWTEXT              = 1609
%TMT_CAPTIONTEXT             = 1610
%TMT_ACTIVEBORDER            = 1611
%TMT_INACTIVEBORDER          = 1612
%TMT_APPWORKSPACE            = 1613
%TMT_HIGHLIGHT               = 1614
%TMT_HIGHLIGHTTEXT           = 1615
%TMT_BTNFACE                 = 1616
%TMT_BTNSHADOW               = 1617
%TMT_GRAYTEXT                = 1618
%TMT_BTNTEXT                 = 1619
%TMT_INACTIVECAPTIONTEXT     = 1620
%TMT_BTNHIGHLIGHT            = 1621
%TMT_DKSHADOW3D              = 1622
%TMT_LIGHT3D                 = 1623
%TMT_INFOTEXT                = 1624
%TMT_INFOBK                  = 1625
%TMT_BUTTONALTERNATEFACE     = 1626
%TMT_HOTTRACKING             = 1627
%TMT_GRADIENTACTIVECAPTION   = 1628
%TMT_GRADIENTINACTIVECAPTION = 1629
%TMT_MENUHILIGHT             = 1630
%TMT_MENUBAR                 = 1631
%TMT_FIRSTCOLOR              = %TMT_SCROLLBAR
%TMT_LASTCOLOR               = %TMT_MENUBAR
%TMT_FROMHUE1                = 1801
%TMT_FROMHUE2                = 1802
%TMT_FROMHUE3                = 1803
%TMT_FROMHUE4                = 1804
%TMT_FROMHUE5                = 1805
%TMT_TOHUE1                  = 1806
%TMT_TOHUE2                  = 1807
%TMT_TOHUE3                  = 1808
%TMT_TOHUE4                  = 1809
%TMT_TOHUE5                  = 1810
%TMT_FROMCOLOR1              = 2001
%TMT_FROMCOLOR2              = 2002
%TMT_FROMCOLOR3              = 2003
%TMT_FROMCOLOR4              = 2004
%TMT_FROMCOLOR5              = 2005
%TMT_TOCOLOR1                = 2006
%TMT_TOCOLOR2                = 2007
%TMT_TOCOLOR3                = 2008
%TMT_TOCOLOR4                = 2009
%TMT_TOCOLOR5                = 2010
%TMT_TRANSPARENT             = 2201
%TMT_AUTOSIZE                = 2202
%TMT_BORDERONLY              = 2203
%TMT_COMPOSITED              = 2204
%TMT_BGFILL                  = 2205
%TMT_GLYPHTRANSPARENT        = 2206
%TMT_GLYPHONLY               = 2207
%TMT_ALWAYSSHOWSIZINGBAR     = 2208
%TMT_MIRRORIMAGE             = 2209
%TMT_UNIFORMSIZING           = 2210
%TMT_INTEGRALSIZING          = 2211
%TMT_SOURCEGROW              = 2212
%TMT_SOURCESHRINK            = 2213
%TMT_DRAWBORDERS             = 2214
%TMT_NOETCHEDEFFECT          = 2215
%TMT_TEXTAPPLYOVERLAY        = 2216
%TMT_TEXTGLOW                = 2217
%TMT_TEXTITALIC              = 2218
%TMT_COMPOSITEDOPAQUE        = 2219
%TMT_LOCALIZEDMIRRORIMAGE    = 2220
%TMT_IMAGECOUNT              = 2401
%TMT_ALPHALEVEL              = 2402
%TMT_BORDERSIZE              = 2403
%TMT_ROUNDCORNERWIDTH        = 2404
%TMT_ROUNDCORNERHEIGHT       = 2405
%TMT_GRADIENTRATIO1          = 2406
%TMT_GRADIENTRATIO2          = 2407
%TMT_GRADIENTRATIO3          = 2408
%TMT_GRADIENTRATIO4          = 2409
%TMT_GRADIENTRATIO5          = 2410
%TMT_PROGRESSCHUNKSIZE       = 2411
%TMT_PROGRESSSPACESIZE       = 2412
%TMT_SATURATION              = 2413
%TMT_TEXTBORDERSIZE          = 2414
%TMT_ALPHATHRESHOLD          = 2415
%TMT_WIDTH                   = 2416
%TMT_HEIGHT                  = 2417
%TMT_GLYPHINDEX              = 2418
%TMT_TRUESIZESTRETCHMARK     = 2419
%TMT_MINDPI1                 = 2420
%TMT_MINDPI2                 = 2421
%TMT_MINDPI3                 = 2422
%TMT_MINDPI4                 = 2423
%TMT_MINDPI5                 = 2424
%TMT_TEXTGLOWSIZE            = 2425
%TMT_FRAMESPERSECOND         = 2426
%TMT_PIXELSPERFRAME          = 2427
%TMT_ANIMATIONDELAY          = 2428
%TMT_GLOWINTENSITY           = 2429
%TMT_OPACITY                 = 2430
%TMT_COLORIZATIONCOLOR       = 2431
%TMT_COLORIZATIONOPACITY     = 2432
%TMT_GLYPHFONT               = 2601
%TMT_IMAGEFILE               = 3001
%TMT_IMAGEFILE1              = 3002
%TMT_IMAGEFILE2              = 3003
%TMT_IMAGEFILE3              = 3004
%TMT_IMAGEFILE4              = 3005
%TMT_IMAGEFILE5              = 3006
%TMT_GLYPHIMAGEFILE          = 3008
%TMT_TEXT                    = 3201
%TMT_CLASSICVALUE            = 3202
%TMT_OFFSET                  = 3401
%TMT_TEXTSHADOWOFFSET        = 3402
%TMT_MINSIZE                 = 3403
%TMT_MINSIZE1                = 3404
%TMT_MINSIZE2                = 3405
%TMT_MINSIZE3                = 3406
%TMT_MINSIZE4                = 3407
%TMT_MINSIZE5                = 3408
%TMT_NORMALSIZE              = 3409
%TMT_SIZINGMARGINS           = 3601
%TMT_CONTENTMARGINS          = 3602
%TMT_CAPTIONMARGINS          = 3603
%TMT_BORDERCOLOR             = 3801
%TMT_FILLCOLOR               = 3802
%TMT_TEXTCOLOR               = 3803
%TMT_EDGELIGHTCOLOR          = 3804
%TMT_EDGEHIGHLIGHTCOLOR      = 3805
%TMT_EDGESHADOWCOLOR         = 3806
%TMT_EDGEDKSHADOWCOLOR       = 3807
%TMT_EDGEFILLCOLOR           = 3808
%TMT_TRANSPARENTCOLOR        = 3809
%TMT_GRADIENTCOLOR1          = 3810
%TMT_GRADIENTCOLOR2          = 3811
%TMT_GRADIENTCOLOR3          = 3812
%TMT_GRADIENTCOLOR4          = 3813
%TMT_GRADIENTCOLOR5          = 3814
%TMT_SHADOWCOLOR             = 3815
%TMT_GLOWCOLOR               = 3816
%TMT_TEXTBORDERCOLOR         = 3817
%TMT_TEXTSHADOWCOLOR         = 3818
%TMT_GLYPHTEXTCOLOR          = 3819
%TMT_GLYPHTRANSPARENTCOLOR   = 3820
%TMT_FILLCOLORHINT           = 3821
%TMT_BORDERCOLORHINT         = 3822
%TMT_ACCENTCOLORHINT         = 3823
%TMT_TEXTCOLORHINT           = 3824
%TMT_HEADING1TEXTCOLOR       = 3825
%TMT_HEADING2TEXTCOLOR       = 3826
%TMT_BODYTEXTCOLOR           = 3827
%TMT_BGTYPE                  = 4001
%TMT_BORDERTYPE              = 4002
%TMT_FILLTYPE                = 4003
%TMT_SIZINGTYPE              = 4004
%TMT_HALIGN                  = 4005
%TMT_CONTENTALIGNMENT        = 4006
%TMT_VALIGN                  = 4007
%TMT_OFFSETTYPE              = 4008
%TMT_ICONEFFECT              = 4009
%TMT_TEXTSHADOWTYPE          = 4010
%TMT_IMAGELAYOUT             = 4011
%TMT_GLYPHTYPE               = 4012
%TMT_IMAGESELECTTYPE         = 4013
%TMT_GLYPHFONTSIZINGTYPE     = 4014
%TMT_TRUESIZESCALINGTYPE     = 4015
%TMT_USERPICTURE             = 5001
%TMT_DEFAULTPANESIZE         = 5002
%TMT_BLENDCOLOR              = 5003
%TMT_CUSTOMSPLITRECT         = 5004
%TMT_ANIMATIONBUTTONRECT     = 5005
%TMT_ANIMATIONDURATION       = 5006
%TMT_TRANSITIONDURATIONS     = 6000
%TMT_SCALEDBACKGROUND        = 7001
%TMT_ATLASIMAGE              = 8000
%TMT_ATLASINPUTIMAGE         = 8001
%TMT_ATLASRECT               = 8002


'//
'//  LINK class parts and states
'//
$$VSCLASS_LINK   = "LINK"$$

' enum LINKPARTS {
%LP_HYPERLINK = 1

' enum HYPERLINKSTATES {
%HLS_NORMALTEXT = 1
%HLS_LINKTEXT   = 2

'//
'//  EMPTYMARKUP class parts and states
'//
$$VSCLASS_EMPTYMARKUP   = "EMPTYMARKUP"$$

' enum EMPTYMARKUPPARTS {
%EMP_MARKUPTEXT = 1

' enum MARKUPTEXTSTATES
%EMT_NORMALTEXT = 1
%EMT_LINKTEXT   = 2


'//
'//  STATIC class parts and states
'//
$$VSCLASS_STATIC   = "STATIC"$$

' enum STATICPARTS
%STAT_TEXT = 1


'//
'//  PAGE class parts and states
'//
$$VSCLASS_PAGE   = "PAGE"$$

' enum PAGEPARTS
%PGRP_UP       = 1
%PGRP_DOWN     = 2
%PGRP_UPHORZ   = 3
%PGRP_DOWNHORZ = 4


'//
'//  MONTHCAL class parts and states
'//
$$VSCLASS_MONTHCAL   = "MONTHCAL"$$

' enum MONTHCALPARTS
%MC_BACKGROUND            = 1
%MC_BORDERS               = 2
%MC_GRIDBACKGROUND        = 3
%MC_COLHEADERSPLITTER     = 4
%MC_GRIDCELLBACKGROUND    = 5
%MC_GRIDCELL              = 6
%MC_GRIDCELLUPPER         = 7
%MC_TRAILINGGRIDCELL      = 8
%MC_TRAILINGGRIDCELLUPPER = 9
%MC_NAVNEXT               = 10
%MC_NAVPREV               = 11

' enum GRIDCELLBACKGROUNDSTATES
%MCGCB_SELECTED           = 1
%MCGCB_HOT                = 2
%MCGCB_SELECTEDHOT        = 3
%MCGCB_SELECTEDNOTFOCUSED = 4
%MCGCB_TODAY              = 5

' enum GRIDCELLSTATES
%MCGC_HOT         = 1
%MCGC_HASSTATE    = 2
%MCGC_HASSTATEHOT = 3
%MCGC_TODAY       = 4

' enum GRIDCELLUPPERSTATES {
%MCGCU_HOT         = 1
%MCGCU_HASSTATE    = 2
%MCGCU_HASSTATEHOT = 3

' enum TRAILINGGRIDCELLSTATES {
%MCTGC_HOT         = 1
%MCTGC_HASSTATE    = 2
%MCTGC_HASSTATEHOT = 3
%MCTGC_TODAY       = 4

' enum TRAILINGGRIDCELLUPPERSTATES
%MCTGCU_HOT         = 1
%MCTGCU_HASSTATE    = 2
%MCTGCU_HASSTATEHOT = 3

' enum NAVNEXTSTATES
%MCNN_NORMAL   = 1
%MCNN_HOT      = 2
%MCNN_PRESSED  = 3
%MCNN_DISABLED = 4

' enum NAVPREVSTATES
%MCNP_NORMAL   = 1
%MCNP_HOT      = 2
%MCNP_PRESSED  = 3
%MCNP_DISABLED = 4

'//
'//  CLOCK class parts and states
'//
$$VSCLASS_CLOCK   = "CLOCK"$$

' enum CLOCKPARTS
%CLP_TIME = 1

' enum CLOCKSTATES
%CLS_NORMAL  = 1
%CLS_HOT     = 2
%CLS_PRESSED = 3

'//
'//  TRAYNOTIFY class parts and states
'//
$$VSCLASS_TRAYNOTIFY   = "TRAYNOTIFY"$$

' enum TRAYNOTIFYPARTS
%TNP_BACKGROUND     = 1
%TNP_ANIMBACKGROUND = 2

'//
'//  TASKBAR class parts and states
'//
$$VSCLASS_TASKBAR   = "TASKBAR"$$

' enum TASKBARPARTS
%TBP_BACKGROUNDBOTTOM = 1
%TBP_BACKGROUNDRIGHT  = 2
%TBP_BACKGROUNDTOP    = 3
%TBP_BACKGROUNDLEFT   = 4
%TBP_SIZINGBARBOTTOM  = 5
%TBP_SIZINGBARRIGHT   = 6
%TBP_SIZINGBARTOP     = 7
%TBP_SIZINGBARLEFT    = 8

'//
'//  TASKBAND class parts and states
'//
$$VSCLASS_TASKBAND   = "TASKBAND"$$

' enum TASKBANDPARTS
%TDP_GROUPCOUNT           = 1
%TDP_FLASHBUTTON          = 2
%TDP_FLASHBUTTONGROUPMENU = 3

'//
'//  STARTPANEL class parts and states
'//
$$VSCLASS_STARTPANEL   = "STARTPANEL"$$

' enum STARTPANELPARTS
%SPP_USERPANE                  = 1
%SPP_MOREPROGRAMS              = 2
%SPP_MOREPROGRAMSARROW         = 3
%SPP_PROGLIST                  = 4
%SPP_PROGLISTSEPARATOR         = 5
%SPP_PLACESLIST                = 6
%SPP_PLACESLISTSEPARATOR       = 7
%SPP_LOGOFF                    = 8
%SPP_LOGOFFBUTTONS             = 9
%SPP_USERPICTURE               = 10
%SPP_PREVIEW                   = 11
%SPP_MOREPROGRAMSTAB           = 12
%SPP_NSCHOST                   = 13
%SPP_SOFTWAREEXPLORER          = 14
%SPP_OPENBOX                   = 15
%SPP_SEARCHVIEW                = 16
%SPP_MOREPROGRAMSARROWBACK     = 17
%SPP_TOPMATCH                  = 18
%SPP_LOGOFFSPLITBUTTONDROPDOWN = 19

' enum MOREPROGRAMSTABSTATES
%SPMPT_NORMAL   = 1
%SPMPT_HOT      = 2
%SPMPT_SELECTED = 3
%SPMPT_DISABLED = 4
%SPMPT_FOCUSED  = 5

' enum SOFTWAREEXPLORERSTATES
%SPSE_NORMAL   = 1
%SPSE_HOT      = 2
%SPSE_SELECTED = 3
%SPSE_DISABLED = 4
%SPSE_FOCUSED  = 5

' enum OPENBOXSTATES
%SPOB_NORMAL   = 1
%SPOB_HOT      = 2
%SPOB_SELECTED = 3
%SPOB_DISABLED = 4
%SPOB_FOCUSED  = 5

' enum MOREPROGRAMSARROWSTATES
%SPS_NORMAL  = 1
%SPS_HOT     = 2
%SPS_PRESSED = 3

' enum MOREPROGRAMSARROWBACKSTATES
%SPSB_NORMAL  = 1
%SPSB_HOT     = 2
%SPSB_PRESSED = 3

' enum LOGOFFBUTTONSSTATES
%SPLS_NORMAL  = 1
%SPLS_HOT     = 2
%SPLS_PRESSED = 3

'//
'//  MENUBAND class parts and states
'//
$$VSCLASS_MENUBAND   = "MENUBAND"$$

' enum MENUBANDPARTS
%MDP_NEWAPPBUTTON = 1
%MDP_SEPERATOR    = 2

' enum MENUBANDSTATES
%MDS_NORMAL     = 1
%MDS_HOT        = 2
%MDS_PRESSED    = 3
%MDS_DISABLED   = 4
%MDS_CHECKED    = 5
%MDS_HOTCHECKED = 6
