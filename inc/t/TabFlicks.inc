#INCLUDE THIS ONCE
%TABFLICKS_INC = 1

%FLICK_WM_HANDLED_MASK = &H1
%NUM_FLICK_DIRECTIONS  = 8

' enum FLICKDIRECTION
%FLICKDIRECTION_MIN       = 0
%FLICKDIRECTION_RIGHT     = 0
%FLICKDIRECTION_UPRIGHT   = 1
%FLICKDIRECTION_UP        = 2
%FLICKDIRECTION_UPLEFT    = 3
%FLICKDIRECTION_LEFT      = 4
%FLICKDIRECTION_DOWNLEFT  = 5
%FLICKDIRECTION_DOWN      = 6
%FLICKDIRECTION_DOWNRIGHT = 7
%FLICKDIRECTION_INVALID   = 8

' enum FLICKMODE
%FLICKMODE_MIN      = 0
%FLICKMODE_OFF      = 0
%FLICKMODE_ON       = 1
%FLICKMODE_LEARNING = 2
%FLICKMODE_MAX      = 2
%FLICKMODE_DEFAULT  = 2

' enum %FLICKACTION_COMMANDCODE
%FLICKACTION_COMMANDCODE_NULL        = 0
%FLICKACTION_COMMANDCODE_SCROLL      = 1
%FLICKACTION_COMMANDCODE_APPCOMMAND  = 2
%FLICKACTION_COMMANDCODE_CUSTOMKEY   = 3
%FLICKACTION_COMMANDCODE_KEYMODIFIER = 4

' // Size = 4 bytes
TYPE FLICK_POINT WORD
   x AS BIT * 16 IN WORD   ' INT x:16
   y AS BIT * 16 IN WORD   '  INT y:16
END TYPE

' // Size = 4 bytes
TYPE FLICK_DATA DWORD
   iFlickActionCommandCode AS BIT * 5  IN DWORD     ' FLICKACTION_COMMANDCODE iFlickActionCommandCode:5
   iFlickDirection         AS BIT * 3               ' FLICKDIRECTION iFlickDirection:3
   fControlModifier        AS BIT * 1               ' BOOL fControlModifier:1
   fMenuModifier           AS BIT * 1               ' BOOL fMenuModifier:1
   fAltGRModifier          AS BIT * 1               ' BOOL fAltGRModifier:1
   fWinModifier            AS BIT * 1               ' BOOL fWinModifier:1
   fShiftModifier          AS BIT * 1               ' BOOL fShiftModifier:1
   iReserved               AS BIT * 2               ' INT   ' iReserved:2
   fOnInkingSurface        AS BIT * 1               ' BOOL fOnInkingSurface:1
   iActionArgument         AS BIT * 16              ' INT iActionArgument:16
END TYPE


' enum SCROLLDIRECTION
%SCROLLDIRECTION_UP   = 0
%SCROLLDIRECTION_DOWN = 1

' enum KEYMODIFIER
%KEYMODIFIER_CONTROL = 1
%KEYMODIFIER_MENU    = 2
%KEYMODIFIER_SHIFT   = 4
%KEYMODIFIER_WIN     = 8
%KEYMODIFIER_ALTGR   = 16
%KEYMODIFIER_EXT     = 32


