' ########################################################################################
' Microsoft Windows
' File: usp10.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%USP10_INC = 1

#INCLUDE ONCE "windows.inc"

'///// Uniscribe build number

'%USPBUILD = 0400   ' Removed from Vista SDK

'/////   USP - Unicode Complex Script processor
'//
'//      Copyright (c) Microsoft Corporation. All rights reserved.

'/////   SCRIPT
'//
'//      The SCRIPT enum is an opaque type used internally to identify
'//      which shaping engine functions are used to process a given run.
'//
'//

%SCRIPT_UNDEFINED = 0

'//
'//p     SCRIPT_UNDEFINED: This is the only public script ordinal. May be
'//      forced into the eScript field of a SCRIPT_ANALYSIS to disable shaping.
'//      SCRIPT_UNDEFINED is supported by all fonts - ScriptShape will display
'//      whatever glyph is defined in the font CMAP table, or, if none, the
'//      missing glyph.

'/////   USP Status Codes
'//
'#define USP_E_SCRIPT_NOT_IN_FONT   \
'        MAKE_HRESULT(SEVERITY_ERROR,FACILITY_ITF,0x200)    // Script doesn't exist in font

%USP_E_SCRIPT_NOT_IN_FONT = &H80040200&

'/////   SCRIPT_CACHE
'//
'//      Many script APIs take a combination of HDC and SCRIPT_CACHE parameter.
'//
'//      A SCRIPT_CACHE is an opaque pointer to a Uniscribe font metric cache
'//      structure.

'typedef void *SCRIPT_CACHE;

'//      The client must allocate and retain one SCRIPT_CACHE variable for each
'//      character style used. It must be initialised by the client to NULL.
'//
'//      APIs are passed an HDC and the address of a SCRIPT_CACHE variable.
'//      Uniscribe will first attempt to access font data via the SCRIPT_CACHE
'//      and will only inspect the HDC if the required data is not already
'//      cached.
'//
'//      The HDC may be passed as NULL. If data required by Uniscribe is
'//      already cached, the HDC won't be accessed and operation continues
'//      normally.
'//
'//      If the HDC is passed as NULL, and Uniscribe needs to access it for
'//      any reason, Uniscribe will return E_PENDING.
'//
'//      E_PENDING is returned quickly, allowing the client to avoid time
'//      consuming SelectObject calls. The following example applies to all
'//      APIs that take a SCRIPT_CACHE and an optional HDC.
'//
'//c     hr = ScriptShape(NULL, &sc, ..);
'//c     if (hr == E_PENDING) {
'//c         ... select font into hdc ...
'//c         hr = ScriptShape(hdc, &sc, ...);
'//c     }


'/////   ScriptFreeCache
'//
'//      The client may free a SCRIPT_CACHE at any time. Uniscribe maintains
'//      reference counts in it's font and shaper caches, and frees font data
'//      only when all sizes of the font are free, and shaper data only when
'//      all fonts it supports are freed.
'//
'//      The client should free the SCRIPT_CACHE for a style when it discards
'//      that style.
'//
'//      ScriptFreeCache always sets it's parameter to NULL to help avoid
'//      mis-referencing.

DECLARE FUNCTION ScriptFreeCache IMPORT "USP10.DLL" ALIAS "ScriptFreeCache" ( _
   BYREF psc AS DWORD _                                 ' __in_out SCRIPT_CACHE *psc  // Cache handle
 ) AS LONG                                              ' HRESULT

'/////   SCRIPT_CONTROL
'//
'//      The SCRIPT_CONTROL structure provides itemization control flags to the
'//      ScriptItemize function.
'//
'//

' // Size = 4 bytes
TYPE SCRIPT_CONTROL DWORD
   uDefaultLanguage    AS BIT * 16 IN DWORD   ' // For NADS, also default for context
   fContextDigits      AS BIT * 1             ' // Means use previous script instead of uDefaultLanguage
   ' // The following flags provide legacy support for GetCharacterPlacement features
   fInvertPreBoundDir  AS BIT * 1             ' // Reading order of virtual item immediately prior to string
   fInvertPostBoundDir AS BIT * 1             ' // Reading order of virtual item immediately following string
   fLinkStringBefore   AS BIT * 1             ' // Equivalent to presence of ZWJ before string
   fLinkStringAfter    AS BIT * 1             ' // Equivalent to presence of ZWJ after string
   fNeutralOverride    AS BIT * 1             ' // Causes all neutrals to be strong in the current embedding direction
   fNumericOverride    AS BIT * 1             ' // Causes all numerals to be strong in the current embedding direction
   fLegacyBidiClass    AS BIT * 1             ' // Causes plus and minus to be reated as neutrals, slash as a common separator
   fMergeNeutralItems  AS BIT * 1             ' // Causes merging neutral characters into strong items, when possible
   fReserved           AS BIT * 7
END TYPE

'//
'//
'//p     uDefaultLanguage: Language to use when Unicode values are ambiguous.
'//              Used by numeric processing to select digit shape when
'//              fDigitSubstitute (see SCRIPT_STATE) is in force.
'//
'//p     fContextDigits: Specifies that national digits are chosen according to
'//              the nearest previous strong text, rather than using
'//              uDefaultLanguage.
'//
'//p     fInvertPreBoundDir: By default text at the start of the string is
'//              laid out as if it follows strong text of the same direction
'//              as the base embedding level. Set fInvertPreBoundDir to change
'//              the initial context to the opposite of the base embedding
'//              level. This flag is for GetCharacterPlacement legacy support.
'//
'//p     fInvertPostBoundDir: By default text at the end of the string is
'//              laid out as if it preceeds strong text of the same direction
'//              as the base embedding level. Set fInvertPostBoundDir to change
'//              the final context to the opposite of the base embedding
'//              level. This flag is for GetCharacterPlacement legacy support.
'//
'//p     fLinkStringBefore: Causes the first character of the string to be
'//              shaped as if were joined to a previous character.
'//
'//p     fLinkStringAfter: Causes the last character of the string to be
'//              shaped as if were joined to a following character.
'//
'//p     fNeutralOverride: Causes all neutral characters in the string to be
'//              treated as if they were strong characters of their enclosing
'//              embedding level. This effectively locks neutrals in place,
'//              reordering occuring only between neutrals.
'//
'//p     fNumericOverride: Causes all numeric characters in the string to be
'//              treated as if they were strong characters of their enclosing
'//              embedding level. This effectively locks numerics in place,
'//              reordering occuring only between numerics.
'//
'//p     fReserved: Reserved. Always initialise to 0.


'/////   SCRIPT_STATE
'//
'//      The SCRIPT_STATE structure is used both to initialise the unicode
'//      algorithm state as an input parameter to ScriptItemize, and is also
'//      a component of each item analysis returned by ScriptItemize.
'//
'//

' // Size = 4 bytes
TYPE SCRIPT_STATE WORD
   uBidiLevel         AS BIT * 5 IN WORD   ' // Unicode Bidi algorithm embedding level (0-16)
   fOverrideDirection AS BIT * 1           ' // Set when in LRO/RLO embedding
   fInhibitSymSwap    AS BIT * 1           ' // Set by U+206A (ISS), cleared by U+206B (ASS)
   fCharShape         AS BIT * 1           ' // Set by U+206D (AAFS), cleared by U+206C (IAFS)
   fDigitSubstitute   AS BIT * 1           ' // Set by U+206E (NADS), cleared by U+206F (NODS)
   fInhibitLigate     AS BIT * 1           ' // Equiv !GCP_Ligate, no Unicode control chars yet
   fDisplayZWG        AS BIT * 1           ' // Equiv GCP_DisplayZWG, no Unicode control characters yet
   fArabicNumContext  AS BIT * 1           ' // For EN->AN Unicode rule
   fGcpClusters       AS BIT * 1           ' // For Generating Backward Compatible GCP Clusters (legacy Apps)
   fReserved          AS BIT * 1           '
   fEngineReserved    AS BIT * 2           ' // For use by shaping engine
END TYPE

'//
'//
'//p     uBidiLevel: The embedding level associated with all characters in this
'//              run according to the Unicode bidi algorithm. When passed to
'//              ScriptItemize, should be initialised to 0 for an LTR base
'//              embedding level, or 1 for RTL.
'//
'//p     fOverrideDirection: TRUE if this level is an override level (LRO/RLO).
'//              In an override level, characters are layed out purely
'//              left to right, or purely right to left. No reordering of digits
'//              or strong characters of opposing direction takes place.
'//              Note that this initial value is reset by LRE, RLE, LRO or
'//              RLO codes in the string.
'//
'//p     fInhibitSymSwap: TRUE if the shaping engine is to bypass mirroring of
'//              Unicode Mirrored glyphs such as brackets. Set by Unicode
'//              character ISS, cleared by ASS.
'//
'//p     fCharShape: TRUE if character codes in the Arabic Presentation Forms
'//              areas of Unicode should be shaped. (Not implemented).
'//
'//p     fDigitSubstitute: TRUE if character codes U+0030 through U+0039
'//              (European digits) are to be substituted by national digits.
'//              Set by Unicode NADS, Cleared by NODS.
'//
'//p     fInhibitLigate: TRUE if ligatures are not to be used in the shaping
'//              of Arabic or Hebrew characters.
'//
'//p     fDisplayZWG: TRUE if control characters are to be shaped as
'//              representational glyphs. (Normally, control characters are
'//              shaped to the blank glyph and given a width of zero).
'//
'//p     fArabicNumContext: TRUE indicates prior strong characters were Arabic
'//              for the purposes of rule P0 on page 3-19 of 'The Unicode
'//              Standard, version 2.0'. Should normally be set TRUE before
'//              itemizing an RTL paragraph in an Arabic language, FALSE
'//              otherwise.
'//
'//p     fGcpClusters: For GetCharaterPlacement legacy support only.
'//              Initialise to TRUE to request ScriptShape to generate
'//              the LogClust array the same way as GetCharacterPlacement
'//              does in Arabic and Hebrew Windows95. Affects only Arabic
'//              and Hebrew items.
'//
'//p     fReserved: Reserved. Always initialise to 0.
'//
'//p     fEngineReserved: Reserved. Always initialise to 0.


'/////   SCRIPT_ANALYSIS
'//
'//      Each analysed item is described by a SCRIPT_ANALYSIS structure.
'//      It also includes a copy of the Unicode algorithm state (SCRIPT_STATE).
'//
'//

' // Size = 4 bytes
TYPE SCRIPT_ANALYSIS WORD
   eScript       AS BIT * 10 IN WORD   ' // Shaping engine
   fRTL          AS BIT * 1            ' // Rendering direction
   fLayoutRTL    AS BIT * 1            ' // Set for GCP classes ARABIC/HEBREW and LOCALNUMBER
   fLinkBefore   AS BIT * 1            ' // Implies there was a ZWJ before this item
   fLinkAfter    AS BIT * 1            ' // Implies there is a ZWJ following this item.
   fLogicalOrder AS BIT * 1            ' // Set by client as input to ScriptShape/Place
   fNoGlyphIndex AS BIT * 1            ' // Generated by ScriptShape/Place - this item does not use glyph indices
   s             AS SCRIPT_STATE
END TYPE

'//
'//
'//p     eScript: Opaque value identifying which engine Uniscribe will use to
'//              Shape, Place and TextOut this item. The value of eScript is
'//              undefined, and will change in future releases, but attributes
'//              of eScript may be obtained by calling ScriptGetProperties.
'//
'//p     fRTL: Rendering direction. Normally identical to the parity of the
'//              Unicode embedding level, but may differ if overridden by
'//              GetCharacterPlacement legacy support.
'//
'//p     fLayoutRTL: Logical direction - whether conceptually part of a
'//              left-to-right sequenece or a right-to-left sequence. Although
'//              this is usually the same as fRTL, for a number in a
'//              right-to-left run, fRTL is False (because digits are always
'//              displayed LTR), but fLayoutRTL is True (because the number is
'//              read as part of the right-to-left sequence).
'//
'//p     fLinkBefore: If set, the shaping engine will shape the first character
'//              of this item as if it were joining with a previous character.
'//              Set by ScriptItemize, may be overriden before calling ScriptShape.
'//
'//p     fLinkAfter: If set, the shaping engine will shape the last character
'//              of this item as if it were joining with a subsequient character.
'//              Set by ScriptItemize, may be overriden before calling ScriptShape.
'//
'//p     fLogicalOrder: If set, the shaping engine will generate all glyph
'//              related arrays in logical order. By default glyph related
'//              arrays are in visual order, the first array entry corresponding
'//              to the leftmost glyph.
'//              Set to FALSE by ScriptItemize, may be overriden before calling
'//              ScriptShape.
'//
'//p     fNoGlyphIndex: May be set TRUE on input to ScriptShape to disable use
'//              of glyphs for this item. Additionally, ScriptShape will set it
'//              TRUE for hdcs containing symbolic, unrecognised and device fonts.
'//              Disabling glyphing disables complex script shaping. When set,
'//              shaping and placing for this item is implemented directly by
'//              calls to GetTextExtentExPoint and ExtTextOut.
'/////   SCRIPT_ITEM
'//
'//      The SCRIPT_ITEM structure includes a SCRIPT_ANALYSIS with the string
'//      ofset of the first character of the item.
'//
'//

' // Size = 8 bytes
TYPE SCRIPT_ITEM DWORD
   iCharPos AS LONG   ' int // Logical offset to first character in this item
   a        AS SCRIPT_ANALYSIS
END TYPE

'//
'//
'//p     iCharPos: Offset from beginning of itemised string to first character
'//              of this item, counted in Unicode codepoints (i.e. words).
'//
'//p     a: Script analysis structure containing analysis specific to this
'//              item, to be passed to ScriptShape, ScriptPlace etc.

