' ########################################################################################
' Microsoft Windows
' File: WinNls.inc
' Contents: Procedure declarations, constant definitions, and macros for the NLS component.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINNLS_INC = 1

#INCLUDE ONCE "windows.inc"

#IF NOT %DEF(%NONLS)

'////////////////////////////////////////////////////////////////////////////
'//
'//  Constants
'//
'//  Define all constants for the NLS component here.
'//
'////////////////////////////////////////////////////////////////////////////

'//
'//  String Length Maximums.
'//
%MAX_LEADBYTES   = 12   ' 5 ranges, 2 bytes ea., 0 term.
%MAX_DEFAULTCHAR = 2    ' single or double byte

'//
'//  Surrogate pairs
'//
'//  Conversion examples:
'//
'//  A) The first character in the Surrogate range (D800, DC00) as UTF-32:
'//
'//  1.  D800: binary 1101100000000000  (lower ten bits: 0000000000)
'//  2.  DC00: binary 1101110000000000  (lower ten bits: 0000000000)
'//  3.  Concatenate 0000000000+0000000000 = 0x0000
'//  4.  Add 0x10000
'//
'//  Result: U+10000. This is correct, since the first character in the Supplementary character
'//  range immediately follows the last code point in the 16-bit UTF-16 range (U+FFFF)
'//
'//  B) A UTF-32 code point such as U+2040A (this a CJK character in CJK Extension B), and wish
'//  to convert it in UTF-16:
'//
'//  1.  Subtract 0x10000 - Result: 0x1040A
'//  2.  Split into two ten-bit pieces: 0001000001 0000001010
'//  3.  Add 1101100000000000 (0xD800) to the high 10 bits piece (0001000001) - Result: 1101100001000001 (0xD841)
'//  4.  Add 1101110000000000 (0xDC00) to the low 10 bits piece (0000001010) - Result: 1101110000001010 (0xDC0A)
'//
'//  RESULT: The surrogate pair: U+D841, U+DC0A
'//
'//  Special Unicode code point values, for use with UTF-16 surrogate pairs.
'//
%HIGH_SURROGATE_START  = &Hd800??
%HIGH_SURROGATE_END    = &Hdbff??
%LOW_SURROGATE_START   = &Hdc00??
%LOW_SURROGATE_END     = &Hdfff??

'//
'//  MBCS and Unicode Translation Flags.
'//
%MB_PRECOMPOSED       = &H00000001???  ' // use precomposed chars
%MB_COMPOSITE         = &H00000002???  ' // use composite chars
%MB_USEGLYPHCHARS     = &H00000004???  ' // use glyph chars, not ctrl chars
%MB_ERR_INVALID_CHARS = &H00000008???  ' // error for invalid chars

%WC_COMPOSITECHECK    = &H00000200???  ' // convert composite to precomposed
%WC_DISCARDNS         = &H00000010???  ' // discard non-spacing chars
%WC_SEPCHARS          = &H00000020???  ' // generate separate chars
%WC_DEFAULTCHAR       = &H00000040???  ' // replace w/ default char
'#if (WINVER >= 0x0600)
%WC_ERR_INVALID_CHARS = &H00000080???  ' // error for invalid chars
'#endif

'#if(WINVER >= 0x0500)
%WC_NO_BEST_FIT_CHARS      = &H00000400???   ' // do not use best fit chars
'#endif /* WINVER >= 0x0500 */


'//
'//  Character Type Flags.
'//
%CT_CTYPE1 = &H00000001???   ' // ctype 1 information
%CT_CTYPE2 = &H00000002???   ' // ctype 2 information
%CT_CTYPE3 = &H00000004???   ' // ctype 3 information

'//
'//  CType 1 Flag Bits.
'//
%C1_UPPER   = &H0001???  ' // upper case
%C1_LOWER   = &H0002???  ' // lower case
%C1_DIGIT   = &H0004???  ' // decimal digits
%C1_SPACE   = &H0008???  ' // spacing characters
%C1_PUNCT   = &H0010???  ' // punctuation characters
%C1_CNTRL   = &H0020???  ' // control characters
%C1_BLANK   = &H0040???  ' // blank characters
%C1_XDIGIT  = &H0080???  ' // other digits
%C1_ALPHA   = &H0100???  ' // any linguistic character
%C1_DEFINED = &H0200???  ' // defined character

'//
'//  CType 2 Flag Bits.
'//
%C2_LEFTTORIGHT      = &H0001???     ' // left to right
%C2_RIGHTTOLEFT      = &H0002???     ' // right to left

%C2_EUROPENUMBER     = &H0003???     ' // European number, digit
%C2_EUROPESEPARATOR  = &H0004???     ' // European numeric separator
%C2_EUROPETERMINATOR = &H0005???     ' // European numeric terminator
%C2_ARABICNUMBER     = &H0006???     ' // Arabic number
%C2_COMMONSEPARATOR  = &H0007???     ' // common numeric separator

%C2_BLOCKSEPARATOR   = &H0008???     ' // block separator
%C2_SEGMENTSEPARATOR = &H0009???     ' // segment separator
%C2_WHITESPACE       = &H000A???     ' // white space
%C2_OTHERNEUTRAL     = &H000B???     ' // other neutrals

%C2_NOTAPPLICABLE    = &H0000???     ' // no implicit directionality

'//
'//  CType 3 Flag Bits.
'//
%C3_NONSPACING    = &H0001???  ' // nonspacing character
%C3_DIACRITIC     = &H0002???  ' // diacritic mark
%C3_VOWELMARK     = &H0004???  ' // vowel mark
%C3_SYMBOL        = &H0008???  ' // symbols

%C3_KATAKANA      = &H0010???  ' // katakana character
%C3_HIRAGANA      = &H0020???  ' // hiragana character
%C3_HALFWIDTH     = &H0040???  ' // half width character
%C3_FULLWIDTH     = &H0080???  ' // full width character
%C3_IDEOGRAPH     = &H0100???  ' // ideographic character
%C3_KASHIDA       = &H0200???  ' // Arabic kashida character
%C3_LEXICAL       = &H0400???  ' // lexical character
%C3_HIGHSURROGATE = &H0800???  ' // high surrogate code unit
%C3_LOWSURROGATE  = &H1000???  ' // low surrogate code unit

%C3_ALPHA         = &H8000???  ' // any linguistic char (C1_ALPHA)

%C3_NOTAPPLICABLE = &H0000???  ' // ctype 3 is not applicable

'//
'//  String Flags.
'//
%NORM_IGNORECASE            = &H00000001???   ' // ignore case
%NORM_IGNORENONSPACE        = &H00000002???   ' // ignore nonspacing chars
%NORM_IGNORESYMBOLS         = &H00000004???   ' // ignore symbols

%LINGUISTIC_IGNORECASE      = &H00000010???   ' // // linguistically appropriate ' //ignore case' //
%LINGUISTIC_IGNOREDIACRITIC = &H00000020???   ' // // linguistically appropriate ' //ignore nonspace' //

%NORM_IGNOREKANATYPE        = &H00010000???   ' // ignore kanatype
%NORM_IGNOREWIDTH           = &H00020000???   ' // ignore width
%NORM_LINGUISTIC_CASING     = &H08000000???   ' // // use linguistic rules for casing

'//
'//  Locale Independent Mapping Flags.
'//
%MAP_FOLDCZONE        = &H00000010???  ' // fold compatibility zone chars
%MAP_PRECOMPOSED      = &H00000020???  ' // convert to precomposed chars
%MAP_COMPOSITE        = &H00000040???  ' // convert to composite chars
%MAP_FOLDDIGITS       = &H00000080???  ' // all digits to ASCII 0-9

'#if(WINVER >= 0x0500)
%MAP_EXPAND_LIGATURES = &H00002000???  ' // expand all ligatures
'#endif /* WINVER >= 0x0500 */

'//
'//  Locale Dependent Mapping Flags.
'//
%LCMAP_LOWERCASE           = &H00000100???  ' // lower case letters
%LCMAP_UPPERCASE           = &H00000200???  ' // upper case letters
'#if (WINVER >= _WIN32_WINNT_WIN7)
%LCMAP_TITLECASE           = &H00000300???  ' // Title Case Letters
'#endif // (WINVER >= _WIN32_WINNT_WIN7)

%LCMAP_SORTKEY             = &H00000400???  ' // WC sort key (normalize)
%LCMAP_BYTEREV             = &H00000800???  ' // byte reversal

%LCMAP_HIRAGANA            = &H00100000???  ' // map katakana to hiragana
%LCMAP_KATAKANA            = &H00200000???  ' // map hiragana to katakana
%LCMAP_HALFWIDTH           = &H00400000???  ' // map double byte to single byte
%LCMAP_FULLWIDTH           = &H00800000???  ' // map single byte to double byte

%LCMAP_LINGUISTIC_CASING   = &H01000000???  ' // use linguistic rules for casing

%LCMAP_SIMPLIFIED_CHINESE  = &H02000000???  ' // map traditional chinese to simplified chinese
%LCMAP_TRADITIONAL_CHINESE = &H04000000???  ' // map simplified chinese to traditional chinese

'//
'//  Search Flags
'//
%FIND_STARTSWITH           = &H00100000???  ' // // see if value is at the beginning of source
%FIND_ENDSWITH             = &H00200000???  ' // // see if value is at the end of source
%FIND_FROMSTART            = &H00400000???  ' // // look for value in source, starting at the beginning
%FIND_FROMEND              = &H00800000???  ' // // look for value in source, starting at the end

'//
'//  Language Group Enumeration Flags.
'//
%LGRPID_INSTALLED          = &H00000001???  ' // installed language group ids
%LGRPID_SUPPORTED          = &H00000002???  ' // supported language group ids

'//
'//  Locale Enumeration Flags.
'//
%LCID_INSTALLED            = &H00000001???  ' // installed locale ids
%LCID_SUPPORTED            = &H00000002???  ' // supported locale ids
%LCID_ALTERNATE_SORTS      = &H00000004???  ' // alternate sort locale ids

'#if (WINVER >= _WIN32_WINNT_VISTA)
'//
'//  Named based enumeration flags.
'//
%LOCALE_ALL                = 0???            ' // // enumerate all named based locales
%LOCALE_WINDOWS            = &H00000001???   ' // // shipped locales and/or replacements for them
%LOCALE_SUPPLEMENTAL       = &H00000002???   ' // // supplemental locales only
%LOCALE_ALTERNATE_SORTS    = &H00000004???   ' // // alternate sort locales
%LOCALE_REPLACEMENT        = &H00000008???   ' // // replacement locales only (supplemental - custom)
'#endif // (WINVER >= _WIN32_WINNT_VISTA)
'#if (WINVER >= _WIN32_WINNT_WIN7)
%LOCALE_NEUTRALDATA        = &H00000010???   ' // Locales that are "neutral" (language only, region data is default)
%LOCALE_SPECIFICDATA       = &H00000020???   ' // Locales that contain language and region data
'#endif // (WINVER >= _WIN32_WINNT_WIN7)

'//
'//  Code Page Enumeration Flags.
'//
%CP_INSTALLED         = &H00000001???  ' // installed code page ids
%CP_SUPPORTED         = &H00000002???  ' // supported code page ids

'//
'//  Sorting Flags.
'//
'//    WORD Sort:    culturally correct sort
'//                  hyphen and apostrophe are special cased
'//                  example: "coop" and "co-op" will sort together in a list
'//
'//                        co_op     <-------  underscore (symbol)
'//                        coat
'//                        comb
'//                        coop
'//                        co-op     <-------  hyphen (punctuation)
'//                        cork
'//                        went
'//                        were
'//                        we're     <-------  apostrophe (punctuation)
'//
'//
'//    STRING Sort:  hyphen and apostrophe will sort with all other symbols
'//
'//                        co-op     <-------  hyphen (punctuation)
'//                        co_op     <-------  underscore (symbol)
'//                        coat
'//                        comb
'//                        coop
'//                        cork
'//                        we're     <-------  apostrophe (punctuation)
'//                        went
'//                        were
'//
%SORT_STRINGSORT = &H00001000   ' // use string sort method

'//  Sort digits as numbers (ie: 2 comes before 10)
'#if (WINVER >= _WIN32_WINNT_WIN7)
%SORT_DIGITSASNUMBERS      = &H00000008???   ' // use digits as numbers sort method
'#endif // (WINVER >= _WIN32_WINNT_WIN7)

'//
'//  Compare String Return Values.
'//
%CSTR_LESS_THAN    = 1           ' // string 1 less than string 2
%CSTR_EQUAL        = 2           ' // string 1 equal to string 2
%CSTR_GREATER_THAN = 3           ' // string 1 greater than string 2

'//
'//  Code Page Default Values.
'//
%CP_ACP        = 0       ' // default to ANSI code page
%CP_OEMCP      = 1       ' // default to OEM  code page
%CP_MACCP      = 2       ' // default to MAC  code page
%CP_THREAD_ACP = 3       ' // current thread' //s ANSI code page
%CP_SYMBOL     = 42      ' // SYMBOL translations

%CP_UTF7       = 65000   ' // UTF-7 translation
%CP_UTF8       = 65001   ' // UTF-8 translation

'//
'//  Country/Region Codes.
'//
%CTRY_DEFAULT            = 0

%CTRY_ALBANIA            = 355   ' // Albania
%CTRY_ALGERIA            = 213   ' // Algeria
%CTRY_ARGENTINA          = 54    ' // Argentina
%CTRY_ARMENIA            = 374   ' // Armenia
%CTRY_AUSTRALIA          = 61    ' // Australia
%CTRY_AUSTRIA            = 43    ' // Austria
%CTRY_AZERBAIJAN         = 994   ' // Azerbaijan
%CTRY_BAHRAIN            = 973   ' // Bahrain
%CTRY_BELARUS            = 375   ' // Belarus
%CTRY_BELGIUM            = 32    ' // Belgium
%CTRY_BELIZE             = 501   ' // Belize
%CTRY_BOLIVIA            = 591   ' // Bolivia
%CTRY_BRAZIL             = 55    ' // Brazil
%CTRY_BRUNEI_DARUSSALAM  = 673   ' // Brunei Darussalam
%CTRY_BULGARIA           = 359   ' // Bulgaria
%CTRY_CANADA             = 2     ' // Canada
%CTRY_CARIBBEAN          = 1     ' // Caribbean
%CTRY_CHILE              = 56    ' // Chile
%CTRY_COLOMBIA           = 57    ' // Colombia
%CTRY_COSTA_RICA         = 506   ' // Costa Rica
%CTRY_CROATIA            = 385   ' // Croatia
%CTRY_CZECH              = 420   ' // Czech Republic
%CTRY_DENMARK            = 45    ' // Denmark
%CTRY_DOMINICAN_REPUBLIC = 1     ' // Dominican Republic
%CTRY_ECUADOR            = 593   ' // Ecuador
%CTRY_EGYPT              = 20    ' // Egypt
%CTRY_EL_SALVADOR        = 503   ' // El Salvador
%CTRY_ESTONIA            = 372   ' // Estonia
%CTRY_FAEROE_ISLANDS     = 298   ' // Faeroe Islands
%CTRY_FINLAND            = 358   ' // Finland
%CTRY_FRANCE             = 33    ' // France
%CTRY_GEORGIA            = 995   ' // Georgia
%CTRY_GERMANY            = 49    ' // Germany
%CTRY_GREECE             = 30    ' // Greece
%CTRY_GUATEMALA          = 502   ' // Guatemala
%CTRY_HONDURAS           = 504   ' // Honduras
%CTRY_HONG_KONG          = 852   ' // Hong Kong S.A.R., P.R.C.
%CTRY_HUNGARY            = 36    ' // Hungary
%CTRY_ICELAND            = 354   ' // Iceland
%CTRY_INDIA              = 91    ' // India
%CTRY_INDONESIA          = 62    ' // Indonesia
%CTRY_IRAN               = 981   ' // Iran
%CTRY_IRAQ               = 964   ' // Iraq
%CTRY_IRELAND            = 353   ' // Ireland
%CTRY_ISRAEL             = 972   ' // Israel
%CTRY_ITALY              = 39    ' // Italy
%CTRY_JAMAICA            = 1     ' // Jamaica
%CTRY_JAPAN              = 81    ' // Japan
%CTRY_JORDAN             = 962   ' // Jordan
%CTRY_KAZAKSTAN          = 7     ' // Kazakstan
%CTRY_KENYA              = 254   ' // Kenya
%CTRY_KUWAIT             = 965   ' // Kuwait
%CTRY_KYRGYZSTAN         = 996   ' // Kyrgyzstan
%CTRY_LATVIA             = 371   ' // Latvia
%CTRY_LEBANON            = 961   ' // Lebanon
%CTRY_LIBYA              = 218   ' // Libya
%CTRY_LIECHTENSTEIN      = 41    ' // Liechtenstein
%CTRY_LITHUANIA          = 370   ' // Lithuania
%CTRY_LUXEMBOURG         = 352   ' // Luxembourg
%CTRY_MACAU              = 853   ' // Macau S.A.R., PRC
%CTRY_MACEDONIA          = 389   ' // Former Yugoslav Republic of Macedonia
%CTRY_MALAYSIA           = 60    ' // Malaysia
%CTRY_MALDIVES           = 960   ' // Maldives
%CTRY_MEXICO             = 52    ' // Mexico
%CTRY_MONACO             = 33    ' // Principality of Monaco
%CTRY_MONGOLIA           = 976   ' // Mongolia
%CTRY_MOROCCO            = 212   ' // Morocco
%CTRY_NETHERLANDS        = 31    ' // Netherlands
%CTRY_NEW_ZEALAND        = 64    ' // New Zealand
%CTRY_NICARAGUA          = 505   ' // Nicaragua
%CTRY_NORWAY             = 47    ' // Norway
%CTRY_OMAN               = 968   ' // Oman
%CTRY_PAKISTAN           = 92    ' // Islamic Republic of Pakistan
%CTRY_PANAMA             = 507   ' // Panama
%CTRY_PARAGUAY           = 595   ' // Paraguay
%CTRY_PERU               = 51    ' // Peru
%CTRY_PHILIPPINES        = 63    ' // Republic of the Philippines
%CTRY_POLAND             = 48    ' // Poland
%CTRY_PORTUGAL           = 351   ' // Portugal
%CTRY_PRCHINA            = 86    ' // People' //s Republic of China
%CTRY_PUERTO_RICO        = 1     ' // Puerto Rico
%CTRY_QATAR              = 974   ' // Qatar
%CTRY_ROMANIA            = 40    ' // Romania
%CTRY_RUSSIA             = 7     ' // Russia
%CTRY_SAUDI_ARABIA       = 966   ' // Saudi Arabia
%CTRY_SERBIA             = 381   ' // Serbia
%CTRY_SINGAPORE          = 65    ' // Singapore
%CTRY_SLOVAK             = 421   ' // Slovak Republic
%CTRY_SLOVENIA           = 386   ' // Slovenia
%CTRY_SOUTH_AFRICA       = 27    ' // South Africa
%CTRY_SOUTH_KOREA        = 82    ' // Korea
%CTRY_SPAIN              = 34    ' // Spain
%CTRY_SWEDEN             = 46    ' // Sweden
%CTRY_SWITZERLAND        = 41    ' // Switzerland
%CTRY_SYRIA              = 963   ' // Syria
%CTRY_TAIWAN             = 886   ' // Taiwan
%CTRY_TATARSTAN          = 7     ' // Tatarstan
%CTRY_THAILAND           = 66    ' // Thailand
%CTRY_TRINIDAD_Y_TOBAGO  = 1     ' // Trinidad y Tobago
%CTRY_TUNISIA            = 216   ' // Tunisia
%CTRY_TURKEY             = 90    ' // Turkey
%CTRY_UAE                = 971   ' // U.A.E.
%CTRY_UKRAINE            = 380   ' // Ukraine
%CTRY_UNITED_KINGDOM     = 44    ' // United Kingdom
%CTRY_UNITED_STATES      = 1     ' // United States
%CTRY_URUGUAY            = 598   ' // Uruguay
%CTRY_UZBEKISTAN         = 7     ' // Uzbekistan
%CTRY_VENEZUELA          = 58    ' // Venezuela
%CTRY_VIET_NAM           = 84    ' // Viet Nam
%CTRY_YEMEN              = 967   ' // Yemen
%CTRY_ZIMBABWE           = 263   ' // Zimbabwe

