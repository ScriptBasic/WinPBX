' ########################################################################################
' Microsoft Windows
' File: WbemCli.inc
' Contents: WMI low-level COM API.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WBEMCLI_INC = 1

'#INCLUDE ONCE "ole2.inc"

' WBEM_GENUS_TYPE enum
%WBEM_GENUS_CLASS                 = 1&
%WBEM_GENUS_INSTANCE              = 2&

' WBEM_CHANGE_FLAG_TYPE enum
%WBEM_FLAG_CREATE_OR_UPDATE       = 0&
%WBEM_FLAG_UPDATE_ONLY            = &H1&
%WBEM_FLAG_CREATE_ONLY            = &H2&
%WBEM_FLAG_UPDATE_COMPATIBLE      = 0&
%WBEM_FLAG_UPDATE_SAFE_MODE       = &H20&
%WBEM_FLAG_UPDATE_FORCE_MODE      = &H40&
%WBEM_MASK_UPDATE_MODE            = &H60&
%WBEM_FLAG_ADVISORY               = &H10000&

' WBEM_GENERIC_FLAG_TYPE enum
%WBEM_FLAG_RETURN_IMMEDIATELY     = &H10&
%WBEM_FLAG_RETURN_WBEM_COMPLETE   = 0&
%WBEM_FLAG_BIDIRECTIONAL          = 0&
%WBEM_FLAG_FORWARD_ONLY           = &H20&
%WBEM_FLAG_NO_ERROR_OBJECT        = &H40&
%WBEM_FLAG_RETURN_ERROR_OBJECT    = 0&
%WBEM_FLAG_SEND_STATUS            = &H80&
%WBEM_FLAG_DONT_SEND_STATUS       = 0&
%WBEM_FLAG_ENSURE_LOCATABLE       = &H100&
%WBEM_FLAG_DIRECT_READ            = &H200&
%WBEM_FLAG_SEND_ONLY_SELECTED     = 0&
%WBEM_RETURN_WHEN_COMPLETE        = 0&
%WBEM_RETURN_IMMEDIATELY          = &H10&
%WBEM_MASK_RESERVED_FLAGS         = &H1f000&
%WBEM_FLAG_USE_AMENDED_QUALIFIERS = &H20000&
%WBEM_FLAG_STRONG_VALIDATION      = &H100000&

' WBEM_STATUS_TYPE enum
%WBEM_STATUS_COMPLETE     = 0&
%WBEM_STATUS_REQUIREMENTS = 1&
%WBEM_STATUS_PROGRESS     = 2&

' WBEM_TIMEOUT_TYPE enum
%WBEM_NO_WAIT  = 0&
%WBEM_INFINITE = &Hffffffff&

' WBEM_CONDITION_FLAG_TYPE enum
%WBEM_FLAG_ALWAYS                    = 0&
%WBEM_FLAG_ONLY_IF_TRUE              = &H1&
%WBEM_FLAG_ONLY_IF_FALSE             = &H2&
%WBEM_FLAG_ONLY_IF_IDENTICAL         = &H3&
%WBEM_MASK_PRIMARY_CONDITION         = &H3&
%WBEM_FLAG_KEYS_ONLY                 = &H4&
%WBEM_FLAG_REFS_ONLY                 = &H8&
%WBEM_FLAG_LOCAL_ONLY                = &H10&
%WBEM_FLAG_PROPAGATED_ONLY           = &H20&
%WBEM_FLAG_SYSTEM_ONLY               = &H30&
%WBEM_FLAG_NONSYSTEM_ONLY            = &H40&
%WBEM_MASK_CONDITION_ORIGIN          = &H70&
%WBEM_FLAG_CLASS_OVERRIDES_ONLY      = &H100&
%WBEM_FLAG_CLASS_LOCAL_AND_OVERRIDES = &H200&
%WBEM_MASK_CLASS_CONDITION           = &H300&

' WBEM_FLAVOR_TYPE enum
%WBEM_FLAVOR_DONT_PROPAGATE                  = 0&
%WBEM_FLAVOR_FLAG_PROPAGATE_TO_INSTANCE      = &H1&
%WBEM_FLAVOR_FLAG_PROPAGATE_TO_DERIVED_CLASS = &H2&
%WBEM_FLAVOR_MASK_PROPAGATION                = &Hf&
%WBEM_FLAVOR_OVERRIDABLE                     = 0&
%WBEM_FLAVOR_NOT_OVERRIDABLE                 = &H10&
%WBEM_FLAVOR_MASK_PERMISSIONS                = &H10&
%WBEM_FLAVOR_ORIGIN_LOCAL                    = 0&
%WBEM_FLAVOR_ORIGIN_PROPAGATED               = &H20&
%WBEM_FLAVOR_ORIGIN_SYSTEM                   = &H40&
%WBEM_FLAVOR_MASK_ORIGIN                     = &H60&
%WBEM_FLAVOR_NOT_AMENDED                     = 0&
%WBEM_FLAVOR_AMENDED                         = &H80&
%WBEM_FLAVOR_MASK_AMENDED                    = &H80&

' WBEM_QUERY_FLAG_TYPE enum
%WBEM_FLAG_DEEP      = 0&
%WBEM_FLAG_SHALLOW   = 1&
%WBEM_FLAG_PROTOTYPE = 2&

' WBEM_SECURITY_FLAGS enum
%WBEM_ENABLE            = 1&
%WBEM_METHOD_EXECUTE    = 2&
%WBEM_FULL_WRITE_REP    = 4&
%WBEM_PARTIAL_WRITE_REP = 8&
%WBEM_WRITE_PROVIDER    = &H10&
%WBEM_REMOTE_ACCESS     = &H20&
%WBEM_RIGHT_SUBSCRIBE   = &H40&
%WBEM_RIGHT_PUBLISH     = &H80&

' WBEM_LIMITATION_FLAG_TYPE enum
%WBEM_FLAG_EXCLUDE_OBJECT_QUALIFIERS   = &H10&
%WBEM_FLAG_EXCLUDE_PROPERTY_QUALIFIERS = &H20&

' WBEM_TEXT_FLAG_TYPE enum
%WBEM_FLAG_NO_FLAVORS = &H1&

' WBEM_COMPARISON_FLAG enum
%WBEM_COMPARISON_INCLUDE_ALL     = 0&
%WBEM_FLAG_IGNORE_QUALIFIERS     = &H1&
%WBEM_FLAG_IGNORE_OBJECT_SOURCE  = &H2&
%WBEM_FLAG_IGNORE_DEFAULT_VALUES = &H4&
%WBEM_FLAG_IGNORE_CLASS          = &H8&
%WBEM_FLAG_IGNORE_CASE           = &H10&
%WBEM_FLAG_IGNORE_FLAVOR         = &H20&

' WBEM_LOCKING_FLAG_TYPE enum
%WBEM_FLAG_ALLOW_READ = &H1&

' CIMTYPE_ENUMERATION enum
%CIM_ILLEGAL    = &Hfff&
%CIM_EMPTY      = 0&
%CIM_SINT8      = 16&
%CIM_UINT8      = 17&
%CIM_SINT16     = 2&
%CIM_UINT16     = 18&
%CIM_SINT32     = 3&
%CIM_UINT32     = 19&
%CIM_SINT64     = 20&
%CIM_UINT64     = 21&
%CIM_REAL32     = 4&
%CIM_REAL64     = 5&
%CIM_BOOLEAN    = 11&
%CIM_STRING     = 8&
%CIM_DATETIME   = 101&
%CIM_REFERENCE  = 102&
%CIM_CHAR16     = 103&
%CIM_OBJECT     = 13&
%CIM_FLAG_ARRAY = &H2000&

' WBEM_BACKUP_RESTORE_FLAGS enum
%WBEM_FLAG_BACKUP_RESTORE_DEFAULT        = 0&
%WBEM_FLAG_BACKUP_RESTORE_FORCE_SHUTDOWN = 1&

' WBEM_REFRESHER_FLAGS enum
%WBEM_FLAG_REFRESH_AUTO_RECONNECT    = 0&
%WBEM_FLAG_REFRESH_NO_AUTO_RECONNECT = 1&

' WBEM_SHUTDOWN_FLAGS enum
%WBEM_SHUTDOWN_UNLOAD_COMPONENT = 1&
%WBEM_SHUTDOWN_WMI              = 2&
%WBEM_SHUTDOWN_OS               = 3&

'typedef long CIMTYPE;

' WBEMSTATUS_FORMAT enum
%WBEMSTATUS_FORMAT_NEWLINE    = 0&
%WBEMSTATUS_FORMAT_NO_NEWLINE = 1&

' WBEM_LIMITS enum
%WBEM_MAX_IDENTIFIER      = &H1000&
%WBEM_MAX_QUERY           = &H4000&
%WBEM_MAX_PATH            = &H2000&
%WBEM_MAX_OBJECT_NESTING  = 64&
%WBEM_MAX_USER_PROPERTIES = 1024&