'/////   ScriptItemize - break text into items
'//
'//      Breaks a run of unicode into individually shapeable items.
'//      Items are delimited by
'//
'//      o Change of shaping engine
'//      o Change of direction
'//
'//      The client may create multiple runs from each item returned by
'//      ScriptItemize, but should not combine multiple items into a single run.
'//
'//      Later the client will call ScriptShape for each run (when measuring or
'//      rendering), and must pass the SCRIPT_ANALYSIS that ScriptItemize
'//      returned.

DECLARE FUNCTION ScriptItemize IMPORT "USP10.DLL" ALIAS "ScriptItemize" ( _
   BYVAL pwcInChars AS DWORD _                          ' __in  const WCHAR          *pwcInChars  // Unicode string to be itemized
 , BYVAL cInChars AS LONG _                             ' __in  int                   cInChars    // Codepoint count to itemize
 , BYVAL cMaxItems AS LONG _                            ' __in  int                   cMaxItems   // Max length of itemization array
 , BYREF psControl AS SCRIPT_CONTROL _                  ' __in  const SCRIPT_CONTROL *psControl   // Analysis control (optional)
 , BYREF psState AS SCRIPT_STATE _                      ' __in  const SCRIPT_STATE   *psState     // Initial bidi algorithm state (optional)
 , BYREF pItems AS SCRIPT_ITEM _                        ' __out SCRIPT_ITEM          *pItems      // Array to receive itemization
 , BYREF pcItems AS LONG _                              ' __out int                  *pcItems     // Count of items processed (optional)
 ) AS LONG                                              ' HRESULT

'/////
'//
'//
'//      Returns E_INVALIDARG if pwcInChars == NULL or cInChars == 0
'//          or pItems == NULL or cMaxItems < 2.
'//
'//      Returns E_OUTOFMEMORY if the output buffer length (cMaxItems) is
'//          insufficient. Note that in this case, as in all error cases, no
'//          items have been fully processed so no part of the output array
'//          contains defined values.
'//
'//      If psControl and psState are NULL on entry, ScriptItemize
'//      breaks the unicode string purely by character code.  If they are all
'//      non-null, it performs a full Unicode bidi analysis.
'//
'//      ScriptItemize always adds a terminal item to the item analysis array
'//      (pItems) such that the length of an item at pItem is always available as:
'//
'//c     pItem[1].iCharPos - pItem[0].iCharPos
'//
'//      For this reason, it is invalid to call ScriptItemize with a buffer
'//      of less than two SCRIPT_ANALYSIS items.
'//
'//      To perform a correct Unicode Bidi analysis, the SCRIPT_STATE should
'//      be initialised according to the paragraph reading order at paragraph
'//      start, and ScriptItemize should be passed the whole paragraph.
'//
'//      fRTL and fNumeric together provide the same classification as
'//      the lpClass output from GetCharacterPlacement.
'//
'//      European digits U+0030 through U+0039 may be rendered as national
'//      digits as follows:
'//
'//t     fDigitSubstitute | FContextDigits | Digit shapes displayed for Unicode U+0030 through U+0039
'//t     ---------------- | -------------- | ------------------------------------
'//t     False            | Any            | Western (European / American) digits
'//t     True             | False          | As specified in SCRIPT_CONTROL.uDefaultLanguage
'//t     True             | True           | As prior strong text, defaulting to SCRIPT_CONTROL.uDefaultLanguage
'//
'//
'//      For fContextDigits, any Western digits (U+0030 - U+0039) encountered
'//      before the first strongly directed character are substituted by the
'//      traditional digits of the SCRIPT_CONTROL.uDefaultLanguage when that
'//      language is written in the same direction as SCRIPT_STATE.uBidiLevel.
'//
'//      Thus, in a right-to-left string, if SCRIPT_CONTROL.uDefaultLanguage is
'//      1 (LANG_ARABIC), then leading Western digits will be substituted by
'//      traditional Arabic digits.
'//
'//      However, also in a right-to-left string, if SCRIPT_CONTROL.uDefaultLanguage
'//      is 0x1e (LANG_THAI), then no substitution occurs on leading Western
'//      digits because the Thai language is written left-to-right.
'//
'//      Following strongly directed characters, digits are substituted
'//      by the traditional digits associated with the closest prior strongly
'//      directed character.
'//
'//      The left-to-right mark (LRM) and right-to-left mark (RLM) are strong
'//      characters whose language depends on the SCRIPT_CONTROL.uDefaultLangauge.
'//
'//      If SCRIPT_CONTROL.uDefaultLangauge is a left-to-right langauge, then
'//      LRM causes subsequent Western digits to be substituted by the
'//      traditional digits associated with that language, while Western
'//      digits following RLM are not substituted.
'//
'//      Conversly, if SCRIPT_CONTROL.uDefaultLangauge is a right-to-left
'//      langauge, then Western digits following LRM are not substituted, while
'//      Western digits following RLM are substituted by the traditional digits
'//      associated with that language.
'//
'//
'//
'//      Effect of Unicode control characters on SCRIPT_STATE:
'//
'//t     SCRIPT_STATE flag | Set by | Cleared by
'//t     ----------------- | ------   ----------
'//t     fDigitSubstitute  |  NADS  |   NODS
'//t     fInhibitSymSwap   |  ISS   |   ASS
'//t     fCharShape        |  AAFS  |   IAFS
'//
'//      SCRIPT_STATE.fArabicNumContext controls the Unicode EN->AN rule.
'//      It should normally be initialised to TRUE
'//      before itemizing an RTL paragraph in an Arabic language, FALSE
'//      otherwise.
'/////   ScriptLayout
'//
'//      The ScriptLayout function converts an array of run embedding levels to
'//      a map of visual to logical position, and/or logical to visual position.
'//
'//      pbLevel must contain the embedding levels for all runs on the line,
'//      ordered logically.
'//
'//      On output, piVisualToLogical[0] is the logical index of the run to
'//      display at the far left. Subsequent entries should be displayed
'//      progressing from left to right.
'//
'//      piLogicalToVisual[0] is the relative visual position where the first
'//      logical run should be displayed - the leftmost display position being zero.
'//
'//      The caller may request either piLogicalToVisual or piVisualToLogical
'//      or both.
'//
'//      Note: No other input is required since the embedding levels give all
'//      necessary information for layout.

DECLARE FUNCTION ScriptLayout IMPORT "USP10.DLL" ALIAS "ScriptLayout" ( _
   BYVAL cRuns AS LONG _                                ' __in  int         cRuns              // Number of runs to process
 , BYREF pbLevel AS BYTE _                              ' __in  const BYTE *pbLevel            // Array of run embedding levels
 , BYREF piVisualToLogical AS LONG _                    ' __out int        *piVisualToLogical  // List of run indices in visual order
 , BYREF piLogicalToVisual AS LONG _                    ' __out int        *piLogicalToVisual  // List of visual run positions
 ) AS LONG                                              ' HRESULT


'/////   SCRIPT_JUSTIFY
'//
'//      The script justification enumeration provides the client with the
'//      glyph characteristic information it needs to implement justification.

' enum tag_SCRIPT_JUSTIFY
%SCRIPT_JUSTIFY_NONE           = 0   ' // Justification can't be applied at this glyph
%SCRIPT_JUSTIFY_ARABIC_BLANK   = 1   ' // This glyph represents a blank in an Arabic run
%SCRIPT_JUSTIFY_CHARACTER      = 2   ' // Inter-character justification point follows this glyph
%SCRIPT_JUSTIFY_RESERVED1      = 3   ' // Reserved #1
%SCRIPT_JUSTIFY_BLANK          = 4   ' // This glyph represents a blank outside an Arabic run
%SCRIPT_JUSTIFY_RESERVED2      = 5   ' // Reserved #2
%SCRIPT_JUSTIFY_RESERVED3      = 6   ' // Reserved #3
%SCRIPT_JUSTIFY_ARABIC_NORMAL  = 7   ' // Normal Middle-Of-Word glyph that connects to the right (begin)
%SCRIPT_JUSTIFY_ARABIC_KASHIDA = 8   ' // Kashida(U+640) in middle of word
%SCRIPT_JUSTIFY_ARABIC_ALEF    = 9   ' // Final form of Alef-like (U+627 U+625 U+623 U+632)
%SCRIPT_JUSTIFY_ARABIC_HA      = 10  ' // Final form of Ha (U+647)
%SCRIPT_JUSTIFY_ARABIC_RA      = 11  ' // Final form of Ra (U+631)
%SCRIPT_JUSTIFY_ARABIC_BA      = 12  ' // Middle-Of-Word form of Ba (U+628)
%SCRIPT_JUSTIFY_ARABIC_BARA    = 13  ' // Ligature of alike (U+628U+631)
%SCRIPT_JUSTIFY_ARABIC_SEEN    = 14  ' // Highest priority: Initial shape of Seen(U+633) (end)
%SCRIPT_JUSTIFY_ARABIC_SEEN_M  = 15  ' // Reserved #4

'/////   SCRIPT_VISATTR
'//
'//      The visual (glyph) attribute buffer generated by ScriptShape
'//      identifies clusters and justification points:

' // Size = 2 bytes
TYPE SCRIPT_VISATTR WORD
   uJustification AS BIT * 4 IN WORD   ' // Justification class
   fClusterStart  AS BIT * 1           ' // First glyph of representation of cluster
   fDiacritic     AS BIT * 1           ' // Diacritic
   fZeroWidth     AS BIT * 1           ' // Blank, ZWJ, ZWNJ etc, with no width
   fReserved      AS BIT * 1           ' // General reserved
   fShapeReserved AS BIT * 8           ' // Reserved for use by shaping engines
END TYPE

'//
'//
'//p     uJustification: Justification class for this glyph. See SCRIPT_JUSTIFY.
'//
'//p     fClusterStart: Set for the logically first glyph in every cluster,
'//          even for clusters containing just one glyph.
'//
'//p     fDiacritic: Set for glyphs that combine with base characters.
'//
'//p     fZeroWidth: Set by the shaping engine for some, but not all, zero
'//          width characters.

'/////   ScriptShape
'//
'//      The ScriptShape function takes a Unicode run and generates glyphs and
'//      visual attributes.
'//
'//      The number of glyphs generated varies according to the script and the
'//      font. Only for simple scripts and fonts does each Unicode code point
'//      generates a single glyph.
'//
'//      There is no limit on the number of glyphs generated by a codepoint.
'//      For example, a sophisticated complex script font might choose to
'//      constuct characters from components, and so generate many times as
'//      many glyphs as characters.
'//
'//      There are also special cases like invalid character representations,
'//      where extra glyphs are added to represent the invalid sequence.
'//
'//      A reasonable guess might be to provide a glyph buffer 1.5 times the
'//      length of the character buffer, plus a 16 glyph fixed addition for
'//      rare cases like invalid sequenece representation.
'//
'//      If ScriptShape returns E_OUTOFMEMORY it will be necessary to recall
'//      it, possibly more than once, until a large enough buffer is found.

DECLARE FUNCTION ScriptShape IMPORT "USP10.DLL" ALIAS "ScriptShape" ( _
   BYVAL hdc AS DWORD _                                 ' __in     HDC              hdc          // Optional (see under caching)
 , BYREF psc AS DWORD _                                 ' __in_out SCRIPT_CACHE    *psc          // Cache handle
 , BYREF pwcChars AS WORD _                             ' __in     const WCHAR     *pwcChars     // Logical unicode run
 , BYVAL cChars AS LONG _                               ' __in     int              cChars       // Length of unicode run
 , BYVAL cMaxGlyphs AS LONG _                           ' __in     int              cMaxGlyphs   // Max glyphs to generate
 , BYREF psa AS SCRIPT_ANALYSIS _                       ' __in_out SCRIPT_ANALYSIS *psa          // Result of ScriptItemize (may have fNoGlyphIndex set)
 , BYREF pwOutGlyphs AS WORD _                          ' __out    WORD            *pwOutGlyphs  // Output glyph buffer
 , BYREF pwLogClust AS WORD _                           ' __out    WORD            *pwLogClust   // Logical clusters
 , BYREF psva AS SCRIPT_VISATTR _                       ' __out    SCRIPT_VISATTR  *psva         // Visual glyph attributes
 , BYREF pcGlyphs AS LONG _                             ' __out    int             *pcGlyphs     // Count of glyphs generated
 ) AS LONG                                              ' HRESULT