'//
'//  Locale Types.
'//
'//  These types are used for the GetLocaleInfo NLS API routine.
'//  Some of these types are also used for the SetLocaleInfo NLS API routine.
'//

'//
'//  The following LCTypes may be used in combination with any other LCTypes.
'//
'//    LOCALE_NOUSEROVERRIDE is also used in GetTimeFormat and
'//    GetDateFormat.
'//
'//    LOCALE_USE_CP_ACP is used in many of the A (Ansi) apis that need
'//    to do string translation.
'//
'//    LOCALE_RETURN_NUMBER will return the result from GetLocaleInfo as a
'//    number instead of a string.  This flag is only valid for the LCTypes
'//    beginning with LOCALE_I.
'//
%LOCALE_NOUSEROVERRIDE   = &H80000000???   ' // do not use user overrides
%LOCALE_USE_CP_ACP       = &H40000000???   ' // use the system ACP

'#if(WINVER >= 0x0400)
%LOCALE_RETURN_NUMBER    = &H20000000???   ' // return number instead of string
'#endif /* WINVER >= 0x0400 */

'#if (WINVER >= _WIN32_WINNT_WIN7)
%LOCALE_RETURN_GENITIVE_NAMES  = &H10000000???   ' // Flag to return the Genitive forms of month names
%LOCALE_ALLOW_NEUTRAL_NAMES    = &H08000000???   ' // Flag to allow returning neutral names/lcids for name conversion
'#endif //(WINVER >= _WIN32_WINNT_WIN7)

'//
'//  The following LCTypes are mutually exclusive in that they may NOT
'//  be used in combination with each other.
'//

'//
'// These are the various forms of the name of the locale:
'//
%LOCALE_SLOCALIZEDDISPLAYNAME  = &H00000002???   ' // localized name of locale, eg "German (Germany)" in UI language
'#if (WINVER >= _WIN32_WINNT_WIN7)
%LOCALE_SENGLISHDISPLAYNAME    = &H00000072???   ' // Display name (language + country usually) in English, eg "German (Germany)"
%LOCALE_SNATIVEDISPLAYNAME     = &H00000073???   ' // Display name in native locale language, eg "Deutsch (Deutschland)
'#endif //(WINVER >= _WIN32_WINNT_WIN7)

'#if (WINVER >= _WIN32_WINNT_VISTA)
%LOCALE_SLOCALIZEDLANGUAGENAME = &H0000006f???   ' // Language Display Name for a language, eg "German" in UI language
'#endif //(WINVER >= _WIN32_WINNT_VISTA)
%LOCALE_SENGLISHLANGUAGENAME   = &H00001001???   ' // English name of language, eg "German"
%LOCALE_SNATIVELANGUAGENAME    = &H00000004???   ' // native name of language, eg "Deutsch"

%LOCALE_SLOCALIZEDCOUNTRYNAME  = &H00000006???   ' // localized name of country, eg "Germany" in UI language
%LOCALE_SENGLISHCOUNTRYNAME    = &H00001002???   ' // English name of country, eg "Germany"
%LOCALE_SNATIVECOUNTRYNAME     = &H00000008???   ' // native name of country, eg "Deutschland"

'//
'// Legacy labels for the locale name values
'//
%LOCALE_SLANGUAGE              = &H00000002???   ' // localized name of locale, eg "German (Germany)" in UI language
'#if (WINVER >= _WIN32_WINNT_VISTA)
%LOCALE_SLANGDISPLAYNAME       = &H0000006f???   ' // Language Display Name for a language, eg "German" in UI language
'#endif //(WINVER >= _WIN32_WINNT_VISTA)
%LOCALE_SENGLANGUAGE           = &H00001001???   ' // English name of language, eg "German"
%LOCALE_SNATIVELANGNAME        = &H00000004???   ' // native name of language, eg "Deutsch"
%LOCALE_SCOUNTRY               = &H00000006???   ' // localized name of country, eg "Germany" in UI language
%LOCALE_SENGCOUNTRY            = &H00001002???   ' // English name of country, eg "Germany"
%LOCALE_SNATIVECTRYNAME        = &H00000008???   ' // native name of country, eg "Deutschland"

'//
'//  The following LCTypes are mutually exclusive in that they may NOT
'//  be used in combination with each other.
'//
%LOCALE_ILANGUAGE              = &H00000001???   ' // language id, LOCALE_SNAME preferred

%LOCALE_SABBREVLANGNAME        = &H00000003???   ' // abbreviated language name, LOCALE_SISO639LANGNAME preferred

%LOCALE_ICOUNTRY               = &H00000005???   ' // country code, eg 1, LOCALE_SISO3166CTRYNAME may be more useful.
%LOCALE_SABBREVCTRYNAME        = &H00000007???   ' // arbitrary abbreviated country name, LOCALE_SISO3166CTRYNAME preferred
%LOCALE_IGEOID                 = &H0000005B???   ' // geographical location id, eg "244"

%LOCALE_IDEFAULTLANGUAGE       = &H00000009???   ' // default language id, deprecated
%LOCALE_IDEFAULTCOUNTRY        = &H0000000A???   ' // default country code, deprecated
%LOCALE_IDEFAULTCODEPAGE       = &H0000000B???   ' // default oem code page (use of Unicode is recommended instead)
%LOCALE_IDEFAULTANSICODEPAGE   = &H00001004???   ' // default ansi code page (use of Unicode is recommended instead)
%LOCALE_IDEFAULTMACCODEPAGE    = &H00001011???   ' // default mac code page (use of Unicode is recommended instead)

%LOCALE_SLIST                  = &H0000000C???   ' // list item separator, eg "," for "1,2,3,4"
%LOCALE_IMEASURE               = &H0000000D???   ' // 0 = metric, 1 = US measurement system

%LOCALE_SDECIMAL               = &H0000000E???   ' // decimal separator, eg "." for 1,234.00
%LOCALE_STHOUSAND              = &H0000000F???   ' // thousand separator, eg "," for 1,234.00
%LOCALE_SGROUPING              = &H00000010???   ' // digit grouping, eg "3;0" for 1,000,000
%LOCALE_IDIGITS                = &H00000011???   ' // number of fractional digits eg 2 for 1.00
%LOCALE_ILZERO                 = &H00000012???   ' // leading zeros for decimal, 0 for .97, 1 for 0.97
%LOCALE_INEGNUMBER             = &H00001010???   ' // negative number mode, 0-4, see documentation
%LOCALE_SNATIVEDIGITS          = &H00000013???   ' // native ascii 0-9, eg "0123456789"

%LOCALE_SCURRENCY              = &H00000014???   ' // local monetary symbol, eg "$"
%LOCALE_SINTLSYMBOL            = &H00000015???   ' // intl monetary symbol, eg "USD"
%LOCALE_SMONDECIMALSEP         = &H00000016???   ' // monetary decimal separator, eg "." for $1,234.00
%LOCALE_SMONTHOUSANDSEP        = &H00000017???   ' // monetary thousand separator, eg "," for $1,234.00
%LOCALE_SMONGROUPING           = &H00000018???   ' // monetary grouping, eg "3;0" for $1,000,000.00
%LOCALE_ICURRDIGITS            = &H00000019???   ' // # local monetary digits, eg 2 for $1.00
%LOCALE_IINTLCURRDIGITS        = &H0000001A???   ' // # intl monetary digits, eg 2 for $1.00
%LOCALE_ICURRENCY              = &H0000001B???   ' // positive currency mode, 0-3, see documenation
%LOCALE_INEGCURR               = &H0000001C???   ' // negative currency mode, 0-15, see documentation

%LOCALE_SDATE                  = &H0000001D???   ' // date separator (derived from LOCALE_SSHORTDATE, use that instead)
%LOCALE_STIME                  = &H0000001E???   ' // time separator (derived from LOCALE_STIMEFORMAT, use that instead)
%LOCALE_SSHORTDATE             = &H0000001F???   ' // short date format string, eg "MM/dd/yyyy"
%LOCALE_SLONGDATE              = &H00000020???   ' // long date format string, eg "dddd, MMMM dd, yyyy"
%LOCALE_STIMEFORMAT            = &H00001003???   ' // time format string, eg "HH:mm:ss"
%LOCALE_IDATE                  = &H00000021???   ' // short date format ordering (derived from LOCALE_SSHORTDATE, use that instead)
%LOCALE_ILDATE                 = &H00000022???   ' // long date format ordering (derived from LOCALE_SLONGDATE, use that instead)
%LOCALE_ITIME                  = &H00000023???   ' // time format specifier (derived from LOCALE_STIMEFORMAT, use that instead)
%LOCALE_ITIMEMARKPOSN          = &H00001005???   ' // time marker position (derived from LOCALE_STIMEFORMAT, use that instead)
%LOCALE_ICENTURY               = &H00000024???   ' // century format specifier (short date, LOCALE_SSHORTDATE is preferred)
%LOCALE_ITLZERO                = &H00000025???   ' // leading zeros in time field (derived from LOCALE_STIMEFORMAT, use that instead)
%LOCALE_IDAYLZERO              = &H00000026???   ' // leading zeros in day field (short date, LOCALE_SSHORTDATE is preferred)
%LOCALE_IMONLZERO              = &H00000027???   ' // leading zeros in month field (short date, LOCALE_SSHORTDATE is preferred)
%LOCALE_S1159                  = &H00000028???   ' // AM designator, eg "AM"
%LOCALE_S2359                  = &H00000029???   ' // PM designator, eg "PM"

%LOCALE_ICALENDARTYPE          = &H00001009???   ' // type of calendar specifier, eg CAL_GREGORIAN
%LOCALE_IOPTIONALCALENDAR      = &H0000100B???   ' // additional calendar types specifier, eg CAL_GREGORIAN_US
%LOCALE_IFIRSTDAYOFWEEK        = &H0000100C???   ' // first day of week specifier, 0-6, 0=Monday, 6=Sunday
%LOCALE_IFIRSTWEEKOFYEAR       = &H0000100D???   ' // first week of year specifier, 0-2, see documentation

%LOCALE_SDAYNAME1              = &H0000002A???   ' // long name for Monday
%LOCALE_SDAYNAME2              = &H0000002B???   ' // long name for Tuesday
%LOCALE_SDAYNAME3              = &H0000002C???   ' // long name for Wednesday
%LOCALE_SDAYNAME4              = &H0000002D???   ' // long name for Thursday
%LOCALE_SDAYNAME5              = &H0000002E???   ' // long name for Friday
%LOCALE_SDAYNAME6              = &H0000002F???   ' // long name for Saturday
%LOCALE_SDAYNAME7              = &H00000030???   ' // long name for Sunday
%LOCALE_SABBREVDAYNAME1        = &H00000031???   ' // abbreviated name for Monday
%LOCALE_SABBREVDAYNAME2        = &H00000032???   ' // abbreviated name for Tuesday
%LOCALE_SABBREVDAYNAME3        = &H00000033???   ' // abbreviated name for Wednesday
%LOCALE_SABBREVDAYNAME4        = &H00000034???   ' // abbreviated name for Thursday
%LOCALE_SABBREVDAYNAME5        = &H00000035???   ' // abbreviated name for Friday
%LOCALE_SABBREVDAYNAME6        = &H00000036???   ' // abbreviated name for Saturday
%LOCALE_SABBREVDAYNAME7        = &H00000037???   ' // abbreviated name for Sunday
%LOCALE_SMONTHNAME1            = &H00000038???   ' // long name for January
%LOCALE_SMONTHNAME2            = &H00000039???   ' // long name for February
%LOCALE_SMONTHNAME3            = &H0000003A???   ' // long name for March
%LOCALE_SMONTHNAME4            = &H0000003B???   ' // long name for April
%LOCALE_SMONTHNAME5            = &H0000003C???   ' // long name for May
%LOCALE_SMONTHNAME6            = &H0000003D???   ' // long name for June
%LOCALE_SMONTHNAME7            = &H0000003E???   ' // long name for July
%LOCALE_SMONTHNAME8            = &H0000003F???   ' // long name for August
%LOCALE_SMONTHNAME9            = &H00000040???   ' // long name for September
%LOCALE_SMONTHNAME10           = &H00000041???   ' // long name for October
%LOCALE_SMONTHNAME11           = &H00000042???   ' // long name for November
%LOCALE_SMONTHNAME12           = &H00000043???   ' // long name for December
%LOCALE_SMONTHNAME13           = &H0000100E???   ' // long name for 13th month (if exists)
%LOCALE_SABBREVMONTHNAME1      = &H00000044???   ' // abbreviated name for January
%LOCALE_SABBREVMONTHNAME2      = &H00000045???   ' // abbreviated name for February
%LOCALE_SABBREVMONTHNAME3      = &H00000046???   ' // abbreviated name for March
%LOCALE_SABBREVMONTHNAME4      = &H00000047???   ' // abbreviated name for April
%LOCALE_SABBREVMONTHNAME5      = &H00000048???   ' // abbreviated name for May
%LOCALE_SABBREVMONTHNAME6      = &H00000049???   ' // abbreviated name for June
%LOCALE_SABBREVMONTHNAME7      = &H0000004A???   ' // abbreviated name for July
%LOCALE_SABBREVMONTHNAME8      = &H0000004B???   ' // abbreviated name for August
%LOCALE_SABBREVMONTHNAME9      = &H0000004C???   ' // abbreviated name for September
%LOCALE_SABBREVMONTHNAME10     = &H0000004D???   ' // abbreviated name for October
%LOCALE_SABBREVMONTHNAME11     = &H0000004E???   ' // abbreviated name for November
%LOCALE_SABBREVMONTHNAME12     = &H0000004F???   ' // abbreviated name for December
%LOCALE_SABBREVMONTHNAME13     = &H0000100F???   ' // abbreviated name for 13th month (if exists)

%LOCALE_SPOSITIVESIGN          = &H00000050???   ' // positive sign, eg ""
%LOCALE_SNEGATIVESIGN          = &H00000051???   ' // negative sign, eg "-"
%LOCALE_IPOSSIGNPOSN           = &H00000052???   ' // positive sign position (derived from INEGCURR)
%LOCALE_INEGSIGNPOSN           = &H00000053???   ' // negative sign position (derived from INEGCURR)
%LOCALE_IPOSSYMPRECEDES        = &H00000054???   ' // mon sym precedes pos amt (derived from ICURRENCY)
%LOCALE_IPOSSEPBYSPACE         = &H00000055???   ' // mon sym sep by space from pos amt (derived from ICURRENCY)
%LOCALE_INEGSYMPRECEDES        = &H00000056???   ' // mon sym precedes neg amt (derived from INEGCURR)
%LOCALE_INEGSEPBYSPACE         = &H00000057???   ' // mon sym sep by space from neg amt (derived from INEGCURR)

'#if(WINVER >= 0x0400)
%LOCALE_FONTSIGNATURE          = &H00000058???   ' font signature
%LOCALE_SISO639LANGNAME        = &H00000059???   ' ISO abbreviated language name, eg "en"
%LOCALE_SISO3166CTRYNAME       = &H0000005A???   ' ISO abbreviated country name, eg "US"
'#endif /* WINVER >= 0x0400 */

'#if(WINVER >= 0x0500)
%LOCALE_IDEFAULTEBCDICCODEPAGE = &H00001012???   ' default ebcdic code page (use of Unicode is recommended instead)
%LOCALE_IPAPERSIZE             = &H0000100A???   ' 1 = letter, 5 = legal, 8 = a3, 9 = a4
%LOCALE_SENGCURRNAME           = &H00001007???   ' english name of currency, eg "Euro"
%LOCALE_SNATIVECURRNAME        = &H00001008???   ' native name of currency, eg "euro"
%LOCALE_SYEARMONTH             = &H00001006???   ' year month format string, eg "MM/yyyy"
%LOCALE_SSORTNAME              = &H00001013???   ' sort name, usually "", eg "Dictionary" in UI Language
%LOCALE_IDIGITSUBSTITUTION     = &H00001014???   ' 0 = context, 1 = none, 2 = national
'#endif /* WINVER >= 0x0500 */

