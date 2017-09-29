' ########################################################################################
' Microsoft Windows
' File: slpublic.inc
' Contents: Software Licensing and Geniune Advantage Client public API
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SLPUBLIC_INC = 1

#INCLUDE ONCE "windows.inc"

'#define SLFreeMemory(p) LocalFree(p)
DECLARE FUNCTION SLFreeMemory IMPORT "KERNEL32.DLL" ALIAS "LocalFree" ( _
   BYVAL hMem AS DWORD _                                ' __in HLOCAL hMem
 ) AS DWORD                                             ' HLOCAL

'#define SLWGAFreeMemory(p) LocalFree(p)
DECLARE FUNCTION SLWGAFreeMemory IMPORT "KERNEL32.DLL" ALIAS "LocalFree" ( _
   BYVAL hMem AS DWORD _                                ' __in HLOCAL hMem
 ) AS DWORD                                             ' HLOCAL

'typedef GUID SLID;

' enum SLDATATYPE
%SL_DATA_NONE        = %REG_NONE
%SL_DATA_SZ          = %REG_SZ
%SL_DATA_DWORD       = %REG_DWORD
%SL_DATA_BINARY      = %REG_BINARY
%SL_DATA_MULTI_SZ    = %REG_MULTI_SZ
%SL_DATA_SUM         = 100

' enum SL_GENUINE_STATE
%SL_GEN_STATE_IS_GENUINE      = 0
%SL_GEN_STATE_INVALID_LICENSE = 1
%SL_GEN_STATE_TAMPERED        = 2
%SL_GEN_STATE_LAST            = 3

' // Size = 12 bytes
TYPE SL_NONGENUINE_UI_OPTIONS
   cbSize       AS DWORD      ' DWORD
   pComponentId AS GUID PTR   ' CONST SLID*
   hResultUI    AS LONG       ' HRESULT
END TYPE

$$SL_PROP_BRT_DATA              = "SL_BRT_DATA"$$
$$SL_PROP_BRT_COMMIT            = "SL_BRT_COMMIT"$$
$$SL_PROP_GENUINE_RESULT        = "SL_GENUINE_RESULT"$$
$$SL_PROP_NONGENUINE_GRACE_FLAG = "SL_NONGENUINE_GRACE_FLAG"$$

$$SL_POLICY_EVALUATION_MODE_ENABLED = "Security-SPP-EvaluationModeEnabled"$$

DECLARE FUNCTION SLGetWindowsInformation IMPORT "Slc.dll" ALIAS "SLGetWindowsInformation" ( _
   BYREF pwszValueName AS WSTRINGZ _                    ' __in PCWSTR pwszValueName
 , BYREF peDataType AS LONG _                           ' __out_opt SLDATATYPE* peDataType
 , BYREF pcbValue AS DWORD _                            ' __out UINT* pcbValue
 , BYREF ppbValue AS DWORD _                            ' __out PBYTE* ppbValue
 ) AS LONG                                              ' HRESULT

'/*++
'Routine Description:

'    This function is used to for Windows components to get
'    component policy value.

'Arguments:

'    pwszValueName
'        The name of the requested value.

'    peDataType
'        Data type. Following types are supported:
'            SL_DATA_SZ     - UNICODE string
'            SL_DATA_DWORD  - DWORD
'            SL_DATA_BINARY - Binary blob

'    pcbValue
'        Size of the allocated buffer.

'    ppbValue
'        The value. If successful, the data is returned in the buffer
'        allocated by SLC.
'        The caller has to call SLFreeMemory to free the memory.

'Return Error:
'    E_INVALIDARG
'    SL_E_VALUE_NOT_FOUND
'    SL_E_RIGHT_NOT_GRANTED

'--*/

DECLARE FUNCTION SLGetWindowsInformationDWORD IMPORT "Slc.dll" ALIAS "SLGetWindowsInformationDWORD" ( _
   BYREF pwszValueName AS WSTRINGZ _                    ' __in PCWSTR pwszValueName
 , BYREF pdwValue AS DWORD _                            ' __out DWORD* pdwValue
 ) AS LONG                                              ' HRESULT

