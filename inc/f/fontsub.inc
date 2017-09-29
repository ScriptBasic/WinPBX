' ########################################################################################
' Microsoft Windows
' File: fontsub.inc
' Contents: Font subsetting services (fontsub.dll)
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%FONTSUB_INC = 1

'typedef void *(__cdecl *CFP_ALLOCPROC)(size_t);
'FUNCTION CFP_ALLOCPROC CDECL (BYVAL nSize AS DWORD) AS DWORD

'typedef void *(__cdecl *CFP_REALLOCPROC)(void *, size_t);
'FUNCTION CFP_REALLOCPROC CDECL (BYVAL pMemBlock AS DWORD, BYVAL nSize AS DWORD) AS DWORD

'typedef void (__cdecl *CFP_FREEPROC)(void *);
'SUB CFP_FREEPROC CDECL (BYVAL pMemBlock AS DWORD)

'unsigned long __cdecl CreateFontPackage(
'   CONST unsigned char * puchSrcBuffer, ' /* input TTF or TTC buffer */
'   CONST unsigned long ulSrcBufferSize, ' /* size of input TTF or TTC buffer data */
'   unsigned char ** ppuchFontPackageBuffer, ' /* output package buffer */
'   unsigned long * pulFontPackageBufferSize, ' /* output package buffer size */
'   unsigned long * pulBytesWritten,  ' /* output package buffer data length */
'   CONST unsigned short usFlag, ' /* subset, compress, or both, TTF or TTC, Chars or Glyphs */
'   CONST unsigned short usTTCIndex,   ' /* TTC Index, only used if TTC bit set */
'   CONST unsigned short usSubsetFormat, ' /* Old Subset, Subset or Delta */
'   CONST unsigned short usSubsetLanguage,   ' /* Language in Name table to keep */
'   CONST unsigned short usSubsetPlatform,   ' /* if ListType is Character, Platform of cmap to use for glyph list */
'   CONST unsigned short usSubsetEncoding,   ' /* if ListType is Character, Encoding of cmap to use for glyph list */
'   CONST unsigned short *pusSubsetKeepList, ' /* List of Characters or Glyphs to keep */
'   CONST unsigned short usSubsetListCount,    ' /* number of elements in list */
'   CFP_ALLOCPROC lpfnAllocate,     ' /* call back function to allocate temp buffers and output buffers */
'   CFP_REALLOCPROC lpfnReAllocate,     ' /* call back function to reallocate temp and output buffers */
'   CFP_FREEPROC lpfnFree,    ' /* call back function to free buffer allocated with lpfnAllocate and lpfnReAllocate */
'   void * lpvReserved);