'#if (WINVER >= 0x0600)
%LOCALE_SNAME                  = &H0000005c???   ' // locale name (ie: en-us)
%LOCALE_SDURATION              = &H0000005d???   ' // time duration format
%LOCALE_SKEYBOARDSTOINSTALL    = &H0000005e???   ' // Used internally, see GetKeyboardLayoutName() function
%LOCALE_SSHORTESTDAYNAME1      = &H00000060???   ' // Shortest day name for Monday
%LOCALE_SSHORTESTDAYNAME2      = &H00000061???   ' // Shortest day name for Tuesday
%LOCALE_SSHORTESTDAYNAME3      = &H00000062???   ' // Shortest day name for Wednesday
%LOCALE_SSHORTESTDAYNAME4      = &H00000063???   ' // Shortest day name for Thursday
%LOCALE_SSHORTESTDAYNAME5      = &H00000064???   ' // Shortest day name for Friday
%LOCALE_SSHORTESTDAYNAME6      = &H00000065???   ' // Shortest day name for Saturday
%LOCALE_SSHORTESTDAYNAME7      = &H00000066???   ' // Shortest day name for Sunday
%LOCALE_SISO639LANGNAME2       = &H00000067???   ' // 3 character ISO abbreviated language name, eg "eng"
%LOCALE_SISO3166CTRYNAME2      = &H00000068???   ' // 3 character ISO country name, eg "USA"
%LOCALE_SNAN                   = &H00000069???   ' // Not a Number, eg "NaN"
%LOCALE_SPOSINFINITY           = &H0000006a???   ' // + Infinity, eg "infinity"
%LOCALE_SNEGINFINITY           = &H0000006b???   ' // - Infinity, eg "-infinity"
%LOCALE_SSCRIPTS               = &H0000006c???   ' // Typical scripts in the locale: ; delimited script codes, eg "Latn;"
%LOCALE_SPARENT                = &H0000006d???   ' // Fallback name for resources, eg "en" for "en-US"
%LOCALE_SCONSOLEFALLBACKNAME   = &H0000006e???   ' // Fallback name for within the console for Unicode Only locales, eg "en" for bn-IN
'#endif //(WINVER >= 0x0600)

'#if (WINVER >= _WIN32_WINNT_WIN7)
%LOCALE_IREADINGLAYOUT         = &H00000070???   ' // Returns one of the following 4 reading layout values:
                                                 ' // 0 - Left to right (eg en-US)
                                                 ' // 1 - Right to left (eg arabic locales)
                                                 ' // 2 - Vertical top to bottom with columns to the left and also left to right (ja-JP locales)
                                                 ' // 3 - Vertical top to bottom with columns proceeding to the right
%LOCALE_INEUTRAL               = &H00000071???   ' // Returns 0 for specific cultures, 1 for neutral cultures.
%LOCALE_INEGATIVEPERCENT       = &H00000074???   ' // Returns 0-11 for the negative percent format
%LOCALE_IPOSITIVEPERCENT       = &H00000075???   ' // Returns 0-3 for the positive percent formatIPOSITIVEPERCENT
%LOCALE_SPERCENT               = &H00000076???   ' // Returns the percent symbol
%LOCALE_SPERMILLE              = &H00000077???   ' // Returns the permille (U+2030) symbol
%LOCALE_SMONTHDAY              = &H00000078???   ' // Returns the preferred month/day format
%LOCALE_SSHORTTIME             = &H00000079???   ' // Returns the preferred short time format (ie: no seconds, just h:mm)
%LOCALE_SOPENTYPELANGUAGETAG   = &H0000007a???   ' // Open type language tag, eg: "latn" or "dflt"
%LOCALE_SSORTLOCALE            = &H0000007b???   ' // Name of locale to use for sorting/collation/casing behavior.
'#endif //(WINVER >= _WIN32_WINNT_WIN7)

'//
'//  Time Flags for GetTimeFormat.
'//
%TIME_NOMINUTESORSECONDS = &H00000001???   ' // do not use minutes or seconds
%TIME_NOSECONDS          = &H00000002???   ' // do not use seconds
%TIME_NOTIMEMARKER       = &H00000004???   ' // do not use time marker
%TIME_FORCE24HOURFORMAT  = &H00000008???   ' // always use 24 hour format


'//
'//  Date Flags for GetDateFormat.
'//
%DATE_SHORTDATE          = &H00000001???   ' // use short date picture
%DATE_LONGDATE           = &H00000002???   ' // use long date picture
%DATE_USE_ALT_CALENDAR   = &H00000004???   ' // use alternate calendar (if any)

'#if(WINVER >= 0x0500)
%DATE_YEARMONTH          = &H00000008???   ' // use year month picture
%DATE_LTRREADING         = &H00000010???   ' // add marks for left to right reading order layout
%DATE_RTLREADING         = &H00000020???   ' // add marks for right to left reading order layout
'#endif /* WINVER >= 0x0500 */

'#if (WINVER >= _WIN32_WINNT_WIN7)
%DATE_AUTOLAYOUT         = &H00000040???   ' // add appropriate marks for left-to-right or right-to-left reading order layout
'#endif //(WINVER >= _WIN32_WINNT_WIN7)

'//
'//  Calendar Types.
'//
'//  These types are used for the EnumCalendarInfo and GetCalendarInfo
'//  NLS API routines.
'//  Some of these types are also used for the SetCalendarInfo NLS API
'//  routine.
'//

'//
'//  The following CalTypes may be used in combination with any other CalTypes.
'//
'//    CAL_NOUSEROVERRIDE
'//
'//    CAL_USE_CP_ACP is used in the A (Ansi) apis that need to do string
'//    translation.
'//
'//    CAL_RETURN_NUMBER will return the result from GetCalendarInfo as a
'//    number instead of a string.  This flag is only valid for the CalTypes
'//    beginning with CAL_I.
'//
'#if(WINVER >= 0x0500)
%CAL_NOUSEROVERRIDE = %LOCALE_NOUSEROVERRIDE  ' // do not use user overrides
%CAL_USE_CP_ACP     = %LOCALE_USE_CP_ACP      ' // use the system ACP
%CAL_RETURN_NUMBER  = %LOCALE_RETURN_NUMBER   ' // return number instead of string
'#endif /* WINVER >= 0x0500 */

'#if (WINVER >= _WIN32_WINNT_WIN7)
%CAL_RETURN_GENITIVE_NAMES = %LOCALE_RETURN_GENITIVE_NAMES   ' // return genitive forms of month names
'#endif // winver >= windows 7

'//
'//  The following CalTypes are mutually exclusive in that they may NOT
'//  be used in combination with each other.
'//
%CAL_ICALINTVALUE       = &H00000001???  ' // calendar type
%CAL_SCALNAME           = &H00000002???  ' // native name of calendar
%CAL_IYEAROFFSETRANGE   = &H00000003???  ' // starting years of eras
%CAL_SERASTRING         = &H00000004???  ' // era name for IYearOffsetRanges, eg A.D.
%CAL_SSHORTDATE         = &H00000005???  ' // short date format string
%CAL_SLONGDATE          = &H00000006???  ' // long date format string
%CAL_SDAYNAME1          = &H00000007???  ' // native name for Monday
%CAL_SDAYNAME2          = &H00000008???  ' // native name for Tuesday
%CAL_SDAYNAME3          = &H00000009???  ' // native name for Wednesday
%CAL_SDAYNAME4          = &H0000000a???  ' // native name for Thursday
%CAL_SDAYNAME5          = &H0000000b???  ' // native name for Friday
%CAL_SDAYNAME6          = &H0000000c???  ' // native name for Saturday
%CAL_SDAYNAME7          = &H0000000d???  ' // native name for Sunday
%CAL_SABBREVDAYNAME1    = &H0000000e???  ' // abbreviated name for Mon
%CAL_SABBREVDAYNAME2    = &H0000000f???  ' // abbreviated name for Tue
%CAL_SABBREVDAYNAME3    = &H00000010???  ' // abbreviated name for Wed
%CAL_SABBREVDAYNAME4    = &H00000011???  ' // abbreviated name for Thu
%CAL_SABBREVDAYNAME5    = &H00000012???  ' // abbreviated name for Fri
%CAL_SABBREVDAYNAME6    = &H00000013???  ' // abbreviated name for Sat
%CAL_SABBREVDAYNAME7    = &H00000014???  ' // abbreviated name for Sun
%CAL_SMONTHNAME1        = &H00000015???  ' // native name for January
%CAL_SMONTHNAME2        = &H00000016???  ' // native name for February
%CAL_SMONTHNAME3        = &H00000017???  ' // native name for March
%CAL_SMONTHNAME4        = &H00000018???  ' // native name for April
%CAL_SMONTHNAME5        = &H00000019???  ' // native name for May
%CAL_SMONTHNAME6        = &H0000001a???  ' // native name for June
%CAL_SMONTHNAME7        = &H0000001b???  ' // native name for July
%CAL_SMONTHNAME8        = &H0000001c???  ' // native name for August
%CAL_SMONTHNAME9        = &H0000001d???  ' // native name for September
%CAL_SMONTHNAME10       = &H0000001e???  ' // native name for October
%CAL_SMONTHNAME11       = &H0000001f???  ' // native name for November
%CAL_SMONTHNAME12       = &H00000020???  ' // native name for December
%CAL_SMONTHNAME13       = &H00000021???  ' // native name for 13th month (if any)
%CAL_SABBREVMONTHNAME1  = &H00000022???  ' // abbreviated name for Jan
%CAL_SABBREVMONTHNAME2  = &H00000023???  ' // abbreviated name for Feb
%CAL_SABBREVMONTHNAME3  = &H00000024???  ' // abbreviated name for Mar
%CAL_SABBREVMONTHNAME4  = &H00000025???  ' // abbreviated name for Apr
%CAL_SABBREVMONTHNAME5  = &H00000026???  ' // abbreviated name for May
%CAL_SABBREVMONTHNAME6  = &H00000027???  ' // abbreviated name for Jun
%CAL_SABBREVMONTHNAME7  = &H00000028???  ' // abbreviated name for Jul
%CAL_SABBREVMONTHNAME8  = &H00000029???  ' // abbreviated name for Aug
%CAL_SABBREVMONTHNAME9  = &H0000002a???  ' // abbreviated name for Sep
%CAL_SABBREVMONTHNAME10 = &H0000002b???  ' // abbreviated name for Oct
%CAL_SABBREVMONTHNAME11 = &H0000002c???  ' // abbreviated name for Nov
%CAL_SABBREVMONTHNAME12 = &H0000002d???  ' // abbreviated name for Dec
%CAL_SABBREVMONTHNAME13 = &H0000002e???  ' // abbreviated name for 13th month (if any)

'#if(WINVER >= 0x0500)
%CAL_SYEARMONTH         = &H0000002f???  ' // year month format string
%CAL_ITWODIGITYEARMAX   = &H00000030???  ' // two digit year max
'#endif /* WINVER >= 0x0500 */

'#if (WINVER >= 0x0600)
%CAL_SSHORTESTDAYNAME1  = &H00000031???  ' // Shortest day name for Mo
%CAL_SSHORTESTDAYNAME2  = &H00000032???  ' // Shortest day name for Tu
%CAL_SSHORTESTDAYNAME3  = &H00000033???  ' // Shortest day name for We
%CAL_SSHORTESTDAYNAME4  = &H00000034???  ' // Shortest day name for Th
%CAL_SSHORTESTDAYNAME5  = &H00000035???  ' // Shortest day name for Fr
%CAL_SSHORTESTDAYNAME6  = &H00000036???  ' // Shortest day name for Sa
%CAL_SSHORTESTDAYNAME7  = &H00000037???  ' // Shortest day name for Su
'#endif //(WINVER >= 0x0600)

'#if (WINVER >= _WIN32_WINNT_WIN7)
%CAL_SMONTHDAY          = &H00000038???  ' // Month/day format
%CAL_SABBREVERASTRING   = &H00000039???  ' // Abbreviated era string (eg: AD)
'#endif // winver >= windows 7

'//
'//  Calendar Enumeration Value.
'//
%ENUM_ALL_CALENDARS     = &Hffffffff???  ' // enumerate all calendars

'//
'//  Calendar ID Values.
'//
%CAL_GREGORIAN              = 1   ' Gregorian (localized) calendar
%CAL_GREGORIAN_US           = 2   ' // Gregorian (U.S.) calendar
%CAL_JAPAN                  = 3   ' // Japanese Emperor Era calendar
%CAL_TAIWAN                 = 4   ' // Taiwan calendar
%CAL_KOREA                  = 5   ' // Korean Tangun Era calendar
%CAL_HIJRI                  = 6   ' // Hijri (Arabic Lunar) calendar
%CAL_THAI                   = 7   ' // Thai calendar
%CAL_HEBREW                 = 8   ' // Hebrew (Lunar) calendar
%CAL_GREGORIAN_ME_FRENCH    = 9   ' // Gregorian Middle East French calendar
%CAL_GREGORIAN_ARABIC       = 10  ' // Gregorian Arabic calendar
%CAL_GREGORIAN_XLIT_ENGLISH = 11  ' // Gregorian Transliterated English calendar
%CAL_GREGORIAN_XLIT_FRENCH  = 12  ' // Gregorian Transliterated French calendar
%CAL_UMALQURA               = 23  ' // UmAlQura Hijri (Arabic Lunar) calendar

'//
'//  Language Group ID Values.
'//
%LGRPID_WESTERN_EUROPE      = &H0001??   ' //Western Europe & U.S.
%LGRPID_CENTRAL_EUROPE      = &H0002??   ' //Central Europe
%LGRPID_BALTIC              = &H0003??   ' //Baltic
%LGRPID_GREEK               = &H0004??   ' //Greek
%LGRPID_CYRILLIC            = &H0005??   ' //Cyrillic
%LGRPID_TURKISH             = &H0006??   ' //Turkish
%LGRPID_JAPANESE            = &H0007??   ' //Japanese
%LGRPID_KOREAN              = &H0008??   ' //Korean
%LGRPID_TRADITIONAL_CHINESE = &H0009??   ' //Traditional Chinese
%LGRPID_SIMPLIFIED_CHINESE  = &H000a??   ' //Simplified Chinese
%LGRPID_THAI                = &H000b??   ' //Thai
%LGRPID_HEBREW              = &H000c??   ' //Hebrew
%LGRPID_ARABIC              = &H000d??   ' //Arabic
%LGRPID_VIETNAMESE          = &H000e??   ' //Vietnamese
%LGRPID_INDIC               = &H000f??   ' //Indic
%LGRPID_GEORGIAN            = &H0010??   ' //Georgian
%LGRPID_ARMENIAN            = &H0011??   ' //Armenian

'#if (WINVER >= 0x0600)
'//
'//  MUI function flag values
'//
%MUI_LANGUAGE_ID                     = &H4???      ' // Use traditional language ID convention
%MUI_LANGUAGE_NAME                   = &H8???      ' // Use ISO language (culture) name convention
%MUI_MERGE_SYSTEM_FALLBACK           = &H10???     ' // GetThreadPreferredUILanguages merges in parent and base languages
%MUI_MERGE_USER_FALLBACK             = &H20???     ' // GetThreadPreferredUILanguages merges in user preferred languages
%MUI_UI_FALLBACK                     = %MUI_MERGE_SYSTEM_FALLBACK OR %MUI_MERGE_USER_FALLBACK
%MUI_THREAD_LANGUAGES                = &H40???     ' // GetThreadPreferredUILanguages merges in user preferred languages
%MUI_CONSOLE_FILTER                  = &H100???    ' // SetThreadPreferredUILanguages takes on console specific behavior
%MUI_COMPLEX_SCRIPT_FILTER           = &H200???    ' // SetThreadPreferredUILanguages takes on complex script specific behavior
%MUI_RESET_FILTERS                   = &H001???    ' // Reset MUI_CONSOLE_FILTER and MUI_COMPLEX_SCRIPT_FILTER
%MUI_USER_PREFERRED_UI_LANGUAGES     = &H10???     ' // GetFileMUIPath returns the MUI files for the languages in the fallback list
%MUI_USE_INSTALLED_LANGUAGES         = &H20???     ' // GetFileMUIPath returns all the MUI files installed in the machine
%MUI_USE_SEARCH_ALL_LANGUAGES        = &H40???     ' // GetFileMUIPath returns all the MUI files irrespective of whether language is installed
%MUI_LANG_NEUTRAL_PE_FILE            = &H100???    ' // GetFileMUIPath returns target file with .mui extension
%MUI_NON_LANG_NEUTRAL_FILE           = &H200???    ' // GetFileMUIPath returns target file with same name as source
%MUI_MACHINE_LANGUAGE_SETTINGS       = &H400???
%MUI_FILETYPE_NOT_LANGUAGE_NEUTRAL   = &H001???   ' // GetFileMUIInfo found a non-split resource file
%MUI_FILETYPE_LANGUAGE_NEUTRAL_MAIN  = &H002???   ' // GetFileMUIInfo found a LN main module resource file
%MUI_FILETYPE_LANGUAGE_NEUTRAL_MUI   = &H004???   ' // GetFileMUIInfo found a LN MUI module resource file
%MUI_QUERY_TYPE                      = &H001???   ' // GetFileMUIInfo will look for the type of the resource file
%MUI_QUERY_CHECKSUM                  = &H002???   ' // GetFileMUIInfo will look for the checksum of the resource file
%MUI_QUERY_LANGUAGE_NAME             = &H004???   ' // GetFileMUIInfo will look for the culture of the resource file
%MUI_QUERY_RESOURCE_TYPES            = &H008???   ' // GetFileMUIInfo will look for the resource types of the resource file
%MUI_FILEINFO_VERSION                = &H001???   ' // Version of FILEMUIINFO structure used with GetFileMUIInfo

%MUI_FULL_LANGUAGE                   = &H01???
%MUI_PARTIAL_LANGUAGE                = &H02???
%MUI_LIP_LANGUAGE                    = &H04???
%MUI_LANGUAGE_INSTALLED              = &H20???
%MUI_LANGUAGE_LICENSED               = &H40???

'//
'// MUI_CALLBACK_FLAG defines are duplicated in rtlmui.h
'//

'%MUI_CALLBACK_ALL_FLAGS = %MUI_CALLBACK_FLAG_UPGRADED_INSTALLATION  ' // OR all other flags when defined.

