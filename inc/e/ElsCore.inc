' ########################################################################################
' Microsoft Windows
' File: ElsCore.inc
' Contents: Structures and function prototypes that are common for ELS.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ELSCORE_INC = 1

'struct _MAPPING_PROPERTY_BAG;

'typedef void (CALLBACK* PFN_MAPPINGCALLBACKPROC)(struct _MAPPING_PROPERTY_BAG *pBag, LPVOID data, DWORD dwDataSize, HRESULT Result);

'SUB MAPPINGCALLBACKPROC(BYREF pBag AS MAPPING_PROPERTY_BAG, BYVAL pData AS DWORD, BYVAL dwDataSize AS DWORD, BYVAL Result AS LONG)


'//
'// Service types constants used in MAPPING_ENUM_OPTIONS (ServiceType field)
'//

%ALL_SERVICE_TYPES          = 0
%HIGHLEVEL_SERVICE_TYPES    = 1
%LOWLEVEL_SERVICE_TYPES     = 2

'//
'// Online service constants used in MAPPING_ENUM_OPTIONS (OnlineService field)
'//
%ALL_SERVICES               = 0
%ONLINE_SERVICES            = 1
%OFFLINE_SERVICES           = 2

'//
'// Public ELS structures
'//

' // Size = 104 bytes
TYPE MAPPING_SERVICE_INFO BYTE
   Size                      AS DWORD              ' size_t
   pszCopyright              AS WSTRINGZ PTR       ' LPWSTR *
   wMajorVersion             AS WORD               ' WORD
   wMinorVersion             AS WORD               ' WORD
   wBuildVersion             AS WORD               ' WORD
   wStepVersion              AS WORD               ' WORD
   dwInputContentTypesCount  AS DWORD              ' DWORD
   prgInputContentTypes      AS WSTRINGZ PTR       ' LPWSTR *
   dwOutputContentTypesCount AS DWORD              ' DWORD
   prgOutputContentTypes     AS WSTRINGZ PTR       ' LPWSTR *
   dwInputLanguagesCount     AS DWORD              ' DWORD
   prgInputLanguages         AS WSTRINGZ PTR       ' LPWSTR *
   dwOutputLanguagesCount    AS DWORD              ' DWORD
   prgOutputLanguages        AS WSTRINGZ PTR       ' LPWSTR *
   dwInputScriptsCount       AS DWORD              ' DWORD
   prgInputScripts           AS WSTRINGZ PTR       ' LPWSTR *
   dwOutputScriptsCount      AS DWORD              ' DWORD
   prgOutputScripts          AS WSTRINGZ PTR       ' LPWSTR *
   guid                      AS GUID               ' GUID
   pszCategory               AS WSTRINGZ PTR       ' LPWSTR *
   pszDescription            AS WSTRINGZ PTR       ' LPWSTR *
   dwPrivateDataSize         AS DWORD              ' DWORD
   pPrivateData              AS DWORD              ' LPVOID
   pContext                  AS DWORD              ' LPVOID
   IsOneToOneLanguageMapping AS BIT * 1 IN DWORD   ' unsigned
   HasSubservices            AS BIT * 1
   OnlineOnly                AS BIT * 1
   ServiceType               AS BIT * 2
END TYPE

' // Size = 40 bytes
TYPE MAPPING_ENUM_OPTIONS BYTE
   Size                 AS DWORD              ' size_t
   pszCategory          AS WSTRINGZ PTR       ' LPWSTR
   pszInputLanguage     AS WSTRINGZ PTR       ' LPWSTR
   pszOutputLanguage    AS WSTRINGZ PTR       ' LPWSTR
   pszInputScript       AS WSTRINGZ PTR       ' LPWSTR
   pszOutputScript      AS WSTRINGZ PTR       ' LPWSTR
   pszInputContentType  AS WSTRINGZ PTR       ' LPWSTR
   pszOutputContentType AS WSTRINGZ PTR       ' LPWSTR
   pGuid                AS GUID PTR           ' GUID *
   OnlineService        AS BIT * 2 IN DWORD   ' unsigned
   ServiceType          AS BIT * 2
END TYPE

