' ########################################################################################
' Microsoft Windows
' File: mscat.inc
' Contents: Microsoft Internet Security Catalog API
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MSCAT_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "wincrypt.inc"
#INCLUDE ONCE "mssip.inc"

'/////////////////////////////////////////////////////////////////////////////
'//
'//  defines:
'//
'/////////////////////////////////////////////////////////////////////////////

$szOID_CATALOG_LIST                 = "1.3.6.1.4.1.311.12.1.1"
$szOID_CATALOG_LIST_MEMBER          = "1.3.6.1.4.1.311.12.1.2"

$$CRYPTCAT_FILEEXT                  = "CAT"$$

%CRYPTCAT_MAX_MEMBERTAG             = 64

'//
'//  fdwOpenFlags
'//
%CRYPTCAT_OPEN_CREATENEW             = &H00000001???  ' // creates/overwrites
%CRYPTCAT_OPEN_ALWAYS                = &H00000002???  ' // opens/creates
%CRYPTCAT_OPEN_EXISTING              = &H00000004???  ' // opens only

%CRYPTCAT_OPEN_EXCLUDE_PAGE_HASHES   = &H00010000???  ' // Exclude page hashes in SPC_INDIRECT_DATA

'// The above CRYPTCAT_OPEN_EXCLUDE_PAGE_HASHES takes precedence if also set.
%CRYPTCAT_OPEN_INCLUDE_PAGE_HASHES   = &H00020000???  ' // Include page hashes in SPC_INDIRECT_DATA
%CRYPTCAT_OPEN_VERIFYSIGHASH         = &H10000000???  ' // verifies the signature (not the certs!)

%CRYPTCAT_OPEN_NO_CONTENT_HCRYPTMSG  = &H20000000???  ' // does CryptMsgDecode without content
%CRYPTCAT_OPEN_SORTED                = &H40000000???  ' // does CertCreateContext(CERT_CREATE_CONTEXT_SORTED_FLAG)

%CRYPTCAT_OPEN_FLAGS_MASK            = &Hffff0000???  ' // mask for upper word

'//
'//  fdwMemberFlags  (used internal -- do not fill)
'//

%CRYPTCAT_MEMBER_SORTED              = &H40000000???

'//
'//  dwAttrTypeAndAction
'//
%CRYPTCAT_ATTR_AUTHENTICATED         = &H10000000???
%CRYPTCAT_ATTR_UNAUTHENTICATED       = &H20000000???

%CRYPTCAT_ATTR_NAMEASCII             = &H00000001???  ' // ascii string
%CRYPTCAT_ATTR_NAMEOBJID             = &H00000002???  ' // crypt obj id

%CRYPTCAT_ATTR_DATAASCII             = &H00010000???  ' // do not decode simple ascii chars
%CRYPTCAT_ATTR_DATABASE64            = &H00020000???  ' // base 64
%CRYPTCAT_ATTR_DATAREPLACE           = &H00040000???  ' // this data is a replacment for an existing attr

'//
'//  dwLocalError - CDF Parse
'//
%CRYPTCAT_E_AREA_HEADER              = &H00000000???
%CRYPTCAT_E_AREA_MEMBER              = &H00010000???
%CRYPTCAT_E_AREA_ATTRIBUTE           = &H00020000???

%CRYPTCAT_E_CDF_UNSUPPORTED          = &H00000001???
%CRYPTCAT_E_CDF_DUPLICATE            = &H00000002???
%CRYPTCAT_E_CDF_TAGNOTFOUND          = &H00000004???

%CRYPTCAT_E_CDF_MEMBER_FILE_PATH     = &H00010001???
%CRYPTCAT_E_CDF_MEMBER_INDIRECTDATA  = &H00010002???
%CRYPTCAT_E_CDF_MEMBER_FILENOTFOUND  = &H00010004???

%CRYPTCAT_E_CDF_BAD_GUID_CONV        = &H00020001???
%CRYPTCAT_E_CDF_ATTR_TOOFEWVALUES    = &H00020002???
%CRYPTCAT_E_CDF_ATTR_TYPECOMBO       = &H00020004???


'/////////////////////////////////////////////////////////////////////////////
'//
'//  structures:
'//
'/////////////////////////////////////////////////////////////////////////////

'#include <pshpack8.h>

' Also declared in mssip.inc
#IF NOT %DEF(%SIP_INDIRECT_DATA_DEFINED)
%SIP_INDIRECT_DATA_DEFINED = 1
' // Size = 32 bytes
TYPE SIP_INDIRECT_DATA DWORD
   Data            AS CRYPT_ATTRIBUTE_TYPE_VALUE
   DigestAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER
   Digest          AS CRYPT_HASH_BLOB
END TYPE
#ENDIF