'//
'// MUI_CALLBACK_ flags are duplicated in rtlmui.h
'//

'#endif

'////////////////////////////////////////////////////////////////////////////
'//
'//  Typedefs
'//
'//  Define all types for the NLS component here.
'//
'////////////////////////////////////////////////////////////////////////////

'//
'//  Language Group ID.
'//
'typedef DWORD LGRPID;


'//
'//  Locale type constant.
'//
'typedef DWORD LCTYPE;


'//
'//  Calendar type constant.
'//
'typedef DWORD CALTYPE;


'//
'//  Calendar ID.
'//
'typedef DWORD CALID;


'//
'//  CP Info.
'//

' // Size = 20 bytes
TYPE CPINFO DWORD
   MaxCharSize AS DWORD                       ' max length (bytes) of a char
   DefaultChar(%MAX_DEFAULTCHAR - 1) AS BYTE  ' default character
   LeadByte(%MAX_LEADBYTES - 1) AS BYTE       ' lead byte ranges
END TYPE

' // Size = 284 bytes
TYPE CPINFOEXA BYTE
   MaxCharSize AS DWORD                      ' max length (in bytes) of a char
   DefaultChar(%MAX_DEFAULTCHAR - 1) AS BYTE ' default character (MB)
   LeadByte(%MAX_LEADBYTES - 1) AS BYTE      ' lead byte ranges
   UnicodeDefaultChar AS WORD                ' default character (Unicode)
   CodePage AS DWORD                         ' code page id
   CodePageName AS ASCIIZ * %MAX_PATH        ' code page name (ANSI?)
END TYPE

' // Size = 544 bytes
TYPE CPINFOEXW BYTE
   MaxCharSize AS DWORD                      ' max length (in bytes) of a char
   DefaultChar(%MAX_DEFAULTCHAR - 1) AS BYTE ' default character (MB)
   LeadByte(%MAX_LEADBYTES - 1) AS BYTE      ' lead byte ranges
   UnicodeDefaultChar AS WORD                ' default character (Unicode)
   CodePage AS DWORD                         ' code page id
   CodePageName AS WSTRINGZ * %MAX_PATH      ' code page name (Unicode)
END TYPE

#IF %DEF(%UNICODE)
   MACRO CPINFOEX = CPINFOEXW
#ELSE
   MACRO CPINFOEX = CPINFOEXA
#ENDIF

'//
'//  Number format.
'//

' // Size = 24 bytes
TYPE NUMBERFMTA DWORD
   NumDigits     AS DWORD        ' UINT  // number of decimal digits
   LeadingZero   AS DWORD        ' UINT  // if leading zero in decimal fields
   Grouping      AS DWORD        ' UINT  // group size left of decimal
   lpDecimalSep  AS ASCIIZ PTR   ' LPSTR // ptr to decimal separator string
   lpThousandSep AS ASCIIZ PTR   ' LPSTR // ptr to thousand separator string
   NegativeOrder AS DWORD        ' UINT  // negative number ordering
END TYPE

' // Size = 24 bytes
TYPE NUMBERFMTW DWORD
   NumDigits     AS DWORD          ' UINT   // number of decimal digits
   LeadingZero   AS DWORD          ' UINT   // if leading zero in decimal fields
   Grouping      AS DWORD          ' UINT   // group size left of decimal
   lpDecimalSep  AS WSTRINGZ PTR   ' LPWSTR // ptr to decimal separator string
   lpThousandSep AS WSTRINGZ PTR   ' LPWSTR // ptr to thousand separator string
   NegativeOrder AS DWORD          ' UINT   // negative number ordering
END TYPE

#IF %DEF(%UNICODE)
   MACRO NUMBERFMT = NUMBERFMTW
#ELSE
   MACRO NUMBERFMT = NUMBERFMTA
#ENDIF

'//
'//  Currency format.
'//

' // Size = 32 bytes
TYPE CURRENCYFMTA DWORD
   NumDigits        AS DWORD        ' UINT  // number of decimal digits
   LeadingZero      AS DWORD        ' UINT  // if leading zero in decimal fields
   Grouping         AS DWORD        ' UINT  // group size left of decimal
   lpDecimalSep     AS ASCIIZ PTR   ' LPSTR // ptr to decimal separator string
   lpThousandSep    AS ASCIIZ PTR   ' LPSTR // ptr to thousand separator string
   NegativeOrder    AS DWORD        ' UINT  // negative currency ordering
   PositiveOrder    AS DWORD        ' UINT  // positive currency ordering
   lpCurrencySymbol AS ASCIIZ PTR   ' LPSTR // ptr to currency symbol string
END TYPE

' // Size = 32 bytes
TYPE CURRENCYFMTW DWORD
   NumDigits        AS DWORD          ' UINT   // number of decimal digits
   LeadingZero      AS DWORD          ' UINT   // if leading zero in decimal fields
   Grouping         AS DWORD          ' UINT   // group size left of decimal
   lpDecimalSep     AS WSTRINGZ PTR   ' LPWSTR // ptr to decimal separator string
   lpThousandSep    AS WSTRINGZ PTR   ' LPWSTR // ptr to thousand separator string
   NegativeOrder    AS DWORD          ' UINT   // negative currency ordering
   PositiveOrder    AS DWORD          ' UINT   // positive currency ordering
   lpCurrencySymbol AS WSTRINGZ PTR   ' LPWSTR // ptr to currency symbol string
END TYPE

#IF %DEF(%UNICODE)
   MACRO CURRENCYFMT = CURRENCYFMTW
#ELSE
   MACRO CURRENCYFMT = CURRENCYFMTA
#ENDIF

'//
'//  NLS function capabilities
'//

' SYSNLS_FUNCTION enum
%COMPARE_STRING    =  &H0001
'typedef DWORD NLS_FUNCTION;


'//
'//  NLS version structure.
'//

' // Size = 12 bytes
TYPE NLSVERSIONINFO DWORD
   dwNLSVersionInfoSize AS DWORD   ' DWORD
   dwNLSVersion         AS DWORD   ' DWORD
   dwDefinedVersion     AS DWORD   ' DWORD
END TYPE

' // Size = 32 bytes
'// This is to be deprecated, please use the NLSVERSIONINFO
'// structure above in the future.  The difference is that
'// the effective ID is more robust.
TYPE NLSVERSIONINFOEX DWORD
   dwNLSVersionInfoSize AS DWORD   ' DWORD // sizeof(NLSVERSIONINFOEX) == 32 bytes
   dwNLSVersion         AS DWORD   ' DWORD
   dwDefinedVersion     AS DWORD   ' DWORD
   dwEffectiveId        AS DWORD   ' DWORD // Use NLSVERSIONINFO instead
   guidCustomVersion    AS GUID    ' GUID
END TYPE

'//
'//  GEO defines
'//

'typedef LONG    GEOID;
'typedef DWORD   GEOTYPE;
'typedef DWORD   GEOCLASS;

%GEOID_NOT_AVAILABLE = -1

'//
'//  GEO information types for clients to query
'//

' SYSGEOTYPE enum
%GEO_NATION            = &H0001
%GEO_LATITUDE          = &H0002
%GEO_LONGITUDE         = &H0003
%GEO_ISO2              = &H0004
%GEO_ISO3              = &H0005
%GEO_RFC1766           = &H0006
%GEO_LCID              = &H0007
%GEO_FRIENDLYNAME      = &H0008
%GEO_OFFICIALNAME      = &H0009
%GEO_TIMEZONES         = &H000A
%GEO_OFFICIALLANGUAGES = &H000B

'//
'//  More GEOCLASS defines will be listed here
'//

' SYSGEOCLASS enum
%GEOCLASS_NATION = 16
%GEOCLASS_REGION = 14

'//
'//  More GEOCLASS defines will be listed here
'//

' enum SYSGEOCLASS {
%GEOCLASS_NATION  = 16
%GEOCLASS_REGION  = 14

'#if (WINVER >= 0x0600)
'//
'//  Normalization forms
'//

' enum NORM_FORM
%NormalizationOther  = 0      ' // Not supported
%NormalizationC      = &H1    ' // Each base plus combining characters to the canonical precomposed equivalent.
%NormalizationD      = &H2    ' // Each precomposed character to its canonical decomposed equivalent.
%NormalizationKC     = &H5    ' // Each base plus combining characters to the canonical precomposed
                              ' //   equivalents and all compatibility characters to their equivalents.
%NormalizationKD     = &H6    ' // Each precomposed character to its canonical decomposed equivalent
                              ' //   and all compatibility characters to their equivalents.

'//
'// IDN (International Domain Name) Flags
'//
%IDN_ALLOW_UNASSIGNED        = &H01    ' // Allow unassigned "query" behavior per RFC 3454
%IDN_USE_STD3_ASCII_RULES    = &H02    ' // Enforce STD3 ASCII restrictions for legal characters

%VS_ALLOW_LATIN              = &H0001  ' // Allow Latin in test script even if not present in locale script

%GSS_ALLOW_INHERITED_COMMON  = &H0001  ' // Output script ids for inherited and common character types if present
'#endif //(WINVER >= 0x0600)

'//
'//  Enumeration function constants.
'//

'#ifdef STRICT

'typedef BOOL (CALLBACK* LANGUAGEGROUP_ENUMPROCA)(LGRPID, LPSTR, LPSTR, DWORD, LONG_PTR);
'typedef BOOL (CALLBACK* LANGGROUPLOCALE_ENUMPROCA)(LGRPID, LCID, LPSTR, LONG_PTR);
'typedef BOOL (CALLBACK* UILANGUAGE_ENUMPROCA)(LPSTR, LONG_PTR);
'typedef BOOL (CALLBACK* LOCALE_ENUMPROCA)(LPSTR);
'typedef BOOL (CALLBACK* CODEPAGE_ENUMPROCA)(LPSTR);
'typedef BOOL (CALLBACK* DATEFMT_ENUMPROCA)(LPSTR);
'typedef BOOL (CALLBACK* DATEFMT_ENUMPROCEXA)(LPSTR, CALID);
'typedef BOOL (CALLBACK* TIMEFMT_ENUMPROCA)(LPSTR);
'typedef BOOL (CALLBACK* CALINFO_ENUMPROCA)(LPSTR);
'typedef BOOL (CALLBACK* CALINFO_ENUMPROCEXA)(LPSTR, CALID);

'typedef BOOL (CALLBACK* LANGUAGEGROUP_ENUMPROCW)(LGRPID, LPWSTR, LPWSTR, DWORD, LONG_PTR);
'typedef BOOL (CALLBACK* LANGGROUPLOCALE_ENUMPROCW)(LGRPID, LCID, LPWSTR, LONG_PTR);
'typedef BOOL (CALLBACK* UILANGUAGE_ENUMPROCW)(LPWSTR, LONG_PTR);
'typedef BOOL (CALLBACK* LOCALE_ENUMPROCW)(LPWSTR);
'typedef BOOL (CALLBACK* CODEPAGE_ENUMPROCW)(LPWSTR);
'typedef BOOL (CALLBACK* DATEFMT_ENUMPROCW)(LPWSTR);
'typedef BOOL (CALLBACK* DATEFMT_ENUMPROCEXW)(LPWSTR, CALID);
'typedef BOOL (CALLBACK* TIMEFMT_ENUMPROCW)(LPWSTR);
'typedef BOOL (CALLBACK* CALINFO_ENUMPROCW)(LPWSTR);
'typedef BOOL (CALLBACK* CALINFO_ENUMPROCEXW)(LPWSTR, CALID);
'typedef BOOL (CALLBACK* GEO_ENUMPROC)(GEOID);

'#else // !STRICT

'typedef FARPROC LANGUAGEGROUP_ENUMPROCA;
'typedef FARPROC LANGGROUPLOCALE_ENUMPROCA;
'typedef FARPROC UILANGUAGE_ENUMPROCA;
'typedef FARPROC LOCALE_ENUMPROCA;
'typedef FARPROC CODEPAGE_ENUMPROCA;
'typedef FARPROC DATEFMT_ENUMPROCA;
'typedef FARPROC DATEFMT_ENUMPROCEXA;
'typedef FARPROC TIMEFMT_ENUMPROCA;
'typedef FARPROC CALINFO_ENUMPROCA;
'typedef FARPROC CALINFO_ENUMPROCEXA;
'typedef FARPROC GEO_ENUMPROC;

'typedef FARPROC LANGUAGEGROUP_ENUMPROCW;
'typedef FARPROC LANGGROUPLOCALE_ENUMPROCW;
'typedef FARPROC UILANGUAGE_ENUMPROCW;
'typedef FARPROC LOCALE_ENUMPROCW;
'typedef FARPROC CODEPAGE_ENUMPROCW;
'typedef FARPROC DATEFMT_ENUMPROCW;
'typedef FARPROC DATEFMT_ENUMPROCEXW;
'typedef FARPROC TIMEFMT_ENUMPROCW;
'typedef FARPROC CALINFO_ENUMPROCW;
'typedef FARPROC CALINFO_ENUMPROCEXW;

'#endif // !STRICT

'//
'// Information about a MUI file, used as input/output in GetFileMUIInfo
'// All offsets are relative to start of the structure. Offsets with value 0 mean empty field.
'//

' // Size = 80 bytes
TYPE FILEMUIINFO DWORD
   dwSize               AS DWORD   ' DWORD // Size of the structure including buffer size [in]
   dwVersion            AS DWORD   ' DWORD // Version of the structure [in]
   dwFileType           AS DWORD   ' DWORD // Type of the file [out]
   pChecksum(15)        AS BYTE    ' BYTE // Checksum of the file [out]
   pServiceChecksum(15) AS BYTE    ' BYTE // Checksum of the file [out]
   dwLanguageNameOffset AS DWORD   ' DWORD // Language name of the file [out]
   dwTypeIDMainSize     AS DWORD   ' DWORD // Number of TypeIDs in main module [out]
   dwTypeIDMainOffset   AS DWORD   ' DWORD // Array of TypeIDs (DWORD) in main module [out]
   dwTypeNameMainOffset AS DWORD   ' DWORD // Multistring array of TypeNames in main module [out]
   dwTypeIDMUISize      AS DWORD   ' DWORD // Number of TypeIDs in MUI module [out]
   dwTypeIDMUIOffset    AS DWORD   ' DWORD // Array of TypeIDs (DWORD) in MUI module [out]
   dwTypeNameMUIOffset  AS DWORD   ' DWORD // Multistring array of TypeNames in MUI module [out]
   abBuffer(7)          AS BYTE    ' BYTE // Buffer for extra data [in] (Size 4 is for padding)
END TYPE

'////////////////////////////////////////////////////////////////////////////
'//
'//  Macros
'//
'//  Define all macros for the NLS component here.
'//
'////////////////////////////////////////////////////////////////////////////

'//
'//  Macros to determine whether a character is a high or low surrogate,
'//  and whether two code points make up a surrogate pair (a high surrogate
'//  and a low surrogate).
'//
'#define IS_HIGH_SURROGATE(wch) (((wch) >= HIGH_SURROGATE_START) && ((wch) <= HIGH_SURROGATE_END))
'#define IS_LOW_SURROGATE(wch)  (((wch) >= LOW_SURROGATE_START) && ((wch) <= LOW_SURROGATE_END))
'#define IS_SURROGATE_PAIR(hs, ls) (IS_HIGH_SURROGATE(hs) && IS_LOW_SURROGATE(ls))

MACRO IS_HIGH_SURROGATE(wch) = ((wch >= %HIGH_SURROGATE_START) AND (wch <= %HIGH_SURROGATE_END))
MACRO IS_LOW_SURROGATE(wch)  = ((wch >= %LOW_SURROGATE_START) AND (wch <= %LOW_SURROGATE_END))
MACRO IS_SURROGATE_PAIR(hs, ls) = (IS_HIGH_SURROGATE(hs) AND IS_LOW_SURROGATE(ls))

'// ----------------------------------------------------------------------
'// The following macros retrieve information from a MUIFILEINFO structure
'//
'// Gets the culture name (LPWSTR), NULL if not initialized
'#define FILEMUIINFO_GET_CULTURE(pInfo)          \
'    ((LPWSTR)((pInfo->dwLanguageNameOffset>0)?(ULONG_PTR)pInfo+pInfo->dwLanguageNameOffset:NULL))
'//
'// Gets the main module types array (DWORD[]), NULL if not initialized
'#define FILEMUIINFO_GET_MAIN_TYPEIDS(pInfo)       \
'    ((DWORD*)((pInfo->dwTypeIDMainOffset>0)?(ULONG_PTR)pInfo+pInfo->dwTypeIDMainOffset:NULL))
'//
'// Gets the main module type array element iType (DWORD), the array is not initialized or index is out of bounds
'#define FILEMUIINFO_GET_MAIN_TYPEID(pInfo,iType)  \
'    (((iType<pInfo->dwTypeIDMainSize)&&(pInfo->dwTypeIDMainOffset>0))?*((DWORD*)((ULONG_PTR)pInfo+pInfo->dwTypeIDMainOffset)+iType):0)
'//
'// Gets the main module names multistring array (LPWSTR), NULL if not initialized
'#define FILEMUIINFO_GET_MAIN_TYPENAMES(pInfo)       \
'    ((LPWSTR)((pInfo->dwTypeNameMainOffset>0)?(ULONG_PTR)pInfo+pInfo->dwTypeNameMainOffset:NULL))
'//
'// Gets the mui module types array (DWORD[]), NULL if not initialized
'#define FILEMUIINFO_GET_MUI_TYPEIDS(pInfo)        \
'    ((DWORD*)((pInfo->dwTypeIDMUIOffset>0)?(ULONG_PTR)pInfo+pInfo->dwTypeIDMUIOffset:NULL))
'//
'// Gets the mui module type array element iType (DWORD), the array is not initialized or index is out of bounds
'#define FILEMUIINFO_GET_MUI_TYPEID(pInfo,iType)   \
'    (((iType<pInfo->dwTypeIDMUISize)&&(pInfo->dwTypeIDMUIOffset>0))?*((DWORD*)((ULONG_PTR)pInfo+pInfo->dwTypeIDMUIOffset)+iType):0)
'//
'// Gets the mui module names multistring array (LPWSTR), NULL if not initialized
'#define FILEMUIINFO_GET_MUI_TYPENAMES(pInfo)        \
'    ((LPWSTR)((pInfo->dwTypeNameMUIOffset>0)?(ULONG_PTR)pInfo+pInfo->dwTypeNameMUIOffset:NULL))
'// ------------------------------------------------------------------------