DECLARE FUNCTION CreateFontPackage CDECL IMPORT "FontSub.dll" ALIAS "CreateFontPackage" ( _
   BYVAL puchSrcBuffer AS BYTE PTR _           ' CONST unsigned char * puchSrcBuffer /* input TTF or TTC buffer */
 , BYVAL ulSrcBufferSize AS DWORD _            ' CONST unsigned long ulSrcBufferSize /* size of input TTF or TTC buffer data */
 , BYREF ppuchFontPackageBuffer AS DWORD _     ' unsigned char ** ppuchFontPackageBuffer /* output package buffer */
 , BYREF pulFontPackageBufferSize AS DWORD _   ' unsigned long * pulFontPackageBufferSize /* output package buffer size */
 , BYREF pulBytesWritten AS DWORD _            ' unsigned long * pulBytesWritten /* output package buffer data length */
 , BYVAL usFlag AS WORD  _                     ' CONST unsigned short usFlag /* subset, compress, or both, TTF or TTC, Chars or Glyphs */
 , BYVAL usTTCIndex AS WORD  _                 ' CONST unsigned short usTTCIndex /* TTC Index, only used if TTC bit set */
 , BYVAL usSubsetFormat AS WORD  _             ' CONST unsigned short usSubsetFormat /* Old Subset, Subset or Delta */
 , BYVAL usSubsetLanguage AS WORD  _           ' CONST unsigned short usSubsetLanguage /* Language in Name table to keep */
 , BYVAL usSubsetPlatform AS WORD  _           ' CONST unsigned short usSubsetPlatform /* if ListType is Character, Platform of cmap to use for glyph list */
 , BYVAL usSubsetEncoding AS WORD  _           ' CONST unsigned short usSubsetEncoding /* if ListType is Character, Encoding of cmap to use for glyph list */
 , BYREF pusSubsetKeepList AS WORD  _          ' CONST unsigned short *pusSubsetKeepList /* List of Characters or Glyphs to keep */
 , BYVAL usSubsetListCount AS WORD  _          ' CONST unsigned short usSubsetListCount /* number of elements in list */
 , BYVAL lpfnAllocate AS DWORD _               ' CFP_ALLOCPROC lpfnAllocate /* call back function to allocate temp buffers and output buffers */
 , BYVAL lpfnReAllocate AS DWORD _             ' CFP_REALLOCPROC lpfnReAllocate /* call back function to reallocate temp and output buffers */
 , BYVAL lpfnFree AS DWORD _                   ' CFP_FREEPROC lpfnFree /* call back function to free buffer allocated with lpfnAllocate and lpfnReAllocate */
 , BYVAL lpvReserved AS DWORD _                ' void * lpvReserved
 ) AS DWORD                                    ' unsigned long

' /* for usSubsetFormat */
%TTFCFP_SUBSET             = 0??        ' /* Straight Subset Font - Backward compatibility */
%TTFCFP_SUBSET1            = 1??        ' /* Subset font with full TTO and Kern tables. For later merge */
%TTFCFP_DELTA              = 2??        ' /* Delta font, for merge with a subset1 font */

' /* for usSubsetPlatform ID values */
%TTFCFP_UNICODE_PLATFORMID = 0??
%TTFCFP_APPLE_PLATFORMID   = 1??
%TTFCFP_ISO_PLATFORMID     = 2??
%TTFCFP_MS_PLATFORMID      = 3??

' /* for usSubsetEncoding values */
%TTFCFP_STD_MAC_CHAR_SET   = 0??        ' /* goes with TTFSUB_APPLE_PLATFORMID */
%TTFCFP_SYMBOL_CHAR_SET    = 0??        ' /* goes with TTFSUB_MS_PLATFORMID */
%TTFCFP_UNICODE_CHAR_SET   = 1??        ' /* goes with TTFSUB_MS_PLATFORMID */
%TTFCFP_DONT_CARE          = &HFFFF??

' /* for usSubsetLanguage values */
%TTFCFP_LANG_KEEP_ALL      = 0??

'' /* for usFlags values */
%TTFCFP_FLAGS_SUBSET       = &H0001??   ' /* if bit off, don't subset */
%TTFCFP_FLAGS_COMPRESS     = &H0002??   ' /* if bit off, don't compress */
%TTFCFP_FLAGS_TTC          = &H0004??   ' /* if bit off, its a TTF */
%TTFCFP_FLAGS_GLYPHLIST    = &H0008??   ' /* if bit off, list is characters */

'unsigned long __cdecl MergeFontPackage(CONST unsigned char * puchMergeFontBuffer, ' /* buffer containing font to merge with */
'         CONST unsigned long ulMergeFontBufferSize,   ' /* size of buffer containing font to merge with */
'         CONST unsigned char * puchFontPackageBuffer, ' /* buffer containing a font package to merge with the MergeFontBuffer */
'         CONST unsigned long ulFontPackageBufferSize, ' /* length of FontPakageBuffer */
'         unsigned char **ppuchDestBuffer, ' /* output: pointer to output buffer containing a TTF to install */
'         unsigned long *pulDestBufferSize, ' /* output: length of output buffer containing TTF to install */
'         unsigned long *pulBytesWritten, ' /* output: number of bytes in buffer used for TTF */
'         CONST unsigned short usMode, ' /* kind of action to perform, see #defines below */
'         CFP_ALLOCPROC lpfnAllocate,     ' /* call back function to allocate output and intermediate buffers */
'         CFP_REALLOCPROC lpfnReAllocate,     ' /* call back function to allocate or reallocate output and intermediate buffers */
'         CFP_FREEPROC lpfnFree,    ' /* call back function to free buffer allocated with lpfnReAllocate */
'         void *lpvReserved);