'/////
'//
'//      Returns E_OUTOFMEMORY if the output buffer length (cMaxGlyphs) is
'//          insufficient. Note that in this case, as in all error cases, the
'//          content of all output parameters are undefined.
'//
'//p     psa: Pass the SCRIPT_ANALYSIS field of the SCRIPT_ITEM entry for this
'//          item. (The SCRIPT_ITEM array is returned by ScriptItemize.)
'//
'//      Clusters are sequenced uniformly within the run, as are glyphs within
'//      the cluster - the fRTL item flag (from ScriptItemize) identifies
'//      whether left to right, or right to left.
'//
'//p     pwLogClust: has cChars elements - each entry in pwLogClust corresponds
'//          to a character in the input string (pwcChars). The value in each
'//          pwLogCLust entry is the offset of the first glyph in the cluster
'//          that contains this character.
'//
'//      Example: In the following example, there are four clusters:
'//      1st cluster: one character represented by one glyph
'//      2nd cluster: one character represented by 3 glyphs
'//      3rd cluster: three characters represented by one glyph
'//      4th cluster: 2 characters represented by three glyphs
'//
'//      Glyph array: (c<n>g<m> means cluster n glyph m)
'//c        0      1    2    3      4      5    6    7
'//c     -------------------------------------------------
'//c     | c1g1 | c2g1 c2g2 c2g3 | c3g1 | c4g1 c4g2 c4g3 |
'//c     -------------------------------------------------
'//
'//      Character array: (c<n>u<m> means cluster n Unicode codepoint m)
'//c        0      1      2    3    4      5    6
'//c     --------------------------------------------
'//c     | c1u1 | c2u1 | c3u1 c3u2 c3u3 | c4u1 c4u2 |
'//c     --------------------------------------------
'//
'//      LogClust: (one entry per character gives 1st glyph in cluster
'//c     --------------------------------------------
'//c     |   0  |   1  |   4    4    4  |   5    5  |
'//c     --------------------------------------------
'//
'//      Note that for an RTL run (SCRIPT_ANALYSIS.a.fRTL == TRUE) and when
'//      fLogicalOrder == FALSE (the default), glyphs are generated in visual
'//      order - the reverse of the codepoint order, and the values in the
'//      LogClust array will be descending.
'//
'//
'//p     psva: has one visual attribute per glyph and so has maxGlyphs entries.
'//
'//
'//      ScriptShape may set the fNoGlyphIndex flag in psa if the font or
'//      OS cannot support glyph indices.
'//
'//      If fLogicalOrder is requested in psa, glyphs will be always be
'//      generated in the same order as the original Unicode characters.
'//
'//      If fLogicalOrder is not set, right to left items are generated in
'//      reverse order, so ScriptTextOut does not need to reverse them before
'//      calling ExtTextOut.
'/////   ScriptPlace
'//
'//      The ScriptPlace function takes the output of a ScriptShape call and
'//      generates glyph advance width and 2D offset information.
'//
'//      The composite ABC width for the whole item identifies how much the
'//      glyphs overhang to the left of the start position and to the right of
'//      the length implied by the sum of the advance widths.
'//
'//      The total advance width of the line is exactly abcA + abcB + abcC.
'//
'//      abcA and abcC are maintained internally by Uniscribe as proportions
'//      of the cell height represented in 8 bits and are thus roughly +/- 1%.
'//      The total width returned (as the sum of piAdvance, and as the sum of
'//      abcA+abcB+abcC) is accurate to the resolution of the TrueType shaping
'//      engine.
'//
'//      All glyph related arrays are in visual order unless the fLogicalOrder
'//      flag is set in psa.

#IF NOT %DEF(%LSDEFS_DEFINED)
%LSDEFS_DEFINED = 1
' // Size = 8 bytes
TYPE GOFFSET DWORD
   du AS LONG
   dv AS LONG
END TYPE
#ENDIF

DECLARE FUNCTION ScriptPlace IMPORT "USP10.DLL" ALIAS "ScriptPlace" ( _
   BYVAL hdc AS DWORD _                                 ' __in     HDC                   hdc        // Optional (see under caching)
 , BYREF psc AS DWORD _                                 ' __in_out SCRIPT_CACHE         *psc        // Cache handle
 , BYREF pwGlyphs AS WORD _                             ' __in     const WORD           *pwGlyphs   // Glyph buffer from prior ScriptShape call
 , BYVAL cGlyphs AS LONG _                              ' __in     int                   cGlyphs    // Number of glyphs
 , BYREF psva AS SCRIPT_VISATTR _                       ' __in     const SCRIPT_VISATTR *psva       // Visual glyph attributes
 , BYREF psa AS SCRIPT_ANALYSIS _                       ' __in_out SCRIPT_ANALYSIS      *psa        // Result of ScriptItemize (may have fNoGlyphIndex set)
 , BYREF piAdvance AS LONG _                            ' __out    int                  *piAdvance  // Advance wdiths
 , BYREF pGoffset AS GOFFSET _                          ' __out    GOFFSET              *pGoffset   // xy offset for combining glyph
 , BYREF pABC AS ABC _                                  ' __out    ABC                  *pABC       // Composite ABC for the whole run (Optional)
 ) AS LONG                                              ' HRESULT

'/////   ScriptTextOut
'//
'//      The ScriptTextOut function takes the output of both ScriptShape and
'//      ScriptPlace calls and calls the operating system ExtTextOut function
'//      appropriately. If the last parameter is not null, GDI's ExtTextOutW calls
'//      are routed to this function.
'//
'//      All arrays are in visual order unless the fLogicalOrder flag is set in
'//      psa.

DECLARE FUNCTION ScriptTextOut IMPORT "USP10.DLL" ALIAS "ScriptTextOut" ( _
   BYVAL hdc AS DWORD _                                 ' __in     const HDC             hdc          // OS handle to device context (required)
 , BYREF psc AS DWORD _                                 ' __in_out SCRIPT_CACHE          *psc         // Cache handle
 , BYVAL x AS LONG _                                    ' __in     int                   x            // x position for first glyph
 , BYVAL y AS LONG _                                    ' __in     int                   y            // y position for first glyph
 , BYVAL fuOptions AS DWORD _                           ' __in     UINT                  fuOptions    // ExtTextOut options
 , BYREF lprc AS RECT _                                 ' __in     const RECT            *lprc        // optional clipping/opaquing rectangle
 , BYREF psa AS SCRIPT_ANALYSIS _                       ' __in     const SCRIPT_ANALYSIS *psa         // Result of ScriptItemize
 , BYVAL pwcReserved AS DWORD _                         ' __in     const WCHAR           *pwcReserved // Reserved (requires NULL)
 , BYVAL iReserved AS LONG _                            ' __in     int                   iReserved    // Reserved (requires 0)
 , BYREF pwGlyphs AS WORD _                             ' __in     const WORD            *pwGlyphs    // Glyph buffer from prior ScriptShape call
 , BYVAL cGlyphs AS LONG _                              ' __in     int                   cGlyphs      // Number of glyphs
 , BYREF piAdvance AS LONG _                            ' __in     const int             *piAdvance   // Advance widths from ScriptPlace
 , BYREF piJustify AS LONG _                            ' __in     const int             *piJustify   // Justified advance widths (optional)
 , BYREF pGoffset AS GOFFSET _                          ' __in     const GOFFSET         *pGoffset    // xy offset for combining glyph
 ) AS LONG                                              ' HRESULT

'/////
'//
'//      The caller should normally use SetTextAlign(hdc, TA_RIGHT) before
'//      calling ScriptTextOut with an RTL item inlogical order.
'//
'//      The piJustify array provides requested cell widths for each glyph.
'//      When the piJustify width of a glyph differs from the unjustified
'//      width (in PiAdvance), space is added to or removed from the glyph
'//      cell at it's trailing edge. The glyph is always aligned with the
'//      leading edge of it's cell. (This rule applies even in visual order.)
'//
'//      When a glyph cell is extended the extra space is uaually made up by
'//      the addition of white space, however for Arabic scripts, the extra
'//      space is made up by one or more kashida glyphs, unless the extra space
'//      is insufficient for the shortest kashida glyph in the font. (The
'//      width of the shortest kashida is available by calling
'//      ScriptGetFontProperties.)
'//
'//      piJustify should only be passed if re-justification of the string is
'//      required. Normally pass NULL to this parameter.
'//
'//      fuOptions may contain ETO_CLIPPED or ETO_OPAQUE (or neither or both).
'//
'//      Do not use ScriptTextOut to write to a metafile unless you are sure
'//      that the metafile will eventually be played back without any font
'//      substitution. ScriptTextOut record glyph numbers in the metafile.
'//      Since glyph numbers vary considerably from one font to another
'//      such a metafile is unlikely to play back correctly when differant
'//      fonts are substituted.
'//
'//      For example when a metafile is played back at a different scale
'//      CreateFont requests recorded in the metafile may resolve to bitmap
'//      instead of truetype fonts, or if the metafile is played back on
'//      a different machine requested fonts may not be installed.//
'//
'//      To write complex scripts in a metafile in a font independant manner,
'//      use ExtTextOut to write the logical characters directly, so that
'//      glyph generation and placement does not occur until the text is
'//      played back.
'/////   ScriptJustify
'//
'//      ScriptJustify provides a simple minded implementation of multilingual
'//      justification.
'//
'//      Sophisticated text formatters may prefer to generate their own delta
'//      dx array by combining their own features with the information returned
'//      by ScriptShape in the SCRIPT_VISATTR array.
'//
'//      ScriptJustify establishes how much adjustment to make at each glyph
'//      position on the line. It interprets the SCRIPT_VISATTR array generated
'//      by a call to ScriptShape, and gives top priority to kashida, then uses
'//      inter word spacing if there's no kashida points, then uses
'//      intercharacter spacing if there are no inter-word points.
'//
'//      The justified advance widths generated in ScriptJustify should be
'//      passed to ScriptTextOut in the piJustify paramter.
'//
'//      ScriptJustify creates a justify array containing updated advance
'//      widths for each glyph. Where a glyphs advance width is increased, it
'//      is expected that the extra width will be rendered to the right of the
'//      glyph, with as white space or, for Arabic text, as kashida.
'/////

DECLARE FUNCTION ScriptJustify IMPORT "USP10.DLL" ALIAS "ScriptJustify" ( _
   BYREF psva AS SCRIPT_VISATTR _                       ' __in  const SCRIPT_VISATTR *psva        // Collected visual attributes for entire line
 , BYREF piAdvance AS LONG _                            ' __in  const int            *piAdvance   // Advance widths from ScriptPlace
 , BYVAL cGlyphs AS LONG _                              ' __in  int                   cGlyphs     // Size of all arrays
 , BYVAL iDx AS LONG _                                  ' __in  int                   iDx         // Desired width change either increase or descrease
 , BYVAL iMinKashida AS LONG _                          ' __in  int                   iMinKashida // Minimum length of continuous kashida glyph to generate
 , BYREF piJustify AS LONG _                            ' __out int                  *piJustify   // Updated advance widths to pass to ScriptTextOut
 ) AS LONG                                              ' HRESULT

'/////   SCRIPT_LOGATTR
'//
'//      The SCRIPT_LOGATTR structure describes attributes of logical
'//      characters useful when editing and formatting text.
'//
'//      Note that for wordbreaking and linebreaking, if the first character of
'//      the run passed in is not whitespace, the client needs to check whether
'//      the last character of the previous run is whitespace to determine if
'//      the first character of this run is the start of a word.
'//
'//

' // Size = 1 byte
TYPE SCRIPT_LOGATTR BYTE
   fSoftBreak  AS BIT * 1 IN BYTE   ' // Potential linebreak point
   fWhiteSpace AS BIT * 1           ' // A unicode whitespace character, except NBSP, ZWNBSP
   fCharStop   AS BIT * 1           ' // Valid cursor position (for left/right arrow)
   fWordStop   AS BIT * 1           ' // Valid cursor position (for ctrl + left/right arrow)
   fInvalid    AS BIT * 1           ' // Invalid character sequence
   fReserved   AS BIT * 3
END TYPE

'//
'//
'//p     fSoftBreak: It would be valid to break the line in front of this
'//              character. This flag is set on the first character of
'//              South-East Asian words. Note that when linebreaking the
'//              client would usually also treat any nonblank following a blank
'//              as a softbreak position, by inspecting the fWhiteSPace flag
'//              below.
'//
'//p     fWhiteSpace: This character is one of the many Unicode character
'//              that are classified as breakable whitespace.
'//
'//p     fCharStop: Valid cursor position. Set on most characters, but not
'//              on codepoints inside Indian and South East Asian character
'//              clusters. May be used to implement left and right arrow
'//              operation in editors.
'//
'//p     fWordStop: Valid position following word advance/retire commonly
'//              implemented at ctrl/left-arrow and ctrl/right-arrow.
'//              May be used to implement ctrl+left and ctrl+right arrow
'//              operation in editors. As with fSoftBreak clients should
'//              normally also inspect the fWhiteSpace flag and treat the
'//              first character after a run of whitespace as the start of a
'//              word.
'//
'//p     fInvalid: Marks characters which form an invalid or undisplayable
'//              combination. Scripts which can set this flag have the flag
'//              fInvalidLogAttr set in their SCRIPT_PROPERTIES.

'/////   ScriptBreak
'//
'//      The ScriptBreak function returns cursor movement and formatting break
'//      positions for an item as an array of SCRIPT_LOGATTRs. To support
'//      mixed formatting within a single word correctly, ScriptBreak should
'//      be passed whole items as returned by ScriptItemize.
'//
'//      ScriptBreak does not require an hdc and does not execute glyph shaping.
'//
'//      The fCharStop flag marks cluster boundaries for those scripts where
'//      it is conventional to restrict from moving inside clusters. The same
'//      boundaries could also be inferred by inspecting the pLogCLust array
'//      returned by ScriptShape, however ScriptBreak is considerably faster in
'//      implementation and does not require an hdc to be prepared.
'//
'//      The fWordStop, fSoftBreak and fWhiteSpace flags are only available
'//      through ScriptBreak.
'//
'//      Most shaping engines that identify invalid sequences do so by setting
'//      the fInvalid flag in ScriptBreak. The fInvalidLogAttr flag in
'//      ScriptProperties identifies which scripts do this.

DECLARE FUNCTION ScriptBreak IMPORT "USP10.DLL" ALIAS "ScriptBreak" ( _
   BYREF pwcChars AS WORD _                             ' __in  const WCHAR           *pwcChars // Logical unicode item
 , BYVAL cChars AS LONG _                               ' __in  int                    cChars   // Length of unicode item
 , BYREF psa AS SCRIPT_ANALYSIS _                       ' __in  const SCRIPT_ANALYSIS *psa      // Result of earlier ScriptItemize call
 , BYREF psla AS SCRIPT_LOGATTR _                       ' __out SCRIPT_LOGATTR        *psla     // Logical character attributes
 ) AS LONG                                              ' HRESULT