' Also declared in mssip.inc
#IF NOT %DEF(%CRYPTCATSTORE_DEFINED)
%CRYPTCATSTORE_DEFINED = 1
' // Size = 40 bytes
TYPE CRYPTCATSTORE DWORD
   cbStruct        AS DWORD          ' DWORD  // = sizeof(CRYPTCATSTORE)
   dwPublicVersion AS DWORD          ' DWORD
   pwszP7File      AS WSTRINGZ PTR   ' LPWSTR
   hProv           AS DWORD          ' HCRYPTPROV
   dwEncodingType  AS DWORD          ' DWORD
   fdwStoreFlags   AS DWORD          ' DWORD
   hReserved       AS DWORD          ' HANDLE // pStack(members) (null if init/pbData) INTERNAL!
   hAttrs          AS DWORD          ' HANDLE // pStack(Catalog attrs) INTERNAL!
   ' // Following is only set if opened with CRYPTCAT_OPEN_NO_CONTENT_HCRYPTMSG
   hCryptMsg       AS DWORD          ' HCRYPTMSG
   ' // Following is only set if opened with CRYPTCAT_OPEN_SORTED
   hSorted         AS DWORD          ' HANDLE // INTERNAL ONLY!
END TYPE
#ENDIF

' Also declared in mssip.inc
#IF NOT %DEF(%CRYPTCATMEMBER_DEFINED)
%CRYPTCATMEMBER_DEFINED = 1
' // Size = 64 bytes
TYPE CRYPTCATMEMBER DWORD
   cbStruct             AS DWORD                   ' DWORD   // = sizeof(CRYPTCATMEMBER)
   pwszReferenceTag     AS WSTRINGZ PTR            ' LPWSTR
   pwszFileName         AS WSTRINGZ PTR            ' LPWSTR  // used only by the CDF APIs
   gSubjectType         AS GUID                    ' GUID    // may be zeros -- see sEncodedMemberInfo
   fdwMemberFlags       AS DWORD                   ' DWORD
   pIndirectData        AS SIP_INDIRECT_DATA PTR   ' struct SIP_INDIRECT_DATA_* // may be null -- see sEncodedIndirectData
   dwCertVersion        AS DWORD                   ' DWORD   // may be zero -- see sEncodedMemberInfo
   dwReserved           AS DWORD                   ' DWORD   // used by enum -- DO NOT USE!
   hReserved            AS DWORD                   ' HANDLE  // pStack(attrs) (null if init) INTERNAL!
   sEncodedIndirectData AS CRYPT_ATTR_BLOB         ' CRYPT_ATTR_BLOB // lazy decode
   sEncodedMemberInfo   AS CRYPT_ATTR_BLOB         ' CRYPT_ATTR_BLOB // lazy decode
END TYPE
#ENDIF

' // Size = 24 bytes
TYPE CRYPTCATATTRIBUTE DWORD
   cbStruct            AS DWORD          ' DWORD   // = sizeof(CRYPTCATATTRIBUTE)
   pwszReferenceTag    AS WSTRINGZ PTR   ' LPWSTR
   dwAttrTypeAndAction AS DWORD          ' DWORD
   cbValue             AS DWORD          ' DWORD
   pbValue             AS BYTE PTR       ' BYTE*   // encoded CAT_NAMEVALUE struct
   dwReserved          AS DWORD          ' DWORD   // used by enum -- DO NOT USE!
END TYPE

' // Size = 28 bytes
TYPE CRYPTCATCDF DWORD
   cbStruct           AS DWORD          ' DWORD  // = sizeof(CRYPTCATCDF)
   hFile              AS DWORD          ' HANDLE
   dwCurFilePos       AS DWORD          ' DWORD
   dwLastMemberOffset AS DWORD          ' DWORD
   fEOF               AS LONG           ' BOOL
   pwszResultDir      AS WSTRINGZ PTR   ' LPWSTR
   hCATStore          AS DWORD          ' HANDLE
END TYPE

' // Size = 524 bytes
TYPE CATALOG_INFO DWORD
   cbStruct       AS DWORD                  ' DWORD  // set to sizeof(CATALOG_INFO)
   wszCatalogFile AS WSTRINGZ * %MAX_PATH   ' WCHAR
END TYPE

'typedef HANDLE          HCATADMIN;
'typedef HANDLE          HCATINFO;

'#include <poppack.h>

'typedef void (WINAPI *PFN_CDF_PARSE_ERROR_CALLBACK)(IN DWORD dwErrorArea,
'                                                    IN DWORD dwLocalError,
'                                                    IN WCHAR *pwszLine);

'SUB CDF_PARSE_ERROR_CALLBACK (BYVAL dwErrorArea AS DWORD, BYVAL dwLocalError AS DWORD, BYVAL pwszLine AS DWORD)

'/////////////////////////////////////////////////////////////////////////////
'//
'//  Prototypes:
'//
'/////////////////////////////////////////////////////////////////////////////

'/////////////////////////////////////////////////////////////////////////////
'//
'//  Open:
'// --------------------------------------------------------------------------
'//  Usage:
'//      open the catalog for Get/Put operations.
'//
'//  Return:
'//      INVALID_HANDLE_VALUE:           an error occured while opening Catalog
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//