'////////////////////////////////////////////////////////////////////////////
'//
'//  Function Prototypes
'//
'//  Only prototypes for the NLS APIs should go here.
'//
'////////////////////////////////////////////////////////////////////////////

'//
'//  Code Page Dependent APIs.
'//

DECLARE FUNCTION IsValidCodePage IMPORT "KERNEL32.DLL" ALIAS "IsValidCodePage" ( _
   BYVAL CodePage AS DWORD _                            ' __in UINT  CodePage
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetACP IMPORT "KERNEL32.DLL" ALIAS "GetACP" ( _
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetOEMCP IMPORT "KERNEL32.DLL" ALIAS "GetOEMCP" ( _
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetCPInfo IMPORT "KERNEL32.DLL" ALIAS "GetCPInfo" ( _
   BYVAL CodePage AS DWORD _                            ' __in UINT       CodePage
 , BYREF lpCPInfo AS CPINFO _                           ' __out LPCPINFO  lpCPInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetCPInfoExA IMPORT "KERNEL32.DLL" ALIAS "GetCPInfoExA" ( _
   BYVAL CodePage AS DWORD _                            ' __in UINT          CodePage
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD         dwFlags
 , BYREF lpCPInfoEx AS CPINFOEXA _                      ' __out LPCPINFOEXA  lpCPInfoEx
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetCPInfoExW IMPORT "KERNEL32.DLL" ALIAS "GetCPInfoExW" ( _
   BYVAL CodePage AS DWORD _                            ' __in UINT          CodePage
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD         dwFlags
 , BYREF lpCPInfoEx AS CPINFOEXW _                      ' __out LPCPINFOEXW  lpCPInfoEx
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetCPInfoEx = GetCPInfoExW
#ELSE
   MACRO GetCPInfoEx = GetCPInfoExA
#ENDIF

DECLARE FUNCTION IsDBCSLeadByte IMPORT "KERNEL32.DLL" ALIAS "IsDBCSLeadByte" ( _
   BYVAL TestChar AS BYTE _                             ' __in BYTE  TestChar
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsDBCSLeadByteEx IMPORT "KERNEL32.DLL" ALIAS "IsDBCSLeadByteEx" ( _
   BYVAL CodePage AS DWORD _                            ' __in UINT  CodePage
 , BYVAL TestChar AS BYTE _                             ' __in BYTE  TestChar
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MultiByteToWideChar IMPORT "KERNEL32.DLL" ALIAS "MultiByteToWideChar" ( _
   BYVAL CodePage AS DWORD _                            ' __in  UINT     CodePage
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD    dwFlags
 , BYREF lpMultiByteStr AS ASCIIZ _                     ' __in  LPCSTR   lpMultiByteStr
 , BYVAL cbMultiByte AS LONG _                          ' __in  int      cbMultiByte
 , BYREF lpWideCharStr AS WSTRINGZ _                    ' __out LPWSTR   lpWideCharStr
 , BYVAL cchWideChar AS LONG _                          ' __in  int      cchWideChar
 ) AS LONG                                              ' int

DECLARE FUNCTION WideCharToMultiByte IMPORT "KERNEL32.DLL" ALIAS "WideCharToMultiByte" ( _
   BYVAL CodePage AS DWORD _                            ' __in UINT         CodePage
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD        dwFlags
 , BYREF lpWideCharStr AS WSTRINGZ _                    ' __in_opt LPCWSTR  lpWideCharStr
 , BYVAL cchWideChar AS LONG _                          ' __in int          cchWideChar
 , BYREF lpMultiByteStr AS ASCIIZ _                     ' __out LPSTR       lpMultiByteStr
 , BYVAL cbMultiByte AS LONG _                          ' __in int          cbMultiByte
 , OPTIONAL BYREF lpDefaultChar AS ASCIIZ _             ' __in_opt LPCSTR   lpDefaultChar
 , OPTIONAL BYREF lpUsedDefaultChar AS LONG _           ' __out_opt LPBOOL  lpUsedDefaultChar
 ) AS LONG                                              ' int

'//
'//  Locale Dependent APIs.
'//

'// For Windows Vista and above CompareStringEx is preferred
DECLARE FUNCTION CompareStringA IMPORT "KERNEL32.DLL" ALIAS "CompareStringA" ( _
   BYVAL Locale AS DWORD _                              ' __in LCID     Locale
 , BYVAL dwCmpFlags AS DWORD _                          ' __in DWORD    dwCmpFlags
 , BYREF lpString1 AS ASCIIZ _                          ' __in PCNZCH   lpString1
 , BYVAL cchCount1 AS LONG _                            ' __in int      cchCount1
 , BYREF lpString2 AS ASCIIZ _                          ' __in PCNZCH   lpString2
 , BYVAL cchCount2 AS LONG _                            ' __in int      cchCount2
 ) AS LONG                                              ' int

DECLARE FUNCTION CompareStringW IMPORT "KERNEL32.DLL" ALIAS "CompareStringW" ( _
   BYVAL Locale AS DWORD _                              ' __in LCID     Locale
 , BYVAL dwCmpFlags AS DWORD _                          ' __in DWORD    dwCmpFlags
 , BYREF lpString1 AS WSTRINGZ _                        ' __in PCNZWCH  lpString1
 , BYVAL cchCount1 AS LONG _                            ' __in int      cchCount1
 , BYREF lpString2 AS WSTRINGZ _                        ' __in PCNZWCH  lpString2
 , BYVAL cchCount2 AS LONG _                            ' __in int      cchCount2
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO CompareString = CompareStringW
#ELSE
   MACRO CompareString = CompareStringA
#ENDIF

'#if (WINVER >= 0x0600)
'// For Windows Vista and above FindNLSStringEx is preferred
DECLARE FUNCTION FindNLSString IMPORT "KERNEL32.DLL" ALIAS "FindNLSString" ( _
   BYVAL Locale AS DWORD _                              ' __in      LCID    Locale
 , BYVAL dwFindNLSStringFlags AS DWORD _                ' __in      DWORD   dwFindNLSStringFlags
 , BYREF lpStringSource AS WSTRINGZ _                   ' __in      LPCWSTR lpStringSource
 , BYVAL cchSource AS LONG _                            ' __in      int     cchSource
 , BYREF lpStringValue AS WSTRINGZ _                    ' __in      LPCWSTR lpStringValue
 , BYVAL cchValue AS LONG _                             ' __in      int     cchValue
 , OPTIONAL BYREF pcchFound AS LONG _                   ' __out_opt LPINT   pcchFound
 ) AS LONG                                              ' int
'#endif //(WINVER >= 0x0600)

'#if (WINVER >= _WIN32_WINNT_WIN7)
DECLARE FUNCTION FindStringOrdinal IMPORT "KERNEL32.DLL" ALIAS "FindStringOrdinal" ( _
   BYVAL dwFindStringOrdinalFlags AS DWORD _            ' __in DWORD dwFindStringOrdinalFlags
 , BYREF lpStringSource AS WSTRINGZ _                   ' __in LPCWSTR lpStringSource
 , BYVAL cchSource AS LONG _                            ' __in int cchSource
 , BYREF lpStringValue AS WSTRINGZ _                    ' __in LPCWSTR lpStringValue
 , BYVAL cchValue AS LONG _                             ' __in int cchValue
 , BYVAL bIgnoreCase AS LONG _                          ' __in BOOL bIgnoreCase
 ) AS LONG                                              ' int
'#endif //(WINVER >= _WIN32_WINNT_WIN7)

'// For Windows Vista and above LCMapStringEx is preferred
DECLARE FUNCTION LCMapStringA IMPORT "KERNEL32.DLL" ALIAS "LCMapStringA" ( _
   BYVAL Locale AS DWORD _                              ' __in  LCID    Locale
 , BYVAL dwMapFlags AS DWORD _                          ' __in  DWORD   dwMapFlags
 , BYREF lpSrcStr AS ASCIIZ _                           ' __in  LPCSTR  lpSrcStr
 , BYVAL cchSrc AS LONG _                               ' __in  int     cchSrc
 , BYREF lpDestStr AS ASCIIZ _                          ' __out LPSTR   lpDestStr
 , BYVAL cchDest AS LONG _                              ' __in  int     cchDest
 ) AS LONG                                              ' int

'// For Windows Vista and above LCMapStringEx is preferred
DECLARE FUNCTION LCMapStringW IMPORT "KERNEL32.DLL" ALIAS "LCMapStringW" ( _
   BYVAL Locale AS DWORD _                              ' __in  LCID     Locale
 , BYVAL dwMapFlags AS DWORD _                          ' __in  DWORD    dwMapFlags
 , BYREF lpSrcStr AS WSTRINGZ _                         ' __in  LPCWSTR  lpSrcStr
 , BYVAL cchSrc AS LONG _                               ' __in  int      cchSrc
 , BYREF lpDestStr AS WSTRINGZ _                        ' __out LPWSTR   lpDestStr
 , BYVAL cchDest AS LONG _                              ' __in  int      cchDest
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO LCMapString = LCMapStringW
#ELSE
   MACRO LCMapString = LCMapStringA
#ENDIF

' // For Windows Vista and above GetLocaleInfoEx is preferred
' // Note: The lpLCData has been declared as ANY because this parameter can be used for
' // numbers if LOCALE_RETURN_NUMBER is used in LCType.
DECLARE FUNCTION GetLocaleInfoA IMPORT "KERNEL32.DLL" ALIAS "GetLocaleInfoA" ( _
   BYVAL Locale AS DWORD _                              ' __in  LCID     Locale
 , BYVAL LCType AS DWORD _                              ' __in  LCTYPE   LCType
 , BYREF lpLCData AS ASCIIZ _                           ' __out LPSTR    lpLCData
 , BYVAL cchData AS LONG _                              ' __in  int      cchData
 ) AS LONG                                              ' int

' // For Windows Vista and above GetLocaleInfoEx is preferred
' // Note: The lpLCData has been declared as ANY because this parameter can be used for
' // numbers if LOCALE_RETURN_NUMBER is used in LCType.
DECLARE FUNCTION GetLocaleInfoW IMPORT "KERNEL32.DLL" ALIAS "GetLocaleInfoW" ( _
   BYVAL Locale AS DWORD _                              ' __in  LCID     Locale
 , BYVAL LCType AS DWORD _                              ' __in  LCTYPE   LCType
 , BYREF lpLCData AS WSTRINGZ _                         ' __out LPWSTR   lpLCData
 , BYVAL cchData AS LONG _                              ' __in  int      cchData
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO GetLocaleInfo = GetLocaleInfoW
#ELSE
   MACRO GetLocaleInfo = GetLocaleInfoA
#ENDIF

DECLARE FUNCTION SetLocaleInfoA IMPORT "KERNEL32.DLL" ALIAS "SetLocaleInfoA" ( _
   BYVAL Locale AS DWORD _                              ' __in LCID     Locale
 , BYVAL LCType AS DWORD _                              ' __in LCTYPE   LCType
 , BYREF lpLCData AS ASCIIZ _                           ' __in LPCSTR   lpLCData
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetLocaleInfoW IMPORT "KERNEL32.DLL" ALIAS "SetLocaleInfoW" ( _
   BYVAL Locale AS DWORD _                              ' __in LCID     Locale
 , BYVAL LCType AS DWORD _                              ' __in LCTYPE   LCType
 , BYREF lpLCData AS WSTRINGZ _                         ' __in LPCWSTR  lpLCData
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetLocaleInfo = SetLocaleInfoW
#ELSE
   MACRO SetLocaleInfo = SetLocaleInfoA
#ENDIF

'#if (WINVER >= 0x040A)

'// For Windows Vista and above GetCalendarInfoEx is preferred
DECLARE FUNCTION GetCalendarInfoA IMPORT "KERNEL32.DLL" ALIAS "GetCalendarInfoA" ( _
   BYVAL Locale AS DWORD _                              ' __in     LCID     Locale
 , BYVAL Calendar AS DWORD _                            ' __in     CALID    Calendar
 , BYVAL CalType AS DWORD _                             ' __in     CALTYPE  CalType
 , BYREF lpCalData AS ASCIIZ  _                         ' __out    LPSTR    lpCalData
 , BYVAL cchData AS LONG _                              ' __in     int      cchData
 , OPTIONAL BYREF lpValue AS DWORD _                    ' __in_opt LPDWORD  lpValue
 ) AS LONG                                              ' int

'// For Windows Vista and above GetCalendarInfoEx is preferred
DECLARE FUNCTION GetCalendarInfoW IMPORT "KERNEL32.DLL" ALIAS "GetCalendarInfoW" ( _
   BYVAL Locale AS DWORD _                              ' __in     LCID     Locale
 , BYVAL Calendar AS DWORD _                            ' __in     CALID    Calendar
 , BYVAL CalType AS DWORD _                             ' __in     CALTYPE  CalType
 , BYREF lpCalData AS WSTRINGZ _                        ' __out    LPWSTR   lpCalData
 , BYVAL cchData AS LONG _                              ' __in     int      cchData
 , OPTIONAL BYREF lpValue AS DWORD _                    ' __in_opt LPDWORD  lpValue
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO GetCalendarInfo = GetCalendarInfoW
#ELSE
   MACRO GetCalendarInfo = GetCalendarInfoA
#ENDIF

DECLARE FUNCTION SetCalendarInfoA IMPORT "KERNEL32.DLL" ALIAS "SetCalendarInfoA" ( _
   BYVAL Locale AS DWORD _                              ' __in LCID     Locale
 , BYVAL Calendar AS DWORD _                            ' __in CALID    Calendar
 , BYVAL CalType AS DWORD _                             ' __in CALTYPE  CalType
 , BYREF lpCalData AS ASCIIZ _                          ' __in LPCSTR   lpCalData
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetCalendarInfoW IMPORT "KERNEL32.DLL" ALIAS "SetCalendarInfoW" ( _
   BYVAL Locale AS DWORD _                              ' __in LCID     Locale
 , BYVAL Calendar AS DWORD _                            ' __in CALID    Calendar
 , BYVAL CalType AS DWORD _                             ' __in CALTYPE  CalType
 , BYREF lpCalData AS WSTRINGZ _                        ' __in LPCWSTR  lpCalData
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetCalendarInfo = SetCalendarInfoW
#ELSE
   MACRO SetCalendarInfo = SetCalendarInfoA
#ENDIF

'#if (WINVER >= 0x0600)
DECLARE FUNCTION LCIDToLocaleName IMPORT "KERNEL32.DLL" ALIAS "LCIDToLocaleName" ( _
   BYVAL Locale AS DWORD _                              ' __in  LCID    Locale
 , BYREF lpName AS WSTRINGZ _                           ' __out LPWSTR  lpName
 , BYVAL cchName AS LONG _                              ' __in  int     cchName
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD   dwFlags
 ) AS LONG                                              ' int

DECLARE FUNCTION LocaleNameToLCID IMPORT "KERNEL32.DLL" ALIAS "LCIDToLocaleName" ( _
   BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' LCID
'#endif  // (WINVER >= 0x0600)

'// For Windows Vista and above GetTimeFormatEx is preferred
DECLARE FUNCTION GetTimeFormatA IMPORT "KERNEL32.DLL" ALIAS "GetTimeFormatA" ( _
   BYVAL Locale AS DWORD _                              ' __in     LCID             Locale
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD            dwFlags
 , BYREF lpTime AS SYSTEMTIME _                         ' __in_opt CONST SYSTEMTIME *lpTime
 , BYREF lpFormat AS ASCIIZ _                           ' __in_opt LPCSTR           lpFormat
 , BYREF lpTimeStr AS ASCIIZ _                          ' __out    LPSTR            lpTimeStr
 , BYVAL cchTime AS LONG _                              ' __in     int              cchTime
 ) AS LONG                                              ' int

'// For Windows Vista and above GetTimeFormatEx is preferred
DECLARE FUNCTION GetTimeFormatW IMPORT "KERNEL32.DLL" ALIAS "GetTimeFormatW" ( _
   BYVAL Locale AS DWORD _                              ' __in     LCID             Locale
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD            dwFlags
 , BYREF lpTime AS SYSTEMTIME _                         ' __in_opt CONST SYSTEMTIME *lpTime
 , BYREF lpFormat AS WSTRINGZ _                         ' __in_opt LPCWSTR          lpFormat
 , BYREF lpTimeStr AS WSTRINGZ _                        ' __out    LPWSTR           lpTimeStr
 , BYVAL cchTime AS LONG _                              ' __in     int              cchTime
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO GetTimeFormat = GetTimeFormatW
#ELSE
   MACRO GetTimeFormat = GetTimeFormatA
#ENDIF

'#if (WINVER >= 0x0600)
'// For Windows Vista and above GetDurationFormatEx is preferred
DECLARE FUNCTION GetDurationFormat IMPORT "KERNEL32.DLL" ALIAS "GetDurationFormat" ( _
   BYVAL Locale AS DWORD _                              ' __in LCID                  Locale
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD                 dwFlags
 , BYREF lpDuration AS SYSTEMTIME _                     ' __in_opt CONST SYSTEMTIME *lpDuration
 , BYVAL ullDuration AS QUAD _                          ' __in ULONGLONG             ullDuration
 , BYREF lpFormat AS WSTRINGZ _                         ' __in_opt LPCWSTR           lpFormat
 , BYREF lpDurationStr AS WSTRINGZ _                    ' __out LPWSTR               lpDurationStr
 , BYVAL cchDuration AS LONG _                          ' __in int                   cchDuration
 ) AS LONG                                              ' int
'#endif //(WINVER >= 0x0600)

'// For Windows Vista and above GetDateFormatEx is preferred
DECLARE FUNCTION GetDateFormatA IMPORT "KERNEL32.DLL" ALIAS "GetDateFormatA" ( _
   BYVAL Locale AS DWORD _                              ' __in     LCID             Locale
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD            dwFlags
 , BYREF lpDate AS SYSTEMTIME _                         ' __in_opt CONST SYSTEMTIME *lpDate
 , BYREF lpFormat AS ASCIIZ _                           ' __in_opt LPCSTR           lpFormat
 , BYREF lpDateStr AS ASCIIZ _                          ' __out    LPSTR            lpDateStr
 , BYVAL cchDate AS LONG _                              ' __in     int              cchDate
 ) AS LONG                                              ' int

'// For Windows Vista and above GetDateFormatEx is preferred
DECLARE FUNCTION GetDateFormatW IMPORT "KERNEL32.DLL" ALIAS "GetDateFormatW" ( _
   BYVAL Locale AS DWORD _                              ' __in     LCID             Locale
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD            dwFlags
 , BYREF lpDate AS SYSTEMTIME _                         ' __in_opt CONST SYSTEMTIME *lpDate
 , BYREF lpFormat AS WSTRINGZ _                         ' __in_opt LPCWSTR          lpFormat
 , BYREF lpDateStr AS WSTRINGZ _                        ' __out    LPWSTR           lpDateStr
 , BYVAL cchDate AS LONG _                              ' __in     int              cchDate
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO GetDateFormat = GetDateFormatW
#ELSE
   MACRO GetDateFormat = GetDateFormatA
#ENDIF

'// For Windows Vista and above GetNumberFormatEx is preferred
DECLARE FUNCTION GetNumberFormatA IMPORT "KERNEL32.DLL" ALIAS "GetNumberFormatA" ( _
   BYVAL Locale AS DWORD _                              ' __in      LCID             Locale
 , BYVAL dwFlags AS DWORD _                             ' __in      DWORD            dwFlags
 , BYREF lpValue AS ASCIIZ _                            ' __in      LPCSTR           lpValue
 , BYREF lpFormat AS NUMBERFMTA _                       ' __in_opt  CONST NUMBERFMTA *lpFormat
 , BYREF lpNumberStr AS ASCIIZ _                        ' __out_opt LPSTR            lpNumberStr
 , BYVAL cchNumber AS LONG _                            ' __in      int              cchNumber
 ) AS LONG                                              ' int

'// For Windows Vista and above GetNumberFormatEx is preferred
DECLARE FUNCTION GetNumberFormatW IMPORT "KERNEL32.DLL" ALIAS "GetNumberFormatW" ( _
   BYVAL Locale AS DWORD _                              ' __in      LCID             Locale
 , BYVAL dwFlags AS DWORD _                             ' __in      DWORD            dwFlags
 , BYREF lpValue AS WSTRINGZ _                          ' __in      LPCWSTR          lpValue
 , BYREF lpFormat AS NUMBERFMTW _                       ' __in_opt  CONST NUMBERFMTW *lpFormat
 , BYREF lpNumberStr AS WSTRINGZ _                      ' __out_opt LPWSTR           lpNumberStr
 , BYVAL cchNumber AS LONG _                            ' __in      int              cchNumber
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO GetNumberFormat = GetNumberFormatW
#ELSE
   MACRO GetNumberFormat = GetNumberFormatA
#ENDIF

'// For Windows Vista and above GetCurrencyFormatEx is preferred
DECLARE FUNCTION GetCurrencyFormatA IMPORT "KERNEL32.DLL" ALIAS "GetCurrencyFormatA" ( _
   BYVAL Locale AS DWORD _                              ' __in  LCID                    Locale
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD                   dwFlags
 , BYREF lpValue AS ASCIIZ _                            ' __in  LPCSTR                  lpValue
 , BYREF lpFormat AS CURRENCYFMTA _                     ' __in_ opt CONST CURRENCYFMTA *lpFormat
 , BYREF lpCurrencyStr AS ASCIIZ _                      ' __out LPSTR                   lpCurrencyStr
 , BYVAL cchCurrency AS LONG _                          ' __in  int                     cchCurrency
 ) AS LONG                                              ' int

'// For Windows Vista and above GetCurrencyFormatEx is preferred
DECLARE FUNCTION GetCurrencyFormatW IMPORT "KERNEL32.DLL" ALIAS "GetCurrencyFormatW" ( _
   BYVAL Locale AS DWORD _                              ' __in      LCID               Locale
 , BYVAL dwFlags AS DWORD _                             ' __in      DWORD              dwFlags
 , BYREF lpValue AS WSTRINGZ _                          ' __in      LPCWSTR            lpValue
 , BYREF lpFormat AS CURRENCYFMTW _                     ' __in_opt  CONST CURRENCYFMTW *lpFormat
 , BYREF lpCurrencyStr AS WSTRINGZ _                    ' __out_opt LPWSTR             lpCurrencyStr
 , BYVAL cchCurrency AS LONG _                          ' __in      int                cchCurrency
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO GetCurrencyFormat = GetCurrencyFormatW
#ELSE
   MACRO GetCurrencyFormat = GetCurrencyFormatA
#ENDIF

'// For Windows Vista and above EnumCalendarInfoExEx is preferred
DECLARE FUNCTION EnumCalendarInfoA IMPORT "KERNEL32.DLL" ALIAS "EnumCalendarInfoA" ( _
   BYVAL lpCalInfoEnumProc AS DWORD _                   ' __in CALINFO_ENUMPROCA lpCalInfoEnumProc
 , BYVAL Locale AS DWORD _                              ' __in LCID              Locale
 , BYVAL Calendar AS DWORD _                            ' __in CALID             Calendar
 , BYVAL CalType AS DWORD _                             ' __in CALTYPE           CalType
 ) AS LONG                                              ' BOOL

'// For Windows Vista and above EnumCalendarInfoExEx is preferred
DECLARE FUNCTION EnumCalendarInfoW IMPORT "KERNEL32.DLL" ALIAS "EnumCalendarInfoW" ( _
   BYVAL lpCalInfoEnumProc AS DWORD _                   ' __in CALINFO_ENUMPROCW lpCalInfoEnumProc
 , BYVAL Locale AS DWORD _                              ' __in LCID              Locale
 , BYVAL Calendar AS DWORD _                            ' __in CALID             Calendar
 , BYVAL CalType AS DWORD _                             ' __in CALTYPE           CalType
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EnumCalendarInfo = EnumCalendarInfoW
#ELSE
   MACRO EnumCalendarInfo = EnumCalendarInfoA
#ENDIF

'#if(WINVER >= 0x0500)
'// For Windows Vista and above EnumCalendarInfoExEx is preferred
DECLARE FUNCTION EnumCalendarInfoExA IMPORT "KERNEL32.DLL" ALIAS "EnumCalendarInfoExA" ( _
   BYVAL lpCalInfoEnumProcEx AS DWORD _                 ' __in CALINFO_ENUMPROCEXA lpCalInfoEnumProcEx
 , BYVAL Locale AS DWORD _                              ' __in LCID                Locale
 , BYVAL Calendar AS DWORD _                            ' __in CALID               Calendar
 , BYVAL CalType AS DWORD _                             ' __in CALTYPE             CalType
 ) AS LONG                                              ' BOOL

'// For Windows Vista and above EnumCalendarInfoExEx is preferred
DECLARE FUNCTION EnumCalendarInfoExW IMPORT "KERNEL32.DLL" ALIAS "EnumCalendarInfoExW" ( _
   BYVAL lpCalInfoEnumProcEx AS DWORD _                 ' __in CALINFO_ENUMPROCEXW lpCalInfoEnumProcEx
 , BYVAL Locale AS DWORD _                              ' __in LCID                Locale
 , BYVAL Calendar AS DWORD _                            ' __in CALID               Calendar
 , BYVAL CalType AS DWORD _                             ' __in CALTYPE             CalType
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EnumCalendarInfoEx = EnumCalendarInfoExW
#ELSE
   MACRO EnumCalendarInfoEx = EnumCalendarInfoExA
#ENDIF
'#endif /* WINVER >= 0x0500 */

'// For Windows Vista and above EnumTimeFormatsEx is preferred
DECLARE FUNCTION EnumTimeFormatsA IMPORT "KERNEL32.DLL" ALIAS "EnumTimeFormatsA" ( _
   BYVAL lpTimeFmtEnumProc AS DWORD _                   ' __in TIMEFMT_ENUMPROCA lpTimeFmtEnumProc
 , BYVAL Locale AS DWORD _                              ' __in LCID              Locale
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD             dwFlags
 ) AS LONG                                              ' BOOL

'// For Windows Vista and above EnumTimeFormatsEx is preferred
DECLARE FUNCTION EnumTimeFormatsW IMPORT "KERNEL32.DLL" ALIAS "EnumTimeFormatsW" ( _
   BYVAL lpTimeFmtEnumProc AS DWORD _                   ' __in TIMEFMT_ENUMPROCW lpTimeFmtEnumProc
 , BYVAL Locale AS DWORD _                              ' __in LCID              Locale
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD             dwFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EnumTimeFormats = EnumTimeFormatsW
#ELSE
   MACRO EnumTimeFormats = EnumTimeFormatsA
#ENDIF

'// For Windows Vista and above EnumDateFormatsExEx is preferred
DECLARE FUNCTION EnumDateFormatsA IMPORT "KERNEL32.DLL" ALIAS "EnumDateFormatsA" ( _
   BYVAL lpDateFmtEnumProc AS DWORD _                   ' __in DATEFMT_ENUMPROCA lpDateFmtEnumProc
 , BYVAL Locale AS DWORD _                              ' __in LCID              Locale
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD             dwFlags
 ) AS LONG                                              ' BOOL

'// For Windows Vista and above EnumDateFormatsExEx is preferred
DECLARE FUNCTION EnumDateFormatsW IMPORT "KERNEL32.DLL" ALIAS "EnumDateFormatsW" ( _
   BYVAL lpDateFmtEnumProc AS DWORD _                   ' __in DATEFMT_ENUMPROCW lpDateFmtEnumProc
 , BYVAL Locale AS DWORD _                              ' __in LCID              Locale
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD             dwFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EnumDateFormats = EnumDateFormatsW
#ELSE
   MACRO EnumDateFormats = EnumDateFormatsA
#ENDIF

'#if(WINVER >= 0x0500)
'// For Windows Vista and above EnumDateFormatsExEx is preferred
DECLARE FUNCTION EnumDateFormatsExA IMPORT "KERNEL32.DLL" ALIAS "EnumDateFormatsExA" ( _
   BYVAL lpDateFmtEnumProcEx AS DWORD _                 ' __in DATEFMT_ENUMPROCEXA lpDateFmtEnumProcEx
 , BYVAL Locale AS DWORD _                              ' __in LCID                Locale
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD               dwFlags
 ) AS LONG                                              ' BOOL

'// For Windows Vista and above EnumDateFormatsExEx is preferred
DECLARE FUNCTION EnumDateFormatsExW IMPORT "KERNEL32.DLL" ALIAS "EnumDateFormatsExW" ( _
   BYVAL lpDateFmtEnumProcEx AS DWORD _                 ' __in DATEFMT_ENUMPROCEXW lpDateFmtEnumProcEx
 , BYVAL Locale AS DWORD _                              ' __in LCID                Locale
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD               dwFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EnumDateFormatsEx = EnumDateFormatsExW
#ELSE
   MACRO EnumDateFormatsEx = EnumDateFormatsExA
#ENDIF
'#endif /* WINVER >= 0x0500 */

'#if(WINVER >= 0x0500)
DECLARE FUNCTION IsValidLanguageGroup IMPORT "KERNEL32.DLL" ALIAS "IsValidLanguageGroup" ( _
   BYVAL LanguageGroup AS DWORD _                       ' __in LGRPID  LanguageGroup
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD   dwFlags
 ) AS LONG                                              ' BOOL
'#endif /* WINVER >= 0x0500 */

'// For Windows Vista and above GetNLSVersionEx is preferred
DECLARE FUNCTION GetNLSVersion IMPORT "KERNEL32.DLL" ALIAS "GetNLSVersion" ( _
   BYVAL Function AS DWORD _                            ' __in NLS_FUNCTION         Function
 , BYVAL Locale AS DWORD _                              ' __in LCID                 Locale
 , BYREF lpVersionInformation AS NLSVERSIONINFO _       ' __in_out LPNLSVERSIONINFO lpVersionInformation
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsNLSDefinedString IMPORT "KERNEL32.DLL" ALIAS "IsNLSDefinedString" ( _
   BYVAL Function AS DWORD _                            ' __in NLS_FUNCTION     Function
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD            dwFlags
 , BYREF lpVersionInformation AS NLSVERSIONINFO _       ' __in LPNLSVERSIONINFO lpVersionInformation
 , BYREF lpString AS WSTRINGZ _                         ' __in LPCWSTR          lpString
 , BYVAL cchStr AS LONG _                               ' __in INT              cchStr
 ) AS LONG                                              ' BOOL

'// For Windows Vista and above IsValidLocaleName is preferred
DECLARE FUNCTION IsValidLocale IMPORT "KERNEL32.DLL" ALIAS "IsValidLocale" ( _
   BYVAL Locale AS DWORD _                              ' __in LCID   Locale
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD  dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetGeoInfoA IMPORT "KERNEL32.DLL" ALIAS "GetGeoInfoA" ( _
   BYVAL Location AS LONG _                             ' __in  GEOID       Location
 , BYVAL GeoType AS DWORD _                             ' __in  GEOTYPE     GeoType
 , BYREF lpGeoData AS ASCIIZ _                          ' __out LPSTR       lpGeoData
 , BYVAL cchData AS LONG _                              ' __in  int         cchData
 , BYVAL LangId AS WORD _                               ' __in  LANGID      LangId
 ) AS LONG                                              ' int

DECLARE FUNCTION GetGeoInfoW IMPORT "KERNEL32.DLL" ALIAS "GetGeoInfoW" ( _
   BYVAL Location AS LONG _                             ' __in      GEOID   Location
 , BYVAL GeoType AS DWORD _                             ' __in      GEOTYPE GeoType
 , BYREF lpGeoData AS WSTRINGZ _                        ' __out_opt LPWSTR  lpGeoData
 , BYVAL cchData AS LONG _                              ' __in      int     cchData
 , BYVAL LangId AS WORD _                               ' __in      LANGID  LangId
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO GetGeoInfo = GetGeoInfoW
#ELSE
   MACRO GetGeoInfo = GetGeoInfoA
#ENDIF

DECLARE FUNCTION EnumSystemGeoID IMPORT "KERNEL32.DLL" ALIAS "EnumSystemGeoID" ( _
   BYVAL GeoClass AS DWORD _                            ' __in GEOCLASS        GeoClass
 , BYVAL ParentGeoId AS LONG _                          ' __in GEOID           ParentGeoId
 , BYVAL lpGeoEnumProc AS DWORD _                       ' __in GEO_ENUMPROC    lpGeoEnumProc
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetUserGeoID IMPORT "KERNEL32.DLL" ALIAS "GetUserGeoID" ( _
   BYVAL GeoClass AS DWORD _                            ' __in GEOCLASS    GeoClass
 ) AS LONG                                              ' GEOID

DECLARE FUNCTION SetUserGeoID IMPORT "KERNEL32.DLL" ALIAS "SetUserGeoID" ( _
   BYVAL GeoId AS LONG _                                ' __in GEOID       GeoId
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ConvertDefaultLocale IMPORT "KERNEL32.DLL" ALIAS "ConvertDefaultLocale" ( _
   BYVAL Locale AS DWORD _                              ' __in LCID   Locale
 ) AS DWORD                                             ' LCID

DECLARE FUNCTION GetThreadLocale IMPORT "KERNEL32.DLL" ALIAS "GetThreadLocale" ( _
 ) AS DWORD                                             ' LCID

DECLARE FUNCTION SetThreadLocale IMPORT "KERNEL32.DLL" ALIAS "SetThreadLocale" ( _
   BYVAL Locale AS DWORD _                              ' __in LCID  Locale
 ) AS LONG                                              ' BOOL

'#if(WINVER >= 0x0500)
DECLARE FUNCTION GetSystemDefaultUILanguage IMPORT "KERNEL32.DLL" ALIAS "GetSystemDefaultUILanguage" ( _
 ) AS WORD                                              ' LANGID

DECLARE FUNCTION GetUserDefaultUILanguage IMPORT "KERNEL32.DLL" ALIAS "GetUserDefaultUILanguage" ( _
 ) AS WORD                                              ' LANGID
'#endif /* WINVER >= 0x0500 */

DECLARE FUNCTION GetSystemDefaultLangID IMPORT "KERNEL32.DLL" ALIAS "GetSystemDefaultLangID" ( _
 ) AS WORD                                              ' LANGID

DECLARE FUNCTION GetUserDefaultLangID IMPORT "KERNEL32.DLL" ALIAS "GetUserDefaultLangID" ( _
 ) AS WORD                                              ' LANGID

DECLARE FUNCTION GetSystemDefaultLCID IMPORT "KERNEL32.DLL" ALIAS "GetSystemDefaultLCID" ( _
 ) AS DWORD                                             ' LCID

DECLARE FUNCTION GetUserDefaultLCID IMPORT "KERNEL32.DLL" ALIAS "GetUserDefaultLCID" ( _
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION SetThreadUILanguage IMPORT "KERNEL32.DLL" ALIAS "SetThreadUILanguage" ( _
   BYVAL WORD _                                         ' __in LANGID LangId
 ) AS WORD                                              ' LANGID

'#if (WINVER >= 0x0600)
DECLARE FUNCTION GetThreadUILanguage IMPORT "KERNEL32.DLL" ALIAS "GetThreadUILanguage" ( _
 ) AS WORD                                              ' LANGID

DECLARE FUNCTION GetProcessPreferredUILanguages IMPORT "KERNEL32.DLL" ALIAS "GetProcessPreferredUILanguages" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pulNumLanguages AS DWORD _                     ' __out PULONG pulNumLanguages
 , BYREF pwszLanguagesBuffer AS ANY _                   ' __out PZZWSTR pwszLanguagesBuffer
 , BYREF pcchLanguagesBuffer AS DWORD _                 ' __inout PULONG pcchLanguagesBuffer
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetProcessPreferredUILanguages IMPORT "KERNEL32.DLL" ALIAS "SetProcessPreferredUILanguages" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYREF pwszLanguagesBuffer AS ANY _          ' __in_opt PZZWSTR pwszLanguagesBuffer
 , OPTIONAL BYREF pulNumLanguages AS DWORD _            ' __out_opt PULONG pulNumLanguages
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetUserPreferredUILanguages IMPORT "KERNEL32.DLL" ALIAS "GetUserPreferredUILanguages" ( _
   BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
 , BYREF pulNumLanguages AS DWORD _                     ' __out PULONG pulNumLanguages
 , BYREF pcchLanguagesBuffer AS ANY _                   ' __out PZZWSTR pwszLanguagesBuffer
 , BYVAL pcchLanguagesBuffer AS DWORD _                 ' __in  PULONG pcchLanguagesBuffer
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetSystemPreferredUILanguages IMPORT "KERNEL32.DLL" ALIAS "GetSystemPreferredUILanguages" ( _
   BYVAL dwFlags AS DWORD _                             ' __in     DWORD dwFlags
 , BYREF pulNumLanguages AS DWORD _                     ' __out    PULONG pulNumLanguages
 , BYREF pcchLanguagesBuffer AS ANY _                   ' __out    PZZWSTR pwszLanguagesBuffer
 , BYVAL pcchLanguagesBuffer AS DWORD _                 ' __in_out PULONG pcchLanguagesBuffer
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetThreadPreferredUILanguages IMPORT "KERNEL32.DLL" ALIAS "GetThreadPreferredUILanguages" ( _
   BYVAL dwFlags AS DWORD _                             ' __in     DWORD dwFlags
 , BYREF pulNumLanguages AS DWORD _                     ' __out    PULONG pulNumLanguages
 , BYREF pwszLanguagesBuffer AS ANY _                   ' __out    PZZWSTR pwszLanguagesBuffer
 , BYVAL pcchLanguagesBuffer AS DWORD _                 ' __in_out PULONG pcchLanguagesBuffer
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetThreadPreferredUILanguages IMPORT "KERNEL32.DLL" ALIAS "SetThreadPreferredUILanguages" ( _
   BYVAL dwFlags AS DWORD _                             ' __in      DWORD  dwFlags
 , OPTIONAL BYREF pwszLanguagesBuffer AS ANY _          ' __in_opt  PCZZWSTR pwszLanguagesBuffer
 , OPTIONAL BYVAL pulNumLanguages AS DWORD _            ' __out_opt PULONG pulNumLanguages
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetFileMUIInfo IMPORT "KERNEL32.DLL" ALIAS "GetFileMUIInfo" ( _
   BYVAL dwFlags AS DWORD _                             ' __in     DWORD        dwFlags
 , BYREF pcwszFilePath AS WSTRINGZ _                    ' __in     PCWSTR       pcwszFilePath
 , BYREF pFileMUIInfo AS FILEMUIINFO _                  ' __in_out PFILEMUIINFO pFileMUIInfo
 , BYREF pcbFileMUIInfo AS DWORD _                      ' __in_out DWORD*       pcbFileMUIInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetFileMUIPath IMPORT "KERNEL32.DLL" ALIAS "GetFileMUIPath" ( _
   BYVAL dwFlags AS DWORD _                             ' __in     DWORD        dwFlags
 , BYREF pcwszFilePath AS WSTRINGZ _                    ' __in     PCWSTR       pcwszFilePath
 , BYREF pwszLanguage AS WSTRINGZ _                     ' __in_out PWSTR        pwszLanguage
 , BYREF pcchLanguage AS DWORD _                        ' __in_out PULONG       pcchLanguage
 , BYREF pwszFileMUIPath AS WSTRINGZ _                  ' __out    PWSTR        pwszFileMUIPath
 , BYREF pcchFileMUIPath AS DWORD _                     ' __in_out PULONG       pcchFileMUIPath
 , BYREF pululEnumerator AS QUAD _                      ' __in_out PULONGLONG   pululEnumerator
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetUILanguageInfo IMPORT "KERNEL32.DLL" ALIAS "GetUILanguageInfo" ( _
   BYVAL dwFlags AS DWORD _                             ' __in     DWORD  dwFlags
 , BYREF pwmszLanguage AS ANY _                         ' __in     PCZZWSTR pwmszLanguage
 , BYREF pwszFallbackLanguages AS ANY _                 ' __out    PZZWSTR  pwszFallbackLanguages
 , BYREF pcchFallbackLanguages AS DWORD _               ' __in_out PULONG pcchFallbackLanguages
 , BYREF pAttributes AS DWORD _                         ' __out    PDWORD pAttributes
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION NotifyUILanguageChange IMPORT "KERNEL32.DLL" ALIAS "NotifyUILanguageChange" ( _
   BYVAL dwFlags AS DWORD _                             ' __in      DWORD  dwFlags
 , BYREF pcwstrNewLanguage AS WSTRINGZ _                ' __in_opt  PCWSTR pcwstrNewLanguage
 , BYREF pcwstrPreviousLanguage AS WSTRINGZ _           ' __in_opt  PCWSTR pcwstrPreviousLanguage
 , BYVAL dwReserved AS DWORD _                          ' __in      DWORD dwReserved
 , OPTIONAL BYREF pdwStatusRtrn AS DWORD _              ' __out_opt PDWORD pdwStatusRtrn
 ) AS LONG                                              ' BOOL

'#endif

'//
'//  Locale Independent APIs.
'//

DECLARE FUNCTION GetStringTypeExA IMPORT "KERNEL32.DLL" ALIAS "GetStringTypeExA" ( _
   BYVAL Locale AS DWORD _                              ' __in LCID     Locale
 , BYVAL dwInfoType AS DWORD _                          ' __in DWORD    dwInfoType
 , BYREF lpSrcStr AS ASCIIZ  _                          ' __in LPCSTR   lpSrcStr
 , BYVAL cchSrc AS LONG _                               ' __in int      cchSrc
 , BYREF lpCharType AS WORD _                           ' __out LPWORD  lpCharType
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetStringTypeExW IMPORT "KERNEL32.DLL" ALIAS "GetStringTypeExW" ( _
   BYVAL Locale AS DWORD _                              ' __in LCID     Locale
 , BYVAL dwInfoType AS DWORD _                          ' __in DWORD    dwInfoType
 , BYREF lpSrcStr AS WSTRINGZ _                         ' __in LPCWSTR  lpSrcStr
 , BYVAL cchSrc AS LONG _                               ' __in int      cchSrc
 , BYREF lpCharType AS WORD _                           ' __out LPWORD  lpCharType
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetStringTypeEx = GetStringTypeExW
#ELSE
   MACRO GetStringTypeEx = GetStringTypeExA
#ENDIF

'//
'//  NOTE: The parameters for GetStringTypeA and GetStringTypeW are
'//        NOT the same.  The W version was shipped in NT 3.1.  The
'//        A version was then shipped in 16-bit OLE with the wrong
'//        parameters (ported from Win95).  To be compatible, we
'//        must break the relationship between the A and W versions
'//        of GetStringType.  There will be NO function call for the
'//        generic GetStringType.
'//
'//        GetStringTypeEx (above) should be used instead.
'//

DECLARE FUNCTION GetStringTypeA IMPORT "KERNEL32.DLL" ALIAS "GetStringTypeA" ( _
   BYVAL Locale AS DWORD _                              ' __in LCID     Locale
 , BYVAL dwInfoType AS DWORD _                          ' __in DWORD    dwInfoType
 , BYREF lpSrcStr AS ASCIIZ _                           ' __in LPCSTR   lpSrcStr
 , BYVAL cchSrc AS LONG _                               ' __in int      cchSrc
 , BYREF lpCharType AS WORD _                           ' __out LPWORD  lpCharType
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetStringTypeW IMPORT "KERNEL32.DLL" ALIAS "GetStringTypeW" ( _
   BYVAL dwInfoType AS DWORD _                          ' __in DWORD    dwInfoType
 , BYREF lpSrcStr AS WSTRINGZ _                         ' __in LPCWSTR  lpSrcStr
 , BYVAL cchSrc AS LONG _                               ' __in int      cchSrc
 , BYREF lpCharType AS WORD _                           ' __out LPWORD  lpCharType
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FoldStringA IMPORT "KERNEL32.DLL" ALIAS "FoldStringA" ( _
   BYVAL dwMapFlags AS DWORD _                          ' __in DWORD    dwMapFlags
 , BYREF lpSrcStr AS ASCIIZ _                           ' __in LPCSTR  lpSrcStr
 , BYVAL cchSrc AS LONG _                               ' __in int      cchSrc
 , BYREF lpDestStr AS ASCIIZ _                          ' __out_ecount_opt(cchDest) LPSTR  lpDestStr
 , BYVAL cchDest AS LONG _                              ' __in int      cchDest
 ) AS LONG                                              ' int

DECLARE FUNCTION FoldStringW IMPORT "KERNEL32.DLL" ALIAS "FoldStringW" ( _
   BYVAL dwMapFlags AS DWORD _                          ' __in  DWORD    dwMapFlags
 , BYREF lpSrcStr AS WSTRINGZ _                         ' __in  LPCWSTR  lpSrcStr
 , BYVAL cchSrc AS LONG _                               ' __in  int      cchSrc
 , BYREF lpDestStr AS WSTRINGZ _                        ' __out LPWSTR   lpDestStr
 , BYVAL cchDest AS LONG _                              ' __in  int      cchDest
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO FoldString = FoldStringW
#ELSE
   MACRO FoldString = FoldStringA
#ENDIF

'#if(WINVER >= 0x0500)

DECLARE FUNCTION EnumSystemLanguageGroupsA IMPORT "KERNEL32.DLL" ALIAS "EnumSystemLanguageGroupsA" ( _
   BYVAL lpLanguageGroupEnumProc AS DWORD _             ' __in LANGUAGEGROUP_ENUMPROCA lpLanguageGroupEnumProc
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD                   dwFlags
 , BYVAL lParam AS LONG _                               ' __in LONG_PTR                lParam
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumSystemLanguageGroupsW IMPORT "KERNEL32.DLL" ALIAS "EnumSystemLanguageGroupsW" ( _
   BYVAL lpLanguageGroupEnumProc AS DWORD _             ' __in LANGUAGEGROUP_ENUMPROCW lpLanguageGroupEnumProc
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD                   dwFlags
 , BYVAL lParam AS LONG _                               ' __in LONG_PTR                lParam
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EnumSystemLanguageGroups = EnumSystemLanguageGroupsW
#ELSE
   MACRO EnumSystemLanguageGroups = EnumSystemLanguageGroupsA
#ENDIF

DECLARE FUNCTION EnumLanguageGroupLocalesA IMPORT "KERNEL32.DLL" ALIAS "EnumLanguageGroupLocalesA" ( _
   BYVAL lpLangGroupLocaleEnumProc AS DWORD _           ' __in LANGGROUPLOCALE_ENUMPROCA lpLangGroupLocaleEnumProc
 , BYVAL LanguageGroup AS DWORD _                       ' __in LGRPID                    LanguageGroup
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD                     dwFlags
 , BYVAL lParam AS LONG _                               ' __in LONG_PTR                  lParam
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumLanguageGroupLocalesW IMPORT "KERNEL32.DLL" ALIAS "EnumLanguageGroupLocalesW" ( _
   BYVAL lpLangGroupLocaleEnumProc AS DWORD _           ' __in LANGGROUPLOCALE_ENUMPROCW lpLangGroupLocaleEnumProc
 , BYVAL LanguageGroup AS DWORD _                       ' __in LGRPID                    LanguageGroup
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD                     dwFlags
 , BYVAL lParam AS LONG _                               ' __in LONG_PTR                  lParam
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EnumLanguageGroupLocales = EnumLanguageGroupLocalesW
#ELSE
   MACRO EnumLanguageGroupLocales = EnumLanguageGroupLocalesA
#ENDIF

DECLARE FUNCTION EnumUILanguagesA IMPORT "KERNEL32.DLL" ALIAS "EnumUILanguagesA" ( _
   BYVAL lpUILanguageEnumProc AS DWORD _                ' __in UILANGUAGE_ENUMPROCA lpUILanguageEnumProc
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD                dwFlags
 , BYVAL lParam AS LONG _                               ' __in LONG_PTR             lParam
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumUILanguagesW IMPORT "KERNEL32.DLL" ALIAS "EnumUILanguagesW" ( _
   BYVAL lpUILanguageEnumProc AS DWORD _                ' __in UILANGUAGE_ENUMPROCW lpUILanguageEnumProc
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD                dwFlags
 , BYVAL lParam AS LONG _                               ' __in LONG_PTR             lParam
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EnumUILanguages = EnumUILanguagesW
#ELSE
   MACRO EnumUILanguages = EnumUILanguagesA
#ENDIF
'#endif /* WINVER >= 0x0500 */

DECLARE FUNCTION EnumSystemLocalesA IMPORT "KERNEL32.DLL" ALIAS "EnumSystemLocalesA" ( _
   BYVAL lpLocaleEnumProc AS DWORD _                    ' __in LOCALE_ENUMPROCA lpLocaleEnumProc
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD            dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumSystemLocalesW IMPORT "KERNEL32.DLL" ALIAS "EnumSystemLocalesW" ( _
   BYVAL lpLocaleEnumProc AS DWORD _                    ' __in LOCALE_ENUMPROCW lpLocaleEnumProc
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD            dwFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EnumSystemLocales = EnumSystemLocalesW
#ELSE
   MACRO EnumSystemLocales = EnumSystemLocalesA
#ENDIF

DECLARE FUNCTION EnumSystemCodePagesA IMPORT "KERNEL32.DLL" ALIAS "EnumSystemCodePagesA" ( _
   BYVAL lpCodePageEnumProc AS DWORD _                  ' __in CODEPAGE_ENUMPROCA lpCodePageEnumProc
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD              dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumSystemCodePagesW IMPORT "KERNEL32.DLL" ALIAS "EnumSystemCodePagesW" ( _
   BYVAL lpCodePageEnumProc AS DWORD _                  ' __in CODEPAGE_ENUMPROCW lpCodePageEnumProc
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD              dwFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EnumSystemCodePages = EnumSystemCodePagesW
#ELSE
   MACRO EnumSystemCodePages = EnumSystemCodePagesA
#ENDIF

'#if (WINVER >= 0x0600)
'//
'// Windows API Normalization Functions
'//

DECLARE FUNCTION NormalizeString IMPORT "NORMALIZ.DLL" ALIAS "NormalizeString" ( _
   BYVAL NormForm AS DWORD _                            ' __in  NORM_FORM NormForm
 , BYREF lpSrcString AS WSTRINGZ _                      ' __in  LPCWSTR   lpSrcString
 , BYVAL cwSrcLength AS LONG _                          ' __in  int       cwSrcLength
 , BYREF lpDstString AS WSTRINGZ _                      ' __out LPWSTR    lpDstString
 , BYVAL cwDstLength AS LONG _                          ' __in  int       cwDstLength
 ) AS LONG                                              ' int

DECLARE FUNCTION IsNormalizedString IMPORT "NORMALIZ.DLL" ALIAS "IsNormalizedString" ( _
   BYVAL NormForm AS DWORD _                            ' __in NORM_FORM NormForm
 , BYREF lpString AS WSTRINGZ _                         ' __in LPCWSTR   lpString
 , BYVAL cwLength AS LONG _                             ' __in int       cwLength
 ) AS LONG                                              ' int

'//
'// IDN (International Domain Name) Functions
'//
DECLARE FUNCTION IdnToAscii IMPORT "NORMALIZ.DLL" ALIAS "IdnToAscii" ( _
   BYVAL dwFlags AS DWORD _                             ' __in  DWORD   dwFlags
 , BYREF lpUnicodeCharStr AS WSTRINGZ _                 ' __in  LPCWSTR lpUnicodeCharStr
 , BYVAL cchUnicodeChar AS LONG _                       ' __in  int     cchUnicodeChar
 , BYREF lpASCIICharStr AS WSTRINGZ _                   ' __out LPWSTR  lpASCIICharStr
 , BYVAL cchASCIIChar AS LONG _                         ' __in  int     cchASCIIChar
 ) AS LONG                                              ' int

DECLARE FUNCTION IdnToNameprepUnicode IMPORT "NORMALIZ.DLL" ALIAS "IdnToNameprepUnicode" ( _
   BYVAL dwFlags AS DWORD _                             ' __in  DWORD   dwFlags
 , BYREF lpUnicodeCharStr AS WSTRINGZ _                 ' __in  LPCWSTR lpUnicodeCharStr
 , BYVAL cchUnicodeChar AS LONG _                       ' __in  int     cchUnicodeChar
 , BYREF lpNameprepCharStr AS WSTRINGZ _                ' __out LPWSTR  lpNameprepCharStr
 , BYVAL cchNameprepChar AS LONG _                      ' __in  int     cchNameprepChar
 ) AS LONG                                              ' int

DECLARE FUNCTION IdnToUnicode IMPORT "NORMALIZ.DLL" ALIAS "IdnToUnicode" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD    dwFlags
 , BYREF lpASCIICharStr AS WSTRINGZ _                   ' __in LPCWSTR  lpASCIICharStr
 , BYVAL cchASCIIChar AS LONG _                         ' __int         cchASCIIChar
 , BYREF lpUnicodeCharStr AS WSTRINGZ _                 ' __out LPWSTR  lpUnicodeCharStr
 , BYVAL cchUnicodeChar AS LONG _                       ' __in int      cchUnicodeChar
 ) AS LONG                                              ' int

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION VerifyScripts LIB "Kernel32.dll" ALIAS "VerifyScripts" _
    (BYVAL dwFlags AS DWORD, _          ' optional behavior flags
    BYVAL lpLocaleScripts AS DWORD, _   ' Locale list of scripts string
    BYVAL cchLocaleScripts AS LONG, _   ' size of locale script list string
    BYVAL lpTestScripts AS DWORD, _     ' test scripts string
    BYVAL cchTestScripts AS LONG) _     ' size of test list string
    AS LONG
#ELSE
DECLARE FUNCTION VerifyScripts IMPORT "KERNEL32.DLL" ALIAS "VerifyScripts" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD    dwFlags
 , BYREF lpLocaleScripts AS WSTRINGZ _                  ' __in LPCWSTR  lpLocaleScripts
 , BYVAL cchLocaleScripts AS LONG _                     ' __int         cchLocaleScripts
 , BYREF lpTestScripts AS WSTRINGZ _                    ' __in LPCWSTR  lpTestScripts
 , BYVAL cchTestScripts AS LONG _                       ' __in int      cchTestScripts
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetStringScripts LIB "Kernel32.dll" ALIAS "GetStringScripts" _
    (BYVAL dwFlags AS DWORD, _       ' optional behavior flags
    BYVAL lpString AS DWORD PTR, _   ' Unicode character input string
    BYVAL cchString AS LONG, _       ' size of input string
    lpScripts AS WSTRINGZ, _         ' Script list output string
    BYVAL cchScripts AS LONG) _      ' size of output string
    AS LONG
#ELSE
DECLARE FUNCTION GetStringScripts IMPORT "KERNEL32.DLL" ALIAS "GetStringScripts" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD    dwFlags
 , BYREF lpString AS WSTRINGZ _                         ' __in LPCWSTR  lpString
 , BYVAL cchString AS LONG _                            ' __int         cchString
 , BYREF lpScripts AS WSTRINGZ _                        ' __in LPWSTR   lpScripts
 , BYVAL cchScripts AS LONG _                           ' __in int      cchScripts
 ) AS LONG                                              ' int
#ENDIF

'#endif //(WINVER >= 0x0600)

'#if (WINVER >= 0x0600)
'//
'// String based NLS APIs
'//

%LOCALE_NAME_USER_DEFAULT            = %NULL
$$LOCALE_NAME_INVARIANT               = ""$$
$$LOCALE_NAME_SYSTEM_DEFAULT          = "!x-sys-default-locale"$$

' // Note: The lpLCData has been declared as ANY because this parameter can be used for
' // numbers if LOCALE_RETURN_NUMBER is used in LCType.
DECLARE FUNCTION GetLocaleInfoEx IMPORT "KERNEL32.DLL" ALIAS "GetLocaleInfoEx" ( _
   BYREF lpLocaleName AS WSTRINGZ _                     ' __in_opt LPCWSTR lpLocaleName
 , BYVAL LCType AS DWORD _                              ' __in     LCTYPE LCType
 , BYREF lpLCData AS WSTRINGZ _                         ' __out    LPWSTR lpLCData
 , BYVAL cchData AS LONG _                              ' __in     int cchData
 ) AS LONG                                              ' int

DECLARE FUNCTION GetCalendarInfoEx IMPORT "KERNEL32.DLL" ALIAS "GetCalendarInfoEx" ( _
   BYREF lpLocaleName AS WSTRINGZ _                     ' __in_opt  LPCWSTR lpLocaleName
 , BYVAL Calendar AS DWORD _                            ' __in      CALID Calendar
 , BYREF lpReserved AS WSTRINGZ _                       ' __in_opt  LPCWSTR lpReserved
 , BYVAL CalType AS DWORD _                             ' __in      CALTYPE CalType
 , BYREF lpCalData AS WSTRINGZ _                        ' __out     LPWSTR lpCalData
 , BYVAL cchData AS LONG _                              ' __in      int cchData
 , OPTIONAL BYREF lpValue AS DWORD _                    ' __out_opt LPDWORD lpValue
 ) AS LONG                                              ' int

DECLARE FUNCTION GetTimeFormatEx IMPORT "KERNEL32.DLL" ALIAS "GetTimeFormatEx" ( _
   BYREF lpLocaleName AS WSTRINGZ _                     ' __in_opt  LPCWSTR lpLocaleName
 , BYVAL dwFlags AS DWORD _                             ' __in      DWORD   dwFlags
 , BYREF lpTime AS SYSTEMTIME _                         ' __in_opt  CONST SYSTEMTIME *lpTime
 , BYREF lpFormat AS WSTRINGZ _                         ' __in_opt  LPCWSTR lpFormat
 , BYREF lpTimeStr AS WSTRINGZ _                        ' __out     LPWSTR  lpTimeStr
 , BYVAL cchTime AS LONG _                              ' __in      int     cchTime
 ) AS LONG                                              ' int

DECLARE FUNCTION GetDateFormatEx IMPORT "KERNEL32.DLL" ALIAS "GetDateFormatEx" ( _
   BYREF lpLocaleName AS WSTRINGZ _                     ' __in_opt  LPCWSTR lpLocaleName
 , BYVAL dwFlags AS DWORD _                             ' __in      DWORD   dwFlags
 , BYREF lpDate AS SYSTEMTIME _                         ' __in_opt  CONST SYSTEMTIME *lpDate
 , BYREF lpFormat AS WSTRINGZ _                         ' __in_opt  LPCWSTR lpFormat
 , BYREF lpDateStr AS WSTRINGZ _                        ' __out     LPWSTR  lpDateStr
 , BYVAL cchDate AS LONG _                              ' __in      int     cchDate
 , OPTIONAL BYREF lpCalendar AS WSTRINGZ _              ' __in_opt  LPCWSTR lpCalendar
 ) AS LONG                                              ' int

DECLARE FUNCTION GetDurationFormatEx IMPORT "KERNEL32.DLL" ALIAS "GetDurationFormatEx" ( _
   BYREF lpLocaleName AS WSTRINGZ _                     ' __in_opt  LPCWSTR   lpLocaleName
 , BYVAL dwFlags AS DWORD _                             ' __in      DWORD     dwFlags
 , BYREF lpDuration AS SYSTEMTIME _                     ' __in_opt  CONST SYSTEMTIME *lpDuration
 , BYVAL ullDuration AS QUAD _                          ' __in_opt  ULONGLONG ullDuration
 , BYREF lpFormat AS WSTRINGZ _                         ' __in_opt  LPCWSTR   lpFormat
 , BYREF lpDurationStr AS WSTRINGZ _                    ' __out_opt LPWSTR    lpDurationStr
 , BYVAL cchDuration AS LONG _                          ' __in      int       cchDuration
 ) AS LONG                                              ' int

DECLARE FUNCTION GetNumberFormatEx IMPORT "KERNEL32.DLL" ALIAS "GetNumberFormatEx" ( _
   BYREF lpLocaleName AS WSTRINGZ _                     ' __in_opt  LPCWSTR lpLocaleName
 , BYVAL dwFlags AS DWORD _                             ' __in      DWORD   dwFlags
 , BYREF lpValue AS WSTRINGZ _                          ' __in      LPCWSTR lpValue
 , BYREF lpFormat AS NUMBERFMTW _                       ' __in_opt  CONST NUMBERFMTW * lpFormat
 , BYREF lpNumberStr AS WSTRINGZ _                      ' __out_opt LPWSTR  lpNumberStr
 , BYVAL cchNumber AS LONG _                            ' __in      int     cchNumber
 ) AS LONG                                              ' int

DECLARE FUNCTION GetCurrencyFormatEx IMPORT "KERNEL32.DLL" ALIAS "GetCurrencyFormatEx" ( _
   BYREF lpLocaleName AS WSTRINGZ _                     ' __in_opt  LPCWSTR lpLocaleName
 , BYVAL dwFlags AS DWORD _                             ' __in      DWORD   dwFlags
 , BYREF lpValue AS WSTRINGZ _                          ' __in      LPCWSTR lpValue
 , BYREF lpFormat AS CURRENCYFMTW _                     ' __in_opt  CONST CURRENCYFMTW * lpFormat
 , BYREF lpCurrencyStr AS WSTRINGZ _                    ' __out_opt LPWSTR  lpCurrencyStr
 , BYVAL cchCurrency AS LONG _                          ' __in      int     cchCurrency
 ) AS LONG                                              ' int

DECLARE FUNCTION GetUserDefaultLocaleName IMPORT "KERNEL32.DLL" ALIAS "GetUserDefaultLocaleName" ( _
   BYREF lpLocaleName AS WSTRINGZ _                     ' __out LPWSTR lpLocaleName
 , BYVAL cchLocaleName AS LONG _                        ' __in  int cchLocaleName
 ) AS LONG                                              ' int

DECLARE FUNCTION GetSystemDefaultLocaleName IMPORT "KERNEL32.DLL" ALIAS "GetSystemDefaultLocaleName" ( _
   BYREF lpLocaleName AS WSTRINGZ _                     ' __out LPWSTR lpLocaleName
 , BYVAL cchLocaleName AS LONG _                        ' __in  int cchLocaleName
 ) AS LONG                                              ' int

DECLARE FUNCTION GetNLSVersionEx IMPORT "KERNEL32.DLL" ALIAS "GetNLSVersionEx" ( _
   BYVAL function AS DWORD _                            ' __in     NLS_FUNCTION function
 , BYREF lpLocaleName AS WSTRINGZ _                     ' __in_opt LPCWSTR lpLocaleName
 , BYREF lpVersionInformation AS NLSVERSIONINFOEX _     ' __in_out LPNLSVERSIONINFOEX lpVersionInformation
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CompareStringEx LIB "Kernel32.dll" _
    ALIAS "CompareStringEx" (lpLocaleName AS WSTRINGZ, _
    BYVAL dwCmpFlags AS DWORD, lpString1 AS WSTRINGZ, _
    BYVAL cchCount1 AS LONG, lpString2 AS WSTRINGZ, BYVAL cchCount2 AS LONG, _
    lpVersionInformation AS NLSVERSIONINFO, lpReserved AS DWORD, _
    BYVAL lParam AS LONG) AS LONG
#ELSE
DECLARE FUNCTION CompareStringEx IMPORT "KERNEL32.DLL" ALIAS "CompareStringEx" ( _
   BYREF lpLocaleName AS WSTRINGZ _                     ' __in_opt LPCWSTR lpLocaleName
 , BYVAL dwCmpFlags AS DWORD _                          ' __in DWORD dwCmpFlags
 , BYREF lpString1 AS WSTRINGZ _                        ' __in LPCWSTR lpString1
 , BYVAL cchCount1 AS LONG _                            ' __in int cchCount1
 , BYREF lpString2 AS WSTRINGZ _                        ' __in LPCWSTR lpString2
 , BYVAL cchCount2 AS LONG _                            ' __in int cchCount2
 , OPTIONAL BYREF lpVersionInformation AS NLSVERSIONINFO _ ' __in_opt LPNLSVERSIONINFO lpVersionInformation
 , OPTIONAL BYVAL lpReserved AS DWORD _                 ' __in_opt LPVOID lpReserved
 , OPTIONAL BYVAL lParam AS LONG _                      ' __in_opt LPARAM lParam
 ) AS LONG                                              ' int
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION FindNLSStringEx LIB "Kernel32.dll" _
    ALIAS "FindNLSStringEx" (lpLocaleName AS WSTRINGZ, _
    BYVAL dwFindNLSStringFlags AS DWORD, lpStringSource AS WSTRINGZ, _
    BYVAL cchSource AS LONG, lpStringValue AS WSTRINGZ, _
    BYVAL cchValue AS LONG, pcchFound AS LONG, _
    lpVersionInformation AS NLSVERSIONINFO, lpReserved AS DWORD, _
    BYVAL lParam AS LONG) AS LONG
#ELSE
DECLARE FUNCTION FindNLSStringEx IMPORT "KERNEL32.DLL" ALIAS "FindNLSStringEx" ( _
   BYREF lpLocaleName AS WSTRINGZ _                     ' __in_opt LPCWSTR lpLocaleName
 , BYVAL dwFindNLSStringFlags AS DWORD _                ' __in DWORD dwFindNLSStringFlags
 , BYREF lpStringSource AS WSTRINGZ _                   ' __in LPCWSTR lpStringSource
 , BYVAL cchSource AS LONG _                            ' __in int cchSource
 , BYREF lpStringValue AS WSTRINGZ _                    ' __in LPCWSTR lpStringValue
 , BYVAL cchValue AS LONG _                             ' __in int cchValue
 , BYREF pcchFound AS LONG _                            ' __out_opt LPINT pcchFound
 , OPTIONAL BYREF lpVersionInformation AS NLSVERSIONINFO _ ' __in_opt LPNLSVERSIONINFO lpVersionInformation
 , OPTIONAL BYVAL lpReserved AS DWORD _                 ' __in_opt LPVOID lpReserved
 , OPTIONAL BYVAL lParam AS LONG _                      ' __in_opt LPARAM lParam
 ) AS LONG                                              ' int
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION LCMapStringEx LIB "Kernel32.dll" _
    ALIAS "LCMapStringEx" (lpLocaleName AS WSTRINGZ, _
    BYVAL dwMapFlags AS DWORD, lpSrcStr AS WSTRINGZ, BYVAL cchSrc AS LONG, _
    lpDestStr AS WSTRINGZ, BYVAL cchDest AS LONG, _
    lpVersionInformation AS NLSVERSIONINFO, lpReserved AS DWORD, _
    BYVAL lParam AS LONG) AS LONG
#ELSE
DECLARE FUNCTION LCMapStringEx IMPORT "KERNEL32.DLL" ALIAS "LCMapStringEx" ( _
   BYREF lpLocaleName AS WSTRINGZ _                     ' __in_opt LPCWSTR lpLocaleName
 , BYVAL dwMapFlags AS DWORD _                          ' __in DWORD dwMapFlags
 , BYREF lpSrcStr AS WSTRINGZ _                         ' __in LPCWSTR lpSrcStr
 , BYVAL cchSrc AS LONG _                               ' __in int cchSrc
 , BYREF lpDestStr AS WSTRINGZ _                        ' __out_opt LPWSTR lpDestStr
 , BYVAL cchDest AS LONG _                              ' __in int cchDest
 , OPTIONAL BYREF lpVersionInformation AS NLSVERSIONINFO _ ' __in_opt LPNLSVERSIONINFO lpVersionInformation
 , OPTIONAL BYVAL lpReserved AS DWORD _                 ' __in_opt LPVOID lpReserved
 , OPTIONAL BYVAL lParam AS LONG _                      ' __in_opt LPARAM lParam
 ) AS LONG                                              ' int
#ENDIF

DECLARE FUNCTION CompareStringOrdinal IMPORT "KERNEL32.DLL" ALIAS "CompareStringOrdinal" ( _
   BYREF lpString1 AS WSTRINGZ _                        ' __in LPCWSTR lpString1
 , BYVAL cchCount1 AS LONG _                            ' __in int     cchCount1
 , BYREF lpString2 AS WSTRINGZ _                        ' __in LPCWSTR lpString2
 , BYVAL cchCount2 AS LONG _                            ' __in int     cchCount2
 , BYVAL bIgnoreCase AS LONG _                          ' __in BOOL    bIgnoreCase
 ) AS LONG                                              ' int

DECLARE FUNCTION IsValidLocaleName IMPORT "KERNEL32.DLL" ALIAS "IsValidLocaleName" ( _
   BYREF lpLocaleName AS WSTRINGZ _                     ' __in LPCWSTR lpLocaleName
 ) AS LONG                                              ' BOOL

'typedef BOOL (CALLBACK* CALINFO_ENUMPROCEXEX)(LPWSTR, CALID, LPWSTR, LPARAM);

DECLARE FUNCTION EnumCalendarInfoExEx IMPORT "KERNEL32.DLL" ALIAS "EnumCalendarInfoExEx" ( _
   BYVAL pCalInfoEnumProcExEx AS DWORD _                ' __in CALINFO_ENUMPROCEXEX pCalInfoEnumProcExEx
 , BYREF lpLocaleName AS WSTRINGZ _                     ' __in_opt LPCWSTR lpLocaleName
 , BYVAL Calendar AS DWORD _                            ' __in CALID Calendar
 , BYREF lpReserved AS WSTRINGZ _                       ' __in_opt LPCWSTR lpReserved
 , BYVAL CalType AS DWORD _                             ' __in CALTYPE CalType
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' BOOL

'typedef BOOL (CALLBACK* DATEFMT_ENUMPROCEXEX)(LPWSTR, CALID, LPARAM);

DECLARE FUNCTION EnumDateFormatsExEx IMPORT "KERNEL32.DLL" ALIAS "EnumDateFormatsExEx" ( _
   BYVAL lpDateFmtEnumProcExEx AS DWORD _               ' __in DATEFMT_ENUMPROCEXEX lpDateFmtEnumProcExEx
 , BYREF lpLocaleName AS WSTRINGZ _                     ' __in_opt LPCWSTR lpLocaleName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' BOOL

'typedef BOOL (CALLBACK* TIMEFMT_ENUMPROCEX)(LPWSTR, LPARAM);

DECLARE FUNCTION EnumTimeFormatsEx IMPORT "KERNEL32.DLL" ALIAS "EnumTimeFormatsEx" ( _
   BYVAL lpTimeFmtEnumProcEx AS DWORD _                 ' __in TIMEFMT_ENUMPROCEX lpTimeFmtEnumProcEx
 , BYREF lpLocaleName AS WSTRINGZ _                     ' __in_opt LPCWSTR lpLocaleName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' BOOL

'typedef BOOL (CALLBACK* LOCALE_ENUMPROCEX)(LPWSTR, DWORD, LPARAM);

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumSystemLocalesEx LIB "Kernel32.dll" _
    ALIAS "EnumSystemLocalesEx" (BYVAL lpLocaleEnumProcEx AS DWORD, _
    BYVAL dwFlags AS DWORD, BYVAL lParam AS LONG, lpReserved AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION EnumSystemLocalesEx IMPORT "KERNEL32.DLL" ALIAS "EnumSystemLocalesEx" ( _
   BYVAL lpLocaleEnumProcEx AS DWORD _                  ' __in LOCALE_ENUMPROCEX lpLocaleEnumProcEx
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 , OPTIONAL BYVAL lpReserved AS DWORD _                 ' __in_opt LPVOID lpReserved
 ) AS LONG                                              ' BOOL
#ENDIF

'#endif //(WINVER >= 0x0600)

'#if (WINVER >= _WIN32_WINNT_WIN7)
DECLARE FUNCTION ResolveLocaleName IMPORT "KERNEL32.DLL" ALIAS "ResolveLocaleName" ( _
   BYREF lpNameToResolve AS WSTRINGZ _                  ' __in_opt LPCWSTR lpNameToResolve
 , BYREF lpLocaleName AS WSTRINGZ _                     ' __out LPWSTR     lpLocaleName
 , BYVAL cchLocaleName AS LONG _                        ' __in int         cchLocaleName
 ) AS LONG                                              ' int
'#endif // (WINVER >= _WIN32_WINNT_WIN7)

#ENDIF   ' // NONLS
