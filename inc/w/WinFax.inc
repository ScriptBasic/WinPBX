' ########################################################################################
' Microsoft Windows
' File: WinFax.inc
' Contents: This module contains the WIN32 FAX APIs.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINFAS_INC = 1

#INCLUDE ONCE "tapi.inc"

'//
'// FAX ERROR CODES
'//

%FAX_ERR_START                                  = 7001&   ' // First fax specific error code

%FAX_ERR_SRV_OUTOFMEMORY                        = 7001&
%FAX_ERR_GROUP_NOT_FOUND                        = 7002&
%FAX_ERR_BAD_GROUP_CONFIGURATION                = 7003&
%FAX_ERR_GROUP_IN_USE                           = 7004&
%FAX_ERR_RULE_NOT_FOUND                         = 7005&
%FAX_ERR_NOT_NTFS                               = 7006&
%FAX_ERR_DIRECTORY_IN_USE                       = 7007&
%FAX_ERR_FILE_ACCESS_DENIED                     = 7008&
%FAX_ERR_MESSAGE_NOT_FOUND                      = 7009&
%FAX_ERR_DEVICE_NUM_LIMIT_EXCEEDED              = 7010&
%FAX_ERR_NOT_SUPPORTED_ON_THIS_SKU              = 7011&
%FAX_ERR_VERSION_MISMATCH                       = 7012&   ' // Fax client/server versions mismtach
%FAX_ERR_RECIPIENTS_LIMIT                       = 7013&   ' // Recipients limit in a single broadcast

%FAX_ERR_END                                    = 7013&   ' // Last fax specific error code


'//
'// MessageId: FAX_E_SRV_OUTOFMEMORY
'//
'// MessageText:
'//
'//  The fax server failed to allocate memory.
'//
'#define FAX_E_SRV_OUTOFMEMORY                MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, FAX_ERR_SRV_OUTOFMEMORY)
%FAX_E_SRV_OUTOFMEMORY = &H80041B59&

'//
'// MessageId: FAX_E_GROUP_NOT_FOUND
'//
'// MessageText:
'//
'//  The fax server failed to locate an outbound routing group by name.
'//
'#define FAX_E_GROUP_NOT_FOUND                MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, FAX_ERR_GROUP_NOT_FOUND)
%FAX_E_GROUP_NOT_FOUND = &H80041B5A&

'//
'// MessageId: FAX_E_BAD_GROUP_CONFIGURATION
'//
'// MessageText:
'//
'//  The fax server encountered an outbound routing group with bad configuration.
'//
'#define FAX_E_BAD_GROUP_CONFIGURATION        MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, FAX_ERR_BAD_GROUP_CONFIGURATION)
%FAX_E_BAD_GROUP_CONFIGURATION = &H080041B5B&

'//
'// MessageId: FAX_E_GROUP_IN_USE
'//
'// MessageText:
'//
'//  The fax server cannot remove an outbound routing group because it is in use by one or more outbound routing rules.
'//
'#define FAX_E_GROUP_IN_USE                   MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, FAX_ERR_GROUP_IN_USE)
%FAX_E_GROUP_IN_USE = &H80041B5C&

'//
'// MessageId: FAX_E_RULE_NOT_FOUND
'//
'// MessageText:
'//
'//  The fax server failed to locate an outbound routing rule by country code and area code.
'//
'#define FAX_E_RULE_NOT_FOUND                 MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, FAX_ERR_RULE_NOT_FOUND)
%FAX_E_RULE_NOT_FOUND = &H80041B5D&

'//
'// MessageId: FAX_E_NOT_NTFS
'//
'// MessageText:
'//
'//  The fax server cannot set an archive folder to a non-NTFS partition.
'//
'#define FAX_E_NOT_NTFS                       MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, FAX_ERR_NOT_NTFS)
%FAX_E_NOT_NTFS = &H80041B5E&

'//
'// MessageId: FAX_E_DIRECTORY_IN_USE
'//
'// MessageText:
'//
'//  The fax server cannot use the same folder for both the inbox and the sent-items archives.
'//
'#define FAX_E_DIRECTORY_IN_USE               MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, FAX_ERR_DIRECTORY_IN_USE)
%FAX_E_DIRECTORY_IN_USE = &H80041B5F&

'//
'// MessageId: FAX_E_FILE_ACCESS_DENIED
'//
'// MessageText:
'//
'//  The fax server cannot access the specified file or folder.
'//
'#define FAX_E_FILE_ACCESS_DENIED             MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, FAX_ERR_FILE_ACCESS_DENIED)
%FAX_E_FILE_ACCESS_DENIED = &H80041B60&

'//
'// MessageId: FAX_E_MESSAGE_NOT_FOUND
'//
'// MessageText:
'//
'//  The fax server cannot find the job or message by its ID.
'//
'#define FAX_E_MESSAGE_NOT_FOUND              MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, FAX_ERR_MESSAGE_NOT_FOUND)
%FAX_E_MESSAGE_NOT_FOUND = &H80041B61&

'//
'// MessageId: FAX_E_DEVICE_NUM_LIMIT_EXCEEDED
'//
'// MessageText:
'//
'//  The fax server cannot complete the operation because the number of active fax devices allowed for this version of Windows was exceeded.
'//
'#define FAX_E_DEVICE_NUM_LIMIT_EXCEEDED      MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, FAX_ERR_DEVICE_NUM_LIMIT_EXCEEDED)
%FAX_E_DEVICE_NUM_LIMIT_EXCEEDED = &H80041B62&

'//
'// MessageId: FAX_E_NOT_SUPPORTED_ON_THIS_SKU
'//
'// MessageText:
'//
'//  The fax server cannot complete the operation because it is not supported for this version of Windows.
'//
'#define FAX_E_NOT_SUPPORTED_ON_THIS_SKU      MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, FAX_ERR_NOT_SUPPORTED_ON_THIS_SKU)
%FAX_E_NOT_SUPPORTED_ON_THIS_SKU = &H80041B63&

'//
'// MessageId: FAX_E_VERSION_MISMATCH
'//
'// MessageText:
'//
'//  The fax server API version does not support the requested operation.
'//
'#define FAX_E_VERSION_MISMATCH               MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, FAX_ERR_VERSION_MISMATCH)
%FAX_E_VERSION_MISMATCH = &H80041B64&

'//
'// MessageId: FAX_E_RECIPIENT_LIMIT
'//
'// MessageText:
'//
'// The limit on the number of recipients for a single fax broadcast was reached.
'//
'#define FAX_E_RECIPIENTS_LIMIT               MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, FAX_ERR_RECIPIENTS_LIMIT)
%FAX_E_RECIPIENTS_LIMIT = &H80041B65&

' enum FAX_ENUM_LOG_LEVELS
%FAXLOG_LEVEL_NONE = 0
%FAXLOG_LEVEL_MIN  = 1
%FAXLOG_LEVEL_MED  = 2
%FAXLOG_LEVEL_MAX  = 3

' enum FAX_ENUM_LOG_CATEGORIES
%FAXLOG_CATEGORY_INIT     = 1       ' // Initialization / shutdown
%FAXLOG_CATEGORY_OUTBOUND = 2       ' // Outbound messages
%FAXLOG_CATEGORY_INBOUND  = 3       ' // Inbound messages
%FAXLOG_CATEGORY_UNKNOWN  = 4       ' // Unknown category (all others)

' // Size = 12 bytes
TYPE FAX_LOG_CATEGORYA DWORD
   Name     AS ASCIIZ PTR   ' LPCSTR // logging category name
   Category AS DWORD        ' DWORD // logging category number
   Level    AS DWORD        ' DWORD // logging level for the category
END TYPE

' // Size = 12 bytes
TYPE FAX_LOG_CATEGORYW DWORD
   Name     AS WSTRINGZ PTR   ' LPCWSTR // logging category name
   Category AS DWORD          ' DWORD // logging category number
   Level    AS DWORD          ' DWORD // logging level for the category
END TYPE

#IF %DEF(%UNICODE)
   MACRO FAX_LOG_CATEGORY = FAX_LOG_CATEGORYW
#ELSE
   MACRO FAX_LOG_CATEGORY = FAX_LOG_CATEGORYA
#ENDIF

' // Size = 4 bytes
TYPE FAX_TIME WORD
   Hour   AS WORD   ' WORD
   Minute AS WORD   ' WORD
END TYPE

' // Size = 52 bytes
TYPE FAX_CONFIGURATIONA DWORD
   SizeOfStruct         AS DWORD        ' DWORD // size of this structure
   Retries              AS DWORD        ' DWORD // number of retries for fax send
   RetryDelay           AS DWORD        ' DWORD // number of minutes between retries
   DirtyDays            AS DWORD        ' DWORD // number of days to keep an unsent job in the queue
   Branding             AS LONG         ' BOOL // fsp should brand outgoing faxes
   UseDeviceTsid        AS LONG         ' BOOL // server uses device tsid only
   ServerCp             AS LONG         ' BOOL // clients must use cover pages on the server
   PauseServerQueue     AS LONG         ' BOOL // is the server queue paused?
   StartCheapTime       AS FAX_TIME     ' FAX_TIME // start of discount rate period
   StopCheapTime        AS FAX_TIME     ' FAX_TIME // end of discount rate period
   ArchiveOutgoingFaxes AS LONG         ' BOOL // whether outgoing faxes should be archived
   ArchiveDirectory     AS ASCIIZ PTR   ' LPCSTR // archive directory for outgoing faxes
   Reserved             AS ASCIIZ PTR   ' LPCSTR // Reserved; must be NULL