' WBEMSTATUS enum
%WBEM_NO_ERROR                             = 0&
%WBEM_S_NO_ERROR                           = 0&
%WBEM_S_SAME                               = 0&
%WBEM_S_FALSE                              = 1&
%WBEM_S_ALREADY_EXISTS                     = &H40001&
%WBEM_S_RESET_TO_DEFAULT                   = &H40002&
%WBEM_S_DIFFERENT                          = &H40003&
%WBEM_S_TIMEDOUT                           = &H40004&
%WBEM_S_NO_MORE_DATA                       = &H40005&
%WBEM_S_OPERATION_CANCELLED                = &H40006&
%WBEM_S_PENDING                            = &H40007&
%WBEM_S_DUPLICATE_OBJECTS                  = &H40008&
%WBEM_S_ACCESS_DENIED                      = &H40009&
%WBEM_S_PARTIAL_RESULTS                    = &H40010&
%WBEM_S_SOURCE_NOT_AVAILABLE               = &H40017&
%WBEM_E_FAILED                             = &H80041001&
%WBEM_E_NOT_FOUND                          = &H80041002&
%WBEM_E_ACCESS_DENIED                      = &H80041003&
%WBEM_E_PROVIDER_FAILURE                   = &H80041004&
%WBEM_E_TYPE_MISMATCH                      = &H80041005&
%WBEM_E_OUT_OF_MEMORY                      = &H80041006&
%WBEM_E_INVALID_CONTEXT                    = &H80041007&
%WBEM_E_INVALID_PARAMETER                  = &H80041008&
%WBEM_E_NOT_AVAILABLE                      = &H80041009&
%WBEM_E_CRITICAL_ERROR                     = &H8004100a&
%WBEM_E_INVALID_STREAM                     = &H8004100b&
%WBEM_E_NOT_SUPPORTED                      = &H8004100c&
%WBEM_E_INVALID_SUPERCLASS                 = &H8004100d&
%WBEM_E_INVALID_NAMESPACE                  = &H8004100e&
%WBEM_E_INVALID_OBJECT                     = &H8004100f&
%WBEM_E_INVALID_CLASS                      = &H80041010&
%WBEM_E_PROVIDER_NOT_FOUND                 = &H80041011&
%WBEM_E_INVALID_PROVIDER_REGISTRATION      = &H80041012&
%WBEM_E_PROVIDER_LOAD_FAILURE              = &H80041013&
%WBEM_E_INITIALIZATION_FAILURE             = &H80041014&
%WBEM_E_TRANSPORT_FAILURE                  = &H80041015&
%WBEM_E_INVALID_OPERATION                  = &H80041016&
%WBEM_E_INVALID_QUERY                      = &H80041017&
%WBEM_E_INVALID_QUERY_TYPE                 = &H80041018&
%WBEM_E_ALREADY_EXISTS                     = &H80041019&
%WBEM_E_OVERRIDE_NOT_ALLOWED               = &H8004101a&
%WBEM_E_PROPAGATED_QUALIFIER               = &H8004101b&
%WBEM_E_PROPAGATED_PROPERTY                = &H8004101c&
%WBEM_E_UNEXPECTED                         = &H8004101d&
%WBEM_E_ILLEGAL_OPERATION                  = &H8004101e&
%WBEM_E_CANNOT_BE_KEY                      = &H8004101f&
%WBEM_E_INCOMPLETE_CLASS                   = &H80041020&
%WBEM_E_INVALID_SYNTAX                     = &H80041021&
%WBEM_E_NONDECORATED_OBJECT                = &H80041022&
%WBEM_E_READ_ONLY                          = &H80041023&
%WBEM_E_PROVIDER_NOT_CAPABLE               = &H80041024&
%WBEM_E_CLASS_HAS_CHILDREN                 = &H80041025&
%WBEM_E_CLASS_HAS_INSTANCES                = &H80041026&
%WBEM_E_QUERY_NOT_IMPLEMENTED              = &H80041027&
%WBEM_E_ILLEGAL_NULL                       = &H80041028&
%WBEM_E_INVALID_QUALIFIER_TYPE             = &H80041029&
%WBEM_E_INVALID_PROPERTY_TYPE              = &H8004102a&
%WBEM_E_VALUE_OUT_OF_RANGE                 = &H8004102b&
%WBEM_E_CANNOT_BE_SINGLETON                = &H8004102c&
%WBEM_E_INVALID_CIM_TYPE                   = &H8004102d&
%WBEM_E_INVALID_METHOD                     = &H8004102e&
%WBEM_E_INVALID_METHOD_PARAMETERS          = &H8004102f&
%WBEM_E_SYSTEM_PROPERTY                    = &H80041030&
%WBEM_E_INVALID_PROPERTY                   = &H80041031&
%WBEM_E_CALL_CANCELLED                     = &H80041032&
%WBEM_E_SHUTTING_DOWN                      = &H80041033&
%WBEM_E_PROPAGATED_METHOD                  = &H80041034&
%WBEM_E_UNSUPPORTED_PARAMETER              = &H80041035&
%WBEM_E_MISSING_PARAMETER_ID               = &H80041036&
%WBEM_E_INVALID_PARAMETER_ID               = &H80041037&
%WBEM_E_NONCONSECUTIVE_PARAMETER_IDS       = &H80041038&
%WBEM_E_PARAMETER_ID_ON_RETVAL             = &H80041039&
%WBEM_E_INVALID_OBJECT_PATH                = &H8004103a&
%WBEM_E_OUT_OF_DISK_SPACE                  = &H8004103b&
%WBEM_E_BUFFER_TOO_SMALL                   = &H8004103c&
%WBEM_E_UNSUPPORTED_PUT_EXTENSION          = &H8004103d&
%WBEM_E_UNKNOWN_OBJECT_TYPE                = &H8004103e&
%WBEM_E_UNKNOWN_PACKET_TYPE                = &H8004103f&
%WBEM_E_MARSHAL_VERSION_MISMATCH           = &H80041040&
%WBEM_E_MARSHAL_INVALID_SIGNATURE          = &H80041041&
%WBEM_E_INVALID_QUALIFIER                  = &H80041042&
%WBEM_E_INVALID_DUPLICATE_PARAMETER        = &H80041043&
%WBEM_E_TOO_MUCH_DATA                      = &H80041044&
%WBEM_E_SERVER_TOO_BUSY                    = &H80041045&
%WBEM_E_INVALID_FLAVOR                     = &H80041046&
%WBEM_E_CIRCULAR_REFERENCE                 = &H80041047&
%WBEM_E_UNSUPPORTED_CLASS_UPDATE           = &H80041048&
%WBEM_E_CANNOT_CHANGE_KEY_INHERITANCE      = &H80041049&
%WBEM_E_CANNOT_CHANGE_INDEX_INHERITANCE    = &H80041050&
%WBEM_E_TOO_MANY_PROPERTIES                = &H80041051&
%WBEM_E_UPDATE_TYPE_MISMATCH               = &H80041052&
%WBEM_E_UPDATE_OVERRIDE_NOT_ALLOWED        = &H80041053&
%WBEM_E_UPDATE_PROPAGATED_METHOD           = &H80041054&
%WBEM_E_METHOD_NOT_IMPLEMENTED             = &H80041055&
%WBEM_E_METHOD_DISABLED                    = &H80041056&
%WBEM_E_REFRESHER_BUSY                     = &H80041057&
%WBEM_E_UNPARSABLE_QUERY                   = &H80041058&
%WBEM_E_NOT_EVENT_CLASS                    = &H80041059&
%WBEM_E_MISSING_GROUP_WITHIN               = &H8004105a&
%WBEM_E_MISSING_AGGREGATION_LIST           = &H8004105b&
%WBEM_E_PROPERTY_NOT_AN_OBJECT             = &H8004105c&
%WBEM_E_AGGREGATING_BY_OBJECT              = &H8004105d&
%WBEM_E_UNINTERPRETABLE_PROVIDER_QUERY     = &H8004105f&
%WBEM_E_BACKUP_RESTORE_WINMGMT_RUNNING     = &H80041060&
%WBEM_E_QUEUE_OVERFLOW                     = &H80041061&
%WBEM_E_PRIVILEGE_NOT_HELD                 = &H80041062&
%WBEM_E_INVALID_OPERATOR                   = &H80041063&
%WBEM_E_LOCAL_CREDENTIALS                  = &H80041064&
%WBEM_E_CANNOT_BE_ABSTRACT                 = &H80041065&
%WBEM_E_AMENDED_OBJECT                     = &H80041066&
%WBEM_E_CLIENT_TOO_SLOW                    = &H80041067&
%WBEM_E_NULL_SECURITY_DESCRIPTOR           = &H80041068&
%WBEM_E_TIMED_OUT                          = &H80041069&
%WBEM_E_INVALID_ASSOCIATION                = &H8004106a&
%WBEM_E_AMBIGUOUS_OPERATION                = &H8004106b&
%WBEM_E_QUOTA_VIOLATION                    = &H8004106c&
%WBEM_E_RESERVED_001                       = &H8004106d&
%WBEM_E_RESERVED_002                       = &H8004106e&
%WBEM_E_UNSUPPORTED_LOCALE                 = &H8004106f&
%WBEM_E_HANDLE_OUT_OF_DATE                 = &H80041070&
%WBEM_E_CONNECTION_FAILED                  = &H80041071&
%WBEM_E_INVALID_HANDLE_REQUEST             = &H80041072&
%WBEM_E_PROPERTY_NAME_TOO_WIDE             = &H80041073&
%WBEM_E_CLASS_NAME_TOO_WIDE                = &H80041074&
%WBEM_E_METHOD_NAME_TOO_WIDE               = &H80041075&
%WBEM_E_QUALIFIER_NAME_TOO_WIDE            = &H80041076&
%WBEM_E_RERUN_COMMAND                      = &H80041077&
%WBEM_E_DATABASE_VER_MISMATCH              = &H80041078&
%WBEM_E_VETO_DELETE                        = &H80041079&
%WBEM_E_VETO_PUT                           = &H8004107a&
%WBEM_E_INVALID_LOCALE                     = &H80041080&
%WBEM_E_PROVIDER_SUSPENDED                 = &H80041081&
%WBEM_E_SYNCHRONIZATION_REQUIRED           = &H80041082&
%WBEM_E_NO_SCHEMA                          = &H80041083&
%WBEM_E_PROVIDER_ALREADY_REGISTERED        = &H80041084&
%WBEM_E_PROVIDER_NOT_REGISTERED            = &H80041085&
%WBEM_E_FATAL_TRANSPORT_ERROR              = &H80041086&
%WBEM_E_ENCRYPTED_CONNECTION_REQUIRED      = &H80041087&
%WBEM_E_PROVIDER_TIMED_OUT                 = &H80041088&
%WBEM_E_NO_KEY                             = &H80041089&
%WBEM_E_PROVIDER_DISABLED                  = &H8004108a&
%WBEMESS_E_REGISTRATION_TOO_BROAD          = &H80042001&
%WBEMESS_E_REGISTRATION_TOO_PRECISE        = &H80042002&
%WBEMESS_E_AUTHZ_NOT_PRIVILEGED            = &H80042003&
%WBEMMOF_E_EXPECTED_QUALIFIER_NAME         = &H80044001&
%WBEMMOF_E_EXPECTED_SEMI                   = &H80044002&
%WBEMMOF_E_EXPECTED_OPEN_BRACE             = &H80044003&
%WBEMMOF_E_EXPECTED_CLOSE_BRACE            = &H80044004&
%WBEMMOF_E_EXPECTED_CLOSE_BRACKET          = &H80044005&
%WBEMMOF_E_EXPECTED_CLOSE_PAREN            = &H80044006&
%WBEMMOF_E_ILLEGAL_CONSTANT_VALUE          = &H80044007&
%WBEMMOF_E_EXPECTED_TYPE_IDENTIFIER        = &H80044008&
%WBEMMOF_E_EXPECTED_OPEN_PAREN             = &H80044009&
%WBEMMOF_E_UNRECOGNIZED_TOKEN              = &H8004400a&
%WBEMMOF_E_UNRECOGNIZED_TYPE               = &H8004400b&
%WBEMMOF_E_EXPECTED_PROPERTY_NAME          = &H8004400c&
%WBEMMOF_E_TYPEDEF_NOT_SUPPORTED           = &H8004400d&
%WBEMMOF_E_UNEXPECTED_ALIAS                = &H8004400e&
%WBEMMOF_E_UNEXPECTED_ARRAY_INIT           = &H8004400f&
%WBEMMOF_E_INVALID_AMENDMENT_SYNTAX        = &H80044010&
%WBEMMOF_E_INVALID_DUPLICATE_AMENDMENT     = &H80044011&
%WBEMMOF_E_INVALID_PRAGMA                  = &H80044012&
%WBEMMOF_E_INVALID_NAMESPACE_SYNTAX        = &H80044013&
%WBEMMOF_E_EXPECTED_CLASS_NAME             = &H80044014&
%WBEMMOF_E_TYPE_MISMATCH                   = &H80044015&
%WBEMMOF_E_EXPECTED_ALIAS_NAME             = &H80044016&
%WBEMMOF_E_INVALID_CLASS_DECLARATION       = &H80044017&
%WBEMMOF_E_INVALID_INSTANCE_DECLARATION    = &H80044018&
%WBEMMOF_E_EXPECTED_DOLLAR                 = &H80044019&
%WBEMMOF_E_CIMTYPE_QUALIFIER               = &H8004401a&
%WBEMMOF_E_DUPLICATE_PROPERTY              = &H8004401b&
%WBEMMOF_E_INVALID_NAMESPACE_SPECIFICATION = &H8004401c&
%WBEMMOF_E_OUT_OF_RANGE                    = &H8004401d&
%WBEMMOF_E_INVALID_FILE                    = &H8004401e&
%WBEMMOF_E_ALIASES_IN_EMBEDDED             = &H8004401f&
%WBEMMOF_E_NULL_ARRAY_ELEM                 = &H80044020&
%WBEMMOF_E_DUPLICATE_QUALIFIER             = &H80044021&
%WBEMMOF_E_EXPECTED_FLAVOR_TYPE            = &H80044022&
%WBEMMOF_E_INCOMPATIBLE_FLAVOR_TYPES       = &H80044023&
%WBEMMOF_E_MULTIPLE_ALIASES                = &H80044024&
%WBEMMOF_E_INCOMPATIBLE_FLAVOR_TYPES2      = &H80044025&
%WBEMMOF_E_NO_ARRAYS_RETURNED              = &H80044026&
%WBEMMOF_E_MUST_BE_IN_OR_OUT               = &H80044027&
%WBEMMOF_E_INVALID_FLAGS_SYNTAX            = &H80044028&
%WBEMMOF_E_EXPECTED_BRACE_OR_BAD_TYPE      = &H80044029&
%WBEMMOF_E_UNSUPPORTED_CIMV22_QUAL_VALUE   = &H8004402a&
%WBEMMOF_E_UNSUPPORTED_CIMV22_DATA_TYPE    = &H8004402b&
%WBEMMOF_E_INVALID_DELETEINSTANCE_SYNTAX   = &H8004402c&
%WBEMMOF_E_INVALID_QUALIFIER_SYNTAX        = &H8004402d&
%WBEMMOF_E_QUALIFIER_USED_OUTSIDE_SCOPE    = &H8004402e&
%WBEMMOF_E_ERROR_CREATING_TEMP_FILE        = &H8004402f&
%WBEMMOF_E_ERROR_INVALID_INCLUDE_FILE      = &H80044030&
%WBEMMOF_E_INVALID_DELETECLASS_SYNTAX      = &H80044031&