DECLARE FUNCTION CryptCATOpen IMPORT "WINTRUST.DLL" ALIAS "CryptCATOpen" ( _
   BYREF pwszFileName AS WSTRINGZ _                     ' __in     LPWSTR pwszFileName
 , BYVAL fdwOpenFlags AS DWORD _                        ' __in     DWORD fdwOpenFlags
 , BYVAL hProv AS DWORD _                               ' __in_opt HCRYPTPROV hProv
 , BYVAL dwPublicVersion AS DWORD _                     ' __in_opt DWORD dwPublicVersion
 , BYVAL dwEncodingType AS DWORD _                      ' __in_opt DWORD dwEncodingType
 ) AS DWORD                                             ' HANDLE

'/////////////////////////////////////////////////////////////////////////////
'//
'//  Close:
'// --------------------------------------------------------------------------
'//  Usage:
'//      close the catalog handle.
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//

DECLARE FUNCTION CryptCATClose IMPORT "WINTRUST.DLL" ALIAS "CryptCATClose" ( _
   BYVAL hCatalog AS DWORD _                            ' __in HANDLE hCatalog
 ) AS LONG                                              ' BOOL

'// WOB #1496767
'/////////////////////////////////////////////////////////////////////////////
'//
'//  Set or clear page-hashes bit:
'// --------------------------------------------------------------------------
'//  Usage:
'//      set a new value into the bit that suppresses page-hash generation.
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//

DECLARE FUNCTION CryptCATSetCreatePageHashesFlag IMPORT "WINTRUST.DLL" ALIAS "CryptCATSetCreatePageHashesFlag" ( _
   BYVAL hCatalog AS DWORD _                            ' __in HANDLE hCatalog
 , BYVAL newCreatePageHashesFlag AS LONG _              ' __in BOOL newCreatePageHashesFlag
 ) AS LONG                                              ' BOOL

'/////////////////////////////////////////////////////////////////////////////
'//
'//  StoreFromHandle:
'// --------------------------------------------------------------------------
'//  Usage:
'//      retrieve the CRYPTCATSTORE from the store handle.
'//
'//          *** DO NOT FREE THE POINTER OR ANY OF ITS MEMBERS! ***
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//

DECLARE FUNCTION CryptCATStoreFromHandle IMPORT "WINTRUST.DLL" ALIAS "CryptCATStoreFromHandle" ( _
   BYVAL hCatalog AS DWORD _                            ' __in HANDLE hCatalog
 ) AS DWORD                                             ' CRYPTCATSTORE*

'/////////////////////////////////////////////////////////////////////////////
'//
'// HandleFromStore:
'// --------------------------------------------------------------------------
'//  Usage:
'//      retrieve the handle from a CRYPTCATSTORE pointer.
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//

DECLARE FUNCTION CryptCATHandleFromStore IMPORT "WINTRUST.DLL" ALIAS "CryptCATHandleFromStore" ( _
   BYREF pCatStore AS CRYPTCATSTORE _                   ' __in CRYPTCATSTORE *pCatStore
 ) AS DWORD                                             ' HANDLE

'/////////////////////////////////////////////////////////////////////////////
'//
'//  PersistStore
'// --------------------------------------------------------------------------
'//  Usage:
'//      Persist the information in the current Catalog Store to an unsigned
'//      Catalog File. It is REQUIRED to fill in the pwszP7File member
'//      of CRYPTCATSTORE prior to this call!
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//

DECLARE FUNCTION CryptCATPersistStore IMPORT "WINTRUST.DLL" ALIAS "CryptCATPersistStore" ( _
   BYVAL hCatalog AS DWORD _                            ' __in HANDLE hCatalog
 ) AS LONG                                              ' BOOL

'/////////////////////////////////////////////////////////////////////////////
'//
'//  CryptCATGetCatAttrInfo
'// --------------------------------------------------------------------------
'//  Usage:
'//
'//          *** DO NOT FREE THE POINTER OR ANY OF ITS MEMBERS! ***
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//

DECLARE FUNCTION CryptCATGetCatAttrInfo IMPORT "WINTRUST.DLL" ALIAS "CryptCATGetCatAttrInfo" ( _
   BYVAL hCatalog AS DWORD _                            ' __in HANDLE hCatalog
 , BYREF pwszReferenceTag AS WSTRINGZ _                 ' __in LPWSTR pwszReferenceTag
 ) AS DWORD                                             ' CRYPTCATATTRIBUTE*

'/////////////////////////////////////////////////////////////////////////////
'//
'//  CryptCATPutCatAttrInfo
'// --------------------------------------------------------------------------
'//  Usage:
'//      Allocates and adds the attribute to the catalog.  Returns a pointer
'//      to the allocated attribute.
'//
'//          *** DO NOT FREE THE POINTER OR ANY OF ITS MEMBERS! ***
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//

DECLARE FUNCTION CryptCATPutCatAttrInfo IMPORT "WINTRUST.DLL" ALIAS "CryptCATPutCatAttrInfo" ( _
   BYVAL hCatalog AS DWORD _                            ' __in HANDLE hCatalog
 , BYREF pwszReferenceTag AS WSTRINGZ _                 ' __in LPWSTR pwszReferenceTag
 , BYVAL dwAttrTypeAndAction AS DWORD _                 ' __in DWORD dwAttrTypeAndAction
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 , BYVAL pbData AS BYTE PTR _                           ' __in BYTE *pbData
 ) AS DWORD                                             ' CRYPTCATATTRIBUTE*