END TYPE

' // Size = 52 bytes
TYPE FAX_CONFIGURATIONW DWORD
   SizeOfStruct         AS DWORD          ' DWORD // size of this structure
   Retries              AS DWORD          ' DWORD // number of retries for fax send
   RetryDelay           AS DWORD          ' DWORD // number of minutes between retries
   DirtyDays            AS DWORD          ' DWORD // number of days to keep an unsent job in the queue
   Branding             AS LONG           ' BOOL // fsp should brand outgoing faxes
   UseDeviceTsid        AS LONG           ' BOOL // server uses device tsid only
   ServerCp             AS LONG           ' BOOL // clients must use cover pages on the server
   PauseServerQueue     AS LONG           ' BOOL // is the server queue paused?
   StartCheapTime       AS FAX_TIME       ' FAX_TIME // start of discount rate period
   StopCheapTime        AS FAX_TIME       ' FAX_TIME // end of discount rate period
   ArchiveOutgoingFaxes AS LONG           ' BOOL // whether outgoing faxes should be archived
   ArchiveDirectory     AS WSTRINGZ PTR   ' LPCWSTR // archive directory for outgoing faxes
   Reserved             AS WSTRINGZ PTR   ' LPCWSTR // Reserved; must be NULL
END TYPE

#IF %DEF(%UNICODE)
   MACRO FAX_CONFIGURATION = FAX_CONFIGURATIONW
#ELSE
   MACRO FAX_CONFIGURATION = FAX_CONFIGURATIONA
#ENDIF

'//
'// FaxSetJob() command codes
'//

' enum FAX_ENUM_JOB_COMMANDS
%JC_UNKNOWN = 0
%JC_DELETE  = 1
%JC_PAUSE   = 2
%JC_RESUME  = 3

%JC_RESTART = %JC_RESUME


'//
'// job type defines
'//

%JT_UNKNOWN                  = 0
%JT_SEND                     = 1
%JT_RECEIVE                  = 2
%JT_ROUTING                  = 3
%JT_FAIL_RECEIVE             = 4

'//
'// job status defines
'//
%JS_PENDING                  = &H00000000???
%JS_INPROGRESS               = &H00000001???
%JS_DELETING                 = &H00000002???
%JS_FAILED                   = &H00000004???
%JS_PAUSED                   = &H00000008???
%JS_NOLINE                   = &H00000010???
%JS_RETRYING                 = &H00000020???
%JS_RETRIES_EXCEEDED         = &H00000040???

' // Size = 88 bytes
TYPE FAX_DEVICE_STATUSA DWORD
   SizeOfStruct  AS DWORD        ' DWORD // size of this structure
   CallerId      AS ASCIIZ PTR   ' LPCSTR // caller id string
   Csid          AS ASCIIZ PTR   ' LPCSTR // station identifier
   CurrentPage   AS DWORD        ' DWORD // current page
   DeviceId      AS DWORD        ' DWORD // permanent line id
   DeviceName    AS ASCIIZ PTR   ' LPCSTR // device name
   DocumentName  AS ASCIIZ PTR   ' LPCSTR // document name
   JobType       AS DWORD        ' DWORD // send or receive?
   PhoneNumber   AS ASCIIZ PTR   ' LPCSTR // sending phone number
   RoutingString AS ASCIIZ PTR   ' LPCSTR // routing information
   SenderName    AS ASCIIZ PTR   ' LPCSTR // sender name
   RecipientName AS ASCIIZ PTR   ' LPCSTR // recipient name
   Size          AS DWORD        ' DWORD // size in bytes of the document
   StartTime     AS FILETIME     ' FILETIME // starting time of the fax send/receive
   Status        AS DWORD        ' DWORD // current status of the device, see FPS_??? masks
   StatusString  AS ASCIIZ PTR   ' LPCSTR // status string if the Status field is zero.  this may be NULL.
   SubmittedTime AS FILETIME     ' FILETIME // time the document was submitted
   TotalPages    AS DWORD        ' DWORD // total number of pages in this job
   Tsid          AS ASCIIZ PTR   ' LPCSTR // transmitting station identifier
   UserName      AS ASCIIZ PTR   ' LPCSTR // user that submitted the active job
END TYPE

' // Size = 88 bytes
TYPE FAX_DEVICE_STATUSW DWORD
   SizeOfStruct  AS DWORD          ' DWORD // size of this structure
   CallerId      AS WSTRINGZ PTR   ' LPCWSTR // caller id string
   Csid          AS WSTRINGZ PTR   ' LPCWSTR // station identifier
   CurrentPage   AS DWORD          ' DWORD // current page
   DeviceId      AS DWORD          ' DWORD // permanent line id
   DeviceName    AS WSTRINGZ PTR   ' LPCWSTR // device name
   DocumentName  AS WSTRINGZ PTR   ' LPCWSTR // document name
   JobType       AS DWORD          ' DWORD // send or receive?
   PhoneNumber   AS WSTRINGZ PTR   ' LPCWSTR // sending phone number
   RoutingString AS WSTRINGZ PTR   ' LPCWSTR // routing information
   SenderName    AS WSTRINGZ PTR   ' LPCWSTR // sender name
   RecipientName AS WSTRINGZ PTR   ' LPCWSTR // recipient name
   Size          AS DWORD          ' DWORD // size in bytes of the document
   StartTime     AS FILETIME       ' FILETIME // starting time of the fax send/receive
   Status        AS DWORD          ' DWORD // current status of the device, see FPS_??? masks
   StatusString  AS WSTRINGZ PTR   ' LPCWSTR // status string if the Status field is zero.  this may be NULL.
   SubmittedTime AS FILETIME       ' FILETIME // time the document was submitted
   TotalPages    AS DWORD          ' DWORD // total number of pages in this job
   Tsid          AS WSTRINGZ PTR   ' LPCWSTR // transmitting station identifier
   UserName      AS WSTRINGZ PTR   ' LPCWSTR // user that submitted the active job
END TYPE

#IF %DEF(%UNICODE)
   MACRO FAX_DEVICE_STATUS = FAX_DEVICE_STATUSW
#ELSE
   MACRO FAX_DEVICE_STATUS = FAX_DEVICE_STATUSA
#ENDIF

' // Size = 92 bytes
TYPE FAX_JOB_ENTRYA DWORD
   SizeOfStruct          AS DWORD        ' DWORD // size of this structure
   JobId                 AS DWORD        ' DWORD // fax job id
   UserName              AS ASCIIZ PTR   ' LPCSTR // user who submitted the job
   JobType               AS DWORD        ' DWORD // job type, see JT defines
   QueueStatus           AS DWORD        ' DWORD // job queue status, see JS defines
   Status                AS DWORD        ' DWORD // current status of the device, see FPS_??? masks
   Size                  AS DWORD        ' DWORD // size in bytes of the document
   PageCount             AS DWORD        ' DWORD // total page count
   RecipientNumber       AS ASCIIZ PTR   ' LPCSTR // recipient fax number
   RecipientName         AS ASCIIZ PTR   ' LPCSTR // recipient name
   Tsid                  AS ASCIIZ PTR   ' LPCSTR // transmitter's id
   SenderName            AS ASCIIZ PTR   ' LPCSTR // sender name
   SenderCompany         AS ASCIIZ PTR   ' LPCSTR // sender company
   SenderDept            AS ASCIIZ PTR   ' LPCSTR // sender department
   BillingCode           AS ASCIIZ PTR   ' LPCSTR // billing code
   ScheduleAction        AS DWORD        ' DWORD // when to schedule the fax, see JSA defines
   ScheduleTime          AS SYSTEMTIME   ' SYSTEMTIME // time to send the fax when JSA_SPECIFIC_TIME is used (must be local time)
   DeliveryReportType    AS DWORD        ' DWORD // delivery report type, see DRT defines
   DeliveryReportAddress AS ASCIIZ PTR   ' LPCSTR // email address for delivery report (ndr or dr) thru MAPI / SMTP
   DocumentName          AS ASCIIZ PTR   ' LPCSTR // document name
END TYPE