'/////   ScriptCPtoX
'//
'//      The ScriptCPtoX function returns the x offset from the left end
'//      (!fLogical) or leading edge (fLogical) of a run to either the leading
'//      or the trailing edge of a logical character cluster.
'//
'//      iCP is the offset of any logical character in the cluster.
'//
'//      For scripts where the caret may conventionally be placed into the
'//      middle of clusters (e.g. Arabic, Hebrew), the returned X may be
'//      an interpolated position for any codepoint in the line.
'//
'//      For scripts where the caret is conventionally snapped to the boundaries
'//      of clusters, (e.g. Thai, Indian), the resulting X position will be
'//      snapped to the requested edge of the cluster containing CP.

DECLARE FUNCTION ScriptCPtoX IMPORT "USP10.DLL" ALIAS "ScriptCPtoX" ( _
   BYVAL iCP AS LONG _                                  ' __in  int                    iCP        // Logical character position in run
 , BYVAL fTrailing AS LONG _                            ' __in  BOOL                   fTrailing  // Which edge (default - leading)
 , BYVAL cChars AS LONG _                               ' __in  int                    cChars     // Count of logical codepoints in run
 , BYVAL cGlyphs AS LONG _                              ' __in  int                    cGlyphs    // Count of glyphs in run
 , BYREF pwLogClust AS WORD _                           ' __in  const WORD            *pwLogClust // Logical clusters
 , BYREF psva AS SCRIPT_VISATTR _                       ' __in  const SCRIPT_VISATTR  *psva       // Visual glyph attributes array
 , BYREF piAdvance AS LONG _                            ' __in  const int             *piAdvance  // Advance widths
 , BYREF psa AS SCRIPT_ANALYSIS _                       ' __in  const SCRIPT_ANALYSIS *psa        // Script analysis from item attributes
 , BYREF piX AS LONG _                                  ' __out int                   *piX        // Resulting X position
 ) AS LONG                                              ' HRESULT

'/////   ScriptXtoCP
'//
'//      The ScriptXtoCP function converts an x offset from the left end
'//      (!fLogical) or leading edge (fLogical) of a run to a logical
'//      character position and a flag that indicates whether the X position
'//      fell in the leading or the trailing half of the character.
'//
'//      For scripts where the cursor may conventionally be placed into the
'//      middle of clusters (e.g. Arabic, Hebrew), the returned CP may be
'//      for any codepoint in the line, and fTrailing will be either zero
'//      or one.
'//
'//      For scripts where the cursor is conventionally snapped to the
'//      boundaries of a cluster, the returned CP is always the position of
'//      the logically first codepoint in a cluster, and fTrailing is either
'//      zero, or the number of codepoints in the cluster.
'//
'//      Thus the appropriate cursor position for a mouse hit is always the
'//      returned CP plus the value of fTrailing.
'//
'//      If the X positition passed is not in the item at all, the resulting
'//      position will be the trailing edge of character -1 (for X positions
'//      before the item), or the leading edge of character 'cChars' (for
'//      X positions following the item).

DECLARE FUNCTION ScriptXtoCP IMPORT "USP10.DLL" ALIAS "ScriptXtoCP" ( _
   BYVAL iX AS LONG _                                   ' __in  int                    iX          // X offset from left of run
 , BYVAL cChars AS LONG _                               ' __in  int                    cChars      // Count of logical codepoints in run
 , BYVAL cGlyphs AS LONG _                              ' __in  int                    cGlyphs     // Count of glyphs in run
 , BYREF pwLogClust AS WORD _                           ' __in  const WORD            *pwLogClust  // Logical clusters
 , BYREF psva AS SCRIPT_VISATTR _                       ' __in  const SCRIPT_VISATTR  *psva        // Visual glyph attributes
 , BYREF piAdvance AS LONG _                            ' __in  const int             *piAdvance   // Advance widths
 , BYREF psa AS SCRIPT_ANALYSIS _                       ' __in  const SCRIPT_ANALYSIS *psa         // Script analysis from item attributes
 , BYREF piCP AS LONG _                                 ' __out int                   *piCP        // Resulting character position
 , BYREF piTrailing AS LONG _                           ' __out int                   *piTrailing  // Leading or trailing half flag
 ) AS LONG                                              ' HRESULT

'/////   Relationship between caret positions, justifications points and clusters
'//
'//
'//t     Job                              | Uniscribe support
'//t     -------------------------------- | --------------------------------------------------------
'//t     Caret move by character cluster  | LogClust or VISATTR.fClusterStart or LOGATTR.fCharStop
'//t     Line breaking between characters | LogClust or VISATTR.fClusterStart or LOGATTR.fCharStop
'//t     Caret move by word               | LOGATTR.fWordStop
'//t     Line breaking between words      | LOGATTR.fWordStop
'//t     Justification                    | VISATTR.uJustification
'//
'//
'//
'/////   Character clusters
'//
'//      Character clusters are glyph sequences that cannot be split between
'//      lines.
'//
'//      Some languages (e.g. Thai, Indic) restrict caret placement to points
'//      betwen clusters. This applies both to keyboard initiated caret
'//      movement (e.g. cursor keys) and pointing and clicking with the mouse
'//      (hit testing).
'//
'//      Uniscribe provides cluster information in both the visual and logical
'//      attributes. If you've called ScriptShape you'll find the cluster
'//      information represented both by sequences of the same value in the
'//      pwLogClust array, and by the fClusterStart flag in the psva
'//      SCRIPT_VISATTR array.
'//
'//      ScriptBreak also returns the fCharStop flag in the SCRIPT_LOGATTR
'//      array to identify cluster positions.
'//
'//
'//
'/////   Word break points
'//
'//      Valid positions for moving the caret when moving in whole words are
'//      marked by the fWordStop flag returned by ScriptBreak.
'//
'//      Valid positions for breaking lines between words are marked by the
'//      fSoftBreak flag returned by ScriptBreak.
'//
'//
'//
'/////   Justification
'//
'//      Justification space or kashida should be inserted where identified by
'//      the uJustificaion field of the SCRIPT_VISATTR.
'//
'//      When performing inter-character justification, insert extra space
'//      only after glyphs marked with uJustify == SCRIPT_JUSTIFY_CHARACTER.
'//
'//
'//
'/////   Script specific processing
'//
'//      Uniscribe provides information about special processing for each
'//      script in the SCRIPT_PROPERTIES array.
'//
'//      Use the following code during initialisation to get a pointer to
'//      the SCRIPT_PROPERTIES array:
'//
'//c     const SCRIPT_PROPERTIES **g_ppScriptProperties; // Array of pointers to properties
'//c     int iMaxScript;
'//c     HRESULT hr;
'//
'//c     hr = ScriptGetProperties(&g_ppScriptProperties, &g_iMaxScript);
'//
'//      Then inspect the properties of the script of an item 'iItem' as follows:
'//
'//c     hr = ScriptItemize( ... , pItems, ... );
'//c     ...
'//c     if (g_ppScriptProperties[pItems[iItem].a.eScript]->fNeedsCaretInfo) {
'//c         // Use ScriptBreak to restrict the caret from entering clusters (for example).
'//c     }
'//
'//
'//      SCRIPT_PROPERTIES.fNeedsCaretInfo
'//
'//      Caret placement should be restricted to cluster
'//      edges for scripts such as Thai and Indian. The fNeedsCaretInfo flag
'//      in SCRIPT_PROPERTIES identifies such languages.
'//
'//      Note that ScriptXtoCP and ScriptCPtoX automatically apply caret
'//      placement restictions.
'//
'//
'//      SCRIPT_PROPERTIES.fNeedsWordBreaking
'//
'//      For most scripts, word break placement  may be
'//      identified by scanning for characters marked as fWhiteSpace in
'//      SCRIPT_LOGATTR, or for glyphs marked as uJustify ==
'//      SCRIPT_JUSTIFY_BLANK or SCRIPT_JUSTIFY_ARABIC_BLANK in SCRIPT_VISATTR.
'//
'//      For languages such as Thai, it is also necessary to call ScriptBreak,
'//      and include character positions marked as fWordStop in SCRIPT_LOGATTR.
'//      Such scripts are marked as fNeedsWordbreaking in SCRIPT_PROPERTIES.
'//
'//
'//      SCRIPT_PROPERTIES.fNeedsCharacterJustify
'//
'//      Languages such as Thai also require inter-character spacing when
'//      justifying (where uJustify == SCRIPT_JUSTIFY_CHARACTER in the
'//      SCRIPT_VISATTR). Such languages are marked as fNeedsCharacterJustify
'//      in SCRIPT_PROPERTIES.
'//
'//
'//      SCRIPT_PROPERTIES.fAmbiguousCharSet
'//
'//      Many Uniscribe scripts do not correspond directly to 8 bit character
'//      sets. For example Unicode characters in the range U+100 through U+024F
'//      represent extended latin shapes used for many languages, including
'//      those supported by EASTEUROPE_CHARSET, TURKISH_CHARSET and
'//      VIETNAMESE_CHARSET. However many of these characters are supported by
'//      more han one of thsese charsets.
'//      fAmbiguousCharset is set for any script token which could contain
'//      characters from a number of these charsets. In these cases the bCharSet
'//      field may contain ANSI_CHARSET or DEFAULT_CHARSET. The Uniscribe client
'//      will generally need to apply futher processing to determine which charset
'//      to use when requesting a font suitable for this run. For example it
'//      determine that the run consists of multiple languages and split it up
'//      to use a different font for each language.


'/////   Notes on ScriptXtoCP and ScriptCPtoX
'//
'//      Both functions work only within runs and require the results of a
'//      previous ScriptShape call.
'//
'//      The client must establish which run a given cursor offset or x
'//      position is within before passing it to ScriptCPtoX or ScriptXtoCP.
'//
'//      Cluster information in the logical cluster array is used to share
'//      the width of a cluster of glyphs equally among the logical characters
'//      they represent.
'//
'//      For example, the lam alif glyph is divided into four areas: the
'//      leading half of the lam, the trailing half of the lam, the leading
'//      half of the alif and the trailing half of the alif.
'//
'//      ScriptXtoCP Understands the caret position conventions of each script.
'//      For Indian and Thai, caret positions are snapped to cluster boundaries,
'//      for Arabic and Hebrew, caret positions are interpolated within clusters.
'//
'//
'/////   Translating mouse hit 'x' offset to caret position
'//
'//      Conventionally, caret position 'cp' may be selected by clicking either
'//      on the trailing half of character 'cp-1' or on the leading half of
'//      character 'cp'. This may easily be implemented as follows:
'//
'//c     int iCharPos;
'//c     int iCaretPos
'//c     int fTrailing;
'//
'//c     ScriptXtoCP(iMouseX, ..., &iCharPos, &fTrailing);
'//c     iCaretPos = iCharPos + fTrailing;
'//
'//      For scripts that snap the caret to cluster boundaries, ScriptXtoCP
'//      returns ftrailing set to either 0, or the width of the cluster in
'//      codepoints. Thus the above code correctly returns only valid
'//      caret positions.
'//
'//
'/////   Displaying the caret in bidi strings
'//
'//      In unidirectional text, the leading edge of a character is at the same
'//      place as the trailing edge of the previous character, so there is no
'//      ambiguity in placing the caret between characters.
'//
'//      In bidirectional text, the caret position between runs of opposing
'//      direction may be ambiguous.
'//
'//      For example in the left to right paragraph 'helloMAALAS', the last
'//      letter of 'hello' immediately preceeds the first letter of 'salaam'.
'//      The best position to display the caret depends on whether it is
'//      considered to follow the 'o' of 'hello', or to preceed the 's' of
'//      'salaam'.
'//
'/////   Commonly used caret positioning conventions
'//
'//t     Situation       | Visual caret placement
'//t     ---------       | -------------------------------------------
'//t     Typing          | Trailing edge of last character typed
'//t     Pasting         | Trailing edge of last character pasted
'//t     Caret advancing | Trailing edge of last character passed over
'//t     Caret retiring  | Leading edge of last character passed over
'//t     Home            | Leading edge of line
'//t     End             | Trailing edge of line
'//
'//      The caret may be positioned as follows:
'//
'//c     if (advancing) {
'//c         ScriptCPtoX(iCharPos-1, TRUE, ..., &iCaretX);
'//c     } else {
'//c         ScriptCPtoX(iCharPos, FALSE, ..., &iCaretX);
'//c     }
'//
'//      Or, more simply, given an fAdvancing BOOL restricted to TRUE or FALSE:
'//
'//c     ScriptCPtoX(iCharPos-fAdvancing, fAdvancing, ..., &iCaretX);
'//
'//      ScriptCPtoX handles out of range positions logically: it returns the
'//      leading edge of the run for iCharPos <0, and the trailing edge of the
'//      run for iCharPos >=length.
'/////   ScriptGetLogicalWidths
'//
'//      Converts visual withs in piAdvance into logical widths,
'//      one per original character, in logical order.
'//
'//      Ligature glyphs widths are divided evenly amongst the characters
'//      they represent.

DECLARE FUNCTION ScriptGetLogicalWidths IMPORT "USP10.DLL" ALIAS "ScriptGetLogicalWidths" ( _
   BYREF psa AS SCRIPT_ANALYSIS _                       ' __in  const SCRIPT_ANALYSIS *psa           // Script analysis from item attributes
 , BYVAL cChars AS LONG _                               ' __in  int                    cChars        // Count of logical codepoints in run
 , BYVAL cGlyphs AS LONG _                              ' __in  int                    cGlyphs       // Count of glyphs in run
 , BYREF piGlyphWidth AS LONG _                         ' __in  const int             *piGlyphWidth  // Advance widths
 , BYREF pwLogClust AS WORD _                           ' __in  const WORD            *pwLogClust    // Logical clusters
 , BYREF psva AS SCRIPT_VISATTR _                       ' __in  const SCRIPT_VISATTR  *psva          // Visual glyph attributes
 , BYREF piDx AS LONG _                                 ' __out int                   *piDx          // Logical widths
 ) AS LONG                                              ' HRESULT