'/////////////////////////////////////////////////////////////////////////////
'//
'//  CryptCATEnumerateCatAttr
'// --------------------------------------------------------------------------
'//  Usage:
'//      Enumerates through the list of attributes associated with the catalog.
'//      Returns a pointer to the attribute. This return should be passed in
'//      as the 'PrevAttr' to continue the enumeration.  On the first call,
'//      the 'PrevAttr' should be set to NULL.
'//
'//          *** DO NOT FREE THE POINTER OR ANY OF ITS MEMBERS! ***
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//

DECLARE FUNCTION CryptCATEnumerateCatAttr IMPORT "WINTRUST.DLL" ALIAS "CryptCATEnumerateCatAttr" ( _
   BYVAL hCatalog AS DWORD _                            ' __in HANDLE hCatalog
 , BYREF pPrevAttr AS CRYPTCATATTRIBUTE _               ' __in CRYPTCATATTRIBUTE *pPrevAttr
 ) AS DWORD                                             ' CRYPTCATATTRIBUTE*

'/////////////////////////////////////////////////////////////////////////////
'//
'//  CryptCATGetMemberInfo
'// --------------------------------------------------------------------------
'//  Usage:
'//      Retrieve the Tag info (member info) structure from the catalog
'//      PKCS#7, fill the CRYPTCATMEMBER structure, and return. -- Opens a
'//      member context.
'//
'//          *** DO NOT FREE THE POINTER OR ANY OF ITS MEMBERS! ***
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//

DECLARE FUNCTION CryptCATGetMemberInfo IMPORT "WINTRUST.DLL" ALIAS "CryptCATGetMemberInfo" ( _
   BYVAL hCatalog AS DWORD _                            ' __in HANDLE hCatalog
 , BYREF pwszReferenceTag AS WSTRINGZ _                 ' __in LPWSTR pwszReferenceTag
 ) AS DWORD                                             ' CRYPTCATMEMBER*

'/////////////////////////////////////////////////////////////////////////////
'//
'//  CryptCATAllocSortedMemberInfo
'// --------------------------------------------------------------------------
'//  Usage:
'//      If CryptCATOpen is called with CRYPTCAT_OPEN_SORTED, this function
'//      must be called instead of the above CryptCATGetMemberInfo().
'//
'//      The returned member context must be freed by calling
'//      CryptCATFreeSortedMemberInfo()
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//

DECLARE FUNCTION CryptCATAllocSortedMemberInfo IMPORT "WINTRUST.DLL" ALIAS "CryptCATAllocSortedMemberInfo" ( _
   BYVAL hCatalog AS DWORD _                            ' __in HANDLE hCatalog
 , BYREF pwszReferenceTag AS WSTRINGZ _                 ' __in LPWSTR pwszReferenceTag
 ) AS DWORD                                             ' CRYPTCATMEMBER*

'/////////////////////////////////////////////////////////////////////////////
'//
'//  CryptCATFreeSortedMemberInfo
'// --------------------------------------------------------------------------
'//  Usage:
'//      Free member context returned by the above
'//      CryptCATAllocSortedMemberInfo().
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//

DECLARE SUB CryptCATFreeSortedMemberInfo IMPORT "WINTRUST.DLL" ALIAS "CryptCATFreeSortedMemberInfo" ( _
   BYVAL hCatalog AS DWORD _                            ' __in HANDLE hCatalog
 , BYREF pCatMember AS CRYPTCATMEMBER _                 ' __in CRYPTCATMEMBER *pCatMember
 )                                                      ' void

'/////////////////////////////////////////////////////////////////////////////
'//
'//  CryptCATGetAttr:
'// --------------------------------------------------------------------------
'//  Usage:
'//      get pwszReferenceTag attribute information for a member.
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//

DECLARE FUNCTION CryptCATGetAttrInfo IMPORT "WINTRUST.DLL" ALIAS "CryptCATGetAttrInfo" ( _
   BYVAL hCatalog AS DWORD _                            ' __in HANDLE hCatalog
 , BYREF pCatMember AS CRYPTCATMEMBER _                 ' __in CRYPTCATMEMBER *pCatMember
 , BYREF pwszReferenceTag AS WSTRINGZ _                 ' __in LPWSTR pwszReferenceTag
 ) AS DWORD                                             ' CRYPTCATATTRIBUTE*

'/////////////////////////////////////////////////////////////////////////////
'//
'//  CryptCATPutMemberInfo
'// --------------------------------------------------------------------------
'//  Usage:
'//      Allocates and adds the member to the catalog.  Returns a pointer
'//      to the allocated member.
'//
'//          *** DO NOT FREE THE POINTER OR ANY OF ITS MEMBERS! ***
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//      CRYPT_E_EXISTS:                 the reference tag already exists
'//      CRYPT_E_NOT_FOUND:              the attr was not found
'//