' // Size = 92 bytes
TYPE FAX_JOB_ENTRYW DWORD
   SizeOfStruct          AS DWORD          ' DWORD // size of this structure
   JobId                 AS DWORD          ' DWORD // fax job id
   UserName              AS WSTRINGZ PTR   ' LPCWSTR // user who submitted the job
   JobType               AS DWORD          ' DWORD // job type, see JT defines
   QueueStatus           AS DWORD          ' DWORD // job queue status, see JS defines
   Status                AS DWORD          ' DWORD // current status of the device, see FPS_??? masks
   Size                  AS DWORD          ' DWORD // size in bytes of the document
   PageCount             AS DWORD          ' DWORD // total page count
   RecipientNumber       AS WSTRINGZ PTR   ' LPCWSTR // recipient fax number
   RecipientName         AS WSTRINGZ PTR   ' LPCWSTR // recipient name
   Tsid                  AS WSTRINGZ PTR   ' LPCWSTR // transmitter's id
   SenderName            AS WSTRINGZ PTR   ' LPCWSTR // sender name
   SenderCompany         AS WSTRINGZ PTR   ' LPCWSTR // sender company
   SenderDept            AS WSTRINGZ PTR   ' LPCWSTR // sender department
   BillingCode           AS WSTRINGZ PTR   ' LPCWSTR // billing code
   ScheduleAction        AS DWORD          ' DWORD // when to schedule the fax, see JSA defines
   ScheduleTime          AS SYSTEMTIME     ' SYSTEMTIME // time to send the fax when JSA_SPECIFIC_TIME is used (must be local time)
   DeliveryReportType    AS DWORD          ' DWORD // delivery report type, see DRT defines
   DeliveryReportAddress AS WSTRINGZ PTR   ' LPCWSTR // email address for delivery report (ndr or dr) thru MAPI / SMTP
   DocumentName          AS WSTRINGZ PTR   ' LPCWSTR // document name
END TYPE

#IF %DEF(%UNICODE)
   MACRO FAX_JOB_ENTRY = FAX_JOB_ENTRYW
#ELSE
   MACRO FAX_JOB_ENTRY = FAX_JOB_ENTRYA
#ENDIF

'//
'// fax port state masks
'//
'// if you change these defines the be sure to
'// change the resources in the fax service.
'//

%FPS_DIALING              = &H20000001???
%FPS_SENDING              = &H20000002???
%FPS_RECEIVING            = &H20000004???
%FPS_COMPLETED            = &H20000008???
%FPS_HANDLED              = &H20000010???
%FPS_UNAVAILABLE          = &H20000020???
%FPS_BUSY                 = &H20000040???
%FPS_NO_ANSWER            = &H20000080???
%FPS_BAD_ADDRESS          = &H20000100???
%FPS_NO_DIAL_TONE         = &H20000200???
%FPS_DISCONNECTED         = &H20000400???
%FPS_FATAL_ERROR          = &H20000800???
%FPS_NOT_FAX_CALL         = &H20001000???
%FPS_CALL_DELAYED         = &H20002000???
%FPS_CALL_BLACKLISTED     = &H20004000???
%FPS_INITIALIZING         = &H20008000???
%FPS_OFFLINE              = &H20010000???
%FPS_RINGING              = &H20020000???

%FPS_AVAILABLE            = &H20100000???
%FPS_ABORTING             = &H20200000???
%FPS_ROUTING              = &H20400000???
%FPS_ANSWERED             = &H20800000???

'//
'// fax port capability mask
'//

%FPF_RECEIVE       = &H00000001???   ' // Automatically receive faxes
%FPF_SEND          = &H00000002???
%FPF_VIRTUAL       = &H00000004???

' // Size = 36 bytes
TYPE FAX_PORT_INFOA DWORD
   SizeOfStruct AS DWORD        ' DWORD // size of this structure
   DeviceId     AS DWORD        ' DWORD // Device ID
   State        AS DWORD        ' DWORD // State of the device
   Flags        AS DWORD        ' DWORD // Device specific flags
   Rings        AS DWORD        ' DWORD // Number of rings before answer
   Priority     AS DWORD        ' DWORD // Device priority
   DeviceName   AS ASCIIZ PTR   ' LPCSTR // Device name
   Tsid         AS ASCIIZ PTR   ' LPCSTR // Device Tsid
   Csid         AS ASCIIZ PTR   ' LPCSTR // Device Csid
END TYPE

' // Size = 36 bytes
TYPE FAX_PORT_INFOW
   SizeOfStruct AS DWORD          ' DWORD // size of this structure
   DeviceId     AS DWORD          ' DWORD // Device ID
   State        AS DWORD          ' DWORD // State of the device
   Flags        AS DWORD          ' DWORD // Device specific flags
   Rings        AS DWORD          ' DWORD // Number of rings before answer
   Priority     AS DWORD          ' DWORD // Device priority
   DeviceName   AS WSTRINGZ PTR   ' LPCWSTR // Device name
   Tsid         AS WSTRINGZ PTR   ' LPCWSTR // Device Tsid
   Csid         AS WSTRINGZ PTR   ' LPCWSTR // Device Csid
END TYPE

#IF %DEF(%UNICODE)
   MACRO FAX_PORT_INFO = FAX_PORT_INFOW
#ELSE
   MACRO FAX_PORT_INFO = FAX_PORT_INFOA
#ENDIF

' // Size = 36 bytes
TYPE FAX_ROUTING_METHODA DWORD
   SizeOfStruct          AS DWORD        ' DWORD // size of this structure
   DeviceId              AS DWORD        ' DWORD // device identifier
   Enabled               AS LONG         ' BOOL // is this method enabled for this device?
   DeviceName            AS ASCIIZ PTR   ' LPCSTR // device name
   Guid                  AS ASCIIZ PTR   ' LPCSTR // guid that identifies this routing method
   FriendlyName          AS ASCIIZ PTR   ' LPCSTR // friendly name for this method
   FunctionName          AS ASCIIZ PTR   ' LPCSTR // exported function name that identifies this method
   ExtensionImageName    AS ASCIIZ PTR   ' LPCSTR // module (dll) name that implements this method
   ExtensionFriendlyName AS ASCIIZ PTR   ' LPCSTR // displayable string that identifies the extension
END TYPE

' // Size = 36 bytes
TYPE FAX_ROUTING_METHODW
   SizeOfStruct          AS DWORD          ' DWORD // size of this structure
   DeviceId              AS DWORD          ' DWORD // device identifier
   Enabled               AS LONG           ' BOOL // is this method enabled for this device?
   DeviceName            AS WSTRINGZ PTR   ' LPCWSTR // device name
   Guid                  AS WSTRINGZ PTR   ' LPCWSTR // guid that identifies this routing method
   FriendlyName          AS WSTRINGZ PTR   ' LPCWSTR // friendly name for this method
   FunctionName          AS WSTRINGZ PTR   ' LPCWSTR // exported function name that identifies this method
   ExtensionImageName    AS WSTRINGZ PTR   ' LPCWSTR // module (dll) name that implements this method
   ExtensionFriendlyName AS WSTRINGZ PTR   ' LPCWSTR // displayable string that identifies the extension
END TYPE

#IF %DEF(%UNICODE)
   MACRO FAX_ROUTING_METHOD = FAX_ROUTING_METHODW
#ELSE
   MACRO FAX_ROUTING_METHOD = FAX_ROUTING_METHODA
#ENDIF

' // Size = 28 bytes
TYPE FAX_GLOBAL_ROUTING_INFOA DWORD
   SizeOfStruct          AS DWORD        ' DWORD // size of this structure
   Priority              AS DWORD        ' DWORD // priority of this device
   Guid                  AS ASCIIZ PTR   ' LPCSTR // guid that identifies this routing method
   FriendlyName          AS ASCIIZ PTR   ' LPCSTR // friendly name for this method
   FunctionName          AS ASCIIZ PTR   ' LPCSTR // exported function name that identifies this method
   ExtensionImageName    AS ASCIIZ PTR   ' LPCSTR // module (dll) name that implements this method
   ExtensionFriendlyName AS ASCIIZ PTR   ' LPCSTR // displayable string that identifies the extension
END TYPE

' // Size = 28 bytes
TYPE FAX_GLOBAL_ROUTING_INFOW DWORD
   SizeOfStruct          AS DWORD          ' DWORD // size of this structure
   Priority              AS DWORD          ' DWORD // priority of this device
   Guid                  AS WSTRINGZ PTR   ' LPCWSTR // guid that identifies this routing method
   FriendlyName          AS WSTRINGZ PTR   ' LPCWSTR // friendly name for this method
   FunctionName          AS WSTRINGZ PTR   ' LPCWSTR // exported function name that identifies this method
   ExtensionImageName    AS WSTRINGZ PTR   ' LPCWSTR // module (dll) name that implements this method
   ExtensionFriendlyName AS WSTRINGZ PTR   ' LPCWSTR // displayable string that identifies the extension
END TYPE

#IF %DEF(%UNICODE)
   MACRO FAX_GLOBAL_ROUTING_INFO = FAX_GLOBAL_ROUTING_INFOW
#ELSE
   MACRO FAX_GLOBAL_ROUTING_INFO = FAX_GLOBAL_ROUTING_INFOA
#ENDIF