'/*++
'Routine Description:

'    This function is used to for Windows components to get
'    component policy DWORD value.

'Arguments:

'    pwszValueName
'        The name of the requested value.

'    pdwValue
'        The buffer to receive DWORD value

'Return Error:
'    E_INVALIDARG
'    SL_E_VALUE_NOT_FOUND
'    SL_E_RIGHT_NOT_GRANTED
'    SL_E_DATATYPE_MISMATCHED

'--*/

DECLARE FUNCTION SLIsGenuineLocal IMPORT "Slwga.dll" ALIAS "SLIsGenuineLocal" ( _
   BYREF pAppId AS GUID _                               ' __in    CONST SLID*               pAppId
 , BYREF pGenuineState AS LONG _                        ' __out   SL_GENUINE_STATE *        pGenuineState
 , BYREF pUIOptions AS SL_NONGENUINE_UI_OPTIONS _       ' __inout SL_NONGENUINE_UI_OPTIONS* pUIOptions
 ) AS LONG                                              ' HRESULT

'/*++
'Routine Description:

'    Determines if an installation is a Genuine installation.
'    It interrogates the license for pAppId and inspects the "Tampered"
'    flag.  If either the license for pAppId is invalid or the "Tampered"
'    flag is set, the installation is assumed to be invalid.

'    pGenuineState is ONLY modified if the result is S_OK.  Otherwise, it is
'    left in the state in which it was found on function entry.

'Arguments:

'    pAppId
'        Application identifier.

'    pbGenuineState
'        Output state value - one of the SL_GENUINE_STATE values

'    pUIOptions
'        Non genuine UI options. If NULL, no UI is displayed if
'        state is non-genuine.

'Return Error:

'    S_OK
'        Operation completed successfully.

'    E_INVALIDARG
'        pGenuineState is NULL.

'--*/

DECLARE FUNCTION SLIsGenuineLocalEx IMPORT "Slwga.dll" ALIAS "SLIsGenuineLocalEx" ( _
   BYREF pAppId AS GUID _                               ' __in     CONST SLID*       pAppId
 , BYREF pSkuId AS GUID _                               ' __in_opt CONST SLID*       pSkuId
 , BYREF pGenuineState AS LONG _                        ' __out    SL_GENUINE_STATE *pGenuineState
 ) AS LONG                                              ' HRESULT

'/*++
'Routine Description:

'    Determines if an installation is a Genuine installation.
'    If the SkuId is provided, it is used for the primary check.  If the Sku license
'    contains a ProductUniquenessGroupId value, that is also used.  Finally, the AppId is used.
'    If the AppId, ProductUniquenessGroupId, or SkuId contains a "Tampered" flag or if the license
'    state is invalid or "Tampered", the installation is assumed to be invalid.


'    pGenuineState is ONLY modified if the result is S_OK.  Otherwise, it is
'    left in the state in which it was found on function entry.

'Arguments:

'    pAppId
'        Application identifier.

'    pSkuId
'        Sku identifier, optional.  If specified and the Sku license contains a
'        ProductUniquenessGroupId then that is also checked.

'    pbGenuineState
'        Output state value - one of the SL_GENUINE_STATE values

'Return Error:

'    S_OK
'        Operation completed successfully.

'    E_INVALIDARG
'        pGenuineState is NULL.

'--*/

DECLARE FUNCTION SLAcquireGenuineTicket IMPORT "Slcext.dll" ALIAS "SLAcquireGenuineTicket" ( _
   BYREF ppTicketBlob AS DWORD _                        ' __out void ** ppTicketBlob
 , BYREF pcbTicketBlob AS DWORD _                       ' __out UINT *pcbTicketBlob
 , BYREF pwszTemplateId AS WSTRINGZ _                   ' __in PCWSTR pwszTemplateId
 , BYREF pwszServerUrl AS WSTRINGZ _                    ' __in PCWSTR pwszServerUrl
 , OPTIONAL BYREF pwszClientToken AS WSTRINGZ _         ' __in_opt PCWSTR pwszClientToken
 ) AS LONG                                              ' HRESULT