DECLARE FUNCTION CryptCATPutMemberInfo IMPORT "WINTRUST.DLL" ALIAS "CryptCATPutMemberInfo" ( _
   BYVAL hCatalog AS DWORD _                            ' __in HANDLE hCatalog
 , BYREF pwszFileName AS WSTRINGZ _                     ' __in_opt LPWSTR pwszFileName
 , BYREF pwszReferenceTag AS WSTRINGZ _                 ' __in LPWSTR pwszReferenceTag
 , BYREF pgSubjectType AS GUID _                        ' __in GUID *pgSubjectType
 , BYVAL dwCertVersion AS DWORD _                       ' __in DWORD dwCertVersion
 , BYVAL cbSIPIndirectData AS DWORD _                   ' __in DWORD cbSIPIndirectData
 , BYVAL pbSIPIndirectData AS BYTE PTR _                ' __in BYTE *pbSIPIndirectData
 ) AS DWORD                                             ' CRYPTCATMEMBER*

'/////////////////////////////////////////////////////////////////////////////
'//
'//  CryptCATPutAttrInfo
'// --------------------------------------------------------------------------
'//  Usage:
'//      Allocates and adds the attribute to the member.  Returns a pointer
'//      to the allocated attribute.
'//
'//          *** DO NOT FREE THE POINTER OR ANY OF ITS MEMBERS! ***
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//

DECLARE FUNCTION CryptCATPutAttrInfo IMPORT "WINTRUST.DLL" ALIAS "CryptCATPutAttrInfo" ( _
   BYVAL hCatalog AS DWORD _                            ' __in HANDLE hCatalog
 , BYREF pCatMember AS CRYPTCATMEMBER _                 ' __in CRYPTCATMEMBER *pCatMember
 , BYREF pwszReferenceTag AS WSTRINGZ _                 ' __in LPWSTR pwszReferenceTag
 , BYVAL dwAttrTypeAndAction AS DWORD _                 ' __in DWORD dwAttrTypeAndAction
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 , BYVAL pbData AS BYTE PTR _                           ' __in BYTE *pbData
 ) AS DWORD                                             ' CRYPTCATATTRIBUTE*

'/////////////////////////////////////////////////////////////////////////////
'//
'//  CryptCATEnumerateMember
'// --------------------------------------------------------------------------
'//  Usage:
'//      Enumerates through the list of members in the store.  Returns a pointer
'//      to the member. This return should be passed in as the 'PrevMember' to
'//      continue the enumeration.  On the first call, the 'PrevMember' should
'//      be set to NULL.
'//
'//          *** DO NOT FREE THE POINTER OR ANY OF ITS MEMBERS! ***
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//

DECLARE FUNCTION CryptCATEnumerateMember IMPORT "WINTRUST.DLL" ALIAS "CryptCATEnumerateMember" ( _
   BYVAL hCatalog AS DWORD _                            ' __in HANDLE hCatalog
 , BYREF pPrevMember AS CRYPTCATMEMBER _                ' __in CRYPTCATMEMBER *pPrevMember
 ) AS DWORD                                             ' CRYPTCATMEMBER*

'/////////////////////////////////////////////////////////////////////////////
'//
'//  CryptCATEnumerateAttr
'// --------------------------------------------------------------------------
'//  Usage:
'//      Enumerates through the list of attributes associated with the member.
'//      Returns a pointer to the attribute. This return should be passed in
'//      as the 'PrevAttr' to continue the enumeration.  On the first call,
'//      the 'PrevAttr' should be set to NULL.
'//
'//          *** DO NOT FREE THE POINTER OR ANY OF ITS MEMBERS! ***
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//

DECLARE FUNCTION CryptCATEnumerateAttr IMPORT "WINTRUST.DLL" ALIAS "CryptCATEnumerateAttr" ( _
   BYVAL hCatalog AS DWORD _                            ' __in HANDLE hCatalog
 , BYREF pCatMember AS CRYPTCATMEMBER _                 ' __in CRYPTCATMEMBER *pCatMember
 , BYREF pPrevAttr AS CRYPTCATATTRIBUTE _               ' __in CRYPTCATATTRIBUTE *pPrevAttr
 ) AS DWORD                                             ' CRYPTCATATTRIBUTE*

'/////////////////////////////////////////////////////////////////////////////
'//
'//  CryptCATCDFOpen
'// --------------------------------------------------------------------------
'//  Usage:
'//      Opens the specified CDF file and initialized the structure
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//      ERROR_FILE_NOT_FOUND:           the CDF file was not found
'//

DECLARE FUNCTION CryptCATCDFOpen IMPORT "WINTRUST.DLL" ALIAS "CryptCATCDFOpen" ( _
   BYREF pwszFilePath AS WSTRINGZ _                     ' __in LPWSTR pwszFilePath
 , BYVAL pfnParseError AS DWORD _                       ' __in_opt PFN_CDF_PARSE_ERROR_CALLBACK pfnParseError
 ) AS DWORD                                             ' CRYPTCATCDF*

'/////////////////////////////////////////////////////////////////////////////
'//
'//  CryptCATCDFClose
'// --------------------------------------------------------------------------
'//  Usage:
'//      Closes the CDF file and deallocates the structure
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//

DECLARE FUNCTION CryptCATCDFClose IMPORT "WINTRUST.DLL" ALIAS "CryptCATCDFClose" ( _
   BYREF pCDF AS CRYPTCATCDF _                          ' __in CRYPTCATCDF *pCDF
 ) AS LONG                                              ' BOOL