DECLARE FUNCTION MergeFontPackage CDECL IMPORT "FontSub.dll" ALIAS "MergeFontPackage" ( _
   BYVAL puchMergeFontBuffer AS BYTE PTR _     ' CONST unsigned char * puchMergeFontBuffer /* buffer containing font to merge with */
 , BYVAL ulMergeFontBufferSize AS DWORD _      ' CONST unsigned long ulMergeFontBufferSize /* size of buffer containing font to merge with */
 , BYVAL puchFontPackageBuffer AS DWORD _      ' CONST unsigned char * puchFontPackageBuffer /* buffer containing a font package to merge with the MergeFontBuffer */
 , BYVAL ulFontPackageBufferSize AS DWORD _    ' CONST unsigned long ulFontPackageBufferSize /* length of FontPakageBuffer */
 , BYREF ppuchDestBuffer AS DWORD _            ' unsigned char **ppuchDestBuffer /* output: pointer to output buffer containing a TTF to install */
 , BYREF pulDestBufferSize AS DWORD _          ' unsigned long *pulDestBufferSize /* output: length of output buffer containing TTF to install */
 , BYREF pulBytesWritten AS DWORD _            ' unsigned long *pulBytesWritten /* output: number of bytes in buffer used for TTF */
 , BYVAL usMode AS WORD _                      ' CONST unsigned short usMode /* kind of action to perform, see #defines below */
 , BYVAL lpfnAllocate AS DWORD _               ' CFP_ALLOCPROC lpfnAllocate /* call back function to allocate output and intermediate buffers */
 , BYVAL lpfnReAllocate AS DWORD _             ' CFP_REALLOCPROC lpfnReAllocate /* call back function to allocate or reallocate output and intermediate buffers */
 , BYVAL lpfnFree AS DWORD _                   ' CFP_FREEPROC lpfnFree /* call back function to free buffer allocated with lpfnReAllocate */
 , BYVAL lpvReserved AS DWORD _                ' void *lpvReserved
 ) AS DWORD                                    ' unsigned long

' /* for usModes */
%TTFMFP_SUBSET             = 0??   ' /* copy a Straight Subset Font package to Dest buffer */
%TTFMFP_SUBSET1            = 1??   ' /* Expand a format 1 font into a format 3 font */
%TTFMFP_DELTA              = 2??   ' /* Merge a format 2 with a format 3 font */

' /* Error codes */
#IF NOT %DEF(%NO_ERROR)
%NO_ERROR = 0
#ENDIF

#IF NOT %DEF(%ERR_GENERIC)
%ERR_GENERIC                 = 1000
%ERR_READOUTOFBOUNDS         = 1001   ' /* trying to read from memory not allowed - data error? */
%ERR_WRITEOUTOFBOUNDS        = 1002   ' /* trying to write to memory not allowed - data error? */
%ERR_READCONTROL             = 1003   ' /* read control structure does not match data */
%ERR_WRITECONTROL            = 1004   ' /* write control structure does not match data */
%ERR_MEM                     = 1005   ' /* error allocating memory */
%ERR_FORMAT                  = 1006   ' /* input data format error */

%ERR_WOULD_GROW              = 1007   ' /* action would cause data to grow. use original data */
%ERR_VERSION                 = 1008   ' /* major dttf.version of the input data is greater than the version this program can read */
%ERR_NO_GLYPHS               = 1009
%ERR_INVALID_MERGE_FORMATS   = 1010   ' /* trying to merge fonts with the wrong dttf formats */
%ERR_INVALID_MERGE_CHECKSUMS = 1011   ' /* trying to merge 2 fonts from different mother font */
%ERR_INVALID_MERGE_NUMGLYPHS = 1012   ' /* trying to merge 2 fonts from different mother font */
%ERR_INVALID_DELTA_FORMAT    = 1013   ' /* trying to subset a format 1 or 2 font */
%ERR_NOT_TTC                 = 1014
%ERR_INVALID_TTC_INDEX       = 1015