'/////
'//      ScriptGetLogicalWidths is useful for recording widths in a
'//      font independant manner. By passing the recorded logical widths
'//      to ScriptApplyLogicalWidths, a block of text can be replayed in the
'//      same boundaries with acceptable loss of quality even when the original
'//      font is not available.
'/////   ScriptApplyLogicalWidth
'//
'//      Accepts an array of advance widths in logical order, corresponding
'//      one to one with codepoints, and generates an array of glyph widths
'//      suitable for passing to the piJustify parameter of ScriptTextOut.
'//
'//      ScriptApplyLogicalWidth may be used to reapply logical widths
'//      obtained with ScriptGetLogicalWidths. It may be useful in situations
'//      such as metafiling, where it is necessary to record and reapply
'//      advance width information in a font independant manner.

DECLARE FUNCTION ScriptApplyLogicalWidth IMPORT "USP10.DLL" ALIAS "ScriptApplyLogicalWidth" ( _
   BYREF piDx AS LONG _                                 ' __in     const int             *piDx        // Logical dx array to apply
 , BYVAL cChars AS LONG _                               ' __in     int                    cChars      // Count of logical codepoints in run
 , BYVAL cGlyphs AS LONG _                              ' __in     int                    cGlyphs     // Glyph count
 , BYREF pwLogClust AS WORD _                           ' __in     const WORD            *pwLogClust  // Logical clusters
 , BYREF psva AS SCRIPT_VISATTR _                       ' __in     const SCRIPT_VISATTR  *psva        // Visual attributes from ScriptShape/Place
 , BYREF piAdvance AS LONG _                            ' __in     const int             *piAdvance   // Glyph advance widths from ScriptPlace
 , BYREF psa AS SCRIPT_ANALYSIS _                       ' __in     const SCRIPT_ANALYSIS *psa         // Script analysis from item attributes
 , BYREF pABC AS ABC _                                  ' __in_out ABC                   *pABC        // Updated item ABC width (optional)
 , BYREF piJustify AS LONG _                            ' __out    int                   *piJustify   // Resulting glyph advance widths for ScriptTextOut
 ) AS LONG                                              ' HRESULT

'/////
'//p     piDx: Pointer to an array of dx widths in logical order, one per codepoint.
'//
'//p     cChars: Count of the logical codepoints in the run.
'//
'//p     cGlyphs: Glyph count.
'//
'//p     pwLogClust: Pointer to an array of logical clusters from ScriptShape
'//
'//p     psva: Pointer to an array of visual attributes from ScriptShape and
'//          updated by ScriptPlace.
'//
'//p     piAdvance: Pointer to an array of glyph advance widths from ScriptPlace.
'//
'//p     psa: Pointer to a SCRIPT_ANALYSIS structure from ScriptItemize and
'//          updated by ScriptShape and SriptPlace..
'//
'//p     pABC: Pointer to the run overall ABC width (optional). If present,
'//          when the function is called, it should contain the run ABC width
'//          returned by ScriptPlace; when the function returns, the ABC width
'//          has been updated to match the new widths.
'//
'//p     piJustify:Pointer to an array of the resulting glyph advance widths.
'//          This is suitable for passing to the piJustify parameter of ScriptTextOut.
'/////   ScriptGetCMap
'//
'//      ScriptGetCMap may be used to determine which characters in a run
'//      are supported by the selected font.
'//
'//      It returns glyph indices of Unicode characters according to Truetype
'//      Cmap table, or standard Cmap implemented for old style fonts. The
'//      glyph indices are returned in the same order as the input string.
'//
'//      The caller may scan the returned glyph buffer looking for the default
'//      glyph to determine which characters are not available. (The default
'//      glyph index for the selected font should be determined by calling
'//      ScriptGetFontProperties).
'//
'//      The return value indicates the presence of any missing glyphs.

%SGCM_RTL  = &H00000001???     ' // Return mirrored glyph for mirrorable Unicode codepoints

DECLARE FUNCTION ScriptGetCMap IMPORT "USP10.DLL" ALIAS "ScriptGetCMap" ( _
   BYVAL hdc AS DWORD _                                 ' __in     HDC           hdc         // Optional (see notes on caching)
 , BYREF psc AS DWORD _                                 ' __in_out SCRIPT_CACHE *psc         // Address of Cache handle
 , BYREF pwcInChars AS WORD _                           ' __in     const WCHAR  *pwcInChars  // Unicode codepoint(s) to look up
 , BYVAL cChars AS LONG _                               ' __in     int           cChars      // Number of characters
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD         dwFlags     // Flags such as SGCM_RTL
 , BYREF pwOutGlyphs AS WORD _                          ' __out    WORD         *pwOutGlyphs // Array of glyphs, one per input character
 ) AS LONG                                              ' HRESULT

'/////
'//  returns S_OK     - All unicode codepoints were present in the font
'//          S_FALSE  - Some of the Unicode codepoints were mapped to the default glyph
'//          E_HANDLE - font or system does not support glyph indices
'/////   ScriptGetGlyphABCWidth
'//
'//      Returns ABC width of a given glyph.
'//      May be useful for drawing glyph charts. Should not be used for
'//      run of the mill complex script text formatting.

DECLARE FUNCTION ScriptGetGlyphABCWidth IMPORT "USP10.DLL" ALIAS "ScriptGetGlyphABCWidth" ( _
   BYVAL hdc AS DWORD _                                 ' __in     HDC           hdc    // Optional (see notes on caching)
 , BYREF psc AS DWORD _                                 ' __in_out SCRIPT_CACHE *psc    // Address of Cache handle
 , BYVAL wGlyph AS WORD _                               ' __in     WORD          wGlyph // Glyph
 , BYREF pABC AS ABC _                                  ' __in     ABC          *pABC   // ABC width
 ) AS LONG                                              ' HRESULT

'/////
'//  returns S_OK     - Glyph width returned
'//          E_HANDLE - font or system does not support glyph indices
'/////   SCRIPT_PROPERTIES
'//

' // Size = 8 bytes
TYPE SCRIPT_PROPERTIES DWORD
   langid                 AS BIT * 16 IN DWORD   ' // Primary and sublanguage associated with script
   fNumeric               AS BIT * 1
   fComplex               AS BIT * 1             ' // Script requires special shaping or layout
   fNeedsWordBreaking     AS BIT * 1             ' // Requires ScriptBreak for word breaking information
   fNeedsCaretInfo        AS BIT * 1             ' // Requires caret restriction to cluster boundaries
   bCharSet               AS BIT * 8             ' // Charset to use when creating font
   fControl               AS BIT * 1             ' // Contains only control characters
   fPrivateUseArea        AS BIT * 1             ' // This item is from the Unicode range U+E000 through U+F8FF
   fNeedsCharacterJustify AS BIT * 1  IN DWORD   ' // Requires inter-character justification
   fInvalidGlyph          AS BIT * 1             ' // Invalid combinations generate glyph wgInvalid in the glyph buffer
   fInvalidLogAttr        AS BIT * 1             ' // Invalid combinations are marked by fInvalid in the logical attributes
   fCDM                   AS BIT * 1             ' // Contains Combining Diacritical Marks
   fAmbiguousCharSet      AS BIT * 1             ' // Script does not correspond 1:1 with a charset
   fClusterSizeVaries     AS BIT * 1             ' // Measured cluster width depends on adjacent clusters
   fRejectInvalid         AS BIT * 1             ' // Invalid combinations should be rejected
END TYPE

'//
'//p     langid: Language associated with this script. When a script is used for many languages,
'//          langid id represents a default language. For example, Western script is represented
'//          by LANG_ENGLISH although it is also used for French, German, Spanish etc.
'//
'//p     fNumeric: Script contains numerics and characters used in conjunction with numerics
'//          by the rules of the Unicode bidirectional algorithm. For example
'//          dollar sign and period are classified as numeric when adjacent to or in between
'//          digits.
'//
'//p     fComplex: Indicates a script that requires complex script handling. If fComplex is false
'//          the script contains no combining characters and requires no contextual shaping or reordering.
'//
'//p     fNeedsWordBreaking: A script, such as Thai, which requires algorithmic wordbreaking.
'//          Use ScriptBreak to obtain a wordbreak points using the standard system wordbreaker.
'//
'//p     fNeedsCaretInfo: A script, such as Thai and Indian, where the caret may not be placed
'//          inside a cluster. To determine valid caret positions inspect the fCharStop flag in the
'//          logical attributes returned by ScriptBreak, or compare adjacent values in the pwLogClust
'//          array returned by ScriptShape.
'//
'//p     bCharSet: Nominal charset associated with script. May be used in a logfont when creating
'//          a font suitable for displaying this script. Note that for new scripts where there
'//          is no charset defined, bCharSet may be innapropriate and DEFAULT_CHARSET should
'//          be used instead - see the description of fAmbiguousCharSet below.
'//
'//p     fControl: contains control characters.
'//
'//p     fPrivateUseArea: The Unicode range U+E000 through U+F8FF.
'//
'//p     fNeedsCharacterJustify: A script, such as Thai, where justification is conventionally
'//          achieved by increasing the space between all letters, not just between words.
'//
'//p     fInvalidGlyph: A script for which ScriptShape generates an invalid glyph
'//          to represent invalid sequences. The glyph index of the invalid glyph for
'//          a particular font may be obtained by calling ScriptGetFontProperties.
'//
'//p     fInvalidLogAttr: A script for which ScriptBreak sets the fInvalid flag
'//          in the logical attributes to mark invalid sequences.
'//
'//p     fCDM: Implies that an item analysed by ScriptItemize included combining
'//          diacritical marks (U+0300 through U+36F).
'//
'//p     fAmbiguousCharSet: No single legacy charset supports this script.
'//          For example the extended Latin Extended-A Unicode range includes
'//          characters from the EASTUROPE_CHARSET, the TURKISH_CHARSET and the
'//          BALTIC_CHARSET. It also contains characters that are not available
'//          in any legacy charset. Use DEFAULT_CHARSET when creating fonts to
'//          display parts of this run.
'//
'//p     fClusterSizeVaries: A script, such as Arabic, where contextual shaping
'//          may cause a string to increase in size when removing characters.
'//
'//p     fRejectInvalid: A script, such as Thai, where invalid sequences conventionally
'//          cause an editor such as notepad to beep, and ignore keypresses.

'/////   ScriptGetProperties
'//
'//      ScriptGetProperties returns the address of a table that maps a
'//      script in a SCRIPT_ANALYSIS uScript field to properties including
'//      the primary language associated with that script, whether it's
'//      numeric and whether it's complex.

DECLARE FUNCTION ScriptGetProperties IMPORT "USP10.DLL" ALIAS "ScriptGetProperties" ( _
   BYREF ppSp AS DWORD _                                ' __out const SCRIPT_PROPERTIES ***ppSp             // Receives pointer to table of pointers to properties indexed by script
 , BYREF piNumScripts AS LONG _                         ' __out int                       *piNumScripts     // Receives number of scripts (valid values are 0 through NumScripts-1)
 ) AS LONG                                              ' HRESULT

'/////   SCRIPT_FONTPROPERTIES
'//
' // Size = 16 bytes
TYPE SCRIPT_FONTPROPERTIES DWORD FILL
   cBytes        AS LONG   ' int  // Structure length
   wgBlank       AS WORD   ' WORD // Blank glyph
   wgDefault     AS WORD   ' WORD // Glyph used for Unicode values not present in the font
   wgInvalid     AS WORD   ' WORD // Glyph used for invalid character combinations (especially in Thai)
   wgKashida     AS WORD   ' WORD // Shortest continuous kashida glyph in the font, -1 if doesn't exist
   iKashidaWidth AS LONG   ' int  // Widths of shortest continuous kashida glyph in the font
END TYPE

'/////   ScriptGetFontProperties
'//
'//      Returns information from the font cache

DECLARE FUNCTION ScriptGetFontProperties IMPORT "USP10.DLL" ALIAS "ScriptGetFontProperties" ( _
   BYVAL hdc AS DWORD _                                 ' __in     HDC                     hdc  // Optional (see notes on caching)
 , BYREF psc AS DWORD _                                 ' __in_out SCRIPT_CACHE           *psc  // Address of Cache handle
 , BYREF sfp AS SCRIPT_FONTPROPERTIES _                 ' __out    SCRIPT_FONTPROPERTIES  *sfp  // Receives properties for this font
 ) AS LONG                                              ' HRESULT

'/////   ScriptCacheGetHeight
'//
'//

DECLARE FUNCTION ScriptCacheGetHeight IMPORT "USP10.DLL" ALIAS "ScriptCacheGetHeight" ( _
   BYVAL hdc AS DWORD _                                 ' __in     HDC            hdc       // Optional (see notes on caching)
 , BYREF psc AS DWORD _                                 ' __in_out SCRIPT_CACHE  *psc       // Address of Cache handle
 , BYREF tmHeight AS LONG _                             ' __out    long          *tmHeight  // Receives font height in pixels
 ) AS LONG                                              ' HRESULT

'/////   ScriptStringAnalyse
'//
'//
%SSA_PASSWORD         = &H00000001  ' // Input string contains a single character to be duplicated iLength times
%SSA_TAB              = &H00000002  ' // Expand tabs
%SSA_CLIP             = &H00000004  ' // Clip string at iReqWidth
%SSA_FIT              = &H00000008  ' // Justify string to iReqWidth
%SSA_DZWG             = &H00000010  ' // Provide representation glyphs for control characters
%SSA_FALLBACK         = &H00000020  ' // Use fallback fonts
%SSA_BREAK            = &H00000040  ' // Return break flags (character and word stops)
%SSA_GLYPHS           = &H00000080  ' // Generate glyphs, positions and attributes
%SSA_RTL              = &H00000100  ' // Base embedding level 1
%SSA_GCP              = &H00000200  ' // Return missing glyphs and LogCLust with GetCharacterPlacement conventions
%SSA_HOTKEY           = &H00000400  ' // Replace '&' with underline on subsequent codepoint
%SSA_METAFILE         = &H00000800  ' // Write items with ExtTextOutW Unicode calls, not glyphs
%SSA_LINK             = &H00001000  ' // Apply FE font linking/association to non-complex text
%SSA_HIDEHOTKEY       = &H00002000  ' // Remove first '&' from displayed string
%SSA_HOTKEYONLY       = &H00002400  ' // Display underline only.