'/////////////////////////////////////////////////////////////////////////////
'//
'//  CryptCATCDFEnumCatAttributes
'// --------------------------------------------------------------------------
'//  Usage:
'//      Enumerates Catalog level attributes within the "[CatalogFiles]"
'//      section of the CDF.
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//

DECLARE FUNCTION CryptCATCDFEnumCatAttributes IMPORT "WINTRUST.DLL" ALIAS "CryptCATCDFEnumCatAttributes" ( _
   BYREF pCDF AS CRYPTCATCDF _                          ' __in CRYPTCATCDF *pCDF
 , BYREF pPrevAttr AS CRYPTCATATTRIBUTE _               ' __in CRYPTCATATTRIBUTE *pPrevAttr
 , BYVAL pfnParseError AS DWORD _                       ' __in PFN_CDF_PARSE_ERROR_CALLBACK pfnParseError
 ) AS DWORD                                             ' CRYPTCATATTRIBUTE*

'/////////////////////////////////////////////////////////////////////////////
'//
'//  CryptCATCDFEnumMembers
'// --------------------------------------------------------------------------
'//  Usage:
'//      Enumerates files within the "[CatalogFiles]" section of the CDF.
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//

DECLARE FUNCTION CryptCATCDFEnumMembers IMPORT "WINTRUST.DLL" ALIAS "CryptCATCDFEnumMembers" ( _
   BYREF pCDF AS CRYPTCATCDF _                          ' __in CRYPTCATCDF *pCDF
 , BYREF pPrevMember AS CRYPTCATMEMBER _                ' __in CRYPTCATMEMBER *pPrevMember
 , BYVAL pfnParseError AS DWORD _                       ' __in_opt PFN_CDF_PARSE_ERROR_CALLBACK pfnParseError
 ) AS DWORD                                             ' CRYPTCATMEMBER*

'/////////////////////////////////////////////////////////////////////////////
'//
'//  CryptCATCDFEnumAttributes
'// --------------------------------------------------------------------------
'//  Usage:
'//      Enumerates the files attributes within the "[CatalogFiles]" section
'//      of the CDF.
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//

DECLARE FUNCTION CryptCATCDFEnumAttributes IMPORT "WINTRUST.DLL" ALIAS "CryptCATCDFEnumAttributes" ( _
   BYREF pCDF AS CRYPTCATCDF _                          ' __in CRYPTCATCDF *pCDF
 , BYREF pPrevMember AS CRYPTCATMEMBER _                ' __in CRYPTCATMEMBER *pPrevMember
 , BYREF pPrevAttr AS CRYPTCATATTRIBUTE _               ' __in CRYPTCATATTRIBUTE *pPrevAttr
 , BYVAL pfnParseError AS DWORD _                       ' __in_opt PFN_CDF_PARSE_ERROR_CALLBACK pfnParseError
 ) AS DWORD                                             ' CRYPTCATATTRIBUTE*

'//////////////////////////////////////////////////////////////////////////
'//
'//  IsCatalogFile
'// --------------------------------------------------------------------------
'//  Usage:
'//      Call this function to determine if the file is a Catalog File.  Both
'//      parameters are optional.  HOWEVER, one of them MUST be passed!
'//
'//  Return:
'//      TRUE if it is.
'//      FALSE if it isn't or an error occured.
'//
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//      ERROR_NOT_ENOUGH_MEMORY:        a memory allocation failed
'//      {file errors}                   a file error occured
'//

DECLARE FUNCTION IsCatalogFile IMPORT "WINTRUST.DLL" ALIAS "IsCatalogFile" ( _
   BYVAL hFile AS DWORD _                               ' __in_opt HANDLE hFile
 , BYVAL pwszFileName AS DWORD _                        ' __in_opt WCHAR *pwszFileName
 ) AS LONG                                              ' BOOL

'//////////////////////////////////////////////////////////////////////////
'//
'//  CryptCATAdminAcquireContext
'// --------------------------------------------------------------------------
'//  Usage:
'//      Opens a new Admin Context based on the pgSubsystem Id.
'//
'//      the Guid passed in will be converted to a string and used as the
'//      sub-directory under %SystemRoot%\CatRoot to store all Catalog files
'//      for this app/sub-system.
'//
'//      if a NULL is passed in to the pgSubsystem parameter, all finds will be
'//      "global" and any Adds will be under the "default" Subsystem.
'//
'//  Return:
'//      TRUE if phCatAdmin points to a valid context.
'//      FALSE if an error occurs.
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//      ERROR_NOT_ENOUGH_MEMORY:        a memory allocation failed
'//      ERROR_DATABASE_FAILURE:         an error occured while processing
'//                                      the database.
'//
'//  Comments:
'//          The dwFlags parameter is reserved for future use.  Must
'//          be set to NULL.
'//
'//

DECLARE FUNCTION CryptCATAdminAcquireContext IMPORT "WINTRUST.DLL" ALIAS "CryptCATAdminAcquireContext" ( _
   BYREF phCatAdmin AS DWORD _                          ' __out HCATADMIN *phCatAdmin
 , BYREF pgSubsystem AS GUID _                          ' __in  const GUID *pgSubsystem
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
 ) AS LONG                                              ' BOOL