%ERR_MISSING_CMAP            = 1030
%ERR_MISSING_GLYF            = 1031
%ERR_MISSING_HEAD            = 1032
%ERR_MISSING_HHEA            = 1033
%ERR_MISSING_HMTX            = 1034
%ERR_MISSING_LOCA            = 1035
%ERR_MISSING_MAXP            = 1036
%ERR_MISSING_NAME            = 1037
%ERR_MISSING_POST            = 1038
%ERR_MISSING_OS2             = 1039
%ERR_MISSING_VHEA            = 1040
%ERR_MISSING_VMTX            = 1041
%ERR_MISSING_HHEA_OR_VHEA    = 1042
%ERR_MISSING_HMTX_OR_VMTX    = 1043
%ERR_MISSING_EBDT            = 1044

%ERR_INVALID_CMAP            = 1060
%ERR_INVALID_GLYF            = 1061
%ERR_INVALID_HEAD            = 1062
%ERR_INVALID_HHEA            = 1063
%ERR_INVALID_HMTX            = 1064
%ERR_INVALID_LOCA            = 1065
%ERR_INVALID_MAXP            = 1066
%ERR_INVALID_NAME            = 1067
%ERR_INVALID_POST            = 1068
%ERR_INVALID_OS2             = 1069
%ERR_INVALID_VHEA            = 1070
%ERR_INVALID_VMTX            = 1071
%ERR_INVALID_HHEA_OR_VHEA    = 1072
%ERR_INVALID_HMTX_OR_VMTX    = 1073

%ERR_INVALID_TTO             = 1080
%ERR_INVALID_GSUB            = 1081
%ERR_INVALID_GPOS            = 1082
%ERR_INVALID_GDEF            = 1083
%ERR_INVALID_JSTF            = 1084
%ERR_INVALID_BASE            = 1085
%ERR_INVALID_EBLC            = 1086
%ERR_INVALID_LTSH            = 1087
%ERR_INVALID_VDMX            = 1088
%ERR_INVALID_HDMX            = 1089

%ERR_PARAMETER0              = 1100   ' /* calling function argument 0 is invalid */
%ERR_PARAMETER1              = 1101   ' /* calling function argument 1 is invalid */
%ERR_PARAMETER2              = 1102   ' /* calling function argument 2 is invalid */
%ERR_PARAMETER3              = 1103   ' /* calling function argument 3 is invalid */
%ERR_PARAMETER4              = 1104   ' /* calling function argument 4 is invalid */
%ERR_PARAMETER5              = 1105   ' /* calling function argument 5 is invalid */
%ERR_PARAMETER6              = 1106   ' /* calling function argument 6 is invalid */
%ERR_PARAMETER7              = 1107   ' /* calling function argument 7 is invalid */
%ERR_PARAMETER8              = 1108   ' /* calling function argument 8 is invalid */
%ERR_PARAMETER9              = 1109   ' /* calling function argument 9 is invalid */
%ERR_PARAMETER10             = 1110   ' /* calling function argument 10 is invalid */
%ERR_PARAMETER11             = 1111   ' /* calling function argument 11 is invalid */
%ERR_PARAMETER12             = 1112   ' /* calling function argument 12 is invalid */
%ERR_PARAMETER13             = 1113   ' /* calling function argument 13 is invalid */
%ERR_PARAMETER14             = 1114   ' /* calling function argument 14 is invalid */
%ERR_PARAMETER15             = 1115   ' /* calling function argument 15 is invalid */
%ERR_PARAMETER16             = 1116   ' /* calling function argument 16 is invalid */
#ENDIF   ' /* ERR_GENERIC */