%SSA_FULLMEASURE      = &H04000000  ' // Internal - calculate full width and out the number of chars can fit in iReqWidth.
%SSA_LPKANSIFALLBACK  = &H08000000  ' // Internal - enable FallBack for all LPK Ansi calls Except BiDi hDC calls
%SSA_PIDX             = &H10000000  ' // Internal
%SSA_LAYOUTRTL        = &H20000000  ' // Internal - Used when DC is mirrored
%SSA_DONTGLYPH        = &H40000000  ' // Internal - Used only by GDI during metafiling - Use ExtTextOutA for positioning
%SSA_NOKASHIDA        = &H80000000  ' // Internal - Used by GCP to justify the non Arabic glyphs only.

'//
'//
'//p     SSA_HOTKEY: Note that SSA_HOTKEY and SSA_HIDEHOTKEY remove the
'//          hotkey '&' character from further processing, so functions
'//          such as ScriptString_pLogAttr return arrays based on a string
'//          which excludes the '&'.

'/////   SCRIPT_TABDEF
'//
'//      Defines tabstop positions for ScriptStringAnalyse (ignored unless SSA_TAB passed)
'//

' // Size = 16 bytes
TYPE SCRIPT_TABDEF DWORD
   cTabStops  AS LONG   ' int   // Number of entries in pTabStops array
   iScale     AS LONG   ' int   // Scale factor for pTabStops (see below)
   pTabStops  AS LONG   ' int * // Pointer to array of one or more tab stops
   iTabOrigin AS LONG   ' int   // Initial offset for tab stops (logical units)
END TYPE

'//
'//
'//p     cTabStops: Number of entries in the pTabStops array. If zero, tabstops
'//          are every 8 average character widths. If one, all tabstops are
'//          the length of the first entry in pTabStops. If more than one,
'//          the first cTabStops are as specified in the pTabStops array,
'//          subsequent tabstops are every 8 average characters from the last
'//          tabstop in the array.
'//
'//p     iScale: Scale factor for iTabOrigin and pTabStops entries. Values are
'//          converted to device coordinates by multiplying by iScale then
'//          dividing by 4. If values are already in device units, set iScale to
'//          4. If values are in dialog units, set iScale to the average char
'//          width of the dialog font. If values are multiples of the average
'//          character width for the selected font, set iScale to 0.
'//
'//p     pTabStops: Array of cTabStops entries. Each entry specifies a
'//          tabstop position. Positive values give nearedge alignment,
'//          negative values give faredge alignment.
'//
'//p     iTabOrigin: Tabs are considered to start iTabOrigin before the
'//          beginning of the string. Helps with multiple tabbed
'//          outputs on the same line.

'/////   ScriptStringAnalyse
'//
'//      cString - Input string must contain at least one character
'//
'//      hdc - required if SSA_GLYPH requested. Optional for SSA_BREAK.
'//      If present the current font in the hdc is inspected and if a symbolic
'//      font the character string is treated as a single neutral SCRIPT_UNDEFINED item.
'//
'//      Note that the uBidiLevel field in the initial SCRIPT_STATE value
'//      is ignored - the uBidiLevel used is derived from the SSA_RTL
'//      flag in combination with the layout of the hdc.

'typedef void* SCRIPT_STRING_ANALYSIS;

DECLARE FUNCTION ScriptStringAnalyse IMPORT "USP10.DLL" ALIAS "ScriptStringAnalyse" ( _
   BYVAL hdc AS DWORD _                                 ' __in  HDC                      hdc        // Device context (required)
 , BYVAL pString AS DWORD _                             ' __in  const void              *pString    // String in 8 or 16 bit characters
 , BYVAL cString AS LONG _                              ' __in  int                      cString    // Length in characters (Must be at least 1)
 , BYVAL cGlyphs AS LONG _                              ' __in  int                      cGlyphs    // Required glyph buffer size (default cString*1.5 + 16)
 , BYVAL iCharset AS LONG _                             ' __in  int                      iCharset   // Charset if an ANSI string, -1 for a Unicode string
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD                    dwFlags    // Analysis required
 , BYVAL iReqWidth AS LONG _                            ' __in  int                      iReqWidth  // Required width for fit and/or clip
 , BYREF psControl AS SCRIPT_CONTROL _                  ' __in  SCRIPT_CONTROL          *psControl  // Analysis control (optional)
 , BYREF psState AS SCRIPT_STATE _                      ' __in  SCRIPT_STATE            *psState    // Analysis initial state (optional)
 , BYREF piDx AS LONG _                                 ' __in  const int               *piDx       // Requested logical dx array
 , BYREF pTabdef AS SCRIPT_TABDEF _                     ' __in  SCRIPT_TABDEF           *pTabdef    // Tab positions (optional)
 , BYREF pbInClass AS BYTE _                            ' __in  const BYTE              *pbInClass  // Legacy GetCharacterPlacement character classifications (deprecated)
 , BYREF pssa AS DWORD _                                ' __out SCRIPT_STRING_ANALYSIS  *pssa       // Analysis of string
 ) AS LONG                                              ' HRESULT

'/////   ScriptStringFree - free a string analysis
'//
'//

DECLARE FUNCTION ScriptStringFree IMPORT "USP10.DLL" ALIAS "ScriptStringFree" ( _
   BYREF pssa AS DWORD _                                ' __in_out SCRIPT_STRING_ANALYSIS *pssa  // Address of pointer to analysis
 ) AS LONG                                              ' HRESULT

'/////   ScriptStringSize
'//
'//      returns a pointer to the size (width and height) of an analysed string
'//
'//      Note that the SIZE pointer remains valid only until the
'//      SCRIPT_STRING_ANALYSIS is passed to ScriptStringFree.

DECLARE FUNCTION ScriptStringSize IMPORT "USP10.DLL" ALIAS "ScriptStringSize" ( _
   BYREF pssa AS DWORD _                                ' __in SCRIPT_STRING_ANALYSIS *pssa  // Address of pointer to analysis
 ) AS DWORD                                             ' SIZE*

'/////   ScriptString_pcOutChars
'//
'//      returns pointer to length of string after clipping (requires SSA_CLIP set)
'//
'//      Note that the int pointer remains valid only until the
'//      SCRIPT_STRING_ANALYSIS is passed to ScriptStringFree.

DECLARE FUNCTION ScriptString_pcOutChars IMPORT "USP10.DLL" ALIAS "ScriptString_pcOutChars" ( _
   BYREF ssa AS DWORD _                                 ' __in SCRIPT_STRING_ANALYSIS ssa
 ) AS DWORD                                             ' int*

'/////   ScriptString_pLogAttr
'//
'//      returns pointer to logical attributes buffer in a SCRIPT_STRING_ANALYSIS
'//
'//      Note that the buffer pointer remains valid only until the
'//      SCRIPT_STRING_ANALYSIS is passed to ScriptStringFree.
'//
'//      The logical attribute array contains *ScriptString_pcOutChars(ssa)
'//      entries.

DECLARE FUNCTION ScriptString_pLogAttr IMPORT "USP10.DLL" ALIAS "ScriptString_pLogAttr" ( _
   BYREF ssa AS DWORD _                                 ' __in SCRIPT_STRING_ANALYSIS ssa
 ) AS DWORD                                             ' SCRIPT_LOGATTR*

'/////   ScriptStringGetOrder
'//
'//      Creates an array mapping original character position to glyph position.
'//
'//      Treats clusters as they were in legacy systems - Unless a cluster
'//      contains more glyphs than codepoints, each glyph is referenced at
'//      least once from the puOrder array.
'//
'//      Requires SSA_GLYPHS requested in original ScriptStringAnalyse call.
'//
'//      The puOrder parameter should address a buffer containing room for
'//      at least *ScriptString_pcOutChars(ssa) ints.

DECLARE FUNCTION ScriptStringGetOrder IMPORT "USP10.DLL" ALIAS "ScriptStringGetOrder" ( _
   BYREF ssa AS DWORD _                                 ' __in  SCRIPT_STRING_ANALYSIS ssa
 , BYREF puOrder AS DWORD _                             ' __out UINT                   *puOrder
 ) AS LONG                                              ' HRESULT

'/////   ScriptStringCPtoX
'//
'//      Return x coordinate for leading or trailing edge of character icp.

DECLARE FUNCTION ScriptStringCPtoX IMPORT "USP10.DLL" ALIAS "ScriptStringCPtoX" ( _
   BYREF ssa AS DWORD _                                 ' __in  SCRIPT_STRING_ANALYSIS  ssa        // String analysis
 , BYVAL icp AS LONG _                                  ' __in  int                     icp        // Caret character position
 , BYVAL fTrailing AS LONG _                            ' __in  BOOL                    fTrailing  // Which edge of icp
 , BYREF pX AS LONG _                                   ' __out int                    *pX         // Corresponding x offset
 ) AS LONG                                              ' HRESULT

'/////   ScriptStringXtoCP
'//
'//

DECLARE FUNCTION ScriptStringXtoCP IMPORT "USP10.DLL" ALIAS "ScriptStringXtoCP" ( _
   BYREF ssa AS DWORD _                                 ' __in  SCRIPT_STRING_ANALYSIS  ssa
 , BYVAL iX AS LONG _                                   ' __in  int                     iX
 , BYREF piCh AS LONG _                                 ' __out int                    *piCh
 , BYREF piTrailing AS LONG _                           ' __out int                    *piTrailing
 ) AS LONG                                              ' HRESULT

'/////   ScriptStringGetLogicalWidths
'//
'//      Converts visual withs in psa->piAdvance into logical widths,
'//      one per original character, in logical order.
'//
'//      Requires SSA_GLYPHS requested in original ScriptStringAnalyse call.
'//
'//      The piDx parameter should address a buffer containing room for
'//      at least *ScriptString_pcOutChars(ssa) ints.

DECLARE FUNCTION ScriptStringGetLogicalWidths IMPORT "USP10.DLL" ALIAS "ScriptStringGetLogicalWidths" ( _
   BYREF ssa AS DWORD _                                 ' __in  SCRIPT_STRING_ANALYSIS  ssa
 , BYREF piDx AS LONG _                                 ' __out int                    *piDx
 ) AS LONG                                              ' HRESULT

'/////   ScriptStringValidate
'//
'//      Scans the string analysis for invalid glyphs.
'//
'//      Only glyphs generated by scripts that can generate invalid glyphs
'//      are scanned.
'//
'//      returns S_OK    - no invalid glyphs are present
'//              S_FALSE - one or more invalid glyphs are present

DECLARE FUNCTION ScriptStringValidate IMPORT "USP10.DLL" ALIAS "ScriptStringValidate" ( _
   BYREF ssa AS DWORD _                                 ' __in SCRIPT_STRING_ANALYSIS  ssa
 ) AS LONG                                              ' HRESULT

'/////   ScriptStringOut
'//
'//      Displays the string generated by a prior ScriptStringAnalyze call,
'//      then optionally adds highlighting corresponding to a logical selection.
'//
'//      Requires SSA_GLYPHS requested in original ScriptStringAnalyse call.

DECLARE FUNCTION ScriptStringOut IMPORT "USP10.DLL" ALIAS "ScriptStringOut" ( _
   BYREF ssa AS DWORD _                                 ' __in SCRIPT_STRING_ANALYSIS  ssa       // Analysis with glyphs
 , BYVAL iX AS LONG _                                   ' __in int                     iX
 , BYVAL iY AS LONG _                                   ' __in int                     iY
 , BYVAL uOptions AS DWORD _                            ' __in UINT                    uOptions  // ExtTextOut options
 , BYREF prc AS RECT _                                  ' __in const RECT             *prc       // Clipping rectangle (iff ETO_CLIPPED)
 , BYVAL iMinSel AS LONG _                              ' __in int                     iMinSel   // Logical selection. Set iMinSel>=iMaxSel for no selection
 , BYVAL iMaxSel AS LONG _                              ' __in int                     iMaxSel
 , BYVAL fDisabled AS LONG _                            ' __in BOOL                    fDisabled // If disabled, only the background is highlighted.
 ) AS LONG                                              ' HRESULT

'/////
'//      uOptions may nclude only ETO_CLIPPED or ETO_OPAQUE.
'/////   ScriptIsComplex
'//
'//      Determines whether a Unicode string requires complex script processing
'//
'//      The dwFlags parameter may include the following requests
'//

%SIC_COMPLEX    = 1  ' // Treat complex script letters as complex
%SIC_ASCIIDIGIT = 2  ' // Treat digits U+0030 through U+0039 as complex
%SIC_NEUTRAL    = 4  ' // Treat neutrals as complex

'//
'//      SIC_COMPLEX: Should normally set. Causes complex script letters to
'//      be treated as complex.
'//
'//      SIC_ASCIIDIGIT: Set this flag if the string would be displayed with
'//      digit substitution enabled. If you are following the users NLS
'//      settings using the ScriptRecordDigitSubstitution API, you can pass
'//      scriptDigitSubstitute.DigitSubstitute != SCRIPT_DIGITSUBSTITUTE_NONE.
'//
'//      SIC_NEUTRAL: Set this flag if you may be displaying the string with
'//      right-to-left reading order. When this flag is set, neutral characters
'//      are considered as complex.
'//
'//
'//      Returns S_OK     if string requires complex script processing,
'//              S_FALSE  if string contains only characters laid out side by
'//                       side from left to right.