'//////////////////////////////////////////////////////////////////////////
'//
'//  CryptCATAdminReleaseContext
'// --------------------------------------------------------------------------
'//  Usage:
'//      Releases (frees) all information related to the Admin Context
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//
'//  Comments:
'//          The dwFlags parameter is reserved for future use.  Must
'//          be set to NULL.
'//

DECLARE FUNCTION CryptCATAdminReleaseContext IMPORT "WINTRUST.DLL" ALIAS "CryptCATAdminReleaseContext" ( _
   BYVAL hCatAdmin AS DWORD _                           ' __in HCATADMIN hCatAdmin
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

'//////////////////////////////////////////////////////////////////////////
'//
'//  CryptCATAdminReleaseCatalogContext
'// -----------------------------------------------------------------------
'//  Usage:
'//      Call this function to release memory associated with the Catalog
'//      Info Context.
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//
'//  Comments:
'//      the dwFlags parameter is reserved for future use and must be assigned
'//      to NULL.
'//

DECLARE FUNCTION CryptCATAdminReleaseCatalogContext IMPORT "WINTRUST.DLL" ALIAS "CryptCATAdminReleaseCatalogContext" ( _
   BYVAL hCatAdmin AS DWORD _                           ' __in HCATADMIN hCatAdmin
 , BYVAL hCatInfo AS DWORD _                            ' __in HCATINFO hCatInfo
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

'//////////////////////////////////////////////////////////////////////////
'//
'//  CryptCATAdminEnumCatalogFromHash
'// --------------------------------------------------------------------------
'//  Usage:
'//      Call this function to retrieve the Catalog Info handle of the Catalog
'//      file that currently "points" to the specified Member Hash.
'//
'//      if hCatInfo is NULL, the first catalog found that contains the
'//      hash will be returned.
'//
'//      if hCatInfo is not NULL, the content must be initialized to NULL prior
'//      to going into the enum loop -- this starts the first/next search.
'//      This function uses this parameter to determine the last catalog returned.
'//
'//      if hCatInfo is not NULL, and the loop is terminated prior to this
'//      function returning NULL, the application must call
'//      CryptCATAdminReleaseCatalogContext to free all memory associated with
'//      ppPrevContext.
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//      ERROR_NOT_ENOUGH_MEMORY:        a memory allocation failed
'//      ERROR_DATABASE_FAILURE:         an error occurred while processing
'//                                      the database.
'//

DECLARE FUNCTION CryptCATAdminEnumCatalogFromHash IMPORT "WINTRUST.DLL" ALIAS "CryptCATAdminEnumCatalogFromHash" ( _
   BYVAL hCatAdmin AS DWORD _                           ' __in HCATADMIN hCatAdmin
 , BYVAL pbHash AS BYTE PTR _                           ' __in BYTE *pbHash
 , BYVAL cbHash AS DWORD _                              ' __in DWORD cbHash
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF phPrevCatInfo AS DWORD _                       ' __in_out HCATINFO *phPrevCatInfo
 ) AS DWORD                                             ' HCATINFO

'//////////////////////////////////////////////////////////////////////////
'//
'//  CryptCATAdminCalcHashFromFileHandle
'// --------------------------------------------------------------------------
'//  Usage:
'//      Call this function to calculate the has based on an open file handle.
'//
'//  Return:
'//      TRUE if the pbHash was filled with the calculated hash.
'//      FALSE if an error occured
'//
'//      To obtain the size required for pbHash, set pbHash to NULL.  The
'//      correct size will be returned in pcbHash, the return value will
'//      be TRUE and a call to GetLastError() will equal ERROR_INSUFFICIENT_BUFFER.
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//      ERROR_INSUFFICIENT_BUFFER:      the *pbHash was not big enough.
'//      ERROR_NOT_ENOUGH_MEMORY:        a memory allocation failed
'//
'//  Comments:
'//      the dwFlags parameter is reserved for future use and must be assigned
'//      to NULL.
'//

DECLARE FUNCTION CryptCATAdminCalcHashFromFileHandle IMPORT "WINTRUST.DLL" ALIAS "CryptCATAdminCalcHashFromFileHandle" ( _
   BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
 , BYREF pcbHash AS DWORD _                             ' __in_out DWORD *pcbHash
 , BYVAL pbHash AS BYTE PTR _                           ' __out_opt BYTE *pbHash
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

'//////////////////////////////////////////////////////////////////////////
'//
'//  CryptCATAdminAddCatalog
'// --------------------------------------------------------------------------
'//  Usage:
'//      Call this function to add a catalog file to the CAT Maintenance
'//      subsystem.
'//
'//      if the pwszSelectedBaseName is NULL, the Catalog Admin system will
'//      generate a file base name for you.  Otherwise, this parameter is
'//      used as the file name (base & extension only) of the copied Catalog
'//      file.
'//
'//      Call CryptCATAdminReleaseCatalogContext to free the memory associated
'//      with the Catalog Context returned if not NULL.
'//
'//  Return:
'//      On success, the HCATINFO of the catalog that was successfully added
'//      is returned.  On failure, NULL is returned.
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//      ERROR_NOT_ENOUGH_MEMORY:        a memory allocation failed
'//      ERROR_BAD_FORMAT:               the file is not a catalog file.
'//      ERROR_DATABASE_FAILURE:         an error occurred while processing
'//                                      the database.
'//
'//  Comments:
'//      the dwFlags parameter is reserved for future use and must be assigned
'//      to NULL.
'//

DECLARE FUNCTION CryptCATAdminAddCatalog IMPORT "WINTRUST.DLL" ALIAS "CryptCATAdminAddCatalog" ( _
   BYVAL hCatAdmin AS DWORD _                           ' __in HCATADMIN hCatAdmin
 , BYVAL pwszCatalogFile AS DWORD _                     ' __in WCHAR *pwszCatalogFile
 , BYVAL pwszSelectBaseName AS DWORD _                  ' __in_opt WCHAR *pwszSelectBaseName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' HCATINFO

'//////////////////////////////////////////////////////////////////////////
'//
'//  CryptCATAdminRemoveCatalog
'// --------------------------------------------------------------------------
'//  Usage:
'//      Call this function to remove a catalog file from the CAT Maintenance
'//      subsystem.
'//
'//  Return:
'//      On success, TRUE is returned.  FALSE if an error occurs.
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//
'//  Comments:
'//      pwszCatalogFile must point to a string that contains only the name
'//      of the catalog file, ex. "foo.cat", and not a fully qualified path
'//      name
'//

DECLARE FUNCTION CryptCATAdminRemoveCatalog IMPORT "WINTRUST.DLL" ALIAS "CryptCATAdminRemoveCatalog" ( _
   BYVAL hCatAdmin AS DWORD _                           ' __in HCATADMIN hCatAdmin
 , BYREF pwszCatalogFile AS WSTRINGZ _                  ' __in LPCWSTR pwszCatalogFile
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

'//////////////////////////////////////////////////////////////////////////
'//
'//  CryptCATCatalogInfoFromContext
'// --------------------------------------------------------------------------
'//  Usage:
'//      call this function to retrieve information relating to the
'//      Catalog info handle passed from the Add Catalog function.
'//
'//  Return:
'//      On success, TRUE is returned and the CATALOG_INFO structure
'//      is filled in.
'//      FALSE if an error occurs.
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//
'//  Comments:
'//      the dwFlags parameter is reserved for future use and must be assigned
'//      to NULL.
'//

DECLARE FUNCTION CryptCATCatalogInfoFromContext IMPORT "WINTRUST.DLL" ALIAS "CryptCATCatalogInfoFromContext" ( _
   BYVAL hCatInfo AS DWORD _                            ' __in HCATINFO hCatInfo
 , BYREF psCatInfo AS CATALOG_INFO _                    ' __in_out CATALOG_INFO *psCatInfo
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

'//////////////////////////////////////////////////////////////////////////
'//
'//  CryptCATAdminResolveCatalogPath
'// --------------------------------------------------------------------------
'//  Usage:
'//      call this function to retrieve the fully qualified path to the
'//      catalog specified by pwszCatalogFile
'//
'//  Return:
'//      On success, TRUE is returned and the CATALOG_INFO structure
'//      is filled in.
'//      FALSE if an error occurs.
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//      ERROR_NOT_ENOUGH_MEMORY:        if the fully qualified path is longer
'//                                      than MAX_PATH
'//
'//  Comments:
'//      the dwFlags parameter is reserved for future use and must be assigned
'//      to NULL.
'//

DECLARE FUNCTION CryptCATAdminResolveCatalogPath IMPORT "WINTRUST.DLL" ALIAS "CryptCATAdminResolveCatalogPath" ( _
   BYVAL hCatAdmin AS DWORD _                           ' __in HCATADMIN hCatAdmin
 , BYVAL pwszCatalogFile AS DWORD _                     ' __in WCHAR *pwszCatalogFile
 , BYREF psCatInfo AS CATALOG_INFO _                    ' __in_out CATALOG_INFO *psCatInfo
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

'//////////////////////////////////////////////////////////////////////////
'//
'//  CryptCATAdminPauseServiceForBackup
'// --------------------------------------------------------------------------
'//  Usage:
'//      call this function to pause the catalog sub-system in preparation
'//      for backing up the catalog sub-systems files.
'//
'//  Return:
'//      On success, TRUE is returned.  FALSE if an error occurs.
'//
'//  Errors:
'//      ERROR_INVALID_PARAMETER:        an input parameter is incorrect
'//      ERROR_TIMEOUT:                  if clients are accessing database files
'//                                      and fail to relinquish them in a timely
'//                                      manner.
'//
'//  Comments:
'//      the dwFlags parameter is reserved for future use and must be assigned
'//      to NULL.  Set fResume to FALSE when pausing the catalog service, and
'//      set it to TRUE to resume service.
'//

DECLARE FUNCTION CryptCATAdminPauseServiceForBackup IMPORT "WINTRUST.DLL" ALIAS "CryptCATAdminPauseServiceForBackup" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL fResume AS LONG _                              ' __in BOOL  fResume
 ) AS LONG                                              ' BOOL