'/*++
'Routine Description:

'    Returns genuine ticket acquired from Software Licensing Server based
'    on SLWGA template blob.

'    The client is responsible for freeing the buffer returned in ppGenuineBlob.
'    SLWGAFreeMemory should be used to free the memory.

'    The output parameters are only set if the function returns S_OK.  Otherwise,
'    they are left as they were when the function was entered.

'Arguments:

'    ppTicketBlob
'        Pointer to output pointer to be returned (XrML genuine ticket).

'    pcbTicketBlob
'        An output pointer that will contain the size, in bytes, of the region
'        returned in ppTicketBlob.

'    pwszTemplateId
'        Id of genuine blob template kept on the server side.

'    pwszServerUrl
'        Ticket acquisition server url.

'    pwszClientToken
'        Client custom token.

'Return Error:

'    S_OK
'        Operation completed successfully.

'--*/

' // *** Removed in Windows 7 SDK ***
'DECLARE FUNCTION SLGetInstalledSAMLicenseApplications IMPORT "Slc.dll" ALIAS "SLGetInstalledSAMLicenseApplications" ( _
'   BYREF pnReturnedAppIds AS DWORD _                    ' __out UINT* pnReturnedAppIds,
' , BYREF ppReturnedAppIds AS DWORD _                    ' __out SLID** ppReturnedAppIds
' ) AS LONG                                              ' HRESULT

'/*++
'Routine Description:

'    Obtains an array of Application Ids representing applications whose SAM
'    licenses have been installed with SLInstallSAMLicense.

'Arguments:
'    pnReturnedAppIds
'        Number of elements in ppReturnedAppIds array
'    ppReturnedAppIds
'        Array containing all installed Application Ids.
'        The caller has to call SLFreeMemory to free the memory.

'Return Errors:

'    S_OK
'        Operation completed successfully
'    E_INVALIDARG
'        One or more arguments are invalid

'--*/

' // *** Removed in Windows 7 SDK ***
'DECLARE FUNCTION SLGetSAMLicense IMPORT "Slc.dll" ALIAS "SLGetSAMLicense" ( _
'   BYREF pApplicationId AS GUID _                       ' __in const SLID* pApplicationId
' , BYREF pcbXmlLicenseData AS DWORD _                   ' __out UINT* pcbXmlLicenseData
' , BYREF ppbXmlLicenseData AS DWORD _                   ' __out PBYTE* ppbXmlLicenseData
' ) AS LONG                                              ' HRESULT

'/*++
'Routine Description:

'    Obtain information about an installed SAM application.

'Arguments:
'    pApplicationId
'        Id of Application for which to obtain its SAM License
'    pcbXmlLicenseData
'        Size of ppbXmlLicenseData in bytes
'    ppbXmlLicenseData
'        License file data for (SAM) application with Application Id pApplicationId.
'        The caller has to call SLFreeMemory to free the memory.

'Return Errors:

'    S_OK
'        Operation completed successfully
'    SL_E_LICENSE_FILE_NOT_INSTALLED
'        License not installed
'    E_INVALIDARG
'        One or more arguments are invalid

'--*/

' // *** Removed in Windows 7 SDK ***
'DECLARE FUNCTION SLInstallSAMLicense IMPORT "Slc.dll" ALIAS "SLInstallSAMLicense" ( _
'   BYREF pApplicationId AS GUID _                       ' __in const SLID* pApplicationId
' , BYVAL cbXmlLicenseData AS DWORD _                    ' __in UINT cbXmlLicenseData
' , BYVAL pbXmlLicenseData AS DWORD _                    ' __in CONST BYTE* pbXmlLicenseData
' ) AS LONG                                              ' HRESULT

'/*++
'Routine Description:

'    Install SAM License

'Arguments:
'    pApplicationId
'        Id of Application for which to install SAM License.
'    cbXmlLicenseData
'        Size of pbXmlLicenseData in bytes
'    pbXmlLicenseData
'        License file data