DECLARE FUNCTION ScriptIsComplex IMPORT "USP10.DLL" ALIAS "ScriptIsComplex" ( _
   BYREF pwcInChars AS WORD _                           ' __in const WCHAR *pwcInChars // String to be tested
 , BYVAL cInChars AS LONG _                             ' __in int          cInChars   // Length in characters
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD        dwFlags    // Flags (see above)
 ) AS LONG                                              ' HRESULT

'/////   ScriptRecordDigitSubstitution
'//
'//      Reads NLS native digit and digit substitution settings and records
'//      them in the SCRIPT_DIGITSUBSTITUTE structure.
'//
'//

' // Size = 12 bytes
TYPE SCRIPT_DIGITSUBSTITUTE DWORD
   NationalDigitLanguage    AS BIT   * 16  IN DWORD   ' // Language for native substitution
   TraditionalDigitLanguage AS BIT   * 16             ' // Language for traditional substitution
   DigitSubstitute          AS BIT   * 8   IN DWORD   ' // Substitution type
   dwReserved               AS DWORD                  ' // Reserved
END TYPE

'//
'//
'//p     NationalDigitLanguage: Standard digits for the selected locale as
'//          defined by the countries standard setting authority.
'//
'//p     TraditionalDigitLangauge: Digits originally used with the locales
'//          script.
'//
'//p     DigitSubstitute: Selects between None, Context, National and
'//          Traditional. See ScriptApplyDigitSubstitution below for
'//          constant definitions.
'//
'//      Although most complex scripts have their own associated digits, many
'//      countries using those scripts use western (so called
'//      'Arabic') digits as their standard. NationalDigitLanguage reflects the
'//      digits used as standard, and is set from
'//      the NLS data for the locale.
'//      On Windows 2000 the national digit langauge can be
'//      adjusted to any digit script with the control panel/regional
'//      options/numbers/Standard digits listbox.
'//
'//      The TraditionalDigitLanguage for a locale is derived directly from the
'//      script used by that locale.

DECLARE FUNCTION ScriptRecordDigitSubstitution IMPORT "USP10.DLL" ALIAS "ScriptRecordDigitSubstitution" ( _
   BYVAL Locale AS DWORD _                              ' __in  LCID                    Locale // LOCALE_USER_DEFAULT or desired locale
 , BYREF psds AS SCRIPT_DIGITSUBSTITUTE _               ' __out SCRIPT_DIGITSUBSTITUTE *psds   // Digit substitution settings
 ) AS LONG                                              ' HRESULT

'/////
'//p     Locale: NLS locale to be queried. Should usually be set to
'//          LOCALE_USER_DEFAULT. Alternatively may be passed as a locale
'//          combined with LOCALE_NOUSEROVERRIDE to obtain default settings
'//          for a given locale. Note that context digit substitution is
'//          supported only in ARABIC and FARSI locales. In other locales,
'//          context digit is mapped to no substitution.
'//
'//p     psds: Pointer to SCRIPT_DIGITSUBSTITUTE. This structure may be passed
'//          later to ScriptApplyDigitSubstitution.
'//
'//p     returns: E_INVALIDARG if Locale is invalid or not installed. E_POINTER
'//          if psds is NULL. Otherwise S_OK.
'//
'//      For performance reasons, you should not call
'//      ScriptRecordDigitSubstitution frequently. In particular it would be a
'//      considerable overhead to call it every time you call ScriptItemize
'//      or ScriptStringAnalyse.
'//
'//      Instead, you may choose to save the SCRIPT_DIGITSUBSTITUTE
'//      structure, and update it only when you receive a
'//      WM_SETTINGCHANGE message or when a RegNotifyChangeKeyValue
'//      call in a dedicated thread indicates a change in the registry
'//      under HKCU\Control Panel\\International.
'//
'//      The normal way to call this function is simply
'//
'//c     SCRIPT_DIGITSUBSTITUTE sds;
'//c     ScriptRecordDigitSubstitution(LOCALE_USER_DEFAULT, &sds);
'//
'//      Then every time you itemize, you'd use the results like this:
'//
'//c     SCRIPT_CONTROL  sc = {0};
'//c     SCRIPT_STATE    ss = {0};
'//
'//c     ScriptApplyDigitSubstitution(&sds, &sc, &ss);
'//
'//
'/////   ScriptApplyDigitSubstitution
'//
'//      Aplies the digit substitution settings recorded in a
'//      SCRIPT_DIGIT_SUBSTITUTE structure to the SCRIPT_CONTROL and
'//      SCRIPT_STATE structures.
'//
'//      The DigitSubstitute field of the SCRIPT_DIGITSUBSTITUTE structure
'//      is normally set by ScriptRecordDigitSubstitution, however it may
'//      be replaced by any one of the following values:
'//
'//

%SCRIPT_DIGITSUBSTITUTE_CONTEXT     = 0  ' // Substitute to match preceeding letters
%SCRIPT_DIGITSUBSTITUTE_NONE        = 1  ' // No substitution
%SCRIPT_DIGITSUBSTITUTE_NATIONAL    = 2  ' // Substitute with official national digits
%SCRIPT_DIGITSUBSTITUTE_TRADITIONAL = 3  ' // Substitute with traditional digits of the locale

'//
'//
'//p     SCRIPT_DIGITSUBSTITUTE_CONTEXT: Digits U+0030 - U+0039 will be
'//          substituted according to the language of prior letters. Before
'//          any letters, digits will be substituted according to the
'//          TraditionalDigitLangauge field of the SCRIPT_DIGIT_SUBSTITUTE
'//          structure. This field is normally set to the primary language of
'//          the Locale passed to ScriptRecordDigitSubstitution.
'//
'//p     SCRIPT_DIGITSUBSTITUTE_NONE: Digits will not be substituted. Unicode
'//          values U+0030 to U+0039 will be displayed with Arabic (i.e.
'//          Western) numerals.
'//
'//p     SCRIPT_DIGITSUBSTITUTE_NATIONAL: Digits U+0030 - U+0039 will be
'//          substituted according to the NationalDigitLangauge field of
'//          the SCRIPT_DIGIT_SUBSTITUTE structure. This field is normally
'//          set to the national digits returned for the NLS LCTYPE
'//          LOCALE_SNATIVEDIGITS by ScriptRecordDigitSubstitution.
'//
'//p     SCRIPT_DIGITSUBSTITUTE_TRADITIONAL: Digits U+0030 - U+0039 will be
'//          substituted according to the TraditionalDigitLangauge field of
'//          the SCRIPT_DIGIT_SUBSTITUTE structure. This field is normally
'//          set to the primary language of the Locale passed to
'//          ScriptRecordDigitSubstitution.

DECLARE FUNCTION ScriptApplyDigitSubstitution IMPORT "USP10.DLL" ALIAS "ScriptApplyDigitSubstitution" ( _
   BYREF psds AS SCRIPT_DIGITSUBSTITUTE _               ' __in  const SCRIPT_DIGITSUBSTITUTE  *psds // Digit substitution settings
 , BYREF psc AS SCRIPT_CONTROL _                        ' __out SCRIPT_CONTROL                *psc  // Script control structure
 , BYREF pss AS SCRIPT_STATE _                          ' __out SCRIPT_STATE                  *pss  // Script state structure
 ) AS LONG                                              ' HRESULT

'/////
'//p     psds: Pointer to SCRIPT_DIGITSUBSTITUTE structure recorded earlier.
'//          If NULL, ScriptApplyDigitSubstitution calls
'//          ScriptRecordDigitSubstitution with LOCALE_USER_DEFAULT.
'//
'//p     psc: SCRIPT_CONTROL structure. The fContextDigits and uDefaultLanguage
'//          fields will be updated.
'//
'//p     pss: SCRIPT_CONTROL structure. The fDigitSubstitute field will be
'//          updated.
'//
'//p     returns: E_INVALIDARG if the DigitSubstitute field of the
'//          SCRIPT_DIGITSUBSTITUTE structure is unrecognised, else S_OK;

'//******************************************************
'//
'//          OpenType enabled Uniscribe APIs
'//
'//******************************************************

'#ifndef UNISCRIBE_OPENTYPE
'#if (_WIN32_WINNT >= 0x0600)
'#define UNISCRIBE_OPENTYPE 0x0100
'#endif
'#endif

'#IF NOT %DEF(%UNISCRIBE_OPENTYPE)
'#IF %WINVER >= &H0600
'%UNISCRIBE_OPENTYPE = &H0100
'#ENDIF
'#ENDIF

'#IF %UNISCRIBE_OPENTYPE >= &H0100

'// 4-byte OpenType tag used to identify Script, LangSys or Feature
'typedef ULONG OPENTYPE_TAG;

'// Undefined script tag.
%SCRIPT_TAG_UNKNOWN   = &H00000000???

'// Single OpenType feature
' // Size = 8 bytes
TYPE OPENTYPE_FEATURE_RECORD DWORD
   tagFeature AS DWORD   ' OPENTYPE_TAG // Feature tag
   lParameter AS LONG    ' LONG // Feature parameter (0 - disabled)
END TYPE

'// Set of OpenType properties applied to the range of characters
' // Size = 8 bytes
TYPE TEXTRANGE_PROPERTIES DWORD
   potfRecords AS OPENTYPE_FEATURE_RECORD PTR   ' OPENTYPE_FEATURE_RECORD *
   cotfRecords AS LONG   ' int
END TYPE

'//
'// Character properties
'//
'// Used by shaping engines to pass shaping information between calls
'//
' // Size = 2 bytes
TYPE SCRIPT_CHARPROP WORD
   fCanGlyphAlone AS BIT * 1 IN WORD
   reserved       AS BIT * 15           ' // Reserved
END TYPE

'//
'// Glyph properties
'//
' // Size = 4 bytes
TYPE SCRIPT_GLYPHPROP WORD
   sva      AS SCRIPT_VISATTR
   reserved AS WORD              ' WORD // Reserved
END TYPE

'//
'// ScriptShapeOpenType
'//
'// New parameters comparing to ScriptShape:
'//
'// tagScript            - script tag to be used by OpenType layout
'// tagLangSys           - language system tag to be used by OpenType layout
'// rcRangeChars         - Number of characters in each range
'//                                          (total should be equal to cChars)
'//
'// rpRangeProperties     - Range properties for each range
'//
'// cRanges              - Number of ranges
'//
'//
'// New output parameters:
'//
'// pCharProps           - array of character properties, generated by Uniscribe
'//
'// pGlyphProps          - array of glyph properties, replaces visual attributes (4 bytes now)
'// pfCanGlyphAlone      - flag per character, indicate that char can be shaped independently
'//

DECLARE FUNCTION ScriptShapeOpenType IMPORT "USP10.DLL" ALIAS "ScriptShapeOpenType" ( _
   BYVAL hdc AS DWORD _                                 ' __in_opt HDC                    hdc               // Optional (see under caching)
 , BYREF psc AS DWORD _                                 ' __in_out SCRIPT_CACHE          *psc               // Cache handle
 , BYREF psa AS SCRIPT_ANALYSIS _                       ' __in_out SCRIPT_ANALYSIS       *psa               // Result of ScriptItemize (may have fNoGlyphIndex set)
 , BYVAL tagScript AS DWORD _                           ' __in     OPENTYPE_TAG           tagScript         // Font script tag for shaping
 , BYVAL tagLangSys AS DWORD _                          ' __in     OPENTYPE_TAG           tagLangSys        // Font language system tag for shaping
 , BYREF rcRangeChars AS LONG _                         ' __in     int                   *rcRangeChars      // Array of number of characters per range
 , BYREF rpRangeProperties AS TEXTRANGE_PROPERTIES _    ' __in     TEXTRANGE_PROPERTIES **rpRangeProperties // Array of range properties (for each range)
 , BYVAL cRanges AS LONG _                              ' __in     int                    cRanges           // Number of ranges
 , BYREF pwcChars AS WORD _                             ' __in     const WCHAR           *pwcChars          // Logical unicode run
 , BYVAL cChars AS LONG _                               ' __in     int                    cChars            // Length of unicode run
 , BYVAL cMaxGlyphs AS LONG _                           ' __in     int                    cMaxGlyphs        // Max glyphs to generate
 , BYREF pwLogClust AS WORD _                           ' __out    WORD                  *pwLogClust        // Logical clusters
 , BYREF pCharProps AS SCRIPT_CHARPROP _                ' __out    SCRIPT_CHARPROP       *pCharProps        // Output buffer for character properties
 , BYREF pwOutGlyphs AS WORD _                          ' __out    WORD                  *pwOutGlyphs       // Output glyph buffer
 , BYREF pOutGlyphProps AS SCRIPT_GLYPHPROP _           ' __out    SCRIPT_GLYPHPROP      *pOutGlyphProps    // Visual glyph attributes
 , BYREF pcGlyphs AS LONG _                             ' __out    int                   *pcGlyphs          // Count of glyphs generated
 ) AS LONG                                              ' HRESULT

'//
'// ScriptPlaceOpenType
'//
'// New parameters comparing to ScriptPlace:
'//
'// tagScript            - script tag to be used by OpenType layout
'// tagLangSys           - language system tag to be used by OpenType layout
'// rcRangeChars         - Number of characters in each range
'//                                          (total should be equal to cChars)
'//
'// rpRangeProperties    - Range properties for each range
'//
'// cRanges              - Number of ranges
'//
'//
'// New output parameters:
'//
'// Character information - pwcChars, pwLogClust, pCharProps are now passed to ScriptPlace
'// pGlyphProps           - array of glyph properties, replaces visual attributes (4 bytes now)
'//