' // Size = 128 bytes
TYPE FAX_COVERPAGE_INFOA DWORD
   SizeOfStruct       AS DWORD        ' DWORD // Size of this structure
   CoverPageName      AS ASCIIZ PTR   ' LPCSTR // coverpage document name
   UseServerCoverPage AS LONG         ' BOOL // coverpage exists on the fax server
   RecName            AS ASCIIZ PTR   ' LPCSTR
   RecFaxNumber       AS ASCIIZ PTR   ' LPCSTR
   RecCompany         AS ASCIIZ PTR   ' LPCSTR
   RecStreetAddress   AS ASCIIZ PTR   ' LPCSTR
   RecCity            AS ASCIIZ PTR   ' LPCSTR
   RecState           AS ASCIIZ PTR   ' LPCSTR
   RecZip             AS ASCIIZ PTR   ' LPCSTR
   RecCountry         AS ASCIIZ PTR   ' LPCSTR
   RecTitle           AS ASCIIZ PTR   ' LPCSTR
   RecDepartment      AS ASCIIZ PTR   ' LPCSTR
   RecOfficeLocation  AS ASCIIZ PTR   ' LPCSTR
   RecHomePhone       AS ASCIIZ PTR   ' LPCSTR
   RecOfficePhone     AS ASCIIZ PTR   ' LPCSTR
   SdrName            AS ASCIIZ PTR   ' LPCSTR
   SdrFaxNumber       AS ASCIIZ PTR   ' LPCSTR
   SdrCompany         AS ASCIIZ PTR   ' LPCSTR
   SdrAddress         AS ASCIIZ PTR   ' LPCSTR
   SdrTitle           AS ASCIIZ PTR   ' LPCSTR
   SdrDepartment      AS ASCIIZ PTR   ' LPCSTR
   SdrOfficeLocation  AS ASCIIZ PTR   ' LPCSTR
   SdrHomePhone       AS ASCIIZ PTR   ' LPCSTR
   SdrOfficePhone     AS ASCIIZ PTR   ' LPCSTR
   Note               AS ASCIIZ PTR   ' LPCSTR
   Subject            AS ASCIIZ PTR   ' LPCSTR
   TimeSent           AS SYSTEMTIME   ' SYSTEMTIME // Time the fax was sent
   PageCount          AS DWORD        ' DWORD // Number of pages
END TYPE

' // Size = 128 bytes
TYPE FAX_COVERPAGE_INFOW DWORD
   SizeOfStruct       AS DWORD          ' DWORD // Size of this structure
   CoverPageName      AS WSTRINGZ PTR   ' LPCWSTR // coverpage document name
   UseServerCoverPage AS LONG           ' BOOL // coverpage exists on the fax server
   RecName            AS WSTRINGZ PTR   ' LPCWSTR
   RecFaxNumber       AS WSTRINGZ PTR   ' LPCWSTR
   RecCompany         AS WSTRINGZ PTR   ' LPCWSTR
   RecStreetAddress   AS WSTRINGZ PTR   ' LPCWSTR
   RecCity            AS WSTRINGZ PTR   ' LPCWSTR
   RecState           AS WSTRINGZ PTR   ' LPCWSTR
   RecZip             AS WSTRINGZ PTR   ' LPCWSTR
   RecCountry         AS WSTRINGZ PTR   ' LPCWSTR
   RecTitle           AS WSTRINGZ PTR   ' LPCWSTR
   RecDepartment      AS WSTRINGZ PTR   ' LPCWSTR
   RecOfficeLocation  AS WSTRINGZ PTR   ' LPCWSTR
   RecHomePhone       AS WSTRINGZ PTR   ' LPCWSTR
   RecOfficePhone     AS WSTRINGZ PTR   ' LPCWSTR
   SdrName            AS WSTRINGZ PTR   ' LPCWSTR
   SdrFaxNumber       AS WSTRINGZ PTR   ' LPCWSTR
   SdrCompany         AS WSTRINGZ PTR   ' LPCWSTR
   SdrAddress         AS WSTRINGZ PTR   ' LPCWSTR
   SdrTitle           AS WSTRINGZ PTR   ' LPCWSTR
   SdrDepartment      AS WSTRINGZ PTR   ' LPCWSTR
   SdrOfficeLocation  AS WSTRINGZ PTR   ' LPCWSTR
   SdrHomePhone       AS WSTRINGZ PTR   ' LPCWSTR
   SdrOfficePhone     AS WSTRINGZ PTR   ' LPCWSTR
   Note               AS WSTRINGZ PTR   ' LPCWSTR
   Subject            AS WSTRINGZ PTR   ' LPCWSTR
   TimeSent           AS SYSTEMTIME     ' SYSTEMTIME // Time the fax was sent
   PageCount          AS DWORD          ' DWORD // Number of pages
END TYPE

#IF %DEF(%UNICODE)
   MACRO FAX_COVERPAGE_INFO = FAX_COVERPAGE_INFOW
#ELSE
   MACRO FAX_COVERPAGE_INFO = FAX_COVERPAGE_INFOA
#ENDIF

' enum FAX_ENUM_JOB_SEND_ATTRIBUTES
%JSA_NOW             = 0   ' // Send now
%JSA_SPECIFIC_TIME   = 1   ' // Send at specific time
%JSA_DISCOUNT_PERIOD = 2   ' // Send at server configured discount period


'#ifndef _FAXAPIP_

' enum FAX_ENUM_DELIVERY_REPORT_TYPES
%DRT_NONE                = &H0000???      ' // Do not send receipt
%DRT_EMAIL               = &H0001???      ' // Send receipt by email
%DRT_INBOX               = &H0002???      ' // send receipt to local inbox

'#endif // _FAXAPIP_

' // Size = 80 bytes
TYPE FAX_JOB_PARAMA DWORD
   SizeOfStruct          AS DWORD        ' DWORD // size of this structure
   RecipientNumber       AS ASCIIZ PTR   ' LPCSTR // recipient fax number
   RecipientName         AS ASCIIZ PTR   ' LPCSTR // recipient name
   Tsid                  AS ASCIIZ PTR   ' LPCSTR // transmitter's id
   SenderName            AS ASCIIZ PTR   ' LPCSTR // sender name
   SenderCompany         AS ASCIIZ PTR   ' LPCSTR // sender company
   SenderDept            AS ASCIIZ PTR   ' LPCSTR // sender department
   BillingCode           AS ASCIIZ PTR   ' LPCSTR // billing code
   ScheduleAction        AS DWORD        ' DWORD // when to schedule the fax, see JSA defines
   ScheduleTime          AS SYSTEMTIME   ' SYSTEMTIME // time to send the fax when JSA_SPECIFIC_TIME is used (must be local time)
   DeliveryReportType    AS DWORD        ' DWORD // delivery report type, see DRT defines
   DeliveryReportAddress AS ASCIIZ PTR   ' LPCSTR // email address for delivery report (ndr or dr) thru MAPI / SMTP
   DocumentName          AS ASCIIZ PTR   ' LPCSTR // document name (optional)
   CallHandle            AS DWORD        ' HCALL // optional call handle
   Reserved(2)           AS DWORD PTR    ' DWORD_PTR // reserved for ms use only
END TYPE

' // Size = 80 bytes
TYPE FAX_JOB_PARAMW DWORD
   SizeOfStruct          AS DWORD          ' DWORD // size of this structure
   RecipientNumber       AS WSTRINGZ PTR   ' LPCWSTR // recipient fax number
   RecipientName         AS WSTRINGZ PTR   ' LPCWSTR // recipient name
   Tsid                  AS WSTRINGZ PTR   ' LPCWSTR // transmitter's id
   SenderName            AS WSTRINGZ PTR   ' LPCWSTR // sender name
   SenderCompany         AS WSTRINGZ PTR   ' LPCWSTR // sender company
   SenderDept            AS WSTRINGZ PTR   ' LPCWSTR // sender department
   BillingCode           AS WSTRINGZ PTR   ' LPCWSTR // billing code
   ScheduleAction        AS DWORD          ' DWORD // when to schedule the fax, see JSA defines
   ScheduleTime          AS SYSTEMTIME     ' SYSTEMTIME // time to send the fax when JSA_SPECIFIC_TIME is used (must be local time)
   DeliveryReportType    AS DWORD          ' DWORD // delivery report type, see DRT defines
   DeliveryReportAddress AS WSTRINGZ PTR   ' LPCWSTR // email address for delivery report (ndr or dr) thru MAPI / SMTP
   DocumentName          AS WSTRINGZ PTR   ' LPCWSTR // document name (optional)
   CallHandle            AS DWORD          ' HCALL // optional call handle
   Reserved(2)           AS DWORD PTR      ' DWORD_PTR // reserved for ms use only
END TYPE

#IF %DEF(%UNICODE)
   MACRO FAX_JOB_PARAM = FAX_JOB_PARAMW
#ELSE
   MACRO FAX_JOB_PARAM = FAX_JOB_PARAMA
#ENDIF

'//
'// Event Ids
'//
'// FEI_NEVENTS is the number of events
'//

%FEI_DIALING                 = &H00000001???
%FEI_SENDING                 = &H00000002???
%FEI_RECEIVING               = &H00000003???
%FEI_COMPLETED               = &H00000004???
%FEI_BUSY                    = &H00000005???
%FEI_NO_ANSWER               = &H00000006???
%FEI_BAD_ADDRESS             = &H00000007???
%FEI_NO_DIAL_TONE            = &H00000008???
%FEI_DISCONNECTED            = &H00000009???
%FEI_FATAL_ERROR             = &H0000000a???
%FEI_NOT_FAX_CALL            = &H0000000b???
%FEI_CALL_DELAYED            = &H0000000c???
%FEI_CALL_BLACKLISTED        = &H0000000d???
%FEI_RINGING                 = &H0000000e???
%FEI_ABORTING                = &H0000000f???
%FEI_ROUTING                 = &H00000010???
%FEI_MODEM_POWERED_ON        = &H00000011???
%FEI_MODEM_POWERED_OFF       = &H00000012???
%FEI_IDLE                    = &H00000013???
%FEI_FAXSVC_ENDED            = &H00000014???
%FEI_ANSWERED                = &H00000015???
%FEI_JOB_QUEUED              = &H00000016???
%FEI_DELETED                 = &H00000017???
%FEI_INITIALIZING            = &H00000018???
%FEI_LINE_UNAVAILABLE        = &H00000019???
%FEI_HANDLED                 = &H0000001a???
%FEI_FAXSVC_STARTED          = &H0000001b???