'Return Errors:

'    S_OK
'        Operation completed successfully
'    SL_E_LUA_ACCESSDENIED
'        The Software Licensing Service reported that the action requires administrator privilege
'    E_INVALIDARG
'        One or more arguments are invalid
'--*/

' // *** Removed in Windows 7 SDK ***
'DECLARE FUNCTION SLUninstallSAMLicense IMPORT "Slc.dll" ALIAS "SLUninstallSAMLicense" ( _
'   BYREF pApplicationId AS GUID _                       ' __in const SLID* pApplicationId
' ) AS LONG                                              ' HRESULT

'/*++
'Routine Description:

'    UnInstall SAM License

'Arguments:
'    pApplicationId
'        Id of Application for which to uninstall SAM License.

'Return Errors:

'    S_OK
'        Operation completed successfully
'    SL_E_LICENSE_FILE_NOT_INSTALLED
'        License not installed
'    SL_E_LUA_ACCESSDENIED
'        The Software Licensing Service reported that the action requires administrator privilege
'    E_INVALIDARG
'        One or more arguments are invalid

'--*/

DECLARE FUNCTION SLSetGenuineInformation IMPORT "Slc.dll" ALIAS "SLSetGenuineInformation" ( _
   BYREF pAppId AS GUID _                               ' __in CONST SLID* pAppId
 , BYREF pwszValueName AS WSTRINGZ _                    ' __in PCWSTR pwszValueName
 , BYVAL eDataType AS LONG _                            ' __in SLDATATYPE eDataType
 , BYVAL cbValue AS DWORD _                             ' __in_opt UINT cbValue
 , BYVAL pbValue AS DWORD _                             ' __in_bcount_opt(cbValue) CONST BYTE* pbValue
 ) AS LONG                                              ' HRESULT

'/*++
'Routine Description:

'    This function sets genuine information.

'Arguments:

'    hSLC
'        Handle to current SLC session.

'    pAppId
'        Application ID. E.g. Windows AppId

'    pwszValueName
'        The name of value.
'        TBD

'    eType
'        See SLDATATYPE

'    cbValue
'        Size of value

'    pbValue
'        Value.
'        Some properties allows NULL pointer, which can be used to delete
'        the property but some properties can't.

'Return Value:
'    HRESULT_FROM_WIN32(ERROR_BUFFER_OVERFLOW)
'        The size of value is over expected size
'    E_ACCESSDENIED
'        Admin privilege required
'    E_INVALIDAGR
'        Some property does not allow NULL value
'    SL_E_NOT_SUPPORTED
'        The name of value is not supported
'    SL_E_DEPENDENT_PROPERTY_NOT_SET
'        If entry has been set
'    SL_E_DATATYPE_MISMATCHED
'        The type of data is mismatched with the expected type
'        of specified value name
'--*/

DECLARE FUNCTION SLGetGenuineInformation IMPORT "Slc.dll" ALIAS "SLGetGenuineInformation" ( _
   BYREF pAppId AS GUID _                               ' __in CONST SLID* pAppId
 , BYREF pwszValueName AS WSTRINGZ _                    ' __in PCWSTR pwszValueName
 , BYREF peDataType AS LONG _                           ' __out_opt SLDATATYPE* peDataType
 , BYREF pcbValue AS DWORD _                            ' __out UINT* pcbValue
 , BYREF ppbValue AS DWORD _                            ' __deref_out_bcount(*pcbValue) BYTE** ppbValue
 ) AS LONG                                              ' HRESULT

'/*++
'Routine Description:

'    This function gets genuine information.

'Arguments:

'    hSLC
'        Handle to current SLC session.

'    pAppId
'        Application ID. E.g. Windows AppId

'    pwszValueName
'        See SLSetOfflineGenuineInformation

'    eType
'        See SLDATATYPE

'    cbValue
'        Size of value

'    pbValue
'        Value

'Return Value:
'    SL_E_NOT_SUPPORTED
'        The name of value is not supported
'    SL_E_VALUE_NOT_FOUND
'        The specified value can not be found
'--*/