' ########################################################################################
' Interface name = IWbemClassObject
' IID = {DC12A681-737F-11CF-884D-00AA004B2E24}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemClassObject_INTERFACE_DEFINED)
    %IWbemClassObject_INTERFACE_DEFINED = 1

$IID_IWbemClassObject = GUID$("{DC12A681-737F-11CF-884D-00AA004B2E24}")

INTERFACE IWbemClassObject $IID_IWbemClassObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetQualifierSet ( _                           ' VTable offset = 12
     BYREF ppQualSet AS IWbemQualifierSet _             ' __out IWbemQualifierSet **ppQualSet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Get ( _                                       ' VTable offset = 16
     BYREF wszName AS WSTRINGZ _                        ' __in LPCWSTR wszName
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF pVal AS VARIANT _                            ' __inout VARIANT *pVal
   , BYREF pType AS LONG _                              ' __inout CIMTYPE *pType
   , BYREF plFlavor AS LONG _                           ' __inout long *plFlavor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Put ( _                                       ' VTable offset = 20
     BYREF wszName AS WSTRINGZ _                        ' __in LPCWSTR wszName
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF pVal AS VARIANT _                            ' __in VARIANT *pVal
   , BYVAL Type AS LONG _                               ' __in CIMTYPE Type
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 24
     BYREF wszName AS WSTRINGZ _                        ' __in LPCWSTR wszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNames ( _                                  ' VTable offset = 28
     BYREF wszQualifierName AS WSTRINGZ _               ' __in LPCWSTR wszQualifierName
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF pQualifierVal AS VARIANT _                   ' __in VARIANT *pQualifierVal
   , BYREF pNames AS DWORD _                            ' __out SAFEARRAY (BSTR) **pNames
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginEnumeration ( _                          ' VTable offset = 32
     BYVAL lEnumFlags AS LONG _                         ' __in long lEnumFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 36
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF strName AS WSTRING _                         ' __inout BSTR *strName
   , BYREF pVal AS VARIANT _                            ' __inout VARIANT *pVal
   , BYREF pType AS LONG _                              ' __inout CIMTYPE *pType
   , BYREF plFlavor AS LONG _                           ' __inout long *plFlavor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndEnumeration ( _                            ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyQualifierSet ( _                   ' VTable offset = 44
     BYREF wszProperty AS WSTRINGZ _                    ' __in LPCWSTR wszProperty
   , BYREF ppQualSet AS IWbemQualifierSet _             ' __out IWbemQualifierSet **ppQualSet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 48
     BYREF ppCopy AS IWbemClassObject _                 ' __out IWbemClassObject **ppCopy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjectText ( _                             ' VTable offset = 52
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF pstrObjectText AS WSTRING _                  ' __out BSTR *pstrObjectText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SpawnDerivedClass ( _                         ' VTable offset = 56
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF ppNewClass AS IWbemClassObject _             ' __out IWbemClassObject **ppNewClass
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SpawnInstance ( _                             ' VTable offset = 60
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF ppNewInstance AS IWbemClassObject _          ' __out IWbemClassObject **ppNewInstance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareTo ( _                                 ' VTable offset = 64
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCompareTo AS IWbemClassObject _             ' __in IWbemClassObject *pCompareTo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyOrigin ( _                         ' VTable offset = 68
     BYREF wszName AS WSTRINGZ _                        ' __in LPCWSTR wszName
   , BYREF pstrClassName AS WSTRING _                   ' __out BSTR *pstrClassName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InheritsFrom ( _                              ' VTable offset = 72
     BYREF strAncestor AS WSTRINGZ _                    ' __in LPCWSTR strAncestor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMethod ( _                                 ' VTable offset = 76
     BYREF wszName AS WSTRINGZ _                        ' __in LPCWSTR wszName
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF ppInSignature AS IWbemClassObject _          ' __out IWbemClassObject **ppInSignature
   , BYREF ppOutSignature AS IWbemClassObject _         ' __out IWbemClassObject **ppOutSignature
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PutMethod ( _                                 ' VTable offset = 80
     BYREF wszName AS WSTRINGZ _                        ' __in LPCWSTR wszName
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pInSignature AS IWbemClassObject _           ' __in IWbemClassObject *pInSignature
   , BYVAL pOutSignature AS IWbemClassObject _          ' __in IWbemClassObject *pOutSignature
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteMethod ( _                              ' VTable offset = 84
     BYREF wszName AS WSTRINGZ _                        ' __in LPCWSTR wszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginMethodEnumeration ( _                    ' VTable offset = 88
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NextMethod ( _                                ' VTable offset = 92
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF pstrName AS WSTRING _                        ' __inout BSTR *pstrName
   , BYREF ppInSignature AS IWbemClassObject _          ' __inout IWbemClassObject **ppInSignature
   , BYREF ppOutSignature AS IWbemClassObject _         ' __inout IWbemClassObject **ppOutSignature
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndMethodEnumeration ( _                      ' VTable offset = 96
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMethodQualifierSet ( _                     ' VTable offset = 100
     BYREF wszMethod AS WSTRINGZ _                      ' __in LPCWSTR wszMethod
   , BYREF ppQualSet AS IWbemQualifierSet _             ' __out IWbemQualifierSet **ppQualSet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMethodOrigin ( _                           ' VTable offset = 104
     BYREF wszMethodName AS WSTRINGZ _                  ' __in LPCWSTR wszMethodName
   , BYREF pstrClassName AS WSTRING _                   ' __out BSTR *pstrClassName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemClassObject_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemObjectAccess
' IID = {49353C9A-516B-11D1-AEA6-00C04FB68820}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IWbemClassObject
' ########################################################################################

#IF NOT %DEF(%IWbemObjectAccess_INTERFACE_DEFINED)
    %IWbemObjectAccess_INTERFACE_DEFINED = 1

$IID_IWbemObjectAccess  = GUID$("{49353C9A-516B-11D1-AEA6-00C04FB68820}")

INTERFACE IWbemObjectAccess $IID_IWbemObjectAccess

   INHERIT IUnknown

   ' =====================================================================================
   ' IWbemClassObject Methods
   ' =====================================================================================
   METHOD GetQualifierSet ( _                           ' VTable offset = 12
     BYREF ppQualSet AS IWbemQualifierSet _             ' __out IWbemQualifierSet **ppQualSet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Get ( _                                       ' VTable offset = 16
     BYREF wszName AS WSTRINGZ _                        ' __in LPCWSTR wszName
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF pVal AS VARIANT _                            ' __inout VARIANT *pVal
   , BYREF pType AS LONG _                              ' __inout CIMTYPE *pType
   , BYREF plFlavor AS LONG _                           ' __inout long *plFlavor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Put ( _                                       ' VTable offset = 20
     BYREF wszName AS WSTRINGZ _                        ' __in LPCWSTR wszName
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF pVal AS VARIANT _                            ' __in VARIANT *pVal
   , BYVAL Type AS LONG _                               ' __in CIMTYPE Type
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 24
     BYREF wszName AS WSTRINGZ _                        ' __in LPCWSTR wszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNames ( _                                  ' VTable offset = 28
     BYREF wszQualifierName AS WSTRINGZ _               ' __in LPCWSTR wszQualifierName
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF pQualifierVal AS VARIANT _                   ' __in VARIANT *pQualifierVal
   , BYREF pNames AS DWORD _                            ' __out SAFEARRAY (BSTR) **pNames
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginEnumeration ( _                          ' VTable offset = 32
     BYVAL lEnumFlags AS LONG _                         ' __in long lEnumFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 36
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF strName AS WSTRING _                         ' __inout BSTR *strName
   , BYREF pVal AS VARIANT _                            ' __inout VARIANT *pVal
   , BYREF pType AS LONG _                              ' __inout CIMTYPE *pType
   , BYREF plFlavor AS LONG _                           ' __inout long *plFlavor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndEnumeration ( _                            ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyQualifierSet ( _                   ' VTable offset = 44
     BYREF wszProperty AS WSTRINGZ _                    ' __in LPCWSTR wszProperty
   , BYREF ppQualSet AS IWbemQualifierSet _             ' __out IWbemQualifierSet **ppQualSet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 48
     BYREF ppCopy AS IWbemClassObject _                 ' __out IWbemClassObject **ppCopy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjectText ( _                             ' VTable offset = 52
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF pstrObjectText AS WSTRING _                  ' __out BSTR *pstrObjectText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SpawnDerivedClass ( _                         ' VTable offset = 56
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF ppNewClass AS IWbemClassObject _             ' __out IWbemClassObject **ppNewClass
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SpawnInstance ( _                             ' VTable offset = 60
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF ppNewInstance AS IWbemClassObject _          ' __out IWbemClassObject **ppNewInstance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareTo ( _                                 ' VTable offset = 64
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCompareTo AS IWbemClassObject _             ' __in IWbemClassObject *pCompareTo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyOrigin ( _                         ' VTable offset = 68
     BYREF wszName AS WSTRINGZ _                        ' __in LPCWSTR wszName
   , BYREF pstrClassName AS WSTRING _                   ' __out BSTR *pstrClassName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InheritsFrom ( _                              ' VTable offset = 72
     BYREF strAncestor AS WSTRINGZ _                    ' __in LPCWSTR strAncestor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMethod ( _                                 ' VTable offset = 76
     BYREF wszName AS WSTRINGZ _                        ' __in LPCWSTR wszName
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF ppInSignature AS IWbemClassObject _          ' __out IWbemClassObject **ppInSignature
   , BYREF ppOutSignature AS IWbemClassObject _         ' __out IWbemClassObject **ppOutSignature
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PutMethod ( _                                 ' VTable offset = 80
     BYREF wszName AS WSTRINGZ _                        ' __in LPCWSTR wszName
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL ppInSignature AS IWbemClassObject _          ' __in IWbemClassObject *pInSignature
   , BYVAL ppOutSignature AS IWbemClassObject _         ' __in IWbemClassObject *pOutSignature
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteMethod ( _                              ' VTable offset = 84
     BYREF wszName AS WSTRINGZ _                        ' __in LPCWSTR wszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginMethodEnumeration ( _                    ' VTable offset = 88
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NextMethod ( _                                ' VTable offset = 92
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF pstrName AS WSTRING _                        ' __inout BSTR *pstrName
   , BYREF ppInSignature AS IWbemClassObject _          ' __inout IWbemClassObject **ppInSignature
   , BYREF ppOutSignature AS IWbemClassObject _         ' __inout IWbemClassObject **ppOutSignature
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndMethodEnumeration ( _                      ' VTable offset = 96
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMethodQualifierSet ( _                     ' VTable offset = 100
     BYREF wszMethod AS WSTRINGZ _                      ' __in LPCWSTR wszMethod
   , BYREF ppQualSet AS IWbemQualifierSet _             ' __out IWbemQualifierSet **ppQualSet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMethodOrigin ( _                           ' VTable offset = 104
     BYREF wszMethodName AS WSTRINGZ _                  ' __in LPCWSTR wszMethodName
   , BYREF pstrClassName AS WSTRING _                   ' __out BSTR *pstrClassName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWbemObjectAccess Methods
   ' =====================================================================================
   METHOD GetPropertyHandle ( _                         ' VTable offset = 108
     BYREF wszPropertyName AS WSTRINGZ _                ' __in LPCWSTR wszPropertyName
   , BYREF pType AS LONG _                              ' __out CIMTYPE *pType
   , BYREF plHandle AS LONG _                           ' __out long *plHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WritePropertyValue ( _                        ' VTable offset = 112
     BYVAL lHandle AS LONG _                            ' __in long lHandle
   , BYVAL lNumBytes AS LONG _                          ' __in long lNumBytes
   , BYVAL aData AS BYTE PTR _                          ' __in const byte *aData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReadPropertyValue ( _                         ' VTable offset = 116
     BYVAL lHandle AS LONG _                            ' __in long lHandle
   , BYVAL lBufferSize AS LONG _                        ' __in long lBufferSize
   , BYREF plNumBytes AS LONG _                         ' __out long *plNumBytes
   , BYVAL aData AS BYTE PTR _                          ' __out byte *aData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReadDWORD ( _                                 ' VTable offset = 120
     BYVAL lHandle AS LONG _                            ' __in long lHandle
   , BYREF pdw AS DWORD _                               ' __out DWORD *pdw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteDWORD ( _                                ' VTable offset = 124
     BYVAL lHandle AS LONG _                            ' __in long lHandle
   , BYVAL dw AS DWORD _                                ' __in DWORD dw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReadQWORD ( _                                 ' VTable offset = 128
     BYVAL lHandle AS LONG _                            ' __in long lHandle
   , BYREF pqw AS QUAD _                                ' __out unsigned __int64 *pqw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteQWORD ( _                                ' VTable offset = 132
     BYVAL lHandle AS LONG _                            ' __in long lHandle
   , BYREF pw AS QUAD _                                 ' __in unsigned __int64 pw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyInfoByHandle ( _                   ' VTable offset = 136
     BYVAL lHandle AS LONG _                            ' __in long lHandle
   , BYREF pstrName AS WSTRING _                        ' __out BSTR *pstrName
   , BYREF pType AS LONG _                              ' __out CIMTYPE *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Lock ( _                                      ' VTable offset = 140
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unlock ( _                                    ' VTable offset = 144
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemObjectAccess_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemQualifierSet
' IID = {DC12A680-737F-11CF-884D-00AA004B2E24}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemQualifierSet_INTERFACE_DEFINED)
    %IWbemQualifierSet_INTERFACE_DEFINED = 1

$IID_IWbemQualifierSet = GUID$("{DC12A680-737F-11CF-884D-00AA004B2E24}")

INTERFACE IWbemQualifierSet $IID_IWbemQualifierSet

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Get ( _                                       ' VTable offset = 12
     BYREF wszName AS WSTRINGZ _                        ' __in LPCWSTR wszName
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF pVal AS VARIANT _                            ' __inout VARIANT *pVal
   , BYREF plFlavor AS LONG _                           ' __inout long *plFlavor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Put ( _                                       ' VTable offset = 16
     BYREF wszName AS WSTRINGZ _                        ' __in LPCWSTR wszName
   , BYREF pVal AS VARIANT _                            ' __in VARIANT *pVal
   , BYVAL plFlavor AS LONG _                           ' __in long lFlavor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 20
     BYREF wszName AS WSTRINGZ _                        ' __in LPCWSTR wszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNames ( _                                  ' VTable offset = 24
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF pNames AS DWORD _                            ' __out SAFEARRAY (BSTR) **pNames
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginEnumeration ( _                          ' VTable offset = 28
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 32
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF pstrName AS WSTRING _                        ' __inout BSTR *pstrName
   , BYREF pVal AS VARIANT _                            ' __inout VARIANT *pVal
   , BYREF plFlavor AS LONG _                           ' __inout long *plFlavor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndEnumeration ( _                            ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemQualifierSet_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemServices
' IID = {9556DC99-828C-11CF-A37E-00AA003240C7}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemServices_INTERFACE_DEFINED)
    %IWbemServices_INTERFACE_DEFINED = 1

$IID_IWbemServices = GUID$("{9556DC99-828C-11CF-A37E-00AA003240C7}")

INTERFACE IWbemServices $IID_IWbemServices

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OpenNamespace ( _                             ' VTable offset = 12
     BYVAL strNamespace AS WSTRING _                    ' __in const BSTR strNamespace
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS DWORD _                              ' __in IWbemContext *pCtx
   , BYREF ppWorkingNamespace AS IWbemServices _        ' __inout IWbemServices **ppWorkingNamespace
   , BYREF ppResult AS IWbemCallResult _                ' __inout IWbemCallResult **ppResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CancelAsyncCall ( _                           ' VTable offset = 16
     BYVAL pSink AS IWbemObjectSink _                   ' __in IWbemObjectSink *pSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryObjectSink ( _                           ' VTable offset = 20
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF ppResponseHandler AS IWbemObjectSink _       ' __out IWbemObjectSink **ppResponseHandler
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObject ( _                                 ' VTable offset = 24
     BYVAL strObjectPath AS WSTRING _                   ' __in const BSTR strObjectPath
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYREF ppObject AS IWbemClassObject _               ' __inout IWbemClassObject **ppObject
   , BYREF ppCallResult AS IWbemCallResult _            ' __inout IWbemCallResult **ppCallResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjectAsync ( _                            ' VTable offset = 28
     BYVAL strObjectPath AS WSTRING _                   ' __in const BSTR strObjectPath
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYVAL pResponseHandler AS IWbemObjectSink _        ' __in IWbemObjectSink *pResponseHandler
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PutClass ( _                                  ' VTable offset = 32
     BYVAL pObject AS IWbemClassObject _                ' __in IWbemClassObject *pObject
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYREF ppCallResult AS IWbemCallResult _            ' __inout IWbemCallResult **ppCallResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PutClassAsync ( _                             ' VTable offset = 36
     BYVAL pObject AS IWbemClassObject _                ' __in IWbemClassObject *pObject
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYVAL ppCallResult AS IWbemObjectSink _            ' __in IWbemObjectSink *pResponseHandler
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteClass ( _                               ' VTable offset = 40
     BYVAL strClass AS WSTRING _                        ' __in const BSTR strClass
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYREF ppCallResult AS IWbemCallResult _            ' __inout IWbemCallResult **ppCallResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteClassAsync ( _                          ' VTable offset = 44
     BYVAL strClass AS WSTRING _                        ' __in const BSTR strClass
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYVAL pResponseHandler AS IWbemObjectSink _        ' __in IWbemObjectSink *pResponseHandler
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateClassEnum ( _                           ' VTable offset = 48
     BYVAL strSuperclass AS WSTRING _                   ' __in const BSTR strSuperclass
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYREF ppEnum AS IEnumWbemClassObject _             ' __out IEnumWbemClassObject **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateClassEnumAsync ( _                      ' VTable offset = 52
     BYVAL strSuperclass AS WSTRING _                   ' __in const BSTR strSuperclass
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYVAL pResponseHandler AS IWbemObjectSink _        ' __in IWbemObjectSink *pResponseHandler
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PutInstance ( _                               ' VTable offset = 56
     BYVAL pInst AS IWbemClassObject _                  ' __in IWbemClassObject *pInst
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYREF ppCallResult AS IWbemCallResult _            ' __inout IWbemCallResult **ppCallResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PutInstanceAsync ( _                          ' VTable offset = 60
     BYVAL pInst AS IWbemClassObject _                  ' __in IWbemClassObject *pInst
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYVAL pResponseHandler AS IWbemObjectSink _        ' __in IWbemObjectSink *pResponseHandler
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteInstance ( _                            ' VTable offset = 64
     BYVAL strObjectPath AS WSTRING _                   ' __in const BSTR strObjectPath
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYREF ppCallResult AS IWbemCallResult _            ' __inout IWbemCallResult **ppCallResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteInstanceAsync ( _                       ' VTable offset = 68
     BYVAL strObjectPath AS WSTRING _                   ' __in const BSTR strObjectPath
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYVAL pResponseHandler AS IWbemObjectSink _        ' __in IWbemObjectSink *pResponseHandler
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateInstanceEnum ( _                        ' VTable offset = 72
     BYVAL strFilter AS WSTRING _                       ' __in const BSTR strFilter
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYREF ppEnum AS IEnumWbemClassObject _             ' __out IEnumWbemClassObject **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateInstanceEnumAsync ( _                   ' VTable offset = 76
     BYVAL strFilter AS WSTRING _                       ' __in const BSTR strFilter
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYVAL pResponseHandler AS IWbemObjectSink _        ' __in IWbemObjectSink *pResponseHandler
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExecQuery ( _                                 ' VTable offset = 80
     BYVAL strQueryLanguage AS WSTRING _                ' __in const BSTR strQueryLanguage
   , BYVAL strQuery AS WSTRING _                        ' __in const BSTR strQuery
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYREF ppEnum AS IEnumWbemClassObject _             ' __out IEnumWbemClassObject **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExecQueryAsync ( _                            ' VTable offset = 84
     BYVAL strQueryLanguage AS WSTRING _                ' __in const BSTR strQueryLanguage
   , BYVAL strQuery AS WSTRING _                        ' __in const BSTR strQuery
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYVAL pResponseHandler AS IWbemObjectSink _        ' __in IWbemObjectSink *pResponseHandler
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExecNotificationQuery ( _                     ' VTable offset = 88
     BYVAL strQueryLanguage AS WSTRING _                ' __in const BSTR strQueryLanguage
   , BYVAL strQuery AS WSTRING _                        ' __in const BSTR strQuery
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYREF ppEnum AS IEnumWbemClassObject _             ' __out IEnumWbemClassObject **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExecNotificationQueryAsync ( _                ' VTable offset = 92
     BYVAL strQueryLanguage AS WSTRING _                ' __in const BSTR strQueryLanguage
   , BYVAL strQuery AS WSTRING _                        ' __in const BSTR strQuery
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYVAL pResponseHandler AS IWbemObjectSink _        ' __in IWbemObjectSink *pResponseHandler
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExecMethod ( _                                ' VTable offset = 96
     BYVAL strObjectPath AS WSTRING _                   ' __in const BSTR strObjectPath
   , BYVAL strMethodName AS WSTRING _                   ' __in const BSTR strMethodName
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYVAL pInParams AS IWbemClassObject _              ' __in IWbemClassObject *pInParams
   , BYREF ppOutParams AS IWbemClassObject _            ' __inout IWbemClassObject **ppOutParams
   , BYREF ppCallResult AS IWbemCallResult _            ' __inout IWbemCallResult **ppCallResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExecMethodAsync ( _                           ' VTable offset = 100
     BYVAL strObjectPath AS WSTRING _                   ' __in const BSTR strObjectPath
   , BYVAL strMethodName AS WSTRING _                   ' __in const BSTR strMethodName
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYVAL pInParams AS IWbemClassObject _              ' __in IWbemClassObject *pInParams
   , BYVAL pResponseHandler AS IWbemObjectSink _        ' __in IWbemObjectSink *pResponseHandler
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemServices_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemLocator
' IID = {DC12A687-737F-11CF-884D-00AA004B2E24}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemLocator_INTERFACE_DEFINED)
    %IWbemLocator_INTERFACE_DEFINED = 1

$IID_IWbemLocator = GUID$("{DC12A687-737F-11CF-884D-00AA004B2E24}")

INTERFACE IWbemLocator $IID_IWbemLocator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ConnectServer ( _                             ' VTable offset = 12
     BYVAL strNetworkResource AS WSTRING _              ' __in const BSTR strNetworkResource
   , BYVAL strUser AS WSTRING _                         ' __in const BSTR strUser
   , BYVAL strPassword AS WSTRING _                     ' __in const BSTR strPassword
   , BYVAL strLocale AS WSTRING _                       ' __in const BSTR strLocale
   , BYVAL lSecurityFlags AS LONG _                     ' __in long lSecurityFlags
   , BYVAL strAuthority AS WSTRING _                    ' __in const BSTR strAuthority
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYREF ppNamespace AS IWbemServices _               ' __out IWbemServices **ppNamespace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemLocator_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemObjectSink
' IID = {7C857801-7381-11CF-884D-00AA004B2E24}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemObjectSink_INTERFACE_DEFINED)
    %IWbemObjectSink_INTERFACE_DEFINED = 1

$IID_IWbemObjectSink = GUID$("{7C857801-7381-11CF-884D-00AA004B2E24}")

INTERFACE IWbemObjectSink $IID_IWbemObjectSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Indicate ( _                                  ' VTable offset = 12
     BYVAL lObjectCount AS LONG _                       ' __in long lObjectCount
   , BYREF apObjArray AS IWbemClassObject _             ' __in IWbemClassObject **apObjArray [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStatus ( _                                 ' VTable offset = 16
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL strParam AS WSTRING _                        ' __in BSTR strParam
   , BYVAL pObjParam AS IWbemClassObject _              ' __in IWbemClassObject *pObjParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemObjectSink_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumWbemClassObject
' IID = {027947E1-D731-11CE-A357-000000000001}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumWbemClassObject_INTERFACE_DEFINED)
    %IEnumWbemClassObject_INTERFACE_DEFINED = 1

$IID_IEnumWbemClassObject = GUID$("{027947E1-D731-11CE-A357-000000000001}")

INTERFACE IEnumWbemClassObject $IID_IEnumWbemClassObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 16
     BYVAL lTimeout AS LONG _                           ' __in long lTimeout
   , BYVAL uCount AS DWORD _                            ' __in ULONG uCount
   , BYREF apObjects AS IWbemClassObject _              ' __out IWbemClassObject **apObjects [array]
   , BYREF DWORD _                                      ' __out ULONG *puReturned
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NextAsync ( _                                 ' VTable offset = 20
     BYVAL uCount AS DWORD _                            ' __in ULONG uCount
   , BYVAL pSink AS IWbemObjectSink _                   ' __in IWbemObjectSink *pSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumWbemClassObject _             ' __out IEnumWbemClassObject **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 28
     BYVAL lTimeout AS LONG _                           ' __in long lTimeout
   , BYVAL nCount AS DWORD _                            ' __in ULONG nCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumWbemClassObject_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemCallResult
' IID = {44ACA675-E8FC-11D0-A07C-00C04FB68820}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemCallResult_INTERFACE_DEFINED)
    %IWbemCallResult_INTERFACE_DEFINED = 1

$IID_IWbemCallResult = GUID$("{44ACA675-E8FC-11D0-A07C-00C04FB68820}")

INTERFACE IWbemCallResult $IID_IWbemCallResult

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetResultObject ( _                           ' VTable offset = 12
     BYVAL lTimeout AS LONG _                           ' __in long lTimeout
   , BYREF ppResultObject AS IWbemClassObject _         ' __out IWbemClassObject **ppResultObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResultString ( _                           ' VTable offset = 16
     BYVAL lTimeout AS LONG _                           ' __in long lTimeout
   , BYREF pstrResultString AS WSTRING _                ' __out BSTR *pstrResultString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResultServices ( _                         ' VTable offset = 20
     BYVAL lTimeout AS LONG _                           ' __in long lTimeout
   , BYREF ppServices AS IWbemServices _                ' __out IWbemServices **ppServices
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCallStatus ( _                             ' VTable offset = 24
     BYVAL lTimeout AS LONG _                           ' __in long lTimeout
   , BYREF plStatus AS LONG _                           ' __out long *plStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemCallResult_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemContext
' IID = {44ACA674-E8FC-11D0-A07C-00C04FB68820}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemContext_INTERFACE_DEFINED)
    %IWbemContext_INTERFACE_DEFINED = 1

$IID_IWbemContext = GUID$("{44ACA674-E8FC-11D0-A07C-00C04FB68820}")

INTERFACE IWbemContext $IID_IWbemContext

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 12
     BYREF ppNewCopy AS IUnknown _                      ' __out IWbemContext **ppNewCopy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNames ( _                                  ' VTable offset = 16
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF pNames AS DWORD _                            ' __out SAFEARRAY (BSTR)**pNames
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginEnumeration ( _                          ' VTable offset = 20
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 24
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF pstrName AS WSTRING _                        ' __out BSTR *pstrName
   , BYREF pValue AS VARIANT _                          ' __out VARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndEnumeration ( _                            ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetValue ( _                                  ' VTable offset = 32
     BYREF wszName AS WSTRINGZ _                        ' __in LPCWSTR wszName
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF pValue AS VARIANT _                          ' __in VARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 36
     BYREF wszName AS WSTRINGZ _                        ' __in LPCWSTR wszName
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF pValue AS VARIANT _                          ' __out VARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteValue ( _                               ' VTable offset = 40
     BYREF wszName AS WSTRINGZ _                        ' __in LPCWSTR wszName
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAll ( _                                 ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUnsecuredApartment
' IID = 1CFABA8C-1523-11D1-AD79-00C04FD8FDFF
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUnsecuredApartment_INTERFACE_DEFINED)
    %IUnsecuredApartment_INTERFACE_DEFINED = 1

$IID_IUnsecuredApartment = GUID$("{1CFABA8C-1523-11D1-AD79-00C04FD8FDFF}")

INTERFACE IUnsecuredApartment $IID_IUnsecuredApartment

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateObjectStub ( _                          ' VTable offset = 12
     BYVAL pObject AS IUnknown _                        ' __in IUnknown *pObject
   , BYREF ppStub AS IUnknown _                         ' __out IUnknown **ppStub
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUnsecuredApartment_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemUnsecuredApartment
' IID = 31739D04-3471-4CF4-9A7C-57A44AE71956
' Inherited interface = IUnsecuredApartment
' ########################################################################################

#IF NOT %DEF(%IWbemUnsecuredApartment_INTERFACE_DEFINED)
    %IWbemUnsecuredApartment_INTERFACE_DEFINED = 1

$IID_IWbemUnsecuredApartment = GUID$("{31739D04-3471-4CF4-9A7C-57A44AE71956}")

INTERFACE IWbemUnsecuredApartment $IID_IWbemUnsecuredApartment

   INHERIT IUnknown

   ' =====================================================================================
   ' IUnsecuredApartment Methods
   ' =====================================================================================
   METHOD CreateObjectStub ( _                          ' VTable offset = 12
     BYVAL pObject AS IUnknown _                        ' __in IUnknown *pObject
   , BYREF ppStub AS IUnknown _                         ' __out IUnknown **ppStub
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWbemUnsecuredApartment Methods
   ' =====================================================================================
   METHOD CreateSinkStub ( _                            ' VTable offset = 16
     BYVAL pSink AS IWbemObjectSink _                   ' __in IWbemObjectSink *pSink
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF wszReserved AS WSTRINGZ _                    ' __in LPCWSTR wszReserved
   , BYREF ppStub AS IWbemObjectSink _                  ' __out IWbemObjectSink **ppStub
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemUnsecuredApartment_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemStatusCodeText
' IID = EB87E1BC-3233-11D2-AEC9-00C04FB68820
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemStatusCodeText_INTERFACE_DEFINED)
    %IWbemStatusCodeText_INTERFACE_DEFINED = 1

$IID_IWbemStatusCodeText = GUID$("{EB87E1BC-3233-11D2-AEC9-00C04FB68820}")

INTERFACE IWbemStatusCodeText $IID_IWbemStatusCodeText

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetErrorCodeText ( _                          ' VTable offset = 12
     BYVAL hRes AS LONG _                               ' __in HRESULT hRes
   , BYVAL LocaleId AS DWORD _                          ' __in LCID LocaleId
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF MessageText AS WSTRING _                     ' __out BSTR *MessageText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFacilityCodeText ( _                       ' VTable offset = 16
     BYVAL hRes AS LONG _                               ' __in HRESULT hRes
   , BYVAL LocaleId AS DWORD _                          ' __in LCID LocaleId
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF MessageText AS WSTRING _                     ' __out BSTR *MessageText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemStatusCodeText_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemBackupRestore
' IID = C49E32C7-BC8B-11D2-85D4-00105A1F8304
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemBackupRestore_INTERFACE_DEFINED)
    %IWbemBackupRestore_INTERFACE_DEFINED = 1

$IID_IWbemBackupRestore = GUID$("{C49E32C7-BC8B-11D2-85D4-00105A1F8304}")

INTERFACE IWbemBackupRestore $IID_IWbemBackupRestore

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Backup ( _                                    ' VTable offset = 12
     BYREF strBackupToFile AS WSTRINGZ _                ' __in LPCWSTR strBackupToFile
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Restore ( _                                   ' VTable offset = 16
     BYREF strRestoreFromFile AS WSTRINGZ _             ' __in LPCWSTR strRestoreFromFile
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemBackupRestore_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemBackupRestoreEx
' IID = A359DEC5-E813-4834-8A2A-BA7F1D777D76
' Inherited interface = IWbemBackupRestore
' ########################################################################################

#IF NOT %DEF(%IWbemBackupRestoreEx_INTERFACE_DEFINED)
    %IWbemBackupRestoreEx_INTERFACE_DEFINED = 1

$IID_IWbemBackupRestoreEx = GUID$("{A359DEC5-E813-4834-8A2A-BA7F1D777D76}")

INTERFACE IWbemBackupRestoreEx $IID_IWbemBackupRestoreEx

   INHERIT IUnknown

   ' =====================================================================================
   ' IWbemBackupRestore Methods
   ' =====================================================================================
   METHOD Backup ( _                                    ' VTable offset = 12
     BYREF strBackupToFile AS WSTRINGZ _                ' __in LPCWSTR strBackupToFile
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Restore ( _                                   ' VTable offset = 16
     BYREF strRestoreFromFile AS WSTRINGZ _             ' __in LPCWSTR strRestoreFromFile
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWbemBackupRestoreEx Methods
   ' =====================================================================================
   METHOD Pause ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Resume ( _                                    ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemBackupRestoreEx_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemRefresher
' IID = {49353C99-516B-11D1-AEA6-00C04FB68820}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemRefresher_INTERFACE_DEFINED)
    %IWbemRefresher_INTERFACE_DEFINED = 1

$IID_IWbemRefresher = GUID$("{49353C99-516B-11D1-AEA6-00C04FB68820}")

INTERFACE IWbemRefresher $IID_IWbemRefresher

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Refresh ( _                                   ' VTable offset = 12
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemRefresher_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemHiPerfEnum
' IID = {2705C288-79AE-11D2-B348-00105A1F8177}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemHiPerfEnum_INTERFACE_DEFINED)
    %IWbemHiPerfEnum_INTERFACE_DEFINED = 1

$IID_IWbemHiPerfEnum = GUID$("{2705C288-79AE-11D2-B348-00105A1F8177}")

INTERFACE IWbemHiPerfEnum $IID_IWbemHiPerfEnum

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddObjects ( _                                ' VTable offset = 12
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL uNumObjects AS DWORD _                       ' __in ULONG uNumObjects
   , BYREF apIds AS LONG _                              ' __in long *apIds
   , BYREF apObj AS IWbemObjectAccess _                 ' __in IWbemObjectAccess **apObj [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveObjects ( _                             ' VTable offset = 16
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL uNumObjects AS DWORD _                       ' __in ULONG uNumObjects
   , BYREF apIds AS LONG _                              ' __in long *apIds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjects ( _                                ' VTable offset = 20
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL uNumObjects AS DWORD _                       ' __in ULONG uNumObjects
   , BYREF apObj AS IWbemObjectAccess _                 ' __out IWbemObjectAccess **apObj [array]
   , BYREF puReturned AS DWORD _                        ' __out ULONG *puReturned
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAll ( _                                 ' VTable offset = 24
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemHiPerfEnum_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemConfigureRefresher
' IID = 49353C92-516B-11D1-AEA6-00C04FB68820
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemConfigureRefresher_INTERFACE_DEFINED)
    %IWbemConfigureRefresher_INTERFACE_DEFINED = 1

$IID_IWbemConfigureRefresher = GUID$("{49353C92-516B-11D1-AEA6-00C04FB68820}")

INTERFACE IWbemConfigureRefresher $IID_IWbemConfigureRefresher

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddObjectByPath ( _                           ' VTable offset = 12
     BYVAL pNamespace AS IWbemServices _                ' __in IWbemServices *pNamespace
   , BYREF wszPath AS WSTRINGZ _                        ' __in LPCWSTR wszPath
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pContext AS IWbemContext _                   ' __in IWbemContext *pContext
   , BYREF ppRefreshable AS IWbemClassObject _          ' __out IWbemClassObject **ppRefreshable
   , BYREF plId AS LONG _                               ' __inout long *plId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddObjectByTemplate ( _                       ' VTable offset = 16
     BYVAL pNamespace AS IWbemServices _                ' __in IWbemServices *pNamespace
   , BYVAL pTemplate AS IWbemClassObject _              ' __in IWbemClassObject *pTemplate
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pContext AS IWbemContext _                   ' __in IWbemContext *pContext
   , BYREF ppRefreshable AS IWbemClassObject _          ' __out IWbemClassObject **ppRefreshable
   , BYREF plId AS LONG _                               ' __inout long *plId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddRefresher ( _                              ' VTable offset = 20
     BYVAL pRefresher AS IWbemRefresher _               ' __in IWbemRefresher *pRefresher
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF plId AS LONG _                               ' __inout long *plId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Remove ( _                                    ' VTable offset = 24
     BYVAL lId AS LONG _                                ' __in long lId
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddEnum ( _                                   ' VTable offset = 28
     BYVAL pNamespace AS IWbemServices _                ' __in IWbemServices *pNamespace
   , BYREF wszClassName AS WSTRINGZ _                   ' __in LPCWSTR wszClassName
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pContext AS IWbemContext _                   ' __in IWbemContext *pContext
   , BYREF ppEnum AS IWbemHiPerfEnum _                  ' __out IWbemHiPerfEnum **ppEnum
   , BYREF plId AS LONG _                               ' __inout long *plId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemConfigureRefresher_INTERFACE_DEFINED__ */


$CLSID_WbemLocator        = GUID$("{4590F811-1D3A-11D0-891F-00AA004B2E24}")
$CLSID_WbemContext        = GUID$("{674B6698-EE92-11D0-AD71-00C04FD8FDFF}")
$CLSID_UnsecuredApartment = GUID$("{49BD2028-1523-11D1-AD79-00C04FD8FDFF}")
$CLSID_WbemClassObject    = GUID$("{9A653086-174F-11D2-B5F9-00104B703EFD}")
$CLSID_MofCompiler        = GUID$("{6DAF9757-2E37-11D2-AEC9-00C04FB68820}")
$CLSID_WbemStatusCodeText = GUID$("{EB87E1BD-3233-11D2-AEC9-00C04FB68820}")
$CLSID_WbemBackupRestore  = GUID$("{C49E32C6-BC8B-11D2-85D4-00105A1F8304}")
$CLSID_WbemRefresher      = GUID$("{C71566F2-561E-11D1-AD87-00C04FD8FDFF}")
$CLSID_WbemObjectTextSrc  = GUID$("{8D1C559D-84F0-4BB3-A7D5-56A7435A9BA6}")

' ########################################################################################
' Interface name = IWbemShutdown
' IID = B7B31DF9-D515-11D3-A11C-00105A1F515A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemShutdown_INTERFACE_DEFINED)
    %IWbemShutdown_INTERFACE_DEFINED = 1

$IID_IWbemShutdown = GUID$("{B7B31DF9-D515-11D3-A11C-00105A1F515A}")

INTERFACE IWbemShutdown $IID_IWbemShutdown

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Shutdown ( _                                  ' VTable offset = 12
     BYVAL uReason AS DWORD _                           ' __in LONG uReason
   , BYVAL uMaxMilliseconds AS DWORD _                  ' __in ULONG uMaxMilliseconds
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE
' ========================================================================================

#ENDIF   ' /* __IWbemShutdown_INTERFACE_DEFINED__ */


%WMI_OBJ_TEXT_CIM_DTD_2_0 = 1&
%WMI_OBJ_TEXT_WMI_DTD_2_0 = 2&
%WMI_OBJ_TEXT_WMI_EXT1    = 3&
%WMI_OBJ_TEXT_WMI_EXT2    = 4&
%WMI_OBJ_TEXT_WMI_EXT3    = 5&
%WMI_OBJ_TEXT_WMI_EXT4    = 6&
%WMI_OBJ_TEXT_WMI_EXT5    = 7&
%WMI_OBJ_TEXT_WMI_EXT6    = 8&
%WMI_OBJ_TEXT_WMI_EXT7    = 9&
%WMI_OBJ_TEXT_WMI_EXT8    = 10&
%WMI_OBJ_TEXT_WMI_EXT9    = 11&
%WMI_OBJ_TEXT_WMI_EXT10   = 12&
%WMI_OBJ_TEXT_LAST        = 13&

' ########################################################################################
' Interface name = IWbemObjectTextSrc
' IID = BFBF883A-CAD7-11D3-A11B-00105A1F515A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemObjectTextSrc_INTERFACE_DEFINED)
    %IWbemObjectTextSrc_INTERFACE_DEFINED = 1

$IID_IWbemObjectTextSrc = GUID$("{BFBF883A-CAD7-11D3-A11B-00105A1F515A}")

INTERFACE IWbemObjectTextSrc $IID_IWbemObjectTextSrc

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetText ( _                                   ' VTable offset = 12
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pObj AS IWbemClassObject _                   ' __in IWbemClassObject *pObj
   , BYVAL uObjTextFormat AS DWORD _                    ' __in ULONG uObjTextFormat
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYREF strText AS WSTRING _                         ' __out BSTR *strText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateFromText ( _                            ' VTable offset = 16
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL strText AS WSTRING _                         ' __in BSTR strText
   , BYVAL uObjTextFormat AS DWORD _                    ' __in ULONG uObjTextFormat
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYREF pNewObj AS IWbemClassObject _                ' __out IWbemClassObject **pNewObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemObjectTextSrc_INTERFACE_DEFINED__ */

' // Size = 24 bytes
TYPE WBEM_COMPILE_STATUS_INFO DWORD
   lPhaseError AS LONG    ' long lPhaseError
   hRes        AS LONG    ' HRESULT hRes
   ObjectNum   AS LONG    ' long ObjectNum
   FirstLine   AS LONG    ' long FirstLine
   LastLine    AS LONG    ' long LastLine
   dwOutFlags  AS DWORD   ' DWORD dwOutFlags
END TYPE

%WBEM_FLAG_CHECK_ONLY       = &H1&
%WBEM_FLAG_AUTORECOVER      = &H2&
%WBEM_FLAG_WMI_CHECK        = &H4&
%WBEM_FLAG_CONSOLE_PRINT    = &H8&
%WBEM_FLAG_DONT_ADD_TO_LIST = &H10&
%WBEM_FLAG_SPLIT_FILES      = &H20&
%WBEM_FLAG_STORE_FILE       = &H100&

%WBEM_FLAG_CONNECT_REPOSITORY_ONLY = &H40&
%WBEM_FLAG_CONNECT_USE_MAX_WAIT    = &H80&
%WBEM_FLAG_CONNECT_PROVIDERS       = &H100&

' ########################################################################################
' Interface name = IWbemObjectTextSrc
' IID = 6DAF974E-2E37-11D2-AEC9-00C04FB68820
' Inherited interface = IUnknown
' The IMofCompiler interface, implemented by Mofd.dll, provides a COM interface used by
' the MOF compiler and any other applications that need to compile MOF files. Objects can
' be obtained using the CLSID_MofCompiler CLSID value.
' ########################################################################################

#IF NOT %DEF(%IMofCompiler_INTERFACE_DEFINED)
    %IMofCompiler_INTERFACE_DEFINED = 1

$IID_IMofCompiler = GUID$("{6DAF974E-2E37-11D2-AEC9-00C04FB68820}")

INTERFACE IMofCompiler $IID_IMofCompiler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CompileFile ( _                               ' VTable offset = 12
     BYREF FileName AS WSTRINGZ _                       ' __in LPWSTR FileName
   , BYREF ServerAndNamespace AS WSTRINGZ _             ' __in LPWSTR ServerAndNamespace
   , BYREF User AS WSTRINGZ _                           ' __in LPWSTR User
   , BYREF Authority AS WSTRINGZ _                      ' __in LPWSTR Authority
   , BYREF Password AS WSTRINGZ _                       ' __in LPWSTR Password
   , BYVAL lOptionFlags AS LONG _                       ' __in LONG lOptionFlags
   , BYVAL lClassFlags AS LONG _                        ' __in LONG lClassFlags
   , BYVAL lInstanceFlags AS LONG _                     ' __in LONG lInstanceFlags
   , BYREF pInfo AS LONG _                              ' __inout WBEM_COMPILE_STATUS_INFO *pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompileBuffer ( _                             ' VTable offset = 16
     BYVAL BuffSize AS LONG _                           ' __in long BuffSize
   , BYVAL pBuffer AS BYTE PTR _                        ' __in BYTE *pBuffer
   , BYREF ServerAndNamespace AS WSTRINGZ _             ' __in LPWSTR ServerAndNamespace
   , BYREF User AS WSTRINGZ _                           ' __in LPWSTR User
   , BYREF Authority AS WSTRINGZ _                      ' __in LPWSTR Authority
   , BYREF Password AS WSTRINGZ _                       ' __in LPWSTR Password
   , BYVAL lOptionFlags AS LONG _                       ' __in LONG lOptionFlags
   , BYVAL lClassFlags AS LONG _                        ' __in LONG lClassFlags
   , BYVAL lInstanceFlags AS LONG _                     ' __in LONG lInstanceFlags
   , BYREF pInfo AS LONG _                              ' __inout WBEM_COMPILE_STATUS_INFO *pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBMOF ( _                                ' VTable offset = 20
     BYREF TextFileName AS WSTRINGZ _                   ' __in LPWSTR TextFileName
   , BYREF BMOFFileName AS WSTRINGZ _                   ' __in LPWSTR BMOFFileName
   , BYREF ServerAndNamespace AS WSTRINGZ _             ' __in LPWSTR ServerAndNamespace
   , BYVAL lOptionFlags AS LONG _                       ' __in LONG lOptionFlags
   , BYVAL lClassFlags AS LONG _                        ' __in LONG lClassFlags
   , BYVAL lInstanceFlags AS LONG _                     ' __in LONG lInstanceFlags
   , BYREF pInfo AS LONG _                              ' __inout WBEM_COMPILE_STATUS_INFO *pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMofCompiler_INTERFACE_DEFINED__ */


%WBEM_FLAG_UNSECAPP_DEFAULT_CHECK_ACCESS = 0&
%WBEM_FLAG_UNSECAPP_CHECK_ACCESS         = 1&
%WBEM_FLAG_UNSECAPP_DONT_CHECK_ACCESS    = 2&

%WBEM_FLAG_SHORT_NAME = &H1&
%WBEM_FLAG_LONG_NAME  = &H2&