%FEI_NEVENTS                 = %FEI_FAXSVC_STARTED

' // Size = 24 bytes
TYPE FAX_EVENTA DWORD
   SizeOfStruct AS DWORD      ' DWORD // Size of this structure
   TimeStamp    AS FILETIME   ' FILETIME // Timestamp for when the event was generated
   DeviceId     AS DWORD      ' DWORD // Permanent line id
   EventId      AS DWORD      ' DWORD // Current event id
   JobId        AS DWORD      ' DWORD // Fax Job Id, 0xffffffff indicates inactive job
END TYPE

' // Size = 24 bytes
TYPE FAX_EVENTW DWORD
   SizeOfStruct AS DWORD      ' DWORD // Size of this structure
   TimeStamp    AS FILETIME   ' FILETIME // Timestamp for when the event was generated
   DeviceId     AS DWORD      ' DWORD // Permanent line id
   EventId      AS DWORD      ' DWORD // Current event id
   JobId        AS DWORD      ' DWORD // Fax Job Id, 0xffffffff indicates inactive job
END TYPE

#IF %DEF(%UNICODE)
   MACRO FAX_EVENT = FAX_EVENTW
#ELSE
   MACRO FAX_EVENT = FAX_EVENTA
#ENDIF

' // Size = 44 bytes
TYPE FAX_PRINT_INFOA DWORD
   SizeOfStruct      AS DWORD        ' DWORD // Size of this structure
   DocName           AS ASCIIZ PTR   ' LPCSTR // Document name that appears in the spooler
   RecipientName     AS ASCIIZ PTR   ' LPCSTR // Recipient name
   RecipientNumber   AS ASCIIZ PTR   ' LPCSTR // Recipient fax number (non-canonical number)
   SenderName        AS ASCIIZ PTR   ' LPCSTR // Sender name
   SenderCompany     AS ASCIIZ PTR   ' LPCSTR // Sender company (optional)
   SenderDept        AS ASCIIZ PTR   ' LPCSTR // Sender department
   SenderBillingCode AS ASCIIZ PTR   ' LPCSTR // Billing code
   Reserved          AS ASCIIZ PTR   ' LPCSTR // Reserved; must be NULL
   DrEmailAddress    AS ASCIIZ PTR   ' LPCSTR // E.Mail address for delivery report
   OutputFileName    AS ASCIIZ PTR   ' LPCSTR // for print to file, resulting file name
END TYPE

' // Size = 44 bytes
TYPE FAX_PRINT_INFOW DWORD
   SizeOfStruct      AS DWORD          ' DWORD // Size of this structure
   DocName           AS WSTRINGZ PTR   ' LPWCSTR // Document name that appears in the spooler
   RecipientName     AS WSTRINGZ PTR   ' LPWCSTR // Recipient name
   RecipientNumber   AS WSTRINGZ PTR   ' LPWCSTR // Recipient fax number (non-canonical number)
   SenderName        AS WSTRINGZ PTR   ' LPWCSTR // Sender name
   SenderCompany     AS WSTRINGZ PTR   ' LPWCSTR // Sender company (optional)
   SenderDept        AS WSTRINGZ PTR   ' LPWCSTR // Sender department
   SenderBillingCode AS WSTRINGZ PTR   ' LPWCSTR // Billing code
   Reserved          AS WSTRINGZ PTR   ' LPWCSTR // Reserved; must be NULL
   DrEmailAddress    AS WSTRINGZ PTR   ' LPWCSTR // E.Mail address for delivery report
   OutputFileName    AS WSTRINGZ PTR   ' LPWCSTR // for print to file, resulting file name
END TYPE

#IF %DEF(%UNICODE)
   MACRO FAX_PRINT_INFO = FAX_PRINT_INFOW
#ELSE
   MACRO FAX_PRINT_INFO = FAX_PRINT_INFOA
#ENDIF

' // Size = 24 bytes
TYPE FAX_CONTEXT_INFOA DWORD
   SizeOfStruct AS DWORD   ' DWORD // Size of this structure
   hDC          AS DWORD   ' HDC // Device Context
   ServerName   AS ASCIIZ * %MAX_COMPUTERNAME_LENGTH + 1   ' CHAR // Server name
END TYPE

' // Size = 40 bytes
TYPE FAX_CONTEXT_INFOW DWORD
   SizeOfStruct AS DWORD   ' DWORD // Size of this structure
   hDC          AS DWORD   ' HDC // Device Context
   ServerName   AS WSTRINGZ * %MAX_COMPUTERNAME_LENGTH + 1   ' WCHAR // Server name
END TYPE

#IF %DEF(%UNICODE)
   MACRO FAX_CONTEXT_INFO = FAX_CONTEXT_INFOW
#ELSE
   MACRO FAX_CONTEXT_INFO = FAX_CONTEXT_INFOA
#ENDIF

'//
'// prototypes
'//