' // Size = 64 bytes
TYPE MAPPING_OPTIONS BYTE
   Size                      AS DWORD              ' size_t
   pszInputLanguage          AS WSTRINGZ PTR       ' LPWSTR
   pszOutputLanguage         AS WSTRINGZ PTR       ' LPWSTR
   pszInputScript            AS WSTRINGZ PTR       ' LPWSTR
   pszOutputScript           AS WSTRINGZ PTR       ' LPWSTR
   pszInputContentType       AS WSTRINGZ PTR       ' LPWSTR
   pszOutputContentType      AS WSTRINGZ PTR       ' LPWSTR
   pszUILanguage             AS WSTRINGZ PTR       ' LPWSTR
   pfnRecognizeCallback      AS DWORD              ' PFN_MAPPINGCALLBACKPROC
   pRecognizeCallerData      AS DWORD              ' LPVOID
   dwRecognizeCallerDataSize AS DWORD              ' DWORD
   pfnActionCallback         AS DWORD              ' PFN_MAPPINGCALLBACKPROC
   pActionCallerData         AS DWORD              ' LPVOID
   dwActionCallerDataSize    AS DWORD              ' DWORD
   dwServiceFlag             AS DWORD              ' DWORD
   GetActionDisplayName      AS BIT * 1 IN DWORD   ' unsigned
END TYPE

' // Size = 40 bytes
TYPE MAPPING_DATA_RANGE BYTE
   dwStartIndex          AS DWORD          ' DWORD
   dwEndIndex            AS DWORD          ' DWORD
   pszDescription        AS WSTRINGZ PTR   ' LPWSTR
   dwDescriptionLength   AS DWORD          ' DWORD
   pData                 AS DWORD          ' LPVOID
   dwDataSize            AS DWORD          ' DWORD
   pszContentType        AS WSTRINGZ PTR   ' LPWSTR
   prgActionIds          AS WSTRINGZ PTR   ' LPWSTR *
   dwActionsCount        AS DWORD          ' DWORD
   prgActionDisplayNames AS WSTRINGZ PTR   ' LPWSTR *
END TYPE

' // Size = 32 bytes
TYPE MAPPING_PROPERTY_BAG BYTE
   Size              AS DWORD                    ' size_t
   prgResultRanges   AS MAPPING_DATA_RANGE PTR   ' PMAPPING_DATA_RANGE
   dwRangesCount     AS DWORD                    ' DWORD
   pServiceData      AS DWORD                    ' LPVOID
   dwServiceDataSize AS DWORD                    ' DWORD
   pCallerData       AS DWORD                    ' LPVOID
   dwCallerDataSize  AS DWORD                    ' DWORD
   pContext          AS DWORD                    ' LPVOID
END TYPE


'//
'// Public ELS APIs
'//

DECLARE FUNCTION MappingGetServices IMPORT "Elscore.dll" ALIAS "MappingGetServices" ( _
   BYREF pOptions AS MAPPING_ENUM_OPTIONS _             ' __in_opt  PMAPPING_ENUM_OPTIONS  pOptions
 , BYREF prgServices AS MAPPING_SERVICE_INFO _          ' __out     PMAPPING_SERVICE_INFO *prgServices
 , BYREF pdwServicesCount AS DWORD _                    ' __out     DWORD                 *pdwServicesCount
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MappingFreeServices IMPORT "Elscore.dll" ALIAS "MappingFreeServices" ( _
   BYREF pServiceInfo AS MAPPING_SERVICE_INFO _         ' __in PMAPPING_SERVICE_INFO pServiceInfo
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MappingRecognizeText IMPORT "Elscore.dll" ALIAS "MappingRecognizeText" ( _
   BYREF pServiceInfo AS MAPPING_SERVICE_INFO _         ' __in     PMAPPING_SERVICE_INFO  pServiceInfo
 , BYREF pszText AS WSTRINGZ _                          ' __in     LPCWSTR                pszText
 , BYVAL dwLength AS DWORD _                            ' __in     DWORD                  dwLength
 , BYVAL dwIndex AS DWORD _                             ' __in     DWORD                  dwIndex
 , BYREF pOptions AS MAPPING_OPTIONS _                  ' __in_opt PMAPPING_OPTIONS       pOptions
 , BYREF pbag AS MAPPING_PROPERTY_BAG _                 ' __inout  PMAPPING_PROPERTY_BAG  pbag
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MappingDoAction IMPORT "Elscore.dll" ALIAS "MappingDoAction" ( _
   BYREF pBag AS MAPPING_PROPERTY_BAG _                 ' __inout PMAPPING_PROPERTY_BAG pBag
 , BYVAL dwRangeIndex AS DWORD _                        ' __in    DWORD                 dwRangeIndex
 , BYREF pszActionId AS WSTRINGZ _                      ' __in    LPCWSTR               pszActionId
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MappingFreePropertyBag IMPORT "Elscore.dll" ALIAS "MappingFreePropertyBag" ( _
   BYREF pBag AS MAPPING_PROPERTY_BAG _                 ' __in PMAPPING_PROPERTY_BAG pBag
 ) AS LONG                                              ' HRESULT