DECLARE FUNCTION ScriptPlaceOpenType IMPORT "USP10.DLL" ALIAS "ScriptPlaceOpenType" ( _
   BYVAL hdc AS DWORD _                                 ' __in_opt  HDC                     hdc               // Optional (see under caching)
 , BYREF psc AS DWORD _                                 ' __in_out  SCRIPT_CACHE           *psc               // Cache handle
 , BYREF psa AS SCRIPT_ANALYSIS _                       ' __in_out  SCRIPT_ANALYSIS        *psa               // Result of ScriptItemize (may have fNoGlyphIndex set)
 , BYVAL tagScript AS DWORD _                           ' __in      OPENTYPE_TAG            tagScript         // Font script tag for shaping
 , BYVAL tagLangSys AS DWORD _                          ' __in      OPENTYPE_TAG            tagLangSys        // Font language system tag for shaping
 , BYREF rcRangeChars AS LONG _                         ' __in      int                    *rcRangeChars      // Array of number of characters per range
 , BYREF rpRangeProperties AS TEXTRANGE_PROPERTIES _    ' __in      TEXTRANGE_PROPERTIES  **rpRangeProperties // Array of range properties (for each range)
 , BYVAL cRanges AS LONG _                              ' __in      int                     cRanges           // Number of ranges
 , BYREF pwcChars AS WORD _                             ' __in      const WCHAR            *pwcChars          // Logical unicode run
 , BYREF pwLogClust AS WORD _                           ' __in      WORD                   *pwLogClust        // Logical clusters
 , BYREF pCharProps AS SCRIPT_CHARPROP _                ' __in      SCRIPT_CHARPROP        *pCharProps        // Output buffer for character properties
 , BYVAL cChars AS LONG _                               ' __in      int                     cChars            // Length of unicode run
 , BYREF pwGlyphs AS WORD _                             ' __in      const WORD             *pwGlyphs          // Glyph buffer from prior ScriptShape call
 , BYREF pGlyphProps AS SCRIPT_GLYPHPROP _              ' __in      const SCRIPT_GLYPHPROP *pGlyphProps       // Glyph properties
 , BYVAL cGlyphs AS DWORD _                             ' __in      int                     cGlyphs           // Number of glyphs
 , BYREF piAdvance AS LONG _                            ' __out     int                    *piAdvance         // Advance widths
 , BYREF pGoffset AS GOFFSET _                          ' __out     GOFFSET                *pGoffset          // x,y offset for combining glyph
 , BYREF pABC AS ABC _                                  ' __out_opt ABC                    *pABC              // Composite ABC for the whole run (Optional)
 ) AS LONG                                              ' HRESULT

'//
'// ScriptItemizeOpenType
'//
'// New parameter comapring to ScriptItemize:
'//
'// pScriptTags -- array parallel to items, contains script tags
'//                                              to be passed to ScriptShapeOpenType.
'//

DECLARE FUNCTION ScriptItemizeOpenType IMPORT "USP10.DLL" ALIAS "ScriptItemizeOpenType" ( _
   BYREF pwcInChars AS WORD _                           ' __in     const WCHAR          *pwcInChars  // Unicode string to be itemized
 , BYVAL cInChars AS LONG _                             ' __in     int                   cInChars    // Codepoint count to itemize
 , BYVAL cMaxItems AS LONG _                            ' __in     int                   cMaxItems   // Max length of itemization array
 , BYREF psControl AS SCRIPT_CONTROL _                  ' __in_opt const SCRIPT_CONTROL *psControl   // Analysis control (optional)
 , BYREF psState AS SCRIPT_STATE _                      ' __in_opt const SCRIPT_STATE   *psState     // Initial bidi algorithm state (optional)
 , BYREF pItems AS SCRIPT_ITEM _                        ' __out    SCRIPT_ITEM          *pItems      // Array to receive itemization
 , BYREF pScriptTags AS DWORD _                         ' __out    OPENTYPE_TAG         *pScriptTags // Array of script tags - parallel to items
 , BYREF pcItems AS LONG _                              ' __out    int                  *pcItems     // Count of items processed (optional)
 ) AS LONG                                              ' HRESULT

'// ScriptGetFontScriptList
'//
'// Returns list of script tags supported by layout tables.
'// Only scripts that can be shaped by eScript will be returned ( or full list if psa==NULL).
'// Usually complex scripts return single tag and neutral (like digits) return all tags from the font
'//
'// Note: If tag coresponding to some script is present it does not guarantee
'//       that font won't be rejected by particular shaping engine because
'//       shaping engine may require particular language system or feature
'//       to be present.
'//

DECLARE FUNCTION ScriptGetFontScriptTags IMPORT "USP10.DLL" ALIAS "ScriptGetFontScriptTags" ( _
   BYVAL hdc AS DWORD _                                 ' __in_opt HDC              hdc         // Optional (see under caching)
 , BYREF psc AS DWORD _                                 ' __in_out SCRIPT_CACHE    *psc         // Cache handle
 , BYREF psa AS SCRIPT_ANALYSIS _                       ' __in_opt SCRIPT_ANALYSIS *psa         // Result of ScriptItemize (can be NULL)
 , BYVAL cMaxTags AS LONG _                             ' __in     int              cMaxTags    // Length of pScriptTags array
 , BYREF pScriptTags AS DWORD _                         ' __out    OPENTYPE_TAG    *pScriptTags // list of script tags in the font
 , BYREF pcTags AS LONG _                               ' __out    int             *pcTags      // Number of tags returned
 ) AS LONG                                              ' HRESULT

'//
'// ScriptGetFontLanguageTags
'//
'// Returns list of language system tags supported by layout tables for particular script.
'//

DECLARE FUNCTION ScriptGetFontLanguageTags IMPORT "USP10.DLL" ALIAS "ScriptGetFontLanguageTags" ( _
   BYVAL hdc AS DWORD _                                 ' __in_opt HDC              hdc          // Optional (see under caching)
 , BYREF psc AS DWORD _                                 ' __in_out SCRIPT_CACHE    *psc          // Cache handle
 , BYREF psa AS SCRIPT_ANALYSIS _                       ' __in_opt SCRIPT_ANALYSIS *psa          // Result of ScriptItemize  (can be NULL)
 , BYVAL tagScript AS DWORD _                           ' __in     OPENTYPE_TAG     tagScript    // Font script tag
 , BYVAL cMaxTags AS LONG _                             ' __in     int              cMaxTags     // Length of pLangsys tags array
 , BYREF pLangsysTags AS DWORD _                        ' __out    OPENTYPE_TAG    *pLangsysTags // list of Langsys tags in the font
 , BYREF pcTags AS LONG _                               ' __out    int             *pcTags       // Number of tags returned
 ) AS LONG                                              ' HRESULT

'//
'// ScriptGetFontFeatureTags
'//
'// Returns list of feature tags supported by layout tables for particular language system.
'//
'// This method will hide features that are language specific, because they are
'// controlled by shaping engines and can not be switched on or off by the client.
'// Example of such features are initial, medial and final forms for Arabic script
'//
'// If psa==NULL function returns unfiltered feature list
'//

DECLARE FUNCTION ScriptGetFontFeatureTags IMPORT "USP10.DLL" ALIAS "ScriptGetFontFeatureTags" ( _
   BYVAL hdc AS DWORD _                                 ' __in_opt HDC              hdc          // Optional (see under caching)
 , BYREF psc AS DWORD _                                 ' __in_out SCRIPT_CACHE    *psc          // Cache handle
 , BYREF psa AS SCRIPT_ANALYSIS _                       ' __in_opt SCRIPT_ANALYSIS *psa          // Result of ScriptItemize  (can be NULL)
 , BYVAL tagScript AS DWORD _                           ' __in     OPENTYPE_TAG     tagScript    // Font script tag
 , BYVAL tagLangSys AS DWORD _                          ' __in     OPENTYPE_TAG     tagLangSys   // Font language system tag for shaping
 , BYVAL cMaxTags AS LONG _                             ' __in     int              cMaxTags     // Length of pLangsys tags array
 , BYREF pFeatureTags AS DWORD _                        ' __out    OPENTYPE_TAG    *pFeatureTags // list of feature tags in the font
 , BYREF pcTags AS LONG _                               ' __out    int             *pcTags       // Number of tags returned
 ) AS LONG                                              ' HRESULT

'//
'//  ScriptGetFontAlternateGlyphs
'//
'//  Returns list alternates for particular glyph.
'//
'//  Original glyph is always added as a first element. Index in this array
'//  is exactly the feature parameter that should be passed to ScriptShape.
'//
'//  To get variants it is a good idea to reshape input without feature
'//  applied to current glyph so it will be always alternates for default
'//  glyph for this position. Original glyph could have variants, while
'//  variants may not. So UI will stick with this final form wihtout ability
'//  to choose another one.
'//
'//  Note: It theoretically can be emulated by ScriptSubstituteSingleGlyph.
'//        Just try parameters one by one while glyphs are substituted.
'//

DECLARE FUNCTION ScriptGetFontAlternateGlyphs IMPORT "USP10.DLL" ALIAS "ScriptGetFontAlternateGlyphs" ( _
   BYVAL hdc AS DWORD _                                 ' __in_opt HDC              hdc               // Optional (see under caching)
 , BYREF psc AS DWORD _                                 ' __in_out SCRIPT_CACHE    *psc               // Cache handle
 , BYREF psa AS SCRIPT_ANALYSIS _                       ' __in_opt SCRIPT_ANALYSIS *psa               // Result of ScriptItemize  (can be NULL)
 , BYVAL tagScript AS DWORD _                           ' __in     OPENTYPE_TAG     tagScript         // Font script tag
 , BYVAL tagLangSys AS DWORD _                          ' __in     OPENTYPE_TAG     tagLangSys        // Font language system tag for shaping
 , BYVAL tagFeature AS DWORD _                          ' __in     OPENTYPE_TAG     tagFeature        // Feature tag to test for alternates
 , BYVAL wGlyphId AS WORD _                             ' __in     WORD             wGlyphId          // Original glyph
 , BYVAL cMaxAlternates AS LONG _                       ' __in     int              cMaxAlternates    // Length of pAlternateGlyphs tags array
 , BYREF pAlternateGlyphs AS WORD _                     ' __out    WORD            *pAlternateGlyphs  // list of feature tags in the font
 , BYREF pcAlternates AS LONG _                         ' __out    int             *pcAlternates      // Number of alternates returned
 ) AS LONG                                              ' HRESULT

'//
'//  ScriptSubstituteSingleGlyph
'//
'//  Apply partcular feature to single glyph, assuming that
'//  expected result is one-to-one substitution
'//

DECLARE FUNCTION ScriptSubstituteSingleGlyph IMPORT "USP10.DLL" ALIAS "ScriptSubstituteSingleGlyph" ( _
   BYVAL hdc AS DWORD _                                 ' __in_opt HDC              hdc          // Optional (see under caching)
 , BYREF psc AS DWORD _                                 ' __in_out SCRIPT_CACHE    *psc          // Cache handle
 , BYREF psa AS SCRIPT_ANALYSIS _                       ' __in_opt SCRIPT_ANALYSIS *psa          // Result of ScriptItemize  (can be NULL)
 , BYVAL tagScript AS DWORD _                           ' __in     OPENTYPE_TAG     tagScript    // Font script tag
 , BYVAL tagLangSys AS DWORD _                          ' __in     OPENTYPE_TAG     tagLangSys   // Font language system tag for shaping
 , BYVAL tagFeature AS DWORD _                          ' __in     OPENTYPE_TAG     tagFeature   // Feature tag to test for alternates
 , BYVAL lParameter AS LONG _                           ' __in     LONG             lParameter   // Feature parameter
 , BYVAL wGlyphId AS WORD _                             ' __in     WORD             wGlyphId     // Original glyph id
 , BYREF pwOutGlyphId AS WORD _                         ' __out    WORD            *pwOutGlyphId // Substituted glyph id
 ) AS LONG                                              ' HRESULT

'//
'//  ScriptPositionSingleGlyph
'//
'//  Apply particular feature to single glyph, assuming that
'//  expected result is single position adjustment.
'//

DECLARE FUNCTION ScriptPositionSingleGlyph IMPORT "USP10.DLL" ALIAS "ScriptPositionSingleGlyph" ( _
   BYVAL hdc AS DWORD _                                 ' __in_opt HDC              hdc          // Optional (see under caching)
 , BYREF psc AS DWORD _                                 ' __in_out SCRIPT_CACHE    *psc          // Cache handle
 , BYREF psa AS SCRIPT_ANALYSIS _                       ' __in_opt SCRIPT_ANALYSIS *psa          // Result of ScriptItemize  (can be NULL)
 , BYVAL tagScript AS DWORD _                           ' __in     OPENTYPE_TAG     tagScript    // Font script tag
 , BYVAL tagLangSys AS DWORD _                          ' __in     OPENTYPE_TAG     tagLangSys   // Font language system tag for shaping
 , BYVAL tagFeature AS DWORD _                          ' __in     OPENTYPE_TAG     tagFeature   // Feature tag to test for alternates
 , BYVAL lParameter AS LONG _                           ' __in     LONG             lParameter   // Feature parameter
 , BYVAL wGlyphId AS WORD _                             ' __in     WORD             wGlyphId     // Glyph id to be moved
 , BYVAL iAdvance AS LONG _                             ' __in     int              iAdvance     // Original glyph advance width
 , BYVAL GOffset AS GOFFSET _                           ' __in     GOFFSET          GOffset      // Original glyph offset
 , BYREF piOutAdvance AS LONG _                         ' __out    int             *piOutAdvance // Adjusted advance width
 , BYREF pOutGoffset AS GOFFSET _                       ' __out    GOFFSET         *pOutGoffset  // Adjusted offset
 ) AS LONG                                              ' HRESULT

'#ENDIF ' // (UNISCRIBE_OPENTYPE >= 0x0100)