DECLARE FUNCTION FaxConnectFaxServerA IMPORT "winfax.dll" ALIAS "FaxConnectFaxServerA" ( _
   BYREF MachineName AS ASCIIZ _                        ' __in  LPCSTR MachineName OPTIONAL
 , BYREF FaxHandle AS DWORD _                           ' __out LPHANDLE FaxHandle
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxConnectFaxServerW IMPORT "winfax.dll" ALIAS "FaxConnectFaxServerW" ( _
   BYREF MachineName AS WSTRINGZ _                      ' __in  LPCWSTR MachineName OPTIONAL
 , BYREF FaxHandle AS DWORD _                           ' __out LPHANDLE FaxHandle
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FaxConnectFaxServer = FaxConnectFaxServerW
#ELSE
   MACRO FaxConnectFaxServer = FaxConnectFaxServerA
#ENDIF

DECLARE FUNCTION FaxClose IMPORT "winfax.dll" ALIAS "FaxClose" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in HANDLE FaxHandle
 ) AS LONG                                              ' BOOL


' enum FAX_ENUM_PORT_OPEN_TYPE
%PORT_OPEN_QUERY  = 1
%PORT_OPEN_MODIFY = 2

DECLARE FUNCTION FaxOpenPort IMPORT "winfax.dll" ALIAS "FaxOpenPort" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYVAL DeviceId AS DWORD _                            ' __in  DWORD DeviceId
 , BYVAL Flags AS DWORD _                               ' __in  DWORD Flags
 , BYREF FaxPortHandle AS DWORD _                       ' __out LPHANDLE FaxPortHandle
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxCompleteJobParamsA IMPORT "winfax.dll" ALIAS "FaxCompleteJobParamsA" ( _
   BYREF JobParams AS FAX_JOB_PARAMA _                  ' __in_out PFAX_JOB_PARAMA *JobParams
 , BYREF CoverpageInfo AS FAX_COVERPAGE_INFOA _         ' __in_out PFAX_COVERPAGE_INFOA *CoverpageInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxCompleteJobParamsW IMPORT "winfax.dll" ALIAS "FaxCompleteJobParamsW" ( _
   BYREF JobParams AS FAX_JOB_PARAMW _                  ' __in_out PFAX_JOB_PARAMA *JobParams
 , BYREF CoverpageInfo AS FAX_COVERPAGE_INFOW _         ' __in_out PFAX_COVERPAGE_INFOA *CoverpageInfo
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FaxCompleteJobParams = FaxCompleteJobParamsW
#ELSE
   MACRO FaxCompleteJobParams = FaxCompleteJobParamsA
#ENDIF

DECLARE FUNCTION FaxSendDocumentA IMPORT "winfax.dll" ALIAS "FaxSendDocumentA" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYREF FileName AS ASCIIZ _                           ' __in  LPCSTR FileName
 , BYREF JobParams AS FAX_JOB_PARAMA _                  ' __in  PFAX_JOB_PARAMA JobParams
 , BYREF CoverpageInfo AS FAX_COVERPAGE_INFOA _         ' __in  const FAX_COVERPAGE_INFOA *CoverpageInfo OPTIONAL
 , BYREF FaxJobId AS DWORD _                            ' __out LPDWORD FaxJobId OPTIONAL
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxSendDocumentW IMPORT "winfax.dll" ALIAS "FaxSendDocumentW" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYREF FileName AS WSTRINGZ _                         ' __in  LPCWSTR FileName
 , BYREF JobParams AS FAX_JOB_PARAMW _                  ' __in  PFAX_JOB_PARAMW JobParams
 , BYREF CoverpageInfo AS FAX_COVERPAGE_INFOW _         ' __in  const FAX_COVERPAGE_INFOW *CoverpageInfo OPTIONAL
 , BYREF FaxJobId AS DWORD _                            ' __out LPDWORD FaxJobId OPTIONAL
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FaxSendDocument = FaxSendDocumentW
#ELSE
   MACRO FaxSendDocument = FaxSendDocumentA
#ENDIF

'typedef BOOL
'(CALLBACK *PFAX_RECIPIENT_CALLBACKA)(
'    __in HANDLE FaxHandle,
'    __in DWORD RecipientNumber,
'    __in LPVOID Context,
'    __in_out PFAX_JOB_PARAMA JobParams,
'    __in_out PFAX_COVERPAGE_INFOA CoverpageInfo OPTIONAL
'    );

'FUNCTION FAX_RECIPIENT_CALLBACKA ( _
'   BYVAL FaxHandle AS DWORD _                           ' __in HANDLE FaxHandle
' , BYVAL RecipientNumber AS DWORD _                     ' __in DWORD RecipientNumber
' , BYVAL Context AS DWORD _                             ' __in LPVOID Context
' , BYREF JobParams AS FAX_JOB_PARAMA _                  ' __in_out PFAX_JOB_PARAMA JobParams
' , BYREF CoverpageInfo AS FAX_COVERPAGE_INFOA _         ' __in_out PFAX_COVERPAGE_INFOA CoverpageInfo OPTIONAL
' ) AS LONG                                              ' BOOL

'typedef BOOL
'(CALLBACK *PFAX_RECIPIENT_CALLBACKW)(
'    __in HANDLE FaxHandle,
'    __in DWORD RecipientNumber,
'    __in LPVOID Context,
'    __in_out PFAX_JOB_PARAMW JobParams,
'    __in_out PFAX_COVERPAGE_INFOW CoverpageInfo OPTIONAL
'    );

'FUNCTION FAX_RECIPIENT_CALLBACKW ( _
'   BYVAL FaxHandle AS DWORD _                           ' __in HANDLE FaxHandle
' , BYVAL RecipientNumber AS DWORD _                     ' __in DWORD RecipientNumber
' , BYVAL Context AS DWORD _                             ' __in LPVOID Context
' , BYREF JobParams AS FAX_JOB_PARAMW _                  ' __in_out PFAX_JOB_PARAMW JobParams
' , BYREF CoverpageInfo AS FAX_COVERPAGE_INFOW _         ' __in_out PFAX_COVERPAGE_INFOW CoverpageInfo OPTIONAL
' ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxSendDocumentForBroadcastA IMPORT "winfax.dll" ALIAS "FaxSendDocumentForBroadcastA" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYREF FileName AS ASCIIZ _                           ' __in  LPCSTR FileName
 , BYREF FaxJobId AS DWORD _                            ' __out LPDWORD FaxJobId
 , BYVAL FaxRecipientCallback AS DWORD _                ' __in  PFAX_RECIPIENT_CALLBACKA FaxRecipientCallback
 , BYVAL Context AS DWORD _                             ' __in  LPVOID Context
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxSendDocumentForBroadcastW IMPORT "winfax.dll" ALIAS "FaxSendDocumentForBroadcastW" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYREF FileName AS WSTRINGZ _                         ' __in  LPCWSTR FileName
 , BYREF FaxJobId AS DWORD _                            ' __out LPDWORD FaxJobId
 , BYVAL FaxRecipientCallback AS DWORD _                ' __in  PFAX_RECIPIENT_CALLBACKA FaxRecipientCallback
 , BYVAL Context AS DWORD _                             ' __in  LPVOID Context
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FaxSendDocumentForBroadcast = FaxSendDocumentForBroadcastW
#ELSE
   MACRO FaxSendDocumentForBroadcast = FaxSendDocumentForBroadcastA
#ENDIF

DECLARE FUNCTION FaxEnumJobsA IMPORT "winfax.dll" ALIAS "FaxEnumJobsA" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYREF JobEntry AS FAX_JOB_ENTRYA _                   ' __out PFAX_JOB_ENTRYA *JobEntry
 , BYREF JobsReturned AS DWORD _                        ' __out LPDWORD JobsReturned
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxEnumJobsW IMPORT "winfax.dll" ALIAS "FaxEnumJobsW" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYREF JobEntry AS FAX_JOB_ENTRYW _                   ' __out PFAX_JOB_ENTRYW *JobEntry
 , BYREF JobsReturned AS DWORD _                        ' __out LPDWORD JobsReturned
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FaxEnumJobs = FaxEnumJobsW
#ELSE
   MACRO FaxEnumJobs = FaxEnumJobsA
#ENDIF

DECLARE FUNCTION FaxGetJobA IMPORT "winfax.dll" ALIAS "FaxGetJobA" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYVAL JobId AS DWORD _                               ' __in  DWORD JobId
 , BYREF JobEntry AS FAX_JOB_ENTRYA _                   ' __out PFAX_JOB_ENTRYA *JobEntry
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxGetJobW IMPORT "winfax.dll" ALIAS "FaxGetJobW" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYVAL JobId AS DWORD _                               ' __in  DWORD JobId
 , BYREF JobEntry AS FAX_JOB_ENTRYW _                   ' __out PFAX_JOB_ENTRYW *JobEntry
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FaxGetJob = FaxGetJobW
#ELSE
   MACRO FaxGetJob = FaxGetJobA
#ENDIF

DECLARE FUNCTION FaxSetJobA IMPORT "winfax.dll" ALIAS "FaxSetJobA" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in HANDLE FaxHandle
 , BYVAL JobId AS DWORD _                               ' __in DWORD JobId
 , BYVAL Command AS DWORD _                             ' __in DWORD Command
 , BYREF JobEntry AS FAX_JOB_ENTRYA _                   ' __in const FAX_JOB_ENTRYA *JobEntry
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxSetJobW IMPORT "winfax.dll" ALIAS "FaxSetJobW" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in HANDLE FaxHandle
 , BYVAL JobId AS DWORD _                               ' __in DWORD JobId
 , BYVAL Command AS DWORD _                             ' __in DWORD Command
 , BYREF JobEntry AS FAX_JOB_ENTRYW _                   ' __in const FAX_JOB_ENTRYW *JobEntry
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FaxSetJob = FaxSetJobW
#ELSE
   MACRO FaxSetJob = FaxSetJobA
#ENDIF

DECLARE FUNCTION FaxGetPageData IMPORT "winfax.dll" ALIAS "FaxGetPageData" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYVAL JobId AS DWORD _                               ' __in  DWORD JobId
 , BYREF Buffer AS DWORD _                              ' __out LPBYTE *Buffer
 , BYREF BufferSize AS DWORD _                          ' __out LPDWORD BufferSize
 , BYREF ImageWidth AS DWORD _                          ' __out LPDWORD ImageWidth
 , BYREF ImageHeight AS DWORD _                         ' __out LPDWORD ImageHeight
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxGetDeviceStatusA IMPORT "winfax.dll" ALIAS "FaxGetDeviceStatusA" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in HANDLE FaxHandle
 , BYREF DeviceStatus AS FAX_DEVICE_STATUSA _           ' __out PFAX_DEVICE_STATUSA *DeviceStatus
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxGetDeviceStatusW IMPORT "winfax.dll" ALIAS "FaxGetDeviceStatusW" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYREF DeviceStatus AS FAX_DEVICE_STATUSW _           ' __out PFAX_DEVICE_STATUSW *DeviceStatus
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FaxGetDeviceStatus = FaxGetDeviceStatusW
#ELSE
   MACRO FaxGetDeviceStatus = FaxGetDeviceStatusA
#ENDIF

DECLARE FUNCTION FaxAbort IMPORT "winfax.dll" ALIAS "FaxAbort" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in HANDLE FaxHandle
 , BYVAL JobId AS DWORD _                               ' __in DWORD JobId
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxGetConfigurationA IMPORT "winfax.dll" ALIAS "FaxGetConfigurationA" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYREF FaxConfig AS FAX_CONFIGURATIONA _              ' __out PFAX_CONFIGURATIONA *FaxConfig
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxGetConfigurationW IMPORT "winfax.dll" ALIAS "FaxGetConfigurationW" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYREF FaxConfig AS FAX_CONFIGURATIONW _              ' __out PFAX_CONFIGURATIONW *FaxConfig
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FaxGetConfiguration = FaxGetConfigurationW
#ELSE
   MACRO FaxGetConfiguration = FaxGetConfigurationA
#ENDIF

DECLARE FUNCTION FaxSetConfigurationA IMPORT "winfax.dll" ALIAS "FaxSetConfigurationA" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in HANDLE FaxHandle
 , BYREF FaxConfig AS FAX_CONFIGURATIONA _              ' __in const FAX_CONFIGURATIONA *FaxConfig
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxSetConfigurationW IMPORT "winfax.dll" ALIAS "FaxSetConfigurationW" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in HANDLE FaxHandle
 , BYREF FaxConfig AS FAX_CONFIGURATIONW _              ' __in const FAX_CONFIGURATIONW *FaxConfig
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FaxSetConfiguration = FaxSetConfigurationW
#ELSE
   MACRO FaxSetConfiguration = FaxSetConfigurationA
#ENDIF

DECLARE FUNCTION FaxGetLoggingCategoriesA IMPORT "winfax.dll" ALIAS "FaxGetLoggingCategoriesA" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYREF Categories AS FAX_LOG_CATEGORYA _              ' __out PFAX_LOG_CATEGORYA *Categories
 , BYREF NumberCategories AS DWORD _                    ' __out LPDWORD NumberCategories
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxGetLoggingCategoriesW IMPORT "winfax.dll" ALIAS "FaxGetLoggingCategoriesW" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYREF Categories AS FAX_LOG_CATEGORYW _              ' __out PFAX_LOG_CATEGORYW *Categories
 , BYREF NumberCategories AS DWORD _                    ' __out LPDWORD NumberCategories
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FaxGetLoggingCategories = FaxGetLoggingCategoriesW
#ELSE
   MACRO FaxGetLoggingCategories = FaxGetLoggingCategoriesA
#ENDIF

DECLARE FUNCTION FaxSetLoggingCategoriesA IMPORT "winfax.dll" ALIAS "FaxSetLoggingCategoriesA" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYREF Categories AS FAX_LOG_CATEGORYA _              ' __in  PFAX_LOG_CATEGORYA *Categories
 , BYREF NumberCategories AS DWORD _                    ' __out LPDWORD NumberCategories
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxSetLoggingCategoriesW IMPORT "winfax.dll" ALIAS "FaxSetLoggingCategoriesW" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYREF Categories AS FAX_LOG_CATEGORYW _              ' __in  PFAX_LOG_CATEGORYW *Categories
 , BYREF NumberCategories AS DWORD _                    ' __out LPDWORD NumberCategories
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FaxSetLoggingCategories = FaxSetLoggingCategoriesW
#ELSE
   MACRO FaxSetLoggingCategories = FaxSetLoggingCategoriesA
#ENDIF

DECLARE FUNCTION FaxEnumPortsA IMPORT "winfax.dll" ALIAS "FaxEnumPortsA" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYREF PortInfo AS FAX_PORT_INFOA _                   ' __out PFAX_PORT_INFOA *PortInfo
 , BYREF PortsReturned AS DWORD _                       ' __out LPDWORD PortsReturned
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxEnumPortsW IMPORT "winfax.dll" ALIAS "FaxEnumPortsW" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYREF PortInfo AS FAX_PORT_INFOW _                   ' __out PFAX_PORT_INFOW *PortInfo
 , BYREF PortsReturned AS DWORD _                       ' __out LPDWORD PortsReturned
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FaxEnumPorts = FaxEnumPortsW
#ELSE
   MACRO FaxEnumPorts = FaxEnumPortsA
#ENDIF

DECLARE FUNCTION FaxGetPortA IMPORT "winfax.dll" ALIAS "FaxGetPortA" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYREF PortInfo AS FAX_PORT_INFOA _                   ' __out PFAX_PORT_INFOA *PortInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxGetPortW IMPORT "winfax.dll" ALIAS "FaxGetPortW" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYREF PortInfo AS FAX_PORT_INFOW _                   ' __out PFAX_PORT_INFOW *PortInfo
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FaxGetPort = FaxGetPortW
#ELSE
   MACRO FaxGetPort = FaxGetPortA
#ENDIF

DECLARE FUNCTION FaxSetPortA IMPORT "winfax.dll" ALIAS "FaxSetPortA" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in HANDLE FaxHandle
 , BYREF PortInfo AS FAX_PORT_INFOA _                   ' __in const PFAX_PORT_INFOA *PortInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxSetPortW IMPORT "winfax.dll" ALIAS "FaxSetPortW" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in HANDLE FaxHandle
 , BYREF PortInfo AS FAX_PORT_INFOW _                   ' __in const PFAX_PORT_INFOW *PortInfo
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FaxSetPort = FaxSetPortW
#ELSE
   MACRO FaxSetPort = FaxSetPortA
#ENDIF

DECLARE FUNCTION FaxEnumRoutingMethodsA IMPORT "winfax.dll" ALIAS "FaxEnumRoutingMethodsA" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYREF RoutingMethod AS FAX_ROUTING_METHODA _         ' __out PFAX_ROUTING_METHODA *RoutingMethod
 , BYREF MethodsReturned AS DWORD _                     ' __out LPDWORD MethodsReturned
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxEnumRoutingMethodsW IMPORT "winfax.dll" ALIAS "FaxEnumRoutingMethodsW" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYREF RoutingMethod AS FAX_ROUTING_METHODW _         ' __out PFAX_ROUTING_METHODW *RoutingMethod
 , BYREF MethodsReturned AS DWORD _                     ' __out LPDWORD MethodsReturned
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FaxEnumRoutingMethods = FaxEnumRoutingMethodsW
#ELSE
   MACRO FaxEnumRoutingMethods = FaxEnumRoutingMethodsA
#ENDIF

DECLARE FUNCTION FaxEnableRoutingMethodA IMPORT "winfax.dll" ALIAS "FaxEnableRoutingMethodA" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in HANDLE FaxHandle
 , BYREF RoutingGuid AS ASCIIZ _                        ' __in LPCSTR RoutingGuid
 , BYVAL Enabled AS LONG _                              ' __in BOOL Enabled
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxEnableRoutingMethodW IMPORT "winfax.dll" ALIAS "FaxEnableRoutingMethodW" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in HANDLE FaxHandle
 , BYREF RoutingGuid AS WSTRINGZ _                      ' __in LPCWSTR RoutingGuid
 , BYVAL Enabled AS LONG _                              ' __in BOOL Enabled
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FaxEnableRoutingMethod = FaxEnableRoutingMethodW
#ELSE
   MACRO FaxEnableRoutingMethod = FaxEnableRoutingMethodA
#ENDIF

DECLARE FUNCTION FaxEnumGlobalRoutingInfoA IMPORT "winfax.dll" ALIAS "FaxEnumGlobalRoutingInfoA" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYREF RoutingInfo AS FAX_GLOBAL_ROUTING_INFOA _      ' __out PFAX_GLOBAL_ROUTING_INFOA *RoutingInfo
 , BYREF MethodsReturned AS DWORD _                     ' __out LPDWORD MethodsReturned
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxEnumGlobalRoutingInfoW IMPORT "winfax.dll" ALIAS "FaxEnumGlobalRoutingInfoW" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYREF RoutingInfo AS FAX_GLOBAL_ROUTING_INFOW _      ' __out PFAX_GLOBAL_ROUTING_INFOW *RoutingInfo
 , BYREF MethodsReturned AS DWORD _                     ' __out LPDWORD MethodsReturned
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FaxEnumGlobalRoutingInfo = FaxEnumGlobalRoutingInfoW
#ELSE
   MACRO FaxEnumGlobalRoutingInfo = FaxEnumGlobalRoutingInfoA
#ENDIF

DECLARE FUNCTION FaxSetGlobalRoutingInfoA IMPORT "winfax.dll" ALIAS "FaxSetGlobalRoutingInfoA" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in HANDLE FaxHandle
 , BYREF RoutingInfo AS FAX_GLOBAL_ROUTING_INFOA _      ' __in const FAX_GLOBAL_ROUTING_INFOA *RoutingInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxSetGlobalRoutingInfoW IMPORT "winfax.dll" ALIAS "FaxSetGlobalRoutingInfoW" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in HANDLE FaxHandle
 , BYREF RoutingInfo AS FAX_GLOBAL_ROUTING_INFOW _      ' __in const FAX_GLOBAL_ROUTING_INFOW *RoutingInfo
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FaxSetGlobalRoutingInfo = FaxSetGlobalRoutingInfoW
#ELSE
   MACRO FaxSetGlobalRoutingInfo = FaxSetGlobalRoutingInfoA
#ENDIF

DECLARE FUNCTION FaxGetRoutingInfoA IMPORT "winfax.dll" ALIAS "FaxGetRoutingInfoA" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYREF RoutingGuid AS ASCIIZ _                        ' __in  LPCSTR RoutingGuid
 , BYREF RoutingInfoBuffer AS DWORD _                   ' __out LPBYTE *RoutingInfoBuffer
 , BYREF RoutingInfoBufferSize AS DWORD _               ' __out LPDWORD RoutingInfoBufferSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxGetRoutingInfoW IMPORT "winfax.dll" ALIAS "FaxGetRoutingInfoW" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYREF RoutingGuid AS WSTRINGZ _                      ' __in  LPCWSTR RoutingGuid
 , BYREF RoutingInfoBuffer AS DWORD _                   ' __out LPBYTE *RoutingInfoBuffer
 , BYREF RoutingInfoBufferSize AS DWORD _               ' __out LPDWORD RoutingInfoBufferSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FaxGetRoutingInfo = FaxGetRoutingInfoW
#ELSE
   MACRO FaxGetRoutingInfo = FaxGetRoutingInfoA
#ENDIF

DECLARE FUNCTION FaxSetRoutingInfoA IMPORT "winfax.dll" ALIAS "FaxSetRoutingInfoA" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYREF RoutingGuid AS ASCIIZ _                        ' __in  LPCSTR RoutingGuid
 , BYVAL RoutingInfoBuffer AS BYTE PTR _                ' __in  const BYTE *RoutingInfoBuffer
 , BYVAL RoutingInfoBufferSize AS DWORD _               ' __in  DWORD RoutingInfoBufferSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxSetRoutingInfoW IMPORT "winfax.dll" ALIAS "FaxSetRoutingInfoW" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYREF RoutingGuid AS WSTRINGZ _                      ' __in  LPCWSTR RoutingGuid
 , BYVAL RoutingInfoBuffer AS BYTE PTR _                ' __in  const BYTE *RoutingInfoBuffer
 , BYVAL RoutingInfoBufferSize AS DWORD _               ' __in  DWORD RoutingInfoBufferSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FaxSetRoutingInfo = FaxSetRoutingInfoW
#ELSE
   MACRO FaxSetRoutingInfo = FaxSetRoutingInfoA
#ENDIF

DECLARE FUNCTION FaxInitializeEventQueue IMPORT "winfax.dll" ALIAS "FaxInitializeEventQueue" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in  HANDLE FaxHandle
 , BYVAL CompletionPort AS DWORD _                      ' __in HANDLE CompletionPort
 , BYVAL CompletionKey AS DWORD _                       ' __in ULONG_PTR CompletionKey
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL MessageStart AS DWORD _                        ' __in UINT MessageStart
 ) AS LONG                                              ' BOOL

DECLARE SUB FaxFreeBuffer IMPORT "winfax.dll" ALIAS "FaxFreeBuffer" ( _
   BYVAL Buffer AS DWORD _                              ' __in LPVOID Buffer
 )                                                      ' void

DECLARE FUNCTION FaxStartPrintJobA IMPORT "winfax.dll" ALIAS "FaxStartPrintJobA" ( _
   BYREF PrinterName AS ASCIIZ _                        ' __in  LPCSTR PrinterName
 , BYREF PrintInfo AS FAX_PRINT_INFOA _                 ' __in  const FAX_PRINT_INFOA *PrintInfo
 , BYREF FaxJobId AS DWORD _                            ' __out LPDWORD FaxJobId
 , BYREF FaxContextInfo AS FAX_CONTEXT_INFOA _          ' __out PFAX_CONTEXT_INFOA FaxContextInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxStartPrintJobW IMPORT "winfax.dll" ALIAS "FaxStartPrintJobW" ( _
   BYREF PrinterName AS ASCIIZ _                        ' __in  LPCSTR PrinterName
 , BYREF PrintInfo AS FAX_PRINT_INFOW _                 ' __in  const FAX_PRINT_INFOW *PrintInfo
 , BYREF FaxJobId AS DWORD _                            ' __out LPDWORD FaxJobId
 , BYREF FaxContextInfo AS FAX_CONTEXT_INFOW _          ' __out PFAX_CONTEXT_INFOW FaxContextInfo
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FaxStartPrintJob = FaxStartPrintJobW
#ELSE
   MACRO FaxStartPrintJob = FaxStartPrintJobA
#ENDIF

DECLARE FUNCTION FaxPrintCoverPageA IMPORT "winfax.dll" ALIAS "FaxPrintCoverPageA" ( _
   BYREF FaxContextInfo AS FAX_CONTEXT_INFOA _          ' __in const FAX_CONTEXT_INFOA *FaxContextInfo
 , BYREF CoverPageInfo AS FAX_COVERPAGE_INFOA _         ' __in const FAX_COVERPAGE_INFOA *CoverPageInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxPrintCoverPageW IMPORT "winfax.dll" ALIAS "FaxPrintCoverPageW" ( _
   BYREF FaxContextInfo AS FAX_CONTEXT_INFOW _          ' __in const FAX_CONTEXT_INFOW *FaxContextInfo
 , BYREF CoverPageInfo AS FAX_COVERPAGE_INFOW _         ' __in const FAX_COVERPAGE_INFOW *CoverPageInfo
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FaxPrintCoverPage = FaxPrintCoverPageW
#ELSE
   MACRO FaxPrintCoverPage = FaxPrintCoverPageA
#ENDIF

DECLARE FUNCTION FaxRegisterServiceProviderW IMPORT "winfax.dll" ALIAS "FaxRegisterServiceProviderW" ( _
   BYREF DeviceProvider AS WSTRINGZ _                   ' __in LPCWSTR DeviceProvider
 , BYREF FriendlyName AS WSTRINGZ _                     ' __in LPCWSTR FriendlyName
 , BYREF ImageName AS WSTRINGZ _                        ' __in LPCWSTR ImageName
 , BYREF TspName AS WSTRINGZ _                          ' __in LPCWSTR TspName
 ) AS LONG                                              ' BOOL

'#define FaxRegisterServiceProvider  FaxRegisterServiceProviderW
MACRO FaxRegisterServiceProvider = FaxRegisterServiceProviderW

DECLARE FUNCTION FaxUnregisterServiceProviderW IMPORT "winfax.dll" ALIAS "FaxUnregisterServiceProviderW" ( _
   BYREF DeviceProvider AS WSTRINGZ _                   ' __in LPCWSTR DeviceProvider
 ) AS LONG                                              ' BOOL

'#define FaxUnregisterServiceProvider  FaxUnregisterServiceProviderW
MACRO FaxUnregisterServiceProvider = FaxUnregisterServiceProviderW

'typedef BOOL
'(CALLBACK *PFAX_ROUTING_INSTALLATION_CALLBACKW)(
'    __in HANDLE FaxHandle,
'    __in LPVOID Context,
'    __in_out LPWSTR MethodName,
'    __in_out LPWSTR FriendlyName,
'    __in_out LPWSTR FunctionName,
'    __in_out LPWSTR Guid
'    );
'#define PFAX_ROUTING_INSTALLATION_CALLBACK PFAX_ROUTING_INSTALLATION_CALLBACKW

'FUNCTION FAX_ROUTING_INSTALLATION_CALLBACKW ( _
'   BYVAL FaxHandle AS DWORD _                           ' __in HANDLE FaxHandle
' , BYVAL Context AS DWORD _                             ' __in LPVOID Context
' , BYREF MethodName AS WSTRINGZ _                       ' __in_out LPWSTR MethodName
' , BYREF FriendlyName AS WSTRINGZ _                     ' __in_out LPWSTR FriendlyName
' , BYREF FunctionName AS WSTRINGZ _                     ' __in_out LPWSTR FunctionName
' , BYREF Guid AS WSTRINGZ _                             ' __in_out LPWSTR Guid
' ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxRegisterRoutingExtensionW IMPORT "winfax.dll" ALIAS "FaxRegisterRoutingExtensionW" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in HANDLE  FaxHandle
 , BYREF ExtensionName AS WSTRINGZ _                    ' __in LPCWSTR ExtensionName
 , BYREF FriendlyName AS WSTRINGZ _                     ' __in LPCWSTR FriendlyName
 , BYREF ImageName AS WSTRINGZ _                        ' __in LPCWSTR ImageName
 , BYVAL CallBack AS DWORD _                            ' __in PFAX_ROUTING_INSTALLATION_CALLBACKW CallBack
 , BYVAL Context AS DWORD _                             ' __in LPVOID Context
 ) AS LONG                                              ' BOOL

'#define FaxRegisterRoutingExtension FaxRegisterRoutingExtensionW
MACRO FaxRegisterRoutingExtension = FaxRegisterRoutingExtensionW

DECLARE FUNCTION FaxUnregisterRoutingExtensionA IMPORT "winfax.dll" ALIAS "FaxUnregisterRoutingExtensionA" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in HANDLE FaxHandle
 , BYREF lpctstrExtensionName AS ASCIIZ _               ' __in LPCSTR lpctstrExtensionName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FaxUnregisterRoutingExtensionW IMPORT "winfax.dll" ALIAS "FaxUnregisterRoutingExtensionW" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in HANDLE  FaxHandle
 , BYREF lpctstrExtensionName AS WSTRINGZ _             ' __in LPCWSTR lpctstrExtensionName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FaxUnregisterRoutingExtension = FaxUnregisterRoutingExtensionW
#ELSE
   MACRO FaxUnregisterRoutingExtension = FaxUnregisterRoutingExtensionA
#ENDIF

DECLARE FUNCTION FaxAccessCheck IMPORT "winfax.dll" ALIAS "FaxAccessCheck" ( _
   BYVAL FaxHandle AS DWORD _                           ' __in HANDLE  FaxHandle
 , BYVAL AccessMask AS DWORD _                          ' __in DWORD  AccessMask
 ) AS LONG                                              ' BOOL

'//
'// Fax Specific Access Rights
'//

%FAX_JOB_SUBMIT          = &H0001???
%FAX_JOB_QUERY           = &H0002???
%FAX_CONFIG_QUERY        = &H0004???
%FAX_CONFIG_SET          = &H0008???
%FAX_PORT_QUERY          = &H0010???
%FAX_PORT_SET            = &H0020???
%FAX_JOB_MANAGE          = &H0040???

%FAX_READ                = %STANDARD_RIGHTS_READ OR _
                           %FAX_JOB_QUERY        OR _
                           %FAX_CONFIG_QUERY     OR _
                           %FAX_PORT_QUERY

%FAX_WRITE               = %STANDARD_RIGHTS_WRITE OR _
                           %FAX_JOB_SUBMIT

%FAX_ALL_ACCESS          = %STANDARD_RIGHTS_ALL OR _
                           %FAX_JOB_SUBMIT      OR _
                           %FAX_JOB_QUERY       OR _
                           %FAX_CONFIG_QUERY    OR _
                           %FAX_CONFIG_SET      OR _
                           %FAX_PORT_QUERY      OR _
                           %FAX_PORT_SET        OR _
                           %FAX_JOB_MANAGE
