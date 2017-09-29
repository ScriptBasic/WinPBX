' ########################################################################################
' Microsoft Windows
' File: AfxNls.inc
' Contents: National language support functions
' Copyright (c) 2011 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AFXNLS_INC = 1

#INCLUDE ONCE "windows.inc"

' ========================================================================================
' Returns the abbreviated native day name for the specified day (1 = Monday, etc.).
' ========================================================================================
FUNCTION AfxGetLocaleAbbrevDayName (BYVAL nDay AS LONG, OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nDay < 1 OR nDay > 7 THEN EXIT FUNCTION
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SABBREVDAYNAME1 + nDay - 1, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the abbreviated native month name for the specified month.
' ========================================================================================
FUNCTION AfxGetLocaleAbbrevMonthName (BYVAL nMonth AS LONG, OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nMonth < 1 OR nMonth > 12 THEN EXIT FUNCTION
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SABBREVMONTHNAME1 + nMonth - 1, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Full localized name of the country/region. Deprecated for Windows 7 and later.
' See AfxGetLocalizedCountryName.
' ========================================================================================
FUNCTION AfxGetLocaleCountryName (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SCOUNTRY, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' String used as the local monetary symbol. The maximum number of characters allowed for
' this string is 13, including a terminating null character. For example, in the United
' States, this symbol is "$".
' ========================================================================================
FUNCTION AfxGetLocaleCurrencySymbol (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SCURRENCY, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the native day name for the specified day (1 = Monday, etc.).
' ========================================================================================
FUNCTION AfxGetLocaleDayName (BYVAL nDay AS LONG, OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nDay < 1 OR nDay > 7 THEN EXIT FUNCTION
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SDAYNAME1 + nDay - 1, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Character(s) used for the decimal separator, for example, "." in "3.14" or "," in "3,14".
' The maximum number of characters allowed for this string is four, including a terminating
' null character.
' ========================================================================================
FUNCTION AfxGetLocaleDecimalSeparator (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SDECIMAL, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sizes for each group of digits to the left of the decimal. The maximum number of characters
' allowed for this string is ten, including a terminating null character. An explicit size
' is needed for each group, and sizes are separated by semicolons. If the last value is 0,
' the preceding value is repeated. For example, to group thousands, specify 3;0. Indic
' locales group the first thousand and then group by hundreds. For example, 12,34,56,789
' is represented by 3;2;0.
' ========================================================================================
FUNCTION AfxGetLocaleDigitsGrouping (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SGROUPING, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Primary language name included in a localized display name. Deprecated in Windows 7.
' See AfxGetLocalizedDisplayName.
' ========================================================================================
FUNCTION AfxGetLocaleDisplayName (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SLANGDISPLAYNAME, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Full English name of the country/region.
' ========================================================================================
FUNCTION AfxGetLocaleEnglishCountryName (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SENGCOUNTRY, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' The full English name of the currency associated with the locale.
' ========================================================================================
FUNCTION AfxGetLocaleEnglishCurrencyName (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SENGCURRNAME, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Windows 7 and later: Display name of the locale in English. Usually the display name
' consists of the language and the country/region, for example, German (Germany) for
' Deutsch (Deutschland).
' ========================================================================================
FUNCTION AfxGetLocaleEnglishDisplayName (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SENGLISHDISPLAYNAME, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Full English name of the language from ISO Standard 639.
' ========================================================================================
FUNCTION AfxGetLocaleEnglishLanguageName (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SENGLANGUAGE, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Three characters of the international monetary symbol specified in ISO 4217, followed by
' the character separating this string from the amount. The maximum number of characters
' allowed for this string is nine, including a terminating null character.
' ========================================================================================
FUNCTION AfxGetLocaleInternationalMonetarySymbol (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SINTLSYMBOL, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' The abbreviated name of the language based entirely on the ISO Standard 639 values, in
' lowercase form, for example, "en" for English. The maximum number of characters allowed
' for this string is nine, including a terminating null character.
' ========================================================================================
FUNCTION AfxGetLocaleISO639LanguageName (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SISO639LANGNAME, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Windows Vista and later: Three-letter ISO language name, in lowercase form (ISO 639-2
' three-letter code for the language), for example, "eng" for English. The maximum number
' of characters allowed for this string is nine, including a terminating null character.
' ========================================================================================
FUNCTION AfxGetLocaleISO639LanguageName2 (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SISO639LANGNAME2, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Country/region name, based on ISO Standard 3166, for example, "US" for the United States.
' The maximum number of characters allowed for this string is nine, including a terminating
' null character.
' ========================================================================================
FUNCTION AfxGetLocaleISO3166CountryName (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SISO3166CTRYNAME, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Windows Vista and later: Three-letter ISO region name (ISO 3166 three-letter code for the
' country/region), for example, "USA" for the United States. The maximum number of characters
' allowed for this string is nine, including a terminating null character.
' ========================================================================================
FUNCTION AfxGetLocaleISO3166CountryName2 (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SISO3166CTRYNAME2, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Full localized name of the language. Deprecated in Windows 7.
' See AfxGetLocalizedLanguageName.
' ========================================================================================
FUNCTION AfxGetLocaleLanguageName (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SLANGUAGE, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Character(s) used to separate list items, for example, a comma is used in many locales.
' The maximum number of characters allowed for this string is four, including a
' terminating null character.
' ========================================================================================
FUNCTION AfxGetLocaleListItemsSeparator (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SLIST, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Long date formatting string for the locale. The maximum number of characters allowed for
' this string is 80, including a terminating null character. The string can consist of a
' combination of day, month, year, and era format pictures and any string of characters
' enclosed in single quotes. Characters in single quotes remain as specified. For example,
' the Spanish (Spain) long date is "dddd, dd' de 'MMMM' de 'yyyy". Locales can define
' multiple long date formats.
' ========================================================================================
FUNCTION AfxGetLocaleLongDateFormatString (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SLONGDATE, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Character(s) used as the monetary decimal separator. The maximum number of characters
' allowed for this string is four, including a terminating null character. For example,
' if a monetary amount is displayed as "$3.40", just as "three dollars and forty cents"
' is displayed in the United States, then the monetary decimal separator is ".".
' ========================================================================================
FUNCTION AfxGetLocaleMonetaryDecimalSeparator (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SMONDECIMALSEP, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sizes for each group of monetary digits to the left of the decimal. The maximum number
' of characters allowed for this string is ten, including a terminating null character.
' An explicit size is needed for each group, and sizes are separated by semicolons. If the
' last value is 0, the preceding value is repeated. For example, to group thousands,
' specify 3;0. Indic languages group the first thousand and then group by hundreds. For
' example 12,34,56,789 is represented by 3;2;0.
' ========================================================================================
FUNCTION AfxGetLocaleMonetaryGrouping (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SMONGROUPING, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Character(s) used as the monetary separator between groups of digits to the left of the
' decimal. The maximum number of characters allowed for this string is four, including a
' terminating null character. Typically, the groups represent thousands. However, depending
' on the value specified for LOCALE_SMONGROUPING, they can represent something else.
' ========================================================================================
FUNCTION AfxGetLocaleMonetaryThousandsSeparator (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SMONTHOUSANDSEP, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Windows 7 and later: Format string for displaying only the month and the day. The
' formatting is similar to that defined for LOCALE_SLONGDATE. For example, if the month/day
' pattern is the full month name followed by the day number with leading zeros, as in
' "September 03", the format string is "MMMM dd". The string can consist of a combination
' of day and month format pictures and any string of characters enclosed in single quotes.
' Characters in single quotes remain as specified, for example, 'de' for Spanish (Spain).
' A locale can specify only one month/day format.
' ========================================================================================
FUNCTION AfxGetLocaleMonthDayFormatString (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SMONTHDAY, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the native month name for the specified month.
' ========================================================================================
FUNCTION AfxGetLocaleMonthName (BYVAL nMonth AS LONG, OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nMonth < 1 OR nMonth > 12 THEN EXIT FUNCTION
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SMONTHNAME1 + nMonth - 1, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Windows Vista and later: Locale name, a multi-part tag to uniquely identify the locale.
' The maximum number of characters allowed for this string is 85, including a terminating
' null character. The tag is based on the language tagging conventions of RFC 4646.
' ========================================================================================
FUNCTION AfxGetLocaleName (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SNAME, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Windows Vista and later: String value for "Not a number", for example, "Nan" for the
' English (United States) locale. There is no limit on the number of characters allowed
' for this string.
' ========================================================================================
FUNCTION AfxGetLocaleNanString (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL nLen AS LONG
   LOCAL bstrBuf AS WSTRING
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   nLen = GetLocaleInfoW(nLocale, %LOCALE_SNAN, BYVAL %NULL, 0)
   IF nLen = 0 THEN EXIT FUNCTION
   bstrBuf = SPACE$(nLen)
   nLen = GetLocaleInfoW(nLocale, %LOCALE_SNAN, BYVAL STRPTR(bstrBuf), LEN(bstrBuf))
   FUNCTION = TRIM$(bstrBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Native name of the country/region, for example, España for Spain. The maximum number of
' characters allowed for this string is 80, including a terminating null character.
' ========================================================================================
FUNCTION AfxGetLocaleNativeCountryName (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SNATIVECTRYNAME, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' The native name of the currency associated with the locale, in the native language of
' the locale. There is no limit on the number of characters allowed for this string.
' ========================================================================================
FUNCTION AfxGetLocaleNativeCurrencyName (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SNATIVECURRNAME, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Native equivalents of ASCII 0 through 9. The maximum number of characters allowed for
' this string is eleven, including a terminating null character.
' ========================================================================================
FUNCTION AfxGetLocaleNativeDigits (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SNATIVEDIGITS, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Windows 7 and later: Display name of the locale in its native language, for example,
' Deutsch (Deutschland) for the locale German (Germany).
' ========================================================================================
FUNCTION AfxGetLocaleNativeDisplayName (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SNATIVEDISPLAYNAME, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Native name of the language, for example, ??????? for Armenian (Armenia). The maximum
' number of characters allowed for this string is 80, including a terminating null character.
' ========================================================================================
FUNCTION AfxGetLocaleNativeLanguageName (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SNATIVELANGNAME, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Windows Vista and later: String value for "negative infinity", for example, "-Infinity"
' for the English (United States) locale. There is no limit on the number of characters
' allowed for this string.
' ========================================================================================
FUNCTION AfxGetLocaleNegativeInfinityString (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL nLen AS LONG
   LOCAL bstrBuf AS WSTRING
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   nLen = GetLocaleInfoW(nLocale, %LOCALE_SNEGINFINITY, BYVAL %NULL, 0)
   IF nLen = 0 THEN EXIT FUNCTION
   bstrBuf = SPACE$(nLen)
   nLen = GetLocaleInfoW(nLocale, %LOCALE_SNEGINFINITY, BYVAL STRPTR(bstrBuf), LEN(bstrBuf))
   FUNCTION = TRIM$(bstrBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' String value for the negative sign, for example, "-" for the English (United States) locale.
' The maximum number of characters allowed for this string is five, including a terminating
' null character.
' ========================================================================================
FUNCTION AfxGetLocaleNegativeSign (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SNEGATIVESIGN, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Windows 7 and later: OpenType language tag used to retrieve culturally appropriate
' typographic features from a font.
' ========================================================================================
FUNCTION AfxGetLocaleOpenTypeLanguageTag (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SOPENTYPELANGUAGETAG, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Windows 7 and later: Symbol used to indicate the permille (U+2030) symbol, that is, ‰.
' ========================================================================================
FUNCTION AfxGetLocalePermilleSymbol (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SPERMILLE, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Windows Vista and later: String value for "positive infinity", for example, "Infinity"
' for the English (United States) locale. There is no limit on the number of characters
' allowed for the string.
' ========================================================================================
FUNCTION AfxGetLocalePositiveInfinityString (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL nLen AS LONG
   LOCAL bstrBuf AS WSTRING
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   nLen = GetLocaleInfoW(nLocale, %LOCALE_SPOSINFINITY, BYVAL %NULL, 0)
   IF nLen = 0 THEN EXIT FUNCTION
   bstrBuf = SPACE$(nLen)
   nLen = GetLocaleInfoW(nLocale, %LOCALE_SPOSINFINITY, BYVAL STRPTR(bstrBuf), LEN(bstrBuf))
   FUNCTION = TRIM$(bstrBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' String value for the positive sign, for example, "+" for the English (United States)
' locale. The maximum number of characters allowed for this string is five, including a
' terminating null character.
' ========================================================================================
FUNCTION AfxGetLocalePositiveSign (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SPOSITIVESIGN, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Windows Vista and later: A string representing a list of scripts, using the 4-character
' notation used in ISO 15924. Each script name consists of four Latin characters and the
' list is arranged in alphabetical order with each name, including the last, followed by a
' semicolon.
' ========================================================================================
FUNCTION AfxGetLocaleScriptsList (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL nLen AS LONG
   LOCAL bstrBuf AS WSTRING
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   nLen = GetLocaleInfoW(nLocale, %LOCALE_SSCRIPTS, BYVAL %NULL, 0)
   IF nLen = 0 THEN EXIT FUNCTION
   bstrBuf = SPACE$(nLen)
   nLen = GetLocaleInfoW(nLocale, %LOCALE_SSCRIPTS, BYVAL STRPTR(bstrBuf), LEN(bstrBuf))
   FUNCTION = TRIM$(bstrBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Short date formatting string for the locale. The maximum number of characters allowed
' for this string is 80, including a terminating null character. The string can consist of
' a combination of day, month, year, and era format pictures. For example, "M/d/yyyy"
' indicates that September 3, 2004 is written 9/3/2004.
' ========================================================================================
FUNCTION AfxGetLocaleShortDateFormatString (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SSHORTDATE, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Windows Vista and later: Short native name of the specified day of the week.
' ========================================================================================
FUNCTION AfxGetLocaleShortestDayName (BYVAL nDay AS LONG, OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nDay < 1 OR nDay > 7 THEN EXIT FUNCTION
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SSHORTESTDAYNAME1 + nDay - 1, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Windows 7 and later: Short time formatting string for the locale. Patterns are typically
' derived by removing the "ss" (seconds) value from the long time format pattern.
' For example, if the long time format is "h:mm:ss tt", the short time format is most
' likely "h:mm tt". This constant can specify multiple formats in a semicolon-delimited
' list. However, the preferred short time format should be the first value listed.
' ========================================================================================
FUNCTION AfxGetLocaleShortTimeFormatString (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SSHORTTIME, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' The full localized name of the sort for the specified locale identifier, dependent on
' the language of the shell. This constant is used to determine casing and sorting behavior.
' ========================================================================================
FUNCTION AfxGetLocaleSortName (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SSORTNAME, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Characters that are used to separate groups of digits to the left of the decimal. The
' maximum number of characters allowed for this string is four, including a terminating
' null character. Typically, these groups represent thousands. However, depending on the
' value specified for LOCALE_SGROUPING, they can represent something else.
' ========================================================================================
FUNCTION AfxGetLocaleThousandsSeparator (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_STHOUSAND, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Character(s) for the date separator. The maximum number of characters allowed for this
' string is four, including a terminating null character.
' ========================================================================================
FUNCTION AfxGetLocaleDateSeparator (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SDATE, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Time formatting strings for the locale. The maximum number of characters allowed for
' this string is 80, including a terminating null character. The string can consist of a
' combination of hour, minute, and second format pictures.
' ========================================================================================
FUNCTION AfxGetLocaleTimeFormatString (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_STIMEFORMAT, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Character(s) for the time separator. The maximum number of characters allowed for this
' string is four, including a terminating null character.
' ========================================================================================
FUNCTION AfxGetLocaleTimeSeparator (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_STIME, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' The year-month formatting string for the locale. The maximum number of characters allowed
' for this string is 80, including a terminating null character. This string shows the
' proper format for a date string that contains only the year and the month, using format
' pictures as defined in Day, Month, Year, and Era Format Pictures.
' ========================================================================================
FUNCTION AfxGetLocaleYearMonthFormatString (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SYEARMONTH, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Windows 7 and later: Full localized name of the country/region, for example, Deutschland
' for Germany. The maximum number of characters allowed for this string is 80, including a
' terminating null character. Since this name is based on the localization of the product,
' it changes for each localized version.
' ========================================================================================
FUNCTION AfxGetLocalizedCountryName (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SLOCALIZEDCOUNTRYNAME, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Windows 7 and later: Full localized name of the locale for the user interface language,
' for example, Deutsch (Deutschland) for German (Germany)" There is no limit on the number
' of characters allowed for this string. Since this name is based on the localization of
' the product, it changes for each localized version.
' ========================================================================================
FUNCTION AfxGetLocalizedDisplayName (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SLOCALIZEDDISPLAYNAME, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Windows Vista: Full localized primary name of the user interface language included in a
' localized display name, for example, Deutsch representing German. Since this name is
' based on the localization of the product, it changes for each localized version.
' ========================================================================================
FUNCTION AfxGetLocalizedLanguageName (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SLOCALIZEDDISPLAYNAME, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Windows 7 and later: Name of the locale to use for sorting or casing behavior.
' ========================================================================================
FUNCTION AfxGetSortLocale (OPTIONAL BYVAL nLocale AS LONG) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * 260
   IF nLocale = 0 THEN nLocale = %LOCALE_SYSTEM_DEFAULT
   GetLocaleInfoW(nLocale, %LOCALE_SSORTLOCALE, wszBuf, SIZEOF(wszBuf))
   FUNCTION = TRIM$(wszBuf)
END FUNCTION
' ========================================================================================
